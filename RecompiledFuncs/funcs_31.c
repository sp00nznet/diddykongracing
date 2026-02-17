#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void get_next_particle_behaviour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4B24: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B4B28: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800B4B2C: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x800B4B30: addiu       $a1, $a1, 0x3284
    ctx->r5 = ADD32(ctx->r5, 0X3284);
    // 0x800B4B34: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B4B38: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B4B3C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B4B40: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B4B44: bne         $at, $zero, L_800B4B64
    if (ctx->r1 != 0) {
        // 0x800B4B48: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_800B4B64;
    }
    // 0x800B4B48: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_800B4B4C:
    // 0x800B4B4C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B4B50: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B4B54: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800B4B58: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B4B5C: beq         $at, $zero, L_800B4B4C
    if (ctx->r1 == 0) {
        // 0x800B4B60: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_800B4B4C;
    }
    // 0x800B4B60: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_800B4B64:
    // 0x800B4B64: lw          $t9, 0x328C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X328C);
    // 0x800B4B68: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B4B6C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B4B70: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800B4B74: jr          $ra
    // 0x800B4B78: nop

    return;
    // 0x800B4B78: nop

;}
RECOMP_FUNC void get_previous_particle_behaviour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4B7C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B4B80: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B4B84: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x800B4B88: bgez        $v1, L_800B4BB0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B4B8C: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_800B4BB0;
    }
    // 0x800B4B8C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B4B90: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B4B94: addiu       $v0, $v0, 0x3284
    ctx->r2 = ADD32(ctx->r2, 0X3284);
L_800B4B98:
    // 0x800B4B98: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B4B9C: nop

    // 0x800B4BA0: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800B4BA4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B4BA8: bltz        $t9, L_800B4B98
    if (SIGNED(ctx->r25) < 0) {
        // 0x800B4BAC: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800B4B98;
    }
    // 0x800B4BAC: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_800B4BB0:
    // 0x800B4BB0: lw          $t0, 0x328C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X328C);
    // 0x800B4BB4: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800B4BB8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B4BBC: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800B4BC0: jr          $ra
    // 0x800B4BC4: nop

    return;
    // 0x800B4BC4: nop

;}
RECOMP_FUNC void increase_emitter_opacity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4BC8: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x800B4BCC: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x800B4BD0: addu        $t0, $t7, $v1
    ctx->r8 = ADD32(ctx->r15, ctx->r3);
    // 0x800B4BD4: lh          $t8, 0xA($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XA);
    // 0x800B4BD8: sll         $t6, $a3, 8
    ctx->r14 = S32(ctx->r7 << 8);
    // 0x800B4BDC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800B4BE0: addu        $v0, $t9, $a2
    ctx->r2 = ADD32(ctx->r25, ctx->r6);
    // 0x800B4BE4: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B4BE8: beq         $at, $zero, L_800B4BF8
    if (ctx->r1 == 0) {
        // 0x800B4BEC: nop
    
            goto L_800B4BF8;
    }
    // 0x800B4BEC: nop

    // 0x800B4BF0: b           L_800B4BFC
    // 0x800B4BF4: sh          $t6, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r14;
        goto L_800B4BFC;
    // 0x800B4BF4: sh          $t6, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r14;
L_800B4BF8:
    // 0x800B4BF8: sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
L_800B4BFC:
    // 0x800B4BFC: lw          $t1, 0x6C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X6C);
    // 0x800B4C00: nop

    // 0x800B4C04: addu        $t0, $t1, $v1
    ctx->r8 = ADD32(ctx->r9, ctx->r3);
    // 0x800B4C08: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x800B4C0C: nop

    // 0x800B4C10: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x800B4C14: jr          $ra
    // 0x800B4C18: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    return;
    // 0x800B4C18: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
;}
RECOMP_FUNC void decrease_emitter_opacity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4C1C: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x800B4C20: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x800B4C24: addu        $t0, $t7, $v1
    ctx->r8 = ADD32(ctx->r15, ctx->r3);
    // 0x800B4C28: lh          $t8, 0xA($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XA);
    // 0x800B4C2C: sll         $t6, $a3, 8
    ctx->r14 = S32(ctx->r7 << 8);
    // 0x800B4C30: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800B4C34: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x800B4C38: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B4C3C: beq         $at, $zero, L_800B4C4C
    if (ctx->r1 == 0) {
        // 0x800B4C40: nop
    
            goto L_800B4C4C;
    }
    // 0x800B4C40: nop

    // 0x800B4C44: b           L_800B4C50
    // 0x800B4C48: sh          $t6, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r14;
        goto L_800B4C50;
    // 0x800B4C48: sh          $t6, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r14;
L_800B4C4C:
    // 0x800B4C4C: sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
L_800B4C50:
    // 0x800B4C50: lw          $t1, 0x6C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X6C);
    // 0x800B4C54: nop

    // 0x800B4C58: addu        $t0, $t1, $v1
    ctx->r8 = ADD32(ctx->r9, ctx->r3);
    // 0x800B4C5C: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x800B4C60: nop

    // 0x800B4C64: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x800B4C68: jr          $ra
    // 0x800B4C6C: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    return;
    // 0x800B4C6C: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
;}
RECOMP_FUNC void strcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4C70: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4C74: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800B4C78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4C7C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4C80: beq         $v0, $zero, L_800B4C9C
    if (ctx->r2 == 0) {
        // 0x800B4C84: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_800B4C9C;
    }
    // 0x800B4C84: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800B4C88:
    // 0x800B4C88: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4C8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4C90: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4C94: bne         $v0, $zero, L_800B4C88
    if (ctx->r2 != 0) {
        // 0x800B4C98: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_800B4C88;
    }
    // 0x800B4C98: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800B4C9C:
    // 0x800B4C9C: jr          $ra
    // 0x800B4CA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B4CA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void strcat_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4CA4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800B4CA8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800B4CAC: beq         $t6, $zero, L_800B4CC4
    if (ctx->r14 == 0) {
        // 0x800B4CB0: nop
    
            goto L_800B4CC4;
    }
    // 0x800B4CB0: nop

L_800B4CB4:
    // 0x800B4CB4: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x800B4CB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4CBC: bne         $t7, $zero, L_800B4CB4
    if (ctx->r15 != 0) {
        // 0x800B4CC0: nop
    
            goto L_800B4CB4;
    }
    // 0x800B4CC0: nop

L_800B4CC4:
    // 0x800B4CC4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4CC8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4CCC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4CD0: beq         $v0, $zero, L_800B4CEC
    if (ctx->r2 == 0) {
        // 0x800B4CD4: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_800B4CEC;
    }
    // 0x800B4CD4: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800B4CD8:
    // 0x800B4CD8: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4CDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4CE0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4CE4: bne         $v0, $zero, L_800B4CD8
    if (ctx->r2 != 0) {
        // 0x800B4CE8: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_800B4CD8;
    }
    // 0x800B4CE8: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800B4CEC:
    // 0x800B4CEC: jr          $ra
    // 0x800B4CF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B4CF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void strcasecmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4CF4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800B4CF8: nop

    // 0x800B4CFC: bne         $v0, $zero, L_800B4D14
    if (ctx->r2 != 0) {
        // 0x800B4D00: andi        $a2, $v0, 0xFF
        ctx->r6 = ctx->r2 & 0XFF;
            goto L_800B4D14;
    }
    // 0x800B4D00: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x800B4D04: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4D08: nop

    // 0x800B4D0C: beq         $t6, $zero, L_800B4D9C
    if (ctx->r14 == 0) {
        // 0x800B4D10: andi        $a2, $v0, 0xFF
        ctx->r6 = ctx->r2 & 0XFF;
            goto L_800B4D9C;
    }
L_800B4D10:
    // 0x800B4D10: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_800B4D14:
    // 0x800B4D14: slti        $at, $a2, 0x61
    ctx->r1 = SIGNED(ctx->r6) < 0X61 ? 1 : 0;
    // 0x800B4D18: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4D1C: bne         $at, $zero, L_800B4D34
    if (ctx->r1 != 0) {
        // 0x800B4D20: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800B4D34;
    }
    // 0x800B4D20: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800B4D24: slti        $at, $a2, 0x7B
    ctx->r1 = SIGNED(ctx->r6) < 0X7B ? 1 : 0;
    // 0x800B4D28: beq         $at, $zero, L_800B4D34
    if (ctx->r1 == 0) {
        // 0x800B4D2C: addiu       $a2, $a2, -0x20
        ctx->r6 = ADD32(ctx->r6, -0X20);
            goto L_800B4D34;
    }
    // 0x800B4D2C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800B4D30: andi        $a3, $a2, 0xFF
    ctx->r7 = ctx->r6 & 0XFF;
L_800B4D34:
    // 0x800B4D34: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800B4D38: slti        $at, $v0, 0x61
    ctx->r1 = SIGNED(ctx->r2) < 0X61 ? 1 : 0;
    // 0x800B4D3C: bne         $at, $zero, L_800B4D54
    if (ctx->r1 != 0) {
        // 0x800B4D40: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800B4D54;
    }
    // 0x800B4D40: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800B4D44: slti        $at, $v0, 0x7B
    ctx->r1 = SIGNED(ctx->r2) < 0X7B ? 1 : 0;
    // 0x800B4D48: beq         $at, $zero, L_800B4D54
    if (ctx->r1 == 0) {
        // 0x800B4D4C: addiu       $v0, $v0, -0x20
        ctx->r2 = ADD32(ctx->r2, -0X20);
            goto L_800B4D54;
    }
    // 0x800B4D4C: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x800B4D50: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_800B4D54:
    // 0x800B4D54: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800B4D58: beq         $at, $zero, L_800B4D6C
    if (ctx->r1 == 0) {
        // 0x800B4D5C: slt         $at, $a2, $a3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800B4D6C;
    }
    // 0x800B4D5C: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800B4D60: jr          $ra
    // 0x800B4D64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800B4D64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B4D68: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
L_800B4D6C:
    // 0x800B4D6C: beq         $at, $zero, L_800B4D7C
    if (ctx->r1 == 0) {
        // 0x800B4D70: nop
    
            goto L_800B4D7C;
    }
    // 0x800B4D70: nop

    // 0x800B4D74: jr          $ra
    // 0x800B4D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800B4D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B4D7C:
    // 0x800B4D7C: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x800B4D80: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4D84: bne         $v0, $zero, L_800B4D10
    if (ctx->r2 != 0) {
        // 0x800B4D88: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800B4D10;
    }
    // 0x800B4D88: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4D8C: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4D90: nop

    // 0x800B4D94: bne         $t9, $zero, L_800B4D14
    if (ctx->r25 != 0) {
        // 0x800B4D98: andi        $a2, $v0, 0xFF
        ctx->r6 = ctx->r2 & 0XFF;
            goto L_800B4D14;
    }
    // 0x800B4D98: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_800B4D9C:
    // 0x800B4D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4DA0: jr          $ra
    // 0x800B4DA4: nop

    return;
    // 0x800B4DA4: nop

;}
RECOMP_FUNC void strncasecmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4DA8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800B4DAC: nop

    // 0x800B4DB0: bne         $v0, $zero, L_800B4DC8
    if (ctx->r2 != 0) {
        // 0x800B4DB4: nop
    
            goto L_800B4DC8;
    }
    // 0x800B4DB4: nop

    // 0x800B4DB8: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4DBC: nop

    // 0x800B4DC0: beq         $t6, $zero, L_800B4E60
    if (ctx->r14 == 0) {
        // 0x800B4DC4: nop
    
            goto L_800B4E60;
    }
    // 0x800B4DC4: nop

L_800B4DC8:
    // 0x800B4DC8: beq         $a2, $zero, L_800B4E60
    if (ctx->r6 == 0) {
        // 0x800B4DCC: andi        $a3, $v0, 0xFF
        ctx->r7 = ctx->r2 & 0XFF;
            goto L_800B4E60;
    }
    // 0x800B4DCC: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
L_800B4DD0:
    // 0x800B4DD0: slti        $at, $a3, 0x61
    ctx->r1 = SIGNED(ctx->r7) < 0X61 ? 1 : 0;
    // 0x800B4DD4: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4DD8: bne         $at, $zero, L_800B4DF0
    if (ctx->r1 != 0) {
        // 0x800B4DDC: or          $t0, $a3, $zero
        ctx->r8 = ctx->r7 | 0;
            goto L_800B4DF0;
    }
    // 0x800B4DDC: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800B4DE0: slti        $at, $a3, 0x7B
    ctx->r1 = SIGNED(ctx->r7) < 0X7B ? 1 : 0;
    // 0x800B4DE4: beq         $at, $zero, L_800B4DF0
    if (ctx->r1 == 0) {
        // 0x800B4DE8: addiu       $a3, $a3, -0x20
        ctx->r7 = ADD32(ctx->r7, -0X20);
            goto L_800B4DF0;
    }
    // 0x800B4DE8: addiu       $a3, $a3, -0x20
    ctx->r7 = ADD32(ctx->r7, -0X20);
    // 0x800B4DEC: andi        $t0, $a3, 0xFF
    ctx->r8 = ctx->r7 & 0XFF;
L_800B4DF0:
    // 0x800B4DF0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800B4DF4: slti        $at, $v0, 0x61
    ctx->r1 = SIGNED(ctx->r2) < 0X61 ? 1 : 0;
    // 0x800B4DF8: bne         $at, $zero, L_800B4E10
    if (ctx->r1 != 0) {
        // 0x800B4DFC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B4E10;
    }
    // 0x800B4DFC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B4E00: slti        $at, $v0, 0x7B
    ctx->r1 = SIGNED(ctx->r2) < 0X7B ? 1 : 0;
    // 0x800B4E04: beq         $at, $zero, L_800B4E10
    if (ctx->r1 == 0) {
        // 0x800B4E08: addiu       $v0, $v0, -0x20
        ctx->r2 = ADD32(ctx->r2, -0X20);
            goto L_800B4E10;
    }
    // 0x800B4E08: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x800B4E0C: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
L_800B4E10:
    // 0x800B4E10: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800B4E14: beq         $at, $zero, L_800B4E24
    if (ctx->r1 == 0) {
        // 0x800B4E18: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800B4E24;
    }
    // 0x800B4E18: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4E1C: jr          $ra
    // 0x800B4E20: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800B4E20: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B4E24:
    // 0x800B4E24: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B4E28: beq         $at, $zero, L_800B4E38
    if (ctx->r1 == 0) {
        // 0x800B4E2C: nop
    
            goto L_800B4E38;
    }
    // 0x800B4E2C: nop

    // 0x800B4E30: jr          $ra
    // 0x800B4E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800B4E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B4E38:
    // 0x800B4E38: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800B4E3C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4E40: bne         $v0, $zero, L_800B4E58
    if (ctx->r2 != 0) {
        // 0x800B4E44: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800B4E58;
    }
    // 0x800B4E44: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800B4E48: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4E4C: nop

    // 0x800B4E50: beq         $t9, $zero, L_800B4E60
    if (ctx->r25 == 0) {
        // 0x800B4E54: nop
    
            goto L_800B4E60;
    }
    // 0x800B4E54: nop

L_800B4E58:
    // 0x800B4E58: bne         $a2, $zero, L_800B4DD0
    if (ctx->r6 != 0) {
        // 0x800B4E5C: andi        $a3, $v0, 0xFF
        ctx->r7 = ctx->r2 & 0XFF;
            goto L_800B4DD0;
    }
    // 0x800B4E5C: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
L_800B4E60:
    // 0x800B4E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4E64: jr          $ra
    // 0x800B4E68: nop

    return;
    // 0x800B4E68: nop

;}
RECOMP_FUNC void memset_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4E6C: sltiu       $v1, $a2, 0x1
    ctx->r3 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x800B4E70: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x800B4E74: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800B4E78: beq         $v1, $zero, L_800B4E98
    if (ctx->r3 == 0) {
        // 0x800B4E7C: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800B4E98;
    }
    // 0x800B4E7C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800B4E80:
    // 0x800B4E80: sltiu       $v1, $a2, 0x1
    ctx->r3 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x800B4E84: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x800B4E88: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800B4E8C: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800B4E90: bne         $v1, $zero, L_800B4E80
    if (ctx->r3 != 0) {
        // 0x800B4E94: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800B4E80;
    }
    // 0x800B4E94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800B4E98:
    // 0x800B4E98: jr          $ra
    // 0x800B4E9C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800B4E9C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void _itoa_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4EA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B4EA4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800B4EA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B4EAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B4EB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B4EB4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B4EB8: beq         $t6, $zero, L_800B4ECC
    if (ctx->r14 == 0) {
        // 0x800B4EBC: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_800B4ECC;
    }
    // 0x800B4EBC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B4EC0: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800B4EC4: b           L_800B4ED4
    // 0x800B4EC8: addiu       $s1, $s1, -0x6E58
    ctx->r17 = ADD32(ctx->r17, -0X6E58);
        goto L_800B4ED4;
    // 0x800B4EC8: addiu       $s1, $s1, -0x6E58
    ctx->r17 = ADD32(ctx->r17, -0X6E58);
L_800B4ECC:
    // 0x800B4ECC: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800B4ED0: addiu       $s1, $s1, -0x6E80
    ctx->r17 = ADD32(ctx->r17, -0X6E80);
L_800B4ED4:
    // 0x800B4ED4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B4ED8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800B4EDC: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800B4EE0: bne         $t8, $zero, L_800B4EF0
    if (ctx->r24 != 0) {
        // 0x800B4EE4: addiu       $t0, $zero, 0x0
        ctx->r8 = ADD32(0, 0X0);
            goto L_800B4EF0;
    }
    // 0x800B4EE4: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x800B4EE8: beq         $t9, $zero, L_800B4F54
    if (ctx->r25 == 0) {
        // 0x800B4EEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B4F54;
    }
    // 0x800B4EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B4EF0:
    // 0x800B4EF0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800B4EF4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
L_800B4EF8:
    // 0x800B4EF8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_800B4EFC:
    // 0x800B4EFC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B4F00: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800B4F04: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800B4F08: jal         0x800CEFEC
    // 0x800B4F0C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x800B4F0C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    after_0:
    // 0x800B4F10: addu        $t2, $v1, $s1
    ctx->r10 = ADD32(ctx->r3, ctx->r17);
    // 0x800B4F14: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800B4F18: nop

    // 0x800B4F1C: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x800B4F20: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800B4F24: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800B4F28: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B4F2C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B4F30: jal         0x800CF028
    // 0x800B4F34: nop

    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800B4F34: nop

    after_1:
    // 0x800B4F38: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800B4F3C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B4F40: bne         $v0, $zero, L_800B4EF8
    if (ctx->r2 != 0) {
        // 0x800B4F44: or          $t5, $v1, $zero
        ctx->r13 = ctx->r3 | 0;
            goto L_800B4EF8;
    }
    // 0x800B4F44: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x800B4F48: bne         $t5, $zero, L_800B4EFC
    if (ctx->r13 != 0) {
        // 0x800B4F4C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800B4EFC;
    }
    // 0x800B4F4C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B4F50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B4F54:
    // 0x800B4F54: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B4F58: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B4F5C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B4F60: jr          $ra
    // 0x800B4F64: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B4F64: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void sprintfSetSpacingCodes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4F68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B4F6C: jr          $ra
    // 0x800B4F70: sw          $a0, 0x3480($at)
    MEM_W(0X3480, ctx->r1) = ctx->r4;
    return;
    // 0x800B4F70: sw          $a0, 0x3480($at)
    MEM_W(0X3480, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void sprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4F74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B4F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4F7C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B4F80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B4F84: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800B4F88: jal         0x800B4FA0
    // 0x800B4F8C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    vsprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B4F8C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800B4F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4F94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B4F98: jr          $ra
    // 0x800B4F9C: nop

    return;
    // 0x800B4F9C: nop

;}
RECOMP_FUNC void vsprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4FA0: addiu       $sp, $sp, -0x1B8
    ctx->r29 = ADD32(ctx->r29, -0X1B8);
    // 0x800B4FA4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800B4FA8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800B4FAC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800B4FB0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800B4FB4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800B4FB8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800B4FBC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800B4FC0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800B4FC4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800B4FC8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B4FCC: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B4FD0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800B4FD4: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4FD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B4FDC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800B4FE0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800B4FE4: beq         $t6, $zero, L_800B63A8
    if (ctx->r14 == 0) {
        // 0x800B4FE8: or          $t3, $a1, $zero
        ctx->r11 = ctx->r5 | 0;
            goto L_800B63A8;
    }
    // 0x800B4FE8: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x800B4FEC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B4FF0: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x800B4FF4: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4FF8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800B4FFC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B5000: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B5004: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B5008: lwc1        $f17, 0xE0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x800B500C: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800B5010: lw          $s4, 0xC8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC8);
    // 0x800B5014: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800B5018: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x800B501C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B5020:
    // 0x800B5020: beq         $a0, $v0, L_800B5060
    if (ctx->r4 == ctx->r2) {
        // 0x800B5024: nop
    
            goto L_800B5060;
    }
    // 0x800B5024: nop

    // 0x800B5028: beq         $a0, $v0, L_800B638C
    if (ctx->r4 == ctx->r2) {
        // 0x800B502C: nop
    
            goto L_800B638C;
    }
    // 0x800B502C: nop

    // 0x800B5030: beq         $v0, $zero, L_800B638C
    if (ctx->r2 == 0) {
        // 0x800B5034: nop
    
            goto L_800B638C;
    }
    // 0x800B5034: nop

L_800B5038:
    // 0x800B5038: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x800B503C: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B5040: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5044: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5048: beq         $a0, $v1, L_800B638C
    if (ctx->r4 == ctx->r3) {
        // 0x800B504C: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_800B638C;
    }
    // 0x800B504C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B5050: bne         $v1, $zero, L_800B5038
    if (ctx->r3 != 0) {
        // 0x800B5054: nop
    
            goto L_800B5038;
    }
    // 0x800B5054: nop

    // 0x800B5058: b           L_800B6390
    // 0x800B505C: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
        goto L_800B6390;
    // 0x800B505C: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
L_800B5060:
    // 0x800B5060: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B5064: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B5068: bne         $a0, $v1, L_800B5088
    if (ctx->r4 != ctx->r3) {
        // 0x800B506C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B5088;
    }
    // 0x800B506C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B5070: addiu       $t7, $zero, 0x25
    ctx->r15 = ADD32(0, 0X25);
    // 0x800B5074: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B5078: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x800B507C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5080: b           L_800B638C
    // 0x800B5084: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B638C;
    // 0x800B5084: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5088:
    // 0x800B5088: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B508C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800B5090: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800B5094: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B5098: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B509C: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
    // 0x800B50A0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800B50A4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800B50A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B50AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B50B0: beq         $v0, $at, L_800B50D8
    if (ctx->r2 == ctx->r1) {
        // 0x800B50B4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800B50D8;
    }
    // 0x800B50B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B50B8: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x800B50BC: beq         $v0, $at, L_800B50D8
    if (ctx->r2 == ctx->r1) {
        // 0x800B50C0: addiu       $at, $zero, 0x2D
        ctx->r1 = ADD32(0, 0X2D);
            goto L_800B50D8;
    }
    // 0x800B50C0: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800B50C4: beq         $v0, $at, L_800B50D8
    if (ctx->r2 == ctx->r1) {
        // 0x800B50C8: addiu       $at, $zero, 0x23
        ctx->r1 = ADD32(0, 0X23);
            goto L_800B50D8;
    }
    // 0x800B50C8: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x800B50CC: beq         $v0, $at, L_800B50D8
    if (ctx->r2 == ctx->r1) {
        // 0x800B50D0: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800B50D8;
    }
    // 0x800B50D0: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B50D4: bne         $v0, $at, L_800B5168
    if (ctx->r2 != ctx->r1) {
        // 0x800B50D8: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B5168;
    }
L_800B50D8:
    // 0x800B50D8: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
L_800B50DC:
    // 0x800B50DC: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x800B50E0: beq         $at, $zero, L_800B5128
    if (ctx->r1 == 0) {
        // 0x800B50E4: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_800B5128;
    }
    // 0x800B50E4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B50E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B50EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B50F0: addu        $at, $at, $t8
    gpr jr_addend_800B50FC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B50F4: lw          $t8, -0x6DD4($at)
    ctx->r24 = ADD32(ctx->r1, -0X6DD4);
    // 0x800B50F8: nop

    // 0x800B50FC: jr          $t8
    // 0x800B5100: nop

    switch (jr_addend_800B50FC >> 2) {
        case 0: goto L_800B5104; break;
        case 1: goto L_800B5128; break;
        case 2: goto L_800B5128; break;
        case 3: goto L_800B511C; break;
        case 4: goto L_800B5128; break;
        case 5: goto L_800B5128; break;
        case 6: goto L_800B5128; break;
        case 7: goto L_800B5128; break;
        case 8: goto L_800B5128; break;
        case 9: goto L_800B5128; break;
        case 10: goto L_800B5128; break;
        case 11: goto L_800B510C; break;
        case 12: goto L_800B5128; break;
        case 13: goto L_800B5114; break;
        case 14: goto L_800B5128; break;
        case 15: goto L_800B5128; break;
        case 16: goto L_800B5124; break;
        default: switch_error(__func__, 0x800B50FC, 0x800E922C);
    }
    // 0x800B5100: nop

L_800B5104:
    // 0x800B5104: b           L_800B5128
    // 0x800B5108: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
        goto L_800B5128;
    // 0x800B5108: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800B510C:
    // 0x800B510C: b           L_800B5128
    // 0x800B5110: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
        goto L_800B5128;
    // 0x800B5110: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800B5114:
    // 0x800B5114: b           L_800B5128
    // 0x800B5118: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
        goto L_800B5128;
    // 0x800B5118: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800B511C:
    // 0x800B511C: b           L_800B5128
    // 0x800B5120: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
        goto L_800B5128;
    // 0x800B5120: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_800B5124:
    // 0x800B5124: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
L_800B5128:
    // 0x800B5128: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800B512C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B5130: beq         $v1, $at, L_800B50D8
    if (ctx->r3 == ctx->r1) {
        // 0x800B5134: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B50D8;
    }
    // 0x800B5134: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B5138: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x800B513C: beq         $v1, $at, L_800B50DC
    if (ctx->r3 == ctx->r1) {
        // 0x800B5140: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B50DC;
    }
    // 0x800B5140: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
    // 0x800B5144: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800B5148: beq         $v1, $at, L_800B50DC
    if (ctx->r3 == ctx->r1) {
        // 0x800B514C: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B50DC;
    }
    // 0x800B514C: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
    // 0x800B5150: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x800B5154: beq         $v1, $at, L_800B50DC
    if (ctx->r3 == ctx->r1) {
        // 0x800B5158: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B50DC;
    }
    // 0x800B5158: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
    // 0x800B515C: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B5160: beq         $v1, $at, L_800B50DC
    if (ctx->r3 == ctx->r1) {
        // 0x800B5164: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B50DC;
    }
    // 0x800B5164: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
L_800B5168:
    // 0x800B5168: beq         $s7, $zero, L_800B5174
    if (ctx->r23 == 0) {
        // 0x800B516C: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_800B5174;
    }
    // 0x800B516C: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x800B5170: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
L_800B5174:
    // 0x800B5174: bne         $v0, $at, L_800B51B4
    if (ctx->r2 != ctx->r1) {
        // 0x800B5178: slti        $at, $v0, 0x30
        ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
            goto L_800B51B4;
    }
    // 0x800B5178: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x800B517C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5180: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5184: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B5188: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B518C: lw          $t0, -0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, -0X4);
    // 0x800B5190: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B5194: bgez        $t0, L_800B51A4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B5198: nop
    
            goto L_800B51A4;
    }
    // 0x800B5198: nop

    // 0x800B519C: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x800B51A0: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800B51A4:
    // 0x800B51A4: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800B51A8: b           L_800B51F4
    // 0x800B51AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B51F4;
    // 0x800B51AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B51B0: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
L_800B51B4:
    // 0x800B51B4: bne         $at, $zero, L_800B51F4
    if (ctx->r1 != 0) {
        // 0x800B51B8: slti        $at, $v0, 0x3A
        ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
            goto L_800B51F4;
    }
    // 0x800B51B8: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B51BC: beq         $at, $zero, L_800B51F4
    if (ctx->r1 == 0) {
        // 0x800B51C0: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_800B51F4;
    }
    // 0x800B51C0: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
L_800B51C4:
    // 0x800B51C4: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B51C8: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x800B51CC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800B51D0: addu        $t0, $t6, $v0
    ctx->r8 = ADD32(ctx->r14, ctx->r2);
    // 0x800B51D4: slti        $at, $v1, 0x30
    ctx->r1 = SIGNED(ctx->r3) < 0X30 ? 1 : 0;
    // 0x800B51D8: addiu       $t0, $t0, -0x30
    ctx->r8 = ADD32(ctx->r8, -0X30);
    // 0x800B51DC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B51E0: bne         $at, $zero, L_800B51F4
    if (ctx->r1 != 0) {
        // 0x800B51E4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B51F4;
    }
    // 0x800B51E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B51E8: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B51EC: bne         $at, $zero, L_800B51C4
    if (ctx->r1 != 0) {
        // 0x800B51F0: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_800B51C4;
    }
    // 0x800B51F0: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
L_800B51F4:
    // 0x800B51F4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x800B51F8: bne         $v0, $at, L_800B52A0
    if (ctx->r2 != ctx->r1) {
        // 0x800B51FC: addiu       $at, $zero, 0x68
        ctx->r1 = ADD32(0, 0X68);
            goto L_800B52A0;
    }
    // 0x800B51FC: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800B5200: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B5204: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x800B5208: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B520C: bne         $v1, $at, L_800B5244
    if (ctx->r3 != ctx->r1) {
        // 0x800B5210: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B5244;
    }
    // 0x800B5210: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B5214: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5218: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B521C: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B5220: addiu       $s1, $t7, 0x4
    ctx->r17 = ADD32(ctx->r15, 0X4);
    // 0x800B5224: lw          $t2, -0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, -0X4);
    // 0x800B5228: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B522C: bgez        $t2, L_800B5238
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B5230: nop
    
            goto L_800B5238;
    }
    // 0x800B5230: nop

    // 0x800B5234: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_800B5238:
    // 0x800B5238: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800B523C: b           L_800B529C
    // 0x800B5240: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B529C;
    // 0x800B5240: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B5244:
    // 0x800B5244: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x800B5248: bne         $at, $zero, L_800B529C
    if (ctx->r1 != 0) {
        // 0x800B524C: slti        $at, $v0, 0x3A
        ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
            goto L_800B529C;
    }
    // 0x800B524C: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B5250: beq         $at, $zero, L_800B529C
    if (ctx->r1 == 0) {
        // 0x800B5254: slti        $at, $v0, 0x30
        ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
            goto L_800B529C;
    }
    // 0x800B5254: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x800B5258: bne         $at, $zero, L_800B529C
    if (ctx->r1 != 0) {
        // 0x800B525C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800B529C;
    }
    // 0x800B525C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800B5260: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B5264: beq         $at, $zero, L_800B529C
    if (ctx->r1 == 0) {
        // 0x800B5268: sll         $t8, $t2, 2
        ctx->r24 = S32(ctx->r10 << 2);
            goto L_800B529C;
    }
    // 0x800B5268: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
L_800B526C:
    // 0x800B526C: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B5270: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x800B5274: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800B5278: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800B527C: slti        $at, $v1, 0x30
    ctx->r1 = SIGNED(ctx->r3) < 0X30 ? 1 : 0;
    // 0x800B5280: addiu       $t2, $t2, -0x30
    ctx->r10 = ADD32(ctx->r10, -0X30);
    // 0x800B5284: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B5288: bne         $at, $zero, L_800B529C
    if (ctx->r1 != 0) {
        // 0x800B528C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B529C;
    }
    // 0x800B528C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B5290: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B5294: bne         $at, $zero, L_800B526C
    if (ctx->r1 != 0) {
        // 0x800B5298: sll         $t8, $t2, 2
        ctx->r24 = S32(ctx->r10 << 2);
            goto L_800B526C;
    }
    // 0x800B5298: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
L_800B529C:
    // 0x800B529C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
L_800B52A0:
    // 0x800B52A0: beq         $v0, $at, L_800B52C4
    if (ctx->r2 == ctx->r1) {
        // 0x800B52A4: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_800B52C4;
    }
    // 0x800B52A4: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800B52A8: beq         $v0, $at, L_800B52C4
    if (ctx->r2 == ctx->r1) {
        // 0x800B52AC: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800B52C4;
    }
    // 0x800B52AC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800B52B0: beq         $v0, $at, L_800B52C4
    if (ctx->r2 == ctx->r1) {
        // 0x800B52B4: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_800B52C4;
    }
    // 0x800B52B4: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x800B52B8: beq         $v0, $at, L_800B52C4
    if (ctx->r2 == ctx->r1) {
        // 0x800B52BC: addiu       $at, $zero, 0x71
        ctx->r1 = ADD32(0, 0X71);
            goto L_800B52C4;
    }
    // 0x800B52BC: addiu       $at, $zero, 0x71
    ctx->r1 = ADD32(0, 0X71);
    // 0x800B52C0: bne         $v0, $at, L_800B5364
    if (ctx->r2 != ctx->r1) {
        // 0x800B52C4: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B5364;
    }
L_800B52C4:
    // 0x800B52C4: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
L_800B52C8:
    // 0x800B52C8: sltiu       $at, $t9, 0x26
    ctx->r1 = ctx->r25 < 0X26 ? 1 : 0;
    // 0x800B52CC: beq         $at, $zero, L_800B5324
    if (ctx->r1 == 0) {
        // 0x800B52D0: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_800B5324;
    }
    // 0x800B52D0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B52D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B52D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B52DC: addu        $at, $at, $t9
    gpr jr_addend_800B52E8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B52E0: lw          $t9, -0x6D90($at)
    ctx->r25 = ADD32(ctx->r1, -0X6D90);
    // 0x800B52E4: nop

    // 0x800B52E8: jr          $t9
    // 0x800B52EC: nop

    switch (jr_addend_800B52E8 >> 2) {
        case 0: goto L_800B5310; break;
        case 1: goto L_800B5324; break;
        case 2: goto L_800B5324; break;
        case 3: goto L_800B5324; break;
        case 4: goto L_800B5324; break;
        case 5: goto L_800B5324; break;
        case 6: goto L_800B5324; break;
        case 7: goto L_800B5324; break;
        case 8: goto L_800B5324; break;
        case 9: goto L_800B5324; break;
        case 10: goto L_800B5324; break;
        case 11: goto L_800B5324; break;
        case 12: goto L_800B5324; break;
        case 13: goto L_800B5324; break;
        case 14: goto L_800B5318; break;
        case 15: goto L_800B5324; break;
        case 16: goto L_800B5324; break;
        case 17: goto L_800B5324; break;
        case 18: goto L_800B5324; break;
        case 19: goto L_800B5324; break;
        case 20: goto L_800B5324; break;
        case 21: goto L_800B5324; break;
        case 22: goto L_800B5324; break;
        case 23: goto L_800B5324; break;
        case 24: goto L_800B5324; break;
        case 25: goto L_800B5324; break;
        case 26: goto L_800B5324; break;
        case 27: goto L_800B5324; break;
        case 28: goto L_800B52F0; break;
        case 29: goto L_800B5324; break;
        case 30: goto L_800B5324; break;
        case 31: goto L_800B5324; break;
        case 32: goto L_800B52F8; break;
        case 33: goto L_800B5324; break;
        case 34: goto L_800B5324; break;
        case 35: goto L_800B5324; break;
        case 36: goto L_800B5324; break;
        case 37: goto L_800B5320; break;
        default: switch_error(__func__, 0x800B52E8, 0x800E9270);
    }
    // 0x800B52EC: nop

L_800B52F0:
    // 0x800B52F0: b           L_800B5324
    // 0x800B52F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800B5324;
    // 0x800B52F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800B52F8:
    // 0x800B52F8: beq         $a1, $zero, L_800B5308
    if (ctx->r5 == 0) {
        // 0x800B52FC: nop
    
            goto L_800B5308;
    }
    // 0x800B52FC: nop

    // 0x800B5300: b           L_800B5324
    // 0x800B5304: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800B5324;
    // 0x800B5304: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B5308:
    // 0x800B5308: b           L_800B5324
    // 0x800B530C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800B5324;
    // 0x800B530C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800B5310:
    // 0x800B5310: b           L_800B5324
    // 0x800B5314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800B5324;
    // 0x800B5314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B5318:
    // 0x800B5318: b           L_800B5324
    // 0x800B531C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800B5324;
    // 0x800B531C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800B5320:
    // 0x800B5320: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B5324:
    // 0x800B5324: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800B5328: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800B532C: beq         $v1, $at, L_800B52C4
    if (ctx->r3 == ctx->r1) {
        // 0x800B5330: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B52C4;
    }
    // 0x800B5330: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B5334: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800B5338: beq         $v1, $at, L_800B52C8
    if (ctx->r3 == ctx->r1) {
        // 0x800B533C: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B52C8;
    }
    // 0x800B533C: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
    // 0x800B5340: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800B5344: beq         $v1, $at, L_800B52C8
    if (ctx->r3 == ctx->r1) {
        // 0x800B5348: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B52C8;
    }
    // 0x800B5348: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
    // 0x800B534C: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x800B5350: beq         $v1, $at, L_800B52C8
    if (ctx->r3 == ctx->r1) {
        // 0x800B5354: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B52C8;
    }
    // 0x800B5354: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
    // 0x800B5358: addiu       $at, $zero, 0x71
    ctx->r1 = ADD32(0, 0X71);
    // 0x800B535C: beq         $v1, $at, L_800B52C8
    if (ctx->r3 == ctx->r1) {
        // 0x800B5360: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B52C8;
    }
    // 0x800B5360: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
L_800B5364:
    // 0x800B5364: andi        $s3, $v1, 0xFF
    ctx->r19 = ctx->r3 & 0XFF;
    // 0x800B5368: addiu       $t6, $s3, -0x45
    ctx->r14 = ADD32(ctx->r19, -0X45);
    // 0x800B536C: sltiu       $at, $t6, 0x34
    ctx->r1 = ctx->r14 < 0X34 ? 1 : 0;
    // 0x800B5370: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B5374: beq         $at, $zero, L_800B636C
    if (ctx->r1 == 0) {
        // 0x800B5378: sb          $s3, 0x19A($sp)
        MEM_B(0X19A, ctx->r29) = ctx->r19;
            goto L_800B636C;
    }
    // 0x800B5378: sb          $s3, 0x19A($sp)
    MEM_B(0X19A, ctx->r29) = ctx->r19;
    // 0x800B537C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B5380: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B5384: addu        $at, $at, $t6
    gpr jr_addend_800B5390 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B5388: lw          $t6, -0x6CF8($at)
    ctx->r14 = ADD32(ctx->r1, -0X6CF8);
    // 0x800B538C: nop

    // 0x800B5390: jr          $t6
    // 0x800B5394: nop

    switch (jr_addend_800B5390 >> 2) {
        case 0: goto L_800B5824; break;
        case 1: goto L_800B636C; break;
        case 2: goto L_800B5CF4; break;
        case 3: goto L_800B636C; break;
        case 4: goto L_800B636C; break;
        case 5: goto L_800B636C; break;
        case 6: goto L_800B636C; break;
        case 7: goto L_800B636C; break;
        case 8: goto L_800B636C; break;
        case 9: goto L_800B636C; break;
        case 10: goto L_800B636C; break;
        case 11: goto L_800B636C; break;
        case 12: goto L_800B636C; break;
        case 13: goto L_800B636C; break;
        case 14: goto L_800B636C; break;
        case 15: goto L_800B636C; break;
        case 16: goto L_800B636C; break;
        case 17: goto L_800B636C; break;
        case 18: goto L_800B636C; break;
        case 19: goto L_800B54E4; break;
        case 20: goto L_800B636C; break;
        case 21: goto L_800B636C; break;
        case 22: goto L_800B636C; break;
        case 23: goto L_800B636C; break;
        case 24: goto L_800B636C; break;
        case 25: goto L_800B636C; break;
        case 26: goto L_800B636C; break;
        case 27: goto L_800B636C; break;
        case 28: goto L_800B636C; break;
        case 29: goto L_800B636C; break;
        case 30: goto L_800B6024; break;
        case 31: goto L_800B5398; break;
        case 32: goto L_800B5824; break;
        case 33: goto L_800B5D04; break;
        case 34: goto L_800B5CF4; break;
        case 35: goto L_800B636C; break;
        case 36: goto L_800B5398; break;
        case 37: goto L_800B636C; break;
        case 38: goto L_800B636C; break;
        case 39: goto L_800B636C; break;
        case 40: goto L_800B636C; break;
        case 41: goto L_800B62D8; break;
        case 42: goto L_800B54C4; break;
        case 43: goto L_800B61EC; break;
        case 44: goto L_800B636C; break;
        case 45: goto L_800B636C; break;
        case 46: goto L_800B60A8; break;
        case 47: goto L_800B636C; break;
        case 48: goto L_800B54A4; break;
        case 49: goto L_800B636C; break;
        case 50: goto L_800B636C; break;
        case 51: goto L_800B5504; break;
        default: switch_error(__func__, 0x800B5390, 0x800E9308);
    }
    // 0x800B5394: nop

L_800B5398:
    // 0x800B5398: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B539C: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B53A0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800B53A4: beq         $a0, $zero, L_800B53D0
    if (ctx->r4 == 0) {
        // 0x800B53A8: addiu       $ra, $sp, 0x17B
        ctx->r31 = ADD32(ctx->r29, 0X17B);
            goto L_800B53D0;
    }
    // 0x800B53A8: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
    // 0x800B53AC: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B53B0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800B53B4: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B53B8: addiu       $s1, $t7, 0x8
    ctx->r17 = ADD32(ctx->r15, 0X8);
    // 0x800B53BC: lw          $t8, -0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, -0X8);
    // 0x800B53C0: lw          $t9, -0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, -0X4);
    // 0x800B53C4: sw          $t8, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r24;
    // 0x800B53C8: b           L_800B544C
    // 0x800B53CC: sw          $t9, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r25;
        goto L_800B544C;
    // 0x800B53CC: sw          $t9, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r25;
L_800B53D0:
    // 0x800B53D0: beq         $a1, $zero, L_800B53FC
    if (ctx->r5 == 0) {
        // 0x800B53D4: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B53FC;
    }
    // 0x800B53D4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B53D8: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B53DC: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B53E0: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B53E4: lw          $t7, -0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, -0X4);
    // 0x800B53E8: nop

    // 0x800B53EC: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800B53F0: sw          $t8, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r24;
    // 0x800B53F4: b           L_800B544C
    // 0x800B53F8: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
        goto L_800B544C;
    // 0x800B53F8: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
L_800B53FC:
    // 0x800B53FC: bne         $a2, $zero, L_800B542C
    if (ctx->r6 != 0) {
        // 0x800B5400: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B542C;
    }
    // 0x800B5400: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5404: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5408: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B540C: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B5410: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B5414: lw          $t7, -0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, -0X4);
    // 0x800B5418: nop

    // 0x800B541C: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800B5420: sw          $t8, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r24;
    // 0x800B5424: b           L_800B544C
    // 0x800B5428: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
        goto L_800B544C;
    // 0x800B5428: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
L_800B542C:
    // 0x800B542C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5430: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B5434: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B5438: lh          $t7, -0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, -0X2);
    // 0x800B543C: nop

    // 0x800B5440: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800B5444: sw          $t8, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r24;
    // 0x800B5448: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
L_800B544C:
    // 0x800B544C: lw          $t6, 0x180($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X180);
    // 0x800B5450: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800B5454: slti        $v0, $t6, 0x0
    ctx->r2 = SIGNED(ctx->r14) < 0X0 ? 1 : 0;
    // 0x800B5458: bgtz        $v0, L_800B546C
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B545C: sltiu       $at, $t7, 0x1
        ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
            goto L_800B546C;
    }
    // 0x800B545C: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800B5460: bgtz        $t6, L_800B5470
    if (SIGNED(ctx->r14) > 0) {
        // 0x800B5464: andi        $t8, $v0, 0xFF
        ctx->r24 = ctx->r2 & 0XFF;
            goto L_800B5470;
    }
    // 0x800B5464: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x800B5468: sltiu       $v0, $t7, 0x0
    ctx->r2 = ctx->r15 < 0X0 ? 1 : 0;
L_800B546C:
    // 0x800B546C: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
L_800B5470:
    // 0x800B5470: beq         $t8, $zero, L_800B5490
    if (ctx->r24 == 0) {
        // 0x800B5474: andi        $s2, $v0, 0xFF
        ctx->r18 = ctx->r2 & 0XFF;
            goto L_800B5490;
    }
    // 0x800B5474: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x800B5478: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x800B547C: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x800B5480: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x800B5484: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800B5488: b           L_800B55B8
    // 0x800B548C: sw          $t8, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r24;
        goto L_800B55B8;
    // 0x800B548C: sw          $t8, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r24;
L_800B5490:
    // 0x800B5490: lw          $t6, 0x180($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X180);
    // 0x800B5494: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800B5498: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B549C: b           L_800B55B8
    // 0x800B54A0: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
        goto L_800B55B8;
    // 0x800B54A0: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
L_800B54A4:
    // 0x800B54A4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B54A8: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B54AC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800B54B0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B54B4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B54B8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B54BC: b           L_800B5520
    // 0x800B54C0: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
        goto L_800B5520;
    // 0x800B54C0: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B54C4:
    // 0x800B54C4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B54C8: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B54CC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800B54D0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B54D4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B54D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B54DC: b           L_800B5520
    // 0x800B54E0: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
        goto L_800B5520;
    // 0x800B54E0: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B54E4:
    // 0x800B54E4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B54E8: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B54EC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800B54F0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B54F4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B54F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B54FC: b           L_800B5520
    // 0x800B5500: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
        goto L_800B5520;
    // 0x800B5500: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B5504:
    // 0x800B5504: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5508: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B550C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800B5510: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B5514: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B5518: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B551C: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B5520:
    // 0x800B5520: beq         $a0, $zero, L_800B5548
    if (ctx->r4 == 0) {
        // 0x800B5524: addiu       $at, $zero, -0x8
        ctx->r1 = ADD32(0, -0X8);
            goto L_800B5548;
    }
    // 0x800B5524: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800B5528: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B552C: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x800B5530: addiu       $s1, $t8, 0x8
    ctx->r17 = ADD32(ctx->r24, 0X8);
    // 0x800B5534: lw          $t6, -0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, -0X8);
    // 0x800B5538: lw          $t7, -0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, -0X4);
    // 0x800B553C: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B5540: b           L_800B55B8
    // 0x800B5544: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
        goto L_800B55B8;
    // 0x800B5544: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
L_800B5548:
    // 0x800B5548: beq         $a1, $zero, L_800B5570
    if (ctx->r5 == 0) {
        // 0x800B554C: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B5570;
    }
    // 0x800B554C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5550: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5554: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B5558: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B555C: lw          $t8, -0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, -0X4);
    // 0x800B5560: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B5564: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B5568: b           L_800B55B8
    // 0x800B556C: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
        goto L_800B55B8;
    // 0x800B556C: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
L_800B5570:
    // 0x800B5570: bne         $a2, $zero, L_800B559C
    if (ctx->r6 != 0) {
        // 0x800B5574: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B559C;
    }
    // 0x800B5574: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5578: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B557C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5580: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B5584: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B5588: lw          $t8, -0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, -0X4);
    // 0x800B558C: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B5590: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B5594: b           L_800B55B8
    // 0x800B5598: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
        goto L_800B55B8;
    // 0x800B5598: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
L_800B559C:
    // 0x800B559C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B55A0: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B55A4: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B55A8: lhu         $t8, -0x2($s1)
    ctx->r24 = MEM_HU(ctx->r17, -0X2);
    // 0x800B55AC: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B55B0: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B55B4: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
L_800B55B8:
    // 0x800B55B8: beq         $v1, $zero, L_800B55D0
    if (ctx->r3 == 0) {
        // 0x800B55BC: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800B55D0;
    }
    // 0x800B55BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B55C0: addiu       $t9, $zero, 0x84
    ctx->r25 = ADD32(0, 0X84);
    // 0x800B55C4: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B55C8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B55CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B55D0:
    // 0x800B55D0: bltz        $t2, L_800B55DC
    if (SIGNED(ctx->r10) < 0) {
        // 0x800B55D4: addiu       $a2, $sp, 0x17C
        ctx->r6 = ADD32(ctx->r29, 0X17C);
            goto L_800B55DC;
    }
    // 0x800B55D4: addiu       $a2, $sp, 0x17C
    ctx->r6 = ADD32(ctx->r29, 0X17C);
    // 0x800B55D8: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
L_800B55DC:
    // 0x800B55DC: bne         $t2, $at, L_800B55E8
    if (ctx->r10 != ctx->r1) {
        // 0x800B55E0: xori        $t8, $s3, 0x58
        ctx->r24 = ctx->r19 ^ 0X58;
            goto L_800B55E8;
    }
    // 0x800B55E0: xori        $t8, $s3, 0x58
    ctx->r24 = ctx->r19 ^ 0X58;
    // 0x800B55E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800B55E8:
    // 0x800B55E8: lw          $a0, 0x188($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X188);
    // 0x800B55EC: lw          $a1, 0x18C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18C);
    // 0x800B55F0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800B55F4: sw          $ra, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r31;
    // 0x800B55F8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800B55FC: sw          $a3, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r7;
    // 0x800B5600: sw          $t0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r8;
    // 0x800B5604: sw          $t1, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r9;
    // 0x800B5608: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800B560C: sw          $t3, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r11;
    // 0x800B5610: sb          $t4, 0x1A4($sp)
    MEM_B(0X1A4, ctx->r29) = ctx->r12;
    // 0x800B5614: swc1        $f17, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800B5618: jal         0x800B4EA0
    // 0x800B561C: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    _itoa_recomp(rdram, ctx);
        goto after_0;
    // 0x800B561C: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800B5620: addiu       $t6, $sp, 0x17B
    ctx->r14 = ADD32(ctx->r29, 0X17B);
    // 0x800B5624: lw          $t0, 0x1A0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A0);
    // 0x800B5628: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800B562C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800B5630: subu        $v1, $t6, $v0
    ctx->r3 = SUB32(ctx->r14, ctx->r2);
    // 0x800B5634: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B5638: lw          $a3, 0x194($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X194);
    // 0x800B563C: lw          $t1, 0x1AC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1AC);
    // 0x800B5640: lw          $t3, 0x1B4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B4);
    // 0x800B5644: lbu         $t4, 0x1A4($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1A4);
    // 0x800B5648: lw          $ra, 0xF8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XF8);
    // 0x800B564C: lwc1        $f17, 0xE0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x800B5650: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800B5654: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B5658: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x800B565C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B5660: sltu        $a2, $zero, $fp
    ctx->r6 = 0 < ctx->r30 ? 1 : 0;
    // 0x800B5664: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800B5668: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800B566C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x800B5670: beq         $a2, $zero, L_800B5698
    if (ctx->r6 == 0) {
        // 0x800B5674: subu        $t2, $t2, $v1
        ctx->r10 = SUB32(ctx->r10, ctx->r3);
            goto L_800B5698;
    }
    // 0x800B5674: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x800B5678: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800B567C: bne         $a3, $at, L_800B569C
    if (ctx->r7 != ctx->r1) {
        // 0x800B5680: slt         $s3, $zero, $t2
        ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800B569C;
    }
    // 0x800B5680: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B5684: bgtz        $t2, L_800B5698
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B5688: addiu       $t7, $zero, 0x30
        ctx->r15 = ADD32(0, 0X30);
            goto L_800B5698;
    }
    // 0x800B5688: addiu       $t7, $zero, 0x30
    ctx->r15 = ADD32(0, 0X30);
    // 0x800B568C: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x800B5690: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x800B5694: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5698:
    // 0x800B5698: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
L_800B569C:
    // 0x800B569C: beq         $s3, $zero, L_800B56C8
    if (ctx->r19 == 0) {
        // 0x800B56A0: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800B56C8;
    }
    // 0x800B56A0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800B56A4: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x800B56A8: beq         $s3, $zero, L_800B56C8
    if (ctx->r19 == 0) {
        // 0x800B56AC: addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
            goto L_800B56C8;
    }
    // 0x800B56AC: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800B56B0: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_800B56B4:
    // 0x800B56B4: slt         $v1, $zero, $t2
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B56B8: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800B56BC: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800B56C0: bne         $v1, $zero, L_800B56B4
    if (ctx->r3 != 0) {
        // 0x800B56C4: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_800B56B4;
    }
    // 0x800B56C4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_800B56C8:
    // 0x800B56C8: beq         $a2, $zero, L_800B56DC
    if (ctx->r6 == 0) {
        // 0x800B56CC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800B56DC;
    }
    // 0x800B56CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B56D0: bne         $a3, $at, L_800B56DC
    if (ctx->r7 != ctx->r1) {
        // 0x800B56D4: nop
    
            goto L_800B56DC;
    }
    // 0x800B56D4: nop

    // 0x800B56D8: addiu       $t0, $t0, -0x2
    ctx->r8 = ADD32(ctx->r8, -0X2);
L_800B56DC:
    // 0x800B56DC: bne         $s2, $zero, L_800B56F4
    if (ctx->r18 != 0) {
        // 0x800B56E0: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_800B56F4;
    }
    // 0x800B56E0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B56E4: bne         $s5, $zero, L_800B56F4
    if (ctx->r21 != 0) {
        // 0x800B56E8: nop
    
            goto L_800B56F4;
    }
    // 0x800B56E8: nop

    // 0x800B56EC: beq         $s6, $zero, L_800B56F8
    if (ctx->r22 == 0) {
        // 0x800B56F0: nop
    
            goto L_800B56F8;
    }
    // 0x800B56F0: nop

L_800B56F4:
    // 0x800B56F4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B56F8:
    // 0x800B56F8: bne         $s7, $zero, L_800B5728
    if (ctx->r23 != 0) {
        // 0x800B56FC: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_800B5728;
    }
    // 0x800B56FC: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800B5700: bne         $t4, $at, L_800B5728
    if (ctx->r12 != ctx->r1) {
        // 0x800B5704: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5728;
    }
    // 0x800B5704: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5708: beq         $v1, $zero, L_800B5728
    if (ctx->r3 == 0) {
        // 0x800B570C: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5728;
    }
    // 0x800B570C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5710:
    // 0x800B5710: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5714: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5718: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B571C: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5720: bne         $v1, $zero, L_800B5710
    if (ctx->r3 != 0) {
        // 0x800B5724: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5710;
    }
    // 0x800B5724: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5728:
    // 0x800B5728: beq         $s2, $zero, L_800B5740
    if (ctx->r18 == 0) {
        // 0x800B572C: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800B5740;
    }
    // 0x800B572C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800B5730: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5734: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5738: b           L_800B576C
    // 0x800B573C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B576C;
    // 0x800B573C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5740:
    // 0x800B5740: beq         $s5, $zero, L_800B5758
    if (ctx->r21 == 0) {
        // 0x800B5744: addiu       $t8, $zero, 0x2B
        ctx->r24 = ADD32(0, 0X2B);
            goto L_800B5758;
    }
    // 0x800B5744: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x800B5748: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B574C: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800B5750: b           L_800B576C
    // 0x800B5754: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B576C;
    // 0x800B5754: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5758:
    // 0x800B5758: beq         $s6, $zero, L_800B576C
    if (ctx->r22 == 0) {
        // 0x800B575C: nop
    
            goto L_800B576C;
    }
    // 0x800B575C: nop

    // 0x800B5760: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5764: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5768: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B576C:
    // 0x800B576C: beq         $a2, $zero, L_800B5790
    if (ctx->r6 == 0) {
        // 0x800B5770: addiu       $t8, $sp, 0x17B
        ctx->r24 = ADD32(ctx->r29, 0X17B);
            goto L_800B5790;
    }
    // 0x800B5770: addiu       $t8, $sp, 0x17B
    ctx->r24 = ADD32(ctx->r29, 0X17B);
    // 0x800B5774: bne         $a3, $at, L_800B5790
    if (ctx->r7 != ctx->r1) {
        // 0x800B5778: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_800B5790;
    }
    // 0x800B5778: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800B577C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800B5780: lbu         $t7, 0x19A($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X19A);
    // 0x800B5784: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800B5788: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800B578C: sb          $t7, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r15;
L_800B5790:
    // 0x800B5790: bne         $s7, $zero, L_800B57C4
    if (ctx->r23 != 0) {
        // 0x800B5794: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800B57C4;
    }
    // 0x800B5794: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B5798: bne         $t4, $at, L_800B57C4
    if (ctx->r12 != ctx->r1) {
        // 0x800B579C: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B57C4;
    }
    // 0x800B579C: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B57A0: beq         $v1, $zero, L_800B57C4
    if (ctx->r3 == 0) {
        // 0x800B57A4: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B57C4;
    }
    // 0x800B57A4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B57A8:
    // 0x800B57A8: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x800B57AC: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B57B0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B57B4: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B57B8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B57BC: bne         $v1, $zero, L_800B57A8
    if (ctx->r3 != 0) {
        // 0x800B57C0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B57A8;
    }
    // 0x800B57C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B57C4:
    // 0x800B57C4: sltu        $at, $t8, $a0
    ctx->r1 = ctx->r24 < ctx->r4 ? 1 : 0;
    // 0x800B57C8: bne         $at, $zero, L_800B57EC
    if (ctx->r1 != 0) {
        // 0x800B57CC: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B57EC;
    }
    // 0x800B57CC: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
L_800B57D0:
    // 0x800B57D0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800B57D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B57D8: sltu        $at, $ra, $a0
    ctx->r1 = ctx->r31 < ctx->r4 ? 1 : 0;
    // 0x800B57DC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B57E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B57E4: beq         $at, $zero, L_800B57D0
    if (ctx->r1 == 0) {
        // 0x800B57E8: sb          $t6, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r14;
            goto L_800B57D0;
    }
    // 0x800B57E8: sb          $t6, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r14;
L_800B57EC:
    // 0x800B57EC: beq         $s7, $zero, L_800B5814
    if (ctx->r23 == 0) {
        // 0x800B57F0: nop
    
            goto L_800B5814;
    }
    // 0x800B57F0: nop

    // 0x800B57F4: beq         $v1, $zero, L_800B5814
    if (ctx->r3 == 0) {
        // 0x800B57F8: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5814;
    }
    // 0x800B57F8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B57FC:
    // 0x800B57FC: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5800: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5804: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5808: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B580C: bne         $v1, $zero, L_800B57FC
    if (ctx->r3 != 0) {
        // 0x800B5810: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B57FC;
    }
    // 0x800B5810: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5814:
    // 0x800B5814: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5818: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B581C: b           L_800B6378
    // 0x800B5820: nop

        goto L_800B6378;
    // 0x800B5820: nop

L_800B5824:
    // 0x800B5824: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B5828: lw          $t7, 0x3480($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3480);
    // 0x800B582C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B5830: beq         $t7, $zero, L_800B5844
    if (ctx->r15 == 0) {
        // 0x800B5834: addiu       $t9, $zero, 0x84
        ctx->r25 = ADD32(0, 0X84);
            goto L_800B5844;
    }
    // 0x800B5834: addiu       $t9, $zero, 0x84
    ctx->r25 = ADD32(0, 0X84);
    // 0x800B5838: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B583C: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5840: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5844:
    // 0x800B5844: bgez        $t2, L_800B5850
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B5848: andi        $t6, $s1, 0x1
        ctx->r14 = ctx->r17 & 0X1;
            goto L_800B5850;
    }
    // 0x800B5848: andi        $t6, $s1, 0x1
    ctx->r14 = ctx->r17 & 0X1;
    // 0x800B584C: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
L_800B5850:
    // 0x800B5850: beq         $a2, $zero, L_800B587C
    if (ctx->r6 == 0) {
        // 0x800B5854: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B587C;
    }
    // 0x800B5854: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5858: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B585C: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x800B5860: addiu       $s1, $t8, 0x4
    ctx->r17 = ADD32(ctx->r24, 0X4);
    // 0x800B5864: lwc1        $f4, -0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0X4);
    // 0x800B5868: nop

    // 0x800B586C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B5870: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    // 0x800B5874: b           L_800B58C8
    // 0x800B5878: swc1        $f7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
        goto L_800B58C8;
    // 0x800B5878: swc1        $f7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
L_800B587C:
    // 0x800B587C: beq         $t6, $zero, L_800B5890
    if (ctx->r14 == 0) {
        // 0x800B5880: andi        $t7, $s1, 0x2
        ctx->r15 = ctx->r17 & 0X2;
            goto L_800B5890;
    }
    // 0x800B5880: andi        $t7, $s1, 0x2
    ctx->r15 = ctx->r17 & 0X2;
    // 0x800B5884: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B5888: b           L_800B58B8
    // 0x800B588C: addiu       $v1, $s1, -0x16
    ctx->r3 = ADD32(ctx->r17, -0X16);
        goto L_800B58B8;
    // 0x800B588C: addiu       $v1, $s1, -0x16
    ctx->r3 = ADD32(ctx->r17, -0X16);
L_800B5890:
    // 0x800B5890: beq         $t7, $zero, L_800B58A4
    if (ctx->r15 == 0) {
        // 0x800B5894: addiu       $at, $zero, -0x8
        ctx->r1 = ADD32(0, -0X8);
            goto L_800B58A4;
    }
    // 0x800B5894: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800B5898: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x800B589C: b           L_800B58B4
    // 0x800B58A0: addiu       $a0, $s1, -0x28
    ctx->r4 = ADD32(ctx->r17, -0X28);
        goto L_800B58B4;
    // 0x800B58A0: addiu       $a0, $s1, -0x28
    ctx->r4 = ADD32(ctx->r17, -0X28);
L_800B58A4:
    // 0x800B58A4: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B58A8: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B58AC: addiu       $s1, $t9, 0x8
    ctx->r17 = ADD32(ctx->r25, 0X8);
    // 0x800B58B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800B58B4:
    // 0x800B58B4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800B58B8:
    // 0x800B58B8: lwc1        $f9, -0x8($v1)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r3, -0X8);
    // 0x800B58BC: lwc1        $f8, -0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X4);
    // 0x800B58C0: swc1        $f9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800B58C4: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
L_800B58C8:
    // 0x800B58C8: lb          $t8, 0xD0($sp)
    ctx->r24 = MEM_B(ctx->r29, 0XD0);
    // 0x800B58CC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800B58D0: bgez        $t8, L_800B58F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B58D4: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_800B58F0;
    }
    // 0x800B58D4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B58D8: lwc1        $f11, 0xD0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B58DC: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B58E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B58E4: neg.d       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = -ctx->f10.d;
    // 0x800B58E8: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x800B58EC: swc1        $f5, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
L_800B58F0:
    // 0x800B58F0: lwc1        $f7, 0xD0($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B58F4: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B58F8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B58FC: lwc1        $f11, 0xD0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5900: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x800B5904: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5908: lwc1        $f7, 0xD0($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B590C: bc1f        L_800B5920
    if (!c1cs) {
        // 0x800B5910: andi        $a0, $t2, 0x3
        ctx->r4 = ctx->r10 & 0X3;
            goto L_800B5920;
    }
    // 0x800B5910: andi        $a0, $t2, 0x3
    ctx->r4 = ctx->r10 & 0X3;
    // 0x800B5914: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B5918: b           L_800B596C
    // 0x800B591C: mov.d       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
        goto L_800B596C;
    // 0x800B591C: mov.d       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
L_800B5920:
    // 0x800B5920: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5924: nop

    // 0x800B5928: c.lt.d      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.d < ctx->f20.d;
    // 0x800B592C: nop

    // 0x800B5930: bc1f        L_800B596C
    if (!c1cs) {
        // 0x800B5934: nop
    
            goto L_800B596C;
    }
    // 0x800B5934: nop

    // 0x800B5938: c.lt.d      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.d < ctx->f20.d;
    // 0x800B593C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B5940: bc1f        L_800B596C
    if (!c1cs) {
        // 0x800B5944: mov.d       $f16, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
            goto L_800B596C;
    }
    // 0x800B5944: mov.d       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
    // 0x800B5948: nop

L_800B594C:
    // 0x800B594C: div.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x800B5950: lwc1        $f5, 0xD0($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5954: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5958: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800B595C: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x800B5960: nop

    // 0x800B5964: bc1t        L_800B594C
    if (c1cs) {
        // 0x800B5968: nop
    
            goto L_800B594C;
    }
    // 0x800B5968: nop

L_800B596C:
    // 0x800B596C: c.le.d      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.d <= ctx->f6.d;
    // 0x800B5970: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B5974: bc1f        L_800B59B4
    if (!c1cs) {
        // 0x800B5978: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_800B59B4;
    }
    // 0x800B5978: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800B597C: c.le.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d <= ctx->f6.d;
    // 0x800B5980: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B5984: mov.d       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
    // 0x800B5988: bc1f        L_800B59B4
    if (!c1cs) {
        // 0x800B598C: mov.d       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.d = ctx->f18.d;
            goto L_800B59B4;
    }
    // 0x800B598C: mov.d       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.d = ctx->f18.d;
L_800B5990:
    // 0x800B5990: mov.d       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.d = ctx->f0.d;
    // 0x800B5994: mul.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800B5998: lwc1        $f9, 0xD0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B599C: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B59A0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B59A4: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x800B59A8: nop

    // 0x800B59AC: bc1t        L_800B5990
    if (c1cs) {
        // 0x800B59B0: nop
    
            goto L_800B5990;
    }
    // 0x800B59B0: nop

L_800B59B4:
    // 0x800B59B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B59B8: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B59BC: mul.d       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x800B59C0: beq         $s3, $zero, L_800B5A24
    if (ctx->r19 == 0) {
        // 0x800B59C4: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800B5A24;
    }
    // 0x800B59C4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800B59C8: beq         $a0, $zero, L_800B59E0
    if (ctx->r4 == 0) {
        // 0x800B59CC: addu        $v1, $a0, $t2
        ctx->r3 = ADD32(ctx->r4, ctx->r10);
            goto L_800B59E0;
    }
    // 0x800B59CC: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
L_800B59D0:
    // 0x800B59D0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B59D4: bne         $v1, $v0, L_800B59D0
    if (ctx->r3 != ctx->r2) {
        // 0x800B59D8: div.d       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
            goto L_800B59D0;
    }
    // 0x800B59D8: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B59DC: beq         $v0, $zero, L_800B5A24
    if (ctx->r2 == 0) {
        // 0x800B59E0: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800B5A24;
    }
L_800B59E0:
    // 0x800B59E0: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800B59E4: beq         $v0, $zero, L_800B5A0C
    if (ctx->r2 == 0) {
        // 0x800B59E8: div.d       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
            goto L_800B5A0C;
    }
    // 0x800B59E8: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
L_800B59EC:
    // 0x800B59EC: nop

    // 0x800B59F0: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B59F4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800B59F8: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B59FC: nop

    // 0x800B5A00: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B5A04: bne         $v0, $zero, L_800B59EC
    if (ctx->r2 != 0) {
        // 0x800B5A08: div.d       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
            goto L_800B59EC;
    }
    // 0x800B5A08: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
L_800B5A0C:
    // 0x800B5A0C: nop

    // 0x800B5A10: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B5A14: nop

    // 0x800B5A18: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B5A1C: nop

    // 0x800B5A20: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
L_800B5A24:
    // 0x800B5A24: mul.d       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800B5A28: lwc1        $f5, 0xD0($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5A2C: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5A30: sltu        $v0, $zero, $a1
    ctx->r2 = 0 < ctx->r5 ? 1 : 0;
    // 0x800B5A34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B5A38: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x800B5A3C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B5A40: c.le.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d <= ctx->f6.d;
    // 0x800B5A44: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    // 0x800B5A48: bc1f        L_800B5A58
    if (!c1cs) {
        // 0x800B5A4C: swc1        $f7, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
            goto L_800B5A58;
    }
    // 0x800B5A4C: swc1        $f7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
    // 0x800B5A50: mov.d       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.d = ctx->f2.d;
    // 0x800B5A54: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800B5A58:
    // 0x800B5A58: slti        $a2, $s4, 0x64
    ctx->r6 = SIGNED(ctx->r20) < 0X64 ? 1 : 0;
    // 0x800B5A5C: bne         $v0, $zero, L_800B5A74
    if (ctx->r2 != 0) {
        // 0x800B5A60: xori        $a2, $a2, 0x1
        ctx->r6 = ctx->r6 ^ 0X1;
            goto L_800B5A74;
    }
    // 0x800B5A60: xori        $a2, $a2, 0x1
    ctx->r6 = ctx->r6 ^ 0X1;
    // 0x800B5A64: sltu        $a0, $zero, $s5
    ctx->r4 = 0 < ctx->r21 ? 1 : 0;
    // 0x800B5A68: bne         $a0, $zero, L_800B5A74
    if (ctx->r4 != 0) {
        // 0x800B5A6C: nop
    
            goto L_800B5A74;
    }
    // 0x800B5A6C: nop

    // 0x800B5A70: sltu        $a0, $zero, $s6
    ctx->r4 = 0 < ctx->r22 ? 1 : 0;
L_800B5A74:
    // 0x800B5A74: bne         $s3, $zero, L_800B5A80
    if (ctx->r19 != 0) {
        // 0x800B5A78: or          $v1, $s3, $zero
        ctx->r3 = ctx->r19 | 0;
            goto L_800B5A80;
    }
    // 0x800B5A78: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x800B5A7C: sltu        $v1, $zero, $fp
    ctx->r3 = 0 < ctx->r30 ? 1 : 0;
L_800B5A80:
    // 0x800B5A80: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x800B5A84: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x800B5A88: addu        $a1, $t7, $a2
    ctx->r5 = ADD32(ctx->r15, ctx->r6);
    // 0x800B5A8C: bne         $s7, $zero, L_800B5ABC
    if (ctx->r23 != 0) {
        // 0x800B5A90: addiu       $a1, $a1, 0x5
        ctx->r5 = ADD32(ctx->r5, 0X5);
            goto L_800B5ABC;
    }
    // 0x800B5A90: addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
    // 0x800B5A94: bne         $t4, $at, L_800B5ABC
    if (ctx->r12 != ctx->r1) {
        // 0x800B5A98: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5ABC;
    }
    // 0x800B5A98: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5A9C: beq         $v1, $zero, L_800B5ABC
    if (ctx->r3 == 0) {
        // 0x800B5AA0: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5ABC;
    }
    // 0x800B5AA0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5AA4:
    // 0x800B5AA4: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5AA8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5AAC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5AB0: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B5AB4: bne         $v1, $zero, L_800B5AA4
    if (ctx->r3 != 0) {
        // 0x800B5AB8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5AA4;
    }
    // 0x800B5AB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5ABC:
    // 0x800B5ABC: beq         $v0, $zero, L_800B5AD4
    if (ctx->r2 == 0) {
        // 0x800B5AC0: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_800B5AD4;
    }
    // 0x800B5AC0: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800B5AC4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5AC8: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5ACC: b           L_800B5B00
    // 0x800B5AD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B5B00;
    // 0x800B5AD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5AD4:
    // 0x800B5AD4: beq         $s5, $zero, L_800B5AEC
    if (ctx->r21 == 0) {
        // 0x800B5AD8: addiu       $t8, $zero, 0x2B
        ctx->r24 = ADD32(0, 0X2B);
            goto L_800B5AEC;
    }
    // 0x800B5AD8: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x800B5ADC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5AE0: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800B5AE4: b           L_800B5B00
    // 0x800B5AE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B5B00;
    // 0x800B5AE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5AEC:
    // 0x800B5AEC: beq         $s6, $zero, L_800B5B00
    if (ctx->r22 == 0) {
        // 0x800B5AF0: nop
    
            goto L_800B5B00;
    }
    // 0x800B5AF0: nop

    // 0x800B5AF4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5AF8: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5AFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5B00:
    // 0x800B5B00: bne         $s7, $zero, L_800B5B30
    if (ctx->r23 != 0) {
        // 0x800B5B04: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800B5B30;
    }
    // 0x800B5B04: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B5B08: bne         $t4, $at, L_800B5B30
    if (ctx->r12 != ctx->r1) {
        // 0x800B5B0C: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5B30;
    }
    // 0x800B5B0C: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5B10: beq         $v1, $zero, L_800B5B30
    if (ctx->r3 == 0) {
        // 0x800B5B14: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5B30;
    }
    // 0x800B5B14: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5B18:
    // 0x800B5B18: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5B1C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5B20: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5B24: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B5B28: bne         $v1, $zero, L_800B5B18
    if (ctx->r3 != 0) {
        // 0x800B5B2C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5B18;
    }
    // 0x800B5B2C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5B30:
    // 0x800B5B30: lwc1        $f9, 0xD0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5B34: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5B38: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800B5B3C: c.le.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d <= ctx->f8.d;
    // 0x800B5B40: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5B44: bc1f        L_800B5B6C
    if (!c1cs) {
        // 0x800B5B48: addiu       $t6, $zero, 0x2E
        ctx->r14 = ADD32(0, 0X2E);
            goto L_800B5B6C;
    }
    // 0x800B5B48: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
L_800B5B4C:
    // 0x800B5B4C: lwc1        $f11, 0xD0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5B50: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5B54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5B58: sub.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f10.d - ctx->f16.d;
    // 0x800B5B5C: c.le.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d <= ctx->f4.d;
    // 0x800B5B60: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x800B5B64: bc1t        L_800B5B4C
    if (c1cs) {
        // 0x800B5B68: swc1        $f5, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
            goto L_800B5B4C;
    }
    // 0x800B5B68: swc1        $f5, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
L_800B5B6C:
    // 0x800B5B6C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5B70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5B74: bne         $s3, $zero, L_800B5B84
    if (ctx->r19 != 0) {
        // 0x800B5B78: div.d       $f16, $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
            goto L_800B5B84;
    }
    // 0x800B5B78: div.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x800B5B7C: beq         $fp, $zero, L_800B5B90
    if (ctx->r30 == 0) {
        // 0x800B5B80: nop
    
            goto L_800B5B90;
    }
    // 0x800B5B80: nop

L_800B5B84:
    // 0x800B5B84: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5B88: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800B5B8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5B90:
    // 0x800B5B90: beq         $s3, $zero, L_800B5BE4
    if (ctx->r19 == 0) {
        // 0x800B5B94: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800B5BE4;
    }
    // 0x800B5B94: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800B5B98:
    // 0x800B5B98: lwc1        $f7, 0xD0($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5B9C: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5BA0: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800B5BA4: c.le.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d <= ctx->f6.d;
    // 0x800B5BA8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5BAC: bc1f        L_800B5BD4
    if (!c1cs) {
        // 0x800B5BB0: addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
            goto L_800B5BD4;
    }
    // 0x800B5BB0: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
L_800B5BB4:
    // 0x800B5BB4: lwc1        $f9, 0xD0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5BB8: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5BBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5BC0: sub.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f8.d - ctx->f16.d;
    // 0x800B5BC4: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x800B5BC8: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
    // 0x800B5BCC: bc1t        L_800B5BB4
    if (c1cs) {
        // 0x800B5BD0: swc1        $f11, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f_odd[(11 - 1) * 2];
            goto L_800B5BB4;
    }
    // 0x800B5BD0: swc1        $f11, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(11 - 1) * 2];
L_800B5BD4:
    // 0x800B5BD4: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5BD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5BDC: bgtz        $t2, L_800B5B98
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B5BE0: div.d       $f16, $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
            goto L_800B5B98;
    }
    // 0x800B5BE0: div.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
L_800B5BE4:
    // 0x800B5BE4: lbu         $t7, 0x19A($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X19A);
    // 0x800B5BE8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5BEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5BF0: bgez        $s4, L_800B5C4C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800B5BF4: sb          $t7, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r15;
            goto L_800B5C4C;
    }
    // 0x800B5BF4: sb          $t7, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r15;
    // 0x800B5BF8: negu        $s4, $s4
    ctx->r20 = SUB32(0, ctx->r20);
    // 0x800B5BFC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800B5C00: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B5C04: slti        $a2, $s4, 0x64
    ctx->r6 = SIGNED(ctx->r20) < 0X64 ? 1 : 0;
    // 0x800B5C08: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800B5C0C: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5C10: xori        $a2, $a2, 0x1
    ctx->r6 = ctx->r6 ^ 0X1;
    // 0x800B5C14: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5C18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5C1C: mflo        $v1
    ctx->r3 = lo;
    // 0x800B5C20: nop

    // 0x800B5C24: nop

    // 0x800B5C28: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800B5C2C: mfhi        $t8
    ctx->r24 = hi;
    // 0x800B5C30: addiu       $v1, $t8, 0x30
    ctx->r3 = ADD32(ctx->r24, 0X30);
    // 0x800B5C34: nop

    // 0x800B5C38: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B5C3C: mfhi        $a0
    ctx->r4 = hi;
    // 0x800B5C40: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x800B5C44: b           L_800B5C8C
    // 0x800B5C48: nop

        goto L_800B5C8C;
    // 0x800B5C48: nop

L_800B5C4C:
    // 0x800B5C4C: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B5C50: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x800B5C54: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x800B5C58: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5C5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5C60: mflo        $v1
    ctx->r3 = lo;
    // 0x800B5C64: nop

    // 0x800B5C68: nop

    // 0x800B5C6C: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800B5C70: mfhi        $t6
    ctx->r14 = hi;
    // 0x800B5C74: addiu       $v1, $t6, 0x30
    ctx->r3 = ADD32(ctx->r14, 0X30);
    // 0x800B5C78: nop

    // 0x800B5C7C: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B5C80: mfhi        $a0
    ctx->r4 = hi;
    // 0x800B5C84: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x800B5C88: nop

L_800B5C8C:
    // 0x800B5C8C: beq         $a2, $zero, L_800B5CAC
    if (ctx->r6 == 0) {
        // 0x800B5C90: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_800B5CAC;
    }
    // 0x800B5C90: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800B5C94: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B5C98: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5C9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5CA0: mflo        $v0
    ctx->r2 = lo;
    // 0x800B5CA4: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x800B5CA8: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
L_800B5CAC:
    // 0x800B5CAC: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x800B5CB0: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800B5CB4: sb          $a0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r4;
    // 0x800B5CB8: beq         $s7, $zero, L_800B5CE4
    if (ctx->r23 == 0) {
        // 0x800B5CBC: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_800B5CE4;
    }
    // 0x800B5CBC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800B5CC0: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5CC4: beq         $v1, $zero, L_800B5CE4
    if (ctx->r3 == 0) {
        // 0x800B5CC8: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5CE4;
    }
    // 0x800B5CC8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5CCC:
    // 0x800B5CCC: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5CD0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5CD4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5CD8: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5CDC: bne         $v1, $zero, L_800B5CCC
    if (ctx->r3 != 0) {
        // 0x800B5CE0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5CCC;
    }
    // 0x800B5CE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5CE4:
    // 0x800B5CE4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5CE8: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B5CEC: b           L_800B6378
    // 0x800B5CF0: nop

        goto L_800B6378;
    // 0x800B5CF0: nop

L_800B5CF4:
    // 0x800B5CF4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5CF8: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B5CFC: b           L_800B6378
    // 0x800B5D00: nop

        goto L_800B6378;
    // 0x800B5D00: nop

L_800B5D04:
    // 0x800B5D04: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B5D08: lw          $t9, 0x3480($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3480);
    // 0x800B5D0C: mov.d       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.d = ctx->f20.d;
    // 0x800B5D10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B5D14: beq         $t9, $zero, L_800B5D2C
    if (ctx->r25 == 0) {
        // 0x800B5D18: mov.d       $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.d = ctx->f18.d;
            goto L_800B5D2C;
    }
    // 0x800B5D18: mov.d       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.d = ctx->f18.d;
    // 0x800B5D1C: addiu       $t8, $zero, 0x84
    ctx->r24 = ADD32(0, 0X84);
    // 0x800B5D20: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800B5D24: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5D28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5D2C:
    // 0x800B5D2C: bgez        $t2, L_800B5D3C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B5D30: slt         $s3, $zero, $t2
        ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800B5D3C;
    }
    // 0x800B5D30: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B5D34: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x800B5D38: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
L_800B5D3C:
    // 0x800B5D3C: beq         $s3, $zero, L_800B5DA4
    if (ctx->r19 == 0) {
        // 0x800B5D40: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B5DA4;
    }
    // 0x800B5D40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B5D44: andi        $a0, $t2, 0x3
    ctx->r4 = ctx->r10 & 0X3;
    // 0x800B5D48: beq         $a0, $zero, L_800B5D60
    if (ctx->r4 == 0) {
        // 0x800B5D4C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800B5D60;
    }
    // 0x800B5D4C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800B5D50:
    // 0x800B5D50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5D54: bne         $v1, $v0, L_800B5D50
    if (ctx->r3 != ctx->r2) {
        // 0x800B5D58: div.d       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
            goto L_800B5D50;
    }
    // 0x800B5D58: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5D5C: beq         $v0, $t2, L_800B5DA4
    if (ctx->r2 == ctx->r10) {
        // 0x800B5D60: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800B5DA4;
    }
L_800B5D60:
    // 0x800B5D60: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B5D64: beq         $v0, $t2, L_800B5D8C
    if (ctx->r2 == ctx->r10) {
        // 0x800B5D68: div.d       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
            goto L_800B5D8C;
    }
    // 0x800B5D68: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
L_800B5D6C:
    // 0x800B5D6C: nop

    // 0x800B5D70: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5D74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B5D78: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5D7C: nop

    // 0x800B5D80: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5D84: bne         $v0, $t2, L_800B5D6C
    if (ctx->r2 != ctx->r10) {
        // 0x800B5D88: div.d       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
            goto L_800B5D6C;
    }
    // 0x800B5D88: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
L_800B5D8C:
    // 0x800B5D8C: nop

    // 0x800B5D90: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5D94: nop

    // 0x800B5D98: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5D9C: nop

    // 0x800B5DA0: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
L_800B5DA4:
    // 0x800B5DA4: beq         $a2, $zero, L_800B5DC8
    if (ctx->r6 == 0) {
        // 0x800B5DA8: andi        $t7, $s1, 0x1
        ctx->r15 = ctx->r17 & 0X1;
            goto L_800B5DC8;
    }
    // 0x800B5DA8: andi        $t7, $s1, 0x1
    ctx->r15 = ctx->r17 & 0X1;
    // 0x800B5DAC: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5DB0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5DB4: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B5DB8: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B5DBC: lwc1        $f4, -0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0X4);
    // 0x800B5DC0: b           L_800B5E10
    // 0x800B5DC4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
        goto L_800B5E10;
    // 0x800B5DC4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
L_800B5DC8:
    // 0x800B5DC8: beq         $t7, $zero, L_800B5DDC
    if (ctx->r15 == 0) {
        // 0x800B5DCC: andi        $t9, $s1, 0x2
        ctx->r25 = ctx->r17 & 0X2;
            goto L_800B5DDC;
    }
    // 0x800B5DCC: andi        $t9, $s1, 0x2
    ctx->r25 = ctx->r17 & 0X2;
    // 0x800B5DD0: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B5DD4: b           L_800B5E04
    // 0x800B5DD8: addiu       $v1, $s1, -0x16
    ctx->r3 = ADD32(ctx->r17, -0X16);
        goto L_800B5E04;
    // 0x800B5DD8: addiu       $v1, $s1, -0x16
    ctx->r3 = ADD32(ctx->r17, -0X16);
L_800B5DDC:
    // 0x800B5DDC: beq         $t9, $zero, L_800B5DF0
    if (ctx->r25 == 0) {
        // 0x800B5DE0: addiu       $at, $zero, -0x8
        ctx->r1 = ADD32(0, -0X8);
            goto L_800B5DF0;
    }
    // 0x800B5DE0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800B5DE4: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x800B5DE8: b           L_800B5E00
    // 0x800B5DEC: addiu       $a0, $s1, -0x28
    ctx->r4 = ADD32(ctx->r17, -0X28);
        goto L_800B5E00;
    // 0x800B5DEC: addiu       $a0, $s1, -0x28
    ctx->r4 = ADD32(ctx->r17, -0X28);
L_800B5DF0:
    // 0x800B5DF0: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B5DF4: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x800B5DF8: addiu       $s1, $t8, 0x8
    ctx->r17 = ADD32(ctx->r24, 0X8);
    // 0x800B5DFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800B5E00:
    // 0x800B5E00: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800B5E04:
    // 0x800B5E04: lwc1        $f1, -0x8($v1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r3, -0X8);
    // 0x800B5E08: lwc1        $f0, -0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X4);
    // 0x800B5E0C: nop

L_800B5E10:
    // 0x800B5E10: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800B5E14: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B5E18: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B5E1C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B5E20: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B5E24: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x800B5E28: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x800B5E2C: bc1f        L_800B5E3C
    if (!c1cs) {
        // 0x800B5E30: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_800B5E3C;
    }
    // 0x800B5E30: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B5E34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B5E38: neg.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = -ctx->f0.d;
L_800B5E3C:
    // 0x800B5E3C: add.d       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = ctx->f0.d + ctx->f10.d;
    // 0x800B5E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B5E44: c.le.d      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.d <= ctx->f0.d;
    // 0x800B5E48: mov.d       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.d = ctx->f20.d;
    // 0x800B5E4C: bc1f        L_800B5E70
    if (!c1cs) {
        // 0x800B5E50: sltu        $a2, $zero, $a1
        ctx->r6 = 0 < ctx->r5 ? 1 : 0;
            goto L_800B5E70;
    }
    // 0x800B5E50: sltu        $a2, $zero, $a1
    ctx->r6 = 0 < ctx->r5 ? 1 : 0;
L_800B5E54:
    // 0x800B5E54: mov.d       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.d = ctx->f14.d;
    // 0x800B5E58: mul.d       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = MUL_D(ctx->f14.d, ctx->f18.d);
    // 0x800B5E5C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5E60: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800B5E64: nop

    // 0x800B5E68: bc1t        L_800B5E54
    if (c1cs) {
        // 0x800B5E6C: nop
    
            goto L_800B5E54;
    }
    // 0x800B5E6C: nop

L_800B5E70:
    // 0x800B5E70: bne         $a2, $zero, L_800B5E88
    if (ctx->r6 != 0) {
        // 0x800B5E74: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800B5E88;
    }
    // 0x800B5E74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B5E78: sltu        $a0, $zero, $s5
    ctx->r4 = 0 < ctx->r21 ? 1 : 0;
    // 0x800B5E7C: bne         $a0, $zero, L_800B5E88
    if (ctx->r4 != 0) {
        // 0x800B5E80: nop
    
            goto L_800B5E88;
    }
    // 0x800B5E80: nop

    // 0x800B5E84: sltu        $a0, $zero, $s6
    ctx->r4 = 0 < ctx->r22 ? 1 : 0;
L_800B5E88:
    // 0x800B5E88: bne         $s3, $zero, L_800B5E94
    if (ctx->r19 != 0) {
        // 0x800B5E8C: or          $v1, $s3, $zero
        ctx->r3 = ctx->r19 | 0;
            goto L_800B5E94;
    }
    // 0x800B5E8C: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x800B5E90: sltu        $v1, $zero, $fp
    ctx->r3 = 0 < ctx->r30 ? 1 : 0;
L_800B5E94:
    // 0x800B5E94: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x800B5E98: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800B5E9C: bne         $s7, $zero, L_800B5ECC
    if (ctx->r23 != 0) {
        // 0x800B5EA0: addu        $a1, $t7, $t2
        ctx->r5 = ADD32(ctx->r15, ctx->r10);
            goto L_800B5ECC;
    }
    // 0x800B5EA0: addu        $a1, $t7, $t2
    ctx->r5 = ADD32(ctx->r15, ctx->r10);
    // 0x800B5EA4: bne         $t4, $at, L_800B5ECC
    if (ctx->r12 != ctx->r1) {
        // 0x800B5EA8: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5ECC;
    }
    // 0x800B5EA8: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5EAC: beq         $v1, $zero, L_800B5ECC
    if (ctx->r3 == 0) {
        // 0x800B5EB0: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5ECC;
    }
    // 0x800B5EB0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5EB4:
    // 0x800B5EB4: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5EB8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5EBC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5EC0: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B5EC4: bne         $v1, $zero, L_800B5EB4
    if (ctx->r3 != 0) {
        // 0x800B5EC8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5EB4;
    }
    // 0x800B5EC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5ECC:
    // 0x800B5ECC: beq         $a2, $zero, L_800B5EE4
    if (ctx->r6 == 0) {
        // 0x800B5ED0: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_800B5EE4;
    }
    // 0x800B5ED0: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800B5ED4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5ED8: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5EDC: b           L_800B5F10
    // 0x800B5EE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B5F10;
    // 0x800B5EE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5EE4:
    // 0x800B5EE4: beq         $s5, $zero, L_800B5EFC
    if (ctx->r21 == 0) {
        // 0x800B5EE8: addiu       $t8, $zero, 0x2B
        ctx->r24 = ADD32(0, 0X2B);
            goto L_800B5EFC;
    }
    // 0x800B5EE8: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x800B5EEC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5EF0: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800B5EF4: b           L_800B5F10
    // 0x800B5EF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B5F10;
    // 0x800B5EF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5EFC:
    // 0x800B5EFC: beq         $s6, $zero, L_800B5F10
    if (ctx->r22 == 0) {
        // 0x800B5F00: nop
    
            goto L_800B5F10;
    }
    // 0x800B5F00: nop

    // 0x800B5F04: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5F08: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5F0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5F10:
    // 0x800B5F10: bne         $s7, $zero, L_800B5F40
    if (ctx->r23 != 0) {
        // 0x800B5F14: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800B5F40;
    }
    // 0x800B5F14: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B5F18: bne         $t4, $at, L_800B5F40
    if (ctx->r12 != ctx->r1) {
        // 0x800B5F1C: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5F40;
    }
    // 0x800B5F1C: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5F20: beq         $v1, $zero, L_800B5F40
    if (ctx->r3 == 0) {
        // 0x800B5F24: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5F40;
    }
    // 0x800B5F24: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5F28:
    // 0x800B5F28: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5F2C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5F30: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5F34: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B5F38: bne         $v1, $zero, L_800B5F28
    if (ctx->r3 != 0) {
        // 0x800B5F3C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5F28;
    }
    // 0x800B5F3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5F40:
    // 0x800B5F40: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800B5F44: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800B5F48: bc1f        L_800B5F6C
    if (!c1cs) {
        // 0x800B5F4C: nop
    
            goto L_800B5F6C;
    }
    // 0x800B5F4C: nop

L_800B5F50:
    // 0x800B5F50: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x800B5F54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5F58: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800B5F5C: nop

    // 0x800B5F60: bc1t        L_800B5F50
    if (c1cs) {
        // 0x800B5F64: nop
    
            goto L_800B5F50;
    }
    // 0x800B5F64: nop

    // 0x800B5F68: nop

L_800B5F6C:
    // 0x800B5F6C: div.d       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f18.d);
    // 0x800B5F70: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5F74: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5F78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5F7C: c.le.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d <= ctx->f2.d;
    // 0x800B5F80: nop

    // 0x800B5F84: bc1t        L_800B5F40
    if (c1cs) {
        // 0x800B5F88: nop
    
            goto L_800B5F40;
    }
    // 0x800B5F88: nop

    // 0x800B5F8C: bne         $s3, $zero, L_800B5F9C
    if (ctx->r19 != 0) {
        // 0x800B5F90: addiu       $t6, $zero, 0x2E
        ctx->r14 = ADD32(0, 0X2E);
            goto L_800B5F9C;
    }
    // 0x800B5F90: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800B5F94: beq         $fp, $zero, L_800B5FA8
    if (ctx->r30 == 0) {
        // 0x800B5F98: nop
    
            goto L_800B5FA8;
    }
    // 0x800B5F98: nop

L_800B5F9C:
    // 0x800B5F9C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5FA0: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800B5FA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5FA8:
    // 0x800B5FA8: beq         $s3, $zero, L_800B5FEC
    if (ctx->r19 == 0) {
        // 0x800B5FAC: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5FEC;
    }
    // 0x800B5FAC: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
L_800B5FB0:
    // 0x800B5FB0: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800B5FB4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800B5FB8: bc1f        L_800B5FD8
    if (!c1cs) {
        // 0x800B5FBC: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800B5FD8;
    }
    // 0x800B5FBC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800B5FC0:
    // 0x800B5FC0: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x800B5FC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5FC8: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800B5FCC: nop

    // 0x800B5FD0: bc1t        L_800B5FC0
    if (c1cs) {
        // 0x800B5FD4: nop
    
            goto L_800B5FC0;
    }
    // 0x800B5FD4: nop

L_800B5FD8:
    // 0x800B5FD8: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800B5FDC: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5FE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5FE4: bgtz        $t2, L_800B5FB0
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B5FE8: div.d       $f2, $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f18.d);
            goto L_800B5FB0;
    }
    // 0x800B5FE8: div.d       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f18.d);
L_800B5FEC:
    // 0x800B5FEC: beq         $s7, $zero, L_800B6014
    if (ctx->r23 == 0) {
        // 0x800B5FF0: nop
    
            goto L_800B6014;
    }
    // 0x800B5FF0: nop

    // 0x800B5FF4: beq         $v1, $zero, L_800B6014
    if (ctx->r3 == 0) {
        // 0x800B5FF8: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B6014;
    }
    // 0x800B5FF8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5FFC:
    // 0x800B5FFC: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B6000: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B6004: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6008: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B600C: bne         $v1, $zero, L_800B5FFC
    if (ctx->r3 != 0) {
        // 0x800B6010: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5FFC;
    }
    // 0x800B6010: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B6014:
    // 0x800B6014: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B6018: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B601C: b           L_800B6378
    // 0x800B6020: nop

        goto L_800B6378;
    // 0x800B6020: nop

L_800B6024:
    // 0x800B6024: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B6028: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B602C: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B6030: addiu       $s1, $t7, 0x4
    ctx->r17 = ADD32(ctx->r15, 0X4);
    // 0x800B6034: lw          $t9, -0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, -0X4);
    // 0x800B6038: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B603C: sra         $t8, $t9, 31
    ctx->r24 = S32(SIGNED(ctx->r25) >> 31);
    // 0x800B6040: sw          $t8, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r24;
    // 0x800B6044: bne         $s7, $zero, L_800B606C
    if (ctx->r23 != 0) {
        // 0x800B6048: sw          $t9, 0x18C($sp)
        MEM_W(0X18C, ctx->r29) = ctx->r25;
            goto L_800B606C;
    }
    // 0x800B6048: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800B604C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B6050: blez        $t0, L_800B6070
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B6054: lw          $t7, 0x18C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18C);
            goto L_800B6070;
    }
    // 0x800B6054: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
L_800B6058:
    // 0x800B6058: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B605C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6060: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B6064: bgtz        $t0, L_800B6058
    if (SIGNED(ctx->r8) > 0) {
        // 0x800B6068: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B6058;
    }
    // 0x800B6068: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B606C:
    // 0x800B606C: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
L_800B6070:
    // 0x800B6070: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6074: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B6078: beq         $s7, $zero, L_800B609C
    if (ctx->r23 == 0) {
        // 0x800B607C: sb          $t7, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r15;
            goto L_800B609C;
    }
    // 0x800B607C: sb          $t7, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r15;
    // 0x800B6080: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B6084: blez        $t0, L_800B609C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B6088: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B609C;
    }
L_800B6088:
    // 0x800B6088: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B608C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6090: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B6094: bgtz        $t0, L_800B6088
    if (SIGNED(ctx->r8) > 0) {
        // 0x800B6098: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B6088;
    }
    // 0x800B6098: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B609C:
    // 0x800B609C: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B60A0: b           L_800B6378
    // 0x800B60A4: nop

        goto L_800B6378;
    // 0x800B60A4: nop

L_800B60A8:
    // 0x800B60A8: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B60AC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B60B0: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B60B4: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B60B8: lw          $a1, -0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, -0X4);
    // 0x800B60BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B60C0: bne         $a1, $zero, L_800B60F4
    if (ctx->r5 != 0) {
        // 0x800B60C4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800B60F4;
    }
    // 0x800B60C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800B60C8: beq         $t2, $at, L_800B60DC
    if (ctx->r10 == ctx->r1) {
        // 0x800B60CC: lui         $a1, 0x800F
        ctx->r5 = S32(0X800F << 16);
            goto L_800B60DC;
    }
    // 0x800B60CC: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800B60D0: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x800B60D4: bne         $at, $zero, L_800B60E8
    if (ctx->r1 != 0) {
        // 0x800B60D8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B60E8;
    }
    // 0x800B60D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800B60DC:
    // 0x800B60DC: addiu       $a1, $a1, -0x6E2C
    ctx->r5 = ADD32(ctx->r5, -0X6E2C);
    // 0x800B60E0: b           L_800B6144
    // 0x800B60E4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
        goto L_800B6144;
    // 0x800B60E4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_800B60E8:
    // 0x800B60E8: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800B60EC: b           L_800B6144
    // 0x800B60F0: addiu       $a1, $a1, -0x6E30
    ctx->r5 = ADD32(ctx->r5, -0X6E30);
        goto L_800B6144;
    // 0x800B60F0: addiu       $a1, $a1, -0x6E30
    ctx->r5 = ADD32(ctx->r5, -0X6E30);
L_800B60F4:
    // 0x800B60F4: sw          $a1, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r5;
    // 0x800B60F8: sw          $t0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r8;
    // 0x800B60FC: sw          $t1, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r9;
    // 0x800B6100: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800B6104: sw          $t3, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r11;
    // 0x800B6108: swc1        $f17, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800B610C: jal         0x800CE6FC
    // 0x800B6110: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    strlen_recomp(rdram, ctx);
        goto after_1;
    // 0x800B6110: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x800B6114: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800B6118: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B611C: lw          $a1, 0x17C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X17C);
    // 0x800B6120: lw          $t0, 0x1A0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A0);
    // 0x800B6124: lw          $t1, 0x1AC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1AC);
    // 0x800B6128: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800B612C: lw          $t3, 0x1B4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B4);
    // 0x800B6130: lwc1        $f17, 0xE0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x800B6134: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800B6138: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B613C: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800B6140: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800B6144:
    // 0x800B6144: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B6148: beq         $t2, $at, L_800B615C
    if (ctx->r10 == ctx->r1) {
        // 0x800B614C: slt         $at, $t2, $a0
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800B615C;
    }
    // 0x800B614C: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B6150: beq         $at, $zero, L_800B615C
    if (ctx->r1 == 0) {
        // 0x800B6154: nop
    
            goto L_800B615C;
    }
    // 0x800B6154: nop

    // 0x800B6158: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
L_800B615C:
    // 0x800B615C: bne         $s7, $zero, L_800B6188
    if (ctx->r23 != 0) {
        // 0x800B6160: subu        $t0, $t0, $a0
        ctx->r8 = SUB32(ctx->r8, ctx->r4);
            goto L_800B6188;
    }
    // 0x800B6160: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x800B6164: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B6168: beq         $v1, $zero, L_800B6188
    if (ctx->r3 == 0) {
        // 0x800B616C: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B6188;
    }
    // 0x800B616C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B6170:
    // 0x800B6170: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B6174: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B6178: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B617C: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B6180: bne         $v1, $zero, L_800B6170
    if (ctx->r3 != 0) {
        // 0x800B6184: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B6170;
    }
    // 0x800B6184: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B6188:
    // 0x800B6188: slt         $v1, $zero, $a0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B618C: beq         $v1, $zero, L_800B61B4
    if (ctx->r3 == 0) {
        // 0x800B6190: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_800B61B4;
    }
    // 0x800B6190: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_800B6194:
    // 0x800B6194: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B6198: slt         $v1, $zero, $a0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B619C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800B61A0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B61A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B61A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B61AC: bne         $v1, $zero, L_800B6194
    if (ctx->r3 != 0) {
        // 0x800B61B0: sb          $t6, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r14;
            goto L_800B6194;
    }
    // 0x800B61B0: sb          $t6, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r14;
L_800B61B4:
    // 0x800B61B4: beq         $s7, $zero, L_800B61DC
    if (ctx->r23 == 0) {
        // 0x800B61B8: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B61DC;
    }
    // 0x800B61B8: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B61BC: beq         $v1, $zero, L_800B61DC
    if (ctx->r3 == 0) {
        // 0x800B61C0: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B61DC;
    }
    // 0x800B61C0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B61C4:
    // 0x800B61C4: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B61C8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B61CC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B61D0: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B61D4: bne         $v1, $zero, L_800B61C4
    if (ctx->r3 != 0) {
        // 0x800B61D8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B61C4;
    }
    // 0x800B61D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B61DC:
    // 0x800B61DC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B61E0: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B61E4: b           L_800B6378
    // 0x800B61E8: nop

        goto L_800B6378;
    // 0x800B61E8: nop

L_800B61EC:
    // 0x800B61EC: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B61F0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B61F4: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B61F8: addiu       $s1, $t7, 0x4
    ctx->r17 = ADD32(ctx->r15, 0X4);
    // 0x800B61FC: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B6200: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B6204: beq         $v0, $zero, L_800B6240
    if (ctx->r2 == 0) {
        // 0x800B6208: addiu       $a0, $a0, -0x6E24
        ctx->r4 = ADD32(ctx->r4, -0X6E24);
            goto L_800B6240;
    }
    // 0x800B6208: addiu       $a0, $a0, -0x6E24
    ctx->r4 = ADD32(ctx->r4, -0X6E24);
    // 0x800B620C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B6210: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x800B6214: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B6218: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B621C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800B6220: sb          $t8, 0x19A($sp)
    MEM_B(0X19A, ctx->r29) = ctx->r24;
    // 0x800B6224: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800B6228: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B622C: sw          $v0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r2;
    // 0x800B6230: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B6234: addiu       $s3, $zero, 0x78
    ctx->r19 = ADD32(0, 0X78);
    // 0x800B6238: b           L_800B55B8
    // 0x800B623C: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
        goto L_800B55B8;
    // 0x800B623C: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B6240:
    // 0x800B6240: bne         $s7, $zero, L_800B626C
    if (ctx->r23 != 0) {
        // 0x800B6244: addiu       $t0, $t0, -0x5
        ctx->r8 = ADD32(ctx->r8, -0X5);
            goto L_800B626C;
    }
    // 0x800B6244: addiu       $t0, $t0, -0x5
    ctx->r8 = ADD32(ctx->r8, -0X5);
    // 0x800B6248: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B624C: beq         $v1, $zero, L_800B626C
    if (ctx->r3 == 0) {
        // 0x800B6250: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B626C;
    }
    // 0x800B6250: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B6254:
    // 0x800B6254: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B6258: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B625C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6260: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B6264: bne         $v1, $zero, L_800B6254
    if (ctx->r3 != 0) {
        // 0x800B6268: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B6254;
    }
    // 0x800B6268: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B626C:
    // 0x800B626C: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800B6270: lbu         $t9, -0x6E24($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X6E24);
    // 0x800B6274: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800B6278: beq         $t9, $zero, L_800B62A0
    if (ctx->r25 == 0) {
        // 0x800B627C: addiu       $t8, $t8, -0x6E24
        ctx->r24 = ADD32(ctx->r24, -0X6E24);
            goto L_800B62A0;
    }
    // 0x800B627C: addiu       $t8, $t8, -0x6E24
    ctx->r24 = ADD32(ctx->r24, -0X6E24);
    // 0x800B6280: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x800B6284: nop

L_800B6288:
    // 0x800B6288: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B628C: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x800B6290: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6294: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B6298: bne         $v0, $zero, L_800B6288
    if (ctx->r2 != 0) {
        // 0x800B629C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800B6288;
    }
    // 0x800B629C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800B62A0:
    // 0x800B62A0: beq         $s7, $zero, L_800B62C8
    if (ctx->r23 == 0) {
        // 0x800B62A4: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B62C8;
    }
    // 0x800B62A4: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B62A8: beq         $v1, $zero, L_800B62C8
    if (ctx->r3 == 0) {
        // 0x800B62AC: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B62C8;
    }
    // 0x800B62AC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B62B0:
    // 0x800B62B0: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B62B4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B62B8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B62BC: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B62C0: bne         $v1, $zero, L_800B62B0
    if (ctx->r3 != 0) {
        // 0x800B62C4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B62B0;
    }
    // 0x800B62C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B62C8:
    // 0x800B62C8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B62CC: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B62D0: b           L_800B6378
    // 0x800B62D4: nop

        goto L_800B6378;
    // 0x800B62D4: nop

L_800B62D8:
    // 0x800B62D8: beq         $a0, $zero, L_800B6304
    if (ctx->r4 == 0) {
        // 0x800B62DC: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800B6304;
    }
    // 0x800B62DC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B62E0: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B62E4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B62E8: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B62EC: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B62F0: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B62F4: sra         $t8, $t1, 31
    ctx->r24 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800B62F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B62FC: b           L_800B6360
    // 0x800B6300: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
        goto L_800B6360;
    // 0x800B6300: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_800B6304:
    // 0x800B6304: beq         $a1, $zero, L_800B6324
    if (ctx->r5 == 0) {
        // 0x800B6308: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B6324;
    }
    // 0x800B6308: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B630C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B6310: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B6314: addiu       $s1, $t7, 0x4
    ctx->r17 = ADD32(ctx->r15, 0X4);
    // 0x800B6318: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B631C: b           L_800B6360
    // 0x800B6320: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_800B6360;
    // 0x800B6320: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800B6324:
    // 0x800B6324: bne         $a2, $zero, L_800B6348
    if (ctx->r6 != 0) {
        // 0x800B6328: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B6348;
    }
    // 0x800B6328: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B632C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B6330: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B6334: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B6338: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B633C: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B6340: b           L_800B6360
    // 0x800B6344: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_800B6360;
    // 0x800B6344: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800B6348:
    // 0x800B6348: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B634C: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x800B6350: addiu       $s1, $t8, 0x4
    ctx->r17 = ADD32(ctx->r24, 0X4);
    // 0x800B6354: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B6358: nop

    // 0x800B635C: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_800B6360:
    // 0x800B6360: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B6364: b           L_800B6378
    // 0x800B6368: nop

        goto L_800B6378;
    // 0x800B6368: nop

L_800B636C:
    // 0x800B636C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B6370: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B6374: nop

L_800B6378:
    // 0x800B6378: beq         $v1, $zero, L_800B638C
    if (ctx->r3 == 0) {
        // 0x800B637C: addiu       $t9, $zero, 0x83
        ctx->r25 = ADD32(0, 0X83);
            goto L_800B638C;
    }
    // 0x800B637C: addiu       $t9, $zero, 0x83
    ctx->r25 = ADD32(0, 0X83);
    // 0x800B6380: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6384: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B6388: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B638C:
    // 0x800B638C: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
L_800B6390:
    // 0x800B6390: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x800B6394: bne         $v1, $zero, L_800B5020
    if (ctx->r3 != 0) {
        // 0x800B6398: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B5020;
    }
    // 0x800B6398: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B639C: swc1        $f17, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800B63A0: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    // 0x800B63A4: sw          $s4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r20;
L_800B63A8:
    // 0x800B63A8: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800B63AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800B63B0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800B63B4: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800B63B8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800B63BC: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800B63C0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800B63C4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800B63C8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800B63CC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800B63D0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B63D4: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B63D8: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800B63DC: addiu       $sp, $sp, 0x1B8
    ctx->r29 = ADD32(ctx->r29, 0X1B8);
    // 0x800B63E0: jr          $ra
    // 0x800B63E4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800B63E4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void debug_text_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B63E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B63EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B63F0: jal         0x8007B2C4
    // 0x800B63F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    load_texture(rdram, ctx);
        goto after_0;
    // 0x800B63F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800B63F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B63FC: sw          $v0, -0x7DA0($at)
    MEM_W(-0X7DA0, ctx->r1) = ctx->r2;
    // 0x800B6400: jal         0x8007B2C4
    // 0x800B6404: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    load_texture(rdram, ctx);
        goto after_1;
    // 0x800B6404: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800B6408: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B640C: sw          $v0, -0x7D9C($at)
    MEM_W(-0X7D9C, ctx->r1) = ctx->r2;
    // 0x800B6410: jal         0x8007B2C4
    // 0x800B6414: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_texture(rdram, ctx);
        goto after_2;
    // 0x800B6414: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800B6418: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B641C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B6420: sw          $v0, -0x7D98($at)
    MEM_W(-0X7D98, ctx->r1) = ctx->r2;
    // 0x800B6424: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B6428: addiu       $t6, $t6, -0x7D68
    ctx->r14 = ADD32(ctx->r14, -0X7D68);
    // 0x800B642C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6430: sw          $t6, -0x7468($at)
    MEM_W(-0X7468, ctx->r1) = ctx->r14;
    // 0x800B6434: jr          $ra
    // 0x800B6438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B6438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void render_printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B643C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B6440: lw          $t6, -0x7468($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7468);
    // 0x800B6444: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B6448: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B644C: addiu       $t7, $t7, -0x7D68
    ctx->r15 = ADD32(ctx->r15, -0X7D68);
    // 0x800B6450: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800B6454: slti        $at, $t8, 0x801
    ctx->r1 = SIGNED(ctx->r24) < 0X801 ? 1 : 0;
    // 0x800B6458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B645C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B6460: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B6464: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B6468: bne         $at, $zero, L_800B6478
    if (ctx->r1 != 0) {
        // 0x800B646C: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800B6478;
    }
    // 0x800B646C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800B6470: b           L_800B64C8
    // 0x800B6474: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B64C8;
    // 0x800B6474: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B6478:
    // 0x800B6478: jal         0x800B4F68
    // 0x800B647C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprintfSetSpacingCodes(rdram, ctx);
        goto after_0;
    // 0x800B647C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800B6480: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B6484: lw          $a0, -0x7468($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7468);
    // 0x800B6488: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800B648C: jal         0x800B4FA0
    // 0x800B6490: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    vsprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800B6490: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800B6494: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B6498: jal         0x800B4F68
    // 0x800B649C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sprintfSetSpacingCodes(rdram, ctx);
        goto after_2;
    // 0x800B649C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x800B64A0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800B64A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B64A8: blez        $v1, L_800B64C4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B64AC: addiu       $v0, $v0, -0x7468
        ctx->r2 = ADD32(ctx->r2, -0X7468);
            goto L_800B64C4;
    }
    // 0x800B64AC: addiu       $v0, $v0, -0x7468
    ctx->r2 = ADD32(ctx->r2, -0X7468);
    // 0x800B64B0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800B64B4: nop

    // 0x800B64B8: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x800B64BC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B64C0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800B64C4:
    // 0x800B64C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B64C8:
    // 0x800B64C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B64CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B64D0: jr          $ra
    // 0x800B64D4: nop

    return;
    // 0x800B64D4: nop

;}
RECOMP_FUNC void debug_text_print(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B64D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B64DC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B64E0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B64E4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800B64E8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B64EC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B64F0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B64F4: jal         0x800784A4
    // 0x800B64F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    rdp_init(rdram, ctx);
        goto after_0;
    // 0x800B64F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B64FC: jal         0x8007A970
    // 0x800B6500: nop

    fb_size(rdram, ctx);
        goto after_1;
    // 0x800B6500: nop

    after_1:
    // 0x800B6504: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B6508: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B650C: addiu       $a1, $a1, -0x7D70
    ctx->r5 = ADD32(ctx->r5, -0X7D70);
    // 0x800B6510: addiu       $a0, $a0, -0x7D6E
    ctx->r4 = ADD32(ctx->r4, -0X7D6E);
    // 0x800B6514: srl         $t6, $v0, 16
    ctx->r14 = S32(U32(ctx->r2) >> 16);
    // 0x800B6518: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800B651C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x800B6520: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800B6524: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x800B6528: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800B652C: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800B6530: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B6534: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x800B6538: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800B653C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B6540: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B6544: bgez        $t0, L_800B655C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B6548: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B655C;
    }
    // 0x800B6548: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B654C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B6550: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B6554: nop

    // 0x800B6558: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800B655C:
    // 0x800B655C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B6560: lhu         $t5, 0x0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X0);
    // 0x800B6564: nop

    // 0x800B6568: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800B656C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B6570: nop

    // 0x800B6574: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B6578: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B657C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B6580: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B6584: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B6588: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x800B658C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B6590: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x800B6594: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x800B6598: bgez        $t5, L_800B65AC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B659C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800B65AC;
    }
    // 0x800B659C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B65A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B65A4: nop

    // 0x800B65A8: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800B65AC:
    // 0x800B65AC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B65B0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B65B4: nop

    // 0x800B65B8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B65BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B65C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B65C4: nop

    // 0x800B65C8: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800B65CC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800B65D0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B65D4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B65D8: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x800B65DC: jal         0x800B73B0
    // 0x800B65E0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    debug_text_bounds(rdram, ctx);
        goto after_2;
    // 0x800B65E0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    after_2:
    // 0x800B65E4: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x800B65E8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B65EC: addiu       $t0, $s1, 0x8
    ctx->r8 = ADD32(ctx->r17, 0X8);
    // 0x800B65F0: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    // 0x800B65F4: addiu       $t2, $t2, 0x3548
    ctx->r10 = ADD32(ctx->r10, 0X3548);
    // 0x800B65F8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800B65FC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B6600: addiu       $s0, $s0, -0x7D68
    ctx->r16 = ADD32(ctx->r16, -0X7D68);
    // 0x800B6604: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x800B6608: jal         0x800B7440
    // 0x800B660C: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    debug_text_origin(rdram, ctx);
        goto after_3;
    // 0x800B660C: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    after_3:
    // 0x800B6610: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800B6614: addiu       $s4, $s4, -0x7D74
    ctx->r20 = ADD32(ctx->r20, -0X7D74);
    // 0x800B6618: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800B661C: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800B6620: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6624: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800B6628: lhu         $a3, -0x7D94($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X7D94);
    // 0x800B662C: sw          $zero, -0x7D8C($at)
    MEM_W(-0X7D8C, ctx->r1) = 0;
    // 0x800B6630: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6634: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B6638: lhu         $v0, -0x7D92($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7D92);
    // 0x800B663C: sh          $a3, -0x7D90($at)
    MEM_H(-0X7D90, ctx->r1) = ctx->r7;
    // 0x800B6640: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B6644: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6648: addiu       $s2, $s2, -0x7468
    ctx->r18 = ADD32(ctx->r18, -0X7468);
    // 0x800B664C: sh          $v0, -0x7D8E($at)
    MEM_H(-0X7D8E, ctx->r1) = ctx->r2;
    // 0x800B6650: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800B6654: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B6658: addiu       $t5, $t5, -0x7D68
    ctx->r13 = ADD32(ctx->r13, -0X7D68);
    // 0x800B665C: beq         $t5, $t6, L_800B66A0
    if (ctx->r13 == ctx->r14) {
        // 0x800B6660: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_800B66A0;
    }
    // 0x800B6660: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800B6664: addiu       $s1, $s1, -0x7D88
    ctx->r17 = ADD32(ctx->r17, -0X7D88);
L_800B6668:
    // 0x800B6668: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800B666C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B6670: jal         0x800B6A9C
    // 0x800B6674: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    debug_text_parse(rdram, ctx);
        goto after_4;
    // 0x800B6674: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800B6678: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800B667C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800B6680: bne         $s0, $t7, L_800B6668
    if (ctx->r16 != ctx->r15) {
        // 0x800B6684: nop
    
            goto L_800B6668;
    }
    // 0x800B6684: nop

    // 0x800B6688: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800B668C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B6690: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B6694: lhu         $v0, -0x7D92($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7D92);
    // 0x800B6698: lhu         $a3, -0x7D94($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X7D94);
    // 0x800B669C: addiu       $s0, $s0, -0x7D68
    ctx->r16 = ADD32(ctx->r16, -0X7D68);
L_800B66A0:
    // 0x800B66A0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B66A4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B66A8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800B66AC: lhu         $a2, -0x7D8E($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X7D8E);
    // 0x800B66B0: lhu         $a1, -0x7D90($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D90);
    // 0x800B66B4: addiu       $t4, $v0, 0xA
    ctx->r12 = ADD32(ctx->r2, 0XA);
    // 0x800B66B8: addiu       $s1, $s1, -0x7D88
    ctx->r17 = ADD32(ctx->r17, -0X7D88);
    // 0x800B66BC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800B66C0: jal         0x800B6EBC
    // 0x800B66C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    debug_text_background(rdram, ctx);
        goto after_5;
    // 0x800B66C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x800B66C8: jal         0x800B7440
    // 0x800B66CC: nop

    debug_text_origin(rdram, ctx);
        goto after_6;
    // 0x800B66CC: nop

    after_6:
    // 0x800B66D0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B66D4: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x800B66D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B66DC: sw          $zero, -0x7D8C($at)
    MEM_W(-0X7D8C, ctx->r1) = 0;
    // 0x800B66E0: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x800B66E4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B66E8: addiu       $t9, $t9, -0x7D68
    ctx->r25 = ADD32(ctx->r25, -0X7D68);
    // 0x800B66EC: beq         $t9, $t0, L_800B6714
    if (ctx->r25 == ctx->r8) {
        // 0x800B66F0: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800B6714;
    }
    // 0x800B66F0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800B66F4:
    // 0x800B66F4: sw          $s4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r20;
    // 0x800B66F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B66FC: jal         0x800B6A9C
    // 0x800B6700: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    debug_text_parse(rdram, ctx);
        goto after_7;
    // 0x800B6700: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800B6704: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800B6708: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800B670C: bne         $s0, $t1, L_800B66F4
    if (ctx->r16 != ctx->r9) {
        // 0x800B6710: nop
    
            goto L_800B66F4;
    }
    // 0x800B6710: nop

L_800B6714:
    // 0x800B6714: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B6718: addiu       $t2, $t2, -0x7D68
    ctx->r10 = ADD32(ctx->r10, -0X7D68);
    // 0x800B671C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800B6720: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800B6724: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B6728: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B672C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B6730: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6734: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B6738: jr          $ra
    // 0x800B673C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B673C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void debug_text_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B6744: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B6748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B674C: addiu       $t6, $t6, -0x7D68
    ctx->r14 = ADD32(ctx->r14, -0X7D68);
    // 0x800B6750: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6754: jal         0x800B7440
    // 0x800B6758: sw          $t6, -0x7468($at)
    MEM_W(-0X7468, ctx->r1) = ctx->r14;
    debug_text_origin(rdram, ctx);
        goto after_0;
    // 0x800B6758: sw          $t6, -0x7468($at)
    MEM_W(-0X7468, ctx->r1) = ctx->r14;
    after_0:
    // 0x800B675C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B6760: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B6764: jr          $ra
    // 0x800B6768: nop

    return;
    // 0x800B6768: nop

;}
RECOMP_FUNC void set_render_printf_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B676C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B6770: addiu       $v0, $v0, -0x7468
    ctx->r2 = ADD32(ctx->r2, -0X7468);
    // 0x800B6774: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800B6778: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B677C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B6780: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800B6784: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800B6788: addiu       $t0, $zero, 0x81
    ctx->r8 = ADD32(0, 0X81);
    // 0x800B678C: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x800B6790: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B6794: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x800B6798: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B679C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800B67A0: sb          $a0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r4;
    // 0x800B67A4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800B67A8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B67AC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800B67B0: or          $t8, $a2, $zero
    ctx->r24 = ctx->r6 | 0;
    // 0x800B67B4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B67B8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800B67BC: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    // 0x800B67C0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B67C4: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x800B67C8: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800B67CC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B67D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B67D4: sb          $a2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r6;
    // 0x800B67D8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800B67DC: nop

    // 0x800B67E0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B67E4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800B67E8: sb          $a3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r7;
    // 0x800B67EC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800B67F0: nop

    // 0x800B67F4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B67F8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B67FC: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x800B6800: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B6804: nop

    // 0x800B6808: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B680C: jr          $ra
    // 0x800B6810: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800B6810: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void set_render_printf_background_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6814: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B6818: addiu       $v0, $v0, -0x7468
    ctx->r2 = ADD32(ctx->r2, -0X7468);
    // 0x800B681C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800B6820: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B6824: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B6828: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800B682C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800B6830: addiu       $t0, $zero, 0x85
    ctx->r8 = ADD32(0, 0X85);
    // 0x800B6834: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x800B6838: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B683C: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x800B6840: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B6844: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800B6848: sb          $a0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r4;
    // 0x800B684C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800B6850: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B6854: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800B6858: or          $t8, $a2, $zero
    ctx->r24 = ctx->r6 | 0;
    // 0x800B685C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B6860: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800B6864: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    // 0x800B6868: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B686C: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x800B6870: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800B6874: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B6878: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B687C: sb          $a2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r6;
    // 0x800B6880: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800B6884: nop

    // 0x800B6888: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B688C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800B6890: sb          $a3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r7;
    // 0x800B6894: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800B6898: nop

    // 0x800B689C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B68A0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B68A4: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x800B68A8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B68AC: nop

    // 0x800B68B0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B68B4: jr          $ra
    // 0x800B68B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800B68B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void set_render_printf_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B68BC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B68C0: addiu       $a2, $a2, -0x7468
    ctx->r6 = ADD32(ctx->r6, -0X7468);
    // 0x800B68C4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B68C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B68CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B68D0: addiu       $t8, $zero, 0x82
    ctx->r24 = ADD32(0, 0X82);
    // 0x800B68D4: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800B68D8: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x800B68DC: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x800B68E0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B68E4: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x800B68E8: sb          $a0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r4;
    // 0x800B68EC: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800B68F0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B68F4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B68F8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800B68FC: sra         $t7, $a0, 8
    ctx->r15 = S32(SIGNED(ctx->r4) >> 8);
    // 0x800B6900: sb          $t7, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r15;
    // 0x800B6904: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B6908: sra         $t6, $a1, 8
    ctx->r14 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800B690C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B6910: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x800B6914: sb          $a1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r5;
    // 0x800B6918: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800B691C: nop

    // 0x800B6920: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B6924: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800B6928: sb          $t6, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r14;
    // 0x800B692C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800B6930: nop

    // 0x800B6934: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B6938: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800B693C: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x800B6940: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800B6944: nop

    // 0x800B6948: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B694C: jr          $ra
    // 0x800B6950: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    return;
    // 0x800B6950: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
;}
RECOMP_FUNC void debug_text_width(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6954: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x800B6958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B695C: sw          $a0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r4;
    // 0x800B6960: sw          $a1, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r5;
    // 0x800B6964: sw          $a2, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r6;
    // 0x800B6968: sw          $a3, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r7;
    // 0x800B696C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800B6970: jal         0x800B4F68
    // 0x800B6974: sw          $zero, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = 0;
    sprintfSetSpacingCodes(rdram, ctx);
        goto after_0;
    // 0x800B6974: sw          $zero, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = 0;
    after_0:
    // 0x800B6978: lw          $a1, 0x138($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X138);
    // 0x800B697C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800B6980: jal         0x800B4FA0
    // 0x800B6984: addiu       $a2, $sp, 0x13C
    ctx->r6 = ADD32(ctx->r29, 0X13C);
    vsprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800B6984: addiu       $a2, $sp, 0x13C
    ctx->r6 = ADD32(ctx->r29, 0X13C);
    after_1:
    // 0x800B6988: jal         0x800B4F68
    // 0x800B698C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprintfSetSpacingCodes(rdram, ctx);
        goto after_2;
    // 0x800B698C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800B6990: lbu         $t7, 0x2C($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2C);
    // 0x800B6994: lw          $a3, 0x12C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X12C);
    // 0x800B6998: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x800B699C: beq         $t7, $zero, L_800B6A8C
    if (ctx->r15 == 0) {
        // 0x800B69A0: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800B6A8C;
    }
    // 0x800B69A0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800B69A4: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x800B69A8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B69AC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B69B0: addiu       $a2, $a2, -0x7D74
    ctx->r6 = ADD32(ctx->r6, -0X7D74);
    // 0x800B69B4: addiu       $t2, $t2, 0x3484
    ctx->r10 = ADD32(ctx->r10, 0X3484);
    // 0x800B69B8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800B69BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B69C0: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x800B69C4: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x800B69C8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800B69CC:
    // 0x800B69CC: beq         $v0, $t0, L_800B6A7C
    if (ctx->r2 == ctx->r8) {
        // 0x800B69D0: nop
    
            goto L_800B6A7C;
    }
    // 0x800B69D0: nop

    // 0x800B69D4: bne         $v0, $t1, L_800B69E4
    if (ctx->r2 != ctx->r9) {
        // 0x800B69D8: slti        $at, $v0, 0x40
        ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
            goto L_800B69E4;
    }
    // 0x800B69D8: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x800B69DC: b           L_800B6A7C
    // 0x800B69E0: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
        goto L_800B6A7C;
    // 0x800B69E0: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
L_800B69E4:
    // 0x800B69E4: beq         $at, $zero, L_800B6A0C
    if (ctx->r1 == 0) {
        // 0x800B69E8: slti        $at, $v0, 0x60
        ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
            goto L_800B6A0C;
    }
    // 0x800B69E8: slti        $at, $v0, 0x60
    ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
    // 0x800B69EC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800B69F0: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x800B69F4: nop

    // 0x800B69F8: addiu       $t9, $t8, -0x21
    ctx->r25 = ADD32(ctx->r24, -0X21);
    // 0x800B69FC: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x800B6A00: b           L_800B6A54
    // 0x800B6A04: andi        $a1, $t9, 0xFF
    ctx->r5 = ctx->r25 & 0XFF;
        goto L_800B6A54;
    // 0x800B6A04: andi        $a1, $t9, 0xFF
    ctx->r5 = ctx->r25 & 0XFF;
    // 0x800B6A08: slti        $at, $v0, 0x60
    ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
L_800B6A0C:
    // 0x800B6A0C: beq         $at, $zero, L_800B6A34
    if (ctx->r1 == 0) {
        // 0x800B6A10: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_800B6A34;
    }
    // 0x800B6A10: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800B6A14: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800B6A18: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x800B6A1C: nop

    // 0x800B6A20: addiu       $t7, $t5, -0x40
    ctx->r15 = ADD32(ctx->r13, -0X40);
    // 0x800B6A24: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x800B6A28: b           L_800B6A54
    // 0x800B6A2C: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
        goto L_800B6A54;
    // 0x800B6A2C: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
    // 0x800B6A30: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
L_800B6A34:
    // 0x800B6A34: beq         $at, $zero, L_800B6A54
    if (ctx->r1 == 0) {
        // 0x800B6A38: nop
    
            goto L_800B6A54;
    }
    // 0x800B6A38: nop

    // 0x800B6A3C: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800B6A40: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800B6A44: nop

    // 0x800B6A48: addiu       $t8, $t6, -0x60
    ctx->r24 = ADD32(ctx->r14, -0X60);
    // 0x800B6A4C: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x800B6A50: andi        $a1, $t8, 0xFF
    ctx->r5 = ctx->r24 & 0XFF;
L_800B6A54:
    // 0x800B6A54: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B6A58: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800B6A5C: sll         $t5, $t9, 6
    ctx->r13 = S32(ctx->r25 << 6);
    // 0x800B6A60: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x800B6A64: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x800B6A68: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800B6A6C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800B6A70: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800B6A74: subu        $a3, $t9, $a0
    ctx->r7 = SUB32(ctx->r25, ctx->r4);
    // 0x800B6A78: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800B6A7C:
    // 0x800B6A7C: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    // 0x800B6A80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B6A84: bne         $a1, $zero, L_800B69CC
    if (ctx->r5 != 0) {
        // 0x800B6A88: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_800B69CC;
    }
    // 0x800B6A88: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800B6A8C:
    // 0x800B6A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B6A90: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // 0x800B6A94: jr          $ra
    // 0x800B6A98: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800B6A98: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
;}
RECOMP_FUNC void debug_text_parse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6A9C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B6AA0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800B6AA4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800B6AA8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800B6AAC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800B6AB0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800B6AB4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B6AB8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B6ABC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B6AC0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B6AC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B6AC8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800B6ACC: lbu         $s1, 0x0($a1)
    ctx->r17 = MEM_BU(ctx->r5, 0X0);
    // 0x800B6AD0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800B6AD4: beq         $s1, $zero, L_800B6E84
    if (ctx->r17 == 0) {
        // 0x800B6AD8: addiu       $s0, $a1, 0x1
        ctx->r16 = ADD32(ctx->r5, 0X1);
            goto L_800B6E84;
    }
    // 0x800B6AD8: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x800B6ADC: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800B6AE0: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800B6AE4: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800B6AE8: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800B6AEC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B6AF0: addiu       $s2, $s2, -0x7D94
    ctx->r18 = ADD32(ctx->r18, -0X7D94);
    // 0x800B6AF4: addiu       $s4, $s4, -0x7D92
    ctx->r20 = ADD32(ctx->r20, -0X7D92);
    // 0x800B6AF8: addiu       $s6, $s6, -0x7D90
    ctx->r22 = ADD32(ctx->r22, -0X7D90);
    // 0x800B6AFC: addiu       $s7, $s7, -0x7D8E
    ctx->r23 = ADD32(ctx->r23, -0X7D8E);
    // 0x800B6B00: addiu       $fp, $fp, -0x7D88
    ctx->r30 = ADD32(ctx->r30, -0X7D88);
    // 0x800B6B04: slti        $at, $s1, 0xB
    ctx->r1 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
L_800B6B08:
    // 0x800B6B08: bne         $at, $zero, L_800B6B54
    if (ctx->r1 != 0) {
        // 0x800B6B0C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800B6B54;
    }
    // 0x800B6B0C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B6B10: slti        $at, $s1, 0x21
    ctx->r1 = SIGNED(ctx->r17) < 0X21 ? 1 : 0;
    // 0x800B6B14: bne         $at, $zero, L_800B6B40
    if (ctx->r1 != 0) {
        // 0x800B6B18: addiu       $t6, $s1, -0x81
        ctx->r14 = ADD32(ctx->r17, -0X81);
            goto L_800B6B40;
    }
    // 0x800B6B18: addiu       $t6, $s1, -0x81
    ctx->r14 = ADD32(ctx->r17, -0X81);
    // 0x800B6B1C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x800B6B20: beq         $at, $zero, L_800B6DDC
    if (ctx->r1 == 0) {
        // 0x800B6B24: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800B6DDC;
    }
    // 0x800B6B24: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B6B28: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B6B2C: addu        $at, $at, $t6
    gpr jr_addend_800B6B38 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B6B30: lw          $t6, -0x6C28($at)
    ctx->r14 = ADD32(ctx->r1, -0X6C28);
    // 0x800B6B34: nop

    // 0x800B6B38: jr          $t6
    // 0x800B6B3C: nop

    switch (jr_addend_800B6B38 >> 2) {
        case 0: goto L_800B6BB8; break;
        case 1: goto L_800B6CA0; break;
        case 2: goto L_800B6B74; break;
        case 3: goto L_800B6B94; break;
        case 4: goto L_800B6C2C; break;
        default: switch_error(__func__, 0x800B6B38, 0x800E93D8);
    }
    // 0x800B6B3C: nop

L_800B6B40:
    // 0x800B6B40: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B6B44: beq         $s1, $at, L_800B6D24
    if (ctx->r17 == ctx->r1) {
        // 0x800B6B48: addiu       $s3, $zero, 0x6
        ctx->r19 = ADD32(0, 0X6);
            goto L_800B6D24;
    }
    // 0x800B6B48: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x800B6B4C: b           L_800B6DE0
    // 0x800B6B50: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800B6DE0;
    // 0x800B6B50: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B6B54:
    // 0x800B6B54: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800B6B58: beq         $s1, $at, L_800B6D9C
    if (ctx->r17 == ctx->r1) {
        // 0x800B6B5C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B6D9C;
    }
    // 0x800B6B5C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6B60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800B6B64: beq         $s1, $at, L_800B6D40
    if (ctx->r17 == ctx->r1) {
        // 0x800B6B68: nop
    
            goto L_800B6D40;
    }
    // 0x800B6B68: nop

    // 0x800B6B6C: b           L_800B6DE0
    // 0x800B6B70: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800B6DE0;
    // 0x800B6B70: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B6B74:
    // 0x800B6B74: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6B78: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6B7C: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6B80: sw          $zero, -0x7D8C($at)
    MEM_W(-0X7D8C, ctx->r1) = 0;
    // 0x800B6B84: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6B88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B6B8C: b           L_800B6E04
    // 0x800B6B90: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6B90: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6B94:
    // 0x800B6B94: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B6B98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6B9C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6BA0: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6BA4: sw          $t7, -0x7D8C($at)
    MEM_W(-0X7D8C, ctx->r1) = ctx->r15;
    // 0x800B6BA8: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6BAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B6BB0: b           L_800B6E04
    // 0x800B6BB4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6BB4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6BB8:
    // 0x800B6BB8: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B6BBC: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800B6BC0: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800B6BC4: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800B6BC8: lbu         $a3, 0x3($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X3);
    // 0x800B6BCC: beq         $t8, $zero, L_800B6C10
    if (ctx->r24 == 0) {
        // 0x800B6BD0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800B6C10;
    }
    // 0x800B6BD0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B6BD4: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800B6BD8: andi        $t3, $a1, 0xFF
    ctx->r11 = ctx->r5 & 0XFF;
    // 0x800B6BDC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800B6BE0: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x800B6BE4: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800B6BE8: sll         $t2, $a0, 24
    ctx->r10 = S32(ctx->r4 << 24);
    // 0x800B6BEC: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x800B6BF0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800B6BF4: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800B6BF8: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x800B6BFC: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800B6C00: andi        $t9, $a3, 0xFF
    ctx->r25 = ctx->r7 & 0XFF;
    // 0x800B6C04: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800B6C08: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x800B6C0C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
L_800B6C10:
    // 0x800B6C10: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6C14: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6C18: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6C1C: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6C20: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6C24: b           L_800B6E04
    // 0x800B6C28: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6C28: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6C2C:
    // 0x800B6C2C: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x800B6C30: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800B6C34: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800B6C38: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800B6C3C: lbu         $a3, 0x3($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X3);
    // 0x800B6C40: bne         $t1, $zero, L_800B6C84
    if (ctx->r9 != 0) {
        // 0x800B6C44: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800B6C84;
    }
    // 0x800B6C44: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B6C48: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800B6C4C: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x800B6C50: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800B6C54: sw          $t3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r11;
    // 0x800B6C58: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800B6C5C: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B6C60: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x800B6C64: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x800B6C68: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800B6C6C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800B6C70: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800B6C74: andi        $t3, $a3, 0xFF
    ctx->r11 = ctx->r7 & 0XFF;
    // 0x800B6C78: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800B6C7C: or          $t2, $t1, $t3
    ctx->r10 = ctx->r9 | ctx->r11;
    // 0x800B6C80: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
L_800B6C84:
    // 0x800B6C84: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6C88: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6C8C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6C90: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6C94: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6C98: b           L_800B6E04
    // 0x800B6C9C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6C9C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6CA0:
    // 0x800B6CA0: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x800B6CA4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B6CA8: bne         $t4, $zero, L_800B6CCC
    if (ctx->r12 != 0) {
        // 0x800B6CAC: nop
    
            goto L_800B6CCC;
    }
    // 0x800B6CAC: nop

    // 0x800B6CB0: lhu         $t5, 0x0($s4)
    ctx->r13 = MEM_HU(ctx->r20, 0X0);
    // 0x800B6CB4: lhu         $a1, 0x0($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0X0);
    // 0x800B6CB8: lhu         $a2, 0x0($s7)
    ctx->r6 = MEM_HU(ctx->r23, 0X0);
    // 0x800B6CBC: lhu         $a3, 0x0($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6CC0: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x800B6CC4: jal         0x800B6EBC
    // 0x800B6CC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    debug_text_background(rdram, ctx);
        goto after_0;
    // 0x800B6CC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
L_800B6CCC:
    // 0x800B6CCC: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x800B6CD0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6CD4: sh          $t9, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r25;
    // 0x800B6CD8: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x800B6CDC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6CE0: sll         $t0, $t8, 8
    ctx->r8 = S32(ctx->r24 << 8);
    // 0x800B6CE4: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x800B6CE8: sh          $t1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r9;
    // 0x800B6CEC: lbu         $t2, 0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2);
    // 0x800B6CF0: andi        $a0, $t1, 0xFFFF
    ctx->r4 = ctx->r9 & 0XFFFF;
    // 0x800B6CF4: sh          $t2, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r10;
    // 0x800B6CF8: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x800B6CFC: sh          $a0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r4;
    // 0x800B6D00: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B6D04: or          $t7, $t2, $t5
    ctx->r15 = ctx->r10 | ctx->r13;
    // 0x800B6D08: sh          $t7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r15;
    // 0x800B6D0C: sh          $t7, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r15;
    // 0x800B6D10: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6D14: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6D18: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B6D1C: b           L_800B6E04
    // 0x800B6D20: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6D20: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6D24:
    // 0x800B6D24: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6D28: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6D2C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6D30: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6D34: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6D38: b           L_800B6E04
    // 0x800B6D3C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6D3C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6D40:
    // 0x800B6D40: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B6D44: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B6D48: bne         $t8, $zero, L_800B6D6C
    if (ctx->r24 != 0) {
        // 0x800B6D4C: nop
    
            goto L_800B6D6C;
    }
    // 0x800B6D4C: nop

    // 0x800B6D50: lhu         $t9, 0x0($s4)
    ctx->r25 = MEM_HU(ctx->r20, 0X0);
    // 0x800B6D54: lhu         $a1, 0x0($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0X0);
    // 0x800B6D58: lhu         $a2, 0x0($s7)
    ctx->r6 = MEM_HU(ctx->r23, 0X0);
    // 0x800B6D5C: lhu         $a3, 0x0($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6D60: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x800B6D64: jal         0x800B6EBC
    // 0x800B6D68: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    debug_text_background(rdram, ctx);
        goto after_1;
    // 0x800B6D68: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
L_800B6D6C:
    // 0x800B6D6C: jal         0x800B7464
    // 0x800B6D70: nop

    debug_text_newline(rdram, ctx);
        goto after_2;
    // 0x800B6D70: nop

    after_2:
    // 0x800B6D74: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6D78: lhu         $t1, 0x0($s4)
    ctx->r9 = MEM_HU(ctx->r20, 0X0);
    // 0x800B6D7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6D80: sh          $a0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r4;
    // 0x800B6D84: sh          $t1, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r9;
    // 0x800B6D88: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6D8C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6D90: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6D94: b           L_800B6E04
    // 0x800B6D98: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6D98: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6D9C:
    // 0x800B6D9C: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6DA0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6DA4: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6DA8: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6DAC: bgez        $a0, L_800B6DC0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800B6DB0: andi        $v0, $a0, 0x1F
        ctx->r2 = ctx->r4 & 0X1F;
            goto L_800B6DC0;
    }
    // 0x800B6DB0: andi        $v0, $a0, 0x1F
    ctx->r2 = ctx->r4 & 0X1F;
    // 0x800B6DB4: beq         $v0, $zero, L_800B6DC0
    if (ctx->r2 == 0) {
        // 0x800B6DB8: nop
    
            goto L_800B6DC0;
    }
    // 0x800B6DB8: nop

    // 0x800B6DBC: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
L_800B6DC0:
    // 0x800B6DC0: bne         $v0, $zero, L_800B6DD0
    if (ctx->r2 != 0) {
        // 0x800B6DC4: addiu       $a1, $a1, -0x10
        ctx->r5 = ADD32(ctx->r5, -0X10);
            goto L_800B6DD0;
    }
    // 0x800B6DC4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x800B6DC8: b           L_800B6E04
    // 0x800B6DCC: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
        goto L_800B6E04;
    // 0x800B6DCC: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
L_800B6DD0:
    // 0x800B6DD0: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800B6DD4: b           L_800B6E04
    // 0x800B6DD8: subu        $s3, $t3, $v0
    ctx->r19 = SUB32(ctx->r11, ctx->r2);
        goto L_800B6E04;
    // 0x800B6DD8: subu        $s3, $t3, $v0
    ctx->r19 = SUB32(ctx->r11, ctx->r2);
L_800B6DDC:
    // 0x800B6DDC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B6DE0:
    // 0x800B6DE0: jal         0x800B6F5C
    // 0x800B6DE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    debug_text_character(rdram, ctx);
        goto after_3;
    // 0x800B6DE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800B6DE8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6DEC: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6DF0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6DF4: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6DF8: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6DFC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800B6E00: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6E04:
    // 0x800B6E04: beq         $v1, $zero, L_800B6E20
    if (ctx->r3 == 0) {
        // 0x800B6E08: slti        $at, $s1, 0x20
        ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
            goto L_800B6E20;
    }
    // 0x800B6E08: slti        $at, $s1, 0x20
    ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
    // 0x800B6E0C: bne         $at, $zero, L_800B6E20
    if (ctx->r1 != 0) {
        // 0x800B6E10: slti        $at, $s1, 0x80
        ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
            goto L_800B6E20;
    }
    // 0x800B6E10: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // 0x800B6E14: beq         $at, $zero, L_800B6E24
    if (ctx->r1 == 0) {
        // 0x800B6E18: addu        $t4, $a0, $s3
        ctx->r12 = ADD32(ctx->r4, ctx->r19);
            goto L_800B6E24;
    }
    // 0x800B6E18: addu        $t4, $a0, $s3
    ctx->r12 = ADD32(ctx->r4, ctx->r19);
    // 0x800B6E1C: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
L_800B6E20:
    // 0x800B6E20: addu        $t4, $a0, $s3
    ctx->r12 = ADD32(ctx->r4, ctx->r19);
L_800B6E24:
    // 0x800B6E24: andi        $a3, $t4, 0xFFFF
    ctx->r7 = ctx->r12 & 0XFFFF;
    // 0x800B6E28: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800B6E2C: beq         $at, $zero, L_800B6E74
    if (ctx->r1 == 0) {
        // 0x800B6E30: sh          $t4, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r12;
            goto L_800B6E74;
    }
    // 0x800B6E30: sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
    // 0x800B6E34: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800B6E38: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B6E3C: bne         $t2, $zero, L_800B6E5C
    if (ctx->r10 != 0) {
        // 0x800B6E40: nop
    
            goto L_800B6E5C;
    }
    // 0x800B6E40: nop

    // 0x800B6E44: lhu         $t5, 0x0($s4)
    ctx->r13 = MEM_HU(ctx->r20, 0X0);
    // 0x800B6E48: lhu         $a1, 0x0($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0X0);
    // 0x800B6E4C: lhu         $a2, 0x0($s7)
    ctx->r6 = MEM_HU(ctx->r23, 0X0);
    // 0x800B6E50: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x800B6E54: jal         0x800B6EBC
    // 0x800B6E58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    debug_text_background(rdram, ctx);
        goto after_4;
    // 0x800B6E58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_4:
L_800B6E5C:
    // 0x800B6E5C: jal         0x800B7464
    // 0x800B6E60: nop

    debug_text_newline(rdram, ctx);
        goto after_5;
    // 0x800B6E60: nop

    after_5:
    // 0x800B6E64: lhu         $t7, 0x0($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6E68: lhu         $t8, 0x0($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X0);
    // 0x800B6E6C: sh          $t7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r15;
    // 0x800B6E70: sh          $t8, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r24;
L_800B6E74:
    // 0x800B6E74: lbu         $s1, 0x0($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X0);
    // 0x800B6E78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B6E7C: bne         $s1, $zero, L_800B6B08
    if (ctx->r17 != 0) {
        // 0x800B6E80: slti        $at, $s1, 0xB
        ctx->r1 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
            goto L_800B6B08;
    }
    // 0x800B6E80: slti        $at, $s1, 0xB
    ctx->r1 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
L_800B6E84:
    // 0x800B6E84: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800B6E88: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B6E8C: subu        $v0, $s0, $t9
    ctx->r2 = SUB32(ctx->r16, ctx->r25);
    // 0x800B6E90: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B6E94: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B6E98: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B6E9C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6EA0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B6EA4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800B6EA8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800B6EAC: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800B6EB0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800B6EB4: jr          $ra
    // 0x800B6EB8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800B6EB8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void debug_text_background(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6EBC: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B6EC0: xor         $t6, $a1, $a3
    ctx->r14 = ctx->r5 ^ ctx->r7;
    // 0x800B6EC4: xor         $t8, $a2, $t7
    ctx->r24 = ctx->r6 ^ ctx->r15;
    // 0x800B6EC8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800B6ECC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800B6ED0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B6ED4: bne         $t9, $zero, L_800B6F54
    if (ctx->r25 != 0) {
        // 0x800B6ED8: sltiu       $at, $a1, 0x2
        ctx->r1 = ctx->r5 < 0X2 ? 1 : 0;
            goto L_800B6F54;
    }
    // 0x800B6ED8: sltiu       $at, $a1, 0x2
    ctx->r1 = ctx->r5 < 0X2 ? 1 : 0;
    // 0x800B6EDC: bne         $at, $zero, L_800B6EE8
    if (ctx->r1 != 0) {
        // 0x800B6EE0: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_800B6EE8;
    }
    // 0x800B6EE0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800B6EE4: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
L_800B6EE8:
    // 0x800B6EE8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B6EEC: lui         $t2, 0xFCFF
    ctx->r10 = S32(0XFCFF << 16);
    // 0x800B6EF0: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800B6EF4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800B6EF8: lui         $t3, 0xFFFD
    ctx->r11 = S32(0XFFFD << 16);
    // 0x800B6EFC: ori         $t3, $t3, 0xF6FB
    ctx->r11 = ctx->r11 | 0XF6FB;
    // 0x800B6F00: ori         $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 | 0XFFFF;
    // 0x800B6F04: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800B6F08: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800B6F0C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B6F10: andi        $t5, $a3, 0x3FF
    ctx->r13 = ctx->r7 & 0X3FF;
    // 0x800B6F14: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B6F18: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B6F1C: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800B6F20: sll         $t7, $t5, 14
    ctx->r15 = S32(ctx->r13 << 14);
    // 0x800B6F24: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800B6F28: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800B6F2C: andi        $t5, $a2, 0x3FF
    ctx->r13 = ctx->r6 & 0X3FF;
    // 0x800B6F30: andi        $t3, $a1, 0x3FF
    ctx->r11 = ctx->r5 & 0X3FF;
    // 0x800B6F34: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x800B6F38: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800B6F3C: sll         $t4, $t3, 14
    ctx->r12 = S32(ctx->r11 << 14);
    // 0x800B6F40: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800B6F44: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800B6F48: or          $t2, $t6, $t1
    ctx->r10 = ctx->r14 | ctx->r9;
    // 0x800B6F4C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800B6F50: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_800B6F54:
    // 0x800B6F54: jr          $ra
    // 0x800B6F58: nop

    return;
    // 0x800B6F58: nop

;}
RECOMP_FUNC void debug_text_character(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6F5C: slti        $at, $a1, 0x40
    ctx->r1 = SIGNED(ctx->r5) < 0X40 ? 1 : 0;
    // 0x800B6F60: beq         $at, $zero, L_800B7070
    if (ctx->r1 == 0) {
        // 0x800B6F64: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B7070;
    }
    // 0x800B6F64: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6F68: addiu       $v1, $v1, -0x7D74
    ctx->r3 = ADD32(ctx->r3, -0X7D74);
    // 0x800B6F6C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B6F70: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B6F74: beq         $t6, $zero, L_800B7068
    if (ctx->r14 == 0) {
        // 0x800B6F78: nop
    
            goto L_800B7068;
    }
    // 0x800B6F78: nop

    // 0x800B6F7C: lw          $t7, -0x7D88($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D88);
    // 0x800B6F80: lui         $t9, 0xFD70
    ctx->r25 = S32(0XFD70 << 16);
    // 0x800B6F84: beq         $t7, $zero, L_800B7064
    if (ctx->r15 == 0) {
        // 0x800B6F88: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_800B7064;
    }
    // 0x800B6F88: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B6F8C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6F90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B6F94: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B6F98: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B6F9C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B6FA0: lw          $t4, -0x7DA0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DA0);
    // 0x800B6FA4: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800B6FA8: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800B6FAC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B6FB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6FB4: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x800B6FB8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B6FBC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B6FC0: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800B6FC4: lui         $t7, 0xF570
    ctx->r15 = S32(0XF570 << 16);
    // 0x800B6FC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B6FCC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B6FD0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6FD4: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800B6FD8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B6FDC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B6FE0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B6FE4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B6FE8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6FEC: lui         $t7, 0x741
    ctx->r15 = S32(0X741 << 16);
    // 0x800B6FF0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B6FF4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B6FF8: ori         $t7, $t7, 0xF056
    ctx->r15 = ctx->r15 | 0XF056;
    // 0x800B6FFC: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800B7000: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B7004: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B7008: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B700C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800B7010: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B7014: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B7018: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B701C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B7020: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7024: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800B7028: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B702C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B7030: lui         $t5, 0xF568
    ctx->r13 = S32(0XF568 << 16);
    // 0x800B7034: ori         $t5, $t5, 0x3000
    ctx->r13 = ctx->r13 | 0X3000;
    // 0x800B7038: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B703C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B7040: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B7044: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7048: lui         $t9, 0x2F
    ctx->r25 = S32(0X2F << 16);
    // 0x800B704C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B7050: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B7054: ori         $t9, $t9, 0xC028
    ctx->r25 = ctx->r25 | 0XC028;
    // 0x800B7058: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800B705C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B7060: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800B7064:
    // 0x800B7064: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800B7068:
    // 0x800B7068: b           L_800B7294
    // 0x800B706C: addiu       $a1, $a1, -0x21
    ctx->r5 = ADD32(ctx->r5, -0X21);
        goto L_800B7294;
    // 0x800B706C: addiu       $a1, $a1, -0x21
    ctx->r5 = ADD32(ctx->r5, -0X21);
L_800B7070:
    // 0x800B7070: slti        $at, $a1, 0x60
    ctx->r1 = SIGNED(ctx->r5) < 0X60 ? 1 : 0;
    // 0x800B7074: beq         $at, $zero, L_800B7184
    if (ctx->r1 == 0) {
        // 0x800B7078: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B7184;
    }
    // 0x800B7078: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B707C: addiu       $v1, $v1, -0x7D74
    ctx->r3 = ADD32(ctx->r3, -0X7D74);
    // 0x800B7080: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800B7084: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B7088: beq         $a2, $t4, L_800B717C
    if (ctx->r6 == ctx->r12) {
        // 0x800B708C: lui         $t5, 0x8013
        ctx->r13 = S32(0X8013 << 16);
            goto L_800B717C;
    }
    // 0x800B708C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B7090: lw          $t5, -0x7D88($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D88);
    // 0x800B7094: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x800B7098: beq         $t5, $zero, L_800B7178
    if (ctx->r13 == 0) {
        // 0x800B709C: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800B7178;
    }
    // 0x800B709C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B70A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B70A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B70A8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B70AC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B70B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B70B4: lw          $t8, -0x7D9C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D9C);
    // 0x800B70B8: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800B70BC: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800B70C0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B70C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B70C8: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x800B70CC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B70D0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B70D4: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B70D8: lui         $t5, 0xF570
    ctx->r13 = S32(0XF570 << 16);
    // 0x800B70DC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B70E0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B70E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B70E8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800B70EC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B70F0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B70F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B70F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B70FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7100: lui         $t5, 0x755
    ctx->r13 = S32(0X755 << 16);
    // 0x800B7104: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B7108: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B710C: ori         $t5, $t5, 0x3043
    ctx->r13 = ctx->r13 | 0X3043;
    // 0x800B7110: lui         $t4, 0xF300
    ctx->r12 = S32(0XF300 << 16);
    // 0x800B7114: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B7118: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B711C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7120: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B7124: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B7128: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B712C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B7130: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B7134: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7138: lui         $t4, 0x8
    ctx->r12 = S32(0X8 << 16);
    // 0x800B713C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B7140: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B7144: lui         $t9, 0xF568
    ctx->r25 = S32(0XF568 << 16);
    // 0x800B7148: ori         $t9, $t9, 0x3E00
    ctx->r25 = ctx->r25 | 0X3E00;
    // 0x800B714C: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x800B7150: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B7154: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B7158: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B715C: lui         $t7, 0x3D
    ctx->r15 = S32(0X3D << 16);
    // 0x800B7160: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B7164: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B7168: ori         $t7, $t7, 0xC028
    ctx->r15 = ctx->r15 | 0XC028;
    // 0x800B716C: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800B7170: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B7174: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_800B7178:
    // 0x800B7178: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
L_800B717C:
    // 0x800B717C: b           L_800B7294
    // 0x800B7180: addiu       $a1, $a1, -0x40
    ctx->r5 = ADD32(ctx->r5, -0X40);
        goto L_800B7294;
    // 0x800B7180: addiu       $a1, $a1, -0x40
    ctx->r5 = ADD32(ctx->r5, -0X40);
L_800B7184:
    // 0x800B7184: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x800B7188: beq         $at, $zero, L_800B7294
    if (ctx->r1 == 0) {
        // 0x800B718C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B7294;
    }
    // 0x800B718C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B7190: addiu       $v1, $v1, -0x7D74
    ctx->r3 = ADD32(ctx->r3, -0X7D74);
    // 0x800B7194: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800B7198: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800B719C: beq         $a2, $t8, L_800B7294
    if (ctx->r6 == ctx->r24) {
        // 0x800B71A0: addiu       $a1, $a1, -0x60
        ctx->r5 = ADD32(ctx->r5, -0X60);
            goto L_800B7294;
    }
    // 0x800B71A0: addiu       $a1, $a1, -0x60
    ctx->r5 = ADD32(ctx->r5, -0X60);
    // 0x800B71A4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B71A8: lw          $t9, -0x7D88($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D88);
    // 0x800B71AC: lui         $t5, 0xFD70
    ctx->r13 = S32(0XFD70 << 16);
    // 0x800B71B0: beq         $t9, $zero, L_800B7290
    if (ctx->r25 == 0) {
        // 0x800B71B4: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800B7290;
    }
    // 0x800B71B4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B71B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B71BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B71C0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B71C4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B71C8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B71CC: lw          $t6, -0x7D98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D98);
    // 0x800B71D0: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800B71D4: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800B71D8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B71DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B71E0: lui         $t4, 0x708
    ctx->r12 = S32(0X708 << 16);
    // 0x800B71E4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B71E8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B71EC: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x800B71F0: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x800B71F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B71F8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B71FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7200: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800B7204: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B7208: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B720C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B7210: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B7214: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7218: lui         $t9, 0x741
    ctx->r25 = S32(0X741 << 16);
    // 0x800B721C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B7220: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B7224: ori         $t9, $t9, 0xF056
    ctx->r25 = ctx->r25 | 0XF056;
    // 0x800B7228: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800B722C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B7230: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B7234: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7238: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800B723C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B7240: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B7244: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B7248: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B724C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7250: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x800B7254: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B7258: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B725C: lui         $t7, 0xF568
    ctx->r15 = S32(0XF568 << 16);
    // 0x800B7260: ori         $t7, $t7, 0x3000
    ctx->r15 = ctx->r15 | 0X3000;
    // 0x800B7264: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800B7268: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B726C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B7270: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7274: lui         $t5, 0x2F
    ctx->r13 = S32(0X2F << 16);
    // 0x800B7278: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B727C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B7280: ori         $t5, $t5, 0xC028
    ctx->r13 = ctx->r13 | 0XC028;
    // 0x800B7284: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x800B7288: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B728C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_800B7290:
    // 0x800B7290: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
L_800B7294:
    // 0x800B7294: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B7298: addiu       $v1, $v1, -0x7D74
    ctx->r3 = ADD32(ctx->r3, -0X7D74);
    // 0x800B729C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B72A0: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x800B72A4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800B72A8: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800B72AC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B72B0: addiu       $t4, $t4, 0x3484
    ctx->r12 = ADD32(ctx->r12, 0X3484);
    // 0x800B72B4: addu        $v0, $t9, $t4
    ctx->r2 = ADD32(ctx->r25, ctx->r12);
    // 0x800B72B8: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x800B72BC: lbu         $t5, 0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1);
    // 0x800B72C0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B72C4: lw          $t6, -0x7D88($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D88);
    // 0x800B72C8: subu        $a3, $t5, $a2
    ctx->r7 = SUB32(ctx->r13, ctx->r6);
    // 0x800B72CC: beq         $t6, $zero, L_800B73A8
    if (ctx->r14 == 0) {
        // 0x800B72D0: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800B73A8;
    }
    // 0x800B72D0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800B72D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B72D8: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x800B72DC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B72E0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B72E4: lui         $t9, 0xFFFE
    ctx->r25 = S32(0XFFFE << 16);
    // 0x800B72E8: ori         $t9, $t9, 0xF379
    ctx->r25 = ctx->r25 | 0XF379;
    // 0x800B72EC: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x800B72F0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B72F4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B72F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B72FC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B7300: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B7304: addiu       $t2, $t2, -0x7D94
    ctx->r10 = ADD32(ctx->r10, -0X7D94);
    // 0x800B7308: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B730C: lhu         $t5, 0x0($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X0);
    // 0x800B7310: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7314: addu        $t6, $t5, $a3
    ctx->r14 = ADD32(ctx->r13, ctx->r7);
    // 0x800B7318: addiu       $t3, $t3, -0x7D92
    ctx->r11 = ADD32(ctx->r11, -0X7D92);
    // 0x800B731C: lhu         $t5, 0x0($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X0);
    // 0x800B7320: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B7324: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B7328: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800B732C: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x800B7330: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B7334: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800B7338: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x800B733C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B7340: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x800B7344: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B7348: lhu         $t5, 0x0($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X0);
    // 0x800B734C: lhu         $t8, 0x0($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X0);
    // 0x800B7350: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B7354: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B7358: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B735C: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x800B7360: sll         $t4, $t7, 12
    ctx->r12 = S32(ctx->r15 << 12);
    // 0x800B7364: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x800B7368: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B736C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7370: sll         $t5, $a2, 21
    ctx->r13 = S32(ctx->r6 << 21);
    // 0x800B7374: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B7378: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B737C: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x800B7380: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B7384: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B7388: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B738C: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800B7390: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B7394: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B7398: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x800B739C: lui         $t7, 0xB200
    ctx->r15 = S32(0XB200 << 16);
    // 0x800B73A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B73A4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_800B73A8:
    // 0x800B73A8: jr          $ra
    // 0x800B73AC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800B73AC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
;}
RECOMP_FUNC void debug_text_bounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B73B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B73B4: lhu         $v0, -0x7D70($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7D70);
    // 0x800B73B8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800B73BC: slti        $at, $v0, 0x141
    ctx->r1 = SIGNED(ctx->r2) < 0X141 ? 1 : 0;
    // 0x800B73C0: beq         $at, $zero, L_800B73E4
    if (ctx->r1 == 0) {
        // 0x800B73C4: addiu       $t9, $v0, -0x20
        ctx->r25 = ADD32(ctx->r2, -0X20);
            goto L_800B73E4;
    }
    // 0x800B73C4: addiu       $t9, $v0, -0x20
    ctx->r25 = ADD32(ctx->r2, -0X20);
    // 0x800B73C8: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800B73CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B73D0: sw          $t6, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = ctx->r14;
    // 0x800B73D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B73D8: addiu       $t7, $v0, -0x10
    ctx->r15 = ADD32(ctx->r2, -0X10);
    // 0x800B73DC: b           L_800B73F4
    // 0x800B73E0: sw          $t7, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = ctx->r15;
        goto L_800B73F4;
    // 0x800B73E0: sw          $t7, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = ctx->r15;
L_800B73E4:
    // 0x800B73E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B73E8: sw          $t8, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = ctx->r24;
    // 0x800B73EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B73F0: sw          $t9, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = ctx->r25;
L_800B73F4:
    // 0x800B73F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B73F8: lhu         $v0, -0x7D6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7D6E);
    // 0x800B73FC: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x800B7400: slti        $at, $v0, 0xF1
    ctx->r1 = SIGNED(ctx->r2) < 0XF1 ? 1 : 0;
    // 0x800B7404: beq         $at, $zero, L_800B7428
    if (ctx->r1 == 0) {
        // 0x800B7408: addiu       $t3, $v0, -0x20
        ctx->r11 = ADD32(ctx->r2, -0X20);
            goto L_800B7428;
    }
    // 0x800B7408: addiu       $t3, $v0, -0x20
    ctx->r11 = ADD32(ctx->r2, -0X20);
    // 0x800B740C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800B7410: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7414: sw          $t0, -0x7D7C($at)
    MEM_W(-0X7D7C, ctx->r1) = ctx->r8;
    // 0x800B7418: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B741C: addiu       $t1, $v0, -0x10
    ctx->r9 = ADD32(ctx->r2, -0X10);
    // 0x800B7420: jr          $ra
    // 0x800B7424: sw          $t1, -0x7D78($at)
    MEM_W(-0X7D78, ctx->r1) = ctx->r9;
    return;
    // 0x800B7424: sw          $t1, -0x7D78($at)
    MEM_W(-0X7D78, ctx->r1) = ctx->r9;
L_800B7428:
    // 0x800B7428: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B742C: sw          $t2, -0x7D7C($at)
    MEM_W(-0X7D7C, ctx->r1) = ctx->r10;
    // 0x800B7430: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7434: sw          $t3, -0x7D78($at)
    MEM_W(-0X7D78, ctx->r1) = ctx->r11;
    // 0x800B7438: jr          $ra
    // 0x800B743C: nop

    return;
    // 0x800B743C: nop

;}
RECOMP_FUNC void debug_text_origin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7440: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B7444: lw          $t6, -0x7D84($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D84);
    // 0x800B7448: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B744C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B7450: lw          $t7, -0x7D7C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D7C);
    // 0x800B7454: sh          $t6, -0x7D94($at)
    MEM_H(-0X7D94, ctx->r1) = ctx->r14;
    // 0x800B7458: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B745C: jr          $ra
    // 0x800B7460: sh          $t7, -0x7D92($at)
    MEM_H(-0X7D92, ctx->r1) = ctx->r15;
    return;
    // 0x800B7460: sh          $t7, -0x7D92($at)
    MEM_H(-0X7D92, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void debug_text_newline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7464: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B7468: lw          $t6, -0x7D84($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D84);
    // 0x800B746C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B7470: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7474: addiu       $v0, $v0, -0x7D92
    ctx->r2 = ADD32(ctx->r2, -0X7D92);
    // 0x800B7478: sh          $t6, -0x7D94($at)
    MEM_H(-0X7D94, ctx->r1) = ctx->r14;
    // 0x800B747C: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800B7480: nop

    // 0x800B7484: addiu       $t8, $t7, 0xB
    ctx->r24 = ADD32(ctx->r15, 0XB);
    // 0x800B7488: jr          $ra
    // 0x800B748C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800B748C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_800B6F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7490: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B7494: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B7498: jr          $ra
    // 0x800B749C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800B749C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void __assert_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B74A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B74A4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B74A8: jr          $ra
    // 0x800B74AC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800B74AC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void thread0_create(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B74B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B74B4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B74B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B74BC: addiu       $t6, $t6, -0x6460
    ctx->r14 = ADD32(ctx->r14, -0X6460);
    // 0x800B74C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B74C4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800B74C8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800B74CC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800B74D0: addiu       $a2, $a2, 0x7524
    ctx->r6 = ADD32(ctx->r6, 0X7524);
    // 0x800B74D4: addiu       $a0, $a0, -0x6460
    ctx->r4 = ADD32(ctx->r4, -0X6460);
    // 0x800B74D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800B74DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B74E0: jal         0x800C8DB0
    // 0x800B74E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800B74E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800B74E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B74EC: jal         0x800C8F00
    // 0x800B74F0: addiu       $a0, $a0, -0x6460
    ctx->r4 = ADD32(ctx->r4, -0X6460);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800B74F0: addiu       $a0, $a0, -0x6460
    ctx->r4 = ADD32(ctx->r4, -0X6460);
    after_1:
    // 0x800B74F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B74F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B74FC: addiu       $a0, $a0, -0x5A84
    ctx->r4 = ADD32(ctx->r4, -0X5A84);
    // 0x800B7500: addiu       $v0, $v0, -0x5A90
    ctx->r2 = ADD32(ctx->r2, -0X5A90);
    // 0x800B7504: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800B7508:
    // 0x800B7508: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B750C: bne         $v0, $a0, L_800B7508
    if (ctx->r2 != ctx->r4) {
        // 0x800B7510: sw          $v1, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r3;
            goto L_800B7508;
    }
    // 0x800B7510: sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
    // 0x800B7514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B751C: jr          $ra
    // 0x800B7520: nop

    return;
    // 0x800B7520: nop

;}
RECOMP_FUNC void thread0_Main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7524: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B7528: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B752C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800B7530: addiu       $s3, $s3, -0x62B0
    ctx->r19 = ADD32(ctx->r19, -0X62B0);
    // 0x800B7534: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B7538: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B753C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B7540: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7544: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B7548: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B754C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B7550: addiu       $a1, $a1, -0x6298
    ctx->r5 = ADD32(ctx->r5, -0X6298);
    // 0x800B7554: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B7558: jal         0x800C8D80
    // 0x800B755C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800B755C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800B7560: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800B7564: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800B7568: jal         0x800CD110
    // 0x800B756C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800B756C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800B7570: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800B7574: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800B7578: jal         0x800CD110
    // 0x800B757C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800B757C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x800B7580: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7584: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B7588: addiu       $a2, $a2, -0x6278
    ctx->r6 = ADD32(ctx->r6, -0X6278);
    // 0x800B758C: addiu       $a1, $a1, -0x6258
    ctx->r5 = ADD32(ctx->r5, -0X6258);
    // 0x800B7590: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x800B7594: jal         0x800C6560
    // 0x800B7598: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_3;
    // 0x800B7598: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_3:
    // 0x800B759C: addiu       $s2, $zero, -0x9
    ctx->r18 = ADD32(0, -0X9);
    // 0x800B75A0: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x800B75A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800B75A8:
    // 0x800B75A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B75AC: jal         0x800C9110
    // 0x800B75B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x800B75B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x800B75B4: jal         0x800B760C
    // 0x800B75B8: and         $s0, $s0, $s2
    ctx->r16 = ctx->r16 & ctx->r18;
    enable_interupts_on_main(rdram, ctx);
        goto after_5;
    // 0x800B75B8: and         $s0, $s0, $s2
    ctx->r16 = ctx->r16 & ctx->r18;
    after_5:
    // 0x800B75BC: jal         0x800B7680
    // 0x800B75C0: nop

    stop_all_threads_except_main(rdram, ctx);
        goto after_6;
    // 0x800B75C0: nop

    after_6:
    // 0x800B75C4: jal         0x800B76EC
    // 0x800B75C8: nop

    write_epc_data_to_cpak(rdram, ctx);
        goto after_7;
    // 0x800B75C8: nop

    after_7:
    // 0x800B75CC: b           L_800B75A8
    // 0x800B75D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_800B75A8;
    // 0x800B75D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B75D4: nop

    // 0x800B75D8: nop

    // 0x800B75DC: nop

    // 0x800B75E0: nop

    // 0x800B75E4: nop

    // 0x800B75E8: nop

    // 0x800B75EC: nop

    // 0x800B75F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B75F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B75F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B75FC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7600: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B7604: jr          $ra
    // 0x800B7608: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B7608: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void enable_interupts_on_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B760C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7614: jal         0x800D29D0
    // 0x800B7618: nop

    __osGetActiveQueue(rdram, ctx);
        goto after_0;
    // 0x800B7618: nop

    after_0:
    // 0x800B761C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800B7620: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800B7624: beq         $a0, $t6, L_800B7670
    if (ctx->r4 == ctx->r14) {
        // 0x800B7628: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800B7670;
    }
    // 0x800B7628: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B762C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800B7630: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
L_800B7634:
    // 0x800B7634: bne         $v0, $zero, L_800B7658
    if (ctx->r2 != 0) {
        // 0x800B7638: nop
    
            goto L_800B7658;
    }
    // 0x800B7638: nop

    // 0x800B763C: lw          $t7, 0x118($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X118);
    // 0x800B7640: ori         $at, $at, 0xFE
    ctx->r1 = ctx->r1 | 0XFE;
    // 0x800B7644: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800B7648: sw          $t8, 0x118($v1)
    MEM_W(0X118, ctx->r3) = ctx->r24;
    // 0x800B764C: ori         $t0, $t8, 0x6C01
    ctx->r8 = ctx->r24 | 0X6C01;
    // 0x800B7650: b           L_800B7670
    // 0x800B7654: sw          $t0, 0x118($v1)
    MEM_W(0X118, ctx->r3) = ctx->r8;
        goto L_800B7670;
    // 0x800B7654: sw          $t0, 0x118($v1)
    MEM_W(0X118, ctx->r3) = ctx->r8;
L_800B7658:
    // 0x800B7658: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    // 0x800B765C: nop

    // 0x800B7660: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800B7664: nop

    // 0x800B7668: bne         $a0, $v0, L_800B7634
    if (ctx->r4 != ctx->r2) {
        // 0x800B766C: nop
    
            goto L_800B7634;
    }
    // 0x800B766C: nop

L_800B7670:
    // 0x800B7670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7674: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7678: jr          $ra
    // 0x800B767C: nop

    return;
    // 0x800B767C: nop

;}
RECOMP_FUNC void stop_all_threads_except_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7680: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B7684: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B7688: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B768C: jal         0x800D29D0
    // 0x800B7690: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    __osGetActiveQueue(rdram, ctx);
        goto after_0;
    // 0x800B7690: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B7694: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800B7698: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800B769C: beq         $s1, $t6, L_800B76D8
    if (ctx->r17 == ctx->r14) {
        // 0x800B76A0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800B76D8;
    }
    // 0x800B76A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B76A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_800B76A8:
    // 0x800B76A8: blez        $v0, L_800B76C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B76AC: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_800B76C0;
    }
    // 0x800B76AC: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800B76B0: beq         $at, $zero, L_800B76C0
    if (ctx->r1 == 0) {
        // 0x800B76B4: nop
    
            goto L_800B76C0;
    }
    // 0x800B76B4: nop

    // 0x800B76B8: jal         0x800C9050
    // 0x800B76BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osStopThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800B76BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_800B76C0:
    // 0x800B76C0: lw          $s0, 0xC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XC);
    // 0x800B76C4: nop

    // 0x800B76C8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800B76CC: nop

    // 0x800B76D0: bne         $s1, $v0, L_800B76A8
    if (ctx->r17 != ctx->r2) {
        // 0x800B76D4: nop
    
            goto L_800B76A8;
    }
    // 0x800B76D4: nop

L_800B76D8:
    // 0x800B76D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B76DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B76E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B76E4: jr          $ra
    // 0x800B76E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B76E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void write_epc_data_to_cpak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B76EC: addiu       $sp, $sp, -0x848
    ctx->r29 = ADD32(ctx->r29, -0X848);
    // 0x800B76F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B76F4: jal         0x800D29D0
    // 0x800B76F8: nop

    __osGetActiveQueue(rdram, ctx);
        goto after_0;
    // 0x800B76F8: nop

    after_0:
    // 0x800B76FC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800B7700: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800B7704: beq         $a0, $t6, L_800B7758
    if (ctx->r4 == ctx->r14) {
        // 0x800B7708: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B7758;
    }
    // 0x800B7708: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B770C: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800B7710: nop

L_800B7714:
    // 0x800B7714: blez        $v1, L_800B7740
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B7718: slti        $at, $v1, 0x80
        ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_800B7740;
    }
    // 0x800B7718: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x800B771C: beq         $at, $zero, L_800B7740
    if (ctx->r1 == 0) {
        // 0x800B7720: nop
    
            goto L_800B7740;
    }
    // 0x800B7720: nop

    // 0x800B7724: lhu         $v1, 0x12($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X12);
    // 0x800B7728: nop

    // 0x800B772C: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800B7730: bne         $t7, $zero, L_800B7758
    if (ctx->r15 != 0) {
        // 0x800B7734: andi        $t8, $v1, 0x1
        ctx->r24 = ctx->r3 & 0X1;
            goto L_800B7758;
    }
    // 0x800B7734: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x800B7738: bne         $t8, $zero, L_800B7758
    if (ctx->r24 != 0) {
        // 0x800B773C: nop
    
            goto L_800B7758;
    }
    // 0x800B773C: nop

L_800B7740:
    // 0x800B7740: lw          $a3, 0xC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0XC);
    // 0x800B7744: nop

    // 0x800B7748: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800B774C: nop

    // 0x800B7750: bne         $a0, $v1, L_800B7714
    if (ctx->r4 != ctx->r3) {
        // 0x800B7754: nop
    
            goto L_800B7714;
    }
    // 0x800B7754: nop

L_800B7758:
    // 0x800B7758: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x800B775C: nop

    // 0x800B7760: beq         $a0, $t9, L_800B7968
    if (ctx->r4 == ctx->r25) {
        // 0x800B7764: nop
    
            goto L_800B7968;
    }
    // 0x800B7764: nop

    // 0x800B7768: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B776C: addiu       $v0, $v0, -0x5A90
    ctx->r2 = ADD32(ctx->r2, -0X5A90);
    // 0x800B7770: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800B7774: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800B7778: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B777C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800B7780: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B7784: addiu       $a2, $zero, 0x1B0
    ctx->r6 = ADD32(0, 0X1B0);
    // 0x800B7788: swc1        $f6, 0x130($a3)
    MEM_W(0X130, ctx->r7) = ctx->f6.u32l;
    // 0x800B778C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800B7790: nop

    // 0x800B7794: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800B7798: nop

    // 0x800B779C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B77A0: swc1        $f10, 0x134($a3)
    MEM_W(0X134, ctx->r7) = ctx->f10.u32l;
    // 0x800B77A4: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800B77A8: nop

    // 0x800B77AC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800B77B0: nop

    // 0x800B77B4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B77B8: swc1        $f18, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->f18.u32l;
    // 0x800B77BC: jal         0x800CA300
    // 0x800B77C0: sw          $a3, 0x844($sp)
    MEM_W(0X844, ctx->r29) = ctx->r7;
    bcopy_recomp(rdram, ctx);
        goto after_1;
    // 0x800B77C0: sw          $a3, 0x844($sp)
    MEM_W(0X844, ctx->r29) = ctx->r7;
    after_1:
    // 0x800B77C4: lw          $a3, 0x844($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X844);
    // 0x800B77C8: addiu       $a1, $sp, 0x244
    ctx->r5 = ADD32(ctx->r29, 0X244);
    // 0x800B77CC: lw          $a0, 0xF4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XF4);
    // 0x800B77D0: jal         0x800CA300
    // 0x800B77D4: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    bcopy_recomp(rdram, ctx);
        goto after_2;
    // 0x800B77D4: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_2:
    // 0x800B77D8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800B77DC: jal         0x800245C8
    // 0x800B77E0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80024594(rdram, ctx);
        goto after_3;
    // 0x800B77E0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x800B77E4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B77E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B77EC: blez        $t3, L_800B7940
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800B77F0: lui         $a3, 0x800F
        ctx->r7 = S32(0X800F << 16);
            goto L_800B7940;
    }
    // 0x800B77F0: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800B77F4: andi        $a2, $t3, 0x3
    ctx->r6 = ctx->r11 & 0X3;
    // 0x800B77F8: beq         $a2, $zero, L_800B785C
    if (ctx->r6 == 0) {
        // 0x800B77FC: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_800B785C;
    }
    // 0x800B77FC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800B7800: sll         $t6, $zero, 1
    ctx->r14 = S32(0 << 1);
    // 0x800B7804: addiu       $t7, $sp, 0x444
    ctx->r15 = ADD32(ctx->r29, 0X444);
    // 0x800B7808: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
L_800B780C:
    // 0x800B780C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B7810: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B7814: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7818: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800B781C: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800B7820: nop

    // 0x800B7824: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x800B7828: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B782C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800B7830: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x800B7834: bgez        $t4, L_800B7844
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800B7838: sw          $t4, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r12;
            goto L_800B7844;
    }
    // 0x800B7838: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800B783C: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x800B7840: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7844:
    // 0x800B7844: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800B7848: bne         $v1, $a1, L_800B780C
    if (ctx->r3 != ctx->r5) {
        // 0x800B784C: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800B780C;
    }
    // 0x800B784C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B7850: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B7854: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800B7858: beq         $a1, $t3, L_800B7940
    if (ctx->r5 == ctx->r11) {
        // 0x800B785C: sll         $t6, $a1, 1
        ctx->r14 = S32(ctx->r5 << 1);
            goto L_800B7940;
    }
L_800B785C:
    // 0x800B785C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800B7860: addiu       $t7, $sp, 0x444
    ctx->r15 = ADD32(ctx->r29, 0X444);
    // 0x800B7864: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
L_800B7868:
    // 0x800B7868: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B786C: nop

    // 0x800B7870: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7874: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800B7878: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x800B787C: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B7880: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x800B7884: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B7888: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B788C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800B7890: bgez        $t2, L_800B78A8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B7894: sw          $t2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r10;
            goto L_800B78A8;
    }
    // 0x800B7894: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B7898: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
    // 0x800B789C: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x800B78A0: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
    // 0x800B78A4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B78A8:
    // 0x800B78A8: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x800B78AC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B78B0: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
    // 0x800B78B4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B78B8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800B78BC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B78C0: bgez        $t7, L_800B78D8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B78C4: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_800B78D8;
    }
    // 0x800B78C4: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800B78C8: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x800B78CC: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x800B78D0: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800B78D4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B78D8:
    // 0x800B78D8: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x800B78DC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B78E0: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x800B78E4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B78E8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B78EC: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800B78F0: bgez        $t2, L_800B7908
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B78F4: sw          $t2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r10;
            goto L_800B7908;
    }
    // 0x800B78F4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B78F8: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
    // 0x800B78FC: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x800B7900: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
    // 0x800B7904: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7908:
    // 0x800B7908: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x800B790C: nop

    // 0x800B7910: sh          $t3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r11;
    // 0x800B7914: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B7918: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800B791C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B7920: bgez        $t7, L_800B7930
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B7924: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_800B7930;
    }
    // 0x800B7924: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800B7928: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x800B792C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7930:
    // 0x800B7930: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800B7934: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B7938: bne         $a1, $t9, L_800B7868
    if (ctx->r5 != ctx->r25) {
        // 0x800B793C: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_800B7868;
    }
    // 0x800B793C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800B7940:
    // 0x800B7940: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800B7944: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x800B7948: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x800B794C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800B7950: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800B7954: addiu       $a2, $a2, -0x6BA4
    ctx->r6 = ADD32(ctx->r6, -0X6BA4);
    // 0x800B7958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B795C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B7960: jal         0x8007692C
    // 0x800B7964: addiu       $a3, $a3, -0x6B9C
    ctx->r7 = ADD32(ctx->r7, -0X6B9C);
    write_controller_pak_file(rdram, ctx);
        goto after_4;
    // 0x800B7964: addiu       $a3, $a3, -0x6B9C
    ctx->r7 = ADD32(ctx->r7, -0X6B9C);
    after_4:
L_800B7968:
    // 0x800B7968: b           L_800B7968
    pause_self(rdram);
    // 0x800B796C: nop

    // 0x800B7970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7974: addiu       $sp, $sp, 0x848
    ctx->r29 = ADD32(ctx->r29, 0X848);
    // 0x800B7978: jr          $ra
    // 0x800B797C: nop

    return;
    // 0x800B797C: nop

;}
RECOMP_FUNC void dump_memory_to_cpak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7980: addiu       $sp, $sp, -0x9F0
    ctx->r29 = ADD32(ctx->r29, -0X9F0);
    // 0x800B7984: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B7988: sw          $a0, 0x9F0($sp)
    MEM_W(0X9F0, ctx->r29) = ctx->r4;
    // 0x800B798C: sw          $a1, 0x9F4($sp)
    MEM_W(0X9F4, ctx->r29) = ctx->r5;
    // 0x800B7990: jal         0x8009C850
    // 0x800B7994: sw          $a2, 0x9F8($sp)
    MEM_W(0X9F8, ctx->r29) = ctx->r6;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x800B7994: sw          $a2, 0x9F8($sp)
    MEM_W(0X9F8, ctx->r29) = ctx->r6;
    after_0:
    // 0x800B7998: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800B799C: bgez        $t6, L_800B7BC8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B79A0: addiu       $a0, $sp, 0x840
        ctx->r4 = ADD32(ctx->r29, 0X840);
            goto L_800B7BC8;
    }
    // 0x800B79A0: addiu       $a0, $sp, 0x840
    ctx->r4 = ADD32(ctx->r29, 0X840);
    // 0x800B79A4: jal         0x800D0A40
    // 0x800B79A8: addiu       $a1, $zero, 0x1B0
    ctx->r5 = ADD32(0, 0X1B0);
    bzero_recomp(rdram, ctx);
        goto after_1;
    // 0x800B79A8: addiu       $a1, $zero, 0x1B0
    ctx->r5 = ADD32(0, 0X1B0);
    after_1:
    // 0x800B79AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B79B0: addiu       $v0, $v0, -0x5A90
    ctx->r2 = ADD32(ctx->r2, -0X5A90);
    // 0x800B79B4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B79B8: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800B79BC: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x800B79C0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B79C4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800B79C8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800B79CC: lw          $t1, 0x9F4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B79D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B79D4: lw          $t7, 0x9F0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9F0);
    // 0x800B79D8: lw          $t4, 0x9F8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9F8);
    // 0x800B79DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B79E0: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B79E4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800B79E8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B79EC: sra         $t2, $t1, 31
    ctx->r10 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800B79F0: sw          $t2, 0x878($sp)
    MEM_W(0X878, ctx->r29) = ctx->r10;
    // 0x800B79F4: sw          $t6, 0x880($sp)
    MEM_W(0X880, ctx->r29) = ctx->r14;
    // 0x800B79F8: sw          $t5, 0x960($sp)
    MEM_W(0X960, ctx->r29) = ctx->r13;
    // 0x800B79FC: swc1        $f6, 0x970($sp)
    MEM_W(0X970, ctx->r29) = ctx->f6.u32l;
    // 0x800B7A00: swc1        $f10, 0x974($sp)
    MEM_W(0X974, ctx->r29) = ctx->f10.u32l;
    // 0x800B7A04: swc1        $f18, 0x978($sp)
    MEM_W(0X978, ctx->r29) = ctx->f18.u32l;
    // 0x800B7A08: addiu       $a0, $sp, 0x840
    ctx->r4 = ADD32(ctx->r29, 0X840);
    // 0x800B7A0C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800B7A10: addiu       $a2, $zero, 0x1B0
    ctx->r6 = ADD32(0, 0X1B0);
    // 0x800B7A14: sw          $t1, 0x87C($sp)
    MEM_W(0X87C, ctx->r29) = ctx->r9;
    // 0x800B7A18: sw          $t7, 0x95C($sp)
    MEM_W(0X95C, ctx->r29) = ctx->r15;
    // 0x800B7A1C: jal         0x800CA300
    // 0x800B7A20: sw          $t4, 0x884($sp)
    MEM_W(0X884, ctx->r29) = ctx->r12;
    bcopy_recomp(rdram, ctx);
        goto after_2;
    // 0x800B7A20: sw          $t4, 0x884($sp)
    MEM_W(0X884, ctx->r29) = ctx->r12;
    after_2:
    // 0x800B7A24: addiu       $a0, $sp, 0x240
    ctx->r4 = ADD32(ctx->r29, 0X240);
    // 0x800B7A28: jal         0x800D0A40
    // 0x800B7A2C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    bzero_recomp(rdram, ctx);
        goto after_3;
    // 0x800B7A2C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_3:
    // 0x800B7A30: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800B7A34: jal         0x800245C8
    // 0x800B7A38: addiu       $a1, $sp, 0x9F4
    ctx->r5 = ADD32(ctx->r29, 0X9F4);
    func_80024594(rdram, ctx);
        goto after_4;
    // 0x800B7A38: addiu       $a1, $sp, 0x9F4
    ctx->r5 = ADD32(ctx->r29, 0X9F4);
    after_4:
    // 0x800B7A3C: lw          $t1, 0x9F4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7A40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B7A44: blez        $t1, L_800B7B98
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800B7A48: lui         $a3, 0x800F
        ctx->r7 = S32(0X800F << 16);
            goto L_800B7B98;
    }
    // 0x800B7A48: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800B7A4C: andi        $a2, $t1, 0x3
    ctx->r6 = ctx->r9 & 0X3;
    // 0x800B7A50: beq         $a2, $zero, L_800B7AB4
    if (ctx->r6 == 0) {
        // 0x800B7A54: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_800B7AB4;
    }
    // 0x800B7A54: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800B7A58: sll         $t2, $zero, 1
    ctx->r10 = S32(0 << 1);
    // 0x800B7A5C: addiu       $t3, $sp, 0x440
    ctx->r11 = ADD32(ctx->r29, 0X440);
    // 0x800B7A60: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
L_800B7A64:
    // 0x800B7A64: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800B7A68: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B7A6C: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800B7A70: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800B7A74: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x800B7A78: nop

    // 0x800B7A7C: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x800B7A80: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B7A84: lw          $t0, 0x9F4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7A88: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B7A8C: bgez        $t9, L_800B7A9C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B7A90: sw          $t9, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r25;
            goto L_800B7A9C;
    }
    // 0x800B7A90: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800B7A94: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x800B7A98: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7A9C:
    // 0x800B7A9C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800B7AA0: bne         $v1, $a1, L_800B7A64
    if (ctx->r3 != ctx->r5) {
        // 0x800B7AA4: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800B7A64;
    }
    // 0x800B7AA4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B7AA8: lw          $t1, 0x9F4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7AAC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800B7AB0: beq         $a1, $t1, L_800B7B98
    if (ctx->r5 == ctx->r9) {
        // 0x800B7AB4: sll         $t2, $a1, 1
        ctx->r10 = S32(ctx->r5 << 1);
            goto L_800B7B98;
    }
L_800B7AB4:
    // 0x800B7AB4: sll         $t2, $a1, 1
    ctx->r10 = S32(ctx->r5 << 1);
    // 0x800B7AB8: addiu       $t3, $sp, 0x440
    ctx->r11 = ADD32(ctx->r29, 0X440);
    // 0x800B7ABC: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
L_800B7AC0:
    // 0x800B7AC0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800B7AC4: nop

    // 0x800B7AC8: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800B7ACC: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800B7AD0: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800B7AD4: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B7AD8: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x800B7ADC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B7AE0: lw          $t9, 0x9F4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7AE4: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x800B7AE8: bgez        $t8, L_800B7B00
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B7AEC: sw          $t8, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r24;
            goto L_800B7B00;
    }
    // 0x800B7AEC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800B7AF0: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x800B7AF4: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x800B7AF8: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x800B7AFC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7B00:
    // 0x800B7B00: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x800B7B04: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B7B08: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    // 0x800B7B0C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B7B10: lw          $t4, 0x9F4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7B14: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800B7B18: bgez        $t3, L_800B7B30
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B7B1C: sw          $t3, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r11;
            goto L_800B7B30;
    }
    // 0x800B7B1C: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x800B7B20: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x800B7B24: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x800B7B28: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800B7B2C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7B30:
    // 0x800B7B30: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800B7B34: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B7B38: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
    // 0x800B7B3C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B7B40: lw          $t9, 0x9F4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7B44: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x800B7B48: bgez        $t8, L_800B7B60
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B7B4C: sw          $t8, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r24;
            goto L_800B7B60;
    }
    // 0x800B7B4C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800B7B50: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x800B7B54: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x800B7B58: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x800B7B5C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7B60:
    // 0x800B7B60: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x800B7B64: nop

    // 0x800B7B68: sh          $t1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r9;
    // 0x800B7B6C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B7B70: lw          $t4, 0x9F4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7B74: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800B7B78: bgez        $t3, L_800B7B88
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B7B7C: sw          $t3, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r11;
            goto L_800B7B88;
    }
    // 0x800B7B7C: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x800B7B80: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x800B7B84: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7B88:
    // 0x800B7B88: lw          $t6, 0x9F4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7B8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B7B90: bne         $a1, $t6, L_800B7AC0
    if (ctx->r5 != ctx->r14) {
        // 0x800B7B94: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_800B7AC0;
    }
    // 0x800B7B94: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800B7B98:
    // 0x800B7B98: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800B7B9C: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x800B7BA0: addiu       $t5, $zero, 0x800
    ctx->r13 = ADD32(0, 0X800);
    // 0x800B7BA4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800B7BA8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800B7BAC: addiu       $a2, $a2, -0x6B98
    ctx->r6 = ADD32(ctx->r6, -0X6B98);
    // 0x800B7BB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B7BB4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B7BB8: jal         0x8007692C
    // 0x800B7BBC: addiu       $a3, $a3, -0x6B90
    ctx->r7 = ADD32(ctx->r7, -0X6B90);
    write_controller_pak_file(rdram, ctx);
        goto after_5;
    // 0x800B7BBC: addiu       $a3, $a3, -0x6B90
    ctx->r7 = ADD32(ctx->r7, -0X6B90);
    after_5:
L_800B7BC0:
    // 0x800B7BC0: b           L_800B7BC0
    pause_self(rdram);
    // 0x800B7BC4: nop

L_800B7BC8:
    // 0x800B7BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7BCC: addiu       $sp, $sp, 0x9F0
    ctx->r29 = ADD32(ctx->r29, 0X9F0);
    // 0x800B7BD0: jr          $ra
    // 0x800B7BD4: nop

    return;
    // 0x800B7BD4: nop

;}
RECOMP_FUNC void update_object_stack_trace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7BD8: bltz        $a0, L_800B7BF4
    if (SIGNED(ctx->r4) < 0) {
        // 0x800B7BDC: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_800B7BF4;
    }
    // 0x800B7BDC: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800B7BE0: beq         $at, $zero, L_800B7BF4
    if (ctx->r1 == 0) {
        // 0x800B7BE4: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800B7BF4;
    }
    // 0x800B7BE4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800B7BE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7BEC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B7BF0: sw          $a1, -0x5A90($at)
    MEM_W(-0X5A90, ctx->r1) = ctx->r5;
L_800B7BF4:
    // 0x800B7BF4: jr          $ra
    // 0x800B7BF8: nop

    return;
    // 0x800B7BF8: nop

;}
RECOMP_FUNC void get_lockup_status(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7BFC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B7C00: addiu       $v0, $v0, 0x35B0
    ctx->r2 = ADD32(ctx->r2, 0X35B0);
    // 0x800B7C04: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800B7C08: addiu       $sp, $sp, -0x828
    ctx->r29 = ADD32(ctx->r29, -0X828);
    // 0x800B7C0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B7C10: beq         $v1, $at, L_800B7C20
    if (ctx->r3 == ctx->r1) {
        // 0x800B7C14: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800B7C20;
    }
    // 0x800B7C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7C18: b           L_800B7CE4
    // 0x800B7C1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B7CE4;
    // 0x800B7C1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B7C20:
    // 0x800B7C20: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B7C24: jal         0x80075B34
    // 0x800B7C28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x800B7C28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800B7C2C: bne         $v0, $zero, L_800B7CB0
    if (ctx->r2 != 0) {
        // 0x800B7C30: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B7CB0;
    }
    // 0x800B7C30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B7C34: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800B7C38: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800B7C3C: addiu       $a2, $a2, -0x6B84
    ctx->r6 = ADD32(ctx->r6, -0X6B84);
    // 0x800B7C40: addiu       $a1, $a1, -0x6B8C
    ctx->r5 = ADD32(ctx->r5, -0X6B8C);
    // 0x800B7C44: jal         0x80076740
    // 0x800B7C48: addiu       $a3, $sp, 0x824
    ctx->r7 = ADD32(ctx->r29, 0X824);
    get_file_number(rdram, ctx);
        goto after_1;
    // 0x800B7C48: addiu       $a3, $sp, 0x824
    ctx->r7 = ADD32(ctx->r29, 0X824);
    after_1:
    // 0x800B7C4C: bne         $v0, $zero, L_800B7CB0
    if (ctx->r2 != 0) {
        // 0x800B7C50: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B7CB0;
    }
    // 0x800B7C50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B7C54: lw          $a1, 0x824($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X824);
    // 0x800B7C58: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800B7C5C: jal         0x80076868
    // 0x800B7C60: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    read_data_from_controller_pak(rdram, ctx);
        goto after_2;
    // 0x800B7C60: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    after_2:
    // 0x800B7C64: bne         $v0, $zero, L_800B7CB0
    if (ctx->r2 != 0) {
        // 0x800B7C68: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_800B7CB0;
    }
    // 0x800B7C68: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800B7C6C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7C70: addiu       $a1, $a1, -0x6240
    ctx->r5 = ADD32(ctx->r5, -0X6240);
    // 0x800B7C74: jal         0x800CA300
    // 0x800B7C78: addiu       $a2, $zero, 0x1B0
    ctx->r6 = ADD32(0, 0X1B0);
    bcopy_recomp(rdram, ctx);
        goto after_3;
    // 0x800B7C78: addiu       $a2, $zero, 0x1B0
    ctx->r6 = ADD32(0, 0X1B0);
    after_3:
    // 0x800B7C7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7C80: addiu       $a1, $a1, -0x6090
    ctx->r5 = ADD32(ctx->r5, -0X6090);
    // 0x800B7C84: addiu       $a0, $sp, 0x220
    ctx->r4 = ADD32(ctx->r29, 0X220);
    // 0x800B7C88: jal         0x800CA300
    // 0x800B7C8C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    bcopy_recomp(rdram, ctx);
        goto after_4;
    // 0x800B7C8C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_4:
    // 0x800B7C90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7C94: addiu       $a1, $a1, -0x5E90
    ctx->r5 = ADD32(ctx->r5, -0X5E90);
    // 0x800B7C98: addiu       $a0, $sp, 0x420
    ctx->r4 = ADD32(ctx->r29, 0X420);
    // 0x800B7C9C: jal         0x800CA300
    // 0x800B7CA0: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    bcopy_recomp(rdram, ctx);
        goto after_5;
    // 0x800B7CA0: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_5:
    // 0x800B7CA4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B7CA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7CAC: sw          $t6, 0x35B0($at)
    MEM_W(0X35B0, ctx->r1) = ctx->r14;
L_800B7CB0:
    // 0x800B7CB0: jal         0x80075D44
    // 0x800B7CB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_6;
    // 0x800B7CB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800B7CB8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B7CBC: lw          $v1, 0x35B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X35B0);
    // 0x800B7CC0: lw          $a1, 0x824($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X824);
    // 0x800B7CC4: beq         $v1, $zero, L_800B7CE4
    if (ctx->r3 == 0) {
        // 0x800B7CC8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B7CE4;
    }
    // 0x800B7CC8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B7CCC: jal         0x80076520
    // 0x800B7CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    delete_file(rdram, ctx);
        goto after_7;
    // 0x800B7CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800B7CD4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B7CD8: lw          $v1, 0x35B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X35B0);
    // 0x800B7CDC: nop

    // 0x800B7CE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B7CE4:
    // 0x800B7CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7CE8: addiu       $sp, $sp, 0x828
    ctx->r29 = ADD32(ctx->r29, 0X828);
    // 0x800B7CEC: jr          $ra
    // 0x800B7CF0: nop

    return;
    // 0x800B7CF0: nop

;}
RECOMP_FUNC void mode_lockup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7CF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B7CF8: addiu       $v0, $v0, 0x35B8
    ctx->r2 = ADD32(ctx->r2, 0X35B8);
    // 0x800B7CFC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B7D00: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B7D04: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800B7D08: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x800B7D0C: bne         $at, $zero, L_800B7D28
    if (ctx->r1 != 0) {
        // 0x800B7D10: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_800B7D28;
    }
    // 0x800B7D10: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B7D14: addiu       $v1, $v1, 0x35B4
    ctx->r3 = ADD32(ctx->r3, 0X35B4);
    // 0x800B7D18: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800B7D1C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B7D20: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B7D24: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800B7D28:
    // 0x800B7D28: jr          $ra
    // 0x800B7D2C: nop

    return;
    // 0x800B7D2C: nop

;}
RECOMP_FUNC void render_epc_lock_up_display(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7D30: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800B7D34: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B7D38: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B7D3C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800B7D40: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800B7D44: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B7D48: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B7D4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B7D50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B7D54: addiu       $t7, $t7, 0x35BC
    ctx->r15 = ADD32(ctx->r15, 0X35BC);
    // 0x800B7D58: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800B7D5C: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x800B7D60: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800B7D64: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800B7D68: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800B7D6C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B7D70: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800B7D74: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800B7D78: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800B7D7C: jal         0x800B68BC
    // 0x800B7D80: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    set_render_printf_position(rdram, ctx);
        goto after_0;
    // 0x800B7D80: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    after_0:
    // 0x800B7D84: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B7D88: addiu       $v1, $v1, 0x35B4
    ctx->r3 = ADD32(ctx->r3, 0X35B4);
    // 0x800B7D8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800B7D90: nop

    // 0x800B7D94: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x800B7D98: beq         $at, $zero, L_800B8208
    if (ctx->r1 == 0) {
        // 0x800B7D9C: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_800B8208;
    }
    // 0x800B7D9C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x800B7DA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B7DA4: addu        $at, $at, $t1
    gpr jr_addend_800B7DB0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800B7DA8: lw          $t1, -0x6944($at)
    ctx->r9 = ADD32(ctx->r1, -0X6944);
    // 0x800B7DAC: nop

    // 0x800B7DB0: jr          $t1
    // 0x800B7DB4: nop

    switch (jr_addend_800B7DB0 >> 2) {
        case 0: goto L_800B7DB8; break;
        case 1: goto L_800B8138; break;
        case 2: goto L_800B8138; break;
        case 3: goto L_800B8138; break;
        case 4: goto L_800B8190; break;
        case 5: goto L_800B8204; break;
        default: switch_error(__func__, 0x800B7DB0, 0x800E96BC);
    }
    // 0x800B7DB4: nop

L_800B7DB8:
    // 0x800B7DB8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800B7DBC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B7DC0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800B7DC4: addiu       $v1, $v1, -0x6240
    ctx->r3 = ADD32(ctx->r3, -0X6240);
    // 0x800B7DC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B7DCC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B7DD0: lwc1        $f4, 0x130($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X130);
    // 0x800B7DD4: lwc1        $f8, 0x134($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X134);
    // 0x800B7DD8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B7DDC: lwc1        $f16, 0x138($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X138);
    // 0x800B7DE0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800B7DE4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B7DE8: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800B7DEC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B7DF0: lw          $t6, 0x120($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X120);
    // 0x800B7DF4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B7DF8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B7DFC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B7E00: addiu       $v0, $v0, -0x5A90
    ctx->r2 = ADD32(ctx->r2, -0X5A90);
    // 0x800B7E04: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B7E08: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800B7E0C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B7E10: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800B7E14: nop

    // 0x800B7E18: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B7E1C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B7E20: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B7E24: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B7E28: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B7E2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B7E30: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B7E34: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800B7E38: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B7E3C: bne         $t6, $at, L_800B7EFC
    if (ctx->r14 != ctx->r1) {
        // 0x800B7E40: sw          $t8, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r24;
            goto L_800B7EFC;
    }
    // 0x800B7E40: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x800B7E44: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7E48: lw          $a1, -0x6124($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6124);
    // 0x800B7E4C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7E50: jal         0x800B643C
    // 0x800B7E54: addiu       $a0, $a0, -0x6B68
    ctx->r4 = ADD32(ctx->r4, -0X6B68);
    render_printf(rdram, ctx);
        goto after_1;
    // 0x800B7E54: addiu       $a0, $a0, -0x6B68
    ctx->r4 = ADD32(ctx->r4, -0X6B68);
    after_1:
    // 0x800B7E58: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B7E5C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7E60: lw          $a2, -0x61FC($t3)
    ctx->r6 = MEM_W(ctx->r11, -0X61FC);
    // 0x800B7E64: lw          $a1, -0x6204($t1)
    ctx->r5 = MEM_W(ctx->r9, -0X6204);
    // 0x800B7E68: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7E6C: jal         0x800B643C
    // 0x800B7E70: addiu       $a0, $a0, -0x6B58
    ctx->r4 = ADD32(ctx->r4, -0X6B58);
    render_printf(rdram, ctx);
        goto after_2;
    // 0x800B7E70: addiu       $a0, $a0, -0x6B58
    ctx->r4 = ADD32(ctx->r4, -0X6B58);
    after_2:
    // 0x800B7E74: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B7E78: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x800B7E7C: addiu       $s5, $s5, -0x6B3C
    ctx->r21 = ADD32(ctx->r21, -0X6B3C);
    // 0x800B7E80: addiu       $s0, $s0, -0x5A90
    ctx->r16 = ADD32(ctx->r16, -0X5A90);
    // 0x800B7E84: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B7E88: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_800B7E8C:
    // 0x800B7E8C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B7E90: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x800B7E94: beq         $s4, $a2, L_800B7EC8
    if (ctx->r20 == ctx->r6) {
        // 0x800B7E98: nop
    
            goto L_800B7EC8;
    }
    // 0x800B7E98: nop

    // 0x800B7E9C: bne         $s3, $zero, L_800B7EB8
    if (ctx->r19 != 0) {
        // 0x800B7EA0: addu        $s1, $s2, $t7
        ctx->r17 = ADD32(ctx->r18, ctx->r15);
            goto L_800B7EB8;
    }
    // 0x800B7EA0: addu        $s1, $s2, $t7
    ctx->r17 = ADD32(ctx->r18, ctx->r15);
    // 0x800B7EA4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800B7EA8: jal         0x800B643C
    // 0x800B7EAC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    render_printf(rdram, ctx);
        goto after_3;
    // 0x800B7EAC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x800B7EB0: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B7EB4: nop

L_800B7EB8:
    // 0x800B7EB8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7EBC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800B7EC0: jal         0x800B643C
    // 0x800B7EC4: addiu       $a0, $a0, -0x6B30
    ctx->r4 = ADD32(ctx->r4, -0X6B30);
    render_printf(rdram, ctx);
        goto after_4;
    // 0x800B7EC4: addiu       $a0, $a0, -0x6B30
    ctx->r4 = ADD32(ctx->r4, -0X6B30);
    after_4:
L_800B7EC8:
    // 0x800B7EC8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B7ECC: addiu       $t4, $t4, -0x5A84
    ctx->r12 = ADD32(ctx->r12, -0X5A84);
    // 0x800B7ED0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B7ED4: bne         $s0, $t4, L_800B7E8C
    if (ctx->r16 != ctx->r12) {
        // 0x800B7ED8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800B7E8C;
    }
    // 0x800B7ED8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800B7EDC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7EE0: jal         0x800B643C
    // 0x800B7EE4: addiu       $a0, $a0, -0x6B28
    ctx->r4 = ADD32(ctx->r4, -0X6B28);
    render_printf(rdram, ctx);
        goto after_5;
    // 0x800B7EE4: addiu       $a0, $a0, -0x6B28
    ctx->r4 = ADD32(ctx->r4, -0X6B28);
    after_5:
    // 0x800B7EE8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7EEC: jal         0x800B643C
    // 0x800B7EF0: addiu       $a0, $a0, -0x6B24
    ctx->r4 = ADD32(ctx->r4, -0X6B24);
    render_printf(rdram, ctx);
        goto after_6;
    // 0x800B7EF0: addiu       $a0, $a0, -0x6B24
    ctx->r4 = ADD32(ctx->r4, -0X6B24);
    after_6:
    // 0x800B7EF4: b           L_800B820C
    // 0x800B7EF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B820C;
    // 0x800B7EF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B7EFC:
    // 0x800B7EFC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7F00: lw          $a1, 0x14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14);
    // 0x800B7F04: jal         0x800B643C
    // 0x800B7F08: addiu       $a0, $a0, -0x6B14
    ctx->r4 = ADD32(ctx->r4, -0X6B14);
    render_printf(rdram, ctx);
        goto after_7;
    // 0x800B7F08: addiu       $a0, $a0, -0x6B14
    ctx->r4 = ADD32(ctx->r4, -0X6B14);
    after_7:
    // 0x800B7F0C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7F10: lw          $a1, -0x6124($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6124);
    // 0x800B7F14: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7F18: jal         0x800B643C
    // 0x800B7F1C: addiu       $a0, $a0, -0x6AFC
    ctx->r4 = ADD32(ctx->r4, -0X6AFC);
    render_printf(rdram, ctx);
        goto after_8;
    // 0x800B7F1C: addiu       $a0, $a0, -0x6AFC
    ctx->r4 = ADD32(ctx->r4, -0X6AFC);
    after_8:
    // 0x800B7F20: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7F24: lw          $a1, -0x6120($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6120);
    // 0x800B7F28: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7F2C: jal         0x800B643C
    // 0x800B7F30: addiu       $a0, $a0, -0x6AEC
    ctx->r4 = ADD32(ctx->r4, -0X6AEC);
    render_printf(rdram, ctx);
        goto after_9;
    // 0x800B7F30: addiu       $a0, $a0, -0x6AEC
    ctx->r4 = ADD32(ctx->r4, -0X6AEC);
    after_9:
    // 0x800B7F34: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7F38: lw          $a1, -0x6128($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6128);
    // 0x800B7F3C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7F40: jal         0x800B643C
    // 0x800B7F44: addiu       $a0, $a0, -0x6ADC
    ctx->r4 = ADD32(ctx->r4, -0X6ADC);
    render_printf(rdram, ctx);
        goto after_10;
    // 0x800B7F44: addiu       $a0, $a0, -0x6ADC
    ctx->r4 = ADD32(ctx->r4, -0X6ADC);
    after_10:
    // 0x800B7F48: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7F4C: lw          $a1, -0x611C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X611C);
    // 0x800B7F50: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7F54: jal         0x800B643C
    // 0x800B7F58: addiu       $a0, $a0, -0x6ACC
    ctx->r4 = ADD32(ctx->r4, -0X6ACC);
    render_printf(rdram, ctx);
        goto after_11;
    // 0x800B7F58: addiu       $a0, $a0, -0x6ACC
    ctx->r4 = ADD32(ctx->r4, -0X6ACC);
    after_11:
    // 0x800B7F5C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B7F60: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x800B7F64: addiu       $s5, $s5, -0x6AB8
    ctx->r21 = ADD32(ctx->r21, -0X6AB8);
    // 0x800B7F68: addiu       $s0, $s0, -0x5A90
    ctx->r16 = ADD32(ctx->r16, -0X5A90);
    // 0x800B7F6C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B7F70: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_800B7F74:
    // 0x800B7F74: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B7F78: addiu       $t5, $sp, 0x50
    ctx->r13 = ADD32(ctx->r29, 0X50);
    // 0x800B7F7C: beq         $s4, $a2, L_800B7FB0
    if (ctx->r20 == ctx->r6) {
        // 0x800B7F80: nop
    
            goto L_800B7FB0;
    }
    // 0x800B7F80: nop

    // 0x800B7F84: bne         $s3, $zero, L_800B7FA0
    if (ctx->r19 != 0) {
        // 0x800B7F88: addu        $s1, $s2, $t5
        ctx->r17 = ADD32(ctx->r18, ctx->r13);
            goto L_800B7FA0;
    }
    // 0x800B7F88: addu        $s1, $s2, $t5
    ctx->r17 = ADD32(ctx->r18, ctx->r13);
    // 0x800B7F8C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800B7F90: jal         0x800B643C
    // 0x800B7F94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    render_printf(rdram, ctx);
        goto after_12;
    // 0x800B7F94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_12:
    // 0x800B7F98: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B7F9C: nop

L_800B7FA0:
    // 0x800B7FA0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7FA4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800B7FA8: jal         0x800B643C
    // 0x800B7FAC: addiu       $a0, $a0, -0x6AAC
    ctx->r4 = ADD32(ctx->r4, -0X6AAC);
    render_printf(rdram, ctx);
        goto after_13;
    // 0x800B7FAC: addiu       $a0, $a0, -0x6AAC
    ctx->r4 = ADD32(ctx->r4, -0X6AAC);
    after_13:
L_800B7FB0:
    // 0x800B7FB0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B7FB4: addiu       $t9, $t9, -0x5A84
    ctx->r25 = ADD32(ctx->r25, -0X5A84);
    // 0x800B7FB8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B7FBC: bne         $s0, $t9, L_800B7F74
    if (ctx->r16 != ctx->r25) {
        // 0x800B7FC0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800B7F74;
    }
    // 0x800B7FC0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800B7FC4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7FC8: jal         0x800B643C
    // 0x800B7FCC: addiu       $a0, $a0, -0x6AA4
    ctx->r4 = ADD32(ctx->r4, -0X6AA4);
    render_printf(rdram, ctx);
        goto after_14;
    // 0x800B7FCC: addiu       $a0, $a0, -0x6AA4
    ctx->r4 = ADD32(ctx->r4, -0X6AA4);
    after_14:
    // 0x800B7FD0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B7FD4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B7FD8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B7FDC: lw          $a3, -0x620C($t1)
    ctx->r7 = MEM_W(ctx->r9, -0X620C);
    // 0x800B7FE0: lw          $a2, -0x6214($t7)
    ctx->r6 = MEM_W(ctx->r15, -0X6214);
    // 0x800B7FE4: lw          $a1, -0x621C($t9)
    ctx->r5 = MEM_W(ctx->r25, -0X621C);
    // 0x800B7FE8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7FEC: jal         0x800B643C
    // 0x800B7FF0: addiu       $a0, $a0, -0x6AA0
    ctx->r4 = ADD32(ctx->r4, -0X6AA0);
    render_printf(rdram, ctx);
        goto after_15;
    // 0x800B7FF0: addiu       $a0, $a0, -0x6AA0
    ctx->r4 = ADD32(ctx->r4, -0X6AA0);
    after_15:
    // 0x800B7FF4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7FF8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B7FFC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B8000: lw          $a3, -0x61F4($t9)
    ctx->r7 = MEM_W(ctx->r25, -0X61F4);
    // 0x800B8004: lw          $a2, -0x61FC($t5)
    ctx->r6 = MEM_W(ctx->r13, -0X61FC);
    // 0x800B8008: lw          $a1, -0x6204($t3)
    ctx->r5 = MEM_W(ctx->r11, -0X6204);
    // 0x800B800C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B8010: jal         0x800B643C
    // 0x800B8014: addiu       $a0, $a0, -0x6A80
    ctx->r4 = ADD32(ctx->r4, -0X6A80);
    render_printf(rdram, ctx);
        goto after_16;
    // 0x800B8014: addiu       $a0, $a0, -0x6A80
    ctx->r4 = ADD32(ctx->r4, -0X6A80);
    after_16:
    // 0x800B8018: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B801C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B8020: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B8024: lw          $a3, -0x61DC($t3)
    ctx->r7 = MEM_W(ctx->r11, -0X61DC);
    // 0x800B8028: lw          $a2, -0x61E4($t1)
    ctx->r6 = MEM_W(ctx->r9, -0X61E4);
    // 0x800B802C: lw          $a1, -0x61EC($t7)
    ctx->r5 = MEM_W(ctx->r15, -0X61EC);
    // 0x800B8030: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B8034: jal         0x800B643C
    // 0x800B8038: addiu       $a0, $a0, -0x6A60
    ctx->r4 = ADD32(ctx->r4, -0X6A60);
    render_printf(rdram, ctx);
        goto after_17;
    // 0x800B8038: addiu       $a0, $a0, -0x6A60
    ctx->r4 = ADD32(ctx->r4, -0X6A60);
    after_17:
    // 0x800B803C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B8040: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B8044: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B8048: lw          $a3, -0x61C4($t7)
    ctx->r7 = MEM_W(ctx->r15, -0X61C4);
    // 0x800B804C: lw          $a2, -0x61CC($t9)
    ctx->r6 = MEM_W(ctx->r25, -0X61CC);
    // 0x800B8050: lw          $a1, -0x61D4($t5)
    ctx->r5 = MEM_W(ctx->r13, -0X61D4);
    // 0x800B8054: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B8058: jal         0x800B643C
    // 0x800B805C: addiu       $a0, $a0, -0x6A40
    ctx->r4 = ADD32(ctx->r4, -0X6A40);
    render_printf(rdram, ctx);
        goto after_18;
    // 0x800B805C: addiu       $a0, $a0, -0x6A40
    ctx->r4 = ADD32(ctx->r4, -0X6A40);
    after_18:
    // 0x800B8060: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B8064: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B8068: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B806C: lw          $a3, -0x61AC($t5)
    ctx->r7 = MEM_W(ctx->r13, -0X61AC);
    // 0x800B8070: lw          $a2, -0x61B4($t3)
    ctx->r6 = MEM_W(ctx->r11, -0X61B4);
    // 0x800B8074: lw          $a1, -0x61BC($t1)
    ctx->r5 = MEM_W(ctx->r9, -0X61BC);
    // 0x800B8078: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B807C: jal         0x800B643C
    // 0x800B8080: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    render_printf(rdram, ctx);
        goto after_19;
    // 0x800B8080: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    after_19:
    // 0x800B8084: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B8088: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B808C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B8090: lw          $a3, -0x6194($t1)
    ctx->r7 = MEM_W(ctx->r9, -0X6194);
    // 0x800B8094: lw          $a2, -0x619C($t7)
    ctx->r6 = MEM_W(ctx->r15, -0X619C);
    // 0x800B8098: lw          $a1, -0x61A4($t9)
    ctx->r5 = MEM_W(ctx->r25, -0X61A4);
    // 0x800B809C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B80A0: jal         0x800B643C
    // 0x800B80A4: addiu       $a0, $a0, -0x6A00
    ctx->r4 = ADD32(ctx->r4, -0X6A00);
    render_printf(rdram, ctx);
        goto after_20;
    // 0x800B80A4: addiu       $a0, $a0, -0x6A00
    ctx->r4 = ADD32(ctx->r4, -0X6A00);
    after_20:
    // 0x800B80A8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B80AC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B80B0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B80B4: lw          $a3, -0x617C($t9)
    ctx->r7 = MEM_W(ctx->r25, -0X617C);
    // 0x800B80B8: lw          $a2, -0x6184($t5)
    ctx->r6 = MEM_W(ctx->r13, -0X6184);
    // 0x800B80BC: lw          $a1, -0x618C($t3)
    ctx->r5 = MEM_W(ctx->r11, -0X618C);
    // 0x800B80C0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B80C4: jal         0x800B643C
    // 0x800B80C8: addiu       $a0, $a0, -0x69E0
    ctx->r4 = ADD32(ctx->r4, -0X69E0);
    render_printf(rdram, ctx);
        goto after_21;
    // 0x800B80C8: addiu       $a0, $a0, -0x69E0
    ctx->r4 = ADD32(ctx->r4, -0X69E0);
    after_21:
    // 0x800B80CC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B80D0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B80D4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B80D8: lw          $a3, -0x6164($t3)
    ctx->r7 = MEM_W(ctx->r11, -0X6164);
    // 0x800B80DC: lw          $a2, -0x616C($t1)
    ctx->r6 = MEM_W(ctx->r9, -0X616C);
    // 0x800B80E0: lw          $a1, -0x6174($t7)
    ctx->r5 = MEM_W(ctx->r15, -0X6174);
    // 0x800B80E4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B80E8: jal         0x800B643C
    // 0x800B80EC: addiu       $a0, $a0, -0x69C0
    ctx->r4 = ADD32(ctx->r4, -0X69C0);
    render_printf(rdram, ctx);
        goto after_22;
    // 0x800B80EC: addiu       $a0, $a0, -0x69C0
    ctx->r4 = ADD32(ctx->r4, -0X69C0);
    after_22:
    // 0x800B80F0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B80F4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B80F8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B80FC: lw          $a3, -0x614C($t7)
    ctx->r7 = MEM_W(ctx->r15, -0X614C);
    // 0x800B8100: lw          $a2, -0x6154($t9)
    ctx->r6 = MEM_W(ctx->r25, -0X6154);
    // 0x800B8104: lw          $a1, -0x615C($t5)
    ctx->r5 = MEM_W(ctx->r13, -0X615C);
    // 0x800B8108: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B810C: jal         0x800B643C
    // 0x800B8110: addiu       $a0, $a0, -0x69A0
    ctx->r4 = ADD32(ctx->r4, -0X69A0);
    render_printf(rdram, ctx);
        goto after_23;
    // 0x800B8110: addiu       $a0, $a0, -0x69A0
    ctx->r4 = ADD32(ctx->r4, -0X69A0);
    after_23:
    // 0x800B8114: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B8118: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B811C: lw          $a2, -0x613C($t3)
    ctx->r6 = MEM_W(ctx->r11, -0X613C);
    // 0x800B8120: lw          $a1, -0x6144($t1)
    ctx->r5 = MEM_W(ctx->r9, -0X6144);
    // 0x800B8124: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B8128: jal         0x800B643C
    // 0x800B812C: addiu       $a0, $a0, -0x6980
    ctx->r4 = ADD32(ctx->r4, -0X6980);
    render_printf(rdram, ctx);
        goto after_24;
    // 0x800B812C: addiu       $a0, $a0, -0x6980
    ctx->r4 = ADD32(ctx->r4, -0X6980);
    after_24:
    // 0x800B8130: b           L_800B820C
    // 0x800B8134: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B820C;
    // 0x800B8134: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B8138:
    // 0x800B8138: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800B813C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800B8140: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800B8144: addiu       $v1, $v1, -0x30
    ctx->r3 = ADD32(ctx->r3, -0X30);
    // 0x800B8148: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B814C: addiu       $t5, $t5, -0x6090
    ctx->r13 = ADD32(ctx->r13, -0X6090);
    // 0x800B8150: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800B8154: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800B8158: addiu       $s1, $s1, -0x6968
    ctx->r17 = ADD32(ctx->r17, -0X6968);
    // 0x800B815C: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x800B8160: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B8164: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
L_800B8168:
    // 0x800B8168: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800B816C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x800B8170: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800B8174: jal         0x800B643C
    // 0x800B8178: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    render_printf(rdram, ctx);
        goto after_25;
    // 0x800B8178: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x800B817C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B8180: bne         $s4, $s5, L_800B8168
    if (ctx->r20 != ctx->r21) {
        // 0x800B8184: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800B8168;
    }
    // 0x800B8184: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B8188: b           L_800B820C
    // 0x800B818C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B820C;
    // 0x800B818C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B8190:
    // 0x800B8190: sll         $v1, $v0, 7
    ctx->r3 = S32(ctx->r2 << 7);
    // 0x800B8194: addiu       $v1, $v1, -0x200
    ctx->r3 = ADD32(ctx->r3, -0X200);
    // 0x800B8198: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B819C: addiu       $t9, $t9, -0x5E90
    ctx->r25 = ADD32(ctx->r25, -0X5E90);
    // 0x800B81A0: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x800B81A4: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x800B81A8: addiu       $s2, $s2, -0x6950
    ctx->r18 = ADD32(ctx->r18, -0X6950);
    // 0x800B81AC: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x800B81B0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B81B4: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x800B81B8: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_800B81BC:
    // 0x800B81BC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B81C0: jal         0x800B643C
    // 0x800B81C4: addiu       $a0, $a0, -0x6954
    ctx->r4 = ADD32(ctx->r4, -0X6954);
    render_printf(rdram, ctx);
        goto after_26;
    // 0x800B81C4: addiu       $a0, $a0, -0x6954
    ctx->r4 = ADD32(ctx->r4, -0X6954);
    after_26:
    // 0x800B81C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B81CC:
    // 0x800B81CC: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    // 0x800B81D0: jal         0x800B643C
    // 0x800B81D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    render_printf(rdram, ctx);
        goto after_27;
    // 0x800B81D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_27:
    // 0x800B81D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B81DC: bne         $s0, $s3, L_800B81CC
    if (ctx->r16 != ctx->r19) {
        // 0x800B81E0: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800B81CC;
    }
    // 0x800B81E0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800B81E4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B81E8: jal         0x800B643C
    // 0x800B81EC: addiu       $a0, $a0, -0x6948
    ctx->r4 = ADD32(ctx->r4, -0X6948);
    render_printf(rdram, ctx);
        goto after_28;
    // 0x800B81EC: addiu       $a0, $a0, -0x6948
    ctx->r4 = ADD32(ctx->r4, -0X6948);
    after_28:
    // 0x800B81F0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B81F4: bne         $s4, $s5, L_800B81BC
    if (ctx->r20 != ctx->r21) {
        // 0x800B81F8: nop
    
            goto L_800B81BC;
    }
    // 0x800B81F8: nop

    // 0x800B81FC: b           L_800B820C
    // 0x800B8200: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B820C;
    // 0x800B8200: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B8204:
    // 0x800B8204: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800B8208:
    // 0x800B8208: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B820C:
    // 0x800B820C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B8210: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B8214: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8218: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B821C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800B8220: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800B8224: jr          $ra
    // 0x800B8228: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800B8228: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800B822C: nop

;}
RECOMP_FUNC void stack_pointer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8230: jr          $ra
    // 0x800B8234: or          $v0, $sp, $zero
    ctx->r2 = ctx->r29 | 0;
    return;
    // 0x800B8234: or          $v0, $sp, $zero
    ctx->r2 = ctx->r29 | 0;
    // 0x800B8238: nop

    // 0x800B823C: nop

;}
RECOMP_FUNC void waves_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8240: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B8244: lw          $a0, 0x35D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X35D0);
    // 0x800B8248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B824C: beq         $a0, $zero, L_800B8264
    if (ctx->r4 == 0) {
        // 0x800B8250: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800B8264;
    }
    // 0x800B8250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8254: jal         0x80071380
    // 0x800B8258: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800B8258: nop

    after_0:
    // 0x800B825C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8260: sw          $zero, 0x35D0($at)
    MEM_W(0X35D0, ctx->r1) = 0;
L_800B8264:
    // 0x800B8264: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B8268: lw          $a0, 0x35D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X35D4);
    // 0x800B826C: nop

    // 0x800B8270: beq         $a0, $zero, L_800B8288
    if (ctx->r4 == 0) {
        // 0x800B8274: nop
    
            goto L_800B8288;
    }
    // 0x800B8274: nop

    // 0x800B8278: jal         0x80071380
    // 0x800B827C: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800B827C: nop

    after_1:
    // 0x800B8280: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8284: sw          $zero, 0x35D4($at)
    MEM_W(0X35D4, ctx->r1) = 0;
L_800B8288:
    // 0x800B8288: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B828C: lw          $a0, 0x35D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X35D8);
    // 0x800B8290: nop

    // 0x800B8294: beq         $a0, $zero, L_800B82AC
    if (ctx->r4 == 0) {
        // 0x800B8298: nop
    
            goto L_800B82AC;
    }
    // 0x800B8298: nop

    // 0x800B829C: jal         0x80071380
    // 0x800B82A0: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800B82A0: nop

    after_2:
    // 0x800B82A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B82A8: sw          $zero, 0x35D8($at)
    MEM_W(0X35D8, ctx->r1) = 0;
L_800B82AC:
    // 0x800B82AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B82B0: lw          $a0, 0x35DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X35DC);
    // 0x800B82B4: nop

    // 0x800B82B8: beq         $a0, $zero, L_800B82D0
    if (ctx->r4 == 0) {
        // 0x800B82BC: nop
    
            goto L_800B82D0;
    }
    // 0x800B82BC: nop

    // 0x800B82C0: jal         0x80071380
    // 0x800B82C4: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x800B82C4: nop

    after_3:
    // 0x800B82C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B82CC: sw          $zero, 0x35DC($at)
    MEM_W(0X35DC, ctx->r1) = 0;
L_800B82D0:
    // 0x800B82D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B82D4: lw          $a0, 0x3600($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3600);
    // 0x800B82D8: nop

    // 0x800B82DC: beq         $a0, $zero, L_800B82F4
    if (ctx->r4 == 0) {
        // 0x800B82E0: nop
    
            goto L_800B82F4;
    }
    // 0x800B82E0: nop

    // 0x800B82E4: jal         0x80071380
    // 0x800B82E8: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800B82E8: nop

    after_4:
    // 0x800B82EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B82F0: sw          $zero, 0x3600($at)
    MEM_W(0X3600, ctx->r1) = 0;
L_800B82F4:
    // 0x800B82F4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B82F8: lw          $a0, 0x3610($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3610);
    // 0x800B82FC: nop

    // 0x800B8300: beq         $a0, $zero, L_800B8318
    if (ctx->r4 == 0) {
        // 0x800B8304: nop
    
            goto L_800B8318;
    }
    // 0x800B8304: nop

    // 0x800B8308: jal         0x80071380
    // 0x800B830C: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800B830C: nop

    after_5:
    // 0x800B8310: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8314: sw          $zero, 0x3610($at)
    MEM_W(0X3610, ctx->r1) = 0;
L_800B8318:
    // 0x800B8318: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B831C: lw          $a0, 0x3660($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3660);
    // 0x800B8320: nop

    // 0x800B8324: beq         $a0, $zero, L_800B833C
    if (ctx->r4 == 0) {
        // 0x800B8328: nop
    
            goto L_800B833C;
    }
    // 0x800B8328: nop

    // 0x800B832C: jal         0x8007B70C
    // 0x800B8330: nop

    tex_free(rdram, ctx);
        goto after_6;
    // 0x800B8330: nop

    after_6:
    // 0x800B8334: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8338: sw          $zero, 0x3660($at)
    MEM_W(0X3660, ctx->r1) = 0;
L_800B833C:
    // 0x800B833C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B8340: lw          $a0, 0x3664($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3664);
    // 0x800B8344: nop

    // 0x800B8348: beq         $a0, $zero, L_800B8360
    if (ctx->r4 == 0) {
        // 0x800B834C: nop
    
            goto L_800B8360;
    }
    // 0x800B834C: nop

    // 0x800B8350: jal         0x80071380
    // 0x800B8354: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x800B8354: nop

    after_7:
    // 0x800B8358: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B835C: sw          $zero, 0x3664($at)
    MEM_W(0X3664, ctx->r1) = 0;
L_800B8360:
    // 0x800B8360: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B8364: lw          $a0, 0x3668($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3668);
    // 0x800B8368: nop

    // 0x800B836C: beq         $a0, $zero, L_800B8384
    if (ctx->r4 == 0) {
        // 0x800B8370: nop
    
            goto L_800B8384;
    }
    // 0x800B8370: nop

    // 0x800B8374: jal         0x80071380
    // 0x800B8378: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x800B8378: nop

    after_8:
    // 0x800B837C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8380: sw          $zero, 0x3668($at)
    MEM_W(0X3668, ctx->r1) = 0;
L_800B8384:
    // 0x800B8384: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B8388: lw          $a0, 0x3708($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3708);
    // 0x800B838C: nop

    // 0x800B8390: beq         $a0, $zero, L_800B83A8
    if (ctx->r4 == 0) {
        // 0x800B8394: nop
    
            goto L_800B83A8;
    }
    // 0x800B8394: nop

    // 0x800B8398: jal         0x80071380
    // 0x800B839C: nop

    mempool_free(rdram, ctx);
        goto after_9;
    // 0x800B839C: nop

    after_9:
    // 0x800B83A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B83A4: sw          $zero, 0x3708($at)
    MEM_W(0X3708, ctx->r1) = 0;
L_800B83A8:
    // 0x800B83A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B83AC: sw          $zero, 0x3720($at)
    MEM_W(0X3720, ctx->r1) = 0;
    // 0x800B83B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B83B4: sw          $zero, 0x3724($at)
    MEM_W(0X3724, ctx->r1) = 0;
    // 0x800B83B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B83BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B83C0: sw          $zero, 0x3714($at)
    MEM_W(0X3714, ctx->r1) = 0;
    // 0x800B83C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B83C8: sw          $zero, 0x3718($at)
    MEM_W(0X3718, ctx->r1) = 0;
    // 0x800B83CC: jr          $ra
    // 0x800B83D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B83D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void waves_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B83D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B83D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B83DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B83E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B83E4: jal         0x800B8240
    // 0x800B83E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    waves_free(rdram, ctx);
        goto after_0;
    // 0x800B83E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B83EC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B83F0: addiu       $s2, $s2, -0x5A78
    ctx->r18 = ADD32(ctx->r18, -0X5A78);
    // 0x800B83F4: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    // 0x800B83F8: lui         $s1, 0xFF
    ctx->r17 = S32(0XFF << 16);
    // 0x800B83FC: ori         $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 | 0XFFFF;
    // 0x800B8400: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800B8404: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B8408: jal         0x80070EDC
    // 0x800B840C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800B840C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800B8410: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8414: sw          $v0, 0x35D0($at)
    MEM_W(0X35D0, ctx->r1) = ctx->r2;
    // 0x800B8418: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800B841C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B8420: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800B8424: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8428: mflo        $a0
    ctx->r4 = lo;
    // 0x800B842C: jal         0x80070EDC
    // 0x800B8430: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800B8430: nop

    after_2:
    // 0x800B8434: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8438: sw          $v0, 0x35D4($at)
    MEM_W(0X35D4, ctx->r1) = ctx->r2;
    // 0x800B843C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800B8440: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B8444: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B8448: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800B844C: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8450: mflo        $a0
    ctx->r4 = lo;
    // 0x800B8454: jal         0x80070EDC
    // 0x800B8458: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x800B8458: nop

    after_3:
    // 0x800B845C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8460: sw          $v0, 0x35D8($at)
    MEM_W(0X35D8, ctx->r1) = ctx->r2;
    // 0x800B8464: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800B8468: addiu       $ra, $zero, 0x9
    ctx->r31 = ADD32(0, 0X9);
    // 0x800B846C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B8470: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800B8474: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8478: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B847C: mflo        $s0
    ctx->r16 = lo;
    // 0x800B8480: nop

    // 0x800B8484: nop

    // 0x800B8488: multu       $s0, $ra
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B848C: mflo        $a0
    ctx->r4 = lo;
    // 0x800B8490: jal         0x80070EDC
    // 0x800B8494: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800B8494: nop

    after_4:
    // 0x800B8498: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B849C: addiu       $a0, $a0, 0x35DC
    ctx->r4 = ADD32(ctx->r4, 0X35DC);
    // 0x800B84A0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B84A4: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x800B84A8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800B84AC: addiu       $ra, $zero, 0x9
    ctx->r31 = ADD32(0, 0X9);
    // 0x800B84B0: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x800B84B4: addiu       $v1, $v1, 0x35E0
    ctx->r3 = ADD32(ctx->r3, 0X35E0);
    // 0x800B84B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B84BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800B84C0: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800B84C4: sll         $a3, $s0, 1
    ctx->r7 = S32(ctx->r16 << 1);
    // 0x800B84C8: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x800B84CC: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800B84D0: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800B84D4: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
L_800B84D8:
    // 0x800B84D8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B84DC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B84E0: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800B84E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B84E8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800B84EC: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x800B84F0: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x800B84F4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800B84F8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B84FC: addu        $a3, $a3, $t3
    ctx->r7 = ADD32(ctx->r7, ctx->r11);
    // 0x800B8500: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800B8504: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800B8508: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800B850C: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x800B8510: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x800B8514: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x800B8518: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x800B851C: bne         $a1, $ra, L_800B84D8
    if (ctx->r5 != ctx->r31) {
        // 0x800B8520: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800B84D8;
    }
    // 0x800B8520: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B8524: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800B8528: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B852C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B8530: sll         $t6, $v1, 5
    ctx->r14 = S32(ctx->r3 << 5);
    // 0x800B8534: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x800B8538: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B853C: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800B8540: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800B8544: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8548: lw          $t7, -0x59C8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X59C8);
    // 0x800B854C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B8550: mflo        $s0
    ctx->r16 = lo;
    // 0x800B8554: sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16 << 1);
    // 0x800B8558: beq         $t7, $at, L_800B8580
    if (ctx->r15 == ctx->r1) {
        // 0x800B855C: nop
    
            goto L_800B8580;
    }
    // 0x800B855C: nop

    // 0x800B8560: jal         0x80070EDC
    // 0x800B8564: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x800B8564: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800B8568: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B856C: addiu       $v1, $v1, 0x3600
    ctx->r3 = ADD32(ctx->r3, 0X3600);
    // 0x800B8570: addu        $t9, $v0, $s0
    ctx->r25 = ADD32(ctx->r2, ctx->r16);
    // 0x800B8574: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B8578: b           L_800B85B0
    // 0x800B857C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_800B85B0;
    // 0x800B857C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_800B8580:
    // 0x800B8580: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x800B8584: jal         0x80070EDC
    // 0x800B8588: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x800B8588: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800B858C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B8590: addiu       $v1, $v1, 0x3600
    ctx->r3 = ADD32(ctx->r3, 0X3600);
    // 0x800B8594: addu        $t7, $v0, $s0
    ctx->r15 = ADD32(ctx->r2, ctx->r16);
    // 0x800B8598: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800B859C: addu        $t9, $t7, $s0
    ctx->r25 = ADD32(ctx->r15, ctx->r16);
    // 0x800B85A0: addu        $t7, $t9, $s0
    ctx->r15 = ADD32(ctx->r25, ctx->r16);
    // 0x800B85A4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B85A8: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x800B85AC: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
L_800B85B0:
    // 0x800B85B0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800B85B4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B85B8: sll         $t8, $v0, 5
    ctx->r24 = S32(ctx->r2 << 5);
    // 0x800B85BC: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B85C0: lw          $t9, -0x59C8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X59C8);
    // 0x800B85C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B85C8: mflo        $s0
    ctx->r16 = lo;
    // 0x800B85CC: sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16 << 1);
    // 0x800B85D0: beq         $t9, $at, L_800B85F8
    if (ctx->r25 == ctx->r1) {
        // 0x800B85D4: nop
    
            goto L_800B85F8;
    }
    // 0x800B85D4: nop

    // 0x800B85D8: jal         0x80070EDC
    // 0x800B85DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x800B85DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800B85E0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B85E4: addiu       $v1, $v1, 0x3610
    ctx->r3 = ADD32(ctx->r3, 0X3610);
    // 0x800B85E8: addu        $t7, $v0, $s0
    ctx->r15 = ADD32(ctx->r2, ctx->r16);
    // 0x800B85EC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B85F0: b           L_800B8628
    // 0x800B85F4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
        goto L_800B8628;
    // 0x800B85F4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_800B85F8:
    // 0x800B85F8: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x800B85FC: jal         0x80070EDC
    // 0x800B8600: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x800B8600: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800B8604: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B8608: addiu       $v1, $v1, 0x3610
    ctx->r3 = ADD32(ctx->r3, 0X3610);
    // 0x800B860C: addu        $t9, $v0, $s0
    ctx->r25 = ADD32(ctx->r2, ctx->r16);
    // 0x800B8610: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800B8614: addu        $t7, $t9, $s0
    ctx->r15 = ADD32(ctx->r25, ctx->r16);
    // 0x800B8618: addu        $t9, $t7, $s0
    ctx->r25 = ADD32(ctx->r15, ctx->r16);
    // 0x800B861C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B8620: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800B8624: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_800B8628:
    // 0x800B8628: lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X2C);
    // 0x800B862C: jal         0x8007B2C4
    // 0x800B8630: nop

    load_texture(rdram, ctx);
        goto after_9;
    // 0x800B8630: nop

    after_9:
    // 0x800B8634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B8638: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B863C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B8640: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8644: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B8648: sw          $v0, 0x3660($at)
    MEM_W(0X3660, ctx->r1) = ctx->r2;
    // 0x800B864C: jr          $ra
    // 0x800B8650: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B8650: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void waves_init_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8654: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B8658: lw          $v0, -0x59C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X59C8);
    // 0x800B865C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800B8660: beq         $v1, $v0, L_800B867C
    if (ctx->r3 == ctx->r2) {
        // 0x800B8664: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_800B867C;
    }
    // 0x800B8664: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B8668: lbu         $t6, 0x56($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X56);
    // 0x800B866C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B8670: addiu       $a1, $a1, -0x5A78
    ctx->r5 = ADD32(ctx->r5, -0X5A78);
    // 0x800B8674: b           L_800B8688
    // 0x800B8678: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
        goto L_800B8688;
    // 0x800B8678: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_800B867C:
    // 0x800B867C: addiu       $a1, $a1, -0x5A78
    ctx->r5 = ADD32(ctx->r5, -0X5A78);
    // 0x800B8680: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800B8684: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_800B8688:
    // 0x800B8688: lbu         $t8, 0x57($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X57);
    // 0x800B868C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800B8690: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800B8694: lbu         $t9, 0x58($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X58);
    // 0x800B8698: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B869C: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800B86A0: lh          $t0, 0x5A($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X5A);
    // 0x800B86A4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800B86A8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B86AC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800B86B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B86B4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B86B8: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    // 0x800B86BC: lbu         $t1, 0x59($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X59);
    // 0x800B86C0: nop

    // 0x800B86C4: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800B86C8: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x800B86CC: lbu         $t3, 0x5C($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X5C);
    // 0x800B86D0: nop

    // 0x800B86D4: sw          $t3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r11;
    // 0x800B86D8: lh          $t4, 0x5E($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X5E);
    // 0x800B86DC: nop

    // 0x800B86E0: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800B86E4: nop

    // 0x800B86E8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B86EC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B86F0: swc1        $f18, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f18.u32l;
    // 0x800B86F4: lbu         $t5, 0x5D($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X5D);
    // 0x800B86F8: nop

    // 0x800B86FC: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B8700: sw          $t6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r14;
    // 0x800B8704: lh          $t7, 0x60($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X60);
    // 0x800B8708: nop

    // 0x800B870C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800B8710: beq         $v1, $v0, L_800B8724
    if (ctx->r3 == ctx->r2) {
        // 0x800B8714: sw          $t8, 0x20($a1)
        MEM_W(0X20, ctx->r5) = ctx->r24;
            goto L_800B8724;
    }
    // 0x800B8714: sw          $t8, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r24;
    // 0x800B8718: lh          $t9, 0x6E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X6E);
    // 0x800B871C: b           L_800B8728
    // 0x800B8720: sw          $t9, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r25;
        goto L_800B8728;
    // 0x800B8720: sw          $t9, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r25;
L_800B8724:
    // 0x800B8724: sw          $t0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r8;
L_800B8728:
    // 0x800B8728: lbu         $t1, 0x71($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X71);
    // 0x800B872C: nop

    // 0x800B8730: sw          $t1, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r9;
    // 0x800B8734: lh          $t2, 0x68($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X68);
    // 0x800B8738: nop

    // 0x800B873C: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x800B8740: sw          $t3, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r11;
    // 0x800B8744: lbu         $t4, 0x6A($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X6A);
    // 0x800B8748: nop

    // 0x800B874C: sw          $t4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r12;
    // 0x800B8750: lbu         $t5, 0x6B($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X6B);
    // 0x800B8754: nop

    // 0x800B8758: sw          $t5, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r13;
    // 0x800B875C: lb          $t6, 0x6C($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X6C);
    // 0x800B8760: nop

    // 0x800B8764: sw          $t6, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->r14;
    // 0x800B8768: lb          $t7, 0x6D($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X6D);
    // 0x800B876C: nop

    // 0x800B8770: sw          $t7, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r15;
    // 0x800B8774: lh          $t8, 0x62($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X62);
    // 0x800B8778: nop

    // 0x800B877C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B8780: nop

    // 0x800B8784: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B8788: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B878C: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
    // 0x800B8790: lh          $t9, 0x64($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X64);
    // 0x800B8794: nop

    // 0x800B8798: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800B879C: nop

    // 0x800B87A0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B87A4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B87A8: swc1        $f18, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f18.u32l;
    // 0x800B87AC: lh          $t0, 0x66($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X66);
    // 0x800B87B0: nop

    // 0x800B87B4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B87B8: nop

    // 0x800B87BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B87C0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B87C4: swc1        $f8, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f8.u32l;
    // 0x800B87C8: lbu         $t1, 0x70($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X70);
    // 0x800B87CC: jr          $ra
    // 0x800B87D0: sw          $t1, 0x4C($a1)
    MEM_W(0X4C, ctx->r5) = ctx->r9;
    return;
    // 0x800B87D0: sw          $t1, 0x4C($a1)
    MEM_W(0X4C, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void waves_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B87D4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800B87D8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800B87DC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B87E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B87E4: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800B87E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B87EC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B87F0: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800B87F4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800B87F8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800B87FC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800B8800: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800B8804: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B8808: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B880C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B8810: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B8814: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B8818: sw          $a2, -0x59C8($at)
    MEM_W(-0X59C8, ctx->r1) = ctx->r6;
    // 0x800B881C: jal         0x800B8654
    // 0x800B8820: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    waves_init_header(rdram, ctx);
        goto after_0;
    // 0x800B8820: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800B8824: jal         0x800B83D4
    // 0x800B8828: nop

    waves_alloc(rdram, ctx);
        goto after_1;
    // 0x800B8828: nop

    after_1:
    // 0x800B882C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800B8830: jal         0x800BC2FC
    // 0x800B8834: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800BBDDC(rdram, ctx);
        goto after_2;
    // 0x800B8834: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800B8838: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B883C: lw          $t6, -0x5998($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5998);
    // 0x800B8840: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B8844: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B8848: addiu       $a1, $a1, -0x59A0
    ctx->r5 = ADD32(ctx->r5, -0X59A0);
    // 0x800B884C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B8850: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B8854: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800B8858: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x800B885C: lw          $t7, -0x5994($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5994);
    // 0x800B8860: addiu       $s4, $s4, -0x5A78
    ctx->r20 = ADD32(ctx->r20, -0X5A78);
    // 0x800B8864: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B8868: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B886C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B8870: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B8874: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B8878: addiu       $a2, $a2, -0x599C
    ctx->r6 = ADD32(ctx->r6, -0X599C);
    // 0x800B887C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B8880: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x800B8884: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B8888: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800B888C: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800B8890: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800B8894: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B8898: addiu       $s2, $s2, -0x5984
    ctx->r18 = ADD32(ctx->r18, -0X5984);
    // 0x800B889C: addiu       $s1, $s1, -0x5988
    ctx->r17 = ADD32(ctx->r17, -0X5988);
    // 0x800B88A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B88A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B88A8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800B88AC: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B88B0: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x800B88B4: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
    // 0x800B88B8: sw          $zero, -0x59BC($at)
    MEM_W(-0X59BC, ctx->r1) = 0;
    // 0x800B88BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B88C0: lw          $v1, -0x59C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X59C0);
    // 0x800B88C4: sw          $zero, -0x59B8($at)
    MEM_W(-0X59B8, ctx->r1) = 0;
    // 0x800B88C8: lw          $t9, 0x30($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X30);
    // 0x800B88CC: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x800B88D0: nop

    // 0x800B88D4: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B88D8: mflo        $t2
    ctx->r10 = lo;
    // 0x800B88DC: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x800B88E0: nop

    // 0x800B88E4: div         $zero, $t3, $v0
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r2)));
    // 0x800B88E8: bne         $v0, $zero, L_800B88F4
    if (ctx->r2 != 0) {
        // 0x800B88EC: nop
    
            goto L_800B88F4;
    }
    // 0x800B88EC: nop

    // 0x800B88F0: break       7
    do_break(2148239600);
L_800B88F4:
    // 0x800B88F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B88F8: bne         $v0, $at, L_800B890C
    if (ctx->r2 != ctx->r1) {
        // 0x800B88FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B890C;
    }
    // 0x800B88FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8900: bne         $t3, $at, L_800B890C
    if (ctx->r11 != ctx->r1) {
        // 0x800B8904: nop
    
            goto L_800B890C;
    }
    // 0x800B8904: nop

    // 0x800B8908: break       6
    do_break(2148239624);
L_800B890C:
    // 0x800B890C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8910: mflo        $t4
    ctx->r12 = lo;
    // 0x800B8914: sw          $t4, -0x59B4($at)
    MEM_W(-0X59B4, ctx->r1) = ctx->r12;
    // 0x800B8918: lw          $t6, 0x34($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X34);
    // 0x800B891C: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x800B8920: nop

    // 0x800B8924: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8928: mflo        $t7
    ctx->r15 = lo;
    // 0x800B892C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x800B8930: nop

    // 0x800B8934: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x800B8938: bne         $v0, $zero, L_800B8944
    if (ctx->r2 != 0) {
        // 0x800B893C: nop
    
            goto L_800B8944;
    }
    // 0x800B893C: nop

    // 0x800B8940: break       7
    do_break(2148239680);
L_800B8944:
    // 0x800B8944: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B8948: bne         $v0, $at, L_800B895C
    if (ctx->r2 != ctx->r1) {
        // 0x800B894C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B895C;
    }
    // 0x800B894C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8950: bne         $t8, $at, L_800B895C
    if (ctx->r24 != ctx->r1) {
        // 0x800B8954: nop
    
            goto L_800B895C;
    }
    // 0x800B8954: nop

    // 0x800B8958: break       6
    do_break(2148239704);
L_800B895C:
    // 0x800B895C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8960: mflo        $t9
    ctx->r25 = lo;
    // 0x800B8964: sw          $t9, -0x59B0($at)
    MEM_W(-0X59B0, ctx->r1) = ctx->r25;
    // 0x800B8968: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x800B896C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8970: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x800B8974: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800B8978: sw          $t4, -0x59AC($at)
    MEM_W(-0X59AC, ctx->r1) = ctx->r12;
    // 0x800B897C: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x800B8980: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8984: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x800B8988: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B898C: sw          $t7, -0x59A8($at)
    MEM_W(-0X59A8, ctx->r1) = ctx->r15;
    // 0x800B8990: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8994: sw          $zero, -0x59A4($at)
    MEM_W(-0X59A4, ctx->r1) = 0;
    // 0x800B8998: lw          $t8, 0x8($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X8);
    // 0x800B899C: lw          $a0, 0x20($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X20);
    // 0x800B89A0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800B89A4: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x800B89A8: lw          $t3, 0x14($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X14);
    // 0x800B89AC: lw          $s6, 0x10($s4)
    ctx->r22 = MEM_W(ctx->r20, 0X10);
    // 0x800B89B0: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800B89B4: bne         $a0, $zero, L_800B89C0
    if (ctx->r4 != 0) {
        // 0x800B89B8: nop
    
            goto L_800B89C0;
    }
    // 0x800B89B8: nop

    // 0x800B89BC: break       7
    do_break(2148239804);
L_800B89C0:
    // 0x800B89C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B89C4: bne         $a0, $at, L_800B89D8
    if (ctx->r4 != ctx->r1) {
        // 0x800B89C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B89D8;
    }
    // 0x800B89C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B89CC: bne         $t9, $at, L_800B89D8
    if (ctx->r25 != ctx->r1) {
        // 0x800B89D0: nop
    
            goto L_800B89D8;
    }
    // 0x800B89D0: nop

    // 0x800B89D4: break       6
    do_break(2148239828);
L_800B89D8:
    // 0x800B89D8: lw          $fp, 0x1C($s4)
    ctx->r30 = MEM_W(ctx->r20, 0X1C);
    // 0x800B89DC: mflo        $t2
    ctx->r10 = lo;
    // 0x800B89E0: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800B89E4: nop

    // 0x800B89E8: div         $zero, $t4, $a0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r4)));
    // 0x800B89EC: bne         $a0, $zero, L_800B89F8
    if (ctx->r4 != 0) {
        // 0x800B89F0: nop
    
            goto L_800B89F8;
    }
    // 0x800B89F0: nop

    // 0x800B89F4: break       7
    do_break(2148239860);
L_800B89F8:
    // 0x800B89F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B89FC: bne         $a0, $at, L_800B8A10
    if (ctx->r4 != ctx->r1) {
        // 0x800B8A00: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B8A10;
    }
    // 0x800B8A00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8A04: bne         $t4, $at, L_800B8A10
    if (ctx->r12 != ctx->r1) {
        // 0x800B8A08: nop
    
            goto L_800B8A10;
    }
    // 0x800B8A08: nop

    // 0x800B8A0C: break       6
    do_break(2148239884);
L_800B8A10:
    // 0x800B8A10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B8A14: lwc1        $f10, -0x67E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X67E0);
    // 0x800B8A18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8A1C: swc1        $f10, -0x5A24($at)
    MEM_W(-0X5A24, ctx->r1) = ctx->f10.u32l;
    // 0x800B8A20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B8A24: lwc1        $f16, -0x67DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X67DC);
    // 0x800B8A28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8A2C: swc1        $f16, -0x5A20($at)
    MEM_W(-0X5A20, ctx->r1) = ctx->f16.u32l;
    // 0x800B8A30: mflo        $t5
    ctx->r13 = lo;
    // 0x800B8A34: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800B8A38: blez        $a0, L_800B8B38
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B8A3C: lui         $s5, 0x800E
        ctx->r21 = S32(0X800E << 16);
            goto L_800B8B38;
    }
    // 0x800B8A3C: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800B8A40: addiu       $s5, $s5, 0x35D0
    ctx->r21 = ADD32(ctx->r21, 0X35D0);
    // 0x800B8A44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B8A48:
    // 0x800B8A48: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B8A4C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B8A50: jal         0x80070A04
    // 0x800B8A54: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x800B8A54: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_3:
    // 0x800B8A58: sll         $a0, $fp, 16
    ctx->r4 = S32(ctx->r30 << 16);
    // 0x800B8A5C: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B8A60: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800B8A64: jal         0x80070A04
    // 0x800B8A68: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_4;
    // 0x800B8A68: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_4:
    // 0x800B8A6C: lwc1        $f18, 0x18($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800B8A70: lwc1        $f6, 0xC($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800B8A74: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800B8A78: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x800B8A7C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B8A80: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800B8A84: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800B8A88: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B8A8C: addiu       $v1, $v1, -0x5A24
    ctx->r3 = ADD32(ctx->r3, -0X5A24);
    // 0x800B8A90: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B8A94: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x800B8A98: lw          $t2, 0x28($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X28);
    // 0x800B8A9C: nop

    // 0x800B8AA0: beq         $t2, $zero, L_800B8AC4
    if (ctx->r10 == 0) {
        // 0x800B8AA4: nop
    
            goto L_800B8AC4;
    }
    // 0x800B8AA4: nop

    // 0x800B8AA8: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x800B8AAC: nop

    // 0x800B8AB0: addu        $v0, $t3, $s0
    ctx->r2 = ADD32(ctx->r11, ctx->r16);
    // 0x800B8AB4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B8AB8: nop

    // 0x800B8ABC: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B8AC0: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_800B8AC4:
    // 0x800B8AC4: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x800B8AC8: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B8ACC: addu        $v0, $t4, $s0
    ctx->r2 = ADD32(ctx->r12, ctx->r16);
    // 0x800B8AD0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B8AD4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B8AD8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800B8ADC: nop

    // 0x800B8AE0: bc1f        L_800B8AF4
    if (!c1cs) {
        // 0x800B8AE4: nop
    
            goto L_800B8AF4;
    }
    // 0x800B8AE4: nop

    // 0x800B8AE8: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800B8AEC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B8AF0: nop

L_800B8AF4:
    // 0x800B8AF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B8AF8: addiu       $v0, $v0, -0x5A20
    ctx->r2 = ADD32(ctx->r2, -0X5A20);
    // 0x800B8AFC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B8B00: nop

    // 0x800B8B04: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800B8B08: nop

    // 0x800B8B0C: bc1f        L_800B8B18
    if (!c1cs) {
        // 0x800B8B10: nop
    
            goto L_800B8B18;
    }
    // 0x800B8B10: nop

    // 0x800B8B14: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800B8B18:
    // 0x800B8B18: lw          $t7, 0x20($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X20);
    // 0x800B8B1C: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800B8B20: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800B8B24: slt         $at, $s7, $t7
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B8B28: addu        $s6, $s6, $t5
    ctx->r22 = ADD32(ctx->r22, ctx->r13);
    // 0x800B8B2C: bne         $at, $zero, L_800B8A48
    if (ctx->r1 != 0) {
        // 0x800B8B30: addu        $fp, $fp, $t6
        ctx->r30 = ADD32(ctx->r30, ctx->r14);
            goto L_800B8A48;
    }
    // 0x800B8B30: addu        $fp, $fp, $t6
    ctx->r30 = ADD32(ctx->r30, ctx->r14);
    // 0x800B8B34: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_800B8B38:
    // 0x800B8B38: jal         0x8006FB58
    // 0x800B8B3C: nop

    save_rng_seed(rdram, ctx);
        goto after_5;
    // 0x800B8B3C: nop

    after_5:
    // 0x800B8B40: lui         $a0, 0x5741
    ctx->r4 = S32(0X5741 << 16);
    // 0x800B8B44: jal         0x8006FB4C
    // 0x800B8B48: ori         $a0, $a0, 0x5646
    ctx->r4 = ctx->r4 | 0X5646;
    set_rng_seed(rdram, ctx);
        goto after_6;
    // 0x800B8B48: ori         $a0, $a0, 0x5646
    ctx->r4 = ctx->r4 | 0X5646;
    after_6:
    // 0x800B8B4C: lw          $v1, 0x4($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X4);
    // 0x800B8B50: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B8B54: blez        $v1, L_800B8BD8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B8B58: nop
    
            goto L_800B8BD8;
    }
    // 0x800B8B58: nop

    // 0x800B8B5C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800B8B60: addiu       $fp, $fp, 0x35D4
    ctx->r30 = ADD32(ctx->r30, 0X35D4);
L_800B8B64:
    // 0x800B8B64: blez        $v1, L_800B8BC0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B8B68: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B8BC0;
    }
    // 0x800B8B68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B8B6C: sll         $s6, $s5, 2
    ctx->r22 = S32(ctx->r21 << 2);
L_800B8B70:
    // 0x800B8B70: lw          $a1, 0x20($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X20);
    // 0x800B8B74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8B78: jal         0x8006FB8C
    // 0x800B8B7C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800B8B7C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_7:
    // 0x800B8B80: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B8B84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8B88: addu        $t9, $t8, $s6
    ctx->r25 = ADD32(ctx->r24, ctx->r22);
    // 0x800B8B8C: sh          $v0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r2;
    // 0x800B8B90: lw          $a1, 0x20($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X20);
    // 0x800B8B94: jal         0x8006FB8C
    // 0x800B8B98: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_8;
    // 0x800B8B98: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_8:
    // 0x800B8B9C: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800B8BA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B8BA4: addu        $t3, $t2, $s6
    ctx->r11 = ADD32(ctx->r10, ctx->r22);
    // 0x800B8BA8: sh          $v0, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r2;
    // 0x800B8BAC: lw          $v1, 0x4($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X4);
    // 0x800B8BB0: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800B8BB4: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B8BB8: bne         $at, $zero, L_800B8B70
    if (ctx->r1 != 0) {
        // 0x800B8BBC: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800B8B70;
    }
    // 0x800B8BBC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800B8BC0:
    // 0x800B8BC0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B8BC4: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B8BC8: bne         $at, $zero, L_800B8B64
    if (ctx->r1 != 0) {
        // 0x800B8BCC: nop
    
            goto L_800B8B64;
    }
    // 0x800B8BCC: nop

    // 0x800B8BD0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800B8BD4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_800B8BD8:
    // 0x800B8BD8: jal         0x8006FB6C
    // 0x800B8BDC: nop

    load_rng_seed(rdram, ctx);
        goto after_9;
    // 0x800B8BDC: nop

    after_9:
    // 0x800B8BE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B8BE4: beq         $s3, $at, L_800B8BF4
    if (ctx->r19 == ctx->r1) {
        // 0x800B8BE8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800B8BF4;
    }
    // 0x800B8BE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B8BEC: b           L_800B8BF8
    // 0x800B8BF0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
        goto L_800B8BF8;
    // 0x800B8BF0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_800B8BF4:
    // 0x800B8BF4: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_800B8BF8:
    // 0x800B8BF8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B8BFC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800B8C00: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B8C04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B8C08: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_800B8C0C:
    // 0x800B8C0C: bltz        $v0, L_800B8D80
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B8C10: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800B8D80;
    }
    // 0x800B8C10: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800B8C14:
    // 0x800B8C14: bltz        $v0, L_800B8D6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B8C18: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B8D6C;
    }
    // 0x800B8C18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B8C1C:
    // 0x800B8C1C: blez        $s3, L_800B8D5C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800B8C20: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B8D5C;
    }
    // 0x800B8C20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8C24: mtc1        $s0, $f20
    ctx->f20.u32l = ctx->r16;
    // 0x800B8C28: mtc1        $s7, $f18
    ctx->f18.u32l = ctx->r23;
    // 0x800B8C2C: cvt.s.w     $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800B8C30: sll         $v1, $s5, 2
    ctx->r3 = S32(ctx->r21 << 2);
    // 0x800B8C34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B8C38: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B8C3C: addu        $v1, $v1, $s5
    ctx->r3 = ADD32(ctx->r3, ctx->r21);
    // 0x800B8C40: addiu       $v0, $v0, 0x3600
    ctx->r2 = ADD32(ctx->r2, 0X3600);
    // 0x800B8C44: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_800B8C48:
    // 0x800B8C48: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800B8C4C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B8C50: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800B8C54: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800B8C58: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B8C5C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800B8C60: add.d       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f18.d + ctx->f0.d;
    // 0x800B8C64: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B8C68: nop

    // 0x800B8C6C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B8C70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B8C74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B8C78: nop

    // 0x800B8C7C: cvt.w.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_D(ctx->f6.d);
    // 0x800B8C80: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800B8C84: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B8C88: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x800B8C8C: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800B8C90: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B8C94: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800B8C98: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x800B8C9C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800B8CA0: add.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f16.d + ctx->f0.d;
    // 0x800B8CA4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B8CA8: nop

    // 0x800B8CAC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B8CB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B8CB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B8CB8: nop

    // 0x800B8CBC: cvt.w.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_D(ctx->f18.d);
    // 0x800B8CC0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800B8CC4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B8CC8: sh          $t9, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r25;
    // 0x800B8CCC: lw          $t4, 0x4C($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X4C);
    // 0x800B8CD0: nop

    // 0x800B8CD4: bne         $t4, $zero, L_800B8D10
    if (ctx->r12 != 0) {
        // 0x800B8CD8: nop
    
            goto L_800B8D10;
    }
    // 0x800B8CD8: nop

    // 0x800B8CDC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B8CE0: nop

    // 0x800B8CE4: addu        $t5, $t6, $v1
    ctx->r13 = ADD32(ctx->r14, ctx->r3);
    // 0x800B8CE8: sb          $a1, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r5;
    // 0x800B8CEC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B8CF0: nop

    // 0x800B8CF4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800B8CF8: sb          $a1, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r5;
    // 0x800B8CFC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B8D00: nop

    // 0x800B8D04: addu        $t9, $t2, $v1
    ctx->r25 = ADD32(ctx->r10, ctx->r3);
    // 0x800B8D08: b           L_800B8D40
    // 0x800B8D0C: sb          $a1, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r5;
        goto L_800B8D40;
    // 0x800B8D0C: sb          $a1, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r5;
L_800B8D10:
    // 0x800B8D10: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800B8D14: nop

    // 0x800B8D18: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x800B8D1C: sb          $zero, 0x6($t4)
    MEM_B(0X6, ctx->r12) = 0;
    // 0x800B8D20: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B8D24: nop

    // 0x800B8D28: addu        $t5, $t6, $v1
    ctx->r13 = ADD32(ctx->r14, ctx->r3);
    // 0x800B8D2C: sb          $zero, 0x7($t5)
    MEM_B(0X7, ctx->r13) = 0;
    // 0x800B8D30: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B8D34: nop

    // 0x800B8D38: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800B8D3C: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
L_800B8D40:
    // 0x800B8D40: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B8D44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B8D48: addu        $t9, $t2, $v1
    ctx->r25 = ADD32(ctx->r10, ctx->r3);
    // 0x800B8D4C: bne         $a0, $s3, L_800B8C48
    if (ctx->r4 != ctx->r19) {
        // 0x800B8D50: sb          $a1, 0x9($t9)
        MEM_B(0X9, ctx->r25) = ctx->r5;
            goto L_800B8C48;
    }
    // 0x800B8D50: sb          $a1, 0x9($t9)
    MEM_B(0X9, ctx->r25) = ctx->r5;
    // 0x800B8D54: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B8D58: nop

L_800B8D5C:
    // 0x800B8D5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B8D60: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800B8D64: beq         $at, $zero, L_800B8C1C
    if (ctx->r1 == 0) {
        // 0x800B8D68: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800B8C1C;
    }
    // 0x800B8D68: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800B8D6C:
    // 0x800B8D6C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B8D70: slt         $at, $v0, $s7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x800B8D74: beq         $at, $zero, L_800B8C14
    if (ctx->r1 == 0) {
        // 0x800B8D78: nop
    
            goto L_800B8C14;
    }
    // 0x800B8D78: nop

    // 0x800B8D7C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_800B8D80:
    // 0x800B8D80: slti        $at, $a2, 0x19
    ctx->r1 = SIGNED(ctx->r6) < 0X19 ? 1 : 0;
    // 0x800B8D84: bne         $at, $zero, L_800B8C0C
    if (ctx->r1 != 0) {
        // 0x800B8D88: nop
    
            goto L_800B8C0C;
    }
    // 0x800B8D88: nop

    // 0x800B8D8C: blez        $v0, L_800B8E80
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B8D90: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800B8E80;
    }
    // 0x800B8D90: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B8D94: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
L_800B8D98:
    // 0x800B8D98: blez        $v0, L_800B8E70
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B8D9C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B8E70;
    }
    // 0x800B8D9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B8DA0:
    // 0x800B8DA0: blez        $s3, L_800B8E60
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800B8DA4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B8E60;
    }
    // 0x800B8DA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8DA8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B8DAC: addiu       $v1, $v1, 0x3610
    ctx->r3 = ADD32(ctx->r3, 0X3610);
    // 0x800B8DB0: addiu       $a1, $s0, 0x1
    ctx->r5 = ADD32(ctx->r16, 0X1);
    // 0x800B8DB4: sll         $v0, $s5, 4
    ctx->r2 = S32(ctx->r21 << 4);
L_800B8DB8:
    // 0x800B8DB8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800B8DBC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B8DC0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800B8DC4: sb          $a2, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r6;
    // 0x800B8DC8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B8DCC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B8DD0: addu        $t5, $t6, $v0
    ctx->r13 = ADD32(ctx->r14, ctx->r2);
    // 0x800B8DD4: sb          $s0, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r16;
    // 0x800B8DD8: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800B8DDC: lw          $t9, -0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X4);
    // 0x800B8DE0: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800B8DE4: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x800B8DE8: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800B8DEC: sb          $t2, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r10;
    // 0x800B8DF0: lw          $t4, -0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X4);
    // 0x800B8DF4: addiu       $s5, $s5, 0x0
    ctx->r21 = ADD32(ctx->r21, 0X0);
    // 0x800B8DF8: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800B8DFC: sb          $a1, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r5;
    // 0x800B8E00: lw          $t5, -0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X4);
    // 0x800B8E04: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800B8E08: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800B8E0C: sb          $a2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r6;
    // 0x800B8E10: lw          $t8, -0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X4);
    // 0x800B8E14: nop

    // 0x800B8E18: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800B8E1C: sb          $a1, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r5;
    // 0x800B8E20: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800B8E24: lw          $t6, -0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X4);
    // 0x800B8E28: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800B8E2C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B8E30: addu        $t5, $t6, $v0
    ctx->r13 = ADD32(ctx->r14, ctx->r2);
    // 0x800B8E34: sb          $t4, 0x2($t5)
    MEM_B(0X2, ctx->r13) = ctx->r12;
    // 0x800B8E38: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800B8E3C: lw          $t2, -0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, -0X4);
    // 0x800B8E40: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800B8E44: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x800B8E48: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800B8E4C: sb          $t9, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r25;
    // 0x800B8E50: bne         $a0, $s3, L_800B8DB8
    if (ctx->r4 != ctx->r19) {
        // 0x800B8E54: addiu       $v0, $v0, -0x10
        ctx->r2 = ADD32(ctx->r2, -0X10);
            goto L_800B8DB8;
    }
    // 0x800B8E54: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // 0x800B8E58: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B8E5C: nop

L_800B8E60:
    // 0x800B8E60: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B8E64: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B8E68: bne         $at, $zero, L_800B8DA0
    if (ctx->r1 != 0) {
        // 0x800B8E6C: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_800B8DA0;
    }
    // 0x800B8E6C: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
L_800B8E70:
    // 0x800B8E70: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B8E74: slt         $at, $s7, $v0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B8E78: bne         $at, $zero, L_800B8D98
    if (ctx->r1 != 0) {
        // 0x800B8E7C: nop
    
            goto L_800B8D98;
    }
    // 0x800B8E7C: nop

L_800B8E80:
    // 0x800B8E80: jal         0x800BCBE8
    // 0x800B8E84: nop

    func_800BC6C8(rdram, ctx);
        goto after_10;
    // 0x800B8E84: nop

    after_10:
    // 0x800B8E88: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B8E8C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B8E90: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800B8E94: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8E98: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800B8E9C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B8EA0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B8EA4: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800B8EA8: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800B8EAC: addiu       $t1, $t1, 0x3608
    ctx->r9 = ADD32(ctx->r9, 0X3608);
    // 0x800B8EB0: addiu       $a3, $a3, 0x3600
    ctx->r7 = ADD32(ctx->r7, 0X3600);
    // 0x800B8EB4: addiu       $a0, $a0, -0x5A18
    ctx->r4 = ADD32(ctx->r4, -0X5A18);
    // 0x800B8EB8: mflo        $s5
    ctx->r21 = lo;
    // 0x800B8EBC: sll         $v1, $s5, 2
    ctx->r3 = S32(ctx->r21 << 2);
    // 0x800B8EC0: addu        $v1, $v1, $s5
    ctx->r3 = ADD32(ctx->r3, ctx->r21);
    // 0x800B8EC4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_800B8EC8:
    // 0x800B8EC8: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800B8ECC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800B8ED0: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x800B8ED4: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x800B8ED8: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x800B8EDC: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x800B8EE0: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x800B8EE4: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x800B8EE8: lbu         $t7, 0x6($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X6);
    // 0x800B8EEC: addu        $a2, $a1, $v1
    ctx->r6 = ADD32(ctx->r5, ctx->r3);
    // 0x800B8EF0: sb          $t7, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r15;
    // 0x800B8EF4: lbu         $t8, 0x7($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X7);
    // 0x800B8EF8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x800B8EFC: sb          $t8, -0x21($a0)
    MEM_B(-0X21, ctx->r4) = ctx->r24;
    // 0x800B8F00: lbu         $t2, 0x8($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X8);
    // 0x800B8F04: nop

    // 0x800B8F08: sb          $t2, -0x20($a0)
    MEM_B(-0X20, ctx->r4) = ctx->r10;
    // 0x800B8F0C: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x800B8F10: nop

    // 0x800B8F14: sb          $t9, -0x1F($a0)
    MEM_B(-0X1F, ctx->r4) = ctx->r25;
    // 0x800B8F18: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800B8F1C: sh          $zero, -0x1C($a0)
    MEM_H(-0X1C, ctx->r4) = 0;
    // 0x800B8F20: sh          $t3, -0x1E($a0)
    MEM_H(-0X1E, ctx->r4) = ctx->r11;
    // 0x800B8F24: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800B8F28: nop

    // 0x800B8F2C: sh          $t6, -0x1A($a0)
    MEM_H(-0X1A, ctx->r4) = ctx->r14;
    // 0x800B8F30: lbu         $t4, 0x6($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X6);
    // 0x800B8F34: nop

    // 0x800B8F38: sb          $t4, -0x18($a0)
    MEM_B(-0X18, ctx->r4) = ctx->r12;
    // 0x800B8F3C: lbu         $t5, 0x7($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X7);
    // 0x800B8F40: nop

    // 0x800B8F44: sb          $t5, -0x17($a0)
    MEM_B(-0X17, ctx->r4) = ctx->r13;
    // 0x800B8F48: lbu         $t7, 0x8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X8);
    // 0x800B8F4C: nop

    // 0x800B8F50: sb          $t7, -0x16($a0)
    MEM_B(-0X16, ctx->r4) = ctx->r15;
    // 0x800B8F54: lbu         $t8, 0x9($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X9);
    // 0x800B8F58: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x800B8F5C: sb          $t8, -0x15($a0)
    MEM_B(-0X15, ctx->r4) = ctx->r24;
    // 0x800B8F60: lh          $t2, 0x0($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X0);
    // 0x800B8F64: sh          $zero, -0x12($a0)
    MEM_H(-0X12, ctx->r4) = 0;
    // 0x800B8F68: sh          $t2, -0x14($a0)
    MEM_H(-0X14, ctx->r4) = ctx->r10;
    // 0x800B8F6C: lh          $t9, 0x4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4);
    // 0x800B8F70: addu        $t7, $t7, $s5
    ctx->r15 = ADD32(ctx->r15, ctx->r21);
    // 0x800B8F74: sh          $t9, -0x10($a0)
    MEM_H(-0X10, ctx->r4) = ctx->r25;
    // 0x800B8F78: lbu         $t3, 0x6($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X6);
    // 0x800B8F7C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800B8F80: sb          $t3, -0xE($a0)
    MEM_B(-0XE, ctx->r4) = ctx->r11;
    // 0x800B8F84: lbu         $t6, 0x7($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X7);
    // 0x800B8F88: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800B8F8C: sb          $t6, -0xD($a0)
    MEM_B(-0XD, ctx->r4) = ctx->r14;
    // 0x800B8F90: lbu         $t4, 0x8($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X8);
    // 0x800B8F94: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x800B8F98: sb          $t4, -0xC($a0)
    MEM_B(-0XC, ctx->r4) = ctx->r12;
    // 0x800B8F9C: lbu         $t5, 0x9($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X9);
    // 0x800B8FA0: nop

    // 0x800B8FA4: sb          $t5, -0xB($a0)
    MEM_B(-0XB, ctx->r4) = ctx->r13;
    // 0x800B8FA8: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800B8FAC: sh          $zero, -0x8($a0)
    MEM_H(-0X8, ctx->r4) = 0;
    // 0x800B8FB0: sh          $t2, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r10;
    // 0x800B8FB4: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800B8FB8: nop

    // 0x800B8FBC: sh          $t9, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r25;
    // 0x800B8FC0: lbu         $t3, 0x6($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X6);
    // 0x800B8FC4: nop

    // 0x800B8FC8: sb          $t3, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r11;
    // 0x800B8FCC: lbu         $t6, 0x7($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X7);
    // 0x800B8FD0: nop

    // 0x800B8FD4: sb          $t6, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r14;
    // 0x800B8FD8: lbu         $t4, 0x8($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X8);
    // 0x800B8FDC: nop

    // 0x800B8FE0: sb          $t4, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r12;
    // 0x800B8FE4: lbu         $t5, 0x9($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X9);
    // 0x800B8FE8: bne         $a3, $t1, L_800B8EC8
    if (ctx->r7 != ctx->r9) {
        // 0x800B8FEC: sb          $t5, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r13;
            goto L_800B8EC8;
    }
    // 0x800B8FEC: sb          $t5, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r13;
    // 0x800B8FF0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800B8FF4: jal         0x800BD190
    // 0x800B8FF8: nop

    func_800BCC70(rdram, ctx);
        goto after_11;
    // 0x800B8FF8: nop

    after_11:
    // 0x800B8FFC: lw          $t7, 0x24($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X24);
    // 0x800B9000: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B9004: bne         $t7, $at, L_800B9030
    if (ctx->r15 != ctx->r1) {
        // 0x800B9008: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_800B9030;
    }
    // 0x800B9008: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800B900C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B9010: addiu       $t8, $t8, 0x3678
    ctx->r24 = ADD32(ctx->r24, 0X3678);
    // 0x800B9014: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B9018: sw          $t8, 0x3670($at)
    MEM_W(0X3670, ctx->r1) = ctx->r24;
    // 0x800B901C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B9020: addiu       $t2, $t2, 0x368C
    ctx->r10 = ADD32(ctx->r10, 0X368C);
    // 0x800B9024: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B9028: b           L_800B9054
    // 0x800B902C: sw          $t2, 0x3674($at)
    MEM_W(0X3674, ctx->r1) = ctx->r10;
        goto L_800B9054;
    // 0x800B902C: sw          $t2, 0x3674($at)
    MEM_W(0X3674, ctx->r1) = ctx->r10;
L_800B9030:
    // 0x800B9030: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B9034: sw          $t9, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->r25;
    // 0x800B9038: addiu       $t3, $t3, 0x36A0
    ctx->r11 = ADD32(ctx->r11, 0X36A0);
    // 0x800B903C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B9040: sw          $t3, 0x3670($at)
    MEM_W(0X3670, ctx->r1) = ctx->r11;
    // 0x800B9044: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B9048: addiu       $t6, $t6, 0x36D4
    ctx->r14 = ADD32(ctx->r14, 0X36D4);
    // 0x800B904C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B9050: sw          $t6, 0x3674($at)
    MEM_W(0X3674, ctx->r1) = ctx->r14;
L_800B9054:
    // 0x800B9054: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B9058: sw          $zero, 0x3718($at)
    MEM_W(0X3718, ctx->r1) = 0;
    // 0x800B905C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B9060: sw          $zero, -0x5318($at)
    MEM_W(-0X5318, ctx->r1) = 0;
    // 0x800B9064: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B9068: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B906C: sw          $zero, 0x3728($at)
    MEM_W(0X3728, ctx->r1) = 0;
    // 0x800B9070: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B9074: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B9078: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B907C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B9080: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B9084: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B9088: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B908C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B9090: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800B9094: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800B9098: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800B909C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800B90A0: sw          $zero, -0x5A28($at)
    MEM_W(-0X5A28, ctx->r1) = 0;
    // 0x800B90A4: jr          $ra
    // 0x800B90A8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800B90A8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void waves_visibility_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B90AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B90B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B90B4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B90B8: sw          $zero, 0x366C($at)
    MEM_W(0X366C, ctx->r1) = 0;
    // 0x800B90BC: addiu       $a1, $a1, -0x5964
    ctx->r5 = ADD32(ctx->r5, -0X5964);
    // 0x800B90C0: addiu       $a0, $a0, -0x5968
    ctx->r4 = ADD32(ctx->r4, -0X5968);
    // 0x800B90C4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B90C8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800B90CC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800B90D0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B90D4: addiu       $a2, $a2, 0x3664
    ctx->r6 = ADD32(ctx->r6, 0X3664);
    // 0x800B90D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B90DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B90E0: mflo        $t8
    ctx->r24 = lo;
    // 0x800B90E4: blez        $t8, L_800B911C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B90E8: nop
    
            goto L_800B911C;
    }
    // 0x800B90E8: nop

L_800B90EC:
    // 0x800B90EC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B90F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B90F4: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x800B90F8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800B90FC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800B9100: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800B9104: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B9108: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B910C: mflo        $t3
    ctx->r11 = lo;
    // 0x800B9110: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B9114: bne         $at, $zero, L_800B90EC
    if (ctx->r1 != 0) {
        // 0x800B9118: nop
    
            goto L_800B90EC;
    }
    // 0x800B9118: nop

L_800B911C:
    // 0x800B911C: jr          $ra
    // 0x800B9120: nop

    return;
    // 0x800B9120: nop

;}
RECOMP_FUNC void waves_visibility(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9124: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B9128: lw          $t2, -0x5970($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5970);
    // 0x800B912C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800B9130: lw          $t0, -0x5998($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5998);
    // 0x800B9134: subu        $t6, $a0, $t2
    ctx->r14 = SUB32(ctx->r4, ctx->r10);
    // 0x800B9138: div         $zero, $t6, $t0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r8)));
    // 0x800B913C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B9140: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800B9144: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B9148: lw          $t4, -0x596C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X596C);
    // 0x800B914C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B9150: lw          $t1, -0x5994($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5994);
    // 0x800B9154: subu        $t7, $a2, $t4
    ctx->r15 = SUB32(ctx->r6, ctx->r12);
    // 0x800B9158: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800B915C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B9160: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B9164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B9168: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800B916C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800B9170: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B9174: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800B9178: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B917C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800B9180: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800B9184: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800B9188: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B918C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B9190: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B9194: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B9198: bne         $t0, $zero, L_800B91A4
    if (ctx->r8 != 0) {
        // 0x800B919C: nop
    
            goto L_800B91A4;
    }
    // 0x800B919C: nop

    // 0x800B91A0: break       7
    do_break(2148241824);
L_800B91A4:
    // 0x800B91A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B91A8: bne         $t0, $at, L_800B91BC
    if (ctx->r8 != ctx->r1) {
        // 0x800B91AC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B91BC;
    }
    // 0x800B91AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B91B0: bne         $t6, $at, L_800B91BC
    if (ctx->r14 != ctx->r1) {
        // 0x800B91B4: nop
    
            goto L_800B91BC;
    }
    // 0x800B91B4: nop

    // 0x800B91B8: break       6
    do_break(2148241848);
L_800B91BC:
    // 0x800B91BC: mflo        $a1
    ctx->r5 = lo;
    // 0x800B91C0: addiu       $v1, $v1, -0x5440
    ctx->r3 = ADD32(ctx->r3, -0X5440);
    // 0x800B91C4: addiu       $a0, $a0, -0x5320
    ctx->r4 = ADD32(ctx->r4, -0X5320);
    // 0x800B91C8: div         $zero, $t7, $t1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r9)));
    // 0x800B91CC: bne         $t1, $zero, L_800B91D8
    if (ctx->r9 != 0) {
        // 0x800B91D0: nop
    
            goto L_800B91D8;
    }
    // 0x800B91D0: nop

    // 0x800B91D4: break       7
    do_break(2148241876);
L_800B91D8:
    // 0x800B91D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B91DC: bne         $t1, $at, L_800B91F0
    if (ctx->r9 != ctx->r1) {
        // 0x800B91E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B91F0;
    }
    // 0x800B91E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B91E4: bne         $t7, $at, L_800B91F0
    if (ctx->r15 != ctx->r1) {
        // 0x800B91E8: nop
    
            goto L_800B91F0;
    }
    // 0x800B91E8: nop

    // 0x800B91EC: break       6
    do_break(2148241900);
L_800B91F0:
    // 0x800B91F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B91F4: sh          $t8, -0x5458($at)
    MEM_H(-0X5458, ctx->r1) = ctx->r24;
    // 0x800B91F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B91FC: sh          $t9, -0x544C($at)
    MEM_H(-0X544C, ctx->r1) = ctx->r25;
    // 0x800B9200: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B9204: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B9208: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B920C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B9210: mflo        $s7
    ctx->r23 = lo;
    // 0x800B9214: nop

    // 0x800B9218: nop

L_800B921C:
    // 0x800B921C: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x800B9220: sh          $v0, -0x30($v1)
    MEM_H(-0X30, ctx->r3) = ctx->r2;
    // 0x800B9224: sh          $v0, -0x24($v1)
    MEM_H(-0X24, ctx->r3) = ctx->r2;
    // 0x800B9228: sh          $v0, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r2;
    // 0x800B922C: bne         $v1, $a0, L_800B921C
    if (ctx->r3 != ctx->r4) {
        // 0x800B9230: sh          $v0, -0xC($v1)
        MEM_H(-0XC, ctx->r3) = ctx->r2;
            goto L_800B921C;
    }
    // 0x800B9230: sh          $v0, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = ctx->r2;
    // 0x800B9234: addiu       $t3, $t3, -0x5A78
    ctx->r11 = ADD32(ctx->r11, -0X5A78);
    // 0x800B9238: lw          $t6, 0x28($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X28);
    // 0x800B923C: nop

    // 0x800B9240: beq         $t6, $zero, L_800B9564
    if (ctx->r14 == 0) {
        // 0x800B9244: nop
    
            goto L_800B9564;
    }
    // 0x800B9244: nop

    // 0x800B9248: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B924C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800B9250: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B9254: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B9258: addiu       $s2, $s2, 0x370C
    ctx->r18 = ADD32(ctx->r18, 0X370C);
    // 0x800B925C: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x800B9260: addiu       $ra, $zero, 0x1C
    ctx->r31 = ADD32(0, 0X1C);
    // 0x800B9264: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9268: subu        $t8, $s0, $t7
    ctx->r24 = SUB32(ctx->r16, ctx->r15);
    // 0x800B926C: subu        $s0, $t8, $t2
    ctx->r16 = SUB32(ctx->r24, ctx->r10);
    // 0x800B9270: multu       $s7, $t1
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9274: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800B9278: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800B927C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B9280: sra         $t8, $t1, 1
    ctx->r24 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800B9284: addiu       $s0, $s0, -0x5458
    ctx->r16 = ADD32(ctx->r16, -0X5458);
    // 0x800B9288: mflo        $t9
    ctx->r25 = lo;
    // 0x800B928C: subu        $t6, $a2, $t9
    ctx->r14 = SUB32(ctx->r6, ctx->r25);
    // 0x800B9290: beq         $at, $zero, L_800B92A0
    if (ctx->r1 == 0) {
        // 0x800B9294: subu        $a2, $t6, $t4
        ctx->r6 = SUB32(ctx->r14, ctx->r12);
            goto L_800B92A0;
    }
    // 0x800B9294: subu        $a2, $t6, $t4
    ctx->r6 = SUB32(ctx->r14, ctx->r12);
    // 0x800B9298: b           L_800B92A4
    // 0x800B929C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_800B92A4;
    // 0x800B929C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_800B92A0:
    // 0x800B92A0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_800B92A4:
    // 0x800B92A4: slt         $at, $t8, $a2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800B92A8: beq         $at, $zero, L_800B92B8
    if (ctx->r1 == 0) {
        // 0x800B92AC: nop
    
            goto L_800B92B8;
    }
    // 0x800B92AC: nop

    // 0x800B92B0: b           L_800B92B8
    // 0x800B92B4: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
        goto L_800B92B8;
    // 0x800B92B4: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
L_800B92B8:
    // 0x800B92B8: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x800B92BC: nop

    // 0x800B92C0: sra         $v0, $a0, 1
    ctx->r2 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800B92C4: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800B92C8: subu        $v1, $v1, $t9
    ctx->r3 = SUB32(ctx->r3, ctx->r25);
    // 0x800B92CC: bgez        $v1, L_800B92E0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B92D0: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_800B92E0;
    }
    // 0x800B92D0: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
L_800B92D4:
    // 0x800B92D4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B92D8: bltz        $v1, L_800B92D4
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B92DC: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800B92D4;
    }
    // 0x800B92DC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_800B92E0:
    // 0x800B92E0: subu        $s4, $s4, $t6
    ctx->r20 = SUB32(ctx->r20, ctx->r14);
    // 0x800B92E4: bgez        $s4, L_800B92F8
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800B92E8: nop
    
            goto L_800B92F8;
    }
    // 0x800B92E8: nop

L_800B92EC:
    // 0x800B92EC: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x800B92F0: bltz        $s4, L_800B92EC
    if (SIGNED(ctx->r20) < 0) {
        // 0x800B92F4: addiu       $s7, $s7, -0x1
        ctx->r23 = ADD32(ctx->r23, -0X1);
            goto L_800B92EC;
    }
    // 0x800B92F4: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
L_800B92F8:
    // 0x800B92F8: blez        $a0, L_800B9708
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B92FC: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_800B9708;
    }
    // 0x800B92FC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B9300: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800B9304: addiu       $fp, $fp, -0x5968
    ctx->r30 = ADD32(ctx->r30, -0X5968);
    // 0x800B9308: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
L_800B930C:
    // 0x800B930C: bltz        $s7, L_800B9534
    if (SIGNED(ctx->r23) < 0) {
        // 0x800B9310: sw          $v1, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r3;
            goto L_800B9534;
    }
    // 0x800B9310: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800B9314: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B9318: lw          $t7, -0x5964($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5964);
    // 0x800B931C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800B9320: slt         $at, $s7, $t7
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B9324: beq         $at, $zero, L_800B9534
    if (ctx->r1 == 0) {
        // 0x800B9328: nop
    
            goto L_800B9534;
    }
    // 0x800B9328: nop

    // 0x800B932C: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B9330: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800B9334: multu       $s7, $t8
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9338: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x800B933C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B9340: mflo        $t9
    ctx->r25 = lo;
    // 0x800B9344: addu        $t2, $t9, $s3
    ctx->r10 = ADD32(ctx->r25, ctx->r19);
    // 0x800B9348: blez        $a0, L_800B9534
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B934C: nop
    
            goto L_800B9534;
    }
    // 0x800B934C: nop

L_800B9350:
    // 0x800B9350: bltz        $s3, L_800B9508
    if (SIGNED(ctx->r19) < 0) {
        // 0x800B9354: nop
    
            goto L_800B9508;
    }
    // 0x800B9354: nop

    // 0x800B9358: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x800B935C: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x800B9360: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B9364: beq         $at, $zero, L_800B9508
    if (ctx->r1 == 0) {
        // 0x800B9368: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800B9508;
    }
    // 0x800B9368: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B936C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B9370: lw          $t8, -0x5958($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5958);
    // 0x800B9374: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B9378: sllv        $t6, $t9, $s3
    ctx->r14 = S32(ctx->r25 << (ctx->r19 & 31));
    // 0x800B937C: and         $t7, $t8, $t6
    ctx->r15 = ctx->r24 & ctx->r14;
    // 0x800B9380: beq         $t7, $zero, L_800B9508
    if (ctx->r15 == 0) {
        // 0x800B9384: nop
    
            goto L_800B9508;
    }
    // 0x800B9384: nop

    // 0x800B9388: multu       $s6, $a0
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B938C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B9390: lw          $t9, 0x3664($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3664);
    // 0x800B9394: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x800B9398: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B939C: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x800B93A0: lw          $t6, 0x3670($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3670);
    // 0x800B93A4: addu        $t4, $t5, $s4
    ctx->r12 = ADD32(ctx->r13, ctx->r20);
    // 0x800B93A8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800B93AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B93B0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B93B4: mflo        $t7
    ctx->r15 = lo;
    // 0x800B93B8: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800B93BC: sll         $t7, $s5, 1
    ctx->r15 = S32(ctx->r21 << 1);
    // 0x800B93C0: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800B93C4: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800B93C8: lh          $t9, 0x0($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X0);
    // 0x800B93CC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800B93D0: sllv        $t8, $t9, $t4
    ctx->r24 = S32(ctx->r25 << (ctx->r12 & 31));
    // 0x800B93D4: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800B93D8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800B93DC: lw          $t0, -0x5960($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5960);
    // 0x800B93E0: nop

    // 0x800B93E4: blez        $t0, L_800B9508
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B93E8: nop
    
            goto L_800B9508;
    }
    // 0x800B93E8: nop

    // 0x800B93EC: lw          $t1, 0x3668($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3668);
    // 0x800B93F0: nop

L_800B93F4:
    // 0x800B93F4: multu       $v0, $ra
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B93F8: mflo        $t9
    ctx->r25 = lo;
    // 0x800B93FC: addu        $a2, $t1, $t9
    ctx->r6 = ADD32(ctx->r9, ctx->r25);
    // 0x800B9400: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x800B9404: nop

    // 0x800B9408: bne         $t2, $t7, L_800B94F8
    if (ctx->r10 != ctx->r15) {
        // 0x800B940C: nop
    
            goto L_800B94F8;
    }
    // 0x800B940C: nop

    // 0x800B9410: multu       $a3, $s1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9414: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800B9418: sra         $t6, $t4, 3
    ctx->r14 = S32(SIGNED(ctx->r12) >> 3);
    // 0x800B941C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800B9420: mflo        $t8
    ctx->r24 = lo;
    // 0x800B9424: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x800B9428: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B942C: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9430: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
    // 0x800B9434: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9438: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800B943C: lh          $t8, 0x12($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X12);
    // 0x800B9440: beq         $t5, $zero, L_800B9490
    if (ctx->r13 == 0) {
        // 0x800B9444: sh          $t8, 0x4($v1)
        MEM_H(0X4, ctx->r3) = ctx->r24;
            goto L_800B9490;
    }
    // 0x800B9444: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x800B9448: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x800B944C: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x800B9450: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x800B9454: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x800B9458: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x800B945C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800B9460: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x800B9464: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800B9468: nop

    // 0x800B946C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B9470: bne         $at, $zero, L_800B9490
    if (ctx->r1 != 0) {
        // 0x800B9474: subu        $t6, $v0, $a0
        ctx->r14 = SUB32(ctx->r2, ctx->r4);
            goto L_800B9490;
    }
    // 0x800B9474: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
L_800B9478:
    // 0x800B9478: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x800B947C: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800B9480: nop

    // 0x800B9484: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B9488: beq         $at, $zero, L_800B9478
    if (ctx->r1 == 0) {
        // 0x800B948C: subu        $t6, $v0, $a0
        ctx->r14 = SUB32(ctx->r2, ctx->r4);
            goto L_800B9478;
    }
    // 0x800B948C: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
L_800B9490:
    // 0x800B9490: lh          $t9, 0x10($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X10);
    // 0x800B9494: beq         $s4, $zero, L_800B94F4
    if (ctx->r20 == 0) {
        // 0x800B9498: sh          $t9, 0x6($v1)
        MEM_H(0X6, ctx->r3) = ctx->r25;
            goto L_800B94F4;
    }
    // 0x800B9498: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
    // 0x800B949C: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x800B94A0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B94A4: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x800B94A8: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800B94AC: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B94B0: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x800B94B4: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x800B94B8: mflo        $t9
    ctx->r25 = lo;
    // 0x800B94BC: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800B94C0: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800B94C4: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x800B94C8: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x800B94CC: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800B94D0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B94D4: bne         $at, $zero, L_800B94F4
    if (ctx->r1 != 0) {
        // 0x800B94D8: subu        $t9, $v0, $a0
        ctx->r25 = SUB32(ctx->r2, ctx->r4);
            goto L_800B94F4;
    }
    // 0x800B94D8: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
L_800B94DC:
    // 0x800B94DC: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
    // 0x800B94E0: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x800B94E4: nop

    // 0x800B94E8: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B94EC: beq         $at, $zero, L_800B94DC
    if (ctx->r1 == 0) {
        // 0x800B94F0: subu        $t9, $v0, $a0
        ctx->r25 = SUB32(ctx->r2, ctx->r4);
            goto L_800B94DC;
    }
    // 0x800B94F0: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
L_800B94F4:
    // 0x800B94F4: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_800B94F8:
    // 0x800B94F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B94FC: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B9500: bne         $at, $zero, L_800B93F4
    if (ctx->r1 != 0) {
        // 0x800B9504: nop
    
            goto L_800B93F4;
    }
    // 0x800B9504: nop

L_800B9508:
    // 0x800B9508: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x800B950C: slti        $at, $t5, 0x9
    ctx->r1 = SIGNED(ctx->r13) < 0X9 ? 1 : 0;
    // 0x800B9510: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x800B9514: bne         $at, $zero, L_800B9528
    if (ctx->r1 != 0) {
        // 0x800B9518: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800B9528;
    }
    // 0x800B9518: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800B951C: addiu       $t5, $t5, -0x10
    ctx->r13 = ADD32(ctx->r13, -0X10);
    // 0x800B9520: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B9524: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_800B9528:
    // 0x800B9528: slt         $at, $s5, $a0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B952C: bne         $at, $zero, L_800B9350
    if (ctx->r1 != 0) {
        // 0x800B9530: nop
    
            goto L_800B9350;
    }
    // 0x800B9530: nop

L_800B9534:
    // 0x800B9534: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // 0x800B9538: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800B953C: slti        $at, $s4, 0x11
    ctx->r1 = SIGNED(ctx->r20) < 0X11 ? 1 : 0;
    // 0x800B9540: bne         $at, $zero, L_800B9550
    if (ctx->r1 != 0) {
        // 0x800B9544: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800B9550;
    }
    // 0x800B9544: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800B9548: addiu       $s4, $s4, -0x20
    ctx->r20 = ADD32(ctx->r20, -0X20);
    // 0x800B954C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_800B9550:
    // 0x800B9550: slt         $at, $s6, $a0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B9554: bne         $at, $zero, L_800B930C
    if (ctx->r1 != 0) {
        // 0x800B9558: nop
    
            goto L_800B930C;
    }
    // 0x800B9558: nop

    // 0x800B955C: b           L_800B970C
    // 0x800B9560: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
        goto L_800B970C;
    // 0x800B9560: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
L_800B9564:
    // 0x800B9564: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x800B9568: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B956C: sra         $v0, $a0, 1
    ctx->r2 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800B9570: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x800B9574: blez        $a0, L_800B9708
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B9578: subu        $s7, $s7, $v0
        ctx->r23 = SUB32(ctx->r23, ctx->r2);
            goto L_800B9708;
    }
    // 0x800B9578: subu        $s7, $s7, $v0
    ctx->r23 = SUB32(ctx->r23, ctx->r2);
    // 0x800B957C: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800B9580: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800B9584: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B9588: addiu       $s0, $s0, -0x5458
    ctx->r16 = ADD32(ctx->r16, -0X5458);
    // 0x800B958C: addiu       $s2, $s2, 0x370C
    ctx->r18 = ADD32(ctx->r18, 0X370C);
    // 0x800B9590: addiu       $fp, $fp, -0x5968
    ctx->r30 = ADD32(ctx->r30, -0X5968);
    // 0x800B9594: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800B9598: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x800B959C: addiu       $ra, $zero, 0x1C
    ctx->r31 = ADD32(0, 0X1C);
L_800B95A0:
    // 0x800B95A0: bltz        $s7, L_800B96F8
    if (SIGNED(ctx->r23) < 0) {
        // 0x800B95A4: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800B96F8;
    }
    // 0x800B95A4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B95A8: lw          $t8, -0x5964($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5964);
    // 0x800B95AC: nop

    // 0x800B95B0: slt         $at, $s7, $t8
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B95B4: beq         $at, $zero, L_800B96F8
    if (ctx->r1 == 0) {
        // 0x800B95B8: nop
    
            goto L_800B96F8;
    }
    // 0x800B95B8: nop

    // 0x800B95BC: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800B95C0: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800B95C4: multu       $s7, $t7
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B95C8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B95CC: mflo        $t9
    ctx->r25 = lo;
    // 0x800B95D0: addu        $t2, $t9, $s3
    ctx->r10 = ADD32(ctx->r25, ctx->r19);
    // 0x800B95D4: blez        $a0, L_800B96F8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B95D8: nop
    
            goto L_800B96F8;
    }
    // 0x800B95D8: nop

L_800B95DC:
    // 0x800B95DC: bltz        $s3, L_800B96E0
    if (SIGNED(ctx->r19) < 0) {
        // 0x800B95E0: nop
    
            goto L_800B96E0;
    }
    // 0x800B95E0: nop

    // 0x800B95E4: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B95E8: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x800B95EC: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B95F0: beq         $at, $zero, L_800B96E0
    if (ctx->r1 == 0) {
        // 0x800B95F4: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_800B96E0;
    }
    // 0x800B95F4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B95F8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800B95FC: lw          $t9, -0x5958($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5958);
    // 0x800B9600: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B9604: sllv        $t8, $t6, $s3
    ctx->r24 = S32(ctx->r14 << (ctx->r19 & 31));
    // 0x800B9608: and         $t7, $t9, $t8
    ctx->r15 = ctx->r25 & ctx->r24;
    // 0x800B960C: beq         $t7, $zero, L_800B96E0
    if (ctx->r15 == 0) {
        // 0x800B9610: nop
    
            goto L_800B96E0;
    }
    // 0x800B9610: nop

    // 0x800B9614: multu       $s6, $a0
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9618: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B961C: lw          $t6, 0x3670($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3670);
    // 0x800B9620: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800B9624: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B9628: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B962C: mflo        $t9
    ctx->r25 = lo;
    // 0x800B9630: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800B9634: sll         $t9, $s5, 1
    ctx->r25 = S32(ctx->r21 << 1);
    // 0x800B9638: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800B963C: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800B9640: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B9644: lw          $t7, 0x3664($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3664);
    // 0x800B9648: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x800B964C: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x800B9650: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800B9654: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800B9658: lw          $t0, -0x5960($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5960);
    // 0x800B965C: nop

    // 0x800B9660: blez        $t0, L_800B96E0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B9664: nop
    
            goto L_800B96E0;
    }
    // 0x800B9664: nop

    // 0x800B9668: lw          $t1, 0x3668($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3668);
    // 0x800B966C: nop

L_800B9670:
    // 0x800B9670: multu       $v0, $ra
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9674: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9678: addu        $a2, $t1, $t7
    ctx->r6 = ADD32(ctx->r9, ctx->r15);
    // 0x800B967C: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x800B9680: nop

    // 0x800B9684: bne         $t2, $t9, L_800B96D0
    if (ctx->r10 != ctx->r25) {
        // 0x800B9688: nop
    
            goto L_800B96D0;
    }
    // 0x800B9688: nop

    // 0x800B968C: multu       $a3, $s1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9690: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800B9694: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800B9698: mflo        $t8
    ctx->r24 = lo;
    // 0x800B969C: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x800B96A0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B96A4: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B96A8: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x800B96AC: lh          $t6, 0x12($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X12);
    // 0x800B96B0: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x800B96B4: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x800B96B8: lh          $t7, 0x10($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X10);
    // 0x800B96BC: nop

    // 0x800B96C0: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x800B96C4: mflo        $t8
    ctx->r24 = lo;
    // 0x800B96C8: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800B96CC: nop

L_800B96D0:
    // 0x800B96D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B96D4: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B96D8: bne         $at, $zero, L_800B9670
    if (ctx->r1 != 0) {
        // 0x800B96DC: nop
    
            goto L_800B9670;
    }
    // 0x800B96DC: nop

L_800B96E0:
    // 0x800B96E0: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x800B96E4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800B96E8: slt         $at, $s5, $a0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B96EC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B96F0: bne         $at, $zero, L_800B95DC
    if (ctx->r1 != 0) {
        // 0x800B96F4: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_800B95DC;
    }
    // 0x800B96F4: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_800B96F8:
    // 0x800B96F8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800B96FC: slt         $at, $s6, $a0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B9700: bne         $at, $zero, L_800B95A0
    if (ctx->r1 != 0) {
        // 0x800B9704: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_800B95A0;
    }
    // 0x800B9704: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_800B9708:
    // 0x800B9708: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
L_800B970C:
    // 0x800B970C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800B9710: jal         0x800BA7A8
    // 0x800B9714: nop

    func_800BA288(rdram, ctx);
        goto after_0;
    // 0x800B9714: nop

    after_0:
    // 0x800B9718: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800B971C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B9720: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9724: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B9728: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B972C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B9730: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9734: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800B9738: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800B973C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800B9740: jr          $ra
    // 0x800B9744: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800B9744: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void waves_block_hq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9748: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B974C: lw          $a1, -0x5960($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5960);
    // 0x800B9750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B9754: blez        $a1, L_800B97A4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800B9758: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800B97A4;
    }
    // 0x800B9758: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B975C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800B9760: lw          $a2, 0x3668($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3668);
    // 0x800B9764: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x800B9768: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800B976C: nop

    // 0x800B9770: beq         $a0, $t6, L_800B97A4
    if (ctx->r4 == ctx->r14) {
        // 0x800B9774: nop
    
            goto L_800B97A4;
    }
    // 0x800B9774: nop

L_800B9778:
    // 0x800B9778: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B977C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800B9780: beq         $at, $zero, L_800B97A4
    if (ctx->r1 == 0) {
        // 0x800B9784: nop
    
            goto L_800B97A4;
    }
    // 0x800B9784: nop

    // 0x800B9788: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B978C: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9790: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x800B9794: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B9798: nop

    // 0x800B979C: bne         $a0, $t9, L_800B9778
    if (ctx->r4 != ctx->r25) {
        // 0x800B97A0: nop
    
            goto L_800B9778;
    }
    // 0x800B97A0: nop

L_800B97A4:
    // 0x800B97A4: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x800B97A8: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B97AC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B97B0: lw          $t0, 0x3668($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3668);
    // 0x800B97B4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B97B8: lw          $t5, 0x3664($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3664);
    // 0x800B97BC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800B97C0: addiu       $a1, $a1, 0x366C
    ctx->r5 = ADD32(ctx->r5, 0X366C);
    // 0x800B97C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B97C8: mflo        $t1
    ctx->r9 = lo;
    // 0x800B97CC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B97D0: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x800B97D4: nop

    // 0x800B97D8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B97DC: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800B97E0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B97E4: nop

    // 0x800B97E8: beq         $t7, $zero, L_800B980C
    if (ctx->r15 == 0) {
        // 0x800B97EC: nop
    
            goto L_800B980C;
    }
    // 0x800B97EC: nop

    // 0x800B97F0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800B97F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B97F8: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800B97FC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B9800: sh          $v0, -0x5858($at)
    MEM_H(-0X5858, ctx->r1) = ctx->r2;
    // 0x800B9804: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x800B9808: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_800B980C:
    // 0x800B980C: jr          $ra
    // 0x800B9810: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B9810: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800B92F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9814: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800B9818: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800B981C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800B9820: addiu       $s5, $s5, -0x5A78
    ctx->r21 = ADD32(ctx->r21, -0X5A78);
    // 0x800B9824: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800B9828: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B982C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800B9830: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9834: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B9838: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800B983C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800B9840: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B9844: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B9848: lwc1        $f6, 0x44($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X44);
    // 0x800B984C: lw          $t8, 0x3668($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3668);
    // 0x800B9850: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800B9854: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B9858: lh          $t2, -0x5458($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X5458);
    // 0x800B985C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B9860: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B9864: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800B9868: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800B986C: mflo        $t1
    ctx->r9 = lo;
    // 0x800B9870: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9874: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B9878: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800B987C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800B9880: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800B9884: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800B9888: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800B988C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800B9890: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800B9894: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800B9898: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B989C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B98A0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B98A4: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x800B98A8: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800B98AC: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x800B98B0: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x800B98B4: beq         $t2, $at, L_800B9C88
    if (ctx->r10 == ctx->r1) {
        // 0x800B98B8: div.s       $f22, $f8, $f10
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
            goto L_800B9C88;
    }
    // 0x800B98B8: div.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B98BC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B98C0: addiu       $t3, $t3, -0x5458
    ctx->r11 = ADD32(ctx->r11, -0X5458);
    // 0x800B98C4: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800B98C8: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x800B98CC: addiu       $s6, $s6, -0x5458
    ctx->r22 = ADD32(ctx->r22, -0X5458);
    // 0x800B98D0: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
L_800B98D4:
    // 0x800B98D4: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x800B98D8: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x800B98DC: bne         $t4, $v0, L_800B9C78
    if (ctx->r12 != ctx->r2) {
        // 0x800B98E0: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800B9C78;
    }
    // 0x800B98E0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B98E4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B98E8: lw          $t1, -0x5A28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5A28);
    // 0x800B98EC: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    // 0x800B98F0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800B98F4: lw          $t5, 0x3664($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3664);
    // 0x800B98F8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B98FC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B9900: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x800B9904: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800B9908: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B990C: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x800B9910: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x800B9914: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B9918: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800B991C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x800B9920: lw          $a3, 0x3674($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3674);
    // 0x800B9924: lw          $a2, 0x3600($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3600);
    // 0x800B9928: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x800B992C: beq         $a1, $zero, L_800B9980
    if (ctx->r5 == 0) {
        // 0x800B9930: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_800B9980;
    }
    // 0x800B9930: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800B9934: lh          $v0, 0x2($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X2);
    // 0x800B9938: nop

    // 0x800B993C: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800B9940: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9944: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x800B9948: sra         $t4, $t2, 1
    ctx->r12 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800B994C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800B9950: srlv        $t5, $a0, $t7
    ctx->r13 = S32(U32(ctx->r4) >> (ctx->r15 & 31));
    // 0x800B9954: andi        $t8, $t5, 0xFF
    ctx->r24 = ctx->r13 & 0XFF;
    // 0x800B9958: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B995C: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x800B9960: mflo        $t3
    ctx->r11 = lo;
    // 0x800B9964: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x800B9968: nop

    // 0x800B996C: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9970: mflo        $t6
    ctx->r14 = lo;
    // 0x800B9974: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
    // 0x800B9978: b           L_800B9998
    // 0x800B997C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
        goto L_800B9998;
    // 0x800B997C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
L_800B9980:
    // 0x800B9980: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x800B9984: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x800B9988: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
    // 0x800B998C: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
    // 0x800B9990: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x800B9994: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
L_800B9998:
    // 0x800B9998: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x800B999C: lh          $a0, 0x6($s6)
    ctx->r4 = MEM_H(ctx->r22, 0X6);
    // 0x800B99A0: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B99A4: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800B99A8: addu        $t6, $a3, $t4
    ctx->r14 = ADD32(ctx->r7, ctx->r12);
    // 0x800B99AC: mflo        $t1
    ctx->r9 = lo;
    // 0x800B99B0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800B99B4: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x800B99B8: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800B99BC: addu        $t2, $a2, $t3
    ctx->r10 = ADD32(ctx->r6, ctx->r11);
    // 0x800B99C0: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x800B99C4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800B99C8: bltz        $v1, L_800B9C78
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B99CC: sw          $t7, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->r15;
            goto L_800B9C78;
    }
    // 0x800B99CC: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x800B99D0: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x800B99D4: nop

L_800B99D8:
    // 0x800B99D8: multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B99DC: lh          $s1, 0x4($s6)
    ctx->r17 = MEM_H(ctx->r22, 0X4);
    // 0x800B99E0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B99E4: addiu       $t3, $t3, 0x35DC
    ctx->r11 = ADD32(ctx->r11, 0X35DC);
    // 0x800B99E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B99EC: sll         $s4, $s7, 2
    ctx->r20 = S32(ctx->r23 << 2);
    // 0x800B99F0: mflo        $t5
    ctx->r13 = lo;
    // 0x800B99F4: addu        $s2, $t5, $s1
    ctx->r18 = ADD32(ctx->r13, ctx->r17);
    // 0x800B99F8: bltz        $v1, L_800B9C34
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B99FC: sll         $t5, $s7, 2
        ctx->r13 = S32(ctx->r23 << 2);
            goto L_800B9C34;
    }
    // 0x800B99FC: sll         $t5, $s7, 2
    ctx->r13 = S32(ctx->r23 << 2);
    // 0x800B9A00: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x800B9A04: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800B9A08: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x800B9A0C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800B9A10: addu        $t5, $t5, $s7
    ctx->r13 = ADD32(ctx->r13, ctx->r23);
    // 0x800B9A14: sra         $t4, $t9, 1
    ctx->r12 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800B9A18: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800B9A1C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800B9A20: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x800B9A24: addu        $a3, $t1, $t3
    ctx->r7 = ADD32(ctx->r9, ctx->r11);
    // 0x800B9A28: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
    // 0x800B9A2C: addu        $t0, $t2, $t6
    ctx->r8 = ADD32(ctx->r10, ctx->r14);
    // 0x800B9A30: addu        $s0, $t7, $t5
    ctx->r16 = ADD32(ctx->r15, ctx->r13);
L_800B9A34:
    // 0x800B9A34: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B9A38: lw          $t8, 0x35D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X35D4);
    // 0x800B9A3C: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x800B9A40: addu        $v1, $t8, $t1
    ctx->r3 = ADD32(ctx->r24, ctx->r9);
    // 0x800B9A44: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B9A48: lw          $v0, 0x35D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X35D0);
    // 0x800B9A4C: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x800B9A50: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800B9A54: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x800B9A58: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x800B9A5C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800B9A60: addu        $t4, $v0, $t9
    ctx->r12 = ADD32(ctx->r2, ctx->r25);
    // 0x800B9A64: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800B9A68: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800B9A6C: lwc1        $f6, 0x40($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X40);
    // 0x800B9A70: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B9A74: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B9A78: lw          $t5, 0x3718($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3718);
    // 0x800B9A7C: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B9A80: blez        $t5, L_800B9AB8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800B9A84: nop
    
            goto L_800B9AB8;
    }
    // 0x800B9A84: nop

    // 0x800B9A88: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x800B9A8C: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x800B9A90: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x800B9A94: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x800B9A98: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800B9A9C: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800B9AA0: addu        $a1, $s3, $t8
    ctx->r5 = ADD32(ctx->r19, ctx->r24);
    // 0x800B9AA4: jal         0x800BF4E4
    // 0x800B9AA8: addu        $a2, $t1, $t3
    ctx->r6 = ADD32(ctx->r9, ctx->r11);
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800B9AA8: addu        $a2, $t1, $t3
    ctx->r6 = ADD32(ctx->r9, ctx->r11);
    after_0:
    // 0x800B9AAC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800B9AB0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800B9AB4: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_800B9AB8:
    // 0x800B9AB8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B9ABC: lw          $t2, 0x3708($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3708);
    // 0x800B9AC0: lw          $v1, 0x8($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X8);
    // 0x800B9AC4: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800B9AC8: addu        $t6, $v1, $t2
    ctx->r14 = ADD32(ctx->r3, ctx->r10);
    // 0x800B9ACC: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x800B9AD0: addu        $t4, $t9, $s4
    ctx->r12 = ADD32(ctx->r25, ctx->r20);
    // 0x800B9AD4: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800B9AD8: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800B9ADC: slti        $at, $t7, 0xFF
    ctx->r1 = SIGNED(ctx->r15) < 0XFF ? 1 : 0;
    // 0x800B9AE0: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x800B9AE4: mul.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800B9AE8: sw          $t5, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r13;
    // 0x800B9AEC: beq         $at, $zero, L_800B9B10
    if (ctx->r1 == 0) {
        // 0x800B9AF0: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800B9B10;
    }
    // 0x800B9AF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800B9AF4: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B9AF8: lwc1        $f10, 0x44($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X44);
    // 0x800B9AFC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B9B00: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800B9B04: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B9B08: mul.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800B9B0C: nop

L_800B9B10:
    // 0x800B9B10: lwc1        $f8, 0x48($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X48);
    // 0x800B9B14: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B9B18: mul.s       $f16, $f20, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800B9B1C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800B9B20: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B9B24: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B9B28: nop

    // 0x800B9B2C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B9B30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B9B34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B9B38: nop

    // 0x800B9B3C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B9B40: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800B9B44: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B9B48: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800B9B4C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800B9B50: bne         $at, $zero, L_800B9B60
    if (ctx->r1 != 0) {
        // 0x800B9B54: nop
    
            goto L_800B9B60;
    }
    // 0x800B9B54: nop

    // 0x800B9B58: b           L_800B9B6C
    // 0x800B9B5C: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
        goto L_800B9B6C;
    // 0x800B9B5C: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
L_800B9B60:
    // 0x800B9B60: bgez        $v0, L_800B9B6C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B9B64: nop
    
            goto L_800B9B6C;
    }
    // 0x800B9B64: nop

    // 0x800B9B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B9B6C:
    // 0x800B9B6C: lh          $t9, 0x2($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X2);
    // 0x800B9B70: subu        $t3, $fp, $v0
    ctx->r11 = SUB32(ctx->r30, ctx->r2);
    // 0x800B9B74: addu        $t4, $t0, $t9
    ctx->r12 = ADD32(ctx->r8, ctx->r25);
    // 0x800B9B78: lbu         $t2, 0x14($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X14);
    // 0x800B9B7C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B9B80: multu       $t3, $t2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9B84: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B9B88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B9B8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B9B90: nop

    // 0x800B9B94: cvt.w.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    ctx->f10.u32l = CVT_W_S(ctx->f20.fl);
    // 0x800B9B98: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800B9B9C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B9BA0: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800B9BA4: mflo        $t6
    ctx->r14 = lo;
    // 0x800B9BA8: sra         $t7, $t6, 7
    ctx->r15 = S32(SIGNED(ctx->r14) >> 7);
    // 0x800B9BAC: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800B9BB0: slti        $at, $v0, 0xC0
    ctx->r1 = SIGNED(ctx->r2) < 0XC0 ? 1 : 0;
    // 0x800B9BB4: beq         $at, $zero, L_800B9BC4
    if (ctx->r1 == 0) {
        // 0x800B9BB8: subu        $v1, $fp, $v0
        ctx->r3 = SUB32(ctx->r30, ctx->r2);
            goto L_800B9BC4;
    }
    // 0x800B9BB8: subu        $v1, $fp, $v0
    ctx->r3 = SUB32(ctx->r30, ctx->r2);
    // 0x800B9BBC: b           L_800B9BCC
    // 0x800B9BC0: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
        goto L_800B9BCC;
    // 0x800B9BC0: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
L_800B9BC4:
    // 0x800B9BC4: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800B9BC8: andi        $v1, $t1, 0xFF
    ctx->r3 = ctx->r9 & 0XFF;
L_800B9BCC:
    // 0x800B9BCC: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x800B9BD0: sb          $v1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r3;
    // 0x800B9BD4: sb          $v1, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r3;
    // 0x800B9BD8: beq         $at, $zero, L_800B9BF0
    if (ctx->r1 == 0) {
        // 0x800B9BDC: sb          $v1, 0x8($s0)
        MEM_B(0X8, ctx->r16) = ctx->r3;
            goto L_800B9BF0;
    }
    // 0x800B9BDC: sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // 0x800B9BE0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800B9BE4: andi        $t4, $v1, 0xFF
    ctx->r12 = ctx->r3 & 0XFF;
    // 0x800B9BE8: b           L_800B9BF4
    // 0x800B9BEC: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
        goto L_800B9BF4;
    // 0x800B9BEC: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_800B9BF0:
    // 0x800B9BF0: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
L_800B9BF4:
    // 0x800B9BF4: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // 0x800B9BF8: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x800B9BFC: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x800B9C00: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B9C04: bne         $at, $zero, L_800B9C14
    if (ctx->r1 != 0) {
        // 0x800B9C08: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800B9C14;
    }
    // 0x800B9C08: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B9C0C: subu        $s1, $s1, $v0
    ctx->r17 = SUB32(ctx->r17, ctx->r2);
    // 0x800B9C10: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
L_800B9C14:
    // 0x800B9C14: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800B9C18: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B9C1C: slt         $at, $v1, $s3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800B9C20: beq         $at, $zero, L_800B9A34
    if (ctx->r1 == 0) {
        // 0x800B9C24: nop
    
            goto L_800B9A34;
    }
    // 0x800B9C24: nop

    // 0x800B9C28: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x800B9C2C: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800B9C30: nop

L_800B9C34:
    // 0x800B9C34: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B9C38: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B9C3C: bne         $at, $zero, L_800B9C48
    if (ctx->r1 != 0) {
        // 0x800B9C40: nop
    
            goto L_800B9C48;
    }
    // 0x800B9C40: nop

    // 0x800B9C44: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
L_800B9C48:
    // 0x800B9C48: beq         $a1, $zero, L_800B9C64
    if (ctx->r5 == 0) {
        // 0x800B9C4C: lw          $t6, 0xAC($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XAC);
            goto L_800B9C64;
    }
    // 0x800B9C4C: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800B9C50: lw          $t3, 0x8($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X8);
    // 0x800B9C54: nop

    // 0x800B9C58: addu        $t2, $t3, $v1
    ctx->r10 = ADD32(ctx->r11, ctx->r3);
    // 0x800B9C5C: sw          $t2, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r10;
    // 0x800B9C60: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
L_800B9C64:
    // 0x800B9C64: nop

    // 0x800B9C68: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B9C6C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B9C70: beq         $at, $zero, L_800B99D8
    if (ctx->r1 == 0) {
        // 0x800B9C74: sw          $t7, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r15;
            goto L_800B99D8;
    }
    // 0x800B9C74: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
L_800B9C78:
    // 0x800B9C78: lh          $v0, 0xC($s6)
    ctx->r2 = MEM_H(ctx->r22, 0XC);
    // 0x800B9C7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9C80: bne         $v0, $at, L_800B98D4
    if (ctx->r2 != ctx->r1) {
        // 0x800B9C84: addiu       $s6, $s6, 0xC
        ctx->r22 = ADD32(ctx->r22, 0XC);
            goto L_800B98D4;
    }
    // 0x800B9C84: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
L_800B9C88:
    // 0x800B9C88: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800B9C8C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B9C90: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B9C94: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800B9C98: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B9C9C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B9CA0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9CA4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800B9CA8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800B9CAC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800B9CB0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800B9CB4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800B9CB8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800B9CBC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800B9CC0: jr          $ra
    // 0x800B9CC4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800B9CC4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_800B97A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9CC8: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800B9CCC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800B9CD0: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800B9CD4: addiu       $s5, $s5, -0x5A78
    ctx->r21 = ADD32(ctx->r21, -0X5A78);
    // 0x800B9CD8: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x800B9CDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B9CE0: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800B9CE4: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9CE8: lwc1        $f0, -0x5A20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5A20);
    // 0x800B9CEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B9CF0: lwc1        $f2, -0x5A24($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5A24);
    // 0x800B9CF4: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B9CF8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800B9CFC: add.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800B9D00: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x800B9D04: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800B9D08: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800B9D0C: sub.s       $f26, $f4, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f26.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800B9D10: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x800B9D14: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B9D18: lw          $t9, 0x3668($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3668);
    // 0x800B9D1C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800B9D20: c.le.s      $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f26.fl <= ctx->f22.fl;
    // 0x800B9D24: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B9D28: mflo        $t6
    ctx->r14 = lo;
    // 0x800B9D2C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800B9D30: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800B9D34: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800B9D38: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800B9D3C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800B9D40: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800B9D44: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800B9D48: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800B9D4C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800B9D50: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800B9D54: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800B9D58: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x800B9D5C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800B9D60: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800B9D64: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800B9D68: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B9D6C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B9D70: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800B9D74: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x800B9D78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B9D7C: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
    // 0x800B9D80: bc1f        L_800B9D98
    if (!c1cs) {
        // 0x800B9D84: sw          $t1, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r9;
            goto L_800B9D98;
    }
    // 0x800B9D84: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x800B9D88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B9D8C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800B9D90: b           L_800B9DA8
    // 0x800B9D94: mov.s       $f28, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    ctx->f28.fl = ctx->f22.fl;
        goto L_800B9DA8;
    // 0x800B9D94: mov.s       $f28, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    ctx->f28.fl = ctx->f22.fl;
L_800B9D98:
    // 0x800B9D98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B9D9C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800B9DA0: nop

    // 0x800B9DA4: div.s       $f28, $f24, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = DIV_S(ctx->f24.fl, ctx->f26.fl);
L_800B9DA8:
    // 0x800B9DA8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B9DAC: lh          $t2, -0x5458($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X5458);
    // 0x800B9DB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9DB4: beq         $t2, $at, L_800BA0E0
    if (ctx->r10 == ctx->r1) {
        // 0x800B9DB8: mov.s       $f26, $f12
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
            goto L_800BA0E0;
    }
    // 0x800B9DB8: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    // 0x800B9DBC: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x800B9DC0: subu        $t3, $t3, $a3
    ctx->r11 = SUB32(ctx->r11, ctx->r7);
    // 0x800B9DC4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B9DC8: addiu       $t4, $t4, -0x5458
    ctx->r12 = ADD32(ctx->r12, -0X5458);
    // 0x800B9DCC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B9DD0: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x800B9DD4: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x800B9DD8: nop

L_800B9DDC:
    // 0x800B9DDC: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800B9DE0: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800B9DE4: bne         $t5, $v1, L_800BA0D0
    if (ctx->r13 != ctx->r3) {
        // 0x800B9DE8: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800BA0D0;
    }
    // 0x800B9DE8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B9DEC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B9DF0: lw          $t2, -0x5A28($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5A28);
    // 0x800B9DF4: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x800B9DF8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800B9DFC: lw          $t6, 0x3664($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3664);
    // 0x800B9E00: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B9E04: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800B9E08: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x800B9E0C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B9E10: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B9E14: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x800B9E18: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800B9E1C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B9E20: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x800B9E24: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800B9E28: lw          $t0, 0x3674($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3674);
    // 0x800B9E2C: lw          $a3, 0x3600($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3600);
    // 0x800B9E30: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800B9E34: beq         $a1, $zero, L_800B9E88
    if (ctx->r5 == 0) {
        // 0x800B9E38: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_800B9E88;
    }
    // 0x800B9E38: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B9E3C: lh          $v1, 0x2($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X2);
    // 0x800B9E40: nop

    // 0x800B9E44: andi        $t2, $v1, 0x1
    ctx->r10 = ctx->r3 & 0X1;
    // 0x800B9E48: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9E4C: andi        $t3, $v1, 0x2
    ctx->r11 = ctx->r3 & 0X2;
    // 0x800B9E50: sra         $t5, $t3, 1
    ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800B9E54: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800B9E58: srlv        $t6, $a0, $t8
    ctx->r14 = S32(U32(ctx->r4) >> (ctx->r24 & 31));
    // 0x800B9E5C: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x800B9E60: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x800B9E64: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800B9E68: mflo        $t4
    ctx->r12 = lo;
    // 0x800B9E6C: sw          $t4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r12;
    // 0x800B9E70: nop

    // 0x800B9E74: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9E78: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9E7C: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x800B9E80: b           L_800B9EA0
    // 0x800B9E84: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
        goto L_800B9EA0;
    // 0x800B9E84: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
L_800B9E88:
    // 0x800B9E88: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800B9E8C: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800B9E90: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x800B9E94: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
    // 0x800B9E98: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x800B9E9C: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
L_800B9EA0:
    // 0x800B9EA0: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800B9EA4: lh          $a0, 0x6($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X6);
    // 0x800B9EA8: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9EAC: sll         $t5, $t1, 1
    ctx->r13 = S32(ctx->r9 << 1);
    // 0x800B9EB0: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x800B9EB4: mflo        $t2
    ctx->r10 = lo;
    // 0x800B9EB8: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800B9EBC: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800B9EC0: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800B9EC4: addu        $t3, $a3, $t4
    ctx->r11 = ADD32(ctx->r7, ctx->r12);
    // 0x800B9EC8: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800B9ECC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800B9ED0: bltz        $v0, L_800BA0D0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B9ED4: sw          $t8, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r24;
            goto L_800BA0D0;
    }
    // 0x800B9ED4: sw          $t8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r24;
    // 0x800B9ED8: lw          $v1, 0x4($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X4);
    // 0x800B9EDC: nop

L_800B9EE0:
    // 0x800B9EE0: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9EE4: lh          $s1, 0x4($a2)
    ctx->r17 = MEM_H(ctx->r6, 0X4);
    // 0x800B9EE8: sll         $t1, $s6, 2
    ctx->r9 = S32(ctx->r22 << 2);
    // 0x800B9EEC: addu        $t1, $t1, $s6
    ctx->r9 = ADD32(ctx->r9, ctx->r22);
    // 0x800B9EF0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800B9EF4: addiu       $t4, $t4, 0x35DC
    ctx->r12 = ADD32(ctx->r12, 0X35DC);
    // 0x800B9EF8: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800B9EFC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B9F00: sll         $s4, $s6, 2
    ctx->r20 = S32(ctx->r22 << 2);
    // 0x800B9F04: mflo        $t6
    ctx->r14 = lo;
    // 0x800B9F08: addu        $s2, $t6, $s1
    ctx->r18 = ADD32(ctx->r14, ctx->r17);
    // 0x800B9F0C: bltz        $v0, L_800BA09C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B9F10: nop
    
            goto L_800BA09C;
    }
    // 0x800B9F10: nop

    // 0x800B9F14: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x800B9F18: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800B9F1C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800B9F20: addu        $s7, $t2, $t4
    ctx->r23 = ADD32(ctx->r10, ctx->r12);
    // 0x800B9F24: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    // 0x800B9F28: sw          $a0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r4;
    // 0x800B9F2C: addu        $s0, $t3, $t1
    ctx->r16 = ADD32(ctx->r11, ctx->r9);
L_800B9F30:
    // 0x800B9F30: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B9F34: lw          $t5, 0x35D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X35D4);
    // 0x800B9F38: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x800B9F3C: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x800B9F40: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B9F44: lw          $v0, 0x35D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X35D0);
    // 0x800B9F48: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x800B9F4C: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800B9F50: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800B9F54: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800B9F58: addu        $t3, $v0, $t4
    ctx->r11 = ADD32(ctx->r2, ctx->r12);
    // 0x800B9F5C: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x800B9F60: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800B9F64: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800B9F68: lwc1        $f16, 0x40($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X40);
    // 0x800B9F6C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B9F70: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B9F74: lw          $t1, 0x3718($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3718);
    // 0x800B9F78: mul.s       $f20, $f10, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B9F7C: blez        $t1, L_800B9FA0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800B9F80: nop
    
            goto L_800B9FA0;
    }
    // 0x800B9F80: nop

    // 0x800B9F84: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x800B9F88: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x800B9F8C: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x800B9F90: addu        $a1, $s3, $t5
    ctx->r5 = ADD32(ctx->r19, ctx->r13);
    // 0x800B9F94: jal         0x800BF4E4
    // 0x800B9F98: addu        $a2, $fp, $t7
    ctx->r6 = ADD32(ctx->r30, ctx->r15);
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800B9F98: addu        $a2, $fp, $t7
    ctx->r6 = ADD32(ctx->r30, ctx->r15);
    after_0:
    // 0x800B9F9C: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_800B9FA0:
    // 0x800B9FA0: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800B9FA4: nop

    // 0x800B9FA8: addu        $t6, $t8, $s4
    ctx->r14 = ADD32(ctx->r24, ctx->r20);
    // 0x800B9FAC: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800B9FB0: nop

    // 0x800B9FB4: mul.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800B9FB8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B9FBC: nop

    // 0x800B9FC0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B9FC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B9FC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B9FCC: nop

    // 0x800B9FD0: cvt.w.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = CVT_W_S(ctx->f20.fl);
    // 0x800B9FD4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B9FD8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800B9FDC: sub.s       $f6, $f20, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x800B9FE0: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x800B9FE4: mul.s       $f20, $f6, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x800B9FE8: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x800B9FEC: nop

    // 0x800B9FF0: bc1f        L_800BA000
    if (!c1cs) {
        // 0x800B9FF4: nop
    
            goto L_800BA000;
    }
    // 0x800B9FF4: nop

    // 0x800B9FF8: b           L_800BA014
    // 0x800B9FFC: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
        goto L_800BA014;
    // 0x800B9FFC: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
L_800BA000:
    // 0x800BA000: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x800BA004: nop

    // 0x800BA008: bc1f        L_800BA014
    if (!c1cs) {
        // 0x800BA00C: nop
    
            goto L_800BA014;
    }
    // 0x800BA00C: nop

    // 0x800BA010: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
L_800BA014:
    // 0x800BA014: mul.s       $f8, $f22, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800BA018: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800BA01C: sb          $t3, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r11;
    // 0x800BA020: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800BA024: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BA028: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800BA02C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BA030: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BA034: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BA038: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800BA03C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BA040: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x800BA044: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800BA048: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BA04C: addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
    // 0x800BA050: sb          $v0, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r2;
    // 0x800BA054: sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    // 0x800BA058: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x800BA05C: lw          $v1, 0x4($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X4);
    // 0x800BA060: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BA064: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BA068: bne         $at, $zero, L_800BA078
    if (ctx->r1 != 0) {
        // 0x800BA06C: nop
    
            goto L_800BA078;
    }
    // 0x800BA06C: nop

    // 0x800BA070: subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // 0x800BA074: subu        $s2, $s2, $v1
    ctx->r18 = SUB32(ctx->r18, ctx->r3);
L_800BA078:
    // 0x800BA078: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x800BA07C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800BA080: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800BA084: beq         $at, $zero, L_800B9F30
    if (ctx->r1 == 0) {
        // 0x800BA088: nop
    
            goto L_800B9F30;
    }
    // 0x800BA088: nop

    // 0x800BA08C: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x800BA090: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BA094: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x800BA098: nop

L_800BA09C:
    // 0x800BA09C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BA0A0: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BA0A4: bne         $at, $zero, L_800BA0B0
    if (ctx->r1 != 0) {
        // 0x800BA0A8: addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
            goto L_800BA0B0;
    }
    // 0x800BA0A8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800BA0AC: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
L_800BA0B0:
    // 0x800BA0B0: beq         $a1, $zero, L_800BA0C8
    if (ctx->r5 == 0) {
        // 0x800BA0B4: slt         $at, $v0, $fp
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r30) ? 1 : 0;
            goto L_800BA0C8;
    }
    // 0x800BA0B4: slt         $at, $v0, $fp
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x800BA0B8: lw          $t1, 0x8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8);
    // 0x800BA0BC: nop

    // 0x800BA0C0: addu        $t5, $t1, $v0
    ctx->r13 = ADD32(ctx->r9, ctx->r2);
    // 0x800BA0C4: sw          $t5, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r13;
L_800BA0C8:
    // 0x800BA0C8: beq         $at, $zero, L_800B9EE0
    if (ctx->r1 == 0) {
        // 0x800BA0CC: nop
    
            goto L_800B9EE0;
    }
    // 0x800BA0CC: nop

L_800BA0D0:
    // 0x800BA0D0: lh          $v1, 0xC($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XC);
    // 0x800BA0D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA0D8: bne         $v1, $at, L_800B9DDC
    if (ctx->r3 != ctx->r1) {
        // 0x800BA0DC: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_800B9DDC;
    }
    // 0x800BA0DC: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_800BA0E0:
    // 0x800BA0E0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800BA0E4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BA0E8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BA0EC: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BA0F0: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BA0F4: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BA0F8: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BA0FC: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BA100: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BA104: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800BA108: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BA10C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800BA110: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800BA114: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800BA118: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800BA11C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800BA120: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800BA124: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800BA128: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800BA12C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800BA130: jr          $ra
    // 0x800BA134: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800BA134: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void waves_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA138: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800BA13C: addiu       $t1, $t1, -0x5A28
    ctx->r9 = ADD32(ctx->r9, -0X5A28);
    // 0x800BA140: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BA144: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800BA148: addiu       $t3, $t3, -0x5A78
    ctx->r11 = ADD32(ctx->r11, -0X5A78);
    // 0x800BA14C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BA150: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    // 0x800BA154: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BA158: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800BA15C: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800BA160: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800BA164: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BA168: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800BA16C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BA170: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800BA174: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BA178: blez        $v0, L_800BA268
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BA17C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800BA268;
    }
    // 0x800BA17C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800BA180: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800BA184: addiu       $a2, $a2, 0x35D4
    ctx->r6 = ADD32(ctx->r6, 0X35D4);
L_800BA188:
    // 0x800BA188: blez        $v0, L_800BA258
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BA18C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800BA258;
    }
    // 0x800BA18C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BA190: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BA194: sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8 << 2);
    // 0x800BA198: addu        $v1, $t9, $a1
    ctx->r3 = ADD32(ctx->r25, ctx->r5);
L_800BA19C:
    // 0x800BA19C: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800BA1A0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BA1A4: addu        $t6, $t7, $s1
    ctx->r14 = ADD32(ctx->r15, ctx->r17);
    // 0x800BA1A8: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800BA1AC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800BA1B0: lw          $v0, 0x20($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X20);
    // 0x800BA1B4: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x800BA1B8: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x800BA1BC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800BA1C0: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA1C4: bne         $at, $zero, L_800BA1F0
    if (ctx->r1 != 0) {
        // 0x800BA1C8: subu        $t9, $a0, $v0
        ctx->r25 = SUB32(ctx->r4, ctx->r2);
            goto L_800BA1F0;
    }
    // 0x800BA1C8: subu        $t9, $a0, $v0
    ctx->r25 = SUB32(ctx->r4, ctx->r2);
L_800BA1CC:
    // 0x800BA1CC: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x800BA1D0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800BA1D4: lw          $v0, 0x20($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X20);
    // 0x800BA1D8: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x800BA1DC: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x800BA1E0: nop

    // 0x800BA1E4: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA1E8: beq         $at, $zero, L_800BA1CC
    if (ctx->r1 == 0) {
        // 0x800BA1EC: subu        $t9, $a0, $v0
        ctx->r25 = SUB32(ctx->r4, ctx->r2);
            goto L_800BA1CC;
    }
    // 0x800BA1EC: subu        $t9, $a0, $v0
    ctx->r25 = SUB32(ctx->r4, ctx->r2);
L_800BA1F0:
    // 0x800BA1F0: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800BA1F4: nop

    // 0x800BA1F8: addu        $t8, $t6, $s1
    ctx->r24 = ADD32(ctx->r14, ctx->r17);
    // 0x800BA1FC: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x800BA200: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BA204: lw          $v0, 0x20($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X20);
    // 0x800BA208: addu        $v1, $t9, $a1
    ctx->r3 = ADD32(ctx->r25, ctx->r5);
    // 0x800BA20C: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x800BA210: nop

    // 0x800BA214: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA218: bne         $at, $zero, L_800BA244
    if (ctx->r1 != 0) {
        // 0x800BA21C: subu        $t7, $a0, $v0
        ctx->r15 = SUB32(ctx->r4, ctx->r2);
            goto L_800BA244;
    }
    // 0x800BA21C: subu        $t7, $a0, $v0
    ctx->r15 = SUB32(ctx->r4, ctx->r2);
L_800BA220:
    // 0x800BA220: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
    // 0x800BA224: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800BA228: lw          $v0, 0x20($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X20);
    // 0x800BA22C: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x800BA230: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x800BA234: nop

    // 0x800BA238: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA23C: beq         $at, $zero, L_800BA220
    if (ctx->r1 == 0) {
        // 0x800BA240: subu        $t7, $a0, $v0
        ctx->r15 = SUB32(ctx->r4, ctx->r2);
            goto L_800BA220;
    }
    // 0x800BA240: subu        $t7, $a0, $v0
    ctx->r15 = SUB32(ctx->r4, ctx->r2);
L_800BA244:
    // 0x800BA244: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    // 0x800BA248: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800BA24C: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA250: bne         $at, $zero, L_800BA19C
    if (ctx->r1 != 0) {
        // 0x800BA254: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800BA19C;
    }
    // 0x800BA254: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800BA258:
    // 0x800BA258: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BA25C: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA260: bne         $at, $zero, L_800BA188
    if (ctx->r1 != 0) {
        // 0x800BA264: nop
    
            goto L_800BA188;
    }
    // 0x800BA264: nop

L_800BA268:
    // 0x800BA268: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BA26C: lw          $a1, 0x3660($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3660);
    // 0x800BA270: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA274: lhu         $t9, 0x14($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X14);
    // 0x800BA278: addiu       $a0, $a0, -0x59A4
    ctx->r4 = ADD32(ctx->r4, -0X59A4);
    // 0x800BA27C: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BA280: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800BA284: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800BA288: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BA28C: addiu       $a3, $a3, -0x59B0
    ctx->r7 = ADD32(ctx->r7, -0X59B0);
    // 0x800BA290: addiu       $t0, $t0, 0x35D8
    ctx->r8 = ADD32(ctx->r8, 0X35D8);
    // 0x800BA294: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800BA298: mflo        $t7
    ctx->r15 = lo;
    // 0x800BA29C: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x800BA2A0: bgez        $v0, L_800BA2B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800BA2A4: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_800BA2B0;
    }
    // 0x800BA2A4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800BA2A8: b           L_800BA2DC
    // 0x800BA2AC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_800BA2DC;
    // 0x800BA2AC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800BA2B0:
    // 0x800BA2B0: lhu         $v1, 0x12($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X12);
    // 0x800BA2B4: nop

    // 0x800BA2B8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BA2BC: bne         $at, $zero, L_800BA2DC
    if (ctx->r1 != 0) {
        // 0x800BA2C0: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_800BA2DC;
    }
    // 0x800BA2C0: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
L_800BA2C4:
    // 0x800BA2C4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800BA2C8: lhu         $v1, 0x12($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X12);
    // 0x800BA2CC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800BA2D0: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BA2D4: beq         $at, $zero, L_800BA2C4
    if (ctx->r1 == 0) {
        // 0x800BA2D8: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_800BA2C4;
    }
    // 0x800BA2D8: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
L_800BA2DC:
    // 0x800BA2DC: lw          $t8, 0x38($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X38);
    // 0x800BA2E0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BA2E4: multu       $t8, $s1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BA2E8: addiu       $t2, $t2, -0x59BC
    ctx->r10 = ADD32(ctx->r10, -0X59BC);
    // 0x800BA2EC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800BA2F0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BA2F4: lw          $t8, -0x59AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X59AC);
    // 0x800BA2F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BA2FC: addiu       $v0, $v0, -0x59B8
    ctx->r2 = ADD32(ctx->r2, -0X59B8);
    // 0x800BA300: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800BA304: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BA308: addiu       $a1, $a1, -0x59B4
    ctx->r5 = ADD32(ctx->r5, -0X59B4);
    // 0x800BA30C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BA310: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BA314: mflo        $t7
    ctx->r15 = lo;
    // 0x800BA318: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x800BA31C: lw          $t6, 0x3C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X3C);
    // 0x800BA320: and         $t7, $t9, $t8
    ctx->r15 = ctx->r25 & ctx->r24;
    // 0x800BA324: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BA328: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800BA32C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x800BA330: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BA334: lw          $t6, -0x59A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X59A8);
    // 0x800BA338: mflo        $t9
    ctx->r25 = lo;
    // 0x800BA33C: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x800BA340: and         $a2, $t7, $t6
    ctx->r6 = ctx->r15 & ctx->r14;
    // 0x800BA344: bltz        $a0, L_800BA3B0
    if (SIGNED(ctx->r4) < 0) {
        // 0x800BA348: sw          $a2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r6;
            goto L_800BA3B0;
    }
    // 0x800BA348: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_800BA34C:
    // 0x800BA34C: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x800BA350: bltz        $a0, L_800BA394
    if (SIGNED(ctx->r4) < 0) {
        // 0x800BA354: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_800BA394;
    }
    // 0x800BA354: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800BA358: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
L_800BA35C:
    // 0x800BA35C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800BA360: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800BA364: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800BA368: sh          $v1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r3;
    // 0x800BA36C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800BA370: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BA374: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x800BA378: sh          $a2, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r6;
    // 0x800BA37C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800BA380: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800BA384: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800BA388: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BA38C: beq         $at, $zero, L_800BA35C
    if (ctx->r1 == 0) {
        // 0x800BA390: addu        $v1, $v1, $t8
        ctx->r3 = ADD32(ctx->r3, ctx->r24);
            goto L_800BA35C;
    }
    // 0x800BA390: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
L_800BA394:
    // 0x800BA394: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800BA398: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BA39C: slt         $at, $a0, $s2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800BA3A0: beq         $at, $zero, L_800BA34C
    if (ctx->r1 == 0) {
        // 0x800BA3A4: addu        $a2, $a2, $t7
        ctx->r6 = ADD32(ctx->r6, ctx->r15);
            goto L_800BA34C;
    }
    // 0x800BA3A4: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x800BA3A8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BA3AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800BA3B0:
    // 0x800BA3B0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BA3B4: lw          $t6, -0x59C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X59C8);
    // 0x800BA3B8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800BA3BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BA3C0: beq         $t6, $at, L_800BA3D0
    if (ctx->r14 == ctx->r1) {
        // 0x800BA3C4: addiu       $t0, $t0, 0x35D8
        ctx->r8 = ADD32(ctx->r8, 0X35D8);
            goto L_800BA3D0;
    }
    // 0x800BA3C4: addiu       $t0, $t0, 0x35D8
    ctx->r8 = ADD32(ctx->r8, 0X35D8);
    // 0x800BA3C8: b           L_800BA3D4
    // 0x800BA3CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_800BA3D4;
    // 0x800BA3CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800BA3D0:
    // 0x800BA3D0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
L_800BA3D4:
    // 0x800BA3D4: addiu       $ra, $a0, 0x1
    ctx->r31 = ADD32(ctx->r4, 0X1);
    // 0x800BA3D8: blez        $a0, L_800BA658
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BA3DC: sw          $ra, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r31;
            goto L_800BA658;
    }
    // 0x800BA3DC: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800BA3E0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800BA3E4: addiu       $a2, $a2, 0x3610
    ctx->r6 = ADD32(ctx->r6, 0X3610);
L_800BA3E8:
    // 0x800BA3E8: blez        $a0, L_800BA63C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BA3EC: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_800BA63C;
    }
    // 0x800BA3EC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_800BA3F0:
    // 0x800BA3F0: blez        $t2, L_800BA624
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800BA3F4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800BA624;
    }
    // 0x800BA3F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BA3F8: sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16 << 4);
    // 0x800BA3FC: sll         $a0, $t5, 2
    ctx->r4 = S32(ctx->r13 << 2);
    // 0x800BA400: sll         $a1, $ra, 2
    ctx->r5 = S32(ctx->r31 << 2);
L_800BA404:
    // 0x800BA404: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800BA408: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800BA40C: addu        $t7, $t8, $a0
    ctx->r15 = ADD32(ctx->r24, ctx->r4);
    // 0x800BA410: lh          $t6, 0x0($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X0);
    // 0x800BA414: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800BA418: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800BA41C: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x800BA420: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800BA424: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800BA428: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BA42C: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x800BA430: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
    // 0x800BA434: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BA438: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BA43C: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x800BA440: lh          $t6, 0x6($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X6);
    // 0x800BA444: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA448: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800BA44C: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800BA450: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BA454: nop

    // 0x800BA458: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA45C: sh          $t6, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r14;
    // 0x800BA460: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BA464: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BA468: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x800BA46C: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x800BA470: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA474: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800BA478: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800BA47C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA480: nop

    // 0x800BA484: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA488: sh          $t6, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r14;
    // 0x800BA48C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800BA490: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800BA494: addu        $t7, $t8, $a1
    ctx->r15 = ADD32(ctx->r24, ctx->r5);
    // 0x800BA498: lh          $t6, 0x2($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X2);
    // 0x800BA49C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800BA4A0: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800BA4A4: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800BA4A8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800BA4AC: nop

    // 0x800BA4B0: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x800BA4B4: sh          $t6, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r14;
    // 0x800BA4B8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BA4BC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BA4C0: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x800BA4C4: lh          $t6, 0x4($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X4);
    // 0x800BA4C8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA4CC: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800BA4D0: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800BA4D4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BA4D8: nop

    // 0x800BA4DC: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA4E0: sh          $t6, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r14;
    // 0x800BA4E4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BA4E8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BA4EC: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x800BA4F0: lh          $t6, 0x6($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X6);
    // 0x800BA4F4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA4F8: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800BA4FC: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800BA500: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA504: nop

    // 0x800BA508: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA50C: sh          $t6, 0xE($t9)
    MEM_H(0XE, ctx->r25) = ctx->r14;
    // 0x800BA510: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800BA514: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800BA518: addu        $t7, $t8, $a0
    ctx->r15 = ADD32(ctx->r24, ctx->r4);
    // 0x800BA51C: lh          $t6, 0x4($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X4);
    // 0x800BA520: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800BA524: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800BA528: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800BA52C: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800BA530: nop

    // 0x800BA534: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x800BA538: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800BA53C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BA540: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BA544: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x800BA548: lh          $t6, 0x6($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X6);
    // 0x800BA54C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA550: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800BA554: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800BA558: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BA55C: nop

    // 0x800BA560: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA564: sh          $t6, 0x16($t8)
    MEM_H(0X16, ctx->r24) = ctx->r14;
    // 0x800BA568: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BA56C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BA570: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x800BA574: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x800BA578: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA57C: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800BA580: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800BA584: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA588: nop

    // 0x800BA58C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA590: sh          $t6, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r14;
    // 0x800BA594: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800BA598: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800BA59C: addu        $t7, $t8, $a1
    ctx->r15 = ADD32(ctx->r24, ctx->r5);
    // 0x800BA5A0: lh          $t6, 0x6($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X6);
    // 0x800BA5A4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800BA5A8: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800BA5AC: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800BA5B0: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800BA5B4: nop

    // 0x800BA5B8: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x800BA5BC: sh          $t6, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r14;
    // 0x800BA5C0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BA5C4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BA5C8: addu        $t8, $t9, $a1
    ctx->r24 = ADD32(ctx->r25, ctx->r5);
    // 0x800BA5CC: lh          $t6, 0x4($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X4);
    // 0x800BA5D0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA5D4: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800BA5D8: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800BA5DC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BA5E0: nop

    // 0x800BA5E4: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA5E8: sh          $t6, 0x1C($t8)
    MEM_H(0X1C, ctx->r24) = ctx->r14;
    // 0x800BA5EC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BA5F0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BA5F4: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x800BA5F8: lh          $t6, 0x6($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X6);
    // 0x800BA5FC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA600: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800BA604: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800BA608: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA60C: nop

    // 0x800BA610: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA614: bne         $a3, $t2, L_800BA404
    if (ctx->r7 != ctx->r10) {
        // 0x800BA618: sh          $t6, 0x1E($t9)
        MEM_H(0X1E, ctx->r25) = ctx->r14;
            goto L_800BA404;
    }
    // 0x800BA618: sh          $t6, 0x1E($t9)
    MEM_H(0X1E, ctx->r25) = ctx->r14;
    // 0x800BA61C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800BA620: nop

L_800BA624:
    // 0x800BA624: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800BA628: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BA62C: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800BA630: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BA634: bne         $at, $zero, L_800BA3F0
    if (ctx->r1 != 0) {
        // 0x800BA638: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_800BA3F0;
    }
    // 0x800BA638: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800BA63C:
    // 0x800BA63C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BA640: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BA644: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800BA648: bne         $at, $zero, L_800BA3E8
    if (ctx->r1 != 0) {
        // 0x800BA64C: addiu       $ra, $ra, 0x1
        ctx->r31 = ADD32(ctx->r31, 0X1);
            goto L_800BA3E8;
    }
    // 0x800BA64C: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BA650: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x800BA654: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_800BA658:
    // 0x800BA658: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800BA65C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800BA660: addiu       $t8, $t8, 0x3620
    ctx->r24 = ADD32(ctx->r24, 0X3620);
    // 0x800BA664: sll         $t9, $t6, 5
    ctx->r25 = S32(ctx->r14 << 5);
    // 0x800BA668: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x800BA66C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BA670: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800BA674: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BA678: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800BA67C: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x800BA680: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x800BA684: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800BA688: addu        $a2, $v1, $t2
    ctx->r6 = ADD32(ctx->r3, ctx->r10);
    // 0x800BA68C: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x800BA690: mflo        $a3
    ctx->r7 = lo;
    // 0x800BA694: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x800BA698: addu        $a1, $v1, $t8
    ctx->r5 = ADD32(ctx->r3, ctx->r24);
    // 0x800BA69C: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x800BA6A0: nop

    // 0x800BA6A4: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x800BA6A8: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x800BA6AC: nop

    // 0x800BA6B0: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x800BA6B4: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800BA6B8: nop

    // 0x800BA6BC: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
    // 0x800BA6C0: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x800BA6C4: nop

    // 0x800BA6C8: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
    // 0x800BA6CC: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x800BA6D0: nop

    // 0x800BA6D4: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
    // 0x800BA6D8: lh          $t6, 0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2);
    // 0x800BA6DC: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x800BA6E0: sh          $t6, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r14;
    // 0x800BA6E4: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x800BA6E8: addu        $t6, $v1, $t7
    ctx->r14 = ADD32(ctx->r3, ctx->r15);
    // 0x800BA6EC: sh          $t9, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r25;
    // 0x800BA6F0: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x800BA6F4: addu        $t4, $t6, $t2
    ctx->r12 = ADD32(ctx->r14, ctx->r10);
    // 0x800BA6F8: sh          $t8, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r24;
    // 0x800BA6FC: lh          $t9, 0x0($t4)
    ctx->r25 = MEM_H(ctx->r12, 0X0);
    // 0x800BA700: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BA704: sh          $t9, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r25;
    // 0x800BA708: lh          $t8, 0x2($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X2);
    // 0x800BA70C: nop

    // 0x800BA710: sh          $t8, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r24;
    // 0x800BA714: lw          $t7, 0x3718($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3718);
    // 0x800BA718: nop

    // 0x800BA71C: blez        $t7, L_800BA734
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800BA720: nop
    
            goto L_800BA734;
    }
    // 0x800BA720: nop

    // 0x800BA724: jal         0x800C03B8
    // 0x800BA728: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BFE98(rdram, ctx);
        goto after_0;
    // 0x800BA728: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800BA72C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BA730: addiu       $t3, $t3, -0x5A78
    ctx->r11 = ADD32(ctx->r11, -0X5A78);
L_800BA734:
    // 0x800BA734: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA738: addiu       $v1, $v1, -0x5318
    ctx->r3 = ADD32(ctx->r3, -0X5318);
    // 0x800BA73C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA740: nop

    // 0x800BA744: blez        $v0, L_800BA790
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BA748: slt         $at, $s1, $v0
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800BA790;
    }
    // 0x800BA748: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA74C: beq         $at, $zero, L_800BA780
    if (ctx->r1 == 0) {
        // 0x800BA750: nop
    
            goto L_800BA780;
    }
    // 0x800BA750: nop

    // 0x800BA754: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800BA758: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BA75C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BA760: lwc1        $f8, -0x531C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X531C);
    // 0x800BA764: lwc1        $f16, 0x40($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X40);
    // 0x800BA768: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BA76C: subu        $t6, $v0, $s1
    ctx->r14 = SUB32(ctx->r2, ctx->r17);
    // 0x800BA770: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BA774: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800BA778: b           L_800BA790
    // 0x800BA77C: swc1        $f18, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f18.u32l;
        goto L_800BA790;
    // 0x800BA77C: swc1        $f18, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f18.u32l;
L_800BA780:
    // 0x800BA780: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BA784: lwc1        $f4, -0x5320($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5320);
    // 0x800BA788: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800BA78C: swc1        $f4, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f4.u32l;
L_800BA790:
    // 0x800BA790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BA794: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BA798: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA79C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800BA7A0: jr          $ra
    // 0x800BA7A4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BA7A4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
