#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800732E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073540: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80073544: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80073548: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007354C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80073550: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80073554: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80073558: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007355C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80073560: jal         0x8006B464
    // 0x80073564: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    level_count(rdram, ctx);
        goto after_0;
    // 0x80073564: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80073568: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8007356C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073570: sw          $t6, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r14;
    // 0x80073574: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073578: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x8007357C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073580: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80073584: sw          $t7, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = ctx->r15;
    // 0x80073588: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007358C: jal         0x80073080
    // 0x80073590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_1;
    // 0x80073590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80073594: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80073598: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007359C: blez        $t8, L_80073634
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800735A0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80073634;
    }
    // 0x800735A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800735A4:
    // 0x800735A4: jal         0x8006B38C
    // 0x800735A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_2;
    // 0x800735A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800735AC: beq         $v0, $zero, L_800735C4
    if (ctx->r2 == 0) {
        // 0x800735B0: andi        $t9, $v0, 0x40
        ctx->r25 = ctx->r2 & 0X40;
            goto L_800735C4;
    }
    // 0x800735B0: andi        $t9, $v0, 0x40
    ctx->r25 = ctx->r2 & 0X40;
    // 0x800735B4: bne         $t9, $zero, L_800735C4
    if (ctx->r25 != 0) {
        // 0x800735B8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800735C4;
    }
    // 0x800735B8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800735BC: bne         $v0, $at, L_80073620
    if (ctx->r2 != ctx->r1) {
        // 0x800735C0: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_80073620;
    }
    // 0x800735C0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_800735C4:
    // 0x800735C4: lw          $t0, 0x4($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X4);
    // 0x800735C8: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x800735CC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800735D0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800735D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800735D8: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x800735DC: beq         $t3, $zero, L_800735E8
    if (ctx->r11 == 0) {
        // 0x800735E0: andi        $t4, $v0, 0x2
        ctx->r12 = ctx->r2 & 0X2;
            goto L_800735E8;
    }
    // 0x800735E0: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x800735E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800735E8:
    // 0x800735E8: beq         $t4, $zero, L_800735FC
    if (ctx->r12 == 0) {
        // 0x800735EC: andi        $t6, $v0, 0x4
        ctx->r14 = ctx->r2 & 0X4;
            goto L_800735FC;
    }
    // 0x800735EC: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x800735F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800735F4: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x800735F8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_800735FC:
    // 0x800735FC: beq         $t6, $zero, L_80073610
    if (ctx->r14 == 0) {
        // 0x80073600: nop
    
            goto L_80073610;
    }
    // 0x80073600: nop

    // 0x80073604: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80073608: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8007360C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_80073610:
    // 0x80073610: jal         0x80073080
    // 0x80073614: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80072E28(rdram, ctx);
        goto after_3;
    // 0x80073614: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80073618: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8007361C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_80073620:
    // 0x80073620: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073624: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80073628: bne         $at, $zero, L_800735A4
    if (ctx->r1 != 0) {
        // 0x8007362C: nop
    
            goto L_800735A4;
    }
    // 0x8007362C: nop

    // 0x80073630: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80073634:
    // 0x80073634: addiu       $t9, $zero, 0x44
    ctx->r25 = ADD32(0, 0X44);
    // 0x80073638: subu        $a0, $t9, $s0
    ctx->r4 = SUB32(ctx->r25, ctx->r16);
    // 0x8007363C: jal         0x80073080
    // 0x80073640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_4;
    // 0x80073640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80073644: lhu         $a1, 0x14($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X14);
    // 0x80073648: jal         0x80073080
    // 0x8007364C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80072E28(rdram, ctx);
        goto after_5;
    // 0x8007364C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_5:
    // 0x80073650: lhu         $a1, 0xE($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0XE);
    // 0x80073654: jal         0x80073080
    // 0x80073658: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_80072E28(rdram, ctx);
        goto after_6;
    // 0x80073658: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_6:
    // 0x8007365C: lhu         $a1, 0xC($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0XC);
    // 0x80073660: jal         0x80073080
    // 0x80073664: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80072E28(rdram, ctx);
        goto after_7;
    // 0x80073664: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_7:
    // 0x80073668: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8007366C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80073670: blez        $t0, L_800736A8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80073674: nop
    
            goto L_800736A8;
    }
    // 0x80073674: nop

L_80073678:
    // 0x80073678: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8007367C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80073680: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073684: lh          $a1, 0x0($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X0);
    // 0x80073688: jal         0x80073080
    // 0x8007368C: nop

    func_80072E28(rdram, ctx);
        goto after_8;
    // 0x8007368C: nop

    after_8:
    // 0x80073690: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80073694: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073698: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007369C: bne         $at, $zero, L_80073678
    if (ctx->r1 != 0) {
        // 0x800736A0: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80073678;
    }
    // 0x800736A0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800736A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800736A8:
    // 0x800736A8: lbu         $a1, 0x16($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X16);
    // 0x800736AC: jal         0x80073080
    // 0x800736B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80072E28(rdram, ctx);
        goto after_9;
    // 0x800736B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_9:
    // 0x800736B4: lbu         $a1, 0x17($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X17);
    // 0x800736B8: jal         0x80073080
    // 0x800736BC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80072E28(rdram, ctx);
        goto after_10;
    // 0x800736BC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_10:
    // 0x800736C0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800736C4: nop

    // 0x800736C8: blez        $t4, L_8007370C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800736CC: nop
    
            goto L_8007370C;
    }
    // 0x800736CC: nop

L_800736D0:
    // 0x800736D0: jal         0x8006B414
    // 0x800736D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    level_world_id(rdram, ctx);
        goto after_11;
    // 0x800736D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x800736D8: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x800736DC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800736E0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800736E4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800736E8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800736EC: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800736F0: jal         0x80073080
    // 0x800736F4: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    func_80072E28(rdram, ctx);
        goto after_12;
    // 0x800736F4: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    after_12:
    // 0x800736F8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800736FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073700: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80073704: bne         $at, $zero, L_800736D0
    if (ctx->r1 != 0) {
        // 0x80073708: nop
    
            goto L_800736D0;
    }
    // 0x80073708: nop

L_8007370C:
    // 0x8007370C: lhu         $a1, 0x8($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X8);
    // 0x80073710: jal         0x80073080
    // 0x80073714: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80072E28(rdram, ctx);
        goto after_13;
    // 0x80073714: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_13:
    // 0x80073718: lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X10);
    // 0x8007371C: jal         0x80073080
    // 0x80073720: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80072E28(rdram, ctx);
        goto after_14;
    // 0x80073720: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_14:
    // 0x80073724: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    // 0x80073728: jal         0x80073080
    // 0x8007372C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_15;
    // 0x8007372C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_15:
    // 0x80073730: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80073734: jal         0x80073080
    // 0x80073738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_16;
    // 0x80073738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x8007373C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80073740: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80073744: addiu       $a0, $a2, 0x2
    ctx->r4 = ADD32(ctx->r6, 0X2);
    // 0x80073748: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8007374C: lbu         $t3, 0x1($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X1);
    // 0x80073750: addiu       $t2, $v0, 0x5
    ctx->r10 = ADD32(ctx->r2, 0X5);
    // 0x80073754: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80073758: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8007375C: sra         $v0, $t4, 16
    ctx->r2 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80073760: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80073764: addiu       $v1, $a2, 0x4
    ctx->r3 = ADD32(ctx->r6, 0X4);
L_80073768:
    // 0x80073768: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8007376C: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x80073770: lbu         $t2, 0x2($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2);
    // 0x80073774: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x80073778: lbu         $t5, 0x3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3);
    // 0x8007377C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80073780: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x80073784: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80073788: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8007378C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80073790: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80073794: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073798: bne         $s1, $a0, L_80073768
    if (ctx->r17 != ctx->r4) {
        // 0x8007379C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80073768;
    }
    // 0x8007379C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800737A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800737A4: sw          $a2, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r6;
    // 0x800737A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800737AC: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x800737B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800737B4: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800737B8: sw          $t8, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = ctx->r24;
    // 0x800737BC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800737C0: jal         0x80073080
    // 0x800737C4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_80072E28(rdram, ctx);
        goto after_17;
    // 0x800737C4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_17:
    // 0x800737C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800737CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800737D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800737D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800737D8: jr          $ra
    // 0x800737DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800737DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80073588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800737E0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800737E4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800737E8: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x800737EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800737F0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800737F4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800737F8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800737FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80073800: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80073804: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80073808: jal         0x8006E9B0
    // 0x8007380C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    clear_lap_records(rdram, ctx);
        goto after_0;
    // 0x8007380C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80073810: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80073814: jal         0x8006B464
    // 0x80073818: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    level_count(rdram, ctx);
        goto after_1;
    // 0x80073818: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x8007381C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80073820: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80073824: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80073828: beq         $t8, $zero, L_8007397C
    if (ctx->r24 == 0) {
        // 0x8007382C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8007397C;
    }
    // 0x8007382C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073830: sw          $t9, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r25;
    // 0x80073834: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073838: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x8007383C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073840: sw          $zero, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = 0;
    // 0x80073844: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80073848: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x8007384C: addiu       $v0, $t9, 0x2
    ctx->r2 = ADD32(ctx->r25, 0X2);
L_80073850:
    // 0x80073850: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80073854: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073858: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x8007385C: slti        $at, $s1, 0xC0
    ctx->r1 = SIGNED(ctx->r17) < 0XC0 ? 1 : 0;
    // 0x80073860: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x80073864: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80073868: bne         $at, $zero, L_80073850
    if (ctx->r1 != 0) {
        // 0x8007386C: sra         $s0, $t1, 16
        ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
            goto L_80073850;
    }
    // 0x8007386C: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80073870: jal         0x80072EAC
    // 0x80073874: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072C54(rdram, ctx);
        goto after_2;
    // 0x80073874: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x80073878: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x8007387C: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x80073880: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80073884: bne         $t4, $zero, L_80073980
    if (ctx->r12 != 0) {
        // 0x80073888: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80073980;
    }
    // 0x80073888: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007388C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80073890: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80073894: blez        $t5, L_80073980
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80073898: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80073980;
    }
    // 0x80073898: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
L_8007389C:
    // 0x8007389C: jal         0x8006B38C
    // 0x800738A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_3;
    // 0x800738A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800738A4: bne         $v0, $zero, L_8007396C
    if (ctx->r2 != 0) {
        // 0x800738A8: lw          $t4, 0x40($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X40);
            goto L_8007396C;
    }
    // 0x800738A8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800738AC: jal         0x8006B338
    // 0x800738B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_4;
    // 0x800738B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800738B4: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800738B8: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800738BC: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800738C0: beq         $t9, $zero, L_800738F8
    if (ctx->r25 == 0) {
        // 0x800738C4: or          $s2, $t6, $zero
        ctx->r18 = ctx->r14 | 0;
            goto L_800738F8;
    }
    // 0x800738C4: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x800738C8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800738CC: jal         0x80072EAC
    // 0x800738D0: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_5;
    // 0x800738D0: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_5:
    // 0x800738D4: lw          $t0, 0x24($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X24);
    // 0x800738D8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800738DC: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x800738E0: jal         0x80072EAC
    // 0x800738E4: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_6;
    // 0x800738E4: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    after_6:
    // 0x800738E8: lw          $t2, 0x18($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X18);
    // 0x800738EC: nop

    // 0x800738F0: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800738F4: sh          $v0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r2;
L_800738F8:
    // 0x800738F8: andi        $t4, $s2, 0x2
    ctx->r12 = ctx->r18 & 0X2;
    // 0x800738FC: beq         $t4, $zero, L_80073930
    if (ctx->r12 == 0) {
        // 0x80073900: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80073930;
    }
    // 0x80073900: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073904: jal         0x80072EAC
    // 0x80073908: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_7;
    // 0x80073908: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_7:
    // 0x8007390C: lw          $t5, 0x28($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X28);
    // 0x80073910: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073914: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x80073918: jal         0x80072EAC
    // 0x8007391C: sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_8;
    // 0x8007391C: sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    after_8:
    // 0x80073920: lw          $t7, 0x1C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X1C);
    // 0x80073924: nop

    // 0x80073928: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8007392C: sh          $v0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r2;
L_80073930:
    // 0x80073930: andi        $t9, $s2, 0x4
    ctx->r25 = ctx->r18 & 0X4;
    // 0x80073934: beq         $t9, $zero, L_80073968
    if (ctx->r25 == 0) {
        // 0x80073938: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80073968;
    }
    // 0x80073938: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007393C: jal         0x80072EAC
    // 0x80073940: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_9;
    // 0x80073940: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_9:
    // 0x80073944: lw          $t0, 0x2C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X2C);
    // 0x80073948: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007394C: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80073950: jal         0x80072EAC
    // 0x80073954: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_10;
    // 0x80073954: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    after_10:
    // 0x80073958: lw          $t2, 0x20($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X20);
    // 0x8007395C: nop

    // 0x80073960: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80073964: sh          $v0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r2;
L_80073968:
    // 0x80073968: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
L_8007396C:
    // 0x8007396C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073970: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80073974: bne         $at, $zero, L_8007389C
    if (ctx->r1 != 0) {
        // 0x80073978: nop
    
            goto L_8007389C;
    }
    // 0x80073978: nop

L_8007397C:
    // 0x8007397C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
L_80073980:
    // 0x80073980: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80073984: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80073988: beq         $t6, $zero, L_80073AE0
    if (ctx->r14 == 0) {
        // 0x8007398C: addiu       $t8, $t7, 0xC0
        ctx->r24 = ADD32(ctx->r15, 0XC0);
            goto L_80073AE0;
    }
    // 0x8007398C: addiu       $t8, $t7, 0xC0
    ctx->r24 = ADD32(ctx->r15, 0XC0);
    // 0x80073990: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073994: sw          $t8, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r24;
    // 0x80073998: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007399C: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x800739A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800739A4: sw          $zero, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = 0;
    // 0x800739A8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x800739AC: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x800739B0: addiu       $v0, $t8, 0x2
    ctx->r2 = ADD32(ctx->r24, 0X2);
L_800739B4:
    // 0x800739B4: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800739B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800739BC: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x800739C0: slti        $at, $s1, 0xC0
    ctx->r1 = SIGNED(ctx->r17) < 0XC0 ? 1 : 0;
    // 0x800739C4: sll         $t0, $s0, 16
    ctx->r8 = S32(ctx->r16 << 16);
    // 0x800739C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800739CC: bne         $at, $zero, L_800739B4
    if (ctx->r1 != 0) {
        // 0x800739D0: sra         $s0, $t0, 16
        ctx->r16 = S32(SIGNED(ctx->r8) >> 16);
            goto L_800739B4;
    }
    // 0x800739D0: sra         $s0, $t0, 16
    ctx->r16 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800739D4: jal         0x80072EAC
    // 0x800739D8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072C54(rdram, ctx);
        goto after_11;
    // 0x800739D8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_11:
    // 0x800739DC: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800739E0: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x800739E4: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800739E8: bne         $t3, $zero, L_80073AE4
    if (ctx->r11 != 0) {
        // 0x800739EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80073AE4;
    }
    // 0x800739EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800739F0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800739F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800739F8: blez        $t4, L_80073AE4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800739FC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80073AE4;
    }
    // 0x800739FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80073A00:
    // 0x80073A00: jal         0x8006B38C
    // 0x80073A04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_12;
    // 0x80073A04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80073A08: bne         $v0, $zero, L_80073AD0
    if (ctx->r2 != 0) {
        // 0x80073A0C: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_80073AD0;
    }
    // 0x80073A0C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80073A10: jal         0x8006B338
    // 0x80073A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_13;
    // 0x80073A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80073A18: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x80073A1C: sra         $t5, $s2, 16
    ctx->r13 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80073A20: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80073A24: beq         $t8, $zero, L_80073A5C
    if (ctx->r24 == 0) {
        // 0x80073A28: or          $s2, $t5, $zero
        ctx->r18 = ctx->r13 | 0;
            goto L_80073A5C;
    }
    // 0x80073A28: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x80073A2C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073A30: jal         0x80072EAC
    // 0x80073A34: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_14;
    // 0x80073A34: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_14:
    // 0x80073A38: lw          $t9, 0x3C($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X3C);
    // 0x80073A3C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073A40: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x80073A44: jal         0x80072EAC
    // 0x80073A48: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_15;
    // 0x80073A48: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    after_15:
    // 0x80073A4C: lw          $t1, 0x30($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X30);
    // 0x80073A50: nop

    // 0x80073A54: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073A58: sh          $v0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r2;
L_80073A5C:
    // 0x80073A5C: andi        $t3, $s2, 0x2
    ctx->r11 = ctx->r18 & 0X2;
    // 0x80073A60: beq         $t3, $zero, L_80073A94
    if (ctx->r11 == 0) {
        // 0x80073A64: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80073A94;
    }
    // 0x80073A64: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073A68: jal         0x80072EAC
    // 0x80073A6C: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_16;
    // 0x80073A6C: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_16:
    // 0x80073A70: lw          $t4, 0x40($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X40);
    // 0x80073A74: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073A78: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80073A7C: jal         0x80072EAC
    // 0x80073A80: sh          $v0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_17;
    // 0x80073A80: sh          $v0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r2;
    after_17:
    // 0x80073A84: lw          $t6, 0x34($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X34);
    // 0x80073A88: nop

    // 0x80073A8C: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80073A90: sh          $v0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r2;
L_80073A94:
    // 0x80073A94: andi        $t8, $s2, 0x4
    ctx->r24 = ctx->r18 & 0X4;
    // 0x80073A98: beq         $t8, $zero, L_80073ACC
    if (ctx->r24 == 0) {
        // 0x80073A9C: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80073ACC;
    }
    // 0x80073A9C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073AA0: jal         0x80072EAC
    // 0x80073AA4: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_18;
    // 0x80073AA4: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_18:
    // 0x80073AA8: lw          $t9, 0x44($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X44);
    // 0x80073AAC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073AB0: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x80073AB4: jal         0x80072EAC
    // 0x80073AB8: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_19;
    // 0x80073AB8: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    after_19:
    // 0x80073ABC: lw          $t1, 0x38($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X38);
    // 0x80073AC0: nop

    // 0x80073AC4: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073AC8: sh          $v0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r2;
L_80073ACC:
    // 0x80073ACC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
L_80073AD0:
    // 0x80073AD0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073AD4: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80073AD8: bne         $at, $zero, L_80073A00
    if (ctx->r1 != 0) {
        // 0x80073ADC: nop
    
            goto L_80073A00;
    }
    // 0x80073ADC: nop

L_80073AE0:
    // 0x80073AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80073AE4:
    // 0x80073AE4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80073AE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80073AEC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80073AF0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80073AF4: jr          $ra
    // 0x80073AF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80073AF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800738A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073AFC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80073B00: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80073B04: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80073B08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80073B0C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80073B10: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80073B14: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80073B18: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80073B1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80073B20: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80073B24: jal         0x8006B464
    // 0x80073B28: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    level_count(rdram, ctx);
        goto after_0;
    // 0x80073B28: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x80073B2C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80073B30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073B34: sw          $t6, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r14;
    // 0x80073B38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073B3C: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x80073B40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073B44: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80073B48: sw          $t7, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = ctx->r15;
    // 0x80073B4C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073B50: jal         0x80073080
    // 0x80073B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_1;
    // 0x80073B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80073B58: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80073B5C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80073B60: blez        $t8, L_80073C70
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80073B64: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80073C70;
    }
    // 0x80073B64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80073B68:
    // 0x80073B68: jal         0x8006B38C
    // 0x80073B6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_2;
    // 0x80073B6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80073B70: bne         $v0, $zero, L_80073C60
    if (ctx->r2 != 0) {
        // 0x80073B74: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80073C60;
    }
    // 0x80073B74: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80073B78: jal         0x8006B338
    // 0x80073B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_3;
    // 0x80073B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80073B80: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80073B84: sra         $t9, $s3, 16
    ctx->r25 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80073B88: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80073B8C: beq         $t2, $zero, L_80073BC8
    if (ctx->r10 == 0) {
        // 0x80073B90: or          $s3, $t9, $zero
        ctx->r19 = ctx->r25 | 0;
            goto L_80073BC8;
    }
    // 0x80073B90: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x80073B94: lw          $t3, 0x24($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X24);
    // 0x80073B98: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073B9C: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80073BA0: lhu         $a1, 0x0($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X0);
    // 0x80073BA4: jal         0x80073080
    // 0x80073BA8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_4;
    // 0x80073BA8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_4:
    // 0x80073BAC: lw          $t5, 0x18($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X18);
    // 0x80073BB0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073BB4: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x80073BB8: lhu         $a1, 0x0($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X0);
    // 0x80073BBC: jal         0x80073080
    // 0x80073BC0: nop

    func_80072E28(rdram, ctx);
        goto after_5;
    // 0x80073BC0: nop

    after_5:
    // 0x80073BC4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80073BC8:
    // 0x80073BC8: andi        $t7, $s3, 0x2
    ctx->r15 = ctx->r19 & 0X2;
    // 0x80073BCC: beq         $t7, $zero, L_80073C0C
    if (ctx->r15 == 0) {
        // 0x80073BD0: andi        $t2, $s3, 0x4
        ctx->r10 = ctx->r19 & 0X4;
            goto L_80073C0C;
    }
    // 0x80073BD0: andi        $t2, $s3, 0x4
    ctx->r10 = ctx->r19 & 0X4;
    // 0x80073BD4: lw          $t8, 0x28($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X28);
    // 0x80073BD8: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073BDC: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80073BE0: lhu         $a1, 0x0($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X0);
    // 0x80073BE4: jal         0x80073080
    // 0x80073BE8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_6;
    // 0x80073BE8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_6:
    // 0x80073BEC: lw          $t0, 0x1C($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X1C);
    // 0x80073BF0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073BF4: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80073BF8: lhu         $a1, 0x0($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0X0);
    // 0x80073BFC: jal         0x80073080
    // 0x80073C00: nop

    func_80072E28(rdram, ctx);
        goto after_7;
    // 0x80073C00: nop

    after_7:
    // 0x80073C04: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80073C08: andi        $t2, $s3, 0x4
    ctx->r10 = ctx->r19 & 0X4;
L_80073C0C:
    // 0x80073C0C: beq         $t2, $zero, L_80073C4C
    if (ctx->r10 == 0) {
        // 0x80073C10: slti        $at, $s2, 0x30
        ctx->r1 = SIGNED(ctx->r18) < 0X30 ? 1 : 0;
            goto L_80073C4C;
    }
    // 0x80073C10: slti        $at, $s2, 0x30
    ctx->r1 = SIGNED(ctx->r18) < 0X30 ? 1 : 0;
    // 0x80073C14: lw          $t3, 0x2C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X2C);
    // 0x80073C18: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073C1C: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80073C20: lhu         $a1, 0x0($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X0);
    // 0x80073C24: jal         0x80073080
    // 0x80073C28: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_8;
    // 0x80073C28: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_8:
    // 0x80073C2C: lw          $t5, 0x20($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X20);
    // 0x80073C30: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073C34: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x80073C38: lhu         $a1, 0x0($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X0);
    // 0x80073C3C: jal         0x80073080
    // 0x80073C40: nop

    func_80072E28(rdram, ctx);
        goto after_9;
    // 0x80073C40: nop

    after_9:
    // 0x80073C44: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80073C48: slti        $at, $s2, 0x30
    ctx->r1 = SIGNED(ctx->r18) < 0X30 ? 1 : 0;
L_80073C4C:
    // 0x80073C4C: bne         $at, $zero, L_80073C60
    if (ctx->r1 != 0) {
        // 0x80073C50: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80073C60;
    }
    // 0x80073C50: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80073C54: b           L_80073C74
    // 0x80073C58: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
        goto L_80073C74;
    // 0x80073C58: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80073C5C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_80073C60:
    // 0x80073C60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073C64: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80073C68: bne         $at, $zero, L_80073B68
    if (ctx->r1 != 0) {
        // 0x80073C6C: nop
    
            goto L_80073B68;
    }
    // 0x80073C6C: nop

L_80073C70:
    // 0x80073C70: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_80073C74:
    // 0x80073C74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073C78: sw          $t8, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r24;
    // 0x80073C7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073C80: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x80073C84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073C88: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80073C8C: sw          $t9, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = ctx->r25;
    // 0x80073C90: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80073C94: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80073C98: addiu       $v0, $t8, 0x2
    ctx->r2 = ADD32(ctx->r24, 0X2);
L_80073C9C:
    // 0x80073C9C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80073CA0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073CA4: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80073CA8: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x80073CAC: slti        $at, $s1, 0xC0
    ctx->r1 = SIGNED(ctx->r17) < 0XC0 ? 1 : 0;
    // 0x80073CB0: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80073CB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80073CB8: bne         $at, $zero, L_80073C9C
    if (ctx->r1 != 0) {
        // 0x80073CBC: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_80073C9C;
    }
    // 0x80073CBC: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80073CC0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073CC4: jal         0x80073080
    // 0x80073CC8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_80072E28(rdram, ctx);
        goto after_10;
    // 0x80073CC8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_10:
    // 0x80073CCC: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80073CD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073CD4: addiu       $s2, $s2, 0xC0
    ctx->r18 = ADD32(ctx->r18, 0XC0);
    // 0x80073CD8: sw          $s2, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r18;
    // 0x80073CDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073CE0: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x80073CE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073CE8: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80073CEC: sw          $t3, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = ctx->r11;
    // 0x80073CF0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073CF4: jal         0x80073080
    // 0x80073CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_11;
    // 0x80073CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80073CFC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80073D00: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80073D04: blez        $t4, L_80073DF4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80073D08: nop
    
            goto L_80073DF4;
    }
    // 0x80073D08: nop

L_80073D0C:
    // 0x80073D0C: jal         0x8006B38C
    // 0x80073D10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_12;
    // 0x80073D10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80073D14: bne         $v0, $zero, L_80073DE4
    if (ctx->r2 != 0) {
        // 0x80073D18: lw          $t3, 0x48($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X48);
            goto L_80073DE4;
    }
    // 0x80073D18: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80073D1C: jal         0x8006B338
    // 0x80073D20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_13;
    // 0x80073D20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80073D24: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80073D28: sra         $t5, $s3, 16
    ctx->r13 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80073D2C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80073D30: beq         $t9, $zero, L_80073D68
    if (ctx->r25 == 0) {
        // 0x80073D34: or          $s3, $t5, $zero
        ctx->r19 = ctx->r13 | 0;
            goto L_80073D68;
    }
    // 0x80073D34: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x80073D38: lw          $t8, 0x3C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X3C);
    // 0x80073D3C: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073D40: addu        $t0, $t8, $s0
    ctx->r8 = ADD32(ctx->r24, ctx->r16);
    // 0x80073D44: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
    // 0x80073D48: jal         0x80073080
    // 0x80073D4C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_14;
    // 0x80073D4C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_14:
    // 0x80073D50: lw          $t1, 0x30($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X30);
    // 0x80073D54: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073D58: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073D5C: lhu         $a1, 0x0($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X0);
    // 0x80073D60: jal         0x80073080
    // 0x80073D64: nop

    func_80072E28(rdram, ctx);
        goto after_15;
    // 0x80073D64: nop

    after_15:
L_80073D68:
    // 0x80073D68: andi        $t3, $s3, 0x2
    ctx->r11 = ctx->r19 & 0X2;
    // 0x80073D6C: beq         $t3, $zero, L_80073DA8
    if (ctx->r11 == 0) {
        // 0x80073D70: andi        $t9, $s3, 0x4
        ctx->r25 = ctx->r19 & 0X4;
            goto L_80073DA8;
    }
    // 0x80073D70: andi        $t9, $s3, 0x4
    ctx->r25 = ctx->r19 & 0X4;
    // 0x80073D74: lw          $t4, 0x40($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X40);
    // 0x80073D78: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073D7C: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80073D80: lhu         $a1, 0x0($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0X0);
    // 0x80073D84: jal         0x80073080
    // 0x80073D88: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_16;
    // 0x80073D88: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_16:
    // 0x80073D8C: lw          $t6, 0x34($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X34);
    // 0x80073D90: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073D94: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80073D98: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x80073D9C: jal         0x80073080
    // 0x80073DA0: nop

    func_80072E28(rdram, ctx);
        goto after_17;
    // 0x80073DA0: nop

    after_17:
    // 0x80073DA4: andi        $t9, $s3, 0x4
    ctx->r25 = ctx->r19 & 0X4;
L_80073DA8:
    // 0x80073DA8: beq         $t9, $zero, L_80073DE4
    if (ctx->r25 == 0) {
        // 0x80073DAC: lw          $t3, 0x48($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X48);
            goto L_80073DE4;
    }
    // 0x80073DAC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80073DB0: lw          $t8, 0x44($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X44);
    // 0x80073DB4: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073DB8: addu        $t0, $t8, $s0
    ctx->r8 = ADD32(ctx->r24, ctx->r16);
    // 0x80073DBC: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
    // 0x80073DC0: jal         0x80073080
    // 0x80073DC4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_18;
    // 0x80073DC4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_18:
    // 0x80073DC8: lw          $t1, 0x38($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X38);
    // 0x80073DCC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073DD0: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073DD4: lhu         $a1, 0x0($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X0);
    // 0x80073DD8: jal         0x80073080
    // 0x80073DDC: nop

    func_80072E28(rdram, ctx);
        goto after_19;
    // 0x80073DDC: nop

    after_19:
    // 0x80073DE0: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
L_80073DE4:
    // 0x80073DE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073DE8: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80073DEC: bne         $at, $zero, L_80073D0C
    if (ctx->r1 != 0) {
        // 0x80073DF0: nop
    
            goto L_80073D0C;
    }
    // 0x80073DF0: nop

L_80073DF4:
    // 0x80073DF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073DF8: sw          $s2, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r18;
    // 0x80073DFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073E00: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80073E04: lw          $a0, 0x476C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X476C);
    // 0x80073E08: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x80073E0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073E10: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80073E14: sw          $t4, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = ctx->r12;
    // 0x80073E18: addiu       $a1, $a0, 0x2
    ctx->r5 = ADD32(ctx->r4, 0X2);
    // 0x80073E1C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80073E20: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x80073E24: addiu       $t6, $v1, 0x5
    ctx->r14 = ADD32(ctx->r3, 0X5);
    // 0x80073E28: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80073E2C: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x80073E30: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x80073E34: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x80073E38: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80073E3C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80073E40:
    // 0x80073E40: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80073E44: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x80073E48: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x80073E4C: addu        $t2, $v1, $t0
    ctx->r10 = ADD32(ctx->r3, ctx->r8);
    // 0x80073E50: lbu         $t8, 0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3);
    // 0x80073E54: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80073E58: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80073E5C: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x80073E60: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x80073E64: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80073E68: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80073E6C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80073E70: bne         $s1, $a0, L_80073E40
    if (ctx->r17 != ctx->r4) {
        // 0x80073E74: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80073E40;
    }
    // 0x80073E74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80073E78: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073E7C: jal         0x80073080
    // 0x80073E80: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_80072E28(rdram, ctx);
        goto after_20;
    // 0x80073E80: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_20:
    // 0x80073E84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80073E88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80073E8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80073E90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80073E94: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80073E98: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80073E9C: jr          $ra
    // 0x80073EA0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80073EA0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void get_game_data_file_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073EA4: jr          $ra
    // 0x80073EA8: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    return;
    // 0x80073EA8: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
;}
RECOMP_FUNC void get_time_data_file_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073EAC: jr          $ra
    // 0x80073EB0: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    return;
    // 0x80073EB0: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
;}
RECOMP_FUNC void get_file_extension(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073EB4: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x80073EB8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80073EBC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80073EC0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80073EC4: sw          $a1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r5;
    // 0x80073EC8: sw          $a2, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r6;
    // 0x80073ECC: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x80073ED0: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x80073ED4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80073ED8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80073EDC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80073EE0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80073EE4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80073EE8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80073EEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80073EF0: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    // 0x80073EF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80073EF8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80073EFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80073F00: addiu       $a2, $sp, 0x100
    ctx->r6 = ADD32(ctx->r29, 0X100);
    // 0x80073F04: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80073F08: jal         0x800760B8
    // 0x80073F0C: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    get_controller_pak_file_list(rdram, ctx);
        goto after_0;
    // 0x80073F0C: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    after_0:
    // 0x80073F10: bne         $v0, $zero, L_80074040
    if (ctx->r2 != 0) {
        // 0x80073F14: sw          $v0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r2;
            goto L_80074040;
    }
    // 0x80073F14: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80073F18: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x80073F1C: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80073F20: addiu       $s7, $s7, 0x7BD0
    ctx->r23 = ADD32(ctx->r23, 0X7BD0);
    // 0x80073F24: addiu       $fp, $fp, 0x7BC0
    ctx->r30 = ADD32(ctx->r30, 0X7BC0);
    // 0x80073F28: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80073F2C: addiu       $s0, $sp, 0x100
    ctx->r16 = ADD32(ctx->r29, 0X100);
    // 0x80073F30: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
    // 0x80073F34: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80073F38: addiu       $s5, $sp, 0x140
    ctx->r21 = ADD32(ctx->r29, 0X140);
L_80073F3C:
    // 0x80073F3C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80073F40: lw          $t9, 0x144($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X144);
    // 0x80073F44: beq         $t8, $zero, L_80073FD0
    if (ctx->r24 == 0) {
        // 0x80073F48: nop
    
            goto L_80073FD0;
    }
    // 0x80073F48: nop

    // 0x80073F4C: bne         $t9, $s6, L_80073F7C
    if (ctx->r25 != ctx->r22) {
        // 0x80073F50: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80073F7C;
    }
    // 0x80073F50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80073F54: jal         0x800CE6FC
    // 0x80073F58: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    strlen_recomp(rdram, ctx);
        goto after_1;
    // 0x80073F58: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x80073F5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80073F60: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80073F64: jal         0x800CE5B0
    // 0x80073F68: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    bcmp_recomp(rdram, ctx);
        goto after_2;
    // 0x80073F68: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80073F6C: beq         $v0, $zero, L_80073FA0
    if (ctx->r2 == 0) {
        // 0x80073F70: addu        $t0, $sp, $s3
        ctx->r8 = ADD32(ctx->r29, ctx->r19);
            goto L_80073FA0;
    }
    // 0x80073F70: addu        $t0, $sp, $s3
    ctx->r8 = ADD32(ctx->r29, ctx->r19);
    // 0x80073F74: b           L_80073FD4
    // 0x80073F78: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_80073FD4;
    // 0x80073F78: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80073F7C:
    // 0x80073F7C: jal         0x800CE6FC
    // 0x80073F80: addiu       $a0, $a0, 0x7BF0
    ctx->r4 = ADD32(ctx->r4, 0X7BF0);
    strlen_recomp(rdram, ctx);
        goto after_3;
    // 0x80073F80: addiu       $a0, $a0, 0x7BF0
    ctx->r4 = ADD32(ctx->r4, 0X7BF0);
    after_3:
    // 0x80073F84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80073F88: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80073F8C: addiu       $a1, $a1, 0x7BE0
    ctx->r5 = ADD32(ctx->r5, 0X7BE0);
    // 0x80073F90: jal         0x800CE5B0
    // 0x80073F94: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    bcmp_recomp(rdram, ctx);
        goto after_4;
    // 0x80073F94: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x80073F98: bne         $v0, $zero, L_80073FD0
    if (ctx->r2 != 0) {
        // 0x80073F9C: addu        $t0, $sp, $s3
        ctx->r8 = ADD32(ctx->r29, ctx->r19);
            goto L_80073FD0;
    }
    // 0x80073F9C: addu        $t0, $sp, $s3
    ctx->r8 = ADD32(ctx->r29, ctx->r19);
L_80073FA0:
    // 0x80073FA0: lw          $t0, 0xC0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XC0);
    // 0x80073FA4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80073FA8: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80073FAC: nop

    // 0x80073FB0: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80073FB4: beq         $at, $zero, L_80073FC4
    if (ctx->r1 == 0) {
        // 0x80073FB8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80073FC4;
    }
    // 0x80073FB8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073FBC: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x80073FC0: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
L_80073FC4:
    // 0x80073FC4: addiu       $t1, $v1, 0x1F
    ctx->r9 = ADD32(ctx->r3, 0X1F);
    // 0x80073FC8: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80073FCC: or          $s1, $s1, $t3
    ctx->r17 = ctx->r17 | ctx->r11;
L_80073FD0:
    // 0x80073FD0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80073FD4:
    // 0x80073FD4: bne         $s0, $s5, L_80073F3C
    if (ctx->r16 != ctx->r21) {
        // 0x80073FD8: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80073F3C;
    }
    // 0x80073FD8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80073FDC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80073FE0: lw          $v0, 0x148($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X148);
    // 0x80073FE4: bne         $s4, $at, L_80073FF8
    if (ctx->r20 != ctx->r1) {
        // 0x80073FE8: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_80073FF8;
    }
    // 0x80073FE8: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80073FEC: b           L_80074038
    // 0x80073FF0: addiu       $s2, $zero, 0x41
    ctx->r18 = ADD32(0, 0X41);
        goto L_80074038;
    // 0x80073FF0: addiu       $s2, $zero, 0x41
    ctx->r18 = ADD32(0, 0X41);
    // 0x80073FF4: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
L_80073FF8:
    // 0x80073FF8: bne         $s4, $at, L_80074030
    if (ctx->r20 != ctx->r1) {
        // 0x80073FFC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80074030;
    }
    // 0x80073FFC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80074000: addiu       $s2, $zero, 0x41
    ctx->r18 = ADD32(0, 0X41);
L_80074004:
    // 0x80074004: andi        $t4, $s1, 0x1
    ctx->r12 = ctx->r17 & 0X1;
    // 0x80074008: beq         $t4, $zero, L_80074038
    if (ctx->r12 == 0) {
        // 0x8007400C: sra         $t5, $s1, 1
        ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
            goto L_80074038;
    }
    // 0x8007400C: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80074010: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80074014: andi        $t6, $s2, 0xFF
    ctx->r14 = ctx->r18 & 0XFF;
    // 0x80074018: slti        $at, $t6, 0x5B
    ctx->r1 = SIGNED(ctx->r14) < 0X5B ? 1 : 0;
    // 0x8007401C: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x80074020: bne         $at, $zero, L_80074004
    if (ctx->r1 != 0) {
        // 0x80074024: or          $s1, $t5, $zero
        ctx->r17 = ctx->r13 | 0;
            goto L_80074004;
    }
    // 0x80074024: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x80074028: b           L_8007403C
    // 0x8007402C: sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
        goto L_8007403C;
    // 0x8007402C: sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
L_80074030:
    // 0x80074030: andi        $t7, $s2, 0xFF
    ctx->r15 = ctx->r18 & 0XFF;
    // 0x80074034: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_80074038:
    // 0x80074038: sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
L_8007403C:
    // 0x8007403C: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
L_80074040:
    // 0x80074040: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80074044: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x80074048: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007404C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80074050: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80074054: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80074058: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8007405C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80074060: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80074064: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80074068: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8007406C: jr          $ra
    // 0x80074070: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x80074070: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void read_game_data_from_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074074: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074078: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007407C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074080: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074084: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80074088: jal         0x80075B34
    // 0x8007408C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x8007408C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80074090: beq         $v0, $zero, L_800740B4
    if (ctx->r2 == 0) {
        // 0x80074094: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800740B4;
    }
    // 0x80074094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007409C: jal         0x80075D44
    // 0x800740A0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x800740A0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x800740A4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800740A8: sll         $t6, $s0, 30
    ctx->r14 = S32(ctx->r16 << 30);
    // 0x800740AC: b           L_800741A4
    // 0x800740B0: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
        goto L_800741A4;
    // 0x800740B0: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
L_800740B4:
    // 0x800740B4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800740B8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800740BC: addiu       $a1, $a1, 0x7C00
    ctx->r5 = ADD32(ctx->r5, 0X7C00);
    // 0x800740C0: jal         0x80076740
    // 0x800740C4: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x800740C4: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x800740C8: bne         $v0, $zero, L_80074180
    if (ctx->r2 != 0) {
        // 0x800740CC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80074180;
    }
    // 0x800740CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800740D0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800740D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800740D8: jal         0x80076B7C
    // 0x800740DC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    get_file_size(rdram, ctx);
        goto after_3;
    // 0x800740DC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x800740E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800740E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800740E8: bne         $a0, $zero, L_800740F4
    if (ctx->r4 != 0) {
        // 0x800740EC: nop
    
            goto L_800740F4;
    }
    // 0x800740EC: nop

    // 0x800740F0: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_800740F4:
    // 0x800740F4: bne         $v1, $zero, L_80074180
    if (ctx->r3 != 0) {
        // 0x800740F8: nop
    
            goto L_80074180;
    }
    // 0x800740F8: nop

    // 0x800740FC: jal         0x80070EDC
    // 0x80074100: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x80074100: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x80074104: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80074108: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8007410C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80074110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074114: jal         0x80076868
    // 0x80074118: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80074118: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x8007411C: bne         $v0, $zero, L_8007416C
    if (ctx->r2 != 0) {
        // 0x80074120: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8007416C;
    }
    // 0x80074120: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80074124: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80074128: lui         $at, 0x4741
    ctx->r1 = S32(0X4741 << 16);
    // 0x8007412C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80074130: ori         $at, $at, 0x4D44
    ctx->r1 = ctx->r1 | 0X4D44;
    // 0x80074134: bne         $t7, $at, L_8007416C
    if (ctx->r15 != ctx->r1) {
        // 0x80074138: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_8007416C;
    }
    // 0x80074138: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x8007413C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80074140: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80074144: jal         0x800732C4
    // 0x80074148: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    populate_settings_from_save_data(rdram, ctx);
        goto after_6;
    // 0x80074148: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_6:
    // 0x8007414C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80074150: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80074154: lbu         $t9, 0x4B($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4B);
    // 0x80074158: nop

    // 0x8007415C: beq         $t9, $zero, L_80074170
    if (ctx->r25 == 0) {
        // 0x80074160: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80074170;
    }
    // 0x80074160: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80074164: b           L_8007416C
    // 0x80074168: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_8007416C;
    // 0x80074168: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_8007416C:
    // 0x8007416C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80074170:
    // 0x80074170: jal         0x80071380
    // 0x80074174: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80074174: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_7:
    // 0x80074178: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8007417C: nop

L_80074180:
    // 0x80074180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074184: jal         0x80075D44
    // 0x80074188: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_8;
    // 0x80074188: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_8:
    // 0x8007418C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80074190: sll         $t0, $s0, 30
    ctx->r8 = S32(ctx->r16 << 30);
    // 0x80074194: beq         $v1, $zero, L_800741A4
    if (ctx->r3 == 0) {
        // 0x80074198: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800741A4;
    }
    // 0x80074198: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007419C: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x800741A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800741A4:
    // 0x800741A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800741A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800741AC: jr          $ra
    // 0x800741B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800741B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void write_game_data_to_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800741B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800741B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800741BC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800741C0: jal         0x80073EA4
    // 0x800741C4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    get_game_data_file_size(rdram, ctx);
        goto after_0;
    // 0x800741C4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800741C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800741CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800741D0: jal         0x80070EDC
    // 0x800741D4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800741D4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800741D8: lui         $t6, 0x4741
    ctx->r14 = S32(0X4741 << 16);
    // 0x800741DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800741E0: ori         $t6, $t6, 0x4D44
    ctx->r14 = ctx->r14 | 0X4D44;
    // 0x800741E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800741E8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800741EC: jal         0x80073540
    // 0x800741F0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800732E8(rdram, ctx);
        goto after_2;
    // 0x800741F0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_2:
    // 0x800741F4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800741F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800741FC: jal         0x80073EB4
    // 0x80074200: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    get_file_extension(rdram, ctx);
        goto after_3;
    // 0x80074200: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80074204: bne         $v0, $zero, L_80074238
    if (ctx->r2 != 0) {
        // 0x80074208: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80074238;
    }
    // 0x80074208: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007420C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80074210: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80074214: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80074218: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007421C: addiu       $a2, $a2, 0x7C10
    ctx->r6 = ADD32(ctx->r6, 0X7C10);
    // 0x80074220: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80074224: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x80074228: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8007422C: jal         0x8007692C
    // 0x80074230: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    write_controller_pak_file(rdram, ctx);
        goto after_4;
    // 0x80074230: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_4:
    // 0x80074234: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80074238:
    // 0x80074238: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8007423C: jal         0x80071380
    // 0x80074240: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80074240: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_5:
    // 0x80074244: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80074248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007424C: beq         $v1, $zero, L_80074268
    if (ctx->r3 == 0) {
        // 0x80074250: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80074268;
    }
    // 0x80074250: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80074254: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80074258: nop

    // 0x8007425C: sll         $t0, $t9, 30
    ctx->r8 = S32(ctx->r25 << 30);
    // 0x80074260: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x80074264: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80074268:
    // 0x80074268: jr          $ra
    // 0x8007426C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007426C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void read_time_data_from_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074270: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074274: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074278: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007427C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074280: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80074284: jal         0x80075B34
    // 0x80074288: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80074288: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007428C: beq         $v0, $zero, L_800742B0
    if (ctx->r2 == 0) {
        // 0x80074290: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800742B0;
    }
    // 0x80074290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074298: jal         0x80075D44
    // 0x8007429C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x8007429C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x800742A0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800742A4: sll         $t6, $s0, 30
    ctx->r14 = S32(ctx->r16 << 30);
    // 0x800742A8: b           L_80074390
    // 0x800742AC: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
        goto L_80074390;
    // 0x800742AC: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
L_800742B0:
    // 0x800742B0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800742B4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800742B8: addiu       $a1, $a1, 0x7C20
    ctx->r5 = ADD32(ctx->r5, 0X7C20);
    // 0x800742BC: jal         0x80076740
    // 0x800742C0: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x800742C0: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x800742C4: bne         $v0, $zero, L_8007436C
    if (ctx->r2 != 0) {
        // 0x800742C8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8007436C;
    }
    // 0x800742C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800742CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800742D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800742D4: jal         0x80076B7C
    // 0x800742D8: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    get_file_size(rdram, ctx);
        goto after_3;
    // 0x800742D8: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x800742DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800742E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800742E4: bne         $a0, $zero, L_800742F0
    if (ctx->r4 != 0) {
        // 0x800742E8: nop
    
            goto L_800742F0;
    }
    // 0x800742E8: nop

    // 0x800742EC: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_800742F0:
    // 0x800742F0: bne         $v1, $zero, L_8007436C
    if (ctx->r3 != 0) {
        // 0x800742F4: nop
    
            goto L_8007436C;
    }
    // 0x800742F4: nop

    // 0x800742F8: jal         0x80070EDC
    // 0x800742FC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800742FC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x80074300: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80074304: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80074308: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8007430C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074310: jal         0x80076868
    // 0x80074314: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80074314: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80074318: bne         $v0, $zero, L_80074358
    if (ctx->r2 != 0) {
        // 0x8007431C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80074358;
    }
    // 0x8007431C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80074320: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80074324: lui         $at, 0x5449
    ctx->r1 = S32(0X5449 << 16);
    // 0x80074328: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8007432C: ori         $at, $at, 0x4D44
    ctx->r1 = ctx->r1 | 0X4D44;
    // 0x80074330: bne         $t7, $at, L_80074358
    if (ctx->r15 != ctx->r1) {
        // 0x80074334: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_80074358;
    }
    // 0x80074334: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x80074338: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8007433C: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80074340: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80074344: jal         0x800737E0
    // 0x80074348: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80073588(rdram, ctx);
        goto after_6;
    // 0x80074348: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_6:
    // 0x8007434C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80074350: b           L_8007435C
    // 0x80074354: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
        goto L_8007435C;
    // 0x80074354: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80074358:
    // 0x80074358: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_8007435C:
    // 0x8007435C: jal         0x80071380
    // 0x80074360: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80074360: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_7:
    // 0x80074364: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80074368: nop

L_8007436C:
    // 0x8007436C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074370: jal         0x80075D44
    // 0x80074374: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_8;
    // 0x80074374: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_8:
    // 0x80074378: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8007437C: sll         $t8, $s0, 30
    ctx->r24 = S32(ctx->r16 << 30);
    // 0x80074380: beq         $v1, $zero, L_80074390
    if (ctx->r3 == 0) {
        // 0x80074384: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80074390;
    }
    // 0x80074384: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80074388: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
    // 0x8007438C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80074390:
    // 0x80074390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074394: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074398: jr          $ra
    // 0x8007439C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007439C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void write_time_data_to_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800743A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800743A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800743A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800743AC: jal         0x80073EAC
    // 0x800743B0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    get_time_data_file_size(rdram, ctx);
        goto after_0;
    // 0x800743B0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800743B4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800743B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800743BC: jal         0x80070EDC
    // 0x800743C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800743C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800743C4: lui         $t6, 0x5449
    ctx->r14 = S32(0X5449 << 16);
    // 0x800743C8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800743CC: ori         $t6, $t6, 0x4D44
    ctx->r14 = ctx->r14 | 0X4D44;
    // 0x800743D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800743D4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800743D8: jal         0x80073AFC
    // 0x800743DC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800738A4(rdram, ctx);
        goto after_2;
    // 0x800743DC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_2:
    // 0x800743E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800743E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800743E8: jal         0x80073EB4
    // 0x800743EC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    get_file_extension(rdram, ctx);
        goto after_3;
    // 0x800743EC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x800743F0: bne         $v0, $zero, L_80074424
    if (ctx->r2 != 0) {
        // 0x800743F4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80074424;
    }
    // 0x800743F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800743F8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800743FC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80074400: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80074404: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80074408: addiu       $a2, $a2, 0x7C30
    ctx->r6 = ADD32(ctx->r6, 0X7C30);
    // 0x8007440C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80074410: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x80074414: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80074418: jal         0x8007692C
    // 0x8007441C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    write_controller_pak_file(rdram, ctx);
        goto after_4;
    // 0x8007441C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_4:
    // 0x80074420: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80074424:
    // 0x80074424: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80074428: jal         0x80071380
    // 0x8007442C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8007442C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_5:
    // 0x80074430: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80074434: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074438: beq         $v1, $zero, L_80074454
    if (ctx->r3 == 0) {
        // 0x8007443C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80074454;
    }
    // 0x8007443C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80074440: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80074444: nop

    // 0x80074448: sll         $t0, $t9, 30
    ctx->r8 = S32(ctx->r25 << 30);
    // 0x8007444C: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x80074450: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80074454:
    // 0x80074454: jr          $ra
    // 0x80074458: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80074458: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void read_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007445C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074460: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80074464: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80074468: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007446C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80074470: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80074474: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80074478: jal         0x8006A340
    // 0x8007447C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x8007447C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80074480: jal         0x800CE770
    // 0x80074484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074488: bne         $v0, $zero, L_80074498
    if (ctx->r2 != 0) {
        // 0x8007448C: addiu       $s3, $zero, 0x5
        ctx->r19 = ADD32(0, 0X5);
            goto L_80074498;
    }
    // 0x8007448C: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x80074490: b           L_80074558
    // 0x80074494: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80074558;
    // 0x80074494: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074498:
    // 0x80074498: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8007449C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x800744A0: beq         $v0, $zero, L_800744C4
    if (ctx->r2 == 0) {
        // 0x800744A4: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800744C4;
    }
    // 0x800744A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800744A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800744AC: beq         $v0, $at, L_800744CC
    if (ctx->r2 == ctx->r1) {
        // 0x800744B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800744CC;
    }
    // 0x800744B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800744B4: beq         $v0, $at, L_800744D4
    if (ctx->r2 == ctx->r1) {
        // 0x800744B8: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_800744D4;
    }
    // 0x800744B8: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800744BC: b           L_800744D4
    // 0x800744C0: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_800744D4;
    // 0x800744C0: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_800744C4:
    // 0x800744C4: b           L_800744D4
    // 0x800744C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800744D4;
    // 0x800744C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800744CC:
    // 0x800744CC: b           L_800744D4
    // 0x800744D0: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_800744D4;
    // 0x800744D0: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_800744D4:
    // 0x800744D4: jal         0x80070EDC
    // 0x800744D8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800744D8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800744DC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800744E0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800744E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800744E8:
    // 0x800744E8: jal         0x8006A340
    // 0x800744EC: nop

    si_mesg(rdram, ctx);
        goto after_3;
    // 0x800744EC: nop

    after_3:
    // 0x800744F0: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x800744F4: addu        $a2, $t6, $s2
    ctx->r6 = ADD32(ctx->r14, ctx->r18);
    // 0x800744F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800744FC: jal         0x800CE7E0
    // 0x80074500: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    osEepromRead_recomp(rdram, ctx);
        goto after_4;
    // 0x80074500: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_4:
    // 0x80074504: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074508: bne         $s0, $s3, L_800744E8
    if (ctx->r16 != ctx->r19) {
        // 0x8007450C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800744E8;
    }
    // 0x8007450C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80074510: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80074514: jal         0x800732C4
    // 0x80074518: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    populate_settings_from_save_data(rdram, ctx);
        goto after_5;
    // 0x80074518: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x8007451C: jal         0x80071380
    // 0x80074520: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x80074520: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80074524: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80074528: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8007452C: lbu         $v1, 0x4B($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X4B);
    // 0x80074530: nop

    // 0x80074534: beq         $v1, $zero, L_80074558
    if (ctx->r3 == 0) {
        // 0x80074538: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80074558;
    }
    // 0x80074538: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007453C: jal         0x80074574
    // 0x80074540: nop

    erase_save_file(rdram, ctx);
        goto after_7;
    // 0x80074540: nop

    after_7:
    // 0x80074544: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80074548: nop

    // 0x8007454C: lbu         $v1, 0x4B($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X4B);
    // 0x80074550: nop

    // 0x80074554: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80074558:
    // 0x80074558: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007455C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80074560: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80074564: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80074568: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007456C: jr          $ra
    // 0x80074570: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80074570: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void erase_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074574: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80074578: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007457C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80074580: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80074584: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80074588: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007458C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80074590: jal         0x8006A340
    // 0x80074594: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074594: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80074598: jal         0x800CE770
    // 0x8007459C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x8007459C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800745A0: beq         $v0, $zero, L_80074718
    if (ctx->r2 == 0) {
        // 0x800745A4: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_80074718;
    }
    // 0x800745A4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800745A8: jal         0x8006B464
    // 0x800745AC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    level_count(rdram, ctx);
        goto after_2;
    // 0x800745AC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x800745B0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800745B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800745B8: blez        $t6, L_800745EC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800745BC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800745EC;
    }
    // 0x800745BC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800745C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800745C4:
    // 0x800745C4: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x800745C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800745CC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800745D0: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800745D4: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800745D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800745DC: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800745E0: bne         $at, $zero, L_800745C4
    if (ctx->r1 != 0) {
        // 0x800745E4: nop
    
            goto L_800745C4;
    }
    // 0x800745E4: nop

    // 0x800745E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800745EC:
    // 0x800745EC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800745F0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x800745F4: blez        $t0, L_80074628
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800745F8: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_80074628;
    }
    // 0x800745F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800745FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80074600:
    // 0x80074600: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80074604: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074608: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8007460C: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x80074610: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80074614: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80074618: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007461C: bne         $at, $zero, L_80074600
    if (ctx->r1 != 0) {
        // 0x80074620: nop
    
            goto L_80074600;
    }
    // 0x80074620: nop

    // 0x80074624: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80074628:
    // 0x80074628: sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
    // 0x8007462C: sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // 0x80074630: sh          $zero, 0x14($s1)
    MEM_H(0X14, ctx->r17) = 0;
    // 0x80074634: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x80074638: beq         $s2, $zero, L_8007465C
    if (ctx->r18 == 0) {
        // 0x8007463C: sb          $t4, 0x4B($s1)
        MEM_B(0X4B, ctx->r17) = ctx->r12;
            goto L_8007465C;
    }
    // 0x8007463C: sb          $t4, 0x4B($s1)
    MEM_B(0X4B, ctx->r17) = ctx->r12;
    // 0x80074640: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80074644: beq         $s2, $at, L_80074664
    if (ctx->r18 == ctx->r1) {
        // 0x80074648: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80074664;
    }
    // 0x80074648: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007464C: beq         $s2, $at, L_8007466C
    if (ctx->r18 == ctx->r1) {
        // 0x80074650: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_8007466C;
    }
    // 0x80074650: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80074654: b           L_8007466C
    // 0x80074658: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
        goto L_8007466C;
    // 0x80074658: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_8007465C:
    // 0x8007465C: b           L_8007466C
    // 0x80074660: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_8007466C;
    // 0x80074660: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80074664:
    // 0x80074664: b           L_8007466C
    // 0x80074668: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
        goto L_8007466C;
    // 0x80074668: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
L_8007466C:
    // 0x8007466C: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80074670: jal         0x80070EDC
    // 0x80074674: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80074674: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_3:
    // 0x80074678: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8007467C: b           L_800746A8
    // 0x80074680: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
        goto L_800746A8;
    // 0x80074680: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80074684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80074688: addu        $v1, $v0, $s0
    ctx->r3 = ADD32(ctx->r2, ctx->r16);
    // 0x8007468C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80074690:
    // 0x80074690: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074694: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x80074698: bne         $a1, $s0, L_80074690
    if (ctx->r5 != ctx->r16) {
        // 0x8007469C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80074690;
    }
    // 0x8007469C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800746A0: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800746A4: beq         $s0, $at, L_800746D0
    if (ctx->r16 == ctx->r1) {
        // 0x800746A8: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800746D0;
    }
L_800746A8:
    // 0x800746A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800746AC: sll         $a1, $s2, 3
    ctx->r5 = S32(ctx->r18 << 3);
    // 0x800746B0: addu        $v1, $v0, $s0
    ctx->r3 = ADD32(ctx->r2, ctx->r16);
L_800746B4:
    // 0x800746B4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800746B8: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x800746BC: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x800746C0: sb          $a0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r4;
    // 0x800746C4: sb          $a0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r4;
    // 0x800746C8: bne         $s0, $a1, L_800746B4
    if (ctx->r16 != ctx->r5) {
        // 0x800746CC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800746B4;
    }
    // 0x800746CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800746D0:
    // 0x800746D0: jal         0x8006ED00
    // 0x800746D4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    is_reset_pressed(rdram, ctx);
        goto after_4;
    // 0x800746D4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_4:
    // 0x800746D8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800746DC: bne         $v0, $zero, L_80074710
    if (ctx->r2 != 0) {
        // 0x800746E0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80074710;
    }
    // 0x800746E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800746E4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
L_800746E8:
    // 0x800746E8: jal         0x8006A340
    // 0x800746EC: nop

    si_mesg(rdram, ctx);
        goto after_5;
    // 0x800746EC: nop

    after_5:
    // 0x800746F0: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
    // 0x800746F4: addu        $a2, $t5, $s3
    ctx->r6 = ADD32(ctx->r13, ctx->r19);
    // 0x800746F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800746FC: jal         0x800CEAE0
    // 0x80074700: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    osEepromWrite_recomp(rdram, ctx);
        goto after_6;
    // 0x80074700: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_6:
    // 0x80074704: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074708: bne         $s0, $s2, L_800746E8
    if (ctx->r16 != ctx->r18) {
        // 0x8007470C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800746E8;
    }
    // 0x8007470C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80074710:
    // 0x80074710: jal         0x80071380
    // 0x80074714: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80074714: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
L_80074718:
    // 0x80074718: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007471C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80074720: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80074724: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80074728: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007472C: jr          $ra
    // 0x80074730: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80074730: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void write_save_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074734: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074738: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007473C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80074740: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80074744: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074748: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8007474C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80074750: jal         0x8006A340
    // 0x80074754: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074754: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_0:
    // 0x80074758: jal         0x800CE770
    // 0x8007475C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x8007475C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074760: bne         $v0, $zero, L_80074770
    if (ctx->r2 != 0) {
        // 0x80074764: addiu       $s2, $zero, 0x5
        ctx->r18 = ADD32(0, 0X5);
            goto L_80074770;
    }
    // 0x80074764: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80074768: b           L_8007480C
    // 0x8007476C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8007480C;
    // 0x8007476C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074770:
    // 0x80074770: beq         $s0, $zero, L_80074794
    if (ctx->r16 == 0) {
        // 0x80074774: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_80074794;
    }
    // 0x80074774: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80074778: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007477C: beq         $s0, $at, L_8007479C
    if (ctx->r16 == ctx->r1) {
        // 0x80074780: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007479C;
    }
    // 0x80074780: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80074784: beq         $s0, $at, L_800747A4
    if (ctx->r16 == ctx->r1) {
        // 0x80074788: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_800747A4;
    }
    // 0x80074788: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x8007478C: b           L_800747A4
    // 0x80074790: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_800747A4;
    // 0x80074790: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_80074794:
    // 0x80074794: b           L_800747A4
    // 0x80074798: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800747A4;
    // 0x80074798: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007479C:
    // 0x8007479C: b           L_800747A4
    // 0x800747A0: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_800747A4;
    // 0x800747A0: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_800747A4:
    // 0x800747A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800747A8: jal         0x80070EDC
    // 0x800747AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800747AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800747B0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800747B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800747B8: jal         0x80073540
    // 0x800747BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800732E8(rdram, ctx);
        goto after_3;
    // 0x800747BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x800747C0: jal         0x8006ED00
    // 0x800747C4: nop

    is_reset_pressed(rdram, ctx);
        goto after_4;
    // 0x800747C4: nop

    after_4:
    // 0x800747C8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800747CC: bne         $v0, $zero, L_80074800
    if (ctx->r2 != 0) {
        // 0x800747D0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80074800;
    }
    // 0x800747D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800747D4: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800747D8:
    // 0x800747D8: jal         0x8006A340
    // 0x800747DC: nop

    si_mesg(rdram, ctx);
        goto after_5;
    // 0x800747DC: nop

    after_5:
    // 0x800747E0: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x800747E4: addu        $a2, $t6, $s3
    ctx->r6 = ADD32(ctx->r14, ctx->r19);
    // 0x800747E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800747EC: jal         0x800CEAE0
    // 0x800747F0: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    osEepromWrite_recomp(rdram, ctx);
        goto after_6;
    // 0x800747F0: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_6:
    // 0x800747F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800747F8: bne         $s0, $s2, L_800747D8
    if (ctx->r16 != ctx->r18) {
        // 0x800747FC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800747D8;
    }
    // 0x800747FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80074800:
    // 0x80074800: jal         0x80071380
    // 0x80074804: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80074804: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x80074808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007480C:
    // 0x8007480C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80074810: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80074814: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80074818: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8007481C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80074820: jr          $ra
    // 0x80074824: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80074824: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void read_eeprom_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074828: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007482C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80074830: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074834: andi        $s0, $a1, 0xFF
    ctx->r16 = ctx->r5 & 0XFF;
    // 0x80074838: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007483C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80074840: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80074844: jal         0x8006A340
    // 0x80074848: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074848: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007484C: jal         0x800CE770
    // 0x80074850: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074850: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074854: bne         $v0, $zero, L_80074864
    if (ctx->r2 != 0) {
        // 0x80074858: addiu       $a0, $zero, 0x200
        ctx->r4 = ADD32(0, 0X200);
            goto L_80074864;
    }
    // 0x80074858: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x8007485C: b           L_80074930
    // 0x80074860: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80074930;
    // 0x80074860: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074864:
    // 0x80074864: jal         0x80070EDC
    // 0x80074868: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80074868: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x8007486C: andi        $t7, $s0, 0x1
    ctx->r15 = ctx->r16 & 0X1;
    // 0x80074870: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80074874: beq         $t7, $zero, L_800748C8
    if (ctx->r15 == 0) {
        // 0x80074878: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_800748C8;
    }
    // 0x80074878: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007487C: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // 0x80074880: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80074884:
    // 0x80074884: jal         0x8006A340
    // 0x80074888: nop

    si_mesg(rdram, ctx);
        goto after_3;
    // 0x80074888: nop

    after_3:
    // 0x8007488C: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x80074890: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80074894: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x80074898: addu        $a2, $t9, $s2
    ctx->r6 = ADD32(ctx->r25, ctx->r18);
    // 0x8007489C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800748A0: jal         0x800CE7E0
    // 0x800748A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromRead_recomp(rdram, ctx);
        goto after_4;
    // 0x800748A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800748A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800748AC: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800748B0: bne         $at, $zero, L_80074884
    if (ctx->r1 != 0) {
        // 0x800748B4: nop
    
            goto L_80074884;
    }
    // 0x800748B4: nop

    // 0x800748B8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800748BC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800748C0: jal         0x800737E0
    // 0x800748C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80073588(rdram, ctx);
        goto after_5;
    // 0x800748C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
L_800748C8:
    // 0x800748C8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800748CC: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // 0x800748D0: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800748D4: beq         $t1, $zero, L_80074924
    if (ctx->r9 == 0) {
        // 0x800748D8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80074924;
    }
    // 0x800748D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800748DC:
    // 0x800748DC: jal         0x8006A340
    // 0x800748E0: nop

    si_mesg(rdram, ctx);
        goto after_6;
    // 0x800748E0: nop

    after_6:
    // 0x800748E4: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x800748E8: sll         $t3, $s0, 3
    ctx->r11 = S32(ctx->r16 << 3);
    // 0x800748EC: addu        $a2, $s2, $t3
    ctx->r6 = ADD32(ctx->r18, ctx->r11);
    // 0x800748F0: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x800748F4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800748F8: addiu       $a2, $a2, 0xC0
    ctx->r6 = ADD32(ctx->r6, 0XC0);
    // 0x800748FC: jal         0x800CE7E0
    // 0x80074900: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromRead_recomp(rdram, ctx);
        goto after_7;
    // 0x80074900: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80074904: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074908: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8007490C: bne         $at, $zero, L_800748DC
    if (ctx->r1 != 0) {
        // 0x80074910: nop
    
            goto L_800748DC;
    }
    // 0x80074910: nop

    // 0x80074914: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80074918: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8007491C: jal         0x800737E0
    // 0x80074920: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80073588(rdram, ctx);
        goto after_8;
    // 0x80074920: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
L_80074924:
    // 0x80074924: jal         0x80071380
    // 0x80074928: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_9;
    // 0x80074928: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x8007492C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80074930:
    // 0x80074930: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80074934: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074938: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007493C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80074940: jr          $ra
    // 0x80074944: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80074944: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void write_eeprom_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074948: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007494C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80074950: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80074954: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074958: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007495C: andi        $s1, $a1, 0xFF
    ctx->r17 = ctx->r5 & 0XFF;
    // 0x80074960: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80074964: jal         0x8006A340
    // 0x80074968: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074968: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007496C: jal         0x800CE770
    // 0x80074970: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074970: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074974: bne         $v0, $zero, L_80074984
    if (ctx->r2 != 0) {
        // 0x80074978: addiu       $a0, $zero, 0x200
        ctx->r4 = ADD32(0, 0X200);
            goto L_80074984;
    }
    // 0x80074978: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x8007497C: b           L_80074A4C
    // 0x80074980: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80074A4C;
    // 0x80074980: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074984:
    // 0x80074984: jal         0x80070EDC
    // 0x80074988: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80074988: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x8007498C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80074990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074994: jal         0x80073AFC
    // 0x80074998: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800738A4(rdram, ctx);
        goto after_3;
    // 0x80074998: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8007499C: andi        $t7, $s1, 0x1
    ctx->r15 = ctx->r17 & 0X1;
    // 0x800749A0: beq         $t7, $zero, L_800749E8
    if (ctx->r15 == 0) {
        // 0x800749A4: sw          $s1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r17;
            goto L_800749E8;
    }
    // 0x800749A4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800749A8: jal         0x8006ED00
    // 0x800749AC: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    is_reset_pressed(rdram, ctx);
        goto after_4;
    // 0x800749AC: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    after_4:
    // 0x800749B0: bne         $v0, $zero, L_800749E8
    if (ctx->r2 != 0) {
        // 0x800749B4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800749E8;
    }
    // 0x800749B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800749B8:
    // 0x800749B8: jal         0x8006A340
    // 0x800749BC: nop

    si_mesg(rdram, ctx);
        goto after_5;
    // 0x800749BC: nop

    after_5:
    // 0x800749C0: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x800749C4: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x800749C8: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x800749CC: addu        $a2, $t9, $s2
    ctx->r6 = ADD32(ctx->r25, ctx->r18);
    // 0x800749D0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800749D4: jal         0x800CEAE0
    // 0x800749D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromWrite_recomp(rdram, ctx);
        goto after_6;
    // 0x800749D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x800749DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800749E0: bne         $s0, $s1, L_800749B8
    if (ctx->r16 != ctx->r17) {
        // 0x800749E4: nop
    
            goto L_800749B8;
    }
    // 0x800749E4: nop

L_800749E8:
    // 0x800749E8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800749EC: nop

    // 0x800749F0: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800749F4: beq         $t1, $zero, L_80074A40
    if (ctx->r9 == 0) {
        // 0x800749F8: nop
    
            goto L_80074A40;
    }
    // 0x800749F8: nop

    // 0x800749FC: jal         0x8006ED00
    // 0x80074A00: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    is_reset_pressed(rdram, ctx);
        goto after_7;
    // 0x80074A00: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    after_7:
    // 0x80074A04: bne         $v0, $zero, L_80074A40
    if (ctx->r2 != 0) {
        // 0x80074A08: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80074A40;
    }
    // 0x80074A08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80074A0C:
    // 0x80074A0C: jal         0x8006A340
    // 0x80074A10: nop

    si_mesg(rdram, ctx);
        goto after_8;
    // 0x80074A10: nop

    after_8:
    // 0x80074A14: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80074A18: sll         $t3, $s0, 3
    ctx->r11 = S32(ctx->r16 << 3);
    // 0x80074A1C: addu        $a2, $s2, $t3
    ctx->r6 = ADD32(ctx->r18, ctx->r11);
    // 0x80074A20: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x80074A24: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80074A28: addiu       $a2, $a2, 0xC0
    ctx->r6 = ADD32(ctx->r6, 0XC0);
    // 0x80074A2C: jal         0x800CEAE0
    // 0x80074A30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromWrite_recomp(rdram, ctx);
        goto after_9;
    // 0x80074A30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80074A34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074A38: bne         $s0, $s1, L_80074A0C
    if (ctx->r16 != ctx->r17) {
        // 0x80074A3C: nop
    
            goto L_80074A0C;
    }
    // 0x80074A3C: nop

L_80074A40:
    // 0x80074A40: jal         0x80071380
    // 0x80074A44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_10;
    // 0x80074A44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x80074A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80074A4C:
    // 0x80074A4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80074A50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074A54: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80074A58: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80074A5C: jr          $ra
    // 0x80074A60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80074A60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void calculate_eeprom_settings_checksum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074A64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80074A68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80074A6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80074A70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074A74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80074A78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80074A7C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80074A80: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x80074A84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80074A88: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
L_80074A8C:
    // 0x80074A8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80074A90: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80074A94: sll         $a3, $s0, 2
    ctx->r7 = S32(ctx->r16 << 2);
    // 0x80074A98: jal         0x800CEFC0
    // 0x80074A9C: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    __ull_rshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80074A9C: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_0:
    // 0x80074AA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074AA4: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x80074AA8: bne         $s0, $s2, L_80074A8C
    if (ctx->r16 != ctx->r18) {
        // 0x80074AAC: addu        $s1, $s1, $t9
        ctx->r17 = ADD32(ctx->r17, ctx->r25);
            goto L_80074A8C;
    }
    // 0x80074AAC: addu        $s1, $s1, $t9
    ctx->r17 = ADD32(ctx->r17, ctx->r25);
    // 0x80074AB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80074AB4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80074AB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80074ABC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074AC0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80074AC4: jr          $ra
    // 0x80074AC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80074AC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void read_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074ACC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80074AD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074AD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074AD8: jal         0x8006A340
    // 0x80074ADC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074ADC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80074AE0: jal         0x800CE770
    // 0x80074AE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074AE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074AE8: bne         $v0, $zero, L_80074AF8
    if (ctx->r2 != 0) {
        // 0x80074AEC: nop
    
            goto L_80074AF8;
    }
    // 0x80074AEC: nop

    // 0x80074AF0: b           L_80074BC4
    // 0x80074AF4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80074BC4;
    // 0x80074AF4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074AF8:
    // 0x80074AF8: jal         0x8006A340
    // 0x80074AFC: nop

    si_mesg(rdram, ctx);
        goto after_2;
    // 0x80074AFC: nop

    after_2:
    // 0x80074B00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074B04: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80074B08: jal         0x800CE7E0
    // 0x80074B0C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osEepromRead_recomp(rdram, ctx);
        goto after_3;
    // 0x80074B0C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80074B10: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80074B14: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80074B18: jal         0x80074A64
    // 0x80074B1C: nop

    calculate_eeprom_settings_checksum(rdram, ctx);
        goto after_4;
    // 0x80074B1C: nop

    after_4:
    // 0x80074B20: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80074B24: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80074B28: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80074B2C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074B30: jal         0x800CEFC0
    // 0x80074B34: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    __ull_rshift_recomp(rdram, ctx);
        goto after_5;
    // 0x80074B34: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_5:
    // 0x80074B38: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80074B3C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80074B40: beq         $t6, $v1, L_80074BC0
    if (ctx->r14 == ctx->r3) {
        // 0x80074B44: lui         $t9, 0x300
        ctx->r25 = S32(0X300 << 16);
            goto L_80074BC0;
    }
    // 0x80074B44: lui         $t9, 0x300
    ctx->r25 = S32(0X300 << 16);
    // 0x80074B48: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80074B4C: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80074B50: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80074B54: lui         $a1, 0x300
    ctx->r5 = S32(0X300 << 16);
    // 0x80074B58: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074B5C: jal         0x800CF064
    // 0x80074B60: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_lshift_recomp(rdram, ctx);
        goto after_6;
    // 0x80074B60: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_6:
    // 0x80074B64: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80074B68: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80074B6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074B70: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80074B74: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074B78: jal         0x800CEFC0
    // 0x80074B7C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ull_rshift_recomp(rdram, ctx);
        goto after_7;
    // 0x80074B7C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_7:
    // 0x80074B80: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80074B84: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80074B88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074B8C: jal         0x80074A64
    // 0x80074B90: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    calculate_eeprom_settings_checksum(rdram, ctx);
        goto after_8;
    // 0x80074B90: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_8:
    // 0x80074B94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80074B98: sra         $a0, $v0, 31
    ctx->r4 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80074B9C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074BA0: jal         0x800CF064
    // 0x80074BA4: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    __ll_lshift_recomp(rdram, ctx);
        goto after_9;
    // 0x80074BA4: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_9:
    // 0x80074BA8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80074BAC: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80074BB0: or          $t2, $t0, $v0
    ctx->r10 = ctx->r8 | ctx->r2;
    // 0x80074BB4: or          $t3, $t1, $v1
    ctx->r11 = ctx->r9 | ctx->r3;
    // 0x80074BB8: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80074BBC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
L_80074BC0:
    // 0x80074BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074BC4:
    // 0x80074BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074BC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074BCC: jr          $ra
    // 0x80074BD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80074BD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void write_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074BD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80074BD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074BDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074BE0: jal         0x8006A340
    // 0x80074BE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074BE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80074BE8: jal         0x800CE770
    // 0x80074BEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074BEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074BF0: bne         $v0, $zero, L_80074C00
    if (ctx->r2 != 0) {
        // 0x80074BF4: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_80074C00;
    }
    // 0x80074BF4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074BF8: b           L_80074C94
    // 0x80074BFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80074C94;
    // 0x80074BFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074C00:
    // 0x80074C00: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80074C04: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80074C08: jal         0x800CF064
    // 0x80074C0C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_lshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80074C0C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x80074C10: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80074C14: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80074C18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074C1C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80074C20: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074C24: jal         0x800CEFC0
    // 0x80074C28: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ull_rshift_recomp(rdram, ctx);
        goto after_3;
    // 0x80074C28: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_3:
    // 0x80074C2C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80074C30: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80074C34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074C38: jal         0x80074A64
    // 0x80074C3C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    calculate_eeprom_settings_checksum(rdram, ctx);
        goto after_4;
    // 0x80074C3C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x80074C40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80074C44: sra         $a0, $v0, 31
    ctx->r4 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80074C48: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074C4C: jal         0x800CF064
    // 0x80074C50: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    __ll_lshift_recomp(rdram, ctx);
        goto after_5;
    // 0x80074C50: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_5:
    // 0x80074C54: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80074C58: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80074C5C: or          $t8, $t6, $v0
    ctx->r24 = ctx->r14 | ctx->r2;
    // 0x80074C60: or          $t9, $t7, $v1
    ctx->r25 = ctx->r15 | ctx->r3;
    // 0x80074C64: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80074C68: jal         0x8006ED00
    // 0x80074C6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    is_reset_pressed(rdram, ctx);
        goto after_6;
    // 0x80074C6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    after_6:
    // 0x80074C70: bne         $v0, $zero, L_80074C94
    if (ctx->r2 != 0) {
        // 0x80074C74: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80074C94;
    }
    // 0x80074C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80074C78: jal         0x8006A340
    // 0x80074C7C: nop

    si_mesg(rdram, ctx);
        goto after_7;
    // 0x80074C7C: nop

    after_7:
    // 0x80074C80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074C84: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80074C88: jal         0x800CEAE0
    // 0x80074C8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osEepromWrite_recomp(rdram, ctx);
        goto after_8;
    // 0x80074C8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_8:
    // 0x80074C90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074C94:
    // 0x80074C94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074C98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074C9C: jr          $ra
    // 0x80074CA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80074CA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void calculate_ghost_header_checksum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074CA4: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x80074CA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80074CAC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80074CB0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80074CB4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80074CB8: addiu       $v0, $t8, 0x8
    ctx->r2 = ADD32(ctx->r24, 0X8);
    // 0x80074CBC: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80074CC0: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80074CC4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80074CC8: bne         $at, $zero, L_80074CF8
    if (ctx->r1 != 0) {
        // 0x80074CCC: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80074CF8;
    }
    // 0x80074CCC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80074CD0:
    // 0x80074CD0: addu        $t1, $a0, $a1
    ctx->r9 = ADD32(ctx->r4, ctx->r5);
    // 0x80074CD4: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80074CD8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80074CDC: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x80074CE0: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80074CE4: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x80074CE8: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80074CEC: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x80074CF0: bne         $at, $zero, L_80074CD0
    if (ctx->r1 != 0) {
        // 0x80074CF4: sra         $v1, $t3, 16
        ctx->r3 = S32(SIGNED(ctx->r11) >> 16);
            goto L_80074CD0;
    }
    // 0x80074CF4: sra         $v1, $t3, 16
    ctx->r3 = S32(SIGNED(ctx->r11) >> 16);
L_80074CF8:
    // 0x80074CF8: jr          $ra
    // 0x80074CFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80074CFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80074AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074D00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80074D04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074D08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074D0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80074D10: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80074D14: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80074D18: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80074D1C: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x80074D20: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80074D24: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x80074D28: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
    // 0x80074D2C: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x80074D30: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80074D34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074D38: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x80074D3C: sll         $a2, $t7, 2
    ctx->r6 = S32(ctx->r15 << 2);
    // 0x80074D40: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
    // 0x80074D44: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80074D48: subu        $a2, $a2, $t7
    ctx->r6 = SUB32(ctx->r6, ctx->r15);
    // 0x80074D4C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80074D50: jal         0x800CA300
    // 0x80074D54: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    bcopy_recomp(rdram, ctx);
        goto after_0;
    // 0x80074D54: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x80074D58: jal         0x80074CA4
    // 0x80074D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    calculate_ghost_header_checksum(rdram, ctx);
        goto after_1;
    // 0x80074D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80074D60: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80074D64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074D68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074D6C: jr          $ra
    // 0x80074D70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80074D70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void get_ghost_data_file_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074D74: addiu       $v1, $zero, 0x1100
    ctx->r3 = ADD32(0, 0X1100);
    // 0x80074D78: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80074D7C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80074D80: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80074D84: jr          $ra
    // 0x80074D88: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    return;
    // 0x80074D88: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
;}
RECOMP_FUNC void func_80074B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074D8C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80074D90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074D94: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80074D98: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80074D9C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80074DA0: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80074DA4: jal         0x80075B34
    // 0x80074DA8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80074DA8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    after_0:
    // 0x80074DAC: beq         $v0, $zero, L_80074DCC
    if (ctx->r2 == 0) {
        // 0x80074DB0: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_80074DCC;
    }
    // 0x80074DB0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80074DB4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80074DB8: jal         0x80075D44
    // 0x80074DBC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80074DBC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80074DC0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80074DC4: b           L_80075104
    // 0x80074DC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80075104;
    // 0x80074DC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80074DCC:
    // 0x80074DCC: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80074DD0: addiu       $a1, $a1, 0x7CCC
    ctx->r5 = ADD32(ctx->r5, 0X7CCC);
    // 0x80074DD4: beq         $v0, $zero, L_80074DF0
    if (ctx->r2 == 0) {
        // 0x80074DD8: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_80074DF0;
    }
    // 0x80074DD8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80074DDC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80074DE0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80074DE4: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x80074DE8: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x80074DEC: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
L_80074DF0:
    // 0x80074DF0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80074DF4: addiu       $a2, $a2, 0x7CDC
    ctx->r6 = ADD32(ctx->r6, 0X7CDC);
    // 0x80074DF8: jal         0x80076740
    // 0x80074DFC: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x80074DFC: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x80074E00: bne         $v0, $zero, L_80075088
    if (ctx->r2 != 0) {
        // 0x80074E04: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80075088;
    }
    // 0x80074E04: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80074E08: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80074E0C: jal         0x80070EDC
    // 0x80074E10: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80074E10: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_3:
    // 0x80074E14: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80074E18: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80074E1C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80074E20: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x80074E24: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80074E28: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80074E2C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80074E30: addiu       $t3, $t3, 0x4598
    ctx->r11 = ADD32(ctx->r11, 0X4598);
    // 0x80074E34: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80074E38: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80074E3C: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80074E40: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80074E44: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80074E48: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80074E4C: bne         $t6, $zero, L_80074E60
    if (ctx->r14 != 0) {
        // 0x80074E50: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80074E60;
    }
    // 0x80074E50: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80074E54: lw          $a0, 0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4590);
    // 0x80074E58: jal         0x800CF280
    // 0x80074E5C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_4;
    // 0x80074E5C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_4:
L_80074E60:
    // 0x80074E60: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80074E64: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80074E68: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80074E6C: jal         0x80076868
    // 0x80074E70: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80074E70: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_5:
    // 0x80074E74: lh          $t0, 0x5E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5E);
    // 0x80074E78: lh          $t1, 0x62($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X62);
    // 0x80074E7C: bne         $v0, $zero, L_80074F7C
    if (ctx->r2 != 0) {
        // 0x80074E80: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80074F7C;
    }
    // 0x80074E80: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80074E84: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80074E88: lui         $at, 0x4748
    ctx->r1 = S32(0X4748 << 16);
    // 0x80074E8C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80074E90: ori         $at, $at, 0x5353
    ctx->r1 = ctx->r1 | 0X5353;
    // 0x80074E94: bne         $t7, $at, L_80074F78
    if (ctx->r15 != ctx->r1) {
        // 0x80074E98: addiu       $a1, $a2, 0x4
        ctx->r5 = ADD32(ctx->r6, 0X4);
            goto L_80074F78;
    }
    // 0x80074E98: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80074E9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80074EA0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80074EA4:
    // 0x80074EA4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80074EA8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80074EAC: bne         $t0, $t8, L_80074EE4
    if (ctx->r8 != ctx->r24) {
        // 0x80074EB0: slti        $at, $v1, 0x18
        ctx->r1 = SIGNED(ctx->r3) < 0X18 ? 1 : 0;
            goto L_80074EE4;
    }
    // 0x80074EB0: slti        $at, $v1, 0x18
    ctx->r1 = SIGNED(ctx->r3) < 0X18 ? 1 : 0;
    // 0x80074EB4: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x80074EB8: nop

    // 0x80074EBC: bne         $t1, $t2, L_80074EE4
    if (ctx->r9 != ctx->r10) {
        // 0x80074EC0: nop
    
            goto L_80074EE4;
    }
    // 0x80074EC0: nop

    // 0x80074EC4: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x80074EC8: nop

    // 0x80074ECC: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80074ED0: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x80074ED4: nop

    // 0x80074ED8: subu        $t4, $t5, $t3
    ctx->r12 = SUB32(ctx->r13, ctx->r11);
    // 0x80074EDC: b           L_80074EEC
    // 0x80074EE0: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
        goto L_80074EEC;
    // 0x80074EE0: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
L_80074EE4:
    // 0x80074EE4: bne         $at, $zero, L_80074EA4
    if (ctx->r1 != 0) {
        // 0x80074EE8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80074EA4;
    }
    // 0x80074EE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80074EEC:
    // 0x80074EEC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80074EF0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80074EF4: bne         $t9, $zero, L_80074F7C
    if (ctx->r25 != 0) {
        // 0x80074EF8: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80074F7C;
    }
    // 0x80074EF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80074EFC: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80074F00: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80074F04: bne         $v1, $t7, L_80074F10
    if (ctx->r3 != ctx->r15) {
        // 0x80074F08: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80074F10;
    }
    // 0x80074F08: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80074F0C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074F10:
    // 0x80074F10: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x80074F14: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80074F18: bne         $v1, $t8, L_80074F24
    if (ctx->r3 != ctx->r24) {
        // 0x80074F1C: addu        $v0, $a1, $t2
        ctx->r2 = ADD32(ctx->r5, ctx->r10);
            goto L_80074F24;
    }
    // 0x80074F1C: addu        $v0, $a1, $t2
    ctx->r2 = ADD32(ctx->r5, ctx->r10);
    // 0x80074F20: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074F24:
    // 0x80074F24: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80074F28: nop

    // 0x80074F2C: bne         $v1, $t3, L_80074F38
    if (ctx->r3 != ctx->r11) {
        // 0x80074F30: nop
    
            goto L_80074F38;
    }
    // 0x80074F30: nop

    // 0x80074F34: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074F38:
    // 0x80074F38: lbu         $t5, 0x4($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4);
    // 0x80074F3C: nop

    // 0x80074F40: bne         $v1, $t5, L_80074F4C
    if (ctx->r3 != ctx->r13) {
        // 0x80074F44: nop
    
            goto L_80074F4C;
    }
    // 0x80074F44: nop

    // 0x80074F48: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074F4C:
    // 0x80074F4C: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x80074F50: nop

    // 0x80074F54: bne         $v1, $t6, L_80074F60
    if (ctx->r3 != ctx->r14) {
        // 0x80074F58: nop
    
            goto L_80074F60;
    }
    // 0x80074F58: nop

    // 0x80074F5C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074F60:
    // 0x80074F60: lbu         $t4, 0xC($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XC);
    // 0x80074F64: nop

    // 0x80074F68: bne         $v1, $t4, L_80074F80
    if (ctx->r3 != ctx->r12) {
        // 0x80074F6C: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80074F80;
    }
    // 0x80074F6C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80074F70: b           L_80074F7C
    // 0x80074F74: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
        goto L_80074F7C;
    // 0x80074F74: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074F78:
    // 0x80074F78: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
L_80074F7C:
    // 0x80074F7C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_80074F80:
    // 0x80074F80: jal         0x80071380
    // 0x80074F84: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x80074F84: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80074F88: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80074F8C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80074F90: beq         $t9, $zero, L_80075070
    if (ctx->r25 == 0) {
        // 0x80074F94: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_80075070;
    }
    // 0x80074F94: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80074F98: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80074F9C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80074FA0: beq         $t7, $zero, L_8007506C
    if (ctx->r15 == 0) {
        // 0x80074FA4: addiu       $a0, $a0, 0x100
        ctx->r4 = ADD32(ctx->r4, 0X100);
            goto L_8007506C;
    }
    // 0x80074FA4: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x80074FA8: jal         0x80070EDC
    // 0x80074FAC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x80074FAC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_7:
    // 0x80074FB0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80074FB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80074FB8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80074FBC: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80074FC0: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80074FC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80074FC8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80074FCC: jal         0x800CF53C
    // 0x80074FD0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_8;
    // 0x80074FD0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_8:
    // 0x80074FD4: bne         $v0, $zero, L_80075058
    if (ctx->r2 != 0) {
        // 0x80074FD8: addiu       $a3, $zero, 0x9
        ctx->r7 = ADD32(0, 0X9);
            goto L_80075058;
    }
    // 0x80074FD8: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x80074FDC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80074FE0: jal         0x80074CA4
    // 0x80074FE4: nop

    calculate_ghost_header_checksum(rdram, ctx);
        goto after_9;
    // 0x80074FE4: nop

    after_9:
    // 0x80074FE8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80074FEC: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80074FF0: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80074FF4: nop

    // 0x80074FF8: bne         $v0, $t3, L_80075050
    if (ctx->r2 != ctx->r11) {
        // 0x80074FFC: nop
    
            goto L_80075050;
    }
    // 0x80074FFC: nop

    // 0x80075000: lbu         $t5, 0x2($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X2);
    // 0x80075004: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80075008: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x8007500C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80075010: lh          $t4, 0x4($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X4);
    // 0x80075014: nop

    // 0x80075018: sh          $t4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r12;
    // 0x8007501C: lh          $t7, 0x6($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X6);
    // 0x80075020: nop

    // 0x80075024: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80075028: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8007502C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075030: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80075034: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80075038: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x8007503C: sll         $a2, $t8, 2
    ctx->r6 = S32(ctx->r24 << 2);
    // 0x80075040: jal         0x800CA300
    // 0x80075044: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    bcopy_recomp(rdram, ctx);
        goto after_10;
    // 0x80075044: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_10:
    // 0x80075048: b           L_80075058
    // 0x8007504C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80075058;
    // 0x8007504C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80075050:
    // 0x80075050: b           L_80075058
    // 0x80075054: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
        goto L_80075058;
    // 0x80075054: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
L_80075058:
    // 0x80075058: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007505C: jal         0x80071380
    // 0x80075060: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    mempool_free(rdram, ctx);
        goto after_11;
    // 0x80075060: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_11:
    // 0x80075064: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80075068: nop

L_8007506C:
    // 0x8007506C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
L_80075070:
    // 0x80075070: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80075074: beq         $t3, $zero, L_8007508C
    if (ctx->r11 == 0) {
        // 0x80075078: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_8007508C;
    }
    // 0x80075078: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8007507C: bne         $t5, $zero, L_8007508C
    if (ctx->r13 != 0) {
        // 0x80075080: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_8007508C;
    }
    // 0x80075080: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80075084: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80075088:
    // 0x80075088: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
L_8007508C:
    // 0x8007508C: jal         0x80075D44
    // 0x80075090: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    start_reading_controller_data(rdram, ctx);
        goto after_12;
    // 0x80075090: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_12:
    // 0x80075094: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80075098: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007509C: bne         $a3, $at, L_800750FC
    if (ctx->r7 != ctx->r1) {
        // 0x800750A0: addiu       $a1, $sp, 0x38
        ctx->r5 = ADD32(ctx->r29, 0X38);
            goto L_800750FC;
    }
    // 0x800750A0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800750A4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800750A8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800750AC: jal         0x800763EC
    // 0x800750B0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    get_free_space(rdram, ctx);
        goto after_13;
    // 0x800750B0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_13:
    // 0x800750B4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800750B8: bne         $v0, $zero, L_800750F4
    if (ctx->r2 != 0) {
        // 0x800750BC: nop
    
            goto L_800750F4;
    }
    // 0x800750BC: nop

    // 0x800750C0: jal         0x80074D74
    // 0x800750C4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    get_ghost_data_file_size(rdram, ctx);
        goto after_14;
    // 0x800750C4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_14:
    // 0x800750C8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800750CC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800750D0: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800750D4: bne         $at, $zero, L_800750EC
    if (ctx->r1 != 0) {
        // 0x800750D8: nop
    
            goto L_800750EC;
    }
    // 0x800750D8: nop

    // 0x800750DC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800750E0: nop

    // 0x800750E4: bne         $t4, $zero, L_80075100
    if (ctx->r12 != 0) {
        // 0x800750E8: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_80075100;
    }
    // 0x800750E8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800750EC:
    // 0x800750EC: b           L_80075100
    // 0x800750F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80075100;
    // 0x800750F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800750F4:
    // 0x800750F4: b           L_80075100
    // 0x800750F8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_80075100;
    // 0x800750F8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_800750FC:
    // 0x800750FC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80075100:
    // 0x80075100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80075104:
    // 0x80075104: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80075108: jr          $ra
    // 0x8007510C: nop

    return;
    // 0x8007510C: nop

;}
RECOMP_FUNC void func_80074EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075110: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80075114: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80075118: addiu       $a2, $zero, 0x1100
    ctx->r6 = ADD32(0, 0X1100);
    // 0x8007511C: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x80075120: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80075124: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80075128: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8007512C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80075130: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80075134: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80075138: addiu       $a0, $v0, 0x200
    ctx->r4 = ADD32(ctx->r2, 0X200);
    // 0x8007513C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80075140: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80075144: jal         0x80070EDC
    // 0x80075148: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80075148: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007514C: lui         $t6, 0x4748
    ctx->r14 = S32(0X4748 << 16);
    // 0x80075150: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80075154: ori         $t6, $t6, 0x5353
    ctx->r14 = ctx->r14 | 0X5353;
    // 0x80075158: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007515C: lh          $t7, 0x46($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X46);
    // 0x80075160: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80075164: sb          $t7, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r15;
    // 0x80075168: lh          $t8, 0x4A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4A);
    // 0x8007516C: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x80075170: lh          $t2, 0x6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6);
    // 0x80075174: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80075178: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x8007517C: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x80075180: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
    // 0x80075184: sb          $t8, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r24;
    // 0x80075188: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x8007518C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80075190: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x80075194: lh          $t4, 0x6($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X6);
    // 0x80075198: sb          $a0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r4;
    // 0x8007519C: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x800751A0: lh          $t5, 0x6($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X6);
    // 0x800751A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800751A8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800751AC: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // 0x800751B0: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x800751B4: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800751B8: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x800751BC: sb          $a0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r4;
    // 0x800751C0: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x800751C4: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    // 0x800751C8: sb          $a0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r4;
    // 0x800751CC: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x800751D0: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x800751D4: sb          $a0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r4;
    // 0x800751D8: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x800751DC: lh          $t2, 0x6($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6);
    // 0x800751E0: nop

    // 0x800751E4: sh          $t2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r10;
    // 0x800751E8: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x800751EC: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800751F0: lh          $a3, 0x56($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X56);
    // 0x800751F4: lh          $a2, 0x52($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X52);
    // 0x800751F8: lh          $a1, 0x4E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4E);
    // 0x800751FC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80075200: addu        $a0, $t3, $t1
    ctx->r4 = ADD32(ctx->r11, ctx->r9);
    // 0x80075204: jal         0x80074D00
    // 0x80075208: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_80074AA8(rdram, ctx);
        goto after_1;
    // 0x80075208: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_1:
    // 0x8007520C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80075210: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80075214: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80075218: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007521C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80075220: addiu       $t7, $t6, 0x100
    ctx->r15 = ADD32(ctx->r14, 0X100);
    // 0x80075224: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80075228: addiu       $a3, $a3, 0x7D08
    ctx->r7 = ADD32(ctx->r7, 0X7D08);
    // 0x8007522C: addiu       $a2, $a2, 0x7CF8
    ctx->r6 = ADD32(ctx->r6, 0X7CF8);
    // 0x80075230: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80075234: jal         0x8007692C
    // 0x80075238: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    write_controller_pak_file(rdram, ctx);
        goto after_2;
    // 0x80075238: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x8007523C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80075240: jal         0x80071380
    // 0x80075244: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80075244: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x80075248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007524C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80075250: jr          $ra
    // 0x80075254: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80075254: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80075000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075258: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8007525C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80075260: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80075264: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80075268: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007526C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80075270: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80075274: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80075278: jal         0x80075B34
    // 0x8007527C: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x8007527C: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    after_0:
    // 0x80075280: beq         $v0, $zero, L_8007529C
    if (ctx->r2 == 0) {
        // 0x80075284: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8007529C;
    }
    // 0x80075284: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80075288: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8007528C: jal         0x80075D44
    // 0x80075290: nop

    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80075290: nop

    after_1:
    // 0x80075294: b           L_80075618
    // 0x80075298: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80075618;
    // 0x80075298: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8007529C:
    // 0x8007529C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800752A0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800752A4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800752A8: addiu       $s1, $zero, 0x1100
    ctx->r17 = ADD32(0, 0X1100);
    // 0x800752AC: addiu       $a2, $a2, 0x7D1C
    ctx->r6 = ADD32(ctx->r6, 0X7D1C);
    // 0x800752B0: addiu       $a1, $a1, 0x7D0C
    ctx->r5 = ADD32(ctx->r5, 0X7D0C);
    // 0x800752B4: jal         0x80076740
    // 0x800752B8: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x800752B8: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x800752BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800752C0: bne         $v0, $at, L_80075308
    if (ctx->r2 != ctx->r1) {
        // 0x800752C4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80075308;
    }
    // 0x800752C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800752C8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800752CC: jal         0x80075D44
    // 0x800752D0: nop

    start_reading_controller_data(rdram, ctx);
        goto after_3;
    // 0x800752D0: nop

    after_3:
    // 0x800752D4: lh          $t6, 0x8A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8A);
    // 0x800752D8: lh          $t7, 0x8E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8E);
    // 0x800752DC: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800752E0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800752E4: lh          $a1, 0x7E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X7E);
    // 0x800752E8: lh          $a2, 0x82($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X82);
    // 0x800752EC: lh          $a3, 0x86($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X86);
    // 0x800752F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800752F4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800752F8: jal         0x80075110
    // 0x800752FC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80074EB8(rdram, ctx);
        goto after_4;
    // 0x800752FC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_4:
    // 0x80075300: b           L_8007561C
    // 0x80075304: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8007561C;
    // 0x80075304: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80075308:
    // 0x80075308: beq         $v0, $zero, L_80075328
    if (ctx->r2 == 0) {
        // 0x8007530C: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80075328;
    }
    // 0x8007530C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80075310: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80075314: jal         0x80075D44
    // 0x80075318: nop

    start_reading_controller_data(rdram, ctx);
        goto after_5;
    // 0x80075318: nop

    after_5:
    // 0x8007531C: b           L_80075618
    // 0x80075320: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80075618;
    // 0x80075320: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80075324: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_80075328:
    // 0x80075328: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8007532C: jal         0x80076B7C
    // 0x80075330: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    get_file_size(rdram, ctx);
        goto after_6;
    // 0x80075330: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_6:
    // 0x80075334: beq         $v0, $zero, L_80075350
    if (ctx->r2 == 0) {
        // 0x80075338: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80075350;
    }
    // 0x80075338: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007533C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80075340: jal         0x80075D44
    // 0x80075344: nop

    start_reading_controller_data(rdram, ctx);
        goto after_7;
    // 0x80075344: nop

    after_7:
    // 0x80075348: b           L_80075618
    // 0x8007534C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80075618;
    // 0x8007534C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80075350:
    // 0x80075350: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80075354: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80075358: jal         0x80070EDC
    // 0x8007535C: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x8007535C: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_8:
    // 0x80075360: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80075364: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80075368: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8007536C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80075370: jal         0x80076868
    // 0x80075374: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_9;
    // 0x80075374: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_9:
    // 0x80075378: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8007537C: jal         0x80075D44
    // 0x80075380: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_10;
    // 0x80075380: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_10:
    // 0x80075384: beq         $s0, $zero, L_8007539C
    if (ctx->r16 == 0) {
        // 0x80075388: lui         $at, 0x4748
        ctx->r1 = S32(0X4748 << 16);
            goto L_8007539C;
    }
    // 0x80075388: lui         $at, 0x4748
    ctx->r1 = S32(0X4748 << 16);
    // 0x8007538C: jal         0x80071380
    // 0x80075390: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_11;
    // 0x80075390: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x80075394: b           L_80075618
    // 0x80075398: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80075618;
    // 0x80075398: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8007539C:
    // 0x8007539C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800753A0: ori         $at, $at, 0x5353
    ctx->r1 = ctx->r1 | 0X5353;
    // 0x800753A4: bne         $t9, $at, L_8007560C
    if (ctx->r25 != ctx->r1) {
        // 0x800753A8: addiu       $s0, $zero, 0x9
        ctx->r16 = ADD32(0, 0X9);
            goto L_8007560C;
    }
    // 0x800753A8: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
    // 0x800753AC: addiu       $a2, $s2, 0x4
    ctx->r6 = ADD32(ctx->r18, 0X4);
    // 0x800753B0: lh          $t3, 0x82($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X82);
    // 0x800753B4: lh          $t2, 0x7E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X7E);
    // 0x800753B8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800753BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800753C0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_800753C4:
    // 0x800753C4: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x800753C8: nop

    // 0x800753CC: bne         $t2, $t4, L_800753EC
    if (ctx->r10 != ctx->r12) {
        // 0x800753D0: nop
    
            goto L_800753EC;
    }
    // 0x800753D0: nop

    // 0x800753D4: lbu         $t5, 0x1($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1);
    // 0x800753D8: nop

    // 0x800753DC: bne         $t3, $t5, L_800753EC
    if (ctx->r11 != ctx->r13) {
        // 0x800753E0: nop
    
            goto L_800753EC;
    }
    // 0x800753E0: nop

    // 0x800753E4: b           L_800753FC
    // 0x800753E8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
        goto L_800753FC;
    // 0x800753E8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
L_800753EC:
    // 0x800753EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800753F0: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x800753F4: bne         $at, $zero, L_800753C4
    if (ctx->r1 != 0) {
        // 0x800753F8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800753C4;
    }
    // 0x800753F8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800753FC:
    // 0x800753FC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80075400: beq         $t1, $a0, L_80075430
    if (ctx->r9 == ctx->r4) {
        // 0x80075404: sll         $t6, $t1, 2
        ctx->r14 = S32(ctx->r9 << 2);
            goto L_80075430;
    }
    // 0x80075404: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80075408: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x8007540C: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80075410: lh          $t9, 0x8A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X8A);
    // 0x80075414: addu        $v1, $t8, $s2
    ctx->r3 = ADD32(ctx->r24, ctx->r18);
    // 0x80075418: lh          $v1, 0x4($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4);
    // 0x8007541C: nop

    // 0x80075420: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80075424: beq         $at, $zero, L_80075430
    if (ctx->r1 == 0) {
        // 0x80075428: nop
    
            goto L_80075430;
    }
    // 0x80075428: nop

    // 0x8007542C: addiu       $t1, $zero, -0x2
    ctx->r9 = ADD32(0, -0X2);
L_80075430:
    // 0x80075430: bne         $t1, $a0, L_8007546C
    if (ctx->r9 != ctx->r4) {
        // 0x80075434: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8007546C;
    }
    // 0x80075434: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80075438: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007543C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80075440: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80075444: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80075448:
    // 0x80075448: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x8007544C: nop

    // 0x80075450: bne         $v0, $t4, L_80075460
    if (ctx->r2 != ctx->r12) {
        // 0x80075454: nop
    
            goto L_80075460;
    }
    // 0x80075454: nop

    // 0x80075458: b           L_8007546C
    // 0x8007545C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
        goto L_8007546C;
    // 0x8007545C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
L_80075460:
    // 0x80075460: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80075464: bne         $v1, $a3, L_80075448
    if (ctx->r3 != ctx->r7) {
        // 0x80075468: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80075448;
    }
    // 0x80075468: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8007546C:
    // 0x8007546C: bne         $t1, $at, L_8007547C
    if (ctx->r9 != ctx->r1) {
        // 0x80075470: nop
    
            goto L_8007547C;
    }
    // 0x80075470: nop

    // 0x80075474: b           L_8007560C
    // 0x80075478: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8007560C;
    // 0x80075478: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007547C:
    // 0x8007547C: bne         $t1, $a0, L_8007548C
    if (ctx->r9 != ctx->r4) {
        // 0x80075480: sll         $t0, $t1, 2
        ctx->r8 = S32(ctx->r9 << 2);
            goto L_8007548C;
    }
    // 0x80075480: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80075484: b           L_8007560C
    // 0x80075488: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
        goto L_8007560C;
    // 0x80075488: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_8007548C:
    // 0x8007548C: addu        $v0, $a2, $t0
    ctx->r2 = ADD32(ctx->r6, ctx->r8);
    // 0x80075490: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x80075494: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80075498: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8007549C: subu        $t6, $s1, $t5
    ctx->r14 = SUB32(ctx->r17, ctx->r13);
    // 0x800754A0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800754A4: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x800754A8: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800754AC: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x800754B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800754B4: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800754B8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800754BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800754C0: jal         0x80070EDC
    // 0x800754C4: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_12;
    // 0x800754C4: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_12:
    // 0x800754C8: lui         $t9, 0x4748
    ctx->r25 = S32(0X4748 << 16);
    // 0x800754CC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800754D0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800754D4: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x800754D8: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800754DC: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x800754E0: ori         $t9, $t9, 0x5353
    ctx->r25 = ctx->r25 | 0X5353;
    // 0x800754E4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800754E8: addiu       $t4, $v0, 0x4
    ctx->r12 = ADD32(ctx->r2, 0X4);
    // 0x800754EC: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x800754F0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800754F4: sb          $t5, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r13;
    // 0x800754F8: lh          $t6, 0x1A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A);
    // 0x800754FC: nop

    // 0x80075500: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80075504: sh          $t7, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r15;
    // 0x80075508: lw          $s1, 0x70($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X70);
    // 0x8007550C: nop

L_80075510:
    // 0x80075510: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x80075514: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80075518: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x8007551C: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x80075520: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80075524: bne         $at, $zero, L_80075538
    if (ctx->r1 != 0) {
        // 0x80075528: sb          $t9, 0x1($s1)
        MEM_B(0X1, ctx->r17) = ctx->r25;
            goto L_80075538;
    }
    // 0x80075528: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x8007552C: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80075530: b           L_80075548
    // 0x80075534: sh          $t4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r12;
        goto L_80075548;
    // 0x80075534: sh          $t4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r12;
L_80075538:
    // 0x80075538: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x8007553C: nop

    // 0x80075540: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x80075544: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
L_80075548:
    // 0x80075548: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x8007554C: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80075550: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x80075554: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80075558: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8007555C: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x80075560: addu        $a0, $v0, $s2
    ctx->r4 = ADD32(ctx->r2, ctx->r18);
    // 0x80075564: subu        $a2, $t9, $v0
    ctx->r6 = SUB32(ctx->r25, ctx->r2);
    // 0x80075568: jal         0x800CA300
    // 0x8007556C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    bcopy_recomp(rdram, ctx);
        goto after_13;
    // 0x8007556C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_13:
    // 0x80075570: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x80075574: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80075578: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8007557C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80075580: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80075584: bne         $v1, $a3, L_80075510
    if (ctx->r3 != ctx->r7) {
        // 0x80075588: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80075510;
    }
    // 0x80075588: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8007558C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80075590: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80075594: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80075598: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x8007559C: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x800755A0: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800755A4: lh          $a1, 0x86($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X86);
    // 0x800755A8: lh          $a2, 0x8A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X8A);
    // 0x800755AC: lh          $a3, 0x8E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X8E);
    // 0x800755B0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800755B4: jal         0x80074D00
    // 0x800755B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80074AA8(rdram, ctx);
        goto after_14;
    // 0x800755B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_14:
    // 0x800755BC: lh          $t9, 0x7E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X7E);
    // 0x800755C0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800755C4: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800755C8: lh          $t4, 0x82($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X82);
    // 0x800755CC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800755D0: sb          $t4, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r12;
    // 0x800755D4: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800755D8: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800755DC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800755E0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800755E4: addiu       $a3, $a3, 0x7D30
    ctx->r7 = ADD32(ctx->r7, 0X7D30);
    // 0x800755E8: addiu       $a2, $a2, 0x7D20
    ctx->r6 = ADD32(ctx->r6, 0X7D20);
    // 0x800755EC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800755F0: jal         0x8007692C
    // 0x800755F4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    write_controller_pak_file(rdram, ctx);
        goto after_15;
    // 0x800755F4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_15:
    // 0x800755F8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800755FC: jal         0x80071380
    // 0x80075600: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    mempool_free(rdram, ctx);
        goto after_16;
    // 0x80075600: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_16:
    // 0x80075604: b           L_8007560C
    // 0x80075608: nop

        goto L_8007560C;
    // 0x80075608: nop

L_8007560C:
    // 0x8007560C: jal         0x80071380
    // 0x80075610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_17;
    // 0x80075610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x80075614: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80075618:
    // 0x80075618: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8007561C:
    // 0x8007561C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80075620: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80075624: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80075628: jr          $ra
    // 0x8007562C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8007562C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800753D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075630: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80075634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80075638: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8007563C: jal         0x80075B34
    // 0x80075640: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075640: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x80075644: beq         $v0, $zero, L_80075664
    if (ctx->r2 == 0) {
        // 0x80075648: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_80075664;
    }
    // 0x80075648: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007564C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075650: jal         0x80075D44
    // 0x80075654: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80075654: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_1:
    // 0x80075658: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8007565C: b           L_80075920
    // 0x80075660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80075920;
    // 0x80075660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80075664:
    // 0x80075664: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075668: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007566C: addiu       $a2, $a2, 0x7D44
    ctx->r6 = ADD32(ctx->r6, 0X7D44);
    // 0x80075670: addiu       $a1, $a1, 0x7D34
    ctx->r5 = ADD32(ctx->r5, 0X7D34);
    // 0x80075674: jal         0x80076740
    // 0x80075678: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x80075678: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x8007567C: bne         $v0, $zero, L_80075904
    if (ctx->r2 != 0) {
        // 0x80075680: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80075904;
    }
    // 0x80075680: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80075684: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075688: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8007568C: jal         0x80076B7C
    // 0x80075690: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    get_file_size(rdram, ctx);
        goto after_3;
    // 0x80075690: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80075694: beq         $v0, $zero, L_800756B4
    if (ctx->r2 == 0) {
        // 0x80075698: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_800756B4;
    }
    // 0x80075698: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8007569C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800756A0: jal         0x80075D44
    // 0x800756A4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_4;
    // 0x800756A4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_4:
    // 0x800756A8: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800756AC: b           L_80075920
    // 0x800756B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80075920;
    // 0x800756B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800756B4:
    // 0x800756B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800756B8: jal         0x80070EDC
    // 0x800756BC: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x800756BC: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_5:
    // 0x800756C0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800756C4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800756C8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800756CC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800756D0: jal         0x80076868
    // 0x800756D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_6;
    // 0x800756D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
    // 0x800756D8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800756DC: jal         0x80075D44
    // 0x800756E0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_7;
    // 0x800756E0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_7:
    // 0x800756E4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800756E8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800756EC: bne         $v1, $zero, L_800758EC
    if (ctx->r3 != 0) {
        // 0x800756F0: lui         $at, 0x4748
        ctx->r1 = S32(0X4748 << 16);
            goto L_800758EC;
    }
    // 0x800756F0: lui         $at, 0x4748
    ctx->r1 = S32(0X4748 << 16);
    // 0x800756F4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800756F8: ori         $at, $at, 0x5353
    ctx->r1 = ctx->r1 | 0X5353;
    // 0x800756FC: bne         $t7, $at, L_800758D8
    if (ctx->r15 != ctx->r1) {
        // 0x80075700: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_800758D8;
    }
    // 0x80075700: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x80075704: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80075708: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8007570C: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80075710: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80075714: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x80075718: lh          $t2, 0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA);
    // 0x8007571C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80075720: subu        $a3, $t9, $t2
    ctx->r7 = SUB32(ctx->r25, ctx->r10);
    // 0x80075724: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80075728: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8007572C: jal         0x80070EDC
    // 0x80075730: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x80075730: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_8:
    // 0x80075734: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80075738: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007573C: addiu       $v1, $a0, 0x4
    ctx->r3 = ADD32(ctx->r4, 0X4);
    // 0x80075740: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80075744: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x80075748: lh          $a2, 0x2($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X2);
    // 0x8007574C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80075750: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80075754: jal         0x800CA300
    // 0x80075758: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bcopy_recomp(rdram, ctx);
        goto after_9;
    // 0x80075758: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x8007575C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80075760: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80075764: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80075768: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007576C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80075770: beq         $t0, $at, L_800757B0
    if (ctx->r8 == ctx->r1) {
        // 0x80075774: slti        $at, $t0, 0x6
        ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
            goto L_800757B0;
    }
    // 0x80075774: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x80075778: lh          $v0, 0x6($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X6);
    // 0x8007577C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80075780: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80075784: lh          $t7, 0x1A($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X1A);
    // 0x80075788: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8007578C: addu        $a1, $t5, $a3
    ctx->r5 = ADD32(ctx->r13, ctx->r7);
    // 0x80075790: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80075794: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x80075798: jal         0x800CA300
    // 0x8007579C: subu        $a2, $t7, $v0
    ctx->r6 = SUB32(ctx->r15, ctx->r2);
    bcopy_recomp(rdram, ctx);
        goto after_10;
    // 0x8007579C: subu        $a2, $t7, $v0
    ctx->r6 = SUB32(ctx->r15, ctx->r2);
    after_10:
    // 0x800757A0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800757A4: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800757A8: nop

    // 0x800757AC: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
L_800757B0:
    // 0x800757B0: beq         $at, $zero, L_80075898
    if (ctx->r1 == 0) {
        // 0x800757B4: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80075898;
    }
    // 0x800757B4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800757B8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800757BC: subu        $a2, $a1, $t0
    ctx->r6 = SUB32(ctx->r5, ctx->r8);
    // 0x800757C0: andi        $t8, $a2, 0x3
    ctx->r24 = ctx->r6 & 0X3;
    // 0x800757C4: beq         $t8, $zero, L_8007580C
    if (ctx->r24 == 0) {
        // 0x800757C8: addu        $a0, $t8, $t0
        ctx->r4 = ADD32(ctx->r24, ctx->r8);
            goto L_8007580C;
    }
    // 0x800757C8: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    // 0x800757CC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800757D0: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x800757D4: addu        $v0, $t1, $t6
    ctx->r2 = ADD32(ctx->r9, ctx->r14);
    // 0x800757D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800757DC:
    // 0x800757DC: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x800757E0: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x800757E4: lbu         $t2, 0x5($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X5);
    // 0x800757E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800757EC: addu        $t4, $t3, $a3
    ctx->r12 = ADD32(ctx->r11, ctx->r7);
    // 0x800757F0: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x800757F4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800757F8: sb          $t9, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r25;
    // 0x800757FC: bne         $a0, $v1, L_800757DC
    if (ctx->r4 != ctx->r3) {
        // 0x80075800: sb          $t2, -0x3($v0)
        MEM_B(-0X3, ctx->r2) = ctx->r10;
            goto L_800757DC;
    }
    // 0x80075800: sb          $t2, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r10;
    // 0x80075804: beq         $v1, $a1, L_8007589C
    if (ctx->r3 == ctx->r5) {
        // 0x80075808: lw          $t1, 0x44($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X44);
            goto L_8007589C;
    }
    // 0x80075808: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_8007580C:
    // 0x8007580C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80075810: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80075814: addu        $v0, $t1, $t5
    ctx->r2 = ADD32(ctx->r9, ctx->r13);
    // 0x80075818: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8007581C:
    // 0x8007581C: lh          $t4, 0xA($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XA);
    // 0x80075820: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x80075824: lbu         $t2, 0x8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X8);
    // 0x80075828: lbu         $t3, 0x9($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X9);
    // 0x8007582C: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x80075830: lbu         $t8, 0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5);
    // 0x80075834: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x80075838: addu        $t9, $t6, $a3
    ctx->r25 = ADD32(ctx->r14, ctx->r7);
    // 0x8007583C: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x80075840: lh          $t4, 0x12($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X12);
    // 0x80075844: sb          $t2, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r10;
    // 0x80075848: sb          $t3, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r11;
    // 0x8007584C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80075850: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x80075854: lbu         $t8, 0xD($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XD);
    // 0x80075858: lbu         $t7, 0xC($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC);
    // 0x8007585C: lbu         $t3, 0x11($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X11);
    // 0x80075860: lbu         $t2, 0x10($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X10);
    // 0x80075864: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // 0x80075868: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x8007586C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80075870: addu        $t9, $t6, $a3
    ctx->r25 = ADD32(ctx->r14, ctx->r7);
    // 0x80075874: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x80075878: sh          $t5, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r13;
    // 0x8007587C: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x80075880: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80075884: sb          $t8, -0x7($v0)
    MEM_B(-0X7, ctx->r2) = ctx->r24;
    // 0x80075888: sb          $t7, -0x8($v0)
    MEM_B(-0X8, ctx->r2) = ctx->r15;
    // 0x8007588C: sb          $t3, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r11;
    // 0x80075890: bne         $v1, $a1, L_8007581C
    if (ctx->r3 != ctx->r5) {
        // 0x80075894: sb          $t2, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = ctx->r10;
            goto L_8007581C;
    }
    // 0x80075894: sb          $t2, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r10;
L_80075898:
    // 0x80075898: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_8007589C:
    // 0x8007589C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800758A0: addiu       $v0, $t1, 0x4
    ctx->r2 = ADD32(ctx->r9, 0X4);
    // 0x800758A4: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x800758A8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800758AC: sh          $t7, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r15;
    // 0x800758B0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800758B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800758B8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800758BC: addiu       $a3, $a3, 0x7D58
    ctx->r7 = ADD32(ctx->r7, 0X7D58);
    // 0x800758C0: addiu       $a2, $a2, 0x7D48
    ctx->r6 = ADD32(ctx->r6, 0X7D48);
    // 0x800758C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800758C8: jal         0x8007692C
    // 0x800758CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    write_controller_pak_file(rdram, ctx);
        goto after_11;
    // 0x800758CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_11:
    // 0x800758D0: b           L_800758D8
    // 0x800758D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800758D8;
    // 0x800758D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800758D8:
    // 0x800758D8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800758DC: jal         0x80071380
    // 0x800758E0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_12;
    // 0x800758E0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_12:
    // 0x800758E4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800758E8: nop

L_800758EC:
    // 0x800758EC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800758F0: jal         0x80071380
    // 0x800758F4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_13;
    // 0x800758F4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_13:
    // 0x800758F8: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800758FC: b           L_8007591C
    // 0x80075900: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8007591C;
    // 0x80075900: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80075904:
    // 0x80075904: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075908: jal         0x80075D44
    // 0x8007590C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_14;
    // 0x8007590C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_14:
    // 0x80075910: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80075914: nop

    // 0x80075918: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8007591C:
    // 0x8007591C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80075920:
    // 0x80075920: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80075924: jr          $ra
    // 0x80075928: nop

    return;
    // 0x80075928: nop

;}
RECOMP_FUNC void func_800756D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007592C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80075930: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80075934: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80075938: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8007593C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80075940: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80075944: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x80075948: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x8007594C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80075950: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80075954: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80075958: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007595C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80075960: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80075964: jal         0x80075B34
    // 0x80075968: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075968: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007596C: beq         $v0, $zero, L_8007598C
    if (ctx->r2 == 0) {
        // 0x80075970: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_8007598C;
    }
    // 0x80075970: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80075974: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80075978: jal         0x80075D44
    // 0x8007597C: nop

    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x8007597C: nop

    after_1:
    // 0x80075980: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80075984: b           L_80075B08
    // 0x80075988: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80075B08;
    // 0x80075988: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8007598C:
    // 0x8007598C: lw          $s5, 0x80($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X80);
    // 0x80075990: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80075994: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80075998: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8007599C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800759A0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800759A4: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
L_800759A8:
    // 0x800759A8: sb          $a3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r7;
    // 0x800759AC: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800759B0: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x800759B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800759B8: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x800759BC: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800759C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800759C4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800759C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800759CC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800759D0: bne         $at, $zero, L_800759A8
    if (ctx->r1 != 0) {
        // 0x800759D4: sb          $v0, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r2;
            goto L_800759A8;
    }
    // 0x800759D4: sb          $v0, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r2;
    // 0x800759D8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800759DC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800759E0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800759E4: addiu       $a2, $a2, 0x7D6C
    ctx->r6 = ADD32(ctx->r6, 0X7D6C);
    // 0x800759E8: addiu       $a1, $a1, 0x7D5C
    ctx->r5 = ADD32(ctx->r5, 0X7D5C);
    // 0x800759EC: jal         0x80076740
    // 0x800759F0: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x800759F0: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_2:
    // 0x800759F4: bne         $v0, $zero, L_80075AF0
    if (ctx->r2 != 0) {
        // 0x800759F8: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_80075AF0;
    }
    // 0x800759F8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800759FC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80075A00: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80075A04: jal         0x80076B7C
    // 0x80075A08: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    get_file_size(rdram, ctx);
        goto after_3;
    // 0x80075A08: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_3:
    // 0x80075A0C: bne         $v0, $zero, L_80075AF0
    if (ctx->r2 != 0) {
        // 0x80075A10: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_80075AF0;
    }
    // 0x80075A10: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80075A14: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80075A18: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80075A1C: jal         0x80070EDC
    // 0x80075A20: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x80075A20: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_4:
    // 0x80075A24: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80075A28: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80075A2C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x80075A30: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80075A34: jal         0x80076868
    // 0x80075A38: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80075A38: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80075A3C: bne         $v0, $zero, L_80075AE8
    if (ctx->r2 != 0) {
        // 0x80075A40: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_80075AE8;
    }
    // 0x80075A40: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80075A44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80075A48: addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // 0x80075A4C: addiu       $s4, $zero, 0x6
    ctx->r20 = ADD32(0, 0X6);
    // 0x80075A50: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
L_80075A54:
    // 0x80075A54: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x80075A58: nop

    // 0x80075A5C: beq         $s3, $t6, L_80075ADC
    if (ctx->r19 == ctx->r14) {
        // 0x80075A60: nop
    
            goto L_80075ADC;
    }
    // 0x80075A60: nop

    // 0x80075A64: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80075A68: jal         0x80074CA4
    // 0x80075A6C: addu        $a0, $t7, $s2
    ctx->r4 = ADD32(ctx->r15, ctx->r18);
    calculate_ghost_header_checksum(rdram, ctx);
        goto after_6;
    // 0x80075A6C: addu        $a0, $t7, $s2
    ctx->r4 = ADD32(ctx->r15, ctx->r18);
    after_6:
    // 0x80075A70: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x80075A74: nop

    // 0x80075A78: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x80075A7C: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80075A80: nop

    // 0x80075A84: beq         $v0, $t0, L_80075A94
    if (ctx->r2 == ctx->r8) {
        // 0x80075A88: addiu       $t1, $zero, 0x9
        ctx->r9 = ADD32(0, 0X9);
            goto L_80075A94;
    }
    // 0x80075A88: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80075A8C: b           L_80075AE8
    // 0x80075A90: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
        goto L_80075AE8;
    // 0x80075A90: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
L_80075A94:
    // 0x80075A94: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x80075A98: addu        $t3, $s6, $s0
    ctx->r11 = ADD32(ctx->r22, ctx->r16);
    // 0x80075A9C: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x80075AA0: lbu         $t4, 0x1($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X1);
    // 0x80075AA4: addu        $t5, $fp, $s0
    ctx->r13 = ADD32(ctx->r30, ctx->r16);
    // 0x80075AA8: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x80075AAC: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x80075AB0: addu        $t9, $s7, $s0
    ctx->r25 = ADD32(ctx->r23, ctx->r16);
    // 0x80075AB4: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x80075AB8: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x80075ABC: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x80075AC0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x80075AC4: lh          $t0, 0x2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2);
    // 0x80075AC8: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x80075ACC: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x80075AD0: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80075AD4: nop

    // 0x80075AD8: sh          $t2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r10;
L_80075ADC:
    // 0x80075ADC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80075AE0: bne         $s0, $s4, L_80075A54
    if (ctx->r16 != ctx->r20) {
        // 0x80075AE4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80075A54;
    }
    // 0x80075AE4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80075AE8:
    // 0x80075AE8: jal         0x80071380
    // 0x80075AEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80075AEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
L_80075AF0:
    // 0x80075AF0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80075AF4: jal         0x80075D44
    // 0x80075AF8: nop

    start_reading_controller_data(rdram, ctx);
        goto after_8;
    // 0x80075AF8: nop

    after_8:
    // 0x80075AFC: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80075B00: nop

    // 0x80075B04: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80075B08:
    // 0x80075B08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80075B0C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80075B10: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80075B14: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80075B18: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80075B1C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80075B20: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80075B24: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80075B28: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80075B2C: jr          $ra
    // 0x80075B30: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80075B30: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void get_si_device_status(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075B34: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80075B38: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80075B3C: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80075B40: addiu       $s4, $s4, 0x4590
    ctx->r20 = ADD32(ctx->r20, 0X4590);
    // 0x80075B44: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80075B48: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80075B4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80075B50: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80075B54: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80075B58: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80075B5C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80075B60: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80075B64: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80075B68: bne         $t6, $zero, L_80075BA8
    if (ctx->r14 != 0) {
        // 0x80075B6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80075BA8;
    }
    // 0x80075B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80075B70: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x80075B74: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x80075B78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80075B7C: addu        $t7, $t7, $s5
    ctx->r15 = ADD32(ctx->r15, ctx->r21);
    // 0x80075B80: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80075B84: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x80075B88: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80075B8C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80075B90: jal         0x8007231C
    // 0x80075B94: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_0;
    // 0x80075B94: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
    // 0x80075B98: bne         $v0, $zero, L_80075BAC
    if (ctx->r2 != 0) {
        // 0x80075B9C: sll         $t9, $s5, 2
        ctx->r25 = S32(ctx->r21 << 2);
            goto L_80075BAC;
    }
    // 0x80075B9C: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x80075BA0: b           L_80075D20
    // 0x80075BA4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80075D20;
    // 0x80075BA4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80075BA8:
    // 0x80075BA8: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
L_80075BAC:
    // 0x80075BAC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80075BB0: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x80075BB4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80075BB8: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x80075BBC: addu        $t9, $t9, $s5
    ctx->r25 = ADD32(ctx->r25, ctx->r21);
    // 0x80075BC0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80075BC4: addiu       $t0, $t0, 0x4598
    ctx->r8 = ADD32(ctx->r8, 0X4598);
    // 0x80075BC8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80075BCC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80075BD0: beq         $t1, $zero, L_80075C0C
    if (ctx->r9 == 0) {
        // 0x80075BD4: addu        $s3, $t9, $t0
        ctx->r19 = ADD32(ctx->r25, ctx->r8);
            goto L_80075C0C;
    }
    // 0x80075BD4: addu        $s3, $t9, $t0
    ctx->r19 = ADD32(ctx->r25, ctx->r8);
    // 0x80075BD8: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80075BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80075BE0:
    // 0x80075BE0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80075BE4: jal         0x800C9110
    // 0x80075BE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80075BE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80075BEC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80075BF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80075BF4: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80075BF8: nop

    // 0x80075BFC: beq         $t2, $zero, L_80075C0C
    if (ctx->r10 == 0) {
        // 0x80075C00: nop
    
            goto L_80075C0C;
    }
    // 0x80075C00: nop

    // 0x80075C04: bne         $s1, $s2, L_80075BE0
    if (ctx->r17 != ctx->r18) {
        // 0x80075C08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80075BE0;
    }
    // 0x80075C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80075C0C:
    // 0x80075C0C: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80075C10: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80075C14: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80075C18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80075C1C:
    // 0x80075C1C: jal         0x800CF940
    // 0x80075C20: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_2;
    // 0x80075C20: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x80075C24: bne         $v0, $s0, L_80075C40
    if (ctx->r2 != ctx->r16) {
        // 0x80075C28: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80075C40;
    }
    // 0x80075C28: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80075C2C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075C30: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80075C34: jal         0x800CF280
    // 0x80075C38: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80075C38: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x80075C3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80075C40:
    // 0x80075C40: bne         $v0, $s2, L_80075C6C
    if (ctx->r2 != ctx->r18) {
        // 0x80075C44: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80075C6C;
    }
    // 0x80075C44: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80075C48: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075C4C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80075C50: jal         0x8007231C
    // 0x80075C54: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    osMotorInit_recomp(rdram, ctx);
        goto after_4;
    // 0x80075C54: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_4:
    // 0x80075C58: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80075C5C: bne         $v0, $zero, L_80075C70
    if (ctx->r2 != 0) {
        // 0x80075C60: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80075C70;
    }
    // 0x80075C60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075C64: b           L_80075D20
    // 0x80075C68: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80075D20;
    // 0x80075C68: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80075C6C:
    // 0x80075C6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80075C70:
    // 0x80075C70: bne         $v1, $at, L_80075CB8
    if (ctx->r3 != ctx->r1) {
        // 0x80075C74: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80075CB8;
    }
    // 0x80075C74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80075C78: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075C7C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80075C80: jal         0x800CF280
    // 0x80075C84: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_5;
    // 0x80075C84: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_5:
    // 0x80075C88: bne         $v0, $s2, L_80075CAC
    if (ctx->r2 != ctx->r18) {
        // 0x80075C8C: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80075CAC;
    }
    // 0x80075C8C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80075C90: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075C94: jal         0x8007231C
    // 0x80075C98: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_6;
    // 0x80075C98: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_6:
    // 0x80075C9C: bne         $v0, $zero, L_80075CAC
    if (ctx->r2 != 0) {
        // 0x80075CA0: nop
    
            goto L_80075CAC;
    }
    // 0x80075CA0: nop

    // 0x80075CA4: b           L_80075D20
    // 0x80075CA8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80075D20;
    // 0x80075CA8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80075CAC:
    // 0x80075CAC: b           L_80075D20
    // 0x80075CB0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80075D20;
    // 0x80075CB0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80075CB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80075CB8:
    // 0x80075CB8: beq         $v1, $at, L_80075CC8
    if (ctx->r3 == ctx->r1) {
        // 0x80075CBC: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80075CC8;
    }
    // 0x80075CBC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80075CC0: bne         $v1, $at, L_80075CD0
    if (ctx->r3 != ctx->r1) {
        // 0x80075CC4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80075CD0;
    }
    // 0x80075CC4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80075CC8:
    // 0x80075CC8: b           L_80075D20
    // 0x80075CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80075D20;
    // 0x80075CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80075CD0:
    // 0x80075CD0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80075CD4: bne         $v1, $at, L_80075CE4
    if (ctx->r3 != ctx->r1) {
        // 0x80075CD8: nop
    
            goto L_80075CE4;
    }
    // 0x80075CD8: nop

    // 0x80075CDC: b           L_80075D20
    // 0x80075CE0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_80075D20;
    // 0x80075CE0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80075CE4:
    // 0x80075CE4: bne         $v1, $s2, L_80075CF4
    if (ctx->r3 != ctx->r18) {
        // 0x80075CE8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80075CF4;
    }
    // 0x80075CE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80075CEC: b           L_80075D20
    // 0x80075CF0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80075D20;
    // 0x80075CF0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80075CF4:
    // 0x80075CF4: bne         $v1, $at, L_80075D04
    if (ctx->r3 != ctx->r1) {
        // 0x80075CF8: nop
    
            goto L_80075D04;
    }
    // 0x80075CF8: nop

    // 0x80075CFC: b           L_80075D20
    // 0x80075D00: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80075D20;
    // 0x80075D00: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80075D04:
    // 0x80075D04: bne         $v1, $zero, L_80075D14
    if (ctx->r3 != 0) {
        // 0x80075D08: nop
    
            goto L_80075D14;
    }
    // 0x80075D08: nop

    // 0x80075D0C: b           L_80075D20
    // 0x80075D10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80075D20;
    // 0x80075D10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80075D14:
    // 0x80075D14: bne         $s1, $s0, L_80075C1C
    if (ctx->r17 != ctx->r16) {
        // 0x80075D18: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80075C1C;
    }
    // 0x80075D18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80075D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80075D20:
    // 0x80075D20: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80075D24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80075D28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80075D2C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80075D30: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80075D34: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80075D38: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80075D3C: jr          $ra
    // 0x80075D40: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80075D40: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void start_reading_controller_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075D44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075D48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80075D4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80075D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075D54: lw          $a0, 0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4590);
    // 0x80075D58: jal         0x800CD540
    // 0x80075D5C: nop

    osContStartReadData_recomp(rdram, ctx);
        goto after_0;
    // 0x80075D5C: nop

    after_0:
    // 0x80075D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075D68: jr          $ra
    // 0x80075D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80075D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void init_controller_paks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075D70: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80075D74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80075D78: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80075D7C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80075D80: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80075D84: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80075D88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80075D8C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80075D90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80075D94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80075D98: jal         0x8006A340
    // 0x80075D9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80075D9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80075DA0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80075DA4: addiu       $s4, $s4, 0x4590
    ctx->r20 = ADD32(ctx->r20, 0X4590);
    // 0x80075DA8: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80075DAC: jal         0x8001E2D0
    // 0x80075DB0: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80075DB0: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_1:
    // 0x80075DB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80075DB8: sw          $v0, 0x4760($at)
    MEM_W(0X4760, ctx->r1) = ctx->r2;
    // 0x80075DBC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80075DC0: addiu       $v1, $v1, 0x4767
    ctx->r3 = ADD32(ctx->r3, 0X4767);
    // 0x80075DC4: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80075DC8: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80075DCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80075DD0: sb          $t7, 0x4766($at)
    MEM_B(0X4766, ctx->r1) = ctx->r15;
    // 0x80075DD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80075DD8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80075DDC: sb          $t8, 0x4764($at)
    MEM_B(0X4764, ctx->r1) = ctx->r24;
    // 0x80075DE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80075DE4: sw          $zero, 0x4768($at)
    MEM_W(0X4768, ctx->r1) = 0;
    // 0x80075DE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80075DEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80075DF0: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80075DF4: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x80075DF8: sw          $t9, -0x1604($at)
    MEM_W(-0X1604, ctx->r1) = ctx->r25;
    // 0x80075DFC: addiu       $s6, $s6, -0x1608
    ctx->r22 = ADD32(ctx->r22, -0X1608);
    // 0x80075E00: addiu       $s5, $s5, 0x4765
    ctx->r21 = ADD32(ctx->r21, 0X4765);
    // 0x80075E04: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075E08: sb          $zero, 0x0($s5)
    MEM_B(0X0, ctx->r21) = 0;
    // 0x80075E0C: sb          $zero, 0x0($s6)
    MEM_B(0X0, ctx->r22) = 0;
    // 0x80075E10: jal         0x800CD7F0
    // 0x80075E14: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_2;
    // 0x80075E14: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    after_2:
    // 0x80075E18: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80075E1C: addiu       $s1, $s1, 0x4738
    ctx->r17 = ADD32(ctx->r17, 0X4738);
    // 0x80075E20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80075E24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80075E28: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x80075E2C: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
L_80075E30:
    // 0x80075E30: lbu         $t2, 0x4E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4E);
    // 0x80075E34: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x80075E38: lh          $t1, 0x2($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X2);
    // 0x80075E3C: and         $t3, $t2, $v1
    ctx->r11 = ctx->r10 & ctx->r3;
    // 0x80075E40: sh          $s7, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r23;
    // 0x80075E44: sh          $s7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r23;
    // 0x80075E48: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x80075E4C: beq         $t3, $zero, L_80075EE4
    if (ctx->r11 == 0) {
        // 0x80075E50: sh          $t1, 0x6($s1)
        MEM_H(0X6, ctx->r17) = ctx->r9;
            goto L_80075EE4;
    }
    // 0x80075E50: sh          $t1, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r9;
    // 0x80075E54: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80075E58: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x80075E5C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80075E60: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x80075E64: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80075E68: addiu       $t5, $t5, 0x4598
    ctx->r13 = ADD32(ctx->r13, 0X4598);
    // 0x80075E6C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80075E70: addu        $s2, $t4, $t5
    ctx->r18 = ADD32(ctx->r12, ctx->r13);
    // 0x80075E74: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075E78: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80075E7C: jal         0x800CF280
    // 0x80075E80: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80075E80: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80075E84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075E88: bne         $v0, $at, L_80075E9C
    if (ctx->r2 != ctx->r1) {
        // 0x80075E8C: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80075E9C;
    }
    // 0x80075E8C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80075E90: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075E94: jal         0x800CF280
    // 0x80075E98: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_4;
    // 0x80075E98: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
L_80075E9C:
    // 0x80075E9C: bne         $v0, $zero, L_80075EB8
    if (ctx->r2 != 0) {
        // 0x80075EA0: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80075EB8;
    }
    // 0x80075EA0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80075EA4: lbu         $t6, 0x0($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X0);
    // 0x80075EA8: nop

    // 0x80075EAC: or          $t7, $t6, $s3
    ctx->r15 = ctx->r14 | ctx->r19;
    // 0x80075EB0: b           L_80075EE4
    // 0x80075EB4: sb          $t7, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r15;
        goto L_80075EE4;
    // 0x80075EB4: sb          $t7, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r15;
L_80075EB8:
    // 0x80075EB8: bne         $v0, $at, L_80075EE4
    if (ctx->r2 != ctx->r1) {
        // 0x80075EBC: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80075EE4;
    }
    // 0x80075EBC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80075EC0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075EC4: jal         0x8007231C
    // 0x80075EC8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_5;
    // 0x80075EC8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80075ECC: bne         $v0, $zero, L_80075EE8
    if (ctx->r2 != 0) {
        // 0x80075ED0: sll         $v1, $s3, 1
        ctx->r3 = S32(ctx->r19 << 1);
            goto L_80075EE8;
    }
    // 0x80075ED0: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
    // 0x80075ED4: lbu         $t8, 0x0($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X0);
    // 0x80075ED8: nop

    // 0x80075EDC: or          $t9, $t8, $s3
    ctx->r25 = ctx->r24 | ctx->r19;
    // 0x80075EE0: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
L_80075EE4:
    // 0x80075EE4: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
L_80075EE8:
    // 0x80075EE8: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
    // 0x80075EEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80075EF0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80075EF4: bne         $s0, $fp, L_80075E30
    if (ctx->r16 != ctx->r30) {
        // 0x80075EF8: addiu       $s1, $s1, 0xA
        ctx->r17 = ADD32(ctx->r17, 0XA);
            goto L_80075E30;
    }
    // 0x80075EF8: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80075EFC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075F00: jal         0x800CD540
    // 0x80075F04: nop

    osContStartReadData_recomp(rdram, ctx);
        goto after_6;
    // 0x80075F04: nop

    after_6:
    // 0x80075F08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80075F0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80075F10: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80075F14: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80075F18: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80075F1C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80075F20: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80075F24: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80075F28: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80075F2C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80075F30: jr          $ra
    // 0x80075F34: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80075F34: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void check_for_rumble_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075F38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80075F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075F40: jal         0x80075B34
    // 0x80075F44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075F44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80075F48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80075F4C: jal         0x80075D44
    // 0x80075F50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80075F50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80075F54: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80075F58: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80075F5C: bne         $v1, $at, L_80075F80
    if (ctx->r3 != ctx->r1) {
        // 0x80075F60: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80075F80;
    }
    // 0x80075F60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80075F64: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80075F68: addiu       $v0, $v0, 0x4765
    ctx->r2 = ADD32(ctx->r2, 0X4765);
    // 0x80075F6C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80075F70: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80075F74: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x80075F78: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x80075F7C: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_80075F80:
    // 0x80075F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075F84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80075F88: jr          $ra
    // 0x80075F8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80075F8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void repair_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075F90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80075F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075F98: jal         0x80075B34
    // 0x80075F9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075F9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80075FA0: beq         $v0, $zero, L_80075FB0
    if (ctx->r2 == 0) {
        // 0x80075FA4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80075FB0;
    }
    // 0x80075FA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075FA8: bne         $v0, $at, L_80076000
    if (ctx->r2 != ctx->r1) {
        // 0x80075FAC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80076000;
    }
    // 0x80075FAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80075FB0:
    // 0x80075FB0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80075FB4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80075FB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80075FBC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80075FC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80075FC4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80075FC8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80075FCC: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x80075FD0: jal         0x800CFA90
    // 0x80075FD4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    osPfsChecker_recomp(rdram, ctx);
        goto after_1;
    // 0x80075FD4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x80075FD8: bne         $v0, $zero, L_80075FE8
    if (ctx->r2 != 0) {
        // 0x80075FDC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80075FE8;
    }
    // 0x80075FDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075FE0: b           L_80076000
    // 0x80075FE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80076000;
    // 0x80075FE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80075FE8:
    // 0x80075FE8: bne         $v0, $at, L_80075FF8
    if (ctx->r2 != ctx->r1) {
        // 0x80075FEC: nop
    
            goto L_80075FF8;
    }
    // 0x80075FEC: nop

    // 0x80075FF0: b           L_80076000
    // 0x80075FF4: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_80076000;
    // 0x80075FF4: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80075FF8:
    // 0x80075FF8: b           L_80076000
    // 0x80075FFC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80076000;
    // 0x80075FFC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80076000:
    // 0x80076000: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80076004: jal         0x80075D44
    // 0x80076008: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_2;
    // 0x80076008: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8007600C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076010: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80076014: jr          $ra
    // 0x80076018: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80076018: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void reformat_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007601C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80076020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076024: jal         0x80075B34
    // 0x80076028: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80076028: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007602C: beq         $v0, $zero, L_80076044
    if (ctx->r2 == 0) {
        // 0x80076030: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80076044;
    }
    // 0x80076030: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80076034: beq         $v0, $at, L_80076044
    if (ctx->r2 == ctx->r1) {
        // 0x80076038: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80076044;
    }
    // 0x80076038: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007603C: bne         $v0, $at, L_8007609C
    if (ctx->r2 != ctx->r1) {
        // 0x80076040: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007609C;
    }
    // 0x80076040: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80076044:
    // 0x80076044: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80076048: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007604C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80076050: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80076054: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80076058: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007605C: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80076060: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80076064: lw          $a1, 0x4590($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4590);
    // 0x80076068: addiu       $t7, $t7, 0x4598
    ctx->r15 = ADD32(ctx->r15, 0X4598);
    // 0x8007606C: jal         0x800D04F0
    // 0x80076070: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    osPfsReFormat(rdram, ctx);
        goto after_1;
    // 0x80076070: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80076074: bne         $v0, $zero, L_80076084
    if (ctx->r2 != 0) {
        // 0x80076078: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80076084;
    }
    // 0x80076078: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007607C: b           L_8007609C
    // 0x80076080: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8007609C;
    // 0x80076080: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80076084:
    // 0x80076084: bne         $v0, $at, L_80076094
    if (ctx->r2 != ctx->r1) {
        // 0x80076088: nop
    
            goto L_80076094;
    }
    // 0x80076088: nop

    // 0x8007608C: b           L_8007609C
    // 0x80076090: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_8007609C;
    // 0x80076090: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80076094:
    // 0x80076094: b           L_8007609C
    // 0x80076098: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8007609C;
    // 0x80076098: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8007609C:
    // 0x8007609C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800760A0: jal         0x80075D44
    // 0x800760A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_2;
    // 0x800760A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800760A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800760AC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800760B0: jr          $ra
    // 0x800760B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800760B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void get_controller_pak_file_list(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800760B8: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800760BC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800760C0: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800760C4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800760C8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800760CC: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800760D0: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800760D4: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800760D8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800760DC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800760E0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800760E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800760E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800760EC: jal         0x80075B34
    // 0x800760F0: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x800760F0: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800760F4: beq         $v0, $zero, L_80076110
    if (ctx->r2 == 0) {
        // 0x800760F8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80076110;
    }
    // 0x800760F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800760FC: jal         0x80075D44
    // 0x80076100: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80076100: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x80076104: sll         $t6, $s7, 30
    ctx->r14 = S32(ctx->r23 << 30);
    // 0x80076108: b           L_80076390
    // 0x8007610C: or          $v0, $t6, $s0
    ctx->r2 = ctx->r14 | ctx->r16;
        goto L_80076390;
    // 0x8007610C: or          $v0, $t6, $s0
    ctx->r2 = ctx->r14 | ctx->r16;
L_80076110:
    // 0x80076110: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x80076114: subu        $t7, $t7, $s7
    ctx->r15 = SUB32(ctx->r15, ctx->r23);
    // 0x80076118: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007611C: addu        $t7, $t7, $s7
    ctx->r15 = ADD32(ctx->r15, ctx->r23);
    // 0x80076120: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80076124: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x80076128: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007612C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80076130: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // 0x80076134: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80076138: jal         0x800D08F0
    // 0x8007613C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_2;
    // 0x8007613C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_2:
    // 0x80076140: beq         $v0, $zero, L_80076160
    if (ctx->r2 == 0) {
        // 0x80076144: nop
    
            goto L_80076160;
    }
    // 0x80076144: nop

    // 0x80076148: jal         0x80075D44
    // 0x8007614C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_3;
    // 0x8007614C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_3:
    // 0x80076150: sll         $v0, $s7, 30
    ctx->r2 = S32(ctx->r23 << 30);
    // 0x80076154: ori         $t9, $v0, 0x9
    ctx->r25 = ctx->r2 | 0X9;
    // 0x80076158: b           L_80076390
    // 0x8007615C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80076390;
    // 0x8007615C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80076160:
    // 0x80076160: jal         0x8009F064
    // 0x80076164: nop

    get_language(rdram, ctx);
        goto after_4;
    // 0x80076164: nop

    after_4:
    // 0x80076168: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007616C: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x80076170: bne         $v0, $at, L_80076184
    if (ctx->r2 != ctx->r1) {
        // 0x80076174: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_80076184;
    }
    // 0x80076174: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80076178: lui         $s6, 0x4E44
    ctx->r22 = S32(0X4E44 << 16);
    // 0x8007617C: b           L_800761A4
    // 0x80076180: ori         $s6, $s6, 0x594A
    ctx->r22 = ctx->r22 | 0X594A;
        goto L_800761A4;
    // 0x80076180: ori         $s6, $s6, 0x594A
    ctx->r22 = ctx->r22 | 0X594A;
L_80076184:
    // 0x80076184: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80076188: lw          $t0, 0x300($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X300);
    // 0x8007618C: lui         $s6, 0x4E44
    ctx->r22 = S32(0X4E44 << 16);
    // 0x80076190: bne         $t0, $zero, L_800761A4
    if (ctx->r8 != 0) {
        // 0x80076194: ori         $s6, $s6, 0x5945
        ctx->r22 = ctx->r22 | 0X5945;
            goto L_800761A4;
    }
    // 0x80076194: ori         $s6, $s6, 0x5945
    ctx->r22 = ctx->r22 | 0X5945;
    // 0x80076198: lui         $s6, 0x4E44
    ctx->r22 = S32(0X4E44 << 16);
    // 0x8007619C: b           L_800761A4
    // 0x800761A0: ori         $s6, $s6, 0x5950
    ctx->r22 = ctx->r22 | 0X5950;
        goto L_800761A4;
    // 0x800761A0: ori         $s6, $s6, 0x5950
    ctx->r22 = ctx->r22 | 0X5950;
L_800761A4:
    // 0x800761A4: slt         $at, $s4, $t1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800761A8: beq         $at, $zero, L_800761B4
    if (ctx->r1 == 0) {
        // 0x800761AC: addiu       $s0, $s0, -0x1650
        ctx->r16 = ADD32(ctx->r16, -0X1650);
            goto L_800761B4;
    }
    // 0x800761AC: addiu       $s0, $s0, -0x1650
    ctx->r16 = ADD32(ctx->r16, -0X1650);
    // 0x800761B0: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
L_800761B4:
    // 0x800761B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800761B8: nop

    // 0x800761BC: beq         $a0, $zero, L_800761D0
    if (ctx->r4 == 0) {
        // 0x800761C0: lw          $a2, 0x68($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X68);
            goto L_800761D0;
    }
    // 0x800761C0: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800761C4: jal         0x80071380
    // 0x800761C8: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800761C8: nop

    after_5:
    // 0x800761CC: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
L_800761D0:
    // 0x800761D0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800761D4: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x800761D8: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x800761DC: sll         $a0, $t2, 3
    ctx->r4 = S32(ctx->r10 << 3);
    // 0x800761E0: jal         0x80070EDC
    // 0x800761E4: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x800761E4: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    after_6:
    // 0x800761E8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800761EC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800761F0: jal         0x800D0A40
    // 0x800761F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    bzero_recomp(rdram, ctx);
        goto after_7;
    // 0x800761F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x800761F8: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800761FC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80076200: blez        $t3, L_80076254
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80076204: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80076254;
    }
    // 0x80076204: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80076208: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x8007620C: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x80076210: lw          $s2, 0xA4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA4);
    // 0x80076214: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80076218: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8007621C:
    // 0x8007621C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80076220: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80076224: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x80076228: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8007622C: sb          $a0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r4;
    // 0x80076230: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80076234: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80076238: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8007623C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80076240: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80076244: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80076248: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007624C: bne         $at, $zero, L_8007621C
    if (ctx->r1 != 0) {
        // 0x80076250: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8007621C;
    }
    // 0x80076250: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
L_80076254:
    // 0x80076254: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x80076258: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8007625C: beq         $at, $zero, L_800762B0
    if (ctx->r1 == 0) {
        // 0x80076260: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800762B0;
    }
    // 0x80076260: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80076264: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x80076268: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x8007626C: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x80076270: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80076274: addu        $a1, $t7, $a3
    ctx->r5 = ADD32(ctx->r15, ctx->r7);
    // 0x80076278: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x8007627C: addu        $s0, $a3, $v1
    ctx->r16 = ADD32(ctx->r7, ctx->r3);
    // 0x80076280: addu        $s1, $t5, $v1
    ctx->r17 = ADD32(ctx->r13, ctx->r3);
    // 0x80076284: addu        $s2, $t6, $s3
    ctx->r18 = ADD32(ctx->r14, ctx->r19);
L_80076288:
    // 0x80076288: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8007628C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80076290: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80076294: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x80076298: sltu        $at, $s0, $a1
    ctx->r1 = ctx->r16 < ctx->r5 ? 1 : 0;
    // 0x8007629C: sb          $a0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r4;
    // 0x800762A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800762A4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800762A8: bne         $at, $zero, L_80076288
    if (ctx->r1 != 0) {
        // 0x800762AC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80076288;
    }
    // 0x800762AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800762B0:
    // 0x800762B0: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800762B4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800762B8: blez        $t8, L_80076384
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800762BC: nop
    
            goto L_80076384;
    }
    // 0x800762BC: nop

    // 0x800762C0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_800762C4:
    // 0x800762C4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800762C8: jal         0x800D0AE0
    // 0x800762CC: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    osPfsFileState_recomp(rdram, ctx);
        goto after_8;
    // 0x800762CC: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_8:
    // 0x800762D0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800762D4: bne         $v0, $at, L_800762E8
    if (ctx->r2 != ctx->r1) {
        // 0x800762D8: sll         $t9, $s3, 2
        ctx->r25 = S32(ctx->r19 << 2);
            goto L_800762E8;
    }
    // 0x800762D8: sll         $t9, $s3, 2
    ctx->r25 = S32(ctx->r19 << 2);
    // 0x800762DC: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x800762E0: b           L_80076370
    // 0x800762E4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_80076370;
    // 0x800762E4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_800762E8:
    // 0x800762E8: beq         $v0, $zero, L_80076300
    if (ctx->r2 == 0) {
        // 0x800762EC: addiu       $a0, $sp, 0x7E
        ctx->r4 = ADD32(ctx->r29, 0X7E);
            goto L_80076300;
    }
    // 0x800762EC: addiu       $a0, $sp, 0x7E
    ctx->r4 = ADD32(ctx->r29, 0X7E);
    // 0x800762F0: jal         0x80075D44
    // 0x800762F4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_9;
    // 0x800762F4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_9:
    // 0x800762F8: b           L_80076390
    // 0x800762FC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_80076390;
    // 0x800762FC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80076300:
    // 0x80076300: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x80076304: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x80076308: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x8007630C: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x80076310: addu        $t1, $s5, $v1
    ctx->r9 = ADD32(ctx->r21, ctx->r3);
    // 0x80076314: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80076318: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8007631C: addu        $s1, $t2, $v1
    ctx->r17 = ADD32(ctx->r10, ctx->r3);
    // 0x80076320: addu        $s0, $t3, $v1
    ctx->r16 = ADD32(ctx->r11, ctx->r3);
    // 0x80076324: jal         0x80076BE4
    // 0x80076328: addu        $s2, $t4, $s3
    ctx->r18 = ADD32(ctx->r12, ctx->r19);
    font_codes_to_string(rdram, ctx);
        goto after_10;
    // 0x80076328: addu        $s2, $t4, $s3
    ctx->r18 = ADD32(ctx->r12, ctx->r19);
    after_10:
    // 0x8007632C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80076330: addiu       $a0, $sp, 0x7A
    ctx->r4 = ADD32(ctx->r29, 0X7A);
    // 0x80076334: jal         0x80076BE4
    // 0x80076338: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    font_codes_to_string(rdram, ctx);
        goto after_11;
    // 0x80076338: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_11:
    // 0x8007633C: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80076340: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80076344: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80076348: sb          $t6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r14;
    // 0x8007634C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80076350: lhu         $t8, 0x78($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X78);
    // 0x80076354: bne         $t7, $s6, L_80076370
    if (ctx->r15 != ctx->r22) {
        // 0x80076358: addiu       $at, $zero, 0x3459
        ctx->r1 = ADD32(0, 0X3459);
            goto L_80076370;
    }
    // 0x80076358: addiu       $at, $zero, 0x3459
    ctx->r1 = ADD32(0, 0X3459);
    // 0x8007635C: bne         $t8, $at, L_80076370
    if (ctx->r24 != ctx->r1) {
        // 0x80076360: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80076370;
    }
    // 0x80076360: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80076364: jal         0x80076D4C
    // 0x80076368: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    get_file_type(rdram, ctx);
        goto after_12;
    // 0x80076368: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_12:
    // 0x8007636C: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_80076370:
    // 0x80076370: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80076374: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80076378: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8007637C: bne         $at, $zero, L_800762C4
    if (ctx->r1 != 0) {
        // 0x80076380: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_800762C4;
    }
    // 0x80076380: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_80076384:
    // 0x80076384: jal         0x80075D44
    // 0x80076388: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_13;
    // 0x80076388: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_13:
    // 0x8007638C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076390:
    // 0x80076390: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80076394: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80076398: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007639C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800763A0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800763A4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800763A8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800763AC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800763B0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800763B4: jr          $ra
    // 0x800763B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800763B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void cpak_free_files(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800763BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800763C0: lw          $a0, -0x1650($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1650);
    // 0x800763C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800763C8: beq         $a0, $zero, L_800763D8
    if (ctx->r4 == 0) {
        // 0x800763CC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800763D8;
    }
    // 0x800763CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800763D0: jal         0x80071380
    // 0x800763D4: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800763D4: nop

    after_0:
L_800763D8:
    // 0x800763D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800763DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800763E0: sw          $zero, -0x1650($at)
    MEM_W(-0X1650, ctx->r1) = 0;
    // 0x800763E4: jr          $ra
    // 0x800763E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800763E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void get_free_space(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800763EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800763F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800763F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800763F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800763FC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80076400: jal         0x80075B34
    // 0x80076404: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80076404: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80076408: bne         $v0, $zero, L_800764F4
    if (ctx->r2 != 0) {
        // 0x8007640C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800764F4;
    }
    // 0x8007640C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076410: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80076414: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80076418: beq         $t6, $zero, L_80076470
    if (ctx->r14 == 0) {
        // 0x8007641C: subu        $t7, $t7, $s0
        ctx->r15 = SUB32(ctx->r15, ctx->r16);
            goto L_80076470;
    }
    // 0x8007641C: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80076420: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80076424: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x80076428: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007642C: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x80076430: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80076434: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80076438: jal         0x800CF940
    // 0x8007643C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_1;
    // 0x8007643C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80076440: beq         $v0, $zero, L_80076460
    if (ctx->r2 == 0) {
        // 0x80076444: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80076460;
    }
    // 0x80076444: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076448: jal         0x80075D44
    // 0x8007644C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_2;
    // 0x8007644C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80076450: sll         $v0, $s0, 30
    ctx->r2 = S32(ctx->r16 << 30);
    // 0x80076454: ori         $t9, $v0, 0x9
    ctx->r25 = ctx->r2 | 0X9;
    // 0x80076458: b           L_80076510
    // 0x8007645C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80076510;
    // 0x8007645C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80076460:
    // 0x80076460: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80076464: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80076468: nop

    // 0x8007646C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_80076470:
    // 0x80076470: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80076474: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80076478: beq         $t2, $zero, L_800764FC
    if (ctx->r10 == 0) {
        // 0x8007647C: subu        $t3, $t3, $s0
        ctx->r11 = SUB32(ctx->r11, ctx->r16);
            goto L_800764FC;
    }
    // 0x8007647C: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x80076480: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80076484: addu        $t3, $t3, $s0
    ctx->r11 = ADD32(ctx->r11, ctx->r16);
    // 0x80076488: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007648C: addiu       $t4, $t4, 0x4598
    ctx->r12 = ADD32(ctx->r12, 0X4598);
    // 0x80076490: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80076494: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80076498: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8007649C: jal         0x800D08F0
    // 0x800764A0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_3;
    // 0x800764A0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x800764A4: beq         $v0, $zero, L_800764C4
    if (ctx->r2 == 0) {
        // 0x800764A8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800764C4;
    }
    // 0x800764A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800764AC: jal         0x80075D44
    // 0x800764B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_4;
    // 0x800764B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800764B4: sll         $v0, $s0, 30
    ctx->r2 = S32(ctx->r16 << 30);
    // 0x800764B8: ori         $t5, $v0, 0x9
    ctx->r13 = ctx->r2 | 0X9;
    // 0x800764BC: b           L_80076510
    // 0x800764C0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80076510;
    // 0x800764C0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800764C4:
    // 0x800764C4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800764C8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800764CC: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x800764D0: bne         $at, $zero, L_800764E4
    if (ctx->r1 != 0) {
        // 0x800764D4: addiu       $t9, $zero, 0x10
        ctx->r25 = ADD32(0, 0X10);
            goto L_800764E4;
    }
    // 0x800764D4: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800764D8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800764DC: b           L_800764FC
    // 0x800764E0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
        goto L_800764FC;
    // 0x800764E0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_800764E4:
    // 0x800764E4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800764E8: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x800764EC: b           L_800764FC
    // 0x800764F0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
        goto L_800764FC;
    // 0x800764F0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_800764F4:
    // 0x800764F4: sll         $t2, $s0, 30
    ctx->r10 = S32(ctx->r16 << 30);
    // 0x800764F8: or          $v1, $v0, $t2
    ctx->r3 = ctx->r2 | ctx->r10;
L_800764FC:
    // 0x800764FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076500: jal         0x80075D44
    // 0x80076504: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_5;
    // 0x80076504: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x80076508: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8007650C: nop

L_80076510:
    // 0x80076510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80076514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80076518: jr          $ra
    // 0x8007651C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007651C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void delete_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076520: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80076524: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80076528: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8007652C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80076530: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80076534: jal         0x80075B34
    // 0x80076538: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80076538: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007653C: beq         $v0, $zero, L_80076558
    if (ctx->r2 == 0) {
        // 0x80076540: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80076558;
    }
    // 0x80076540: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80076544: jal         0x80075D44
    // 0x80076548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80076548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8007654C: sll         $t6, $s0, 30
    ctx->r14 = S32(ctx->r16 << 30);
    // 0x80076550: b           L_800765CC
    // 0x80076554: or          $v0, $t6, $s1
    ctx->r2 = ctx->r14 | ctx->r17;
        goto L_800765CC;
    // 0x80076554: or          $v0, $t6, $s1
    ctx->r2 = ctx->r14 | ctx->r17;
L_80076558:
    // 0x80076558: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8007655C: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x80076560: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80076564: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x80076568: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007656C: sll         $s1, $s0, 30
    ctx->r17 = S32(ctx->r16 << 30);
    // 0x80076570: addiu       $t9, $t9, 0x4598
    ctx->r25 = ADD32(ctx->r25, 0X4598);
    // 0x80076574: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80076578: ori         $t7, $s1, 0x9
    ctx->r15 = ctx->r17 | 0X9;
    // 0x8007657C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80076580: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80076584: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80076588: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007658C: jal         0x800D0AE0
    // 0x80076590: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    osPfsFileState_recomp(rdram, ctx);
        goto after_2;
    // 0x80076590: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x80076594: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80076598: bne         $v0, $zero, L_800765C0
    if (ctx->r2 != 0) {
        // 0x8007659C: addiu       $a3, $sp, 0x3E
        ctx->r7 = ADD32(ctx->r29, 0X3E);
            goto L_800765C0;
    }
    // 0x8007659C: addiu       $a3, $sp, 0x3E
    ctx->r7 = ADD32(ctx->r29, 0X3E);
    // 0x800765A0: lhu         $a1, 0x38($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X38);
    // 0x800765A4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800765A8: addiu       $t0, $sp, 0x3A
    ctx->r8 = ADD32(ctx->r29, 0X3A);
    // 0x800765AC: jal         0x800D0DD0
    // 0x800765B0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    osPfsDeleteFile_recomp(rdram, ctx);
        goto after_3;
    // 0x800765B0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_3:
    // 0x800765B4: bne         $v0, $zero, L_800765C0
    if (ctx->r2 != 0) {
        // 0x800765B8: nop
    
            goto L_800765C0;
    }
    // 0x800765B8: nop

    // 0x800765BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800765C0:
    // 0x800765C0: jal         0x80075D44
    // 0x800765C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_4;
    // 0x800765C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800765C8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_800765CC:
    // 0x800765CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800765D0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800765D4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800765D8: jr          $ra
    // 0x800765DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800765DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void copy_controller_pak_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800765E0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800765E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800765E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800765EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800765F0: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800765F4: jal         0x80075B34
    // 0x800765F8: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x800765F8: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    after_0:
    // 0x800765FC: beq         $v0, $zero, L_80076620
    if (ctx->r2 == 0) {
        // 0x80076600: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_80076620;
    }
    // 0x80076600: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80076604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076608: jal         0x80075D44
    // 0x8007660C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x8007660C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_1:
    // 0x80076610: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80076614: sll         $t6, $s0, 30
    ctx->r14 = S32(ctx->r16 << 30);
    // 0x80076618: b           L_80076730
    // 0x8007661C: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
        goto L_80076730;
    // 0x8007661C: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
L_80076620:
    // 0x80076620: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80076624: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80076628: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x8007662C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80076630: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x80076634: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80076638: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8007663C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80076640: jal         0x800D0AE0
    // 0x80076644: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    osPfsFileState_recomp(rdram, ctx);
        goto after_2;
    // 0x80076644: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80076648: beq         $v0, $zero, L_8007666C
    if (ctx->r2 == 0) {
        // 0x8007664C: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_8007666C;
    }
    // 0x8007664C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80076650: jal         0x80075D44
    // 0x80076654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_3;
    // 0x80076654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80076658: sll         $v0, $s0, 30
    ctx->r2 = S32(ctx->r16 << 30);
    // 0x8007665C: ori         $t9, $v0, 0x9
    ctx->r25 = ctx->r2 | 0X9;
    // 0x80076660: b           L_80076730
    // 0x80076664: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80076730;
    // 0x80076664: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80076668: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_8007666C:
    // 0x8007666C: jal         0x80070EDC
    // 0x80076670: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x80076670: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x80076674: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80076678: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8007667C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80076680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076684: jal         0x80076868
    // 0x80076688: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80076688: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x8007668C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076690: jal         0x80075D44
    // 0x80076694: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_6;
    // 0x80076694: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_6:
    // 0x80076698: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8007669C: addiu       $a0, $sp, 0x42
    ctx->r4 = ADD32(ctx->r29, 0X42);
    // 0x800766A0: beq         $v1, $zero, L_800766C4
    if (ctx->r3 == 0) {
        // 0x800766A4: addiu       $a2, $zero, 0x10
        ctx->r6 = ADD32(0, 0X10);
            goto L_800766C4;
    }
    // 0x800766A4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800766A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800766AC: jal         0x80071380
    // 0x800766B0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x800766B0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_7:
    // 0x800766B4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800766B8: sll         $t0, $s0, 30
    ctx->r8 = S32(ctx->r16 << 30);
    // 0x800766BC: b           L_80076730
    // 0x800766C0: or          $v0, $t0, $v1
    ctx->r2 = ctx->r8 | ctx->r3;
        goto L_80076730;
    // 0x800766C0: or          $v0, $t0, $v1
    ctx->r2 = ctx->r8 | ctx->r3;
L_800766C4:
    // 0x800766C4: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x800766C8: jal         0x80076BE4
    // 0x800766CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    font_codes_to_string(rdram, ctx);
        goto after_8;
    // 0x800766CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800766D0: addiu       $a0, $sp, 0x3E
    ctx->r4 = ADD32(ctx->r29, 0X3E);
    // 0x800766D4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800766D8: jal         0x80076BE4
    // 0x800766DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    font_codes_to_string(rdram, ctx);
        goto after_9;
    // 0x800766DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_9:
    // 0x800766E0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800766E4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800766E8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800766EC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800766F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800766F4: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x800766F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800766FC: jal         0x8007692C
    // 0x80076700: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    write_controller_pak_file(rdram, ctx);
        goto after_10;
    // 0x80076700: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_10:
    // 0x80076704: beq         $v0, $zero, L_8007671C
    if (ctx->r2 == 0) {
        // 0x80076708: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8007671C;
    }
    // 0x80076708: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007670C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80076710: nop

    // 0x80076714: sll         $t4, $t3, 30
    ctx->r12 = S32(ctx->r11 << 30);
    // 0x80076718: or          $v1, $v0, $t4
    ctx->r3 = ctx->r2 | ctx->r12;
L_8007671C:
    // 0x8007671C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80076720: jal         0x80071380
    // 0x80076724: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_11;
    // 0x80076724: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_11:
    // 0x80076728: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8007672C: nop

L_80076730:
    // 0x80076730: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80076734: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80076738: jr          $ra
    // 0x8007673C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8007673C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void get_file_number(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076740: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80076744: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80076748: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007674C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80076750: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80076754: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80076758: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8007675C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80076760: jal         0x80076C90
    // 0x80076764: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    string_to_font_codes(rdram, ctx);
        goto after_0;
    // 0x80076764: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x80076768: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007676C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80076770: jal         0x80076C90
    // 0x80076774: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    string_to_font_codes(rdram, ctx);
        goto after_1;
    // 0x80076774: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80076778: jal         0x8009F064
    // 0x8007677C: nop

    get_language(rdram, ctx);
        goto after_2;
    // 0x8007677C: nop

    after_2:
    // 0x80076780: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80076784: bne         $v0, $at, L_80076798
    if (ctx->r2 != ctx->r1) {
        // 0x80076788: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80076798;
    }
    // 0x80076788: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007678C: lui         $a2, 0x4E44
    ctx->r6 = S32(0X4E44 << 16);
    // 0x80076790: b           L_800767B8
    // 0x80076794: ori         $a2, $a2, 0x594A
    ctx->r6 = ctx->r6 | 0X594A;
        goto L_800767B8;
    // 0x80076794: ori         $a2, $a2, 0x594A
    ctx->r6 = ctx->r6 | 0X594A;
L_80076798:
    // 0x80076798: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8007679C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800767A0: lui         $a2, 0x4E44
    ctx->r6 = S32(0X4E44 << 16);
    // 0x800767A4: bne         $t6, $zero, L_800767B8
    if (ctx->r14 != 0) {
        // 0x800767A8: ori         $a2, $a2, 0x5945
        ctx->r6 = ctx->r6 | 0X5945;
            goto L_800767B8;
    }
    // 0x800767A8: ori         $a2, $a2, 0x5945
    ctx->r6 = ctx->r6 | 0X5945;
    // 0x800767AC: lui         $a2, 0x4E44
    ctx->r6 = S32(0X4E44 << 16);
    // 0x800767B0: b           L_800767B8
    // 0x800767B4: ori         $a2, $a2, 0x5950
    ctx->r6 = ctx->r6 | 0X5950;
        goto L_800767B8;
    // 0x800767B4: ori         $a2, $a2, 0x5950
    ctx->r6 = ctx->r6 | 0X5950;
L_800767B8:
    // 0x800767B8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800767BC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800767C0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800767C4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800767C8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800767CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800767D0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800767D4: addiu       $t9, $t9, 0x4598
    ctx->r25 = ADD32(ctx->r25, 0X4598);
    // 0x800767D8: addiu       $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x800767DC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800767E0: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800767E4: addiu       $a1, $zero, 0x3459
    ctx->r5 = ADD32(0, 0X3459);
    // 0x800767E8: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x800767EC: jal         0x800D13E0
    // 0x800767F0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    osPfsFindFile_recomp(rdram, ctx);
        goto after_3;
    // 0x800767F0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_3:
    // 0x800767F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800767F8: bne         $v0, $zero, L_80076808
    if (ctx->r2 != 0) {
        // 0x800767FC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80076808;
    }
    // 0x800767FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80076800: b           L_80076860
    // 0x80076804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076860;
    // 0x80076804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076808:
    // 0x80076808: beq         $v0, $at, L_80076818
    if (ctx->r2 == ctx->r1) {
        // 0x8007680C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80076818;
    }
    // 0x8007680C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80076810: bne         $v0, $at, L_80076824
    if (ctx->r2 != ctx->r1) {
        // 0x80076814: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80076824;
    }
    // 0x80076814: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80076818:
    // 0x80076818: b           L_80076860
    // 0x8007681C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80076860;
    // 0x8007681C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80076820: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80076824:
    // 0x80076824: bne         $v0, $at, L_80076838
    if (ctx->r2 != ctx->r1) {
        // 0x80076828: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80076838;
    }
    // 0x80076828: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007682C: b           L_80076860
    // 0x80076830: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80076860;
    // 0x80076830: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80076834: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80076838:
    // 0x80076838: bne         $v0, $at, L_8007684C
    if (ctx->r2 != ctx->r1) {
        // 0x8007683C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8007684C;
    }
    // 0x8007683C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80076840: b           L_80076860
    // 0x80076844: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80076860;
    // 0x80076844: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80076848: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8007684C:
    // 0x8007684C: bne         $v0, $at, L_80076860
    if (ctx->r2 != ctx->r1) {
        // 0x80076850: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80076860;
    }
    // 0x80076850: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80076854: b           L_80076860
    // 0x80076858: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80076860;
    // 0x80076858: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8007685C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80076860:
    // 0x80076860: jr          $ra
    // 0x80076864: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80076864: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void read_data_from_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076868: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007686C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80076870: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80076874: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80076878: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007687C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80076880: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80076884: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80076888: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8007688C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80076890: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80076894: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80076898: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x8007689C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800768A0: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800768A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800768A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800768AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800768B0: jal         0x800CF53C
    // 0x800768B4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_0;
    // 0x800768B4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_0:
    // 0x800768B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800768BC: bne         $v0, $zero, L_800768CC
    if (ctx->r2 != 0) {
        // 0x800768C0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800768CC;
    }
    // 0x800768C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800768C4: b           L_80076924
    // 0x800768C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076924;
    // 0x800768C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800768CC:
    // 0x800768CC: beq         $v0, $at, L_800768DC
    if (ctx->r2 == ctx->r1) {
        // 0x800768D0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800768DC;
    }
    // 0x800768D0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800768D4: bne         $v0, $at, L_800768E8
    if (ctx->r2 != ctx->r1) {
        // 0x800768D8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800768E8;
    }
    // 0x800768D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800768DC:
    // 0x800768DC: b           L_80076924
    // 0x800768E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80076924;
    // 0x800768E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800768E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800768E8:
    // 0x800768E8: bne         $v0, $at, L_800768FC
    if (ctx->r2 != ctx->r1) {
        // 0x800768EC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800768FC;
    }
    // 0x800768EC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800768F0: b           L_80076924
    // 0x800768F4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80076924;
    // 0x800768F4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800768F8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800768FC:
    // 0x800768FC: bne         $v0, $at, L_80076910
    if (ctx->r2 != ctx->r1) {
        // 0x80076900: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80076910;
    }
    // 0x80076900: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80076904: b           L_80076924
    // 0x80076908: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80076924;
    // 0x80076908: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007690C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80076910:
    // 0x80076910: bne         $v0, $at, L_80076924
    if (ctx->r2 != ctx->r1) {
        // 0x80076914: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80076924;
    }
    // 0x80076914: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80076918: b           L_80076924
    // 0x8007691C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80076924;
    // 0x8007691C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80076920: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80076924:
    // 0x80076924: jr          $ra
    // 0x80076928: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80076928: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void write_controller_pak_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007692C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80076930: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80076934: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80076938: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8007693C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80076940: jal         0x80075B34
    // 0x80076944: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80076944: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_0:
    // 0x80076948: beq         $v0, $zero, L_80076968
    if (ctx->r2 == 0) {
        // 0x8007694C: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_80076968;
    }
    // 0x8007694C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80076950: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80076954: jal         0x80075D44
    // 0x80076958: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80076958: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x8007695C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80076960: b           L_80076B70
    // 0x80076964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80076B70;
    // 0x80076964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80076968:
    // 0x80076968: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8007696C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80076970: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80076974: beq         $v0, $zero, L_80076984
    if (ctx->r2 == 0) {
        // 0x80076978: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80076984;
    }
    // 0x80076978: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8007697C: subu        $a3, $v1, $v0
    ctx->r7 = SUB32(ctx->r3, ctx->r2);
    // 0x80076980: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
L_80076984:
    // 0x80076984: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80076988: jal         0x80076C90
    // 0x8007698C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    string_to_font_codes(rdram, ctx);
        goto after_2;
    // 0x8007698C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_2:
    // 0x80076990: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80076994: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80076998: jal         0x80076C90
    // 0x8007699C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    string_to_font_codes(rdram, ctx);
        goto after_3;
    // 0x8007699C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x800769A0: jal         0x8009F064
    // 0x800769A4: nop

    get_language(rdram, ctx);
        goto after_4;
    // 0x800769A4: nop

    after_4:
    // 0x800769A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800769AC: bne         $v0, $at, L_800769C4
    if (ctx->r2 != ctx->r1) {
        // 0x800769B0: lui         $t7, 0x8000
        ctx->r15 = S32(0X8000 << 16);
            goto L_800769C4;
    }
    // 0x800769B0: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800769B4: lui         $t6, 0x4E44
    ctx->r14 = S32(0X4E44 << 16);
    // 0x800769B8: ori         $t6, $t6, 0x594A
    ctx->r14 = ctx->r14 | 0X594A;
    // 0x800769BC: b           L_800769E8
    // 0x800769C0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
        goto L_800769E8;
    // 0x800769C0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_800769C4:
    // 0x800769C4: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800769C8: lui         $t9, 0x4E44
    ctx->r25 = S32(0X4E44 << 16);
    // 0x800769CC: bne         $t7, $zero, L_800769E4
    if (ctx->r15 != 0) {
        // 0x800769D0: ori         $t9, $t9, 0x5945
        ctx->r25 = ctx->r25 | 0X5945;
            goto L_800769E4;
    }
    // 0x800769D0: ori         $t9, $t9, 0x5945
    ctx->r25 = ctx->r25 | 0X5945;
    // 0x800769D4: lui         $t8, 0x4E44
    ctx->r24 = S32(0X4E44 << 16);
    // 0x800769D8: ori         $t8, $t8, 0x5950
    ctx->r24 = ctx->r24 | 0X5950;
    // 0x800769DC: b           L_800769E8
    // 0x800769E0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
        goto L_800769E8;
    // 0x800769E0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_800769E4:
    // 0x800769E4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_800769E8:
    // 0x800769E8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800769EC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800769F0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x800769F4: jal         0x80076740
    // 0x800769F8: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    get_file_number(rdram, ctx);
        goto after_5;
    // 0x800769F8: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x800769FC: bne         $v0, $zero, L_80076A2C
    if (ctx->r2 != 0) {
        // 0x80076A00: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80076A2C;
    }
    // 0x80076A00: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076A04: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80076A08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80076A0C: beq         $v0, $at, L_80076AC0
    if (ctx->r2 == ctx->r1) {
        // 0x80076A10: nop
    
            goto L_80076AC0;
    }
    // 0x80076A10: nop

    // 0x80076A14: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80076A18: nop

    // 0x80076A1C: beq         $v0, $t0, L_80076AC0
    if (ctx->r2 == ctx->r8) {
        // 0x80076A20: nop
    
            goto L_80076AC0;
    }
    // 0x80076A20: nop

    // 0x80076A24: b           L_80076AC0
    // 0x80076A28: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_80076AC0;
    // 0x80076A28: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_80076A2C:
    // 0x80076A2C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80076A30: bne         $v0, $at, L_80076AC0
    if (ctx->r2 != ctx->r1) {
        // 0x80076A34: nop
    
            goto L_80076AC0;
    }
    // 0x80076A34: nop

    // 0x80076A38: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80076A3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80076A40: beq         $t1, $at, L_80076A50
    if (ctx->r9 == ctx->r1) {
        // 0x80076A44: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80076A50;
    }
    // 0x80076A44: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80076A48: b           L_80076AC0
    // 0x80076A4C: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_80076AC0;
    // 0x80076A4C: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_80076A50:
    // 0x80076A50: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80076A54: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80076A58: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80076A5C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80076A60: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80076A64: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80076A68: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80076A6C: addiu       $t4, $t4, 0x4598
    ctx->r12 = ADD32(ctx->r12, 0X4598);
    // 0x80076A70: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80076A74: addiu       $t5, $sp, 0x3C
    ctx->r13 = ADD32(ctx->r29, 0X3C);
    // 0x80076A78: addiu       $t7, $sp, 0x34
    ctx->r15 = ADD32(ctx->r29, 0X34);
    // 0x80076A7C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80076A80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80076A84: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80076A88: addiu       $a1, $zero, 0x3459
    ctx->r5 = ADD32(0, 0X3459);
    // 0x80076A8C: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    // 0x80076A90: jal         0x800D15A0
    // 0x80076A94: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    osPfsAllocateFile_recomp(rdram, ctx);
        goto after_6;
    // 0x80076A94: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x80076A98: bne         $v0, $zero, L_80076AA8
    if (ctx->r2 != 0) {
        // 0x80076A9C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80076AA8;
    }
    // 0x80076A9C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80076AA0: b           L_80076AC0
    // 0x80076AA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80076AC0;
    // 0x80076AA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80076AA8:
    // 0x80076AA8: beq         $v0, $at, L_80076AB8
    if (ctx->r2 == ctx->r1) {
        // 0x80076AAC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80076AB8;
    }
    // 0x80076AAC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80076AB0: bne         $v0, $at, L_80076AC0
    if (ctx->r2 != ctx->r1) {
        // 0x80076AB4: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_80076AC0;
    }
    // 0x80076AB4: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_80076AB8:
    // 0x80076AB8: b           L_80076AC0
    // 0x80076ABC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80076AC0;
    // 0x80076ABC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80076AC0:
    // 0x80076AC0: bne         $v1, $zero, L_80076B58
    if (ctx->r3 != 0) {
        // 0x80076AC4: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80076B58;
    }
    // 0x80076AC4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80076AC8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80076ACC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80076AD0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80076AD4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80076AD8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80076ADC: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80076AE0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80076AE4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80076AE8: addiu       $t0, $t0, 0x4598
    ctx->r8 = ADD32(ctx->r8, 0X4598);
    // 0x80076AEC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80076AF0: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80076AF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80076AF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80076AFC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80076B00: jal         0x800CF53C
    // 0x80076B04: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_7;
    // 0x80076B04: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_7:
    // 0x80076B08: bne         $v0, $zero, L_80076B18
    if (ctx->r2 != 0) {
        // 0x80076B0C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80076B18;
    }
    // 0x80076B0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80076B10: b           L_80076B58
    // 0x80076B14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80076B58;
    // 0x80076B14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80076B18:
    // 0x80076B18: beq         $v0, $at, L_80076B28
    if (ctx->r2 == ctx->r1) {
        // 0x80076B1C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80076B28;
    }
    // 0x80076B1C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80076B20: bne         $v0, $at, L_80076B34
    if (ctx->r2 != ctx->r1) {
        // 0x80076B24: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80076B34;
    }
    // 0x80076B24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80076B28:
    // 0x80076B28: b           L_80076B58
    // 0x80076B2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80076B58;
    // 0x80076B2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80076B30: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80076B34:
    // 0x80076B34: bne         $v0, $at, L_80076B48
    if (ctx->r2 != ctx->r1) {
        // 0x80076B38: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80076B48;
    }
    // 0x80076B38: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80076B3C: b           L_80076B58
    // 0x80076B40: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80076B58;
    // 0x80076B40: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80076B44: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80076B48:
    // 0x80076B48: bne         $v0, $at, L_80076B58
    if (ctx->r2 != ctx->r1) {
        // 0x80076B4C: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_80076B58;
    }
    // 0x80076B4C: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x80076B50: b           L_80076B58
    // 0x80076B54: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80076B58;
    // 0x80076B54: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80076B58:
    // 0x80076B58: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80076B5C: jal         0x80075D44
    // 0x80076B60: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_8;
    // 0x80076B60: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_8:
    // 0x80076B64: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80076B68: nop

    // 0x80076B6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80076B70:
    // 0x80076B70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80076B74: jr          $ra
    // 0x80076B78: nop

    return;
    // 0x80076B78: nop

;}
RECOMP_FUNC void get_file_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076B7C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80076B80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80076B84: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80076B88: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80076B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076B90: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80076B94: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80076B98: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80076B9C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80076BA0: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x80076BA4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80076BA8: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80076BAC: jal         0x800D0AE0
    // 0x80076BB0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    osPfsFileState_recomp(rdram, ctx);
        goto after_0;
    // 0x80076BB0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80076BB4: bne         $v0, $zero, L_80076BD4
    if (ctx->r2 != 0) {
        // 0x80076BB8: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80076BD4;
    }
    // 0x80076BB8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80076BBC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80076BC0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80076BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80076BC8: b           L_80076BD4
    // 0x80076BCC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_80076BD4;
    // 0x80076BCC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80076BD0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80076BD4:
    // 0x80076BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076BD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80076BDC: jr          $ra
    // 0x80076BE0: nop

    return;
    // 0x80076BE0: nop

;}
RECOMP_FUNC void font_codes_to_string(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076BE4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80076BE8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80076BEC: beq         $v0, $zero, L_80076C40
    if (ctx->r2 == 0) {
        // 0x80076BF0: nop
    
            goto L_80076C40;
    }
    // 0x80076BF0: nop

    // 0x80076BF4: beq         $a2, $zero, L_80076C40
    if (ctx->r6 == 0) {
        // 0x80076BF8: addiu       $t0, $zero, 0x2D
        ctx->r8 = ADD32(0, 0X2D);
            goto L_80076C40;
    }
    // 0x80076BF8: addiu       $t0, $zero, 0x2D
    ctx->r8 = ADD32(0, 0X2D);
    // 0x80076BFC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80076C00: addiu       $a3, $a3, -0x164C
    ctx->r7 = ADD32(ctx->r7, -0X164C);
    // 0x80076C04: slti        $at, $v0, 0x42
    ctx->r1 = SIGNED(ctx->r2) < 0X42 ? 1 : 0;
L_80076C08:
    // 0x80076C08: beq         $at, $zero, L_80076C20
    if (ctx->r1 == 0) {
        // 0x80076C0C: addu        $t6, $a3, $v0
        ctx->r14 = ADD32(ctx->r7, ctx->r2);
            goto L_80076C20;
    }
    // 0x80076C0C: addu        $t6, $a3, $v0
    ctx->r14 = ADD32(ctx->r7, ctx->r2);
    // 0x80076C10: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80076C14: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80076C18: b           L_80076C28
    // 0x80076C1C: sb          $t7, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r15;
        goto L_80076C28;
    // 0x80076C1C: sb          $t7, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r15;
L_80076C20:
    // 0x80076C20: sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
    // 0x80076C24: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80076C28:
    // 0x80076C28: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x80076C2C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80076C30: beq         $v0, $zero, L_80076C40
    if (ctx->r2 == 0) {
        // 0x80076C34: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80076C40;
    }
    // 0x80076C34: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80076C38: bne         $a2, $zero, L_80076C08
    if (ctx->r6 != 0) {
        // 0x80076C3C: slti        $at, $v0, 0x42
        ctx->r1 = SIGNED(ctx->r2) < 0X42 ? 1 : 0;
            goto L_80076C08;
    }
    // 0x80076C3C: slti        $at, $v0, 0x42
    ctx->r1 = SIGNED(ctx->r2) < 0X42 ? 1 : 0;
L_80076C40:
    // 0x80076C40: beq         $a2, $zero, L_80076C84
    if (ctx->r6 == 0) {
        // 0x80076C44: andi        $a0, $a2, 0x3
        ctx->r4 = ctx->r6 & 0X3;
            goto L_80076C84;
    }
    // 0x80076C44: andi        $a0, $a2, 0x3
    ctx->r4 = ctx->r6 & 0X3;
    // 0x80076C48: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80076C4C: beq         $a0, $zero, L_80076C68
    if (ctx->r4 == 0) {
        // 0x80076C50: addu        $v0, $a0, $a2
        ctx->r2 = ADD32(ctx->r4, ctx->r6);
            goto L_80076C68;
    }
    // 0x80076C50: addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
L_80076C54:
    // 0x80076C54: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80076C58: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076C5C: bne         $v0, $a2, L_80076C54
    if (ctx->r2 != ctx->r6) {
        // 0x80076C60: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80076C54;
    }
    // 0x80076C60: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80076C64: beq         $a2, $zero, L_80076C84
    if (ctx->r6 == 0) {
        // 0x80076C68: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80076C84;
    }
L_80076C68:
    // 0x80076C68: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80076C6C: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076C70: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x80076C74: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x80076C78: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
    // 0x80076C7C: bne         $a2, $zero, L_80076C68
    if (ctx->r6 != 0) {
        // 0x80076C80: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80076C68;
    }
    // 0x80076C80: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80076C84:
    // 0x80076C84: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076C88: jr          $ra
    // 0x80076C8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80076C8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void string_to_font_codes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076C90: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80076C94: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80076C98: beq         $t6, $zero, L_80076CFC
    if (ctx->r14 == 0) {
        // 0x80076C9C: nop
    
            goto L_80076CFC;
    }
    // 0x80076C9C: nop

    // 0x80076CA0: beq         $a2, $zero, L_80076CFC
    if (ctx->r6 == 0) {
        // 0x80076CA4: addiu       $t1, $zero, 0x41
        ctx->r9 = ADD32(0, 0X41);
            goto L_80076CFC;
    }
    // 0x80076CA4: addiu       $t1, $zero, 0x41
    ctx->r9 = ADD32(0, 0X41);
L_80076CA8:
    // 0x80076CA8: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076CAC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80076CB0: lbu         $a3, 0x0($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X0);
    // 0x80076CB4: addiu       $t0, $t0, -0x164C
    ctx->r8 = ADD32(ctx->r8, -0X164C);
    // 0x80076CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076CBC:
    // 0x80076CBC: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x80076CC0: nop

    // 0x80076CC4: bne         $a3, $t7, L_80076CD8
    if (ctx->r7 != ctx->r15) {
        // 0x80076CC8: nop
    
            goto L_80076CD8;
    }
    // 0x80076CC8: nop

    // 0x80076CCC: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80076CD0: b           L_80076CE4
    // 0x80076CD4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80076CE4;
    // 0x80076CD4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80076CD8:
    // 0x80076CD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80076CDC: bne         $v0, $t1, L_80076CBC
    if (ctx->r2 != ctx->r9) {
        // 0x80076CE0: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80076CBC;
    }
    // 0x80076CE0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80076CE4:
    // 0x80076CE4: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x80076CE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80076CEC: beq         $t8, $zero, L_80076CFC
    if (ctx->r24 == 0) {
        // 0x80076CF0: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80076CFC;
    }
    // 0x80076CF0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80076CF4: bne         $a2, $zero, L_80076CA8
    if (ctx->r6 != 0) {
        // 0x80076CF8: nop
    
            goto L_80076CA8;
    }
    // 0x80076CF8: nop

L_80076CFC:
    // 0x80076CFC: beq         $a2, $zero, L_80076D40
    if (ctx->r6 == 0) {
        // 0x80076D00: andi        $a0, $a2, 0x3
        ctx->r4 = ctx->r6 & 0X3;
            goto L_80076D40;
    }
    // 0x80076D00: andi        $a0, $a2, 0x3
    ctx->r4 = ctx->r6 & 0X3;
    // 0x80076D04: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80076D08: beq         $a0, $zero, L_80076D24
    if (ctx->r4 == 0) {
        // 0x80076D0C: addu        $v0, $a0, $a2
        ctx->r2 = ADD32(ctx->r4, ctx->r6);
            goto L_80076D24;
    }
    // 0x80076D0C: addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
L_80076D10:
    // 0x80076D10: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80076D14: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076D18: bne         $v0, $a2, L_80076D10
    if (ctx->r2 != ctx->r6) {
        // 0x80076D1C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80076D10;
    }
    // 0x80076D1C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80076D20: beq         $a2, $zero, L_80076D40
    if (ctx->r6 == 0) {
        // 0x80076D24: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80076D40;
    }
L_80076D24:
    // 0x80076D24: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80076D28: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076D2C: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x80076D30: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x80076D34: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
    // 0x80076D38: bne         $a2, $zero, L_80076D24
    if (ctx->r6 != 0) {
        // 0x80076D3C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80076D24;
    }
    // 0x80076D3C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80076D40:
    // 0x80076D40: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076D44: jr          $ra
    // 0x80076D48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80076D48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void get_file_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076D4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80076D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076D54: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80076D58: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80076D5C: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80076D60: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80076D64: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80076D68: jal         0x80070EDC
    // 0x80076D6C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80076D6C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_0:
    // 0x80076D70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80076D74: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80076D78: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80076D7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80076D80: jal         0x80076868
    // 0x80076D84: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    read_data_from_controller_pak(rdram, ctx);
        goto after_1;
    // 0x80076D84: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_1:
    // 0x80076D88: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80076D8C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80076D90: bne         $v0, $zero, L_80076DDC
    if (ctx->r2 != 0) {
        // 0x80076D94: lui         $at, 0x4741
        ctx->r1 = S32(0X4741 << 16);
            goto L_80076DDC;
    }
    // 0x80076D94: lui         $at, 0x4741
    ctx->r1 = S32(0X4741 << 16);
    // 0x80076D98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80076D9C: ori         $at, $at, 0x4D44
    ctx->r1 = ctx->r1 | 0X4D44;
    // 0x80076DA0: beq         $v0, $at, L_80076DC8
    if (ctx->r2 == ctx->r1) {
        // 0x80076DA4: lui         $at, 0x4748
        ctx->r1 = S32(0X4748 << 16);
            goto L_80076DC8;
    }
    // 0x80076DA4: lui         $at, 0x4748
    ctx->r1 = S32(0X4748 << 16);
    // 0x80076DA8: ori         $at, $at, 0x5353
    ctx->r1 = ctx->r1 | 0X5353;
    // 0x80076DAC: beq         $v0, $at, L_80076DD8
    if (ctx->r2 == ctx->r1) {
        // 0x80076DB0: lui         $at, 0x5449
        ctx->r1 = S32(0X5449 << 16);
            goto L_80076DD8;
    }
    // 0x80076DB0: lui         $at, 0x5449
    ctx->r1 = S32(0X5449 << 16);
    // 0x80076DB4: ori         $at, $at, 0x4D44
    ctx->r1 = ctx->r1 | 0X4D44;
    // 0x80076DB8: beq         $v0, $at, L_80076DD0
    if (ctx->r2 == ctx->r1) {
        // 0x80076DBC: nop
    
            goto L_80076DD0;
    }
    // 0x80076DBC: nop

    // 0x80076DC0: b           L_80076DDC
    // 0x80076DC4: nop

        goto L_80076DDC;
    // 0x80076DC4: nop

L_80076DC8:
    // 0x80076DC8: b           L_80076DDC
    // 0x80076DCC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80076DDC;
    // 0x80076DCC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80076DD0:
    // 0x80076DD0: b           L_80076DDC
    // 0x80076DD4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80076DDC;
    // 0x80076DD4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80076DD8:
    // 0x80076DD8: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80076DDC:
    // 0x80076DDC: jal         0x80071380
    // 0x80076DE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80076DE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80076DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076DE8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80076DEC: jr          $ra
    // 0x80076DF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80076DF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80076DF4: nop

    // 0x80076DF8: nop

    // 0x80076DFC: nop

;}
RECOMP_FUNC void pi_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076E00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80076E04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076E08: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076E0C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076E10: addiu       $a1, $a1, 0x47B8
    ctx->r5 = ADD32(ctx->r5, 0X47B8);
    // 0x80076E14: addiu       $a0, $a0, 0x47F8
    ctx->r4 = ADD32(ctx->r4, 0X47F8);
    // 0x80076E18: jal         0x800C8D80
    // 0x80076E1C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80076E1C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x80076E20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076E24: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076E28: addiu       $a1, $a1, 0x4798
    ctx->r5 = ADD32(ctx->r5, 0X4798);
    // 0x80076E2C: addiu       $a0, $a0, 0x47A0
    ctx->r4 = ADD32(ctx->r4, 0X47A0);
    // 0x80076E30: jal         0x800C8D80
    // 0x80076E34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80076E34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80076E38: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076E3C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80076E40: addiu       $a2, $a2, 0x47B8
    ctx->r6 = ADD32(ctx->r6, 0X47B8);
    // 0x80076E44: addiu       $a1, $a1, 0x47F8
    ctx->r5 = ADD32(ctx->r5, 0X47F8);
    // 0x80076E48: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80076E4C: jal         0x800C6560
    // 0x80076E50: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_2;
    // 0x80076E50: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x80076E54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076E58: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076E5C: addiu       $a1, $a1, 0x4810
    ctx->r5 = ADD32(ctx->r5, 0X4810);
    // 0x80076E60: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80076E64: jal         0x800C8D80
    // 0x80076E68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x80076E68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80076E6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076E70: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80076E74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80076E78: jal         0x800C9390
    // 0x80076E7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80076E7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80076E80: lui         $t6, 0xF
    ctx->r14 = S32(0XF << 16);
    // 0x80076E84: lui         $t7, 0xF
    ctx->r15 = S32(0XF << 16);
    // 0x80076E88: addiu       $t7, $t7, -0x2F20
    ctx->r15 = ADD32(ctx->r15, -0X2F20);
    // 0x80076E8C: addiu       $t6, $t6, -0x2E50
    ctx->r14 = ADD32(ctx->r14, -0X2E50);
    // 0x80076E90: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x80076E94: lui         $a1, 0x7F7F
    ctx->r5 = S32(0X7F7F << 16);
    // 0x80076E98: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80076E9C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80076EA0: jal         0x80070EDC
    // 0x80076EA4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x80076EA4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_5:
    // 0x80076EA8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80076EAC: addiu       $v1, $v1, 0x4830
    ctx->r3 = ADD32(ctx->r3, 0X4830);
    // 0x80076EB0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80076EB4: jal         0x800716B8
    // 0x80076EB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mempool_locked_set(rdram, ctx);
        goto after_6;
    // 0x80076EB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80076EBC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076EC0: lw          $a1, 0x4830($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4830);
    // 0x80076EC4: lui         $a0, 0xF
    ctx->r4 = S32(0XF << 16);
    // 0x80076EC8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80076ECC: jal         0x800773D4
    // 0x80076ED0: addiu       $a0, $a0, -0x2F20
    ctx->r4 = ADD32(ctx->r4, -0X2F20);
    dmacopy_v1(rdram, ctx);
        goto after_7;
    // 0x80076ED0: addiu       $a0, $a0, -0x2F20
    ctx->r4 = ADD32(ctx->r4, -0X2F20);
    after_7:
    // 0x80076ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076ED8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80076EDC: jr          $ra
    // 0x80076EE0: nop

    return;
    // 0x80076EE0: nop

;}
RECOMP_FUNC void asset_table_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076EE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80076EE8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80076EEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076EF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076EF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80076EF8: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80076EFC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80076F00: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80076F04: jal         0x800C9110
    // 0x80076F08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80076F08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80076F0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80076F10: lw          $v1, 0x4830($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4830);
    // 0x80076F14: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80076F18: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80076F1C: lui         $a1, 0x7F7F
    ctx->r5 = S32(0X7F7F << 16);
    // 0x80076F20: sltu        $at, $t6, $a3
    ctx->r1 = ctx->r14 < ctx->r7 ? 1 : 0;
    // 0x80076F24: beq         $at, $zero, L_80076F34
    if (ctx->r1 == 0) {
        // 0x80076F28: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80076F34;
    }
    // 0x80076F28: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80076F2C: b           L_80076FA0
    // 0x80076F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076FA0;
    // 0x80076F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076F34:
    // 0x80076F34: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80076F38: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80076F3C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80076F40: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80076F44: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80076F48: subu        $a0, $t8, $t0
    ctx->r4 = SUB32(ctx->r24, ctx->r8);
    // 0x80076F4C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80076F50: jal         0x80070EDC
    // 0x80076F54: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80076F54: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_1:
    // 0x80076F58: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80076F5C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80076F60: bne         $v0, $zero, L_80076F70
    if (ctx->r2 != 0) {
        // 0x80076F64: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80076F70;
    }
    // 0x80076F64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80076F68: b           L_80076FA0
    // 0x80076F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076FA0;
    // 0x80076F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076F70:
    // 0x80076F70: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x80076F74: addiu       $t9, $t9, -0x2E50
    ctx->r25 = ADD32(ctx->r25, -0X2E50);
    // 0x80076F78: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    // 0x80076F7C: jal         0x800773D4
    // 0x80076F80: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    dmacopy_v1(rdram, ctx);
        goto after_2;
    // 0x80076F80: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_2:
    // 0x80076F84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076F88: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80076F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80076F90: jal         0x800C9390
    // 0x80076F94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80076F94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80076F98: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80076F9C: nop

L_80076FA0:
    // 0x80076FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076FA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80076FA8: jr          $ra
    // 0x80076FAC: nop

    return;
    // 0x80076FAC: nop

;}
RECOMP_FUNC void asset_table_load_zipped(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076FB0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80076FB4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80076FB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80076FBC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80076FC0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076FC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80076FC8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80076FCC: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80076FD0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80076FD4: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80076FD8: jal         0x800C9110
    // 0x80076FDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80076FDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80076FE0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80076FE4: lw          $v1, 0x4830($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4830);
    // 0x80076FE8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80076FEC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80076FF0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80076FF4: sltu        $at, $t6, $a3
    ctx->r1 = ctx->r14 < ctx->r7 ? 1 : 0;
    // 0x80076FF8: beq         $at, $zero, L_80077008
    if (ctx->r1 == 0) {
        // 0x80076FFC: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80077008;
    }
    // 0x80076FFC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80077000: b           L_800770D8
    // 0x80077004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800770D8;
    // 0x80077004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077008:
    // 0x80077008: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8007700C: addu        $s0, $t7, $v1
    ctx->r16 = ADD32(ctx->r15, ctx->r3);
    // 0x80077010: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80077014: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80077018: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8007701C: subu        $t9, $t8, $t0
    ctx->r25 = SUB32(ctx->r24, ctx->r8);
    // 0x80077020: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80077024: jal         0x80070EDC
    // 0x80077028: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80077028: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x8007702C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80077030: lui         $t1, 0xF
    ctx->r9 = S32(0XF << 16);
    // 0x80077034: addiu       $t1, $t1, -0x2E50
    ctx->r9 = ADD32(ctx->r9, -0X2E50);
    // 0x80077038: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x8007703C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80077040: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80077044: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80077048: jal         0x800773D4
    // 0x8007704C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    dmacopy_v1(rdram, ctx);
        goto after_2;
    // 0x8007704C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80077050: jal         0x800C670C
    // 0x80077054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    byteswap32(rdram, ctx);
        goto after_3;
    // 0x80077054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80077058: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8007705C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80077060: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80077064: jal         0x80071380
    // 0x80077068: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80077068: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    after_4:
    // 0x8007706C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80077070: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80077074: lui         $a1, 0x7F7F
    ctx->r5 = S32(0X7F7F << 16);
    // 0x80077078: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x8007707C: jal         0x80070EDC
    // 0x80077080: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x80077080: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_5:
    // 0x80077084: bne         $v0, $zero, L_80077094
    if (ctx->r2 != 0) {
        // 0x80077088: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80077094;
    }
    // 0x80077088: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007708C: b           L_800770D8
    // 0x80077090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800770D8;
    // 0x80077090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077094:
    // 0x80077094: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80077098: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8007709C: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800770A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800770A4: subu        $a3, $t7, $a2
    ctx->r7 = SUB32(ctx->r15, ctx->r6);
    // 0x800770A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800770AC: jal         0x800773D4
    // 0x800770B0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    dmacopy_v1(rdram, ctx);
        goto after_6;
    // 0x800770B0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_6:
    // 0x800770B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800770B8: jal         0x800C6778
    // 0x800770BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    gzip_inflate(rdram, ctx);
        goto after_7;
    // 0x800770BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800770C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800770C4: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x800770C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800770CC: jal         0x800C9390
    // 0x800770D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x800770D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x800770D4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800770D8:
    // 0x800770D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800770DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800770E0: jr          $ra
    // 0x800770E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800770E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void asset_table_load_addr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800770E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800770EC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800770F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800770F4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800770F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800770FC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80077100: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80077104: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80077108: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8007710C: jal         0x800C9110
    // 0x80077110: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80077110: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80077114: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80077118: lw          $t0, 0x4830($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4830);
    // 0x8007711C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80077120: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80077124: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x80077128: sltu        $at, $t6, $a3
    ctx->r1 = ctx->r14 < ctx->r7 ? 1 : 0;
    // 0x8007712C: beq         $at, $zero, L_8007713C
    if (ctx->r1 == 0) {
        // 0x80077130: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_8007713C;
    }
    // 0x80077130: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80077134: b           L_80077180
    // 0x80077138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077180;
    // 0x80077138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007713C:
    // 0x8007713C: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80077140: addu        $v0, $t7, $t0
    ctx->r2 = ADD32(ctx->r15, ctx->r8);
    // 0x80077144: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80077148: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8007714C: addiu       $t9, $t9, -0x2E50
    ctx->r25 = ADD32(ctx->r25, -0X2E50);
    // 0x80077150: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80077154: subu        $a2, $t8, $v1
    ctx->r6 = SUB32(ctx->r24, ctx->r3);
    // 0x80077158: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007715C: jal         0x800773D4
    // 0x80077160: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    dmacopy_v1(rdram, ctx);
        goto after_1;
    // 0x80077160: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    after_1:
    // 0x80077164: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077168: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x8007716C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80077170: jal         0x800C9390
    // 0x80077174: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077174: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80077178: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8007717C: nop

L_80077180:
    // 0x80077180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077184: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80077188: jr          $ra
    // 0x8007718C: nop

    return;
    // 0x8007718C: nop

;}
RECOMP_FUNC void asset_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077190: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077194: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80077198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007719C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800771A0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800771A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800771A8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800771AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800771B0: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x800771B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800771B8: jal         0x800C9110
    // 0x800771BC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800771BC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800771C0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800771C4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800771C8: beq         $a2, $zero, L_800771EC
    if (ctx->r6 == 0) {
        // 0x800771CC: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_800771EC;
    }
    // 0x800771CC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800771D0: lw          $a3, 0x4830($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4830);
    // 0x800771D4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800771D8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800771DC: lui         $t1, 0xF
    ctx->r9 = S32(0XF << 16);
    // 0x800771E0: sltu        $at, $t6, $t0
    ctx->r1 = ctx->r14 < ctx->r8 ? 1 : 0;
    // 0x800771E4: beq         $at, $zero, L_800771F4
    if (ctx->r1 == 0) {
        // 0x800771E8: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800771F4;
    }
    // 0x800771E8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800771EC:
    // 0x800771EC: b           L_80077230
    // 0x800771F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077230;
    // 0x800771F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800771F4:
    // 0x800771F4: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800771F8: addu        $v0, $t7, $a3
    ctx->r2 = ADD32(ctx->r15, ctx->r7);
    // 0x800771FC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80077200: addiu       $t1, $t1, -0x2E50
    ctx->r9 = ADD32(ctx->r9, -0X2E50);
    // 0x80077204: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80077208: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8007720C: jal         0x800773D4
    // 0x80077210: addu        $a0, $v1, $t1
    ctx->r4 = ADD32(ctx->r3, ctx->r9);
    dmacopy_v1(rdram, ctx);
        goto after_1;
    // 0x80077210: addu        $a0, $v1, $t1
    ctx->r4 = ADD32(ctx->r3, ctx->r9);
    after_1:
    // 0x80077214: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077218: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x8007721C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80077220: jal         0x800C9390
    // 0x80077224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80077228: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8007722C: nop

L_80077230:
    // 0x80077230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077234: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80077238: jr          $ra
    // 0x8007723C: nop

    return;
    // 0x8007723C: nop

;}
RECOMP_FUNC void asset_rom_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077240: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077244: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80077248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007724C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80077250: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077254: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80077258: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x8007725C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80077260: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80077264: jal         0x800C9110
    // 0x80077268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80077268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007726C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80077270: lw          $v1, 0x4830($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4830);
    // 0x80077274: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80077278: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8007727C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80077280: sltu        $at, $t6, $a3
    ctx->r1 = ctx->r14 < ctx->r7 ? 1 : 0;
    // 0x80077284: beq         $at, $zero, L_80077294
    if (ctx->r1 == 0) {
        // 0x80077288: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80077294;
    }
    // 0x80077288: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8007728C: b           L_800772CC
    // 0x80077290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800772CC;
    // 0x80077290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077294:
    // 0x80077294: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80077298: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x8007729C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800772A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800772A4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800772A8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800772AC: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x800772B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800772B4: jal         0x800C9390
    // 0x800772B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800772B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800772BC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800772C0: lui         $t2, 0xF
    ctx->r10 = S32(0XF << 16);
    // 0x800772C4: addiu       $t2, $t2, -0x2E50
    ctx->r10 = ADD32(ctx->r10, -0X2E50);
    // 0x800772C8: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
L_800772CC:
    // 0x800772CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800772D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800772D4: jr          $ra
    // 0x800772D8: nop

    return;
    // 0x800772D8: nop

;}
