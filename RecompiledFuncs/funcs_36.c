#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void _Genld(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6F00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6F04: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D6F08: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D6F0C: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D6F10: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D6F14: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800D6F18: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D6F1C: andi        $t6, $s4, 0xFF
    ctx->r14 = ctx->r20 & 0XFF;
    // 0x800D6F20: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x800D6F24: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800D6F28: bgtz        $s3, L_800D6F3C
    if (SIGNED(ctx->r19) > 0) {
        // 0x800D6F2C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D6F3C;
    }
    // 0x800D6F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6F30: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800D6F34: addiu       $s1, $s1, -0x61D0
    ctx->r17 = ADD32(ctx->r17, -0X61D0);
    // 0x800D6F38: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800D6F3C:
    // 0x800D6F3C: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x800D6F40: beq         $v0, $s4, L_800D6F74
    if (ctx->r2 == ctx->r20) {
        // 0x800D6F44: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_800D6F74;
    }
    // 0x800D6F44: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x800D6F48: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800D6F4C: beq         $a0, $v1, L_800D6F58
    if (ctx->r4 == ctx->r3) {
        // 0x800D6F50: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800D6F58;
    }
    // 0x800D6F50: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800D6F54: bne         $v1, $at, L_800D71B0
    if (ctx->r3 != ctx->r1) {
        // 0x800D6F58: slti        $at, $s2, -0x4
        ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
            goto L_800D71B0;
    }
L_800D6F58:
    // 0x800D6F58: slti        $at, $s2, -0x4
    ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
    // 0x800D6F5C: bne         $at, $zero, L_800D71B0
    if (ctx->r1 != 0) {
        // 0x800D6F60: nop
    
            goto L_800D71B0;
    }
    // 0x800D6F60: nop

    // 0x800D6F64: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800D6F68: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D6F6C: beq         $at, $zero, L_800D71B0
    if (ctx->r1 == 0) {
        // 0x800D6F70: nop
    
            goto L_800D71B0;
    }
    // 0x800D6F70: nop

L_800D6F74:
    // 0x800D6F74: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D6F78: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x800D6F7C: beq         $v0, $v1, L_800D6FB8
    if (ctx->r2 == ctx->r3) {
        // 0x800D6F80: sra         $s2, $t8, 16
        ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
            goto L_800D6FB8;
    }
    // 0x800D6F80: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D6F84: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x800D6F88: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6F8C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x800D6F90: bne         $t7, $zero, L_800D6FA8
    if (ctx->r15 != 0) {
        // 0x800D6F94: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800D6FA8;
    }
    // 0x800D6F94: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D6F98: beql        $at, $zero, L_800D6FAC
    if (ctx->r1 == 0) {
        // 0x800D6F9C: subu        $t8, $v0, $s2
        ctx->r24 = SUB32(ctx->r2, ctx->r18);
            goto L_800D6FAC;
    }
    goto skip_0;
    // 0x800D6F9C: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
    skip_0:
    // 0x800D6FA0: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800D6FA4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_800D6FA8:
    // 0x800D6FA8: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
L_800D6FAC:
    // 0x800D6FAC: bgez        $t8, L_800D6FB8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D6FB0: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800D6FB8;
    }
    // 0x800D6FB0: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800D6FB4: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800D6FB8:
    // 0x800D6FB8: bgtz        $s2, L_800D7088
    if (SIGNED(ctx->r18) > 0) {
        // 0x800D6FBC: slt         $at, $s3, $s2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800D7088;
    }
    // 0x800D6FBC: slt         $at, $s3, $s2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800D6FC0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D6FC4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D6FC8: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800D6FCC: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800D6FD0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800D6FD4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800D6FD8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D6FDC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6FE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D6FE4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800D6FE8: bgtz        $v0, L_800D7000
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D6FEC: sw          $t8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r24;
            goto L_800D7000;
    }
    // 0x800D6FEC: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x800D6FF0: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x800D6FF4: andi        $t9, $t6, 0x8
    ctx->r25 = ctx->r14 & 0X8;
    // 0x800D6FF8: beql        $t9, $zero, L_800D7028
    if (ctx->r25 == 0) {
        // 0x800D6FFC: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800D7028;
    }
    goto skip_1;
    // 0x800D6FFC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
L_800D7000:
    // 0x800D7000: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800D7004: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800D7008: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x800D700C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800D7010: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x800D7014: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D7018: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D701C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800D7020: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800D7024: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800D7028:
    // 0x800D7028: beql        $at, $zero, L_800D7044
    if (ctx->r1 == 0) {
        // 0x800D702C: addu        $t8, $v0, $s2
        ctx->r24 = ADD32(ctx->r2, ctx->r18);
            goto L_800D7044;
    }
    goto skip_2;
    // 0x800D702C: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
    skip_2:
    // 0x800D7030: negu        $s2, $v0
    ctx->r18 = SUB32(0, ctx->r2);
    // 0x800D7034: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800D7038: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800D703C: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800D7040: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
L_800D7044:
    // 0x800D7044: slt         $at, $t8, $s3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D7048: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x800D704C: beq         $at, $zero, L_800D7060
    if (ctx->r1 == 0) {
        // 0x800D7050: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800D7060;
    }
    // 0x800D7050: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800D7054: sll         $s3, $t8, 16
    ctx->r19 = S32(ctx->r24 << 16);
    // 0x800D7058: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D705C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800D7060:
    // 0x800D7060: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D7064: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D7068: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x800D706C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D7070: jal         0x800CE6D0
    // 0x800D7074: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800D7074: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x800D7078: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x800D707C: subu        $t6, $t8, $s3
    ctx->r14 = SUB32(ctx->r24, ctx->r19);
    // 0x800D7080: b           L_800D740C
    // 0x800D7084: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_800D740C;
    // 0x800D7084: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_800D7088:
    // 0x800D7088: beq         $at, $zero, L_800D7100
    if (ctx->r1 == 0) {
        // 0x800D708C: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800D7100;
    }
    // 0x800D708C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D7090: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D7094: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D7098: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D709C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D70A0: jal         0x800CE6D0
    // 0x800D70A4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x800D70A4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x800D70A8: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D70AC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D70B0: subu        $t7, $s2, $s3
    ctx->r15 = SUB32(ctx->r18, ctx->r19);
    // 0x800D70B4: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x800D70B8: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800D70BC: bgtz        $v0, L_800D70D4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D70C0: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_800D70D4;
    }
    // 0x800D70C0: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x800D70C4: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800D70C8: andi        $t8, $t9, 0x8
    ctx->r24 = ctx->r25 & 0X8;
    // 0x800D70CC: beq         $t8, $zero, L_800D70F8
    if (ctx->r24 == 0) {
        // 0x800D70D0: nop
    
            goto L_800D70F8;
    }
    // 0x800D70D0: nop

L_800D70D4:
    // 0x800D70D4: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D70D8: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D70DC: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800D70E0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D70E4: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x800D70E8: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x800D70EC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D70F0: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800D70F4: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_800D70F8:
    // 0x800D70F8: b           L_800D740C
    // 0x800D70FC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_800D740C;
    // 0x800D70FC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_800D7100:
    // 0x800D7100: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x800D7104: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D7108: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800D710C: jal         0x800CE6D0
    // 0x800D7110: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x800D7110: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x800D7114: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D7118: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D711C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800D7120: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800D7124: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800D7128: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x800D712C: bgtz        $v0, L_800D7144
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D7130: sra         $s3, $t6, 16
        ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
            goto L_800D7144;
    }
    // 0x800D7130: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D7134: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800D7138: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x800D713C: beql        $t9, $zero, L_800D716C
    if (ctx->r25 == 0) {
        // 0x800D7140: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_800D716C;
    }
    goto skip_3;
    // 0x800D7140: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    skip_3:
L_800D7144:
    // 0x800D7144: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800D7148: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D714C: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800D7150: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800D7154: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800D7158: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D715C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D7160: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800D7164: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800D7168: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
L_800D716C:
    // 0x800D716C: beq         $at, $zero, L_800D7180
    if (ctx->r1 == 0) {
        // 0x800D7170: addu        $a1, $s2, $s1
        ctx->r5 = ADD32(ctx->r18, ctx->r17);
            goto L_800D7180;
    }
    // 0x800D7170: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x800D7174: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800D7178: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D717C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800D7180:
    // 0x800D7180: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800D7184: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D7188: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D718C: jal         0x800CE6D0
    // 0x800D7190: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x800D7190: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_3:
    // 0x800D7194: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D7198: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800D719C: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x800D71A0: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x800D71A4: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800D71A8: b           L_800D740C
    // 0x800D71AC: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
        goto L_800D740C;
    // 0x800D71AC: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
L_800D71B0:
    // 0x800D71B0: beq         $a0, $v1, L_800D71C0
    if (ctx->r4 == ctx->r3) {
        // 0x800D71B4: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800D71C0;
    }
    // 0x800D71B4: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800D71B8: bnel        $v1, $at, L_800D7200
    if (ctx->r3 != ctx->r1) {
        // 0x800D71BC: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_800D7200;
    }
    goto skip_4;
    // 0x800D71BC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_4:
L_800D71C0:
    // 0x800D71C0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D71C4: addiu       $s4, $zero, 0x45
    ctx->r20 = ADD32(0, 0X45);
    // 0x800D71C8: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D71CC: beql        $at, $zero, L_800D71E0
    if (ctx->r1 == 0) {
        // 0x800D71D0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800D71E0;
    }
    goto skip_5;
    // 0x800D71D0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_5:
    // 0x800D71D4: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800D71D8: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800D71DC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_800D71E0:
    // 0x800D71E0: bgez        $t7, L_800D71EC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800D71E4: sw          $t7, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r15;
            goto L_800D71EC;
    }
    // 0x800D71E4: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x800D71E8: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800D71EC:
    // 0x800D71EC: bne         $a0, $v1, L_800D71FC
    if (ctx->r4 != ctx->r3) {
        // 0x800D71F0: nop
    
            goto L_800D71FC;
    }
    // 0x800D71F0: nop

    // 0x800D71F4: b           L_800D71FC
    // 0x800D71F8: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
        goto L_800D71FC;
    // 0x800D71F8: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
L_800D71FC:
    // 0x800D71FC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_800D7200:
    // 0x800D7200: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D7204: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x800D7208: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D720C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800D7210: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x800D7214: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D7218: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D721C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800D7220: bgtz        $v0, L_800D7238
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D7224: sw          $t7, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r15;
            goto L_800D7238;
    }
    // 0x800D7224: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800D7228: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800D722C: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x800D7230: beq         $t6, $zero, L_800D725C
    if (ctx->r14 == 0) {
        // 0x800D7234: nop
    
            goto L_800D725C;
    }
    // 0x800D7234: nop

L_800D7238:
    // 0x800D7238: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D723C: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D7240: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x800D7244: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800D7248: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800D724C: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D7250: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D7254: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800D7258: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
L_800D725C:
    // 0x800D725C: blezl       $v0, L_800D72B8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D7260: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_800D72B8;
    }
    goto skip_6;
    // 0x800D7260: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_6:
    // 0x800D7264: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800D7268: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800D726C: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D7270: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D7274: beq         $at, $zero, L_800D7288
    if (ctx->r1 == 0) {
        // 0x800D7278: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800D7288;
    }
    // 0x800D7278: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D727C: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800D7280: sra         $t7, $s3, 16
    ctx->r15 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D7284: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_800D7288:
    // 0x800D7288: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800D728C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D7290: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D7294: jal         0x800CE6D0
    // 0x800D7298: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x800D7298: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_4:
    // 0x800D729C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800D72A0: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800D72A4: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x800D72A8: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x800D72AC: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800D72B0: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x800D72B4: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_800D72B8:
    // 0x800D72B8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D72BC: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800D72C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D72C4: bltz        $s2, L_800D72DC
    if (SIGNED(ctx->r18) < 0) {
        // 0x800D72C8: sb          $s4, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r20;
            goto L_800D72DC;
    }
    // 0x800D72C8: sb          $s4, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r20;
    // 0x800D72CC: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x800D72D0: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x800D72D4: b           L_800D72F8
    // 0x800D72D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800D72F8;
    // 0x800D72D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800D72DC:
    // 0x800D72DC: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
    // 0x800D72E0: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D72E4: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800D72E8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D72EC: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800D72F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D72F4: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_800D72F8:
    // 0x800D72F8: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x800D72FC: bnel        $at, $zero, L_800D73A8
    if (ctx->r1 != 0) {
        // 0x800D7300: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800D73A8;
    }
    goto skip_7;
    // 0x800D7300: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_7:
    // 0x800D7304: slti        $at, $s2, 0x3E8
    ctx->r1 = SIGNED(ctx->r18) < 0X3E8 ? 1 : 0;
    // 0x800D7308: bne         $at, $zero, L_800D7358
    if (ctx->r1 != 0) {
        // 0x800D730C: addiu       $v0, $zero, 0x3E8
        ctx->r2 = ADD32(0, 0X3E8);
            goto L_800D7358;
    }
    // 0x800D730C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x800D7310: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800D7314: bne         $v0, $zero, L_800D7320
    if (ctx->r2 != 0) {
        // 0x800D7318: nop
    
            goto L_800D7320;
    }
    // 0x800D7318: nop

    // 0x800D731C: break       7
    do_break(2148365084);
L_800D7320:
    // 0x800D7320: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D7324: bne         $v0, $at, L_800D7338
    if (ctx->r2 != ctx->r1) {
        // 0x800D7328: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D7338;
    }
    // 0x800D7328: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D732C: bne         $s2, $at, L_800D7338
    if (ctx->r18 != ctx->r1) {
        // 0x800D7330: nop
    
            goto L_800D7338;
    }
    // 0x800D7330: nop

    // 0x800D7334: break       6
    do_break(2148365108);
L_800D7338:
    // 0x800D7338: mfhi        $s2
    ctx->r18 = hi;
    // 0x800D733C: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D7340: mflo        $t9
    ctx->r25 = lo;
    // 0x800D7344: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800D7348: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D734C: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800D7350: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800D7354: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800D7358:
    // 0x800D7358: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800D735C: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800D7360: bne         $v0, $zero, L_800D736C
    if (ctx->r2 != 0) {
        // 0x800D7364: nop
    
            goto L_800D736C;
    }
    // 0x800D7364: nop

    // 0x800D7368: break       7
    do_break(2148365160);
L_800D736C:
    // 0x800D736C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D7370: bne         $v0, $at, L_800D7384
    if (ctx->r2 != ctx->r1) {
        // 0x800D7374: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D7384;
    }
    // 0x800D7374: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D7378: bne         $s2, $at, L_800D7384
    if (ctx->r18 != ctx->r1) {
        // 0x800D737C: nop
    
            goto L_800D7384;
    }
    // 0x800D737C: nop

    // 0x800D7380: break       6
    do_break(2148365184);
L_800D7384:
    // 0x800D7384: mfhi        $s2
    ctx->r18 = hi;
    // 0x800D7388: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D738C: mflo        $t9
    ctx->r25 = lo;
    // 0x800D7390: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800D7394: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D7398: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800D739C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800D73A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D73A4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800D73A8:
    // 0x800D73A8: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800D73AC: bne         $v0, $zero, L_800D73B8
    if (ctx->r2 != 0) {
        // 0x800D73B0: nop
    
            goto L_800D73B8;
    }
    // 0x800D73B0: nop

    // 0x800D73B4: break       7
    do_break(2148365236);
L_800D73B8:
    // 0x800D73B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D73BC: bne         $v0, $at, L_800D73D0
    if (ctx->r2 != ctx->r1) {
        // 0x800D73C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D73D0;
    }
    // 0x800D73C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D73C4: bne         $s2, $at, L_800D73D0
    if (ctx->r18 != ctx->r1) {
        // 0x800D73C8: nop
    
            goto L_800D73D0;
    }
    // 0x800D73C8: nop

    // 0x800D73CC: break       6
    do_break(2148365260);
L_800D73D0:
    // 0x800D73D0: mfhi        $s2
    ctx->r18 = hi;
    // 0x800D73D4: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D73D8: mflo        $t9
    ctx->r25 = lo;
    // 0x800D73DC: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800D73E0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D73E4: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x800D73E8: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800D73EC: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x800D73F0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800D73F4: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800D73F8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D73FC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800D7400: subu        $t6, $s1, $t8
    ctx->r14 = SUB32(ctx->r17, ctx->r24);
    // 0x800D7404: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x800D7408: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_800D740C:
    // 0x800D740C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x800D7410: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800D7414: andi        $t6, $t8, 0x14
    ctx->r14 = ctx->r24 & 0X14;
    // 0x800D7418: bnel        $t6, $at, L_800D745C
    if (ctx->r14 != ctx->r1) {
        // 0x800D741C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D745C;
    }
    goto skip_8;
    // 0x800D741C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x800D7420: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D7424: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D7428: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x800D742C: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x800D7430: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D7434: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x800D7438: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800D743C: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800D7440: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D7444: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x800D7448: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D744C: beq         $at, $zero, L_800D7458
    if (ctx->r1 == 0) {
        // 0x800D7450: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_800D7458;
    }
    // 0x800D7450: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x800D7454: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_800D7458:
    // 0x800D7458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D745C:
    // 0x800D745C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7460: jr          $ra
    // 0x800D7464: nop

    return;
    // 0x800D7464: nop

    // 0x800D7468: jr          $ra
    // 0x800D746C: nop

    return;
    // 0x800D746C: nop

;}
RECOMP_FUNC void _Ldtob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7470: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800D7474: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D7478: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800D747C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800D7480: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800D7484: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800D7488: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800D748C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800D7490: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800D7494: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x800D7498: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x800D749C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x800D74A0: addiu       $s5, $sp, 0xB0
    ctx->r21 = ADD32(ctx->r29, 0XB0);
    // 0x800D74A4: ldc1        $f20, 0x0($a0)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r4, 0X0);
    // 0x800D74A8: bgez        $v0, L_800D74B8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D74AC: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_800D74B8;
    }
    // 0x800D74AC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800D74B0: b           L_800D74E4
    // 0x800D74B4: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
        goto L_800D74E4;
    // 0x800D74B4: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_800D74B8:
    // 0x800D74B8: bne         $v0, $zero, L_800D74E4
    if (ctx->r2 != 0) {
        // 0x800D74BC: lbu         $t8, 0xD7($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0XD7);
            goto L_800D74E4;
    }
    // 0x800D74BC: lbu         $t8, 0xD7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD7);
    // 0x800D74C0: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x800D74C4: beq         $t8, $at, L_800D74D8
    if (ctx->r24 == ctx->r1) {
        // 0x800D74C8: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_800D74D8;
    }
    // 0x800D74C8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x800D74CC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800D74D0: bnel        $t8, $at, L_800D74E8
    if (ctx->r24 != ctx->r1) {
        // 0x800D74D4: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_800D74E8;
    }
    goto skip_0;
    // 0x800D74D4: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    skip_0:
L_800D74D8:
    // 0x800D74D8: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x800D74DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D74E0: sw          $t9, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r25;
L_800D74E4:
    // 0x800D74E4: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
L_800D74E8:
    // 0x800D74E8: addiu       $at, $zero, 0x7FF
    ctx->r1 = ADD32(0, 0X7FF);
    // 0x800D74EC: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x800D74F0: andi        $v1, $a0, 0x7FF0
    ctx->r3 = ctx->r4 & 0X7FF0;
    // 0x800D74F4: sra         $t8, $v1, 4
    ctx->r24 = S32(SIGNED(ctx->r3) >> 4);
    // 0x800D74F8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D74FC: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D7500: bne         $v1, $at, L_800D7564
    if (ctx->r3 != ctx->r1) {
        // 0x800D7504: nop
    
            goto L_800D7564;
    }
    // 0x800D7504: nop

    // 0x800D7508: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x800D750C: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x800D7510: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800D7514: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800D7518: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x800D751C: bnel        $t9, $zero, L_800D7548
    if (ctx->r25 != 0) {
        // 0x800D7520: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800D7548;
    }
    goto skip_1;
    // 0x800D7520: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_1:
    // 0x800D7524: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x800D7528: bnel        $t7, $zero, L_800D7548
    if (ctx->r15 != 0) {
        // 0x800D752C: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800D7548;
    }
    goto skip_2;
    // 0x800D752C: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_2:
    // 0x800D7530: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x800D7534: bnel        $t8, $zero, L_800D7548
    if (ctx->r24 != 0) {
        // 0x800D7538: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800D7548;
    }
    goto skip_3;
    // 0x800D7538: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_3:
    // 0x800D753C: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x800D7540: beq         $t9, $zero, L_800D7550
    if (ctx->r25 == 0) {
        // 0x800D7544: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800D7550;
    }
    // 0x800D7544: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
L_800D7548:
    // 0x800D7548: b           L_800D759C
    // 0x800D754C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800D759C;
    // 0x800D754C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800D7550:
    // 0x800D7550: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800D7554: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800D7558: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800D755C: b           L_800D759C
    // 0x800D7560: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800D759C;
    // 0x800D7560: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800D7564:
    // 0x800D7564: blez        $v1, L_800D7588
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800D7568: andi        $t8, $a0, 0x800F
        ctx->r24 = ctx->r4 & 0X800F;
            goto L_800D7588;
    }
    // 0x800D7568: andi        $t8, $a0, 0x800F
    ctx->r24 = ctx->r4 & 0X800F;
    // 0x800D756C: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800D7570: ori         $t6, $t8, 0x3FF0
    ctx->r14 = ctx->r24 | 0X3FF0;
    // 0x800D7574: addiu       $t7, $v1, -0x3FE
    ctx->r15 = ADD32(ctx->r3, -0X3FE);
    // 0x800D7578: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x800D757C: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800D7580: b           L_800D759C
    // 0x800D7584: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800D759C;
    // 0x800D7584: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800D7588:
    // 0x800D7588: bgez        $v1, L_800D7598
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D758C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D7598;
    }
    // 0x800D758C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D7590: b           L_800D759C
    // 0x800D7594: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800D759C;
    // 0x800D7594: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800D7598:
    // 0x800D7598: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_800D759C:
    // 0x800D759C: blez        $v0, L_800D75E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D75A0: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_800D75E8;
    }
    // 0x800D75A0: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800D75A4: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800D75A8: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D75AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D75B0: bne         $t6, $at, L_800D75C4
    if (ctx->r14 != ctx->r1) {
        // 0x800D75B4: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_800D75C4;
    }
    // 0x800D75B4: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800D75B8: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800D75BC: b           L_800D75CC
    // 0x800D75C0: addiu       $a1, $a1, -0x61D8
    ctx->r5 = ADD32(ctx->r5, -0X61D8);
        goto L_800D75CC;
    // 0x800D75C0: addiu       $a1, $a1, -0x61D8
    ctx->r5 = ADD32(ctx->r5, -0X61D8);
L_800D75C4:
    // 0x800D75C4: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800D75C8: addiu       $a1, $a1, -0x61D4
    ctx->r5 = ADD32(ctx->r5, -0X61D4);
L_800D75CC:
    // 0x800D75CC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800D75D0: sw          $t7, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r15;
    // 0x800D75D4: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x800D75D8: jal         0x800CE6D0
    // 0x800D75DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800D75DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x800D75E0: b           L_800D7998
    // 0x800D75E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800D7998;
    // 0x800D75E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800D75E8:
    // 0x800D75E8: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D75EC: bne         $t6, $zero, L_800D75FC
    if (ctx->r14 != 0) {
        // 0x800D75F0: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800D75FC;
    }
    // 0x800D75F0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800D75F4: b           L_800D7980
    // 0x800D75F8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
        goto L_800D7980;
    // 0x800D75F8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_800D75FC:
    // 0x800D75FC: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800D7600: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D7604: lbu         $t7, 0xD7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD7);
    // 0x800D7608: lh          $t9, 0x9A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X9A);
    // 0x800D760C: c.lt.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d < ctx->f2.d;
    // 0x800D7610: addiu       $at, $zero, 0x7597
    ctx->r1 = ADD32(0, 0X7597);
    // 0x800D7614: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D7618: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x800D761C: bc1f        L_800D7628
    if (!c1cs) {
        // 0x800D7620: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_800D7628;
    }
    // 0x800D7620: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800D7624: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_800D7628:
    // 0x800D7628: multu       $t9, $at
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D762C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800D7630: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x800D7634: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800D7638: mflo        $t8
    ctx->r24 = lo;
    // 0x800D763C: nop

    // 0x800D7640: nop

    // 0x800D7644: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800D7648: mflo        $t6
    ctx->r14 = lo;
    // 0x800D764C: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x800D7650: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800D7654: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D7658: bgez        $t8, L_800D76C0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D765C: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_800D76C0;
    }
    // 0x800D765C: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800D7660: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800D7664: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D7668: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800D766C: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x800D7670: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D7674: and         $v0, $a0, $at
    ctx->r2 = ctx->r4 & ctx->r1;
    // 0x800D7678: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x800D767C: blez        $v0, L_800D7730
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D7680: sh          $t9, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r25;
            goto L_800D7730;
    }
    // 0x800D7680: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x800D7684: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D7688: addiu       $a0, $a0, -0x6220
    ctx->r4 = ADD32(ctx->r4, -0X6220);
L_800D768C:
    // 0x800D768C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800D7690: beq         $t6, $zero, L_800D76AC
    if (ctx->r14 == 0) {
        // 0x800D7694: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800D76AC;
    }
    // 0x800D7694: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800D7698: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800D769C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x800D76A0: ldc1        $f4, 0x0($t7)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r15, 0X0);
    // 0x800D76A4: mul.d       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f4.d);
    // 0x800D76A8: nop

L_800D76AC:
    // 0x800D76AC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800D76B0: bgtz        $t9, L_800D768C
    if (SIGNED(ctx->r25) > 0) {
        // 0x800D76B4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D768C;
    }
    // 0x800D76B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D76B8: b           L_800D7734
    // 0x800D76BC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
        goto L_800D7734;
    // 0x800D76BC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_800D76C0:
    // 0x800D76C0: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x800D76C4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D76C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D76CC: blez        $t6, L_800D7730
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D76D0: andi        $t8, $t6, 0xFFFC
        ctx->r24 = ctx->r14 & 0XFFFC;
            goto L_800D7730;
    }
    // 0x800D76D0: andi        $t8, $t6, 0xFFFC
    ctx->r24 = ctx->r14 & 0XFFFC;
    // 0x800D76D4: sll         $v0, $t8, 16
    ctx->r2 = S32(ctx->r24 << 16);
    // 0x800D76D8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D76DC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800D76E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D76E4: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D76E8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800D76EC: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x800D76F0: blez        $t6, L_800D772C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D76F4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800D772C;
    }
    // 0x800D76F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800D76F8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D76FC: addiu       $a0, $a0, -0x6220
    ctx->r4 = ADD32(ctx->r4, -0X6220);
L_800D7700:
    // 0x800D7700: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800D7704: beq         $t7, $zero, L_800D7720
    if (ctx->r15 == 0) {
        // 0x800D7708: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800D7720;
    }
    // 0x800D7708: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800D770C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800D7710: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800D7714: ldc1        $f6, 0x0($t9)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r25, 0X0);
    // 0x800D7718: mul.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800D771C: nop

L_800D7720:
    // 0x800D7720: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800D7724: bgtz        $t6, L_800D7700
    if (SIGNED(ctx->r14) > 0) {
        // 0x800D7728: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D7700;
    }
    // 0x800D7728: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D772C:
    // 0x800D772C: div.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f0.d);
L_800D7730:
    // 0x800D7730: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_800D7734:
    // 0x800D7734: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x800D7738: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800D773C: bne         $t7, $at, L_800D7750
    if (ctx->r15 != ctx->r1) {
        // 0x800D7740: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_800D7750;
    }
    // 0x800D7740: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800D7744: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x800D7748: b           L_800D7750
    // 0x800D774C: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
        goto L_800D7750;
    // 0x800D774C: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_800D7750:
    // 0x800D7750: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x800D7754: addu        $s4, $a1, $t9
    ctx->r20 = ADD32(ctx->r5, ctx->r25);
    // 0x800D7758: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x800D775C: bne         $at, $zero, L_800D7768
    if (ctx->r1 != 0) {
        // 0x800D7760: nop
    
            goto L_800D7768;
    }
    // 0x800D7760: nop

    // 0x800D7764: addiu       $s4, $zero, 0x13
    ctx->r20 = ADD32(0, 0X13);
L_800D7768:
    // 0x800D7768: blez        $s4, L_800D7838
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800D776C: sb          $t6, 0xB0($sp)
        MEM_B(0XB0, ctx->r29) = ctx->r14;
            goto L_800D7838;
    }
    // 0x800D776C: sb          $t6, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r14;
    // 0x800D7770: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800D7774: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x800D7778: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x800D777C: bc1fl       L_800D783C
    if (!c1cs) {
        // 0x800D7780: lh          $t8, 0x9A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X9A);
            goto L_800D783C;
    }
    goto skip_4;
    // 0x800D7780: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
    skip_4:
    // 0x800D7784: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
L_800D7788:
    // 0x800D7788: addiu       $s4, $s4, -0x8
    ctx->r20 = ADD32(ctx->r20, -0X8);
    // 0x800D778C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800D7790: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x800D7794: blez        $s4, L_800D77B8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800D7798: nop
    
            goto L_800D77B8;
    }
    // 0x800D7798: nop

    // 0x800D779C: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x800D77A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D77A4: ldc1        $f8, -0x61C8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X61C8);
    // 0x800D77A8: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x800D77AC: sub.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f20.d - ctx->f4.d;
    // 0x800D77B0: mul.d       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f20.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800D77B4: nop

L_800D77B8:
    // 0x800D77B8: blez        $s1, L_800D7800
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800D77BC: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_800D7800;
    }
    // 0x800D77BC: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x800D77C0: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x800D77C4: bltz        $s0, L_800D7800
    if (SIGNED(ctx->r16) < 0) {
        // 0x800D77C8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D7800;
    }
    // 0x800D77C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800D77CC:
    // 0x800D77CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D77D0: jal         0x800D7AD0
    // 0x800D77D4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    ldiv_recomp(rdram, ctx);
        goto after_1;
    // 0x800D77D4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x800D77D8: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800D77DC: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800D77E0: addiu       $t9, $t8, 0x30
    ctx->r25 = ADD32(ctx->r24, 0X30);
    // 0x800D77E4: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x800D77E8: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x800D77EC: blezl       $s1, L_800D7804
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800D77F0: mtc1        $zero, $f3
        ctx->f_odd[(3 - 1) * 2] = 0;
            goto L_800D7804;
    }
    goto skip_5;
    // 0x800D77F0: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    skip_5:
    // 0x800D77F4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800D77F8: bgezl       $s0, L_800D77CC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800D77FC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D77CC;
    }
    goto skip_6;
    // 0x800D77FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
L_800D7800:
    // 0x800D7800: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
L_800D7804:
    // 0x800D7804: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D7808: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800D780C: bltz        $s0, L_800D7820
    if (SIGNED(ctx->r16) < 0) {
        // 0x800D7810: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800D7820;
    }
L_800D7810:
    // 0x800D7810: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800D7814: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800D7818: bgez        $s0, L_800D7810
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800D781C: sb          $s3, 0x0($s5)
        MEM_B(0X0, ctx->r21) = ctx->r19;
            goto L_800D7810;
    }
    // 0x800D781C: sb          $s3, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r19;
L_800D7820:
    // 0x800D7820: blez        $s4, L_800D7838
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800D7824: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_800D7838;
    }
    // 0x800D7824: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800D7828: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800D782C: nop

    // 0x800D7830: bc1tl       L_800D7788
    if (c1cs) {
        // 0x800D7834: trunc.w.d   $f8, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
            goto L_800D7788;
    }
    goto skip_7;
    // 0x800D7834: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
    skip_7:
L_800D7838:
    // 0x800D7838: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
L_800D783C:
    // 0x800D783C: lbu         $t6, 0xB1($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB1);
    // 0x800D7840: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x800D7844: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800D7848: subu        $s4, $s5, $t7
    ctx->r20 = SUB32(ctx->r21, ctx->r15);
    // 0x800D784C: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800D7850: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800D7854: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x800D7858: bne         $v0, $t6, L_800D7880
    if (ctx->r2 != ctx->r14) {
        // 0x800D785C: addiu       $s5, $sp, 0xB1
        ctx->r21 = ADD32(ctx->r29, 0XB1);
            goto L_800D7880;
    }
    // 0x800D785C: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x800D7860: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
L_800D7864:
    // 0x800D7864: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800D7868: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800D786C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800D7870: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x800D7874: lbu         $t9, 0x0($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X0);
    // 0x800D7878: beql        $v0, $t9, L_800D7864
    if (ctx->r2 == ctx->r25) {
        // 0x800D787C: lh          $t7, 0x9A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X9A);
            goto L_800D7864;
    }
    goto skip_8;
    // 0x800D787C: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
    skip_8:
L_800D7880:
    // 0x800D7880: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800D7884: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x800D7888: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800D788C: bne         $t6, $at, L_800D78A0
    if (ctx->r14 != ctx->r1) {
        // 0x800D7890: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_800D78A0;
    }
    // 0x800D7890: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800D7894: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x800D7898: b           L_800D78C0
    // 0x800D789C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_800D78C0;
    // 0x800D789C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800D78A0:
    // 0x800D78A0: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x800D78A4: beq         $t7, $at, L_800D78B4
    if (ctx->r15 == ctx->r1) {
        // 0x800D78A8: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_800D78B4;
    }
    // 0x800D78A8: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x800D78AC: bne         $t7, $at, L_800D78BC
    if (ctx->r15 != ctx->r1) {
        // 0x800D78B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D78BC;
    }
    // 0x800D78B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D78B4:
    // 0x800D78B4: b           L_800D78BC
    // 0x800D78B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D78BC;
    // 0x800D78B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D78BC:
    // 0x800D78BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800D78C0:
    // 0x800D78C0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x800D78C4: addu        $s3, $a1, $t9
    ctx->r19 = ADD32(ctx->r5, ctx->r25);
    // 0x800D78C8: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800D78CC: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D78D0: slt         $at, $s4, $s3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D78D4: beq         $at, $zero, L_800D78E8
    if (ctx->r1 == 0) {
        // 0x800D78D8: nop
    
            goto L_800D78E8;
    }
    // 0x800D78D8: nop

    // 0x800D78DC: sll         $s3, $s4, 16
    ctx->r19 = S32(ctx->r20 << 16);
    // 0x800D78E0: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D78E4: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_800D78E8:
    // 0x800D78E8: blez        $s3, L_800D7980
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800D78EC: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_800D7980;
    }
    // 0x800D78EC: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800D78F0: beq         $at, $zero, L_800D7910
    if (ctx->r1 == 0) {
        // 0x800D78F4: addu        $v0, $s3, $s5
        ctx->r2 = ADD32(ctx->r19, ctx->r21);
            goto L_800D7910;
    }
    // 0x800D78F4: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
    // 0x800D78F8: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800D78FC: slti        $at, $t9, 0x35
    ctx->r1 = SIGNED(ctx->r25) < 0X35 ? 1 : 0;
    // 0x800D7900: bnel        $at, $zero, L_800D7914
    if (ctx->r1 != 0) {
        // 0x800D7904: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_800D7914;
    }
    goto skip_9;
    // 0x800D7904: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    skip_9:
    // 0x800D7908: b           L_800D7918
    // 0x800D790C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
        goto L_800D7918;
    // 0x800D790C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
L_800D7910:
    // 0x800D7910: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
L_800D7914:
    // 0x800D7914: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
L_800D7918:
    // 0x800D7918: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x800D791C: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x800D7920: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D7924: bne         $a1, $t6, L_800D794C
    if (ctx->r5 != ctx->r14) {
        // 0x800D7928: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_800D794C;
    }
    // 0x800D7928: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x800D792C: addu        $v0, $v1, $s5
    ctx->r2 = ADD32(ctx->r3, ctx->r21);
L_800D7930:
    // 0x800D7930: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x800D7934: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800D7938: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800D793C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800D7940: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800D7944: beq         $a0, $t9, L_800D7930
    if (ctx->r4 == ctx->r25) {
        // 0x800D7948: sra         $s3, $t7, 16
        ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
            goto L_800D7930;
    }
    // 0x800D7948: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
L_800D794C:
    // 0x800D794C: bne         $a0, $at, L_800D7960
    if (ctx->r4 != ctx->r1) {
        // 0x800D7950: addu        $v0, $s5, $v1
        ctx->r2 = ADD32(ctx->r21, ctx->r3);
            goto L_800D7960;
    }
    // 0x800D7950: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x800D7954: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800D7958: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D795C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_800D7960:
    // 0x800D7960: bgez        $v1, L_800D7980
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D7964: lh          $t6, 0x9A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X9A);
            goto L_800D7980;
    }
    // 0x800D7964: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x800D7968: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800D796C: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800D7970: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D7974: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800D7978: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D797C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_800D7980:
    // 0x800D7980: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x800D7984: lbu         $s4, 0xD7($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XD7);
    // 0x800D7988: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x800D798C: jal         0x800D6F00
    // 0x800D7990: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    _Genld(rdram, ctx);
        goto after_2;
    // 0x800D7990: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    after_2:
    // 0x800D7994: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800D7998:
    // 0x800D7998: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800D799C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800D79A0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800D79A4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800D79A8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800D79AC: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800D79B0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800D79B4: jr          $ra
    // 0x800D79B8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x800D79B8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    // 0x800D79BC: nop

;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D79D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D79D4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D79D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D79DC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800D79E0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800D79E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D79E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800D79EC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800D79F0: jal         0x800CF0CC
    // 0x800D79F4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    __ll_div_recomp(rdram, ctx);
        goto after_0;
    // 0x800D79F4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x800D79F8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D79FC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800D7A00: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800D7A04: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800D7A08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D7A0C: jal         0x800CF128
    // 0x800D7A10: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800D7A10: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x800D7A14: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800D7A18: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800D7A1C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800D7A20: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x800D7A24: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x800D7A28: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x800D7A2C: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x800D7A30: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800D7A34: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800D7A38: bgtz        $t0, L_800D7A98
    if (SIGNED(ctx->r8) > 0) {
        // 0x800D7A3C: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_800D7A98;
    }
    // 0x800D7A3C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800D7A40: bltz        $t0, L_800D7A50
    if (SIGNED(ctx->r8) < 0) {
        // 0x800D7A44: nop
    
            goto L_800D7A50;
    }
    // 0x800D7A44: nop

    // 0x800D7A48: b           L_800D7A9C
    // 0x800D7A4C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
        goto L_800D7A9C;
    // 0x800D7A4C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800D7A50:
    // 0x800D7A50: bltzl       $t8, L_800D7A9C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800D7A54: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_800D7A9C;
    }
    goto skip_0;
    // 0x800D7A54: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_0:
    // 0x800D7A58: bgtz        $t8, L_800D7A68
    if (SIGNED(ctx->r24) > 0) {
        // 0x800D7A5C: addiu       $t3, $t1, 0x1
        ctx->r11 = ADD32(ctx->r9, 0X1);
            goto L_800D7A68;
    }
    // 0x800D7A5C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x800D7A60: beql        $t9, $zero, L_800D7A9C
    if (ctx->r25 == 0) {
        // 0x800D7A64: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_800D7A9C;
    }
    goto skip_1;
    // 0x800D7A64: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_1:
L_800D7A68:
    // 0x800D7A68: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800D7A6C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800D7A70: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x800D7A74: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x800D7A78: subu        $t6, $t8, $t4
    ctx->r14 = SUB32(ctx->r24, ctx->r12);
    // 0x800D7A7C: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x800D7A80: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x800D7A84: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x800D7A88: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800D7A8C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800D7A90: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800D7A94: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_800D7A98:
    // 0x800D7A98: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800D7A9C:
    // 0x800D7A9C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800D7AA0: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x800D7AA4: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x800D7AA8: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800D7AAC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800D7AB0: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x800D7AB4: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x800D7AB8: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x800D7ABC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800D7AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7AC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D7AC8: jr          $ra
    // 0x800D7ACC: nop

    return;
    // 0x800D7ACC: nop

;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7AD0: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x800D7AD4: mflo        $v0
    ctx->r2 = lo;
    // 0x800D7AD8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800D7ADC: bne         $a2, $zero, L_800D7AE8
    if (ctx->r6 != 0) {
        // 0x800D7AE0: nop
    
            goto L_800D7AE8;
    }
    // 0x800D7AE0: nop

    // 0x800D7AE4: break       7
    do_break(2148367076);
L_800D7AE8:
    // 0x800D7AE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D7AEC: bne         $a2, $at, L_800D7B00
    if (ctx->r6 != ctx->r1) {
        // 0x800D7AF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D7B00;
    }
    // 0x800D7AF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D7AF4: bne         $a1, $at, L_800D7B00
    if (ctx->r5 != ctx->r1) {
        // 0x800D7AF8: nop
    
            goto L_800D7B00;
    }
    // 0x800D7AF8: nop

    // 0x800D7AFC: break       6
    do_break(2148367100);
L_800D7B00:
    // 0x800D7B00: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D7B04: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800D7B08: addiu       $t7, $sp, 0x0
    ctx->r15 = ADD32(ctx->r29, 0X0);
    // 0x800D7B0C: mflo        $t6
    ctx->r14 = lo;
    // 0x800D7B10: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x800D7B14: bgez        $v0, L_800D7B38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D7B18: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_800D7B38;
    }
    // 0x800D7B18: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800D7B1C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800D7B20: blez        $v1, L_800D7B38
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800D7B24: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_800D7B38;
    }
    // 0x800D7B24: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800D7B28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D7B2C: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x800D7B30: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800D7B34: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_800D7B38:
    // 0x800D7B38: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800D7B3C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D7B40: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x800D7B44: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800D7B48: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800D7B4C: jr          $ra
    // 0x800D7B50: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x800D7B50: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x800D7B54: nop

    // 0x800D7B58: nop

    // 0x800D7B5C: nop

;}
RECOMP_FUNC void static_0_8007A524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A524: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A528: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007A52C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007A530: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007A534: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007A538: addiu       $t0, $zero, -0x3
    ctx->r8 = ADD32(0, -0X3);
L_8007A53C:
    // 0x8007A53C: lw          $t6, 0x284($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X284);
    // 0x8007A540: lw          $s0, 0x268($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X268);
    // 0x8007A544: lw          $v0, 0x264($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X264);
    // 0x8007A548: beq         $t6, $zero, L_8007A5A4
    if (ctx->r14 == 0) {
        // 0x8007A54C: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8007A5A4;
    }
    // 0x8007A54C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007A550: andi        $t7, $a3, 0x2
    ctx->r15 = ctx->r7 & 0X2;
    // 0x8007A554: beq         $t7, $zero, L_8007A5A8
    if (ctx->r15 == 0) {
        // 0x8007A558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8007A5A8;
    }
    // 0x8007A558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A55C: beq         $s0, $zero, L_8007A580
    if (ctx->r16 == 0) {
        // 0x8007A560: nop
    
            goto L_8007A580;
    }
    // 0x8007A560: nop

    // 0x8007A564: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8007A568: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A56C: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x8007A570: beq         $t9, $zero, L_8007A580
    if (ctx->r25 == 0) {
        // 0x8007A574: nop
    
            goto L_8007A580;
    }
    // 0x8007A574: nop

    // 0x8007A578: b           L_8007A6F4
    // 0x8007A57C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
        goto L_8007A6F4;
    // 0x8007A57C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
L_8007A580:
    // 0x8007A580: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8007A584: lw          $t2, 0x264($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X264);
    // 0x8007A588: sw          $zero, 0x284($s1)
    MEM_W(0X284, ctx->r17) = 0;
    // 0x8007A58C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8007A590: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A594: bne         $t3, $zero, L_8007A6F4
    if (ctx->r11 != 0) {
        // 0x8007A598: sw          $t3, 0x264($s1)
        MEM_W(0X264, ctx->r17) = ctx->r11;
            goto L_8007A6F4;
    }
    // 0x8007A598: sw          $t3, 0x264($s1)
    MEM_W(0X264, ctx->r17) = ctx->r11;
    // 0x8007A59C: b           L_8007A6F4
    // 0x8007A5A0: sw          $zero, 0x26C($s1)
    MEM_W(0X26C, ctx->r17) = 0;
        goto L_8007A6F4;
    // 0x8007A5A0: sw          $zero, 0x26C($s1)
    MEM_W(0X26C, ctx->r17) = 0;
L_8007A5A4:
    // 0x8007A5A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8007A5A8:
    // 0x8007A5A8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8007A5AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007A5B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007A5B4: jal         0x8007A238
    // 0x8007A5B8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    __scTaskReady(rdram, ctx);
        goto after_0;
    // 0x8007A5B8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8007A5BC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8007A5C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A5C4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8007A5C8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8007A5CC: addiu       $t0, $zero, -0x3
    ctx->r8 = ADD32(0, -0X3);
    // 0x8007A5D0: beq         $v0, $zero, L_8007A6F4
    if (ctx->r2 == 0) {
        // 0x8007A5D4: addiu       $t1, $zero, -0x2
        ctx->r9 = ADD32(0, -0X2);
            goto L_8007A6F4;
    }
    // 0x8007A5D4: addiu       $t1, $zero, -0x2
    ctx->r9 = ADD32(0, -0X2);
    // 0x8007A5D8: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8007A5DC: nop

    // 0x8007A5E0: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x8007A5E4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007A5E8: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8007A5EC: beq         $at, $zero, L_8007A6F4
    if (ctx->r1 == 0) {
        // 0x8007A5F0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8007A6F4;
    }
    // 0x8007A5F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007A5F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A5F8: addu        $at, $at, $t7
    gpr jr_addend_8007A604 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007A5FC: lw          $t7, 0x7F00($at)
    ctx->r15 = ADD32(ctx->r1, 0X7F00);
    // 0x8007A600: nop

    // 0x8007A604: jr          $t7
    // 0x8007A608: nop

    switch (jr_addend_8007A604 >> 2) {
        case 0: goto L_8007A6F4; break;
        case 1: goto L_8007A698; break;
        case 2: goto L_8007A60C; break;
        case 3: goto L_8007A6F4; break;
        case 4: goto L_8007A6F4; break;
        case 5: goto L_8007A698; break;
        case 6: goto L_8007A698; break;
        default: switch_error(__func__, 0x8007A604, 0x800E7F00);
    }
    // 0x8007A608: nop

L_8007A60C:
    // 0x8007A60C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8007A610: andi        $t2, $a3, 0x2
    ctx->r10 = ctx->r7 & 0X2;
    // 0x8007A614: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x8007A618: beq         $t9, $zero, L_8007A668
    if (ctx->r25 == 0) {
        // 0x8007A61C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8007A668;
    }
    // 0x8007A61C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007A620: beq         $t2, $zero, L_8007A6F4
    if (ctx->r10 == 0) {
        // 0x8007A624: nop
    
            goto L_8007A6F4;
    }
    // 0x8007A624: nop

    // 0x8007A628: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8007A62C: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8007A630: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A634: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8007A638: beq         $t4, $zero, L_8007A648
    if (ctx->r12 == 0) {
        // 0x8007A63C: nop
    
            goto L_8007A648;
    }
    // 0x8007A63C: nop

    // 0x8007A640: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8007A644: and         $v1, $v1, $t1
    ctx->r3 = ctx->r3 & ctx->r9;
L_8007A648:
    // 0x8007A648: lw          $t5, 0x268($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X268);
    // 0x8007A64C: nop

    // 0x8007A650: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8007A654: nop

    // 0x8007A658: bne         $t6, $zero, L_8007A6F4
    if (ctx->r14 != 0) {
        // 0x8007A65C: sw          $t6, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r14;
            goto L_8007A6F4;
    }
    // 0x8007A65C: sw          $t6, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r14;
    // 0x8007A660: b           L_8007A6F4
    // 0x8007A664: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
        goto L_8007A6F4;
    // 0x8007A664: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8007A668:
    // 0x8007A668: bne         $a3, $at, L_8007A6F4
    if (ctx->r7 != ctx->r1) {
        // 0x8007A66C: nop
    
            goto L_8007A6F4;
    }
    // 0x8007A66C: nop

    // 0x8007A670: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8007A674: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8007A678: lw          $t8, 0x268($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X268);
    // 0x8007A67C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8007A680: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8007A684: and         $v1, $a3, $at
    ctx->r3 = ctx->r7 & ctx->r1;
    // 0x8007A688: bne         $t9, $zero, L_8007A6F4
    if (ctx->r25 != 0) {
        // 0x8007A68C: sw          $t9, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r25;
            goto L_8007A6F4;
    }
    // 0x8007A68C: sw          $t9, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r25;
    // 0x8007A690: b           L_8007A6F4
    // 0x8007A694: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
        goto L_8007A6F4;
    // 0x8007A694: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8007A698:
    // 0x8007A698: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8007A69C: andi        $t4, $a3, 0x2
    ctx->r12 = ctx->r7 & 0X2;
    // 0x8007A6A0: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x8007A6A4: beq         $t3, $zero, L_8007A6C4
    if (ctx->r11 == 0) {
        // 0x8007A6A8: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_8007A6C4;
    }
    // 0x8007A6A8: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8007A6AC: beq         $t4, $zero, L_8007A6C4
    if (ctx->r12 == 0) {
        // 0x8007A6B0: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_8007A6C4;
    }
    // 0x8007A6B0: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8007A6B4: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8007A6B8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8007A6BC: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A6C0: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
L_8007A6C4:
    // 0x8007A6C4: beq         $t5, $zero, L_8007A6F4
    if (ctx->r13 == 0) {
        // 0x8007A6C8: andi        $t6, $v1, 0x1
        ctx->r14 = ctx->r3 & 0X1;
            goto L_8007A6F4;
    }
    // 0x8007A6C8: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x8007A6CC: beq         $t6, $zero, L_8007A6F4
    if (ctx->r14 == 0) {
        // 0x8007A6D0: nop
    
            goto L_8007A6F4;
    }
    // 0x8007A6D0: nop

    // 0x8007A6D4: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8007A6D8: lw          $t7, 0x268($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X268);
    // 0x8007A6DC: and         $v1, $v1, $t1
    ctx->r3 = ctx->r3 & ctx->r9;
    // 0x8007A6E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007A6E4: nop

    // 0x8007A6E8: bne         $t8, $zero, L_8007A6F4
    if (ctx->r24 != 0) {
        // 0x8007A6EC: sw          $t8, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r24;
            goto L_8007A6F4;
    }
    // 0x8007A6EC: sw          $t8, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r24;
    // 0x8007A6F0: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8007A6F4:
    // 0x8007A6F4: beq         $v1, $a3, L_8007A708
    if (ctx->r3 == ctx->r7) {
        // 0x8007A6F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007A708;
    }
    // 0x8007A6F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A6FC: b           L_8007A53C
    // 0x8007A700: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8007A53C;
    // 0x8007A700: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8007A704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007A708:
    // 0x8007A708: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007A70C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007A710: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007A714: jr          $ra
    // 0x8007A718: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8007A718: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007A71C: nop

;}
RECOMP_FUNC void static_0_800C7B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B10: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x800C7B14: bne         $t6, $zero, L_800C7BF4
    if (ctx->r14 != 0) {
        // 0x800C7B18: nop
    
            goto L_800C7BF4;
    }
    // 0x800C7B18: nop

    // 0x800C7B1C: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x800C7B20: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C7B24: sb          $t1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r9;
    // 0x800C7B28: blez        $t7, L_800C7BF4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C7B2C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C7BF4;
    }
    // 0x800C7B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C7B30: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C7B34: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800C7B38: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_800C7B3C:
    // 0x800C7B3C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C7B40: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800C7B44: lbu         $t6, 0xE($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XE);
    // 0x800C7B48: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C7B4C: bnel        $t6, $zero, L_800C7BE0
    if (ctx->r14 != 0) {
        // 0x800C7B50: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C7BE0;
    }
    goto skip_0;
    // 0x800C7B50: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_0:
    // 0x800C7B54: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800C7B58: sb          $t1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r9;
    // 0x800C7B5C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C7B60: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C7B64: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x800C7B68: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x800C7B6C: addu        $t6, $t9, $a1
    ctx->r14 = ADD32(ctx->r25, ctx->r5);
    // 0x800C7B70: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C7B74: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800C7B78: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800C7B7C: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x800C7B80: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800C7B84: bnel        $t9, $zero, L_800C7BE0
    if (ctx->r25 != 0) {
        // 0x800C7B88: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C7BE0;
    }
    goto skip_1;
    // 0x800C7B88: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_1:
    // 0x800C7B8C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800C7B90: lbu         $a2, 0x8($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X8);
    // 0x800C7B94: sb          $t1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r9;
    // 0x800C7B98: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800C7B9C: bne         $a2, $zero, L_800C7BC4
    if (ctx->r6 != 0) {
        // 0x800C7BA0: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_800C7BC4;
    }
    // 0x800C7BA0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800C7BA4: lw          $t8, 0x10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X10);
    // 0x800C7BA8: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800C7BAC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C7BB0: beq         $a2, $zero, L_800C7BDC
    if (ctx->r6 == 0) {
        // 0x800C7BB4: sw          $t9, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r25;
            goto L_800C7BDC;
    }
    // 0x800C7BB4: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x800C7BB8: addu        $t6, $a2, $a1
    ctx->r14 = ADD32(ctx->r6, ctx->r5);
    // 0x800C7BBC: b           L_800C7BDC
    // 0x800C7BC0: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
        goto L_800C7BDC;
    // 0x800C7BC0: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
L_800C7BC4:
    // 0x800C7BC4: bnel        $t2, $a2, L_800C7BE0
    if (ctx->r10 != ctx->r6) {
        // 0x800C7BC8: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C7BE0;
    }
    goto skip_2;
    // 0x800C7BC8: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_2:
    // 0x800C7BCC: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800C7BD0: beq         $a2, $zero, L_800C7BDC
    if (ctx->r6 == 0) {
        // 0x800C7BD4: addu        $t7, $a2, $a1
        ctx->r15 = ADD32(ctx->r6, ctx->r5);
            goto L_800C7BDC;
    }
    // 0x800C7BD4: addu        $t7, $a2, $a1
    ctx->r15 = ADD32(ctx->r6, ctx->r5);
    // 0x800C7BD8: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
L_800C7BDC:
    // 0x800C7BDC: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
L_800C7BE0:
    // 0x800C7BE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C7BE4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C7BE8: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7BEC: bnel        $at, $zero, L_800C7B3C
    if (ctx->r1 != 0) {
        // 0x800C7BF0: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_800C7B3C;
    }
    goto skip_3;
    // 0x800C7BF0: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_3:
L_800C7BF4:
    // 0x800C7BF4: jr          $ra
    // 0x800C7BF8: nop

    return;
    // 0x800C7BF8: nop

    // 0x800C7BFC: jr          $ra
    // 0x800C7C00: nop

    return;
    // 0x800C7C00: nop

;}
RECOMP_FUNC void static_0_800C8140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8140: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800C8144: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x800C8148: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C814C: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800C8150: beql        $t6, $zero, L_800C8188
    if (ctx->r14 == 0) {
        // 0x800C8154: lw          $a3, 0x18($a2)
        ctx->r7 = MEM_W(ctx->r6, 0X18);
            goto L_800C8188;
    }
    goto skip_0;
    // 0x800C8154: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
    skip_0:
    // 0x800C8158: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C815C: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800C8160: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x800C8164: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C8168: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C816C: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x800C8170: lbu         $t9, 0x98($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X98);
    // 0x800C8174: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800C8178: sb          $t6, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r14;
    // 0x800C817C: jr          $ra
    // 0x800C8180: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C8180: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C8184: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
L_800C8188:
    // 0x800C8188: addiu       $t0, $zero, 0xFE
    ctx->r8 = ADD32(0, 0XFE);
    // 0x800C818C: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C8190: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C8194: sw          $t8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r24;
    // 0x800C8198: bne         $t0, $v1, L_800C81FC
    if (ctx->r8 != ctx->r3) {
        // 0x800C819C: nop
    
            goto L_800C81FC;
    }
    // 0x800C819C: nop

    // 0x800C81A0: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x800C81A4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C81A8: sw          $t9, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r25;
    // 0x800C81AC: beq         $t0, $a0, L_800C81FC
    if (ctx->r8 == ctx->r4) {
        // 0x800C81B0: addiu       $t6, $t9, 0x1
        ctx->r14 = ADD32(ctx->r25, 0X1);
            goto L_800C81FC;
    }
    // 0x800C81B0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C81B4: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x800C81B8: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x800C81BC: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x800C81C0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C81C4: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x800C81C8: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x800C81CC: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800C81D0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C81D4: addiu       $t9, $t7, -0x4
    ctx->r25 = ADD32(ctx->r15, -0X4);
    // 0x800C81D8: sw          $t9, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r25;
    // 0x800C81DC: sb          $a1, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r5;
    // 0x800C81E0: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x800C81E4: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C81E8: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C81EC: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x800C81F0: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x800C81F4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800C81F8: sb          $t7, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r15;
L_800C81FC:
    // 0x800C81FC: jr          $ra
    // 0x800C8200: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C8200: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void static_0_800C8204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C820C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800C8210: jal         0x800C8140
    // 0x800C8214: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_0_800C8140(rdram, ctx);
        goto after_0;
    // 0x800C8214: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x800C8218: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800C821C: beq         $t6, $zero, L_800C8248
    if (ctx->r14 == 0) {
        // 0x800C8220: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800C8248;
    }
    // 0x800C8220: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800C8224: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
L_800C8228:
    // 0x800C8228: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800C822C: jal         0x800C8140
    // 0x800C8230: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_0_800C8140(rdram, ctx);
        goto after_1;
    // 0x800C8230: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800C8234: sll         $t7, $t1, 7
    ctx->r15 = S32(ctx->r9 << 7);
    // 0x800C8238: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x800C823C: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x800C8240: bne         $t9, $zero, L_800C8228
    if (ctx->r25 != 0) {
        // 0x800C8244: addu        $t1, $t7, $t8
        ctx->r9 = ADD32(ctx->r15, ctx->r24);
            goto L_800C8228;
    }
    // 0x800C8244: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
L_800C8248:
    // 0x800C8248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C824C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8250: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800C8254: jr          $ra
    // 0x800C8258: nop

    return;
    // 0x800C8258: nop

    // 0x800C825C: jr          $ra
    // 0x800C8260: nop

    return;
    // 0x800C8260: nop

;}
RECOMP_FUNC void static_0_800CB1BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
        goto after_0;
    // 0x800CB248: addiu       $a2, $zero, 0x175
    ctx->r6 = ADD32(0, 0X175);
    after_0:
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
        goto after_1;
    // 0x800CB26C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_1:
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
        goto after_2;
    // 0x800CB3B4: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    after_2:
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
        goto after_3;
    // 0x800CB428: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    after_3:
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
        goto after_4;
    // 0x800CB5D0: nop

    after_4:
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
        goto after_5;
    // 0x800CB618: nop

    after_5:
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
RECOMP_FUNC void static_0_800CB834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
;}
RECOMP_FUNC void static_0_800CB9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
RECOMP_FUNC void static_0_800CC020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
        goto after_0;
    // 0x800CC054: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    after_0:
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
RECOMP_FUNC void static_0_800D1C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
        goto after_0;
    // 0x800D1CB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
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
        goto after_1;
    // 0x800D1CF8: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
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
        goto after_2;
    // 0x800D1D2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
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
RECOMP_FUNC void static_0_800D3E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
