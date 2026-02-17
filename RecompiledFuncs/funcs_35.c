#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void alSynSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9BB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C9BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9BB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C9BBC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C9BC0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800C9BC4: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800C9BC8: beql        $t7, $zero, L_800C9C40
    if (ctx->r15 == 0) {
        // 0x800C9BCC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9C40;
    }
    goto skip_0;
    // 0x800C9BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9BD0: jal         0x800658A8
    // 0x800C9BD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9BD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C9BD8: beq         $v0, $zero, L_800C9C3C
    if (ctx->r2 == 0) {
        // 0x800C9BDC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800C9C3C;
    }
    // 0x800C9BDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C9BE0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800C9BE4: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x800C9BE8: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x800C9BEC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800C9BF0: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x800C9BF4: sh          $t3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r11;
    // 0x800C9BF8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800C9BFC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800C9C00: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x800C9C04: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x800C9C08: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C9C0C: jal         0x80065A04
    // 0x800C9C10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _timeToSamples(rdram, ctx);
        goto after_1;
    // 0x800C9C10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800C9C14: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9C18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9C1C: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x800C9C20: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800C9C24: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C9C28: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x800C9C2C: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x800C9C30: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9C34: jalr        $t9
    // 0x800C9C38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800C9C38: nop

    after_2:
L_800C9C3C:
    // 0x800C9C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9C40:
    // 0x800C9C40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C9C44: jr          $ra
    // 0x800C9C48: nop

    return;
    // 0x800C9C48: nop

    // 0x800C9C4C: nop

;}
RECOMP_FUNC void alSynStartVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9C58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9C5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C9C60: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800C9C64: beql        $t6, $zero, L_800C9CD0
    if (ctx->r14 == 0) {
        // 0x800C9C68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9CD0;
    }
    goto skip_0;
    // 0x800C9C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9C6C: jal         0x800658A8
    // 0x800C9C70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9C70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C9C74: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9C78: beq         $v0, $zero, L_800C9CCC
    if (ctx->r2 == 0) {
        // 0x800C9C7C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9CCC;
    }
    // 0x800C9C7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9C80: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C9C84: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800C9C88: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x800C9C8C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800C9C90: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800C9C94: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800C9C98: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9C9C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C9CA0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9CA4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800C9CA8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C9CAC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800C9CB0: lh          $t4, 0x1A($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A);
    // 0x800C9CB4: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x800C9CB8: lw          $t5, 0x8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8);
    // 0x800C9CBC: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    // 0x800C9CC0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9CC4: jalr        $t9
    // 0x800C9CC8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9CC8: nop

    after_1:
L_800C9CCC:
    // 0x800C9CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9CD0:
    // 0x800C9CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9CD4: jr          $ra
    // 0x800C9CD8: nop

    return;
    // 0x800C9CD8: nop

    // 0x800C9CDC: nop

;}
RECOMP_FUNC void alSynSetPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9CE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9CE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9CEC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C9CF0: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800C9CF4: beql        $t6, $zero, L_800C9D58
    if (ctx->r14 == 0) {
        // 0x800C9CF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9D58;
    }
    goto skip_0;
    // 0x800C9CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9CFC: jal         0x800658A8
    // 0x800C9D00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9D00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C9D04: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9D08: beq         $v0, $zero, L_800C9D54
    if (ctx->r2 == 0) {
        // 0x800C9D0C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9D54;
    }
    // 0x800C9D0C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9D10: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C9D14: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800C9D18: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x800C9D1C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800C9D20: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800C9D24: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800C9D28: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9D2C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C9D30: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9D34: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C9D38: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C9D3C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800C9D40: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800C9D44: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800C9D48: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9D4C: jalr        $t9
    // 0x800C9D50: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9D50: nop

    after_1:
L_800C9D54:
    // 0x800C9D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9D58:
    // 0x800C9D58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9D5C: jr          $ra
    // 0x800C9D60: nop

    return;
    // 0x800C9D60: nop

    // 0x800C9D64: nop

    // 0x800C9D68: nop

    // 0x800C9D6C: nop

;}
RECOMP_FUNC void alSynSetFXMix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9D78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9D7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C9D80: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800C9D84: beql        $t6, $zero, L_800C9DF8
    if (ctx->r14 == 0) {
        // 0x800C9D88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9DF8;
    }
    goto skip_0;
    // 0x800C9D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9D8C: jal         0x800658A8
    // 0x800C9D90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9D90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C9D94: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9D98: beq         $v0, $zero, L_800C9DF4
    if (ctx->r2 == 0) {
        // 0x800C9D9C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9DF4;
    }
    // 0x800C9D9C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9DA0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C9DA4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800C9DA8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800C9DAC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800C9DB0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800C9DB4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800C9DB8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C9DBC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9DC0: lbu         $v1, 0x23($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X23);
    // 0x800C9DC4: bgez        $v1, L_800C9DD4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800C9DC8: negu        $t3, $v1
        ctx->r11 = SUB32(0, ctx->r3);
            goto L_800C9DD4;
    }
    // 0x800C9DC8: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x800C9DCC: b           L_800C9DD8
    // 0x800C9DD0: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
        goto L_800C9DD8;
    // 0x800C9DD0: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_800C9DD4:
    // 0x800C9DD4: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_800C9DD8:
    // 0x800C9DD8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800C9DDC: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x800C9DE0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9DE4: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x800C9DE8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9DEC: jalr        $t9
    // 0x800C9DF0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9DF0: nop

    after_1:
L_800C9DF4:
    // 0x800C9DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9DF8:
    // 0x800C9DF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9DFC: jr          $ra
    // 0x800C9E00: nop

    return;
    // 0x800C9E00: nop

    // 0x800C9E04: nop

    // 0x800C9E08: nop

    // 0x800C9E0C: nop

;}
RECOMP_FUNC void alSynStopVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9E10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9E18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9E1C: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800C9E20: beql        $t6, $zero, L_800C9E7C
    if (ctx->r14 == 0) {
        // 0x800C9E24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9E7C;
    }
    goto skip_0;
    // 0x800C9E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9E28: jal         0x800658A8
    // 0x800C9E2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9E2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C9E30: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9E34: beq         $v0, $zero, L_800C9E78
    if (ctx->r2 == 0) {
        // 0x800C9E38: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9E78;
    }
    // 0x800C9E38: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9E3C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C9E40: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800C9E44: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800C9E48: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800C9E4C: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800C9E50: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800C9E54: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C9E58: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C9E5C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9E60: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800C9E64: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9E68: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800C9E6C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9E70: jalr        $t9
    // 0x800C9E74: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9E74: nop

    after_1:
L_800C9E78:
    // 0x800C9E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9E7C:
    // 0x800C9E7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9E80: jr          $ra
    // 0x800C9E84: nop

    return;
    // 0x800C9E84: nop

    // 0x800C9E88: nop

    // 0x800C9E8C: nop

;}
RECOMP_FUNC void alSynFreeVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9E98: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    // 0x800C9E9C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800C9EA0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C9EA4: beql        $a2, $zero, L_800C9F34
    if (ctx->r6 == 0) {
        // 0x800C9EA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9F34;
    }
    goto skip_0;
    // 0x800C9EA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9EAC: lw          $t6, 0xD8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD8);
    // 0x800C9EB0: beql        $t6, $zero, L_800C9F1C
    if (ctx->r14 == 0) {
        // 0x800C9EB4: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800C9F1C;
    }
    goto skip_1;
    // 0x800C9EB4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    skip_1:
    // 0x800C9EB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C9EBC: jal         0x800658A8
    // 0x800C9EC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9EC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C9EC4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9EC8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C9ECC: beq         $v0, $zero, L_800C9F30
    if (ctx->r2 == 0) {
        // 0x800C9ED0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9F30;
    }
    // 0x800C9ED0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9ED4: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x800C9ED8: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x800C9EDC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9EE0: lw          $t9, 0xD8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XD8);
    // 0x800C9EE4: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x800C9EE8: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x800C9EEC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9EF0: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800C9EF4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800C9EF8: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800C9EFC: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800C9F00: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800C9F04: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9F08: jalr        $t9
    // 0x800C9F0C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9F0C: nop

    after_1:
    // 0x800C9F10: b           L_800C9F2C
    // 0x800C9F14: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_800C9F2C;
    // 0x800C9F14: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9F18: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800C9F1C:
    // 0x800C9F1C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800C9F20: jal         0x8006595C
    // 0x800C9F24: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    _freePVoice(rdram, ctx);
        goto after_2;
    // 0x800C9F24: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x800C9F28: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800C9F2C:
    // 0x800C9F2C: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
L_800C9F30:
    // 0x800C9F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9F34:
    // 0x800C9F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9F38: jr          $ra
    // 0x800C9F3C: nop

    return;
    // 0x800C9F3C: nop

;}
RECOMP_FUNC void alCents2Ratio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9F40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9F44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C9F48: bltz        $a0, L_800C9F5C
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C9F4C: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800C9F5C;
    }
    // 0x800C9F4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9F50: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9F54: b           L_800C9F64
    // 0x800C9F58: lwc1        $f0, -0x65C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X65C0);
        goto L_800C9F64;
    // 0x800C9F58: lwc1        $f0, -0x65C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X65C0);
L_800C9F5C:
    // 0x800C9F5C: lwc1        $f0, -0x65BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X65BC);
    // 0x800C9F60: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_800C9F64:
    // 0x800C9F64: beq         $a0, $zero, L_800C9F88
    if (ctx->r4 == 0) {
        // 0x800C9F68: andi        $t6, $a0, 0x1
        ctx->r14 = ctx->r4 & 0X1;
            goto L_800C9F88;
    }
L_800C9F68:
    // 0x800C9F68: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x800C9F6C: beq         $t6, $zero, L_800C9F7C
    if (ctx->r14 == 0) {
        // 0x800C9F70: sra         $t7, $a0, 1
        ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800C9F7C;
    }
    // 0x800C9F70: sra         $t7, $a0, 1
    ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800C9F74: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C9F78: nop

L_800C9F7C:
    // 0x800C9F7C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9F80: bne         $t7, $zero, L_800C9F68
    if (ctx->r15 != 0) {
        // 0x800C9F84: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800C9F68;
    }
    // 0x800C9F84: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800C9F88:
    // 0x800C9F88: jr          $ra
    // 0x800C9F8C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800C9F8C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void sqrtf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA030: jr          $ra
    // 0x800CA034: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x800CA034: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    // 0x800CA038: nop

    // 0x800CA03C: nop

;}
RECOMP_FUNC void alSynSetPriority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA040: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800CA044: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800CA048: jr          $ra
    // 0x800CA04C: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
    return;
    // 0x800CA04C: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void __NOPS_NEEDED(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA050: nop

    // 0x800CA054: nop

    // 0x800CA058: nop

    // 0x800CA05C: nop

    // 0x800CA060: nop

    // 0x800CA064: nop

    // 0x800CA068: nop

    // 0x800CA06C: nop

    // 0x800CA070: nop

    // 0x800CA074: nop

    // 0x800CA078: nop

    // 0x800CA07C: nop

    // 0x800CA080: nop

    // 0x800CA084: nop

    // 0x800CA088: nop

    // 0x800CA08C: nop

;}
RECOMP_FUNC void bcopy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA300: beq         $a2, $zero, L_800CA36C
    if (ctx->r6 == 0) {
        // 0x800CA304: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800CA36C;
    }
    // 0x800CA304: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CA308: beq         $a0, $a1, L_800CA36C
    if (ctx->r4 == ctx->r5) {
        // 0x800CA30C: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800CA36C;
    }
    // 0x800CA30C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CA310: bnel        $at, $zero, L_800CA334
    if (ctx->r1 != 0) {
        // 0x800CA314: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CA334;
    }
    goto skip_0;
    // 0x800CA314: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x800CA318: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x800CA31C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CA320: beql        $at, $zero, L_800CA334
    if (ctx->r1 == 0) {
        // 0x800CA324: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CA334;
    }
    goto skip_1;
    // 0x800CA324: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x800CA328: b           L_800CA498
    // 0x800CA32C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_800CA498;
    // 0x800CA32C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800CA330: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CA334:
    // 0x800CA334: bne         $at, $zero, L_800CA34C
    if (ctx->r1 != 0) {
        // 0x800CA338: nop
    
            goto L_800CA34C;
    }
    // 0x800CA338: nop

    // 0x800CA33C: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800CA340: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800CA344: beq         $v0, $v1, L_800CA374
    if (ctx->r2 == ctx->r3) {
        // 0x800CA348: nop
    
            goto L_800CA374;
    }
    // 0x800CA348: nop

L_800CA34C:
    // 0x800CA34C: beq         $a2, $zero, L_800CA36C
    if (ctx->r6 == 0) {
        // 0x800CA350: nop
    
            goto L_800CA36C;
    }
    // 0x800CA350: nop

    // 0x800CA354: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_800CA358:
    // 0x800CA358: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CA35C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CA360: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CA364: bne         $a0, $v1, L_800CA358
    if (ctx->r4 != ctx->r3) {
        // 0x800CA368: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_800CA358;
    }
    // 0x800CA368: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_800CA36C:
    // 0x800CA36C: jr          $ra
    // 0x800CA370: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800CA370: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800CA374:
    // 0x800CA374: beq         $v0, $zero, L_800CA3D8
    if (ctx->r2 == 0) {
        // 0x800CA378: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800CA3D8;
    }
    // 0x800CA378: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CA37C: beq         $v0, $at, L_800CA3BC
    if (ctx->r2 == ctx->r1) {
        // 0x800CA380: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CA3BC;
    }
    // 0x800CA380: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CA384: beql        $v0, $at, L_800CA3A8
    if (ctx->r2 == ctx->r1) {
        // 0x800CA388: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_800CA3A8;
    }
    goto skip_2;
    // 0x800CA388: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x800CA38C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CA390: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CA394: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CA398: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800CA39C: b           L_800CA3D8
    // 0x800CA3A0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_800CA3D8;
    // 0x800CA3A0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x800CA3A4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_800CA3A8:
    // 0x800CA3A8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800CA3AC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800CA3B0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800CA3B4: b           L_800CA3D8
    // 0x800CA3B8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_800CA3D8;
    // 0x800CA3B8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_800CA3BC:
    // 0x800CA3BC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CA3C0: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x800CA3C4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800CA3C8: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x800CA3CC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800CA3D0: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x800CA3D4: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_800CA3D8:
    // 0x800CA3D8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800CA3DC: bnel        $at, $zero, L_800CA438
    if (ctx->r1 != 0) {
        // 0x800CA3E0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CA438;
    }
    goto skip_3;
    // 0x800CA3E0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x800CA3E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CA3E8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800CA3EC: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800CA3F0: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800CA3F4: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x800CA3F8: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CA3FC: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x800CA400: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x800CA404: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800CA408: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800CA40C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800CA410: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x800CA414: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x800CA418: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x800CA41C: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x800CA420: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x800CA424: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x800CA428: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x800CA42C: b           L_800CA3D8
    // 0x800CA430: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_800CA3D8;
    // 0x800CA430: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_800CA434:
    // 0x800CA434: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CA438:
    // 0x800CA438: bnel        $at, $zero, L_800CA474
    if (ctx->r1 != 0) {
        // 0x800CA43C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800CA474;
    }
    goto skip_4;
    // 0x800CA43C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x800CA440: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CA444: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800CA448: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800CA44C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800CA450: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800CA454: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800CA458: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800CA45C: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x800CA460: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x800CA464: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x800CA468: b           L_800CA434
    // 0x800CA46C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_800CA434;
    // 0x800CA46C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_800CA470:
    // 0x800CA470: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800CA474:
    // 0x800CA474: bne         $at, $zero, L_800CA34C
    if (ctx->r1 != 0) {
        // 0x800CA478: nop
    
            goto L_800CA34C;
    }
    // 0x800CA478: nop

    // 0x800CA47C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CA480: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CA484: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800CA488: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800CA48C: b           L_800CA470
    // 0x800CA490: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_800CA470;
    // 0x800CA490: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x800CA494: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CA498:
    // 0x800CA498: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800CA49C: bne         $at, $zero, L_800CA4B4
    if (ctx->r1 != 0) {
        // 0x800CA4A0: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_800CA4B4;
    }
    // 0x800CA4A0: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800CA4A4: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800CA4A8: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800CA4AC: beq         $v0, $v1, L_800CA4E4
    if (ctx->r2 == ctx->r3) {
        // 0x800CA4B0: nop
    
            goto L_800CA4E4;
    }
    // 0x800CA4B0: nop

L_800CA4B4:
    // 0x800CA4B4: beq         $a2, $zero, L_800CA36C
    if (ctx->r6 == 0) {
        // 0x800CA4B8: nop
    
            goto L_800CA36C;
    }
    // 0x800CA4B8: nop

    // 0x800CA4BC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CA4C0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800CA4C4: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_800CA4C8:
    // 0x800CA4C8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CA4CC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CA4D0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800CA4D4: bne         $a0, $v1, L_800CA4C8
    if (ctx->r4 != ctx->r3) {
        // 0x800CA4D8: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_800CA4C8;
    }
    // 0x800CA4D8: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x800CA4DC: jr          $ra
    // 0x800CA4E0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800CA4E0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800CA4E4:
    // 0x800CA4E4: beq         $v0, $zero, L_800CA548
    if (ctx->r2 == 0) {
        // 0x800CA4E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800CA548;
    }
    // 0x800CA4E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CA4EC: beq         $v0, $at, L_800CA52C
    if (ctx->r2 == ctx->r1) {
        // 0x800CA4F0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CA52C;
    }
    // 0x800CA4F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CA4F4: beql        $v0, $at, L_800CA518
    if (ctx->r2 == ctx->r1) {
        // 0x800CA4F8: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_800CA518;
    }
    goto skip_5;
    // 0x800CA4F8: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x800CA4FC: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800CA500: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CA504: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800CA508: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800CA50C: b           L_800CA548
    // 0x800CA510: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_800CA548;
    // 0x800CA510: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800CA514: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_800CA518:
    // 0x800CA518: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x800CA51C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800CA520: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800CA524: b           L_800CA548
    // 0x800CA528: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_800CA548;
    // 0x800CA528: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_800CA52C:
    // 0x800CA52C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800CA530: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x800CA534: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x800CA538: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x800CA53C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800CA540: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x800CA544: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_800CA548:
    // 0x800CA548: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800CA54C: bnel        $at, $zero, L_800CA5A8
    if (ctx->r1 != 0) {
        // 0x800CA550: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CA5A8;
    }
    goto skip_6;
    // 0x800CA550: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x800CA554: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CA558: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800CA55C: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800CA560: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800CA564: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x800CA568: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x800CA56C: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x800CA570: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x800CA574: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x800CA578: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x800CA57C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800CA580: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x800CA584: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x800CA588: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x800CA58C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x800CA590: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x800CA594: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800CA598: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800CA59C: b           L_800CA548
    // 0x800CA5A0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_800CA548;
    // 0x800CA5A0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_800CA5A4:
    // 0x800CA5A4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CA5A8:
    // 0x800CA5A8: bnel        $at, $zero, L_800CA5E4
    if (ctx->r1 != 0) {
        // 0x800CA5AC: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800CA5E4;
    }
    goto skip_7;
    // 0x800CA5AC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x800CA5B0: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CA5B4: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800CA5B8: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800CA5BC: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800CA5C0: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800CA5C4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x800CA5C8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800CA5CC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x800CA5D0: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x800CA5D4: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800CA5D8: b           L_800CA5A4
    // 0x800CA5DC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_800CA5A4;
    // 0x800CA5DC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_800CA5E0:
    // 0x800CA5E0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800CA5E4:
    // 0x800CA5E4: bne         $at, $zero, L_800CA4B4
    if (ctx->r1 != 0) {
        // 0x800CA5E8: nop
    
            goto L_800CA4B4;
    }
    // 0x800CA5E8: nop

    // 0x800CA5EC: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CA5F0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800CA5F4: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800CA5F8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800CA5FC: b           L_800CA5E0
    // 0x800CA600: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_800CA5E0;
    // 0x800CA600: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800CA604: nop

    // 0x800CA608: nop

    // 0x800CA60C: nop

;}
RECOMP_FUNC void alFilterNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA610: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800CA614: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800CA618: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800CA61C: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x800CA620: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x800CA624: jr          $ra
    // 0x800CA628: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    return;
    // 0x800CA628: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    // 0x800CA62C: nop

;}
RECOMP_FUNC void alEnvmixerPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA630: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800CA634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CA638: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800CA63C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800CA640: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800CA644: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800CA648: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800CA64C: nop

    // 0x800CA650: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x800CA654: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800CA658: nop

    // 0x800CA65C: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x800CA660: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800CA664: nop

    // 0x800CA668: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800CA66C: sh          $zero, 0x46($sp)
    MEM_H(0X46, ctx->r29) = 0;
    // 0x800CA670: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    // 0x800CA674: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA678: nop

    // 0x800CA67C: lw          $t0, 0x3C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X3C);
    // 0x800CA680: nop

    // 0x800CA684: beq         $t0, $zero, L_800CAF2C
    if (ctx->r8 == 0) {
        // 0x800CA688: nop
    
            goto L_800CAF2C;
    }
    // 0x800CA688: nop

L_800CA68C:
    // 0x800CA68C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800CA690: nop

    // 0x800CA694: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x800CA698: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA69C: nop

    // 0x800CA6A0: lw          $t3, 0x3C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X3C);
    // 0x800CA6A4: nop

    // 0x800CA6A8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800CA6AC: nop

    // 0x800CA6B0: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800CA6B4: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800CA6B8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800CA6BC: nop

    // 0x800CA6C0: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x800CA6C4: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800CA6C8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CA6CC: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x800CA6D0: nop

    // 0x800CA6D4: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800CA6D8: beq         $at, $zero, L_800CA6E8
    if (ctx->r1 == 0) {
        // 0x800CA6DC: nop
    
            goto L_800CA6E8;
    }
    // 0x800CA6DC: nop

    // 0x800CA6E0: b           L_800CAF2C
    // 0x800CA6E4: nop

        goto L_800CAF2C;
    // 0x800CA6E4: nop

L_800CA6E8:
    // 0x800CA6E8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800CA6EC: nop

    // 0x800CA6F0: bltz        $t0, L_800CA700
    if (SIGNED(ctx->r8) < 0) {
        // 0x800CA6F4: nop
    
            goto L_800CA700;
    }
    // 0x800CA6F4: nop

    // 0x800CA6F8: b           L_800CA718
    // 0x800CA6FC: nop

        goto L_800CA718;
    // 0x800CA6FC: nop

L_800CA700:
    // 0x800CA700: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CA704: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800CA708: addiu       $a1, $a1, -0x6510
    ctx->r5 = ADD32(ctx->r5, -0X6510);
    // 0x800CA70C: addiu       $a0, $a0, -0x6520
    ctx->r4 = ADD32(ctx->r4, -0X6520);
    // 0x800CA710: jal         0x800B74A0
    // 0x800CA714: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    __assert_recomp(rdram, ctx);
        goto after_0;
    // 0x800CA714: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    after_0:
L_800CA718:
    // 0x800CA718: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CA71C: nop

    // 0x800CA720: slti        $at, $t1, 0xA1
    ctx->r1 = SIGNED(ctx->r9) < 0XA1 ? 1 : 0;
    // 0x800CA724: beq         $at, $zero, L_800CA734
    if (ctx->r1 == 0) {
        // 0x800CA728: nop
    
            goto L_800CA734;
    }
    // 0x800CA728: nop

    // 0x800CA72C: b           L_800CA74C
    // 0x800CA730: nop

        goto L_800CA74C;
    // 0x800CA730: nop

L_800CA734:
    // 0x800CA734: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CA738: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800CA73C: addiu       $a1, $a1, -0x64E8
    ctx->r5 = ADD32(ctx->r5, -0X64E8);
    // 0x800CA740: addiu       $a0, $a0, -0x6508
    ctx->r4 = ADD32(ctx->r4, -0X6508);
    // 0x800CA744: jal         0x800B74A0
    // 0x800CA748: addiu       $a2, $zero, 0x69
    ctx->r6 = ADD32(0, 0X69);
    __assert_recomp(rdram, ctx);
        goto after_1;
    // 0x800CA748: addiu       $a2, $zero, 0x69
    ctx->r6 = ADD32(0, 0X69);
    after_1:
L_800CA74C:
    // 0x800CA74C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA750: nop

    // 0x800CA754: lw          $t3, 0x3C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X3C);
    // 0x800CA758: nop

    // 0x800CA75C: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x800CA760: nop

    // 0x800CA764: sltiu       $at, $t4, 0x11
    ctx->r1 = ctx->r12 < 0X11 ? 1 : 0;
    // 0x800CA768: beq         $at, $zero, L_800CAE24
    if (ctx->r1 == 0) {
        // 0x800CA76C: nop
    
            goto L_800CAE24;
    }
    // 0x800CA76C: nop

    // 0x800CA770: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800CA774: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CA778: addu        $at, $at, $t4
    gpr jr_addend_800CA784 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800CA77C: lw          $t4, -0x64D0($at)
    ctx->r12 = ADD32(ctx->r1, -0X64D0);
    // 0x800CA780: nop

    // 0x800CA784: jr          $t4
    // 0x800CA788: nop

    switch (jr_addend_800CA784 >> 2) {
        case 0: goto L_800CADD0; break;
        case 1: goto L_800CAE24; break;
        case 2: goto L_800CAE24; break;
        case 3: goto L_800CAE24; break;
        case 4: goto L_800CAE24; break;
        case 5: goto L_800CAE24; break;
        case 6: goto L_800CAE24; break;
        case 7: goto L_800CAE24; break;
        case 8: goto L_800CAE24; break;
        case 9: goto L_800CAE24; break;
        case 10: goto L_800CAE24; break;
        case 11: goto L_800CA9C0; break;
        case 12: goto L_800CA9C0; break;
        case 13: goto L_800CA78C; break;
        case 14: goto L_800CAD08; break;
        case 15: goto L_800CAD88; break;
        case 16: goto L_800CA9C0; break;
        default: switch_error(__func__, 0x800CA784, 0x800E9B30);
    }
    // 0x800CA788: nop

L_800CA78C:
    // 0x800CA78C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA790: nop

    // 0x800CA794: lw          $t6, 0x3C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X3C);
    // 0x800CA798: nop

    // 0x800CA79C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800CA7A0: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800CA7A4: nop

    // 0x800CA7A8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800CA7AC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800CA7B0: nop

    // 0x800CA7B4: lh          $t9, 0xA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XA);
    // 0x800CA7B8: nop

    // 0x800CA7BC: beq         $t9, $zero, L_800CA7DC
    if (ctx->r25 == 0) {
        // 0x800CA7C0: nop
    
            goto L_800CA7DC;
    }
    // 0x800CA7C0: nop

    // 0x800CA7C4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA7C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800CA7CC: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x800CA7D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA7D4: jalr        $t9
    // 0x800CA7D8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CA7D8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
L_800CA7DC:
    // 0x800CA7DC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CA7E0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800CA7E4: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x800CA7E8: lw          $a2, 0x18($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X18);
    // 0x800CA7EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800CA7F0: jalr        $t9
    // 0x800CA7F4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800CA7F4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
    // 0x800CA7F8: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CA7FC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CA800: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x800CA804: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA808: jalr        $t9
    // 0x800CA80C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800CA80C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_4:
    // 0x800CA810: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA814: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800CA818: sw          $t4, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r12;
    // 0x800CA81C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800CA820: nop

    // 0x800CA824: sw          $zero, 0x30($t6)
    MEM_W(0X30, ctx->r14) = 0;
    // 0x800CA828: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800CA82C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA830: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x800CA834: nop

    // 0x800CA838: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
    // 0x800CA83C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800CA840: nop

    // 0x800CA844: lh          $t1, 0x10($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X10);
    // 0x800CA848: nop

    // 0x800CA84C: addu        $t3, $t1, $t1
    ctx->r11 = ADD32(ctx->r9, ctx->r9);
    // 0x800CA850: bgez        $t3, L_800CA860
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800CA854: sra         $t9, $t3, 1
        ctx->r25 = S32(SIGNED(ctx->r11) >> 1);
            goto L_800CA860;
    }
    // 0x800CA854: sra         $t9, $t3, 1
    ctx->r25 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800CA858: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x800CA85C: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800CA860:
    // 0x800CA860: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800CA864: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800CA868: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA86C: nop

    // 0x800CA870: sh          $t4, 0x1A($t5)
    MEM_H(0X1A, ctx->r13) = ctx->r12;
    // 0x800CA874: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800CA878: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CA87C: lbu         $t7, 0x12($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X12);
    // 0x800CA880: nop

    // 0x800CA884: sh          $t7, 0x18($t8)
    MEM_H(0X18, ctx->r24) = ctx->r15;
    // 0x800CA888: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800CA88C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800CA890: lbu         $t2, 0x13($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X13);
    // 0x800CA894: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA898: sll         $t1, $t2, 1
    ctx->r9 = S32(ctx->r10 << 1);
    // 0x800CA89C: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x800CA8A0: lh          $t3, 0x3D30($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X3D30);
    // 0x800CA8A4: nop

    // 0x800CA8A8: sh          $t3, 0x20($t9)
    MEM_H(0X20, ctx->r25) = ctx->r11;
    // 0x800CA8AC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800CA8B0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800CA8B4: lbu         $t5, 0x13($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X13);
    // 0x800CA8B8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA8BC: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800CA8C0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800CA8C4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800CA8C8: lh          $t8, 0x3E2E($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X3E2E);
    // 0x800CA8CC: nop

    // 0x800CA8D0: sh          $t8, 0x22($t0)
    MEM_H(0X22, ctx->r8) = ctx->r24;
    // 0x800CA8D4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800CA8D8: nop

    // 0x800CA8DC: lw          $t1, 0x14($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X14);
    // 0x800CA8E0: nop

    // 0x800CA8E4: beq         $t1, $zero, L_800CA908
    if (ctx->r9 == 0) {
        // 0x800CA8E8: nop
    
            goto L_800CA908;
    }
    // 0x800CA8E8: nop

    // 0x800CA8EC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA8F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800CA8F4: sh          $t3, 0x1C($t9)
    MEM_H(0X1C, ctx->r25) = ctx->r11;
    // 0x800CA8F8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA8FC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800CA900: b           L_800CA96C
    // 0x800CA904: sh          $t4, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = ctx->r12;
        goto L_800CA96C;
    // 0x800CA904: sh          $t4, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = ctx->r12;
L_800CA908:
    // 0x800CA908: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800CA90C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800CA910: lh          $t7, 0x18($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X18);
    // 0x800CA914: lh          $t2, 0x1A($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X1A);
    // 0x800CA918: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800CA91C: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800CA920: lh          $t0, 0x3D30($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X3D30);
    // 0x800CA924: nop

    // 0x800CA928: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA92C: mflo        $t1
    ctx->r9 = lo;
    // 0x800CA930: sra         $t3, $t1, 15
    ctx->r11 = S32(SIGNED(ctx->r9) >> 15);
    // 0x800CA934: sh          $t3, 0x1C($t6)
    MEM_H(0X1C, ctx->r14) = ctx->r11;
    // 0x800CA938: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA93C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800CA940: lh          $t4, 0x18($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X18);
    // 0x800CA944: lh          $t0, 0x1A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X1A);
    // 0x800CA948: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800CA94C: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x800CA950: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800CA954: lh          $t8, 0x3E2E($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X3E2E);
    // 0x800CA958: nop

    // 0x800CA95C: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA960: mflo        $t2
    ctx->r10 = lo;
    // 0x800CA964: sra         $t1, $t2, 15
    ctx->r9 = S32(SIGNED(ctx->r10) >> 15);
    // 0x800CA968: sh          $t1, 0x1E($t9)
    MEM_H(0X1E, ctx->r25) = ctx->r9;
L_800CA96C:
    // 0x800CA96C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800CA970: nop

    // 0x800CA974: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800CA978: nop

    // 0x800CA97C: beq         $t6, $zero, L_800CA9B8
    if (ctx->r14 == 0) {
        // 0x800CA980: nop
    
            goto L_800CA9B8;
    }
    // 0x800CA980: nop

    // 0x800CA984: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800CA988: nop

    // 0x800CA98C: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800CA990: nop

    // 0x800CA994: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800CA998: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800CA99C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800CA9A0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800CA9A4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800CA9A8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x800CA9AC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800CA9B0: jalr        $t9
    // 0x800CA9B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x800CA9B4: nop

    after_5:
L_800CA9B8:
    // 0x800CA9B8: b           L_800CAE8C
    // 0x800CA9BC: nop

        goto L_800CAE8C;
    // 0x800CA9BC: nop

L_800CA9C0:
    // 0x800CA9C0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800CA9C4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800CA9C8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800CA9CC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800CA9D0: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x800CA9D4: addiu       $a2, $sp, 0x46
    ctx->r6 = ADD32(ctx->r29, 0X46);
    // 0x800CA9D8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800CA9DC: jal         0x800CB1BC
    // 0x800CA9E0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    static_0_800CB1BC(rdram, ctx);
        goto after_6;
    // 0x800CA9E0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_6:
    // 0x800CA9E4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CA9E8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA9EC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800CA9F0: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x800CA9F4: nop

    // 0x800CA9F8: addu        $t6, $t1, $t3
    ctx->r14 = ADD32(ctx->r9, ctx->r11);
    // 0x800CA9FC: sw          $t6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r14;
    // 0x800CAA00: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA04: nop

    // 0x800CAA08: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x800CAA0C: lw          $t7, 0x34($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X34);
    // 0x800CAA10: nop

    // 0x800CAA14: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800CAA18: bne         $at, $zero, L_800CAAC0
    if (ctx->r1 != 0) {
        // 0x800CAA1C: nop
    
            goto L_800CAAC0;
    }
    // 0x800CAA1C: nop

    // 0x800CAA20: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA24: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800CAA28: lh          $t8, 0x18($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X18);
    // 0x800CAA2C: lh          $t3, 0x1A($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X1A);
    // 0x800CAA30: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800CAA34: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800CAA38: lh          $t1, 0x3D30($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X3D30);
    // 0x800CAA3C: nop

    // 0x800CAA40: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CAA44: mflo        $t6
    ctx->r14 = lo;
    // 0x800CAA48: sra         $t2, $t6, 15
    ctx->r10 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800CAA4C: sh          $t2, 0x28($t9)
    MEM_H(0X28, ctx->r25) = ctx->r10;
    // 0x800CAA50: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA54: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800CAA58: lh          $t5, 0x18($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X18);
    // 0x800CAA5C: lh          $t1, 0x1A($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X1A);
    // 0x800CAA60: negu        $t7, $t5
    ctx->r15 = SUB32(0, ctx->r13);
    // 0x800CAA64: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800CAA68: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800CAA6C: lh          $t0, 0x3E2E($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X3E2E);
    // 0x800CAA70: nop

    // 0x800CAA74: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CAA78: mflo        $t3
    ctx->r11 = lo;
    // 0x800CAA7C: sra         $t6, $t3, 15
    ctx->r14 = S32(SIGNED(ctx->r11) >> 15);
    // 0x800CAA80: sh          $t6, 0x2E($t4)
    MEM_H(0X2E, ctx->r12) = ctx->r14;
    // 0x800CAA84: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA88: nop

    // 0x800CAA8C: lw          $t9, 0x34($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X34);
    // 0x800CAA90: nop

    // 0x800CAA94: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
    // 0x800CAA98: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA9C: nop

    // 0x800CAAA0: lh          $t7, 0x28($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X28);
    // 0x800CAAA4: nop

    // 0x800CAAA8: sh          $t7, 0x1C($t5)
    MEM_H(0X1C, ctx->r13) = ctx->r15;
    // 0x800CAAAC: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CAAB0: nop

    // 0x800CAAB4: lh          $t0, 0x2E($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X2E);
    // 0x800CAAB8: b           L_800CAB60
    // 0x800CAABC: sh          $t0, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = ctx->r8;
        goto L_800CAB60;
    // 0x800CAABC: sh          $t0, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = ctx->r8;
L_800CAAC0:
    // 0x800CAAC0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CAAC4: nop

    // 0x800CAAC8: lh          $t3, 0x1C($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X1C);
    // 0x800CAACC: lw          $a1, 0x30($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X30);
    // 0x800CAAD0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800CAAD4: lh          $a2, 0x26($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X26);
    // 0x800CAAD8: lhu         $a3, 0x24($t1)
    ctx->r7 = MEM_HU(ctx->r9, 0X24);
    // 0x800CAADC: jal         0x800CB9F8
    // 0x800CAAE0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    static_0_800CB9F8(rdram, ctx);
        goto after_7;
    // 0x800CAAE0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_7:
    // 0x800CAAE4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800CAAE8: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CAAEC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800CAAF0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CAAF4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CAAF8: nop

    // 0x800CAAFC: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800CAB00: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800CAB04: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800CAB08: sh          $t4, 0x1C($t9)
    MEM_H(0X1C, ctx->r25) = ctx->r12;
    // 0x800CAB0C: nop

    // 0x800CAB10: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CAB14: nop

    // 0x800CAB18: lh          $t7, 0x1E($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X1E);
    // 0x800CAB1C: lw          $a1, 0x30($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X30);
    // 0x800CAB20: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800CAB24: lh          $a2, 0x2C($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X2C);
    // 0x800CAB28: lhu         $a3, 0x2A($t2)
    ctx->r7 = MEM_HU(ctx->r10, 0X2A);
    // 0x800CAB2C: jal         0x800CB9F8
    // 0x800CAB30: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    static_0_800CB9F8(rdram, ctx);
        goto after_8;
    // 0x800CAB30: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_8:
    // 0x800CAB34: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800CAB38: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CAB3C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800CAB40: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CAB44: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CAB48: nop

    // 0x800CAB4C: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800CAB50: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x800CAB54: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800CAB58: sh          $t0, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = ctx->r8;
    // 0x800CAB5C: nop

L_800CAB60:
    // 0x800CAB60: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CAB64: nop

    // 0x800CAB68: lh          $t1, 0x1C($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X1C);
    // 0x800CAB6C: nop

    // 0x800CAB70: bne         $t1, $zero, L_800CAB84
    if (ctx->r9 != 0) {
        // 0x800CAB74: nop
    
            goto L_800CAB84;
    }
    // 0x800CAB74: nop

    // 0x800CAB78: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CAB7C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CAB80: sh          $t6, 0x1C($t4)
    MEM_H(0X1C, ctx->r12) = ctx->r14;
L_800CAB84:
    // 0x800CAB84: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CAB88: nop

    // 0x800CAB8C: lh          $t7, 0x1E($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X1E);
    // 0x800CAB90: nop

    // 0x800CAB94: bne         $t7, $zero, L_800CABA8
    if (ctx->r15 != 0) {
        // 0x800CAB98: nop
    
            goto L_800CABA8;
    }
    // 0x800CAB98: nop

    // 0x800CAB9C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CABA0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800CABA4: sh          $t2, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = ctx->r10;
L_800CABA8:
    // 0x800CABA8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CABAC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800CABB0: lw          $t8, 0x3C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X3C);
    // 0x800CABB4: nop

    // 0x800CABB8: lh          $t3, 0x8($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X8);
    // 0x800CABBC: nop

    // 0x800CABC0: bne         $t3, $at, L_800CABE4
    if (ctx->r11 != ctx->r1) {
        // 0x800CABC4: nop
    
            goto L_800CABE4;
    }
    // 0x800CABC4: nop

    // 0x800CABC8: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CABCC: nop

    // 0x800CABD0: lw          $t6, 0x3C($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X3C);
    // 0x800CABD4: nop

    // 0x800CABD8: lw          $t4, 0xC($t6)
    ctx->r12 = MEM_W(ctx->r14, 0XC);
    // 0x800CABDC: nop

    // 0x800CABE0: sh          $t4, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r12;
L_800CABE4:
    // 0x800CABE4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CABE8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800CABEC: lw          $t7, 0x3C($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X3C);
    // 0x800CABF0: nop

    // 0x800CABF4: lh          $t2, 0x8($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X8);
    // 0x800CABF8: nop

    // 0x800CABFC: bne         $t2, $at, L_800CAC78
    if (ctx->r10 != ctx->r1) {
        // 0x800CAC00: nop
    
            goto L_800CAC78;
    }
    // 0x800CAC00: nop

    // 0x800CAC04: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CAC08: nop

    // 0x800CAC0C: sw          $zero, 0x30($t5)
    MEM_W(0X30, ctx->r13) = 0;
    // 0x800CAC10: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CAC14: nop

    // 0x800CAC18: lw          $t8, 0x3C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X3C);
    // 0x800CAC1C: nop

    // 0x800CAC20: lw          $t3, 0xC($t8)
    ctx->r11 = MEM_W(ctx->r24, 0XC);
    // 0x800CAC24: nop

    // 0x800CAC28: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x800CAC2C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800CAC30: nop

    // 0x800CAC34: addu        $t4, $t6, $t6
    ctx->r12 = ADD32(ctx->r14, ctx->r14);
    // 0x800CAC38: bgez        $t4, L_800CAC48
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800CAC3C: sra         $t1, $t4, 1
        ctx->r9 = S32(SIGNED(ctx->r12) >> 1);
            goto L_800CAC48;
    }
    // 0x800CAC3C: sra         $t1, $t4, 1
    ctx->r9 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800CAC40: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x800CAC44: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_800CAC48:
    // 0x800CAC48: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x800CAC4C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800CAC50: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800CAC54: nop

    // 0x800CAC58: sh          $t9, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r25;
    // 0x800CAC5C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CAC60: nop

    // 0x800CAC64: lw          $t5, 0x3C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X3C);
    // 0x800CAC68: nop

    // 0x800CAC6C: lw          $t0, 0x10($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X10);
    // 0x800CAC70: nop

    // 0x800CAC74: sw          $t0, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r8;
L_800CAC78:
    // 0x800CAC78: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CAC7C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800CAC80: lw          $t3, 0x3C($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X3C);
    // 0x800CAC84: nop

    // 0x800CAC88: lh          $t6, 0x8($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X8);
    // 0x800CAC8C: nop

    // 0x800CAC90: bne         $t6, $at, L_800CACF4
    if (ctx->r14 != ctx->r1) {
        // 0x800CAC94: nop
    
            goto L_800CACF4;
    }
    // 0x800CAC94: nop

    // 0x800CAC98: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CAC9C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800CACA0: lw          $t1, 0x3C($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X3C);
    // 0x800CACA4: nop

    // 0x800CACA8: lw          $t9, 0xC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC);
    // 0x800CACAC: nop

    // 0x800CACB0: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x800CACB4: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x800CACB8: lh          $t5, 0x3D30($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X3D30);
    // 0x800CACBC: nop

    // 0x800CACC0: sh          $t5, 0x20($t4)
    MEM_H(0X20, ctx->r12) = ctx->r13;
    // 0x800CACC4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CACC8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800CACCC: lw          $t2, 0x3C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X3C);
    // 0x800CACD0: nop

    // 0x800CACD4: lw          $t8, 0xC($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XC);
    // 0x800CACD8: nop

    // 0x800CACDC: negu        $t3, $t8
    ctx->r11 = SUB32(0, ctx->r24);
    // 0x800CACE0: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800CACE4: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x800CACE8: lh          $t1, 0x3E2E($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X3E2E);
    // 0x800CACEC: nop

    // 0x800CACF0: sh          $t1, 0x22($t0)
    MEM_H(0X22, ctx->r8) = ctx->r9;
L_800CACF4:
    // 0x800CACF4: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800CACF8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800CACFC: sw          $t9, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r25;
    // 0x800CAD00: b           L_800CAE8C
    // 0x800CAD04: nop

        goto L_800CAE8C;
    // 0x800CAD04: nop

L_800CAD08:
    // 0x800CAD08: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CAD0C: nop

    // 0x800CAD10: lw          $t4, 0x3C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X3C);
    // 0x800CAD14: nop

    // 0x800CAD18: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800CAD1C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800CAD20: nop

    // 0x800CAD24: lh          $t8, 0xA($t2)
    ctx->r24 = MEM_H(ctx->r10, 0XA);
    // 0x800CAD28: nop

    // 0x800CAD2C: beq         $t8, $zero, L_800CAD4C
    if (ctx->r24 == 0) {
        // 0x800CAD30: nop
    
            goto L_800CAD4C;
    }
    // 0x800CAD30: nop

    // 0x800CAD34: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CAD38: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800CAD3C: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x800CAD40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CAD44: jalr        $t9
    // 0x800CAD48: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x800CAD48: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_9:
L_800CAD4C:
    // 0x800CAD4C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800CAD50: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800CAD54: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x800CAD58: lw          $a2, 0xC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XC);
    // 0x800CAD5C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800CAD60: jalr        $t9
    // 0x800CAD64: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x800CAD64: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_10:
    // 0x800CAD68: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CAD6C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CAD70: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x800CAD74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CAD78: jalr        $t9
    // 0x800CAD7C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x800CAD7C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_11:
    // 0x800CAD80: b           L_800CAE8C
    // 0x800CAD84: nop

        goto L_800CAE8C;
    // 0x800CAD84: nop

L_800CAD88:
    // 0x800CAD88: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800CAD8C: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800CAD90: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800CAD94: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800CAD98: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x800CAD9C: addiu       $a2, $sp, 0x46
    ctx->r6 = ADD32(ctx->r29, 0X46);
    // 0x800CADA0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CADA4: jal         0x800CB1BC
    // 0x800CADA8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    static_0_800CB1BC(rdram, ctx);
        goto after_12;
    // 0x800CADA8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_12:
    // 0x800CADAC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CADB0: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CADB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800CADB8: lw          $t9, 0x8($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X8);
    // 0x800CADBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CADC0: jalr        $t9
    // 0x800CADC4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x800CADC4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_13:
    // 0x800CADC8: b           L_800CAE8C
    // 0x800CADCC: nop

        goto L_800CAE8C;
    // 0x800CADCC: nop

L_800CADD0:
    // 0x800CADD0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800CADD4: lw          $t2, 0x3D10($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3D10);
    // 0x800CADD8: nop

    // 0x800CADDC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800CADE0: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CADE4: nop

    // 0x800CADE8: lw          $t3, 0x3C($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X3C);
    // 0x800CADEC: nop

    // 0x800CADF0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800CADF4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800CADF8: nop

    // 0x800CADFC: lw          $t6, 0xC($t1)
    ctx->r14 = MEM_W(ctx->r9, 0XC);
    // 0x800CAE00: nop

    // 0x800CAE04: sw          $zero, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = 0;
    // 0x800CAE08: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CAE0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800CAE10: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x800CAE14: jal         0x8006595C
    // 0x800CAE18: nop

    _freePVoice(rdram, ctx);
        goto after_14;
    // 0x800CAE18: nop

    after_14:
    // 0x800CAE1C: b           L_800CAE8C
    // 0x800CAE20: nop

        goto L_800CAE8C;
    // 0x800CAE20: nop

L_800CAE24:
    // 0x800CAE24: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800CAE28: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800CAE2C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800CAE30: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800CAE34: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x800CAE38: addiu       $a2, $sp, 0x46
    ctx->r6 = ADD32(ctx->r29, 0X46);
    // 0x800CAE3C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CAE40: jal         0x800CB1BC
    // 0x800CAE44: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    static_0_800CB1BC(rdram, ctx);
        goto after_15;
    // 0x800CAE44: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_15:
    // 0x800CAE48: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CAE4C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CAE50: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800CAE54: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x800CAE58: nop

    // 0x800CAE5C: addu        $t8, $t9, $t2
    ctx->r24 = ADD32(ctx->r25, ctx->r10);
    // 0x800CAE60: sw          $t8, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r24;
    // 0x800CAE64: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CAE68: nop

    // 0x800CAE6C: lw          $t1, 0x3C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X3C);
    // 0x800CAE70: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x800CAE74: lh          $a1, 0x8($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X8);
    // 0x800CAE78: lw          $a2, 0xC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XC);
    // 0x800CAE7C: jalr        $t9
    // 0x800CAE80: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_16;
    // 0x800CAE80: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_16:
    // 0x800CAE84: b           L_800CAE8C
    // 0x800CAE88: nop

        goto L_800CAE8C;
    // 0x800CAE88: nop

L_800CAE8C:
    // 0x800CAE8C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800CAE90: lh          $t6, 0x46($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X46);
    // 0x800CAE94: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x800CAE98: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x800CAE9C: sh          $t5, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r13;
    // 0x800CAEA0: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800CAEA4: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CAEA8: nop

    // 0x800CAEAC: subu        $t4, $t2, $t8
    ctx->r12 = SUB32(ctx->r10, ctx->r24);
    // 0x800CAEB0: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x800CAEB4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CAEB8: nop

    // 0x800CAEBC: lw          $t3, 0x3C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X3C);
    // 0x800CAEC0: nop

    // 0x800CAEC4: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800CAEC8: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CAECC: nop

    // 0x800CAED0: lw          $t0, 0x3C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X3C);
    // 0x800CAED4: nop

    // 0x800CAED8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800CAEDC: nop

    // 0x800CAEE0: sw          $t6, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r14;
    // 0x800CAEE4: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800CAEE8: nop

    // 0x800CAEEC: lw          $t5, 0x3C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X3C);
    // 0x800CAEF0: nop

    // 0x800CAEF4: bne         $t5, $zero, L_800CAF08
    if (ctx->r13 != 0) {
        // 0x800CAEF8: nop
    
            goto L_800CAF08;
    }
    // 0x800CAEF8: nop

    // 0x800CAEFC: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CAF00: nop

    // 0x800CAF04: sw          $zero, 0x40($t2)
    MEM_W(0X40, ctx->r10) = 0;
L_800CAF08:
    // 0x800CAF08: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800CAF0C: jal         0x800658DC
    // 0x800CAF10: nop

    __freeParam(rdram, ctx);
        goto after_17;
    // 0x800CAF10: nop

    after_17:
    // 0x800CAF14: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CAF18: nop

    // 0x800CAF1C: lw          $t4, 0x3C($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X3C);
    // 0x800CAF20: nop

    // 0x800CAF24: bne         $t4, $zero, L_800CA68C
    if (ctx->r12 != 0) {
        // 0x800CAF28: nop
    
            goto L_800CA68C;
    }
    // 0x800CAF28: nop

L_800CAF2C:
    // 0x800CAF2C: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CAF30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CAF34: lw          $t3, 0x48($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X48);
    // 0x800CAF38: nop

    // 0x800CAF3C: bne         $t3, $at, L_800CAF84
    if (ctx->r11 != ctx->r1) {
        // 0x800CAF40: nop
    
            goto L_800CAF84;
    }
    // 0x800CAF40: nop

    // 0x800CAF44: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800CAF48: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800CAF4C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800CAF50: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800CAF54: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x800CAF58: addiu       $a2, $sp, 0x46
    ctx->r6 = ADD32(ctx->r29, 0X46);
    // 0x800CAF5C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800CAF60: jal         0x800CB1BC
    // 0x800CAF64: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    static_0_800CB1BC(rdram, ctx);
        goto after_18;
    // 0x800CAF64: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_18:
    // 0x800CAF68: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CAF6C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CAF70: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800CAF74: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x800CAF78: nop

    // 0x800CAF7C: addu        $t2, $t7, $t5
    ctx->r10 = ADD32(ctx->r15, ctx->r13);
    // 0x800CAF80: sw          $t2, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r10;
L_800CAF84:
    // 0x800CAF84: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CAF88: nop

    // 0x800CAF8C: lw          $t4, 0x30($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X30);
    // 0x800CAF90: lw          $t1, 0x34($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X34);
    // 0x800CAF94: nop

    // 0x800CAF98: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800CAF9C: beq         $at, $zero, L_800CAFB8
    if (ctx->r1 == 0) {
        // 0x800CAFA0: nop
    
            goto L_800CAFB8;
    }
    // 0x800CAFA0: nop

    // 0x800CAFA4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CAFA8: nop

    // 0x800CAFAC: lw          $t0, 0x34($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X34);
    // 0x800CAFB0: nop

    // 0x800CAFB4: sw          $t0, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r8;
L_800CAFB8:
    // 0x800CAFB8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800CAFBC: b           L_800CAFCC
    // 0x800CAFC0: nop

        goto L_800CAFCC;
    // 0x800CAFC0: nop

    // 0x800CAFC4: b           L_800CAFCC
    // 0x800CAFC8: nop

        goto L_800CAFCC;
    // 0x800CAFC8: nop

L_800CAFCC:
    // 0x800CAFCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CAFD0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800CAFD4: jr          $ra
    // 0x800CAFD8: nop

    return;
    // 0x800CAFD8: nop

;}
RECOMP_FUNC void alEnvmixerParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAFDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CAFE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CAFE4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800CAFE8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800CAFEC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800CAFF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CAFF4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800CAFF8: nop

    // 0x800CAFFC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800CB000: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800CB004: nop

    // 0x800CB008: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800CB00C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800CB010: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CB014: beq         $s0, $at, L_800CB14C
    if (ctx->r16 == ctx->r1) {
        // 0x800CB018: nop
    
            goto L_800CB14C;
    }
    // 0x800CB018: nop

    // 0x800CB01C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CB020: beq         $s0, $at, L_800CB048
    if (ctx->r16 == ctx->r1) {
        // 0x800CB024: nop
    
            goto L_800CB048;
    }
    // 0x800CB024: nop

    // 0x800CB028: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CB02C: beq         $s0, $at, L_800CB09C
    if (ctx->r16 == ctx->r1) {
        // 0x800CB030: nop
    
            goto L_800CB09C;
    }
    // 0x800CB030: nop

    // 0x800CB034: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800CB038: beq         $s0, $at, L_800CB100
    if (ctx->r16 == ctx->r1) {
        // 0x800CB03C: nop
    
            goto L_800CB100;
    }
    // 0x800CB03C: nop

    // 0x800CB040: b           L_800CB164
    // 0x800CB044: nop

        goto L_800CB164;
    // 0x800CB044: nop

L_800CB048:
    // 0x800CB048: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800CB04C: nop

    // 0x800CB050: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x800CB054: nop

    // 0x800CB058: beq         $t9, $zero, L_800CB074
    if (ctx->r25 == 0) {
        // 0x800CB05C: nop
    
            goto L_800CB074;
    }
    // 0x800CB05C: nop

    // 0x800CB060: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800CB064: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800CB068: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x800CB06C: b           L_800CB084
    // 0x800CB070: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
        goto L_800CB084;
    // 0x800CB070: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
L_800CB074:
    // 0x800CB074: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800CB078: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800CB07C: nop

    // 0x800CB080: sw          $t3, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r11;
L_800CB084:
    // 0x800CB084: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800CB088: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800CB08C: nop

    // 0x800CB090: sw          $t5, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r13;
    // 0x800CB094: b           L_800CB19C
    // 0x800CB098: nop

        goto L_800CB19C;
    // 0x800CB098: nop

L_800CB09C:
    // 0x800CB09C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800CB0A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CB0A4: sw          $t7, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->r15;
    // 0x800CB0A8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800CB0AC: nop

    // 0x800CB0B0: sw          $zero, 0x48($t9)
    MEM_W(0X48, ctx->r25) = 0;
    // 0x800CB0B4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800CB0B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800CB0BC: sh          $t1, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r9;
    // 0x800CB0C0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB0C4: nop

    // 0x800CB0C8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800CB0CC: nop

    // 0x800CB0D0: beq         $t3, $zero, L_800CB0F8
    if (ctx->r11 == 0) {
        // 0x800CB0D4: nop
    
            goto L_800CB0F8;
    }
    // 0x800CB0D4: nop

    // 0x800CB0D8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB0DC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800CB0E0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800CB0E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800CB0E8: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x800CB0EC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800CB0F0: jalr        $t9
    // 0x800CB0F4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CB0F4: nop

    after_0:
L_800CB0F8:
    // 0x800CB0F8: b           L_800CB19C
    // 0x800CB0FC: nop

        goto L_800CB19C;
    // 0x800CB0FC: nop

L_800CB100:
    // 0x800CB100: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800CB104: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CB108: sw          $t6, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->r14;
    // 0x800CB10C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB110: nop

    // 0x800CB114: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x800CB118: nop

    // 0x800CB11C: beq         $t1, $zero, L_800CB144
    if (ctx->r9 == 0) {
        // 0x800CB120: nop
    
            goto L_800CB144;
    }
    // 0x800CB120: nop

    // 0x800CB124: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB128: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800CB12C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800CB130: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CB134: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x800CB138: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800CB13C: jalr        $t9
    // 0x800CB140: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CB140: nop

    after_1:
L_800CB144:
    // 0x800CB144: b           L_800CB19C
    // 0x800CB148: nop

        goto L_800CB19C;
    // 0x800CB148: nop

L_800CB14C:
    // 0x800CB14C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800CB150: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB154: nop

    // 0x800CB158: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800CB15C: b           L_800CB19C
    // 0x800CB160: nop

        goto L_800CB19C;
    // 0x800CB160: nop

L_800CB164:
    // 0x800CB164: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB168: nop

    // 0x800CB16C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800CB170: nop

    // 0x800CB174: beq         $t6, $zero, L_800CB19C
    if (ctx->r14 == 0) {
        // 0x800CB178: nop
    
            goto L_800CB19C;
    }
    // 0x800CB178: nop

    // 0x800CB17C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB180: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800CB184: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800CB188: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800CB18C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800CB190: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800CB194: jalr        $t9
    // 0x800CB198: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CB198: nop

    after_2:
L_800CB19C:
    // 0x800CB19C: b           L_800CB1AC
    // 0x800CB1A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CB1AC;
    // 0x800CB1A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CB1A4: b           L_800CB1AC
    // 0x800CB1A8: nop

        goto L_800CB1AC;
    // 0x800CB1A8: nop

L_800CB1AC:
    // 0x800CB1AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB1B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CB1B4: jr          $ra
    // 0x800CB1B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CB1B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CB1BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CB1C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CB1C4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800CB1C8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800CB1CC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800CB1D0: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800CB1D4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800CB1D8: nop

    // 0x800CB1DC: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800CB1E0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800CB1E4: nop

    // 0x800CB1E8: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800CB1EC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CB1F0: nop

    // 0x800CB1F4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800CB1F8: nop

    // 0x800CB1FC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800CB200: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800CB204: nop

    // 0x800CB208: bne         $t0, $zero, L_800CB21C
    if (ctx->r8 != 0) {
        // 0x800CB20C: nop
    
            goto L_800CB21C;
    }
    // 0x800CB20C: nop

    // 0x800CB210: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB214: b           L_800CB654
    // 0x800CB218: nop

        goto L_800CB654;
    // 0x800CB218: nop

L_800CB21C:
    // 0x800CB21C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800CB220: nop

    // 0x800CB224: beq         $t1, $zero, L_800CB234
    if (ctx->r9 == 0) {
        // 0x800CB228: nop
    
            goto L_800CB234;
    }
    // 0x800CB228: nop

    // 0x800CB22C: b           L_800CB24C
    // 0x800CB230: nop

        goto L_800CB24C;
    // 0x800CB230: nop

L_800CB234:
    // 0x800CB234: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CB238: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800CB23C: addiu       $a1, $a1, -0x64D8
    ctx->r5 = ADD32(ctx->r5, -0X64D8);
    // 0x800CB240: addiu       $a0, $a0, -0x64E0
    ctx->r4 = ADD32(ctx->r4, -0X64E0);
    // 0x800CB244: jal         0x800B74A0
    // 0x800CB248: addiu       $a2, $zero, 0x175
    ctx->r6 = ADD32(0, 0X175);
    __assert_recomp(rdram, ctx);
        goto after_3;
    // 0x800CB248: addiu       $a2, $zero, 0x175
    ctx->r6 = ADD32(0, 0X175);
    after_3:
L_800CB24C:
    // 0x800CB24C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800CB250: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800CB254: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800CB258: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x800CB25C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800CB260: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800CB264: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x800CB268: jalr        $t9
    // 0x800CB26C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800CB26C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_4:
    // 0x800CB270: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800CB274: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB278: nop

    // 0x800CB27C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800CB280: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800CB284: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800CB288: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800CB28C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800CB290: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800CB294: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CB298: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CB29C: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x800CB2A0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800CB2A4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CB2A8: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800CB2AC: lh          $t2, 0x0($t3)
    ctx->r10 = MEM_H(ctx->r11, 0X0);
    // 0x800CB2B0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800CB2B4: addiu       $t9, $t2, 0x440
    ctx->r25 = ADD32(ctx->r10, 0X440);
    // 0x800CB2B8: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800CB2BC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800CB2C0: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x800CB2C4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CB2C8: or          $t0, $t5, $t8
    ctx->r8 = ctx->r13 | ctx->r24;
    // 0x800CB2CC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800CB2D0: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB2D4: nop

    // 0x800CB2D8: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800CB2DC: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x800CB2E0: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800CB2E4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CB2E8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800CB2EC: lh          $t4, 0x0($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X0);
    // 0x800CB2F0: lui         $at, 0x808
    ctx->r1 = S32(0X808 << 16);
    // 0x800CB2F4: addiu       $t6, $t4, 0x580
    ctx->r14 = ADD32(ctx->r12, 0X580);
    // 0x800CB2F8: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CB2FC: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x800CB300: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800CB304: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CB308: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800CB30C: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800CB310: nop

    // 0x800CB314: addiu       $t9, $t1, 0x6C0
    ctx->r25 = ADD32(ctx->r9, 0X6C0);
    // 0x800CB318: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800CB31C: addiu       $t3, $t1, 0x800
    ctx->r11 = ADD32(ctx->r9, 0X800);
    // 0x800CB320: andi        $t2, $t3, 0xFFFF
    ctx->r10 = ctx->r11 & 0XFFFF;
    // 0x800CB324: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x800CB328: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x800CB32C: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x800CB330: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CB334: nop

    // 0x800CB338: lw          $t0, 0x38($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X38);
    // 0x800CB33C: nop

    // 0x800CB340: beq         $t0, $zero, L_800CB5E8
    if (ctx->r8 == 0) {
        // 0x800CB344: nop
    
            goto L_800CB5E8;
    }
    // 0x800CB344: nop

    // 0x800CB348: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800CB34C: nop

    // 0x800CB350: sw          $zero, 0x38($t3)
    MEM_W(0X38, ctx->r11) = 0;
    // 0x800CB354: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CB358: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800CB35C: lh          $t9, 0x18($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X18);
    // 0x800CB360: lh          $t6, 0x1A($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X1A);
    // 0x800CB364: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800CB368: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x800CB36C: lh          $t2, 0x3D30($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X3D30);
    // 0x800CB370: nop

    // 0x800CB374: multu       $t2, $t6
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CB378: mflo        $t7
    ctx->r15 = lo;
    // 0x800CB37C: sra         $t5, $t7, 15
    ctx->r13 = S32(SIGNED(ctx->r15) >> 15);
    // 0x800CB380: sh          $t5, 0x28($t1)
    MEM_H(0X28, ctx->r9) = ctx->r13;
    // 0x800CB384: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CB388: nop

    // 0x800CB38C: lh          $t0, 0x1C($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X1C);
    // 0x800CB390: lh          $t3, 0x28($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X28);
    // 0x800CB394: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x800CB398: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800CB39C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800CB3A0: addiu       $t4, $t8, 0x24
    ctx->r12 = ADD32(ctx->r24, 0X24);
    // 0x800CB3A4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800CB3A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800CB3AC: cvt.d.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.d = CVT_D_W(ctx->f4.u32l);
    // 0x800CB3B0: jal         0x800CB834
    // 0x800CB3B4: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    static_0_800CB834(rdram, ctx);
        goto after_5;
    // 0x800CB3B4: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    after_5:
    // 0x800CB3B8: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800CB3BC: nop

    // 0x800CB3C0: sh          $v0, 0x26($t2)
    MEM_H(0X26, ctx->r10) = ctx->r2;
    // 0x800CB3C4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800CB3C8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800CB3CC: lh          $t7, 0x18($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X18);
    // 0x800CB3D0: lh          $t3, 0x1A($t6)
    ctx->r11 = MEM_H(ctx->r14, 0X1A);
    // 0x800CB3D4: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800CB3D8: sll         $t1, $t5, 1
    ctx->r9 = S32(ctx->r13 << 1);
    // 0x800CB3DC: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800CB3E0: lh          $t0, 0x3E2E($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X3E2E);
    // 0x800CB3E4: nop

    // 0x800CB3E8: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CB3EC: mflo        $t9
    ctx->r25 = lo;
    // 0x800CB3F0: sra         $t8, $t9, 15
    ctx->r24 = S32(SIGNED(ctx->r25) >> 15);
    // 0x800CB3F4: sh          $t8, 0x2E($t6)
    MEM_H(0X2E, ctx->r14) = ctx->r24;
    // 0x800CB3F8: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800CB3FC: nop

    // 0x800CB400: lh          $t2, 0x1E($t4)
    ctx->r10 = MEM_H(ctx->r12, 0X1E);
    // 0x800CB404: lh          $t7, 0x2E($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X2E);
    // 0x800CB408: lw          $t5, 0x34($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34);
    // 0x800CB40C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800CB410: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800CB414: addiu       $t1, $t4, 0x2A
    ctx->r9 = ADD32(ctx->r12, 0X2A);
    // 0x800CB418: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800CB41C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800CB420: cvt.d.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.d = CVT_D_W(ctx->f8.u32l);
    // 0x800CB424: jal         0x800CB834
    // 0x800CB428: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    static_0_800CB834(rdram, ctx);
        goto after_6;
    // 0x800CB428: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    after_6:
    // 0x800CB42C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800CB430: nop

    // 0x800CB434: sh          $v0, 0x2C($t0)
    MEM_H(0X2C, ctx->r8) = ctx->r2;
    // 0x800CB438: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB43C: nop

    // 0x800CB440: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x800CB444: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800CB448: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x800CB44C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CB450: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800CB454: lh          $t6, 0x1C($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X1C);
    // 0x800CB458: lui         $at, 0x906
    ctx->r1 = S32(0X906 << 16);
    // 0x800CB45C: andi        $t2, $t6, 0xFFFF
    ctx->r10 = ctx->r14 & 0XFFFF;
    // 0x800CB460: or          $t7, $t2, $at
    ctx->r15 = ctx->r10 | ctx->r1;
    // 0x800CB464: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800CB468: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800CB46C: nop

    // 0x800CB470: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800CB474: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB478: nop

    // 0x800CB47C: addiu       $t0, $t1, 0x8
    ctx->r8 = ADD32(ctx->r9, 0X8);
    // 0x800CB480: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800CB484: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800CB488: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800CB48C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800CB490: lh          $t9, 0x1E($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X1E);
    // 0x800CB494: lui         $at, 0x904
    ctx->r1 = S32(0X904 << 16);
    // 0x800CB498: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800CB49C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800CB4A0: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800CB4A4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800CB4A8: nop

    // 0x800CB4AC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800CB4B0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB4B4: nop

    // 0x800CB4B8: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x800CB4BC: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800CB4C0: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800CB4C4: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CB4C8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800CB4CC: lh          $t0, 0x28($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X28);
    // 0x800CB4D0: lui         $at, 0x902
    ctx->r1 = S32(0X902 << 16);
    // 0x800CB4D4: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x800CB4D8: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x800CB4DC: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x800CB4E0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800CB4E4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800CB4E8: lh          $t2, 0x26($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X26);
    // 0x800CB4EC: lhu         $t4, 0x24($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X24);
    // 0x800CB4F0: andi        $t7, $t2, 0xFFFF
    ctx->r15 = ctx->r10 & 0XFFFF;
    // 0x800CB4F4: sll         $t5, $t7, 16
    ctx->r13 = S32(ctx->r15 << 16);
    // 0x800CB4F8: andi        $t1, $t4, 0xFFFF
    ctx->r9 = ctx->r12 & 0XFFFF;
    // 0x800CB4FC: or          $t0, $t5, $t1
    ctx->r8 = ctx->r13 | ctx->r9;
    // 0x800CB500: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x800CB504: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB508: nop

    // 0x800CB50C: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800CB510: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800CB514: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800CB518: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800CB51C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB520: lh          $t7, 0x2E($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X2E);
    // 0x800CB524: lui         $at, 0x900
    ctx->r1 = S32(0X900 << 16);
    // 0x800CB528: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800CB52C: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x800CB530: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800CB534: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CB538: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB53C: lh          $t0, 0x2C($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X2C);
    // 0x800CB540: lhu         $t8, 0x2A($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X2A);
    // 0x800CB544: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x800CB548: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x800CB54C: andi        $t2, $t8, 0xFFFF
    ctx->r10 = ctx->r24 & 0XFFFF;
    // 0x800CB550: or          $t7, $t9, $t2
    ctx->r15 = ctx->r25 | ctx->r10;
    // 0x800CB554: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800CB558: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB55C: nop

    // 0x800CB560: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800CB564: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800CB568: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800CB56C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800CB570: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800CB574: lh          $t3, 0x20($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X20);
    // 0x800CB578: lui         $at, 0x908
    ctx->r1 = S32(0X908 << 16);
    // 0x800CB57C: andi        $t1, $t3, 0xFFFF
    ctx->r9 = ctx->r11 & 0XFFFF;
    // 0x800CB580: or          $t8, $t1, $at
    ctx->r24 = ctx->r9 | ctx->r1;
    // 0x800CB584: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800CB588: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800CB58C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800CB590: lh          $t7, 0x22($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X22);
    // 0x800CB594: nop

    // 0x800CB598: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800CB59C: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800CB5A0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB5A4: nop

    // 0x800CB5A8: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800CB5AC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800CB5B0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800CB5B4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800CB5B8: lui         $t3, 0x309
    ctx->r11 = S32(0X309 << 16);
    // 0x800CB5BC: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x800CB5C0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CB5C4: nop

    // 0x800CB5C8: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x800CB5CC: jal         0x800C9250
    // 0x800CB5D0: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_7;
    // 0x800CB5D0: nop

    after_7:
    // 0x800CB5D4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800CB5D8: nop

    // 0x800CB5DC: sw          $v0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r2;
    // 0x800CB5E0: b           L_800CB628
    // 0x800CB5E4: nop

        goto L_800CB628;
    // 0x800CB5E4: nop

L_800CB5E8:
    // 0x800CB5E8: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB5EC: nop

    // 0x800CB5F0: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x800CB5F4: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x800CB5F8: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800CB5FC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800CB600: lui         $t6, 0x308
    ctx->r14 = S32(0X308 << 16);
    // 0x800CB604: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800CB608: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800CB60C: nop

    // 0x800CB610: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    // 0x800CB614: jal         0x800C9250
    // 0x800CB618: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_8;
    // 0x800CB618: nop

    after_8:
    // 0x800CB61C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CB620: nop

    // 0x800CB624: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
L_800CB628:
    // 0x800CB628: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800CB62C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800CB630: lh          $t1, 0x0($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X0);
    // 0x800CB634: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800CB638: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x800CB63C: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x800CB640: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB644: b           L_800CB654
    // 0x800CB648: nop

        goto L_800CB654;
    // 0x800CB648: nop

    // 0x800CB64C: b           L_800CB654
    // 0x800CB650: nop

        goto L_800CB654;
    // 0x800CB650: nop

L_800CB654:
    // 0x800CB654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB658: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800CB65C: jr          $ra
    // 0x800CB660: nop

    return;
    // 0x800CB660: nop

;}
RECOMP_FUNC void _frexpf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB664: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800CB668: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800CB66C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800CB670: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CB674: nop

    // 0x800CB678: c.eq.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d == ctx->f4.d;
    // 0x800CB67C: nop

    // 0x800CB680: bc1f        L_800CB690
    if (!c1cs) {
        // 0x800CB684: nop
    
            goto L_800CB690;
    }
    // 0x800CB684: nop

    // 0x800CB688: b           L_800CB7E0
    // 0x800CB68C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800CB7E0;
    // 0x800CB68C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
L_800CB690:
    // 0x800CB690: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800CB694: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CB698: nop

    // 0x800CB69C: c.lt.d      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.d < ctx->f12.d;
    // 0x800CB6A0: nop

    // 0x800CB6A4: bc1f        L_800CB6B8
    if (!c1cs) {
        // 0x800CB6A8: nop
    
            goto L_800CB6B8;
    }
    // 0x800CB6A8: nop

    // 0x800CB6AC: swc1        $f13, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    // 0x800CB6B0: b           L_800CB6C4
    // 0x800CB6B4: swc1        $f12, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f12.u32l;
        goto L_800CB6C4;
    // 0x800CB6B4: swc1        $f12, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f12.u32l;
L_800CB6B8:
    // 0x800CB6B8: neg.d       $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = -ctx->f12.d;
    // 0x800CB6BC: swc1        $f8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f8.u32l;
    // 0x800CB6C0: swc1        $f9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
L_800CB6C4:
    // 0x800CB6C4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CB6C8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CB6CC: lwc1        $f11, 0x8($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB6D0: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB6D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CB6D8: nop

    // 0x800CB6DC: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x800CB6E0: nop

    // 0x800CB6E4: bc1f        L_800CB734
    if (!c1cs) {
        // 0x800CB6E8: nop
    
            goto L_800CB734;
    }
    // 0x800CB6E8: nop

L_800CB6EC:
    // 0x800CB6EC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800CB6F0: nop

    // 0x800CB6F4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800CB6F8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800CB6FC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CB700: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800CB704: lwc1        $f19, 0x8($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB708: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB70C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CB710: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CB714: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800CB718: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800CB71C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CB720: nop

    // 0x800CB724: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x800CB728: swc1        $f6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f6.u32l;
    // 0x800CB72C: bc1t        L_800CB6EC
    if (c1cs) {
        // 0x800CB730: swc1        $f7, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
            goto L_800CB6EC;
    }
    // 0x800CB730: swc1        $f7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
L_800CB734:
    // 0x800CB734: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CB738: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CB73C: lwc1        $f11, 0x8($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB740: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB744: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CB748: nop

    // 0x800CB74C: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x800CB750: nop

    // 0x800CB754: bc1f        L_800CB794
    if (!c1cs) {
        // 0x800CB758: nop
    
            goto L_800CB794;
    }
    // 0x800CB758: nop

L_800CB75C:
    // 0x800CB75C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800CB760: nop

    // 0x800CB764: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800CB768: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CB76C: lwc1        $f19, 0x8($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB770: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB774: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CB778: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CB77C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CB780: add.d       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f18.d + ctx->f18.d;
    // 0x800CB784: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800CB788: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x800CB78C: bc1t        L_800CB75C
    if (c1cs) {
        // 0x800CB790: swc1        $f5, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
            goto L_800CB75C;
    }
    // 0x800CB790: swc1        $f5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
L_800CB794:
    // 0x800CB794: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800CB798: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CB79C: nop

    // 0x800CB7A0: c.lt.d      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.d < ctx->f12.d;
    // 0x800CB7A4: nop

    // 0x800CB7A8: bc1f        L_800CB7C0
    if (!c1cs) {
        // 0x800CB7AC: nop
    
            goto L_800CB7C0;
    }
    // 0x800CB7AC: nop

    // 0x800CB7B0: lwc1        $f15, 0x8($sp)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB7B4: lwc1        $f14, 0xC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB7B8: b           L_800CB7D0
    // 0x800CB7BC: nop

        goto L_800CB7D0;
    // 0x800CB7BC: nop

L_800CB7C0:
    // 0x800CB7C0: lwc1        $f15, 0x8($sp)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB7C4: lwc1        $f14, 0xC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB7C8: nop

    // 0x800CB7CC: neg.d       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f14.d = -ctx->f14.d;
L_800CB7D0:
    // 0x800CB7D0: b           L_800CB7E0
    // 0x800CB7D4: mov.d       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.d = ctx->f14.d;
        goto L_800CB7E0;
    // 0x800CB7D4: mov.d       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.d = ctx->f14.d;
    // 0x800CB7D8: b           L_800CB7E0
    // 0x800CB7DC: nop

        goto L_800CB7E0;
    // 0x800CB7DC: nop

L_800CB7E0:
    // 0x800CB7E0: jr          $ra
    // 0x800CB7E4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800CB7E4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void _ldexpf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB7E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CB7EC: beq         $a2, $zero, L_800CB81C
    if (ctx->r6 == 0) {
        // 0x800CB7F0: nop
    
            goto L_800CB81C;
    }
    // 0x800CB7F0: nop

    // 0x800CB7F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CB7F8: sllv        $t7, $t6, $a2
    ctx->r15 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x800CB7FC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800CB800: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800CB804: nop

    // 0x800CB808: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800CB80C: nop

    // 0x800CB810: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800CB814: mul.d       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x800CB818: nop

L_800CB81C:
    // 0x800CB81C: b           L_800CB82C
    // 0x800CB820: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800CB82C;
    // 0x800CB820: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800CB824: b           L_800CB82C
    // 0x800CB828: nop

        goto L_800CB82C;
    // 0x800CB828: nop

L_800CB82C:
    // 0x800CB82C: jr          $ra
    // 0x800CB830: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CB830: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800CB834: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800CB838: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CB83C: nop

    // 0x800CB840: bne         $t6, $zero, L_800CB888
    if (ctx->r14 != 0) {
        // 0x800CB844: nop
    
            goto L_800CB888;
    }
    // 0x800CB844: nop

    // 0x800CB848: c.le.d      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.d <= ctx->f14.d;
    // 0x800CB84C: nop

    // 0x800CB850: bc1f        L_800CB874
    if (!c1cs) {
        // 0x800CB854: nop
    
            goto L_800CB874;
    }
    // 0x800CB854: nop

    // 0x800CB858: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800CB85C: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x800CB860: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800CB864: b           L_800CB9F0
    // 0x800CB868: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_800CB9F0;
    // 0x800CB868: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x800CB86C: b           L_800CB888
    // 0x800CB870: nop

        goto L_800CB888;
    // 0x800CB870: nop

L_800CB874:
    // 0x800CB874: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800CB878: nop

    // 0x800CB87C: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x800CB880: b           L_800CB9F0
    // 0x800CB884: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
        goto L_800CB9F0;
    // 0x800CB884: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
L_800CB888:
    // 0x800CB888: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CB88C: sub.d       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f14.d - ctx->f12.d;
    // 0x800CB890: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800CB894: nop

    // 0x800CB898: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CB89C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800CB8A0: nop

    // 0x800CB8A4: div.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800CB8A8: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
    // 0x800CB8AC: swc1        $f17, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800CB8B0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800CB8B4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CB8B8: lwc1        $f19, 0x0($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB8BC: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB8C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CB8C4: nop

    // 0x800CB8C8: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x800CB8CC: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x800CB8D0: swc1        $f9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800CB8D4: lwc1        $f5, 0x0($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB8D8: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB8DC: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800CB8E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800CB8E4: nop

    // 0x800CB8E8: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x800CB8EC: nop

    // 0x800CB8F0: bc1f        L_800CB91C
    if (!c1cs) {
        // 0x800CB8F4: nop
    
            goto L_800CB91C;
    }
    // 0x800CB8F4: nop

    // 0x800CB8F8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CB8FC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800CB900: lwc1        $f17, 0x0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB904: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB908: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800CB90C: nop

    // 0x800CB910: sub.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f16.d - ctx->f18.d;
    // 0x800CB914: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x800CB918: swc1        $f7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
L_800CB91C:
    // 0x800CB91C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800CB920: lwc1        $f9, 0x0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB924: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800CB928: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CB92C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CB930: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB934: nop

    // 0x800CB938: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x800CB93C: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800CB940: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800CB944: sh          $t2, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r10;
    // 0x800CB948: nop

    // 0x800CB94C: lh          $t3, 0xE($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XE);
    // 0x800CB950: lwc1        $f11, 0x0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB954: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800CB958: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB95C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CB960: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB964: lwc1        $f5, -0x6488($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X6488);
    // 0x800CB968: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x800CB96C: lwc1        $f4, -0x6484($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6484);
    // 0x800CB970: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x800CB974: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800CB978: mul.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x800CB97C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800CB980: nop

    // 0x800CB984: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800CB988: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CB98C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CB990: nop

    // 0x800CB994: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x800CB998: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800CB99C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800CB9A0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800CB9A4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CB9A8: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800CB9AC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800CB9B0: lwc1        $f11, 0x0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB9B4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800CB9B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CB9BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CB9C0: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB9C4: nop

    // 0x800CB9C8: cvt.w.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_D(ctx->f10.d);
    // 0x800CB9CC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800CB9D0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800CB9D4: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x800CB9D8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800CB9DC: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800CB9E0: b           L_800CB9F0
    // 0x800CB9E4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800CB9F0;
    // 0x800CB9E4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CB9E8: b           L_800CB9F0
    // 0x800CB9EC: nop

        goto L_800CB9F0;
    // 0x800CB9EC: nop

L_800CB9F0:
    // 0x800CB9F0: jr          $ra
    // 0x800CB9F4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800CB9F4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800CB9F8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800CB9FC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800CBA00: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CBA04: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x800CBA08: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800CBA0C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800CBA10: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800CBA14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CBA18: bgez        $a3, L_800CBA30
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800CBA1C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800CBA30;
    }
    // 0x800CBA1C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CBA20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CBA24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800CBA28: nop

    // 0x800CBA2C: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800CBA30:
    // 0x800CBA30: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CBA34: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x800CBA38: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800CBA3C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CBA40: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800CBA44: nop

    // 0x800CBA48: div.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x800CBA4C: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x800CBA50: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x800CBA54: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800CBA58: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CBA5C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CBA60: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800CBA64: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CBA68: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800CBA6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CBA70: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x800CBA74: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800CBA78: nop

    // 0x800CBA7C: div.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f6.d);
    // 0x800CBA80: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x800CBA84: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x800CBA88: b           L_800CBA98
    // 0x800CBA8C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800CBA98;
    // 0x800CBA8C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800CBA90: b           L_800CBA98
    // 0x800CBA94: nop

        goto L_800CBA98;
    // 0x800CBA94: nop

L_800CBA98:
    // 0x800CBA98: jr          $ra
    // 0x800CBA9C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CBA9C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void alLoadParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBAA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CBAA4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CBAA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CBAAC: beq         $a1, $at, L_800CBC04
    if (ctx->r5 == ctx->r1) {
        // 0x800CBAB0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800CBC04;
    }
    // 0x800CBAB0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CBAB4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800CBAB8: bnel        $a1, $at, L_800CBC68
    if (ctx->r5 != ctx->r1) {
        // 0x800CBABC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CBC68;
    }
    goto skip_0;
    // 0x800CBABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CBAC0: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x800CBAC4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800CBAC8: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x800CBACC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CBAD0: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x800CBAD4: lbu         $v0, 0x8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X8);
    // 0x800CBAD8: beql        $v0, $zero, L_800CBAF8
    if (ctx->r2 == 0) {
        // 0x800CBADC: lw          $v0, 0x28($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X28);
            goto L_800CBAF8;
    }
    goto skip_1;
    // 0x800CBADC: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    skip_1:
    // 0x800CBAE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CBAE4: beq         $v0, $a0, L_800CBBB8
    if (ctx->r2 == ctx->r4) {
        // 0x800CBAE8: lui         $t0, 0x800D
        ctx->r8 = S32(0X800D << 16);
            goto L_800CBBB8;
    }
    // 0x800CBAE8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800CBAEC: b           L_800CBC68
    // 0x800CBAF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CBC68;
    // 0x800CBAF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CBAF4: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
L_800CBAF8:
    // 0x800CBAF8: addiu       $t7, $t7, -0x3EB4
    ctx->r15 = ADD32(ctx->r15, -0X3EB4);
    // 0x800CBAFC: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800CBB00: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800CBB04: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CBB08: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x800CBB0C: mflo        $t9
    ctx->r25 = lo;
    // 0x800CBB10: bne         $a1, $zero, L_800CBB1C
    if (ctx->r5 != 0) {
        // 0x800CBB14: nop
    
            goto L_800CBB1C;
    }
    // 0x800CBB14: nop

    // 0x800CBB18: break       7
    do_break(2148317976);
L_800CBB1C:
    // 0x800CBB1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CBB20: bne         $a1, $at, L_800CBB34
    if (ctx->r5 != ctx->r1) {
        // 0x800CBB24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CBB34;
    }
    // 0x800CBB24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CBB28: bne         $t8, $at, L_800CBB34
    if (ctx->r24 != ctx->r1) {
        // 0x800CBB2C: nop
    
            goto L_800CBB34;
    }
    // 0x800CBB2C: nop

    // 0x800CBB30: break       6
    do_break(2148318000);
L_800CBB34:
    // 0x800CBB34: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CBB38: mflo        $t0
    ctx->r8 = lo;
    // 0x800CBB3C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800CBB40: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800CBB44: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800CBB48: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800CBB4C: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x800CBB50: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800CBB54: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CBB58: mflo        $t4
    ctx->r12 = lo;
    // 0x800CBB5C: sw          $t4, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r12;
    // 0x800CBB60: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CBB64: beql        $v1, $zero, L_800CBBAC
    if (ctx->r3 == 0) {
        // 0x800CBB68: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800CBBAC;
    }
    goto skip_2;
    // 0x800CBB68: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_2:
    // 0x800CBB6C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800CBB70: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    // 0x800CBB74: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800CBB78: sw          $t5, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r13;
    // 0x800CBB7C: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800CBB80: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800CBB84: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x800CBB88: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800CBB8C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800CBB90: sw          $t9, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r25;
    // 0x800CBB94: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800CBB98: jal         0x800D3D80
    // 0x800CBB9C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    alCopy(rdram, ctx);
        goto after_0;
    // 0x800CBB9C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800CBBA0: b           L_800CBC68
    // 0x800CBBA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CBC68;
    // 0x800CBBA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CBBA8: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800CBBAC:
    // 0x800CBBAC: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800CBBB0: b           L_800CBC64
    // 0x800CBBB4: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800CBC64;
    // 0x800CBBB4: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800CBBB8:
    // 0x800CBBB8: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800CBBBC: addiu       $t0, $t0, -0x438C
    ctx->r8 = ADD32(ctx->r8, -0X438C);
    // 0x800CBBC0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x800CBBC4: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CBBC8: beql        $v1, $zero, L_800CBBF8
    if (ctx->r3 == 0) {
        // 0x800CBBCC: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800CBBF8;
    }
    goto skip_3;
    // 0x800CBBCC: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_3:
    // 0x800CBBD0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800CBBD4: sw          $t1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r9;
    // 0x800CBBD8: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800CBBDC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800CBBE0: sw          $t3, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r11;
    // 0x800CBBE4: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800CBBE8: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800CBBEC: b           L_800CBC64
    // 0x800CBBF0: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
        goto L_800CBC64;
    // 0x800CBBF0: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
    // 0x800CBBF4: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800CBBF8:
    // 0x800CBBF8: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800CBBFC: b           L_800CBC64
    // 0x800CBC00: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800CBC64;
    // 0x800CBC00: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800CBC04:
    // 0x800CBC04: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800CBC08: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CBC0C: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x800CBC10: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x800CBC14: beq         $v0, $zero, L_800CBC64
    if (ctx->r2 == 0) {
        // 0x800CBC18: sw          $zero, 0x38($a3)
        MEM_W(0X38, ctx->r7) = 0;
            goto L_800CBC64;
    }
    // 0x800CBC18: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x800CBC1C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800CBC20: sw          $t6, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r14;
    // 0x800CBC24: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x800CBC28: bne         $v1, $zero, L_800CBC48
    if (ctx->r3 != 0) {
        // 0x800CBC2C: nop
    
            goto L_800CBC48;
    }
    // 0x800CBC2C: nop

    // 0x800CBC30: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CBC34: beql        $v1, $zero, L_800CBC68
    if (ctx->r3 == 0) {
        // 0x800CBC38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CBC68;
    }
    goto skip_4;
    // 0x800CBC38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800CBC3C: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800CBC40: b           L_800CBC64
    // 0x800CBC44: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
        goto L_800CBC64;
    // 0x800CBC44: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
L_800CBC48:
    // 0x800CBC48: bnel        $a0, $v1, L_800CBC68
    if (ctx->r4 != ctx->r3) {
        // 0x800CBC4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CBC68;
    }
    goto skip_5;
    // 0x800CBC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800CBC50: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CBC54: beql        $v1, $zero, L_800CBC68
    if (ctx->r3 == 0) {
        // 0x800CBC58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CBC68;
    }
    goto skip_6;
    // 0x800CBC58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x800CBC5C: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800CBC60: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
L_800CBC64:
    // 0x800CBC64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CBC68:
    // 0x800CBC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CBC6C: jr          $ra
    // 0x800CBC70: nop

    return;
    // 0x800CBC70: nop

;}
RECOMP_FUNC void alRaw16Pull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBC74: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CBC78: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800CBC7C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CBC80: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CBC84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CBC88: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800CBC8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CBC90: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CBC94: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CBC98: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800CBC9C: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x800CBCA0: bne         $a2, $zero, L_800CBCB0
    if (ctx->r6 != 0) {
        // 0x800CBCA4: or          $t1, $t0, $zero
        ctx->r9 = ctx->r8 | 0;
            goto L_800CBCB0;
    }
    // 0x800CBCA4: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800CBCA8: b           L_800CC004
    // 0x800CBCAC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800CC004;
    // 0x800CBCAC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800CBCB0:
    // 0x800CBCB0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800CBCB4: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x800CBCB8: addu        $t6, $v0, $s3
    ctx->r14 = ADD32(ctx->r2, ctx->r19);
    // 0x800CBCBC: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x800CBCC0: beql        $at, $zero, L_800CBED4
    if (ctx->r1 == 0) {
        // 0x800CBCC4: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800CBED4;
    }
    goto skip_0;
    // 0x800CBCC4: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x800CBCC8: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800CBCCC: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // 0x800CBCD0: beql        $t7, $zero, L_800CBED4
    if (ctx->r15 == 0) {
        // 0x800CBCD4: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800CBED4;
    }
    goto skip_1;
    // 0x800CBCD4: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x800CBCD8: blez        $s2, L_800CBD54
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800CBCDC: sll         $s1, $s2, 1
        ctx->r17 = S32(ctx->r18 << 1);
            goto L_800CBD54;
    }
    // 0x800CBCDC: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x800CBCE0: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800CBCE4: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800CBCE8: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800CBCEC: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800CBCF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CBCF4: jalr        $t9
    // 0x800CBCF8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CBCF8: nop

    after_0:
    // 0x800CBCFC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800CBD00: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800CBD04: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800CBD08: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x800CBD0C: addu        $a3, $s1, $a2
    ctx->r7 = ADD32(ctx->r17, ctx->r6);
    // 0x800CBD10: andi        $t5, $a3, 0x7
    ctx->r13 = ctx->r7 & 0X7;
    // 0x800CBD14: subu        $t6, $a3, $t5
    ctx->r14 = SUB32(ctx->r7, ctx->r13);
    // 0x800CBD18: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CBD1C: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x800CBD20: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800CBD24: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800CBD28: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800CBD2C: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800CBD30: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CBD34: subu        $t3, $v0, $a2
    ctx->r11 = SUB32(ctx->r2, ctx->r6);
    // 0x800CBD38: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800CBD3C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800CBD40: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800CBD44: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x800CBD48: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CBD4C: b           L_800CBD58
    // 0x800CBD50: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800CBD58;
    // 0x800CBD50: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800CBD54:
    // 0x800CBD54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CBD58:
    // 0x800CBD58: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x800CBD5C: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800CBD60: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800CBD64: sh          $t5, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r13;
    // 0x800CBD68: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x800CBD6C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800CBD70: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800CBD74: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800CBD78: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800CBD7C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800CBD80: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
    // 0x800CBD84: beq         $at, $zero, L_800CBEAC
    if (ctx->r1 == 0) {
        // 0x800CBD88: lh          $t0, 0x0($t2)
        ctx->r8 = MEM_H(ctx->r10, 0X0);
            goto L_800CBEAC;
    }
    // 0x800CBD88: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x800CBD8C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_800CBD90:
    // 0x800CBD90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CBD94: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x800CBD98: beq         $v0, $at, L_800CBDAC
    if (ctx->r2 == ctx->r1) {
        // 0x800CBD9C: subu        $s3, $s3, $s2
        ctx->r19 = SUB32(ctx->r19, ctx->r18);
            goto L_800CBDAC;
    }
    // 0x800CBD9C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800CBDA0: beq         $v0, $zero, L_800CBDAC
    if (ctx->r2 == 0) {
        // 0x800CBDA4: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800CBDAC;
    }
    // 0x800CBDA4: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800CBDA8: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
L_800CBDAC:
    // 0x800CBDAC: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x800CBDB0: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x800CBDB4: subu        $v0, $t4, $t5
    ctx->r2 = SUB32(ctx->r12, ctx->r13);
    // 0x800CBDB8: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x800CBDBC: beq         $at, $zero, L_800CBDCC
    if (ctx->r1 == 0) {
        // 0x800CBDC0: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800CBDCC;
    }
    // 0x800CBDC0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800CBDC4: b           L_800CBDCC
    // 0x800CBDC8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
        goto L_800CBDCC;
    // 0x800CBDC8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_800CBDCC:
    // 0x800CBDCC: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800CBDD0: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800CBDD4: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800CBDD8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800CBDDC: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800CBDE0: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x800CBDE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CBDE8: jalr        $t9
    // 0x800CBDEC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CBDEC: nop

    after_1:
    // 0x800CBDF0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800CBDF4: andi        $a1, $v0, 0x7
    ctx->r5 = ctx->r2 & 0X7;
    // 0x800CBDF8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800CBDFC: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x800CBE00: beq         $v1, $zero, L_800CBE14
    if (ctx->r3 == 0) {
        // 0x800CBE04: addu        $a3, $s1, $a1
        ctx->r7 = ADD32(ctx->r17, ctx->r5);
            goto L_800CBE14;
    }
    // 0x800CBE04: addu        $a3, $s1, $a1
    ctx->r7 = ADD32(ctx->r17, ctx->r5);
    // 0x800CBE08: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800CBE0C: b           L_800CBE18
    // 0x800CBE10: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
        goto L_800CBE18;
    // 0x800CBE10: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
L_800CBE14:
    // 0x800CBE14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CBE18:
    // 0x800CBE18: addu        $t7, $t0, $a2
    ctx->r15 = ADD32(ctx->r8, ctx->r6);
    // 0x800CBE1C: andi        $t4, $a3, 0x7
    ctx->r12 = ctx->r7 & 0X7;
    // 0x800CBE20: subu        $t5, $a3, $t4
    ctx->r13 = SUB32(ctx->r7, ctx->r12);
    // 0x800CBE24: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CBE28: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800CBE2C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CBE30: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x800CBE34: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800CBE38: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800CBE3C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800CBE40: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CBE44: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800CBE48: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800CBE4C: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x800CBE50: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x800CBE54: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CBE58: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800CBE5C: bne         $a1, $zero, L_800CBE68
    if (ctx->r5 != 0) {
        // 0x800CBE60: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_800CBE68;
    }
    // 0x800CBE60: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800CBE64: beq         $a2, $zero, L_800CBEA0
    if (ctx->r6 == 0) {
        // 0x800CBE68: addu        $t3, $t0, $a1
        ctx->r11 = ADD32(ctx->r8, ctx->r5);
            goto L_800CBEA0;
    }
L_800CBE68:
    // 0x800CBE68: addu        $t3, $t0, $a1
    ctx->r11 = ADD32(ctx->r8, ctx->r5);
    // 0x800CBE6C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CBE70: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CBE74: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x800CBE78: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800CBE7C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CBE80: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800CBE84: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800CBE88: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x800CBE8C: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x800CBE90: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x800CBE94: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800CBE98: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800CBE9C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800CBEA0:
    // 0x800CBEA0: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800CBEA4: bnel        $at, $zero, L_800CBD90
    if (ctx->r1 != 0) {
        // 0x800CBEA8: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_800CBD90;
    }
    goto skip_2;
    // 0x800CBEA8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_2:
L_800CBEAC:
    // 0x800CBEAC: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x800CBEB0: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800CBEB4: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x800CBEB8: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x800CBEBC: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800CBEC0: sw          $t5, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r13;
    // 0x800CBEC4: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x800CBEC8: b           L_800CC004
    // 0x800CBECC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800CC004;
    // 0x800CBECC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CBED0: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
L_800CBED4:
    // 0x800CBED4: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800CBED8: sll         $s1, $s3, 1
    ctx->r17 = S32(ctx->r19 << 1);
    // 0x800CBEDC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800CBEE0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x800CBEE4: addu        $v1, $a0, $s1
    ctx->r3 = ADD32(ctx->r4, ctx->r17);
    // 0x800CBEE8: subu        $t3, $v1, $t8
    ctx->r11 = SUB32(ctx->r3, ctx->r24);
    // 0x800CBEEC: subu        $s2, $t3, $t4
    ctx->r18 = SUB32(ctx->r11, ctx->r12);
    // 0x800CBEF0: bgezl       $s2, L_800CBF00
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800CBEF4: slt         $at, $s1, $s2
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800CBF00;
    }
    goto skip_3;
    // 0x800CBEF4: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    skip_3:
    // 0x800CBEF8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800CBEFC: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
L_800CBF00:
    // 0x800CBF00: beql        $at, $zero, L_800CBF10
    if (ctx->r1 == 0) {
        // 0x800CBF04: slt         $at, $s2, $s1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_800CBF10;
    }
    goto skip_4;
    // 0x800CBF04: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
    skip_4:
    // 0x800CBF08: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x800CBF0C: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
L_800CBF10:
    // 0x800CBF10: beql        $at, $zero, L_800CBFC4
    if (ctx->r1 == 0) {
        // 0x800CBF14: sw          $v1, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r3;
            goto L_800CBFC4;
    }
    goto skip_5;
    // 0x800CBF14: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    skip_5:
    // 0x800CBF18: blez        $s3, L_800CBF98
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800CBF1C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800CBF98;
    }
    // 0x800CBF1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CBF20: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800CBF24: subu        $a1, $s1, $s2
    ctx->r5 = SUB32(ctx->r17, ctx->r18);
    // 0x800CBF28: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800CBF2C: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800CBF30: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800CBF34: jalr        $t9
    // 0x800CBF38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CBF38: nop

    after_2:
    // 0x800CBF3C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800CBF40: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800CBF44: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800CBF48: lh          $t5, 0x0($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X0);
    // 0x800CBF4C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800CBF50: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x800CBF54: andi        $t8, $a3, 0x7
    ctx->r24 = ctx->r7 & 0X7;
    // 0x800CBF58: subu        $t3, $a3, $t8
    ctx->r11 = SUB32(ctx->r7, ctx->r24);
    // 0x800CBF5C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CBF60: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800CBF64: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CBF68: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800CBF6C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800CBF70: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x800CBF74: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CBF78: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x800CBF7C: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x800CBF80: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800CBF84: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800CBF88: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800CBF8C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800CBF90: b           L_800CBF98
    // 0x800CBF94: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800CBF98;
    // 0x800CBF94: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800CBF98:
    // 0x800CBF98: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x800CBF9C: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x800CBFA0: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x800CBFA4: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x800CBFA8: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800CBFAC: addu        $t4, $t3, $s3
    ctx->r12 = ADD32(ctx->r11, ctx->r19);
    // 0x800CBFB0: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x800CBFB4: sw          $t4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r12;
    // 0x800CBFB8: b           L_800CBFC4
    // 0x800CBFBC: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
        goto L_800CBFC4;
    // 0x800CBFBC: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
    // 0x800CBFC0: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
L_800CBFC4:
    // 0x800CBFC4: beq         $s2, $zero, L_800CC000
    if (ctx->r18 == 0) {
        // 0x800CBFC8: subu        $v1, $s1, $s2
        ctx->r3 = SUB32(ctx->r17, ctx->r18);
            goto L_800CC000;
    }
    // 0x800CBFC8: subu        $v1, $s1, $s2
    ctx->r3 = SUB32(ctx->r17, ctx->r18);
    // 0x800CBFCC: bgez        $v1, L_800CBFD8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800CBFD0: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800CBFD8;
    }
    // 0x800CBFD0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CBFD4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800CBFD8:
    // 0x800CBFD8: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x800CBFDC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CBFE0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CBFE4: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800CBFE8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800CBFEC: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800CBFF0: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x800CBFF4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800CBFF8: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x800CBFFC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800CC000:
    // 0x800CC000: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800CC004:
    // 0x800CC004: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CC008: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CC00C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CC010: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC014: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CC018: jr          $ra
    // 0x800CC01C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800CC01C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800CC020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CC024: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CC028: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800CC02C: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800CC030: sll         $t8, $s5, 16
    ctx->r24 = S32(ctx->r21 << 16);
    // 0x800CC034: sra         $s5, $t8, 16
    ctx->r21 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800CC038: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CC03C: blez        $s1, L_800CC0A8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800CC040: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800CC0A8;
    }
    // 0x800CC040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC044: lw          $t9, 0x30($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X30);
    // 0x800CC048: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x800CC04C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CC050: jalr        $t9
    // 0x800CC054: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800CC054: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    after_3:
    // 0x800CC058: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800CC05C: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x800CC060: andi        $t6, $s3, 0xFFFF
    ctx->r14 = ctx->r19 & 0XFFFF;
    // 0x800CC064: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CC068: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CC06C: andi        $t8, $s1, 0x7
    ctx->r24 = ctx->r17 & 0X7;
    // 0x800CC070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC074: subu        $t9, $s1, $t8
    ctx->r25 = SUB32(ctx->r17, ctx->r24);
    // 0x800CC078: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800CC07C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CC080: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CC084: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CC088: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CC08C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800CC090: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x800CC094: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800CC098: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800CC09C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800CC0A0: b           L_800CC0AC
    // 0x800CC0A4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800CC0AC;
    // 0x800CC0A4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800CC0A8:
    // 0x800CC0A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CC0AC:
    // 0x800CC0AC: andi        $t6, $s4, 0x2
    ctx->r14 = ctx->r20 & 0X2;
    // 0x800CC0B0: beq         $t6, $zero, L_800CC0D8
    if (ctx->r14 == 0) {
        // 0x800CC0B4: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800CC0D8;
    }
    // 0x800CC0B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CC0B8: lui         $t7, 0xF00
    ctx->r15 = S32(0XF00 << 16);
    // 0x800CC0BC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CC0C0: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x800CC0C4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800CC0C8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC0CC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800CC0D0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800CC0D4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800CC0D8:
    // 0x800CC0D8: addu        $t6, $s3, $a2
    ctx->r14 = ADD32(ctx->r19, ctx->r6);
    // 0x800CC0DC: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CC0E0: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CC0E4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800CC0E8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800CC0EC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800CC0F0: sll         $t7, $s6, 1
    ctx->r15 = S32(ctx->r22 << 1);
    // 0x800CC0F4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CC0F8: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x800CC0FC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800CC100: andi        $t7, $s4, 0xFF
    ctx->r15 = ctx->r20 & 0XFF;
    // 0x800CC104: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CC108: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800CC10C: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800CC110: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800CC114: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800CC118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC11C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CC120: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x800CC124: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800CC128: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC12C: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800CC130: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800CC134: sw          $zero, 0x40($s2)
    MEM_W(0X40, ctx->r18) = 0;
    // 0x800CC138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CC13C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CC140: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CC144: jr          $ra
    // 0x800CC148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800CC148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void alAdpcmPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC14C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800CC150: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800CC154: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x800CC158: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CC15C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800CC160: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800CC164: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800CC168: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800CC16C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800CC170: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800CC174: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800CC178: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800CC17C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800CC180: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800CC184: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800CC188: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800CC18C: bne         $a2, $zero, L_800CC19C
    if (ctx->r6 != 0) {
        // 0x800CC190: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_800CC19C;
    }
    // 0x800CC190: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800CC194: b           L_800CC5BC
    // 0x800CC198: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
        goto L_800CC5BC;
    // 0x800CC198: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
L_800CC19C:
    // 0x800CC19C: lw          $t6, 0x2C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X2C);
    // 0x800CC1A0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CC1A4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC1A8: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x800CC1AC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800CC1B0: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x800CC1B4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800CC1B8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800CC1BC: lw          $t9, 0x28($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X28);
    // 0x800CC1C0: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800CC1C4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC1C8: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x800CC1CC: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x800CC1D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CC1D4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800CC1D8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800CC1DC: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800CC1E0: lw          $v1, 0x38($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X38);
    // 0x800CC1E4: lw          $a0, 0x20($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X20);
    // 0x800CC1E8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800CC1EC: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x800CC1F0: sltu        $t1, $a0, $t9
    ctx->r9 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x800CC1F4: beq         $t1, $zero, L_800CC208
    if (ctx->r9 == 0) {
        // 0x800CC1F8: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_800CC208;
    }
    // 0x800CC1F8: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800CC1FC: lw          $t1, 0x24($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X24);
    // 0x800CC200: sltu        $t6, $zero, $t1
    ctx->r14 = 0 < ctx->r9 ? 1 : 0;
    // 0x800CC204: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
L_800CC208:
    // 0x800CC208: beq         $t1, $zero, L_800CC218
    if (ctx->r9 == 0) {
        // 0x800CC20C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800CC218;
    }
    // 0x800CC20C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800CC210: b           L_800CC218
    // 0x800CC214: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
        goto L_800CC218;
    // 0x800CC214: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
L_800CC218:
    // 0x800CC218: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC21C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800CC220: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800CC224: beq         $v1, $zero, L_800CC234
    if (ctx->r3 == 0) {
        // 0x800CC228: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800CC234;
    }
    // 0x800CC228: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800CC22C: b           L_800CC234
    // 0x800CC230: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
        goto L_800CC234;
    // 0x800CC230: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
L_800CC234:
    // 0x800CC234: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800CC238: bgez        $a0, L_800CC244
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800CC23C: nop
    
            goto L_800CC244;
    }
    // 0x800CC23C: nop

    // 0x800CC240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800CC244:
    // 0x800CC244: beq         $t1, $zero, L_800CC44C
    if (ctx->r9 == 0) {
        // 0x800CC248: addiu       $fp, $a0, 0xF
        ctx->r30 = ADD32(ctx->r4, 0XF);
            goto L_800CC44C;
    }
    // 0x800CC248: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800CC24C: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800CC250: sra         $t8, $fp, 4
    ctx->r24 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800CC254: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800CC258: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800CC25C: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x800CC260: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x800CC264: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800CC268: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800CC26C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800CC270: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800CC274: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800CC278: or          $fp, $t8, $zero
    ctx->r30 = ctx->r24 | 0;
    // 0x800CC27C: jal         0x800CC020
    // 0x800CC280: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    static_0_800CC020(rdram, ctx);
        goto after_0;
    // 0x800CC280: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_0:
    // 0x800CC284: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC288: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800CC28C: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800CC290: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800CC294: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800CC298: beq         $v1, $zero, L_800CC2B4
    if (ctx->r3 == 0) {
        // 0x800CC29C: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800CC2B4;
    }
    // 0x800CC29C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800CC2A0: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800CC2A4: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800CC2A8: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800CC2AC: b           L_800CC2C0
    // 0x800CC2B0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
        goto L_800CC2C0;
    // 0x800CC2B0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800CC2B4:
    // 0x800CC2B4: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800CC2B8: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x800CC2BC: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_800CC2C0:
    // 0x800CC2C0: lw          $v0, 0x1C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1C);
    // 0x800CC2C4: lw          $t7, 0x28($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X28);
    // 0x800CC2C8: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CC2CC: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x800CC2D0: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800CC2D4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800CC2D8: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x800CC2DC: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800CC2E0: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800CC2E4: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800CC2E8: addiu       $t9, $t7, 0x9
    ctx->r25 = ADD32(ctx->r15, 0X9);
    // 0x800CC2EC: sw          $t9, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r25;
    // 0x800CC2F0: sw          $v0, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r2;
    // 0x800CC2F4: beq         $at, $zero, L_800CC41C
    if (ctx->r1 == 0) {
        // 0x800CC2F8: lh          $a2, 0x0($a3)
        ctx->r6 = MEM_H(ctx->r7, 0X0);
            goto L_800CC41C;
    }
    // 0x800CC2F8: lh          $a2, 0x0($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X0);
    // 0x800CC2FC: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_800CC300:
    // 0x800CC300: addiu       $t8, $fp, 0x1
    ctx->r24 = ADD32(ctx->r30, 0X1);
    // 0x800CC304: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x800CC308: lw          $v0, 0x24($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X24);
    // 0x800CC30C: addu        $a3, $t6, $a2
    ctx->r7 = ADD32(ctx->r14, ctx->r6);
    // 0x800CC310: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800CC314: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x800CC318: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CC31C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x800CC320: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800CC324: beq         $v0, $at, L_800CC338
    if (ctx->r2 == ctx->r1) {
        // 0x800CC328: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_800CC338;
    }
    // 0x800CC328: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800CC32C: beq         $v0, $zero, L_800CC338
    if (ctx->r2 == 0) {
        // 0x800CC330: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800CC338;
    }
    // 0x800CC330: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800CC334: sw          $t9, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->r25;
L_800CC338:
    // 0x800CC338: lw          $t8, 0x20($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X20);
    // 0x800CC33C: lw          $t6, 0x1C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X1C);
    // 0x800CC340: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800CC344: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800CC348: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x800CC34C: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800CC350: beq         $at, $zero, L_800CC360
    if (ctx->r1 == 0) {
        // 0x800CC354: sll         $s5, $a3, 16
        ctx->r21 = S32(ctx->r7 << 16);
            goto L_800CC360;
    }
    // 0x800CC354: sll         $s5, $a3, 16
    ctx->r21 = S32(ctx->r7 << 16);
    // 0x800CC358: b           L_800CC364
    // 0x800CC35C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_800CC364;
    // 0x800CC35C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_800CC360:
    // 0x800CC360: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800CC364:
    // 0x800CC364: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC368: sra         $t8, $s5, 16
    ctx->r24 = S32(SIGNED(ctx->r21) >> 16);
    // 0x800CC36C: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
    // 0x800CC370: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x800CC374: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800CC378: bgez        $a0, L_800CC384
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800CC37C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800CC384;
    }
    // 0x800CC37C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800CC380: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800CC384:
    // 0x800CC384: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800CC388: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800CC38C: sra         $t9, $fp, 4
    ctx->r25 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800CC390: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800CC394: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800CC398: ori         $t6, $s4, 0x2
    ctx->r14 = ctx->r20 | 0X2;
    // 0x800CC39C: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800CC3A0: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800CC3A4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800CC3A8: or          $fp, $t9, $zero
    ctx->r30 = ctx->r25 | 0;
    // 0x800CC3AC: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800CC3B0: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x800CC3B4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800CC3B8: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800CC3BC: jal         0x800CC020
    // 0x800CC3C0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    static_0_800CC020(rdram, ctx);
        goto after_1;
    // 0x800CC3C0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_1:
    // 0x800CC3C4: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC3C8: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x800CC3CC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CC3D0: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800CC3D4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC3D8: addu        $t8, $t9, $a3
    ctx->r24 = ADD32(ctx->r25, ctx->r7);
    // 0x800CC3DC: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800CC3E0: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800CC3E4: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800CC3E8: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x800CC3EC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CC3F0: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800CC3F4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800CC3F8: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800CC3FC: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800CC400: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CC404: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800CC408: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800CC40C: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CC410: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800CC414: bne         $at, $zero, L_800CC300
    if (ctx->r1 != 0) {
        // 0x800CC418: addiu       $t2, $v0, 0x8
        ctx->r10 = ADD32(ctx->r2, 0X8);
            goto L_800CC300;
    }
    // 0x800CC418: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
L_800CC41C:
    // 0x800CC41C: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC420: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800CC424: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800CC428: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800CC42C: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800CC430: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800CC434: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800CC438: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800CC43C: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800CC440: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800CC444: b           L_800CC5BC
    // 0x800CC448: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800CC5BC;
    // 0x800CC448: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800CC44C:
    // 0x800CC44C: lw          $v0, 0x28($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X28);
    // 0x800CC450: sra         $t7, $fp, 4
    ctx->r15 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800CC454: lw          $t9, 0x44($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X44);
    // 0x800CC458: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x800CC45C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800CC460: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x800CC464: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x800CC468: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800CC46C: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x800CC470: subu        $t6, $t3, $t8
    ctx->r14 = SUB32(ctx->r11, ctx->r24);
    // 0x800CC474: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x800CC478: bgez        $v1, L_800CC484
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800CC47C: sll         $a1, $fp, 4
        ctx->r5 = S32(ctx->r30 << 4);
            goto L_800CC484;
    }
    // 0x800CC47C: sll         $a1, $fp, 4
    ctx->r5 = S32(ctx->r30 << 4);
    // 0x800CC480: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800CC484:
    // 0x800CC484: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800CC488: mflo        $v0
    ctx->r2 = lo;
    // 0x800CC48C: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x800CC490: addu        $t4, $a1, $a2
    ctx->r12 = ADD32(ctx->r5, ctx->r6);
    // 0x800CC494: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CC498: beq         $at, $zero, L_800CC4A4
    if (ctx->r1 == 0) {
        // 0x800CC49C: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_800CC4A4;
    }
    // 0x800CC49C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800CC4A0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_800CC4A4:
    // 0x800CC4A4: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x800CC4A8: subu        $t6, $a0, $t8
    ctx->r14 = SUB32(ctx->r4, ctx->r24);
    // 0x800CC4AC: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CC4B0: beq         $at, $zero, L_800CC560
    if (ctx->r1 == 0) {
        // 0x800CC4B4: subu        $a2, $t1, $v1
        ctx->r6 = SUB32(ctx->r9, ctx->r3);
            goto L_800CC560;
    }
    // 0x800CC4B4: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    // 0x800CC4B8: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800CC4BC: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800CC4C0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800CC4C4: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800CC4C8: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x800CC4CC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800CC4D0: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800CC4D4: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800CC4D8: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x800CC4DC: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800CC4E0: subu        $s6, $a1, $a0
    ctx->r22 = SUB32(ctx->r5, ctx->r4);
    // 0x800CC4E4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800CC4E8: jal         0x800CC020
    // 0x800CC4EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    static_0_800CC020(rdram, ctx);
        goto after_2;
    // 0x800CC4EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_2:
    // 0x800CC4F0: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC4F4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800CC4F8: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800CC4FC: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800CC500: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800CC504: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800CC508: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800CC50C: beq         $v1, $zero, L_800CC528
    if (ctx->r3 == 0) {
        // 0x800CC510: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800CC528;
    }
    // 0x800CC510: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800CC514: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800CC518: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800CC51C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800CC520: b           L_800CC534
    // 0x800CC524: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_800CC534;
    // 0x800CC524: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_800CC528:
    // 0x800CC528: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x800CC52C: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x800CC530: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800CC534:
    // 0x800CC534: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC538: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800CC53C: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800CC540: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800CC544: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800CC548: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800CC54C: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800CC550: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800CC554: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800CC558: b           L_800CC568
    // 0x800CC55C: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800CC568;
    // 0x800CC55C: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800CC560:
    // 0x800CC560: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800CC564: sw          $t3, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r11;
L_800CC568:
    // 0x800CC568: beq         $a0, $zero, L_800CC5B8
    if (ctx->r4 == 0) {
        // 0x800CC56C: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800CC5B8;
    }
    // 0x800CC56C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800CC570: beq         $t5, $zero, L_800CC588
    if (ctx->r13 == 0) {
        // 0x800CC574: sw          $zero, 0x3C($s7)
        MEM_W(0X3C, ctx->r23) = 0;
            goto L_800CC588;
    }
    // 0x800CC574: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800CC578: subu        $v1, $t4, $a0
    ctx->r3 = SUB32(ctx->r12, ctx->r4);
    // 0x800CC57C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x800CC580: b           L_800CC58C
    // 0x800CC584: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_800CC58C;
    // 0x800CC584: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_800CC588:
    // 0x800CC588: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800CC58C:
    // 0x800CC58C: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800CC590: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CC594: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC598: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800CC59C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800CC5A0: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800CC5A4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CC5A8: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800CC5AC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800CC5B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CC5B4: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_800CC5B8:
    // 0x800CC5B8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800CC5BC:
    // 0x800CC5BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800CC5C0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800CC5C4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800CC5C8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800CC5CC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800CC5D0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800CC5D4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800CC5D8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800CC5DC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800CC5E0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800CC5E4: jr          $ra
    // 0x800CC5E8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800CC5E8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x800CC5EC: nop

;}
RECOMP_FUNC void alResampleParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC5F0: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x800CC5F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CC5F8: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x800CC5FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC600: beq         $at, $zero, L_800CC6B0
    if (ctx->r1 == 0) {
        // 0x800CC604: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800CC6B0;
    }
    // 0x800CC604: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CC608: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CC60C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CC610: addu        $at, $at, $t6
    gpr jr_addend_800CC618 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800CC614: lw          $t6, -0x6480($at)
    ctx->r14 = ADD32(ctx->r1, -0X6480);
    // 0x800CC618: jr          $t6
    // 0x800CC61C: nop

    switch (jr_addend_800CC618 >> 2) {
        case 0: goto L_800CC620; break;
        case 1: goto L_800CC6B0; break;
        case 2: goto L_800CC6B0; break;
        case 3: goto L_800CC628; break;
        case 4: goto L_800CC6B0; break;
        case 5: goto L_800CC6B0; break;
        case 6: goto L_800CC694; break;
        case 7: goto L_800CC6A4; break;
        case 8: goto L_800CC664; break;
        default: switch_error(__func__, 0x800CC618, 0x800E9B80);
    }
    // 0x800CC61C: nop

L_800CC620:
    // 0x800CC620: b           L_800CC6C8
    // 0x800CC624: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_800CC6C8;
    // 0x800CC624: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
L_800CC628:
    // 0x800CC628: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800CC62C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CC630: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CC634: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
    // 0x800CC638: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x800CC63C: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x800CC640: beq         $a0, $zero, L_800CC6C8
    if (ctx->r4 == 0) {
        // 0x800CC644: swc1        $f4, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
            goto L_800CC6C8;
    }
    // 0x800CC644: swc1        $f4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
    // 0x800CC648: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800CC64C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800CC650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CC654: jalr        $t9
    // 0x800CC658: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CC658: nop

    after_0:
    // 0x800CC65C: b           L_800CC6CC
    // 0x800CC660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CC6CC;
    // 0x800CC660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CC664:
    // 0x800CC664: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800CC668: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CC66C: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
    // 0x800CC670: beql        $a0, $zero, L_800CC6CC
    if (ctx->r4 == 0) {
        // 0x800CC674: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CC6CC;
    }
    goto skip_0;
    // 0x800CC674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CC678: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800CC67C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CC680: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CC684: jalr        $t9
    // 0x800CC688: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CC688: nop

    after_1:
    // 0x800CC68C: b           L_800CC6CC
    // 0x800CC690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CC6CC;
    // 0x800CC690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CC694:
    // 0x800CC694: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800CC698: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CC69C: b           L_800CC6C8
    // 0x800CC6A0: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
        goto L_800CC6C8;
    // 0x800CC6A0: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
L_800CC6A4:
    // 0x800CC6A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CC6A8: b           L_800CC6C8
    // 0x800CC6AC: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
        goto L_800CC6C8;
    // 0x800CC6AC: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
L_800CC6B0:
    // 0x800CC6B0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800CC6B4: beql        $a0, $zero, L_800CC6CC
    if (ctx->r4 == 0) {
        // 0x800CC6B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CC6CC;
    }
    goto skip_1;
    // 0x800CC6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800CC6BC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800CC6C0: jalr        $t9
    // 0x800CC6C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CC6C4: nop

    after_2:
L_800CC6C8:
    // 0x800CC6C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CC6CC:
    // 0x800CC6CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CC6D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CC6D4: jr          $ra
    // 0x800CC6D8: nop

    return;
    // 0x800CC6D8: nop

;}
RECOMP_FUNC void alResamplePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC6DC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CC6E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CC6E4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800CC6E8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800CC6EC: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x800CC6F0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800CC6F4: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800CC6F8: bne         $a2, $zero, L_800CC708
    if (ctx->r6 != 0) {
        // 0x800CC6FC: sh          $t6, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r14;
            goto L_800CC708;
    }
    // 0x800CC6FC: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
    // 0x800CC700: b           L_800CC8D4
    // 0x800CC704: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
        goto L_800CC8D4;
    // 0x800CC704: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
L_800CC708:
    // 0x800CC708: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x800CC70C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800CC710: beql        $t7, $zero, L_800CC77C
    if (ctx->r15 == 0) {
        // 0x800CC714: lwc1        $f2, 0x18($t0)
        ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
            goto L_800CC77C;
    }
    goto skip_0;
    // 0x800CC714: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    skip_0:
    // 0x800CC718: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800CC71C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800CC720: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800CC724: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CC728: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800CC72C: jalr        $t9
    // 0x800CC730: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CC730: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_0:
    // 0x800CC734: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x800CC738: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CC73C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC740: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800CC744: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800CC748: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CC74C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800CC750: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800CC754: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800CC758: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800CC75C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800CC760: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x800CC764: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800CC768: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800CC76C: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800CC770: b           L_800CC8D0
    // 0x800CC774: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_800CC8D0;
    // 0x800CC774: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800CC778: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
L_800CC77C:
    // 0x800CC77C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CC780: ldc1        $f4, -0x6458($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X6458);
    // 0x800CC784: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800CC788: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CC78C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800CC790: nop

    // 0x800CC794: bc1fl       L_800CC7AC
    if (!c1cs) {
        // 0x800CC798: lui         $at, 0x4700
        ctx->r1 = S32(0X4700 << 16);
            goto L_800CC7AC;
    }
    goto skip_1;
    // 0x800CC798: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    skip_1:
    // 0x800CC79C: lwc1        $f8, -0x6450($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6450);
    // 0x800CC7A0: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800CC7A4: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800CC7A8: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
L_800CC7AC:
    // 0x800CC7AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800CC7B0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CC7B4: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800CC7B8: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800CC7BC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CC7C0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800CC7C4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800CC7C8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800CC7CC: nop

    // 0x800CC7D0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CC7D4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CC7D8: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x800CC7DC: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800CC7E0: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800CC7E4: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x800CC7E8: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800CC7EC: lwc1        $f10, 0x18($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800CC7F0: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800CC7F4: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800CC7F8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800CC7FC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800CC800: nop

    // 0x800CC804: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800CC808: nop

    // 0x800CC80C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CC810: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800CC814: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x800CC818: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800CC81C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800CC820: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800CC824: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800CC828: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800CC82C: jalr        $t9
    // 0x800CC830: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CC830: nop

    after_1:
    // 0x800CC834: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800CC838: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x800CC83C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800CC840: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CC844: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800CC848: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CC84C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800CC850: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CC854: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CC858: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CC85C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800CC860: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800CC864: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x800CC868: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800CC86C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800CC870: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800CC874: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x800CC878: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800CC87C: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CC880: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800CC884: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800CC888: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x800CC88C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800CC890: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800CC894: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x800CC898: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x800CC89C: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x800CC8A0: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800CC8A4: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800CC8A8: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800CC8AC: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x800CC8B0: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x800CC8B4: jal         0x800C9250
    // 0x800CC8B8: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800CC8B8: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_2:
    // 0x800CC8BC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800CC8C0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800CC8C4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800CC8C8: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x800CC8CC: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
L_800CC8D0:
    // 0x800CC8D0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800CC8D4:
    // 0x800CC8D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC8D8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800CC8DC: jr          $ra
    // 0x800CC8E0: nop

    return;
    // 0x800CC8E0: nop

    // 0x800CC8E4: nop

    // 0x800CC8E8: nop

    // 0x800CC8EC: nop

;}
RECOMP_FUNC void alMainBusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC8F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CC8F4: bne         $a1, $at, L_800CC918
    if (ctx->r5 != ctx->r1) {
        // 0x800CC8F8: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_800CC918;
    }
    // 0x800CC8F8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800CC8FC: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800CC900: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CC904: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800CC908: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x800CC90C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800CC910: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800CC914: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_800CC918:
    // 0x800CC918: jr          $ra
    // 0x800CC91C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CC91C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void alMainBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC920: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800CC924: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CC928: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800CC92C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800CC930: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800CC934: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800CC938: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800CC93C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800CC940: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CC944: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800CC948: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800CC94C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CC950: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800CC954: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800CC958: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800CC95C: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x800CC960: ori         $t6, $t6, 0x440
    ctx->r14 = ctx->r14 | 0X440;
    // 0x800CC964: ori         $t7, $t7, 0x580
    ctx->r15 = ctx->r15 | 0X580;
    // 0x800CC968: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800CC96C: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800CC970: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x800CC974: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x800CC978: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x800CC97C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800CC980: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800CC984: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x800CC988: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800CC98C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800CC990: blez        $t8, L_800CCA0C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800CC994: addiu       $s3, $t0, 0x10
        ctx->r19 = ADD32(ctx->r8, 0X10);
            goto L_800CCA0C;
    }
    // 0x800CC994: addiu       $s3, $t0, 0x10
    ctx->r19 = ADD32(ctx->r8, 0X10);
    // 0x800CC998: lui         $s2, 0xC00
    ctx->r18 = S32(0XC00 << 16);
    // 0x800CC99C: ori         $s2, $s2, 0x7FFF
    ctx->r18 = ctx->r18 | 0X7FFF;
    // 0x800CC9A0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800CC9A4: andi        $s6, $v0, 0xFFFF
    ctx->r22 = ctx->r2 & 0XFFFF;
L_800CC9A8:
    // 0x800CC9A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800CC9AC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800CC9B0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800CC9B4: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800CC9B8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800CC9BC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800CC9C0: jalr        $t9
    // 0x800CC9C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CC9C4: nop

    after_0:
    // 0x800CC9C8: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x800CC9CC: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x800CC9D0: lui         $t1, 0x800
    ctx->r9 = S32(0X800 << 16);
    // 0x800CC9D4: ori         $t2, $t2, 0x440
    ctx->r10 = ctx->r10 | 0X440;
    // 0x800CC9D8: ori         $t3, $t3, 0x580
    ctx->r11 = ctx->r11 | 0X580;
    // 0x800CC9DC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800CC9E0: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x800CC9E4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800CC9E8: sw          $s2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r18;
    // 0x800CC9EC: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x800CC9F0: sw          $s2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r18;
    // 0x800CC9F4: lw          $t4, 0x14($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X14);
    // 0x800CC9F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800CC9FC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800CCA00: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800CCA04: bne         $at, $zero, L_800CC9A8
    if (ctx->r1 != 0) {
        // 0x800CCA08: addiu       $s3, $v0, 0x18
        ctx->r19 = ADD32(ctx->r2, 0X18);
            goto L_800CC9A8;
    }
    // 0x800CCA08: addiu       $s3, $v0, 0x18
    ctx->r19 = ADD32(ctx->r2, 0X18);
L_800CCA0C:
    // 0x800CCA0C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800CCA10: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800CCA14: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800CCA18: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800CCA1C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800CCA20: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800CCA24: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800CCA28: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800CCA2C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800CCA30: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800CCA34: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800CCA38: jr          $ra
    // 0x800CCA3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800CCA3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alSaveParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCA40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CCA44: beq         $a1, $at, L_800CCA60
    if (ctx->r5 == ctx->r1) {
        // 0x800CCA48: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CCA60;
    }
    // 0x800CCA48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CCA4C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800CCA50: beql        $a1, $at, L_800CCA6C
    if (ctx->r5 == ctx->r1) {
        // 0x800CCA54: sw          $a2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r6;
            goto L_800CCA6C;
    }
    goto skip_0;
    // 0x800CCA54: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800CCA58: jr          $ra
    // 0x800CCA5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CCA5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CCA60:
    // 0x800CCA60: jr          $ra
    // 0x800CCA64: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    return;
    // 0x800CCA64: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800CCA68: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_800CCA6C:
    // 0x800CCA6C: jr          $ra
    // 0x800CCA70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CCA70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void alSavePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCA74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CCA78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CCA7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CCA80: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800CCA84: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800CCA88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CCA8C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CCA90: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800CCA94: jalr        $t9
    // 0x800CCA98: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CCA98: nop

    after_0:
    // 0x800CCA9C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800CCAA0: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x800CCAA4: lui         $t2, 0x440
    ctx->r10 = S32(0X440 << 16);
    // 0x800CCAA8: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800CCAAC: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800CCAB0: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x800CCAB4: ori         $t2, $t2, 0x580
    ctx->r10 = ctx->r10 | 0X580;
    // 0x800CCAB8: lui         $t1, 0xD00
    ctx->r9 = S32(0XD00 << 16);
    // 0x800CCABC: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800CCAC0: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800CCAC4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800CCAC8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800CCACC: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x800CCAD0: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800CCAD4: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x800CCAD8: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x800CCADC: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x800CCAE0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CCAE4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800CCAE8: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x800CCAEC: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x800CCAF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CCAF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CCAF8: jr          $ra
    // 0x800CCAFC: nop

    return;
    // 0x800CCAFC: nop

;}
RECOMP_FUNC void guPerspectiveF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCE80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CCE84: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800CCE88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CCE8C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800CCE90: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800CCE94: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800CCE98: jal         0x800D4EA0
    // 0x800CCE9C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800CCE9C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800CCEA0: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800CCEA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CCEA8: ldc1        $f6, -0x6440($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6440);
    // 0x800CCEAC: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x800CCEB0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800CCEB4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800CCEB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800CCEBC: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x800CCEC0: div.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800CCEC4: jal         0x800D5010
    // 0x800CCEC8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800CCEC8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800CCECC: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CCED0: jal         0x800D5180
    // 0x800CCED4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800CCED4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800CCED8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800CCEDC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800CCEE0: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800CCEE4: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CCEE8: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800CCEEC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800CCEF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CCEF4: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x800CCEF8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800CCEFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800CCF00: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800CCF04: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800CCF08: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x800CCF0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CCF10: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800CCF14: div.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800CCF18: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x800CCF1C: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800CCF20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CCF24: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x800CCF28: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800CCF2C: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CCF30: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CCF34: nop

    // 0x800CCF38: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x800CCF3C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800CCF40: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800CCF44: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x800CCF48: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800CCF4C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CCF50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CCF54: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800CCF58: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CCF5C: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800CCF60: beq         $v1, $a0, L_800CCFA4
    if (ctx->r3 == ctx->r4) {
        // 0x800CCF64: lwc1        $f14, 0xC($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
            goto L_800CCFA4;
    }
    // 0x800CCF64: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
L_800CCF68:
    // 0x800CCF68: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800CCF6C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CCF70: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CCF74: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800CCF78: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800CCF7C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CCF80: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800CCF84: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800CCF88: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800CCF8C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CCF90: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800CCF94: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800CCF98: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800CCF9C: bne         $v1, $a0, L_800CCF68
    if (ctx->r3 != ctx->r4) {
        // 0x800CCFA0: swc1        $f2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
            goto L_800CCF68;
    }
    // 0x800CCFA0: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
L_800CCFA4:
    // 0x800CCFA4: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800CCFA8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800CCFAC: swc1        $f10, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f10.u32l;
    // 0x800CCFB0: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800CCFB4: nop

    // 0x800CCFB8: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800CCFBC: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x800CCFC0: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800CCFC4: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x800CCFC8: beq         $a1, $zero, L_800CD0A0
    if (ctx->r5 == 0) {
        // 0x800CCFCC: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800CD0A0;
    }
    // 0x800CCFCC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800CCFD0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800CCFD4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CCFD8: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x800CCFDC: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800CCFE0: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x800CCFE4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800CCFE8: bc1fl       L_800CCFFC
    if (!c1cs) {
        // 0x800CCFEC: mtc1        $at, $f11
        ctx->f_odd[(11 - 1) * 2] = ctx->r1;
            goto L_800CCFFC;
    }
    goto skip_0;
    // 0x800CCFEC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800CCFF0: b           L_800CD0A0
    // 0x800CCFF4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_800CD0A0;
    // 0x800CCFF4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800CCFF8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
L_800CCFFC:
    // 0x800CCFFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800CD000: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CD004: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800CD008: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x800CD00C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CD010: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800CD014: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800CD018: nop

    // 0x800CD01C: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800CD020: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800CD024: nop

    // 0x800CD028: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800CD02C: beql        $t8, $zero, L_800CD080
    if (ctx->r24 == 0) {
        // 0x800CD030: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_800CD080;
    }
    goto skip_1;
    // 0x800CD030: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x800CD034: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CD038: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CD03C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CD040: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x800CD044: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800CD048: nop

    // 0x800CD04C: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800CD050: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800CD054: nop

    // 0x800CD058: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800CD05C: bne         $t8, $zero, L_800CD074
    if (ctx->r24 != 0) {
        // 0x800CD060: nop
    
            goto L_800CD074;
    }
    // 0x800CD060: nop

    // 0x800CD064: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800CD068: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CD06C: b           L_800CD08C
    // 0x800CD070: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800CD08C;
    // 0x800CD070: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800CD074:
    // 0x800CD074: b           L_800CD08C
    // 0x800CD078: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800CD08C;
    // 0x800CD078: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800CD07C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_800CD080:
    // 0x800CD080: nop

    // 0x800CD084: bltz        $t8, L_800CD074
    if (SIGNED(ctx->r24) < 0) {
        // 0x800CD088: nop
    
            goto L_800CD074;
    }
    // 0x800CD088: nop

L_800CD08C:
    // 0x800CD08C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800CD090: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800CD094: bgtz        $t9, L_800CD0A0
    if (SIGNED(ctx->r25) > 0) {
        // 0x800CD098: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_800CD0A0;
    }
    // 0x800CD098: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800CD09C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_800CD0A0:
    // 0x800CD0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD0A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CD0A8: jr          $ra
    // 0x800CD0AC: nop

    return;
    // 0x800CD0AC: nop

;}
RECOMP_FUNC void guPerspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD0B0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800CD0B4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800CD0B8: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800CD0BC: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800CD0C0: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800CD0C4: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CD0C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CD0CC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800CD0D0: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800CD0D4: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800CD0D8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800CD0DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800CD0E0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800CD0E4: jal         0x800CCE80
    // 0x800CD0E8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x800CD0E8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800CD0EC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800CD0F0: jal         0x800D4DA0
    // 0x800CD0F4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800CD0F4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x800CD0F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CD0FC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800CD100: jr          $ra
    // 0x800CD104: nop

    return;
    // 0x800CD104: nop

    // 0x800CD108: nop

    // 0x800CD10C: nop

;}
RECOMP_FUNC void bcmp_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE5B0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800CE5B4: bne         $at, $zero, L_800CE694
    if (ctx->r1 != 0) {
        // 0x800CE5B8: xor         $v0, $a0, $a1
        ctx->r2 = ctx->r4 ^ ctx->r5;
            goto L_800CE694;
    }
    // 0x800CE5B8: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x800CE5BC: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800CE5C0: bne         $v0, $zero, L_800CE628
    if (ctx->r2 != 0) {
        // 0x800CE5C4: negu        $t8, $a0
        ctx->r24 = SUB32(0, ctx->r4);
            goto L_800CE628;
    }
    // 0x800CE5C4: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x800CE5C8: andi        $t8, $t8, 0x3
    ctx->r24 = ctx->r24 & 0X3;
    // 0x800CE5CC: beq         $t8, $zero, L_800CE5EC
    if (ctx->r24 == 0) {
        // 0x800CE5D0: subu        $a2, $a2, $t8
        ctx->r6 = SUB32(ctx->r6, ctx->r24);
            goto L_800CE5EC;
    }
    // 0x800CE5D0: subu        $a2, $a2, $t8
    ctx->r6 = SUB32(ctx->r6, ctx->r24);
    // 0x800CE5D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CE5D8: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x800CE5DC: lwl         $v1, 0x0($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X0);
    // 0x800CE5E0: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800CE5E4: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x800CE5E8: bne         $v0, $v1, L_800CE6C4
    if (ctx->r2 != ctx->r3) {
        // 0x800CE5EC: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800CE6C4;
    }
L_800CE5EC:
    // 0x800CE5EC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800CE5F0: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x800CE5F4: beq         $a3, $zero, L_800CE694
    if (ctx->r7 == 0) {
        // 0x800CE5F8: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800CE694;
    }
    // 0x800CE5F8: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800CE5FC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800CE600: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800CE604:
    // 0x800CE604: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800CE608: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CE60C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800CE610: bne         $v0, $v1, L_800CE6C4
    if (ctx->r2 != ctx->r3) {
        // 0x800CE614: nop
    
            goto L_800CE6C4;
    }
    // 0x800CE614: nop

    // 0x800CE618: bnel        $a0, $a3, L_800CE604
    if (ctx->r4 != ctx->r7) {
        // 0x800CE61C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_800CE604;
    }
    goto skip_0;
    // 0x800CE61C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800CE620: b           L_800CE694
    // 0x800CE624: nop

        goto L_800CE694;
    // 0x800CE624: nop

L_800CE628:
    // 0x800CE628: negu        $a3, $a1
    ctx->r7 = SUB32(0, ctx->r5);
    // 0x800CE62C: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x800CE630: beq         $a3, $zero, L_800CE65C
    if (ctx->r7 == 0) {
        // 0x800CE634: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800CE65C;
    }
    // 0x800CE634: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800CE638: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800CE63C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800CE640:
    // 0x800CE640: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE644: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CE648: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE64C: bne         $v0, $v1, L_800CE6C4
    if (ctx->r2 != ctx->r3) {
        // 0x800CE650: nop
    
            goto L_800CE6C4;
    }
    // 0x800CE650: nop

    // 0x800CE654: bnel        $a0, $a3, L_800CE640
    if (ctx->r4 != ctx->r7) {
        // 0x800CE658: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_800CE640;
    }
    goto skip_1;
    // 0x800CE658: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_800CE65C:
    // 0x800CE65C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800CE660: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x800CE664: beq         $a3, $zero, L_800CE694
    if (ctx->r7 == 0) {
        // 0x800CE668: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800CE694;
    }
    // 0x800CE668: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800CE66C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800CE670: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
L_800CE674:
    // 0x800CE674: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800CE678: lwr         $v0, 0x3($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r4, 0X3);
    // 0x800CE67C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CE680: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800CE684: bne         $v0, $v1, L_800CE6C4
    if (ctx->r2 != ctx->r3) {
        // 0x800CE688: nop
    
            goto L_800CE6C4;
    }
    // 0x800CE688: nop

    // 0x800CE68C: bnel        $a0, $a3, L_800CE674
    if (ctx->r4 != ctx->r7) {
        // 0x800CE690: lwl         $v0, 0x0($a0)
        ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
            goto L_800CE674;
    }
    goto skip_2;
    // 0x800CE690: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    skip_2:
L_800CE694:
    // 0x800CE694: blez        $a2, L_800CE6BC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CE698: addu        $a3, $a2, $a0
        ctx->r7 = ADD32(ctx->r6, ctx->r4);
            goto L_800CE6BC;
    }
    // 0x800CE698: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x800CE69C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800CE6A0:
    // 0x800CE6A0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE6A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CE6A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE6AC: bne         $v0, $v1, L_800CE6C4
    if (ctx->r2 != ctx->r3) {
        // 0x800CE6B0: nop
    
            goto L_800CE6C4;
    }
    // 0x800CE6B0: nop

    // 0x800CE6B4: bnel        $a0, $a3, L_800CE6A0
    if (ctx->r4 != ctx->r7) {
        // 0x800CE6B8: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_800CE6A0;
    }
    goto skip_3;
    // 0x800CE6B8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_3:
L_800CE6BC:
    // 0x800CE6BC: jr          $ra
    // 0x800CE6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE6C4:
    // 0x800CE6C4: jr          $ra
    // 0x800CE6C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800CE6C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CE6CC: nop

;}
RECOMP_FUNC void memcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE6D0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800CE6D4: beq         $a2, $zero, L_800CE6F4
    if (ctx->r6 == 0) {
        // 0x800CE6D8: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800CE6F4;
    }
    // 0x800CE6D8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800CE6DC:
    // 0x800CE6DC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800CE6E0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800CE6E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CE6E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CE6EC: bne         $a2, $zero, L_800CE6DC
    if (ctx->r6 != 0) {
        // 0x800CE6F0: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_800CE6DC;
    }
    // 0x800CE6F0: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_800CE6F4:
    // 0x800CE6F4: jr          $ra
    // 0x800CE6F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800CE6F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void strlen_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE6FC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800CE700: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800CE704: beq         $t6, $zero, L_800CE71C
    if (ctx->r14 == 0) {
        // 0x800CE708: nop
    
            goto L_800CE71C;
    }
    // 0x800CE708: nop

    // 0x800CE70C: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
L_800CE710:
    // 0x800CE710: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CE714: bnel        $t7, $zero, L_800CE710
    if (ctx->r15 != 0) {
        // 0x800CE718: lbu         $t7, 0x1($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X1);
            goto L_800CE710;
    }
    goto skip_0;
    // 0x800CE718: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    skip_0:
L_800CE71C:
    // 0x800CE71C: jr          $ra
    // 0x800CE720: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    return;
    // 0x800CE720: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
;}
RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE724: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800CE728: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800CE72C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800CE730: beql        $t6, $v1, L_800CE75C
    if (ctx->r14 == ctx->r3) {
        // 0x800CE734: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800CE75C;
    }
    goto skip_0;
    // 0x800CE734: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_800CE738:
    // 0x800CE738: bnel        $v1, $zero, L_800CE74C
    if (ctx->r3 != 0) {
        // 0x800CE73C: lbu         $v1, 0x1($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X1);
            goto L_800CE74C;
    }
    goto skip_1;
    // 0x800CE73C: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x800CE740: jr          $ra
    // 0x800CE744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CE748: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
L_800CE74C:
    // 0x800CE74C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CE750: bne         $v0, $v1, L_800CE738
    if (ctx->r2 != ctx->r3) {
        // 0x800CE754: nop
    
            goto L_800CE738;
    }
    // 0x800CE754: nop

    // 0x800CE758: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800CE75C:
    // 0x800CE75C: jr          $ra
    // 0x800CE760: nop

    return;
    // 0x800CE760: nop

    // 0x800CE764: nop

    // 0x800CE768: nop

    // 0x800CE76C: nop

;}
RECOMP_FUNC void osPfsReFormat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D04F0: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x800D04F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D04F8: sw          $a0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r4;
    // 0x800D04FC: sw          $a1, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r5;
    // 0x800D0500: jal         0x800CDBB0
    // 0x800D0504: sw          $a2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r6;
    __osSiGetAccess_recomp(rdram, ctx);
        goto after_0;
    // 0x800D0504: sw          $a2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D0508: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D050C: jal         0x800CF334
    // 0x800D0510: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    __osPfsGetStatus_recomp(rdram, ctx);
        goto after_1;
    // 0x800D0510: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    after_1:
    // 0x800D0514: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0518: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D051C: beq         $t6, $zero, L_800D052C
    if (ctx->r14 == 0) {
        // 0x800D0520: nop
    
            goto L_800D052C;
    }
    // 0x800D0520: nop

    // 0x800D0524: b           L_800D08E0
    // 0x800D0528: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800D08E0;
    // 0x800D0528: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_800D052C:
    // 0x800D052C: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800D0530: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800D0534: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x800D0538: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800D053C: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x800D0540: lw          $t0, 0x154($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X154);
    // 0x800D0544: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800D0548: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x800D054C: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x800D0550: jal         0x800CDBF4
    // 0x800D0554: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    __osSiRelAccess_recomp(rdram, ctx);
        goto after_2;
    // 0x800D0554: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    after_2:
    // 0x800D0558: jal         0x800D5EC4
    // 0x800D055C: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    __osGetId_recomp(rdram, ctx);
        goto after_3;
    // 0x800D055C: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    after_3:
    // 0x800D0560: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0564: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800D0568: beq         $t4, $zero, L_800D0578
    if (ctx->r12 == 0) {
        // 0x800D056C: nop
    
            goto L_800D0578;
    }
    // 0x800D056C: nop

    // 0x800D0570: b           L_800D08E0
    // 0x800D0574: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_800D08E0;
    // 0x800D0574: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_800D0578:
    // 0x800D0578: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800D057C: lbu         $t6, 0x65($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X65);
    // 0x800D0580: beq         $t6, $zero, L_800D05AC
    if (ctx->r14 == 0) {
        // 0x800D0584: nop
    
            goto L_800D05AC;
    }
    // 0x800D0584: nop

    // 0x800D0588: sb          $zero, 0x65($t5)
    MEM_B(0X65, ctx->r13) = 0;
    // 0x800D058C: jal         0x800D653C
    // 0x800D0590: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_4;
    // 0x800D0590: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    after_4:
    // 0x800D0594: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0598: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D059C: beq         $t8, $zero, L_800D05AC
    if (ctx->r24 == 0) {
        // 0x800D05A0: nop
    
            goto L_800D05AC;
    }
    // 0x800D05A0: nop

    // 0x800D05A4: b           L_800D08E0
    // 0x800D05A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D08E0;
    // 0x800D05A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D05AC:
    // 0x800D05AC: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
L_800D05B0:
    // 0x800D05B0: lw          $t9, 0x14C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14C);
    // 0x800D05B4: addu        $t7, $sp, $t9
    ctx->r15 = ADD32(ctx->r29, ctx->r25);
    // 0x800D05B8: sb          $zero, 0x28($t7)
    MEM_B(0X28, ctx->r15) = 0;
    // 0x800D05BC: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800D05C0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800D05C4: slti        $at, $t1, 0x20
    ctx->r1 = SIGNED(ctx->r9) < 0X20 ? 1 : 0;
    // 0x800D05C8: bne         $at, $zero, L_800D05B0
    if (ctx->r1 != 0) {
        // 0x800D05CC: sw          $t1, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r9;
            goto L_800D05B0;
    }
    // 0x800D05CC: sw          $t1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r9;
    // 0x800D05D0: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800D05D4: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
    // 0x800D05D8: lw          $t3, 0x50($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X50);
    // 0x800D05DC: blez        $t3, L_800D0640
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800D05E0: nop
    
            goto L_800D0640;
    }
    // 0x800D05E0: nop

L_800D05E4:
    // 0x800D05E4: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x800D05E8: lw          $t5, 0x14C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14C);
    // 0x800D05EC: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D05F0: lw          $t6, 0x5C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X5C);
    // 0x800D05F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D05F8: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D05FC: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x800D0600: jal         0x800CDE50
    // 0x800D0604: addu        $a2, $t6, $t5
    ctx->r6 = ADD32(ctx->r14, ctx->r13);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_5;
    // 0x800D0604: addu        $a2, $t6, $t5
    ctx->r6 = ADD32(ctx->r14, ctx->r13);
    after_5:
    // 0x800D0608: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D060C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D0610: beq         $t8, $zero, L_800D0620
    if (ctx->r24 == 0) {
        // 0x800D0614: nop
    
            goto L_800D0620;
    }
    // 0x800D0614: nop

    // 0x800D0618: b           L_800D08E0
    // 0x800D061C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D08E0;
    // 0x800D061C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D0620:
    // 0x800D0620: lw          $t9, 0x14C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0624: lw          $t0, 0x150($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X150);
    // 0x800D0628: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800D062C: sw          $t7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r15;
    // 0x800D0630: lw          $t1, 0x50($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X50);
    // 0x800D0634: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D0638: bne         $at, $zero, L_800D05E4
    if (ctx->r1 != 0) {
        // 0x800D063C: nop
    
            goto L_800D05E4;
    }
    // 0x800D063C: nop

L_800D0640:
    // 0x800D0640: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800D0644: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
    // 0x800D0648: lw          $t3, 0x60($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X60);
    // 0x800D064C: blez        $t3, L_800D0684
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800D0650: nop
    
            goto L_800D0684;
    }
    // 0x800D0650: nop

L_800D0654:
    // 0x800D0654: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0658: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800D065C: addu        $t5, $sp, $t6
    ctx->r13 = ADD32(ctx->r29, ctx->r14);
    // 0x800D0660: sh          $zero, 0x48($t5)
    MEM_H(0X48, ctx->r13) = 0;
    // 0x800D0664: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0668: lw          $t0, 0x150($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X150);
    // 0x800D066C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D0670: sw          $t9, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r25;
    // 0x800D0674: lw          $t7, 0x60($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X60);
    // 0x800D0678: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D067C: bne         $at, $zero, L_800D0654
    if (ctx->r1 != 0) {
        // 0x800D0680: nop
    
            goto L_800D0654;
    }
    // 0x800D0680: nop

L_800D0684:
    // 0x800D0684: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x800D0688: lw          $t2, 0x60($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X60);
    // 0x800D068C: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x800D0690: beq         $at, $zero, L_800D06C0
    if (ctx->r1 == 0) {
        // 0x800D0694: sw          $t2, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r10;
            goto L_800D06C0;
    }
    // 0x800D0694: sw          $t2, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r10;
L_800D0698:
    // 0x800D0698: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800D069C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800D06A0: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800D06A4: addu        $t5, $sp, $t6
    ctx->r13 = ADD32(ctx->r29, ctx->r14);
    // 0x800D06A8: sh          $t3, 0x48($t5)
    MEM_H(0X48, ctx->r13) = ctx->r11;
    // 0x800D06AC: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800D06B0: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x800D06B4: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800D06B8: bne         $at, $zero, L_800D0698
    if (ctx->r1 != 0) {
        // 0x800D06BC: sw          $t0, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r8;
            goto L_800D0698;
    }
    // 0x800D06BC: sw          $t0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r8;
L_800D06C0:
    // 0x800D06C0: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x800D06C4: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x800D06C8: lw          $t7, 0x60($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X60);
    // 0x800D06CC: negu        $a1, $t7
    ctx->r5 = SUB32(0, ctx->r15);
    // 0x800D06D0: sll         $t4, $a1, 1
    ctx->r12 = S32(ctx->r5 << 1);
    // 0x800D06D4: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800D06D8: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x800D06DC: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x800D06E0: jal         0x800D5850
    // 0x800D06E4: addiu       $a1, $a1, 0x100
    ctx->r5 = ADD32(ctx->r5, 0X100);
    __osSumcalc(rdram, ctx);
        goto after_6;
    // 0x800D06E4: addiu       $a1, $a1, 0x100
    ctx->r5 = ADD32(ctx->r5, 0X100);
    after_6:
    // 0x800D06E8: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
    // 0x800D06EC: sh          $v0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r2;
    // 0x800D06F0: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x800D06F4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800D06F8: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
L_800D06FC:
    // 0x800D06FC: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800D0700: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0704: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800D0708: lw          $t8, 0x54($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X54);
    // 0x800D070C: sll         $t9, $t0, 5
    ctx->r25 = S32(ctx->r8 << 5);
    // 0x800D0710: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D0714: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D0718: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D071C: addu        $a3, $t9, $t1
    ctx->r7 = ADD32(ctx->r25, ctx->r9);
    // 0x800D0720: jal         0x800CDE50
    // 0x800D0724: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_7;
    // 0x800D0724: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    after_7:
    // 0x800D0728: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D072C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800D0730: beq         $t2, $zero, L_800D0740
    if (ctx->r10 == 0) {
        // 0x800D0734: nop
    
            goto L_800D0740;
    }
    // 0x800D0734: nop

    // 0x800D0738: b           L_800D08E0
    // 0x800D073C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800D08E0;
    // 0x800D073C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800D0740:
    // 0x800D0740: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800D0744: lw          $t3, 0x14C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0748: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800D074C: lw          $t4, 0x58($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X58);
    // 0x800D0750: sll         $t6, $t3, 5
    ctx->r14 = S32(ctx->r11 << 5);
    // 0x800D0754: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D0758: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D075C: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D0760: addu        $a3, $t6, $t5
    ctx->r7 = ADD32(ctx->r14, ctx->r13);
    // 0x800D0764: jal         0x800CDE50
    // 0x800D0768: addu        $a2, $t4, $t3
    ctx->r6 = ADD32(ctx->r12, ctx->r11);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_8;
    // 0x800D0768: addu        $a2, $t4, $t3
    ctx->r6 = ADD32(ctx->r12, ctx->r11);
    after_8:
    // 0x800D076C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0770: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D0774: beq         $t8, $zero, L_800D0784
    if (ctx->r24 == 0) {
        // 0x800D0778: nop
    
            goto L_800D0784;
    }
    // 0x800D0778: nop

    // 0x800D077C: b           L_800D08E0
    // 0x800D0780: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D08E0;
    // 0x800D0780: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D0784:
    // 0x800D0784: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0788: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800D078C: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800D0790: bne         $at, $zero, L_800D06FC
    if (ctx->r1 != 0) {
        // 0x800D0794: sw          $t9, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r25;
            goto L_800D06FC;
    }
    // 0x800D0794: sw          $t9, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r25;
    // 0x800D0798: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800D079C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D07A0: sw          $t1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r9;
    // 0x800D07A4: lbu         $t7, 0x64($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X64);
    // 0x800D07A8: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800D07AC: bne         $at, $zero, L_800D08DC
    if (ctx->r1 != 0) {
        // 0x800D07B0: nop
    
            goto L_800D08DC;
    }
    // 0x800D07B0: nop

L_800D07B4:
    // 0x800D07B4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D07B8: sw          $t4, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r12;
L_800D07BC:
    // 0x800D07BC: lw          $t6, 0x14C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14C);
    // 0x800D07C0: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800D07C4: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x800D07C8: addu        $t8, $sp, $t5
    ctx->r24 = ADD32(ctx->r29, ctx->r13);
    // 0x800D07CC: sh          $t3, 0x48($t8)
    MEM_H(0X48, ctx->r24) = ctx->r11;
    // 0x800D07D0: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800D07D4: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800D07D8: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800D07DC: bne         $at, $zero, L_800D07BC
    if (ctx->r1 != 0) {
        // 0x800D07E0: sw          $t9, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r25;
            goto L_800D07BC;
    }
    // 0x800D07E0: sw          $t9, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r25;
    // 0x800D07E4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800D07E8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800D07EC: jal         0x800D5850
    // 0x800D07F0: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
    __osSumcalc(rdram, ctx);
        goto after_9;
    // 0x800D07F0: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
    after_9:
    // 0x800D07F4: addiu       $t1, $sp, 0x48
    ctx->r9 = ADD32(ctx->r29, 0X48);
    // 0x800D07F8: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // 0x800D07FC: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x800D0800: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800D0804: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
L_800D0808:
    // 0x800D0808: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800D080C: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800D0810: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0814: lw          $t4, 0x54($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X54);
    // 0x800D0818: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800D081C: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x800D0820: sll         $t0, $t8, 5
    ctx->r8 = S32(ctx->r24 << 5);
    // 0x800D0824: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x800D0828: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D082C: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D0830: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D0834: addu        $a2, $t5, $t8
    ctx->r6 = ADD32(ctx->r13, ctx->r24);
    // 0x800D0838: jal         0x800CDE50
    // 0x800D083C: addu        $a3, $t0, $t9
    ctx->r7 = ADD32(ctx->r8, ctx->r25);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_10;
    // 0x800D083C: addu        $a3, $t0, $t9
    ctx->r7 = ADD32(ctx->r8, ctx->r25);
    after_10:
    // 0x800D0840: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0844: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800D0848: beq         $t1, $zero, L_800D0858
    if (ctx->r9 == 0) {
        // 0x800D084C: nop
    
            goto L_800D0858;
    }
    // 0x800D084C: nop

    // 0x800D0850: b           L_800D08E0
    // 0x800D0854: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800D08E0;
    // 0x800D0854: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800D0858:
    // 0x800D0858: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800D085C: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800D0860: lw          $t5, 0x14C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0864: lw          $t7, 0x58($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X58);
    // 0x800D0868: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800D086C: sll         $t4, $t6, 3
    ctx->r12 = S32(ctx->r14 << 3);
    // 0x800D0870: sll         $t8, $t5, 5
    ctx->r24 = S32(ctx->r13 << 5);
    // 0x800D0874: addu        $t3, $t7, $t4
    ctx->r11 = ADD32(ctx->r15, ctx->r12);
    // 0x800D0878: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D087C: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D0880: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D0884: addu        $a2, $t3, $t5
    ctx->r6 = ADD32(ctx->r11, ctx->r13);
    // 0x800D0888: jal         0x800CDE50
    // 0x800D088C: addu        $a3, $t8, $t0
    ctx->r7 = ADD32(ctx->r24, ctx->r8);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_11;
    // 0x800D088C: addu        $a3, $t8, $t0
    ctx->r7 = ADD32(ctx->r24, ctx->r8);
    after_11:
    // 0x800D0890: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0894: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800D0898: beq         $t9, $zero, L_800D08A8
    if (ctx->r25 == 0) {
        // 0x800D089C: nop
    
            goto L_800D08A8;
    }
    // 0x800D089C: nop

    // 0x800D08A0: b           L_800D08E0
    // 0x800D08A4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800D08E0;
    // 0x800D08A4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800D08A8:
    // 0x800D08A8: lw          $t1, 0x14C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14C);
    // 0x800D08AC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800D08B0: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x800D08B4: bne         $at, $zero, L_800D0808
    if (ctx->r1 != 0) {
        // 0x800D08B8: sw          $t2, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r10;
            goto L_800D0808;
    }
    // 0x800D08B8: sw          $t2, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r10;
    // 0x800D08BC: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800D08C0: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x800D08C4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D08C8: sw          $t7, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r15;
    // 0x800D08CC: lbu         $t3, 0x64($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0X64);
    // 0x800D08D0: slt         $at, $t7, $t3
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800D08D4: bne         $at, $zero, L_800D07B4
    if (ctx->r1 != 0) {
        // 0x800D08D8: nop
    
            goto L_800D07B4;
    }
    // 0x800D08D8: nop

L_800D08DC:
    // 0x800D08DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D08E0:
    // 0x800D08E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D08E4: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    // 0x800D08E8: jr          $ra
    // 0x800D08EC: nop

    return;
    // 0x800D08EC: nop

;}
RECOMP_FUNC void bzero_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0A40: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x800D0A44: bne         $at, $zero, L_800D0ABC
    if (ctx->r1 != 0) {
        // 0x800D0A48: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_800D0ABC;
    }
    // 0x800D0A48: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x800D0A4C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x800D0A50: beq         $v1, $zero, L_800D0A60
    if (ctx->r3 == 0) {
        // 0x800D0A54: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_800D0A60;
    }
    // 0x800D0A54: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x800D0A58: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x800D0A5C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_800D0A60:
    // 0x800D0A60: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800D0A64: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800D0A68: beq         $a3, $zero, L_800D0A9C
    if (ctx->r7 == 0) {
        // 0x800D0A6C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800D0A9C;
    }
    // 0x800D0A6C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800D0A70: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800D0A74:
    // 0x800D0A74: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800D0A78: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x800D0A7C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x800D0A80: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x800D0A84: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x800D0A88: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x800D0A8C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x800D0A90: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x800D0A94: bne         $a0, $a3, L_800D0A74
    if (ctx->r4 != ctx->r7) {
        // 0x800D0A98: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800D0A74;
    }
    // 0x800D0A98: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800D0A9C:
    // 0x800D0A9C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D0AA0: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800D0AA4: beq         $a3, $zero, L_800D0ABC
    if (ctx->r7 == 0) {
        // 0x800D0AA8: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800D0ABC;
    }
    // 0x800D0AA8: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800D0AAC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800D0AB0:
    // 0x800D0AB0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800D0AB4: bne         $a0, $a3, L_800D0AB0
    if (ctx->r4 != ctx->r7) {
        // 0x800D0AB8: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800D0AB0;
    }
    // 0x800D0AB8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800D0ABC:
    // 0x800D0ABC: blez        $a1, L_800D0AD4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D0AC0: nop
    
            goto L_800D0AD4;
    }
    // 0x800D0AC0: nop

    // 0x800D0AC4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_800D0AC8:
    // 0x800D0AC8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D0ACC: bne         $a0, $a1, L_800D0AC8
    if (ctx->r4 != ctx->r5) {
        // 0x800D0AD0: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_800D0AC8;
    }
    // 0x800D0AD0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_800D0AD4:
    // 0x800D0AD4: jr          $ra
    // 0x800D0AD8: nop

    return;
    // 0x800D0AD8: nop

    // 0x800D0ADC: nop

;}
RECOMP_FUNC void __osPfsReleasePages(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D10B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D10B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D10B8: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x800D10BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D10C0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800D10C4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800D10C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D10CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D10D0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800D10D4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800D10D8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800D10DC: lhu         $at, 0x0($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X0);
    // 0x800D10E0: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x800D10E4: sh          $at, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r1;
    // 0x800D10E8: lhu         $t4, 0x24($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X24);
    // 0x800D10EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D10F0: beq         $t4, $at, L_800D1120
    if (ctx->r12 == ctx->r1) {
        // 0x800D10F4: nop
    
            goto L_800D1120;
    }
    // 0x800D10F4: nop

    // 0x800D10F8: lbu         $t5, 0x24($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X24);
    // 0x800D10FC: blez        $t5, L_800D1110
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800D1100: nop
    
            goto L_800D1110;
    }
    // 0x800D1100: nop

    // 0x800D1104: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D1108: b           L_800D1144
    // 0x800D110C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_800D1144;
    // 0x800D110C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_800D1110:
    // 0x800D1110: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D1114: lw          $t9, 0x60($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X60);
    // 0x800D1118: b           L_800D1144
    // 0x800D111C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
        goto L_800D1144;
    // 0x800D111C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800D1120:
    // 0x800D1120: lbu         $t2, 0x3B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3B);
    // 0x800D1124: blez        $t2, L_800D1138
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800D1128: nop
    
            goto L_800D1138;
    }
    // 0x800D1128: nop

    // 0x800D112C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D1130: b           L_800D1144
    // 0x800D1134: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
        goto L_800D1144;
    // 0x800D1134: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_800D1138:
    // 0x800D1138: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800D113C: lw          $t0, 0x60($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X60);
    // 0x800D1140: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_800D1144:
    // 0x800D1144: lbu         $t3, 0x25($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X25);
    // 0x800D1148: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800D114C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800D1150: beq         $at, $zero, L_800D1170
    if (ctx->r1 == 0) {
        // 0x800D1154: nop
    
            goto L_800D1170;
    }
    // 0x800D1154: nop

    // 0x800D1158: lhu         $t5, 0x24($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X24);
    // 0x800D115C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D1160: beq         $t5, $at, L_800D1170
    if (ctx->r13 == ctx->r1) {
        // 0x800D1164: nop
    
            goto L_800D1170;
    }
    // 0x800D1164: nop

    // 0x800D1168: b           L_800D12D8
    // 0x800D116C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800D12D8;
    // 0x800D116C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800D1170:
    // 0x800D1170: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x800D1174: lhu         $at, 0x0($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X0);
    // 0x800D1178: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800D117C: sh          $at, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r1;
    // 0x800D1180: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800D1184: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D1188: bne         $t1, $at, L_800D11A8
    if (ctx->r9 != ctx->r1) {
        // 0x800D118C: nop
    
            goto L_800D11A8;
    }
    // 0x800D118C: nop

    // 0x800D1190: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x800D1194: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1198: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800D119C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800D11A0: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800D11A4: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_800D11A8:
    // 0x800D11A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800D11AC: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    // 0x800D11B0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800D11B4: jal         0x800D12E8
    // 0x800D11B8: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    __osBlockSum(rdram, ctx);
        goto after_0;
    // 0x800D11B8: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    after_0:
    // 0x800D11BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D11C0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800D11C4: beq         $t9, $zero, L_800D11D4
    if (ctx->r25 == 0) {
        // 0x800D11C8: nop
    
            goto L_800D11D4;
    }
    // 0x800D11C8: nop

    // 0x800D11CC: b           L_800D12D8
    // 0x800D11D0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800D12D8;
    // 0x800D11D0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800D11D4:
    // 0x800D11D4: lhu         $t8, 0x24($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X24);
    // 0x800D11D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D11DC: bne         $t8, $at, L_800D11EC
    if (ctx->r24 != ctx->r1) {
        // 0x800D11E0: nop
    
            goto L_800D11EC;
    }
    // 0x800D11E0: nop

    // 0x800D11E4: b           L_800D12D8
    // 0x800D11E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D12D8;
    // 0x800D11E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D11EC:
    // 0x800D11EC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800D11F0: lhu         $t7, 0x24($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X24);
    // 0x800D11F4: lw          $t1, 0x60($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X60);
    // 0x800D11F8: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D11FC: bne         $at, $zero, L_800D1294
    if (ctx->r1 != 0) {
        // 0x800D1200: nop
    
            goto L_800D1294;
    }
    // 0x800D1200: nop

L_800D1204:
    // 0x800D1204: lbu         $t6, 0x25($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X25);
    // 0x800D1208: lhu         $t3, 0x24($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X24);
    // 0x800D120C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1210: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x800D1214: sh          $t3, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r11;
    // 0x800D1218: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x800D121C: lhu         $at, 0x0($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X0);
    // 0x800D1220: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800D1224: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800D1228: sh          $at, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r1;
    // 0x800D122C: lbu         $t3, 0x21($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X21);
    // 0x800D1230: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1234: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800D1238: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x800D123C: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x800D1240: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    // 0x800D1244: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800D1248: lbu         $a1, 0x21($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X21);
    // 0x800D124C: jal         0x800D12E8
    // 0x800D1250: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osBlockSum(rdram, ctx);
        goto after_1;
    // 0x800D1250: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800D1254: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D1258: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800D125C: beq         $t5, $zero, L_800D126C
    if (ctx->r13 == 0) {
        // 0x800D1260: nop
    
            goto L_800D126C;
    }
    // 0x800D1260: nop

    // 0x800D1264: b           L_800D12D8
    // 0x800D1268: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800D12D8;
    // 0x800D1268: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800D126C:
    // 0x800D126C: lbu         $t8, 0x24($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X24);
    // 0x800D1270: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x800D1274: bne         $t8, $t0, L_800D1294
    if (ctx->r24 != ctx->r8) {
        // 0x800D1278: nop
    
            goto L_800D1294;
    }
    // 0x800D1278: nop

    // 0x800D127C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800D1280: lhu         $t9, 0x24($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X24);
    // 0x800D1284: lw          $t3, 0x60($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X60);
    // 0x800D1288: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800D128C: beq         $at, $zero, L_800D1204
    if (ctx->r1 == 0) {
        // 0x800D1290: nop
    
            goto L_800D1204;
    }
    // 0x800D1290: nop

L_800D1294:
    // 0x800D1294: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800D1298: lhu         $t1, 0x24($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X24);
    // 0x800D129C: lw          $t7, 0x60($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X60);
    // 0x800D12A0: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D12A4: bne         $at, $zero, L_800D12C4
    if (ctx->r1 != 0) {
        // 0x800D12A8: nop
    
            goto L_800D12C4;
    }
    // 0x800D12A8: nop

    // 0x800D12AC: lbu         $t8, 0x25($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X25);
    // 0x800D12B0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800D12B4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800D12B8: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800D12BC: addu        $t2, $t5, $t0
    ctx->r10 = ADD32(ctx->r13, ctx->r8);
    // 0x800D12C0: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
L_800D12C4:
    // 0x800D12C4: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x800D12C8: lhu         $at, 0x0($t3)
    ctx->r1 = MEM_HU(ctx->r11, 0X0);
    // 0x800D12CC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800D12D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D12D4: sh          $at, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r1;
L_800D12D8:
    // 0x800D12D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D12DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D12E0: jr          $ra
    // 0x800D12E4: nop

    return;
    // 0x800D12E4: nop

;}
RECOMP_FUNC void __osBlockSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D12E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D12EC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800D12F0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800D12F4: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x800D12F8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800D12FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1300: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800D1304: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800D1308: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800D130C: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x800D1310: jal         0x800D653C
    // 0x800D1314: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x800D1314: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x800D1318: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800D131C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800D1320: beq         $t8, $zero, L_800D1330
    if (ctx->r24 == 0) {
        // 0x800D1324: nop
    
            goto L_800D1330;
    }
    // 0x800D1324: nop

    // 0x800D1328: b           L_800D13C8
    // 0x800D132C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D13C8;
    // 0x800D132C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D1330:
    // 0x800D1330: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_800D1334:
    // 0x800D1334: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x800D1338: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800D133C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800D1340: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800D1344: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x800D1348: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800D134C: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x800D1350: jal         0x800CE200
    // 0x800D1354: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamRead_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1354: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800D1358: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800D135C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800D1360: beq         $t3, $zero, L_800D1380
    if (ctx->r11 == 0) {
        // 0x800D1364: nop
    
            goto L_800D1380;
    }
    // 0x800D1364: nop

    // 0x800D1368: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800D136C: sb          $zero, 0x65($t4)
    MEM_B(0X65, ctx->r12) = 0;
    // 0x800D1370: jal         0x800D653C
    // 0x800D1374: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800D1374: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x800D1378: b           L_800D13C8
    // 0x800D137C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_800D13C8;
    // 0x800D137C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800D1380:
    // 0x800D1380: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800D1384: jal         0x800D5850
    // 0x800D1388: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    __osSumcalc(rdram, ctx);
        goto after_3;
    // 0x800D1388: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_3:
    // 0x800D138C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800D1390: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800D1394: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800D1398: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
    // 0x800D139C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800D13A0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D13A4: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800D13A8: bne         $at, $zero, L_800D1334
    if (ctx->r1 != 0) {
        // 0x800D13AC: sw          $t9, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r25;
            goto L_800D1334;
    }
    // 0x800D13AC: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800D13B0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800D13B4: sb          $zero, 0x65($t0)
    MEM_B(0X65, ctx->r8) = 0;
    // 0x800D13B8: jal         0x800D653C
    // 0x800D13BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_4;
    // 0x800D13BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x800D13C0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800D13C4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800D13C8:
    // 0x800D13C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D13CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800D13D0: jr          $ra
    // 0x800D13D4: nop

    return;
    // 0x800D13D4: nop

    // 0x800D13D8: nop

    // 0x800D13DC: nop

;}
RECOMP_FUNC void __osPfsDeclearPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1A24: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D1A28: lbu         $t6, 0x63($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X63);
    // 0x800D1A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1A30: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800D1A34: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800D1A38: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800D1A3C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800D1A40: blez        $t6, L_800D1A54
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D1A44: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_800D1A54;
    }
    // 0x800D1A44: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800D1A48: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D1A4C: b           L_800D1A60
    // 0x800D1A50: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
        goto L_800D1A60;
    // 0x800D1A50: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_800D1A54:
    // 0x800D1A54: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800D1A58: lw          $t9, 0x60($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X60);
    // 0x800D1A5C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800D1A60:
    // 0x800D1A60: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800D1A64: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800D1A68: beq         $at, $zero, L_800D1AA4
    if (ctx->r1 == 0) {
        // 0x800D1A6C: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_800D1AA4;
    }
    // 0x800D1A6C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_800D1A70:
    // 0x800D1A70: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1A74: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800D1A78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D1A7C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800D1A80: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800D1A84: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800D1A88: beq         $t5, $at, L_800D1AA4
    if (ctx->r13 == ctx->r1) {
        // 0x800D1A8C: nop
    
            goto L_800D1AA4;
    }
    // 0x800D1A8C: nop

    // 0x800D1A90: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1A94: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D1A98: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800D1A9C: bne         $at, $zero, L_800D1A70
    if (ctx->r1 != 0) {
        // 0x800D1AA0: sw          $t7, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r15;
            goto L_800D1A70;
    }
    // 0x800D1AA0: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_800D1AA4:
    // 0x800D1AA4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1AA8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800D1AAC: bne         $t8, $at, L_800D1AC8
    if (ctx->r24 != ctx->r1) {
        // 0x800D1AB0: nop
    
            goto L_800D1AC8;
    }
    // 0x800D1AB0: nop

    // 0x800D1AB4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800D1AB8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800D1ABC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800D1AC0: b           L_800D1C78
    // 0x800D1AC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800D1C78;
    // 0x800D1AC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800D1AC8:
    // 0x800D1AC8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800D1ACC:
    // 0x800D1ACC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800D1AD0: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x800D1AD4: sb          $zero, 0x24($t1)
    MEM_B(0X24, ctx->r9) = 0;
    // 0x800D1AD8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800D1ADC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800D1AE0: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x800D1AE4: bne         $at, $zero, L_800D1ACC
    if (ctx->r1 != 0) {
        // 0x800D1AE8: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_800D1ACC;
    }
    // 0x800D1AE8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800D1AEC: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1AF0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800D1AF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D1AF8: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x800D1AFC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800D1B00: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1B04: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800D1B08: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800D1B0C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D1B10: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800D1B14: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800D1B18: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x800D1B1C: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D1B20: beq         $at, $zero, L_800D1BF4
    if (ctx->r1 == 0) {
        // 0x800D1B24: slti        $at, $t9, 0x80
        ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
            goto L_800D1BF4;
    }
    // 0x800D1B24: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800D1B28: beq         $at, $zero, L_800D1BF4
    if (ctx->r1 == 0) {
        // 0x800D1B2C: nop
    
            goto L_800D1BF4;
    }
    // 0x800D1B2C: nop

L_800D1B30:
    // 0x800D1B30: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1B34: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800D1B38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D1B3C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800D1B40: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800D1B44: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800D1B48: bne         $t7, $at, L_800D1BC0
    if (ctx->r15 != ctx->r1) {
        // 0x800D1B4C: nop
    
            goto L_800D1BC0;
    }
    // 0x800D1B4C: nop

    // 0x800D1B50: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800D1B54: lbu         $t8, 0x63($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X63);
    // 0x800D1B58: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800D1B5C: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x800D1B60: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x800D1B64: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
    // 0x800D1B68: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800D1B6C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800D1B70: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1B74: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800D1B78: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800D1B7C: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x800D1B80: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x800D1B84: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800D1B88: jal         0x800D1C88
    // 0x800D1B8C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    static_0_800D1C88(rdram, ctx);
        goto after_0;
    // 0x800D1B8C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x800D1B90: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D1B94: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1B98: beq         $t2, $zero, L_800D1BA8
    if (ctx->r10 == 0) {
        // 0x800D1B9C: nop
    
            goto L_800D1BA8;
    }
    // 0x800D1B9C: nop

    // 0x800D1BA0: b           L_800D1C78
    // 0x800D1BA4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800D1C78;
    // 0x800D1BA4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800D1BA8:
    // 0x800D1BA8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1BAC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800D1BB0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800D1BB4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800D1BB8: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x800D1BBC: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
L_800D1BC0:
    // 0x800D1BC0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1BC4: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800D1BC8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800D1BCC: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800D1BD0: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800D1BD4: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800D1BD8: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D1BDC: beq         $at, $zero, L_800D1BF4
    if (ctx->r1 == 0) {
        // 0x800D1BE0: nop
    
            goto L_800D1BF4;
    }
    // 0x800D1BE0: nop

    // 0x800D1BE4: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1BE8: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x800D1BEC: bne         $at, $zero, L_800D1B30
    if (ctx->r1 != 0) {
        // 0x800D1BF0: nop
    
            goto L_800D1B30;
    }
    // 0x800D1BF0: nop

L_800D1BF4:
    // 0x800D1BF4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800D1BF8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800D1BFC: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800D1C00: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800D1C04: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1C08: bne         $t1, $at, L_800D1C3C
    if (ctx->r9 != ctx->r1) {
        // 0x800D1C0C: nop
    
            goto L_800D1C3C;
    }
    // 0x800D1C0C: nop

    // 0x800D1C10: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800D1C14: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800D1C18: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x800D1C1C: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D1C20: beq         $at, $zero, L_800D1C3C
    if (ctx->r1 == 0) {
        // 0x800D1C24: nop
    
            goto L_800D1C3C;
    }
    // 0x800D1C24: nop

    // 0x800D1C28: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800D1C2C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800D1C30: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800D1C34: b           L_800D1C78
    // 0x800D1C38: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800D1C78;
    // 0x800D1C38: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800D1C3C:
    // 0x800D1C3C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800D1C40: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800D1C44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D1C48: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x800D1C4C: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800D1C50: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x800D1C54: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x800D1C58: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800D1C5C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800D1C60: jal         0x800D1C88
    // 0x800D1C64: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    static_0_800D1C88(rdram, ctx);
        goto after_1;
    // 0x800D1C64: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800D1C68: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800D1C6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D1C70: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800D1C74: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800D1C78:
    // 0x800D1C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1C7C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800D1C80: jr          $ra
    // 0x800D1C84: nop

    return;
    // 0x800D1C84: nop

    // 0x800D1C88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D1C8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D1C90: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800D1C94: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x800D1C98: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D1C9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D1CA0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D1CA4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D1CA8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800D1CAC: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x800D1CB0: jal         0x800D653C
    // 0x800D1CB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800D1CB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800D1CB8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D1CBC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D1CC0: beq         $t8, $zero, L_800D1CD0
    if (ctx->r24 == 0) {
        // 0x800D1CC4: nop
    
            goto L_800D1CD0;
    }
    // 0x800D1CC4: nop

    // 0x800D1CC8: b           L_800D1D38
    // 0x800D1CCC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D1D38;
    // 0x800D1CCC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D1CD0:
    // 0x800D1CD0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800D1CD4:
    // 0x800D1CD4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800D1CD8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1CDC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800D1CE0: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800D1CE4: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x800D1CE8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800D1CEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D1CF0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800D1CF4: jal         0x800CDE50
    // 0x800D1CF8: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_3;
    // 0x800D1CF8: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_3:
    // 0x800D1CFC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D1D00: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800D1D04: bne         $t3, $zero, L_800D1D20
    if (ctx->r11 != 0) {
        // 0x800D1D08: nop
    
            goto L_800D1D20;
    }
    // 0x800D1D08: nop

    // 0x800D1D0C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800D1D10: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800D1D14: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x800D1D18: bne         $at, $zero, L_800D1CD4
    if (ctx->r1 != 0) {
        // 0x800D1D1C: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_800D1CD4;
    }
    // 0x800D1D1C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_800D1D20:
    // 0x800D1D20: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800D1D24: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x800D1D28: jal         0x800D653C
    // 0x800D1D2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_4;
    // 0x800D1D2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x800D1D30: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D1D34: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_800D1D38:
    // 0x800D1D38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1D3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D1D40: jr          $ra
    // 0x800D1D44: nop

    return;
    // 0x800D1D44: nop

    // 0x800D1D48: nop

    // 0x800D1D4C: nop

;}
RECOMP_FUNC void __osGetActiveQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D29D0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800D29D4: jr          $ra
    // 0x800D29D8: lw          $v0, 0x4E1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4E1C);
    return;
    // 0x800D29D8: lw          $v0, 0x4E1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4E1C);
    // 0x800D29DC: nop

;}
RECOMP_FUNC void alSynDelete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D31C0: jr          $ra
    // 0x800D31C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x800D31C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800D31C8: nop

    // 0x800D31CC: nop

;}
RECOMP_FUNC void alCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D3D84: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800D3D88: blez        $a2, L_800D3DEC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800D3D8C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800D3DEC;
    }
    // 0x800D3D8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D3D90: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x800D3D94: beq         $a1, $zero, L_800D3DBC
    if (ctx->r5 == 0) {
        // 0x800D3D98: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800D3DBC;
    }
    // 0x800D3D98: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800D3D9C:
    // 0x800D3D9C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800D3DA0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800D3DA4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D3DA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D3DAC: bne         $a0, $a3, L_800D3D9C
    if (ctx->r4 != ctx->r7) {
        // 0x800D3DB0: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_800D3D9C;
    }
    // 0x800D3DB0: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x800D3DB4: beq         $a3, $a2, L_800D3DEC
    if (ctx->r7 == ctx->r6) {
        // 0x800D3DB8: nop
    
            goto L_800D3DEC;
    }
    // 0x800D3DB8: nop

L_800D3DBC:
    // 0x800D3DBC: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800D3DC0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800D3DC4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D3DC8: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x800D3DCC: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800D3DD0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D3DD4: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x800D3DD8: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x800D3DDC: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x800D3DE0: lbu         $t0, -0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X1);
    // 0x800D3DE4: bne         $a3, $a2, L_800D3DBC
    if (ctx->r7 != ctx->r6) {
        // 0x800D3DE8: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_800D3DBC;
    }
    // 0x800D3DE8: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
L_800D3DEC:
    // 0x800D3DEC: jr          $ra
    // 0x800D3DF0: nop

    return;
    // 0x800D3DF0: nop

    // 0x800D3DF4: nop

    // 0x800D3DF8: nop

    // 0x800D3DFC: nop

    // 0x800D3E00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3E04: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800D3E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3E0C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800D3E10: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x800D3E14: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800D3E18: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800D3E1C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800D3E20: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800D3E24: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800D3E28: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x800D3E2C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800D3E30: bne         $at, $zero, L_800D3E5C
    if (ctx->r1 != 0) {
        // 0x800D3E34: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800D3E5C;
    }
    // 0x800D3E34: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800D3E38: addiu       $t7, $t6, -0x45
    ctx->r15 = ADD32(ctx->r14, -0X45);
    // 0x800D3E3C: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x800D3E40: beq         $at, $zero, L_800D4448
    if (ctx->r1 == 0) {
        // 0x800D3E44: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800D4448;
    }
    // 0x800D3E44: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D3E48: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D3E4C: addu        $at, $at, $t7
    gpr jr_addend_800D3E54 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D3E50: lw          $t7, -0x639C($at)
    ctx->r15 = ADD32(ctx->r1, -0X639C);
    // 0x800D3E54: jr          $t7
    // 0x800D3E58: nop

    switch (jr_addend_800D3E54 >> 2) {
        case 0: goto L_800D4168; break;
        case 1: goto L_800D4448; break;
        case 2: goto L_800D4168; break;
        case 3: goto L_800D4448; break;
        case 4: goto L_800D4448; break;
        case 5: goto L_800D4448; break;
        case 6: goto L_800D4448; break;
        case 7: goto L_800D4448; break;
        case 8: goto L_800D4448; break;
        case 9: goto L_800D4448; break;
        case 10: goto L_800D4448; break;
        case 11: goto L_800D4448; break;
        case 12: goto L_800D4448; break;
        case 13: goto L_800D4448; break;
        case 14: goto L_800D4448; break;
        case 15: goto L_800D4448; break;
        case 16: goto L_800D4448; break;
        case 17: goto L_800D4448; break;
        case 18: goto L_800D4448; break;
        case 19: goto L_800D4018; break;
        case 20: goto L_800D4448; break;
        case 21: goto L_800D4448; break;
        case 22: goto L_800D4448; break;
        case 23: goto L_800D4448; break;
        case 24: goto L_800D4448; break;
        case 25: goto L_800D4448; break;
        case 26: goto L_800D4448; break;
        case 27: goto L_800D4448; break;
        case 28: goto L_800D4448; break;
        case 29: goto L_800D4448; break;
        case 30: goto L_800D3E70; break;
        case 31: goto L_800D3EA8; break;
        case 32: goto L_800D4168; break;
        case 33: goto L_800D4168; break;
        case 34: goto L_800D4168; break;
        case 35: goto L_800D4448; break;
        case 36: goto L_800D3EA8; break;
        case 37: goto L_800D4448; break;
        case 38: goto L_800D4448; break;
        case 39: goto L_800D4448; break;
        case 40: goto L_800D4448; break;
        case 41: goto L_800D42CC; break;
        case 42: goto L_800D4018; break;
        case 43: goto L_800D439C; break;
        case 44: goto L_800D4448; break;
        case 45: goto L_800D4448; break;
        case 46: goto L_800D43E4; break;
        case 47: goto L_800D4448; break;
        case 48: goto L_800D4018; break;
        case 49: goto L_800D4448; break;
        case 50: goto L_800D4448; break;
        case 51: goto L_800D4018; break;
        default: switch_error(__func__, 0x800D3E54, 0x800E9C64);
    }
    // 0x800D3E58: nop

L_800D3E5C:
    // 0x800D3E5C: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x800D3E60: beql        $v1, $at, L_800D442C
    if (ctx->r3 == ctx->r1) {
        // 0x800D3E64: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800D442C;
    }
    goto skip_0;
    // 0x800D3E64: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x800D3E68: b           L_800D444C
    // 0x800D3E6C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_800D444C;
    // 0x800D3E6C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800D3E70:
    // 0x800D3E70: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D3E74: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3E78: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800D3E7C: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x800D3E80: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800D3E84: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D3E88: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D3E8C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800D3E90: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800D3E94: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800D3E98: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D3E9C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800D3EA0: b           L_800D4460
    // 0x800D3EA4: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_800D4460;
    // 0x800D3EA4: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800D3EA8:
    // 0x800D3EA8: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800D3EAC: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800D3EB0: bnel        $v0, $at, L_800D3EE8
    if (ctx->r2 != ctx->r1) {
        // 0x800D3EB4: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800D3EE8;
    }
    goto skip_1;
    // 0x800D3EB4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_1:
    // 0x800D3EB8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800D3EBC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3EC0: addiu       $t7, $t9, 0x3
    ctx->r15 = ADD32(ctx->r25, 0X3);
    // 0x800D3EC4: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D3EC8: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800D3ECC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D3ED0: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x800D3ED4: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800D3ED8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3EDC: b           L_800D3F44
    // 0x800D3EE0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800D3F44;
    // 0x800D3EE0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800D3EE4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800D3EE8:
    // 0x800D3EE8: bnel        $v0, $at, L_800D3F20
    if (ctx->r2 != ctx->r1) {
        // 0x800D3EEC: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_800D3F20;
    }
    goto skip_2;
    // 0x800D3EEC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x800D3EF0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800D3EF4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D3EF8: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800D3EFC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D3F00: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800D3F04: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D3F08: lw          $t8, -0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X8);
    // 0x800D3F0C: lw          $t9, -0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4);
    // 0x800D3F10: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3F14: b           L_800D3F44
    // 0x800D3F18: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800D3F44;
    // 0x800D3F18: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800D3F1C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_800D3F20:
    // 0x800D3F20: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3F24: addiu       $t6, $t7, 0x3
    ctx->r14 = ADD32(ctx->r15, 0X3);
    // 0x800D3F28: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800D3F2C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800D3F30: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D3F34: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x800D3F38: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800D3F3C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3F40: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_800D3F44:
    // 0x800D3F44: lbu         $t7, 0x34($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X34);
    // 0x800D3F48: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800D3F4C: bnel        $t7, $at, L_800D3F70
    if (ctx->r15 != ctx->r1) {
        // 0x800D3F50: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_800D3F70;
    }
    goto skip_3;
    // 0x800D3F50: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x800D3F54: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800D3F58: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800D3F5C: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D3F60: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800D3F64: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3F68: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800D3F6C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_800D3F70:
    // 0x800D3F70: bgtzl       $t6, L_800D3FAC
    if (SIGNED(ctx->r14) > 0) {
        // 0x800D3F74: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_800D3FAC;
    }
    goto skip_4;
    // 0x800D3F74: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x800D3F78: bltzl       $t6, L_800D3F8C
    if (SIGNED(ctx->r14) < 0) {
        // 0x800D3F7C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_800D3F8C;
    }
    goto skip_5;
    // 0x800D3F7C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x800D3F80: b           L_800D3FAC
    // 0x800D3F84: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_800D3FAC;
    // 0x800D3F84: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800D3F88: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_800D3F8C:
    // 0x800D3F8C: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800D3F90: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800D3F94: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800D3F98: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D3F9C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800D3FA0: b           L_800D3FFC
    // 0x800D3FA4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
        goto L_800D3FFC;
    // 0x800D3FA4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800D3FA8: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_800D3FAC:
    // 0x800D3FAC: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x800D3FB0: beq         $t8, $zero, L_800D3FD8
    if (ctx->r24 == 0) {
        // 0x800D3FB4: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_800D3FD8;
    }
    // 0x800D3FB4: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800D3FB8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D3FBC: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x800D3FC0: addu        $t9, $a3, $t7
    ctx->r25 = ADD32(ctx->r7, ctx->r15);
    // 0x800D3FC4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800D3FC8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D3FCC: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800D3FD0: b           L_800D3FFC
    // 0x800D3FD4: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
        goto L_800D3FFC;
    // 0x800D3FD4: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_800D3FD8:
    // 0x800D3FD8: beql        $t6, $zero, L_800D4000
    if (ctx->r14 == 0) {
        // 0x800D3FDC: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_800D4000;
    }
    goto skip_6;
    // 0x800D3FDC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x800D3FE0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D3FE4: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x800D3FE8: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800D3FEC: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800D3FF0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D3FF4: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800D3FF8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800D3FFC:
    // 0x800D3FFC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_800D4000:
    // 0x800D4000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4004: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x800D4008: jal         0x800D6C60
    // 0x800D400C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_0;
    // 0x800D400C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_0:
    // 0x800D4010: b           L_800D4464
    // 0x800D4014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D4464;
    // 0x800D4014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D4018:
    // 0x800D4018: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800D401C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800D4020: bnel        $v0, $at, L_800D4058
    if (ctx->r2 != ctx->r1) {
        // 0x800D4024: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800D4058;
    }
    goto skip_7;
    // 0x800D4024: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_7:
    // 0x800D4028: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800D402C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D4030: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x800D4034: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800D4038: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x800D403C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D4040: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x800D4044: sra         $t6, $t8, 31
    ctx->r14 = S32(SIGNED(ctx->r24) >> 31);
    // 0x800D4048: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800D404C: b           L_800D40B4
    // 0x800D4050: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800D40B4;
    // 0x800D4050: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800D4054: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800D4058:
    // 0x800D4058: bnel        $v0, $at, L_800D4090
    if (ctx->r2 != ctx->r1) {
        // 0x800D405C: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_800D4090;
    }
    goto skip_8;
    // 0x800D405C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    skip_8:
    // 0x800D4060: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800D4064: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D4068: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x800D406C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800D4070: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D4074: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D4078: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800D407C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x800D4080: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800D4084: b           L_800D40B4
    // 0x800D4088: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_800D40B4;
    // 0x800D4088: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D408C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_800D4090:
    // 0x800D4090: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D4094: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x800D4098: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D409C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800D40A0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D40A4: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x800D40A8: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800D40AC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D40B0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800D40B4:
    // 0x800D40B4: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800D40B8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800D40BC: bne         $v0, $at, L_800D40DC
    if (ctx->r2 != ctx->r1) {
        // 0x800D40C0: nop
    
            goto L_800D40DC;
    }
    // 0x800D40C0: nop

    // 0x800D40C4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800D40C8: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800D40CC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800D40D0: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800D40D4: b           L_800D40F4
    // 0x800D40D8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800D40F4;
    // 0x800D40D8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800D40DC:
    // 0x800D40DC: bnel        $v0, $zero, L_800D40F8
    if (ctx->r2 != 0) {
        // 0x800D40E0: lw          $t7, 0x30($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X30);
            goto L_800D40F8;
    }
    goto skip_9;
    // 0x800D40E0: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    skip_9:
    // 0x800D40E4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800D40E8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800D40EC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D40F0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800D40F4:
    // 0x800D40F4: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
L_800D40F8:
    // 0x800D40F8: andi        $t6, $t7, 0x8
    ctx->r14 = ctx->r15 & 0X8;
    // 0x800D40FC: beql        $t6, $zero, L_800D4150
    if (ctx->r14 == 0) {
        // 0x800D4100: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800D4150;
    }
    goto skip_10;
    // 0x800D4100: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_10:
    // 0x800D4104: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800D4108: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x800D410C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800D4110: addu        $t7, $a3, $t9
    ctx->r15 = ADD32(ctx->r7, ctx->r25);
    // 0x800D4114: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x800D4118: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D411C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800D4120: beq         $v1, $at, L_800D4134
    if (ctx->r3 == ctx->r1) {
        // 0x800D4124: sw          $t9, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r25;
            goto L_800D4134;
    }
    // 0x800D4124: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800D4128: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x800D412C: bnel        $v1, $at, L_800D4150
    if (ctx->r3 != ctx->r1) {
        // 0x800D4130: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800D4150;
    }
    goto skip_11;
    // 0x800D4130: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_11:
L_800D4134:
    // 0x800D4134: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D4138: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800D413C: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
    // 0x800D4140: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D4144: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800D4148: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800D414C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800D4150:
    // 0x800D4150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4154: addu        $t7, $t8, $a3
    ctx->r15 = ADD32(ctx->r24, ctx->r7);
    // 0x800D4158: jal         0x800D6C60
    // 0x800D415C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_1;
    // 0x800D415C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_1:
    // 0x800D4160: b           L_800D4464
    // 0x800D4164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D4464;
    // 0x800D4164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D4168:
    // 0x800D4168: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x800D416C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800D4170: bnel        $t6, $at, L_800D41D8
    if (ctx->r14 != ctx->r1) {
        // 0x800D4174: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_800D41D8;
    }
    goto skip_12;
    // 0x800D4174: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_12:
    // 0x800D4178: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800D417C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800D4180: beq         $t9, $zero, L_800D4198
    if (ctx->r25 == 0) {
        // 0x800D4184: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D4198;
    }
    // 0x800D4184: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D4188: addiu       $t8, $v1, 0x7
    ctx->r24 = ADD32(ctx->r3, 0X7);
    // 0x800D418C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800D4190: b           L_800D41C8
    // 0x800D4194: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
        goto L_800D41C8;
    // 0x800D4194: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
L_800D4198:
    // 0x800D4198: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800D419C: beq         $t7, $zero, L_800D41B4
    if (ctx->r15 == 0) {
        // 0x800D41A0: addiu       $t9, $v0, 0x7
        ctx->r25 = ADD32(ctx->r2, 0X7);
            goto L_800D41B4;
    }
    // 0x800D41A0: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x800D41A4: addiu       $t6, $v1, 0xA
    ctx->r14 = ADD32(ctx->r3, 0XA);
    // 0x800D41A8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D41AC: b           L_800D41C4
    // 0x800D41B0: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
        goto L_800D41C4;
    // 0x800D41B0: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
L_800D41B4:
    // 0x800D41B4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D41B8: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800D41BC: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x800D41C0: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800D41C4:
    // 0x800D41C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D41C8:
    // 0x800D41C8: ldc1        $f4, -0x8($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, -0X8);
    // 0x800D41CC: b           L_800D422C
    // 0x800D41D0: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
        goto L_800D422C;
    // 0x800D41D0: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
    // 0x800D41D4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_800D41D8:
    // 0x800D41D8: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800D41DC: beq         $t6, $zero, L_800D41F4
    if (ctx->r14 == 0) {
        // 0x800D41E0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D41F4;
    }
    // 0x800D41E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D41E4: addiu       $t9, $v1, 0x7
    ctx->r25 = ADD32(ctx->r3, 0X7);
    // 0x800D41E8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D41EC: b           L_800D4224
    // 0x800D41F0: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
        goto L_800D4224;
    // 0x800D41F0: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
L_800D41F4:
    // 0x800D41F4: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x800D41F8: beq         $t8, $zero, L_800D4210
    if (ctx->r24 == 0) {
        // 0x800D41FC: addiu       $t6, $v0, 0x7
        ctx->r14 = ADD32(ctx->r2, 0X7);
            goto L_800D4210;
    }
    // 0x800D41FC: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x800D4200: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x800D4204: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D4208: b           L_800D4220
    // 0x800D420C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
        goto L_800D4220;
    // 0x800D420C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
L_800D4210:
    // 0x800D4210: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D4214: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x800D4218: addiu       $a0, $t9, 0x8
    ctx->r4 = ADD32(ctx->r25, 0X8);
    // 0x800D421C: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800D4220:
    // 0x800D4220: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D4224:
    // 0x800D4224: ldc1        $f6, -0x8($v0)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r2, -0X8);
    // 0x800D4228: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
L_800D422C:
    // 0x800D422C: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x800D4230: andi        $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 & 0X8000;
    // 0x800D4234: beql        $t6, $zero, L_800D4260
    if (ctx->r14 == 0) {
        // 0x800D4238: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_800D4260;
    }
    goto skip_13;
    // 0x800D4238: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_13:
    // 0x800D423C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D4240: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800D4244: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800D4248: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800D424C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D4250: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800D4254: b           L_800D42B0
    // 0x800D4258: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_800D42B0;
    // 0x800D4258: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x800D425C: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_800D4260:
    // 0x800D4260: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x800D4264: beq         $t9, $zero, L_800D428C
    if (ctx->r25 == 0) {
        // 0x800D4268: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_800D428C;
    }
    // 0x800D4268: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800D426C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D4270: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x800D4274: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x800D4278: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800D427C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800D4280: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800D4284: b           L_800D42B0
    // 0x800D4288: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_800D42B0;
    // 0x800D4288: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800D428C:
    // 0x800D428C: beql        $t7, $zero, L_800D42B4
    if (ctx->r15 == 0) {
        // 0x800D4290: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800D42B4;
    }
    goto skip_14;
    // 0x800D4290: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x800D4294: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800D4298: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800D429C: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800D42A0: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800D42A4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D42A8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800D42AC: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_800D42B0:
    // 0x800D42B0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800D42B4:
    // 0x800D42B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D42B8: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x800D42BC: jal         0x800D7470
    // 0x800D42C0: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Ldtob(rdram, ctx);
        goto after_2;
    // 0x800D42C0: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_2:
    // 0x800D42C4: b           L_800D4464
    // 0x800D42C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D4464;
    // 0x800D42C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D42CC:
    // 0x800D42CC: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800D42D0: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800D42D4: bnel        $v0, $at, L_800D4308
    if (ctx->r2 != ctx->r1) {
        // 0x800D42D8: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_800D4308;
    }
    goto skip_15;
    // 0x800D42D8: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    skip_15:
    // 0x800D42DC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800D42E0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D42E4: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x800D42E8: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800D42EC: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800D42F0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D42F4: lw          $t9, -0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X4);
    // 0x800D42F8: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800D42FC: b           L_800D4460
    // 0x800D4300: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
        goto L_800D4460;
    // 0x800D4300: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x800D4304: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
L_800D4308:
    // 0x800D4308: bnel        $v0, $at, L_800D433C
    if (ctx->r2 != ctx->r1) {
        // 0x800D430C: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800D433C;
    }
    goto skip_16;
    // 0x800D430C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_16:
    // 0x800D4310: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D4314: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D4318: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x800D431C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800D4320: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x800D4324: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D4328: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x800D432C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x800D4330: b           L_800D4460
    // 0x800D4334: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_800D4460;
    // 0x800D4334: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800D4338: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800D433C:
    // 0x800D433C: bnel        $v0, $at, L_800D4378
    if (ctx->r2 != ctx->r1) {
        // 0x800D4340: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_800D4378;
    }
    goto skip_17;
    // 0x800D4340: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_17:
    // 0x800D4344: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800D4348: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D434C: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x800D4350: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800D4354: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800D4358: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D435C: lw          $t6, -0x4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4);
    // 0x800D4360: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800D4364: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800D4368: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800D436C: b           L_800D4460
    // 0x800D4370: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
        goto L_800D4460;
    // 0x800D4370: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800D4374: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_800D4378:
    // 0x800D4378: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D437C: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x800D4380: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800D4384: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800D4388: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D438C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x800D4390: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800D4394: b           L_800D4460
    // 0x800D4398: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_800D4460;
    // 0x800D4398: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_800D439C:
    // 0x800D439C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800D43A0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D43A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D43A8: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x800D43AC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800D43B0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800D43B4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800D43B8: lw          $t6, -0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X4);
    // 0x800D43BC: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D43C0: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x800D43C4: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800D43C8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800D43CC: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x800D43D0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D43D4: jal         0x800D6C60
    // 0x800D43D8: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Litob(rdram, ctx);
        goto after_3;
    // 0x800D43D8: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_3:
    // 0x800D43DC: b           L_800D4464
    // 0x800D43E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D4464;
    // 0x800D43E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D43E4:
    // 0x800D43E4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D43E8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D43EC: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800D43F0: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800D43F4: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x800D43F8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D43FC: lw          $a0, -0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, -0X4);
    // 0x800D4400: jal         0x800CE6FC
    // 0x800D4404: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_4;
    // 0x800D4404: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_4:
    // 0x800D4408: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x800D440C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800D4410: bltz        $v1, L_800D4460
    if (SIGNED(ctx->r3) < 0) {
        // 0x800D4414: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800D4460;
    }
    // 0x800D4414: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D4418: beql        $at, $zero, L_800D4464
    if (ctx->r1 == 0) {
        // 0x800D441C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D4464;
    }
    goto skip_18;
    // 0x800D441C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_18:
    // 0x800D4420: b           L_800D4460
    // 0x800D4424: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
        goto L_800D4460;
    // 0x800D4424: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x800D4428: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800D442C:
    // 0x800D442C: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x800D4430: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800D4434: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800D4438: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D443C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800D4440: b           L_800D4460
    // 0x800D4444: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_800D4460;
    // 0x800D4444: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800D4448:
    // 0x800D4448: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800D444C:
    // 0x800D444C: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x800D4450: sb          $a1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r5;
    // 0x800D4454: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D4458: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800D445C: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800D4460:
    // 0x800D4460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D4464:
    // 0x800D4464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D4468: jr          $ra
    // 0x800D446C: nop

    return;
    // 0x800D446C: nop

;}
RECOMP_FUNC void _Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4470: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x800D4474: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800D4478: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D447C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D4480: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800D4484: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D4488: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D448C: sw          $a3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r7;
    // 0x800D4490: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800D4494: lui         $s6, 0x800F
    ctx->r22 = S32(0X800F << 16);
    // 0x800D4498: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800D449C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800D44A0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800D44A4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800D44A8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D44AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D44B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D44B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D44B8: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x800D44BC: sw          $zero, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = 0;
    // 0x800D44C0: addiu       $s7, $s7, 0x4E50
    ctx->r23 = ADD32(ctx->r23, 0X4E50);
    // 0x800D44C4: addiu       $s6, $s6, -0x63BC
    ctx->r22 = ADD32(ctx->r22, -0X63BC);
    // 0x800D44C8: addiu       $s5, $s5, 0x4E74
    ctx->r21 = ADD32(ctx->r21, 0X4E74);
    // 0x800D44CC: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
L_800D44D0:
    // 0x800D44D0: lbu         $s0, 0x0($a3)
    ctx->r16 = MEM_BU(ctx->r7, 0X0);
    // 0x800D44D4: addiu       $s2, $a3, 0x1
    ctx->r18 = ADD32(ctx->r7, 0X1);
    // 0x800D44D8: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x800D44DC: blez        $s0, L_800D4504
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D44E0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D4504;
    }
    // 0x800D44E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800D44E4:
    // 0x800D44E4: bnel        $v1, $s0, L_800D44F8
    if (ctx->r3 != ctx->r16) {
        // 0x800D44E8: lbu         $s0, 0x0($s2)
        ctx->r16 = MEM_BU(ctx->r18, 0X0);
            goto L_800D44F8;
    }
    goto skip_0;
    // 0x800D44E8: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
    skip_0:
    // 0x800D44EC: b           L_800D4504
    // 0x800D44F0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_800D4504;
    // 0x800D44F0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800D44F4: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
L_800D44F8:
    // 0x800D44F8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D44FC: bgtz        $s0, L_800D44E4
    if (SIGNED(ctx->r16) > 0) {
        // 0x800D4500: nop
    
            goto L_800D44E4;
    }
    // 0x800D4500: nop

L_800D4504:
    // 0x800D4504: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
    // 0x800D4508: blez        $v0, L_800D453C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D450C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_800D453C;
    }
    // 0x800D450C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800D4510: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D4514: jalr        $s4
    // 0x800D4518: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x800D4518: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_0:
    // 0x800D451C: beq         $v0, $zero, L_800D4534
    if (ctx->r2 == 0) {
        // 0x800D4520: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4534;
    }
    // 0x800D4520: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4524: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4528: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800D452C: b           L_800D453C
    // 0x800D4530: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
        goto L_800D453C;
    // 0x800D4530: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
L_800D4534:
    // 0x800D4534: b           L_800D4A84
    // 0x800D4538: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4538: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D453C:
    // 0x800D453C: bne         $s0, $zero, L_800D454C
    if (ctx->r16 != 0) {
        // 0x800D4540: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800D454C;
    }
    // 0x800D4540: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4544: b           L_800D4A84
    // 0x800D4548: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4548: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D454C:
    // 0x800D454C: sw          $zero, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = 0;
    // 0x800D4550: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800D4554: jal         0x800CE724
    // 0x800D4558: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    strchr_recomp(rdram, ctx);
        goto after_1;
    // 0x800D4558: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x800D455C: beq         $v0, $zero, L_800D459C
    if (ctx->r2 == 0) {
        // 0x800D4560: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D459C;
    }
    // 0x800D4560: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D4564:
    // 0x800D4564: subu        $t9, $s0, $s6
    ctx->r25 = SUB32(ctx->r16, ctx->r22);
    // 0x800D4568: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800D456C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D4570: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800D4574: lw          $t7, -0x63B4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X63B4);
    // 0x800D4578: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x800D457C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4580: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800D4584: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800D4588: sw          $t9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r25;
    // 0x800D458C: jal         0x800CE724
    // 0x800D4590: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    strchr_recomp(rdram, ctx);
        goto after_2;
    // 0x800D4590: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_2:
    // 0x800D4594: bne         $v0, $zero, L_800D4564
    if (ctx->r2 != 0) {
        // 0x800D4598: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D4564;
    }
    // 0x800D4598: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D459C:
    // 0x800D459C: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x800D45A0: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x800D45A4: lw          $t8, 0xEC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XEC);
    // 0x800D45A8: bne         $v0, $t6, L_800D45F0
    if (ctx->r2 != ctx->r14) {
        // 0x800D45AC: lui         $a0, 0x800F
        ctx->r4 = S32(0X800F << 16);
            goto L_800D45F0;
    }
    // 0x800D45AC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D45B0: addiu       $t7, $t8, 0x3
    ctx->r15 = ADD32(ctx->r24, 0X3);
    // 0x800D45B4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D45B8: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x800D45BC: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800D45C0: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x800D45C4: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800D45C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D45CC: bgez        $t8, L_800D45E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D45D0: sw          $t8, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->r24;
            goto L_800D45E8;
    }
    // 0x800D45D0: sw          $t8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r24;
    // 0x800D45D4: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x800D45D8: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x800D45DC: sw          $t7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r15;
    // 0x800D45E0: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x800D45E4: sw          $t9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r25;
L_800D45E8:
    // 0x800D45E8: b           L_800D464C
    // 0x800D45EC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800D464C;
    // 0x800D45EC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800D45F0:
    // 0x800D45F0: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
    // 0x800D45F4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800D45F8: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800D45FC: bne         $at, $zero, L_800D464C
    if (ctx->r1 != 0) {
        // 0x800D4600: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800D464C;
    }
    // 0x800D4600: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800D4604: beql        $at, $zero, L_800D4650
    if (ctx->r1 == 0) {
        // 0x800D4608: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800D4650;
    }
    goto skip_1;
    // 0x800D4608: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_1:
    // 0x800D460C: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
L_800D4610:
    // 0x800D4610: slti        $at, $t8, 0x3E7
    ctx->r1 = SIGNED(ctx->r24) < 0X3E7 ? 1 : 0;
    // 0x800D4614: beql        $at, $zero, L_800D4634
    if (ctx->r1 == 0) {
        // 0x800D4618: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_800D4634;
    }
    goto skip_2;
    // 0x800D4618: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_2:
    // 0x800D461C: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D4620: mflo        $t7
    ctx->r15 = lo;
    // 0x800D4624: addu        $t6, $a1, $t7
    ctx->r14 = ADD32(ctx->r5, ctx->r15);
    // 0x800D4628: addiu       $t9, $t6, -0x30
    ctx->r25 = ADD32(ctx->r14, -0X30);
    // 0x800D462C: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x800D4630: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_800D4634:
    // 0x800D4634: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4638: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800D463C: bne         $at, $zero, L_800D464C
    if (ctx->r1 != 0) {
        // 0x800D4640: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800D464C;
    }
    // 0x800D4640: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800D4644: bnel        $at, $zero, L_800D4610
    if (ctx->r1 != 0) {
        // 0x800D4648: lw          $t8, 0xD0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XD0);
            goto L_800D4610;
    }
    goto skip_3;
    // 0x800D4648: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    skip_3:
L_800D464C:
    // 0x800D464C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_800D4650:
    // 0x800D4650: beq         $a1, $at, L_800D4664
    if (ctx->r5 == ctx->r1) {
        // 0x800D4654: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_800D4664;
    }
    // 0x800D4654: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800D4658: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
    // 0x800D465C: b           L_800D46F8
    // 0x800D4660: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800D46F8;
    // 0x800D4660: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800D4664:
    // 0x800D4664: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x800D4668: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x800D466C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4670: bne         $v0, $t7, L_800D469C
    if (ctx->r2 != ctx->r15) {
        // 0x800D4674: addiu       $t9, $t6, 0x3
        ctx->r25 = ADD32(ctx->r14, 0X3);
            goto L_800D469C;
    }
    // 0x800D4674: addiu       $t9, $t6, 0x3
    ctx->r25 = ADD32(ctx->r14, 0X3);
    // 0x800D4678: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D467C: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800D4680: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x800D4684: sw          $t7, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r15;
    // 0x800D4688: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800D468C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4690: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800D4694: b           L_800D46F8
    // 0x800D4698: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800D46F8;
    // 0x800D4698: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800D469C:
    // 0x800D469C: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x800D46A0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800D46A4: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800D46A8: bne         $at, $zero, L_800D46F8
    if (ctx->r1 != 0) {
        // 0x800D46AC: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800D46F8;
    }
    // 0x800D46AC: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800D46B0: beq         $at, $zero, L_800D46F8
    if (ctx->r1 == 0) {
        // 0x800D46B4: nop
    
            goto L_800D46F8;
    }
    // 0x800D46B4: nop

    // 0x800D46B8: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
L_800D46BC:
    // 0x800D46BC: slti        $at, $t9, 0x3E7
    ctx->r1 = SIGNED(ctx->r25) < 0X3E7 ? 1 : 0;
    // 0x800D46C0: beql        $at, $zero, L_800D46E0
    if (ctx->r1 == 0) {
        // 0x800D46C4: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_800D46E0;
    }
    goto skip_4;
    // 0x800D46C4: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_4:
    // 0x800D46C8: multu       $t9, $fp
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D46CC: mflo        $t7
    ctx->r15 = lo;
    // 0x800D46D0: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800D46D4: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x800D46D8: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800D46DC: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_800D46E0:
    // 0x800D46E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D46E4: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800D46E8: bne         $at, $zero, L_800D46F8
    if (ctx->r1 != 0) {
        // 0x800D46EC: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800D46F8;
    }
    // 0x800D46EC: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800D46F0: bnel        $at, $zero, L_800D46BC
    if (ctx->r1 != 0) {
        // 0x800D46F4: lw          $t9, 0xCC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XCC);
            goto L_800D46BC;
    }
    goto skip_5;
    // 0x800D46F4: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    skip_5:
L_800D46F8:
    // 0x800D46F8: jal         0x800CE724
    // 0x800D46FC: addiu       $a0, $a0, -0x63C0
    ctx->r4 = ADD32(ctx->r4, -0X63C0);
    strchr_recomp(rdram, ctx);
        goto after_3;
    // 0x800D46FC: addiu       $a0, $a0, -0x63C0
    ctx->r4 = ADD32(ctx->r4, -0X63C0);
    after_3:
    // 0x800D4700: beq         $v0, $zero, L_800D4718
    if (ctx->r2 == 0) {
        // 0x800D4704: addiu       $s0, $sp, 0xA8
        ctx->r16 = ADD32(ctx->r29, 0XA8);
            goto L_800D4718;
    }
    // 0x800D4704: addiu       $s0, $sp, 0xA8
    ctx->r16 = ADD32(ctx->r29, 0XA8);
    // 0x800D4708: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x800D470C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4710: b           L_800D471C
    // 0x800D4714: sb          $t9, 0xDC($sp)
    MEM_B(0XDC, ctx->r29) = ctx->r25;
        goto L_800D471C;
    // 0x800D4714: sb          $t9, 0xDC($sp)
    MEM_B(0XDC, ctx->r29) = ctx->r25;
L_800D4718:
    // 0x800D4718: sb          $zero, 0xDC($sp)
    MEM_B(0XDC, ctx->r29) = 0;
L_800D471C:
    // 0x800D471C: lbu         $t7, 0xDC($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XDC);
    // 0x800D4720: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x800D4724: addiu       $a2, $sp, 0xEC
    ctx->r6 = ADD32(ctx->r29, 0XEC);
    // 0x800D4728: bne         $v0, $t7, L_800D4748
    if (ctx->r2 != ctx->r15) {
        // 0x800D472C: addiu       $a3, $sp, 0x7C
        ctx->r7 = ADD32(ctx->r29, 0X7C);
            goto L_800D4748;
    }
    // 0x800D472C: addiu       $a3, $sp, 0x7C
    ctx->r7 = ADD32(ctx->r29, 0X7C);
    // 0x800D4730: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800D4734: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x800D4738: bne         $v0, $t8, L_800D4748
    if (ctx->r2 != ctx->r24) {
        // 0x800D473C: nop
    
            goto L_800D4748;
    }
    // 0x800D473C: nop

    // 0x800D4740: sb          $t6, 0xDC($sp)
    MEM_B(0XDC, ctx->r29) = ctx->r14;
    // 0x800D4744: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D4748:
    // 0x800D4748: jal         0x800D3E00
    // 0x800D474C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    static_0_800D3E00(rdram, ctx);
        goto after_4;
    // 0x800D474C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_4:
    // 0x800D4750: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800D4754: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800D4758: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800D475C: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800D4760: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800D4764: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800D4768: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800D476C: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800D4770: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800D4774: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800D4778: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800D477C: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800D4780: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x800D4784: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800D4788: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x800D478C: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800D4790: bne         $t8, $zero, L_800D47FC
    if (ctx->r24 != 0) {
        // 0x800D4794: slt         $t6, $zero, $t9
        ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_800D47FC;
    }
    // 0x800D4794: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D4798: beql        $t6, $zero, L_800D4800
    if (ctx->r14 == 0) {
        // 0x800D479C: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800D4800;
    }
    goto skip_6;
    // 0x800D479C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_6:
    // 0x800D47A0: beq         $t6, $zero, L_800D47FC
    if (ctx->r14 == 0) {
        // 0x800D47A4: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800D47FC;
    }
    // 0x800D47A4: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800D47A8: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D47AC:
    // 0x800D47AC: bne         $at, $zero, L_800D47BC
    if (ctx->r1 != 0) {
        // 0x800D47B0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D47BC;
    }
    // 0x800D47B0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D47B4: b           L_800D47BC
    // 0x800D47B8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D47BC;
    // 0x800D47B8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D47BC:
    // 0x800D47BC: blez        $s0, L_800D47F0
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D47C0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D47F0;
    }
    // 0x800D47C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D47C4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800D47C8: jalr        $s4
    // 0x800D47CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x800D47CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x800D47D0: beq         $v0, $zero, L_800D47E8
    if (ctx->r2 == 0) {
        // 0x800D47D4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D47E8;
    }
    // 0x800D47D4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D47D8: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x800D47DC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800D47E0: b           L_800D47F0
    // 0x800D47E4: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D47F0;
    // 0x800D47E4: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D47E8:
    // 0x800D47E8: b           L_800D4A84
    // 0x800D47EC: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D47EC: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D47F0:
    // 0x800D47F0: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D47F4: bgtzl       $s1, L_800D47AC
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D47F8: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D47AC;
    }
    goto skip_7;
    // 0x800D47F8: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_7:
L_800D47FC:
    // 0x800D47FC: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_800D4800:
    // 0x800D4800: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D4804: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x800D4808: blezl       $t9, L_800D4840
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D480C: lw          $t9, 0xB8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB8);
            goto L_800D4840;
    }
    goto skip_8;
    // 0x800D480C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    skip_8:
    // 0x800D4810: jalr        $s4
    // 0x800D4814: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x800D4814: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_6:
    // 0x800D4818: beq         $v0, $zero, L_800D4834
    if (ctx->r2 == 0) {
        // 0x800D481C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4834;
    }
    // 0x800D481C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4820: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4824: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800D4828: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800D482C: b           L_800D483C
    // 0x800D4830: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D483C;
    // 0x800D4830: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D4834:
    // 0x800D4834: b           L_800D4A84
    // 0x800D4838: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4838: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D483C:
    // 0x800D483C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
L_800D4840:
    // 0x800D4840: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D4844: beql        $t6, $zero, L_800D48AC
    if (ctx->r14 == 0) {
        // 0x800D4848: lw          $t9, 0xBC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XBC);
            goto L_800D48AC;
    }
    goto skip_9;
    // 0x800D4848: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    skip_9:
    // 0x800D484C: beq         $t6, $zero, L_800D48A8
    if (ctx->r14 == 0) {
        // 0x800D4850: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800D48A8;
    }
    // 0x800D4850: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800D4854: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D4858:
    // 0x800D4858: bne         $at, $zero, L_800D4868
    if (ctx->r1 != 0) {
        // 0x800D485C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D4868;
    }
    // 0x800D485C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D4860: b           L_800D4868
    // 0x800D4864: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D4868;
    // 0x800D4864: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D4868:
    // 0x800D4868: blez        $s0, L_800D489C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D486C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D489C;
    }
    // 0x800D486C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D4870: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D4874: jalr        $s4
    // 0x800D4878: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x800D4878: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x800D487C: beq         $v0, $zero, L_800D4894
    if (ctx->r2 == 0) {
        // 0x800D4880: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4894;
    }
    // 0x800D4880: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4884: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4888: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800D488C: b           L_800D489C
    // 0x800D4890: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D489C;
    // 0x800D4890: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D4894:
    // 0x800D4894: b           L_800D4A84
    // 0x800D4898: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4898: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D489C:
    // 0x800D489C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D48A0: bgtzl       $s1, L_800D4858
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D48A4: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D4858;
    }
    goto skip_10;
    // 0x800D48A4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_10:
L_800D48A8:
    // 0x800D48A8: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
L_800D48AC:
    // 0x800D48AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D48B0: lw          $a1, 0xB0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB0);
    // 0x800D48B4: blezl       $t9, L_800D48EC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D48B8: lw          $t9, 0xC0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC0);
            goto L_800D48EC;
    }
    goto skip_11;
    // 0x800D48B8: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    skip_11:
    // 0x800D48BC: jalr        $s4
    // 0x800D48C0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x800D48C0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_8:
    // 0x800D48C4: beq         $v0, $zero, L_800D48E0
    if (ctx->r2 == 0) {
        // 0x800D48C8: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D48E0;
    }
    // 0x800D48C8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D48CC: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800D48D0: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800D48D4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800D48D8: b           L_800D48E8
    // 0x800D48DC: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D48E8;
    // 0x800D48DC: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D48E0:
    // 0x800D48E0: b           L_800D4A84
    // 0x800D48E4: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D48E4: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D48E8:
    // 0x800D48E8: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
L_800D48EC:
    // 0x800D48EC: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D48F0: beql        $t6, $zero, L_800D4958
    if (ctx->r14 == 0) {
        // 0x800D48F4: lw          $t9, 0xC4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC4);
            goto L_800D4958;
    }
    goto skip_12;
    // 0x800D48F4: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    skip_12:
    // 0x800D48F8: beq         $t6, $zero, L_800D4954
    if (ctx->r14 == 0) {
        // 0x800D48FC: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800D4954;
    }
    // 0x800D48FC: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800D4900: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D4904:
    // 0x800D4904: bne         $at, $zero, L_800D4914
    if (ctx->r1 != 0) {
        // 0x800D4908: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D4914;
    }
    // 0x800D4908: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D490C: b           L_800D4914
    // 0x800D4910: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D4914;
    // 0x800D4910: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D4914:
    // 0x800D4914: blez        $s0, L_800D4948
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D4918: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D4948;
    }
    // 0x800D4918: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D491C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D4920: jalr        $s4
    // 0x800D4924: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x800D4924: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x800D4928: beq         $v0, $zero, L_800D4940
    if (ctx->r2 == 0) {
        // 0x800D492C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4940;
    }
    // 0x800D492C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4930: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4934: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800D4938: b           L_800D4948
    // 0x800D493C: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D4948;
    // 0x800D493C: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D4940:
    // 0x800D4940: b           L_800D4A84
    // 0x800D4944: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4944: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D4948:
    // 0x800D4948: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D494C: bgtzl       $s1, L_800D4904
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D4950: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D4904;
    }
    goto skip_13;
    // 0x800D4950: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_13:
L_800D4954:
    // 0x800D4954: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
L_800D4958:
    // 0x800D4958: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D495C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800D4960: blez        $t9, L_800D4998
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D4964: lw          $t7, 0xBC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XBC);
            goto L_800D4998;
    }
    // 0x800D4964: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800D4968: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800D496C: jalr        $s4
    // 0x800D4970: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x800D4970: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_10:
    // 0x800D4974: beq         $v0, $zero, L_800D4990
    if (ctx->r2 == 0) {
        // 0x800D4978: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4990;
    }
    // 0x800D4978: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D497C: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4980: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800D4984: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800D4988: b           L_800D4998
    // 0x800D498C: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
        goto L_800D4998;
    // 0x800D498C: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
L_800D4990:
    // 0x800D4990: b           L_800D4A84
    // 0x800D4994: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4994: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D4998:
    // 0x800D4998: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800D499C: slt         $t8, $zero, $t9
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D49A0: beql        $t8, $zero, L_800D4A08
    if (ctx->r24 == 0) {
        // 0x800D49A4: lw          $t9, 0xD8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD8);
            goto L_800D4A08;
    }
    goto skip_14;
    // 0x800D49A4: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    skip_14:
    // 0x800D49A8: beq         $t8, $zero, L_800D4A04
    if (ctx->r24 == 0) {
        // 0x800D49AC: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800D4A04;
    }
    // 0x800D49AC: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800D49B0: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D49B4:
    // 0x800D49B4: bne         $at, $zero, L_800D49C4
    if (ctx->r1 != 0) {
        // 0x800D49B8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D49C4;
    }
    // 0x800D49B8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D49BC: b           L_800D49C4
    // 0x800D49C0: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D49C4;
    // 0x800D49C0: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D49C4:
    // 0x800D49C4: blez        $s0, L_800D49F8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D49C8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D49F8;
    }
    // 0x800D49C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D49CC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D49D0: jalr        $s4
    // 0x800D49D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x800D49D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x800D49D8: beq         $v0, $zero, L_800D49F0
    if (ctx->r2 == 0) {
        // 0x800D49DC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D49F0;
    }
    // 0x800D49DC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D49E0: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800D49E4: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800D49E8: b           L_800D49F8
    // 0x800D49EC: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
        goto L_800D49F8;
    // 0x800D49EC: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
L_800D49F0:
    // 0x800D49F0: b           L_800D4A84
    // 0x800D49F4: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D49F4: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D49F8:
    // 0x800D49F8: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D49FC: bgtzl       $s1, L_800D49B4
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D4A00: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D49B4;
    }
    goto skip_15;
    // 0x800D4A00: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_15:
L_800D4A04:
    // 0x800D4A04: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
L_800D4A08:
    // 0x800D4A08: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x800D4A0C: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x800D4A10: beq         $t8, $zero, L_800D4A7C
    if (ctx->r24 == 0) {
        // 0x800D4A14: slt         $t7, $zero, $t6
        ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_800D4A7C;
    }
    // 0x800D4A14: slt         $t7, $zero, $t6
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D4A18: beq         $t7, $zero, L_800D4A7C
    if (ctx->r15 == 0) {
        // 0x800D4A1C: nop
    
            goto L_800D4A7C;
    }
    // 0x800D4A1C: nop

    // 0x800D4A20: beq         $t7, $zero, L_800D4A7C
    if (ctx->r15 == 0) {
        // 0x800D4A24: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_800D4A7C;
    }
    // 0x800D4A24: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800D4A28: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D4A2C:
    // 0x800D4A2C: bne         $at, $zero, L_800D4A3C
    if (ctx->r1 != 0) {
        // 0x800D4A30: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D4A3C;
    }
    // 0x800D4A30: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D4A34: b           L_800D4A3C
    // 0x800D4A38: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D4A3C;
    // 0x800D4A38: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D4A3C:
    // 0x800D4A3C: blez        $s0, L_800D4A70
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D4A40: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D4A70;
    }
    // 0x800D4A40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D4A44: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800D4A48: jalr        $s4
    // 0x800D4A4C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_12;
    // 0x800D4A4C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x800D4A50: beq         $v0, $zero, L_800D4A68
    if (ctx->r2 == 0) {
        // 0x800D4A54: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4A68;
    }
    // 0x800D4A54: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4A58: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4A5C: addu        $t8, $t9, $s0
    ctx->r24 = ADD32(ctx->r25, ctx->r16);
    // 0x800D4A60: b           L_800D4A70
    // 0x800D4A64: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D4A70;
    // 0x800D4A64: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D4A68:
    // 0x800D4A68: b           L_800D4A84
    // 0x800D4A6C: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4A6C: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D4A70:
    // 0x800D4A70: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D4A74: bgtzl       $s1, L_800D4A2C
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D4A78: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D4A2C;
    }
    goto skip_16;
    // 0x800D4A78: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_16:
L_800D4A7C:
    // 0x800D4A7C: b           L_800D44D0
    // 0x800D4A80: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
        goto L_800D44D0;
    // 0x800D4A80: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
L_800D4A84:
    // 0x800D4A84: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800D4A88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D4A8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4A90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D4A94: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D4A98: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D4A9C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4AA0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D4AA4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800D4AA8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800D4AAC: jr          $ra
    // 0x800D4AB0: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x800D4AB0: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x800D4AB4: nop

    // 0x800D4AB8: nop

    // 0x800D4ABC: nop

;}
RECOMP_FUNC void __osSetHWIntrRoutine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4D50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D4D54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D4D58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D4D5C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D4D60: jal         0x800D2AC0
    // 0x800D4D64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x800D4D64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800D4D68: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D4D6C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4D70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800D4D74: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800D4D78: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D4D7C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800D4D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4D84: jal         0x800D2AE0
    // 0x800D4D88: sw          $t6, 0x4E30($at)
    MEM_W(0X4E30, ctx->r1) = ctx->r14;
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x800D4D88: sw          $t6, 0x4E30($at)
    MEM_W(0X4E30, ctx->r1) = ctx->r14;
    after_1:
    // 0x800D4D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4D90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D4D94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D4D98: jr          $ra
    // 0x800D4D9C: nop

    return;
    // 0x800D4D9C: nop

;}
RECOMP_FUNC void guMtxF2L(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4DA0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800D4DA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D4DA8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D4DAC: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x800D4DB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D4DB4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D4DB8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800D4DBC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800D4DC0: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_800D4DC4:
    // 0x800D4DC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D4DC8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800D4DCC: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D4DD0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D4DD4: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D4DD8: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800D4DDC: beq         $a0, $t3, L_800D4E44
    if (ctx->r4 == ctx->r11) {
        // 0x800D4DE0: nop
    
            goto L_800D4E44;
    }
    // 0x800D4DE0: nop

L_800D4DE4:
    // 0x800D4DE4: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D4DE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D4DEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D4DF0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D4DF4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800D4DF8: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D4DFC: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800D4E00: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x800D4E04: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800D4E08: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800D4E0C: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x800D4E10: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x800D4E14: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800D4E18: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800D4E1C: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x800D4E20: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x800D4E24: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x800D4E28: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800D4E2C: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x800D4E30: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D4E34: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D4E38: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800D4E3C: bne         $a0, $t3, L_800D4DE4
    if (ctx->r4 != ctx->r11) {
        // 0x800D4E40: nop
    
            goto L_800D4DE4;
    }
    // 0x800D4E40: nop

L_800D4E44:
    // 0x800D4E44: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D4E48: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800D4E4C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D4E50: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D4E54: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D4E58: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800D4E5C: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x800D4E60: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800D4E64: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800D4E68: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x800D4E6C: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x800D4E70: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800D4E74: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800D4E78: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x800D4E7C: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x800D4E80: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x800D4E84: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800D4E88: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x800D4E8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D4E90: bne         $a2, $t4, L_800D4DC4
    if (ctx->r6 != ctx->r12) {
        // 0x800D4E94: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800D4DC4;
    }
    // 0x800D4E94: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800D4E98: jr          $ra
    // 0x800D4E9C: nop

    return;
    // 0x800D4E9C: nop

;}
RECOMP_FUNC void guMtxIdentF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4EA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D4EA4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D4EA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D4EAC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D4EB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D4EB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D4EB8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800D4EBC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800D4EC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800D4EC4:
    // 0x800D4EC4: bnel        $v0, $zero, L_800D4ED8
    if (ctx->r2 != 0) {
        // 0x800D4EC8: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_800D4ED8;
    }
    goto skip_0;
    // 0x800D4EC8: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x800D4ECC: b           L_800D4ED8
    // 0x800D4ED0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_800D4ED8;
    // 0x800D4ED0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800D4ED4: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_800D4ED8:
    // 0x800D4ED8: bnel        $v0, $a0, L_800D4EEC
    if (ctx->r2 != ctx->r4) {
        // 0x800D4EDC: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_800D4EEC;
    }
    goto skip_1;
    // 0x800D4EDC: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x800D4EE0: b           L_800D4EEC
    // 0x800D4EE4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_800D4EEC;
    // 0x800D4EE4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800D4EE8: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_800D4EEC:
    // 0x800D4EEC: bnel        $v0, $a1, L_800D4F00
    if (ctx->r2 != ctx->r5) {
        // 0x800D4EF0: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_800D4F00;
    }
    goto skip_2;
    // 0x800D4EF0: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x800D4EF4: b           L_800D4F00
    // 0x800D4EF8: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_800D4F00;
    // 0x800D4EF8: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x800D4EFC: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_800D4F00:
    // 0x800D4F00: bnel        $v0, $a2, L_800D4F14
    if (ctx->r2 != ctx->r6) {
        // 0x800D4F04: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_800D4F14;
    }
    goto skip_3;
    // 0x800D4F04: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x800D4F08: b           L_800D4F14
    // 0x800D4F0C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_800D4F14;
    // 0x800D4F0C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x800D4F10: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_800D4F14:
    // 0x800D4F14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D4F18: bne         $v0, $a3, L_800D4EC4
    if (ctx->r2 != ctx->r7) {
        // 0x800D4F1C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800D4EC4;
    }
    // 0x800D4F1C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800D4F20: jr          $ra
    // 0x800D4F24: nop

    return;
    // 0x800D4F24: nop

;}
RECOMP_FUNC void guMtxIdent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4F28: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800D4F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4F30: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800D4F34: jal         0x800D4EA0
    // 0x800D4F38: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800D4F38: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800D4F3C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800D4F40: jal         0x800D4DA0
    // 0x800D4F44: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800D4F44: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x800D4F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D4F4C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800D4F50: jr          $ra
    // 0x800D4F54: nop

    return;
    // 0x800D4F54: nop

;}
RECOMP_FUNC void guMtxL2F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4F58: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800D4F5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D4F60: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800D4F64: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D4F68: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x800D4F6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D4F70: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D4F74: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800D4F78: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800D4F7C: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_800D4F80:
    // 0x800D4F80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D4F84: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_800D4F88:
    // 0x800D4F88: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800D4F8C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800D4F90: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D4F94: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x800D4F98: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800D4F9C: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x800D4FA0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800D4FA4: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800D4FA8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800D4FAC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800D4FB0: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x800D4FB4: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800D4FB8: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x800D4FBC: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800D4FC0: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x800D4FC4: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x800D4FC8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D4FCC: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800D4FD0: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x800D4FD4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D4FD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D4FDC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D4FE0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4FE4: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D4FE8: div.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800D4FEC: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x800D4FF0: bne         $a0, $t3, L_800D4F88
    if (ctx->r4 != ctx->r11) {
        // 0x800D4FF4: swc1        $f16, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
            goto L_800D4F88;
    }
    // 0x800D4FF4: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x800D4FF8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D4FFC: bne         $a2, $t4, L_800D4F80
    if (ctx->r6 != ctx->r12) {
        // 0x800D5000: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_800D4F80;
    }
    // 0x800D5000: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800D5004: jr          $ra
    // 0x800D5008: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800D5008: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800D500C: nop

;}
RECOMP_FUNC void cosf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5010: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800D5014: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800D5018: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D501C: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D5020: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800D5024: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800D5028: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x800D502C: beql        $at, $zero, L_800D5154
    if (ctx->r1 == 0) {
        // 0x800D5030: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_800D5154;
    }
    goto skip_0;
    // 0x800D5030: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x800D5034: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D5038: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D503C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800D5040: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800D5044: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D5048: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D504C: bc1fl       L_800D5060
    if (!c1cs) {
        // 0x800D5050: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_800D5060;
    }
    goto skip_1;
    // 0x800D5050: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x800D5054: b           L_800D5060
    // 0x800D5058: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_800D5060;
    // 0x800D5058: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x800D505C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800D5060:
    // 0x800D5060: ldc1        $f8, -0x6298($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6298);
    // 0x800D5064: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x800D5068: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800D506C: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x800D5070: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800D5074: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D5078: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x800D507C: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x800D5080: nop

    // 0x800D5084: bc1fl       L_800D50A4
    if (!c1cs) {
        // 0x800D5088: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_800D50A4;
    }
    goto skip_2;
    // 0x800D5088: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x800D508C: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x800D5090: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800D5094: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800D5098: b           L_800D50B4
    // 0x800D509C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_800D50B4;
    // 0x800D509C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800D50A0: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_800D50A4:
    // 0x800D50A4: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800D50A8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800D50AC: nop

    // 0x800D50B0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_800D50B4:
    // 0x800D50B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D50B8: ldc1        $f10, -0x6290($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6290);
    // 0x800D50BC: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800D50C0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D50C4: ldc1        $f6, -0x6288($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6288);
    // 0x800D50C8: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800D50CC: addiu       $v1, $v1, -0x62C0
    ctx->r3 = ADD32(ctx->r3, -0X62C0);
    // 0x800D50D0: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x800D50D4: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800D50D8: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x800D50DC: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x800D50E0: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800D50E4: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x800D50E8: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x800D50EC: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x800D50F0: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D50F4: nop

    // 0x800D50F8: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x800D50FC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800D5100: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800D5104: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800D5108: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x800D510C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800D5110: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x800D5114: bne         $t0, $zero, L_800D5134
    if (ctx->r8 != 0) {
        // 0x800D5118: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_800D5134;
    }
    // 0x800D5118: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x800D511C: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x800D5120: nop

    // 0x800D5124: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800D5128: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800D512C: jr          $ra
    // 0x800D5130: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800D5130: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800D5134:
    // 0x800D5134: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x800D5138: nop

    // 0x800D513C: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800D5140: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x800D5144: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x800D5148: jr          $ra
    // 0x800D514C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800D514C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800D5150: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_800D5154:
    // 0x800D5154: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5158: bc1t        L_800D516C
    if (c1cs) {
        // 0x800D515C: nop
    
            goto L_800D516C;
    }
    // 0x800D515C: nop

    // 0x800D5160: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5164: jr          $ra
    // 0x800D5168: lwc1        $f0, -0x61C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X61C0);
    return;
    // 0x800D5168: lwc1        $f0, -0x61C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X61C0);
L_800D516C:
    // 0x800D516C: lwc1        $f0, -0x6280($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6280);
    // 0x800D5170: jr          $ra
    // 0x800D5174: nop

    return;
    // 0x800D5174: nop

    // 0x800D5178: nop

    // 0x800D517C: nop

;}
RECOMP_FUNC void sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5180: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800D5184: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800D5188: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D518C: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800D5190: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x800D5194: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x800D5198: beq         $at, $zero, L_800D5200
    if (ctx->r1 == 0) {
        // 0x800D519C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800D5200;
    }
    // 0x800D519C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800D51A0: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x800D51A4: bne         $at, $zero, L_800D51F8
    if (ctx->r1 != 0) {
        // 0x800D51A8: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_800D51F8;
    }
    // 0x800D51A8: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800D51AC: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D51B0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800D51B4: addiu       $v1, $v1, -0x6270
    ctx->r3 = ADD32(ctx->r3, -0X6270);
    // 0x800D51B8: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x800D51BC: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x800D51C0: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800D51C4: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800D51C8: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800D51CC: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800D51D0: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x800D51D4: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800D51D8: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800D51DC: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x800D51E0: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800D51E4: nop

    // 0x800D51E8: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x800D51EC: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x800D51F0: jr          $ra
    // 0x800D51F4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800D51F4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800D51F8:
    // 0x800D51F8: jr          $ra
    // 0x800D51FC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x800D51FC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_800D5200:
    // 0x800D5200: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x800D5204: beq         $at, $zero, L_800D5318
    if (ctx->r1 == 0) {
        // 0x800D5208: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_800D5318;
    }
    // 0x800D5208: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D520C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D5210: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5214: ldc1        $f10, -0x6248($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6248);
    // 0x800D5218: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x800D521C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800D5220: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x800D5224: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D5228: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D522C: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x800D5230: nop

    // 0x800D5234: bc1fl       L_800D5264
    if (!c1cs) {
        // 0x800D5238: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_800D5264;
    }
    goto skip_0;
    // 0x800D5238: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800D523C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D5240: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D5244: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D5248: nop

    // 0x800D524C: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x800D5250: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x800D5254: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800D5258: b           L_800D5280
    // 0x800D525C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_800D5280;
    // 0x800D525C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800D5260: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_800D5264:
    // 0x800D5264: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D5268: nop

    // 0x800D526C: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x800D5270: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800D5274: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800D5278: nop

    // 0x800D527C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_800D5280:
    // 0x800D5280: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5284: ldc1        $f18, -0x6240($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6240);
    // 0x800D5288: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x800D528C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5290: ldc1        $f6, -0x6238($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6238);
    // 0x800D5294: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800D5298: addiu       $v1, $v1, -0x6270
    ctx->r3 = ADD32(ctx->r3, -0X6270);
    // 0x800D529C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800D52A0: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x800D52A4: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x800D52A8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800D52AC: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800D52B0: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x800D52B4: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x800D52B8: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x800D52BC: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D52C0: nop

    // 0x800D52C4: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800D52C8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800D52CC: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x800D52D0: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x800D52D4: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x800D52D8: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800D52DC: bne         $t9, $zero, L_800D52FC
    if (ctx->r25 != 0) {
        // 0x800D52E0: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_800D52FC;
    }
    // 0x800D52E0: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x800D52E4: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800D52E8: nop

    // 0x800D52EC: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x800D52F0: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800D52F4: jr          $ra
    // 0x800D52F8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800D52F8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800D52FC:
    // 0x800D52FC: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800D5300: nop

    // 0x800D5304: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800D5308: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x800D530C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x800D5310: jr          $ra
    // 0x800D5314: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800D5314: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800D5318:
    // 0x800D5318: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x800D531C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5320: bc1t        L_800D5334
    if (c1cs) {
        // 0x800D5324: nop
    
            goto L_800D5334;
    }
    // 0x800D5324: nop

    // 0x800D5328: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D532C: jr          $ra
    // 0x800D5330: lwc1        $f0, -0x61C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X61C0);
    return;
    // 0x800D5330: lwc1        $f0, -0x61C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X61C0);
L_800D5334:
    // 0x800D5334: lwc1        $f0, -0x6230($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6230);
    // 0x800D5338: jr          $ra
    // 0x800D533C: nop

    return;
    // 0x800D533C: nop

;}
RECOMP_FUNC void __osSumcalc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5850: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800D5854: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x800D5858: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800D585C: blez        $a1, L_800D58A0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D5860: sw          $zero, 0xC($sp)
        MEM_W(0XC, ctx->r29) = 0;
            goto L_800D58A0;
    }
    // 0x800D5860: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_800D5864:
    // 0x800D5864: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800D5868: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800D586C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800D5870: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800D5874: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x800D5878: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800D587C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800D5880: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800D5884: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800D5888: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D588C: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800D5890: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800D5894: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800D5898: bne         $at, $zero, L_800D5864
    if (ctx->r1 != 0) {
        // 0x800D589C: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_800D5864;
    }
    // 0x800D589C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_800D58A0:
    // 0x800D58A0: lhu         $v0, 0xA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XA);
    // 0x800D58A4: jr          $ra
    // 0x800D58A8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800D58A8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void __osIdCheckSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D58AC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800D58B0: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x800D58B4: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x800D58B8: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x800D58BC: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800D58C0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800D58C4:
    // 0x800D58C4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800D58C8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800D58CC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800D58D0: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x800D58D4: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x800D58D8: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x800D58DC: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x800D58E0: lhu         $t3, 0x6($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6);
    // 0x800D58E4: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x800D58E8: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x800D58EC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800D58F0: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x800D58F4: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800D58F8: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800D58FC: sltiu       $at, $t7, 0x1C
    ctx->r1 = ctx->r15 < 0X1C ? 1 : 0;
    // 0x800D5900: bne         $at, $zero, L_800D58C4
    if (ctx->r1 != 0) {
        // 0x800D5904: sw          $t7, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r15;
            goto L_800D58C4;
    }
    // 0x800D5904: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800D5908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D590C: jr          $ra
    // 0x800D5910: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800D5910: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void _Litob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6C60: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800D6C64: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800D6C68: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800D6C6C: addiu       $v1, $zero, 0x58
    ctx->r3 = ADD32(0, 0X58);
    // 0x800D6C70: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D6C74: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800D6C78: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800D6C7C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800D6C80: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800D6C84: bne         $v1, $v0, L_800D6C98
    if (ctx->r3 != ctx->r2) {
        // 0x800D6C88: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_800D6C98;
    }
    // 0x800D6C88: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x800D6C8C: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800D6C90: b           L_800D6CA0
    // 0x800D6C94: addiu       $s3, $s3, 0x4EC4
    ctx->r19 = ADD32(ctx->r19, 0X4EC4);
        goto L_800D6CA0;
    // 0x800D6C94: addiu       $s3, $s3, 0x4EC4
    ctx->r19 = ADD32(ctx->r19, 0X4EC4);
L_800D6C98:
    // 0x800D6C98: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800D6C9C: addiu       $s3, $s3, 0x4EB0
    ctx->r19 = ADD32(ctx->r19, 0X4EB0);
L_800D6CA0:
    // 0x800D6CA0: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x800D6CA4: bne         $v0, $at, L_800D6CB4
    if (ctx->r2 != ctx->r1) {
        // 0x800D6CA8: addiu       $s0, $zero, 0x18
        ctx->r16 = ADD32(0, 0X18);
            goto L_800D6CB4;
    }
    // 0x800D6CA8: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x800D6CAC: b           L_800D6CD4
    // 0x800D6CB0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_800D6CD4;
    // 0x800D6CB0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_800D6CB4:
    // 0x800D6CB4: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800D6CB8: beq         $v0, $at, L_800D6CD0
    if (ctx->r2 == ctx->r1) {
        // 0x800D6CBC: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_800D6CD0;
    }
    // 0x800D6CBC: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800D6CC0: beq         $v1, $v0, L_800D6CD0
    if (ctx->r3 == ctx->r2) {
        // 0x800D6CC4: nop
    
            goto L_800D6CD0;
    }
    // 0x800D6CC4: nop

    // 0x800D6CC8: b           L_800D6CD0
    // 0x800D6CCC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
        goto L_800D6CD0;
    // 0x800D6CCC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_800D6CD0:
    // 0x800D6CD0: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_800D6CD4:
    // 0x800D6CD4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800D6CD8: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800D6CDC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800D6CE0: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800D6CE4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800D6CE8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800D6CEC: beq         $v0, $at, L_800D6D00
    if (ctx->r2 == ctx->r1) {
        // 0x800D6CF0: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_800D6D00;
    }
    // 0x800D6CF0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800D6CF4: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x800D6CF8: bnel        $v0, $at, L_800D6D3C
    if (ctx->r2 != ctx->r1) {
        // 0x800D6CFC: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_800D6D3C;
    }
    goto skip_0;
    // 0x800D6CFC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_0:
L_800D6D00:
    // 0x800D6D00: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800D6D04: bgtzl       $t4, L_800D6D3C
    if (SIGNED(ctx->r12) > 0) {
        // 0x800D6D08: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_800D6D3C;
    }
    goto skip_1;
    // 0x800D6D08: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x800D6D0C: bltz        $t4, L_800D6D1C
    if (SIGNED(ctx->r12) < 0) {
        // 0x800D6D10: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_800D6D1C;
    }
    // 0x800D6D10: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800D6D14: b           L_800D6D3C
    // 0x800D6D18: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
        goto L_800D6D3C;
    // 0x800D6D18: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_800D6D1C:
    // 0x800D6D1C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800D6D20: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x800D6D24: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800D6D28: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x800D6D2C: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x800D6D30: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800D6D34: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800D6D38: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_800D6D3C:
    // 0x800D6D3C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800D6D40: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x800D6D44: bne         $t2, $zero, L_800D6D60
    if (ctx->r10 != 0) {
        // 0x800D6D48: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_800D6D60;
    }
    // 0x800D6D48: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D6D4C: bnel        $t3, $zero, L_800D6D64
    if (ctx->r11 != 0) {
        // 0x800D6D50: addiu       $s0, $zero, 0x17
        ctx->r16 = ADD32(0, 0X17);
            goto L_800D6D64;
    }
    goto skip_2;
    // 0x800D6D50: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
    skip_2:
    // 0x800D6D54: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x800D6D58: beql        $t4, $zero, L_800D6D9C
    if (ctx->r12 == 0) {
        // 0x800D6D5C: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_800D6D9C;
    }
    goto skip_3;
    // 0x800D6D5C: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    skip_3:
L_800D6D60:
    // 0x800D6D60: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
L_800D6D64:
    // 0x800D6D64: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800D6D68: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800D6D6C: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800D6D70: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800D6D74: jal         0x800CEFEC
    // 0x800D6D78: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x800D6D78: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_0:
    // 0x800D6D7C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800D6D80: addu        $t6, $v1, $s3
    ctx->r14 = ADD32(ctx->r3, ctx->r19);
    // 0x800D6D84: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800D6D88: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x800D6D8C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800D6D90: addu        $t8, $s2, $t0
    ctx->r24 = ADD32(ctx->r18, ctx->r8);
    // 0x800D6D94: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800D6D98: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_800D6D9C:
    // 0x800D6D9C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D6DA0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800D6DA4: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800D6DA8: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800D6DAC: jal         0x800CF028
    // 0x800D6DB0: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800D6DB0: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_1:
    // 0x800D6DB4: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800D6DB8: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x800D6DBC: bltz        $v0, L_800D6E6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D6DC0: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_800D6E6C;
    }
    // 0x800D6DC0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800D6DC4: bgtz        $v0, L_800D6DD4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D6DC8: nop
    
            goto L_800D6DD4;
    }
    // 0x800D6DC8: nop

    // 0x800D6DCC: beql        $v1, $zero, L_800D6E70
    if (ctx->r3 == 0) {
        // 0x800D6DD0: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_800D6E70;
    }
    goto skip_4;
    // 0x800D6DD0: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_4:
L_800D6DD4:
    // 0x800D6DD4: blez        $s0, L_800D6E6C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D6DD8: sra         $t4, $t1, 31
        ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
            goto L_800D6E6C;
    }
    // 0x800D6DD8: sra         $t4, $t1, 31
    ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800D6DDC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800D6DE0: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x800D6DE4: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800D6DE8: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800D6DEC: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800D6DF0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800D6DF4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_800D6DF8:
    // 0x800D6DF8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800D6DFC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800D6E00: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800D6E04: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800D6E08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D6E0C: jal         0x800D79D0
    // 0x800D6E10: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x800D6E10: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x800D6E14: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800D6E18: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800D6E1C: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x800D6E20: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D6E24: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x800D6E28: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800D6E2C: addu        $t7, $s2, $a0
    ctx->r15 = ADD32(ctx->r18, ctx->r4);
    // 0x800D6E30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D6E34: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x800D6E38: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800D6E3C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800D6E40: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800D6E44: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800D6E48: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800D6E4C: bltz        $t8, L_800D6E6C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800D6E50: sw          $t9, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r25;
            goto L_800D6E6C;
    }
    // 0x800D6E50: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800D6E54: bgtz        $t8, L_800D6E64
    if (SIGNED(ctx->r24) > 0) {
        // 0x800D6E58: nop
    
            goto L_800D6E64;
    }
    // 0x800D6E58: nop

    // 0x800D6E5C: beql        $t9, $zero, L_800D6E70
    if (ctx->r25 == 0) {
        // 0x800D6E60: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_800D6E70;
    }
    goto skip_5;
    // 0x800D6E60: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_5:
L_800D6E64:
    // 0x800D6E64: bgtzl       $s0, L_800D6DF8
    if (SIGNED(ctx->r16) > 0) {
        // 0x800D6E68: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_800D6DF8;
    }
    goto skip_6;
    // 0x800D6E68: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_6:
L_800D6E6C:
    // 0x800D6E6C: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
L_800D6E70:
    // 0x800D6E70: subu        $a2, $t4, $s0
    ctx->r6 = SUB32(ctx->r12, ctx->r16);
    // 0x800D6E74: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x800D6E78: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x800D6E7C: jal         0x800CE6D0
    // 0x800D6E80: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x800D6E80: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    after_3:
    // 0x800D6E84: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x800D6E88: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x800D6E8C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800D6E90: beq         $at, $zero, L_800D6E9C
    if (ctx->r1 == 0) {
        // 0x800D6E94: subu        $t5, $a0, $a1
        ctx->r13 = SUB32(ctx->r4, ctx->r5);
            goto L_800D6E9C;
    }
    // 0x800D6E94: subu        $t5, $a0, $a1
    ctx->r13 = SUB32(ctx->r4, ctx->r5);
    // 0x800D6E98: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
L_800D6E9C:
    // 0x800D6E9C: bgezl       $a0, L_800D6EE0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800D6EA0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800D6EE0;
    }
    goto skip_7;
    // 0x800D6EA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x800D6EA4: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x800D6EA8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800D6EAC: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x800D6EB0: bnel        $t7, $at, L_800D6EE0
    if (ctx->r15 != ctx->r1) {
        // 0x800D6EB4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800D6EE0;
    }
    goto skip_8;
    // 0x800D6EB4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x800D6EB8: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x800D6EBC: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x800D6EC0: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800D6EC4: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x800D6EC8: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x800D6ECC: subu        $s0, $t3, $a1
    ctx->r16 = SUB32(ctx->r11, ctx->r5);
    // 0x800D6ED0: blez        $s0, L_800D6EDC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D6ED4: addu        $t4, $v0, $s0
        ctx->r12 = ADD32(ctx->r2, ctx->r16);
            goto L_800D6EDC;
    }
    // 0x800D6ED4: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x800D6ED8: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
L_800D6EDC:
    // 0x800D6EDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800D6EE0:
    // 0x800D6EE0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800D6EE4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800D6EE8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800D6EEC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800D6EF0: jr          $ra
    // 0x800D6EF4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800D6EF4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x800D6EF8: nop

    // 0x800D6EFC: nop

;}
