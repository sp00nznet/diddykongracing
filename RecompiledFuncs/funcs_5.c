#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void process_object_interactions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800155B8: addiu       $sp, $sp, -0x490
    ctx->r29 = ADD32(ctx->r29, -0X490);
    // 0x800155BC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800155C0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800155C4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800155C8: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x800155CC: lw          $s3, -0x4C20($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X4C20);
    // 0x800155D0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800155D4: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800155D8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800155DC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800155E0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800155E4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800155E8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800155EC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800155F0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800155F4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800155F8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800155FC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80015600: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80015604: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80015608: beq         $at, $zero, L_800156A4
    if (ctx->r1 == 0) {
        // 0x8001560C: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800156A4;
    }
    // 0x8001560C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80015610: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80015614: addiu       $a0, $a0, -0x4C28
    ctx->r4 = ADD32(ctx->r4, -0X4C28);
    // 0x80015618: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x8001561C: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x80015620: addiu       $s6, $sp, 0x64
    ctx->r22 = ADD32(ctx->r29, 0X64);
    // 0x80015624: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80015628: addiu       $a1, $zero, -0x49
    ctx->r5 = ADD32(0, -0X49);
L_8001562C:
    // 0x8001562C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80015630: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80015634: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80015638: lw          $s1, 0x0($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X0);
    // 0x8001563C: nop

    // 0x80015640: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x80015644: nop

    // 0x80015648: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8001564C: bne         $t9, $zero, L_8001569C
    if (ctx->r25 != 0) {
        // 0x80015650: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001569C;
    }
    // 0x80015650: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80015654: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x80015658: sll         $t0, $s5, 2
    ctx->r8 = S32(ctx->r21 << 2);
    // 0x8001565C: beq         $s2, $zero, L_80015698
    if (ctx->r18 == 0) {
        // 0x80015660: addu        $t1, $s6, $t0
        ctx->r9 = ADD32(ctx->r22, ctx->r8);
            goto L_80015698;
    }
    // 0x80015660: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x80015664: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
    // 0x80015668: lbu         $t2, 0x11($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X11);
    // 0x8001566C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80015670: beq         $fp, $t2, L_8001569C
    if (ctx->r30 == ctx->r10) {
        // 0x80015674: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001569C;
    }
    // 0x80015674: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80015678: lh          $t3, 0x14($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X14);
    // 0x8001567C: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x80015680: and         $t4, $t3, $a1
    ctx->r12 = ctx->r11 & ctx->r5;
    // 0x80015684: sh          $t4, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r12;
    // 0x80015688: sb          $a2, 0x13($s2)
    MEM_B(0X13, ctx->r18) = ctx->r6;
    // 0x8001568C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80015690: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x80015694: nop

L_80015698:
    // 0x80015698: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
L_8001569C:
    // 0x8001569C: bne         $at, $zero, L_8001562C
    if (ctx->r1 != 0) {
        // 0x800156A0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8001562C;
    }
    // 0x800156A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800156A4:
    // 0x800156A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800156A8: addiu       $s6, $sp, 0x64
    ctx->r22 = ADD32(ctx->r29, 0X64);
    // 0x800156AC: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x800156B0: sw          $zero, -0x4C10($at)
    MEM_W(-0X4C10, ctx->r1) = 0;
    // 0x800156B4: blez        $s5, L_80015864
    if (SIGNED(ctx->r21) <= 0) {
        // 0x800156B8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80015864;
    }
    // 0x800156B8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800156BC: lui         $at, 0x4880
    ctx->r1 = S32(0X4880 << 16);
    // 0x800156C0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800156C4: lui         $at, 0x4A80
    ctx->r1 = S32(0X4A80 << 16);
    // 0x800156C8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800156CC: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x800156D0: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_800156D4:
    // 0x800156D4: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800156D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800156DC: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x800156E0: nop

    // 0x800156E4: lbu         $t5, 0x11($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X11);
    // 0x800156E8: nop

    // 0x800156EC: bne         $fp, $t5, L_80015728
    if (ctx->r30 != ctx->r13) {
        // 0x800156F0: nop
    
            goto L_80015728;
    }
    // 0x800156F0: nop

    // 0x800156F4: lw          $v0, -0x4C10($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C10);
    // 0x800156F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800156FC: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80015700: beq         $at, $zero, L_80015728
    if (ctx->r1 == 0) {
        // 0x80015704: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80015728;
    }
    // 0x80015704: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80015708: lw          $t6, -0x4C14($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C14);
    // 0x8001570C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80015710: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80015714: sw          $s1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r17;
    // 0x80015718: lw          $t9, -0x4C10($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4C10);
    // 0x8001571C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80015720: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80015724: sw          $t0, -0x4C10($at)
    MEM_W(-0X4C10, ctx->r1) = ctx->r8;
L_80015728:
    // 0x80015728: lh          $v0, 0x14($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X14);
    // 0x8001572C: nop

    // 0x80015730: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x80015734: beq         $t1, $zero, L_80015804
    if (ctx->r9 == 0) {
        // 0x80015738: andi        $t6, $v0, 0x100
        ctx->r14 = ctx->r2 & 0X100;
            goto L_80015804;
    }
    // 0x80015738: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x8001573C: blez        $s5, L_80015800
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80015740: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80015800;
    }
    // 0x80015740: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80015744:
    // 0x80015744: beq         $s3, $s0, L_800157EC
    if (ctx->r19 == ctx->r16) {
        // 0x80015748: sll         $t2, $s0, 2
        ctx->r10 = S32(ctx->r16 << 2);
            goto L_800157EC;
    }
    // 0x80015748: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8001574C: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x80015750: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80015754: nop

    // 0x80015758: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8001575C: nop

    // 0x80015760: lh          $v1, 0x14($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X14);
    // 0x80015764: nop

    // 0x80015768: andi        $t4, $v1, 0x3
    ctx->r12 = ctx->r3 & 0X3;
    // 0x8001576C: beq         $t4, $zero, L_800157EC
    if (ctx->r12 == 0) {
        // 0x80015770: nop
    
            goto L_800157EC;
    }
    // 0x80015770: nop

    // 0x80015774: lbu         $a0, 0x11($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X11);
    // 0x80015778: nop

    // 0x8001577C: bne         $s4, $a0, L_80015794
    if (ctx->r20 != ctx->r4) {
        // 0x80015780: nop
    
            goto L_80015794;
    }
    // 0x80015780: nop

    // 0x80015784: jal         0x8001677C
    // 0x80015788: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80016748(rdram, ctx);
        goto after_0;
    // 0x80015788: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8001578C: b           L_800157F0
    // 0x80015790: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800157F0;
    // 0x80015790: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80015794:
    // 0x80015794: beq         $fp, $a0, L_800157EC
    if (ctx->r30 == ctx->r4) {
        // 0x80015798: andi        $t5, $v1, 0x20
        ctx->r13 = ctx->r3 & 0X20;
            goto L_800157EC;
    }
    // 0x80015798: andi        $t5, $v1, 0x20
    ctx->r13 = ctx->r3 & 0X20;
    // 0x8001579C: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800157A0: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800157A4: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800157A8: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800157AC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800157B0: beq         $t5, $zero, L_800157C0
    if (ctx->r13 == 0) {
        // 0x800157B4: sub.s       $f2, $f8, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
            goto L_800157C0;
    }
    // 0x800157B4: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800157B8: b           L_800157C4
    // 0x800157BC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
        goto L_800157C4;
    // 0x800157BC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_800157C0:
    // 0x800157C0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
L_800157C4:
    // 0x800157C4: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800157C8: nop

    // 0x800157CC: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800157D0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800157D4: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800157D8: nop

    // 0x800157DC: bc1f        L_800157EC
    if (!c1cs) {
        // 0x800157E0: nop
    
            goto L_800157EC;
    }
    // 0x800157E0: nop

    // 0x800157E4: jal         0x800159C8
    // 0x800157E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800159C8(rdram, ctx);
        goto after_1;
    // 0x800157E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
L_800157EC:
    // 0x800157EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800157F0:
    // 0x800157F0: bne         $s0, $s5, L_80015744
    if (ctx->r16 != ctx->r21) {
        // 0x800157F4: nop
    
            goto L_80015744;
    }
    // 0x800157F4: nop

    // 0x800157F8: lh          $v0, 0x14($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X14);
    // 0x800157FC: nop

L_80015800:
    // 0x80015800: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
L_80015804:
    // 0x80015804: beq         $t6, $zero, L_80015854
    if (ctx->r14 == 0) {
        // 0x80015808: nop
    
            goto L_80015854;
    }
    // 0x80015808: nop

    // 0x8001580C: blez        $s5, L_80015854
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80015810: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80015854;
    }
    // 0x80015810: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80015814:
    // 0x80015814: beq         $s3, $s0, L_80015848
    if (ctx->r19 == ctx->r16) {
        // 0x80015818: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_80015848;
    }
    // 0x80015818: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8001581C: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x80015820: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80015824: nop

    // 0x80015828: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8001582C: nop

    // 0x80015830: lbu         $t9, 0x11($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X11);
    // 0x80015834: nop

    // 0x80015838: bne         $s4, $t9, L_80015848
    if (ctx->r20 != ctx->r25) {
        // 0x8001583C: nop
    
            goto L_80015848;
    }
    // 0x8001583C: nop

    // 0x80015840: jal         0x8001677C
    // 0x80015844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80016748(rdram, ctx);
        goto after_2;
    // 0x80015844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
L_80015848:
    // 0x80015848: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001584C: bne         $s0, $s5, L_80015814
    if (ctx->r16 != ctx->r21) {
        // 0x80015850: nop
    
            goto L_80015814;
    }
    // 0x80015850: nop

L_80015854:
    // 0x80015854: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80015858: bne         $s3, $s5, L_800156D4
    if (ctx->r19 != ctx->r21) {
        // 0x8001585C: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_800156D4;
    }
    // 0x8001585C: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80015860: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80015864:
    // 0x80015864: blez        $s5, L_80015988
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80015868: andi        $v1, $s5, 0x3
        ctx->r3 = ctx->r21 & 0X3;
            goto L_80015988;
    }
    // 0x80015868: andi        $v1, $s5, 0x3
    ctx->r3 = ctx->r21 & 0X3;
    // 0x8001586C: beq         $v1, $zero, L_800158B4
    if (ctx->r3 == 0) {
        // 0x80015870: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800158B4;
    }
    // 0x80015870: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80015874: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x80015878: addiu       $t1, $sp, 0x64
    ctx->r9 = ADD32(ctx->r29, 0X64);
    // 0x8001587C: addu        $s7, $t0, $t1
    ctx->r23 = ADD32(ctx->r8, ctx->r9);
L_80015880:
    // 0x80015880: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x80015884: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80015888: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x8001588C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80015890: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80015894: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80015898: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8001589C: nop

    // 0x800158A0: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x800158A4: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800158A8: bne         $v0, $s3, L_80015880
    if (ctx->r2 != ctx->r19) {
        // 0x800158AC: swc1        $f10, 0xC($s2)
        MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
            goto L_80015880;
    }
    // 0x800158AC: swc1        $f10, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
    // 0x800158B0: beq         $s3, $s5, L_80015988
    if (ctx->r19 == ctx->r21) {
        // 0x800158B4: addiu       $t3, $sp, 0x64
        ctx->r11 = ADD32(ctx->r29, 0X64);
            goto L_80015988;
    }
L_800158B4:
    // 0x800158B4: addiu       $t3, $sp, 0x64
    ctx->r11 = ADD32(ctx->r29, 0X64);
    // 0x800158B8: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x800158BC: sll         $t4, $s5, 2
    ctx->r12 = S32(ctx->r21 << 2);
    // 0x800158C0: addu        $v0, $t4, $t3
    ctx->r2 = ADD32(ctx->r12, ctx->r11);
    // 0x800158C4: addu        $s7, $t2, $t3
    ctx->r23 = ADD32(ctx->r10, ctx->r11);
L_800158C8:
    // 0x800158C8: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800158CC: addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
    // 0x800158D0: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x800158D4: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800158D8: nop

    // 0x800158DC: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
    // 0x800158E0: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800158E4: nop

    // 0x800158E8: swc1        $f18, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f18.u32l;
    // 0x800158EC: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800158F0: nop

    // 0x800158F4: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    // 0x800158F8: lw          $s1, -0xC($s7)
    ctx->r17 = MEM_W(ctx->r23, -0XC);
    // 0x800158FC: nop

    // 0x80015900: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x80015904: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80015908: nop

    // 0x8001590C: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80015910: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80015914: nop

    // 0x80015918: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x8001591C: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80015920: nop

    // 0x80015924: swc1        $f10, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
    // 0x80015928: lw          $s1, -0x8($s7)
    ctx->r17 = MEM_W(ctx->r23, -0X8);
    // 0x8001592C: nop

    // 0x80015930: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x80015934: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80015938: nop

    // 0x8001593C: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
    // 0x80015940: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80015944: nop

    // 0x80015948: swc1        $f18, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f18.u32l;
    // 0x8001594C: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80015950: nop

    // 0x80015954: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    // 0x80015958: lw          $s1, -0x4($s7)
    ctx->r17 = MEM_W(ctx->r23, -0X4);
    // 0x8001595C: nop

    // 0x80015960: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x80015964: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80015968: nop

    // 0x8001596C: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80015970: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80015974: nop

    // 0x80015978: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x8001597C: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80015980: bne         $s7, $v0, L_800158C8
    if (ctx->r23 != ctx->r2) {
        // 0x80015984: swc1        $f10, 0xC($s2)
        MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
            goto L_800158C8;
    }
    // 0x80015984: swc1        $f10, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
L_80015988:
    // 0x80015988: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8001598C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80015990: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80015994: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80015998: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001599C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800159A0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800159A4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800159A8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800159AC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800159B0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800159B4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800159B8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800159BC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800159C0: jr          $ra
    // 0x800159C4: addiu       $sp, $sp, 0x490
    ctx->r29 = ADD32(ctx->r29, 0X490);
    return;
    // 0x800159C4: addiu       $sp, $sp, 0x490
    ctx->r29 = ADD32(ctx->r29, 0X490);
;}
RECOMP_FUNC void func_800159C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800159C8: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800159CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800159D0: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800159D4: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800159D8: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800159DC: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800159E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800159E4: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800159E8: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800159EC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800159F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800159F4: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800159F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800159FC: lwc1        $f6, -0x4CD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4CD8);
    // 0x80015A00: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80015A04: lw          $a2, 0x4C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4C);
    // 0x80015A08: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80015A0C: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x80015A10: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80015A14: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80015A18: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x80015A1C: lbu         $v0, 0x11($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X11);
    // 0x80015A20: nop

    // 0x80015A24: bne         $t1, $v0, L_80015A90
    if (ctx->r9 != ctx->r2) {
        // 0x80015A28: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80015A90;
    }
    // 0x80015A28: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80015A2C: lb          $t9, 0x16($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X16);
    // 0x80015A30: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80015A34: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80015A38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80015A3C: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80015A40: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80015A44: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80015A48: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80015A4C: nop

    // 0x80015A50: bc1t        L_80016528
    if (c1cs) {
        // 0x80015A54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015A58: lb          $t2, 0x17($a2)
    ctx->r10 = MEM_B(ctx->r6, 0X17);
    // 0x80015A5C: nop

    // 0x80015A60: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80015A64: nop

    // 0x80015A68: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80015A6C: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80015A70: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80015A74: nop

    // 0x80015A78: bc1t        L_80016528
    if (c1cs) {
        // 0x80015A7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015A80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80015A84: nop

    // 0x80015A88: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80015A8C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80015A90:
    // 0x80015A90: bne         $v0, $at, L_80015AC4
    if (ctx->r2 != ctx->r1) {
        // 0x80015A94: nop
    
            goto L_80015AC4;
    }
    // 0x80015A94: nop

    // 0x80015A98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80015A9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015AA0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80015AA4: nop

    // 0x80015AA8: bc1f        L_80015AC4
    if (!c1cs) {
        // 0x80015AAC: nop
    
            goto L_80015AC4;
    }
    // 0x80015AAC: nop

    // 0x80015AB0: lwc1        $f5, 0x5B48($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5B48);
    // 0x80015AB4: lwc1        $f4, 0x5B4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B4C);
    // 0x80015AB8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80015ABC: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80015AC0: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80015AC4:
    // 0x80015AC4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80015AC8: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80015ACC: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80015AD0: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80015AD4: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80015AD8: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80015ADC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80015AE0: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x80015AE4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80015AE8: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80015AEC: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x80015AF0: jal         0x800CA030
    // 0x80015AF4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80015AF4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80015AF8: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80015AFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80015B00: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80015B04: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80015B08: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80015B0C: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80015B10: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80015B14: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80015B18: bc1t        L_80016524
    if (c1cs) {
        // 0x80015B1C: mov.s       $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
            goto L_80016524;
    }
    // 0x80015B1C: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80015B20: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x80015B24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80015B28: nop

    // 0x80015B2C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80015B30: nop

    // 0x80015B34: bc1t        L_80016528
    if (c1cs) {
        // 0x80015B38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015B3C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80015B40: lh          $t6, 0x14($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X14);
    // 0x80015B44: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80015B48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80015B4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80015B50: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x80015B54: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80015B58: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80015B5C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80015B60: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80015B64: nop

    // 0x80015B68: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80015B6C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80015B70: nop

    // 0x80015B74: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80015B78: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80015B7C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80015B80: nop

    // 0x80015B84: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80015B88: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80015B8C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80015B90: beq         $t7, $zero, L_80015B9C
    if (ctx->r15 == 0) {
        // 0x80015B94: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80015B9C;
    }
    // 0x80015B94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80015B98: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
L_80015B9C:
    // 0x80015B9C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80015BA0: bne         $at, $zero, L_80015BAC
    if (ctx->r1 != 0) {
        // 0x80015BA4: nop
    
            goto L_80015BAC;
    }
    // 0x80015BA4: nop

    // 0x80015BA8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80015BAC:
    // 0x80015BAC: lbu         $t8, 0x13($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X13);
    // 0x80015BB0: nop

    // 0x80015BB4: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015BB8: bne         $at, $zero, L_80015BC8
    if (ctx->r1 != 0) {
        // 0x80015BBC: nop
    
            goto L_80015BC8;
    }
    // 0x80015BBC: nop

    // 0x80015BC0: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x80015BC4: sb          $v0, 0x13($t0)
    MEM_B(0X13, ctx->r8) = ctx->r2;
L_80015BC8:
    // 0x80015BC8: lh          $a1, 0x14($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X14);
    // 0x80015BCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80015BD0: andi        $t9, $a1, 0x20
    ctx->r25 = ctx->r5 & 0X20;
    // 0x80015BD4: beq         $t9, $zero, L_80015BE4
    if (ctx->r25 == 0) {
        // 0x80015BD8: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_80015BE4;
    }
    // 0x80015BD8: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80015BDC: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80015BE0: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
L_80015BE4:
    // 0x80015BE4: bne         $at, $zero, L_80015BF0
    if (ctx->r1 != 0) {
        // 0x80015BE8: nop
    
            goto L_80015BF0;
    }
    // 0x80015BE8: nop

    // 0x80015BEC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80015BF0:
    // 0x80015BF0: lbu         $t2, 0x13($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X13);
    // 0x80015BF4: nop

    // 0x80015BF8: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015BFC: bne         $at, $zero, L_80015C14
    if (ctx->r1 != 0) {
        // 0x80015C00: andi        $t4, $a1, 0x1
        ctx->r12 = ctx->r5 & 0X1;
            goto L_80015C14;
    }
    // 0x80015C00: andi        $t4, $a1, 0x1
    ctx->r12 = ctx->r5 & 0X1;
    // 0x80015C04: lh          $a1, 0x14($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X14);
    // 0x80015C08: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x80015C0C: sb          $v0, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r2;
    // 0x80015C10: andi        $t4, $a1, 0x1
    ctx->r12 = ctx->r5 & 0X1;
L_80015C14:
    // 0x80015C14: beq         $t4, $zero, L_80016528
    if (ctx->r12 == 0) {
        // 0x80015C18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015C1C: lb          $t3, 0x10($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X10);
    // 0x80015C20: lb          $t5, 0x10($t0)
    ctx->r13 = MEM_B(ctx->r8, 0X10);
    // 0x80015C24: nop

    // 0x80015C28: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80015C2C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80015C30: nop

    // 0x80015C34: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015C38: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    // 0x80015C3C: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80015C40: nop

    // 0x80015C44: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80015C48: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80015C4C: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80015C50: nop

    // 0x80015C54: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80015C58: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x80015C5C: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80015C60: nop

    // 0x80015C64: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80015C68: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80015C6C: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80015C70: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80015C74: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80015C78: sub.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80015C7C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80015C80: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80015C84: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80015C88: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80015C8C: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x80015C90: lbu         $t7, 0x11($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X11);
    // 0x80015C94: mul.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80015C98: bne         $t1, $t7, L_80015CA8
    if (ctx->r9 != ctx->r15) {
        // 0x80015C9C: nop
    
            goto L_80015CA8;
    }
    // 0x80015C9C: nop

    // 0x80015CA0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80015CA4: nop

L_80015CA8:
    // 0x80015CA8: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80015CAC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80015CB0: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80015CB4: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80015CB8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80015CBC: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80015CC0: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80015CC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80015CC8: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80015CCC: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80015CD0: nop

    // 0x80015CD4: bc1f        L_80015E10
    if (!c1cs) {
        // 0x80015CD8: nop
    
            goto L_80015E10;
    }
    // 0x80015CD8: nop

    // 0x80015CDC: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80015CE0: lwc1        $f18, 0xC($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80015CE4: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80015CE8: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80015CEC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80015CF0: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80015CF4: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80015CF8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80015CFC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80015D00: mul.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80015D04: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80015D08: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80015D0C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80015D10: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80015D14: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80015D18: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80015D1C: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80015D20: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80015D24: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80015D28: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80015D2C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80015D30: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80015D34: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80015D38: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80015D3C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80015D40: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80015D44: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80015D48: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x80015D4C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80015D50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80015D54: div.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80015D58: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x80015D5C: nop

    // 0x80015D60: bc1f        L_80015E10
    if (!c1cs) {
        // 0x80015D64: nop
    
            goto L_80015E10;
    }
    // 0x80015D64: nop

    // 0x80015D68: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80015D6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015D70: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80015D74: c.le.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d <= ctx->f6.d;
    // 0x80015D78: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80015D7C: bc1f        L_80015E10
    if (!c1cs) {
        // 0x80015D80: swc1        $f12, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->f12.u32l;
            goto L_80015E10;
    }
    // 0x80015D80: swc1        $f12, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f12.u32l;
    // 0x80015D84: mul.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80015D88: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80015D8C: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80015D90: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80015D94: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80015D98: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80015D9C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80015DA0: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x80015DA4: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80015DA8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80015DAC: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80015DB0: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80015DB4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80015DB8: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80015DBC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80015DC0: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80015DC4: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80015DC8: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80015DCC: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80015DD0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80015DD4: sub.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80015DD8: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80015DDC: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80015DE0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80015DE4: sub.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80015DE8: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80015DEC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80015DF0: jal         0x800CA030
    // 0x80015DF4: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80015DF4: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_1:
    // 0x80015DF8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80015DFC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80015E00: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80015E04: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80015E08: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80015E0C: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_80015E10:
    // 0x80015E10: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80015E14: nop

    // 0x80015E18: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80015E1C: nop

    // 0x80015E20: bc1f        L_80016528
    if (!c1cs) {
        // 0x80015E24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015E28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80015E2C: nop

    // 0x80015E30: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80015E34: nop

    // 0x80015E38: bc1f        L_80016528
    if (!c1cs) {
        // 0x80015E3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015E40: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80015E44: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80015E48: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80015E4C: sub.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80015E50: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80015E54: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80015E58: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80015E5C: lbu         $t8, 0x11($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X11);
    // 0x80015E60: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80015E64: bne         $t1, $t8, L_80015E74
    if (ctx->r9 != ctx->r24) {
        // 0x80015E68: sub.s       $f14, $f8, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
            goto L_80015E74;
    }
    // 0x80015E68: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80015E6C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80015E70: nop

L_80015E74:
    // 0x80015E74: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80015E78: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80015E7C: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80015E80: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80015E84: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80015E88: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80015E8C: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x80015E90: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
    // 0x80015E94: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80015E98: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80015E9C: swc1        $f16, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f16.u32l;
    // 0x80015EA0: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x80015EA4: jal         0x800CA030
    // 0x80015EA8: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80015EA8: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_2:
    // 0x80015EAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80015EB0: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80015EB4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80015EB8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80015EBC: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80015EC0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80015EC4: lwc1        $f2, 0x8C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80015EC8: lwc1        $f14, 0x84($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80015ECC: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80015ED0: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80015ED4: bc1f        L_80015EFC
    if (!c1cs) {
        // 0x80015ED8: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80015EFC;
    }
    // 0x80015ED8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80015EDC: nop

    // 0x80015EE0: div.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80015EE4: nop

    // 0x80015EE8: div.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80015EEC: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x80015EF0: div.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80015EF4: b           L_80015F20
    // 0x80015EF8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
        goto L_80015F20;
    // 0x80015EF8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
L_80015EFC:
    // 0x80015EFC: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80015F00: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80015F04: div.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80015F08: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80015F0C: div.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80015F10: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x80015F14: div.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80015F18: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x80015F1C: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
L_80015F20:
    // 0x80015F20: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80015F24: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80015F28: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80015F2C: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x80015F30: nop

    // 0x80015F34: bc1f        L_80015F40
    if (!c1cs) {
        // 0x80015F38: nop
    
            goto L_80015F40;
    }
    // 0x80015F38: nop

    // 0x80015F3C: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
L_80015F40:
    // 0x80015F40: mul.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80015F44: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80015F48: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80015F4C: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80015F50: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80015F54: nop

    // 0x80015F58: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80015F5C: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x80015F60: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x80015F64: lh          $t9, 0x14($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X14);
    // 0x80015F68: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80015F6C: ori         $t2, $t9, 0x8
    ctx->r10 = ctx->r25 | 0X8;
    // 0x80015F70: sh          $t2, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r10;
    // 0x80015F74: lh          $t4, 0x14($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X14);
    // 0x80015F78: lbu         $t5, 0x12($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X12);
    // 0x80015F7C: ori         $t3, $t4, 0x8
    ctx->r11 = ctx->r12 | 0X8;
    // 0x80015F80: bne         $t5, $zero, L_8001629C
    if (ctx->r13 != 0) {
        // 0x80015F84: sh          $t3, 0x14($a2)
        MEM_H(0X14, ctx->r6) = ctx->r11;
            goto L_8001629C;
    }
    // 0x80015F84: sh          $t3, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r11;
    // 0x80015F88: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80015F8C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80015F90: sub.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80015F94: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x80015F98: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80015F9C: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80015FA0: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80015FA4: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x80015FA8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80015FAC: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80015FB0: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80015FB4: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80015FB8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80015FBC: nop

    // 0x80015FC0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80015FC4: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x80015FC8: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x80015FCC: nop

    // 0x80015FD0: bne         $t1, $t6, L_80016528
    if (ctx->r9 != ctx->r14) {
        // 0x80015FD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80015FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015FD8: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x80015FDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80015FE0: lb          $t7, 0x1D6($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1D6);
    // 0x80015FE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015FE8: bne         $t1, $t7, L_80016150
    if (ctx->r9 != ctx->r15) {
        // 0x80015FEC: nop
    
            goto L_80016150;
    }
    // 0x80015FEC: nop

    // 0x80015FF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015FF4: lwc1        $f5, 0x5B50($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5B50);
    // 0x80015FF8: lwc1        $f4, 0x5B54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B54);
    // 0x80015FFC: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80016000: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80016004: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80016008: bc1f        L_80016274
    if (!c1cs) {
        // 0x8001600C: nop
    
            goto L_80016274;
    }
    // 0x8001600C: nop

    // 0x80016010: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80016014: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016018: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001601C: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x80016020: nop

    // 0x80016024: bc1f        L_80016030
    if (!c1cs) {
        // 0x80016028: nop
    
            goto L_80016030;
    }
    // 0x80016028: nop

    // 0x8001602C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80016030:
    // 0x80016030: beq         $v0, $zero, L_8001606C
    if (ctx->r2 == 0) {
        // 0x80016034: nop
    
            goto L_8001606C;
    }
    // 0x80016034: nop

    // 0x80016038: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8001603C: lwc1        $f1, 0x5B58($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X5B58);
    // 0x80016040: lwc1        $f0, 0x5B5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B5C);
    // 0x80016044: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80016048: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8001604C: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80016050: nop

    // 0x80016054: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80016058: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8001605C: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80016060: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x80016064: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80016068: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
L_8001606C:
    // 0x8001606C: beq         $v0, $zero, L_80016274
    if (ctx->r2 == 0) {
        // 0x80016070: nop
    
            goto L_80016274;
    }
    // 0x80016070: nop

    // 0x80016074: lh          $t8, 0x14($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X14);
    // 0x80016078: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8001607C: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x80016080: sh          $t9, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r25;
    // 0x80016084: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80016088: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8001608C: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80016090: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80016094: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80016098: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8001609C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800160A0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800160A4: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800160A8: lwc1        $f10, 0x14($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800160AC: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800160B0: sb          $t2, 0x1D2($a1)
    MEM_B(0X1D2, ctx->r5) = ctx->r10;
    // 0x800160B4: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800160B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800160BC: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800160C0: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800160C4: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x800160C8: nop

    // 0x800160CC: bc1f        L_80016114
    if (!c1cs) {
        // 0x800160D0: nop
    
            goto L_80016114;
    }
    // 0x800160D0: nop

    // 0x800160D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800160D8: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800160DC: lwc1        $f1, 0x5B60($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X5B60);
    // 0x800160E0: lwc1        $f0, 0x5B64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B64);
    // 0x800160E4: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800160E8: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800160EC: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800160F0: swc1        $f10, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->f10.u32l;
    // 0x800160F4: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800160F8: nop

    // 0x800160FC: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x80016100: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80016104: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80016108: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8001610C: b           L_80016274
    // 0x80016110: swc1        $f4, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f4.u32l;
        goto L_80016274;
    // 0x80016110: swc1        $f4, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f4.u32l;
L_80016114:
    // 0x80016114: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80016118: lwc1        $f1, 0x5B68($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X5B68);
    // 0x8001611C: lwc1        $f0, 0x5B6C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B6C);
    // 0x80016120: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x80016124: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80016128: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8001612C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80016130: swc1        $f8, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->f8.u32l;
    // 0x80016134: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80016138: nop

    // 0x8001613C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80016140: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80016144: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80016148: b           L_80016274
    // 0x8001614C: swc1        $f8, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f8.u32l;
        goto L_80016274;
    // 0x8001614C: swc1        $f8, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f8.u32l;
L_80016150:
    // 0x80016150: lwc1        $f7, 0x5B70($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5B70);
    // 0x80016154: lwc1        $f6, 0x5B74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5B74);
    // 0x80016158: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x8001615C: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80016160: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80016164: bc1f        L_800161C8
    if (!c1cs) {
        // 0x80016168: nop
    
            goto L_800161C8;
    }
    // 0x80016168: nop

    // 0x8001616C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80016170: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80016174: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80016178: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8001617C: nop

    // 0x80016180: bc1f        L_8001618C
    if (!c1cs) {
        // 0x80016184: nop
    
            goto L_8001618C;
    }
    // 0x80016184: nop

    // 0x80016188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001618C:
    // 0x8001618C: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80016190: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80016194: sub.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80016198: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001619C: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x800161A0: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800161A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800161A8: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800161AC: mul.d       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f8.d);
    // 0x800161B0: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x800161B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800161B8: nop

    // 0x800161BC: swc1        $f4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f4.u32l;
    // 0x800161C0: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800161C4: swc1        $f10, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f10.u32l;
L_800161C8:
    // 0x800161C8: beq         $v0, $zero, L_80016274
    if (ctx->r2 == 0) {
        // 0x800161CC: nop
    
            goto L_80016274;
    }
    // 0x800161CC: nop

    // 0x800161D0: lh          $t4, 0x14($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X14);
    // 0x800161D4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800161D8: ori         $t3, $t4, 0x40
    ctx->r11 = ctx->r12 | 0X40;
    // 0x800161DC: sh          $t3, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r11;
    // 0x800161E0: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800161E4: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800161E8: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800161EC: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800161F0: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800161F4: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800161F8: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800161FC: sub.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80016200: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80016204: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80016208: nop

    // 0x8001620C: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80016210: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80016214: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80016218: sub.s       $f2, $f8, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8001621C: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x80016220: nop

    // 0x80016224: bc1f        L_8001623C
    if (!c1cs) {
        // 0x80016228: nop
    
            goto L_8001623C;
    }
    // 0x80016228: nop

    // 0x8001622C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80016230: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80016234: b           L_80016248
    // 0x80016238: lwc1        $f10, 0x50($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X50);
        goto L_80016248;
    // 0x80016238: lwc1        $f10, 0x50($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X50);
L_8001623C:
    // 0x8001623C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80016240: nop

    // 0x80016244: lwc1        $f10, 0x50($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X50);
L_80016248:
    // 0x80016248: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8001624C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80016250: lwc1        $f6, 0x58($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X58);
    // 0x80016254: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80016258: sb          $t5, 0x1D2($a1)
    MEM_B(0X1D2, ctx->r5) = ctx->r13;
    // 0x8001625C: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80016260: nop

    // 0x80016264: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80016268: swc1        $f8, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f8.u32l;
    // 0x8001626C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80016270: swc1        $f4, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->f4.u32l;
L_80016274:
    // 0x80016274: beq         $v0, $zero, L_80016528
    if (ctx->r2 == 0) {
        // 0x80016278: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80016278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001627C: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80016280: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80016284: beq         $t6, $at, L_80016528
    if (ctx->r14 == ctx->r1) {
        // 0x80016288: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80016288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001628C: jal         0x80016534
    // 0x80016290: nop

    func_80016500(rdram, ctx);
        goto after_3;
    // 0x80016290: nop

    after_3:
    // 0x80016294: b           L_80016528
    // 0x80016298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80016528;
    // 0x80016298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001629C:
    // 0x8001629C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x800162A0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800162A4: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x800162A8: mul.d       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x800162AC: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800162B0: nop

    // 0x800162B4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800162B8: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800162BC: mul.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x800162C0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800162C4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800162C8: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800162CC: mul.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x800162D0: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x800162D4: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800162D8: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x800162DC: lbu         $t7, 0x12($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X12);
    // 0x800162E0: nop

    // 0x800162E4: beq         $t7, $zero, L_8001631C
    if (ctx->r15 == 0) {
        // 0x800162E8: nop
    
            goto L_8001631C;
    }
    // 0x800162E8: nop

    // 0x800162EC: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800162F0: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800162F4: sub.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800162F8: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800162FC: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80016300: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80016304: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80016308: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x8001630C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016310: nop

    // 0x80016314: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80016318: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
L_8001631C:
    // 0x8001631C: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80016320: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80016324: add.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80016328: swc1        $f4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f4.u32l;
    // 0x8001632C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80016330: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80016334: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80016338: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x8001633C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016340: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80016344: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80016348: swc1        $f6, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f6.u32l;
    // 0x8001634C: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016350: nop

    // 0x80016354: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80016358: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8001635C: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
    // 0x80016360: nop

    // 0x80016364: bne         $t1, $t8, L_80016528
    if (ctx->r9 != ctx->r24) {
        // 0x80016368: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80016368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001636C: lh          $t9, 0x48($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X48);
    // 0x80016370: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80016374: bne         $t1, $t9, L_80016528
    if (ctx->r9 != ctx->r25) {
        // 0x80016378: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80016378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001637C: lbu         $t2, 0x12($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X12);
    // 0x80016380: lbu         $t4, 0x12($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X12);
    // 0x80016384: lwc1        $f5, 0x5B78($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5B78);
    // 0x80016388: subu        $t3, $t2, $t4
    ctx->r11 = SUB32(ctx->r10, ctx->r12);
    // 0x8001638C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80016390: lwc1        $f4, 0x5B7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B7C);
    // 0x80016394: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80016398: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8001639C: lw          $t5, 0x64($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X64);
    // 0x800163A0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800163A4: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800163A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800163AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800163B0: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800163B4: lb          $v0, 0x189($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X189);
    // 0x800163B8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800163BC: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x800163C0: beq         $v0, $zero, L_800163DC
    if (ctx->r2 == 0) {
        // 0x800163C4: cvt.s.d     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
            goto L_800163DC;
    }
    // 0x800163C4: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x800163C8: lb          $t7, 0x189($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X189);
    // 0x800163CC: nop

    // 0x800163D0: bne         $t7, $zero, L_800163E0
    if (ctx->r15 != 0) {
        // 0x800163D4: lw          $t8, 0x4C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X4C);
            goto L_800163E0;
    }
    // 0x800163D4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800163D8: sb          $v0, 0x1DB($t5)
    MEM_B(0X1DB, ctx->r13) = ctx->r2;
L_800163DC:
    // 0x800163DC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_800163E0:
    // 0x800163E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800163E4: lb          $v0, 0x189($t8)
    ctx->r2 = MEM_B(ctx->r24, 0X189);
    // 0x800163E8: nop

    // 0x800163EC: beq         $v0, $zero, L_80016408
    if (ctx->r2 == 0) {
        // 0x800163F0: nop
    
            goto L_80016408;
    }
    // 0x800163F0: nop

    // 0x800163F4: lb          $t9, 0x189($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X189);
    // 0x800163F8: nop

    // 0x800163FC: bne         $t9, $zero, L_80016408
    if (ctx->r25 != 0) {
        // 0x80016400: nop
    
            goto L_80016408;
    }
    // 0x80016400: nop

    // 0x80016404: sb          $v0, 0x1DB($a1)
    MEM_B(0X1DB, ctx->r5) = ctx->r2;
L_80016408:
    // 0x80016408: lb          $t2, 0x1D6($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1D6);
    // 0x8001640C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016410: bne         $t1, $t2, L_80016424
    if (ctx->r9 != ctx->r10) {
        // 0x80016414: nop
    
            goto L_80016424;
    }
    // 0x80016414: nop

    // 0x80016418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001641C: b           L_80016470
    // 0x80016420: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
        goto L_80016470;
    // 0x80016420: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
L_80016424:
    // 0x80016424: lwc1        $f1, 0x5B80($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X5B80);
    // 0x80016428: lwc1        $f0, 0x5B84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B84);
    // 0x8001642C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80016430: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x80016434: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x80016438: bc1f        L_80016470
    if (!c1cs) {
        // 0x8001643C: nop
    
            goto L_80016470;
    }
    // 0x8001643C: nop

    // 0x80016440: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80016444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80016448: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8001644C: mul.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x80016450: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016454: nop

    // 0x80016458: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8001645C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80016460: mul.d       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x80016464: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x80016468: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8001646C: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
L_80016470:
    // 0x80016470: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80016474: beq         $v0, $zero, L_80016528
    if (ctx->r2 == 0) {
        // 0x80016478: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80016528;
    }
    // 0x80016478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001647C: lbu         $t4, 0x12($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X12);
    // 0x80016480: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80016484: beq         $t4, $zero, L_800164EC
    if (ctx->r12 == 0) {
        // 0x80016488: nop
    
            goto L_800164EC;
    }
    // 0x80016488: nop

    // 0x8001648C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80016490: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80016494: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80016498: sub.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d - ctx->f8.d;
    // 0x8001649C: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x800164A0: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800164A4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x800164A8: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800164AC: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800164B0: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800164B4: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800164B8: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x800164BC: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800164C0: nop

    // 0x800164C4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800164C8: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800164CC: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x800164D0: swc1        $f14, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f14.u32l;
    // 0x800164D4: jal         0x80016534
    // 0x800164D8: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    func_80016500(rdram, ctx);
        goto after_4;
    // 0x800164D8: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    after_4:
    // 0x800164DC: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x800164E0: lwc1        $f14, 0x90($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800164E4: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800164E8: nop

L_800164EC:
    // 0x800164EC: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800164F0: lwc1        $f6, 0x1C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x800164F4: lwc1        $f4, 0x24($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X24);
    // 0x800164F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800164FC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80016500: swc1        $f8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f8.u32l;
    // 0x80016504: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016508: nop

    // 0x8001650C: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80016510: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80016514: swc1        $f8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f8.u32l;
    // 0x80016518: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8001651C: jal         0x80016534
    // 0x80016520: nop

    func_80016500(rdram, ctx);
        goto after_5;
    // 0x80016520: nop

    after_5:
L_80016524:
    // 0x80016524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80016528:
    // 0x80016528: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x8001652C: jr          $ra
    // 0x80016530: nop

    return;
    // 0x80016530: nop

;}
RECOMP_FUNC void func_80016500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016534: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80016538: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001653C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80016540: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80016544: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80016548: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001654C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80016550: lb          $t6, 0x1D6($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1D6);
    // 0x80016554: lh          $v0, 0x1A0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X1A0);
    // 0x80016558: bne         $t6, $zero, L_80016588
    if (ctx->r14 != 0) {
        // 0x8001655C: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_80016588;
    }
    // 0x8001655C: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x80016560: lb          $t7, 0x1E6($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1E6);
    // 0x80016564: nop

    // 0x80016568: beq         $t7, $zero, L_80016588
    if (ctx->r15 == 0) {
        // 0x8001656C: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_80016588;
    }
    // 0x8001656C: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x80016570: lw          $t8, 0x10C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10C);
    // 0x80016574: nop

    // 0x80016578: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8001657C: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80016580: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80016584: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_80016588:
    // 0x80016588: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x8001658C: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80016590: jal         0x80070A38
    // 0x80016594: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80016594: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80016598: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001659C: jal         0x80070A04
    // 0x800165A0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x800165A0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800165A4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800165A8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800165AC: lwc1        $f6, 0x1C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x800165B0: lwc1        $f10, 0x24($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X24);
    // 0x800165B4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800165B8: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x800165BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800165C0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800165C4: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800165C8: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
    // 0x800165CC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800165D0: nop

    // 0x800165D4: lwc1        $f4, 0x1C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x800165D8: lwc1        $f8, 0x24($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X24);
    // 0x800165DC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800165E0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800165E4: nop

    // 0x800165E8: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800165EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800165F0: beq         $t5, $at, L_8001676C
    if (ctx->r13 == ctx->r1) {
        // 0x800165F4: swc1        $f18, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
            goto L_8001676C;
    }
    // 0x800165F4: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x800165F8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800165FC: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80016600: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80016604: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80016608: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001660C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80016610: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80016614: nop

    // 0x80016618: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001661C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80016620: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80016624: nop

    // 0x80016628: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8001662C: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80016630: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80016634: bgez        $v0, L_80016640
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80016638: nop
    
            goto L_80016640;
    }
    // 0x80016638: nop

    // 0x8001663C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80016640:
    // 0x80016640: addiu       $v0, $v0, 0x23
    ctx->r2 = ADD32(ctx->r2, 0X23);
    // 0x80016644: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80016648: bne         $at, $zero, L_80016654
    if (ctx->r1 != 0) {
        // 0x8001664C: addiu       $a0, $zero, 0xD
        ctx->r4 = ADD32(0, 0XD);
            goto L_80016654;
    }
    // 0x8001664C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80016650: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_80016654:
    // 0x80016654: lb          $v1, 0x1F6($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1F6);
    // 0x80016658: addiu       $a1, $s0, 0x220
    ctx->r5 = ADD32(ctx->r16, 0X220);
    // 0x8001665C: bne         $v1, $zero, L_8001668C
    if (ctx->r3 != 0) {
        // 0x80016660: nop
    
            goto L_8001668C;
    }
    // 0x80016660: nop

    // 0x80016664: jal         0x80001D04
    // 0x80016668: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80016668: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_2:
    // 0x8001666C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80016670: lw          $a1, 0x220($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X220);
    // 0x80016674: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80016678: jal         0x80001FB8
    // 0x8001667C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    sound_volume_set_relative(rdram, ctx);
        goto after_3;
    // 0x8001667C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_3:
    // 0x80016680: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80016684: lb          $v1, 0x1F6($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1F6);
    // 0x80016688: nop

L_8001668C:
    // 0x8001668C: bne         $v1, $zero, L_800166D0
    if (ctx->r3 != 0) {
        // 0x80016690: slti        $at, $v0, 0x38
        ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
            goto L_800166D0;
    }
    // 0x80016690: slti        $at, $v0, 0x38
    ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
    // 0x80016694: bne         $at, $zero, L_800166D4
    if (ctx->r1 != 0) {
        // 0x80016698: slti        $at, $v0, 0x38
        ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
            goto L_800166D4;
    }
    // 0x80016698: slti        $at, $v0, 0x38
    ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
    // 0x8001669C: lb          $t7, 0x1D8($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D8);
    // 0x800166A0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x800166A4: bne         $t7, $zero, L_800166C0
    if (ctx->r15 != 0) {
        // 0x800166A8: nop
    
            goto L_800166C0;
    }
    // 0x800166A8: nop

    // 0x800166AC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800166B0: jal         0x80072594
    // 0x800166B4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    rumble_set(rdram, ctx);
        goto after_4;
    // 0x800166B4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_4:
    // 0x800166B8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800166BC: nop

L_800166C0:
    // 0x800166C0: lbu         $t8, 0x1F3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1F3);
    // 0x800166C4: nop

    // 0x800166C8: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x800166CC: sb          $t9, 0x1F3($s0)
    MEM_B(0X1F3, ctx->r16) = ctx->r25;
L_800166D0:
    // 0x800166D0: slti        $at, $v0, 0x38
    ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
L_800166D4:
    // 0x800166D4: bne         $at, $zero, L_800166EC
    if (ctx->r1 != 0) {
        // 0x800166D8: addiu       $a1, $zero, 0x1C2
        ctx->r5 = ADD32(0, 0X1C2);
            goto L_800166EC;
    }
    // 0x800166D8: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x800166DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800166E0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800166E4: jal         0x800570F8
    // 0x800166E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    play_random_character_voice(rdram, ctx);
        goto after_5;
    // 0x800166E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
L_800166EC:
    // 0x800166EC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800166F0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800166F4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800166F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800166FC: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x80016700: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80016704: nop

    // 0x80016708: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8001670C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80016710: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80016714: nop

    // 0x80016718: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001671C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80016720: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80016724: bgez        $v1, L_80016734
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80016728: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80016734;
    }
    // 0x80016728: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8001672C: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80016730: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
L_80016734:
    // 0x80016734: bne         $at, $zero, L_80016740
    if (ctx->r1 != 0) {
        // 0x80016738: nop
    
            goto L_80016740;
    }
    // 0x80016738: nop

    // 0x8001673C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80016740:
    // 0x80016740: sb          $t1, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = ctx->r9;
    // 0x80016744: jal         0x80066828
    // 0x80016748: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    set_active_camera(rdram, ctx);
        goto after_6;
    // 0x80016748: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_6:
    // 0x8001674C: jal         0x80069F60
    // 0x80016750: nop

    cam_get_active_camera(rdram, ctx);
        goto after_7;
    // 0x80016750: nop

    after_7:
    // 0x80016754: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80016758: nop

    // 0x8001675C: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x80016760: nop

    // 0x80016764: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80016768: swc1        $f18, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f18.u32l;
L_8001676C:
    // 0x8001676C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80016770: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016774: jr          $ra
    // 0x80016778: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80016778: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80016748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001677C: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80016780: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x80016784: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x80016788: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8001678C: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x80016790: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80016794: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80016798: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8001679C: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x800167A0: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x800167A4: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x800167A8: swc1        $f31, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800167AC: swc1        $f30, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f30.u32l;
    // 0x800167B0: swc1        $f29, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800167B4: swc1        $f28, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f28.u32l;
    // 0x800167B8: swc1        $f27, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800167BC: swc1        $f26, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f26.u32l;
    // 0x800167C0: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800167C4: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x800167C8: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800167CC: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x800167D0: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800167D4: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x800167D8: lw          $t6, 0x44($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X44);
    // 0x800167DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800167E0: beq         $t6, $zero, L_80016B98
    if (ctx->r14 == 0) {
        // 0x800167E4: or          $s5, $a1, $zero
        ctx->r21 = ctx->r5 | 0;
            goto L_80016B98;
    }
    // 0x800167E4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800167E8: lw          $t7, 0x68($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X68);
    // 0x800167EC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800167F0: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800167F4: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800167F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800167FC: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x80016800: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x80016804: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80016808: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001680C: nop

    // 0x80016810: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80016814: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80016818: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x8001681C: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80016820: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80016824: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80016828: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8001682C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80016830: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80016834: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x80016838: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001683C: nop

    // 0x80016840: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80016844: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80016848: jal         0x800CA030
    // 0x8001684C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001684C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_0:
    // 0x80016850: lwc1        $f18, 0x3C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X3C);
    // 0x80016854: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80016858: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x8001685C: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80016860: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80016864: add.d       $f4, $f16, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f30.d); 
    ctx->f4.d = ctx->f16.d + ctx->f30.d;
    // 0x80016868: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x8001686C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80016870: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80016874: nop

    // 0x80016878: bc1t        L_80016B9C
    if (c1cs) {
        // 0x8001687C: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_80016B9C;
    }
    // 0x8001687C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x80016880: lw          $s6, 0x4C($s0)
    ctx->r22 = MEM_W(ctx->r16, 0X4C);
    // 0x80016884: lw          $s4, 0x4C($s5)
    ctx->r20 = MEM_W(ctx->r21, 0X4C);
    // 0x80016888: jal         0x8006FE70
    // 0x8001688C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mtxf_from_transform(rdram, ctx);
        goto after_1;
    // 0x8001688C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x80016890: lh          $t8, 0x20($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X20);
    // 0x80016894: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80016898: blez        $t8, L_80016B98
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001689C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80016B98;
    }
    // 0x8001689C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800168A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800168A4: lwc1        $f29, 0x5B88($at)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r1, 0X5B88);
    // 0x800168A8: lwc1        $f28, 0x5B8C($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X5B8C);
    // 0x800168AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800168B0: lwc1        $f27, 0x5B90($at)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r1, 0X5B90);
    // 0x800168B4: lwc1        $f26, 0x5B94($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X5B94);
    // 0x800168B8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800168BC: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
L_800168C0:
    // 0x800168C0: lw          $t0, 0x1C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X1C);
    // 0x800168C4: lw          $t9, 0x44($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X44);
    // 0x800168C8: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x800168CC: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x800168D0: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x800168D4: multu       $t2, $s7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800168D8: mflo        $t3
    ctx->r11 = lo;
    // 0x800168DC: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800168E0: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800168E4: nop

    // 0x800168E8: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800168EC: nop

    // 0x800168F0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800168F4: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x800168F8: lw          $t7, 0x1C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X1C);
    // 0x800168FC: lw          $t6, 0x44($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X44);
    // 0x80016900: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80016904: lh          $t0, 0x0($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X0);
    // 0x80016908: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x8001690C: multu       $t0, $s7
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016910: mflo        $t1
    ctx->r9 = lo;
    // 0x80016914: addu        $t2, $t6, $t1
    ctx->r10 = ADD32(ctx->r14, ctx->r9);
    // 0x80016918: lh          $t9, 0x2($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X2);
    // 0x8001691C: addiu       $t2, $sp, 0xA4
    ctx->r10 = ADD32(ctx->r29, 0XA4);
    // 0x80016920: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80016924: addiu       $t9, $sp, 0xA0
    ctx->r25 = ADD32(ctx->r29, 0XA0);
    // 0x80016928: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001692C: addiu       $t1, $sp, 0xA8
    ctx->r9 = ADD32(ctx->r29, 0XA8);
    // 0x80016930: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
    // 0x80016934: lw          $t4, 0x1C($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X1C);
    // 0x80016938: lw          $t3, 0x44($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X44);
    // 0x8001693C: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80016940: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x80016944: lw          $a2, 0xA4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA4);
    // 0x80016948: multu       $t7, $s7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001694C: mflo        $t8
    ctx->r24 = lo;
    // 0x80016950: addu        $t0, $t3, $t8
    ctx->r8 = ADD32(ctx->r11, ctx->r24);
    // 0x80016954: lh          $t6, 0x4($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X4);
    // 0x80016958: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8001695C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80016960: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80016964: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80016968: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8001696C: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x80016970: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x80016974: jal         0x8006F88C
    // 0x80016978: nop

    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x80016978: nop

    after_2:
    // 0x8001697C: lw          $t4, 0x1C($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X1C);
    // 0x80016980: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80016984: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80016988: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x8001698C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80016990: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80016994: lwc1        $f4, 0x8($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80016998: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001699C: nop

    // 0x800169A0: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800169A4: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800169A8: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800169AC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800169B0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800169B4: mul.d       $f10, $f6, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f30.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f30.d);
    // 0x800169B8: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800169BC: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800169C0: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x800169C4: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800169C8: cvt.s.d     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f22.fl = CVT_S_D(ctx->f10.d);
    // 0x800169CC: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800169D0: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800169D4: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
    // 0x800169D8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800169DC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800169E0: nop

    // 0x800169E4: sub.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800169E8: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800169EC: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x800169F0: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800169F4: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800169F8: jal         0x800CA030
    // 0x800169FC: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800169FC: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_3:
    // 0x80016A00: lb          $t3, 0x10($s4)
    ctx->r11 = MEM_B(ctx->r20, 0X10);
    // 0x80016A04: nop

    // 0x80016A08: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80016A0C: nop

    // 0x80016A10: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80016A14: add.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x80016A18: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80016A1C: nop

    // 0x80016A20: bc1f        L_80016B84
    if (!c1cs) {
        // 0x80016A24: nop
    
            goto L_80016B84;
    }
    // 0x80016A24: nop

    // 0x80016A28: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x80016A2C: nop

    // 0x80016A30: bc1f        L_80016B84
    if (!c1cs) {
        // 0x80016A34: nop
    
            goto L_80016B84;
    }
    // 0x80016A34: nop

    // 0x80016A38: sub.s       $f18, $f22, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x80016A3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80016A40: div.s       $f20, $f18, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80016A44: lh          $t8, 0x14($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X14);
    // 0x80016A48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80016A4C: ori         $t0, $t8, 0x8
    ctx->r8 = ctx->r24 | 0X8;
    // 0x80016A50: sh          $t0, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r8;
    // 0x80016A54: lh          $t6, 0x14($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X14);
    // 0x80016A58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016A5C: ori         $t1, $t6, 0x8
    ctx->r9 = ctx->r14 | 0X8;
    // 0x80016A60: sh          $t1, 0x14($s4)
    MEM_H(0X14, ctx->r20) = ctx->r9;
    // 0x80016A64: sw          $s5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r21;
    // 0x80016A68: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    // 0x80016A6C: sb          $zero, 0x13($s6)
    MEM_B(0X13, ctx->r22) = 0;
    // 0x80016A70: div.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80016A74: sb          $zero, 0x13($s4)
    MEM_B(0X13, ctx->r20) = 0;
    // 0x80016A78: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80016A7C: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80016A80: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016A84: mul.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80016A88: nop

    // 0x80016A8C: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80016A90: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x80016A94: mul.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80016A98: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x80016A9C: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x80016AA0: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80016AA4: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80016AA8: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80016AAC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80016AB0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80016AB4: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80016AB8: lh          $t2, 0x48($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X48);
    // 0x80016ABC: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80016AC0: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80016AC4: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016AC8: nop

    // 0x80016ACC: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80016AD0: bne         $t2, $at, L_80016B84
    if (ctx->r10 != ctx->r1) {
        // 0x80016AD4: swc1        $f10, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
            goto L_80016B84;
    }
    // 0x80016AD4: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80016AD8: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x80016ADC: nop

    // 0x80016AE0: lb          $t9, 0x1D8($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1D8);
    // 0x80016AE4: nop

    // 0x80016AE8: bne         $t9, $zero, L_80016AFC
    if (ctx->r25 != 0) {
        // 0x80016AEC: nop
    
            goto L_80016AFC;
    }
    // 0x80016AEC: nop

    // 0x80016AF0: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80016AF4: jal         0x80072594
    // 0x80016AF8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    rumble_set(rdram, ctx);
        goto after_4;
    // 0x80016AF8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_4:
L_80016AFC:
    // 0x80016AFC: lb          $t4, 0x1D6($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X1D6);
    // 0x80016B00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016B04: bne         $t4, $at, L_80016B44
    if (ctx->r12 != ctx->r1) {
        // 0x80016B08: nop
    
            goto L_80016B44;
    }
    // 0x80016B08: nop

    // 0x80016B0C: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x80016B10: c.lt.d      $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f26.d < ctx->f6.d;
    // 0x80016B14: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80016B18: bc1f        L_80016B84
    if (!c1cs) {
        // 0x80016B1C: nop
    
            goto L_80016B84;
    }
    // 0x80016B1C: nop

    // 0x80016B20: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80016B24: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80016B28: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80016B2C: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x80016B30: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016B34: nop

    // 0x80016B38: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80016B3C: b           L_80016B84
    // 0x80016B40: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_80016B84;
    // 0x80016B40: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80016B44:
    // 0x80016B44: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x80016B48: c.lt.d      $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f28.d < ctx->f18.d;
    // 0x80016B4C: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80016B50: bc1f        L_80016B84
    if (!c1cs) {
        // 0x80016B54: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80016B84;
    }
    // 0x80016B54: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80016B58: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80016B5C: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80016B60: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80016B64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80016B68: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x80016B6C: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016B70: mul.s       $f16, $f20, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80016B74: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80016B78: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80016B7C: swc1        $f16, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f16.u32l;
    // 0x80016B80: swc1        $f24, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f24.u32l;
L_80016B84:
    // 0x80016B84: lh          $t5, 0x20($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X20);
    // 0x80016B88: addiu       $fp, $fp, 0x2
    ctx->r30 = ADD32(ctx->r30, 0X2);
    // 0x80016B8C: slt         $at, $fp, $t5
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80016B90: bne         $at, $zero, L_800168C0
    if (ctx->r1 != 0) {
        // 0x80016B94: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800168C0;
    }
    // 0x80016B94: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80016B98:
    // 0x80016B98: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_80016B9C:
    // 0x80016B9C: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80016BA0: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016BA4: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80016BA8: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80016BAC: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80016BB0: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80016BB4: lwc1        $f27, 0x40($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80016BB8: lwc1        $f26, 0x44($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80016BBC: lwc1        $f29, 0x48($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x80016BC0: lwc1        $f28, 0x4C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80016BC4: lwc1        $f31, 0x50($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x80016BC8: lwc1        $f30, 0x54($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80016BCC: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80016BD0: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80016BD4: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80016BD8: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x80016BDC: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80016BE0: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80016BE4: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x80016BE8: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x80016BEC: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x80016BF0: jr          $ra
    // 0x80016BF4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x80016BF4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_80016BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016BF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80016BFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80016C00: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80016C04: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80016C08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80016C0C: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80016C10: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80016C14: jal         0x800170D0
    // 0x80016C18: sb          $zero, 0x104($t6)
    MEM_B(0X104, ctx->r14) = 0;
    obj_collision_transform(rdram, ctx);
        goto after_0;
    // 0x80016C18: sb          $zero, 0x104($t6)
    MEM_B(0X104, ctx->r14) = 0;
    after_0:
    // 0x80016C1C: jal         0x800170D0
    // 0x80016C20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_collision_transform(rdram, ctx);
        goto after_1;
    // 0x80016C20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80016C24: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x80016C28: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80016C2C: lb          $v1, 0x55($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X55);
    // 0x80016C30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80016C34: blez        $v1, L_80016C88
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80016C38: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80016C88;
    }
    // 0x80016C38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80016C3C:
    // 0x80016C3C: lw          $t8, 0x68($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X68);
    // 0x80016C40: nop

    // 0x80016C44: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80016C48: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80016C4C: nop

    // 0x80016C50: beq         $v0, $zero, L_80016C74
    if (ctx->r2 == 0) {
        // 0x80016C54: nop
    
            goto L_80016C74;
    }
    // 0x80016C54: nop

    // 0x80016C58: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80016C5C: jal         0x800603BC
    // 0x80016C60: nop

    model_init_collision(rdram, ctx);
        goto after_2;
    // 0x80016C60: nop

    after_2:
    // 0x80016C64: lw          $t0, 0x40($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X40);
    // 0x80016C68: nop

    // 0x80016C6C: lb          $v1, 0x55($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X55);
    // 0x80016C70: nop

L_80016C74:
    // 0x80016C74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80016C78: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80016C7C: bne         $at, $zero, L_80016C3C
    if (ctx->r1 != 0) {
        // 0x80016C80: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80016C3C;
    }
    // 0x80016C80: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80016C84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80016C88:
    // 0x80016C88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016C8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80016C94: jr          $ra
    // 0x80016C98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80016C98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_butterfly_node(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016C9C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80016CA0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80016CA4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80016CA8: addiu       $s6, $s6, -0x4C24
    ctx->r22 = ADD32(ctx->r22, -0X4C24);
    // 0x80016CAC: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x80016CB0: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80016CB4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80016CB8: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80016CBC: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x80016CC0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80016CC4: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80016CC8: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80016CCC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80016CD0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80016CD4: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80016CD8: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x80016CDC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80016CE0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80016CE4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80016CE8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80016CEC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80016CF0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80016CF4: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80016CF8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80016CFC: blez        $t6, L_80016DD0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80016D00: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80016DD0;
    }
    // 0x80016D00: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80016D04: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80016D08: lw          $s3, 0x68($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X68);
    // 0x80016D0C: addiu       $s4, $s4, -0x4C28
    ctx->r20 = ADD32(ctx->r20, -0X4C28);
    // 0x80016D10: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80016D14: addiu       $s5, $zero, 0x55
    ctx->r21 = ADD32(0, 0X55);
L_80016D18:
    // 0x80016D18: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80016D1C: nop

    // 0x80016D20: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80016D24: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x80016D28: nop

    // 0x80016D2C: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x80016D30: nop

    // 0x80016D34: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x80016D38: bne         $t0, $zero, L_80016DBC
    if (ctx->r8 != 0) {
        // 0x80016D3C: nop
    
            goto L_80016DBC;
    }
    // 0x80016D3C: nop

    // 0x80016D40: lh          $t1, 0x48($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X48);
    // 0x80016D44: nop

    // 0x80016D48: bne         $s5, $t1, L_80016DBC
    if (ctx->r21 != ctx->r9) {
        // 0x80016D4C: nop
    
            goto L_80016DBC;
    }
    // 0x80016D4C: nop

    // 0x80016D50: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80016D54: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80016D58: sub.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80016D5C: bne         $s3, $zero, L_80016D90
    if (ctx->r19 != 0) {
        // 0x80016D60: sub.s       $f14, $f6, $f22
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f22.fl;
            goto L_80016D90;
    }
    // 0x80016D60: sub.s       $f14, $f6, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80016D64: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80016D68: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016D6C: sub.s       $f0, $f8, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80016D70: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80016D74: nop

    // 0x80016D78: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80016D7C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80016D80: jal         0x800CA030
    // 0x80016D84: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80016D84: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x80016D88: b           L_80016DA8
    // 0x80016D8C: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
        goto L_80016DA8;
    // 0x80016D8C: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80016D90:
    // 0x80016D90: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016D94: nop

    // 0x80016D98: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80016D9C: jal         0x800CA030
    // 0x80016DA0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80016DA0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x80016DA4: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80016DA8:
    // 0x80016DA8: nop

    // 0x80016DAC: bc1f        L_80016DBC
    if (!c1cs) {
        // 0x80016DB0: nop
    
            goto L_80016DBC;
    }
    // 0x80016DB0: nop

    // 0x80016DB4: b           L_80016DD4
    // 0x80016DB8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80016DD4;
    // 0x80016DB8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80016DBC:
    // 0x80016DBC: lw          $t2, 0x0($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X0);
    // 0x80016DC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80016DC4: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80016DC8: bne         $at, $zero, L_80016D18
    if (ctx->r1 != 0) {
        // 0x80016DCC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80016D18;
    }
    // 0x80016DCC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80016DD0:
    // 0x80016DD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80016DD4:
    // 0x80016DD4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80016DD8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80016DDC: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80016DE0: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80016DE4: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016DE8: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80016DEC: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016DF0: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80016DF4: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80016DF8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80016DFC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80016E00: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80016E04: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80016E08: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80016E0C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80016E10: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80016E14: jr          $ra
    // 0x80016E18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80016E18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void obj_dist_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016E1C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80016E20: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x80016E24: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80016E28: addiu       $s6, $s6, -0x4B90
    ctx->r22 = ADD32(ctx->r22, -0X4B90);
    // 0x80016E2C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x80016E30: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x80016E34: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80016E38: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80016E3C: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x80016E40: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x80016E44: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80016E48: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x80016E4C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80016E50: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80016E54: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80016E58: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x80016E5C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80016E60: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x80016E64: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80016E68: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80016E6C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80016E70: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80016E74: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80016E78: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80016E7C: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80016E80: blez        $v0, L_80017080
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80016E84: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80017080;
    }
    // 0x80016E84: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80016E88: blez        $v0, L_80016F7C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80016E8C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80016F7C;
    }
    // 0x80016E8C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80016E90: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80016E94: lw          $s5, 0xC8($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC8);
    // 0x80016E98: lw          $s0, 0xCC($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XCC);
    // 0x80016E9C: addiu       $s3, $s3, -0x4B9C
    ctx->r19 = ADD32(ctx->r19, -0X4B9C);
    // 0x80016EA0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80016EA4: addiu       $s7, $sp, 0x98
    ctx->r23 = ADD32(ctx->r29, 0X98);
L_80016EA8:
    // 0x80016EA8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80016EAC: nop

    // 0x80016EB0: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x80016EB4: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80016EB8: nop

    // 0x80016EBC: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80016EC0: nop

    // 0x80016EC4: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80016EC8: nop

    // 0x80016ECC: bltz        $a0, L_80016F68
    if (SIGNED(ctx->r4) < 0) {
        // 0x80016ED0: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_80016F68;
    }
    // 0x80016ED0: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80016ED4: beq         $at, $zero, L_80016F68
    if (ctx->r1 == 0) {
        // 0x80016ED8: nop
    
            goto L_80016F68;
    }
    // 0x80016ED8: nop

    // 0x80016EDC: beq         $s5, $zero, L_80016F0C
    if (ctx->r21 == 0) {
        // 0x80016EE0: nop
    
            goto L_80016F0C;
    }
    // 0x80016EE0: nop

    // 0x80016EE4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80016EE8: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80016EEC: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80016EF0: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80016EF4: sub.s       $f2, $f6, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80016EF8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016EFC: jal         0x800CA030
    // 0x80016F00: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80016F00: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80016F04: b           L_80016F40
    // 0x80016F08: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
        goto L_80016F40;
    // 0x80016F08: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80016F0C:
    // 0x80016F0C: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80016F10: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80016F14: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x80016F18: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80016F1C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80016F20: sub.s       $f14, $f18, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f24.fl;
    // 0x80016F24: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80016F28: sub.s       $f2, $f4, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80016F2C: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016F30: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80016F34: jal         0x800CA030
    // 0x80016F38: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80016F38: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_1:
    // 0x80016F3C: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80016F40:
    // 0x80016F40: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x80016F44: bc1f        L_80016F68
    if (!c1cs) {
        // 0x80016F48: addu        $t8, $s7, $v0
        ctx->r24 = ADD32(ctx->r23, ctx->r2);
            goto L_80016F68;
    }
    // 0x80016F48: addu        $t8, $s7, $v0
    ctx->r24 = ADD32(ctx->r23, ctx->r2);
    // 0x80016F4C: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x80016F50: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80016F54: addu        $t2, $s0, $v0
    ctx->r10 = ADD32(ctx->r16, ctx->r2);
    // 0x80016F58: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x80016F5C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80016F60: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80016F64: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_80016F68:
    // 0x80016F68: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80016F6C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80016F70: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80016F74: bne         $at, $zero, L_80016EA8
    if (ctx->r1 != 0) {
        // 0x80016F78: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80016EA8;
    }
    // 0x80016F78: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80016F7C:
    // 0x80016F7C: lw          $s0, 0xCC($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XCC);
    // 0x80016F80: slti        $at, $s4, 0x2
    ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
    // 0x80016F84: bne         $at, $zero, L_80017080
    if (ctx->r1 != 0) {
        // 0x80016F88: addiu       $s1, $s4, -0x1
        ctx->r17 = ADD32(ctx->r20, -0X1);
            goto L_80017080;
    }
    // 0x80016F88: addiu       $s1, $s4, -0x1
    ctx->r17 = ADD32(ctx->r20, -0X1);
    // 0x80016F8C: blez        $s1, L_80017084
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80016F90: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80017084;
    }
    // 0x80016F90: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80016F94:
    // 0x80016F94: blez        $s1, L_80017074
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80016F98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80017074;
    }
    // 0x80016F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016F9C: andi        $v1, $s1, 0x1
    ctx->r3 = ctx->r17 & 0X1;
    // 0x80016FA0: beq         $v1, $zero, L_80016FE4
    if (ctx->r3 == 0) {
        // 0x80016FA4: addiu       $t5, $sp, 0x98
        ctx->r13 = ADD32(ctx->r29, 0X98);
            goto L_80016FE4;
    }
    // 0x80016FA4: addiu       $t5, $sp, 0x98
    ctx->r13 = ADD32(ctx->r29, 0X98);
    // 0x80016FA8: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80016FAC: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80016FB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80016FB4: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80016FB8: nop

    // 0x80016FBC: bc1f        L_80016FE0
    if (!c1cs) {
        // 0x80016FC0: nop
    
            goto L_80016FE0;
    }
    // 0x80016FC0: nop

    // 0x80016FC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80016FC8: swc1        $f18, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f18.u32l;
    // 0x80016FCC: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80016FD0: nop

    // 0x80016FD4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80016FD8: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x80016FDC: sw          $a0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r4;
L_80016FE0:
    // 0x80016FE0: beq         $v0, $s1, L_80017074
    if (ctx->r2 == ctx->r17) {
        // 0x80016FE4: sll         $a1, $v0, 2
        ctx->r5 = S32(ctx->r2 << 2);
            goto L_80017074;
    }
L_80016FE4:
    // 0x80016FE4: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x80016FE8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80016FEC: addu        $a2, $t6, $t5
    ctx->r6 = ADD32(ctx->r14, ctx->r13);
    // 0x80016FF0: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
L_80016FF4:
    // 0x80016FF4: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80016FF8: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80016FFC: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // 0x80017000: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80017004: nop

    // 0x80017008: bc1f        L_80017034
    if (!c1cs) {
        // 0x8001700C: nop
    
            goto L_80017034;
    }
    // 0x8001700C: nop

    // 0x80017010: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80017014: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80017018: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8001701C: nop

    // 0x80017020: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80017024: swc1        $f12, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
    // 0x80017028: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8001702C: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80017030: nop

L_80017034:
    // 0x80017034: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80017038: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // 0x8001703C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80017040: nop

    // 0x80017044: bc1f        L_80017068
    if (!c1cs) {
        // 0x80017048: nop
    
            goto L_80017068;
    }
    // 0x80017048: nop

    // 0x8001704C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80017050: swc1        $f12, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
    // 0x80017054: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80017058: nop

    // 0x8001705C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80017060: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80017064: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
L_80017068:
    // 0x80017068: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001706C: bne         $v1, $a2, L_80016FF4
    if (ctx->r3 != ctx->r6) {
        // 0x80017070: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_80016FF4;
    }
    // 0x80017070: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_80017074:
    // 0x80017074: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80017078: bne         $s1, $zero, L_80016F94
    if (ctx->r17 != 0) {
        // 0x8001707C: nop
    
            goto L_80016F94;
    }
    // 0x8001707C: nop

L_80017080:
    // 0x80017080: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80017084:
    // 0x80017084: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80017088: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8001708C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80017090: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80017094: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80017098: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001709C: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800170A0: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800170A4: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800170A8: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800170AC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800170B0: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800170B4: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x800170B8: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x800170BC: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x800170C0: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800170C4: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x800170C8: jr          $ra
    // 0x800170CC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800170CC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void obj_collision_transform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800170D0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800170D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800170D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800170DC: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x800170E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800170E4: lbu         $t6, 0x104($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X104);
    // 0x800170E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800170EC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800170F0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800170F4: sb          $t8, 0x104($s0)
    MEM_B(0X104, ctx->r16) = ctx->r24;
    // 0x800170F8: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x800170FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017100: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80017104: sh          $t3, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r11;
    // 0x80017108: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x8001710C: andi        $t0, $t8, 0xFF
    ctx->r8 = ctx->r24 & 0XFF;
    // 0x80017110: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80017114: sh          $t5, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r13;
    // 0x80017118: lh          $t6, 0x4($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X4);
    // 0x8001711C: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x80017120: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80017124: sh          $t7, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r15;
    // 0x80017128: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8001712C: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x80017130: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80017134: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80017138: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8001713C: addu        $a0, $s0, $t1
    ctx->r4 = ADD32(ctx->r16, ctx->r9);
    // 0x80017140: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80017144: swc1        $f16, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f16.u32l;
    // 0x80017148: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8001714C: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    // 0x80017150: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80017154: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x80017158: sw          $a0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r4;
    // 0x8001715C: jal         0x800700B4
    // 0x80017160: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x80017160: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_0:
    // 0x80017164: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x80017168: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001716C: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80017170: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80017174: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80017178: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001717C: nop

    // 0x80017180: div.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f12.d, ctx->f8.d);
    // 0x80017184: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80017188: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001718C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80017190: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017194: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
    // 0x80017198: addiu       $v1, $sp, 0x6C
    ctx->r3 = ADD32(ctx->r29, 0X6C);
    // 0x8001719C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800171A0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800171A4: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_800171A8:
    // 0x800171A8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800171AC: swc1        $f0, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f0.u32l;
    // 0x800171B0: swc1        $f0, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f0.u32l;
    // 0x800171B4: swc1        $f0, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f0.u32l;
    // 0x800171B8: bne         $v0, $v1, L_800171A8
    if (ctx->r2 != ctx->r3) {
        // 0x800171BC: swc1        $f0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
            goto L_800171A8;
    }
    // 0x800171BC: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800171C0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800171C4: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x800171C8: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x800171CC: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x800171D0: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    // 0x800171D4: jal         0x8006F9A8
    // 0x800171D8: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    mtxf_mul(rdram, ctx);
        goto after_1;
    // 0x800171D8: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x800171DC: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800171E0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800171E4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800171E8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800171EC: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x800171F0: nop

    // 0x800171F4: div.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800171F8: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x800171FC: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x80017200: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x80017204: nop

    // 0x80017208: sh          $t8, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r24;
    // 0x8001720C: lh          $t9, 0x2($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X2);
    // 0x80017210: nop

    // 0x80017214: sh          $t9, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r25;
    // 0x80017218: lh          $t0, 0x4($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X4);
    // 0x8001721C: nop

    // 0x80017220: sh          $t0, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r8;
    // 0x80017224: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80017228: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x8001722C: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80017230: nop

    // 0x80017234: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80017238: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8001723C: nop

    // 0x80017240: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x80017244: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80017248: nop

    // 0x8001724C: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x80017250: lbu         $t1, 0x104($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X104);
    // 0x80017254: nop

    // 0x80017258: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x8001725C: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x80017260: jal         0x8006FE70
    // 0x80017264: addu        $a0, $s0, $t4
    ctx->r4 = ADD32(ctx->r16, ctx->r12);
    mtxf_from_transform(rdram, ctx);
        goto after_2;
    // 0x80017264: addu        $a0, $s0, $t4
    ctx->r4 = ADD32(ctx->r16, ctx->r12);
    after_2:
    // 0x80017268: sw          $zero, 0x100($s0)
    MEM_W(0X100, ctx->r16) = 0;
    // 0x8001726C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80017270: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017274: jr          $ra
    // 0x80017278: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80017278: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void collision_objectmodel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001727C: addiu       $sp, $sp, -0x178
    ctx->r29 = ADD32(ctx->r29, -0X178);
    // 0x80017280: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80017284: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80017288: addiu       $s5, $s5, -0x4C10
    ctx->r21 = ADD32(ctx->r21, -0X4C10);
    // 0x8001728C: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80017290: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80017294: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80017298: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8001729C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800172A0: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800172A4: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800172A8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800172AC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800172B0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800172B4: swc1        $f21, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800172B8: swc1        $f20, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f20.u32l;
    // 0x800172BC: sw          $a1, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r5;
    // 0x800172C0: sw          $a3, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r7;
    // 0x800172C4: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
    // 0x800172C8: sw          $zero, 0x170($sp)
    MEM_W(0X170, ctx->r29) = 0;
    // 0x800172CC: blez        $t6, L_800174BC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800172D0: sw          $a2, 0x180($sp)
        MEM_W(0X180, ctx->r29) = ctx->r6;
            goto L_800174BC;
    }
    // 0x800172D0: sw          $a2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r6;
    // 0x800172D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800172D8: sw          $a0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r4;
    // 0x800172DC: sw          $a2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r6;
    // 0x800172E0: addiu       $s4, $sp, 0x8C
    ctx->r20 = ADD32(ctx->r29, 0X8C);
    // 0x800172E4: addiu       $s3, $sp, 0xB4
    ctx->r19 = ADD32(ctx->r29, 0XB4);
    // 0x800172E8: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
L_800172EC:
    // 0x800172EC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800172F0: lw          $t7, -0x4C14($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C14);
    // 0x800172F4: lw          $a0, 0x178($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X178);
    // 0x800172F8: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800172FC: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80017300: nop

    // 0x80017304: lb          $t2, 0x3A($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X3A);
    // 0x80017308: lw          $t9, 0x68($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X68);
    // 0x8001730C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80017310: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80017314: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80017318: nop

    // 0x8001731C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80017320: nop

    // 0x80017324: sw          $t5, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r13;
    // 0x80017328: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001732C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80017330: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80017334: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80017338: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001733C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80017340: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80017344: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80017348: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001734C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80017350: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80017354: sw          $v0, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r2;
    // 0x80017358: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001735C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80017360: jal         0x800CA030
    // 0x80017364: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80017364: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80017368: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001736C: lw          $a0, 0x158($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X158);
    // 0x80017370: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80017374: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80017378: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001737C: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x80017380: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80017384: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x80017388: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8001738C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80017390: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x80017394: beq         $t8, $zero, L_800173A0
    if (ctx->r24 == 0) {
        // 0x80017398: or          $fp, $v0, $zero
        ctx->r30 = ctx->r2 | 0;
            goto L_800173A0;
    }
    // 0x80017398: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x8001739C: sra         $fp, $v0, 3
    ctx->r30 = S32(SIGNED(ctx->r2) >> 3);
L_800173A0:
    // 0x800173A0: slti        $at, $fp, 0x100
    ctx->r1 = SIGNED(ctx->r30) < 0X100 ? 1 : 0;
    // 0x800173A4: bne         $at, $zero, L_800173B0
    if (ctx->r1 != 0) {
        // 0x800173A8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800173B0;
    }
    // 0x800173A8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800173AC: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
L_800173B0:
    // 0x800173B0: lbu         $t2, 0x13($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X13);
    // 0x800173B4: nop

    // 0x800173B8: slt         $at, $fp, $t2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800173BC: beq         $at, $zero, L_800173DC
    if (ctx->r1 == 0) {
        // 0x800173C0: lw          $t4, 0x154($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X154);
            goto L_800173DC;
    }
    // 0x800173C0: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x800173C4: sb          $fp, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r30;
    // 0x800173C8: lw          $t3, 0x4C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C);
    // 0x800173CC: lw          $t9, 0x178($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X178);
    // 0x800173D0: nop

    // 0x800173D4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800173D8: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
L_800173DC:
    // 0x800173DC: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800173E0: lwc1        $f6, 0x3C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X3C);
    // 0x800173E4: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800173E8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800173EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800173F0: lw          $a1, 0x160($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X160);
    // 0x800173F4: lw          $t5, 0x170($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X170);
    // 0x800173F8: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800173FC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80017400: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80017404: addu        $t6, $s3, $v0
    ctx->r14 = ADD32(ctx->r19, ctx->r2);
    // 0x80017408: bc1f        L_80017494
    if (!c1cs) {
        // 0x8001740C: addu        $v1, $s4, $v0
        ctx->r3 = ADD32(ctx->r20, ctx->r2);
            goto L_80017494;
    }
    // 0x8001740C: addu        $v1, $s4, $v0
    ctx->r3 = ADD32(ctx->r20, ctx->r2);
    // 0x80017410: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80017414: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80017418: blez        $a1, L_8001748C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8001741C: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_8001748C;
    }
    // 0x8001741C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80017420: lwc1        $f16, -0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80017424: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80017428: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x8001742C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80017430: addu        $v1, $s4, $a0
    ctx->r3 = ADD32(ctx->r20, ctx->r4);
    // 0x80017434: bc1f        L_8001748C
    if (!c1cs) {
        // 0x80017438: nop
    
            goto L_8001748C;
    }
    // 0x80017438: nop

    // 0x8001743C: lwc1        $f0, -0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80017440: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80017444: addu        $v0, $s3, $a0
    ctx->r2 = ADD32(ctx->r19, ctx->r4);
L_80017448:
    // 0x80017448: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8001744C: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x80017450: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80017454: sltu        $at, $v0, $s0
    ctx->r1 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x80017458: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8001745C: swc1        $f2, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f2.u32l;
    // 0x80017460: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80017464: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80017468: bne         $at, $zero, L_8001748C
    if (ctx->r1 != 0) {
        // 0x8001746C: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_8001748C;
    }
    // 0x8001746C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80017470: lwc1        $f0, -0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80017474: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80017478: nop

    // 0x8001747C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80017480: nop

    // 0x80017484: bc1t        L_80017448
    if (c1cs) {
        // 0x80017488: nop
    
            goto L_80017448;
    }
    // 0x80017488: nop

L_8001748C:
    // 0x8001748C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80017490: sw          $a1, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r5;
L_80017494:
    // 0x80017494: lw          $t8, 0x170($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X170);
    // 0x80017498: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x8001749C: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x800174A0: lw          $a1, 0x160($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X160);
    // 0x800174A4: slt         $at, $t2, $t9
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800174A8: bne         $at, $zero, L_800172EC
    if (ctx->r1 != 0) {
        // 0x800174AC: sw          $t2, 0x170($sp)
        MEM_W(0X170, ctx->r29) = ctx->r10;
            goto L_800172EC;
    }
    // 0x800174AC: sw          $t2, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r10;
    // 0x800174B0: lw          $a0, 0x178($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X178);
    // 0x800174B4: sw          $zero, 0x170($sp)
    MEM_W(0X170, ctx->r29) = 0;
    // 0x800174B8: sw          $a1, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r5;
L_800174BC:
    // 0x800174BC: lw          $t3, 0x160($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X160);
    // 0x800174C0: lw          $a2, 0x180($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X180);
    // 0x800174C4: blez        $t3, L_800178A8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800174C8: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800178A8;
    }
    // 0x800174C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800174CC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800174D0: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x800174D4: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x800174D8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800174DC: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x800174E0: sw          $a0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r4;
    // 0x800174E4: sw          $a2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r6;
    // 0x800174E8: sw          $zero, 0x168($sp)
    MEM_W(0X168, ctx->r29) = 0;
L_800174EC:
    // 0x800174EC: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x800174F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800174F4: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800174F8: lw          $t4, -0x4C14($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4C14);
    // 0x800174FC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80017500: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80017504: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80017508: lw          $a0, 0x178($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X178);
    // 0x8001750C: lb          $t2, 0x3A($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X3A);
    // 0x80017510: lw          $t8, 0x68($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X68);
    // 0x80017514: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x80017518: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8001751C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80017520: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80017524: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80017528: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001752C: sw          $t5, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r13;
    // 0x80017530: lw          $v0, 0x5C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X5C);
    // 0x80017534: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80017538: lbu         $t4, 0x104($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X104);
    // 0x8001753C: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x80017540: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80017544: andi        $t2, $t6, 0x1
    ctx->r10 = ctx->r14 & 0X1;
    // 0x80017548: sll         $t8, $t2, 6
    ctx->r24 = S32(ctx->r10 << 6);
    // 0x8001754C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80017550: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x80017554: jal         0x80017940
    // 0x80017558: sw          $a1, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r5;
    func_8001790C(rdram, ctx);
        goto after_1;
    // 0x80017558: sw          $a1, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r5;
    after_1:
    // 0x8001755C: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x80017560: beq         $v0, $zero, L_80017614
    if (ctx->r2 == 0) {
        // 0x80017564: sw          $v0, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r2;
            goto L_80017614;
    }
    // 0x80017564: sw          $v0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r2;
    // 0x80017568: lw          $t3, 0x17C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X17C);
    // 0x8001756C: addiu       $s2, $sp, 0x13C
    ctx->r18 = ADD32(ctx->r29, 0X13C);
    // 0x80017570: blez        $t3, L_80017678
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80017574: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80017678;
    }
    // 0x80017574: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80017578: lw          $s1, 0x188($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X188);
    // 0x8001757C: addiu       $s3, $sp, 0x12C
    ctx->r19 = ADD32(ctx->r29, 0X12C);
    // 0x80017580: addiu       $s4, $sp, 0x11C
    ctx->r20 = ADD32(ctx->r29, 0X11C);
    // 0x80017584: addiu       $s5, $sp, 0x100
    ctx->r21 = ADD32(ctx->r29, 0X100);
    // 0x80017588: addiu       $s6, $sp, 0xF0
    ctx->r22 = ADD32(ctx->r29, 0XF0);
    // 0x8001758C: addiu       $s7, $sp, 0xE0
    ctx->r23 = ADD32(ctx->r29, 0XE0);
L_80017590:
    // 0x80017590: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80017594: nop

    // 0x80017598: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    // 0x8001759C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800175A0: nop

    // 0x800175A4: swc1        $f8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f8.u32l;
    // 0x800175A8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800175AC: nop

    // 0x800175B0: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x800175B4: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x800175B8: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x800175BC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800175C0: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800175C4: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x800175C8: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x800175CC: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x800175D0: jal         0x8006F88C
    // 0x800175D4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x800175D4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_2:
    // 0x800175D8: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800175DC: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800175E0: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x800175E4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800175E8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800175EC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800175F0: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800175F4: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800175F8: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800175FC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80017600: bne         $fp, $t5, L_80017590
    if (ctx->r30 != ctx->r13) {
        // 0x80017604: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80017590;
    }
    // 0x80017604: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80017608: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001760C: b           L_80017678
    // 0x80017610: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
        goto L_80017678;
    // 0x80017610: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_80017614:
    // 0x80017614: lw          $t4, 0x17C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X17C);
    // 0x80017618: addiu       $s2, $sp, 0x13C
    ctx->r18 = ADD32(ctx->r29, 0X13C);
    // 0x8001761C: blez        $t4, L_80017678
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80017620: addiu       $s3, $sp, 0x12C
        ctx->r19 = ADD32(ctx->r29, 0X12C);
            goto L_80017678;
    }
    // 0x80017620: addiu       $s3, $sp, 0x12C
    ctx->r19 = ADD32(ctx->r29, 0X12C);
    // 0x80017624: lw          $s0, 0x184($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X184);
    // 0x80017628: addiu       $s4, $sp, 0x11C
    ctx->r20 = ADD32(ctx->r29, 0X11C);
L_8001762C:
    // 0x8001762C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80017630: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80017634: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80017638: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x8001763C: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x80017640: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80017644: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80017648: jal         0x8006F88C
    // 0x8001764C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x8001764C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_3:
    // 0x80017650: lw          $t6, 0x17C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X17C);
    // 0x80017654: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80017658: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x8001765C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80017660: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80017664: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80017668: bne         $fp, $t6, L_8001762C
    if (ctx->r30 != ctx->r14) {
        // 0x8001766C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8001762C;
    }
    // 0x8001766C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80017670: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80017674: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_80017678:
    // 0x80017678: lw          $t7, 0x17C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X17C);
    // 0x8001767C: addiu       $s5, $sp, 0x100
    ctx->r21 = ADD32(ctx->r29, 0X100);
    // 0x80017680: blez        $t7, L_800176D8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80017684: addiu       $s6, $sp, 0xF0
        ctx->r22 = ADD32(ctx->r29, 0XF0);
            goto L_800176D8;
    }
    // 0x80017684: addiu       $s6, $sp, 0xF0
    ctx->r22 = ADD32(ctx->r29, 0XF0);
    // 0x80017688: lw          $s1, 0x188($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X188);
    // 0x8001768C: addiu       $s7, $sp, 0xE0
    ctx->r23 = ADD32(ctx->r29, 0XE0);
L_80017690:
    // 0x80017690: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80017694: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80017698: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x8001769C: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800176A0: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x800176A4: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x800176A8: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x800176AC: jal         0x8006F88C
    // 0x800176B0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    mtxf_transform_point(rdram, ctx);
        goto after_4;
    // 0x800176B0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_4:
    // 0x800176B4: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x800176B8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800176BC: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x800176C0: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800176C4: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800176C8: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800176CC: bne         $fp, $t2, L_80017690
    if (ctx->r30 != ctx->r10) {
        // 0x800176D0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80017690;
    }
    // 0x800176D0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800176D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800176D8:
    // 0x800176D8: lw          $a2, 0x180($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X180);
    // 0x800176DC: addiu       $t8, $sp, 0x12C
    ctx->r24 = ADD32(ctx->r29, 0X12C);
    // 0x800176E0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800176E4: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x800176E8: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800176EC: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x800176F0: addiu       $t9, $sp, 0x11C
    ctx->r25 = ADD32(ctx->r29, 0X11C);
    // 0x800176F4: addiu       $t3, $sp, 0x100
    ctx->r11 = ADD32(ctx->r29, 0X100);
    // 0x800176F8: addiu       $t5, $sp, 0xF0
    ctx->r13 = ADD32(ctx->r29, 0XF0);
    // 0x800176FC: addiu       $t4, $sp, 0xE0
    ctx->r12 = ADD32(ctx->r29, 0XE0);
    // 0x80017700: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80017704: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80017708: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8001770C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80017710: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80017714: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80017718: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8001771C: lwc1        $f10, 0x8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80017720: lw          $a1, 0x17C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X17C);
    // 0x80017724: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80017728: nop

    // 0x8001772C: div.d       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f20.d, ctx->f16.d);
    // 0x80017730: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x80017734: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x80017738: addiu       $a3, $sp, 0x13C
    ctx->r7 = ADD32(ctx->r29, 0X13C);
    // 0x8001773C: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80017740: jal         0x80017A4C
    // 0x80017744: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_80017A18(rdram, ctx);
        goto after_5;
    // 0x80017744: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80017748: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x8001774C: beq         $v0, $zero, L_80017768
    if (ctx->r2 == 0) {
        // 0x80017750: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80017768;
    }
    // 0x80017750: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80017754: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x80017758: lw          $t8, 0x178($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X178);
    // 0x8001775C: lw          $t9, 0x5C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X5C);
    // 0x80017760: nop

    // 0x80017764: sw          $t8, 0x100($t9)
    MEM_W(0X100, ctx->r25) = ctx->r24;
L_80017768:
    // 0x80017768: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001776C: lb          $t3, -0x4D5C($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X4D5C);
    // 0x80017770: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x80017774: bne         $t3, $zero, L_80017794
    if (ctx->r11 != 0) {
        // 0x80017778: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80017794;
    }
    // 0x80017778: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8001777C: lw          $a0, 0x178($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X178);
    // 0x80017780: jal         0x800179AC
    // 0x80017784: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    func_80017978(rdram, ctx);
        goto after_6;
    // 0x80017784: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    after_6:
    // 0x80017788: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x8001778C: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x80017790: sw          $v0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r2;
L_80017794:
    // 0x80017794: lw          $v0, 0x5C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X5C);
    // 0x80017798: lw          $t8, 0x17C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X17C);
    // 0x8001779C: lbu         $t5, 0x104($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X104);
    // 0x800177A0: nop

    // 0x800177A4: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x800177A8: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800177AC: addu        $t2, $v0, $t7
    ctx->r10 = ADD32(ctx->r2, ctx->r15);
    // 0x800177B0: blez        $t8, L_80017874
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800177B4: sw          $t2, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->r10;
            goto L_80017874;
    }
    // 0x800177B4: sw          $t2, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r10;
L_800177B8:
    // 0x800177B8: lw          $t9, 0x14C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14C);
    // 0x800177BC: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800177C0: beq         $t9, $zero, L_800177F8
    if (ctx->r25 == 0) {
        // 0x800177C4: and         $t7, $s2, $t0
        ctx->r15 = ctx->r18 & ctx->r8;
            goto L_800177F8;
    }
    // 0x800177C4: and         $t7, $s2, $t0
    ctx->r15 = ctx->r18 & ctx->r8;
    // 0x800177C8: sll         $v0, $fp, 2
    ctx->r2 = S32(ctx->r30 << 2);
    // 0x800177CC: addu        $t5, $sp, $v0
    ctx->r13 = ADD32(ctx->r29, ctx->r2);
    // 0x800177D0: lwc1        $f8, 0x100($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X100);
    // 0x800177D4: addu        $s0, $t9, $t3
    ctx->r16 = ADD32(ctx->r25, ctx->r11);
    // 0x800177D8: addu        $t4, $sp, $v0
    ctx->r12 = ADD32(ctx->r29, ctx->r2);
    // 0x800177DC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800177E0: lwc1        $f4, 0xF0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XF0);
    // 0x800177E4: addu        $t6, $sp, $v0
    ctx->r14 = ADD32(ctx->r29, ctx->r2);
    // 0x800177E8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800177EC: lwc1        $f10, 0xE0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XE0);
    // 0x800177F0: nop

    // 0x800177F4: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
L_800177F8:
    // 0x800177F8: beq         $t7, $zero, L_8001785C
    if (ctx->r15 == 0) {
        // 0x800177FC: sll         $v0, $fp, 2
        ctx->r2 = S32(ctx->r30 << 2);
            goto L_8001785C;
    }
    // 0x800177FC: sll         $v0, $fp, 2
    ctx->r2 = S32(ctx->r30 << 2);
    // 0x80017800: addu        $t2, $sp, $v0
    ctx->r10 = ADD32(ctx->r29, ctx->r2);
    // 0x80017804: addu        $t8, $sp, $v0
    ctx->r24 = ADD32(ctx->r29, ctx->r2);
    // 0x80017808: addu        $t9, $sp, $v0
    ctx->r25 = ADD32(ctx->r29, ctx->r2);
    // 0x8001780C: lw          $v1, 0x188($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X188);
    // 0x80017810: lw          $a3, 0xE0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XE0);
    // 0x80017814: lw          $a2, 0xF0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XF0);
    // 0x80017818: lw          $a1, 0x100($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X100);
    // 0x8001781C: addiu       $t2, $s1, 0x2
    ctx->r10 = ADD32(ctx->r17, 0X2);
    // 0x80017820: addiu       $t4, $s1, 0x1
    ctx->r12 = ADD32(ctx->r17, 0X1);
    // 0x80017824: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80017828: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8001782C: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80017830: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x80017834: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x80017838: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8001783C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80017840: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80017844: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80017848: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8001784C: jal         0x8006F88C
    // 0x80017850: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    mtxf_transform_point(rdram, ctx);
        goto after_7;
    // 0x80017850: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    after_7:
    // 0x80017854: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x80017858: nop

L_8001785C:
    // 0x8001785C: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x80017860: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80017864: sll         $t3, $t0, 1
    ctx->r11 = S32(ctx->r8 << 1);
    // 0x80017868: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x8001786C: bne         $fp, $t5, L_800177B8
    if (ctx->r30 != ctx->r13) {
        // 0x80017870: addiu       $s1, $s1, 0x3
        ctx->r17 = ADD32(ctx->r17, 0X3);
            goto L_800177B8;
    }
    // 0x80017870: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
L_80017874:
    // 0x80017874: lw          $t4, 0x168($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X168);
    // 0x80017878: lw          $t7, 0x170($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X170);
    // 0x8001787C: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x80017880: lw          $t3, 0x160($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X160);
    // 0x80017884: or          $t6, $t4, $s2
    ctx->r14 = ctx->r12 | ctx->r18;
    // 0x80017888: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8001788C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80017890: sw          $t6, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r14;
    // 0x80017894: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x80017898: bne         $t2, $t3, L_800174EC
    if (ctx->r10 != ctx->r11) {
        // 0x8001789C: sw          $t2, 0x170($sp)
        MEM_W(0X170, ctx->r29) = ctx->r10;
            goto L_800174EC;
    }
    // 0x8001789C: sw          $t2, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r10;
    // 0x800178A0: lw          $a2, 0x180($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X180);
    // 0x800178A4: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_800178A8:
    // 0x800178A8: andi        $t5, $a3, 0x1
    ctx->r13 = ctx->r7 & 0X1;
    // 0x800178AC: beq         $t5, $zero, L_800178BC
    if (ctx->r13 == 0) {
        // 0x800178B0: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_800178BC;
    }
    // 0x800178B0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800178B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800178B8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_800178BC:
    // 0x800178BC: andi        $t8, $a3, 0x2
    ctx->r24 = ctx->r7 & 0X2;
    // 0x800178C0: beq         $t8, $zero, L_800178D8
    if (ctx->r24 == 0) {
        // 0x800178C4: andi        $t3, $a3, 0x4
        ctx->r11 = ctx->r7 & 0X4;
            goto L_800178D8;
    }
    // 0x800178C4: andi        $t3, $a3, 0x4
    ctx->r11 = ctx->r7 & 0X4;
    // 0x800178C8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800178CC: nop

    // 0x800178D0: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800178D4: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_800178D8:
    // 0x800178D8: beq         $t3, $zero, L_800178F0
    if (ctx->r11 == 0) {
        // 0x800178DC: andi        $t4, $a3, 0x8
        ctx->r12 = ctx->r7 & 0X8;
            goto L_800178F0;
    }
    // 0x800178DC: andi        $t4, $a3, 0x8
    ctx->r12 = ctx->r7 & 0X8;
    // 0x800178E0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800178E4: nop

    // 0x800178E8: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x800178EC: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
L_800178F0:
    // 0x800178F0: beq         $t4, $zero, L_80017908
    if (ctx->r12 == 0) {
        // 0x800178F4: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_80017908;
    }
    // 0x800178F4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800178F8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800178FC: nop

    // 0x80017900: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80017904: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_80017908:
    // 0x80017908: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8001790C: lwc1        $f21, 0x38($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80017910: lwc1        $f20, 0x3C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80017914: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80017918: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8001791C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80017920: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80017924: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80017928: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8001792C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80017930: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80017934: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80017938: jr          $ra
    // 0x8001793C: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
    return;
    // 0x8001793C: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
;}
RECOMP_FUNC void func_8001790C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017940: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80017944: lw          $a2, -0x4A8C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4A8C);
    // 0x80017948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001794C: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
L_80017950:
    // 0x80017950: addu        $v1, $t6, $a2
    ctx->r3 = ADD32(ctx->r14, ctx->r6);
    // 0x80017954: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80017958: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001795C: beq         $t7, $zero, L_80017990
    if (ctx->r15 == 0) {
        // 0x80017960: sll         $t0, $v0, 16
        ctx->r8 = S32(ctx->r2 << 16);
            goto L_80017990;
    }
    // 0x80017960: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x80017964: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80017968: nop

    // 0x8001796C: bne         $a0, $t8, L_80017990
    if (ctx->r4 != ctx->r24) {
        // 0x80017970: nop
    
            goto L_80017990;
    }
    // 0x80017970: nop

    // 0x80017974: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80017978: nop

    // 0x8001797C: bne         $a1, $t9, L_80017994
    if (ctx->r5 != ctx->r25) {
        // 0x80017980: sra         $v0, $t0, 16
        ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
            goto L_80017994;
    }
    // 0x80017980: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80017984: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80017988: jr          $ra
    // 0x8001798C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001798C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80017990:
    // 0x80017990: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
L_80017994:
    // 0x80017994: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80017998: bne         $at, $zero, L_80017950
    if (ctx->r1 != 0) {
        // 0x8001799C: sll         $t6, $v0, 6
        ctx->r14 = S32(ctx->r2 << 6);
            goto L_80017950;
    }
    // 0x8001799C: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x800179A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800179A4: jr          $ra
    // 0x800179A8: nop

    return;
    // 0x800179A8: nop

;}
RECOMP_FUNC void func_80017978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800179AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800179B0: lw          $a2, -0x4A8C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4A8C);
    // 0x800179B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800179B8: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
L_800179BC:
    // 0x800179BC: addu        $v1, $t6, $a2
    ctx->r3 = ADD32(ctx->r14, ctx->r6);
    // 0x800179C0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800179C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800179C8: bne         $t7, $zero, L_800179E8
    if (ctx->r15 != 0) {
        // 0x800179CC: sll         $t9, $v0, 16
        ctx->r25 = S32(ctx->r2 << 16);
            goto L_800179E8;
    }
    // 0x800179CC: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800179D0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800179D4: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800179D8: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x800179DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800179E0: jr          $ra
    // 0x800179E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800179E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800179E8:
    // 0x800179E8: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800179EC: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800179F0: bne         $at, $zero, L_800179BC
    if (ctx->r1 != 0) {
        // 0x800179F4: sll         $t6, $v0, 6
        ctx->r14 = S32(ctx->r2 << 6);
            goto L_800179BC;
    }
    // 0x800179F4: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x800179F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800179FC: jr          $ra
    // 0x80017A00: nop

    return;
    // 0x80017A00: nop

;}
RECOMP_FUNC void func_800179D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017A04: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80017A08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017A0C: addiu       $a1, $a1, -0x4A8C
    ctx->r5 = ADD32(ctx->r5, -0X4A8C);
L_80017A10:
    // 0x80017A10: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80017A14: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x80017A18: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80017A1C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80017A20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80017A24: beq         $a0, $zero, L_80017A34
    if (ctx->r4 == 0) {
        // 0x80017A28: sll         $t9, $v0, 16
        ctx->r25 = S32(ctx->r2 << 16);
            goto L_80017A34;
    }
    // 0x80017A28: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80017A2C: addiu       $t8, $a0, -0x1
    ctx->r24 = ADD32(ctx->r4, -0X1);
    // 0x80017A30: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80017A34:
    // 0x80017A34: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80017A38: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80017A3C: bne         $at, $zero, L_80017A10
    if (ctx->r1 != 0) {
        // 0x80017A40: nop
    
            goto L_80017A10;
    }
    // 0x80017A40: nop

    // 0x80017A44: jr          $ra
    // 0x80017A48: nop

    return;
    // 0x80017A48: nop

;}
RECOMP_FUNC void func_80017A18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017A4C: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x80017A50: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80017A54: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80017A58: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80017A5C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80017A60: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80017A64: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80017A68: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80017A6C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80017A70: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80017A74: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80017A78: swc1        $f31, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80017A7C: swc1        $f30, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f30.u32l;
    // 0x80017A80: swc1        $f29, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80017A84: swc1        $f28, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f28.u32l;
    // 0x80017A88: swc1        $f27, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80017A8C: swc1        $f26, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f26.u32l;
    // 0x80017A90: swc1        $f25, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80017A94: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x80017A98: swc1        $f23, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80017A9C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80017AA0: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80017AA4: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x80017AA8: sw          $a1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r5;
    // 0x80017AAC: sw          $a2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r6;
    // 0x80017AB0: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
    // 0x80017AB4: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x80017AB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80017ABC: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80017AC0: blez        $a1, L_80017E44
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80017AC4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80017E44;
    }
    // 0x80017AC4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80017AC8: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x80017ACC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80017AD0: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x80017AD4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80017AD8: lw          $s2, 0x138($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X138);
    // 0x80017ADC: lw          $s3, 0x13C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X13C);
    // 0x80017AE0: lw          $s4, 0x140($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X140);
    // 0x80017AE4: lw          $fp, 0x130($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X130);
    // 0x80017AE8: lw          $ra, 0x134($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X134);
    // 0x80017AEC: lw          $s5, 0x148($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X148);
    // 0x80017AF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80017AF4: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
L_80017AF8:
    // 0x80017AF8: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80017AFC: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80017B00: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80017B04: lwc1        $f8, 0x0($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80017B08: lwc1        $f30, 0x0($s3)
    ctx->f30.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80017B0C: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    // 0x80017B10: lwc1        $f10, 0x14C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x80017B14: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80017B18: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80017B1C: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80017B20: lwc1        $f20, 0x0($fp)
    ctx->f20.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80017B24: lwc1        $f22, 0x0($ra)
    ctx->f22.u32l = MEM_W(ctx->r31, 0X0);
    // 0x80017B28: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80017B2C: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
    // 0x80017B30: lh          $t3, 0x32($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X32);
    // 0x80017B34: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80017B38: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
L_80017B3C:
    // 0x80017B3C: blez        $t3, L_80017DDC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80017B40: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80017DDC;
    }
    // 0x80017B40: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80017B44: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x80017B48: swc1        $f20, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f20.u32l;
    // 0x80017B4C: swc1        $f22, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f22.u32l;
L_80017B50:
    // 0x80017B50: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80017B54: lwc1        $f28, 0xA4($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80017B58: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80017B5C: lwc1        $f20, 0x9C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80017B60: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x80017B64: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80017B68: lhu         $t7, 0x0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X0);
    // 0x80017B6C: lwc1        $f18, 0xC0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80017B70: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x80017B74: addu        $v0, $t0, $t6
    ctx->r2 = ADD32(ctx->r8, ctx->r14);
    // 0x80017B78: lwc1        $f26, 0x4($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80017B7C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80017B80: mul.s       $f14, $f26, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f6.fl);
    // 0x80017B84: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80017B88: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80017B8C: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    // 0x80017B90: mul.s       $f4, $f16, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f28.fl);
    // 0x80017B94: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80017B98: swc1        $f12, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f12.u32l;
    // 0x80017B9C: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80017BA0: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80017BA4: add.s       $f4, $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80017BA8: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80017BAC: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80017BB0: mul.s       $f14, $f26, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f30.fl);
    // 0x80017BB4: add.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80017BB8: swc1        $f10, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f10.u32l;
    // 0x80017BBC: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80017BC0: mul.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80017BC4: add.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017BC8: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80017BCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017BD0: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80017BD4: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80017BD8: lwc1        $f10, 0x5B9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5B9C);
    // 0x80017BDC: swc1        $f28, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f28.u32l;
    // 0x80017BE0: add.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80017BE4: swc1        $f20, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f20.u32l;
    // 0x80017BE8: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80017BEC: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x80017BF0: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x80017BF4: lwc1        $f11, 0x5B98($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X5B98);
    // 0x80017BF8: cvt.d.s     $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.d = CVT_D_S(ctx->f0.fl);
    // 0x80017BFC: c.le.d      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.d <= ctx->f14.d;
    // 0x80017C00: sub.s       $f22, $f12, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80017C04: bc1f        L_80017DBC
    if (!c1cs) {
        // 0x80017C08: swc1        $f8, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
            goto L_80017DBC;
    }
    // 0x80017C08: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x80017C0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017C10: lwc1        $f9, 0x5BA0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5BA0);
    // 0x80017C14: lwc1        $f8, 0x5BA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5BA4);
    // 0x80017C18: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x80017C1C: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80017C20: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80017C24: bc1f        L_80017DBC
    if (!c1cs) {
        // 0x80017C28: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80017DBC;
    }
    // 0x80017C28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80017C2C: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80017C30: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80017C34: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80017C38: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x80017C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017C40: sub.s       $f28, $f6, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80017C44: bc1t        L_80017C58
    if (c1cs) {
        // 0x80017C48: sub.s       $f14, $f30, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f30.fl - ctx->f8.fl;
            goto L_80017C58;
    }
    // 0x80017C48: sub.s       $f14, $f30, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f30.fl - ctx->f8.fl;
    // 0x80017C4C: sub.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80017C50: b           L_80017C60
    // 0x80017C54: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
        goto L_80017C60;
    // 0x80017C54: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
L_80017C58:
    // 0x80017C58: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80017C5C: nop

L_80017C60:
    // 0x80017C60: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80017C64: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80017C68: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80017C6C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80017C70: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80017C74: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80017C78: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80017C7C: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    // 0x80017C80: mul.s       $f8, $f28, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x80017C84: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017C88: add.s       $f20, $f8, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f6.fl;
L_80017C8C:
    // 0x80017C8C: lhu         $t8, 0x2($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X2);
    // 0x80017C90: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80017C94: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80017C98: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x80017C9C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80017CA0: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80017CA4: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80017CA8: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80017CAC: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80017CB0: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80017CB4: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80017CB8: nop

    // 0x80017CBC: mul.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80017CC0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017CC4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80017CC8: add.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80017CCC: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x80017CD0: nop

    // 0x80017CD4: bc1f        L_80017CE0
    if (!c1cs) {
        // 0x80017CD8: nop
    
            goto L_80017CE0;
    }
    // 0x80017CD8: nop

    // 0x80017CDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80017CE0:
    // 0x80017CE0: beq         $at, $zero, L_80017CF0
    if (ctx->r1 == 0) {
        // 0x80017CE4: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80017CF0;
    }
    // 0x80017CE4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80017CE8: beq         $a2, $a3, L_80017C8C
    if (ctx->r6 == ctx->r7) {
        // 0x80017CEC: nop
    
            goto L_80017C8C;
    }
    // 0x80017CEC: nop

L_80017CF0:
    // 0x80017CF0: beq         $a2, $zero, L_80017DBC
    if (ctx->r6 == 0) {
        // 0x80017CF4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80017DBC;
    }
    // 0x80017CF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017CF8: lwc1        $f9, 0x5BA8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5BA8);
    // 0x80017CFC: lwc1        $f8, 0x5BAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5BAC);
    // 0x80017D00: cvt.d.s     $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f6.d = CVT_D_S(ctx->f26.fl);
    // 0x80017D04: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80017D08: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80017D0C: bc1f        L_80017D38
    if (!c1cs) {
        // 0x80017D10: addu        $v0, $s5, $s1
        ctx->r2 = ADD32(ctx->r21, ctx->r17);
            goto L_80017D38;
    }
    // 0x80017D10: addu        $v0, $s5, $s1
    ctx->r2 = ADD32(ctx->r21, ctx->r17);
    // 0x80017D14: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80017D18: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80017D1C: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80017D20: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017D24: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80017D28: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80017D2C: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80017D30: b           L_80017D68
    // 0x80017D34: div.s       $f30, $f8, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f30.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
        goto L_80017D68;
    // 0x80017D34: div.s       $f30, $f8, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f30.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
L_80017D38:
    // 0x80017D38: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80017D3C: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80017D40: mul.s       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x80017D44: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80017D48: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80017D4C: mul.s       $f10, $f22, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x80017D50: swc1        $f8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f8.u32l;
    // 0x80017D54: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80017D58: mul.s       $f8, $f22, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80017D5C: sub.s       $f30, $f30, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f30.fl - ctx->f10.fl;
    // 0x80017D60: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80017D64: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
L_80017D68:
    // 0x80017D68: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80017D6C: slti        $at, $t4, 0xB
    ctx->r1 = SIGNED(ctx->r12) < 0XB ? 1 : 0;
    // 0x80017D70: bne         $at, $zero, L_80017D90
    if (ctx->r1 != 0) {
        // 0x80017D74: nop
    
            goto L_80017D90;
    }
    // 0x80017D74: nop

    // 0x80017D78: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80017D7C: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80017D80: lwc1        $f30, 0xA0($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80017D84: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80017D88: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80017D8C: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
L_80017D90:
    // 0x80017D90: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80017D94: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80017D98: nop

    // 0x80017D9C: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
    // 0x80017DA0: swc1        $f30, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f30.u32l;
    // 0x80017DA4: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80017DA8: nop

    // 0x80017DAC: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80017DB0: lh          $t3, 0x32($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X32);
    // 0x80017DB4: nop

    // 0x80017DB8: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
L_80017DBC:
    // 0x80017DBC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80017DC0: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80017DC4: bne         $at, $zero, L_80017B50
    if (ctx->r1 != 0) {
        // 0x80017DC8: nop
    
            goto L_80017B50;
    }
    // 0x80017DC8: nop

    // 0x80017DCC: lwc1        $f22, 0x9C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80017DD0: lwc1        $f20, 0xA0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80017DD4: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80017DD8: nop

L_80017DDC:
    // 0x80017DDC: bne         $t5, $zero, L_80017B3C
    if (ctx->r13 != 0) {
        // 0x80017DE0: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_80017B3C;
    }
    // 0x80017DE0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80017DE4: blez        $t4, L_80017E14
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80017DE8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80017E14;
    }
    // 0x80017DE8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80017DEC: lw          $t7, 0x128($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X128);
    // 0x80017DF0: nop

    // 0x80017DF4: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80017DF8: nop

    // 0x80017DFC: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80017E00: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80017E04: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x80017E08: nop

    // 0x80017E0C: or          $t6, $t9, $s6
    ctx->r14 = ctx->r25 | ctx->r22;
    // 0x80017E10: sw          $t6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r14;
L_80017E14:
    // 0x80017E14: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80017E18: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80017E1C: sll         $t8, $s6, 1
    ctx->r24 = S32(ctx->r22 << 1);
    // 0x80017E20: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x80017E24: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x80017E28: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80017E2C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80017E30: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80017E34: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80017E38: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x80017E3C: bne         $s1, $t6, L_80017AF8
    if (ctx->r17 != ctx->r14) {
        // 0x80017E40: or          $s6, $t8, $zero
        ctx->r22 = ctx->r24 | 0;
            goto L_80017AF8;
    }
    // 0x80017E40: or          $s6, $t8, $zero
    ctx->r22 = ctx->r24 | 0;
L_80017E44:
    // 0x80017E44: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80017E48: lw          $v0, 0xF8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XF8);
    // 0x80017E4C: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x80017E50: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80017E54: lwc1        $f23, 0x10($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80017E58: lwc1        $f22, 0x14($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80017E5C: lwc1        $f25, 0x18($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80017E60: lwc1        $f24, 0x1C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80017E64: lwc1        $f27, 0x20($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80017E68: lwc1        $f26, 0x24($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80017E6C: lwc1        $f29, 0x28($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80017E70: lwc1        $f28, 0x2C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80017E74: lwc1        $f31, 0x30($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80017E78: lwc1        $f30, 0x34($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80017E7C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80017E80: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80017E84: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80017E88: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80017E8C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80017E90: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80017E94: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80017E98: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80017E9C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80017EA0: jr          $ra
    // 0x80017EA4: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x80017EA4: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void set_taj_challenge_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017EA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80017EAC: sh          $a0, -0x4BA8($at)
    MEM_H(-0X4BA8, ctx->r1) = ctx->r4;
    // 0x80017EB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80017EB4: jr          $ra
    // 0x80017EB8: sw          $zero, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = 0;
    return;
    // 0x80017EB8: sw          $zero, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = 0;
;}
RECOMP_FUNC void get_taj_challenge_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017EBC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80017EC0: lh          $v0, -0x4BA8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4BA8);
    // 0x80017EC4: jr          $ra
    // 0x80017EC8: nop

    return;
    // 0x80017EC8: nop

;}
RECOMP_FUNC void checkpoint_update_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017ECC: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x80017ED0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80017ED4: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x80017ED8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80017EDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80017EE0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80017EE4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80017EE8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80017EEC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80017EF0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80017EF4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80017EF8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80017EFC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80017F00: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80017F04: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80017F08: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80017F0C: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80017F10: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80017F14: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80017F18: sw          $zero, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = 0;
    // 0x80017F1C: blez        $v1, L_8001803C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80017F20: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001803C;
    }
    // 0x80017F20: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80017F24: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80017F28: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80017F2C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80017F30: addiu       $a2, $a2, -0x4C28
    ctx->r6 = ADD32(ctx->r6, -0X4C28);
    // 0x80017F34: addiu       $t1, $t1, -0x4BA8
    ctx->r9 = ADD32(ctx->r9, -0X4BA8);
    // 0x80017F38: addiu       $s4, $s4, -0x4BB4
    ctx->r20 = ADD32(ctx->r20, -0X4BB4);
    // 0x80017F3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017F40: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x80017F44: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
L_80017F48:
    // 0x80017F48: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80017F4C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80017F50: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80017F54: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    // 0x80017F58: nop

    // 0x80017F5C: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x80017F60: nop

    // 0x80017F64: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80017F68: bne         $t9, $zero, L_80018034
    if (ctx->r25 != 0) {
        // 0x80017F6C: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018034;
    }
    // 0x80017F6C: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017F70: lh          $t3, 0x48($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X48);
    // 0x80017F74: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80017F78: bne         $t0, $t3, L_80018034
    if (ctx->r8 != ctx->r11) {
        // 0x80017F7C: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018034;
    }
    // 0x80017F7C: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017F80: lw          $a3, -0x4BB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB0);
    // 0x80017F84: nop

    // 0x80017F88: slti        $at, $a3, 0x3C
    ctx->r1 = SIGNED(ctx->r7) < 0X3C ? 1 : 0;
    // 0x80017F8C: beq         $at, $zero, L_80018034
    if (ctx->r1 == 0) {
        // 0x80017F90: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018034;
    }
    // 0x80017F90: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017F94: lw          $s7, 0x3C($s0)
    ctx->r23 = MEM_W(ctx->r16, 0X3C);
    // 0x80017F98: lh          $t4, 0x0($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X0);
    // 0x80017F9C: lb          $t5, 0x1A($s7)
    ctx->r13 = MEM_B(ctx->r23, 0X1A);
    // 0x80017FA0: nop

    // 0x80017FA4: bne         $t4, $t5, L_80018034
    if (ctx->r12 != ctx->r13) {
        // 0x80017FA8: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018034;
    }
    // 0x80017FA8: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017FAC: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80017FB0: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80017FB4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80017FB8: addiu       $a3, $a3, -0x4BB0
    ctx->r7 = ADD32(ctx->r7, -0X4BB0);
    // 0x80017FBC: mflo        $t7
    ctx->r15 = lo;
    // 0x80017FC0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80017FC4: sw          $s0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r16;
    // 0x80017FC8: lbu         $t9, 0x17($s7)
    ctx->r25 = MEM_BU(ctx->r23, 0X17);
    // 0x80017FCC: lbu         $a0, 0x9($s7)
    ctx->r4 = MEM_BU(ctx->r23, 0X9);
    // 0x80017FD0: beq         $t9, $zero, L_80017FE0
    if (ctx->r25 == 0) {
        // 0x80017FD4: nop
    
            goto L_80017FE0;
    }
    // 0x80017FD4: nop

    // 0x80017FD8: addiu       $a0, $a0, 0xFF
    ctx->r4 = ADD32(ctx->r4, 0XFF);
    // 0x80017FDC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80017FE0:
    // 0x80017FE0: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80017FE4: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80017FE8: multu       $t4, $a1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80017FEC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80017FF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80017FF4: mflo        $t5
    ctx->r13 = lo;
    // 0x80017FF8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80017FFC: sh          $a0, 0x2C($t6)
    MEM_H(0X2C, ctx->r14) = ctx->r4;
    // 0x80018000: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80018004: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80018008: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001800C: mflo        $t4
    ctx->r12 = lo;
    // 0x80018010: addu        $t3, $t8, $t4
    ctx->r11 = ADD32(ctx->r24, ctx->r12);
    // 0x80018014: sb          $t7, 0x3A($t3)
    MEM_B(0X3A, ctx->r11) = ctx->r15;
    // 0x80018018: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8001801C: nop

    // 0x80018020: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80018024: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80018028: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x8001802C: nop

    // 0x80018030: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
L_80018034:
    // 0x80018034: bne         $at, $zero, L_80017F48
    if (ctx->r1 != 0) {
        // 0x80018038: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80017F48;
    }
    // 0x80018038: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8001803C:
    // 0x8001803C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80018040: lw          $a3, -0x4BB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB0);
    // 0x80018044: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80018048: lw          $s2, 0x104($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X104);
    // 0x8001804C: addiu       $s4, $s4, -0x4BB4
    ctx->r20 = ADD32(ctx->r20, -0X4BB4);
    // 0x80018050: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80018054: addiu       $a2, $a3, -0x1
    ctx->r6 = ADD32(ctx->r7, -0X1);
    // 0x80018058: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001805C:
    // 0x8001805C: blez        $a2, L_800180EC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80018060: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800180EC;
    }
    // 0x80018060: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80018064: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80018068:
    // 0x80018068: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8001806C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80018070: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x80018074: lh          $v1, 0x2C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2C);
    // 0x80018078: lh          $a0, 0x68($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X68);
    // 0x8001807C: nop

    // 0x80018080: bne         $v1, $a0, L_80018090
    if (ctx->r3 != ctx->r4) {
        // 0x80018084: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018090;
    }
    // 0x80018084: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80018088: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001808C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
L_80018090:
    // 0x80018090: beq         $at, $zero, L_800180E4
    if (ctx->r1 == 0) {
        // 0x80018094: slt         $at, $s3, $a2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800180E4;
    }
    // 0x80018094: slt         $at, $s3, $a2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80018098: sh          $a0, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r4;
    // 0x8001809C: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800180A0: lw          $s0, 0x28($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X28);
    // 0x800180A4: addu        $v0, $t8, $s1
    ctx->r2 = ADD32(ctx->r24, ctx->r17);
    // 0x800180A8: lw          $t4, 0x64($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X64);
    // 0x800180AC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800180B0: sw          $t4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r12;
    // 0x800180B4: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800180B8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800180BC: addu        $t3, $t7, $s1
    ctx->r11 = ADD32(ctx->r15, ctx->r17);
    // 0x800180C0: sh          $v1, 0x68($t3)
    MEM_H(0X68, ctx->r11) = ctx->r3;
    // 0x800180C4: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800180C8: nop

    // 0x800180CC: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800180D0: sw          $s0, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r16;
    // 0x800180D4: lw          $a3, -0x4BB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB0);
    // 0x800180D8: nop

    // 0x800180DC: addiu       $a2, $a3, -0x1
    ctx->r6 = ADD32(ctx->r7, -0X1);
    // 0x800180E0: slt         $at, $s3, $a2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r6) ? 1 : 0;
L_800180E4:
    // 0x800180E4: bne         $at, $zero, L_80018068
    if (ctx->r1 != 0) {
        // 0x800180E8: addiu       $s1, $s1, 0x3C
        ctx->r17 = ADD32(ctx->r17, 0X3C);
            goto L_80018068;
    }
    // 0x800180E8: addiu       $s1, $s1, 0x3C
    ctx->r17 = ADD32(ctx->r17, 0X3C);
L_800180EC:
    // 0x800180EC: beq         $t0, $zero, L_8001805C
    if (ctx->r8 == 0) {
        // 0x800180F0: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8001805C;
    }
    // 0x800180F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800180F4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800180F8: addiu       $t0, $t0, -0x4BAC
    ctx->r8 = ADD32(ctx->r8, -0X4BAC);
    // 0x800180FC: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x80018100: subu        $t9, $a3, $t2
    ctx->r25 = SUB32(ctx->r7, ctx->r10);
    // 0x80018104: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80018108: beq         $t1, $zero, L_80018134
    if (ctx->r9 == 0) {
        // 0x8001810C: sw          $t9, -0x4BB0($at)
        MEM_W(-0X4BB0, ctx->r1) = ctx->r25;
            goto L_80018134;
    }
    // 0x8001810C: sw          $t9, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = ctx->r25;
    // 0x80018110: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80018114: jal         0x800B68BC
    // 0x80018118: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    set_render_printf_position(rdram, ctx);
        goto after_0;
    // 0x80018118: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    after_0:
    // 0x8001811C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80018120: addiu       $a0, $a0, 0x5664
    ctx->r4 = ADD32(ctx->r4, 0X5664);
    // 0x80018124: jal         0x800B643C
    // 0x80018128: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    render_printf(rdram, ctx);
        goto after_1;
    // 0x80018128: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x8001812C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80018130: addiu       $t0, $t0, -0x4BAC
    ctx->r8 = ADD32(ctx->r8, -0X4BAC);
L_80018134:
    // 0x80018134: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80018138: lw          $a3, -0x4BB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB0);
    // 0x8001813C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80018140: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80018144: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80018148: beq         $at, $zero, L_800181E4
    if (ctx->r1 == 0) {
        // 0x8001814C: sll         $s1, $a3, 4
        ctx->r17 = S32(ctx->r7 << 4);
            goto L_800181E4;
    }
    // 0x8001814C: sll         $s1, $a3, 4
    ctx->r17 = S32(ctx->r7 << 4);
    // 0x80018150: subu        $s1, $s1, $a3
    ctx->r17 = SUB32(ctx->r17, ctx->r7);
    // 0x80018154: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
L_80018158:
    // 0x80018158: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8001815C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018160: addu        $t4, $t8, $s1
    ctx->r12 = ADD32(ctx->r24, ctx->r17);
    // 0x80018164: lh          $a1, 0x2C($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X2C);
    // 0x80018168: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001816C: blez        $a3, L_800181D0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80018170: addiu       $a1, $a1, -0xFF
        ctx->r5 = ADD32(ctx->r5, -0XFF);
            goto L_800181D0;
    }
    // 0x80018170: addiu       $a1, $a1, -0xFF
    ctx->r5 = ADD32(ctx->r5, -0XFF);
    // 0x80018174: sll         $v0, $zero, 4
    ctx->r2 = S32(0 << 4);
    // 0x80018178: subu        $v0, $v0, $zero
    ctx->r2 = SUB32(ctx->r2, 0);
    // 0x8001817C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_80018180:
    // 0x80018180: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80018184: nop

    // 0x80018188: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x8001818C: lh          $t3, 0x2C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2C);
    // 0x80018190: nop

    // 0x80018194: bne         $a1, $t3, L_800181B8
    if (ctx->r5 != ctx->r11) {
        // 0x80018198: nop
    
            goto L_800181B8;
    }
    // 0x80018198: nop

    // 0x8001819C: sb          $s3, 0x3A($v1)
    MEM_B(0X3A, ctx->r3) = ctx->r19;
    // 0x800181A0: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800181A4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800181A8: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800181AC: sb          $a0, 0x3A($t6)
    MEM_B(0X3A, ctx->r14) = ctx->r4;
    // 0x800181B0: lw          $a3, -0x4BB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB0);
    // 0x800181B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800181B8:
    // 0x800181B8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800181BC: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800181C0: beq         $at, $zero, L_800181D0
    if (ctx->r1 == 0) {
        // 0x800181C4: addiu       $v0, $v0, 0x3C
        ctx->r2 = ADD32(ctx->r2, 0X3C);
            goto L_800181D0;
    }
    // 0x800181C4: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x800181C8: beq         $a2, $zero, L_80018180
    if (ctx->r6 == 0) {
        // 0x800181CC: nop
    
            goto L_80018180;
    }
    // 0x800181CC: nop

L_800181D0:
    // 0x800181D0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800181D4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800181D8: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800181DC: bne         $at, $zero, L_80018158
    if (ctx->r1 != 0) {
        // 0x800181E0: addiu       $s1, $s1, 0x3C
        ctx->r17 = ADD32(ctx->r17, 0X3C);
            goto L_80018158;
    }
    // 0x800181E0: addiu       $s1, $s1, 0x3C
    ctx->r17 = ADD32(ctx->r17, 0X3C);
L_800181E4:
    // 0x800181E4: blez        $v0, L_800185D8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800181E8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800185D8;
    }
    // 0x800181E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800181EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800181F0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800181F4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800181F8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800181FC:
    // 0x800181FC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80018200: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80018204: addu        $s2, $s1, $t9
    ctx->r18 = ADD32(ctx->r17, ctx->r25);
    // 0x80018208: lw          $s0, 0x28($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X28);
    // 0x8001820C: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x80018210: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80018214: lw          $s7, 0x3C($s0)
    ctx->r23 = MEM_W(ctx->r16, 0X3C);
    // 0x80018218: sh          $t8, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r24;
    // 0x8001821C: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80018220: nop

    // 0x80018224: sh          $t4, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r12;
    // 0x80018228: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x8001822C: swc1        $f22, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f22.u32l;
    // 0x80018230: swc1        $f20, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f20.u32l;
    // 0x80018234: swc1        $f20, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f20.u32l;
    // 0x80018238: swc1        $f20, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f20.u32l;
    // 0x8001823C: jal         0x8006FE70
    // 0x80018240: sh          $t7, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r15;
    mtxf_from_transform(rdram, ctx);
        goto after_2;
    // 0x80018240: sh          $t7, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r15;
    after_2:
    // 0x80018244: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80018248: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001824C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80018250: addiu       $t3, $sp, 0xE8
    ctx->r11 = ADD32(ctx->r29, 0XE8);
    // 0x80018254: addiu       $t5, $sp, 0xE4
    ctx->r13 = ADD32(ctx->r29, 0XE4);
    // 0x80018258: addiu       $t6, $sp, 0xE0
    ctx->r14 = ADD32(ctx->r29, 0XE0);
    // 0x8001825C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80018260: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80018264: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80018268: jal         0x8006F88C
    // 0x8001826C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x8001826C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    after_3:
    // 0x80018270: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80018274: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80018278: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x8001827C: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80018280: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80018284: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80018288: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8001828C: addiu       $t4, $s3, 0x1
    ctx->r12 = ADD32(ctx->r19, 0X1);
    // 0x80018290: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x80018294: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018298: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8001829C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800182A0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800182A4: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800182A8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800182AC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800182B0: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800182B4: nop

    // 0x800182B8: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800182BC: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800182C0: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800182C4: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x800182C8: swc1        $f8, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f8.u32l;
    // 0x800182CC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800182D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800182D4: swc1        $f16, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f16.u32l;
    // 0x800182D8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800182DC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800182E0: swc1        $f4, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f4.u32l;
    // 0x800182E4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800182E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800182EC: swc1        $f10, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f10.u32l;
    // 0x800182F0: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800182F4: nop

    // 0x800182F8: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800182FC: swc1        $f8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f8.u32l;
    // 0x80018300: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80018304: swc1        $f20, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f20.u32l;
    // 0x80018308: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8001830C: swc1        $f20, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f20.u32l;
    // 0x80018310: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80018314: nop

    // 0x80018318: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001831C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80018320: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80018324: nop

    // 0x80018328: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001832C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80018330: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80018334: sh          $t8, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r24;
    // 0x80018338: lw          $a3, -0x4BB0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB0);
    // 0x8001833C: nop

    // 0x80018340: slt         $at, $s3, $a3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80018344: beq         $at, $zero, L_80018430
    if (ctx->r1 == 0) {
        // 0x80018348: nop
    
            goto L_80018430;
    }
    // 0x80018348: nop

    // 0x8001834C: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
    // 0x80018350: bne         $t4, $a3, L_8001835C
    if (ctx->r12 != ctx->r7) {
        // 0x80018354: or          $a1, $fp, $zero
        ctx->r5 = ctx->r30 | 0;
            goto L_8001835C;
    }
    // 0x80018354: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80018358: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001835C:
    // 0x8001835C: sll         $s6, $a1, 4
    ctx->r22 = S32(ctx->r5 << 4);
    // 0x80018360: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80018364: subu        $s6, $s6, $a1
    ctx->r22 = SUB32(ctx->r22, ctx->r5);
    // 0x80018368: sll         $s6, $s6, 2
    ctx->r22 = S32(ctx->r22 << 2);
    // 0x8001836C: addu        $t3, $t7, $s6
    ctx->r11 = ADD32(ctx->r15, ctx->r22);
    // 0x80018370: lw          $v0, 0x28($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X28);
    // 0x80018374: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018378: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001837C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80018380: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80018384: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80018388: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001838C: sub.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80018390: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018394: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80018398: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001839C: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800183A0: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800183A4: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800183A8: jal         0x800CA030
    // 0x800183AC: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x800183AC: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_4:
    // 0x800183B0: swc1        $f0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f0.u32l;
    // 0x800183B4: lw          $s5, 0x0($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X0);
    // 0x800183B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800183BC: addu        $t5, $s5, $s6
    ctx->r13 = ADD32(ctx->r21, ctx->r22);
    // 0x800183C0: lb          $v1, 0x3A($t5)
    ctx->r3 = MEM_B(ctx->r13, 0X3A);
    // 0x800183C4: nop

    // 0x800183C8: beq         $v1, $at, L_80018424
    if (ctx->r3 == ctx->r1) {
        // 0x800183CC: sll         $t6, $v1, 4
        ctx->r14 = S32(ctx->r3 << 4);
            goto L_80018424;
    }
    // 0x800183CC: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x800183D0: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x800183D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800183D8: addu        $t9, $s5, $t6
    ctx->r25 = ADD32(ctx->r21, ctx->r14);
    // 0x800183DC: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x800183E0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800183E4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800183E8: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800183EC: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800183F0: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800183F4: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800183F8: sub.s       $f2, $f18, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800183FC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018400: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80018404: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80018408: sub.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8001840C: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018410: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018414: jal         0x800CA030
    // 0x80018418: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80018418: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_5:
    // 0x8001841C: b           L_80018528
    // 0x80018420: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
        goto L_80018528;
    // 0x80018420: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
L_80018424:
    // 0x80018424: lwc1        $f16, 0x20($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80018428: b           L_80018528
    // 0x8001842C: swc1        $f16, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f16.u32l;
        goto L_80018528;
    // 0x8001842C: swc1        $f16, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f16.u32l;
L_80018430:
    // 0x80018430: lw          $s5, 0x0($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X0);
    // 0x80018434: nop

    // 0x80018438: addu        $t8, $s5, $s1
    ctx->r24 = ADD32(ctx->r21, ctx->r17);
    // 0x8001843C: lb          $a1, 0x3A($t8)
    ctx->r5 = MEM_B(ctx->r24, 0X3A);
    // 0x80018440: nop

    // 0x80018444: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80018448: bne         $a1, $a3, L_80018458
    if (ctx->r5 != ctx->r7) {
        // 0x8001844C: sll         $s6, $a1, 4
        ctx->r22 = S32(ctx->r5 << 4);
            goto L_80018458;
    }
    // 0x8001844C: sll         $s6, $a1, 4
    ctx->r22 = S32(ctx->r5 << 4);
    // 0x80018450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018454: sll         $s6, $a1, 4
    ctx->r22 = S32(ctx->r5 << 4);
L_80018458:
    // 0x80018458: subu        $s6, $s6, $a1
    ctx->r22 = SUB32(ctx->r22, ctx->r5);
    // 0x8001845C: sll         $s6, $s6, 2
    ctx->r22 = S32(ctx->r22 << 2);
    // 0x80018460: addu        $t4, $s5, $s6
    ctx->r12 = ADD32(ctx->r21, ctx->r22);
    // 0x80018464: lw          $v0, 0x28($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X28);
    // 0x80018468: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001846C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80018470: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80018474: sub.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80018478: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001847C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80018480: sub.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80018484: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018488: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001848C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80018490: sub.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80018494: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018498: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001849C: jal         0x800CA030
    // 0x800184A0: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x800184A0: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_6:
    // 0x800184A4: swc1        $f0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f0.u32l;
    // 0x800184A8: lw          $s5, 0x0($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X0);
    // 0x800184AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800184B0: addu        $t7, $s5, $s6
    ctx->r15 = ADD32(ctx->r21, ctx->r22);
    // 0x800184B4: lb          $v1, 0x3A($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X3A);
    // 0x800184B8: nop

    // 0x800184BC: beq         $v1, $at, L_8001851C
    if (ctx->r3 == ctx->r1) {
        // 0x800184C0: sll         $t3, $v1, 4
        ctx->r11 = S32(ctx->r3 << 4);
            goto L_8001851C;
    }
    // 0x800184C0: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x800184C4: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x800184C8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800184CC: addu        $t5, $s5, $t3
    ctx->r13 = ADD32(ctx->r21, ctx->r11);
    // 0x800184D0: lw          $v0, 0x28($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X28);
    // 0x800184D4: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800184D8: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800184DC: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800184E0: sub.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800184E4: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800184E8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800184EC: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800184F0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800184F4: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800184F8: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800184FC: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80018500: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018504: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80018508: jal         0x800CA030
    // 0x8001850C: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8001850C: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_7:
    // 0x80018510: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
    // 0x80018514: b           L_80018528
    // 0x80018518: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
        goto L_80018528;
    // 0x80018518: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
L_8001851C:
    // 0x8001851C: lwc1        $f6, 0x20($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80018520: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
    // 0x80018524: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
L_80018528:
    // 0x80018528: lb          $t6, 0xB($s7)
    ctx->r14 = MEM_B(ctx->r23, 0XB);
    // 0x8001852C: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x80018530: sb          $t6, 0x2E($s2)
    MEM_B(0X2E, ctx->r18) = ctx->r14;
    // 0x80018534: lb          $t9, 0xF($s7)
    ctx->r25 = MEM_B(ctx->r23, 0XF);
    // 0x80018538: addiu       $s1, $s1, 0x3C
    ctx->r17 = ADD32(ctx->r17, 0X3C);
    // 0x8001853C: sb          $t9, 0x32($s2)
    MEM_B(0X32, ctx->r18) = ctx->r25;
    // 0x80018540: lb          $t8, 0x13($s7)
    ctx->r24 = MEM_B(ctx->r23, 0X13);
    // 0x80018544: nop

    // 0x80018548: sb          $t8, 0x36($s2)
    MEM_B(0X36, ctx->r18) = ctx->r24;
    // 0x8001854C: lb          $t4, 0xC($s7)
    ctx->r12 = MEM_B(ctx->r23, 0XC);
    // 0x80018550: nop

    // 0x80018554: sb          $t4, 0x2F($s2)
    MEM_B(0X2F, ctx->r18) = ctx->r12;
    // 0x80018558: lb          $t7, 0x10($s7)
    ctx->r15 = MEM_B(ctx->r23, 0X10);
    // 0x8001855C: nop

    // 0x80018560: sb          $t7, 0x33($s2)
    MEM_B(0X33, ctx->r18) = ctx->r15;
    // 0x80018564: lb          $t3, 0x14($s7)
    ctx->r11 = MEM_B(ctx->r23, 0X14);
    // 0x80018568: nop

    // 0x8001856C: sb          $t3, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r11;
    // 0x80018570: lb          $t5, 0xD($s7)
    ctx->r13 = MEM_B(ctx->r23, 0XD);
    // 0x80018574: nop

    // 0x80018578: sb          $t5, 0x30($s2)
    MEM_B(0X30, ctx->r18) = ctx->r13;
    // 0x8001857C: lb          $t6, 0x11($s7)
    ctx->r14 = MEM_B(ctx->r23, 0X11);
    // 0x80018580: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80018584: sb          $t6, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r14;
    // 0x80018588: lb          $t9, 0x15($s7)
    ctx->r25 = MEM_B(ctx->r23, 0X15);
    // 0x8001858C: nop

    // 0x80018590: sb          $t9, 0x38($s2)
    MEM_B(0X38, ctx->r18) = ctx->r25;
    // 0x80018594: lb          $t8, 0xE($s7)
    ctx->r24 = MEM_B(ctx->r23, 0XE);
    // 0x80018598: nop

    // 0x8001859C: sb          $t8, 0x31($s2)
    MEM_B(0X31, ctx->r18) = ctx->r24;
    // 0x800185A0: lb          $t4, 0x12($s7)
    ctx->r12 = MEM_B(ctx->r23, 0X12);
    // 0x800185A4: nop

    // 0x800185A8: sb          $t4, 0x35($s2)
    MEM_B(0X35, ctx->r18) = ctx->r12;
    // 0x800185AC: lb          $t7, 0x16($s7)
    ctx->r15 = MEM_B(ctx->r23, 0X16);
    // 0x800185B0: nop

    // 0x800185B4: sb          $t7, 0x39($s2)
    MEM_B(0X39, ctx->r18) = ctx->r15;
    // 0x800185B8: lbu         $t3, 0x19($s7)
    ctx->r11 = MEM_BU(ctx->r23, 0X19);
    // 0x800185BC: nop

    // 0x800185C0: sb          $t3, 0x3B($s2)
    MEM_B(0X3B, ctx->r18) = ctx->r11;
    // 0x800185C4: lw          $t5, -0x4BAC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4BAC);
    // 0x800185C8: nop

    // 0x800185CC: slt         $at, $fp, $t5
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800185D0: bne         $at, $zero, L_800181FC
    if (ctx->r1 != 0) {
        // 0x800185D4: nop
    
            goto L_800181FC;
    }
    // 0x800185D4: nop

L_800185D8:
    // 0x800185D8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800185DC: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800185E0: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800185E4: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800185E8: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800185EC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800185F0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800185F4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800185F8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800185FC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80018600: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80018604: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80018608: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8001860C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80018610: jr          $ra
    // 0x80018614: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x80018614: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void checkpoint_is_passed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018618: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8001861C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80018620: lw          $v0, -0x4BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
    // 0x80018624: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x80018628: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8001862C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80018630: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80018634: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80018638: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8001863C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80018640: bne         $v0, $zero, L_80018650
    if (ctx->r2 != 0) {
        // 0x80018644: sw          $a2, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r6;
            goto L_80018650;
    }
    // 0x80018644: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80018648: b           L_80018C8C
    // 0x8001864C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80018C8C;
    // 0x8001864C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80018650:
    // 0x80018650: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80018654: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x80018658: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001865C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80018660: lw          $a2, -0x4BB4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4BB4);
    // 0x80018664: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x80018668: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001866C: mflo        $t1
    ctx->r9 = lo;
    // 0x80018670: addu        $v1, $t1, $a2
    ctx->r3 = ADD32(ctx->r9, ctx->r6);
    // 0x80018674: beq         $t7, $zero, L_80018684
    if (ctx->r15 == 0) {
        // 0x80018678: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80018684;
    }
    // 0x80018678: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8001867C: b           L_80018694
    // 0x80018680: addiu       $a0, $v1, -0x3C
    ctx->r4 = ADD32(ctx->r3, -0X3C);
        goto L_80018694;
    // 0x80018680: addiu       $a0, $v1, -0x3C
    ctx->r4 = ADD32(ctx->r3, -0X3C);
L_80018684:
    // 0x80018684: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018688: mflo        $t8
    ctx->r24 = lo;
    // 0x8001868C: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    // 0x80018690: addiu       $a0, $a0, -0x3C
    ctx->r4 = ADD32(ctx->r4, -0X3C);
L_80018694:
    // 0x80018694: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x80018698: nop

    // 0x8001869C: beq         $v1, $zero, L_800186E4
    if (ctx->r3 == 0) {
        // 0x800186A0: nop
    
            goto L_800186E4;
    }
    // 0x800186A0: nop

    // 0x800186A4: lb          $v0, 0x3A($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X3A);
    // 0x800186A8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800186AC: beq         $t2, $v0, L_800186C4
    if (ctx->r10 == ctx->r2) {
        // 0x800186B0: nop
    
            goto L_800186C4;
    }
    // 0x800186B0: nop

    // 0x800186B4: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800186B8: mflo        $t4
    ctx->r12 = lo;
    // 0x800186BC: addu        $a1, $t4, $a2
    ctx->r5 = ADD32(ctx->r12, ctx->r6);
    // 0x800186C0: nop

L_800186C4:
    // 0x800186C4: lb          $v0, 0x3A($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3A);
    // 0x800186C8: nop

    // 0x800186CC: beq         $t2, $v0, L_800186E4
    if (ctx->r10 == ctx->r2) {
        // 0x800186D0: nop
    
            goto L_800186E4;
    }
    // 0x800186D0: nop

    // 0x800186D4: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800186D8: mflo        $t5
    ctx->r13 = lo;
    // 0x800186DC: addu        $a0, $t5, $a2
    ctx->r4 = ADD32(ctx->r13, ctx->r6);
    // 0x800186E0: nop

L_800186E4:
    // 0x800186E4: bne         $v1, $zero, L_800187AC
    if (ctx->r3 != 0) {
        // 0x800186E8: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_800187AC;
    }
    // 0x800186E8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800186EC: lb          $t6, 0x3A($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3A);
    // 0x800186F0: nop

    // 0x800186F4: bne         $t2, $t6, L_800187AC
    if (ctx->r10 != ctx->r14) {
        // 0x800186F8: nop
    
            goto L_800187AC;
    }
    // 0x800186F8: nop

    // 0x800186FC: lb          $v0, 0x3A($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X3A);
    // 0x80018700: nop

    // 0x80018704: beq         $t2, $v0, L_800187AC
    if (ctx->r10 == ctx->r2) {
        // 0x80018708: nop
    
            goto L_800187AC;
    }
    // 0x80018708: nop

    // 0x8001870C: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018710: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80018714: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80018718: mflo        $t7
    ctx->r15 = lo;
    // 0x8001871C: addu        $v1, $t7, $a2
    ctx->r3 = ADD32(ctx->r15, ctx->r6);
    // 0x80018720: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80018724: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80018728: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8001872C: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80018730: sub.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80018734: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80018738: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001873C: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80018740: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80018744: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80018748: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8001874C: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x80018750: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80018754: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80018758: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001875C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018760: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80018764: jal         0x800CA030
    // 0x80018768: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80018768: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_0:
    // 0x8001876C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80018770: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80018774: lh          $t8, 0x2C($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2C);
    // 0x80018778: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8001877C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80018780: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x80018784: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80018788: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8001878C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80018790: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80018794: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80018798: bc1f        L_800187AC
    if (!c1cs) {
        // 0x8001879C: nop
    
            goto L_800187AC;
    }
    // 0x8001879C: nop

    // 0x800187A0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800187A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800187A8: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
L_800187AC:
    // 0x800187AC: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800187B0: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800187B4: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800187B8: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800187BC: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800187C0: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800187C4: sub.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800187C8: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800187CC: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800187D0: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800187D4: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x800187D8: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x800187DC: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800187E0: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x800187E4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x800187E8: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x800187EC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800187F0: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800187F4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800187F8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800187FC: jal         0x800CA030
    // 0x80018800: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80018800: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_1:
    // 0x80018804: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80018808: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001880C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80018810: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x80018814: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80018818: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8001881C: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x80018820: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80018824: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80018828: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8001882C: bc1f        L_80018860
    if (!c1cs) {
        // 0x80018830: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_80018860;
    }
    // 0x80018830: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80018834: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018838: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001883C: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80018840: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80018844: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80018848: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001884C: nop

    // 0x80018850: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80018854: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x80018858: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001885C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
L_80018860:
    // 0x80018860: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018864: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80018868: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001886C: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80018870: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80018874: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80018878: lwc1        $f12, 0x14($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8001887C: mul.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80018880: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x80018884: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80018888: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001888C: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80018890: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80018894: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80018898: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001889C: mul.s       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800188A0: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800188A4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800188A8: mul.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800188AC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800188B0: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800188B4: nop

    // 0x800188B8: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800188BC: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800188C0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800188C4: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x800188C8: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
    // 0x800188CC: nop

    // 0x800188D0: div.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800188D4: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800188D8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800188DC: nop

    // 0x800188E0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800188E4: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800188E8: nop

    // 0x800188EC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800188F0: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800188F4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800188F8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800188FC: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80018900: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80018904: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80018908: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001890C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80018910: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80018914: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80018918: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001891C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80018920: nop

    // 0x80018924: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80018928: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8001892C: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018930: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80018934: nop

    // 0x80018938: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001893C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80018940: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80018944: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80018948: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8001894C: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80018950: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80018954: nop

    // 0x80018958: mul.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8001895C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80018960: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80018964: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80018968: nop

    // 0x8001896C: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80018970: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80018974: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80018978: nop

    // 0x8001897C: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80018980: add.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80018984: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80018988: c.eq.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d == ctx->f8.d;
    // 0x8001898C: nop

    // 0x80018990: bc1t        L_800189A0
    if (c1cs) {
        // 0x80018994: nop
    
            goto L_800189A0;
    }
    // 0x80018994: nop

    // 0x80018998: b           L_800189A8
    // 0x8001899C: div.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
        goto L_800189A8;
    // 0x8001899C: div.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
L_800189A0:
    // 0x800189A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800189A4: nop

L_800189A8:
    // 0x800189A8: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x800189AC: lh          $t9, 0x48($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X48);
    // 0x800189B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800189B4: bne         $v1, $t9, L_80018A1C
    if (ctx->r3 != ctx->r25) {
        // 0x800189B8: nop
    
            goto L_80018A1C;
    }
    // 0x800189B8: nop

    // 0x800189BC: lw          $v0, 0x64($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X64);
    // 0x800189C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800189C4: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x800189C8: nop

    // 0x800189CC: bne         $t2, $t4, L_80018A1C
    if (ctx->r10 != ctx->r12) {
        // 0x800189D0: nop
    
            goto L_80018A1C;
    }
    // 0x800189D0: nop

    // 0x800189D4: lwc1        $f7, 0x5BB0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5BB0);
    // 0x800189D8: lwc1        $f6, 0x5BB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5BB4);
    // 0x800189DC: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800189E0: c.lt.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d < ctx->f6.d;
    // 0x800189E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800189E8: bc1f        L_800189F8
    if (!c1cs) {
        // 0x800189EC: nop
    
            goto L_800189F8;
    }
    // 0x800189EC: nop

    // 0x800189F0: b           L_80018C8C
    // 0x800189F4: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
        goto L_80018C8C;
    // 0x800189F4: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
L_800189F8:
    // 0x800189F8: lwc1        $f5, 0x5BB8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5BB8);
    // 0x800189FC: lwc1        $f4, 0x5BBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5BBC);
    // 0x80018A00: nop

    // 0x80018A04: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80018A08: nop

    // 0x80018A0C: bc1f        L_80018A1C
    if (!c1cs) {
        // 0x80018A10: nop
    
            goto L_80018A1C;
    }
    // 0x80018A10: nop

    // 0x80018A14: b           L_80018C8C
    // 0x80018A18: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
        goto L_80018C8C;
    // 0x80018A18: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
L_80018A1C:
    // 0x80018A1C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80018A20: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80018A24: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80018A28: nop

    // 0x80018A2C: bc1f        L_80018C4C
    if (!c1cs) {
        // 0x80018A30: nop
    
            goto L_80018C4C;
    }
    // 0x80018A30: nop

    // 0x80018A34: beq         $t3, $zero, L_80018A48
    if (ctx->r11 == 0) {
        // 0x80018A38: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80018A48;
    }
    // 0x80018A38: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80018A3C: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80018A40: b           L_80018A5C
    // 0x80018A44: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
        goto L_80018A5C;
    // 0x80018A44: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
L_80018A48:
    // 0x80018A48: lb          $t7, 0x3A($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X3A);
    // 0x80018A4C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80018A50: bne         $t2, $t7, L_80018A5C
    if (ctx->r10 != ctx->r15) {
        // 0x80018A54: nop
    
            goto L_80018A5C;
    }
    // 0x80018A54: nop

    // 0x80018A58: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
L_80018A5C:
    // 0x80018A5C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018A60: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80018A64: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80018A68: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80018A6C: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80018A70: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80018A74: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80018A78: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80018A7C: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80018A80: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80018A84: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80018A88: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80018A8C: nop

    // 0x80018A90: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80018A94: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80018A98: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018A9C: add.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018AA0: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x80018AA4: nop

    // 0x80018AA8: bc1f        L_80018C40
    if (!c1cs) {
        // 0x80018AAC: nop
    
            goto L_80018C40;
    }
    // 0x80018AAC: nop

    // 0x80018AB0: lh          $t9, 0x48($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X48);
    // 0x80018AB4: nop

    // 0x80018AB8: bne         $v1, $t9, L_80018AD8
    if (ctx->r3 != ctx->r25) {
        // 0x80018ABC: nop
    
            goto L_80018AD8;
    }
    // 0x80018ABC: nop

    // 0x80018AC0: lbu         $v1, 0x3B($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X3B);
    // 0x80018AC4: lw          $v0, 0x64($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X64);
    // 0x80018AC8: beq         $v1, $zero, L_80018AD8
    if (ctx->r3 == 0) {
        // 0x80018ACC: addiu       $t4, $zero, 0x78
        ctx->r12 = ADD32(0, 0X78);
            goto L_80018AD8;
    }
    // 0x80018ACC: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x80018AD0: sb          $v1, 0x1F8($v0)
    MEM_B(0X1F8, ctx->r2) = ctx->r3;
    // 0x80018AD4: sb          $t4, 0x1F9($v0)
    MEM_B(0X1F9, ctx->r2) = ctx->r12;
L_80018AD8:
    // 0x80018AD8: lw          $t5, -0x4BB0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4BB0);
    // 0x80018ADC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80018AE0: bne         $t0, $t5, L_80018AEC
    if (ctx->r8 != ctx->r13) {
        // 0x80018AE4: addiu       $t1, $t1, 0x3C
        ctx->r9 = ADD32(ctx->r9, 0X3C);
            goto L_80018AEC;
    }
    // 0x80018AE4: addiu       $t1, $t1, 0x3C
    ctx->r9 = ADD32(ctx->r9, 0X3C);
    // 0x80018AE8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80018AEC:
    // 0x80018AEC: lw          $t6, -0x4BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BB4);
    // 0x80018AF0: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80018AF4: addu        $a1, $t1, $t6
    ctx->r5 = ADD32(ctx->r9, ctx->r14);
    // 0x80018AF8: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018AFC: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80018B00: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80018B04: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80018B08: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80018B0C: lwc1        $f12, 0x14($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80018B10: mul.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80018B14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80018B18: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80018B1C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018B20: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80018B24: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018B28: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80018B2C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018B30: mul.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80018B34: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80018B38: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80018B3C: mul.s       $f8, $f16, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80018B40: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018B44: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80018B48: nop

    // 0x80018B4C: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80018B50: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80018B54: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80018B58: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x80018B5C: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x80018B60: nop

    // 0x80018B64: div.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80018B68: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80018B6C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80018B70: nop

    // 0x80018B74: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80018B78: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80018B7C: nop

    // 0x80018B80: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80018B84: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80018B88: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80018B8C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80018B90: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80018B94: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80018B98: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80018B9C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80018BA0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80018BA4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80018BA8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80018BAC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80018BB0: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80018BB4: nop

    // 0x80018BB8: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80018BBC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80018BC0: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80018BC4: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80018BC8: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80018BCC: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80018BD0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80018BD4: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80018BD8: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x80018BDC: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80018BE0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80018BE4: nop

    // 0x80018BE8: mul.s       $f8, $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80018BEC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80018BF0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018BF4: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80018BF8: nop

    // 0x80018BFC: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80018C00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80018C04: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80018C08: nop

    // 0x80018C0C: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80018C10: add.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80018C14: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80018C18: c.eq.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d == ctx->f4.d;
    // 0x80018C1C: nop

    // 0x80018C20: bc1t        L_80018C30
    if (c1cs) {
        // 0x80018C24: nop
    
            goto L_80018C30;
    }
    // 0x80018C24: nop

    // 0x80018C28: b           L_80018C38
    // 0x80018C2C: div.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
        goto L_80018C38;
    // 0x80018C2C: div.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
L_80018C30:
    // 0x80018C30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80018C34: nop

L_80018C38:
    // 0x80018C38: b           L_80018C8C
    // 0x80018C3C: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
        goto L_80018C8C;
    // 0x80018C3C: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
L_80018C40:
    // 0x80018C40: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x80018C44: b           L_80018C8C
    // 0x80018C48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80018C8C;
    // 0x80018C48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80018C4C:
    // 0x80018C4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018C50: nop

    // 0x80018C54: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80018C58: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80018C5C: nop

    // 0x80018C60: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80018C64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80018C68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80018C6C: nop

    // 0x80018C70: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80018C74: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80018C78: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80018C7C: bne         $v0, $zero, L_80018C88
    if (ctx->r2 != 0) {
        // 0x80018C80: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80018C88;
    }
    // 0x80018C80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80018C84: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
L_80018C88:
    // 0x80018C88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80018C8C:
    // 0x80018C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80018C90: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80018C94: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80018C98: jr          $ra
    // 0x80018C9C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80018C9C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void find_taj_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018CA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80018CA4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80018CA8: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x80018CAC: lw          $v0, -0x4C20($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C20);
    // 0x80018CB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80018CB4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80018CB8: beq         $at, $zero, L_80018D08
    if (ctx->r1 == 0) {
        // 0x80018CBC: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80018D08;
    }
    // 0x80018CBC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80018CC0: lw          $t6, -0x4C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C28);
    // 0x80018CC4: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    // 0x80018CC8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
L_80018CCC:
    // 0x80018CCC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80018CD0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80018CD4: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x80018CD8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80018CDC: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80018CE0: bne         $t9, $zero, L_80018D00
    if (ctx->r25 != 0) {
        // 0x80018CE4: nop
    
            goto L_80018D00;
    }
    // 0x80018CE4: nop

    // 0x80018CE8: lh          $t0, 0x48($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X48);
    // 0x80018CEC: nop

    // 0x80018CF0: bne         $a2, $t0, L_80018D00
    if (ctx->r6 != ctx->r8) {
        // 0x80018CF4: nop
    
            goto L_80018D00;
    }
    // 0x80018CF4: nop

    // 0x80018CF8: jr          $ra
    // 0x80018CFC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80018CFC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80018D00:
    // 0x80018D00: bne         $at, $zero, L_80018CCC
    if (ctx->r1 != 0) {
        // 0x80018D04: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80018CCC;
    }
    // 0x80018D04: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80018D08:
    // 0x80018D08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80018D0C: jr          $ra
    // 0x80018D10: nop

    return;
    // 0x80018D10: nop

;}
RECOMP_FUNC void func_80018CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018D14: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80018D18: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80018D1C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80018D20: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80018D24: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80018D28: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80018D2C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80018D30: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80018D34: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80018D38: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80018D3C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80018D40: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80018D44: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x80018D48: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80018D4C: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x80018D50: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80018D54: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80018D58: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80018D5C: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80018D60: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80018D64: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80018D68: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80018D6C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80018D70: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x80018D74: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    // 0x80018D78: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x80018D7C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80018D80: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80018D84: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80018D88: nop

    // 0x80018D8C: bne         $t3, $zero, L_80019534
    if (ctx->r11 != 0) {
        // 0x80018D90: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80019534;
    }
    // 0x80018D90: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80018D94: jal         0x80066450
    // 0x80018D98: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x80018D98: nop

    after_0:
    // 0x80018D9C: bne         $v0, $zero, L_80019530
    if (ctx->r2 != 0) {
        // 0x80018DA0: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80019530;
    }
    // 0x80018DA0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80018DA4: lw          $t4, -0x4C20($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4C20);
    // 0x80018DA8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80018DAC: lw          $t5, -0x4C24($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4C24);
    // 0x80018DB0: sw          $t4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r12;
    // 0x80018DB4: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80018DB8: beq         $at, $zero, L_80019290
    if (ctx->r1 == 0) {
        // 0x80018DBC: sll         $t8, $t4, 2
        ctx->r24 = S32(ctx->r12 << 2);
            goto L_80019290;
    }
    // 0x80018DBC: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80018DC0: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x80018DC4: addiu       $fp, $zero, 0x7F
    ctx->r30 = ADD32(0, 0X7F);
    // 0x80018DC8: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
    // 0x80018DCC: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80018DD0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80018DD4:
    // 0x80018DD4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80018DD8: lw          $t7, -0x4C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C28);
    // 0x80018DDC: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x80018DE0: nop

    // 0x80018DE4: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80018DE8: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x80018DEC: nop

    // 0x80018DF0: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x80018DF4: nop

    // 0x80018DF8: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80018DFC: bne         $t1, $zero, L_8001926C
    if (ctx->r9 != 0) {
        // 0x80018E00: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80018E00: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80018E04: lh          $v0, 0x48($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X48);
    // 0x80018E08: addiu       $at, $zero, 0x70
    ctx->r1 = ADD32(0, 0X70);
    // 0x80018E0C: bne         $v0, $at, L_80018FD0
    if (ctx->r2 != ctx->r1) {
        // 0x80018E10: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80018FD0;
    }
    // 0x80018E10: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80018E14: lwc1        $f6, 0xC($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0XC);
    // 0x80018E18: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018E1C: lwc1        $f10, 0x10($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X10);
    // 0x80018E20: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80018E24: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80018E28: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018E2C: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80018E30: lwc1        $f6, 0x14($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X14);
    // 0x80018E34: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80018E38: sub.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80018E3C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80018E40: nop

    // 0x80018E44: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018E48: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80018E4C: jal         0x800CA030
    // 0x80018E50: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80018E50: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_1:
    // 0x80018E54: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x80018E58: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80018E5C: lhu         $t2, 0x2($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X2);
    // 0x80018E60: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80018E64: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80018E68: bgez        $t2, L_80018E7C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80018E6C: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80018E7C;
    }
    // 0x80018E6C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80018E70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018E74: nop

    // 0x80018E78: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_80018E7C:
    // 0x80018E7C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80018E80: nop

    // 0x80018E84: bc1f        L_8001926C
    if (!c1cs) {
        // 0x80018E88: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80018E88: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80018E8C: sw          $v1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r3;
    // 0x80018E90: jal         0x80001918
    // 0x80018E94: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    music_current_sequence(rdram, ctx);
        goto after_2;
    // 0x80018E94: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80018E98: lw          $v1, 0xBC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XBC);
    // 0x80018E9C: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80018EA0: lbu         $t3, 0x1C($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1C);
    // 0x80018EA4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80018EA8: bne         $t3, $v0, L_80019268
    if (ctx->r11 != ctx->r2) {
        // 0x80018EAC: or          $s3, $v1, $zero
        ctx->r19 = ctx->r3 | 0;
            goto L_80019268;
    }
    // 0x80018EAC: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x80018EB0: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80018EB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80018EB8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80018EBC: bgez        $v0, L_80018ED0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80018EC0: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80018ED0;
    }
    // 0x80018EC0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80018EC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018EC8: nop

    // 0x80018ECC: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_80018ED0:
    // 0x80018ED0: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x80018ED4: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80018ED8: bc1f        L_80018EE8
    if (!c1cs) {
        // 0x80018EDC: nop
    
            goto L_80018EE8;
    }
    // 0x80018EDC: nop

    // 0x80018EE0: b           L_80018F34
    // 0x80018EE4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80018F34;
    // 0x80018EE4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80018EE8:
    // 0x80018EE8: lhu         $t5, 0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X2);
    // 0x80018EEC: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80018EF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018EF4: subu        $t4, $t5, $v0
    ctx->r12 = SUB32(ctx->r13, ctx->r2);
    // 0x80018EF8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80018EFC: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80018F00: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80018F04: nop

    // 0x80018F08: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80018F0C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80018F10: nop

    // 0x80018F14: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80018F18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80018F1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80018F20: nop

    // 0x80018F24: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80018F28: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80018F2C: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x80018F30: nop

L_80018F34:
    // 0x80018F34: lbu         $v0, 0xC($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0XC);
    // 0x80018F38: slti        $at, $s2, 0x7B
    ctx->r1 = SIGNED(ctx->r18) < 0X7B ? 1 : 0;
    // 0x80018F3C: beq         $v0, $s5, L_80018F54
    if (ctx->r2 == ctx->r21) {
        // 0x80018F40: nop
    
            goto L_80018F54;
    }
    // 0x80018F40: nop

    // 0x80018F44: beq         $v0, $s6, L_80018F90
    if (ctx->r2 == ctx->r22) {
        // 0x80018F48: andi        $s0, $s1, 0xFF
        ctx->r16 = ctx->r17 & 0XFF;
            goto L_80018F90;
    }
    // 0x80018F48: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x80018F4C: b           L_80018FBC
    // 0x80018F50: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80018FBC;
    // 0x80018F50: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018F54:
    // 0x80018F54: bne         $at, $zero, L_80018F6C
    if (ctx->r1 != 0) {
        // 0x80018F58: andi        $s0, $s1, 0xFF
        ctx->r16 = ctx->r17 & 0XFF;
            goto L_80018F6C;
    }
    // 0x80018F58: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x80018F5C: jal         0x80001114
    // 0x80018F60: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_3;
    // 0x80018F60: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_3:
    // 0x80018F64: b           L_80018FBC
    // 0x80018F68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80018FBC;
    // 0x80018F68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018F6C:
    // 0x80018F6C: subu        $a1, $fp, $s2
    ctx->r5 = SUB32(ctx->r30, ctx->r18);
    // 0x80018F70: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80018F74: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80018F78: jal         0x80001268
    // 0x80018F7C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_4;
    // 0x80018F7C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_4:
    // 0x80018F80: jal         0x80001170
    // 0x80018F84: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_5;
    // 0x80018F84: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_5:
    // 0x80018F88: b           L_80018FBC
    // 0x80018F8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80018FBC;
    // 0x80018F8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018F90:
    // 0x80018F90: jal         0x800012A8
    // 0x80018F94: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_fade(rdram, ctx);
        goto after_6;
    // 0x80018F94: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_6:
    // 0x80018F98: blez        $v0, L_80018FB8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80018F9C: nop
    
            goto L_80018FB8;
    }
    // 0x80018F9C: nop

    // 0x80018FA0: jal         0x8000114C
    // 0x80018FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    music_channel_active(rdram, ctx);
        goto after_7;
    // 0x80018FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80018FA8: bne         $v0, $zero, L_80018FB8
    if (ctx->r2 != 0) {
        // 0x80018FAC: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80018FB8;
    }
    // 0x80018FAC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80018FB0: jal         0x80001268
    // 0x80018FB4: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_8;
    // 0x80018FB4: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_8:
L_80018FB8:
    // 0x80018FB8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018FBC:
    // 0x80018FBC: bne         $s1, $s7, L_80018F34
    if (ctx->r17 != ctx->r23) {
        // 0x80018FC0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80018F34;
    }
    // 0x80018FC0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80018FC4: b           L_8001926C
    // 0x80018FC8: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
        goto L_8001926C;
    // 0x80018FC8: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80018FCC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
L_80018FD0:
    // 0x80018FD0: bne         $v0, $at, L_800191B8
    if (ctx->r2 != ctx->r1) {
        // 0x80018FD4: addiu       $at, $zero, 0x76
        ctx->r1 = ADD32(0, 0X76);
            goto L_800191B8;
    }
    // 0x80018FD4: addiu       $at, $zero, 0x76
    ctx->r1 = ADD32(0, 0X76);
    // 0x80018FD8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80018FDC: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80018FE0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80018FE4: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80018FE8: mul.s       $f30, $f16, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80018FEC: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80018FF0: lwc1        $f10, 0x104($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80018FF4: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80018FF8: mul.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80018FFC: lwc1        $f24, 0xC($s4)
    ctx->f24.u32l = MEM_W(ctx->r20, 0XC);
    // 0x80019000: lwc1        $f26, 0x10($s4)
    ctx->f26.u32l = MEM_W(ctx->r20, 0X10);
    // 0x80019004: lwc1        $f20, 0x14($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80019008: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8001900C: lwc1        $f28, 0x14($s4)
    ctx->f28.u32l = MEM_W(ctx->r20, 0X14);
    // 0x80019010: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    // 0x80019014: mul.s       $f10, $f12, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x80019018: add.s       $f8, $f6, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f30.fl;
    // 0x8001901C: mul.s       $f6, $f16, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80019020: add.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x80019024: add.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80019028: mul.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8001902C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80019030: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80019034: nop

    // 0x80019038: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8001903C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80019040: bc1f        L_80019068
    if (!c1cs) {
        // 0x80019044: add.s       $f2, $f10, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f20.fl;
            goto L_80019068;
    }
    // 0x80019044: add.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x80019048: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001904C: sll         $v1, $s5, 24
    ctx->r3 = S32(ctx->r21 << 24);
    // 0x80019050: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80019054: sra         $t6, $v1, 24
    ctx->r14 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80019058: bc1f        L_80019068
    if (!c1cs) {
        // 0x8001905C: nop
    
            goto L_80019068;
    }
    // 0x8001905C: nop

    // 0x80019060: b           L_800190A0
    // 0x80019064: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
        goto L_800190A0;
    // 0x80019064: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80019068:
    // 0x80019068: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001906C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019070: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80019074: nop

    // 0x80019078: bc1f        L_800190A0
    if (!c1cs) {
        // 0x8001907C: nop
    
            goto L_800190A0;
    }
    // 0x8001907C: nop

    // 0x80019080: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80019084: nop

    // 0x80019088: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8001908C: nop

    // 0x80019090: bc1f        L_800190A0
    if (!c1cs) {
        // 0x80019094: nop
    
            goto L_800190A0;
    }
    // 0x80019094: nop

    // 0x80019098: b           L_800190A0
    // 0x8001909C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_800190A0;
    // 0x8001909C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800190A0:
    // 0x800190A0: beq         $v1, $zero, L_8001926C
    if (ctx->r3 == 0) {
        // 0x800190A4: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x800190A4: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x800190A8: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800190AC: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
    // 0x800190B0: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800190B4: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800190B8: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800190BC: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x800190C0: sub.s       $f2, $f26, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f26.fl - ctx->f8.fl;
    // 0x800190C4: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800190C8: sub.s       $f10, $f10, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f30.fl;
    // 0x800190CC: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x800190D0: sub.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800190D4: sub.s       $f0, $f24, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f6.fl;
    // 0x800190D8: sub.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800190DC: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800190E0: sub.s       $f14, $f28, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f28.fl - ctx->f4.fl;
    // 0x800190E4: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800190E8: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800190EC: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800190F0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800190F4: nop

    // 0x800190F8: div.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800190FC: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80019100: mul.s       $f4, $f22, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80019104: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80019108: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x8001910C: nop

    // 0x80019110: bc1f        L_8001926C
    if (!c1cs) {
        // 0x80019114: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80019114: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019118: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8001911C: nop

    // 0x80019120: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x80019124: nop

    // 0x80019128: bc1f        L_8001926C
    if (!c1cs) {
        // 0x8001912C: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x8001912C: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019130: mul.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80019134: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80019138: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8001913C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80019140: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80019144: nop

    // 0x80019148: bc1f        L_8001926C
    if (!c1cs) {
        // 0x8001914C: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x8001914C: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019150: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80019154: nop

    // 0x80019158: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8001915C: nop

    // 0x80019160: bc1f        L_8001926C
    if (!c1cs) {
        // 0x80019164: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80019164: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019168: mul.s       $f4, $f22, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8001916C: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80019170: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80019174: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80019178: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8001917C: nop

    // 0x80019180: bc1f        L_8001926C
    if (!c1cs) {
        // 0x80019184: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80019184: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019188: lwc1        $f10, 0x2C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8001918C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80019190: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80019194: nop

    // 0x80019198: bc1f        L_8001926C
    if (!c1cs) {
        // 0x8001919C: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x8001919C: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x800191A0: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x800191A4: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800191A8: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800191AC: b           L_80019268
    // 0x800191B0: sw          $v0, -0x4B20($at)
    MEM_W(-0X4B20, ctx->r1) = ctx->r2;
        goto L_80019268;
    // 0x800191B0: sw          $v0, -0x4B20($at)
    MEM_W(-0X4B20, ctx->r1) = ctx->r2;
    // 0x800191B4: addiu       $at, $zero, 0x76
    ctx->r1 = ADD32(0, 0X76);
L_800191B8:
    // 0x800191B8: bne         $v0, $at, L_8001926C
    if (ctx->r2 != ctx->r1) {
        // 0x800191BC: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x800191BC: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x800191C0: lwc1        $f4, 0xC($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800191C4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800191C8: lwc1        $f8, 0x10($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X10);
    // 0x800191CC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800191D0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800191D4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800191D8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800191DC: lwc1        $f4, 0x14($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800191E0: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800191E4: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800191E8: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x800191EC: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800191F0: nop

    // 0x800191F4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800191F8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800191FC: jal         0x800CA030
    // 0x80019200: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x80019200: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_9:
    // 0x80019204: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x80019208: nop

    // 0x8001920C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80019210: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80019214: nop

    // 0x80019218: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001921C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80019220: nop

    // 0x80019224: bc1f        L_8001926C
    if (!c1cs) {
        // 0x80019228: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80019228: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x8001922C: jal         0x8000105C
    // 0x80019230: nop

    music_channel_get_mask(rdram, ctx);
        goto after_10;
    // 0x80019230: nop

    after_10:
    // 0x80019234: lhu         $t0, 0x0($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X0);
    // 0x80019238: nop

    // 0x8001923C: beq         $t0, $v0, L_8001926C
    if (ctx->r8 == ctx->r2) {
        // 0x80019240: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80019240: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019244: jal         0x80001918
    // 0x80019248: nop

    music_current_sequence(rdram, ctx);
        goto after_11;
    // 0x80019248: nop

    after_11:
    // 0x8001924C: lbu         $t1, 0x3($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X3);
    // 0x80019250: nop

    // 0x80019254: bne         $t1, $v0, L_8001926C
    if (ctx->r9 != ctx->r2) {
        // 0x80019258: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80019258: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x8001925C: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80019260: jal         0x80001074
    // 0x80019264: nop

    music_dynamic_set(rdram, ctx);
        goto after_12;
    // 0x80019264: nop

    after_12:
L_80019268:
    // 0x80019268: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
L_8001926C:
    // 0x8001926C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80019270: lw          $t8, -0x4C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4C24);
    // 0x80019274: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x80019278: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8001927C: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80019280: addiu       $t4, $t5, 0x4
    ctx->r12 = ADD32(ctx->r13, 0X4);
    // 0x80019284: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x80019288: bne         $at, $zero, L_80018DD4
    if (ctx->r1 != 0) {
        // 0x8001928C: sw          $t3, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = ctx->r11;
            goto L_80018DD4;
    }
    // 0x8001928C: sw          $t3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r11;
L_80019290:
    // 0x80019290: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80019294: lw          $t7, -0x4B20($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4B20);
    // 0x80019298: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8001929C: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800192A0: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
    // 0x800192A4: beq         $t7, $zero, L_80019530
    if (ctx->r15 == 0) {
        // 0x800192A8: addiu       $fp, $zero, 0x7F
        ctx->r30 = ADD32(0, 0X7F);
            goto L_80019530;
    }
    // 0x800192A8: addiu       $fp, $zero, 0x7F
    ctx->r30 = ADD32(0, 0X7F);
    // 0x800192AC: jal         0x80001918
    // 0x800192B0: nop

    music_current_sequence(rdram, ctx);
        goto after_13;
    // 0x800192B0: nop

    after_13:
    // 0x800192B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800192B8: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x800192BC: lw          $t0, 0x110($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X110);
    // 0x800192C0: lbu         $t6, 0x40($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X40);
    // 0x800192C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800192C8: bne         $t6, $v0, L_800194F8
    if (ctx->r14 != ctx->r2) {
        // 0x800192CC: addiu       $s4, $zero, 0x3
        ctx->r20 = ADD32(0, 0X3);
            goto L_800194F8;
    }
    // 0x800192CC: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800192D0: lhu         $t9, 0x4($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4);
    // 0x800192D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800192D8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800192DC: sh          $t1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r9;
    // 0x800192E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800192E4: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x800192E8: lw          $t5, 0x6710($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6710);
    // 0x800192EC: lbu         $t2, 0x2($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2);
    // 0x800192F0: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x800192F4: multu       $t2, $t5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800192F8: addiu       $t8, $zero, 0xFE
    ctx->r24 = ADD32(0, 0XFE);
    // 0x800192FC: mflo        $a0
    ctx->r4 = lo;
    // 0x80019300: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x80019304: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80019308: beq         $at, $zero, L_80019328
    if (ctx->r1 == 0) {
        // 0x8001930C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_80019328;
    }
    // 0x8001930C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80019310: sh          $t4, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r12;
    // 0x80019314: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80019318: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x8001931C: nop

    // 0x80019320: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x80019324: nop

L_80019328:
    // 0x80019328: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8001932C: bgez        $v0, L_80019344
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80019330: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80019344;
    }
    // 0x80019330: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80019334: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80019338: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001933C: nop

    // 0x80019340: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80019344:
    // 0x80019344: lui         $at, 0x437E
    ctx->r1 = S32(0X437E << 16);
    // 0x80019348: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001934C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80019350: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80019354: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80019358: bgez        $a0, L_8001936C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8001935C: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8001936C;
    }
    // 0x8001935C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80019360: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019364: nop

    // 0x80019368: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8001936C:
    // 0x8001936C: nop

    // 0x80019370: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80019374: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80019378: nop

    // 0x8001937C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80019380: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80019384: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80019388: nop

    // 0x8001938C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80019390: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80019394: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80019398: slti        $at, $a1, 0xFE
    ctx->r1 = SIGNED(ctx->r5) < 0XFE ? 1 : 0;
    // 0x8001939C: beq         $at, $zero, L_800193AC
    if (ctx->r1 == 0) {
        // 0x800193A0: nop
    
            goto L_800193AC;
    }
    // 0x800193A0: nop

    // 0x800193A4: b           L_800193B0
    // 0x800193A8: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
        goto L_800193B0;
    // 0x800193A8: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
L_800193AC:
    // 0x800193AC: sb          $t8, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r24;
L_800193B0:
    // 0x800193B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800193B4: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x800193B8: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800193BC:
    // 0x800193BC: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x800193C0: addu        $t7, $v1, $s1
    ctx->r15 = ADD32(ctx->r3, ctx->r17);
    // 0x800193C4: lb          $v0, 0x30($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X30);
    // 0x800193C8: bne         $s3, $t6, L_800193D8
    if (ctx->r19 != ctx->r14) {
        // 0x800193CC: sra         $t9, $v0, 2
        ctx->r25 = S32(SIGNED(ctx->r2) >> 2);
            goto L_800193D8;
    }
    // 0x800193CC: sra         $t9, $v0, 2
    ctx->r25 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800193D0: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x800193D4: sra         $v0, $t0, 24
    ctx->r2 = S32(SIGNED(ctx->r8) >> 24);
L_800193D8:
    // 0x800193D8: andi        $t2, $v0, 0x3
    ctx->r10 = ctx->r2 & 0X3;
    // 0x800193DC: sll         $t5, $t2, 24
    ctx->r13 = S32(ctx->r10 << 24);
    // 0x800193E0: sra         $t4, $t5, 24
    ctx->r12 = S32(SIGNED(ctx->r13) >> 24);
    // 0x800193E4: beq         $t4, $zero, L_80019430
    if (ctx->r12 == 0) {
        // 0x800193E8: nop
    
            goto L_80019430;
    }
    // 0x800193E8: nop

    // 0x800193EC: beq         $t4, $s5, L_8001940C
    if (ctx->r12 == ctx->r21) {
        // 0x800193F0: andi        $s0, $s1, 0xFF
        ctx->r16 = ctx->r17 & 0XFF;
            goto L_8001940C;
    }
    // 0x800193F0: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x800193F4: beq         $t4, $s6, L_80019498
    if (ctx->r12 == ctx->r22) {
        // 0x800193F8: nop
    
            goto L_80019498;
    }
    // 0x800193F8: nop

    // 0x800193FC: beq         $t4, $s4, L_80019448
    if (ctx->r12 == ctx->r20) {
        // 0x80019400: nop
    
            goto L_80019448;
    }
    // 0x80019400: nop

    // 0x80019404: b           L_800194F0
    // 0x80019408: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800194F0;
    // 0x80019408: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001940C:
    // 0x8001940C: jal         0x80001170
    // 0x80019410: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_14;
    // 0x80019410: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_14:
    // 0x80019414: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80019418: jal         0x80001268
    // 0x8001941C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    music_channel_fade_set(rdram, ctx);
        goto after_15;
    // 0x8001941C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_15:
    // 0x80019420: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80019424: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x80019428: b           L_800194F0
    // 0x8001942C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800194F0;
    // 0x8001942C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80019430:
    // 0x80019430: jal         0x80001114
    // 0x80019434: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_16;
    // 0x80019434: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_16:
    // 0x80019438: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001943C: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x80019440: b           L_800194F0
    // 0x80019444: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800194F0;
    // 0x80019444: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80019448:
    // 0x80019448: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8001944C: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x80019450: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80019454: bne         $at, $zero, L_80019488
    if (ctx->r1 != 0) {
        // 0x80019458: addiu       $s2, $v0, -0x7F
        ctx->r18 = ADD32(ctx->r2, -0X7F);
            goto L_80019488;
    }
    // 0x80019458: addiu       $s2, $v0, -0x7F
    ctx->r18 = ADD32(ctx->r2, -0X7F);
    // 0x8001945C: andi        $t3, $s2, 0xFF
    ctx->r11 = ctx->r18 & 0XFF;
    // 0x80019460: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x80019464: jal         0x80001170
    // 0x80019468: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_17;
    // 0x80019468: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_17:
    // 0x8001946C: jal         0x800012A8
    // 0x80019470: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_fade(rdram, ctx);
        goto after_18;
    // 0x80019470: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_18:
    // 0x80019474: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80019478: beq         $at, $zero, L_80019488
    if (ctx->r1 == 0) {
        // 0x8001947C: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80019488;
    }
    // 0x8001947C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80019480: jal         0x80001268
    // 0x80019484: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_19;
    // 0x80019484: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_19:
L_80019488:
    // 0x80019488: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001948C: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x80019490: b           L_800194F0
    // 0x80019494: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800194F0;
    // 0x80019494: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80019498:
    // 0x80019498: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8001949C: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x800194A0: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800194A4: beq         $at, $zero, L_800194D8
    if (ctx->r1 == 0) {
        // 0x800194A8: subu        $s2, $fp, $v0
        ctx->r18 = SUB32(ctx->r30, ctx->r2);
            goto L_800194D8;
    }
    // 0x800194A8: subu        $s2, $fp, $v0
    ctx->r18 = SUB32(ctx->r30, ctx->r2);
    // 0x800194AC: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x800194B0: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800194B4: jal         0x800012A8
    // 0x800194B8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_fade(rdram, ctx);
        goto after_20;
    // 0x800194B8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_20:
    // 0x800194BC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800194C0: beq         $at, $zero, L_800194E0
    if (ctx->r1 == 0) {
        // 0x800194C4: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_800194E0;
    }
    // 0x800194C4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800194C8: jal         0x80001268
    // 0x800194CC: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_21;
    // 0x800194CC: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_21:
    // 0x800194D0: b           L_800194E0
    // 0x800194D4: nop

        goto L_800194E0;
    // 0x800194D4: nop

L_800194D8:
    // 0x800194D8: jal         0x80001114
    // 0x800194DC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_22;
    // 0x800194DC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_22:
L_800194E0:
    // 0x800194E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800194E4: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x800194E8: nop

    // 0x800194EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800194F0:
    // 0x800194F0: bne         $s1, $s7, L_800193BC
    if (ctx->r17 != ctx->r23) {
        // 0x800194F4: nop
    
            goto L_800193BC;
    }
    // 0x800194F4: nop

L_800194F8:
    // 0x800194F8: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x800194FC: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x80019500: bne         $t7, $at, L_80019534
    if (ctx->r15 != ctx->r1) {
        // 0x80019504: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80019534;
    }
    // 0x80019504: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80019508: jal         0x80001918
    // 0x8001950C: nop

    music_current_sequence(rdram, ctx);
        goto after_23;
    // 0x8001950C: nop

    after_23:
    // 0x80019510: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80019514: lw          $t6, -0x4B20($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B20);
    // 0x80019518: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001951C: lbu         $t9, 0x40($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X40);
    // 0x80019520: nop

    // 0x80019524: bne         $t9, $v0, L_80019534
    if (ctx->r25 != ctx->r2) {
        // 0x80019528: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80019534;
    }
    // 0x80019528: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8001952C: sw          $zero, -0x4B20($at)
    MEM_W(-0X4B20, ctx->r1) = 0;
L_80019530:
    // 0x80019530: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80019534:
    // 0x80019534: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80019538: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001953C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80019540: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80019544: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80019548: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001954C: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80019550: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80019554: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80019558: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001955C: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80019560: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80019564: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80019568: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8001956C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80019570: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80019574: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80019578: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8001957C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80019580: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80019584: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80019588: jr          $ra
    // 0x8001958C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8001958C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void homing_rocket_get_next_direction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019590: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80019594: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80019598: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8001959C: lw          $s6, -0x4BB0($s6)
    ctx->r22 = MEM_W(ctx->r22, -0X4BB0);
    // 0x800195A0: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x800195A4: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x800195A8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800195AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800195B0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800195B4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800195B8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800195BC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800195C0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800195C4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800195C8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800195CC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800195D0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800195D4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800195D8: bne         $s6, $zero, L_800195E8
    if (ctx->r22 != 0) {
        // 0x800195DC: sw          $a0, 0xC0($sp)
        MEM_W(0XC0, ctx->r29) = ctx->r4;
            goto L_800195E8;
    }
    // 0x800195DC: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x800195E0: b           L_80019804
    // 0x800195E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80019804;
    // 0x800195E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800195E8:
    // 0x800195E8: addiu       $v0, $a1, -0x2
    ctx->r2 = ADD32(ctx->r5, -0X2);
    // 0x800195EC: bgez        $v0, L_800195F8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800195F0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800195F8;
    }
    // 0x800195F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800195F4: addu        $s1, $v0, $s6
    ctx->r17 = ADD32(ctx->r2, ctx->r22);
L_800195F8:
    // 0x800195F8: mtc1        $a3, $f18
    ctx->f18.u32l = ctx->r7;
    // 0x800195FC: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x80019600: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80019604: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80019608: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8001960C: cvt.s.w     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    ctx->f22.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80019610: addiu       $s2, $sp, 0xA4
    ctx->r18 = ADD32(ctx->r29, 0XA4);
    // 0x80019614: addiu       $s3, $sp, 0x94
    ctx->r19 = ADD32(ctx->r29, 0X94);
    // 0x80019618: addiu       $s0, $sp, 0x84
    ctx->r16 = ADD32(ctx->r29, 0X84);
    // 0x8001961C: addiu       $s5, $sp, 0x94
    ctx->r21 = ADD32(ctx->r29, 0X94);
L_80019620:
    // 0x80019620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80019624: jal         0x8001BA50
    // 0x80019628: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_0;
    // 0x80019628: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8001962C: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80019630: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80019634: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80019638: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001963C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80019640: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80019644: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80019648: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8001964C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80019650: swc1        $f8, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->f8.u32l;
    // 0x80019654: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80019658: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001965C: mul.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80019660: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80019664: swc1        $f4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f4.u32l;
    // 0x80019668: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001966C: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80019670: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x80019674: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80019678: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8001967C: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80019680: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80019684: bne         $s1, $s6, L_80019690
    if (ctx->r17 != ctx->r22) {
        // 0x80019688: swc1        $f8, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f8.u32l;
            goto L_80019690;
    }
    // 0x80019688: swc1        $f8, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8001968C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80019690:
    // 0x80019690: bne         $s0, $s5, L_80019620
    if (ctx->r16 != ctx->r21) {
        // 0x80019694: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80019620;
    }
    // 0x80019694: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80019698: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8001969C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800196A0: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x800196A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800196A8: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x800196AC: sub.d       $f18, $f2, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f2.d - ctx->f6.d;
    // 0x800196B0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800196B4: cvt.s.d     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f20.fl = CVT_S_D(ctx->f18.d);
    // 0x800196B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800196BC: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    // 0x800196C0: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x800196C4: bc1f        L_800196D0
    if (!c1cs) {
        // 0x800196C8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800196D0;
    }
    // 0x800196C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800196CC: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_800196D0:
    // 0x800196D0: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x800196D4: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x800196D8: nop

    // 0x800196DC: bc1f        L_800196EC
    if (!c1cs) {
        // 0x800196E0: nop
    
            goto L_800196EC;
    }
    // 0x800196E0: nop

    // 0x800196E4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800196E8: nop

L_800196EC:
    // 0x800196EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800196F0: jal         0x80022670
    // 0x800196F4: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    cubic_spline_interpolation(rdram, ctx);
        goto after_1;
    // 0x800196F4: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    after_1:
    // 0x800196F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800196FC: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x80019700: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80019704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019708: jal         0x80022670
    // 0x8001970C: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_2;
    // 0x8001970C: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_2:
    // 0x80019710: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80019714: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80019718: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8001971C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019720: jal         0x80022670
    // 0x80019724: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    cubic_spline_interpolation(rdram, ctx);
        goto after_3;
    // 0x80019724: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x80019728: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001972C: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80019730: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80019734: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80019738: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8001973C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80019740: nop

    // 0x80019744: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80019748: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001974C: jal         0x800CA030
    // 0x80019750: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80019750: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_4:
    // 0x80019754: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80019758: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001975C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80019760: nop

    // 0x80019764: bc1t        L_800197AC
    if (c1cs) {
        // 0x80019768: nop
    
            goto L_800197AC;
    }
    // 0x80019768: nop

    // 0x8001976C: lwc1        $f9, 0x5BC0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5BC0);
    // 0x80019770: lwc1        $f8, 0x5BC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5BC4);
    // 0x80019774: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80019778: nop

    // 0x8001977C: div.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80019780: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80019784: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80019788: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001978C: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x80019790: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80019794: nop

    // 0x80019798: mul.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8001979C: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    // 0x800197A0: mul.s       $f16, $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800197A4: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x800197A8: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
L_800197AC:
    // 0x800197AC: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800197B0: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800197B4: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x800197B8: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800197BC: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800197C0: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x800197C4: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800197C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800197CC: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x800197D0: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800197D4: lwc1        $f8, 0x10($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X10);
    // 0x800197D8: add.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f18.fl;
    // 0x800197DC: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x800197E0: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800197E4: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x800197E8: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800197EC: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800197F0: lwc1        $f8, 0x14($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X14);
    // 0x800197F4: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800197F8: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x800197FC: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80019800: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
L_80019804:
    // 0x80019804: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80019808: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8001980C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80019810: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80019814: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80019818: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001981C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80019820: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80019824: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80019828: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8001982C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80019830: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80019834: jr          $ra
    // 0x80019838: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80019838: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void race_check_finish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001983C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80019840: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80019844: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80019848: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001984C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80019850: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80019854: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80019858: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001985C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80019860: jal         0x8006BFF0
    // 0x80019864: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80019864: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    after_0:
    // 0x80019868: jal         0x8006ECD0
    // 0x8001986C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_1;
    // 0x8001986C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_1:
    // 0x80019870: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80019874: sh          $zero, 0x88($sp)
    MEM_H(0X88, ctx->r29) = 0;
    // 0x80019878: sh          $zero, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = 0;
    // 0x8001987C: lb          $v1, 0x4C($ra)
    ctx->r3 = MEM_B(ctx->r31, 0X4C);
    // 0x80019880: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80019884: beq         $v1, $zero, L_80019F10
    if (ctx->r3 == 0) {
        // 0x80019888: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80019F10;
    }
    // 0x80019888: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001988C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80019890: beq         $v1, $at, L_80019F10
    if (ctx->r3 == ctx->r1) {
        // 0x80019894: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80019F10;
    }
    // 0x80019894: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80019898: beq         $v1, $at, L_80019F10
    if (ctx->r3 == ctx->r1) {
        // 0x8001989C: andi        $t6, $v1, 0x40
        ctx->r14 = ctx->r3 & 0X40;
            goto L_80019F10;
    }
    // 0x8001989C: andi        $t6, $v1, 0x40
    ctx->r14 = ctx->r3 & 0X40;
    // 0x800198A0: beq         $t6, $zero, L_8001A7E4
    if (ctx->r14 == 0) {
        // 0x800198A4: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_8001A7E4;
    }
    // 0x800198A4: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800198A8: bne         $v1, $at, L_800198CC
    if (ctx->r3 != ctx->r1) {
        // 0x800198AC: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800198CC;
    }
    // 0x800198AC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800198B0: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
    // 0x800198B4: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800198B8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800198BC: jal         0x80045168
    // 0x800198C0: nop

    racer_update_eggs(rdram, ctx);
        goto after_2;
    // 0x800198C0: nop

    after_2:
    // 0x800198C4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800198C8: nop

L_800198CC:
    // 0x800198CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800198D0: lw          $t7, -0x4CCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CCC);
    // 0x800198D4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800198D8: bne         $t7, $zero, L_8001A7E4
    if (ctx->r15 != 0) {
        // 0x800198DC: addiu       $t3, $t3, -0x4B9C
        ctx->r11 = ADD32(ctx->r11, -0X4B9C);
            goto L_8001A7E4;
    }
    // 0x800198DC: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
    // 0x800198E0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800198E4: addiu       $s2, $s2, -0x4B90
    ctx->r18 = ADD32(ctx->r18, -0X4B90);
    // 0x800198E8: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800198EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800198F0: blez        $a3, L_80019A8C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800198F4: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80019A8C;
    }
    // 0x800198F4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800198F8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800198FC: addiu       $s1, $s1, -0x4CC0
    ctx->r17 = ADD32(ctx->r17, -0X4CC0);
    // 0x80019900: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80019904: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80019908: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8001990C: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
L_80019910:
    // 0x80019910: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80019914: nop

    // 0x80019918: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001991C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80019920: nop

    // 0x80019924: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80019928: nop

    // 0x8001992C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80019930: lb          $t8, 0x4C($ra)
    ctx->r24 = MEM_B(ctx->r31, 0X4C);
    // 0x80019934: nop

    // 0x80019938: bne         $t1, $t8, L_80019A00
    if (ctx->r9 != ctx->r24) {
        // 0x8001993C: nop
    
            goto L_80019A00;
    }
    // 0x8001993C: nop

    // 0x80019940: lb          $t9, 0x185($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X185);
    // 0x80019944: nop

    // 0x80019948: bgtz        $t9, L_80019A00
    if (SIGNED(ctx->r25) > 0) {
        // 0x8001994C: nop
    
            goto L_80019A00;
    }
    // 0x8001994C: nop

    // 0x80019950: lb          $t6, 0x1D8($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X1D8);
    // 0x80019954: nop

    // 0x80019958: bne         $t6, $zero, L_80019A00
    if (ctx->r14 != 0) {
        // 0x8001995C: nop
    
            goto L_80019A00;
    }
    // 0x8001995C: nop

    // 0x80019960: sb          $s4, 0x1D8($t7)
    MEM_B(0X1D8, ctx->r15) = ctx->r20;
    // 0x80019964: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80019968: nop

    // 0x8001996C: sb          $zero, 0x173($t7)
    MEM_B(0X173, ctx->r15) = 0;
    // 0x80019970: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80019974: nop

    // 0x80019978: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001997C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80019980: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80019984: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80019988: jal         0x80006AC8
    // 0x8001998C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    racer_sound_free(rdram, ctx);
        goto after_3;
    // 0x8001998C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_3:
    // 0x80019990: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80019994: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
    // 0x80019998: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001999C: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800199A0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800199A4: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x800199A8: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800199AC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800199B0: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x800199B4: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x800199B8: ori         $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 | 0X4000;
    // 0x800199BC: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x800199C0: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800199C4: nop

    // 0x800199C8: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x800199CC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800199D0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800199D4: lw          $t9, 0x4C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4C);
    // 0x800199D8: nop

    // 0x800199DC: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x800199E0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800199E4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800199E8: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800199EC: sh          $t8, 0x1AC($t9)
    MEM_H(0X1AC, ctx->r25) = ctx->r24;
    // 0x800199F0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800199F4: nop

    // 0x800199F8: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800199FC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_80019A00:
    // 0x80019A00: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80019A04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80019A08: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80019A0C: lb          $v1, 0x1D8($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1D8);
    // 0x80019A10: beq         $s5, $t8, L_80019A40
    if (ctx->r21 == ctx->r24) {
        // 0x80019A14: nop
    
            goto L_80019A40;
    }
    // 0x80019A14: nop

    // 0x80019A18: beq         $v1, $zero, L_80019A34
    if (ctx->r3 == 0) {
        // 0x80019A1C: lh          $t6, 0x8A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X8A);
            goto L_80019A34;
    }
    // 0x80019A1C: lh          $t6, 0x8A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8A);
    // 0x80019A20: lh          $t9, 0x88($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X88);
    // 0x80019A24: nop

    // 0x80019A28: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80019A2C: sh          $t7, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r15;
    // 0x80019A30: lh          $t6, 0x8A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8A);
L_80019A34:
    // 0x80019A34: nop

    // 0x80019A38: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80019A3C: sh          $t8, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r24;
L_80019A40:
    // 0x80019A40: beq         $v1, $zero, L_80019A78
    if (ctx->r3 == 0) {
        // 0x80019A44: nop
    
            goto L_80019A78;
    }
    // 0x80019A44: nop

    // 0x80019A48: lh          $t6, 0x1AC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1AC);
    // 0x80019A4C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80019A50: sll         $t9, $s3, 16
    ctx->r25 = S32(ctx->r19 << 16);
    // 0x80019A54: bne         $t6, $zero, L_80019A78
    if (ctx->r14 != 0) {
        // 0x80019A58: sra         $s3, $t9, 16
        ctx->r19 = S32(SIGNED(ctx->r25) >> 16);
            goto L_80019A78;
    }
    // 0x80019A58: sra         $s3, $t9, 16
    ctx->r19 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80019A5C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80019A60: nop

    // 0x80019A64: sh          $t8, 0x1AC($v0)
    MEM_H(0X1AC, ctx->r2) = ctx->r24;
    // 0x80019A68: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80019A6C: nop

    // 0x80019A70: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80019A74: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_80019A78:
    // 0x80019A78: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80019A7C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80019A80: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80019A84: bne         $at, $zero, L_80019910
    if (ctx->r1 != 0) {
        // 0x80019A88: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80019910;
    }
    // 0x80019A88: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80019A8C:
    // 0x80019A8C: lb          $t6, 0x4C($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4C);
    // 0x80019A90: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80019A94: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80019A98: addiu       $s1, $s1, -0x4CC0
    ctx->r17 = ADD32(ctx->r17, -0X4CC0);
    // 0x80019A9C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80019AA0: beq         $t1, $t6, L_80019AB0
    if (ctx->r9 == ctx->r14) {
        // 0x80019AA4: addiu       $s5, $zero, -0x1
        ctx->r21 = ADD32(0, -0X1);
            goto L_80019AB0;
    }
    // 0x80019AA4: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80019AA8: bgtz        $s3, L_80019AEC
    if (SIGNED(ctx->r19) > 0) {
        // 0x80019AAC: nop
    
            goto L_80019AEC;
    }
    // 0x80019AAC: nop

L_80019AB0:
    // 0x80019AB0: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
    // 0x80019AB4: lh          $t9, 0x88($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X88);
    // 0x80019AB8: bne         $t8, $s4, L_80019ACC
    if (ctx->r24 != ctx->r20) {
        // 0x80019ABC: lh          $t7, 0x8A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X8A);
            goto L_80019ACC;
    }
    // 0x80019ABC: lh          $t7, 0x8A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8A);
    // 0x80019AC0: beq         $t9, $s4, L_80019AEC
    if (ctx->r25 == ctx->r20) {
        // 0x80019AC4: nop
    
            goto L_80019AEC;
    }
    // 0x80019AC4: nop

    // 0x80019AC8: lh          $t7, 0x8A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8A);
L_80019ACC:
    // 0x80019ACC: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
    // 0x80019AD0: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80019AD4: bne         $at, $zero, L_80019AE0
    if (ctx->r1 != 0) {
        // 0x80019AD8: slt         $at, $t6, $t7
        ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
            goto L_80019AE0;
    }
    // 0x80019AD8: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80019ADC: beq         $at, $zero, L_80019AEC
    if (ctx->r1 == 0) {
        // 0x80019AE0: slti        $at, $s3, 0x3
        ctx->r1 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
            goto L_80019AEC;
    }
L_80019AE0:
    // 0x80019AE0: slti        $at, $s3, 0x3
    ctx->r1 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
    // 0x80019AE4: bne         $at, $zero, L_8001A7E4
    if (ctx->r1 != 0) {
        // 0x80019AE8: nop
    
            goto L_8001A7E4;
    }
    // 0x80019AE8: nop

L_80019AEC:
    // 0x80019AEC: blez        $a3, L_80019BF4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80019AF0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80019BF4;
    }
    // 0x80019AF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019AF4: addiu       $v1, $sp, 0x5C
    ctx->r3 = ADD32(ctx->r29, 0X5C);
    // 0x80019AF8: addu        $a0, $a3, $v1
    ctx->r4 = ADD32(ctx->r7, ctx->r3);
    // 0x80019AFC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80019B00: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80019B04: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80019B08: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
L_80019B0C:
    // 0x80019B0C: lb          $t9, 0x4C($ra)
    ctx->r25 = MEM_B(ctx->r31, 0X4C);
    // 0x80019B10: nop

    // 0x80019B14: bne         $t1, $t9, L_80019B38
    if (ctx->r9 != ctx->r25) {
        // 0x80019B18: nop
    
            goto L_80019B38;
    }
    // 0x80019B18: nop

    // 0x80019B1C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80019B20: nop

    // 0x80019B24: lb          $t7, 0x185($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X185);
    // 0x80019B28: nop

    // 0x80019B2C: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x80019B30: b           L_80019BB4
    // 0x80019B34: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
        goto L_80019BB4;
    // 0x80019B34: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_80019B38:
    // 0x80019B38: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80019B3C: nop

    // 0x80019B40: lb          $t9, 0x193($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X193);
    // 0x80019B44: nop

    // 0x80019B48: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x80019B4C: lb          $t6, 0x4C($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4C);
    // 0x80019B50: nop

    // 0x80019B54: bne         $a2, $t6, L_80019BB4
    if (ctx->r6 != ctx->r14) {
        // 0x80019B58: nop
    
            goto L_80019BB4;
    }
    // 0x80019B58: nop

    // 0x80019B5C: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x80019B60: nop

    // 0x80019B64: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019B68: mflo        $t8
    ctx->r24 = lo;
    // 0x80019B6C: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x80019B70: lb          $t9, 0x1CF($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1CF);
    // 0x80019B74: nop

    // 0x80019B78: beq         $t9, $zero, L_80019B94
    if (ctx->r25 == 0) {
        // 0x80019B7C: nop
    
            goto L_80019B94;
    }
    // 0x80019B7C: nop

    // 0x80019B80: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x80019B84: nop

    // 0x80019B88: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x80019B8C: b           L_80019BB4
    // 0x80019B90: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
        goto L_80019BB4;
    // 0x80019B90: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_80019B94:
    // 0x80019B94: lw          $t8, 0x144($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X144);
    // 0x80019B98: nop

    // 0x80019B9C: beq         $t8, $zero, L_80019BB4
    if (ctx->r24 == 0) {
        // 0x80019BA0: nop
    
            goto L_80019BB4;
    }
    // 0x80019BA0: nop

    // 0x80019BA4: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x80019BA8: nop

    // 0x80019BAC: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80019BB0: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_80019BB4:
    // 0x80019BB4: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80019BB8: nop

    // 0x80019BBC: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80019BC0: bne         $at, $zero, L_80019BD4
    if (ctx->r1 != 0) {
        // 0x80019BC4: nop
    
            goto L_80019BD4;
    }
    // 0x80019BC4: nop

    // 0x80019BC8: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x80019BCC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80019BD0: nop

L_80019BD4:
    // 0x80019BD4: bgez        $v0, L_80019BE0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80019BD8: nop
    
            goto L_80019BE0;
    }
    // 0x80019BD8: nop

    // 0x80019BDC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80019BE0:
    // 0x80019BE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80019BE4: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80019BE8: bne         $at, $zero, L_80019B0C
    if (ctx->r1 != 0) {
        // 0x80019BEC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80019B0C;
    }
    // 0x80019BEC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80019BF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80019BF4:
    // 0x80019BF4: addiu       $t0, $sp, 0x6C
    ctx->r8 = ADD32(ctx->r29, 0X6C);
    // 0x80019BF8: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
L_80019BFC:
    // 0x80019BFC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80019C00: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80019C04: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x80019C08: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80019C0C: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80019C10: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80019C14: blez        $a3, L_80019C78
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80019C18: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_80019C78;
    }
    // 0x80019C18: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80019C1C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
L_80019C20:
    // 0x80019C20: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80019C24: addu        $t7, $a2, $s0
    ctx->r15 = ADD32(ctx->r6, ctx->r16);
    // 0x80019C28: lb          $t6, 0x1D8($t9)
    ctx->r14 = MEM_B(ctx->r25, 0X1D8);
    // 0x80019C2C: nop

    // 0x80019C30: bne         $t6, $zero, L_80019C64
    if (ctx->r14 != 0) {
        // 0x80019C34: nop
    
            goto L_80019C64;
    }
    // 0x80019C34: nop

    // 0x80019C38: lb          $v0, 0x0($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X0);
    // 0x80019C3C: nop

    // 0x80019C40: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80019C44: bne         $at, $zero, L_80019C64
    if (ctx->r1 != 0) {
        // 0x80019C48: nop
    
            goto L_80019C64;
    }
    // 0x80019C48: nop

    // 0x80019C4C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80019C50: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80019C54: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80019C58: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80019C5C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80019C60: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_80019C64:
    // 0x80019C64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80019C68: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80019C6C: bne         $at, $zero, L_80019C20
    if (ctx->r1 != 0) {
        // 0x80019C70: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80019C20;
    }
    // 0x80019C70: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80019C74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80019C78:
    // 0x80019C78: beq         $a0, $s5, L_80019CD4
    if (ctx->r4 == ctx->r21) {
        // 0x80019C7C: nop
    
            goto L_80019CD4;
    }
    // 0x80019C7C: nop

    // 0x80019C80: lb          $t6, 0x4C($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4C);
    // 0x80019C84: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80019C88: bne         $t1, $t6, L_80019CB0
    if (ctx->r9 != ctx->r14) {
        // 0x80019C8C: addu        $v0, $t0, $t9
        ctx->r2 = ADD32(ctx->r8, ctx->r25);
            goto L_80019CB0;
    }
    // 0x80019C8C: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x80019C90: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80019C94: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80019C98: addu        $v0, $t0, $t7
    ctx->r2 = ADD32(ctx->r8, ctx->r15);
    // 0x80019C9C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80019CA0: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80019CA4: subu        $t6, $t9, $t8
    ctx->r14 = SUB32(ctx->r25, ctx->r24);
    // 0x80019CA8: b           L_80019CC0
    // 0x80019CAC: sh          $t6, 0x1AC($t7)
    MEM_H(0X1AC, ctx->r15) = ctx->r14;
        goto L_80019CC0;
    // 0x80019CAC: sh          $t6, 0x1AC($t7)
    MEM_H(0X1AC, ctx->r15) = ctx->r14;
L_80019CB0:
    // 0x80019CB0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80019CB4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80019CB8: nop

    // 0x80019CBC: sh          $t8, 0x1AC($t6)
    MEM_H(0X1AC, ctx->r14) = ctx->r24;
L_80019CC0:
    // 0x80019CC0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80019CC4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80019CC8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80019CCC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80019CD0: sb          $s4, 0x1D8($t8)
    MEM_B(0X1D8, ctx->r24) = ctx->r20;
L_80019CD4:
    // 0x80019CD4: bne         $a0, $s5, L_80019BFC
    if (ctx->r4 != ctx->r21) {
        // 0x80019CD8: nop
    
            goto L_80019BFC;
    }
    // 0x80019CD8: nop

    // 0x80019CDC: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80019CE0: addiu       $s3, $s3, -0x334C
    ctx->r19 = ADD32(ctx->r19, -0X334C);
    // 0x80019CE4: jal         0x8009C814
    // 0x80019CE8: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    is_in_tracks_mode(rdram, ctx);
        goto after_4;
    // 0x80019CE8: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    after_4:
    // 0x80019CEC: bne         $v0, $zero, L_80019D80
    if (ctx->r2 != 0) {
        // 0x80019CF0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019D80;
    }
    // 0x80019CF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019CF4: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80019CF8: nop

    // 0x80019CFC: lh          $t7, 0x1AC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X1AC);
    // 0x80019D00: nop

    // 0x80019D04: beq         $s4, $t7, L_80019D34
    if (ctx->r20 == ctx->r15) {
        // 0x80019D08: nop
    
            goto L_80019D34;
    }
    // 0x80019D08: nop

    // 0x80019D0C: jal         0x8009F1C4
    // 0x80019D10: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_5;
    // 0x80019D10: nop

    after_5:
    // 0x80019D14: beq         $v0, $zero, L_80019D80
    if (ctx->r2 == 0) {
        // 0x80019D18: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019D80;
    }
    // 0x80019D18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019D1C: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80019D20: nop

    // 0x80019D24: lh          $t8, 0x1AC($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X1AC);
    // 0x80019D28: nop

    // 0x80019D2C: bne         $s4, $t8, L_80019D80
    if (ctx->r20 != ctx->r24) {
        // 0x80019D30: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019D80;
    }
    // 0x80019D30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80019D34:
    // 0x80019D34: lbu         $t7, 0x49($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X49);
    // 0x80019D38: lw          $t6, 0x4($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X4);
    // 0x80019D3C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80019D40: addu        $v0, $t6, $t9
    ctx->r2 = ADD32(ctx->r14, ctx->r25);
    // 0x80019D44: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80019D48: nop

    // 0x80019D4C: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x80019D50: bne         $t8, $zero, L_80019D7C
    if (ctx->r24 != 0) {
        // 0x80019D54: ori         $t7, $v1, 0x2
        ctx->r15 = ctx->r3 | 0X2;
            goto L_80019D7C;
    }
    // 0x80019D54: ori         $t7, $v1, 0x2
    ctx->r15 = ctx->r3 | 0X2;
    // 0x80019D58: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80019D5C: lbu         $s0, 0x16($s6)
    ctx->r16 = MEM_BU(ctx->r22, 0X16);
    // 0x80019D60: nop

    // 0x80019D64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80019D68: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x80019D6C: bne         $at, $zero, L_80019D78
    if (ctx->r1 != 0) {
        // 0x80019D70: nop
    
            goto L_80019D78;
    }
    // 0x80019D70: nop

    // 0x80019D74: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_80019D78:
    // 0x80019D78: sb          $s0, 0x16($s6)
    MEM_B(0X16, ctx->r22) = ctx->r16;
L_80019D7C:
    // 0x80019D7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80019D80:
    // 0x80019D80: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
L_80019D84:
    // 0x80019D84: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80019D88: slti        $at, $a2, 0x8
    ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    // 0x80019D8C: sb          $s5, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r21;
    // 0x80019D90: bne         $at, $zero, L_80019D84
    if (ctx->r1 != 0) {
        // 0x80019D94: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_80019D84;
    }
    // 0x80019D94: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80019D98: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80019D9C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80019DA0: blez        $t6, L_80019E00
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80019DA4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019E00;
    }
    // 0x80019DA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019DA8: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80019DAC: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
L_80019DB0:
    // 0x80019DB0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80019DB4: nop

    // 0x80019DB8: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80019DBC: nop

    // 0x80019DC0: beq         $s5, $t9, L_80019DDC
    if (ctx->r21 == ctx->r25) {
        // 0x80019DC4: nop
    
            goto L_80019DDC;
    }
    // 0x80019DC4: nop

    // 0x80019DC8: lh          $t8, 0x1AC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X1AC);
    // 0x80019DCC: nop

    // 0x80019DD0: bne         $s4, $t8, L_80019DDC
    if (ctx->r20 != ctx->r24) {
        // 0x80019DD4: nop
    
            goto L_80019DDC;
    }
    // 0x80019DD4: nop

    // 0x80019DD8: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
L_80019DDC:
    // 0x80019DDC: lh          $t7, 0x1AC($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X1AC);
    // 0x80019DE0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80019DE4: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x80019DE8: sb          $t6, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r14;
    // 0x80019DEC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80019DF0: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80019DF4: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80019DF8: bne         $at, $zero, L_80019DB0
    if (ctx->r1 != 0) {
        // 0x80019DFC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80019DB0;
    }
    // 0x80019DFC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80019E00:
    // 0x80019E00: jal         0x80000B34
    // 0x80019E04: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    music_play(rdram, ctx);
        goto after_6;
    // 0x80019E04: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    after_6:
    // 0x80019E08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80019E0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019E10: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80019E14: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
L_80019E18:
    // 0x80019E18: lb          $t8, 0x5A($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5A);
    // 0x80019E1C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80019E20: bne         $s5, $t8, L_80019E30
    if (ctx->r21 != ctx->r24) {
        // 0x80019E24: nop
    
            goto L_80019E30;
    }
    // 0x80019E24: nop

    // 0x80019E28: sb          $a1, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r5;
    // 0x80019E2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80019E30:
    // 0x80019E30: bne         $v1, $a0, L_80019E18
    if (ctx->r3 != ctx->r4) {
        // 0x80019E34: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_80019E18;
    }
    // 0x80019E34: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80019E38: jal         0x8009F1C4
    // 0x80019E3C: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    is_in_two_player_adventure(rdram, ctx);
        goto after_7;
    // 0x80019E3C: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    after_7:
    // 0x80019E40: beq         $v0, $zero, L_80019E64
    if (ctx->r2 == 0) {
        // 0x80019E44: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80019E64;
    }
    // 0x80019E44: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80019E48: lb          $t7, 0x72($s6)
    ctx->r15 = MEM_B(ctx->r22, 0X72);
    // 0x80019E4C: lb          $t6, 0x5A($s6)
    ctx->r14 = MEM_B(ctx->r22, 0X5A);
    // 0x80019E50: nop

    // 0x80019E54: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80019E58: beq         $at, $zero, L_80019E64
    if (ctx->r1 == 0) {
        // 0x80019E5C: nop
    
            goto L_80019E64;
    }
    // 0x80019E5C: nop

    // 0x80019E60: sb          $s4, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r20;
L_80019E64:
    // 0x80019E64: bne         $s0, $zero, L_80019ED8
    if (ctx->r16 != 0) {
        // 0x80019E68: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80019ED8;
    }
    // 0x80019E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019E6C: jal         0x8009F1C4
    // 0x80019E70: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_8;
    // 0x80019E70: nop

    after_8:
    // 0x80019E74: beq         $v0, $zero, L_80019EC8
    if (ctx->r2 == 0) {
        // 0x80019E78: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80019EC8;
    }
    // 0x80019E78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019E7C: lb          $t9, 0x0($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X0);
    // 0x80019E80: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80019E84: beq         $t9, $zero, L_80019EB0
    if (ctx->r25 == 0) {
        // 0x80019E88: nop
    
            goto L_80019EB0;
    }
    // 0x80019E88: nop

    // 0x80019E8C: jal         0x8006F5D8
    // 0x80019E90: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    swap_lead_player(rdram, ctx);
        goto after_9;
    // 0x80019E90: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    after_9:
    // 0x80019E94: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80019E98: lb          $t8, -0x3354($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X3354);
    // 0x80019E9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80019EA0: beq         $t8, $zero, L_80019EC8
    if (ctx->r24 == 0) {
        // 0x80019EA4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80019EC8;
    }
    // 0x80019EA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019EA8: b           L_80019EC4
    // 0x80019EAC: sb          $s4, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = ctx->r20;
        goto L_80019EC4;
    // 0x80019EAC: sb          $s4, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = ctx->r20;
L_80019EB0:
    // 0x80019EB0: lb          $t7, -0x3354($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X3354);
    // 0x80019EB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80019EB8: beq         $t7, $zero, L_80019EC8
    if (ctx->r15 == 0) {
        // 0x80019EBC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80019EC8;
    }
    // 0x80019EBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019EC0: sb          $s4, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = ctx->r20;
L_80019EC4:
    // 0x80019EC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80019EC8:
    // 0x80019EC8: jal         0x80094B8C
    // 0x80019ECC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    postrace_start(rdram, ctx);
        goto after_10;
    // 0x80019ECC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_10:
    // 0x80019ED0: b           L_80019F04
    // 0x80019ED4: nop

        goto L_80019F04;
    // 0x80019ED4: nop

L_80019ED8:
    // 0x80019ED8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019EDC: jal         0x8006C3EC
    // 0x80019EE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_11;
    // 0x80019EE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80019EE4: lbu         $a3, 0x16($s6)
    ctx->r7 = MEM_BU(ctx->r22, 0X16);
    // 0x80019EE8: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x80019EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019EF0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80019EF4: jal         0x8006C3EC
    // 0x80019EF8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    level_properties_push(rdram, ctx);
        goto after_12;
    // 0x80019EF8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    after_12:
    // 0x80019EFC: jal         0x8001A908
    // 0x80019F00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    race_finish_adventure(rdram, ctx);
        goto after_13;
    // 0x80019F00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
L_80019F04:
    // 0x80019F04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80019F08: b           L_8001A7E4
    // 0x80019F0C: sw          $s4, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r20;
        goto L_8001A7E4;
    // 0x80019F0C: sw          $s4, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r20;
L_80019F10:
    // 0x80019F10: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80019F14: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80019F18: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80019F1C: lw          $a3, -0x4B90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4B90);
    // 0x80019F20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019F24: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
    // 0x80019F28: addiu       $s2, $s2, -0x4B90
    ctx->r18 = ADD32(ctx->r18, -0X4B90);
    // 0x80019F2C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80019F30: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
L_80019F34:
    // 0x80019F34: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x80019F38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80019F3C: addu        $t6, $t1, $t2
    ctx->r14 = ADD32(ctx->r9, ctx->r10);
    // 0x80019F40: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80019F44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019F48: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x80019F4C: nop

    // 0x80019F50: lh          $t4, 0x1AA($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X1AA);
    // 0x80019F54: nop

L_80019F58:
    // 0x80019F58: beq         $a1, $s0, L_80019FE8
    if (ctx->r5 == ctx->r16) {
        // 0x80019F5C: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80019FE8;
    }
    // 0x80019F5C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80019F60: addu        $t7, $t1, $t8
    ctx->r15 = ADD32(ctx->r9, ctx->r24);
    // 0x80019F64: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80019F68: lb          $t9, 0x1D8($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1D8);
    // 0x80019F6C: lw          $v0, 0x64($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X64);
    // 0x80019F70: bne         $t9, $zero, L_80019F90
    if (ctx->r25 != 0) {
        // 0x80019F74: nop
    
            goto L_80019F90;
    }
    // 0x80019F74: nop

    // 0x80019F78: lb          $t8, 0x1D8($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1D8);
    // 0x80019F7C: nop

    // 0x80019F80: beq         $t8, $zero, L_80019F90
    if (ctx->r24 == 0) {
        // 0x80019F84: nop
    
            goto L_80019F90;
    }
    // 0x80019F84: nop

    // 0x80019F88: b           L_80019FE8
    // 0x80019F8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_80019FE8;
    // 0x80019F8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80019F90:
    // 0x80019F90: lh          $v1, 0x190($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X190);
    // 0x80019F94: lh          $a0, 0x190($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X190);
    // 0x80019F98: nop

    // 0x80019F9C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80019FA0: beq         $at, $zero, L_80019FB0
    if (ctx->r1 == 0) {
        // 0x80019FA4: nop
    
            goto L_80019FB0;
    }
    // 0x80019FA4: nop

    // 0x80019FA8: b           L_80019FE8
    // 0x80019FAC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_80019FE8;
    // 0x80019FAC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80019FB0:
    // 0x80019FB0: bne         $a0, $v1, L_80019FE8
    if (ctx->r4 != ctx->r3) {
        // 0x80019FB4: nop
    
            goto L_80019FE8;
    }
    // 0x80019FB4: nop

    // 0x80019FB8: lh          $v1, 0x1A8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X1A8);
    // 0x80019FBC: lh          $a0, 0x1A8($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X1A8);
    // 0x80019FC0: nop

    // 0x80019FC4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80019FC8: beq         $at, $zero, L_80019FD4
    if (ctx->r1 == 0) {
        // 0x80019FCC: nop
    
            goto L_80019FD4;
    }
    // 0x80019FCC: nop

    // 0x80019FD0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80019FD4:
    // 0x80019FD4: bne         $v1, $a0, L_80019FE8
    if (ctx->r3 != ctx->r4) {
        // 0x80019FD8: slt         $at, $s0, $a1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80019FE8;
    }
    // 0x80019FD8: slt         $at, $s0, $a1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80019FDC: beq         $at, $zero, L_80019FE8
    if (ctx->r1 == 0) {
        // 0x80019FE0: nop
    
            goto L_80019FE8;
    }
    // 0x80019FE0: nop

    // 0x80019FE4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80019FE8:
    // 0x80019FE8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80019FEC: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80019FF0: bne         $at, $zero, L_80019F58
    if (ctx->r1 != 0) {
        // 0x80019FF4: nop
    
            goto L_80019F58;
    }
    // 0x80019FF4: nop

    // 0x80019FF8: sh          $a2, 0x1AA($t0)
    MEM_H(0X1AA, ctx->r8) = ctx->r6;
    // 0x80019FFC: lb          $t6, 0x4B($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4B);
    // 0x8001A000: lb          $t7, 0x193($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X193);
    // 0x8001A004: nop

    // 0x8001A008: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001A00C: beq         $at, $zero, L_8001A070
    if (ctx->r1 == 0) {
        // 0x8001A010: nop
    
            goto L_8001A070;
    }
    // 0x8001A010: nop

    // 0x8001A014: lh          $v0, 0x1AA($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X1AA);
    // 0x8001A018: nop

    // 0x8001A01C: bne         $t4, $v0, L_8001A06C
    if (ctx->r12 != ctx->r2) {
        // 0x8001A020: nop
    
            goto L_8001A06C;
    }
    // 0x8001A020: nop

    // 0x8001A024: lh          $v1, 0x1B0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X1B0);
    // 0x8001A028: nop

    // 0x8001A02C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8001A030: beq         $at, $zero, L_8001A050
    if (ctx->r1 == 0) {
        // 0x8001A034: nop
    
            goto L_8001A050;
    }
    // 0x8001A034: nop

    // 0x8001A038: lb          $t9, 0x1D6($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1D6);
    // 0x8001A03C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001A040: beq         $t9, $at, L_8001A070
    if (ctx->r25 == ctx->r1) {
        // 0x8001A044: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8001A070;
    }
    // 0x8001A044: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8001A048: b           L_8001A070
    // 0x8001A04C: sh          $t8, 0x1B0($t0)
    MEM_H(0X1B0, ctx->r8) = ctx->r24;
        goto L_8001A070;
    // 0x8001A04C: sh          $t8, 0x1B0($t0)
    MEM_H(0X1B0, ctx->r8) = ctx->r24;
L_8001A050:
    // 0x8001A050: lh          $t7, 0x1AE($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X1AE);
    // 0x8001A054: nop

    // 0x8001A058: beq         $t7, $v0, L_8001A070
    if (ctx->r15 == ctx->r2) {
        // 0x8001A05C: nop
    
            goto L_8001A070;
    }
    // 0x8001A05C: nop

    // 0x8001A060: sh          $t5, 0x1B2($t0)
    MEM_H(0X1B2, ctx->r8) = ctx->r13;
    // 0x8001A064: b           L_8001A070
    // 0x8001A068: sh          $v0, 0x1AE($t0)
    MEM_H(0X1AE, ctx->r8) = ctx->r2;
        goto L_8001A070;
    // 0x8001A068: sh          $v0, 0x1AE($t0)
    MEM_H(0X1AE, ctx->r8) = ctx->r2;
L_8001A06C:
    // 0x8001A06C: sh          $zero, 0x1B0($t0)
    MEM_H(0X1B0, ctx->r8) = 0;
L_8001A070:
    // 0x8001A070: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8001A074: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A078: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A07C: bne         $at, $zero, L_80019F34
    if (ctx->r1 != 0) {
        // 0x8001A080: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_80019F34;
    }
    // 0x8001A080: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A084: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001A088: addiu       $s1, $s1, -0x4CC0
    ctx->r17 = ADD32(ctx->r17, -0X4CC0);
    // 0x8001A08C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8001A090: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x8001A094: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_8001A098:
    // 0x8001A098: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8001A09C: nop

    // 0x8001A0A0: addu        $t9, $t6, $t2
    ctx->r25 = ADD32(ctx->r14, ctx->r10);
    // 0x8001A0A4: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8001A0A8: lb          $t6, 0x4B($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4B);
    // 0x8001A0AC: lw          $t0, 0x64($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X64);
    // 0x8001A0B0: nop

    // 0x8001A0B4: lb          $t7, 0x193($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X193);
    // 0x8001A0B8: nop

    // 0x8001A0BC: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001A0C0: bne         $at, $zero, L_8001A164
    if (ctx->r1 != 0) {
        // 0x8001A0C4: nop
    
            goto L_8001A164;
    }
    // 0x8001A0C4: nop

    // 0x8001A0C8: lb          $t9, 0x1D8($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A0CC: nop

    // 0x8001A0D0: bne         $t9, $zero, L_8001A164
    if (ctx->r25 != 0) {
        // 0x8001A0D4: nop
    
            goto L_8001A164;
    }
    // 0x8001A0D4: nop

    // 0x8001A0D8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8001A0DC: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x8001A0E0: jal         0x8006DC4C
    // 0x8001A0E4: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    get_game_mode(rdram, ctx);
        goto after_14;
    // 0x8001A0E4: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_14:
    // 0x8001A0E8: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001A0EC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001A0F0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001A0F4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8001A0F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001A0FC: beq         $v0, $at, L_8001A164
    if (ctx->r2 == ctx->r1) {
        // 0x8001A100: addiu       $t3, $t3, -0x4B9C
        ctx->r11 = ADD32(ctx->r11, -0X4B9C);
            goto L_8001A164;
    }
    // 0x8001A100: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
    // 0x8001A104: sb          $s4, 0x1D8($t0)
    MEM_B(0X1D8, ctx->r8) = ctx->r20;
    // 0x8001A108: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8001A10C: nop

    // 0x8001A110: sh          $t8, 0x1AC($t0)
    MEM_H(0X1AC, ctx->r8) = ctx->r24;
    // 0x8001A114: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A118: nop

    // 0x8001A11C: bne         $s4, $v0, L_8001A160
    if (ctx->r20 != ctx->r2) {
        // 0x8001A120: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8001A160;
    }
    // 0x8001A120: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8001A124: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x8001A128: addiu       $a0, $zero, 0x23C
    ctx->r4 = ADD32(0, 0X23C);
    // 0x8001A12C: bne         $s5, $t7, L_8001A15C
    if (ctx->r21 != ctx->r15) {
        // 0x8001A130: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001A15C;
    }
    // 0x8001A130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A134: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8001A138: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x8001A13C: jal         0x80001D04
    // 0x8001A140: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x8001A140: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_15:
    // 0x8001A144: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001A148: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001A14C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001A150: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8001A154: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A158: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
L_8001A15C:
    // 0x8001A15C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
L_8001A160:
    // 0x8001A160: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_8001A164:
    // 0x8001A164: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8001A168: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x8001A16C: lb          $v0, 0x1D8($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A170: beq         $s5, $t9, L_8001A1A4
    if (ctx->r21 == ctx->r25) {
        // 0x8001A174: sll         $v1, $a3, 2
        ctx->r3 = S32(ctx->r7 << 2);
            goto L_8001A1A4;
    }
    // 0x8001A174: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x8001A178: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
    // 0x8001A17C: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
    // 0x8001A180: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8001A184: beq         $v0, $zero, L_8001A1B8
    if (ctx->r2 == 0) {
        // 0x8001A188: sh          $t7, 0x8A($sp)
        MEM_H(0X8A, ctx->r29) = ctx->r15;
            goto L_8001A1B8;
    }
    // 0x8001A188: sh          $t7, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r15;
    // 0x8001A18C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001A190: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x8001A194: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8001A198: sh          $t9, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r25;
    // 0x8001A19C: b           L_8001A1B8
    // 0x8001A1A0: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
        goto L_8001A1B8;
    // 0x8001A1A0: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
L_8001A1A4:
    // 0x8001A1A4: beq         $v0, $zero, L_8001A1B8
    if (ctx->r2 == 0) {
        // 0x8001A1A8: nop
    
            goto L_8001A1B8;
    }
    // 0x8001A1A8: nop

    // 0x8001A1AC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001A1B0: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x8001A1B4: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
L_8001A1B8:
    // 0x8001A1B8: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A1BC: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001A1C0: bne         $at, $zero, L_8001A098
    if (ctx->r1 != 0) {
        // 0x8001A1C4: nop
    
            goto L_8001A098;
    }
    // 0x8001A1C4: nop

    // 0x8001A1C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A1CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A1D0: addiu       $t1, $t1, -0x4B98
    ctx->r9 = ADD32(ctx->r9, -0X4B98);
    // 0x8001A1D4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001A1D8:
    // 0x8001A1D8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001A1DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A1E0: addu        $t7, $t8, $t2
    ctx->r15 = ADD32(ctx->r24, ctx->r10);
    // 0x8001A1E4: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8001A1E8: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001A1EC: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A1F0: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001A1F4: bne         $at, $zero, L_8001A1D8
    if (ctx->r1 != 0) {
        // 0x8001A1F8: nop
    
            goto L_8001A1D8;
    }
    // 0x8001A1F8: nop

    // 0x8001A1FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A200: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001A204:
    // 0x8001A204: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x8001A208: nop

    // 0x8001A20C: addu        $t8, $t9, $t2
    ctx->r24 = ADD32(ctx->r25, ctx->r10);
    // 0x8001A210: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001A214: nop

    // 0x8001A218: lw          $t0, 0x64($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X64);
    // 0x8001A21C: nop

    // 0x8001A220: lb          $t7, 0x1D8($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A224: nop

    // 0x8001A228: beq         $t7, $zero, L_8001A23C
    if (ctx->r15 == 0) {
        // 0x8001A22C: nop
    
            goto L_8001A23C;
    }
    // 0x8001A22C: nop

    // 0x8001A230: lh          $a2, 0x1AC($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X1AC);
    // 0x8001A234: b           L_8001A248
    // 0x8001A238: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
        goto L_8001A248;
    // 0x8001A238: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001A23C:
    // 0x8001A23C: lh          $a2, 0x1AA($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X1AA);
    // 0x8001A240: nop

    // 0x8001A244: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001A248:
    // 0x8001A248: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001A24C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8001A250: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8001A254: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8001A258: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8001A25C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A260: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A264: bne         $at, $zero, L_8001A204
    if (ctx->r1 != 0) {
        // 0x8001A268: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8001A204;
    }
    // 0x8001A268: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A26C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001A274:
    // 0x8001A274: blez        $a3, L_8001A2D0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8001A278: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001A2D0;
    }
    // 0x8001A278: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001A27C: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8001A280: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8001A284: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8001A288: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8001A28C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8001A290: nop

    // 0x8001A294: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
L_8001A298:
    // 0x8001A298: addu        $t7, $v1, $t8
    ctx->r15 = ADD32(ctx->r3, ctx->r24);
    // 0x8001A29C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8001A2A0: nop

    // 0x8001A2A4: bne         $t6, $v0, L_8001A2C0
    if (ctx->r14 != ctx->r2) {
        // 0x8001A2A8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001A2C0;
    }
    // 0x8001A2A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001A2AC: sll         $a0, $s4, 24
    ctx->r4 = S32(ctx->r20 << 24);
    // 0x8001A2B0: sra         $t9, $a0, 24
    ctx->r25 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8001A2B4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8001A2B8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8001A2BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8001A2C0:
    // 0x8001A2C0: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A2C4: bne         $at, $zero, L_8001A298
    if (ctx->r1 != 0) {
        // 0x8001A2C8: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_8001A298;
    }
    // 0x8001A2C8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8001A2CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001A2D0:
    // 0x8001A2D0: bne         $a0, $zero, L_8001A334
    if (ctx->r4 != 0) {
        // 0x8001A2D4: nop
    
            goto L_8001A334;
    }
    // 0x8001A2D4: nop

    // 0x8001A2D8: blez        $a3, L_8001A334
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8001A2DC: nop
    
            goto L_8001A334;
    }
    // 0x8001A2DC: nop

L_8001A2E0:
    // 0x8001A2E0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001A2E4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8001A2E8: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x8001A2EC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001A2F0: nop

    // 0x8001A2F4: bne         $t6, $zero, L_8001A324
    if (ctx->r14 != 0) {
        // 0x8001A2F8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001A324;
    }
    // 0x8001A2F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001A2FC: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x8001A300: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8001A304: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8001A308: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8001A30C: nop

    // 0x8001A310: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001A314: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8001A318: nop

    // 0x8001A31C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8001A320: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8001A324:
    // 0x8001A324: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A328: bne         $at, $zero, L_8001A2E0
    if (ctx->r1 != 0) {
        // 0x8001A32C: nop
    
            goto L_8001A2E0;
    }
    // 0x8001A32C: nop

    // 0x8001A330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001A334:
    // 0x8001A334: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A338: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A33C: bne         $at, $zero, L_8001A274
    if (ctx->r1 != 0) {
        // 0x8001A340: nop
    
            goto L_8001A274;
    }
    // 0x8001A340: nop

    // 0x8001A344: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001A348:
    // 0x8001A348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001A34C: jal         0x8006A794
    // 0x8001A350: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_16;
    // 0x8001A350: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    after_16:
    // 0x8001A354: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x8001A358: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A35C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8001A360: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001A364: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
    // 0x8001A368: bne         $at, $zero, L_8001A348
    if (ctx->r1 != 0) {
        // 0x8001A36C: or          $a1, $a1, $v0
        ctx->r5 = ctx->r5 | ctx->r2;
            goto L_8001A348;
    }
    // 0x8001A36C: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8001A370: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8001A374: lb          $t9, -0x4B8A($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X4B8A);
    // 0x8001A378: lh          $t8, 0x88($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X88);
    // 0x8001A37C: beq         $t9, $zero, L_8001A39C
    if (ctx->r25 == 0) {
        // 0x8001A380: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8001A39C;
    }
    // 0x8001A380: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001A384: beq         $t8, $zero, L_8001A39C
    if (ctx->r24 == 0) {
        // 0x8001A388: nop
    
            goto L_8001A39C;
    }
    // 0x8001A388: nop

    // 0x8001A38C: jal         0x80022E4C
    // 0x8001A390: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mode_end_taj_race(rdram, ctx);
        goto after_17;
    // 0x8001A390: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x8001A394: b           L_8001A7E8
    // 0x8001A398: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8001A7E8;
    // 0x8001A398: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001A39C:
    // 0x8001A39C: lb          $t7, -0x4D44($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X4D44);
    // 0x8001A3A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001A3A4: beq         $t7, $zero, L_8001A400
    if (ctx->r15 == 0) {
        // 0x8001A3A8: nop
    
            goto L_8001A400;
    }
    // 0x8001A3A8: nop

    // 0x8001A3AC: beq         $s3, $zero, L_8001A400
    if (ctx->r19 == 0) {
        // 0x8001A3B0: nop
    
            goto L_8001A400;
    }
    // 0x8001A3B0: nop

    // 0x8001A3B4: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8001A3B8: nop

    // 0x8001A3BC: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8001A3C0: nop

    // 0x8001A3C4: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x8001A3C8: nop

    // 0x8001A3CC: lb          $t8, 0x1D8($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A3D0: nop

    // 0x8001A3D4: bne         $t8, $zero, L_8001A7E8
    if (ctx->r24 != 0) {
        // 0x8001A3D8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001A7E8;
    }
    // 0x8001A3D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001A3DC: sb          $s4, 0x1D8($t0)
    MEM_B(0X1D8, ctx->r8) = ctx->r20;
    // 0x8001A3E0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8001A3E4: nop

    // 0x8001A3E8: sh          $t7, 0x1AC($t0)
    MEM_H(0X1AC, ctx->r8) = ctx->r15;
    // 0x8001A3EC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001A3F0: nop

    // 0x8001A3F4: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8001A3F8: b           L_8001A7E4
    // 0x8001A3FC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
        goto L_8001A7E4;
    // 0x8001A3FC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_8001A400:
    // 0x8001A400: lw          $t8, -0x4CCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4CCC);
    // 0x8001A404: nop

    // 0x8001A408: bne         $t8, $zero, L_8001A7E8
    if (ctx->r24 != 0) {
        // 0x8001A40C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001A7E8;
    }
    // 0x8001A40C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001A410: jal         0x8009F1C4
    // 0x8001A414: sb          $zero, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = 0;
    is_in_two_player_adventure(rdram, ctx);
        goto after_18;
    // 0x8001A414: sb          $zero, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = 0;
    after_18:
    // 0x8001A418: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A41C: beq         $v0, $zero, L_8001A460
    if (ctx->r2 == 0) {
        // 0x8001A420: addiu       $t1, $t1, -0x4B98
        ctx->r9 = ADD32(ctx->r9, -0X4B98);
            goto L_8001A460;
    }
    // 0x8001A420: addiu       $t1, $t1, -0x4B98
    ctx->r9 = ADD32(ctx->r9, -0X4B98);
    // 0x8001A424: lh          $t7, 0x88($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X88);
    // 0x8001A428: nop

    // 0x8001A42C: blez        $t7, L_8001A464
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001A430: lh          $t6, 0x88($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X88);
            goto L_8001A464;
    }
    // 0x8001A430: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
    // 0x8001A434: jal         0x80099B68
    // 0x8001A438: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_19;
    // 0x8001A438: nop

    after_19:
    // 0x8001A43C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A440: bne         $v0, $zero, L_8001A460
    if (ctx->r2 != 0) {
        // 0x8001A444: addiu       $t1, $t1, -0x4B98
        ctx->r9 = ADD32(ctx->r9, -0X4B98);
            goto L_8001A460;
    }
    // 0x8001A444: addiu       $t1, $t1, -0x4B98
    ctx->r9 = ADD32(ctx->r9, -0X4B98);
    // 0x8001A448: jal         0x8001A80C
    // 0x8001A44C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    set_course_finish_flags(rdram, ctx);
        goto after_20;
    // 0x8001A44C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_20:
    // 0x8001A450: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A454: beq         $v0, $zero, L_8001A460
    if (ctx->r2 == 0) {
        // 0x8001A458: addiu       $t1, $t1, -0x4B98
        ctx->r9 = ADD32(ctx->r9, -0X4B98);
            goto L_8001A460;
    }
    // 0x8001A458: addiu       $t1, $t1, -0x4B98
    ctx->r9 = ADD32(ctx->r9, -0X4B98);
    // 0x8001A45C: sb          $s4, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r20;
L_8001A460:
    // 0x8001A460: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
L_8001A464:
    // 0x8001A464: lh          $t9, 0x8A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X8A);
    // 0x8001A468: nop

    // 0x8001A46C: beq         $t6, $t9, L_8001A4A4
    if (ctx->r14 == ctx->r25) {
        // 0x8001A470: slti        $at, $t9, 0x2
        ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
            goto L_8001A4A4;
    }
    // 0x8001A470: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8001A474: bne         $at, $zero, L_8001A498
    if (ctx->r1 != 0) {
        // 0x8001A478: lb          $t6, 0x5B($sp)
        ctx->r14 = MEM_B(ctx->r29, 0X5B);
            goto L_8001A498;
    }
    // 0x8001A478: lb          $t6, 0x5B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X5B);
    // 0x8001A47C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8001A480: nop

    // 0x8001A484: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x8001A488: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001A48C: beq         $at, $zero, L_8001A4A8
    if (ctx->r1 == 0) {
        // 0x8001A490: lh          $t9, 0x88($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X88);
            goto L_8001A4A8;
    }
    // 0x8001A490: lh          $t9, 0x88($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X88);
    // 0x8001A494: lb          $t6, 0x5B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X5B);
L_8001A498:
    // 0x8001A498: nop

    // 0x8001A49C: beq         $t6, $zero, L_8001A7E8
    if (ctx->r14 == 0) {
        // 0x8001A4A0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001A7E8;
    }
    // 0x8001A4A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001A4A4:
    // 0x8001A4A4: lh          $t9, 0x88($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X88);
L_8001A4A8:
    // 0x8001A4A8: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
    // 0x8001A4AC: nop

    // 0x8001A4B0: beq         $t9, $t8, L_8001A558
    if (ctx->r25 == ctx->r24) {
        // 0x8001A4B4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001A558;
    }
    // 0x8001A4B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A4B8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001A4BC:
    // 0x8001A4BC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8001A4C0: nop

    // 0x8001A4C4: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x8001A4C8: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8001A4CC: nop

    // 0x8001A4D0: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x8001A4D4: nop

    // 0x8001A4D8: lb          $t8, 0x1D8($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A4DC: nop

    // 0x8001A4E0: bne         $t8, $zero, L_8001A544
    if (ctx->r24 != 0) {
        // 0x8001A4E4: nop
    
            goto L_8001A544;
    }
    // 0x8001A4E4: nop

    // 0x8001A4E8: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    // 0x8001A4EC: nop

    // 0x8001A4F0: bltz        $a0, L_8001A524
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001A4F4: nop
    
            goto L_8001A524;
    }
    // 0x8001A4F4: nop

    // 0x8001A4F8: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x8001A4FC: jal         0x80066828
    // 0x8001A500: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    set_active_camera(rdram, ctx);
        goto after_21;
    // 0x8001A500: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_21:
    // 0x8001A504: jal         0x80069F3C
    // 0x8001A508: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_22;
    // 0x8001A508: nop

    after_22:
    // 0x8001A50C: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001A510: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A514: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001A518: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8001A51C: addiu       $t1, $t1, -0x4B98
    ctx->r9 = ADD32(ctx->r9, -0X4B98);
    // 0x8001A520: sh          $t7, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r15;
L_8001A524:
    // 0x8001A524: sb          $s4, 0x1D8($t0)
    MEM_B(0X1D8, ctx->r8) = ctx->r20;
    // 0x8001A528: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001A52C: nop

    // 0x8001A530: sh          $t6, 0x1AC($t0)
    MEM_H(0X1AC, ctx->r8) = ctx->r14;
    // 0x8001A534: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8001A538: nop

    // 0x8001A53C: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8001A540: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
L_8001A544:
    // 0x8001A544: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8001A548: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A54C: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001A550: bne         $at, $zero, L_8001A4BC
    if (ctx->r1 != 0) {
        // 0x8001A554: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8001A4BC;
    }
    // 0x8001A554: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
L_8001A558:
    // 0x8001A558: lui         $v1, 0xA460
    ctx->r3 = S32(0XA460 << 16);
    // 0x8001A55C: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x8001A560: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001A564: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001A568: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8001A56C: beq         $t6, $zero, L_8001A588
    if (ctx->r14 == 0) {
        // 0x8001A570: lui         $t8, 0xB000
        ctx->r24 = S32(0XB000 << 16);
            goto L_8001A588;
    }
    // 0x8001A570: lui         $t8, 0xB000
    ctx->r24 = S32(0XB000 << 16);
L_8001A574:
    // 0x8001A574: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001A578: nop

    // 0x8001A57C: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8001A580: bne         $t9, $zero, L_8001A574
    if (ctx->r25 != 0) {
        // 0x8001A584: nop
    
            goto L_8001A574;
    }
    // 0x8001A584: nop

L_8001A588:
    // 0x8001A588: lw          $t7, 0x574($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X574);
    // 0x8001A58C: addiu       $at, $zero, 0x6C07
    ctx->r1 = ADD32(0, 0X6C07);
    // 0x8001A590: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x8001A594: beq         $t6, $at, L_8001A5A8
    if (ctx->r14 == ctx->r1) {
        // 0x8001A598: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8001A5A8;
    }
    // 0x8001A598: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001A59C: sll         $a0, $s4, 24
    ctx->r4 = S32(ctx->r20 << 24);
    // 0x8001A5A0: sra         $t9, $a0, 24
    ctx->r25 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8001A5A4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_8001A5A8:
    // 0x8001A5A8: lbu         $t8, -0x4B8B($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X4B8B);
    // 0x8001A5AC: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8001A5B0: bne         $t8, $zero, L_8001A60C
    if (ctx->r24 != 0) {
        // 0x8001A5B4: addiu       $s3, $s3, -0x334C
        ctx->r19 = ADD32(ctx->r19, -0X334C);
            goto L_8001A60C;
    }
    // 0x8001A5B4: addiu       $s3, $s3, -0x334C
    ctx->r19 = ADD32(ctx->r19, -0X334C);
    // 0x8001A5B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A5BC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8001A5C0: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_8001A5C4:
    // 0x8001A5C4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8001A5C8: nop

    // 0x8001A5CC: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x8001A5D0: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8001A5D4: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A5D8: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x8001A5DC: nop

    // 0x8001A5E0: lb          $a2, 0x2($t0)
    ctx->r6 = MEM_B(ctx->r8, 0X2);
    // 0x8001A5E4: nop

    // 0x8001A5E8: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A5EC: mflo        $t8
    ctx->r24 = lo;
    // 0x8001A5F0: addu        $t7, $s6, $t8
    ctx->r15 = ADD32(ctx->r22, ctx->r24);
    // 0x8001A5F4: sb          $s0, 0x5A($t7)
    MEM_B(0X5A, ctx->r15) = ctx->r16;
    // 0x8001A5F8: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001A5FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A600: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001A604: bne         $at, $zero, L_8001A5C4
    if (ctx->r1 != 0) {
        // 0x8001A608: nop
    
            goto L_8001A5C4;
    }
    // 0x8001A608: nop

L_8001A60C:
    // 0x8001A60C: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x8001A610: jal         0x8009F1C4
    // 0x8001A614: sb          $a0, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r4;
    is_in_two_player_adventure(rdram, ctx);
        goto after_23;
    // 0x8001A614: sb          $a0, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r4;
    after_23:
    // 0x8001A618: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A61C: beq         $v0, $zero, L_8001A640
    if (ctx->r2 == 0) {
        // 0x8001A620: addiu       $t1, $t1, -0x4B98
        ctx->r9 = ADD32(ctx->r9, -0X4B98);
            goto L_8001A640;
    }
    // 0x8001A620: addiu       $t1, $t1, -0x4B98
    ctx->r9 = ADD32(ctx->r9, -0X4B98);
    // 0x8001A624: lb          $t9, 0x72($s6)
    ctx->r25 = MEM_B(ctx->r22, 0X72);
    // 0x8001A628: lb          $t8, 0x5A($s6)
    ctx->r24 = MEM_B(ctx->r22, 0X5A);
    // 0x8001A62C: nop

    // 0x8001A630: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001A634: beq         $at, $zero, L_8001A640
    if (ctx->r1 == 0) {
        // 0x8001A638: nop
    
            goto L_8001A640;
    }
    // 0x8001A638: nop

    // 0x8001A63C: sb          $s4, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r20;
L_8001A640:
    // 0x8001A640: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8001A644: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001A648: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8001A64C: addiu       $s1, $s1, -0x4CBC
    ctx->r17 = ADD32(ctx->r17, -0X4CBC);
    // 0x8001A650: lw          $t0, 0x64($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X64);
    // 0x8001A654: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x8001A658: lbu         $t9, 0x4A($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X4A);
    // 0x8001A65C: nop

    // 0x8001A660: beq         $s4, $t9, L_8001A67C
    if (ctx->r20 == ctx->r25) {
        // 0x8001A664: nop
    
            goto L_8001A67C;
    }
    // 0x8001A664: nop

    // 0x8001A668: jal         0x8009F1C4
    // 0x8001A66C: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    is_in_two_player_adventure(rdram, ctx);
        goto after_24;
    // 0x8001A66C: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    after_24:
    // 0x8001A670: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001A674: beq         $v0, $zero, L_8001A6B0
    if (ctx->r2 == 0) {
        // 0x8001A678: nop
    
            goto L_8001A6B0;
    }
    // 0x8001A678: nop

L_8001A67C:
    // 0x8001A67C: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x8001A680: nop

    // 0x8001A684: beq         $s5, $t8, L_8001A6B0
    if (ctx->r21 == ctx->r24) {
        // 0x8001A688: nop
    
            goto L_8001A6B0;
    }
    // 0x8001A688: nop

    // 0x8001A68C: jal         0x8009C814
    // 0x8001A690: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_25;
    // 0x8001A690: nop

    after_25:
    // 0x8001A694: bne         $v0, $zero, L_8001A6B0
    if (ctx->r2 != 0) {
        // 0x8001A698: nop
    
            goto L_8001A6B0;
    }
    // 0x8001A698: nop

    // 0x8001A69C: jal         0x80099B68
    // 0x8001A6A0: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_26;
    // 0x8001A6A0: nop

    after_26:
    // 0x8001A6A4: bne         $v0, $zero, L_8001A6B0
    if (ctx->r2 != 0) {
        // 0x8001A6A8: nop
    
            goto L_8001A6B0;
    }
    // 0x8001A6A8: nop

    // 0x8001A6AC: sb          $s4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r20;
L_8001A6B0:
    // 0x8001A6B0: lb          $t7, 0x0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X0);
    // 0x8001A6B4: lb          $t6, 0x5B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X5B);
    // 0x8001A6B8: beq         $t7, $zero, L_8001A6D4
    if (ctx->r15 == 0) {
        // 0x8001A6BC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001A6D4;
    }
    // 0x8001A6BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A6C0: bne         $t6, $zero, L_8001A6D8
    if (ctx->r14 != 0) {
        // 0x8001A6C4: lb          $t9, 0x5B($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X5B);
            goto L_8001A6D8;
    }
    // 0x8001A6C4: lb          $t9, 0x5B($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X5B);
    // 0x8001A6C8: jal         0x8001A80C
    // 0x8001A6CC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    set_course_finish_flags(rdram, ctx);
        goto after_27;
    // 0x8001A6CC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_27:
    // 0x8001A6D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8001A6D4:
    // 0x8001A6D4: lb          $t9, 0x5B($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X5B);
L_8001A6D8:
    // 0x8001A6D8: nop

    // 0x8001A6DC: beq         $t9, $zero, L_8001A6F0
    if (ctx->r25 == 0) {
        // 0x8001A6E0: lb          $t8, 0x5A($sp)
        ctx->r24 = MEM_B(ctx->r29, 0X5A);
            goto L_8001A6F0;
    }
    // 0x8001A6E0: lb          $t8, 0x5A($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X5A);
    // 0x8001A6E4: sb          $s4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r20;
    // 0x8001A6E8: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8001A6EC: lb          $t8, 0x5A($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X5A);
L_8001A6F0:
    // 0x8001A6F0: nop

    // 0x8001A6F4: beq         $t8, $zero, L_8001A704
    if (ctx->r24 == 0) {
        // 0x8001A6F8: nop
    
            goto L_8001A704;
    }
    // 0x8001A6F8: nop

    // 0x8001A6FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A700: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8001A704:
    // 0x8001A704: bne         $s0, $zero, L_8001A778
    if (ctx->r16 != 0) {
        // 0x8001A708: nop
    
            goto L_8001A778;
    }
    // 0x8001A708: nop

    // 0x8001A70C: jal         0x8009F1C4
    // 0x8001A710: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_28;
    // 0x8001A710: nop

    after_28:
    // 0x8001A714: beq         $v0, $zero, L_8001A764
    if (ctx->r2 == 0) {
        // 0x8001A718: nop
    
            goto L_8001A764;
    }
    // 0x8001A718: nop

    // 0x8001A71C: lb          $t7, 0x0($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X0);
    // 0x8001A720: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8001A724: beq         $t7, $zero, L_8001A750
    if (ctx->r15 == 0) {
        // 0x8001A728: nop
    
            goto L_8001A750;
    }
    // 0x8001A728: nop

    // 0x8001A72C: jal         0x8006F5D8
    // 0x8001A730: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    swap_lead_player(rdram, ctx);
        goto after_29;
    // 0x8001A730: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    after_29:
    // 0x8001A734: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001A738: lb          $t6, -0x3354($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X3354);
    // 0x8001A73C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001A740: beq         $t6, $zero, L_8001A764
    if (ctx->r14 == 0) {
        // 0x8001A744: nop
    
            goto L_8001A764;
    }
    // 0x8001A744: nop

    // 0x8001A748: b           L_8001A764
    // 0x8001A74C: sb          $s4, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = ctx->r20;
        goto L_8001A764;
    // 0x8001A74C: sb          $s4, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = ctx->r20;
L_8001A750:
    // 0x8001A750: lb          $t9, -0x3354($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X3354);
    // 0x8001A754: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001A758: beq         $t9, $zero, L_8001A764
    if (ctx->r25 == 0) {
        // 0x8001A75C: nop
    
            goto L_8001A764;
    }
    // 0x8001A75C: nop

    // 0x8001A760: sb          $s4, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = ctx->r20;
L_8001A764:
    // 0x8001A764: lb          $a0, 0x0($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X0);
    // 0x8001A768: jal         0x80094B8C
    // 0x8001A76C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    postrace_start(rdram, ctx);
        goto after_30;
    // 0x8001A76C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_30:
    // 0x8001A770: b           L_8001A7C8
    // 0x8001A774: nop

        goto L_8001A7C8;
    // 0x8001A774: nop

L_8001A778:
    // 0x8001A778: lbu         $t7, 0x48($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X48);
    // 0x8001A77C: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x8001A780: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8001A784: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x8001A788: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8001A78C: nop

    // 0x8001A790: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8001A794: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8001A798: lbu         $t8, 0x48($s6)
    ctx->r24 = MEM_BU(ctx->r22, 0X48);
    // 0x8001A79C: nop

    // 0x8001A7A0: beq         $t8, $zero, L_8001A7C0
    if (ctx->r24 == 0) {
        // 0x8001A7A4: nop
    
            goto L_8001A7C0;
    }
    // 0x8001A7A4: nop

    // 0x8001A7A8: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8001A7AC: nop

    // 0x8001A7B0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8001A7B4: nop

    // 0x8001A7B8: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8001A7BC: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
L_8001A7C0:
    // 0x8001A7C0: jal         0x8001A908
    // 0x8001A7C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    race_finish_adventure(rdram, ctx);
        goto after_31;
    // 0x8001A7C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_31:
L_8001A7C8:
    // 0x8001A7C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001A7CC: jal         0x8009C90C
    // 0x8001A7D0: sw          $s5, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r21;
    get_number_of_active_players(rdram, ctx);
        goto after_32;
    // 0x8001A7D0: sw          $s5, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r21;
    after_32:
    // 0x8001A7D4: bne         $v0, $s4, L_8001A7E8
    if (ctx->r2 != ctx->r20) {
        // 0x8001A7D8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001A7E8;
    }
    // 0x8001A7D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001A7DC: jal         0x8001AE98
    // 0x8001A7E0: nop

    race_finish_time_trial(rdram, ctx);
        goto after_33;
    // 0x8001A7E0: nop

    after_33:
L_8001A7E4:
    // 0x8001A7E4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001A7E8:
    // 0x8001A7E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A7EC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A7F0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001A7F4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001A7F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7FC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A800: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001A804: jr          $ra
    // 0x8001A808: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8001A808: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void set_course_finish_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A80C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001A810: lw          $t6, -0x4B98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B98);
    // 0x8001A814: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A818: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001A81C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001A820: lw          $v0, 0x64($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X64);
    // 0x8001A824: addiu       $v1, $v1, -0x4CBC
    ctx->r3 = ADD32(ctx->r3, -0X4CBC);
    // 0x8001A828: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8001A82C: nop

    // 0x8001A830: bne         $t8, $at, L_8001A840
    if (ctx->r24 != ctx->r1) {
        // 0x8001A834: nop
    
            goto L_8001A840;
    }
    // 0x8001A834: nop

    // 0x8001A838: jr          $ra
    // 0x8001A83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001A83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001A840:
    // 0x8001A840: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8001A844: lbu         $t0, 0x49($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X49);
    // 0x8001A848: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8001A84C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8001A850: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8001A854: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001A858: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001A85C: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x8001A860: bne         $t4, $zero, L_8001A8A0
    if (ctx->r12 != 0) {
        // 0x8001A864: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8001A8A0;
    }
    // 0x8001A864: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001A868: lbu         $t5, -0x4B8B($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4B8B);
    // 0x8001A86C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001A870: bne         $t5, $zero, L_8001A8F8
    if (ctx->r13 != 0) {
        // 0x8001A874: nop
    
            goto L_8001A8F8;
    }
    // 0x8001A874: nop

    // 0x8001A878: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8001A87C: lbu         $t8, 0x49($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X49);
    // 0x8001A880: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8001A884: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8001A888: addu        $v0, $t7, $t0
    ctx->r2 = ADD32(ctx->r15, ctx->r8);
    // 0x8001A88C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8001A890: nop

    // 0x8001A894: ori         $t1, $t9, 0x2
    ctx->r9 = ctx->r25 | 0X2;
    // 0x8001A898: b           L_8001A8F8
    // 0x8001A89C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_8001A8F8;
    // 0x8001A89C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_8001A8A0:
    // 0x8001A8A0: lb          $t2, -0x4C7D($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X4C7D);
    // 0x8001A8A4: nop

    // 0x8001A8A8: beq         $t2, $zero, L_8001A8F8
    if (ctx->r10 == 0) {
        // 0x8001A8AC: nop
    
            goto L_8001A8F8;
    }
    // 0x8001A8AC: nop

    // 0x8001A8B0: lb          $t3, 0x202($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X202);
    // 0x8001A8B4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001A8B8: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x8001A8BC: bne         $at, $zero, L_8001A8F8
    if (ctx->r1 != 0) {
        // 0x8001A8C0: nop
    
            goto L_8001A8F8;
    }
    // 0x8001A8C0: nop

    // 0x8001A8C4: lbu         $t4, -0x4B8B($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X4B8B);
    // 0x8001A8C8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001A8CC: bne         $t4, $zero, L_8001A8F8
    if (ctx->r12 != 0) {
        // 0x8001A8D0: nop
    
            goto L_8001A8F8;
    }
    // 0x8001A8D0: nop

    // 0x8001A8D4: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8001A8D8: lbu         $t8, 0x49($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X49);
    // 0x8001A8DC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8001A8E0: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001A8E4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8001A8E8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8001A8EC: nop

    // 0x8001A8F0: ori         $t9, $t0, 0x4
    ctx->r25 = ctx->r8 | 0X4;
    // 0x8001A8F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8001A8F8:
    // 0x8001A8F8: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8001A8FC: nop

    // 0x8001A900: jr          $ra
    // 0x8001A904: nop

    return;
    // 0x8001A904: nop

;}
RECOMP_FUNC void race_finish_adventure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A908: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x8001A90C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001A910: sh          $t6, -0x4D32($at)
    MEM_H(-0X4D32, ctx->r1) = ctx->r14;
    // 0x8001A914: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001A918: sb          $zero, -0x4D30($at)
    MEM_B(-0X4D30, ctx->r1) = 0;
    // 0x8001A91C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001A920: jr          $ra
    // 0x8001A924: sb          $a0, -0x4D2E($at)
    MEM_B(-0X4D2E, ctx->r1) = ctx->r4;
    return;
    // 0x8001A924: sb          $a0, -0x4D2E($at)
    MEM_B(-0X4D2E, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void race_transition_adventure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A928: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001A92C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A930: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8001A934: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001A938: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001A93C: jal         0x8006F5C8
    // 0x8001A940: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_pause_lockout_timer(rdram, ctx);
        goto after_0;
    // 0x8001A940: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8001A944: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001A948: addiu       $s0, $s0, -0x4D32
    ctx->r16 = ADD32(ctx->r16, -0X4D32);
    // 0x8001A94C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8001A950: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8001A954: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001A958: subu        $t7, $v1, $t6
    ctx->r15 = SUB32(ctx->r3, ctx->r14);
    // 0x8001A95C: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x8001A960: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8001A964: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x8001A968: bgtz        $t8, L_8001A974
    if (SIGNED(ctx->r24) > 0) {
        // 0x8001A96C: nop
    
            goto L_8001A974;
    }
    // 0x8001A96C: nop

    // 0x8001A970: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
L_8001A974:
    // 0x8001A974: bne         $at, $zero, L_8001A998
    if (ctx->r1 != 0) {
        // 0x8001A978: nop
    
            goto L_8001A998;
    }
    // 0x8001A978: nop

    // 0x8001A97C: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8001A980: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001A984: slti        $at, $t1, 0x33
    ctx->r1 = SIGNED(ctx->r9) < 0X33 ? 1 : 0;
    // 0x8001A988: beq         $at, $zero, L_8001A998
    if (ctx->r1 == 0) {
        // 0x8001A98C: nop
    
            goto L_8001A998;
    }
    // 0x8001A98C: nop

    // 0x8001A990: jal         0x800C06F8
    // 0x8001A994: addiu       $a0, $a0, -0x3238
    ctx->r4 = ADD32(ctx->r4, -0X3238);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8001A994: addiu       $a0, $a0, -0x3238
    ctx->r4 = ADD32(ctx->r4, -0X3238);
    after_1:
L_8001A998:
    // 0x8001A998: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001A99C: lb          $v0, -0x4D30($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D30);
    // 0x8001A9A0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8001A9A4: bne         $v0, $zero, L_8001AB6C
    if (ctx->r2 != 0) {
        // 0x8001A9A8: nop
    
            goto L_8001AB6C;
    }
    // 0x8001A9A8: nop

    // 0x8001A9AC: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x8001A9B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A9B4: bne         $t2, $at, L_8001AB6C
    if (ctx->r10 != ctx->r1) {
        // 0x8001A9B8: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_8001AB6C;
    }
    // 0x8001A9B8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001A9BC: addiu       $s1, $s1, -0x4B90
    ctx->r17 = ADD32(ctx->r17, -0X4B90);
    // 0x8001A9C0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8001A9C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A9C8: blez        $t3, L_8001AA70
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8001A9CC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001AA70;
    }
    // 0x8001A9CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001A9D0:
    // 0x8001A9D0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001A9D4: lw          $t4, -0x4B9C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4B9C);
    // 0x8001A9D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A9DC: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8001A9E0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001A9E4: nop

    // 0x8001A9E8: lw          $a1, 0x64($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X64);
    // 0x8001A9EC: nop

    // 0x8001A9F0: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8001A9F4: sw          $zero, 0x140($a1)
    MEM_W(0X140, ctx->r5) = 0;
    // 0x8001A9F8: beq         $t7, $at, L_8001AA14
    if (ctx->r15 == ctx->r1) {
        // 0x8001A9FC: nop
    
            goto L_8001AA14;
    }
    // 0x8001A9FC: nop

    // 0x8001AA00: lh          $t8, 0x1AC($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X1AC);
    // 0x8001AA04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001AA08: bne         $t8, $at, L_8001AA14
    if (ctx->r24 != ctx->r1) {
        // 0x8001AA0C: nop
    
            goto L_8001AA14;
    }
    // 0x8001AA0C: nop

    // 0x8001AA10: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
L_8001AA14:
    // 0x8001AA14: lw          $a0, 0x178($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X178);
    // 0x8001AA18: nop

    // 0x8001AA1C: beq         $a0, $zero, L_8001AA3C
    if (ctx->r4 == 0) {
        // 0x8001AA20: nop
    
            goto L_8001AA3C;
    }
    // 0x8001AA20: nop

    // 0x8001AA24: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8001AA28: jal         0x8000488C
    // 0x8001AA2C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x8001AA2C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_2:
    // 0x8001AA30: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001AA34: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8001AA38: nop

L_8001AA3C:
    // 0x8001AA3C: lw          $a0, 0x17C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X17C);
    // 0x8001AA40: nop

    // 0x8001AA44: beq         $a0, $zero, L_8001AA5C
    if (ctx->r4 == 0) {
        // 0x8001AA48: nop
    
            goto L_8001AA5C;
    }
    // 0x8001AA48: nop

    // 0x8001AA4C: jal         0x800096F8
    // 0x8001AA50: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    audspat_point_stop(rdram, ctx);
        goto after_3;
    // 0x8001AA50: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x8001AA54: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001AA58: nop

L_8001AA5C:
    // 0x8001AA5C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8001AA60: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001AA64: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001AA68: bne         $at, $zero, L_8001A9D0
    if (ctx->r1 != 0) {
        // 0x8001AA6C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8001A9D0;
    }
    // 0x8001AA6C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8001AA70:
    // 0x8001AA70: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8001AA74: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AA78: lw          $v0, -0x4B9C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B9C);
    // 0x8001AA7C: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8001AA80: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8001AA84: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001AA88: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8001AA8C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001AA90: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8001AA94: lw          $t4, -0x4B9C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4B9C);
    // 0x8001AA98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001AA9C: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x8001AAA0: sw          $a2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r6;
    // 0x8001AAA4: lw          $t6, -0x4B9C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B9C);
    // 0x8001AAA8: nop

    // 0x8001AAAC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8001AAB0: jal         0x80006AC8
    // 0x8001AAB4: nop

    racer_sound_free(rdram, ctx);
        goto after_4;
    // 0x8001AAB4: nop

    after_4:
    // 0x8001AAB8: jal         0x800A10B4
    // 0x8001AABC: nop

    hud_audio_init(rdram, ctx);
        goto after_5;
    // 0x8001AABC: nop

    after_5:
    // 0x8001AAC0: jal         0x8003F110
    // 0x8001AAC4: nop

    reset_rocket_sound_timer(rdram, ctx);
        goto after_6;
    // 0x8001AAC4: nop

    after_6:
    // 0x8001AAC8: jal         0x800049D8
    // 0x8001AACC: nop

    sndp_stop_all_looped(rdram, ctx);
        goto after_7;
    // 0x8001AACC: nop

    after_7:
    // 0x8001AAD0: jal         0x8009F1C4
    // 0x8001AAD4: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_8;
    // 0x8001AAD4: nop

    after_8:
    // 0x8001AAD8: beq         $v0, $zero, L_8001AB4C
    if (ctx->r2 == 0) {
        // 0x8001AADC: nop
    
            goto L_8001AB4C;
    }
    // 0x8001AADC: nop

    // 0x8001AAE0: jal         0x80024A20
    // 0x8001AAE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_scene_viewport_num(rdram, ctx);
        goto after_9;
    // 0x8001AAE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8001AAE8: jal         0x8006676C
    // 0x8001AAEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_layout(rdram, ctx);
        goto after_10;
    // 0x8001AAEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8001AAF0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001AAF4: lw          $t7, -0x4B9C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4B9C);
    // 0x8001AAF8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001AAFC: addiu       $a3, $a3, -0x4B94
    ctx->r7 = ADD32(ctx->r7, -0X4B94);
    // 0x8001AB00: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8001AB04: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x8001AB08: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8001AB0C: lw          $a1, 0x64($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X64);
    // 0x8001AB10: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8001AB14: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8001AB18: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8001AB1C: addiu       $t0, $t0, -0x334C
    ctx->r8 = ADD32(ctx->r8, -0X334C);
    // 0x8001AB20: sw          $a2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r6;
    // 0x8001AB24: lb          $t9, 0x0($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X0);
    // 0x8001AB28: nop

    // 0x8001AB2C: beq         $t9, $zero, L_8001AB4C
    if (ctx->r25 == 0) {
        // 0x8001AB30: nop
    
            goto L_8001AB4C;
    }
    // 0x8001AB30: nop

    // 0x8001AB34: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8001AB38: jal         0x8006F5D8
    // 0x8001AB3C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    swap_lead_player(rdram, ctx);
        goto after_11;
    // 0x8001AB3C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_11:
    // 0x8001AB40: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8001AB44: nop

    // 0x8001AB48: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_8001AB4C:
    // 0x8001AB4C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8001AB50: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001AB54: addiu       $a3, $a3, -0x4D2F
    ctx->r7 = ADD32(ctx->r7, -0X4D2F);
    // 0x8001AB58: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001AB5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001AB60: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
    // 0x8001AB64: sb          $t2, -0x4D30($at)
    MEM_B(-0X4D30, ctx->r1) = ctx->r10;
    // 0x8001AB68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001AB6C:
    // 0x8001AB6C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001AB70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001AB74: bne         $v0, $at, L_8001ACCC
    if (ctx->r2 != ctx->r1) {
        // 0x8001AB78: addiu       $s1, $s1, -0x4B90
        ctx->r17 = ADD32(ctx->r17, -0X4B90);
            goto L_8001ACCC;
    }
    // 0x8001AB78: addiu       $s1, $s1, -0x4B90
    ctx->r17 = ADD32(ctx->r17, -0X4B90);
    // 0x8001AB7C: jal         0x800AB730
    // 0x8001AB80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    hud_visibility(rdram, ctx);
        goto after_12;
    // 0x8001AB80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x8001AB84: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001AB88: addiu       $a3, $a3, -0x4D2F
    ctx->r7 = ADD32(ctx->r7, -0X4D2F);
    // 0x8001AB8C: lb          $t3, 0x0($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X0);
    // 0x8001AB90: nop

    // 0x8001AB94: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8001AB98: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
    // 0x8001AB9C: lb          $a2, 0x0($a3)
    ctx->r6 = MEM_B(ctx->r7, 0X0);
    // 0x8001ABA0: nop

    // 0x8001ABA4: blez        $a2, L_8001ACC0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001ABA8: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8001ACC0;
    }
    // 0x8001ABA8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001ABAC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8001ABB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001ABB4: blez        $a0, L_8001AC0C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001ABB8: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8001AC0C;
    }
    // 0x8001ABB8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001ABBC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001ABC0: lw          $t5, -0x4B9C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4B9C);
    // 0x8001ABC4: addiu       $a1, $a1, -0x4B98
    ctx->r5 = ADD32(ctx->r5, -0X4B98);
    // 0x8001ABC8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8001ABCC: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8001ABD0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8001ABD4: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x8001ABD8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8001ABDC: nop

    // 0x8001ABE0: beq         $t8, $v1, L_8001AC0C
    if (ctx->r24 == ctx->r3) {
        // 0x8001ABE4: nop
    
            goto L_8001AC0C;
    }
    // 0x8001ABE4: nop

L_8001ABE8:
    // 0x8001ABE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001ABEC: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001ABF0: beq         $at, $zero, L_8001AC0C
    if (ctx->r1 == 0) {
        // 0x8001ABF4: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_8001AC0C;
    }
    // 0x8001ABF4: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8001ABF8: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x8001ABFC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001AC00: nop

    // 0x8001AC04: bne         $t2, $v1, L_8001ABE8
    if (ctx->r10 != ctx->r3) {
        // 0x8001AC08: nop
    
            goto L_8001ABE8;
    }
    // 0x8001AC08: nop

L_8001AC0C:
    // 0x8001AC0C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001AC10: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001AC14: beq         $at, $zero, L_8001AC64
    if (ctx->r1 == 0) {
        // 0x8001AC18: addiu       $a1, $a1, -0x4B98
        ctx->r5 = ADD32(ctx->r5, -0X4B98);
            goto L_8001AC64;
    }
    // 0x8001AC18: addiu       $a1, $a1, -0x4B98
    ctx->r5 = ADD32(ctx->r5, -0X4B98);
    // 0x8001AC1C: addiu       $t3, $a0, -0x1
    ctx->r11 = ADD32(ctx->r4, -0X1);
    // 0x8001AC20: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001AC24: beq         $at, $zero, L_8001AC64
    if (ctx->r1 == 0) {
        // 0x8001AC28: sll         $v1, $s0, 2
        ctx->r3 = S32(ctx->r16 << 2);
            goto L_8001AC64;
    }
    // 0x8001AC28: sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16 << 2);
L_8001AC2C:
    // 0x8001AC2C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8001AC30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001AC34: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x8001AC38: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8001AC3C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001AC40: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8001AC44: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001AC48: nop

    // 0x8001AC4C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001AC50: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001AC54: bne         $at, $zero, L_8001AC2C
    if (ctx->r1 != 0) {
        // 0x8001AC58: nop
    
            goto L_8001AC2C;
    }
    // 0x8001AC58: nop

    // 0x8001AC5C: lb          $a2, 0x0($a3)
    ctx->r6 = MEM_B(ctx->r7, 0X0);
    // 0x8001AC60: nop

L_8001AC64:
    // 0x8001AC64: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001AC68: lw          $t8, -0x4B9C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4B9C);
    // 0x8001AC6C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8001AC70: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8001AC74: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8001AC78: jal         0x8000FFB8
    // 0x8001AC7C: nop

    free_object(rdram, ctx);
        goto after_13;
    // 0x8001AC7C: nop

    after_13:
    // 0x8001AC80: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001AC84: addiu       $a3, $a3, -0x4D2F
    ctx->r7 = ADD32(ctx->r7, -0X4D2F);
    // 0x8001AC88: lb          $t3, 0x0($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X0);
    // 0x8001AC8C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001AC90: lw          $t2, -0x4B9C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4B9C);
    // 0x8001AC94: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001AC98: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8001AC9C: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x8001ACA0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001ACA4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001ACA8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001ACAC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8001ACB0: lb          $v0, -0x4D30($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D30);
    // 0x8001ACB4: b           L_8001ACD0
    // 0x8001ACB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_8001ACD0;
    // 0x8001ACB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001ACBC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
L_8001ACC0:
    // 0x8001ACC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001ACC4: sb          $t8, -0x4D30($at)
    MEM_B(-0X4D30, ctx->r1) = ctx->r24;
    // 0x8001ACC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8001ACCC:
    // 0x8001ACCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8001ACD0:
    // 0x8001ACD0: bne         $v0, $at, L_8001AD2C
    if (ctx->r2 != ctx->r1) {
        // 0x8001ACD4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8001AD2C;
    }
    // 0x8001ACD4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8001ACD8: lw          $t9, -0x4B9C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4B9C);
    // 0x8001ACDC: nop

    // 0x8001ACE0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8001ACE4: nop

    // 0x8001ACE8: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8001ACEC: jal         0x80023104
    // 0x8001ACF0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_800230D0(rdram, ctx);
        goto after_14;
    // 0x8001ACF0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_14:
    // 0x8001ACF4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8001ACF8: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8001ACFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001AD00: sb          $zero, 0x1D8($a1)
    MEM_B(0X1D8, ctx->r5) = 0;
    // 0x8001AD04: sb          $t1, -0x4D30($at)
    MEM_B(-0X4D30, ctx->r1) = ctx->r9;
    // 0x8001AD08: jal         0x8001E490
    // 0x8001AD0C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8001E45C(rdram, ctx);
        goto after_15;
    // 0x8001AD0C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_15:
    // 0x8001AD10: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001AD14: addiu       $s0, $s0, -0x4CB8
    ctx->r16 = ADD32(ctx->r16, -0X4CB8);
    // 0x8001AD18: jal         0x8001E970
    // 0x8001AD1C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    func_8001E93C(rdram, ctx);
        goto after_16;
    // 0x8001AD1C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    after_16:
    // 0x8001AD20: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AD24: lb          $v0, -0x4D30($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D30);
    // 0x8001AD28: nop

L_8001AD2C:
    // 0x8001AD2C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001AD30: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001AD34: bne         $v0, $at, L_8001AD68
    if (ctx->r2 != ctx->r1) {
        // 0x8001AD38: addiu       $s0, $s0, -0x4CB8
        ctx->r16 = ADD32(ctx->r16, -0X4CB8);
            goto L_8001AD68;
    }
    // 0x8001AD38: addiu       $s0, $s0, -0x4CB8
    ctx->r16 = ADD32(ctx->r16, -0X4CB8);
    // 0x8001AD3C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001AD40: jal         0x800C06F8
    // 0x8001AD44: addiu       $a0, $a0, -0x3230
    ctx->r4 = ADD32(ctx->r4, -0X3230);
    transition_begin(rdram, ctx);
        goto after_17;
    // 0x8001AD44: addiu       $a0, $a0, -0x3230
    ctx->r4 = ADD32(ctx->r4, -0X3230);
    after_17:
    // 0x8001AD48: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8001AD4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001AD50: sb          $t3, -0x4D30($at)
    MEM_B(-0X4D30, ctx->r1) = ctx->r11;
    // 0x8001AD54: jal         0x80028FE0
    // 0x8001AD58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_anti_aliasing(rdram, ctx);
        goto after_18;
    // 0x8001AD58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_18:
    // 0x8001AD5C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AD60: lb          $v0, -0x4D30($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D30);
    // 0x8001AD64: nop

L_8001AD68:
    // 0x8001AD68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001AD6C: bne         $v0, $at, L_8001AE68
    if (ctx->r2 != ctx->r1) {
        // 0x8001AD70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001AE68;
    }
    // 0x8001AD70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AD74: jal         0x80028FE0
    // 0x8001AD78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_anti_aliasing(rdram, ctx);
        goto after_19;
    // 0x8001AD78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x8001AD7C: jal         0x8005A41C
    // 0x8001AD80: nop

    disable_racer_input(rdram, ctx);
        goto after_20;
    // 0x8001AD80: nop

    after_20:
    // 0x8001AD84: jal         0x8006BFD8
    // 0x8001AD88: nop

    level_type(rdram, ctx);
        goto after_21;
    // 0x8001AD88: nop

    after_21:
    // 0x8001AD8C: andi        $t2, $v0, 0x40
    ctx->r10 = ctx->r2 & 0X40;
    // 0x8001AD90: bne         $t2, $zero, L_8001ADE0
    if (ctx->r10 != 0) {
        // 0x8001AD94: lui         $t4, 0x8000
        ctx->r12 = S32(0X8000 << 16);
            goto L_8001ADE0;
    }
    // 0x8001AD94: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8001AD98: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x8001AD9C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8001ADA0: bne         $t4, $zero, L_8001ADB0
    if (ctx->r12 != 0) {
        // 0x8001ADA4: addiu       $v0, $zero, 0x21C
        ctx->r2 = ADD32(0, 0X21C);
            goto L_8001ADB0;
    }
    // 0x8001ADA4: addiu       $v0, $zero, 0x21C
    ctx->r2 = ADD32(0, 0X21C);
    // 0x8001ADA8: b           L_8001ADB0
    // 0x8001ADAC: addiu       $v0, $zero, 0x19F
    ctx->r2 = ADD32(0, 0X19F);
        goto L_8001ADB0;
    // 0x8001ADAC: addiu       $v0, $zero, 0x19F
    ctx->r2 = ADD32(0, 0X19F);
L_8001ADB0:
    // 0x8001ADB0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8001ADB4: nop

    // 0x8001ADB8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8001ADBC: sltu        $at, $t7, $v0
    ctx->r1 = ctx->r15 < ctx->r2 ? 1 : 0;
    // 0x8001ADC0: beq         $at, $zero, L_8001ADD8
    if (ctx->r1 == 0) {
        // 0x8001ADC4: sw          $t7, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r15;
            goto L_8001ADD8;
    }
    // 0x8001ADC4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8001ADC8: jal         0x800AB6F0
    // 0x8001ADCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    minimap_fade(rdram, ctx);
        goto after_22;
    // 0x8001ADCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_22:
    // 0x8001ADD0: b           L_8001ADE0
    // 0x8001ADD4: nop

        goto L_8001ADE0;
    // 0x8001ADD4: nop

L_8001ADD8:
    // 0x8001ADD8: jal         0x800AB730
    // 0x8001ADDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    hud_visibility(rdram, ctx);
        goto after_23;
    // 0x8001ADDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_23:
L_8001ADE0:
    // 0x8001ADE0: jal         0x8006A794
    // 0x8001ADE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_24;
    // 0x8001ADE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
    // 0x8001ADE8: jal         0x8006ECD0
    // 0x8001ADEC: andi        $s0, $v0, 0x8000
    ctx->r16 = ctx->r2 & 0X8000;
    get_settings(rdram, ctx);
        goto after_25;
    // 0x8001ADEC: andi        $s0, $v0, 0x8000
    ctx->r16 = ctx->r2 & 0X8000;
    after_25:
    // 0x8001ADF0: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x8001ADF4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8001ADF8: sll         $t1, $t9, 13
    ctx->r9 = S32(ctx->r25 << 13);
    // 0x8001ADFC: bltz        $t1, L_8001AE08
    if (SIGNED(ctx->r9) < 0) {
        // 0x8001AE00: nop
    
            goto L_8001AE08;
    }
    // 0x8001AE00: nop

    // 0x8001AE04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001AE08:
    // 0x8001AE08: jal         0x800214F8
    // 0x8001AE0C: nop

    func_800214C4(rdram, ctx);
        goto after_26;
    // 0x8001AE0C: nop

    after_26:
    // 0x8001AE10: bne         $v0, $zero, L_8001AE30
    if (ctx->r2 != 0) {
        // 0x8001AE14: nop
    
            goto L_8001AE30;
    }
    // 0x8001AE14: nop

    // 0x8001AE18: beq         $s0, $zero, L_8001AE68
    if (ctx->r16 == 0) {
        // 0x8001AE1C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001AE68;
    }
    // 0x8001AE1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AE20: jal         0x800C06AC
    // 0x8001AE24: nop

    check_fadeout_transition(rdram, ctx);
        goto after_27;
    // 0x8001AE24: nop

    after_27:
    // 0x8001AE28: bne         $v0, $zero, L_8001AE68
    if (ctx->r2 != 0) {
        // 0x8001AE2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001AE68;
    }
    // 0x8001AE2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001AE30:
    // 0x8001AE30: beq         $s0, $zero, L_8001AE40
    if (ctx->r16 == 0) {
        // 0x8001AE34: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8001AE40;
    }
    // 0x8001AE34: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001AE38: jal         0x800C06F8
    // 0x8001AE3C: addiu       $a0, $a0, -0x3398
    ctx->r4 = ADD32(ctx->r4, -0X3398);
    transition_begin(rdram, ctx);
        goto after_28;
    // 0x8001AE3C: addiu       $a0, $a0, -0x3398
    ctx->r4 = ADD32(ctx->r4, -0X3398);
    after_28:
L_8001AE40:
    // 0x8001AE40: jal         0x8006F380
    // 0x8001AE44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    level_transition_begin(rdram, ctx);
        goto after_29;
    // 0x8001AE44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_29:
    // 0x8001AE48: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001AE4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001AE50: sb          $t3, -0x4D30($at)
    MEM_B(-0X4D30, ctx->r1) = ctx->r11;
    // 0x8001AE54: lw          $t2, 0x10($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X10);
    // 0x8001AE58: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8001AE5C: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x8001AE60: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
    // 0x8001AE64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001AE68:
    // 0x8001AE68: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001AE6C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001AE70: jr          $ra
    // 0x8001AE74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001AE74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void race_finish_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE78: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AE7C: lh          $v0, -0x4D32($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4D32);
    // 0x8001AE80: jr          $ra
    // 0x8001AE84: nop

    return;
    // 0x8001AE84: nop

;}
RECOMP_FUNC void get_balloon_cutscene_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE88: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AE8C: lw          $v0, -0x4CB8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CB8);
    // 0x8001AE90: jr          $ra
    // 0x8001AE94: nop

    return;
    // 0x8001AE94: nop

;}
RECOMP_FUNC void race_finish_time_trial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE98: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001AE9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001AEA0: jal         0x8006BFF0
    // 0x8001AEA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    level_header(rdram, ctx);
        goto after_0;
    // 0x8001AEA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8001AEA8: jal         0x8006ECD0
    // 0x8001AEAC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_1;
    // 0x8001AEAC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001AEB0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8001AEB4: sb          $zero, 0x114($v0)
    MEM_B(0X114, ctx->r2) = 0;
    // 0x8001AEB8: sb          $zero, 0x116($v0)
    MEM_B(0X116, ctx->r2) = 0;
    // 0x8001AEBC: sb          $zero, 0x115($v0)
    MEM_B(0X115, ctx->r2) = 0;
    // 0x8001AEC0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001AEC4: lw          $t6, -0x4B98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B98);
    // 0x8001AEC8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8001AECC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001AED0: lw          $t9, -0x4B90($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4B90);
    // 0x8001AED4: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x8001AED8: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8001AEDC: ori         $s0, $zero, 0x8CA1
    ctx->r16 = 0 | 0X8CA1;
    // 0x8001AEE0: ori         $t1, $zero, 0x8CA1
    ctx->r9 = 0 | 0X8CA1;
    // 0x8001AEE4: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001AEE8: blez        $t9, L_8001B054
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001AEEC: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_8001B054;
    }
    // 0x8001AEEC: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8001AEF0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8001AEF4:
    // 0x8001AEF4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001AEF8: lw          $t6, -0x4B98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B98);
    // 0x8001AEFC: nop

    // 0x8001AF00: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x8001AF04: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001AF08: nop

    // 0x8001AF0C: lw          $a3, 0x64($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X64);
    // 0x8001AF10: nop

    // 0x8001AF14: lb          $t9, 0x2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X2);
    // 0x8001AF18: nop

    // 0x8001AF1C: bltz        $t9, L_8001B03C
    if (SIGNED(ctx->r25) < 0) {
        // 0x8001AF20: nop
    
            goto L_8001B03C;
    }
    // 0x8001AF20: nop

    // 0x8001AF24: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8001AF28: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8001AF2C: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x8001AF30: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8001AF34: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8001AF38: jal         0x8009C90C
    // 0x8001AF3C: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    get_number_of_active_players(rdram, ctx);
        goto after_2;
    // 0x8001AF3C: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    after_2:
    // 0x8001AF40: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8001AF44: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8001AF48: lb          $v1, 0x2($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X2);
    // 0x8001AF4C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8001AF50: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8001AF54: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8001AF58: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8001AF5C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001AF60: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001AF64: beq         $at, $zero, L_8001B03C
    if (ctx->r1 == 0) {
        // 0x8001AF68: addiu       $ra, $zero, 0x18
        ctx->r31 = ADD32(0, 0X18);
            goto L_8001B03C;
    }
    // 0x8001AF68: addiu       $ra, $zero, 0x18
    ctx->r31 = ADD32(0, 0X18);
    // 0x8001AF6C: multu       $v1, $ra
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AF70: mflo        $t6
    ctx->r14 = lo;
    // 0x8001AF74: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8001AF78: sb          $zero, 0x58($t7)
    MEM_B(0X58, ctx->r15) = 0;
    // 0x8001AF7C: lb          $v0, 0x1D7($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X1D7);
    // 0x8001AF80: nop

    // 0x8001AF84: bltz        $v0, L_8001B03C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001AF88: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_8001B03C;
    }
    // 0x8001AF88: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001AF8C: beq         $at, $zero, L_8001B03C
    if (ctx->r1 == 0) {
        // 0x8001AF90: nop
    
            goto L_8001B03C;
    }
    // 0x8001AF90: nop

    // 0x8001AF94: lb          $t8, 0x4B($t2)
    ctx->r24 = MEM_B(ctx->r10, 0X4B);
    // 0x8001AF98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001AF9C: blez        $t8, L_8001B010
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001AFA0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001B010;
    }
    // 0x8001AFA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001AFA4: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8001AFA8: addu        $v0, $a3, $t9
    ctx->r2 = ADD32(ctx->r7, ctx->r25);
    // 0x8001AFAC: sll         $a1, $a0, 1
    ctx->r5 = S32(ctx->r4 << 1);
L_8001AFB0:
    // 0x8001AFB0: lb          $t7, 0x2($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X2);
    // 0x8001AFB4: lw          $t6, 0x128($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X128);
    // 0x8001AFB8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001AFBC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8001AFC0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8001AFC4: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8001AFC8: addu        $t7, $t9, $a1
    ctx->r15 = ADD32(ctx->r25, ctx->r5);
    // 0x8001AFCC: sh          $t6, 0x66($t7)
    MEM_H(0X66, ctx->r15) = ctx->r14;
    // 0x8001AFD0: lw          $v1, 0x128($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X128);
    // 0x8001AFD4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8001AFD8: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001AFDC: beq         $at, $zero, L_8001AFF4
    if (ctx->r1 == 0) {
        // 0x8001AFE0: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_8001AFF4;
    }
    // 0x8001AFE0: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8001AFE4: sb          $a0, 0x116($t0)
    MEM_B(0X116, ctx->r8) = ctx->r4;
    // 0x8001AFE8: lb          $t8, 0x2($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X2);
    // 0x8001AFEC: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8001AFF0: sb          $t8, 0x115($t0)
    MEM_B(0X115, ctx->r8) = ctx->r24;
L_8001AFF4:
    // 0x8001AFF4: lb          $t9, 0x4B($t2)
    ctx->r25 = MEM_B(ctx->r10, 0X4B);
    // 0x8001AFF8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001AFFC: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001B000: beq         $at, $zero, L_8001B010
    if (ctx->r1 == 0) {
        // 0x8001B004: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8001B010;
    }
    // 0x8001B004: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001B008: bne         $a0, $t3, L_8001AFB0
    if (ctx->r4 != ctx->r11) {
        // 0x8001B00C: nop
    
            goto L_8001AFB0;
    }
    // 0x8001B00C: nop

L_8001B010:
    // 0x8001B010: lb          $t6, 0x2($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X2);
    // 0x8001B014: slt         $at, $a2, $s0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8001B018: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B01C: mflo        $t7
    ctx->r15 = lo;
    // 0x8001B020: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8001B024: beq         $at, $zero, L_8001B03C
    if (ctx->r1 == 0) {
        // 0x8001B028: sh          $a2, 0x64($t8)
        MEM_H(0X64, ctx->r24) = ctx->r6;
            goto L_8001B03C;
    }
    // 0x8001B028: sh          $a2, 0x64($t8)
    MEM_H(0X64, ctx->r24) = ctx->r6;
    // 0x8001B02C: lb          $t9, 0x2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X2);
    // 0x8001B030: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8001B034: sb          $t9, 0x114($t0)
    MEM_B(0X114, ctx->r8) = ctx->r25;
    // 0x8001B038: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
L_8001B03C:
    // 0x8001B03C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B040: lw          $t6, -0x4B90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B90);
    // 0x8001B044: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001B048: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001B04C: bne         $at, $zero, L_8001AEF4
    if (ctx->r1 != 0) {
        // 0x8001B050: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_8001AEF4;
    }
    // 0x8001B050: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
L_8001B054:
    // 0x8001B054: sb          $zero, 0x117($t0)
    MEM_B(0X117, ctx->r8) = 0;
    // 0x8001B058: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001B05C: lbu         $t7, -0x4B8B($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4B8B);
    // 0x8001B060: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001B064: beq         $t7, $zero, L_8001B2AC
    if (ctx->r15 == 0) {
        // 0x8001B068: addiu       $ra, $zero, 0x18
        ctx->r31 = ADD32(0, 0X18);
            goto L_8001B2AC;
    }
    // 0x8001B068: addiu       $ra, $zero, 0x18
    ctx->r31 = ADD32(0, 0X18);
    // 0x8001B06C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B070: lh          $v0, -0x4BFE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4BFE);
    // 0x8001B074: nop

    // 0x8001B078: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001B07C: beq         $at, $zero, L_8001B08C
    if (ctx->r1 == 0) {
        // 0x8001B080: nop
    
            goto L_8001B08C;
    }
    // 0x8001B080: nop

    // 0x8001B084: bgez        $v0, L_8001B090
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001B088: nop
    
            goto L_8001B090;
    }
    // 0x8001B088: nop

L_8001B08C:
    // 0x8001B08C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B090:
    // 0x8001B090: lb          $t9, 0x115($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X115);
    // 0x8001B094: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001B098: bne         $t9, $zero, L_8001B0FC
    if (ctx->r25 != 0) {
        // 0x8001B09C: sb          $t8, 0x117($t0)
        MEM_B(0X117, ctx->r8) = ctx->r24;
            goto L_8001B0FC;
    }
    // 0x8001B09C: sb          $t8, 0x117($t0)
    MEM_B(0X117, ctx->r8) = ctx->r24;
    // 0x8001B0A0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001B0A4: lbu         $t9, 0x49($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X49);
    // 0x8001B0A8: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8001B0AC: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x8001B0B0: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8001B0B4: addu        $a0, $t8, $t6
    ctx->r4 = ADD32(ctx->r24, ctx->r14);
    // 0x8001B0B8: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8001B0BC: nop

    // 0x8001B0C0: beq         $v1, $zero, L_8001B0D0
    if (ctx->r3 == 0) {
        // 0x8001B0C4: slt         $at, $t1, $v1
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001B0D0;
    }
    // 0x8001B0C4: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001B0C8: beq         $at, $zero, L_8001B0FC
    if (ctx->r1 == 0) {
        // 0x8001B0CC: nop
    
            goto L_8001B0FC;
    }
    // 0x8001B0CC: nop

L_8001B0D0:
    // 0x8001B0D0: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x8001B0D4: lb          $t7, 0x115($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X115);
    // 0x8001B0D8: lb          $t6, 0x116($t0)
    ctx->r14 = MEM_B(ctx->r8, 0X116);
    // 0x8001B0DC: multu       $t7, $ra
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B0E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001B0E4: mflo        $t9
    ctx->r25 = lo;
    // 0x8001B0E8: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x8001B0EC: lb          $t8, 0x58($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X58);
    // 0x8001B0F0: sllv        $t9, $t7, $t6
    ctx->r25 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8001B0F4: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8001B0F8: sb          $t7, 0x58($v1)
    MEM_B(0X58, ctx->r3) = ctx->r15;
L_8001B0FC:
    // 0x8001B0FC: lb          $a1, 0x114($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X114);
    // 0x8001B100: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001B104: bne         $a1, $zero, L_8001B168
    if (ctx->r5 != 0) {
        // 0x8001B108: nop
    
            goto L_8001B168;
    }
    // 0x8001B108: nop

    // 0x8001B10C: lbu         $t7, 0x49($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X49);
    // 0x8001B110: addu        $t8, $t0, $t6
    ctx->r24 = ADD32(ctx->r8, ctx->r14);
    // 0x8001B114: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x8001B118: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8001B11C: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x8001B120: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8001B124: nop

    // 0x8001B128: beq         $v1, $zero, L_8001B138
    if (ctx->r3 == 0) {
        // 0x8001B12C: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001B138;
    }
    // 0x8001B12C: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001B130: beq         $at, $zero, L_8001B168
    if (ctx->r1 == 0) {
        // 0x8001B134: nop
    
            goto L_8001B168;
    }
    // 0x8001B134: nop

L_8001B138:
    // 0x8001B138: sh          $s0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r16;
    // 0x8001B13C: lb          $t8, 0x114($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X114);
    // 0x8001B140: nop

    // 0x8001B144: multu       $t8, $ra
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B148: mflo        $t7
    ctx->r15 = lo;
    // 0x8001B14C: addu        $v1, $t0, $t7
    ctx->r3 = ADD32(ctx->r8, ctx->r15);
    // 0x8001B150: lb          $t9, 0x58($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X58);
    // 0x8001B154: nop

    // 0x8001B158: ori         $t6, $t9, 0x80
    ctx->r14 = ctx->r25 | 0X80;
    // 0x8001B15C: sb          $t6, 0x58($v1)
    MEM_B(0X58, ctx->r3) = ctx->r14;
    // 0x8001B160: lb          $a1, 0x114($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X114);
    // 0x8001B164: nop

L_8001B168:
    // 0x8001B168: bne         $a1, $zero, L_8001B2AC
    if (ctx->r5 != 0) {
        // 0x8001B16C: slti        $at, $s0, 0x2A30
        ctx->r1 = SIGNED(ctx->r16) < 0X2A30 ? 1 : 0;
            goto L_8001B2AC;
    }
    // 0x8001B16C: slti        $at, $s0, 0x2A30
    ctx->r1 = SIGNED(ctx->r16) < 0X2A30 ? 1 : 0;
    // 0x8001B170: beq         $at, $zero, L_8001B204
    if (ctx->r1 == 0) {
        // 0x8001B174: nop
    
            goto L_8001B204;
    }
    // 0x8001B174: nop

    // 0x8001B178: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001B17C: lh          $t8, -0x3368($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X3368);
    // 0x8001B180: nop

    // 0x8001B184: bne         $v0, $t8, L_8001B1C4
    if (ctx->r2 != ctx->r24) {
        // 0x8001B188: nop
    
            goto L_8001B1C4;
    }
    // 0x8001B188: nop

    // 0x8001B18C: jal         0x800599F8
    // 0x8001B190: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    timetrial_map_id(rdram, ctx);
        goto after_3;
    // 0x8001B190: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_3:
    // 0x8001B194: jal         0x8006BFC8
    // 0x8001B198: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    level_id(rdram, ctx);
        goto after_4;
    // 0x8001B198: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_4:
    // 0x8001B19C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001B1A0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8001B1A4: bne         $v0, $t7, L_8001B1C4
    if (ctx->r2 != ctx->r15) {
        // 0x8001B1A8: addiu       $t3, $zero, 0x5
        ctx->r11 = ADD32(0, 0X5);
            goto L_8001B1C4;
    }
    // 0x8001B1A8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001B1AC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8001B1B0: lh          $t9, -0x336C($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X336C);
    // 0x8001B1B4: nop

    // 0x8001B1B8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001B1BC: beq         $at, $zero, L_8001B204
    if (ctx->r1 == 0) {
        // 0x8001B1C0: nop
    
            goto L_8001B204;
    }
    // 0x8001B1C0: nop

L_8001B1C4:
    // 0x8001B1C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B1C8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B1CC: lh          $t6, -0x4BFE($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4BFE);
    // 0x8001B1D0: sh          $s0, -0x336C($at)
    MEM_H(-0X336C, ctx->r1) = ctx->r16;
    // 0x8001B1D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B1D8: sh          $t6, -0x3368($at)
    MEM_H(-0X3368, ctx->r1) = ctx->r14;
    // 0x8001B1DC: lb          $t8, 0x59($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X59);
    // 0x8001B1E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B1E4: jal         0x8006BFC8
    // 0x8001B1E8: sh          $t8, -0x3364($at)
    MEM_H(-0X3364, ctx->r1) = ctx->r24;
    level_id(rdram, ctx);
        goto after_5;
    // 0x8001B1E8: sh          $t8, -0x3364($at)
    MEM_H(-0X3364, ctx->r1) = ctx->r24;
    after_5:
    // 0x8001B1EC: jal         0x800599D4
    // 0x8001B1F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    timetrial_swap_player_ghost(rdram, ctx);
        goto after_6;
    // 0x8001B1F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8001B1F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001B1F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B1FC: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001B200: sb          $t7, -0x3360($at)
    MEM_B(-0X3360, ctx->r1) = ctx->r15;
L_8001B204:
    // 0x8001B204: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8001B208: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x8001B20C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8001B210: bne         $t9, $zero, L_8001B254
    if (ctx->r25 != 0) {
        // 0x8001B214: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8001B254;
    }
    // 0x8001B214: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001B218: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x8001B21C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8001B220: div         $zero, $t6, $t3
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r11)));
    // 0x8001B224: bne         $t3, $zero, L_8001B230
    if (ctx->r11 != 0) {
        // 0x8001B228: nop
    
            goto L_8001B230;
    }
    // 0x8001B228: nop

    // 0x8001B22C: break       7
    do_break(2147594796);
L_8001B230:
    // 0x8001B230: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B234: bne         $t3, $at, L_8001B248
    if (ctx->r11 != ctx->r1) {
        // 0x8001B238: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001B248;
    }
    // 0x8001B238: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B23C: bne         $t6, $at, L_8001B248
    if (ctx->r14 != ctx->r1) {
        // 0x8001B240: nop
    
            goto L_8001B248;
    }
    // 0x8001B240: nop

    // 0x8001B244: break       6
    do_break(2147594820);
L_8001B248:
    // 0x8001B248: mflo        $s0
    ctx->r16 = lo;
    // 0x8001B24C: nop

    // 0x8001B250: nop

L_8001B254:
    // 0x8001B254: lh          $t8, -0x4C00($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4C00);
    // 0x8001B258: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8001B25C: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001B260: beq         $at, $zero, L_8001B2A4
    if (ctx->r1 == 0) {
        // 0x8001B264: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_8001B2A4;
    }
    // 0x8001B264: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8001B268: lbu         $t7, -0x335C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X335C);
    // 0x8001B26C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8001B270: beq         $t7, $zero, L_8001B294
    if (ctx->r15 == 0) {
        // 0x8001B274: nop
    
            goto L_8001B294;
    }
    // 0x8001B274: nop

    // 0x8001B278: jal         0x8006BFC8
    // 0x8001B27C: nop

    level_id(rdram, ctx);
        goto after_7;
    // 0x8001B27C: nop

    after_7:
    // 0x8001B280: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8001B284: jal         0x8001B3F8
    // 0x8001B288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tt_ghost_beaten(rdram, ctx);
        goto after_8;
    // 0x8001B288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x8001B28C: b           L_8001B2B0
    // 0x8001B290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001B2B0;
    // 0x8001B290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B294:
    // 0x8001B294: jal         0x800A72FC
    // 0x8001B298: nop

    hud_time_trial_message(rdram, ctx);
        goto after_9;
    // 0x8001B298: nop

    after_9:
    // 0x8001B29C: b           L_8001B2B0
    // 0x8001B2A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001B2B0;
    // 0x8001B2A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B2A4:
    // 0x8001B2A4: jal         0x800A72FC
    // 0x8001B2A8: nop

    hud_time_trial_message(rdram, ctx);
        goto after_10;
    // 0x8001B2A8: nop

    after_10:
L_8001B2AC:
    // 0x8001B2AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B2B0:
    // 0x8001B2B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001B2B4: jr          $ra
    // 0x8001B2B8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8001B2B8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void timetrial_valid_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B2BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B2C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B2C4: jal         0x800599F8
    // 0x8001B2C8: nop

    timetrial_map_id(rdram, ctx);
        goto after_0;
    // 0x8001B2C8: nop

    after_0:
    // 0x8001B2CC: jal         0x8006BFC8
    // 0x8001B2D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    level_id(rdram, ctx);
        goto after_1;
    // 0x8001B2D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001B2D4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B2DC: beq         $v0, $t6, L_8001B2EC
    if (ctx->r2 == ctx->r14) {
        // 0x8001B2E0: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8001B2EC;
    }
    // 0x8001B2E0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001B2E4: b           L_8001B30C
    // 0x8001B2E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B30C;
    // 0x8001B2E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B2EC:
    // 0x8001B2EC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001B2F0: lh          $t8, -0x3368($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X3368);
    // 0x8001B2F4: lh          $t7, -0x4BFE($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X4BFE);
    // 0x8001B2F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B2FC: beq         $t7, $t8, L_8001B30C
    if (ctx->r15 == ctx->r24) {
        // 0x8001B300: nop
    
            goto L_8001B30C;
    }
    // 0x8001B300: nop

    // 0x8001B304: b           L_8001B30C
    // 0x8001B308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B30C;
    // 0x8001B308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B30C:
    // 0x8001B30C: jr          $ra
    // 0x8001B310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001B310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void timetrial_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B314: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B318: lw          $v0, -0x4D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D4C);
    // 0x8001B31C: jr          $ra
    // 0x8001B320: nop

    return;
    // 0x8001B320: nop

;}
RECOMP_FUNC void timetrial_load_staff_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B324: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001B328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B32C: jal         0x8006B2EC
    // 0x8001B330: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    leveltable_vehicle_default(rdram, ctx);
        goto after_0;
    // 0x8001B330: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001B334: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001B338: addiu       $a1, $a1, -0x4BFC
    ctx->r5 = ADD32(ctx->r5, -0X4BFC);
    // 0x8001B33C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8001B340: jal         0x80076EE4
    // 0x8001B344: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x8001B344: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_1:
    // 0x8001B348: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001B34C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001B350: addiu       $a1, $a1, -0x4BFC
    ctx->r5 = ADD32(ctx->r5, -0X4BFC);
    // 0x8001B354: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8001B358: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001B35C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_8001B360:
    // 0x8001B360: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8001B364: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001B368: bne         $a2, $t6, L_8001B390
    if (ctx->r6 != ctx->r14) {
        // 0x8001B36C: nop
    
            goto L_8001B390;
    }
    // 0x8001B36C: nop

    // 0x8001B370: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8001B374: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x8001B378: nop

    // 0x8001B37C: bne         $t7, $t8, L_8001B390
    if (ctx->r15 != ctx->r24) {
        // 0x8001B380: nop
    
            goto L_8001B390;
    }
    // 0x8001B380: nop

    // 0x8001B384: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8001B388: b           L_8001B3A0
    // 0x8001B38C: nop

        goto L_8001B3A0;
    // 0x8001B38C: nop

L_8001B390:
    // 0x8001B390: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8001B394: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001B398: bne         $a3, $v0, L_8001B360
    if (ctx->r7 != ctx->r2) {
        // 0x8001B39C: nop
    
            goto L_8001B360;
    }
    // 0x8001B39C: nop

L_8001B3A0:
    // 0x8001B3A0: beq         $a3, $v0, L_8001B3C4
    if (ctx->r7 == ctx->r2) {
        // 0x8001B3A4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8001B3C4;
    }
    // 0x8001B3A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001B3A8: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8001B3AC: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8001B3B0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001B3B4: addiu       $a2, $a2, -0x4C00
    ctx->r6 = ADD32(ctx->r6, -0X4C00);
    // 0x8001B3B8: jal         0x80059AB8
    // 0x8001B3BC: subu        $a1, $t9, $a0
    ctx->r5 = SUB32(ctx->r25, ctx->r4);
    load_tt_ghost(rdram, ctx);
        goto after_2;
    // 0x8001B3BC: subu        $a1, $t9, $a0
    ctx->r5 = SUB32(ctx->r25, ctx->r4);
    after_2:
    // 0x8001B3C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8001B3C4:
    // 0x8001B3C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001B3C8: jal         0x80071380
    // 0x8001B3CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x8001B3CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x8001B3D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B3D4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B3D8: jr          $ra
    // 0x8001B3DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001B3DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void timetrial_staff_ghost_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3E0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001B3E4: lw          $t6, -0x3378($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3378);
    // 0x8001B3E8: nop

    // 0x8001B3EC: xor         $v0, $a0, $t6
    ctx->r2 = ctx->r4 ^ ctx->r14;
    // 0x8001B3F0: jr          $ra
    // 0x8001B3F4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8001B3F4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void tt_ghost_beaten(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B3FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B400: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001B404: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B408: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001B40C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001B410: jal         0x80059B9C
    // 0x8001B414: sw          $zero, -0x3378($at)
    MEM_W(-0X3378, ctx->r1) = 0;
    timetrial_free_staff_ghost(rdram, ctx);
        goto after_0;
    // 0x8001B414: sw          $zero, -0x3378($at)
    MEM_W(-0X3378, ctx->r1) = 0;
    after_0:
    // 0x8001B418: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B41C: sb          $zero, -0x335C($at)
    MEM_B(-0X335C, ctx->r1) = 0;
    // 0x8001B420: jal         0x8001E2D0
    // 0x8001B424: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8001B424: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_1:
    // 0x8001B428: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8001B42C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8001B430: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001B434: beq         $a3, $t6, L_8001B470
    if (ctx->r7 == ctx->r14) {
        // 0x8001B438: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001B470;
    }
    // 0x8001B438: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001B43C: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x8001B440: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8001B444: beq         $s0, $t7, L_8001B470
    if (ctx->r16 == ctx->r15) {
        // 0x8001B448: nop
    
            goto L_8001B470;
    }
    // 0x8001B448: nop

L_8001B44C:
    // 0x8001B44C: lb          $t8, 0x1($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X1);
    // 0x8001B450: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001B454: beq         $a3, $t8, L_8001B470
    if (ctx->r7 == ctx->r24) {
        // 0x8001B458: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8001B470;
    }
    // 0x8001B458: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001B45C: addu        $t9, $a1, $a2
    ctx->r25 = ADD32(ctx->r5, ctx->r6);
    // 0x8001B460: lb          $t0, 0x0($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X0);
    // 0x8001B464: nop

    // 0x8001B468: bne         $s0, $t0, L_8001B44C
    if (ctx->r16 != ctx->r8) {
        // 0x8001B46C: nop
    
            goto L_8001B44C;
    }
    // 0x8001B46C: nop

L_8001B470:
    // 0x8001B470: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8001B474: addiu       $s0, $s0, -0x3358
    ctx->r16 = ADD32(ctx->r16, -0X3358);
    // 0x8001B478: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B47C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8001B480: beq         $t1, $zero, L_8001B514
    if (ctx->r9 == 0) {
        // 0x8001B484: sllv        $a1, $t2, $a2
        ctx->r5 = S32(ctx->r10 << (ctx->r6 & 31));
            goto L_8001B514;
    }
    // 0x8001B484: sllv        $a1, $t2, $a2
    ctx->r5 = S32(ctx->r10 << (ctx->r6 & 31));
    // 0x8001B488: jal         0x8009EFBC
    // 0x8001B48C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    set_eeprom_settings_value(rdram, ctx);
        goto after_2;
    // 0x8001B48C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_2:
    // 0x8001B490: jal         0x8009F04C
    // 0x8001B494: nop

    get_eeprom_settings(rdram, ctx);
        goto after_3;
    // 0x8001B494: nop

    after_3:
    // 0x8001B498: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001B49C: ori         $at, $at, 0xFFF0
    ctx->r1 = ctx->r1 | 0XFFF0;
    // 0x8001B4A0: and         $t5, $v1, $at
    ctx->r13 = ctx->r3 & ctx->r1;
    // 0x8001B4A4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001B4A8: ori         $at, $at, 0xFFF0
    ctx->r1 = ctx->r1 | 0XFFF0;
    // 0x8001B4AC: bne         $t5, $at, L_8001B4EC
    if (ctx->r13 != ctx->r1) {
        // 0x8001B4B0: addiu       $a0, $zero, 0x24C
        ctx->r4 = ADD32(0, 0X24C);
            goto L_8001B4EC;
    }
    // 0x8001B4B0: addiu       $a0, $zero, 0x24C
    ctx->r4 = ADD32(0, 0X24C);
    // 0x8001B4B4: jal         0x8009C824
    // 0x8001B4B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_magic_code_flags(rdram, ctx);
        goto after_4;
    // 0x8001B4B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8001B4BC: addiu       $a0, $zero, 0x24E
    ctx->r4 = ADD32(0, 0X24E);
    // 0x8001B4C0: jal         0x80001D04
    // 0x8001B4C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8001B4C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8001B4C8: addiu       $a0, $zero, 0x24F
    ctx->r4 = ADD32(0, 0X24F);
    // 0x8001B4CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001B4D0: jal         0x80000FDC
    // 0x8001B4D4: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_6;
    // 0x8001B4D4: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_6:
    // 0x8001B4D8: jal         0x800C3744
    // 0x8001B4DC: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    set_current_text(rdram, ctx);
        goto after_7;
    // 0x8001B4DC: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_7:
    // 0x8001B4E0: b           L_8001B50C
    // 0x8001B4E4: nop

        goto L_8001B50C;
    // 0x8001B4E4: nop

    // 0x8001B4E8: addiu       $a0, $zero, 0x24C
    ctx->r4 = ADD32(0, 0X24C);
L_8001B4EC:
    // 0x8001B4EC: jal         0x80001D04
    // 0x8001B4F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8001B4F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8001B4F4: addiu       $a0, $zero, 0x24D
    ctx->r4 = ADD32(0, 0X24D);
    // 0x8001B4F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001B4FC: jal         0x80000FDC
    // 0x8001B500: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_9;
    // 0x8001B500: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
    // 0x8001B504: jal         0x800C3744
    // 0x8001B508: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    set_current_text(rdram, ctx);
        goto after_10;
    // 0x8001B508: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_10:
L_8001B50C:
    // 0x8001B50C: b           L_8001B520
    // 0x8001B510: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_8001B520;
    // 0x8001B510: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8001B514:
    // 0x8001B514: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001B518: jal         0x800A72FC
    // 0x8001B51C: nop

    hud_time_trial_message(rdram, ctx);
        goto after_11;
    // 0x8001B51C: nop

    after_11:
L_8001B520:
    // 0x8001B520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B524: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001B528: jr          $ra
    // 0x8001B52C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001B52C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void timetrial_init_staff_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B530: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001B534: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B538: sb          $zero, -0x3358($at)
    MEM_B(-0X3358, ctx->r1) = 0;
    // 0x8001B53C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B540: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001B544: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B548: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001B54C: jal         0x8006ECD0
    // 0x8001B550: sb          $zero, -0x335C($at)
    MEM_B(-0X335C, ctx->r1) = 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8001B550: sb          $zero, -0x335C($at)
    MEM_B(-0X335C, ctx->r1) = 0;
    after_0:
    // 0x8001B554: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8001B558: jal         0x8006B2EC
    // 0x8001B55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_vehicle_default(rdram, ctx);
        goto after_1;
    // 0x8001B55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001B560: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B564: lh          $t6, -0x4BFE($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4BFE);
    // 0x8001B568: nop

    // 0x8001B56C: bne         $v0, $t6, L_8001B660
    if (ctx->r2 != ctx->r14) {
        // 0x8001B570: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001B660;
    }
    // 0x8001B570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B574: jal         0x8001E2D0
    // 0x8001B578: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_2;
    // 0x8001B578: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_2:
    // 0x8001B57C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8001B580: jal         0x8001E2D0
    // 0x8001B584: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x8001B584: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x8001B588: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001B58C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8001B590: lb          $t7, 0x0($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X0);
    // 0x8001B594: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8001B598: beq         $a3, $t7, L_8001B5C8
    if (ctx->r7 == ctx->r15) {
        // 0x8001B59C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001B5C8;
    }
    // 0x8001B59C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001B5A0: lb          $t8, 0x0($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X0);
    // 0x8001B5A4: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8001B5A8: beq         $s0, $t8, L_8001B5CC
    if (ctx->r16 == ctx->r24) {
        // 0x8001B5AC: addu        $t9, $t0, $a2
        ctx->r25 = ADD32(ctx->r8, ctx->r6);
            goto L_8001B5CC;
    }
    // 0x8001B5AC: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
L_8001B5B0:
    // 0x8001B5B0: lb          $a1, 0x1($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X1);
    // 0x8001B5B4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001B5B8: beq         $a3, $a1, L_8001B5C8
    if (ctx->r7 == ctx->r5) {
        // 0x8001B5BC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8001B5C8;
    }
    // 0x8001B5BC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001B5C0: bne         $s0, $a1, L_8001B5B0
    if (ctx->r16 != ctx->r5) {
        // 0x8001B5C4: nop
    
            goto L_8001B5B0;
    }
    // 0x8001B5C4: nop

L_8001B5C8:
    // 0x8001B5C8: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
L_8001B5CC:
    // 0x8001B5CC: lb          $t1, 0x0($t9)
    ctx->r9 = MEM_B(ctx->r25, 0X0);
    // 0x8001B5D0: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x8001B5D4: beq         $a3, $t1, L_8001B65C
    if (ctx->r7 == ctx->r9) {
        // 0x8001B5D8: addu        $t3, $v0, $t2
        ctx->r11 = ADD32(ctx->r2, ctx->r10);
            goto L_8001B65C;
    }
    // 0x8001B5D8: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8001B5DC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B5E0: lh          $t6, -0x4BFE($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4BFE);
    // 0x8001B5E4: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x8001B5E8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001B5EC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8001B5F0: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x8001B5F4: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001B5F8: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8001B5FC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8001B600: nop

    // 0x8001B604: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001B608: bne         $at, $zero, L_8001B660
    if (ctx->r1 != 0) {
        // 0x8001B60C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001B660;
    }
    // 0x8001B60C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B610: jal         0x8009F04C
    // 0x8001B614: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    get_eeprom_settings(rdram, ctx);
        goto after_4;
    // 0x8001B614: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_4:
    // 0x8001B618: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8001B61C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8001B620: sllv        $t5, $t6, $a2
    ctx->r13 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x8001B624: sra         $t8, $t5, 31
    ctx->r24 = S32(SIGNED(ctx->r13) >> 31);
    // 0x8001B628: and         $t2, $v0, $t8
    ctx->r10 = ctx->r2 & ctx->r24;
    // 0x8001B62C: bne         $t2, $zero, L_8001B644
    if (ctx->r10 != 0) {
        // 0x8001B630: and         $t3, $v1, $t5
        ctx->r11 = ctx->r3 & ctx->r13;
            goto L_8001B644;
    }
    // 0x8001B630: and         $t3, $v1, $t5
    ctx->r11 = ctx->r3 & ctx->r13;
    // 0x8001B634: bne         $t3, $zero, L_8001B644
    if (ctx->r11 != 0) {
        // 0x8001B638: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8001B644;
    }
    // 0x8001B638: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001B63C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B640: sb          $t7, -0x3358($at)
    MEM_B(-0X3358, ctx->r1) = ctx->r15;
L_8001B644:
    // 0x8001B644: jal         0x8001B324
    // 0x8001B648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    timetrial_load_staff_ghost(rdram, ctx);
        goto after_5;
    // 0x8001B648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8001B64C: bne         $v0, $zero, L_8001B65C
    if (ctx->r2 != 0) {
        // 0x8001B650: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8001B65C;
    }
    // 0x8001B650: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001B654: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B658: sb          $t1, -0x335C($at)
    MEM_B(-0X335C, ctx->r1) = ctx->r9;
L_8001B65C:
    // 0x8001B65C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B660:
    // 0x8001B660: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B664: lbu         $v0, -0x335C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X335C);
    // 0x8001B668: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001B66C: jr          $ra
    // 0x8001B670: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001B670: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void timetrial_ghost_staff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B674: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B678: lw          $v0, -0x3378($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3378);
    // 0x8001B67C: jr          $ra
    // 0x8001B680: nop

    return;
    // 0x8001B680: nop

;}
RECOMP_FUNC void timetrial_staff_unbeaten(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B684: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B688: lbu         $v0, -0x3358($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3358);
    // 0x8001B68C: nop

    // 0x8001B690: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8001B694: jr          $ra
    // 0x8001B698: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8001B698: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void timetrial_init_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B69C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001B6A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B6A4: jal         0x800599F8
    // 0x8001B6A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    timetrial_map_id(rdram, ctx);
        goto after_0;
    // 0x8001B6A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001B6AC: jal         0x8006BFC8
    // 0x8001B6B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    level_id(rdram, ctx);
        goto after_1;
    // 0x8001B6B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001B6B4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001B6B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001B6BC: bne         $v0, $t6, L_8001B6D8
    if (ctx->r2 != ctx->r14) {
        // 0x8001B6C0: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_8001B6D8;
    }
    // 0x8001B6C0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001B6C4: lh          $t7, -0x4BFE($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X4BFE);
    // 0x8001B6C8: lh          $t8, -0x3368($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X3368);
    // 0x8001B6CC: nop

    // 0x8001B6D0: beq         $t7, $t8, L_8001B738
    if (ctx->r15 == ctx->r24) {
        // 0x8001B6D4: nop
    
            goto L_8001B738;
    }
    // 0x8001B6D4: nop

L_8001B6D8:
    // 0x8001B6D8: jal         0x8006BFC8
    // 0x8001B6DC: nop

    level_id(rdram, ctx);
        goto after_2;
    // 0x8001B6DC: nop

    after_2:
    // 0x8001B6E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001B6E4: lh          $a2, -0x4BFE($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X4BFE);
    // 0x8001B6E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8001B6EC: addiu       $t9, $sp, 0x2C
    ctx->r25 = ADD32(ctx->r29, 0X2C);
    // 0x8001B6F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8001B6F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001B6F8: jal         0x80059A08
    // 0x8001B6FC: addiu       $a3, $sp, 0x2E
    ctx->r7 = ADD32(ctx->r29, 0X2E);
    timetrial_load_player_ghost(rdram, ctx);
        goto after_3;
    // 0x8001B6FC: addiu       $a3, $sp, 0x2E
    ctx->r7 = ADD32(ctx->r29, 0X2E);
    after_3:
    // 0x8001B700: bne         $v0, $zero, L_8001B730
    if (ctx->r2 != 0) {
        // 0x8001B704: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001B730;
    }
    // 0x8001B704: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001B708: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8001B70C: lh          $t0, -0x4BFE($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4BFE);
    // 0x8001B710: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B714: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x8001B718: sh          $t0, -0x3368($at)
    MEM_H(-0X3368, ctx->r1) = ctx->r8;
    // 0x8001B71C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B720: lh          $t2, 0x2C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2C);
    // 0x8001B724: sh          $t1, -0x3364($at)
    MEM_H(-0X3364, ctx->r1) = ctx->r9;
    // 0x8001B728: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B72C: sh          $t2, -0x336C($at)
    MEM_H(-0X336C, ctx->r1) = ctx->r10;
L_8001B730:
    // 0x8001B730: b           L_8001B75C
    // 0x8001B734: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8001B75C;
    // 0x8001B734: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001B738:
    // 0x8001B738: jal         0x8006BFC8
    // 0x8001B73C: nop

    level_id(rdram, ctx);
        goto after_4;
    // 0x8001B73C: nop

    after_4:
    // 0x8001B740: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001B744: lh          $a2, -0x4BFE($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X4BFE);
    // 0x8001B748: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8001B74C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001B750: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001B754: jal         0x80059A08
    // 0x8001B758: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    timetrial_load_player_ghost(rdram, ctx);
        goto after_5;
    // 0x8001B758: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
L_8001B75C:
    // 0x8001B75C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B760: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001B764: jr          $ra
    // 0x8001B768: nop

    return;
    // 0x8001B768: nop

;}
RECOMP_FUNC void timetrial_save_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B76C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B770: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B774: jal         0x800599F8
    // 0x8001B778: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    timetrial_map_id(rdram, ctx);
        goto after_0;
    // 0x8001B778: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001B77C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001B780: lh          $t6, -0x336C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X336C);
    // 0x8001B784: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8001B788: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8001B78C: lh          $a3, -0x3364($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X3364);
    // 0x8001B790: lh          $a2, -0x3368($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X3368);
    // 0x8001B794: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001B798: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001B79C: jal         0x80059BCC
    // 0x8001B7A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    timetrial_write_player_ghost(rdram, ctx);
        goto after_1;
    // 0x8001B7A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8001B7A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B7A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B7AC: jr          $ra
    // 0x8001B7B0: nop

    return;
    // 0x8001B7B0: nop

;}
RECOMP_FUNC void has_ghost_to_save(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7B4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B7B8: lbu         $v0, -0x3360($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3360);
    // 0x8001B7BC: jr          $ra
    // 0x8001B7C0: nop

    return;
    // 0x8001B7C0: nop

;}
RECOMP_FUNC void set_ghost_none(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8001B7C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001B7CC: sh          $t6, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r14;
    // 0x8001B7D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B7D4: jr          $ra
    // 0x8001B7D8: sb          $zero, -0x3360($at)
    MEM_B(-0X3360, ctx->r1) = 0;
    return;
    // 0x8001B7D8: sb          $zero, -0x3360($at)
    MEM_B(-0X3360, ctx->r1) = 0;
;}
RECOMP_FUNC void racer_find_nearest_opponent_relative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B7E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B7E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001B7E8: lh          $t6, 0x1AA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1AA);
    // 0x8001B7EC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001B7F0: subu        $a1, $t6, $a1
    ctx->r5 = SUB32(ctx->r14, ctx->r5);
    // 0x8001B7F4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001B7F8: bltz        $a1, L_8001B814
    if (SIGNED(ctx->r5) < 0) {
        // 0x8001B7FC: nop
    
            goto L_8001B814;
    }
    // 0x8001B7FC: nop

    // 0x8001B800: lw          $t7, -0x4B90($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4B90);
    // 0x8001B804: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001B808: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001B80C: bne         $at, $zero, L_8001B81C
    if (ctx->r1 != 0) {
        // 0x8001B810: nop
    
            goto L_8001B81C;
    }
    // 0x8001B810: nop

L_8001B814:
    // 0x8001B814: b           L_8001B858
    // 0x8001B818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B858;
    // 0x8001B818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B81C:
    // 0x8001B81C: lw          $t8, -0x4B98($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4B98);
    // 0x8001B820: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8001B824: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8001B828: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001B82C: nop

    // 0x8001B830: bne         $v1, $zero, L_8001B840
    if (ctx->r3 != 0) {
        // 0x8001B834: nop
    
            goto L_8001B840;
    }
    // 0x8001B834: nop

    // 0x8001B838: b           L_8001B858
    // 0x8001B83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B858;
    // 0x8001B83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B840:
    // 0x8001B840: lw          $a1, 0x64($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X64);
    // 0x8001B844: jal         0x8001B868
    // 0x8001B848: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    racer_calc_distance_to_opponent(rdram, ctx);
        goto after_0;
    // 0x8001B848: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001B84C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001B850: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8001B854: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
L_8001B858:
    // 0x8001B858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B85C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B860: jr          $ra
    // 0x8001B864: nop

    return;
    // 0x8001B864: nop

;}
RECOMP_FUNC void racer_calc_distance_to_opponent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B868: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B86C: lw          $v0, -0x4BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
    // 0x8001B870: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001B874: bgtz        $v0, L_8001B888
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001B878: nop
    
            goto L_8001B888;
    }
    // 0x8001B878: nop

    // 0x8001B87C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001B880: jr          $ra
    // 0x8001B884: nop

    return;
    // 0x8001B884: nop

L_8001B888:
    // 0x8001B888: lh          $a0, 0x190($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X190);
    // 0x8001B88C: lh          $a3, 0x190($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X190);
    // 0x8001B890: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001B894: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001B898: beq         $at, $zero, L_8001B8B8
    if (ctx->r1 == 0) {
        // 0x8001B89C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001B8B8;
    }
    // 0x8001B89C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001B8A0: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8001B8A4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8001B8A8: lh          $a3, 0x190($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X190);
    // 0x8001B8AC: lh          $a0, 0x190($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X190);
    // 0x8001B8B0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8001B8B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001B8B8:
    // 0x8001B8B8: lb          $t1, 0x192($a2)
    ctx->r9 = MEM_B(ctx->r6, 0X192);
    // 0x8001B8BC: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001B8C0: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8001B8C4: beq         $at, $zero, L_8001B908
    if (ctx->r1 == 0) {
        // 0x8001B8C8: or          $t0, $t1, $zero
        ctx->r8 = ctx->r9 | 0;
            goto L_8001B908;
    }
    // 0x8001B8C8: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8001B8CC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001B8D0: lw          $a3, -0x4BB4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB4);
    // 0x8001B8D4: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
L_8001B8D8:
    // 0x8001B8D8: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B8DC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8001B8E0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001B8E4: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001B8E8: mflo        $t6
    ctx->r14 = lo;
    // 0x8001B8EC: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8001B8F0: lwc1        $f4, 0x20($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8001B8F4: bne         $t0, $v0, L_8001B900
    if (ctx->r8 != ctx->r2) {
        // 0x8001B8F8: add.s       $f2, $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
            goto L_8001B900;
    }
    // 0x8001B8F8: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8001B8FC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8001B900:
    // 0x8001B900: bne         $at, $zero, L_8001B8D8
    if (ctx->r1 != 0) {
        // 0x8001B904: nop
    
            goto L_8001B8D8;
    }
    // 0x8001B904: nop

L_8001B908:
    // 0x8001B908: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001B90C: addiu       $t0, $t1, -0x1
    ctx->r8 = ADD32(ctx->r9, -0X1);
    // 0x8001B910: lw          $a3, -0x4BB4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB4);
    // 0x8001B914: bgez        $t0, L_8001B920
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8001B918: addiu       $t3, $zero, 0x3C
        ctx->r11 = ADD32(0, 0X3C);
            goto L_8001B920;
    }
    // 0x8001B918: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x8001B91C: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
L_8001B920:
    // 0x8001B920: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B924: lwc1        $f8, 0xA8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XA8);
    // 0x8001B928: lb          $t0, 0x192($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X192);
    // 0x8001B92C: nop

    // 0x8001B930: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8001B934: mflo        $t8
    ctx->r24 = lo;
    // 0x8001B938: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8001B93C: lwc1        $f6, 0x20($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8001B940: nop

    // 0x8001B944: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001B948: bgez        $t0, L_8001B954
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8001B94C: add.s       $f2, $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
            goto L_8001B954;
    }
    // 0x8001B94C: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8001B950: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
L_8001B954:
    // 0x8001B954: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B958: lwc1        $f18, 0xA8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XA8);
    // 0x8001B95C: mflo        $t4
    ctx->r12 = lo;
    // 0x8001B960: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x8001B964: lwc1        $f16, 0x20($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X20);
    // 0x8001B968: nop

    // 0x8001B96C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001B970: beq         $v1, $zero, L_8001B97C
    if (ctx->r3 == 0) {
        // 0x8001B974: sub.s       $f2, $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_8001B97C;
    }
    // 0x8001B974: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001B978: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8001B97C:
    // 0x8001B97C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001B980: jr          $ra
    // 0x8001B984: nop

    return;
    // 0x8001B984: nop

;}
RECOMP_FUNC void race_calc_distance_to_start_line(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B988: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B98C: lw          $v0, -0x4BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
    // 0x8001B990: nop

    // 0x8001B994: bgtz        $v0, L_8001B9A8
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001B998: nop
    
            goto L_8001B9A8;
    }
    // 0x8001B998: nop

    // 0x8001B99C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001B9A0: jr          $ra
    // 0x8001B9A4: nop

    return;
    // 0x8001B9A4: nop

L_8001B9A8:
    // 0x8001B9A8: lb          $a1, 0x192($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X192);
    // 0x8001B9AC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001B9B0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001B9B4: beq         $at, $zero, L_8001B9EC
    if (ctx->r1 == 0) {
        // 0x8001B9B8: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8001B9EC;
    }
    // 0x8001B9B8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8001B9BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B9C0: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8001B9C4: lw          $t6, -0x4BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BB4);
    // 0x8001B9C8: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8001B9CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001B9D0: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
L_8001B9D4:
    // 0x8001B9D4: lwc1        $f4, 0x20($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X20);
    // 0x8001B9D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001B9DC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001B9E0: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    // 0x8001B9E4: bne         $at, $zero, L_8001B9D4
    if (ctx->r1 != 0) {
        // 0x8001B9E8: add.s       $f2, $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
            goto L_8001B9D4;
    }
    // 0x8001B9E8: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
L_8001B9EC:
    // 0x8001B9EC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001B9F0: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8001B9F4: lw          $a2, -0x4BB4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4BB4);
    // 0x8001B9F8: bgez        $v1, L_8001BA08
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001B9FC: sll         $t8, $v1, 4
        ctx->r24 = S32(ctx->r3 << 4);
            goto L_8001BA08;
    }
    // 0x8001B9FC: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x8001BA00: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8001BA04: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
L_8001BA08:
    // 0x8001BA08: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8001BA0C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001BA10: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8001BA14: lwc1        $f6, 0x20($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8001BA18: lwc1        $f8, 0xA8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x8001BA1C: nop

    // 0x8001BA20: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001BA24: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8001BA28: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001BA2C: jr          $ra
    // 0x8001BA30: nop

    return;
    // 0x8001BA30: nop

;}
RECOMP_FUNC void get_checkpoint_node(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA34: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x8001BA38: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001BA3C: lw          $t7, -0x4BB4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4BB4);
    // 0x8001BA40: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8001BA44: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001BA48: jr          $ra
    // 0x8001BA4C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    return;
    // 0x8001BA4C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
;}
RECOMP_FUNC void find_next_checkpoint_node(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA50: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8001BA54: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BA58: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BA5C: lw          $v0, -0x4BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB4);
    // 0x8001BA60: mflo        $t6
    ctx->r14 = lo;
    // 0x8001BA64: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x8001BA68: beq         $a1, $zero, L_8001BA90
    if (ctx->r5 == 0) {
        // 0x8001BA6C: nop
    
            goto L_8001BA90;
    }
    // 0x8001BA6C: nop

    // 0x8001BA70: lb          $a0, 0x3A($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X3A);
    // 0x8001BA74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001BA78: beq         $a0, $at, L_8001BA90
    if (ctx->r4 == ctx->r1) {
        // 0x8001BA7C: nop
    
            goto L_8001BA90;
    }
    // 0x8001BA7C: nop

    // 0x8001BA80: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BA84: mflo        $t7
    ctx->r15 = lo;
    // 0x8001BA88: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x8001BA8C: nop

L_8001BA90:
    // 0x8001BA90: jr          $ra
    // 0x8001BA94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001BA94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void get_checkpoint_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BA9C: lw          $v0, -0x4BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
    // 0x8001BAA0: jr          $ra
    // 0x8001BAA4: nop

    return;
    // 0x8001BAA4: nop

;}
RECOMP_FUNC void get_racer_objects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BAA8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001BAAC: lw          $t6, -0x4B90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B90);
    // 0x8001BAB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BAB4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BAB8: lw          $v0, -0x4B9C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B9C);
    // 0x8001BABC: jr          $ra
    // 0x8001BAC0: nop

    return;
    // 0x8001BAC0: nop

;}
RECOMP_FUNC void get_racer_objects_by_port(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BAC4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001BAC8: lw          $t6, -0x4B90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B90);
    // 0x8001BACC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BAD0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BAD4: lw          $v0, -0x4B94($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B94);
    // 0x8001BAD8: jr          $ra
    // 0x8001BADC: nop

    return;
    // 0x8001BADC: nop

;}
RECOMP_FUNC void get_racer_objects_by_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BAE0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001BAE4: lw          $t6, -0x4B90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B90);
    // 0x8001BAE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BAEC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BAF0: lw          $v0, -0x4B98($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B98);
    // 0x8001BAF4: jr          $ra
    // 0x8001BAF8: nop

    return;
    // 0x8001BAF8: nop

;}
RECOMP_FUNC void get_racer_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BAFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BB00: lw          $v0, -0x4B90($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B90);
    // 0x8001BB04: nop

    // 0x8001BB08: bne         $v0, $zero, L_8001BB18
    if (ctx->r2 != 0) {
        // 0x8001BB0C: nop
    
            goto L_8001BB18;
    }
    // 0x8001BB0C: nop

    // 0x8001BB10: jr          $ra
    // 0x8001BB14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BB14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BB18:
    // 0x8001BB18: bltz        $a0, L_8001BB28
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001BB1C: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001BB28;
    }
    // 0x8001BB1C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BB20: bne         $at, $zero, L_8001BB30
    if (ctx->r1 != 0) {
        // 0x8001BB24: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001BB30;
    }
    // 0x8001BB24: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
L_8001BB28:
    // 0x8001BB28: jr          $ra
    // 0x8001BB2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BB2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BB30:
    // 0x8001BB30: lw          $t6, -0x4B9C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B9C);
    // 0x8001BB34: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001BB38: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001BB3C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001BB40: nop

    // 0x8001BB44: jr          $ra
    // 0x8001BB48: nop

    return;
    // 0x8001BB48: nop

;}
RECOMP_FUNC void get_racer_object_by_port(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BB4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BB50: lw          $v0, -0x4B90($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B90);
    // 0x8001BB54: nop

    // 0x8001BB58: bne         $v0, $zero, L_8001BB68
    if (ctx->r2 != 0) {
        // 0x8001BB5C: nop
    
            goto L_8001BB68;
    }
    // 0x8001BB5C: nop

    // 0x8001BB60: jr          $ra
    // 0x8001BB64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BB64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BB68:
    // 0x8001BB68: bltz        $a0, L_8001BB78
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001BB6C: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001BB78;
    }
    // 0x8001BB6C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BB70: bne         $at, $zero, L_8001BB80
    if (ctx->r1 != 0) {
        // 0x8001BB74: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001BB80;
    }
    // 0x8001BB74: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
L_8001BB78:
    // 0x8001BB78: jr          $ra
    // 0x8001BB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BB80:
    // 0x8001BB80: lw          $t6, -0x4B94($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B94);
    // 0x8001BB84: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001BB88: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001BB8C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001BB90: nop

    // 0x8001BB94: jr          $ra
    // 0x8001BB98: nop

    return;
    // 0x8001BB98: nop

;}
