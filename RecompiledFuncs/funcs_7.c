#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800214E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002151C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021520: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x80021524: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80021528: lb          $t6, 0x3A($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X3A);
    // 0x8002152C: nop

    // 0x80021530: beq         $t6, $zero, L_80021548
    if (ctx->r14 == 0) {
        // 0x80021534: nop
    
            goto L_80021548;
    }
    // 0x80021534: nop

    // 0x80021538: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8002153C: nop

    // 0x80021540: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x80021544: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
L_80021548:
    // 0x80021548: lh          $v0, 0x36($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X36);
    // 0x8002154C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80021550: bne         $v1, $v0, L_80021564
    if (ctx->r3 != ctx->r2) {
        // 0x80021554: nop
    
            goto L_80021564;
    }
    // 0x80021554: nop

    // 0x80021558: lb          $v0, 0x3A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X3A);
    // 0x8002155C: b           L_80021628
    // 0x80021560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80021628;
    // 0x80021560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021564:
    // 0x80021564: bltz        $v0, L_80021578
    if (SIGNED(ctx->r2) < 0) {
        // 0x80021568: subu        $t9, $v0, $a1
        ctx->r25 = SUB32(ctx->r2, ctx->r5);
            goto L_80021578;
    }
    // 0x80021568: subu        $t9, $v0, $a1
    ctx->r25 = SUB32(ctx->r2, ctx->r5);
    // 0x8002156C: sh          $t9, 0x36($a2)
    MEM_H(0X36, ctx->r6) = ctx->r25;
    // 0x80021570: lh          $v0, 0x36($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X36);
    // 0x80021574: nop

L_80021578:
    // 0x80021578: bne         $v1, $v0, L_8002158C
    if (ctx->r3 != ctx->r2) {
        // 0x8002157C: addiu       $t0, $zero, -0x2
        ctx->r8 = ADD32(0, -0X2);
            goto L_8002158C;
    }
    // 0x8002157C: addiu       $t0, $zero, -0x2
    ctx->r8 = ADD32(0, -0X2);
    // 0x80021580: sh          $t0, 0x36($a2)
    MEM_H(0X36, ctx->r6) = ctx->r8;
    // 0x80021584: lh          $v0, 0x36($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X36);
    // 0x80021588: nop

L_8002158C:
    // 0x8002158C: bgtz        $v0, L_80021620
    if (SIGNED(ctx->r2) > 0) {
        // 0x80021590: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80021620;
    }
    // 0x80021590: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80021594: lh          $t1, 0x6($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X6);
    // 0x80021598: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002159C: ori         $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 | 0X4000;
    // 0x800215A0: sh          $t2, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r10;
    // 0x800215A4: lh          $a1, -0x4C08($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X4C08);
    // 0x800215A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800215AC: blez        $a1, L_80021600
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800215B0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80021600;
    }
    // 0x800215B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800215B4: lw          $a0, -0x4C0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C0C);
    // 0x800215B8: lh          $v1, 0x28($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X28);
    // 0x800215BC: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800215C0: nop

    // 0x800215C4: lw          $t4, 0x7C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X7C);
    // 0x800215C8: nop

    // 0x800215CC: beq         $v1, $t4, L_80021600
    if (ctx->r3 == ctx->r12) {
        // 0x800215D0: nop
    
            goto L_80021600;
    }
    // 0x800215D0: nop

L_800215D4:
    // 0x800215D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800215D8: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800215DC: beq         $at, $zero, L_80021600
    if (ctx->r1 == 0) {
        // 0x800215E0: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_80021600;
    }
    // 0x800215E0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800215E4: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x800215E8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800215EC: nop

    // 0x800215F0: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x800215F4: nop

    // 0x800215F8: bne         $v1, $t8, L_800215D4
    if (ctx->r3 != ctx->r24) {
        // 0x800215FC: nop
    
            goto L_800215D4;
    }
    // 0x800215FC: nop

L_80021600:
    // 0x80021600: lw          $t9, -0x4C0C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4C0C);
    // 0x80021604: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80021608: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8002160C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80021610: jal         0x8001EFD8
    // 0x80021614: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_init_animobject(rdram, ctx);
        goto after_0;
    // 0x80021614: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80021618: b           L_80021624
    // 0x8002161C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80021624;
    // 0x8002161C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80021620:
    // 0x80021620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80021624:
    // 0x80021624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021628:
    // 0x80021628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002162C: jr          $ra
    // 0x80021630: nop

    return;
    // 0x80021630: nop

;}
RECOMP_FUNC void func_80021600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021634: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x80021638: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002163C: lh          $t6, -0x4C06($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4C06);
    // 0x80021640: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80021644: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80021648: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8002164C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80021650: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80021654: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80021658: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002165C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80021660: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80021664: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80021668: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002166C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80021670: bgez        $t6, L_80021680
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80021674: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80021680;
    }
    // 0x80021674: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80021678: b           L_8002253C
    // 0x8002167C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002253C;
    // 0x8002167C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80021680:
    // 0x80021680: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021684: lh          $v1, -0x4C08($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4C08);
    // 0x80021688: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002168C: blez        $v1, L_800216E4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80021690: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800216E4;
    }
    // 0x80021690: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80021694: addiu       $a2, $a2, -0x4C0C
    ctx->r6 = ADD32(ctx->r6, -0X4C0C);
    // 0x80021698: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8002169C: nop

    // 0x800216A0: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800216A4: nop

    // 0x800216A8: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x800216AC: nop

    // 0x800216B0: beq         $a1, $t8, L_800216E4
    if (ctx->r5 == ctx->r24) {
        // 0x800216B4: nop
    
            goto L_800216E4;
    }
    // 0x800216B4: nop

L_800216B8:
    // 0x800216B8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800216BC: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800216C0: beq         $at, $zero, L_800216E4
    if (ctx->r1 == 0) {
        // 0x800216C4: sll         $t9, $s7, 2
        ctx->r25 = S32(ctx->r23 << 2);
            goto L_800216E4;
    }
    // 0x800216C4: sll         $t9, $s7, 2
    ctx->r25 = S32(ctx->r23 << 2);
    // 0x800216C8: addu        $t3, $a3, $t9
    ctx->r11 = ADD32(ctx->r7, ctx->r25);
    // 0x800216CC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800216D0: nop

    // 0x800216D4: lw          $t5, 0x7C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X7C);
    // 0x800216D8: nop

    // 0x800216DC: bne         $a1, $t5, L_800216B8
    if (ctx->r5 != ctx->r13) {
        // 0x800216E0: nop
    
            goto L_800216B8;
    }
    // 0x800216E0: nop

L_800216E4:
    // 0x800216E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800216E8: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800216EC: bne         $at, $zero, L_800216FC
    if (ctx->r1 != 0) {
        // 0x800216F0: addiu       $a2, $a2, -0x4C0C
        ctx->r6 = ADD32(ctx->r6, -0X4C0C);
            goto L_800216FC;
    }
    // 0x800216F0: addiu       $a2, $a2, -0x4C0C
    ctx->r6 = ADD32(ctx->r6, -0X4C0C);
    // 0x800216F4: b           L_8002253C
    // 0x800216F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002253C;
    // 0x800216F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800216FC:
    // 0x800216FC: addiu       $t6, $s7, 0x1
    ctx->r14 = ADD32(ctx->r23, 0X1);
    // 0x80021700: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021704: beq         $at, $zero, L_8002175C
    if (ctx->r1 == 0) {
        // 0x80021708: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_8002175C;
    }
    // 0x80021708: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8002170C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80021710: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x80021714: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80021718: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8002171C: addu        $v0, $s7, $s5
    ctx->r2 = ADD32(ctx->r23, ctx->r21);
    // 0x80021720: lw          $t3, 0x7C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X7C);
    // 0x80021724: nop

    // 0x80021728: bne         $a1, $t3, L_8002175C
    if (ctx->r5 != ctx->r11) {
        // 0x8002172C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8002175C;
    }
    // 0x8002172C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80021730:
    // 0x80021730: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021734: beq         $at, $zero, L_8002175C
    if (ctx->r1 == 0) {
        // 0x80021738: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8002175C;
    }
    // 0x80021738: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8002173C: sll         $t4, $s5, 2
    ctx->r12 = S32(ctx->r21 << 2);
    // 0x80021740: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80021744: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80021748: nop

    // 0x8002174C: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x80021750: nop

    // 0x80021754: beq         $a1, $t7, L_80021730
    if (ctx->r5 == ctx->r15) {
        // 0x80021758: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80021730;
    }
    // 0x80021758: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8002175C:
    // 0x8002175C: slti        $at, $s5, 0x2
    ctx->r1 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
    // 0x80021760: beq         $at, $zero, L_80021770
    if (ctx->r1 == 0) {
        // 0x80021764: sll         $t8, $s7, 2
        ctx->r24 = S32(ctx->r23 << 2);
            goto L_80021770;
    }
    // 0x80021764: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x80021768: b           L_8002253C
    // 0x8002176C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002253C;
    // 0x8002176C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80021770:
    // 0x80021770: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80021774: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x80021778: addu        $t3, $a3, $t8
    ctx->r11 = ADD32(ctx->r7, ctx->r24);
    // 0x8002177C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80021780: addiu       $s2, $sp, 0x124
    ctx->r18 = ADD32(ctx->r29, 0X124);
    // 0x80021784: lw          $t4, 0x64($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X64);
    // 0x80021788: addiu       $s3, $sp, 0x110
    ctx->r19 = ADD32(ctx->r29, 0X110);
    // 0x8002178C: bne         $t4, $zero, L_8002179C
    if (ctx->r12 != 0) {
        // 0x80021790: sw          $t4, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r12;
            goto L_8002179C;
    }
    // 0x80021790: sw          $t4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r12;
    // 0x80021794: b           L_8002253C
    // 0x80021798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002253C;
    // 0x80021798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002179C:
    // 0x8002179C: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x800217A0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800217A4: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x800217A8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800217AC: sw          $t7, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r15;
    // 0x800217B0: lw          $t8, 0x40($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X40);
    // 0x800217B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800217B8: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800217BC: sll         $t9, $s7, 2
    ctx->r25 = S32(ctx->r23 << 2);
    // 0x800217C0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800217C4: nop

    // 0x800217C8: div.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x800217CC: addu        $t3, $a3, $t9
    ctx->r11 = ADD32(ctx->r7, ctx->r25);
    // 0x800217D0: sll         $t4, $s5, 2
    ctx->r12 = S32(ctx->r21 << 2);
    // 0x800217D4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800217D8: slti        $at, $s5, 0x3
    ctx->r1 = SIGNED(ctx->r21) < 0X3 ? 1 : 0;
    // 0x800217DC: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x800217E0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800217E4: addiu       $s4, $sp, 0xFC
    ctx->r20 = ADD32(ctx->r29, 0XFC);
    // 0x800217E8: addiu       $fp, $sp, 0xBC
    ctx->r30 = ADD32(ctx->r29, 0XBC);
    // 0x800217EC: addiu       $s6, $sp, 0xA8
    ctx->r22 = ADD32(ctx->r29, 0XA8);
    // 0x800217F0: addiu       $t1, $sp, 0x94
    ctx->r9 = ADD32(ctx->r29, 0X94);
    // 0x800217F4: addiu       $s1, $sp, 0xD0
    ctx->r17 = ADD32(ctx->r29, 0XD0);
    // 0x800217F8: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x800217FC: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x80021800: lw          $t6, -0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X4);
    // 0x80021804: nop

    // 0x80021808: lw          $a1, 0x3C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X3C);
    // 0x8002180C: bne         $at, $zero, L_80021830
    if (ctx->r1 != 0) {
        // 0x80021810: nop
    
            goto L_80021830;
    }
    // 0x80021810: nop

    // 0x80021814: lb          $v0, 0x1D($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1D);
    // 0x80021818: addiu       $t7, $s5, -0x1
    ctx->r15 = ADD32(ctx->r21, -0X1);
    // 0x8002181C: bltz        $v0, L_80021830
    if (SIGNED(ctx->r2) < 0) {
        // 0x80021820: slt         $at, $v0, $t7
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
            goto L_80021830;
    }
    // 0x80021820: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80021824: beq         $at, $zero, L_80021830
    if (ctx->r1 == 0) {
        // 0x80021828: nop
    
            goto L_80021830;
    }
    // 0x80021828: nop

    // 0x8002182C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80021830:
    // 0x80021830: lh          $s0, 0x26($t8)
    ctx->r16 = MEM_H(ctx->r24, 0X26);
    // 0x80021834: sw          $v1, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r3;
    // 0x80021838: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8002183C:
    // 0x8002183C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021840: bne         $s0, $at, L_800219F0
    if (ctx->r16 != ctx->r1) {
        // 0x80021844: slt         $at, $s0, $s5
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_800219F0;
    }
    // 0x80021844: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80021848: lw          $t9, 0x138($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X138);
    // 0x8002184C: addu        $t3, $s7, $s5
    ctx->r11 = ADD32(ctx->r23, ctx->r21);
    // 0x80021850: beq         $t9, $zero, L_80021938
    if (ctx->r25 == 0) {
        // 0x80021854: sll         $t4, $t3, 2
        ctx->r12 = S32(ctx->r11 << 2);
            goto L_80021938;
    }
    // 0x80021854: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80021858: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x8002185C: nop

    // 0x80021860: addu        $v0, $a3, $t3
    ctx->r2 = ADD32(ctx->r7, ctx->r11);
    // 0x80021864: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80021868: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8002186C: lwc1        $f0, 0xC($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80021870: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80021874: nop

    // 0x80021878: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8002187C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80021880: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    // 0x80021884: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80021888: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8002188C: lwc1        $f2, 0x10($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80021890: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80021894: nop

    // 0x80021898: sub.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8002189C: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800218A0: swc1        $f8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f8.u32l;
    // 0x800218A4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800218A8: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800218AC: lwc1        $f12, 0x14($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X14);
    // 0x800218B0: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x800218B4: nop

    // 0x800218B8: sub.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x800218BC: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800218C0: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x800218C4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800218C8: nop

    // 0x800218CC: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x800218D0: nop

    // 0x800218D4: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800218D8: nop

    // 0x800218DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800218E0: swc1        $f10, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f10.u32l;
    // 0x800218E4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800218E8: nop

    // 0x800218EC: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x800218F0: nop

    // 0x800218F4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800218F8: nop

    // 0x800218FC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021900: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
    // 0x80021904: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80021908: nop

    // 0x8002190C: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x80021910: nop

    // 0x80021914: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80021918: nop

    // 0x8002191C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021920: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80021924: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80021928: nop

    // 0x8002192C: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80021930: b           L_80021D08
    // 0x80021934: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_80021D08;
    // 0x80021934: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_80021938:
    // 0x80021938: addu        $v0, $a3, $t4
    ctx->r2 = ADD32(ctx->r7, ctx->r12);
    // 0x8002193C: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x80021940: nop

    // 0x80021944: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80021948: nop

    // 0x8002194C: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80021950: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80021954: nop

    // 0x80021958: lwc1        $f8, 0x10($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8002195C: nop

    // 0x80021960: swc1        $f8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f8.u32l;
    // 0x80021964: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x80021968: nop

    // 0x8002196C: lwc1        $f10, 0x14($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X14);
    // 0x80021970: nop

    // 0x80021974: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80021978: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x8002197C: nop

    // 0x80021980: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80021984: nop

    // 0x80021988: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8002198C: nop

    // 0x80021990: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021994: swc1        $f4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f4.u32l;
    // 0x80021998: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x8002199C: nop

    // 0x800219A0: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x800219A4: nop

    // 0x800219A8: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800219AC: nop

    // 0x800219B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800219B4: swc1        $f10, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f10.u32l;
    // 0x800219B8: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800219BC: nop

    // 0x800219C0: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x800219C4: nop

    // 0x800219C8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800219CC: nop

    // 0x800219D0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800219D4: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x800219D8: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800219DC: nop

    // 0x800219E0: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800219E4: b           L_80021D08
    // 0x800219E8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
        goto L_80021D08;
    // 0x800219E8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x800219EC: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
L_800219F0:
    // 0x800219F0: bne         $at, $zero, L_80021BFC
    if (ctx->r1 != 0) {
        // 0x800219F4: addu        $a2, $s0, $s7
        ctx->r6 = ADD32(ctx->r16, ctx->r23);
            goto L_80021BFC;
    }
    // 0x800219F4: addu        $a2, $s0, $s7
    ctx->r6 = ADD32(ctx->r16, ctx->r23);
    // 0x800219F8: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x800219FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021A00: bne         $t8, $at, L_80021B30
    if (ctx->r24 != ctx->r1) {
        // 0x80021A04: addu        $v0, $s5, $s7
        ctx->r2 = ADD32(ctx->r21, ctx->r23);
            goto L_80021B30;
    }
    // 0x80021A04: addu        $v0, $s5, $s7
    ctx->r2 = ADD32(ctx->r21, ctx->r23);
    // 0x80021A08: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80021A0C: addu        $t3, $a3, $t9
    ctx->r11 = ADD32(ctx->r7, ctx->r25);
    // 0x80021A10: lw          $t4, -0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, -0X4);
    // 0x80021A14: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x80021A18: lw          $a1, 0x3C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X3C);
    // 0x80021A1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021A20: lb          $t5, 0x22($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X22);
    // 0x80021A24: addiu       $s0, $s5, -0x1
    ctx->r16 = ADD32(ctx->r21, -0X1);
    // 0x80021A28: bne         $t5, $at, L_80021A6C
    if (ctx->r13 != ctx->r1) {
        // 0x80021A2C: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80021A6C;
    }
    // 0x80021A2C: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80021A30: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x80021A34: nop

    // 0x80021A38: lb          $a0, 0x30($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X30);
    // 0x80021A3C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80021A40: jal         0x80066828
    // 0x80021A44: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    set_active_camera(rdram, ctx);
        goto after_0;
    // 0x80021A44: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80021A48: jal         0x80069F3C
    // 0x80021A4C: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_1;
    // 0x80021A4C: nop

    after_1:
    // 0x80021A50: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80021A54: lw          $a3, -0x4C0C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4C0C);
    // 0x80021A58: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80021A5C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80021A60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80021A64: b           L_80021A78
    // 0x80021A68: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
        goto L_80021A78;
    // 0x80021A68: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
L_80021A6C:
    // 0x80021A6C: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x80021A70: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021A74: nop

L_80021A78:
    // 0x80021A78: lw          $t7, -0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, -0X4);
    // 0x80021A7C: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80021A80: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80021A84: nop

    // 0x80021A88: sub.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80021A8C: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80021A90: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80021A94: lw          $t8, -0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, -0X4);
    // 0x80021A98: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80021A9C: lwc1        $f8, 0x10($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80021AA0: nop

    // 0x80021AA4: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80021AA8: add.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80021AAC: swc1        $f6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f6.u32l;
    // 0x80021AB0: lw          $t9, -0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, -0X4);
    // 0x80021AB4: lwc1        $f12, 0x14($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80021AB8: lwc1        $f4, 0x14($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80021ABC: nop

    // 0x80021AC0: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80021AC4: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80021AC8: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80021ACC: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80021AD0: nop

    // 0x80021AD4: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80021AD8: nop

    // 0x80021ADC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021AE0: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
    // 0x80021AE4: lh          $t4, 0x4($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X4);
    // 0x80021AE8: nop

    // 0x80021AEC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80021AF0: nop

    // 0x80021AF4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021AF8: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80021AFC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021B00: nop

    // 0x80021B04: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80021B08: nop

    // 0x80021B0C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80021B10: nop

    // 0x80021B14: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021B18: swc1        $f4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f4.u32l;
    // 0x80021B1C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80021B20: nop

    // 0x80021B24: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80021B28: b           L_80021D08
    // 0x80021B2C: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
        goto L_80021D08;
    // 0x80021B2C: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
L_80021B30:
    // 0x80021B30: lw          $t7, 0x138($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X138);
    // 0x80021B34: nop

    // 0x80021B38: addu        $t8, $s7, $t7
    ctx->r24 = ADD32(ctx->r23, ctx->r15);
    // 0x80021B3C: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80021B40: subu        $t3, $t9, $s5
    ctx->r11 = SUB32(ctx->r25, ctx->r21);
    // 0x80021B44: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80021B48: addu        $v0, $a3, $t4
    ctx->r2 = ADD32(ctx->r7, ctx->r12);
    // 0x80021B4C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80021B50: nop

    // 0x80021B54: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80021B58: nop

    // 0x80021B5C: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    // 0x80021B60: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80021B64: nop

    // 0x80021B68: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80021B6C: nop

    // 0x80021B70: swc1        $f6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f6.u32l;
    // 0x80021B74: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80021B78: nop

    // 0x80021B7C: lwc1        $f4, 0x14($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X14);
    // 0x80021B80: nop

    // 0x80021B84: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x80021B88: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80021B8C: nop

    // 0x80021B90: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80021B94: nop

    // 0x80021B98: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80021B9C: nop

    // 0x80021BA0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021BA4: swc1        $f10, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f10.u32l;
    // 0x80021BA8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80021BAC: nop

    // 0x80021BB0: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80021BB4: nop

    // 0x80021BB8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80021BBC: nop

    // 0x80021BC0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021BC4: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
    // 0x80021BC8: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80021BCC: nop

    // 0x80021BD0: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x80021BD4: nop

    // 0x80021BD8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80021BDC: nop

    // 0x80021BE0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021BE4: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80021BE8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80021BEC: nop

    // 0x80021BF0: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80021BF4: b           L_80021D08
    // 0x80021BF8: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_80021D08;
    // 0x80021BF8: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_80021BFC:
    // 0x80021BFC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80021C00: addu        $a0, $a3, $t8
    ctx->r4 = ADD32(ctx->r7, ctx->r24);
    // 0x80021C04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80021C08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021C0C: lw          $a1, 0x3C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X3C);
    // 0x80021C10: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80021C14: lb          $t9, 0x22($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X22);
    // 0x80021C18: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80021C1C: bne         $t9, $at, L_80021C60
    if (ctx->r25 != ctx->r1) {
        // 0x80021C20: nop
    
            goto L_80021C60;
    }
    // 0x80021C20: nop

    // 0x80021C24: lb          $a0, 0x30($t3)
    ctx->r4 = MEM_B(ctx->r11, 0X30);
    // 0x80021C28: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80021C2C: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80021C30: jal         0x80066828
    // 0x80021C34: sw          $a1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r5;
    set_active_camera(rdram, ctx);
        goto after_2;
    // 0x80021C34: sw          $a1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r5;
    after_2:
    // 0x80021C38: jal         0x80069F3C
    // 0x80021C3C: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_3;
    // 0x80021C3C: nop

    after_3:
    // 0x80021C40: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80021C44: lw          $a3, -0x4C0C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4C0C);
    // 0x80021C48: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80021C4C: lw          $a1, 0x150($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X150);
    // 0x80021C50: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80021C54: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80021C58: b           L_80021C60
    // 0x80021C5C: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
        goto L_80021C60;
    // 0x80021C5C: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
L_80021C60:
    // 0x80021C60: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80021C64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021C68: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80021C6C: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80021C70: nop

    // 0x80021C74: swc1        $f8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f8.u32l;
    // 0x80021C78: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80021C7C: nop

    // 0x80021C80: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80021C84: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x80021C88: nop

    // 0x80021C8C: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80021C90: nop

    // 0x80021C94: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021C98: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
    // 0x80021C9C: lh          $t5, 0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X4);
    // 0x80021CA0: nop

    // 0x80021CA4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80021CA8: nop

    // 0x80021CAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021CB0: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80021CB4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021CB8: nop

    // 0x80021CBC: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80021CC0: nop

    // 0x80021CC4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80021CC8: nop

    // 0x80021CCC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021CD0: swc1        $f4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f4.u32l;
    // 0x80021CD4: lb          $t7, 0x22($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X22);
    // 0x80021CD8: nop

    // 0x80021CDC: bne         $t7, $at, L_80021CF4
    if (ctx->r15 != ctx->r1) {
        // 0x80021CE0: nop
    
            goto L_80021CF4;
    }
    // 0x80021CE0: nop

    // 0x80021CE4: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80021CE8: nop

    // 0x80021CEC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80021CF0: swc1        $f10, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f10.u32l;
L_80021CF4:
    // 0x80021CF4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80021CF8: nop

    // 0x80021CFC: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80021D00: nop

    // 0x80021D04: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_80021D08:
    // 0x80021D08: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80021D0C: addiu       $t9, $sp, 0xE4
    ctx->r25 = ADD32(ctx->r29, 0XE4);
    // 0x80021D10: sltu        $at, $s1, $t9
    ctx->r1 = ctx->r17 < ctx->r25 ? 1 : 0;
    // 0x80021D14: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80021D18: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80021D1C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80021D20: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80021D24: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80021D28: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80021D2C: bne         $at, $zero, L_8002183C
    if (ctx->r1 != 0) {
        // 0x80021D30: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8002183C;
    }
    // 0x80021D30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80021D34: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80021D38: addiu       $s0, $sp, 0x124
    ctx->r16 = ADD32(ctx->r29, 0X124);
    // 0x80021D3C: lb          $t4, 0x3F($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X3F);
    // 0x80021D40: lwc1        $f0, 0x0($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80021D44: bne         $t4, $zero, L_80021D9C
    if (ctx->r12 != 0) {
        // 0x80021D48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80021D9C;
    }
    // 0x80021D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021D4C: addiu       $s0, $sp, 0x124
    ctx->r16 = ADD32(ctx->r29, 0X124);
    // 0x80021D50: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80021D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021D58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021D5C: jal         0x80022574
    // 0x80021D60: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_4;
    // 0x80021D60: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80021D64: addiu       $s1, $sp, 0x110
    ctx->r17 = ADD32(ctx->r29, 0X110);
    // 0x80021D68: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021D6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021D74: jal         0x80022574
    // 0x80021D78: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_5;
    // 0x80021D78: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80021D7C: addiu       $s2, $sp, 0xFC
    ctx->r18 = ADD32(ctx->r29, 0XFC);
    // 0x80021D80: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021D84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021D88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021D8C: jal         0x80022574
    // 0x80021D90: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_6;
    // 0x80021D90: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80021D94: b           L_80021DE0
    // 0x80021D98: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
        goto L_80021DE0;
    // 0x80021D98: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
L_80021D9C:
    // 0x80021D9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80021DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021DA4: jal         0x800228BC
    // 0x80021DA8: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    lerp(rdram, ctx);
        goto after_7;
    // 0x80021DA8: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80021DAC: addiu       $s1, $sp, 0x110
    ctx->r17 = ADD32(ctx->r29, 0X110);
    // 0x80021DB0: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021DB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021DB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021DBC: jal         0x800228BC
    // 0x80021DC0: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    lerp(rdram, ctx);
        goto after_8;
    // 0x80021DC0: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80021DC4: addiu       $s2, $sp, 0xFC
    ctx->r18 = ADD32(ctx->r29, 0XFC);
    // 0x80021DC8: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021DCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021DD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021DD4: jal         0x800228BC
    // 0x80021DD8: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    lerp(rdram, ctx);
        goto after_9;
    // 0x80021DD8: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80021DDC: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
L_80021DE0:
    // 0x80021DE0: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x80021DE4: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80021DE8: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80021DEC: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80021DF0: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80021DF4: swc1        $f10, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f10.u32l;
    // 0x80021DF8: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80021DFC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80021E00: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80021E04: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80021E08: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    // 0x80021E0C: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80021E10: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80021E14: sub.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80021E18: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80021E1C: jal         0x80011570
    // 0x80021E20: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    move_object(rdram, ctx);
        goto after_10;
    // 0x80021E20: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80021E24: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021E28: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x80021E2C: jal         0x80022574
    // 0x80021E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_11;
    // 0x80021E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80021E34: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80021E38: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x80021E3C: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80021E40: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80021E44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021E48: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80021E4C: nop

    // 0x80021E50: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80021E54: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x80021E58: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x80021E5C: nop

    // 0x80021E60: lbu         $v0, 0x2E($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X2E);
    // 0x80021E64: nop

    // 0x80021E68: beq         $v0, $at, L_80022538
    if (ctx->r2 == ctx->r1) {
        // 0x80021E6C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80022538;
    }
    // 0x80021E6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80021E70: beq         $v0, $at, L_80021E88
    if (ctx->r2 == ctx->r1) {
        // 0x80021E74: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80021E88;
    }
    // 0x80021E74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80021E78: beq         $v0, $at, L_80021FD4
    if (ctx->r2 == ctx->r1) {
        // 0x80021E7C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80021FD4;
    }
    // 0x80021E7C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021E80: b           L_80022104
    // 0x80021E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80022104;
    // 0x80021E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80021E88:
    // 0x80021E88: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x80021E8C: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021E90: lb          $t3, 0x3F($t9)
    ctx->r11 = MEM_B(ctx->r25, 0X3F);
    // 0x80021E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021E98: bne         $t3, $zero, L_80021EE4
    if (ctx->r11 != 0) {
        // 0x80021E9C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80021EE4;
    }
    // 0x80021E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021EA0: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021EA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021EAC: jal         0x80022670
    // 0x80021EB0: addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    cubic_spline_interpolation(rdram, ctx);
        goto after_12;
    // 0x80021EB0: addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    after_12:
    // 0x80021EB4: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021EC0: jal         0x80022670
    // 0x80021EC4: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    cubic_spline_interpolation(rdram, ctx);
        goto after_13;
    // 0x80021EC4: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    after_13:
    // 0x80021EC8: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021ECC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021ED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021ED4: jal         0x80022670
    // 0x80021ED8: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    cubic_spline_interpolation(rdram, ctx);
        goto after_14;
    // 0x80021ED8: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    after_14:
    // 0x80021EDC: b           L_80021F18
    // 0x80021EE0: lwc1        $f20, 0xF8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF8);
        goto L_80021F18;
    // 0x80021EE0: lwc1        $f20, 0xF8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF8);
L_80021EE4:
    // 0x80021EE4: jal         0x800228E4
    // 0x80021EE8: addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    lerp_and_get_derivative(rdram, ctx);
        goto after_15;
    // 0x80021EE8: addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    after_15:
    // 0x80021EEC: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021EF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021EF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021EF8: jal         0x800228E4
    // 0x80021EFC: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    lerp_and_get_derivative(rdram, ctx);
        goto after_16;
    // 0x80021EFC: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    after_16:
    // 0x80021F00: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021F04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021F08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021F0C: jal         0x800228E4
    // 0x80021F10: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    lerp_and_get_derivative(rdram, ctx);
        goto after_17;
    // 0x80021F10: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    after_17:
    // 0x80021F14: lwc1        $f20, 0xF8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF8);
L_80021F18:
    // 0x80021F18: lwc1        $f2, 0xF4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80021F1C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80021F20: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80021F24: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80021F28: nop

    // 0x80021F2C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80021F30: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80021F34: jal         0x800CA030
    // 0x80021F38: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_18;
    // 0x80021F38: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_18:
    // 0x80021F3C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80021F40: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80021F44: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80021F48: nop

    // 0x80021F4C: bc1t        L_80021F94
    if (c1cs) {
        // 0x80021F50: nop
    
            goto L_80021F94;
    }
    // 0x80021F50: nop

    // 0x80021F54: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80021F58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80021F5C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80021F60: nop

    // 0x80021F64: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x80021F68: lwc1        $f20, 0xF8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80021F6C: lwc1        $f2, 0xF4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80021F70: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80021F74: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80021F78: mul.s       $f20, $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x80021F7C: nop

    // 0x80021F80: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80021F84: swc1        $f20, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f20.u32l;
    // 0x80021F88: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80021F8C: swc1        $f2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f2.u32l;
    // 0x80021F90: swc1        $f14, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f14.u32l;
L_80021F94:
    // 0x80021F94: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80021F98: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80021F9C: jal         0x80070990
    // 0x80021FA0: nop

    arctan2_f(rdram, ctx);
        goto after_19;
    // 0x80021FA0: nop

    after_19:
    // 0x80021FA4: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80021FA8: lw          $t5, 0x154($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X154);
    // 0x80021FAC: addu        $t4, $v0, $at
    ctx->r12 = ADD32(ctx->r2, ctx->r1);
    // 0x80021FB0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80021FB4: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x80021FB8: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80021FBC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80021FC0: jal         0x80070990
    // 0x80021FC4: nop

    arctan2_f(rdram, ctx);
        goto after_20;
    // 0x80021FC4: nop

    after_20:
    // 0x80021FC8: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x80021FCC: b           L_80022538
    // 0x80021FD0: sh          $v0, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r2;
        goto L_80022538;
    // 0x80021FD0: sh          $v0, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r2;
L_80021FD4:
    // 0x80021FD4: lh          $v1, -0x4C08($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4C08);
    // 0x80021FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021FDC: blez        $v1, L_80022030
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80021FE0: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80022030;
    }
    // 0x80021FE0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80021FE4: lw          $a3, -0x4C0C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4C0C);
    // 0x80021FE8: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x80021FEC: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80021FF0: lb          $v0, 0x3E($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X3E);
    // 0x80021FF4: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x80021FF8: nop

    // 0x80021FFC: beq         $v0, $t9, L_80022030
    if (ctx->r2 == ctx->r25) {
        // 0x80022000: nop
    
            goto L_80022030;
    }
    // 0x80022000: nop

L_80022004:
    // 0x80022004: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80022008: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002200C: beq         $at, $zero, L_80022030
    if (ctx->r1 == 0) {
        // 0x80022010: sll         $t3, $a1, 2
        ctx->r11 = S32(ctx->r5 << 2);
            goto L_80022030;
    }
    // 0x80022010: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80022014: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80022018: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8002201C: nop

    // 0x80022020: lw          $t7, 0x7C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X7C);
    // 0x80022024: nop

    // 0x80022028: bne         $v0, $t7, L_80022004
    if (ctx->r2 != ctx->r15) {
        // 0x8002202C: nop
    
            goto L_80022004;
    }
    // 0x8002202C: nop

L_80022030:
    // 0x80022030: beq         $a1, $v1, L_80022538
    if (ctx->r5 == ctx->r3) {
        // 0x80022034: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80022538;
    }
    // 0x80022034: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80022038: lw          $t6, -0x4C0C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C0C);
    // 0x8002203C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80022040: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80022044: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80022048: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x8002204C: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x80022050: nop

    // 0x80022054: beq         $v1, $zero, L_8002253C
    if (ctx->r3 == 0) {
        // 0x80022058: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002253C;
    }
    // 0x80022058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002205C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80022060: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80022064: nop

    // 0x80022068: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8002206C: swc1        $f10, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f10.u32l;
    // 0x80022070: lwc1        $f6, 0x10($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X10);
    // 0x80022074: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80022078: nop

    // 0x8002207C: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80022080: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
    // 0x80022084: lwc1        $f8, 0x14($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X14);
    // 0x80022088: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8002208C: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80022090: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80022094: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80022098: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8002209C: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    // 0x800220A0: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800220A4: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800220A8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800220AC: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800220B0: jal         0x800CA030
    // 0x800220B4: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_21;
    // 0x800220B4: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_21:
    // 0x800220B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800220BC: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800220C0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800220C4: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800220C8: bc1f        L_80022538
    if (!c1cs) {
        // 0x800220CC: swc1        $f0, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
            goto L_80022538;
    }
    // 0x800220CC: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    // 0x800220D0: jal         0x80070990
    // 0x800220D4: nop

    arctan2_f(rdram, ctx);
        goto after_22;
    // 0x800220D4: nop

    after_22:
    // 0x800220D8: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x800220DC: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800220E0: addu        $t5, $v0, $at
    ctx->r13 = ADD32(ctx->r2, ctx->r1);
    // 0x800220E4: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x800220E8: lwc1        $f14, 0xEC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800220EC: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800220F0: jal         0x80070990
    // 0x800220F4: nop

    arctan2_f(rdram, ctx);
        goto after_23;
    // 0x800220F4: nop

    after_23:
    // 0x800220F8: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x800220FC: b           L_80022538
    // 0x80022100: sh          $v0, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r2;
        goto L_80022538;
    // 0x80022100: sh          $v0, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r2;
L_80022104:
    // 0x80022104: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x80022108: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8002210C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80022110: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80022114: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80022118: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8002211C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80022120: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80022124: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80022128: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8002212C: addiu       $fp, $sp, 0xC0
    ctx->r30 = ADD32(ctx->r29, 0XC0);
    // 0x80022130: addiu       $s6, $sp, 0xAC
    ctx->r22 = ADD32(ctx->r29, 0XAC);
    // 0x80022134: addiu       $t1, $sp, 0x98
    ctx->r9 = ADD32(ctx->r29, 0X98);
    // 0x80022138: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8002213C: addiu       $t0, $sp, 0xA8
    ctx->r8 = ADD32(ctx->r29, 0XA8);
    // 0x80022140: addiu       $a3, $sp, 0xBC
    ctx->r7 = ADD32(ctx->r29, 0XBC);
    // 0x80022144: addiu       $a2, $sp, 0xD0
    ctx->r6 = ADD32(ctx->r29, 0XD0);
L_80022148:
    // 0x80022148: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8002214C: lwc1        $f8, -0x4($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, -0X4);
    // 0x80022150: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80022154: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80022158: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x8002215C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80022160: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x80022164: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x80022168: bc1f        L_80022180
    if (!c1cs) {
        // 0x8002216C: subu        $a0, $t2, $a1
        ctx->r4 = SUB32(ctx->r10, ctx->r5);
            goto L_80022180;
    }
    // 0x8002216C: subu        $a0, $t2, $a1
    ctx->r4 = SUB32(ctx->r10, ctx->r5);
    // 0x80022170: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80022174: sub.d       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f4.d - ctx->f14.d;
    // 0x80022178: b           L_8002219C
    // 0x8002217C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
        goto L_8002219C;
    // 0x8002217C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80022180:
    // 0x80022180: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x80022184: nop

    // 0x80022188: bc1f        L_8002219C
    if (!c1cs) {
        // 0x8002218C: nop
    
            goto L_8002219C;
    }
    // 0x8002218C: nop

    // 0x80022190: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80022194: add.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d + ctx->f14.d;
    // 0x80022198: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_8002219C:
    // 0x8002219C: beq         $at, $zero, L_80022220
    if (ctx->r1 == 0) {
        // 0x800221A0: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_80022220;
    }
    // 0x800221A0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800221A4: andi        $t8, $a0, 0x3
    ctx->r24 = ctx->r4 & 0X3;
    // 0x800221A8: beq         $t8, $zero, L_800221D8
    if (ctx->r24 == 0) {
        // 0x800221AC: addu        $v1, $t8, $a1
        ctx->r3 = ADD32(ctx->r24, ctx->r5);
            goto L_800221D8;
    }
    // 0x800221AC: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x800221B0: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x800221B4: addiu       $t3, $sp, 0xBC
    ctx->r11 = ADD32(ctx->r29, 0XBC);
    // 0x800221B8: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
L_800221BC:
    // 0x800221BC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800221C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800221C4: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800221C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800221CC: bne         $v1, $s0, L_800221BC
    if (ctx->r3 != ctx->r16) {
        // 0x800221D0: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_800221BC;
    }
    // 0x800221D0: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800221D4: beq         $s0, $t2, L_8002221C
    if (ctx->r16 == ctx->r10) {
        // 0x800221D8: sll         $t4, $s0, 2
        ctx->r12 = S32(ctx->r16 << 2);
            goto L_8002221C;
    }
L_800221D8:
    // 0x800221D8: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800221DC: addiu       $t5, $sp, 0xBC
    ctx->r13 = ADD32(ctx->r29, 0XBC);
    // 0x800221E0: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_800221E4:
    // 0x800221E4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800221E8: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800221EC: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800221F0: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800221F4: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800221F8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800221FC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80022200: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80022204: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80022208: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002220C: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80022210: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80022214: bne         $v0, $a2, L_800221E4
    if (ctx->r2 != ctx->r6) {
        // 0x80022218: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_800221E4;
    }
    // 0x80022218: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
L_8002221C:
    // 0x8002221C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
L_80022220:
    // 0x80022220: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80022224: lwc1        $f8, -0x4($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, -0X4);
    // 0x80022228: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8002222C: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80022230: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80022234: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80022238: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x8002223C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x80022240: bc1f        L_80022258
    if (!c1cs) {
        // 0x80022244: addiu       $t7, $zero, 0x5
        ctx->r15 = ADD32(0, 0X5);
            goto L_80022258;
    }
    // 0x80022244: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80022248: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8002224C: sub.d       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f4.d - ctx->f14.d;
    // 0x80022250: b           L_80022274
    // 0x80022254: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
        goto L_80022274;
    // 0x80022254: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80022258:
    // 0x80022258: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x8002225C: nop

    // 0x80022260: bc1f        L_80022274
    if (!c1cs) {
        // 0x80022264: nop
    
            goto L_80022274;
    }
    // 0x80022264: nop

    // 0x80022268: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002226C: add.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d + ctx->f14.d;
    // 0x80022270: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80022274:
    // 0x80022274: beq         $at, $zero, L_800222F8
    if (ctx->r1 == 0) {
        // 0x80022278: subu        $a0, $t7, $a1
        ctx->r4 = SUB32(ctx->r15, ctx->r5);
            goto L_800222F8;
    }
    // 0x80022278: subu        $a0, $t7, $a1
    ctx->r4 = SUB32(ctx->r15, ctx->r5);
    // 0x8002227C: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x80022280: beq         $t6, $zero, L_800222B0
    if (ctx->r14 == 0) {
        // 0x80022284: addu        $v1, $t6, $a1
        ctx->r3 = ADD32(ctx->r14, ctx->r5);
            goto L_800222B0;
    }
    // 0x80022284: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x80022288: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8002228C: addiu       $t9, $sp, 0xA8
    ctx->r25 = ADD32(ctx->r29, 0XA8);
    // 0x80022290: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
L_80022294:
    // 0x80022294: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80022298: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002229C: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800222A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800222A4: bne         $v1, $s0, L_80022294
    if (ctx->r3 != ctx->r16) {
        // 0x800222A8: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80022294;
    }
    // 0x800222A8: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800222AC: beq         $s0, $t2, L_800222F4
    if (ctx->r16 == ctx->r10) {
        // 0x800222B0: sll         $t3, $s0, 2
        ctx->r11 = S32(ctx->r16 << 2);
            goto L_800222F4;
    }
L_800222B0:
    // 0x800222B0: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x800222B4: addiu       $t4, $sp, 0xA8
    ctx->r12 = ADD32(ctx->r29, 0XA8);
    // 0x800222B8: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_800222BC:
    // 0x800222BC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800222C0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800222C4: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800222C8: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800222CC: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800222D0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800222D4: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800222D8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800222DC: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800222E0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800222E4: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800222E8: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800222EC: bne         $v0, $a3, L_800222BC
    if (ctx->r2 != ctx->r7) {
        // 0x800222F0: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_800222BC;
    }
    // 0x800222F0: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
L_800222F4:
    // 0x800222F4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
L_800222F8:
    // 0x800222F8: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800222FC: lwc1        $f8, -0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, -0X4);
    // 0x80022300: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80022304: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80022308: subu        $a0, $t5, $a1
    ctx->r4 = SUB32(ctx->r13, ctx->r5);
    // 0x8002230C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80022310: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x80022314: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x80022318: bc1f        L_80022330
    if (!c1cs) {
        // 0x8002231C: slti        $at, $a1, 0x5
        ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
            goto L_80022330;
    }
    // 0x8002231C: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80022320: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80022324: sub.d       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f4.d - ctx->f14.d;
    // 0x80022328: b           L_8002234C
    // 0x8002232C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
        goto L_8002234C;
    // 0x8002232C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80022330:
    // 0x80022330: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x80022334: nop

    // 0x80022338: bc1f        L_8002234C
    if (!c1cs) {
        // 0x8002233C: nop
    
            goto L_8002234C;
    }
    // 0x8002233C: nop

    // 0x80022340: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80022344: add.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d + ctx->f14.d;
    // 0x80022348: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_8002234C:
    // 0x8002234C: beq         $at, $zero, L_800223C8
    if (ctx->r1 == 0) {
        // 0x80022350: andi        $t7, $a0, 0x3
        ctx->r15 = ctx->r4 & 0X3;
            goto L_800223C8;
    }
    // 0x80022350: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x80022354: beq         $t7, $zero, L_80022384
    if (ctx->r15 == 0) {
        // 0x80022358: addu        $v1, $t7, $a1
        ctx->r3 = ADD32(ctx->r15, ctx->r5);
            goto L_80022384;
    }
    // 0x80022358: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x8002235C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80022360: addiu       $t8, $sp, 0x94
    ctx->r24 = ADD32(ctx->r29, 0X94);
    // 0x80022364: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
L_80022368:
    // 0x80022368: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002236C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80022370: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80022374: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022378: bne         $v1, $s0, L_80022368
    if (ctx->r3 != ctx->r16) {
        // 0x8002237C: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80022368;
    }
    // 0x8002237C: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80022380: beq         $s0, $t2, L_800223C8
    if (ctx->r16 == ctx->r10) {
        // 0x80022384: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_800223C8;
    }
L_80022384:
    // 0x80022384: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80022388: addiu       $t3, $sp, 0x94
    ctx->r11 = ADD32(ctx->r29, 0X94);
    // 0x8002238C: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
L_80022390:
    // 0x80022390: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80022394: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80022398: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8002239C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800223A0: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800223A4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800223A8: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800223AC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800223B0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800223B4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800223B8: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800223BC: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800223C0: bne         $v0, $t0, L_80022390
    if (ctx->r2 != ctx->r8) {
        // 0x800223C4: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80022390;
    }
    // 0x800223C4: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
L_800223C8:
    // 0x800223C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800223CC: bne         $a1, $t2, L_80022148
    if (ctx->r5 != ctx->r10) {
        // 0x800223D0: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_80022148;
    }
    // 0x800223D0: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800223D4: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x800223D8: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x800223DC: lb          $t5, 0x3F($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X3F);
    // 0x800223E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800223E4: bne         $t5, $zero, L_80022494
    if (ctx->r13 != 0) {
        // 0x800223E8: addiu       $a0, $sp, 0xBC
        ctx->r4 = ADD32(ctx->r29, 0XBC);
            goto L_80022494;
    }
    // 0x800223E8: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x800223EC: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x800223F0: jal         0x80022574
    // 0x800223F4: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    catmull_rom_interpolation(rdram, ctx);
        goto after_24;
    // 0x800223F4: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    after_24:
    // 0x800223F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800223FC: lw          $t8, 0x154($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X154);
    // 0x80022400: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80022404: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022408: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002240C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80022410: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80022414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80022418: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8002241C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80022420: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x80022424: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80022428: jal         0x80022574
    // 0x8002242C: nop

    catmull_rom_interpolation(rdram, ctx);
        goto after_25;
    // 0x8002242C: nop

    after_25:
    // 0x80022430: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80022434: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x80022438: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002243C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022440: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022444: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80022448: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8002244C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80022450: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80022454: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80022458: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x8002245C: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80022460: jal         0x80022574
    // 0x80022464: nop

    catmull_rom_interpolation(rdram, ctx);
        goto after_26;
    // 0x80022464: nop

    after_26:
    // 0x80022468: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002246C: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x80022470: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80022474: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022478: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002247C: nop

    // 0x80022480: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80022484: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80022488: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002248C: b           L_80022538
    // 0x80022490: sh          $t7, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r15;
        goto L_80022538;
    // 0x80022490: sh          $t7, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r15;
L_80022494:
    // 0x80022494: jal         0x800228BC
    // 0x80022498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lerp(rdram, ctx);
        goto after_27;
    // 0x80022498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x8002249C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800224A0: lw          $t3, 0x154($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X154);
    // 0x800224A4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800224A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800224AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800224B0: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x800224B4: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800224B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800224BC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800224C0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800224C4: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
    // 0x800224C8: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x800224CC: jal         0x800228BC
    // 0x800224D0: nop

    lerp(rdram, ctx);
        goto after_28;
    // 0x800224D0: nop

    after_28:
    // 0x800224D4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800224D8: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x800224DC: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800224E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800224E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800224E8: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x800224EC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800224F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800224F4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800224F8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800224FC: sh          $t5, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r13;
    // 0x80022500: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80022504: jal         0x800228BC
    // 0x80022508: nop

    lerp(rdram, ctx);
        goto after_29;
    // 0x80022508: nop

    after_29:
    // 0x8002250C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80022510: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x80022514: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80022518: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002251C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022520: nop

    // 0x80022524: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80022528: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8002252C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80022530: sh          $t8, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r24;
    // 0x80022534: nop

L_80022538:
    // 0x80022538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002253C:
    // 0x8002253C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80022540: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80022544: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80022548: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002254C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80022550: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80022554: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80022558: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002255C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80022560: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80022564: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80022568: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8002256C: jr          $ra
    // 0x80022570: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x80022570: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
;}
RECOMP_FUNC void catmull_rom_interpolation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022574: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80022578: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002257C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80022580: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80022584: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80022588: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8002258C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80022590: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80022594: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80022598: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002259C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800225A0: cvt.d.s     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f12.d = CVT_D_S(ctx->f6.fl);
    // 0x800225A4: mul.d       $f14, $f8, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f14.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800225A8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800225AC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800225B0: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800225B4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800225B8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800225BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800225C0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800225C4: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x800225C8: lui         $at, 0xBFF8
    ctx->r1 = S32(0XBFF8 << 16);
    // 0x800225CC: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800225D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800225D4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800225D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800225DC: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800225E0: add.d       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f14.d + ctx->f8.d;
    // 0x800225E4: lui         $at, 0xC004
    ctx->r1 = S32(0XC004 << 16);
    // 0x800225E8: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x800225EC: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x800225F0: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x800225F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800225F8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800225FC: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80022600: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80022604: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80022608: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x8002260C: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x80022610: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x80022614: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x80022618: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002261C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80022620: nop

    // 0x80022624: mul.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x80022628: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x8002262C: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80022630: mul.d       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x80022634: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80022638: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x8002263C: add.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f8.d + ctx->f14.d;
    // 0x80022640: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80022644: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80022648: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x8002264C: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80022650: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80022654: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80022658: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002265C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80022660: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80022664: add.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80022668: jr          $ra
    // 0x8002266C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8002266C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void cubic_spline_interpolation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022670: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022674: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80022678: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8002267C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80022680: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80022684: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x80022688: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8002268C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80022690: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80022694: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80022698: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002269C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800226A0: cvt.d.s     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f12.d = CVT_D_S(ctx->f6.fl);
    // 0x800226A4: mul.d       $f14, $f8, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f14.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800226A8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800226AC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800226B0: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800226B4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800226B8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800226BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800226C0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800226C4: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x800226C8: lui         $at, 0xBFF8
    ctx->r1 = S32(0XBFF8 << 16);
    // 0x800226CC: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800226D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800226D4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800226D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800226DC: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800226E0: add.d       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f14.d + ctx->f8.d;
    // 0x800226E4: lui         $at, 0xC004
    ctx->r1 = S32(0XC004 << 16);
    // 0x800226E8: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800226EC: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x800226F0: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x800226F4: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x800226F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800226FC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80022700: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80022704: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80022708: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8002270C: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x80022710: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80022714: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x80022718: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x8002271C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80022720: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80022724: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80022728: mul.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x8002272C: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    // 0x80022730: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x80022734: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80022738: mul.d       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x8002273C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80022740: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80022744: add.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f8.d + ctx->f14.d;
    // 0x80022748: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8002274C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80022750: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    // 0x80022754: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80022758: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002275C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80022760: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80022764: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80022768: nop

    // 0x8002276C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80022770: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80022774: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80022778: nop

    // 0x8002277C: mul.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80022780: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80022784: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x80022788: add.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8002278C: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x80022790: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80022794: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80022798: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8002279C: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800227A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800227A4: add.s       $f2, $f10, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800227A8: jr          $ra
    // 0x800227AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800227AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void catmull_rom_derivative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800227B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800227B4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800227B8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800227BC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800227C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800227C4: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800227C8: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800227CC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x800227D0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800227D4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800227D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800227DC: cvt.d.s     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f12.d = CVT_D_S(ctx->f10.fl);
    // 0x800227E0: mul.d       $f14, $f6, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f14.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800227E4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800227E8: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800227EC: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800227F0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800227F4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800227F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800227FC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80022800: mul.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80022804: lui         $at, 0xBFF8
    ctx->r1 = S32(0XBFF8 << 16);
    // 0x80022808: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8002280C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80022810: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80022814: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80022818: mul.d       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8002281C: add.d       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f14.d + ctx->f6.d;
    // 0x80022820: lui         $at, 0xC004
    ctx->r1 = S32(0XC004 << 16);
    // 0x80022824: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x80022828: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x8002282C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80022830: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80022834: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80022838: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002283C: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80022840: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80022844: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x80022848: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x8002284C: add.d       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f12.d + ctx->f6.d;
    // 0x80022850: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x80022854: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80022858: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002285C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80022860: mul.d       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x80022864: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80022868: mul.d       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x8002286C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80022870: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x80022874: add.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d + ctx->f14.d;
    // 0x80022878: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8002287C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80022880: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80022884: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80022888: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002288C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80022890: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x80022894: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80022898: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002289C: nop

    // 0x800228A0: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800228A4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800228A8: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800228AC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800228B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800228B4: jr          $ra
    // 0x800228B8: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
    return;
    // 0x800228B8: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
;}
RECOMP_FUNC void lerp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800228BC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800228C0: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800228C4: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800228C8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800228CC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800228D0: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800228D4: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800228D8: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800228DC: jr          $ra
    // 0x800228E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800228E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void lerp_and_get_derivative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800228E4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800228E8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800228EC: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800228F0: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800228F4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800228F8: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800228FC: sub.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80022900: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80022904: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
    // 0x80022908: jr          $ra
    // 0x8002290C: add.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f8.fl;
    return;
    // 0x8002290C: add.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f8.fl;
;}
RECOMP_FUNC void func_800228DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022910: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80022914: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80022918: jr          $ra
    // 0x8002291C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x8002291C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void init_racer_for_challenge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022928: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002292C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80022930: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022934: sb          $t6, -0x4B89($at)
    MEM_B(-0X4B89, ctx->r1) = ctx->r14;
    // 0x80022938: jal         0x8001BAFC
    // 0x8002293C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x8002293C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80022940: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80022944: nop

    // 0x80022948: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x8002294C: sb          $zero, 0x192($v1)
    MEM_B(0X192, ctx->r3) = 0;
    // 0x80022950: sb          $zero, 0x193($v1)
    MEM_B(0X193, ctx->r3) = 0;
    // 0x80022954: sh          $zero, 0x1BA($v1)
    MEM_H(0X1BA, ctx->r3) = 0;
    // 0x80022958: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002295C: jal         0x80017EA8
    // 0x80022960: nop

    set_taj_challenge_type(rdram, ctx);
        goto after_1;
    // 0x80022960: nop

    after_1:
    // 0x80022964: jal         0x8006F5C8
    // 0x80022968: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    set_pause_lockout_timer(rdram, ctx);
        goto after_2;
    // 0x80022968: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x8002296C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022974: jr          $ra
    // 0x80022978: nop

    return;
    // 0x80022978: nop

;}
RECOMP_FUNC void mode_init_taj_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002297C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022980: addiu       $v0, $v0, -0x4B89
    ctx->r2 = ADD32(ctx->r2, -0X4B89);
    // 0x80022984: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x80022988: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8002298C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80022990: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80022994: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x80022998: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002299C: bne         $t8, $zero, L_80022D20
    if (ctx->r24 != 0) {
        // 0x800229A0: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80022D20;
    }
    // 0x800229A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800229A4: jal         0x8006BFF0
    // 0x800229A8: nop

    level_header(rdram, ctx);
        goto after_0;
    // 0x800229A8: nop

    after_0:
    // 0x800229AC: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x800229B0: lbu         $t9, 0x52($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X52);
    // 0x800229B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800229B8: sb          $t9, -0x4B88($at)
    MEM_B(-0X4B88, ctx->r1) = ctx->r25;
    // 0x800229BC: lhu         $t1, 0x54($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X54);
    // 0x800229C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800229C4: addiu       $t2, $zero, 0x1D
    ctx->r10 = ADD32(0, 0X1D);
    // 0x800229C8: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x800229CC: sw          $t1, -0x4B84($at)
    MEM_W(-0X4B84, ctx->r1) = ctx->r9;
    // 0x800229D0: sb          $t2, 0x52($v0)
    MEM_B(0X52, ctx->r2) = ctx->r10;
    // 0x800229D4: sh          $t3, 0x54($v0)
    MEM_H(0X54, ctx->r2) = ctx->r11;
    // 0x800229D8: jal         0x8001BAFC
    // 0x800229DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_1;
    // 0x800229DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800229E0: lw          $s0, 0x64($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X64);
    // 0x800229E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800229E8: lb          $t4, 0x1D6($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D6);
    // 0x800229EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800229F0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800229F4: sb          $t5, -0x4B8A($at)
    MEM_B(-0X4B8A, ctx->r1) = ctx->r13;
    // 0x800229F8: jal         0x80023104
    // 0x800229FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800230D0(rdram, ctx);
        goto after_2;
    // 0x800229FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80022A00: lh          $t6, 0x1A0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A0);
    // 0x80022A04: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80022A08: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80022A0C: sh          $t8, 0x196($s0)
    MEM_H(0X196, ctx->r16) = ctx->r24;
    // 0x80022A10: sb          $zero, 0x1FC($s0)
    MEM_B(0X1FC, ctx->r16) = 0;
    // 0x80022A14: sb          $zero, 0x1F4($s0)
    MEM_B(0X1F4, ctx->r16) = 0;
    // 0x80022A18: sh          $zero, 0x190($s0)
    MEM_H(0X190, ctx->r16) = 0;
    // 0x80022A1C: sb          $zero, 0x192($s0)
    MEM_B(0X192, ctx->r16) = 0;
    // 0x80022A20: sb          $zero, 0x193($s0)
    MEM_B(0X193, ctx->r16) = 0;
    // 0x80022A24: sb          $zero, 0x194($s0)
    MEM_B(0X194, ctx->r16) = 0;
    // 0x80022A28: sw          $zero, 0x128($s0)
    MEM_W(0X128, ctx->r16) = 0;
    // 0x80022A2C: sw          $zero, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = 0;
    // 0x80022A30: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80022A34: sh          $zero, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = 0;
    // 0x80022A38: jal         0x8006ECD0
    // 0x80022A3C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_3;
    // 0x80022A3C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80022A40: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80022A44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022A48: sw          $t9, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = ctx->r25;
    // 0x80022A4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022A50: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x80022A54: sw          $zero, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = 0;
    // 0x80022A58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022A5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80022A60: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80022A64: sw          $t1, -0x4CC0($at)
    MEM_W(-0X4CC0, ctx->r1) = ctx->r9;
    // 0x80022A68: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80022A6C: sb          $t2, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r10;
    // 0x80022A70: jal         0x8009F574
    // 0x80022A74: sb          $zero, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = 0;
    hud_init_element(rdram, ctx);
        goto after_4;
    // 0x80022A74: sb          $zero, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = 0;
    after_4:
    // 0x80022A78: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80022A7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022A80: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_80022A84:
    // 0x80022A84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022A88: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80022A8C: sw          $zero, 0x128($v1)
    MEM_W(0X128, ctx->r3) = 0;
    // 0x80022A90: bne         $at, $zero, L_80022A84
    if (ctx->r1 != 0) {
        // 0x80022A94: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80022A84;
    }
    // 0x80022A94: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80022A98: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80022A9C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80022AA0: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80022AA4: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80022AA8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80022AAC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80022AB0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80022AB4: nop

    // 0x80022AB8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80022ABC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022AC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022AC4: nop

    // 0x80022AC8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80022ACC: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80022AD0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80022AD4: sh          $t4, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r12;
    // 0x80022AD8: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80022ADC: lwc1        $f18, 0x18($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80022AE0: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80022AE4: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x80022AE8: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80022AEC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80022AF0: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80022AF4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80022AF8: nop

    // 0x80022AFC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80022B00: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022B04: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022B08: nop

    // 0x80022B0C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80022B10: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80022B14: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80022B18: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80022B1C: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80022B20: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80022B24: sh          $t7, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r15;
    // 0x80022B28: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80022B2C: lwc1        $f14, 0x14($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80022B30: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x80022B34: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80022B38: jal         0x80029F58
    // 0x80022B3C: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    get_level_segment_index_from_position(rdram, ctx);
        goto after_5;
    // 0x80022B3C: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_5:
    // 0x80022B40: lh          $t2, 0x5A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5A);
    // 0x80022B44: lh          $t3, 0x5E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X5E);
    // 0x80022B48: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80022B4C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80022B50: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80022B54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80022B58: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x80022B5C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80022B60: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80022B64: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80022B68: jal         0x8002BAF0
    // 0x80022B6C: nop

    collision_get_y(rdram, ctx);
        goto after_6;
    // 0x80022B6C: nop

    after_6:
    // 0x80022B70: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80022B74: beq         $v0, $zero, L_80022BA8
    if (ctx->r2 == 0) {
        // 0x80022B78: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_80022BA8;
    }
    // 0x80022B78: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80022B7C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80022B80: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80022B84: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80022B88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022B8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022B90: nop

    // 0x80022B94: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80022B98: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80022B9C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80022BA0: b           L_80022BD4
    // 0x80022BA4: sh          $t4, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r12;
        goto L_80022BD4;
    // 0x80022BA4: sh          $t4, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r12;
L_80022BA8:
    // 0x80022BA8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80022BAC: lwc1        $f16, 0x14($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80022BB0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80022BB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022BB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022BBC: nop

    // 0x80022BC0: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80022BC4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80022BC8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80022BCC: sh          $t8, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r24;
    // 0x80022BD0: nop

L_80022BD4:
    // 0x80022BD4: sb          $t7, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r15;
    // 0x80022BD8: lh          $t9, 0x1A0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A0);
    // 0x80022BDC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80022BE0: addiu       $t2, $zero, 0xDA
    ctx->r10 = ADD32(0, 0XDA);
    // 0x80022BE4: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x80022BE8: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x80022BEC: sh          $t1, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r9;
    // 0x80022BF0: sb          $t2, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r10;
    // 0x80022BF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022BF8: jal         0x80061C34
    // 0x80022BFC: sh          $t9, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r25;
    model_anim_offset(rdram, ctx);
        goto after_7;
    // 0x80022BFC: sh          $t9, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r25;
    after_7:
    // 0x80022C00: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80022C04: jal         0x8000EA54
    // 0x80022C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_8;
    // 0x80022C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80022C0C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80022C10: lw          $t3, -0x4B9C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4B9C);
    // 0x80022C14: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80022C18: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x80022C1C: lw          $t5, -0x4B98($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4B98);
    // 0x80022C20: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80022C24: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x80022C28: lw          $t4, -0x4B94($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4B94);
    // 0x80022C2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80022C30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80022C34: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80022C38: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80022C3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022C40: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80022C44: sw          $t6, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = ctx->r14;
    // 0x80022C48: lw          $s0, 0x64($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X64);
    // 0x80022C4C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80022C50: sb          $t8, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r24;
    // 0x80022C54: lb          $t7, 0x1D6($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D6);
    // 0x80022C58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80022C5C: sb          $t9, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r25;
    // 0x80022C60: sb          $t7, 0x1D7($s0)
    MEM_B(0X1D7, ctx->r16) = ctx->r15;
    // 0x80022C64: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80022C68: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80022C6C: lb          $t2, 0x59($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X59);
    // 0x80022C70: swc1        $f0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f0.u32l;
    // 0x80022C74: swc1        $f0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f0.u32l;
    // 0x80022C78: sb          $t3, 0x1F7($s0)
    MEM_B(0X1F7, ctx->r16) = ctx->r11;
    // 0x80022C7C: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
    // 0x80022C80: sb          $t2, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r10;
    // 0x80022C84: lw          $t4, 0x4C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4C);
    // 0x80022C88: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80022C8C: sb          $t5, 0x12($t4)
    MEM_B(0X12, ctx->r12) = ctx->r13;
    // 0x80022C90: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80022C94: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80022C98: lw          $a1, -0x4C24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4C24);
    // 0x80022C9C: lw          $a0, -0x4C20($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C20);
    // 0x80022CA0: addiu       $a3, $zero, 0x3E
    ctx->r7 = ADD32(0, 0X3E);
    // 0x80022CA4: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022CA8: beq         $at, $zero, L_80022D0C
    if (ctx->r1 == 0) {
        // 0x80022CAC: sll         $v1, $a0, 2
        ctx->r3 = S32(ctx->r4 << 2);
            goto L_80022D0C;
    }
    // 0x80022CAC: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80022CB0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80022CB4: addiu       $a2, $a2, -0x4C28
    ctx->r6 = ADD32(ctx->r6, -0X4C28);
L_80022CB8:
    // 0x80022CB8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80022CBC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80022CC0: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x80022CC4: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80022CC8: nop

    // 0x80022CCC: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x80022CD0: nop

    // 0x80022CD4: andi        $t9, $t7, 0x8000
    ctx->r25 = ctx->r15 & 0X8000;
    // 0x80022CD8: bne         $t9, $zero, L_80022D04
    if (ctx->r25 != 0) {
        // 0x80022CDC: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80022D04;
    }
    // 0x80022CDC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022CE0: lh          $t1, 0x48($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X48);
    // 0x80022CE4: nop

    // 0x80022CE8: bne         $a3, $t1, L_80022D04
    if (ctx->r7 != ctx->r9) {
        // 0x80022CEC: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80022D04;
    }
    // 0x80022CEC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022CF0: sw          $v0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r2;
    // 0x80022CF4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80022CF8: lw          $a1, -0x4C24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4C24);
    // 0x80022CFC: nop

    // 0x80022D00: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80022D04:
    // 0x80022D04: bne         $at, $zero, L_80022CB8
    if (ctx->r1 != 0) {
        // 0x80022D08: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80022CB8;
    }
    // 0x80022D08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80022D0C:
    // 0x80022D0C: jal         0x8006F5C8
    // 0x80022D10: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    set_pause_lockout_timer(rdram, ctx);
        goto after_9;
    // 0x80022D10: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_9:
    // 0x80022D14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80022D18: jal         0x800C06F8
    // 0x80022D1C: addiu       $a0, $a0, -0x33A0
    ctx->r4 = ADD32(ctx->r4, -0X33A0);
    transition_begin(rdram, ctx);
        goto after_10;
    // 0x80022D1C: addiu       $a0, $a0, -0x33A0
    ctx->r4 = ADD32(ctx->r4, -0X33A0);
    after_10:
L_80022D20:
    // 0x80022D20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022D24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022D28: jr          $ra
    // 0x80022D2C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80022D2C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void obj_taj_create_balloon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022D30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80022D34: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80022D38: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80022D3C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80022D40: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80022D44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80022D48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80022D4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80022D50: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80022D54: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x80022D58: jal         0x8006ECD0
    // 0x80022D5C: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80022D5C: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80022D60: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80022D64: lw          $t0, -0x4C24($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4C24);
    // 0x80022D68: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80022D6C: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80022D70: blez        $t0, L_80022E34
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80022D74: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80022E34;
    }
    // 0x80022D74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80022D78: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80022D7C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80022D80: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80022D84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80022D88: addiu       $t1, $t1, -0x4C28
    ctx->r9 = ADD32(ctx->r9, -0X4C28);
    // 0x80022D8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80022D90: addiu       $t2, $zero, 0x4D
    ctx->r10 = ADD32(0, 0X4D);
L_80022D94:
    // 0x80022D94: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80022D98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80022D9C: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80022DA0: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80022DA4: nop

    // 0x80022DA8: lh          $t8, 0x48($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X48);
    // 0x80022DAC: nop

    // 0x80022DB0: bne         $t2, $t8, L_80022E2C
    if (ctx->r10 != ctx->r24) {
        // 0x80022DB4: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80022E2C;
    }
    // 0x80022DB4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80022DB8: lw          $a0, 0x3C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X3C);
    // 0x80022DBC: nop

    // 0x80022DC0: beq         $a0, $zero, L_80022E2C
    if (ctx->r4 == 0) {
        // 0x80022DC4: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80022E2C;
    }
    // 0x80022DC4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80022DC8: lb          $a1, 0xA($a0)
    ctx->r5 = MEM_B(ctx->r4, 0XA);
    // 0x80022DCC: nop

    // 0x80022DD0: blez        $a1, L_80022E2C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80022DD4: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80022E2C;
    }
    // 0x80022DD4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80022DD8: lhu         $a0, 0x14($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X14);
    // 0x80022DDC: addiu       $t9, $a1, 0x2
    ctx->r25 = ADD32(ctx->r5, 0X2);
    // 0x80022DE0: beq         $a0, $zero, L_80022E28
    if (ctx->r4 == 0) {
        // 0x80022DE4: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80022E28;
    }
    // 0x80022DE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80022DE8: sllv        $t4, $t3, $t9
    ctx->r12 = S32(ctx->r11 << (ctx->r25 & 31));
    // 0x80022DEC: and         $t5, $a0, $t4
    ctx->r13 = ctx->r4 & ctx->r12;
    // 0x80022DF0: beq         $t5, $zero, L_80022E2C
    if (ctx->r13 == 0) {
        // 0x80022DF4: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80022E2C;
    }
    // 0x80022DF4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80022DF8: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80022DFC: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x80022E00: swc1        $f12, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f12.u32l;
    // 0x80022E04: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80022E08: swc1        $f20, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f20.u32l;
    // 0x80022E0C: swc1        $f8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f8.u32l;
    // 0x80022E10: sh          $s0, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = ctx->r16;
    // 0x80022E14: sw          $zero, 0x78($v1)
    MEM_W(0X78, ctx->r3) = 0;
    // 0x80022E18: sb          $zero, 0x39($v1)
    MEM_B(0X39, ctx->r3) = 0;
    // 0x80022E1C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80022E20: lw          $t0, -0x4C24($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4C24);
    // 0x80022E24: nop

L_80022E28:
    // 0x80022E28: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
L_80022E2C:
    // 0x80022E2C: bne         $at, $zero, L_80022D94
    if (ctx->r1 != 0) {
        // 0x80022E30: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80022D94;
    }
    // 0x80022E30: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80022E34:
    // 0x80022E34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80022E38: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80022E3C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80022E40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80022E44: jr          $ra
    // 0x80022E48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80022E48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mode_end_taj_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022E4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80022E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022E54: jal         0x8006BFF0
    // 0x80022E58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80022E58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80022E5C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80022E60: sb          $t6, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r14;
    // 0x80022E64: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80022E68: lb          $t7, -0x4B88($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X4B88);
    // 0x80022E6C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80022E70: sb          $t7, 0x52($v0)
    MEM_B(0X52, ctx->r2) = ctx->r15;
    // 0x80022E74: lw          $t8, -0x4B84($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4B84);
    // 0x80022E78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80022E7C: jal         0x800AB708
    // 0x80022E80: sh          $t8, 0x54($v0)
    MEM_H(0X54, ctx->r2) = ctx->r24;
    minimap_opacity_set(rdram, ctx);
        goto after_1;
    // 0x80022E80: sh          $t8, 0x54($v0)
    MEM_H(0X54, ctx->r2) = ctx->r24;
    after_1:
    // 0x80022E84: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80022E88: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80022E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80022E90: addiu       $a2, $a2, -0x4B90
    ctx->r6 = ADD32(ctx->r6, -0X4B90);
    // 0x80022E94: addiu       $a3, $a3, -0x4B9C
    ctx->r7 = ADD32(ctx->r7, -0X4B9C);
    // 0x80022E98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80022E9C:
    // 0x80022E9C: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80022EA0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80022EA4: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80022EA8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80022EAC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022EB0: lw          $v1, 0x64($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X64);
    // 0x80022EB4: nop

    // 0x80022EB8: sb          $zero, 0x1D8($v1)
    MEM_B(0X1D8, ctx->r3) = 0;
    // 0x80022EBC: sb          $zero, 0x193($v1)
    MEM_B(0X193, ctx->r3) = 0;
    // 0x80022EC0: sb          $zero, 0x192($v1)
    MEM_B(0X192, ctx->r3) = 0;
    // 0x80022EC4: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x80022EC8: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80022ECC: nop

    // 0x80022ED0: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80022ED4: bne         $at, $zero, L_80022E9C
    if (ctx->r1 != 0) {
        // 0x80022ED8: nop
    
            goto L_80022E9C;
    }
    // 0x80022ED8: nop

    // 0x80022EDC: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80022EE0: nop

    // 0x80022EE4: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x80022EE8: jal         0x8000FFB8
    // 0x80022EEC: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x80022EEC: nop

    after_2:
    // 0x80022EF0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80022EF4: addiu       $a3, $a3, -0x4B9C
    ctx->r7 = ADD32(ctx->r7, -0X4B9C);
    // 0x80022EF8: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80022EFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80022F00: lw          $t6, -0x4B98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B98);
    // 0x80022F04: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80022F08: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80022F0C: addiu       $a2, $a2, -0x4B90
    ctx->r6 = ADD32(ctx->r6, -0X4B90);
    // 0x80022F10: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80022F14: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80022F18: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80022F1C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80022F20: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80022F24: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x80022F28: lw          $a1, -0x4C20($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4C20);
    // 0x80022F2C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80022F30: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022F34: beq         $at, $zero, L_80022F84
    if (ctx->r1 == 0) {
        // 0x80022F38: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_80022F84;
    }
    // 0x80022F38: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80022F3C: lw          $t8, -0x4C28($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4C28);
    // 0x80022F40: sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3 << 2);
    // 0x80022F44: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80022F48: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
L_80022F4C:
    // 0x80022F4C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80022F50: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022F54: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x80022F58: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80022F5C: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x80022F60: bne         $t0, $zero, L_80022F7C
    if (ctx->r8 != 0) {
        // 0x80022F64: nop
    
            goto L_80022F7C;
    }
    // 0x80022F64: nop

    // 0x80022F68: lh          $t1, 0x48($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X48);
    // 0x80022F6C: nop

    // 0x80022F70: bne         $a1, $t1, L_80022F7C
    if (ctx->r5 != ctx->r9) {
        // 0x80022F74: nop
    
            goto L_80022F7C;
    }
    // 0x80022F74: nop

    // 0x80022F78: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_80022F7C:
    // 0x80022F7C: bne         $at, $zero, L_80022F4C
    if (ctx->r1 != 0) {
        // 0x80022F80: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80022F4C;
    }
    // 0x80022F80: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80022F84:
    // 0x80022F84: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80022F88: nop

    // 0x80022F8C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80022F90: nop

    // 0x80022F94: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x80022F98: nop

    // 0x80022F9C: lw          $a0, 0x15C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X15C);
    // 0x80022FA0: nop

    // 0x80022FA4: beq         $a0, $zero, L_80022FC4
    if (ctx->r4 == 0) {
        // 0x80022FA8: lw          $t4, 0x30($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X30);
            goto L_80022FC4;
    }
    // 0x80022FA8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80022FAC: jal         0x8000FFB8
    // 0x80022FB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    free_object(rdram, ctx);
        goto after_3;
    // 0x80022FB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x80022FB4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80022FB8: nop

    // 0x80022FBC: sw          $zero, 0x15C($v1)
    MEM_W(0X15C, ctx->r3) = 0;
    // 0x80022FC0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80022FC4:
    // 0x80022FC4: nop

    // 0x80022FC8: bne         $t4, $zero, L_8002307C
    if (ctx->r12 != 0) {
        // 0x80022FCC: nop
    
            goto L_8002307C;
    }
    // 0x80022FCC: nop

    // 0x80022FD0: lh          $t5, 0x1AC($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X1AC);
    // 0x80022FD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80022FD8: bne         $t5, $at, L_80023058
    if (ctx->r13 != ctx->r1) {
        // 0x80022FDC: nop
    
            goto L_80023058;
    }
    // 0x80022FDC: nop

    // 0x80022FE0: jal         0x8006ECD0
    // 0x80022FE4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    get_settings(rdram, ctx);
        goto after_4;
    // 0x80022FE4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x80022FE8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80022FEC: lhu         $t8, 0x14($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X14);
    // 0x80022FF0: lb          $a3, 0x1D6($v1)
    ctx->r7 = MEM_B(ctx->r3, 0X1D6);
    // 0x80022FF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80022FF8: addiu       $t6, $a3, 0x3
    ctx->r14 = ADD32(ctx->r7, 0X3);
    // 0x80022FFC: sllv        $a1, $t7, $t6
    ctx->r5 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80023000: and         $t9, $t8, $a1
    ctx->r25 = ctx->r24 & ctx->r5;
    // 0x80023004: beq         $t9, $zero, L_8002301C
    if (ctx->r25 == 0) {
        // 0x80023008: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002301C;
    }
    // 0x80023008: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002300C: jal         0x8009D874
    // 0x80023010: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_5;
    // 0x80023010: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x80023014: b           L_80023064
    // 0x80023018: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
        goto L_80023064;
    // 0x80023018: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_8002301C:
    // 0x8002301C: addiu       $a0, $a3, 0x6
    ctx->r4 = ADD32(ctx->r7, 0X6);
    // 0x80023020: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80023024: jal         0x8009D874
    // 0x80023028: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_6;
    // 0x80023028: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_6:
    // 0x8002302C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80023030: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80023034: lhu         $t0, 0x14($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X14);
    // 0x80023038: nop

    // 0x8002303C: or          $t1, $t0, $a1
    ctx->r9 = ctx->r8 | ctx->r5;
    // 0x80023040: jal         0x8009C6E4
    // 0x80023044: sh          $t1, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r9;
    get_save_file_index(rdram, ctx);
        goto after_7;
    // 0x80023044: sh          $t1, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r9;
    after_7:
    // 0x80023048: jal         0x8006EE88
    // 0x8002304C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_8;
    // 0x8002304C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80023050: b           L_80023064
    // 0x80023054: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
        goto L_80023064;
    // 0x80023054: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80023058:
    // 0x80023058: jal         0x8009D874
    // 0x8002305C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_9;
    // 0x8002305C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_9:
    // 0x80023060: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80023064:
    // 0x80023064: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x80023068: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002306C: jal         0x800521F8
    // 0x80023070: sw          $t2, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->r10;
    set_taj_status(rdram, ctx);
        goto after_10;
    // 0x80023070: sw          $t2, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->r10;
    after_10:
    // 0x80023074: b           L_800230D0
    // 0x80023078: nop

        goto L_800230D0;
    // 0x80023078: nop

L_8002307C:
    // 0x8002307C: jal         0x80000B28
    // 0x80023080: nop

    music_change_on(rdram, ctx);
        goto after_11;
    // 0x80023080: nop

    after_11:
    // 0x80023084: jal         0x80001844
    // 0x80023088: nop

    music_stop(rdram, ctx);
        goto after_12;
    // 0x80023088: nop

    after_12:
    // 0x8002308C: jal         0x8009D874
    // 0x80023090: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_13;
    // 0x80023090: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80023094: jal         0x80008168
    // 0x80023098: nop

    audspat_jingle_on(rdram, ctx);
        goto after_14;
    // 0x80023098: nop

    after_14:
    // 0x8002309C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800230A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800230A4: bne         $t4, $at, L_800230B4
    if (ctx->r12 != ctx->r1) {
        // 0x800230A8: nop
    
            goto L_800230B4;
    }
    // 0x800230A8: nop

    // 0x800230AC: jal         0x800C3744
    // 0x800230B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_current_text(rdram, ctx);
        goto after_15;
    // 0x800230B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
L_800230B4:
    // 0x800230B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800230B8: sw          $zero, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = 0;
    // 0x800230BC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800230C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800230C4: sw          $zero, -0x4CC8($at)
    MEM_W(-0X4CC8, ctx->r1) = 0;
    // 0x800230C8: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x800230CC: sw          $t5, 0x78($t7)
    MEM_W(0X78, ctx->r15) = ctx->r13;
L_800230D0:
    // 0x800230D0: jal         0x80000B28
    // 0x800230D4: nop

    music_change_on(rdram, ctx);
        goto after_16;
    // 0x800230D4: nop

    after_16:
    // 0x800230D8: jal         0x800A10B4
    // 0x800230DC: nop

    hud_audio_init(rdram, ctx);
        goto after_17;
    // 0x800230DC: nop

    after_17:
    // 0x800230E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800230E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800230E8: jal         0x8006BF50
    // 0x800230EC: nop

    level_music_start(rdram, ctx);
        goto after_18;
    // 0x800230EC: nop

    after_18:
    // 0x800230F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800230F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800230F8: sb          $zero, -0x4B8A($at)
    MEM_B(-0X4B8A, ctx->r1) = 0;
    // 0x800230FC: jr          $ra
    // 0x80023100: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80023100: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800230D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023104: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80023108: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002310C: lw          $v0, -0x4BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
    // 0x80023110: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80023114: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80023118: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002311C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80023120: bne         $v0, $zero, L_800231EC
    if (ctx->r2 != 0) {
        // 0x80023124: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800231EC;
    }
    // 0x80023124: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80023128: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8002312C: addiu       $a3, $a3, -0x4C24
    ctx->r7 = ADD32(ctx->r7, -0X4C24);
    // 0x80023130: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80023134: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80023138: blez        $a0, L_800231E4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8002313C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800231E4;
    }
    // 0x8002313C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80023140: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80023144: addiu       $a1, $a1, -0x4C28
    ctx->r5 = ADD32(ctx->r5, -0X4C28);
    // 0x80023148: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
L_8002314C:
    // 0x8002314C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80023150: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80023154: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80023158: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x8002315C: nop

    // 0x80023160: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x80023164: nop

    // 0x80023168: andi        $t1, $t9, 0x8000
    ctx->r9 = ctx->r25 & 0X8000;
    // 0x8002316C: bne         $t1, $zero, L_800231D0
    if (ctx->r9 != 0) {
        // 0x80023170: nop
    
            goto L_800231D0;
    }
    // 0x80023170: nop

    // 0x80023174: lh          $t2, 0x48($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X48);
    // 0x80023178: nop

    // 0x8002317C: bne         $a2, $t2, L_800231D0
    if (ctx->r6 != ctx->r10) {
        // 0x80023180: nop
    
            goto L_800231D0;
    }
    // 0x80023180: nop

    // 0x80023184: lw          $t3, 0x78($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X78);
    // 0x80023188: nop

    // 0x8002318C: bne         $t3, $zero, L_800231D4
    if (ctx->r11 != 0) {
        // 0x80023190: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800231D4;
    }
    // 0x80023190: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80023194: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80023198: nop

    // 0x8002319C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x800231A0: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800231A4: nop

    // 0x800231A8: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800231AC: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800231B0: nop

    // 0x800231B4: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800231B8: lh          $t4, 0x2E($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2E);
    // 0x800231BC: nop

    // 0x800231C0: sh          $t4, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r12;
    // 0x800231C4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800231C8: nop

    // 0x800231CC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800231D0:
    // 0x800231D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800231D4:
    // 0x800231D4: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800231D8: bne         $at, $zero, L_8002314C
    if (ctx->r1 != 0) {
        // 0x800231DC: nop
    
            goto L_8002314C;
    }
    // 0x800231DC: nop

    // 0x800231E0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
L_800231E4:
    // 0x800231E4: b           L_80023260
    // 0x800231E8: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_80023260;
    // 0x800231E8: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800231EC:
    // 0x800231EC: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x800231F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800231F4: lw          $t6, -0x4BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BB4);
    // 0x800231F8: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x800231FC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80023200: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80023204: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x80023208: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002320C: lwc1        $f16, -0x34($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X34);
    // 0x80023210: lwc1        $f10, -0x2C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, -0X2C);
    // 0x80023214: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80023218: addiu       $t0, $t0, -0x3C
    ctx->r8 = ADD32(ctx->r8, -0X3C);
    // 0x8002321C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80023220: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80023224: lwc1        $f6, 0x14($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80023228: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8002322C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80023230: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80023234: lwc1        $f8, 0x18($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80023238: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8002323C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023240: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80023244: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x80023248: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8002324C: jal         0x80029F58
    // 0x80023250: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_0;
    // 0x80023250: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80023254: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80023258: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // 0x8002325C: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_80023260:
    // 0x80023260: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80023264: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80023268: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8002326C: jal         0x8002BAF0
    // 0x80023270: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    collision_get_y(rdram, ctx);
        goto after_1;
    // 0x80023270: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x80023274: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80023278: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8002327C: beq         $v0, $zero, L_80023294
    if (ctx->r2 == 0) {
        // 0x80023280: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80023294;
    }
    // 0x80023280: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80023284: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x80023288: lwc1        $f4, 0x2C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X2C);
    // 0x8002328C: nop

    // 0x80023290: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_80023294:
    // 0x80023294: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023298: nop

    // 0x8002329C: swc1        $f6, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f6.u32l;
    // 0x800232A0: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800232A4: nop

    // 0x800232A8: swc1        $f16, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f16.u32l;
    // 0x800232AC: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800232B0: beq         $t0, $zero, L_800232D4
    if (ctx->r8 == 0) {
        // 0x800232B4: swc1        $f8, 0x64($s1)
        MEM_W(0X64, ctx->r17) = ctx->f8.u32l;
            goto L_800232D4;
    }
    // 0x800232B4: swc1        $f8, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f8.u32l;
    // 0x800232B8: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800232BC: lwc1        $f14, 0x8($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800232C0: jal         0x80070990
    // 0x800232C4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x800232C4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800232C8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800232CC: b           L_800232E0
    // 0x800232D0: sh          $v0, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r2;
        goto L_800232E0;
    // 0x800232D0: sh          $v0, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r2;
L_800232D4:
    // 0x800232D4: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800232D8: nop

    // 0x800232DC: sh          $t9, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r25;
L_800232E0:
    // 0x800232E0: sb          $zero, 0x192($s1)
    MEM_B(0X192, ctx->r17) = 0;
    // 0x800232E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800232E8: lw          $t2, -0x4BB0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4BB0);
    // 0x800232EC: lb          $t1, 0x193($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X193);
    // 0x800232F0: lh          $t4, 0x1A0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X1A0);
    // 0x800232F4: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800232F8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800232FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80023300: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80023304: mflo        $t3
    ctx->r11 = lo;
    // 0x80023308: sh          $t3, 0x190($s1)
    MEM_H(0X190, ctx->r17) = ctx->r11;
    // 0x8002330C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023310: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x80023314: swc1        $f10, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f10.u32l;
    // 0x80023318: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8002331C: nop

    // 0x80023320: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80023324: swc1        $f4, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f4.u32l;
    // 0x80023328: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002332C: nop

    // 0x80023330: swc1        $f6, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f6.u32l;
    // 0x80023334: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023338: nop

    // 0x8002333C: swc1        $f16, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f16.u32l;
    // 0x80023340: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023344: nop

    // 0x80023348: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8002334C: swc1        $f10, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f10.u32l;
    // 0x80023350: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80023354: nop

    // 0x80023358: swc1        $f18, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f18.u32l;
    // 0x8002335C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023360: nop

    // 0x80023364: swc1        $f4, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f4.u32l;
    // 0x80023368: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8002336C: nop

    // 0x80023370: add.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80023374: swc1        $f16, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f16.u32l;
    // 0x80023378: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002337C: nop

    // 0x80023380: swc1        $f8, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f8.u32l;
    // 0x80023384: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023388: nop

    // 0x8002338C: swc1        $f10, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = ctx->f10.u32l;
    // 0x80023390: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023394: nop

    // 0x80023398: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8002339C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800233A0: swc1        $f4, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->f4.u32l;
    // 0x800233A4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800233A8: nop

    // 0x800233AC: swc1        $f6, 0x104($s1)
    MEM_W(0X104, ctx->r17) = ctx->f6.u32l;
    // 0x800233B0: lw          $t5, 0x4C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4C);
    // 0x800233B4: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800233B8: nop

    // 0x800233BC: swc1        $f16, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f16.u32l;
    // 0x800233C0: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x800233C4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800233C8: nop

    // 0x800233CC: swc1        $f8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f8.u32l;
    // 0x800233D0: lw          $t7, 0x4C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4C);
    // 0x800233D4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800233D8: nop

    // 0x800233DC: swc1        $f10, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f10.u32l;
    // 0x800233E0: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x800233E4: swc1        $f0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
    // 0x800233E8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800233EC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800233F0: lb          $t8, 0x1D7($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X1D7);
    // 0x800233F4: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x800233F8: sb          $t8, 0x1D6($s1)
    MEM_B(0X1D6, ctx->r17) = ctx->r24;
    // 0x800233FC: beq         $a0, $at, L_8002343C
    if (ctx->r4 == ctx->r1) {
        // 0x80023400: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002343C;
    }
    // 0x80023400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80023404: jal         0x80066828
    // 0x80023408: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    set_active_camera(rdram, ctx);
        goto after_3;
    // 0x80023408: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_3:
    // 0x8002340C: jal         0x80069F3C
    // 0x80023410: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_4;
    // 0x80023410: nop

    after_4:
    // 0x80023414: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023418: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8002341C: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x80023420: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023424: nop

    // 0x80023428: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x8002342C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80023430: nop

    // 0x80023434: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x80023438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002343C:
    // 0x8002343C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80023440: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80023444: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80023448: jr          $ra
    // 0x8002344C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8002344C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void is_taj_challenge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023450: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023454: lb          $v0, -0x4B8A($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4B8A);
    // 0x80023458: jr          $ra
    // 0x8002345C: nop

    return;
    // 0x8002345C: nop

;}
RECOMP_FUNC void find_furthest_telepoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023460: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80023464: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80023468: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002346C: addiu       $s3, $s3, -0x4C24
    ctx->r19 = ADD32(ctx->r19, -0X4C24);
    // 0x80023470: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80023474: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80023478: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002347C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80023480: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80023484: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80023488: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002348C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80023490: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80023494: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x80023498: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x8002349C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800234A0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800234A4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800234A8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800234AC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800234B0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800234B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800234B8: blez        $t6, L_80023558
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800234BC: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_80023558;
    }
    // 0x800234BC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800234C0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800234C4: addiu       $s4, $s4, -0x4C28
    ctx->r20 = ADD32(ctx->r20, -0X4C28);
    // 0x800234C8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800234CC: addiu       $s5, $zero, 0x57
    ctx->r21 = ADD32(0, 0X57);
L_800234D0:
    // 0x800234D0: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800234D4: nop

    // 0x800234D8: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800234DC: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800234E0: nop

    // 0x800234E4: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800234E8: nop

    // 0x800234EC: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x800234F0: bne         $t0, $zero, L_80023544
    if (ctx->r8 != 0) {
        // 0x800234F4: nop
    
            goto L_80023544;
    }
    // 0x800234F4: nop

    // 0x800234F8: lh          $t1, 0x48($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X48);
    // 0x800234FC: nop

    // 0x80023500: bne         $s5, $t1, L_80023544
    if (ctx->r21 != ctx->r9) {
        // 0x80023504: nop
    
            goto L_80023544;
    }
    // 0x80023504: nop

    // 0x80023508: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002350C: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80023510: sub.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80023514: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80023518: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8002351C: sub.s       $f2, $f6, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x80023520: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80023524: jal         0x800CA030
    // 0x80023528: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80023528: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8002352C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80023530: nop

    // 0x80023534: bc1f        L_80023544
    if (!c1cs) {
        // 0x80023538: nop
    
            goto L_80023544;
    }
    // 0x80023538: nop

    // 0x8002353C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80023540: or          $s6, $s0, $zero
    ctx->r22 = ctx->r16 | 0;
L_80023544:
    // 0x80023544: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80023548: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002354C: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80023550: bne         $at, $zero, L_800234D0
    if (ctx->r1 != 0) {
        // 0x80023554: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800234D0;
    }
    // 0x80023554: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80023558:
    // 0x80023558: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002355C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80023560: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80023564: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80023568: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002356C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80023570: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80023574: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80023578: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002357C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80023580: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80023584: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80023588: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002358C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80023590: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80023594: jr          $ra
    // 0x80023598: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80023598: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80023568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002359C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800235A0: lb          $t6, -0x4D44($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X4D44);
    // 0x800235A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800235A8: beq         $t6, $zero, L_800235C0
    if (ctx->r14 == 0) {
        // 0x800235AC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800235C0;
    }
    // 0x800235AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800235B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800235B4: lb          $v0, -0x4D5B($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D5B);
    // 0x800235B8: b           L_800235E4
    // 0x800235BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800235E4;
    // 0x800235BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800235C0:
    // 0x800235C0: jal         0x8006BFD8
    // 0x800235C4: nop

    level_type(rdram, ctx);
        goto after_0;
    // 0x800235C4: nop

    after_0:
    // 0x800235C8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800235CC: bne         $v0, $at, L_800235E0
    if (ctx->r2 != ctx->r1) {
        // 0x800235D0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800235E0;
    }
    // 0x800235D0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800235D4: lb          $v0, -0x4D5B($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D5B);
    // 0x800235D8: b           L_800235E4
    // 0x800235DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800235E4;
    // 0x800235DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800235E0:
    // 0x800235E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800235E4:
    // 0x800235E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800235E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800235EC: jr          $ra
    // 0x800235F0: nop

    return;
    // 0x800235F0: nop

;}
RECOMP_FUNC void obj_door_override(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800235F4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800235F8: lb          $v0, -0x4CAB($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4CAB);
    // 0x800235FC: jr          $ra
    // 0x80023600: nop

    return;
    // 0x80023600: nop

;}
RECOMP_FUNC void obj_door_open(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80023608: jr          $ra
    // 0x8002360C: sb          $a0, -0x4CAB($at)
    MEM_B(-0X4CAB, ctx->r1) = ctx->r4;
    return;
    // 0x8002360C: sb          $a0, -0x4CAB($at)
    MEM_B(-0X4CAB, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void get_object_property_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023610: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80023614: sw          $a1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r5;
    // 0x80023618: lb          $t7, 0x54($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X54);
    // 0x8002361C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80023620: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80023624: sltiu       $at, $t8, 0x77
    ctx->r1 = ctx->r24 < 0X77 ? 1 : 0;
    // 0x80023628: beq         $at, $zero, L_800238DC
    if (ctx->r1 == 0) {
        // 0x8002362C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800238DC;
    }
    // 0x8002362C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80023630: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80023634: addu        $at, $at, $t8
    gpr jr_addend_80023640 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80023638: lw          $t8, 0x5C18($at)
    ctx->r24 = ADD32(ctx->r1, 0X5C18);
    // 0x8002363C: nop

    // 0x80023640: jr          $t8
    // 0x80023644: nop

    switch (jr_addend_80023640 >> 2) {
        case 0: goto L_80023648; break;
        case 1: goto L_800238DC; break;
        case 2: goto L_8002383C; break;
        case 3: goto L_80023684; break;
        case 4: goto L_80023710; break;
        case 5: goto L_800238DC; break;
        case 6: goto L_80023670; break;
        case 7: goto L_80023698; break;
        case 8: goto L_800236AC; break;
        case 9: goto L_800238DC; break;
        case 10: goto L_800238DC; break;
        case 11: goto L_800237C4; break;
        case 12: goto L_800238DC; break;
        case 13: goto L_8002365C; break;
        case 14: goto L_800238DC; break;
        case 15: goto L_800236C0; break;
        case 16: goto L_80023724; break;
        case 17: goto L_80023710; break;
        case 18: goto L_800236AC; break;
        case 19: goto L_800238DC; break;
        case 20: goto L_800238DC; break;
        case 21: goto L_800238DC; break;
        case 22: goto L_800238DC; break;
        case 23: goto L_800238DC; break;
        case 24: goto L_800238DC; break;
        case 25: goto L_800238DC; break;
        case 26: goto L_800236E8; break;
        case 27: goto L_800238DC; break;
        case 28: goto L_800236FC; break;
        case 29: goto L_800236D4; break;
        case 30: goto L_80023788; break;
        case 31: goto L_80023738; break;
        case 32: goto L_800238DC; break;
        case 33: goto L_800238DC; break;
        case 34: goto L_800238DC; break;
        case 35: goto L_800238DC; break;
        case 36: goto L_800238DC; break;
        case 37: goto L_8002374C; break;
        case 38: goto L_800238DC; break;
        case 39: goto L_80023760; break;
        case 40: goto L_800236D4; break;
        case 41: goto L_800238DC; break;
        case 42: goto L_800238DC; break;
        case 43: goto L_800238DC; break;
        case 44: goto L_80023774; break;
        case 45: goto L_800238DC; break;
        case 46: goto L_80023864; break;
        case 47: goto L_800238DC; break;
        case 48: goto L_800238DC; break;
        case 49: goto L_800237C4; break;
        case 50: goto L_800237C4; break;
        case 51: goto L_800238DC; break;
        case 52: goto L_800237C4; break;
        case 53: goto L_800237C4; break;
        case 54: goto L_800236D4; break;
        case 55: goto L_800237C4; break;
        case 56: goto L_800238DC; break;
        case 57: goto L_800238DC; break;
        case 58: goto L_800238DC; break;
        case 59: goto L_800238DC; break;
        case 60: goto L_80023814; break;
        case 61: goto L_80023788; break;
        case 62: goto L_800238DC; break;
        case 63: goto L_800238DC; break;
        case 64: goto L_800238DC; break;
        case 65: goto L_800238DC; break;
        case 66: goto L_800238DC; break;
        case 67: goto L_800238DC; break;
        case 68: goto L_800238DC; break;
        case 69: goto L_800237C4; break;
        case 70: goto L_800237D8; break;
        case 71: goto L_800237C4; break;
        case 72: goto L_800238DC; break;
        case 73: goto L_800238A0; break;
        case 74: goto L_800238DC; break;
        case 75: goto L_800238DC; break;
        case 76: goto L_80023788; break;
        case 77: goto L_800238DC; break;
        case 78: goto L_8002379C; break;
        case 79: goto L_800237C4; break;
        case 80: goto L_800237C4; break;
        case 81: goto L_800238DC; break;
        case 82: goto L_800237B0; break;
        case 83: goto L_800237C4; break;
        case 84: goto L_800237C4; break;
        case 85: goto L_800237C4; break;
        case 86: goto L_800238DC; break;
        case 87: goto L_800238DC; break;
        case 88: goto L_800238DC; break;
        case 89: goto L_800238DC; break;
        case 90: goto L_800238DC; break;
        case 91: goto L_800238DC; break;
        case 92: goto L_800238DC; break;
        case 93: goto L_8002388C; break;
        case 94: goto L_800238DC; break;
        case 95: goto L_800237C4; break;
        case 96: goto L_800237C4; break;
        case 97: goto L_800238DC; break;
        case 98: goto L_800238DC; break;
        case 99: goto L_800238DC; break;
        case 100: goto L_800237C4; break;
        case 101: goto L_800237C4; break;
        case 102: goto L_800237C4; break;
        case 103: goto L_800237C4; break;
        case 104: goto L_800238DC; break;
        case 105: goto L_800238DC; break;
        case 106: goto L_800238DC; break;
        case 107: goto L_800238DC; break;
        case 108: goto L_800238B4; break;
        case 109: goto L_800238DC; break;
        case 110: goto L_8002365C; break;
        case 111: goto L_800237EC; break;
        case 112: goto L_800237C4; break;
        case 113: goto L_800238DC; break;
        case 114: goto L_800237C4; break;
        case 115: goto L_800238C8; break;
        case 116: goto L_800238DC; break;
        case 117: goto L_80023800; break;
        case 118: goto L_800237C4; break;
        default: switch_error(__func__, 0x80023640, 0x800E5C18);
    }
    // 0x80023644: nop

L_80023648:
    // 0x80023648: addiu       $v1, $zero, 0x224
    ctx->r3 = ADD32(0, 0X224);
    // 0x8002364C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023650: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023654: jr          $ra
    // 0x80023658: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023658: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002365C:
    // 0x8002365C: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x80023660: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023664: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023668: jr          $ra
    // 0x8002366C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002366C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023670:
    // 0x80023670: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x80023674: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023678: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002367C: jr          $ra
    // 0x80023680: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023680: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023684:
    // 0x80023684: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80023688: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002368C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023690: jr          $ra
    // 0x80023694: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023694: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023698:
    // 0x80023698: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8002369C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236A0: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236A4: jr          $ra
    // 0x800236A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236AC:
    // 0x800236AC: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x800236B0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236B4: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236B8: jr          $ra
    // 0x800236BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236C0:
    // 0x800236C0: addiu       $v1, $zero, 0x1C
    ctx->r3 = ADD32(0, 0X1C);
    // 0x800236C4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236C8: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236CC: jr          $ra
    // 0x800236D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236D4:
    // 0x800236D4: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800236D8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236DC: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236E0: jr          $ra
    // 0x800236E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236E8:
    // 0x800236E8: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x800236EC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236F0: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236F4: jr          $ra
    // 0x800236F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236FC:
    // 0x800236FC: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80023700: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023704: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023708: jr          $ra
    // 0x8002370C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002370C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023710:
    // 0x80023710: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x80023714: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023718: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002371C: jr          $ra
    // 0x80023720: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023720: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023724:
    // 0x80023724: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x80023728: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002372C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023730: jr          $ra
    // 0x80023734: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023734: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023738:
    // 0x80023738: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8002373C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023740: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023744: jr          $ra
    // 0x80023748: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023748: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002374C:
    // 0x8002374C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x80023750: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023754: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023758: jr          $ra
    // 0x8002375C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002375C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023760:
    // 0x80023760: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x80023764: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023768: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002376C: jr          $ra
    // 0x80023770: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023770: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023774:
    // 0x80023774: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80023778: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002377C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023780: jr          $ra
    // 0x80023784: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023784: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023788:
    // 0x80023788: addiu       $v1, $zero, 0x38
    ctx->r3 = ADD32(0, 0X38);
    // 0x8002378C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023790: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023794: jr          $ra
    // 0x80023798: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023798: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002379C:
    // 0x8002379C: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x800237A0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237A4: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237A8: jr          $ra
    // 0x800237AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800237B0:
    // 0x800237B0: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800237B4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237B8: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237BC: jr          $ra
    // 0x800237C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800237C4:
    // 0x800237C4: addiu       $v1, $zero, 0x48
    ctx->r3 = ADD32(0, 0X48);
    // 0x800237C8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237CC: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237D0: jr          $ra
    // 0x800237D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800237D8:
    // 0x800237D8: addiu       $v1, $zero, 0x44
    ctx->r3 = ADD32(0, 0X44);
    // 0x800237DC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237E0: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237E4: jr          $ra
    // 0x800237E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800237EC:
    // 0x800237EC: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x800237F0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237F4: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237F8: jr          $ra
    // 0x800237FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023800:
    // 0x80023800: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80023804: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023808: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002380C: jr          $ra
    // 0x80023810: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023810: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023814:
    // 0x80023814: andi        $t9, $a1, 0xF
    ctx->r25 = ctx->r5 & 0XF;
    // 0x80023818: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8002381C: subu        $v0, $t0, $t9
    ctx->r2 = SUB32(ctx->r8, ctx->r25);
    // 0x80023820: addu        $t1, $a1, $v0
    ctx->r9 = ADD32(ctx->r5, ctx->r2);
    // 0x80023824: addiu       $v1, $v0, 0x110
    ctx->r3 = ADD32(ctx->r2, 0X110);
    // 0x80023828: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002382C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023830: sw          $t1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r9;
    // 0x80023834: jr          $ra
    // 0x80023838: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023838: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002383C:
    // 0x8002383C: andi        $t2, $a1, 0xF
    ctx->r10 = ctx->r5 & 0XF;
    // 0x80023840: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80023844: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
    // 0x80023848: addu        $t4, $a1, $v0
    ctx->r12 = ADD32(ctx->r5, ctx->r2);
    // 0x8002384C: addiu       $v1, $v0, 0x120
    ctx->r3 = ADD32(ctx->r2, 0X120);
    // 0x80023850: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023854: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023858: sw          $t4, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r12;
    // 0x8002385C: jr          $ra
    // 0x80023860: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023860: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023864:
    // 0x80023864: andi        $t5, $a1, 0xF
    ctx->r13 = ctx->r5 & 0XF;
    // 0x80023868: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8002386C: subu        $v0, $t6, $t5
    ctx->r2 = SUB32(ctx->r14, ctx->r13);
    // 0x80023870: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x80023874: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x80023878: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002387C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023880: sw          $t7, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r15;
    // 0x80023884: jr          $ra
    // 0x80023888: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023888: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002388C:
    // 0x8002388C: addiu       $v1, $zero, 0x60
    ctx->r3 = ADD32(0, 0X60);
    // 0x80023890: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023894: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023898: jr          $ra
    // 0x8002389C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002389C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800238A0:
    // 0x800238A0: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x800238A4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800238A8: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800238AC: jr          $ra
    // 0x800238B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800238B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800238B4:
    // 0x800238B4: addiu       $v1, $zero, 0x34
    ctx->r3 = ADD32(0, 0X34);
    // 0x800238B8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800238BC: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800238C0: jr          $ra
    // 0x800238C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800238C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800238C8:
    // 0x800238C8: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x800238CC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800238D0: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800238D4: jr          $ra
    // 0x800238D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800238D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800238DC:
    // 0x800238DC: sw          $zero, 0x64($a0)
    MEM_W(0X64, ctx->r4) = 0;
    // 0x800238E0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800238E4: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800238E8: jr          $ra
    // 0x800238EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800238EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
;}
RECOMP_FUNC void run_object_init_func(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800238F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800238F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800238F8: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x800238FC: nop

    // 0x80023900: lb          $t7, 0x54($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X54);
    // 0x80023904: nop

    // 0x80023908: sh          $t7, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r15;
    // 0x8002390C: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
    // 0x80023910: nop

    // 0x80023914: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80023918: sltiu       $at, $t9, 0x76
    ctx->r1 = ctx->r25 < 0X76 ? 1 : 0;
    // 0x8002391C: beq         $at, $zero, L_80023E54
    if (ctx->r1 == 0) {
        // 0x80023920: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80023E54;
    }
    // 0x80023920: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80023924: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80023928: addu        $at, $at, $t9
    gpr jr_addend_80023934 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8002392C: lw          $t9, 0x5DF4($at)
    ctx->r25 = ADD32(ctx->r1, 0X5DF4);
    // 0x80023930: nop

    // 0x80023934: jr          $t9
    // 0x80023938: nop

    switch (jr_addend_80023934 >> 2) {
        case 0: goto L_8002393C; break;
        case 1: goto L_8002394C; break;
        case 2: goto L_8002395C; break;
        case 3: goto L_8002396C; break;
        case 4: goto L_80023AAC; break;
        case 5: goto L_8002397C; break;
        case 6: goto L_800239AC; break;
        case 7: goto L_800239BC; break;
        case 8: goto L_800239CC; break;
        case 9: goto L_800239EC; break;
        case 10: goto L_800239FC; break;
        case 11: goto L_80023A0C; break;
        case 12: goto L_80023A1C; break;
        case 13: goto L_80023A4C; break;
        case 14: goto L_80023A6C; break;
        case 15: goto L_80023A7C; break;
        case 16: goto L_80023A8C; break;
        case 17: goto L_80023AAC; break;
        case 18: goto L_800239CC; break;
        case 19: goto L_80023E54; break;
        case 20: goto L_80023E54; break;
        case 21: goto L_8002399C; break;
        case 22: goto L_80023A9C; break;
        case 23: goto L_80023E54; break;
        case 24: goto L_8002398C; break;
        case 25: goto L_80023ABC; break;
        case 26: goto L_800239DC; break;
        case 27: goto L_80023ACC; break;
        case 28: goto L_80023ADC; break;
        case 29: goto L_80023A2C; break;
        case 30: goto L_80023AEC; break;
        case 31: goto L_80023AFC; break;
        case 32: goto L_80023B0C; break;
        case 33: goto L_80023E54; break;
        case 34: goto L_80023E54; break;
        case 35: goto L_80023B1C; break;
        case 36: goto L_80023B3C; break;
        case 37: goto L_80023B4C; break;
        case 38: goto L_80023B5C; break;
        case 39: goto L_80023B6C; break;
        case 40: goto L_80023A3C; break;
        case 41: goto L_80023E54; break;
        case 42: goto L_80023B7C; break;
        case 43: goto L_80023B8C; break;
        case 44: goto L_80023B9C; break;
        case 45: goto L_80023BAC; break;
        case 46: goto L_80023BBC; break;
        case 47: goto L_80023E54; break;
        case 48: goto L_80023BCC; break;
        case 49: goto L_80023E54; break;
        case 50: goto L_80023E54; break;
        case 51: goto L_80023BDC; break;
        case 52: goto L_80023E54; break;
        case 53: goto L_80023E54; break;
        case 54: goto L_80023BEC; break;
        case 55: goto L_80023E54; break;
        case 56: goto L_80023BFC; break;
        case 57: goto L_80023C0C; break;
        case 58: goto L_80023C1C; break;
        case 59: goto L_80023E54; break;
        case 60: goto L_80023C2C; break;
        case 61: goto L_80023C3C; break;
        case 62: goto L_80023E54; break;
        case 63: goto L_80023C4C; break;
        case 64: goto L_80023C5C; break;
        case 65: goto L_80023C6C; break;
        case 66: goto L_80023B2C; break;
        case 67: goto L_80023C7C; break;
        case 68: goto L_80023C8C; break;
        case 69: goto L_80023C9C; break;
        case 70: goto L_80023CDC; break;
        case 71: goto L_80023CAC; break;
        case 72: goto L_80023D0C; break;
        case 73: goto L_80023D1C; break;
        case 74: goto L_80023D2C; break;
        case 75: goto L_80023D3C; break;
        case 76: goto L_80023D4C; break;
        case 77: goto L_80023D5C; break;
        case 78: goto L_80023D6C; break;
        case 79: goto L_80023E54; break;
        case 80: goto L_80023E54; break;
        case 81: goto L_80023D7C; break;
        case 82: goto L_80023D8C; break;
        case 83: goto L_80023D9C; break;
        case 84: goto L_80023E54; break;
        case 85: goto L_80023E54; break;
        case 86: goto L_80023E54; break;
        case 87: goto L_80023DBC; break;
        case 88: goto L_80023DAC; break;
        case 89: goto L_80023DCC; break;
        case 90: goto L_80023E54; break;
        case 91: goto L_80023E54; break;
        case 92: goto L_80023BFC; break;
        case 93: goto L_80023DDC; break;
        case 94: goto L_80023CAC; break;
        case 95: goto L_80023CBC; break;
        case 96: goto L_80023CCC; break;
        case 97: goto L_80023DEC; break;
        case 98: goto L_80023DFC; break;
        case 99: goto L_80023DFC; break;
        case 100: goto L_80023CBC; break;
        case 101: goto L_80023CCC; break;
        case 102: goto L_80023C9C; break;
        case 103: goto L_80023CAC; break;
        case 104: goto L_80023E0C; break;
        case 105: goto L_80023E54; break;
        case 106: goto L_80023E54; break;
        case 107: goto L_80023E1C; break;
        case 108: goto L_80023E2C; break;
        case 109: goto L_80023E3C; break;
        case 110: goto L_80023A5C; break;
        case 111: goto L_80023CEC; break;
        case 112: goto L_80023E54; break;
        case 113: goto L_80023E54; break;
        case 114: goto L_80023E54; break;
        case 115: goto L_80023E1C; break;
        case 116: goto L_80023E4C; break;
        case 117: goto L_80023CFC; break;
        default: switch_error(__func__, 0x80023934, 0x800E5DF4);
    }
    // 0x80023938: nop

L_8002393C:
    // 0x8002393C: jal         0x8004DAF0
    // 0x80023940: nop

    obj_init_racer(rdram, ctx);
        goto after_0;
    // 0x80023940: nop

    after_0:
    // 0x80023944: b           L_80023E58
    // 0x80023948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002394C:
    // 0x8002394C: jal         0x80033D00
    // 0x80023950: nop

    obj_init_scenery(rdram, ctx);
        goto after_1;
    // 0x80023950: nop

    after_1:
    // 0x80023954: b           L_80023E58
    // 0x80023958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002395C:
    // 0x8002395C: jal         0x80036C70
    // 0x80023960: nop

    obj_init_fish(rdram, ctx);
        goto after_2;
    // 0x80023960: nop

    after_2:
    // 0x80023964: b           L_80023E58
    // 0x80023968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002396C:
    // 0x8002396C: jal         0x80037720
    // 0x80023970: nop

    obj_init_animator(rdram, ctx);
        goto after_3;
    // 0x80023970: nop

    after_3:
    // 0x80023974: b           L_80023E58
    // 0x80023978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002397C:
    // 0x8002397C: jal         0x800389EC
    // 0x80023980: nop

    obj_init_smoke(rdram, ctx);
        goto after_4;
    // 0x80023980: nop

    after_4:
    // 0x80023984: b           L_80023E58
    // 0x80023988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002398C:
    // 0x8002398C: jal         0x80038AAC
    // 0x80023990: nop

    obj_init_unknown25(rdram, ctx);
        goto after_5;
    // 0x80023990: nop

    after_5:
    // 0x80023994: b           L_80023E58
    // 0x80023998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002399C:
    // 0x8002399C: jal         0x80038BB4
    // 0x800239A0: nop

    obj_init_bombexplosion(rdram, ctx);
        goto after_6;
    // 0x800239A0: nop

    after_6:
    // 0x800239A4: b           L_80023E58
    // 0x800239A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x800239A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239AC:
    // 0x800239AC: jal         0x80038E7C
    // 0x800239B0: nop

    obj_init_exit(rdram, ctx);
        goto after_7;
    // 0x800239B0: nop

    after_7:
    // 0x800239B4: b           L_80023E58
    // 0x800239B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x800239B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239BC:
    // 0x800239BC: jal         0x8003FDA8
    // 0x800239C0: nop

    obj_init_audio(rdram, ctx);
        goto after_8;
    // 0x800239C0: nop

    after_8:
    // 0x800239C4: b           L_80023E58
    // 0x800239C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x800239C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239CC:
    // 0x800239CC: jal         0x8003FF34
    // 0x800239D0: nop

    obj_init_audioline(rdram, ctx);
        goto after_9;
    // 0x800239D0: nop

    after_9:
    // 0x800239D4: b           L_80023E58
    // 0x800239D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x800239D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239DC:
    // 0x800239DC: jal         0x8004005C
    // 0x800239E0: nop

    obj_init_audioreverb(rdram, ctx);
        goto after_10;
    // 0x800239E0: nop

    after_10:
    // 0x800239E4: b           L_80023E58
    // 0x800239E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x800239E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239EC:
    // 0x800239EC: jal         0x800391A0
    // 0x800239F0: nop

    obj_init_cameracontrol(rdram, ctx);
        goto after_11;
    // 0x800239F0: nop

    after_11:
    // 0x800239F4: b           L_80023E58
    // 0x800239F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x800239F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239FC:
    // 0x800239FC: jal         0x800391D0
    // 0x80023A00: nop

    obj_init_setuppoint(rdram, ctx);
        goto after_12;
    // 0x80023A00: nop

    after_12:
    // 0x80023A04: b           L_80023E58
    // 0x80023A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A0C:
    // 0x80023A0C: jal         0x80039208
    // 0x80023A10: nop

    obj_init_dino_whale(rdram, ctx);
        goto after_13;
    // 0x80023A10: nop

    after_13:
    // 0x80023A14: b           L_80023E58
    // 0x80023A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A1C:
    // 0x80023A1C: jal         0x8003ACFC
    // 0x80023A20: nop

    obj_init_checkpoint(rdram, ctx);
        goto after_14;
    // 0x80023A20: nop

    after_14:
    // 0x80023A24: b           L_80023E58
    // 0x80023A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A2C:
    // 0x80023A2C: jal         0x8003AD74
    // 0x80023A30: nop

    obj_init_modechange(rdram, ctx);
        goto after_15;
    // 0x80023A30: nop

    after_15:
    // 0x80023A34: b           L_80023E58
    // 0x80023A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A3C:
    // 0x80023A3C: jal         0x8003B098
    // 0x80023A40: nop

    obj_init_bonus(rdram, ctx);
        goto after_16;
    // 0x80023A40: nop

    after_16:
    // 0x80023A44: b           L_80023E58
    // 0x80023A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A4C:
    // 0x80023A4C: jal         0x8003B80C
    // 0x80023A50: nop

    obj_init_door(rdram, ctx);
        goto after_17;
    // 0x80023A50: nop

    after_17:
    // 0x80023A54: b           L_80023E58
    // 0x80023A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A5C:
    // 0x80023A5C: jal         0x8003C220
    // 0x80023A60: nop

    obj_init_ttdoor(rdram, ctx);
        goto after_18;
    // 0x80023A60: nop

    after_18:
    // 0x80023A64: b           L_80023E58
    // 0x80023A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A6C:
    // 0x80023A6C: jal         0x8003CF58
    // 0x80023A70: nop

    obj_init_fogchanger(rdram, ctx);
        goto after_19;
    // 0x80023A70: nop

    after_19:
    // 0x80023A74: b           L_80023E58
    // 0x80023A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A7C:
    // 0x80023A7C: jal         0x8003D020
    // 0x80023A80: nop

    obj_init_ainode(rdram, ctx);
        goto after_20;
    // 0x80023A80: nop

    after_20:
    // 0x80023A84: b           L_80023E58
    // 0x80023A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A8C:
    // 0x80023A8C: jal         0x8003E00C
    // 0x80023A90: nop

    obj_init_weaponballoon(rdram, ctx);
        goto after_21;
    // 0x80023A90: nop

    after_21:
    // 0x80023A94: b           L_80023E58
    // 0x80023A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A9C:
    // 0x80023A9C: jal         0x8003E5F0
    // 0x80023AA0: nop

    obj_init_wballoonpop(rdram, ctx);
        goto after_22;
    // 0x80023AA0: nop

    after_22:
    // 0x80023AA4: b           L_80023E58
    // 0x80023AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023AAC:
    // 0x80023AAC: jal         0x8003E608
    // 0x80023AB0: nop

    obj_init_weapon(rdram, ctx);
        goto after_23;
    // 0x80023AB0: nop

    after_23:
    // 0x80023AB4: b           L_80023E58
    // 0x80023AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023ABC:
    // 0x80023ABC: jal         0x8003CF98
    // 0x80023AC0: nop

    obj_init_skycontrol(rdram, ctx);
        goto after_24;
    // 0x80023AC0: nop

    after_24:
    // 0x80023AC4: b           L_80023E58
    // 0x80023AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023ACC:
    // 0x80023ACC: jal         0x80034B30
    // 0x80023AD0: nop

    obj_init_torch_mist(rdram, ctx);
        goto after_25;
    // 0x80023AD0: nop

    after_25:
    // 0x80023AD4: b           L_80023E58
    // 0x80023AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023ADC:
    // 0x80023ADC: jal         0x800400E4
    // 0x80023AE0: nop

    obj_init_texscroll(rdram, ctx);
        goto after_26;
    // 0x80023AE0: nop

    after_26:
    // 0x80023AE4: b           L_80023E58
    // 0x80023AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023AEC:
    // 0x80023AEC: jal         0x800361D4
    // 0x80023AF0: nop

    obj_init_stopwatchman(rdram, ctx);
        goto after_27;
    // 0x80023AF0: nop

    after_27:
    // 0x80023AF4: b           L_80023E58
    // 0x80023AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023AFC:
    // 0x80023AFC: jal         0x8003D574
    // 0x80023B00: nop

    obj_init_banana(rdram, ctx);
        goto after_28;
    // 0x80023B00: nop

    after_28:
    // 0x80023B04: b           L_80023E58
    // 0x80023B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B0C:
    // 0x80023B0C: jal         0x800403E8
    // 0x80023B10: nop

    obj_init_rgbalight(rdram, ctx);
        goto after_29;
    // 0x80023B10: nop

    after_29:
    // 0x80023B14: b           L_80023E58
    // 0x80023B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B1C:
    // 0x80023B1C: jal         0x80040418
    // 0x80023B20: nop

    obj_init_buoy_pirateship(rdram, ctx);
        goto after_30;
    // 0x80023B20: nop

    after_30:
    // 0x80023B24: b           L_80023E58
    // 0x80023B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B2C:
    // 0x80023B2C: jal         0x800404DC
    // 0x80023B30: nop

    obj_init_log(rdram, ctx);
        goto after_31;
    // 0x80023B30: nop

    after_31:
    // 0x80023B34: b           L_80023E58
    // 0x80023B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B3C:
    // 0x80023B3C: jal         0x80040840
    // 0x80023B40: nop

    obj_init_weather(rdram, ctx);
        goto after_32;
    // 0x80023B40: nop

    after_32:
    // 0x80023B44: b           L_80023E58
    // 0x80023B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B4C:
    // 0x80023B4C: jal         0x8003CA2C
    // 0x80023B50: nop

    obj_init_bridge_whaleramp(rdram, ctx);
        goto after_33;
    // 0x80023B50: nop

    after_33:
    // 0x80023B54: b           L_80023E58
    // 0x80023B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B5C:
    // 0x80023B5C: jal         0x8003CEA4
    // 0x80023B60: nop

    obj_init_rampswitch(rdram, ctx);
        goto after_34;
    // 0x80023B60: nop

    after_34:
    // 0x80023B64: b           L_80023E58
    // 0x80023B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B6C:
    // 0x80023B6C: jal         0x8003CF40
    // 0x80023B70: nop

    obj_init_seamonster(rdram, ctx);
        goto after_35;
    // 0x80023B70: nop

    after_35:
    // 0x80023B74: b           L_80023E58
    // 0x80023B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B7C:
    // 0x80023B7C: jal         0x8004096C
    // 0x80023B80: nop

    obj_init_lensflare(rdram, ctx);
        goto after_36;
    // 0x80023B80: nop

    after_36:
    // 0x80023B84: b           L_80023E58
    // 0x80023B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B8C:
    // 0x80023B8C: jal         0x8004098C
    // 0x80023B90: nop

    obj_init_lensflareswitch(rdram, ctx);
        goto after_37;
    // 0x80023B90: nop

    after_37:
    // 0x80023B94: b           L_80023E58
    // 0x80023B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B9C:
    // 0x80023B9C: jal         0x8003526C
    // 0x80023BA0: nop

    obj_init_collectegg(rdram, ctx);
        goto after_38;
    // 0x80023BA0: nop

    after_38:
    // 0x80023BA4: b           L_80023E58
    // 0x80023BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BAC:
    // 0x80023BAC: jal         0x80035680
    // 0x80023BB0: nop

    obj_init_eggcreator(rdram, ctx);
        goto after_39;
    // 0x80023BB0: nop

    after_39:
    // 0x80023BB4: b           L_80023E58
    // 0x80023BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BBC:
    // 0x80023BBC: jal         0x80035F38
    // 0x80023BC0: nop

    obj_init_characterflag(rdram, ctx);
        goto after_40;
    // 0x80023BC0: nop

    after_40:
    // 0x80023BC4: b           L_80023E58
    // 0x80023BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BCC:
    // 0x80023BCC: jal         0x80037A58
    // 0x80023BD0: nop

    obj_init_animation(rdram, ctx);
        goto after_41;
    // 0x80023BD0: nop

    after_41:
    // 0x80023BD4: b           L_80023E58
    // 0x80023BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BDC:
    // 0x80023BDC: jal         0x80038894
    // 0x80023BE0: nop

    obj_init_infopoint(rdram, ctx);
        goto after_42;
    // 0x80023BE0: nop

    after_42:
    // 0x80023BE4: b           L_80023E58
    // 0x80023BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BEC:
    // 0x80023BEC: jal         0x8003C684
    // 0x80023BF0: nop

    obj_init_trigger(rdram, ctx);
        goto after_43;
    // 0x80023BF0: nop

    after_43:
    // 0x80023BF4: b           L_80023E58
    // 0x80023BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BFC:
    // 0x80023BFC: jal         0x800358CC
    // 0x80023C00: nop

    obj_init_airzippers_waterzippers(rdram, ctx);
        goto after_44;
    // 0x80023C00: nop

    after_44:
    // 0x80023C04: b           L_80023E58
    // 0x80023C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C0C:
    // 0x80023C0C: jal         0x80035E60
    // 0x80023C10: nop

    obj_init_timetrialghost(rdram, ctx);
        goto after_45;
    // 0x80023C10: nop

    after_45:
    // 0x80023C14: b           L_80023E58
    // 0x80023C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C1C:
    // 0x80023C1C: jal         0x800409E4
    // 0x80023C20: nop

    obj_init_wavegenerator(rdram, ctx);
        goto after_46;
    // 0x80023C20: nop

    after_46:
    // 0x80023C24: b           L_80023E58
    // 0x80023C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C2C:
    // 0x80023C2C: jal         0x80040A08
    // 0x80023C30: nop

    obj_init_butterfly(rdram, ctx);
        goto after_47;
    // 0x80023C30: nop

    after_47:
    // 0x80023C34: b           L_80023E58
    // 0x80023C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C3C:
    // 0x80023C3C: jal         0x800392F8
    // 0x80023C40: nop

    obj_init_parkwarden(rdram, ctx);
        goto after_48;
    // 0x80023C40: nop

    after_48:
    // 0x80023C44: b           L_80023E58
    // 0x80023C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C4C:
    // 0x80023C4C: jal         0x8003DEB4
    // 0x80023C50: nop

    obj_init_worldkey(rdram, ctx);
        goto after_49;
    // 0x80023C50: nop

    after_49:
    // 0x80023C54: b           L_80023E58
    // 0x80023C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C5C:
    // 0x80023C5C: jal         0x8003D42C
    // 0x80023C60: nop

    obj_init_bananacreator(rdram, ctx);
        goto after_50;
    // 0x80023C60: nop

    after_50:
    // 0x80023C64: b           L_80023E58
    // 0x80023C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C6C:
    // 0x80023C6C: jal         0x8003D078
    // 0x80023C70: nop

    obj_init_treasuresucker(rdram, ctx);
        goto after_51;
    // 0x80023C70: nop

    after_51:
    // 0x80023C74: b           L_80023E58
    // 0x80023C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C7C:
    // 0x80023C7C: jal         0x800375B8
    // 0x80023C80: nop

    obj_init_lavaspurt(rdram, ctx);
        goto after_52;
    // 0x80023C80: nop

    after_52:
    // 0x80023C84: b           L_80023E58
    // 0x80023C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C8C:
    // 0x80023C8C: jal         0x80037664
    // 0x80023C90: nop

    obj_init_posarrow(rdram, ctx);
        goto after_53;
    // 0x80023C90: nop

    after_53:
    // 0x80023C94: b           L_80023E58
    // 0x80023C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C9C:
    // 0x80023C9C: jal         0x800381CC
    // 0x80023CA0: nop

    obj_init_hittester(rdram, ctx);
        goto after_54;
    // 0x80023CA0: nop

    after_54:
    // 0x80023CA4: b           L_80023E58
    // 0x80023CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CAC:
    // 0x80023CAC: jal         0x80038220
    // 0x80023CB0: nop

    obj_init_dynamic_lighting_object(rdram, ctx);
        goto after_55;
    // 0x80023CB0: nop

    after_55:
    // 0x80023CB4: b           L_80023E58
    // 0x80023CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CBC:
    // 0x80023CBC: jal         0x80038254
    // 0x80023CC0: nop

    obj_init_unknown96(rdram, ctx);
        goto after_56;
    // 0x80023CC0: nop

    after_56:
    // 0x80023CC4: b           L_80023E58
    // 0x80023CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CCC:
    // 0x80023CCC: jal         0x80038288
    // 0x80023CD0: nop

    obj_init_snowball(rdram, ctx);
        goto after_57;
    // 0x80023CD0: nop

    after_57:
    // 0x80023CD4: b           L_80023E58
    // 0x80023CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CDC:
    // 0x80023CDC: jal         0x80041AD0
    // 0x80023CE0: nop

    obj_init_midifade(rdram, ctx);
        goto after_58;
    // 0x80023CE0: nop

    after_58:
    // 0x80023CE4: b           L_80023E58
    // 0x80023CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CEC:
    // 0x80023CEC: jal         0x80041EC0
    // 0x80023CF0: nop

    obj_init_midifadepoint(rdram, ctx);
        goto after_59;
    // 0x80023CF0: nop

    after_59:
    // 0x80023CF4: b           L_80023E58
    // 0x80023CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CFC:
    // 0x80023CFC: jal         0x80042054
    // 0x80023D00: nop

    obj_init_midichset(rdram, ctx);
        goto after_60;
    // 0x80023D00: nop

    after_60:
    // 0x80023D04: b           L_80023E58
    // 0x80023D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D0C:
    // 0x80023D0C: jal         0x80034BA8
    // 0x80023D10: nop

    obj_init_effectbox(rdram, ctx);
        goto after_61;
    // 0x80023D10: nop

    after_61:
    // 0x80023D14: b           L_80023E58
    // 0x80023D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D1C:
    // 0x80023D1C: jal         0x80034EB0
    // 0x80023D20: nop

    obj_init_trophycab(rdram, ctx);
        goto after_62;
    // 0x80023D20: nop

    after_62:
    // 0x80023D24: b           L_80023E58
    // 0x80023D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D2C:
    // 0x80023D2C: jal         0x8004207C
    // 0x80023D30: nop

    obj_init_bubbler(rdram, ctx);
        goto after_63;
    // 0x80023D30: nop

    after_63:
    // 0x80023D34: b           L_80023E58
    // 0x80023D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D3C:
    // 0x80023D3C: jal         0x8003D2EC
    // 0x80023D40: nop

    obj_init_flycoin(rdram, ctx);
        goto after_64;
    // 0x80023D40: nop

    after_64:
    // 0x80023D44: b           L_80023E58
    // 0x80023D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D4C:
    // 0x80023D4C: jal         0x8003B3A8
    // 0x80023D50: nop

    obj_init_goldenballoon(rdram, ctx);
        goto after_65;
    // 0x80023D50: nop

    after_65:
    // 0x80023D54: b           L_80023E58
    // 0x80023D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D5C:
    // 0x80023D5C: jal         0x80034884
    // 0x80023D60: nop

    obj_init_laserbolt(rdram, ctx);
        goto after_66;
    // 0x80023D60: nop

    after_66:
    // 0x80023D64: b           L_80023E58
    // 0x80023D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D6C:
    // 0x80023D6C: jal         0x80034570
    // 0x80023D70: nop

    obj_init_lasergun(rdram, ctx);
        goto after_67;
    // 0x80023D70: nop

    after_67:
    // 0x80023D74: b           L_80023E58
    // 0x80023D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D7C:
    // 0x80023D7C: jal         0x80035B28
    // 0x80023D80: nop

    obj_init_groundzipper(rdram, ctx);
        goto after_68;
    // 0x80023D80: nop

    after_68:
    // 0x80023D84: b           L_80023E58
    // 0x80023D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D8C:
    // 0x80023D8C: jal         0x80037D94
    // 0x80023D90: nop

    obj_init_overridepos(rdram, ctx);
        goto after_69;
    // 0x80023D90: nop

    after_69:
    // 0x80023D94: b           L_80023E58
    // 0x80023D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D9C:
    // 0x80023D9C: jal         0x80037DAC
    // 0x80023DA0: nop

    obj_init_wizpigship(rdram, ctx);
        goto after_70;
    // 0x80023DA0: nop

    after_70:
    // 0x80023DA4: b           L_80023E58
    // 0x80023DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DAC:
    // 0x80023DAC: jal         0x8004214C
    // 0x80023DB0: nop

    obj_init_boost(rdram, ctx);
        goto after_71;
    // 0x80023DB0: nop

    after_71:
    // 0x80023DB4: b           L_80023E58
    // 0x80023DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DBC:
    // 0x80023DBC: jal         0x8003DC9C
    // 0x80023DC0: nop

    obj_init_silvercoin(rdram, ctx);
        goto after_72;
    // 0x80023DC0: nop

    after_72:
    // 0x80023DC4: b           L_80023E58
    // 0x80023DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DCC:
    // 0x80023DCC: jal         0x80038B08
    // 0x80023DD0: nop

    obj_init_wardensmoke(rdram, ctx);
        goto after_73;
    // 0x80023DD0: nop

    after_73:
    // 0x80023DD4: b           L_80023E58
    // 0x80023DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DDC:
    // 0x80023DDC: jal         0x80042190
    // 0x80023DE0: nop

    obj_init_unknown94(rdram, ctx);
        goto after_74;
    // 0x80023DE0: nop

    after_74:
    // 0x80023DE4: b           L_80023E58
    // 0x80023DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DEC:
    // 0x80023DEC: jal         0x80038D98
    // 0x80023DF0: nop

    obj_init_teleport(rdram, ctx);
        goto after_75;
    // 0x80023DF0: nop

    after_75:
    // 0x80023DF4: b           L_80023E58
    // 0x80023DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DFC:
    // 0x80023DFC: jal         0x8003576C
    // 0x80023E00: nop

    obj_init_lighthouse_rocketsignpost(rdram, ctx);
        goto after_76;
    // 0x80023E00: nop

    after_76:
    // 0x80023E04: b           L_80023E58
    // 0x80023E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E0C:
    // 0x80023E0C: jal         0x800421AC
    // 0x80023E10: nop

    obj_init_rangetrigger(rdram, ctx);
        goto after_77;
    // 0x80023E10: nop

    after_77:
    // 0x80023E14: b           L_80023E58
    // 0x80023E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E1C:
    // 0x80023E1C: jal         0x80033F84
    // 0x80023E20: nop

    obj_init_fireball_octoweapon(rdram, ctx);
        goto after_78;
    // 0x80023E20: nop

    after_78:
    // 0x80023E24: b           L_80023E58
    // 0x80023E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E2C:
    // 0x80023E2C: jal         0x80042250
    // 0x80023E30: nop

    obj_init_frog(rdram, ctx);
        goto after_79;
    // 0x80023E30: nop

    after_79:
    // 0x80023E34: b           L_80023E58
    // 0x80023E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E3C:
    // 0x80023E3C: jal         0x8003DBE0
    // 0x80023E40: nop

    obj_init_silvercoin_adv2(rdram, ctx);
        goto after_80;
    // 0x80023E40: nop

    after_80:
    // 0x80023E44: b           L_80023E58
    // 0x80023E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E58;
    // 0x80023E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E4C:
    // 0x80023E4C: jal         0x80042A5C
    // 0x80023E50: nop

    obj_init_levelname(rdram, ctx);
        goto after_81;
    // 0x80023E50: nop

    after_81:
L_80023E54:
    // 0x80023E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E58:
    // 0x80023E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023E5C: jr          $ra
    // 0x80023E60: nop

    return;
    // 0x80023E60: nop

;}
RECOMP_FUNC void obj_init_property_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023E64: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80023E68: sltiu       $at, $t6, 0x74
    ctx->r1 = ctx->r14 < 0X74 ? 1 : 0;
    // 0x80023E6C: beq         $at, $zero, L_80023F74
    if (ctx->r1 == 0) {
        // 0x80023E70: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80023F74;
    }
    // 0x80023E70: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80023E74: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80023E78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80023E7C: addu        $at, $at, $t6
    gpr jr_addend_80023E88 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80023E80: lw          $t6, 0x5FCC($at)
    ctx->r14 = ADD32(ctx->r1, 0X5FCC);
    // 0x80023E84: nop

    // 0x80023E88: jr          $t6
    // 0x80023E8C: nop

    switch (jr_addend_80023E88 >> 2) {
        case 0: goto L_80023E90; break;
        case 1: goto L_80023E98; break;
        case 2: goto L_80023F74; break;
        case 3: goto L_80023F74; break;
        case 4: goto L_80023EA0; break;
        case 5: goto L_80023F74; break;
        case 6: goto L_80023F48; break;
        case 7: goto L_80023F74; break;
        case 8: goto L_80023F74; break;
        case 9: goto L_80023F74; break;
        case 10: goto L_80023F74; break;
        case 11: goto L_80023EA8; break;
        case 12: goto L_80023F48; break;
        case 13: goto L_80023EB0; break;
        case 14: goto L_80023F74; break;
        case 15: goto L_80023F74; break;
        case 16: goto L_80023EB8; break;
        case 17: goto L_80023F48; break;
        case 18: goto L_80023F74; break;
        case 19: goto L_80023F74; break;
        case 20: goto L_80023F74; break;
        case 21: goto L_80023F74; break;
        case 22: goto L_80023F74; break;
        case 23: goto L_80023ED0; break;
        case 24: goto L_80023F74; break;
        case 25: goto L_80023F48; break;
        case 26: goto L_80023F74; break;
        case 27: goto L_80023F74; break;
        case 28: goto L_80023F74; break;
        case 29: goto L_80023F48; break;
        case 30: goto L_80023ED8; break;
        case 31: goto L_80023EE0; break;
        case 32: goto L_80023F74; break;
        case 33: goto L_80023F74; break;
        case 34: goto L_80023F74; break;
        case 35: goto L_80023F48; break;
        case 36: goto L_80023F74; break;
        case 37: goto L_80023EF0; break;
        case 38: goto L_80023EF8; break;
        case 39: goto L_80023F00; break;
        case 40: goto L_80023F48; break;
        case 41: goto L_80023F74; break;
        case 42: goto L_80023F74; break;
        case 43: goto L_80023F74; break;
        case 44: goto L_80023F08; break;
        case 45: goto L_80023F74; break;
        case 46: goto L_80023F74; break;
        case 47: goto L_80023F10; break;
        case 48: goto L_80023F58; break;
        case 49: goto L_80023F20; break;
        case 50: goto L_80023F58; break;
        case 51: goto L_80023F48; break;
        case 52: goto L_80023F74; break;
        case 53: goto L_80023F28; break;
        case 54: goto L_80023F48; break;
        case 55: goto L_80023F20; break;
        case 56: goto L_80023F48; break;
        case 57: goto L_80023F74; break;
        case 58: goto L_80023F74; break;
        case 59: goto L_80023F74; break;
        case 60: goto L_80023F58; break;
        case 61: goto L_80023F60; break;
        case 62: goto L_80023F18; break;
        case 63: goto L_80023EE0; break;
        case 64: goto L_80023F74; break;
        case 65: goto L_80023F74; break;
        case 66: goto L_80023EE8; break;
        case 67: goto L_80023F48; break;
        case 68: goto L_80023F74; break;
        case 69: goto L_80023EC0; break;
        case 70: goto L_80023F74; break;
        case 71: goto L_80023EC0; break;
        case 72: goto L_80023F74; break;
        case 73: goto L_80023F30; break;
        case 74: goto L_80023F74; break;
        case 75: goto L_80023F74; break;
        case 76: goto L_80023EB8; break;
        case 77: goto L_80023F48; break;
        case 78: goto L_80023F48; break;
        case 79: goto L_80023F20; break;
        case 80: goto L_80023F40; break;
        case 81: goto L_80023F50; break;
        case 82: goto L_80023F74; break;
        case 83: goto L_80023F20; break;
        case 84: goto L_80023F74; break;
        case 85: goto L_80023F20; break;
        case 86: goto L_80023F74; break;
        case 87: goto L_80023EE0; break;
        case 88: goto L_80023F74; break;
        case 89: goto L_80023F74; break;
        case 90: goto L_80023F38; break;
        case 91: goto L_80023F74; break;
        case 92: goto L_80023F48; break;
        case 93: goto L_80023F74; break;
        case 94: goto L_80023F30; break;
        case 95: goto L_80023EC0; break;
        case 96: goto L_80023EC0; break;
        case 97: goto L_80023F48; break;
        case 98: goto L_80023F30; break;
        case 99: goto L_80023F30; break;
        case 100: goto L_80023EC8; break;
        case 101: goto L_80023EC8; break;
        case 102: goto L_80023EC8; break;
        case 103: goto L_80023EC8; break;
        case 104: goto L_80023F74; break;
        case 105: goto L_80023F74; break;
        case 106: goto L_80023F74; break;
        case 107: goto L_80023F48; break;
        case 108: goto L_80023F68; break;
        case 109: goto L_80023EE0; break;
        case 110: goto L_80023EB0; break;
        case 111: goto L_80023F74; break;
        case 112: goto L_80023F74; break;
        case 113: goto L_80023F70; break;
        case 114: goto L_80023F20; break;
        case 115: goto L_80023F48; break;
        default: switch_error(__func__, 0x80023E88, 0x800E5FCC);
    }
    // 0x80023E8C: nop

L_80023E90:
    // 0x80023E90: jr          $ra
    // 0x80023E94: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    return;
    // 0x80023E94: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_80023E98:
    // 0x80023E98: jr          $ra
    // 0x80023E9C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    return;
    // 0x80023E9C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_80023EA0:
    // 0x80023EA0: jr          $ra
    // 0x80023EA4: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    return;
    // 0x80023EA4: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_80023EA8:
    // 0x80023EA8: jr          $ra
    // 0x80023EAC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80023EAC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80023EB0:
    // 0x80023EB0: jr          $ra
    // 0x80023EB4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    return;
    // 0x80023EB4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_80023EB8:
    // 0x80023EB8: jr          $ra
    // 0x80023EBC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023EBC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023EC0:
    // 0x80023EC0: jr          $ra
    // 0x80023EC4: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    return;
    // 0x80023EC4: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
L_80023EC8:
    // 0x80023EC8: jr          $ra
    // 0x80023ECC: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
    return;
    // 0x80023ECC: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
L_80023ED0:
    // 0x80023ED0: jr          $ra
    // 0x80023ED4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80023ED4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80023ED8:
    // 0x80023ED8: jr          $ra
    // 0x80023EDC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80023EDC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80023EE0:
    // 0x80023EE0: jr          $ra
    // 0x80023EE4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023EE4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023EE8:
    // 0x80023EE8: jr          $ra
    // 0x80023EEC: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    return;
    // 0x80023EEC: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_80023EF0:
    // 0x80023EF0: jr          $ra
    // 0x80023EF4: addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    return;
    // 0x80023EF4: addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
L_80023EF8:
    // 0x80023EF8: jr          $ra
    // 0x80023EFC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023EFC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023F00:
    // 0x80023F00: jr          $ra
    // 0x80023F04: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x80023F04: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80023F08:
    // 0x80023F08: jr          $ra
    // 0x80023F0C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023F0C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023F10:
    // 0x80023F10: jr          $ra
    // 0x80023F14: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x80023F14: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80023F18:
    // 0x80023F18: jr          $ra
    // 0x80023F1C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x80023F1C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80023F20:
    // 0x80023F20: jr          $ra
    // 0x80023F24: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x80023F24: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80023F28:
    // 0x80023F28: jr          $ra
    // 0x80023F2C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x80023F2C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80023F30:
    // 0x80023F30: jr          $ra
    // 0x80023F34: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    return;
    // 0x80023F34: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
L_80023F38:
    // 0x80023F38: jr          $ra
    // 0x80023F3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80023F3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80023F40:
    // 0x80023F40: jr          $ra
    // 0x80023F44: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x80023F44: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80023F48:
    // 0x80023F48: jr          $ra
    // 0x80023F4C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x80023F4C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80023F50:
    // 0x80023F50: jr          $ra
    // 0x80023F54: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023F54: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023F58:
    // 0x80023F58: jr          $ra
    // 0x80023F5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80023F5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80023F60:
    // 0x80023F60: jr          $ra
    // 0x80023F64: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80023F64: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80023F68:
    // 0x80023F68: jr          $ra
    // 0x80023F6C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x80023F6C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80023F70:
    // 0x80023F70: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80023F74:
    // 0x80023F74: jr          $ra
    // 0x80023F78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80023F78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void run_object_loop_func(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023F7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023F84: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80023F88: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80023F8C: lh          $a1, 0x4A($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X4A);
    // 0x80023F90: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80023F94: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80023F98: jal         0x800B7BD8
    // 0x80023F9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    update_object_stack_trace(rdram, ctx);
        goto after_0;
    // 0x80023F9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80023FA0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80023FA4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80023FA8: lh          $t6, 0x48($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X48);
    // 0x80023FAC: nop

    // 0x80023FB0: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80023FB4: sltiu       $at, $t7, 0x76
    ctx->r1 = ctx->r15 < 0X76 ? 1 : 0;
    // 0x80023FB8: beq         $at, $zero, L_800245A4
    if (ctx->r1 == 0) {
        // 0x80023FBC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800245A4;
    }
    // 0x80023FBC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80023FC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80023FC4: addu        $at, $at, $t7
    gpr jr_addend_80023FD0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80023FC8: lw          $t7, 0x619C($at)
    ctx->r15 = ADD32(ctx->r1, 0X619C);
    // 0x80023FCC: nop

    // 0x80023FD0: jr          $t7
    // 0x80023FD4: nop

    switch (jr_addend_80023FD0 >> 2) {
        case 0: goto L_80023FD8; break;
        case 1: goto L_80023FEC; break;
        case 2: goto L_80024000; break;
        case 3: goto L_8002413C; break;
        case 4: goto L_80024014; break;
        case 5: goto L_80024050; break;
        case 6: goto L_800245A4; break;
        case 7: goto L_800245A4; break;
        case 8: goto L_80024064; break;
        case 9: goto L_80024078; break;
        case 10: goto L_8002408C; break;
        case 11: goto L_800240A0; break;
        case 12: goto L_800240DC; break;
        case 13: goto L_800240F0; break;
        case 14: goto L_80024100; break;
        case 15: goto L_80024114; break;
        case 16: goto L_8002413C; break;
        case 17: goto L_800245A4; break;
        case 18: goto L_800245A4; break;
        case 19: goto L_800245A4; break;
        case 20: goto L_8002403C; break;
        case 21: goto L_80024128; break;
        case 22: goto L_800245A4; break;
        case 23: goto L_80024028; break;
        case 24: goto L_80024150; break;
        case 25: goto L_800245A4; break;
        case 26: goto L_80024164; break;
        case 27: goto L_80024178; break;
        case 28: goto L_800240B4; break;
        case 29: goto L_8002418C; break;
        case 30: goto L_800241A0; break;
        case 31: goto L_800245A4; break;
        case 32: goto L_800245A4; break;
        case 33: goto L_800245A4; break;
        case 34: goto L_800241B4; break;
        case 35: goto L_800241DC; break;
        case 36: goto L_800241F0; break;
        case 37: goto L_80024204; break;
        case 38: goto L_80024218; break;
        case 39: goto L_800240C8; break;
        case 40: goto L_800245A4; break;
        case 41: goto L_800245A4; break;
        case 42: goto L_800245A4; break;
        case 43: goto L_8002422C; break;
        case 44: goto L_80024240; break;
        case 45: goto L_80024254; break;
        case 46: goto L_800245A4; break;
        case 47: goto L_800245A4; break;
        case 48: goto L_80024268; break;
        case 49: goto L_80024290; break;
        case 50: goto L_800242A4; break;
        case 51: goto L_800242B8; break;
        case 52: goto L_800242CC; break;
        case 53: goto L_800242E0; break;
        case 54: goto L_800242F4; break;
        case 55: goto L_80024308; break;
        case 56: goto L_8002431C; break;
        case 57: goto L_800245A4; break;
        case 58: goto L_80024330; break;
        case 59: goto L_80024340; break;
        case 60: goto L_80024354; break;
        case 61: goto L_800245A4; break;
        case 62: goto L_80024368; break;
        case 63: goto L_8002437C; break;
        case 64: goto L_80024390; break;
        case 65: goto L_800241C8; break;
        case 66: goto L_800243A4; break;
        case 67: goto L_800243B8; break;
        case 68: goto L_800243CC; break;
        case 69: goto L_800245A4; break;
        case 70: goto L_800243CC; break;
        case 71: goto L_800243F4; break;
        case 72: goto L_80024408; break;
        case 73: goto L_8002441C; break;
        case 74: goto L_80024430; break;
        case 75: goto L_80024444; break;
        case 76: goto L_80024458; break;
        case 77: goto L_8002446C; break;
        case 78: goto L_80024480; break;
        case 79: goto L_80024268; break;
        case 80: goto L_80024494; break;
        case 81: goto L_800245A4; break;
        case 82: goto L_800244A8; break;
        case 83: goto L_80024268; break;
        case 84: goto L_80024268; break;
        case 85: goto L_800245A4; break;
        case 86: goto L_800244BC; break;
        case 87: goto L_800245A4; break;
        case 88: goto L_800244D0; break;
        case 89: goto L_800245A4; break;
        case 90: goto L_800245A4; break;
        case 91: goto L_80024308; break;
        case 92: goto L_800244E4; break;
        case 93: goto L_800245A4; break;
        case 94: goto L_800243E0; break;
        case 95: goto L_800243E0; break;
        case 96: goto L_800244F8; break;
        case 97: goto L_800245A4; break;
        case 98: goto L_80024520; break;
        case 99: goto L_800243E0; break;
        case 100: goto L_800243E0; break;
        case 101: goto L_800243CC; break;
        case 102: goto L_800243CC; break;
        case 103: goto L_8002450C; break;
        case 104: goto L_800245A4; break;
        case 105: goto L_800245A4; break;
        case 106: goto L_80024534; break;
        case 107: goto L_80024548; break;
        case 108: goto L_800244BC; break;
        case 109: goto L_8002455C; break;
        case 110: goto L_800245A4; break;
        case 111: goto L_80024570; break;
        case 112: goto L_800245A4; break;
        case 113: goto L_80024584; break;
        case 114: goto L_80024534; break;
        case 115: goto L_80024598; break;
        case 116: goto L_800245A4; break;
        case 117: goto L_8002427C; break;
        default: switch_error(__func__, 0x80023FD0, 0x800E619C);
    }
    // 0x80023FD4: nop

L_80023FD8:
    // 0x80023FD8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80023FDC: jal         0x80033E10
    // 0x80023FE0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_scenery(rdram, ctx);
        goto after_1;
    // 0x80023FE0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x80023FE4: b           L_800245A8
    // 0x80023FE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80023FE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80023FEC:
    // 0x80023FEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80023FF0: jal         0x80037114
    // 0x80023FF4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_fish(rdram, ctx);
        goto after_2;
    // 0x80023FF4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
    // 0x80023FF8: b           L_800245A8
    // 0x80023FFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80023FFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024000:
    // 0x80024000: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024004: jal         0x80037824
    // 0x80024008: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_animator(rdram, ctx);
        goto after_3;
    // 0x80024008: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_3:
    // 0x8002400C: b           L_800245A8
    // 0x80024010: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024010: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024014:
    // 0x80024014: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024018: jal         0x800389F8
    // 0x8002401C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_smoke(rdram, ctx);
        goto after_4;
    // 0x8002401C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_4:
    // 0x80024020: b           L_800245A8
    // 0x80024024: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024024: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024028:
    // 0x80024028: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002402C: jal         0x80038AB8
    // 0x80024030: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_unknown25(rdram, ctx);
        goto after_5;
    // 0x80024030: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_5:
    // 0x80024034: b           L_800245A8
    // 0x80024038: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024038: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002403C:
    // 0x8002403C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024040: jal         0x80038C34
    // 0x80024044: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bombexplosion(rdram, ctx);
        goto after_6;
    // 0x80024044: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_6:
    // 0x80024048: b           L_800245A8
    // 0x8002404C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002404C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024050:
    // 0x80024050: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024054: jal         0x80038F98
    // 0x80024058: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_exit(rdram, ctx);
        goto after_7;
    // 0x80024058: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_7:
    // 0x8002405C: b           L_800245A8
    // 0x80024060: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024060: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024064:
    // 0x80024064: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024068: jal         0x800391C4
    // 0x8002406C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_cameracontrol(rdram, ctx);
        goto after_8;
    // 0x8002406C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_8:
    // 0x80024070: b           L_800245A8
    // 0x80024074: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024074: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024078:
    // 0x80024078: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002407C: jal         0x800391FC
    // 0x80024080: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_setuppoint(rdram, ctx);
        goto after_9;
    // 0x80024080: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_9:
    // 0x80024084: b           L_800245A8
    // 0x80024088: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024088: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002408C:
    // 0x8002408C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024090: jal         0x8003923C
    // 0x80024094: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_dino_whale(rdram, ctx);
        goto after_10;
    // 0x80024094: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_10:
    // 0x80024098: b           L_800245A8
    // 0x8002409C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002409C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240A0:
    // 0x800240A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800240A4: jal         0x8003AD68
    // 0x800240A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_checkpoint(rdram, ctx);
        goto after_11;
    // 0x800240A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_11:
    // 0x800240AC: b           L_800245A8
    // 0x800240B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800240B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240B4:
    // 0x800240B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800240B8: jal         0x8003AE90
    // 0x800240BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_modechange(rdram, ctx);
        goto after_12;
    // 0x800240BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_12:
    // 0x800240C0: b           L_800245A8
    // 0x800240C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800240C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240C8:
    // 0x800240C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800240CC: jal         0x8003B1B4
    // 0x800240D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bonus(rdram, ctx);
        goto after_13;
    // 0x800240D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_13:
    // 0x800240D4: b           L_800245A8
    // 0x800240D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800240D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240DC:
    // 0x800240DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800240E0: jal         0x8003B9C8
    // 0x800240E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_door(rdram, ctx);
        goto after_14;
    // 0x800240E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_14:
    // 0x800240E8: b           L_800245A8
    // 0x800240EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800240EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240F0:
    // 0x800240F0: jal         0x80030AB4
    // 0x800240F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    obj_loop_fogchanger(rdram, ctx);
        goto after_15;
    // 0x800240F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_15:
    // 0x800240F8: b           L_800245A8
    // 0x800240FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800240FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024100:
    // 0x80024100: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024104: jal         0x8003D06C
    // 0x80024108: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_ainode(rdram, ctx);
        goto after_16;
    // 0x80024108: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_16:
    // 0x8002410C: b           L_800245A8
    // 0x80024110: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024110: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024114:
    // 0x80024114: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024118: jal         0x8003E180
    // 0x8002411C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_weaponballoon(rdram, ctx);
        goto after_17;
    // 0x8002411C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_17:
    // 0x80024120: b           L_800245A8
    // 0x80024124: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024124: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024128:
    // 0x80024128: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002412C: jal         0x8003E5FC
    // 0x80024130: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_wballoonpop(rdram, ctx);
        goto after_18;
    // 0x80024130: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_18:
    // 0x80024134: b           L_800245A8
    // 0x80024138: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024138: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002413C:
    // 0x8002413C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024140: jal         0x8003E670
    // 0x80024144: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_weapon(rdram, ctx);
        goto after_19;
    // 0x80024144: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_19:
    // 0x80024148: b           L_800245A8
    // 0x8002414C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002414C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024150:
    // 0x80024150: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024154: jal         0x8003CFD8
    // 0x80024158: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_skycontrol(rdram, ctx);
        goto after_20;
    // 0x80024158: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_20:
    // 0x8002415C: b           L_800245A8
    // 0x80024160: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024160: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024164:
    // 0x80024164: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024168: jal         0x80034B8C
    // 0x8002416C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_torch_mist(rdram, ctx);
        goto after_21;
    // 0x8002416C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_21:
    // 0x80024170: b           L_800245A8
    // 0x80024174: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024174: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024178:
    // 0x80024178: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002417C: jal         0x80040188
    // 0x80024180: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_texscroll(rdram, ctx);
        goto after_22;
    // 0x80024180: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_22:
    // 0x80024184: b           L_800245A8
    // 0x80024188: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024188: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002418C:
    // 0x8002418C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024190: jal         0x80036220
    // 0x80024194: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_stopwatchman(rdram, ctx);
        goto after_23;
    // 0x80024194: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_23:
    // 0x80024198: b           L_800245A8
    // 0x8002419C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002419C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241A0:
    // 0x800241A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241A4: jal         0x8003D5E0
    // 0x800241A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_banana(rdram, ctx);
        goto after_24;
    // 0x800241A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_24:
    // 0x800241AC: b           L_800245A8
    // 0x800241B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800241B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241B4:
    // 0x800241B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241B8: jal         0x80040488
    // 0x800241BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_buoy_pirateship(rdram, ctx);
        goto after_25;
    // 0x800241BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_25:
    // 0x800241C0: b           L_800245A8
    // 0x800241C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800241C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241C8:
    // 0x800241C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241CC: jal         0x800405B0
    // 0x800241D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_log(rdram, ctx);
        goto after_26;
    // 0x800241D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_26:
    // 0x800241D4: b           L_800245A8
    // 0x800241D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800241D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241DC:
    // 0x800241DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241E0: jal         0x80040860
    // 0x800241E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_weather(rdram, ctx);
        goto after_27;
    // 0x800241E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_27:
    // 0x800241E8: b           L_800245A8
    // 0x800241EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800241EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241F0:
    // 0x800241F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241F4: jal         0x8003CAA8
    // 0x800241F8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bridge_whaleramp(rdram, ctx);
        goto after_28;
    // 0x800241F8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_28:
    // 0x800241FC: b           L_800245A8
    // 0x80024200: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024200: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024204:
    // 0x80024204: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024208: jal         0x8003CEE0
    // 0x8002420C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_rampswitch(rdram, ctx);
        goto after_29;
    // 0x8002420C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_29:
    // 0x80024210: b           L_800245A8
    // 0x80024214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024218:
    // 0x80024218: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002421C: jal         0x8003CF4C
    // 0x80024220: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_seamonster(rdram, ctx);
        goto after_30;
    // 0x80024220: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_30:
    // 0x80024224: b           L_800245A8
    // 0x80024228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002422C:
    // 0x8002422C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024230: jal         0x800352A0
    // 0x80024234: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_collectegg(rdram, ctx);
        goto after_31;
    // 0x80024234: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_31:
    // 0x80024238: b           L_800245A8
    // 0x8002423C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002423C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024240:
    // 0x80024240: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024244: jal         0x8003568C
    // 0x80024248: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_eggcreator(rdram, ctx);
        goto after_32;
    // 0x80024248: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_32:
    // 0x8002424C: b           L_800245A8
    // 0x80024250: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024250: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024254:
    // 0x80024254: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024258: jal         0x80035FAC
    // 0x8002425C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_characterflag(rdram, ctx);
        goto after_33;
    // 0x8002425C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_33:
    // 0x80024260: b           L_800245A8
    // 0x80024264: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024264: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024268:
    // 0x80024268: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002426C: jal         0x80037D28
    // 0x80024270: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_animobject(rdram, ctx);
        goto after_34;
    // 0x80024270: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_34:
    // 0x80024274: b           L_800245A8
    // 0x80024278: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024278: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002427C:
    // 0x8002427C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024280: jal         0x80042D10
    // 0x80024284: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_wizghosts(rdram, ctx);
        goto after_35;
    // 0x80024284: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_35:
    // 0x80024288: b           L_800245A8
    // 0x8002428C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002428C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024290:
    // 0x80024290: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024294: jal         0x80038750
    // 0x80024298: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_animcamera(rdram, ctx);
        goto after_36;
    // 0x80024298: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_36:
    // 0x8002429C: b           L_800245A8
    // 0x800242A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800242A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242A4:
    // 0x800242A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242A8: jal         0x80038914
    // 0x800242AC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_infopoint(rdram, ctx);
        goto after_37;
    // 0x800242AC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_37:
    // 0x800242B0: b           L_800245A8
    // 0x800242B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800242B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242B8:
    // 0x800242B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242BC: jal         0x8003880C
    // 0x800242C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_animcar(rdram, ctx);
        goto after_38;
    // 0x800242C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_38:
    // 0x800242C4: b           L_800245A8
    // 0x800242C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800242C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242CC:
    // 0x800242CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242D0: jal         0x8003837C
    // 0x800242D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_char_select(rdram, ctx);
        goto after_39;
    // 0x800242D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_39:
    // 0x800242D8: b           L_800245A8
    // 0x800242DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800242DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242E0:
    // 0x800242E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242E4: jal         0x8003C7E4
    // 0x800242E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_trigger(rdram, ctx);
        goto after_40;
    // 0x800242E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_40:
    // 0x800242EC: b           L_800245A8
    // 0x800242F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800242F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242F4:
    // 0x800242F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242F8: jal         0x80038138
    // 0x800242FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_vehicleanim(rdram, ctx);
        goto after_41;
    // 0x800242FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_41:
    // 0x80024300: b           L_800245A8
    // 0x80024304: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024304: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024308:
    // 0x80024308: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002430C: jal         0x800359AC
    // 0x80024310: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_airzippers_waterzippers(rdram, ctx);
        goto after_42;
    // 0x80024310: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_42:
    // 0x80024314: b           L_800245A8
    // 0x80024318: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024318: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002431C:
    // 0x8002431C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024320: jal         0x80035E74
    // 0x80024324: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_timetrialghost(rdram, ctx);
        goto after_43;
    // 0x80024324: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_43:
    // 0x80024328: b           L_800245A8
    // 0x8002432C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002432C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024330:
    // 0x80024330: jal         0x800C04FC
    // 0x80024334: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    obj_loop_wavepower(rdram, ctx);
        goto after_44;
    // 0x80024334: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_44:
    // 0x80024338: b           L_800245A8
    // 0x8002433C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002433C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024340:
    // 0x80024340: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024344: jal         0x80040C94
    // 0x80024348: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_butterfly(rdram, ctx);
        goto after_45;
    // 0x80024348: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_45:
    // 0x8002434C: b           L_800245A8
    // 0x80024350: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024350: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024354:
    // 0x80024354: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024358: jal         0x80039370
    // 0x8002435C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_parkwarden(rdram, ctx);
        goto after_46;
    // 0x8002435C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_46:
    // 0x80024360: b           L_800245A8
    // 0x80024364: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024364: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024368:
    // 0x80024368: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002436C: jal         0x8003DF48
    // 0x80024370: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_worldkey(rdram, ctx);
        goto after_47;
    // 0x80024370: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_47:
    // 0x80024374: b           L_800245A8
    // 0x80024378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002437C:
    // 0x8002437C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024380: jal         0x8003D43C
    // 0x80024384: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bananacreator(rdram, ctx);
        goto after_48;
    // 0x80024384: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_48:
    // 0x80024388: b           L_800245A8
    // 0x8002438C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002438C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024390:
    // 0x80024390: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024394: jal         0x8003D098
    // 0x80024398: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_treasuresucker(rdram, ctx);
        goto after_49;
    // 0x80024398: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_49:
    // 0x8002439C: b           L_800245A8
    // 0x800243A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800243A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243A4:
    // 0x800243A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243A8: jal         0x800375D4
    // 0x800243AC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_lavaspurt(rdram, ctx);
        goto after_50;
    // 0x800243AC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_50:
    // 0x800243B0: b           L_800245A8
    // 0x800243B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800243B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243B8:
    // 0x800243B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243BC: jal         0x8003767C
    // 0x800243C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_posarrow(rdram, ctx);
        goto after_51;
    // 0x800243C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_51:
    // 0x800243C4: b           L_800245A8
    // 0x800243C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800243C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243CC:
    // 0x800243CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243D0: jal         0x80038200
    // 0x800243D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_hittester(rdram, ctx);
        goto after_52;
    // 0x800243D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_52:
    // 0x800243D8: b           L_800245A8
    // 0x800243DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800243DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243E0:
    // 0x800243E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243E4: jal         0x800382BC
    // 0x800243E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_snowball(rdram, ctx);
        goto after_53;
    // 0x800243E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_53:
    // 0x800243EC: b           L_800245A8
    // 0x800243F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800243F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243F4:
    // 0x800243F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243F8: jal         0x80034BB4
    // 0x800243FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_effectbox(rdram, ctx);
        goto after_54;
    // 0x800243FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_54:
    // 0x80024400: b           L_800245A8
    // 0x80024404: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024404: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024408:
    // 0x80024408: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002440C: jal         0x80034EDC
    // 0x80024410: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_trophycab(rdram, ctx);
        goto after_55;
    // 0x80024410: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_55:
    // 0x80024414: b           L_800245A8
    // 0x80024418: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024418: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002441C:
    // 0x8002441C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024420: jal         0x800420D0
    // 0x80024424: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bubbler(rdram, ctx);
        goto after_56;
    // 0x80024424: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_56:
    // 0x80024428: b           L_800245A8
    // 0x8002442C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002442C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024430:
    // 0x80024430: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024434: jal         0x8003D2F8
    // 0x80024438: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_flycoin(rdram, ctx);
        goto after_57;
    // 0x80024438: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_57:
    // 0x8002443C: b           L_800245A8
    // 0x80024440: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024440: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024444:
    // 0x80024444: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024448: jal         0x8003B4FC
    // 0x8002444C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_goldenballoon(rdram, ctx);
        goto after_58;
    // 0x8002444C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_58:
    // 0x80024450: b           L_800245A8
    // 0x80024454: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024454: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024458:
    // 0x80024458: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002445C: jal         0x800348A0
    // 0x80024460: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_laserbolt(rdram, ctx);
        goto after_59;
    // 0x80024460: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_59:
    // 0x80024464: b           L_800245A8
    // 0x80024468: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024468: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002446C:
    // 0x8002446C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024470: jal         0x800345E0
    // 0x80024474: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_lasergun(rdram, ctx);
        goto after_60;
    // 0x80024474: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_60:
    // 0x80024478: b           L_800245A8
    // 0x8002447C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002447C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024480:
    // 0x80024480: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024484: jal         0x8003ACE0
    // 0x80024488: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_gbparkwarden(rdram, ctx);
        goto after_61;
    // 0x80024488: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_61:
    // 0x8002448C: b           L_800245A8
    // 0x80024490: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024490: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024494:
    // 0x80024494: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024498: jal         0x80035C90
    // 0x8002449C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_groundzipper(rdram, ctx);
        goto after_62;
    // 0x8002449C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_62:
    // 0x800244A0: b           L_800245A8
    // 0x800244A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800244A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244A8:
    // 0x800244A8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244AC: jal         0x80037DB8
    // 0x800244B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_wizpigship(rdram, ctx);
        goto after_63;
    // 0x800244B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_63:
    // 0x800244B4: b           L_800245A8
    // 0x800244B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800244B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244BC:
    // 0x800244BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244C0: jal         0x8003DD54
    // 0x800244C4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_silvercoin(rdram, ctx);
        goto after_64;
    // 0x800244C4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_64:
    // 0x800244C8: b           L_800245A8
    // 0x800244CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800244CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244D0:
    // 0x800244D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244D4: jal         0x80038B14
    // 0x800244D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_wardensmoke(rdram, ctx);
        goto after_65;
    // 0x800244D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_65:
    // 0x800244DC: b           L_800245A8
    // 0x800244E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800244E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244E4:
    // 0x800244E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244E8: jal         0x800421A0
    // 0x800244EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_unknown94(rdram, ctx);
        goto after_66;
    // 0x800244EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_66:
    // 0x800244F0: b           L_800245A8
    // 0x800244F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800244F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244F8:
    // 0x800244F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244FC: jal         0x80038E04
    // 0x80024500: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_teleport(rdram, ctx);
        goto after_67;
    // 0x80024500: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_67:
    // 0x80024504: b           L_800245A8
    // 0x80024508: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024508: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002450C:
    // 0x8002450C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024510: jal         0x800421B8
    // 0x80024514: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_rangetrigger(rdram, ctx);
        goto after_68;
    // 0x80024514: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_68:
    // 0x80024518: b           L_800245A8
    // 0x8002451C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002451C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024520:
    // 0x80024520: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024524: jal         0x80035814
    // 0x80024528: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_rocketsignpost(rdram, ctx);
        goto after_69;
    // 0x80024528: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_69:
    // 0x8002452C: b           L_800245A8
    // 0x80024530: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024530: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024534:
    // 0x80024534: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024538: jal         0x80033FA0
    // 0x8002453C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_fireball_octoweapon(rdram, ctx);
        goto after_70;
    // 0x8002453C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_70:
    // 0x80024540: b           L_800245A8
    // 0x80024544: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024544: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024548:
    // 0x80024548: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002454C: jal         0x80042330
    // 0x80024550: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_frog(rdram, ctx);
        goto after_71;
    // 0x80024550: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_71:
    // 0x80024554: b           L_800245A8
    // 0x80024558: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024558: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002455C:
    // 0x8002455C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024560: jal         0x8003C324
    // 0x80024564: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_ttdoor(rdram, ctx);
        goto after_72;
    // 0x80024564: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_72:
    // 0x80024568: b           L_800245A8
    // 0x8002456C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002456C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024570:
    // 0x80024570: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024574: jal         0x80037D48
    // 0x80024578: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_dooropener(rdram, ctx);
        goto after_73;
    // 0x80024578: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_73:
    // 0x8002457C: b           L_800245A8
    // 0x80024580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024584:
    // 0x80024584: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024588: jal         0x800429D8
    // 0x8002458C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_pigrocketeer(rdram, ctx);
        goto after_74;
    // 0x8002458C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_74:
    // 0x80024590: b           L_800245A8
    // 0x80024594: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024594: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024598:
    // 0x80024598: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002459C: jal         0x80042AD0
    // 0x800245A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_levelname(rdram, ctx);
        goto after_75;
    // 0x800245A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_75:
L_800245A4:
    // 0x800245A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800245A8:
    // 0x800245A8: jal         0x800B7BD8
    // 0x800245AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    update_object_stack_trace(rdram, ctx);
        goto after_76;
    // 0x800245AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_76:
    // 0x800245B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800245B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800245B8: jr          $ra
    // 0x800245BC: nop

    return;
    // 0x800245BC: nop

;}
RECOMP_FUNC void func_8002458C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800245C0: jr          $ra
    // 0x800245C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800245C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80024594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800245C8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800245CC: lw          $t6, -0x3390($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3390);
    // 0x800245D0: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800245D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800245D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800245DC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800245E0: jr          $ra
    // 0x800245E4: addiu       $v0, $v0, -0x4E60
    ctx->r2 = ADD32(ctx->r2, -0X4E60);
    return;
    // 0x800245E4: addiu       $v0, $v0, -0x4E60
    ctx->r2 = ADD32(ctx->r2, -0X4E60);
;}
RECOMP_FUNC void func_800245B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800245E8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800245EC: addiu       $v1, $v1, -0x3390
    ctx->r3 = ADD32(ctx->r3, -0X3390);
    // 0x800245F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800245F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800245F8: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800245FC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80024600: sh          $a0, -0x4E60($at)
    MEM_H(-0X4E60, ctx->r1) = ctx->r4;
    // 0x80024604: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80024608: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x8002460C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80024610: bne         $at, $zero, L_8002461C
    if (ctx->r1 != 0) {
        // 0x80024614: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_8002461C;
    }
    // 0x80024614: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80024618: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8002461C:
    // 0x8002461C: jr          $ra
    // 0x80024620: nop

    return;
    // 0x80024620: nop

    // 0x80024624: nop

    // 0x80024628: nop

    // 0x8002462C: nop

;}
RECOMP_FUNC void obj_shade_fast(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024630: lw          $a3, 0x54($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X54);
    // 0x80024634: beq         $a3, $zero, L_8002477C
    if (ctx->r7 == 0) {
        // 0x80024638: nop
    
            goto L_8002477C;
    }
    // 0x80024638: nop

    // 0x8002463C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80024640: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80024644: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80024648: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8002464C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80024650: lh          $t0, 0x28($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X28);
    // 0x80024654: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80024658: lw          $t5, 0x38($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X38);
    // 0x8002465C: lh          $t8, 0x1C($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X1C);
    // 0x80024660: lh          $t7, 0x1E($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X1E);
    // 0x80024664: lh          $t6, 0x20($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X20);
    // 0x80024668: lw          $a3, 0x40($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X40);
    // 0x8002466C: lw          $a1, 0x44($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X44);
    // 0x80024670: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80024674: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80024678: nop

    // 0x8002467C: ori         $v1, $v0, 0x3
    ctx->r3 = ctx->r2 | 0X3;
    // 0x80024680: xori        $v1, $v1, 0x2
    ctx->r3 = ctx->r3 ^ 0X2;
    // 0x80024684: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80024688: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8002468C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80024690: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80024694: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x80024698: add         $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x8002469C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800246A0: add         $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x800246A4: lbu         $t0, 0x6($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X6);
L_800246A8:
    // 0x800246A8: lh          $v0, 0x2($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X2);
    // 0x800246AC: lh          $v1, 0xE($t5)
    ctx->r3 = MEM_H(ctx->r13, 0XE);
    // 0x800246B0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800246B4: bne         $t0, $at, L_800246E8
    if (ctx->r8 != ctx->r1) {
        // 0x800246B8: sub         $t4, $v1, $v0
        ctx->r12 = SUB32(ctx->r3, ctx->r2);
            goto L_800246E8;
    }
    // 0x800246B8: sub         $t4, $v1, $v0
    ctx->r12 = SUB32(ctx->r3, ctx->r2);
    // 0x800246BC: lw          $t1, 0x8($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X8);
    // 0x800246C0: sll         $v0, $t4, 3
    ctx->r2 = S32(ctx->r12 << 3);
    // 0x800246C4: sll         $v1, $t4, 1
    ctx->r3 = S32(ctx->r12 << 1);
    // 0x800246C8: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800246CC: andi        $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 & 0X8000;
    // 0x800246D0: beq         $t1, $zero, L_8002476C
    if (ctx->r9 == 0) {
        // 0x800246D4: add         $a1, $a1, $v0
        ctx->r5 = ADD32(ctx->r5, ctx->r2);
            goto L_8002476C;
    }
    // 0x800246D4: add         $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800246D8: sll         $v0, $t4, 2
    ctx->r2 = S32(ctx->r12 << 2);
    // 0x800246DC: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800246E0: b           L_8002476C
    // 0x800246E4: add         $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
        goto L_8002476C;
    // 0x800246E4: add         $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
L_800246E8:
    // 0x800246E8: lh          $t0, 0x0($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X0);
    // 0x800246EC: mult        $t0, $t8
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800246F0: mflo        $t9
    ctx->r25 = lo;
    // 0x800246F4: lh          $t1, 0x2($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X2);
    // 0x800246F8: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800246FC: mult        $t1, $t7
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024700: mflo        $v0
    ctx->r2 = lo;
    // 0x80024704: lh          $t2, 0x4($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X4);
    // 0x80024708: add         $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8002470C: mult        $t2, $t6
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024710: mflo        $v0
    ctx->r2 = lo;
    // 0x80024714: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x80024718: add         $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8002471C: sra         $t9, $t9, 11
    ctx->r25 = S32(SIGNED(ctx->r25) >> 11);
    // 0x80024720: bgtz        $t9, L_80024730
    if (SIGNED(ctx->r25) > 0) {
        // 0x80024724: nop
    
            goto L_80024730;
    }
    // 0x80024724: nop

    // 0x80024728: b           L_80024750
    // 0x8002472C: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
        goto L_80024750;
    // 0x8002472C: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
L_80024730:
    // 0x80024730: mult        $t9, $a2
    result = S64(S32(ctx->r25)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024734: mflo        $t9
    ctx->r25 = lo;
    // 0x80024738: srl         $t9, $t9, 16
    ctx->r25 = S32(U32(ctx->r25) >> 16);
    // 0x8002473C: add         $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x80024740: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80024744: bnel        $at, $zero, L_80024754
    if (ctx->r1 != 0) {
        // 0x80024748: sll         $v0, $t9, 8
        ctx->r2 = S32(ctx->r25 << 8);
            goto L_80024754;
    }
    goto skip_0;
    // 0x80024748: sll         $v0, $t9, 8
    ctx->r2 = S32(ctx->r25 << 8);
    skip_0:
    // 0x8002474C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
L_80024750:
    // 0x80024750: sll         $v0, $t9, 8
    ctx->r2 = S32(ctx->r25 << 8);
L_80024754:
    // 0x80024754: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
    // 0x80024758: sh          $t9, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r25;
    // 0x8002475C: ori         $t9, $t9, 0xFF
    ctx->r25 = ctx->r25 | 0XFF;
    // 0x80024760: sh          $t9, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r25;
    // 0x80024764: bne         $t4, $zero, L_800246E8
    if (ctx->r12 != 0) {
        // 0x80024768: addiu       $a1, $a1, 0xA
        ctx->r5 = ADD32(ctx->r5, 0XA);
            goto L_800246E8;
    }
    // 0x80024768: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_8002476C:
    // 0x8002476C: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80024770: slt         $at, $t5, $a0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80024774: bnel        $at, $zero, L_800246A8
    if (ctx->r1 != 0) {
        // 0x80024778: lbu         $t0, 0x6($t5)
        ctx->r8 = MEM_BU(ctx->r13, 0X6);
            goto L_800246A8;
    }
    goto skip_1;
    // 0x80024778: lbu         $t0, 0x6($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X6);
    skip_1:
L_8002477C:
    // 0x8002477C: jr          $ra
    // 0x80024780: nop

    return;
    // 0x80024780: nop

;}
RECOMP_FUNC void calc_dynamic_lighting_for_object_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024784: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80024788: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x8002478C: sw          $ra, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r31;
    // 0x80024790: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x80024794: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x80024798: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x8002479C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800247A0: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x800247A4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800247A8: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800247AC: beq         $t9, $zero, L_800249FC
    if (ctx->r25 == 0) {
        // 0x800247B0: or          $s3, $a3, $zero
        ctx->r19 = ctx->r7 | 0;
            goto L_800249FC;
    }
    // 0x800247B0: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800247B4: lh          $t0, 0x1C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X1C);
    // 0x800247B8: lh          $t1, 0x1E($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X1E);
    // 0x800247BC: lh          $t2, 0x20($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X20);
    // 0x800247C0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800247C4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800247C8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800247CC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800247D0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800247D4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800247D8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800247DC: addiu       $t8, $sp, 0x10
    ctx->r24 = ADD32(ctx->r29, 0X10);
    // 0x800247E0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800247E4: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800247E8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800247EC: swc1        $f6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f6.u32l;
    // 0x800247F0: beq         $a2, $zero, L_80024810
    if (ctx->r6 == 0) {
        // 0x800247F4: swc1        $f8, 0x8($t8)
        MEM_W(0X8, ctx->r24) = ctx->f8.u32l;
            goto L_80024810;
    }
    // 0x800247F4: swc1        $f8, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f8.u32l;
    // 0x800247F8: jal         0x80069FE4
    // 0x800247FC: nop

    get_projection_matrix_f32(rdram, ctx);
        goto after_0;
    // 0x800247FC: nop

    after_0:
    // 0x80024800: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80024804: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80024808: jal         0x8006F92C
    // 0x8002480C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_1;
    // 0x8002480C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_1:
L_80024810:
    // 0x80024810: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x80024814: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x80024818: addiu       $v1, $zero, 0x0
    ctx->r3 = ADD32(0, 0X0);
    // 0x8002481C: sub         $t0, $zero, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x80024820: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
    // 0x80024824: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x80024828: lui         $v0, 0x3F80
    ctx->r2 = S32(0X3F80 << 16);
    // 0x8002482C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80024830: sub         $t1, $zero, $t1
    ctx->r9 = SUB32(0, ctx->r9);
    // 0x80024834: sh          $t1, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r9;
    // 0x80024838: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x8002483C: sw          $v0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r2;
    // 0x80024840: sw          $v1, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r3;
    // 0x80024844: sub         $t2, $zero, $t2
    ctx->r10 = SUB32(0, ctx->r10);
    // 0x80024848: sh          $t2, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r10;
    // 0x8002484C: sw          $v1, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r3;
    // 0x80024850: sw          $v1, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r3;
    // 0x80024854: jal         0x800700B4
    // 0x80024858: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_2;
    // 0x80024858: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_2:
    // 0x8002485C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80024860: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80024864: jal         0x8006F92C
    // 0x80024868: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_3;
    // 0x80024868: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_3:
    // 0x8002486C: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x80024870: mtc1        $s3, $f6
    ctx->f6.u32l = ctx->r19;
    // 0x80024874: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80024878: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8002487C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80024880: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x80024884: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80024888: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x8002488C: addiu       $t0, $sp, 0x10
    ctx->r8 = ADD32(ctx->r29, 0X10);
    // 0x80024890: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80024894: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80024898: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8002489C: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x800248A0: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x800248A4: lh          $t0, 0x28($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X28);
    // 0x800248A8: lw          $t5, 0x38($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X38);
    // 0x800248AC: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800248B0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800248B4: lw          $s3, 0x44($s0)
    ctx->r19 = MEM_W(ctx->r16, 0X44);
    // 0x800248B8: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x800248BC: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800248C0: nop

    // 0x800248C4: mul.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800248C8: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800248CC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800248D0: nop

    // 0x800248D4: ori         $v1, $v0, 0x3
    ctx->r3 = ctx->r2 | 0X3;
    // 0x800248D8: xori        $v1, $v1, 0x2
    ctx->r3 = ctx->r3 ^ 0X2;
    // 0x800248DC: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x800248E0: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x800248E4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800248E8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800248EC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800248F0: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800248F4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800248F8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800248FC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80024900: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80024904: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80024908: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002490C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80024910: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80024914: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x80024918: add         $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x8002491C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80024920: add         $s2, $s2, $t5
    ctx->r18 = ADD32(ctx->r18, ctx->r13);
    // 0x80024924: lbu         $t0, 0x6($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X6);
L_80024928:
    // 0x80024928: lh          $v0, 0x2($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X2);
    // 0x8002492C: lh          $v1, 0xE($t5)
    ctx->r3 = MEM_H(ctx->r13, 0XE);
    // 0x80024930: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80024934: bne         $t0, $at, L_80024968
    if (ctx->r8 != ctx->r1) {
        // 0x80024938: sub         $t4, $v1, $v0
        ctx->r12 = SUB32(ctx->r3, ctx->r2);
            goto L_80024968;
    }
    // 0x80024938: sub         $t4, $v1, $v0
    ctx->r12 = SUB32(ctx->r3, ctx->r2);
    // 0x8002493C: lw          $t1, 0x8($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X8);
    // 0x80024940: sll         $v0, $t4, 3
    ctx->r2 = S32(ctx->r12 << 3);
    // 0x80024944: sll         $v1, $t4, 1
    ctx->r3 = S32(ctx->r12 << 1);
    // 0x80024948: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002494C: andi        $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 & 0X8000;
    // 0x80024950: beq         $t1, $zero, L_800249EC
    if (ctx->r9 == 0) {
        // 0x80024954: add         $s3, $s3, $v0
        ctx->r19 = ADD32(ctx->r19, ctx->r2);
            goto L_800249EC;
    }
    // 0x80024954: add         $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x80024958: sll         $v0, $t4, 2
    ctx->r2 = S32(ctx->r12 << 2);
    // 0x8002495C: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024960: b           L_800249EC
    // 0x80024964: add         $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
        goto L_800249EC;
    // 0x80024964: add         $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_80024968:
    // 0x80024968: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x8002496C: mult        $t0, $a2
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024970: mflo        $a1
    ctx->r5 = lo;
    // 0x80024974: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x80024978: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x8002497C: mult        $t1, $a3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024980: mflo        $v0
    ctx->r2 = lo;
    // 0x80024984: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x80024988: add         $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8002498C: mult        $t2, $t6
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024990: mflo        $v0
    ctx->r2 = lo;
    // 0x80024994: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x80024998: add         $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8002499C: sra         $a1, $a1, 7
    ctx->r5 = S32(SIGNED(ctx->r5) >> 7);
    // 0x800249A0: bgtz        $a1, L_800249B0
    if (SIGNED(ctx->r5) > 0) {
        // 0x800249A4: nop
    
            goto L_800249B0;
    }
    // 0x800249A4: nop

    // 0x800249A8: b           L_800249D0
    // 0x800249AC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
        goto L_800249D0;
    // 0x800249AC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_800249B0:
    // 0x800249B0: mult        $a1, $t7
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800249B4: mflo        $a1
    ctx->r5 = lo;
    // 0x800249B8: srl         $a1, $a1, 21
    ctx->r5 = S32(U32(ctx->r5) >> 21);
    // 0x800249BC: add         $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x800249C0: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x800249C4: bnel        $at, $zero, L_800249D4
    if (ctx->r1 != 0) {
        // 0x800249C8: sll         $v0, $a1, 8
        ctx->r2 = S32(ctx->r5 << 8);
            goto L_800249D4;
    }
    goto skip_0;
    // 0x800249C8: sll         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5 << 8);
    skip_0:
    // 0x800249CC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_800249D0:
    // 0x800249D0: sll         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5 << 8);
L_800249D4:
    // 0x800249D4: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x800249D8: sh          $a1, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r5;
    // 0x800249DC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800249E0: sh          $a1, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r5;
    // 0x800249E4: bne         $t4, $zero, L_80024968
    if (ctx->r12 != 0) {
        // 0x800249E8: addiu       $s3, $s3, 0xA
        ctx->r19 = ADD32(ctx->r19, 0XA);
            goto L_80024968;
    }
    // 0x800249E8: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
L_800249EC:
    // 0x800249EC: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x800249F0: slt         $at, $t5, $s2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800249F4: bnel        $at, $zero, L_80024928
    if (ctx->r1 != 0) {
        // 0x800249F8: lbu         $t0, 0x6($t5)
        ctx->r8 = MEM_BU(ctx->r13, 0X6);
            goto L_80024928;
    }
    goto skip_1;
    // 0x800249F8: lbu         $t0, 0x6($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X6);
    skip_1:
L_800249FC:
    // 0x800249FC: lw          $ra, 0x78($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X78);
    // 0x80024A00: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x80024A04: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x80024A08: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x80024A0C: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x80024A10: jr          $ra
    // 0x80024A14: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80024A14: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80024A18: nop

    // 0x80024A1C: nop

;}
RECOMP_FUNC void set_scene_viewport_num(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024A20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A24: sw          $a0, -0x2704($at)
    MEM_W(-0X2704, ctx->r1) = ctx->r4;
    // 0x80024A28: jr          $ra
    // 0x80024A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80024A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void init_track(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024A30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024A34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80024A38: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80024A3C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80024A40: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80024A44: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80024A48: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80024A4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80024A50: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80024A54: jal         0x8006BFF0
    // 0x80024A58: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80024A58: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80024A5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80024A60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80024A64: addiu       $a1, $a1, -0x3174
    ctx->r5 = ADD32(ctx->r5, -0X3174);
    // 0x80024A68: addiu       $a0, $a0, -0x4988
    ctx->r4 = ADD32(ctx->r4, -0X4988);
    // 0x80024A6C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80024A70: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80024A74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A78: sw          $zero, -0x4980($at)
    MEM_W(-0X4980, ctx->r1) = 0;
    // 0x80024A7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A80: sw          $zero, -0x497C($at)
    MEM_W(-0X497C, ctx->r1) = 0;
    // 0x80024A84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A88: sw          $zero, -0x4978($at)
    MEM_W(-0X4978, ctx->r1) = 0;
    // 0x80024A8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A90: sw          $zero, -0x4974($at)
    MEM_W(-0X4974, ctx->r1) = 0;
    // 0x80024A94: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80024A98: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80024A9C: lb          $v1, 0x4C($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X4C);
    // 0x80024AA0: nop

    // 0x80024AA4: beq         $v1, $at, L_80024AB0
    if (ctx->r3 == ctx->r1) {
        // 0x80024AA8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80024AB0;
    }
    // 0x80024AA8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80024AAC: bne         $v1, $at, L_80024AB8
    if (ctx->r3 != ctx->r1) {
        // 0x80024AB0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80024AB8;
    }
L_80024AB0:
    // 0x80024AB0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80024AB4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_80024AB8:
    // 0x80024AB8: jal         0x8002C104
    // 0x80024ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    generate_track(rdram, ctx);
        goto after_1;
    // 0x80024ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80024AC0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80024AC4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80024AC8: addiu       $s0, $s0, -0x26FC
    ctx->r16 = ADD32(ctx->r16, -0X26FC);
    // 0x80024ACC: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80024AD0: beq         $at, $zero, L_80024B4C
    if (ctx->r1 == 0) {
        // 0x80024AD4: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_80024B4C;
    }
    // 0x80024AD4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80024AD8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80024ADC: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x80024AE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80024AE4: lh          $a0, 0x1A($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X1A);
    // 0x80024AE8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80024AEC: blez        $a0, L_80024B4C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80024AF0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80024B4C;
    }
    // 0x80024AF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80024AF4:
    // 0x80024AF4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80024AF8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80024AFC: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80024B00: lb          $t1, 0x2B($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X2B);
    // 0x80024B04: nop

    // 0x80024B08: beq         $t1, $zero, L_80024B44
    if (ctx->r9 == 0) {
        // 0x80024B0C: slt         $at, $a2, $a0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80024B44;
    }
    // 0x80024B0C: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80024B10: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80024B14: nop

    // 0x80024B18: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80024B1C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80024B20: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80024B24: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80024B28: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80024B2C: sb          $a1, 0x2B($t5)
    MEM_B(0X2B, ctx->r13) = ctx->r5;
    // 0x80024B30: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x80024B34: nop

    // 0x80024B38: lh          $a0, 0x1A($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X1A);
    // 0x80024B3C: nop

    // 0x80024B40: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
L_80024B44:
    // 0x80024B44: bne         $at, $zero, L_80024AF4
    if (ctx->r1 != 0) {
        // 0x80024B48: addiu       $v1, $v1, 0x44
        ctx->r3 = ADD32(ctx->r3, 0X44);
            goto L_80024AF4;
    }
    // 0x80024B48: addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
L_80024B4C:
    // 0x80024B4C: jal         0x8009F1C4
    // 0x80024B50: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_2;
    // 0x80024B50: nop

    after_2:
    // 0x80024B54: beq         $v0, $zero, L_80024B84
    if (ctx->r2 == 0) {
        // 0x80024B58: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_80024B84;
    }
    // 0x80024B58: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80024B5C: lw          $t6, -0x3174($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3174);
    // 0x80024B60: nop

    // 0x80024B64: lb          $v1, 0x4C($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X4C);
    // 0x80024B68: nop

    // 0x80024B6C: beq         $v1, $zero, L_80024B7C
    if (ctx->r3 == 0) {
        // 0x80024B70: andi        $t7, $v1, 0x40
        ctx->r15 = ctx->r3 & 0X40;
            goto L_80024B7C;
    }
    // 0x80024B70: andi        $t7, $v1, 0x40
    ctx->r15 = ctx->r3 & 0X40;
    // 0x80024B74: beq         $t7, $zero, L_80024B88
    if (ctx->r15 == 0) {
        // 0x80024B78: lw          $a2, 0x30($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X30);
            goto L_80024B88;
    }
    // 0x80024B78: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
L_80024B7C:
    // 0x80024B7C: b           L_80024B90
    // 0x80024B80: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_80024B90;
    // 0x80024B80: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80024B84:
    // 0x80024B84: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
L_80024B88:
    // 0x80024B88: nop

    // 0x80024B8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80024B90:
    // 0x80024B90: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80024B94: nop

    // 0x80024B98: beq         $t8, $zero, L_80024BB4
    if (ctx->r24 == 0) {
        // 0x80024B9C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80024BB4;
    }
    // 0x80024B9C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80024BA0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80024BA4: lw          $a1, -0x3174($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3174);
    // 0x80024BA8: lw          $a0, -0x3178($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3178);
    // 0x80024BAC: jal         0x800B87D4
    // 0x80024BB0: nop

    waves_init(rdram, ctx);
        goto after_3;
    // 0x80024BB0: nop

    after_3:
L_80024BB4:
    // 0x80024BB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80024BB8: jal         0x8006676C
    // 0x80024BBC: nop

    cam_set_layout(rdram, ctx);
        goto after_4;
    // 0x80024BBC: nop

    after_4:
    // 0x80024BC0: jal         0x80028004
    // 0x80024BC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skydome_spawn(rdram, ctx);
        goto after_5;
    // 0x80024BC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80024BC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024BCC: sw          $zero, -0x4970($at)
    MEM_W(-0X4970, ctx->r1) = 0;
    // 0x80024BD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024BD4: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80024BD8: jal         0x80011390
    // 0x80024BDC: sw          $t9, -0x496C($at)
    MEM_W(-0X496C, ctx->r1) = ctx->r25;
    path_enable(rdram, ctx);
        goto after_6;
    // 0x80024BDC: sw          $t9, -0x496C($at)
    MEM_W(-0X496C, ctx->r1) = ctx->r25;
    after_6:
    // 0x80024BE0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80024BE4: jal         0x8000C8F8
    // 0x80024BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    track_spawn_objects(rdram, ctx);
        goto after_7;
    // 0x80024BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80024BEC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80024BF0: jal         0x8000C8F8
    // 0x80024BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    track_spawn_objects(rdram, ctx);
        goto after_8;
    // 0x80024BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80024BF8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80024BFC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80024C00: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80024C04: addiu       $s3, $s3, -0x2704
    ctx->r19 = ADD32(ctx->r19, -0X2704);
    // 0x80024C08: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80024C0C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80024C10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80024C14: jal         0x8000CC7C
    // 0x80024C18: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    track_setup_racers(rdram, ctx);
        goto after_9;
    // 0x80024C18: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    after_9:
    // 0x80024C1C: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80024C20: jal         0x8000B020
    // 0x80024C24: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    racerfx_alloc(rdram, ctx);
        goto after_10;
    // 0x80024C24: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_10:
    // 0x80024C28: bne         $s1, $zero, L_80024C4C
    if (ctx->r17 != 0) {
        // 0x80024C2C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80024C4C;
    }
    // 0x80024C2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80024C30: bne         $s0, $zero, L_80024C4C
    if (ctx->r16 != 0) {
        // 0x80024C34: nop
    
            goto L_80024C4C;
    }
    // 0x80024C34: nop

    // 0x80024C38: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80024C3C: jal         0x800C06F8
    // 0x80024C40: addiu       $a0, $a0, -0x3214
    ctx->r4 = ADD32(ctx->r4, -0X3214);
    transition_begin(rdram, ctx);
        goto after_11;
    // 0x80024C40: addiu       $a0, $a0, -0x3214
    ctx->r4 = ADD32(ctx->r4, -0X3214);
    after_11:
    // 0x80024C44: b           L_80024C58
    // 0x80024C48: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
        goto L_80024C58;
    // 0x80024C48: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
L_80024C4C:
    // 0x80024C4C: jal         0x800C06F8
    // 0x80024C50: addiu       $a0, $a0, -0x321C
    ctx->r4 = ADD32(ctx->r4, -0X321C);
    transition_begin(rdram, ctx);
        goto after_12;
    // 0x80024C50: addiu       $a0, $a0, -0x321C
    ctx->r4 = ADD32(ctx->r4, -0X321C);
    after_12:
    // 0x80024C54: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
L_80024C58:
    // 0x80024C58: jal         0x8006676C
    // 0x80024C5C: nop

    cam_set_layout(rdram, ctx);
        goto after_13;
    // 0x80024C5C: nop

    after_13:
    // 0x80024C60: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x80024C64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024C68: lui         $s3, 0xFFFF
    ctx->r19 = S32(0XFFFF << 16);
    // 0x80024C6C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80024C70: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80024C74: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80024C78: sw          $zero, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = 0;
    // 0x80024C7C: addiu       $s0, $s0, -0x2748
    ctx->r16 = ADD32(ctx->r16, -0X2748);
    // 0x80024C80: addiu       $s2, $s2, -0x2760
    ctx->r18 = ADD32(ctx->r18, -0X2760);
    // 0x80024C84: addiu       $s1, $s1, -0x2730
    ctx->r17 = ADD32(ctx->r17, -0X2730);
    // 0x80024C88: ori         $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 | 0XFF;
    // 0x80024C8C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_80024C90:
    // 0x80024C90: addiu       $a0, $zero, 0xC80
    ctx->r4 = ADD32(0, 0XC80);
    // 0x80024C94: jal         0x80070EDC
    // 0x80024C98: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_14;
    // 0x80024C98: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_14:
    // 0x80024C9C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80024CA0: addiu       $a0, $zero, 0x3200
    ctx->r4 = ADD32(0, 0X3200);
    // 0x80024CA4: jal         0x80070EDC
    // 0x80024CA8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_15;
    // 0x80024CA8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_15:
    // 0x80024CAC: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x80024CB0: addiu       $a0, $zero, 0x4E20
    ctx->r4 = ADD32(0, 0X4E20);
    // 0x80024CB4: jal         0x80070EDC
    // 0x80024CB8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_16;
    // 0x80024CB8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_16:
    // 0x80024CBC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80024CC0: addiu       $t2, $t2, -0x2738
    ctx->r10 = ADD32(ctx->r10, -0X2738);
    // 0x80024CC4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80024CC8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80024CCC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80024CD0: bne         $s0, $t2, L_80024C90
    if (ctx->r16 != ctx->r10) {
        // 0x80024CD4: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_80024C90;
    }
    // 0x80024CD4: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x80024CD8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80024CDC: addiu       $s0, $s0, -0x49B8
    ctx->r16 = ADD32(ctx->r16, -0X49B8);
    // 0x80024CE0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80024CE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80024CE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80024CEC: jal         0x8002D91C
    // 0x80024CF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    shadow_update(rdram, ctx);
        goto after_17;
    // 0x80024CF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80024CF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80024CF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80024CFC: jal         0x8002D91C
    // 0x80024D00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    shadow_update(rdram, ctx);
        goto after_18;
    // 0x80024D00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x80024D04: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80024D08: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80024D0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80024D10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80024D14: jal         0x8002D91C
    // 0x80024D18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    shadow_update(rdram, ctx);
        goto after_19;
    // 0x80024D18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x80024D1C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80024D20: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80024D24: jal         0x8002D91C
    // 0x80024D28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    shadow_update(rdram, ctx);
        goto after_20;
    // 0x80024D28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x80024D2C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80024D30: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80024D34: lw          $v0, -0x3174($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3174);
    // 0x80024D38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024D3C: lbu         $t4, 0xB7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XB7);
    // 0x80024D40: nop

    // 0x80024D44: beq         $t4, $zero, L_80024D7C
    if (ctx->r12 == 0) {
        // 0x80024D48: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80024D7C;
    }
    // 0x80024D48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80024D4C: lbu         $t5, 0xB4($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XB4);
    // 0x80024D50: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80024D54: sb          $t5, -0x499F($at)
    MEM_B(-0X499F, ctx->r1) = ctx->r13;
    // 0x80024D58: lbu         $t6, 0xB5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XB5);
    // 0x80024D5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024D60: sb          $t6, -0x499E($at)
    MEM_B(-0X499E, ctx->r1) = ctx->r14;
    // 0x80024D64: lbu         $t7, 0xB6($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XB6);
    // 0x80024D68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024D6C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80024D70: jal         0x80025550
    // 0x80024D74: sb          $t7, -0x499D($at)
    MEM_B(-0X499D, ctx->r1) = ctx->r15;
    void_init(rdram, ctx);
        goto after_21;
    // 0x80024D74: sb          $t7, -0x499D($at)
    MEM_B(-0X499D, ctx->r1) = ctx->r15;
    after_21:
    // 0x80024D78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80024D7C:
    // 0x80024D7C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80024D80: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80024D84: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80024D88: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80024D8C: jr          $ra
    // 0x80024D90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80024D90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void render_scene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024D94: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80024D98: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80024D9C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80024DA0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80024DA4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80024DA8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80024DAC: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80024DB0: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80024DB4: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80024DB8: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x80024DBC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80024DC0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80024DC4: addiu       $s1, $s1, -0x49E0
    ctx->r17 = ADD32(ctx->r17, -0X49E0);
    // 0x80024DC8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80024DCC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80024DD0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80024DD4: addiu       $s2, $s2, -0x49DC
    ctx->r18 = ADD32(ctx->r18, -0X49DC);
    // 0x80024DD8: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80024DDC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80024DE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024DE4: sw          $t3, -0x49D8($at)
    MEM_W(-0X49D8, ctx->r1) = ctx->r11;
    // 0x80024DE8: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80024DEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024DF0: sw          $t5, -0x49D4($at)
    MEM_W(-0X49D4, ctx->r1) = ctx->r13;
    // 0x80024DF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024DF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80024DFC: sw          $t6, -0x49A4($at)
    MEM_W(-0X49A4, ctx->r1) = ctx->r14;
    // 0x80024E00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024E04: sw          $zero, -0x49BC($at)
    MEM_W(-0X49BC, ctx->r1) = 0;
    // 0x80024E08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024E0C: sw          $zero, -0x49C0($at)
    MEM_W(-0X49C0, ctx->r1) = 0;
    // 0x80024E10: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80024E14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024E18: lw          $a0, -0x2704($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2704);
    // 0x80024E1C: jal         0x8006676C
    // 0x80024E20: sw          $zero, -0x49C4($at)
    MEM_W(-0X49C4, ctx->r1) = 0;
    cam_set_layout(rdram, ctx);
        goto after_0;
    // 0x80024E20: sw          $zero, -0x49C4($at)
    MEM_W(-0X49C4, ctx->r1) = 0;
    after_0:
    // 0x80024E24: jal         0x8006ECE0
    // 0x80024E28: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    is_game_paused(rdram, ctx);
        goto after_1;
    // 0x80024E28: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_1:
    // 0x80024E2C: beq         $v0, $zero, L_80024E3C
    if (ctx->r2 == 0) {
        // 0x80024E30: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80024E3C;
    }
    // 0x80024E30: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80024E34: b           L_80024E48
    // 0x80024E38: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
        goto L_80024E48;
    // 0x80024E38: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
L_80024E3C:
    // 0x80024E3C: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80024E40: nop

    // 0x80024E44: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
L_80024E48:
    // 0x80024E48: lw          $t8, -0x26FC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26FC);
    // 0x80024E4C: nop

    // 0x80024E50: beq         $t8, $zero, L_80024E68
    if (ctx->r24 == 0) {
        // 0x80024E54: lw          $a2, 0xA0($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XA0);
            goto L_80024E68;
    }
    // 0x80024E54: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x80024E58: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80024E5C: jal         0x800BA138
    // 0x80024E60: nop

    waves_update(rdram, ctx);
        goto after_2;
    // 0x80024E60: nop

    after_2:
    // 0x80024E64: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
L_80024E68:
    // 0x80024E68: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80024E6C: jal         0x8002D91C
    // 0x80024E70: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    shadow_update(rdram, ctx);
        goto after_3;
    // 0x80024E70: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80024E74: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80024E78: lw          $v1, -0x3174($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3174);
    // 0x80024E7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80024E80: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
L_80024E84:
    // 0x80024E84: lw          $a0, 0x74($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X74);
    // 0x80024E88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024E8C: beq         $a0, $at, L_80024EB0
    if (ctx->r4 == ctx->r1) {
        // 0x80024E90: nop
    
            goto L_80024EB0;
    }
    // 0x80024E90: nop

    // 0x80024E94: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80024E98: jal         0x8007F69C
    // 0x80024E9C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    update_colour_cycle(rdram, ctx);
        goto after_4;
    // 0x80024E9C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_4:
    // 0x80024EA0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80024EA4: lw          $v1, -0x3174($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3174);
    // 0x80024EA8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80024EAC: nop

L_80024EB0:
    // 0x80024EB0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80024EB4: slti        $at, $v0, 0x1C
    ctx->r1 = SIGNED(ctx->r2) < 0X1C ? 1 : 0;
    // 0x80024EB8: bne         $at, $zero, L_80024E84
    if (ctx->r1 != 0) {
        // 0x80024EBC: addu        $t9, $v1, $v0
        ctx->r25 = ADD32(ctx->r3, ctx->r2);
            goto L_80024E84;
    }
    // 0x80024EBC: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x80024EC0: lw          $a0, 0xAC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XAC);
    // 0x80024EC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024EC8: beq         $a0, $at, L_80024EE8
    if (ctx->r4 == ctx->r1) {
        // 0x80024ECC: nop
    
            goto L_80024EE8;
    }
    // 0x80024ECC: nop

    // 0x80024ED0: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80024ED4: jal         0x8007F8B0
    // 0x80024ED8: nop

    update_pulsating_light_data(rdram, ctx);
        goto after_5;
    // 0x80024ED8: nop

    after_5:
    // 0x80024EDC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80024EE0: lw          $v1, -0x3174($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3174);
    // 0x80024EE4: nop

L_80024EE8:
    // 0x80024EE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80024EEC: addiu       $a0, $a0, -0x49A0
    ctx->r4 = ADD32(ctx->r4, -0X49A0);
    // 0x80024EF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80024EF4: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
    // 0x80024EF8: lb          $v0, 0x4C($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X4C);
    // 0x80024EFC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80024F00: bne         $v0, $at, L_80024F20
    if (ctx->r2 != ctx->r1) {
        // 0x80024F04: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80024F20;
    }
    // 0x80024F04: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80024F08: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80024F0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024F10: sw          $t1, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = ctx->r9;
    // 0x80024F14: lb          $v0, 0x4C($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X4C);
    // 0x80024F18: nop

    // 0x80024F1C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_80024F20:
    // 0x80024F20: beq         $v0, $at, L_80024F34
    if (ctx->r2 == ctx->r1) {
        // 0x80024F24: nop
    
            goto L_80024F34;
    }
    // 0x80024F24: nop

    // 0x80024F28: lb          $t2, 0xBD($v1)
    ctx->r10 = MEM_B(ctx->r3, 0XBD);
    // 0x80024F2C: nop

    // 0x80024F30: beq         $t2, $zero, L_80024F3C
    if (ctx->r10 == 0) {
        // 0x80024F34: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80024F3C;
    }
L_80024F34:
    // 0x80024F34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024F38: sw          $t1, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = ctx->r9;
L_80024F3C:
    // 0x80024F3C: lb          $t3, 0x49($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X49);
    // 0x80024F40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024F44: bne         $t3, $at, L_80024FDC
    if (ctx->r11 != ctx->r1) {
        // 0x80024F48: nop
    
            goto L_80024FDC;
    }
    // 0x80024F48: nop

    // 0x80024F4C: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x80024F50: lb          $t7, 0xA2($v1)
    ctx->r15 = MEM_B(ctx->r3, 0XA2);
    // 0x80024F54: lw          $t4, 0xA4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA4);
    // 0x80024F58: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024F5C: lbu         $t0, 0x0($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X0);
    // 0x80024F60: lh          $t6, 0xA8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA8);
    // 0x80024F64: sll         $t5, $t0, 9
    ctx->r13 = S32(ctx->r8 << 9);
    // 0x80024F68: addiu       $t0, $t5, -0x1
    ctx->r8 = ADD32(ctx->r13, -0X1);
    // 0x80024F6C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80024F70: addiu       $v0, $v0, -0x3174
    ctx->r2 = ADD32(ctx->r2, -0X3174);
    // 0x80024F74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80024F78: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80024F7C: addiu       $a2, $a2, -0x4970
    ctx->r6 = ADD32(ctx->r6, -0X4970);
    // 0x80024F80: addiu       $a1, $a1, -0x496C
    ctx->r5 = ADD32(ctx->r5, -0X496C);
    // 0x80024F84: mflo        $t8
    ctx->r24 = lo;
    // 0x80024F88: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80024F8C: and         $t2, $t9, $t0
    ctx->r10 = ctx->r25 & ctx->r8;
    // 0x80024F90: sh          $t2, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = ctx->r10;
    // 0x80024F94: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80024F98: nop

    // 0x80024F9C: lb          $t7, 0xA3($v1)
    ctx->r15 = MEM_B(ctx->r3, 0XA3);
    // 0x80024FA0: lw          $t3, 0xA4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XA4);
    // 0x80024FA4: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024FA8: lbu         $t0, 0x1($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0X1);
    // 0x80024FAC: lh          $t5, 0xAA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XAA);
    // 0x80024FB0: sll         $t4, $t0, 9
    ctx->r12 = S32(ctx->r8 << 9);
    // 0x80024FB4: addiu       $t0, $t4, -0x1
    ctx->r8 = ADD32(ctx->r12, -0X1);
    // 0x80024FB8: mflo        $t6
    ctx->r14 = lo;
    // 0x80024FBC: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x80024FC0: and         $t9, $t8, $t0
    ctx->r25 = ctx->r24 & ctx->r8;
    // 0x80024FC4: sh          $t9, 0xAA($v1)
    MEM_H(0XAA, ctx->r3) = ctx->r25;
    // 0x80024FC8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80024FCC: nop

    // 0x80024FD0: lw          $a0, 0xA4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XA4);
    // 0x80024FD4: jal         0x8007F3D0
    // 0x80024FD8: nop

    tex_animate_texture(rdram, ctx);
        goto after_6;
    // 0x80024FD8: nop

    after_6:
L_80024FDC:
    // 0x80024FDC: jal         0x8009C850
    // 0x80024FE0: sb          $zero, 0x83($sp)
    MEM_B(0X83, ctx->r29) = 0;
    get_filtered_cheats(rdram, ctx);
        goto after_7;
    // 0x80024FE0: sb          $zero, 0x83($sp)
    MEM_B(0X83, ctx->r29) = 0;
    after_7:
    // 0x80024FE4: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x80024FE8: beq         $t3, $zero, L_80024FF8
    if (ctx->r11 == 0) {
        // 0x80024FEC: lui         $t7, 0xA000
        ctx->r15 = S32(0XA000 << 16);
            goto L_80024FF8;
    }
    // 0x80024FEC: lui         $t7, 0xA000
    ctx->r15 = S32(0XA000 << 16);
    // 0x80024FF0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80024FF4: sb          $t4, 0x83($sp)
    MEM_B(0X83, ctx->r29) = ctx->r12;
L_80024FF8:
    // 0x80024FF8: lw          $t5, 0x200($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X200);
    // 0x80024FFC: lui         $at, 0xAC29
    ctx->r1 = S32(0XAC29 << 16);
    // 0x80025000: beq         $t5, $at, L_8002500C
    if (ctx->r13 == ctx->r1) {
        // 0x80025004: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8002500C;
    }
    // 0x80025004: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80025008: sb          $t6, 0x83($sp)
    MEM_B(0X83, ctx->r29) = ctx->r14;
L_8002500C:
    // 0x8002500C: jal         0x8007B820
    // 0x80025010: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    rendermode_reset(rdram, ctx);
        goto after_8;
    // 0x80025010: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80025014: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025018: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x8002501C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80025020: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80025024: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x80025028: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002502C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025030: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025034: lui         $t3, 0xB600
    ctx->r11 = S32(0XB600 << 16);
    // 0x80025038: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8002503C: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80025040: addiu       $t4, $zero, 0x1000
    ctx->r12 = ADD32(0, 0X1000);
    // 0x80025044: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80025048: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8002504C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025050: lui         $t5, 0xF900
    ctx->r13 = S32(0XF900 << 16);
    // 0x80025054: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80025058: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8002505C: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80025060: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80025064: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80025068: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8002506C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80025070: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80025074: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80025078: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8002507C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80025080: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80025084: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025088: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x8002508C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80025090: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80025094: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80025098: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8002509C: jal         0x800AD96C
    // 0x800250A0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    rain_fog(rdram, ctx);
        goto after_9;
    // 0x800250A0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_9:
    // 0x800250A4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x800250A8: jal         0x80030878
    // 0x800250AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    update_fog(rdram, ctx);
        goto after_10;
    // 0x800250AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x800250B0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800250B4: jal         0x800AF964
    // 0x800250B8: nop

    scroll_particle_textures(rdram, ctx);
        goto after_11;
    // 0x800250B8: nop

    after_11:
    // 0x800250BC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800250C0: lw          $t5, -0x3178($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3178);
    // 0x800250C4: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800250C8: lh          $t6, 0x1E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X1E);
    // 0x800250CC: nop

    // 0x800250D0: blez        $t6, L_800250E0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800250D4: nop
    
            goto L_800250E0;
    }
    // 0x800250D4: nop

    // 0x800250D8: jal         0x80027E64
    // 0x800250DC: nop

    track_tex_anim(rdram, ctx);
        goto after_12;
    // 0x800250DC: nop

    after_12:
L_800250E0:
    // 0x800250E0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800250E4: addiu       $s0, $s0, -0x49CC
    ctx->r16 = ADD32(ctx->r16, -0X49CC);
    // 0x800250E8: slt         $at, $zero, $s3
    ctx->r1 = SIGNED(0) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800250EC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800250F0: beq         $at, $zero, L_800252EC
    if (ctx->r1 == 0) {
        // 0x800250F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800252EC;
    }
    // 0x800250F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800250F8:
    // 0x800250F8: bne         $v0, $zero, L_80025120
    if (ctx->r2 != 0) {
        // 0x800250FC: lb          $t9, 0x83($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X83);
            goto L_80025120;
    }
    // 0x800250FC: lb          $t9, 0x83($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X83);
    // 0x80025100: jal         0x8000E184
    // 0x80025104: nop

    is_player_two_in_control(rdram, ctx);
        goto after_13;
    // 0x80025104: nop

    after_13:
    // 0x80025108: beq         $v0, $zero, L_8002511C
    if (ctx->r2 == 0) {
        // 0x8002510C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8002511C;
    }
    // 0x8002510C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80025110: bne         $s3, $at, L_8002511C
    if (ctx->r19 != ctx->r1) {
        // 0x80025114: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8002511C;
    }
    // 0x80025114: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80025118: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_8002511C:
    // 0x8002511C: lb          $t9, 0x83($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X83);
L_80025120:
    // 0x80025120: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x80025124: beq         $t9, $zero, L_80025144
    if (ctx->r25 == 0) {
        // 0x80025128: nop
    
            goto L_80025144;
    }
    // 0x80025128: nop

    // 0x8002512C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025130: addiu       $t4, $zero, 0x1000
    ctx->r12 = ADD32(0, 0X1000);
    // 0x80025134: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80025138: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8002513C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80025140: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80025144:
    // 0x80025144: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80025148: jal         0x8003097C
    // 0x8002514C: nop

    apply_fog(rdram, ctx);
        goto after_14;
    // 0x8002514C: nop

    after_14:
    // 0x80025150: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025154: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80025158: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002515C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80025160: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025164: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80025168: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002516C: jal         0x80066828
    // 0x80025170: nop

    set_active_camera(rdram, ctx);
        goto after_15;
    // 0x80025170: nop

    after_15:
    // 0x80025174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025178: jal         0x80066F1C
    // 0x8002517C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    viewport_main(rdram, ctx);
        goto after_16;
    // 0x8002517C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
    // 0x80025180: jal         0x8002A35C
    // 0x80025184: nop

    func_8002A31C(rdram, ctx);
        goto after_17;
    // 0x80025184: nop

    after_17:
    // 0x80025188: slti        $at, $s3, 0x2
    ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x8002518C: beq         $at, $zero, L_800251DC
    if (ctx->r1 == 0) {
        // 0x80025190: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800251DC;
    }
    // 0x80025190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025194: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025198: jal         0x80068648
    // 0x8002519C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_world_origin(rdram, ctx);
        goto after_18;
    // 0x8002519C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_18:
    // 0x800251A0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800251A4: lw          $t6, -0x3174($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3174);
    // 0x800251A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800251AC: lb          $t8, 0x49($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X49);
    // 0x800251B0: nop

    // 0x800251B4: bne         $t8, $at, L_800251CC
    if (ctx->r24 != ctx->r1) {
        // 0x800251B8: nop
    
            goto L_800251CC;
    }
    // 0x800251B8: nop

    // 0x800251BC: jal         0x80028090
    // 0x800251C0: nop

    trackbg_render_flashy(rdram, ctx);
        goto after_19;
    // 0x800251C0: nop

    after_19:
    // 0x800251C4: b           L_80025208
    // 0x800251C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_80025208;
    // 0x800251C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_800251CC:
    // 0x800251CC: jal         0x80028C50
    // 0x800251D0: nop

    skydome_render(rdram, ctx);
        goto after_20;
    // 0x800251D0: nop

    after_20:
    // 0x800251D4: b           L_80025208
    // 0x800251D8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_80025208;
    // 0x800251D8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_800251DC:
    // 0x800251DC: jal         0x800682BC
    // 0x800251E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_perspective(rdram, ctx);
        goto after_21;
    // 0x800251E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_21:
    // 0x800251E4: jal         0x800289F8
    // 0x800251E8: nop

    trackbg_render_gradient(rdram, ctx);
        goto after_22;
    // 0x800251E8: nop

    after_22:
    // 0x800251EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800251F0: jal         0x80067F7C
    // 0x800251F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80067D3C(rdram, ctx);
        goto after_23;
    // 0x800251F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_23:
    // 0x800251F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800251FC: jal         0x80068648
    // 0x80025200: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_world_origin(rdram, ctx);
        goto after_24;
    // 0x80025200: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x80025204: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80025208:
    // 0x80025208: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x8002520C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80025210: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80025214: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025218: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8002521C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80025220: jal         0x80028D10
    // 0x80025224: nop

    initialise_player_viewport_vars(rdram, ctx);
        goto after_25;
    // 0x80025224: nop

    after_25:
    // 0x80025228: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8002522C: jal         0x800AB868
    // 0x80025230: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    weather_clip_planes(rdram, ctx);
        goto after_26;
    // 0x80025230: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    after_26:
    // 0x80025234: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80025238: lw          $t3, -0x3174($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3174);
    // 0x8002523C: slti        $at, $s3, 0x2
    ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x80025240: lh          $t4, 0x90($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X90);
    // 0x80025244: nop

    // 0x80025248: blez        $t4, L_80025278
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8002524C: nop
    
            goto L_80025278;
    }
    // 0x8002524C: nop

    // 0x80025250: beq         $at, $zero, L_80025278
    if (ctx->r1 == 0) {
        // 0x80025254: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80025278;
    }
    // 0x80025254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025258: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x8002525C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025260: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80025264: addiu       $a3, $a3, -0x49D4
    ctx->r7 = ADD32(ctx->r7, -0X49D4);
    // 0x80025268: addiu       $a2, $a2, -0x49D8
    ctx->r6 = ADD32(ctx->r6, -0X49D8);
    // 0x8002526C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80025270: jal         0x800AC3C8
    // 0x80025274: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    weather_update(rdram, ctx);
        goto after_27;
    // 0x80025274: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_27:
L_80025278:
    // 0x80025278: jal         0x80069F60
    // 0x8002527C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_28;
    // 0x8002527C: nop

    after_28:
    // 0x80025280: jal         0x800AD590
    // 0x80025284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    lensflare_override(rdram, ctx);
        goto after_29;
    // 0x80025284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_29:
    // 0x80025288: jal         0x80069F60
    // 0x8002528C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_30;
    // 0x8002528C: nop

    after_30:
    // 0x80025290: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025294: addiu       $a2, $a2, -0x49D8
    ctx->r6 = ADD32(ctx->r6, -0X49D8);
    // 0x80025298: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002529C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800252A0: jal         0x800ACF80
    // 0x800252A4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lensflare_render(rdram, ctx);
        goto after_31;
    // 0x800252A4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_31:
    // 0x800252A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800252AC: jal         0x8001BB4C
    // 0x800252B0: nop

    get_racer_object_by_port(rdram, ctx);
        goto after_32;
    // 0x800252B0: nop

    after_32:
    // 0x800252B4: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x800252B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800252BC: addiu       $a2, $a2, -0x49D8
    ctx->r6 = ADD32(ctx->r6, -0X49D8);
    // 0x800252C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800252C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800252C8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800252CC: jal         0x800A06E0
    // 0x800252D0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    hud_render_player(rdram, ctx);
        goto after_33;
    // 0x800252D0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_33:
    // 0x800252D4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800252D8: nop

    // 0x800252DC: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x800252E0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800252E4: bne         $at, $zero, L_800250F8
    if (ctx->r1 != 0) {
        // 0x800252E8: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800250F8;
    }
    // 0x800252E8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800252EC:
    // 0x800252EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800252F0: bne         $s3, $at, L_800254A4
    if (ctx->r19 != ctx->r1) {
        // 0x800252F4: nop
    
            goto L_800254A4;
    }
    // 0x800252F4: nop

    // 0x800252F8: jal         0x8006BFD8
    // 0x800252FC: nop

    level_type(rdram, ctx);
        goto after_34;
    // 0x800252FC: nop

    after_34:
    // 0x80025300: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80025304: beq         $v0, $at, L_800254A4
    if (ctx->r2 == ctx->r1) {
        // 0x80025308: nop
    
            goto L_800254A4;
    }
    // 0x80025308: nop

    // 0x8002530C: jal         0x8006BFD8
    // 0x80025310: nop

    level_type(rdram, ctx);
        goto after_35;
    // 0x80025310: nop

    after_35:
    // 0x80025314: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80025318: beq         $v0, $at, L_800254A4
    if (ctx->r2 == ctx->r1) {
        // 0x8002531C: nop
    
            goto L_800254A4;
    }
    // 0x8002531C: nop

    // 0x80025320: jal         0x8006BFD8
    // 0x80025324: nop

    level_type(rdram, ctx);
        goto after_36;
    // 0x80025324: nop

    after_36:
    // 0x80025328: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x8002532C: beq         $v0, $at, L_800254A4
    if (ctx->r2 == ctx->r1) {
        // 0x80025330: nop
    
            goto L_800254A4;
    }
    // 0x80025330: nop

    // 0x80025334: jal         0x800A89B4
    // 0x80025338: nop

    hud_setting(rdram, ctx);
        goto after_37;
    // 0x80025338: nop

    after_37:
    // 0x8002533C: bne         $v0, $zero, L_80025490
    if (ctx->r2 != 0) {
        // 0x80025340: nop
    
            goto L_80025490;
    }
    // 0x80025340: nop

    // 0x80025344: lb          $t9, 0x83($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X83);
    // 0x80025348: nop

    // 0x8002534C: beq         $t9, $zero, L_80025370
    if (ctx->r25 == 0) {
        // 0x80025350: nop
    
            goto L_80025370;
    }
    // 0x80025350: nop

    // 0x80025354: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025358: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x8002535C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80025360: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80025364: addiu       $t4, $zero, 0x1000
    ctx->r12 = ADD32(0, 0X1000);
    // 0x80025368: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8002536C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80025370:
    // 0x80025370: jal         0x8003097C
    // 0x80025374: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    apply_fog(rdram, ctx);
        goto after_38;
    // 0x80025374: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_38:
    // 0x80025378: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8002537C: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80025380: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80025384: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80025388: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002538C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025390: jal         0x80066828
    // 0x80025394: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    set_active_camera(rdram, ctx);
        goto after_39;
    // 0x80025394: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    after_39:
    // 0x80025398: jal         0x80066760
    // 0x8002539C: nop

    disable_cutscene_camera(rdram, ctx);
        goto after_40;
    // 0x8002539C: nop

    after_40:
    // 0x800253A0: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800253A4: jal         0x80027928
    // 0x800253A8: nop

    ttcam_update(rdram, ctx);
        goto after_41;
    // 0x800253A8: nop

    after_41:
    // 0x800253AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800253B0: jal         0x80066F1C
    // 0x800253B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    viewport_main(rdram, ctx);
        goto after_42;
    // 0x800253B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_42:
    // 0x800253B8: jal         0x8002A35C
    // 0x800253BC: nop

    func_8002A31C(rdram, ctx);
        goto after_43;
    // 0x800253BC: nop

    after_43:
    // 0x800253C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800253C4: jal         0x800682BC
    // 0x800253C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_perspective(rdram, ctx);
        goto after_44;
    // 0x800253C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_44:
    // 0x800253CC: jal         0x800289F8
    // 0x800253D0: nop

    trackbg_render_gradient(rdram, ctx);
        goto after_45;
    // 0x800253D0: nop

    after_45:
    // 0x800253D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800253D8: jal         0x80067F7C
    // 0x800253DC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80067D3C(rdram, ctx);
        goto after_46;
    // 0x800253DC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_46:
    // 0x800253E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800253E4: jal         0x80068648
    // 0x800253E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_world_origin(rdram, ctx);
        goto after_47;
    // 0x800253E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_47:
    // 0x800253EC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800253F0: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800253F4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800253F8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800253FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025400: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80025404: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80025408: jal         0x80028D10
    // 0x8002540C: nop

    initialise_player_viewport_vars(rdram, ctx);
        goto after_48;
    // 0x8002540C: nop

    after_48:
    // 0x80025410: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80025414: jal         0x800AB868
    // 0x80025418: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    weather_clip_planes(rdram, ctx);
        goto after_49;
    // 0x80025418: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    after_49:
    // 0x8002541C: jal         0x80069F60
    // 0x80025420: nop

    cam_get_active_camera(rdram, ctx);
        goto after_50;
    // 0x80025420: nop

    after_50:
    // 0x80025424: jal         0x800AD590
    // 0x80025428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    lensflare_override(rdram, ctx);
        goto after_51;
    // 0x80025428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_51:
    // 0x8002542C: jal         0x80069F60
    // 0x80025430: nop

    cam_get_active_camera(rdram, ctx);
        goto after_52;
    // 0x80025430: nop

    after_52:
    // 0x80025434: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025438: addiu       $a2, $a2, -0x49D8
    ctx->r6 = ADD32(ctx->r6, -0X49D8);
    // 0x8002543C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025440: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80025444: jal         0x800ACF80
    // 0x80025448: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lensflare_render(rdram, ctx);
        goto after_53;
    // 0x80025448: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_53:
    // 0x8002544C: jal         0x800C484C
    // 0x80025450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_54;
    // 0x80025450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_54:
    // 0x80025454: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80025458: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x8002545C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025460: bne         $t9, $zero, L_80025474
    if (ctx->r25 != 0) {
        // 0x80025464: lui         $a3, 0x800E
        ctx->r7 = S32(0X800E << 16);
            goto L_80025474;
    }
    // 0x80025464: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80025468: addiu       $a1, $zero, 0xA6
    ctx->r5 = ADD32(0, 0XA6);
    // 0x8002546C: b           L_8002547C
    // 0x80025470: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
        goto L_8002547C;
    // 0x80025470: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
L_80025474:
    // 0x80025474: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x80025478: addiu       $a2, $zero, 0x7D
    ctx->r6 = ADD32(0, 0X7D);
L_8002547C:
    // 0x8002547C: addiu       $a3, $a3, 0x6380
    ctx->r7 = ADD32(ctx->r7, 0X6380);
    // 0x80025480: jal         0x800C49A0
    // 0x80025484: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    draw_text(rdram, ctx);
        goto after_55;
    // 0x80025484: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_55:
    // 0x80025488: b           L_800254A4
    // 0x8002548C: nop

        goto L_800254A4;
    // 0x8002548C: nop

L_80025490:
    // 0x80025490: jal         0x80066828
    // 0x80025494: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    set_active_camera(rdram, ctx);
        goto after_56;
    // 0x80025494: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_56:
    // 0x80025498: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8002549C: jal         0x80027928
    // 0x800254A0: nop

    ttcam_update(rdram, ctx);
        goto after_57;
    // 0x800254A0: nop

    after_57:
L_800254A4:
    // 0x800254A4: jal         0x800684EC
    // 0x800254A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    viewport_reset(rdram, ctx);
        goto after_58;
    // 0x800254A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_58:
    // 0x800254AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800254B0: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800254B4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800254B8: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800254BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800254C0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800254C4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800254C8: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x800254CC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800254D0: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x800254D4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800254D8: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800254DC: addiu       $a1, $a1, -0x49B8
    ctx->r5 = ADD32(ctx->r5, -0X49B8);
    // 0x800254E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800254E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800254E8: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800254EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800254F0: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x800254F4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800254F8: subu        $t8, $t6, $t5
    ctx->r24 = SUB32(ctx->r14, ctx->r13);
    // 0x800254FC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80025500: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80025504: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x80025508: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8002550C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80025510: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80025514: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x80025518: lw          $t7, -0x49D8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X49D8);
    // 0x8002551C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80025520: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80025524: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80025528: lw          $t5, -0x49D4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X49D4);
    // 0x8002552C: nop

    // 0x80025530: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x80025534: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80025538: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8002553C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80025540: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80025544: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80025548: jr          $ra
    // 0x8002554C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8002554C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void void_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025550: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80025554: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025558: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002555C: addiu       $t1, $t1, -0x25C6
    ctx->r9 = ADD32(ctx->r9, -0X25C6);
    // 0x80025560: addiu       $a2, $a2, -0x25C4
    ctx->r6 = ADD32(ctx->r6, -0X25C4);
    // 0x80025564: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80025568: addiu       $t6, $zero, 0xAF
    ctx->r14 = ADD32(0, 0XAF);
    // 0x8002556C: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x80025570: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80025574: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80025578: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002557C: sh          $t6, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r14;
    // 0x80025580: bne         $at, $zero, L_80025598
    if (ctx->r1 != 0) {
        // 0x80025584: sh          $t7, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r15;
            goto L_80025598;
    }
    // 0x80025584: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x80025588: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x8002558C: nop

    // 0x80025590: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80025594: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80025598:
    // 0x80025598: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x8002559C: lh          $v1, 0x0($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X0);
    // 0x800255A0: sll         $a3, $t0, 2
    ctx->r7 = S32(ctx->r8 << 2);
    // 0x800255A4: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x800255A8: addu        $t5, $t5, $a3
    ctx->r13 = ADD32(ctx->r13, ctx->r7);
    // 0x800255AC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800255B0: sll         $t6, $t0, 5
    ctx->r14 = S32(ctx->r8 << 5);
    // 0x800255B4: sll         $t2, $v1, 3
    ctx->r10 = S32(ctx->r3 << 3);
    // 0x800255B8: addiu       $t3, $t2, 0x30
    ctx->r11 = ADD32(ctx->r10, 0X30);
    // 0x800255BC: addiu       $a3, $t5, 0xC8
    ctx->r7 = ADD32(ctx->r13, 0XC8);
    // 0x800255C0: addiu       $t0, $t6, 0xA0
    ctx->r8 = ADD32(ctx->r14, 0XA0);
    // 0x800255C4: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800255C8: addiu       $t4, $v1, 0x5
    ctx->r12 = ADD32(ctx->r3, 0X5);
    // 0x800255CC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800255D0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800255D4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800255D8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800255DC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800255E0: jal         0x80070EDC
    // 0x800255E4: sll         $a0, $s0, 4
    ctx->r4 = S32(ctx->r16 << 4);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800255E4: sll         $a0, $s0, 4
    ctx->r4 = S32(ctx->r16 << 4);
    after_0:
    // 0x800255E8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800255EC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800255F0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800255F4: addu        $t2, $a3, $t0
    ctx->r10 = ADD32(ctx->r7, ctx->r8);
    // 0x800255F8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800255FC: multu       $t3, $s0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80025600: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80025604: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025608: addiu       $a2, $a2, -0x260C
    ctx->r6 = ADD32(ctx->r6, -0X260C);
    // 0x8002560C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80025610: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80025614: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80025618: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8002561C: mflo        $t4
    ctx->r12 = lo;
    // 0x80025620: addu        $a0, $t9, $t4
    ctx->r4 = ADD32(ctx->r25, ctx->r12);
    // 0x80025624: jal         0x80070EDC
    // 0x80025628: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80025628: nop

    after_1:
    // 0x8002562C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80025630: addiu       $a0, $a0, -0x316C
    ctx->r4 = ADD32(ctx->r4, -0X316C);
    // 0x80025634: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025638: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8002563C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80025640: addiu       $a2, $a2, -0x260C
    ctx->r6 = ADD32(ctx->r6, -0X260C);
    // 0x80025644: beq         $v0, $zero, L_800257F8
    if (ctx->r2 == 0) {
        // 0x80025648: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_800257F8;
    }
    // 0x80025648: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002564C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80025650: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025654: sw          $v0, -0x2608($at)
    MEM_W(-0X2608, ctx->r1) = ctx->r2;
    // 0x80025658: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8002565C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025660: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
    // 0x80025664: sw          $v1, -0x2604($at)
    MEM_W(-0X2604, ctx->r1) = ctx->r3;
    // 0x80025668: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8002566C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80025670: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80025674: and         $t7, $v1, $at
    ctx->r15 = ctx->r3 & ctx->r1;
    // 0x80025678: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8002567C: blez        $s0, L_800257F8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80025680: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800257F8;
    }
    // 0x80025680: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80025684: andi        $t1, $s0, 0x3
    ctx->r9 = ctx->r16 & 0X3;
    // 0x80025688: beq         $t1, $zero, L_800256E4
    if (ctx->r9 == 0) {
        // 0x8002568C: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_800256E4;
    }
    // 0x8002568C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80025690: sll         $v0, $zero, 4
    ctx->r2 = S32(0 << 4);
L_80025694:
    // 0x80025694: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80025698: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002569C: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800256A0: sw          $v1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r3;
    // 0x800256A4: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800256A8: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800256AC: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x800256B0: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
    // 0x800256B4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800256B8: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800256BC: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800256C0: sw          $v1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r3;
    // 0x800256C4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800256C8: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800256CC: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800256D0: sw          $v1, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r3;
    // 0x800256D4: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800256D8: bne         $a1, $a0, L_80025694
    if (ctx->r5 != ctx->r4) {
        // 0x800256DC: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_80025694;
    }
    // 0x800256DC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800256E0: beq         $a0, $s0, L_800257F8
    if (ctx->r4 == ctx->r16) {
        // 0x800256E4: sll         $v0, $a0, 4
        ctx->r2 = S32(ctx->r4 << 4);
            goto L_800257F8;
    }
L_800256E4:
    // 0x800256E4: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800256E8: sll         $a1, $s0, 4
    ctx->r5 = S32(ctx->r16 << 4);
L_800256EC:
    // 0x800256EC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800256F0: nop

    // 0x800256F4: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800256F8: sw          $v1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r3;
    // 0x800256FC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80025700: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025704: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x80025708: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
    // 0x8002570C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80025710: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025714: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80025718: sw          $v1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r3;
    // 0x8002571C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80025720: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025724: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80025728: sw          $v1, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r3;
    // 0x8002572C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80025730: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025734: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x80025738: sw          $v1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r3;
    // 0x8002573C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80025740: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025744: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x80025748: sw          $v1, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r3;
    // 0x8002574C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80025750: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025754: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80025758: sw          $v1, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r3;
    // 0x8002575C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80025760: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025764: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80025768: sw          $v1, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r3;
    // 0x8002576C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80025770: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025774: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x80025778: sw          $v1, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r3;
    // 0x8002577C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80025780: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025784: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x80025788: sw          $v1, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r3;
    // 0x8002578C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80025790: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025794: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80025798: sw          $v1, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r3;
    // 0x8002579C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800257A0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800257A4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800257A8: sw          $v1, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r3;
    // 0x800257AC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800257B0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800257B4: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800257B8: sw          $v1, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r3;
    // 0x800257BC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800257C0: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800257C4: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x800257C8: sw          $v1, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r3;
    // 0x800257CC: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800257D0: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800257D4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800257D8: sw          $v1, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r3;
    // 0x800257DC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800257E0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800257E4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800257E8: sw          $v1, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r3;
    // 0x800257EC: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800257F0: bne         $v0, $a1, L_800256EC
    if (ctx->r2 != ctx->r5) {
        // 0x800257F4: addu        $v1, $v1, $a3
        ctx->r3 = ADD32(ctx->r3, ctx->r7);
            goto L_800256EC;
    }
    // 0x800257F4: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
L_800257F8:
    // 0x800257F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800257FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025800: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80025804: sb          $zero, -0x25CC($at)
    MEM_B(-0X25CC, ctx->r1) = 0;
    // 0x80025808: jr          $ra
    // 0x8002580C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002580C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void void_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025810: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80025814: lw          $t6, -0x316C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X316C);
    // 0x80025818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002581C: beq         $t6, $zero, L_8002584C
    if (ctx->r14 == 0) {
        // 0x80025820: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8002584C;
    }
    // 0x80025820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025824: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80025828: lw          $a0, -0x260C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X260C);
    // 0x8002582C: jal         0x80071380
    // 0x80025830: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x80025830: nop

    after_0:
    // 0x80025834: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80025838: lw          $a0, -0x316C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X316C);
    // 0x8002583C: jal         0x80071380
    // 0x80025840: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x80025840: nop

    after_1:
    // 0x80025844: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80025848: sw          $zero, -0x316C($at)
    MEM_W(-0X316C, ctx->r1) = 0;
L_8002584C:
    // 0x8002584C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025854: jr          $ra
    // 0x80025858: nop

    return;
    // 0x80025858: nop

;}
RECOMP_FUNC void void_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002585C: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80025860: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80025864: lw          $t6, -0x260C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X260C);
    // 0x80025868: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x8002586C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80025870: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80025874: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80025878: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8002587C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80025880: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80025884: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80025888: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8002588C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80025890: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80025894: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80025898: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002589C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800258A0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800258A4: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x800258A8: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x800258AC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800258B0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800258B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800258B8: addiu       $v1, $v1, -0x25F0
    ctx->r3 = ADD32(ctx->r3, -0X25F0);
    // 0x800258BC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800258C0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800258C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800258C8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800258CC: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800258D0: addiu       $t0, $t0, -0x2600
    ctx->r8 = ADD32(ctx->r8, -0X2600);
    // 0x800258D4: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800258D8: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800258DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800258E0: addiu       $a0, $a0, -0x49E0
    ctx->r4 = ADD32(ctx->r4, -0X49E0);
    // 0x800258E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800258E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800258EC: jal         0x8007B918
    // 0x800258F0: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x800258F0: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    after_0:
    // 0x800258F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800258F8: sh          $zero, -0x25E4($at)
    MEM_H(-0X25E4, ctx->r1) = 0;
    // 0x800258FC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80025900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025904: addiu       $s0, $s0, -0x49D0
    ctx->r16 = ADD32(ctx->r16, -0X49D0);
    // 0x80025908: sh          $zero, -0x25E2($at)
    MEM_H(-0X25E2, ctx->r1) = 0;
    // 0x8002590C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80025910: nop

    // 0x80025914: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    // 0x80025918: nop

    // 0x8002591C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80025920: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x80025924: jal         0x80070A04
    // 0x80025928: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80025928: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_1:
    // 0x8002592C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80025930: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80025934: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x80025938: nop

    // 0x8002593C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80025940: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80025944: jal         0x80070A38
    // 0x80025948: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_2;
    // 0x80025948: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_2:
    // 0x8002594C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80025950: lwc1        $f15, 0x63F0($at)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r1, 0X63F0);
    // 0x80025954: lwc1        $f14, 0x63F4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X63F4);
    // 0x80025958: cvt.d.s     $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f8.d = CVT_D_S(ctx->f26.fl);
    // 0x8002595C: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80025960: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80025964: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80025968: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002596C: addiu       $v1, $v1, -0x25D4
    ctx->r3 = ADD32(ctx->r3, -0X25D4);
    // 0x80025970: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80025974: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x80025978: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002597C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80025980: addiu       $a0, $a0, -0x25D0
    ctx->r4 = ADD32(ctx->r4, -0X25D0);
    // 0x80025984: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80025988: mul.d       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x8002598C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x80025990: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80025994: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80025998: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002599C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800259A0: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800259A4: addiu       $a1, $a1, -0x25E0
    ctx->r5 = ADD32(ctx->r5, -0X25E0);
    // 0x800259A8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800259AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800259B0: mul.s       $f4, $f26, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x800259B4: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800259B8: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800259BC: addiu       $a2, $a2, -0x25DC
    ctx->r6 = ADD32(ctx->r6, -0X25DC);
    // 0x800259C0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x800259C4: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800259C8: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x800259CC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800259D0: swc1        $f26, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f26.u32l;
    // 0x800259D4: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800259D8: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800259DC: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x800259E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800259E4: add.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800259E8: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800259EC: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800259F0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800259F4: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    // 0x800259F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800259FC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80025A00: addiu       $s4, $s4, -0x3178
    ctx->r20 = ADD32(ctx->r20, -0X3178);
    // 0x80025A04: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80025A08: blez        $t2, L_80025BB0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80025A0C: swc1        $f8, -0x25D8($at)
        MEM_W(-0X25D8, ctx->r1) = ctx->f8.u32l;
            goto L_80025BB0;
    }
    // 0x80025A0C: swc1        $f8, -0x25D8($at)
    MEM_W(-0X25D8, ctx->r1) = ctx->f8.u32l;
    // 0x80025A10: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x80025A14: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80025A18: addiu       $s3, $zero, 0x44
    ctx->r19 = ADD32(0, 0X44);
    // 0x80025A1C: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
L_80025A20:
    // 0x80025A20: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x80025A24: addu        $s1, $s2, $t3
    ctx->r17 = ADD32(ctx->r18, ctx->r11);
    // 0x80025A28: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80025A2C: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x80025A30: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80025A34: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x80025A38: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80025A3C: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x80025A40: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80025A44: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x80025A48: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80025A4C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80025A50: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80025A54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025A58: mul.s       $f0, $f18, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x80025A5C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80025A60: mul.s       $f2, $f24, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x80025A64: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80025A68: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x80025A6C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80025A70: c.le.d      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.d <= ctx->f20.d;
    // 0x80025A74: nop

    // 0x80025A78: bc1f        L_80025A84
    if (!c1cs) {
        // 0x80025A7C: nop
    
            goto L_80025A84;
    }
    // 0x80025A7C: nop

    // 0x80025A80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80025A84:
    // 0x80025A84: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x80025A88: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80025A8C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80025A90: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80025A94: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80025A98: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80025A9C: mul.s       $f12, $f26, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x80025AA0: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80025AA4: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80025AA8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80025AAC: c.le.d      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.d <= ctx->f20.d;
    // 0x80025AB0: nop

    // 0x80025AB4: bc1f        L_80025AC0
    if (!c1cs) {
        // 0x80025AB8: nop
    
            goto L_80025AC0;
    }
    // 0x80025AB8: nop

    // 0x80025ABC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80025AC0:
    // 0x80025AC0: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x80025AC4: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x80025AC8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80025ACC: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x80025AD0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80025AD4: sra         $a2, $t4, 16
    ctx->r6 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80025AD8: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80025ADC: mul.s       $f14, $f24, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x80025AE0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80025AE4: add.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80025AE8: add.s       $f4, $f16, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x80025AEC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80025AF0: c.le.d      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.d <= ctx->f20.d;
    // 0x80025AF4: add.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80025AF8: bc1f        L_80025B04
    if (!c1cs) {
        // 0x80025AFC: add.s       $f10, $f8, $f22
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
            goto L_80025B04;
    }
    // 0x80025AFC: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80025B00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80025B04:
    // 0x80025B04: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80025B08: c.le.d      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.d <= ctx->f20.d;
    // 0x80025B0C: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x80025B10: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80025B14: bc1f        L_80025B20
    if (!c1cs) {
        // 0x80025B18: sra         $a2, $t8, 16
        ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
            goto L_80025B20;
    }
    // 0x80025B18: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80025B1C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80025B20:
    // 0x80025B20: addu        $t4, $a2, $t2
    ctx->r12 = ADD32(ctx->r6, ctx->r10);
    // 0x80025B24: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x80025B28: beq         $t5, $zero, L_80025B94
    if (ctx->r13 == 0) {
        // 0x80025B2C: nop
    
            goto L_80025B94;
    }
    // 0x80025B2C: nop

    // 0x80025B30: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80025B34: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80025B38: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80025B3C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80025B40: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80025B44: mflo        $t6
    ctx->r14 = lo;
    // 0x80025B48: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80025B4C: jal         0x80026470
    // 0x80025B50: nop

    func_80026430(rdram, ctx);
        goto after_3;
    // 0x80025B50: nop

    after_3:
    // 0x80025B54: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x80025B58: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80025B5C: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80025B60: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80025B64: mflo        $t3
    ctx->r11 = lo;
    // 0x80025B68: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80025B6C: lw          $t5, 0x3C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X3C);
    // 0x80025B70: nop

    // 0x80025B74: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80025B78: beq         $t6, $zero, L_80025B94
    if (ctx->r14 == 0) {
        // 0x80025B7C: nop
    
            goto L_80025B94;
    }
    // 0x80025B7C: nop

    // 0x80025B80: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80025B84: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80025B88: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80025B8C: jal         0x800260B0
    // 0x80025B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80026070(rdram, ctx);
        goto after_4;
    // 0x80025B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80025B94:
    // 0x80025B94: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80025B98: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x80025B9C: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x80025BA0: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80025BA4: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80025BA8: bne         $at, $zero, L_80025A20
    if (ctx->r1 != 0) {
        // 0x80025BAC: lw          $t3, 0xC0($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XC0);
            goto L_80025A20;
    }
    // 0x80025BAC: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
L_80025BB0:
    // 0x80025BB0: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80025BB4: addiu       $s4, $s4, -0x3178
    ctx->r20 = ADD32(ctx->r20, -0X3178);
    // 0x80025BB8: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80025BBC: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    // 0x80025BC0: lh          $a1, 0x40($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X40);
    // 0x80025BC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80025BC8: addiu       $a1, $a1, -0xC3
    ctx->r5 = ADD32(ctx->r5, -0XC3);
    // 0x80025BCC: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x80025BD0: jal         0x80026C54
    // 0x80025BD4: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    func_80026C14(rdram, ctx);
        goto after_5;
    // 0x80025BD4: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    after_5:
    // 0x80025BD8: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80025BDC: addiu       $a0, $zero, -0x12C
    ctx->r4 = ADD32(0, -0X12C);
    // 0x80025BE0: lh          $a1, 0x40($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X40);
    // 0x80025BE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80025BE8: addiu       $a1, $a1, -0xC3
    ctx->r5 = ADD32(ctx->r5, -0XC3);
    // 0x80025BEC: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80025BF0: jal         0x80026C54
    // 0x80025BF4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_80026C14(rdram, ctx);
        goto after_6;
    // 0x80025BF4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_6:
    // 0x80025BF8: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80025BFC: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    // 0x80025C00: lh          $a1, 0x42($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X42);
    // 0x80025C04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025C08: addiu       $a1, $a1, 0xC3
    ctx->r5 = ADD32(ctx->r5, 0XC3);
    // 0x80025C0C: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x80025C10: jal         0x80026C54
    // 0x80025C14: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    func_80026C14(rdram, ctx);
        goto after_7;
    // 0x80025C14: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_7:
    // 0x80025C18: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80025C1C: addiu       $a0, $zero, -0x12C
    ctx->r4 = ADD32(0, -0X12C);
    // 0x80025C20: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x80025C24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025C28: addiu       $a1, $a1, 0xC3
    ctx->r5 = ADD32(ctx->r5, 0XC3);
    // 0x80025C2C: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80025C30: jal         0x80026C54
    // 0x80025C34: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    func_80026C14(rdram, ctx);
        goto after_8;
    // 0x80025C34: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_8:
    // 0x80025C38: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80025C3C: addiu       $t1, $t1, -0x25E2
    ctx->r9 = ADD32(ctx->r9, -0X25E2);
    // 0x80025C40: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80025C44: lh          $t6, -0x25C6($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X25C6);
    // 0x80025C48: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80025C4C: nop

    // 0x80025C50: slt         $at, $a3, $t6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80025C54: beq         $at, $zero, L_80026074
    if (ctx->r1 == 0) {
        // 0x80025C58: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80026074;
    }
    // 0x80025C58: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80025C5C: beq         $a3, $zero, L_80026070
    if (ctx->r7 == 0) {
        // 0x80025C60: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80026070;
    }
    // 0x80025C60: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80025C64: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80025C68: addiu       $t0, $t0, -0x2608
    ctx->r8 = ADD32(ctx->r8, -0X2608);
    // 0x80025C6C: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
L_80025C70:
    // 0x80025C70: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80025C74: blez        $a1, L_80025CE0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80025C78: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80025CE0;
    }
    // 0x80025C78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80025C7C:
    // 0x80025C7C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80025C80: sll         $t8, $s2, 3
    ctx->r24 = S32(ctx->r18 << 3);
    // 0x80025C84: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80025C88: lh          $t2, 0x8($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X8);
    // 0x80025C8C: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x80025C90: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80025C94: slt         $at, $t2, $t9
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80025C98: beq         $at, $zero, L_80025CCC
    if (ctx->r1 == 0) {
        // 0x80025C9C: sll         $t5, $s2, 16
        ctx->r13 = S32(ctx->r18 << 16);
            goto L_80025CCC;
    }
    // 0x80025C9C: sll         $t5, $s2, 16
    ctx->r13 = S32(ctx->r18 << 16);
    // 0x80025CA0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80025CA4: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80025CA8: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x80025CAC: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80025CB0: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x80025CB4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80025CB8: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80025CBC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80025CC0: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80025CC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025CC8: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
L_80025CCC:
    // 0x80025CCC: sra         $s2, $t5, 16
    ctx->r18 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80025CD0: slt         $at, $s2, $a1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80025CD4: bne         $at, $zero, L_80025C7C
    if (ctx->r1 != 0) {
        // 0x80025CD8: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80025C7C;
    }
    // 0x80025CD8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80025CDC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80025CE0:
    // 0x80025CE0: beq         $a2, $zero, L_80025C70
    if (ctx->r6 == 0) {
        // 0x80025CE4: nop
    
            goto L_80025C70;
    }
    // 0x80025CE4: nop

    // 0x80025CE8: blez        $a3, L_80025D74
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80025CEC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80025D74;
    }
    // 0x80025CEC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80025CF0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80025CF4: addiu       $a1, $a1, -0x2604
    ctx->r5 = ADD32(ctx->r5, -0X2604);
    // 0x80025CF8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80025CFC:
    // 0x80025CFC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80025D00: sll         $t8, $s2, 3
    ctx->r24 = S32(ctx->r18 << 3);
    // 0x80025D04: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80025D08: lb          $t2, 0x7($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X7);
    // 0x80025D0C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80025D10: sll         $t9, $t2, 17
    ctx->r25 = S32(ctx->r10 << 17);
    // 0x80025D14: sra         $t3, $t9, 16
    ctx->r11 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80025D18: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80025D1C: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x80025D20: nop

    // 0x80025D24: bne         $a2, $t5, L_80025D50
    if (ctx->r6 != ctx->r13) {
        // 0x80025D28: nop
    
            goto L_80025D50;
    }
    // 0x80025D28: nop

    // 0x80025D2C: lb          $t6, 0x6($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X6);
    // 0x80025D30: nop

    // 0x80025D34: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80025D38: sb          $t7, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r15;
    // 0x80025D3C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80025D40: nop

    // 0x80025D44: addu        $t2, $t8, $t3
    ctx->r10 = ADD32(ctx->r24, ctx->r11);
    // 0x80025D48: b           L_80025D54
    // 0x80025D4C: sb          $s2, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r18;
        goto L_80025D54;
    // 0x80025D4C: sb          $s2, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r18;
L_80025D50:
    // 0x80025D50: sb          $s2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r18;
L_80025D54:
    // 0x80025D54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80025D58: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80025D5C: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x80025D60: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80025D64: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025D68: bne         $at, $zero, L_80025CFC
    if (ctx->r1 != 0) {
        // 0x80025D6C: nop
    
            goto L_80025CFC;
    }
    // 0x80025D6C: nop

    // 0x80025D70: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80025D74:
    // 0x80025D74: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80025D78: addiu       $a0, $a0, -0x25CC
    ctx->r4 = ADD32(ctx->r4, -0X25CC);
    // 0x80025D7C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80025D80: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80025D84: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80025D88: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80025D8C: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80025D90: lw          $t8, -0x2600($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2600);
    // 0x80025D94: lh          $s3, 0x0($t4)
    ctx->r19 = MEM_H(ctx->r12, 0X0);
    // 0x80025D98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80025D9C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80025DA0: lw          $t6, -0x49D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X49D8);
    // 0x80025DA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025DA8: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80025DAC: lw          $t2, -0x25F0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X25F0);
    // 0x80025DB0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80025DB4: sw          $t8, -0x49D8($at)
    MEM_W(-0X49D8, ctx->r1) = ctx->r24;
    // 0x80025DB8: lw          $t7, -0x49D4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X49D4);
    // 0x80025DBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025DC0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80025DC4: subu        $t3, $t9, $v0
    ctx->r11 = SUB32(ctx->r25, ctx->r2);
    // 0x80025DC8: sll         $s4, $s3, 16
    ctx->r20 = S32(ctx->r19 << 16);
    // 0x80025DCC: sw          $t2, -0x49D4($at)
    MEM_W(-0X49D4, ctx->r1) = ctx->r10;
    // 0x80025DD0: sra         $t5, $s4, 16
    ctx->r13 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80025DD4: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x80025DD8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80025DDC: lw          $t4, -0x49D8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X49D8);
    // 0x80025DE0: or          $s4, $t5, $zero
    ctx->r20 = ctx->r13 | 0;
    // 0x80025DE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025DE8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80025DEC: lw          $t5, -0x49D4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X49D4);
    // 0x80025DF0: sw          $t4, -0x25F8($at)
    MEM_W(-0X25F8, ctx->r1) = ctx->r12;
    // 0x80025DF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025DF8: sw          $t5, -0x25E8($at)
    MEM_W(-0X25E8, ctx->r1) = ctx->r13;
    // 0x80025DFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025E00: sh          $zero, -0x25CA($at)
    MEM_H(-0X25CA, ctx->r1) = 0;
    // 0x80025E04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025E08: sh          $zero, -0x25C8($at)
    MEM_H(-0X25C8, ctx->r1) = 0;
    // 0x80025E0C: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x80025E10: blez        $a3, L_80025F84
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80025E14: sw          $t7, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r15;
            goto L_80025F84;
    }
    // 0x80025E14: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
    // 0x80025E18: addiu       $s1, $sp, 0x7C
    ctx->r17 = ADD32(ctx->r29, 0X7C);
    // 0x80025E1C: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025E20:
    // 0x80025E20: beq         $at, $zero, L_80025F0C
    if (ctx->r1 == 0) {
        // 0x80025E24: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025F0C;
    }
    // 0x80025E24: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025E28: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80025E2C: sll         $t6, $s2, 3
    ctx->r14 = S32(ctx->r18 << 3);
    // 0x80025E30: addu        $a0, $a1, $t6
    ctx->r4 = ADD32(ctx->r5, ctx->r14);
    // 0x80025E34: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80025E38: nop

    // 0x80025E3C: bne         $s4, $t7, L_80025F0C
    if (ctx->r20 != ctx->r15) {
        // 0x80025E40: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025F0C;
    }
    // 0x80025E40: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025E44:
    // 0x80025E44: lb          $t8, 0x6($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X6);
    // 0x80025E48: addu        $t3, $s1, $s0
    ctx->r11 = ADD32(ctx->r17, ctx->r16);
    // 0x80025E4C: andi        $t2, $t8, 0x2
    ctx->r10 = ctx->r24 & 0X2;
    // 0x80025E50: beq         $t2, $zero, L_80025E70
    if (ctx->r10 == 0) {
        // 0x80025E54: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80025E70;
    }
    // 0x80025E54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80025E58: lb          $t9, 0x7($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X7);
    // 0x80025E5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80025E60: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80025E64: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80025E68: b           L_80025EDC
    // 0x80025E6C: sb          $t9, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r25;
        goto L_80025EDC;
    // 0x80025E6C: sb          $t9, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r25;
L_80025E70:
    // 0x80025E70: blez        $s0, L_80025EDC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80025E74: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80025EDC;
    }
    // 0x80025E74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80025E78: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
L_80025E7C:
    // 0x80025E7C: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x80025E80: lb          $t8, 0x7($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X7);
    // 0x80025E84: nop

    // 0x80025E88: bne         $t7, $t8, L_80025EC4
    if (ctx->r15 != ctx->r24) {
        // 0x80025E8C: nop
    
            goto L_80025EC4;
    }
    // 0x80025E8C: nop

    // 0x80025E90: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80025E94: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x80025E98: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80025E9C: slt         $at, $v1, $s0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80025EA0: beq         $at, $zero, L_80025EC4
    if (ctx->r1 == 0) {
        // 0x80025EA4: addu        $v0, $s1, $v1
        ctx->r2 = ADD32(ctx->r17, ctx->r3);
            goto L_80025EC4;
    }
L_80025EA4:
    // 0x80025EA4: addu        $v0, $s1, $v1
    ctx->r2 = ADD32(ctx->r17, ctx->r3);
    // 0x80025EA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80025EAC: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x80025EB0: lb          $t3, 0x1($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X1);
    // 0x80025EB4: sra         $v1, $t4, 16
    ctx->r3 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80025EB8: slt         $at, $v1, $s0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80025EBC: bne         $at, $zero, L_80025EA4
    if (ctx->r1 != 0) {
        // 0x80025EC0: sb          $t3, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r11;
            goto L_80025EA4;
    }
    // 0x80025EC0: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_80025EC4:
    // 0x80025EC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80025EC8: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80025ECC: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80025ED0: slt         $at, $v1, $s0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80025ED4: bne         $at, $zero, L_80025E7C
    if (ctx->r1 != 0) {
        // 0x80025ED8: addu        $t6, $s1, $v1
        ctx->r14 = ADD32(ctx->r17, ctx->r3);
            goto L_80025E7C;
    }
    // 0x80025ED8: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
L_80025EDC:
    // 0x80025EDC: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x80025EE0: sra         $t2, $t8, 16
    ctx->r10 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80025EE4: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025EE8: beq         $at, $zero, L_80025F08
    if (ctx->r1 == 0) {
        // 0x80025EEC: or          $s2, $t2, $zero
        ctx->r18 = ctx->r10 | 0;
            goto L_80025F08;
    }
    // 0x80025EEC: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x80025EF0: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x80025EF4: addu        $a0, $a1, $t9
    ctx->r4 = ADD32(ctx->r5, ctx->r25);
    // 0x80025EF8: lh          $t3, 0x0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X0);
    // 0x80025EFC: nop

    // 0x80025F00: beq         $s4, $t3, L_80025E44
    if (ctx->r20 == ctx->r11) {
        // 0x80025F04: nop
    
            goto L_80025E44;
    }
    // 0x80025F04: nop

L_80025F08:
    // 0x80025F08: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025F0C:
    // 0x80025F0C: beq         $at, $zero, L_80025F7C
    if (ctx->r1 == 0) {
        // 0x80025F10: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025F7C;
    }
    // 0x80025F10: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025F14: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80025F18: sll         $t5, $s2, 3
    ctx->r13 = S32(ctx->r18 << 3);
    // 0x80025F1C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80025F20: lh          $s3, 0x0($t6)
    ctx->r19 = MEM_H(ctx->r14, 0X0);
    // 0x80025F24: nop

    // 0x80025F28: beq         $s4, $s3, L_80025F7C
    if (ctx->r20 == ctx->r19) {
        // 0x80025F2C: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025F7C;
    }
    // 0x80025F2C: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025F30: mtc1        $s3, $f16
    ctx->f16.u32l = ctx->r19;
    // 0x80025F34: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x80025F38: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80025F3C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80025F40: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80025F44: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80025F48: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80025F4C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80025F50: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80025F54: jal         0x80026E94
    // 0x80025F58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80026E54(rdram, ctx);
        goto after_9;
    // 0x80025F58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80025F5C: sll         $s4, $s3, 16
    ctx->r20 = S32(ctx->r19 << 16);
    // 0x80025F60: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80025F64: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80025F68: sra         $t8, $s4, 16
    ctx->r24 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80025F6C: lh          $a3, -0x25E2($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X25E2);
    // 0x80025F70: addiu       $t0, $t0, -0x2608
    ctx->r8 = ADD32(ctx->r8, -0X2608);
    // 0x80025F74: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x80025F78: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025F7C:
    // 0x80025F7C: bne         $at, $zero, L_80025E20
    if (ctx->r1 != 0) {
        // 0x80025F80: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025E20;
    }
    // 0x80025F80: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025F84:
    // 0x80025F84: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025F88: lh          $a2, -0x25CA($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X25CA);
    // 0x80025F8C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80025F90: beq         $a2, $zero, L_80026058
    if (ctx->r6 == 0) {
        // 0x80025F94: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80026058;
    }
    // 0x80025F94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80025F98: addiu       $t0, $t0, -0x49E0
    ctx->r8 = ADD32(ctx->r8, -0X49E0);
    // 0x80025F9C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80025FA0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80025FA4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80025FA8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80025FAC: lw          $t4, -0x25F8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X25F8);
    // 0x80025FB0: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x80025FB4: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x80025FB8: andi        $t6, $t5, 0x6
    ctx->r14 = ctx->r13 & 0X6;
    // 0x80025FBC: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x80025FC0: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x80025FC4: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x80025FC8: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x80025FCC: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x80025FD0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80025FD4: sll         $t2, $t8, 16
    ctx->r10 = S32(ctx->r24 << 16);
    // 0x80025FD8: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x80025FDC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80025FE0: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x80025FE4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80025FE8: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80025FEC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80025FF0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80025FF4: lw          $t2, -0x25F8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X25F8);
    // 0x80025FF8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80025FFC: addu        $t4, $t2, $a3
    ctx->r12 = ADD32(ctx->r10, ctx->r7);
    // 0x80026000: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80026004: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80026008: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8002600C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80026010: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80026014: lh          $a1, -0x25CA($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X25CA);
    // 0x80026018: nop

    // 0x8002601C: sra         $t3, $a1, 1
    ctx->r11 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80026020: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x80026024: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x80026028: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x8002602C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80026030: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80026034: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80026038: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x8002603C: or          $t3, $t2, $t5
    ctx->r11 = ctx->r10 | ctx->r13;
    // 0x80026040: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80026044: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80026048: lw          $t6, -0x25E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X25E8);
    // 0x8002604C: nop

    // 0x80026050: addu        $t9, $t6, $a3
    ctx->r25 = ADD32(ctx->r14, ctx->r7);
    // 0x80026054: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80026058:
    // 0x80026058: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8002605C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80026060: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80026064: sw          $t7, -0x49D8($at)
    MEM_W(-0X49D8, ctx->r1) = ctx->r15;
    // 0x80026068: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002606C: sw          $t8, -0x49D4($at)
    MEM_W(-0X49D4, ctx->r1) = ctx->r24;
L_80026070:
    // 0x80026070: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80026074:
    // 0x80026074: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80026078: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002607C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80026080: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80026084: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80026088: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002608C: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80026090: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80026094: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80026098: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8002609C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800260A0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800260A4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800260A8: jr          $ra
    // 0x800260AC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800260AC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_80026070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800260B0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800260B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800260B8: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800260BC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800260C0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800260C4: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800260C8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800260CC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800260D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800260D4: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800260D8: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800260DC: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800260E0: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x800260E4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800260E8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800260EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800260F0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800260F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800260F8: addiu       $t4, $sp, 0x40
    ctx->r12 = ADD32(ctx->r29, 0X40);
    // 0x800260FC: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x80026100: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x80026104: addiu       $t3, $sp, 0x80
    ctx->r11 = ADD32(ctx->r29, 0X80);
    // 0x80026108: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8002610C: addiu       $t2, $sp, 0x70
    ctx->r10 = ADD32(ctx->r29, 0X70);
    // 0x80026110: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026114: addiu       $t1, $sp, 0x60
    ctx->r9 = ADD32(ctx->r29, 0X60);
    // 0x80026118: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x8002611C: lh          $t9, 0x4($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4);
    // 0x80026120: nop

    // 0x80026124: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80026128: nop

    // 0x8002612C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026130: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x80026134: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80026138: nop

    // 0x8002613C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80026140: nop

    // 0x80026144: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026148: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x8002614C: lh          $t7, 0xA($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XA);
    // 0x80026150: nop

    // 0x80026154: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80026158: nop

    // 0x8002615C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026160: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x80026164: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x80026168: nop

    // 0x8002616C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80026170: nop

    // 0x80026174: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026178: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x8002617C: lh          $t9, 0xA($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XA);
    // 0x80026180: nop

    // 0x80026184: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80026188: nop

    // 0x8002618C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026190: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
L_80026194:
    // 0x80026194: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80026198: addu        $t6, $t2, $v0
    ctx->r14 = ADD32(ctx->r10, ctx->r2);
    // 0x8002619C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800261A0: addu        $t7, $t3, $v0
    ctx->r15 = ADD32(ctx->r11, ctx->r2);
    // 0x800261A4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800261A8: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800261AC: addu        $t8, $t1, $v0
    ctx->r24 = ADD32(ctx->r9, ctx->r2);
    // 0x800261B0: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x800261B4: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800261B8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800261BC: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x800261C0: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x800261C4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800261C8: add.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800261CC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800261D0: c.le.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d <= ctx->f2.d;
    // 0x800261D4: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x800261D8: bc1f        L_800261E4
    if (!c1cs) {
        // 0x800261DC: nop
    
            goto L_800261E4;
    }
    // 0x800261DC: nop

    // 0x800261E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_800261E4:
    // 0x800261E4: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800261E8: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800261EC: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800261F0: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x800261F4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800261F8: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800261FC: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80026200: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026204: bne         $at, $zero, L_80026194
    if (ctx->r1 != 0) {
        // 0x80026208: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_80026194;
    }
    // 0x80026208: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8002620C: beq         $t9, $zero, L_8002645C
    if (ctx->r25 == 0) {
        // 0x80026210: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8002645C;
    }
    // 0x80026210: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80026214: beq         $t9, $at, L_8002645C
    if (ctx->r25 == ctx->r1) {
        // 0x80026218: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8002645C;
    }
    // 0x80026218: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002621C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80026220: addiu       $ra, $sp, 0x4C
    ctx->r31 = ADD32(ctx->r29, 0X4C);
    // 0x80026224: addiu       $t5, $sp, 0x54
    ctx->r13 = ADD32(ctx->r29, 0X54);
L_80026228:
    // 0x80026228: addiu       $a2, $a1, 0x1
    ctx->r6 = ADD32(ctx->r5, 0X1);
    // 0x8002622C: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x80026230: sll         $a3, $a2, 16
    ctx->r7 = S32(ctx->r6 << 16);
    // 0x80026234: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80026238: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8002623C: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80026240: bne         $at, $zero, L_8002624C
    if (ctx->r1 != 0) {
        // 0x80026244: or          $a3, $t8, $zero
        ctx->r7 = ctx->r24 | 0;
            goto L_8002624C;
    }
    // 0x80026244: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80026248: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8002624C:
    // 0x8002624C: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x80026250: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x80026254: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80026258: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8002625C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80026260: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80026264: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80026268: beq         $t9, $t8, L_800262E0
    if (ctx->r25 == ctx->r24) {
        // 0x8002626C: addu        $t7, $t1, $v0
        ctx->r15 = ADD32(ctx->r9, ctx->r2);
            goto L_800262E0;
    }
    // 0x8002626C: addu        $t7, $t1, $v0
    ctx->r15 = ADD32(ctx->r9, ctx->r2);
    // 0x80026270: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x80026274: addu        $t9, $t1, $v1
    ctx->r25 = ADD32(ctx->r9, ctx->r3);
    // 0x80026278: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8002627C: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80026280: addu        $t6, $t3, $v1
    ctx->r14 = ADD32(ctx->r11, ctx->r3);
    // 0x80026284: sub.s       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80026288: addu        $t8, $t3, $v0
    ctx->r24 = ADD32(ctx->r11, ctx->r2);
    // 0x8002628C: div.s       $f14, $f12, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80026290: lwc1        $f2, 0x0($t8)
    ctx->f2.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80026294: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80026298: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x8002629C: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800262A0: addu        $t7, $t5, $a0
    ctx->r15 = ADD32(ctx->r13, ctx->r4);
    // 0x800262A4: addu        $t8, $t2, $v1
    ctx->r24 = ADD32(ctx->r10, ctx->r3);
    // 0x800262A8: addu        $t9, $t2, $v0
    ctx->r25 = ADD32(ctx->r10, ctx->r2);
    // 0x800262AC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800262B0: addu        $t6, $ra, $a0
    ctx->r14 = ADD32(ctx->r31, ctx->r4);
    // 0x800262B4: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800262B8: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800262BC: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x800262C0: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800262C4: lwc1        $f0, 0x0($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800262C8: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800262CC: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800262D0: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800262D4: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800262D8: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800262DC: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
L_800262E0:
    // 0x800262E0: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x800262E4: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800262E8: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800262EC: bne         $at, $zero, L_80026228
    if (ctx->r1 != 0) {
        // 0x800262F0: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_80026228;
    }
    // 0x800262F0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800262F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800262F8: bne         $t0, $at, L_8002645C
    if (ctx->r8 != ctx->r1) {
        // 0x800262FC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8002645C;
    }
    // 0x800262FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80026300: lwc1        $f0, -0x25DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25DC);
    // 0x80026304: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80026308: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002630C: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80026310: lwc1        $f2, -0x25E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X25E0);
    // 0x80026314: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80026318: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002631C: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80026320: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80026324: lwc1        $f12, -0x25D8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25D8);
    // 0x80026328: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002632C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80026330: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80026334: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80026338: add.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8002633C: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80026340: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80026344: add.s       $f18, $f6, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80026348: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8002634C: nop

    // 0x80026350: bc1f        L_80026364
    if (!c1cs) {
        // 0x80026354: nop
    
            goto L_80026364;
    }
    // 0x80026354: nop

    // 0x80026358: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x8002635C: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x80026360: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
L_80026364:
    // 0x80026364: lwc1        $f13, 0x63F8($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X63F8);
    // 0x80026368: lwc1        $f12, 0x63FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X63FC);
    // 0x8002636C: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x80026370: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x80026374: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80026378: bc1t        L_8002645C
    if (c1cs) {
        // 0x8002637C: swc1        $f18, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
            goto L_8002645C;
    }
    // 0x8002637C: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x80026380: lwc1        $f15, 0x6400($at)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r1, 0X6400);
    // 0x80026384: lwc1        $f14, 0x6404($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6404);
    // 0x80026388: cvt.d.s     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.d = CVT_D_S(ctx->f16.fl);
    // 0x8002638C: c.lt.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d < ctx->f2.d;
    // 0x80026390: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x80026394: bc1t        L_8002645C
    if (c1cs) {
        // 0x80026398: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_8002645C;
    }
    // 0x80026398: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8002639C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    // 0x800263A0: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x800263A4: bc1f        L_800263B8
    if (!c1cs) {
        // 0x800263A8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800263B8;
    }
    // 0x800263A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800263AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800263B0: nop

    // 0x800263B4: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
L_800263B8:
    // 0x800263B8: c.lt.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d < ctx->f0.d;
    // 0x800263BC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800263C0: bc1f        L_800263D4
    if (!c1cs) {
        // 0x800263C4: nop
    
            goto L_800263D4;
    }
    // 0x800263C4: nop

    // 0x800263C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800263CC: nop

    // 0x800263D0: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
L_800263D4:
    // 0x800263D4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800263D8: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800263DC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800263E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800263E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800263E8: lw          $t8, -0x3178($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3178);
    // 0x800263EC: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800263F0: lh          $a1, 0x40($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X40);
    // 0x800263F4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800263F8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800263FC: addiu       $a1, $a1, -0xC3
    ctx->r5 = ADD32(ctx->r5, -0XC3);
    // 0x80026400: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80026404: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80026408: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002640C: jal         0x80026C54
    // 0x80026410: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_80026C14(rdram, ctx);
        goto after_0;
    // 0x80026410: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x80026414: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80026418: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8002641C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80026420: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026424: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026428: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8002642C: lw          $t7, -0x3178($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3178);
    // 0x80026430: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80026434: lh          $a1, 0x40($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X40);
    // 0x80026438: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8002643C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80026440: addiu       $a1, $a1, -0xC3
    ctx->r5 = ADD32(ctx->r5, -0XC3);
    // 0x80026444: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80026448: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8002644C: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026450: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80026454: jal         0x80026C54
    // 0x80026458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80026C14(rdram, ctx);
        goto after_1;
    // 0x80026458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_8002645C:
    // 0x8002645C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80026460: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80026464: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80026468: jr          $ra
    // 0x8002646C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8002646C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80026430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026470: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x80026474: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80026478: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002647C: lh          $t7, -0x25C6($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X25C6);
    // 0x80026480: lh          $t6, -0x25E2($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X25E2);
    // 0x80026484: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x80026488: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8002648C: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80026490: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x80026494: mtc1        $a1, $f26
    ctx->f26.u32l = ctx->r5;
    // 0x80026498: mtc1        $a3, $f28
    ctx->f28.u32l = ctx->r7;
    // 0x8002649C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800264A0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800264A4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800264A8: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800264AC: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800264B0: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800264B4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800264B8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800264BC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800264C0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800264C4: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800264C8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800264CC: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800264D0: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x800264D4: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800264D8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800264DC: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800264E0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800264E4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800264E8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800264EC: beq         $at, $zero, L_80026BF4
    if (ctx->r1 == 0) {
        // 0x800264F0: swc1        $f20, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
            goto L_80026BF4;
    }
    // 0x800264F0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800264F4: sh          $zero, 0x10E($sp)
    MEM_H(0X10E, ctx->r29) = 0;
    // 0x800264F8: lh          $a0, 0x20($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X20);
    // 0x800264FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80026500: blez        $a0, L_80026BF4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80026504: addiu       $fp, $sp, 0xB8
        ctx->r30 = ADD32(ctx->r29, 0XB8);
            goto L_80026BF4;
    }
    // 0x80026504: addiu       $fp, $sp, 0xB8
    ctx->r30 = ADD32(ctx->r29, 0XB8);
    // 0x80026508: lwc1        $f31, 0x6408($at)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r1, 0X6408);
    // 0x8002650C: lwc1        $f30, 0x640C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X640C);
    // 0x80026510: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x80026514: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80026518: addiu       $s5, $sp, 0xD0
    ctx->r21 = ADD32(ctx->r29, 0XD0);
    // 0x8002651C: addiu       $s4, $sp, 0xDC
    ctx->r20 = ADD32(ctx->r29, 0XDC);
    // 0x80026520: addiu       $s3, $sp, 0xE8
    ctx->r19 = ADD32(ctx->r29, 0XE8);
    // 0x80026524: addiu       $s2, $sp, 0xF8
    ctx->r18 = ADD32(ctx->r29, 0XF8);
    // 0x80026528: addiu       $s1, $sp, 0xC4
    ctx->r17 = ADD32(ctx->r29, 0XC4);
    // 0x8002652C: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80026530: addiu       $t5, $sp, 0xA8
    ctx->r13 = ADD32(ctx->r29, 0XA8);
    // 0x80026534: addiu       $t4, $sp, 0xA0
    ctx->r12 = ADD32(ctx->r29, 0XA0);
    // 0x80026538: addiu       $t3, $sp, 0xB0
    ctx->r11 = ADD32(ctx->r29, 0XB0);
    // 0x8002653C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_80026540:
    // 0x80026540: lh          $t9, 0x10E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X10E);
    // 0x80026544: lw          $t8, 0xC($s6)
    ctx->r24 = MEM_W(ctx->r22, 0XC);
    // 0x80026548: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8002654C: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80026550: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80026554: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x80026558: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x8002655C: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80026560: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80026564: sh          $t7, 0x108($sp)
    MEM_H(0X108, ctx->r29) = ctx->r15;
    // 0x80026568: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8002656C: lh          $t7, 0x108($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X108);
    // 0x80026570: andi        $t8, $t9, 0x300
    ctx->r24 = ctx->r25 & 0X300;
    // 0x80026574: beq         $t8, $zero, L_80026588
    if (ctx->r24 == 0) {
        // 0x80026578: sll         $s7, $v1, 16
        ctx->r23 = S32(ctx->r3 << 16);
            goto L_80026588;
    }
    // 0x80026578: sll         $s7, $v1, 16
    ctx->r23 = S32(ctx->r3 << 16);
    // 0x8002657C: lh          $v1, 0x108($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X108);
    // 0x80026580: nop

    // 0x80026584: sll         $s7, $v1, 16
    ctx->r23 = S32(ctx->r3 << 16);
L_80026588:
    // 0x80026588: sra         $t6, $s7, 16
    ctx->r14 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8002658C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80026590: beq         $at, $zero, L_80026BD4
    if (ctx->r1 == 0) {
        // 0x80026594: or          $s7, $t6, $zero
        ctx->r23 = ctx->r14 | 0;
            goto L_80026BD4;
    }
    // 0x80026594: or          $s7, $t6, $zero
    ctx->r23 = ctx->r14 | 0;
L_80026598:
    // 0x80026598: lw          $t9, 0x4($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X4);
    // 0x8002659C: sll         $t8, $s7, 4
    ctx->r24 = S32(ctx->r23 << 4);
    // 0x800265A0: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800265A4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800265A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800265AC: andi        $t9, $t7, 0x40
    ctx->r25 = ctx->r15 & 0X40;
    // 0x800265B0: bne         $t9, $zero, L_80026BB0
    if (ctx->r25 != 0) {
        // 0x800265B4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80026BB0;
    }
    // 0x800265B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800265B8:
    // 0x800265B8: lw          $t8, 0x4($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X4);
    // 0x800265BC: sll         $t6, $s7, 4
    ctx->r14 = S32(ctx->r23 << 4);
    // 0x800265C0: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800265C4: addu        $t9, $t7, $a3
    ctx->r25 = ADD32(ctx->r15, ctx->r7);
    // 0x800265C8: lbu         $t8, 0x1($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X1);
    // 0x800265CC: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x800265D0: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800265D4: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800265D8: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800265DC: addu        $a0, $s3, $v0
    ctx->r4 = ADD32(ctx->r19, ctx->r2);
    // 0x800265E0: addu        $a1, $s5, $v0
    ctx->r5 = ADD32(ctx->r21, ctx->r2);
    // 0x800265E4: addu        $a2, $s2, $a3
    ctx->r6 = ADD32(ctx->r18, ctx->r7);
    // 0x800265E8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800265EC: mflo        $t7
    ctx->r15 = lo;
    // 0x800265F0: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800265F4: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800265F8: addu        $t7, $s4, $v0
    ctx->r15 = ADD32(ctx->r20, ctx->r2);
    // 0x800265FC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80026600: addu        $t8, $s1, $v0
    ctx->r24 = ADD32(ctx->r17, ctx->r2);
    // 0x80026604: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026608: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8002660C: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x80026610: nop

    // 0x80026614: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80026618: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8002661C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026620: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x80026624: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80026628: nop

    // 0x8002662C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80026630: nop

    // 0x80026634: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026638: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002663C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80026640: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80026644: nop

    // 0x80026648: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x8002664C: nop

    // 0x80026650: mul.s       $f6, $f26, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x80026654: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80026658: add.s       $f0, $f8, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x8002665C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80026660: c.le.d      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.d <= ctx->f20.d;
    // 0x80026664: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x80026668: bc1f        L_80026674
    if (!c1cs) {
        // 0x8002666C: nop
    
            goto L_80026674;
    }
    // 0x8002666C: nop

    // 0x80026670: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80026674:
    // 0x80026674: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80026678: lb          $t7, 0x0($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X0);
    // 0x8002667C: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x80026680: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80026684: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80026688: cvt.d.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.d = CVT_D_W(ctx->f10.u32l);
    // 0x8002668C: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80026690: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x80026694: c.le.d      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.d <= ctx->f20.d;
    // 0x80026698: nop

    // 0x8002669C: bc1f        L_800266A8
    if (!c1cs) {
        // 0x800266A0: nop
    
            goto L_800266A8;
    }
    // 0x800266A0: nop

    // 0x800266A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800266A8:
    // 0x800266A8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800266AC: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x800266B0: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800266B4: bne         $at, $zero, L_800265B8
    if (ctx->r1 != 0) {
        // 0x800266B8: or          $t0, $t6, $zero
        ctx->r8 = ctx->r14 | 0;
            goto L_800265B8;
    }
    // 0x800266B8: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x800266BC: beq         $t6, $ra, L_800266C8
    if (ctx->r14 == ctx->r31) {
        // 0x800266C0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800266C8;
    }
    // 0x800266C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800266C4: bne         $t6, $at, L_80026BB0
    if (ctx->r14 != ctx->r1) {
        // 0x800266C8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80026BB0;
    }
L_800266C8:
    // 0x800266C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800266CC: lwc1        $f8, -0x25DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X25DC);
    // 0x800266D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800266D4: lwc1        $f4, -0x25E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X25E0);
    // 0x800266D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800266DC: lwc1        $f22, -0x25D8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X25D8);
    // 0x800266E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800266E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800266E8: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x800266EC: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
L_800266F0:
    // 0x800266F0: addiu       $a2, $a3, 0x1
    ctx->r6 = ADD32(ctx->r7, 0X1);
    // 0x800266F4: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800266F8: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x800266FC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80026700: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80026704: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80026708: bne         $at, $zero, L_80026714
    if (ctx->r1 != 0) {
        // 0x8002670C: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_80026714;
    }
    // 0x8002670C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80026710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80026714:
    // 0x80026714: addu        $t9, $s2, $a1
    ctx->r25 = ADD32(ctx->r18, ctx->r5);
    // 0x80026718: addu        $t6, $s2, $a3
    ctx->r14 = ADD32(ctx->r18, ctx->r7);
    // 0x8002671C: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x80026720: lb          $t8, 0x0($t9)
    ctx->r24 = MEM_B(ctx->r25, 0X0);
    // 0x80026724: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80026728: beq         $t8, $t7, L_800267CC
    if (ctx->r24 == ctx->r15) {
        // 0x8002672C: addu        $t6, $s1, $v0
        ctx->r14 = ADD32(ctx->r17, ctx->r2);
            goto L_800267CC;
    }
    // 0x8002672C: addu        $t6, $s1, $v0
    ctx->r14 = ADD32(ctx->r17, ctx->r2);
    // 0x80026730: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80026734: addu        $t8, $s1, $v1
    ctx->r24 = ADD32(ctx->r17, ctx->r3);
    // 0x80026738: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8002673C: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80026740: addu        $t9, $s3, $v1
    ctx->r25 = ADD32(ctx->r19, ctx->r3);
    // 0x80026744: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80026748: addu        $t7, $s3, $v0
    ctx->r15 = ADD32(ctx->r19, ctx->r2);
    // 0x8002674C: div.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80026750: lwc1        $f2, 0x0($t7)
    ctx->f2.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80026754: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80026758: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x8002675C: sub.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80026760: addu        $t6, $t3, $a0
    ctx->r14 = ADD32(ctx->r11, ctx->r4);
    // 0x80026764: addu        $t7, $s4, $v1
    ctx->r15 = ADD32(ctx->r20, ctx->r3);
    // 0x80026768: addu        $t8, $s4, $v0
    ctx->r24 = ADD32(ctx->r20, ctx->r2);
    // 0x8002676C: addu        $t9, $fp, $a0
    ctx->r25 = ADD32(ctx->r30, ctx->r4);
    // 0x80026770: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80026774: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80026778: add.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8002677C: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80026780: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80026784: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80026788: addu        $t6, $t4, $a0
    ctx->r14 = ADD32(ctx->r12, ctx->r4);
    // 0x8002678C: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80026790: addu        $t8, $s5, $v0
    ctx->r24 = ADD32(ctx->r21, ctx->r2);
    // 0x80026794: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80026798: addu        $t7, $s5, $v1
    ctx->r15 = ADD32(ctx->r21, ctx->r3);
    // 0x8002679C: add.s       $f14, $f10, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800267A0: swc1        $f14, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f14.u32l;
    // 0x800267A4: swc1        $f14, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f14.u32l;
    // 0x800267A8: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800267AC: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800267B0: addu        $t9, $t5, $a0
    ctx->r25 = ADD32(ctx->r13, ctx->r4);
    // 0x800267B4: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800267B8: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x800267BC: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800267C0: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800267C4: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800267C8: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
L_800267CC:
    // 0x800267CC: sll         $a3, $a2, 16
    ctx->r7 = S32(ctx->r6 << 16);
    // 0x800267D0: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800267D4: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x800267D8: bne         $at, $zero, L_800266F0
    if (ctx->r1 != 0) {
        // 0x800267DC: or          $a3, $t7, $zero
        ctx->r7 = ctx->r15 | 0;
            goto L_800266F0;
    }
    // 0x800267DC: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800267E0: lwc1        $f14, 0x98($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800267E4: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800267E8: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800267EC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800267F0: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800267F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800267F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800267FC: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80026800: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80026804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026808: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002680C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80026810: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80026814: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80026818: add.s       $f2, $f6, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x8002681C: lwc1        $f9, 0x6410($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6410);
    // 0x80026820: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
    // 0x80026824: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80026828: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002682C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80026830: lwc1        $f8, 0x6414($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6414);
    // 0x80026834: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80026838: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8002683C: add.s       $f12, $f4, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80026840: bc1f        L_80026854
    if (!c1cs) {
        // 0x80026844: swc1        $f12, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->f12.u32l;
            goto L_80026854;
    }
    // 0x80026844: swc1        $f12, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f12.u32l;
    // 0x80026848: sll         $v0, $ra, 24
    ctx->r2 = S32(ctx->r31 << 24);
    // 0x8002684C: sra         $t9, $v0, 24
    ctx->r25 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80026850: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80026854:
    // 0x80026854: c.lt.d      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.d < ctx->f0.d;
    // 0x80026858: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8002685C: bc1f        L_80026870
    if (!c1cs) {
        // 0x80026860: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80026870;
    }
    // 0x80026860: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80026864: ori         $t6, $v0, 0x2
    ctx->r14 = ctx->r2 | 0X2;
    // 0x80026868: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x8002686C: sra         $v0, $t8, 24
    ctx->r2 = S32(SIGNED(ctx->r24) >> 24);
L_80026870:
    // 0x80026870: lwc1        $f5, 0x6418($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6418);
    // 0x80026874: lwc1        $f4, 0x641C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X641C);
    // 0x80026878: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8002687C: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80026880: nop

    // 0x80026884: bc1f        L_80026898
    if (!c1cs) {
        // 0x80026888: nop
    
            goto L_80026898;
    }
    // 0x80026888: nop

    // 0x8002688C: sll         $v1, $ra, 24
    ctx->r3 = S32(ctx->r31 << 24);
    // 0x80026890: sra         $t9, $v1, 24
    ctx->r25 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80026894: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_80026898:
    // 0x80026898: c.lt.d      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.d < ctx->f0.d;
    // 0x8002689C: ori         $t6, $v1, 0x2
    ctx->r14 = ctx->r3 | 0X2;
    // 0x800268A0: bc1f        L_800268AC
    if (!c1cs) {
        // 0x800268A4: sll         $t8, $t6, 24
        ctx->r24 = S32(ctx->r14 << 24);
            goto L_800268AC;
    }
    // 0x800268A4: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x800268A8: sra         $v1, $t8, 24
    ctx->r3 = S32(SIGNED(ctx->r24) >> 24);
L_800268AC:
    // 0x800268AC: or          $t9, $v1, $v0
    ctx->r25 = ctx->r3 | ctx->r2;
    // 0x800268B0: bne         $t9, $zero, L_800268D0
    if (ctx->r25 != 0) {
        // 0x800268B4: nop
    
            goto L_800268D0;
    }
    // 0x800268B4: nop

    // 0x800268B8: sll         $s0, $ra, 16
    ctx->r16 = S32(ctx->r31 << 16);
    // 0x800268BC: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800268C0: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800268C4: sb          $v1, 0xF9($sp)
    MEM_B(0XF9, ctx->r29) = ctx->r3;
    // 0x800268C8: b           L_80026A0C
    // 0x800268CC: sb          $v0, 0xF8($sp)
    MEM_B(0XF8, ctx->r29) = ctx->r2;
        goto L_80026A0C;
    // 0x800268CC: sb          $v0, 0xF8($sp)
    MEM_B(0XF8, ctx->r29) = ctx->r2;
L_800268D0:
    // 0x800268D0: sb          $v0, 0xF8($sp)
    MEM_B(0XF8, ctx->r29) = ctx->r2;
    // 0x800268D4: beq         $v1, $v0, L_80026A0C
    if (ctx->r3 == ctx->r2) {
        // 0x800268D8: sb          $v1, 0xF9($sp)
        MEM_B(0XF9, ctx->r29) = ctx->r3;
            goto L_80026A0C;
    }
    // 0x800268D8: sb          $v1, 0xF9($sp)
    MEM_B(0XF9, ctx->r29) = ctx->r3;
    // 0x800268DC: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800268E0: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800268E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800268E8: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800268EC: sll         $s0, $ra, 16
    ctx->r16 = S32(ctx->r31 << 16);
    // 0x800268F0: bc1f        L_80026908
    if (!c1cs) {
        // 0x800268F4: addu        $t9, $s2, $a3
        ctx->r25 = ADD32(ctx->r18, ctx->r7);
            goto L_80026908;
    }
    // 0x800268F4: addu        $t9, $s2, $a3
    ctx->r25 = ADD32(ctx->r18, ctx->r7);
    // 0x800268F8: sll         $a3, $ra, 16
    ctx->r7 = S32(ctx->r31 << 16);
    // 0x800268FC: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80026900: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80026904: addu        $t9, $s2, $a3
    ctx->r25 = ADD32(ctx->r18, ctx->r7);
L_80026908:
    // 0x80026908: lb          $t6, 0x0($t9)
    ctx->r14 = MEM_B(ctx->r25, 0X0);
    // 0x8002690C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80026910: bne         $ra, $t6, L_80026988
    if (ctx->r31 != ctx->r14) {
        // 0x80026914: subu        $a2, $ra, $a3
        ctx->r6 = SUB32(ctx->r31, ctx->r7);
            goto L_80026988;
    }
    // 0x80026914: subu        $a2, $ra, $a3
    ctx->r6 = SUB32(ctx->r31, ctx->r7);
    // 0x80026918: subu        $a1, $ra, $a3
    ctx->r5 = SUB32(ctx->r31, ctx->r7);
    // 0x8002691C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80026920: addu        $v1, $s1, $v0
    ctx->r3 = ADD32(ctx->r17, ctx->r2);
    // 0x80026924: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80026928: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002692C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80026930: addu        $t6, $s1, $t9
    ctx->r14 = ADD32(ctx->r17, ctx->r25);
    // 0x80026934: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80026938: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8002693C: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80026940: sub.d       $f10, $f4, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f30.d); 
    ctx->f10.d = ctx->f4.d - ctx->f30.d;
    // 0x80026944: addu        $t8, $fp, $t9
    ctx->r24 = ADD32(ctx->r30, ctx->r25);
    // 0x80026948: sub.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8002694C: addu        $a0, $fp, $v0
    ctx->r4 = ADD32(ctx->r30, ctx->r2);
    // 0x80026950: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80026954: nop

    // 0x80026958: div.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x8002695C: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80026960: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80026964: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80026968: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8002696C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80026970: nop

    // 0x80026974: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80026978: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8002697C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80026980: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80026984: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
L_80026988:
    // 0x80026988: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8002698C: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80026990: addu        $t6, $s2, $t9
    ctx->r14 = ADD32(ctx->r18, ctx->r25);
    // 0x80026994: lb          $t8, 0x0($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X0);
    // 0x80026998: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002699C: bne         $t8, $at, L_80026A08
    if (ctx->r24 != ctx->r1) {
        // 0x800269A0: sra         $t6, $s0, 16
        ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
            goto L_80026A08;
    }
    // 0x800269A0: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800269A4: sll         $a1, $t9, 2
    ctx->r5 = S32(ctx->r25 << 2);
    // 0x800269A8: addu        $v1, $s1, $a1
    ctx->r3 = ADD32(ctx->r17, ctx->r5);
    // 0x800269AC: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800269B0: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800269B4: addu        $t7, $s1, $v0
    ctx->r15 = ADD32(ctx->r17, ctx->r2);
    // 0x800269B8: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800269BC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800269C0: sub.d       $f4, $f10, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f30.d); 
    ctx->f4.d = ctx->f10.d - ctx->f30.d;
    // 0x800269C4: addu        $t9, $fp, $v0
    ctx->r25 = ADD32(ctx->r30, ctx->r2);
    // 0x800269C8: sub.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800269CC: addu        $a0, $fp, $a1
    ctx->r4 = ADD32(ctx->r30, ctx->r5);
    // 0x800269D0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800269D4: nop

    // 0x800269D8: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800269DC: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800269E0: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800269E4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800269E8: sub.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800269EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800269F0: nop

    // 0x800269F4: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800269F8: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800269FC: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80026A00: add.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80026A04: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
L_80026A08:
    // 0x80026A08: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_80026A0C:
    // 0x80026A0C: beq         $s0, $zero, L_80026BB0
    if (ctx->r16 == 0) {
        // 0x80026A10: sll         $t7, $s7, 3
        ctx->r15 = S32(ctx->r23 << 3);
            goto L_80026BB0;
    }
    // 0x80026A10: sll         $t7, $s7, 3
    ctx->r15 = S32(ctx->r23 << 3);
    // 0x80026A14: lw          $t8, 0x14($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X14);
    // 0x80026A18: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80026A1C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80026A20: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x80026A24: lw          $t9, 0x18($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X18);
    // 0x80026A28: sll         $t8, $t6, 18
    ctx->r24 = S32(ctx->r14 << 18);
    // 0x80026A2C: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026A30: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80026A34: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80026A38: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x80026A3C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80026A40: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80026A44: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80026A48: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80026A4C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80026A50: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80026A54: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80026A58: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80026A5C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80026A60: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80026A64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80026A68: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80026A6C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80026A70: nop

    // 0x80026A74: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80026A78: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026A7C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80026A80: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80026A84: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80026A88: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80026A8C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80026A90: c.lt.d      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.d < ctx->f4.d;
    // 0x80026A94: nop

    // 0x80026A98: bc1f        L_80026AA8
    if (!c1cs) {
        // 0x80026A9C: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_80026AA8;
    }
    // 0x80026A9C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80026AA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80026AA4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_80026AA8:
    // 0x80026AA8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80026AAC: sll         $s0, $t8, 16
    ctx->r16 = S32(ctx->r24 << 16);
    // 0x80026AB0: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80026AB4: bc1f        L_80026ACC
    if (!c1cs) {
        // 0x80026AB8: or          $s0, $t7, $zero
        ctx->r16 = ctx->r15 | 0;
            goto L_80026ACC;
    }
    // 0x80026AB8: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80026ABC: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x80026AC0: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x80026AC4: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80026AC8: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
L_80026ACC:
    // 0x80026ACC: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80026AD0: ori         $t9, $s0, 0x8
    ctx->r25 = ctx->r16 | 0X8;
    // 0x80026AD4: bc1f        L_80026AE0
    if (!c1cs) {
        // 0x80026AD8: sll         $t6, $t9, 16
        ctx->r14 = S32(ctx->r25 << 16);
            goto L_80026AE0;
    }
    // 0x80026AD8: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80026ADC: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
L_80026AE0:
    // 0x80026AE0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80026AE4: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80026AE8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80026AEC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026AF0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026AF4: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80026AF8: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80026AFC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80026B00: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80026B04: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80026B08: sh          $t1, 0x10A($sp)
    MEM_H(0X10A, ctx->r29) = ctx->r9;
    // 0x80026B0C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80026B10: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80026B14: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80026B18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026B1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026B20: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80026B24: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80026B28: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80026B2C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80026B30: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80026B34: jal         0x80026C54
    // 0x80026B38: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    func_80026C14(rdram, ctx);
        goto after_0;
    // 0x80026B38: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    after_0:
    // 0x80026B3C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80026B40: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80026B44: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80026B48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026B4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026B50: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80026B54: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80026B58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80026B5C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80026B60: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80026B64: nop

    // 0x80026B68: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80026B6C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80026B70: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80026B74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026B78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026B7C: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026B80: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80026B84: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80026B88: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80026B8C: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80026B90: jal         0x80026C54
    // 0x80026B94: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_80026C14(rdram, ctx);
        goto after_1;
    // 0x80026B94: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_1:
    // 0x80026B98: lh          $t1, 0x10A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X10A);
    // 0x80026B9C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80026BA0: addiu       $t3, $sp, 0xB0
    ctx->r11 = ADD32(ctx->r29, 0XB0);
    // 0x80026BA4: addiu       $t4, $sp, 0xA0
    ctx->r12 = ADD32(ctx->r29, 0XA0);
    // 0x80026BA8: addiu       $t5, $sp, 0xA8
    ctx->r13 = ADD32(ctx->r29, 0XA8);
    // 0x80026BAC: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
L_80026BB0:
    // 0x80026BB0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80026BB4: lh          $t6, 0x108($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X108);
    // 0x80026BB8: sll         $t7, $s7, 16
    ctx->r15 = S32(ctx->r23 << 16);
    // 0x80026BBC: sra         $s7, $t7, 16
    ctx->r23 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80026BC0: slt         $at, $s7, $t6
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80026BC4: bne         $at, $zero, L_80026598
    if (ctx->r1 != 0) {
        // 0x80026BC8: nop
    
            goto L_80026598;
    }
    // 0x80026BC8: nop

    // 0x80026BCC: lh          $a0, 0x20($s6)
    ctx->r4 = MEM_H(ctx->r22, 0X20);
    // 0x80026BD0: nop

L_80026BD4:
    // 0x80026BD4: lh          $v0, 0x10E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X10E);
    // 0x80026BD8: nop

    // 0x80026BDC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80026BE0: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80026BE4: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026BE8: slt         $at, $t7, $a0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80026BEC: bne         $at, $zero, L_80026540
    if (ctx->r1 != 0) {
        // 0x80026BF0: sh          $t7, 0x10E($sp)
        MEM_H(0X10E, ctx->r29) = ctx->r15;
            goto L_80026540;
    }
    // 0x80026BF0: sh          $t7, 0x10E($sp)
    MEM_H(0X10E, ctx->r29) = ctx->r15;
L_80026BF4:
    // 0x80026BF4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80026BF8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80026BFC: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80026C00: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80026C04: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80026C08: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80026C0C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80026C10: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80026C14: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80026C18: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80026C1C: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80026C20: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80026C24: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80026C28: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80026C2C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80026C30: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80026C34: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80026C38: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80026C3C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80026C40: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80026C44: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80026C48: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80026C4C: jr          $ra
    // 0x80026C50: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x80026C50: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void func_80026C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026C54: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80026C58: addiu       $t0, $t0, -0x25E2
    ctx->r8 = ADD32(ctx->r8, -0X25E2);
    // 0x80026C5C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80026C60: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80026C64: lh          $t8, -0x25C6($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X25C6);
    // 0x80026C68: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x80026C6C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80026C70: sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5 << 16);
    // 0x80026C74: sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4 << 16);
    // 0x80026C78: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80026C7C: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80026C80: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80026C84: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80026C88: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80026C8C: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80026C90: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x80026C94: beq         $at, $zero, L_80026E88
    if (ctx->r1 == 0) {
        // 0x80026C98: sw          $a2, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r6;
            goto L_80026E88;
    }
    // 0x80026C98: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x80026C9C: blez        $v0, L_80026CFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80026CA0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80026CFC;
    }
    // 0x80026CA0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80026CA4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80026CA8: addiu       $t1, $t1, -0x2608
    ctx->r9 = ADD32(ctx->r9, -0X2608);
    // 0x80026CAC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80026CB0: nop

    // 0x80026CB4: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x80026CB8: nop

    // 0x80026CBC: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80026CC0: beq         $at, $zero, L_80026CFC
    if (ctx->r1 == 0) {
        // 0x80026CC4: nop
    
            goto L_80026CFC;
    }
    // 0x80026CC4: nop

L_80026CC8:
    // 0x80026CC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026CCC: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x80026CD0: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80026CD4: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80026CD8: beq         $at, $zero, L_80026CFC
    if (ctx->r1 == 0) {
        // 0x80026CDC: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80026CFC;
    }
    // 0x80026CDC: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80026CE0: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80026CE4: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80026CE8: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80026CEC: nop

    // 0x80026CF0: slt         $at, $t6, $a3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80026CF4: bne         $at, $zero, L_80026CC8
    if (ctx->r1 != 0) {
        // 0x80026CF8: nop
    
            goto L_80026CC8;
    }
    // 0x80026CF8: nop

L_80026CFC:
    // 0x80026CFC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80026D00: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80026D04: beq         $at, $zero, L_80026D80
    if (ctx->r1 == 0) {
        // 0x80026D08: addiu       $t1, $t1, -0x2608
        ctx->r9 = ADD32(ctx->r9, -0X2608);
            goto L_80026D80;
    }
    // 0x80026D08: addiu       $t1, $t1, -0x2608
    ctx->r9 = ADD32(ctx->r9, -0X2608);
    // 0x80026D0C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80026D10: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x80026D14: addu        $a1, $a0, $t7
    ctx->r5 = ADD32(ctx->r4, ctx->r15);
    // 0x80026D18: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x80026D1C: nop

    // 0x80026D20: bne         $a3, $t8, L_80026D80
    if (ctx->r7 != ctx->r24) {
        // 0x80026D24: nop
    
            goto L_80026D80;
    }
    // 0x80026D24: nop

    // 0x80026D28: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x80026D2C: nop

    // 0x80026D30: slt         $at, $t9, $s0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80026D34: beq         $at, $zero, L_80026D84
    if (ctx->r1 == 0) {
        // 0x80026D38: sll         $a1, $v0, 16
        ctx->r5 = S32(ctx->r2 << 16);
            goto L_80026D84;
    }
    // 0x80026D38: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
L_80026D3C:
    // 0x80026D3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026D40: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x80026D44: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80026D48: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80026D4C: beq         $at, $zero, L_80026D80
    if (ctx->r1 == 0) {
        // 0x80026D50: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80026D80;
    }
    // 0x80026D50: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80026D54: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80026D58: addu        $a1, $a0, $t4
    ctx->r5 = ADD32(ctx->r4, ctx->r12);
    // 0x80026D5C: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x80026D60: nop

    // 0x80026D64: bne         $a3, $t5, L_80026D80
    if (ctx->r7 != ctx->r13) {
        // 0x80026D68: nop
    
            goto L_80026D80;
    }
    // 0x80026D68: nop

    // 0x80026D6C: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x80026D70: nop

    // 0x80026D74: slt         $at, $t6, $s0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80026D78: bne         $at, $zero, L_80026D3C
    if (ctx->r1 != 0) {
        // 0x80026D7C: nop
    
            goto L_80026D3C;
    }
    // 0x80026D7C: nop

L_80026D80:
    // 0x80026D80: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
L_80026D84:
    // 0x80026D84: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80026D88: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80026D8C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80026D90: beq         $at, $zero, L_80026DF8
    if (ctx->r1 == 0) {
        // 0x80026D94: sll         $a0, $v1, 3
        ctx->r4 = S32(ctx->r3 << 3);
            goto L_80026DF8;
    }
    // 0x80026D94: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
L_80026D98:
    // 0x80026D98: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80026D9C: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80026DA0: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    // 0x80026DA4: lh          $t9, -0x8($a2)
    ctx->r25 = MEM_H(ctx->r6, -0X8);
    // 0x80026DA8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80026DAC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x80026DB0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80026DB4: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80026DB8: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
    // 0x80026DBC: lh          $t3, -0x6($a2)
    ctx->r11 = MEM_H(ctx->r6, -0X6);
    // 0x80026DC0: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026DC4: sh          $t3, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r11;
    // 0x80026DC8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80026DCC: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80026DD0: addu        $a2, $t4, $v0
    ctx->r6 = ADD32(ctx->r12, ctx->r2);
    // 0x80026DD4: lb          $t5, -0x1($a2)
    ctx->r13 = MEM_B(ctx->r6, -0X1);
    // 0x80026DD8: nop

    // 0x80026DDC: sb          $t5, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r13;
    // 0x80026DE0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80026DE4: nop

    // 0x80026DE8: addu        $a2, $t6, $v0
    ctx->r6 = ADD32(ctx->r14, ctx->r2);
    // 0x80026DEC: lb          $t7, -0x2($a2)
    ctx->r15 = MEM_B(ctx->r6, -0X2);
    // 0x80026DF0: bne         $at, $zero, L_80026D98
    if (ctx->r1 != 0) {
        // 0x80026DF4: sb          $t7, 0x6($a2)
        MEM_B(0X6, ctx->r6) = ctx->r15;
            goto L_80026D98;
    }
    // 0x80026DF4: sb          $t7, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r15;
L_80026DF8:
    // 0x80026DF8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80026DFC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80026E00: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x80026E04: sh          $a3, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r7;
    // 0x80026E08: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80026E0C: addiu       $v1, $v1, -0x25E4
    ctx->r3 = ADD32(ctx->r3, -0X25E4);
    // 0x80026E10: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80026E14: sh          $s0, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r16;
    // 0x80026E18: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80026E1C: nop

    // 0x80026E20: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80026E24: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
    // 0x80026E28: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80026E2C: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80026E30: addu        $t2, $t9, $a0
    ctx->r10 = ADD32(ctx->r25, ctx->r4);
    // 0x80026E34: sb          $t8, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r24;
    // 0x80026E38: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80026E3C: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x80026E40: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80026E44: sb          $t3, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r11;
    // 0x80026E48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80026E4C: lw          $t7, -0x2604($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2604);
    // 0x80026E50: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x80026E54: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80026E58: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80026E5C: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x80026E60: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x80026E64: nop

    // 0x80026E68: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80026E6C: beq         $t2, $zero, L_80026E84
    if (ctx->r10 == 0) {
        // 0x80026E70: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_80026E84;
    }
    // 0x80026E70: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80026E74: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x80026E78: nop

    // 0x80026E7C: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80026E80: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
L_80026E84:
    // 0x80026E84: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
L_80026E88:
    // 0x80026E88: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80026E8C: jr          $ra
    // 0x80026E90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80026E90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80026E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026E94: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x80026E98: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80026E9C: sll         $s5, $a0, 16
    ctx->r21 = S32(ctx->r4 << 16);
    // 0x80026EA0: sra         $t6, $s5, 16
    ctx->r14 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80026EA4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80026EA8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80026EAC: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80026EB0: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80026EB4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80026EB8: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x80026EBC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80026EC0: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
    // 0x80026EC4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80026EC8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80026ECC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80026ED0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80026ED4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80026ED8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80026EDC: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80026EE0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80026EE4: beq         $at, $zero, L_8002718C
    if (ctx->r1 == 0) {
        // 0x80026EE8: sw          $a0, 0x108($sp)
        MEM_W(0X108, ctx->r29) = ctx->r4;
            goto L_8002718C;
    }
    // 0x80026EE8: sw          $a0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r4;
    // 0x80026EEC: beq         $t6, $zero, L_8002718C
    if (ctx->r14 == 0) {
        // 0x80026EF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002718C;
    }
    // 0x80026EF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026EF4: blez        $t6, L_8002702C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80026EF8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8002702C;
    }
    // 0x80026EF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80026EFC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80026F00: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80026F04: lw          $a3, -0x2608($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2608);
    // 0x80026F08: lw          $t0, -0x2604($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2604);
    // 0x80026F0C: addiu       $s4, $sp, 0x94
    ctx->r20 = ADD32(ctx->r29, 0X94);
    // 0x80026F10: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // 0x80026F14: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
L_80026F18:
    // 0x80026F18: addu        $t7, $s0, $s3
    ctx->r15 = ADD32(ctx->r16, ctx->r19);
    // 0x80026F1C: lb          $t8, 0x0($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X0);
    // 0x80026F20: nop

    // 0x80026F24: sll         $t9, $t8, 17
    ctx->r25 = S32(ctx->r24 << 17);
    // 0x80026F28: sra         $t2, $t9, 16
    ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80026F2C: addu        $a0, $t2, $t0
    ctx->r4 = ADD32(ctx->r10, ctx->r8);
    // 0x80026F30: lb          $t3, 0x0($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X0);
    // 0x80026F34: lb          $t5, 0x1($a0)
    ctx->r13 = MEM_B(ctx->r4, 0X1);
    // 0x80026F38: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80026F3C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80026F40: addu        $v1, $t4, $a3
    ctx->r3 = ADD32(ctx->r12, ctx->r7);
    // 0x80026F44: addu        $a2, $t6, $a3
    ctx->r6 = ADD32(ctx->r14, ctx->r7);
    // 0x80026F48: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80026F4C: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x80026F50: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80026F54: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80026F58: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026F5C: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80026F60: lh          $t2, 0x2($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X2);
    // 0x80026F64: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026F68: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80026F6C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80026F70: c.eq.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl == ctx->f14.fl;
    // 0x80026F74: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80026F78: bc1t        L_8002718C
    if (c1cs) {
        // 0x80026F7C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8002718C;
    }
    // 0x80026F7C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80026F80: sub.s       $f0, $f2, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80026F84: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80026F88: sub.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x80026F8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80026F90: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80026F94: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80026F98: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x80026F9C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80026FA0: addu        $t4, $s4, $t3
    ctx->r12 = ADD32(ctx->r20, ctx->r11);
    // 0x80026FA4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80026FA8: addu        $v1, $s4, $t8
    ctx->r3 = ADD32(ctx->r20, ctx->r24);
    // 0x80026FAC: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80026FB0: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x80026FB4: addu        $t9, $s2, $s0
    ctx->r25 = ADD32(ctx->r18, ctx->r16);
    // 0x80026FB8: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80026FBC: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x80026FC0: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80026FC4: sub.s       $f6, $f22, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f14.fl;
    // 0x80026FC8: sra         $v0, $t2, 16
    ctx->r2 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80026FCC: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80026FD0: nop

    // 0x80026FD4: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80026FD8: sub.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80026FDC: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x80026FE0: lwc1        $f4, -0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80026FE4: sb          $s0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r16;
    // 0x80026FE8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80026FEC: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80026FF0: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x80026FF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80026FF8: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x80026FFC: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80027000: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80027004: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80027008: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8002700C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80027010: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80027014: lwc1        $f18, -0x4($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, -0X4);
    // 0x80027018: nop

    // 0x8002701C: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80027020: bne         $at, $zero, L_80026F18
    if (ctx->r1 != 0) {
        // 0x80027024: swc1        $f8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
            goto L_80026F18;
    }
    // 0x80027024: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80027028: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002702C:
    // 0x8002702C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80027030: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // 0x80027034: addiu       $s4, $sp, 0x94
    ctx->r20 = ADD32(ctx->r29, 0X94);
    // 0x80027038: addiu       $s1, $s5, -0x1
    ctx->r17 = ADD32(ctx->r21, -0X1);
L_8002703C:
    // 0x8002703C: blez        $s1, L_800270BC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80027040: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800270BC;
    }
    // 0x80027040: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80027044: addu        $v1, $s2, $s0
    ctx->r3 = ADD32(ctx->r18, ctx->r16);
L_80027048:
    // 0x80027048: lb          $t8, 0x1($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X1);
    // 0x8002704C: lb          $t3, 0x0($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X0);
    // 0x80027050: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80027054: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80027058: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x8002705C: addu        $t2, $a1, $t9
    ctx->r10 = ADD32(ctx->r5, ctx->r25);
    // 0x80027060: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80027064: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80027068: addu        $a0, $s0, $s3
    ctx->r4 = ADD32(ctx->r16, ctx->r19);
    // 0x8002706C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80027070: nop

    // 0x80027074: bc1f        L_800270A0
    if (!c1cs) {
        // 0x80027078: nop
    
            goto L_800270A0;
    }
    // 0x80027078: nop

    // 0x8002707C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80027080: lb          $t6, 0x1($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1);
    // 0x80027084: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x80027088: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8002708C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80027090: lb          $t7, 0x1($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1);
    // 0x80027094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80027098: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8002709C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_800270A0:
    // 0x800270A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800270A4: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x800270A8: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800270AC: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800270B0: bne         $at, $zero, L_80027048
    if (ctx->r1 != 0) {
        // 0x800270B4: addu        $v1, $s2, $s0
        ctx->r3 = ADD32(ctx->r18, ctx->r16);
            goto L_80027048;
    }
    // 0x800270B4: addu        $v1, $s2, $s0
    ctx->r3 = ADD32(ctx->r18, ctx->r16);
    // 0x800270B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800270BC:
    // 0x800270BC: beq         $a2, $zero, L_8002703C
    if (ctx->r6 == 0) {
        // 0x800270C0: nop
    
            goto L_8002703C;
    }
    // 0x800270C0: nop

    // 0x800270C4: blez        $s1, L_8002718C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800270C8: lui         $s6, 0x8012
        ctx->r22 = S32(0X8012 << 16);
            goto L_8002718C;
    }
    // 0x800270C8: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800270CC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800270D0: addiu       $s5, $s5, -0x2608
    ctx->r21 = ADD32(ctx->r21, -0X2608);
    // 0x800270D4: addiu       $s6, $s6, -0x2604
    ctx->r22 = ADD32(ctx->r22, -0X2604);
    // 0x800270D8: addu        $a0, $s0, $s3
    ctx->r4 = ADD32(ctx->r16, ctx->r19);
L_800270DC:
    // 0x800270DC: lb          $t2, 0x0($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X0);
    // 0x800270E0: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x800270E4: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800270E8: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x800270EC: lb          $t5, 0x0($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X0);
    // 0x800270F0: lw          $a3, 0x0($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X0);
    // 0x800270F4: lb          $t3, 0x1($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X1);
    // 0x800270F8: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800270FC: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80027100: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80027104: lb          $v0, 0x6($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X6);
    // 0x80027108: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x8002710C: lb          $t6, 0x0($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X0);
    // 0x80027110: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80027114: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80027118: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8002711C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80027120: lb          $v1, 0x6($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X6);
    // 0x80027124: sra         $v0, $t9, 24
    ctx->r2 = S32(SIGNED(ctx->r25) >> 24);
    // 0x80027128: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x8002712C: sll         $t2, $t9, 24
    ctx->r10 = S32(ctx->r25 << 24);
    // 0x80027130: beq         $v0, $zero, L_80027174
    if (ctx->r2 == 0) {
        // 0x80027134: sra         $t3, $t2, 24
        ctx->r11 = S32(SIGNED(ctx->r10) >> 24);
            goto L_80027174;
    }
    // 0x80027134: sra         $t3, $t2, 24
    ctx->r11 = S32(SIGNED(ctx->r10) >> 24);
    // 0x80027138: bne         $t3, $zero, L_80027174
    if (ctx->r11 != 0) {
        // 0x8002713C: addu        $v1, $s2, $s0
        ctx->r3 = ADD32(ctx->r18, ctx->r16);
            goto L_80027174;
    }
    // 0x8002713C: addu        $v1, $s2, $s0
    ctx->r3 = ADD32(ctx->r18, ctx->r16);
    // 0x80027140: lb          $t4, 0x0($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X0);
    // 0x80027144: lb          $t7, 0x1($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1);
    // 0x80027148: sll         $t5, $t4, 17
    ctx->r13 = S32(ctx->r12 << 17);
    // 0x8002714C: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x80027150: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80027154: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80027158: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8002715C: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x80027160: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80027164: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80027168: addu        $a0, $s4, $t2
    ctx->r4 = ADD32(ctx->r20, ctx->r10);
    // 0x8002716C: jal         0x800271C4
    // 0x80027170: addu        $a1, $s4, $t3
    ctx->r5 = ADD32(ctx->r20, ctx->r11);
    void_generate_primitive(rdram, ctx);
        goto after_0;
    // 0x80027170: addu        $a1, $s4, $t3
    ctx->r5 = ADD32(ctx->r20, ctx->r11);
    after_0:
L_80027174:
    // 0x80027174: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80027178: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x8002717C: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80027180: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80027184: bne         $at, $zero, L_800270DC
    if (ctx->r1 != 0) {
        // 0x80027188: addu        $a0, $s0, $s3
        ctx->r4 = ADD32(ctx->r16, ctx->r19);
            goto L_800270DC;
    }
    // 0x80027188: addu        $a0, $s0, $s3
    ctx->r4 = ADD32(ctx->r16, ctx->r19);
L_8002718C:
    // 0x8002718C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80027190: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80027194: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80027198: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002719C: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800271A0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800271A4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800271A8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800271AC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800271B0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800271B4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800271B8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800271BC: jr          $ra
    // 0x800271C0: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800271C0: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void void_generate_primitive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800271C4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800271C8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800271CC: addiu       $a2, $a2, -0x25C8
    ctx->r6 = ADD32(ctx->r6, -0X25C8);
    // 0x800271D0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800271D4: lh          $t7, -0x25C4($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X25C4);
    // 0x800271D8: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800271DC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800271E0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800271E4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800271E8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800271EC: bne         $at, $zero, L_800271FC
    if (ctx->r1 != 0) {
        // 0x800271F0: sw          $a3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r7;
            goto L_800271FC;
    }
    // 0x800271F0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800271F4: b           L_80027598
    // 0x800271F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80027598;
    // 0x800271F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800271FC:
    // 0x800271FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80027200: addiu       $v1, $v1, -0x25CA
    ctx->r3 = ADD32(ctx->r3, -0X25CA);
    // 0x80027204: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80027208: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8002720C: bne         $v0, $at, L_800272F8
    if (ctx->r2 != ctx->r1) {
        // 0x80027210: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_800272F8;
    }
    // 0x80027210: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027214: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80027218: addiu       $t5, $t5, -0x49E0
    ctx->r13 = ADD32(ctx->r13, -0X49E0);
    // 0x8002721C: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x80027220: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80027224: addiu       $s0, $s0, -0x25F8
    ctx->r16 = ADD32(ctx->r16, -0X25F8);
    // 0x80027228: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8002722C: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x80027230: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
    // 0x80027234: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x80027238: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8002723C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x80027240: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80027244: andi        $t9, $t8, 0x6
    ctx->r25 = ctx->r24 & 0X6;
    // 0x80027248: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8002724C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80027250: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80027254: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80027258: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002725C: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80027260: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80027264: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x80027268: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002726C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80027270: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80027274: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80027278: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8002727C: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80027280: addu        $t9, $t7, $s1
    ctx->r25 = ADD32(ctx->r15, ctx->r17);
    // 0x80027284: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80027288: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x8002728C: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x80027290: sra         $t6, $t4, 1
    ctx->r14 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80027294: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80027298: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x8002729C: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x800272A0: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800272A4: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x800272A8: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x800272AC: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800272B0: sll         $t9, $t4, 4
    ctx->r25 = S32(ctx->r12 << 4);
    // 0x800272B4: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800272B8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800272BC: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800272C0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800272C4: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800272C8: lw          $t9, -0x25E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X25E8);
    // 0x800272CC: addiu       $a3, $a3, -0x49D8
    ctx->r7 = ADD32(ctx->r7, -0X49D8);
    // 0x800272D0: addu        $t7, $t9, $s1
    ctx->r15 = ADD32(ctx->r25, ctx->r17);
    // 0x800272D4: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x800272D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800272DC: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800272E0: addiu       $t0, $t0, -0x49D4
    ctx->r8 = ADD32(ctx->r8, -0X49D4);
    // 0x800272E4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800272E8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800272EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800272F0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800272F4: sw          $t6, -0x25E8($at)
    MEM_W(-0X25E8, ctx->r1) = ctx->r14;
L_800272F8:
    // 0x800272F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800272FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80027300: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80027304: lwc1        $f0, -0x25E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25E0);
    // 0x80027308: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002730C: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80027310: lwc1        $f2, -0x25D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X25D4);
    // 0x80027314: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027318: addiu       $a3, $a3, -0x49D8
    ctx->r7 = ADD32(ctx->r7, -0X49D8);
    // 0x8002731C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80027320: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80027324: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80027328: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002732C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80027330: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027334: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027338: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002733C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80027340: lwc1        $f14, -0x25DC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X25DC);
    // 0x80027344: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80027348: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002734C: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80027350: lwc1        $f16, -0x25D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X25D0);
    // 0x80027354: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80027358: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002735C: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80027360: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80027364: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80027368: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002736C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80027370: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027374: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027378: lbu         $t5, -0x499F($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X499F);
    // 0x8002737C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80027380: lbu         $s0, -0x499E($s0)
    ctx->r16 = MEM_BU(ctx->r16, -0X499E);
    // 0x80027384: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80027388: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8002738C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80027390: lbu         $s1, -0x499D($s1)
    ctx->r17 = MEM_BU(ctx->r17, -0X499D);
    // 0x80027394: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x80027398: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002739C: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800273A0: addiu       $t0, $t0, -0x49D4
    ctx->r8 = ADD32(ctx->r8, -0X49D4);
    // 0x800273A4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800273A8: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800273AC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800273B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800273B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800273B8: nop

    // 0x800273BC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800273C0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800273C4: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800273C8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800273CC: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800273D0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800273D4: sb          $t8, -0x1F($v0)
    MEM_B(-0X1F, ctx->r2) = ctx->r24;
    // 0x800273D8: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800273DC: sb          $t5, -0x22($v0)
    MEM_B(-0X22, ctx->r2) = ctx->r13;
    // 0x800273E0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800273E4: sb          $s0, -0x21($v0)
    MEM_B(-0X21, ctx->r2) = ctx->r16;
    // 0x800273E8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800273EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800273F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800273F4: sh          $t2, -0x24($v0)
    MEM_H(-0X24, ctx->r2) = ctx->r10;
    // 0x800273F8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800273FC: sb          $s1, -0x20($v0)
    MEM_B(-0X20, ctx->r2) = ctx->r17;
    // 0x80027400: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80027404: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80027408: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8002740C: sh          $t3, -0x1E($v0)
    MEM_H(-0X1E, ctx->r2) = ctx->r11;
    // 0x80027410: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80027414: nop

    // 0x80027418: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002741C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027420: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027424: nop

    // 0x80027428: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002742C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80027430: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80027434: sh          $t7, -0x26($v0)
    MEM_H(-0X26, ctx->r2) = ctx->r15;
    // 0x80027438: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8002743C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80027440: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80027444: sb          $t7, -0x15($v0)
    MEM_B(-0X15, ctx->r2) = ctx->r15;
    // 0x80027448: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002744C: sh          $t1, -0x14($v0)
    MEM_H(-0X14, ctx->r2) = ctx->r9;
    // 0x80027450: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80027454: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027458: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002745C: sb          $t5, -0x18($v0)
    MEM_B(-0X18, ctx->r2) = ctx->r13;
    // 0x80027460: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80027464: sb          $s0, -0x17($v0)
    MEM_B(-0X17, ctx->r2) = ctx->r16;
    // 0x80027468: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8002746C: sb          $s1, -0x16($v0)
    MEM_B(-0X16, ctx->r2) = ctx->r17;
    // 0x80027470: sh          $t4, -0x1A($v0)
    MEM_H(-0X1A, ctx->r2) = ctx->r12;
    // 0x80027474: sh          $t9, -0x1C($v0)
    MEM_H(-0X1C, ctx->r2) = ctx->r25;
    // 0x80027478: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002747C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80027480: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80027484: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80027488: sb          $t9, -0xB($v0)
    MEM_B(-0XB, ctx->r2) = ctx->r25;
    // 0x8002748C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80027490: sb          $t5, -0xE($v0)
    MEM_B(-0XE, ctx->r2) = ctx->r13;
    // 0x80027494: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80027498: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002749C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800274A0: sb          $s0, -0xD($v0)
    MEM_B(-0XD, ctx->r2) = ctx->r16;
    // 0x800274A4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800274A8: sh          $t2, -0x10($v0)
    MEM_H(-0X10, ctx->r2) = ctx->r10;
    // 0x800274AC: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800274B0: sb          $s1, -0xC($v0)
    MEM_B(-0XC, ctx->r2) = ctx->r17;
    // 0x800274B4: sh          $t3, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r11;
    // 0x800274B8: sh          $t6, -0x12($v0)
    MEM_H(-0X12, ctx->r2) = ctx->r14;
    // 0x800274BC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800274C0: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800274C4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800274C8: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800274CC: sb          $t5, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r13;
    // 0x800274D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800274D4: sb          $s0, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r16;
    // 0x800274D8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800274DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800274E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800274E4: sh          $t4, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r12;
    // 0x800274E8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800274EC: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
    // 0x800274F0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800274F4: sb          $s1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r17;
    // 0x800274F8: sh          $t8, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r24;
    // 0x800274FC: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    // 0x80027500: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80027504: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80027508: addiu       $t5, $zero, 0x3E0
    ctx->r13 = ADD32(0, 0X3E0);
    // 0x8002750C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80027510: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80027514: addiu       $t2, $a1, 0x2
    ctx->r10 = ADD32(ctx->r5, 0X2);
    // 0x80027518: addiu       $t3, $a1, 0x1
    ctx->r11 = ADD32(ctx->r5, 0X1);
    // 0x8002751C: addiu       $t9, $a1, 0x3
    ctx->r25 = ADD32(ctx->r5, 0X3);
    // 0x80027520: sb          $t9, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r25;
    // 0x80027524: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x80027528: sb          $t2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r10;
    // 0x8002752C: sb          $t3, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r11;
    // 0x80027530: sb          $a1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r5;
    // 0x80027534: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x80027538: sh          $t5, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r13;
    // 0x8002753C: sh          $t5, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r13;
    // 0x80027540: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x80027544: sh          $s0, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r16;
    // 0x80027548: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x8002754C: sb          $t4, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r12;
    // 0x80027550: sb          $t3, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r11;
    // 0x80027554: sb          $t2, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r10;
    // 0x80027558: sh          $s0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r16;
    // 0x8002755C: sh          $t5, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r13;
    // 0x80027560: sh          $t5, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r13;
    // 0x80027564: sh          $t5, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r13;
    // 0x80027568: sh          $s0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r16;
    // 0x8002756C: sh          $zero, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = 0;
    // 0x80027570: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80027574: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80027578: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x8002757C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80027580: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80027584: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80027588: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    // 0x8002758C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80027590: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x80027594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80027598:
    // 0x80027598: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002759C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800275A0: jr          $ra
    // 0x800275A4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800275A4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80027568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800275A8: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x800275AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800275B0: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800275B4: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x800275B8: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800275BC: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x800275C0: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800275C4: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x800275C8: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800275CC: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800275D0: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800275D4: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800275D8: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800275DC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800275E0: jal         0x8001BAA8
    // 0x800275E4: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800275E4: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    after_0:
    // 0x800275E8: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800275EC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800275F0: bne         $t6, $zero, L_80027600
    if (ctx->r14 != 0) {
        // 0x800275F4: nop
    
            goto L_80027600;
    }
    // 0x800275F4: nop

    // 0x800275F8: b           L_800278EC
    // 0x800275FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800278EC;
    // 0x800275FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80027600:
    // 0x80027600: jal         0x80066750
    // 0x80027604: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_1;
    // 0x80027604: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    after_1:
    // 0x80027608: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8002760C: bne         $v0, $zero, L_80027638
    if (ctx->r2 != 0) {
        // 0x80027610: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80027638;
    }
    // 0x80027610: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80027614: lw          $t7, -0x49D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X49D0);
    // 0x80027618: nop

    // 0x8002761C: lh          $v0, 0x36($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X36);
    // 0x80027620: nop

    // 0x80027624: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80027628: beq         $at, $zero, L_80027638
    if (ctx->r1 == 0) {
        // 0x8002762C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80027638;
    }
    // 0x8002762C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80027630: bne         $v0, $at, L_80027640
    if (ctx->r2 != ctx->r1) {
        // 0x80027634: nop
    
            goto L_80027640;
    }
    // 0x80027634: nop

L_80027638:
    // 0x80027638: b           L_800278EC
    // 0x8002763C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800278EC;
    // 0x8002763C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80027640:
    // 0x80027640: jal         0x80066460
    // 0x80027644: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    get_current_viewport(rdram, ctx);
        goto after_2;
    // 0x80027644: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    after_2:
    // 0x80027648: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x8002764C: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80027650: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80027654: blez        $t8, L_8002769C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80027658: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002769C;
    }
    // 0x80027658: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002765C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_80027660:
    // 0x80027660: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x80027664: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80027668: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x8002766C: lw          $a0, 0x64($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X64);
    // 0x80027670: nop

    // 0x80027674: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80027678: nop

    // 0x8002767C: bne         $v0, $t7, L_80027690
    if (ctx->r2 != ctx->r15) {
        // 0x80027680: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80027690;
    }
    // 0x80027680: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80027684: lw          $v1, 0xC4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC4);
    // 0x80027688: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x8002768C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80027690:
    // 0x80027690: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80027694: bne         $at, $zero, L_80027660
    if (ctx->r1 != 0) {
        // 0x80027698: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80027660;
    }
    // 0x80027698: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_8002769C:
    // 0x8002769C: bne         $t3, $zero, L_800276AC
    if (ctx->r11 != 0) {
        // 0x800276A0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800276AC;
    }
    // 0x800276A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800276A4: b           L_800278EC
    // 0x800276A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800278EC;
    // 0x800276A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800276AC:
    // 0x800276AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800276B0: lw          $a2, -0x49D0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X49D0);
    // 0x800276B4: addiu       $a1, $t3, 0xC
    ctx->r5 = ADD32(ctx->r11, 0XC);
    // 0x800276B8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800276BC: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800276C0: jal         0x80031170
    // 0x800276C4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    generate_collision_candidates(rdram, ctx);
        goto after_3;
    // 0x800276C4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    after_3:
    // 0x800276C8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800276CC: lw          $v1, -0x2708($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2708);
    // 0x800276D0: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800276D4: blez        $v1, L_800278E8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800276D8: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800278E8;
    }
    // 0x800276D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800276DC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800276E0: lw          $t9, -0x2710($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2710);
    // 0x800276E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800276E8: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x800276EC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800276F0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800276F4: lw          $ra, 0xE4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE4);
    // 0x800276F8: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800276FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80027700: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
L_80027704:
    // 0x80027704: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80027708: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002770C: blez        $a0, L_8002771C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80027710: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8002771C;
    }
    // 0x80027710: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80027714: b           L_800278C8
    // 0x80027718: or          $ra, $a0, $at
    ctx->r31 = ctx->r4 | ctx->r1;
        goto L_800278C8;
    // 0x80027718: or          $ra, $a0, $at
    ctx->r31 = ctx->r4 | ctx->r1;
L_8002771C:
    // 0x8002771C: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x80027720: lw          $t0, 0x18($ra)
    ctx->r8 = MEM_W(ctx->r31, 0X18);
    // 0x80027724: lw          $a1, -0x49D0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X49D0);
    // 0x80027728: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8002772C: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x80027730: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80027734: lwc1        $f28, 0xC($a1)
    ctx->f28.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80027738: lwc1        $f20, 0x4($v1)
    ctx->f20.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002773C: mul.s       $f4, $f28, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x80027740: lwc1        $f30, 0x10($a1)
    ctx->f30.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80027744: lwc1        $f22, 0x8($v1)
    ctx->f22.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80027748: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8002774C: mul.s       $f6, $f20, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80027750: lwc1        $f24, 0xC($v1)
    ctx->f24.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80027754: lui         $at, 0x402C
    ctx->r1 = S32(0X402C << 16);
    // 0x80027758: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8002775C: mul.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80027760: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80027764: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80027768: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002776C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80027770: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80027774: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80027778: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8002777C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80027780: sub.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d - ctx->f10.d;
    // 0x80027784: lwc1        $f8, 0x6424($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6424);
    // 0x80027788: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x8002778C: lwc1        $f9, 0x6420($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6420);
    // 0x80027790: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x80027794: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80027798: nop

    // 0x8002779C: bc1f        L_800278CC
    if (!c1cs) {
        // 0x800277A0: lw          $t9, 0x4C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X4C);
            goto L_800278CC;
    }
    // 0x800277A0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800277A4: lwc1        $f14, 0xC($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800277A8: lwc1        $f16, 0x10($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X10);
    // 0x800277AC: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800277B0: lwc1        $f18, 0x14($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X14);
    // 0x800277B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800277B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800277BC: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x800277C0: nop

    // 0x800277C4: mul.s       $f8, $f22, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x800277C8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800277CC: lwc1        $f7, 0x6428($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6428);
    // 0x800277D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800277D4: lwc1        $f6, 0x642C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X642C);
    // 0x800277D8: add.s       $f0, $f10, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x800277DC: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800277E0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800277E4: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x800277E8: nop

    // 0x800277EC: bc1f        L_800278C8
    if (!c1cs) {
        // 0x800277F0: nop
    
            goto L_800278C8;
    }
    // 0x800277F0: nop

    // 0x800277F4: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x800277F8: sub.s       $f20, $f28, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f14.fl;
    // 0x800277FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80027800: sub.s       $f22, $f30, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x80027804: bc1t        L_80027818
    if (c1cs) {
        // 0x80027808: sub.s       $f24, $f8, $f18
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f18.fl;
            goto L_80027818;
    }
    // 0x80027808: sub.s       $f24, $f8, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8002780C: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80027810: b           L_80027820
    // 0x80027814: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
        goto L_80027820;
    // 0x80027814: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
L_80027818:
    // 0x80027818: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002781C: nop

L_80027820:
    // 0x80027820: mul.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80027824: sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2 << 1);
    // 0x80027828: addu        $a2, $t2, $a1
    ctx->r6 = ADD32(ctx->r10, ctx->r5);
    // 0x8002782C: mul.s       $f6, $f22, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80027830: add.s       $f20, $f14, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x80027834: mul.s       $f8, $f24, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x80027838: add.s       $f22, $f16, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8002783C: add.s       $f24, $f18, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f18.fl + ctx->f8.fl;
L_80027840:
    // 0x80027840: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    // 0x80027844: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80027848: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x8002784C: beq         $t9, $zero, L_80027860
    if (ctx->r25 == 0) {
        // 0x80027850: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80027860;
    }
    // 0x80027850: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80027854: andi        $t6, $v0, 0x7FFF
    ctx->r14 = ctx->r2 & 0X7FFF;
    // 0x80027858: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8002785C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
L_80027860:
    // 0x80027860: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80027864: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x80027868: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002786C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80027870: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80027874: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80027878: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002787C: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x80027880: mul.s       $f4, $f2, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x80027884: nop

    // 0x80027888: mul.s       $f8, $f12, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x8002788C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80027890: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80027894: add.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80027898: beq         $a0, $zero, L_800278A4
    if (ctx->r4 == 0) {
        // 0x8002789C: mov.s       $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
            goto L_800278A4;
    }
    // 0x8002789C: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x800278A0: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
L_800278A4:
    // 0x800278A4: c.lt.s      $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f26.fl < ctx->f16.fl;
    // 0x800278A8: nop

    // 0x800278AC: bc1f        L_800278B8
    if (!c1cs) {
        // 0x800278B0: nop
    
            goto L_800278B8;
    }
    // 0x800278B0: nop

    // 0x800278B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800278B8:
    // 0x800278B8: beq         $at, $zero, L_800278C8
    if (ctx->r1 == 0) {
        // 0x800278BC: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_800278C8;
    }
    // 0x800278BC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800278C0: beq         $a3, $t1, L_80027840
    if (ctx->r7 == ctx->r9) {
        // 0x800278C4: nop
    
            goto L_80027840;
    }
    // 0x800278C4: nop

L_800278C8:
    // 0x800278C8: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
L_800278CC:
    // 0x800278CC: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x800278D0: slt         $at, $t4, $t9
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800278D4: beq         $at, $zero, L_800278E8
    if (ctx->r1 == 0) {
        // 0x800278D8: addiu       $t5, $t5, 0x4
        ctx->r13 = ADD32(ctx->r13, 0X4);
            goto L_800278E8;
    }
    // 0x800278D8: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x800278DC: beq         $a3, $zero, L_80027704
    if (ctx->r7 == 0) {
        // 0x800278E0: nop
    
            goto L_80027704;
    }
    // 0x800278E0: nop

    // 0x800278E4: sw          $ra, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r31;
L_800278E8:
    // 0x800278E8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800278EC:
    // 0x800278EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800278F0: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800278F4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800278F8: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800278FC: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80027900: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80027904: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80027908: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002790C: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80027910: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80027914: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80027918: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002791C: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80027920: jr          $ra
    // 0x80027924: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x80027924: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void ttcam_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027928: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8002792C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80027930: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80027934: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80027938: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002793C: jal         0x8001BAA8
    // 0x80027940: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x80027940: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x80027944: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80027948: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002794C: blez        $t6, L_80027A14
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80027950: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80027A14;
    }
    // 0x80027950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80027954: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80027958:
    // 0x80027958: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002795C: nop

    // 0x80027960: beq         $v0, $zero, L_80027A04
    if (ctx->r2 == 0) {
        // 0x80027964: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80027A04;
    }
    // 0x80027964: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80027968: lw          $s1, 0x64($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X64);
    // 0x8002796C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80027970: lb          $t7, 0x1FD($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1FD);
    // 0x80027974: nop

    // 0x80027978: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8002797C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80027980: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80027984: jal         0x8001BE08
    // 0x80027988: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    spectate_nearest(rdram, ctx);
        goto after_1;
    // 0x80027988: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_1:
    // 0x8002798C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80027990: lb          $t9, 0x1D8($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1D8);
    // 0x80027994: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80027998: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8002799C: beq         $t9, $zero, L_800279C4
    if (ctx->r25 == 0) {
        // 0x800279A0: sb          $t8, 0x1FD($s1)
        MEM_B(0X1FD, ctx->r17) = ctx->r24;
            goto L_800279C4;
    }
    // 0x800279A0: sb          $t8, 0x1FD($s1)
    MEM_B(0X1FD, ctx->r17) = ctx->r24;
    // 0x800279A4: lh          $t0, 0x1AC($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X1AC);
    // 0x800279A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800279AC: bne         $t0, $at, L_80027A04
    if (ctx->r8 != ctx->r1) {
        // 0x800279B0: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80027A04;
    }
    // 0x800279B0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800279B4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800279B8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800279BC: b           L_80027A00
    // 0x800279C0: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
        goto L_80027A00;
    // 0x800279C0: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
L_800279C4:
    // 0x800279C4: bne         $v1, $zero, L_800279DC
    if (ctx->r3 != 0) {
        // 0x800279C8: nop
    
            goto L_800279DC;
    }
    // 0x800279C8: nop

    // 0x800279CC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800279D0: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800279D4: b           L_80027A00
    // 0x800279D8: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
        goto L_80027A00;
    // 0x800279D8: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_800279DC:
    // 0x800279DC: lh          $t3, 0x1AE($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X1AE);
    // 0x800279E0: lh          $t4, 0x1AE($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X1AE);
    // 0x800279E4: nop

    // 0x800279E8: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800279EC: beq         $at, $zero, L_80027A04
    if (ctx->r1 == 0) {
        // 0x800279F0: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80027A04;
    }
    // 0x800279F0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800279F4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800279F8: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800279FC: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
L_80027A00:
    // 0x80027A00: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_80027A04:
    // 0x80027A04: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80027A08: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80027A0C: bne         $at, $zero, L_80027958
    if (ctx->r1 != 0) {
        // 0x80027A10: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80027958;
    }
    // 0x80027A10: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80027A14:
    // 0x80027A14: beq         $v1, $zero, L_80027A2C
    if (ctx->r3 == 0) {
        // 0x80027A18: lw          $s1, 0x3C($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X3C);
            goto L_80027A2C;
    }
    // 0x80027A18: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80027A1C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80027A20: b           L_80027A34
    // 0x80027A24: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
        goto L_80027A34;
    // 0x80027A24: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80027A28: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
L_80027A2C:
    // 0x80027A2C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80027A30: nop

L_80027A34:
    // 0x80027A34: lb          $a0, 0x1FD($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X1FD);
    // 0x80027A38: jal         0x8001BDC8
    // 0x80027A3C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    spectate_object(rdram, ctx);
        goto after_2;
    // 0x80027A3C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_2:
    // 0x80027A40: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80027A44: lw          $t7, -0x497C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X497C);
    // 0x80027A48: lb          $t8, 0x1FD($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X1FD);
    // 0x80027A4C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80027A50: beq         $t7, $t8, L_80027A68
    if (ctx->r15 == ctx->r24) {
        // 0x80027A54: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80027A68;
    }
    // 0x80027A54: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80027A58: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027A5C: addiu       $a3, $a3, -0x4978
    ctx->r7 = ADD32(ctx->r7, -0X4978);
    // 0x80027A60: b           L_80027A9C
    // 0x80027A64: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
        goto L_80027A9C;
    // 0x80027A64: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80027A68:
    // 0x80027A68: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80027A6C: addiu       $v1, $v1, -0x4980
    ctx->r3 = ADD32(ctx->r3, -0X4980);
    // 0x80027A70: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80027A74: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x80027A78: nop

    // 0x80027A7C: beq         $t9, $t0, L_80027A9C
    if (ctx->r25 == ctx->r8) {
        // 0x80027A80: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80027A9C;
    }
    // 0x80027A80: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027A84: addiu       $a3, $a3, -0x4978
    ctx->r7 = ADD32(ctx->r7, -0X4978);
    // 0x80027A88: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x80027A8C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80027A90: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x80027A94: nop

    // 0x80027A98: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80027A9C:
    // 0x80027A9C: beq         $v0, $zero, L_80027E54
    if (ctx->r2 == 0) {
        // 0x80027AA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80027E54;
    }
    // 0x80027AA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80027AA4: jal         0x80069F3C
    // 0x80027AA8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_3;
    // 0x80027AA8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_3:
    // 0x80027AAC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80027AB0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80027AB4: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x80027AB8: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027ABC: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80027AC0: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80027AC4: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027AC8: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80027ACC: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x80027AD0: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80027AD4: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80027AD8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80027ADC: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80027AE0: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80027AE4: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80027AE8: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80027AEC: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80027AF0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80027AF4: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x80027AF8: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x80027AFC: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80027B00: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80027B04: jal         0x800CA030
    // 0x80027B08: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80027B08: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_4:
    // 0x80027B0C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027B10: addiu       $a3, $a3, -0x4978
    ctx->r7 = ADD32(ctx->r7, -0X4978);
    // 0x80027B14: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80027B18: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027B1C: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80027B20: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80027B24: beq         $t3, $zero, L_80027D58
    if (ctx->r11 == 0) {
        // 0x80027B28: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_80027D58;
    }
    // 0x80027B28: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80027B2C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80027B30: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80027B34: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80027B38: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027B3C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027B40: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x80027B44: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80027B48: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80027B4C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80027B50: nop

    // 0x80027B54: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80027B58: nop

    // 0x80027B5C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80027B60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027B64: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027B68: nop

    // 0x80027B6C: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80027B70: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80027B74: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80027B78: jal         0x800708AC
    // 0x80027B7C: nop

    atan2s(rdram, ctx);
        goto after_5;
    // 0x80027B7C: nop

    after_5:
    // 0x80027B80: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027B84: negu        $t6, $v0
    ctx->r14 = SUB32(0, ctx->r2);
    // 0x80027B88: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x80027B8C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80027B90: subu        $s0, $t6, $a2
    ctx->r16 = SUB32(ctx->r14, ctx->r6);
    // 0x80027B94: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x80027B98: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x80027B9C: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80027BA0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80027BA4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027BA8: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80027BAC: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80027BB0: addiu       $a3, $a3, -0x4978
    ctx->r7 = ADD32(ctx->r7, -0X4978);
    // 0x80027BB4: bne         $at, $zero, L_80027BD4
    if (ctx->r1 != 0) {
        // 0x80027BB8: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_80027BD4;
    }
    // 0x80027BB8: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80027BBC: lui         $t0, 0xFFFF
    ctx->r8 = S32(0XFFFF << 16);
    // 0x80027BC0: ori         $t0, $t0, 0x1
    ctx->r8 = ctx->r8 | 0X1;
    // 0x80027BC4: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80027BC8: subu        $s0, $t0, $t9
    ctx->r16 = SUB32(ctx->r8, ctx->r25);
    // 0x80027BCC: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x80027BD0: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
L_80027BD4:
    // 0x80027BD4: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80027BD8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80027BDC: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80027BE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027BE4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80027BE8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80027BEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80027BF0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80027BF4: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80027BF8: nop

    // 0x80027BFC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80027C00: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80027C04: nop

    // 0x80027C08: div.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80027C0C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80027C10: nop

    // 0x80027C14: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80027C18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027C1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027C20: nop

    // 0x80027C24: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80027C28: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80027C2C: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80027C30: nop

    // 0x80027C34: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80027C38: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x80027C3C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80027C40: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80027C44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027C48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027C4C: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80027C50: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80027C54: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80027C58: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80027C5C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80027C60: nop

    // 0x80027C64: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80027C68: nop

    // 0x80027C6C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80027C70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027C74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027C78: nop

    // 0x80027C7C: cvt.w.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80027C80: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80027C84: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80027C88: jal         0x800708AC
    // 0x80027C8C: nop

    atan2s(rdram, ctx);
        goto after_6;
    // 0x80027C8C: nop

    after_6:
    // 0x80027C90: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027C94: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80027C98: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x80027C9C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027CA0: subu        $s0, $v0, $a0
    ctx->r16 = SUB32(ctx->r2, ctx->r4);
    // 0x80027CA4: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x80027CA8: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80027CAC: slt         $at, $t1, $at
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80027CB0: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80027CB4: bne         $at, $zero, L_80027CD4
    if (ctx->r1 != 0) {
        // 0x80027CB8: addiu       $a3, $a3, -0x4978
        ctx->r7 = ADD32(ctx->r7, -0X4978);
            goto L_80027CD4;
    }
    // 0x80027CB8: addiu       $a3, $a3, -0x4978
    ctx->r7 = ADD32(ctx->r7, -0X4978);
    // 0x80027CBC: lui         $t3, 0xFFFF
    ctx->r11 = S32(0XFFFF << 16);
    // 0x80027CC0: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x80027CC4: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80027CC8: subu        $s0, $t3, $t2
    ctx->r16 = SUB32(ctx->r11, ctx->r10);
    // 0x80027CCC: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80027CD0: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
L_80027CD4:
    // 0x80027CD4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80027CD8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80027CDC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80027CE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80027CE4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80027CE8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80027CEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027CF0: div.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80027CF4: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x80027CF8: nop

    // 0x80027CFC: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80027D00: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80027D04: nop

    // 0x80027D08: div.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80027D0C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80027D10: nop

    // 0x80027D14: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80027D18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027D1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027D20: nop

    // 0x80027D24: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80027D28: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80027D2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80027D30: addu        $t9, $a0, $t0
    ctx->r25 = ADD32(ctx->r4, ctx->r8);
    // 0x80027D34: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x80027D38: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80027D3C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80027D40: nop

    // 0x80027D44: subu        $t2, $t1, $t3
    ctx->r10 = SUB32(ctx->r9, ctx->r11);
    // 0x80027D48: bgez        $t2, L_80027E20
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80027D4C: sw          $t2, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r10;
            goto L_80027E20;
    }
    // 0x80027D4C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80027D50: b           L_80027E20
    // 0x80027D54: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
        goto L_80027E20;
    // 0x80027D54: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80027D58:
    // 0x80027D58: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80027D5C: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80027D60: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80027D64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027D68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027D6C: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x80027D70: cvt.w.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80027D74: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80027D78: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80027D7C: nop

    // 0x80027D80: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80027D84: nop

    // 0x80027D88: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80027D8C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027D90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027D94: nop

    // 0x80027D98: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80027D9C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80027DA0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80027DA4: jal         0x800708AC
    // 0x80027DA8: nop

    atan2s(rdram, ctx);
        goto after_7;
    // 0x80027DA8: nop

    after_7:
    // 0x80027DAC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80027DB0: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027DB4: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80027DB8: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80027DBC: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x80027DC0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80027DC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027DC8: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80027DCC: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80027DD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027DD4: nop

    // 0x80027DD8: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80027DDC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80027DE0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80027DE4: nop

    // 0x80027DE8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80027DEC: nop

    // 0x80027DF0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80027DF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027DF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027DFC: nop

    // 0x80027E00: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80027E04: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80027E08: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80027E0C: jal         0x800708AC
    // 0x80027E10: nop

    atan2s(rdram, ctx);
        goto after_8;
    // 0x80027E10: nop

    after_8:
    // 0x80027E14: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027E18: nop

    // 0x80027E1C: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_80027E20:
    // 0x80027E20: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x80027E24: lwc1        $f14, 0x3C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80027E28: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80027E2C: lw          $a2, 0x14($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X14);
    // 0x80027E30: jal         0x80029F58
    // 0x80027E34: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_9;
    // 0x80027E34: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_9:
    // 0x80027E38: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027E3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80027E40: sh          $v0, 0x34($v1)
    MEM_H(0X34, ctx->r3) = ctx->r2;
    // 0x80027E44: lb          $t1, 0x1FD($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1FD);
    // 0x80027E48: nop

    // 0x80027E4C: sw          $t1, -0x497C($at)
    MEM_W(-0X497C, ctx->r1) = ctx->r9;
    // 0x80027E50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80027E54:
    // 0x80027E54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80027E58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80027E5C: jr          $ra
    // 0x80027E60: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80027E60: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void track_tex_anim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027E64: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80027E68: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80027E6C: lw          $a1, -0x3178($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3178);
    // 0x80027E70: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80027E74: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80027E78: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80027E7C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80027E80: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80027E84: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80027E88: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80027E8C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80027E90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80027E94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80027E98: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80027E9C: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80027EA0: lh          $v0, 0x1A($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X1A);
    // 0x80027EA4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80027EA8: blez        $v0, L_80027FD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80027EAC: or          $s6, $v1, $zero
        ctx->r22 = ctx->r3 | 0;
            goto L_80027FD4;
    }
    // 0x80027EAC: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x80027EB0: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x80027EB4: lui         $s7, 0x1
    ctx->r23 = S32(0X1 << 16);
    // 0x80027EB8: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
L_80027EBC:
    // 0x80027EBC: lh          $v1, 0x20($s6)
    ctx->r3 = MEM_H(ctx->r22, 0X20);
    // 0x80027EC0: lw          $s5, 0xC($s6)
    ctx->r21 = MEM_W(ctx->r22, 0XC);
    // 0x80027EC4: blez        $v1, L_80027FBC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80027EC8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80027FBC;
    }
    // 0x80027EC8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80027ECC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80027ED0: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
L_80027ED4:
    // 0x80027ED4: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80027ED8: nop

    // 0x80027EDC: and         $t7, $t6, $s7
    ctx->r15 = ctx->r14 & ctx->r23;
    // 0x80027EE0: beq         $t7, $zero, L_80027FA0
    if (ctx->r15 == 0) {
        // 0x80027EE4: nop
    
            goto L_80027FA0;
    }
    // 0x80027EE4: nop

    // 0x80027EE8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80027EEC: nop

    // 0x80027EF0: beq         $fp, $v0, L_80027FA0
    if (ctx->r30 == ctx->r2) {
        // 0x80027EF4: nop
    
            goto L_80027FA0;
    }
    // 0x80027EF4: nop

    // 0x80027EF8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80027EFC: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x80027F00: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80027F04: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80027F08: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80027F0C: lhu         $t1, 0x12($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X12);
    // 0x80027F10: nop

    // 0x80027F14: beq         $t1, $at, L_80027FA0
    if (ctx->r9 == ctx->r1) {
        // 0x80027F18: nop
    
            goto L_80027FA0;
    }
    // 0x80027F18: nop

    // 0x80027F1C: lhu         $t2, 0x14($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X14);
    // 0x80027F20: nop

    // 0x80027F24: beq         $t2, $zero, L_80027FA0
    if (ctx->r10 == 0) {
        // 0x80027F28: nop
    
            goto L_80027FA0;
    }
    // 0x80027F28: nop

    // 0x80027F2C: lbu         $t3, 0x7($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7);
    // 0x80027F30: addu        $a1, $s2, $s5
    ctx->r5 = ADD32(ctx->r18, ctx->r21);
    // 0x80027F34: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x80027F38: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x80027F3C: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80027F40: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80027F44: sll         $t6, $t5, 0
    ctx->r14 = S32(ctx->r13 << 0);
    // 0x80027F48: bgez        $t6, L_80027F7C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80027F4C: or          $a2, $s4, $zero
        ctx->r6 = ctx->r20 | 0;
            goto L_80027F7C;
    }
    // 0x80027F4C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80027F50: lbu         $t8, 0x6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6);
    // 0x80027F54: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80027F58: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x80027F5C: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x80027F60: jal         0x8007F3D0
    // 0x80027F64: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    tex_animate_texture(rdram, ctx);
        goto after_0;
    // 0x80027F64: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_0:
    // 0x80027F68: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80027F6C: nop

    // 0x80027F70: andi        $t1, $t0, 0x3F
    ctx->r9 = ctx->r8 & 0X3F;
    // 0x80027F74: b           L_80027F84
    // 0x80027F78: sb          $t1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r9;
        goto L_80027F84;
    // 0x80027F78: sb          $t1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r9;
L_80027F7C:
    // 0x80027F7C: jal         0x8007F3D0
    // 0x80027F80: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    tex_animate_texture(rdram, ctx);
        goto after_1;
    // 0x80027F80: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
L_80027F84:
    // 0x80027F84: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80027F88: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80027F8C: sra         $t4, $t2, 6
    ctx->r12 = S32(SIGNED(ctx->r10) >> 6);
    // 0x80027F90: sb          $t4, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r12;
    // 0x80027F94: lh          $v1, 0x20($s6)
    ctx->r3 = MEM_H(ctx->r22, 0X20);
    // 0x80027F98: lw          $a1, -0x3178($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3178);
    // 0x80027F9C: nop

L_80027FA0:
    // 0x80027FA0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80027FA4: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80027FA8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80027FAC: bne         $at, $zero, L_80027ED4
    if (ctx->r1 != 0) {
        // 0x80027FB0: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80027ED4;
    }
    // 0x80027FB0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80027FB4: lh          $v0, 0x1A($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X1A);
    // 0x80027FB8: nop

L_80027FBC:
    // 0x80027FBC: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80027FC0: addiu       $s6, $s6, 0x44
    ctx->r22 = ADD32(ctx->r22, 0X44);
    // 0x80027FC4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80027FC8: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80027FCC: bne         $at, $zero, L_80027EBC
    if (ctx->r1 != 0) {
        // 0x80027FD0: sw          $t6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r14;
            goto L_80027EBC;
    }
    // 0x80027FD0: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_80027FD4:
    // 0x80027FD4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80027FD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80027FDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80027FE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80027FE4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80027FE8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80027FEC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80027FF0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80027FF4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80027FF8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80027FFC: jr          $ra
    // 0x80028000: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80028000: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void skydome_spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028004: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80028008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002800C: jal         0x8005A43C
    // 0x80028010: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    drm_checksum_balloon(rdram, ctx);
        goto after_0;
    // 0x80028010: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80028014: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80028018: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002801C: bne         $v0, $at, L_80028030
    if (ctx->r2 != ctx->r1) {
        // 0x80028020: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80028030;
    }
    // 0x80028020: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80028024: addiu       $a0, $a0, -0x49C8
    ctx->r4 = ADD32(ctx->r4, -0X49C8);
    // 0x80028028: b           L_80028074
    // 0x8002802C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_80028074;
    // 0x8002802C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80028030:
    // 0x80028030: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80028034: sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
    // 0x80028038: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // 0x8002803C: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
    // 0x80028040: sb          $t6, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r14;
    // 0x80028044: sb          $v0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r2;
    // 0x80028048: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8002804C: jal         0x8000EA54
    // 0x80028050: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    spawn_object(rdram, ctx);
        goto after_1;
    // 0x80028050: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80028054: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80028058: addiu       $a0, $a0, -0x49C8
    ctx->r4 = ADD32(ctx->r4, -0X49C8);
    // 0x8002805C: beq         $v0, $zero, L_80028074
    if (ctx->r2 == 0) {
        // 0x80028060: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80028074;
    }
    // 0x80028060: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80028064: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80028068: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8002806C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80028070: sh          $t7, 0x4A($t8)
    MEM_H(0X4A, ctx->r24) = ctx->r15;
L_80028074:
    // 0x80028074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028078: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002807C: jr          $ra
    // 0x80028080: nop

    return;
    // 0x80028080: nop

;}
RECOMP_FUNC void set_skydome_visbility(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028084: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028088: jr          $ra
    // 0x8002808C: sw          $a0, -0x49A4($at)
    MEM_W(-0X49A4, ctx->r1) = ctx->r4;
    return;
    // 0x8002808C: sw          $a0, -0x49A4($at)
    MEM_W(-0X49A4, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void trackbg_render_flashy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028090: addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // 0x80028094: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80028098: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002809C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800280A0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800280A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800280A8: lw          $s1, -0x49D8($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X49D8);
    // 0x800280AC: lw          $s0, -0x49D4($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X49D4);
    // 0x800280B0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800280B4: jal         0x80069F60
    // 0x800280B8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x800280B8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_0:
    // 0x800280BC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800280C0: lw          $t6, -0x3174($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3174);
    // 0x800280C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800280C8: lw          $v1, 0xA4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0XA4);
    // 0x800280CC: nop

    // 0x800280D0: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x800280D4: lbu         $s3, 0x0($v1)
    ctx->r19 = MEM_BU(ctx->r3, 0X0);
    // 0x800280D8: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x800280DC: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x800280E0: sw          $t4, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r12;
    // 0x800280E4: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x800280E8: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x800280EC: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800280F0: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800280F4: addiu       $s3, $t7, -0x1
    ctx->r19 = ADD32(ctx->r15, -0X1);
    // 0x800280F8: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800280FC: jal         0x80070A04
    // 0x80028100: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80028100: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    after_1:
    // 0x80028104: swc1        $f0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f0.u32l;
    // 0x80028108: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    // 0x8002810C: nop

    // 0x80028110: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80028114: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80028118: jal         0x80070A38
    // 0x8002811C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    coss_f(rdram, ctx);
        goto after_2;
    // 0x8002811C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_2:
    // 0x80028120: lui         $at, 0x44A0
    ctx->r1 = S32(0X44A0 << 16);
    // 0x80028124: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80028128: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002812C: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80028130: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80028134: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80028138: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8002813C: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80028140: neg.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = -ctx->f12.fl;
    // 0x80028144: lw          $a0, -0x3174($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3174);
    // 0x80028148: add.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8002814C: sub.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80028150: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80028154: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80028158: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8002815C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80028160: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80028164: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80028168: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
    // 0x8002816C: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80028170: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80028174: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80028178: swc1        $f8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f8.u32l;
    // 0x8002817C: swc1        $f8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f8.u32l;
    // 0x80028180: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80028184: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80028188: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002818C: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x80028190: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
    // 0x80028194: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x80028198: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002819C: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x800281A0: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x800281A4: add.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800281A8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800281AC: swc1        $f4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f4.u32l;
    // 0x800281B0: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x800281B4: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800281B8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800281BC: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x800281C0: sub.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800281C4: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800281C8: swc1        $f8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f8.u32l;
    // 0x800281CC: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800281D0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800281D4: sub.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x800281D8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800281DC: swc1        $f8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f8.u32l;
    // 0x800281E0: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800281E4: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
    // 0x800281E8: add.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x800281EC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800281F0: swc1        $f10, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f10.u32l;
    // 0x800281F4: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
    // 0x800281F8: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800281FC: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80028200: swc1        $f10, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f10.u32l;
    // 0x80028204: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    // 0x80028208: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x8002820C: lbu         $t5, 0xA0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XA0);
    // 0x80028210: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x80028214: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80028218: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002821C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80028220: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80028224: lbu         $t6, 0x1($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1);
    // 0x80028228: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8002822C: lbu         $t8, 0xA1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA1);
    // 0x80028230: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80028234: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80028238: mflo        $a1
    ctx->r5 = lo;
    // 0x8002823C: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x80028240: nop

    // 0x80028244: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80028248: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002824C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80028250: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80028254: lh          $t5, 0xA8($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XA8);
    // 0x80028258: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8002825C: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80028260: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x80028264: mflo        $a2
    ctx->r6 = lo;
    // 0x80028268: mul.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8002826C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028270: nop

    // 0x80028274: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028278: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002827C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028280: nop

    // 0x80028284: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80028288: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x8002828C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028290: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80028294: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80028298: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8002829C: and         $v0, $t7, $s3
    ctx->r2 = ctx->r15 & ctx->r19;
    // 0x800282A0: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x800282A4: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800282A8: lh          $t5, 0xAA($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XAA);
    // 0x800282AC: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800282B0: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800282B4: lw          $t7, 0x14C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14C);
    // 0x800282B8: sra         $t4, $t5, 4
    ctx->r12 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800282BC: sh          $v0, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r2;
    // 0x800282C0: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800282C4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800282C8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800282CC: nop

    // 0x800282D0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800282D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800282D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800282DC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800282E0: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800282E4: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800282E8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800282EC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800282F0: mul.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800282F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800282F8: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x800282FC: and         $v1, $t6, $t7
    ctx->r3 = ctx->r14 & ctx->r15;
    // 0x80028300: mul.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80028304: neg.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
    // 0x80028308: swc1        $f14, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f14.u32l;
    // 0x8002830C: swc1        $f14, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f14.u32l;
    // 0x80028310: sub.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80028314: sh          $v1, 0x11C($sp)
    MEM_H(0X11C, ctx->r29) = ctx->r3;
    // 0x80028318: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002831C: nop

    // 0x80028320: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028324: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80028328: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8002832C: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80028330: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x80028334: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80028338: sh          $t6, 0x128($sp)
    MEM_H(0X128, ctx->r29) = ctx->r14;
    // 0x8002833C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80028340: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028344: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028348: nop

    // 0x8002834C: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80028350: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80028354: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80028358: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8002835C: addu        $t9, $a0, $v1
    ctx->r25 = ADD32(ctx->r4, ctx->r3);
    // 0x80028360: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80028364: sh          $t9, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r25;
    // 0x80028368: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8002836C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028370: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028374: nop

    // 0x80028378: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002837C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80028380: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80028384: sub.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80028388: addu        $t5, $t8, $v0
    ctx->r13 = ADD32(ctx->r24, ctx->r2);
    // 0x8002838C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028390: sh          $t5, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r13;
    // 0x80028394: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028398: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002839C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800283A0: nop

    // 0x800283A4: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800283A8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800283AC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800283B0: add.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x800283B4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800283B8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800283BC: sh          $t8, 0x116($sp)
    MEM_H(0X116, ctx->r29) = ctx->r24;
    // 0x800283C0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800283C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800283C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800283CC: nop

    // 0x800283D0: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800283D4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800283D8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800283DC: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800283E0: addu        $t6, $a1, $v0
    ctx->r14 = ADD32(ctx->r5, ctx->r2);
    // 0x800283E4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800283E8: sh          $t6, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = ctx->r14;
    // 0x800283EC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800283F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800283F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800283F8: addu        $t6, $a0, $v0
    ctx->r14 = ADD32(ctx->r4, ctx->r2);
    // 0x800283FC: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80028400: sh          $t6, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = ctx->r14;
    // 0x80028404: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80028408: addu        $t7, $a1, $v1
    ctx->r15 = ADD32(ctx->r5, ctx->r3);
    // 0x8002840C: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80028410: sh          $t7, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = ctx->r15;
    // 0x80028414: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80028418: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8002841C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80028420: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x80028424: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80028428: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002842C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028430: sh          $t4, 0x118($sp)
    MEM_H(0X118, ctx->r29) = ctx->r12;
    // 0x80028434: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028438: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002843C: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80028440: add.s       $f2, $f14, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80028444: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x80028448: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002844C: sh          $t6, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r14;
    // 0x80028450: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80028454: nop

    // 0x80028458: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002845C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028460: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028464: nop

    // 0x80028468: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002846C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80028470: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80028474: sub.s       $f8, $f14, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x80028478: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x8002847C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80028480: sh          $t4, 0x11E($sp)
    MEM_H(0X11E, ctx->r29) = ctx->r12;
    // 0x80028484: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80028488: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002848C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028490: nop

    // 0x80028494: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028498: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002849C: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800284A0: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x800284A4: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800284A8: addu        $t9, $t5, $v0
    ctx->r25 = ADD32(ctx->r13, ctx->r2);
    // 0x800284AC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800284B0: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
    // 0x800284B4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800284B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800284BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800284C0: nop

    // 0x800284C4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800284C8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800284CC: nop

    // 0x800284D0: nop

    // 0x800284D4: lwc1        $f14, 0xB4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800284D8: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800284DC: add.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x800284E0: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800284E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800284E8: addu        $t5, $t8, $v1
    ctx->r13 = ADD32(ctx->r24, ctx->r3);
    // 0x800284EC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800284F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800284F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800284F8: sh          $t5, 0x120($sp)
    MEM_H(0X120, ctx->r29) = ctx->r13;
    // 0x800284FC: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028500: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80028504: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028508: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8002850C: add.s       $f2, $f16, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f16.fl;
    // 0x80028510: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80028514: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80028518: sh          $t8, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r24;
    // 0x8002851C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80028520: addiu       $s3, $s3, -0x49E0
    ctx->r19 = ADD32(ctx->r19, -0X49E0);
    // 0x80028524: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80028528: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002852C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028530: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80028534: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80028538: addiu       $a1, $a1, -0x49DC
    ctx->r5 = ADD32(ctx->r5, -0X49DC);
    // 0x8002853C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80028540: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80028544: sub.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80028548: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8002854C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80028550: sh          $t7, 0x122($sp)
    MEM_H(0X122, ctx->r29) = ctx->r15;
    // 0x80028554: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80028558: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002855C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028560: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80028564: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028568: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002856C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80028570: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80028574: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x80028578: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002857C: sh          $t6, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r14;
    // 0x80028580: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80028584: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028588: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002858C: nop

    // 0x80028590: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80028594: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80028598: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002859C: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x800285A0: jal         0x80068648
    // 0x800285A4: sh          $t4, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r12;
    mtx_world_origin(rdram, ctx);
        goto after_3;
    // 0x800285A4: sh          $t4, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r12;
    after_3:
    // 0x800285A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800285AC: lw          $a0, -0x3174($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3174);
    // 0x800285B0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800285B4: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x800285B8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800285BC: beq         $t2, $v1, L_800285DC
    if (ctx->r10 == ctx->r3) {
        // 0x800285C0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800285DC;
    }
    // 0x800285C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800285C4: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x800285C8: nop

    // 0x800285CC: bne         $v0, $v1, L_800285E4
    if (ctx->r2 != ctx->r3) {
        // 0x800285D0: nop
    
            goto L_800285E4;
    }
    // 0x800285D0: nop

    // 0x800285D4: b           L_800285E4
    // 0x800285D8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800285E4;
    // 0x800285D8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800285DC:
    // 0x800285DC: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800285E0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_800285E4:
    // 0x800285E4: beq         $t2, $zero, L_80028600
    if (ctx->r10 == 0) {
        // 0x800285E8: addiu       $a3, $zero, -0x100
        ctx->r7 = ADD32(0, -0X100);
            goto L_80028600;
    }
    // 0x800285E8: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x800285EC: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    // 0x800285F0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800285F4: and         $t6, $a3, $at
    ctx->r14 = ctx->r7 & ctx->r1;
    // 0x800285F8: lw          $a2, 0x10($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X10);
    // 0x800285FC: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_80028600:
    // 0x80028600: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80028604: jal         0x8007F9E4
    // 0x80028608: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    gfx_init_basic_xlu(rdram, ctx);
        goto after_4;
    // 0x80028608: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    after_4:
    // 0x8002860C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80028610: lw          $a1, -0x4970($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4970);
    // 0x80028614: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80028618: sll         $t7, $a1, 8
    ctx->r15 = S32(ctx->r5 << 8);
    // 0x8002861C: jal         0x8007B8BC
    // 0x80028620: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    set_animated_texture_header(rdram, ctx);
        goto after_5;
    // 0x80028620: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_5:
    // 0x80028624: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80028628: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8002862C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80028630: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x80028634: lh          $a1, 0xA($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XA);
    // 0x80028638: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8002863C: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x80028640: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x80028644: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80028648: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8002864C: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x80028650: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80028654: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80028658: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x8002865C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80028660: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80028664: addu        $t9, $t5, $t1
    ctx->r25 = ADD32(ctx->r13, ctx->r9);
    // 0x80028668: addiu       $t3, $t3, -0x49D8
    ctx->r11 = ADD32(ctx->r11, -0X49D8);
    // 0x8002866C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80028670: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80028674: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80028678: addu        $t7, $t4, $t1
    ctx->r15 = ADD32(ctx->r12, ctx->r9);
    // 0x8002867C: andi        $t8, $t7, 0x6
    ctx->r24 = ctx->r15 & 0X6;
    // 0x80028680: ori         $t5, $t8, 0x40
    ctx->r13 = ctx->r24 | 0X40;
    // 0x80028684: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80028688: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8002868C: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x80028690: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80028694: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80028698: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x8002869C: ori         $t7, $t4, 0xAA
    ctx->r15 = ctx->r12 | 0XAA;
    // 0x800286A0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800286A4: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800286A8: lui         $t6, 0x571
    ctx->r14 = S32(0X571 << 16);
    // 0x800286AC: addu        $t5, $t8, $t1
    ctx->r13 = ADD32(ctx->r24, ctx->r9);
    // 0x800286B0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800286B4: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800286B8: ori         $t6, $t6, 0x80
    ctx->r14 = ctx->r14 | 0X80;
    // 0x800286BC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800286C0: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x800286C4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800286C8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800286CC: lw          $t4, -0x49D4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X49D4);
    // 0x800286D0: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800286D4: addu        $t7, $t4, $t1
    ctx->r15 = ADD32(ctx->r12, ctx->r9);
    // 0x800286D8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800286DC: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800286E0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800286E4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800286E8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800286EC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800286F0: beq         $t2, $zero, L_8002872C
    if (ctx->r10 == 0) {
        // 0x800286F4: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_8002872C;
    }
    // 0x800286F4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800286F8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800286FC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80028700: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80028704: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80028708: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8002870C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80028710: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80028714: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80028718: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8002871C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80028720: addiu       $t5, $zero, -0x100
    ctx->r13 = ADD32(0, -0X100);
    // 0x80028724: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80028728: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8002872C:
    // 0x8002872C: jal         0x8007B820
    // 0x80028730: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_6;
    // 0x80028730: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x80028734: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x80028738: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002873C: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80028740: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    // 0x80028744: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80028748: addiu       $v0, $sp, 0xB8
    ctx->r2 = ADD32(ctx->r29, 0XB8);
    // 0x8002874C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028750: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    // 0x80028754: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028758: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002875C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028760: addiu       $a2, $sp, 0xCC
    ctx->r6 = ADD32(ctx->r29, 0XCC);
    // 0x80028764: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80028768: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8002876C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80028770: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028774: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80028778: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
L_8002877C:
    // 0x8002877C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80028780: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80028784: sh          $a1, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r5;
    // 0x80028788: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002878C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80028790: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80028794: nop

    // 0x80028798: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002879C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800287A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800287A4: nop

    // 0x800287A8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800287AC: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800287B0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800287B4: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
    // 0x800287B8: lwc1        $f10, 0x14($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800287BC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800287C0: sb          $v1, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r3;
    // 0x800287C4: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800287C8: sb          $v1, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r3;
    // 0x800287CC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800287D0: sb          $v1, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r3;
    // 0x800287D4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800287D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800287DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800287E0: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800287E4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800287E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800287EC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800287F0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800287F4: beq         $at, $zero, L_80028804
    if (ctx->r1 == 0) {
        // 0x800287F8: sh          $t9, 0x4($s1)
        MEM_H(0X4, ctx->r17) = ctx->r25;
            goto L_80028804;
    }
    // 0x800287F8: sh          $t9, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r25;
    // 0x800287FC: b           L_80028808
    // 0x80028800: sb          $v1, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r3;
        goto L_80028808;
    // 0x80028800: sb          $v1, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r3;
L_80028804:
    // 0x80028804: sb          $zero, 0x9($s1)
    MEM_B(0X9, ctx->r17) = 0;
L_80028808:
    // 0x80028808: sltu        $at, $v0, $a3
    ctx->r1 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x8002880C: bne         $at, $zero, L_8002877C
    if (ctx->r1 != 0) {
        // 0x80028810: addiu       $s1, $s1, 0xA
        ctx->r17 = ADD32(ctx->r17, 0XA);
            goto L_8002877C;
    }
    // 0x80028810: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80028814: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80028818: addiu       $v0, $v0, -0x3164
    ctx->r2 = ADD32(ctx->r2, -0X3164);
    // 0x8002881C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80028820: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80028824: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80028828: addiu       $a0, $sp, 0x114
    ctx->r4 = ADD32(ctx->r29, 0X114);
    // 0x8002882C: addiu       $v1, $sp, 0x128
    ctx->r3 = ADD32(ctx->r29, 0X128);
L_80028830:
    // 0x80028830: sb          $a1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r5;
    // 0x80028834: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80028838: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002883C: sb          $t6, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r14;
    // 0x80028840: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80028844: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80028848: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x8002884C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80028850: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x80028854: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80028858: sh          $t5, -0x1C($s0)
    MEM_H(-0X1C, ctx->r16) = ctx->r13;
    // 0x8002885C: lbu         $t9, -0x6($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X6);
    // 0x80028860: nop

    // 0x80028864: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80028868: addu        $t4, $a0, $t6
    ctx->r12 = ADD32(ctx->r4, ctx->r14);
    // 0x8002886C: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x80028870: nop

    // 0x80028874: sh          $t7, -0x1A($s0)
    MEM_H(-0X1A, ctx->r16) = ctx->r15;
    // 0x80028878: lbu         $t8, -0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X5);
    // 0x8002887C: nop

    // 0x80028880: sb          $t8, -0x1E($s0)
    MEM_B(-0X1E, ctx->r16) = ctx->r24;
    // 0x80028884: lbu         $t5, -0x5($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X5);
    // 0x80028888: nop

    // 0x8002888C: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x80028890: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x80028894: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80028898: nop

    // 0x8002889C: sh          $t4, -0x18($s0)
    MEM_H(-0X18, ctx->r16) = ctx->r12;
    // 0x800288A0: lbu         $t7, -0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X5);
    // 0x800288A4: nop

    // 0x800288A8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800288AC: addu        $t5, $a0, $t8
    ctx->r13 = ADD32(ctx->r4, ctx->r24);
    // 0x800288B0: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x800288B4: nop

    // 0x800288B8: sh          $t9, -0x16($s0)
    MEM_H(-0X16, ctx->r16) = ctx->r25;
    // 0x800288BC: lbu         $t6, -0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X4);
    // 0x800288C0: nop

    // 0x800288C4: sb          $t6, -0x1D($s0)
    MEM_B(-0X1D, ctx->r16) = ctx->r14;
    // 0x800288C8: lbu         $t4, -0x4($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X4);
    // 0x800288CC: nop

    // 0x800288D0: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x800288D4: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800288D8: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x800288DC: nop

    // 0x800288E0: sh          $t5, -0x14($s0)
    MEM_H(-0X14, ctx->r16) = ctx->r13;
    // 0x800288E4: lbu         $t9, -0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X4);
    // 0x800288E8: nop

    // 0x800288EC: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800288F0: addu        $t4, $a0, $t6
    ctx->r12 = ADD32(ctx->r4, ctx->r14);
    // 0x800288F4: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x800288F8: sb          $a1, -0x10($s0)
    MEM_B(-0X10, ctx->r16) = ctx->r5;
    // 0x800288FC: sh          $t7, -0x12($s0)
    MEM_H(-0X12, ctx->r16) = ctx->r15;
    // 0x80028900: lbu         $t8, -0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X3);
    // 0x80028904: nop

    // 0x80028908: sb          $t8, -0xF($s0)
    MEM_B(-0XF, ctx->r16) = ctx->r24;
    // 0x8002890C: lbu         $t5, -0x3($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X3);
    // 0x80028910: nop

    // 0x80028914: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x80028918: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x8002891C: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80028920: nop

    // 0x80028924: sh          $t4, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r12;
    // 0x80028928: lbu         $t7, -0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X3);
    // 0x8002892C: nop

    // 0x80028930: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80028934: addu        $t5, $a0, $t8
    ctx->r13 = ADD32(ctx->r4, ctx->r24);
    // 0x80028938: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x8002893C: nop

    // 0x80028940: sh          $t9, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r25;
    // 0x80028944: lbu         $t6, -0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X2);
    // 0x80028948: nop

    // 0x8002894C: sb          $t6, -0xE($s0)
    MEM_B(-0XE, ctx->r16) = ctx->r14;
    // 0x80028950: lbu         $t4, -0x2($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X2);
    // 0x80028954: nop

    // 0x80028958: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x8002895C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80028960: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x80028964: nop

    // 0x80028968: sh          $t5, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r13;
    // 0x8002896C: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x80028970: nop

    // 0x80028974: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80028978: addu        $t4, $a0, $t6
    ctx->r12 = ADD32(ctx->r4, ctx->r14);
    // 0x8002897C: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x80028980: nop

    // 0x80028984: sh          $t7, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r15;
    // 0x80028988: lbu         $t8, -0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X1);
    // 0x8002898C: nop

    // 0x80028990: sb          $t8, -0xD($s0)
    MEM_B(-0XD, ctx->r16) = ctx->r24;
    // 0x80028994: lbu         $t5, -0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X1);
    // 0x80028998: nop

    // 0x8002899C: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x800289A0: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x800289A4: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x800289A8: nop

    // 0x800289AC: sh          $t4, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r12;
    // 0x800289B0: lbu         $t7, -0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X1);
    // 0x800289B4: nop

    // 0x800289B8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800289BC: addu        $t5, $a0, $t8
    ctx->r13 = ADD32(ctx->r4, ctx->r24);
    // 0x800289C0: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x800289C4: bne         $a2, $a3, L_80028830
    if (ctx->r6 != ctx->r7) {
        // 0x800289C8: sh          $t9, -0x2($s0)
        MEM_H(-0X2, ctx->r16) = ctx->r25;
            goto L_80028830;
    }
    // 0x800289C8: sh          $t9, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r25;
    // 0x800289CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800289D0: sw          $s1, -0x49D8($at)
    MEM_W(-0X49D8, ctx->r1) = ctx->r17;
    // 0x800289D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800289D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800289DC: sw          $s0, -0x49D4($at)
    MEM_W(-0X49D4, ctx->r1) = ctx->r16;
    // 0x800289E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800289E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800289E8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800289EC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800289F0: jr          $ra
    // 0x800289F4: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    return;
    // 0x800289F4: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
;}
RECOMP_FUNC void trackbg_render_gradient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800289F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800289FC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80028A00: lw          $v0, -0x3174($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3174);
    // 0x80028A04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028A08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80028A0C: lbu         $t6, 0xC1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC1);
    // 0x80028A10: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028A14: sb          $t6, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r14;
    // 0x80028A18: lbu         $t7, 0xC2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC2);
    // 0x80028A1C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80028A20: sb          $t7, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r15;
    // 0x80028A24: lbu         $t8, 0xC3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XC3);
    // 0x80028A28: lw          $v1, -0x49D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X49D8);
    // 0x80028A2C: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x80028A30: lbu         $t9, 0xBE($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XBE);
    // 0x80028A34: lw          $a3, -0x49D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X49D4);
    // 0x80028A38: sb          $t9, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r25;
    // 0x80028A3C: lbu         $t6, 0xBF($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XBF);
    // 0x80028A40: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80028A44: sb          $t6, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r14;
    // 0x80028A48: lbu         $t7, 0xC0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC0);
    // 0x80028A4C: addiu       $s0, $s0, -0x49E0
    ctx->r16 = ADD32(ctx->r16, -0X49E0);
    // 0x80028A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80028A54: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80028A58: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80028A5C: jal         0x8007B820
    // 0x80028A60: sb          $t7, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x80028A60: sb          $t7, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r15;
    after_0:
    // 0x80028A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80028A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80028A6C: jal         0x8007B918
    // 0x80028A70: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    material_set_no_tex_offset(rdram, ctx);
        goto after_1;
    // 0x80028A70: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80028A74: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80028A78: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80028A7C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80028A80: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    // 0x80028A84: andi        $t9, $a1, 0x6
    ctx->r25 = ctx->r5 & 0X6;
    // 0x80028A88: ori         $t6, $t9, 0x18
    ctx->r14 = ctx->r25 | 0X18;
    // 0x80028A8C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80028A90: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80028A94: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80028A98: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80028A9C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80028AA0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80028AA4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80028AA8: ori         $t6, $t9, 0x50
    ctx->r14 = ctx->r25 | 0X50;
    // 0x80028AAC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80028AB0: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80028AB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80028AB8: lui         $t8, 0x510
    ctx->r24 = S32(0X510 << 16);
    // 0x80028ABC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80028AC0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80028AC4: ori         $t8, $t8, 0x20
    ctx->r24 = ctx->r24 | 0X20;
    // 0x80028AC8: addu        $t9, $a3, $t0
    ctx->r25 = ADD32(ctx->r7, ctx->r8);
    // 0x80028ACC: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80028AD0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80028AD4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80028AD8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80028ADC: addiu       $s0, $zero, -0x96
    ctx->r16 = ADD32(0, -0X96);
    // 0x80028AE0: bne         $t6, $zero, L_80028AF4
    if (ctx->r14 != 0) {
        // 0x80028AE4: addiu       $a0, $zero, 0x96
        ctx->r4 = ADD32(0, 0X96);
            goto L_80028AF4;
    }
    // 0x80028AE4: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80028AE8: addiu       $s0, $zero, -0xB4
    ctx->r16 = ADD32(0, -0XB4);
    // 0x80028AEC: b           L_80028AF4
    // 0x80028AF0: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
        goto L_80028AF4;
    // 0x80028AF0: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
L_80028AF4:
    // 0x80028AF4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80028AF8: sh          $a0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r4;
    // 0x80028AFC: jal         0x80066450
    // 0x80028B00: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    cam_get_viewport_layout(rdram, ctx);
        goto after_2;
    // 0x80028B00: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x80028B04: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80028B08: lh          $a0, 0x30($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X30);
    // 0x80028B0C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80028B10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80028B14: bne         $v0, $at, L_80028B34
    if (ctx->r2 != ctx->r1) {
        // 0x80028B18: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80028B34;
    }
    // 0x80028B18: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80028B1C: sra         $t7, $s0, 1
    ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80028B20: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80028B24: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80028B28: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80028B2C: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80028B30: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
L_80028B34:
    // 0x80028B34: lbu         $t1, 0x2F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2F);
    // 0x80028B38: lbu         $t2, 0x2E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2E);
    // 0x80028B3C: lbu         $t3, 0x2D($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X2D);
    // 0x80028B40: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80028B44: addiu       $a2, $zero, -0xC8
    ctx->r6 = ADD32(0, -0XC8);
    // 0x80028B48: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x80028B4C: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x80028B50: sh          $s0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r16;
    // 0x80028B54: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x80028B58: sb          $a1, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r5;
    // 0x80028B5C: sh          $t0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r8;
    // 0x80028B60: sh          $s0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r16;
    // 0x80028B64: sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
    // 0x80028B68: sb          $t1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r9;
    // 0x80028B6C: sb          $t1, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r9;
    // 0x80028B70: sb          $t2, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r10;
    // 0x80028B74: sb          $t3, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r11;
    // 0x80028B78: lbu         $ra, 0x2A($sp)
    ctx->r31 = MEM_BU(ctx->r29, 0X2A);
    // 0x80028B7C: lbu         $t5, 0x2B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2B);
    // 0x80028B80: lbu         $t4, 0x2C($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2C);
    // 0x80028B84: sh          $a2, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r6;
    // 0x80028B88: sh          $t0, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r8;
    // 0x80028B8C: sb          $a1, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r5;
    // 0x80028B90: sh          $a0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r4;
    // 0x80028B94: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    // 0x80028B98: sb          $a1, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r5;
    // 0x80028B9C: sh          $a0, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r4;
    // 0x80028BA0: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x80028BA4: sb          $a1, 0x27($v1)
    MEM_B(0X27, ctx->r3) = ctx->r5;
    // 0x80028BA8: sb          $t2, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r10;
    // 0x80028BAC: sb          $t3, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r11;
    // 0x80028BB0: sb          $ra, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r31;
    // 0x80028BB4: sb          $ra, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r31;
    // 0x80028BB8: sb          $t5, 0x1B($v1)
    MEM_B(0X1B, ctx->r3) = ctx->r13;
    // 0x80028BBC: sb          $t5, 0x25($v1)
    MEM_B(0X25, ctx->r3) = ctx->r13;
    // 0x80028BC0: sb          $t4, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r12;
    // 0x80028BC4: sb          $t4, 0x24($v1)
    MEM_B(0X24, ctx->r3) = ctx->r12;
    // 0x80028BC8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80028BCC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80028BD0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80028BD4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80028BD8: sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // 0x80028BDC: sb          $t0, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r8;
    // 0x80028BE0: sb          $t1, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r9;
    // 0x80028BE4: sb          $zero, 0x3($a3)
    MEM_B(0X3, ctx->r7) = 0;
    // 0x80028BE8: sh          $zero, 0x4($a3)
    MEM_H(0X4, ctx->r7) = 0;
    // 0x80028BEC: sh          $zero, 0x6($a3)
    MEM_H(0X6, ctx->r7) = 0;
    // 0x80028BF0: sh          $zero, 0x8($a3)
    MEM_H(0X8, ctx->r7) = 0;
    // 0x80028BF4: sh          $zero, 0xA($a3)
    MEM_H(0XA, ctx->r7) = 0;
    // 0x80028BF8: sh          $zero, 0xC($a3)
    MEM_H(0XC, ctx->r7) = 0;
    // 0x80028BFC: sh          $zero, 0xE($a3)
    MEM_H(0XE, ctx->r7) = 0;
    // 0x80028C00: sb          $a2, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r6;
    // 0x80028C04: sb          $t9, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r25;
    // 0x80028C08: sb          $t0, 0x12($a3)
    MEM_B(0X12, ctx->r7) = ctx->r8;
    // 0x80028C0C: sb          $t1, 0x13($a3)
    MEM_B(0X13, ctx->r7) = ctx->r9;
    // 0x80028C10: sh          $zero, 0x14($a3)
    MEM_H(0X14, ctx->r7) = 0;
    // 0x80028C14: sh          $zero, 0x16($a3)
    MEM_H(0X16, ctx->r7) = 0;
    // 0x80028C18: sh          $zero, 0x18($a3)
    MEM_H(0X18, ctx->r7) = 0;
    // 0x80028C1C: sh          $zero, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = 0;
    // 0x80028C20: sh          $zero, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = 0;
    // 0x80028C24: sh          $zero, 0x1E($a3)
    MEM_H(0X1E, ctx->r7) = 0;
    // 0x80028C28: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
    // 0x80028C2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028C34: sw          $v1, -0x49D8($at)
    MEM_W(-0X49D8, ctx->r1) = ctx->r3;
    // 0x80028C38: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x80028C3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028C40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80028C44: sw          $a3, -0x49D4($at)
    MEM_W(-0X49D4, ctx->r1) = ctx->r7;
    // 0x80028C48: jr          $ra
    // 0x80028C4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80028C4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void skydome_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028C50: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028C54: addiu       $v1, $v1, -0x49C8
    ctx->r3 = ADD32(ctx->r3, -0X49C8);
    // 0x80028C58: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80028C5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028C60: beq         $t6, $zero, L_80028D00
    if (ctx->r14 == 0) {
        // 0x80028C64: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80028D00;
    }
    // 0x80028C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028C68: jal         0x80069F60
    // 0x80028C6C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x80028C6C: nop

    after_0:
    // 0x80028C70: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80028C74: lw          $t7, -0x3174($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3174);
    // 0x80028C78: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028C7C: lb          $t8, 0x49($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X49);
    // 0x80028C80: addiu       $v1, $v1, -0x49C8
    ctx->r3 = ADD32(ctx->r3, -0X49C8);
    // 0x80028C84: bne         $t8, $zero, L_80028CBC
    if (ctx->r24 != 0) {
        // 0x80028C88: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80028CBC;
    }
    // 0x80028C88: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80028C8C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80028C90: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80028C94: nop

    // 0x80028C98: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x80028C9C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80028CA0: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80028CA4: nop

    // 0x80028CA8: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
    // 0x80028CAC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80028CB0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80028CB4: nop

    // 0x80028CB8: swc1        $f8, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f8.u32l;
L_80028CBC:
    // 0x80028CBC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80028CC0: addiu       $a1, $a1, -0x49DC
    ctx->r5 = ADD32(ctx->r5, -0X49DC);
    // 0x80028CC4: jal         0x80068648
    // 0x80028CC8: addiu       $a0, $a0, -0x49E0
    ctx->r4 = ADD32(ctx->r4, -0X49E0);
    mtx_world_origin(rdram, ctx);
        goto after_1;
    // 0x80028CC8: addiu       $a0, $a0, -0x49E0
    ctx->r4 = ADD32(ctx->r4, -0X49E0);
    after_1:
    // 0x80028CCC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80028CD0: lw          $t2, -0x49A4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X49A4);
    // 0x80028CD4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028CD8: beq         $t2, $zero, L_80028D00
    if (ctx->r10 == 0) {
        // 0x80028CDC: addiu       $v1, $v1, -0x49C8
        ctx->r3 = ADD32(ctx->r3, -0X49C8);
            goto L_80028D00;
    }
    // 0x80028CDC: addiu       $v1, $v1, -0x49C8
    ctx->r3 = ADD32(ctx->r3, -0X49C8);
    // 0x80028CE0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80028CE4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80028CE8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80028CEC: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x80028CF0: addiu       $a2, $a2, -0x49D8
    ctx->r6 = ADD32(ctx->r6, -0X49D8);
    // 0x80028CF4: addiu       $a1, $a1, -0x49DC
    ctx->r5 = ADD32(ctx->r5, -0X49DC);
    // 0x80028CF8: jal         0x80012D5C
    // 0x80028CFC: addiu       $a0, $a0, -0x49E0
    ctx->r4 = ADD32(ctx->r4, -0X49E0);
    render_object(rdram, ctx);
        goto after_2;
    // 0x80028CFC: addiu       $a0, $a0, -0x49E0
    ctx->r4 = ADD32(ctx->r4, -0X49E0);
    after_2:
L_80028D00:
    // 0x80028D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028D08: jr          $ra
    // 0x80028D0C: nop

    return;
    // 0x80028D0C: nop

;}
RECOMP_FUNC void initialise_player_viewport_vars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028D10: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80028D14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028D18: jal         0x80069F60
    // 0x80028D1C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x80028D1C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80028D20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028D24: jal         0x80066460
    // 0x80028D28: sw          $v0, -0x49D0($at)
    MEM_W(-0X49D0, ctx->r1) = ctx->r2;
    get_current_viewport(rdram, ctx);
        goto after_1;
    // 0x80028D28: sw          $v0, -0x49D0($at)
    MEM_W(-0X49D0, ctx->r1) = ctx->r2;
    after_1:
    // 0x80028D2C: jal         0x80031058
    // 0x80028D30: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    compute_scene_camera_transform_matrix(rdram, ctx);
        goto after_2;
    // 0x80028D30: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80028D34: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80028D38: addiu       $v0, $v0, -0x2618
    ctx->r2 = ADD32(ctx->r2, -0X2618);
    // 0x80028D3C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80028D40: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80028D44: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80028D48: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80028D4C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80028D50: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80028D54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80028D58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80028D5C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80028D60: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80028D64: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80028D68: nop

    // 0x80028D6C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80028D70: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80028D74: div.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80028D78: jal         0x8001D614
    // 0x80028D7C: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    update_envmap_position(rdram, ctx);
        goto after_3;
    // 0x80028D7C: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    after_3:
    // 0x80028D80: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028D84: lw          $v1, -0x49D0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X49D0);
    // 0x80028D88: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80028D8C: lh          $v0, 0x34($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X34);
    // 0x80028D90: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80028D94: bltz        $v0, L_80028DD0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80028D98: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80028DD0;
    }
    // 0x80028D98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80028D9C: lw          $a0, -0x3178($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3178);
    // 0x80028DA0: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x80028DA4: lh          $t9, 0x1A($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X1A);
    // 0x80028DA8: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80028DAC: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80028DB0: beq         $at, $zero, L_80028DD0
    if (ctx->r1 == 0) {
        // 0x80028DB4: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80028DD0;
    }
    // 0x80028DB4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80028DB8: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x80028DBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028DC0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80028DC4: lh          $t4, 0x28($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X28);
    // 0x80028DC8: b           L_80028DDC
    // 0x80028DCC: sw          $t4, -0x49AC($at)
    MEM_W(-0X49AC, ctx->r1) = ctx->r12;
        goto L_80028DDC;
    // 0x80028DCC: sw          $t4, -0x49AC($at)
    MEM_W(-0X49AC, ctx->r1) = ctx->r12;
L_80028DD0:
    // 0x80028DD0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80028DD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028DD8: sw          $t5, -0x49AC($at)
    MEM_W(-0X49AC, ctx->r1) = ctx->r13;
L_80028DDC:
    // 0x80028DDC: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80028DE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028DE4: swc1        $f6, -0x276C($at)
    MEM_W(-0X276C, ctx->r1) = ctx->f6.u32l;
    // 0x80028DE8: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80028DEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028DF0: swc1        $f8, -0x2768($at)
    MEM_W(-0X2768, ctx->r1) = ctx->f8.u32l;
    // 0x80028DF4: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80028DF8: lw          $t6, -0x26FC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26FC);
    // 0x80028DFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028E00: beq         $t6, $zero, L_80028FBC
    if (ctx->r14 == 0) {
        // 0x80028E04: swc1        $f10, -0x2764($at)
        MEM_W(-0X2764, ctx->r1) = ctx->f10.u32l;
            goto L_80028FBC;
    }
    // 0x80028E04: swc1        $f10, -0x2764($at)
    MEM_W(-0X2764, ctx->r1) = ctx->f10.u32l;
    // 0x80028E08: jal         0x800B90AC
    // 0x80028E0C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    waves_visibility_reset(rdram, ctx);
        goto after_4;
    // 0x80028E0C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80028E10: jal         0x8001BAA8
    // 0x80028E14: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    get_racer_objects(rdram, ctx);
        goto after_5;
    // 0x80028E14: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x80028E18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80028E1C: lw          $t7, -0x49D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X49D0);
    // 0x80028E20: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80028E24: lh          $t8, 0x36($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X36);
    // 0x80028E28: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80028E2C: beq         $t8, $at, L_80028F2C
    if (ctx->r24 == ctx->r1) {
        // 0x80028E30: nop
    
            goto L_80028F2C;
    }
    // 0x80028E30: nop

    // 0x80028E34: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80028E38: nop

    // 0x80028E3C: blez        $t9, L_80028F2C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80028E40: nop
    
            goto L_80028F2C;
    }
    // 0x80028E40: nop

    // 0x80028E44: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80028E48: jal         0x80066750
    // 0x80028E4C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_6;
    // 0x80028E4C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80028E50: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80028E54: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80028E58: bne         $v0, $zero, L_80028F2C
    if (ctx->r2 != 0) {
        // 0x80028E5C: addiu       $v1, $a0, -0x4
        ctx->r3 = ADD32(ctx->r4, -0X4);
            goto L_80028F2C;
    }
    // 0x80028E5C: addiu       $v1, $a0, -0x4
    ctx->r3 = ADD32(ctx->r4, -0X4);
    // 0x80028E60: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80028E64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80028E68: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_80028E6C:
    // 0x80028E6C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80028E70: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80028E74: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80028E78: lw          $a0, 0x64($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X64);
    // 0x80028E7C: beq         $at, $zero, L_80028E94
    if (ctx->r1 == 0) {
        // 0x80028E80: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80028E94;
    }
    // 0x80028E80: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80028E84: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x80028E88: nop

    // 0x80028E8C: bne         $a3, $t2, L_80028E6C
    if (ctx->r7 != ctx->r10) {
        // 0x80028E90: nop
    
            goto L_80028E6C;
    }
    // 0x80028E90: nop

L_80028E94:
    // 0x80028E94: jal         0x80066460
    // 0x80028E98: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    get_current_viewport(rdram, ctx);
        goto after_7;
    // 0x80028E98: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_7:
    // 0x80028E9C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80028EA0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80028EA4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80028EA8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80028EAC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028EB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028EB4: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80028EB8: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80028EBC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80028EC0: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80028EC4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80028EC8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80028ECC: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80028ED0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80028ED4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80028ED8: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80028EDC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028EE0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028EE4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80028EE8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028EEC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80028EF0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80028EF4: nop

    // 0x80028EF8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80028EFC: nop

    // 0x80028F00: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80028F04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028F08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028F0C: nop

    // 0x80028F10: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028F14: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80028F18: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80028F1C: jal         0x800B9124
    // 0x80028F20: nop

    waves_visibility(rdram, ctx);
        goto after_8;
    // 0x80028F20: nop

    after_8:
    // 0x80028F24: b           L_80028FBC
    // 0x80028F28: nop

        goto L_80028FBC;
    // 0x80028F28: nop

L_80028F2C:
    // 0x80028F2C: jal         0x80066460
    // 0x80028F30: nop

    get_current_viewport(rdram, ctx);
        goto after_9;
    // 0x80028F30: nop

    after_9:
    // 0x80028F34: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80028F38: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028F3C: lw          $v1, -0x49D0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X49D0);
    // 0x80028F40: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80028F44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028F48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028F4C: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80028F50: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80028F54: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80028F58: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80028F5C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80028F60: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80028F64: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80028F68: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80028F6C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80028F70: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80028F74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028F78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028F7C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80028F80: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028F84: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80028F88: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80028F8C: nop

    // 0x80028F90: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028F94: nop

    // 0x80028F98: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028F9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028FA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028FA4: nop

    // 0x80028FA8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028FAC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80028FB0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028FB4: jal         0x800B9124
    // 0x80028FB8: nop

    waves_visibility(rdram, ctx);
        goto after_10;
    // 0x80028FB8: nop

    after_10:
L_80028FBC:
    // 0x80028FBC: jal         0x8006BFF0
    // 0x80028FC0: nop

    level_header(rdram, ctx);
        goto after_11;
    // 0x80028FC0: nop

    after_11:
    // 0x80028FC4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80028FC8: jal         0x80028FEC
    // 0x80028FCC: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
    render_level_geometry_and_objects(rdram, ctx);
        goto after_12;
    // 0x80028FCC: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
    after_12:
    // 0x80028FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028FD4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80028FD8: jr          $ra
    // 0x80028FDC: nop

    return;
    // 0x80028FDC: nop

;}
RECOMP_FUNC void set_anti_aliasing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028FE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028FE4: jr          $ra
    // 0x80028FE8: sw          $a0, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = ctx->r4;
    return;
    // 0x80028FE8: sw          $a0, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void render_level_geometry_and_objects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028FEC: addiu       $sp, $sp, -0x170
    ctx->r29 = ADD32(ctx->r29, -0X170);
    // 0x80028FF0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80028FF4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80028FF8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80028FFC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80029000: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80029004: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80029008: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002900C: jal         0x80012C30
    // 0x80029010: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    func_80012C30(rdram, ctx);
        goto after_0;
    // 0x80029010: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x80029014: jal         0x8006ECD0
    // 0x80029018: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x80029018: nop

    after_1:
    // 0x8002901C: lbu         $t6, 0x49($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X49);
    // 0x80029020: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80029024: bne         $t6, $at, L_80029034
    if (ctx->r14 != ctx->r1) {
        // 0x80029028: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80029034;
    }
    // 0x80029028: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002902C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80029030: sw          $t7, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = ctx->r15;
L_80029034:
    // 0x80029034: jal         0x80014814
    // 0x80029038: addiu       $a0, $sp, 0x16C
    ctx->r4 = ADD32(ctx->r29, 0X16C);
    get_first_active_object(rdram, ctx);
        goto after_2;
    // 0x80029038: addiu       $a0, $sp, 0x16C
    ctx->r4 = ADD32(ctx->r29, 0X16C);
    after_2:
    // 0x8002903C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80029040: lw          $s0, -0x3178($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X3178);
    // 0x80029044: sw          $v0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r2;
    // 0x80029048: lh          $t8, 0x1A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A);
    // 0x8002904C: nop

    // 0x80029050: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80029054: bne         $at, $zero, L_80029094
    if (ctx->r1 != 0) {
        // 0x80029058: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80029094;
    }
    // 0x80029058: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002905C: sw          $zero, 0x168($sp)
    MEM_W(0X168, ctx->r29) = 0;
    // 0x80029060: lh          $a2, 0x1A($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X1A);
    // 0x80029064: addiu       $t9, $sp, 0x168
    ctx->r25 = ADD32(ctx->r29, 0X168);
    // 0x80029068: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002906C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029074: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    // 0x80029078: jal         0x80029B38
    // 0x8002907C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    traverse_segments_bsp_tree(rdram, ctx);
        goto after_3;
    // 0x8002907C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_3:
    // 0x80029080: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80029084: lw          $s0, -0x3178($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X3178);
    // 0x80029088: b           L_800290A0
    // 0x8002908C: lh          $t1, 0x1A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A);
        goto L_800290A0;
    // 0x8002908C: lh          $t1, 0x1A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A);
    // 0x80029090: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80029094:
    // 0x80029094: sw          $t0, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r8;
    // 0x80029098: sb          $zero, 0xD8($sp)
    MEM_B(0XD8, ctx->r29) = 0;
    // 0x8002909C: lh          $t1, 0x1A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A);
L_800290A0:
    // 0x800290A0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800290A4: blez        $t1, L_800290C8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800290A8: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800290C8;
    }
    // 0x800290A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800290AC: addiu       $v0, $sp, 0x59
    ctx->r2 = ADD32(ctx->r29, 0X59);
L_800290B0:
    // 0x800290B0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800290B4: lh          $t2, 0x1A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A);
    // 0x800290B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800290BC: slt         $at, $t2, $s2
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800290C0: beq         $at, $zero, L_800290B0
    if (ctx->r1 == 0) {
        // 0x800290C4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800290B0;
    }
    // 0x800290C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800290C8:
    // 0x800290C8: lb          $t4, -0x49A0($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X49A0);
    // 0x800290CC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800290D0: beq         $t4, $zero, L_8002912C
    if (ctx->r12 == 0) {
        // 0x800290D4: sb          $t3, 0x58($sp)
        MEM_B(0X58, ctx->r29) = ctx->r11;
            goto L_8002912C;
    }
    // 0x800290D4: sb          $t3, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r11;
    // 0x800290D8: lw          $t5, 0x168($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X168);
    // 0x800290DC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800290E0: blez        $t5, L_8002912C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800290E4: addiu       $s6, $sp, 0x58
        ctx->r22 = ADD32(ctx->r29, 0X58);
            goto L_8002912C;
    }
    // 0x800290E4: addiu       $s6, $sp, 0x58
    ctx->r22 = ADD32(ctx->r29, 0X58);
    // 0x800290E8: addiu       $s0, $sp, 0xD8
    ctx->r16 = ADD32(ctx->r29, 0XD8);
    // 0x800290EC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800290F0:
    // 0x800290F0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800290F4: jal         0x80029698
    // 0x800290F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    render_level_segment(rdram, ctx);
        goto after_4;
    // 0x800290F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800290FC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80029100: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80029104: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x80029108: sb          $s1, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r17;
    // 0x8002910C: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x80029110: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80029114: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80029118: bne         $at, $zero, L_800290F0
    if (ctx->r1 != 0) {
        // 0x8002911C: nop
    
            goto L_800290F0;
    }
    // 0x8002911C: nop

    // 0x80029120: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80029124: lw          $s0, -0x3178($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X3178);
    // 0x80029128: nop

L_8002912C:
    // 0x8002912C: lh          $t9, 0x1A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A);
    // 0x80029130: addiu       $s6, $sp, 0x58
    ctx->r22 = ADD32(ctx->r29, 0X58);
    // 0x80029134: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80029138: beq         $at, $zero, L_80029148
    if (ctx->r1 == 0) {
        // 0x8002913C: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_80029148;
    }
    // 0x8002913C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80029140: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80029144: sb          $t0, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r8;
L_80029148:
    // 0x80029148: addiu       $s3, $s3, -0x49E0
    ctx->r19 = ADD32(ctx->r19, -0X49E0);
    // 0x8002914C: jal         0x8007B820
    // 0x80029150: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x80029150: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x80029154: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x80029158: lw          $a0, 0x160($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X160);
    // 0x8002915C: jal         0x80015348
    // 0x80029160: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    sort_objects_by_dist(rdram, ctx);
        goto after_6;
    // 0x80029160: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    after_6:
    // 0x80029164: jal         0x80066460
    // 0x80029168: nop

    get_current_viewport(rdram, ctx);
        goto after_7;
    // 0x80029168: nop

    after_7:
    // 0x8002916C: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x80029170: lw          $s2, 0x160($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X160);
    // 0x80029174: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80029178: addiu       $t2, $zero, 0x200
    ctx->r10 = ADD32(0, 0X200);
    // 0x8002917C: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80029180: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029184: beq         $at, $zero, L_800292E0
    if (ctx->r1 == 0) {
        // 0x80029188: sw          $t3, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r11;
            goto L_800292E0;
    }
    // 0x80029188: sw          $t3, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r11;
    // 0x8002918C: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80029190: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80029194: addiu       $s4, $s4, -0x49DC
    ctx->r20 = ADD32(ctx->r20, -0X49DC);
    // 0x80029198: addiu       $s5, $s5, -0x49D8
    ctx->r21 = ADD32(ctx->r21, -0X49D8);
    // 0x8002919C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800291A0:
    // 0x800291A0: jal         0x8000E948
    // 0x800291A4: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    get_object(rdram, ctx);
        goto after_8;
    // 0x800291A4: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    after_8:
    // 0x800291A8: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x800291AC: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x800291B0: andi        $t5, $v1, 0x80
    ctx->r13 = ctx->r3 & 0X80;
    // 0x800291B4: beq         $t5, $zero, L_800291C4
    if (ctx->r13 == 0) {
        // 0x800291B8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800291C4;
    }
    // 0x800291B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800291BC: b           L_800291D8
    // 0x800291C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800291D8;
    // 0x800291C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800291C4:
    // 0x800291C4: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x800291C8: bne         $t6, $zero, L_800291DC
    if (ctx->r14 != 0) {
        // 0x800291CC: and         $t8, $v1, $t7
        ctx->r24 = ctx->r3 & ctx->r15;
            goto L_800291DC;
    }
    // 0x800291CC: and         $t8, $v1, $t7
    ctx->r24 = ctx->r3 & ctx->r15;
    // 0x800291D0: lbu         $s0, 0x39($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X39);
    // 0x800291D4: nop

L_800291D8:
    // 0x800291D8: and         $t8, $v1, $t7
    ctx->r24 = ctx->r3 & ctx->r15;
L_800291DC:
    // 0x800291DC: beq         $t8, $zero, L_800291E8
    if (ctx->r24 == 0) {
        // 0x800291E0: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_800291E8;
    }
    // 0x800291E0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800291E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800291E8:
    // 0x800291E8: beq         $v0, $zero, L_800292D0
    if (ctx->r2 == 0) {
        // 0x800291EC: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_800292D0;
    }
    // 0x800291EC: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x800291F0: bne         $s0, $at, L_800292D0
    if (ctx->r16 != ctx->r1) {
        // 0x800291F4: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_800292D0;
    }
    // 0x800291F4: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x800291F8: jal         0x8002A940
    // 0x800291FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    check_if_in_draw_range(rdram, ctx);
        goto after_9;
    // 0x800291FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80029200: beq         $v0, $zero, L_800292D0
    if (ctx->r2 == 0) {
        // 0x80029204: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_800292D0;
    }
    // 0x80029204: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x80029208: lh          $t9, 0x2E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2E);
    // 0x8002920C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80029210: addu        $t0, $s6, $t9
    ctx->r8 = ADD32(ctx->r22, ctx->r25);
    // 0x80029214: lbu         $t2, 0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X1);
    // 0x80029218: nop

    // 0x8002921C: bne         $t2, $zero, L_80029244
    if (ctx->r10 != 0) {
        // 0x80029220: nop
    
            goto L_80029244;
    }
    // 0x80029220: nop

    // 0x80029224: lwc1        $f6, 0x34($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80029228: lwc1        $f5, 0x6430($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6430);
    // 0x8002922C: lwc1        $f4, 0x6434($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6434);
    // 0x80029230: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80029234: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80029238: nop

    // 0x8002923C: bc1f        L_800292D0
    if (!c1cs) {
        // 0x80029240: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_800292D0;
    }
    // 0x80029240: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
L_80029244:
    // 0x80029244: lh          $t1, 0x6($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X6);
    // 0x80029248: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002924C: andi        $t3, $t1, 0x8000
    ctx->r11 = ctx->r9 & 0X8000;
    // 0x80029250: beq         $t3, $zero, L_8002926C
    if (ctx->r11 == 0) {
        // 0x80029254: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_8002926C;
    }
    // 0x80029254: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029258: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002925C: jal         0x80012D5C
    // 0x80029260: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_10;
    // 0x80029260: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_10:
    // 0x80029264: b           L_800292D0
    // 0x80029268: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
        goto L_800292D0;
    // 0x80029268: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
L_8002926C:
    // 0x8002926C: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    // 0x80029270: nop

    // 0x80029274: beq         $a1, $zero, L_80029288
    if (ctx->r5 == 0) {
        // 0x80029278: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80029288;
    }
    // 0x80029278: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002927C: jal         0x8002D3C4
    // 0x80029280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_render(rdram, ctx);
        goto after_11;
    // 0x80029280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80029284: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80029288:
    // 0x80029288: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8002928C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029290: jal         0x80012D5C
    // 0x80029294: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_12;
    // 0x80029294: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_12:
    // 0x80029298: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    // 0x8002929C: nop

    // 0x800292A0: beq         $a1, $zero, L_800292D0
    if (ctx->r5 == 0) {
        // 0x800292A4: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_800292D0;
    }
    // 0x800292A4: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x800292A8: lw          $t4, 0x40($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X40);
    // 0x800292AC: nop

    // 0x800292B0: lhu         $t5, 0x30($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X30);
    // 0x800292B4: nop

    // 0x800292B8: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x800292BC: beq         $t6, $zero, L_800292D0
    if (ctx->r14 == 0) {
        // 0x800292C0: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_800292D0;
    }
    // 0x800292C0: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x800292C4: jal         0x8002D6B0
    // 0x800292C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    watereffect_render(rdram, ctx);
        goto after_13;
    // 0x800292C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x800292CC: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
L_800292D0:
    // 0x800292D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800292D4: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800292D8: bne         $at, $zero, L_800291A0
    if (ctx->r1 != 0) {
        // 0x800292DC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800291A0;
    }
    // 0x800292DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800292E0:
    // 0x800292E0: lw          $t7, 0x160($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X160);
    // 0x800292E4: addiu       $s2, $v1, -0x1
    ctx->r18 = ADD32(ctx->r3, -0X1);
    // 0x800292E8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800292EC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800292F0: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800292F4: addiu       $s5, $s5, -0x49D8
    ctx->r21 = ADD32(ctx->r21, -0X49D8);
    // 0x800292F8: bne         $at, $zero, L_8002940C
    if (ctx->r1 != 0) {
        // 0x800292FC: addiu       $s4, $s4, -0x49DC
        ctx->r20 = ADD32(ctx->r20, -0X49DC);
            goto L_8002940C;
    }
    // 0x800292FC: addiu       $s4, $s4, -0x49DC
    ctx->r20 = ADD32(ctx->r20, -0X49DC);
    // 0x80029300: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80029304: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_80029308:
    // 0x80029308: jal         0x8000E948
    // 0x8002930C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    get_object(rdram, ctx);
        goto after_14;
    // 0x8002930C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x80029310: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x80029314: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x80029318: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8002931C: and         $t0, $v1, $t9
    ctx->r8 = ctx->r3 & ctx->r25;
    // 0x80029320: beq         $t0, $zero, L_80029330
    if (ctx->r8 == 0) {
        // 0x80029324: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80029330;
    }
    // 0x80029324: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80029328: b           L_80029330
    // 0x8002932C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80029330;
    // 0x8002932C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80029330:
    // 0x80029330: beq         $v0, $zero, L_80029400
    if (ctx->r2 == 0) {
        // 0x80029334: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029400;
    }
    // 0x80029334: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029338: beq         $s0, $zero, L_800293FC
    if (ctx->r16 == 0) {
        // 0x8002933C: andi        $t2, $v1, 0x100
        ctx->r10 = ctx->r3 & 0X100;
            goto L_800293FC;
    }
    // 0x8002933C: andi        $t2, $v1, 0x100
    ctx->r10 = ctx->r3 & 0X100;
    // 0x80029340: beq         $t2, $zero, L_80029400
    if (ctx->r10 == 0) {
        // 0x80029344: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029400;
    }
    // 0x80029344: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029348: lh          $t1, 0x2E($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2E);
    // 0x8002934C: nop

    // 0x80029350: addu        $t3, $s6, $t1
    ctx->r11 = ADD32(ctx->r22, ctx->r9);
    // 0x80029354: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x80029358: nop

    // 0x8002935C: beq         $t4, $zero, L_80029400
    if (ctx->r12 == 0) {
        // 0x80029360: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029400;
    }
    // 0x80029360: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029364: jal         0x8002A940
    // 0x80029368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    check_if_in_draw_range(rdram, ctx);
        goto after_15;
    // 0x80029368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x8002936C: beq         $v0, $zero, L_80029400
    if (ctx->r2 == 0) {
        // 0x80029370: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029400;
    }
    // 0x80029370: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029374: lh          $t5, 0x6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X6);
    // 0x80029378: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002937C: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80029380: beq         $t6, $zero, L_8002939C
    if (ctx->r14 == 0) {
        // 0x80029384: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_8002939C;
    }
    // 0x80029384: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029388: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002938C: jal         0x80012D5C
    // 0x80029390: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_16;
    // 0x80029390: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_16:
    // 0x80029394: b           L_80029400
    // 0x80029398: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
        goto L_80029400;
    // 0x80029398: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_8002939C:
    // 0x8002939C: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    // 0x800293A0: nop

    // 0x800293A4: beq         $a1, $zero, L_800293B8
    if (ctx->r5 == 0) {
        // 0x800293A8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800293B8;
    }
    // 0x800293A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800293AC: jal         0x8002D3C4
    // 0x800293B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_render(rdram, ctx);
        goto after_17;
    // 0x800293B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x800293B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800293B8:
    // 0x800293B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800293BC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800293C0: jal         0x80012D5C
    // 0x800293C4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_18;
    // 0x800293C4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_18:
    // 0x800293C8: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    // 0x800293CC: nop

    // 0x800293D0: beq         $a1, $zero, L_80029400
    if (ctx->r5 == 0) {
        // 0x800293D4: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029400;
    }
    // 0x800293D4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800293D8: lw          $t7, 0x40($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X40);
    // 0x800293DC: nop

    // 0x800293E0: lhu         $t8, 0x30($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X30);
    // 0x800293E4: nop

    // 0x800293E8: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x800293EC: beq         $t9, $zero, L_80029400
    if (ctx->r25 == 0) {
        // 0x800293F0: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029400;
    }
    // 0x800293F0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800293F4: jal         0x8002D6B0
    // 0x800293F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    watereffect_render(rdram, ctx);
        goto after_19;
    // 0x800293F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
L_800293FC:
    // 0x800293FC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_80029400:
    // 0x80029400: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80029404: bne         $s2, $t0, L_80029308
    if (ctx->r18 != ctx->r8) {
        // 0x80029408: nop
    
            goto L_80029308;
    }
    // 0x80029408: nop

L_8002940C:
    // 0x8002940C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80029410: lb          $t2, -0x49A0($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X49A0);
    // 0x80029414: lw          $v0, 0x168($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X168);
    // 0x80029418: beq         $t2, $zero, L_8002944C
    if (ctx->r10 == 0) {
        // 0x8002941C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8002944C;
    }
    // 0x8002941C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80029420: bltz        $v0, L_8002944C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80029424: addiu       $t1, $sp, 0xD8
        ctx->r9 = ADD32(ctx->r29, 0XD8);
            goto L_8002944C;
    }
    // 0x80029424: addiu       $t1, $sp, 0xD8
    ctx->r9 = ADD32(ctx->r29, 0XD8);
    // 0x80029428: addu        $s0, $v0, $t1
    ctx->r16 = ADD32(ctx->r2, ctx->r9);
    // 0x8002942C: addiu       $s1, $sp, 0xD8
    ctx->r17 = ADD32(ctx->r29, 0XD8);
L_80029430:
    // 0x80029430: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80029434: jal         0x80029698
    // 0x80029438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    render_level_segment(rdram, ctx);
        goto after_20;
    // 0x80029438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x8002943C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80029440: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80029444: beq         $at, $zero, L_80029430
    if (ctx->r1 == 0) {
        // 0x80029448: nop
    
            goto L_80029430;
    }
    // 0x80029448: nop

L_8002944C:
    // 0x8002944C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80029450: lw          $t3, -0x26FC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X26FC);
    // 0x80029454: nop

    // 0x80029458: beq         $t3, $zero, L_80029478
    if (ctx->r11 == 0) {
        // 0x8002945C: nop
    
            goto L_80029478;
    }
    // 0x8002945C: nop

    // 0x80029460: jal         0x80066460
    // 0x80029464: nop

    get_current_viewport(rdram, ctx);
        goto after_21;
    // 0x80029464: nop

    after_21:
    // 0x80029468: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002946C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029470: jal         0x800BAE04
    // 0x80029474: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    waves_render(rdram, ctx);
        goto after_22;
    // 0x80029474: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_22:
L_80029478:
    // 0x80029478: jal         0x8007B820
    // 0x8002947C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_23;
    // 0x8002947C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_23:
    // 0x80029480: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80029484: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029488: jal         0x8007B918
    // 0x8002948C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    material_set_no_tex_offset(rdram, ctx);
        goto after_24;
    // 0x8002948C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_24:
    // 0x80029490: jal         0x80012C3C
    // 0x80029494: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80012C3C(rdram, ctx);
        goto after_25;
    // 0x80029494: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_25:
    // 0x80029498: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x8002949C: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x800294A0: addiu       $s2, $v1, -0x1
    ctx->r18 = ADD32(ctx->r3, -0X1);
    // 0x800294A4: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800294A8: bne         $at, $zero, L_8002962C
    if (ctx->r1 != 0) {
        // 0x800294AC: addiu       $t5, $t4, -0x1
        ctx->r13 = ADD32(ctx->r12, -0X1);
            goto L_8002962C;
    }
    // 0x800294AC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800294B0: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x800294B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800294B8:
    // 0x800294B8: jal         0x8000E948
    // 0x800294BC: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    get_object(rdram, ctx);
        goto after_26;
    // 0x800294BC: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    after_26:
    // 0x800294C0: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x800294C4: lw          $t8, 0x158($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X158);
    // 0x800294C8: andi        $t6, $v1, 0x80
    ctx->r14 = ctx->r3 & 0X80;
    // 0x800294CC: beq         $t6, $zero, L_800294DC
    if (ctx->r14 == 0) {
        // 0x800294D0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800294DC;
    }
    // 0x800294D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800294D4: b           L_800294F0
    // 0x800294D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800294F0;
    // 0x800294D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800294DC:
    // 0x800294DC: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x800294E0: bne         $t7, $zero, L_800294F4
    if (ctx->r15 != 0) {
        // 0x800294E4: and         $t9, $v1, $t8
        ctx->r25 = ctx->r3 & ctx->r24;
            goto L_800294F4;
    }
    // 0x800294E4: and         $t9, $v1, $t8
    ctx->r25 = ctx->r3 & ctx->r24;
    // 0x800294E8: lbu         $s0, 0x39($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X39);
    // 0x800294EC: nop

L_800294F0:
    // 0x800294F0: and         $t9, $v1, $t8
    ctx->r25 = ctx->r3 & ctx->r24;
L_800294F4:
    // 0x800294F4: beq         $t9, $zero, L_80029500
    if (ctx->r25 == 0) {
        // 0x800294F8: nop
    
            goto L_80029500;
    }
    // 0x800294F8: nop

    // 0x800294FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80029500:
    // 0x80029500: lh          $t0, 0x48($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X48);
    // 0x80029504: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80029508: bne         $t0, $at, L_8002951C
    if (ctx->r8 != ctx->r1) {
        // 0x8002950C: slti        $at, $s0, 0xFF
        ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
            goto L_8002951C;
    }
    // 0x8002950C: slti        $at, $s0, 0xFF
    ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
    // 0x80029510: bne         $at, $zero, L_8002951C
    if (ctx->r1 != 0) {
        // 0x80029514: nop
    
            goto L_8002951C;
    }
    // 0x80029514: nop

    // 0x80029518: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002951C:
    // 0x8002951C: beq         $v0, $zero, L_8002961C
    if (ctx->r2 == 0) {
        // 0x80029520: slti        $at, $s0, 0xFF
        ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
            goto L_8002961C;
    }
    // 0x80029520: slti        $at, $s0, 0xFF
    ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
    // 0x80029524: beq         $at, $zero, L_80029620
    if (ctx->r1 == 0) {
        // 0x80029528: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029620;
    }
    // 0x80029528: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8002952C: lh          $t2, 0x2E($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2E);
    // 0x80029530: nop

    // 0x80029534: addu        $t1, $s6, $t2
    ctx->r9 = ADD32(ctx->r22, ctx->r10);
    // 0x80029538: lbu         $t3, 0x1($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X1);
    // 0x8002953C: nop

    // 0x80029540: beq         $t3, $zero, L_80029620
    if (ctx->r11 == 0) {
        // 0x80029544: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029620;
    }
    // 0x80029544: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029548: jal         0x8002A940
    // 0x8002954C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    check_if_in_draw_range(rdram, ctx);
        goto after_27;
    // 0x8002954C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x80029550: beq         $v0, $zero, L_80029620
    if (ctx->r2 == 0) {
        // 0x80029554: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80029620;
    }
    // 0x80029554: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029558: blez        $s0, L_800295E8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8002955C: nop
    
            goto L_800295E8;
    }
    // 0x8002955C: nop

    // 0x80029560: lh          $t4, 0x6($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X6);
    // 0x80029564: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80029568: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8002956C: beq         $t5, $zero, L_80029588
    if (ctx->r13 == 0) {
        // 0x80029570: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_80029588;
    }
    // 0x80029570: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029574: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029578: jal         0x80012D5C
    // 0x8002957C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_28;
    // 0x8002957C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_28:
    // 0x80029580: b           L_800295EC
    // 0x80029584: lh          $t9, 0x48($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X48);
        goto L_800295EC;
    // 0x80029584: lh          $t9, 0x48($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X48);
L_80029588:
    // 0x80029588: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    // 0x8002958C: nop

    // 0x80029590: beq         $a1, $zero, L_800295A4
    if (ctx->r5 == 0) {
        // 0x80029594: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800295A4;
    }
    // 0x80029594: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80029598: jal         0x8002D3C4
    // 0x8002959C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_render(rdram, ctx);
        goto after_29;
    // 0x8002959C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
    // 0x800295A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800295A4:
    // 0x800295A4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800295A8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800295AC: jal         0x80012D5C
    // 0x800295B0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_30;
    // 0x800295B0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_30:
    // 0x800295B4: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    // 0x800295B8: nop

    // 0x800295BC: beq         $a1, $zero, L_800295E8
    if (ctx->r5 == 0) {
        // 0x800295C0: nop
    
            goto L_800295E8;
    }
    // 0x800295C0: nop

    // 0x800295C4: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x800295C8: nop

    // 0x800295CC: lhu         $t7, 0x30($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X30);
    // 0x800295D0: nop

    // 0x800295D4: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x800295D8: beq         $t8, $zero, L_800295E8
    if (ctx->r24 == 0) {
        // 0x800295DC: nop
    
            goto L_800295E8;
    }
    // 0x800295DC: nop

    // 0x800295E0: jal         0x8002D6B0
    // 0x800295E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    watereffect_render(rdram, ctx);
        goto after_31;
    // 0x800295E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_31:
L_800295E8:
    // 0x800295E8: lh          $t9, 0x48($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X48);
L_800295EC:
    // 0x800295EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800295F0: bne         $t9, $at, L_8002961C
    if (ctx->r25 != ctx->r1) {
        // 0x800295F4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8002961C;
    }
    // 0x800295F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800295F8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800295FC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029600: jal         0x80013A0C
    // 0x80029604: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_racer_shield(rdram, ctx);
        goto after_32;
    // 0x80029604: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_32:
    // 0x80029608: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002960C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029610: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029614: jal         0x80013DCC
    // 0x80029618: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_racer_magnet(rdram, ctx);
        goto after_33;
    // 0x80029618: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_33:
L_8002961C:
    // 0x8002961C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_80029620:
    // 0x80029620: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80029624: bne         $s2, $t0, L_800294B8
    if (ctx->r18 != ctx->r8) {
        // 0x80029628: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800294B8;
    }
    // 0x80029628: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8002962C:
    // 0x8002962C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80029630: lw          $t2, -0x316C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X316C);
    // 0x80029634: nop

    // 0x80029638: beq         $t2, $zero, L_8002966C
    if (ctx->r10 == 0) {
        // 0x8002963C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002966C;
    }
    // 0x8002963C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80029640: jal         0x800275A8
    // 0x80029644: nop

    func_80027568(rdram, ctx);
        goto after_34;
    // 0x80029644: nop

    after_34:
    // 0x80029648: beq         $v0, $zero, L_8002966C
    if (ctx->r2 == 0) {
        // 0x8002964C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002966C;
    }
    // 0x8002964C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80029650: jal         0x80066460
    // 0x80029654: nop

    get_current_viewport(rdram, ctx);
        goto after_35;
    // 0x80029654: nop

    after_35:
    // 0x80029658: lw          $a1, 0x168($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X168);
    // 0x8002965C: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x80029660: jal         0x8002585C
    // 0x80029664: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    void_check(rdram, ctx);
        goto after_36;
    // 0x80029664: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_36:
    // 0x80029668: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8002966C:
    // 0x8002966C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80029670: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80029674: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80029678: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002967C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80029680: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80029684: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80029688: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002968C: sw          $zero, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = 0;
    // 0x80029690: jr          $ra
    // 0x80029694: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
    return;
    // 0x80029694: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
;}
RECOMP_FUNC void render_level_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029698: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8002969C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800296A0: lw          $t6, -0x3178($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3178);
    // 0x800296A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800296A8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800296AC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800296B0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800296B4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800296B8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800296BC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800296C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800296C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800296C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800296CC: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800296D0: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800296D4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800296D8: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x800296DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800296E0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800296E4: beq         $a1, $zero, L_80029710
    if (ctx->r5 == 0) {
        // 0x800296E8: sw          $t9, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r25;
            goto L_80029710;
    }
    // 0x800296E8: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x800296EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800296F0: lw          $t4, -0x26FC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X26FC);
    // 0x800296F4: nop

    // 0x800296F8: beq         $t4, $zero, L_80029710
    if (ctx->r12 == 0) {
        // 0x800296FC: nop
    
            goto L_80029710;
    }
    // 0x800296FC: nop

    // 0x80029700: jal         0x800B9748
    // 0x80029704: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    waves_block_hq(rdram, ctx);
        goto after_0;
    // 0x80029704: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x80029708: b           L_80029714
    // 0x8002970C: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
        goto L_80029714;
    // 0x8002970C: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
L_80029710:
    // 0x80029710: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
L_80029714:
    // 0x80029714: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x80029718: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x8002971C: beq         $t5, $zero, L_8002973C
    if (ctx->r13 == 0) {
        // 0x80029720: lui         $fp, 0x8000
        ctx->r30 = S32(0X8000 << 16);
            goto L_8002973C;
    }
    // 0x80029720: lui         $fp, 0x8000
    ctx->r30 = S32(0X8000 << 16);
    // 0x80029724: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x80029728: nop

    // 0x8002972C: lh          $t7, 0x20($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X20);
    // 0x80029730: lbu         $v0, 0x40($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X40);
    // 0x80029734: b           L_80029748
    // 0x80029738: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
        goto L_80029748;
    // 0x80029738: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
L_8002973C:
    // 0x8002973C: lbu         $t3, 0x40($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X40);
    // 0x80029740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80029744: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
L_80029748:
    // 0x80029748: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8002974C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80029750: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80029754: beq         $at, $zero, L_80029B08
    if (ctx->r1 == 0) {
        // 0x80029758: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_80029B08;
    }
    // 0x80029758: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8002975C: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80029760: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80029764: addiu       $s2, $s2, -0x49E0
    ctx->r18 = ADD32(ctx->r18, -0X49E0);
    // 0x80029768: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
L_8002976C:
    // 0x8002976C: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x80029770: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80029774: lw          $t5, 0xC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC);
    // 0x80029778: nop

    // 0x8002977C: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    // 0x80029780: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x80029784: nop

    // 0x80029788: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8002978C: bne         $v0, $zero, L_80029AF8
    if (ctx->r2 != 0) {
        // 0x80029790: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_80029AF8;
    }
    // 0x80029790: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80029794: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80029798: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8002979C: bne         $v0, $at, L_800297AC
    if (ctx->r2 != ctx->r1) {
        // 0x800297A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800297AC;
    }
    // 0x800297A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800297A4: b           L_800297D4
    // 0x800297A8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
        goto L_800297D4;
    // 0x800297A8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_800297AC:
    // 0x800297AC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800297B0: lw          $t6, -0x3178($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3178);
    // 0x800297B4: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800297B8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800297BC: nop

    // 0x800297C0: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x800297C4: lw          $s5, 0x0($t3)
    ctx->r21 = MEM_W(ctx->r11, 0X0);
    // 0x800297C8: nop

    // 0x800297CC: lh          $a2, 0x6($s5)
    ctx->r6 = MEM_H(ctx->r21, 0X6);
    // 0x800297D0: nop

L_800297D4:
    // 0x800297D4: ori         $t4, $s1, 0xA
    ctx->r12 = ctx->r17 | 0XA;
    // 0x800297D8: andi        $t9, $t4, 0x10
    ctx->r25 = ctx->r12 & 0X10;
    // 0x800297DC: bne         $t9, $zero, L_800297FC
    if (ctx->r25 != 0) {
        // 0x800297E0: or          $s1, $t4, $zero
        ctx->r17 = ctx->r12 | 0;
            goto L_800297FC;
    }
    // 0x800297E0: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x800297E4: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x800297E8: bne         $t5, $zero, L_800297FC
    if (ctx->r13 != 0) {
        // 0x800297EC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800297FC;
    }
    // 0x800297EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800297F0: lw          $t6, -0x4984($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4984);
    // 0x800297F4: nop

    // 0x800297F8: or          $s1, $t4, $t6
    ctx->r17 = ctx->r12 | ctx->r14;
L_800297FC:
    // 0x800297FC: andi        $t7, $a2, 0x4
    ctx->r15 = ctx->r6 & 0X4;
    // 0x80029800: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x80029804: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80029808: bne         $t7, $zero, L_80029814
    if (ctx->r15 != 0) {
        // 0x8002980C: andi        $t8, $s1, 0x2000
        ctx->r24 = ctx->r17 & 0X2000;
            goto L_80029814;
    }
    // 0x8002980C: andi        $t8, $s1, 0x2000
    ctx->r24 = ctx->r17 & 0X2000;
    // 0x80029810: beq         $t8, $zero, L_80029820
    if (ctx->r24 == 0) {
        // 0x80029814: andi        $t3, $s1, 0x800
        ctx->r11 = ctx->r17 & 0X800;
            goto L_80029820;
    }
L_80029814:
    // 0x80029814: andi        $t3, $s1, 0x800
    ctx->r11 = ctx->r17 & 0X800;
    // 0x80029818: beq         $t3, $zero, L_80029824
    if (ctx->r11 == 0) {
        // 0x8002981C: nop
    
            goto L_80029824;
    }
    // 0x8002981C: nop

L_80029820:
    // 0x80029820: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80029824:
    // 0x80029824: beq         $t4, $zero, L_80029838
    if (ctx->r12 == 0) {
        // 0x80029828: andi        $t6, $s1, 0x2000
        ctx->r14 = ctx->r17 & 0X2000;
            goto L_80029838;
    }
    // 0x80029828: andi        $t6, $s1, 0x2000
    ctx->r14 = ctx->r17 & 0X2000;
    // 0x8002982C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80029830: andi        $t9, $a0, 0x1
    ctx->r25 = ctx->r4 & 0X1;
    // 0x80029834: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_80029838:
    // 0x80029838: beq         $t5, $zero, L_8002984C
    if (ctx->r13 == 0) {
        // 0x8002983C: nop
    
            goto L_8002984C;
    }
    // 0x8002983C: nop

    // 0x80029840: beq         $t6, $zero, L_8002984C
    if (ctx->r14 == 0) {
        // 0x80029844: nop
    
            goto L_8002984C;
    }
    // 0x80029844: nop

    // 0x80029848: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8002984C:
    // 0x8002984C: beq         $a0, $zero, L_80029AFC
    if (ctx->r4 == 0) {
        // 0x80029850: lw          $t7, 0x70($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X70);
            goto L_80029AFC;
    }
    // 0x80029850: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80029854: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
    // 0x80029858: lw          $t3, 0xAC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XAC);
    // 0x8002985C: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    // 0x80029860: lh          $t7, 0xE($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XE);
    // 0x80029864: lh          $t8, 0x10($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X10);
    // 0x80029868: lbu         $a3, 0x7($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X7);
    // 0x8002986C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80029870: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80029874: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80029878: sra         $a0, $s1, 28
    ctx->r4 = S32(SIGNED(ctx->r17) >> 28);
    // 0x8002987C: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80029880: subu        $s3, $t7, $v0
    ctx->r19 = SUB32(ctx->r15, ctx->r2);
    // 0x80029884: subu        $s4, $t8, $v1
    ctx->r20 = SUB32(ctx->r24, ctx->r3);
    // 0x80029888: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8002988C: andi        $t8, $a0, 0x7
    ctx->r24 = ctx->r4 & 0X7;
    // 0x80029890: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80029894: sll         $t7, $a3, 14
    ctx->r15 = S32(ctx->r7 << 14);
    // 0x80029898: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8002989C: addu        $s6, $t4, $t9
    ctx->r22 = ADD32(ctx->r12, ctx->r25);
    // 0x800298A0: beq         $t8, $zero, L_80029904
    if (ctx->r24 == 0) {
        // 0x800298A4: addu        $s7, $t5, $t6
        ctx->r23 = ADD32(ctx->r13, ctx->r14);
            goto L_80029904;
    }
    // 0x800298A4: addu        $s7, $t5, $t6
    ctx->r23 = ADD32(ctx->r13, ctx->r14);
    // 0x800298A8: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800298AC: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x800298B0: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800298B4: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x800298B8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800298BC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800298C0: lw          $t3, -0x3174($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3174);
    // 0x800298C4: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x800298C8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800298CC: lw          $v0, 0x70($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X70);
    // 0x800298D0: nop

    // 0x800298D4: lbu         $t9, 0x10($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X10);
    // 0x800298D8: lbu         $t8, 0x13($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X13);
    // 0x800298DC: sll         $t3, $t9, 24
    ctx->r11 = S32(ctx->r25 << 24);
    // 0x800298E0: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x800298E4: or          $t5, $t8, $t3
    ctx->r13 = ctx->r24 | ctx->r11;
    // 0x800298E8: lbu         $t3, 0x12($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X12);
    // 0x800298EC: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800298F0: or          $t9, $t5, $t4
    ctx->r25 = ctx->r13 | ctx->r12;
    // 0x800298F4: sll         $t6, $t3, 8
    ctx->r14 = S32(ctx->r11 << 8);
    // 0x800298F8: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800298FC: b           L_80029920
    // 0x80029900: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_80029920;
    // 0x80029900: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_80029904:
    // 0x80029904: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029908: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x8002990C: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80029910: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80029914: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
    // 0x80029918: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8002991C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_80029920:
    // 0x80029920: sll         $t3, $s1, 13
    ctx->r11 = S32(ctx->r17 << 13);
    // 0x80029924: bgez        $t3, L_80029A40
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80029928: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80029A40;
    }
    // 0x80029928: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002992C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80029930: lw          $t9, -0x3174($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3174);
    // 0x80029934: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029938: lw          $t6, 0xAC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0XAC);
    // 0x8002993C: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80029940: lw          $t0, 0x8($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X8);
    // 0x80029944: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80029948: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x8002994C: sll         $t4, $v0, 24
    ctx->r12 = S32(ctx->r2 << 24);
    // 0x80029950: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80029954: or          $t3, $t4, $t8
    ctx->r11 = ctx->r12 | ctx->r24;
    // 0x80029958: sll         $t9, $v0, 8
    ctx->r25 = S32(ctx->r2 << 8);
    // 0x8002995C: or          $t6, $t3, $t9
    ctx->r14 = ctx->r11 | ctx->r25;
    // 0x80029960: or          $t7, $t6, $v0
    ctx->r15 = ctx->r14 | ctx->r2;
    // 0x80029964: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80029968: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8002996C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80029970: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80029974: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x80029978: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002997C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80029980: jal         0x8007BEAC
    // 0x80029984: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    material_set_blinking_lights(rdram, ctx);
        goto after_1;
    // 0x80029984: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x80029988: addu        $v1, $s6, $fp
    ctx->r3 = ADD32(ctx->r22, ctx->r30);
    // 0x8002998C: addiu       $t4, $s3, -0x1
    ctx->r12 = ADD32(ctx->r19, -0X1);
    // 0x80029990: sll         $t8, $t4, 3
    ctx->r24 = S32(ctx->r12 << 3);
    // 0x80029994: andi        $t3, $v1, 0x6
    ctx->r11 = ctx->r3 & 0X6;
    // 0x80029998: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x8002999C: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800299A0: sll         $t4, $s3, 3
    ctx->r12 = S32(ctx->r19 << 3);
    // 0x800299A4: addu        $t8, $t4, $s3
    ctx->r24 = ADD32(ctx->r12, ctx->r19);
    // 0x800299A8: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x800299AC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800299B0: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x800299B4: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800299B8: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800299BC: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x800299C0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800299C4: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800299C8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800299CC: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x800299D0: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800299D4: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800299D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800299DC: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x800299E0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800299E4: addiu       $t8, $s4, -0x1
    ctx->r24 = ADD32(ctx->r20, -0X1);
    // 0x800299E8: sll         $t3, $t8, 4
    ctx->r11 = S32(ctx->r24 << 4);
    // 0x800299EC: ori         $t9, $t3, 0x1
    ctx->r25 = ctx->r11 | 0X1;
    // 0x800299F0: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800299F4: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x800299F8: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x800299FC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80029A00: sll         $t4, $s4, 4
    ctx->r12 = S32(ctx->r20 << 4);
    // 0x80029A04: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80029A08: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80029A0C: andi        $t8, $t4, 0xFFFF
    ctx->r24 = ctx->r12 & 0XFFFF;
    // 0x80029A10: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x80029A14: addu        $t9, $s7, $fp
    ctx->r25 = ADD32(ctx->r23, ctx->r30);
    // 0x80029A18: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80029A1C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80029A20: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029A24: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80029A28: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80029A2C: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80029A30: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80029A34: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80029A38: b           L_80029AF8
    // 0x80029A3C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
        goto L_80029AF8;
    // 0x80029A3C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
L_80029A40:
    // 0x80029A40: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80029A44: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80029A48: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x80029A4C: jal         0x8007B938
    // 0x80029A50: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    material_set(rdram, ctx);
        goto after_2;
    // 0x80029A50: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    after_2:
    // 0x80029A54: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80029A58: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80029A5C: bne         $s5, $zero, L_80029A68
    if (ctx->r21 != 0) {
        // 0x80029A60: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_80029A68;
    }
    // 0x80029A60: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80029A64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80029A68:
    // 0x80029A68: addu        $v1, $s6, $fp
    ctx->r3 = ADD32(ctx->r22, ctx->r30);
    // 0x80029A6C: addiu       $t8, $s3, -0x1
    ctx->r24 = ADD32(ctx->r19, -0X1);
    // 0x80029A70: sll         $t3, $t8, 3
    ctx->r11 = S32(ctx->r24 << 3);
    // 0x80029A74: andi        $t9, $v1, 0x6
    ctx->r25 = ctx->r3 & 0X6;
    // 0x80029A78: or          $t5, $t3, $t9
    ctx->r13 = ctx->r11 | ctx->r25;
    // 0x80029A7C: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029A80: sll         $t8, $s3, 3
    ctx->r24 = S32(ctx->r19 << 3);
    // 0x80029A84: addu        $t3, $t8, $s3
    ctx->r11 = ADD32(ctx->r24, ctx->r19);
    // 0x80029A88: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80029A8C: sll         $t4, $t6, 16
    ctx->r12 = S32(ctx->r14 << 16);
    // 0x80029A90: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x80029A94: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80029A98: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80029A9C: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x80029AA0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80029AA4: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x80029AA8: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80029AAC: or          $t4, $t7, $t6
    ctx->r12 = ctx->r15 | ctx->r14;
    // 0x80029AB0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80029AB4: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80029AB8: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029ABC: addiu       $t3, $s4, -0x1
    ctx->r11 = ADD32(ctx->r20, -0X1);
    // 0x80029AC0: sll         $t9, $t3, 4
    ctx->r25 = S32(ctx->r11 << 4);
    // 0x80029AC4: or          $t5, $t9, $s1
    ctx->r13 = ctx->r25 | ctx->r17;
    // 0x80029AC8: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80029ACC: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80029AD0: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x80029AD4: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80029AD8: sll         $t8, $s4, 4
    ctx->r24 = S32(ctx->r20 << 4);
    // 0x80029ADC: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80029AE0: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x80029AE4: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x80029AE8: or          $t9, $t4, $t3
    ctx->r25 = ctx->r12 | ctx->r11;
    // 0x80029AEC: addu        $t5, $s7, $fp
    ctx->r13 = ADD32(ctx->r23, ctx->r30);
    // 0x80029AF0: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x80029AF4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_80029AF8:
    // 0x80029AF8: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
L_80029AFC:
    // 0x80029AFC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80029B00: bne         $t1, $t7, L_8002976C
    if (ctx->r9 != ctx->r15) {
        // 0x80029B04: addiu       $t2, $t2, 0xC
        ctx->r10 = ADD32(ctx->r10, 0XC);
            goto L_8002976C;
    }
    // 0x80029B04: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
L_80029B08:
    // 0x80029B08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80029B0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029B10: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80029B14: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80029B18: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80029B1C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80029B20: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80029B24: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80029B28: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80029B2C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80029B30: jr          $ra
    // 0x80029B34: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80029B34: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
