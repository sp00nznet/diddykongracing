#include "recomp.h"
#include "funcs.h"
#include <stdio.h>
static int _syn_start_params_calls = 0;

RECOMP_FUNC void __CSPPostNextSeqEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062C0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80062C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062C14: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80062C18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80062C1C: bne         $t6, $at, L_80062C6C
    if (ctx->r14 != ctx->r1) {
        // 0x80062C20: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80062C6C;
    }
    // 0x80062C20: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80062C24: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x80062C28: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80062C2C: beq         $a0, $zero, L_80062C70
    if (ctx->r4 == 0) {
        // 0x80062C30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80062C70;
    }
    // 0x80062C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062C34: jal         0x800C894C
    // 0x80062C38: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    __alCSeqNextDelta(rdram, ctx);
        goto after_0;
    // 0x80062C38: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x80062C3C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80062C40: beq         $v0, $zero, L_80062C70
    if (ctx->r2 == 0) {
        // 0x80062C44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80062C70;
    }
    // 0x80062C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062C48: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x80062C4C: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x80062C50: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80062C54: addiu       $a0, $a3, 0x48
    ctx->r4 = ADD32(ctx->r7, 0X48);
    // 0x80062C58: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062C5C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80062C60: mflo        $a2
    ctx->r6 = lo;
    // 0x80062C64: jal         0x800C970C
    // 0x80062C68: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x80062C68: nop

    after_1:
L_80062C6C:
    // 0x80062C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80062C70:
    // 0x80062C70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80062C74: jr          $ra
    // 0x80062C78: nop

    return;
    // 0x80062C78: nop

;}
RECOMP_FUNC void __CSPHandleNextSeqEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062C7C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80062C80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80062C84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062C88: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x80062C8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80062C90: beq         $a2, $zero, L_80062D30
    if (ctx->r6 == 0) {
        // 0x80062C94: addiu       $a1, $sp, 0x28
        ctx->r5 = ADD32(ctx->r29, 0X28);
            goto L_80062D30;
    }
    // 0x80062C94: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80062C98: jal         0x800C8264
    // 0x80062C9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    alCSeqNextEvent(rdram, ctx);
        goto after_0;
    // 0x80062C9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80062CA0: lh          $t6, 0x28($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X28);
    // 0x80062CA4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80062CA8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80062CAC: sltiu       $at, $t7, 0x14
    ctx->r1 = ctx->r15 < 0X14 ? 1 : 0;
    // 0x80062CB0: beq         $at, $zero, L_80062D30
    if (ctx->r1 == 0) {
        // 0x80062CB4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80062D30;
    }
    // 0x80062CB4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80062CB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80062CBC: addu        $at, $at, $t7
    gpr jr_addend_80062CC8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80062CC0: lw          $t7, 0x7220($at)
    ctx->r15 = ADD32(ctx->r1, 0X7220);
    // 0x80062CC4: nop

    // 0x80062CC8: jr          $t7
    // 0x80062CCC: nop

    switch (jr_addend_80062CC8 >> 2) {
        case 0: goto L_80062CD0; break;
        case 1: goto L_80062D30; break;
        case 2: goto L_80062CE8; break;
        case 3: goto L_80062D00; break;
        case 4: goto L_80062D30; break;
        case 5: goto L_80062D30; break;
        case 6: goto L_80062D30; break;
        case 7: goto L_80062D30; break;
        case 8: goto L_80062D30; break;
        case 9: goto L_80062D30; break;
        case 10: goto L_80062D30; break;
        case 11: goto L_80062D30; break;
        case 12: goto L_80062D30; break;
        case 13: goto L_80062D30; break;
        case 14: goto L_80062D30; break;
        case 15: goto L_80062D30; break;
        case 16: goto L_80062D30; break;
        case 17: goto L_80062D28; break;
        case 18: goto L_80062D28; break;
        case 19: goto L_80062D28; break;
        default: switch_error(__func__, 0x80062CC8, 0x800E7220);
    }
    // 0x80062CCC: nop

L_80062CD0:
    // 0x80062CD0: jal         0x80062D40
    // 0x80062CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __CSPHandleMIDIMsg(rdram, ctx);
        goto after_1;
    // 0x80062CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80062CD8: jal         0x80062C0C
    // 0x80062CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_2;
    // 0x80062CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80062CE0: b           L_80062D34
    // 0x80062CE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80062D34;
    // 0x80062CE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80062CE8:
    // 0x80062CE8: jal         0x80063A2C
    // 0x80062CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __CSPHandleMetaMsg(rdram, ctx);
        goto after_3;
    // 0x80062CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80062CF0: jal         0x80062C0C
    // 0x80062CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_4;
    // 0x80062CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80062CF8: b           L_80062D34
    // 0x80062CFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80062D34;
    // 0x80062CFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80062D00:
    // 0x80062D00: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80062D04: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x80062D08: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80062D0C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80062D10: sh          $t9, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r25;
    // 0x80062D14: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80062D18: jal         0x800C970C
    // 0x80062D1C: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x80062D1C: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    after_5:
    // 0x80062D20: b           L_80062D34
    // 0x80062D24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80062D34;
    // 0x80062D24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80062D28:
    // 0x80062D28: jal         0x80062C0C
    // 0x80062D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_6;
    // 0x80062D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80062D30:
    // 0x80062D30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80062D34:
    // 0x80062D34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062D38: jr          $ra
    // 0x80062D3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80062D3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void __CSPHandleMIDIMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062D40: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80062D44: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80062D48: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80062D4C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80062D50: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80062D54: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80062D58: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80062D5C: lbu         $a3, 0x8($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X8);
    // 0x80062D60: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80062D64: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x80062D68: sb          $t7, 0xCA($sp)
    MEM_B(0XCA, ctx->r29) = ctx->r15;
    // 0x80062D6C: lbu         $s3, 0xA($a1)
    ctx->r19 = MEM_BU(ctx->r5, 0XA);
    // 0x80062D70: andi        $v1, $a3, 0xF0
    ctx->r3 = ctx->r7 & 0XF0;
    // 0x80062D74: andi        $t6, $a3, 0xF
    ctx->r14 = ctx->r7 & 0XF;
    // 0x80062D78: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80062D7C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80062D80: bne         $v1, $a2, L_80062E20
    if (ctx->r3 != ctx->r6) {
        // 0x80062D84: or          $a3, $t6, $zero
        ctx->r7 = ctx->r14 | 0;
            goto L_80062E20;
    }
    // 0x80062D84: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80062D88: andi        $s1, $t7, 0xFF
    ctx->r17 = ctx->r15 & 0XFF;
    // 0x80062D8C: addiu       $at, $zero, 0x6A
    ctx->r1 = ADD32(0, 0X6A);
    // 0x80062D90: bne         $s1, $at, L_80062E00
    if (ctx->r17 != ctx->r1) {
        // 0x80062D94: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80062E00;
    }
    // 0x80062D94: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80062D98: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x80062D9C: lhu         $t8, 0x30($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X30);
    // 0x80062DA0: sllv        $t1, $t0, $s3
    ctx->r9 = S32(ctx->r8 << (ctx->r19 & 31));
    // 0x80062DA4: lw          $s0, 0x64($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X64);
    // 0x80062DA8: nor         $t2, $t1, $zero
    ctx->r10 = ~(ctx->r9 | 0);
    // 0x80062DAC: and         $t3, $t8, $t2
    ctx->r11 = ctx->r24 & ctx->r10;
    // 0x80062DB0: beq         $s0, $zero, L_80063A0C
    if (ctx->r16 == 0) {
        // 0x80062DB4: sh          $t3, 0x30($a0)
        MEM_H(0X30, ctx->r4) = ctx->r11;
            goto L_80063A0C;
    }
    // 0x80062DB4: sh          $t3, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r11;
    // 0x80062DB8: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
L_80062DBC:
    // 0x80062DBC: lbu         $t5, 0x31($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X31);
    // 0x80062DC0: nop

    // 0x80062DC4: bne         $t4, $t5, L_80062DE8
    if (ctx->r12 != ctx->r13) {
        // 0x80062DC8: nop
    
            goto L_80062DE8;
    }
    // 0x80062DC8: nop

    // 0x80062DCC: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80062DD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062DD4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80062DD8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80062DDC: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    // 0x80062DE0: jal         0x8000AB00
    // 0x80062DE4: nop

    __seqpReleaseVoice(rdram, ctx);
        goto after_0;
    // 0x80062DE4: nop

    after_0:
L_80062DE8:
    // 0x80062DE8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80062DEC: nop

    // 0x80062DF0: bne         $s0, $zero, L_80062DBC
    if (ctx->r16 != 0) {
        // 0x80062DF4: lw          $t4, 0x58($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X58);
            goto L_80062DBC;
    }
    // 0x80062DF4: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80062DF8: b           L_80063A10
    // 0x80062DFC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x80062DFC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80062E00:
    // 0x80062E00: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80062E04: bne         $s1, $at, L_80062E20
    if (ctx->r17 != ctx->r1) {
        // 0x80062E08: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80062E20;
    }
    // 0x80062E08: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80062E0C: lhu         $t0, 0x30($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X30);
    // 0x80062E10: sllv        $t1, $t9, $s3
    ctx->r9 = S32(ctx->r25 << (ctx->r19 & 31));
    // 0x80062E14: or          $t8, $t0, $t1
    ctx->r24 = ctx->r8 | ctx->r9;
    // 0x80062E18: b           L_80063A0C
    // 0x80062E1C: sh          $t8, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r24;
        goto L_80063A0C;
    // 0x80062E1C: sh          $t8, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r24;
L_80062E20:
    // 0x80062E20: lhu         $t4, 0x30($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X30);
    // 0x80062E24: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80062E28: sllv        $t3, $t2, $a3
    ctx->r11 = S32(ctx->r10 << (ctx->r7 & 31));
    // 0x80062E2C: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x80062E30: bne         $t5, $zero, L_80062E50
    if (ctx->r13 != 0) {
        // 0x80062E34: or          $s4, $a3, $zero
        ctx->r20 = ctx->r7 | 0;
            goto L_80062E50;
    }
    // 0x80062E34: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80062E38: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x80062E3C: beq         $v1, $at, L_80062E54
    if (ctx->r3 == ctx->r1) {
        // 0x80062E40: addiu       $t6, $v1, -0x80
        ctx->r14 = ADD32(ctx->r3, -0X80);
            goto L_80062E54;
    }
    // 0x80062E40: addiu       $t6, $v1, -0x80
    ctx->r14 = ADD32(ctx->r3, -0X80);
    // 0x80062E44: beq         $v1, $a2, L_80062E50
    if (ctx->r3 == ctx->r6) {
        // 0x80062E48: addiu       $at, $zero, 0xE0
        ctx->r1 = ADD32(0, 0XE0);
            goto L_80062E50;
    }
    // 0x80062E48: addiu       $at, $zero, 0xE0
    ctx->r1 = ADD32(0, 0XE0);
    // 0x80062E4C: bne         $v1, $at, L_80063A0C
    if (ctx->r3 != ctx->r1) {
        // 0x80062E50: addiu       $t6, $v1, -0x80
        ctx->r14 = ADD32(ctx->r3, -0X80);
            goto L_80063A0C;
    }
L_80062E50:
    // 0x80062E50: addiu       $t6, $v1, -0x80
    ctx->r14 = ADD32(ctx->r3, -0X80);
L_80062E54:
    // 0x80062E54: sltiu       $at, $t6, 0x61
    ctx->r1 = ctx->r14 < 0X61 ? 1 : 0;
    // 0x80062E58: beq         $at, $zero, L_80063A0C
    if (ctx->r1 == 0) {
        // 0x80062E5C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80063A0C;
    }
    // 0x80062E5C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80062E60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80062E64: addu        $at, $at, $t6
    gpr jr_addend_80062E70 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80062E68: lw          $t6, 0x7270($at)
    ctx->r14 = ADD32(ctx->r1, 0X7270);
    // 0x80062E6C: nop

    // 0x80062E70: jr          $t6
    // 0x80062E74: nop

    switch (jr_addend_80062E70 >> 2) {
        case 0: goto L_800632A8; break;
        case 1: goto L_80063A0C; break;
        case 2: goto L_80063A0C; break;
        case 3: goto L_80063A0C; break;
        case 4: goto L_80063A0C; break;
        case 5: goto L_80063A0C; break;
        case 6: goto L_80063A0C; break;
        case 7: goto L_80063A0C; break;
        case 8: goto L_80063A0C; break;
        case 9: goto L_80063A0C; break;
        case 10: goto L_80063A0C; break;
        case 11: goto L_80063A0C; break;
        case 12: goto L_80063A0C; break;
        case 13: goto L_80063A0C; break;
        case 14: goto L_80063A0C; break;
        case 15: goto L_80063A0C; break;
        case 16: goto L_80062E78; break;
        case 17: goto L_80063A0C; break;
        case 18: goto L_80063A0C; break;
        case 19: goto L_80063A0C; break;
        case 20: goto L_80063A0C; break;
        case 21: goto L_80063A0C; break;
        case 22: goto L_80063A0C; break;
        case 23: goto L_80063A0C; break;
        case 24: goto L_80063A0C; break;
        case 25: goto L_80063A0C; break;
        case 26: goto L_80063A0C; break;
        case 27: goto L_80063A0C; break;
        case 28: goto L_80063A0C; break;
        case 29: goto L_80063A0C; break;
        case 30: goto L_80063A0C; break;
        case 31: goto L_80063A0C; break;
        case 32: goto L_80063300; break;
        case 33: goto L_80063A0C; break;
        case 34: goto L_80063A0C; break;
        case 35: goto L_80063A0C; break;
        case 36: goto L_80063A0C; break;
        case 37: goto L_80063A0C; break;
        case 38: goto L_80063A0C; break;
        case 39: goto L_80063A0C; break;
        case 40: goto L_80063A0C; break;
        case 41: goto L_80063A0C; break;
        case 42: goto L_80063A0C; break;
        case 43: goto L_80063A0C; break;
        case 44: goto L_80063A0C; break;
        case 45: goto L_80063A0C; break;
        case 46: goto L_80063A0C; break;
        case 47: goto L_80063A0C; break;
        case 48: goto L_800633DC; break;
        case 49: goto L_80063A0C; break;
        case 50: goto L_80063A0C; break;
        case 51: goto L_80063A0C; break;
        case 52: goto L_80063A0C; break;
        case 53: goto L_80063A0C; break;
        case 54: goto L_80063A0C; break;
        case 55: goto L_80063A0C; break;
        case 56: goto L_80063A0C; break;
        case 57: goto L_80063A0C; break;
        case 58: goto L_80063A0C; break;
        case 59: goto L_80063A0C; break;
        case 60: goto L_80063A0C; break;
        case 61: goto L_80063A0C; break;
        case 62: goto L_80063A0C; break;
        case 63: goto L_80063A0C; break;
        case 64: goto L_80063920; break;
        case 65: goto L_80063A0C; break;
        case 66: goto L_80063A0C; break;
        case 67: goto L_80063A0C; break;
        case 68: goto L_80063A0C; break;
        case 69: goto L_80063A0C; break;
        case 70: goto L_80063A0C; break;
        case 71: goto L_80063A0C; break;
        case 72: goto L_80063A0C; break;
        case 73: goto L_80063A0C; break;
        case 74: goto L_80063A0C; break;
        case 75: goto L_80063A0C; break;
        case 76: goto L_80063A0C; break;
        case 77: goto L_80063A0C; break;
        case 78: goto L_80063A0C; break;
        case 79: goto L_80063A0C; break;
        case 80: goto L_80063364; break;
        case 81: goto L_80063A0C; break;
        case 82: goto L_80063A0C; break;
        case 83: goto L_80063A0C; break;
        case 84: goto L_80063A0C; break;
        case 85: goto L_80063A0C; break;
        case 86: goto L_80063A0C; break;
        case 87: goto L_80063A0C; break;
        case 88: goto L_80063A0C; break;
        case 89: goto L_80063A0C; break;
        case 90: goto L_80063A0C; break;
        case 91: goto L_80063A0C; break;
        case 92: goto L_80063A0C; break;
        case 93: goto L_80063A0C; break;
        case 94: goto L_80063A0C; break;
        case 95: goto L_80063A0C; break;
        case 96: goto L_80063954; break;
        default: switch_error(__func__, 0x80062E70, 0x800E7270);
    }
    // 0x80062E74: nop

L_80062E78:
    // 0x80062E78: beq         $s3, $zero, L_800632AC
    if (ctx->r19 == 0) {
        // 0x80062E7C: lbu         $a1, 0xCA($sp)
        ctx->r5 = MEM_BU(ctx->r29, 0XCA);
            goto L_800632AC;
    }
    // 0x80062E7C: lbu         $a1, 0xCA($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XCA);
    // 0x80062E80: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x80062E84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80062E88: bne         $t7, $at, L_80063A0C
    if (ctx->r15 != ctx->r1) {
        // 0x80062E8C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80063A0C;
    }
    // 0x80062E8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062E90: lbu         $a1, 0xCA($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XCA);
    // 0x80062E94: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    // 0x80062E98: sb          $a3, 0xCB($sp)
    MEM_B(0XCB, ctx->r29) = ctx->r7;
    // 0x80062E9C: jal         0x8000A8D0
    // 0x80062EA0: sw          $s0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r16;
    __lookupSoundQuick(rdram, ctx);
        goto after_1;
    // 0x80062EA0: sw          $s0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r16;
    after_1:
    // 0x80062EA4: beq         $v0, $zero, L_80063A0C
    if (ctx->r2 == 0) {
        // 0x80062EA8: sw          $v0, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r2;
            goto L_80063A0C;
    }
    // 0x80062EA8: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x80062EAC: lbu         $a3, 0xCB($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0XCB);
    // 0x80062EB0: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x80062EB4: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x80062EB8: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80062EBC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80062EC0: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80062EC4: lbu         $t1, 0x8($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X8);
    // 0x80062EC8: lbu         $a1, 0xCA($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XCA);
    // 0x80062ECC: sh          $zero, 0x96($sp)
    MEM_H(0X96, ctx->r29) = 0;
    // 0x80062ED0: sb          $zero, 0x98($sp)
    MEM_B(0X98, ctx->r29) = 0;
    // 0x80062ED4: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80062ED8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062EDC: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    // 0x80062EE0: jal         0x8000A71C
    // 0x80062EE4: sh          $t1, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r9;
    __mapVoice(rdram, ctx);
        goto after_2;
    // 0x80062EE4: sh          $t1, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r9;
    after_2:
    // 0x80062EE8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80062EEC: beq         $v0, $zero, L_80063A0C
    if (ctx->r2 == 0) {
        // 0x80062EF0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80063A0C;
    }
    // 0x80062EF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80062EF4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80062EF8: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80062EFC: lbu         $s1, 0xCA($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0XCA);
    // 0x80062F00: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x80062F04: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80062F08: jal         0x800C9A68
    // 0x80062F0C: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    alSynAllocVoice(rdram, ctx);
        goto after_3;
    // 0x80062F0C: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    after_3:
    // 0x80062F10: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80062F14: beq         $v0, $zero, L_80062F38
    if (ctx->r2 == 0) {
        // 0x80062F18: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80062F38;
    }
    // 0x80062F18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80062F1C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80062F20: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80062F24: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    // 0x80062F28: jal         0x80065CC0
    // 0x80062F2C: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    func_80065A80(rdram, ctx);
        goto after_4;
    // 0x80062F2C: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_4:
    // 0x80062F30: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80062F34: nop

L_80062F38:
    // 0x80062F38: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    // 0x80062F3C: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x80062F40: sw          $a1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r5;
    // 0x80062F44: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x80062F48: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80062F4C: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80062F50: lbu         $t4, 0xB($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XB);
    // 0x80062F54: nop

    // 0x80062F58: slti        $at, $t4, 0x40
    ctx->r1 = SIGNED(ctx->r12) < 0X40 ? 1 : 0;
    // 0x80062F5C: bne         $at, $zero, L_80062F6C
    if (ctx->r1 != 0) {
        // 0x80062F60: nop
    
            goto L_80062F6C;
    }
    // 0x80062F60: nop

    // 0x80062F64: b           L_80062F70
    // 0x80062F68: sb          $t5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r13;
        goto L_80062F70;
    // 0x80062F68: sb          $t5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r13;
L_80062F6C:
    // 0x80062F6C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_80062F70:
    // 0x80062F70: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80062F74: nop

    // 0x80062F78: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    // 0x80062F7C: lb          $t0, 0x5($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X5);
    // 0x80062F80: subu        $t7, $s1, $t6
    ctx->r15 = SUB32(ctx->r17, ctx->r14);
    // 0x80062F84: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80062F88: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80062F8C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80062F90: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80062F94: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80062F98: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80062F9C: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x80062FA0: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80062FA4: jal         0x800C9F40
    // 0x80062FA8: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    alCents2Ratio(rdram, ctx);
        goto after_5;
    // 0x80062FA8: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_5:
    // 0x80062FAC: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80062FB0: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80062FB4: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x80062FB8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80062FBC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80062FC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80062FC4: lbu         $t4, 0xC($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XC);
    // 0x80062FC8: nop

    // 0x80062FCC: sb          $t4, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r12;
    // 0x80062FD0: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80062FD4: lw          $t5, 0x1C($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C);
    // 0x80062FD8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80062FDC: nop

    // 0x80062FE0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80062FE4: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    // 0x80062FE8: addu        $t0, $t5, $t9
    ctx->r8 = ADD32(ctx->r13, ctx->r25);
    // 0x80062FEC: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
    // 0x80062FF0: lw          $t1, 0x60($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X60);
    // 0x80062FF4: nop

    // 0x80062FF8: addu        $t8, $t1, $v1
    ctx->r24 = ADD32(ctx->r9, ctx->r3);
    // 0x80062FFC: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x80063000: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x80063004: lbu         $a2, 0x4($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X4);
    // 0x80063008: nop

    // 0x8006300C: beq         $a2, $zero, L_80063080
    if (ctx->r6 == 0) {
        // 0x80063010: nop
    
            goto L_80063080;
    }
    // 0x80063010: nop

    // 0x80063014: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x80063018: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8006301C: beq         $v0, $zero, L_80063080
    if (ctx->r2 == 0) {
        // 0x80063020: addiu       $a1, $sp, 0x84
        ctx->r5 = ADD32(ctx->r29, 0X84);
            goto L_80063080;
    }
    // 0x80063020: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80063024: lbu         $t2, 0x6($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X6);
    // 0x80063028: lbu         $a3, 0x5($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X5);
    // 0x8006302C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80063030: lbu         $t3, 0x7($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X7);
    // 0x80063034: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80063038: jalr        $v0
    // 0x8006303C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x8006303C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_6:
    // 0x80063040: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80063044: beq         $v0, $zero, L_80063080
    if (ctx->r2 == 0) {
        // 0x80063048: addiu       $t4, $zero, 0x16
        ctx->r12 = ADD32(0, 0X16);
            goto L_80063080;
    }
    // 0x80063048: addiu       $t4, $zero, 0x16
    ctx->r12 = ADD32(0, 0X16);
    // 0x8006304C: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80063050: sh          $t4, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r12;
    // 0x80063054: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // 0x80063058: addiu       $a0, $s2, 0x48
    ctx->r4 = ADD32(ctx->r18, 0X48);
    // 0x8006305C: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80063060: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80063064: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80063068: jal         0x800C970C
    // 0x8006306C: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x8006306C: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    after_7:
    // 0x80063070: lbu         $t7, 0x37($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X37);
    // 0x80063074: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80063078: ori         $t5, $t7, 0x1
    ctx->r13 = ctx->r15 | 0X1;
    // 0x8006307C: sb          $t5, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r13;
L_80063080:
    // 0x80063080: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80063084: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80063088: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8006308C: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80063090: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80063094: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80063098: addiu       $t1, $s2, 0x48
    ctx->r9 = ADD32(ctx->r18, 0X48);
    // 0x8006309C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800630A0: nop

    // 0x800630A4: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800630A8: beq         $t0, $zero, L_800630F4
    if (ctx->r8 == 0) {
        // 0x800630AC: nop
    
            goto L_800630F4;
    }
    // 0x800630AC: nop

    // 0x800630B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800630B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800630B8: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800630BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800630C0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800630C4: nop

    // 0x800630C8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800630CC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800630D0: nop

    // 0x800630D4: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800630D8: bne         $t0, $zero, L_800630EC
    if (ctx->r8 != 0) {
        // 0x800630DC: nop
    
            goto L_800630EC;
    }
    // 0x800630DC: nop

    // 0x800630E0: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800630E4: b           L_80063104
    // 0x800630E8: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80063104;
    // 0x800630E8: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800630EC:
    // 0x800630EC: b           L_80063104
    // 0x800630F0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80063104;
    // 0x800630F0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800630F4:
    // 0x800630F4: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800630F8: nop

    // 0x800630FC: bltz        $t0, L_800630EC
    if (SIGNED(ctx->r8) < 0) {
        // 0x80063100: nop
    
            goto L_800630EC;
    }
    // 0x80063100: nop

L_80063104:
    // 0x80063104: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80063108: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006310C: sb          $t0, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r8;
    // 0x80063110: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x80063114: lbu         $a2, 0x8($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X8);
    // 0x80063118: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8006311C: beq         $a2, $zero, L_80063198
    if (ctx->r6 == 0) {
        // 0x80063120: sw          $t1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r9;
            goto L_80063198;
    }
    // 0x80063120: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80063124: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x80063128: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8006312C: beq         $v0, $zero, L_80063198
    if (ctx->r2 == 0) {
        // 0x80063130: addiu       $a1, $sp, 0x84
        ctx->r5 = ADD32(ctx->r29, 0X84);
            goto L_80063198;
    }
    // 0x80063130: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80063134: lbu         $t8, 0xA($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0XA);
    // 0x80063138: lbu         $a3, 0x9($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X9);
    // 0x8006313C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80063140: lbu         $t2, 0xB($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0XB);
    // 0x80063144: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80063148: jalr        $v0
    // 0x8006314C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x8006314C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_8:
    // 0x80063150: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80063154: beq         $v0, $zero, L_80063198
    if (ctx->r2 == 0) {
        // 0x80063158: addiu       $t3, $zero, 0x17
        ctx->r11 = ADD32(0, 0X17);
            goto L_80063198;
    }
    // 0x80063158: addiu       $t3, $zero, 0x17
    ctx->r11 = ADD32(0, 0X17);
    // 0x8006315C: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80063160: lbu         $t6, 0xCB($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XCB);
    // 0x80063164: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80063168: sh          $t3, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r11;
    // 0x8006316C: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // 0x80063170: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80063174: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80063178: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x8006317C: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    // 0x80063180: jal         0x800C970C
    // 0x80063184: sb          $t6, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r14;
    alEvtqPostEvent(rdram, ctx);
        goto after_9;
    // 0x80063184: sb          $t6, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r14;
    after_9:
    // 0x80063188: lbu         $t7, 0x37($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X37);
    // 0x8006318C: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80063190: ori         $t5, $t7, 0x2
    ctx->r13 = ctx->r15 | 0X2;
    // 0x80063194: sb          $t5, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r13;
L_80063198:
    // 0x80063198: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8006319C: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800631A0: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x800631A4: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x800631A8: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800631AC: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x800631B0: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800631B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800631B8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800631BC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800631C0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800631C4: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x800631C8: lbu         $s1, 0xA($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0XA);
    // 0x800631CC: jal         0x8000AAAC
    // 0x800631D0: nop

    __vsPan(rdram, ctx);
        goto after_10;
    // 0x800631D0: nop

    after_10:
    // 0x800631D4: sb          $v0, 0xA3($sp)
    MEM_B(0XA3, ctx->r29) = ctx->r2;
    // 0x800631D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800631DC: jal         0x8000A9F8
    // 0x800631E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_11;
    // 0x800631E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_11:
    // 0x800631E4: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x800631E8: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800631EC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800631F0: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x800631F4: lw          $s3, 0x0($t1)
    ctx->r19 = MEM_W(ctx->r9, 0X0);
    // 0x800631F8: lbu         $t8, 0xA3($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XA3);
    // 0x800631FC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80063200: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80063204: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80063208: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8006320C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80063210: jal         0x80065E78
    // 0x80063214: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    alSynStartVoiceParams(rdram, ctx);
        goto after_12;
    // 0x80063214: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_12:
    // 0x80063218: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8006321C: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80063220: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80063224: sh          $t2, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r10;
    // 0x80063228: sw          $t3, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r11;
    // 0x8006322C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80063230: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80063234: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x80063238: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x8006323C: sb          $t7, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r15;
    // 0x80063240: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80063244: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80063248: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x8006324C: jal         0x800C970C
    // 0x80063250: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    alEvtqPostEvent(rdram, ctx);
        goto after_13;
    // 0x80063250: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    after_13:
    // 0x80063254: lw          $v0, 0xDC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XDC);
    // 0x80063258: addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // 0x8006325C: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80063260: ori         $t8, $s4, 0x80
    ctx->r24 = ctx->r20 | 0X80;
    // 0x80063264: beq         $t1, $zero, L_80063A0C
    if (ctx->r9 == 0) {
        // 0x80063268: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80063A0C;
    }
    // 0x80063268: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006326C: lbu         $t2, 0xCA($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XCA);
    // 0x80063270: sh          $t0, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r8;
    // 0x80063274: sb          $t8, 0xB4($sp)
    MEM_B(0XB4, ctx->r29) = ctx->r24;
    // 0x80063278: sb          $zero, 0xB6($sp)
    MEM_B(0XB6, ctx->r29) = 0;
    // 0x8006327C: sb          $t2, 0xB5($sp)
    MEM_B(0XB5, ctx->r29) = ctx->r10;
    // 0x80063280: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80063284: lw          $t3, 0x24($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X24);
    // 0x80063288: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8006328C: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063290: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80063294: mflo        $a2
    ctx->r6 = lo;
    // 0x80063298: jal         0x800C970C
    // 0x8006329C: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_14;
    // 0x8006329C: nop

    after_14:
    // 0x800632A0: b           L_80063A10
    // 0x800632A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x800632A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800632A8:
    // 0x800632A8: lbu         $a1, 0xCA($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XCA);
L_800632AC:
    // 0x800632AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800632B0: jal         0x8000A84C
    // 0x800632B4: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_15;
    // 0x800632B4: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    after_15:
    // 0x800632B8: beq         $v0, $zero, L_80063A0C
    if (ctx->r2 == 0) {
        // 0x800632BC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80063A0C;
    }
    // 0x800632BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800632C0: lbu         $t7, 0x35($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X35);
    // 0x800632C4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x800632C8: bne         $s1, $t7, L_800632DC
    if (ctx->r17 != ctx->r15) {
        // 0x800632CC: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_800632DC;
    }
    // 0x800632CC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800632D0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800632D4: b           L_80063A0C
    // 0x800632D8: sb          $t4, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r12;
        goto L_80063A0C;
    // 0x800632D8: sb          $t4, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r12;
L_800632DC:
    // 0x800632DC: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x800632E0: sb          $t5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r13;
    // 0x800632E4: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800632E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800632EC: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x800632F0: jal         0x8000AB00
    // 0x800632F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    __seqpReleaseVoice(rdram, ctx);
        goto after_16;
    // 0x800632F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_16:
    // 0x800632F8: b           L_80063A10
    // 0x800632FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x800632FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063300:
    // 0x80063300: lbu         $a1, 0xCA($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XCA);
    // 0x80063304: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80063308: jal         0x8000A84C
    // 0x8006330C: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_17;
    // 0x8006330C: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    after_17:
    // 0x80063310: beq         $v0, $zero, L_80063A0C
    if (ctx->r2 == 0) {
        // 0x80063314: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80063A0C;
    }
    // 0x80063314: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80063318: sb          $s3, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r19;
    // 0x8006331C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80063320: jal         0x8000A9F8
    // 0x80063324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_18;
    // 0x80063324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_18:
    // 0x80063328: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8006332C: sra         $t0, $s1, 16
    ctx->r8 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80063330: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x80063334: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80063338: jal         0x8000AA88
    // 0x8006333C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __vsDelta(rdram, ctx);
        goto after_19;
    // 0x8006333C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80063340: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x80063344: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80063348: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8006334C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80063350: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80063354: jal         0x800C9BB0
    // 0x80063358: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_20;
    // 0x80063358: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_20:
    // 0x8006335C: b           L_80063A10
    // 0x80063360: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x80063360: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063364:
    // 0x80063364: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80063368: nop

    // 0x8006336C: beq         $s0, $zero, L_80063A10
    if (ctx->r16 == 0) {
        // 0x80063370: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80063A10;
    }
    // 0x80063370: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063374:
    // 0x80063374: lbu         $t2, 0x31($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X31);
    // 0x80063378: lbu         $t3, 0xCA($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XCA);
    // 0x8006337C: bne         $s4, $t2, L_800633C4
    if (ctx->r20 != ctx->r10) {
        // 0x80063380: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800633C4;
    }
    // 0x80063380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80063384: sb          $t3, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r11;
    // 0x80063388: jal         0x8000A9F8
    // 0x8006338C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_21;
    // 0x8006338C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_21:
    // 0x80063390: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80063394: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80063398: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x8006339C: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800633A0: jal         0x8000AA88
    // 0x800633A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __vsDelta(rdram, ctx);
        goto after_22;
    // 0x800633A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x800633A8: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800633AC: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800633B0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800633B4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800633B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800633BC: jal         0x800C9BB0
    // 0x800633C0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_23;
    // 0x800633C0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_23:
L_800633C4:
    // 0x800633C4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800633C8: nop

    // 0x800633CC: bne         $s0, $zero, L_80063374
    if (ctx->r16 != 0) {
        // 0x800633D0: nop
    
            goto L_80063374;
    }
    // 0x800633D0: nop

    // 0x800633D4: b           L_80063A10
    // 0x800633D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x800633D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800633DC:
    // 0x800633DC: lbu         $s1, 0xCA($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0XCA);
    // 0x800633E0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800633E4: beq         $s1, $at, L_800634A0
    if (ctx->r17 == ctx->r1) {
        // 0x800633E8: sll         $v1, $a3, 2
        ctx->r3 = S32(ctx->r7 << 2);
            goto L_800634A0;
    }
    // 0x800633E8: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x800633EC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800633F0: beq         $s1, $at, L_80063610
    if (ctx->r17 == ctx->r1) {
        // 0x800633F4: sll         $v1, $a3, 2
        ctx->r3 = S32(ctx->r7 << 2);
            goto L_80063610;
    }
    // 0x800633F4: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x800633F8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800633FC: beq         $s1, $at, L_8006343C
    if (ctx->r17 == ctx->r1) {
        // 0x80063400: sll         $t5, $a3, 2
        ctx->r13 = S32(ctx->r7 << 2);
            goto L_8006343C;
    }
    // 0x80063400: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x80063404: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80063408: beq         $s1, $at, L_80063760
    if (ctx->r17 == ctx->r1) {
        // 0x8006340C: sll         $t3, $a3, 2
        ctx->r11 = S32(ctx->r7 << 2);
            goto L_80063760;
    }
    // 0x8006340C: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x80063410: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80063414: beq         $s1, $at, L_80063778
    if (ctx->r17 == ctx->r1) {
        // 0x80063418: sll         $t4, $a3, 2
        ctx->r12 = S32(ctx->r7 << 2);
            goto L_80063778;
    }
    // 0x80063418: sll         $t4, $a3, 2
    ctx->r12 = S32(ctx->r7 << 2);
    // 0x8006341C: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x80063420: beq         $s1, $at, L_80063820
    if (ctx->r17 == ctx->r1) {
        // 0x80063424: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_80063820;
    }
    // 0x80063424: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80063428: addiu       $at, $zero, 0x5F
    ctx->r1 = ADD32(0, 0X5F);
    // 0x8006342C: beq         $s1, $at, L_80063878
    if (ctx->r17 == ctx->r1) {
        // 0x80063430: nop
    
            goto L_80063878;
    }
    // 0x80063430: nop

    // 0x80063434: b           L_80063A10
    // 0x80063438: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x80063438: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8006343C:
    // 0x8006343C: lw          $t4, 0x60($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X60);
    // 0x80063440: addu        $t5, $t5, $a3
    ctx->r13 = ADD32(ctx->r13, ctx->r7);
    // 0x80063444: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80063448: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x8006344C: sb          $s3, 0x7($t9)
    MEM_B(0X7, ctx->r25) = ctx->r19;
    // 0x80063450: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80063454: nop

    // 0x80063458: beq         $s0, $zero, L_80063A10
    if (ctx->r16 == 0) {
        // 0x8006345C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80063A10;
    }
    // 0x8006345C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063460:
    // 0x80063460: lbu         $t1, 0x31($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X31);
    // 0x80063464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80063468: bne         $s4, $t1, L_80063488
    if (ctx->r20 != ctx->r9) {
        // 0x8006346C: nop
    
            goto L_80063488;
    }
    // 0x8006346C: nop

    // 0x80063470: jal         0x8000AAAC
    // 0x80063474: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsPan(rdram, ctx);
        goto after_24;
    // 0x80063474: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x80063478: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8006347C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80063480: jal         0x80065D60
    // 0x80063484: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    alSynSetPan(rdram, ctx);
        goto after_25;
    // 0x80063484: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_25:
L_80063488:
    // 0x80063488: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8006348C: nop

    // 0x80063490: bne         $s0, $zero, L_80063460
    if (ctx->r16 != 0) {
        // 0x80063494: nop
    
            goto L_80063460;
    }
    // 0x80063494: nop

    // 0x80063498: b           L_80063A10
    // 0x8006349C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x8006349C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800634A0:
    // 0x800634A0: lw          $t0, 0x60($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X60);
    // 0x800634A4: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800634A8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800634AC: addu        $t8, $t0, $v1
    ctx->r24 = ADD32(ctx->r8, ctx->r3);
    // 0x800634B0: sb          $s3, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r19;
    // 0x800634B4: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x800634B8: mtc1        $s3, $f6
    ctx->f6.u32l = ctx->r19;
    // 0x800634BC: addu        $v0, $t2, $v1
    ctx->r2 = ADD32(ctx->r10, ctx->r3);
    // 0x800634C0: lbu         $t3, 0x10($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X10);
    // 0x800634C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800634C8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800634CC: bgez        $t3, L_800634E0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800634D0: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800634E0;
    }
    // 0x800634D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800634D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800634D8: nop

    // 0x800634DC: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800634E0:
    // 0x800634E0: bgez        $s3, L_800634F8
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800634E4: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800634F8;
    }
    // 0x800634E4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800634E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800634EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800634F0: nop

    // 0x800634F4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800634F8:
    // 0x800634F8: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800634FC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80063500: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80063504: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80063508: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8006350C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80063510: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80063514: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80063518: nop

    // 0x8006351C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80063520: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80063524: nop

    // 0x80063528: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8006352C: beq         $t7, $zero, L_80063578
    if (ctx->r15 == 0) {
        // 0x80063530: nop
    
            goto L_80063578;
    }
    // 0x80063530: nop

    // 0x80063534: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80063538: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006353C: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80063540: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80063544: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80063548: nop

    // 0x8006354C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80063550: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80063554: nop

    // 0x80063558: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8006355C: bne         $t7, $zero, L_80063570
    if (ctx->r15 != 0) {
        // 0x80063560: nop
    
            goto L_80063570;
    }
    // 0x80063560: nop

    // 0x80063564: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80063568: b           L_80063588
    // 0x8006356C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80063588;
    // 0x8006356C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80063570:
    // 0x80063570: b           L_80063588
    // 0x80063574: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80063588;
    // 0x80063574: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80063578:
    // 0x80063578: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8006357C: nop

    // 0x80063580: bltz        $t7, L_80063570
    if (SIGNED(ctx->r15) < 0) {
        // 0x80063584: nop
    
            goto L_80063570;
    }
    // 0x80063584: nop

L_80063588:
    // 0x80063588: sb          $t7, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r15;
    // 0x8006358C: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80063590: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80063594: beq         $s0, $zero, L_80063A10
    if (ctx->r16 == 0) {
        // 0x80063598: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80063A10;
    }
    // 0x80063598: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8006359C:
    // 0x8006359C: lbu         $t4, 0x31($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X31);
    // 0x800635A0: nop

    // 0x800635A4: bne         $s4, $t4, L_800635F8
    if (ctx->r20 != ctx->r12) {
        // 0x800635A8: nop
    
            goto L_800635F8;
    }
    // 0x800635A8: nop

    // 0x800635AC: lbu         $t5, 0x34($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X34);
    // 0x800635B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800635B4: beq         $t5, $at, L_800635F8
    if (ctx->r13 == ctx->r1) {
        // 0x800635B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800635F8;
    }
    // 0x800635B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800635BC: jal         0x8000A9F8
    // 0x800635C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_26;
    // 0x800635C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_26:
    // 0x800635C4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800635C8: sra         $t9, $s1, 16
    ctx->r25 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800635CC: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x800635D0: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800635D4: jal         0x8000AA88
    // 0x800635D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __vsDelta(rdram, ctx);
        goto after_27;
    // 0x800635D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x800635DC: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800635E0: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800635E4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800635E8: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800635EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800635F0: jal         0x800C9BB0
    // 0x800635F4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_28;
    // 0x800635F4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_28:
L_800635F8:
    // 0x800635F8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800635FC: nop

    // 0x80063600: bne         $s0, $zero, L_8006359C
    if (ctx->r16 != 0) {
        // 0x80063604: nop
    
            goto L_8006359C;
    }
    // 0x80063604: nop

    // 0x80063608: b           L_80063A10
    // 0x8006360C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x8006360C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063610:
    // 0x80063610: lw          $t0, 0x60($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X60);
    // 0x80063614: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80063618: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006361C: addu        $t8, $t0, $v1
    ctx->r24 = ADD32(ctx->r8, ctx->r3);
    // 0x80063620: sb          $s3, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r19;
    // 0x80063624: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x80063628: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8006362C: addu        $v0, $t2, $v1
    ctx->r2 = ADD32(ctx->r10, ctx->r3);
    // 0x80063630: lbu         $t3, 0x10($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X10);
    // 0x80063634: lbu         $t6, 0x11($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X11);
    // 0x80063638: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006363C: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063640: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80063644: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80063648: mflo        $t7
    ctx->r15 = lo;
    // 0x8006364C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80063650: nop

    // 0x80063654: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063658: nop

    // 0x8006365C: div.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80063660: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80063664: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80063668: nop

    // 0x8006366C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80063670: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80063674: nop

    // 0x80063678: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8006367C: beq         $t5, $zero, L_800636C8
    if (ctx->r13 == 0) {
        // 0x80063680: nop
    
            goto L_800636C8;
    }
    // 0x80063680: nop

    // 0x80063684: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80063688: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8006368C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80063690: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80063694: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80063698: nop

    // 0x8006369C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800636A0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800636A4: nop

    // 0x800636A8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800636AC: bne         $t5, $zero, L_800636C0
    if (ctx->r13 != 0) {
        // 0x800636B0: nop
    
            goto L_800636C0;
    }
    // 0x800636B0: nop

    // 0x800636B4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800636B8: b           L_800636D8
    // 0x800636BC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800636D8;
    // 0x800636BC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800636C0:
    // 0x800636C0: b           L_800636D8
    // 0x800636C4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800636D8;
    // 0x800636C4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_800636C8:
    // 0x800636C8: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800636CC: nop

    // 0x800636D0: bltz        $t5, L_800636C0
    if (SIGNED(ctx->r13) < 0) {
        // 0x800636D4: nop
    
            goto L_800636C0;
    }
    // 0x800636D4: nop

L_800636D8:
    // 0x800636D8: sb          $t5, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r13;
    // 0x800636DC: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800636E0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800636E4: beq         $s0, $zero, L_80063A10
    if (ctx->r16 == 0) {
        // 0x800636E8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80063A10;
    }
    // 0x800636E8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800636EC:
    // 0x800636EC: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    // 0x800636F0: nop

    // 0x800636F4: bne         $s4, $t9, L_80063748
    if (ctx->r20 != ctx->r25) {
        // 0x800636F8: nop
    
            goto L_80063748;
    }
    // 0x800636F8: nop

    // 0x800636FC: lbu         $t1, 0x34($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X34);
    // 0x80063700: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80063704: beq         $t1, $at, L_80063748
    if (ctx->r9 == ctx->r1) {
        // 0x80063708: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80063748;
    }
    // 0x80063708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006370C: jal         0x8000A9F8
    // 0x80063710: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_29;
    // 0x80063710: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_29:
    // 0x80063714: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80063718: sra         $t0, $s1, 16
    ctx->r8 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8006371C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x80063720: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80063724: jal         0x8000AA88
    // 0x80063728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __vsDelta(rdram, ctx);
        goto after_30;
    // 0x80063728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8006372C: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x80063730: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80063734: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80063738: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8006373C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80063740: jal         0x800C9BB0
    // 0x80063744: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_31;
    // 0x80063744: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_31:
L_80063748:
    // 0x80063748: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8006374C: nop

    // 0x80063750: bne         $s0, $zero, L_800636EC
    if (ctx->r16 != 0) {
        // 0x80063754: nop
    
            goto L_800636EC;
    }
    // 0x80063754: nop

    // 0x80063758: b           L_80063A10
    // 0x8006375C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x8006375C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063760:
    // 0x80063760: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x80063764: addu        $t3, $t3, $a3
    ctx->r11 = ADD32(ctx->r11, ctx->r7);
    // 0x80063768: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8006376C: addu        $t6, $t2, $t3
    ctx->r14 = ADD32(ctx->r10, ctx->r11);
    // 0x80063770: b           L_80063A0C
    // 0x80063774: sb          $s3, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r19;
        goto L_80063A0C;
    // 0x80063774: sb          $s3, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r19;
L_80063778:
    // 0x80063778: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x8006377C: addu        $t4, $t4, $a3
    ctx->r12 = ADD32(ctx->r12, ctx->r7);
    // 0x80063780: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80063784: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x80063788: sb          $s3, 0xB($t5)
    MEM_B(0XB, ctx->r13) = ctx->r19;
    // 0x8006378C: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80063790: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80063794: beq         $s0, $zero, L_80063A10
    if (ctx->r16 == 0) {
        // 0x80063798: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80063A10;
    }
    // 0x80063798: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8006379C:
    // 0x8006379C: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    // 0x800637A0: nop

    // 0x800637A4: bne         $s4, $t9, L_80063808
    if (ctx->r20 != ctx->r25) {
        // 0x800637A8: nop
    
            goto L_80063808;
    }
    // 0x800637A8: nop

    // 0x800637AC: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x800637B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800637B4: beq         $v0, $at, L_80063808
    if (ctx->r2 == ctx->r1) {
        // 0x800637B8: slti        $at, $s3, 0x40
        ctx->r1 = SIGNED(ctx->r19) < 0X40 ? 1 : 0;
            goto L_80063808;
    }
    // 0x800637B8: slti        $at, $s3, 0x40
    ctx->r1 = SIGNED(ctx->r19) < 0X40 ? 1 : 0;
    // 0x800637BC: bne         $at, $zero, L_800637D4
    if (ctx->r1 != 0) {
        // 0x800637C0: nop
    
            goto L_800637D4;
    }
    // 0x800637C0: nop

    // 0x800637C4: bne         $v0, $zero, L_80063808
    if (ctx->r2 != 0) {
        // 0x800637C8: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_80063808;
    }
    // 0x800637C8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800637CC: b           L_80063808
    // 0x800637D0: sb          $t1, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r9;
        goto L_80063808;
    // 0x800637D0: sb          $t1, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r9;
L_800637D4:
    // 0x800637D4: bne         $s1, $v0, L_800637E4
    if (ctx->r17 != ctx->r2) {
        // 0x800637D8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800637E4;
    }
    // 0x800637D8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800637DC: b           L_80063808
    // 0x800637E0: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
        goto L_80063808;
    // 0x800637E0: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_800637E4:
    // 0x800637E4: bne         $v0, $at, L_80063808
    if (ctx->r2 != ctx->r1) {
        // 0x800637E8: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_80063808;
    }
    // 0x800637E8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800637EC: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x800637F0: sb          $t0, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r8;
    // 0x800637F4: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x800637F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800637FC: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x80063800: jal         0x8000AB00
    // 0x80063804: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    __seqpReleaseVoice(rdram, ctx);
        goto after_32;
    // 0x80063804: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_32:
L_80063808:
    // 0x80063808: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8006380C: nop

    // 0x80063810: bne         $s0, $zero, L_8006379C
    if (ctx->r16 != 0) {
        // 0x80063814: nop
    
            goto L_8006379C;
    }
    // 0x80063814: nop

    // 0x80063818: b           L_80063A10
    // 0x8006381C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x8006381C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063820:
    // 0x80063820: lw          $t3, 0x60($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X60);
    // 0x80063824: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x80063828: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006382C: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80063830: sb          $s3, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r19;
    // 0x80063834: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80063838: nop

    // 0x8006383C: beq         $s0, $zero, L_80063A10
    if (ctx->r16 == 0) {
        // 0x80063840: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80063A10;
    }
    // 0x80063840: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063844:
    // 0x80063844: lbu         $t4, 0x31($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X31);
    // 0x80063848: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006384C: bne         $s4, $t4, L_80063860
    if (ctx->r20 != ctx->r12) {
        // 0x80063850: nop
    
            goto L_80063860;
    }
    // 0x80063850: nop

    // 0x80063854: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80063858: jal         0x800C9D70
    // 0x8006385C: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_33;
    // 0x8006385C: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    after_33:
L_80063860:
    // 0x80063860: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80063864: nop

    // 0x80063868: bne         $s0, $zero, L_80063844
    if (ctx->r16 != 0) {
        // 0x8006386C: nop
    
            goto L_80063844;
    }
    // 0x8006386C: nop

    // 0x80063870: b           L_80063A10
    // 0x80063874: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x80063874: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063878:
    // 0x80063878: lbu         $t5, 0x34($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X34);
    // 0x8006387C: sb          $s3, 0x36($s2)
    MEM_B(0X36, ctx->r18) = ctx->r19;
    // 0x80063880: blez        $t5, L_80063A0C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80063884: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80063A0C;
    }
    // 0x80063884: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80063888: or          $s4, $s3, $zero
    ctx->r20 = ctx->r19 | 0;
    // 0x8006388C: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
L_80063890:
    // 0x80063890: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x80063894: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80063898: nop

    // 0x8006389C: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x800638A0: lbu         $t0, 0xA($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XA);
    // 0x800638A4: nop

    // 0x800638A8: slt         $at, $t0, $s4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800638AC: beq         $at, $zero, L_800638F8
    if (ctx->r1 == 0) {
        // 0x800638B0: lw          $t2, 0x54($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X54);
            goto L_800638F8;
    }
    // 0x800638B0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800638B4: sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
    // 0x800638B8: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800638BC: nop

    // 0x800638C0: beq         $s0, $zero, L_800638F8
    if (ctx->r16 == 0) {
        // 0x800638C4: lw          $t2, 0x54($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X54);
            goto L_800638F8;
    }
    // 0x800638C4: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
L_800638C8:
    // 0x800638C8: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
    // 0x800638CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800638D0: bne         $s1, $t8, L_800638E4
    if (ctx->r17 != ctx->r24) {
        // 0x800638D4: nop
    
            goto L_800638E4;
    }
    // 0x800638D4: nop

    // 0x800638D8: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800638DC: jal         0x800C9D70
    // 0x800638E0: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_34;
    // 0x800638E0: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    after_34:
L_800638E4:
    // 0x800638E4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800638E8: nop

    // 0x800638EC: bne         $s0, $zero, L_800638C8
    if (ctx->r16 != 0) {
        // 0x800638F0: nop
    
            goto L_800638C8;
    }
    // 0x800638F0: nop

    // 0x800638F4: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
L_800638F8:
    // 0x800638F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800638FC: addiu       $t3, $t2, 0x14
    ctx->r11 = ADD32(ctx->r10, 0X14);
    // 0x80063900: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80063904: lbu         $t6, 0x34($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X34);
    // 0x80063908: nop

    // 0x8006390C: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80063910: bne         $at, $zero, L_80063890
    if (ctx->r1 != 0) {
        // 0x80063914: nop
    
            goto L_80063890;
    }
    // 0x80063914: nop

    // 0x80063918: b           L_80063A10
    // 0x8006391C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x8006391C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063920:
    // 0x80063920: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x80063924: lbu         $t7, 0xCA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XCA);
    // 0x80063928: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8006392C: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x80063930: slt         $at, $t7, $t4
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80063934: beq         $at, $zero, L_80063A0C
    if (ctx->r1 == 0) {
        // 0x80063938: addu        $t9, $v0, $t5
        ctx->r25 = ADD32(ctx->r2, ctx->r13);
            goto L_80063A0C;
    }
    // 0x80063938: addu        $t9, $v0, $t5
    ctx->r25 = ADD32(ctx->r2, ctx->r13);
    // 0x8006393C: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    // 0x80063940: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80063944: jal         0x8000AD98
    // 0x80063948: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    __setInstChanState(rdram, ctx);
        goto after_35;
    // 0x80063948: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_35:
    // 0x8006394C: b           L_80063A10
    // 0x80063950: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80063A10;
    // 0x80063950: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063954:
    // 0x80063954: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x80063958: lw          $t3, 0x60($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X60);
    // 0x8006395C: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80063960: lbu         $t0, 0xCA($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XCA);
    // 0x80063964: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80063968: sll         $t1, $s3, 7
    ctx->r9 = S32(ctx->r19 << 7);
    // 0x8006396C: addu        $t6, $t3, $v1
    ctx->r14 = ADD32(ctx->r11, ctx->r3);
    // 0x80063970: lh          $t4, 0x4($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X4);
    // 0x80063974: addu        $t8, $t1, $t0
    ctx->r24 = ADD32(ctx->r9, ctx->r8);
    // 0x80063978: addiu       $t2, $t8, -0x2000
    ctx->r10 = ADD32(ctx->r24, -0X2000);
    // 0x8006397C: multu       $t4, $t2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063980: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80063984: mflo        $a0
    ctx->r4 = lo;
    // 0x80063988: bgez        $a0, L_80063998
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006398C: sra         $t7, $a0, 13
        ctx->r15 = S32(SIGNED(ctx->r4) >> 13);
            goto L_80063998;
    }
    // 0x8006398C: sra         $t7, $a0, 13
    ctx->r15 = S32(SIGNED(ctx->r4) >> 13);
    // 0x80063990: addiu       $at, $a0, 0x1FFF
    ctx->r1 = ADD32(ctx->r4, 0X1FFF);
    // 0x80063994: sra         $t7, $at, 13
    ctx->r15 = S32(SIGNED(ctx->r1) >> 13);
L_80063998:
    // 0x80063998: jal         0x800C9F40
    // 0x8006399C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    alCents2Ratio(rdram, ctx);
        goto after_36;
    // 0x8006399C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_36:
    // 0x800639A0: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x800639A4: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800639A8: lw          $t5, 0x60($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X60);
    // 0x800639AC: nop

    // 0x800639B0: addu        $t9, $t5, $v1
    ctx->r25 = ADD32(ctx->r13, ctx->r3);
    // 0x800639B4: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x800639B8: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800639BC: nop

    // 0x800639C0: beq         $s0, $zero, L_80063A10
    if (ctx->r16 == 0) {
        // 0x800639C4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80063A10;
    }
    // 0x800639C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800639C8:
    // 0x800639C8: lbu         $t1, 0x31($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X31);
    // 0x800639CC: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800639D0: bne         $s4, $t1, L_800639FC
    if (ctx->r20 != ctx->r9) {
        // 0x800639D4: nop
    
            goto L_800639FC;
    }
    // 0x800639D4: nop

    // 0x800639D8: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800639DC: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800639E0: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800639E4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800639E8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800639EC: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800639F0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800639F4: jal         0x800C9CE0
    // 0x800639F8: nop

    alSynSetPitch(rdram, ctx);
        goto after_37;
    // 0x800639F8: nop

    after_37:
L_800639FC:
    // 0x800639FC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80063A00: nop

    // 0x80063A04: bne         $s0, $zero, L_800639C8
    if (ctx->r16 != 0) {
        // 0x80063A08: nop
    
            goto L_800639C8;
    }
    // 0x80063A08: nop

L_80063A0C:
    // 0x80063A0C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063A10:
    // 0x80063A10: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80063A14: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80063A18: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80063A1C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80063A20: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80063A24: jr          $ra
    // 0x80063A28: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80063A28: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void __CSPHandleMetaMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063A2C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80063A30: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80063A34: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80063A38: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80063A3C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80063A40: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80063A44: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80063A48: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80063A4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80063A50: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80063A54: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80063A58: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80063A5C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80063A60: bne         $t6, $at, L_80063B9C
    if (ctx->r14 != ctx->r1) {
        // 0x80063A64: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80063B9C;
    }
    // 0x80063A64: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80063A68: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80063A6C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80063A70: bne         $t7, $at, L_80063B9C
    if (ctx->r15 != ctx->r1) {
        // 0x80063A74: addiu       $v0, $a1, 0x4
        ctx->r2 = ADD32(ctx->r5, 0X4);
            goto L_80063B9C;
    }
    // 0x80063A74: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x80063A78: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x80063A7C: lbu         $t0, 0x8($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X8);
    // 0x80063A80: lbu         $t3, 0x9($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X9);
    // 0x80063A84: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80063A88: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x80063A8C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80063A90: or          $v1, $t2, $t3
    ctx->r3 = ctx->r10 | ctx->r11;
    // 0x80063A94: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80063A98: lw          $s6, 0x24($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X24);
    // 0x80063A9C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80063AA0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80063AA4: jal         0x80063C74
    // 0x80063AA8: nop

    __setUsptFromTempo(rdram, ctx);
        goto after_0;
    // 0x80063AA8: nop

    after_0:
    // 0x80063AAC: lw          $s0, 0x50($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X50);
    // 0x80063AB0: nop

    // 0x80063AB4: beq         $s0, $zero, L_80063B2C
    if (ctx->r16 == 0) {
        // 0x80063AB8: nop
    
            goto L_80063B2C;
    }
    // 0x80063AB8: nop

    // 0x80063ABC: addiu       $s4, $zero, 0x15
    ctx->r20 = ADD32(0, 0X15);
L_80063AC0:
    // 0x80063AC0: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x80063AC4: lh          $t5, 0xC($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XC);
    // 0x80063AC8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80063ACC: bne         $s4, $t5, L_80063B24
    if (ctx->r20 != ctx->r13) {
        // 0x80063AD0: addu        $s2, $s2, $t4
        ctx->r18 = ADD32(ctx->r18, ctx->r12);
            goto L_80063B24;
    }
    // 0x80063AD0: addu        $s2, $s2, $t4
    ctx->r18 = ADD32(ctx->r18, ctx->r12);
    // 0x80063AD4: jal         0x800C8CC0
    // 0x80063AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x80063AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80063ADC: beq         $s3, $zero, L_80063AF8
    if (ctx->r19 == 0) {
        // 0x80063AE0: nop
    
            goto L_80063AF8;
    }
    // 0x80063AE0: nop

    // 0x80063AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80063AE8: jal         0x800C8CF0
    // 0x80063AEC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x80063AEC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x80063AF0: b           L_80063B04
    // 0x80063AF4: nop

        goto L_80063B04;
    // 0x80063AF4: nop

L_80063AF8:
    // 0x80063AF8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80063AFC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80063B00: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
L_80063B04:
    // 0x80063B04: beq         $s1, $zero, L_80063B20
    if (ctx->r17 == 0) {
        // 0x80063B08: or          $v1, $s2, $zero
        ctx->r3 = ctx->r18 | 0;
            goto L_80063B20;
    }
    // 0x80063B08: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x80063B0C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80063B10: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x80063B14: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x80063B18: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80063B1C: sw          $t7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r15;
L_80063B20:
    // 0x80063B20: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
L_80063B24:
    // 0x80063B24: bne         $s1, $zero, L_80063AC0
    if (ctx->r17 != 0) {
        // 0x80063B28: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80063AC0;
    }
    // 0x80063B28: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80063B2C:
    // 0x80063B2C: beq         $s3, $zero, L_80063B9C
    if (ctx->r19 == 0) {
        // 0x80063B30: or          $s0, $s3, $zero
        ctx->r16 = ctx->r19 | 0;
            goto L_80063B9C;
    }
    // 0x80063B30: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80063B34: addiu       $s2, $s5, 0x48
    ctx->r18 = ADD32(ctx->r21, 0X48);
L_80063B38:
    // 0x80063B38: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80063B3C: lw          $t0, 0x24($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X24);
    // 0x80063B40: div         $zero, $t8, $s6
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r22)));
    // 0x80063B44: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80063B48: bne         $s6, $zero, L_80063B54
    if (ctx->r22 != 0) {
        // 0x80063B4C: nop
    
            goto L_80063B54;
    }
    // 0x80063B4C: nop

    // 0x80063B50: break       7
    do_break(2147892048);
L_80063B54:
    // 0x80063B54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80063B58: bne         $s6, $at, L_80063B6C
    if (ctx->r22 != ctx->r1) {
        // 0x80063B5C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80063B6C;
    }
    // 0x80063B5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80063B60: bne         $t8, $at, L_80063B6C
    if (ctx->r24 != ctx->r1) {
        // 0x80063B64: nop
    
            goto L_80063B6C;
    }
    // 0x80063B64: nop

    // 0x80063B68: break       6
    do_break(2147892072);
L_80063B6C:
    // 0x80063B6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80063B70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80063B74: mflo        $v0
    ctx->r2 = lo;
    // 0x80063B78: nop

    // 0x80063B7C: nop

    // 0x80063B80: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063B84: mflo        $t9
    ctx->r25 = lo;
    // 0x80063B88: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
    // 0x80063B8C: jal         0x80063BC4
    // 0x80063B90: nop

    __CSPRepostEvent(rdram, ctx);
        goto after_3;
    // 0x80063B90: nop

    after_3:
    // 0x80063B94: bne         $s1, $zero, L_80063B38
    if (ctx->r17 != 0) {
        // 0x80063B98: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80063B38;
    }
    // 0x80063B98: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80063B9C:
    // 0x80063B9C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80063BA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80063BA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80063BA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80063BAC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80063BB0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80063BB4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80063BB8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80063BBC: jr          $ra
    // 0x80063BC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80063BC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void __CSPRepostEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063BC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80063BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063BCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80063BD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80063BD4: jal         0x800C9F90
    // 0x80063BD8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80063BD8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80063BDC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80063BE0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80063BE4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80063BE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80063BEC: beq         $v1, $at, L_80063C58
    if (ctx->r3 == ctx->r1) {
        // 0x80063BF0: addiu       $a1, $v1, 0x8
        ctx->r5 = ADD32(ctx->r3, 0X8);
            goto L_80063C58;
    }
    // 0x80063BF0: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
L_80063BF4:
    // 0x80063BF4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80063BF8: nop

    // 0x80063BFC: bne         $a0, $zero, L_80063C14
    if (ctx->r4 != 0) {
        // 0x80063C00: nop
    
            goto L_80063C14;
    }
    // 0x80063C00: nop

    // 0x80063C04: jal         0x800C8CF0
    // 0x80063C08: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x80063C08: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80063C0C: b           L_80063C5C
    // 0x80063C10: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_80063C5C;
    // 0x80063C10: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80063C14:
    // 0x80063C14: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x80063C18: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80063C1C: nop

    // 0x80063C20: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80063C24: beq         $at, $zero, L_80063C44
    if (ctx->r1 == 0) {
        // 0x80063C28: subu        $t7, $v0, $v1
        ctx->r15 = SUB32(ctx->r2, ctx->r3);
            goto L_80063C44;
    }
    // 0x80063C28: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x80063C2C: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x80063C30: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x80063C34: jal         0x800C8CF0
    // 0x80063C38: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x80063C38: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x80063C3C: b           L_80063C5C
    // 0x80063C40: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_80063C5C;
    // 0x80063C40: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80063C44:
    // 0x80063C44: sw          $t7, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r15;
    // 0x80063C48: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x80063C4C: nop

    // 0x80063C50: bne         $a1, $zero, L_80063BF4
    if (ctx->r5 != 0) {
        // 0x80063C54: nop
    
            goto L_80063BF4;
    }
    // 0x80063C54: nop

L_80063C58:
    // 0x80063C58: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80063C5C:
    // 0x80063C5C: jal         0x800C9F90
    // 0x80063C60: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x80063C60: nop

    after_3:
    // 0x80063C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063C68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80063C6C: jr          $ra
    // 0x80063C70: nop

    return;
    // 0x80063C70: nop

;}
RECOMP_FUNC void __setUsptFromTempo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C74: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80063C78: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80063C7C: beq         $v0, $zero, L_80063CBC
    if (ctx->r2 == 0) {
        // 0x80063C80: addiu       $t8, $zero, 0x1E8
        ctx->r24 = ADD32(0, 0X1E8);
            goto L_80063CBC;
    }
    // 0x80063C80: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x80063C84: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80063C88: nop

    // 0x80063C8C: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80063C90: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80063C94: nop

    // 0x80063C98: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80063C9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80063CA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80063CA4: nop

    // 0x80063CA8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80063CAC: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80063CB0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80063CB4: jr          $ra
    // 0x80063CB8: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    return;
    // 0x80063CB8: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_80063CBC:
    // 0x80063CBC: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x80063CC0: jr          $ra
    // 0x80063CC4: nop

    return;
    // 0x80063CC4: nop

    // 0x80063CC8: nop

    // 0x80063CCC: nop

;}
RECOMP_FUNC void func_80063A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063CD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063CD8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063CDC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063CE0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80063CE4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80063CE8: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80063CEC: addiu       $t8, $zero, 0x5F
    ctx->r24 = ADD32(0, 0X5F);
    // 0x80063CF0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80063CF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80063CF8: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80063CFC: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80063D00: sb          $a3, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r7;
    // 0x80063D04: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063D08: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80063D0C: jal         0x800C970C
    // 0x80063D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80063D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80063D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063D18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063D1C: jr          $ra
    // 0x80063D20: nop

    return;
    // 0x80063D20: nop

    // 0x80063D24: nop

    // 0x80063D28: nop

    // 0x80063D2C: nop

;}
RECOMP_FUNC void alSeqChOff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063D30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063D38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063D3C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063D40: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80063D44: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80063D48: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80063D4C: addiu       $t8, $zero, 0x6A
    ctx->r24 = ADD32(0, 0X6A);
    // 0x80063D50: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80063D54: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80063D58: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80063D5C: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80063D60: sb          $a3, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r7;
    // 0x80063D64: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063D68: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80063D6C: jal         0x800C970C
    // 0x80063D70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80063D70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80063D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063D78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063D7C: jr          $ra
    // 0x80063D80: nop

    return;
    // 0x80063D80: nop

;}
RECOMP_FUNC void alSeqChOn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063D84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063D88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063D8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063D90: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063D94: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80063D98: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80063D9C: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80063DA0: addiu       $t8, $zero, 0x6C
    ctx->r24 = ADD32(0, 0X6C);
    // 0x80063DA4: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80063DA8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80063DAC: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80063DB0: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80063DB4: sb          $a3, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r7;
    // 0x80063DB8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063DBC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80063DC0: jal         0x800C970C
    // 0x80063DC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80063DC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80063DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063DCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063DD0: jr          $ra
    // 0x80063DD4: nop

    return;
    // 0x80063DD4: nop

    // 0x80063DD8: nop

    // 0x80063DDC: nop

;}
RECOMP_FUNC void alCSPSetFadeIn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063DE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063DE4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80063DE8: lbu         $t9, 0x33($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X33);
    // 0x80063DEC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80063DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063DF4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063DF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063DFC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80063E00: ori         $t7, $a3, 0xB0
    ctx->r15 = ctx->r7 | 0XB0;
    // 0x80063E04: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80063E08: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80063E0C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80063E10: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80063E14: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80063E18: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063E1C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80063E20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80063E24: jal         0x800C970C
    // 0x80063E28: sb          $t9, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r25;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80063E28: sb          $t9, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r25;
    after_0:
    // 0x80063E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063E30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063E34: jr          $ra
    // 0x80063E38: nop

    return;
    // 0x80063E38: nop

    // 0x80063E3C: nop

;}
RECOMP_FUNC void alCSPGetFadeIn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E40: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80063E44: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80063E48: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80063E4C: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x80063E50: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80063E54: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80063E58: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80063E5C: lbu         $v0, 0x10($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X10);
    // 0x80063E60: jr          $ra
    // 0x80063E64: nop

    return;
    // 0x80063E64: nop

    // 0x80063E68: nop

    // 0x80063E6C: nop

;}
RECOMP_FUNC void alFxPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063E70: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80063E74: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80063E78: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80063E7C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80063E80: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80063E84: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80063E88: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80063E8C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80063E90: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80063E94: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80063E98: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80063E9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80063EA0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80063EA4: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80063EA8: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x80063EAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80063EB0: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80063EB4: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80063EB8: jalr        $t9
    // 0x80063EBC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80063EBC: nop

    after_0:
    // 0x80063EC0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80063EC4: lbu         $t7, -0x2BE0($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2BE0);
    // 0x80063EC8: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x80063ECC: bne         $t7, $zero, L_80063EDC
    if (ctx->r15 != 0) {
        // 0x80063ED0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80063EDC;
    }
    // 0x80063ED0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80063ED4: b           L_800641A8
    // 0x80063ED8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800641A8;
    // 0x80063ED8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80063EDC:
    // 0x80063EDC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80063EE0: sll         $s1, $s6, 1
    ctx->r17 = S32(ctx->r22 << 1);
    // 0x80063EE4: andi        $t3, $s1, 0xFFFF
    ctx->r11 = ctx->r17 & 0XFFFF;
    // 0x80063EE8: addiu       $t0, $s0, 0x8
    ctx->r8 = ADD32(ctx->r16, 0X8);
    // 0x80063EEC: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x80063EF0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80063EF4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80063EF8: lui         $t4, 0xC00
    ctx->r12 = S32(0XC00 << 16);
    // 0x80063EFC: lui         $t5, 0x6C0
    ctx->r13 = S32(0X6C0 << 16);
    // 0x80063F00: ori         $t5, $t5, 0x6C0
    ctx->r13 = ctx->r13 | 0X6C0;
    // 0x80063F04: ori         $t4, $t4, 0xDA83
    ctx->r12 = ctx->r12 | 0XDA83;
    // 0x80063F08: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80063F0C: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x80063F10: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80063F14: lui         $t6, 0xC00
    ctx->r14 = S32(0XC00 << 16);
    // 0x80063F18: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x80063F1C: ori         $t9, $t9, 0x6C0
    ctx->r25 = ctx->r25 | 0X6C0;
    // 0x80063F20: ori         $t6, $t6, 0x5A82
    ctx->r14 = ctx->r14 | 0X5A82;
    // 0x80063F24: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80063F28: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80063F2C: lw          $a1, 0x18($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X18);
    // 0x80063F30: addiu       $s0, $t1, 0x8
    ctx->r16 = ADD32(ctx->r9, 0X8);
    // 0x80063F34: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80063F38: addiu       $s2, $zero, 0x140
    ctx->r18 = ADD32(0, 0X140);
    // 0x80063F3C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80063F40: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80063F44: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80063F48: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    // 0x80063F4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80063F50: addiu       $a2, $zero, 0x6C0
    ctx->r6 = ADD32(0, 0X6C0);
    // 0x80063F54: jal         0x80064878
    // 0x80063F58: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    _saveBuffer(rdram, ctx);
        goto after_1;
    // 0x80063F58: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_1:
    // 0x80063F5C: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x80063F60: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x80063F64: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x80063F68: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80063F6C: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80063F70: lbu         $t8, 0x24($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X24);
    // 0x80063F74: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80063F78: blez        $t8, L_80064154
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80063F7C: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_80064154;
    }
    // 0x80063F7C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80063F80: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x80063F84: nop

L_80063F88:
    // 0x80063F88: sll         $t5, $s7, 2
    ctx->r13 = S32(ctx->r23 << 2);
    // 0x80063F8C: lw          $t4, 0x20($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X20);
    // 0x80063F90: addu        $t5, $t5, $s7
    ctx->r13 = ADD32(ctx->r13, ctx->r23);
    // 0x80063F94: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80063F98: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x80063F9C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80063FA0: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80063FA4: negu        $t9, $t6
    ctx->r25 = SUB32(0, ctx->r14);
    // 0x80063FA8: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80063FAC: negu        $t4, $t8
    ctx->r12 = SUB32(0, ctx->r24);
    // 0x80063FB0: addu        $s4, $v0, $t7
    ctx->r20 = ADD32(ctx->r2, ctx->r15);
    // 0x80063FB4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80063FB8: bne         $s4, $v1, L_80063FE0
    if (ctx->r20 != ctx->r3) {
        // 0x80063FBC: addu        $fp, $v0, $t5
        ctx->r30 = ADD32(ctx->r2, ctx->r13);
            goto L_80063FE0;
    }
    // 0x80063FBC: addu        $fp, $v0, $t5
    ctx->r30 = ADD32(ctx->r2, ctx->r13);
    // 0x80063FC0: or          $t6, $s2, $zero
    ctx->r14 = ctx->r18 | 0;
    // 0x80063FC4: sll         $s2, $s5, 16
    ctx->r18 = S32(ctx->r21 << 16);
    // 0x80063FC8: sll         $s5, $t6, 16
    ctx->r21 = S32(ctx->r14 << 16);
    // 0x80063FCC: sra         $t7, $s5, 16
    ctx->r15 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80063FD0: sra         $t9, $s2, 16
    ctx->r25 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80063FD4: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x80063FD8: b           L_80063FFC
    // 0x80063FDC: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
        goto L_80063FFC;
    // 0x80063FDC: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
L_80063FE0:
    // 0x80063FE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80063FE4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80063FE8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80063FEC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80063FF0: jal         0x800646E0
    // 0x80063FF4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _loadBuffer(rdram, ctx);
        goto after_2;
    // 0x80063FF4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x80063FF8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80063FFC:
    // 0x80063FFC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80064000: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80064004: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80064008: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8006400C: jal         0x80064464
    // 0x80064010: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _loadOutputBuffer(rdram, ctx);
        goto after_3;
    // 0x80064010: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
    // 0x80064014: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x80064018: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8006401C: beq         $a0, $zero, L_80064074
    if (ctx->r4 == 0) {
        // 0x80064020: andi        $t4, $a0, 0xFFFF
        ctx->r12 = ctx->r4 & 0XFFFF;
            goto L_80064074;
    }
    // 0x80064020: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x80064024: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80064028: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x8006402C: andi        $t7, $s2, 0xFFFF
    ctx->r15 = ctx->r18 & 0XFFFF;
    // 0x80064030: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80064034: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80064038: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8006403C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80064040: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x80064044: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80064048: bne         $t4, $zero, L_80064074
    if (ctx->r12 != 0) {
        // 0x8006404C: nop
    
            goto L_80064074;
    }
    // 0x8006404C: nop

    // 0x80064050: lw          $t5, 0x20($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X20);
    // 0x80064054: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80064058: bne         $t5, $zero, L_80064074
    if (ctx->r13 != 0) {
        // 0x8006405C: or          $a1, $fp, $zero
        ctx->r5 = ctx->r30 | 0;
            goto L_80064074;
    }
    // 0x8006405C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80064060: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80064064: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80064068: jal         0x80064878
    // 0x8006406C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _saveBuffer(rdram, ctx);
        goto after_4;
    // 0x8006406C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // 0x80064070: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80064074:
    // 0x80064074: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
    // 0x80064078: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8006407C: beq         $v1, $zero, L_800640C0
    if (ctx->r3 == 0) {
        // 0x80064080: andi        $t9, $v1, 0xFFFF
        ctx->r25 = ctx->r3 & 0XFFFF;
            goto L_800640C0;
    }
    // 0x80064080: andi        $t9, $v1, 0xFFFF
    ctx->r25 = ctx->r3 & 0XFFFF;
    // 0x80064084: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80064088: sll         $t4, $s2, 16
    ctx->r12 = S32(ctx->r18 << 16);
    // 0x8006408C: andi        $t5, $s5, 0xFFFF
    ctx->r13 = ctx->r21 & 0XFFFF;
    // 0x80064090: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80064094: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80064098: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006409C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800640A0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800640A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800640A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800640AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800640B0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800640B4: jal         0x80064878
    // 0x800640B8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    _saveBuffer(rdram, ctx);
        goto after_5;
    // 0x800640B8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_5:
    // 0x800640BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800640C0:
    // 0x800640C0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800640C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800640C8: beq         $a0, $zero, L_800640DC
    if (ctx->r4 == 0) {
        // 0x800640CC: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_800640DC;
    }
    // 0x800640CC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800640D0: jal         0x80064A10
    // 0x800640D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _filterBuffer(rdram, ctx);
        goto after_6;
    // 0x800640D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x800640D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800640DC:
    // 0x800640DC: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x800640E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800640E4: bne         $t9, $zero, L_80064100
    if (ctx->r25 != 0) {
        // 0x800640E8: or          $a1, $fp, $zero
        ctx->r5 = ctx->r30 | 0;
            goto L_80064100;
    }
    // 0x800640E8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800640EC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800640F0: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800640F4: jal         0x80064878
    // 0x800640F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _saveBuffer(rdram, ctx);
        goto after_7;
    // 0x800640F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // 0x800640FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80064100:
    // 0x80064100: lh          $v1, 0xC($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XC);
    // 0x80064104: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80064108: beq         $v1, $zero, L_80064130
    if (ctx->r3 == 0) {
        // 0x8006410C: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80064130;
    }
    // 0x8006410C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80064110: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x80064114: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80064118: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8006411C: ori         $t9, $t6, 0x800
    ctx->r25 = ctx->r14 | 0X800;
    // 0x80064120: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x80064124: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80064128: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8006412C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80064130:
    // 0x80064130: lbu         $t6, 0x24($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X24);
    // 0x80064134: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x80064138: sll         $t4, $s7, 16
    ctx->r12 = S32(ctx->r23 << 16);
    // 0x8006413C: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x80064140: sra         $s7, $t4, 16
    ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80064144: slt         $at, $s7, $t6
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80064148: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8006414C: bne         $at, $zero, L_80063F88
    if (ctx->r1 != 0) {
        // 0x80064150: addu        $v1, $v0, $t8
        ctx->r3 = ADD32(ctx->r2, ctx->r24);
            goto L_80063F88;
    }
    // 0x80064150: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
L_80064154:
    // 0x80064154: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    // 0x80064158: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x8006415C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80064160: lw          $t5, 0x14($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X14);
    // 0x80064164: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x80064168: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8006416C: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x80064170: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x80064174: beq         $at, $zero, L_80064184
    if (ctx->r1 == 0) {
        // 0x80064178: sw          $t8, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->r24;
            goto L_80064184;
    }
    // 0x80064178: sw          $t8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r24;
    // 0x8006417C: subu        $t9, $t8, $t4
    ctx->r25 = SUB32(ctx->r24, ctx->r12);
    // 0x80064180: sw          $t9, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r25;
L_80064184:
    // 0x80064184: lui         $t7, 0xA00
    ctx->r15 = S32(0XA00 << 16);
    // 0x80064188: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x8006418C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80064190: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80064194: lui         $at, 0x6C0
    ctx->r1 = S32(0X6C0 << 16);
    // 0x80064198: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x8006419C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x800641A0: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x800641A4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800641A8:
    // 0x800641A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800641AC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800641B0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800641B4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800641B8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800641BC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800641C0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800641C4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800641C8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800641CC: jr          $ra
    // 0x800641D0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800641D0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void alFxParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800641D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800641D8: bne         $a1, $at, L_800641E4
    if (ctx->r5 != ctx->r1) {
        // 0x800641DC: nop
    
            goto L_800641E4;
    }
    // 0x800641DC: nop

    // 0x800641E0: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_800641E4:
    // 0x800641E4: jr          $ra
    // 0x800641E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800641E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void alFxParamHdl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800641EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800641F0: addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // 0x800641F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800641F8: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x800641FC: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80064200: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80064204: beq         $at, $zero, L_80064454
    if (ctx->r1 == 0) {
        // 0x80064208: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80064454;
    }
    // 0x80064208: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006420C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80064210: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80064214: addu        $at, $at, $t6
    gpr jr_addend_80064220 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80064218: lw          $t6, 0x7400($at)
    ctx->r14 = ADD32(ctx->r1, 0X7400);
    // 0x8006421C: nop

    // 0x80064220: jr          $t6
    // 0x80064224: nop

    switch (jr_addend_80064220 >> 2) {
        case 0: goto L_80064228; break;
        case 1: goto L_8006425C; break;
        case 2: goto L_800642BC; break;
        case 3: goto L_80064290; break;
        case 4: goto L_800642E8; break;
        case 5: goto L_80064314; break;
        case 6: goto L_80064384; break;
        case 7: goto L_80064404; break;
        default: switch_error(__func__, 0x80064220, 0x800E7400);
    }
    // 0x80064224: nop

L_80064228:
    // 0x80064228: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8006422C: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x80064230: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x80064234: bgez        $v1, L_80064244
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064238: sra         $t9, $v1, 3
        ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064244;
    }
    // 0x80064238: sra         $t9, $v1, 3
    ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8006423C: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064240: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_80064244:
    // 0x80064244: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80064248: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8006424C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80064250: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80064254: b           L_80064454
    // 0x80064258: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
        goto L_80064454;
    // 0x80064258: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_8006425C:
    // 0x8006425C: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80064260: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x80064264: lw          $t4, 0x20($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X20);
    // 0x80064268: bgez        $v1, L_80064278
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006426C: sra         $t5, $v1, 3
        ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064278;
    }
    // 0x8006426C: sra         $t5, $v1, 3
    ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80064270: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064274: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_80064278:
    // 0x80064278: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006427C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80064280: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80064284: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x80064288: b           L_80064454
    // 0x8006428C: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
        goto L_80064454;
    // 0x8006428C: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
L_80064290:
    // 0x80064290: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x80064294: bgez        $v1, L_800642A4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064298: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800642A4;
    }
    // 0x80064298: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8006429C: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800642A0: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_800642A4:
    // 0x800642A4: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x800642A8: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x800642AC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800642B0: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x800642B4: b           L_80064454
    // 0x800642B8: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
        goto L_80064454;
    // 0x800642B8: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
L_800642BC:
    // 0x800642BC: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x800642C0: bgez        $v1, L_800642D0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800642C4: sra         $t4, $v1, 3
        ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800642D0;
    }
    // 0x800642C4: sra         $t4, $v1, 3
    ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800642C8: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800642CC: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800642D0:
    // 0x800642D0: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800642D4: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800642D8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800642DC: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x800642E0: b           L_80064454
    // 0x800642E4: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
        goto L_80064454;
    // 0x800642E4: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
L_800642E8:
    // 0x800642E8: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x800642EC: bgez        $v1, L_800642FC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800642F0: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800642FC;
    }
    // 0x800642F0: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800642F4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800642F8: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_800642FC:
    // 0x800642FC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80064300: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x80064304: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80064308: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8006430C: b           L_80064454
    // 0x80064310: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
        goto L_80064454;
    // 0x80064310: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
L_80064314:
    // 0x80064314: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80064318: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8006431C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80064320: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80064324: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80064328: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006432C: lw          $t2, 0x3D10($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3D10);
    // 0x80064330: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x80064334: lw          $t4, 0x44($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X44);
    // 0x80064338: nop

    // 0x8006433C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80064340: nop

    // 0x80064344: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80064348: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8006434C: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x80064350: nop

    // 0x80064354: div.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x80064358: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8006435C: bgez        $v1, L_8006436C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064360: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8006436C;
    }
    // 0x80064360: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80064364: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064368: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8006436C:
    // 0x8006436C: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80064370: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x80064374: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80064378: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x8006437C: b           L_80064454
    // 0x80064380: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
        goto L_80064454;
    // 0x80064380: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
L_80064384:
    // 0x80064384: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x80064388: bgez        $v1, L_80064398
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006438C: sra         $t8, $v1, 3
        ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064398;
    }
    // 0x8006438C: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80064390: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064394: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_80064398:
    // 0x80064398: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8006439C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800643A0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800643A4: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x800643A8: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800643AC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800643B0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800643B4: subu        $t6, $t2, $t4
    ctx->r14 = SUB32(ctx->r10, ctx->r12);
    // 0x800643B8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800643BC: bgez        $t6, L_800643D8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800643C0: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_800643D8;
    }
    // 0x800643C0: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x800643C4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800643C8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800643CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800643D0: nop

    // 0x800643D4: add.d       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f18.d + ctx->f16.d;
L_800643D8:
    // 0x800643D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800643DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800643E0: lwc1        $f11, 0x7420($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X7420);
    // 0x800643E4: lwc1        $f10, 0x7424($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7424);
    // 0x800643E8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800643EC: nop

    // 0x800643F0: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800643F4: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x800643F8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800643FC: b           L_80064454
    // 0x80064400: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
        goto L_80064454;
    // 0x80064400: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
L_80064404:
    // 0x80064404: bgez        $v1, L_80064414
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064408: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064414;
    }
    // 0x80064408: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8006440C: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064410: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_80064414:
    // 0x80064414: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80064418: lw          $t3, 0x20($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X20);
    // 0x8006441C: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x80064420: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80064424: addu        $t1, $t3, $t5
    ctx->r9 = ADD32(ctx->r11, ctx->r13);
    // 0x80064428: lw          $a1, 0x20($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X20);
    // 0x8006442C: nop

    // 0x80064430: beq         $a1, $zero, L_80064458
    if (ctx->r5 == 0) {
        // 0x80064434: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80064458;
    }
    // 0x80064434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064438: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x8006443C: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x80064440: nop

    // 0x80064444: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x80064448: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    // 0x8006444C: jal         0x80064B90
    // 0x80064450: nop

    init_lpfilter(rdram, ctx);
        goto after_0;
    // 0x80064450: nop

    after_0:
L_80064454:
    // 0x80064454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80064458:
    // 0x80064458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006445C: jr          $ra
    // 0x80064460: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80064460: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void _loadOutputBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064464: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80064468: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006446C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80064470: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80064474: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80064478: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8006447C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80064480: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x80064484: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80064488: beq         $t6, $zero, L_80064694
    if (ctx->r14 == 0) {
        // 0x8006448C: or          $s2, $a3, $zero
        ctx->r18 = ctx->r7 | 0;
            goto L_80064694;
    }
    // 0x8006448C: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80064490: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80064494: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80064498: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8006449C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800644A0: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x800644A4: jal         0x80064AC4
    // 0x800644A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _doModFunc(rdram, ctx);
        goto after_0;
    // 0x800644A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x800644AC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800644B0: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800644B4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800644B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800644BC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800644C0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800644C4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800644C8: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800644CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800644D0: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800644D4: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // 0x800644D8: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800644DC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800644E0: nop

    // 0x800644E4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800644E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800644EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800644F0: nop

    // 0x800644F4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800644F8: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800644FC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80064500: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80064504: nop

    // 0x80064508: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006450C: nop

    // 0x80064510: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80064514: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x80064518: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8006451C: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x80064520: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80064524: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x80064528: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x8006452C: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80064530: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80064534: nop

    // 0x80064538: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8006453C: nop

    // 0x80064540: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80064544: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80064548: nop

    // 0x8006454C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80064550: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80064554: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80064558: nop

    // 0x8006455C: cvt.w.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80064560: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80064564: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80064568: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8006456C: nop

    // 0x80064570: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80064574: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80064578: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x8006457C: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x80064580: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80064584: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x80064588: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8006458C: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80064590: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x80064594: addu        $s1, $t3, $t2
    ctx->r17 = ADD32(ctx->r11, ctx->r10);
    // 0x80064598: andi        $v1, $s1, 0x7
    ctx->r3 = ctx->r17 & 0X7;
    // 0x8006459C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800645A0: sra         $t4, $v1, 1
    ctx->r12 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800645A4: sll         $t1, $t4, 1
    ctx->r9 = S32(ctx->r12 << 1);
    // 0x800645A8: subu        $a1, $s1, $t1
    ctx->r5 = SUB32(ctx->r17, ctx->r9);
    // 0x800645AC: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800645B0: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x800645B4: addu        $a3, $t0, $t4
    ctx->r7 = ADD32(ctx->r8, ctx->r12);
    // 0x800645B8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800645BC: jal         0x800646E0
    // 0x800645C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    _loadBuffer(rdram, ctx);
        goto after_1;
    // 0x800645C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_1:
    // 0x800645C4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800645C8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800645CC: addiu       $t6, $t1, 0x280
    ctx->r14 = ADD32(ctx->r9, 0X280);
    // 0x800645D0: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800645D4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800645D8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800645DC: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800645E0: sll         $t4, $s2, 1
    ctx->r12 = S32(ctx->r18 << 1);
    // 0x800645E4: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800645E8: sll         $t2, $t3, 16
    ctx->r10 = S32(ctx->r11 << 16);
    // 0x800645EC: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x800645F0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800645F4: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800645F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800645FC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80064600: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80064604: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80064608: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8006460C: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x80064610: addiu       $s1, $v0, 0x10
    ctx->r17 = ADD32(ctx->r2, 0X10);
    // 0x80064614: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80064618: lw          $t2, 0x24($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X24);
    // 0x8006461C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80064620: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80064624: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80064628: andi        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 & 0XFF;
    // 0x8006462C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80064630: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80064634: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80064638: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8006463C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80064640: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80064644: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x80064648: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x8006464C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80064650: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80064654: nop

    // 0x80064658: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    // 0x8006465C: jal         0x800C9250
    // 0x80064660: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80064660: nop

    after_2:
    // 0x80064664: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80064668: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8006466C: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80064670: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80064674: nop

    // 0x80064678: sw          $zero, 0x24($t2)
    MEM_W(0X24, ctx->r10) = 0;
    // 0x8006467C: lw          $t5, 0x18($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X18);
    // 0x80064680: nop

    // 0x80064684: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x80064688: subu        $t7, $t6, $s2
    ctx->r15 = SUB32(ctx->r14, ctx->r18);
    // 0x8006468C: b           L_800646C4
    // 0x80064690: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
        goto L_800646C4;
    // 0x80064690: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
L_80064694:
    // 0x80064694: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80064698: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8006469C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800646A0: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x800646A4: negu        $t4, $t9
    ctx->r12 = SUB32(0, ctx->r25);
    // 0x800646A8: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x800646AC: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x800646B0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800646B4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800646B8: jal         0x800646E0
    // 0x800646BC: addu        $a1, $t8, $t2
    ctx->r5 = ADD32(ctx->r24, ctx->r10);
    _loadBuffer(rdram, ctx);
        goto after_3;
    // 0x800646BC: addu        $a1, $t8, $t2
    ctx->r5 = ADD32(ctx->r24, ctx->r10);
    after_3:
    // 0x800646C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800646C4:
    // 0x800646C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800646C8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800646CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800646D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800646D4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800646D8: jr          $ra
    // 0x800646DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800646DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void _loadBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800646E0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800646E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800646E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800646EC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800646F0: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800646F4: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800646F8: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800646FC: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80064700: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80064704: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80064708: beq         $at, $zero, L_80064714
    if (ctx->r1 == 0) {
        // 0x8006470C: addu        $t0, $v0, $t7
        ctx->r8 = ADD32(ctx->r2, ctx->r15);
            goto L_80064714;
    }
    // 0x8006470C: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x80064710: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_80064714:
    // 0x80064714: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x80064718: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8006471C: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80064720: addu        $a3, $t8, $a1
    ctx->r7 = ADD32(ctx->r24, ctx->r5);
    // 0x80064724: sltu        $at, $t0, $a3
    ctx->r1 = ctx->r8 < ctx->r7 ? 1 : 0;
    // 0x80064728: beq         $at, $zero, L_80064808
    if (ctx->r1 == 0) {
        // 0x8006472C: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_80064808;
    }
    // 0x8006472C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80064730: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80064734: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80064738: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x8006473C: sra         $t6, $t1, 1
    ctx->r14 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80064740: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80064744: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80064748: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8006474C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80064750: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80064754: addiu       $s0, $t9, 0x8
    ctx->r16 = ADD32(ctx->r25, 0X8);
    // 0x80064758: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8006475C: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x80064760: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80064764: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x80064768: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8006476C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80064770: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80064774: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80064778: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8006477C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80064780: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80064784: jal         0x800C9250
    // 0x80064788: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80064788: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8006478C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80064790: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80064794: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80064798: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8006479C: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x800647A0: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800647A4: subu        $t7, $a3, $t0
    ctx->r15 = SUB32(ctx->r7, ctx->r8);
    // 0x800647A8: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800647AC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800647B0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800647B4: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800647B8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800647BC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800647C0: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800647C4: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x800647C8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800647CC: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800647D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800647D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800647D8: lui         $t4, 0x400
    ctx->r12 = S32(0X400 << 16);
    // 0x800647DC: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800647E0: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x800647E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800647E8: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    // 0x800647EC: jal         0x800C9250
    // 0x800647F0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800647F0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800647F4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800647F8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800647FC: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80064800: b           L_80064854
    // 0x80064804: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
        goto L_80064854;
    // 0x80064804: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
L_80064808:
    // 0x80064808: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8006480C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80064810: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80064814: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80064818: addiu       $s0, $t6, 0x8
    ctx->r16 = ADD32(ctx->r14, 0X8);
    // 0x8006481C: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
    // 0x80064820: sw          $a3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r7;
    // 0x80064824: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80064828: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8006482C: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x80064830: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80064834: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80064838: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8006483C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80064840: jal         0x800C9250
    // 0x80064844: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80064844: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80064848: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8006484C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80064850: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80064854:
    // 0x80064854: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80064858: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x8006485C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80064860: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80064864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80064868: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x8006486C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064870: jr          $ra
    // 0x80064874: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80064874: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _saveBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064878: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006487C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80064880: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064884: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80064888: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8006488C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80064890: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80064894: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80064898: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8006489C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800648A0: beq         $at, $zero, L_800648AC
    if (ctx->r1 == 0) {
        // 0x800648A4: addu        $t0, $v0, $t7
        ctx->r8 = ADD32(ctx->r2, ctx->r15);
            goto L_800648AC;
    }
    // 0x800648A4: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x800648A8: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_800648AC:
    // 0x800648AC: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800648B0: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800648B4: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800648B8: addu        $a3, $t8, $a1
    ctx->r7 = ADD32(ctx->r24, ctx->r5);
    // 0x800648BC: sltu        $at, $t0, $a3
    ctx->r1 = ctx->r8 < ctx->r7 ? 1 : 0;
    // 0x800648C0: beq         $at, $zero, L_800649B4
    if (ctx->r1 == 0) {
        // 0x800648C4: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800649B4;
    }
    // 0x800648C4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800648C8: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x800648CC: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x800648D0: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x800648D4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800648D8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800648DC: sra         $t4, $t1, 1
    ctx->r12 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800648E0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800648E4: andi        $t9, $t5, 0xFFFF
    ctx->r25 = ctx->r13 & 0XFFFF;
    // 0x800648E8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800648EC: or          $t3, $t8, $t9
    ctx->r11 = ctx->r24 | ctx->r25;
    // 0x800648F0: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800648F4: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800648F8: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800648FC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80064900: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80064904: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80064908: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8006490C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80064910: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80064914: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80064918: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8006491C: jal         0x800C9250
    // 0x80064920: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80064920: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80064924: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80064928: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8006492C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80064930: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80064934: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80064938: lui         $t5, 0x800
    ctx->r13 = S32(0X800 << 16);
    // 0x8006493C: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x80064940: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80064944: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80064948: subu        $t3, $a3, $t0
    ctx->r11 = SUB32(ctx->r7, ctx->r8);
    // 0x8006494C: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80064950: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x80064954: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80064958: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8006495C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80064960: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80064964: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80064968: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006496C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80064970: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80064974: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80064978: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8006497C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80064980: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    // 0x80064984: jal         0x800C9250
    // 0x80064988: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80064988: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8006498C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80064990: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80064994: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80064998: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x8006499C: andi        $t5, $a2, 0xFFFF
    ctx->r13 = ctx->r6 & 0XFFFF;
    // 0x800649A0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800649A4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800649A8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800649AC: b           L_800649FC
    // 0x800649B0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800649FC;
    // 0x800649B0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800649B4:
    // 0x800649B4: lui         $t6, 0x800
    ctx->r14 = S32(0X800 << 16);
    // 0x800649B8: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800649BC: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800649C0: andi        $t4, $a2, 0xFFFF
    ctx->r12 = ctx->r6 & 0XFFFF;
    // 0x800649C4: sll         $t3, $t8, 16
    ctx->r11 = S32(ctx->r24 << 16);
    // 0x800649C8: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800649CC: addiu       $s0, $t9, 0x8
    ctx->r16 = ADD32(ctx->r25, 0X8);
    // 0x800649D0: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x800649D4: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800649D8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800649DC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800649E0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800649E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800649E8: jal         0x800C9250
    // 0x800649EC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800649EC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800649F0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800649F4: nop

    // 0x800649F8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800649FC:
    // 0x800649FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80064A00: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80064A04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064A08: jr          $ra
    // 0x80064A0C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80064A0C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _filterBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064A10: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80064A14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064A18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80064A1C: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x80064A20: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80064A24: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80064A28: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80064A2C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80064A30: lui         $t1, 0xB00
    ctx->r9 = S32(0XB00 << 16);
    // 0x80064A34: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x80064A38: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80064A3C: ori         $t1, $t1, 0x20
    ctx->r9 = ctx->r9 | 0X20;
    // 0x80064A40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80064A44: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80064A48: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80064A4C: sw          $t1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r9;
    // 0x80064A50: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80064A54: jal         0x800C9250
    // 0x80064A58: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80064A58: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x80064A5C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80064A60: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x80064A64: addiu       $v1, $a3, 0x10
    ctx->r3 = ADD32(ctx->r7, 0X10);
    // 0x80064A68: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80064A6C: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x80064A70: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80064A74: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x80064A78: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80064A7C: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80064A80: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80064A84: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80064A88: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x80064A8C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80064A90: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80064A94: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80064A98: jal         0x800C9250
    // 0x80064A9C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80064A9C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x80064AA0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80064AA4: nop

    // 0x80064AA8: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80064AAC: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80064AB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80064AB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064AB8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80064ABC: jr          $ra
    // 0x80064AC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80064AC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _doModFunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064AC4: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80064AC8: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80064ACC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80064AD0: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80064AD4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80064AD8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80064ADC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80064AE0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80064AE4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80064AE8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80064AEC: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80064AF0: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80064AF4: nop

    // 0x80064AF8: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80064AFC: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80064B00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80064B04: bc1f        L_80064B28
    if (!c1cs) {
        // 0x80064B08: nop
    
            goto L_80064B28;
    }
    // 0x80064B08: nop

    // 0x80064B0C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80064B10: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80064B14: nop

    // 0x80064B18: sub.d       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f0.d - ctx->f8.d;
    // 0x80064B1C: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80064B20: b           L_80064B30
    // 0x80064B24: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
        goto L_80064B30;
    // 0x80064B24: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
L_80064B28:
    // 0x80064B28: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    // 0x80064B2C: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
L_80064B30:
    // 0x80064B30: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80064B34: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80064B38: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80064B3C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80064B40: bc1f        L_80064B4C
    if (!c1cs) {
        // 0x80064B44: nop
    
            goto L_80064B4C;
    }
    // 0x80064B44: nop

    // 0x80064B48: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80064B4C:
    // 0x80064B4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80064B50: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80064B54: sub.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f4.d - ctx->f8.d;
    // 0x80064B58: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80064B5C: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x80064B60: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80064B64: jr          $ra
    // 0x80064B68: nop

    return;
    // 0x80064B68: nop

;}
RECOMP_FUNC void alFxReverbSet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80064B70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80064B74: jr          $ra
    // 0x80064B78: sb          $a0, -0x2BE0($at)
    MEM_B(-0X2BE0, ctx->r1) = ctx->r4;
    return;
    // 0x80064B78: sb          $a0, -0x2BE0($at)
    MEM_B(-0X2BE0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _alFxEnabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B7C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80064B80: lbu         $v0, -0x2BE0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2BE0);
    // 0x80064B84: jr          $ra
    // 0x80064B88: nop

    return;
    // 0x80064B88: nop

    // 0x80064B8C: nop

;}
RECOMP_FUNC void init_lpfilter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B90: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80064B94: addiu       $t9, $zero, 0x4000
    ctx->r25 = ADD32(0, 0X4000);
    // 0x80064B98: sll         $t6, $v0, 14
    ctx->r14 = S32(ctx->r2 << 14);
    // 0x80064B9C: sra         $v1, $t6, 15
    ctx->r3 = S32(SIGNED(ctx->r14) >> 15);
    // 0x80064BA0: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80064BA4: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80064BA8: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x80064BAC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80064BB0: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x80064BB4: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x80064BB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80064BBC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_80064BC0:
    // 0x80064BC0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80064BC4: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x80064BC8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80064BCC: bne         $at, $zero, L_80064BC0
    if (ctx->r1 != 0) {
        // 0x80064BD0: sh          $zero, 0x6($a2)
        MEM_H(0X6, ctx->r6) = 0;
            goto L_80064BC0;
    }
    // 0x80064BD0: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x80064BD4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80064BD8: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x80064BDC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80064BE0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80064BE4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80064BE8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80064BEC: div.d       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x80064BF0: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80064BF4: sh          $v1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r3;
    // 0x80064BF8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80064BFC: beq         $at, $zero, L_80064C40
    if (ctx->r1 == 0) {
        // 0x80064C00: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_80064C40;
    }
    // 0x80064C00: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_80064C04:
    // 0x80064C04: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x80064C08: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80064C0C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80064C10: mul.d       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f12.d);
    // 0x80064C14: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80064C18: nop

    // 0x80064C1C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80064C20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80064C24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80064C28: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80064C2C: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x80064C30: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80064C34: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80064C38: bne         $at, $zero, L_80064C04
    if (ctx->r1 != 0) {
        // 0x80064C3C: sh          $t3, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r11;
            goto L_80064C04;
    }
    // 0x80064C3C: sh          $t3, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r11;
L_80064C40:
    // 0x80064C40: jr          $ra
    // 0x80064C44: nop

    return;
    // 0x80064C44: nop

;}
RECOMP_FUNC void alFxNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064C48: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80064C4C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80064C50: sll         $s0, $a2, 16
    ctx->r16 = S32(ctx->r6 << 16);
    // 0x80064C54: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80064C58: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80064C5C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80064C60: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80064C64: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80064C68: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80064C6C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80064C70: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80064C74: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80064C78: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80064C7C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80064C80: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80064C84: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80064C88: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80064C8C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80064C90: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80064C94: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80064C98: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80064C9C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80064CA0: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80064CA4: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80064CA8: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80064CAC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80064CB0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80064CB4: addiu       $a2, $a2, 0x41D4
    ctx->r6 = ADD32(ctx->r6, 0X41D4);
    // 0x80064CB8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80064CBC: jal         0x800CA610
    // 0x80064CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80064CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80064CC4: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80064CC8: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80064CCC: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80064CD0: addiu       $t7, $t7, 0x3E70
    ctx->r15 = ADD32(ctx->r15, 0X3E70);
    // 0x80064CD4: addiu       $t8, $t8, 0x41EC
    ctx->r24 = ADD32(ctx->r24, 0X41EC);
    // 0x80064CD8: sw          $t7, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r15;
    // 0x80064CDC: sw          $t8, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r24;
    // 0x80064CE0: addu        $t9, $v0, $s0
    ctx->r25 = ADD32(ctx->r2, ctx->r16);
    // 0x80064CE4: lbu         $t0, 0x1C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1C);
    // 0x80064CE8: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064CEC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80064CF0: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x80064CF4: beq         $at, $zero, L_80064D68
    if (ctx->r1 == 0) {
        // 0x80064CF8: addiu       $s3, $s3, -0x2A68
        ctx->r19 = ADD32(ctx->r19, -0X2A68);
            goto L_80064D68;
    }
    // 0x80064CF8: addiu       $s3, $s3, -0x2A68
    ctx->r19 = ADD32(ctx->r19, -0X2A68);
    // 0x80064CFC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80064D00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80064D04: addu        $at, $at, $t1
    gpr jr_addend_80064D10 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80064D08: lw          $t1, 0x7430($at)
    ctx->r9 = ADD32(ctx->r1, 0X7430);
    // 0x80064D0C: nop

    // 0x80064D10: jr          $t1
    // 0x80064D14: nop

    switch (jr_addend_80064D10 >> 2) {
        case 0: goto L_80064D18; break;
        case 1: goto L_80064D24; break;
        case 2: goto L_80064D3C; break;
        case 3: goto L_80064D48; break;
        case 4: goto L_80064D30; break;
        case 5: goto L_80064D54; break;
        default: switch_error(__func__, 0x80064D10, 0x800E7430);
    }
    // 0x80064D14: nop

L_80064D18:
    // 0x80064D18: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064D1C: b           L_80064D68
    // 0x80064D20: addiu       $s3, $s3, -0x2BD0
    ctx->r19 = ADD32(ctx->r19, -0X2BD0);
        goto L_80064D68;
    // 0x80064D20: addiu       $s3, $s3, -0x2BD0
    ctx->r19 = ADD32(ctx->r19, -0X2BD0);
L_80064D24:
    // 0x80064D24: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064D28: b           L_80064D68
    // 0x80064D2C: addiu       $s3, $s3, -0x2B68
    ctx->r19 = ADD32(ctx->r19, -0X2B68);
        goto L_80064D68;
    // 0x80064D2C: addiu       $s3, $s3, -0x2B68
    ctx->r19 = ADD32(ctx->r19, -0X2B68);
L_80064D30:
    // 0x80064D30: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064D34: b           L_80064D68
    // 0x80064D38: addiu       $s3, $s3, -0x2AE0
    ctx->r19 = ADD32(ctx->r19, -0X2AE0);
        goto L_80064D68;
    // 0x80064D38: addiu       $s3, $s3, -0x2AE0
    ctx->r19 = ADD32(ctx->r19, -0X2AE0);
L_80064D3C:
    // 0x80064D3C: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064D40: b           L_80064D68
    // 0x80064D44: addiu       $s3, $s3, -0x2AB8
    ctx->r19 = ADD32(ctx->r19, -0X2AB8);
        goto L_80064D68;
    // 0x80064D44: addiu       $s3, $s3, -0x2AB8
    ctx->r19 = ADD32(ctx->r19, -0X2AB8);
L_80064D48:
    // 0x80064D48: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064D4C: b           L_80064D68
    // 0x80064D50: addiu       $s3, $s3, -0x2A90
    ctx->r19 = ADD32(ctx->r19, -0X2A90);
        goto L_80064D68;
    // 0x80064D50: addiu       $s3, $s3, -0x2A90
    ctx->r19 = ADD32(ctx->r19, -0X2A90);
L_80064D54:
    // 0x80064D54: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80064D58: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80064D5C: lw          $s3, 0x20($t3)
    ctx->r19 = MEM_W(ctx->r11, 0X20);
    // 0x80064D60: b           L_80064D6C
    // 0x80064D64: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
        goto L_80064D6C;
    // 0x80064D64: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_80064D68:
    // 0x80064D68: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_80064D6C:
    // 0x80064D6C: addiu       $fp, $zero, 0x28
    ctx->r30 = ADD32(0, 0X28);
    // 0x80064D70: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x80064D74: multu       $t6, $fp
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064D78: sb          $t4, 0x24($s6)
    MEM_B(0X24, ctx->r22) = ctx->r12;
    // 0x80064D7C: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
    // 0x80064D80: lui         $s5, 0xFF
    ctx->r21 = S32(0XFF << 16);
    // 0x80064D84: ori         $s5, $s5, 0xFFFF
    ctx->r21 = ctx->r21 | 0XFFFF;
    // 0x80064D88: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80064D8C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80064D90: sw          $t5, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->r13;
    // 0x80064D94: mflo        $a0
    ctx->r4 = lo;
    // 0x80064D98: jal         0x80070EDC
    // 0x80064D9C: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80064D9C: nop

    after_1:
    // 0x80064DA0: lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X1C);
    // 0x80064DA4: sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // 0x80064DA8: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80064DAC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80064DB0: jal         0x80070EDC
    // 0x80064DB4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80064DB4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
    // 0x80064DB8: lw          $t8, 0x1C($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X1C);
    // 0x80064DBC: sw          $v0, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r2;
    // 0x80064DC0: sw          $v0, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r2;
    // 0x80064DC4: beq         $t8, $zero, L_80064DF4
    if (ctx->r24 == 0) {
        // 0x80064DC8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80064DF4;
    }
    // 0x80064DC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80064DCC:
    // 0x80064DCC: lw          $t9, 0x14($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X14);
    // 0x80064DD0: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x80064DD4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80064DD8: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x80064DDC: lw          $t3, 0x1C($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X1C);
    // 0x80064DE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80064DE4: andi        $t2, $v1, 0xFFFF
    ctx->r10 = ctx->r3 & 0XFFFF;
    // 0x80064DE8: sltu        $at, $t2, $t3
    ctx->r1 = ctx->r10 < ctx->r11 ? 1 : 0;
    // 0x80064DEC: bne         $at, $zero, L_80064DCC
    if (ctx->r1 != 0) {
        // 0x80064DF0: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_80064DCC;
    }
    // 0x80064DF0: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_80064DF4:
    // 0x80064DF4: lbu         $t4, 0x24($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X24);
    // 0x80064DF8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80064DFC: blez        $t4, L_80065044
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80064E00: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80065044;
    }
    // 0x80064E00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80064E04: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80064E08: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80064E0C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80064E10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80064E14: lwc1        $f21, 0x7448($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X7448);
    // 0x80064E18: lwc1        $f20, 0x744C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X744C);
    // 0x80064E1C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80064E20: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_80064E24:
    // 0x80064E24: multu       $s4, $fp
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064E28: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80064E2C: lw          $t5, 0x20($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X20);
    // 0x80064E30: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80064E34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064E38: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80064E3C: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x80064E40: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80064E44: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x80064E48: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x80064E4C: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x80064E50: addiu       $s1, $t4, 0x1
    ctx->r17 = ADD32(ctx->r12, 0X1);
    // 0x80064E54: mflo        $t6
    ctx->r14 = lo;
    // 0x80064E58: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    // 0x80064E5C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80064E60: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80064E64: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80064E68: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x80064E6C: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80064E70: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80064E74: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x80064E78: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80064E7C: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x80064E80: addiu       $s1, $t8, 0x1
    ctx->r17 = ADD32(ctx->r24, 0X1);
    // 0x80064E84: sh          $t7, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r15;
    // 0x80064E88: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80064E8C: andi        $t2, $s1, 0xFFFF
    ctx->r10 = ctx->r17 & 0XFFFF;
    // 0x80064E90: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80064E94: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x80064E98: addiu       $s1, $t2, 0x1
    ctx->r17 = ADD32(ctx->r10, 0X1);
    // 0x80064E9C: sh          $t1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r9;
    // 0x80064EA0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80064EA4: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x80064EA8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80064EAC: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80064EB0: sh          $t5, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r13;
    // 0x80064EB4: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80064EB8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80064EBC: beq         $v0, $zero, L_80064FAC
    if (ctx->r2 == 0) {
        // 0x80064EC0: or          $t2, $s1, $zero
        ctx->r10 = ctx->r17 | 0;
            goto L_80064FAC;
    }
    // 0x80064EC0: or          $t2, $s1, $zero
    ctx->r10 = ctx->r17 | 0;
    // 0x80064EC4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80064EC8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80064ECC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80064ED0: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x80064ED4: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80064ED8: div.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80064EDC: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80064EE0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80064EE4: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80064EE8: addiu       $s1, $t6, 0x1
    ctx->r17 = ADD32(ctx->r14, 0X1);
    // 0x80064EEC: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x80064EF0: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80064EF4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80064EF8: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80064EFC: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x80064F00: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80064F04: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80064F08: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x80064F0C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80064F10: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x80064F14: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x80064F18: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80064F1C: bgez        $t4, L_80064F34
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80064F20: swc1        $f6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
            goto L_80064F34;
    }
    // 0x80064F20: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80064F24: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80064F28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80064F2C: nop

    // 0x80064F30: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_80064F34:
    // 0x80064F34: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80064F38: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064F3C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80064F40: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x80064F44: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80064F48: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x80064F4C: swc1        $f24, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f24.u32l;
    // 0x80064F50: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80064F54: nop

    // 0x80064F58: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80064F5C: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80064F60: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x80064F64: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80064F68: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80064F6C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80064F70: jal         0x80070EDC
    // 0x80064F74: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80064F74: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x80064F78: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80064F7C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80064F80: jal         0x80070EDC
    // 0x80064F84: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x80064F84: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x80064F88: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80064F8C: nop

    // 0x80064F90: sw          $v0, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r2;
    // 0x80064F94: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x80064F98: nop

    // 0x80064F9C: swc1        $f26, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f26.u32l;
    // 0x80064FA0: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80064FA4: b           L_80064FBC
    // 0x80064FA8: sw          $s7, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r23;
        goto L_80064FBC;
    // 0x80064FA8: sw          $s7, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r23;
L_80064FAC:
    // 0x80064FAC: addiu       $s1, $t2, 0x2
    ctx->r17 = ADD32(ctx->r10, 0X2);
    // 0x80064FB0: andi        $t3, $s1, 0xFFFF
    ctx->r11 = ctx->r17 & 0XFFFF;
    // 0x80064FB4: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80064FB8: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
L_80064FBC:
    // 0x80064FBC: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80064FC0: addu        $s2, $s3, $t4
    ctx->r18 = ADD32(ctx->r19, ctx->r12);
    // 0x80064FC4: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80064FC8: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80064FCC: beq         $t5, $zero, L_8006501C
    if (ctx->r13 == 0) {
        // 0x80064FD0: nop
    
            goto L_8006501C;
    }
    // 0x80064FD0: nop

    // 0x80064FD4: jal         0x80070EDC
    // 0x80064FD8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x80064FD8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
    // 0x80064FDC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80064FE0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80064FE4: jal         0x80070EDC
    // 0x80064FE8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x80064FE8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_6:
    // 0x80064FEC: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80064FF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064FF4: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    // 0x80064FF8: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x80064FFC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80065000: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x80065004: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80065008: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x8006500C: jal         0x80064B90
    // 0x80065010: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    init_lpfilter(rdram, ctx);
        goto after_7;
    // 0x80065010: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    after_7:
    // 0x80065014: b           L_80065030
    // 0x80065018: lbu         $t2, 0x24($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X24);
        goto L_80065030;
    // 0x80065018: lbu         $t2, 0x24($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X24);
L_8006501C:
    // 0x8006501C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80065020: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x80065024: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80065028: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x8006502C: lbu         $t2, 0x24($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X24);
L_80065030:
    // 0x80065030: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80065034: andi        $t1, $s4, 0xFFFF
    ctx->r9 = ctx->r20 & 0XFFFF;
    // 0x80065038: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8006503C: bne         $at, $zero, L_80064E24
    if (ctx->r1 != 0) {
        // 0x80065040: or          $s4, $t1, $zero
        ctx->r20 = ctx->r9 | 0;
            goto L_80064E24;
    }
    // 0x80065040: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
L_80065044:
    // 0x80065044: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80065048: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8006504C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80065050: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80065054: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80065058: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8006505C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80065060: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80065064: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80065068: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8006506C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80065070: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80065074: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80065078: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8006507C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80065080: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80065084: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80065088: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8006508C: jr          $ra
    // 0x80065090: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80065090: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void alEnvmixerNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065094: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80065098: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006509C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800650A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800650A4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800650A8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800650AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800650B0: addiu       $a2, $a2, -0x5024
    ctx->r6 = ADD32(ctx->r6, -0X5024);
    // 0x800650B4: addiu       $a1, $a1, -0x59D0
    ctx->r5 = ADD32(ctx->r5, -0X59D0);
    // 0x800650B8: jal         0x800CA610
    // 0x800650BC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800650BC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x800650C0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800650C4: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x800650C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800650CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800650D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800650D4: jal         0x800C7D50
    // 0x800650D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800650D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800650DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800650E0: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800650E4: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
    // 0x800650E8: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x800650EC: sh          $v1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r3;
    // 0x800650F0: sh          $v1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r3;
    // 0x800650F4: sh          $v1, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r3;
    // 0x800650F8: sh          $v1, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r3;
    // 0x800650FC: sh          $v1, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r3;
    // 0x80065100: sh          $zero, 0x20($s0)
    MEM_H(0X20, ctx->r16) = 0;
    // 0x80065104: sh          $zero, 0x22($s0)
    MEM_H(0X22, ctx->r16) = 0;
    // 0x80065108: sh          $v1, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r3;
    // 0x8006510C: sh          $zero, 0x24($s0)
    MEM_H(0X24, ctx->r16) = 0;
    // 0x80065110: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80065114: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80065118: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x8006511C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80065120: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x80065124: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x80065128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006512C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80065130: jr          $ra
    // 0x80065134: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065134: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alLoadNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065138: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006513C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80065140: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80065144: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80065148: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006514C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80065150: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80065154: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80065158: addiu       $a1, $a1, -0x3EB4
    ctx->r5 = ADD32(ctx->r5, -0X3EB4);
    // 0x8006515C: addiu       $a2, $a2, -0x4560
    ctx->r6 = ADD32(ctx->r6, -0X4560);
    // 0x80065160: jal         0x800CA610
    // 0x80065164: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80065164: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80065168: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8006516C: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80065170: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065174: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006517C: jal         0x800C7D50
    // 0x80065180: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80065180: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80065184: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80065188: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8006518C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80065190: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80065194: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006519C: jal         0x800C7D50
    // 0x800651A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800651A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800651A4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800651A8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800651AC: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800651B0: jalr        $t9
    // 0x800651B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800651B4: nop

    after_3:
    // 0x800651B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800651BC: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800651C0: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x800651C4: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x800651C8: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x800651CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800651D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800651D4: jr          $ra
    // 0x800651D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800651D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alResampleNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800651DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800651E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800651E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800651E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800651EC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800651F0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800651F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800651F8: addiu       $a2, $a2, -0x3A10
    ctx->r6 = ADD32(ctx->r6, -0X3A10);
    // 0x800651FC: addiu       $a1, $a1, -0x3924
    ctx->r5 = ADD32(ctx->r5, -0X3924);
    // 0x80065200: jal         0x800CA610
    // 0x80065204: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80065204: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80065208: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8006520C: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80065210: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065214: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006521C: jal         0x800C7D50
    // 0x80065220: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80065220: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80065224: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80065228: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8006522C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80065230: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80065234: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80065238: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x8006523C: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80065240: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80065244: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80065248: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x8006524C: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x80065250: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x80065254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80065258: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006525C: jr          $ra
    // 0x80065260: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065260: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alAuxBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065268: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006526C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80065270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065274: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80065278: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8006527C: addiu       $a1, $a1, 0x5B40
    ctx->r5 = ADD32(ctx->r5, 0X5B40);
    // 0x80065280: addiu       $a2, $a2, 0x5C14
    ctx->r6 = ADD32(ctx->r6, 0X5C14);
    // 0x80065284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065288: jal         0x800CA610
    // 0x8006528C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x8006528C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x80065290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80065294: nop

    // 0x80065298: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8006529C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800652A0: nop

    // 0x800652A4: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800652A8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800652AC: nop

    // 0x800652B0: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800652B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800652B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800652BC: jr          $ra
    // 0x800652C0: nop

    return;
    // 0x800652C0: nop

;}
RECOMP_FUNC void alMainBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800652C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800652C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800652CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800652D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800652D4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800652D8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800652DC: addiu       $a1, $a1, -0x36E0
    ctx->r5 = ADD32(ctx->r5, -0X36E0);
    // 0x800652E0: addiu       $a2, $a2, -0x3710
    ctx->r6 = ADD32(ctx->r6, -0X3710);
    // 0x800652E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800652E8: jal         0x800CA610
    // 0x800652EC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800652EC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x800652F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800652F4: nop

    // 0x800652F8: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800652FC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80065300: nop

    // 0x80065304: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80065308: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8006530C: nop

    // 0x80065310: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x80065314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006531C: jr          $ra
    // 0x80065320: nop

    return;
    // 0x80065320: nop

;}
RECOMP_FUNC void alSaveNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006532C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80065330: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80065334: addiu       $a2, $a2, -0x35C0
    ctx->r6 = ADD32(ctx->r6, -0X35C0);
    // 0x80065338: addiu       $a1, $a1, -0x358C
    ctx->r5 = ADD32(ctx->r5, -0X358C);
    // 0x8006533C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065340: jal         0x800CA610
    // 0x80065344: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80065344: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80065348: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006534C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80065350: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80065354: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80065358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006535C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065360: jr          $ra
    // 0x80065364: nop

    return;
    // 0x80065364: nop

    // 0x80065368: nop

    // 0x8006536C: nop

;}
RECOMP_FUNC void alSynNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065370: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80065374: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80065378: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8006537C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80065380: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80065384: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80065388: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006538C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80065390: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80065394: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80065398: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006539C: lw          $s7, 0x14($a1)
    ctx->r23 = MEM_W(ctx->r5, 0X14);
    // 0x800653A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800653A4: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800653A8: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800653AC: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800653B0: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x800653B4: lw          $t7, 0x18($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X18);
    // 0x800653B8: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x800653BC: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x800653C0: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    // 0x800653C4: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x800653C8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800653CC: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x800653D0: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x800653D4: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x800653D8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800653DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800653E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800653E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800653E8: jal         0x800C7D50
    // 0x800653EC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800653EC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_0:
    // 0x800653F0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800653F4: jal         0x80065324
    // 0x800653F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    alSaveNew(rdram, ctx);
        goto after_1;
    // 0x800653F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800653FC: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80065400: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x80065404: sw          $t1, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->r9;
    // 0x80065408: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8006540C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065414: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80065418: jal         0x800C7D50
    // 0x8006541C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x8006541C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80065420: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80065424: sw          $v0, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->r2;
    // 0x80065428: sw          $t3, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r11;
    // 0x8006542C: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x80065430: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80065434: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80065438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006543C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065440: jal         0x800C7D50
    // 0x80065444: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x80065444: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_3:
    // 0x80065448: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x8006544C: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    // 0x80065450: jal         0x80065264
    // 0x80065454: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alAuxBusNew(rdram, ctx);
        goto after_4;
    // 0x80065454: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80065458: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x8006545C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80065460: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80065464: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006546C: jal         0x800C7D50
    // 0x80065470: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x80065470: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_5:
    // 0x80065474: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x80065478: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    // 0x8006547C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80065480: jal         0x80065264
    // 0x80065484: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    alAuxBusNew(rdram, ctx);
        goto after_6;
    // 0x80065484: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    after_6:
    // 0x80065488: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8006548C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065490: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065498: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8006549C: jal         0x800C7D50
    // 0x800654A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_7;
    // 0x800654A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x800654A4: sw          $v0, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r2;
    // 0x800654A8: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800654AC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800654B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800654B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800654B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800654BC: jal         0x800C7D50
    // 0x800654C0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_8;
    // 0x800654C0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_8:
    // 0x800654C4: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x800654C8: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    // 0x800654CC: jal         0x800652C4
    // 0x800654D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alMainBusNew(rdram, ctx);
        goto after_9;
    // 0x800654D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x800654D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800654D8: or          $s1, $fp, $zero
    ctx->r17 = ctx->r30 | 0;
    // 0x800654DC: addiu       $s2, $zero, 0x4C
    ctx->r18 = ADD32(0, 0X4C);
L_800654E0:
    // 0x800654E0: lbu         $t8, 0x1C($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1C);
    // 0x800654E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800654E8: beq         $t8, $zero, L_8006550C
    if (ctx->r24 == 0) {
        // 0x800654EC: sll         $a1, $s0, 16
        ctx->r5 = S32(ctx->r16 << 16);
            goto L_8006550C;
    }
    // 0x800654EC: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x800654F0: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800654F4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800654F8: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800654FC: jal         0x80065AA0
    // 0x80065500: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    alSynAllocFX(rdram, ctx);
        goto after_10;
    // 0x80065500: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_10:
    // 0x80065504: b           L_80065530
    // 0x80065508: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80065530;
    // 0x80065508: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8006550C:
    // 0x8006550C: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065510: lw          $t0, 0x34($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X34);
    // 0x80065514: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x80065518: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8006551C: mflo        $t1
    ctx->r9 = lo;
    // 0x80065520: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    // 0x80065524: jal         0x800CC8F0
    // 0x80065528: nop

    alMainBusParam(rdram, ctx);
        goto after_11;
    // 0x80065528: nop

    after_11:
    // 0x8006552C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80065530:
    // 0x80065530: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80065534: bne         $at, $zero, L_800654E0
    if (ctx->r1 != 0) {
        // 0x80065538: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800654E0;
    }
    // 0x80065538: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006553C: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
    // 0x80065540: sw          $zero, 0x8($s6)
    MEM_W(0X8, ctx->r22) = 0;
    // 0x80065544: sw          $zero, 0x14($s6)
    MEM_W(0X14, ctx->r22) = 0;
    // 0x80065548: sw          $zero, 0x18($s6)
    MEM_W(0X18, ctx->r22) = 0;
    // 0x8006554C: sw          $zero, 0xC($s6)
    MEM_W(0XC, ctx->r22) = 0;
    // 0x80065550: sw          $zero, 0x10($s6)
    MEM_W(0X10, ctx->r22) = 0;
    // 0x80065554: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x80065558: addiu       $t2, $zero, 0xE0
    ctx->r10 = ADD32(0, 0XE0);
    // 0x8006555C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80065560: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065568: jal         0x800C7D50
    // 0x8006556C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_12;
    // 0x8006556C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_12:
    // 0x80065570: lw          $t3, 0x4($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X4);
    // 0x80065574: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80065578: blez        $t3, L_8006563C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8006557C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8006563C;
    }
    // 0x8006557C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80065580: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    // 0x80065584: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x80065588: addiu       $s2, $v0, 0x8C
    ctx->r18 = ADD32(ctx->r2, 0X8C);
    // 0x8006558C: addiu       $s3, $v0, 0x58
    ctx->r19 = ADD32(ctx->r2, 0X58);
    // 0x80065590: addiu       $s4, $v0, 0x10
    ctx->r20 = ADD32(ctx->r2, 0X10);
L_80065594:
    // 0x80065594: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80065598: or          $s5, $s1, $zero
    ctx->r21 = ctx->r17 | 0;
    // 0x8006559C: jal         0x800C8CF0
    // 0x800655A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    alLink(rdram, ctx);
        goto after_13;
    // 0x800655A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x800655A4: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x800655A8: lw          $a1, 0x24($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X24);
    // 0x800655AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800655B0: jal         0x80065138
    // 0x800655B4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alLoadNew(rdram, ctx);
        goto after_14;
    // 0x800655B4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_14:
    // 0x800655B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800655BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800655C0: jal         0x800CBAA0
    // 0x800655C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alLoadParam(rdram, ctx);
        goto after_15;
    // 0x800655C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x800655C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800655CC: jal         0x800651DC
    // 0x800655D0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alResampleNew(rdram, ctx);
        goto after_16;
    // 0x800655D0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_16:
    // 0x800655D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800655D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800655DC: jal         0x800CC5F0
    // 0x800655E0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    alResampleParam(rdram, ctx);
        goto after_17;
    // 0x800655E0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_17:
    // 0x800655E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800655E8: jal         0x80065094
    // 0x800655EC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alEnvmixerNew(rdram, ctx);
        goto after_18;
    // 0x800655EC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_18:
    // 0x800655F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800655F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800655F8: jal         0x800CAFDC
    // 0x800655FC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEnvmixerParam(rdram, ctx);
        goto after_19;
    // 0x800655FC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_19:
    // 0x80065600: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x80065604: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80065608: jal         0x80065C14
    // 0x8006560C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    alAuxBusParam(rdram, ctx);
        goto after_20;
    // 0x8006560C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_20:
    // 0x80065610: addiu       $t4, $s5, 0x8C
    ctx->r12 = ADD32(ctx->r21, 0X8C);
    // 0x80065614: sw          $t4, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r12;
    // 0x80065618: lw          $t5, 0x4($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X4);
    // 0x8006561C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80065620: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80065624: addiu       $s1, $s1, 0xE0
    ctx->r17 = ADD32(ctx->r17, 0XE0);
    // 0x80065628: addiu       $s2, $s2, 0xE0
    ctx->r18 = ADD32(ctx->r18, 0XE0);
    // 0x8006562C: addiu       $s3, $s3, 0xE0
    ctx->r19 = ADD32(ctx->r19, 0XE0);
    // 0x80065630: bne         $at, $zero, L_80065594
    if (ctx->r1 != 0) {
        // 0x80065634: addiu       $s4, $s4, 0xE0
        ctx->r20 = ADD32(ctx->r20, 0XE0);
            goto L_80065594;
    }
    // 0x80065634: addiu       $s4, $s4, 0xE0
    ctx->r20 = ADD32(ctx->r20, 0XE0);
    // 0x80065638: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006563C:
    // 0x8006563C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80065640: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    // 0x80065644: jal         0x800CCA40
    // 0x80065648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    alSaveParam(rdram, ctx);
        goto after_21;
    // 0x80065648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x8006564C: lw          $a3, 0x8($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X8);
    // 0x80065650: addiu       $t6, $zero, 0x1C
    ctx->r14 = ADD32(0, 0X1C);
    // 0x80065654: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065658: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006565C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065660: jal         0x800C7D50
    // 0x80065664: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_22;
    // 0x80065664: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_22:
    // 0x80065668: sw          $zero, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = 0;
    // 0x8006566C: lw          $t7, 0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X8);
    // 0x80065670: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80065674: blez        $t7, L_800656A0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80065678: nop
    
            goto L_800656A0;
    }
    // 0x80065678: nop

L_8006567C:
    // 0x8006567C: lw          $t8, 0x2C($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X2C);
    // 0x80065680: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80065684: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80065688: sw          $v1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r3;
    // 0x8006568C: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x80065690: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80065694: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80065698: bne         $at, $zero, L_8006567C
    if (ctx->r1 != 0) {
        // 0x8006569C: nop
    
            goto L_8006567C;
    }
    // 0x8006569C: nop

L_800656A0:
    // 0x800656A0: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
    // 0x800656A4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800656A8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800656AC: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800656B0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800656B4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800656B8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800656BC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800656C0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800656C4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800656C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800656CC: jr          $ra
    // 0x800656D0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800656D0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void alAudioFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800656D4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800656D8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800656DC: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800656E0: lw          $s2, 0x3D10($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X3D10);
    // 0x800656E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800656E8: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x800656EC: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x800656F0: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800656F4: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800656F8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800656FC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80065700: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80065704: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80065708: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x8006570C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80065710: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80065714: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80065718: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8006571C: bne         $t6, $zero, L_80065730
    if (ctx->r14 != 0) {
        // 0x80065720: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_80065730;
    }
    // 0x80065720: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80065724: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80065728: b           L_8006587C
    // 0x8006572C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006587C;
    // 0x8006572C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80065730:
    // 0x80065730: addiu       $s0, $sp, 0x6C
    ctx->r16 = ADD32(ctx->r29, 0X6C);
    // 0x80065734: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80065738: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006573C: jal         0x80065A2C
    // 0x80065740: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    __nextSampleTime(rdram, ctx);
        goto after_0;
    // 0x80065740: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    after_0:
    // 0x80065744: lw          $t8, 0x20($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X20);
    // 0x80065748: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x8006574C: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x80065750: slt         $at, $t9, $s3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80065754: beq         $at, $zero, L_800657C4
    if (ctx->r1 == 0) {
        // 0x80065758: addiu       $s1, $zero, -0x10
        ctx->r17 = ADD32(0, -0X10);
            goto L_800657C4;
    }
    // 0x80065758: addiu       $s1, $zero, -0x10
    ctx->r17 = ADD32(0, -0X10);
L_8006575C:
    // 0x8006575C: lw          $t0, 0x1C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X1C);
    // 0x80065760: nop

    // 0x80065764: and         $t1, $t0, $s1
    ctx->r9 = ctx->r8 & ctx->r17;
    // 0x80065768: sw          $t1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r9;
    // 0x8006576C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80065770: nop

    // 0x80065774: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80065778: nop

    // 0x8006577C: jalr        $t9
    // 0x80065780: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80065780: nop

    after_1:
    // 0x80065784: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80065788: jal         0x80065994
    // 0x8006578C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _timeToSamplesNoRound(rdram, ctx);
        goto after_2;
    // 0x8006578C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80065790: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80065794: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80065798: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8006579C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800657A0: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800657A4: jal         0x80065A2C
    // 0x800657A8: sw          $t5, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r13;
    __nextSampleTime(rdram, ctx);
        goto after_3;
    // 0x800657A8: sw          $t5, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r13;
    after_3:
    // 0x800657AC: lw          $t6, 0x20($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X20);
    // 0x800657B0: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x800657B4: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x800657B8: slt         $at, $t7, $s3
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800657BC: bne         $at, $zero, L_8006575C
    if (ctx->r1 != 0) {
        // 0x800657C0: nop
    
            goto L_8006575C;
    }
    // 0x800657C0: nop

L_800657C4:
    // 0x800657C4: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    // 0x800657C8: addiu       $s1, $zero, -0x10
    ctx->r17 = ADD32(0, -0X10);
    // 0x800657CC: and         $t0, $t8, $s1
    ctx->r8 = ctx->r24 & ctx->r17;
    // 0x800657D0: blez        $s3, L_8006585C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800657D4: sw          $t0, 0x1C($s2)
        MEM_W(0X1C, ctx->r18) = ctx->r8;
            goto L_8006585C;
    }
    // 0x800657D4: sw          $t0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r8;
    // 0x800657D8: addiu       $s7, $sp, 0x62
    ctx->r23 = ADD32(ctx->r29, 0X62);
    // 0x800657DC: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
L_800657E0:
    // 0x800657E0: lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X48);
    // 0x800657E4: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800657E8: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800657EC: beq         $at, $zero, L_800657FC
    if (ctx->r1 == 0) {
        // 0x800657F0: nop
    
            goto L_800657FC;
    }
    // 0x800657F0: nop

    // 0x800657F4: b           L_800657FC
    // 0x800657F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800657FC;
    // 0x800657F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800657FC:
    // 0x800657FC: sw          $s6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r22;
    // 0x80065800: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x80065804: lw          $s1, 0x38($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X38);
    // 0x80065808: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8006580C: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80065810: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80065814: jalr        $t9
    // 0x80065818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80065818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8006581C: lw          $a3, 0x20($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X20);
    // 0x80065820: addiu       $t1, $s4, 0x8
    ctx->r9 = ADD32(ctx->r20, 0X8);
    // 0x80065824: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80065828: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x8006582C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80065830: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80065834: jalr        $t9
    // 0x80065838: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80065838: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x8006583C: lw          $t5, 0x20($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X20);
    // 0x80065840: subu        $s3, $s3, $s0
    ctx->r19 = SUB32(ctx->r19, ctx->r16);
    // 0x80065844: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80065848: addu        $t3, $t5, $s0
    ctx->r11 = ADD32(ctx->r13, ctx->r16);
    // 0x8006584C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80065850: addu        $s5, $s5, $t4
    ctx->r21 = ADD32(ctx->r21, ctx->r12);
    // 0x80065854: bgtz        $s3, L_800657E0
    if (SIGNED(ctx->r19) > 0) {
        // 0x80065858: sw          $t3, 0x20($s2)
        MEM_W(0X20, ctx->r18) = ctx->r11;
            goto L_800657E0;
    }
    // 0x80065858: sw          $t3, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r11;
L_8006585C:
    // 0x8006585C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80065860: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80065864: subu        $t7, $s4, $t6
    ctx->r15 = SUB32(ctx->r20, ctx->r14);
    // 0x80065868: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8006586C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80065870: jal         0x800658FC
    // 0x80065874: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    _collectPVoices(rdram, ctx);
        goto after_6;
    // 0x80065874: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    after_6:
    // 0x80065878: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_8006587C:
    // 0x8006587C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80065880: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80065884: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80065888: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8006588C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80065890: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80065894: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80065898: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x8006589C: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x800658A0: jr          $ra
    // 0x800658A4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800658A4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void __allocParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800658A8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800658AC: lw          $v0, 0x3D10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3D10);
    // 0x800658B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800658B4: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x800658B8: nop

    // 0x800658BC: beq         $a0, $zero, L_800658D4
    if (ctx->r4 == 0) {
        // 0x800658C0: nop
    
            goto L_800658D4;
    }
    // 0x800658C0: nop

    // 0x800658C4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800658C8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800658CC: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x800658D0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800658D4:
    // 0x800658D4: jr          $ra
    // 0x800658D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800658D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void __freeParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800658DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800658E0: lw          $v0, 0x3D10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3D10);
    // 0x800658E4: nop

    // 0x800658E8: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x800658EC: nop

    // 0x800658F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800658F4: jr          $ra
    // 0x800658F8: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
    return;
    // 0x800658F8: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void _collectPVoices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800658FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80065900: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80065904: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80065908: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006590C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80065910: lw          $s0, 0x14($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X14);
    // 0x80065914: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80065918: beq         $s0, $zero, L_80065944
    if (ctx->r16 == 0) {
        // 0x8006591C: addiu       $s2, $a0, 0x4
        ctx->r18 = ADD32(ctx->r4, 0X4);
            goto L_80065944;
    }
    // 0x8006591C: addiu       $s2, $a0, 0x4
    ctx->r18 = ADD32(ctx->r4, 0X4);
L_80065920:
    // 0x80065920: jal         0x800C8CC0
    // 0x80065924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x80065924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80065928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006592C: jal         0x800C8CF0
    // 0x80065930: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x80065930: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80065934: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    // 0x80065938: nop

    // 0x8006593C: bne         $s0, $zero, L_80065920
    if (ctx->r16 != 0) {
        // 0x80065940: nop
    
            goto L_80065920;
    }
    // 0x80065940: nop

L_80065944:
    // 0x80065944: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80065948: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006594C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80065950: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80065954: jr          $ra
    // 0x80065958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _freePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006595C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065964: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065968: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006596C: jal         0x800C8CC0
    // 0x80065970: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x80065970: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80065974: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80065978: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006597C: jal         0x800C8CF0
    // 0x80065980: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    alLink(rdram, ctx);
        goto after_1;
    // 0x80065980: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
    // 0x80065984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006598C: jr          $ra
    // 0x80065990: nop

    return;
    // 0x80065990: nop

;}
RECOMP_FUNC void _timeToSamplesNoRound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065994: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x80065998: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8006599C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800659A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800659A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800659A8: lwc1        $f5, 0x7450($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X7450);
    // 0x800659AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800659B0: lwc1        $f4, 0x7454($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7454);
    // 0x800659B4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800659B8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800659BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800659C0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800659C4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800659C8: nop

    // 0x800659CC: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x800659D0: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800659D4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800659D8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800659DC: nop

    // 0x800659E0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800659E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800659E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800659EC: nop

    // 0x800659F0: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800659F4: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800659F8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800659FC: jr          $ra
    // 0x80065A00: nop

    return;
    // 0x80065A00: nop

;}
RECOMP_FUNC void _timeToSamples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065A04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065A0C: jal         0x80065994
    // 0x80065A10: nop

    _timeToSamplesNoRound(rdram, ctx);
        goto after_0;
    // 0x80065A10: nop

    after_0:
    // 0x80065A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065A18: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80065A1C: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x80065A20: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065A24: jr          $ra
    // 0x80065A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80065A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void __nextSampleTime(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065A2C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80065A30: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80065A34: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80065A38: beq         $v1, $zero, L_80065A84
    if (ctx->r3 == 0) {
        // 0x80065A3C: ori         $v0, $v0, 0xFFFF
        ctx->r2 = ctx->r2 | 0XFFFF;
            goto L_80065A84;
    }
    // 0x80065A3C: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80065A40: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x80065A44: nop

L_80065A48:
    // 0x80065A48: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x80065A4C: nop

    // 0x80065A50: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x80065A54: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80065A58: beq         $at, $zero, L_80065A74
    if (ctx->r1 == 0) {
        // 0x80065A5C: nop
    
            goto L_80065A74;
    }
    // 0x80065A5C: nop

    // 0x80065A60: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80065A64: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x80065A68: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x80065A6C: nop

    // 0x80065A70: subu        $v0, $t8, $a2
    ctx->r2 = SUB32(ctx->r24, ctx->r6);
L_80065A74:
    // 0x80065A74: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80065A78: nop

    // 0x80065A7C: bne         $v1, $zero, L_80065A48
    if (ctx->r3 != 0) {
        // 0x80065A80: nop
    
            goto L_80065A48;
    }
    // 0x80065A80: nop

L_80065A84:
    // 0x80065A84: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80065A88: nop

    // 0x80065A8C: lw          $v0, 0x10($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X10);
    // 0x80065A90: jr          $ra
    // 0x80065A94: nop

    return;
    // 0x80065A94: nop

    // 0x80065A98: nop

    // 0x80065A9C: nop

;}
RECOMP_FUNC void alSynAllocFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065AA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065AA4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80065AA8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065AAC: lh          $a2, 0x26($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X26);
    // 0x80065AB0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80065AB4: sll         $s1, $a2, 2
    ctx->r17 = S32(ctx->r6 << 2);
    // 0x80065AB8: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x80065ABC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065AC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80065AC4: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80065AC8: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x80065ACC: subu        $s1, $s1, $a2
    ctx->r17 = SUB32(ctx->r17, ctx->r6);
    // 0x80065AD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80065AD4: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80065AD8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80065ADC: addu        $a0, $t6, $s1
    ctx->r4 = ADD32(ctx->r14, ctx->r17);
    // 0x80065AE0: jal         0x80064C48
    // 0x80065AE4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    alFxNew(rdram, ctx);
        goto after_0;
    // 0x80065AE4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x80065AE8: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    // 0x80065AEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80065AF0: addu        $a2, $t7, $s1
    ctx->r6 = ADD32(ctx->r15, ctx->r17);
    // 0x80065AF4: jal         0x800641D4
    // 0x80065AF8: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    alFxParam(rdram, ctx);
        goto after_1;
    // 0x80065AF8: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    after_1:
    // 0x80065AFC: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x80065B00: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80065B04: addu        $a2, $t8, $s1
    ctx->r6 = ADD32(ctx->r24, ctx->r17);
    // 0x80065B08: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x80065B0C: jal         0x800CC8F0
    // 0x80065B10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    alMainBusParam(rdram, ctx);
        goto after_2;
    // 0x80065B10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80065B14: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x80065B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065B1C: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x80065B20: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80065B24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80065B28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065B2C: jr          $ra
    // 0x80065B30: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    return;
    // 0x80065B30: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80065B34: nop

    // 0x80065B38: nop

    // 0x80065B3C: nop

;}
RECOMP_FUNC void alAuxBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065B40: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80065B44: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80065B48: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x80065B4C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80065B50: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80065B54: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80065B58: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80065B5C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80065B60: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80065B64: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80065B68: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80065B6C: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x80065B70: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80065B74: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x80065B78: ori         $t6, $t6, 0x6C0
    ctx->r14 = ctx->r14 | 0X6C0;
    // 0x80065B7C: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x80065B80: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80065B84: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80065B88: sw          $t7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r15;
    // 0x80065B8C: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80065B90: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x80065B94: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80065B98: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80065B9C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80065BA0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80065BA4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80065BA8: blez        $t8, L_80065BE8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80065BAC: addiu       $s2, $s1, 0x10
        ctx->r18 = ADD32(ctx->r17, 0X10);
            goto L_80065BE8;
    }
    // 0x80065BAC: addiu       $s2, $s1, 0x10
    ctx->r18 = ADD32(ctx->r17, 0X10);
    // 0x80065BB0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_80065BB4:
    // 0x80065BB4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80065BB8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80065BBC: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80065BC0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80065BC4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80065BC8: jalr        $t9
    // 0x80065BCC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80065BCC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_0:
    // 0x80065BD0: lw          $t0, 0x14($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X14);
    // 0x80065BD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80065BD8: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80065BDC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80065BE0: bne         $at, $zero, L_80065BB4
    if (ctx->r1 != 0) {
        // 0x80065BE4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80065BB4;
    }
    // 0x80065BE4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80065BE8:
    // 0x80065BE8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80065BEC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80065BF0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80065BF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80065BF8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80065BFC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80065C00: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80065C04: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80065C08: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80065C0C: jr          $ra
    // 0x80065C10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80065C10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void alAuxBusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065C14: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80065C18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80065C1C: beq         $a1, $at, L_80065C38
    if (ctx->r5 == ctx->r1) {
        // 0x80065C20: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80065C38;
    }
    // 0x80065C20: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80065C24: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80065C28: beq         $a1, $at, L_80065C60
    if (ctx->r5 == ctx->r1) {
        // 0x80065C2C: nop
    
            goto L_80065C60;
    }
    // 0x80065C2C: nop

    // 0x80065C30: jr          $ra
    // 0x80065C34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80065C34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80065C38:
    // 0x80065C38: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80065C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80065C40: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80065C44: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80065C48: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x80065C4C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x80065C50: nop

    // 0x80065C54: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80065C58: jr          $ra
    // 0x80065C5C: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    return;
    // 0x80065C5C: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_80065C60:
    // 0x80065C60: lw          $t1, 0x14($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14);
    // 0x80065C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065C68: blez        $t1, L_80065CB8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80065C6C: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80065CB8;
    }
    // 0x80065C6C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_80065C70:
    // 0x80065C70: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80065C74: nop

    // 0x80065C78: bne         $a2, $t2, L_80065CA4
    if (ctx->r6 != ctx->r10) {
        // 0x80065C7C: nop
    
            goto L_80065CA4;
    }
    // 0x80065C7C: nop

    // 0x80065C80: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80065C84: nop

    // 0x80065C88: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80065C8C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80065C90: sw          $t4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r12;
    // 0x80065C94: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80065C98: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80065C9C: nop

    // 0x80065CA0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_80065CA4:
    // 0x80065CA4: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x80065CA8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80065CAC: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80065CB0: bne         $at, $zero, L_80065C70
    if (ctx->r1 != 0) {
        // 0x80065CB4: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80065C70;
    }
    // 0x80065CB4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80065CB8:
    // 0x80065CB8: jr          $ra
    // 0x80065CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80065CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80065A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065CC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065CC4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065CCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80065CD0: lbu         $v0, 0xDC($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XDC);
    // 0x80065CD4: lh          $t6, 0x2A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2A);
    // 0x80065CD8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80065CDC: beq         $t6, $v0, L_80065D50
    if (ctx->r14 == ctx->r2) {
        // 0x80065CE0: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80065D50;
    }
    // 0x80065CE0: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80065CE4: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80065CE8: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x80065CEC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80065CF0: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80065CF4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80065CF8: addiu       $a2, $a3, 0x8C
    ctx->r6 = ADD32(ctx->r7, 0X8C);
    // 0x80065CFC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80065D00: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80065D04: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80065D08: jal         0x80065C14
    // 0x80065D0C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    alAuxBusParam(rdram, ctx);
        goto after_0;
    // 0x80065D0C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80065D10: lh          $t2, 0x2A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2A);
    // 0x80065D14: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80065D18: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80065D1C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80065D20: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80065D24: lw          $t1, 0x34($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X34);
    // 0x80065D28: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80065D2C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80065D30: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80065D34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80065D38: jal         0x80065C14
    // 0x80065D3C: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    alAuxBusParam(rdram, ctx);
        goto after_1;
    // 0x80065D3C: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    after_1:
    // 0x80065D40: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x80065D44: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80065D48: nop

    // 0x80065D4C: sb          $t4, 0xDC($t5)
    MEM_B(0XDC, ctx->r13) = ctx->r12;
L_80065D50:
    // 0x80065D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065D54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065D58: jr          $ra
    // 0x80065D5C: nop

    return;
    // 0x80065D5C: nop

;}
RECOMP_FUNC void alSynSetPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065D60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065D68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80065D6C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80065D70: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065D74: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80065D78: nop

    // 0x80065D7C: beq         $t7, $zero, L_80065DFC
    if (ctx->r15 == 0) {
        // 0x80065D80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80065DFC;
    }
    // 0x80065D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065D84: jal         0x800658A8
    // 0x80065D88: nop

    __allocParam(rdram, ctx);
        goto after_0;
    // 0x80065D88: nop

    after_0:
    // 0x80065D8C: beq         $v0, $zero, L_80065DF8
    if (ctx->r2 == 0) {
        // 0x80065D90: addiu       $t4, $zero, 0xC
        ctx->r12 = ADD32(0, 0XC);
            goto L_80065DF8;
    }
    // 0x80065D90: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80065D94: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80065D98: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80065D9C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80065DA0: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x80065DA4: lw          $t2, 0xD8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XD8);
    // 0x80065DA8: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
    // 0x80065DAC: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80065DB0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80065DB4: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x80065DB8: jal         0x80065E2C
    // 0x80065DBC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    modify_panning(rdram, ctx);
        goto after_1;
    // 0x80065DBC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80065DC0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80065DC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80065DC8: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x80065DCC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80065DD0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80065DD4: nop

    // 0x80065DD8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80065DDC: nop

    // 0x80065DE0: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x80065DE4: nop

    // 0x80065DE8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80065DEC: nop

    // 0x80065DF0: jalr        $t9
    // 0x80065DF4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80065DF4: nop

    after_2:
L_80065DF8:
    // 0x80065DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80065DFC:
    // 0x80065DFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065E00: jr          $ra
    // 0x80065E04: nop

    return;
    // 0x80065E04: nop

    // 0x80065E08: nop

    // 0x80065E0C: nop

;}
RECOMP_FUNC void set_stereo_pan_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80065E14: jr          $ra
    // 0x80065E18: sh          $a0, -0x2A40($at)
    MEM_H(-0X2A40, ctx->r1) = ctx->r4;
    return;
    // 0x80065E18: sh          $a0, -0x2A40($at)
    MEM_H(-0X2A40, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void get_stereo_pan_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E1C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80065E20: lh          $v0, -0x2A40($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2A40);
    // 0x80065E24: jr          $ra
    // 0x80065E28: nop

    return;
    // 0x80065E28: nop

;}
RECOMP_FUNC void modify_panning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E2C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80065E30: lh          $v0, -0x2A40($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2A40);
    // 0x80065E34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80065E38: beq         $v0, $zero, L_80065E58
    if (ctx->r2 == 0) {
        // 0x80065E3C: nop
    
            goto L_80065E58;
    }
    // 0x80065E3C: nop

    // 0x80065E40: beq         $v0, $at, L_80065E6C
    if (ctx->r2 == ctx->r1) {
        // 0x80065E44: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80065E6C;
    }
    // 0x80065E44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80065E48: beq         $v0, $at, L_80065E60
    if (ctx->r2 == ctx->r1) {
        // 0x80065E4C: addiu       $a0, $a0, -0x40
        ctx->r4 = ADD32(ctx->r4, -0X40);
            goto L_80065E60;
    }
    // 0x80065E4C: addiu       $a0, $a0, -0x40
    ctx->r4 = ADD32(ctx->r4, -0X40);
    // 0x80065E50: b           L_80065E70
    // 0x80065E54: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
        goto L_80065E70;
    // 0x80065E54: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80065E58:
    // 0x80065E58: jr          $ra
    // 0x80065E5C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80065E5C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80065E60:
    // 0x80065E60: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80065E64: jr          $ra
    // 0x80065E68: addiu       $v0, $t6, 0x40
    ctx->r2 = ADD32(ctx->r14, 0X40);
    return;
    // 0x80065E68: addiu       $v0, $t6, 0x40
    ctx->r2 = ADD32(ctx->r14, 0X40);
L_80065E6C:
    // 0x80065E6C: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80065E70:
    // 0x80065E70: jr          $ra
    // 0x80065E74: nop

    return;
    // 0x80065E74: nop

;}
RECOMP_FUNC void alSynStartVoiceParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    _syn_start_params_calls++;
    if (_syn_start_params_calls <= 30 || (_syn_start_params_calls % 200) == 0) {
        gpr wt = ctx->r6;
        int32_t wt_ptr = (int32_t)wt;
        int32_t wbase = 0, wlen = 0;
        uint8_t wtype = 0;
        if (wt_ptr != 0) { wbase = MEM_W(0x00, wt); wlen = MEM_W(0x04, wt); wtype = MEM_BU(0x08, wt); }
        int32_t pv = MEM_W(0x08, ctx->r5);
        fprintf(stderr, "[SYN-PARAMS #%d] synth=0x%08X voice=0x%08X(pv=0x%08X) wt=0x%08X base=0x%08X len=%d type=%d\n",
            _syn_start_params_calls, (int32_t)ctx->r4, (int32_t)ctx->r5, pv, wt_ptr, wbase, wlen, wtype);
        fflush(stderr);
    }
    // 0x80065E78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065E80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80065E84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80065E88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065E8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80065E90: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80065E94: nop

    // 0x80065E98: beq         $t7, $zero, L_80065F74
    if (ctx->r15 == 0) {
        // 0x80065E9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80065F74;
    }
    // 0x80065E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065EA0: jal         0x800658A8
    // 0x80065EA4: nop

    __allocParam(rdram, ctx);
        goto after_0;
    // 0x80065EA4: nop

    after_0:
    // 0x80065EA8: beq         $v0, $zero, L_80065F70
    if (ctx->r2 == 0) {
        // 0x80065EAC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80065F70;
    }
    // 0x80065EAC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80065EB0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80065EB4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80065EB8: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80065EBC: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x80065EC0: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x80065EC4: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x80065EC8: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80065ECC: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x80065ED0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80065ED4: sh          $t3, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r11;
    // 0x80065ED8: lh          $t4, 0x1A($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X1A);
    // 0x80065EDC: nop

    // 0x80065EE0: sh          $t4, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r12;
    // 0x80065EE4: lbu         $a0, 0x37($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X37);
    // 0x80065EE8: jal         0x80065E2C
    // 0x80065EEC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    modify_panning(rdram, ctx);
        goto after_1;
    // 0x80065EEC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80065EF0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80065EF4: nop

    // 0x80065EF8: sb          $v0, 0x12($a2)
    MEM_B(0X12, ctx->r6) = ctx->r2;
    // 0x80065EFC: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x80065F00: nop

    // 0x80065F04: sh          $t5, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r13;
    // 0x80065F08: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x80065F0C: nop

    // 0x80065F10: sb          $t6, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r14;
    // 0x80065F14: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80065F18: nop

    // 0x80065F1C: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x80065F20: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80065F24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80065F28: jal         0x80065A04
    // 0x80065F2C: nop

    _timeToSamples(rdram, ctx);
        goto after_2;
    // 0x80065F2C: nop

    after_2:
    // 0x80065F30: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80065F34: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80065F38: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x80065F3C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80065F40: nop

    // 0x80065F44: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x80065F48: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80065F4C: nop

    // 0x80065F50: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80065F54: nop

    // 0x80065F58: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x80065F5C: nop

    // 0x80065F60: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80065F64: nop

    // 0x80065F68: jalr        $t9
    // 0x80065F6C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80065F6C: nop

    after_3:
L_80065F70:
    // 0x80065F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80065F74:
    // 0x80065F74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065F78: jr          $ra
    // 0x80065F7C: nop

    return;
    // 0x80065F7C: nop

;}
RECOMP_FUNC void mainproc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065F80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065F84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065F88: jal         0x800CCB00
    // 0x80065F8C: nop

    osInitialize_recomp(rdram, ctx);
        goto after_0;
    // 0x80065F8C: nop

    after_0:
    // 0x80065F90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80065F94: addiu       $t6, $t6, -0x2330
    ctx->r14 = ADD32(ctx->r14, -0X2330);
    // 0x80065F98: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80065F9C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80065FA0: addiu       $a2, $a2, 0x5FD8
    ctx->r6 = ADD32(ctx->r6, 0X5FD8);
    // 0x80065FA4: addiu       $a0, $a0, -0x320
    ctx->r4 = ADD32(ctx->r4, -0X320);
    // 0x80065FA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065FAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80065FB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80065FB4: jal         0x800C8DB0
    // 0x80065FB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80065FB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x80065FBC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80065FC0: jal         0x800C8F00
    // 0x80065FC4: addiu       $a0, $a0, -0x320
    ctx->r4 = ADD32(ctx->r4, -0X320);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80065FC4: addiu       $a0, $a0, -0x320
    ctx->r4 = ADD32(ctx->r4, -0X320);
    after_2:
    // 0x80065FC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065FCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065FD0: jr          $ra
    // 0x80065FD4: nop

    return;
    // 0x80065FD4: nop

;}
RECOMP_FUNC void thread1_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065FD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065FDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065FE0: jal         0x800B74B0
    // 0x80065FE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    thread0_create(rdram, ctx);
        goto after_0;
    // 0x80065FE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80065FE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80065FEC: addiu       $t6, $t6, -0x328
    ctx->r14 = ADD32(ctx->r14, -0X328);
    // 0x80065FF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80065FF4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80065FF8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80065FFC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80066000: addiu       $a2, $a2, -0x3A90
    ctx->r6 = ADD32(ctx->r6, -0X3A90);
    // 0x80066004: addiu       $a0, $a0, -0x170
    ctx->r4 = ADD32(ctx->r4, -0X170);
    // 0x80066008: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8006600C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80066010: jal         0x800C8DB0
    // 0x80066014: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80066014: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80066018: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006601C: addiu       $v0, $v0, -0x2328
    ctx->r2 = ADD32(ctx->r2, -0X2328);
    // 0x80066020: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80066024: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80066028: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8006602C: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80066030: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80066034: sw          $t9, 0x2004($v0)
    MEM_W(0X2004, ctx->r2) = ctx->r25;
    // 0x80066038: sw          $t8, 0x2000($v0)
    MEM_W(0X2000, ctx->r2) = ctx->r24;
    // 0x8006603C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80066040: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80066044: jal         0x800C8F00
    // 0x80066048: addiu       $a0, $a0, -0x170
    ctx->r4 = ADD32(ctx->r4, -0X170);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80066048: addiu       $a0, $a0, -0x170
    ctx->r4 = ADD32(ctx->r4, -0X170);
    after_2:
    // 0x8006604C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80066050: jal         0x800CCDA0
    // 0x80066054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_3;
    // 0x80066054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_80066058:
    // 0x80066058: b           L_80066058
    pause_self(rdram);
    // 0x8006605C: nop

    // 0x80066060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066064: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80066068: jr          $ra
    // 0x8006606C: nop

    return;
    // 0x8006606C: nop

;}
RECOMP_FUNC void thread3_verify_stack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066070: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066074: addiu       $v0, $v0, -0x2328
    ctx->r2 = ADD32(ctx->r2, -0X2328);
    // 0x80066078: lw          $t7, 0x2004($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2004);
    // 0x8006607C: lw          $t6, 0x2000($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2000);
    // 0x80066080: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80066084: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80066088: sltiu       $at, $t9, 0x1
    ctx->r1 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006608C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80066090: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x80066094: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80066098: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006609C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800660A0: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x800660A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800660A8: sw          $t8, 0x2000($v0)
    MEM_W(0X2000, ctx->r2) = ctx->r24;
    // 0x800660AC: sw          $t9, 0x2004($v0)
    MEM_W(0X2004, ctx->r2) = ctx->r25;
    // 0x800660B0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800660B4: bne         $t8, $t2, L_800660C0
    if (ctx->r24 != ctx->r10) {
        // 0x800660B8: sw          $t3, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r11;
            goto L_800660C0;
    }
    // 0x800660B8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800660BC: beq         $t9, $t3, L_800660CC
    if (ctx->r25 == ctx->r11) {
        // 0x800660C0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800660CC;
    }
L_800660C0:
    // 0x800660C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800660C4: jal         0x800CA2B4
    // 0x800660C8: addiu       $a0, $a0, 0x7460
    ctx->r4 = ADD32(ctx->r4, 0X7460);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800660C8: addiu       $a0, $a0, 0x7460
    ctx->r4 = ADD32(ctx->r4, 0X7460);
    after_0:
L_800660CC:
    // 0x800660CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800660D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800660D4: jr          $ra
    // 0x800660D8: nop

    return;
    // 0x800660D8: nop

    // 0x800660DC: nop

;}
