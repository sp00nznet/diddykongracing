#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

RECOMP_FUNC void gzip_huft_build(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C67D4: addiu       $sp, $sp, -0x5F8
    ctx->r29 = ADD32(ctx->r29, -0X5F8);
    // 0x800C67D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C67DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C67E0: addiu       $s1, $sp, 0x5B0
    ctx->r17 = ADD32(ctx->r29, 0X5B0);
    // 0x800C67E4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C67E8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C67EC: sw          $a1, 0x5FC($sp)
    MEM_W(0X5FC, ctx->r29) = ctx->r5;
    // 0x800C67F0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800C67F4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800C67F8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C67FC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C6800: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C6804: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C6808: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C680C: sw          $a2, 0x600($sp)
    MEM_W(0X600, ctx->r29) = ctx->r6;
    // 0x800C6810: sw          $a3, 0x604($sp)
    MEM_W(0X604, ctx->r29) = ctx->r7;
    // 0x800C6814: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x800C6818: jal         0x800D0A40
    // 0x800C681C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x800C681C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800C6820: lw          $t6, 0x5FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5FC);
    // 0x800C6824: or          $fp, $s2, $zero
    ctx->r30 = ctx->r18 | 0;
    // 0x800C6828: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x800C682C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800C6830: beq         $v0, $zero, L_800C6868
    if (ctx->r2 == 0) {
        // 0x800C6834: or          $ra, $t6, $zero
        ctx->r31 = ctx->r14 | 0;
            goto L_800C6868;
    }
    // 0x800C6834: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x800C6838: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
L_800C683C:
    // 0x800C683C: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800C6840: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800C6844: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6848: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C684C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C6850: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6854: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C6858: bne         $v1, $ra, L_800C683C
    if (ctx->r3 != ctx->r31) {
        // 0x800C685C: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_800C683C;
    }
    // 0x800C685C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C6860: beq         $ra, $zero, L_800C68F0
    if (ctx->r31 == 0) {
        // 0x800C6864: lw          $t7, 0x5FC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5FC);
            goto L_800C68F0;
    }
    // 0x800C6864: lw          $t7, 0x5FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5FC);
L_800C6868:
    // 0x800C6868: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800C686C: addiu       $ra, $ra, -0x4
    ctx->r31 = ADD32(ctx->r31, -0X4);
    // 0x800C6870: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6874: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C6878: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C687C: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
    // 0x800C6880: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C6884: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C6888: lw          $t7, -0xC($fp)
    ctx->r15 = MEM_W(ctx->r30, -0XC);
    // 0x800C688C: nop

    // 0x800C6890: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6894: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C6898: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C689C: nop

    // 0x800C68A0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C68A4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C68A8: lw          $t7, -0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, -0X8);
    // 0x800C68AC: nop

    // 0x800C68B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C68B4: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C68B8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C68BC: nop

    // 0x800C68C0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C68C4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C68C8: lw          $t7, -0x4($fp)
    ctx->r15 = MEM_W(ctx->r30, -0X4);
    // 0x800C68CC: nop

    // 0x800C68D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C68D4: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C68D8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C68DC: nop

    // 0x800C68E0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C68E4: bne         $ra, $zero, L_800C6868
    if (ctx->r31 != 0) {
        // 0x800C68E8: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_800C6868;
    }
    // 0x800C68E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C68EC: lw          $t7, 0x5FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5FC);
L_800C68F0:
    // 0x800C68F0: lw          $t8, 0x5B0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5B0);
    // 0x800C68F4: lw          $a1, 0x610($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X610);
    // 0x800C68F8: bne         $t7, $t8, L_800C6918
    if (ctx->r15 != ctx->r24) {
        // 0x800C68FC: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800C6918;
    }
    // 0x800C68FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C6900: lw          $a1, 0x610($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X610);
    // 0x800C6904: lw          $s5, 0x60C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60C);
    // 0x800C6908: nop

    // 0x800C690C: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800C6910: b           L_800C6DEC
    // 0x800C6914: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_800C6DEC;
    // 0x800C6914: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800C6918:
    // 0x800C6918: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x800C691C: addiu       $a0, $sp, 0x5B4
    ctx->r4 = ADD32(ctx->r29, 0X5B4);
    // 0x800C6920: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_800C6924:
    // 0x800C6924: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800C6928: nop

    // 0x800C692C: bne         $t9, $zero, L_800C6944
    if (ctx->r25 != 0) {
        // 0x800C6930: sltu        $at, $s0, $a3
        ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
            goto L_800C6944;
    }
    // 0x800C6930: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x800C6934: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C6938: bne         $a3, $v0, L_800C6924
    if (ctx->r7 != ctx->r2) {
        // 0x800C693C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800C6924;
    }
    // 0x800C693C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C6940: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
L_800C6944:
    // 0x800C6944: beq         $at, $zero, L_800C6950
    if (ctx->r1 == 0) {
        // 0x800C6948: or          $s4, $a3, $zero
        ctx->r20 = ctx->r7 | 0;
            goto L_800C6950;
    }
    // 0x800C6948: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800C694C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
L_800C6950:
    // 0x800C6950: addiu       $ra, $zero, 0x10
    ctx->r31 = ADD32(0, 0X10);
    // 0x800C6954: addiu       $v1, $sp, 0x5F0
    ctx->r3 = ADD32(ctx->r29, 0X5F0);
L_800C6958:
    // 0x800C6958: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C695C: nop

    // 0x800C6960: bne         $t6, $zero, L_800C6978
    if (ctx->r14 != 0) {
        // 0x800C6964: sltu        $at, $ra, $s0
        ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
            goto L_800C6978;
    }
    // 0x800C6964: sltu        $at, $ra, $s0
    ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
    // 0x800C6968: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800C696C: bne         $ra, $zero, L_800C6958
    if (ctx->r31 != 0) {
        // 0x800C6970: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800C6958;
    }
    // 0x800C6970: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800C6974: sltu        $at, $ra, $s0
    ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
L_800C6978:
    // 0x800C6978: beq         $at, $zero, L_800C6984
    if (ctx->r1 == 0) {
        // 0x800C697C: sw          $ra, 0x5A8($sp)
        MEM_W(0X5A8, ctx->r29) = ctx->r31;
            goto L_800C6984;
    }
    // 0x800C697C: sw          $ra, 0x5A8($sp)
    MEM_W(0X5A8, ctx->r29) = ctx->r31;
    // 0x800C6980: or          $s0, $ra, $zero
    ctx->r16 = ctx->r31 | 0;
L_800C6984:
    // 0x800C6984: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C6988: sltu        $at, $a3, $ra
    ctx->r1 = ctx->r7 < ctx->r31 ? 1 : 0;
    // 0x800C698C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x800C6990: beq         $at, $zero, L_800C69C0
    if (ctx->r1 == 0) {
        // 0x800C6994: sllv        $v0, $t7, $a3
        ctx->r2 = S32(ctx->r15 << (ctx->r7 & 31));
            goto L_800C69C0;
    }
    // 0x800C6994: sllv        $v0, $t7, $a3
    ctx->r2 = S32(ctx->r15 << (ctx->r7 & 31));
    // 0x800C6998: sll         $t8, $ra, 2
    ctx->r24 = S32(ctx->r31 << 2);
    // 0x800C699C: addiu       $t9, $sp, 0x5B0
    ctx->r25 = ADD32(ctx->r29, 0X5B0);
    // 0x800C69A0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
L_800C69A4:
    // 0x800C69A4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C69A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C69AC: subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // 0x800C69B0: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800C69B4: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x800C69B8: bne         $at, $zero, L_800C69A4
    if (ctx->r1 != 0) {
        // 0x800C69BC: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800C69A4;
    }
    // 0x800C69BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800C69C0:
    // 0x800C69C0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800C69C4: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800C69C8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800C69CC: addu        $t8, $a0, $v0
    ctx->r24 = ADD32(ctx->r4, ctx->r2);
    // 0x800C69D0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C69D4: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800C69D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C69DC: addiu       $fp, $sp, 0x5B4
    ctx->r30 = ADD32(ctx->r29, 0X5B4);
    // 0x800C69E0: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x800C69E4: beq         $ra, $zero, L_800C6A74
    if (ctx->r31 == 0) {
        // 0x800C69E8: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800C6A74;
    }
    // 0x800C69E8: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800C69EC: andi        $a1, $ra, 0x3
    ctx->r5 = ctx->r31 & 0X3;
    // 0x800C69F0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800C69F4: beq         $a1, $zero, L_800C6A2C
    if (ctx->r5 == 0) {
        // 0x800C69F8: addu        $v0, $a1, $ra
        ctx->r2 = ADD32(ctx->r5, ctx->r31);
            goto L_800C6A2C;
    }
    // 0x800C69F8: addu        $v0, $a1, $ra
    ctx->r2 = ADD32(ctx->r5, ctx->r31);
    // 0x800C69FC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800C6A00: addiu       $t6, $sp, 0x5B0
    ctx->r14 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6A04: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
L_800C6A08:
    // 0x800C6A08: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800C6A0C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800C6A10: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C6A14: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x800C6A18: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800C6A1C: bne         $a0, $v1, L_800C6A08
    if (ctx->r4 != ctx->r3) {
        // 0x800C6A20: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_800C6A08;
    }
    // 0x800C6A20: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6A24: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6A28: beq         $v1, $t8, L_800C6A74
    if (ctx->r3 == ctx->r24) {
        // 0x800C6A2C: addiu       $v0, $sp, 0x5B0
        ctx->r2 = ADD32(ctx->r29, 0X5B0);
            goto L_800C6A74;
    }
L_800C6A2C:
    // 0x800C6A2C: addiu       $v0, $sp, 0x5B0
    ctx->r2 = ADD32(ctx->r29, 0X5B0);
L_800C6A30:
    // 0x800C6A30: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800C6A34: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x800C6A38: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x800C6A3C: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x800C6A40: lw          $t6, 0x4($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X4);
    // 0x800C6A44: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800C6A48: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x800C6A4C: sw          $a3, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->r7;
    // 0x800C6A50: lw          $t7, 0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X8);
    // 0x800C6A54: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
    // 0x800C6A58: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C6A5C: sw          $a3, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->r7;
    // 0x800C6A60: lw          $t8, -0x4($fp)
    ctx->r24 = MEM_W(ctx->r30, -0X4);
    // 0x800C6A64: nop

    // 0x800C6A68: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x800C6A6C: bne         $v1, $v0, L_800C6A30
    if (ctx->r3 != ctx->r2) {
        // 0x800C6A70: sw          $a3, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r7;
            goto L_800C6A30;
    }
    // 0x800C6A70: sw          $a3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r7;
L_800C6A74:
    // 0x800C6A74: or          $fp, $s2, $zero
    ctx->r30 = ctx->r18 | 0;
    // 0x800C6A78: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800C6A7C: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x800C6A80: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
L_800C6A84:
    // 0x800C6A84: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
    // 0x800C6A88: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6A8C: beq         $a3, $zero, L_800C6AB4
    if (ctx->r7 == 0) {
        // 0x800C6A90: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_800C6AB4;
    }
    // 0x800C6A90: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x800C6A94: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x800C6A98: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800C6A9C: nop

    // 0x800C6AA0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800C6AA4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800C6AA8: sw          $ra, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r31;
    // 0x800C6AAC: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800C6AB0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800C6AB4:
    // 0x800C6AB4: lw          $t9, 0x5FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5FC);
    // 0x800C6AB8: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800C6ABC: sltu        $at, $ra, $t9
    ctx->r1 = ctx->r31 < ctx->r25 ? 1 : 0;
    // 0x800C6AC0: bne         $at, $zero, L_800C6A84
    if (ctx->r1 != 0) {
        // 0x800C6AC4: nop
    
            goto L_800C6A84;
    }
    // 0x800C6AC4: nop

    // 0x800C6AC8: lw          $t6, 0x5A8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5A8);
    // 0x800C6ACC: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800C6AD0: slt         $at, $t6, $s4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6AD4: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x800C6AD8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800C6ADC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800C6AE0: negu        $t2, $s0
    ctx->r10 = SUB32(0, ctx->r16);
    // 0x800C6AE4: sw          $zero, 0x544($sp)
    MEM_W(0X544, ctx->r29) = 0;
    // 0x800C6AE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C6AEC: bne         $at, $zero, L_800C6DEC
    if (ctx->r1 != 0) {
        // 0x800C6AF0: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800C6DEC;
    }
    // 0x800C6AF0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800C6AF4: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x800C6AF8: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6AFC: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800C6B00: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C6B04: lw          $s5, 0x60C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60C);
    // 0x800C6B08: addiu       $s2, $s2, -0x4F68
    ctx->r18 = ADD32(ctx->r18, -0X4F68);
    // 0x800C6B0C: addiu       $s7, $s7, 0x3CF0
    ctx->r23 = ADD32(ctx->r23, 0X3CF0);
    // 0x800C6B10: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800C6B14: addiu       $s3, $sp, 0x584
    ctx->r19 = ADD32(ctx->r29, 0X584);
L_800C6B18:
    // 0x800C6B18: lw          $s6, 0x0($v0)
    ctx->r22 = MEM_W(ctx->r2, 0X0);
    // 0x800C6B1C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C6B20: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800C6B24: beq         $s6, $zero, L_800C6DD4
    if (ctx->r22 == 0) {
        // 0x800C6B28: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800C6DD4;
    }
    // 0x800C6B28: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800C6B2C: lw          $t6, 0x5FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5FC);
    // 0x800C6B30: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x800C6B34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C6B38: addu        $t3, $t5, $t9
    ctx->r11 = ADD32(ctx->r13, ctx->r25);
    // 0x800C6B3C: addiu       $t8, $sp, 0xC4
    ctx->r24 = ADD32(ctx->r29, 0XC4);
    // 0x800C6B40: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C6B44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C6B48: addiu       $t6, $s4, 0x1F
    ctx->r14 = ADD32(ctx->r20, 0X1F);
    // 0x800C6B4C: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x800C6B50: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800C6B54: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800C6B58: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
L_800C6B5C:
    // 0x800C6B5C: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x800C6B60: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6B64: beq         $at, $zero, L_800C6C84
    if (ctx->r1 == 0) {
        // 0x800C6B68: addiu       $s1, $s6, 0x1
        ctx->r17 = ADD32(ctx->r22, 0X1);
            goto L_800C6C84;
    }
    // 0x800C6B68: addiu       $s1, $s6, 0x1
    ctx->r17 = ADD32(ctx->r22, 0X1);
    // 0x800C6B6C: addiu       $t9, $sp, 0x544
    ctx->r25 = ADD32(ctx->r29, 0X544);
    // 0x800C6B70: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x800C6B74: lw          $t7, 0x5A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5A8);
L_800C6B78:
    // 0x800C6B78: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C6B7C: subu        $t0, $t7, $v1
    ctx->r8 = SUB32(ctx->r15, ctx->r3);
    // 0x800C6B80: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x800C6B84: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x800C6B88: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800C6B8C: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800C6B90: beq         $at, $zero, L_800C6B9C
    if (ctx->r1 == 0) {
        // 0x800C6B94: or          $t2, $v1, $zero
        ctx->r10 = ctx->r3 | 0;
            goto L_800C6B9C;
    }
    // 0x800C6B94: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x800C6B98: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
L_800C6B9C:
    // 0x800C6B9C: subu        $v0, $s4, $t2
    ctx->r2 = SUB32(ctx->r20, ctx->r10);
    // 0x800C6BA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C6BA4: sllv        $a0, $t6, $v0
    ctx->r4 = S32(ctx->r14 << (ctx->r2 & 31));
    // 0x800C6BA8: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x800C6BAC: beq         $at, $zero, L_800C6BF8
    if (ctx->r1 == 0) {
        // 0x800C6BB0: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800C6BF8;
    }
    // 0x800C6BB0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800C6BB4: addiu       $a3, $v0, 0x1
    ctx->r7 = ADD32(ctx->r2, 0X1);
    // 0x800C6BB8: subu        $v1, $a0, $s6
    ctx->r3 = SUB32(ctx->r4, ctx->r22);
    // 0x800C6BBC: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x800C6BC0: addiu       $t9, $sp, 0x5B0
    ctx->r25 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6BC4: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6BC8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800C6BCC: beq         $at, $zero, L_800C6BF8
    if (ctx->r1 == 0) {
        // 0x800C6BD0: addu        $a2, $t8, $t9
        ctx->r6 = ADD32(ctx->r24, ctx->r25);
            goto L_800C6BF8;
    }
    // 0x800C6BD0: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
L_800C6BD4:
    // 0x800C6BD4: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800C6BD8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C6BDC: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800C6BE0: beq         $at, $zero, L_800C6BF8
    if (ctx->r1 == 0) {
        // 0x800C6BE4: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C6BF8;
    }
    // 0x800C6BE4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800C6BE8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C6BEC: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6BF0: bne         $at, $zero, L_800C6BD4
    if (ctx->r1 != 0) {
        // 0x800C6BF4: subu        $v1, $v0, $a0
        ctx->r3 = SUB32(ctx->r2, ctx->r4);
            goto L_800C6BD4;
    }
    // 0x800C6BF4: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
L_800C6BF8:
    // 0x800C6BF8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800C6BFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C6C00: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800C6C04: sllv        $t0, $t7, $a3
    ctx->r8 = S32(ctx->r15 << (ctx->r7 & 31));
    // 0x800C6C08: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800C6C0C: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x800C6C10: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800C6C14: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    // 0x800C6C18: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800C6C1C: addiu       $a0, $a2, 0x8
    ctx->r4 = ADD32(ctx->r6, 0X8);
    // 0x800C6C20: sw          $a0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r4;
    // 0x800C6C24: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800C6C28: addiu       $s5, $a2, 0x4
    ctx->r21 = ADD32(ctx->r6, 0X4);
    // 0x800C6C2C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C6C30: beq         $t4, $zero, L_800C6C74
    if (ctx->r12 == 0) {
        // 0x800C6C34: sw          $a0, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r4;
            goto L_800C6C74;
    }
    // 0x800C6C34: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x800C6C38: sw          $ra, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r31;
    // 0x800C6C3C: addiu       $t6, $a3, 0x10
    ctx->r14 = ADD32(ctx->r7, 0X10);
    // 0x800C6C40: sb          $t6, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r14;
    // 0x800C6C44: sb          $s0, 0x585($sp)
    MEM_B(0X585, ctx->r29) = ctx->r16;
    // 0x800C6C48: sw          $a0, 0x588($sp)
    MEM_W(0X588, ctx->r29) = ctx->r4;
    // 0x800C6C4C: subu        $t9, $t2, $s0
    ctx->r25 = SUB32(ctx->r10, ctx->r16);
    // 0x800C6C50: lw          $t8, -0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, -0X4);
    // 0x800C6C54: srlv        $t7, $ra, $t9
    ctx->r15 = S32(U32(ctx->r31) >> (ctx->r25 & 31));
    // 0x800C6C58: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x800C6C5C: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800C6C60: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800C6C64: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x800C6C68: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x800C6C6C: nop

    // 0x800C6C70: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
L_800C6C74:
    // 0x800C6C74: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x800C6C78: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6C7C: bne         $at, $zero, L_800C6B78
    if (ctx->r1 != 0) {
        // 0x800C6C80: lw          $t7, 0x5A8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5A8);
            goto L_800C6B78;
    }
    // 0x800C6C80: lw          $t7, 0x5A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5A8);
L_800C6C84:
    // 0x800C6C84: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800C6C88: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C6C8C: subu        $v1, $s4, $t2
    ctx->r3 = SUB32(ctx->r20, ctx->r10);
    // 0x800C6C90: sllv        $a1, $t8, $t2
    ctx->r5 = S32(ctx->r24 << (ctx->r10 & 31));
    // 0x800C6C94: sltu        $at, $fp, $t7
    ctx->r1 = ctx->r30 < ctx->r15 ? 1 : 0;
    // 0x800C6C98: sb          $v1, 0x585($sp)
    MEM_B(0X585, ctx->r29) = ctx->r3;
    // 0x800C6C9C: bne         $at, $zero, L_800C6CB0
    if (ctx->r1 != 0) {
        // 0x800C6CA0: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800C6CB0;
    }
    // 0x800C6CA0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800C6CA4: addiu       $t9, $zero, 0x63
    ctx->r25 = ADD32(0, 0X63);
    // 0x800C6CA8: b           L_800C6D30
    // 0x800C6CAC: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
        goto L_800C6D30;
    // 0x800C6CAC: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
L_800C6CB0:
    // 0x800C6CB0: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x800C6CB4: lw          $t6, 0x600($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X600);
    // 0x800C6CB8: lw          $a0, 0x600($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X600);
    // 0x800C6CBC: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x800C6CC0: beq         $at, $zero, L_800C6CF0
    if (ctx->r1 == 0) {
        // 0x800C6CC4: sltiu       $at, $v0, 0x100
        ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
            goto L_800C6CF0;
    }
    // 0x800C6CC4: sltiu       $at, $v0, 0x100
    ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
    // 0x800C6CC8: beq         $at, $zero, L_800C6CDC
    if (ctx->r1 == 0) {
        // 0x800C6CCC: addiu       $t7, $zero, 0xF
        ctx->r15 = ADD32(0, 0XF);
            goto L_800C6CDC;
    }
    // 0x800C6CCC: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x800C6CD0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800C6CD4: b           L_800C6CE0
    // 0x800C6CD8: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
        goto L_800C6CE0;
    // 0x800C6CD8: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
L_800C6CDC:
    // 0x800C6CDC: sb          $t7, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r15;
L_800C6CE0:
    // 0x800C6CE0: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800C6CE4: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6CE8: b           L_800C6D30
    // 0x800C6CEC: sh          $t9, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r25;
        goto L_800C6D30;
    // 0x800C6CEC: sh          $t9, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r25;
L_800C6CF0:
    // 0x800C6CF0: lw          $t8, 0x608($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X608);
    // 0x800C6CF4: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800C6CF8: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800C6CFC: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800C6D00: lw          $t6, 0x604($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X604);
    // 0x800C6D04: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
    // 0x800C6D08: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800C6D0C: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6D10: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800C6D14: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800C6D18: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800C6D1C: negu        $t6, $t8
    ctx->r14 = SUB32(0, ctx->r24);
    // 0x800C6D20: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800C6D24: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800C6D28: nop

    // 0x800C6D2C: sh          $t8, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r24;
L_800C6D30:
    // 0x800C6D30: srlv        $a3, $ra, $t2
    ctx->r7 = S32(U32(ctx->r31) >> (ctx->r10 & 31));
    // 0x800C6D34: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6D38: beq         $at, $zero, L_800C6D68
    if (ctx->r1 == 0) {
        // 0x800C6D3C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800C6D68;
    }
    // 0x800C6D3C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C6D40: sllv        $v0, $t9, $v1
    ctx->r2 = S32(ctx->r25 << (ctx->r3 & 31));
L_800C6D44:
    // 0x800C6D44: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x800C6D48: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x800C6D4C: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x800C6D50: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x800C6D54: lw          $t9, 0x4($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X4);
    // 0x800C6D58: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x800C6D5C: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6D60: bne         $at, $zero, L_800C6D44
    if (ctx->r1 != 0) {
        // 0x800C6D64: sw          $t9, 0x4($t7)
        MEM_W(0X4, ctx->r15) = ctx->r25;
            goto L_800C6D44;
    }
    // 0x800C6D64: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
L_800C6D68:
    // 0x800C6D68: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800C6D6C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800C6D70: and         $t6, $ra, $a3
    ctx->r14 = ctx->r31 & ctx->r7;
    // 0x800C6D74: beq         $t6, $zero, L_800C6D8C
    if (ctx->r14 == 0) {
        // 0x800C6D78: srl         $t8, $a3, 1
        ctx->r24 = S32(U32(ctx->r7) >> 1);
            goto L_800C6D8C;
    }
L_800C6D78:
    // 0x800C6D78: srl         $t8, $a3, 1
    ctx->r24 = S32(U32(ctx->r7) >> 1);
    // 0x800C6D7C: xor         $ra, $ra, $a3
    ctx->r31 = ctx->r31 ^ ctx->r7;
    // 0x800C6D80: and         $t7, $ra, $t8
    ctx->r15 = ctx->r31 & ctx->r24;
    // 0x800C6D84: bne         $t7, $zero, L_800C6D78
    if (ctx->r15 != 0) {
        // 0x800C6D88: or          $a3, $t8, $zero
        ctx->r7 = ctx->r24 | 0;
            goto L_800C6D78;
    }
    // 0x800C6D88: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_800C6D8C:
    // 0x800C6D8C: xor         $ra, $ra, $a3
    ctx->r31 = ctx->r31 ^ ctx->r7;
    // 0x800C6D90: and         $t9, $ra, $a1
    ctx->r25 = ctx->r31 & ctx->r5;
    // 0x800C6D94: beq         $t9, $v0, L_800C6DC4
    if (ctx->r25 == ctx->r2) {
        // 0x800C6D98: or          $a1, $s6, $zero
        ctx->r5 = ctx->r22 | 0;
            goto L_800C6DC4;
    }
    // 0x800C6D98: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
L_800C6D9C:
    // 0x800C6D9C: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x800C6DA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C6DA4: sllv        $t8, $t6, $t2
    ctx->r24 = S32(ctx->r14 << (ctx->r10 & 31));
    // 0x800C6DA8: lw          $t6, -0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, -0X4);
    // 0x800C6DAC: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x800C6DB0: and         $t9, $ra, $t7
    ctx->r25 = ctx->r31 & ctx->r15;
    // 0x800C6DB4: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800C6DB8: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
    // 0x800C6DBC: bne         $t9, $t6, L_800C6D9C
    if (ctx->r25 != ctx->r14) {
        // 0x800C6DC0: addiu       $t3, $t3, -0x4
        ctx->r11 = ADD32(ctx->r11, -0X4);
            goto L_800C6D9C;
    }
    // 0x800C6DC0: addiu       $t3, $t3, -0x4
    ctx->r11 = ADD32(ctx->r11, -0X4);
L_800C6DC4:
    // 0x800C6DC4: bne         $s6, $zero, L_800C6B5C
    if (ctx->r22 != 0) {
        // 0x800C6DC8: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800C6B5C;
    }
    // 0x800C6DC8: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800C6DCC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800C6DD0: nop

L_800C6DD4:
    // 0x800C6DD4: lw          $t8, 0x5A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5A8);
    // 0x800C6DD8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6DDC: slt         $at, $t8, $s4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6DE0: beq         $at, $zero, L_800C6B18
    if (ctx->r1 == 0) {
        // 0x800C6DE4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800C6B18;
    }
    // 0x800C6DE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C6DE8: sw          $s5, 0x60C($sp)
    MEM_W(0X60C, ctx->r29) = ctx->r21;
L_800C6DEC:
    // 0x800C6DEC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C6DF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C6DF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6DF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C6DFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C6E00: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C6E04: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6E08: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C6E0C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800C6E10: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800C6E14: jr          $ra
    // 0x800C6E18: addiu       $sp, $sp, 0x5F8
    ctx->r29 = ADD32(ctx->r29, 0X5F8);
    return;
    // 0x800C6E18: addiu       $sp, $sp, 0x5F8
    ctx->r29 = ADD32(ctx->r29, 0X5F8);
    // 0x800C6E1C: nop

;}
RECOMP_FUNC void gzip_inflate_block(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6E20: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C6E24: lw          $t3, -0x4F6C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4F6C);
    // 0x800C6E28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6E2C: sw          $zero, -0x4F68($at)
    MEM_W(-0X4F68, ctx->r1) = 0;
    // 0x800C6E30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C6E34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C6E38: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800C6E3C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C6E40: sltu        $at, $t3, $t0
    ctx->r1 = ctx->r11 < ctx->r8 ? 1 : 0;
    // 0x800C6E44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C6E48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C6E4C: lw          $t4, 0x3CF8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3CF8);
    // 0x800C6E50: beq         $at, $zero, L_800C6E74
    if (ctx->r1 == 0) {
        // 0x800C6E54: lw          $t2, -0x4F70($t2)
        ctx->r10 = MEM_W(ctx->r10, -0X4F70);
            goto L_800C6E74;
    }
    // 0x800C6E54: lw          $t2, -0x4F70($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4F70);
L_800C6E58:
    // 0x800C6E58: lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X0);
    // 0x800C6E5C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C6E60: sllv        $v0, $v0, $t3
    ctx->r2 = S32(ctx->r2 << (ctx->r11 & 31));
    // 0x800C6E64: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x800C6E68: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6E6C: bne         $at, $zero, L_800C6E58
    if (ctx->r1 != 0) {
        // 0x800C6E70: or          $t2, $t2, $v0
        ctx->r10 = ctx->r10 | ctx->r2;
            goto L_800C6E58;
    }
    // 0x800C6E70: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
L_800C6E74:
    // 0x800C6E74: andi        $s0, $t2, 0x1
    ctx->r16 = ctx->r10 & 0X1;
    // 0x800C6E78: srlv        $t2, $t2, $t0
    ctx->r10 = S32(U32(ctx->r10) >> (ctx->r8 & 31));
    // 0x800C6E7C: sub         $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x800C6E80: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800C6E84: sltu        $at, $t3, $t0
    ctx->r1 = ctx->r11 < ctx->r8 ? 1 : 0;
    // 0x800C6E88: beq         $at, $zero, L_800C6EAC
    if (ctx->r1 == 0) {
        // 0x800C6E8C: nop
    
            goto L_800C6EAC;
    }
    // 0x800C6E8C: nop

L_800C6E90:
    // 0x800C6E90: lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X0);
    // 0x800C6E94: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C6E98: sllv        $v0, $v0, $t3
    ctx->r2 = S32(ctx->r2 << (ctx->r11 & 31));
    // 0x800C6E9C: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x800C6EA0: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6EA4: bne         $at, $zero, L_800C6E90
    if (ctx->r1 != 0) {
        // 0x800C6EA8: or          $t2, $t2, $v0
        ctx->r10 = ctx->r10 | ctx->r2;
            goto L_800C6E90;
    }
    // 0x800C6EA8: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
L_800C6EAC:
    // 0x800C6EAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6EB0: andi        $t1, $t2, 0x3
    ctx->r9 = ctx->r10 & 0X3;
    // 0x800C6EB4: sw          $t4, 0x3CF8($at)
    MEM_W(0X3CF8, ctx->r1) = ctx->r12;
    // 0x800C6EB8: srlv        $t2, $t2, $t0
    ctx->r10 = S32(U32(ctx->r10) >> (ctx->r8 & 31));
    // 0x800C6EBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6EC0: sw          $t2, -0x4F70($at)
    MEM_W(-0X4F70, ctx->r1) = ctx->r10;
    // 0x800C6EC4: sub         $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x800C6EC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6ECC: sw          $t3, -0x4F6C($at)
    MEM_W(-0X4F6C, ctx->r1) = ctx->r11;
    // 0x800C6ED0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C6ED4: beq         $t1, $at, L_800C6F04
    if (ctx->r9 == ctx->r1) {
        // 0x800C6ED8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800C6F04;
    }
    // 0x800C6ED8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C6EDC: beq         $t1, $at, L_800C6EF4
    if (ctx->r9 == ctx->r1) {
        // 0x800C6EE0: nop
    
            goto L_800C6EF4;
    }
    // 0x800C6EE0: nop

    // 0x800C6EE4: jal         0x800C7494
    // 0x800C6EE8: nop

    gzip_inflate_stored(rdram, ctx);
        goto after_0;
    // 0x800C6EE8: nop

    after_0:
    // 0x800C6EEC: j           L_800C6F0C
    // 0x800C6EF0: nop

        goto L_800C6F0C;
    // 0x800C6EF0: nop

L_800C6EF4:
    // 0x800C6EF4: jal         0x800C733C
    // 0x800C6EF8: nop

    gzip_inflate_fixed(rdram, ctx);
        goto after_1;
    // 0x800C6EF8: nop

    after_1:
    // 0x800C6EFC: j           L_800C6F0C
    // 0x800C6F00: nop

        goto L_800C6F0C;
    // 0x800C6F00: nop

L_800C6F04:
    // 0x800C6F04: jal         0x800C6F24
    // 0x800C6F08: nop

    gzip_inflate_dynamic(rdram, ctx);
        goto after_2;
    // 0x800C6F08: nop

    after_2:
L_800C6F0C:
    // 0x800C6F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6F10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C6F14: sub         $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x800C6F18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C6F1C: jr          $ra
    // 0x800C6F20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C6F20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void gzip_inflate_dynamic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6F24: addiu       $sp, $sp, -0x540
    ctx->r29 = ADD32(ctx->r29, -0X540);
    // 0x800C6F28: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800C6F2C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C6F30: lw          $s3, -0x4F6C($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X4F6C);
    // 0x800C6F34: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800C6F38: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800C6F3C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x800C6F40: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800C6F44: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C6F48: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C6F4C: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800C6F50: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800C6F54: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800C6F58: lw          $s4, 0x3CF8($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X3CF8);
    // 0x800C6F5C: beq         $at, $zero, L_800C6F80
    if (ctx->r1 == 0) {
        // 0x800C6F60: lw          $s2, -0x4F70($s2)
        ctx->r18 = MEM_W(ctx->r18, -0X4F70);
            goto L_800C6F80;
    }
    // 0x800C6F60: lw          $s2, -0x4F70($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X4F70);
L_800C6F64:
    // 0x800C6F64: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6F68: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6F6C: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6F70: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6F74: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6F78: bne         $at, $zero, L_800C6F64
    if (ctx->r1 != 0) {
        // 0x800C6F7C: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6F64;
    }
    // 0x800C6F7C: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_800C6F80:
    // 0x800C6F80: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C6F84: andi        $s1, $s2, 0x1F
    ctx->r17 = ctx->r18 & 0X1F;
    // 0x800C6F88: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C6F8C: addiu       $s1, $s1, 0x101
    ctx->r17 = ADD32(ctx->r17, 0X101);
    // 0x800C6F90: beq         $at, $zero, L_800C6FB4
    if (ctx->r1 == 0) {
        // 0x800C6F94: srlv        $s2, $s2, $t0
        ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
            goto L_800C6FB4;
    }
    // 0x800C6F94: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
L_800C6F98:
    // 0x800C6F98: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6F9C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6FA0: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6FA4: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6FA8: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6FAC: bne         $at, $zero, L_800C6F98
    if (ctx->r1 != 0) {
        // 0x800C6FB0: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6F98;
    }
    // 0x800C6FB0: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_800C6FB4:
    // 0x800C6FB4: andi        $s0, $s2, 0x1F
    ctx->r16 = ctx->r18 & 0X1F;
    // 0x800C6FB8: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C6FBC: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C6FC0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800C6FC4: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C6FC8: beq         $at, $zero, L_800C6FEC
    if (ctx->r1 == 0) {
        // 0x800C6FCC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C6FEC;
    }
    // 0x800C6FCC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C6FD0:
    // 0x800C6FD0: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6FD4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6FD8: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6FDC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6FE0: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6FE4: bne         $at, $zero, L_800C6FD0
    if (ctx->r1 != 0) {
        // 0x800C6FE8: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6FD0;
    }
    // 0x800C6FE8: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_800C6FEC:
    // 0x800C6FEC: andi        $t2, $s2, 0xF
    ctx->r10 = ctx->r18 & 0XF;
    // 0x800C6FF0: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800C6FF4: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800C6FF8: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C6FFC: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C7000: or          $t1, $zero, $t2
    ctx->r9 = 0 | ctx->r10;
    // 0x800C7004: addiu       $t9, $t9, -0x66C0
    ctx->r25 = ADD32(ctx->r25, -0X66C0);
    // 0x800C7008: beq         $t2, $zero, L_800C7070
    if (ctx->r10 == 0) {
        // 0x800C700C: addi        $t7, $sp, 0x44
        ctx->r15 = ADD32(ctx->r29, 0X44);
            goto L_800C7070;
    }
    // 0x800C700C: addi        $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
L_800C7010:
    // 0x800C7010: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800C7014: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C7018: beql        $at, $zero, L_800C7040
    if (ctx->r1 == 0) {
        // 0x800C701C: lbu         $v1, 0x0($t9)
        ctx->r3 = MEM_BU(ctx->r25, 0X0);
            goto L_800C7040;
    }
    goto skip_0;
    // 0x800C701C: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    skip_0:
L_800C7020:
    // 0x800C7020: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C7024: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C7028: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C702C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C7030: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C7034: bne         $at, $zero, L_800C7020
    if (ctx->r1 != 0) {
        // 0x800C7038: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C7020;
    }
    // 0x800C7038: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C703C: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
L_800C7040:
    // 0x800C7040: andi        $v0, $s2, 0x7
    ctx->r2 = ctx->r18 & 0X7;
    // 0x800C7044: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800C7048: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C704C: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800C7050: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800C7054: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C7058: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C705C: bne         $t2, $zero, L_800C7010
    if (ctx->r10 != 0) {
        // 0x800C7060: addiu       $t9, $t9, 0x1
        ctx->r25 = ADD32(ctx->r25, 0X1);
            goto L_800C7010;
    }
    // 0x800C7060: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x800C7064: sltiu       $at, $t1, 0x13
    ctx->r1 = ctx->r9 < 0X13 ? 1 : 0;
    // 0x800C7068: beql        $at, $zero, L_800C7094
    if (ctx->r1 == 0) {
        // 0x800C706C: addiu       $t5, $zero, 0x7
        ctx->r13 = ADD32(0, 0X7);
            goto L_800C7094;
    }
    goto skip_1;
    // 0x800C706C: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    skip_1:
L_800C7070:
    // 0x800C7070: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x800C7074: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800C7078: slti        $at, $t1, 0x13
    ctx->r1 = SIGNED(ctx->r9) < 0X13 ? 1 : 0;
    // 0x800C707C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C7080: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800C7084: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800C7088: bne         $at, $zero, L_800C7070
    if (ctx->r1 != 0) {
        // 0x800C708C: addiu       $t9, $t9, 0x1
        ctx->r25 = ADD32(ctx->r25, 0X1);
            goto L_800C7070;
    }
    // 0x800C708C: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x800C7090: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
L_800C7094:
    // 0x800C7094: addi        $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x800C7098: addi        $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x800C709C: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800C70A0: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C70A4: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x800C70A8: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x800C70AC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800C70B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C70B4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800C70B8: jal         0x800C67D4
    // 0x800C70BC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    gzip_huft_build(rdram, ctx);
        goto after_0;
    // 0x800C70BC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_0:
    // 0x800C70C0: addi        $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x800C70C4: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800C70C8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C70CC: addiu       $v0, $v0, -0x65F4
    ctx->r2 = ADD32(ctx->r2, -0X65F4);
    // 0x800C70D0: sll         $v1, $t5, 1
    ctx->r3 = S32(ctx->r13 << 1);
    // 0x800C70D4: addi        $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x800C70D8: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C70DC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800C70E0: add         $t9, $s1, $s0
    ctx->r25 = ADD32(ctx->r17, ctx->r16);
    // 0x800C70E4: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800C70E8: addi        $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x800C70EC: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
L_800C70F0:
    // 0x800C70F0: beq         $t9, $zero, L_800C7270
    if (ctx->r25 == 0) {
        // 0x800C70F4: sltu        $at, $s3, $t5
        ctx->r1 = ctx->r19 < ctx->r13 ? 1 : 0;
            goto L_800C7270;
    }
    // 0x800C70F4: sltu        $at, $s3, $t5
    ctx->r1 = ctx->r19 < ctx->r13 ? 1 : 0;
    // 0x800C70F8: beql        $at, $zero, L_800C7120
    if (ctx->r1 == 0) {
        // 0x800C70FC: and         $v0, $s2, $t8
        ctx->r2 = ctx->r18 & ctx->r24;
            goto L_800C7120;
    }
    goto skip_2;
    // 0x800C70FC: and         $v0, $s2, $t8
    ctx->r2 = ctx->r18 & ctx->r24;
    skip_2:
L_800C7100:
    // 0x800C7100: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C7104: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C7108: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C710C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C7110: slt         $at, $s3, $t5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C7114: bne         $at, $zero, L_800C7100
    if (ctx->r1 != 0) {
        // 0x800C7118: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C7100;
    }
    // 0x800C7118: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C711C: and         $v0, $s2, $t8
    ctx->r2 = ctx->r18 & ctx->r24;
L_800C7120:
    // 0x800C7120: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C7124: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x800C7128: lhu         $t0, 0x4($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X4);
    // 0x800C712C: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x800C7130: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800C7134: srlv        $s2, $s2, $v0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r2 & 31));
    // 0x800C7138: bne         $at, $zero, L_800C71AC
    if (ctx->r1 != 0) {
        // 0x800C713C: sub         $s3, $s3, $v0
        ctx->r19 = SUB32(ctx->r19, ctx->r2);
            goto L_800C71AC;
    }
    // 0x800C713C: sub         $s3, $s3, $v0
    ctx->r19 = SUB32(ctx->r19, ctx->r2);
    // 0x800C7140: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800C7144: beq         $t0, $at, L_800C71C0
    if (ctx->r8 == ctx->r1) {
        // 0x800C7148: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_800C71C0;
    }
    // 0x800C7148: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800C714C: beql        $t0, $at, L_800C721C
    if (ctx->r8 == ctx->r1) {
        // 0x800C7150: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_800C721C;
    }
    goto skip_3;
    // 0x800C7150: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    skip_3:
    // 0x800C7154: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800C7158: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C715C: beql        $at, $zero, L_800C7184
    if (ctx->r1 == 0) {
        // 0x800C7160: andi        $t1, $s2, 0x7F
        ctx->r9 = ctx->r18 & 0X7F;
            goto L_800C7184;
    }
    goto skip_4;
    // 0x800C7160: andi        $t1, $s2, 0x7F
    ctx->r9 = ctx->r18 & 0X7F;
    skip_4:
L_800C7164:
    // 0x800C7164: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C7168: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C716C: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C7170: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C7174: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C7178: bne         $at, $zero, L_800C7164
    if (ctx->r1 != 0) {
        // 0x800C717C: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C7164;
    }
    // 0x800C717C: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C7180: andi        $t1, $s2, 0x7F
    ctx->r9 = ctx->r18 & 0X7F;
L_800C7184:
    // 0x800C7184: addiu       $t1, $t1, 0xB
    ctx->r9 = ADD32(ctx->r9, 0XB);
    // 0x800C7188: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C718C: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C7190: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
L_800C7194:
    // 0x800C7194: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800C7198: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800C719C: bne         $t1, $zero, L_800C7194
    if (ctx->r9 != 0) {
        // 0x800C71A0: addiu       $t7, $t7, 0x4
        ctx->r15 = ADD32(ctx->r15, 0X4);
            goto L_800C7194;
    }
    // 0x800C71A0: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C71A4: j           L_800C70F0
    // 0x800C71A8: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
        goto L_800C70F0;
    // 0x800C71A8: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
L_800C71AC:
    // 0x800C71AC: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x800C71B0: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C71B4: addiu       $t9, $t9, -0x1
    ctx->r25 = ADD32(ctx->r25, -0X1);
    // 0x800C71B8: j           L_800C70F0
    // 0x800C71BC: or          $t2, $zero, $t0
    ctx->r10 = 0 | ctx->r8;
        goto L_800C70F0;
    // 0x800C71BC: or          $t2, $zero, $t0
    ctx->r10 = 0 | ctx->r8;
L_800C71C0:
    // 0x800C71C0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800C71C4: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C71C8: beql        $at, $zero, L_800C71F0
    if (ctx->r1 == 0) {
        // 0x800C71CC: andi        $t1, $s2, 0x3
        ctx->r9 = ctx->r18 & 0X3;
            goto L_800C71F0;
    }
    goto skip_5;
    // 0x800C71CC: andi        $t1, $s2, 0x3
    ctx->r9 = ctx->r18 & 0X3;
    skip_5:
L_800C71D0:
    // 0x800C71D0: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C71D4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C71D8: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C71DC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C71E0: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C71E4: bne         $at, $zero, L_800C71D0
    if (ctx->r1 != 0) {
        // 0x800C71E8: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C71D0;
    }
    // 0x800C71E8: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C71EC: andi        $t1, $s2, 0x3
    ctx->r9 = ctx->r18 & 0X3;
L_800C71F0:
    // 0x800C71F0: addi        $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x800C71F4: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C71F8: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C71FC: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
L_800C7200:
    // 0x800C7200: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800C7204: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800C7208: bne         $t1, $zero, L_800C7200
    if (ctx->r9 != 0) {
        // 0x800C720C: addiu       $t7, $t7, 0x4
        ctx->r15 = ADD32(ctx->r15, 0X4);
            goto L_800C7200;
    }
    // 0x800C720C: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C7210: j           L_800C70F0
    // 0x800C7214: nop

        goto L_800C70F0;
    // 0x800C7214: nop

    // 0x800C7218: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_800C721C:
    // 0x800C721C: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C7220: beql        $at, $zero, L_800C7248
    if (ctx->r1 == 0) {
        // 0x800C7224: andi        $t1, $s2, 0x7
        ctx->r9 = ctx->r18 & 0X7;
            goto L_800C7248;
    }
    goto skip_6;
    // 0x800C7224: andi        $t1, $s2, 0x7
    ctx->r9 = ctx->r18 & 0X7;
    skip_6:
L_800C7228:
    // 0x800C7228: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C722C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C7230: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C7234: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C7238: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C723C: bne         $at, $zero, L_800C7228
    if (ctx->r1 != 0) {
        // 0x800C7240: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C7228;
    }
    // 0x800C7240: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C7244: andi        $t1, $s2, 0x7
    ctx->r9 = ctx->r18 & 0X7;
L_800C7248:
    // 0x800C7248: addi        $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x800C724C: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C7250: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C7254: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
L_800C7258:
    // 0x800C7258: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800C725C: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800C7260: bne         $t1, $zero, L_800C7258
    if (ctx->r9 != 0) {
        // 0x800C7264: addiu       $t7, $t7, 0x4
        ctx->r15 = ADD32(ctx->r15, 0X4);
            goto L_800C7258;
    }
    // 0x800C7264: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C7268: j           L_800C70F0
    // 0x800C726C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
        goto L_800C70F0;
    // 0x800C726C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
L_800C7270:
    // 0x800C7270: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7274: sw          $s4, 0x3CF8($at)
    MEM_W(0X3CF8, ctx->r1) = ctx->r20;
    // 0x800C7278: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C727C: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x800C7280: sw          $s2, -0x4F70($at)
    MEM_W(-0X4F70, ctx->r1) = ctx->r18;
    // 0x800C7284: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800C7288: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C728C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7290: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800C7294: addiu       $v0, $v0, -0x666E
    ctx->r2 = ADD32(ctx->r2, -0X666E);
    // 0x800C7298: addi        $v1, $sp, 0x34
    ctx->r3 = ADD32(ctx->r29, 0X34);
    // 0x800C729C: addi        $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
    // 0x800C72A0: sw          $s3, -0x4F6C($at)
    MEM_W(-0X4F6C, ctx->r1) = ctx->r19;
    // 0x800C72A4: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C72A8: or          $a1, $zero, $s1
    ctx->r5 = 0 | ctx->r17;
    // 0x800C72AC: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x800C72B0: addiu       $a3, $a3, -0x66AC
    ctx->r7 = ADD32(ctx->r7, -0X66AC);
    // 0x800C72B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C72B8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C72BC: jal         0x800C67D4
    // 0x800C72C0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    gzip_huft_build(rdram, ctx);
        goto after_1;
    // 0x800C72C0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_1:
    // 0x800C72C4: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C72C8: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800C72CC: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800C72D0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C72D4: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800C72D8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C72DC: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800C72E0: addiu       $v0, $v0, -0x6612
    ctx->r2 = ADD32(ctx->r2, -0X6612);
    // 0x800C72E4: addi        $v1, $sp, 0x3C
    ctx->r3 = ADD32(ctx->r29, 0X3C);
    // 0x800C72E8: addi        $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x800C72EC: or          $a1, $zero, $s0
    ctx->r5 = 0 | ctx->r16;
    // 0x800C72F0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C72F4: addiu       $a3, $a3, -0x664E
    ctx->r7 = ADD32(ctx->r7, -0X664E);
    // 0x800C72F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C72FC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C7300: jal         0x800C67D4
    // 0x800C7304: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    gzip_huft_build(rdram, ctx);
        goto after_2;
    // 0x800C7304: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_2:
    // 0x800C7308: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800C730C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800C7310: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800C7314: jal         0x800C75A0
    // 0x800C7318: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    gzip_inflate_codes(rdram, ctx);
        goto after_3;
    // 0x800C7318: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x800C731C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800C7320: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7324: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800C7328: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800C732C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800C7330: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7334: jr          $ra
    // 0x800C7338: addiu       $sp, $sp, 0x540
    ctx->r29 = ADD32(ctx->r29, 0X540);
    return;
    // 0x800C7338: addiu       $sp, $sp, 0x540
    ctx->r29 = ADD32(ctx->r29, 0X540);
;}
RECOMP_FUNC void gzip_inflate_fixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C733C: addiu       $sp, $sp, -0x530
    ctx->r29 = ADD32(ctx->r29, -0X530);
    // 0x800C7340: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7344: addi        $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x800C7348: addiu       $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
    // 0x800C734C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_800C7350:
    // 0x800C7350: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800C7354: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C7358: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C735C: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C7360: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800C7364: bne         $t0, $zero, L_800C7350
    if (ctx->r8 != 0) {
        // 0x800C7368: addiu       $t3, $t3, 0x10
        ctx->r11 = ADD32(ctx->r11, 0X10);
            goto L_800C7350;
    }
    // 0x800C7368: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x800C736C: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x800C7370: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
L_800C7374:
    // 0x800C7374: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800C7378: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C737C: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C7380: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C7384: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800C7388: bne         $t0, $zero, L_800C7374
    if (ctx->r8 != 0) {
        // 0x800C738C: addiu       $t3, $t3, 0x10
        ctx->r11 = ADD32(ctx->r11, 0X10);
            goto L_800C7374;
    }
    // 0x800C738C: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x800C7390: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800C7394: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
L_800C7398:
    // 0x800C7398: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800C739C: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C73A0: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C73A4: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C73A8: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800C73AC: bne         $t0, $zero, L_800C7398
    if (ctx->r8 != 0) {
        // 0x800C73B0: addiu       $t3, $t3, 0x10
        ctx->r11 = ADD32(ctx->r11, 0X10);
            goto L_800C7398;
    }
    // 0x800C73B0: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x800C73B4: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x800C73B8: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C73BC: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C73C0: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C73C4: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800C73C8: sw          $t1, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r9;
    // 0x800C73CC: sw          $t1, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r9;
    // 0x800C73D0: sw          $t1, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r9;
    // 0x800C73D4: sw          $t1, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r9;
    // 0x800C73D8: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800C73DC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800C73E0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C73E4: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800C73E8: addiu       $v0, $v0, -0x666E
    ctx->r2 = ADD32(ctx->r2, -0X666E);
    // 0x800C73EC: addi        $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x800C73F0: addi        $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800C73F4: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C73F8: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    // 0x800C73FC: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x800C7400: addiu       $a3, $a3, -0x66AC
    ctx->r7 = ADD32(ctx->r7, -0X66AC);
    // 0x800C7404: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C7408: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C740C: jal         0x800C67D4
    // 0x800C7410: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    gzip_huft_build(rdram, ctx);
        goto after_0;
    // 0x800C7410: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x800C7414: addi        $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x800C7418: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x800C741C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
L_800C7420:
    // 0x800C7420: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800C7424: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C7428: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C742C: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C7430: bne         $t0, $zero, L_800C7420
    if (ctx->r8 != 0) {
        // 0x800C7434: addiu       $t3, $t3, 0xC
        ctx->r11 = ADD32(ctx->r11, 0XC);
            goto L_800C7420;
    }
    // 0x800C7434: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800C7438: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C743C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800C7440: addiu       $v0, $v0, -0x6612
    ctx->r2 = ADD32(ctx->r2, -0X6612);
    // 0x800C7444: addi        $v1, $sp, 0x28
    ctx->r3 = ADD32(ctx->r29, 0X28);
    // 0x800C7448: addi        $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x800C744C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x800C7450: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C7454: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800C7458: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C745C: addiu       $a3, $a3, -0x664E
    ctx->r7 = ADD32(ctx->r7, -0X664E);
    // 0x800C7460: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C7464: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C7468: jal         0x800C67D4
    // 0x800C746C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    gzip_huft_build(rdram, ctx);
        goto after_1;
    // 0x800C746C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_1:
    // 0x800C7470: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C7474: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800C7478: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C747C: jal         0x800C75A0
    // 0x800C7480: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    gzip_inflate_codes(rdram, ctx);
        goto after_2;
    // 0x800C7480: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800C7484: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7488: addiu       $sp, $sp, 0x530
    ctx->r29 = ADD32(ctx->r29, 0X530);
    // 0x800C748C: jr          $ra
    // 0x800C7490: nop

    return;
    // 0x800C7490: nop

;}
RECOMP_FUNC void gzip_inflate_stored(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7494: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800C7498: lw          $t5, -0x4F6C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4F6C);
    // 0x800C749C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // PATCHED: Validate gzip source pointer (loaded from global 0x800E3CF8)
    // before the copy loop. If source has drifted out of valid 16MB RDRAM,
    // abort this stored block to prevent access violation.
    {
        // Source pointer will be loaded into r15 at line +8 below, but we can
        // pre-read it from the same global:
        uint32_t src_check = (uint32_t)MEM_W(S32(0X800E << 16), 0X3CF8);
        uint32_t dst_check = (uint32_t)MEM_W(S32(0X800E << 16), 0X3CFC);
        if (src_check < 0x80000000u || src_check >= 0x81000000u ||
            dst_check < 0x80000000u || dst_check >= 0x81000000u) {
            static int stored_warn_count = 0;
            if (stored_warn_count < 10) {
                fprintf(stderr, "[GZIP-STORED] WARN #%d: bad ptrs src=0x%08X dst=0x%08X, aborting block\n",
                    ++stored_warn_count, src_check, dst_check);
                fflush(stderr);
            }
            return;
        }
    }
    // 0x800C74A0: lw          $t4, -0x4F70($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4F70);
    // 0x800C74A4: andi        $t0, $t5, 0x7
    ctx->r8 = ctx->r13 & 0X7;
    // 0x800C74A8: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800C74AC: srlv        $t4, $t4, $t0
    ctx->r12 = S32(U32(ctx->r12) >> (ctx->r8 & 31));
    // 0x800C74B0: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800C74B4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800C74B8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C74BC: sltu        $at, $t5, $t0
    ctx->r1 = ctx->r13 < ctx->r8 ? 1 : 0;
    // 0x800C74C0: lw          $t7, 0x3CF8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3CF8);
    // 0x800C74C4: beq         $at, $zero, L_800C74E8
    if (ctx->r1 == 0) {
        // 0x800C74C8: lw          $t6, 0x3CFC($t6)
        ctx->r14 = MEM_W(ctx->r14, 0X3CFC);
            goto L_800C74E8;
    }
    // 0x800C74C8: lw          $t6, 0x3CFC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3CFC);
L_800C74CC:
    // 0x800C74CC: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800C74D0: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C74D4: sllv        $v0, $v0, $t5
    ctx->r2 = S32(ctx->r2 << (ctx->r13 & 31));
    // 0x800C74D8: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x800C74DC: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C74E0: bne         $at, $zero, L_800C74CC
    if (ctx->r1 != 0) {
        // 0x800C74E4: or          $t4, $t4, $v0
        ctx->r12 = ctx->r12 | ctx->r2;
            goto L_800C74CC;
    }
    // 0x800C74E4: or          $t4, $t4, $v0
    ctx->r12 = ctx->r12 | ctx->r2;
L_800C74E8:
    // 0x800C74E8: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800C74EC: andi        $t1, $t4, 0xFFFF
    ctx->r9 = ctx->r12 & 0XFFFF;
    // 0x800C74F0: sltu        $at, $t5, $t0
    ctx->r1 = ctx->r13 < ctx->r8 ? 1 : 0;
    // 0x800C74F4: beq         $at, $zero, L_800C7518
    if (ctx->r1 == 0) {
        // 0x800C74F8: srlv        $t4, $t4, $t0
        ctx->r12 = S32(U32(ctx->r12) >> (ctx->r8 & 31));
            goto L_800C7518;
    }
    // 0x800C74F8: srlv        $t4, $t4, $t0
    ctx->r12 = S32(U32(ctx->r12) >> (ctx->r8 & 31));
L_800C74FC:
    // 0x800C74FC: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800C7500: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C7504: sllv        $v0, $v0, $t5
    ctx->r2 = S32(ctx->r2 << (ctx->r13 & 31));
    // 0x800C7508: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x800C750C: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C7510: bne         $at, $zero, L_800C74FC
    if (ctx->r1 != 0) {
        // 0x800C7514: or          $t4, $t4, $v0
        ctx->r12 = ctx->r12 | ctx->r2;
            goto L_800C74FC;
    }
    // 0x800C7514: or          $t4, $t4, $v0
    ctx->r12 = ctx->r12 | ctx->r2;
L_800C7518:
    // 0x800C7518: andi        $v0, $t1, 0x3
    ctx->r2 = ctx->r9 & 0X3;
    // 0x800C751C: srlv        $t4, $t4, $t0
    ctx->r12 = S32(U32(ctx->r12) >> (ctx->r8 & 31));
    // 0x800C7520: beq         $v0, $zero, L_800C754C
    if (ctx->r2 == 0) {
        // 0x800C7524: sub         $t5, $t5, $t0
        ctx->r13 = SUB32(ctx->r13, ctx->r8);
            goto L_800C754C;
    }
    // 0x800C7524: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800C7528: sub         $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
L_800C752C:
    // 0x800C752C: lbu         $t2, 0x0($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X0);
    // 0x800C7530: addi        $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C7534: addi        $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C7538: addi        $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x800C753C: bne         $v0, $zero, L_800C752C
    if (ctx->r2 != 0) {
        // 0x800C7540: sb          $t2, -0x1($t6)
        MEM_B(-0X1, ctx->r14) = ctx->r10;
            goto L_800C752C;
    }
    // 0x800C7540: sb          $t2, -0x1($t6)
    MEM_B(-0X1, ctx->r14) = ctx->r10;
    // 0x800C7544: beq         $t1, $zero, L_800C757C
    if (ctx->r9 == 0) {
        // 0x800C7548: nop
    
            goto L_800C757C;
    }
    // 0x800C7548: nop

L_800C754C:
    // 0x800C754C: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800C7550: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800C7554: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C7558: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x800C755C: lbu         $v1, -0x3($t7)
    ctx->r3 = MEM_BU(ctx->r15, -0X3);
    // 0x800C7560: addiu       $t6, $t6, 0x4
    ctx->r14 = ADD32(ctx->r14, 0X4);
    // 0x800C7564: sb          $v1, -0x3($t6)
    MEM_B(-0X3, ctx->r14) = ctx->r3;
    // 0x800C7568: lbu         $t2, -0x2($t7)
    ctx->r10 = MEM_BU(ctx->r15, -0X2);
    // 0x800C756C: sb          $t2, -0x2($t6)
    MEM_B(-0X2, ctx->r14) = ctx->r10;
    // 0x800C7570: lbu         $t3, -0x1($t7)
    ctx->r11 = MEM_BU(ctx->r15, -0X1);
    // 0x800C7574: bne         $t1, $zero, L_800C754C
    if (ctx->r9 != 0) {
        // 0x800C7578: sb          $t3, -0x1($t6)
        MEM_B(-0X1, ctx->r14) = ctx->r11;
            goto L_800C754C;
    }
    // 0x800C7578: sb          $t3, -0x1($t6)
    MEM_B(-0X1, ctx->r14) = ctx->r11;
L_800C757C:
    // 0x800C757C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7580: sw          $t7, 0x3CF8($at)
    MEM_W(0X3CF8, ctx->r1) = ctx->r15;
    // 0x800C7584: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7588: sw          $t6, 0x3CFC($at)
    MEM_W(0X3CFC, ctx->r1) = ctx->r14;
    // 0x800C758C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7590: sw          $t4, -0x4F70($at)
    MEM_W(-0X4F70, ctx->r1) = ctx->r12;
    // 0x800C7594: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7598: jr          $ra
    // 0x800C759C: sw          $t5, -0x4F6C($at)
    MEM_W(-0X4F6C, ctx->r1) = ctx->r13;
    return;
    // 0x800C759C: sw          $t5, -0x4F6C($at)
    MEM_W(-0X4F6C, ctx->r1) = ctx->r13;
;}
RECOMP_FUNC void gzip_inflate_codes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // PATCHED: Validate gzip source/dest pointers before Huffman decode loop
    {
        uint32_t src_check = (uint32_t)MEM_W(S32(0X800E << 16), 0X3CF8);
        uint32_t dst_check = (uint32_t)MEM_W(S32(0X800E << 16), 0X3CFC);
        if (src_check < 0x80000000u || src_check >= 0x81000000u ||
            dst_check < 0x80000000u || dst_check >= 0x81000000u) {
            static int codes_warn_count = 0;
            if (codes_warn_count < 10) {
                fprintf(stderr, "[GZIP-CODES] WARN #%d: bad ptrs src=0x%08X dst=0x%08X, aborting\n",
                    ++codes_warn_count, src_check, dst_check);
                fflush(stderr);
            }
            return;
        }
    }
    // 0x800C75A0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C75A4: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C75A8: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x800C75AC: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x800C75B0: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x800C75B4: addiu       $t3, $t3, -0x65F4
    ctx->r11 = ADD32(ctx->r11, -0X65F4);
    // 0x800C75B8: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800C75BC: sll         $t0, $a3, 1
    ctx->r8 = S32(ctx->r7 << 1);
    // 0x800C75C0: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800C75C4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800C75C8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C75CC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C75D0: addu        $v1, $t3, $v0
    ctx->r3 = ADD32(ctx->r11, ctx->r2);
    // 0x800C75D4: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x800C75D8: lw          $s2, 0x3CF8($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X3CF8);
    // 0x800C75DC: lw          $s1, 0x3CFC($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X3CFC);
    // 0x800C75E0: lw          $t9, -0x4F70($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4F70);
    // 0x800C75E4: lw          $s0, -0x4F6C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4F6C);
    // 0x800C75E8: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x800C75EC: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
L_800C75F0:
    // 0x800C75F0: sltu        $at, $s0, $a2
    ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
L_800C75F4:
    // 0x800C75F4: beql        $at, $zero, L_800C761C
    if (ctx->r1 == 0) {
        // 0x800C75F8: and         $v0, $t9, $t5
        ctx->r2 = ctx->r25 & ctx->r13;
            goto L_800C761C;
    }
    goto skip_0;
    // 0x800C75F8: and         $v0, $t9, $t5
    ctx->r2 = ctx->r25 & ctx->r13;
    skip_0:
L_800C75FC:
    // 0x800C75FC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C7600: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C7604: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C7608: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C760C: slt         $at, $s0, $a2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800C7610: bne         $at, $zero, L_800C75FC
    if (ctx->r1 != 0) {
        // 0x800C7614: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C75FC;
    }
    // 0x800C7614: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
    // 0x800C7618: and         $v0, $t9, $t5
    ctx->r2 = ctx->r25 & ctx->r13;
L_800C761C:
    // 0x800C761C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C7620: addu        $t7, $a0, $v0
    ctx->r15 = ADD32(ctx->r4, ctx->r2);
    // 0x800C7624: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C7628: slti        $at, $t8, 0x11
    ctx->r1 = SIGNED(ctx->r24) < 0X11 ? 1 : 0;
    // 0x800C762C: bnel        $at, $zero, L_800C7698
    if (ctx->r1 != 0) {
        // 0x800C7630: lbu         $v0, 0x1($t7)
        ctx->r2 = MEM_BU(ctx->r15, 0X1);
            goto L_800C7698;
    }
    goto skip_1;
    // 0x800C7630: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
    skip_1:
    // 0x800C7634: lb          $v1, 0x1($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X1);
L_800C7638:
    // 0x800C7638: addi        $t8, $t8, -0x10
    ctx->r24 = ADD32(ctx->r24, -0X10);
    // 0x800C763C: sub         $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // 0x800C7640: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800C7644: beq         $at, $zero, L_800C7668
    if (ctx->r1 == 0) {
        // 0x800C7648: srlv        $t9, $t9, $v1
        ctx->r25 = S32(U32(ctx->r25) >> (ctx->r3 & 31));
            goto L_800C7668;
    }
    // 0x800C7648: srlv        $t9, $t9, $v1
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r3 & 31));
L_800C764C:
    // 0x800C764C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C7650: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C7654: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C7658: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C765C: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7660: bne         $at, $zero, L_800C764C
    if (ctx->r1 != 0) {
        // 0x800C7664: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C764C;
    }
    // 0x800C7664: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
L_800C7668:
    // 0x800C7668: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    // 0x800C766C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C7670: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x800C7674: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800C7678: and         $t1, $t1, $t9
    ctx->r9 = ctx->r9 & ctx->r25;
    // 0x800C767C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C7680: add         $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x800C7684: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C7688: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x800C768C: beql        $at, $zero, L_800C7638
    if (ctx->r1 == 0) {
        // 0x800C7690: lb          $v1, 0x1($t7)
        ctx->r3 = MEM_B(ctx->r15, 0X1);
            goto L_800C7638;
    }
    goto skip_2;
    // 0x800C7690: lb          $v1, 0x1($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X1);
    skip_2:
    // 0x800C7694: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
L_800C7698:
    // 0x800C7698: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800C769C: srlv        $t9, $t9, $v0
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r2 & 31));
    // 0x800C76A0: bne         $t8, $at, L_800C76B8
    if (ctx->r24 != ctx->r1) {
        // 0x800C76A4: sub         $s0, $s0, $v0
        ctx->r16 = SUB32(ctx->r16, ctx->r2);
            goto L_800C76B8;
    }
    // 0x800C76A4: sub         $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800C76A8: lhu         $v0, 0x4($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X4);
    // 0x800C76AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C76B0: j           L_800C75F0
    // 0x800C76B4: sb          $v0, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r2;
        goto L_800C75F0;
    // 0x800C76B4: sb          $v0, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r2;
L_800C76B8:
    // 0x800C76B8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800C76BC: beq         $t8, $at, L_800C7860
    if (ctx->r24 == ctx->r1) {
        // 0x800C76C0: sltu        $at, $s0, $t8
        ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
            goto L_800C7860;
    }
    // 0x800C76C0: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800C76C4: beql        $at, $zero, L_800C76EC
    if (ctx->r1 == 0) {
        // 0x800C76C8: sll         $v0, $t8, 1
        ctx->r2 = S32(ctx->r24 << 1);
            goto L_800C76EC;
    }
    goto skip_3;
    // 0x800C76C8: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    skip_3:
L_800C76CC:
    // 0x800C76CC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C76D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C76D4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C76D8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C76DC: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C76E0: bne         $at, $zero, L_800C76CC
    if (ctx->r1 != 0) {
        // 0x800C76E4: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C76CC;
    }
    // 0x800C76E4: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
    // 0x800C76E8: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
L_800C76EC:
    // 0x800C76EC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C76F0: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x800C76F4: lhu         $t0, 0x4($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X4);
    // 0x800C76F8: sub         $s0, $s0, $t8
    ctx->r16 = SUB32(ctx->r16, ctx->r24);
    // 0x800C76FC: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x800C7700: and         $t1, $t1, $t9
    ctx->r9 = ctx->r9 & ctx->r25;
    // 0x800C7704: srlv        $t9, $t9, $t8
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r24 & 31));
    // 0x800C7708: beq         $at, $zero, L_800C772C
    if (ctx->r1 == 0) {
        // 0x800C770C: addu        $t6, $t0, $t1
        ctx->r14 = ADD32(ctx->r8, ctx->r9);
            goto L_800C772C;
    }
    // 0x800C770C: addu        $t6, $t0, $t1
    ctx->r14 = ADD32(ctx->r8, ctx->r9);
L_800C7710:
    // 0x800C7710: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C7714: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C7718: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C771C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C7720: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C7724: bne         $at, $zero, L_800C7710
    if (ctx->r1 != 0) {
        // 0x800C7728: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C7710;
    }
    // 0x800C7728: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
L_800C772C:
    // 0x800C772C: and         $v0, $t4, $t9
    ctx->r2 = ctx->r12 & ctx->r25;
    // 0x800C7730: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C7734: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x800C7738: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C773C: slti        $at, $t8, 0x11
    ctx->r1 = SIGNED(ctx->r24) < 0X11 ? 1 : 0;
    // 0x800C7740: bnel        $at, $zero, L_800C77AC
    if (ctx->r1 != 0) {
        // 0x800C7744: lbu         $v0, 0x1($t7)
        ctx->r2 = MEM_BU(ctx->r15, 0X1);
            goto L_800C77AC;
    }
    goto skip_4;
    // 0x800C7744: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
    skip_4:
    // 0x800C7748: lbu         $t0, 0x1($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X1);
L_800C774C:
    // 0x800C774C: addi        $t8, $t8, -0x10
    ctx->r24 = ADD32(ctx->r24, -0X10);
    // 0x800C7750: sub         $s0, $s0, $t0
    ctx->r16 = SUB32(ctx->r16, ctx->r8);
    // 0x800C7754: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800C7758: beq         $at, $zero, L_800C777C
    if (ctx->r1 == 0) {
        // 0x800C775C: srlv        $t9, $t9, $t0
        ctx->r25 = S32(U32(ctx->r25) >> (ctx->r8 & 31));
            goto L_800C777C;
    }
    // 0x800C775C: srlv        $t9, $t9, $t0
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r8 & 31));
L_800C7760:
    // 0x800C7760: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C7764: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C7768: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C776C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C7770: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7774: bne         $at, $zero, L_800C7760
    if (ctx->r1 != 0) {
        // 0x800C7778: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C7760;
    }
    // 0x800C7778: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
L_800C777C:
    // 0x800C777C: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    // 0x800C7780: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C7784: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x800C7788: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800C778C: and         $t1, $t1, $t9
    ctx->r9 = ctx->r9 & ctx->r25;
    // 0x800C7790: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C7794: addu        $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x800C7798: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C779C: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x800C77A0: beql        $at, $zero, L_800C774C
    if (ctx->r1 == 0) {
        // 0x800C77A4: lbu         $t0, 0x1($t7)
        ctx->r8 = MEM_BU(ctx->r15, 0X1);
            goto L_800C774C;
    }
    goto skip_5;
    // 0x800C77A4: lbu         $t0, 0x1($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X1);
    skip_5:
    // 0x800C77A8: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
L_800C77AC:
    // 0x800C77AC: sub         $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800C77B0: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800C77B4: beq         $at, $zero, L_800C77D8
    if (ctx->r1 == 0) {
        // 0x800C77B8: srlv        $t9, $t9, $v0
        ctx->r25 = S32(U32(ctx->r25) >> (ctx->r2 & 31));
            goto L_800C77D8;
    }
    // 0x800C77B8: srlv        $t9, $t9, $v0
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r2 & 31));
L_800C77BC:
    // 0x800C77BC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C77C0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C77C4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C77C8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C77CC: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C77D0: bne         $at, $zero, L_800C77BC
    if (ctx->r1 != 0) {
        // 0x800C77D4: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C77BC;
    }
    // 0x800C77D4: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
L_800C77D8:
    // 0x800C77D8: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    // 0x800C77DC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C77E0: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x800C77E4: lhu         $v1, 0x4($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X4);
    // 0x800C77E8: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x800C77EC: and         $t1, $t1, $t9
    ctx->r9 = ctx->r9 & ctx->r25;
    // 0x800C77F0: sub         $t0, $s1, $v1
    ctx->r8 = SUB32(ctx->r17, ctx->r3);
    // 0x800C77F4: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x800C77F8: srlv        $t9, $t9, $t8
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r24 & 31));
    // 0x800C77FC: beq         $v0, $zero, L_800C7828
    if (ctx->r2 == 0) {
        // 0x800C7800: sub         $s0, $s0, $t8
        ctx->r16 = SUB32(ctx->r16, ctx->r24);
            goto L_800C7828;
    }
    // 0x800C7800: sub         $s0, $s0, $t8
    ctx->r16 = SUB32(ctx->r16, ctx->r24);
    // 0x800C7804: sub         $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
L_800C7808:
    // 0x800C7808: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x800C780C: addi        $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C7810: addi        $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C7814: addi        $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C7818: bne         $v0, $zero, L_800C7808
    if (ctx->r2 != 0) {
        // 0x800C781C: sb          $t2, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r10;
            goto L_800C7808;
    }
    // 0x800C781C: sb          $t2, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r10;
    // 0x800C7820: beql        $t6, $zero, L_800C75F4
    if (ctx->r14 == 0) {
        // 0x800C7824: sltu        $at, $s0, $a2
        ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
            goto L_800C75F4;
    }
    goto skip_6;
    // 0x800C7824: sltu        $at, $s0, $a2
    ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
    skip_6:
L_800C7828:
    // 0x800C7828: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x800C782C: addiu       $t6, $t6, -0x4
    ctx->r14 = ADD32(ctx->r14, -0X4);
    // 0x800C7830: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800C7834: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x800C7838: lbu         $v1, -0x3($t0)
    ctx->r3 = MEM_BU(ctx->r8, -0X3);
    // 0x800C783C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800C7840: sb          $v1, -0x3($s1)
    MEM_B(-0X3, ctx->r17) = ctx->r3;
    // 0x800C7844: lbu         $t1, -0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, -0X2);
    // 0x800C7848: sb          $t1, -0x2($s1)
    MEM_B(-0X2, ctx->r17) = ctx->r9;
    // 0x800C784C: lbu         $t2, -0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, -0X1);
    // 0x800C7850: bne         $t6, $zero, L_800C7828
    if (ctx->r14 != 0) {
        // 0x800C7854: sb          $t2, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r10;
            goto L_800C7828;
    }
    // 0x800C7854: sb          $t2, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r10;
    // 0x800C7858: j           L_800C75F0
    // 0x800C785C: nop

        goto L_800C75F0;
    // 0x800C785C: nop

L_800C7860:
    // 0x800C7860: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7864: sw          $s2, 0x3CF8($at)
    MEM_W(0X3CF8, ctx->r1) = ctx->r18;
    // 0x800C7868: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C786C: sw          $s1, 0x3CFC($at)
    MEM_W(0X3CFC, ctx->r1) = ctx->r17;
    // 0x800C7870: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7874: sw          $t9, -0x4F70($at)
    MEM_W(-0X4F70, ctx->r1) = ctx->r25;
    // 0x800C7878: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C787C: sw          $s0, -0x4F6C($at)
    MEM_W(-0X4F6C, ctx->r1) = ctx->r16;
    // 0x800C7880: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x800C7884: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x800C7888: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x800C788C: jr          $ra
    // 0x800C7890: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C7890: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800C7894: nop

    // 0x800C7898: nop

    // 0x800C789C: nop

;}
RECOMP_FUNC void bgload_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C78B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C78B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C78B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C78BC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C78C0: addiu       $a1, $a1, -0x4D88
    ctx->r5 = ADD32(ctx->r5, -0X4D88);
    // 0x800C78C4: addiu       $a0, $a0, -0x4DA0
    ctx->r4 = ADD32(ctx->r4, -0X4DA0);
    // 0x800C78C8: jal         0x800C8D80
    // 0x800C78CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800C78CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800C78D0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C78D4: addiu       $t6, $t6, -0x2D80
    ctx->r14 = ADD32(ctx->r14, -0X2D80);
    // 0x800C78D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C78DC: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x800C78E0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800C78E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C78E8: addiu       $a2, $a2, 0x7A00
    ctx->r6 = ADD32(ctx->r6, 0X7A00);
    // 0x800C78EC: addiu       $a0, $a0, -0x4F50
    ctx->r4 = ADD32(ctx->r4, -0X4F50);
    // 0x800C78F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C78F4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800C78F8: jal         0x800C8DB0
    // 0x800C78FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800C78FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800C7900: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C7904: jal         0x800C8F00
    // 0x800C7908: addiu       $a0, $a0, -0x4F50
    ctx->r4 = ADD32(ctx->r4, -0X4F50);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800C7908: addiu       $a0, $a0, -0x4F50
    ctx->r4 = ADD32(ctx->r4, -0X4F50);
    after_2:
    // 0x800C790C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7910: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C7914: jr          $ra
    // 0x800C7918: nop

    return;
    // 0x800C7918: nop

;}
RECOMP_FUNC void bgload_kill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C791C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7924: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C7928: jal         0x800C9050
    // 0x800C792C: addiu       $a0, $a0, -0x4F50
    ctx->r4 = ADD32(ctx->r4, -0X4F50);
    osStopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800C792C: addiu       $a0, $a0, -0x4F50
    ctx->r4 = ADD32(ctx->r4, -0X4F50);
    after_0:
    // 0x800C7930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7938: jr          $ra
    // 0x800C793C: nop

    return;
    // 0x800C793C: nop

;}
RECOMP_FUNC void bgload_active(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7940: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C7944: lw          $v0, 0x3D00($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3D00);
    // 0x800C7948: jr          $ra
    // 0x800C794C: nop

    return;
    // 0x800C794C: nop

;}
RECOMP_FUNC void bgload_tick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7950: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C7954: lw          $t6, 0x3D00($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3D00);
    // 0x800C7958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C795C: beq         $t6, $zero, L_800C7998
    if (ctx->r14 == 0) {
        // 0x800C7960: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C7998;
    }
    // 0x800C7960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7964: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C7968: addiu       $v1, $v1, 0x3D0C
    ctx->r3 = ADD32(ctx->r3, 0X3D0C);
    // 0x800C796C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C7970: nop

    // 0x800C7974: blez        $v0, L_800C7998
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C7978: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800C7998;
    }
    // 0x800C7978: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800C797C: bne         $t7, $zero, L_800C7998
    if (ctx->r15 != 0) {
        // 0x800C7980: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_800C7998;
    }
    // 0x800C7980: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C7984: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C7988: addiu       $a0, $a0, -0x4DA0
    ctx->r4 = ADD32(ctx->r4, -0X4DA0);
    // 0x800C798C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C7990: jal         0x800C9390
    // 0x800C7994: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7994: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_800C7998:
    // 0x800C7998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C799C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C79A0: jr          $ra
    // 0x800C79A4: nop

    return;
    // 0x800C79A4: nop

;}
RECOMP_FUNC void bgload_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79A8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C79AC: lw          $v0, 0x3D0C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3D0C);
    // 0x800C79B0: jr          $ra
    // 0x800C79B4: nop

    return;
    // 0x800C79B4: nop

;}
RECOMP_FUNC void bgload_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79B8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C79BC: addiu       $v1, $v1, 0x3D00
    ctx->r3 = ADD32(ctx->r3, 0X3D00);
    // 0x800C79C0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C79C4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800C79C8: bne         $t6, $zero, L_800C79F4
    if (ctx->r14 != 0) {
        // 0x800C79CC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800C79F4;
    }
    // 0x800C79CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C79D0: sw          $t7, 0x3D0C($at)
    MEM_W(0X3D0C, ctx->r1) = ctx->r15;
    // 0x800C79D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C79D8: sw          $a0, 0x3D04($at)
    MEM_W(0X3D04, ctx->r1) = ctx->r4;
    // 0x800C79DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C79E0: sw          $a1, 0x3D08($at)
    MEM_W(0X3D08, ctx->r1) = ctx->r5;
    // 0x800C79E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C79E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C79EC: jr          $ra
    // 0x800C79F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800C79F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C79F4:
    // 0x800C79F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C79F8: jr          $ra
    // 0x800C79FC: nop

    return;
    // 0x800C79FC: nop

;}
RECOMP_FUNC void thread30_bgload(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C7A04: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800C7A08: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800C7A0C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C7A10: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C7A14: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C7A18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C7A1C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C7A20: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800C7A24: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800C7A28: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800C7A2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C7A30: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C7A34: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800C7A38: addiu       $s5, $s5, 0x3D00
    ctx->r21 = ADD32(ctx->r21, 0X3D00);
    // 0x800C7A3C: addiu       $s4, $s4, 0x3D08
    ctx->r20 = ADD32(ctx->r20, 0X3D08);
    // 0x800C7A40: addiu       $s3, $s3, 0x3D04
    ctx->r19 = ADD32(ctx->r19, 0X3D04);
    // 0x800C7A44: addiu       $s0, $s0, -0x4DA0
    ctx->r16 = ADD32(ctx->r16, -0X4DA0);
    // 0x800C7A48: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x800C7A4C: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_800C7A50:
    // 0x800C7A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C7A54:
    // 0x800C7A54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C7A58: jal         0x800C9110
    // 0x800C7A5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7A5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800C7A60: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800C7A64: nop

    // 0x800C7A68: bne         $t6, $s2, L_800C7A54
    if (ctx->r14 != ctx->r18) {
        // 0x800C7A6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C7A54;
    }
    // 0x800C7A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C7A70: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800C7A74: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x800C7A78: jal         0x8006E528
    // 0x800C7A7C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_level_for_menu(rdram, ctx);
        goto after_1;
    // 0x800C7A7C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800C7A80: b           L_800C7A50
    // 0x800C7A84: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
        goto L_800C7A50;
    // 0x800C7A84: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800C7A88: nop

    // 0x800C7A8C: nop

    // 0x800C7A90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7A94: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C7A98: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C7A9C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7AA0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C7AA4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800C7AA8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800C7AAC: jr          $ra
    // 0x800C7AB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C7AB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C7AB4: nop

    // 0x800C7AB8: nop

    // 0x800C7ABC: nop

;}
RECOMP_FUNC void alHeapInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7AC0: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800C7AC4: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x800C7AC8: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    // 0x800C7ACC: beq         $v1, $v0, L_800C7ADC
    if (ctx->r3 == ctx->r2) {
        // 0x800C7AD0: addu        $t7, $a1, $v0
        ctx->r15 = ADD32(ctx->r5, ctx->r2);
            goto L_800C7ADC;
    }
    // 0x800C7AD0: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x800C7AD4: b           L_800C7AE0
    // 0x800C7AD8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_800C7AE0;
    // 0x800C7AD8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_800C7ADC:
    // 0x800C7ADC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_800C7AE0:
    // 0x800C7AE0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800C7AE4: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800C7AE8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800C7AEC: jr          $ra
    // 0x800C7AF0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    return;
    // 0x800C7AF0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800C7AF4: nop

    // 0x800C7AF8: nop

    // 0x800C7AFC: nop

    // 0x800C7B00: jr          $ra
    // 0x800C7B04: nop

    return;
    // 0x800C7B04: nop

    // 0x800C7B08: jr          $ra
    // 0x800C7B0C: nop

    return;
    // 0x800C7B0C: nop

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
RECOMP_FUNC void alBnkfNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7C04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C7C08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C7C0C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C7C10: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C7C14: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C7C18: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C7C1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C7C20: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800C7C24: addiu       $at, $zero, 0x4231
    ctx->r1 = ADD32(0, 0X4231);
    // 0x800C7C28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C7C2C: bne         $t6, $at, L_800C7CE8
    if (ctx->r14 != ctx->r1) {
        // 0x800C7C30: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_800C7CE8;
    }
    // 0x800C7C30: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C7C34: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x800C7C38: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C7C3C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C7C40: blez        $t7, L_800C7CE8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C7C44: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800C7CE8;
    }
    // 0x800C7C44: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800C7C48: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
L_800C7C4C:
    // 0x800C7C4C: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800C7C50: beq         $t9, $zero, L_800C7CD0
    if (ctx->r25 == 0) {
        // 0x800C7C54: sw          $t9, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r25;
            goto L_800C7CD0;
    }
    // 0x800C7C54: sw          $t9, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r25;
    // 0x800C7C58: lbu         $t6, 0x2($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2);
    // 0x800C7C5C: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800C7C60: bnel        $t6, $zero, L_800C7CD4
    if (ctx->r14 != 0) {
        // 0x800C7C64: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800C7CD4;
    }
    goto skip_0;
    // 0x800C7C64: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x800C7C68: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x800C7C6C: sb          $s4, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r20;
    // 0x800C7C70: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800C7C74: beq         $v0, $zero, L_800C7C8C
    if (ctx->r2 == 0) {
        // 0x800C7C78: addu        $a0, $v0, $s0
        ctx->r4 = ADD32(ctx->r2, ctx->r16);
            goto L_800C7C8C;
    }
    // 0x800C7C78: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x800C7C7C: sw          $a0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r4;
    // 0x800C7C80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C7C84: jal         0x800C7B10
    // 0x800C7C88: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_0_800C7B10(rdram, ctx);
        goto after_0;
    // 0x800C7C88: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
L_800C7C8C:
    // 0x800C7C8C: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x800C7C90: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x800C7C94: blezl       $t8, L_800C7CD4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800C7C98: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800C7CD4;
    }
    goto skip_1;
    // 0x800C7C98: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x800C7C9C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
L_800C7CA0:
    // 0x800C7CA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C7CA4: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x800C7CA8: beq         $a0, $zero, L_800C7CB8
    if (ctx->r4 == 0) {
        // 0x800C7CAC: sw          $a0, 0xC($t3)
        MEM_W(0XC, ctx->r11) = ctx->r4;
            goto L_800C7CB8;
    }
    // 0x800C7CAC: sw          $a0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r4;
    // 0x800C7CB0: jal         0x800C7B10
    // 0x800C7CB4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_0_800C7B10(rdram, ctx);
        goto after_1;
    // 0x800C7CB4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
L_800C7CB8:
    // 0x800C7CB8: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x800C7CBC: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C7CC0: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800C7CC4: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C7CC8: bnel        $at, $zero, L_800C7CA0
    if (ctx->r1 != 0) {
        // 0x800C7CCC: lw          $t9, 0xC($t3)
        ctx->r25 = MEM_W(ctx->r11, 0XC);
            goto L_800C7CA0;
    }
    goto skip_2;
    // 0x800C7CCC: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    skip_2:
L_800C7CD0:
    // 0x800C7CD0: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
L_800C7CD4:
    // 0x800C7CD4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800C7CD8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C7CDC: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7CE0: bnel        $at, $zero, L_800C7C4C
    if (ctx->r1 != 0) {
        // 0x800C7CE4: lw          $t8, 0x4($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X4);
            goto L_800C7C4C;
    }
    goto skip_3;
    // 0x800C7CE4: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    skip_3:
L_800C7CE8:
    // 0x800C7CE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7CEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C7CF0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7CF4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C7CF8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C7CFC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C7D00: jr          $ra
    // 0x800C7D04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C7D04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void alSeqFileNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7D08: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800C7D0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C7D10: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C7D14: blez        $t6, L_800C7D40
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800C7D18: nop
    
            goto L_800C7D40;
    }
    // 0x800C7D18: nop

    // 0x800C7D1C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
L_800C7D20:
    // 0x800C7D20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C7D24: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C7D28: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C7D2C: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x800C7D30: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x800C7D34: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C7D38: bnel        $at, $zero, L_800C7D20
    if (ctx->r1 != 0) {
        // 0x800C7D3C: lw          $t7, 0x4($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X4);
            goto L_800C7D20;
    }
    goto skip_0;
    // 0x800C7D3C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    skip_0:
L_800C7D40:
    // 0x800C7D40: jr          $ra
    // 0x800C7D44: nop

    return;
    // 0x800C7D44: nop

    // 0x800C7D48: nop

    // 0x800C7D4C: nop

;}
RECOMP_FUNC void alHeapDBAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7D50: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800C7D54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C7D58: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C7D5C: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7D60: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800C7D64: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C7D68: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800C7D6C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800C7D70: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C7D74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C7D78: mflo        $v0
    ctx->r2 = lo;
    // 0x800C7D7C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800C7D80: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x800C7D84: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x800C7D88: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x800C7D8C: bne         $at, $zero, L_800C7D9C
    if (ctx->r1 != 0) {
        // 0x800C7D90: addu        $t2, $a0, $t7
        ctx->r10 = ADD32(ctx->r4, ctx->r15);
            goto L_800C7D9C;
    }
    // 0x800C7D90: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x800C7D94: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C7D98: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
L_800C7D9C:
    // 0x800C7D9C: jr          $ra
    // 0x800C7DA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C7DA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C7DA4: nop

    // 0x800C7DA8: nop

    // 0x800C7DAC: nop

;}
RECOMP_FUNC void alCSPSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7DB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7DB8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C7DBC: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800C7DC0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800C7DC4: sh          $t7, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r15;
    // 0x800C7DC8: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x800C7DCC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7DD0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C7DD4: jal         0x800C970C
    // 0x800C7DD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7DD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C7DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7DE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7DE4: jr          $ra
    // 0x800C7DE8: nop

    return;
    // 0x800C7DE8: nop

    // 0x800C7DEC: nop

;}
RECOMP_FUNC void alCSPGetTempo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7DF0: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x800C7DF4: bnel        $v1, $zero, L_800C7E08
    if (ctx->r3 != 0) {
        // 0x800C7DF8: lw          $t6, 0x24($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X24);
            goto L_800C7E08;
    }
    goto skip_0;
    // 0x800C7DF8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    skip_0:
    // 0x800C7DFC: jr          $ra
    // 0x800C7E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C7E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C7E04: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
L_800C7E08:
    // 0x800C7E08: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800C7E0C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800C7E10: nop

    // 0x800C7E14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C7E18: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C7E1C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C7E20: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800C7E24: nop

    // 0x800C7E28: jr          $ra
    // 0x800C7E2C: nop

    return;
    // 0x800C7E2C: nop

;}
RECOMP_FUNC void alCSPSetChlPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7E40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7E44: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C7E48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7E4C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C7E50: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C7E54: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800C7E58: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C7E5C: ori         $t7, $a3, 0xB0
    ctx->r15 = ctx->r7 | 0XB0;
    // 0x800C7E60: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800C7E64: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C7E68: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C7E6C: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x800C7E70: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x800C7E74: sb          $t0, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r8;
    // 0x800C7E78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C7E7C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7E80: jal         0x800C970C
    // 0x800C7E84: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7E84: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x800C7E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7E8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7E90: jr          $ra
    // 0x800C7E94: nop

    return;
    // 0x800C7E94: nop

    // 0x800C7E98: nop

    // 0x800C7E9C: nop

;}
RECOMP_FUNC void alCSPSetChlVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7EA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7EA4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C7EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7EAC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C7EB0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C7EB4: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800C7EB8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C7EBC: ori         $t7, $a3, 0xB0
    ctx->r15 = ctx->r7 | 0XB0;
    // 0x800C7EC0: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x800C7EC4: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C7EC8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C7ECC: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x800C7ED0: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x800C7ED4: sb          $t0, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r8;
    // 0x800C7ED8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C7EDC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7EE0: jal         0x800C970C
    // 0x800C7EE4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7EE4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x800C7EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7EEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7EF0: jr          $ra
    // 0x800C7EF4: nop

    return;
    // 0x800C7EF4: nop

    // 0x800C7EF8: nop

    // 0x800C7EFC: nop

;}
RECOMP_FUNC void alCSPGetChlVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7F00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C7F04: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x800C7F08: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800C7F0C: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800C7F10: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C7F14: jr          $ra
    // 0x800C7F18: lbu         $v0, 0x9($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X9);
    return;
    // 0x800C7F18: lbu         $v0, 0x9($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X9);
    // 0x800C7F1C: nop

;}
RECOMP_FUNC void alSeqpGetChlFXMix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7F20: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C7F24: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x800C7F28: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800C7F2C: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800C7F30: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C7F34: jr          $ra
    // 0x800C7F38: lbu         $v0, 0xA($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0XA);
    return;
    // 0x800C7F38: lbu         $v0, 0xA($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0XA);
    // 0x800C7F3C: nop

;}
RECOMP_FUNC void alCSPSetTempo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7F40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7F44: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800C7F48: and         $t9, $a1, $at
    ctx->r25 = ctx->r5 & ctx->r1;
    // 0x800C7F4C: andi        $t2, $a1, 0xFF00
    ctx->r10 = ctx->r5 & 0XFF00;
    // 0x800C7F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7F54: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x800C7F58: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800C7F5C: addiu       $t8, $zero, 0x51
    ctx->r24 = ADD32(0, 0X51);
    // 0x800C7F60: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800C7F64: sra         $t3, $t2, 8
    ctx->r11 = S32(SIGNED(ctx->r10) >> 8);
    // 0x800C7F68: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
    // 0x800C7F6C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C7F70: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x800C7F74: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x800C7F78: sb          $t1, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r9;
    // 0x800C7F7C: sb          $t3, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r11;
    // 0x800C7F80: sb          $t4, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r12;
    // 0x800C7F84: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7F88: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C7F8C: jal         0x800C970C
    // 0x800C7F90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7F90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C7F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7F9C: jr          $ra
    // 0x800C7FA0: nop

    return;
    // 0x800C7FA0: nop

    // 0x800C7FA4: nop

    // 0x800C7FA8: nop

    // 0x800C7FAC: nop

;}
RECOMP_FUNC void alCSPGetState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7FB0: jr          $ra
    // 0x800C7FB4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    return;
    // 0x800C7FB4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x800C7FB8: nop

    // 0x800C7FBC: nop

;}
RECOMP_FUNC void alCSPSetBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7FC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7FC8: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800C7FCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C7FD0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C7FD4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7FD8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C7FDC: jal         0x800C970C
    // 0x800C7FE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7FE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C7FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7FE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7FEC: jr          $ra
    // 0x800C7FF0: nop

    return;
    // 0x800C7FF0: nop

    // 0x800C7FF4: nop

    // 0x800C7FF8: nop

    // 0x800C7FFC: nop

;}
RECOMP_FUNC void alCSeqGetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8000: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C8004: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C8008: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800C800C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800C8010: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800C8014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C8018: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C801C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800C8020: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x800C8024: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800C8028: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C802C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
L_800C8030:
    // 0x800C8030: lw          $t9, 0x18($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X18);
    // 0x800C8034: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C8038: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C803C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800C8040: lw          $t1, 0x58($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X58);
    // 0x800C8044: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800C8048: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800C804C: sw          $t1, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r9;
    // 0x800C8050: lbu         $t2, 0x98($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X98);
    // 0x800C8054: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800C8058: sb          $t2, 0x8A($a3)
    MEM_B(0X8A, ctx->r7) = ctx->r10;
    // 0x800C805C: lbu         $t3, 0xA6($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XA6);
    // 0x800C8060: sb          $t3, 0x9A($a3)
    MEM_B(0X9A, ctx->r7) = ctx->r11;
    // 0x800C8064: lw          $t4, 0xB0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XB0);
    // 0x800C8068: sw          $t4, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r12;
    // 0x800C806C: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x800C8070: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x800C8074: lw          $t6, 0x54($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X54);
    // 0x800C8078: sw          $t6, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r14;
    // 0x800C807C: lbu         $t7, 0x97($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X97);
    // 0x800C8080: sb          $t7, 0x8B($a3)
    MEM_B(0X8B, ctx->r7) = ctx->r15;
    // 0x800C8084: lbu         $t8, 0xA7($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XA7);
    // 0x800C8088: sb          $t8, 0x9B($a3)
    MEM_B(0X9B, ctx->r7) = ctx->r24;
    // 0x800C808C: lw          $t9, 0xB4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XB4);
    // 0x800C8090: bne         $v0, $a0, L_800C8030
    if (ctx->r2 != ctx->r4) {
        // 0x800C8094: sw          $t9, 0xA8($v1)
        MEM_W(0XA8, ctx->r3) = ctx->r25;
            goto L_800C8030;
    }
    // 0x800C8094: sw          $t9, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r25;
    // 0x800C8098: jr          $ra
    // 0x800C809C: nop

    return;
    // 0x800C809C: nop

;}
RECOMP_FUNC void alCSeqSetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C80A0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800C80A4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C80A8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C80AC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800C80B0: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800C80B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C80B8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C80BC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x800C80C0: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800C80C4: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800C80C8: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x800C80CC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_800C80D0:
    // 0x800C80D0: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x800C80D4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C80D8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C80DC: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800C80E0: lw          $t1, 0x4C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4C);
    // 0x800C80E4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800C80E8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800C80EC: sw          $t1, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r9;
    // 0x800C80F0: lbu         $t2, 0x8C($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X8C);
    // 0x800C80F4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800C80F8: sb          $t2, 0x96($a3)
    MEM_B(0X96, ctx->r7) = ctx->r10;
    // 0x800C80FC: lbu         $t3, 0x9A($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X9A);
    // 0x800C8100: sb          $t3, 0xA6($a3)
    MEM_B(0XA6, ctx->r7) = ctx->r11;
    // 0x800C8104: lw          $t4, 0xA4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XA4);
    // 0x800C8108: sw          $t4, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r12;
    // 0x800C810C: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x800C8110: sw          $t5, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r13;
    // 0x800C8114: lw          $t6, 0x48($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X48);
    // 0x800C8118: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
    // 0x800C811C: lbu         $t7, 0x8B($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X8B);
    // 0x800C8120: sb          $t7, 0x97($a3)
    MEM_B(0X97, ctx->r7) = ctx->r15;
    // 0x800C8124: lbu         $t8, 0x9B($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X9B);
    // 0x800C8128: sb          $t8, 0xA7($a3)
    MEM_B(0XA7, ctx->r7) = ctx->r24;
    // 0x800C812C: lw          $t9, 0xA8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA8);
    // 0x800C8130: bne         $v0, $a0, L_800C80D0
    if (ctx->r2 != ctx->r4) {
        // 0x800C8134: sw          $t9, 0xB4($v1)
        MEM_W(0XB4, ctx->r3) = ctx->r25;
            goto L_800C80D0;
    }
    // 0x800C8134: sw          $t9, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r25;
    // 0x800C8138: jr          $ra
    // 0x800C813C: nop

    return;
    // 0x800C813C: nop

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
RECOMP_FUNC void alCSeqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8264: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C8268: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C826C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C8270: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C8274: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x800C8278: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800C827C: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x800C8280: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800C8284: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800C8288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C828C: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
L_800C8290:
    // 0x800C8290: srlv        $t7, $t6, $v0
    ctx->r15 = S32(U32(ctx->r14) >> (ctx->r2 & 31));
    // 0x800C8294: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C8298: beql        $t8, $zero, L_800C82DC
    if (ctx->r24 == 0) {
        // 0x800C829C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C82DC;
    }
    goto skip_0;
    // 0x800C829C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800C82A0: lw          $t6, 0x14($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X14);
    // 0x800C82A4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800C82A8: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x800C82AC: beql        $t6, $zero, L_800C82C4
    if (ctx->r14 == 0) {
        // 0x800C82B0: lw          $a0, 0xB8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XB8);
            goto L_800C82C4;
    }
    goto skip_1;
    // 0x800C82B0: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
    skip_1:
    // 0x800C82B4: lw          $t7, 0xB8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XB8);
    // 0x800C82B8: subu        $t8, $t7, $a2
    ctx->r24 = SUB32(ctx->r15, ctx->r6);
    // 0x800C82BC: sw          $t8, 0xB8($v1)
    MEM_W(0XB8, ctx->r3) = ctx->r24;
    // 0x800C82C0: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
L_800C82C4:
    // 0x800C82C4: sltu        $at, $a0, $t1
    ctx->r1 = ctx->r4 < ctx->r9 ? 1 : 0;
    // 0x800C82C8: beql        $at, $zero, L_800C82DC
    if (ctx->r1 == 0) {
        // 0x800C82CC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C82DC;
    }
    goto skip_2;
    // 0x800C82CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x800C82D0: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800C82D4: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800C82D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C82DC:
    // 0x800C82DC: bnel        $v0, $a1, L_800C8290
    if (ctx->r2 != ctx->r5) {
        // 0x800C82E0: lw          $t6, 0x4($t4)
        ctx->r14 = MEM_W(ctx->r12, 0X4);
            goto L_800C8290;
    }
    goto skip_3;
    // 0x800C82E0: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    skip_3:
    // 0x800C82E4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C82E8: jal         0x800C8140
    // 0x800C82EC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_0_800C8140(rdram, ctx);
        goto after_0;
    // 0x800C82EC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x800C82F0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C82F4: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x800C82F8: bne         $v0, $at, L_800C8464
    if (ctx->r2 != ctx->r1) {
        // 0x800C82FC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C8464;
    }
    // 0x800C82FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C8300: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C8304: jal         0x800C8140
    // 0x800C8308: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_0_800C8140(rdram, ctx);
        goto after_1;
    // 0x800C8308: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800C830C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800C8310: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x800C8314: bne         $v0, $at, L_800C8368
    if (ctx->r2 != ctx->r1) {
        // 0x800C8318: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C8368;
    }
    // 0x800C8318: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C831C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800C8320: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800C8324: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800C8328: sb          $a2, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r6;
    // 0x800C832C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C8330: jal         0x800C8140
    // 0x800C8334: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_0_800C8140(rdram, ctx);
        goto after_2;
    // 0x800C8334: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_2:
    // 0x800C8338: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x800C833C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C8340: jal         0x800C8140
    // 0x800C8344: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_0_800C8140(rdram, ctx);
        goto after_3;
    // 0x800C8344: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_3:
    // 0x800C8348: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x800C834C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C8350: jal         0x800C8140
    // 0x800C8354: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_0_800C8140(rdram, ctx);
        goto after_4;
    // 0x800C8354: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_4:
    // 0x800C8358: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x800C835C: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C8360: b           L_800C8500
    // 0x800C8364: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
        goto L_800C8500;
    // 0x800C8364: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
L_800C8368:
    // 0x800C8368: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x800C836C: bnel        $v1, $at, L_800C83A8
    if (ctx->r3 != ctx->r1) {
        // 0x800C8370: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800C83A8;
    }
    goto skip_4;
    // 0x800C8370: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_4:
    // 0x800C8374: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x800C8378: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C837C: sllv        $t9, $t8, $t3
    ctx->r25 = S32(ctx->r24 << (ctx->r11 & 31));
    // 0x800C8380: xor         $t6, $t7, $t9
    ctx->r14 = ctx->r15 ^ ctx->r25;
    // 0x800C8384: beq         $t6, $zero, L_800C8398
    if (ctx->r14 == 0) {
        // 0x800C8388: sw          $t6, 0x4($t4)
        MEM_W(0X4, ctx->r12) = ctx->r14;
            goto L_800C8398;
    }
    // 0x800C8388: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800C838C: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x800C8390: b           L_800C8500
    // 0x800C8394: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_800C8500;
    // 0x800C8394: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_800C8398:
    // 0x800C8398: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800C839C: b           L_800C8500
    // 0x800C83A0: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
        goto L_800C8500;
    // 0x800C83A0: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800C83A4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_800C83A8:
    // 0x800C83A8: bne         $v1, $at, L_800C83D8
    if (ctx->r3 != ctx->r1) {
        // 0x800C83AC: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800C83D8;
    }
    // 0x800C83AC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C83B0: jal         0x800C8140
    // 0x800C83B4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_0_800C8140(rdram, ctx);
        goto after_5;
    // 0x800C83B4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_5:
    // 0x800C83B8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C83BC: jal         0x800C8140
    // 0x800C83C0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_0_800C8140(rdram, ctx);
        goto after_6;
    // 0x800C83C0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_6:
    // 0x800C83C4: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C83C8: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x800C83CC: addiu       $t8, $zero, 0x13
    ctx->r24 = ADD32(0, 0X13);
    // 0x800C83D0: b           L_800C8500
    // 0x800C83D4: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_800C8500;
    // 0x800C83D4: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800C83D8:
    // 0x800C83D8: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800C83DC: bne         $v1, $at, L_800C8500
    if (ctx->r3 != ctx->r1) {
        // 0x800C83E0: sll         $t7, $t3, 2
        ctx->r15 = S32(ctx->r11 << 2);
            goto L_800C8500;
    }
    // 0x800C83E0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800C83E4: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x800C83E8: lw          $v0, 0x18($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X18);
    // 0x800C83EC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C83F0: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x800C83F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C83F8: addiu       $t9, $v0, 0x5
    ctx->r25 = ADD32(ctx->r2, 0X5);
    // 0x800C83FC: bne         $a0, $zero, L_800C8410
    if (ctx->r4 != 0) {
        // 0x800C8400: lbu         $a1, -0x1($v0)
        ctx->r5 = MEM_BU(ctx->r2, -0X1);
            goto L_800C8410;
    }
    // 0x800C8400: lbu         $a1, -0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, -0X1);
    // 0x800C8404: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800C8408: b           L_800C8450
    // 0x800C840C: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
        goto L_800C8450;
    // 0x800C840C: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_800C8410:
    // 0x800C8410: beq         $a0, $at, L_800C841C
    if (ctx->r4 == ctx->r1) {
        // 0x800C8414: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800C841C;
    }
    // 0x800C8414: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800C8418: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_800C841C:
    // 0x800C841C: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x800C8420: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x800C8424: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x800C8428: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800C842C: sll         $t8, $v1, 24
    ctx->r24 = S32(ctx->r3 << 24);
    // 0x800C8430: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800C8434: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800C8438: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800C843C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800C8440: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x800C8444: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800C8448: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x800C844C: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_800C8450:
    // 0x800C8450: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C8454: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x800C8458: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x800C845C: b           L_800C8500
    // 0x800C8460: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_800C8500;
    // 0x800C8460: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800C8464:
    // 0x800C8464: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C8468: andi        $t9, $v1, 0x80
    ctx->r25 = ctx->r3 & 0X80;
    // 0x800C846C: beq         $t9, $zero, L_800C8494
    if (ctx->r25 == 0) {
        // 0x800C8470: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_800C8494;
    }
    // 0x800C8470: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x800C8474: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800C8478: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C847C: jal         0x800C8140
    // 0x800C8480: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_0_800C8140(rdram, ctx);
        goto after_7;
    // 0x800C8480: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_7:
    // 0x800C8484: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800C8488: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C848C: b           L_800C84A4
    // 0x800C8490: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
        goto L_800C84A4;
    // 0x800C8490: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
L_800C8494:
    // 0x800C8494: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x800C8498: lbu         $t7, 0xA8($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XA8);
    // 0x800C849C: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800C84A0: sb          $t7, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r15;
L_800C84A4:
    // 0x800C84A4: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x800C84A8: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800C84AC: andi        $t9, $v0, 0xF0
    ctx->r25 = ctx->r2 & 0XF0;
    // 0x800C84B0: beq         $t9, $at, L_800C84FC
    if (ctx->r25 == ctx->r1) {
        // 0x800C84B4: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_800C84FC;
    }
    // 0x800C84B4: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x800C84B8: beq         $t9, $at, L_800C84FC
    if (ctx->r25 == ctx->r1) {
        // 0x800C84BC: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800C84FC;
    }
    // 0x800C84BC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C84C0: jal         0x800C8140
    // 0x800C84C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_0_800C8140(rdram, ctx);
        goto after_8;
    // 0x800C84C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_8:
    // 0x800C84C8: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x800C84CC: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x800C84D0: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    // 0x800C84D4: andi        $t8, $t6, 0xF0
    ctx->r24 = ctx->r14 & 0XF0;
    // 0x800C84D8: bne         $t8, $at, L_800C8500
    if (ctx->r24 != ctx->r1) {
        // 0x800C84DC: or          $t2, $t4, $zero
        ctx->r10 = ctx->r12 | 0;
            goto L_800C8500;
    }
    // 0x800C84DC: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x800C84E0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800C84E4: jal         0x800C8204
    // 0x800C84E8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    static_0_800C8204(rdram, ctx);
        goto after_9;
    // 0x800C84E8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_9:
    // 0x800C84EC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C84F0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800C84F4: b           L_800C8500
    // 0x800C84F8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
        goto L_800C8500;
    // 0x800C84F8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_800C84FC:
    // 0x800C84FC: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
L_800C8500:
    // 0x800C8500: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x800C8504: lw          $t7, 0xC($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC);
    // 0x800C8508: sw          $t1, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r9;
    // 0x800C850C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800C8510: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x800C8514: sw          $t9, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r25;
    // 0x800C8518: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800C851C: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x800C8520: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x800C8524: beql        $t6, $at, L_800C8544
    if (ctx->r14 == ctx->r1) {
        // 0x800C8528: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800C8544;
    }
    goto skip_5;
    // 0x800C8528: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_5:
    // 0x800C852C: jal         0x800C8204
    // 0x800C8530: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    static_0_800C8204(rdram, ctx);
        goto after_10;
    // 0x800C8530: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    after_10:
    // 0x800C8534: lw          $t7, 0xB8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XB8);
    // 0x800C8538: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C853C: sw          $t9, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r25;
    // 0x800C8540: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_800C8544:
    // 0x800C8544: sw          $t6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r14;
    // 0x800C8548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C854C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C8550: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C8554: jr          $ra
    // 0x800C8558: nop

    return;
    // 0x800C8558: nop

;}
RECOMP_FUNC void alCSeqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C855C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C8560: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C8564: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C8568: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C856C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C8570: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C8574: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C8578: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C857C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C8580: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800C8584: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800C8588: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800C858C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800C8590: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800C8594: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800C8598: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C859C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C85A0: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x800C85A4: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800C85A8: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
L_800C85AC:
    // 0x800C85AC: sb          $zero, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = 0;
    // 0x800C85B0: sw          $zero, 0x58($t4)
    MEM_W(0X58, ctx->r12) = 0;
    // 0x800C85B4: sb          $zero, 0x98($s1)
    MEM_B(0X98, ctx->r17) = 0;
    // 0x800C85B8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800C85BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C85C0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800C85C4: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800C85C8: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x800C85CC: beq         $v0, $zero, L_800C85F8
    if (ctx->r2 == 0) {
        // 0x800C85D0: addu        $t6, $s4, $v0
        ctx->r14 = ADD32(ctx->r20, ctx->r2);
            goto L_800C85F8;
    }
    // 0x800C85D0: addu        $t6, $s4, $v0
    ctx->r14 = ADD32(ctx->r20, ctx->r2);
    // 0x800C85D4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800C85D8: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800C85DC: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x800C85E0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800C85E4: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800C85E8: jal         0x800C8204
    // 0x800C85EC: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    static_0_800C8204(rdram, ctx);
        goto after_0;
    // 0x800C85EC: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    after_0:
    // 0x800C85F0: b           L_800C85FC
    // 0x800C85F4: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
        goto L_800C85FC;
    // 0x800C85F4: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
L_800C85F8:
    // 0x800C85F8: sw          $zero, 0x18($t4)
    MEM_W(0X18, ctx->r12) = 0;
L_800C85FC:
    // 0x800C85FC: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800C8600: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C8604: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C8608: bne         $t5, $s3, L_800C85AC
    if (ctx->r13 != ctx->r19) {
        // 0x800C860C: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_800C85AC;
    }
    // 0x800C860C: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x800C8610: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800C8614: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C8618: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800C861C: lw          $t7, 0x40($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X40);
    // 0x800C8620: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C8624: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C8628: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800C862C: bgez        $t7, L_800C8640
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C8630: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800C8640;
    }
    // 0x800C8630: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C8634: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C8638: nop

    // 0x800C863C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800C8640:
    // 0x800C8640: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800C8644: div.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x800C8648: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800C864C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800C8650: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C8654: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C8658: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C865C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C8660: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C8668: jr          $ra
    // 0x800C866C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C866C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void alCSeqNewMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8670: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x800C8674: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C8678: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C867C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C8680: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x800C8684: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C8688: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800C868C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800C8690: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C8694: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C8698: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C869C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800C86A0: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800C86A4: jal         0x800C855C
    // 0x800C86A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    alCSeqNew(rdram, ctx);
        goto after_0;
    // 0x800C86A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800C86AC: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x800C86B0: addiu       $s4, $sp, 0x140
    ctx->r20 = ADD32(ctx->r29, 0X140);
    // 0x800C86B4: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800C86B8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
L_800C86BC:
    // 0x800C86BC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800C86C0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C86C4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C86C8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800C86CC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800C86D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C86D4: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x800C86D8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800C86DC: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
L_800C86E0:
    // 0x800C86E0: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x800C86E4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C86E8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C86EC: sw          $t0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r8;
    // 0x800C86F0: lw          $t1, 0x58($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X58);
    // 0x800C86F4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800C86F8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800C86FC: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x800C8700: lbu         $t2, 0x94($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X94);
    // 0x800C8704: sb          $t2, 0x88($a1)
    MEM_B(0X88, ctx->r5) = ctx->r10;
    // 0x800C8708: lbu         $t3, 0xA4($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA4);
    // 0x800C870C: sb          $t3, 0x98($a1)
    MEM_B(0X98, ctx->r5) = ctx->r11;
    // 0x800C8710: lw          $t4, 0xA8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA8);
    // 0x800C8714: sw          $t4, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r12;
    // 0x800C8718: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800C871C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800C8720: lw          $t6, 0x4C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4C);
    // 0x800C8724: sw          $t6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r14;
    // 0x800C8728: lbu         $t7, 0x95($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X95);
    // 0x800C872C: sb          $t7, 0x89($a1)
    MEM_B(0X89, ctx->r5) = ctx->r15;
    // 0x800C8730: lbu         $t8, 0xA5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA5);
    // 0x800C8734: sb          $t8, 0x99($a1)
    MEM_B(0X99, ctx->r5) = ctx->r24;
    // 0x800C8738: lw          $t9, 0xAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC);
    // 0x800C873C: sw          $t9, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r25;
    // 0x800C8740: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x800C8744: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800C8748: lw          $t1, 0x50($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X50);
    // 0x800C874C: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x800C8750: lbu         $t2, 0x96($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X96);
    // 0x800C8754: sb          $t2, 0x8A($a1)
    MEM_B(0X8A, ctx->r5) = ctx->r10;
    // 0x800C8758: lbu         $t3, 0xA6($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA6);
    // 0x800C875C: sb          $t3, 0x9A($a1)
    MEM_B(0X9A, ctx->r5) = ctx->r11;
    // 0x800C8760: lw          $t4, 0xB0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XB0);
    // 0x800C8764: sw          $t4, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r12;
    // 0x800C8768: lw          $t5, 0x14($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X14);
    // 0x800C876C: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800C8770: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x800C8774: sw          $t6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r14;
    // 0x800C8778: lbu         $t7, 0x97($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X97);
    // 0x800C877C: sb          $t7, 0x8B($a1)
    MEM_B(0X8B, ctx->r5) = ctx->r15;
    // 0x800C8780: lbu         $t8, 0xA7($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA7);
    // 0x800C8784: sb          $t8, 0x9B($a1)
    MEM_B(0X9B, ctx->r5) = ctx->r24;
    // 0x800C8788: lw          $t9, 0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB4);
    // 0x800C878C: bne         $a0, $s0, L_800C86E0
    if (ctx->r4 != ctx->r16) {
        // 0x800C8790: sw          $t9, 0xA8($v0)
        MEM_W(0XA8, ctx->r2) = ctx->r25;
            goto L_800C86E0;
    }
    // 0x800C8790: sw          $t9, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r25;
    // 0x800C8794: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C8798: jal         0x800C8264
    // 0x800C879C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alCSeqNextEvent(rdram, ctx);
        goto after_1;
    // 0x800C879C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x800C87A0: lh          $t0, 0x140($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X140);
    // 0x800C87A4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800C87A8: beq         $t0, $s5, L_800C87B8
    if (ctx->r8 == ctx->r21) {
        // 0x800C87AC: sltu        $at, $t1, $s2
        ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
            goto L_800C87B8;
    }
    // 0x800C87AC: sltu        $at, $t1, $s2
    ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
    // 0x800C87B0: bnel        $at, $zero, L_800C86BC
    if (ctx->r1 != 0) {
        // 0x800C87B4: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_800C86BC;
    }
    goto skip_0;
    // 0x800C87B4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_800C87B8:
    // 0x800C87B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C87BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C87C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C87C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C87C8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C87CC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800C87D0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800C87D4: jr          $ra
    // 0x800C87D8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x800C87D8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void alCSeqGetTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C87DC: jr          $ra
    // 0x800C87E0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x800C87E0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void alCSeqSecToTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C87E4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C87E8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C87EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C87F0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800C87F4: ldc1        $f6, -0x65D0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X65D0);
    // 0x800C87F8: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800C87FC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800C8800: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C8804: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800C8808: bgez        $t7, L_800C8820
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C880C: cvt.d.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
            goto L_800C8820;
    }
    // 0x800C880C: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800C8810: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C8814: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C8818: nop

    // 0x800C881C: add.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f16.d + ctx->f18.d;
L_800C8820:
    // 0x800C8820: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800C8824: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800C8828: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800C882C: bgez        $a2, L_800C8844
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C8830: cvt.d.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
            goto L_800C8844;
    }
    // 0x800C8830: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x800C8834: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C8838: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C883C: nop

    // 0x800C8840: add.d       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f10.d + ctx->f18.d;
L_800C8844:
    // 0x800C8844: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800C8848: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C884C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800C8850: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C8854: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800C8858: nop

    // 0x800C885C: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C8860: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800C8864: nop

    // 0x800C8868: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800C886C: beql        $v0, $zero, L_800C88C8
    if (ctx->r2 == 0) {
        // 0x800C8870: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_800C88C8;
    }
    goto skip_0;
    // 0x800C8870: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x800C8874: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800C8878: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C887C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C8880: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C8884: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x800C8888: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800C888C: nop

    // 0x800C8890: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x800C8894: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800C8898: nop

    // 0x800C889C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800C88A0: bnel        $v0, $zero, L_800C88BC
    if (ctx->r2 != 0) {
        // 0x800C88A4: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_800C88BC;
    }
    goto skip_1;
    // 0x800C88A4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_1:
    // 0x800C88A8: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800C88AC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C88B0: jr          $ra
    // 0x800C88B4: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x800C88B4: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x800C88B8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
L_800C88BC:
    // 0x800C88BC: jr          $ra
    // 0x800C88C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800C88C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C88C4: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_800C88C8:
    // 0x800C88C8: nop

    // 0x800C88CC: bltzl       $v0, L_800C88BC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800C88D0: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_800C88BC;
    }
    goto skip_2;
    // 0x800C88D0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_2:
    // 0x800C88D4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C88D8: jr          $ra
    // 0x800C88DC: nop

    return;
    // 0x800C88DC: nop

;}
RECOMP_FUNC void alCSeqTicksToSec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C88E0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800C88E4: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800C88E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C88EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C88F0: bgez        $a2, L_800C8904
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C88F4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C8904;
    }
    // 0x800C88F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C88F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C88FC: nop

    // 0x800C8900: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800C8904:
    // 0x800C8904: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C8908: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C890C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C8910: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800C8914: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800C8918: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800C891C: bgez        $t7, L_800C8930
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C8920: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C8930;
    }
    // 0x800C8920: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C8924: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C8928: nop

    // 0x800C892C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_800C8930:
    // 0x800C8930: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8934: ldc1        $f18, -0x65C8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X65C8);
    // 0x800C8938: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800C893C: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800C8940: div.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x800C8944: jr          $ra
    // 0x800C8948: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    return;
    // 0x800C8948: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
;}
RECOMP_FUNC void __alCSeqNextDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C894C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C8950: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x800C8954: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800C8958: bne         $t6, $zero, L_800C8968
    if (ctx->r14 != 0) {
        // 0x800C895C: lw          $v0, 0x10($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X10);
            goto L_800C8968;
    }
    // 0x800C895C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800C8960: jr          $ra
    // 0x800C8964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C8964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C8968:
    // 0x800C8968: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C896C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800C8970: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
L_800C8974:
    // 0x800C8974: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x800C8978: srlv        $t7, $a1, $a2
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r6 & 31));
    // 0x800C897C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C8980: beql        $t8, $zero, L_800C89C4
    if (ctx->r24 == 0) {
        // 0x800C8984: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C89C4;
    }
    goto skip_0;
    // 0x800C8984: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_0:
    // 0x800C8988: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C898C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C8990: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C8994: beql        $t3, $zero, L_800C89B0
    if (ctx->r11 == 0) {
        // 0x800C8998: lw          $t0, 0xB8($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XB8);
            goto L_800C89B0;
    }
    goto skip_1;
    // 0x800C8998: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
    skip_1:
    // 0x800C899C: lw          $t4, 0xB8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XB8);
    // 0x800C89A0: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C89A4: sw          $t5, 0xB8($a3)
    MEM_W(0XB8, ctx->r7) = ctx->r13;
    // 0x800C89A8: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800C89AC: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
L_800C89B0:
    // 0x800C89B0: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800C89B4: beql        $at, $zero, L_800C89C4
    if (ctx->r1 == 0) {
        // 0x800C89B8: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C89C4;
    }
    goto skip_2;
    // 0x800C89B8: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_2:
    // 0x800C89BC: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800C89C0: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800C89C4:
    // 0x800C89C4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C89C8: beq         $t8, $zero, L_800C8A08
    if (ctx->r24 == 0) {
        // 0x800C89CC: addiu       $t6, $a2, 0x2
        ctx->r14 = ADD32(ctx->r6, 0X2);
            goto L_800C8A08;
    }
    // 0x800C89CC: addiu       $t6, $a2, 0x2
    ctx->r14 = ADD32(ctx->r6, 0X2);
    // 0x800C89D0: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C89D4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C89D8: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C89DC: beql        $t3, $zero, L_800C89F8
    if (ctx->r11 == 0) {
        // 0x800C89E0: lw          $t0, 0xBC($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XBC);
            goto L_800C89F8;
    }
    goto skip_3;
    // 0x800C89E0: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
    skip_3:
    // 0x800C89E4: lw          $t4, 0xBC($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XBC);
    // 0x800C89E8: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C89EC: sw          $t5, 0xBC($a3)
    MEM_W(0XBC, ctx->r7) = ctx->r13;
    // 0x800C89F0: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800C89F4: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
L_800C89F8:
    // 0x800C89F8: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800C89FC: beql        $at, $zero, L_800C8A0C
    if (ctx->r1 == 0) {
        // 0x800C8A00: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C8A0C;
    }
    goto skip_4;
    // 0x800C8A00: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_4:
    // 0x800C8A04: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800C8A08:
    // 0x800C8A08: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800C8A0C:
    // 0x800C8A0C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C8A10: beq         $t8, $zero, L_800C8A50
    if (ctx->r24 == 0) {
        // 0x800C8A14: addiu       $t6, $a2, 0x3
        ctx->r14 = ADD32(ctx->r6, 0X3);
            goto L_800C8A50;
    }
    // 0x800C8A14: addiu       $t6, $a2, 0x3
    ctx->r14 = ADD32(ctx->r6, 0X3);
    // 0x800C8A18: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C8A1C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C8A20: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C8A24: beql        $t3, $zero, L_800C8A40
    if (ctx->r11 == 0) {
        // 0x800C8A28: lw          $t0, 0xC0($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XC0);
            goto L_800C8A40;
    }
    goto skip_5;
    // 0x800C8A28: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
    skip_5:
    // 0x800C8A2C: lw          $t4, 0xC0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC0);
    // 0x800C8A30: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C8A34: sw          $t5, 0xC0($a3)
    MEM_W(0XC0, ctx->r7) = ctx->r13;
    // 0x800C8A38: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800C8A3C: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
L_800C8A40:
    // 0x800C8A40: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800C8A44: beql        $at, $zero, L_800C8A54
    if (ctx->r1 == 0) {
        // 0x800C8A48: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C8A54;
    }
    goto skip_6;
    // 0x800C8A48: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_6:
    // 0x800C8A4C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800C8A50:
    // 0x800C8A50: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800C8A54:
    // 0x800C8A54: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C8A58: beql        $t8, $zero, L_800C8A98
    if (ctx->r24 == 0) {
        // 0x800C8A5C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C8A98;
    }
    goto skip_7;
    // 0x800C8A5C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_7:
    // 0x800C8A60: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C8A64: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C8A68: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C8A6C: beql        $t3, $zero, L_800C8A84
    if (ctx->r11 == 0) {
        // 0x800C8A70: lw          $a1, 0xC4($a3)
        ctx->r5 = MEM_W(ctx->r7, 0XC4);
            goto L_800C8A84;
    }
    goto skip_8;
    // 0x800C8A70: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
    skip_8:
    // 0x800C8A74: lw          $t4, 0xC4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC4);
    // 0x800C8A78: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C8A7C: sw          $t5, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->r13;
    // 0x800C8A80: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
L_800C8A84:
    // 0x800C8A84: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800C8A88: beql        $at, $zero, L_800C8A98
    if (ctx->r1 == 0) {
        // 0x800C8A8C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C8A98;
    }
    goto skip_9;
    // 0x800C8A8C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_9:
    // 0x800C8A90: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C8A94: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_800C8A98:
    // 0x800C8A98: bnel        $a2, $t2, L_800C8974
    if (ctx->r6 != ctx->r10) {
        // 0x800C8A9C: lw          $a1, 0x4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X4);
            goto L_800C8974;
    }
    goto skip_10;
    // 0x800C8A9C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x800C8AA0: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800C8AA4: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x800C8AA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C8AAC: jr          $ra
    // 0x800C8AB0: nop

    return;
    // 0x800C8AB0: nop

    // 0x800C8AB4: nop

    // 0x800C8AB8: nop

    // 0x800C8ABC: nop

;}
RECOMP_FUNC void alCSPSetSeq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8AC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C8AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8AC8: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x800C8ACC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C8AD0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C8AD4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C8AD8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C8ADC: jal         0x800C970C
    // 0x800C8AE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C8AE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C8AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8AE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C8AEC: jr          $ra
    // 0x800C8AF0: nop

    return;
    // 0x800C8AF0: nop

    // 0x800C8AF4: nop

    // 0x800C8AF8: nop

    // 0x800C8AFC: nop

;}
RECOMP_FUNC void alCSPPlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C8B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8B08: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800C8B0C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C8B10: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C8B14: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C8B18: jal         0x800C970C
    // 0x800C8B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C8B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C8B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8B24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C8B28: jr          $ra
    // 0x800C8B2C: nop

    return;
    // 0x800C8B2C: nop

;}
RECOMP_FUNC void alCSPStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8B30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C8B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8B38: addiu       $t6, $zero, 0x11
    ctx->r14 = ADD32(0, 0X11);
    // 0x800C8B3C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C8B40: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C8B44: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C8B48: jal         0x800C970C
    // 0x800C8B4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C8B4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C8B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8B54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C8B58: jr          $ra
    // 0x800C8B5C: nop

    return;
    // 0x800C8B5C: nop

;}
RECOMP_FUNC void alUnlink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8CC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C8CC4: beql        $v0, $zero, L_800C8CD8
    if (ctx->r2 == 0) {
        // 0x800C8CC8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800C8CD8;
    }
    goto skip_0;
    // 0x800C8CC8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x800C8CCC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C8CD0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800C8CD4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800C8CD8:
    // 0x800C8CD8: beq         $v0, $zero, L_800C8CE8
    if (ctx->r2 == 0) {
        // 0x800C8CDC: nop
    
            goto L_800C8CE8;
    }
    // 0x800C8CDC: nop

    // 0x800C8CE0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800C8CE4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800C8CE8:
    // 0x800C8CE8: jr          $ra
    // 0x800C8CEC: nop

    return;
    // 0x800C8CEC: nop

;}
RECOMP_FUNC void alLink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8CF0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800C8CF4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800C8CF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C8CFC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800C8D00: beq         $v0, $zero, L_800C8D0C
    if (ctx->r2 == 0) {
        // 0x800C8D04: nop
    
            goto L_800C8D0C;
    }
    // 0x800C8D04: nop

    // 0x800C8D08: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_800C8D0C:
    // 0x800C8D0C: jr          $ra
    // 0x800C8D10: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    return;
    // 0x800C8D10: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void alClose(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8D14: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C8D18: lw          $t6, 0x3D10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3D10);
    // 0x800C8D1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8D24: beql        $t6, $zero, L_800C8D40
    if (ctx->r14 == 0) {
        // 0x800C8D28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8D40;
    }
    goto skip_0;
    // 0x800C8D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C8D2C: jal         0x800D31C0
    // 0x800C8D30: nop

    alSynDelete(rdram, ctx);
        goto after_0;
    // 0x800C8D30: nop

    after_0:
    // 0x800C8D34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C8D38: sw          $zero, 0x3D10($at)
    MEM_W(0X3D10, ctx->r1) = 0;
    // 0x800C8D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8D40:
    // 0x800C8D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8D44: jr          $ra
    // 0x800C8D48: nop

    return;
    // 0x800C8D48: nop

;}
RECOMP_FUNC void alInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8D4C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C8D50: addiu       $v0, $v0, 0x3D10
    ctx->r2 = ADD32(ctx->r2, 0X3D10);
    // 0x800C8D54: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C8D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8D60: bnel        $t6, $zero, L_800C8D74
    if (ctx->r14 != 0) {
        // 0x800C8D64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8D74;
    }
    goto skip_0;
    // 0x800C8D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C8D68: jal         0x80065370
    // 0x800C8D6C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    alSynNew(rdram, ctx);
        goto after_0;
    // 0x800C8D6C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_0:
    // 0x800C8D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8D74:
    // 0x800C8D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8D78: jr          $ra
    // 0x800C8D7C: nop

    return;
    // 0x800C8D7C: nop

;}
RECOMP_FUNC void alEvtqFlushType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C95F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C95F4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C95F8: sll         $s3, $a1, 16
    ctx->r19 = S32(ctx->r5 << 16);
    // 0x800C95FC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C9600: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C9604: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800C9608: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C960C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x800C9610: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C9614: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C9618: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800C961C: jal         0x800C9F90
    // 0x800C9620: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9620: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C9624: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800C9628: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x800C962C: beq         $s0, $zero, L_800C9678
    if (ctx->r16 == 0) {
        // 0x800C9630: nop
    
            goto L_800C9678;
    }
    // 0x800C9630: nop

L_800C9634:
    // 0x800C9634: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x800C9638: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800C963C: bne         $s3, $t7, L_800C9670
    if (ctx->r19 != ctx->r15) {
        // 0x800C9640: nop
    
            goto L_800C9670;
    }
    // 0x800C9640: nop

    // 0x800C9644: beq         $s1, $zero, L_800C965C
    if (ctx->r17 == 0) {
        // 0x800C9648: nop
    
            goto L_800C965C;
    }
    // 0x800C9648: nop

    // 0x800C964C: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800C9650: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800C9654: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C9658: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_800C965C:
    // 0x800C965C: jal         0x800C8CC0
    // 0x800C9660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C9660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C9664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9668: jal         0x800C8CF0
    // 0x800C966C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800C966C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_800C9670:
    // 0x800C9670: bne         $s1, $zero, L_800C9634
    if (ctx->r17 != 0) {
        // 0x800C9674: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800C9634;
    }
    // 0x800C9674: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800C9678:
    // 0x800C9678: jal         0x800C9F90
    // 0x800C967C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800C967C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800C9680: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9684: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C9688: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C968C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9690: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C9694: jr          $ra
    // 0x800C9698: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C9698: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void alEvtqFlush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C969C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C96A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C96A4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C96A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C96AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C96B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C96B4: jal         0x800C9F90
    // 0x800C96B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C96B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C96BC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800C96C0: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x800C96C4: beq         $s0, $zero, L_800C96EC
    if (ctx->r16 == 0) {
        // 0x800C96C8: nop
    
            goto L_800C96EC;
    }
    // 0x800C96C8: nop

L_800C96CC:
    // 0x800C96CC: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800C96D0: jal         0x800C8CC0
    // 0x800C96D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C96D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C96D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C96DC: jal         0x800C8CF0
    // 0x800C96E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800C96E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800C96E4: bne         $s1, $zero, L_800C96CC
    if (ctx->r17 != 0) {
        // 0x800C96E8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800C96CC;
    }
    // 0x800C96E8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800C96EC:
    // 0x800C96EC: jal         0x800C9F90
    // 0x800C96F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800C96F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800C96F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C96F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C96FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9700: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C9704: jr          $ra
    // 0x800C9708: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C9708: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void alEvtqPostEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C970C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C9710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9714: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C9718: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C971C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800C9720: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C9724: jal         0x800C9F90
    // 0x800C9728: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9728: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C972C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C9730: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800C9734: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C9738: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x800C973C: bne         $t0, $zero, L_800C9754
    if (ctx->r8 != 0) {
        // 0x800C9740: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800C9754;
    }
    // 0x800C9740: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800C9744: jal         0x800C9F90
    // 0x800C9748: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800C9748: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800C974C: b           L_800C9824
    // 0x800C9750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C9824;
    // 0x800C9750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9754:
    // 0x800C9754: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C9758: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800C975C: jal         0x800C8CC0
    // 0x800C9760: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x800C9760: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800C9764: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9768: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800C976C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800C9770: jal         0x800D3D80
    // 0x800C9774: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alCopy(rdram, ctx);
        goto after_3;
    // 0x800C9774: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800C9778: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800C977C: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800C9780: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800C9784: bne         $a3, $at, L_800C9794
    if (ctx->r7 != ctx->r1) {
        // 0x800C9788: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_800C9794;
    }
    // 0x800C9788: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C978C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C9790: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800C9794:
    // 0x800C9794: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800C9798: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800C979C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800C97A0: beq         $v0, $at, L_800C9818
    if (ctx->r2 == ctx->r1) {
        // 0x800C97A4: addiu       $a1, $v0, 0x8
        ctx->r5 = ADD32(ctx->r2, 0X8);
            goto L_800C9818;
    }
    // 0x800C97A4: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
L_800C97A8:
    // 0x800C97A8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800C97AC: bnel        $v0, $zero, L_800C97DC
    if (ctx->r2 != 0) {
        // 0x800C97B0: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_800C97DC;
    }
    goto skip_0;
    // 0x800C97B0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x800C97B4: beql        $t8, $zero, L_800C97C8
    if (ctx->r24 == 0) {
        // 0x800C97B8: sw          $a3, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r7;
            goto L_800C97C8;
    }
    goto skip_1;
    // 0x800C97B8: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    skip_1:
    // 0x800C97BC: b           L_800C97C8
    // 0x800C97C0: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
        goto L_800C97C8;
    // 0x800C97C0: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x800C97C4: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
L_800C97C8:
    // 0x800C97C8: jal         0x800C8CF0
    // 0x800C97CC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    alLink(rdram, ctx);
        goto after_4;
    // 0x800C97CC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_4:
    // 0x800C97D0: b           L_800C9818
    // 0x800C97D4: nop

        goto L_800C9818;
    // 0x800C97D4: nop

    // 0x800C97D8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_800C97DC:
    // 0x800C97DC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C97E0: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C97E4: beql        $at, $zero, L_800C9810
    if (ctx->r1 == 0) {
        // 0x800C97E8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800C9810;
    }
    goto skip_2;
    // 0x800C97E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    skip_2:
    // 0x800C97EC: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    // 0x800C97F0: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800C97F4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800C97F8: subu        $t1, $t9, $a3
    ctx->r9 = SUB32(ctx->r25, ctx->r7);
    // 0x800C97FC: jal         0x800C8CF0
    // 0x800C9800: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    alLink(rdram, ctx);
        goto after_5;
    // 0x800C9800: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    after_5:
    // 0x800C9804: b           L_800C9818
    // 0x800C9808: nop

        goto L_800C9818;
    // 0x800C9808: nop

    // 0x800C980C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800C9810:
    // 0x800C9810: bne         $v0, $zero, L_800C97A8
    if (ctx->r2 != 0) {
        // 0x800C9814: subu        $a3, $a3, $v1
        ctx->r7 = SUB32(ctx->r7, ctx->r3);
            goto L_800C97A8;
    }
    // 0x800C9814: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
L_800C9818:
    // 0x800C9818: jal         0x800C9F90
    // 0x800C981C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x800C981C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x800C9820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9824:
    // 0x800C9824: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C9828: jr          $ra
    // 0x800C982C: nop

    return;
    // 0x800C982C: nop

;}
RECOMP_FUNC void alEvtqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9830: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C9834: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9838: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C983C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C9840: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C9844: jal         0x800C9F90
    // 0x800C9848: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9848: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C984C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C9850: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C9854: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800C9858: lw          $s0, 0x8($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X8);
    // 0x800C985C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C9860: beql        $s0, $zero, L_800C9898
    if (ctx->r16 == 0) {
        // 0x800C9864: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_800C9898;
    }
    goto skip_0;
    // 0x800C9864: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    skip_0:
    // 0x800C9868: jal         0x800C8CC0
    // 0x800C986C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C986C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C9870: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x800C9874: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800C9878: jal         0x800D3D80
    // 0x800C987C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    alCopy(rdram, ctx);
        goto after_2;
    // 0x800C987C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x800C9880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9884: jal         0x800C8CF0
    // 0x800C9888: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800C9888: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800C988C: b           L_800C989C
    // 0x800C9890: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
        goto L_800C989C;
    // 0x800C9890: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800C9894: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_800C9898:
    // 0x800C9898: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_800C989C:
    // 0x800C989C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800C98A0: jal         0x800C9F90
    // 0x800C98A4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_4;
    // 0x800C98A4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_4:
    // 0x800C98A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C98AC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800C98B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C98B4: jr          $ra
    // 0x800C98B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C98B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void alEvtqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C98BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C98C0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C98C4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C98C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C98CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C98D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C98D4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C98D8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800C98DC: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800C98E0: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800C98E4: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800C98E8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800C98EC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800C98F0: blez        $a2, L_800C9914
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800C98F4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800C9914;
    }
    // 0x800C98F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800C98F8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_800C98FC:
    // 0x800C98FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C9900: jal         0x800C8CF0
    // 0x800C9904: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_0;
    // 0x800C9904: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800C9908: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C990C: bne         $s0, $s3, L_800C98FC
    if (ctx->r16 != ctx->r19) {
        // 0x800C9910: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_800C98FC;
    }
    // 0x800C9910: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_800C9914:
    // 0x800C9914: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9918: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C991C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C9920: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9924: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C9928: jr          $ra
    // 0x800C992C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C992C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alSynAddPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9938: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C993C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800C9940: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C9944: jal         0x800C9F90
    // 0x800C9948: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9948: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C994C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800C9950: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9954: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C9958: lw          $t6, 0x20($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X20);
    // 0x800C995C: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x800C9960: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C9964: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800C9968: jal         0x800C9F90
    // 0x800C996C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800C996C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    after_1:
    // 0x800C9970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9978: jr          $ra
    // 0x800C997C: nop

    return;
    // 0x800C997C: nop

;}
RECOMP_FUNC void _allocatePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9980: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9988: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C998C: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x800C9990: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800C9994: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C9998: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800C999C: beq         $a3, $zero, L_800C99D4
    if (ctx->r7 == 0) {
        // 0x800C99A0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C99D4;
    }
    // 0x800C99A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C99A4: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800C99A8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800C99AC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C99B0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C99B4: jal         0x800C8CC0
    // 0x800C99B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800C99B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800C99BC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C99C0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800C99C4: jal         0x800C8CF0
    // 0x800C99C8: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink(rdram, ctx);
        goto after_1;
    // 0x800C99C8: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_1:
    // 0x800C99CC: b           L_800C9A54
    // 0x800C99D0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800C9A54;
    // 0x800C99D0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800C99D4:
    // 0x800C99D4: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x800C99D8: beq         $a3, $zero, L_800C9A0C
    if (ctx->r7 == 0) {
        // 0x800C99DC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800C9A0C;
    }
    // 0x800C99DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800C99E0: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800C99E4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800C99E8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C99EC: jal         0x800C8CC0
    // 0x800C99F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x800C99F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800C99F4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C99F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800C99FC: jal         0x800C8CF0
    // 0x800C9A00: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800C9A00: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800C9A04: b           L_800C9A54
    // 0x800C9A08: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800C9A54;
    // 0x800C9A08: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800C9A0C:
    // 0x800C9A0C: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x800C9A10: beql        $a3, $zero, L_800C9A58
    if (ctx->r7 == 0) {
        // 0x800C9A14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9A58;
    }
    goto skip_0;
    // 0x800C9A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9A18: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
L_800C9A1C:
    // 0x800C9A1C: lh          $t9, 0x16($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X16);
    // 0x800C9A20: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C9A24: bnel        $at, $zero, L_800C9A4C
    if (ctx->r1 != 0) {
        // 0x800C9A28: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800C9A4C;
    }
    goto skip_1;
    // 0x800C9A28: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x800C9A2C: lw          $t1, 0xD8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XD8);
    // 0x800C9A30: bnel        $t1, $zero, L_800C9A4C
    if (ctx->r9 != 0) {
        // 0x800C9A34: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800C9A4C;
    }
    goto skip_2;
    // 0x800C9A34: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x800C9A38: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800C9A3C: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800C9A40: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C9A44: lh          $a2, 0x16($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X16);
    // 0x800C9A48: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
L_800C9A4C:
    // 0x800C9A4C: bnel        $a3, $zero, L_800C9A1C
    if (ctx->r7 != 0) {
        // 0x800C9A50: lw          $t8, 0x8($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X8);
            goto L_800C9A1C;
    }
    goto skip_3;
    // 0x800C9A50: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    skip_3:
L_800C9A54:
    // 0x800C9A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9A58:
    // 0x800C9A58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9A5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C9A60: jr          $ra
    // 0x800C9A64: nop

    return;
    // 0x800C9A64: nop

;}
RECOMP_FUNC void alSynAllocVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9A68: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C9A6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9A70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C9A74: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C9A78: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800C9A7C: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800C9A80: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C9A84: sh          $t6, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r14;
    // 0x800C9A88: lbu         $t7, 0x4($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X4);
    // 0x800C9A8C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800C9A90: sh          $t7, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r15;
    // 0x800C9A94: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x800C9A98: sh          $zero, 0x14($a1)
    MEM_H(0X14, ctx->r5) = 0;
    // 0x800C9A9C: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800C9AA0: sh          $t8, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r24;
    // 0x800C9AA4: lh          $a2, 0x0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X0);
    // 0x800C9AA8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800C9AAC: jal         0x800C9980
    // 0x800C9AB0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _allocatePVoice(rdram, ctx);
        goto after_0;
    // 0x800C9AB0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800C9AB4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9AB8: beql        $t9, $zero, L_800C9B90
    if (ctx->r25 == 0) {
        // 0x800C9ABC: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_800C9B90;
    }
    goto skip_0;
    // 0x800C9ABC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800C9AC0: beq         $v0, $zero, L_800C9B74
    if (ctx->r2 == 0) {
        // 0x800C9AC4: lw          $a0, 0xC($t9)
        ctx->r4 = MEM_W(ctx->r25, 0XC);
            goto L_800C9B74;
    }
    // 0x800C9AC4: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    // 0x800C9AC8: addiu       $t0, $zero, 0x200
    ctx->r8 = ADD32(0, 0X200);
    // 0x800C9ACC: sw          $t0, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->r8;
    // 0x800C9AD0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9AD4: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800C9AD8: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x800C9ADC: jal         0x800658A8
    // 0x800C9AE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_1;
    // 0x800C9AE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x800C9AE4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800C9AE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C9AEC: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x800C9AF0: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x800C9AF4: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800C9AF8: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800C9AFC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800C9B00: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9B04: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9B08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9B0C: lw          $t7, 0xD8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD8);
    // 0x800C9B10: addiu       $t8, $t7, -0x40
    ctx->r24 = ADD32(ctx->r15, -0X40);
    // 0x800C9B14: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x800C9B18: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9B1C: jalr        $t9
    // 0x800C9B20: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800C9B20: nop

    after_2:
    // 0x800C9B24: jal         0x800658A8
    // 0x800C9B28: nop

    __allocParam(rdram, ctx);
        goto after_3;
    // 0x800C9B28: nop

    after_3:
    // 0x800C9B2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C9B30: beq         $v0, $zero, L_800C9B7C
    if (ctx->r2 == 0) {
        // 0x800C9B34: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9B7C;
    }
    // 0x800C9B34: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9B38: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C9B3C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9B40: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x800C9B44: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x800C9B48: lw          $t3, 0xD8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XD8);
    // 0x800C9B4C: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800C9B50: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C9B54: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C9B58: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800C9B5C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9B60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9B64: jalr        $t9
    // 0x800C9B68: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800C9B68: nop

    after_4:
    // 0x800C9B6C: b           L_800C9B80
    // 0x800C9B70: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_800C9B80;
    // 0x800C9B70: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800C9B74:
    // 0x800C9B74: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9B78: sw          $zero, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = 0;
L_800C9B7C:
    // 0x800C9B7C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800C9B80:
    // 0x800C9B80: sw          $s0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r16;
    // 0x800C9B84: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9B88: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800C9B8C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_800C9B90:
    // 0x800C9B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9B94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C9B98: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C9B9C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800C9BA0: jr          $ra
    // 0x800C9BA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C9BA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C9BA8: nop

    // 0x800C9BAC: nop

;}
