#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void traverse_segments_bsp_tree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029B38: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80029B3C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80029B40: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80029B44: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80029B48: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80029B4C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x80029B50: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80029B54: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80029B58: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80029B5C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80029B60: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80029B64: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80029B68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80029B6C: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80029B70: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80029B74: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80029B78: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80029B7C: addiu       $fp, $fp, -0x3178
    ctx->r30 = ADD32(ctx->r30, -0X3178);
    // 0x80029B80: addiu       $s7, $s7, -0x49D0
    ctx->r23 = ADD32(ctx->r23, -0X49D0);
    // 0x80029B84: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80029B88: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
L_80029B8C:
    // 0x80029B8C: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80029B90: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x80029B94: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80029B98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80029B9C: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80029BA0: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80029BA4: nop

    // 0x80029BA8: bne         $v0, $zero, L_80029BE0
    if (ctx->r2 != 0) {
        // 0x80029BAC: nop
    
            goto L_80029BE0;
    }
    // 0x80029BAC: nop

    // 0x80029BB0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80029BB4: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80029BB8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80029BBC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029BC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029BC4: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80029BC8: nop

    // 0x80029BCC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80029BD0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80029BD4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80029BD8: b           L_80029C48
    // 0x80029BDC: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
        goto L_80029C48;
    // 0x80029BDC: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
L_80029BE0:
    // 0x80029BE0: bne         $v0, $at, L_80029C18
    if (ctx->r2 != ctx->r1) {
        // 0x80029BE4: nop
    
            goto L_80029C18;
    }
    // 0x80029BE4: nop

    // 0x80029BE8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80029BEC: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x80029BF0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80029BF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029BF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029BFC: lwc1        $f8, 0x10($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X10);
    // 0x80029C00: nop

    // 0x80029C04: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80029C08: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80029C0C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80029C10: b           L_80029C48
    // 0x80029C14: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
        goto L_80029C48;
    // 0x80029C14: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
L_80029C18:
    // 0x80029C18: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80029C1C: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x80029C20: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80029C24: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029C28: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029C2C: lwc1        $f16, 0x14($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X14);
    // 0x80029C30: nop

    // 0x80029C34: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80029C38: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80029C3C: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80029C40: nop

    // 0x80029C44: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
L_80029C48:
    // 0x80029C48: nop

    // 0x80029C4C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80029C50: beq         $at, $zero, L_80029CC4
    if (ctx->r1 == 0) {
        // 0x80029C54: nop
    
            goto L_80029CC4;
    }
    // 0x80029C54: nop

    // 0x80029C58: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80029C5C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80029C60: beq         $s6, $a0, L_80029C88
    if (ctx->r22 == ctx->r4) {
        // 0x80029C64: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_80029C88;
    }
    // 0x80029C64: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80029C68: lbu         $a2, 0x5($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X5);
    // 0x80029C6C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80029C70: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029C74: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80029C78: jal         0x80029B38
    // 0x80029C7C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    traverse_segments_bsp_tree(rdram, ctx);
        goto after_0;
    // 0x80029C7C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x80029C80: b           L_80029C94
    // 0x80029C84: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
        goto L_80029C94;
    // 0x80029C84: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
L_80029C88:
    // 0x80029C88: jal         0x80029D54
    // 0x80029C8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    add_segment_to_order(rdram, ctx);
        goto after_1;
    // 0x80029C8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x80029C90: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
L_80029C94:
    // 0x80029C94: nop

    // 0x80029C98: beq         $s6, $a0, L_80029CAC
    if (ctx->r22 == ctx->r4) {
        // 0x80029C9C: nop
    
            goto L_80029CAC;
    }
    // 0x80029C9C: nop

    // 0x80029CA0: lbu         $s4, 0x5($s0)
    ctx->r20 = MEM_BU(ctx->r16, 0X5);
    // 0x80029CA4: b           L_80029B8C
    // 0x80029CA8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
        goto L_80029B8C;
    // 0x80029CA8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
L_80029CAC:
    // 0x80029CAC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80029CB0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80029CB4: jal         0x80029D54
    // 0x80029CB8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    add_segment_to_order(rdram, ctx);
        goto after_2;
    // 0x80029CB8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x80029CBC: b           L_80029D28
    // 0x80029CC0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80029D28;
    // 0x80029CC0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80029CC4:
    // 0x80029CC4: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80029CC8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80029CCC: beq         $s6, $a0, L_80029CF0
    if (ctx->r22 == ctx->r4) {
        // 0x80029CD0: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_80029CF0;
    }
    // 0x80029CD0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80029CD4: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80029CD8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80029CDC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029CE0: jal         0x80029B38
    // 0x80029CE4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    traverse_segments_bsp_tree(rdram, ctx);
        goto after_3;
    // 0x80029CE4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_3:
    // 0x80029CE8: b           L_80029CFC
    // 0x80029CEC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
        goto L_80029CFC;
    // 0x80029CEC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_80029CF0:
    // 0x80029CF0: jal         0x80029D54
    // 0x80029CF4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    add_segment_to_order(rdram, ctx);
        goto after_4;
    // 0x80029CF4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x80029CF8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_80029CFC:
    // 0x80029CFC: nop

    // 0x80029D00: beq         $s6, $a0, L_80029D14
    if (ctx->r22 == ctx->r4) {
        // 0x80029D04: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_80029D14;
    }
    // 0x80029D04: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80029D08: lbu         $s5, 0x5($s0)
    ctx->r21 = MEM_BU(ctx->r16, 0X5);
    // 0x80029D0C: b           L_80029B8C
    // 0x80029D10: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
        goto L_80029B8C;
    // 0x80029D10: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_80029D14:
    // 0x80029D14: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80029D18: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80029D1C: jal         0x80029D54
    // 0x80029D20: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    add_segment_to_order(rdram, ctx);
        goto after_5;
    // 0x80029D20: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x80029D24: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80029D28:
    // 0x80029D28: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80029D2C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80029D30: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80029D34: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80029D38: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80029D3C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80029D40: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80029D44: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80029D48: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80029D4C: jr          $ra
    // 0x80029D50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80029D50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void add_segment_to_order(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029D54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029D58: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80029D5C: lw          $t0, -0x3178($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3178);
    // 0x80029D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029D64: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80029D68: lh          $t6, 0x1A($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X1A);
    // 0x80029D6C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80029D70: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80029D74: beq         $at, $zero, L_80029E10
    if (ctx->r1 == 0) {
        // 0x80029D78: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80029E10;
    }
    // 0x80029D78: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80029D7C: lw          $v1, -0x49AC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X49AC);
    // 0x80029D80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80029D84: beq         $v1, $at, L_80029DB4
    if (ctx->r3 == ctx->r1) {
        // 0x80029D88: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80029DB4;
    }
    // 0x80029D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80029D8C: lw          $t7, 0x10($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X10);
    // 0x80029D90: sra         $t9, $a0, 3
    ctx->r25 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80029D94: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80029D98: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80029D9C: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x80029DA0: andi        $t2, $a0, 0x7
    ctx->r10 = ctx->r4 & 0X7;
    // 0x80029DA4: srlv        $v0, $v0, $t2
    ctx->r2 = S32(U32(ctx->r2) >> (ctx->r10 & 31));
    // 0x80029DA8: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x80029DAC: b           L_80029DB4
    // 0x80029DB0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_80029DB4;
    // 0x80029DB0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80029DB4:
    // 0x80029DB4: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x80029DB8: beq         $t4, $zero, L_80029E10
    if (ctx->r12 == 0) {
        // 0x80029DBC: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_80029E10;
    }
    // 0x80029DBC: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80029DC0: lw          $t5, 0x8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X8);
    // 0x80029DC4: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x80029DC8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80029DCC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80029DD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80029DD4: jal         0x8002A638
    // 0x80029DD8: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    block_visible(rdram, ctx);
        goto after_0;
    // 0x80029DD8: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_0:
    // 0x80029DDC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80029DE0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80029DE4: beq         $v0, $zero, L_80029E14
    if (ctx->r2 == 0) {
        // 0x80029DE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80029E14;
    }
    // 0x80029DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029DEC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80029DF0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80029DF4: nop

    // 0x80029DF8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80029DFC: sb          $a3, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r7;
    // 0x80029E00: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80029E04: nop

    // 0x80029E08: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80029E0C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
L_80029E10:
    // 0x80029E10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80029E14:
    // 0x80029E14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80029E18: jr          $ra
    // 0x80029E1C: nop

    return;
    // 0x80029E1C: nop

;}
RECOMP_FUNC void check_if_inside_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029E20: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80029E24: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x80029E28: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80029E2C: lh          $t6, 0x1A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1A);
    // 0x80029E30: nop

    // 0x80029E34: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80029E38: bne         $at, $zero, L_80029E48
    if (ctx->r1 != 0) {
        // 0x80029E3C: nop
    
            goto L_80029E48;
    }
    // 0x80029E3C: nop

    // 0x80029E40: jr          $ra
    // 0x80029E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80029E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80029E48:
    // 0x80029E48: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80029E4C: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80029E50: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80029E54: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029E58: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029E5C: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80029E60: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80029E64: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80029E68: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80029E6C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80029E70: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80029E74: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80029E78: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80029E7C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80029E80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029E84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029E88: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80029E8C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80029E90: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80029E94: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80029E98: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x80029E9C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80029EA0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80029EA4: addiu       $t4, $t3, 0x19
    ctx->r12 = ADD32(ctx->r11, 0X19);
    // 0x80029EA8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80029EAC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029EB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029EB4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80029EB8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80029EBC: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80029EC0: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80029EC4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80029EC8: beq         $at, $zero, L_80029F50
    if (ctx->r1 == 0) {
        // 0x80029ECC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80029F50;
    }
    // 0x80029ECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80029ED0: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80029ED4: nop

    // 0x80029ED8: addiu       $t6, $t5, -0x19
    ctx->r14 = ADD32(ctx->r13, -0X19);
    // 0x80029EDC: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80029EE0: beq         $at, $zero, L_80029F50
    if (ctx->r1 == 0) {
        // 0x80029EE4: nop
    
            goto L_80029F50;
    }
    // 0x80029EE4: nop

    // 0x80029EE8: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
    // 0x80029EEC: nop

    // 0x80029EF0: addiu       $t8, $t7, 0x19
    ctx->r24 = ADD32(ctx->r15, 0X19);
    // 0x80029EF4: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80029EF8: beq         $at, $zero, L_80029F50
    if (ctx->r1 == 0) {
        // 0x80029EFC: nop
    
            goto L_80029F50;
    }
    // 0x80029EFC: nop

    // 0x80029F00: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80029F04: nop

    // 0x80029F08: addiu       $t1, $t9, -0x19
    ctx->r9 = ADD32(ctx->r25, -0X19);
    // 0x80029F0C: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80029F10: beq         $at, $zero, L_80029F50
    if (ctx->r1 == 0) {
        // 0x80029F14: nop
    
            goto L_80029F50;
    }
    // 0x80029F14: nop

    // 0x80029F18: lh          $t2, 0x8($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X8);
    // 0x80029F1C: nop

    // 0x80029F20: addiu       $t3, $t2, 0x19
    ctx->r11 = ADD32(ctx->r10, 0X19);
    // 0x80029F24: slt         $at, $a3, $t3
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80029F28: beq         $at, $zero, L_80029F50
    if (ctx->r1 == 0) {
        // 0x80029F2C: nop
    
            goto L_80029F50;
    }
    // 0x80029F2C: nop

    // 0x80029F30: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x80029F34: nop

    // 0x80029F38: addiu       $t5, $t4, -0x19
    ctx->r13 = ADD32(ctx->r12, -0X19);
    // 0x80029F3C: slt         $at, $t5, $a3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80029F40: beq         $at, $zero, L_80029F50
    if (ctx->r1 == 0) {
        // 0x80029F44: nop
    
            goto L_80029F50;
    }
    // 0x80029F44: nop

    // 0x80029F48: jr          $ra
    // 0x80029F4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80029F4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80029F50:
    // 0x80029F50: jr          $ra
    // 0x80029F54: nop

    return;
    // 0x80029F54: nop

;}
RECOMP_FUNC void get_level_segment_index_from_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029F58: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80029F5C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80029F60: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x80029F64: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x80029F68: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80029F6C: bne         $v0, $zero, L_80029F7C
    if (ctx->r2 != 0) {
        // 0x80029F70: swc1        $f21, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
            goto L_80029F7C;
    }
    // 0x80029F70: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80029F74: b           L_8002A08C
    // 0x80029F78: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8002A08C;
    // 0x80029F78: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80029F7C:
    // 0x80029F7C: lh          $a3, 0x1A($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X1A);
    // 0x80029F80: lui         $a0, 0xF
    ctx->r4 = S32(0XF << 16);
    // 0x80029F84: ori         $a0, $a0, 0x4240
    ctx->r4 = ctx->r4 | 0X4240;
    // 0x80029F88: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80029F8C: blez        $a3, L_8002A088
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80029F90: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8002A088;
    }
    // 0x80029F90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80029F94: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80029F98: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80029F9C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80029FA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029FA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029FA8: nop

    // 0x80029FAC: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80029FB0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80029FB4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80029FB8: nop

L_80029FBC:
    // 0x80029FBC: lh          $t7, 0x6($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X6);
    // 0x80029FC0: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x80029FC4: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80029FC8: beq         $at, $zero, L_8002A078
    if (ctx->r1 == 0) {
        // 0x80029FCC: nop
    
            goto L_8002A078;
    }
    // 0x80029FCC: nop

    // 0x80029FD0: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x80029FD4: nop

    // 0x80029FD8: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029FDC: beq         $at, $zero, L_8002A078
    if (ctx->r1 == 0) {
        // 0x80029FE0: nop
    
            goto L_8002A078;
    }
    // 0x80029FE0: nop

    // 0x80029FE4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80029FE8: lh          $t2, 0xA($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XA);
    // 0x80029FEC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80029FF0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029FF4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029FF8: nop

    // 0x80029FFC: cvt.w.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.u32l = CVT_W_S(ctx->f20.fl);
    // 0x8002A000: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8002A004: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002A008: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8002A00C: beq         $at, $zero, L_8002A078
    if (ctx->r1 == 0) {
        // 0x8002A010: nop
    
            goto L_8002A078;
    }
    // 0x8002A010: nop

    // 0x8002A014: lh          $t3, 0x4($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X4);
    // 0x8002A018: nop

    // 0x8002A01C: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002A020: beq         $at, $zero, L_8002A078
    if (ctx->r1 == 0) {
        // 0x8002A024: nop
    
            goto L_8002A078;
    }
    // 0x8002A024: nop

    // 0x8002A028: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002A02C: lh          $t4, 0x8($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X8);
    // 0x8002A030: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002A034: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002A038: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002A03C: lh          $t5, 0x2($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X2);
    // 0x8002A040: cvt.w.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = CVT_W_S(ctx->f14.fl);
    // 0x8002A044: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8002A048: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8002A04C: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8002A050: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002A054: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x8002A058: bgez        $v0, L_8002A068
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002A05C: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8002A068;
    }
    // 0x8002A05C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002A060: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8002A064: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
L_8002A068:
    // 0x8002A068: beq         $at, $zero, L_8002A078
    if (ctx->r1 == 0) {
        // 0x8002A06C: nop
    
            goto L_8002A078;
    }
    // 0x8002A06C: nop

    // 0x8002A070: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002A074: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_8002A078:
    // 0x8002A078: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002A07C: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8002A080: bne         $at, $zero, L_80029FBC
    if (ctx->r1 != 0) {
        // 0x8002A084: addiu       $t1, $t1, 0xC
        ctx->r9 = ADD32(ctx->r9, 0XC);
            goto L_80029FBC;
    }
    // 0x8002A084: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
L_8002A088:
    // 0x8002A088: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8002A08C:
    // 0x8002A08C: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x8002A090: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8002A094: jr          $ra
    // 0x8002A098: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002A098: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void get_inside_segment_count_xz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A09C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002A0A0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8002A0A4: lw          $a3, -0x3178($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X3178);
    // 0x8002A0A8: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002A0AC: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002A0B0: lh          $t0, 0x1A($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X1A);
    // 0x8002A0B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002A0B8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8002A0BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002A0C0: blez        $t0, L_8002A160
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8002A0C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002A160;
    }
    // 0x8002A0C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002A0C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8002A0CC:
    // 0x8002A0CC: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
    // 0x8002A0D0: nop

    // 0x8002A0D4: addu        $a0, $t6, $a1
    ctx->r4 = ADD32(ctx->r14, ctx->r5);
    // 0x8002A0D8: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8002A0DC: nop

    // 0x8002A0E0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8002A0E4: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002A0E8: beq         $at, $zero, L_8002A150
    if (ctx->r1 == 0) {
        // 0x8002A0EC: nop
    
            goto L_8002A150;
    }
    // 0x8002A0EC: nop

    // 0x8002A0F0: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x8002A0F4: nop

    // 0x8002A0F8: addiu       $t1, $t9, -0x4
    ctx->r9 = ADD32(ctx->r25, -0X4);
    // 0x8002A0FC: slt         $at, $t1, $s0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002A100: beq         $at, $zero, L_8002A150
    if (ctx->r1 == 0) {
        // 0x8002A104: nop
    
            goto L_8002A150;
    }
    // 0x8002A104: nop

    // 0x8002A108: lh          $t2, 0xA($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XA);
    // 0x8002A10C: nop

    // 0x8002A110: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8002A114: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002A118: beq         $at, $zero, L_8002A150
    if (ctx->r1 == 0) {
        // 0x8002A11C: nop
    
            goto L_8002A150;
    }
    // 0x8002A11C: nop

    // 0x8002A120: lh          $t4, 0x4($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4);
    // 0x8002A124: nop

    // 0x8002A128: addiu       $t5, $t4, -0x4
    ctx->r13 = ADD32(ctx->r12, -0X4);
    // 0x8002A12C: slt         $at, $t5, $s1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8002A130: beq         $at, $zero, L_8002A150
    if (ctx->r1 == 0) {
        // 0x8002A134: nop
    
            goto L_8002A150;
    }
    // 0x8002A134: nop

    // 0x8002A138: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8002A13C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8002A140: lw          $a3, -0x3178($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X3178);
    // 0x8002A144: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002A148: lh          $t0, 0x1A($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X1A);
    // 0x8002A14C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8002A150:
    // 0x8002A150: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A154: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002A158: bne         $at, $zero, L_8002A0CC
    if (ctx->r1 != 0) {
        // 0x8002A15C: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8002A0CC;
    }
    // 0x8002A15C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_8002A160:
    // 0x8002A160: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002A164: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002A168: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8002A16C: jr          $ra
    // 0x8002A170: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8002A170: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void get_inside_segment_count_xyz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A178: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8002A17C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002A180: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002A184: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8002A188: lh          $s0, 0x2A($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X2A);
    // 0x8002A18C: lh          $s1, 0x2E($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X2E);
    // 0x8002A190: lh          $s2, 0x32($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X32);
    // 0x8002A194: lw          $t0, -0x3178($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3178);
    // 0x8002A198: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002A19C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002A1A0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8002A1A4: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002A1A8: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
    // 0x8002A1AC: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8002A1B0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8002A1B4: addiu       $a1, $t7, -0x4
    ctx->r5 = ADD32(ctx->r15, -0X4);
    // 0x8002A1B8: addiu       $a2, $t9, -0x4
    ctx->r6 = ADD32(ctx->r25, -0X4);
    // 0x8002A1BC: addiu       $a3, $t4, -0x4
    ctx->r7 = ADD32(ctx->r12, -0X4);
    // 0x8002A1C0: lh          $t1, 0x1A($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X1A);
    // 0x8002A1C4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8002A1C8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002A1CC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8002A1D0: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x8002A1D4: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8002A1D8: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x8002A1DC: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x8002A1E0: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x8002A1E4: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x8002A1E8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8002A1EC: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8002A1F0: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002A1F4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002A1F8: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8002A1FC: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002A200: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002A204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002A208: blez        $t1, L_8002A2C0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8002A20C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002A2C0;
    }
    // 0x8002A20C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002A210: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8002A214:
    // 0x8002A214: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x8002A218: nop

    // 0x8002A21C: addu        $a0, $t3, $t2
    ctx->r4 = ADD32(ctx->r11, ctx->r10);
    // 0x8002A220: lh          $t4, 0x6($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X6);
    // 0x8002A224: nop

    // 0x8002A228: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002A22C: bne         $at, $zero, L_8002A2B0
    if (ctx->r1 != 0) {
        // 0x8002A230: nop
    
            goto L_8002A2B0;
    }
    // 0x8002A230: nop

    // 0x8002A234: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x8002A238: nop

    // 0x8002A23C: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002A240: bne         $at, $zero, L_8002A2B0
    if (ctx->r1 != 0) {
        // 0x8002A244: nop
    
            goto L_8002A2B0;
    }
    // 0x8002A244: nop

    // 0x8002A248: lh          $t6, 0xA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XA);
    // 0x8002A24C: nop

    // 0x8002A250: slt         $at, $t6, $a3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8002A254: bne         $at, $zero, L_8002A2B0
    if (ctx->r1 != 0) {
        // 0x8002A258: nop
    
            goto L_8002A2B0;
    }
    // 0x8002A258: nop

    // 0x8002A25C: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x8002A260: nop

    // 0x8002A264: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002A268: bne         $at, $zero, L_8002A2B0
    if (ctx->r1 != 0) {
        // 0x8002A26C: nop
    
            goto L_8002A2B0;
    }
    // 0x8002A26C: nop

    // 0x8002A270: lh          $t8, 0x8($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8);
    // 0x8002A274: nop

    // 0x8002A278: slt         $at, $t8, $a2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002A27C: bne         $at, $zero, L_8002A2B0
    if (ctx->r1 != 0) {
        // 0x8002A280: nop
    
            goto L_8002A2B0;
    }
    // 0x8002A280: nop

    // 0x8002A284: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8002A288: nop

    // 0x8002A28C: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002A290: bne         $at, $zero, L_8002A2B0
    if (ctx->r1 != 0) {
        // 0x8002A294: nop
    
            goto L_8002A2B0;
    }
    // 0x8002A294: nop

    // 0x8002A298: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8002A29C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8002A2A0: lw          $t0, -0x3178($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3178);
    // 0x8002A2A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002A2A8: lh          $t1, 0x1A($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X1A);
    // 0x8002A2AC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8002A2B0:
    // 0x8002A2B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A2B4: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002A2B8: bne         $at, $zero, L_8002A214
    if (ctx->r1 != 0) {
        // 0x8002A2BC: addiu       $t2, $t2, 0xC
        ctx->r10 = ADD32(ctx->r10, 0XC);
            goto L_8002A214;
    }
    // 0x8002A2BC: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
L_8002A2C0:
    // 0x8002A2C0: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002A2C4: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002A2C8: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8002A2CC: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8002A2D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A2D4: jr          $ra
    // 0x8002A2D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8002A2D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void block_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A2DC: bltz        $a0, L_8002A300
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002A2E0: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8002A300;
    }
    // 0x8002A2E0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8002A2E4: lw          $v1, -0x3178($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3178);
    // 0x8002A2E8: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x8002A2EC: lh          $t6, 0x1A($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1A);
    // 0x8002A2F0: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8002A2F4: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002A2F8: beq         $at, $zero, L_8002A308
    if (ctx->r1 == 0) {
        // 0x8002A2FC: nop
    
            goto L_8002A308;
    }
    // 0x8002A2FC: nop

L_8002A300:
    // 0x8002A300: jr          $ra
    // 0x8002A304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002A304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A308:
    // 0x8002A308: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8002A30C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002A310: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002A314: jr          $ra
    // 0x8002A318: nop

    return;
    // 0x8002A318: nop

;}
RECOMP_FUNC void block_boundbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A31C: bltz        $a0, L_8002A340
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002A320: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8002A340;
    }
    // 0x8002A320: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8002A324: lw          $v1, -0x3178($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3178);
    // 0x8002A328: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8002A32C: lh          $t6, 0x1A($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1A);
    // 0x8002A330: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8002A334: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002A338: beq         $at, $zero, L_8002A348
    if (ctx->r1 == 0) {
        // 0x8002A33C: nop
    
            goto L_8002A348;
    }
    // 0x8002A33C: nop

L_8002A340:
    // 0x8002A340: jr          $ra
    // 0x8002A344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002A344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A348:
    // 0x8002A348: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8002A34C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002A350: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002A354: jr          $ra
    // 0x8002A358: nop

    return;
    // 0x8002A358: nop

;}
RECOMP_FUNC void func_8002A31C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A35C: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8002A360: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8002A364: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x8002A368: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8002A36C: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x8002A370: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x8002A374: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8002A378: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8002A37C: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8002A380: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8002A384: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8002A388: swc1        $f31, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8002A38C: swc1        $f30, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f30.u32l;
    // 0x8002A390: swc1        $f29, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002A394: swc1        $f28, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f28.u32l;
    // 0x8002A398: swc1        $f27, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002A39C: swc1        $f26, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f26.u32l;
    // 0x8002A3A0: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002A3A4: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x8002A3A8: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002A3AC: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x8002A3B0: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002A3B4: jal         0x80069FE4
    // 0x8002A3B8: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    get_projection_matrix_f32(rdram, ctx);
        goto after_0;
    // 0x8002A3B8: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8002A3BC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8002A3C0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002A3C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8002A3C8: addiu       $s1, $s1, -0x2988
    ctx->r17 = ADD32(ctx->r17, -0X2988);
    // 0x8002A3CC: addiu       $s0, $s0, -0x31E4
    ctx->r16 = ADD32(ctx->r16, -0X31E4);
    // 0x8002A3D0: addiu       $fp, $sp, 0xB8
    ctx->r30 = ADD32(ctx->r29, 0XB8);
    // 0x8002A3D4: addiu       $s7, $sp, 0xBC
    ctx->r23 = ADD32(ctx->r29, 0XBC);
    // 0x8002A3D8: addiu       $s6, $sp, 0xC0
    ctx->r22 = ADD32(ctx->r29, 0XC0);
    // 0x8002A3DC: addiu       $s5, $sp, 0xC4
    ctx->r21 = ADD32(ctx->r29, 0XC4);
    // 0x8002A3E0: addiu       $s4, $sp, 0xC8
    ctx->r20 = ADD32(ctx->r29, 0XC8);
    // 0x8002A3E4: addiu       $s3, $sp, 0xCC
    ctx->r19 = ADD32(ctx->r29, 0XCC);
L_8002A3E8:
    // 0x8002A3E8: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8002A3EC: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8002A3F0: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8002A3F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8002A3F8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8002A3FC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8002A400: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002A404: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8002A408: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x8002A40C: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x8002A410: swc1        $f0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f0.u32l;
    // 0x8002A414: swc1        $f2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f2.u32l;
    // 0x8002A418: jal         0x8006F88C
    // 0x8002A41C: swc1        $f12, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f12.u32l;
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x8002A41C: swc1        $f12, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8002A420: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8002A424: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8002A428: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002A42C: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8002A430: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8002A434: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8002A438: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002A43C: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x8002A440: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x8002A444: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x8002A448: swc1        $f14, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f14.u32l;
    // 0x8002A44C: swc1        $f16, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f16.u32l;
    // 0x8002A450: jal         0x8006F88C
    // 0x8002A454: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x8002A454: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8002A458: lwc1        $f26, 0x18($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8002A45C: lwc1        $f28, 0x1C($s0)
    ctx->f28.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8002A460: lwc1        $f30, 0x20($s0)
    ctx->f30.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8002A464: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x8002A468: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x8002A46C: addiu       $t8, $sp, 0xAC
    ctx->r24 = ADD32(ctx->r29, 0XAC);
    // 0x8002A470: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8002A474: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8002A478: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x8002A47C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8002A480: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8002A484: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002A488: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002A48C: swc1        $f26, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f26.u32l;
    // 0x8002A490: swc1        $f28, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f28.u32l;
    // 0x8002A494: jal         0x8006F88C
    // 0x8002A498: swc1        $f30, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f30.u32l;
    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x8002A498: swc1        $f30, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f30.u32l;
    after_3:
    // 0x8002A49C: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8002A4A0: lwc1        $f30, 0xAC($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8002A4A4: lwc1        $f2, 0xC8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8002A4A8: sub.s       $f4, $f18, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f30.fl;
    // 0x8002A4AC: lwc1        $f12, 0xC4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002A4B0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002A4B4: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002A4B8: lwc1        $f28, 0xB0($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8002A4BC: lwc1        $f14, 0xC0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8002A4C0: sub.s       $f8, $f30, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f30.fl - ctx->f12.fl;
    // 0x8002A4C4: lwc1        $f26, 0xB4($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8002A4C8: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8002A4CC: sub.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8002A4D0: lwc1        $f0, 0xCC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8002A4D4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8002A4D8: mul.s       $f6, $f28, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f8.fl);
    // 0x8002A4DC: sub.s       $f10, $f14, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f26.fl;
    // 0x8002A4E0: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8002A4E4: add.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002A4E8: sub.s       $f4, $f26, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x8002A4EC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002A4F0: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8002A4F4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002A4F8: mul.s       $f8, $f30, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f4.fl);
    // 0x8002A4FC: sub.s       $f6, $f16, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f28.fl;
    // 0x8002A500: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002A504: add.s       $f22, $f10, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002A508: sub.s       $f10, $f28, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f28.fl - ctx->f2.fl;
    // 0x8002A50C: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8002A510: sub.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8002A514: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002A518: mul.s       $f4, $f26, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f10.fl);
    // 0x8002A51C: nop

    // 0x8002A520: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8002A524: add.s       $f24, $f6, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002A528: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8002A52C: nop

    // 0x8002A530: mul.s       $f4, $f24, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8002A534: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002A538: jal         0x800CA030
    // 0x8002A53C: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x8002A53C: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_4:
    // 0x8002A540: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002A544: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002A548: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002A54C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8002A550: nop

    // 0x8002A554: div.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x8002A558: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8002A55C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002A560: lwc1        $f0, 0xCC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8002A564: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x8002A568: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8002A56C: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8002A570: nop

    // 0x8002A574: bc1f        L_8002A594
    if (!c1cs) {
        // 0x8002A578: nop
    
            goto L_8002A594;
    }
    // 0x8002A578: nop

    // 0x8002A57C: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8002A580: nop

    // 0x8002A584: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8002A588: nop

    // 0x8002A58C: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8002A590: nop

L_8002A594:
    // 0x8002A594: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8002A598: lwc1        $f2, 0xC8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8002A59C: lwc1        $f12, 0xC4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002A5A0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002A5A4: mul.s       $f6, $f2, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8002A5A8: addiu       $t9, $t9, -0x2958
    ctx->r25 = ADD32(ctx->r25, -0X2958);
    // 0x8002A5AC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8002A5B0: swc1        $f20, -0x10($s1)
    MEM_W(-0X10, ctx->r17) = ctx->f20.u32l;
    // 0x8002A5B4: mul.s       $f8, $f12, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x8002A5B8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002A5BC: swc1        $f22, -0xC($s1)
    MEM_W(-0XC, ctx->r17) = ctx->f22.u32l;
    // 0x8002A5C0: swc1        $f24, -0x8($s1)
    MEM_W(-0X8, ctx->r17) = ctx->f24.u32l;
    // 0x8002A5C4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002A5C8: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x8002A5CC: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8002A5D0: bne         $s1, $t9, L_8002A3E8
    if (ctx->r17 != ctx->r25) {
        // 0x8002A5D4: swc1        $f6, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f6.u32l;
            goto L_8002A3E8;
    }
    // 0x8002A5D4: swc1        $f6, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f6.u32l;
    // 0x8002A5D8: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8002A5DC: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002A5E0: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002A5E4: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002A5E8: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002A5EC: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002A5F0: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002A5F4: lwc1        $f27, 0x40($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002A5F8: lwc1        $f26, 0x44($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002A5FC: lwc1        $f29, 0x48($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x8002A600: lwc1        $f28, 0x4C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002A604: lwc1        $f31, 0x50($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x8002A608: lwc1        $f30, 0x54($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002A60C: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8002A610: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8002A614: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8002A618: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8002A61C: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8002A620: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8002A624: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x8002A628: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8002A62C: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x8002A630: jr          $ra
    // 0x8002A634: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x8002A634: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void block_visible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A638: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8002A63C: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8002A640: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8002A644: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002A648: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002A64C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002A650: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8002A654: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8002A658: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002A65C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x8002A660: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002A664: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x8002A668: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002A66C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8002A670: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002A674: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8002A678: addiu       $s3, $s3, -0x2988
    ctx->r19 = ADD32(ctx->r19, -0X2988);
L_8002A67C:
    // 0x8002A67C: lwc1        $f20, 0x0($s3)
    ctx->f20.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8002A680: lwc1        $f22, 0x4($s3)
    ctx->f22.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8002A684: lwc1        $f24, 0x8($s3)
    ctx->f24.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8002A688: lwc1        $f26, 0xC($s3)
    ctx->f26.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8002A68C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002A690: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002A694: andi        $t6, $s0, 0x1
    ctx->r14 = ctx->r16 & 0X1;
L_8002A698:
    // 0x8002A698: beq         $t6, $zero, L_8002A6CC
    if (ctx->r14 == 0) {
        // 0x8002A69C: nop
    
            goto L_8002A6CC;
    }
    // 0x8002A69C: nop

    // 0x8002A6A0: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8002A6A4: nop

    // 0x8002A6A8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8002A6AC: nop

    // 0x8002A6B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002A6B4: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8002A6B8: jal         0x800CA0AC
    // 0x8002A6BC: nop

    __f_to_ll_recomp(rdram, ctx);
        goto after_0;
    // 0x8002A6BC: nop

    after_0:
    // 0x8002A6C0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A6C4: b           L_8002A6F4
    // 0x8002A6C8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
        goto L_8002A6F4;
    // 0x8002A6C8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8002A6CC:
    // 0x8002A6CC: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8002A6D0: nop

    // 0x8002A6D4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8002A6D8: nop

    // 0x8002A6DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002A6E0: mul.s       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8002A6E4: jal         0x800CA0AC
    // 0x8002A6E8: nop

    __f_to_ll_recomp(rdram, ctx);
        goto after_1;
    // 0x8002A6E8: nop

    after_1:
    // 0x8002A6EC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A6F0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8002A6F4:
    // 0x8002A6F4: andi        $t9, $s0, 0x2
    ctx->r25 = ctx->r16 & 0X2;
    // 0x8002A6F8: beq         $t9, $zero, L_8002A740
    if (ctx->r25 == 0) {
        // 0x8002A6FC: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8002A740;
    }
    // 0x8002A6FC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A700: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A704: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A708: jal         0x800CA21C
    // 0x8002A70C: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_2;
    // 0x8002A70C: nop

    after_2:
    // 0x8002A710: lh          $t0, 0x2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2);
    // 0x8002A714: nop

    // 0x8002A718: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8002A71C: nop

    // 0x8002A720: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002A724: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8002A728: jal         0x800CA0AC
    // 0x8002A72C: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_3;
    // 0x8002A72C: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_3:
    // 0x8002A730: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A734: b           L_8002A774
    // 0x8002A738: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
        goto L_8002A774;
    // 0x8002A738: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8002A73C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8002A740:
    // 0x8002A740: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A744: jal         0x800CA21C
    // 0x8002A748: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_4;
    // 0x8002A748: nop

    after_4:
    // 0x8002A74C: lh          $t1, 0x8($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X8);
    // 0x8002A750: nop

    // 0x8002A754: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8002A758: nop

    // 0x8002A75C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002A760: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8002A764: jal         0x800CA0AC
    // 0x8002A768: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_5;
    // 0x8002A768: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    after_5:
    // 0x8002A76C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A770: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8002A774:
    // 0x8002A774: andi        $t2, $s0, 0x4
    ctx->r10 = ctx->r16 & 0X4;
    // 0x8002A778: beq         $t2, $zero, L_8002A7C0
    if (ctx->r10 == 0) {
        // 0x8002A77C: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8002A7C0;
    }
    // 0x8002A77C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A780: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A784: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A788: jal         0x800CA21C
    // 0x8002A78C: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_6;
    // 0x8002A78C: nop

    after_6:
    // 0x8002A790: lh          $t3, 0x4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X4);
    // 0x8002A794: nop

    // 0x8002A798: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8002A79C: nop

    // 0x8002A7A0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002A7A4: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8002A7A8: jal         0x800CA0AC
    // 0x8002A7AC: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_7;
    // 0x8002A7AC: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_7:
    // 0x8002A7B0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A7B4: b           L_8002A7F4
    // 0x8002A7B8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
        goto L_8002A7F4;
    // 0x8002A7B8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8002A7BC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8002A7C0:
    // 0x8002A7C0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A7C4: jal         0x800CA21C
    // 0x8002A7C8: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_8;
    // 0x8002A7C8: nop

    after_8:
    // 0x8002A7CC: lh          $t4, 0xA($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XA);
    // 0x8002A7D0: nop

    // 0x8002A7D4: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8002A7D8: nop

    // 0x8002A7DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002A7E0: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x8002A7E4: jal         0x800CA0AC
    // 0x8002A7E8: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_9;
    // 0x8002A7E8: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    after_9:
    // 0x8002A7EC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A7F0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8002A7F4:
    // 0x8002A7F4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A7F8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A7FC: jal         0x800CA21C
    // 0x8002A800: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_10;
    // 0x8002A800: nop

    after_10:
    // 0x8002A804: jal         0x800CA0AC
    // 0x8002A808: add.s       $f12, $f0, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f26.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_11;
    // 0x8002A808: add.s       $f12, $f0, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f26.fl;
    after_11:
    // 0x8002A80C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A810: bltz        $v0, L_8002A82C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8002A814: sw          $v1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r3;
            goto L_8002A82C;
    }
    // 0x8002A814: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8002A818: bgtz        $v0, L_8002A828
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002A81C: nop
    
            goto L_8002A828;
    }
    // 0x8002A81C: nop

    // 0x8002A820: beq         $v1, $zero, L_8002A82C
    if (ctx->r3 == 0) {
        // 0x8002A824: nop
    
            goto L_8002A82C;
    }
    // 0x8002A824: nop

L_8002A828:
    // 0x8002A828: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8002A82C:
    // 0x8002A82C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002A830: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8002A834: beq         $at, $zero, L_8002A848
    if (ctx->r1 == 0) {
        // 0x8002A838: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8002A848;
    }
    // 0x8002A838: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002A83C: beq         $s2, $zero, L_8002A698
    if (ctx->r18 == 0) {
        // 0x8002A840: andi        $t6, $s0, 0x1
        ctx->r14 = ctx->r16 & 0X1;
            goto L_8002A698;
    }
    // 0x8002A840: andi        $t6, $s0, 0x1
    ctx->r14 = ctx->r16 & 0X1;
    // 0x8002A844: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_8002A848:
    // 0x8002A848: bne         $s0, $at, L_8002A860
    if (ctx->r16 != ctx->r1) {
        // 0x8002A84C: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_8002A860;
    }
    // 0x8002A84C: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x8002A850: bne         $s2, $zero, L_8002A860
    if (ctx->r18 != 0) {
        // 0x8002A854: nop
    
            goto L_8002A860;
    }
    // 0x8002A854: nop

    // 0x8002A858: b           L_8002A904
    // 0x8002A85C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002A904;
    // 0x8002A85C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A860:
    // 0x8002A860: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002A864: addiu       $t5, $t5, -0x2958
    ctx->r13 = ADD32(ctx->r13, -0X2958);
    // 0x8002A868: bne         $s3, $t5, L_8002A67C
    if (ctx->r19 != ctx->r13) {
        // 0x8002A86C: nop
    
            goto L_8002A67C;
    }
    // 0x8002A86C: nop

    // 0x8002A870: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8002A874: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x8002A878: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x8002A87C: lh          $t5, 0x4($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X4);
    // 0x8002A880: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8002A884: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x8002A888: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8002A88C: lh          $t2, 0x8($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X8);
    // 0x8002A890: lh          $t3, 0x2($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X2);
    // 0x8002A894: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8002A898: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8002A89C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002A8A0: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8002A8A4: sra         $t6, $t4, 1
    ctx->r14 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8002A8A8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8002A8AC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8002A8B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002A8B4: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002A8B8: jal         0x80066588
    // 0x8002A8BC: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    get_distance_to_active_camera(rdram, ctx);
        goto after_12;
    // 0x8002A8BC: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_12:
    // 0x8002A8C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002A8C4: addiu       $v0, $v0, -0x2700
    ctx->r2 = ADD32(ctx->r2, -0X2700);
    // 0x8002A8C8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8002A8CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002A8D0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002A8D4: lwc1        $f11, 0x6438($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6438);
    // 0x8002A8D8: lwc1        $f10, 0x643C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X643C);
    // 0x8002A8DC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002A8E0: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8002A8E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002A8E8: bc1f        L_8002A900
    if (!c1cs) {
        // 0x8002A8EC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002A900;
    }
    // 0x8002A8EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A8F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002A8F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002A8F8: b           L_8002A904
    // 0x8002A8FC: sw          $t0, -0x49C4($at)
    MEM_W(-0X49C4, ctx->r1) = ctx->r8;
        goto L_8002A904;
    // 0x8002A8FC: sw          $t0, -0x49C4($at)
    MEM_W(-0X49C4, ctx->r1) = ctx->r8;
L_8002A900:
    // 0x8002A900: sw          $zero, -0x49C4($at)
    MEM_W(-0X49C4, ctx->r1) = 0;
L_8002A904:
    // 0x8002A904: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002A908: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8002A90C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8002A910: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002A914: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002A918: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002A91C: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002A920: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002A924: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002A928: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8002A92C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8002A930: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8002A934: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8002A938: jr          $ra
    // 0x8002A93C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8002A93C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void check_if_in_draw_range(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A940: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002A944: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002A948: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002A94C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x8002A950: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002A954: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x8002A958: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002A95C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8002A960: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002A964: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8002A968: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8002A96C: nop

    // 0x8002A970: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8002A974: bne         $t7, $zero, L_8002AC14
    if (ctx->r15 != 0) {
        // 0x8002A978: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002AC14;
    }
    // 0x8002A978: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A97C: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x8002A980: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8002A984: lh          $v1, 0x4E($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X4E);
    // 0x8002A988: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002A98C: beq         $v1, $zero, L_8002AB00
    if (ctx->r3 == 0) {
        // 0x8002A990: nop
    
            goto L_8002AB00;
    }
    // 0x8002A990: nop

    // 0x8002A994: lw          $t9, -0x2704($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2704);
    // 0x8002A998: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002A99C: bne         $t9, $at, L_8002A9E8
    if (ctx->r25 != ctx->r1) {
        // 0x8002A9A0: nop
    
            goto L_8002A9E8;
    }
    // 0x8002A9A0: nop

    // 0x8002A9A4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8002A9A8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002A9AC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8002A9B0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002A9B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002A9B8: nop

    // 0x8002A9BC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8002A9C0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8002A9C4: nop

    // 0x8002A9C8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8002A9CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002A9D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002A9D4: nop

    // 0x8002A9D8: cvt.w.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_D(ctx->f10.d);
    // 0x8002A9DC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8002A9E0: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8002A9E4: nop

L_8002A9E8:
    // 0x8002A9E8: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002A9EC: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002A9F0: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x8002A9F4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8002A9F8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8002A9FC: jal         0x80066588
    // 0x8002AA00: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    get_distance_to_active_camera(rdram, ctx);
        goto after_0;
    // 0x8002AA00: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002AA04: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8002AA08: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8002AA0C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8002AA10: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8002AA14: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002AA18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002AA1C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8002AA20: nop

    // 0x8002AA24: bc1f        L_8002AA34
    if (!c1cs) {
        // 0x8002AA28: nop
    
            goto L_8002AA34;
    }
    // 0x8002AA28: nop

    // 0x8002AA2C: b           L_8002AC14
    // 0x8002AA30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002AC14;
    // 0x8002AA30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002AA34:
    // 0x8002AA34: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8002AA38: lwc1        $f5, 0x6440($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6440);
    // 0x8002AA3C: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8002AA40: lwc1        $f4, 0x6444($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6444);
    // 0x8002AA44: nop

    // 0x8002AA48: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8002AA4C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x8002AA50: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002AA54: nop

    // 0x8002AA58: bc1f        L_8002AB00
    if (!c1cs) {
        // 0x8002AA5C: nop
    
            goto L_8002AB00;
    }
    // 0x8002AA5C: nop

    // 0x8002AA60: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8002AA64: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8002AA68: nop

    // 0x8002AA6C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8002AA70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002AA74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002AA78: nop

    // 0x8002AA7C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002AA80: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8002AA84: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8002AA88: blez        $v1, L_8002AAF4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002AA8C: nop
    
            goto L_8002AAF4;
    }
    // 0x8002AA8C: nop

    // 0x8002AA90: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8002AA94: sub.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002AA98: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002AA9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002AAA0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002AAA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002AAA8: div.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8002AAAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002AAB0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AAB4: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8002AAB8: lwc1        $f6, 0x644C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X644C);
    // 0x8002AABC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002AAC0: lwc1        $f7, 0x6448($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6448);
    // 0x8002AAC4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AAC8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8002AACC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002AAD0: nop

    // 0x8002AAD4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8002AAD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002AADC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002AAE0: nop

    // 0x8002AAE4: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x8002AAE8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002AAEC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002AAF0: nop

L_8002AAF4:
    // 0x8002AAF4: bne         $a1, $zero, L_8002AB00
    if (ctx->r5 != 0) {
        // 0x8002AAF8: nop
    
            goto L_8002AB00;
    }
    // 0x8002AAF8: nop

    // 0x8002AAFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8002AB00:
    // 0x8002AB00: lh          $v0, 0x48($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X48);
    // 0x8002AB04: nop

    // 0x8002AB08: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8002AB0C: bne         $at, $zero, L_8002AB38
    if (ctx->r1 != 0) {
        // 0x8002AB10: addiu       $t3, $v0, -0x32
        ctx->r11 = ADD32(ctx->r2, -0X32);
            goto L_8002AB38;
    }
    // 0x8002AB10: addiu       $t3, $v0, -0x32
    ctx->r11 = ADD32(ctx->r2, -0X32);
    // 0x8002AB14: sltiu       $at, $t3, 0x20
    ctx->r1 = ctx->r11 < 0X20 ? 1 : 0;
    // 0x8002AB18: beq         $at, $zero, L_8002AB94
    if (ctx->r1 == 0) {
        // 0x8002AB1C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_8002AB94;
    }
    // 0x8002AB1C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002AB20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002AB24: addu        $at, $at, $t3
    gpr jr_addend_8002AB30 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8002AB28: lw          $t3, 0x6450($at)
    ctx->r11 = ADD32(ctx->r1, 0X6450);
    // 0x8002AB2C: nop

    // 0x8002AB30: jr          $t3
    // 0x8002AB34: nop

    switch (jr_addend_8002AB30 >> 2) {
        case 0: goto L_8002AB80; break;
        case 1: goto L_8002AB80; break;
        case 2: goto L_8002AB94; break;
        case 3: goto L_8002AB80; break;
        case 4: goto L_8002AB80; break;
        case 5: goto L_8002AB94; break;
        case 6: goto L_8002AB80; break;
        case 7: goto L_8002AB94; break;
        case 8: goto L_8002AB6C; break;
        case 9: goto L_8002AB94; break;
        case 10: goto L_8002AB94; break;
        case 11: goto L_8002AB94; break;
        case 12: goto L_8002AB98; break;
        case 13: goto L_8002AB94; break;
        case 14: goto L_8002AB94; break;
        case 15: goto L_8002AB94; break;
        case 16: goto L_8002AB94; break;
        case 17: goto L_8002AB94; break;
        case 18: goto L_8002AB94; break;
        case 19: goto L_8002AB94; break;
        case 20: goto L_8002AB80; break;
        case 21: goto L_8002AB94; break;
        case 22: goto L_8002AB80; break;
        case 23: goto L_8002AB94; break;
        case 24: goto L_8002AB94; break;
        case 25: goto L_8002AB94; break;
        case 26: goto L_8002AB94; break;
        case 27: goto L_8002AB98; break;
        case 28: goto L_8002AB94; break;
        case 29: goto L_8002AB94; break;
        case 30: goto L_8002AB98; break;
        case 31: goto L_8002AB80; break;
        default: switch_error(__func__, 0x8002AB30, 0x800E6450);
    }
    // 0x8002AB34: nop

L_8002AB38:
    // 0x8002AB38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AB3C: bne         $v0, $at, L_8002AB94
    if (ctx->r2 != ctx->r1) {
        // 0x8002AB40: nop
    
            goto L_8002AB94;
    }
    // 0x8002AB40: nop

    // 0x8002AB44: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8002AB48: nop

    // 0x8002AB4C: lbu         $t4, 0x1F7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1F7);
    // 0x8002AB50: nop

    // 0x8002AB54: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8002AB58: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002AB5C: mflo        $t6
    ctx->r14 = lo;
    // 0x8002AB60: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8002AB64: b           L_8002AB98
    // 0x8002AB68: sb          $t7, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r15;
        goto L_8002AB98;
    // 0x8002AB68: sb          $t7, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r15;
L_8002AB6C:
    // 0x8002AB6C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8002AB70: nop

    // 0x8002AB74: lbu         $t8, 0x1F7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1F7);
    // 0x8002AB78: b           L_8002AB98
    // 0x8002AB7C: sb          $t8, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r24;
        goto L_8002AB98;
    // 0x8002AB7C: sb          $t8, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r24;
L_8002AB80:
    // 0x8002AB80: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8002AB84: nop

    // 0x8002AB88: lbu         $t9, 0x42($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X42);
    // 0x8002AB8C: b           L_8002AB98
    // 0x8002AB90: sb          $t9, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r25;
        goto L_8002AB98;
    // 0x8002AB90: sb          $t9, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r25;
L_8002AB94:
    // 0x8002AB94: sb          $a1, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r5;
L_8002AB98:
    // 0x8002AB98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002AB9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002ABA0: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002ABA4: lwc1        $f20, 0x10($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002ABA8: lwc1        $f22, 0x14($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002ABAC: lwc1        $f24, 0x34($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8002ABB0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8002ABB4: addiu       $v1, $v1, -0x2958
    ctx->r3 = ADD32(ctx->r3, -0X2958);
    // 0x8002ABB8: addiu       $v0, $v0, -0x2988
    ctx->r2 = ADD32(ctx->r2, -0X2988);
L_8002ABBC:
    // 0x8002ABBC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002ABC0: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002ABC4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8002ABC8: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002ABCC: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002ABD0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002ABD4: mul.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8002ABD8: nop

    // 0x8002ABDC: mul.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8002ABE0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002ABE4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002ABE8: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8002ABEC: add.s       $f16, $f6, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8002ABF0: c.lt.s      $f16, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f16.fl < ctx->f26.fl;
    // 0x8002ABF4: nop

    // 0x8002ABF8: bc1f        L_8002AC08
    if (!c1cs) {
        // 0x8002ABFC: nop
    
            goto L_8002AC08;
    }
    // 0x8002ABFC: nop

    // 0x8002AC00: b           L_8002AC14
    // 0x8002AC04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002AC14;
    // 0x8002AC04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002AC08:
    // 0x8002AC08: bne         $v0, $v1, L_8002ABBC
    if (ctx->r2 != ctx->r3) {
        // 0x8002AC0C: nop
    
            goto L_8002ABBC;
    }
    // 0x8002AC0C: nop

    // 0x8002AC10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002AC14:
    // 0x8002AC14: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002AC18: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8002AC1C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8002AC20: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002AC24: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002AC28: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002AC2C: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002AC30: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002AC34: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002AC38: jr          $ra
    // 0x8002AC3C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8002AC3C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8002AC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AC40: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8002AC44: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x8002AC48: nop

    // 0x8002AC4C: lh          $v1, 0x1A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X1A);
    // 0x8002AC50: nop

    // 0x8002AC54: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002AC58: beq         $at, $zero, L_8002ACD8
    if (ctx->r1 == 0) {
        // 0x8002AC5C: slt         $at, $a1, $v1
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8002ACD8;
    }
    // 0x8002AC5C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002AC60: beq         $at, $zero, L_8002ACD8
    if (ctx->r1 == 0) {
        // 0x8002AC64: sll         $t7, $a0, 4
        ctx->r15 = S32(ctx->r4 << 4);
            goto L_8002ACD8;
    }
    // 0x8002AC64: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x8002AC68: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8002AC6C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8002AC70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002AC74: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002AC78: lh          $v1, 0x28($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X28);
    // 0x8002AC7C: beq         $a2, $zero, L_8002ACB0
    if (ctx->r6 == 0) {
        // 0x8002AC80: sra         $t0, $a1, 3
        ctx->r8 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8002ACB0;
    }
    // 0x8002AC80: sra         $t0, $a1, 3
    ctx->r8 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8002AC84: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x8002AC88: sra         $t1, $a1, 3
    ctx->r9 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8002AC8C: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x8002AC90: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x8002AC94: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x8002AC98: andi        $t3, $a1, 0x7
    ctx->r11 = ctx->r5 & 0X7;
    // 0x8002AC9C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8002ACA0: sllv        $t6, $t4, $t3
    ctx->r14 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x8002ACA4: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x8002ACA8: jr          $ra
    // 0x8002ACAC: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x8002ACAC: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_8002ACB0:
    // 0x8002ACB0: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8002ACB4: andi        $t4, $a1, 0x7
    ctx->r12 = ctx->r5 & 0X7;
    // 0x8002ACB8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8002ACBC: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x8002ACC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002ACC4: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x8002ACC8: sllv        $t2, $t3, $t4
    ctx->r10 = S32(ctx->r11 << (ctx->r12 & 31));
    // 0x8002ACCC: nor         $t6, $t2, $zero
    ctx->r14 = ~(ctx->r10 | 0);
    // 0x8002ACD0: and         $t7, $t1, $t6
    ctx->r15 = ctx->r9 & ctx->r14;
    // 0x8002ACD4: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_8002ACD8:
    // 0x8002ACD8: jr          $ra
    // 0x8002ACDC: nop

    return;
    // 0x8002ACDC: nop

;}
RECOMP_FUNC void get_collision_candidate_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ACE0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002ACE4: lw          $t6, -0x2708($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2708);
    // 0x8002ACE8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002ACEC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8002ACF0: lw          $t7, -0x2710($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2710);
    // 0x8002ACF4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002ACF8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8002ACFC: lw          $t8, -0x270C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X270C);
    // 0x8002AD00: jr          $ra
    // 0x8002AD04: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    return;
    // 0x8002AD04: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
;}
RECOMP_FUNC void set_collision_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002AD0C: jr          $ra
    // 0x8002AD10: sw          $a0, -0x498C($at)
    MEM_W(-0X498C, ctx->r1) = ctx->r4;
    return;
    // 0x8002AD10: sw          $a0, -0x498C($at)
    MEM_W(-0X498C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void get_collision_normal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002AD18: lwc1        $f4, -0x499C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X499C);
    // 0x8002AD1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002AD20: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8002AD24: lwc1        $f6, -0x4998($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4998);
    // 0x8002AD28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002AD2C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8002AD30: lwc1        $f8, -0x4994($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4994);
    // 0x8002AD34: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002AD38: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x8002AD3C: lw          $v0, -0x4990($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4990);
    // 0x8002AD40: jr          $ra
    // 0x8002AD44: nop

    return;
    // 0x8002AD44: nop

;}
RECOMP_FUNC void get_wave_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD48: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002AD4C: lb          $v0, -0x2778($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2778);
    // 0x8002AD50: beq         $a2, $zero, L_8002AD70
    if (ctx->r6 == 0) {
        // 0x8002AD54: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002AD70;
    }
    // 0x8002AD54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002AD58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002AD5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002AD60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002AD64: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8002AD68: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8002AD6C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
L_8002AD70:
    // 0x8002AD70: blez        $v0, L_8002AE84
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002AD74: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8002AE84;
    }
    // 0x8002AD74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002AD78: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // 0x8002AD7C: beq         $t1, $zero, L_8002ADCC
    if (ctx->r9 == 0) {
        // 0x8002AD80: or          $a3, $t1, $zero
        ctx->r7 = ctx->r9 | 0;
            goto L_8002ADCC;
    }
    // 0x8002AD80: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8002AD84: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002AD88: addiu       $t7, $t7, -0x27C8
    ctx->r15 = ADD32(ctx->r15, -0X27C8);
    // 0x8002AD8C: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8002AD90: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x8002AD94: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x8002AD98: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
L_8002AD9C:
    // 0x8002AD9C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8002ADA0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002ADA4: lb          $t2, 0x10($t8)
    ctx->r10 = MEM_B(ctx->r24, 0X10);
    // 0x8002ADA8: nop

    // 0x8002ADAC: beq         $t3, $t2, L_8002ADBC
    if (ctx->r11 == ctx->r10) {
        // 0x8002ADB0: nop
    
            goto L_8002ADBC;
    }
    // 0x8002ADB0: nop

    // 0x8002ADB4: bne         $t4, $t2, L_8002ADC0
    if (ctx->r12 != ctx->r10) {
        // 0x8002ADB8: nop
    
            goto L_8002ADC0;
    }
    // 0x8002ADB8: nop

L_8002ADBC:
    // 0x8002ADBC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002ADC0:
    // 0x8002ADC0: bne         $a3, $v1, L_8002AD9C
    if (ctx->r7 != ctx->r3) {
        // 0x8002ADC4: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8002AD9C;
    }
    // 0x8002ADC4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8002ADC8: beq         $v1, $v0, L_8002AE84
    if (ctx->r3 == ctx->r2) {
        // 0x8002ADCC: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8002AE84;
    }
L_8002ADCC:
    // 0x8002ADCC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002ADD0: addiu       $t5, $t5, -0x27C8
    ctx->r13 = ADD32(ctx->r13, -0X27C8);
    // 0x8002ADD4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8002ADD8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8002ADDC: addu        $t0, $t6, $t5
    ctx->r8 = ADD32(ctx->r14, ctx->r13);
    // 0x8002ADE0: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    // 0x8002ADE4: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8002ADE8: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
L_8002ADEC:
    // 0x8002ADEC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8002ADF0: nop

    // 0x8002ADF4: lb          $t2, 0x10($t7)
    ctx->r10 = MEM_B(ctx->r15, 0X10);
    // 0x8002ADF8: nop

    // 0x8002ADFC: beq         $t3, $t2, L_8002AE0C
    if (ctx->r11 == ctx->r10) {
        // 0x8002AE00: nop
    
            goto L_8002AE0C;
    }
    // 0x8002AE00: nop

    // 0x8002AE04: bne         $t4, $t2, L_8002AE10
    if (ctx->r12 != ctx->r10) {
        // 0x8002AE08: nop
    
            goto L_8002AE10;
    }
    // 0x8002AE08: nop

L_8002AE0C:
    // 0x8002AE0C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002AE10:
    // 0x8002AE10: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x8002AE14: nop

    // 0x8002AE18: lb          $t2, 0x10($t8)
    ctx->r10 = MEM_B(ctx->r24, 0X10);
    // 0x8002AE1C: nop

    // 0x8002AE20: beq         $t3, $t2, L_8002AE30
    if (ctx->r11 == ctx->r10) {
        // 0x8002AE24: nop
    
            goto L_8002AE30;
    }
    // 0x8002AE24: nop

    // 0x8002AE28: bne         $t4, $t2, L_8002AE34
    if (ctx->r12 != ctx->r10) {
        // 0x8002AE2C: nop
    
            goto L_8002AE34;
    }
    // 0x8002AE2C: nop

L_8002AE30:
    // 0x8002AE30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002AE34:
    // 0x8002AE34: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x8002AE38: nop

    // 0x8002AE3C: lb          $v1, 0x10($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X10);
    // 0x8002AE40: nop

    // 0x8002AE44: beq         $t3, $v1, L_8002AE54
    if (ctx->r11 == ctx->r3) {
        // 0x8002AE48: nop
    
            goto L_8002AE54;
    }
    // 0x8002AE48: nop

    // 0x8002AE4C: bne         $t4, $v1, L_8002AE58
    if (ctx->r12 != ctx->r3) {
        // 0x8002AE50: nop
    
            goto L_8002AE58;
    }
    // 0x8002AE50: nop

L_8002AE54:
    // 0x8002AE54: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002AE58:
    // 0x8002AE58: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x8002AE5C: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8002AE60: lb          $v1, 0x10($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X10);
    // 0x8002AE64: nop

    // 0x8002AE68: beq         $t3, $v1, L_8002AE78
    if (ctx->r11 == ctx->r3) {
        // 0x8002AE6C: nop
    
            goto L_8002AE78;
    }
    // 0x8002AE6C: nop

    // 0x8002AE70: bne         $t4, $v1, L_8002AE7C
    if (ctx->r12 != ctx->r3) {
        // 0x8002AE74: nop
    
            goto L_8002AE7C;
    }
    // 0x8002AE74: nop

L_8002AE78:
    // 0x8002AE78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002AE7C:
    // 0x8002AE7C: bne         $t0, $a3, L_8002ADEC
    if (ctx->r8 != ctx->r7) {
        // 0x8002AE80: nop
    
            goto L_8002ADEC;
    }
    // 0x8002AE80: nop

L_8002AE84:
    // 0x8002AE84: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8002AE88: bne         $a0, $zero, L_8002AE98
    if (ctx->r4 != 0) {
        // 0x8002AE8C: addiu       $t4, $zero, 0xE
        ctx->r12 = ADD32(0, 0XE);
            goto L_8002AE98;
    }
    // 0x8002AE8C: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x8002AE90: jr          $ra
    // 0x8002AE94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002AE94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002AE98:
    // 0x8002AE98: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8002AE9C: blez        $v0, L_8002B0B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002AEA0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002B0B0;
    }
    // 0x8002AEA0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002AEA4: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x8002AEA8: beq         $t0, $zero, L_8002AF34
    if (ctx->r8 == 0) {
        // 0x8002AEAC: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8002AF34;
    }
    // 0x8002AEAC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002AEB0: lw          $t5, -0x27C8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X27C8);
    // 0x8002AEB4: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x8002AEB8: lb          $v1, 0x10($t5)
    ctx->r3 = MEM_B(ctx->r13, 0X10);
    // 0x8002AEBC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002AEC0: beq         $t3, $v1, L_8002AED0
    if (ctx->r11 == ctx->r3) {
        // 0x8002AEC4: nop
    
            goto L_8002AED0;
    }
    // 0x8002AEC4: nop

    // 0x8002AEC8: bne         $t4, $v1, L_8002AF30
    if (ctx->r12 != ctx->r3) {
        // 0x8002AECC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002AF30;
    }
    // 0x8002AECC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002AED0:
    // 0x8002AED0: lw          $t7, -0x27C8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X27C8);
    // 0x8002AED4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8002AED8: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002AEDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002AEE0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002AEE4: add.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d + ctx->f2.d;
    // 0x8002AEE8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002AEEC: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8002AEF0: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x8002AEF4: nop

    // 0x8002AEF8: bc1f        L_8002AF30
    if (!c1cs) {
        // 0x8002AEFC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002AF30;
    }
    // 0x8002AEFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002AF00: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8002AF04: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002AF08: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AF0C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8002AF10: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x8002AF14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AF18: bc1t        L_8002AF28
    if (c1cs) {
        // 0x8002AF1C: nop
    
            goto L_8002AF28;
    }
    // 0x8002AF1C: nop

    // 0x8002AF20: bne         $a0, $at, L_8002AF30
    if (ctx->r4 != ctx->r1) {
        // 0x8002AF24: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002AF30;
    }
    // 0x8002AF24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002AF28:
    // 0x8002AF28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002AF2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002AF30:
    // 0x8002AF30: beq         $v1, $v0, L_8002B0B0
    if (ctx->r3 == ctx->r2) {
        // 0x8002AF34: lui         $at, 0x4039
        ctx->r1 = S32(0X4039 << 16);
            goto L_8002B0B0;
    }
L_8002AF34:
    // 0x8002AF34: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x8002AF38: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8002AF3C: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8002AF40: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002AF44: addiu       $t9, $t9, -0x27C8
    ctx->r25 = ADD32(ctx->r25, -0X27C8);
    // 0x8002AF48: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8002AF4C: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8002AF50: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002AF54: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8002AF58: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
L_8002AF5C:
    // 0x8002AF5C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8002AF60: nop

    // 0x8002AF64: lb          $t2, 0x10($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X10);
    // 0x8002AF68: nop

    // 0x8002AF6C: beq         $t3, $t2, L_8002AF7C
    if (ctx->r11 == ctx->r10) {
        // 0x8002AF70: nop
    
            goto L_8002AF7C;
    }
    // 0x8002AF70: nop

    // 0x8002AF74: bne         $t4, $t2, L_8002AFD0
    if (ctx->r12 != ctx->r10) {
        // 0x8002AF78: nop
    
            goto L_8002AFD0;
    }
    // 0x8002AF78: nop

L_8002AF7C:
    // 0x8002AF7C: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8002AF80: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x8002AF84: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8002AF88: add.d       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f16.d + ctx->f2.d;
    // 0x8002AF8C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002AF90: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8002AF94: nop

    // 0x8002AF98: bc1f        L_8002B004
    if (!c1cs) {
        // 0x8002AF9C: nop
    
            goto L_8002B004;
    }
    // 0x8002AF9C: nop

    // 0x8002AFA0: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8002AFA4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002AFA8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AFAC: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8002AFB0: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x8002AFB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AFB8: bc1t        L_8002AFC8
    if (c1cs) {
        // 0x8002AFBC: nop
    
            goto L_8002AFC8;
    }
    // 0x8002AFBC: nop

    // 0x8002AFC0: bne         $a0, $at, L_8002B004
    if (ctx->r4 != ctx->r1) {
        // 0x8002AFC4: nop
    
            goto L_8002B004;
    }
    // 0x8002AFC4: nop

L_8002AFC8:
    // 0x8002AFC8: b           L_8002B004
    // 0x8002AFCC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8002B004;
    // 0x8002AFCC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_8002AFD0:
    // 0x8002AFD0: bltz        $a3, L_8002B004
    if (SIGNED(ctx->r7) < 0) {
        // 0x8002AFD4: slti        $at, $a0, 0x2
        ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8002B004;
    }
    // 0x8002AFD4: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002AFD8: bne         $at, $zero, L_8002B004
    if (ctx->r1 != 0) {
        // 0x8002AFDC: nop
    
            goto L_8002B004;
    }
    // 0x8002AFDC: nop

    // 0x8002AFE0: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8002AFE4: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x8002AFE8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AFEC: sub.d       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f4.d - ctx->f14.d;
    // 0x8002AFF0: c.lt.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d < ctx->f8.d;
    // 0x8002AFF4: nop

    // 0x8002AFF8: bc1f        L_8002B004
    if (!c1cs) {
        // 0x8002AFFC: nop
    
            goto L_8002B004;
    }
    // 0x8002AFFC: nop

    // 0x8002B000: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8002B004:
    // 0x8002B004: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8002B008: nop

    // 0x8002B00C: lb          $t2, 0x10($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X10);
    // 0x8002B010: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8002B014: beq         $t3, $t2, L_8002B024
    if (ctx->r11 == ctx->r10) {
        // 0x8002B018: nop
    
            goto L_8002B024;
    }
    // 0x8002B018: nop

    // 0x8002B01C: bne         $t4, $t2, L_8002B074
    if (ctx->r12 != ctx->r10) {
        // 0x8002B020: nop
    
            goto L_8002B074;
    }
    // 0x8002B020: nop

L_8002B024:
    // 0x8002B024: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B028: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x8002B02C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002B030: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x8002B034: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8002B038: nop

    // 0x8002B03C: bc1f        L_8002B0A4
    if (!c1cs) {
        // 0x8002B040: nop
    
            goto L_8002B0A4;
    }
    // 0x8002B040: nop

    // 0x8002B044: lwc1        $f16, 0x8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8002B048: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002B04C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002B050: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002B054: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8002B058: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002B05C: bc1t        L_8002B06C
    if (c1cs) {
        // 0x8002B060: nop
    
            goto L_8002B06C;
    }
    // 0x8002B060: nop

    // 0x8002B064: bne         $a0, $at, L_8002B0A4
    if (ctx->r4 != ctx->r1) {
        // 0x8002B068: nop
    
            goto L_8002B0A4;
    }
    // 0x8002B068: nop

L_8002B06C:
    // 0x8002B06C: b           L_8002B0A4
    // 0x8002B070: addiu       $a3, $v1, 0x1
    ctx->r7 = ADD32(ctx->r3, 0X1);
        goto L_8002B0A4;
    // 0x8002B070: addiu       $a3, $v1, 0x1
    ctx->r7 = ADD32(ctx->r3, 0X1);
L_8002B074:
    // 0x8002B074: bltz        $a3, L_8002B0A4
    if (SIGNED(ctx->r7) < 0) {
        // 0x8002B078: slti        $at, $a0, 0x2
        ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8002B0A4;
    }
    // 0x8002B078: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002B07C: bne         $at, $zero, L_8002B0A4
    if (ctx->r1 != 0) {
        // 0x8002B080: nop
    
            goto L_8002B0A4;
    }
    // 0x8002B080: nop

    // 0x8002B084: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B088: sub.d       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f18.d - ctx->f14.d;
    // 0x8002B08C: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8002B090: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8002B094: nop

    // 0x8002B098: bc1f        L_8002B0A4
    if (!c1cs) {
        // 0x8002B09C: nop
    
            goto L_8002B0A4;
    }
    // 0x8002B09C: nop

    // 0x8002B0A0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8002B0A4:
    // 0x8002B0A4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8002B0A8: bne         $v1, $v0, L_8002AF5C
    if (ctx->r3 != ctx->r2) {
        // 0x8002B0AC: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_8002AF5C;
    }
    // 0x8002B0AC: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_8002B0B0:
    // 0x8002B0B0: bgez        $a3, L_8002B0C0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8002B0B4: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_8002B0C0;
    }
    // 0x8002B0B4: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8002B0B8: jr          $ra
    // 0x8002B0BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002B0BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002B0C0:
    // 0x8002B0C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002B0C4: addiu       $t5, $t5, -0x27C8
    ctx->r13 = ADD32(ctx->r13, -0X27C8);
    // 0x8002B0C8: addu        $v1, $t6, $t5
    ctx->r3 = ADD32(ctx->r14, ctx->r13);
    // 0x8002B0CC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0D0: nop

    // 0x8002B0D4: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002B0D8: beq         $a2, $zero, L_8002B11C
    if (ctx->r6 == 0) {
        // 0x8002B0DC: swc1        $f16, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
            goto L_8002B11C;
    }
    // 0x8002B0DC: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8002B0E0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0E4: nop

    // 0x8002B0E8: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8002B0EC: nop

    // 0x8002B0F0: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x8002B0F4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0F8: nop

    // 0x8002B0FC: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8002B100: nop

    // 0x8002B104: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x8002B108: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002B10C: nop

    // 0x8002B110: lwc1        $f18, 0xC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8002B114: nop

    // 0x8002B118: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
L_8002B11C:
    // 0x8002B11C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8002B120: nop

    // 0x8002B124: lb          $v0, 0x10($t5)
    ctx->r2 = MEM_B(ctx->r13, 0X10);
    // 0x8002B128: nop

    // 0x8002B12C: jr          $ra
    // 0x8002B130: nop

    return;
    // 0x8002B130: nop

;}
RECOMP_FUNC void func_8002B0F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B134: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002B138: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002B13C: sb          $zero, -0x2778($at)
    MEM_B(-0X2778, ctx->r1) = 0;
    // 0x8002B140: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x8002B144: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002B148: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002B14C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002B150: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8002B154: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002B158: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002B15C: cvt.w.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = CVT_W_S(ctx->f20.fl);
    // 0x8002B160: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8002B164: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002B168: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8002B16C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8002B170: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002B174: mfc1        $s6, $f4
    ctx->r22 = (int32_t)ctx->f4.u32l;
    // 0x8002B178: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002B17C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002B180: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002B184: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002B188: cvt.w.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    ctx->f6.u32l = CVT_W_S(ctx->f22.fl);
    // 0x8002B18C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002B190: mfc1        $s4, $f6
    ctx->r20 = (int32_t)ctx->f6.u32l;
    // 0x8002B194: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002B198: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8002B19C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8002B1A0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8002B1A4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8002B1A8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8002B1AC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8002B1B0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002B1B4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002B1B8: sw          $a3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r7;
    // 0x8002B1BC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002B1C0: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8002B1C4: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x8002B1C8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8002B1CC: jal         0x8002A09C
    // 0x8002B1D0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    get_inside_segment_count_xz(rdram, ctx);
        goto after_0;
    // 0x8002B1D0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8002B1D4: beq         $v0, $zero, L_8002B1E8
    if (ctx->r2 == 0) {
        // 0x8002B1D8: sw          $v0, 0x108($sp)
        MEM_W(0X108, ctx->r29) = ctx->r2;
            goto L_8002B1E8;
    }
    // 0x8002B1D8: sw          $v0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r2;
    // 0x8002B1DC: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8002B1E0: bne         $at, $zero, L_8002B1F0
    if (ctx->r1 != 0) {
        // 0x8002B1E4: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8002B1F0;
    }
    // 0x8002B1E4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8002B1E8:
    // 0x8002B1E8: b           L_8002B9BC
    // 0x8002B1EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002B9BC;
    // 0x8002B1EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002B1F0:
    // 0x8002B1F0: blez        $v0, L_8002B6C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002B1F4: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_8002B6C8;
    }
    // 0x8002B1F4: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8002B1F8: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8002B1FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002B200: sw          $s0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r16;
    // 0x8002B204: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x8002B208: sll         $t9, $fp, 2
    ctx->r25 = S32(ctx->r30 << 2);
L_8002B20C:
    // 0x8002B20C: addu        $t1, $sp, $t9
    ctx->r9 = ADD32(ctx->r29, ctx->r25);
    // 0x8002B210: lw          $t1, 0xB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XB0);
    // 0x8002B214: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8002B218: lw          $t3, -0x3178($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3178);
    // 0x8002B21C: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8002B220: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x8002B224: sll         $t6, $t1, 4
    ctx->r14 = S32(ctx->r9 << 4);
    // 0x8002B228: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x8002B22C: lw          $t7, 0x4($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X4);
    // 0x8002B230: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002B234: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8002B238: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B23C: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x8002B240: addu        $ra, $t6, $t7
    ctx->r31 = ADD32(ctx->r14, ctx->r15);
    // 0x8002B244: lh          $t6, 0x6($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X6);
    // 0x8002B248: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x8002B24C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002B250: subu        $a2, $t6, $t0
    ctx->r6 = SUB32(ctx->r14, ctx->r8);
    // 0x8002B254: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002B258: addiu       $a2, $t7, 0x1
    ctx->r6 = ADD32(ctx->r15, 0X1);
    // 0x8002B25C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002B260: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B264: addu        $v1, $a2, $t0
    ctx->r3 = ADD32(ctx->r6, ctx->r8);
    // 0x8002B268: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x8002B26C: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8002B270: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002B274: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002B278: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B27C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8002B280: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002B284: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8002B288:
    // 0x8002B288: slt         $at, $v1, $s6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002B28C: bne         $at, $zero, L_8002B2AC
    if (ctx->r1 != 0) {
        // 0x8002B290: addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
            goto L_8002B2AC;
    }
    // 0x8002B290: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B294: slt         $at, $s6, $a0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002B298: bne         $at, $zero, L_8002B2B0
    if (ctx->r1 != 0) {
        // 0x8002B29C: sll         $t7, $v1, 16
        ctx->r15 = S32(ctx->r3 << 16);
            goto L_8002B2B0;
    }
    // 0x8002B29C: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8002B2A0: or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // 0x8002B2A4: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8002B2A8: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
L_8002B2AC:
    // 0x8002B2AC: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
L_8002B2B0:
    // 0x8002B2B0: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002B2B4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002B2B8: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B2BC: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002B2C0: slti        $at, $a3, 0x8
    ctx->r1 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
    // 0x8002B2C4: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8002B2C8: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8002B2CC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002B2D0: bne         $at, $zero, L_8002B288
    if (ctx->r1 != 0) {
        // 0x8002B2D4: sra         $a1, $t8, 16
        ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8002B288;
    }
    // 0x8002B2D4: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B2D8: lh          $t0, 0x4($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X4);
    // 0x8002B2DC: lh          $t6, 0xA($t2)
    ctx->r14 = MEM_H(ctx->r10, 0XA);
    // 0x8002B2E0: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x8002B2E4: subu        $a2, $t6, $t0
    ctx->r6 = SUB32(ctx->r14, ctx->r8);
    // 0x8002B2E8: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002B2EC: addiu       $a2, $t7, 0x1
    ctx->r6 = ADD32(ctx->r15, 0X1);
    // 0x8002B2F0: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002B2F4: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B2F8: addu        $v1, $a2, $t0
    ctx->r3 = ADD32(ctx->r6, ctx->r8);
    // 0x8002B2FC: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8002B300: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002B304: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B308: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8002B30C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8002B310:
    // 0x8002B310: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002B314: bne         $at, $zero, L_8002B334
    if (ctx->r1 != 0) {
        // 0x8002B318: addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
            goto L_8002B334;
    }
    // 0x8002B318: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B31C: slt         $at, $s4, $a0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002B320: bne         $at, $zero, L_8002B338
    if (ctx->r1 != 0) {
        // 0x8002B324: sll         $t7, $v1, 16
        ctx->r15 = S32(ctx->r3 << 16);
            goto L_8002B338;
    }
    // 0x8002B324: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8002B328: or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // 0x8002B32C: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8002B330: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
L_8002B334:
    // 0x8002B334: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
L_8002B338:
    // 0x8002B338: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002B33C: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B340: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8002B344: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002B348: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002B34C: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8002B350: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002B354: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B358: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8002B35C: bne         $at, $zero, L_8002B37C
    if (ctx->r1 != 0) {
        // 0x8002B360: or          $a1, $t9, $zero
        ctx->r5 = ctx->r25 | 0;
            goto L_8002B37C;
    }
    // 0x8002B360: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8002B364: slt         $at, $s4, $t6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002B368: bne         $at, $zero, L_8002B37C
    if (ctx->r1 != 0) {
        // 0x8002B36C: nop
    
            goto L_8002B37C;
    }
    // 0x8002B36C: nop

    // 0x8002B370: or          $s1, $s1, $t9
    ctx->r17 = ctx->r17 | ctx->r25;
    // 0x8002B374: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x8002B378: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
L_8002B37C:
    // 0x8002B37C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B380: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x8002B384: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B388: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B38C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8002B390: or          $t8, $a1, $zero
    ctx->r24 = ctx->r5 | 0;
    // 0x8002B394: sll         $t9, $t8, 17
    ctx->r25 = S32(ctx->r24 << 17);
    // 0x8002B398: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B39C: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002B3A0: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002B3A4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8002B3A8: bne         $at, $zero, L_8002B3C8
    if (ctx->r1 != 0) {
        // 0x8002B3AC: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8002B3C8;
    }
    // 0x8002B3AC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8002B3B0: slt         $at, $s4, $t7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002B3B4: bne         $at, $zero, L_8002B3C8
    if (ctx->r1 != 0) {
        // 0x8002B3B8: nop
    
            goto L_8002B3C8;
    }
    // 0x8002B3B8: nop

    // 0x8002B3BC: or          $s1, $s1, $t6
    ctx->r17 = ctx->r17 | ctx->r14;
    // 0x8002B3C0: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8002B3C4: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
L_8002B3C8:
    // 0x8002B3C8: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B3CC: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8002B3D0: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002B3D4: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B3D8: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8002B3DC: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8002B3E0: sll         $t6, $t9, 17
    ctx->r14 = S32(ctx->r25 << 17);
    // 0x8002B3E4: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002B3E8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B3EC: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002B3F0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8002B3F4: bne         $at, $zero, L_8002B414
    if (ctx->r1 != 0) {
        // 0x8002B3F8: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_8002B414;
    }
    // 0x8002B3F8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8002B3FC: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002B400: bne         $at, $zero, L_8002B414
    if (ctx->r1 != 0) {
        // 0x8002B404: nop
    
            goto L_8002B414;
    }
    // 0x8002B404: nop

    // 0x8002B408: or          $s1, $s1, $t7
    ctx->r17 = ctx->r17 | ctx->r15;
    // 0x8002B40C: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x8002B410: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
L_8002B414:
    // 0x8002B414: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B418: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8002B41C: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B420: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8002B424: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B428: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8002B42C: sll         $t7, $t6, 17
    ctx->r15 = S32(ctx->r14 << 17);
    // 0x8002B430: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8002B434: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002B438: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002B43C: bne         $a3, $at, L_8002B310
    if (ctx->r7 != ctx->r1) {
        // 0x8002B440: sra         $a0, $t8, 16
        ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8002B310;
    }
    // 0x8002B440: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B444: lh          $a1, 0x20($ra)
    ctx->r5 = MEM_H(ctx->r31, 0X20);
    // 0x8002B448: nop

    // 0x8002B44C: blez        $a1, L_8002B6AC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002B450: sll         $t6, $s7, 2
        ctx->r14 = S32(ctx->r23 << 2);
            goto L_8002B6AC;
    }
    // 0x8002B450: sll         $t6, $s7, 2
    ctx->r14 = S32(ctx->r23 << 2);
L_8002B454:
    // 0x8002B454: lw          $t9, 0xC($ra)
    ctx->r25 = MEM_W(ctx->r31, 0XC);
    // 0x8002B458: subu        $t6, $t6, $s7
    ctx->r14 = SUB32(ctx->r14, ctx->r23);
    // 0x8002B45C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B460: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8002B464: lw          $t7, -0x3178($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3178);
    // 0x8002B468: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x8002B46C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8002B470: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8002B474: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x8002B478: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8002B47C: lb          $s2, 0x7($t7)
    ctx->r18 = MEM_B(ctx->r15, 0X7);
    // 0x8002B480: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    // 0x8002B484: lh          $t5, 0x2($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2);
    // 0x8002B488: lh          $s0, 0x10($v1)
    ctx->r16 = MEM_H(ctx->r3, 0X10);
    // 0x8002B48C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8002B490: beq         $s2, $at, L_8002B4B8
    if (ctx->r18 == ctx->r1) {
        // 0x8002B494: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8002B4B8;
    }
    // 0x8002B494: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8002B498: beq         $s2, $at, L_8002B4BC
    if (ctx->r18 == ctx->r1) {
        // 0x8002B49C: slt         $at, $a0, $s0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_8002B4BC;
    }
    // 0x8002B49C: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002B4A0: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x8002B4A4: nop

    // 0x8002B4A8: andi        $t8, $t9, 0x300
    ctx->r24 = ctx->r25 & 0X300;
    // 0x8002B4AC: beq         $t8, $zero, L_8002B4BC
    if (ctx->r24 == 0) {
        // 0x8002B4B0: slt         $at, $a0, $s0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_8002B4BC;
    }
    // 0x8002B4B0: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002B4B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8002B4B8:
    // 0x8002B4B8: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
L_8002B4BC:
    // 0x8002B4BC: beq         $at, $zero, L_8002B69C
    if (ctx->r1 == 0) {
        // 0x8002B4C0: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_8002B69C;
    }
    // 0x8002B4C0: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
L_8002B4C4:
    // 0x8002B4C4: lw          $t6, 0x10($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X10);
    // 0x8002B4C8: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x8002B4CC: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8002B4D0: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x8002B4D4: nop

    // 0x8002B4D8: and         $t6, $t8, $s1
    ctx->r14 = ctx->r24 & ctx->r17;
    // 0x8002B4DC: bne         $s1, $t6, L_8002B684
    if (ctx->r17 != ctx->r14) {
        // 0x8002B4E0: nop
    
            goto L_8002B684;
    }
    // 0x8002B4E0: nop

    // 0x8002B4E4: lw          $t7, 0x4($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X4);
    // 0x8002B4E8: sll         $t9, $t2, 4
    ctx->r25 = S32(ctx->r10 << 4);
    // 0x8002B4EC: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x8002B4F0: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x8002B4F4: lbu         $t9, 0x2($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2);
    // 0x8002B4F8: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x8002B4FC: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B500: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x8002B504: lw          $a1, 0x0($ra)
    ctx->r5 = MEM_W(ctx->r31, 0X0);
    // 0x8002B508: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B50C: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x8002B510: lbu         $t7, 0x3($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3);
    // 0x8002B514: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B518: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x8002B51C: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x8002B520: lh          $a3, 0x4($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X4);
    // 0x8002B524: nop

    // 0x8002B528: subu        $a0, $s4, $a3
    ctx->r4 = SUB32(ctx->r20, ctx->r7);
    // 0x8002B52C: mflo        $t6
    ctx->r14 = lo;
    // 0x8002B530: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x8002B534: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x8002B538: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B53C: lh          $t1, 0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X4);
    // 0x8002B540: subu        $t9, $t0, $a2
    ctx->r25 = SUB32(ctx->r8, ctx->r6);
    // 0x8002B544: subu        $t6, $t1, $a3
    ctx->r14 = SUB32(ctx->r9, ctx->r7);
    // 0x8002B548: mflo        $t8
    ctx->r24 = lo;
    // 0x8002B54C: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x8002B550: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x8002B554: lh          $t4, 0x4($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X4);
    // 0x8002B558: subu        $v1, $s6, $a2
    ctx->r3 = SUB32(ctx->r22, ctx->r6);
    // 0x8002B55C: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B560: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B564: nop

    // 0x8002B568: nop

    // 0x8002B56C: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B570: subu        $t9, $s6, $t0
    ctx->r25 = SUB32(ctx->r22, ctx->r8);
    // 0x8002B574: mflo        $t8
    ctx->r24 = lo;
    // 0x8002B578: subu        $a1, $t7, $t8
    ctx->r5 = SUB32(ctx->r15, ctx->r24);
    // 0x8002B57C: subu        $t7, $t4, $t1
    ctx->r15 = SUB32(ctx->r12, ctx->r9);
    // 0x8002B580: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B584: slti        $t6, $a1, 0x0
    ctx->r14 = SIGNED(ctx->r5) < 0X0 ? 1 : 0;
    // 0x8002B588: xori        $a1, $t6, 0x1
    ctx->r5 = ctx->r14 ^ 0X1;
    // 0x8002B58C: subu        $t9, $s4, $t1
    ctx->r25 = SUB32(ctx->r20, ctx->r9);
    // 0x8002B590: subu        $t6, $t3, $t0
    ctx->r14 = SUB32(ctx->r11, ctx->r8);
    // 0x8002B594: mflo        $t8
    ctx->r24 = lo;
    // 0x8002B598: nop

    // 0x8002B59C: nop

    // 0x8002B5A0: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B5A4: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B5A8: subu        $t6, $t8, $t7
    ctx->r14 = SUB32(ctx->r24, ctx->r15);
    // 0x8002B5AC: slti        $t9, $t6, 0x0
    ctx->r25 = SIGNED(ctx->r14) < 0X0 ? 1 : 0;
    // 0x8002B5B0: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x8002B5B4: bne         $t9, $a1, L_8002B684
    if (ctx->r25 != ctx->r5) {
        // 0x8002B5B8: subu        $t8, $t4, $a3
        ctx->r24 = SUB32(ctx->r12, ctx->r7);
            goto L_8002B684;
    }
    // 0x8002B5B8: subu        $t8, $t4, $a3
    ctx->r24 = SUB32(ctx->r12, ctx->r7);
    // 0x8002B5BC: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B5C0: subu        $t6, $t3, $a2
    ctx->r14 = SUB32(ctx->r11, ctx->r6);
    // 0x8002B5C4: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B5C8: nop

    // 0x8002B5CC: nop

    // 0x8002B5D0: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B5D4: mflo        $t9
    ctx->r25 = lo;
    // 0x8002B5D8: subu        $t8, $t7, $t9
    ctx->r24 = SUB32(ctx->r15, ctx->r25);
    // 0x8002B5DC: slti        $t6, $t8, 0x0
    ctx->r14 = SIGNED(ctx->r24) < 0X0 ? 1 : 0;
    // 0x8002B5E0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8002B5E4: beq         $a1, $t6, L_8002B684
    if (ctx->r5 == ctx->r14) {
        // 0x8002B5E8: nop
    
            goto L_8002B684;
    }
    // 0x8002B5E8: nop

    // 0x8002B5EC: lw          $t7, 0x14($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X14);
    // 0x8002B5F0: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x8002B5F4: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8002B5F8: lhu         $t7, 0x0($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X0);
    // 0x8002B5FC: lw          $t6, 0x18($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X18);
    // 0x8002B600: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8002B604: addu        $v1, $t6, $t9
    ctx->r3 = ADD32(ctx->r14, ctx->r25);
    // 0x8002B608: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002B60C: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002B610: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B614: c.eq.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d == ctx->f8.d;
    // 0x8002B618: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002B61C: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002B620: bc1t        L_8002B684
    if (c1cs) {
        // 0x8002B624: nop
    
            goto L_8002B684;
    }
    // 0x8002B624: nop

    // 0x8002B628: mul.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8002B62C: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x8002B630: addu        $t8, $t8, $s5
    ctx->r24 = ADD32(ctx->r24, ctx->r21);
    // 0x8002B634: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002B638: mul.s       $f18, $f12, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x8002B63C: addiu       $t7, $t7, -0x2958
    ctx->r15 = ADD32(ctx->r15, -0X2958);
    // 0x8002B640: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002B644: addu        $v1, $t8, $t7
    ctx->r3 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B648: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8002B64C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8002B650: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x8002B654: slti        $at, $s5, 0x14
    ctx->r1 = SIGNED(ctx->r21) < 0X14 ? 1 : 0;
    // 0x8002B658: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002B65C: sb          $s2, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r18;
    // 0x8002B660: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x8002B664: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8002B668: swc1        $f12, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f12.u32l;
    // 0x8002B66C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8002B670: bne         $at, $zero, L_8002B684
    if (ctx->r1 != 0) {
        // 0x8002B674: swc1        $f10, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
            goto L_8002B684;
    }
    // 0x8002B674: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8002B678: lh          $s7, 0x20($ra)
    ctx->r23 = MEM_H(ctx->r31, 0X20);
    // 0x8002B67C: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x8002B680: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_8002B684:
    // 0x8002B684: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8002B688: slt         $at, $t2, $s0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002B68C: bne         $at, $zero, L_8002B4C4
    if (ctx->r1 != 0) {
        // 0x8002B690: nop
    
            goto L_8002B4C4;
    }
    // 0x8002B690: nop

    // 0x8002B694: lh          $a1, 0x20($ra)
    ctx->r5 = MEM_H(ctx->r31, 0X20);
    // 0x8002B698: nop

L_8002B69C:
    // 0x8002B69C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002B6A0: slt         $at, $s7, $a1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002B6A4: bne         $at, $zero, L_8002B454
    if (ctx->r1 != 0) {
        // 0x8002B6A8: sll         $t6, $s7, 2
        ctx->r14 = S32(ctx->r23 << 2);
            goto L_8002B454;
    }
    // 0x8002B6A8: sll         $t6, $s7, 2
    ctx->r14 = S32(ctx->r23 << 2);
L_8002B6AC:
    // 0x8002B6AC: lw          $t6, 0x108($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X108);
    // 0x8002B6B0: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8002B6B4: slt         $at, $fp, $t6
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002B6B8: bne         $at, $zero, L_8002B20C
    if (ctx->r1 != 0) {
        // 0x8002B6BC: sll         $t9, $fp, 2
        ctx->r25 = S32(ctx->r30 << 2);
            goto L_8002B20C;
    }
    // 0x8002B6BC: sll         $t9, $fp, 2
    ctx->r25 = S32(ctx->r30 << 2);
    // 0x8002B6C0: lw          $s0, 0x128($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X128);
    // 0x8002B6C4: nop

L_8002B6C8:
    // 0x8002B6C8: bltz        $s0, L_8002B77C
    if (SIGNED(ctx->r16) < 0) {
        // 0x8002B6CC: lui         $t3, 0x800E
        ctx->r11 = S32(0X800E << 16);
            goto L_8002B77C;
    }
    // 0x8002B6CC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8002B6D0: lw          $t3, -0x3178($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3178);
    // 0x8002B6D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002B6D8: lh          $t9, 0x1A($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X1A);
    // 0x8002B6DC: addiu       $t0, $t0, -0x2958
    ctx->r8 = ADD32(ctx->r8, -0X2958);
    // 0x8002B6E0: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002B6E4: beq         $at, $zero, L_8002B77C
    if (ctx->r1 == 0) {
        // 0x8002B6E8: sll         $t7, $s0, 4
        ctx->r15 = S32(ctx->r16 << 4);
            goto L_8002B77C;
    }
    // 0x8002B6E8: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x8002B6EC: sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21 << 2);
    // 0x8002B6F0: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8002B6F4: lw          $t8, 0x4($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X4);
    // 0x8002B6F8: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x8002B6FC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002B700: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002B704: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x8002B708: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8002B70C: sb          $t6, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r14;
    // 0x8002B710: addu        $ra, $t8, $t7
    ctx->r31 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B714: lb          $t9, 0x2B($ra)
    ctx->r25 = MEM_B(ctx->r31, 0X2B);
    // 0x8002B718: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002B71C: beq         $t9, $zero, L_8002B754
    if (ctx->r25 == 0) {
        // 0x8002B720: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8002B754;
    }
    // 0x8002B720: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002B724: lw          $t8, -0x26FC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26FC);
    // 0x8002B728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002B72C: beq         $t8, $zero, L_8002B754
    if (ctx->r24 == 0) {
        // 0x8002B730: addu        $a3, $v0, $t0
        ctx->r7 = ADD32(ctx->r2, ctx->r8);
            goto L_8002B754;
    }
    // 0x8002B730: addu        $a3, $v0, $t0
    ctx->r7 = ADD32(ctx->r2, ctx->r8);
    // 0x8002B734: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8002B738: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8002B73C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8002B740: jal         0x800BB814
    // 0x8002B744: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    func_800BB2F4(rdram, ctx);
        goto after_1;
    // 0x8002B744: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    after_1:
    // 0x8002B748: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8002B74C: b           L_8002B778
    // 0x8002B750: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_8002B778;
    // 0x8002B750: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_8002B754:
    // 0x8002B754: lh          $t7, 0x38($ra)
    ctx->r15 = MEM_H(ctx->r31, 0X38);
    // 0x8002B758: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002B75C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8002B760: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002B764: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002B768: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8002B76C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8002B770: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8002B774: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
L_8002B778:
    // 0x8002B778: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_8002B77C:
    // 0x8002B77C: blez        $s5, L_8002B83C
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8002B780: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8002B83C;
    }
    // 0x8002B780: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002B784: andi        $a1, $s5, 0x3
    ctx->r5 = ctx->r21 & 0X3;
    // 0x8002B788: beq         $a1, $zero, L_8002B7C8
    if (ctx->r5 == 0) {
        // 0x8002B78C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8002B7C8;
    }
    // 0x8002B78C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002B790: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002B794: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002B798: addiu       $t7, $t7, -0x2958
    ctx->r15 = ADD32(ctx->r15, -0X2958);
    // 0x8002B79C: addiu       $t9, $t9, -0x27C8
    ctx->r25 = ADD32(ctx->r25, -0X27C8);
    // 0x8002B7A0: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8002B7A4: sll         $t8, $zero, 4
    ctx->r24 = S32(0 << 4);
    // 0x8002B7A8: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B7AC: addu        $v1, $t6, $t9
    ctx->r3 = ADD32(ctx->r14, ctx->r25);
L_8002B7B0:
    // 0x8002B7B0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002B7B4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002B7B8: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x8002B7BC: bne         $a0, $a3, L_8002B7B0
    if (ctx->r4 != ctx->r7) {
        // 0x8002B7C0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8002B7B0;
    }
    // 0x8002B7C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002B7C4: beq         $a3, $s5, L_8002B83C
    if (ctx->r7 == ctx->r21) {
        // 0x8002B7C8: sll         $t6, $s5, 2
        ctx->r14 = S32(ctx->r21 << 2);
            goto L_8002B83C;
    }
L_8002B7C8:
    // 0x8002B7C8: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x8002B7CC: addu        $t6, $t6, $s5
    ctx->r14 = ADD32(ctx->r14, ctx->r21);
    // 0x8002B7D0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002B7D4: addiu       $t9, $t9, -0x291C
    ctx->r25 = ADD32(ctx->r25, -0X291C);
    // 0x8002B7D8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B7DC: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x8002B7E0: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8002B7E4: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x8002B7E8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002B7EC: addiu       $t9, $t9, -0x2958
    ctx->r25 = ADD32(ctx->r25, -0X2958);
    // 0x8002B7F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B7F4: addu        $v0, $t6, $t9
    ctx->r2 = ADD32(ctx->r14, ctx->r25);
    // 0x8002B7F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002B7FC: addiu       $t7, $t7, -0x27C8
    ctx->r15 = ADD32(ctx->r15, -0X27C8);
    // 0x8002B800: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x8002B804: addu        $v1, $t8, $t7
    ctx->r3 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B808: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    // 0x8002B80C: addiu       $a2, $v0, 0x28
    ctx->r6 = ADD32(ctx->r2, 0X28);
    // 0x8002B810: addiu       $a0, $v0, 0x3C
    ctx->r4 = ADD32(ctx->r2, 0X3C);
L_8002B814:
    // 0x8002B814: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
    // 0x8002B818: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x8002B81C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002B820: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8002B824: sw          $a2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r6;
    // 0x8002B828: addiu       $a2, $a2, 0x50
    ctx->r6 = ADD32(ctx->r6, 0X50);
    // 0x8002B82C: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x8002B830: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x8002B834: bne         $a0, $t0, L_8002B814
    if (ctx->r4 != ctx->r8) {
        // 0x8002B838: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8002B814;
    }
    // 0x8002B838: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8002B83C:
    // 0x8002B83C: addiu       $t1, $s5, -0x1
    ctx->r9 = ADD32(ctx->r21, -0X1);
    // 0x8002B840: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8002B844:
    // 0x8002B844: blez        $t1, L_8002B998
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8002B848: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8002B998;
    }
    // 0x8002B848: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002B84C: addiu       $v0, $s5, -0x1
    ctx->r2 = ADD32(ctx->r21, -0X1);
    // 0x8002B850: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8002B854: beq         $t8, $zero, L_8002B8A8
    if (ctx->r24 == 0) {
        // 0x8002B858: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_8002B8A8;
    }
    // 0x8002B858: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8002B85C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002B860: addiu       $t6, $t6, -0x27C8
    ctx->r14 = ADD32(ctx->r14, -0X27C8);
    // 0x8002B864: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x8002B868: addu        $v1, $t7, $t6
    ctx->r3 = ADD32(ctx->r15, ctx->r14);
L_8002B86C:
    // 0x8002B86C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8002B870: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8002B874: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B878: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002B87C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002B880: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8002B884: nop

    // 0x8002B888: bc1f        L_8002B89C
    if (!c1cs) {
        // 0x8002B88C: nop
    
            goto L_8002B89C;
    }
    // 0x8002B88C: nop

    // 0x8002B890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B894: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8002B898: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
L_8002B89C:
    // 0x8002B89C: bne         $t0, $a3, L_8002B86C
    if (ctx->r8 != ctx->r7) {
        // 0x8002B8A0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8002B86C;
    }
    // 0x8002B8A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002B8A4: beq         $a3, $t1, L_8002B998
    if (ctx->r7 == ctx->r9) {
        // 0x8002B8A8: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8002B998;
    }
L_8002B8A8:
    // 0x8002B8A8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002B8AC: addiu       $t8, $t8, -0x27C8
    ctx->r24 = ADD32(ctx->r24, -0X27C8);
    // 0x8002B8B0: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8002B8B4: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8002B8B8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8002B8BC: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
L_8002B8C0:
    // 0x8002B8C0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8002B8C4: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8002B8C8: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B8CC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002B8D0: nop

    // 0x8002B8D4: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8002B8D8: nop

    // 0x8002B8DC: bc1f        L_8002B8F8
    if (!c1cs) {
        // 0x8002B8E0: nop
    
            goto L_8002B8F8;
    }
    // 0x8002B8E0: nop

    // 0x8002B8E4: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8002B8E8: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8002B8EC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B8F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B8F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8002B8F8:
    // 0x8002B8F8: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x8002B8FC: nop

    // 0x8002B900: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B904: nop

    // 0x8002B908: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002B90C: nop

    // 0x8002B910: bc1f        L_8002B92C
    if (!c1cs) {
        // 0x8002B914: nop
    
            goto L_8002B92C;
    }
    // 0x8002B914: nop

    // 0x8002B918: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8002B91C: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x8002B920: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002B924: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002B928: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8002B92C:
    // 0x8002B92C: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x8002B930: nop

    // 0x8002B934: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002B938: nop

    // 0x8002B93C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002B940: nop

    // 0x8002B944: bc1f        L_8002B960
    if (!c1cs) {
        // 0x8002B948: nop
    
            goto L_8002B960;
    }
    // 0x8002B948: nop

    // 0x8002B94C: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x8002B950: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8002B954: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B958: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002B95C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8002B960:
    // 0x8002B960: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    // 0x8002B964: nop

    // 0x8002B968: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B96C: nop

    // 0x8002B970: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8002B974: nop

    // 0x8002B978: bc1f        L_8002B98C
    if (!c1cs) {
        // 0x8002B97C: nop
    
            goto L_8002B98C;
    }
    // 0x8002B97C: nop

    // 0x8002B980: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B984: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8002B988: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
L_8002B98C:
    // 0x8002B98C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8002B990: bne         $v1, $t0, L_8002B8C0
    if (ctx->r3 != ctx->r8) {
        // 0x8002B994: nop
    
            goto L_8002B8C0;
    }
    // 0x8002B994: nop

L_8002B998:
    // 0x8002B998: beq         $a2, $zero, L_8002B844
    if (ctx->r6 == 0) {
        // 0x8002B99C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8002B844;
    }
    // 0x8002B99C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8002B9A0: lw          $t9, 0x134($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X134);
    // 0x8002B9A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002B9A8: addiu       $t6, $t6, -0x27C8
    ctx->r14 = ADD32(ctx->r14, -0X27C8);
    // 0x8002B9AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002B9B0: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8002B9B4: sb          $s5, -0x2778($at)
    MEM_B(-0X2778, ctx->r1) = ctx->r21;
    // 0x8002B9B8: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_8002B9BC:
    // 0x8002B9BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002B9C0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002B9C4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002B9C8: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002B9CC: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002B9D0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002B9D4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B9D8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002B9DC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002B9E0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8002B9E4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8002B9E8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8002B9EC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8002B9F0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8002B9F4: jr          $ra
    // 0x8002B9F8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x8002B9F8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void func_8002B9BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B9FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002BA00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002BA04: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8002BA08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002BA0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002BA10: beq         $a2, $zero, L_8002BA30
    if (ctx->r6 == 0) {
        // 0x8002BA14: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8002BA30;
    }
    // 0x8002BA14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002BA18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002BA1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002BA20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002BA24: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8002BA28: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8002BA2C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
L_8002BA30:
    // 0x8002BA30: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002BA34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8002BA38: lh          $a0, 0x2E($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X2E);
    // 0x8002BA3C: nop

    // 0x8002BA40: bltz        $a0, L_8002BA64
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002BA44: nop
    
            goto L_8002BA64;
    }
    // 0x8002BA44: nop

    // 0x8002BA48: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x8002BA4C: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x8002BA50: lh          $t7, 0x1A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X1A);
    // 0x8002BA54: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8002BA58: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002BA5C: bne         $at, $zero, L_8002BA6C
    if (ctx->r1 != 0) {
        // 0x8002BA60: nop
    
            goto L_8002BA6C;
    }
    // 0x8002BA60: nop

L_8002BA64:
    // 0x8002BA64: b           L_8002BAE0
    // 0x8002BA68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002BAE0;
    // 0x8002BA68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002BA6C:
    // 0x8002BA6C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8002BA70: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002BA74: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8002BA78: lb          $t0, 0x2B($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X2B);
    // 0x8002BA7C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002BA80: beq         $t0, $zero, L_8002BAC8
    if (ctx->r8 == 0) {
        // 0x8002BA84: nop
    
            goto L_8002BAC8;
    }
    // 0x8002BA84: nop

    // 0x8002BA88: lw          $t1, -0x26FC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X26FC);
    // 0x8002BA8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002BA90: beq         $t1, $zero, L_8002BAC8
    if (ctx->r9 == 0) {
        // 0x8002BA94: nop
    
            goto L_8002BAC8;
    }
    // 0x8002BA94: nop

    // 0x8002BA98: bne         $a3, $at, L_8002BAC8
    if (ctx->r7 != ctx->r1) {
        // 0x8002BA9C: nop
    
            goto L_8002BAC8;
    }
    // 0x8002BA9C: nop

    // 0x8002BAA0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002BAA4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002BAA8: lw          $a1, 0xC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC);
    // 0x8002BAAC: lw          $a2, 0x14($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X14);
    // 0x8002BAB0: jal         0x800BB814
    // 0x8002BAB4: nop

    func_800BB2F4(rdram, ctx);
        goto after_0;
    // 0x8002BAB4: nop

    after_0:
    // 0x8002BAB8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002BABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002BAC0: b           L_8002BAE0
    // 0x8002BAC4: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
        goto L_8002BAE0;
    // 0x8002BAC4: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
L_8002BAC8:
    // 0x8002BAC8: lh          $t4, 0x38($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X38);
    // 0x8002BACC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8002BAD0: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8002BAD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002BAD8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002BADC: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
L_8002BAE0:
    // 0x8002BAE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BAE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002BAE8: jr          $ra
    // 0x8002BAEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002BAEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void collision_get_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BAF0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002BAF4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8002BAF8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8002BAFC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8002BB00: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x8002BB04: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002BB08: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x8002BB0C: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8002BB10: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8002BB14: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8002BB18: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8002BB1C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8002BB20: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002BB24: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002BB28: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002BB2C: bltz        $a0, L_8002BB54
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002BB30: swc1        $f20, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
            goto L_8002BB54;
    }
    // 0x8002BB30: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x8002BB34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8002BB38: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x8002BB3C: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x8002BB40: lh          $t6, 0x1A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1A);
    // 0x8002BB44: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8002BB48: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002BB4C: bne         $at, $zero, L_8002BB5C
    if (ctx->r1 != 0) {
        // 0x8002BB50: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8002BB5C;
    }
    // 0x8002BB50: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
L_8002BB54:
    // 0x8002BB54: b           L_8002C0CC
    // 0x8002BB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002C0CC;
    // 0x8002BB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002BB5C:
    // 0x8002BB5C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8002BB60: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8002BB64: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8002BB68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002BB6C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8002BB70: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x8002BB74: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002BB78: addu        $t4, $t7, $t8
    ctx->r12 = ADD32(ctx->r15, ctx->r24);
    // 0x8002BB7C: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x8002BB80: lh          $a3, 0x0($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X0);
    // 0x8002BB84: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002BB88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002BB8C: subu        $a2, $t7, $a3
    ctx->r6 = SUB32(ctx->r15, ctx->r7);
    // 0x8002BB90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002BB94: sra         $t8, $a2, 3
    ctx->r24 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002BB98: addiu       $a2, $t8, 0x1
    ctx->r6 = ADD32(ctx->r24, 0X1);
    // 0x8002BB9C: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x8002BBA0: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x8002BBA4: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BBA8: addu        $t0, $a2, $a3
    ctx->r8 = ADD32(ctx->r6, ctx->r7);
    // 0x8002BBAC: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x8002BBB0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002BBB4: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8002BBB8: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8002BBBC: mfc1        $s3, $f4
    ctx->r19 = (int32_t)ctx->f4.u32l;
    // 0x8002BBC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002BBC4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002BBC8: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BBCC: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8002BBD0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8002BBD4:
    // 0x8002BBD4: slt         $at, $t0, $s3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8002BBD8: bne         $at, $zero, L_8002BBF8
    if (ctx->r1 != 0) {
        // 0x8002BBDC: addu        $t0, $t0, $a2
        ctx->r8 = ADD32(ctx->r8, ctx->r6);
            goto L_8002BBF8;
    }
    // 0x8002BBDC: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BBE0: slt         $at, $s3, $t1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002BBE4: bne         $at, $zero, L_8002BBFC
    if (ctx->r1 != 0) {
        // 0x8002BBE8: sll         $t9, $t0, 16
        ctx->r25 = S32(ctx->r8 << 16);
            goto L_8002BBFC;
    }
    // 0x8002BBE8: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8002BBEC: or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // 0x8002BBF0: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8002BBF4: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
L_8002BBF8:
    // 0x8002BBF8: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
L_8002BBFC:
    // 0x8002BBFC: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BC00: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8002BC04: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BC08: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8002BC0C: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8002BC10: sll         $t7, $t1, 16
    ctx->r15 = S32(ctx->r9 << 16);
    // 0x8002BC14: sll         $t6, $t9, 17
    ctx->r14 = S32(ctx->r25 << 17);
    // 0x8002BC18: sra         $t1, $t7, 16
    ctx->r9 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BC1C: bne         $at, $zero, L_8002BBD4
    if (ctx->r1 != 0) {
        // 0x8002BC20: sra         $a1, $t6, 16
        ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8002BBD4;
    }
    // 0x8002BC20: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BC24: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x8002BC28: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x8002BC2C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002BC30: subu        $a2, $t8, $v0
    ctx->r6 = SUB32(ctx->r24, ctx->r2);
    // 0x8002BC34: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002BC38: sra         $t9, $a2, 3
    ctx->r25 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002BC3C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002BC40: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002BC44: addiu       $a2, $t9, 0x1
    ctx->r6 = ADD32(ctx->r25, 0X1);
    // 0x8002BC48: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8002BC4C: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x8002BC50: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BC54: addu        $t0, $a2, $v0
    ctx->r8 = ADD32(ctx->r6, ctx->r2);
    // 0x8002BC58: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x8002BC5C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002BC60: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x8002BC64: sra         $t6, $t1, 16
    ctx->r14 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8002BC68: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x8002BC6C: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002BC70: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8002BC74: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8002BC78: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8002BC7C:
    // 0x8002BC7C: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002BC80: bne         $at, $zero, L_8002BCA0
    if (ctx->r1 != 0) {
        // 0x8002BC84: addu        $t0, $t0, $a2
        ctx->r8 = ADD32(ctx->r8, ctx->r6);
            goto L_8002BCA0;
    }
    // 0x8002BC84: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BC88: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002BC8C: bne         $at, $zero, L_8002BCA4
    if (ctx->r1 != 0) {
        // 0x8002BC90: sll         $t6, $t0, 16
        ctx->r14 = S32(ctx->r8 << 16);
            goto L_8002BCA4;
    }
    // 0x8002BC90: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x8002BC94: or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // 0x8002BC98: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x8002BC9C: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
L_8002BCA0:
    // 0x8002BCA0: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
L_8002BCA4:
    // 0x8002BCA4: sra         $t0, $t6, 16
    ctx->r8 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BCA8: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BCAC: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x8002BCB0: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8002BCB4: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002BCB8: sll         $t7, $t6, 17
    ctx->r15 = S32(ctx->r14 << 17);
    // 0x8002BCBC: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002BCC0: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BCC4: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8002BCC8: bne         $at, $zero, L_8002BCE8
    if (ctx->r1 != 0) {
        // 0x8002BCCC: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_8002BCE8;
    }
    // 0x8002BCCC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8002BCD0: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002BCD4: bne         $at, $zero, L_8002BCE8
    if (ctx->r1 != 0) {
        // 0x8002BCD8: nop
    
            goto L_8002BCE8;
    }
    // 0x8002BCD8: nop

    // 0x8002BCDC: or          $s1, $s1, $t8
    ctx->r17 = ctx->r17 | ctx->r24;
    // 0x8002BCE0: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8002BCE4: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
L_8002BCE8:
    // 0x8002BCE8: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BCEC: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8002BCF0: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BCF4: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BCF8: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8002BCFC: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002BD00: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8002BD04: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BD08: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002BD0C: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002BD10: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8002BD14: bne         $at, $zero, L_8002BD34
    if (ctx->r1 != 0) {
        // 0x8002BD18: or          $t1, $t6, $zero
        ctx->r9 = ctx->r14 | 0;
            goto L_8002BD34;
    }
    // 0x8002BD18: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8002BD1C: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002BD20: bne         $at, $zero, L_8002BD34
    if (ctx->r1 != 0) {
        // 0x8002BD24: nop
    
            goto L_8002BD34;
    }
    // 0x8002BD24: nop

    // 0x8002BD28: or          $s1, $s1, $t9
    ctx->r17 = ctx->r17 | ctx->r25;
    // 0x8002BD2C: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x8002BD30: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
L_8002BD34:
    // 0x8002BD34: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BD38: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x8002BD3C: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002BD40: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BD44: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x8002BD48: or          $t8, $a1, $zero
    ctx->r24 = ctx->r5 | 0;
    // 0x8002BD4C: sll         $t9, $t8, 17
    ctx->r25 = S32(ctx->r24 << 17);
    // 0x8002BD50: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BD54: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BD58: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002BD5C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8002BD60: bne         $at, $zero, L_8002BD80
    if (ctx->r1 != 0) {
        // 0x8002BD64: or          $t1, $t7, $zero
        ctx->r9 = ctx->r15 | 0;
            goto L_8002BD80;
    }
    // 0x8002BD64: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x8002BD68: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002BD6C: bne         $at, $zero, L_8002BD80
    if (ctx->r1 != 0) {
        // 0x8002BD70: nop
    
            goto L_8002BD80;
    }
    // 0x8002BD70: nop

    // 0x8002BD74: or          $s1, $s1, $t6
    ctx->r17 = ctx->r17 | ctx->r14;
    // 0x8002BD78: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8002BD7C: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
L_8002BD80:
    // 0x8002BD80: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BD84: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8002BD88: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BD8C: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8002BD90: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BD94: sll         $t7, $t1, 16
    ctx->r15 = S32(ctx->r9 << 16);
    // 0x8002BD98: sll         $t6, $t9, 17
    ctx->r14 = S32(ctx->r25 << 17);
    // 0x8002BD9C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8002BDA0: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BDA4: bne         $t2, $v0, L_8002BC7C
    if (ctx->r10 != ctx->r2) {
        // 0x8002BDA8: sra         $t1, $t7, 16
        ctx->r9 = S32(SIGNED(ctx->r15) >> 16);
            goto L_8002BC7C;
    }
    // 0x8002BDA8: sra         $t1, $t7, 16
    ctx->r9 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BDAC: lh          $v0, 0x20($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X20);
    // 0x8002BDB0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002BDB4: blez        $v0, L_8002BFA8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002BDB8: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8002BFA8;
    }
    // 0x8002BDB8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8002BDBC: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x8002BDC0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8002BDC4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8002BDC8: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
L_8002BDCC:
    // 0x8002BDCC: lw          $t8, 0xC($t4)
    ctx->r24 = MEM_W(ctx->r12, 0XC);
    // 0x8002BDD0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8002BDD4: addu        $a0, $t8, $s6
    ctx->r4 = ADD32(ctx->r24, ctx->r22);
    // 0x8002BDD8: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
    // 0x8002BDDC: lh          $t5, 0x10($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X10);
    // 0x8002BDE0: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x8002BDE4: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002BDE8: beq         $at, $zero, L_8002BF9C
    if (ctx->r1 == 0) {
        // 0x8002BDEC: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8002BF9C;
    }
    // 0x8002BDEC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8002BDF0: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
L_8002BDF4:
    // 0x8002BDF4: lw          $t9, 0x10($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X10);
    // 0x8002BDF8: nop

    // 0x8002BDFC: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8002BE00: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8002BE04: nop

    // 0x8002BE08: and         $t8, $t7, $s1
    ctx->r24 = ctx->r15 & ctx->r17;
    // 0x8002BE0C: bne         $s1, $t8, L_8002BF84
    if (ctx->r17 != ctx->r24) {
        // 0x8002BE10: nop
    
            goto L_8002BF84;
    }
    // 0x8002BE10: nop

    // 0x8002BE14: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8002BE18: sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6 << 4);
    // 0x8002BE1C: addu        $fp, $t9, $t6
    ctx->r30 = ADD32(ctx->r25, ctx->r14);
    // 0x8002BE20: lbu         $t7, 0x1($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1);
    // 0x8002BE24: lbu         $t6, 0x2($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0X2);
    // 0x8002BE28: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x8002BE2C: multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE30: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x8002BE34: lw          $ra, 0x0($t4)
    ctx->r31 = MEM_W(ctx->r12, 0X0);
    // 0x8002BE38: mflo        $t9
    ctx->r25 = lo;
    // 0x8002BE3C: addu        $s7, $t9, $ra
    ctx->r23 = ADD32(ctx->r25, ctx->r31);
    // 0x8002BE40: lbu         $t9, 0x3($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0X3);
    // 0x8002BE44: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE48: addu        $t6, $t9, $t1
    ctx->r14 = ADD32(ctx->r25, ctx->r9);
    // 0x8002BE4C: lh          $v0, 0x0($s7)
    ctx->r2 = MEM_H(ctx->r23, 0X0);
    // 0x8002BE50: lh          $v1, 0x4($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X4);
    // 0x8002BE54: nop

    // 0x8002BE58: subu        $fp, $s0, $v1
    ctx->r30 = SUB32(ctx->r16, ctx->r3);
    // 0x8002BE5C: mflo        $t8
    ctx->r24 = lo;
    // 0x8002BE60: addu        $s7, $t8, $ra
    ctx->r23 = ADD32(ctx->r24, ctx->r31);
    // 0x8002BE64: lh          $a0, 0x0($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X0);
    // 0x8002BE68: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE6C: lh          $a1, 0x4($s7)
    ctx->r5 = MEM_H(ctx->r23, 0X4);
    // 0x8002BE70: subu        $t6, $a0, $v0
    ctx->r14 = SUB32(ctx->r4, ctx->r2);
    // 0x8002BE74: subu        $t8, $a1, $v1
    ctx->r24 = SUB32(ctx->r5, ctx->r3);
    // 0x8002BE78: mflo        $t7
    ctx->r15 = lo;
    // 0x8002BE7C: addu        $s7, $t7, $ra
    ctx->r23 = ADD32(ctx->r15, ctx->r31);
    // 0x8002BE80: lh          $a3, 0x0($s7)
    ctx->r7 = MEM_H(ctx->r23, 0X0);
    // 0x8002BE84: lh          $t0, 0x4($s7)
    ctx->r8 = MEM_H(ctx->r23, 0X4);
    // 0x8002BE88: subu        $s7, $s3, $v0
    ctx->r23 = SUB32(ctx->r19, ctx->r2);
    // 0x8002BE8C: multu       $s7, $t8
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE90: mflo        $t9
    ctx->r25 = lo;
    // 0x8002BE94: nop

    // 0x8002BE98: nop

    // 0x8002BE9C: multu       $t6, $fp
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BEA0: subu        $t6, $s3, $a0
    ctx->r14 = SUB32(ctx->r19, ctx->r4);
    // 0x8002BEA4: mflo        $t7
    ctx->r15 = lo;
    // 0x8002BEA8: subu        $ra, $t9, $t7
    ctx->r31 = SUB32(ctx->r25, ctx->r15);
    // 0x8002BEAC: subu        $t9, $t0, $a1
    ctx->r25 = SUB32(ctx->r8, ctx->r5);
    // 0x8002BEB0: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BEB4: slti        $t8, $ra, 0x0
    ctx->r24 = SIGNED(ctx->r31) < 0X0 ? 1 : 0;
    // 0x8002BEB8: xori        $ra, $t8, 0x1
    ctx->r31 = ctx->r24 ^ 0X1;
    // 0x8002BEBC: subu        $t6, $s0, $a1
    ctx->r14 = SUB32(ctx->r16, ctx->r5);
    // 0x8002BEC0: subu        $t8, $a3, $a0
    ctx->r24 = SUB32(ctx->r7, ctx->r4);
    // 0x8002BEC4: mflo        $t7
    ctx->r15 = lo;
    // 0x8002BEC8: nop

    // 0x8002BECC: nop

    // 0x8002BED0: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BED4: mflo        $t9
    ctx->r25 = lo;
    // 0x8002BED8: subu        $t8, $t7, $t9
    ctx->r24 = SUB32(ctx->r15, ctx->r25);
    // 0x8002BEDC: slti        $t6, $t8, 0x0
    ctx->r14 = SIGNED(ctx->r24) < 0X0 ? 1 : 0;
    // 0x8002BEE0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8002BEE4: bne         $t6, $ra, L_8002BF84
    if (ctx->r14 != ctx->r31) {
        // 0x8002BEE8: subu        $t7, $t0, $v1
        ctx->r15 = SUB32(ctx->r8, ctx->r3);
            goto L_8002BF84;
    }
    // 0x8002BEE8: subu        $t7, $t0, $v1
    ctx->r15 = SUB32(ctx->r8, ctx->r3);
    // 0x8002BEEC: multu       $s7, $t7
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BEF0: subu        $t8, $a3, $v0
    ctx->r24 = SUB32(ctx->r7, ctx->r2);
    // 0x8002BEF4: mflo        $t9
    ctx->r25 = lo;
    // 0x8002BEF8: nop

    // 0x8002BEFC: nop

    // 0x8002BF00: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BF04: mflo        $t6
    ctx->r14 = lo;
    // 0x8002BF08: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x8002BF0C: slti        $t8, $t7, 0x0
    ctx->r24 = SIGNED(ctx->r15) < 0X0 ? 1 : 0;
    // 0x8002BF10: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8002BF14: beq         $ra, $t8, L_8002BF84
    if (ctx->r31 == ctx->r24) {
        // 0x8002BF18: nop
    
            goto L_8002BF84;
    }
    // 0x8002BF18: nop

    // 0x8002BF1C: lw          $t9, 0x14($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X14);
    // 0x8002BF20: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x8002BF24: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002BF28: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x8002BF2C: lw          $t8, 0x18($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X18);
    // 0x8002BF30: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8002BF34: addu        $v1, $t8, $t6
    ctx->r3 = ADD32(ctx->r24, ctx->r14);
    // 0x8002BF38: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002BF3C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002BF40: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8002BF44: c.eq.d      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.d == ctx->f8.d;
    // 0x8002BF48: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002BF4C: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002BF50: bc1t        L_8002BF84
    if (c1cs) {
        // 0x8002BF54: nop
    
            goto L_8002BF84;
    }
    // 0x8002BF54: nop

    // 0x8002BF58: mul.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8002BF5C: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8002BF60: addu        $t9, $s4, $t7
    ctx->r25 = ADD32(ctx->r20, ctx->r15);
    // 0x8002BF64: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002BF68: mul.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8002BF6C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8002BF70: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8002BF74: nop

    // 0x8002BF78: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8002BF7C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8002BF80: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
L_8002BF84:
    // 0x8002BF84: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002BF88: slt         $at, $a2, $t5
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002BF8C: bne         $at, $zero, L_8002BDF4
    if (ctx->r1 != 0) {
        // 0x8002BF90: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_8002BDF4;
    }
    // 0x8002BF90: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x8002BF94: lh          $v0, 0x20($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X20);
    // 0x8002BF98: nop

L_8002BF9C:
    // 0x8002BF9C: slt         $at, $s5, $v0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002BFA0: bne         $at, $zero, L_8002BDCC
    if (ctx->r1 != 0) {
        // 0x8002BFA4: addiu       $s6, $s6, 0xC
        ctx->r22 = ADD32(ctx->r22, 0XC);
            goto L_8002BDCC;
    }
    // 0x8002BFA4: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
L_8002BFA8:
    // 0x8002BFA8: addiu       $a0, $s2, -0x1
    ctx->r4 = ADD32(ctx->r18, -0X1);
    // 0x8002BFAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002BFB0:
    // 0x8002BFB0: blez        $a0, L_8002C0C0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8002BFB4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002C0C0;
    }
    // 0x8002BFB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002BFB8: addiu       $a3, $s2, -0x1
    ctx->r7 = ADD32(ctx->r18, -0X1);
    // 0x8002BFBC: andi        $t8, $a3, 0x3
    ctx->r24 = ctx->r7 & 0X3;
    // 0x8002BFC0: beq         $t8, $zero, L_8002C004
    if (ctx->r24 == 0) {
        // 0x8002BFC4: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8002C004;
    }
    // 0x8002BFC4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8002BFC8: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8002BFCC: addu        $a1, $s4, $t6
    ctx->r5 = ADD32(ctx->r20, ctx->r14);
L_8002BFD0:
    // 0x8002BFD0: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8002BFD4: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002BFD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002BFDC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002BFE0: nop

    // 0x8002BFE4: bc1f        L_8002BFF8
    if (!c1cs) {
        // 0x8002BFE8: nop
    
            goto L_8002BFF8;
    }
    // 0x8002BFE8: nop

    // 0x8002BFEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002BFF0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8002BFF4: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
L_8002BFF8:
    // 0x8002BFF8: bne         $a2, $v0, L_8002BFD0
    if (ctx->r6 != ctx->r2) {
        // 0x8002BFFC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8002BFD0;
    }
    // 0x8002BFFC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8002C000: beq         $v0, $a0, L_8002C0C0
    if (ctx->r2 == ctx->r4) {
        // 0x8002C004: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8002C0C0;
    }
L_8002C004:
    // 0x8002C004: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8002C008: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8002C00C: addu        $a2, $t9, $s4
    ctx->r6 = ADD32(ctx->r25, ctx->r20);
    // 0x8002C010: addu        $a1, $s4, $t7
    ctx->r5 = ADD32(ctx->r20, ctx->r15);
L_8002C014:
    // 0x8002C014: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8002C018: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002C01C: nop

    // 0x8002C020: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002C024: nop

    // 0x8002C028: bc1f        L_8002C040
    if (!c1cs) {
        // 0x8002C02C: nop
    
            goto L_8002C040;
    }
    // 0x8002C02C: nop

    // 0x8002C030: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8002C034: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x8002C038: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8002C03C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002C040:
    // 0x8002C040: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8002C044: nop

    // 0x8002C048: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002C04C: nop

    // 0x8002C050: bc1f        L_8002C068
    if (!c1cs) {
        // 0x8002C054: nop
    
            goto L_8002C068;
    }
    // 0x8002C054: nop

    // 0x8002C058: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x8002C05C: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x8002C060: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8002C064: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002C068:
    // 0x8002C068: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8002C06C: nop

    // 0x8002C070: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002C074: nop

    // 0x8002C078: bc1f        L_8002C090
    if (!c1cs) {
        // 0x8002C07C: nop
    
            goto L_8002C090;
    }
    // 0x8002C07C: nop

    // 0x8002C080: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x8002C084: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    // 0x8002C088: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8002C08C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002C090:
    // 0x8002C090: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8002C094: nop

    // 0x8002C098: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002C09C: nop

    // 0x8002C0A0: bc1f        L_8002C0B4
    if (!c1cs) {
        // 0x8002C0A4: nop
    
            goto L_8002C0B4;
    }
    // 0x8002C0A4: nop

    // 0x8002C0A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002C0AC: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    // 0x8002C0B0: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
L_8002C0B4:
    // 0x8002C0B4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8002C0B8: bne         $a1, $a2, L_8002C014
    if (ctx->r5 != ctx->r6) {
        // 0x8002C0BC: nop
    
            goto L_8002C014;
    }
    // 0x8002C0BC: nop

L_8002C0C0:
    // 0x8002C0C0: beq         $v1, $zero, L_8002BFB0
    if (ctx->r3 == 0) {
        // 0x8002C0C4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002BFB0;
    }
    // 0x8002C0C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002C0C8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8002C0CC:
    // 0x8002C0CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002C0D0: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x8002C0D4: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8002C0D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002C0DC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002C0E0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8002C0E4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C0E8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8002C0EC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8002C0F0: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8002C0F4: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C0F8: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x8002C0FC: jr          $ra
    // 0x8002C100: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002C100: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void generate_track(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C104: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002C108: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002C10C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8002C110: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002C114: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x8002C118: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8002C11C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8002C120: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8002C124: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002C128: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002C12C: jal         0x8007B7C4
    // 0x8002C130: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    set_texture_colour_tag(rdram, ctx);
        goto after_0;
    // 0x8002C130: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_0:
    // 0x8002C134: lui         $s5, 0x8
    ctx->r21 = S32(0X8 << 16);
    // 0x8002C138: ori         $s5, $s5, 0x2A00
    ctx->r21 = ctx->r21 | 0X2A00;
    // 0x8002C13C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8002C140: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8002C144: jal         0x80070EDC
    // 0x8002C148: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8002C148: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8002C14C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002C150: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8002C154: addiu       $s1, $s1, -0x3178
    ctx->r17 = ADD32(ctx->r17, -0X3178);
    // 0x8002C158: addiu       $v1, $v1, -0x2774
    ctx->r3 = ADD32(ctx->r3, -0X2774);
    // 0x8002C15C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8002C160: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002C164: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8002C168: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8002C16C: jal         0x80070EDC
    // 0x8002C170: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x8002C170: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    after_2:
    // 0x8002C174: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002C178: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8002C17C: sw          $v0, -0x2710($at)
    MEM_W(-0X2710, ctx->r1) = ctx->r2;
    // 0x8002C180: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8002C184: jal         0x80070EDC
    // 0x8002C188: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8002C188: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    after_3:
    // 0x8002C18C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002C190: sw          $v0, -0x270C($at)
    MEM_W(-0X270C, ctx->r1) = ctx->r2;
    // 0x8002C194: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002C198: sw          $zero, -0x2708($at)
    MEM_W(-0X2708, ctx->r1) = 0;
    // 0x8002C19C: jal         0x80076EE4
    // 0x8002C1A0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x8002C1A0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_4:
    // 0x8002C1A4: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002C1A8: addiu       $s4, $s4, -0x2770
    ctx->r20 = ADD32(ctx->r20, -0X2770);
    // 0x8002C1AC: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x8002C1B0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8002C1B4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8002C1B8: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8002C1BC: beq         $v1, $t7, L_8002C1D4
    if (ctx->r3 == ctx->r15) {
        // 0x8002C1C0: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_8002C1D4;
    }
    // 0x8002C1C0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_8002C1C4:
    // 0x8002C1C4: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8002C1C8: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8002C1CC: bne         $v1, $t8, L_8002C1C4
    if (ctx->r3 != ctx->r24) {
        // 0x8002C1D0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8002C1C4;
    }
    // 0x8002C1D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002C1D4:
    // 0x8002C1D4: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x8002C1D8: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002C1DC: bne         $at, $zero, L_8002C1E8
    if (ctx->r1 != 0) {
        // 0x8002C1E0: addiu       $a0, $zero, 0x1B
        ctx->r4 = ADD32(0, 0X1B);
            goto L_8002C1E8;
    }
    // 0x8002C1E0: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x8002C1E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8002C1E8:
    // 0x8002C1E8: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x8002C1EC: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x8002C1F0: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8002C1F4: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8002C1F8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8002C1FC: subu        $s3, $t5, $a2
    ctx->r19 = SUB32(ctx->r13, ctx->r6);
    // 0x8002C200: addu        $t6, $s0, $s5
    ctx->r14 = ADD32(ctx->r16, ctx->r21);
    // 0x8002C204: subu        $s0, $t6, $s3
    ctx->r16 = SUB32(ctx->r14, ctx->r19);
    // 0x8002C208: bgez        $s0, L_8002C21C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8002C20C: andi        $t7, $s0, 0xF
        ctx->r15 = ctx->r16 & 0XF;
            goto L_8002C21C;
    }
    // 0x8002C20C: andi        $t7, $s0, 0xF
    ctx->r15 = ctx->r16 & 0XF;
    // 0x8002C210: beq         $t7, $zero, L_8002C21C
    if (ctx->r15 == 0) {
        // 0x8002C214: nop
    
            goto L_8002C21C;
    }
    // 0x8002C214: nop

    // 0x8002C218: addiu       $t7, $t7, -0x10
    ctx->r15 = ADD32(ctx->r15, -0X10);
L_8002C21C:
    // 0x8002C21C: subu        $s0, $s0, $t7
    ctx->r16 = SUB32(ctx->r16, ctx->r15);
    // 0x8002C220: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002C224: jal         0x80077190
    // 0x8002C228: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    asset_load(rdram, ctx);
        goto after_5;
    // 0x8002C228: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_5:
    // 0x8002C22C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8002C230: jal         0x800C6778
    // 0x8002C234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gzip_inflate(rdram, ctx);
        goto after_6;
    // 0x8002C234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8002C238: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x8002C23C: jal         0x80071380
    // 0x8002C240: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8002C240: nop

    after_7:
    // 0x8002C244: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C248: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002C24C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8002C250: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8002C254: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8002C258: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8002C25C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C260: nop

    // 0x8002C264: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x8002C268: nop

    // 0x8002C26C: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8002C270: sw          $t6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r14;
    // 0x8002C274: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C278: nop

    // 0x8002C27C: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x8002C280: nop

    // 0x8002C284: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x8002C288: sw          $t8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r24;
    // 0x8002C28C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C290: nop

    // 0x8002C294: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x8002C298: nop

    // 0x8002C29C: addu        $t5, $t9, $a2
    ctx->r13 = ADD32(ctx->r25, ctx->r6);
    // 0x8002C2A0: sw          $t5, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r13;
    // 0x8002C2A4: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C2A8: nop

    // 0x8002C2AC: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
    // 0x8002C2B0: nop

    // 0x8002C2B4: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x8002C2B8: sw          $t7, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r15;
    // 0x8002C2BC: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C2C0: nop

    // 0x8002C2C4: lw          $t8, 0x14($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X14);
    // 0x8002C2C8: nop

    // 0x8002C2CC: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8002C2D0: sw          $t9, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r25;
    // 0x8002C2D4: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C2D8: nop

    // 0x8002C2DC: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C2E0: nop

    // 0x8002C2E4: blez        $v1, L_8002C394
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002C2E8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8002C394;
    }
    // 0x8002C2E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8002C2EC:
    // 0x8002C2EC: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x8002C2F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C2F4: addu        $v0, $t5, $s3
    ctx->r2 = ADD32(ctx->r13, ctx->r19);
    // 0x8002C2F8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8002C2FC: nop

    // 0x8002C300: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x8002C304: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002C308: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8002C30C: nop

    // 0x8002C310: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8002C314: nop

    // 0x8002C318: addu        $v0, $t9, $s3
    ctx->r2 = ADD32(ctx->r25, ctx->r19);
    // 0x8002C31C: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8002C320: nop

    // 0x8002C324: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8002C328: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002C32C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8002C330: nop

    // 0x8002C334: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8002C338: nop

    // 0x8002C33C: addu        $v0, $t8, $s3
    ctx->r2 = ADD32(ctx->r24, ctx->r19);
    // 0x8002C340: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8002C344: nop

    // 0x8002C348: addu        $t5, $t9, $a2
    ctx->r13 = ADD32(ctx->r25, ctx->r6);
    // 0x8002C34C: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x8002C350: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C354: nop

    // 0x8002C358: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C35C: nop

    // 0x8002C360: addu        $v0, $t7, $s3
    ctx->r2 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C364: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x8002C368: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
    // 0x8002C36C: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8002C370: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x8002C374: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C378: nop

    // 0x8002C37C: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C380: nop

    // 0x8002C384: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002C388: bne         $at, $zero, L_8002C2EC
    if (ctx->r1 != 0) {
        // 0x8002C38C: nop
    
            goto L_8002C2EC;
    }
    // 0x8002C38C: nop

    // 0x8002C390: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002C394:
    // 0x8002C394: lh          $t5, 0x18($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X18);
    // 0x8002C398: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002C39C: blez        $t5, L_8002C400
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8002C3A0: nop
    
            goto L_8002C400;
    }
    // 0x8002C3A0: nop

L_8002C3A4:
    // 0x8002C3A4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8002C3A8: nop

    // 0x8002C3AC: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x8002C3B0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8002C3B4: nop

    // 0x8002C3B8: ori         $t8, $a0, 0x8000
    ctx->r24 = ctx->r4 | 0X8000;
    // 0x8002C3BC: jal         0x8007B2C4
    // 0x8002C3C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    load_texture(rdram, ctx);
        goto after_8;
    // 0x8002C3C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_8:
    // 0x8002C3C4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002C3C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C3CC: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8002C3D0: nop

    // 0x8002C3D4: addu        $t6, $t5, $s3
    ctx->r14 = ADD32(ctx->r13, ctx->r19);
    // 0x8002C3D8: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8002C3DC: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C3E0: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8002C3E4: lh          $t7, 0x18($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X18);
    // 0x8002C3E8: nop

    // 0x8002C3EC: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002C3F0: bne         $at, $zero, L_8002C3A4
    if (ctx->r1 != 0) {
        // 0x8002C3F4: nop
    
            goto L_8002C3A4;
    }
    // 0x8002C3F4: nop

    // 0x8002C3F8: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C3FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002C400:
    // 0x8002C400: lw          $t8, 0x48($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X48);
    // 0x8002C404: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8002C408: blez        $v1, L_8002C52C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002C40C: addu        $s4, $s2, $t8
        ctx->r20 = ADD32(ctx->r18, ctx->r24);
            goto L_8002C52C;
    }
    // 0x8002C40C: addu        $s4, $s2, $t8
    ctx->r20 = ADD32(ctx->r18, ctx->r24);
    // 0x8002C410: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002C414: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8002C418:
    // 0x8002C418: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x8002C41C: nop

    // 0x8002C420: addu        $t5, $t9, $s3
    ctx->r13 = ADD32(ctx->r25, ctx->r19);
    // 0x8002C424: sw          $s4, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r20;
    // 0x8002C428: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C42C: nop

    // 0x8002C430: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C434: nop

    // 0x8002C438: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C43C: lh          $t9, 0x1E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X1E);
    // 0x8002C440: nop

    // 0x8002C444: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8002C448: jal         0x80071A90
    // 0x8002C44C: addu        $a0, $t5, $s4
    ctx->r4 = ADD32(ctx->r13, ctx->r20);
    align16(rdram, ctx);
        goto after_9;
    // 0x8002C44C: addu        $a0, $t5, $s4
    ctx->r4 = ADD32(ctx->r13, ctx->r20);
    after_9:
    // 0x8002C450: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C454: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8002C458: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C45C: nop

    // 0x8002C460: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C464: sw          $v0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r2;
    // 0x8002C468: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002C46C: nop

    // 0x8002C470: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8002C474: jal         0x8002CC70
    // 0x8002C478: addu        $a0, $t5, $s3
    ctx->r4 = ADD32(ctx->r13, ctx->r19);
    track_init_collision(rdram, ctx);
        goto after_10;
    // 0x8002C478: addu        $a0, $t5, $s3
    ctx->r4 = ADD32(ctx->r13, ctx->r19);
    after_10:
    // 0x8002C47C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C480: addu        $s4, $v0, $s4
    ctx->r20 = ADD32(ctx->r2, ctx->r20);
    // 0x8002C484: lw          $t6, 0x4($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X4);
    // 0x8002C488: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x8002C48C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8002C490: addu        $a0, $t6, $s3
    ctx->r4 = ADD32(ctx->r14, ctx->r19);
    // 0x8002C494: jal         0x8002C994
    // 0x8002C498: addu        $a1, $t7, $s5
    ctx->r5 = ADD32(ctx->r15, ctx->r21);
    func_8002C954(rdram, ctx);
        goto after_11;
    // 0x8002C498: addu        $a1, $t7, $s5
    ctx->r5 = ADD32(ctx->r15, ctx->r21);
    after_11:
    // 0x8002C49C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8002C4A0: nop

    // 0x8002C4A4: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8002C4A8: nop

    // 0x8002C4AC: addu        $t5, $t9, $s3
    ctx->r13 = ADD32(ctx->r25, ctx->r19);
    // 0x8002C4B0: sh          $zero, 0x30($t5)
    MEM_H(0X30, ctx->r13) = 0;
    // 0x8002C4B4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C4B8: nop

    // 0x8002C4BC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C4C0: nop

    // 0x8002C4C4: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C4C8: sw          $s4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r20;
    // 0x8002C4CC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002C4D0: nop

    // 0x8002C4D4: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8002C4D8: jal         0x8002C75C
    // 0x8002C4DC: addu        $a0, $t5, $s3
    ctx->r4 = ADD32(ctx->r13, ctx->r19);
    func_8002C71C(rdram, ctx);
        goto after_12;
    // 0x8002C4DC: addu        $a0, $t5, $s3
    ctx->r4 = ADD32(ctx->r13, ctx->r19);
    after_12:
    // 0x8002C4E0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C4E4: nop

    // 0x8002C4E8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C4EC: nop

    // 0x8002C4F0: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C4F4: lh          $t9, 0x32($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X32);
    // 0x8002C4F8: nop

    // 0x8002C4FC: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8002C500: jal         0x80071A90
    // 0x8002C504: addu        $a0, $t5, $s4
    ctx->r4 = ADD32(ctx->r13, ctx->r20);
    align16(rdram, ctx);
        goto after_13;
    // 0x8002C504: addu        $a0, $t5, $s4
    ctx->r4 = ADD32(ctx->r13, ctx->r20);
    after_13:
    // 0x8002C508: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C50C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C510: lh          $t6, 0x1A($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C514: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
    // 0x8002C518: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002C51C: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x8002C520: bne         $at, $zero, L_8002C418
    if (ctx->r1 != 0) {
        // 0x8002C524: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_8002C418;
    }
    // 0x8002C524: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8002C528: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8002C52C:
    // 0x8002C52C: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8002C530: subu        $s3, $s4, $v0
    ctx->r19 = SUB32(ctx->r20, ctx->r2);
    // 0x8002C534: ori         $at, $at, 0x2A01
    ctx->r1 = ctx->r1 | 0X2A01;
    // 0x8002C538: slt         $at, $s3, $at
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8002C53C: bne         $at, $zero, L_8002C550
    if (ctx->r1 != 0) {
        // 0x8002C540: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8002C550;
    }
    // 0x8002C540: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8002C544: addiu       $a0, $a0, 0x63C8
    ctx->r4 = ADD32(ctx->r4, 0X63C8);
    // 0x8002C548: jal         0x800CA2B4
    // 0x8002C54C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_14;
    // 0x8002C54C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_14:
L_8002C550:
    // 0x8002C550: jal         0x800712F0
    // 0x8002C554: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_15;
    // 0x8002C554: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x8002C558: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C55C: lw          $a0, -0x2774($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2774);
    // 0x8002C560: jal         0x80071380
    // 0x8002C564: nop

    mempool_free(rdram, ctx);
        goto after_16;
    // 0x8002C564: nop

    after_16:
    // 0x8002C568: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002C56C: lw          $a1, -0x2774($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2774);
    // 0x8002C570: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x8002C574: ori         $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 | 0XFF;
    // 0x8002C578: jal         0x80071138
    // 0x8002C57C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mempool_alloc_fixed(rdram, ctx);
        goto after_17;
    // 0x8002C57C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_17:
    // 0x8002C580: jal         0x800712F0
    // 0x8002C584: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_18;
    // 0x8002C584: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_18:
    // 0x8002C588: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002C58C: jal         0x800A8910
    // 0x8002C590: nop

    minimap_init(rdram, ctx);
        goto after_19;
    // 0x8002C590: nop

    after_19:
    // 0x8002C594: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C598: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8002C59C: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C5A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C5A4: blez        $v1, L_8002C72C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002C5A8: lui         $t3, 0x800
        ctx->r11 = S32(0X800 << 16);
            goto L_8002C72C;
    }
    // 0x8002C5A8: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x8002C5AC: lw          $a2, 0x4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4);
    // 0x8002C5B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002C5B4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
L_8002C5B8:
    // 0x8002C5B8: lh          $v0, 0x20($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X20);
    // 0x8002C5BC: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8002C5C0: blez        $v0, L_8002C71C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002C5C4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8002C71C;
    }
    // 0x8002C5C4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002C5C8: lw          $a0, 0xC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC);
    // 0x8002C5CC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8002C5D0:
    // 0x8002C5D0: lh          $s0, 0x2($a0)
    ctx->r16 = MEM_H(ctx->r4, 0X2);
    // 0x8002C5D4: lh          $t1, 0xE($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XE);
    // 0x8002C5D8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8002C5DC: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002C5E0: beq         $at, $zero, L_8002C708
    if (ctx->r1 == 0) {
        // 0x8002C5E4: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002C708;
    }
    // 0x8002C5E4: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002C5E8: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8002C5EC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8002C5F0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8002C5F4:
    // 0x8002C5F4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8002C5F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C5FC: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x8002C600: lbu         $t8, 0x6($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X6);
    // 0x8002C604: nop

    // 0x8002C608: bne         $t2, $t8, L_8002C6F4
    if (ctx->r10 != ctx->r24) {
        // 0x8002C60C: slt         $at, $s0, $t1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8002C6F4;
    }
    // 0x8002C60C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002C610: lbu         $t9, 0x7($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X7);
    // 0x8002C614: nop

    // 0x8002C618: bne         $t2, $t9, L_8002C6F4
    if (ctx->r10 != ctx->r25) {
        // 0x8002C61C: slt         $at, $s0, $t1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8002C6F4;
    }
    // 0x8002C61C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002C620: lbu         $t5, 0x8($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X8);
    // 0x8002C624: nop

    // 0x8002C628: sb          $t5, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r13;
    // 0x8002C62C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C630: nop

    // 0x8002C634: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C638: nop

    // 0x8002C63C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C640: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002C644: nop

    // 0x8002C648: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x8002C64C: sb          $a3, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r7;
    // 0x8002C650: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C654: nop

    // 0x8002C658: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C65C: nop

    // 0x8002C660: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C664: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002C668: nop

    // 0x8002C66C: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x8002C670: sb          $a3, 0x7($t5)
    MEM_B(0X7, ctx->r13) = ctx->r7;
    // 0x8002C674: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C678: nop

    // 0x8002C67C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C680: nop

    // 0x8002C684: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C688: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002C68C: nop

    // 0x8002C690: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x8002C694: sb          $a3, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r7;
    // 0x8002C698: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C69C: nop

    // 0x8002C6A0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C6A4: nop

    // 0x8002C6A8: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C6AC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8002C6B0: nop

    // 0x8002C6B4: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x8002C6B8: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x8002C6BC: nop

    // 0x8002C6C0: or          $t6, $t5, $t3
    ctx->r14 = ctx->r13 | ctx->r11;
    // 0x8002C6C4: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x8002C6C8: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C6CC: nop

    // 0x8002C6D0: lw          $t7, 0x4($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X4);
    // 0x8002C6D4: nop

    // 0x8002C6D8: addu        $a2, $t7, $a1
    ctx->r6 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C6DC: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x8002C6E0: nop

    // 0x8002C6E4: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    // 0x8002C6E8: lh          $t1, 0xE($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XE);
    // 0x8002C6EC: nop

    // 0x8002C6F0: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
L_8002C6F4:
    // 0x8002C6F4: bne         $at, $zero, L_8002C5F4
    if (ctx->r1 != 0) {
        // 0x8002C6F8: addiu       $v0, $v0, 0xA
        ctx->r2 = ADD32(ctx->r2, 0XA);
            goto L_8002C5F4;
    }
    // 0x8002C6F8: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8002C6FC: lh          $v0, 0x20($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X20);
    // 0x8002C700: nop

    // 0x8002C704: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
L_8002C708:
    // 0x8002C708: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8002C70C: bne         $at, $zero, L_8002C5D0
    if (ctx->r1 != 0) {
        // 0x8002C710: addiu       $a0, $a0, 0xC
        ctx->r4 = ADD32(ctx->r4, 0XC);
            goto L_8002C5D0;
    }
    // 0x8002C710: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x8002C714: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C718: nop

L_8002C71C:
    // 0x8002C71C: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002C720: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    // 0x8002C724: bne         $at, $zero, L_8002C5B8
    if (ctx->r1 != 0) {
        // 0x8002C728: addiu       $a2, $a2, 0x44
        ctx->r6 = ADD32(ctx->r6, 0X44);
            goto L_8002C5B8;
    }
    // 0x8002C728: addiu       $a2, $a2, 0x44
    ctx->r6 = ADD32(ctx->r6, 0X44);
L_8002C72C:
    // 0x8002C72C: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x8002C730: jal         0x8007B7C4
    // 0x8002C734: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    set_texture_colour_tag(rdram, ctx);
        goto after_20;
    // 0x8002C734: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_20:
    // 0x8002C738: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C73C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002C740: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002C744: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C748: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002C74C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8002C750: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8002C754: jr          $ra
    // 0x8002C758: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002C758: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8002C71C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C75C: lh          $t6, 0x20($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X20);
    // 0x8002C760: addiu       $t0, $zero, -0x2710
    ctx->r8 = ADD32(0, -0X2710);
    // 0x8002C764: sh          $t0, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r8;
    // 0x8002C768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002C76C: blez        $t6, L_8002C7FC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002C770: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002C7FC;
    }
    // 0x8002C770: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002C774: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C778: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
L_8002C77C:
    // 0x8002C77C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8002C780: nop

    // 0x8002C784: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C788: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8002C78C: nop

    // 0x8002C790: andi        $t2, $t9, 0x2000
    ctx->r10 = ctx->r25 & 0X2000;
    // 0x8002C794: beq         $t2, $zero, L_8002C7E8
    if (ctx->r10 == 0) {
        // 0x8002C798: nop
    
            goto L_8002C7E8;
    }
    // 0x8002C798: nop

    // 0x8002C79C: lw          $t3, 0x34($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X34);
    // 0x8002C7A0: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8002C7A4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8002C7A8: sh          $v1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r3;
    // 0x8002C7AC: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8002C7B0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8002C7B4: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C7B8: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x8002C7BC: lh          $a3, 0x38($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X38);
    // 0x8002C7C0: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002C7C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002C7C8: mflo        $t2
    ctx->r10 = lo;
    // 0x8002C7CC: addu        $t3, $t6, $t2
    ctx->r11 = ADD32(ctx->r14, ctx->r10);
    // 0x8002C7D0: lh          $a2, 0x2($t3)
    ctx->r6 = MEM_H(ctx->r11, 0X2);
    // 0x8002C7D4: beq         $t0, $a3, L_8002C7E4
    if (ctx->r8 == ctx->r7) {
        // 0x8002C7D8: slt         $at, $a3, $a2
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8002C7E4;
    }
    // 0x8002C7D8: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002C7DC: beq         $at, $zero, L_8002C7E8
    if (ctx->r1 == 0) {
        // 0x8002C7E0: nop
    
            goto L_8002C7E8;
    }
    // 0x8002C7E0: nop

L_8002C7E4:
    // 0x8002C7E4: sh          $a2, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r6;
L_8002C7E8:
    // 0x8002C7E8: lh          $t4, 0x20($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X20);
    // 0x8002C7EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002C7F0: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002C7F4: bne         $at, $zero, L_8002C77C
    if (ctx->r1 != 0) {
        // 0x8002C7F8: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8002C77C;
    }
    // 0x8002C7F8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_8002C7FC:
    // 0x8002C7FC: jr          $ra
    // 0x8002C800: sh          $v0, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r2;
    return;
    // 0x8002C800: sh          $v0, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void get_current_level_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C804: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8002C808: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x8002C80C: jr          $ra
    // 0x8002C810: nop

    return;
    // 0x8002C810: nop

;}
RECOMP_FUNC void free_track(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C814: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002C818: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002C81C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002C820: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002C824: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002C828: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002C82C: jal         0x8000B290
    // 0x8002C830: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    racerfx_free(rdram, ctx);
        goto after_0;
    // 0x8002C830: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8002C834: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002C838: lw          $t6, -0x26FC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26FC);
    // 0x8002C83C: nop

    // 0x8002C840: beq         $t6, $zero, L_8002C850
    if (ctx->r14 == 0) {
        // 0x8002C844: nop
    
            goto L_8002C850;
    }
    // 0x8002C844: nop

    // 0x8002C848: jal         0x800B8240
    // 0x8002C84C: nop

    waves_free(rdram, ctx);
        goto after_1;
    // 0x8002C84C: nop

    after_1:
L_8002C850:
    // 0x8002C850: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8002C854: addiu       $s4, $s4, -0x3178
    ctx->r20 = ADD32(ctx->r20, -0X3178);
    // 0x8002C858: lw          $s1, 0x0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X0);
    // 0x8002C85C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002C860: lh          $t7, 0x18($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X18);
    // 0x8002C864: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002C868: blez        $t7, L_8002C8A4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8002C86C: nop
    
            goto L_8002C8A4;
    }
    // 0x8002C86C: nop

L_8002C870:
    // 0x8002C870: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8002C874: nop

    // 0x8002C878: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8002C87C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8002C880: jal         0x8007B70C
    // 0x8002C884: nop

    tex_free(rdram, ctx);
        goto after_2;
    // 0x8002C884: nop

    after_2:
    // 0x8002C888: lw          $s1, 0x0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X0);
    // 0x8002C88C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C890: lh          $t0, 0x18($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X18);
    // 0x8002C894: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8002C898: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002C89C: bne         $at, $zero, L_8002C870
    if (ctx->r1 != 0) {
        // 0x8002C8A0: nop
    
            goto L_8002C870;
    }
    // 0x8002C8A0: nop

L_8002C8A4:
    // 0x8002C8A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C8A8: lw          $a0, -0x2774($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2774);
    // 0x8002C8AC: jal         0x80071380
    // 0x8002C8B0: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x8002C8B0: nop

    after_3:
    // 0x8002C8B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C8B8: lw          $a0, -0x2710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2710);
    // 0x8002C8BC: jal         0x80071380
    // 0x8002C8C0: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x8002C8C0: nop

    after_4:
    // 0x8002C8C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C8C8: lw          $a0, -0x270C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X270C);
    // 0x8002C8CC: jal         0x80071380
    // 0x8002C8D0: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8002C8D0: nop

    after_5:
    // 0x8002C8D4: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x8002C8D8: nop

    // 0x8002C8DC: lw          $a0, 0x20($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X20);
    // 0x8002C8E0: jal         0x8007D100
    // 0x8002C8E4: nop

    sprite_free(rdram, ctx);
        goto after_6;
    // 0x8002C8E4: nop

    after_6:
    // 0x8002C8E8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002C8EC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8002C8F0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002C8F4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002C8F8: addiu       $s3, $s3, -0x2738
    ctx->r19 = ADD32(ctx->r19, -0X2738);
    // 0x8002C8FC: addiu       $s0, $s0, -0x2748
    ctx->r16 = ADD32(ctx->r16, -0X2748);
    // 0x8002C900: addiu       $s2, $s2, -0x2760
    ctx->r18 = ADD32(ctx->r18, -0X2760);
    // 0x8002C904: addiu       $s1, $s1, -0x2730
    ctx->r17 = ADD32(ctx->r17, -0X2730);
L_8002C908:
    // 0x8002C908: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002C90C: jal         0x80071380
    // 0x8002C910: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8002C910: nop

    after_7:
    // 0x8002C914: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8002C918: jal         0x80071380
    // 0x8002C91C: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8002C91C: nop

    after_8:
    // 0x8002C920: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002C924: jal         0x80071380
    // 0x8002C928: nop

    mempool_free(rdram, ctx);
        goto after_9;
    // 0x8002C928: nop

    after_9:
    // 0x8002C92C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8002C930: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002C934: bne         $s0, $s3, L_8002C908
    if (ctx->r16 != ctx->r19) {
        // 0x8002C938: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8002C908;
    }
    // 0x8002C938: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8002C93C: jal         0x80025810
    // 0x8002C940: nop

    void_free(rdram, ctx);
        goto after_10;
    // 0x8002C940: nop

    after_10:
    // 0x8002C944: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C948: lw          $a0, -0x49C8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X49C8);
    // 0x8002C94C: nop

    // 0x8002C950: beq         $a0, $zero, L_8002C968
    if (ctx->r4 == 0) {
        // 0x8002C954: nop
    
            goto L_8002C968;
    }
    // 0x8002C954: nop

    // 0x8002C958: jal         0x8000FFB8
    // 0x8002C95C: nop

    free_object(rdram, ctx);
        goto after_11;
    // 0x8002C95C: nop

    after_11:
    // 0x8002C960: jal         0x8001004C
    // 0x8002C964: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_12;
    // 0x8002C964: nop

    after_12:
L_8002C968:
    // 0x8002C968: jal         0x8000C604
    // 0x8002C96C: nop

    free_all_objects(rdram, ctx);
        goto after_13;
    // 0x8002C96C: nop

    after_13:
    // 0x8002C970: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C974: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x8002C978: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002C97C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002C980: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C984: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002C988: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002C98C: jr          $ra
    // 0x8002C990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002C990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8002C954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C994: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002C998: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002C99C: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8002C9A0: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8002C9A4: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8002C9A8: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8002C9AC: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8002C9B0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8002C9B4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8002C9B8: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002C9BC: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002C9C0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002C9C4: lh          $v0, 0x20($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X20);
    // 0x8002C9C8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8002C9CC: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8002C9D0: blez        $v0, L_8002CC40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002C9D4: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8002CC40;
    }
    // 0x8002C9D4: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002C9D8: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8002C9DC: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8002C9E0: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
L_8002C9E4:
    // 0x8002C9E4: lw          $t6, 0xC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XC);
    // 0x8002C9E8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002C9EC: addu        $a0, $t6, $fp
    ctx->r4 = ADD32(ctx->r14, ctx->r30);
    // 0x8002C9F0: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
    // 0x8002C9F4: lh          $s6, 0x10($a0)
    ctx->r22 = MEM_H(ctx->r4, 0X10);
    // 0x8002C9F8: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x8002C9FC: slt         $at, $v1, $s6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002CA00: beq         $at, $zero, L_8002CC34
    if (ctx->r1 == 0) {
        // 0x8002CA04: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8002CC34;
    }
    // 0x8002CA04: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8002CA08: sll         $s5, $v1, 4
    ctx->r21 = S32(ctx->r3 << 4);
    // 0x8002CA0C: sll         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3 << 1);
L_8002CA10:
    // 0x8002CA10: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8002CA14: addiu       $a3, $zero, -0x7D00
    ctx->r7 = ADD32(0, -0X7D00);
    // 0x8002CA18: addu        $t7, $v0, $s5
    ctx->r15 = ADD32(ctx->r2, ctx->r21);
    // 0x8002CA1C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8002CA20: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x8002CA24: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x8002CA28: beq         $t9, $zero, L_8002CA44
    if (ctx->r25 == 0) {
        // 0x8002CA2C: addiu       $t2, $zero, -0x7D00
        ctx->r10 = ADD32(0, -0X7D00);
            goto L_8002CA44;
    }
    // 0x8002CA2C: addiu       $t2, $zero, -0x7D00
    ctx->r10 = ADD32(0, -0X7D00);
    // 0x8002CA30: lw          $t6, 0x10($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X10);
    // 0x8002CA34: nop

    // 0x8002CA38: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x8002CA3C: b           L_8002CC1C
    // 0x8002CA40: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
        goto L_8002CC1C;
    // 0x8002CA40: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
L_8002CA44:
    // 0x8002CA44: sll         $t8, $s1, 4
    ctx->r24 = S32(ctx->r17 << 4);
    // 0x8002CA48: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x8002CA4C: addiu       $t3, $zero, 0x7D00
    ctx->r11 = ADD32(0, 0X7D00);
    // 0x8002CA50: addiu       $t0, $zero, 0x7D00
    ctx->r8 = ADD32(0, 0X7D00);
    // 0x8002CA54: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // 0x8002CA58: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002CA5C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8002CA60:
    // 0x8002CA60: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8002CA64: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002CA68: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x8002CA6C: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CA70: mflo        $t7
    ctx->r15 = lo;
    // 0x8002CA74: addu        $a2, $t7, $a1
    ctx->r6 = ADD32(ctx->r15, ctx->r5);
    // 0x8002CA78: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x8002CA7C: lh          $ra, 0x4($a2)
    ctx->r31 = MEM_H(ctx->r6, 0X4);
    // 0x8002CA80: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002CA84: beq         $at, $zero, L_8002CA9C
    if (ctx->r1 == 0) {
        // 0x8002CA88: slt         $at, $v0, $t0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_8002CA9C;
    }
    // 0x8002CA88: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002CA8C: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8002CA90: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8002CA94: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8002CA98: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
L_8002CA9C:
    // 0x8002CA9C: beq         $at, $zero, L_8002CAB4
    if (ctx->r1 == 0) {
        // 0x8002CAA0: slt         $at, $t2, $ra
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r31) ? 1 : 0;
            goto L_8002CAB4;
    }
    // 0x8002CAA0: slt         $at, $t2, $ra
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x8002CAA4: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8002CAA8: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8002CAAC: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x8002CAB0: slt         $at, $t2, $ra
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r31) ? 1 : 0;
L_8002CAB4:
    // 0x8002CAB4: beq         $at, $zero, L_8002CACC
    if (ctx->r1 == 0) {
        // 0x8002CAB8: slt         $at, $ra, $t3
        ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_8002CACC;
    }
    // 0x8002CAB8: slt         $at, $ra, $t3
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002CABC: sll         $t2, $ra, 16
    ctx->r10 = S32(ctx->r31 << 16);
    // 0x8002CAC0: sra         $t6, $t2, 16
    ctx->r14 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8002CAC4: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x8002CAC8: slt         $at, $ra, $t3
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
L_8002CACC:
    // 0x8002CACC: beq         $at, $zero, L_8002CAE0
    if (ctx->r1 == 0) {
        // 0x8002CAD0: nop
    
            goto L_8002CAE0;
    }
    // 0x8002CAD0: nop

    // 0x8002CAD4: sll         $t3, $ra, 16
    ctx->r11 = S32(ctx->r31 << 16);
    // 0x8002CAD8: sra         $t7, $t3, 16
    ctx->r15 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8002CADC: or          $t3, $t7, $zero
    ctx->r11 = ctx->r15 | 0;
L_8002CAE0:
    // 0x8002CAE0: bne         $v1, $s0, L_8002CA60
    if (ctx->r3 != ctx->r16) {
        // 0x8002CAE4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8002CA60;
    }
    // 0x8002CAE4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002CAE8: lh          $ra, 0x0($s4)
    ctx->r31 = MEM_H(ctx->r20, 0X0);
    // 0x8002CAEC: lh          $t8, 0x6($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X6);
    // 0x8002CAF0: sll         $a0, $ra, 16
    ctx->r4 = S32(ctx->r31 << 16);
    // 0x8002CAF4: subu        $a2, $t8, $ra
    ctx->r6 = SUB32(ctx->r24, ctx->r31);
    // 0x8002CAF8: sra         $t9, $a2, 3
    ctx->r25 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002CAFC: addiu       $a2, $t9, 0x1
    ctx->r6 = ADD32(ctx->r25, 0X1);
    // 0x8002CB00: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8002CB04: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002CB08: addu        $v1, $a2, $ra
    ctx->r3 = ADD32(ctx->r6, ctx->r31);
    // 0x8002CB0C: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x8002CB10: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002CB14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002CB18: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002CB1C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8002CB20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002CB24:
    // 0x8002CB24: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002CB28: bne         $at, $zero, L_8002CB48
    if (ctx->r1 != 0) {
        // 0x8002CB2C: addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
            goto L_8002CB48;
    }
    // 0x8002CB2C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002CB30: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002CB34: bne         $at, $zero, L_8002CB48
    if (ctx->r1 != 0) {
        // 0x8002CB38: nop
    
            goto L_8002CB48;
    }
    // 0x8002CB38: nop

    // 0x8002CB3C: or          $t1, $t1, $a1
    ctx->r9 = ctx->r9 | ctx->r5;
    // 0x8002CB40: sll         $t7, $t1, 16
    ctx->r15 = S32(ctx->r9 << 16);
    // 0x8002CB44: sra         $t1, $t7, 16
    ctx->r9 = S32(SIGNED(ctx->r15) >> 16);
L_8002CB48:
    // 0x8002CB48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002CB4C: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8002CB50: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8002CB54: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002CB58: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002CB5C: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002CB60: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8002CB64: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8002CB68: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8002CB6C: sll         $t6, $t9, 17
    ctx->r14 = S32(ctx->r25 << 17);
    // 0x8002CB70: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002CB74: bne         $at, $zero, L_8002CB24
    if (ctx->r1 != 0) {
        // 0x8002CB78: sra         $a1, $t6, 16
        ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8002CB24;
    }
    // 0x8002CB78: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002CB7C: lh          $a3, 0x4($s4)
    ctx->r7 = MEM_H(ctx->r20, 0X4);
    // 0x8002CB80: lh          $t6, 0xA($s4)
    ctx->r14 = MEM_H(ctx->r20, 0XA);
    // 0x8002CB84: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8002CB88: subu        $a2, $t6, $a3
    ctx->r6 = SUB32(ctx->r14, ctx->r7);
    // 0x8002CB8C: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002CB90: addiu       $a2, $t7, 0x1
    ctx->r6 = ADD32(ctx->r15, 0X1);
    // 0x8002CB94: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002CB98: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002CB9C: addu        $v1, $a2, $a3
    ctx->r3 = ADD32(ctx->r6, ctx->r7);
    // 0x8002CBA0: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8002CBA4: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002CBA8: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002CBAC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8002CBB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002CBB4:
    // 0x8002CBB4: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002CBB8: bne         $at, $zero, L_8002CBD8
    if (ctx->r1 != 0) {
        // 0x8002CBBC: addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
            goto L_8002CBD8;
    }
    // 0x8002CBBC: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002CBC0: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002CBC4: bne         $at, $zero, L_8002CBD8
    if (ctx->r1 != 0) {
        // 0x8002CBC8: nop
    
            goto L_8002CBD8;
    }
    // 0x8002CBC8: nop

    // 0x8002CBCC: or          $t1, $t1, $a1
    ctx->r9 = ctx->r9 | ctx->r5;
    // 0x8002CBD0: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8002CBD4: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
L_8002CBD8:
    // 0x8002CBD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002CBDC: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8002CBE0: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8002CBE4: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002CBE8: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002CBEC: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002CBF0: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002CBF4: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8002CBF8: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8002CBFC: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8002CC00: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002CC04: bne         $at, $zero, L_8002CBB4
    if (ctx->r1 != 0) {
        // 0x8002CC08: sra         $a1, $t8, 16
        ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8002CBB4;
    }
    // 0x8002CC08: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002CC0C: lw          $t8, 0x10($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X10);
    // 0x8002CC10: nop

    // 0x8002CC14: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8002CC18: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
L_8002CC1C:
    // 0x8002CC1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002CC20: slt         $at, $s1, $s6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002CC24: bne         $at, $zero, L_8002CA10
    if (ctx->r1 != 0) {
        // 0x8002CC28: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_8002CA10;
    }
    // 0x8002CC28: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8002CC2C: lh          $v0, 0x20($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X20);
    // 0x8002CC30: nop

L_8002CC34:
    // 0x8002CC34: slt         $at, $s7, $v0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002CC38: bne         $at, $zero, L_8002C9E4
    if (ctx->r1 != 0) {
        // 0x8002CC3C: addiu       $fp, $fp, 0xC
        ctx->r30 = ADD32(ctx->r30, 0XC);
            goto L_8002C9E4;
    }
    // 0x8002CC3C: addiu       $fp, $fp, 0xC
    ctx->r30 = ADD32(ctx->r30, 0XC);
L_8002CC40:
    // 0x8002CC40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CC44: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002CC48: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002CC4C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8002CC50: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8002CC54: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8002CC58: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CC5C: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8002CC60: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8002CC64: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8002CC68: jr          $ra
    // 0x8002CC6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002CC6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void track_init_collision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CC70: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8002CC74: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8002CC78: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8002CC7C: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8002CC80: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8002CC84: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8002CC88: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8002CC8C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8002CC90: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8002CC94: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8002CC98: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8002CC9C: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8002CCA0: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x8002CCA4: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002CCA8: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8002CCAC: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002CCB0: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8002CCB4: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002CCB8: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8002CCBC: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002CCC0: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002CCC4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002CCC8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002CCCC: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
    // 0x8002CCD0: lh          $a1, 0x20($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X20);
    // 0x8002CCD4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8002CCD8: blez        $a1, L_8002CF58
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002CCDC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8002CF58;
    }
    // 0x8002CCDC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8002CCE0: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8002CCE4: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_8002CCE8:
    // 0x8002CCE8: lw          $t6, 0xC($s2)
    ctx->r14 = MEM_W(ctx->r18, 0XC);
    // 0x8002CCEC: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8002CCF0: nop

    // 0x8002CCF4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8002CCF8: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x8002CCFC: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8002CD00: lh          $fp, 0x2($v0)
    ctx->r30 = MEM_H(ctx->r2, 0X2);
    // 0x8002CD04: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002CD08: beq         $at, $zero, L_8002CF38
    if (ctx->r1 == 0) {
        // 0x8002CD0C: sw          $t8, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = ctx->r24;
            goto L_8002CF38;
    }
    // 0x8002CD0C: sw          $t8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r24;
    // 0x8002CD10: sll         $a1, $v1, 4
    ctx->r5 = S32(ctx->r3 << 4);
    // 0x8002CD14: sll         $s0, $t8, 4
    ctx->r16 = S32(ctx->r24 << 4);
L_8002CD18:
    // 0x8002CD18: lw          $t2, 0x4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X4);
    // 0x8002CD1C: nop

    // 0x8002CD20: addu        $v1, $t2, $a1
    ctx->r3 = ADD32(ctx->r10, ctx->r5);
    // 0x8002CD24: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x8002CD28: nop

    // 0x8002CD2C: andi        $t4, $t3, 0x80
    ctx->r12 = ctx->r11 & 0X80;
    // 0x8002CD30: bne         $t4, $zero, L_8002CF20
    if (ctx->r12 != 0) {
        // 0x8002CD34: nop
    
            goto L_8002CF20;
    }
    // 0x8002CD34: nop

    // 0x8002CD38: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x8002CD3C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8002CD40: addu        $t6, $t5, $fp
    ctx->r14 = ADD32(ctx->r13, ctx->r30);
    // 0x8002CD44: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CD48: mflo        $t7
    ctx->r15 = lo;
    // 0x8002CD4C: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x8002CD50: lh          $t2, 0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4);
    // 0x8002CD54: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8002CD58: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8002CD5C: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8002CD60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002CD64: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8002CD68: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8002CD6C: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x8002CD70: lbu         $t3, 0x2($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2);
    // 0x8002CD74: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x8002CD78: addu        $t4, $t3, $fp
    ctx->r12 = ADD32(ctx->r11, ctx->r30);
    // 0x8002CD7C: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CD80: addu        $t2, $t9, $fp
    ctx->r10 = ADD32(ctx->r25, ctx->r30);
    // 0x8002CD84: cvt.s.w     $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002CD88: lwc1        $f26, 0xBC($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002CD8C: cvt.s.w     $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    ctx->f28.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002CD90: mflo        $t5
    ctx->r13 = lo;
    // 0x8002CD94: addu        $v0, $t5, $a0
    ctx->r2 = ADD32(ctx->r13, ctx->r4);
    // 0x8002CD98: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8002CD9C: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CDA0: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8002CDA4: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8002CDA8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002CDAC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8002CDB0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8002CDB4: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002CDB8: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002CDBC: mflo        $t3
    ctx->r11 = lo;
    // 0x8002CDC0: addu        $v0, $t3, $a0
    ctx->r2 = ADD32(ctx->r11, ctx->r4);
    // 0x8002CDC4: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8002CDC8: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8002CDCC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8002CDD0: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8002CDD4: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002CDD8: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8002CDDC: sw          $a1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r5;
    // 0x8002CDE0: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002CDE4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8002CDE8: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8002CDEC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002CDF0: mul.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f30.fl);
    // 0x8002CDF4: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002CDF8: sub.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x8002CDFC: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8002CE00: sub.s       $f4, $f26, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f14.fl;
    // 0x8002CE04: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002CE08: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002CE0C: sub.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8002CE10: mul.s       $f4, $f6, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x8002CE14: add.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002CE18: swc1        $f20, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f20.u32l;
    // 0x8002CE1C: sub.s       $f8, $f16, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f28.fl;
    // 0x8002CE20: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8002CE24: sub.s       $f8, $f28, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f28.fl - ctx->f2.fl;
    // 0x8002CE28: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002CE2C: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8002CE30: sub.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8002CE34: mul.s       $f8, $f10, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x8002CE38: add.s       $f22, $f6, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002CE3C: swc1        $f22, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f22.u32l;
    // 0x8002CE40: sub.s       $f6, $f18, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f30.fl;
    // 0x8002CE44: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8002CE48: sub.s       $f6, $f30, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f30.fl - ctx->f12.fl;
    // 0x8002CE4C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8002CE50: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8002CE54: nop

    // 0x8002CE58: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8002CE5C: add.s       $f24, $f10, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002CE60: swc1        $f24, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f24.u32l;
    // 0x8002CE64: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8002CE68: nop

    // 0x8002CE6C: mul.s       $f8, $f24, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8002CE70: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002CE74: jal         0x800CA030
    // 0x8002CE78: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8002CE78: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x8002CE7C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8002CE80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002CE84: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8002CE88: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8002CE8C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8002CE90: bc1f        L_8002CEB8
    if (!c1cs) {
        // 0x8002CE94: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_8002CEB8;
    }
    // 0x8002CE94: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8002CE98: nop

    // 0x8002CE9C: div.s       $f14, $f20, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8002CEA0: nop

    // 0x8002CEA4: div.s       $f12, $f22, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8002CEA8: swc1        $f14, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f14.u32l;
    // 0x8002CEAC: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8002CEB0: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x8002CEB4: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
L_8002CEB8:
    // 0x8002CEB8: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x8002CEBC: lwc1        $f14, 0xA0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002CEC0: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8002CEC4: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8002CEC8: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8002CECC: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8002CED0: swc1        $f14, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f14.u32l;
    // 0x8002CED4: lw          $t2, 0x18($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X18);
    // 0x8002CED8: mul.s       $f10, $f28, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f14.fl);
    // 0x8002CEDC: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x8002CEE0: swc1        $f12, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f12.u32l;
    // 0x8002CEE4: lw          $t4, 0x18($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X18);
    // 0x8002CEE8: mul.s       $f8, $f30, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f12.fl);
    // 0x8002CEEC: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x8002CEF0: swc1        $f2, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f2.u32l;
    // 0x8002CEF4: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002CEF8: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002CEFC: lw          $t6, 0x18($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X18);
    // 0x8002CF00: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8002CF04: addu        $t7, $t6, $t7
    ctx->r15 = ADD32(ctx->r14, ctx->r15);
    // 0x8002CF08: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002CF0C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002CF10: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x8002CF14: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x8002CF18: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8002CF1C: nop

L_8002CF20:
    // 0x8002CF20: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8002CF24: slt         $at, $a1, $s0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002CF28: bne         $at, $zero, L_8002CD18
    if (ctx->r1 != 0) {
        // 0x8002CF2C: nop
    
            goto L_8002CD18;
    }
    // 0x8002CF2C: nop

    // 0x8002CF30: lh          $a1, 0x20($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X20);
    // 0x8002CF34: nop

L_8002CF38:
    // 0x8002CF38: lw          $t8, 0xEC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XEC);
    // 0x8002CF3C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8002CF40: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002CF44: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002CF48: addiu       $t3, $t2, 0xC
    ctx->r11 = ADD32(ctx->r10, 0XC);
    // 0x8002CF4C: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x8002CF50: bne         $at, $zero, L_8002CCE8
    if (ctx->r1 != 0) {
        // 0x8002CF54: sw          $t9, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r25;
            goto L_8002CCE8;
    }
    // 0x8002CF54: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
L_8002CF58:
    // 0x8002CF58: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002CF5C: lw          $t4, -0x4988($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4988);
    // 0x8002CF60: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8002CF64: beq         $t4, $zero, L_8002CF74
    if (ctx->r12 == 0) {
        // 0x8002CF68: or          $t1, $s4, $zero
        ctx->r9 = ctx->r20 | 0;
            goto L_8002CF74;
    }
    // 0x8002CF68: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
    // 0x8002CF6C: b           L_8002D2EC
    // 0x8002CF70: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
        goto L_8002D2EC;
    // 0x8002CF70: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
L_8002CF74:
    // 0x8002CF74: blez        $a1, L_8002D2E8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002CF78: sw          $zero, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = 0;
            goto L_8002D2E8;
    }
    // 0x8002CF78: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
    // 0x8002CF7C: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8002CF80: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_8002CF84:
    // 0x8002CF84: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x8002CF88: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8002CF8C: nop

    // 0x8002CF90: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8002CF94: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x8002CF98: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x8002CF9C: lh          $fp, 0x2($v0)
    ctx->r30 = MEM_H(ctx->r2, 0X2);
    // 0x8002CFA0: sw          $t7, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r15;
    // 0x8002CFA4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8002CFA8: lw          $t3, 0xF4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF4);
    // 0x8002CFAC: andi        $t2, $t8, 0x200
    ctx->r10 = ctx->r24 & 0X200;
    // 0x8002CFB0: beq         $t2, $zero, L_8002CFC0
    if (ctx->r10 == 0) {
        // 0x8002CFB4: slt         $at, $v1, $t3
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_8002CFC0;
    }
    // 0x8002CFB4: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002CFB8: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8002CFBC: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
L_8002CFC0:
    // 0x8002CFC0: beq         $at, $zero, L_8002D2C8
    if (ctx->r1 == 0) {
        // 0x8002CFC4: or          $s7, $v1, $zero
        ctx->r23 = ctx->r3 | 0;
            goto L_8002D2C8;
    }
    // 0x8002CFC4: or          $s7, $v1, $zero
    ctx->r23 = ctx->r3 | 0;
    // 0x8002CFC8: sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3 << 4);
L_8002CFCC:
    // 0x8002CFCC: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x8002CFD0: nop

    // 0x8002CFD4: addu        $t4, $t9, $a0
    ctx->r12 = ADD32(ctx->r25, ctx->r4);
    // 0x8002CFD8: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8002CFDC: nop

    // 0x8002CFE0: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x8002CFE4: bne         $t6, $zero, L_8002D2B4
    if (ctx->r14 != 0) {
        // 0x8002CFE8: lw          $t9, 0xF4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XF4);
            goto L_8002D2B4;
    }
    // 0x8002CFE8: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x8002CFEC: lw          $t7, 0x14($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X14);
    // 0x8002CFF0: sll         $t8, $s7, 3
    ctx->r24 = S32(ctx->r23 << 3);
    // 0x8002CFF4: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x8002CFF8: lhu         $s1, 0x0($t2)
    ctx->r17 = MEM_HU(ctx->r10, 0X0);
    // 0x8002CFFC: lw          $t3, 0x18($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X18);
    // 0x8002D000: sll         $t4, $s1, 4
    ctx->r12 = S32(ctx->r17 << 4);
    // 0x8002D004: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x8002D008: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002D00C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002D010: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x8002D014: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002D018: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8002D01C: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x8002D020: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002D024: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8002D028: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
L_8002D02C:
    // 0x8002D02C: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x8002D030: lw          $t7, 0x14($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X14);
    // 0x8002D034: addiu       $s6, $v0, 0x1
    ctx->r22 = ADD32(ctx->r2, 0X1);
    // 0x8002D038: sll         $t6, $s7, 4
    ctx->r14 = S32(ctx->r23 << 4);
    // 0x8002D03C: sll         $t8, $s7, 3
    ctx->r24 = S32(ctx->r23 << 3);
    // 0x8002D040: slti        $at, $s6, 0x3
    ctx->r1 = SIGNED(ctx->r22) < 0X3 ? 1 : 0;
    // 0x8002D044: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x8002D048: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x8002D04C: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x8002D050: addu        $a3, $t2, $s5
    ctx->r7 = ADD32(ctx->r10, ctx->r21);
    // 0x8002D054: bne         $at, $zero, L_8002D060
    if (ctx->r1 != 0) {
        // 0x8002D058: addu        $a0, $v1, $v0
        ctx->r4 = ADD32(ctx->r3, ctx->r2);
            goto L_8002D060;
    }
    // 0x8002D058: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x8002D05C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002D060:
    // 0x8002D060: addu        $t3, $v1, $s0
    ctx->r11 = ADD32(ctx->r3, ctx->r16);
    // 0x8002D064: lhu         $s0, 0x2($a3)
    ctx->r16 = MEM_HU(ctx->r7, 0X2);
    // 0x8002D068: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8002D06C: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x8002D070: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002D074: addu        $a1, $t9, $fp
    ctx->r5 = ADD32(ctx->r25, ctx->r30);
    // 0x8002D078: beq         $at, $zero, L_8002D298
    if (ctx->r1 == 0) {
        // 0x8002D07C: addu        $a2, $t4, $fp
        ctx->r6 = ADD32(ctx->r12, ctx->r30);
            goto L_8002D298;
    }
    // 0x8002D07C: addu        $a2, $t4, $fp
    ctx->r6 = ADD32(ctx->r12, ctx->r30);
    // 0x8002D080: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D084: lw          $t5, 0x18($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X18);
    // 0x8002D088: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x8002D08C: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x8002D090: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002D094: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002D098: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8002D09C: add.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D0A0: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8002D0A4: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002D0A8: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002D0AC: add.s       $f26, $f6, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D0B0: mflo        $t8
    ctx->r24 = lo;
    // 0x8002D0B4: addu        $v0, $a0, $t8
    ctx->r2 = ADD32(ctx->r4, ctx->r24);
    // 0x8002D0B8: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x8002D0BC: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D0C0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8002D0C4: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8002D0C8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002D0CC: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x8002D0D0: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8002D0D4: add.s       $f22, $f10, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002D0D8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8002D0DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002D0E0: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x8002D0E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002D0E8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8002D0EC: mflo        $t4
    ctx->r12 = lo;
    // 0x8002D0F0: addu        $v0, $a0, $t4
    ctx->r2 = ADD32(ctx->r4, ctx->r12);
    // 0x8002D0F4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8002D0F8: cvt.s.w     $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    ctx->f28.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002D0FC: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8002D100: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8002D104: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8002D108: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8002D10C: sw          $t1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r9;
    // 0x8002D110: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8002D114: cvt.s.w     $f30, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    ctx->f30.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002D118: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8002D11C: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002D120: mul.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8002D124: add.s       $f16, $f4, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x8002D128: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002D12C: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002D130: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002D134: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002D138: mul.s       $f6, $f26, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8002D13C: add.s       $f18, $f10, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x8002D140: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D144: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8002D148: mul.s       $f8, $f10, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x8002D14C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8002D150: mul.s       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8002D154: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002D158: sub.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8002D15C: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8002D160: sub.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8002D164: add.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8002D168: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8002D16C: sub.s       $f10, $f16, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f28.fl;
    // 0x8002D170: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8002D174: sub.s       $f10, $f28, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f28.fl - ctx->f2.fl;
    // 0x8002D178: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002D17C: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8002D180: sub.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8002D184: mul.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x8002D188: add.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002D18C: sub.s       $f4, $f18, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f30.fl;
    // 0x8002D190: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8002D194: sub.s       $f4, $f30, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f30.fl - ctx->f12.fl;
    // 0x8002D198: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002D19C: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8002D1A0: nop

    // 0x8002D1A4: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8002D1A8: add.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002D1AC: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8002D1B0: mov.s       $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    ctx->f26.fl = ctx->f24.fl;
    // 0x8002D1B4: mul.s       $f10, $f24, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8002D1B8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D1BC: jal         0x800CA030
    // 0x8002D1C0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8002D1C0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x8002D1C4: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8002D1C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002D1CC: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8002D1D0: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8002D1D4: lw          $t1, 0xD0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD0);
    // 0x8002D1D8: bc1f        L_8002D1F8
    if (!c1cs) {
        // 0x8002D1DC: addiu       $t0, $zero, 0xA
        ctx->r8 = ADD32(0, 0XA);
            goto L_8002D1F8;
    }
    // 0x8002D1DC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8002D1E0: nop

    // 0x8002D1E4: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8002D1E8: nop

    // 0x8002D1EC: div.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8002D1F0: nop

    // 0x8002D1F4: div.s       $f26, $f24, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
L_8002D1F8:
    // 0x8002D1F8: beq         $s0, $s1, L_8002D230
    if (ctx->r16 == ctx->r17) {
        // 0x8002D1FC: sll         $t5, $s7, 3
        ctx->r13 = S32(ctx->r23 << 3);
            goto L_8002D230;
    }
    // 0x8002D1FC: sll         $t5, $s7, 3
    ctx->r13 = S32(ctx->r23 << 3);
    // 0x8002D200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002D204:
    // 0x8002D204: lw          $t8, 0x14($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X14);
    // 0x8002D208: sll         $t2, $s0, 3
    ctx->r10 = S32(ctx->r16 << 3);
    // 0x8002D20C: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8002D210: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x8002D214: lhu         $t3, 0x2($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2);
    // 0x8002D218: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8002D21C: bne         $s1, $t3, L_8002D228
    if (ctx->r17 != ctx->r11) {
        // 0x8002D220: ori         $t4, $s4, 0x8000
        ctx->r12 = ctx->r20 | 0X8000;
            goto L_8002D228;
    }
    // 0x8002D220: ori         $t4, $s4, 0x8000
    ctx->r12 = ctx->r20 | 0X8000;
    // 0x8002D224: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
L_8002D228:
    // 0x8002D228: bne         $v0, $s3, L_8002D204
    if (ctx->r2 != ctx->r19) {
        // 0x8002D22C: nop
    
            goto L_8002D204;
    }
    // 0x8002D22C: nop

L_8002D230:
    // 0x8002D230: lw          $t6, 0x14($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X14);
    // 0x8002D234: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8002D238: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8002D23C: addu        $t8, $t7, $s5
    ctx->r24 = ADD32(ctx->r15, ctx->r21);
    // 0x8002D240: sh          $s4, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r20;
    // 0x8002D244: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x8002D248: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x8002D24C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8002D250: swc1        $f20, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f20.u32l;
    // 0x8002D254: lw          $t4, 0x18($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X18);
    // 0x8002D258: mul.s       $f8, $f28, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x8002D25C: addu        $t6, $t4, $t2
    ctx->r14 = ADD32(ctx->r12, ctx->r10);
    // 0x8002D260: swc1        $f22, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f22.u32l;
    // 0x8002D264: lw          $t5, 0x18($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X18);
    // 0x8002D268: mul.s       $f10, $f30, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x8002D26C: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x8002D270: swc1        $f26, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f26.u32l;
    // 0x8002D274: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002D278: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002D27C: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x8002D280: mul.s       $f8, $f4, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x8002D284: addu        $t2, $t8, $t2
    ctx->r10 = ADD32(ctx->r24, ctx->r10);
    // 0x8002D288: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002D28C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002D290: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8002D294: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
L_8002D298:
    // 0x8002D298: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002D29C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x8002D2A0: bne         $s6, $at, L_8002D02C
    if (ctx->r22 != ctx->r1) {
        // 0x8002D2A4: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_8002D02C;
    }
    // 0x8002D2A4: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x8002D2A8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8002D2AC: nop

    // 0x8002D2B0: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
L_8002D2B4:
    // 0x8002D2B4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002D2B8: bne         $s7, $t9, L_8002CFCC
    if (ctx->r23 != ctx->r25) {
        // 0x8002D2BC: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8002CFCC;
    }
    // 0x8002D2BC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002D2C0: lh          $a1, 0x20($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X20);
    // 0x8002D2C4: nop

L_8002D2C8:
    // 0x8002D2C8: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
    // 0x8002D2CC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8002D2D0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8002D2D4: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002D2D8: addiu       $t5, $t6, 0xC
    ctx->r13 = ADD32(ctx->r14, 0XC);
    // 0x8002D2DC: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x8002D2E0: bne         $at, $zero, L_8002CF84
    if (ctx->r1 != 0) {
        // 0x8002D2E4: sw          $t4, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r12;
            goto L_8002CF84;
    }
    // 0x8002D2E4: sw          $t4, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r12;
L_8002D2E8:
    // 0x8002D2E8: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
L_8002D2EC:
    // 0x8002D2EC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8002D2F0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002D2F4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002D2F8: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002D2FC: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002D300: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002D304: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002D308: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002D30C: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002D310: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002D314: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002D318: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002D31C: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002D320: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8002D324: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8002D328: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8002D32C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8002D330: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8002D334: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8002D338: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8002D33C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8002D340: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8002D344: jr          $ra
    // 0x8002D348: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8002D348: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void trackMakeAbsolute(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D34C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002D350: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002D354: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002D358: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002D35C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8002D360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D364: beq         $s0, $zero, L_8002D3B4
    if (ctx->r16 == 0) {
        // 0x8002D368: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002D3B4;
    }
    // 0x8002D368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002D36C:
    // 0x8002D36C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8002D370: nop

    // 0x8002D374: beq         $v0, $zero, L_8002D380
    if (ctx->r2 == 0) {
        // 0x8002D378: addu        $t6, $v0, $s1
        ctx->r14 = ADD32(ctx->r2, ctx->r17);
            goto L_8002D380;
    }
    // 0x8002D378: addu        $t6, $v0, $s1
    ctx->r14 = ADD32(ctx->r2, ctx->r17);
    // 0x8002D37C: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_8002D380:
    // 0x8002D380: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8002D384: nop

    // 0x8002D388: beq         $v0, $zero, L_8002D394
    if (ctx->r2 == 0) {
        // 0x8002D38C: addu        $t7, $v0, $s1
        ctx->r15 = ADD32(ctx->r2, ctx->r17);
            goto L_8002D394;
    }
    // 0x8002D38C: addu        $t7, $v0, $s1
    ctx->r15 = ADD32(ctx->r2, ctx->r17);
    // 0x8002D390: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
L_8002D394:
    // 0x8002D394: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8002D398: jal         0x8002D34C
    // 0x8002D39C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    trackMakeAbsolute(rdram, ctx);
        goto after_0;
    // 0x8002D39C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8002D3A0: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x8002D3A4: nop

    // 0x8002D3A8: bne         $s0, $zero, L_8002D36C
    if (ctx->r16 != 0) {
        // 0x8002D3AC: nop
    
            goto L_8002D36C;
    }
    // 0x8002D3AC: nop

    // 0x8002D3B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002D3B4:
    // 0x8002D3B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002D3B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002D3BC: jr          $ra
    // 0x8002D3C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002D3C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void shadow_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D3C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002D3C8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002D3CC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002D3D0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002D3D4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002D3D8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002D3DC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002D3E0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002D3E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002D3E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002D3EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D3F0: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8002D3F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002D3F8: lh          $t7, 0x32($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X32);
    // 0x8002D3FC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8002D400: beq         $t7, $zero, L_8002D684
    if (ctx->r15 == 0) {
        // 0x8002D404: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002D684;
    }
    // 0x8002D404: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002D408: lh          $t8, 0x8($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X8);
    // 0x8002D40C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002D410: beq         $t8, $at, L_8002D680
    if (ctx->r24 == ctx->r1) {
        // 0x8002D414: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8002D680;
    }
    // 0x8002D414: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002D418: lw          $t9, -0x49BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X49BC);
    // 0x8002D41C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002D420: bne         $t9, $zero, L_8002D680
    if (ctx->r25 != 0) {
        // 0x8002D424: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8002D680;
    }
    // 0x8002D424: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002D428: lw          $t5, -0x49B8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X49B8);
    // 0x8002D42C: addiu       $a0, $a0, -0x49B4
    ctx->r4 = ADD32(ctx->r4, -0X49B4);
    // 0x8002D430: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8002D434: lw          $t6, 0x40($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X40);
    // 0x8002D438: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D43C: lh          $t7, 0x32($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X32);
    // 0x8002D440: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002D444: bne         $t7, $at, L_8002D454
    if (ctx->r15 != ctx->r1) {
        // 0x8002D448: addiu       $s4, $s4, -0x2720
        ctx->r20 = ADD32(ctx->r20, -0X2720);
            goto L_8002D454;
    }
    // 0x8002D448: addiu       $s4, $s4, -0x2720
    ctx->r20 = ADD32(ctx->r20, -0X2720);
    // 0x8002D44C: addiu       $t9, $t5, 0x2
    ctx->r25 = ADD32(ctx->r13, 0X2);
    // 0x8002D450: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_8002D454:
    // 0x8002D454: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8002D458: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002D45C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8002D460: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8002D464: lw          $t6, -0x2730($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2730);
    // 0x8002D468: lh          $s3, 0x8($a3)
    ctx->r19 = MEM_H(ctx->r7, 0X8);
    // 0x8002D46C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002D470: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8002D474: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8002D478: lw          $t7, -0x2760($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2760);
    // 0x8002D47C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D480: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002D484: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8002D488: sw          $t7, -0x2750($at)
    MEM_W(-0X2750, ctx->r1) = ctx->r15;
    // 0x8002D48C: lw          $t8, -0x2748($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2748);
    // 0x8002D490: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8002D494: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8002D498: addiu       $s7, $s7, -0x2738
    ctx->r23 = ADD32(ctx->r23, -0X2738);
    // 0x8002D49C: sll         $t5, $s3, 3
    ctx->r13 = S32(ctx->r19 << 3);
    // 0x8002D4A0: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x8002D4A4: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8002D4A8: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x8002D4AC: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x8002D4B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002D4B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002D4B8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8002D4BC: addu        $t5, $t9, $t8
    ctx->r13 = ADD32(ctx->r25, ctx->r24);
    // 0x8002D4C0: lbu         $v1, 0x9($t5)
    ctx->r3 = MEM_BU(ctx->r13, 0X9);
    // 0x8002D4C4: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x8002D4C8: beq         $v1, $zero, L_8002D4E0
    if (ctx->r3 == 0) {
        // 0x8002D4CC: lui         $s6, 0x500
        ctx->r22 = S32(0X500 << 16);
            goto L_8002D4E0;
    }
    // 0x8002D4CC: lui         $s6, 0x500
    ctx->r22 = S32(0X500 << 16);
    // 0x8002D4D0: lbu         $a1, 0x39($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X39);
    // 0x8002D4D4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002D4D8: bne         $a1, $zero, L_8002D4EC
    if (ctx->r5 != 0) {
        // 0x8002D4DC: nop
    
            goto L_8002D4EC;
    }
    // 0x8002D4DC: nop

L_8002D4E0:
    // 0x8002D4E0: lh          $s3, 0xA($a3)
    ctx->r19 = MEM_H(ctx->r7, 0XA);
    // 0x8002D4E4: b           L_8002D53C
    // 0x8002D4E8: lh          $t6, 0xA($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XA);
        goto L_8002D53C;
    // 0x8002D4E8: lh          $t6, 0xA($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XA);
L_8002D4EC:
    // 0x8002D4EC: bne         $v1, $v0, L_8002D4FC
    if (ctx->r3 != ctx->r2) {
        // 0x8002D4F0: nop
    
            goto L_8002D4FC;
    }
    // 0x8002D4F0: nop

    // 0x8002D4F4: beq         $v0, $a1, L_8002D538
    if (ctx->r2 == ctx->r5) {
        // 0x8002D4F8: nop
    
            goto L_8002D538;
    }
    // 0x8002D4F8: nop

L_8002D4FC:
    // 0x8002D4FC: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D500: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002D504: addiu       $s1, $s1, -0x49E0
    ctx->r17 = ADD32(ctx->r17, -0X49E0);
    // 0x8002D508: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D50C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8002D510: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x8002D514: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8002D518: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8002D51C: addiu       $fp, $zero, 0xE
    ctx->r30 = ADD32(0, 0XE);
    // 0x8002D520: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8002D524: mflo        $v1
    ctx->r3 = lo;
    // 0x8002D528: sra         $t6, $v1, 8
    ctx->r14 = S32(SIGNED(ctx->r3) >> 8);
    // 0x8002D52C: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x8002D530: or          $t5, $t8, $at
    ctx->r13 = ctx->r24 | ctx->r1;
    // 0x8002D534: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
L_8002D538:
    // 0x8002D538: lh          $t6, 0xA($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XA);
L_8002D53C:
    // 0x8002D53C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002D540: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002D544: beq         $at, $zero, L_8002D65C
    if (ctx->r1 == 0) {
        // 0x8002D548: addiu       $s1, $s1, -0x49E0
        ctx->r17 = ADD32(ctx->r17, -0X49E0);
            goto L_8002D65C;
    }
    // 0x8002D548: addiu       $s1, $s1, -0x49E0
    ctx->r17 = ADD32(ctx->r17, -0X49E0);
    // 0x8002D54C: sll         $s0, $s3, 3
    ctx->r16 = S32(ctx->r19 << 3);
    // 0x8002D550: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8002D554: lui         $s5, 0x400
    ctx->r21 = S32(0X400 << 16);
    // 0x8002D558: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
L_8002D55C:
    // 0x8002D55C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8002D560: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002D564: addu        $t9, $t7, $s0
    ctx->r25 = ADD32(ctx->r15, ctx->r16);
    // 0x8002D568: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x8002D56C: jal         0x8007B918
    // 0x8002D570: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x8002D570: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_0:
    // 0x8002D574: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8002D578: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002D57C: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x8002D580: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x8002D584: lh          $a2, 0x6($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X6);
    // 0x8002D588: lh          $t5, 0xC($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XC);
    // 0x8002D58C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8002D590: subu        $a3, $t5, $a1
    ctx->r7 = SUB32(ctx->r13, ctx->r5);
    // 0x8002D594: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x8002D598: lw          $t9, -0x2750($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2750);
    // 0x8002D59C: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x8002D5A0: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x8002D5A4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8002D5A8: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x8002D5AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D5B0: subu        $v1, $t6, $a2
    ctx->r3 = SUB32(ctx->r14, ctx->r6);
    // 0x8002D5B4: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x8002D5B8: addu        $t4, $t8, $t5
    ctx->r12 = ADD32(ctx->r24, ctx->r13);
    // 0x8002D5BC: addu        $t1, $t4, $s2
    ctx->r9 = ADD32(ctx->r12, ctx->r18);
    // 0x8002D5C0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8002D5C4: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8002D5C8: andi        $t8, $t1, 0x6
    ctx->r24 = ctx->r9 & 0X6;
    // 0x8002D5CC: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8002D5D0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8002D5D4: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8002D5D8: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8002D5DC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8002D5E0: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8002D5E4: addu        $t5, $t8, $v1
    ctx->r13 = ADD32(ctx->r24, ctx->r3);
    // 0x8002D5E8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8002D5EC: or          $t9, $t7, $s5
    ctx->r25 = ctx->r15 | ctx->r21;
    // 0x8002D5F0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D5F4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002D5F8: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8002D5FC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8002D600: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8002D604: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D608: addiu       $t7, $a3, -0x1
    ctx->r15 = ADD32(ctx->r7, -0X1);
    // 0x8002D60C: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8002D610: ori         $t8, $t9, 0x1
    ctx->r24 = ctx->r25 | 0X1;
    // 0x8002D614: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8002D618: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8002D61C: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x8002D620: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8002D624: or          $t7, $t6, $s6
    ctx->r15 = ctx->r14 | ctx->r22;
    // 0x8002D628: sll         $t9, $a3, 4
    ctx->r25 = S32(ctx->r7 << 4);
    // 0x8002D62C: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x8002D630: or          $t5, $t7, $t8
    ctx->r13 = ctx->r15 | ctx->r24;
    // 0x8002D634: addu        $t6, $t3, $s2
    ctx->r14 = ADD32(ctx->r11, ctx->r18);
    // 0x8002D638: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8002D63C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8002D640: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8002D644: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8002D648: lh          $t7, 0xA($t9)
    ctx->r15 = MEM_H(ctx->r25, 0XA);
    // 0x8002D64C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002D650: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002D654: bne         $at, $zero, L_8002D55C
    if (ctx->r1 != 0) {
        // 0x8002D658: nop
    
            goto L_8002D55C;
    }
    // 0x8002D658: nop

L_8002D65C:
    // 0x8002D65C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002D660: beq         $fp, $at, L_8002D680
    if (ctx->r30 == ctx->r1) {
        // 0x8002D664: lui         $t5, 0xFA00
        ctx->r13 = S32(0XFA00 << 16);
            goto L_8002D680;
    }
    // 0x8002D664: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8002D668: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D66C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8002D670: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x8002D674: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8002D678: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8002D67C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_8002D680:
    // 0x8002D680: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8002D684:
    // 0x8002D684: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D688: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D68C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002D690: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002D694: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002D698: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D69C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002D6A0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002D6A4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002D6A8: jr          $ra
    // 0x8002D6AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002D6AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void watereffect_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D6B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002D6B4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002D6B8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002D6BC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002D6C0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002D6C4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002D6C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002D6CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002D6D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002D6D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002D6D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D6DC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8002D6E0: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8002D6E4: nop

    // 0x8002D6E8: lh          $t7, 0x36($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X36);
    // 0x8002D6EC: nop

    // 0x8002D6F0: beq         $t7, $zero, L_8002D8F0
    if (ctx->r15 == 0) {
        // 0x8002D6F4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002D8F0;
    }
    // 0x8002D6F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002D6F8: lh          $t9, 0x8($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X8);
    // 0x8002D6FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002D700: beq         $t9, $at, L_8002D8EC
    if (ctx->r25 == ctx->r1) {
        // 0x8002D704: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8002D8EC;
    }
    // 0x8002D704: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002D708: lw          $t5, -0x49BC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X49BC);
    // 0x8002D70C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002D710: bne         $t5, $zero, L_8002D8EC
    if (ctx->r13 != 0) {
        // 0x8002D714: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8002D8EC;
    }
    // 0x8002D714: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002D718: lw          $t6, -0x49B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X49B8);
    // 0x8002D71C: addiu       $s0, $s0, -0x49B0
    ctx->r16 = ADD32(ctx->r16, -0X49B0);
    // 0x8002D720: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8002D724: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x8002D728: lh          $s2, 0x8($a1)
    ctx->r18 = MEM_H(ctx->r5, 0X8);
    // 0x8002D72C: lh          $t9, 0x36($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X36);
    // 0x8002D730: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D734: bne         $t9, $at, L_8002D778
    if (ctx->r25 != ctx->r1) {
        // 0x8002D738: addiu       $t6, $t6, 0x2
        ctx->r14 = ADD32(ctx->r14, 0X2);
            goto L_8002D778;
    }
    // 0x8002D738: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x8002D73C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8002D740: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x8002D744: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002D748: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002D74C: jal         0x80066588
    // 0x8002D750: nop

    get_distance_to_active_camera(rdram, ctx);
        goto after_0;
    // 0x8002D750: nop

    after_0:
    // 0x8002D754: lui         $at, 0x4440
    ctx->r1 = S32(0X4440 << 16);
    // 0x8002D758: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002D75C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002D760: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8002D764: nop

    // 0x8002D768: bc1f        L_8002D778
    if (!c1cs) {
        // 0x8002D76C: nop
    
            goto L_8002D778;
    }
    // 0x8002D76C: nop

    // 0x8002D770: lh          $s2, 0xA($t7)
    ctx->r18 = MEM_H(ctx->r15, 0XA);
    // 0x8002D774: nop

L_8002D778:
    // 0x8002D778: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002D77C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002D780: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8002D784: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002D788: lw          $t9, -0x2730($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2730);
    // 0x8002D78C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002D790: addiu       $s3, $s3, -0x2720
    ctx->r19 = ADD32(ctx->r19, -0X2720);
    // 0x8002D794: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002D798: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x8002D79C: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8002D7A0: lw          $t5, -0x2760($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2760);
    // 0x8002D7A4: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002D7A8: addiu       $s5, $s5, -0x2750
    ctx->r21 = ADD32(ctx->r21, -0X2750);
    // 0x8002D7AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002D7B0: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8002D7B4: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
    // 0x8002D7B8: lw          $t6, -0x2748($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2748);
    // 0x8002D7BC: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8002D7C0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002D7C4: addiu       $s6, $s6, -0x2738
    ctx->r22 = ADD32(ctx->r22, -0X2738);
    // 0x8002D7C8: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x8002D7CC: lh          $t8, 0xA($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XA);
    // 0x8002D7D0: sll         $s1, $s2, 3
    ctx->r17 = S32(ctx->r18 << 3);
    // 0x8002D7D4: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002D7D8: beq         $at, $zero, L_8002D8EC
    if (ctx->r1 == 0) {
        // 0x8002D7DC: lui         $fp, 0x400
        ctx->r30 = S32(0X400 << 16);
            goto L_8002D8EC;
    }
    // 0x8002D7DC: lui         $fp, 0x400
    ctx->r30 = S32(0X400 << 16);
    // 0x8002D7E0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002D7E4: addiu       $s0, $s0, -0x49E0
    ctx->r16 = ADD32(ctx->r16, -0X49E0);
    // 0x8002D7E8: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x8002D7EC: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
L_8002D7F0:
    // 0x8002D7F0: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8002D7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002D7F8: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x8002D7FC: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x8002D800: jal         0x8007B918
    // 0x8002D804: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    material_set_no_tex_offset(rdram, ctx);
        goto after_1;
    // 0x8002D804: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_1:
    // 0x8002D808: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8002D80C: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8002D810: addu        $v1, $t6, $s1
    ctx->r3 = ADD32(ctx->r14, ctx->r17);
    // 0x8002D814: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x8002D818: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x8002D81C: multu       $a2, $s7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D820: lh          $t7, 0xC($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XC);
    // 0x8002D824: lh          $t8, 0xE($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XE);
    // 0x8002D828: subu        $a3, $t7, $a1
    ctx->r7 = SUB32(ctx->r15, ctx->r5);
    // 0x8002D82C: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x8002D830: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x8002D834: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002D838: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x8002D83C: subu        $a0, $t8, $a2
    ctx->r4 = SUB32(ctx->r24, ctx->r6);
    // 0x8002D840: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x8002D844: sll         $t5, $t9, 3
    ctx->r13 = S32(ctx->r25 << 3);
    // 0x8002D848: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002D84C: mflo        $t6
    ctx->r14 = lo;
    // 0x8002D850: addu        $t4, $t6, $t7
    ctx->r12 = ADD32(ctx->r14, ctx->r15);
    // 0x8002D854: addu        $t1, $t4, $s4
    ctx->r9 = ADD32(ctx->r12, ctx->r20);
    // 0x8002D858: andi        $t6, $t1, 0x6
    ctx->r14 = ctx->r9 & 0X6;
    // 0x8002D85C: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8002D860: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8002D864: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8002D868: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002D86C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8002D870: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8002D874: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8002D878: or          $t5, $t9, $fp
    ctx->r13 = ctx->r25 | ctx->r30;
    // 0x8002D87C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8002D880: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8002D884: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8002D888: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002D88C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002D890: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002D894: addiu       $t9, $a3, -0x1
    ctx->r25 = ADD32(ctx->r7, -0X1);
    // 0x8002D898: sll         $t5, $t9, 4
    ctx->r13 = S32(ctx->r25 << 4);
    // 0x8002D89C: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8002D8A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002D8A4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8002D8A8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8002D8AC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8002D8B0: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8002D8B4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8002D8B8: sll         $t5, $a3, 4
    ctx->r13 = S32(ctx->r7 << 4);
    // 0x8002D8BC: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8002D8C0: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8002D8C4: addu        $t8, $t3, $s4
    ctx->r24 = ADD32(ctx->r11, ctx->r20);
    // 0x8002D8C8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002D8CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002D8D0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002D8D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002D8D8: lh          $t9, 0xA($t5)
    ctx->r25 = MEM_H(ctx->r13, 0XA);
    // 0x8002D8DC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8002D8E0: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002D8E4: bne         $at, $zero, L_8002D7F0
    if (ctx->r1 != 0) {
        // 0x8002D8E8: nop
    
            goto L_8002D7F0;
    }
    // 0x8002D8E8: nop

L_8002D8EC:
    // 0x8002D8EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8002D8F0:
    // 0x8002D8F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D8F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D8F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002D8FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002D900: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002D904: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D908: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002D90C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002D910: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002D914: jr          $ra
    // 0x8002D918: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002D918: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void shadow_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D91C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8002D920: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002D924: lw          $t6, -0x49B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X49B8);
    // 0x8002D928: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002D92C: addiu       $v1, $v1, -0x49B4
    ctx->r3 = ADD32(ctx->r3, -0X49B4);
    // 0x8002D930: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002D934: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D938: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8002D93C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002D940: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002D944: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002D948: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002D94C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002D950: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002D954: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002D958: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002D95C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002D960: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002D964: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8002D968: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002D96C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002D970: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002D974: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002D978: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x8002D97C: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x8002D980: bne         $a0, $at, L_8002D990
    if (ctx->r4 != ctx->r1) {
        // 0x8002D984: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8002D990;
    }
    // 0x8002D984: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002D988: addiu       $t8, $t6, 0x2
    ctx->r24 = ADD32(ctx->r14, 0X2);
    // 0x8002D98C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8002D990:
    // 0x8002D990: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002D994: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002D998: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8002D99C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002D9A0: lw          $t0, -0x2760($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2760);
    // 0x8002D9A4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002D9A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9AC: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8002D9B0: lw          $t1, -0x2748($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2748);
    // 0x8002D9B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8002D9B8: sw          $t0, -0x2750($at)
    MEM_W(-0X2750, ctx->r1) = ctx->r8;
    // 0x8002D9BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9C0: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8002D9C4: lw          $t2, -0x2730($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2730);
    // 0x8002D9C8: sw          $t1, -0x2738($at)
    MEM_W(-0X2738, ctx->r1) = ctx->r9;
    // 0x8002D9CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9D0: sw          $t2, -0x2720($at)
    MEM_W(-0X2720, ctx->r1) = ctx->r10;
    // 0x8002D9D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9D8: sw          $zero, -0x271C($at)
    MEM_W(-0X271C, ctx->r1) = 0;
    // 0x8002D9DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9E0: sw          $zero, -0x2718($at)
    MEM_W(-0X2718, ctx->r1) = 0;
    // 0x8002D9E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9E8: jal         0x80066450
    // 0x8002D9EC: sw          $zero, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = 0;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8002D9EC: sw          $zero, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = 0;
    after_0:
    // 0x8002D9F0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8002D9F4: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8002D9F8: jal         0x8000E988
    // 0x8002D9FC: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    objGetObjList(rdram, ctx);
        goto after_1;
    // 0x8002D9FC: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_1:
    // 0x8002DA00: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x8002DA04: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x8002DA08: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8002DA0C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002DA10: beq         $at, $zero, L_8002DDE0
    if (ctx->r1 == 0) {
        // 0x8002DA14: addiu       $s7, $zero, 0x5
        ctx->r23 = ADD32(0, 0X5);
            goto L_8002DDE0;
    }
    // 0x8002DA14: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
    // 0x8002DA18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002DA1C: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002DA20: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8002DA24: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8002DA28: addiu       $s5, $s5, -0x29AC
    ctx->r21 = ADD32(ctx->r21, -0X29AC);
    // 0x8002DA2C: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x8002DA30: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x8002DA34: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
L_8002DA38:
    // 0x8002DA38: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8002DA3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002DA40: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8002DA44: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x8002DA48: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8002DA4C: lw          $s2, 0x40($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X40);
    // 0x8002DA50: lw          $s0, 0x58($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X58);
    // 0x8002DA54: lw          $v0, 0x50($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X50);
    // 0x8002DA58: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x8002DA5C: lh          $v1, 0x6($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6);
    // 0x8002DA60: nop

    // 0x8002DA64: andi        $t0, $v1, 0x8000
    ctx->r8 = ctx->r3 & 0X8000;
    // 0x8002DA68: bne         $t0, $zero, L_8002DDCC
    if (ctx->r8 != 0) {
        // 0x8002DA6C: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DDCC;
    }
    // 0x8002DA6C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DA70: beq         $v0, $zero, L_8002DAB0
    if (ctx->r2 == 0) {
        // 0x8002DA74: andi        $t2, $v1, 0x4000
        ctx->r10 = ctx->r3 & 0X4000;
            goto L_8002DAB0;
    }
    // 0x8002DA74: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8002DA78: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002DA7C: nop

    // 0x8002DA80: c.lt.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl < ctx->f4.fl;
    // 0x8002DA84: nop

    // 0x8002DA88: bc1f        L_8002DAB0
    if (!c1cs) {
        // 0x8002DA8C: andi        $t2, $v1, 0x4000
        ctx->r10 = ctx->r3 & 0X4000;
            goto L_8002DAB0;
    }
    // 0x8002DA8C: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8002DA90: lh          $t1, 0x32($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X32);
    // 0x8002DA94: nop

    // 0x8002DA98: bne         $fp, $t1, L_8002DAB0
    if (ctx->r30 != ctx->r9) {
        // 0x8002DA9C: andi        $t2, $v1, 0x4000
        ctx->r10 = ctx->r3 & 0X4000;
            goto L_8002DAB0;
    }
    // 0x8002DA9C: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8002DAA0: sh          $s3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r19;
    // 0x8002DAA4: lh          $v1, 0x6($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6);
    // 0x8002DAA8: nop

    // 0x8002DAAC: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
L_8002DAB0:
    // 0x8002DAB0: beq         $t2, $zero, L_8002DABC
    if (ctx->r10 == 0) {
        // 0x8002DAB4: nop
    
            goto L_8002DABC;
    }
    // 0x8002DAB4: nop

    // 0x8002DAB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002DABC:
    // 0x8002DABC: beq         $v0, $zero, L_8002DAD4
    if (ctx->r2 == 0) {
        // 0x8002DAC0: nop
    
            goto L_8002DAD4;
    }
    // 0x8002DAC0: nop

    // 0x8002DAC4: lh          $t3, 0x32($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X32);
    // 0x8002DAC8: nop

    // 0x8002DACC: beq         $s4, $t3, L_8002DAEC
    if (ctx->r20 == ctx->r11) {
        // 0x8002DAD0: nop
    
            goto L_8002DAEC;
    }
    // 0x8002DAD0: nop

L_8002DAD4:
    // 0x8002DAD4: beq         $s0, $zero, L_8002DB0C
    if (ctx->r16 == 0) {
        // 0x8002DAD8: nop
    
            goto L_8002DB0C;
    }
    // 0x8002DAD8: nop

    // 0x8002DADC: lh          $t4, 0x36($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X36);
    // 0x8002DAE0: nop

    // 0x8002DAE4: bne         $s4, $t4, L_8002DB0C
    if (ctx->r20 != ctx->r12) {
        // 0x8002DAE8: nop
    
            goto L_8002DB0C;
    }
    // 0x8002DAE8: nop

L_8002DAEC:
    // 0x8002DAEC: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8002DAF0: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8002DAF4: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x8002DAF8: jal         0x80066588
    // 0x8002DAFC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    get_distance_to_active_camera(rdram, ctx);
        goto after_2;
    // 0x8002DAFC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8002DB00: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8002DB04: b           L_8002DB14
    // 0x8002DB08: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_8002DB14;
    // 0x8002DB08: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8002DB0C:
    // 0x8002DB0C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8002DB10: nop

L_8002DB14:
    // 0x8002DB14: beq         $v0, $zero, L_8002DC48
    if (ctx->r2 == 0) {
        // 0x8002DB18: nop
    
            goto L_8002DC48;
    }
    // 0x8002DB18: nop

    // 0x8002DB1C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002DB20: nop

    // 0x8002DB24: c.lt.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl < ctx->f6.fl;
    // 0x8002DB28: nop

    // 0x8002DB2C: bc1f        L_8002DC48
    if (!c1cs) {
        // 0x8002DB30: nop
    
            goto L_8002DC48;
    }
    // 0x8002DB30: nop

    // 0x8002DB34: lh          $t5, 0x32($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X32);
    // 0x8002DB38: nop

    // 0x8002DB3C: bne         $fp, $t5, L_8002DC48
    if (ctx->r30 != ctx->r13) {
        // 0x8002DB40: nop
    
            goto L_8002DC48;
    }
    // 0x8002DB40: nop

    // 0x8002DB44: swc1        $f24, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f24.u32l;
    // 0x8002DB48: sh          $s3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r19;
    // 0x8002DB4C: lh          $t7, 0x32($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X32);
    // 0x8002DB50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002DB54: bne         $s4, $t7, L_8002DBBC
    if (ctx->r20 != ctx->r15) {
        // 0x8002DB58: nop
    
            goto L_8002DBBC;
    }
    // 0x8002DB58: nop

    // 0x8002DB5C: blez        $s6, L_8002DBBC
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8002DB60: slti        $at, $s6, 0x4
        ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
            goto L_8002DBBC;
    }
    // 0x8002DB60: slti        $at, $s6, 0x4
    ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
    // 0x8002DB64: beq         $at, $zero, L_8002DBBC
    if (ctx->r1 == 0) {
        // 0x8002DB68: nop
    
            goto L_8002DBBC;
    }
    // 0x8002DB68: nop

    // 0x8002DB6C: lh          $v0, 0x48($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X48);
    // 0x8002DB70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DB74: bne         $v0, $at, L_8002DBA4
    if (ctx->r2 != ctx->r1) {
        // 0x8002DB78: nop
    
            goto L_8002DBA4;
    }
    // 0x8002DB78: nop

    // 0x8002DB7C: lw          $t8, 0x64($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X64);
    // 0x8002DB80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DB84: lh          $v0, 0x0($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X0);
    // 0x8002DB88: nop

    // 0x8002DB8C: beq         $v0, $s3, L_8002DC28
    if (ctx->r2 == ctx->r19) {
        // 0x8002DB90: nop
    
            goto L_8002DC28;
    }
    // 0x8002DB90: nop

    // 0x8002DB94: jal         0x8002E274
    // 0x8002DB98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_generate(rdram, ctx);
        goto after_3;
    // 0x8002DB98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8002DB9C: b           L_8002DC28
    // 0x8002DBA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8002DC28;
    // 0x8002DBA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002DBA4:
    // 0x8002DBA4: bne         $s7, $v0, L_8002DC28
    if (ctx->r23 != ctx->r2) {
        // 0x8002DBA8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8002DC28;
    }
    // 0x8002DBA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DBAC: jal         0x8002E274
    // 0x8002DBB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_generate(rdram, ctx);
        goto after_4;
    // 0x8002DBB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8002DBB4: b           L_8002DC28
    // 0x8002DBB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8002DC28;
    // 0x8002DBB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002DBBC:
    // 0x8002DBBC: lh          $v1, 0x4A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X4A);
    // 0x8002DBC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DBC4: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8002DBC8: nop

    // 0x8002DBCC: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002DBD0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8002DBD4: nop

    // 0x8002DBD8: bc1f        L_8002DC28
    if (!c1cs) {
        // 0x8002DBDC: nop
    
            goto L_8002DC28;
    }
    // 0x8002DBDC: nop

    // 0x8002DBE0: lh          $v0, 0x4C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4C);
    // 0x8002DBE4: nop

    // 0x8002DBE8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8002DBEC: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x8002DBF0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002DBF4: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8002DBF8: nop

    // 0x8002DBFC: bc1f        L_8002DC1C
    if (!c1cs) {
        // 0x8002DC00: nop
    
            goto L_8002DC1C;
    }
    // 0x8002DC00: nop

    // 0x8002DC04: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002DC08: sub.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8002DC0C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002DC10: nop

    // 0x8002DC14: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8002DC18: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
L_8002DC1C:
    // 0x8002DC1C: jal         0x8002E274
    // 0x8002DC20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_generate(rdram, ctx);
        goto after_5;
    // 0x8002DC20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8002DC24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002DC28:
    // 0x8002DC28: bne         $a0, $zero, L_8002DC48
    if (ctx->r4 != 0) {
        // 0x8002DC2C: nop
    
            goto L_8002DC48;
    }
    // 0x8002DC2C: nop

    // 0x8002DC30: lw          $t9, 0x54($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X54);
    // 0x8002DC34: nop

    // 0x8002DC38: beq         $t9, $zero, L_8002DC48
    if (ctx->r25 == 0) {
        // 0x8002DC3C: nop
    
            goto L_8002DC48;
    }
    // 0x8002DC3C: nop

    // 0x8002DC40: jal         0x8002DE70
    // 0x8002DC44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8002DE30(rdram, ctx);
        goto after_6;
    // 0x8002DC44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
L_8002DC48:
    // 0x8002DC48: beq         $s0, $zero, L_8002DDCC
    if (ctx->r16 == 0) {
        // 0x8002DC4C: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DDCC;
    }
    // 0x8002DC4C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DC50: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8002DC54: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x8002DC58: c.lt.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl < ctx->f10.fl;
    // 0x8002DC5C: nop

    // 0x8002DC60: bc1f        L_8002DDCC
    if (!c1cs) {
        // 0x8002DC64: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DDCC;
    }
    // 0x8002DC64: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DC68: lh          $t1, 0x36($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X36);
    // 0x8002DC6C: nop

    // 0x8002DC70: bne         $t0, $t1, L_8002DDCC
    if (ctx->r8 != ctx->r9) {
        // 0x8002DC74: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DDCC;
    }
    // 0x8002DC74: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DC78: sh          $s3, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r19;
    // 0x8002DC7C: swc1        $f24, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f24.u32l;
    // 0x8002DC80: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8002DC84: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x8002DC88: beq         $a0, $zero, L_8002DCF0
    if (ctx->r4 == 0) {
        // 0x8002DC8C: nop
    
            goto L_8002DCF0;
    }
    // 0x8002DC8C: nop

    // 0x8002DC90: beq         $t2, $zero, L_8002DCF0
    if (ctx->r10 == 0) {
        // 0x8002DC94: nop
    
            goto L_8002DCF0;
    }
    // 0x8002DC94: nop

    // 0x8002DC98: lhu         $t3, 0x12($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X12);
    // 0x8002DC9C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x8002DCA0: beq         $t3, $at, L_8002DCF0
    if (ctx->r11 == ctx->r1) {
        // 0x8002DCA4: nop
    
            goto L_8002DCF0;
    }
    // 0x8002DCA4: nop

    // 0x8002DCA8: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x8002DCAC: lh          $t5, 0xE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE);
    // 0x8002DCB0: nop

    // 0x8002DCB4: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8002DCB8: sh          $t7, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r15;
    // 0x8002DCBC: lh          $v1, 0xC($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XC);
    // 0x8002DCC0: lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X12);
    // 0x8002DCC4: nop

    // 0x8002DCC8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002DCCC: beq         $at, $zero, L_8002DCF0
    if (ctx->r1 == 0) {
        // 0x8002DCD0: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_8002DCF0;
    }
    // 0x8002DCD0: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_8002DCD4:
    // 0x8002DCD4: sh          $t8, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r24;
    // 0x8002DCD8: lh          $v1, 0xC($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XC);
    // 0x8002DCDC: lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X12);
    // 0x8002DCE0: nop

    // 0x8002DCE4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002DCE8: bne         $at, $zero, L_8002DCD4
    if (ctx->r1 != 0) {
        // 0x8002DCEC: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_8002DCD4;
    }
    // 0x8002DCEC: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_8002DCF0:
    // 0x8002DCF0: lh          $t6, 0x32($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X32);
    // 0x8002DCF4: nop

    // 0x8002DCF8: bne         $s4, $t6, L_8002DD60
    if (ctx->r20 != ctx->r14) {
        // 0x8002DCFC: nop
    
            goto L_8002DD60;
    }
    // 0x8002DCFC: nop

    // 0x8002DD00: blez        $s6, L_8002DD60
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8002DD04: slti        $at, $s6, 0x4
        ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
            goto L_8002DD60;
    }
    // 0x8002DD04: slti        $at, $s6, 0x4
    ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
    // 0x8002DD08: beq         $at, $zero, L_8002DD60
    if (ctx->r1 == 0) {
        // 0x8002DD0C: nop
    
            goto L_8002DD60;
    }
    // 0x8002DD0C: nop

    // 0x8002DD10: lh          $v0, 0x48($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X48);
    // 0x8002DD14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DD18: bne         $v0, $at, L_8002DD48
    if (ctx->r2 != ctx->r1) {
        // 0x8002DD1C: nop
    
            goto L_8002DD48;
    }
    // 0x8002DD1C: nop

    // 0x8002DD20: lw          $t9, 0x64($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X64);
    // 0x8002DD24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002DD28: lh          $v0, 0x0($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X0);
    // 0x8002DD2C: nop

    // 0x8002DD30: beq         $v0, $s3, L_8002DDCC
    if (ctx->r2 == ctx->r19) {
        // 0x8002DD34: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DDCC;
    }
    // 0x8002DD34: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DD38: jal         0x8002E274
    // 0x8002DD3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    shadow_generate(rdram, ctx);
        goto after_7;
    // 0x8002DD3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8002DD40: b           L_8002DDCC
    // 0x8002DD44: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
        goto L_8002DDCC;
    // 0x8002DD44: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
L_8002DD48:
    // 0x8002DD48: bne         $s7, $v0, L_8002DDC8
    if (ctx->r23 != ctx->r2) {
        // 0x8002DD4C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8002DDC8;
    }
    // 0x8002DD4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002DD50: jal         0x8002E274
    // 0x8002DD54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    shadow_generate(rdram, ctx);
        goto after_8;
    // 0x8002DD54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8002DD58: b           L_8002DDCC
    // 0x8002DD5C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
        goto L_8002DDCC;
    // 0x8002DD5C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
L_8002DD60:
    // 0x8002DD60: lh          $v1, 0x4A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X4A);
    // 0x8002DD64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002DD68: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x8002DD6C: nop

    // 0x8002DD70: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002DD74: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8002DD78: nop

    // 0x8002DD7C: bc1f        L_8002DDCC
    if (!c1cs) {
        // 0x8002DD80: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DDCC;
    }
    // 0x8002DD80: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DD84: lh          $v0, 0x4C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4C);
    // 0x8002DD88: nop

    // 0x8002DD8C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8002DD90: subu        $t0, $v1, $v0
    ctx->r8 = SUB32(ctx->r3, ctx->r2);
    // 0x8002DD94: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002DD98: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x8002DD9C: nop

    // 0x8002DDA0: bc1f        L_8002DDC0
    if (!c1cs) {
        // 0x8002DDA4: nop
    
            goto L_8002DDC0;
    }
    // 0x8002DDA4: nop

    // 0x8002DDA8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8002DDAC: sub.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8002DDB0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002DDB4: nop

    // 0x8002DDB8: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002DDBC: swc1        $f16, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f16.u32l;
L_8002DDC0:
    // 0x8002DDC0: jal         0x8002E274
    // 0x8002DDC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    shadow_generate(rdram, ctx);
        goto after_9;
    // 0x8002DDC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_8002DDC8:
    // 0x8002DDC8: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
L_8002DDCC:
    // 0x8002DDCC: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x8002DDD0: nop

    // 0x8002DDD4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8002DDD8: bne         $at, $zero, L_8002DA38
    if (ctx->r1 != 0) {
        // 0x8002DDDC: lw          $t6, 0x94($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X94);
            goto L_8002DA38;
    }
    // 0x8002DDDC: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
L_8002DDE0:
    // 0x8002DDE0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002DDE4: addiu       $v1, $v1, -0x271C
    ctx->r3 = ADD32(ctx->r3, -0X271C);
    // 0x8002DDE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002DDEC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8002DDF0: addiu       $v0, $v0, -0x2720
    ctx->r2 = ADD32(ctx->r2, -0X2720);
    // 0x8002DDF4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8002DDF8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8002DDFC: lw          $t3, -0x2718($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2718);
    // 0x8002DE00: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x8002DE04: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x8002DE08: sh          $t3, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r11;
    // 0x8002DE0C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8002DE10: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8002DE14: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002DE18: lw          $t6, -0x2714($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2714);
    // 0x8002DE1C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8002DE20: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8002DE24: sh          $t6, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r14;
    // 0x8002DE28: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8002DE2C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8002DE30: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8002DE34: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8002DE38: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8002DE3C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002DE40: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002DE44: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002DE48: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8002DE4C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002DE50: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002DE54: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002DE58: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002DE5C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002DE60: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002DE64: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002DE68: jr          $ra
    // 0x8002DE6C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8002DE6C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8002DE30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DE70: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8002DE74: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002DE78: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002DE7C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002DE80: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002DE84: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002DE88: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002DE8C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002DE90: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002DE94: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002DE98: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002DE9C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002DEA0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002DEA4: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002DEA8: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8002DEAC: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002DEB0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8002DEB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DEB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DEBC: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002DEC0: lw          $a1, 0x40($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X40);
    // 0x8002DEC4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002DEC8: lh          $t7, 0x44($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X44);
    // 0x8002DECC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8002DED0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002DED4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8002DED8: sw          $t8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r24;
    // 0x8002DEDC: lh          $t9, 0x42($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X42);
    // 0x8002DEE0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002DEE4: addu        $t4, $v0, $t9
    ctx->r12 = ADD32(ctx->r2, ctx->r25);
    // 0x8002DEE8: sw          $t4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r12;
    // 0x8002DEEC: lh          $v1, 0x2E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X2E);
    // 0x8002DEF0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8002DEF4: beq         $v1, $at, L_8002E234
    if (ctx->r3 == ctx->r1) {
        // 0x8002DEF8: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8002E234;
    }
    // 0x8002DEF8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002DEFC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002DF00: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002DF04: lwc1        $f0, 0xC($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0XC);
    // 0x8002DF08: lwc1        $f2, 0x14($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8002DF0C: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8002DF10: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8002DF14: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002DF18: addiu       $s0, $s0, -0x3178
    ctx->r16 = ADD32(ctx->r16, -0X3178);
    // 0x8002DF1C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002DF20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DF24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DF28: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8002DF2C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002DF30: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8002DF34: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002DF38: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8002DF3C: sub.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8002DF40: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8002DF44: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002DF48: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002DF4C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002DF50: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DF54: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DF58: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002DF5C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002DF60: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8002DF64: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002DF68: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8002DF6C: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8002DF70: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x8002DF74: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8002DF78: nop

    // 0x8002DF7C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8002DF80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DF84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DF88: nop

    // 0x8002DF8C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002DF90: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8002DF94: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8002DF98: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8002DF9C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002DFA0: nop

    // 0x8002DFA4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8002DFA8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DFAC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DFB0: nop

    // 0x8002DFB4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002DFB8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8002DFBC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002DFC0: jal         0x8003151C
    // 0x8002DFC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    compute_grid_overlap_mask(rdram, ctx);
        goto after_0;
    // 0x8002DFC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002DFC8: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x8002DFCC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8002DFD0: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x8002DFD4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8002DFD8: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8002DFDC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002DFE0: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x8002DFE4: addu        $s5, $t8, $t9
    ctx->r21 = ADD32(ctx->r24, ctx->r25);
    // 0x8002DFE8: lh          $t4, 0x20($s5)
    ctx->r12 = MEM_H(ctx->r21, 0X20);
    // 0x8002DFEC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8002DFF0: blez        $t4, L_8002E234
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8002DFF4: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8002E234;
    }
    // 0x8002DFF4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8002DFF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002DFFC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8002E000: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E004: lwc1        $f21, 0x64D0($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X64D0);
    // 0x8002E008: lwc1        $f20, 0x64D4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X64D4);
    // 0x8002E00C: lw          $v0, 0xC($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XC);
    // 0x8002E010: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8002E014: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
L_8002E018:
    // 0x8002E018: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8002E01C: nop

    // 0x8002E020: andi        $t6, $v1, 0x6900
    ctx->r14 = ctx->r3 & 0X6900;
    // 0x8002E024: bne         $t6, $zero, L_8002E208
    if (ctx->r14 != 0) {
        // 0x8002E028: srl         $fp, $v1, 19
        ctx->r30 = S32(U32(ctx->r3) >> 19);
            goto L_8002E208;
    }
    // 0x8002E028: srl         $fp, $v1, 19
    ctx->r30 = S32(U32(ctx->r3) >> 19);
    // 0x8002E02C: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8002E030: lh          $s3, 0x4($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X4);
    // 0x8002E034: lh          $t5, 0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X10);
    // 0x8002E038: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8002E03C: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x8002E040: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002E044: andi        $t7, $fp, 0x7
    ctx->r15 = ctx->r30 & 0X7;
    // 0x8002E048: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8002E04C: slt         $at, $s3, $t5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002E050: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x8002E054: beq         $at, $zero, L_8002E208
    if (ctx->r1 == 0) {
        // 0x8002E058: addu        $s0, $t9, $t4
        ctx->r16 = ADD32(ctx->r25, ctx->r12);
            goto L_8002E208;
    }
    // 0x8002E058: addu        $s0, $t9, $t4
    ctx->r16 = ADD32(ctx->r25, ctx->r12);
    // 0x8002E05C: bne         $s7, $zero, L_8002E208
    if (ctx->r23 != 0) {
        // 0x8002E060: sll         $s4, $s3, 1
        ctx->r20 = S32(ctx->r19 << 1);
            goto L_8002E208;
    }
    // 0x8002E060: sll         $s4, $s3, 1
    ctx->r20 = S32(ctx->r19 << 1);
L_8002E064:
    // 0x8002E064: lw          $t6, 0x10($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X10);
    // 0x8002E068: nop

    // 0x8002E06C: addu        $t7, $t6, $s4
    ctx->r15 = ADD32(ctx->r14, ctx->r20);
    // 0x8002E070: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002E074: nop

    // 0x8002E078: and         $v0, $t8, $t3
    ctx->r2 = ctx->r24 & ctx->r11;
    // 0x8002E07C: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8002E080: beq         $t9, $zero, L_8002E1E0
    if (ctx->r25 == 0) {
        // 0x8002E084: andi        $t4, $v0, 0xFF00
        ctx->r12 = ctx->r2 & 0XFF00;
            goto L_8002E1E0;
    }
    // 0x8002E084: andi        $t4, $v0, 0xFF00
    ctx->r12 = ctx->r2 & 0XFF00;
    // 0x8002E088: beq         $t4, $zero, L_8002E1E0
    if (ctx->r12 == 0) {
        // 0x8002E08C: nop
    
            goto L_8002E1E0;
    }
    // 0x8002E08C: nop

    // 0x8002E090: lw          $t5, 0x4($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X4);
    // 0x8002E094: sll         $t6, $s3, 4
    ctx->r14 = S32(ctx->r19 << 4);
    // 0x8002E098: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x8002E09C: lbu         $t7, 0x1($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X1);
    // 0x8002E0A0: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x8002E0A4: multu       $t7, $s1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E0A8: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x8002E0AC: addiu       $a0, $t0, 0x1
    ctx->r4 = ADD32(ctx->r8, 0X1);
    // 0x8002E0B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002E0B4: mflo        $t1
    ctx->r9 = lo;
    // 0x8002E0B8: addu        $t8, $s0, $t1
    ctx->r24 = ADD32(ctx->r16, ctx->r9);
    // 0x8002E0BC: lh          $a1, 0x2($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X2);
    // 0x8002E0C0: nop

    // 0x8002E0C4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_8002E0C8:
    // 0x8002E0C8: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8002E0CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E0D0: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E0D4: mflo        $t4
    ctx->r12 = lo;
    // 0x8002E0D8: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x8002E0DC: lh          $v0, 0x2($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X2);
    // 0x8002E0E0: nop

    // 0x8002E0E4: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002E0E8: beq         $at, $zero, L_8002E0FC
    if (ctx->r1 == 0) {
        // 0x8002E0EC: slt         $at, $a2, $v0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002E0FC;
    }
    // 0x8002E0EC: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002E0F0: b           L_8002E108
    // 0x8002E0F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8002E108;
    // 0x8002E0F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002E0F8: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_8002E0FC:
    // 0x8002E0FC: beq         $at, $zero, L_8002E108
    if (ctx->r1 == 0) {
        // 0x8002E100: nop
    
            goto L_8002E108;
    }
    // 0x8002E100: nop

    // 0x8002E104: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8002E108:
    // 0x8002E108: bne         $v1, $s2, L_8002E0C8
    if (ctx->r3 != ctx->r18) {
        // 0x8002E10C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8002E0C8;
    }
    // 0x8002E10C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002E110: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002E114: bne         $at, $zero, L_8002E1E0
    if (ctx->r1 != 0) {
        // 0x8002E118: slt         $at, $t7, $a1
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8002E1E0;
    }
    // 0x8002E118: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002E11C: bne         $at, $zero, L_8002E1E0
    if (ctx->r1 != 0) {
        // 0x8002E120: nop
    
            goto L_8002E1E0;
    }
    // 0x8002E120: nop

    // 0x8002E124: lbu         $t4, 0x2($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X2);
    // 0x8002E128: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002E12C: multu       $t4, $s1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E130: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002E134: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E138: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E13C: lwc1        $f16, 0xC($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0XC);
    // 0x8002E140: lbu         $t6, 0x3($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X3);
    // 0x8002E144: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002E148: lwc1        $f4, 0x14($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8002E14C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002E150: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8002E154: sw          $t3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r11;
    // 0x8002E158: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002E15C: mflo        $t5
    ctx->r13 = lo;
    // 0x8002E160: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002E164: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E168: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E16C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E170: addu        $a3, $t5, $s0
    ctx->r7 = ADD32(ctx->r13, ctx->r16);
    // 0x8002E174: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E178: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8002E17C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8002E180: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002E184: addu        $a2, $t1, $s0
    ctx->r6 = ADD32(ctx->r9, ctx->r16);
    // 0x8002E188: mflo        $t7
    ctx->r15 = lo;
    // 0x8002E18C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8002E190: jal         0x80070730
    // 0x8002E194: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    tri2d_xz_contains_point(rdram, ctx);
        goto after_1;
    // 0x8002E194: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8002E198: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8002E19C: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8002E1A0: beq         $v0, $zero, L_8002E1E0
    if (ctx->r2 == 0) {
        // 0x8002E1A4: sll         $t9, $fp, 2
        ctx->r25 = S32(ctx->r30 << 2);
            goto L_8002E1E0;
    }
    // 0x8002E1A4: sll         $t9, $fp, 2
    ctx->r25 = S32(ctx->r30 << 2);
    // 0x8002E1A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E1AC: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8002E1B0: lwc1        $f10, -0x320C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X320C);
    // 0x8002E1B4: lw          $v0, 0x54($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X54);
    // 0x8002E1B8: sub.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f10.fl;
    // 0x8002E1BC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002E1C0: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8002E1C4: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8002E1C8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E1CC: mul.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x8002E1D0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8002E1D4: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8002E1D8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002E1DC: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_8002E1E0:
    // 0x8002E1E0: lw          $t4, 0xC($s5)
    ctx->r12 = MEM_W(ctx->r21, 0XC);
    // 0x8002E1E4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8002E1E8: addu        $v0, $t4, $t2
    ctx->r2 = ADD32(ctx->r12, ctx->r10);
    // 0x8002E1EC: lh          $t5, 0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X10);
    // 0x8002E1F0: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8002E1F4: slt         $at, $s3, $t5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002E1F8: beq         $at, $zero, L_8002E20C
    if (ctx->r1 == 0) {
        // 0x8002E1FC: lw          $t6, 0x78($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X78);
            goto L_8002E20C;
    }
    // 0x8002E1FC: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8002E200: beq         $s7, $zero, L_8002E064
    if (ctx->r23 == 0) {
        // 0x8002E204: nop
    
            goto L_8002E064;
    }
    // 0x8002E204: nop

L_8002E208:
    // 0x8002E208: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
L_8002E20C:
    // 0x8002E20C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8002E210: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002E214: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x8002E218: lh          $t8, 0x20($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X20);
    // 0x8002E21C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8002E220: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002E224: beq         $at, $zero, L_8002E238
    if (ctx->r1 == 0) {
        // 0x8002E228: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8002E238;
    }
    // 0x8002E228: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8002E22C: beq         $s7, $zero, L_8002E018
    if (ctx->r23 == 0) {
        // 0x8002E230: nop
    
            goto L_8002E018;
    }
    // 0x8002E230: nop

L_8002E234:
    // 0x8002E234: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8002E238:
    // 0x8002E238: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002E23C: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002E240: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002E244: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002E248: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002E24C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8002E250: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002E254: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002E258: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002E25C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8002E260: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8002E264: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8002E268: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8002E26C: jr          $ra
    // 0x8002E270: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8002E270: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void shadow_generate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E274: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8002E278: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002E27C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002E280: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002E284: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8002E288: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8002E28C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8002E290: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8002E294: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8002E298: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8002E29C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002E2A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E2A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E2A8: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002E2AC: lh          $t7, 0x48($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X48);
    // 0x8002E2B0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E2B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002E2B8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8002E2BC: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x8002E2C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002E2C4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002E2C8: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8002E2CC: bne         $s2, $t7, L_8002E30C
    if (ctx->r18 != ctx->r15) {
        // 0x8002E2D0: or          $s6, $a1, $zero
        ctx->r22 = ctx->r5 | 0;
            goto L_8002E30C;
    }
    // 0x8002E2D0: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8002E2D4: jal         0x8009C850
    // 0x8002E2D8: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x8002E2D8: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8002E2DC: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002E2E0: andi        $t8, $v0, 0x10
    ctx->r24 = ctx->r2 & 0X10;
    // 0x8002E2E4: beq         $t8, $zero, L_8002E2FC
    if (ctx->r24 == 0) {
        // 0x8002E2E8: andi        $t9, $v0, 0x20
        ctx->r25 = ctx->r2 & 0X20;
            goto L_8002E2FC;
    }
    // 0x8002E2E8: andi        $t9, $v0, 0x20
    ctx->r25 = ctx->r2 & 0X20;
    // 0x8002E2EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E2F0: lwc1        $f18, 0x64D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64D8);
    // 0x8002E2F4: b           L_8002E310
    // 0x8002E2F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
        goto L_8002E310;
    // 0x8002E2F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8002E2FC:
    // 0x8002E2FC: beq         $t9, $zero, L_8002E30C
    if (ctx->r25 == 0) {
        // 0x8002E300: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8002E30C;
    }
    // 0x8002E300: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E304: lwc1        $f18, 0x64DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64DC);
    // 0x8002E308: nop

L_8002E30C:
    // 0x8002E30C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8002E310:
    // 0x8002E310: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002E314: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002E318: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002E31C: addiu       $s3, $s3, -0x29BC
    ctx->r19 = ADD32(ctx->r19, -0X29BC);
    // 0x8002E320: addiu       $s1, $s1, -0x29B8
    ctx->r17 = ADD32(ctx->r17, -0X29B8);
    // 0x8002E324: sw          $s5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r21;
    // 0x8002E328: beq         $s6, $zero, L_8002E434
    if (ctx->r22 == 0) {
        // 0x8002E32C: swc1        $f8, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
            goto L_8002E434;
    }
    // 0x8002E32C: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x8002E330: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E334: sw          $zero, -0x29C8($at)
    MEM_W(-0X29C8, ctx->r1) = 0;
    // 0x8002E338: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002E33C: lw          $t0, -0x271C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X271C);
    // 0x8002E340: lw          $t1, 0x58($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X58);
    // 0x8002E344: nop

    // 0x8002E348: sh          $t0, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r8;
    // 0x8002E34C: lw          $v0, 0x58($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X58);
    // 0x8002E350: nop

    // 0x8002E354: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    // 0x8002E358: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8002E35C: sll         $t2, $a1, 8
    ctx->r10 = S32(ctx->r5 << 8);
    // 0x8002E360: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8002E364: jal         0x8007B8BC
    // 0x8002E368: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    set_animated_texture_header(rdram, ctx);
        goto after_1;
    // 0x8002E368: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8002E36C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E370: sw          $v0, -0x29C0($at)
    MEM_W(-0X29C0, ctx->r1) = ctx->r2;
    // 0x8002E374: lw          $t3, 0x40($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X40);
    // 0x8002E378: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002E37C: lh          $t4, 0x48($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X48);
    // 0x8002E380: addiu       $s4, $s4, -0x29B2
    ctx->r20 = ADD32(ctx->r20, -0X29B2);
    // 0x8002E384: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8002E388: sh          $t5, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r13;
    // 0x8002E38C: lw          $t6, 0x40($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X40);
    // 0x8002E390: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002E394: lh          $t7, 0x46($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X46);
    // 0x8002E398: lw          $t9, -0x26FC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26FC);
    // 0x8002E39C: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002E3A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E3A4: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8002E3A8: beq         $t9, $zero, L_8002E3C4
    if (ctx->r25 == 0) {
        // 0x8002E3AC: sh          $t8, -0x29B4($at)
        MEM_H(-0X29B4, ctx->r1) = ctx->r24;
            goto L_8002E3C4;
    }
    // 0x8002E3AC: sh          $t8, -0x29B4($at)
    MEM_H(-0X29B4, ctx->r1) = ctx->r24;
    // 0x8002E3B0: jal         0x80066450
    // 0x8002E3B4: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    cam_get_viewport_layout(rdram, ctx);
        goto after_2;
    // 0x8002E3B4: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8002E3B8: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002E3BC: bgtz        $v0, L_8002E3D0
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002E3C0: nop
    
            goto L_8002E3D0;
    }
    // 0x8002E3C0: nop

L_8002E3C4:
    // 0x8002E3C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002E3C8: nop

    // 0x8002E3CC: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_8002E3D0:
    // 0x8002E3D0: lw          $t0, 0x58($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X58);
    // 0x8002E3D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002E3D8: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8002E3DC: addiu       $v1, $v1, -0x29A8
    ctx->r3 = ADD32(ctx->r3, -0X29A8);
    // 0x8002E3E0: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8002E3E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002E3E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002E3EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E3F0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8002E3F4: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002E3F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002E3FC: mul.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8002E400: addiu       $v0, $v0, -0x2990
    ctx->r2 = ADD32(ctx->r2, -0X2990);
    // 0x8002E404: swc1        $f0, -0x29A4($at)
    MEM_W(-0X29A4, ctx->r1) = ctx->f0.u32l;
    // 0x8002E408: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E40C: swc1        $f0, -0x29A0($at)
    MEM_W(-0X29A0, ctx->r1) = ctx->f0.u32l;
    // 0x8002E410: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8002E414: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002E418: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E41C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8002E420: lwc1        $f12, -0x29A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x8002E424: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E428: lwc1        $f14, -0x29A0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X29A0);
    // 0x8002E42C: b           L_8002E608
    // 0x8002E430: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
        goto L_8002E608;
    // 0x8002E430: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
L_8002E434:
    // 0x8002E434: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002E438: lw          $t1, -0x271C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X271C);
    // 0x8002E43C: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
    // 0x8002E440: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E444: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
    // 0x8002E448: lw          $t3, 0x50($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X50);
    // 0x8002E44C: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002E450: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8002E454: addiu       $s4, $s4, -0x29B2
    ctx->r20 = ADD32(ctx->r20, -0X29B2);
    // 0x8002E458: sw          $t4, -0x29C0($at)
    MEM_W(-0X29C0, ctx->r1) = ctx->r12;
    // 0x8002E45C: lw          $t5, 0x40($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X40);
    // 0x8002E460: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E464: lh          $t6, 0x44($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X44);
    // 0x8002E468: nop

    // 0x8002E46C: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8002E470: sh          $t7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r15;
    // 0x8002E474: lw          $t8, 0x40($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X40);
    // 0x8002E478: nop

    // 0x8002E47C: lh          $t9, 0x42($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X42);
    // 0x8002E480: nop

    // 0x8002E484: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8002E488: sh          $t0, -0x29B4($at)
    MEM_H(-0X29B4, ctx->r1) = ctx->r8;
    // 0x8002E48C: lh          $t1, 0x48($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X48);
    // 0x8002E490: nop

    // 0x8002E494: beq         $s2, $t1, L_8002E52C
    if (ctx->r18 == ctx->r9) {
        // 0x8002E498: nop
    
            goto L_8002E52C;
    }
    // 0x8002E498: nop

    // 0x8002E49C: lwc1        $f2, 0x30($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X30);
    // 0x8002E4A0: mtc1        $zero, $f13
    ctx->f_odd[(13 - 1) * 2] = 0;
    // 0x8002E4A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002E4A8: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8002E4AC: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x8002E4B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E4B4: bc1f        L_8002E4C4
    if (!c1cs) {
        // 0x8002E4B8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8002E4C4;
    }
    // 0x8002E4B8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002E4BC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8002E4C0: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_8002E4C4:
    // 0x8002E4C4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E4C8: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8002E4CC: sub.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d - ctx->f4.d;
    // 0x8002E4D0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002E4D4: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x8002E4D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002E4DC: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8002E4E0: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x8002E4E4: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8002E4E8: bc1f        L_8002E4FC
    if (!c1cs) {
        // 0x8002E4EC: nop
    
            goto L_8002E4FC;
    }
    // 0x8002E4EC: nop

    // 0x8002E4F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002E4F4: nop

    // 0x8002E4F8: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_8002E4FC:
    // 0x8002E4FC: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8002E500: nop

    // 0x8002E504: bc1f        L_8002E514
    if (!c1cs) {
        // 0x8002E508: nop
    
            goto L_8002E514;
    }
    // 0x8002E508: nop

    // 0x8002E50C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002E510: nop

L_8002E514:
    // 0x8002E514: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E518: lwc1        $f4, 0x64E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X64E0);
    // 0x8002E51C: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8002E520: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8002E524: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002E528: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
L_8002E52C:
    // 0x8002E52C: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
    // 0x8002E530: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002E534: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8002E538: addiu       $v1, $v1, -0x29A8
    ctx->r3 = ADD32(ctx->r3, -0X29A8);
    // 0x8002E53C: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8002E540: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002E544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002E548: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E54C: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8002E550: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002E554: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002E558: mul.s       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8002E55C: addiu       $v0, $v0, -0x2990
    ctx->r2 = ADD32(ctx->r2, -0X2990);
    // 0x8002E560: swc1        $f0, -0x29A4($at)
    MEM_W(-0X29A4, ctx->r1) = ctx->f0.u32l;
    // 0x8002E564: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E568: swc1        $f0, -0x29A0($at)
    MEM_W(-0X29A0, ctx->r1) = ctx->f0.u32l;
    // 0x8002E56C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E570: lwc1        $f12, -0x29A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x8002E574: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E578: lwc1        $f14, -0x29A0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X29A0);
    // 0x8002E57C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002E580: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002E584: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E588: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8002E58C: nop

    // 0x8002E590: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8002E594: swc1        $f10, -0x299C($at)
    MEM_W(-0X299C, ctx->r1) = ctx->f10.u32l;
    // 0x8002E598: lw          $t3, 0x40($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X40);
    // 0x8002E59C: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8002E5A0: lh          $t4, 0x42($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X42);
    // 0x8002E5A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002E5A8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8002E5AC: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8002E5B0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002E5B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E5B8: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8002E5BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002E5C0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8002E5C4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002E5C8: nop

    // 0x8002E5CC: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8002E5D0: nop

    // 0x8002E5D4: bc1f        L_8002E5EC
    if (!c1cs) {
        // 0x8002E5D8: nop
    
            goto L_8002E5EC;
    }
    // 0x8002E5D8: nop

    // 0x8002E5DC: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8002E5E0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8002E5E4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002E5E8: nop

L_8002E5EC:
    // 0x8002E5EC: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002E5F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E5F4: addiu       $t5, $zero, -0x8000
    ctx->r13 = ADD32(0, -0X8000);
    // 0x8002E5F8: swc1        $f10, -0x298C($at)
    MEM_W(-0X298C, ctx->r1) = ctx->f10.u32l;
    // 0x8002E5FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E600: sh          $t5, -0x29B0($at)
    MEM_H(-0X29B0, ctx->r1) = ctx->r13;
    // 0x8002E604: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
L_8002E608:
    // 0x8002E608: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002E60C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8002E610: div.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8002E614: lh          $t4, 0x0($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X0);
    // 0x8002E618: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8002E61C: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8002E620: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8002E624: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E628: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002E62C: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8002E630: lh          $a2, -0x29B4($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X29B4);
    // 0x8002E634: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002E638: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8002E63C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002E640: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E644: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E648: nop

    // 0x8002E64C: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E650: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002E654: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002E658: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8002E65C: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8002E660: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002E664: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002E668: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002E66C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E670: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E674: nop

    // 0x8002E678: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002E67C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002E680: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8002E684: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8002E688: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x8002E68C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002E690: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8002E694: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8002E698: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E69C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E6A0: nop

    // 0x8002E6A4: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E6A8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002E6AC: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8002E6B0: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8002E6B4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002E6B8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002E6BC: nop

    // 0x8002E6C0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8002E6C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E6C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E6CC: nop

    // 0x8002E6D0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002E6D4: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8002E6D8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002E6DC: jal         0x8002A174
    // 0x8002E6E0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    get_inside_segment_count_xyz(rdram, ctx);
        goto after_3;
    // 0x8002E6E0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_3:
    // 0x8002E6E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E6E8: sw          $zero, -0x3850($at)
    MEM_W(-0X3850, ctx->r1) = 0;
    // 0x8002E6EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E6F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002E6F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002E6F8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x8002E6FC: sw          $zero, -0x4968($at)
    MEM_W(-0X4968, ctx->r1) = 0;
    // 0x8002E700: addiu       $a0, $a0, -0x4750
    ctx->r4 = ADD32(ctx->r4, -0X4750);
    // 0x8002E704: addiu       $v1, $v1, -0x4760
    ctx->r3 = ADD32(ctx->r3, -0X4760);
L_8002E708:
    // 0x8002E708: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002E70C: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8002E710: bne         $at, $zero, L_8002E708
    if (ctx->r1 != 0) {
        // 0x8002E714: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_8002E708;
    }
    // 0x8002E714: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8002E718: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8002E71C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E720: sw          $v1, -0x2998($at)
    MEM_W(-0X2998, ctx->r1) = ctx->r3;
    // 0x8002E724: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E728: sw          $v1, -0x2994($at)
    MEM_W(-0X2994, ctx->r1) = ctx->r3;
    // 0x8002E72C: blez        $v0, L_8002E8A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002E730: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8002E8A0;
    }
    // 0x8002E730: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002E734: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8002E738: addiu       $s3, $s3, -0x3178
    ctx->r19 = ADD32(ctx->r19, -0X3178);
    // 0x8002E73C: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x8002E740: addiu       $s4, $zero, 0x44
    ctx->r20 = ADD32(0, 0X44);
L_8002E744:
    // 0x8002E744: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8002E748: nop

    // 0x8002E74C: bltz        $s0, L_8002E894
    if (SIGNED(ctx->r16) < 0) {
        // 0x8002E750: lw          $t5, 0x70($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X70);
            goto L_8002E894;
    }
    // 0x8002E750: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8002E754: beq         $s6, $zero, L_8002E7A4
    if (ctx->r22 == 0) {
        // 0x8002E758: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8002E7A4;
    }
    // 0x8002E758: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E75C: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E760: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8002E764: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8002E768: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8002E76C: mflo        $t9
    ctx->r25 = lo;
    // 0x8002E770: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8002E774: lb          $t1, 0x2B($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X2B);
    // 0x8002E778: nop

    // 0x8002E77C: beq         $t1, $zero, L_8002E7A4
    if (ctx->r9 == 0) {
        // 0x8002E780: nop
    
            goto L_8002E7A4;
    }
    // 0x8002E780: nop

    // 0x8002E784: lw          $t2, -0x26FC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X26FC);
    // 0x8002E788: nop

    // 0x8002E78C: beq         $t2, $zero, L_8002E7A4
    if (ctx->r10 == 0) {
        // 0x8002E790: nop
    
            goto L_8002E7A4;
    }
    // 0x8002E790: nop

    // 0x8002E794: jal         0x8002EF2C
    // 0x8002E798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002EEEC(rdram, ctx);
        goto after_4;
    // 0x8002E798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8002E79C: b           L_8002E894
    // 0x8002E7A0: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
        goto L_8002E894;
    // 0x8002E7A0: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
L_8002E7A4:
    // 0x8002E7A4: lwc1        $f0, 0xC($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8002E7A8: lwc1        $f12, -0x29A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x8002E7AC: lwc1        $f2, 0x14($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8002E7B0: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8002E7B4: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8002E7B8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002E7BC: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8002E7C0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002E7C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E7C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E7CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E7D0: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E7D4: lwc1        $f14, -0x29A0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X29A0);
    // 0x8002E7D8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002E7DC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002E7E0: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8002E7E4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8002E7E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002E7EC: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x8002E7F0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002E7F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E7F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E7FC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002E800: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002E804: addu        $a0, $t3, $t5
    ctx->r4 = ADD32(ctx->r11, ctx->r13);
    // 0x8002E808: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002E80C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8002E810: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8002E814: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002E818: nop

    // 0x8002E81C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002E820: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E824: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E828: nop

    // 0x8002E82C: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E830: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002E834: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8002E838: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8002E83C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002E840: nop

    // 0x8002E844: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002E848: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E84C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E850: nop

    // 0x8002E854: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002E858: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8002E85C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002E860: jal         0x8003151C
    // 0x8002E864: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    compute_grid_overlap_mask(rdram, ctx);
        goto after_5;
    // 0x8002E864: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_5:
    // 0x8002E868: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8002E86C: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8002E870: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E874: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x8002E878: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002E87C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002E880: mflo        $t2
    ctx->r10 = lo;
    // 0x8002E884: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x8002E888: jal         0x8002E944
    // 0x8002E88C: nop

    func_8002E904(rdram, ctx);
        goto after_6;
    // 0x8002E88C: nop

    after_6:
    // 0x8002E890: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
L_8002E894:
    // 0x8002E894: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002E898: bne         $s2, $t5, L_8002E744
    if (ctx->r18 != ctx->r13) {
        // 0x8002E89C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8002E744;
    }
    // 0x8002E89C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8002E8A0:
    // 0x8002E8A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002E8A4: lw          $t6, -0x3850($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3850);
    // 0x8002E8A8: nop

    // 0x8002E8AC: blez        $t6, L_8002E8F0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002E8B0: nop
    
            goto L_8002E8F0;
    }
    // 0x8002E8B0: nop

    // 0x8002E8B4: lw          $t7, 0x54($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X54);
    // 0x8002E8B8: nop

    // 0x8002E8BC: beq         $t7, $zero, L_8002E8E0
    if (ctx->r15 == 0) {
        // 0x8002E8C0: nop
    
            goto L_8002E8E0;
    }
    // 0x8002E8C0: nop

    // 0x8002E8C4: bne         $s6, $zero, L_8002E8E0
    if (ctx->r22 != 0) {
        // 0x8002E8C8: nop
    
            goto L_8002E8E0;
    }
    // 0x8002E8C8: nop

    // 0x8002E8CC: jal         0x8002FAA4
    // 0x8002E8D0: nop

    func_8002FA64(rdram, ctx);
        goto after_7;
    // 0x8002E8D0: nop

    after_7:
    // 0x8002E8D4: lw          $t8, 0x54($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X54);
    // 0x8002E8D8: nop

    // 0x8002E8DC: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
L_8002E8E0:
    // 0x8002E8E0: jal         0x8002F2EC
    // 0x8002E8E4: nop

    func_8002F2AC(rdram, ctx);
        goto after_8;
    // 0x8002E8E4: nop

    after_8:
    // 0x8002E8E8: jal         0x8002F480
    // 0x8002E8EC: nop

    func_8002F440(rdram, ctx);
        goto after_9;
    // 0x8002E8EC: nop

    after_9:
L_8002E8F0:
    // 0x8002E8F0: bne         $s6, $zero, L_8002E90C
    if (ctx->r22 != 0) {
        // 0x8002E8F4: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8002E90C;
    }
    // 0x8002E8F4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002E8F8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002E8FC: lw          $t9, -0x271C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X271C);
    // 0x8002E900: lw          $t0, 0x50($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X50);
    // 0x8002E904: b           L_8002E91C
    // 0x8002E908: sh          $t9, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r25;
        goto L_8002E91C;
    // 0x8002E908: sh          $t9, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r25;
L_8002E90C:
    // 0x8002E90C: lw          $t1, -0x271C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X271C);
    // 0x8002E910: lw          $t4, 0x58($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X58);
    // 0x8002E914: nop

    // 0x8002E918: sh          $t1, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r9;
L_8002E91C:
    // 0x8002E91C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002E920: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002E924: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8002E928: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002E92C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002E930: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8002E934: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8002E938: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8002E93C: jr          $ra
    // 0x8002E940: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8002E940: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_8002E904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E944: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x8002E948: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002E94C: lw          $v0, -0x29BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X29BC);
    // 0x8002E950: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002E954: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002E958: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002E95C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002E960: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002E964: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002E968: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002E96C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002E970: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002E974: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002E978: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002E97C: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8002E980: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002E984: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8002E988: sw          $a1, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r5;
    // 0x8002E98C: sw          $a2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r6;
    // 0x8002E990: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E994: lwc1        $f0, -0x29A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x8002E998: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E99C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E9A0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002E9A4: lwc1        $f2, -0x29A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X29A0);
    // 0x8002E9A8: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    // 0x8002E9AC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002E9B0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002E9B4: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8002E9B8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002E9BC: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    // 0x8002E9C0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E9C4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8002E9C8: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8002E9CC: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8002E9D0: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
    // 0x8002E9D4: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002E9D8: addiu       $s6, $s6, -0x4960
    ctx->r22 = ADD32(ctx->r22, -0X4960);
    // 0x8002E9DC: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8002E9E0: addiu       $s4, $s4, -0x29C4
    ctx->r20 = ADD32(ctx->r20, -0X29C4);
    // 0x8002E9E4: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x8002E9E8: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E9EC: addiu       $s3, $s3, -0x4968
    ctx->r19 = ADD32(ctx->r19, -0X4968);
    // 0x8002E9F0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8002E9F4: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8002E9F8: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x8002E9FC: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EA00: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8002EA04: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8002EA08: addiu       $s5, $sp, 0x100
    ctx->r21 = ADD32(ctx->r29, 0X100);
    // 0x8002EA0C: swc1        $f18, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f18.u32l;
    // 0x8002EA10: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EA14: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002EA18: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002EA1C: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x8002EA20: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EA24: nop

    // 0x8002EA28: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8002EA2C: swc1        $f10, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f10.u32l;
    // 0x8002EA30: lh          $a3, 0x20($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X20);
    // 0x8002EA34: nop

    // 0x8002EA38: blez        $a3, L_8002EEF0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8002EA3C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8002EEF0;
    }
    // 0x8002EA3C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8002EA40: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8002EA44: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8002EA48: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8002EA4C: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
L_8002EA50:
    // 0x8002EA50: nop

    // 0x8002EA54: beq         $t6, $zero, L_8002EA84
    if (ctx->r14 == 0) {
        // 0x8002EA58: lw          $t6, 0x158($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X158);
            goto L_8002EA84;
    }
    // 0x8002EA58: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x8002EA5C: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EA60: lw          $t7, 0xC($fp)
    ctx->r15 = MEM_W(ctx->r30, 0XC);
    // 0x8002EA64: mflo        $t8
    ctx->r24 = lo;
    // 0x8002EA68: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EA6C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8002EA70: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x8002EA74: andi        $t9, $v1, 0x2000
    ctx->r25 = ctx->r3 & 0X2000;
    // 0x8002EA78: bne         $t9, $zero, L_8002EAB8
    if (ctx->r25 != 0) {
        // 0x8002EA7C: nop
    
            goto L_8002EAB8;
    }
    // 0x8002EA7C: nop

    // 0x8002EA80: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
L_8002EA84:
    // 0x8002EA84: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x8002EA88: bne         $t6, $zero, L_8002EED4
    if (ctx->r14 != 0) {
        // 0x8002EA8C: nop
    
            goto L_8002EED4;
    }
    // 0x8002EA8C: nop

    // 0x8002EA90: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EA94: lw          $t7, 0xC($fp)
    ctx->r15 = MEM_W(ctx->r30, 0XC);
    // 0x8002EA98: mflo        $t8
    ctx->r24 = lo;
    // 0x8002EA9C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EAA0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8002EAA4: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x8002EAA8: andi        $t9, $v1, 0x6900
    ctx->r25 = ctx->r3 & 0X6900;
    // 0x8002EAAC: bne         $t9, $zero, L_8002EED4
    if (ctx->r25 != 0) {
        // 0x8002EAB0: nop
    
            goto L_8002EED4;
    }
    // 0x8002EAB0: nop

    // 0x8002EAB4: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
L_8002EAB8:
    // 0x8002EAB8: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8002EABC: lh          $s7, 0x4($v0)
    ctx->r23 = MEM_H(ctx->r2, 0X4);
    // 0x8002EAC0: lh          $a0, 0x10($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X10);
    // 0x8002EAC4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002EAC8: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8002EACC: srl         $t5, $v1, 19
    ctx->r13 = S32(U32(ctx->r3) >> 19);
    // 0x8002EAD0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8002EAD4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8002EAD8: andi        $t9, $t5, 0x7
    ctx->r25 = ctx->r13 & 0X7;
    // 0x8002EADC: slt         $at, $s7, $a0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002EAE0: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x8002EAE4: beq         $at, $zero, L_8002EED4
    if (ctx->r1 == 0) {
        // 0x8002EAE8: addu        $s1, $t7, $t8
        ctx->r17 = ADD32(ctx->r15, ctx->r24);
            goto L_8002EED4;
    }
    // 0x8002EAE8: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EAEC: sll         $ra, $s7, 1
    ctx->r31 = S32(ctx->r23 << 1);
    // 0x8002EAF0: sw          $a0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r4;
L_8002EAF4:
    // 0x8002EAF4: lw          $t6, 0x10($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X10);
    // 0x8002EAF8: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x8002EAFC: addu        $t7, $t6, $ra
    ctx->r15 = ADD32(ctx->r14, ctx->r31);
    // 0x8002EB00: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002EB04: nop

    // 0x8002EB08: and         $v0, $t8, $t9
    ctx->r2 = ctx->r24 & ctx->r25;
    // 0x8002EB0C: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8002EB10: beq         $t6, $zero, L_8002EEB8
    if (ctx->r14 == 0) {
        // 0x8002EB14: andi        $t7, $v0, 0xFF00
        ctx->r15 = ctx->r2 & 0XFF00;
            goto L_8002EEB8;
    }
    // 0x8002EB14: andi        $t7, $v0, 0xFF00
    ctx->r15 = ctx->r2 & 0XFF00;
    // 0x8002EB18: beq         $t7, $zero, L_8002EEBC
    if (ctx->r15 == 0) {
        // 0x8002EB1C: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_8002EEBC;
    }
    // 0x8002EB1C: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8002EB20: lw          $t8, 0x4($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X4);
    // 0x8002EB24: sll         $t9, $s7, 4
    ctx->r25 = S32(ctx->r23 << 4);
    // 0x8002EB28: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x8002EB2C: lbu         $t6, 0x1($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1);
    // 0x8002EB30: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002EB34: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EB38: lh          $t0, -0x29B2($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X29B2);
    // 0x8002EB3C: addiu       $v1, $a3, 0x1
    ctx->r3 = ADD32(ctx->r7, 0X1);
    // 0x8002EB40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002EB44: mflo        $t7
    ctx->r15 = lo;
    // 0x8002EB48: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8002EB4C: lh          $a1, 0x2($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X2);
    // 0x8002EB50: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002EB54: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_8002EB58:
    // 0x8002EB58: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8002EB5C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002EB60: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EB64: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EB68: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EB6C: lh          $v0, 0x2($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X2);
    // 0x8002EB70: nop

    // 0x8002EB74: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002EB78: beq         $at, $zero, L_8002EB8C
    if (ctx->r1 == 0) {
        // 0x8002EB7C: slt         $at, $a2, $v0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002EB8C;
    }
    // 0x8002EB7C: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002EB80: b           L_8002EB98
    // 0x8002EB84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8002EB98;
    // 0x8002EB84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002EB88: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_8002EB8C:
    // 0x8002EB8C: beq         $at, $zero, L_8002EB9C
    if (ctx->r1 == 0) {
        // 0x8002EB90: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_8002EB9C;
    }
    // 0x8002EB90: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8002EB94: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8002EB98:
    // 0x8002EB98: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
L_8002EB9C:
    // 0x8002EB9C: bne         $at, $zero, L_8002EB58
    if (ctx->r1 != 0) {
        // 0x8002EBA0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8002EB58;
    }
    // 0x8002EBA0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EBA4: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002EBA8: bne         $at, $zero, L_8002EEBC
    if (ctx->r1 != 0) {
        // 0x8002EBAC: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_8002EEBC;
    }
    // 0x8002EBAC: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8002EBB0: lh          $t8, -0x29B4($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X29B4);
    // 0x8002EBB4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8002EBB8: slt         $at, $a2, $t8
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002EBBC: bne         $at, $zero, L_8002EEB8
    if (ctx->r1 != 0) {
        // 0x8002EBC0: addiu       $v0, $sp, 0xD0
        ctx->r2 = ADD32(ctx->r29, 0XD0);
            goto L_8002EEB8;
    }
    // 0x8002EBC0: addiu       $v0, $sp, 0xD0
    ctx->r2 = ADD32(ctx->r29, 0XD0);
    // 0x8002EBC4: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8002EBC8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002EBCC: beq         $v0, $s5, L_8002EC2C
    if (ctx->r2 == ctx->r21) {
        // 0x8002EBD0: multu       $t9, $s2
        result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
            goto L_8002EC2C;
    }
    // 0x8002EBD0: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8002EBD4:
    // 0x8002EBD4: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EBD8: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EBDC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002EBE0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002EBE4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8002EBE8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EBEC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EBF0: swc1        $f18, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->f18.u32l;
    // 0x8002EBF4: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8002EBF8: nop

    // 0x8002EBFC: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EC00: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EC04: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EC08: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8002EC0C: sh          $s0, -0x12($v0)
    MEM_H(-0X12, ctx->r2) = ctx->r16;
    // 0x8002EC10: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8002EC14: nop

    // 0x8002EC18: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EC1C: swc1        $f18, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->f18.u32l;
    // 0x8002EC20: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8002EC24: bne         $v0, $s5, L_8002EBD4
    if (ctx->r2 != ctx->r21) {
        // 0x8002EC28: multu       $t9, $s2
        result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
            goto L_8002EBD4;
    }
    // 0x8002EC28: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8002EC2C:
    // 0x8002EC2C: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EC30: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EC34: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002EC38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EC3C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8002EC40: nop

    // 0x8002EC44: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EC48: swc1        $f18, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f18.u32l;
    // 0x8002EC4C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8002EC50: nop

    // 0x8002EC54: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EC58: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EC5C: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EC60: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8002EC64: sh          $s0, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r16;
    // 0x8002EC68: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8002EC6C: nop

    // 0x8002EC70: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EC74: swc1        $f18, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8002EC78: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8002EC7C: lwc1        $f14, 0xC4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002EC80: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    // 0x8002EC84: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8002EC88: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8002EC8C: addiu       $t6, $sp, 0xD0
    ctx->r14 = ADD32(ctx->r29, 0XD0);
    // 0x8002EC90: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8002EC94: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8002EC98: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002EC9C: jal         0x8002FDB4
    // 0x8002ECA0: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    func_8002FD74(rdram, ctx);
        goto after_0;
    // 0x8002ECA0: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    after_0:
    // 0x8002ECA4: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8002ECA8: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8002ECAC: beq         $v0, $zero, L_8002EEBC
    if (ctx->r2 == 0) {
        // 0x8002ECB0: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_8002EEBC;
    }
    // 0x8002ECB0: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8002ECB4: lw          $t7, 0x14($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X14);
    // 0x8002ECB8: sll         $t8, $s7, 3
    ctx->r24 = S32(ctx->r23 << 3);
    // 0x8002ECBC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002ECC0: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x8002ECC4: lw          $t7, 0x18($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X18);
    // 0x8002ECC8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8002ECCC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8002ECD0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002ECD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8002ECD8: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x8002ECDC: lw          $t6, 0x18($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X18);
    // 0x8002ECE0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8002ECE4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002ECE8: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8002ECEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002ECF0: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x8002ECF4: nop

    // 0x8002ECF8: bc1t        L_8002EEBC
    if (c1cs) {
        // 0x8002ECFC: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_8002EEBC;
    }
    // 0x8002ECFC: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8002ED00: lwc1        $f10, -0x2990($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2990);
    // 0x8002ED04: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x8002ED08: c.lt.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl < ctx->f10.fl;
    // 0x8002ED0C: nop

    // 0x8002ED10: bc1f        L_8002ED30
    if (!c1cs) {
        // 0x8002ED14: nop
    
            goto L_8002ED30;
    }
    // 0x8002ED14: nop

    // 0x8002ED18: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8002ED1C: jal         0x80030508
    // 0x8002ED20: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    func_800304C8(rdram, ctx);
        goto after_1;
    // 0x8002ED20: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    after_1:
    // 0x8002ED24: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8002ED28: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8002ED2C: nop

L_8002ED30:
    // 0x8002ED30: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8002ED34: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002ED38: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    // 0x8002ED3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8002ED40: addiu       $a3, $sp, 0xB0
    ctx->r7 = ADD32(ctx->r29, 0XB0);
    // 0x8002ED44: jal         0x8002FFAC
    // 0x8002ED48: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    func_8002FF6C(rdram, ctx);
        goto after_2;
    // 0x8002ED48: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    after_2:
    // 0x8002ED4C: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8002ED50: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8002ED54: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8002ED58: bne         $at, $zero, L_8002EEB8
    if (ctx->r1 != 0) {
        // 0x8002ED5C: or          $t4, $v0, $zero
        ctx->r12 = ctx->r2 | 0;
            goto L_8002EEB8;
    }
    // 0x8002ED5C: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x8002ED60: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8002ED64: lw          $t3, -0x3850($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3850);
    // 0x8002ED68: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002ED6C: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8002ED70: subu        $t9, $t9, $t3
    ctx->r25 = SUB32(ctx->r25, ctx->r11);
    // 0x8002ED74: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002ED78: addiu       $t6, $t6, -0x3848
    ctx->r14 = ADD32(ctx->r14, -0X3848);
    // 0x8002ED7C: addu        $t2, $t9, $t6
    ctx->r10 = ADD32(ctx->r25, ctx->r14);
    // 0x8002ED80: sb          $zero, 0x1($t2)
    MEM_B(0X1, ctx->r10) = 0;
    // 0x8002ED84: blez        $v0, L_8002EE84
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002ED88: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8002EE84;
    }
    // 0x8002ED88: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002ED8C: addiu       $a3, $sp, 0xD0
    ctx->r7 = ADD32(ctx->r29, 0XD0);
L_8002ED90:
    // 0x8002ED90: lh          $v1, 0xE($a3)
    ctx->r3 = MEM_H(ctx->r7, 0XE);
    // 0x8002ED94: addu        $t6, $t2, $t0
    ctx->r14 = ADD32(ctx->r10, ctx->r8);
    // 0x8002ED98: bgez        $v1, L_8002EE64
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002ED9C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8002EE64;
    }
    // 0x8002ED9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002EDA0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8002EDA4: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8002EDA8: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x8002EDAC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002EDB0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002EDB4: addiu       $t9, $t9, -0x3848
    ctx->r25 = ADD32(ctx->r25, -0X3848);
    // 0x8002EDB8: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x8002EDBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002EDC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002EDC4: blez        $a2, L_8002EE28
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8002EDC8: addu        $t1, $t8, $t9
        ctx->r9 = ADD32(ctx->r24, ctx->r25);
            goto L_8002EE28;
    }
    // 0x8002EDC8: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8002EDCC: sll         $t6, $zero, 4
    ctx->r14 = S32(0 << 4);
    // 0x8002EDD0: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002EDD4: addu        $v1, $s6, $t6
    ctx->r3 = ADD32(ctx->r22, ctx->r14);
L_8002EDD8:
    // 0x8002EDD8: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002EDDC: nop

    // 0x8002EDE0: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x8002EDE4: nop

    // 0x8002EDE8: bc1f        L_8002EE10
    if (!c1cs) {
        // 0x8002EDEC: nop
    
            goto L_8002EE10;
    }
    // 0x8002EDEC: nop

    // 0x8002EDF0: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002EDF4: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002EDF8: nop

    // 0x8002EDFC: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8002EE00: nop

    // 0x8002EE04: bc1f        L_8002EE10
    if (!c1cs) {
        // 0x8002EE08: nop
    
            goto L_8002EE10;
    }
    // 0x8002EE08: nop

    // 0x8002EE0C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8002EE10:
    // 0x8002EE10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002EE14: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002EE18: beq         $at, $zero, L_8002EE28
    if (ctx->r1 == 0) {
        // 0x8002EE1C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8002EE28;
    }
    // 0x8002EE1C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8002EE20: beq         $a1, $s0, L_8002EDD8
    if (ctx->r5 == ctx->r16) {
        // 0x8002EE24: nop
    
            goto L_8002EDD8;
    }
    // 0x8002EE24: nop

L_8002EE28:
    // 0x8002EE28: bne         $a1, $s0, L_8002EE5C
    if (ctx->r5 != ctx->r16) {
        // 0x8002EE2C: sll         $t7, $a2, 4
        ctx->r15 = S32(ctx->r6 << 4);
            goto L_8002EE5C;
    }
    // 0x8002EE2C: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x8002EE30: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002EE34: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8002EE38: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002EE3C: addu        $v1, $s6, $t7
    ctx->r3 = ADD32(ctx->r22, ctx->r15);
    // 0x8002EE40: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
    // 0x8002EE44: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8002EE48: sb          $a2, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r6;
    // 0x8002EE4C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8002EE50: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x8002EE54: b           L_8002EE78
    // 0x8002EE58: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
        goto L_8002EE78;
    // 0x8002EE58: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
L_8002EE5C:
    // 0x8002EE5C: b           L_8002EE78
    // 0x8002EE60: sb          $a1, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r5;
        goto L_8002EE78;
    // 0x8002EE60: sb          $a1, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r5;
L_8002EE64:
    // 0x8002EE64: sb          $v1, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r3;
    // 0x8002EE68: lbu         $t7, 0x1($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X1);
    // 0x8002EE6C: sllv        $t9, $t8, $t0
    ctx->r25 = S32(ctx->r24 << (ctx->r8 & 31));
    // 0x8002EE70: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8002EE74: sb          $t6, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r14;
L_8002EE78:
    // 0x8002EE78: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8002EE7C: bne         $t0, $t4, L_8002ED90
    if (ctx->r8 != ctx->r12) {
        // 0x8002EE80: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8002ED90;
    }
    // 0x8002EE80: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_8002EE84:
    // 0x8002EE84: sb          $v0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r2;
    // 0x8002EE88: sh          $t5, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r13;
    // 0x8002EE8C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002EE90: lw          $v1, -0x2998($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2998);
    // 0x8002EE94: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x8002EE98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EE9C: bltz        $v1, L_8002EEB0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8002EEA0: sw          $t8, -0x3850($at)
        MEM_W(-0X3850, ctx->r1) = ctx->r24;
            goto L_8002EEB0;
    }
    // 0x8002EEA0: sw          $t8, -0x3850($at)
    MEM_W(-0X3850, ctx->r1) = ctx->r24;
    // 0x8002EEA4: beq         $t5, $v1, L_8002EEB0
    if (ctx->r13 == ctx->r3) {
        // 0x8002EEA8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8002EEB0;
    }
    // 0x8002EEA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EEAC: sw          $zero, -0x2994($at)
    MEM_W(-0X2994, ctx->r1) = 0;
L_8002EEB0:
    // 0x8002EEB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EEB4: sw          $t5, -0x2998($at)
    MEM_W(-0X2998, ctx->r1) = ctx->r13;
L_8002EEB8:
    // 0x8002EEB8: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
L_8002EEBC:
    // 0x8002EEBC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002EEC0: slt         $at, $s7, $t7
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002EEC4: bne         $at, $zero, L_8002EAF4
    if (ctx->r1 != 0) {
        // 0x8002EEC8: addiu       $ra, $ra, 0x2
        ctx->r31 = ADD32(ctx->r31, 0X2);
            goto L_8002EAF4;
    }
    // 0x8002EEC8: addiu       $ra, $ra, 0x2
    ctx->r31 = ADD32(ctx->r31, 0X2);
    // 0x8002EECC: lh          $a3, 0x20($fp)
    ctx->r7 = MEM_H(ctx->r30, 0X20);
    // 0x8002EED0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_8002EED4:
    // 0x8002EED4: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x8002EED8: nop

    // 0x8002EEDC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8002EEE0: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8002EEE4: bne         $at, $zero, L_8002EA50
    if (ctx->r1 != 0) {
        // 0x8002EEE8: lw          $t6, 0x158($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X158);
            goto L_8002EA50;
    }
    // 0x8002EEE8: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x8002EEEC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8002EEF0:
    // 0x8002EEF0: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002EEF4: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002EEF8: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002EEFC: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002EF00: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002EF04: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8002EF08: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002EF0C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002EF10: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002EF14: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8002EF18: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8002EF1C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8002EF20: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8002EF24: jr          $ra
    // 0x8002EF28: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x8002EF28: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void func_8002EEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EF2C: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x8002EF30: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002EF34: lw          $v0, -0x29BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X29BC);
    // 0x8002EF38: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002EF3C: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x8002EF40: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8002EF44: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8002EF48: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8002EF4C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8002EF50: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8002EF54: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8002EF58: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8002EF5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EF60: lwc1        $f0, -0x29A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x8002EF64: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EF68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EF6C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002EF70: lwc1        $f2, -0x29A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X29A0);
    // 0x8002EF74: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x8002EF78: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EF7C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8002EF80: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8002EF84: addiu       $s7, $s7, -0x29C8
    ctx->r23 = ADD32(ctx->r23, -0X29C8);
    // 0x8002EF88: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x8002EF8C: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EF90: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8002EF94: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8002EF98: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002EF9C: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x8002EFA0: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EFA4: addiu       $t8, $t8, -0x31C8
    ctx->r24 = ADD32(ctx->r24, -0X31C8);
    // 0x8002EFA8: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8002EFAC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002EFB0: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x8002EFB4: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EFB8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8002EFBC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8002EFC0: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EFC4: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x8002EFC8: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EFCC: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    // 0x8002EFD0: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8002EFD4: addiu       $a1, $a1, -0x36C8
    ctx->r5 = ADD32(ctx->r5, -0X36C8);
    // 0x8002EFD8: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x8002EFDC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EFE0: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8002EFE4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002EFE8: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8002EFEC: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x8002EFF0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EFF4: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002EFF8: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8002EFFC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8002F000: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
    // 0x8002F004: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8002F008: jal         0x800BE1A0
    // 0x8002F00C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800BDC80(rdram, ctx);
        goto after_0;
    // 0x8002F00C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8002F010: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8002F014: blez        $v0, L_8002F2B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002F018: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8002F2B4;
    }
    // 0x8002F018: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8002F01C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002F020: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002F024: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002F028: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002F02C: addiu       $s1, $s1, -0x29C4
    ctx->r17 = ADD32(ctx->r17, -0X29C4);
    // 0x8002F030: addiu       $s3, $s3, -0x4960
    ctx->r19 = ADD32(ctx->r19, -0X4960);
    // 0x8002F034: addiu       $s5, $s5, -0x3850
    ctx->r21 = ADD32(ctx->r21, -0X3850);
    // 0x8002F038: addiu       $s0, $s0, -0x36C8
    ctx->r16 = ADD32(ctx->r16, -0X36C8);
    // 0x8002F03C: addiu       $s2, $sp, 0xD8
    ctx->r18 = ADD32(ctx->r29, 0XD8);
    // 0x8002F040: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8002F044:
    // 0x8002F044: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x8002F048: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
    // 0x8002F04C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8002F050: lh          $a2, -0x29B2($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X29B2);
    // 0x8002F054: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002F058: beq         $at, $zero, L_8002F068
    if (ctx->r1 == 0) {
        // 0x8002F05C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8002F068;
    }
    // 0x8002F05C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002F060: b           L_8002F078
    // 0x8002F064: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_8002F078;
    // 0x8002F064: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_8002F068:
    // 0x8002F068: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002F06C: beq         $at, $zero, L_8002F078
    if (ctx->r1 == 0) {
        // 0x8002F070: nop
    
            goto L_8002F078;
    }
    // 0x8002F070: nop

    // 0x8002F074: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8002F078:
    // 0x8002F078: lh          $v0, 0xE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE);
    // 0x8002F07C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002F080: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002F084: beq         $at, $zero, L_8002F098
    if (ctx->r1 == 0) {
        // 0x8002F088: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002F098;
    }
    // 0x8002F088: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002F08C: b           L_8002F0A4
    // 0x8002F090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8002F0A4;
    // 0x8002F090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002F094: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_8002F098:
    // 0x8002F098: beq         $at, $zero, L_8002F0A8
    if (ctx->r1 == 0) {
        // 0x8002F09C: slt         $at, $a2, $a0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8002F0A8;
    }
    // 0x8002F09C: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002F0A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8002F0A4:
    // 0x8002F0A4: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
L_8002F0A8:
    // 0x8002F0A8: bne         $at, $zero, L_8002F2A4
    if (ctx->r1 != 0) {
        // 0x8002F0AC: nop
    
            goto L_8002F2A4;
    }
    // 0x8002F0AC: nop

    // 0x8002F0B0: lh          $t9, -0x29B4($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X29B4);
    // 0x8002F0B4: addiu       $v0, $sp, 0xA8
    ctx->r2 = ADD32(ctx->r29, 0XA8);
    // 0x8002F0B8: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002F0BC: bne         $at, $zero, L_8002F2A4
    if (ctx->r1 != 0) {
        // 0x8002F0C0: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_8002F2A4;
    }
    // 0x8002F0C0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002F0C4: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8002F0C8: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x8002F0CC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8002F0D0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8002F0D4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002F0D8: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x8002F0DC: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x8002F0E0: mtc1        $t8, $f14
    ctx->f14.u32l = ctx->r24;
    // 0x8002F0E4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002F0E8: mtc1        $t9, $f12
    ctx->f12.u32l = ctx->r25;
    // 0x8002F0EC: lh          $t6, 0xC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XC);
    // 0x8002F0F0: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8002F0F4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8002F0F8: lh          $t7, 0x10($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X10);
    // 0x8002F0FC: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x8002F100: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8002F104: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x8002F108: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002F10C: swc1        $f16, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f16.u32l;
    // 0x8002F110: swc1        $f14, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f14.u32l;
    // 0x8002F114: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002F118: swc1        $f12, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f12.u32l;
    // 0x8002F11C: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x8002F120: swc1        $f8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f8.u32l;
L_8002F124:
    // 0x8002F124: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002F128: bne         $v0, $s2, L_8002F124
    if (ctx->r2 != ctx->r18) {
        // 0x8002F12C: sh          $t0, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r8;
            goto L_8002F124;
    }
    // 0x8002F12C: sh          $t0, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r8;
    // 0x8002F130: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8002F134: sll         $t6, $s4, 4
    ctx->r14 = S32(ctx->r20 << 4);
    // 0x8002F138: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8002F13C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002F140: addiu       $t8, $t8, -0x31C8
    ctx->r24 = ADD32(ctx->r24, -0X31C8);
    // 0x8002F144: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002F148: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002F14C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8002F150: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x8002F154: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8002F158: jal         0x8002FFAC
    // 0x8002F15C: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    func_8002FF6C(rdram, ctx);
        goto after_1;
    // 0x8002F15C: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    after_1:
    // 0x8002F160: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002F164: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8002F168: addiu       $t5, $t5, -0x4968
    ctx->r13 = ADD32(ctx->r13, -0X4968);
    // 0x8002F16C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8002F170: bne         $at, $zero, L_8002F2A4
    if (ctx->r1 != 0) {
        // 0x8002F174: or          $ra, $v0, $zero
        ctx->r31 = ctx->r2 | 0;
            goto L_8002F2A4;
    }
    // 0x8002F174: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
    // 0x8002F178: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x8002F17C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002F180: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8002F184: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x8002F188: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002F18C: addiu       $t7, $t7, -0x3848
    ctx->r15 = ADD32(ctx->r15, -0X3848);
    // 0x8002F190: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
    // 0x8002F194: sb          $zero, 0x1($t3)
    MEM_B(0X1, ctx->r11) = 0;
    // 0x8002F198: blez        $v0, L_8002F298
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002F19C: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8002F298;
    }
    // 0x8002F19C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8002F1A0: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
L_8002F1A4:
    // 0x8002F1A4: lh          $v1, 0xE($a3)
    ctx->r3 = MEM_H(ctx->r7, 0XE);
    // 0x8002F1A8: addu        $t7, $t3, $t1
    ctx->r15 = ADD32(ctx->r11, ctx->r9);
    // 0x8002F1AC: bgez        $v1, L_8002F278
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002F1B0: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8002F278;
    }
    // 0x8002F1B0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002F1B4: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8002F1B8: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x8002F1BC: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x8002F1C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002F1C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002F1C8: addiu       $t6, $t6, -0x3848
    ctx->r14 = ADD32(ctx->r14, -0X3848);
    // 0x8002F1CC: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x8002F1D0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8002F1D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002F1D8: blez        $a2, L_8002F23C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8002F1DC: addu        $t2, $t9, $t6
        ctx->r10 = ADD32(ctx->r25, ctx->r14);
            goto L_8002F23C;
    }
    // 0x8002F1DC: addu        $t2, $t9, $t6
    ctx->r10 = ADD32(ctx->r25, ctx->r14);
    // 0x8002F1E0: sll         $t7, $zero, 4
    ctx->r15 = S32(0 << 4);
    // 0x8002F1E4: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002F1E8: addu        $a0, $s3, $t7
    ctx->r4 = ADD32(ctx->r19, ctx->r15);
L_8002F1EC:
    // 0x8002F1EC: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002F1F0: nop

    // 0x8002F1F4: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x8002F1F8: nop

    // 0x8002F1FC: bc1f        L_8002F224
    if (!c1cs) {
        // 0x8002F200: nop
    
            goto L_8002F224;
    }
    // 0x8002F200: nop

    // 0x8002F204: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8002F208: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002F20C: nop

    // 0x8002F210: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8002F214: nop

    // 0x8002F218: bc1f        L_8002F224
    if (!c1cs) {
        // 0x8002F21C: nop
    
            goto L_8002F224;
    }
    // 0x8002F21C: nop

    // 0x8002F220: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8002F224:
    // 0x8002F224: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F228: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002F22C: beq         $at, $zero, L_8002F23C
    if (ctx->r1 == 0) {
        // 0x8002F230: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8002F23C;
    }
    // 0x8002F230: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002F234: beq         $a1, $t0, L_8002F1EC
    if (ctx->r5 == ctx->r8) {
        // 0x8002F238: nop
    
            goto L_8002F1EC;
    }
    // 0x8002F238: nop

L_8002F23C:
    // 0x8002F23C: bne         $a1, $t0, L_8002F270
    if (ctx->r5 != ctx->r8) {
        // 0x8002F240: sll         $t8, $a2, 4
        ctx->r24 = S32(ctx->r6 << 4);
            goto L_8002F270;
    }
    // 0x8002F240: sll         $t8, $a2, 4
    ctx->r24 = S32(ctx->r6 << 4);
    // 0x8002F244: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002F248: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002F24C: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002F250: addu        $v1, $s3, $t8
    ctx->r3 = ADD32(ctx->r19, ctx->r24);
    // 0x8002F254: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x8002F258: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8002F25C: sb          $a2, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r6;
    // 0x8002F260: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x8002F264: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x8002F268: b           L_8002F28C
    // 0x8002F26C: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
        goto L_8002F28C;
    // 0x8002F26C: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
L_8002F270:
    // 0x8002F270: b           L_8002F28C
    // 0x8002F274: sb          $a1, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r5;
        goto L_8002F28C;
    // 0x8002F274: sb          $a1, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r5;
L_8002F278:
    // 0x8002F278: sb          $v1, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r3;
    // 0x8002F27C: lbu         $t8, 0x1($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X1);
    // 0x8002F280: sllv        $t6, $t9, $t1
    ctx->r14 = S32(ctx->r25 << (ctx->r9 & 31));
    // 0x8002F284: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8002F288: sb          $t7, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r15;
L_8002F28C:
    // 0x8002F28C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8002F290: bne         $t1, $ra, L_8002F1A4
    if (ctx->r9 != ctx->r31) {
        // 0x8002F294: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8002F1A4;
    }
    // 0x8002F294: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_8002F298:
    // 0x8002F298: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x8002F29C: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x8002F2A0: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
L_8002F2A4:
    // 0x8002F2A4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002F2A8: slt         $at, $s4, $s6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002F2AC: bne         $at, $zero, L_8002F044
    if (ctx->r1 != 0) {
        // 0x8002F2B0: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_8002F044;
    }
    // 0x8002F2B0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_8002F2B4:
    // 0x8002F2B4: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8002F2B8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002F2BC: addu        $t6, $t8, $s6
    ctx->r14 = ADD32(ctx->r24, ctx->r22);
    // 0x8002F2C0: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x8002F2C4: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x8002F2C8: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x8002F2CC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8002F2D0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8002F2D4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8002F2D8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8002F2DC: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8002F2E0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8002F2E4: jr          $ra
    // 0x8002F2E8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x8002F2E8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void func_8002F2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F2EC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002F2F0: lw          $v1, -0x4968($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4968);
    // 0x8002F2F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002F2F8: blez        $v1, L_8002F39C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002F2FC: addiu       $a0, $t6, -0x4960
        ctx->r4 = ADD32(ctx->r14, -0X4960);
            goto L_8002F39C;
    }
    // 0x8002F2FC: addiu       $a0, $t6, -0x4960
    ctx->r4 = ADD32(ctx->r14, -0X4960);
    // 0x8002F300: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8002F304: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x8002F308: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002F30C: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8002F310: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8002F314: lwc1        $f18, -0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, -0X10);
    // 0x8002F318: beq         $at, $zero, L_8002F368
    if (ctx->r1 == 0) {
        // 0x8002F31C: nop
    
            goto L_8002F368;
    }
    // 0x8002F31C: nop

L_8002F320:
    // 0x8002F320: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F324: lwc1        $f14, -0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8002F328: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002F32C: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F330: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002F334: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F338: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002F33C: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002F340: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002F344: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8002F348: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8002F34C: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8002F350: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8002F354: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x8002F358: nop

    // 0x8002F35C: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002F360: bne         $at, $zero, L_8002F320
    if (ctx->r1 != 0) {
        // 0x8002F364: swc1        $f8, -0x1C($a0)
        MEM_W(-0X1C, ctx->r4) = ctx->f8.u32l;
            goto L_8002F320;
    }
    // 0x8002F364: swc1        $f8, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = ctx->f8.u32l;
L_8002F368:
    // 0x8002F368: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F36C: lwc1        $f14, -0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8002F370: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002F374: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F378: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002F37C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F380: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002F384: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8002F388: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8002F38C: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x8002F390: nop

    // 0x8002F394: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002F398: swc1        $f8, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f8.u32l;
L_8002F39C:
    // 0x8002F39C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002F3A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002F3A4: addiu       $t0, $t0, -0x4750
    ctx->r8 = ADD32(ctx->r8, -0X4750);
    // 0x8002F3A8: addiu       $a1, $a1, -0x4760
    ctx->r5 = ADD32(ctx->r5, -0X4760);
    // 0x8002F3AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8002F3B0:
    // 0x8002F3B0: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x8002F3B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002F3B8: blez        $a2, L_8002F46C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8002F3BC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8002F46C;
    }
    // 0x8002F3BC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8002F3C0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002F3C4: addiu       $t9, $t9, -0x4750
    ctx->r25 = ADD32(ctx->r25, -0X4750);
    // 0x8002F3C8: sll         $t8, $v0, 5
    ctx->r24 = S32(ctx->r2 << 5);
    // 0x8002F3CC: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x8002F3D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F3D4: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002F3D8: lw          $v0, 0xC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC);
    // 0x8002F3DC: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002F3E0: beq         $at, $zero, L_8002F434
    if (ctx->r1 == 0) {
        // 0x8002F3E4: nop
    
            goto L_8002F434;
    }
    // 0x8002F3E4: nop

L_8002F3E8:
    // 0x8002F3E8: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F3EC: lwc1        $f14, 0x8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002F3F0: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002F3F4: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F3F8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002F3FC: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F400: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002F404: lwc1        $f18, 0x20($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X20);
    // 0x8002F408: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F40C: lw          $v0, 0x2C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X2C);
    // 0x8002F410: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8002F414: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002F418: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8002F41C: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x8002F420: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x8002F424: nop

    // 0x8002F428: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002F42C: bne         $at, $zero, L_8002F3E8
    if (ctx->r1 != 0) {
        // 0x8002F430: swc1        $f8, -0x1C($a3)
        MEM_W(-0X1C, ctx->r7) = ctx->f8.u32l;
            goto L_8002F3E8;
    }
    // 0x8002F430: swc1        $f8, -0x1C($a3)
    MEM_W(-0X1C, ctx->r7) = ctx->f8.u32l;
L_8002F434:
    // 0x8002F434: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F438: lwc1        $f14, 0x8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002F43C: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002F440: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F444: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002F448: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F44C: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002F450: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x8002F454: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8002F458: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8002F45C: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x8002F460: nop

    // 0x8002F464: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002F468: swc1        $f8, -0x1C($a3)
    MEM_W(-0X1C, ctx->r7) = ctx->f8.u32l;
L_8002F46C:
    // 0x8002F46C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8002F470: bne         $a1, $t0, L_8002F3B0
    if (ctx->r5 != ctx->r8) {
        // 0x8002F474: addiu       $a0, $a0, 0x20
        ctx->r4 = ADD32(ctx->r4, 0X20);
            goto L_8002F3B0;
    }
    // 0x8002F474: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8002F478: jr          $ra
    // 0x8002F47C: nop

    return;
    // 0x8002F47C: nop

;}
RECOMP_FUNC void func_8002F440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F480: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8002F484: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002F488: addiu       $t4, $t4, -0x29BC
    ctx->r12 = ADD32(ctx->r12, -0X29BC);
    // 0x8002F48C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8002F490: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002F494: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002F498: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002F49C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002F4A0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002F4A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002F4A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002F4AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002F4B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002F4B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002F4B8: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    // 0x8002F4BC: jal         0x80070A04
    // 0x8002F4C0: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x8002F4C0: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    after_0:
    // 0x8002F4C4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002F4C8: addiu       $t4, $t4, -0x29BC
    ctx->r12 = ADD32(ctx->r12, -0X29BC);
    // 0x8002F4CC: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8002F4D0: nop

    // 0x8002F4D4: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x8002F4D8: jal         0x80070A38
    // 0x8002F4DC: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x8002F4DC: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8002F4E0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002F4E4: lw          $t8, -0x29C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X29C0);
    // 0x8002F4E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002F4EC: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8002F4F0: lwc1        $f6, -0x29A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x8002F4F4: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8002F4F8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002F4FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002F500: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002F504: lwc1        $f8, 0x64E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64E4);
    // 0x8002F508: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002F50C: div.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8002F510: lwc1        $f12, -0x2990($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2990);
    // 0x8002F514: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002F518: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002F51C: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x8002F520: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8002F524: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002F528: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8002F52C: addiu       $t4, $t4, -0x29BC
    ctx->r12 = ADD32(ctx->r12, -0X29BC);
    // 0x8002F530: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002F534: addiu       $fp, $fp, -0x271C
    ctx->r30 = ADD32(ctx->r30, -0X271C);
    // 0x8002F538: addiu       $t5, $t5, -0x3848
    ctx->r13 = ADD32(ctx->r13, -0X3848);
    // 0x8002F53C: mul.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8002F540: bc1f        L_8002F5FC
    if (!c1cs) {
        // 0x8002F544: addiu       $s6, $zero, 0x40
        ctx->r22 = ADD32(0, 0X40);
            goto L_8002F5FC;
    }
    // 0x8002F544: addiu       $s6, $zero, 0x40
    ctx->r22 = ADD32(0, 0X40);
    // 0x8002F548: lh          $t8, -0x29B0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X29B0);
    // 0x8002F54C: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8002F550: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8002F554: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8002F558: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002F55C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8002F560: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8002F564: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8002F568: nop

    // 0x8002F56C: bc1f        L_8002F5C4
    if (!c1cs) {
        // 0x8002F570: nop
    
            goto L_8002F5C4;
    }
    // 0x8002F570: nop

    // 0x8002F574: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002F578: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8002F57C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002F580: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8002F584: lwc1        $f8, -0x298C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X298C);
    // 0x8002F588: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8002F58C: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8002F590: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002F594: nop

    // 0x8002F598: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002F59C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F5A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F5A4: nop

    // 0x8002F5A8: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002F5AC: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8002F5B0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002F5B4: subu        $s7, $t7, $t6
    ctx->r23 = SUB32(ctx->r15, ctx->r14);
    // 0x8002F5B8: bgez        $s7, L_8002F5C4
    if (SIGNED(ctx->r23) >= 0) {
        // 0x8002F5BC: nop
    
            goto L_8002F5C4;
    }
    // 0x8002F5BC: nop

    // 0x8002F5C0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8002F5C4:
    // 0x8002F5C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002F5C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002F5CC: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8002F5D0: nop

    // 0x8002F5D4: bc1f        L_8002F5FC
    if (!c1cs) {
        // 0x8002F5D8: nop
    
            goto L_8002F5FC;
    }
    // 0x8002F5D8: nop

    // 0x8002F5DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002F5E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002F5E4: lwc1        $f10, 0x64E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64E8);
    // 0x8002F5E8: nop

    // 0x8002F5EC: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8002F5F0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002F5F4: mul.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8002F5F8: nop

L_8002F5FC:
    // 0x8002F5FC: mtc1        $s7, $f10
    ctx->f10.u32l = ctx->r23;
    // 0x8002F600: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002F604: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002F608: lwc1        $f6, -0x29AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X29AC);
    // 0x8002F60C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002F610: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8002F614: lw          $t9, -0x3850($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3850);
    // 0x8002F618: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002F61C: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002F620: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002F624: addiu       $s2, $zero, 0x19
    ctx->r18 = ADD32(0, 0X19);
    // 0x8002F628: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002F62C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F630: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F634: addiu       $s4, $s4, -0x2738
    ctx->r20 = ADD32(ctx->r20, -0X2738);
    // 0x8002F638: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002F63C: addiu       $s5, $s5, -0x2750
    ctx->r21 = ADD32(ctx->r21, -0X2750);
    // 0x8002F640: mfc1        $s7, $f10
    ctx->r23 = (int32_t)ctx->f10.u32l;
    // 0x8002F644: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002F648: blez        $t9, L_8002FA74
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8002F64C: sw          $zero, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = 0;
            goto L_8002FA74;
    }
    // 0x8002F64C: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x8002F650: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002F654: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002F658: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8002F65C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8002F660: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002F664: addiu       $t1, $t1, -0x4750
    ctx->r9 = ADD32(ctx->r9, -0X4750);
    // 0x8002F668: addiu       $t2, $t2, -0x4960
    ctx->r10 = ADD32(ctx->r10, -0X4960);
    // 0x8002F66C: addiu       $ra, $ra, -0x2718
    ctx->r31 = ADD32(ctx->r31, -0X2718);
    // 0x8002F670: addiu       $s0, $s0, -0x2714
    ctx->r16 = ADD32(ctx->r16, -0X2714);
    // 0x8002F674: addiu       $s1, $s1, -0x29B8
    ctx->r17 = ADD32(ctx->r17, -0X29B8);
    // 0x8002F678: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x8002F67C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_8002F680:
    // 0x8002F680: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x8002F684: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002F688: addu        $t7, $v0, $s2
    ctx->r15 = ADD32(ctx->r2, ctx->r18);
    // 0x8002F68C: slti        $at, $t7, 0x18
    ctx->r1 = SIGNED(ctx->r15) < 0X18 ? 1 : 0;
    // 0x8002F690: bne         $at, $zero, L_8002F6F8
    if (ctx->r1 != 0) {
        // 0x8002F694: addiu       $v1, $v1, -0x2720
        ctx->r3 = ADD32(ctx->r3, -0X2720);
            goto L_8002F6F8;
    }
    // 0x8002F694: addiu       $v1, $v1, -0x2720
    ctx->r3 = ADD32(ctx->r3, -0X2720);
    // 0x8002F698: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x8002F69C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8002F6A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002F6A4: lw          $t6, -0x29C0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X29C0);
    // 0x8002F6A8: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x8002F6AC: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8002F6B0: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8002F6B4: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x8002F6B8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8002F6BC: lw          $t8, 0x0($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X0);
    // 0x8002F6C0: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x8002F6C4: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x8002F6C8: sh          $t8, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r24;
    // 0x8002F6CC: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8002F6D0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8002F6D4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8002F6D8: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x8002F6DC: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8002F6E0: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    // 0x8002F6E4: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x8002F6E8: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x8002F6EC: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8002F6F0: sw          $t6, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r14;
    // 0x8002F6F4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8002F6F8:
    // 0x8002F6F8: lbu         $t0, 0x1($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X1);
    // 0x8002F6FC: blez        $v0, L_8002F9A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002F700: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8002F9A8;
    }
    // 0x8002F700: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002F704: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8002F708: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002F70C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002F710: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8002F714: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002F718: addiu       $t9, $t9, -0x3848
    ctx->r25 = ADD32(ctx->r25, -0X3848);
    // 0x8002F71C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8002F720: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x8002F724: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
L_8002F728:
    // 0x8002F728: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002F72C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8002F730: multu       $a0, $s3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002F734: andi        $t9, $t0, 0x1
    ctx->r25 = ctx->r8 & 0X1;
    // 0x8002F738: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x8002F73C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8002F740: mflo        $t6
    ctx->r14 = lo;
    // 0x8002F744: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8002F748: beq         $t9, $zero, L_8002F828
    if (ctx->r25 == 0) {
        // 0x8002F74C: nop
    
            goto L_8002F828;
    }
    // 0x8002F74C: nop

    // 0x8002F750: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F754: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002F758: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8002F75C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002F760: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F764: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8002F768: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8002F76C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F770: nop

    // 0x8002F774: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F778: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8002F77C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002F780: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x8002F784: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F788: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x8002F78C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8002F790: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    // 0x8002F794: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002F798: lwc1        $f10, 0xC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8002F79C: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8002F7A0: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8002F7A4: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8002F7A8: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002F7AC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002F7B0: nop

    // 0x8002F7B4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002F7B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F7BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F7C0: nop

    // 0x8002F7C4: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002F7C8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8002F7CC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002F7D0: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x8002F7D4: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F7D8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002F7DC: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8002F7E0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002F7E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F7E8: addu        $t6, $t1, $t9
    ctx->r14 = ADD32(ctx->r9, ctx->r25);
    // 0x8002F7EC: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8002F7F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F7F4: nop

    // 0x8002F7F8: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F7FC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8002F800: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002F804: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x8002F808: lbu         $t9, 0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F80C: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8002F810: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x8002F814: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x8002F818: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8002F81C: lwc1        $f10, 0x14($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8002F820: b           L_8002F900
    // 0x8002F824: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
        goto L_8002F900;
    // 0x8002F824: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
L_8002F828:
    // 0x8002F828: lbu         $t9, 0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F82C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002F830: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8002F834: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002F838: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F83C: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8002F840: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002F844: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F848: nop

    // 0x8002F84C: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F850: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8002F854: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002F858: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8002F85C: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F860: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8002F864: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8002F868: addu        $a0, $t2, $t7
    ctx->r4 = ADD32(ctx->r10, ctx->r15);
    // 0x8002F86C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002F870: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8002F874: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8002F878: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8002F87C: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8002F880: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002F884: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002F888: nop

    // 0x8002F88C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002F890: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F894: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F898: nop

    // 0x8002F89C: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002F8A0: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8002F8A4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002F8A8: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x8002F8AC: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F8B0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002F8B4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8002F8B8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002F8BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F8C0: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x8002F8C4: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8002F8C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F8CC: nop

    // 0x8002F8D0: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F8D4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8002F8D8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002F8DC: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x8002F8E0: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F8E4: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8002F8E8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8002F8EC: addu        $t6, $t2, $t9
    ctx->r14 = ADD32(ctx->r10, ctx->r25);
    // 0x8002F8F0: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8002F8F4: lwc1        $f10, 0x14($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X14);
    // 0x8002F8F8: nop

    // 0x8002F8FC: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
L_8002F900:
    // 0x8002F900: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8002F904: sra         $t8, $t0, 1
    ctx->r24 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8002F908: sb          $t3, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r11;
    // 0x8002F90C: sb          $t3, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r11;
    // 0x8002F910: mul.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8002F914: sb          $t3, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r11;
    // 0x8002F918: sb          $s7, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r23;
    // 0x8002F91C: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x8002F920: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8002F924: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8002F928: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8002F92C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002F930: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F934: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8002F938: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8002F93C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002F940: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002F944: nop

    // 0x8002F948: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002F94C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F950: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F954: nop

    // 0x8002F958: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F95C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002F960: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8002F964: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8002F968: sh          $t6, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r14;
    // 0x8002F96C: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8002F970: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002F974: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8002F978: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8002F97C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002F980: nop

    // 0x8002F984: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002F988: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F98C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F990: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002F994: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002F998: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8002F99C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002F9A0: bne         $at, $zero, L_8002F728
    if (ctx->r1 != 0) {
        // 0x8002F9A4: sh          $t8, -0x2($a2)
        MEM_H(-0X2, ctx->r6) = ctx->r24;
            goto L_8002F728;
    }
    // 0x8002F9A4: sh          $t8, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r24;
L_8002F9A8:
    // 0x8002F9A8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8002F9AC: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8002F9B0: bne         $at, $zero, L_8002FA50
    if (ctx->r1 != 0) {
        // 0x8002F9B4: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8002FA50;
    }
    // 0x8002F9B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002F9B8: addiu       $a0, $s2, 0x1
    ctx->r4 = ADD32(ctx->r18, 0X1);
    // 0x8002F9BC: addiu       $t0, $a0, 0x1
    ctx->r8 = ADD32(ctx->r4, 0X1);
    // 0x8002F9C0: addiu       $a1, $sp, 0x92
    ctx->r5 = ADD32(ctx->r29, 0X92);
    // 0x8002F9C4: addiu       $a2, $sp, 0x82
    ctx->r6 = ADD32(ctx->r29, 0X82);
L_8002F9C8:
    // 0x8002F9C8: lw          $v1, 0x0($ra)
    ctx->r3 = MEM_W(ctx->r31, 0X0);
    // 0x8002F9CC: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8002F9D0: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x8002F9D4: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8002F9D8: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
    // 0x8002F9DC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8002F9E0: sb          $s6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r22;
    // 0x8002F9E4: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x8002F9E8: sb          $t0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r8;
    // 0x8002F9EC: sb          $s2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r18;
    // 0x8002F9F0: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x8002F9F4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002F9F8: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x8002F9FC: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x8002FA00: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8002FA04: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x8002FA08: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x8002FA0C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002FA10: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x8002FA14: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x8002FA18: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8002FA1C: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x8002FA20: lh          $t9, 0x90($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X90);
    // 0x8002FA24: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002FA28: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
    // 0x8002FA2C: lh          $t6, 0x80($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X80);
    // 0x8002FA30: nop

    // 0x8002FA34: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
    // 0x8002FA38: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x8002FA3C: nop

    // 0x8002FA40: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8002FA44: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002FA48: bne         $at, $zero, L_8002F9C8
    if (ctx->r1 != 0) {
        // 0x8002FA4C: nop
    
            goto L_8002F9C8;
    }
    // 0x8002FA4C: nop

L_8002FA50:
    // 0x8002FA50: lw          $v1, 0xAC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XAC);
    // 0x8002FA54: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002FA58: lw          $t8, -0x3850($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3850);
    // 0x8002FA5C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002FA60: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002FA64: sw          $v1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r3;
    // 0x8002FA68: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8002FA6C: bne         $at, $zero, L_8002F680
    if (ctx->r1 != 0) {
        // 0x8002FA70: addu        $s2, $s2, $v0
        ctx->r18 = ADD32(ctx->r18, ctx->r2);
            goto L_8002F680;
    }
    // 0x8002FA70: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_8002FA74:
    // 0x8002FA74: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002FA78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002FA7C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FA80: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002FA84: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002FA88: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002FA8C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002FA90: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002FA94: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002FA98: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002FA9C: jr          $ra
    // 0x8002FAA0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8002FAA0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_8002FA64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FAA4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8002FAA8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002FAAC: lw          $v1, -0x3850($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3850);
    // 0x8002FAB0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002FAB4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8002FAB8: sw          $s7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r23;
    // 0x8002FABC: sw          $s6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r22;
    // 0x8002FAC0: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x8002FAC4: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x8002FAC8: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x8002FACC: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x8002FAD0: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8002FAD4: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x8002FAD8: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8002FADC: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x8002FAE0: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002FAE4: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8002FAE8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002FAEC: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8002FAF0: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002FAF4: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8002FAF8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002FAFC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002FB00: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002FB04: blez        $v1, L_8002FD48
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002FB08: swc1        $f20, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
            goto L_8002FD48;
    }
    // 0x8002FB08: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002FB0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002FB10: lw          $t6, -0x2994($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2994);
    // 0x8002FB14: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002FB18: beq         $t6, $zero, L_8002FB54
    if (ctx->r14 == 0) {
        // 0x8002FB1C: nop
    
            goto L_8002FB54;
    }
    // 0x8002FB1C: nop

    // 0x8002FB20: lw          $v0, -0x2998($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2998);
    // 0x8002FB24: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8002FB28: blez        $v0, L_8002FD1C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002FB2C: addiu       $s6, $s6, -0x320C
        ctx->r22 = ADD32(ctx->r22, -0X320C);
            goto L_8002FD1C;
    }
    // 0x8002FB2C: addiu       $s6, $s6, -0x320C
    ctx->r22 = ADD32(ctx->r22, -0X320C);
    // 0x8002FB30: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8002FB34: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x8002FB38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002FB3C: lwc1        $f6, -0x299C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X299C);
    // 0x8002FB40: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8002FB44: nop

    // 0x8002FB48: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002FB4C: b           L_8002FD1C
    // 0x8002FB50: nop

        goto L_8002FD1C;
    // 0x8002FB50: nop

L_8002FB54:
    // 0x8002FB54: blez        $v1, L_8002FD1C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002FB58: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8002FD1C;
    }
    // 0x8002FB58: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002FB5C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002FB60: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8002FB64: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002FB68: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002FB6C: addiu       $s4, $s4, -0x4750
    ctx->r20 = ADD32(ctx->r20, -0X4750);
    // 0x8002FB70: addiu       $s5, $s5, -0x4960
    ctx->r21 = ADD32(ctx->r21, -0X4960);
    // 0x8002FB74: addiu       $s6, $s6, -0x320C
    ctx->r22 = ADD32(ctx->r22, -0X320C);
    // 0x8002FB78: addiu       $s3, $s3, -0x3848
    ctx->r19 = ADD32(ctx->r19, -0X3848);
L_8002FB7C:
    // 0x8002FB7C: lh          $t9, 0xA($s3)
    ctx->r25 = MEM_H(ctx->r19, 0XA);
    // 0x8002FB80: nop

    // 0x8002FB84: blez        $t9, L_8002FD0C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8002FB88: nop
    
            goto L_8002FD0C;
    }
    // 0x8002FB88: nop

    // 0x8002FB8C: lbu         $s1, 0x1($s3)
    ctx->r17 = MEM_BU(ctx->r19, 0X1);
    // 0x8002FB90: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x8002FB94: andi        $t0, $s1, 0x1
    ctx->r8 = ctx->r17 & 0X1;
    // 0x8002FB98: beq         $t0, $zero, L_8002FBC0
    if (ctx->r8 == 0) {
        // 0x8002FB9C: nop
    
            goto L_8002FBC0;
    }
    // 0x8002FB9C: nop

    // 0x8002FBA0: lbu         $t1, 0x2($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X2);
    // 0x8002FBA4: nop

    // 0x8002FBA8: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8002FBAC: addu        $v0, $s4, $t2
    ctx->r2 = ADD32(ctx->r20, ctx->r10);
    // 0x8002FBB0: lwc1        $f28, 0x0($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FBB4: lwc1        $f30, 0x8($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FBB8: b           L_8002FBE0
    // 0x8002FBBC: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
        goto L_8002FBE0;
    // 0x8002FBBC: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
L_8002FBC0:
    // 0x8002FBC0: lbu         $t3, 0x2($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X2);
    // 0x8002FBC4: nop

    // 0x8002FBC8: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8002FBCC: addu        $v0, $s5, $t4
    ctx->r2 = ADD32(ctx->r21, ctx->r12);
    // 0x8002FBD0: lwc1        $f28, 0x0($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FBD4: lwc1        $f30, 0x8($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FBD8: nop

    // 0x8002FBDC: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
L_8002FBE0:
    // 0x8002FBE0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8002FBE4: beq         $t6, $zero, L_8002FC0C
    if (ctx->r14 == 0) {
        // 0x8002FBE8: or          $s1, $t5, $zero
        ctx->r17 = ctx->r13 | 0;
            goto L_8002FC0C;
    }
    // 0x8002FBE8: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x8002FBEC: lbu         $t7, 0x3($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X3);
    // 0x8002FBF0: nop

    // 0x8002FBF4: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8002FBF8: addu        $v0, $s4, $t8
    ctx->r2 = ADD32(ctx->r20, ctx->r24);
    // 0x8002FBFC: lwc1        $f24, 0x0($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FC00: lwc1        $f26, 0x8($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FC04: b           L_8002FC2C
    // 0x8002FC08: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
        goto L_8002FC2C;
    // 0x8002FC08: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
L_8002FC0C:
    // 0x8002FC0C: lbu         $t9, 0x3($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X3);
    // 0x8002FC10: nop

    // 0x8002FC14: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8002FC18: addu        $v0, $s5, $t0
    ctx->r2 = ADD32(ctx->r21, ctx->r8);
    // 0x8002FC1C: lwc1        $f24, 0x0($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FC20: lwc1        $f26, 0x8($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FC24: nop

    // 0x8002FC28: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
L_8002FC2C:
    // 0x8002FC2C: sra         $t1, $s1, 1
    ctx->r9 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8002FC30: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8002FC34: bne         $at, $zero, L_8002FD0C
    if (ctx->r1 != 0) {
        // 0x8002FC38: or          $s1, $t1, $zero
        ctx->r17 = ctx->r9 | 0;
            goto L_8002FD0C;
    }
    // 0x8002FC38: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8002FC3C: sll         $t3, $s7, 2
    ctx->r11 = S32(ctx->r23 << 2);
    // 0x8002FC40: subu        $t3, $t3, $s7
    ctx->r11 = SUB32(ctx->r11, ctx->r23);
    // 0x8002FC44: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002FC48: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002FC4C: addiu       $t5, $t5, -0x3848
    ctx->r13 = ADD32(ctx->r13, -0X3848);
    // 0x8002FC50: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x8002FC54: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
L_8002FC58:
    // 0x8002FC58: andi        $t6, $s1, 0x1
    ctx->r14 = ctx->r17 & 0X1;
    // 0x8002FC5C: beq         $t6, $zero, L_8002FC84
    if (ctx->r14 == 0) {
        // 0x8002FC60: nop
    
            goto L_8002FC84;
    }
    // 0x8002FC60: nop

    // 0x8002FC64: lbu         $t7, 0x2($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2);
    // 0x8002FC68: nop

    // 0x8002FC6C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8002FC70: addu        $v0, $s4, $t8
    ctx->r2 = ADD32(ctx->r20, ctx->r24);
    // 0x8002FC74: lwc1        $f20, 0x0($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FC78: lwc1        $f22, 0x8($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FC7C: b           L_8002FCA4
    // 0x8002FC80: sra         $t1, $s1, 1
    ctx->r9 = S32(SIGNED(ctx->r17) >> 1);
        goto L_8002FCA4;
    // 0x8002FC80: sra         $t1, $s1, 1
    ctx->r9 = S32(SIGNED(ctx->r17) >> 1);
L_8002FC84:
    // 0x8002FC84: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    // 0x8002FC88: nop

    // 0x8002FC8C: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8002FC90: addu        $v0, $s5, $t0
    ctx->r2 = ADD32(ctx->r21, ctx->r8);
    // 0x8002FC94: lwc1        $f20, 0x0($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FC98: lwc1        $f22, 0x8($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FC9C: nop

    // 0x8002FCA0: sra         $t1, $s1, 1
    ctx->r9 = S32(SIGNED(ctx->r17) >> 1);
L_8002FCA4:
    // 0x8002FCA4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8002FCA8: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8002FCAC: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8002FCB0: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x8002FCB4: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    // 0x8002FCB8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8002FCBC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8002FCC0: jal         0x80070C6C
    // 0x8002FCC4: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    area_triangle_2d(rdram, ctx);
        goto after_0;
    // 0x8002FCC4: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8002FCC8: lh          $t2, 0xA($s3)
    ctx->r10 = MEM_H(ctx->r19, 0XA);
    // 0x8002FCCC: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    // 0x8002FCD0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8002FCD4: addu        $t4, $s6, $t3
    ctx->r12 = ADD32(ctx->r22, ctx->r11);
    // 0x8002FCD8: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8002FCDC: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8002FCE0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8002FCE4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002FCE8: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002FCEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002FCF0: mov.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    ctx->f24.fl = ctx->f20.fl;
    // 0x8002FCF4: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
    // 0x8002FCF8: bne         $at, $zero, L_8002FC58
    if (ctx->r1 != 0) {
        // 0x8002FCFC: add.s       $f2, $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
            goto L_8002FC58;
    }
    // 0x8002FCFC: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8002FD00: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002FD04: lw          $v1, -0x3850($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3850);
    // 0x8002FD08: nop

L_8002FD0C:
    // 0x8002FD0C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002FD10: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002FD14: bne         $at, $zero, L_8002FB7C
    if (ctx->r1 != 0) {
        // 0x8002FD18: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_8002FB7C;
    }
    // 0x8002FD18: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
L_8002FD1C:
    // 0x8002FD1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002FD20: lwc1        $f12, -0x299C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X299C);
    // 0x8002FD24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002FD28: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8002FD2C: nop

    // 0x8002FD30: bc1f        L_8002FD48
    if (!c1cs) {
        // 0x8002FD34: nop
    
            goto L_8002FD48;
    }
    // 0x8002FD34: nop

    // 0x8002FD38: lwc1        $f16, 0x64EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X64EC);
    // 0x8002FD3C: nop

    // 0x8002FD40: mul.s       $f2, $f12, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8002FD44: nop

L_8002FD48:
    // 0x8002FD48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002FD4C: lwc1        $f12, -0x299C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X299C);
    // 0x8002FD50: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8002FD54: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8002FD58: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002FD5C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002FD60: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002FD64: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002FD68: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002FD6C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002FD70: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002FD74: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002FD78: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002FD7C: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002FD80: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002FD84: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002FD88: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8002FD8C: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8002FD90: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x8002FD94: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x8002FD98: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x8002FD9C: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8002FDA0: lw          $s6, 0x64($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X64);
    // 0x8002FDA4: lw          $s7, 0x68($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X68);
    // 0x8002FDA8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8002FDAC: jr          $ra
    // 0x8002FDB0: div.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    return;
    // 0x8002FDB0: div.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
;}
RECOMP_FUNC void func_8002FD74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FDB4: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x8002FDB8: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x8002FDBC: swc1        $f14, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f14.u32l;
    // 0x8002FDC0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8002FDC4: blez        $a0, L_8002FFA0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8002FDC8: sw          $a3, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r7;
            goto L_8002FFA0;
    }
    // 0x8002FDC8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8002FDCC: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8002FDD0: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002FDD4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FDD8: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FDDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002FDE0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8002FDE4: bne         $at, $zero, L_8002FF50
    if (ctx->r1 != 0) {
        // 0x8002FDE8: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_8002FF50;
    }
    // 0x8002FDE8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x8002FDEC: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x8002FDF0: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x8002FDF4: beq         $t6, $zero, L_8002FE6C
    if (ctx->r14 == 0) {
        // 0x8002FDF8: sll         $t8, $a0, 4
        ctx->r24 = S32(ctx->r4 << 4);
            goto L_8002FE6C;
    }
    // 0x8002FDF8: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x8002FDFC: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x8002FE00: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002FE04: nop

    // 0x8002FE08: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8002FE0C: nop

    // 0x8002FE10: bc1f        L_8002FE20
    if (!c1cs) {
        // 0x8002FE14: nop
    
            goto L_8002FE20;
    }
    // 0x8002FE14: nop

    // 0x8002FE18: b           L_8002FE34
    // 0x8002FE1C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8002FE34;
    // 0x8002FE1C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8002FE20:
    // 0x8002FE20: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8002FE24: nop

    // 0x8002FE28: bc1f        L_8002FE34
    if (!c1cs) {
        // 0x8002FE2C: nop
    
            goto L_8002FE34;
    }
    // 0x8002FE2C: nop

    // 0x8002FE30: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8002FE34:
    // 0x8002FE34: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002FE38: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8002FE3C: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x8002FE40: nop

    // 0x8002FE44: bc1f        L_8002FE54
    if (!c1cs) {
        // 0x8002FE48: nop
    
            goto L_8002FE54;
    }
    // 0x8002FE48: nop

    // 0x8002FE4C: b           L_8002FE68
    // 0x8002FE50: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8002FE68;
    // 0x8002FE50: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8002FE54:
    // 0x8002FE54: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8002FE58: nop

    // 0x8002FE5C: bc1f        L_8002FE68
    if (!c1cs) {
        // 0x8002FE60: nop
    
            goto L_8002FE68;
    }
    // 0x8002FE60: nop

    // 0x8002FE64: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_8002FE68:
    // 0x8002FE68: beq         $v1, $a0, L_8002FF50
    if (ctx->r3 == ctx->r4) {
        // 0x8002FE6C: sll         $t7, $v1, 4
        ctx->r15 = S32(ctx->r3 << 4);
            goto L_8002FF50;
    }
L_8002FE6C:
    // 0x8002FE6C: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8002FE70: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8002FE74: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
L_8002FE78:
    // 0x8002FE78: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002FE7C: nop

    // 0x8002FE80: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8002FE84: nop

    // 0x8002FE88: bc1f        L_8002FE98
    if (!c1cs) {
        // 0x8002FE8C: nop
    
            goto L_8002FE98;
    }
    // 0x8002FE8C: nop

    // 0x8002FE90: b           L_8002FEAC
    // 0x8002FE94: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8002FEAC;
    // 0x8002FE94: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8002FE98:
    // 0x8002FE98: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8002FE9C: nop

    // 0x8002FEA0: bc1f        L_8002FEAC
    if (!c1cs) {
        // 0x8002FEA4: nop
    
            goto L_8002FEAC;
    }
    // 0x8002FEA4: nop

    // 0x8002FEA8: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8002FEAC:
    // 0x8002FEAC: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8002FEB0: nop

    // 0x8002FEB4: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x8002FEB8: nop

    // 0x8002FEBC: bc1f        L_8002FECC
    if (!c1cs) {
        // 0x8002FEC0: nop
    
            goto L_8002FECC;
    }
    // 0x8002FEC0: nop

    // 0x8002FEC4: b           L_8002FEE0
    // 0x8002FEC8: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8002FEE0;
    // 0x8002FEC8: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8002FECC:
    // 0x8002FECC: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8002FED0: nop

    // 0x8002FED4: bc1f        L_8002FEE0
    if (!c1cs) {
        // 0x8002FED8: nop
    
            goto L_8002FEE0;
    }
    // 0x8002FED8: nop

    // 0x8002FEDC: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_8002FEE0:
    // 0x8002FEE0: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8002FEE4: nop

    // 0x8002FEE8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8002FEEC: nop

    // 0x8002FEF0: bc1f        L_8002FF00
    if (!c1cs) {
        // 0x8002FEF4: nop
    
            goto L_8002FF00;
    }
    // 0x8002FEF4: nop

    // 0x8002FEF8: b           L_8002FF14
    // 0x8002FEFC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8002FF14;
    // 0x8002FEFC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8002FF00:
    // 0x8002FF00: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8002FF04: nop

    // 0x8002FF08: bc1f        L_8002FF14
    if (!c1cs) {
        // 0x8002FF0C: nop
    
            goto L_8002FF14;
    }
    // 0x8002FF0C: nop

    // 0x8002FF10: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8002FF14:
    // 0x8002FF14: lwc1        $f16, 0x18($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8002FF18: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8002FF1C: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x8002FF20: nop

    // 0x8002FF24: bc1f        L_8002FF34
    if (!c1cs) {
        // 0x8002FF28: nop
    
            goto L_8002FF34;
    }
    // 0x8002FF28: nop

    // 0x8002FF2C: b           L_8002FF48
    // 0x8002FF30: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8002FF48;
    // 0x8002FF30: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8002FF34:
    // 0x8002FF34: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8002FF38: nop

    // 0x8002FF3C: bc1f        L_8002FF48
    if (!c1cs) {
        // 0x8002FF40: nop
    
            goto L_8002FF48;
    }
    // 0x8002FF40: nop

    // 0x8002FF44: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_8002FF48:
    // 0x8002FF48: bne         $a1, $a2, L_8002FE78
    if (ctx->r5 != ctx->r6) {
        // 0x8002FF4C: nop
    
            goto L_8002FE78;
    }
    // 0x8002FF4C: nop

L_8002FF50:
    // 0x8002FF50: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002FF54: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8002FF58: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8002FF5C: nop

    // 0x8002FF60: bc1f        L_8002FFA4
    if (!c1cs) {
        // 0x8002FF64: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002FFA4;
    }
    // 0x8002FF64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002FF68: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8002FF6C: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8002FF70: bc1f        L_8002FFA4
    if (!c1cs) {
        // 0x8002FF74: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002FFA4;
    }
    // 0x8002FF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002FF78: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8002FF7C: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8002FF80: bc1f        L_8002FFA4
    if (!c1cs) {
        // 0x8002FF84: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002FFA4;
    }
    // 0x8002FF84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002FF88: c.le.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl <= ctx->f10.fl;
    // 0x8002FF8C: nop

    // 0x8002FF90: bc1f        L_8002FFA4
    if (!c1cs) {
        // 0x8002FF94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002FFA4;
    }
    // 0x8002FF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002FF98: jr          $ra
    // 0x8002FF9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8002FF9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8002FFA0:
    // 0x8002FFA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002FFA4:
    // 0x8002FFA4: jr          $ra
    // 0x8002FFA8: nop

    return;
    // 0x8002FFA8: nop

;}
RECOMP_FUNC void func_8002FF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FFAC: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x8002FFB0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002FFB4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002FFB8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002FFBC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002FFC0: or          $ra, $a2, $zero
    ctx->r31 = ctx->r6 | 0;
    // 0x8002FFC4: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002FFC8: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002FFCC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002FFD0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002FFD4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002FFD8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002FFDC: swc1        $f29, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002FFE0: swc1        $f28, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f28.u32l;
    // 0x8002FFE4: swc1        $f27, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002FFE8: swc1        $f26, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f26.u32l;
    // 0x8002FFEC: swc1        $f25, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002FFF0: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x8002FFF4: swc1        $f23, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002FFF8: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8002FFFC: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80030000: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x80030004: sw          $a3, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r7;
    // 0x80030008: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8003000C: addiu       $s0, $sp, 0xE0
    ctx->r16 = ADD32(ctx->r29, 0XE0);
    // 0x80030010: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80030014: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80030018: blez        $a2, L_80030398
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8003001C: sw          $a1, 0x164($sp)
        MEM_W(0X164, ctx->r29) = ctx->r5;
            goto L_80030398;
    }
    // 0x8003001C: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x80030020: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80030024: bne         $at, $zero, L_80030398
    if (ctx->r1 != 0) {
        // 0x80030028: sw          $a1, 0x164($sp)
        MEM_W(0X164, ctx->r29) = ctx->r5;
            goto L_80030398;
    }
    // 0x80030028: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x8003002C: sll         $t7, $zero, 3
    ctx->r15 = S32(0 << 3);
    // 0x80030030: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80030034: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80030038: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8003003C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80030040: addiu       $s1, $s1, -0x4750
    ctx->r17 = ADD32(ctx->r17, -0X4750);
    // 0x80030044: addiu       $s4, $s4, -0x4760
    ctx->r20 = ADD32(ctx->r20, -0X4760);
    // 0x80030048: addiu       $s6, $s6, -0x29C4
    ctx->r22 = ADD32(ctx->r22, -0X29C4);
    // 0x8003004C: addu        $s7, $a3, $t7
    ctx->r23 = ADD32(ctx->r7, ctx->r15);
    // 0x80030050: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x80030054: addiu       $s5, $zero, 0x1F
    ctx->r21 = ADD32(0, 0X1F);
    // 0x80030058: addiu       $fp, $t5, 0x1
    ctx->r30 = ADD32(ctx->r13, 0X1);
L_8003005C:
    // 0x8003005C: slt         $at, $fp, $ra
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x80030060: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x80030064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030068: bne         $at, $zero, L_80030074
    if (ctx->r1 != 0) {
        // 0x8003006C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80030074;
    }
    // 0x8003006C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80030070: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80030074:
    // 0x80030074: lw          $t8, 0x16C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X16C);
    // 0x80030078: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8003007C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80030080: lwc1        $f20, 0x0($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80030084: lwc1        $f22, 0x0($s7)
    ctx->f22.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80030088: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8003008C: lwc1        $f18, 0x4($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X4);
    // 0x80030090: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x80030094: sub.s       $f14, $f20, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80030098: or          $t1, $s3, $zero
    ctx->r9 = ctx->r19 | 0;
    // 0x8003009C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x800300A0: bc1f        L_800300C0
    if (!c1cs) {
        // 0x800300A4: sub.s       $f12, $f16, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
            goto L_800300C0;
    }
    // 0x800300A4: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800300A8: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800300AC: nop

    // 0x800300B0: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x800300B4: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800300B8: b           L_800300D4
    // 0x800300BC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_800300D4;
    // 0x800300BC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_800300C0:
    // 0x800300C0: mul.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800300C4: nop

    // 0x800300C8: mul.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800300CC: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800300D0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_800300D4:
    // 0x800300D4: blez        $s2, L_8003036C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800300D8: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_8003036C;
    }
L_800300D8:
    // 0x800300D8: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x800300DC: slt         $at, $t4, $s2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800300E0: bne         $at, $zero, L_800300EC
    if (ctx->r1 != 0) {
        // 0x800300E4: or          $v1, $t4, $zero
        ctx->r3 = ctx->r12 | 0;
            goto L_800300EC;
    }
    // 0x800300E4: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x800300E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800300EC:
    // 0x800300EC: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800300F0: lwc1        $f20, 0x0($t1)
    ctx->f20.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800300F4: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800300F8: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x800300FC: addu        $a3, $s3, $t6
    ctx->r7 = ADD32(ctx->r19, ctx->r14);
    // 0x80030100: lwc1        $f24, 0x8($a3)
    ctx->f24.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80030104: mul.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80030108: lwc1        $f26, 0x0($a3)
    ctx->f26.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8003010C: mul.s       $f10, $f24, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f14.fl);
    // 0x80030110: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80030114: mul.s       $f4, $f12, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f26.fl);
    // 0x80030118: add.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8003011C: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x80030120: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80030124: bc1f        L_8003013C
    if (!c1cs) {
        // 0x80030128: add.s       $f22, $f6, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f2.fl;
            goto L_8003013C;
    }
    // 0x80030128: add.s       $f22, $f6, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8003012C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80030130: nop

    // 0x80030134: bc1t        L_8003015C
    if (c1cs) {
        // 0x80030138: sll         $t7, $t5, 2
        ctx->r15 = S32(ctx->r13 << 2);
            goto L_8003015C;
    }
    // 0x80030138: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
L_8003013C:
    // 0x8003013C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80030140: nop

    // 0x80030144: bc1f        L_80030330
    if (!c1cs) {
        // 0x80030148: nop
    
            goto L_80030330;
    }
    // 0x80030148: nop

    // 0x8003014C: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x80030150: nop

    // 0x80030154: bc1f        L_80030330
    if (!c1cs) {
        // 0x80030158: sll         $t7, $t5, 2
        ctx->r15 = S32(ctx->r13 << 2);
            goto L_80030330;
    }
    // 0x80030158: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
L_8003015C:
    // 0x8003015C: addu        $t0, $s4, $t7
    ctx->r8 = ADD32(ctx->r20, ctx->r15);
    // 0x80030160: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80030164: sll         $t3, $t5, 5
    ctx->r11 = S32(ctx->r13 << 5);
    // 0x80030168: sll         $t8, $t2, 4
    ctx->r24 = S32(ctx->r10 << 4);
    // 0x8003016C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80030170: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80030174: blez        $a0, L_8003025C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80030178: addu        $a2, $s0, $t8
        ctx->r6 = ADD32(ctx->r16, ctx->r24);
            goto L_8003025C;
    }
    // 0x80030178: addu        $a2, $s0, $t8
    ctx->r6 = ADD32(ctx->r16, ctx->r24);
    // 0x8003017C: sll         $t9, $v1, 5
    ctx->r25 = S32(ctx->r3 << 5);
    // 0x80030180: addu        $v0, $s1, $t9
    ctx->r2 = ADD32(ctx->r17, ctx->r25);
L_80030184:
    // 0x80030184: lwc1        $f28, 0x10($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80030188: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8003018C: c.eq.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl == ctx->f20.fl;
    // 0x80030190: nop

    // 0x80030194: bc1f        L_800301EC
    if (!c1cs) {
        // 0x80030198: nop
    
            goto L_800301EC;
    }
    // 0x80030198: nop

    // 0x8003019C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800301A0: nop

    // 0x800301A4: c.eq.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl == ctx->f18.fl;
    // 0x800301A8: nop

    // 0x800301AC: bc1f        L_800301EC
    if (!c1cs) {
        // 0x800301B0: nop
    
            goto L_800301EC;
    }
    // 0x800301B0: nop

    // 0x800301B4: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800301B8: nop

    // 0x800301BC: c.eq.s      $f10, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f10.fl == ctx->f26.fl;
    // 0x800301C0: nop

    // 0x800301C4: bc1f        L_800301EC
    if (!c1cs) {
        // 0x800301C8: nop
    
            goto L_800301EC;
    }
    // 0x800301C8: nop

    // 0x800301CC: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800301D0: nop

    // 0x800301D4: c.eq.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl == ctx->f24.fl;
    // 0x800301D8: nop

    // 0x800301DC: bc1f        L_800301EC
    if (!c1cs) {
        // 0x800301E0: nop
    
            goto L_800301EC;
    }
    // 0x800301E0: nop

    // 0x800301E4: b           L_80030248
    // 0x800301E8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_80030248;
    // 0x800301E8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_800301EC:
    // 0x800301EC: c.eq.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl == ctx->f26.fl;
    // 0x800301F0: nop

    // 0x800301F4: bc1f        L_80030248
    if (!c1cs) {
        // 0x800301F8: nop
    
            goto L_80030248;
    }
    // 0x800301F8: nop

    // 0x800301FC: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80030200: nop

    // 0x80030204: c.eq.s      $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f6.fl == ctx->f24.fl;
    // 0x80030208: nop

    // 0x8003020C: bc1f        L_80030248
    if (!c1cs) {
        // 0x80030210: nop
    
            goto L_80030248;
    }
    // 0x80030210: nop

    // 0x80030214: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80030218: nop

    // 0x8003021C: c.eq.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl == ctx->f20.fl;
    // 0x80030220: nop

    // 0x80030224: bc1f        L_80030248
    if (!c1cs) {
        // 0x80030228: nop
    
            goto L_80030248;
    }
    // 0x80030228: nop

    // 0x8003022C: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80030230: nop

    // 0x80030234: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x80030238: nop

    // 0x8003023C: bc1f        L_80030248
    if (!c1cs) {
        // 0x80030240: nop
    
            goto L_80030248;
    }
    // 0x80030240: nop

    // 0x80030244: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_80030248:
    // 0x80030248: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003024C: blez        $a0, L_8003025C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80030250: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_8003025C;
    }
    // 0x80030250: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80030254: bltz        $a1, L_80030184
    if (SIGNED(ctx->r5) < 0) {
        // 0x80030258: nop
    
            goto L_80030184;
    }
    // 0x80030258: nop

L_8003025C:
    // 0x8003025C: bltz        $a1, L_80030284
    if (SIGNED(ctx->r5) < 0) {
        // 0x80030260: sll         $t6, $a1, 5
        ctx->r14 = S32(ctx->r5 << 5);
            goto L_80030284;
    }
    // 0x80030260: sll         $t6, $a1, 5
    ctx->r14 = S32(ctx->r5 << 5);
    // 0x80030264: sh          $a1, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r5;
    // 0x80030268: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x8003026C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80030270: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80030274: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x80030278: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003027C: b           L_80030330
    // 0x80030280: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
        goto L_80030330;
    // 0x80030280: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
L_80030284:
    // 0x80030284: sub.s       $f8, $f16, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x80030288: nop

    // 0x8003028C: div.s       $f24, $f16, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80030290: sub.s       $f10, $f26, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f20.fl;
    // 0x80030294: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80030298: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8003029C: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800302A0: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800302A4: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800302A8: nop

    // 0x800302AC: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800302B0: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800302B4: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800302B8: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x800302BC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800302C0: nop

    // 0x800302C4: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x800302C8: bne         $at, $zero, L_800302DC
    if (ctx->r1 != 0) {
        // 0x800302CC: addu        $v1, $a0, $t3
        ctx->r3 = ADD32(ctx->r4, ctx->r11);
            goto L_800302DC;
    }
    // 0x800302CC: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
    // 0x800302D0: sw          $s5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r21;
    // 0x800302D4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800302D8: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
L_800302DC:
    // 0x800302DC: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800302E0: sll         $t7, $v1, 5
    ctx->r15 = S32(ctx->r3 << 5);
    // 0x800302E4: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x800302E8: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x800302EC: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800302F0: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800302F4: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x800302F8: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800302FC: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x80030300: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80030304: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80030308: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8003030C: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x80030310: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80030314: nop

    // 0x80030318: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8003031C: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80030320: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80030324: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x80030328: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x8003032C: sh          $v1, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r3;
L_80030330:
    // 0x80030330: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x80030334: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80030338: bc1f        L_80030364
    if (!c1cs) {
        // 0x8003033C: sll         $t6, $t2, 4
        ctx->r14 = S32(ctx->r10 << 4);
            goto L_80030364;
    }
    // 0x8003033C: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x80030340: lh          $t7, 0xE($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XE);
    // 0x80030344: addu        $a2, $s0, $t6
    ctx->r6 = ADD32(ctx->r16, ctx->r14);
    // 0x80030348: sh          $t7, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r15;
    // 0x8003034C: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80030350: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80030354: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x80030358: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8003035C: nop

    // 0x80030360: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
L_80030364:
    // 0x80030364: bne         $t4, $s2, L_800300D8
    if (ctx->r12 != ctx->r18) {
        // 0x80030368: addiu       $t1, $t1, 0x10
        ctx->r9 = ADD32(ctx->r9, 0X10);
            goto L_800300D8;
    }
    // 0x80030368: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
L_8003036C:
    // 0x8003036C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80030370: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x80030374: slt         $at, $fp, $ra
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x80030378: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x8003037C: or          $t5, $fp, $zero
    ctx->r13 = ctx->r30 | 0;
    // 0x80030380: addiu       $s7, $s7, 0x8
    ctx->r23 = ADD32(ctx->r23, 0X8);
    // 0x80030384: beq         $at, $zero, L_80030398
    if (ctx->r1 == 0) {
        // 0x80030388: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80030398;
    }
    // 0x80030388: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003038C: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x80030390: beq         $at, $zero, L_8003005C
    if (ctx->r1 == 0) {
        // 0x80030394: addiu       $fp, $t5, 0x1
        ctx->r30 = ADD32(ctx->r13, 0X1);
            goto L_8003005C;
    }
    // 0x80030394: addiu       $fp, $t5, 0x1
    ctx->r30 = ADD32(ctx->r13, 0X1);
L_80030398:
    // 0x80030398: lw          $a1, 0x164($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X164);
    // 0x8003039C: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x800303A0: bne         $at, $zero, L_800304A8
    if (ctx->r1 != 0) {
        // 0x800303A4: nop
    
            goto L_800304A8;
    }
    // 0x800303A4: nop

    // 0x800303A8: beq         $s3, $a1, L_800304B0
    if (ctx->r19 == ctx->r5) {
        // 0x800303AC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_800304B0;
    }
    // 0x800303AC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800303B0: blez        $s2, L_800304AC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800303B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800304AC;
    }
    // 0x800303B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800303B8: andi        $a3, $s2, 0x3
    ctx->r7 = ctx->r18 & 0X3;
    // 0x800303BC: beq         $a3, $zero, L_800303FC
    if (ctx->r7 == 0) {
        // 0x800303C0: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_800303FC;
    }
    // 0x800303C0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800303C4: sll         $v1, $zero, 4
    ctx->r3 = S32(0 << 4);
    // 0x800303C8: addu        $t1, $s3, $v1
    ctx->r9 = ADD32(ctx->r19, ctx->r3);
    // 0x800303CC: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_800303D0:
    // 0x800303D0: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800303D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800303D8: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800303DC: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800303E0: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x800303E4: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800303E8: lh          $t8, -0x2($t1)
    ctx->r24 = MEM_H(ctx->r9, -0X2);
    // 0x800303EC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800303F0: bne         $a2, $v0, L_800303D0
    if (ctx->r6 != ctx->r2) {
        // 0x800303F4: sh          $t8, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r24;
            goto L_800303D0;
    }
    // 0x800303F4: sh          $t8, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r24;
    // 0x800303F8: beq         $v0, $s2, L_800304AC
    if (ctx->r2 == ctx->r18) {
        // 0x800303FC: sll         $v1, $v0, 4
        ctx->r3 = S32(ctx->r2 << 4);
            goto L_800304AC;
    }
L_800303FC:
    // 0x800303FC: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80030400: sll         $t9, $s2, 4
    ctx->r25 = S32(ctx->r18 << 4);
    // 0x80030404: addu        $a2, $t9, $a1
    ctx->r6 = ADD32(ctx->r25, ctx->r5);
    // 0x80030408: addu        $t1, $s3, $v1
    ctx->r9 = ADD32(ctx->r19, ctx->r3);
    // 0x8003040C: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_80030410:
    // 0x80030410: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80030414: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x80030418: swc1        $f4, -0x40($a0)
    MEM_W(-0X40, ctx->r4) = ctx->f4.u32l;
    // 0x8003041C: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80030420: addiu       $t1, $t1, 0x40
    ctx->r9 = ADD32(ctx->r9, 0X40);
    // 0x80030424: swc1        $f6, -0x38($a0)
    MEM_W(-0X38, ctx->r4) = ctx->f6.u32l;
    // 0x80030428: lh          $t6, -0x32($t1)
    ctx->r14 = MEM_H(ctx->r9, -0X32);
    // 0x8003042C: nop

    // 0x80030430: sh          $t6, -0x32($a0)
    MEM_H(-0X32, ctx->r4) = ctx->r14;
    // 0x80030434: lwc1        $f8, -0x30($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, -0X30);
    // 0x80030438: nop

    // 0x8003043C: swc1        $f8, -0x30($a0)
    MEM_W(-0X30, ctx->r4) = ctx->f8.u32l;
    // 0x80030440: lwc1        $f10, -0x28($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, -0X28);
    // 0x80030444: nop

    // 0x80030448: swc1        $f10, -0x28($a0)
    MEM_W(-0X28, ctx->r4) = ctx->f10.u32l;
    // 0x8003044C: lh          $t7, -0x22($t1)
    ctx->r15 = MEM_H(ctx->r9, -0X22);
    // 0x80030450: nop

    // 0x80030454: sh          $t7, -0x22($a0)
    MEM_H(-0X22, ctx->r4) = ctx->r15;
    // 0x80030458: lwc1        $f4, -0x20($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, -0X20);
    // 0x8003045C: nop

    // 0x80030460: swc1        $f4, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = ctx->f4.u32l;
    // 0x80030464: lwc1        $f6, -0x18($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, -0X18);
    // 0x80030468: nop

    // 0x8003046C: swc1        $f6, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = ctx->f6.u32l;
    // 0x80030470: lh          $t8, -0x12($t1)
    ctx->r24 = MEM_H(ctx->r9, -0X12);
    // 0x80030474: nop

    // 0x80030478: sh          $t8, -0x12($a0)
    MEM_H(-0X12, ctx->r4) = ctx->r24;
    // 0x8003047C: lwc1        $f8, -0x10($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, -0X10);
    // 0x80030480: nop

    // 0x80030484: swc1        $f8, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f8.u32l;
    // 0x80030488: lwc1        $f10, -0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, -0X8);
    // 0x8003048C: nop

    // 0x80030490: swc1        $f10, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80030494: lh          $t9, -0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, -0X2);
    // 0x80030498: bne         $a0, $a2, L_80030410
    if (ctx->r4 != ctx->r6) {
        // 0x8003049C: sh          $t9, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r25;
            goto L_80030410;
    }
    // 0x8003049C: sh          $t9, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r25;
    // 0x800304A0: b           L_800304B0
    // 0x800304A4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_800304B0;
    // 0x800304A4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800304A8:
    // 0x800304A8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800304AC:
    // 0x800304AC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800304B0:
    // 0x800304B0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800304B4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800304B8: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800304BC: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800304C0: lwc1        $f23, 0x10($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800304C4: lwc1        $f22, 0x14($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800304C8: lwc1        $f25, 0x18($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800304CC: lwc1        $f24, 0x1C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800304D0: lwc1        $f27, 0x20($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800304D4: lwc1        $f26, 0x24($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800304D8: lwc1        $f29, 0x28($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800304DC: lwc1        $f28, 0x2C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800304E0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800304E4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800304E8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800304EC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800304F0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800304F4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800304F8: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800304FC: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80030500: jr          $ra
    // 0x80030504: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x80030504: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
;}
RECOMP_FUNC void func_800304C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030508: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8003050C: lw          $a2, -0x29BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X29BC);
    // 0x80030510: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80030514: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80030518: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003051C: lwc1        $f0, 0xC($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80030520: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80030524: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80030528: lwc1        $f2, 0x14($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003052C: sub.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80030530: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80030534: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80030538: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x8003053C: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80030540: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030544: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80030548: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003054C: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x80030550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80030554: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80030558: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003055C: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80030560: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80030564: nop

    // 0x80030568: bc1f        L_80030574
    if (!c1cs) {
        // 0x8003056C: nop
    
            goto L_80030574;
    }
    // 0x8003056C: nop

    // 0x80030570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80030574:
    // 0x80030574: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80030578: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8003057C: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x80030580: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80030584: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80030588: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x8003058C: sub.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80030590: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80030594: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80030598: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8003059C: nop

    // 0x800305A0: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800305A4: sub.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x800305A8: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800305AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800305B0: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800305B4: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800305B8: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800305BC: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x800305C0: nop

    // 0x800305C4: bc1f        L_800305D0
    if (!c1cs) {
        // 0x800305C8: nop
    
            goto L_800305D0;
    }
    // 0x800305C8: nop

    // 0x800305CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800305D0:
    // 0x800305D0: bne         $v0, $v1, L_8003069C
    if (ctx->r2 != ctx->r3) {
        // 0x800305D4: nop
    
            goto L_8003069C;
    }
    // 0x800305D4: nop

    // 0x800305D8: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800305DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800305E0: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800305E4: mul.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800305E8: sub.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800305EC: sub.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x800305F0: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800305F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800305F8: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800305FC: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80030600: nop

    // 0x80030604: bc1f        L_80030610
    if (!c1cs) {
        // 0x80030608: nop
    
            goto L_80030610;
    }
    // 0x80030608: nop

    // 0x8003060C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80030610:
    // 0x80030610: bne         $v1, $a1, L_8003069C
    if (ctx->r3 != ctx->r5) {
        // 0x80030614: nop
    
            goto L_8003069C;
    }
    // 0x80030614: nop

    // 0x80030618: lw          $v0, -0x29C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X29C4);
    // 0x8003061C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80030620: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80030624: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80030628: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003062C: addiu       $v1, $v1, -0x29B0
    ctx->r3 = ADD32(ctx->r3, -0X29B0);
    // 0x80030630: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80030634: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80030638: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003063C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80030640: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80030644: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80030648: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x8003064C: nop

    // 0x80030650: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80030654: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80030658: nop

    // 0x8003065C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80030660: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80030664: nop

    // 0x80030668: bc1f        L_8003069C
    if (!c1cs) {
        // 0x8003066C: nop
    
            goto L_8003069C;
    }
    // 0x8003066C: nop

    // 0x80030670: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80030674: nop

    // 0x80030678: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8003067C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80030680: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80030684: nop

    // 0x80030688: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x8003068C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80030690: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80030694: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80030698: nop

L_8003069C:
    // 0x8003069C: jr          $ra
    // 0x800306A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800306A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void set_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800306A4: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800306A8: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800306AC: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800306B0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800306B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800306B8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800306BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800306C0: andi        $t1, $a3, 0xFF
    ctx->r9 = ctx->r7 & 0XFF;
    // 0x800306C4: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800306C8: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800306CC: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800306D0: beq         $at, $zero, L_800306F0
    if (ctx->r1 == 0) {
        // 0x800306D4: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_800306F0;
    }
    // 0x800306D4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800306D8: sll         $a1, $t9, 16
    ctx->r5 = S32(ctx->r25 << 16);
    // 0x800306DC: sll         $a2, $t7, 16
    ctx->r6 = S32(ctx->r15 << 16);
    // 0x800306E0: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800306E4: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800306E8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800306EC: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
L_800306F0:
    // 0x800306F0: slti        $at, $a2, 0x400
    ctx->r1 = SIGNED(ctx->r6) < 0X400 ? 1 : 0;
    // 0x800306F4: bne         $at, $zero, L_80030700
    if (ctx->r1 != 0) {
        // 0x800306F8: sll         $t5, $a0, 3
        ctx->r13 = S32(ctx->r4 << 3);
            goto L_80030700;
    }
    // 0x800306F8: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x800306FC: addiu       $a2, $zero, 0x3FF
    ctx->r6 = ADD32(0, 0X3FF);
L_80030700:
    // 0x80030700: addiu       $v0, $a2, -0x5
    ctx->r2 = ADD32(ctx->r6, -0X5);
    // 0x80030704: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030708: bne         $at, $zero, L_8003071C
    if (ctx->r1 != 0) {
        // 0x8003070C: subu        $t5, $t5, $a0
        ctx->r13 = SUB32(ctx->r13, ctx->r4);
            goto L_8003071C;
    }
    // 0x8003070C: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x80030710: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80030714: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80030718: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_8003071C:
    // 0x8003071C: lbu         $v1, 0x13($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X13);
    // 0x80030720: lbu         $t0, 0x17($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X17);
    // 0x80030724: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80030728: addiu       $t6, $t6, -0x26F8
    ctx->r14 = ADD32(ctx->r14, -0X26F8);
    // 0x8003072C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80030730: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x80030734: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80030738: sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5 << 16);
    // 0x8003073C: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x80030740: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x80030744: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x80030748: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x8003074C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80030750: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80030754: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80030758: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8003075C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80030760: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80030764: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x80030768: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8003076C: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x80030770: sb          $a3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r7;
    // 0x80030774: sh          $a1, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r5;
    // 0x80030778: sh          $a2, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r6;
    // 0x8003077C: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80030780: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x80030784: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80030788: jr          $ra
    // 0x8003078C: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
    return;
    // 0x8003078C: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void get_fog_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030790: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80030794: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80030798: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8003079C: addiu       $t7, $t7, -0x26F8
    ctx->r15 = ADD32(ctx->r15, -0X26F8);
    // 0x800307A0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800307A4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800307A8: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800307AC: nop

    // 0x800307B0: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800307B4: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x800307B8: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x800307BC: nop

    // 0x800307C0: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800307C4: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
    // 0x800307C8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800307CC: nop

    // 0x800307D0: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800307D4: sb          $t3, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r11;
    // 0x800307D8: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x800307DC: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800307E0: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800307E4: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x800307E8: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x800307EC: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800307F0: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800307F4: jr          $ra
    // 0x800307F8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    return;
    // 0x800307F8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
;}
RECOMP_FUNC void reset_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800307FC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80030800: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80030804: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80030808: addiu       $t7, $t7, -0x26F8
    ctx->r15 = ADD32(ctx->r15, -0X26F8);
    // 0x8003080C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80030810: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80030814: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80030818: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8003081C: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x80030820: lui         $t8, 0x3FA
    ctx->r24 = S32(0X3FA << 16);
    // 0x80030824: lui         $t9, 0x3FF
    ctx->r25 = S32(0X3FF << 16);
    // 0x80030828: addiu       $t6, $zero, 0x3FA
    ctx->r14 = ADD32(0, 0X3FA);
    // 0x8003082C: addiu       $t7, $zero, 0x3FF
    ctx->r15 = ADD32(0, 0X3FF);
    // 0x80030830: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80030834: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80030838: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8003083C: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80030840: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80030844: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80030848: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x8003084C: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80030850: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x80030854: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    // 0x80030858: sb          $t1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r9;
    // 0x8003085C: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80030860: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80030864: sh          $t6, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r14;
    // 0x80030868: sh          $t7, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r15;
    // 0x8003086C: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80030870: jr          $ra
    // 0x80030874: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    return;
    // 0x80030874: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
;}
RECOMP_FUNC void update_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030878: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003087C: blez        $a0, L_80030974
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80030880: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80030974;
    }
    // 0x80030880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030884: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80030888: addiu       $v1, $v1, -0x26F8
    ctx->r3 = ADD32(ctx->r3, -0X26F8);
L_8003088C:
    // 0x8003088C: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    // 0x80030890: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80030894: blez        $a1, L_8003096C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80030898: slt         $at, $a2, $a1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8003096C;
    }
    // 0x80030898: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003089C: beq         $at, $zero, L_8003092C
    if (ctx->r1 == 0) {
        // 0x800308A0: nop
    
            goto L_8003092C;
    }
    // 0x800308A0: nop

    // 0x800308A4: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x800308A8: lw          $t1, 0x18($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X18);
    // 0x800308AC: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800308B0: lw          $t5, 0x1C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X1C);
    // 0x800308B4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800308B8: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x800308BC: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800308C0: mflo        $t8
    ctx->r24 = lo;
    // 0x800308C4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800308C8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800308CC: multu       $t1, $a2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800308D0: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x800308D4: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x800308D8: mflo        $t2
    ctx->r10 = lo;
    // 0x800308DC: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800308E0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800308E4: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800308E8: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x800308EC: lw          $t2, 0x10($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X10);
    // 0x800308F0: mflo        $t7
    ctx->r15 = lo;
    // 0x800308F4: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x800308F8: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x800308FC: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030900: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x80030904: subu        $t6, $t7, $a2
    ctx->r14 = SUB32(ctx->r15, ctx->r6);
    // 0x80030908: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x8003090C: mflo        $t1
    ctx->r9 = lo;
    // 0x80030910: addu        $t0, $t8, $t1
    ctx->r8 = ADD32(ctx->r24, ctx->r9);
    // 0x80030914: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x80030918: multu       $t3, $a2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003091C: mflo        $t5
    ctx->r13 = lo;
    // 0x80030920: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x80030924: b           L_8003096C
    // 0x80030928: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
        goto L_8003096C;
    // 0x80030928: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
L_8003092C:
    // 0x8003092C: lbu         $t9, 0x28($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X28);
    // 0x80030930: lbu         $t1, 0x29($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X29);
    // 0x80030934: lbu         $t3, 0x2A($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2A);
    // 0x80030938: lh          $t5, 0x2C($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2C);
    // 0x8003093C: lh          $t7, 0x2E($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2E);
    // 0x80030940: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80030944: sll         $t0, $t1, 16
    ctx->r8 = S32(ctx->r9 << 16);
    // 0x80030948: sll         $t2, $t3, 16
    ctx->r10 = S32(ctx->r11 << 16);
    // 0x8003094C: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x80030950: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80030954: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80030958: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8003095C: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80030960: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x80030964: sw          $t6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r14;
    // 0x80030968: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
L_8003096C:
    // 0x8003096C: bne         $v0, $a0, L_8003088C
    if (ctx->r2 != ctx->r4) {
        // 0x80030970: addiu       $v1, $v1, 0x38
        ctx->r3 = ADD32(ctx->r3, 0X38);
            goto L_8003088C;
    }
    // 0x80030970: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
L_80030974:
    // 0x80030974: jr          $ra
    // 0x80030978: nop

    return;
    // 0x80030978: nop

;}
RECOMP_FUNC void apply_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003097C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80030980: addiu       $t1, $t1, -0x49E0
    ctx->r9 = ADD32(ctx->r9, -0X49E0);
    // 0x80030984: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80030988: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8003098C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80030990: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80030994: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80030998: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8003099C: addiu       $t9, $t9, -0x26F8
    ctx->r25 = ADD32(ctx->r25, -0X26F8);
    // 0x800309A0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800309A4: lui         $t7, 0xF800
    ctx->r15 = S32(0XF800 << 16);
    // 0x800309A8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x800309AC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800309B0: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x800309B4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800309B8: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800309BC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800309C0: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x800309C4: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800309C8: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800309CC: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800309D0: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x800309D4: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800309D8: or          $t2, $t5, $t9
    ctx->r10 = ctx->r13 | ctx->r25;
    // 0x800309DC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800309E0: or          $t8, $t2, $t7
    ctx->r24 = ctx->r10 | ctx->r15;
    // 0x800309E4: ori         $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 | 0XFF;
    // 0x800309E8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800309EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800309F0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800309F4: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x800309F8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800309FC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80030A00: ori         $t3, $t3, 0x8
    ctx->r11 = ctx->r11 | 0X8;
    // 0x80030A04: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80030A08: lw          $a3, 0xC($a1)
    ctx->r7 = MEM_W(ctx->r5, 0XC);
    // 0x80030A0C: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80030A10: sra         $t4, $a3, 16
    ctx->r12 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80030A14: negu        $t7, $t4
    ctx->r15 = SUB32(0, ctx->r12);
    // 0x80030A18: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80030A1C: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x80030A20: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80030A24: sra         $t2, $t6, 16
    ctx->r10 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80030A28: subu        $t0, $t2, $t4
    ctx->r8 = SUB32(ctx->r10, ctx->r12);
    // 0x80030A2C: addu        $t5, $t8, $at
    ctx->r13 = ADD32(ctx->r24, ctx->r1);
    // 0x80030A30: div         $zero, $t5, $t0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r8)));
    // 0x80030A34: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x80030A38: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x80030A3C: ori         $t4, $t4, 0xF400
    ctx->r12 = ctx->r12 | 0XF400;
    // 0x80030A40: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80030A44: bne         $t0, $zero, L_80030A50
    if (ctx->r8 != 0) {
        // 0x80030A48: nop
    
            goto L_80030A50;
    }
    // 0x80030A48: nop

    // 0x80030A4C: break       7
    do_break(2147682892);
L_80030A50:
    // 0x80030A50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030A54: bne         $t0, $at, L_80030A68
    if (ctx->r8 != ctx->r1) {
        // 0x80030A58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030A68;
    }
    // 0x80030A58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030A5C: bne         $t5, $at, L_80030A68
    if (ctx->r13 != ctx->r1) {
        // 0x80030A60: nop
    
            goto L_80030A68;
    }
    // 0x80030A60: nop

    // 0x80030A64: break       6
    do_break(2147682916);
L_80030A68:
    // 0x80030A68: mflo        $t9
    ctx->r25 = lo;
    // 0x80030A6C: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x80030A70: nop

    // 0x80030A74: div         $zero, $t4, $t0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r8)));
    // 0x80030A78: bne         $t0, $zero, L_80030A84
    if (ctx->r8 != 0) {
        // 0x80030A7C: nop
    
            goto L_80030A84;
    }
    // 0x80030A7C: nop

    // 0x80030A80: break       7
    do_break(2147682944);
L_80030A84:
    // 0x80030A84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030A88: bne         $t0, $at, L_80030A9C
    if (ctx->r8 != ctx->r1) {
        // 0x80030A8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030A9C;
    }
    // 0x80030A8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030A90: bne         $t4, $at, L_80030A9C
    if (ctx->r12 != ctx->r1) {
        // 0x80030A94: nop
    
            goto L_80030A9C;
    }
    // 0x80030A94: nop

    // 0x80030A98: break       6
    do_break(2147682968);
L_80030A9C:
    // 0x80030A9C: mflo        $t6
    ctx->r14 = lo;
    // 0x80030AA0: andi        $t2, $t6, 0xFFFF
    ctx->r10 = ctx->r14 & 0XFFFF;
    // 0x80030AA4: sll         $t7, $t2, 16
    ctx->r15 = S32(ctx->r10 << 16);
    // 0x80030AA8: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x80030AAC: jr          $ra
    // 0x80030AB0: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    return;
    // 0x80030AB0: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
;}
RECOMP_FUNC void obj_loop_fogchanger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030AB4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80030AB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80030ABC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80030AC0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80030AC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80030AC8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80030ACC: lw          $t3, 0x3C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X3C);
    // 0x80030AD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80030AD4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80030AD8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80030ADC: jal         0x80066750
    // 0x80030AE0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_0;
    // 0x80030AE0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_0:
    // 0x80030AE4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80030AE8: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80030AEC: beq         $v0, $zero, L_80030B1C
    if (ctx->r2 == 0) {
        // 0x80030AF0: addiu       $a0, $sp, 0x74
        ctx->r4 = ADD32(ctx->r29, 0X74);
            goto L_80030B1C;
    }
    // 0x80030AF0: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80030AF4: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x80030AF8: jal         0x80069FBC
    // 0x80030AFC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    cam_get_cameras(rdram, ctx);
        goto after_1;
    // 0x80030AFC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_1:
    // 0x80030B00: jal         0x80066450
    // 0x80030B04: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    cam_get_viewport_layout(rdram, ctx);
        goto after_2;
    // 0x80030B04: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_2:
    // 0x80030B08: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80030B0C: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80030B10: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80030B14: b           L_80030B2C
    // 0x80030B18: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
        goto L_80030B2C;
    // 0x80030B18: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
L_80030B1C:
    // 0x80030B1C: jal         0x8001BAA8
    // 0x80030B20: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    get_racer_objects(rdram, ctx);
        goto after_3;
    // 0x80030B20: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_3:
    // 0x80030B24: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80030B28: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
L_80030B2C:
    // 0x80030B2C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80030B30: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80030B34: blez        $t7, L_80030E04
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80030B38: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80030E04;
    }
    // 0x80030B38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80030B3C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80030B40: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80030B44: addiu       $t4, $t4, -0x26F8
    ctx->r12 = ADD32(ctx->r12, -0X26F8);
    // 0x80030B48: addiu       $s2, $zero, 0x44
    ctx->r18 = ADD32(0, 0X44);
    // 0x80030B4C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80030B50: addiu       $t5, $zero, 0x38
    ctx->r13 = ADD32(0, 0X38);
L_80030B54:
    // 0x80030B54: beq         $ra, $zero, L_80030BB8
    if (ctx->r31 == 0) {
        // 0x80030B58: or          $t2, $s1, $zero
        ctx->r10 = ctx->r17 | 0;
            goto L_80030BB8;
    }
    // 0x80030B58: or          $t2, $s1, $zero
    ctx->r10 = ctx->r17 | 0;
    // 0x80030B5C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80030B60: addu        $t9, $ra, $t8
    ctx->r25 = ADD32(ctx->r31, ctx->r24);
    // 0x80030B64: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80030B68: nop

    // 0x80030B6C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80030B70: nop

    // 0x80030B74: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80030B78: nop

    // 0x80030B7C: bltz        $v0, L_80030BFC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80030B80: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_80030BFC;
    }
    // 0x80030B80: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80030B84: beq         $at, $zero, L_80030BFC
    if (ctx->r1 == 0) {
        // 0x80030B88: nop
    
            goto L_80030BFC;
    }
    // 0x80030B88: nop

    // 0x80030B8C: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030B90: mflo        $t6
    ctx->r14 = lo;
    // 0x80030B94: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80030B98: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x80030B9C: nop

    // 0x80030BA0: beq         $s0, $t8, L_80030BFC
    if (ctx->r16 == ctx->r24) {
        // 0x80030BA4: nop
    
            goto L_80030BFC;
    }
    // 0x80030BA4: nop

    // 0x80030BA8: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80030BAC: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80030BB0: b           L_80030BFC
    // 0x80030BB4: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
        goto L_80030BFC;
    // 0x80030BB4: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_80030BB8:
    // 0x80030BB8: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80030BBC: beq         $at, $zero, L_80030BFC
    if (ctx->r1 == 0) {
        // 0x80030BC0: nop
    
            goto L_80030BFC;
    }
    // 0x80030BC0: nop

    // 0x80030BC4: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030BC8: mflo        $t9
    ctx->r25 = lo;
    // 0x80030BCC: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x80030BD0: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x80030BD4: nop

    // 0x80030BD8: beq         $s0, $t7, L_80030BFC
    if (ctx->r16 == ctx->r15) {
        // 0x80030BDC: nop
    
            goto L_80030BFC;
    }
    // 0x80030BDC: nop

    // 0x80030BE0: multu       $a2, $s2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030BE4: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x80030BE8: mflo        $t8
    ctx->r24 = lo;
    // 0x80030BEC: addu        $v0, $s3, $t8
    ctx->r2 = ADD32(ctx->r19, ctx->r24);
    // 0x80030BF0: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80030BF4: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80030BF8: nop

L_80030BFC:
    // 0x80030BFC: beq         $t2, $s1, L_80030DF0
    if (ctx->r10 == ctx->r17) {
        // 0x80030C00: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_80030DF0;
    }
    // 0x80030C00: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80030C04: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80030C08: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80030C0C: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80030C10: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80030C14: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80030C18: sub.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80030C1C: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80030C20: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80030C24: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80030C28: nop

    // 0x80030C2C: bc1f        L_80030DF0
    if (!c1cs) {
        // 0x80030C30: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_80030DF0;
    }
    // 0x80030C30: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80030C34: lh          $a0, 0xC($t3)
    ctx->r4 = MEM_H(ctx->r11, 0XC);
    // 0x80030C38: lh          $v1, 0xE($t3)
    ctx->r3 = MEM_H(ctx->r11, 0XE);
    // 0x80030C3C: lbu         $a3, 0x9($t3)
    ctx->r7 = MEM_BU(ctx->r11, 0X9);
    // 0x80030C40: lbu         $t0, 0xA($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0XA);
    // 0x80030C44: lbu         $t1, 0xB($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0XB);
    // 0x80030C48: lh          $a1, 0x10($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X10);
    // 0x80030C4C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80030C50: beq         $at, $zero, L_80030C60
    if (ctx->r1 == 0) {
        // 0x80030C54: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80030C60;
    }
    // 0x80030C54: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80030C58: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80030C5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80030C60:
    // 0x80030C60: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x80030C64: bne         $at, $zero, L_80030C74
    if (ctx->r1 != 0) {
        // 0x80030C68: addiu       $v0, $v1, -0x5
        ctx->r2 = ADD32(ctx->r3, -0X5);
            goto L_80030C74;
    }
    // 0x80030C68: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x80030C6C: addiu       $v1, $zero, 0x3FF
    ctx->r3 = ADD32(0, 0X3FF);
    // 0x80030C70: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
L_80030C74:
    // 0x80030C74: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030C78: bne         $at, $zero, L_80030C84
    if (ctx->r1 != 0) {
        // 0x80030C7C: nop
    
            goto L_80030C84;
    }
    // 0x80030C7C: nop

    // 0x80030C80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80030C84:
    // 0x80030C84: multu       $t2, $t5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030C88: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80030C8C: mflo        $t9
    ctx->r25 = lo;
    // 0x80030C90: addu        $v0, $t4, $t9
    ctx->r2 = ADD32(ctx->r12, ctx->r25);
    // 0x80030C94: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80030C98: sb          $a3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r7;
    // 0x80030C9C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030CA0: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030CA4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80030CA8: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x80030CAC: sb          $t0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r8;
    // 0x80030CB0: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x80030CB4: sh          $a0, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r4;
    // 0x80030CB8: sh          $v1, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r3;
    // 0x80030CBC: bne         $a1, $zero, L_80030CC8
    if (ctx->r5 != 0) {
        // 0x80030CC0: nop
    
            goto L_80030CC8;
    }
    // 0x80030CC0: nop

    // 0x80030CC4: break       7
    do_break(2147683524);
L_80030CC8:
    // 0x80030CC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030CCC: bne         $a1, $at, L_80030CE0
    if (ctx->r5 != ctx->r1) {
        // 0x80030CD0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030CE0;
    }
    // 0x80030CD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030CD4: bne         $t8, $at, L_80030CE0
    if (ctx->r24 != ctx->r1) {
        // 0x80030CD8: nop
    
            goto L_80030CE0;
    }
    // 0x80030CD8: nop

    // 0x80030CDC: break       6
    do_break(2147683548);
L_80030CE0:
    // 0x80030CE0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030CE4: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80030CE8: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x80030CEC: sw          $a1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r5;
    // 0x80030CF0: sw          $s0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r16;
    // 0x80030CF4: mflo        $t9
    ctx->r25 = lo;
    // 0x80030CF8: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x80030CFC: nop

    // 0x80030D00: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030D04: bne         $a1, $zero, L_80030D10
    if (ctx->r5 != 0) {
        // 0x80030D08: nop
    
            goto L_80030D10;
    }
    // 0x80030D08: nop

    // 0x80030D0C: break       7
    do_break(2147683596);
L_80030D10:
    // 0x80030D10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030D14: bne         $a1, $at, L_80030D28
    if (ctx->r5 != ctx->r1) {
        // 0x80030D18: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030D28;
    }
    // 0x80030D18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030D1C: bne         $t8, $at, L_80030D28
    if (ctx->r24 != ctx->r1) {
        // 0x80030D20: nop
    
            goto L_80030D28;
    }
    // 0x80030D20: nop

    // 0x80030D24: break       6
    do_break(2147683620);
L_80030D28:
    // 0x80030D28: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030D2C: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x80030D30: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80030D34: mflo        $t9
    ctx->r25 = lo;
    // 0x80030D38: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x80030D3C: nop

    // 0x80030D40: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030D44: bne         $a1, $zero, L_80030D50
    if (ctx->r5 != 0) {
        // 0x80030D48: nop
    
            goto L_80030D50;
    }
    // 0x80030D48: nop

    // 0x80030D4C: break       7
    do_break(2147683660);
L_80030D50:
    // 0x80030D50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030D54: bne         $a1, $at, L_80030D68
    if (ctx->r5 != ctx->r1) {
        // 0x80030D58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030D68;
    }
    // 0x80030D58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030D5C: bne         $t8, $at, L_80030D68
    if (ctx->r24 != ctx->r1) {
        // 0x80030D60: nop
    
            goto L_80030D68;
    }
    // 0x80030D60: nop

    // 0x80030D64: break       6
    do_break(2147683684);
L_80030D68:
    // 0x80030D68: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030D6C: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x80030D70: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80030D74: mflo        $t9
    ctx->r25 = lo;
    // 0x80030D78: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x80030D7C: nop

    // 0x80030D80: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030D84: bne         $a1, $zero, L_80030D90
    if (ctx->r5 != 0) {
        // 0x80030D88: nop
    
            goto L_80030D90;
    }
    // 0x80030D88: nop

    // 0x80030D8C: break       7
    do_break(2147683724);
L_80030D90:
    // 0x80030D90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030D94: bne         $a1, $at, L_80030DA8
    if (ctx->r5 != ctx->r1) {
        // 0x80030D98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030DA8;
    }
    // 0x80030D98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030D9C: bne         $t8, $at, L_80030DA8
    if (ctx->r24 != ctx->r1) {
        // 0x80030DA0: nop
    
            goto L_80030DA8;
    }
    // 0x80030DA0: nop

    // 0x80030DA4: break       6
    do_break(2147683748);
L_80030DA8:
    // 0x80030DA8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030DAC: mflo        $t9
    ctx->r25 = lo;
    // 0x80030DB0: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
    // 0x80030DB4: nop

    // 0x80030DB8: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030DBC: bne         $a1, $zero, L_80030DC8
    if (ctx->r5 != 0) {
        // 0x80030DC0: nop
    
            goto L_80030DC8;
    }
    // 0x80030DC0: nop

    // 0x80030DC4: break       7
    do_break(2147683780);
L_80030DC8:
    // 0x80030DC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030DCC: bne         $a1, $at, L_80030DE0
    if (ctx->r5 != ctx->r1) {
        // 0x80030DD0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030DE0;
    }
    // 0x80030DD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030DD4: bne         $t8, $at, L_80030DE0
    if (ctx->r24 != ctx->r1) {
        // 0x80030DD8: nop
    
            goto L_80030DE0;
    }
    // 0x80030DD8: nop

    // 0x80030DDC: break       6
    do_break(2147683804);
L_80030DE0:
    // 0x80030DE0: mflo        $t9
    ctx->r25 = lo;
    // 0x80030DE4: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x80030DE8: nop

    // 0x80030DEC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80030DF0:
    // 0x80030DF0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80030DF4: bne         $a2, $t6, L_80030B54
    if (ctx->r6 != ctx->r14) {
        // 0x80030DF8: nop
    
            goto L_80030B54;
    }
    // 0x80030DF8: nop

    // 0x80030DFC: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    // 0x80030E00: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
L_80030E04:
    // 0x80030E04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80030E08: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80030E0C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80030E10: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80030E14: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80030E18: jr          $ra
    // 0x80030E1C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80030E1C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void slowly_change_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030E20: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80030E24: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80030E28: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80030E2C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80030E30: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80030E34: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80030E38: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80030E3C: beq         $at, $zero, L_80030E50
    if (ctx->r1 == 0) {
        // 0x80030E40: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_80030E50;
    }
    // 0x80030E40: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80030E44: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80030E48: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80030E4C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80030E50:
    // 0x80030E50: slti        $at, $s0, 0x400
    ctx->r1 = SIGNED(ctx->r16) < 0X400 ? 1 : 0;
    // 0x80030E54: bne         $at, $zero, L_80030E60
    if (ctx->r1 != 0) {
        // 0x80030E58: subu        $t6, $t6, $a0
        ctx->r14 = SUB32(ctx->r14, ctx->r4);
            goto L_80030E60;
    }
    // 0x80030E58: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80030E5C: addiu       $s0, $zero, 0x3FF
    ctx->r16 = ADD32(0, 0X3FF);
L_80030E60:
    // 0x80030E60: addiu       $v0, $s0, -0x5
    ctx->r2 = ADD32(ctx->r16, -0X5);
    // 0x80030E64: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030E68: bne         $at, $zero, L_80030E74
    if (ctx->r1 != 0) {
        // 0x80030E6C: sll         $t6, $t6, 3
        ctx->r14 = S32(ctx->r14 << 3);
            goto L_80030E74;
    }
    // 0x80030E6C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80030E70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80030E74:
    // 0x80030E74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80030E78: addiu       $t7, $t7, -0x26F8
    ctx->r15 = ADD32(ctx->r15, -0X26F8);
    // 0x80030E7C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80030E80: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80030E84: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80030E88: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80030E8C: div         $zero, $t0, $v1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r3)));
    // 0x80030E90: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x80030E94: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x80030E98: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80030E9C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80030EA0: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80030EA4: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030EA8: sb          $a1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r5;
    // 0x80030EAC: sb          $a2, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r6;
    // 0x80030EB0: sb          $a3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r7;
    // 0x80030EB4: sh          $s1, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r17;
    // 0x80030EB8: sh          $s0, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r16;
    // 0x80030EBC: bne         $v1, $zero, L_80030EC8
    if (ctx->r3 != 0) {
        // 0x80030EC0: nop
    
            goto L_80030EC8;
    }
    // 0x80030EC0: nop

    // 0x80030EC4: break       7
    do_break(2147684036);
L_80030EC8:
    // 0x80030EC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030ECC: bne         $v1, $at, L_80030EE0
    if (ctx->r3 != ctx->r1) {
        // 0x80030ED0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030EE0;
    }
    // 0x80030ED0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030ED4: bne         $t0, $at, L_80030EE0
    if (ctx->r8 != ctx->r1) {
        // 0x80030ED8: nop
    
            goto L_80030EE0;
    }
    // 0x80030ED8: nop

    // 0x80030EDC: break       6
    do_break(2147684060);
L_80030EE0:
    // 0x80030EE0: sll         $t0, $s1, 16
    ctx->r8 = S32(ctx->r17 << 16);
    // 0x80030EE4: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x80030EE8: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x80030EEC: mflo        $t1
    ctx->r9 = lo;
    // 0x80030EF0: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
    // 0x80030EF4: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80030EF8: div         $zero, $t4, $v1
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r3)));
    // 0x80030EFC: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80030F00: bne         $v1, $zero, L_80030F0C
    if (ctx->r3 != 0) {
        // 0x80030F04: nop
    
            goto L_80030F0C;
    }
    // 0x80030F04: nop

    // 0x80030F08: break       7
    do_break(2147684104);
L_80030F0C:
    // 0x80030F0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030F10: bne         $v1, $at, L_80030F24
    if (ctx->r3 != ctx->r1) {
        // 0x80030F14: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030F24;
    }
    // 0x80030F14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030F18: bne         $t4, $at, L_80030F24
    if (ctx->r12 != ctx->r1) {
        // 0x80030F1C: nop
    
            goto L_80030F24;
    }
    // 0x80030F1C: nop

    // 0x80030F20: break       6
    do_break(2147684128);
L_80030F24:
    // 0x80030F24: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80030F28: mflo        $t5
    ctx->r13 = lo;
    // 0x80030F2C: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x80030F30: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x80030F34: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x80030F38: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80030F3C: bne         $v1, $zero, L_80030F48
    if (ctx->r3 != 0) {
        // 0x80030F40: nop
    
            goto L_80030F48;
    }
    // 0x80030F40: nop

    // 0x80030F44: break       7
    do_break(2147684164);
L_80030F48:
    // 0x80030F48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030F4C: bne         $v1, $at, L_80030F60
    if (ctx->r3 != ctx->r1) {
        // 0x80030F50: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030F60;
    }
    // 0x80030F50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030F54: bne         $t8, $at, L_80030F60
    if (ctx->r24 != ctx->r1) {
        // 0x80030F58: nop
    
            goto L_80030F60;
    }
    // 0x80030F58: nop

    // 0x80030F5C: break       6
    do_break(2147684188);
L_80030F60:
    // 0x80030F60: mflo        $t9
    ctx->r25 = lo;
    // 0x80030F64: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x80030F68: nop

    // 0x80030F6C: div         $zero, $t2, $v1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r3)));
    // 0x80030F70: bne         $v1, $zero, L_80030F7C
    if (ctx->r3 != 0) {
        // 0x80030F74: nop
    
            goto L_80030F7C;
    }
    // 0x80030F74: nop

    // 0x80030F78: break       7
    do_break(2147684216);
L_80030F7C:
    // 0x80030F7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030F80: bne         $v1, $at, L_80030F94
    if (ctx->r3 != ctx->r1) {
        // 0x80030F84: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030F94;
    }
    // 0x80030F84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030F88: bne         $t2, $at, L_80030F94
    if (ctx->r10 != ctx->r1) {
        // 0x80030F8C: nop
    
            goto L_80030F94;
    }
    // 0x80030F8C: nop

    // 0x80030F90: break       6
    do_break(2147684240);
L_80030F94:
    // 0x80030F94: mflo        $t3
    ctx->r11 = lo;
    // 0x80030F98: sw          $t3, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r11;
    // 0x80030F9C: nop

    // 0x80030FA0: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x80030FA4: bne         $v1, $zero, L_80030FB0
    if (ctx->r3 != 0) {
        // 0x80030FA8: nop
    
            goto L_80030FB0;
    }
    // 0x80030FA8: nop

    // 0x80030FAC: break       7
    do_break(2147684268);
L_80030FB0:
    // 0x80030FB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030FB4: bne         $v1, $at, L_80030FC8
    if (ctx->r3 != ctx->r1) {
        // 0x80030FB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030FC8;
    }
    // 0x80030FB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030FBC: bne         $t6, $at, L_80030FC8
    if (ctx->r14 != ctx->r1) {
        // 0x80030FC0: nop
    
            goto L_80030FC8;
    }
    // 0x80030FC0: nop

    // 0x80030FC4: break       6
    do_break(2147684292);
L_80030FC8:
    // 0x80030FC8: mflo        $t7
    ctx->r15 = lo;
    // 0x80030FCC: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x80030FD0: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80030FD4: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80030FD8: jr          $ra
    // 0x80030FDC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80030FDC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void update_perspective_and_envmap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030FE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030FE8: jal         0x80069F60
    // 0x80030FEC: nop

    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x80030FEC: nop

    after_0:
    // 0x80030FF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80030FF4: jal         0x80031058
    // 0x80030FF8: sw          $v0, -0x49D0($at)
    MEM_W(-0X49D0, ctx->r1) = ctx->r2;
    compute_scene_camera_transform_matrix(rdram, ctx);
        goto after_1;
    // 0x80030FF8: sw          $v0, -0x49D0($at)
    MEM_W(-0X49D0, ctx->r1) = ctx->r2;
    after_1:
    // 0x80030FFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80031000: addiu       $v0, $v0, -0x2618
    ctx->r2 = ADD32(ctx->r2, -0X2618);
    // 0x80031004: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80031008: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8003100C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80031010: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80031014: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80031018: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8003101C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80031020: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80031024: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80031028: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8003102C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80031030: nop

    // 0x80031034: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80031038: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003103C: div.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80031040: jal         0x8001D614
    // 0x80031044: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    update_envmap_position(rdram, ctx);
        goto after_2;
    // 0x80031044: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    after_2:
    // 0x80031048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003104C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031050: jr          $ra
    // 0x80031054: nop

    return;
    // 0x80031054: nop

;}
RECOMP_FUNC void compute_scene_camera_transform_matrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031058: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8003105C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80031060: lui         $at, 0xC780
    ctx->r1 = S32(0XC780 << 16);
    // 0x80031064: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80031068: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8003106C: lw          $v0, -0x49D0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X49D0);
    // 0x80031070: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80031074: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80031078: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8003107C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80031080: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80031084: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80031088: sh          $t6, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r14;
    // 0x8003108C: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80031090: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80031094: sh          $t7, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r15;
    // 0x80031098: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8003109C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800310A0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800310A4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800310A8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800310AC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800310B0: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800310B4: jal         0x8006FE70
    // 0x800310B8: sh          $t8, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r24;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x800310B8: sh          $t8, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r24;
    after_0:
    // 0x800310BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800310C0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800310C4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800310C8: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800310CC: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x800310D0: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x800310D4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800310D8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800310DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800310E0: jal         0x8006F88C
    // 0x800310E4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x800310E4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_1:
    // 0x800310E8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800310EC: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800310F0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800310F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800310F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800310FC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80031100: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80031104: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80031108: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8003110C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80031110: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80031114: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80031118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003111C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80031120: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80031124: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80031128: addiu       $v0, $v0, -0x2618
    ctx->r2 = ADD32(ctx->r2, -0X2618);
    // 0x8003112C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80031130: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80031134: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80031138: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8003113C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80031140: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80031144: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80031148: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003114C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80031150: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80031154: nop

    // 0x80031158: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003115C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80031160: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80031164: jr          $ra
    // 0x80031168: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    return;
    // 0x80031168: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8003116C: nop

;}
RECOMP_FUNC void generate_collision_candidates(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031170: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80031174: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80031178: lui         $t1, 0xFFFE
    ctx->r9 = S32(0XFFFE << 16);
    // 0x8003117C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80031180: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80031184: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80031188: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8003118C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80031190: ori         $t0, $t0, 0x86A0
    ctx->r8 = ctx->r8 | 0X86A0;
    // 0x80031194: ori         $t1, $t1, 0x7960
    ctx->r9 = ctx->r9 | 0X7960;
    // 0x80031198: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8003119C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800311A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800311A4: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
    // 0x800311A8: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
    // 0x800311AC: or          $s3, $t0, $zero
    ctx->r19 = ctx->r8 | 0;
    // 0x800311B0: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x800311B4: beq         $a0, $zero, L_8003128C
    if (ctx->r4 == 0) {
        // 0x800311B8: or          $s6, $a3, $zero
        ctx->r22 = ctx->r7 | 0;
            goto L_8003128C;
    }
    // 0x800311B8: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x800311BC: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x800311C0: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x800311C4: add         $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x800311C8: add         $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
L_800311CC:
    // 0x800311CC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800311D0: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800311D4: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800311D8: trunc.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800311DC: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800311E0: trunc.w.s   $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800311E4: mfc1        $t0, $f0
    ctx->r8 = (int32_t)ctx->f0.u32l;
    // 0x800311E8: trunc.w.s   $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800311EC: mfc1        $t1, $f2
    ctx->r9 = (int32_t)ctx->f2.u32l;
    // 0x800311F0: slt         $at, $s4, $t0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800311F4: trunc.w.s   $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800311F8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800311FC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80031200: beql        $at, $zero, L_80031210
    if (ctx->r1 == 0) {
        // 0x80031204: slt         $at, $t0, $s5
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_80031210;
    }
    goto skip_0;
    // 0x80031204: slt         $at, $t0, $s5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r21) ? 1 : 0;
    skip_0:
    // 0x80031208: or          $s4, $t0, $zero
    ctx->r20 = ctx->r8 | 0;
    // 0x8003120C: slt         $at, $t0, $s5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r21) ? 1 : 0;
L_80031210:
    // 0x80031210: beql        $at, $zero, L_80031220
    if (ctx->r1 == 0) {
        // 0x80031214: slt         $at, $s2, $t1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80031220;
    }
    goto skip_1;
    // 0x80031214: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    skip_1:
    // 0x80031218: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
    // 0x8003121C: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
L_80031220:
    // 0x80031220: beql        $at, $zero, L_80031230
    if (ctx->r1 == 0) {
        // 0x80031224: slt         $at, $t1, $s3
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80031230;
    }
    goto skip_2;
    // 0x80031224: slt         $at, $t1, $s3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r19) ? 1 : 0;
    skip_2:
    // 0x80031228: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x8003122C: slt         $at, $t1, $s3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r19) ? 1 : 0;
L_80031230:
    // 0x80031230: beql        $at, $zero, L_80031240
    if (ctx->r1 == 0) {
        // 0x80031234: slt         $at, $s4, $t2
        ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80031240;
    }
    goto skip_3;
    // 0x80031234: slt         $at, $s4, $t2
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r10) ? 1 : 0;
    skip_3:
    // 0x80031238: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x8003123C: slt         $at, $s4, $t2
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r10) ? 1 : 0;
L_80031240:
    // 0x80031240: beql        $at, $zero, L_80031250
    if (ctx->r1 == 0) {
        // 0x80031244: slt         $at, $t2, $s5
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_80031250;
    }
    goto skip_4;
    // 0x80031244: slt         $at, $t2, $s5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r21) ? 1 : 0;
    skip_4:
    // 0x80031248: or          $s4, $t2, $zero
    ctx->r20 = ctx->r10 | 0;
    // 0x8003124C: slt         $at, $t2, $s5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r21) ? 1 : 0;
L_80031250:
    // 0x80031250: beql        $at, $zero, L_80031260
    if (ctx->r1 == 0) {
        // 0x80031254: slt         $at, $s2, $t3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80031260;
    }
    goto skip_5;
    // 0x80031254: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    skip_5:
    // 0x80031258: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
    // 0x8003125C: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
L_80031260:
    // 0x80031260: beql        $at, $zero, L_80031270
    if (ctx->r1 == 0) {
        // 0x80031264: slt         $at, $t3, $s3
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80031270;
    }
    goto skip_6;
    // 0x80031264: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
    skip_6:
    // 0x80031268: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x8003126C: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
L_80031270:
    // 0x80031270: beql        $at, $zero, L_80031280
    if (ctx->r1 == 0) {
        // 0x80031274: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_80031280;
    }
    goto skip_7;
    // 0x80031274: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    skip_7:
    // 0x80031278: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x8003127C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_80031280:
    // 0x80031280: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80031284: bne         $at, $zero, L_800311CC
    if (ctx->r1 != 0) {
        // 0x80031288: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_800311CC;
    }
    // 0x80031288: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_8003128C:
    // 0x8003128C: addiu       $s5, $s5, -0x14
    ctx->r21 = ADD32(ctx->r21, -0X14);
    // 0x80031290: addiu       $s4, $s4, 0x14
    ctx->r20 = ADD32(ctx->r20, 0X14);
    // 0x80031294: slt         $at, $s4, $s5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80031298: addiu       $s3, $s3, -0x14
    ctx->r19 = ADD32(ctx->r19, -0X14);
    // 0x8003129C: beq         $at, $zero, L_800312B0
    if (ctx->r1 == 0) {
        // 0x800312A0: addiu       $s2, $s2, 0x14
        ctx->r18 = ADD32(ctx->r18, 0X14);
            goto L_800312B0;
    }
    // 0x800312A0: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x800312A4: or          $t0, $s5, $zero
    ctx->r8 = ctx->r21 | 0;
    // 0x800312A8: or          $s5, $s4, $zero
    ctx->r21 = ctx->r20 | 0;
    // 0x800312AC: or          $s4, $t0, $zero
    ctx->r20 = ctx->r8 | 0;
L_800312B0:
    // 0x800312B0: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800312B4: beq         $at, $zero, L_800312C8
    if (ctx->r1 == 0) {
        // 0x800312B8: nop
    
            goto L_800312C8;
    }
    // 0x800312B8: nop

    // 0x800312BC: or          $t0, $s3, $zero
    ctx->r8 = ctx->r19 | 0;
    // 0x800312C0: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x800312C4: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
L_800312C8:
    // 0x800312C8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800312CC: lw          $t0, -0x3178($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3178);
    // 0x800312D0: addi        $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x800312D4: addi        $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x800312D8: lh          $t7, 0x1A($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X1A);
    // 0x800312DC: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800312E0: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x800312E4: beq         $t7, $zero, L_80031374
    if (ctx->r15 == 0) {
        // 0x800312E8: lw          $t6, 0x4($t0)
        ctx->r14 = MEM_W(ctx->r8, 0X4);
            goto L_80031374;
    }
    // 0x800312E8: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
L_800312EC:
    // 0x800312EC: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x800312F0: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x800312F4: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x800312F8: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800312FC: bne         $at, $zero, L_80031364
    if (ctx->r1 != 0) {
        // 0x80031300: addiu       $v1, $v1, -0x5
        ctx->r3 = ADD32(ctx->r3, -0X5);
            goto L_80031364;
    }
    // 0x80031300: addiu       $v1, $v1, -0x5
    ctx->r3 = ADD32(ctx->r3, -0X5);
    // 0x80031304: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80031308: bnel        $at, $zero, L_80031368
    if (ctx->r1 != 0) {
        // 0x8003130C: addiu       $t7, $t7, -0x1
        ctx->r15 = ADD32(ctx->r15, -0X1);
            goto L_80031368;
    }
    goto skip_8;
    // 0x8003130C: addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
    skip_8:
    // 0x80031310: lh          $t0, 0xA($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XA);
    // 0x80031314: lh          $t1, 0x4($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4);
    // 0x80031318: addiu       $t0, $t0, 0x5
    ctx->r8 = ADD32(ctx->r8, 0X5);
    // 0x8003131C: slt         $at, $t0, $s3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80031320: bne         $at, $zero, L_80031364
    if (ctx->r1 != 0) {
        // 0x80031324: addiu       $t1, $t1, -0x5
        ctx->r9 = ADD32(ctx->r9, -0X5);
            goto L_80031364;
    }
    // 0x80031324: addiu       $t1, $t1, -0x5
    ctx->r9 = ADD32(ctx->r9, -0X5);
    // 0x80031328: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8003132C: bnel        $at, $zero, L_80031368
    if (ctx->r1 != 0) {
        // 0x80031330: addiu       $t7, $t7, -0x1
        ctx->r15 = ADD32(ctx->r15, -0X1);
            goto L_80031368;
    }
    goto skip_9;
    // 0x80031330: addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
    skip_9:
    // 0x80031334: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80031338: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8003133C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80031340: jal         0x8003151C
    // 0x80031344: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    compute_grid_overlap_mask(rdram, ctx);
        goto after_0;
    // 0x80031344: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_0:
    // 0x80031348: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8003134C: addiu       $t8, $t8, 0x1
    ctx->r24 = ADD32(ctx->r24, 0X1);
    // 0x80031350: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80031354: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80031358: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8003135C: beq         $t8, $at, L_80031374
    if (ctx->r24 == ctx->r1) {
        // 0x80031360: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80031374;
    }
    // 0x80031360: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80031364:
    // 0x80031364: addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
L_80031368:
    // 0x80031368: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x8003136C: bne         $t7, $zero, L_800312EC
    if (ctx->r15 != 0) {
        // 0x80031370: addiu       $t6, $t6, 0x44
        ctx->r14 = ADD32(ctx->r14, 0X44);
            goto L_800312EC;
    }
    // 0x80031370: addiu       $t6, $t6, 0x44
    ctx->r14 = ADD32(ctx->r14, 0X44);
L_80031374:
    // 0x80031374: beq         $t8, $zero, L_800314E8
    if (ctx->r24 == 0) {
        // 0x80031378: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800314E8;
    }
    // 0x80031378: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003137C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80031380: lw          $a0, -0x3178($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3178);
    // 0x80031384: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80031388: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8003138C: addi        $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80031390: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80031394: lw          $s2, -0x2710($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X2710);
    // 0x80031398: lw          $t9, -0x270C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X270C);
    // 0x8003139C: addi        $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x800313A0: add         $t8, $s1, $t8
    ctx->r24 = ADD32(ctx->r17, ctx->r24);
    // 0x800313A4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
L_800313A8:
    // 0x800313A8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800313AC: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800313B0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800313B4: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x800313B8: and         $v0, $t7, $at
    ctx->r2 = ctx->r15 & ctx->r1;
    // 0x800313BC: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800313C0: lh          $t0, 0x20($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X20);
    // 0x800313C4: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x800313C8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800313CC: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x800313D0: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x800313D4: add         $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x800313D8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800313DC: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x800313E0: add         $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800313E4: addiu       $t4, $t5, 0xC
    ctx->r12 = ADD32(ctx->r13, 0XC);
L_800313E8:
    // 0x800313E8: lw          $t0, 0x8($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X8);
    // 0x800313EC: andi        $v0, $t0, 0x200
    ctx->r2 = ctx->r8 & 0X200;
    // 0x800313F0: bne         $v0, $zero, L_800314C8
    if (ctx->r2 != 0) {
        // 0x800313F4: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800314C8;
    }
    // 0x800313F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800313F8: bnel        $s6, $at, L_80031410
    if (ctx->r22 != ctx->r1) {
        // 0x800313FC: lbu         $v1, 0x0($t5)
        ctx->r3 = MEM_BU(ctx->r13, 0X0);
            goto L_80031410;
    }
    goto skip_10;
    // 0x800313FC: lbu         $v1, 0x0($t5)
    ctx->r3 = MEM_BU(ctx->r13, 0X0);
    skip_10:
    // 0x80031400: andi        $v0, $t0, 0x100
    ctx->r2 = ctx->r8 & 0X100;
    // 0x80031404: bnel        $v0, $zero, L_800314CC
    if (ctx->r2 != 0) {
        // 0x80031408: addiu       $t5, $t5, 0xC
        ctx->r13 = ADD32(ctx->r13, 0XC);
            goto L_800314CC;
    }
    goto skip_11;
    // 0x80031408: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    skip_11:
    // 0x8003140C: lbu         $v1, 0x0($t5)
    ctx->r3 = MEM_BU(ctx->r13, 0X0);
L_80031410:
    // 0x80031410: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80031414: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80031418: beql        $v1, $at, L_8003145C
    if (ctx->r3 == ctx->r1) {
        // 0x8003141C: lh          $t0, 0x4($t5)
        ctx->r8 = MEM_H(ctx->r13, 0X4);
            goto L_8003145C;
    }
    goto skip_12;
    // 0x8003141C: lh          $t0, 0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X4);
    skip_12:
    // 0x80031420: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80031424: add         $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80031428: lb          $t2, 0x7($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X7);
    // 0x8003142C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80031430: beq         $t2, $at, L_800314C8
    if (ctx->r10 == ctx->r1) {
        // 0x80031434: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800314C8;
    }
    // 0x80031434: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80031438: bne         $s6, $at, L_80031448
    if (ctx->r22 != ctx->r1) {
        // 0x8003143C: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80031448;
    }
    // 0x8003143C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80031440: beql        $t2, $at, L_800314CC
    if (ctx->r10 == ctx->r1) {
        // 0x80031444: addiu       $t5, $t5, 0xC
        ctx->r13 = ADD32(ctx->r13, 0XC);
            goto L_800314CC;
    }
    goto skip_13;
    // 0x80031444: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    skip_13:
L_80031448:
    // 0x80031448: beq         $s6, $zero, L_80031458
    if (ctx->r22 == 0) {
        // 0x8003144C: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80031458;
    }
    // 0x8003144C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80031450: beql        $t2, $at, L_800314CC
    if (ctx->r10 == ctx->r1) {
        // 0x80031454: addiu       $t5, $t5, 0xC
        ctx->r13 = ADD32(ctx->r13, 0XC);
            goto L_800314CC;
    }
    goto skip_14;
    // 0x80031454: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    skip_14:
L_80031458:
    // 0x80031458: lh          $t0, 0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X4);
L_8003145C:
    // 0x8003145C: lh          $t1, 0x4($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X4);
    // 0x80031460: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x80031464: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    // 0x80031468: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8003146C: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x80031470: sll         $v1, $t0, 3
    ctx->r3 = S32(ctx->r8 << 3);
    // 0x80031474: add         $a1, $a2, $t1
    ctx->r5 = ADD32(ctx->r6, ctx->r9);
    // 0x80031478: add         $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8003147C: add         $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
L_80031480:
    // 0x80031480: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x80031484: and         $t0, $t0, $t6
    ctx->r8 = ctx->r8 & ctx->r14;
    // 0x80031488: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x8003148C: beq         $v0, $zero, L_800314B8
    if (ctx->r2 == 0) {
        // 0x80031490: andi        $v1, $t0, 0xFF00
        ctx->r3 = ctx->r8 & 0XFF00;
            goto L_800314B8;
    }
    // 0x80031490: andi        $v1, $t0, 0xFF00
    ctx->r3 = ctx->r8 & 0XFF00;
    // 0x80031494: beql        $v1, $zero, L_800314BC
    if (ctx->r3 == 0) {
        // 0x80031498: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_800314BC;
    }
    goto skip_15;
    // 0x80031498: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_15:
    // 0x8003149C: sw          $a3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r7;
    // 0x800314A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800314A4: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x800314A8: sb          $t2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r10;
    // 0x800314AC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800314B0: beq         $s3, $at, L_800314E8
    if (ctx->r19 == ctx->r1) {
        // 0x800314B4: addiu       $t9, $t9, 0x1
        ctx->r25 = ADD32(ctx->r25, 0X1);
            goto L_800314E8;
    }
    // 0x800314B4: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
L_800314B8:
    // 0x800314B8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_800314BC:
    // 0x800314BC: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800314C0: bne         $at, $zero, L_80031480
    if (ctx->r1 != 0) {
        // 0x800314C4: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80031480;
    }
    // 0x800314C4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_800314C8:
    // 0x800314C8: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
L_800314CC:
    // 0x800314CC: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800314D0: bne         $at, $zero, L_800313E8
    if (ctx->r1 != 0) {
        // 0x800314D4: addiu       $t4, $t4, 0xC
        ctx->r12 = ADD32(ctx->r12, 0XC);
            goto L_800313E8;
    }
    // 0x800314D4: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x800314D8: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800314DC: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800314E0: bne         $at, $zero, L_800313A8
    if (ctx->r1 != 0) {
        // 0x800314E4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800313A8;
    }
    // 0x800314E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800314E8:
    // 0x800314E8: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800314EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800314F0: sw          $s3, -0x2708($at)
    MEM_W(-0X2708, ctx->r1) = ctx->r19;
    // 0x800314F4: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800314F8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800314FC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80031500: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80031504: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80031508: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003150C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80031510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031514: jr          $ra
    // 0x80031518: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80031518: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void compute_grid_overlap_mask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003151C: beq         $a0, $zero, L_80031638
    if (ctx->r4 == 0) {
        // 0x80031520: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80031638;
    }
    // 0x80031520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031524: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x80031528: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x8003152C: lh          $t1, 0x4($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4);
    // 0x80031530: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80031534: lh          $t2, 0x6($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X6);
    // 0x80031538: beq         $at, $zero, L_80031544
    if (ctx->r1 == 0) {
        // 0x8003153C: lh          $t3, 0xA($a0)
        ctx->r11 = MEM_H(ctx->r4, 0XA);
            goto L_80031544;
    }
    // 0x8003153C: lh          $t3, 0xA($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XA);
    // 0x80031540: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_80031544:
    // 0x80031544: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80031548: beql        $at, $zero, L_80031558
    if (ctx->r1 == 0) {
        // 0x8003154C: slt         $at, $t5, $t1
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80031558;
    }
    goto skip_0;
    // 0x8003154C: slt         $at, $t5, $t1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
    skip_0:
    // 0x80031550: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80031554: slt         $at, $t5, $t1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
L_80031558:
    // 0x80031558: beql        $at, $zero, L_80031568
    if (ctx->r1 == 0) {
        // 0x8003155C: slt         $at, $a2, $t1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80031568;
    }
    goto skip_1;
    // 0x8003155C: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    skip_1:
    // 0x80031560: or          $t5, $t1, $zero
    ctx->r13 = ctx->r9 | 0;
    // 0x80031564: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
L_80031568:
    // 0x80031568: beql        $at, $zero, L_80031578
    if (ctx->r1 == 0) {
        // 0x8003156C: slt         $at, $t2, $a3
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80031578;
    }
    goto skip_2;
    // 0x8003156C: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    skip_2:
    // 0x80031570: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80031574: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
L_80031578:
    // 0x80031578: beql        $at, $zero, L_80031588
    if (ctx->r1 == 0) {
        // 0x8003157C: slt         $at, $t2, $a1
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80031588;
    }
    goto skip_3;
    // 0x8003157C: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    skip_3:
    // 0x80031580: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x80031584: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
L_80031588:
    // 0x80031588: beql        $at, $zero, L_80031598
    if (ctx->r1 == 0) {
        // 0x8003158C: slt         $at, $t3, $t5
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
            goto L_80031598;
    }
    goto skip_4;
    // 0x8003158C: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    skip_4:
    // 0x80031590: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80031594: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
L_80031598:
    // 0x80031598: beql        $at, $zero, L_800315A8
    if (ctx->r1 == 0) {
        // 0x8003159C: slt         $at, $t3, $a2
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800315A8;
    }
    goto skip_5;
    // 0x8003159C: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    skip_5:
    // 0x800315A0: or          $t5, $t3, $zero
    ctx->r13 = ctx->r11 | 0;
    // 0x800315A4: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
L_800315A8:
    // 0x800315A8: beql        $at, $zero, L_800315B8
    if (ctx->r1 == 0) {
        // 0x800315AC: sub         $t2, $t2, $t0
        ctx->r10 = SUB32(ctx->r10, ctx->r8);
            goto L_800315B8;
    }
    goto skip_6;
    // 0x800315AC: sub         $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    skip_6:
    // 0x800315B0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800315B4: sub         $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
L_800315B8:
    // 0x800315B8: sra         $t2, $t2, 3
    ctx->r10 = S32(SIGNED(ctx->r10) >> 3);
    // 0x800315BC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800315C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800315C4: add         $t4, $t2, $t0
    ctx->r12 = ADD32(ctx->r10, ctx->r8);
L_800315C8:
    // 0x800315C8: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800315CC: bne         $at, $zero, L_800315E0
    if (ctx->r1 != 0) {
        // 0x800315D0: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800315E0;
    }
    // 0x800315D0: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800315D4: bnel        $at, $zero, L_800315E4
    if (ctx->r1 != 0) {
        // 0x800315D8: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_800315E4;
    }
    goto skip_7;
    // 0x800315D8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    skip_7:
    // 0x800315DC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_800315E0:
    // 0x800315E0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_800315E4:
    // 0x800315E4: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800315E8: add         $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800315EC: bne         $at, $zero, L_800315C8
    if (ctx->r1 != 0) {
        // 0x800315F0: add         $t0, $t0, $t2
        ctx->r8 = ADD32(ctx->r8, ctx->r10);
            goto L_800315C8;
    }
    // 0x800315F0: add         $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x800315F4: sub         $t2, $t3, $t1
    ctx->r10 = SUB32(ctx->r11, ctx->r9);
    // 0x800315F8: sra         $t2, $t2, 3
    ctx->r10 = S32(SIGNED(ctx->r10) >> 3);
    // 0x800315FC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80031600: add         $t4, $t2, $t1
    ctx->r12 = ADD32(ctx->r10, ctx->r9);
    // 0x80031604: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_80031608:
    // 0x80031608: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8003160C: bne         $at, $zero, L_80031620
    if (ctx->r1 != 0) {
        // 0x80031610: slt         $at, $t5, $t0
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80031620;
    }
    // 0x80031610: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80031614: bnel        $at, $zero, L_80031624
    if (ctx->r1 != 0) {
        // 0x80031618: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_80031624;
    }
    goto skip_8;
    // 0x80031618: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    skip_8:
    // 0x8003161C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_80031620:
    // 0x80031620: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_80031624:
    // 0x80031624: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80031628: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8003162C: add         $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x80031630: bne         $at, $zero, L_80031608
    if (ctx->r1 != 0) {
        // 0x80031634: add         $t0, $t0, $t2
        ctx->r8 = ADD32(ctx->r8, ctx->r10);
            goto L_80031608;
    }
    // 0x80031634: add         $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
L_80031638:
    // 0x80031638: jr          $ra
    // 0x8003163C: nop

    return;
    // 0x8003163C: nop

;}
