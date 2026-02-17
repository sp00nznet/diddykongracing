#include "recomp.h"
#include "funcs.h"

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
RECOMP_FUNC void func_800BA288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA7A8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA7AC: lw          $v1, -0x5960($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5960);
    // 0x800BA7B0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800BA7B4: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800BA7B8: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800BA7BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BA7C0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800BA7C4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800BA7C8: blez        $v1, L_800BA9C8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BA7CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BA9C8;
    }
    // 0x800BA7CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BA7D0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BA7D4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BA7D8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BA7DC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BA7E0: addiu       $t1, $t1, 0x3668
    ctx->r9 = ADD32(ctx->r9, 0X3668);
    // 0x800BA7E4: addiu       $t2, $t2, -0x5958
    ctx->r10 = ADD32(ctx->r10, -0X5958);
    // 0x800BA7E8: addiu       $t3, $t3, -0x5A78
    ctx->r11 = ADD32(ctx->r11, -0X5A78);
    // 0x800BA7EC: addiu       $t4, $t4, 0x3664
    ctx->r12 = ADD32(ctx->r12, 0X3664);
    // 0x800BA7F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BA7F4: addiu       $s1, $zero, 0x80
    ctx->r17 = ADD32(0, 0X80);
    // 0x800BA7F8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
L_800BA7FC:
    // 0x800BA7FC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800BA800: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BA804: addu        $a3, $a0, $a2
    ctx->r7 = ADD32(ctx->r4, ctx->r6);
    // 0x800BA808: lbu         $t7, 0xA($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0XA);
    // 0x800BA80C: lbu         $t6, 0xB($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XB);
    // 0x800BA810: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x800BA814: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800BA818: addu        $t7, $t2, $t8
    ctx->r15 = ADD32(ctx->r10, ctx->r24);
    // 0x800BA81C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x800BA820: nop

    // 0x800BA824: and         $t8, $t9, $t6
    ctx->r24 = ctx->r25 & ctx->r14;
    // 0x800BA828: beq         $t8, $zero, L_800BA9B8
    if (ctx->r24 == 0) {
        // 0x800BA82C: nop
    
            goto L_800BA9B8;
    }
    // 0x800BA82C: nop

    // 0x800BA830: lw          $t7, 0x28($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X28);
    // 0x800BA834: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BA838: beq         $t7, $zero, L_800BA910
    if (ctx->r15 == 0) {
        // 0x800BA83C: nop
    
            goto L_800BA910;
    }
    // 0x800BA83C: nop

L_800BA840:
    // 0x800BA840: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800BA844: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800BA848: addu        $t6, $a0, $a2
    ctx->r14 = ADD32(ctx->r4, ctx->r6);
    // 0x800BA84C: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800BA850: nop

    // 0x800BA854: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA858: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x800BA85C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800BA860: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800BA864: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800BA868: sllv        $t6, $t7, $t9
    ctx->r14 = S32(ctx->r15 << (ctx->r25 & 31));
    // 0x800BA86C: and         $t7, $t8, $t6
    ctx->r15 = ctx->r24 & ctx->r14;
    // 0x800BA870: beq         $t7, $zero, L_800BA8B8
    if (ctx->r15 == 0) {
        // 0x800BA874: sll         $t8, $v0, 3
        ctx->r24 = S32(ctx->r2 << 3);
            goto L_800BA8B8;
    }
    // 0x800BA874: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800BA878: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800BA87C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800BA880: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BA884: addu        $t8, $a0, $t9
    ctx->r24 = ADD32(ctx->r4, ctx->r25);
    // 0x800BA888: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x800BA88C: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800BA890: addu        $a3, $t7, $v1
    ctx->r7 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA894: lbu         $t0, 0x14($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X14);
    // 0x800BA898: nop

    // 0x800BA89C: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BA8A0: beq         $at, $zero, L_800BA8B0
    if (ctx->r1 == 0) {
        // 0x800BA8A4: subu        $t9, $t0, $a1
        ctx->r25 = SUB32(ctx->r8, ctx->r5);
            goto L_800BA8B0;
    }
    // 0x800BA8A4: subu        $t9, $t0, $a1
    ctx->r25 = SUB32(ctx->r8, ctx->r5);
    // 0x800BA8A8: b           L_800BA8F4
    // 0x800BA8AC: sb          $t9, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r25;
        goto L_800BA8F4;
    // 0x800BA8AC: sb          $t9, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r25;
L_800BA8B0:
    // 0x800BA8B0: b           L_800BA8F4
    // 0x800BA8B4: sb          $zero, 0x14($a3)
    MEM_B(0X14, ctx->r7) = 0;
        goto L_800BA8F4;
    // 0x800BA8B4: sb          $zero, 0x14($a3)
    MEM_B(0X14, ctx->r7) = 0;
L_800BA8B8:
    // 0x800BA8B8: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800BA8BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BA8C0: addu        $t6, $a0, $t8
    ctx->r14 = ADD32(ctx->r4, ctx->r24);
    // 0x800BA8C4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800BA8C8: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800BA8CC: addu        $a3, $t9, $v1
    ctx->r7 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA8D0: lbu         $t8, 0x14($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X14);
    // 0x800BA8D4: nop

    // 0x800BA8D8: addu        $t0, $t8, $a1
    ctx->r8 = ADD32(ctx->r24, ctx->r5);
    // 0x800BA8DC: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800BA8E0: beq         $at, $zero, L_800BA8F0
    if (ctx->r1 == 0) {
        // 0x800BA8E4: nop
    
            goto L_800BA8F0;
    }
    // 0x800BA8E4: nop

    // 0x800BA8E8: b           L_800BA8F4
    // 0x800BA8EC: sb          $t0, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r8;
        goto L_800BA8F4;
    // 0x800BA8EC: sb          $t0, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r8;
L_800BA8F0:
    // 0x800BA8F0: sb          $s1, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r17;
L_800BA8F4:
    // 0x800BA8F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BA8F8: bne         $v1, $t5, L_800BA840
    if (ctx->r3 != ctx->r13) {
        // 0x800BA8FC: nop
    
            goto L_800BA840;
    }
    // 0x800BA8FC: nop

    // 0x800BA900: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA904: lw          $v1, -0x5960($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5960);
    // 0x800BA908: b           L_800BA9BC
    // 0x800BA90C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800BA9BC;
    // 0x800BA90C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BA910:
    // 0x800BA910: lw          $t7, 0xC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XC);
    // 0x800BA914: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800BA918: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA91C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800BA920: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA924: sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16 << 2);
    // 0x800BA928: beq         $t7, $zero, L_800BA96C
    if (ctx->r15 == 0) {
        // 0x800BA92C: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_800BA96C;
    }
    // 0x800BA92C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800BA930: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800BA934: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BA938: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x800BA93C: addu        $a3, $t9, $v1
    ctx->r7 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA940: lbu         $t0, 0x14($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X14);
    // 0x800BA944: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA948: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BA94C: beq         $at, $zero, L_800BA95C
    if (ctx->r1 == 0) {
        // 0x800BA950: subu        $t8, $t0, $a1
        ctx->r24 = SUB32(ctx->r8, ctx->r5);
            goto L_800BA95C;
    }
    // 0x800BA950: subu        $t8, $t0, $a1
    ctx->r24 = SUB32(ctx->r8, ctx->r5);
    // 0x800BA954: b           L_800BA960
    // 0x800BA958: sb          $t8, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r24;
        goto L_800BA960;
    // 0x800BA958: sb          $t8, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r24;
L_800BA95C:
    // 0x800BA95C: sb          $zero, 0x14($a3)
    MEM_B(0X14, ctx->r7) = 0;
L_800BA960:
    // 0x800BA960: lw          $v1, -0x5960($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5960);
    // 0x800BA964: b           L_800BA9BC
    // 0x800BA968: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800BA9BC;
    // 0x800BA968: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BA96C:
    // 0x800BA96C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800BA970: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800BA974: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BA978: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x800BA97C: addu        $a3, $t6, $v1
    ctx->r7 = ADD32(ctx->r14, ctx->r3);
    // 0x800BA980: lbu         $t9, 0x14($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X14);
    // 0x800BA984: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA988: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x800BA98C: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800BA990: beq         $at, $zero, L_800BA9AC
    if (ctx->r1 == 0) {
        // 0x800BA994: nop
    
            goto L_800BA9AC;
    }
    // 0x800BA994: nop

    // 0x800BA998: sb          $t0, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r8;
    // 0x800BA99C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA9A0: lw          $v1, -0x5960($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5960);
    // 0x800BA9A4: b           L_800BA9BC
    // 0x800BA9A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800BA9BC;
    // 0x800BA9A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BA9AC:
    // 0x800BA9AC: sb          $s1, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r17;
    // 0x800BA9B0: lw          $v1, -0x5960($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5960);
    // 0x800BA9B4: nop

L_800BA9B8:
    // 0x800BA9B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BA9BC:
    // 0x800BA9BC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BA9C0: bne         $at, $zero, L_800BA7FC
    if (ctx->r1 != 0) {
        // 0x800BA9C4: addiu       $a2, $a2, 0x1C
        ctx->r6 = ADD32(ctx->r6, 0X1C);
            goto L_800BA7FC;
    }
    // 0x800BA9C4: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
L_800BA9C8:
    // 0x800BA9C8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800BA9CC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800BA9D0: jr          $ra
    // 0x800BA9D4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800BA9D4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void wave_load_material(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA9D8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BA9DC: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800BA9E0: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x800BA9E4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800BA9E8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800BA9EC: bne         $t0, $at, L_800BAA08
    if (ctx->r8 != ctx->r1) {
        // 0x800BA9F0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800BAA08;
    }
    // 0x800BA9F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BA9F4: beq         $a1, $zero, L_800BAA00
    if (ctx->r5 == 0) {
        // 0x800BA9F8: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_800BAA00;
    }
    // 0x800BA9F8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800BA9FC: addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
L_800BAA00:
    // 0x800BAA00: b           L_800BAA44
    // 0x800BAA04: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
        goto L_800BAA44;
    // 0x800BAA04: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
L_800BAA08:
    // 0x800BAA08: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800BAA0C: bne         $t0, $at, L_800BAA34
    if (ctx->r8 != ctx->r1) {
        // 0x800BAA10: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_800BAA34;
    }
    // 0x800BAA10: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800BAA14: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800BAA18: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800BAA1C: beq         $t7, $zero, L_800BAA28
    if (ctx->r15 == 0) {
        // 0x800BAA20: nop
    
            goto L_800BAA28;
    }
    // 0x800BAA20: nop

    // 0x800BAA24: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
L_800BAA28:
    // 0x800BAA28: b           L_800BAA44
    // 0x800BAA2C: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
        goto L_800BAA44;
    // 0x800BAA2C: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x800BAA30: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_800BAA34:
    // 0x800BAA34: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800BAA38: beq         $t8, $zero, L_800BAA44
    if (ctx->r24 == 0) {
        // 0x800BAA3C: nop
    
            goto L_800BAA44;
    }
    // 0x800BAA3C: nop

    // 0x800BAA40: addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
L_800BAA44:
    // 0x800BAA44: lbu         $t9, 0x2($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X2);
    // 0x800BAA48: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800BAA4C: andi        $t6, $t9, 0xF
    ctx->r14 = ctx->r25 & 0XF;
    // 0x800BAA50: bne         $t6, $zero, L_800BAC20
    if (ctx->r14 != 0) {
        // 0x800BAA54: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800BAC20;
    }
    // 0x800BAA54: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BAA58: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BAA5C: addiu       $v1, $v1, -0x5A80
    ctx->r3 = ADD32(ctx->r3, -0X5A80);
    // 0x800BAA60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAA64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BAA68: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BAA6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BAA70: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800BAA74: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800BAA78: addu        $t6, $a3, $at
    ctx->r14 = ADD32(ctx->r7, ctx->r1);
    // 0x800BAA7C: lui         $t8, 0xFD18
    ctx->r24 = S32(0XFD18 << 16);
    // 0x800BAA80: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BAA84: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800BAA88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAA8C: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x800BAA90: andi        $t1, $a2, 0x1FF
    ctx->r9 = ctx->r6 & 0X1FF;
    // 0x800BAA94: or          $t8, $t1, $at
    ctx->r24 = ctx->r9 | ctx->r1;
    // 0x800BAA98: andi        $a0, $t4, 0xF
    ctx->r4 = ctx->r12 & 0XF;
    // 0x800BAA9C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BAAA0: multu       $t0, $t0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BAAA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BAAA8: sll         $t2, $a0, 14
    ctx->r10 = S32(ctx->r4 << 14);
    // 0x800BAAAC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BAAB0: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x800BAAB4: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x800BAAB8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800BAABC: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x800BAAC0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800BAAC4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BAAC8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAACC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800BAAD0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800BAAD4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800BAAD8: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800BAADC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800BAAE0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800BAAE4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800BAAE8: mflo        $a1
    ctx->r5 = lo;
    // 0x800BAAEC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800BAAF0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800BAAF4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BAAF8: sltiu       $at, $a1, 0x7FF
    ctx->r1 = ctx->r5 < 0X7FF ? 1 : 0;
    // 0x800BAAFC: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800BAB00: beq         $at, $zero, L_800BAB10
    if (ctx->r1 == 0) {
        // 0x800BAB04: sw          $t8, 0x0($t5)
        MEM_W(0X0, ctx->r13) = ctx->r24;
            goto L_800BAB10;
    }
    // 0x800BAB04: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x800BAB08: b           L_800BAB14
    // 0x800BAB0C: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
        goto L_800BAB14;
    // 0x800BAB0C: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
L_800BAB10:
    // 0x800BAB10: addiu       $t4, $zero, 0x7FF
    ctx->r12 = ADD32(0, 0X7FF);
L_800BAB14:
    // 0x800BAB14: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800BAB18: srl         $t9, $v0, 3
    ctx->r25 = S32(U32(ctx->r2) >> 3);
    // 0x800BAB1C: bne         $t9, $zero, L_800BAB2C
    if (ctx->r25 != 0) {
        // 0x800BAB20: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_800BAB2C;
    }
    // 0x800BAB20: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800BAB24: b           L_800BAB30
    // 0x800BAB28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800BAB30;
    // 0x800BAB28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800BAB2C:
    // 0x800BAB2C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800BAB30:
    // 0x800BAB30: bne         $v0, $zero, L_800BAB40
    if (ctx->r2 != 0) {
        // 0x800BAB34: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_800BAB40;
    }
    // 0x800BAB34: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x800BAB38: b           L_800BAB44
    // 0x800BAB3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800BAB44;
    // 0x800BAB3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800BAB40:
    // 0x800BAB40: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800BAB44:
    // 0x800BAB44: divu        $zero, $t7, $a2
    lo = S32(U32(ctx->r15) / U32(ctx->r6)); hi = S32(U32(ctx->r15) % U32(ctx->r6));
    // 0x800BAB48: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x800BAB4C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BAB50: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x800BAB54: bne         $a2, $zero, L_800BAB60
    if (ctx->r6 != 0) {
        // 0x800BAB58: nop
    
            goto L_800BAB60;
    }
    // 0x800BAB58: nop

    // 0x800BAB5C: break       7
    do_break(2148248412);
L_800BAB60:
    // 0x800BAB60: mflo        $t6
    ctx->r14 = lo;
    // 0x800BAB64: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800BAB68: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800BAB6C: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x800BAB70: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800BAB74: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x800BAB78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAB7C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800BAB80: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BAB84: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BAB88: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800BAB8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800BAB90: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800BAB94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAB98: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x800BAB9C: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x800BABA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800BABA4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800BABA8: srl         $t6, $t9, 3
    ctx->r14 = S32(U32(ctx->r25) >> 3);
    // 0x800BABAC: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x800BABB0: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x800BABB4: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x800BABB8: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800BABBC: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x800BABC0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800BABC4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BABC8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800BABCC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800BABD0: andi        $t7, $a0, 0x7
    ctx->r15 = ctx->r4 & 0X7;
    // 0x800BABD4: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x800BABD8: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x800BABDC: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x800BABE0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800BABE4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BABE8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800BABEC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800BABF0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BABF4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800BABF8: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800BABFC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800BAC00: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BAC04: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800BAC08: or          $t8, $a0, $t6
    ctx->r24 = ctx->r4 | ctx->r14;
    // 0x800BAC0C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800BAC10: or          $t9, $t8, $t9
    ctx->r25 = ctx->r24 | ctx->r25;
    // 0x800BAC14: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800BAC18: b           L_800BADFC
    // 0x800BAC1C: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
        goto L_800BADFC;
    // 0x800BAC1C: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
L_800BAC20:
    // 0x800BAC20: addiu       $v1, $v1, -0x5A80
    ctx->r3 = ADD32(ctx->r3, -0X5A80);
    // 0x800BAC24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAC28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BAC2C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800BAC30: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BAC34: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800BAC38: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800BAC3C: addu        $t7, $a3, $at
    ctx->r15 = ADD32(ctx->r7, ctx->r1);
    // 0x800BAC40: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x800BAC44: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BAC48: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800BAC4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAC50: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800BAC54: andi        $t1, $a2, 0x1FF
    ctx->r9 = ctx->r6 & 0X1FF;
    // 0x800BAC58: or          $t8, $t1, $at
    ctx->r24 = ctx->r9 | ctx->r1;
    // 0x800BAC5C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800BAC60: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BAC64: andi        $a0, $t4, 0xF
    ctx->r4 = ctx->r12 & 0XF;
    // 0x800BAC68: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800BAC6C: sll         $t2, $a0, 14
    ctx->r10 = S32(ctx->r4 << 14);
    // 0x800BAC70: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BAC74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BAC78: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800BAC7C: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x800BAC80: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x800BAC84: multu       $t0, $t0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BAC88: or          $t6, $t9, $t3
    ctx->r14 = ctx->r25 | ctx->r11;
    // 0x800BAC8C: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x800BAC90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAC94: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800BAC98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BAC9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BACA0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800BACA4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800BACA8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800BACAC: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x800BACB0: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800BACB4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800BACB8: mflo        $a1
    ctx->r5 = lo;
    // 0x800BACBC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800BACC0: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x800BACC4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BACC8: sltiu       $at, $a1, 0x7FF
    ctx->r1 = ctx->r5 < 0X7FF ? 1 : 0;
    // 0x800BACCC: beq         $at, $zero, L_800BACDC
    if (ctx->r1 == 0) {
        // 0x800BACD0: sw          $t9, 0x0($t5)
        MEM_W(0X0, ctx->r13) = ctx->r25;
            goto L_800BACDC;
    }
    // 0x800BACD0: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800BACD4: b           L_800BACE0
    // 0x800BACD8: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
        goto L_800BACE0;
    // 0x800BACD8: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
L_800BACDC:
    // 0x800BACDC: addiu       $t4, $zero, 0x7FF
    ctx->r12 = ADD32(0, 0X7FF);
L_800BACE0:
    // 0x800BACE0: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x800BACE4: srl         $t8, $t6, 3
    ctx->r24 = S32(U32(ctx->r14) >> 3);
    // 0x800BACE8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800BACEC: bne         $t8, $zero, L_800BACFC
    if (ctx->r24 != 0) {
        // 0x800BACF0: sw          $t6, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r14;
            goto L_800BACFC;
    }
    // 0x800BACF0: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x800BACF4: b           L_800BAD00
    // 0x800BACF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800BAD00;
    // 0x800BACF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800BACFC:
    // 0x800BACFC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800BAD00:
    // 0x800BAD00: bne         $v0, $zero, L_800BAD10
    if (ctx->r2 != 0) {
        // 0x800BAD04: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_800BAD10;
    }
    // 0x800BAD04: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x800BAD08: b           L_800BAD14
    // 0x800BAD0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800BAD14;
    // 0x800BAD0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800BAD10:
    // 0x800BAD10: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800BAD14:
    // 0x800BAD14: divu        $zero, $t7, $a2
    lo = S32(U32(ctx->r15) / U32(ctx->r6)); hi = S32(U32(ctx->r15) % U32(ctx->r6));
    // 0x800BAD18: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x800BAD1C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BAD20: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x800BAD24: bne         $a2, $zero, L_800BAD30
    if (ctx->r6 != 0) {
        // 0x800BAD28: nop
    
            goto L_800BAD30;
    }
    // 0x800BAD28: nop

    // 0x800BAD2C: break       7
    do_break(2148248876);
L_800BAD30:
    // 0x800BAD30: mflo        $t9
    ctx->r25 = lo;
    // 0x800BAD34: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800BAD38: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800BAD3C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800BAD40: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800BAD44: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x800BAD48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAD4C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800BAD50: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BAD54: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BAD58: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800BAD5C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BAD60: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BAD64: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800BAD68: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800BAD6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BAD70: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BAD74: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BAD78: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800BAD7C: srl         $t6, $t9, 3
    ctx->r14 = S32(U32(ctx->r25) >> 3);
    // 0x800BAD80: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BAD84: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800BAD88: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x800BAD8C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800BAD90: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x800BAD94: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800BAD98: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BAD9C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800BADA0: nop

    // 0x800BADA4: andi        $t8, $a0, 0x7
    ctx->r24 = ctx->r4 & 0X7;
    // 0x800BADA8: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800BADAC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800BADB0: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x800BADB4: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x800BADB8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800BADBC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BADC0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800BADC4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800BADC8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BADCC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800BADD0: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800BADD4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BADD8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800BADDC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BADE0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800BADE4: or          $t7, $a0, $t6
    ctx->r15 = ctx->r4 | ctx->r14;
    // 0x800BADE8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800BADEC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800BADF0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BADF4: nop

    // 0x800BADF8: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
L_800BADFC:
    // 0x800BADFC: jr          $ra
    // 0x800BAE00: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BAE00: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void waves_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BAE04: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x800BAE08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BAE0C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800BAE10: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800BAE14: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800BAE18: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800BAE1C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800BAE20: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800BAE24: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800BAE28: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800BAE2C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800BAE30: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800BAE34: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BAE38: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x800BAE3C: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BAE40: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x800BAE44: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BAE48: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800BAE4C: sw          $a0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r4;
    // 0x800BAE50: bne         $a2, $at, L_800BAE6C
    if (ctx->r6 != ctx->r1) {
        // 0x800BAE54: sw          $a1, 0x124($sp)
        MEM_W(0X124, ctx->r29) = ctx->r5;
            goto L_800BAE6C;
    }
    // 0x800BAE54: sw          $a1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r5;
    // 0x800BAE58: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BAE5C: lw          $t6, -0x59C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X59C8);
    // 0x800BAE60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BAE64: beq         $t6, $at, L_800BAE74
    if (ctx->r14 == ctx->r1) {
        // 0x800BAE68: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800BAE74;
    }
    // 0x800BAE68: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_800BAE6C:
    // 0x800BAE6C: b           L_800BAE78
    // 0x800BAE70: sw          $zero, 0x128($sp)
    MEM_W(0X128, ctx->r29) = 0;
        goto L_800BAE78;
    // 0x800BAE70: sw          $zero, 0x128($sp)
    MEM_W(0X128, ctx->r29) = 0;
L_800BAE74:
    // 0x800BAE74: sw          $t7, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r15;
L_800BAE78:
    // 0x800BAE78: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800BAE7C: lw          $t8, 0x366C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X366C);
    // 0x800BAE80: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800BAE84: blez        $t8, L_800BB7C4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800BAE88: addiu       $s1, $s1, -0x5A80
        ctx->r17 = ADD32(ctx->r17, -0X5A80);
            goto L_800BB7C4;
    }
    // 0x800BAE88: addiu       $s1, $s1, -0x5A80
    ctx->r17 = ADD32(ctx->r17, -0X5A80);
    // 0x800BAE8C: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    // 0x800BAE90: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x800BAE94: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800BAE98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BAE9C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BAEA0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800BAEA4: sw          $zero, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = 0;
    // 0x800BAEA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BAEAC: jal         0x8007B820
    // 0x800BAEB0: sw          $t8, -0x5A7C($at)
    MEM_W(-0X5A7C, ctx->r1) = ctx->r24;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800BAEB0: sw          $t8, -0x5A7C($at)
    MEM_W(-0X5A7C, ctx->r1) = ctx->r24;
    after_0:
    // 0x800BAEB4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAEB8: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BAEBC: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BAEC0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BAEC4: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x800BAEC8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BAECC: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BAED0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800BAED4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BAED8: lw          $t8, 0x4C($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X4C);
    // 0x800BAEDC: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x800BAEE0: beq         $t8, $zero, L_800BB0A0
    if (ctx->r24 == 0) {
        // 0x800BAEE4: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800BB0A0;
    }
    // 0x800BAEE4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BAEE8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAEEC: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x800BAEF0: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BAEF4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BAEF8: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x800BAEFC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BAF00: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800BAF04: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BAF08: lw          $a1, -0x59A4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X59A4);
    // 0x800BAF0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800BAF10: lw          $a0, 0x3660($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3660);
    // 0x800BAF14: sll         $t8, $a1, 8
    ctx->r24 = S32(ctx->r5 << 8);
    // 0x800BAF18: jal         0x8007B8BC
    // 0x800BAF1C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    set_animated_texture_header(rdram, ctx);
        goto after_1;
    // 0x800BAF1C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_1:
    // 0x800BAF20: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BAF24: lw          $t9, -0x59C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X59C4);
    // 0x800BAF28: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BAF2C: lbu         $a1, 0x7($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X7);
    // 0x800BAF30: lw          $a0, -0x59C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X59C0);
    // 0x800BAF34: sll         $t6, $a1, 14
    ctx->r14 = S32(ctx->r5 << 14);
    // 0x800BAF38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800BAF3C: jal         0x8007B8BC
    // 0x800BAF40: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    set_animated_texture_header(rdram, ctx);
        goto after_2;
    // 0x800BAF40: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_2:
    // 0x800BAF44: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800BAF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BAF4C: jal         0x800BA9D8
    // 0x800BAF50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wave_load_material(rdram, ctx);
        goto after_3;
    // 0x800BAF50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x800BAF54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BAF58: jal         0x800BA9D8
    // 0x800BAF5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    wave_load_material(rdram, ctx);
        goto after_4;
    // 0x800BAF5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800BAF60: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAF64: lui         $t8, 0xFC22
    ctx->r24 = S32(0XFC22 << 16);
    // 0x800BAF68: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BAF6C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BAF70: lui         $t9, 0x1010
    ctx->r25 = S32(0X1010 << 16);
    // 0x800BAF74: ori         $t9, $t9, 0x923F
    ctx->r25 = ctx->r25 | 0X923F;
    // 0x800BAF78: ori         $t8, $t8, 0x66AC
    ctx->r24 = ctx->r24 | 0X66AC;
    // 0x800BAF7C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800BAF80: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800BAF84: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x800BAF88: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BAF8C: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800BAF90: bne         $t7, $zero, L_800BAFD4
    if (ctx->r15 != 0) {
        // 0x800BAF94: addiu       $ra, $ra, -0x5A78
        ctx->r31 = ADD32(ctx->r31, -0X5A78);
            goto L_800BAFD4;
    }
    // 0x800BAF94: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BAF98: jal         0x80066450
    // 0x800BAF9C: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_5;
    // 0x800BAF9C: nop

    after_5:
    // 0x800BAFA0: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BAFA4: bgtz        $v0, L_800BAFD4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800BAFA8: addiu       $ra, $ra, -0x5A78
        ctx->r31 = ADD32(ctx->r31, -0X5A78);
            goto L_800BAFD4;
    }
    // 0x800BAFA8: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BAFAC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAFB0: lui         $t9, 0xEF18
    ctx->r25 = S32(0XEF18 << 16);
    // 0x800BAFB4: lui         $t6, 0x10
    ctx->r14 = S32(0X10 << 16);
    // 0x800BAFB8: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BAFBC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BAFC0: ori         $t6, $t6, 0x45D8
    ctx->r14 = ctx->r14 | 0X45D8;
    // 0x800BAFC4: ori         $t9, $t9, 0x2C0F
    ctx->r25 = ctx->r25 | 0X2C0F;
    // 0x800BAFC8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BAFCC: b           L_800BAFF8
    // 0x800BAFD0: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
        goto L_800BAFF8;
    // 0x800BAFD0: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
L_800BAFD4:
    // 0x800BAFD4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAFD8: lui         $t8, 0xEF18
    ctx->r24 = S32(0XEF18 << 16);
    // 0x800BAFDC: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BAFE0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BAFE4: lui         $t9, 0x11
    ctx->r25 = S32(0X11 << 16);
    // 0x800BAFE8: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x800BAFEC: ori         $t8, $t8, 0x2C0F
    ctx->r24 = ctx->r24 | 0X2C0F;
    // 0x800BAFF0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800BAFF4: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
L_800BAFF8:
    // 0x800BAFF8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAFFC: addiu       $v1, $zero, -0x100
    ctx->r3 = ADD32(0, -0X100);
    // 0x800BB000: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800BB004: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BB008: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BB00C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800BB010: addiu       $t1, $t1, 0x3710
    ctx->r9 = ADD32(ctx->r9, 0X3710);
    // 0x800BB014: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB018: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x800BB01C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BB020: nop

    // 0x800BB024: beq         $t8, $zero, L_800BB080
    if (ctx->r24 == 0) {
        // 0x800BB028: nop
    
            goto L_800BB080;
    }
    // 0x800BB028: nop

    // 0x800BB02C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB030: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800BB034: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BB038: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BB03C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BB040: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800BB044: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
    // 0x800BB048: lbu         $t8, 0x10($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X10);
    // 0x800BB04C: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x800BB050: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800BB054: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800BB058: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800BB05C: lbu         $t9, 0x12($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X12);
    // 0x800BB060: nop

    // 0x800BB064: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x800BB068: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800BB06C: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x800BB070: nop

    // 0x800BB074: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800BB078: b           L_800BB200
    // 0x800BB07C: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
        goto L_800BB200;
    // 0x800BB07C: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
L_800BB080:
    // 0x800BB080: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB084: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800BB088: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BB08C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BB090: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x800BB094: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB098: b           L_800BB200
    // 0x800BB09C: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
        goto L_800BB200;
    // 0x800BB09C: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
L_800BB0A0:
    // 0x800BB0A0: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB0A4: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x800BB0A8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800BB0AC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BB0B0: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800BB0B4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800BB0B8: lw          $t7, -0x59C4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X59C4);
    // 0x800BB0BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB0C0: lbu         $a1, 0x7($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X7);
    // 0x800BB0C4: lw          $a0, -0x59C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X59C0);
    // 0x800BB0C8: sll         $t6, $a1, 14
    ctx->r14 = S32(ctx->r5 << 14);
    // 0x800BB0CC: jal         0x8007B8BC
    // 0x800BB0D0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    set_animated_texture_header(rdram, ctx);
        goto after_6;
    // 0x800BB0D0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_6:
    // 0x800BB0D4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB0D8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BB0DC: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB0E0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB0E4: lh          $a0, 0xA($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XA);
    // 0x800BB0E8: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
    // 0x800BB0EC: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x800BB0F0: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800BB0F4: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x800BB0F8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800BB0FC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800BB100: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800BB104: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB108: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800BB10C: lui         $t7, 0xFC56
    ctx->r15 = S32(0XFC56 << 16);
    // 0x800BB110: addu        $t6, $t8, $s2
    ctx->r14 = ADD32(ctx->r24, ctx->r18);
    // 0x800BB114: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800BB118: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB11C: lui         $t8, 0x1FFC
    ctx->r24 = S32(0X1FFC << 16);
    // 0x800BB120: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BB124: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BB128: ori         $t8, $t8, 0xF7F8
    ctx->r24 = ctx->r24 | 0XF7F8;
    // 0x800BB12C: ori         $t7, $t7, 0x7E04
    ctx->r15 = ctx->r15 | 0X7E04;
    // 0x800BB130: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB134: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800BB138: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB13C: lui         $t7, 0xC811
    ctx->r15 = S32(0XC811 << 16);
    // 0x800BB140: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800BB144: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BB148: lui         $t9, 0xEF18
    ctx->r25 = S32(0XEF18 << 16);
    // 0x800BB14C: ori         $t9, $t9, 0x2C0F
    ctx->r25 = ctx->r25 | 0X2C0F;
    // 0x800BB150: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x800BB154: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800BB158: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB15C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB160: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BB164: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB168: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB16C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800BB170: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800BB174: addiu       $t1, $t1, 0x3710
    ctx->r9 = ADD32(ctx->r9, 0X3710);
    // 0x800BB178: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BB17C: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800BB180: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BB184: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB188: beq         $t7, $zero, L_800BB1E4
    if (ctx->r15 == 0) {
        // 0x800BB18C: addiu       $ra, $ra, -0x5A78
        ctx->r31 = ADD32(ctx->r31, -0X5A78);
            goto L_800BB1E4;
    }
    // 0x800BB18C: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BB190: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB194: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800BB198: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB19C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB1A0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BB1A4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800BB1A8: nop

    // 0x800BB1AC: lbu         $t7, 0x10($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X10);
    // 0x800BB1B0: lbu         $t9, 0x11($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X11);
    // 0x800BB1B4: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800BB1B8: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800BB1BC: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800BB1C0: lbu         $t8, 0x12($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X12);
    // 0x800BB1C4: nop

    // 0x800BB1C8: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x800BB1CC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800BB1D0: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x800BB1D4: nop

    // 0x800BB1D8: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800BB1DC: b           L_800BB200
    // 0x800BB1E0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
        goto L_800BB200;
    // 0x800BB1E0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
L_800BB1E4:
    // 0x800BB1E4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB1E8: addiu       $v1, $zero, -0x100
    ctx->r3 = ADD32(0, -0X100);
    // 0x800BB1EC: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB1F0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB1F4: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x800BB1F8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB1FC: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
L_800BB200:
    // 0x800BB200: lw          $t6, 0x28($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X28);
    // 0x800BB204: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB208: beq         $t6, $zero, L_800BB228
    if (ctx->r14 == 0) {
        // 0x800BB20C: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800BB228;
    }
    // 0x800BB20C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BB210: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BB214: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BB218: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB21C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800BB220: b           L_800BB238
    // 0x800BB224: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
        goto L_800BB238;
    // 0x800BB224: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
L_800BB228:
    // 0x800BB228: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800BB22C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BB230: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BB234: swc1        $f24, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f24.u32l;
L_800BB238:
    // 0x800BB238: lw          $t7, 0x366C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X366C);
    // 0x800BB23C: sh          $zero, 0xE8($sp)
    MEM_H(0XE8, ctx->r29) = 0;
    // 0x800BB240: sh          $zero, 0xE6($sp)
    MEM_H(0XE6, ctx->r29) = 0;
    // 0x800BB244: blez        $t7, L_800BB760
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800BB248: sh          $zero, 0xE4($sp)
        MEM_H(0XE4, ctx->r29) = 0;
            goto L_800BB760;
    }
    // 0x800BB248: sh          $zero, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = 0;
    // 0x800BB24C: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x800BB250: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BB254: addiu       $t6, $t6, -0x5858
    ctx->r14 = ADD32(ctx->r14, -0X5858);
    // 0x800BB258: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BB25C: addu        $s0, $t9, $t6
    ctx->r16 = ADD32(ctx->r25, ctx->r14);
    // 0x800BB260: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800BB264: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800BB268: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800BB26C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800BB270: addiu       $s3, $s3, -0x5A28
    ctx->r19 = ADD32(ctx->r19, -0X5A28);
    // 0x800BB274: addiu       $s5, $s5, 0x3600
    ctx->r21 = ADD32(ctx->r21, 0X3600);
    // 0x800BB278: addiu       $s7, $s7, 0x3610
    ctx->r23 = ADD32(ctx->r23, 0X3610);
    // 0x800BB27C: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
    // 0x800BB280: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x800BB284: lui         $s4, 0x400
    ctx->r20 = S32(0X400 << 16);
L_800BB288:
    // 0x800BB288: lw          $t7, 0x4C($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X4C);
    // 0x800BB28C: lw          $s0, 0x74($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X74);
    // 0x800BB290: beq         $t7, $zero, L_800BB2B4
    if (ctx->r15 == 0) {
        // 0x800BB294: nop
    
            goto L_800BB2B4;
    }
    // 0x800BB294: nop

    // 0x800BB298: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800BB29C: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x800BB2A0: jal         0x800B9814
    // 0x800BB2A4: nop

    func_800B92F4(rdram, ctx);
        goto after_7;
    // 0x800BB2A4: nop

    after_7:
    // 0x800BB2A8: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB2AC: b           L_800BB2CC
    // 0x800BB2B0: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
        goto L_800BB2CC;
    // 0x800BB2B0: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
L_800BB2B4:
    // 0x800BB2B4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800BB2B8: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x800BB2BC: jal         0x800B9CC8
    // 0x800BB2C0: nop

    func_800B97A8(rdram, ctx);
        goto after_8;
    // 0x800BB2C0: nop

    after_8:
    // 0x800BB2C4: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB2C8: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
L_800BB2CC:
    // 0x800BB2CC: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800BB2D0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BB2D4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BB2D8: lw          $t6, 0x3668($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3668);
    // 0x800BB2DC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800BB2E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BB2E4: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x800BB2E8: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800BB2EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BB2F0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800BB2F4: lw          $t6, 0x3664($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3664);
    // 0x800BB2F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB2FC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BB300: addiu       $a1, $a1, -0x5A7C
    ctx->r5 = ADD32(ctx->r5, -0X5A7C);
    // 0x800BB304: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    // 0x800BB308: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x800BB30C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BB310: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800BB314: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x800BB318: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BB31C: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
    // 0x800BB320: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x800BB324: nop

    // 0x800BB328: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800BB32C: nop

    // 0x800BB330: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BB334: swc1        $f18, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f18.u32l;
    // 0x800BB338: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800BB33C: nop

    // 0x800BB340: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BB344: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800BB348: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800BB34C: lw          $t6, 0x28($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X28);
    // 0x800BB350: sw          $t7, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r15;
    // 0x800BB354: beq         $t6, $zero, L_800BB5E8
    if (ctx->r14 == 0) {
        // 0x800BB358: nop
    
            goto L_800BB5E8;
    }
    // 0x800BB358: nop

    // 0x800BB35C: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
    // 0x800BB360: sw          $v0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r2;
    // 0x800BB364: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
L_800BB368:
    // 0x800BB368: lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE0);
    // 0x800BB36C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800BB370: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800BB374: nop

    // 0x800BB378: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800BB37C: nop

    // 0x800BB380: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB384: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
L_800BB388:
    // 0x800BB388: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BB38C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800BB390: addiu       $a1, $a1, -0x5A7C
    ctx->r5 = ADD32(ctx->r5, -0X5A7C);
    // 0x800BB394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BB398: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x800BB39C: jal         0x800696C4
    // 0x800BB3A0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_9;
    // 0x800BB3A0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_9:
    // 0x800BB3A4: lw          $a1, 0x104($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X104);
    // 0x800BB3A8: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB3AC: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x800BB3B0: beq         $t9, $zero, L_800BB4E0
    if (ctx->r25 == 0) {
        // 0x800BB3B4: addiu       $ra, $ra, -0x5A78
        ctx->r31 = ADD32(ctx->r31, -0X5A78);
            goto L_800BB4E0;
    }
    // 0x800BB3B4: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BB3B8: lw          $a2, 0x0($ra)
    ctx->r6 = MEM_W(ctx->r31, 0X0);
    // 0x800BB3BC: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x800BB3C0: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x800BB3C4: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB3C8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800BB3CC: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800BB3D0: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800BB3D4: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800BB3D8: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x800BB3DC: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x800BB3E0: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x800BB3E4: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
    // 0x800BB3E8: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
    // 0x800BB3EC: addiu       $t8, $a0, -0x1
    ctx->r24 = ADD32(ctx->r4, -0X1);
    // 0x800BB3F0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800BB3F4: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB3F8: ori         $t7, $t9, 0x1
    ctx->r15 = ctx->r25 | 0X1;
    // 0x800BB3FC: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800BB400: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB404: andi        $t6, $t4, 0xFFFF
    ctx->r14 = ctx->r12 & 0XFFFF;
    // 0x800BB408: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x800BB40C: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x800BB410: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800BB414: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x800BB418: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800BB41C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800BB420: or          $t5, $t9, $t6
    ctx->r13 = ctx->r25 | ctx->r14;
    // 0x800BB424: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BB428: mflo        $t0
    ctx->r8 = lo;
    // 0x800BB42C: blez        $a2, L_800BB578
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BB430: nop
    
            goto L_800BB578;
    }
    // 0x800BB430: nop

L_800BB434:
    // 0x800BB434: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB438: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800BB43C: lw          $t7, 0x128($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X128);
    // 0x800BB440: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB444: addu        $a0, $t8, $t7
    ctx->r4 = ADD32(ctx->r24, ctx->r15);
    // 0x800BB448: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800BB44C: addu        $t6, $s5, $t9
    ctx->r14 = ADD32(ctx->r21, ctx->r25);
    // 0x800BB450: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800BB454: addu        $t9, $s7, $t9
    ctx->r25 = ADD32(ctx->r23, ctx->r25);
    // 0x800BB458: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800BB45C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BB460: addu        $t1, $t8, $t7
    ctx->r9 = ADD32(ctx->r24, ctx->r15);
    // 0x800BB464: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800BB468: multu       $s0, $t8
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB46C: addu        $a1, $t1, $s2
    ctx->r5 = ADD32(ctx->r9, ctx->r18);
    // 0x800BB470: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB474: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB478: sw          $a1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r5;
    // 0x800BB47C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BB480: mflo        $t7
    ctx->r15 = lo;
    // 0x800BB484: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800BB488: andi        $t7, $a1, 0x6
    ctx->r15 = ctx->r5 & 0X6;
    // 0x800BB48C: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x800BB490: or          $t6, $t3, $t7
    ctx->r14 = ctx->r11 | ctx->r15;
    // 0x800BB494: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x800BB498: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800BB49C: or          $t7, $t8, $s4
    ctx->r15 = ctx->r24 | ctx->r20;
    // 0x800BB4A0: or          $t6, $t7, $t4
    ctx->r14 = ctx->r15 | ctx->r12;
    // 0x800BB4A4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BB4A8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB4AC: addu        $t8, $t2, $s2
    ctx->r24 = ADD32(ctx->r10, ctx->r18);
    // 0x800BB4B0: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BB4B4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BB4B8: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800BB4BC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x800BB4C0: lw          $a2, 0x0($ra)
    ctx->r6 = MEM_W(ctx->r31, 0X0);
    // 0x800BB4C4: nop

    // 0x800BB4C8: slt         $at, $s0, $a2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BB4CC: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x800BB4D0: bne         $at, $zero, L_800BB434
    if (ctx->r1 != 0) {
        // 0x800BB4D4: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BB434;
    }
    // 0x800BB4D4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800BB4D8: b           L_800BB578
    // 0x800BB4DC: nop

        goto L_800BB578;
    // 0x800BB4DC: nop

L_800BB4E0:
    // 0x800BB4E0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800BB4E4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x800BB4E8: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB4EC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB4F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB4F4: addiu       $a0, $a0, -0x5A18
    ctx->r4 = ADD32(ctx->r4, -0X5A18);
    // 0x800BB4F8: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BB4FC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BB500: mflo        $t9
    ctx->r25 = lo;
    // 0x800BB504: addu        $t8, $a0, $t9
    ctx->r24 = ADD32(ctx->r4, ctx->r25);
    // 0x800BB508: addu        $t7, $t8, $s2
    ctx->r15 = ADD32(ctx->r24, ctx->r18);
    // 0x800BB50C: andi        $t6, $t7, 0x6
    ctx->r14 = ctx->r15 & 0X6;
    // 0x800BB510: ori         $t9, $t6, 0x18
    ctx->r25 = ctx->r14 | 0X18;
    // 0x800BB514: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x800BB518: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800BB51C: or          $t6, $t7, $s4
    ctx->r14 = ctx->r15 | ctx->r20;
    // 0x800BB520: ori         $t9, $t6, 0x50
    ctx->r25 = ctx->r14 | 0X50;
    // 0x800BB524: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB528: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800BB52C: nop

    // 0x800BB530: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB534: mflo        $t7
    ctx->r15 = lo;
    // 0x800BB538: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x800BB53C: addu        $t9, $t6, $s2
    ctx->r25 = ADD32(ctx->r14, ctx->r18);
    // 0x800BB540: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800BB544: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB548: lui         $t7, 0x511
    ctx->r15 = S32(0X511 << 16);
    // 0x800BB54C: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB550: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB554: ori         $t7, $t7, 0x20
    ctx->r15 = ctx->r15 | 0X20;
    // 0x800BB558: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB55C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800BB560: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BB564: sll         $t8, $t9, 5
    ctx->r24 = S32(ctx->r25 << 5);
    // 0x800BB568: addu        $t7, $t8, $s2
    ctx->r15 = ADD32(ctx->r24, ctx->r18);
    // 0x800BB56C: addiu       $t6, $t6, 0x3620
    ctx->r14 = ADD32(ctx->r14, 0X3620);
    // 0x800BB570: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x800BB574: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
L_800BB578:
    // 0x800BB578: jal         0x80069C80
    // 0x800BB57C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mtx_pop(rdram, ctx);
        goto after_10;
    // 0x800BB57C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x800BB580: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB584: lwc1        $f10, -0x59A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800BB588: lw          $t8, 0x104($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X104);
    // 0x800BB58C: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800BB590: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800BB594: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800BB598: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800BB59C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800BB5A0: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB5A4: sra         $t7, $t8, 8
    ctx->r15 = S32(SIGNED(ctx->r24) >> 8);
    // 0x800BB5A8: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BB5AC: sw          $t7, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r15;
    // 0x800BB5B0: bne         $fp, $v1, L_800BB388
    if (ctx->r30 != ctx->r3) {
        // 0x800BB5B4: swc1        $f18, 0xF0($sp)
        MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
            goto L_800BB388;
    }
    // 0x800BB5B4: swc1        $f18, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
    // 0x800BB5B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB5BC: lwc1        $f6, -0x599C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800BB5C0: lw          $v0, 0x11C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X11C);
    // 0x800BB5C4: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BB5C8: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800BB5CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BB5D0: sw          $v0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r2;
    // 0x800BB5D4: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800BB5D8: bne         $v0, $v1, L_800BB368
    if (ctx->r2 != ctx->r3) {
        // 0x800BB5DC: swc1        $f8, 0xF8($sp)
        MEM_W(0XF8, ctx->r29) = ctx->f8.u32l;
            goto L_800BB368;
    }
    // 0x800BB5DC: swc1        $f8, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f8.u32l;
    // 0x800BB5E0: b           L_800BB73C
    // 0x800BB5E4: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
        goto L_800BB73C;
    // 0x800BB5E4: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
L_800BB5E8:
    // 0x800BB5E8: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
    // 0x800BB5EC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800BB5F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BB5F4: jal         0x800696C4
    // 0x800BB5F8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_11;
    // 0x800BB5F8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_11:
    // 0x800BB5FC: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB600: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x800BB604: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BB608: lw          $a2, 0x0($ra)
    ctx->r6 = MEM_W(ctx->r31, 0X0);
    // 0x800BB60C: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x800BB610: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800BB614: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x800BB618: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB61C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800BB620: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800BB624: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800BB628: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800BB62C: sll         $t6, $t3, 3
    ctx->r14 = S32(ctx->r11 << 3);
    // 0x800BB630: sll         $t8, $t4, 1
    ctx->r24 = S32(ctx->r12 << 1);
    // 0x800BB634: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x800BB638: or          $t3, $t6, $zero
    ctx->r11 = ctx->r14 | 0;
    // 0x800BB63C: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
    // 0x800BB640: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800BB644: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x800BB648: mflo        $t7
    ctx->r15 = lo;
    // 0x800BB64C: ori         $t8, $t9, 0x1
    ctx->r24 = ctx->r25 | 0X1;
    // 0x800BB650: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800BB654: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB658: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800BB65C: or          $t4, $t7, $zero
    ctx->r12 = ctx->r15 | 0;
    // 0x800BB660: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x800BB664: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800BB668: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800BB66C: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x800BB670: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800BB674: mflo        $t0
    ctx->r8 = lo;
    // 0x800BB678: blez        $a2, L_800BB728
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BB67C: nop
    
            goto L_800BB728;
    }
    // 0x800BB67C: nop

    // 0x800BB680: lw          $fp, 0x128($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X128);
    // 0x800BB684: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
L_800BB688:
    // 0x800BB688: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB68C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800BB690: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB694: addu        $a0, $t6, $fp
    ctx->r4 = ADD32(ctx->r14, ctx->r30);
    // 0x800BB698: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800BB69C: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x800BB6A0: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800BB6A4: addu        $t8, $s7, $t8
    ctx->r24 = ADD32(ctx->r23, ctx->r24);
    // 0x800BB6A8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800BB6AC: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB6B0: addu        $t1, $t7, $t6
    ctx->r9 = ADD32(ctx->r15, ctx->r14);
    // 0x800BB6B4: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x800BB6B8: multu       $s0, $t7
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB6BC: addu        $a1, $t1, $s2
    ctx->r5 = ADD32(ctx->r9, ctx->r18);
    // 0x800BB6C0: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BB6C4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BB6C8: sw          $a1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r5;
    // 0x800BB6CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BB6D0: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB6D4: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800BB6D8: andi        $t6, $a1, 0x6
    ctx->r14 = ctx->r5 & 0X6;
    // 0x800BB6DC: addu        $t2, $t9, $t8
    ctx->r10 = ADD32(ctx->r25, ctx->r24);
    // 0x800BB6E0: or          $t9, $t3, $t6
    ctx->r25 = ctx->r11 | ctx->r14;
    // 0x800BB6E4: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x800BB6E8: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800BB6EC: or          $t6, $t7, $s4
    ctx->r14 = ctx->r15 | ctx->r20;
    // 0x800BB6F0: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x800BB6F4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB6F8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB6FC: addu        $t7, $t2, $s2
    ctx->r15 = ADD32(ctx->r10, ctx->r18);
    // 0x800BB700: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB704: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB708: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800BB70C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x800BB710: lw          $a2, 0x0($ra)
    ctx->r6 = MEM_W(ctx->r31, 0X0);
    // 0x800BB714: nop

    // 0x800BB718: slt         $at, $s0, $a2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BB71C: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x800BB720: bne         $at, $zero, L_800BB688
    if (ctx->r1 != 0) {
        // 0x800BB724: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BB688;
    }
    // 0x800BB724: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BB728:
    // 0x800BB728: jal         0x80069C80
    // 0x800BB72C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mtx_pop(rdram, ctx);
        goto after_12;
    // 0x800BB72C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x800BB730: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB734: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BB738: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
L_800BB73C:
    // 0x800BB73C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x800BB740: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800BB744: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BB748: lw          $t6, 0x366C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X366C);
    // 0x800BB74C: addiu       $t7, $t8, 0x2
    ctx->r15 = ADD32(ctx->r24, 0X2);
    // 0x800BB750: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BB754: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x800BB758: bne         $at, $zero, L_800BB288
    if (ctx->r1 != 0) {
        // 0x800BB75C: sw          $t9, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->r25;
            goto L_800BB288;
    }
    // 0x800BB75C: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
L_800BB760:
    // 0x800BB760: lw          $t8, 0x4C($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X4C);
    // 0x800BB764: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x800BB768: beq         $t8, $zero, L_800BB7A4
    if (ctx->r24 == 0) {
        // 0x800BB76C: nop
    
            goto L_800BB7A4;
    }
    // 0x800BB76C: nop

    // 0x800BB770: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB774: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800BB778: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BB77C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BB780: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800BB784: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB788: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB78C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800BB790: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB794: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB798: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800BB79C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB7A0: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
L_800BB7A4:
    // 0x800BB7A4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BB7A8: lw          $t8, 0x120($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X120);
    // 0x800BB7AC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BB7B0: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800BB7B4: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800BB7B8: lw          $t7, -0x5A7C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5A7C);
    // 0x800BB7BC: nop

    // 0x800BB7C0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
L_800BB7C4:
    // 0x800BB7C4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800BB7C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BB7CC: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BB7D0: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BB7D4: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BB7D8: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BB7DC: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BB7E0: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BB7E4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800BB7E8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800BB7EC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800BB7F0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800BB7F4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800BB7F8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800BB7FC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800BB800: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800BB804: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800BB808: sw          $zero, 0x366C($at)
    MEM_W(0X366C, ctx->r1) = 0;
    // 0x800BB80C: jr          $ra
    // 0x800BB810: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x800BB810: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void func_800BB2F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB814: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800BB818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BB81C: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800BB820: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800BB824: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800BB828: bltz        $a0, L_800BB848
    if (SIGNED(ctx->r4) < 0) {
        // 0x800BB82C: sw          $a3, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r7;
            goto L_800BB848;
    }
    // 0x800BB82C: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800BB830: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BB834: lw          $t7, -0x5960($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5960);
    // 0x800BB838: nop

    // 0x800BB83C: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BB840: bne         $at, $zero, L_800BB850
    if (ctx->r1 != 0) {
        // 0x800BB844: lw          $t8, 0xA8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA8);
            goto L_800BB850;
    }
    // 0x800BB844: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
L_800BB848:
    // 0x800BB848: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x800BB84C: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
L_800BB850:
    // 0x800BB850: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BB854: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x800BB858: lw          $t9, 0x3668($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3668);
    // 0x800BB85C: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x800BB860: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BB864: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
    // 0x800BB868: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BB86C: lw          $t9, 0x370C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X370C);
    // 0x800BB870: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x800BB874: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB878: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800BB87C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB880: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BB884: lwc1        $f6, -0x5984($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x800BB888: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB88C: lwc1        $f8, -0x5988($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800BB890: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800BB894: addiu       $t1, $t1, -0x5A78
    ctx->r9 = ADD32(ctx->r9, -0X5A78);
    // 0x800BB898: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x800BB89C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB8A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB8A4: lwc1        $f4, 0x44($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X44);
    // 0x800BB8A8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800BB8AC: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800BB8B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BB8B4: lw          $t7, 0x28($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X28);
    // 0x800BB8B8: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB8BC: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x800BB8C0: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x800BB8C4: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x800BB8C8: beq         $t7, $zero, L_800BB900
    if (ctx->r15 == 0) {
        // 0x800BB8CC: div.s       $f16, $f10, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
            goto L_800BB900;
    }
    // 0x800BB8CC: div.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800BB8D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BB8D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB8D8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BB8DC: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BB8E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BB8E4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BB8E8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BB8EC: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800BB8F0: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x800BB8F4: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x800BB8F8: b           L_800BB910
    // 0x800BB8FC: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
        goto L_800BB910;
    // 0x800BB8FC: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
L_800BB900:
    // 0x800BB900: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BB904: nop

    // 0x800BB908: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BB90C: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
L_800BB910:
    // 0x800BB910: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x800BB914: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BB918: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800BB91C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB920: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BB924: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BB928: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800BB92C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800BB930: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x800BB934: bc1f        L_800BB948
    if (!c1cs) {
        // 0x800BB938: nop
    
            goto L_800BB948;
    }
    // 0x800BB938: nop

    // 0x800BB93C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BB940: b           L_800BB974
    // 0x800BB944: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
        goto L_800BB974;
    // 0x800BB944: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
L_800BB948:
    // 0x800BB948: lwc1        $f0, -0x59A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800BB94C: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BB950: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB954: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x800BB958: nop

    // 0x800BB95C: bc1f        L_800BB974
    if (!c1cs) {
        // 0x800BB960: nop
    
            goto L_800BB974;
    }
    // 0x800BB960: nop

    // 0x800BB964: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB968: nop

    // 0x800BB96C: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800BB970: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
L_800BB974:
    // 0x800BB974: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x800BB978: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BB97C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800BB980: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB984: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB988: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800BB98C: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800BB990: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800BB994: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x800BB998: bc1f        L_800BB9AC
    if (!c1cs) {
        // 0x800BB99C: nop
    
            goto L_800BB9AC;
    }
    // 0x800BB99C: nop

    // 0x800BB9A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BB9A4: b           L_800BB9D8
    // 0x800BB9A8: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
        goto L_800BB9D8;
    // 0x800BB9A8: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
L_800BB9AC:
    // 0x800BB9AC: lwc1        $f0, -0x599C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800BB9B0: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BB9B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB9B8: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x800BB9BC: nop

    // 0x800BB9C0: bc1f        L_800BB9D8
    if (!c1cs) {
        // 0x800BB9C4: nop
    
            goto L_800BB9D8;
    }
    // 0x800BB9C4: nop

    // 0x800BB9C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BB9CC: nop

    // 0x800BB9D0: sub.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800BB9D4: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
L_800BB9D8:
    // 0x800BB9D8: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BB9DC: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BB9E0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800BB9E4: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BB9E8: lw          $v1, 0x4($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X4);
    // 0x800BB9EC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BB9F0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800BB9F4: nop

    // 0x800BB9F8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800BB9FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BBA00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BBA04: nop

    // 0x800BBA08: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BBA0C: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BBA10: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800BBA14: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800BBA18: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BBA1C: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x800BBA20: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800BBA24: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BBA28: nop

    // 0x800BBA2C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BBA30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BBA34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BBA38: nop

    // 0x800BBA3C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800BBA40: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800BBA44: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800BBA48: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BBA4C: sw          $a0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r4;
    // 0x800BBA50: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBA54: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBA58: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BBA5C: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800BBA60: nop

    // 0x800BBA64: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800BBA68: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800BBA6C: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x800BBA70: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBA74: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800BBA78: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800BBA7C: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BBA80: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x800BBA84: lh          $t9, 0x12($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X12);
    // 0x800BBA88: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BBA8C: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800BBA90: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBA94: bne         $at, $zero, L_800BBAAC
    if (ctx->r1 != 0) {
        // 0x800BBA98: nop
    
            goto L_800BBAAC;
    }
    // 0x800BBA98: nop

L_800BBA9C:
    // 0x800BBA9C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x800BBAA0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBAA4: beq         $at, $zero, L_800BBA9C
    if (ctx->r1 == 0) {
        // 0x800BBAA8: nop
    
            goto L_800BBA9C;
    }
    // 0x800BBAA8: nop

L_800BBAAC:
    // 0x800BBAAC: lh          $t7, 0x10($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X10);
    // 0x800BBAB0: addiu       $ra, $t0, 0x1
    ctx->r31 = ADD32(ctx->r8, 0X1);
    // 0x800BBAB4: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x800BBAB8: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBABC: bne         $at, $zero, L_800BBAD4
    if (ctx->r1 != 0) {
        // 0x800BBAC0: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_800BBAD4;
    }
    // 0x800BBAC0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
L_800BBAC4:
    // 0x800BBAC4: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // 0x800BBAC8: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBACC: beq         $at, $zero, L_800BBAC4
    if (ctx->r1 == 0) {
        // 0x800BBAD0: nop
    
            goto L_800BBAC4;
    }
    // 0x800BBAD0: nop

L_800BBAD4:
    // 0x800BBAD4: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800BBAD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BBADC: bc1t        L_800BBB10
    if (c1cs) {
        // 0x800BBAE0: slt         $at, $ra, $v1
        ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BBB10;
    }
    // 0x800BBAE0: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBAE4: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800BBAE8: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BBAEC: div.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BBAF0: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BBAF4: nop

    // 0x800BBAF8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BBAFC: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800BBB00: nop

    // 0x800BBB04: bc1f        L_800BBB10
    if (!c1cs) {
        // 0x800BBB08: nop
    
            goto L_800BBB10;
    }
    // 0x800BBB08: nop

    // 0x800BBB0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800BBB10:
    // 0x800BBB10: beq         $v0, $zero, L_800BBE90
    if (ctx->r2 == 0) {
        // 0x800BBB14: nop
    
            goto L_800BBE90;
    }
    // 0x800BBB14: nop

    // 0x800BBB18: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBB1C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BBB20: lw          $t2, 0x35D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35D4);
    // 0x800BBB24: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BBB28: lw          $a1, 0x35D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X35D0);
    // 0x800BBB2C: lwc1        $f14, 0x40($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X40);
    // 0x800BBB30: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BBB34: lw          $t3, 0x3718($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3718);
    // 0x800BBB38: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBB3C: mflo        $t9
    ctx->r25 = lo;
    // 0x800BBB40: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800BBB44: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BBB48: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x800BBB4C: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800BBB50: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800BBB54: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BBB58: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800BBB5C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BBB60: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800BBB64: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BBB68: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BBB6C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BBB70: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800BBB74: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800BBB78: blez        $t3, L_800BBBD4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BBB7C: swc1        $f8, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
            goto L_800BBBD4;
    }
    // 0x800BBB7C: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x800BBB80: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BBB84: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800BBB88: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800BBB8C: jal         0x800BF4E4
    // 0x800BBB90: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800BBB90: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800BBB94: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBB98: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBB9C: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800BBBA0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BBBA4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BBBA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBBAC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BBBB0: lw          $t3, 0x3718($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3718);
    // 0x800BBBB4: lwc1        $f14, -0x5A38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800BBBB8: lw          $t2, 0x35D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35D4);
    // 0x800BBBBC: lw          $a1, 0x35D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X35D0);
    // 0x800BBBC0: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BBBC4: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800BBBC8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800BBBCC: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BBBD0: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
L_800BBBD4:
    // 0x800BBBD4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBBD8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800BBBDC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800BBBE0: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBBE4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800BBBE8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BBBEC: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x800BBBF0: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BBBF4: addiu       $t1, $a3, 0x1
    ctx->r9 = ADD32(ctx->r7, 0X1);
    // 0x800BBBF8: mflo        $t9
    ctx->r25 = lo;
    // 0x800BBBFC: addu        $ra, $t5, $t9
    ctx->r31 = ADD32(ctx->r13, ctx->r25);
    // 0x800BBC00: addu        $t6, $t4, $ra
    ctx->r14 = ADD32(ctx->r12, ctx->r31);
    // 0x800BBC04: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x800BBC08: nop

    // 0x800BBC0C: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BBC10: beq         $at, $zero, L_800BBC40
    if (ctx->r1 == 0) {
        // 0x800BBC14: slt         $at, $t1, $v1
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BBC40;
    }
    // 0x800BBC14: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBC18: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800BBC1C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBC20: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BBC24: lwc1        $f4, -0x5A34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BBC28: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BBC2C: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBC30: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800BBC34: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BBC38: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x800BBC3C: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
L_800BBC40:
    // 0x800BBC40: bne         $at, $zero, L_800BBC50
    if (ctx->r1 != 0) {
        // 0x800BBC44: nop
    
            goto L_800BBC50;
    }
    // 0x800BBC44: nop

    // 0x800BBC48: b           L_800BBC60
    // 0x800BBC4C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_800BBC60;
    // 0x800BBC4C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800BBC50:
    // 0x800BBC50: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBC54: mflo        $t7
    ctx->r15 = lo;
    // 0x800BBC58: addu        $a0, $t7, $t0
    ctx->r4 = ADD32(ctx->r15, ctx->r8);
    // 0x800BBC5C: nop

L_800BBC60:
    // 0x800BBC60: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800BBC64: addu        $v0, $t2, $t8
    ctx->r2 = ADD32(ctx->r10, ctx->r24);
    // 0x800BBC68: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x800BBC6C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800BBC70: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BBC74: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800BBC78: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BBC7C: addu        $t6, $a1, $t9
    ctx->r14 = ADD32(ctx->r5, ctx->r25);
    // 0x800BBC80: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BBC84: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BBC88: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBC8C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800BBC90: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BBC94: mul.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BBC98: blez        $t3, L_800BBD0C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BBC9C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800BBD0C;
    }
    // 0x800BBC9C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BBCA0: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BBCA4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800BBCA8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800BBCAC: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800BBCB0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800BBCB4: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x800BBCB8: jal         0x800BF4E4
    // 0x800BBCBC: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_1;
    // 0x800BBCBC: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x800BBCC0: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BBCC4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBCC8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BBCCC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BBCD0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBCD4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BBCD8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BBCDC: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BBCE0: lw          $t3, 0x3718($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3718);
    // 0x800BBCE4: lwc1        $f14, -0x5A38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800BBCE8: lw          $t2, 0x35D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35D4);
    // 0x800BBCEC: lw          $a1, 0x35D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X35D0);
    // 0x800BBCF0: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BBCF4: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800BBCF8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800BBCFC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800BBD00: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800BBD04: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BBD08: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_800BBD0C:
    // 0x800BBD0C: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBD10: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800BBD14: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BBD18: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBD1C: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800BBD20: mflo        $t6
    ctx->r14 = lo;
    // 0x800BBD24: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800BBD28: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x800BBD2C: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBD30: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x800BBD34: nop

    // 0x800BBD38: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BBD3C: mflo        $a2
    ctx->r6 = lo;
    // 0x800BBD40: addu        $a0, $t0, $a2
    ctx->r4 = ADD32(ctx->r8, ctx->r6);
    // 0x800BBD44: beq         $at, $zero, L_800BBD6C
    if (ctx->r1 == 0) {
        // 0x800BBD48: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800BBD6C;
    }
    // 0x800BBD48: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BBD4C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800BBD50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBD54: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBD58: lwc1        $f4, -0x5A34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BBD5C: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BBD60: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BBD64: mul.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800BBD68: nop

L_800BBD6C:
    // 0x800BBD6C: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBD70: bne         $at, $zero, L_800BBD80
    if (ctx->r1 != 0) {
        // 0x800BBD74: nop
    
            goto L_800BBD80;
    }
    // 0x800BBD74: nop

    // 0x800BBD78: b           L_800BBD80
    // 0x800BBD7C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
        goto L_800BBD80;
    // 0x800BBD7C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_800BBD80:
    // 0x800BBD80: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BBD84: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x800BBD88: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800BBD8C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800BBD90: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BBD94: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800BBD98: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BBD9C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800BBDA0: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BBDA4: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BBDA8: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BBDAC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BBDB0: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BBDB4: mul.s       $f2, $f8, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BBDB8: blez        $t3, L_800BBDF4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BBDBC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800BBDF4;
    }
    // 0x800BBDBC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BBDC0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBDC4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800BBDC8: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x800BBDCC: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x800BBDD0: jal         0x800BF4E4
    // 0x800BBDD4: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_2;
    // 0x800BBDD4: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x800BBDD8: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800BBDDC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BBDE0: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BBDE4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800BBDE8: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BBDEC: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BBDF0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
L_800BBDF4:
    // 0x800BBDF4: addu        $t9, $t4, $ra
    ctx->r25 = ADD32(ctx->r12, ctx->r31);
    // 0x800BBDF8: lbu         $v0, 0x1($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X1);
    // 0x800BBDFC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBE00: lw          $v1, -0x5A50($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A50);
    // 0x800BBE04: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BBE08: beq         $at, $zero, L_800BBE30
    if (ctx->r1 == 0) {
        // 0x800BBE0C: nop
    
            goto L_800BBE30;
    }
    // 0x800BBE0C: nop

    // 0x800BBE10: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800BBE14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBE18: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BBE1C: lwc1        $f10, -0x5A34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BBE20: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800BBE24: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800BBE28: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800BBE2C: nop

L_800BBE30:
    // 0x800BBE30: beq         $v1, $zero, L_800BBE5C
    if (ctx->r3 == 0) {
        // 0x800BBE34: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800BBE5C;
    }
    // 0x800BBE34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BBE38: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBE3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BBE40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BBE44: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BBE48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BBE4C: mul.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800BBE50: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x800BBE54: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800BBE58: nop

L_800BBE5C:
    // 0x800BBE5C: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBE60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BBE64: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BBE68: sub.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800BBE6C: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
    // 0x800BBE70: mul.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800BBE74: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BBE78: nop

    // 0x800BBE7C: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BBE80: sub.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800BBE84: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BBE88: b           L_800BC220
    // 0x800BBE8C: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
        goto L_800BC220;
    // 0x800BBE8C: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
L_800BBE90:
    // 0x800BBE90: bne         $at, $zero, L_800BBEA8
    if (ctx->r1 != 0) {
        // 0x800BBE94: nop
    
            goto L_800BBEA8;
    }
    // 0x800BBE94: nop

    // 0x800BBE98: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBE9C: mflo        $a0
    ctx->r4 = lo;
    // 0x800BBEA0: b           L_800BBEB8
    // 0x800BBEA4: nop

        goto L_800BBEB8;
    // 0x800BBEA4: nop

L_800BBEA8:
    // 0x800BBEA8: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBEAC: mflo        $t6
    ctx->r14 = lo;
    // 0x800BBEB0: addu        $a0, $t0, $t6
    ctx->r4 = ADD32(ctx->r8, ctx->r14);
    // 0x800BBEB4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800BBEB8:
    // 0x800BBEB8: lw          $t2, 0x35D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35D4);
    // 0x800BBEBC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800BBEC0: addu        $v0, $t2, $t7
    ctx->r2 = ADD32(ctx->r10, ctx->r15);
    // 0x800BBEC4: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x800BBEC8: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800BBECC: lw          $a1, 0x35D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X35D0);
    // 0x800BBED0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BBED4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BBED8: addu        $t6, $a1, $t9
    ctx->r14 = ADD32(ctx->r5, ctx->r25);
    // 0x800BBEDC: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800BBEE0: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BBEE4: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BBEE8: lwc1        $f14, 0x40($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X40);
    // 0x800BBEEC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BBEF0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BBEF4: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800BBEF8: lw          $t3, 0x3718($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3718);
    // 0x800BBEFC: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BBF00: blez        $t3, L_800BBF6C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BBF04: swc1        $f10, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
            goto L_800BBF6C;
    }
    // 0x800BBF04: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x800BBF08: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BBF0C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBF10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BBF14: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800BBF18: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800BBF1C: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x800BBF20: jal         0x800BF4E4
    // 0x800BBF24: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    waves_get_y(rdram, ctx);
        goto after_3;
    // 0x800BBF24: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_3:
    // 0x800BBF28: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBF2C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBF30: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800BBF34: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BBF38: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BBF3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBF40: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BBF44: lw          $t3, 0x3718($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3718);
    // 0x800BBF48: lwc1        $f14, -0x5A38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800BBF4C: lw          $t2, 0x35D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35D4);
    // 0x800BBF50: lw          $a1, 0x35D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X35D0);
    // 0x800BBF54: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BBF58: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800BBF5C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800BBF60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BBF64: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BBF68: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
L_800BBF6C:
    // 0x800BBF6C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBF70: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800BBF74: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800BBF78: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBF7C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800BBF80: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BBF84: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x800BBF88: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BBF8C: addiu       $t1, $a3, 0x1
    ctx->r9 = ADD32(ctx->r7, 0X1);
    // 0x800BBF90: mflo        $t6
    ctx->r14 = lo;
    // 0x800BBF94: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800BBF98: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x800BBF9C: lbu         $v0, 0x1($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X1);
    // 0x800BBFA0: nop

    // 0x800BBFA4: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BBFA8: beq         $at, $zero, L_800BBFD8
    if (ctx->r1 == 0) {
        // 0x800BBFAC: slt         $at, $t1, $v1
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BBFD8;
    }
    // 0x800BBFAC: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBFB0: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800BBFB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBFB8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBFBC: lwc1        $f6, -0x5A34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BBFC0: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800BBFC4: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBFC8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800BBFCC: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BBFD0: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x800BBFD4: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
L_800BBFD8:
    // 0x800BBFD8: bne         $at, $zero, L_800BBFE8
    if (ctx->r1 != 0) {
        // 0x800BBFDC: nop
    
            goto L_800BBFE8;
    }
    // 0x800BBFDC: nop

    // 0x800BBFE0: b           L_800BBFF8
    // 0x800BBFE4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_800BBFF8;
    // 0x800BBFE4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800BBFE8:
    // 0x800BBFE8: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBFEC: mflo        $t9
    ctx->r25 = lo;
    // 0x800BBFF0: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800BBFF4: nop

L_800BBFF8:
    // 0x800BBFF8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BBFFC: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x800BC000: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800BC004: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800BC008: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BC00C: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800BC010: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BC014: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800BC018: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BC01C: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BC020: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BC024: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800BC028: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BC02C: mul.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800BC030: blez        $t3, L_800BC09C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BC034: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800BC09C;
    }
    // 0x800BC034: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BC038: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BC03C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BC040: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800BC044: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800BC048: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x800BC04C: jal         0x800BF4E4
    // 0x800BC050: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_4;
    // 0x800BC050: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x800BC054: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BC058: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC05C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BC060: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BC064: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC068: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BC06C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BC070: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BC074: lw          $t3, 0x3718($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3718);
    // 0x800BC078: lwc1        $f14, -0x5A38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800BC07C: lw          $t2, 0x35D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35D4);
    // 0x800BC080: lw          $a1, 0x35D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X35D0);
    // 0x800BC084: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BC088: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800BC08C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800BC090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BC094: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BC098: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_800BC09C:
    // 0x800BC09C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BC0A0: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800BC0A4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BC0A8: multu       $a2, $t9
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC0AC: or          $a0, $ra, $zero
    ctx->r4 = ctx->r31 | 0;
    // 0x800BC0B0: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC0B4: addu        $a3, $t5, $t6
    ctx->r7 = ADD32(ctx->r13, ctx->r14);
    // 0x800BC0B8: addu        $t7, $t4, $a3
    ctx->r15 = ADD32(ctx->r12, ctx->r7);
    // 0x800BC0BC: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800BC0C0: nop

    // 0x800BC0C4: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BC0C8: beq         $at, $zero, L_800BC0F4
    if (ctx->r1 == 0) {
        // 0x800BC0CC: slt         $at, $ra, $v1
        ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BC0F4;
    }
    // 0x800BC0CC: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC0D0: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800BC0D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC0D8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BC0DC: lwc1        $f6, -0x5A34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BC0E0: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800BC0E4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800BC0E8: mul.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800BC0EC: nop

    // 0x800BC0F0: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
L_800BC0F4:
    // 0x800BC0F4: bne         $at, $zero, L_800BC104
    if (ctx->r1 != 0) {
        // 0x800BC0F8: nop
    
            goto L_800BC104;
    }
    // 0x800BC0F8: nop

    // 0x800BC0FC: b           L_800BC104
    // 0x800BC100: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800BC104;
    // 0x800BC100: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BC104:
    // 0x800BC104: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC108: beq         $at, $zero, L_800BC124
    if (ctx->r1 == 0) {
        // 0x800BC10C: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_800BC124;
    }
    // 0x800BC10C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800BC110: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC114: mflo        $t8
    ctx->r24 = lo;
    // 0x800BC118: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800BC11C: nop

    // 0x800BC120: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
L_800BC124:
    // 0x800BC124: addu        $v0, $t2, $t9
    ctx->r2 = ADD32(ctx->r10, ctx->r25);
    // 0x800BC128: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x800BC12C: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800BC130: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BC134: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800BC138: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BC13C: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800BC140: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BC144: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BC148: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BC14C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BC150: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BC154: mul.s       $f2, $f10, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800BC158: blez        $t3, L_800BC190
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BC15C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800BC190;
    }
    // 0x800BC15C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BC160: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800BC164: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x800BC168: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x800BC16C: jal         0x800BF4E4
    // 0x800BC170: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_5;
    // 0x800BC170: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x800BC174: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800BC178: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BC17C: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BC180: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800BC184: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BC188: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BC18C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
L_800BC190:
    // 0x800BC190: addu        $t8, $t4, $a3
    ctx->r24 = ADD32(ctx->r12, ctx->r7);
    // 0x800BC194: lbu         $v0, 0x1($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X1);
    // 0x800BC198: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC19C: lw          $v1, -0x5A50($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A50);
    // 0x800BC1A0: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BC1A4: beq         $at, $zero, L_800BC1CC
    if (ctx->r1 == 0) {
        // 0x800BC1A8: nop
    
            goto L_800BC1CC;
    }
    // 0x800BC1A8: nop

    // 0x800BC1AC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800BC1B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC1B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BC1B8: lwc1        $f8, -0x5A34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BC1BC: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BC1C0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BC1C4: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800BC1C8: nop

L_800BC1CC:
    // 0x800BC1CC: beq         $v1, $zero, L_800BC1F8
    if (ctx->r3 == 0) {
        // 0x800BC1D0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800BC1F8;
    }
    // 0x800BC1D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BC1D4: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BC1D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BC1DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BC1E0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BC1E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BC1E8: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800BC1EC: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x800BC1F0: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800BC1F4: nop

L_800BC1F8:
    // 0x800BC1F8: sub.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x800BC1FC: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BC200: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BC204: mul.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800BC208: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BC20C: swc1        $f8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f8.u32l;
    // 0x800BC210: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800BC214: sub.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800BC218: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BC21C: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
L_800BC220:
    // 0x800BC220: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800BC224: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    // 0x800BC228: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x800BC22C: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x800BC230: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800BC234: nop

    // 0x800BC238: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800BC23C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BC240: jal         0x800CA030
    // 0x800BC244: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x800BC244: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_6:
    // 0x800BC248: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800BC24C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800BC250: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800BC254: c.eq.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d == ctx->f4.d;
    // 0x800BC258: lwc1        $f14, 0x88($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800BC25C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800BC260: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800BC264: bc1t        L_800BC2D4
    if (c1cs) {
        // 0x800BC268: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800BC2D4;
    }
    // 0x800BC268: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x800BC26C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x800BC270: c.eq.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d == ctx->f6.d;
    // 0x800BC274: nop

    // 0x800BC278: bc1t        L_800BC2D0
    if (c1cs) {
        // 0x800BC27C: nop
    
            goto L_800BC2D0;
    }
    // 0x800BC27C: nop

    // 0x800BC280: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800BC284: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BC288: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BC28C: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BC290: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800BC294: nop

    // 0x800BC298: div.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800BC29C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800BC2A0: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800BC2A4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800BC2A8: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BC2AC: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800BC2B0: swc1        $f2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f2.u32l;
    // 0x800BC2B4: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BC2B8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800BC2BC: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800BC2C0: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800BC2C4: div.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BC2C8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800BC2CC: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
L_800BC2D0:
    // 0x800BC2D0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_800BC2D4:
    // 0x800BC2D4: lwc1        $f2, 0x84($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800BC2D8: beq         $t9, $zero, L_800BC2F0
    if (ctx->r25 == 0) {
        // 0x800BC2DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BC2F0;
    }
    // 0x800BC2DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BC2E0: swc1        $f14, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f14.u32l;
    // 0x800BC2E4: swc1        $f2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f2.u32l;
    // 0x800BC2E8: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
    // 0x800BC2EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BC2F0:
    // 0x800BC2F0: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800BC2F4: jr          $ra
    // 0x800BC2F8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800BC2F8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_800BBDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC2FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BC300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BC304: jal         0x800BC328
    // 0x800BC308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800BBE08(rdram, ctx);
        goto after_0;
    // 0x800BC308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800BC30C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BC310: jal         0x800BC498
    // 0x800BC314: nop

    func_800BBF78(rdram, ctx);
        goto after_1;
    // 0x800BC314: nop

    after_1:
    // 0x800BC318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BC31C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BC320: jr          $ra
    // 0x800BC324: nop

    return;
    // 0x800BC324: nop

;}
RECOMP_FUNC void func_800BBE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC328: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800BC32C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800BC330: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800BC334: lh          $a2, 0x1A($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X1A);
    // 0x800BC338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BC33C: blez        $a2, L_800BC3CC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BC340: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BC3CC;
    }
    // 0x800BC340: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BC344: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800BC348: sll         $t7, $zero, 6
    ctx->r15 = S32(0 << 6);
    // 0x800BC34C: lui         $s1, 0x100
    ctx->r17 = S32(0X100 << 16);
    // 0x800BC350: lui         $s0, 0x100
    ctx->r16 = S32(0X100 << 16);
    // 0x800BC354: ori         $s0, $s0, 0x2000
    ctx->r16 = ctx->r16 | 0X2000;
    // 0x800BC358: ori         $s1, $s1, 0x2100
    ctx->r17 = ctx->r17 | 0X2100;
    // 0x800BC35C: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x800BC360: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_800BC364:
    // 0x800BC364: bne         $v0, $zero, L_800BC3B4
    if (ctx->r2 != 0) {
        // 0x800BC368: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_800BC3B4;
    }
    // 0x800BC368: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800BC36C: lh          $t2, 0x20($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X20);
    // 0x800BC370: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x800BC374: blez        $t2, L_800BC3B4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800BC378: subu        $t4, $t4, $zero
        ctx->r12 = SUB32(ctx->r12, 0);
            goto L_800BC3B4;
    }
    // 0x800BC378: subu        $t4, $t4, $zero
    ctx->r12 = SUB32(ctx->r12, 0);
    // 0x800BC37C: lw          $t3, 0xC($a3)
    ctx->r11 = MEM_W(ctx->r7, 0XC);
    // 0x800BC380: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BC384: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
L_800BC388:
    // 0x800BC388: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x800BC38C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800BC390: and         $t9, $t8, $s1
    ctx->r25 = ctx->r24 & ctx->r17;
    // 0x800BC394: bne         $s0, $t9, L_800BC3A0
    if (ctx->r16 != ctx->r25) {
        // 0x800BC398: addiu       $t5, $t5, 0xC
        ctx->r13 = ADD32(ctx->r13, 0XC);
            goto L_800BC3A0;
    }
    // 0x800BC398: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x800BC39C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_800BC3A0:
    // 0x800BC3A0: bne         $v0, $zero, L_800BC3B4
    if (ctx->r2 != 0) {
        // 0x800BC3A4: addiu       $t4, $t4, 0xC
        ctx->r12 = ADD32(ctx->r12, 0XC);
            goto L_800BC3B4;
    }
    // 0x800BC3A4: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x800BC3A8: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BC3AC: bne         $at, $zero, L_800BC388
    if (ctx->r1 != 0) {
        // 0x800BC3B0: nop
    
            goto L_800BC388;
    }
    // 0x800BC3B0: nop

L_800BC3B4:
    // 0x800BC3B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BC3B8: bne         $v0, $zero, L_800BC3CC
    if (ctx->r2 != 0) {
        // 0x800BC3BC: addiu       $t0, $t0, 0x44
        ctx->r8 = ADD32(ctx->r8, 0X44);
            goto L_800BC3CC;
    }
    // 0x800BC3BC: addiu       $t0, $t0, 0x44
    ctx->r8 = ADD32(ctx->r8, 0X44);
    // 0x800BC3C0: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BC3C4: bne         $at, $zero, L_800BC364
    if (ctx->r1 != 0) {
        // 0x800BC3C8: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_800BC364;
    }
    // 0x800BC3C8: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_800BC3CC:
    // 0x800BC3CC: bne         $v0, $zero, L_800BC3DC
    if (ctx->r2 != 0) {
        // 0x800BC3D0: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_800BC3DC;
    }
    // 0x800BC3D0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800BC3D4: b           L_800BC3DC
    // 0x800BC3D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800BC3DC;
    // 0x800BC3D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800BC3DC:
    // 0x800BC3DC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800BC3E0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800BC3E4: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x800BC3E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BC3EC: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x800BC3F0: lh          $t8, 0x6($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X6);
    // 0x800BC3F4: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800BC3F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC3FC: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x800BC400: sw          $t6, -0x5998($at)
    MEM_W(-0X5998, ctx->r1) = ctx->r14;
    // 0x800BC404: lh          $t8, 0x4($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X4);
    // 0x800BC408: lh          $t7, 0xA($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XA);
    // 0x800BC40C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC410: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800BC414: sw          $t9, -0x5994($at)
    MEM_W(-0X5994, ctx->r1) = ctx->r25;
    // 0x800BC418: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800BC41C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC420: sw          $t6, -0x5990($at)
    MEM_W(-0X5990, ctx->r1) = ctx->r14;
    // 0x800BC424: lh          $t7, 0x4($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X4);
    // 0x800BC428: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC42C: sw          $t7, -0x598C($at)
    MEM_W(-0X598C, ctx->r1) = ctx->r15;
    // 0x800BC430: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC434: sw          $v0, -0x59C4($at)
    MEM_W(-0X59C4, ctx->r1) = ctx->r2;
    // 0x800BC438: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800BC43C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800BC440: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800BC444: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800BC448: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BC44C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC450: sw          $t9, -0x59C0($at)
    MEM_W(-0X59C0, ctx->r1) = ctx->r25;
    // 0x800BC454: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x800BC458: lui         $at, 0x7000
    ctx->r1 = S32(0X7000 << 16);
    // 0x800BC45C: and         $t8, $a3, $at
    ctx->r24 = ctx->r7 & ctx->r1;
    // 0x800BC460: srl         $t6, $t8, 28
    ctx->r14 = S32(U32(ctx->r24) >> 28);
    // 0x800BC464: blez        $t6, L_800BC484
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BC468: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800BC484;
    }
    // 0x800BC468: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC46C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BC470: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x800BC474: lw          $t8, 0x70($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X70);
    // 0x800BC478: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC47C: b           L_800BC488
    // 0x800BC480: sw          $t8, 0x3710($at)
    MEM_W(0X3710, ctx->r1) = ctx->r24;
        goto L_800BC488;
    // 0x800BC480: sw          $t8, 0x3710($at)
    MEM_W(0X3710, ctx->r1) = ctx->r24;
L_800BC484:
    // 0x800BC484: sw          $zero, 0x3710($at)
    MEM_W(0X3710, ctx->r1) = 0;
L_800BC488:
    // 0x800BC488: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800BC48C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800BC490: jr          $ra
    // 0x800BC494: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800BC494: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800BBF78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC498: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BC49C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800BC4A0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800BC4A4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800BC4A8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800BC4AC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800BC4B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800BC4B4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800BC4B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800BC4BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800BC4C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BC4C4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800BC4C8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BC4CC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BC4D0: lw          $t7, -0x5A78($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5A78);
    // 0x800BC4D4: lw          $t8, -0x5A50($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5A50);
    // 0x800BC4D8: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800BC4DC: lw          $s4, 0x8($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X8);
    // 0x800BC4E0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800BC4E4: beq         $t8, $zero, L_800BC4F4
    if (ctx->r24 == 0) {
        // 0x800BC4E8: sw          $t7, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r15;
            goto L_800BC4F4;
    }
    // 0x800BC4E8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x800BC4EC: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800BC4F0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_800BC4F4:
    // 0x800BC4F4: lh          $t6, 0x0($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X0);
    // 0x800BC4F8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC4FC: addiu       $v1, $v1, -0x5980
    ctx->r3 = ADD32(ctx->r3, -0X5980);
    // 0x800BC500: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BC504: lh          $t8, 0x6($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X6);
    // 0x800BC508: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BC50C: addiu       $a0, $a0, -0x5978
    ctx->r4 = ADD32(ctx->r4, -0X5978);
    // 0x800BC510: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800BC514: lh          $t7, 0x4($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X4);
    // 0x800BC518: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800BC51C: addiu       $a2, $a2, -0x597C
    ctx->r6 = ADD32(ctx->r6, -0X597C);
    // 0x800BC520: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800BC524: lh          $t9, 0xA($s4)
    ctx->r25 = MEM_H(ctx->r20, 0XA);
    // 0x800BC528: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800BC52C: addiu       $t1, $t1, -0x5974
    ctx->r9 = ADD32(ctx->r9, -0X5974);
    // 0x800BC530: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800BC534: lh          $t6, 0x1A($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC538: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x800BC53C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800BC540: bne         $at, $zero, L_800BC5CC
    if (ctx->r1 != 0) {
        // 0x800BC544: lui         $s6, 0x8013
        ctx->r22 = S32(0X8013 << 16);
            goto L_800BC5CC;
    }
    // 0x800BC544: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800BC548: addiu       $s0, $s4, 0xC
    ctx->r16 = ADD32(ctx->r20, 0XC);
L_800BC54C:
    // 0x800BC54C: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800BC550: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800BC554: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x800BC558: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BC55C: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x800BC560: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BC564: beq         $at, $zero, L_800BC570
    if (ctx->r1 == 0) {
        // 0x800BC568: nop
    
            goto L_800BC570;
    }
    // 0x800BC568: nop

    // 0x800BC56C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800BC570:
    // 0x800BC570: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x800BC574: nop

    // 0x800BC578: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BC57C: beq         $at, $zero, L_800BC588
    if (ctx->r1 == 0) {
        // 0x800BC580: nop
    
            goto L_800BC588;
    }
    // 0x800BC580: nop

    // 0x800BC584: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_800BC588:
    // 0x800BC588: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x800BC58C: nop

    // 0x800BC590: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800BC594: beq         $at, $zero, L_800BC5A0
    if (ctx->r1 == 0) {
        // 0x800BC598: nop
    
            goto L_800BC5A0;
    }
    // 0x800BC598: nop

    // 0x800BC59C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_800BC5A0:
    // 0x800BC5A0: lh          $v0, 0xA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA);
    // 0x800BC5A4: nop

    // 0x800BC5A8: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BC5AC: beq         $at, $zero, L_800BC5B8
    if (ctx->r1 == 0) {
        // 0x800BC5B0: nop
    
            goto L_800BC5B8;
    }
    // 0x800BC5B0: nop

    // 0x800BC5B4: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_800BC5B8:
    // 0x800BC5B8: lh          $t7, 0x1A($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC5BC: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BC5C0: slt         $at, $ra, $t7
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BC5C4: bne         $at, $zero, L_800BC54C
    if (ctx->r1 != 0) {
        // 0x800BC5C8: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800BC54C;
    }
    // 0x800BC5C8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_800BC5CC:
    // 0x800BC5CC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BC5D0: lw          $a0, -0x5990($t9)
    ctx->r4 = MEM_W(ctx->r25, -0X5990);
    // 0x800BC5D4: addiu       $s6, $s6, -0x5970
    ctx->r22 = ADD32(ctx->r22, -0X5970);
    // 0x800BC5D8: sw          $a0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r4;
    // 0x800BC5DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BC5E0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BC5E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BC5E8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800BC5EC: lw          $t0, -0x5974($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5974);
    // 0x800BC5F0: lw          $a1, -0x597C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X597C);
    // 0x800BC5F4: lw          $a3, -0x5978($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5978);
    // 0x800BC5F8: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BC5FC: beq         $at, $zero, L_800BC624
    if (ctx->r1 == 0) {
        // 0x800BC600: lui         $s5, 0x8013
        ctx->r21 = S32(0X8013 << 16);
            goto L_800BC624;
    }
    // 0x800BC600: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800BC604: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800BC608: lw          $a2, -0x5998($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5998);
    // 0x800BC60C: nop

L_800BC610:
    // 0x800BC610: subu        $t6, $a0, $a2
    ctx->r14 = SUB32(ctx->r4, ctx->r6);
    // 0x800BC614: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BC618: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x800BC61C: bne         $at, $zero, L_800BC610
    if (ctx->r1 != 0) {
        // 0x800BC620: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800BC610;
    }
    // 0x800BC620: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_800BC624:
    // 0x800BC624: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BC628: lw          $t8, -0x598C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X598C);
    // 0x800BC62C: addiu       $s5, $s5, -0x596C
    ctx->r21 = ADD32(ctx->r21, -0X596C);
    // 0x800BC630: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800BC634: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x800BC638: lw          $a2, -0x5998($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5998);
    // 0x800BC63C: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BC640: beq         $at, $zero, L_800BC668
    if (ctx->r1 == 0) {
        // 0x800BC644: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800BC668;
    }
    // 0x800BC644: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800BC648: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC64C: lw          $v1, -0x5994($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5994);
    // 0x800BC650: nop

L_800BC654:
    // 0x800BC654: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x800BC658: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BC65C: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x800BC660: bne         $at, $zero, L_800BC654
    if (ctx->r1 != 0) {
        // 0x800BC664: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800BC654;
    }
    // 0x800BC664: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800BC668:
    // 0x800BC668: subu        $t9, $a3, $a0
    ctx->r25 = SUB32(ctx->r7, ctx->r4);
    // 0x800BC66C: div         $zero, $t9, $a2
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r6)));
    // 0x800BC670: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800BC674: addiu       $fp, $fp, -0x5994
    ctx->r30 = ADD32(ctx->r30, -0X5994);
    // 0x800BC678: subu        $t7, $t0, $v0
    ctx->r15 = SUB32(ctx->r8, ctx->r2);
    // 0x800BC67C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800BC680: addiu       $s7, $s7, -0x5968
    ctx->r23 = ADD32(ctx->r23, -0X5968);
    // 0x800BC684: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800BC688: addiu       $s2, $s2, 0x3664
    ctx->r18 = ADD32(ctx->r18, 0X3664);
    // 0x800BC68C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800BC690: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800BC694: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800BC698: addiu       $s1, $s1, -0x5964
    ctx->r17 = ADD32(ctx->r17, -0X5964);
    // 0x800BC69C: addiu       $s0, $s0, 0x371C
    ctx->r16 = ADD32(ctx->r16, 0X371C);
    // 0x800BC6A0: bne         $a2, $zero, L_800BC6AC
    if (ctx->r6 != 0) {
        // 0x800BC6A4: nop
    
            goto L_800BC6AC;
    }
    // 0x800BC6A4: nop

    // 0x800BC6A8: break       7
    do_break(2148255400);
L_800BC6AC:
    // 0x800BC6AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC6B0: bne         $a2, $at, L_800BC6C4
    if (ctx->r6 != ctx->r1) {
        // 0x800BC6B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC6C4;
    }
    // 0x800BC6B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC6B8: bne         $t9, $at, L_800BC6C4
    if (ctx->r25 != ctx->r1) {
        // 0x800BC6BC: nop
    
            goto L_800BC6C4;
    }
    // 0x800BC6BC: nop

    // 0x800BC6C0: break       6
    do_break(2148255424);
L_800BC6C4:
    // 0x800BC6C4: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800BC6C8: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC6CC: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800BC6D0: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x800BC6D4: div         $zero, $t7, $t9
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r25)));
    // 0x800BC6D8: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x800BC6DC: bne         $t9, $zero, L_800BC6E8
    if (ctx->r25 != 0) {
        // 0x800BC6E0: nop
    
            goto L_800BC6E8;
    }
    // 0x800BC6E0: nop

    // 0x800BC6E4: break       7
    do_break(2148255460);
L_800BC6E8:
    // 0x800BC6E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC6EC: bne         $t9, $at, L_800BC700
    if (ctx->r25 != ctx->r1) {
        // 0x800BC6F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC700;
    }
    // 0x800BC6F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC6F4: bne         $t7, $at, L_800BC700
    if (ctx->r15 != ctx->r1) {
        // 0x800BC6F8: nop
    
            goto L_800BC700;
    }
    // 0x800BC6F8: nop

    // 0x800BC6FC: break       6
    do_break(2148255484);
L_800BC700:
    // 0x800BC700: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800BC704: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC708: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800BC70C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BC710: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC714: mflo        $t9
    ctx->r25 = lo;
    // 0x800BC718: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BC71C: beq         $a1, $zero, L_800BC734
    if (ctx->r5 == 0) {
        // 0x800BC720: sw          $t6, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r14;
            goto L_800BC734;
    }
    // 0x800BC720: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800BC724: jal         0x80071380
    // 0x800BC728: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800BC728: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800BC72C: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x800BC730: nop

L_800BC734:
    // 0x800BC734: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800BC738: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800BC73C: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC740: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800BC744: mflo        $a0
    ctx->r4 = lo;
    // 0x800BC748: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800BC74C: jal         0x80070EDC
    // 0x800BC750: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800BC750: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x800BC754: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800BC758: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800BC75C: lw          $a0, 0x3668($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3668);
    // 0x800BC760: nop

    // 0x800BC764: beq         $a0, $zero, L_800BC774
    if (ctx->r4 == 0) {
        // 0x800BC768: nop
    
            goto L_800BC774;
    }
    // 0x800BC768: nop

    // 0x800BC76C: jal         0x80071380
    // 0x800BC770: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800BC770: nop

    after_2:
L_800BC774:
    // 0x800BC774: lh          $t9, 0x1A($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC778: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800BC77C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800BC780: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x800BC784: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BC788: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x800BC78C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800BC790: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800BC794: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800BC798: jal         0x80070EDC
    // 0x800BC79C: addiu       $a0, $a0, 0x880
    ctx->r4 = ADD32(ctx->r4, 0X880);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x800BC79C: addiu       $a0, $a0, 0x880
    ctx->r4 = ADD32(ctx->r4, 0X880);
    after_3:
    // 0x800BC7A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC7A4: sw          $v0, 0x3668($at)
    MEM_W(0X3668, ctx->r1) = ctx->r2;
    // 0x800BC7A8: lh          $t8, 0x1A($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC7AC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BC7B0: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x800BC7B4: lw          $t9, 0x3668($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3668);
    // 0x800BC7B8: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x800BC7BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BC7C0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BC7C4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800BC7C8: addiu       $a1, $a1, 0x3720
    ctx->r5 = ADD32(ctx->r5, 0X3720);
    // 0x800BC7CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800BC7D0: addiu       $t9, $t7, 0x800
    ctx->r25 = ADD32(ctx->r15, 0X800);
    // 0x800BC7D4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800BC7D8: addiu       $a0, $a0, 0x3724
    ctx->r4 = ADD32(ctx->r4, 0X3724);
    // 0x800BC7DC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800BC7E0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BC7E4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800BC7E8: addiu       $t7, $t9, 0x80
    ctx->r15 = ADD32(ctx->r25, 0X80);
    // 0x800BC7EC: addiu       $v1, $v1, 0x3714
    ctx->r3 = ADD32(ctx->r3, 0X3714);
    // 0x800BC7F0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BC7F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BC7F8: blez        $t9, L_800BC82C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BC7FC: or          $ra, $zero, $zero
        ctx->r31 = 0 | 0;
            goto L_800BC82C;
    }
    // 0x800BC7FC: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800BC800: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800BC804:
    // 0x800BC804: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800BC808: nop

    // 0x800BC80C: addu        $t7, $t6, $ra
    ctx->r15 = ADD32(ctx->r14, ctx->r31);
    // 0x800BC810: sb          $v0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r2;
    // 0x800BC814: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800BC818: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BC81C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BC820: slt         $at, $ra, $t9
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BC824: bne         $at, $zero, L_800BC804
    if (ctx->r1 != 0) {
        // 0x800BC828: nop
    
            goto L_800BC804;
    }
    // 0x800BC828: nop

L_800BC82C:
    // 0x800BC82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BC830:
    // 0x800BC830: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800BC834: nop

    // 0x800BC838: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800BC83C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC840: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800BC844: bne         $at, $zero, L_800BC830
    if (ctx->r1 != 0) {
        // 0x800BC848: sw          $zero, 0x0($t7)
        MEM_W(0X0, ctx->r15) = 0;
            goto L_800BC830;
    }
    // 0x800BC848: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800BC84C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC850: sw          $zero, 0x3718($at)
    MEM_W(0X3718, ctx->r1) = 0;
    // 0x800BC854: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800BC858: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800BC85C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800BC860: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC864: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC868: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800BC86C: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800BC870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BC874: addiu       $v1, $v1, -0x5858
    ctx->r3 = ADD32(ctx->r3, -0X5858);
    // 0x800BC878: addiu       $s4, $s4, -0x5998
    ctx->r20 = ADD32(ctx->r20, -0X5998);
    // 0x800BC87C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x800BC880: lui         $t3, 0x40
    ctx->r11 = S32(0X40 << 16);
    // 0x800BC884: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800BC888: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC88C: blez        $t6, L_800BC8C4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BC890: nop
    
            goto L_800BC8C4;
    }
    // 0x800BC890: nop

L_800BC894:
    // 0x800BC894: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800BC898: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BC89C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800BC8A0: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800BC8A4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BC8A8: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800BC8AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC8B0: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC8B4: mflo        $t7
    ctx->r15 = lo;
    // 0x800BC8B8: slt         $at, $ra, $t7
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BC8BC: bne         $at, $zero, L_800BC894
    if (ctx->r1 != 0) {
        // 0x800BC8C0: nop
    
            goto L_800BC894;
    }
    // 0x800BC8C0: nop

L_800BC8C4:
    // 0x800BC8C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BC8C8: addiu       $v0, $v0, -0x5958
    ctx->r2 = ADD32(ctx->r2, -0X5958);
L_800BC8CC:
    // 0x800BC8CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC8D0: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800BC8D4: bne         $at, $zero, L_800BC8CC
    if (ctx->r1 != 0) {
        // 0x800BC8D8: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_800BC8CC;
    }
    // 0x800BC8D8: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x800BC8DC: lh          $t9, 0x1A($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC8E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BC8E4: addiu       $v0, $v0, -0x5960
    ctx->r2 = ADD32(ctx->r2, -0X5960);
    // 0x800BC8E8: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800BC8EC: blez        $t9, L_800BCBB8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BC8F0: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_800BCBB8;
    }
    // 0x800BC8F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800BC8F4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800BC8F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BC8FC: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x800BC900: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800BC904:
    // 0x800BC904: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x800BC908: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800BC90C: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x800BC910: subu        $t1, $t7, $a0
    ctx->r9 = SUB32(ctx->r15, ctx->r4);
    // 0x800BC914: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800BC918: div         $zero, $t1, $a2
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r6)));
    // 0x800BC91C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x800BC920: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x800BC924: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x800BC928: subu        $t2, $t8, $v0
    ctx->r10 = SUB32(ctx->r24, ctx->r2);
    // 0x800BC92C: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x800BC930: bne         $a2, $zero, L_800BC93C
    if (ctx->r6 != 0) {
        // 0x800BC934: nop
    
            goto L_800BC93C;
    }
    // 0x800BC934: nop

    // 0x800BC938: break       7
    do_break(2148256056);
L_800BC93C:
    // 0x800BC93C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC940: bne         $a2, $at, L_800BC954
    if (ctx->r6 != ctx->r1) {
        // 0x800BC944: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC954;
    }
    // 0x800BC944: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC948: bne         $t1, $at, L_800BC954
    if (ctx->r9 != ctx->r1) {
        // 0x800BC94C: nop
    
            goto L_800BC954;
    }
    // 0x800BC94C: nop

    // 0x800BC950: break       6
    do_break(2148256080);
L_800BC954:
    // 0x800BC954: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800BC958: lh          $t5, 0x20($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X20);
    // 0x800BC95C: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BC960: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800BC964: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BC968: mflo        $t9
    ctx->r25 = lo;
    // 0x800BC96C: nop

    // 0x800BC970: nop

    // 0x800BC974: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC978: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC97C: addu        $t1, $t6, $a0
    ctx->r9 = ADD32(ctx->r14, ctx->r4);
    // 0x800BC980: nop

    // 0x800BC984: div         $zero, $t2, $v1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r3)));
    // 0x800BC988: bne         $v1, $zero, L_800BC994
    if (ctx->r3 != 0) {
        // 0x800BC98C: nop
    
            goto L_800BC994;
    }
    // 0x800BC98C: nop

    // 0x800BC990: break       7
    do_break(2148256144);
L_800BC994:
    // 0x800BC994: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC998: bne         $v1, $at, L_800BC9AC
    if (ctx->r3 != ctx->r1) {
        // 0x800BC99C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC9AC;
    }
    // 0x800BC99C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC9A0: bne         $t2, $at, L_800BC9AC
    if (ctx->r10 != ctx->r1) {
        // 0x800BC9A4: nop
    
            goto L_800BC9AC;
    }
    // 0x800BC9A4: nop

    // 0x800BC9A8: break       6
    do_break(2148256168);
L_800BC9AC:
    // 0x800BC9AC: mflo        $t7
    ctx->r15 = lo;
    // 0x800BC9B0: nop

    // 0x800BC9B4: nop

    // 0x800BC9B8: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC9BC: mflo        $t8
    ctx->r24 = lo;
    // 0x800BC9C0: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800BC9C4: blez        $t5, L_800BCA24
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800BC9C8: nop
    
            goto L_800BCA24;
    }
    // 0x800BC9C8: nop

    // 0x800BC9CC: sll         $a2, $t5, 2
    ctx->r6 = S32(ctx->r13 << 2);
    // 0x800BC9D0: subu        $a2, $a2, $t5
    ctx->r6 = SUB32(ctx->r6, ctx->r13);
    // 0x800BC9D4: lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XC);
    // 0x800BC9D8: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x800BC9DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800BC9E0:
    // 0x800BC9E0: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x800BC9E4: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800BC9E8: andi        $t9, $a0, 0x2000
    ctx->r25 = ctx->r4 & 0X2000;
    // 0x800BC9EC: beq         $t9, $zero, L_800BCA1C
    if (ctx->r25 == 0) {
        // 0x800BC9F0: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800BCA1C;
    }
    // 0x800BC9F0: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BC9F4: and         $t6, $a0, $t3
    ctx->r14 = ctx->r4 & ctx->r11;
    // 0x800BC9F8: beq         $t6, $zero, L_800BCA1C
    if (ctx->r14 == 0) {
        // 0x800BC9FC: nop
    
            goto L_800BCA1C;
    }
    // 0x800BC9FC: nop

    // 0x800BCA00: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x800BCA04: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BCA08: multu       $t8, $t4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCA0C: mflo        $t9
    ctx->r25 = lo;
    // 0x800BCA10: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800BCA14: lh          $a3, 0x2($t6)
    ctx->r7 = MEM_H(ctx->r14, 0X2);
    // 0x800BCA18: nop

L_800BCA1C:
    // 0x800BCA1C: bne         $at, $zero, L_800BC9E0
    if (ctx->r1 != 0) {
        // 0x800BCA20: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800BC9E0;
    }
    // 0x800BCA20: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_800BCA24:
    // 0x800BCA24: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800BCA28: lw          $t8, 0x3668($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3668);
    // 0x800BCA2C: addiu       $t0, $t0, 0x44
    ctx->r8 = ADD32(ctx->r8, 0X44);
    // 0x800BCA30: addu        $a0, $s2, $t8
    ctx->r4 = ADD32(ctx->r18, ctx->r24);
    // 0x800BCA34: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x800BCA38: sh          $t1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r9;
    // 0x800BCA3C: sh          $a3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r7;
    // 0x800BCA40: sh          $t2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r10;
    // 0x800BCA44: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800BCA48: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800BCA4C: subu        $t9, $t1, $t7
    ctx->r25 = SUB32(ctx->r9, ctx->r15);
    // 0x800BCA50: div         $zero, $t9, $t6
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r14)));
    // 0x800BCA54: bne         $t6, $zero, L_800BCA60
    if (ctx->r14 != 0) {
        // 0x800BCA58: nop
    
            goto L_800BCA60;
    }
    // 0x800BCA58: nop

    // 0x800BCA5C: break       7
    do_break(2148256348);
L_800BCA60:
    // 0x800BCA60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BCA64: bne         $t6, $at, L_800BCA78
    if (ctx->r14 != ctx->r1) {
        // 0x800BCA68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BCA78;
    }
    // 0x800BCA68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BCA6C: bne         $t9, $at, L_800BCA78
    if (ctx->r25 != ctx->r1) {
        // 0x800BCA70: nop
    
            goto L_800BCA78;
    }
    // 0x800BCA70: nop

    // 0x800BCA74: break       6
    do_break(2148256372);
L_800BCA78:
    // 0x800BCA78: mflo        $t8
    ctx->r24 = lo;
    // 0x800BCA7C: sb          $t8, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r24;
    // 0x800BCA80: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800BCA84: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x800BCA88: subu        $t9, $t2, $t7
    ctx->r25 = SUB32(ctx->r10, ctx->r15);
    // 0x800BCA8C: div         $zero, $t9, $t6
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r14)));
    // 0x800BCA90: lbu         $a2, 0xA($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0XA);
    // 0x800BCA94: bne         $t6, $zero, L_800BCAA0
    if (ctx->r14 != 0) {
        // 0x800BCA98: nop
    
            goto L_800BCAA0;
    }
    // 0x800BCA98: nop

    // 0x800BCA9C: break       7
    do_break(2148256412);
L_800BCAA0:
    // 0x800BCAA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BCAA4: bne         $t6, $at, L_800BCAB8
    if (ctx->r14 != ctx->r1) {
        // 0x800BCAA8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BCAB8;
    }
    // 0x800BCAA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BCAAC: bne         $t9, $at, L_800BCAB8
    if (ctx->r25 != ctx->r1) {
        // 0x800BCAB0: nop
    
            goto L_800BCAB8;
    }
    // 0x800BCAB0: nop

    // 0x800BCAB4: break       6
    do_break(2148256436);
L_800BCAB8:
    // 0x800BCAB8: mflo        $t8
    ctx->r24 = lo;
    // 0x800BCABC: sb          $t8, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r24;
    // 0x800BCAC0: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800BCAC4: andi        $s1, $t8, 0xFF
    ctx->r17 = ctx->r24 & 0XFF;
    // 0x800BCAC8: multu       $s1, $t7
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCACC: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x800BCAD0: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x800BCAD4: or          $t5, $s1, $zero
    ctx->r13 = ctx->r17 | 0;
    // 0x800BCAD8: mflo        $t9
    ctx->r25 = lo;
    // 0x800BCADC: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x800BCAE0: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x800BCAE4: lb          $t8, -0x19($t0)
    ctx->r24 = MEM_B(ctx->r8, -0X19);
    // 0x800BCAE8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800BCAEC: beq         $t8, $zero, L_800BCB80
    if (ctx->r24 == 0) {
        // 0x800BCAF0: nop
    
            goto L_800BCB80;
    }
    // 0x800BCAF0: nop

    // 0x800BCAF4: multu       $a2, $t7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCAF8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BCAFC: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BCB00: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BCB04: addiu       $t8, $t8, -0x5958
    ctx->r24 = ADD32(ctx->r24, -0X5958);
    // 0x800BCB08: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800BCB0C: mflo        $v0
    ctx->r2 = lo;
    // 0x800BCB10: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCB14: bne         $at, $zero, L_800BCB2C
    if (ctx->r1 != 0) {
        // 0x800BCB18: nop
    
            goto L_800BCB2C;
    }
    // 0x800BCB18: nop

L_800BCB1C:
    // 0x800BCB1C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800BCB20: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCB24: beq         $at, $zero, L_800BCB1C
    if (ctx->r1 == 0) {
        // 0x800BCB28: nop
    
            goto L_800BCB1C;
    }
    // 0x800BCB28: nop

L_800BCB2C:
    // 0x800BCB2C: sh          $v0, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r2;
    // 0x800BCB30: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800BCB34: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BCB38: multu       $t5, $t9
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCB3C: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BCB40: mflo        $v0
    ctx->r2 = lo;
    // 0x800BCB44: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCB48: bne         $at, $zero, L_800BCB60
    if (ctx->r1 != 0) {
        // 0x800BCB4C: nop
    
            goto L_800BCB60;
    }
    // 0x800BCB4C: nop

L_800BCB50:
    // 0x800BCB50: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800BCB54: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCB58: beq         $at, $zero, L_800BCB50
    if (ctx->r1 == 0) {
        // 0x800BCB5C: nop
    
            goto L_800BCB50;
    }
    // 0x800BCB5C: nop

L_800BCB60:
    // 0x800BCB60: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x800BCB64: lbu         $t9, 0xA($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XA);
    // 0x800BCB68: sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // 0x800BCB6C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800BCB70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800BCB74: sllv        $t8, $t6, $t9
    ctx->r24 = S32(ctx->r14 << (ctx->r25 & 31));
    // 0x800BCB78: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800BCB7C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800BCB80:
    // 0x800BCB80: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BCB84: sb          $a1, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r5;
    // 0x800BCB88: sb          $a1, 0x19($a0)
    MEM_B(0X19, ctx->r4) = ctx->r5;
    // 0x800BCB8C: sb          $a1, 0x16($a0)
    MEM_B(0X16, ctx->r4) = ctx->r5;
    // 0x800BCB90: sb          $a1, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r5;
    // 0x800BCB94: sb          $a1, 0x17($a0)
    MEM_B(0X17, ctx->r4) = ctx->r5;
    // 0x800BCB98: sb          $a1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r5;
    // 0x800BCB9C: sb          $a1, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r5;
    // 0x800BCBA0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x800BCBA4: lw          $t9, -0x5960($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5960);
    // 0x800BCBA8: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x800BCBAC: slt         $at, $ra, $t9
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BCBB0: bne         $at, $zero, L_800BC904
    if (ctx->r1 != 0) {
        // 0x800BCBB4: addiu       $s3, $s3, 0x44
        ctx->r19 = ADD32(ctx->r19, 0X44);
            goto L_800BC904;
    }
    // 0x800BCBB4: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
L_800BCBB8:
    // 0x800BCBB8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800BCBBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BCBC0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCBC4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800BCBC8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800BCBCC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800BCBD0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800BCBD4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800BCBD8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800BCBDC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800BCBE0: jr          $ra
    // 0x800BCBE4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BCBE4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800BC6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCBE8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BCBEC: addiu       $t2, $t2, -0x5A78
    ctx->r10 = ADD32(ctx->r10, -0X5A78);
    // 0x800BCBF0: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCBF4: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x800BCBF8: div         $zero, $t6, $a2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r6)));
    // 0x800BCBFC: addiu       $sp, $sp, -0x248
    ctx->r29 = ADD32(ctx->r29, -0X248);
    // 0x800BCC00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BCC04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BCC08: bne         $a2, $zero, L_800BCC14
    if (ctx->r6 != 0) {
        // 0x800BCC0C: nop
    
            goto L_800BCC14;
    }
    // 0x800BCC0C: nop

    // 0x800BCC10: break       7
    do_break(2148256784);
L_800BCC14:
    // 0x800BCC14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BCC18: bne         $a2, $at, L_800BCC2C
    if (ctx->r6 != ctx->r1) {
        // 0x800BCC1C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BCC2C;
    }
    // 0x800BCC1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BCC20: bne         $t6, $at, L_800BCC2C
    if (ctx->r14 != ctx->r1) {
        // 0x800BCC24: nop
    
            goto L_800BCC2C;
    }
    // 0x800BCC24: nop

    // 0x800BCC28: break       6
    do_break(2148256808);
L_800BCC2C:
    // 0x800BCC2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BCC30: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BCC34: mflo        $v0
    ctx->r2 = lo;
    // 0x800BCC38: blez        $a2, L_800BCC90
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BCC3C: addiu       $a1, $sp, 0x34
        ctx->r5 = ADD32(ctx->r29, 0X34);
            goto L_800BCC90;
    }
    // 0x800BCC3C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
L_800BCC40:
    // 0x800BCC40: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800BCC44: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800BCC48: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800BCC4C: sw          $v0, 0x234($sp)
    MEM_W(0X234, ctx->r29) = ctx->r2;
    // 0x800BCC50: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x800BCC54: jal         0x80070A04
    // 0x800BCC58: sw          $t3, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r11;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800BCC58: sw          $t3, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r11;
    after_0:
    // 0x800BCC5C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BCC60: lw          $t3, 0x244($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X244);
    // 0x800BCC64: addiu       $t2, $t2, -0x5A78
    ctx->r10 = ADD32(ctx->r10, -0X5A78);
    // 0x800BCC68: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCC6C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800BCC70: lw          $v0, 0x234($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X234);
    // 0x800BCC74: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCC78: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BCC7C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800BCC80: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800BCC84: bne         $at, $zero, L_800BCC40
    if (ctx->r1 != 0) {
        // 0x800BCC88: addu        $s0, $s0, $v0
        ctx->r16 = ADD32(ctx->r16, ctx->r2);
            goto L_800BCC40;
    }
    // 0x800BCC88: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800BCC8C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BCC90:
    // 0x800BCC90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BCC94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BCC98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BCC9C: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x800BCCA0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800BCCA4: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800BCCA8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800BCCAC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800BCCB0: bltz        $a2, L_800BCD08
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCCB4: swc1        $f0, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
            goto L_800BCD08;
    }
    // 0x800BCCB4: swc1        $f0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
    // 0x800BCCB8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BCCBC: addiu       $t1, $t1, 0x35DC
    ctx->r9 = ADD32(ctx->r9, 0X35DC);
L_800BCCC0:
    // 0x800BCCC0: bltz        $a2, L_800BCCF0
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCCC4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BCCF0;
    }
    // 0x800BCCC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BCCC8: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
L_800BCCCC:
    // 0x800BCCCC: lw          $t5, 0x10($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X10);
    // 0x800BCCD0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCCD4: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800BCCD8: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x800BCCDC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCCE0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BCCE4: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCCE8: beq         $at, $zero, L_800BCCCC
    if (ctx->r1 == 0) {
        // 0x800BCCEC: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BCCCC;
    }
    // 0x800BCCEC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BCCF0:
    // 0x800BCCF0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCCF4: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCCF8: beq         $at, $zero, L_800BCCC0
    if (ctx->r1 == 0) {
        // 0x800BCCFC: nop
    
            goto L_800BCCC0;
    }
    // 0x800BCCFC: nop

    // 0x800BCD00: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BCD04: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800BCD08:
    // 0x800BCD08: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BCD0C: bltz        $a2, L_800BCD68
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCD10: addiu       $t1, $t1, 0x35DC
        ctx->r9 = ADD32(ctx->r9, 0X35DC);
            goto L_800BCD68;
    }
    // 0x800BCD10: addiu       $t1, $t1, 0x35DC
    ctx->r9 = ADD32(ctx->r9, 0X35DC);
L_800BCD14:
    // 0x800BCD14: bltz        $a2, L_800BCD50
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCD18: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BCD50;
    }
    // 0x800BCD18: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BCD1C: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800BCD20: addu        $a1, $t4, $t7
    ctx->r5 = ADD32(ctx->r12, ctx->r15);
    // 0x800BCD24: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
L_800BCD28:
    // 0x800BCD28: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
    // 0x800BCD2C: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCD30: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800BCD34: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x800BCD38: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCD3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCD40: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCD44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BCD48: beq         $at, $zero, L_800BCD28
    if (ctx->r1 == 0) {
        // 0x800BCD4C: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BCD28;
    }
    // 0x800BCD4C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BCD50:
    // 0x800BCD50: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCD54: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCD58: beq         $at, $zero, L_800BCD14
    if (ctx->r1 == 0) {
        // 0x800BCD5C: nop
    
            goto L_800BCD14;
    }
    // 0x800BCD5C: nop

    // 0x800BCD60: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BCD64: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800BCD68:
    // 0x800BCD68: bltz        $a2, L_800BCDC4
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCD6C: nop
    
            goto L_800BCDC4;
    }
    // 0x800BCD6C: nop

L_800BCD70:
    // 0x800BCD70: bltz        $a2, L_800BCDAC
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCD74: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BCDAC;
    }
    // 0x800BCD74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BCD78: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800BCD7C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_800BCD80:
    // 0x800BCD80: lw          $t5, 0xC($t1)
    ctx->r13 = MEM_W(ctx->r9, 0XC);
    // 0x800BCD84: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800BCD88: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800BCD8C: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x800BCD90: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCD94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCD98: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCD9C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BCDA0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800BCDA4: beq         $at, $zero, L_800BCD80
    if (ctx->r1 == 0) {
        // 0x800BCDA8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800BCD80;
    }
    // 0x800BCDA8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800BCDAC:
    // 0x800BCDAC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCDB0: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCDB4: beq         $at, $zero, L_800BCD70
    if (ctx->r1 == 0) {
        // 0x800BCDB8: nop
    
            goto L_800BCD70;
    }
    // 0x800BCDB8: nop

    // 0x800BCDBC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BCDC0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800BCDC4:
    // 0x800BCDC4: bltz        $a2, L_800BCE30
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCDC8: nop
    
            goto L_800BCE30;
    }
    // 0x800BCDC8: nop

L_800BCDCC:
    // 0x800BCDCC: bltz        $a2, L_800BCE18
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCDD0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BCE18;
    }
    // 0x800BCDD0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BCDD4: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800BCDD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BCDDC:
    // 0x800BCDDC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800BCDE0: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x800BCDE4: negu        $t9, $a0
    ctx->r25 = SUB32(0, ctx->r4);
    // 0x800BCDE8: lw          $t6, 0x14($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X14);
    // 0x800BCDEC: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x800BCDF0: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800BCDF4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800BCDF8: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x800BCDFC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCE00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCE04: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCE08: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BCE0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BCE10: beq         $at, $zero, L_800BCDDC
    if (ctx->r1 == 0) {
        // 0x800BCE14: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BCDDC;
    }
    // 0x800BCE14: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BCE18:
    // 0x800BCE18: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCE1C: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCE20: beq         $at, $zero, L_800BCDCC
    if (ctx->r1 == 0) {
        // 0x800BCE24: nop
    
            goto L_800BCDCC;
    }
    // 0x800BCE24: nop

    // 0x800BCE28: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BCE2C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800BCE30:
    // 0x800BCE30: bltz        $a2, L_800BCE94
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCE34: nop
    
            goto L_800BCE94;
    }
    // 0x800BCE34: nop

L_800BCE38:
    // 0x800BCE38: bltz        $a2, L_800BCE80
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCE3C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BCE80;
    }
    // 0x800BCE3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BCE40: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BCE44: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
L_800BCE48:
    // 0x800BCE48: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800BCE4C: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800BCE50: negu        $t5, $a3
    ctx->r13 = SUB32(0, ctx->r7);
    // 0x800BCE54: lw          $t7, 0x1C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X1C);
    // 0x800BCE58: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800BCE5C: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BCE60: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800BCE64: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x800BCE68: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCE6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCE70: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCE74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BCE78: beq         $at, $zero, L_800BCE48
    if (ctx->r1 == 0) {
        // 0x800BCE7C: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BCE48;
    }
    // 0x800BCE7C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BCE80:
    // 0x800BCE80: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCE84: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCE88: beq         $at, $zero, L_800BCE38
    if (ctx->r1 == 0) {
        // 0x800BCE8C: nop
    
            goto L_800BCE38;
    }
    // 0x800BCE8C: nop

    // 0x800BCE90: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BCE94:
    // 0x800BCE94: bltz        $a2, L_800BCF30
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCE98: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCF30;
    }
    // 0x800BCE98: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BCE9C:
    // 0x800BCE9C: bne         $at, $zero, L_800BCF1C
    if (ctx->r1 != 0) {
        // 0x800BCEA0: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800BCF1C;
    }
    // 0x800BCEA0: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800BCEA4: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BCEA8: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800BCEAC: addu        $a1, $a3, $t9
    ctx->r5 = ADD32(ctx->r7, ctx->r25);
    // 0x800BCEB0: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800BCEB4: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
L_800BCEB8:
    // 0x800BCEB8: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCEBC: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800BCEC0: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCEC4: mflo        $t7
    ctx->r15 = lo;
    // 0x800BCEC8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BCECC: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800BCED0: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x800BCED4: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    // 0x800BCED8: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800BCEDC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BCEE0: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800BCEE4: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCEE8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCEEC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCEF0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BCEF4: mflo        $t9
    ctx->r25 = lo;
    // 0x800BCEF8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BCEFC: addu        $t5, $t7, $t6
    ctx->r13 = ADD32(ctx->r15, ctx->r14);
    // 0x800BCF00: addu        $t8, $t5, $a3
    ctx->r24 = ADD32(ctx->r13, ctx->r7);
    // 0x800BCF04: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800BCF08: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCF0C: nop

    // 0x800BCF10: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCF14: beq         $at, $zero, L_800BCEB8
    if (ctx->r1 == 0) {
        // 0x800BCF18: addiu       $t6, $a2, 0x1
        ctx->r14 = ADD32(ctx->r6, 0X1);
            goto L_800BCEB8;
    }
    // 0x800BCF18: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
L_800BCF1C:
    // 0x800BCF1C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCF20: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCF24: beq         $at, $zero, L_800BCE9C
    if (ctx->r1 == 0) {
        // 0x800BCF28: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCE9C;
    }
    // 0x800BCF28: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCF2C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BCF30:
    // 0x800BCF30: bltz        $a2, L_800BCFE4
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCF34: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCFE4;
    }
    // 0x800BCF34: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BCF38:
    // 0x800BCF38: bne         $at, $zero, L_800BCFD0
    if (ctx->r1 != 0) {
        // 0x800BCF3C: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800BCFD0;
    }
    // 0x800BCF3C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800BCF40: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BCF44: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800BCF48: addu        $a1, $a3, $t9
    ctx->r5 = ADD32(ctx->r7, ctx->r25);
    // 0x800BCF4C: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800BCF50: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
L_800BCF54:
    // 0x800BCF54: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCF58: lw          $t7, 0x8($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X8);
    // 0x800BCF5C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800BCF60: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCF64: mflo        $t5
    ctx->r13 = lo;
    // 0x800BCF68: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800BCF6C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800BCF70: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x800BCF74: negu        $t7, $a0
    ctx->r15 = SUB32(0, ctx->r4);
    // 0x800BCF78: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800BCF7C: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x800BCF80: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCF84: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x800BCF88: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x800BCF8C: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCF90: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800BCF94: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCF98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCF9C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BCFA0: mflo        $t5
    ctx->r13 = lo;
    // 0x800BCFA4: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800BCFA8: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800BCFAC: addu        $t5, $t8, $t6
    ctx->r13 = ADD32(ctx->r24, ctx->r14);
    // 0x800BCFB0: negu        $t9, $a3
    ctx->r25 = SUB32(0, ctx->r7);
    // 0x800BCFB4: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x800BCFB8: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x800BCFBC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCFC0: nop

    // 0x800BCFC4: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCFC8: beq         $at, $zero, L_800BCF54
    if (ctx->r1 == 0) {
        // 0x800BCFCC: addiu       $t6, $a2, 0x1
        ctx->r14 = ADD32(ctx->r6, 0X1);
            goto L_800BCF54;
    }
    // 0x800BCFCC: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
L_800BCFD0:
    // 0x800BCFD0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCFD4: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCFD8: beq         $at, $zero, L_800BCF38
    if (ctx->r1 == 0) {
        // 0x800BCFDC: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCF38;
    }
    // 0x800BCFDC: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCFE0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BCFE4:
    // 0x800BCFE4: bltz        $a2, L_800BD0A8
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCFE8: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BD0A8;
    }
    // 0x800BCFE8: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BCFEC:
    // 0x800BCFEC: bne         $at, $zero, L_800BD094
    if (ctx->r1 != 0) {
        // 0x800BCFF0: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800BD094;
    }
    // 0x800BCFF0: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800BCFF4: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BCFF8: addiu       $t8, $sp, 0x34
    ctx->r24 = ADD32(ctx->r29, 0X34);
    // 0x800BCFFC: addu        $a1, $a3, $t8
    ctx->r5 = ADD32(ctx->r7, ctx->r24);
    // 0x800BD000: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800BD004: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_800BD008:
    // 0x800BD008: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD00C: lw          $t6, 0x18($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X18);
    // 0x800BD010: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BD014: mflo        $t5
    ctx->r13 = lo;
    // 0x800BD018: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800BD01C: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800BD020: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD024: mflo        $t8
    ctx->r24 = lo;
    // 0x800BD028: negu        $at, $t8
    ctx->r1 = SUB32(0, ctx->r24);
    // 0x800BD02C: sll         $t5, $at, 2
    ctx->r13 = S32(ctx->r1 << 2);
    // 0x800BD030: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x800BD034: addu        $t9, $t6, $a0
    ctx->r25 = ADD32(ctx->r14, ctx->r4);
    // 0x800BD038: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x800BD03C: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BD040: lw          $t8, 0x18($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X18);
    // 0x800BD044: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800BD048: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD04C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BD050: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BD054: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD058: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x800BD05C: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x800BD060: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD064: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD068: mflo        $t9
    ctx->r25 = lo;
    // 0x800BD06C: negu        $at, $t9
    ctx->r1 = SUB32(0, ctx->r25);
    // 0x800BD070: sll         $t7, $at, 2
    ctx->r15 = S32(ctx->r1 << 2);
    // 0x800BD074: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800BD078: addu        $t5, $t8, $a3
    ctx->r13 = ADD32(ctx->r24, ctx->r7);
    // 0x800BD07C: swc1        $f16, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f16.u32l;
    // 0x800BD080: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BD084: nop

    // 0x800BD088: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BD08C: beq         $at, $zero, L_800BD008
    if (ctx->r1 == 0) {
        // 0x800BD090: addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
            goto L_800BD008;
    }
    // 0x800BD090: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_800BD094:
    // 0x800BD094: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BD098: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BD09C: beq         $at, $zero, L_800BCFEC
    if (ctx->r1 == 0) {
        // 0x800BD0A0: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCFEC;
    }
    // 0x800BD0A0: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BD0A4: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BD0A8:
    // 0x800BD0A8: bltz        $a2, L_800BD180
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BD0AC: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BD180;
    }
    // 0x800BD0AC: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BD0B0:
    // 0x800BD0B0: bne         $at, $zero, L_800BD170
    if (ctx->r1 != 0) {
        // 0x800BD0B4: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800BD170;
    }
    // 0x800BD0B4: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800BD0B8: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BD0BC: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800BD0C0: addu        $a1, $a3, $t9
    ctx->r5 = ADD32(ctx->r7, ctx->r25);
    // 0x800BD0C4: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800BD0C8: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_800BD0CC:
    // 0x800BD0CC: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD0D0: lw          $t6, 0x20($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X20);
    // 0x800BD0D4: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BD0D8: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD0DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BD0E0: addu        $t5, $t6, $t8
    ctx->r13 = ADD32(ctx->r14, ctx->r24);
    // 0x800BD0E4: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD0E8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800BD0EC: mflo        $t9
    ctx->r25 = lo;
    // 0x800BD0F0: negu        $at, $t9
    ctx->r1 = SUB32(0, ctx->r25);
    // 0x800BD0F4: sll         $t7, $at, 2
    ctx->r15 = S32(ctx->r1 << 2);
    // 0x800BD0F8: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x800BD0FC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800BD100: negu        $t5, $a0
    ctx->r13 = SUB32(0, ctx->r4);
    // 0x800BD104: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x800BD108: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x800BD10C: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BD110: lw          $t6, 0x20($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X20);
    // 0x800BD114: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800BD118: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD11C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BD120: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BD124: mflo        $t8
    ctx->r24 = lo;
    // 0x800BD128: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BD12C: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x800BD130: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD134: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800BD138: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD13C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD140: negu        $at, $t7
    ctx->r1 = SUB32(0, ctx->r15);
    // 0x800BD144: sll         $t8, $at, 2
    ctx->r24 = S32(ctx->r1 << 2);
    // 0x800BD148: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x800BD14C: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800BD150: negu        $t5, $a3
    ctx->r13 = SUB32(0, ctx->r7);
    // 0x800BD154: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x800BD158: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800BD15C: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BD160: nop

    // 0x800BD164: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BD168: beq         $at, $zero, L_800BD0CC
    if (ctx->r1 == 0) {
        // 0x800BD16C: addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
            goto L_800BD0CC;
    }
    // 0x800BD16C: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_800BD170:
    // 0x800BD170: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BD174: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BD178: beq         $at, $zero, L_800BD0B0
    if (ctx->r1 == 0) {
        // 0x800BD17C: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BD0B0;
    }
    // 0x800BD17C: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BD180:
    // 0x800BD180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BD184: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BD188: jr          $ra
    // 0x800BD18C: addiu       $sp, $sp, 0x248
    ctx->r29 = ADD32(ctx->r29, 0X248);
    return;
    // 0x800BD18C: addiu       $sp, $sp, 0x248
    ctx->r29 = ADD32(ctx->r29, 0X248);
;}
RECOMP_FUNC void func_800BCC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD190: addiu       $sp, $sp, -0x190
    ctx->r29 = ADD32(ctx->r29, -0X190);
    // 0x800BD194: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800BD198: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800BD19C: addiu       $fp, $fp, -0x5A78
    ctx->r30 = ADD32(ctx->r30, -0X5A78);
    // 0x800BD1A0: lw          $t6, 0x28($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X28);
    // 0x800BD1A4: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800BD1A8: lw          $s4, 0x0($fp)
    ctx->r20 = MEM_W(ctx->r30, 0X0);
    // 0x800BD1AC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800BD1B0: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800BD1B4: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800BD1B8: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800BD1BC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800BD1C0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800BD1C4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800BD1C8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800BD1CC: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800BD1D0: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x800BD1D4: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800BD1D8: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x800BD1DC: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BD1E0: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800BD1E4: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BD1E8: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800BD1EC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BD1F0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BD1F4: beq         $t6, $zero, L_800BD204
    if (ctx->r14 == 0) {
        // 0x800BD1F8: sw          $a0, 0x190($sp)
        MEM_W(0X190, ctx->r29) = ctx->r4;
            goto L_800BD204;
    }
    // 0x800BD1F8: sw          $a0, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r4;
    // 0x800BD1FC: sll         $t7, $s4, 1
    ctx->r15 = S32(ctx->r20 << 1);
    // 0x800BD200: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
L_800BD204:
    // 0x800BD204: addiu       $t8, $s4, 0x1
    ctx->r24 = ADD32(ctx->r20, 0X1);
    // 0x800BD208: multu       $t8, $t8
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD20C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800BD210: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BD214: addiu       $s1, $s1, 0x3708
    ctx->r17 = ADD32(ctx->r17, 0X3708);
    // 0x800BD218: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x800BD21C: mflo        $t6
    ctx->r14 = lo;
    // 0x800BD220: sw          $t6, 0x370C($at)
    MEM_W(0X370C, ctx->r1) = ctx->r14;
    // 0x800BD224: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD228: nop

    // 0x800BD22C: beq         $a0, $zero, L_800BD240
    if (ctx->r4 == 0) {
        // 0x800BD230: lw          $t7, 0x190($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X190);
            goto L_800BD240;
    }
    // 0x800BD230: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x800BD234: jal         0x80071380
    // 0x800BD238: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800BD238: nop

    after_0:
    // 0x800BD23C: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
L_800BD240:
    // 0x800BD240: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BD244: lw          $t9, 0x370C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X370C);
    // 0x800BD248: lh          $t8, 0x1A($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X1A);
    // 0x800BD24C: lui         $s0, 0xFF
    ctx->r16 = S32(0XFF << 16);
    // 0x800BD250: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD254: ori         $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 | 0XFFFF;
    // 0x800BD258: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800BD25C: mflo        $a0
    ctx->r4 = lo;
    // 0x800BD260: jal         0x80070EDC
    // 0x800BD264: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800BD264: nop

    after_1:
    // 0x800BD268: lw          $t6, 0x190($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X190);
    // 0x800BD26C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800BD270: lh          $a0, 0x1A($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X1A);
    // 0x800BD274: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800BD278: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800BD27C: jal         0x80070EDC
    // 0x800BD280: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800BD280: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x800BD284: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BD288: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BD28C: lw          $t9, -0x5964($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5964);
    // 0x800BD290: lw          $t8, -0x5968($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5968);
    // 0x800BD294: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x800BD298: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD29C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800BD2A0: mflo        $a0
    ctx->r4 = lo;
    // 0x800BD2A4: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800BD2A8: jal         0x80070EDC
    // 0x800BD2AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x800BD2AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_3:
    // 0x800BD2B0: sll         $a0, $s4, 2
    ctx->r4 = S32(ctx->r20 << 2);
    // 0x800BD2B4: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800BD2B8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BD2BC: jal         0x80070EDC
    // 0x800BD2C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800BD2C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800BD2C4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BD2C8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BD2CC: lw          $t8, -0x5964($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5964);
    // 0x800BD2D0: lw          $t7, -0x5968($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5968);
    // 0x800BD2D4: lw          $v1, 0xA4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD2D8: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD2DC: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x800BD2E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BD2E4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800BD2E8: addiu       $a1, $s4, 0x1
    ctx->r5 = ADD32(ctx->r20, 0X1);
    // 0x800BD2EC: mflo        $t9
    ctx->r25 = lo;
    // 0x800BD2F0: blez        $t9, L_800BD32C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BD2F4: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_800BD32C;
    }
    // 0x800BD2F4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_800BD2F8:
    // 0x800BD2F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BD2FC: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800BD300: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BD304: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BD308: lw          $t8, -0x5964($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5964);
    // 0x800BD30C: lw          $t7, -0x5968($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5968);
    // 0x800BD310: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BD314: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD318: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800BD31C: mflo        $t9
    ctx->r25 = lo;
    // 0x800BD320: slt         $at, $a3, $t9
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BD324: bne         $at, $zero, L_800BD2F8
    if (ctx->r1 != 0) {
        // 0x800BD328: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_800BD2F8;
    }
    // 0x800BD328: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_800BD32C:
    // 0x800BD32C: bltz        $s4, L_800BD46C
    if (SIGNED(ctx->r20) < 0) {
        // 0x800BD330: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800BD46C;
    }
    // 0x800BD330: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BD334: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x800BD338: beq         $t6, $zero, L_800BD3C4
    if (ctx->r14 == 0) {
        // 0x800BD33C: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800BD3C4;
    }
    // 0x800BD33C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800BD340: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x800BD344: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800BD348: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800BD34C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800BD350: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x800BD354: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BD358: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x800BD35C: subu        $t9, $s4, $t8
    ctx->r25 = SUB32(ctx->r20, ctx->r24);
    // 0x800BD360: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BD364: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800BD368: beq         $a0, $t2, L_800BD39C
    if (ctx->r4 == ctx->r10) {
        // 0x800BD36C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800BD39C;
    }
    // 0x800BD36C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
L_800BD370:
    // 0x800BD370: nop

    // 0x800BD374: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800BD378: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BD37C: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x800BD380: subu        $t9, $s4, $t8
    ctx->r25 = SUB32(ctx->r20, ctx->r24);
    // 0x800BD384: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BD388: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800BD38C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BD390: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800BD394: bne         $a0, $t2, L_800BD370
    if (ctx->r4 != ctx->r10) {
        // 0x800BD398: swc1        $f16, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
            goto L_800BD370;
    }
    // 0x800BD398: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
L_800BD39C:
    // 0x800BD39C: nop

    // 0x800BD3A0: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800BD3A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BD3A8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BD3AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800BD3B0: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800BD3B4: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x800BD3B8: addiu       $t6, $s4, 0x1
    ctx->r14 = ADD32(ctx->r20, 0X1);
    // 0x800BD3BC: beq         $t6, $t2, L_800BD46C
    if (ctx->r14 == ctx->r10) {
        // 0x800BD3C0: nop
    
            goto L_800BD46C;
    }
    // 0x800BD3C0: nop

L_800BD3C4:
    // 0x800BD3C4: mtc1        $s4, $f18
    ctx->f18.u32l = ctx->r20;
    // 0x800BD3C8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800BD3CC: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800BD3D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800BD3D4: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x800BD3D8: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
L_800BD3DC:
    // 0x800BD3DC: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x800BD3E0: subu        $t9, $s4, $t8
    ctx->r25 = SUB32(ctx->r20, ctx->r24);
    // 0x800BD3E4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800BD3E8: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x800BD3EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BD3F0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800BD3F4: subu        $t8, $s4, $t7
    ctx->r24 = SUB32(ctx->r20, ctx->r15);
    // 0x800BD3F8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800BD3FC: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800BD400: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BD404: addiu       $t9, $t2, 0x2
    ctx->r25 = ADD32(ctx->r10, 0X2);
    // 0x800BD408: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800BD40C: subu        $t7, $s4, $t6
    ctx->r15 = SUB32(ctx->r20, ctx->r14);
    // 0x800BD410: addiu       $t8, $t2, 0x3
    ctx->r24 = ADD32(ctx->r10, 0X3);
    // 0x800BD414: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BD418: subu        $t6, $s4, $t9
    ctx->r14 = SUB32(ctx->r20, ctx->r25);
    // 0x800BD41C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800BD420: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800BD424: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BD428: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BD42C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800BD430: addiu       $t7, $s4, 0x1
    ctx->r15 = ADD32(ctx->r20, 0X1);
    // 0x800BD434: swc1        $f10, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f10.u32l;
    // 0x800BD438: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BD43C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BD440: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800BD444: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BD448: swc1        $f6, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f6.u32l;
    // 0x800BD44C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BD450: nop

    // 0x800BD454: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800BD458: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800BD45C: swc1        $f18, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f18.u32l;
    // 0x800BD460: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BD464: bne         $t7, $t2, L_800BD3DC
    if (ctx->r15 != ctx->r10) {
        // 0x800BD468: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_800BD3DC;
    }
    // 0x800BD468: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
L_800BD46C:
    // 0x800BD46C: mtc1        $s4, $f16
    ctx->f16.u32l = ctx->r20;
    // 0x800BD470: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BD474: lwc1        $f18, -0x59A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800BD478: lw          $t8, 0x190($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X190);
    // 0x800BD47C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BD480: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BD484: sw          $zero, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = 0;
    // 0x800BD488: lwc1        $f4, -0x599C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800BD48C: lh          $v0, 0x1A($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X1A);
    // 0x800BD490: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800BD494: div.s       $f26, $f18, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BD498: blez        $v0, L_800BD794
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BD49C: div.s       $f28, $f4, $f0
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
            goto L_800BD794;
    }
    // 0x800BD49C: div.s       $f28, $f4, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800BD4A0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800BD4A4: addiu       $a2, $a2, 0x3668
    ctx->r6 = ADD32(ctx->r6, 0X3668);
    // 0x800BD4A8: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800BD4AC: addiu       $s0, $sp, 0xAC
    ctx->r16 = ADD32(ctx->r29, 0XAC);
L_800BD4B0:
    // 0x800BD4B0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BD4B4: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800BD4B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BD4BC: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD4C0: lbu         $a0, 0xB($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0XB);
    // 0x800BD4C4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BD4C8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800BD4CC: lbu         $v1, 0xA($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XA);
    // 0x800BD4D0: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800BD4D4: lw          $t6, -0x5958($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5958);
    // 0x800BD4D8: sllv        $t8, $t7, $v1
    ctx->r24 = S32(ctx->r15 << (ctx->r3 & 31));
    // 0x800BD4DC: and         $t7, $t8, $t6
    ctx->r15 = ctx->r24 & ctx->r14;
    // 0x800BD4E0: beq         $t7, $zero, L_800BD728
    if (ctx->r15 == 0) {
        // 0x800BD4E4: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800BD728;
    }
    // 0x800BD4E4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BD4E8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BD4EC: lw          $t6, -0x5968($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5968);
    // 0x800BD4F0: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD4F4: multu       $a0, $t6
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD4F8: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800BD4FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BD500: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD504: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800BD508: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800BD50C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800BD510: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x800BD514: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800BD518: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x800BD51C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800BD520: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BD524: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800BD528: lbu         $t9, 0xB($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XB);
    // 0x800BD52C: lw          $t6, -0x5968($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5968);
    // 0x800BD530: nop

    // 0x800BD534: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD538: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD53C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD540: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800BD544: lbu         $t7, 0xA($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA);
    // 0x800BD548: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800BD54C: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x800BD550: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800BD554: sw          $s5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r21;
    // 0x800BD558: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800BD55C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800BD560: nop

    // 0x800BD564: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    // 0x800BD568: lh          $t9, 0x6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X6);
    // 0x800BD56C: lh          $t8, 0x8($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X8);
    // 0x800BD570: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BD574: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800BD578: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BD57C: bltz        $s4, L_800BD714
    if (SIGNED(ctx->r20) < 0) {
        // 0x800BD580: cvt.s.w     $f24, $f8
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800BD714;
    }
    // 0x800BD580: cvt.s.w     $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
L_800BD584:
    // 0x800BD584: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800BD588: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800BD58C: nop

    // 0x800BD590: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x800BD594: lh          $t8, 0x4($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X4);
    // 0x800BD598: nop

    // 0x800BD59C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BD5A0: bltz        $s4, L_800BD704
    if (SIGNED(ctx->r20) < 0) {
        // 0x800BD5A4: cvt.s.w     $f22, $f10
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800BD704;
    }
    // 0x800BD5A4: cvt.s.w     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BD5A8: sw          $v0, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r2;
    // 0x800BD5AC: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800BD5B0: lw          $s7, 0x90($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X90);
    // 0x800BD5B4: lw          $s3, 0xA8($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA8);
    // 0x800BD5B8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800BD5BC: sll         $t9, $s7, 2
    ctx->r25 = S32(ctx->r23 << 2);
    // 0x800BD5C0: or          $s7, $t9, $zero
    ctx->r23 = ctx->r25 | 0;
    // 0x800BD5C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BD5C8: addu        $s6, $s3, $t6
    ctx->r22 = ADD32(ctx->r19, ctx->r14);
L_800BD5CC:
    // 0x800BD5CC: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800BD5D0: lwc1        $f4, 0x0($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800BD5D4: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x800BD5D8: lw          $a0, 0x18C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18C);
    // 0x800BD5DC: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x800BD5E0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800BD5E4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800BD5E8: jal         0x8002BAF0
    // 0x800BD5EC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    collision_get_y(rdram, ctx);
        goto after_5;
    // 0x800BD5EC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_5:
    // 0x800BD5F0: bne         $v0, $zero, L_800BD600
    if (ctx->r2 != 0) {
        // 0x800BD5F4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800BD600;
    }
    // 0x800BD5F4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800BD5F8: b           L_800BD6DC
    // 0x800BD5FC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
        goto L_800BD6DC;
    // 0x800BD5FC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_800BD600:
    // 0x800BD600: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x800BD604: blez        $a0, L_800BD650
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BD608: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BD650;
    }
    // 0x800BD608: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BD60C: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BD610: nop

    // 0x800BD614: c.le.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl <= ctx->f8.fl;
    // 0x800BD618: nop

    // 0x800BD61C: bc1f        L_800BD654
    if (!c1cs) {
        // 0x800BD620: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_800BD654;
    }
    // 0x800BD620: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
L_800BD624:
    // 0x800BD624: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD628: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BD62C: beq         $at, $zero, L_800BD650
    if (ctx->r1 == 0) {
        // 0x800BD630: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_800BD650;
    }
    // 0x800BD630: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800BD634: addu        $t7, $s0, $t8
    ctx->r15 = ADD32(ctx->r16, ctx->r24);
    // 0x800BD638: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BD63C: nop

    // 0x800BD640: c.le.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl <= ctx->f10.fl;
    // 0x800BD644: nop

    // 0x800BD648: bc1t        L_800BD624
    if (c1cs) {
        // 0x800BD64C: nop
    
            goto L_800BD624;
    }
    // 0x800BD64C: nop

L_800BD650:
    // 0x800BD650: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
L_800BD654:
    // 0x800BD654: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x800BD658: lwc1        $f0, 0x0($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BD65C: nop

    // 0x800BD660: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800BD664: nop

    // 0x800BD668: bc1f        L_800BD678
    if (!c1cs) {
        // 0x800BD66C: nop
    
            goto L_800BD678;
    }
    // 0x800BD66C: nop

    // 0x800BD670: b           L_800BD6DC
    // 0x800BD674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800BD6DC;
    // 0x800BD674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800BD678:
    // 0x800BD678: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800BD67C: nop

    // 0x800BD680: bc1f        L_800BD690
    if (!c1cs) {
        // 0x800BD684: nop
    
            goto L_800BD690;
    }
    // 0x800BD684: nop

    // 0x800BD688: b           L_800BD6DC
    // 0x800BD68C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
        goto L_800BD6DC;
    // 0x800BD68C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_800BD690:
    // 0x800BD690: sub.s       $f16, $f20, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800BD694: lwc1        $f18, 0x48($fp)
    ctx->f18.u32l = MEM_W(ctx->r30, 0X48);
    // 0x800BD698: nop

    // 0x800BD69C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800BD6A0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BD6A4: nop

    // 0x800BD6A8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BD6AC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BD6B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BD6B4: nop

    // 0x800BD6B8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800BD6BC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800BD6C0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BD6C4: slti        $at, $a2, 0x200
    ctx->r1 = SIGNED(ctx->r6) < 0X200 ? 1 : 0;
    // 0x800BD6C8: bne         $at, $zero, L_800BD6D8
    if (ctx->r1 != 0) {
        // 0x800BD6CC: sra         $t7, $a2, 1
        ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
            goto L_800BD6D8;
    }
    // 0x800BD6CC: sra         $t7, $a2, 1
    ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD6D0: addiu       $a2, $zero, 0x1FF
    ctx->r6 = ADD32(0, 0X1FF);
    // 0x800BD6D4: sra         $t7, $a2, 1
    ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
L_800BD6D8:
    // 0x800BD6D8: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_800BD6DC:
    // 0x800BD6DC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD6E0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800BD6E4: addu        $t9, $t6, $s5
    ctx->r25 = ADD32(ctx->r14, ctx->r21);
    // 0x800BD6E8: sb          $a2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r6;
    // 0x800BD6EC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800BD6F0: bne         $s7, $s2, L_800BD5CC
    if (ctx->r23 != ctx->r18) {
        // 0x800BD6F4: add.s       $f22, $f22, $f26
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
            goto L_800BD5CC;
    }
    // 0x800BD6F4: add.s       $f22, $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
    // 0x800BD6F8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800BD6FC: lw          $v0, 0x184($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X184);
    // 0x800BD700: addiu       $a2, $a2, 0x3668
    ctx->r6 = ADD32(ctx->r6, 0X3668);
L_800BD704:
    // 0x800BD704: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800BD708: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BD70C: bne         $t8, $v0, L_800BD584
    if (ctx->r24 != ctx->r2) {
        // 0x800BD710: add.s       $f24, $f24, $f28
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f28.fl;
            goto L_800BD584;
    }
    // 0x800BD710: add.s       $f24, $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f28.fl;
L_800BD714:
    // 0x800BD714: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x800BD718: nop

    // 0x800BD71C: lh          $v0, 0x1A($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X1A);
    // 0x800BD720: b           L_800BD774
    // 0x800BD724: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
        goto L_800BD774;
    // 0x800BD724: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
L_800BD728:
    // 0x800BD728: lw          $t6, 0x370C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X370C);
    // 0x800BD72C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BD730: blez        $t6, L_800BD774
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BD734: lw          $t9, 0x18C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18C);
            goto L_800BD774;
    }
    // 0x800BD734: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
L_800BD738:
    // 0x800BD738: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800BD73C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800BD740: addu        $t7, $t8, $s5
    ctx->r15 = ADD32(ctx->r24, ctx->r21);
    // 0x800BD744: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800BD748: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BD74C: lw          $t6, 0x370C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X370C);
    // 0x800BD750: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BD754: slt         $at, $t2, $t6
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BD758: bne         $at, $zero, L_800BD738
    if (ctx->r1 != 0) {
        // 0x800BD75C: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800BD738;
    }
    // 0x800BD75C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800BD760: lw          $t8, 0x190($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X190);
    // 0x800BD764: nop

    // 0x800BD768: lh          $v0, 0x1A($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X1A);
    // 0x800BD76C: nop

    // 0x800BD770: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
L_800BD774:
    // 0x800BD774: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800BD778: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800BD77C: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BD780: addiu       $t8, $t6, 0x1C
    ctx->r24 = ADD32(ctx->r14, 0X1C);
    // 0x800BD784: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
    // 0x800BD788: bne         $at, $zero, L_800BD4B0
    if (ctx->r1 != 0) {
        // 0x800BD78C: sw          $t7, 0x18C($sp)
        MEM_W(0X18C, ctx->r29) = ctx->r15;
            goto L_800BD4B0;
    }
    // 0x800BD78C: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800BD790: sw          $zero, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = 0;
L_800BD794:
    // 0x800BD794: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BD798: lw          $v1, -0x5964($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5964);
    // 0x800BD79C: sw          $zero, 0x184($sp)
    MEM_W(0X184, ctx->r29) = 0;
    // 0x800BD7A0: blez        $v1, L_800BDB94
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BD7A4: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800BDB94;
    }
    // 0x800BD7A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD7A8: lw          $a0, -0x5968($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5968);
    // 0x800BD7AC: nop

L_800BD7B0:
    // 0x800BD7B0: blez        $a0, L_800BDB6C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BD7B4: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800BDB6C;
    }
    // 0x800BD7B4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BD7B8: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD7BC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BD7C0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800BD7C4:
    // 0x800BD7C4: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800BD7C8: nop

    // 0x800BD7CC: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD7D0: mflo        $t6
    ctx->r14 = lo;
    // 0x800BD7D4: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800BD7D8: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x800BD7DC: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x800BD7E0: lw          $t4, 0x4($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X4);
    // 0x800BD7E4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BD7E8: beq         $t4, $a2, L_800BDB4C
    if (ctx->r12 == ctx->r6) {
        // 0x800BD7EC: nop
    
            goto L_800BDB4C;
    }
    // 0x800BD7EC: nop

    // 0x800BD7F0: lw          $t8, -0x5964($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5964);
    // 0x800BD7F4: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BD7F8: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x800BD7FC: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BD800: beq         $at, $zero, L_800BD99C
    if (ctx->r1 == 0) {
        // 0x800BD804: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_800BD99C;
    }
    // 0x800BD804: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x800BD808: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD80C: mflo        $t8
    ctx->r24 = lo;
    // 0x800BD810: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x800BD814: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x800BD818: addu        $t6, $t9, $t3
    ctx->r14 = ADD32(ctx->r25, ctx->r11);
    // 0x800BD81C: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x800BD820: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800BD824: beq         $v0, $a2, L_800BD99C
    if (ctx->r2 == ctx->r6) {
        // 0x800BD828: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_800BD99C;
    }
    // 0x800BD828: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x800BD82C: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD830: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800BD834: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x800BD838: addiu       $t1, $s4, -0x1
    ctx->r9 = ADD32(ctx->r20, -0X1);
    // 0x800BD83C: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x800BD840: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BD844: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD848: addu        $a1, $t7, $t4
    ctx->r5 = ADD32(ctx->r15, ctx->r12);
    // 0x800BD84C: blez        $t1, L_800BD998
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800BD850: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800BD998;
    }
    // 0x800BD850: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD854: beq         $t9, $zero, L_800BD8A4
    if (ctx->r25 == 0) {
        // 0x800BD858: or          $t0, $t9, $zero
        ctx->r8 = ctx->r25 | 0;
            goto L_800BD8A4;
    }
    // 0x800BD858: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
L_800BD85C:
    // 0x800BD85C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD860: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BD864: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD868: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD86C: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD870: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD874: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD878: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD87C: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD880: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BD884: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD888: nop

    // 0x800BD88C: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BD890: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BD894: bne         $t0, $a3, L_800BD85C
    if (ctx->r8 != ctx->r7) {
        // 0x800BD898: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800BD85C;
    }
    // 0x800BD898: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD89C: beq         $a3, $t1, L_800BD98C
    if (ctx->r7 == ctx->r9) {
        // 0x800BD8A0: nop
    
            goto L_800BD98C;
    }
    // 0x800BD8A0: nop

L_800BD8A4:
    // 0x800BD8A4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD8A8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800BD8AC: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD8B0: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD8B4: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BD8B8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD8BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD8C0: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD8C4: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD8C8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BD8CC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BD8D0: nop

    // 0x800BD8D4: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BD8D8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BD8DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD8E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD8E4: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD8E8: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD8EC: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD8F0: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD8F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD8F8: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD8FC: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD900: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BD904: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD908: nop

    // 0x800BD90C: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BD910: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BD914: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD918: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD91C: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD920: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD924: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD928: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BD92C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD930: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD934: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD938: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BD93C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BD940: nop

    // 0x800BD944: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BD948: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BD94C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD950: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD954: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD958: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD95C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD960: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD964: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD968: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD96C: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD970: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BD974: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD978: nop

    // 0x800BD97C: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BD980: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BD984: bne         $a3, $t1, L_800BD8A4
    if (ctx->r7 != ctx->r9) {
        // 0x800BD988: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800BD8A4;
    }
    // 0x800BD988: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800BD98C:
    // 0x800BD98C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD990: lw          $a0, -0x5968($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5968);
    // 0x800BD994: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800BD998:
    // 0x800BD998: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
L_800BD99C:
    // 0x800BD99C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD9A0: slt         $at, $t2, $t7
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BD9A4: beq         $at, $zero, L_800BDB4C
    if (ctx->r1 == 0) {
        // 0x800BD9A8: nop
    
            goto L_800BDB4C;
    }
    // 0x800BD9A8: nop

    // 0x800BD9AC: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800BD9B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BD9B4: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD9B8: addiu       $t1, $s4, -0x1
    ctx->r9 = ADD32(ctx->r20, -0X1);
    // 0x800BD9BC: mflo        $t6
    ctx->r14 = lo;
    // 0x800BD9C0: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800BD9C4: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x800BD9C8: addu        $t9, $t7, $t3
    ctx->r25 = ADD32(ctx->r15, ctx->r11);
    // 0x800BD9CC: lw          $v0, 0xC($t9)
    ctx->r2 = MEM_W(ctx->r25, 0XC);
    // 0x800BD9D0: sll         $t6, $s4, 1
    ctx->r14 = S32(ctx->r20 << 1);
    // 0x800BD9D4: beq         $v0, $a2, L_800BDB4C
    if (ctx->r2 == ctx->r6) {
        // 0x800BD9D8: addu        $a1, $t6, $t4
        ctx->r5 = ADD32(ctx->r14, ctx->r12);
            goto L_800BDB4C;
    }
    // 0x800BD9D8: addu        $a1, $t6, $t4
    ctx->r5 = ADD32(ctx->r14, ctx->r12);
    // 0x800BD9DC: addu        $v1, $v0, $s4
    ctx->r3 = ADD32(ctx->r2, ctx->r20);
    // 0x800BD9E0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD9E4: blez        $t1, L_800BDB4C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800BD9E8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800BDB4C;
    }
    // 0x800BD9E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD9EC: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x800BD9F0: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x800BD9F4: beq         $t8, $zero, L_800BDA48
    if (ctx->r24 == 0) {
        // 0x800BD9F8: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_800BDA48;
    }
    // 0x800BD9F8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_800BD9FC:
    // 0x800BD9FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BDA00: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDA04: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BDA08: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BDA0C: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BDA10: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BDA14: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BDA18: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDA1C: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BDA20: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BDA24: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BDA28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BDA2C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BDA30: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BDA34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BDA38: bne         $t0, $a3, L_800BD9FC
    if (ctx->r8 != ctx->r7) {
        // 0x800BDA3C: sb          $t8, 0x0($t9)
        MEM_B(0X0, ctx->r25) = ctx->r24;
            goto L_800BD9FC;
    }
    // 0x800BDA3C: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BDA40: beq         $a3, $t1, L_800BDB40
    if (ctx->r7 == ctx->r9) {
        // 0x800BDA44: nop
    
            goto L_800BDB40;
    }
    // 0x800BDA44: nop

L_800BDA48:
    // 0x800BDA48: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BDA4C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800BDA50: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BDA54: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BDA58: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BDA5C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BDA60: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BDA64: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BDA68: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BDA6C: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BDA70: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDA74: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BDA78: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BDA7C: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BDA80: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BDA84: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BDA88: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BDA8C: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BDA90: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BDA94: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BDA98: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BDA9C: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BDAA0: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDAA4: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BDAA8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BDAAC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BDAB0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BDAB4: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BDAB8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BDABC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BDAC0: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BDAC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BDAC8: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BDACC: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BDAD0: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BDAD4: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BDAD8: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BDADC: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BDAE0: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BDAE4: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BDAE8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDAEC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BDAF0: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BDAF4: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BDAF8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BDAFC: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BDB00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BDB04: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BDB08: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BDB0C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BDB10: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BDB14: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BDB18: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDB1C: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BDB20: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BDB24: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BDB28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BDB2C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BDB30: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BDB34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BDB38: bne         $a3, $t1, L_800BDA48
    if (ctx->r7 != ctx->r9) {
        // 0x800BDB3C: sb          $t8, 0x0($t9)
        MEM_B(0X0, ctx->r25) = ctx->r24;
            goto L_800BDA48;
    }
    // 0x800BDB3C: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_800BDB40:
    // 0x800BDB40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BDB44: lw          $a0, -0x5968($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5968);
    // 0x800BDB48: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800BDB4C:
    // 0x800BDB4C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BDB50: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BDB54: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BDB58: bne         $at, $zero, L_800BD7C4
    if (ctx->r1 != 0) {
        // 0x800BDB5C: addiu       $t3, $t3, 0x8
        ctx->r11 = ADD32(ctx->r11, 0X8);
            goto L_800BD7C4;
    }
    // 0x800BDB5C: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x800BDB60: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BDB64: lw          $v1, -0x5964($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5964);
    // 0x800BDB68: nop

L_800BDB6C:
    // 0x800BDB6C: lw          $t6, 0x184($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X184);
    // 0x800BDB70: nop

    // 0x800BDB74: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800BDB78: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BDB7C: bne         $at, $zero, L_800BD7B0
    if (ctx->r1 != 0) {
        // 0x800BDB80: sw          $t8, 0x184($sp)
        MEM_W(0X184, ctx->r29) = ctx->r24;
            goto L_800BD7B0;
    }
    // 0x800BDB80: sw          $t8, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r24;
    // 0x800BDB84: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x800BDB88: nop

    // 0x800BDB8C: lh          $v0, 0x1A($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X1A);
    // 0x800BDB90: nop

L_800BDB94:
    // 0x800BDB94: blez        $v0, L_800BDC5C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BDB98: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_800BDC5C;
    }
    // 0x800BDB98: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800BDB9C: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800BDBA0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BDBA4: multu       $t9, $t9
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDBA8: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x800BDBAC: lw          $a0, 0x190($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X190);
    // 0x800BDBB0: addiu       $v1, $v1, 0x370C
    ctx->r3 = ADD32(ctx->r3, 0X370C);
    // 0x800BDBB4: mflo        $ra
    ctx->r31 = lo;
    // 0x800BDBB8: nop

    // 0x800BDBBC: nop

    // 0x800BDBC0: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDBC4: mflo        $t5
    ctx->r13 = lo;
    // 0x800BDBC8: nop

    // 0x800BDBCC: nop

L_800BDBD0:
    // 0x800BDBD0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDBD4: addu        $t9, $t4, $s4
    ctx->r25 = ADD32(ctx->r12, ctx->r20);
    // 0x800BDBD8: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x800BDBDC: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x800BDBE0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800BDBE4: sb          $t7, -0x4($t0)
    MEM_B(-0X4, ctx->r8) = ctx->r15;
    // 0x800BDBE8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDBEC: nop

    // 0x800BDBF0: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDBF4: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x800BDBF8: addu        $t9, $t5, $t4
    ctx->r25 = ADD32(ctx->r13, ctx->r12);
    // 0x800BDBFC: sb          $t7, -0x3($t0)
    MEM_B(-0X3, ctx->r8) = ctx->r15;
    // 0x800BDC00: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDC04: nop

    // 0x800BDC08: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDC0C: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x800BDC10: addu        $t9, $ra, $t4
    ctx->r25 = ADD32(ctx->r31, ctx->r12);
    // 0x800BDC14: sb          $t7, -0x2($t0)
    MEM_B(-0X2, ctx->r8) = ctx->r15;
    // 0x800BDC18: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDC1C: nop

    // 0x800BDC20: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDC24: lbu         $t7, -0x1($t8)
    ctx->r15 = MEM_BU(ctx->r24, -0X1);
    // 0x800BDC28: nop

    // 0x800BDC2C: sb          $t7, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r15;
    // 0x800BDC30: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800BDC34: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800BDC38: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BDC3C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800BDC40: lh          $v0, 0x1A($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X1A);
    // 0x800BDC44: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x800BDC48: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BDC4C: bne         $at, $zero, L_800BDBD0
    if (ctx->r1 != 0) {
        // 0x800BDC50: nop
    
            goto L_800BDBD0;
    }
    // 0x800BDC50: nop

    // 0x800BDC54: sw          $zero, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = 0;
    // 0x800BDC58: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_800BDC5C:
    // 0x800BDC5C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BDC60: blez        $v0, L_800BE124
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BDC64: addiu       $v1, $v1, 0x370C
        ctx->r3 = ADD32(ctx->r3, 0X370C);
            goto L_800BE124;
    }
    // 0x800BDC64: addiu       $v1, $v1, 0x370C
    ctx->r3 = ADD32(ctx->r3, 0X370C);
    // 0x800BDC68: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800BDC6C: addiu       $t1, $sp, 0x160
    ctx->r9 = ADD32(ctx->r29, 0X160);
L_800BDC70:
    // 0x800BDC70: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BDC74: lw          $t7, 0x3668($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3668);
    // 0x800BDC78: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800BDC7C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BDC80: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    // 0x800BDC84: lbu         $t6, 0xB($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XB);
    // 0x800BDC88: lw          $a0, -0x5968($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5968);
    // 0x800BDC8C: lbu         $t8, 0xA($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDC90: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDC94: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800BDC98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDC9C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BDCA0: addu        $s5, $t8, $t7
    ctx->r21 = ADD32(ctx->r24, ctx->r15);
    // 0x800BDCA4: sll         $t6, $s5, 3
    ctx->r14 = S32(ctx->r21 << 3);
    // 0x800BDCA8: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BDCAC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800BDCB0: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x800BDCB4: beq         $t8, $at, L_800BE0FC
    if (ctx->r24 == ctx->r1) {
        // 0x800BDCB8: nop
    
            goto L_800BE0FC;
    }
    // 0x800BDCB8: nop

    // 0x800BDCBC: multu       $t7, $t7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDCC0: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800BDCC4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BDCC8: lw          $t3, -0x5964($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5964);
    // 0x800BDCCC: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x800BDCD0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800BDCD4: addiu       $t2, $a0, -0x1
    ctx->r10 = ADD32(ctx->r4, -0X1);
    // 0x800BDCD8: addiu       $v0, $sp, 0x140
    ctx->r2 = ADD32(ctx->r29, 0X140);
    // 0x800BDCDC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800BDCE0: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x800BDCE4: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x800BDCE8: mflo        $ra
    ctx->r31 = lo;
    // 0x800BDCEC: nop

    // 0x800BDCF0: nop

    // 0x800BDCF4: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDCF8: mflo        $t5
    ctx->r13 = lo;
    // 0x800BDCFC: nop

    // 0x800BDD00: nop

L_800BDD04:
    // 0x800BDD04: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BDD08: sltu        $at, $v0, $t1
    ctx->r1 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x800BDD0C: bne         $at, $zero, L_800BDD04
    if (ctx->r1 != 0) {
        // 0x800BDD10: sw          $v1, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r3;
            goto L_800BDD04;
    }
    // 0x800BDD10: sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
    // 0x800BDD14: lbu         $t7, 0xB($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XB);
    // 0x800BDD18: nop

    // 0x800BDD1C: blez        $t7, L_800BDD94
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800BDD20: nop
    
            goto L_800BDD94;
    }
    // 0x800BDD20: nop

    // 0x800BDD24: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDD28: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800BDD2C: blez        $t6, L_800BDD50
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BDD30: sll         $t8, $s5, 3
        ctx->r24 = S32(ctx->r21 << 3);
            goto L_800BDD50;
    }
    // 0x800BDD30: sll         $t8, $s5, 3
    ctx->r24 = S32(ctx->r21 << 3);
    // 0x800BDD34: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x800BDD38: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800BDD3C: negu        $t9, $t6
    ctx->r25 = SUB32(0, ctx->r14);
    // 0x800BDD40: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800BDD44: lw          $t6, -0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X8);
    // 0x800BDD48: nop

    // 0x800BDD4C: sw          $t6, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r14;
L_800BDD50:
    // 0x800BDD50: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x800BDD54: sll         $t9, $s5, 3
    ctx->r25 = S32(ctx->r21 << 3);
    // 0x800BDD58: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800BDD5C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800BDD60: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800BDD64: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x800BDD68: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800BDD6C: nop

    // 0x800BDD70: sw          $t9, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r25;
    // 0x800BDD74: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDD78: nop

    // 0x800BDD7C: slt         $at, $t6, $t2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BDD80: beq         $at, $zero, L_800BDD94
    if (ctx->r1 == 0) {
        // 0x800BDD84: nop
    
            goto L_800BDD94;
    }
    // 0x800BDD84: nop

    // 0x800BDD88: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800BDD8C: nop

    // 0x800BDD90: sw          $t8, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r24;
L_800BDD94:
    // 0x800BDD94: lbu         $v1, 0xA($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDD98: nop

    // 0x800BDD9C: blez        $v1, L_800BDDBC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BDDA0: slt         $at, $v1, $t2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800BDDBC;
    }
    // 0x800BDDA0: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BDDA4: lw          $t7, -0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X8);
    // 0x800BDDA8: nop

    // 0x800BDDAC: sw          $t7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r15;
    // 0x800BDDB0: lbu         $v1, 0xA($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDDB4: nop

    // 0x800BDDB8: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
L_800BDDBC:
    // 0x800BDDBC: beq         $at, $zero, L_800BDDD0
    if (ctx->r1 == 0) {
        // 0x800BDDC0: sll         $v1, $a0, 3
        ctx->r3 = S32(ctx->r4 << 3);
            goto L_800BDDD0;
    }
    // 0x800BDDC0: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x800BDDC4: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800BDDC8: nop

    // 0x800BDDCC: sw          $t9, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r25;
L_800BDDD0:
    // 0x800BDDD0: lbu         $t6, 0xB($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XB);
    // 0x800BDDD4: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x800BDDD8: slt         $at, $t6, $t3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BDDDC: beq         $at, $zero, L_800BDE34
    if (ctx->r1 == 0) {
        // 0x800BDDE0: nop
    
            goto L_800BDE34;
    }
    // 0x800BDDE0: nop

    // 0x800BDDE4: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDDE8: sll         $t7, $s5, 3
    ctx->r15 = S32(ctx->r21 << 3);
    // 0x800BDDEC: blez        $t9, L_800BDE04
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BDDF0: addu        $v0, $t8, $t7
        ctx->r2 = ADD32(ctx->r24, ctx->r15);
            goto L_800BDE04;
    }
    // 0x800BDDF0: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x800BDDF4: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x800BDDF8: lw          $t8, -0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X8);
    // 0x800BDDFC: nop

    // 0x800BDE00: sw          $t8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r24;
L_800BDE04:
    // 0x800BDE04: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x800BDE08: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800BDE0C: nop

    // 0x800BDE10: sw          $t7, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r15;
    // 0x800BDE14: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x800BDE18: nop

    // 0x800BDE1C: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BDE20: beq         $at, $zero, L_800BDE38
    if (ctx->r1 == 0) {
        // 0x800BDE24: lw          $t8, 0x140($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X140);
            goto L_800BDE38;
    }
    // 0x800BDE24: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x800BDE28: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800BDE2C: nop

    // 0x800BDE30: sw          $t6, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r14;
L_800BDE34:
    // 0x800BDE34: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
L_800BDE38:
    // 0x800BDE38: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800BDE3C: lbu         $a2, 0x0($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X0);
    // 0x800BDE40: beq         $a0, $t8, L_800BDE60
    if (ctx->r4 == ctx->r24) {
        // 0x800BDE44: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800BDE60;
    }
    // 0x800BDE44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800BDE48: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
    // 0x800BDE4C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BDE50: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDE54: lbu         $t6, 0x3($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X3);
    // 0x800BDE58: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BDE5C: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
L_800BDE60:
    // 0x800BDE60: lw          $t8, 0x144($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X144);
    // 0x800BDE64: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
    // 0x800BDE68: beq         $a0, $t8, L_800BDE84
    if (ctx->r4 == ctx->r24) {
        // 0x800BDE6C: nop
    
            goto L_800BDE84;
    }
    // 0x800BDE6C: nop

    // 0x800BDE70: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BDE74: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDE78: lbu         $t6, 0x2($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2);
    // 0x800BDE7C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDE80: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
L_800BDE84:
    // 0x800BDE84: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800BDE88: nop

    // 0x800BDE8C: beq         $a0, $t8, L_800BDEA8
    if (ctx->r4 == ctx->r24) {
        // 0x800BDE90: nop
    
            goto L_800BDEA8;
    }
    // 0x800BDE90: nop

    // 0x800BDE94: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BDE98: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDE9C: lbu         $t6, 0x1($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X1);
    // 0x800BDEA0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDEA4: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
L_800BDEA8:
    // 0x800BDEA8: div         $zero, $a2, $a3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r7)));
    // 0x800BDEAC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BDEB0: bne         $a3, $zero, L_800BDEBC
    if (ctx->r7 != 0) {
        // 0x800BDEB4: nop
    
            goto L_800BDEBC;
    }
    // 0x800BDEB4: nop

    // 0x800BDEB8: break       7
    do_break(2148261560);
L_800BDEBC:
    // 0x800BDEBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDEC0: bne         $a3, $at, L_800BDED4
    if (ctx->r7 != ctx->r1) {
        // 0x800BDEC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDED4;
    }
    // 0x800BDEC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDEC8: bne         $a2, $at, L_800BDED4
    if (ctx->r6 != ctx->r1) {
        // 0x800BDECC: nop
    
            goto L_800BDED4;
    }
    // 0x800BDECC: nop

    // 0x800BDED0: break       6
    do_break(2148261584);
L_800BDED4:
    // 0x800BDED4: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x800BDED8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800BDEDC: mflo        $t8
    ctx->r24 = lo;
    // 0x800BDEE0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BDEE4: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x800BDEE8: lbu         $a2, 0x1($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X1);
    // 0x800BDEEC: beq         $a0, $t6, L_800BDF08
    if (ctx->r4 == ctx->r14) {
        // 0x800BDEF0: nop
    
            goto L_800BDF08;
    }
    // 0x800BDEF0: nop

    // 0x800BDEF4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BDEF8: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDEFC: lbu         $t9, 0x3($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3);
    // 0x800BDF00: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BDF04: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDF08:
    // 0x800BDF08: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800BDF0C: nop

    // 0x800BDF10: beq         $a0, $t6, L_800BDF2C
    if (ctx->r4 == ctx->r14) {
        // 0x800BDF14: nop
    
            goto L_800BDF2C;
    }
    // 0x800BDF14: nop

    // 0x800BDF18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BDF1C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDF20: lbu         $t9, 0x2($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2);
    // 0x800BDF24: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDF28: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDF2C:
    // 0x800BDF2C: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x800BDF30: nop

    // 0x800BDF34: beq         $a0, $t6, L_800BDF50
    if (ctx->r4 == ctx->r14) {
        // 0x800BDF38: nop
    
            goto L_800BDF50;
    }
    // 0x800BDF38: nop

    // 0x800BDF3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BDF40: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDF44: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800BDF48: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDF4C: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDF50:
    // 0x800BDF50: div         $zero, $a2, $a3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r7)));
    // 0x800BDF54: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BDF58: bne         $a3, $zero, L_800BDF64
    if (ctx->r7 != 0) {
        // 0x800BDF5C: nop
    
            goto L_800BDF64;
    }
    // 0x800BDF5C: nop

    // 0x800BDF60: break       7
    do_break(2148261728);
L_800BDF64:
    // 0x800BDF64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDF68: bne         $a3, $at, L_800BDF7C
    if (ctx->r7 != ctx->r1) {
        // 0x800BDF6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDF7C;
    }
    // 0x800BDF6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDF70: bne         $a2, $at, L_800BDF7C
    if (ctx->r6 != ctx->r1) {
        // 0x800BDF74: nop
    
            goto L_800BDF7C;
    }
    // 0x800BDF74: nop

    // 0x800BDF78: break       6
    do_break(2148261752);
L_800BDF7C:
    // 0x800BDF7C: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x800BDF80: addu        $t9, $t8, $s4
    ctx->r25 = ADD32(ctx->r24, ctx->r20);
    // 0x800BDF84: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800BDF88: mflo        $t6
    ctx->r14 = lo;
    // 0x800BDF8C: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800BDF90: lw          $t7, 0x14C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14C);
    // 0x800BDF94: lbu         $a2, 0x2($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X2);
    // 0x800BDF98: beq         $a0, $t7, L_800BDFB4
    if (ctx->r4 == ctx->r15) {
        // 0x800BDF9C: nop
    
            goto L_800BDFB4;
    }
    // 0x800BDF9C: nop

    // 0x800BDFA0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BDFA4: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800BDFA8: lbu         $t9, 0x3($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X3);
    // 0x800BDFAC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BDFB0: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDFB4:
    // 0x800BDFB4: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x800BDFB8: nop

    // 0x800BDFBC: beq         $a0, $t7, L_800BDFD8
    if (ctx->r4 == ctx->r15) {
        // 0x800BDFC0: nop
    
            goto L_800BDFD8;
    }
    // 0x800BDFC0: nop

    // 0x800BDFC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BDFC8: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800BDFCC: lbu         $t9, 0x1($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X1);
    // 0x800BDFD0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDFD4: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDFD8:
    // 0x800BDFD8: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x800BDFDC: nop

    // 0x800BDFE0: beq         $a0, $t7, L_800BDFFC
    if (ctx->r4 == ctx->r15) {
        // 0x800BDFE4: nop
    
            goto L_800BDFFC;
    }
    // 0x800BDFE4: nop

    // 0x800BDFE8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BDFEC: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800BDFF0: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x800BDFF4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDFF8: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDFFC:
    // 0x800BDFFC: div         $zero, $a2, $a3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r7)));
    // 0x800BE000: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800BE004: bne         $a3, $zero, L_800BE010
    if (ctx->r7 != 0) {
        // 0x800BE008: nop
    
            goto L_800BE010;
    }
    // 0x800BE008: nop

    // 0x800BE00C: break       7
    do_break(2148261900);
L_800BE010:
    // 0x800BE010: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BE014: bne         $a3, $at, L_800BE028
    if (ctx->r7 != ctx->r1) {
        // 0x800BE018: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BE028;
    }
    // 0x800BE018: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE01C: bne         $a2, $at, L_800BE028
    if (ctx->r6 != ctx->r1) {
        // 0x800BE020: nop
    
            goto L_800BE028;
    }
    // 0x800BE020: nop

    // 0x800BE024: break       6
    do_break(2148261924);
L_800BE028:
    // 0x800BE028: addu        $t6, $t8, $t4
    ctx->r14 = ADD32(ctx->r24, ctx->r12);
    // 0x800BE02C: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x800BE030: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800BE034: mflo        $t7
    ctx->r15 = lo;
    // 0x800BE038: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x800BE03C: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x800BE040: lbu         $a2, 0x3($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X3);
    // 0x800BE044: beq         $a0, $t8, L_800BE060
    if (ctx->r4 == ctx->r24) {
        // 0x800BE048: nop
    
            goto L_800BE060;
    }
    // 0x800BE048: nop

    // 0x800BE04C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800BE050: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800BE054: lbu         $t9, 0x2($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X2);
    // 0x800BE058: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BE05C: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BE060:
    // 0x800BE060: lw          $t8, 0x158($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X158);
    // 0x800BE064: nop

    // 0x800BE068: beq         $a0, $t8, L_800BE084
    if (ctx->r4 == ctx->r24) {
        // 0x800BE06C: nop
    
            goto L_800BE084;
    }
    // 0x800BE06C: nop

    // 0x800BE070: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800BE074: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800BE078: lbu         $t9, 0x1($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X1);
    // 0x800BE07C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BE080: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BE084:
    // 0x800BE084: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x800BE088: nop

    // 0x800BE08C: beq         $a0, $t8, L_800BE0A8
    if (ctx->r4 == ctx->r24) {
        // 0x800BE090: nop
    
            goto L_800BE0A8;
    }
    // 0x800BE090: nop

    // 0x800BE094: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800BE098: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800BE09C: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BE0A0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BE0A4: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BE0A8:
    // 0x800BE0A8: div         $zero, $a2, $a3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r7)));
    // 0x800BE0AC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BE0B0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BE0B4: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x800BE0B8: addu        $t9, $t7, $ra
    ctx->r25 = ADD32(ctx->r15, ctx->r31);
    // 0x800BE0BC: addiu       $v1, $v1, 0x370C
    ctx->r3 = ADD32(ctx->r3, 0X370C);
    // 0x800BE0C0: bne         $a3, $zero, L_800BE0CC
    if (ctx->r7 != 0) {
        // 0x800BE0C4: nop
    
            goto L_800BE0CC;
    }
    // 0x800BE0C4: nop

    // 0x800BE0C8: break       7
    do_break(2148262088);
L_800BE0CC:
    // 0x800BE0CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BE0D0: bne         $a3, $at, L_800BE0E4
    if (ctx->r7 != ctx->r1) {
        // 0x800BE0D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BE0E4;
    }
    // 0x800BE0D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BE0D8: bne         $a2, $at, L_800BE0E4
    if (ctx->r6 != ctx->r1) {
        // 0x800BE0DC: nop
    
            goto L_800BE0E4;
    }
    // 0x800BE0DC: nop

    // 0x800BE0E0: break       6
    do_break(2148262112);
L_800BE0E4:
    // 0x800BE0E4: mflo        $t8
    ctx->r24 = lo;
    // 0x800BE0E8: sb          $t8, -0x1($t9)
    MEM_B(-0X1, ctx->r25) = ctx->r24;
    // 0x800BE0EC: lw          $t6, 0x190($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X190);
    // 0x800BE0F0: nop

    // 0x800BE0F4: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x800BE0F8: nop

L_800BE0FC:
    // 0x800BE0FC: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800BE100: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800BE104: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BE108: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800BE10C: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BE110: addiu       $t6, $t9, 0x1C
    ctx->r14 = ADD32(ctx->r25, 0X1C);
    // 0x800BE114: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    // 0x800BE118: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800BE11C: bne         $at, $zero, L_800BDC70
    if (ctx->r1 != 0) {
        // 0x800BE120: addu        $t4, $t4, $t7
        ctx->r12 = ADD32(ctx->r12, ctx->r15);
            goto L_800BDC70;
    }
    // 0x800BE120: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
L_800BE124:
    // 0x800BE124: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BE128: jal         0x80071380
    // 0x800BE12C: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800BE12C: nop

    after_6:
    // 0x800BE130: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x800BE134: jal         0x80071380
    // 0x800BE138: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x800BE138: nop

    after_7:
    // 0x800BE13C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800BE140: jal         0x80071380
    // 0x800BE144: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x800BE144: nop

    after_8:
    // 0x800BE148: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800BE14C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BE150: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BE154: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BE158: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BE15C: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BE160: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BE164: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BE168: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BE16C: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800BE170: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BE174: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800BE178: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800BE17C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800BE180: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800BE184: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800BE188: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800BE18C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800BE190: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800BE194: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800BE198: jr          $ra
    // 0x800BE19C: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
    return;
    // 0x800BE19C: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
;}
RECOMP_FUNC void func_800BDC80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE1A0: addiu       $sp, $sp, -0x370
    ctx->r29 = ADD32(ctx->r29, -0X370);
    // 0x800BE1A4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BE1A8: lw          $t6, 0x370C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X370C);
    // 0x800BE1AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE1B0: multu       $a0, $t6
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE1B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BE1B8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800BE1BC: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BE1C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE1C4: lwc1        $f4, -0x5988($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800BE1C8: addiu       $a3, $a3, -0x5A78
    ctx->r7 = ADD32(ctx->r7, -0X5A78);
    // 0x800BE1CC: lwc1        $f8, 0x44($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X44);
    // 0x800BE1D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE1D4: lwc1        $f6, -0x5984($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x800BE1D8: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800BE1DC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800BE1E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BE1E4: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800BE1E8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800BE1EC: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BE1F0: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800BE1F4: mflo        $t0
    ctx->r8 = lo;
    // 0x800BE1F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BE1FC: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800BE200: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800BE204: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800BE208: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800BE20C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800BE210: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800BE214: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800BE218: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800BE21C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800BE220: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800BE224: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x800BE228: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800BE22C: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x800BE230: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800BE234: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x800BE238: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BE23C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800BE240: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BE244: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BE248: sw          $a1, 0x374($sp)
    MEM_W(0X374, ctx->r29) = ctx->r5;
    // 0x800BE24C: sw          $a2, 0x378($sp)
    MEM_W(0X378, ctx->r29) = ctx->r6;
    // 0x800BE250: swc1        $f4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f4.u32l;
    // 0x800BE254: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x800BE258: beq         $t7, $zero, L_800BE2A4
    if (ctx->r15 == 0) {
        // 0x800BE25C: div.s       $f24, $f10, $f8
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
            goto L_800BE2A4;
    }
    // 0x800BE25C: div.s       $f24, $f10, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BE260: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x800BE264: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800BE268: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x800BE26C: cvt.d.s     $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f28.d = CVT_D_S(ctx->f4.fl);
    // 0x800BE270: mul.d       $f28, $f28, $f30
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.d); NAN_CHECK(ctx->f30.d); 
    ctx->f28.d = MUL_D(ctx->f28.d, ctx->f30.d);
    // 0x800BE274: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800BE278: cvt.d.s     $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f26.d = CVT_D_S(ctx->f6.fl);
    // 0x800BE27C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BE280: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800BE284: mul.d       $f30, $f26, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.d); NAN_CHECK(ctx->f30.d); 
    ctx->f30.d = MUL_D(ctx->f26.d, ctx->f30.d);
    // 0x800BE288: cvt.s.d     $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.d); 
    ctx->f4.fl = CVT_S_D(ctx->f28.d);
    // 0x800BE28C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BE290: swc1        $f4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f4.u32l;
    // 0x800BE294: sw          $t9, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = ctx->r25;
    // 0x800BE298: cvt.s.d     $f4, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.d); 
    ctx->f4.fl = CVT_S_D(ctx->f30.d);
    // 0x800BE29C: b           L_800BE2B0
    // 0x800BE2A0: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
        goto L_800BE2B0;
    // 0x800BE2A0: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
L_800BE2A4:
    // 0x800BE2A4: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800BE2A8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800BE2AC: sw          $t2, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = ctx->r10;
L_800BE2B0:
    // 0x800BE2B0: sll         $t3, $s0, 3
    ctx->r11 = S32(ctx->r16 << 3);
    // 0x800BE2B4: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x800BE2B8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BE2BC: lw          $t4, 0x3668($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3668);
    // 0x800BE2C0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800BE2C4: sw          $t3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r11;
    // 0x800BE2C8: addu        $a2, $t4, $t3
    ctx->r6 = ADD32(ctx->r12, ctx->r11);
    // 0x800BE2CC: lh          $t6, 0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4);
    // 0x800BE2D0: lh          $t1, 0x8($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X8);
    // 0x800BE2D4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800BE2D8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800BE2DC: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BE2E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BE2E4: lwc1        $f14, 0x380($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X380);
    // 0x800BE2E8: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800BE2EC: lwc1        $f16, 0x384($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X384);
    // 0x800BE2F0: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BE2F4: lwc1        $f18, 0x388($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X388);
    // 0x800BE2F8: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE2FC: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800BE300: sub.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800BE304: sub.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800BE308: bc1f        L_800BE318
    if (!c1cs) {
        // 0x800BE30C: sub.s       $f18, $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f2.fl;
            goto L_800BE318;
    }
    // 0x800BE30C: sub.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800BE310: b           L_800BE34C
    // 0x800BE314: sw          $zero, 0x368($sp)
    MEM_W(0X368, ctx->r29) = 0;
        goto L_800BE34C;
    // 0x800BE314: sw          $zero, 0x368($sp)
    MEM_W(0X368, ctx->r29) = 0;
L_800BE318:
    // 0x800BE318: nop

    // 0x800BE31C: div.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800BE320: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800BE324: nop

    // 0x800BE328: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800BE32C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE330: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE334: nop

    // 0x800BE338: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE33C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800BE340: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800BE344: sw          $t8, 0x368($sp)
    MEM_W(0X368, ctx->r29) = ctx->r24;
    // 0x800BE348: nop

L_800BE34C:
    // 0x800BE34C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BE350: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE354: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x800BE358: nop

    // 0x800BE35C: bc1f        L_800BE370
    if (!c1cs) {
        // 0x800BE360: nop
    
            goto L_800BE370;
    }
    // 0x800BE360: nop

    // 0x800BE364: b           L_800BE3A0
    // 0x800BE368: sw          $zero, 0x364($sp)
    MEM_W(0X364, ctx->r29) = 0;
        goto L_800BE3A0;
    // 0x800BE368: sw          $zero, 0x364($sp)
    MEM_W(0X364, ctx->r29) = 0;
    // 0x800BE36C: nop

L_800BE370:
    // 0x800BE370: div.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800BE374: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BE378: nop

    // 0x800BE37C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BE380: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE384: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE388: nop

    // 0x800BE38C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE390: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800BE394: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BE398: sw          $t2, 0x364($sp)
    MEM_W(0X364, ctx->r29) = ctx->r10;
    // 0x800BE39C: nop

L_800BE3A0:
    // 0x800BE3A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE3A4: lwc1        $f8, -0x59A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800BE3A8: lw          $t3, 0x36C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X36C);
    // 0x800BE3AC: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x800BE3B0: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE3B4: bc1f        L_800BE3C8
    if (!c1cs) {
        // 0x800BE3B8: nop
    
            goto L_800BE3C8;
    }
    // 0x800BE3B8: nop

    // 0x800BE3BC: b           L_800BE3F8
    // 0x800BE3C0: sw          $t3, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->r11;
        goto L_800BE3F8;
    // 0x800BE3C0: sw          $t3, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->r11;
    // 0x800BE3C4: nop

L_800BE3C8:
    // 0x800BE3C8: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800BE3CC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BE3D0: nop

    // 0x800BE3D4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BE3D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE3DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE3E0: nop

    // 0x800BE3E4: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE3E8: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800BE3EC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BE3F0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800BE3F4: sw          $t6, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->r14;
L_800BE3F8:
    // 0x800BE3F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE3FC: lwc1        $f8, -0x599C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800BE400: lw          $t7, 0x36C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X36C);
    // 0x800BE404: c.le.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl <= ctx->f18.fl;
    // 0x800BE408: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE40C: bc1f        L_800BE420
    if (!c1cs) {
        // 0x800BE410: nop
    
            goto L_800BE420;
    }
    // 0x800BE410: nop

    // 0x800BE414: b           L_800BE450
    // 0x800BE418: sw          $t7, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->r15;
        goto L_800BE450;
    // 0x800BE418: sw          $t7, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->r15;
    // 0x800BE41C: nop

L_800BE420:
    // 0x800BE420: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800BE424: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BE428: nop

    // 0x800BE42C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BE430: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE434: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE438: nop

    // 0x800BE43C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE440: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800BE444: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BE448: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800BE44C: sw          $t2, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->r10;
L_800BE450:
    // 0x800BE450: lh          $t3, 0x12($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X12);
    // 0x800BE454: lw          $t4, 0x368($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X368);
    // 0x800BE458: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x800BE45C: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x800BE460: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE464: bne         $at, $zero, L_800BE47C
    if (ctx->r1 != 0) {
        // 0x800BE468: nop
    
            goto L_800BE47C;
    }
    // 0x800BE468: nop

L_800BE46C:
    // 0x800BE46C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800BE470: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE474: beq         $at, $zero, L_800BE46C
    if (ctx->r1 == 0) {
        // 0x800BE478: nop
    
            goto L_800BE46C;
    }
    // 0x800BE478: nop

L_800BE47C:
    // 0x800BE47C: lh          $t5, 0x10($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X10);
    // 0x800BE480: lw          $t6, 0x364($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X364);
    // 0x800BE484: lw          $t7, 0x364($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X364);
    // 0x800BE488: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x800BE48C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE490: bne         $at, $zero, L_800BE4AC
    if (ctx->r1 != 0) {
        // 0x800BE494: lw          $t8, 0x354($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X354);
            goto L_800BE4AC;
    }
    // 0x800BE494: lw          $t8, 0x354($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X354);
L_800BE498:
    // 0x800BE498: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800BE49C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE4A0: beq         $at, $zero, L_800BE498
    if (ctx->r1 == 0) {
        // 0x800BE4A4: nop
    
            goto L_800BE498;
    }
    // 0x800BE4A4: nop

    // 0x800BE4A8: lw          $t8, 0x354($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X354);
L_800BE4AC:
    // 0x800BE4AC: or          $s6, $t7, $zero
    ctx->r22 = ctx->r15 | 0;
    // 0x800BE4B0: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BE4B4: bne         $at, $zero, L_800BE690
    if (ctx->r1 != 0) {
        // 0x800BE4B8: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_800BE690;
    }
    // 0x800BE4B8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800BE4BC: lw          $t3, 0x36C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X36C);
    // 0x800BE4C0: lw          $t9, 0x368($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X368);
    // 0x800BE4C4: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE4C8: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x800BE4CC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800BE4D0: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800BE4D4: addiu       $fp, $fp, 0x35D0
    ctx->r30 = ADD32(ctx->r30, 0X35D0);
    // 0x800BE4D8: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
    // 0x800BE4DC: sw          $v0, 0x34C($sp)
    MEM_W(0X34C, ctx->r29) = ctx->r2;
    // 0x800BE4E0: sw          $v1, 0x350($sp)
    MEM_W(0X350, ctx->r29) = ctx->r3;
    // 0x800BE4E4: sw          $s0, 0x370($sp)
    MEM_W(0X370, ctx->r29) = ctx->r16;
    // 0x800BE4E8: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x800BE4EC: mflo        $t4
    ctx->r12 = lo;
    // 0x800BE4F0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800BE4F4: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
L_800BE4F8:
    // 0x800BE4F8: lw          $v0, 0x34C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34C);
    // 0x800BE4FC: lw          $t3, 0x358($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X358);
    // 0x800BE500: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE504: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BE508: sll         $t2, $s7, 1
    ctx->r10 = S32(ctx->r23 << 1);
    // 0x800BE50C: addiu       $t4, $sp, 0xD8
    ctx->r12 = ADD32(ctx->r29, 0XD8);
    // 0x800BE510: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BE514: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800BE518: addu        $s3, $t2, $t4
    ctx->r19 = ADD32(ctx->r10, ctx->r12);
    // 0x800BE51C: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x800BE520: addiu       $s5, $t3, 0x1
    ctx->r21 = ADD32(ctx->r11, 0X1);
    // 0x800BE524: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800BE528: mflo        $t7
    ctx->r15 = lo;
    // 0x800BE52C: addu        $s2, $t7, $v1
    ctx->r18 = ADD32(ctx->r15, ctx->r3);
    // 0x800BE530: bne         $at, $zero, L_800BE658
    if (ctx->r1 != 0) {
        // 0x800BE534: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800BE658;
    }
L_800BE534:
    // 0x800BE534: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800BE538: lw          $t5, 0x35D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X35D4);
    // 0x800BE53C: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x800BE540: addu        $v1, $t5, $t8
    ctx->r3 = ADD32(ctx->r13, ctx->r24);
    // 0x800BE544: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800BE548: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800BE54C: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x800BE550: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800BE554: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800BE558: addu        $t3, $v0, $t4
    ctx->r11 = ADD32(ctx->r2, ctx->r12);
    // 0x800BE55C: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x800BE560: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BE564: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800BE568: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x800BE56C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800BE570: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800BE574: lw          $t5, 0x3718($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3718);
    // 0x800BE578: mul.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BE57C: blez        $t5, L_800BE5B0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800BE580: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800BE5B0;
    }
    // 0x800BE580: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800BE584: lw          $a0, 0x370($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X370);
    // 0x800BE588: jal         0x800BF4E4
    // 0x800BE58C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800BE58C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_0:
    // 0x800BE590: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BE594: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800BE598: lw          $t8, 0x3668($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3668);
    // 0x800BE59C: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800BE5A0: addiu       $a3, $a3, -0x5A78
    ctx->r7 = ADD32(ctx->r7, -0X5A78);
    // 0x800BE5A4: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x800BE5A8: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x800BE5AC: addu        $a2, $t8, $t6
    ctx->r6 = ADD32(ctx->r24, ctx->r14);
L_800BE5B0:
    // 0x800BE5B0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BE5B4: lw          $t9, 0x3708($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3708);
    // 0x800BE5B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800BE5BC: addu        $t7, $t9, $s4
    ctx->r15 = ADD32(ctx->r25, ctx->r20);
    // 0x800BE5C0: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800BE5C4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800BE5C8: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BE5CC: beq         $at, $zero, L_800BE5F0
    if (ctx->r1 == 0) {
        // 0x800BE5D0: nop
    
            goto L_800BE5F0;
    }
    // 0x800BE5D0: nop

    // 0x800BE5D4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800BE5D8: lwc1        $f8, 0x44($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X44);
    // 0x800BE5DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BE5E0: mul.s       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800BE5E4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BE5E8: mul.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800BE5EC: nop

L_800BE5F0:
    // 0x800BE5F0: mul.s       $f6, $f20, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800BE5F4: lh          $t2, 0x6($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X6);
    // 0x800BE5F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BE5FC: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800BE600: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BE604: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800BE608: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BE60C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE610: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE614: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE618: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE61C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BE620: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800BE624: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BE628: addu        $t6, $t2, $t8
    ctx->r14 = ADD32(ctx->r10, ctx->r24);
    // 0x800BE62C: bne         $at, $zero, L_800BE63C
    if (ctx->r1 != 0) {
        // 0x800BE630: sh          $t6, -0x2($s3)
        MEM_H(-0X2, ctx->r19) = ctx->r14;
            goto L_800BE63C;
    }
    // 0x800BE630: sh          $t6, -0x2($s3)
    MEM_H(-0X2, ctx->r19) = ctx->r14;
    // 0x800BE634: subu        $s0, $s0, $a0
    ctx->r16 = SUB32(ctx->r16, ctx->r4);
    // 0x800BE638: subu        $s2, $s2, $a0
    ctx->r18 = SUB32(ctx->r18, ctx->r4);
L_800BE63C:
    // 0x800BE63C: bne         $s5, $s1, L_800BE534
    if (ctx->r21 != ctx->r17) {
        // 0x800BE640: nop
    
            goto L_800BE534;
    }
    // 0x800BE640: nop

    // 0x800BE644: lw          $t0, 0x368($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X368);
    // 0x800BE648: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BE64C: lw          $v1, 0x350($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X350);
    // 0x800BE650: lw          $v0, 0x34C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34C);
    // 0x800BE654: nop

L_800BE658:
    // 0x800BE658: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BE65C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE660: bne         $at, $zero, L_800BE66C
    if (ctx->r1 != 0) {
        // 0x800BE664: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800BE66C;
    }
    // 0x800BE664: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800BE668: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
L_800BE66C:
    // 0x800BE66C: lw          $t9, 0x36C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X36C);
    // 0x800BE670: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x800BE674: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x800BE678: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x800BE67C: bne         $t7, $s6, L_800BE4F8
    if (ctx->r15 != ctx->r22) {
        // 0x800BE680: sw          $v0, 0x34C($sp)
        MEM_W(0X34C, ctx->r29) = ctx->r2;
            goto L_800BE4F8;
    }
    // 0x800BE680: sw          $v0, 0x34C($sp)
    MEM_W(0X34C, ctx->r29) = ctx->r2;
    // 0x800BE684: lh          $t1, 0x8($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X8);
    // 0x800BE688: lw          $s6, 0x364($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X364);
    // 0x800BE68C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_800BE690:
    // 0x800BE690: lw          $t8, 0x364($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X364);
    // 0x800BE694: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE698: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BE69C: lw          $t4, 0x358($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X358);
    // 0x800BE6A0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BE6A4: lw          $t3, 0x368($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X368);
    // 0x800BE6A8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800BE6AC: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800BE6B0: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x800BE6B4: sw          $t2, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = ctx->r10;
    // 0x800BE6B8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800BE6BC: nop

    // 0x800BE6C0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800BE6C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE6C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE6CC: nop

    // 0x800BE6D0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BE6D4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800BE6D8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800BE6DC: lw          $t6, 0x354($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X354);
    // 0x800BE6E0: addu        $a1, $t1, $t4
    ctx->r5 = ADD32(ctx->r9, ctx->r12);
    // 0x800BE6E4: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x800BE6E8: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BE6EC: beq         $at, $zero, L_800BEB10
    if (ctx->r1 == 0) {
        // 0x800BE6F0: sra         $a1, $t5, 16
        ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
            goto L_800BEB10;
    }
    // 0x800BE6F0: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800BE6F4: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800BE6F8: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE6FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BE700: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BE704: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BE708: nop

    // 0x800BE70C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BE710: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE714: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE718: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE71C: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800BE720: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800BE724: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800BE728: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BE72C: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800BE730: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800BE734: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
L_800BE738:
    // 0x800BE738: addiu       $v0, $s6, 0x1
    ctx->r2 = ADD32(ctx->r22, 0X1);
    // 0x800BE73C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800BE740: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE744: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BE748: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BE74C: lw          $t2, 0x3668($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3668);
    // 0x800BE750: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BE754: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x800BE758: nop

    // 0x800BE75C: addu        $a2, $t2, $t8
    ctx->r6 = ADD32(ctx->r10, ctx->r24);
    // 0x800BE760: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800BE764: lh          $t4, 0x8($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X8);
    // 0x800BE768: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800BE76C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE770: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE774: lh          $t8, 0x4($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X4);
    // 0x800BE778: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800BE77C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800BE780: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800BE784: addu        $fp, $t4, $t7
    ctx->r30 = ADD32(ctx->r12, ctx->r15);
    // 0x800BE788: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800BE78C: lw          $t7, 0x358($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X358);
    // 0x800BE790: lw          $t4, 0x368($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X368);
    // 0x800BE794: addu        $s3, $t8, $t6
    ctx->r19 = ADD32(ctx->r24, ctx->r14);
    // 0x800BE798: sll         $t5, $fp, 16
    ctx->r13 = S32(ctx->r30 << 16);
    // 0x800BE79C: sll         $t3, $s3, 16
    ctx->r11 = S32(ctx->r19 << 16);
    // 0x800BE7A0: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BE7A4: sra         $fp, $t5, 16
    ctx->r30 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800BE7A8: sra         $s3, $t3, 16
    ctx->r19 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800BE7AC: beq         $at, $zero, L_800BEAF8
    if (ctx->r1 == 0) {
        // 0x800BE7B0: or          $s1, $t4, $zero
        ctx->r17 = ctx->r12 | 0;
            goto L_800BEAF8;
    }
    // 0x800BE7B0: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x800BE7B4: lw          $t9, 0x364($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X364);
    // 0x800BE7B8: lw          $t7, 0x36C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X36C);
    // 0x800BE7BC: subu        $a2, $s6, $t9
    ctx->r6 = SUB32(ctx->r22, ctx->r25);
    // 0x800BE7C0: multu       $a2, $t7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE7C4: sll         $t2, $s7, 2
    ctx->r10 = S32(ctx->r23 << 2);
    // 0x800BE7C8: lw          $t5, 0x374($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X374);
    // 0x800BE7CC: addu        $t2, $t2, $s7
    ctx->r10 = ADD32(ctx->r10, ctx->r23);
    // 0x800BE7D0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800BE7D4: addu        $s0, $t5, $t2
    ctx->r16 = ADD32(ctx->r13, ctx->r10);
    // 0x800BE7D8: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
    // 0x800BE7DC: subu        $t8, $t4, $t4
    ctx->r24 = SUB32(ctx->r12, ctx->r12);
    // 0x800BE7E0: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x800BE7E4: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800BE7E8: addiu       $t3, $sp, 0xD8
    ctx->r11 = ADD32(ctx->r29, 0XD8);
    // 0x800BE7EC: lwc1        $f0, 0xCC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE7F0: mflo        $a3
    ctx->r7 = lo;
    // 0x800BE7F4: addu        $v0, $t6, $t3
    ctx->r2 = ADD32(ctx->r14, ctx->r11);
    // 0x800BE7F8: sll         $t5, $a3, 1
    ctx->r13 = S32(ctx->r7 << 1);
    // 0x800BE7FC: multu       $t2, $t7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE800: mul.s       $f26, $f0, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800BE804: negu        $at, $t4
    ctx->r1 = SUB32(0, ctx->r12);
    // 0x800BE808: sll         $t3, $at, 1
    ctx->r11 = S32(ctx->r1 << 1);
    // 0x800BE80C: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x800BE810: addu        $s4, $v0, $t5
    ctx->r20 = ADD32(ctx->r2, ctx->r13);
    // 0x800BE814: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800BE818: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x800BE81C: addiu       $t5, $sp, 0xD8
    ctx->r13 = ADD32(ctx->r29, 0XD8);
    // 0x800BE820: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x800BE824: mul.s       $f28, $f26, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x800BE828: addu        $v1, $t1, $a3
    ctx->r3 = ADD32(ctx->r9, ctx->r7);
    // 0x800BE82C: mflo        $t0
    ctx->r8 = lo;
    // 0x800BE830: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x800BE834: addu        $s5, $v0, $t8
    ctx->r21 = ADD32(ctx->r2, ctx->r24);
    // 0x800BE838: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
L_800BE83C:
    // 0x800BE83C: addiu       $s6, $s1, 0x1
    ctx->r22 = ADD32(ctx->r17, 0X1);
    // 0x800BE840: mtc1        $s6, $f8
    ctx->f8.u32l = ctx->r22;
    // 0x800BE844: lwc1        $f0, 0xCC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE848: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE84C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BE850: lw          $t2, 0x3668($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3668);
    // 0x800BE854: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800BE858: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800BE85C: lwc1        $f2, 0xC8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE860: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x800BE864: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800BE868: lh          $t4, 0x4($t8)
    ctx->r12 = MEM_H(ctx->r24, 0X4);
    // 0x800BE86C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800BE870: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE874: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE878: sh          $s3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r19;
    // 0x800BE87C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE880: sh          $s3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r19;
    // 0x800BE884: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800BE888: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800BE88C: addu        $s2, $t4, $t5
    ctx->r18 = ADD32(ctx->r12, ctx->r13);
    // 0x800BE890: sll         $t2, $s2, 16
    ctx->r10 = S32(ctx->r18 << 16);
    // 0x800BE894: sra         $s2, $t2, 16
    ctx->r18 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800BE898: sh          $s2, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r18;
    // 0x800BE89C: lh          $t8, 0x0($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X0);
    // 0x800BE8A0: nop

    // 0x800BE8A4: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800BE8A8: lh          $t6, 0x0($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X0);
    // 0x800BE8AC: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x800BE8B0: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x800BE8B4: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x800BE8B8: lh          $t5, 0x8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8);
    // 0x800BE8BC: sh          $t3, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r11;
    // 0x800BE8C0: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
    // 0x800BE8C4: subu        $t2, $v0, $t5
    ctx->r10 = SUB32(ctx->r2, ctx->r13);
    // 0x800BE8C8: subu        $t4, $v0, $t9
    ctx->r12 = SUB32(ctx->r2, ctx->r25);
    // 0x800BE8CC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800BE8D0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800BE8D4: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE8D8: sh          $a1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r5;
    // 0x800BE8DC: sh          $fp, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r30;
    // 0x800BE8E0: mul.s       $f20, $f4, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BE8E4: sh          $a1, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r5;
    // 0x800BE8E8: sh          $a1, 0x332($sp)
    MEM_H(0X332, ctx->r29) = ctx->r5;
    // 0x800BE8EC: sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
    // 0x800BE8F0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BE8F4: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    // 0x800BE8F8: mul.s       $f22, $f10, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BE8FC: nop

    // 0x800BE900: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800BE904: nop

    // 0x800BE908: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800BE90C: add.s       $f4, $f8, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x800BE910: jal         0x800CA030
    // 0x800BE914: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800BE914: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x800BE918: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BE91C: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x800BE920: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800BE924: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800BE928: lh          $a1, 0x332($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X332);
    // 0x800BE92C: bc1f        L_800BE9A8
    if (!c1cs) {
        // 0x800BE930: nop
    
            goto L_800BE9A8;
    }
    // 0x800BE930: nop

    // 0x800BE934: div.s       $f24, $f30, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
    // 0x800BE938: lw          $t7, 0x378($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X378);
    // 0x800BE93C: sll         $t8, $s7, 4
    ctx->r24 = S32(ctx->r23 << 4);
    // 0x800BE940: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800BE944: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800BE948: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800BE94C: mul.s       $f2, $f20, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800BE950: nop

    // 0x800BE954: mul.s       $f14, $f26, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x800BE958: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800BE95C: mul.s       $f12, $f22, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x800BE960: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x800BE964: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x800BE968: lh          $t6, -0x14($s0)
    ctx->r14 = MEM_H(ctx->r16, -0X14);
    // 0x800BE96C: lh          $t3, -0x12($s0)
    ctx->r11 = MEM_H(ctx->r16, -0X12);
    // 0x800BE970: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800BE974: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800BE978: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE97C: lh          $t9, -0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X10);
    // 0x800BE980: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BE984: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BE988: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BE98C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800BE990: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BE994: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE998: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800BE99C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800BE9A0: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x800BE9A4: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
L_800BE9A8:
    // 0x800BE9A8: sh          $s2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r18;
    // 0x800BE9AC: sh          $s3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r19;
    // 0x800BE9B0: sh          $s2, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r18;
    // 0x800BE9B4: lh          $t4, 0x2($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X2);
    // 0x800BE9B8: nop

    // 0x800BE9BC: sh          $t4, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r12;
    // 0x800BE9C0: lh          $t5, 0x0($s5)
    ctx->r13 = MEM_H(ctx->r21, 0X0);
    // 0x800BE9C4: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x800BE9C8: sh          $t5, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r13;
    // 0x800BE9CC: lh          $t2, 0x2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2);
    // 0x800BE9D0: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x800BE9D4: sh          $t2, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r10;
    // 0x800BE9D8: lh          $v0, 0xE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE);
    // 0x800BE9DC: sh          $a1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r5;
    // 0x800BE9E0: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x800BE9E4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800BE9E8: sh          $fp, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r30;
    // 0x800BE9EC: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BE9F0: sh          $fp, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r30;
    // 0x800BE9F4: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE9F8: subu        $t3, $t6, $v0
    ctx->r11 = SUB32(ctx->r14, ctx->r2);
    // 0x800BE9FC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800BEA00: mul.s       $f20, $f10, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BEA04: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BEA08: sh          $a1, 0x332($sp)
    MEM_H(0X332, ctx->r29) = ctx->r5;
    // 0x800BEA0C: sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
    // 0x800BEA10: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BEA14: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    // 0x800BEA18: mul.s       $f22, $f4, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BEA1C: nop

    // 0x800BEA20: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800BEA24: nop

    // 0x800BEA28: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800BEA2C: add.s       $f6, $f8, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x800BEA30: jal         0x800CA030
    // 0x800BEA34: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800BEA34: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_2:
    // 0x800BEA38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BEA3C: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x800BEA40: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800BEA44: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800BEA48: lh          $a1, 0x332($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X332);
    // 0x800BEA4C: bc1f        L_800BEACC
    if (!c1cs) {
        // 0x800BEA50: sll         $s3, $s2, 16
        ctx->r19 = S32(ctx->r18 << 16);
            goto L_800BEACC;
    }
    // 0x800BEA50: sll         $s3, $s2, 16
    ctx->r19 = S32(ctx->r18 << 16);
    // 0x800BEA54: nop

    // 0x800BEA58: div.s       $f24, $f30, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
    // 0x800BEA5C: lw          $t9, 0x378($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X378);
    // 0x800BEA60: sll         $t4, $s7, 4
    ctx->r12 = S32(ctx->r23 << 4);
    // 0x800BEA64: addu        $v0, $t9, $t4
    ctx->r2 = ADD32(ctx->r25, ctx->r12);
    // 0x800BEA68: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800BEA6C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800BEA70: mul.s       $f2, $f20, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800BEA74: nop

    // 0x800BEA78: mul.s       $f14, $f26, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x800BEA7C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800BEA80: mul.s       $f12, $f22, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x800BEA84: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x800BEA88: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x800BEA8C: lh          $t5, -0x14($s0)
    ctx->r13 = MEM_H(ctx->r16, -0X14);
    // 0x800BEA90: lh          $t2, -0x12($s0)
    ctx->r10 = MEM_H(ctx->r16, -0X12);
    // 0x800BEA94: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800BEA98: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800BEA9C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BEAA0: lh          $t7, -0x10($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X10);
    // 0x800BEAA4: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BEAA8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BEAAC: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BEAB0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800BEAB4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BEAB8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BEABC: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800BEAC0: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800BEAC4: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x800BEAC8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
L_800BEACC:
    // 0x800BEACC: lw          $t6, 0x358($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X358);
    // 0x800BEAD0: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800BEAD4: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x800BEAD8: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x800BEADC: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x800BEAE0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800BEAE4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800BEAE8: bne         $s6, $t6, L_800BE83C
    if (ctx->r22 != ctx->r14) {
        // 0x800BEAEC: or          $s3, $t8, $zero
        ctx->r19 = ctx->r24 | 0;
            goto L_800BE83C;
    }
    // 0x800BEAEC: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x800BEAF0: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x800BEAF4: nop

L_800BEAF8:
    // 0x800BEAF8: lw          $t9, 0x354($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X354);
    // 0x800BEAFC: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x800BEB00: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800BEB04: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800BEB08: bne         $v0, $t9, L_800BE738
    if (ctx->r2 != ctx->r25) {
        // 0x800BEB0C: or          $a1, $t3, $zero
        ctx->r5 = ctx->r11 | 0;
            goto L_800BE738;
    }
    // 0x800BEB0C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_800BEB10:
    // 0x800BEB10: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800BEB14: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x800BEB18: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800BEB1C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BEB20: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BEB24: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BEB28: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BEB2C: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BEB30: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BEB34: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BEB38: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BEB3C: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800BEB40: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BEB44: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x800BEB48: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800BEB4C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800BEB50: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800BEB54: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800BEB58: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800BEB5C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800BEB60: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800BEB64: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800BEB68: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800BEB6C: jr          $ra
    // 0x800BEB70: addiu       $sp, $sp, 0x370
    ctx->r29 = ADD32(ctx->r29, 0X370);
    return;
    // 0x800BEB70: addiu       $sp, $sp, 0x370
    ctx->r29 = ADD32(ctx->r29, 0X370);
;}
RECOMP_FUNC void obj_wave_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEB74: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x800BEB78: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BEB7C: lw          $t6, 0x35D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X35D0);
    // 0x800BEB80: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800BEB84: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x800BEB88: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800BEB8C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BEB90: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BEB94: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BEB98: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800BEB9C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BEBA0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800BEBA4: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x800BEBA8: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x800BEBAC: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800BEBB0: beq         $t6, $zero, L_800BF3AC
    if (ctx->r14 == 0) {
        // 0x800BEBB4: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800BF3AC;
    }
    // 0x800BEBB4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BEBB8: bltz        $a0, L_800BF3AC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800BEBBC: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800BF3AC;
    }
    // 0x800BEBBC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BEBC0: lw          $t7, -0x5960($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5960);
    // 0x800BEBC4: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800BEBC8: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BEBCC: beq         $at, $zero, L_800BF3AC
    if (ctx->r1 == 0) {
        // 0x800BEBD0: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800BF3AC;
    }
    // 0x800BEBD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BEBD4: lw          $a0, -0x5A58($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5A58);
    // 0x800BEBD8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800BEBDC: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800BEBE0: addiu       $a0, $t8, 0xE
    ctx->r4 = ADD32(ctx->r24, 0XE);
    // 0x800BEBE4: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x800BEBE8: jal         0x80070EDC
    // 0x800BEBEC: sh          $t0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r8;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800BEBEC: sh          $t0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r8;
    after_0:
    // 0x800BEBF0: lw          $ra, 0xE8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE8);
    // 0x800BEBF4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800BEBF8: addiu       $t5, $t5, 0x3668
    ctx->r13 = ADD32(ctx->r13, 0X3668);
    // 0x800BEBFC: sll         $t1, $ra, 3
    ctx->r9 = S32(ctx->r31 << 3);
    // 0x800BEC00: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800BEC04: subu        $t1, $t1, $ra
    ctx->r9 = SUB32(ctx->r9, ctx->r31);
    // 0x800BEC08: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800BEC0C: addu        $t6, $t9, $t1
    ctx->r14 = ADD32(ctx->r25, ctx->r9);
    // 0x800BEC10: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x800BEC14: lh          $t0, 0xA6($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XA6);
    // 0x800BEC18: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BEC1C: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800BEC20: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
    // 0x800BEC24: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800BEC28: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BEC2C: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800BEC30: lw          $t9, -0x5A58($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5A58);
    // 0x800BEC34: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BEC38: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x800BEC3C: lw          $t6, 0x370C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X370C);
    // 0x800BEC40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BEC44: multu       $ra, $t6
    result = U64(U32(ctx->r31)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEC48: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800BEC4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BEC50: lwc1        $f20, -0x5984($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x800BEC54: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BEC58: lwc1        $f22, -0x5988($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800BEC5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BEC60: lwc1        $f4, -0x5A34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BEC64: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800BEC68: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BEC6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BEC70: lw          $t8, -0x5A50($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5A50);
    // 0x800BEC74: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x800BEC78: mflo        $t7
    ctx->r15 = lo;
    // 0x800BEC7C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800BEC80: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x800BEC84: beq         $t8, $zero, L_800BECB4
    if (ctx->r24 == 0) {
        // 0x800BEC88: div.s       $f2, $f6, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_800BECB4;
    }
    // 0x800BEC88: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BEC8C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BEC90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BEC94: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800BEC98: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800BEC9C: lw          $t4, -0x5A78($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5A78);
    // 0x800BECA0: nop

    // 0x800BECA4: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x800BECA8: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800BECAC: b           L_800BECC4
    // 0x800BECB0: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
        goto L_800BECC4;
    // 0x800BECB0: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
L_800BECB4:
    // 0x800BECB4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800BECB8: lw          $t4, -0x5A78($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5A78);
    // 0x800BECBC: nop

    // 0x800BECC0: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
L_800BECC4:
    // 0x800BECC4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800BECC8: lwc1        $f16, 0xEC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800BECCC: addu        $a3, $t6, $t1
    ctx->r7 = ADD32(ctx->r14, ctx->r9);
    // 0x800BECD0: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x800BECD4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800BECD8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800BECDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BECE0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BECE4: sub.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800BECE8: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x800BECEC: nop

    // 0x800BECF0: bc1f        L_800BED00
    if (!c1cs) {
        // 0x800BECF4: nop
    
            goto L_800BED00;
    }
    // 0x800BECF4: nop

    // 0x800BECF8: b           L_800BED30
    // 0x800BECFC: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
        goto L_800BED30;
    // 0x800BECFC: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
L_800BED00:
    // 0x800BED00: lwc1        $f0, -0x59A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800BED04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BED08: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x800BED0C: swc1        $f16, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f16.u32l;
    // 0x800BED10: bc1f        L_800BED30
    if (!c1cs) {
        // 0x800BED14: nop
    
            goto L_800BED30;
    }
    // 0x800BED14: nop

    // 0x800BED18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BED1C: nop

    // 0x800BED20: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800BED24: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x800BED28: lwc1        $f16, 0xEC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800BED2C: nop

L_800BED30:
    // 0x800BED30: lh          $t8, 0x8($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X8);
    // 0x800BED34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BED38: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BED3C: div.s       $f8, $f16, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f22.fl);
    // 0x800BED40: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BED44: sub.s       $f24, $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x800BED48: c.lt.s      $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f24.fl < ctx->f14.fl;
    // 0x800BED4C: nop

    // 0x800BED50: bc1f        L_800BED60
    if (!c1cs) {
        // 0x800BED54: nop
    
            goto L_800BED60;
    }
    // 0x800BED54: nop

    // 0x800BED58: b           L_800BED84
    // 0x800BED5C: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
        goto L_800BED84;
    // 0x800BED5C: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
L_800BED60:
    // 0x800BED60: lwc1        $f0, -0x599C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800BED64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BED68: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x800BED6C: nop

    // 0x800BED70: bc1f        L_800BED84
    if (!c1cs) {
        // 0x800BED74: nop
    
            goto L_800BED84;
    }
    // 0x800BED74: nop

    // 0x800BED78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BED7C: nop

    // 0x800BED80: sub.s       $f24, $f0, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f6.fl;
L_800BED84:
    // 0x800BED84: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BED88: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BED8C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BED90: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BED94: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BED98: nop

    // 0x800BED9C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BEDA0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BEDA4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800BEDA8: div.s       $f4, $f24, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800BEDAC: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800BEDB0: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x800BEDB4: sh          $ra, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r31;
    // 0x800BEDB8: sh          $a1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r5;
    // 0x800BEDBC: addiu       $ra, $sp, 0x50
    ctx->r31 = ADD32(ctx->r29, 0X50);
    // 0x800BEDC0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800BEDC4: nop

    // 0x800BEDC8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800BEDCC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BEDD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BEDD4: nop

    // 0x800BEDD8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800BEDDC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800BEDE0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800BEDE4: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800BEDE8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BEDEC: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
    // 0x800BEDF0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800BEDF4: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800BEDF8: addu        $a3, $t7, $t1
    ctx->r7 = ADD32(ctx->r15, ctx->r9);
    // 0x800BEDFC: lh          $t8, 0x12($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X12);
    // 0x800BEE00: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x800BEE04: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BEE08: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BEE0C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800BEE10: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800BEE14: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEE18: addiu       $t5, $sp, 0x80
    ctx->r13 = ADD32(ctx->r29, 0X80);
    // 0x800BEE1C: sub.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800BEE20: bne         $at, $zero, L_800BEE38
    if (ctx->r1 != 0) {
        // 0x800BEE24: sub.s       $f24, $f24, $f10
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f10.fl;
            goto L_800BEE38;
    }
    // 0x800BEE24: sub.s       $f24, $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f10.fl;
L_800BEE28:
    // 0x800BEE28: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800BEE2C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEE30: beq         $at, $zero, L_800BEE28
    if (ctx->r1 == 0) {
        // 0x800BEE34: nop
    
            goto L_800BEE28;
    }
    // 0x800BEE34: nop

L_800BEE38:
    // 0x800BEE38: lh          $t6, 0x10($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X10);
    // 0x800BEE3C: addiu       $a2, $a0, 0x1
    ctx->r6 = ADD32(ctx->r4, 0X1);
    // 0x800BEE40: addu        $v0, $t6, $t3
    ctx->r2 = ADD32(ctx->r14, ctx->r11);
    // 0x800BEE44: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEE48: bne         $at, $zero, L_800BEE60
    if (ctx->r1 != 0) {
        // 0x800BEE4C: nop
    
            goto L_800BEE60;
    }
    // 0x800BEE4C: nop

L_800BEE50:
    // 0x800BEE50: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800BEE54: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEE58: beq         $at, $zero, L_800BEE50
    if (ctx->r1 == 0) {
        // 0x800BEE5C: nop
    
            goto L_800BEE50;
    }
    // 0x800BEE5C: nop

L_800BEE60:
    // 0x800BEE60: c.eq.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl == ctx->f20.fl;
    // 0x800BEE64: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800BEE68: bc1t        L_800BEE94
    if (c1cs) {
        // 0x800BEE6C: slt         $at, $a2, $v1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BEE94;
    }
    // 0x800BEE6C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEE70: sub.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x800BEE74: nop

    // 0x800BEE78: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800BEE7C: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800BEE80: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800BEE84: nop

    // 0x800BEE88: bc1f        L_800BEE94
    if (!c1cs) {
        // 0x800BEE8C: nop
    
            goto L_800BEE94;
    }
    // 0x800BEE8C: nop

    // 0x800BEE90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800BEE94:
    // 0x800BEE94: beq         $t1, $zero, L_800BEF2C
    if (ctx->r9 == 0) {
        // 0x800BEE98: addiu       $a1, $v0, 0x1
        ctx->r5 = ADD32(ctx->r2, 0X1);
            goto L_800BEF2C;
    }
    // 0x800BEE98: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x800BEE9C: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEEA0: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x800BEEA4: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEEA8: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x800BEEAC: mflo        $a2
    ctx->r6 = lo;
    // 0x800BEEB0: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x800BEEB4: bne         $at, $zero, L_800BEEC4
    if (ctx->r1 != 0) {
        // 0x800BEEB8: sw          $a3, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r7;
            goto L_800BEEC4;
    }
    // 0x800BEEB8: sw          $a3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r7;
    // 0x800BEEBC: b           L_800BEED4
    // 0x800BEEC0: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
        goto L_800BEED4;
    // 0x800BEEC0: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
L_800BEEC4:
    // 0x800BEEC4: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEEC8: mflo        $t7
    ctx->r15 = lo;
    // 0x800BEECC: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800BEED0: sw          $t8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r24;
L_800BEED4:
    // 0x800BEED4: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEED8: bne         $at, $zero, L_800BEEE8
    if (ctx->r1 != 0) {
        // 0x800BEEDC: addiu       $v0, $a3, 0x1
        ctx->r2 = ADD32(ctx->r7, 0X1);
            goto L_800BEEE8;
    }
    // 0x800BEEDC: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x800BEEE0: b           L_800BEEEC
    // 0x800BEEE4: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
        goto L_800BEEEC;
    // 0x800BEEE4: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
L_800BEEE8:
    // 0x800BEEE8: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
L_800BEEEC:
    // 0x800BEEEC: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEEF0: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x800BEEF4: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800BEEF8: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800BEEFC: swc1        $f14, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f14.u32l;
    // 0x800BEF00: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800BEF04: mflo        $t8
    ctx->r24 = lo;
    // 0x800BEF08: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x800BEF0C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800BEF10: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEF14: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // 0x800BEF18: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x800BEF1C: mflo        $t6
    ctx->r14 = lo;
    // 0x800BEF20: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEF24: b           L_800BEFF0
    // 0x800BEF28: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
        goto L_800BEFF0;
    // 0x800BEF28: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
L_800BEF2C:
    // 0x800BEF2C: bne         $at, $zero, L_800BEF48
    if (ctx->r1 != 0) {
        // 0x800BEF30: nop
    
            goto L_800BEF48;
    }
    // 0x800BEF30: nop

    // 0x800BEF34: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEF38: mflo        $t9
    ctx->r25 = lo;
    // 0x800BEF3C: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x800BEF40: b           L_800BEF60
    // 0x800BEF44: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_800BEF60;
    // 0x800BEF44: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_800BEF48:
    // 0x800BEF48: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEF4C: mflo        $t6
    ctx->r14 = lo;
    // 0x800BEF50: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800BEF54: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BEF58: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
    // 0x800BEF5C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_800BEF60:
    // 0x800BEF60: bne         $at, $zero, L_800BEF70
    if (ctx->r1 != 0) {
        // 0x800BEF64: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_800BEF70;
    }
    // 0x800BEF64: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800BEF68: b           L_800BEF80
    // 0x800BEF6C: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
        goto L_800BEF80;
    // 0x800BEF6C: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
L_800BEF70:
    // 0x800BEF70: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEF74: mflo        $t9
    ctx->r25 = lo;
    // 0x800BEF78: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x800BEF7C: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
L_800BEF80:
    // 0x800BEF80: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEF84: bne         $at, $zero, L_800BEF94
    if (ctx->r1 != 0) {
        // 0x800BEF88: nop
    
            goto L_800BEF94;
    }
    // 0x800BEF88: nop

    // 0x800BEF8C: b           L_800BEF94
    // 0x800BEF90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BEF94;
    // 0x800BEF90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BEF94:
    // 0x800BEF94: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEF98: beq         $at, $zero, L_800BEFB0
    if (ctx->r1 == 0) {
        // 0x800BEF9C: sw          $v0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r2;
            goto L_800BEFB0;
    }
    // 0x800BEF9C: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x800BEFA0: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEFA4: mflo        $t7
    ctx->r15 = lo;
    // 0x800BEFA8: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800BEFAC: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
L_800BEFB0:
    // 0x800BEFB0: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEFB4: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800BEFB8: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x800BEFBC: swc1        $f22, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f22.u32l;
    // 0x800BEFC0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800BEFC4: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x800BEFC8: mflo        $t6
    ctx->r14 = lo;
    // 0x800BEFCC: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEFD0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BEFD4: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEFD8: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x800BEFDC: mflo        $t6
    ctx->r14 = lo;
    // 0x800BEFE0: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEFE4: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800BEFE8: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x800BEFEC: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
L_800BEFF0:
    // 0x800BEFF0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BEFF4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BEFF8: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    // 0x800BEFFC: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BF000: lw          $t3, 0x35D4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X35D4);
    // 0x800BF004: addiu       $t1, $sp, 0x68
    ctx->r9 = ADD32(ctx->r29, 0X68);
    // 0x800BF008: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BF00C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_800BF010:
    // 0x800BF010: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800BF014: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800BF018: sll         $t9, $a3, 3
    ctx->r25 = S32(ctx->r7 << 3);
    // 0x800BF01C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BF020: addu        $a0, $t3, $t8
    ctx->r4 = ADD32(ctx->r11, ctx->r24);
    // 0x800BF024: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x800BF028: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x800BF02C: addu        $a1, $ra, $v0
    ctx->r5 = ADD32(ctx->r31, ctx->r2);
    // 0x800BF030: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BF034: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800BF038: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    // 0x800BF03C: addu        $t7, $sp, $v0
    ctx->r15 = ADD32(ctx->r29, ctx->r2);
    // 0x800BF040: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800BF044: lw          $t7, 0x5C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5C);
    // 0x800BF048: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BF04C: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x800BF050: lbu         $a2, 0x0($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X0);
    // 0x800BF054: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x800BF058: slti        $at, $a2, 0x7F
    ctx->r1 = SIGNED(ctx->r6) < 0X7F ? 1 : 0;
    // 0x800BF05C: beq         $at, $zero, L_800BF088
    if (ctx->r1 == 0) {
        // 0x800BF060: sra         $a3, $t9, 16
        ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
            goto L_800BF088;
    }
    // 0x800BF060: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800BF064: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800BF068: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BF06C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BF070: lwc1        $f10, -0x5A34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BF074: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BF078: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BF07C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800BF080: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800BF084: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_800BF088:
    // 0x800BF088: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800BF08C: bne         $at, $zero, L_800BF010
    if (ctx->r1 != 0) {
        // 0x800BF090: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_800BF010;
    }
    // 0x800BF090: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800BF094: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BF098: lw          $t7, -0x5A50($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5A50);
    // 0x800BF09C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800BF0A0: beq         $t7, $zero, L_800BF0F0
    if (ctx->r15 == 0) {
        // 0x800BF0A4: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800BF0F0;
    }
    // 0x800BF0A4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BF0A8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800BF0AC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800BF0B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BF0B4: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800BF0B8: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x800BF0BC: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800BF0C0: nop

    // 0x800BF0C4: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800BF0C8: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800BF0CC: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800BF0D0: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x800BF0D4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800BF0D8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800BF0DC: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800BF0E0: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x800BF0E4: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800BF0E8: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800BF0EC: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
L_800BF0F0:
    // 0x800BF0F0: lw          $t8, -0x5A58($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5A58);
    // 0x800BF0F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BF0F8: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800BF0FC: blez        $t9, L_800BF3B0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BF100: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800BF3B0;
    }
    // 0x800BF100: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF104: mul.s       $f18, $f20, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800BF108: swc1        $f16, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f16.u32l;
    // 0x800BF10C: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800BF110: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800BF114: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
L_800BF118:
    // 0x800BF118: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800BF11C: lw          $v0, 0x35D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X35D0);
    // 0x800BF120: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800BF124: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BF128: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800BF12C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BF130: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BF134: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BF138: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BF13C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800BF140: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800BF144: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BF148: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BF14C: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x800BF150: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800BF154: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BF158: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BF15C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800BF160: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BF164: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BF168: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800BF16C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800BF170: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BF174: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800BF178: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BF17C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800BF180: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BF184: mul.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BF188: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BF18C: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BF190: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BF194: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800BF198: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BF19C: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x800BF1A0: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BF1A4: beq         $t8, $zero, L_800BF1C4
    if (ctx->r24 == 0) {
        // 0x800BF1A8: nop
    
            goto L_800BF1C4;
    }
    // 0x800BF1A8: nop

    // 0x800BF1AC: sub.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800BF1B0: mul.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BF1B4: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800BF1B8: mul.s       $f14, $f4, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800BF1BC: b           L_800BF1D8
    // 0x800BF1C0: nop

        goto L_800BF1D8;
    // 0x800BF1C0: nop

L_800BF1C4:
    // 0x800BF1C4: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800BF1C8: mul.s       $f2, $f8, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800BF1CC: sub.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800BF1D0: mul.s       $f14, $f10, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800BF1D4: nop

L_800BF1D8:
    // 0x800BF1D8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800BF1DC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800BF1E0: sh          $a3, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r7;
    // 0x800BF1E4: sh          $t0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r8;
    // 0x800BF1E8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800BF1EC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BF1F0: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x800BF1F4: swc1        $f2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f2.u32l;
    // 0x800BF1F8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BF1FC: swc1        $f14, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f14.u32l;
    // 0x800BF200: swc1        $f16, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f16.u32l;
    // 0x800BF204: jal         0x800CA030
    // 0x800BF208: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800BF208: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x800BF20C: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BF210: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BF214: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800BF218: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800BF21C: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800BF220: lwc1        $f16, 0xE0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800BF224: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800BF228: lh          $t0, 0xA6($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XA6);
    // 0x800BF22C: lh          $a3, 0xA2($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XA2);
    // 0x800BF230: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800BF234: addiu       $t1, $sp, 0x68
    ctx->r9 = ADD32(ctx->r29, 0X68);
    // 0x800BF238: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BF23C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BF240: negu        $t6, $t0
    ctx->r14 = SUB32(0, ctx->r8);
    // 0x800BF244: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800BF248: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800BF24C: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800BF250: div.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BF254: mul.s       $f8, $f14, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x800BF258: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BF25C: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BF260: nop

    // 0x800BF264: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800BF268: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BF26C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BF270: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800BF274: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800BF278: nop

    // 0x800BF27C: div.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800BF280: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BF284: nop

    // 0x800BF288: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BF28C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF290: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF294: nop

    // 0x800BF298: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BF29C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800BF2A0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BF2A4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800BF2A8: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BF2AC: beq         $at, $zero, L_800BF2C0
    if (ctx->r1 == 0) {
        // 0x800BF2B0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800BF2C0;
    }
    // 0x800BF2B0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800BF2B4: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BF2B8: beq         $at, $zero, L_800BF330
    if (ctx->r1 == 0) {
        // 0x800BF2BC: nop
    
            goto L_800BF330;
    }
    // 0x800BF2BC: nop

L_800BF2C0:
    // 0x800BF2C0: addu        $t0, $t0, $t0
    ctx->r8 = ADD32(ctx->r8, ctx->r8);
    // 0x800BF2C4: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800BF2C8: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800BF2CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BF2D0: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x800BF2D4: slt         $at, $a2, $t8
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BF2D8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800BF2DC: beq         $at, $zero, L_800BF2C0
    if (ctx->r1 == 0) {
        // 0x800BF2E0: sra         $v1, $t9, 16
        ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
            goto L_800BF2C0;
    }
    // 0x800BF2E0: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800BF2E4: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x800BF2E8: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BF2EC: bne         $at, $zero, L_800BF2C0
    if (ctx->r1 != 0) {
        // 0x800BF2F0: nop
    
            goto L_800BF2C0;
    }
    // 0x800BF2F0: nop

    // 0x800BF2F4: blez        $a3, L_800BF320
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800BF2F8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800BF320;
    }
    // 0x800BF2F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800BF2FC:
    // 0x800BF2FC: addu        $v0, $t2, $a1
    ctx->r2 = ADD32(ctx->r10, ctx->r5);
    // 0x800BF300: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BF304: lb          $t8, 0xE($v0)
    ctx->r24 = MEM_B(ctx->r2, 0XE);
    // 0x800BF308: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800BF30C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800BF310: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800BF314: srav        $t9, $t8, $v1
    ctx->r25 = S32(SIGNED(ctx->r24) >> (ctx->r3 & 31));
    // 0x800BF318: bne         $at, $zero, L_800BF2FC
    if (ctx->r1 != 0) {
        // 0x800BF31C: sb          $t9, 0xE($v0)
        MEM_B(0XE, ctx->r2) = ctx->r25;
            goto L_800BF2FC;
    }
    // 0x800BF31C: sb          $t9, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r25;
L_800BF320:
    // 0x800BF320: lbu         $t8, 0x2($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X2);
    // 0x800BF324: nop

    // 0x800BF328: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800BF32C: sb          $t9, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r25;
L_800BF330:
    // 0x800BF330: lbu         $t6, 0x2($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X2);
    // 0x800BF334: addu        $t8, $t2, $a3
    ctx->r24 = ADD32(ctx->r10, ctx->r7);
    // 0x800BF338: srav        $t7, $a2, $t6
    ctx->r15 = S32(SIGNED(ctx->r6) >> (ctx->r14 & 31));
    // 0x800BF33C: sb          $t7, 0xE($t8)
    MEM_B(0XE, ctx->r24) = ctx->r15;
    // 0x800BF340: lw          $a0, -0x5A58($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5A58);
    // 0x800BF344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BF348: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
L_800BF34C:
    // 0x800BF34C: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x800BF350: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800BF354: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BF358: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x800BF35C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BF360: bne         $at, $zero, L_800BF37C
    if (ctx->r1 != 0) {
        // 0x800BF364: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800BF37C;
    }
    // 0x800BF364: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800BF368:
    // 0x800BF368: subu        $t8, $v0, $a0
    ctx->r24 = SUB32(ctx->r2, ctx->r4);
    // 0x800BF36C: slt         $at, $t8, $a0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BF370: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800BF374: beq         $at, $zero, L_800BF368
    if (ctx->r1 == 0) {
        // 0x800BF378: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800BF368;
    }
    // 0x800BF378: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800BF37C:
    // 0x800BF37C: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x800BF380: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800BF384: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x800BF388: bne         $at, $zero, L_800BF34C
    if (ctx->r1 != 0) {
        // 0x800BF38C: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_800BF34C;
    }
    // 0x800BF38C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800BF390: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BF394: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x800BF398: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800BF39C: sra         $t9, $a0, 1
    ctx->r25 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800BF3A0: slt         $at, $a3, $t9
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BF3A4: bne         $at, $zero, L_800BF118
    if (ctx->r1 != 0) {
        // 0x800BF3A8: lw          $t6, 0x68($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X68);
            goto L_800BF118;
    }
    // 0x800BF3A8: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
L_800BF3AC:
    // 0x800BF3AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800BF3B0:
    // 0x800BF3B0: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800BF3B4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800BF3B8: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BF3BC: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BF3C0: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BF3C4: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BF3C8: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x800BF3CC: jr          $ra
    // 0x800BF3D0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x800BF3D0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
;}
RECOMP_FUNC void obj_wave_height(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF3D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BF3D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF3DC: lhu         $t6, 0x4($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X4);
    // 0x800BF3E0: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x800BF3E4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800BF3E8: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x800BF3EC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BF3F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800BF3F4: bne         $at, $zero, L_800BF410
    if (ctx->r1 != 0) {
        // 0x800BF3F8: sh          $t7, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r15;
            goto L_800BF410;
    }
    // 0x800BF3F8: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
L_800BF3FC:
    // 0x800BF3FC: subu        $t8, $v0, $v1
    ctx->r24 = SUB32(ctx->r2, ctx->r3);
    // 0x800BF400: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x800BF404: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BF408: beq         $at, $zero, L_800BF3FC
    if (ctx->r1 == 0) {
        // 0x800BF40C: sh          $t8, 0x4($a3)
        MEM_H(0X4, ctx->r7) = ctx->r24;
            goto L_800BF3FC;
    }
    // 0x800BF40C: sh          $t8, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r24;
L_800BF410:
    // 0x800BF410: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800BF414: addu        $a0, $a3, $t9
    ctx->r4 = ADD32(ctx->r7, ctx->r25);
    // 0x800BF418: lb          $t0, 0xE($a0)
    ctx->r8 = MEM_B(ctx->r4, 0XE);
    // 0x800BF41C: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800BF420: beq         $t1, $zero, L_800BF46C
    if (ctx->r9 == 0) {
        // 0x800BF424: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_800BF46C;
    }
    // 0x800BF424: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x800BF428: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BF42C: bne         $at, $zero, L_800BF440
    if (ctx->r1 != 0) {
        // 0x800BF430: nop
    
            goto L_800BF440;
    }
    // 0x800BF430: nop

    // 0x800BF434: lb          $t3, 0xE($a3)
    ctx->r11 = MEM_B(ctx->r7, 0XE);
    // 0x800BF438: b           L_800BF44C
    // 0x800BF43C: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
        goto L_800BF44C;
    // 0x800BF43C: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
L_800BF440:
    // 0x800BF440: lb          $t4, 0xF($a0)
    ctx->r12 = MEM_B(ctx->r4, 0XF);
    // 0x800BF444: nop

    // 0x800BF448: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
L_800BF44C:
    // 0x800BF44C: lbu         $v0, 0x2($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2);
    // 0x800BF450: sra         $t6, $t0, 1
    ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800BF454: blez        $v0, L_800BF464
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BF458: addiu       $t5, $v0, 0x1F
        ctx->r13 = ADD32(ctx->r2, 0X1F);
            goto L_800BF464;
    }
    // 0x800BF458: addiu       $t5, $v0, 0x1F
    ctx->r13 = ADD32(ctx->r2, 0X1F);
    // 0x800BF45C: b           L_800BF478
    // 0x800BF460: sllv        $t0, $t0, $t5
    ctx->r8 = S32(ctx->r8 << (ctx->r13 & 31));
        goto L_800BF478;
    // 0x800BF460: sllv        $t0, $t0, $t5
    ctx->r8 = S32(ctx->r8 << (ctx->r13 & 31));
L_800BF464:
    // 0x800BF464: b           L_800BF478
    // 0x800BF468: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
        goto L_800BF478;
    // 0x800BF468: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
L_800BF46C:
    // 0x800BF46C: lbu         $t7, 0x2($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X2);
    // 0x800BF470: nop

    // 0x800BF474: sllv        $t0, $t0, $t7
    ctx->r8 = S32(ctx->r8 << (ctx->r15 & 31));
L_800BF478:
    // 0x800BF478: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800BF47C: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800BF480: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BF484: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x800BF488: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800BF48C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BF490: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800BF494: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800BF498: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800BF49C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BF4A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BF4A4: lwc1        $f10, -0x5A38($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800BF4A8: lhu         $a0, 0xC($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0XC);
    // 0x800BF4AC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800BF4B0: add.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d + ctx->f6.d;
    // 0x800BF4B4: lhu         $a1, 0x8($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X8);
    // 0x800BF4B8: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800BF4BC: lhu         $a2, 0xA($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0XA);
    // 0x800BF4C0: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800BF4C4: jal         0x800BF4E4
    // 0x800BF4C8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800BF4C8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x800BF4CC: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800BF4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF4D4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800BF4D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BF4DC: jr          $ra
    // 0x800BF4E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800BF4E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void waves_get_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF4E4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BF4E8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BF4EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800BF4F0: lw          $t6, 0x3718($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3718);
    // 0x800BF4F4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x800BF4F8: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x800BF4FC: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800BF500: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x800BF504: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800BF508: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800BF50C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800BF510: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x800BF514: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x800BF518: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x800BF51C: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x800BF520: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800BF524: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x800BF528: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800BF52C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x800BF530: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BF534: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800BF538: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BF53C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800BF540: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BF544: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800BF548: bgtz        $t6, L_800BF558
    if (SIGNED(ctx->r14) > 0) {
        // 0x800BF54C: mov.s       $f28, $f2
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
            goto L_800BF558;
    }
    // 0x800BF54C: mov.s       $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
    // 0x800BF550: b           L_800BF8B0
    // 0x800BF554: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800BF8B0;
    // 0x800BF554: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800BF558:
    // 0x800BF558: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BF55C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BF560: addiu       $v0, $v0, -0x5A78
    ctx->r2 = ADD32(ctx->r2, -0X5A78);
    // 0x800BF564: lwc1        $f0, -0x5988($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800BF568: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x800BF56C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BF570: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800BF574: lwc1        $f2, -0x5984($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x800BF578: beq         $t7, $zero, L_800BF59C
    if (ctx->r15 == 0) {
        // 0x800BF57C: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800BF59C;
    }
    // 0x800BF57C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BF580: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BF584: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800BF588: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x800BF58C: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800BF590: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800BF594: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800BF598: nop

L_800BF59C:
    // 0x800BF59C: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x800BF5A0: lw          $t9, 0x3668($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3668);
    // 0x800BF5A4: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x800BF5A8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BF5AC: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x800BF5B0: lbu         $t1, 0xA($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0XA);
    // 0x800BF5B4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BF5B8: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BF5BC: lw          $t4, 0x3714($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3714);
    // 0x800BF5C0: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // 0x800BF5C4: mflo        $t2
    ctx->r10 = lo;
    // 0x800BF5C8: addu        $a1, $t2, $s0
    ctx->r5 = ADD32(ctx->r10, ctx->r16);
    // 0x800BF5CC: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x800BF5D0: addu        $a3, $t3, $t4
    ctx->r7 = ADD32(ctx->r11, ctx->r12);
    // 0x800BF5D4: lbu         $t5, 0x0($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X0);
    // 0x800BF5D8: nop

    // 0x800BF5DC: beq         $s5, $t5, L_800BF8AC
    if (ctx->r21 == ctx->r13) {
        // 0x800BF5E0: nop
    
            goto L_800BF8AC;
    }
    // 0x800BF5E0: nop

    // 0x800BF5E4: lbu         $t6, 0xB($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XB);
    // 0x800BF5E8: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800BF5EC: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BF5F0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BF5F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BF5F8: lw          $t8, -0x5970($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5970);
    // 0x800BF5FC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BF600: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800BF604: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BF608: lw          $t9, -0x596C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X596C);
    // 0x800BF60C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800BF610: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800BF614: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BF618: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800BF61C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BF620: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x800BF624: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800BF628: add.s       $f30, $f6, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800BF62C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800BF630: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BF634: addiu       $s4, $s4, 0x3720
    ctx->r20 = ADD32(ctx->r20, 0X3720);
    // 0x800BF638: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800BF63C: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800BF640: andi        $v0, $t5, 0xFF
    ctx->r2 = ctx->r13 & 0XFF;
    // 0x800BF644: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BF648: add.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f6.fl;
L_800BF64C:
    // 0x800BF64C: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x800BF650: sll         $t0, $v0, 6
    ctx->r8 = S32(ctx->r2 << 6);
    // 0x800BF654: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    // 0x800BF658: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BF65C: nop

    // 0x800BF660: c.le.s      $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f16.fl <= ctx->f24.fl;
    // 0x800BF664: nop

    // 0x800BF668: bc1f        L_800BF88C
    if (!c1cs) {
        // 0x800BF66C: nop
    
            goto L_800BF88C;
    }
    // 0x800BF66C: nop

    // 0x800BF670: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800BF674: nop

    // 0x800BF678: c.le.s      $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f24.fl <= ctx->f18.fl;
    // 0x800BF67C: nop

    // 0x800BF680: bc1f        L_800BF88C
    if (!c1cs) {
        // 0x800BF684: nop
    
            goto L_800BF88C;
    }
    // 0x800BF684: nop

    // 0x800BF688: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800BF68C: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800BF690: sub.s       $f20, $f30, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f30.fl - ctx->f8.fl;
    // 0x800BF694: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800BF698: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800BF69C: sub.s       $f22, $f24, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x800BF6A0: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800BF6A4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BF6A8: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x800BF6AC: nop

    // 0x800BF6B0: bc1f        L_800BF88C
    if (!c1cs) {
        // 0x800BF6B4: nop
    
            goto L_800BF88C;
    }
    // 0x800BF6B4: nop

    // 0x800BF6B8: jal         0x800CA030
    // 0x800BF6BC: nop

    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800BF6BC: nop

    after_0:
    // 0x800BF6C0: lbu         $t2, 0x30($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X30);
    // 0x800BF6C4: lhu         $s0, 0x1A($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0X1A);
    // 0x800BF6C8: beq         $t2, $zero, L_800BF750
    if (ctx->r10 == 0) {
        // 0x800BF6CC: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800BF750;
    }
    // 0x800BF6CC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800BF6D0: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800BF6D4: nop

    // 0x800BF6D8: bc1f        L_800BF718
    if (!c1cs) {
        // 0x800BF6DC: nop
    
            goto L_800BF718;
    }
    // 0x800BF6DC: nop

    // 0x800BF6E0: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF6E4: nop

    // 0x800BF6E8: mul.s       $f8, $f20, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800BF6EC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800BF6F0: nop

    // 0x800BF6F4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800BF6F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF6FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF700: nop

    // 0x800BF704: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BF708: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800BF70C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800BF710: b           L_800BF818
    // 0x800BF714: subu        $s0, $s0, $t4
    ctx->r16 = SUB32(ctx->r16, ctx->r12);
        goto L_800BF818;
    // 0x800BF714: subu        $s0, $s0, $t4
    ctx->r16 = SUB32(ctx->r16, ctx->r12);
L_800BF718:
    // 0x800BF718: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF71C: nop

    // 0x800BF720: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800BF724: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800BF728: nop

    // 0x800BF72C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800BF730: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF734: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF738: nop

    // 0x800BF73C: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BF740: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800BF744: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800BF748: b           L_800BF818
    // 0x800BF74C: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
        goto L_800BF818;
    // 0x800BF74C: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_800BF750:
    // 0x800BF750: lbu         $t7, 0x31($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X31);
    // 0x800BF754: nop

    // 0x800BF758: beq         $t7, $zero, L_800BF7E0
    if (ctx->r15 == 0) {
        // 0x800BF75C: nop
    
            goto L_800BF7E0;
    }
    // 0x800BF75C: nop

    // 0x800BF760: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800BF764: nop

    // 0x800BF768: bc1f        L_800BF7A8
    if (!c1cs) {
        // 0x800BF76C: nop
    
            goto L_800BF7A8;
    }
    // 0x800BF76C: nop

    // 0x800BF770: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF774: nop

    // 0x800BF778: mul.s       $f8, $f22, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x800BF77C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BF780: nop

    // 0x800BF784: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BF788: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF78C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF790: nop

    // 0x800BF794: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BF798: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800BF79C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BF7A0: b           L_800BF818
    // 0x800BF7A4: subu        $s0, $s0, $t9
    ctx->r16 = SUB32(ctx->r16, ctx->r25);
        goto L_800BF818;
    // 0x800BF7A4: subu        $s0, $s0, $t9
    ctx->r16 = SUB32(ctx->r16, ctx->r25);
L_800BF7A8:
    // 0x800BF7A8: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF7AC: nop

    // 0x800BF7B0: mul.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x800BF7B4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800BF7B8: nop

    // 0x800BF7BC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800BF7C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF7C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF7C8: nop

    // 0x800BF7CC: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BF7D0: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x800BF7D4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800BF7D8: b           L_800BF818
    // 0x800BF7DC: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
        goto L_800BF818;
    // 0x800BF7DC: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
L_800BF7E0:
    // 0x800BF7E0: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF7E4: nop

    // 0x800BF7E8: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800BF7EC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800BF7F0: nop

    // 0x800BF7F4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800BF7F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF7FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF800: nop

    // 0x800BF804: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BF808: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800BF80C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800BF810: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x800BF814: nop

L_800BF818:
    // 0x800BF818: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800BF81C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BF820: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800BF824: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800BF828: nop

    // 0x800BF82C: div.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BF830: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BF834: nop

    // 0x800BF838: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BF83C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF840: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF844: nop

    // 0x800BF848: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800BF84C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800BF850: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BF854: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800BF858: jal         0x80070A38
    // 0x800BF85C: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800BF85C: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_1:
    // 0x800BF860: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800BF864: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800BF868: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800BF86C: jal         0x80070A04
    // 0x800BF870: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x800BF870: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x800BF874: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800BF878: nop

    // 0x800BF87C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BF880: nop

    // 0x800BF884: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800BF888: add.s       $f28, $f28, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f6.fl;
L_800BF88C:
    // 0x800BF88C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800BF890: slti        $at, $s3, 0x8
    ctx->r1 = SIGNED(ctx->r19) < 0X8 ? 1 : 0;
    // 0x800BF894: beq         $at, $zero, L_800BF8AC
    if (ctx->r1 == 0) {
        // 0x800BF898: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800BF8AC;
    }
    // 0x800BF898: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BF89C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800BF8A0: nop

    // 0x800BF8A4: bne         $s5, $v0, L_800BF64C
    if (ctx->r21 != ctx->r2) {
        // 0x800BF8A8: nop
    
            goto L_800BF64C;
    }
    // 0x800BF8A8: nop

L_800BF8AC:
    // 0x800BF8AC: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_800BF8B0:
    // 0x800BF8B0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800BF8B4: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800BF8B8: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800BF8BC: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BF8C0: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BF8C4: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BF8C8: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BF8CC: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BF8D0: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BF8D4: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BF8D8: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BF8DC: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800BF8E0: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BF8E4: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x800BF8E8: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x800BF8EC: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x800BF8F0: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x800BF8F4: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x800BF8F8: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x800BF8FC: jr          $ra
    // 0x800BF900: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BF900: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void wavegen_destroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF904: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BF908: lw          $t6, 0x3720($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3720);
    // 0x800BF90C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BF910: beq         $t6, $zero, L_800BFA3C
    if (ctx->r14 == 0) {
        // 0x800BF914: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800BFA3C;
    }
    // 0x800BF914: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800BF918: addiu       $t0, $t0, 0x3718
    ctx->r8 = ADD32(ctx->r8, 0X3718);
    // 0x800BF91C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800BF920: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF924: blez        $a0, L_800BF960
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BF928: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BF960;
    }
    // 0x800BF928: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BF92C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BF930: lw          $t7, 0x3724($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3724);
    // 0x800BF934: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x800BF938: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
L_800BF93C:
    // 0x800BF93C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BF940: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BF944: bne         $a1, $t9, L_800BF950
    if (ctx->r5 != ctx->r25) {
        // 0x800BF948: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800BF950;
    }
    // 0x800BF948: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BF94C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800BF950:
    // 0x800BF950: beq         $at, $zero, L_800BF960
    if (ctx->r1 == 0) {
        // 0x800BF954: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800BF960;
    }
    // 0x800BF954: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800BF958: beq         $v1, $zero, L_800BF93C
    if (ctx->r3 == 0) {
        // 0x800BF95C: nop
    
            goto L_800BF93C;
    }
    // 0x800BF95C: nop

L_800BF960:
    // 0x800BF960: beq         $v1, $zero, L_800BFA3C
    if (ctx->r3 == 0) {
        // 0x800BF964: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_800BFA3C;
    }
    // 0x800BF964: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BF968: addiu       $t1, $t1, 0x371C
    ctx->r9 = ADD32(ctx->r9, 0X371C);
    // 0x800BF96C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800BF970: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800BF974: blez        $t5, L_800BFA18
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800BF978: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BFA18;
    }
    // 0x800BF978: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BF97C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BF980: addiu       $t2, $t2, 0x3714
    ctx->r10 = ADD32(ctx->r10, 0X3714);
    // 0x800BF984: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800BF988: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800BF98C:
    // 0x800BF98C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800BF990: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800BF994: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800BF998: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800BF99C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800BF9A0: beq         $t3, $t8, L_800BFA04
    if (ctx->r11 == ctx->r24) {
        // 0x800BF9A4: nop
    
            goto L_800BFA04;
    }
    // 0x800BF9A4: nop

    // 0x800BF9A8: lbu         $a3, 0x0($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X0);
    // 0x800BF9AC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_800BF9B0:
    // 0x800BF9B0: bne         $v0, $a3, L_800BF9E4
    if (ctx->r2 != ctx->r7) {
        // 0x800BF9B4: slti        $at, $a0, 0x7
        ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
            goto L_800BF9E4;
    }
    // 0x800BF9B4: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x800BF9B8: beq         $at, $zero, L_800BF9D8
    if (ctx->r1 == 0) {
        // 0x800BF9BC: nop
    
            goto L_800BF9D8;
    }
    // 0x800BF9BC: nop

L_800BF9C0:
    // 0x800BF9C0: lbu         $t9, 0x1($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1);
    // 0x800BF9C4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BF9C8: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x800BF9CC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BF9D0: bne         $at, $zero, L_800BF9C0
    if (ctx->r1 != 0) {
        // 0x800BF9D4: sb          $t9, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r25;
            goto L_800BF9C0;
    }
    // 0x800BF9D4: sb          $t9, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r25;
L_800BF9D8:
    // 0x800BF9D8: sb          $t4, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r12;
    // 0x800BF9DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BF9E0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800BF9E4:
    // 0x800BF9E4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BF9E8: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800BF9EC: beq         $at, $zero, L_800BFA04
    if (ctx->r1 == 0) {
        // 0x800BF9F0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800BFA04;
    }
    // 0x800BF9F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BF9F4: lbu         $a3, 0x0($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X0);
    // 0x800BF9F8: nop

    // 0x800BF9FC: bne         $t3, $a3, L_800BF9B0
    if (ctx->r11 != ctx->r7) {
        // 0x800BFA00: nop
    
            goto L_800BF9B0;
    }
    // 0x800BFA00: nop

L_800BFA04:
    // 0x800BFA04: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800BFA08: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BFA0C: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800BFA10: bne         $at, $zero, L_800BF98C
    if (ctx->r1 != 0) {
        // 0x800BFA14: nop
    
            goto L_800BF98C;
    }
    // 0x800BFA14: nop

L_800BFA18:
    // 0x800BFA18: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BFA1C: lw          $t6, 0x3724($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3724);
    // 0x800BFA20: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800BFA24: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800BFA28: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800BFA2C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BFA30: nop

    // 0x800BFA34: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x800BFA38: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_800BFA3C:
    // 0x800BFA3C: jr          $ra
    // 0x800BFA40: nop

    return;
    // 0x800BFA40: nop

;}
RECOMP_FUNC void wavegen_add(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFA44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BFA48: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BFA4C: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x800BFA50: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x800BFA54: lbu         $t6, 0x10($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10);
    // 0x800BFA58: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800BFA5C: beq         $t6, $zero, L_800BFA68
    if (ctx->r14 == 0) {
        // 0x800BFA60: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BFA68;
    }
    // 0x800BFA60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BFA64: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BFA68:
    // 0x800BFA68: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x800BFA6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BFA70: beq         $t7, $zero, L_800BFA7C
    if (ctx->r15 == 0) {
        // 0x800BFA74: ori         $t8, $v1, 0x2
        ctx->r24 = ctx->r3 | 0X2;
            goto L_800BFA7C;
    }
    // 0x800BFA74: ori         $t8, $v1, 0x2
    ctx->r24 = ctx->r3 | 0X2;
    // 0x800BFA78: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800BFA7C:
    // 0x800BFA7C: lhu         $t9, 0xA($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XA);
    // 0x800BFA80: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
    // 0x800BFA84: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800BFA88: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x800BFA8C: bgez        $t9, L_800BFAA4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800BFA90: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800BFAA4;
    }
    // 0x800BFA90: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BFA94: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BFA98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BFA9C: nop

    // 0x800BFAA0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800BFAA4:
    // 0x800BFAA4: lbu         $t0, 0x9($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X9);
    // 0x800BFAA8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800BFAAC: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x800BFAB0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800BFAB4: lbu         $t2, 0x8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X8);
    // 0x800BFAB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BFABC: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800BFAC0: bgez        $t2, L_800BFAD4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BFAC4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800BFAD4;
    }
    // 0x800BFAC4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BFAC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BFACC: nop

    // 0x800BFAD0: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800BFAD4:
    // 0x800BFAD4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800BFAD8: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x800BFADC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BFAE0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800BFAE4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800BFAE8: lhu         $t3, 0xE($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XE);
    // 0x800BFAEC: nop

    // 0x800BFAF0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800BFAF4: bgez        $t3, L_800BFB08
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800BFAF8: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800BFB08;
    }
    // 0x800BFAF8: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BFAFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BFB00: nop

    // 0x800BFB04: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_800BFB08:
    // 0x800BFB08: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x800BFB0C: lhu         $t4, 0xC($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0XC);
    // 0x800BFB10: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BFB14: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800BFB18: bgez        $t4, L_800BFB2C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800BFB1C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BFB2C;
    }
    // 0x800BFB1C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BFB20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BFB24: nop

    // 0x800BFB28: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800BFB2C:
    // 0x800BFB2C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800BFB30: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800BFB34: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x800BFB38: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800BFB3C: jal         0x800BFB54
    // 0x800BFB40: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_800BF634(rdram, ctx);
        goto after_0;
    // 0x800BFB40: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800BFB44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BFB48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BFB4C: jr          $ra
    // 0x800BFB50: nop

    return;
    // 0x800BFB50: nop

;}
RECOMP_FUNC void func_800BF634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFB54: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BFB58: addiu       $v1, $v1, 0x3720
    ctx->r3 = ADD32(ctx->r3, 0X3720);
    // 0x800BFB5C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800BFB60: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BFB64: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800BFB68: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800BFB6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BFB70: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800BFB74: beq         $t6, $zero, L_800BFF0C
    if (ctx->r14 == 0) {
        // 0x800BFB78: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800BFF0C;
    }
    // 0x800BFB78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BFB7C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BFB80: lw          $t7, 0x3724($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3724);
    // 0x800BFB84: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x800BFB88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BFB8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800BFB90: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
L_800BFB94:
    // 0x800BFB94: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BFB98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BFB9C: bne         $t9, $zero, L_800BFBA8
    if (ctx->r25 != 0) {
        // 0x800BFBA0: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_800BFBA8;
    }
    // 0x800BFBA0: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800BFBA4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_800BFBA8:
    // 0x800BFBA8: beq         $at, $zero, L_800BFBB8
    if (ctx->r1 == 0) {
        // 0x800BFBAC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800BFBB8;
    }
    // 0x800BFBAC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800BFBB0: beq         $a0, $zero, L_800BFB94
    if (ctx->r4 == 0) {
        // 0x800BFBB4: nop
    
            goto L_800BFB94;
    }
    // 0x800BFBB4: nop

L_800BFBB8:
    // 0x800BFBB8: beq         $a0, $zero, L_800BFF0C
    if (ctx->r4 == 0) {
        // 0x800BFBBC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800BFF0C;
    }
    // 0x800BFBBC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800BFBC0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BFBC4: lw          $t3, 0x3724($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3724);
    // 0x800BFBC8: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800BFBCC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800BFBD0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800BFBD4: addiu       $a0, $a0, 0x3718
    ctx->r4 = ADD32(ctx->r4, 0X3718);
    // 0x800BFBD8: sw          $a3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r7;
    // 0x800BFBDC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800BFBE0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BFBE4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BFBE8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800BFBEC: lw          $t8, -0x5A50($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5A50);
    // 0x800BFBF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BFBF4: lwc1        $f0, -0x5988($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800BFBF8: beq         $t8, $zero, L_800BFC14
    if (ctx->r24 == 0) {
        // 0x800BFBFC: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_800BFC14;
    }
    // 0x800BFBFC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BFC00: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BFC04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BFC08: nop

    // 0x800BFC0C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800BFC10: nop

L_800BFC14:
    // 0x800BFC14: lw          $t9, -0x5970($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5970);
    // 0x800BFC18: sub.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800BFC1C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BFC20: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BFC24: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BFC28: lw          $a1, 0x371C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X371C);
    // 0x800BFC2C: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800BFC30: nop

    // 0x800BFC34: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BFC38: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800BFC3C: nop

    // 0x800BFC40: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800BFC44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BFC48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BFC4C: nop

    // 0x800BFC50: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800BFC54: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800BFC58: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800BFC5C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800BFC60: bne         $at, $zero, L_800BFC70
    if (ctx->r1 != 0) {
        // 0x800BFC64: nop
    
            goto L_800BFC70;
    }
    // 0x800BFC64: nop

    // 0x800BFC68: jr          $ra
    // 0x800BFC6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800BFC6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BFC70:
    // 0x800BFC70: add.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800BFC74: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800BFC78: nop

    // 0x800BFC7C: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800BFC80: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BFC84: nop

    // 0x800BFC88: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BFC8C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BFC90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BFC94: nop

    // 0x800BFC98: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BFC9C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800BFCA0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BFCA4: bgez        $a2, L_800BFCB4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800BFCA8: slt         $at, $a2, $a1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800BFCB4;
    }
    // 0x800BFCA8: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800BFCAC: jr          $ra
    // 0x800BFCB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800BFCB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BFCB4:
    // 0x800BFCB4: bgez        $a0, L_800BFCC0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800BFCB8: sll         $t4, $v0, 6
        ctx->r12 = S32(ctx->r2 << 6);
            goto L_800BFCC0;
    }
    // 0x800BFCB8: sll         $t4, $v0, 6
    ctx->r12 = S32(ctx->r2 << 6);
    // 0x800BFCBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BFCC0:
    // 0x800BFCC0: bne         $at, $zero, L_800BFCCC
    if (ctx->r1 != 0) {
        // 0x800BFCC4: addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
            goto L_800BFCCC;
    }
    // 0x800BFCC4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800BFCC8: addiu       $a2, $a1, -0x1
    ctx->r6 = ADD32(ctx->r5, -0X1);
L_800BFCCC:
    // 0x800BFCCC: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BFCD0: bne         $at, $zero, L_800BFD30
    if (ctx->r1 != 0) {
        // 0x800BFCD4: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800BFD30;
    }
    // 0x800BFCD4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BFCD8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BFCDC: addiu       $t1, $t1, 0x3714
    ctx->r9 = ADD32(ctx->r9, 0X3714);
    // 0x800BFCE0: addiu       $t0, $a2, 0x1
    ctx->r8 = ADD32(ctx->r6, 0X1);
L_800BFCE4:
    // 0x800BFCE4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800BFCE8: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x800BFCEC: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x800BFCF0: lbu         $t7, 0x7($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7);
    // 0x800BFCF4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BFCF8: bne         $t2, $t7, L_800BFD28
    if (ctx->r10 != ctx->r15) {
        // 0x800BFCFC: nop
    
            goto L_800BFD28;
    }
    // 0x800BFCFC: nop

    // 0x800BFD00: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800BFD04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BFD08: beq         $t2, $t8, L_800BFD20
    if (ctx->r10 == ctx->r24) {
        // 0x800BFD0C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800BFD20;
    }
    // 0x800BFD0C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_800BFD10:
    // 0x800BFD10: lbu         $t9, 0x1($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X1);
    // 0x800BFD14: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BFD18: bne         $t2, $t9, L_800BFD10
    if (ctx->r10 != ctx->r25) {
        // 0x800BFD1C: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800BFD10;
    }
    // 0x800BFD1C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800BFD20:
    // 0x800BFD20: addu        $t3, $a0, $a2
    ctx->r11 = ADD32(ctx->r4, ctx->r6);
    // 0x800BFD24: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
L_800BFD28:
    // 0x800BFD28: bne         $t0, $a1, L_800BFCE4
    if (ctx->r8 != ctx->r5) {
        // 0x800BFD2C: nop
    
            goto L_800BFCE4;
    }
    // 0x800BFD2C: nop

L_800BFD30:
    // 0x800BFD30: lwc1        $f16, 0x8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800BFD34: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800BFD38: sub.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x800BFD3C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800BFD40: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x800BFD44: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800BFD48: swc1        $f12, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f12.u32l;
    // 0x800BFD4C: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x800BFD50: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800BFD54: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800BFD58: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800BFD5C: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800BFD60: swc1        $f14, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f14.u32l;
    // 0x800BFD64: sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
    // 0x800BFD68: swc1        $f10, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f10.u32l;
    // 0x800BFD6C: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    // 0x800BFD70: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800BFD74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BFD78: sh          $t6, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r14;
    // 0x800BFD7C: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800BFD80: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800BFD84: bne         $t7, $zero, L_800BFE34
    if (ctx->r15 != 0) {
        // 0x800BFD88: nop
    
            goto L_800BFE34;
    }
    // 0x800BFD88: nop

    // 0x800BFD8C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BFD90: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800BFD94: lwc1        $f19, -0x67D8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X67D8);
    // 0x800BFD98: lwc1        $f18, -0x67D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X67D4);
    // 0x800BFD9C: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x800BFDA0: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800BFDA4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800BFDA8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800BFDAC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BFDB0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BFDB4: nop

    // 0x800BFDB8: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800BFDBC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BFDC0: nop

    // 0x800BFDC4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800BFDC8: beq         $t9, $zero, L_800BFE18
    if (ctx->r25 == 0) {
        // 0x800BFDCC: nop
    
            goto L_800BFE18;
    }
    // 0x800BFDCC: nop

    // 0x800BFDD0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800BFDD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800BFDD8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800BFDDC: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x800BFDE0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BFDE4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BFDE8: nop

    // 0x800BFDEC: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800BFDF0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BFDF4: nop

    // 0x800BFDF8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800BFDFC: bne         $t9, $zero, L_800BFE10
    if (ctx->r25 != 0) {
        // 0x800BFE00: nop
    
            goto L_800BFE10;
    }
    // 0x800BFE00: nop

    // 0x800BFE04: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800BFE08: b           L_800BFE28
    // 0x800BFE0C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800BFE28;
    // 0x800BFE0C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800BFE10:
    // 0x800BFE10: b           L_800BFE28
    // 0x800BFE14: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800BFE28;
    // 0x800BFE14: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800BFE18:
    // 0x800BFE18: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800BFE1C: nop

    // 0x800BFE20: bltz        $t9, L_800BFE10
    if (SIGNED(ctx->r25) < 0) {
        // 0x800BFE24: nop
    
            goto L_800BFE10;
    }
    // 0x800BFE24: nop

L_800BFE28:
    // 0x800BFE28: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BFE2C: b           L_800BFED4
    // 0x800BFE30: sw          $t9, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r25;
        goto L_800BFED4;
    // 0x800BFE30: sw          $t9, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r25;
L_800BFE34:
    // 0x800BFE34: lwc1        $f11, -0x67D0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X67D0);
    // 0x800BFE38: lwc1        $f10, -0x67CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X67CC);
    // 0x800BFE3C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800BFE40: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800BFE44: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800BFE48: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800BFE4C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800BFE50: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BFE54: nop

    // 0x800BFE58: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x800BFE5C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BFE60: nop

    // 0x800BFE64: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800BFE68: beq         $t4, $zero, L_800BFEB8
    if (ctx->r12 == 0) {
        // 0x800BFE6C: nop
    
            goto L_800BFEB8;
    }
    // 0x800BFE6C: nop

    // 0x800BFE70: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800BFE74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800BFE78: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800BFE7C: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x800BFE80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BFE84: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BFE88: nop

    // 0x800BFE8C: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x800BFE90: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BFE94: nop

    // 0x800BFE98: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800BFE9C: bne         $t4, $zero, L_800BFEB0
    if (ctx->r12 != 0) {
        // 0x800BFEA0: nop
    
            goto L_800BFEB0;
    }
    // 0x800BFEA0: nop

    // 0x800BFEA4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800BFEA8: b           L_800BFEC8
    // 0x800BFEAC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800BFEC8;
    // 0x800BFEAC: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800BFEB0:
    // 0x800BFEB0: b           L_800BFEC8
    // 0x800BFEB4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800BFEC8;
    // 0x800BFEB4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_800BFEB8:
    // 0x800BFEB8: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800BFEBC: nop

    // 0x800BFEC0: bltz        $t4, L_800BFEB0
    if (SIGNED(ctx->r12) < 0) {
        // 0x800BFEC4: nop
    
            goto L_800BFEB0;
    }
    // 0x800BFEC4: nop

L_800BFEC8:
    // 0x800BFEC8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800BFECC: sw          $t4, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r12;
    // 0x800BFED0: nop

L_800BFED4:
    // 0x800BFED4: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800BFED8: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800BFEDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BFEE0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800BFEE4: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BFEE8: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x800BFEEC: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x800BFEF0: swc1        $f6, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f6.u32l;
    // 0x800BFEF4: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BFEF8: swc1        $f0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f0.u32l;
    // 0x800BFEFC: sb          $t5, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r13;
    // 0x800BFF00: sb          $t6, 0x31($a1)
    MEM_B(0X31, ctx->r5) = ctx->r14;
    // 0x800BFF04: swc1        $f2, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f2.u32l;
    // 0x800BFF08: swc1        $f8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f8.u32l;
L_800BFF0C:
    // 0x800BFF0C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800BFF10: jr          $ra
    // 0x800BFF14: nop

    return;
    // 0x800BFF14: nop

;}
RECOMP_FUNC void func_800BF9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFF18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BFF1C: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x800BFF20: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800BFF24: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800BFF28: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800BFF2C: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BFF30: beq         $a0, $zero, L_800C015C
    if (ctx->r4 == 0) {
        // 0x800BFF34: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_800C015C;
    }
    // 0x800BFF34: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800BFF38: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BFF3C: lw          $t6, -0x5A50($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5A50);
    // 0x800BFF40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BFF44: lwc1        $f0, -0x5988($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800BFF48: beq         $t6, $zero, L_800BFF64
    if (ctx->r14 == 0) {
        // 0x800BFF4C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BFF64;
    }
    // 0x800BFF4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BFF50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BFF54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BFF58: nop

    // 0x800BFF5C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800BFF60: nop

L_800BFF64:
    // 0x800BFF64: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800BFF68: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BFF6C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BFF70: lhu         $v1, 0x18($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X18);
    // 0x800BFF74: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BFF78: addiu       $t3, $t3, -0x5970
    ctx->r11 = ADD32(ctx->r11, -0X5970);
    // 0x800BFF7C: addiu       $t4, $t4, 0x371C
    ctx->r12 = ADD32(ctx->r12, 0X371C);
    // 0x800BFF80: addiu       $t5, $t5, 0x3714
    ctx->r13 = ADD32(ctx->r13, 0X3714);
    // 0x800BFF84: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x800BFF88: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
L_800BFF8C:
    // 0x800BFF8C: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800BFF90: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800BFF94: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800BFF98: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800BFF9C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BFFA0: lw          $a3, 0x0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X0);
    // 0x800BFFA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800BFFA8: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800BFFAC: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800BFFB0: nop

    // 0x800BFFB4: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BFFB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BFFBC: nop

    // 0x800BFFC0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BFFC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BFFC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BFFCC: nop

    // 0x800BFFD0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800BFFD4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800BFFD8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BFFDC: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800BFFE0: bne         $at, $zero, L_800BFFF0
    if (ctx->r1 != 0) {
        // 0x800BFFE4: nop
    
            goto L_800BFFF0;
    }
    // 0x800BFFE4: nop

    // 0x800BFFE8: b           L_800BFFFC
    // 0x800BFFEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800BFFFC;
    // 0x800BFFEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800BFFF0:
    // 0x800BFFF0: bgez        $a2, L_800BFFFC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800BFFF4: nop
    
            goto L_800BFFFC;
    }
    // 0x800BFFF4: nop

    // 0x800BFFF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800BFFFC:
    // 0x800BFFFC: beq         $a1, $zero, L_800C0054
    if (ctx->r5 == 0) {
        // 0x800C0000: nop
    
            goto L_800C0054;
    }
    // 0x800C0000: nop

    // 0x800C0004: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800C0008: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x800C000C: nop

    // 0x800C0010: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C0014: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C0018: nop

    // 0x800C001C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800C0020: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C0024: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C0028: nop

    // 0x800C002C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800C0030: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800C0034: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C0038: bgez        $t0, L_800C0048
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800C003C: slt         $at, $t0, $a3
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800C0048;
    }
    // 0x800C003C: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C0040: b           L_800C0054
    // 0x800C0044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800C0054;
    // 0x800C0044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800C0048:
    // 0x800C0048: bne         $at, $zero, L_800C0054
    if (ctx->r1 != 0) {
        // 0x800C004C: nop
    
            goto L_800C0054;
    }
    // 0x800C004C: nop

    // 0x800C0050: addiu       $t0, $a3, -0x1
    ctx->r8 = ADD32(ctx->r7, -0X1);
L_800C0054:
    // 0x800C0054: beq         $a1, $zero, L_800C0110
    if (ctx->r5 == 0) {
        // 0x800C0058: slt         $at, $t0, $a2
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800C0110;
    }
    // 0x800C0058: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800C005C: bne         $at, $zero, L_800C0110
    if (ctx->r1 != 0) {
        // 0x800C0060: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800C0110;
    }
    // 0x800C0060: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800C0064: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
L_800C0068:
    // 0x800C0068: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800C006C: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800C0070: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C0074: beq         $v0, $zero, L_800C00B4
    if (ctx->r2 == 0) {
        // 0x800C0078: addu        $a2, $t6, $t7
        ctx->r6 = ADD32(ctx->r14, ctx->r15);
            goto L_800C00B4;
    }
    // 0x800C0078: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x800C007C: lbu         $t8, 0x7($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X7);
    // 0x800C0080: nop

    // 0x800C0084: bne         $s0, $t8, L_800C0104
    if (ctx->r16 != ctx->r24) {
        // 0x800C0088: nop
    
            goto L_800C0104;
    }
    // 0x800C0088: nop

    // 0x800C008C: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800C0090: nop

    // 0x800C0094: beq         $s0, $t9, L_800C00AC
    if (ctx->r16 == ctx->r25) {
        // 0x800C0098: nop
    
            goto L_800C00AC;
    }
    // 0x800C0098: nop

L_800C009C:
    // 0x800C009C: lbu         $t6, 0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1);
    // 0x800C00A0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C00A4: bne         $s0, $t6, L_800C009C
    if (ctx->r16 != ctx->r14) {
        // 0x800C00A8: nop
    
            goto L_800C009C;
    }
    // 0x800C00A8: nop

L_800C00AC:
    // 0x800C00AC: b           L_800C0104
    // 0x800C00B0: sb          $v1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r3;
        goto L_800C0104;
    // 0x800C00B0: sb          $v1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r3;
L_800C00B4:
    // 0x800C00B4: addu        $t1, $a2, $a3
    ctx->r9 = ADD32(ctx->r6, ctx->r7);
L_800C00B8:
    // 0x800C00B8: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x800C00BC: slti        $at, $a3, 0x7
    ctx->r1 = SIGNED(ctx->r7) < 0X7 ? 1 : 0;
    // 0x800C00C0: bne         $v1, $t7, L_800C00F4
    if (ctx->r3 != ctx->r15) {
        // 0x800C00C4: nop
    
            goto L_800C00F4;
    }
    // 0x800C00C4: nop

    // 0x800C00C8: beq         $at, $zero, L_800C00E8
    if (ctx->r1 == 0) {
        // 0x800C00CC: nop
    
            goto L_800C00E8;
    }
    // 0x800C00CC: nop

L_800C00D0:
    // 0x800C00D0: lbu         $t8, 0x1($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1);
    // 0x800C00D4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C00D8: slti        $at, $a3, 0x7
    ctx->r1 = SIGNED(ctx->r7) < 0X7 ? 1 : 0;
    // 0x800C00DC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800C00E0: bne         $at, $zero, L_800C00D0
    if (ctx->r1 != 0) {
        // 0x800C00E4: sb          $t8, -0x1($t1)
        MEM_B(-0X1, ctx->r9) = ctx->r24;
            goto L_800C00D0;
    }
    // 0x800C00E4: sb          $t8, -0x1($t1)
    MEM_B(-0X1, ctx->r9) = ctx->r24;
L_800C00E8:
    // 0x800C00E8: sb          $s1, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r17;
    // 0x800C00EC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C00F0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800C00F4:
    // 0x800C00F4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C00F8: slti        $at, $a3, 0x8
    ctx->r1 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
    // 0x800C00FC: bne         $at, $zero, L_800C00B8
    if (ctx->r1 != 0) {
        // 0x800C0100: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800C00B8;
    }
    // 0x800C0100: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800C0104:
    // 0x800C0104: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C0108: bne         $t2, $a1, L_800C0068
    if (ctx->r10 != ctx->r5) {
        // 0x800C010C: nop
    
            goto L_800C0068;
    }
    // 0x800C010C: nop

L_800C0110:
    // 0x800C0110: bne         $v0, $zero, L_800C014C
    if (ctx->r2 != 0) {
        // 0x800C0114: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C014C;
    }
    // 0x800C0114: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C0118: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800C011C: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C0120: lwc1        $f14, 0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800C0124: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800C0128: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C012C: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C0130: add.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f20.fl;
    // 0x800C0134: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x800C0138: add.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x800C013C: swc1        $f14, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f14.u32l;
    // 0x800C0140: add.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x800C0144: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800C0148: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
L_800C014C:
    // 0x800C014C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C0150: bne         $v0, $at, L_800BFF8C
    if (ctx->r2 != ctx->r1) {
        // 0x800C0154: nop
    
            goto L_800BFF8C;
    }
    // 0x800C0154: nop

    // 0x800C0158: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_800C015C:
    // 0x800C015C: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800C0160: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C0164: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C0168: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C016C: jr          $ra
    // 0x800C0170: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C0170: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void wavegen_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0174: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C0178: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C017C: beq         $a0, $zero, L_800C03B0
    if (ctx->r4 == 0) {
        // 0x800C0180: sw          $a3, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r7;
            goto L_800C03B0;
    }
    // 0x800C0180: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800C0184: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800C0188: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C018C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800C0190: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800C0194: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x800C0198: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800C019C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C01A0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800C01A4: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x800C01A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C01AC: bc1f        L_800C01C8
    if (!c1cs) {
        // 0x800C01B0: nop
    
            goto L_800C01C8;
    }
    // 0x800C01B0: nop

    // 0x800C01B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C01B8: nop

    // 0x800C01BC: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800C01C0: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800C01C4: nop

L_800C01C8:
    // 0x800C01C8: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800C01CC: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800C01D0: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C01D4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800C01D8: add.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C01DC: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800C01E0: add.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800C01E4: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x800C01E8: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x800C01EC: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800C01F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C01F4: bne         $t6, $zero, L_800C02A4
    if (ctx->r14 != 0) {
        // 0x800C01F8: nop
    
            goto L_800C02A4;
    }
    // 0x800C01F8: nop

    // 0x800C01FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C0200: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800C0204: lwc1        $f5, -0x67C8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X67C8);
    // 0x800C0208: lwc1        $f4, -0x67C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X67C4);
    // 0x800C020C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800C0210: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C0214: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C0218: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800C021C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C0220: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C0224: nop

    // 0x800C0228: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800C022C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C0230: nop

    // 0x800C0234: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800C0238: beq         $t8, $zero, L_800C0288
    if (ctx->r24 == 0) {
        // 0x800C023C: nop
    
            goto L_800C0288;
    }
    // 0x800C023C: nop

    // 0x800C0240: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800C0244: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C0248: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C024C: sub.d       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f6.d - ctx->f8.d;
    // 0x800C0250: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C0254: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C0258: nop

    // 0x800C025C: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C0260: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C0264: nop

    // 0x800C0268: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800C026C: bne         $t8, $zero, L_800C0280
    if (ctx->r24 != 0) {
        // 0x800C0270: nop
    
            goto L_800C0280;
    }
    // 0x800C0270: nop

    // 0x800C0274: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800C0278: b           L_800C0298
    // 0x800C027C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800C0298;
    // 0x800C027C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800C0280:
    // 0x800C0280: b           L_800C0298
    // 0x800C0284: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800C0298;
    // 0x800C0284: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800C0288:
    // 0x800C0288: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800C028C: nop

    // 0x800C0290: bltz        $t8, L_800C0280
    if (SIGNED(ctx->r24) < 0) {
        // 0x800C0294: nop
    
            goto L_800C0280;
    }
    // 0x800C0294: nop

L_800C0298:
    // 0x800C0298: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C029C: b           L_800C0348
    // 0x800C02A0: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
        goto L_800C0348;
    // 0x800C02A0: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
L_800C02A4:
    // 0x800C02A4: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800C02A8: lwc1        $f5, -0x67C0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X67C0);
    // 0x800C02AC: lwc1        $f4, -0x67BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X67BC);
    // 0x800C02B0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800C02B4: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C02B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C02BC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800C02C0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C02C4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800C02C8: nop

    // 0x800C02CC: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800C02D0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800C02D4: nop

    // 0x800C02D8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800C02DC: beq         $t0, $zero, L_800C032C
    if (ctx->r8 == 0) {
        // 0x800C02E0: nop
    
            goto L_800C032C;
    }
    // 0x800C02E0: nop

    // 0x800C02E4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800C02E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C02EC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C02F0: sub.d       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f6.d - ctx->f8.d;
    // 0x800C02F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C02F8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800C02FC: nop

    // 0x800C0300: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C0304: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800C0308: nop

    // 0x800C030C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800C0310: bne         $t0, $zero, L_800C0324
    if (ctx->r8 != 0) {
        // 0x800C0314: nop
    
            goto L_800C0324;
    }
    // 0x800C0314: nop

    // 0x800C0318: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800C031C: b           L_800C033C
    // 0x800C0320: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800C033C;
    // 0x800C0320: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800C0324:
    // 0x800C0324: b           L_800C033C
    // 0x800C0328: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800C033C;
    // 0x800C0328: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800C032C:
    // 0x800C032C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800C0330: nop

    // 0x800C0334: bltz        $t0, L_800C0324
    if (SIGNED(ctx->r8) < 0) {
        // 0x800C0338: nop
    
            goto L_800C0324;
    }
    // 0x800C0338: nop

L_800C033C:
    // 0x800C033C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C0340: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x800C0344: nop

L_800C0348:
    // 0x800C0348: lwc1        $f10, 0x2C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800C034C: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C0350: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C0354: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800C0358: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x800C035C: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800C0360: nop

    // 0x800C0364: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800C0368: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x800C036C: nop

    // 0x800C0370: bc1f        L_800C038C
    if (!c1cs) {
        // 0x800C0374: nop
    
            goto L_800C038C;
    }
    // 0x800C0374: nop

    // 0x800C0378: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C037C: nop

    // 0x800C0380: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
    // 0x800C0384: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800C0388: nop

L_800C038C:
    // 0x800C038C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800C0390: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C0394: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800C0398: div.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800C039C: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x800C03A0: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C03A4: nop

    // 0x800C03A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C03AC: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
L_800C03B0:
    // 0x800C03B0: jr          $ra
    // 0x800C03B4: nop

    return;
    // 0x800C03B4: nop

;}
RECOMP_FUNC void func_800BFE98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C03B8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C03BC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800C03C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C03C4: addiu       $t0, $t0, 0x3724
    ctx->r8 = ADD32(ctx->r8, 0X3724);
    // 0x800C03C8: addiu       $t1, $t1, 0x3720
    ctx->r9 = ADD32(ctx->r9, 0X3720);
    // 0x800C03CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C03D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C03D4: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
L_800C03D8:
    // 0x800C03D8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800C03DC: nop

    // 0x800C03E0: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    // 0x800C03E4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800C03E8: nop

    // 0x800C03EC: beq         $t7, $zero, L_800C0428
    if (ctx->r15 == 0) {
        // 0x800C03F0: nop
    
            goto L_800C0428;
    }
    // 0x800C03F0: nop

    // 0x800C03F4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800C03F8: sll         $t9, $v0, 6
    ctx->r25 = S32(ctx->r2 << 6);
    // 0x800C03FC: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x800C0400: lw          $t3, 0x1C($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X1C);
    // 0x800C0404: lhu         $t4, 0x1A($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X1A);
    // 0x800C0408: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C040C: mflo        $a1
    ctx->r5 = lo;
    // 0x800C0410: srl         $t5, $a1, 4
    ctx->r13 = S32(U32(ctx->r5) >> 4);
    // 0x800C0414: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800C0418: sh          $t6, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r14;
    // 0x800C041C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800C0420: nop

    // 0x800C0424: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
L_800C0428:
    // 0x800C0428: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x800C042C: nop

    // 0x800C0430: beq         $t8, $zero, L_800C046C
    if (ctx->r24 == 0) {
        // 0x800C0434: nop
    
            goto L_800C046C;
    }
    // 0x800C0434: nop

    // 0x800C0438: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800C043C: sll         $t3, $v0, 6
    ctx->r11 = S32(ctx->r2 << 6);
    // 0x800C0440: addu        $a2, $t9, $t3
    ctx->r6 = ADD32(ctx->r25, ctx->r11);
    // 0x800C0444: lw          $t4, 0x5C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X5C);
    // 0x800C0448: lhu         $t5, 0x5A($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X5A);
    // 0x800C044C: multu       $t4, $a3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C0450: mflo        $a1
    ctx->r5 = lo;
    // 0x800C0454: srl         $t6, $a1, 4
    ctx->r14 = S32(U32(ctx->r5) >> 4);
    // 0x800C0458: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800C045C: sh          $t7, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r15;
    // 0x800C0460: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800C0464: nop

    // 0x800C0468: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
L_800C046C:
    // 0x800C046C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C0470: nop

    // 0x800C0474: beq         $t9, $zero, L_800C04B0
    if (ctx->r25 == 0) {
        // 0x800C0478: nop
    
            goto L_800C04B0;
    }
    // 0x800C0478: nop

    // 0x800C047C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800C0480: sll         $t4, $v0, 6
    ctx->r12 = S32(ctx->r2 << 6);
    // 0x800C0484: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x800C0488: lw          $t5, 0x9C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X9C);
    // 0x800C048C: lhu         $t6, 0x9A($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X9A);
    // 0x800C0490: multu       $t5, $a3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C0494: mflo        $a1
    ctx->r5 = lo;
    // 0x800C0498: srl         $t7, $a1, 4
    ctx->r15 = S32(U32(ctx->r5) >> 4);
    // 0x800C049C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800C04A0: sh          $t8, 0x9A($a2)
    MEM_H(0X9A, ctx->r6) = ctx->r24;
    // 0x800C04A4: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800C04A8: nop

    // 0x800C04AC: addu        $a0, $t9, $v1
    ctx->r4 = ADD32(ctx->r25, ctx->r3);
L_800C04B0:
    // 0x800C04B0: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800C04B4: nop

    // 0x800C04B8: beq         $t3, $zero, L_800C04E8
    if (ctx->r11 == 0) {
        // 0x800C04BC: nop
    
            goto L_800C04E8;
    }
    // 0x800C04BC: nop

    // 0x800C04C0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800C04C4: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x800C04C8: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x800C04CC: lw          $t6, 0xDC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XDC);
    // 0x800C04D0: lhu         $t7, 0xDA($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XDA);
    // 0x800C04D4: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C04D8: mflo        $a1
    ctx->r5 = lo;
    // 0x800C04DC: srl         $t8, $a1, 4
    ctx->r24 = S32(U32(ctx->r5) >> 4);
    // 0x800C04E0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C04E4: sh          $t9, 0xDA($a2)
    MEM_H(0XDA, ctx->r6) = ctx->r25;
L_800C04E8:
    // 0x800C04E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C04EC: bne         $v0, $t2, L_800C03D8
    if (ctx->r2 != ctx->r10) {
        // 0x800C04F0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800C03D8;
    }
    // 0x800C04F0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800C04F4: jr          $ra
    // 0x800C04F8: nop

    return;
    // 0x800C04F8: nop

;}
RECOMP_FUNC void obj_loop_wavepower(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C04FC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C0500: lw          $t6, 0x3728($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3728);
    // 0x800C0504: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800C0508: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C050C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C0510: beq         $a0, $t6, L_800C0680
    if (ctx->r4 == ctx->r14) {
        // 0x800C0514: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800C0680;
    }
    // 0x800C0514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C0518: jal         0x8001BAA8
    // 0x800C051C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800C051C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x800C0520: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800C0524: nop

    // 0x800C0528: blez        $a1, L_800C0684
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C052C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C0684;
    }
    // 0x800C052C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0530: blez        $a1, L_800C057C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C0534: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800C057C;
    }
    // 0x800C0534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C0538: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C053C: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x800C0540: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x800C0544: addu        $a3, $t7, $v0
    ctx->r7 = ADD32(ctx->r15, ctx->r2);
L_800C0548:
    // 0x800C0548: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800C054C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C0550: lw          $a0, 0x64($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X64);
    // 0x800C0554: sltu        $at, $v1, $a3
    ctx->r1 = ctx->r3 < ctx->r7 ? 1 : 0;
    // 0x800C0558: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x800C055C: nop

    // 0x800C0560: bne         $t9, $zero, L_800C056C
    if (ctx->r25 != 0) {
        // 0x800C0564: nop
    
            goto L_800C056C;
    }
    // 0x800C0564: nop

    // 0x800C0568: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_800C056C:
    // 0x800C056C: beq         $at, $zero, L_800C057C
    if (ctx->r1 == 0) {
        // 0x800C0570: nop
    
            goto L_800C057C;
    }
    // 0x800C0570: nop

    // 0x800C0574: beq         $a2, $zero, L_800C0548
    if (ctx->r6 == 0) {
        // 0x800C0578: nop
    
            goto L_800C0548;
    }
    // 0x800C0578: nop

L_800C057C:
    // 0x800C057C: beq         $a2, $zero, L_800C0684
    if (ctx->r6 == 0) {
        // 0x800C0580: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C0684;
    }
    // 0x800C0580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0584: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x800C0588: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C058C: lhu         $t0, 0x8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X8);
    // 0x800C0590: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C0594: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800C0598: bgez        $t0, L_800C05AC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800C059C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C05AC;
    }
    // 0x800C059C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C05A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C05A4: nop

    // 0x800C05A8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_800C05AC:
    // 0x800C05AC: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800C05B0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800C05B4: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C05B8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800C05BC: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800C05C0: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800C05C4: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C05C8: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800C05CC: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800C05D0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800C05D4: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800C05D8: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C05DC: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C05E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C05E4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800C05E8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800C05EC: nop

    // 0x800C05F0: bc1f        L_800C0684
    if (!c1cs) {
        // 0x800C05F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C0684;
    }
    // 0x800C05F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C05F8: lhu         $t1, 0xA($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XA);
    // 0x800C05FC: addiu       $v1, $v1, -0x5320
    ctx->r3 = ADD32(ctx->r3, -0X5320);
    // 0x800C0600: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800C0604: bgez        $t1, L_800C061C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800C0608: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800C061C;
    }
    // 0x800C0608: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C060C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0610: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C0614: nop

    // 0x800C0618: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800C061C:
    // 0x800C061C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800C0620: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C0624: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0628: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C062C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x800C0630: lhu         $t2, 0xC($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XC);
    // 0x800C0634: lwc1        $f6, -0x5A38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800C0638: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C063C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800C0640: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C0644: bgez        $t2, L_800C065C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800C0648: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C065C;
    }
    // 0x800C0648: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C064C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0650: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C0654: nop

    // 0x800C0658: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800C065C:
    // 0x800C065C: nop

    // 0x800C0660: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C0664: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0668: swc1        $f4, -0x531C($at)
    MEM_W(-0X531C, ctx->r1) = ctx->f4.u32l;
    // 0x800C066C: lhu         $t3, 0xC($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XC);
    // 0x800C0670: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0674: sw          $t3, -0x5318($at)
    MEM_W(-0X5318, ctx->r1) = ctx->r11;
    // 0x800C0678: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C067C: sw          $s0, 0x3728($at)
    MEM_W(0X3728, ctx->r1) = ctx->r16;
L_800C0680:
    // 0x800C0680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C0684:
    // 0x800C0684: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C0688: jr          $ra
    // 0x800C068C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800C068C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void enable_new_screen_transitions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0690: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C0694: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0698: jr          $ra
    // 0x800C069C: sw          $t6, 0x3730($at)
    MEM_W(0X3730, ctx->r1) = ctx->r14;
    return;
    // 0x800C069C: sw          $t6, 0x3730($at)
    MEM_W(0X3730, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void disable_new_screen_transitions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C06A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C06A4: jr          $ra
    // 0x800C06A8: sw          $zero, 0x3730($at)
    MEM_W(0X3730, ctx->r1) = 0;
    return;
    // 0x800C06A8: sw          $zero, 0x3730($at)
    MEM_W(0X3730, ctx->r1) = 0;
;}
RECOMP_FUNC void check_fadeout_transition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C06AC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C06B0: lhu         $v0, 0x3740($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3740);
    // 0x800C06B4: nop

    // 0x800C06B8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C06BC: bne         $t6, $zero, L_800C06F0
    if (ctx->r14 != 0) {
        // 0x800C06C0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800C06F0;
    }
    // 0x800C06C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800C06C4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C06C8: lhu         $v0, 0x3744($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3744);
    // 0x800C06CC: nop

    // 0x800C06D0: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C06D4: beq         $t7, $zero, L_800C06F0
    if (ctx->r15 == 0) {
        // 0x800C06D8: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800C06F0;
    }
    // 0x800C06D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800C06DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C06E0: lb          $v0, 0x374C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X374C);
    // 0x800C06E4: nop

    // 0x800C06E8: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C06EC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800C06F0:
    // 0x800C06F0: jr          $ra
    // 0x800C06F4: nop

    return;
    // 0x800C06F4: nop

;}
RECOMP_FUNC void transition_begin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C06F8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C06FC: lw          $t6, 0x3730($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3730);
    // 0x800C0700: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C0704: beq         $t6, $zero, L_800C0714
    if (ctx->r14 == 0) {
        // 0x800C0708: sw          $ra, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r31;
            goto L_800C0714;
    }
    // 0x800C0708: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C070C: b           L_800C09A4
    // 0x800C0710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C09A4;
    // 0x800C0710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0714:
    // 0x800C0714: jal         0x800C0C44
    // 0x800C0718: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    transition_end(rdram, ctx);
        goto after_0;
    // 0x800C0718: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C071C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800C0720: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0724: bne         $a0, $zero, L_800C0734
    if (ctx->r4 != 0) {
        // 0x800C0728: addiu       $v1, $v1, 0x374C
        ctx->r3 = ADD32(ctx->r3, 0X374C);
            goto L_800C0734;
    }
    // 0x800C0728: addiu       $v1, $v1, 0x374C
    ctx->r3 = ADD32(ctx->r3, 0X374C);
    // 0x800C072C: b           L_800C09A4
    // 0x800C0730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C09A4;
    // 0x800C0730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0734:
    // 0x800C0734: lhu         $t7, 0x4($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X4);
    // 0x800C0738: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C073C: addiu       $a2, $a2, 0x3740
    ctx->r6 = ADD32(ctx->r6, 0X3740);
    // 0x800C0740: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x800C0744: lhu         $t8, 0x4($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X4);
    // 0x800C0748: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C074C: sh          $t8, 0x3748($at)
    MEM_H(0X3748, ctx->r1) = ctx->r24;
    // 0x800C0750: lhu         $t9, 0x6($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6);
    // 0x800C0754: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0758: sh          $t9, 0x3744($at)
    MEM_H(0X3744, ctx->r1) = ctx->r25;
    // 0x800C075C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0760: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C0764: andi        $t0, $v0, 0x80
    ctx->r8 = ctx->r2 & 0X80;
    // 0x800C0768: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x800C076C: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x800C0770: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0774: addiu       $a3, $a3, -0x5310
    ctx->r7 = ADD32(ctx->r7, -0X5310);
    // 0x800C0778: andi        $t3, $t2, 0x3F
    ctx->r11 = ctx->r10 & 0X3F;
    // 0x800C077C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x800C0780: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0784: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0788: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x800C078C: sw          $t5, 0x3738($at)
    MEM_W(0X3738, ctx->r1) = ctx->r13;
    // 0x800C0790: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x800C0794: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C0798: addiu       $a1, $a1, 0x3734
    ctx->r5 = ADD32(ctx->r5, 0X3734);
    // 0x800C079C: bne         $t6, $zero, L_800C07AC
    if (ctx->r14 != 0) {
        // 0x800C07A0: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_800C07AC;
    }
    // 0x800C07A0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800C07A4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800C07A8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
L_800C07AC:
    // 0x800C07AC: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x800C07B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C07B4: blez        $t9, L_800C0998
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800C07B8: addiu       $v0, $v0, -0x530C
        ctx->r2 = ADD32(ctx->r2, -0X530C);
            goto L_800C0998;
    }
    // 0x800C07B8: addiu       $v0, $v0, -0x530C
    ctx->r2 = ADD32(ctx->r2, -0X530C);
    // 0x800C07BC: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x800C07C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C07C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C07C8: addiu       $v1, $v1, -0x530B
    ctx->r3 = ADD32(ctx->r3, -0X530B);
    // 0x800C07CC: sw          $t0, -0x5308($at)
    MEM_W(-0X5308, ctx->r1) = ctx->r8;
    // 0x800C07D0: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x800C07D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C07D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C07DC: addiu       $a1, $a1, -0x530A
    ctx->r5 = ADD32(ctx->r5, -0X530A);
    // 0x800C07E0: sw          $t1, -0x5304($at)
    MEM_W(-0X5304, ctx->r1) = ctx->r9;
    // 0x800C07E4: lbu         $t2, 0x0($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X0);
    // 0x800C07E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C07EC: sw          $t2, -0x5300($at)
    MEM_W(-0X5300, ctx->r1) = ctx->r10;
    // 0x800C07F0: lbu         $t3, 0x1($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X1);
    // 0x800C07F4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800C07F8: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x800C07FC: lbu         $t4, 0x2($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X2);
    // 0x800C0800: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x800C0804: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x800C0808: lbu         $t5, 0x3($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X3);
    // 0x800C080C: beq         $at, $zero, L_800C0998
    if (ctx->r1 == 0) {
        // 0x800C0810: sb          $t5, 0x0($a1)
        MEM_B(0X0, ctx->r5) = ctx->r13;
            goto L_800C0998;
    }
    // 0x800C0810: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
    // 0x800C0814: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C0818: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C081C: addu        $at, $at, $t6
    gpr jr_addend_800C0828 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C0820: lw          $t6, -0x67B0($at)
    ctx->r14 = ADD32(ctx->r1, -0X67B0);
    // 0x800C0824: nop

    // 0x800C0828: jr          $t6
    // 0x800C082C: nop

    switch (jr_addend_800C0828 >> 2) {
        case 0: goto L_800C0830; break;
        case 1: goto L_800C0840; break;
        case 2: goto L_800C0890; break;
        case 3: goto L_800C08E0; break;
        case 4: goto L_800C08F0; break;
        case 5: goto L_800C0940; break;
        case 6: goto L_800C0990; break;
        default: switch_error(__func__, 0x800C0828, 0x800E9850);
    }
    // 0x800C082C: nop

L_800C0830:
    // 0x800C0830: jal         0x800C0CA0
    // 0x800C0834: nop

    transition_fullscreen_start(rdram, ctx);
        goto after_1;
    // 0x800C0834: nop

    after_1:
    // 0x800C0838: b           L_800C0998
    // 0x800C083C: nop

        goto L_800C0998;
    // 0x800C083C: nop

L_800C0840:
    // 0x800C0840: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0844: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800C0848: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C084C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C0850: addiu       $v0, $v0, 0x3860
    ctx->r2 = ADD32(ctx->r2, 0X3860);
    // 0x800C0854: addiu       $t9, $t9, 0x3848
    ctx->r25 = ADD32(ctx->r25, 0X3848);
    // 0x800C0858: addiu       $t8, $t8, 0x383C
    ctx->r24 = ADD32(ctx->r24, 0X383C);
    // 0x800C085C: addiu       $t7, $t7, 0x3830
    ctx->r15 = ADD32(ctx->r15, 0X3830);
    // 0x800C0860: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C0864: addiu       $a3, $a3, 0x37C0
    ctx->r7 = ADD32(ctx->r7, 0X37C0);
    // 0x800C0868: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C086C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800C0870: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800C0874: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C0878: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C087C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800C0880: jal         0x800C1020
    // 0x800C0884: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    transition_init_shape(rdram, ctx);
        goto after_2;
    // 0x800C0884: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x800C0888: b           L_800C0998
    // 0x800C088C: nop

        goto L_800C0998;
    // 0x800C088C: nop

L_800C0890:
    // 0x800C0890: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0894: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800C0898: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C089C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C08A0: addiu       $v0, $v0, 0x3860
    ctx->r2 = ADD32(ctx->r2, 0X3860);
    // 0x800C08A4: addiu       $t2, $t2, 0x3848
    ctx->r10 = ADD32(ctx->r10, 0X3848);
    // 0x800C08A8: addiu       $t1, $t1, 0x383C
    ctx->r9 = ADD32(ctx->r9, 0X383C);
    // 0x800C08AC: addiu       $t0, $t0, 0x3830
    ctx->r8 = ADD32(ctx->r8, 0X3830);
    // 0x800C08B0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C08B4: addiu       $a3, $a3, 0x37F8
    ctx->r7 = ADD32(ctx->r7, 0X37F8);
    // 0x800C08B8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C08BC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800C08C0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800C08C4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C08C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C08CC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800C08D0: jal         0x800C1020
    // 0x800C08D4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    transition_init_shape(rdram, ctx);
        goto after_3;
    // 0x800C08D4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x800C08D8: b           L_800C0998
    // 0x800C08DC: nop

        goto L_800C0998;
    // 0x800C08DC: nop

L_800C08E0:
    // 0x800C08E0: jal         0x800C1AF4
    // 0x800C08E4: nop

    transition_init_circle(rdram, ctx);
        goto after_4;
    // 0x800C08E4: nop

    after_4:
    // 0x800C08E8: b           L_800C0998
    // 0x800C08EC: nop

        goto L_800C0998;
    // 0x800C08EC: nop

L_800C08F0:
    // 0x800C08F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C08F4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800C08F8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800C08FC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C0900: addiu       $v0, $v0, 0x3A88
    ctx->r2 = ADD32(ctx->r2, 0X3A88);
    // 0x800C0904: addiu       $t5, $t5, 0x3AE4
    ctx->r13 = ADD32(ctx->r13, 0X3AE4);
    // 0x800C0908: addiu       $t4, $t4, 0x39D0
    ctx->r12 = ADD32(ctx->r12, 0X39D0);
    // 0x800C090C: addiu       $t3, $t3, 0x3A2C
    ctx->r11 = ADD32(ctx->r11, 0X3A2C);
    // 0x800C0910: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C0914: addiu       $a3, $a3, 0x38D4
    ctx->r7 = ADD32(ctx->r7, 0X38D4);
    // 0x800C0918: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800C091C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800C0920: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800C0924: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C0928: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C092C: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x800C0930: jal         0x800C1020
    // 0x800C0934: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    transition_init_shape(rdram, ctx);
        goto after_5;
    // 0x800C0934: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_5:
    // 0x800C0938: b           L_800C0998
    // 0x800C093C: nop

        goto L_800C0998;
    // 0x800C093C: nop

L_800C0940:
    // 0x800C0940: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0944: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C0948: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800C094C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C0950: addiu       $v0, $v0, 0x38C8
    ctx->r2 = ADD32(ctx->r2, 0X38C8);
    // 0x800C0954: addiu       $t8, $t8, 0x38B4
    ctx->r24 = ADD32(ctx->r24, 0X38B4);
    // 0x800C0958: addiu       $t7, $t7, 0x38A8
    ctx->r15 = ADD32(ctx->r15, 0X38A8);
    // 0x800C095C: addiu       $t6, $t6, 0x389C
    ctx->r14 = ADD32(ctx->r14, 0X389C);
    // 0x800C0960: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C0964: addiu       $a3, $a3, 0x386C
    ctx->r7 = ADD32(ctx->r7, 0X386C);
    // 0x800C0968: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C096C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C0970: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800C0974: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C0978: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C097C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C0980: jal         0x800C1020
    // 0x800C0984: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    transition_init_shape(rdram, ctx);
        goto after_6;
    // 0x800C0984: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_6:
    // 0x800C0988: b           L_800C0998
    // 0x800C098C: nop

        goto L_800C0998;
    // 0x800C098C: nop

L_800C0990:
    // 0x800C0990: jal         0x800C2B60
    // 0x800C0994: nop

    transition_init_blank(rdram, ctx);
        goto after_7;
    // 0x800C0994: nop

    after_7:
L_800C0998:
    // 0x800C0998: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C099C: lw          $v0, 0x373C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X373C);
    // 0x800C09A0: nop

L_800C09A4:
    // 0x800C09A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C09A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C09AC: jr          $ra
    // 0x800C09B0: nop

    return;
    // 0x800C09B0: nop

;}
RECOMP_FUNC void transition_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C09B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C09B8: addiu       $v1, $v1, 0x3734
    ctx->r3 = ADD32(ctx->r3, 0X3734);
    // 0x800C09BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C09C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C09C4: beq         $v0, $zero, L_800C09DC
    if (ctx->r2 == 0) {
        // 0x800C09C8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C09DC;
    }
    // 0x800C09C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C09CC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800C09D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C09D4: b           L_800C09EC
    // 0x800C09D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800C09EC;
    // 0x800C09D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800C09DC:
    // 0x800C09DC: slti        $at, $a0, 0x6
    ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x800C09E0: bne         $at, $zero, L_800C09EC
    if (ctx->r1 != 0) {
        // 0x800C09E4: nop
    
            goto L_800C09EC;
    }
    // 0x800C09E4: nop

    // 0x800C09E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800C09EC:
    // 0x800C09EC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C09F0: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
    // 0x800C09F4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C09F8: nop

    // 0x800C09FC: beq         $t7, $zero, L_800C0AD8
    if (ctx->r15 == 0) {
        // 0x800C0A00: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800C0AD8;
    }
    // 0x800C0A00: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0A04: lhu         $v0, 0x3740($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3740);
    // 0x800C0A08: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800C0A0C: bne         $v0, $zero, L_800C0A18
    if (ctx->r2 != 0) {
        // 0x800C0A10: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800C0A18;
    }
    // 0x800C0A10: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C0A14: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_800C0A18:
    // 0x800C0A18: bne         $v0, $zero, L_800C0A44
    if (ctx->r2 != 0) {
        // 0x800C0A1C: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_800C0A44;
    }
    // 0x800C0A1C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C0A20: lhu         $t9, 0x3744($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X3744);
    // 0x800C0A24: nop

    // 0x800C0A28: bne         $t9, $zero, L_800C0A44
    if (ctx->r25 != 0) {
        // 0x800C0A2C: nop
    
            goto L_800C0A44;
    }
    // 0x800C0A2C: nop

    // 0x800C0A30: jal         0x800C0C44
    // 0x800C0A34: nop

    transition_end(rdram, ctx);
        goto after_0;
    // 0x800C0A34: nop

    after_0:
    // 0x800C0A38: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0A3C: b           L_800C0AD8
    // 0x800C0A40: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
        goto L_800C0AD8;
    // 0x800C0A40: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
L_800C0A44:
    // 0x800C0A44: blez        $v0, L_800C0A60
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C0A48: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800C0A60;
    }
    // 0x800C0A48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0A4C: addiu       $v0, $v0, 0x3760
    ctx->r2 = ADD32(ctx->r2, 0X3760);
    // 0x800C0A50: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800C0A54: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C0A58: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x800C0A5C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_800C0A60:
    // 0x800C0A60: lw          $t3, -0x5310($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5310);
    // 0x800C0A64: nop

    // 0x800C0A68: sltiu       $at, $t3, 0x7
    ctx->r1 = ctx->r11 < 0X7 ? 1 : 0;
    // 0x800C0A6C: beq         $at, $zero, L_800C0AD8
    if (ctx->r1 == 0) {
        // 0x800C0A70: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_800C0AD8;
    }
    // 0x800C0A70: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800C0A74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C0A78: addu        $at, $at, $t3
    gpr jr_addend_800C0A84 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C0A7C: lw          $t3, -0x6794($at)
    ctx->r11 = ADD32(ctx->r1, -0X6794);
    // 0x800C0A80: nop

    // 0x800C0A84: jr          $t3
    // 0x800C0A88: nop

    switch (jr_addend_800C0A84 >> 2) {
        case 0: goto L_800C0A8C; break;
        case 1: goto L_800C0AA0; break;
        case 2: goto L_800C0AA0; break;
        case 3: goto L_800C0AB4; break;
        case 4: goto L_800C0AA0; break;
        case 5: goto L_800C0AA0; break;
        case 6: goto L_800C0AC8; break;
        default: switch_error(__func__, 0x800C0A84, 0x800E986C);
    }
    // 0x800C0A88: nop

L_800C0A8C:
    // 0x800C0A8C: jal         0x800C0D54
    // 0x800C0A90: nop

    transition_update_fullscreen(rdram, ctx);
        goto after_1;
    // 0x800C0A90: nop

    after_1:
    // 0x800C0A94: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0A98: b           L_800C0AD8
    // 0x800C0A9C: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
        goto L_800C0AD8;
    // 0x800C0A9C: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
L_800C0AA0:
    // 0x800C0AA0: jal         0x800C1650
    // 0x800C0AA4: nop

    transition_update_shape(rdram, ctx);
        goto after_2;
    // 0x800C0AA4: nop

    after_2:
    // 0x800C0AA8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0AAC: b           L_800C0AD8
    // 0x800C0AB0: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
        goto L_800C0AD8;
    // 0x800C0AB0: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
L_800C0AB4:
    // 0x800C0AB4: jal         0x800C2408
    // 0x800C0AB8: nop

    transition_update_circle(rdram, ctx);
        goto after_3;
    // 0x800C0AB8: nop

    after_3:
    // 0x800C0ABC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0AC0: b           L_800C0AD8
    // 0x800C0AC4: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
        goto L_800C0AD8;
    // 0x800C0AC4: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
L_800C0AC8:
    // 0x800C0AC8: jal         0x800C2CC0
    // 0x800C0ACC: nop

    transition_update_blank(rdram, ctx);
        goto after_4;
    // 0x800C0ACC: nop

    after_4:
    // 0x800C0AD0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0AD4: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
L_800C0AD8:
    // 0x800C0AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0ADC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C0AE0: jr          $ra
    // 0x800C0AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C0AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void transition_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0AE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C0AEC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C0AF0: lw          $t6, 0x373C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X373C);
    // 0x800C0AF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C0AF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C0AFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C0B00: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C0B04: beq         $t6, $zero, L_800C0C30
    if (ctx->r14 == 0) {
        // 0x800C0B08: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800C0C30;
    }
    // 0x800C0B08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C0B0C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800C0B10: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800C0B14: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C0B18: bne         $t7, $zero, L_800C0B3C
    if (ctx->r15 != 0) {
        // 0x800C0B1C: nop
    
            goto L_800C0B3C;
    }
    // 0x800C0B1C: nop

    // 0x800C0B20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C0B24: lwc1        $f12, -0x6778($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6778);
    // 0x800C0B28: jal         0x80068160
    // 0x800C0B2C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    set_ortho_matrix_height(rdram, ctx);
        goto after_0;
    // 0x800C0B2C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C0B30: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C0B34: b           L_800C0B54
    // 0x800C0B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0B54;
    // 0x800C0B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0B3C:
    // 0x800C0B3C: lwc1        $f12, -0x6774($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6774);
    // 0x800C0B40: jal         0x80068160
    // 0x800C0B44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    set_ortho_matrix_height(rdram, ctx);
        goto after_1;
    // 0x800C0B44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x800C0B48: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C0B4C: nop

    // 0x800C0B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0B54:
    // 0x800C0B54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C0B58: jal         0x8006816C
    // 0x800C0B5C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    mtx_ortho(rdram, ctx);
        goto after_2;
    // 0x800C0B5C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    // 0x800C0B60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C0B64: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C0B68: jal         0x80068160
    // 0x800C0B6C: nop

    set_ortho_matrix_height(rdram, ctx);
        goto after_3;
    // 0x800C0B6C: nop

    after_3:
    // 0x800C0B70: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C0B74: lw          $t8, -0x5310($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5310);
    // 0x800C0B78: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C0B7C: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x800C0B80: beq         $at, $zero, L_800C0C24
    if (ctx->r1 == 0) {
        // 0x800C0B84: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800C0C24;
    }
    // 0x800C0B84: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800C0B88: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C0B8C: addu        $at, $at, $t8
    gpr jr_addend_800C0B98 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800C0B90: lw          $t8, -0x6770($at)
    ctx->r24 = ADD32(ctx->r1, -0X6770);
    // 0x800C0B94: nop

    // 0x800C0B98: jr          $t8
    // 0x800C0B9C: nop

    switch (jr_addend_800C0B98 >> 2) {
        case 0: goto L_800C0BA0; break;
        case 1: goto L_800C0BB4; break;
        case 2: goto L_800C0BC8; break;
        case 3: goto L_800C0BDC; break;
        case 4: goto L_800C0BF0; break;
        case 5: goto L_800C0C04; break;
        case 6: goto L_800C0C18; break;
        default: switch_error(__func__, 0x800C0B98, 0x800E9890);
    }
    // 0x800C0B9C: nop

L_800C0BA0:
    // 0x800C0BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0BA4: jal         0x800C0F28
    // 0x800C0BA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_fullscreen(rdram, ctx);
        goto after_4;
    // 0x800C0BA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800C0BAC: b           L_800C0C28
    // 0x800C0BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0C28;
    // 0x800C0BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0BB4:
    // 0x800C0BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0BB8: jal         0x800C1904
    // 0x800C0BBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_barndoor_hor(rdram, ctx);
        goto after_5;
    // 0x800C0BBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800C0BC0: b           L_800C0C28
    // 0x800C0BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0C28;
    // 0x800C0BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0BC8:
    // 0x800C0BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0BCC: jal         0x800C19FC
    // 0x800C0BD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_barndoor_vert(rdram, ctx);
        goto after_6;
    // 0x800C0BD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800C0BD4: b           L_800C0C28
    // 0x800C0BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0C28;
    // 0x800C0BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0BDC:
    // 0x800C0BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0BE0: jal         0x800C2794
    // 0x800C0BE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_circle(rdram, ctx);
        goto after_7;
    // 0x800C0BE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800C0BE8: b           L_800C0C28
    // 0x800C0BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0C28;
    // 0x800C0BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0BF0:
    // 0x800C0BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0BF4: jal         0x800C2918
    // 0x800C0BF8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_waves(rdram, ctx);
        goto after_8;
    // 0x800C0BF8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800C0BFC: b           L_800C0C28
    // 0x800C0C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0C28;
    // 0x800C0C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0C04:
    // 0x800C0C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0C08: jal         0x800C2A68
    // 0x800C0C0C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_barndoor_diag(rdram, ctx);
        goto after_9;
    // 0x800C0C0C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x800C0C10: b           L_800C0C28
    // 0x800C0C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0C28;
    // 0x800C0C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0C18:
    // 0x800C0C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0C1C: jal         0x800C2E08
    // 0x800C0C20: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_blank(rdram, ctx);
        goto after_10;
    // 0x800C0C20: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
L_800C0C24:
    // 0x800C0C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0C28:
    // 0x800C0C28: jal         0x80066F1C
    // 0x800C0C2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    viewport_main(rdram, ctx);
        goto after_11;
    // 0x800C0C2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
L_800C0C30:
    // 0x800C0C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0C34: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C0C38: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C0C3C: jr          $ra
    // 0x800C0C40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C0C40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void transition_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0C44: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0C48: addiu       $v0, $v0, 0x3750
    ctx->r2 = ADD32(ctx->r2, 0X3750);
    // 0x800C0C4C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800C0C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0C54: beq         $a0, $zero, L_800C0C84
    if (ctx->r4 == 0) {
        // 0x800C0C58: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C0C84;
    }
    // 0x800C0C58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0C5C: jal         0x80071380
    // 0x800C0C60: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800C0C60: nop

    after_0:
    // 0x800C0C64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0C68: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0C6C: addiu       $v1, $v1, 0x3758
    ctx->r3 = ADD32(ctx->r3, 0X3758);
    // 0x800C0C70: addiu       $v0, $v0, 0x3750
    ctx->r2 = ADD32(ctx->r2, 0X3750);
    // 0x800C0C74: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C0C78: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C0C7C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800C0C80: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_800C0C84:
    // 0x800C0C84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0C8C: sw          $zero, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = 0;
    // 0x800C0C90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0C94: sw          $zero, 0x3760($at)
    MEM_W(0X3760, ctx->r1) = 0;
    // 0x800C0C98: jr          $ra
    // 0x800C0C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C0C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void transition_fullscreen_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0CA0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0CA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0CA8: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x800C0CAC: beq         $t7, $zero, L_800C0D04
    if (ctx->r15 == 0) {
        // 0x800C0CB0: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800C0D04;
    }
    // 0x800C0CB0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C0CB4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C0CB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C0CBC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C0CC0: lhu         $t8, 0x3740($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X3740);
    // 0x800C0CC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0CC8: swc1        $f4, -0x52F0($at)
    MEM_W(-0X52F0, ctx->r1) = ctx->f4.u32l;
    // 0x800C0CCC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800C0CD0: lui         $at, 0xC37F
    ctx->r1 = S32(0XC37F << 16);
    // 0x800C0CD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C0CD8: bgez        $t8, L_800C0CF0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C0CDC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C0CF0;
    }
    // 0x800C0CDC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C0CE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0CE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C0CE8: nop

    // 0x800C0CEC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800C0CF0:
    // 0x800C0CF0: nop

    // 0x800C0CF4: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C0CF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0CFC: b           L_800C0D48
    // 0x800C0D00: swc1        $f18, -0x52EC($at)
    MEM_W(-0X52EC, ctx->r1) = ctx->f18.u32l;
        goto L_800C0D48;
    // 0x800C0D00: swc1        $f18, -0x52EC($at)
    MEM_W(-0X52EC, ctx->r1) = ctx->f18.u32l;
L_800C0D04:
    // 0x800C0D04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C0D08: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C0D0C: lhu         $t9, 0x3740($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X3740);
    // 0x800C0D10: swc1        $f4, -0x52F0($at)
    MEM_W(-0X52F0, ctx->r1) = ctx->f4.u32l;
    // 0x800C0D14: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800C0D18: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C0D1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C0D20: bgez        $t9, L_800C0D38
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800C0D24: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800C0D38;
    }
    // 0x800C0D24: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C0D28: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0D2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C0D30: nop

    // 0x800C0D34: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800C0D38:
    // 0x800C0D38: nop

    // 0x800C0D3C: div.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800C0D40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0D44: swc1        $f18, -0x52EC($at)
    MEM_W(-0X52EC, ctx->r1) = ctx->f18.u32l;
L_800C0D48:
    // 0x800C0D48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0D4C: jr          $ra
    // 0x800C0D50: sw          $t0, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = ctx->r8;
    return;
    // 0x800C0D50: sw          $t0, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void transition_update_fullscreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0D54: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C0D58: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800C0D5C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800C0D60: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C0D64: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C0D68: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C0D6C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C0D70: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C0D74: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C0D78: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C0D7C: addiu       $a1, $a1, 0x3740
    ctx->r5 = ADD32(ctx->r5, 0X3740);
    // 0x800C0D80: addiu       $a2, $a2, -0x52F0
    ctx->r6 = ADD32(ctx->r6, -0X52F0);
    // 0x800C0D84: addiu       $a3, $a3, -0x5309
    ctx->r7 = ADD32(ctx->r7, -0X5309);
    // 0x800C0D88: addiu       $t1, $t1, 0x3744
    ctx->r9 = ADD32(ctx->r9, 0X3744);
    // 0x800C0D8C: addiu       $t2, $t2, 0x3738
    ctx->r10 = ADD32(ctx->r10, 0X3738);
    // 0x800C0D90: addiu       $t3, $t3, 0x3748
    ctx->r11 = ADD32(ctx->r11, 0X3748);
    // 0x800C0D94: addiu       $t4, $t4, -0x52EC
    ctx->r12 = ADD32(ctx->r12, -0X52EC);
    // 0x800C0D98: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
L_800C0D9C:
    // 0x800C0D9C: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800C0DA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C0DA4: blez        $v1, L_800C0EC4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C0DA8: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800C0EC4;
    }
    // 0x800C0DA8: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C0DAC: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C0DB0: beq         $at, $zero, L_800C0DDC
    if (ctx->r1 == 0) {
        // 0x800C0DB4: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800C0DDC;
    }
    // 0x800C0DB4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C0DB8: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800C0DBC: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C0DC0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C0DC4: subu        $t6, $v1, $a0
    ctx->r14 = SUB32(ctx->r3, ctx->r4);
    // 0x800C0DC8: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800C0DCC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C0DD0: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800C0DD4: b           L_800C0DFC
    // 0x800C0DD8: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
        goto L_800C0DFC;
    // 0x800C0DD8: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
L_800C0DDC:
    // 0x800C0DDC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C0DE0: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800C0DE4: bc1f        L_800C0DF4
    if (!c1cs) {
        // 0x800C0DE8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C0DF4;
    }
    // 0x800C0DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0DEC: b           L_800C0DF8
    // 0x800C0DF0: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
        goto L_800C0DF8;
    // 0x800C0DF0: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
L_800C0DF4:
    // 0x800C0DF4: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
L_800C0DF8:
    // 0x800C0DF8: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_800C0DFC:
    // 0x800C0DFC: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C0E00: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800C0E04: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C0E08: nop

    // 0x800C0E0C: bc1f        L_800C0E24
    if (!c1cs) {
        // 0x800C0E10: nop
    
            goto L_800C0E24;
    }
    // 0x800C0E10: nop

    // 0x800C0E14: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x800C0E18: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C0E1C: b           L_800C0E44
    // 0x800C0E20: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
        goto L_800C0E44;
    // 0x800C0E20: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
L_800C0E24:
    // 0x800C0E24: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800C0E28: nop

    // 0x800C0E2C: bc1f        L_800C0E40
    if (!c1cs) {
        // 0x800C0E30: nop
    
            goto L_800C0E40;
    }
    // 0x800C0E30: nop

    // 0x800C0E34: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
    // 0x800C0E38: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C0E3C: nop

L_800C0E40:
    // 0x800C0E40: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
L_800C0E44:
    // 0x800C0E44: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C0E48: nop

    // 0x800C0E4C: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800C0E50: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C0E54: nop

    // 0x800C0E58: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800C0E5C: beq         $t8, $zero, L_800C0EA8
    if (ctx->r24 == 0) {
        // 0x800C0E60: nop
    
            goto L_800C0EA8;
    }
    // 0x800C0E60: nop

    // 0x800C0E64: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C0E68: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C0E6C: sub.s       $f18, $f0, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800C0E70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C0E74: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C0E78: nop

    // 0x800C0E7C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800C0E80: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C0E84: nop

    // 0x800C0E88: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800C0E8C: bne         $t8, $zero, L_800C0EA0
    if (ctx->r24 != 0) {
        // 0x800C0E90: nop
    
            goto L_800C0EA0;
    }
    // 0x800C0E90: nop

    // 0x800C0E94: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800C0E98: b           L_800C0EB8
    // 0x800C0E9C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800C0EB8;
    // 0x800C0E9C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800C0EA0:
    // 0x800C0EA0: b           L_800C0EB8
    // 0x800C0EA4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800C0EB8;
    // 0x800C0EA4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800C0EA8:
    // 0x800C0EA8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800C0EAC: nop

    // 0x800C0EB0: bltz        $t8, L_800C0EA0
    if (SIGNED(ctx->r24) < 0) {
        // 0x800C0EB4: nop
    
            goto L_800C0EA0;
    }
    // 0x800C0EB4: nop

L_800C0EB8:
    // 0x800C0EB8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C0EBC: b           L_800C0F10
    // 0x800C0EC0: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
        goto L_800C0F10;
    // 0x800C0EC0: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
L_800C0EC4:
    // 0x800C0EC4: lhu         $v1, 0x0($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X0);
    // 0x800C0EC8: nop

    // 0x800C0ECC: beq         $t0, $v1, L_800C0F10
    if (ctx->r8 == ctx->r3) {
        // 0x800C0ED0: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800C0F10;
    }
    // 0x800C0ED0: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C0ED4: beq         $at, $zero, L_800C0EE4
    if (ctx->r1 == 0) {
        // 0x800C0ED8: subu        $t9, $v1, $a0
        ctx->r25 = SUB32(ctx->r3, ctx->r4);
            goto L_800C0EE4;
    }
    // 0x800C0ED8: subu        $t9, $v1, $a0
    ctx->r25 = SUB32(ctx->r3, ctx->r4);
    // 0x800C0EDC: b           L_800C0F10
    // 0x800C0EE0: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
        goto L_800C0F10;
    // 0x800C0EE0: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
L_800C0EE4:
    // 0x800C0EE4: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800C0EE8: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800C0EEC: beq         $t5, $zero, L_800C0F10
    if (ctx->r13 == 0) {
        // 0x800C0EF0: sh          $zero, 0x0($t1)
        MEM_H(0X0, ctx->r9) = 0;
            goto L_800C0F10;
    }
    // 0x800C0EF0: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x800C0EF4: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C0EF8: lhu         $t6, 0x0($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X0);
    // 0x800C0EFC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800C0F00: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x800C0F04: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x800C0F08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0F0C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
L_800C0F10:
    // 0x800C0F10: bne         $v0, $zero, L_800C0F20
    if (ctx->r2 != 0) {
        // 0x800C0F14: nop
    
            goto L_800C0F20;
    }
    // 0x800C0F14: nop

    // 0x800C0F18: bgtz        $a0, L_800C0D9C
    if (SIGNED(ctx->r4) > 0) {
        // 0x800C0F1C: nop
    
            goto L_800C0D9C;
    }
    // 0x800C0F1C: nop

L_800C0F20:
    // 0x800C0F20: jr          $ra
    // 0x800C0F24: nop

    return;
    // 0x800C0F24: nop

;}
RECOMP_FUNC void transition_render_fullscreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0F30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C0F34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C0F38: jal         0x8007A970
    // 0x800C0F3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800C0F3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C0F40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C0F44: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C0F48: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0F4C: addiu       $t8, $t8, 0x3768
    ctx->r24 = ADD32(ctx->r24, 0X3768);
    // 0x800C0F50: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C0F54: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C0F58: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C0F5C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C0F60: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C0F64: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0F68: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800C0F6C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C0F70: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C0F74: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800C0F78: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800C0F7C: lbu         $t6, -0x530B($t5)
    ctx->r14 = MEM_BU(ctx->r13, -0X530B);
    // 0x800C0F80: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C0F84: lbu         $t3, -0x530C($t2)
    ctx->r11 = MEM_BU(ctx->r10, -0X530C);
    // 0x800C0F88: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C0F8C: lbu         $t1, -0x530A($t9)
    ctx->r9 = MEM_BU(ctx->r25, -0X530A);
    // 0x800C0F90: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800C0F94: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800C0F98: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x800C0F9C: lbu         $t6, -0x5309($t5)
    ctx->r14 = MEM_BU(ctx->r13, -0X5309);
    // 0x800C0FA0: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800C0FA4: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800C0FA8: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x800C0FAC: or          $t4, $t3, $t6
    ctx->r12 = ctx->r11 | ctx->r14;
    // 0x800C0FB0: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800C0FB4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0FB8: lui         $t1, 0xFFFD
    ctx->r9 = S32(0XFFFD << 16);
    // 0x800C0FBC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C0FC0: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800C0FC4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800C0FC8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800C0FCC: ori         $t1, $t1, 0xF6FB
    ctx->r9 = ctx->r9 | 0XF6FB;
    // 0x800C0FD0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800C0FD4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C0FD8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0FDC: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C0FE0: andi        $t5, $v0, 0x3FF
    ctx->r13 = ctx->r2 & 0X3FF;
    // 0x800C0FE4: sll         $t3, $t5, 14
    ctx->r11 = S32(ctx->r13 << 14);
    // 0x800C0FE8: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x800C0FEC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800C0FF0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C0FF4: or          $t6, $t3, $at
    ctx->r14 = ctx->r11 | ctx->r1;
    // 0x800C0FF8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800C0FFC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800C1000: or          $t8, $t6, $t1
    ctx->r24 = ctx->r14 | ctx->r9;
    // 0x800C1004: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C1008: jal         0x8007B820
    // 0x800C100C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C100C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    after_1:
    // 0x800C1010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1018: jr          $ra
    // 0x800C101C: nop

    return;
    // 0x800C101C: nop

;}
RECOMP_FUNC void transition_init_shape(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1020: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C1024: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800C1028: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x800C102C: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x800C1030: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800C1034: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C1038: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800C103C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C1040: sll         $t0, $a2, 4
    ctx->r8 = S32(ctx->r6 << 4);
    // 0x800C1044: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C1048: addu        $t6, $v1, $t0
    ctx->r14 = ADD32(ctx->r3, ctx->r8);
    // 0x800C104C: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x800C1050: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C1054: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C1058: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C105C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800C1060: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x800C1064: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800C1068: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x800C106C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800C1070: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800C1074: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C1078: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800C107C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800C1080: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800C1084: jal         0x80070EDC
    // 0x800C1088: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C1088: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x800C108C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800C1090: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C1094: addiu       $a0, $a0, 0x3750
    ctx->r4 = ADD32(ctx->r4, 0X3750);
    // 0x800C1098: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C109C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C10A0: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x800C10A4: sw          $t4, 0x3754($at)
    MEM_W(0X3754, ctx->r1) = ctx->r12;
    // 0x800C10A8: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x800C10AC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C10B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C10B4: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x800C10B8: addiu       $a1, $a1, 0x3758
    ctx->r5 = ADD32(ctx->r5, 0X3758);
    // 0x800C10BC: sw          $t6, 0x3758($at)
    MEM_W(0X3758, ctx->r1) = ctx->r14;
    // 0x800C10C0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C10C4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800C10C8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C10CC: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x800C10D0: sw          $t8, 0x375C($at)
    MEM_W(0X375C, ctx->r1) = ctx->r24;
    // 0x800C10D4: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800C10D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C10DC: addu        $t4, $t9, $t0
    ctx->r12 = ADD32(ctx->r25, ctx->r8);
    // 0x800C10E0: addiu       $a2, $a2, -0x52D0
    ctx->r6 = ADD32(ctx->r6, -0X52D0);
    // 0x800C10E4: sw          $t4, -0x52D0($at)
    MEM_W(-0X52D0, ctx->r1) = ctx->r12;
    // 0x800C10E8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C10EC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C10F0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C10F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C10F8: addu        $t6, $t5, $t1
    ctx->r14 = ADD32(ctx->r13, ctx->r9);
    // 0x800C10FC: addiu       $t3, $t3, -0x52CC
    ctx->r11 = ADD32(ctx->r11, -0X52CC);
    // 0x800C1100: sw          $t6, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r14;
    // 0x800C1104: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800C1108: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800C110C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1110: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x800C1114: sw          $t8, -0x52C8($at)
    MEM_W(-0X52C8, ctx->r1) = ctx->r24;
    // 0x800C1118: lbu         $t4, 0x0($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X0);
    // 0x800C111C: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800C1120: andi        $t5, $t4, 0x80
    ctx->r13 = ctx->r12 & 0X80;
    // 0x800C1124: beq         $t5, $zero, L_800C1148
    if (ctx->r13 == 0) {
        // 0x800C1128: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_800C1148;
    }
    // 0x800C1128: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C112C: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800C1130: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800C1134: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800C1138: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800C113C: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x800C1140: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x800C1144: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
L_800C1148:
    // 0x800C1148: blez        $s0, L_800C137C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800C114C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800C137C;
    }
    // 0x800C114C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800C1150: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C1154: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800C1158: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800C115C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800C1160: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800C1164: addiu       $v1, $v1, -0x52C8
    ctx->r3 = ADD32(ctx->r3, -0X52C8);
    // 0x800C1168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C116C: addiu       $t1, $t1, 0x3740
    ctx->r9 = ADD32(ctx->r9, 0X3740);
L_800C1170:
    // 0x800C1170: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1174: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C1178: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C117C: addu        $t4, $s2, $t9
    ctx->r12 = ADD32(ctx->r18, ctx->r25);
    // 0x800C1180: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800C1184: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1188: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C118C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C1190: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C1194: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x800C1198: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800C119C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C11A0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C11A4: addu        $t4, $s2, $t9
    ctx->r12 = ADD32(ctx->r18, ctx->r25);
    // 0x800C11A8: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x800C11AC: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C11B0: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800C11B4: nop

    // 0x800C11B8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C11BC: swc1        $f10, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f10.u32l;
    // 0x800C11C0: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x800C11C4: nop

    // 0x800C11C8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800C11CC: bgez        $t8, L_800C11E0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C11D0: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800C11E0;
    }
    // 0x800C11D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C11D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C11D8: nop

    // 0x800C11DC: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800C11E0:
    // 0x800C11E0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C11E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C11E8: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C11EC: swc1        $f18, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f18.u32l;
    // 0x800C11F0: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x800C11F4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C11F8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800C11FC: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x800C1200: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800C1204: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1208: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800C120C: nop

    // 0x800C1210: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C1214: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x800C1218: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x800C121C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1220: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800C1224: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x800C1228: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800C122C: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1230: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800C1234: nop

    // 0x800C1238: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C123C: swc1        $f16, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f16.u32l;
    // 0x800C1240: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800C1244: nop

    // 0x800C1248: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C124C: bgez        $t5, L_800C1260
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800C1250: cvt.s.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C1260;
    }
    // 0x800C1250: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C1254: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C1258: nop

    // 0x800C125C: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_800C1260:
    // 0x800C1260: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1264: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C1268: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C126C: swc1        $f18, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f18.u32l;
    // 0x800C1270: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C1274: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C1278: lhu         $t6, 0x0($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X0);
    // 0x800C127C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1280: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C1284: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800C1288: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800C128C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800C1290: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800C1294: bgez        $t6, L_800C12A8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800C1298: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C12A8;
    }
    // 0x800C1298: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C129C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C12A0: nop

    // 0x800C12A4: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
L_800C12A8:
    // 0x800C12A8: nop

    // 0x800C12AC: div.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800C12B0: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800C12B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C12B8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C12BC: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x800C12C0: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C12C4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C12C8: lhu         $t7, 0x0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X0);
    // 0x800C12CC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C12D0: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C12D4: lwc1        $f10, 0x4($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C12D8: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800C12DC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800C12E0: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800C12E4: bgez        $t7, L_800C12F8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C12E8: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800C12F8;
    }
    // 0x800C12E8: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C12EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C12F0: nop

    // 0x800C12F4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800C12F8:
    // 0x800C12F8: nop

    // 0x800C12FC: div.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800C1300: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800C1304: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C1308: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C130C: swc1        $f10, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f10.u32l;
    // 0x800C1310: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C1314: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1318: lhu         $t8, 0x0($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X0);
    // 0x800C131C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1320: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1324: lwc1        $f4, 0x8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8);
    // 0x800C1328: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800C132C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800C1330: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800C1334: bgez        $t8, L_800C1348
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C1338: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800C1348;
    }
    // 0x800C1338: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C133C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C1340: nop

    // 0x800C1344: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800C1348:
    // 0x800C1348: nop

    // 0x800C134C: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800C1350: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x800C1354: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C1358: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C135C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C1360: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C1364: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C1368: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C136C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C1370: bne         $t2, $s0, L_800C1170
    if (ctx->r10 != ctx->r16) {
        // 0x800C1374: swc1        $f4, 0x8($t4)
        MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
            goto L_800C1170;
    }
    // 0x800C1374: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
    // 0x800C1378: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_800C137C:
    // 0x800C137C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C1380: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C1384: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C1388: addiu       $a2, $a2, -0x530C
    ctx->r6 = ADD32(ctx->r6, -0X530C);
    // 0x800C138C: addiu       $a3, $a3, -0x530B
    ctx->r7 = ADD32(ctx->r7, -0X530B);
    // 0x800C1390: addiu       $t0, $t0, -0x530A
    ctx->r8 = ADD32(ctx->r8, -0X530A);
    // 0x800C1394: addiu       $a0, $zero, -0x10
    ctx->r4 = ADD32(0, -0X10);
L_800C1398:
    // 0x800C1398: blez        $s0, L_800C1530
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800C139C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800C1530;
    }
    // 0x800C139C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C13A0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C13A4: addiu       $t6, $t6, 0x3750
    ctx->r14 = ADD32(ctx->r14, 0X3750);
    // 0x800C13A8: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x800C13AC: andi        $t3, $s0, 0x3
    ctx->r11 = ctx->r16 & 0X3;
    // 0x800C13B0: beq         $t3, $zero, L_800C1410
    if (ctx->r11 == 0) {
        // 0x800C13B4: addu        $v1, $t5, $t6
        ctx->r3 = ADD32(ctx->r13, ctx->r14);
            goto L_800C1410;
    }
    // 0x800C13B4: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x800C13B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C13BC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C13C0: or          $t1, $t3, $zero
    ctx->r9 = ctx->r11 | 0;
L_800C13C4:
    // 0x800C13C4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C13C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C13CC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C13D0: sh          $a0, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r4;
    // 0x800C13D4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C13D8: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800C13DC: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C13E0: sb          $t9, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r25;
    // 0x800C13E4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C13E8: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x800C13EC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C13F0: sb          $t6, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r14;
    // 0x800C13F4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C13F8: lbu         $t4, 0x0($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X0);
    // 0x800C13FC: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1400: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800C1404: bne         $t1, $a1, L_800C13C4
    if (ctx->r9 != ctx->r5) {
        // 0x800C1408: sb          $t4, 0x8($t5)
        MEM_B(0X8, ctx->r13) = ctx->r12;
            goto L_800C13C4;
    }
    // 0x800C1408: sb          $t4, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r12;
    // 0x800C140C: beq         $a1, $s0, L_800C1530
    if (ctx->r5 == ctx->r16) {
        // 0x800C1410: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_800C1530;
    }
L_800C1410:
    // 0x800C1410: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800C1414: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800C1418: addu        $t1, $t1, $s0
    ctx->r9 = ADD32(ctx->r9, ctx->r16);
    // 0x800C141C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C1420: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C1424: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
L_800C1428:
    // 0x800C1428: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C142C: nop

    // 0x800C1430: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1434: sh          $a0, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r4;
    // 0x800C1438: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C143C: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1440: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1444: sb          $t8, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r24;
    // 0x800C1448: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C144C: lbu         $t5, 0x0($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X0);
    // 0x800C1450: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1454: sb          $t5, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r13;
    // 0x800C1458: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C145C: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x800C1460: addu        $t4, $t8, $v0
    ctx->r12 = ADD32(ctx->r24, ctx->r2);
    // 0x800C1464: sb          $t9, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r25;
    // 0x800C1468: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C146C: nop

    // 0x800C1470: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1474: sh          $a0, 0xE($t5)
    MEM_H(0XE, ctx->r13) = ctx->r4;
    // 0x800C1478: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C147C: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1480: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C1484: sb          $t6, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r14;
    // 0x800C1488: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C148C: lbu         $t4, 0x0($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X0);
    // 0x800C1490: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1494: sb          $t4, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r12;
    // 0x800C1498: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C149C: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x800C14A0: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x800C14A4: sb          $t8, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r24;
    // 0x800C14A8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C14AC: nop

    // 0x800C14B0: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800C14B4: sh          $a0, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r4;
    // 0x800C14B8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C14BC: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x800C14C0: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800C14C4: sb          $t5, 0x1A($t8)
    MEM_B(0X1A, ctx->r24) = ctx->r13;
    // 0x800C14C8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C14CC: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x800C14D0: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800C14D4: sb          $t9, 0x1B($t4)
    MEM_B(0X1B, ctx->r12) = ctx->r25;
    // 0x800C14D8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C14DC: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x800C14E0: addu        $t8, $t5, $v0
    ctx->r24 = ADD32(ctx->r13, ctx->r2);
    // 0x800C14E4: sb          $t6, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r14;
    // 0x800C14E8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C14EC: nop

    // 0x800C14F0: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C14F4: sh          $a0, 0x22($t9)
    MEM_H(0X22, ctx->r25) = ctx->r4;
    // 0x800C14F8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C14FC: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1500: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C1504: sb          $t4, 0x24($t6)
    MEM_B(0X24, ctx->r14) = ctx->r12;
    // 0x800C1508: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C150C: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x800C1510: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1514: sb          $t8, 0x25($t9)
    MEM_B(0X25, ctx->r25) = ctx->r24;
    // 0x800C1518: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C151C: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800C1520: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1524: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800C1528: bne         $v0, $t1, L_800C1428
    if (ctx->r2 != ctx->r9) {
        // 0x800C152C: sb          $t5, 0x26($t6)
        MEM_B(0X26, ctx->r14) = ctx->r13;
            goto L_800C1428;
    }
    // 0x800C152C: sb          $t5, 0x26($t6)
    MEM_B(0X26, ctx->r14) = ctx->r13;
L_800C1530:
    // 0x800C1530: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C1534: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800C1538: bne         $at, $zero, L_800C1398
    if (ctx->r1 != 0) {
        // 0x800C153C: nop
    
            goto L_800C1398;
    }
    // 0x800C153C: nop

    // 0x800C1540: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800C1544: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800C1548: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800C154C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
L_800C1550:
    // 0x800C1550: blez        $s1, L_800C1618
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800C1554: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800C1618;
    }
    // 0x800C1554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C1558: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C155C: addiu       $t8, $t8, 0x3758
    ctx->r24 = ADD32(ctx->r24, 0X3758);
    // 0x800C1560: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800C1564: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800C1568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C156C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_800C1570:
    // 0x800C1570: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1574: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C1578: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C157C: sb          $a2, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r6;
    // 0x800C1580: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1584: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1588: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C158C: sb          $t5, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r13;
    // 0x800C1590: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C1594: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800C1598: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C159C: sh          $zero, 0x4($t9)
    MEM_H(0X4, ctx->r25) = 0;
    // 0x800C15A0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C15A4: nop

    // 0x800C15A8: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C15AC: sh          $zero, 0x6($t6)
    MEM_H(0X6, ctx->r14) = 0;
    // 0x800C15B0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C15B4: lbu         $t5, -0x2($a0)
    ctx->r13 = MEM_BU(ctx->r4, -0X2);
    // 0x800C15B8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C15BC: sb          $t5, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r13;
    // 0x800C15C0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C15C4: nop

    // 0x800C15C8: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C15CC: sh          $zero, 0x8($t4)
    MEM_H(0X8, ctx->r12) = 0;
    // 0x800C15D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C15D4: nop

    // 0x800C15D8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C15DC: sh          $zero, 0xA($t7)
    MEM_H(0XA, ctx->r15) = 0;
    // 0x800C15E0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C15E4: lbu         $t5, -0x1($a0)
    ctx->r13 = MEM_BU(ctx->r4, -0X1);
    // 0x800C15E8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C15EC: sb          $t5, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r13;
    // 0x800C15F0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C15F4: nop

    // 0x800C15F8: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C15FC: sh          $zero, 0xC($t6)
    MEM_H(0XC, ctx->r14) = 0;
    // 0x800C1600: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1604: nop

    // 0x800C1608: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C160C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C1610: bne         $a1, $s1, L_800C1570
    if (ctx->r5 != ctx->r17) {
        // 0x800C1614: sh          $zero, 0xE($t8)
        MEM_H(0XE, ctx->r24) = 0;
            goto L_800C1570;
    }
    // 0x800C1614: sh          $zero, 0xE($t8)
    MEM_H(0XE, ctx->r24) = 0;
L_800C1618:
    // 0x800C1618: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C161C: bne         $t2, $t0, L_800C1550
    if (ctx->r10 != ctx->r8) {
        // 0x800C1620: nop
    
            goto L_800C1550;
    }
    // 0x800C1620: nop

    // 0x800C1624: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800C1628: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C162C: sw          $t5, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = ctx->r13;
    // 0x800C1630: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C1638: sw          $s0, -0x52C4($at)
    MEM_W(-0X52C4, ctx->r1) = ctx->r16;
    // 0x800C163C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C1640: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1644: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C1648: jr          $ra
    // 0x800C164C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C164C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void transition_update_shape(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1650: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C1654: addiu       $a3, $a3, 0x3740
    ctx->r7 = ADD32(ctx->r7, 0X3740);
    // 0x800C1658: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800C165C: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x800C1660: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C1664: blez        $v0, L_800C18D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C1668: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C18D4;
    }
    // 0x800C1668: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C166C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C1670: beq         $at, $zero, L_800C1744
    if (ctx->r1 == 0) {
        // 0x800C1674: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_800C1744;
    }
    // 0x800C1674: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C1678: addiu       $t0, $t0, -0x52C4
    ctx->r8 = ADD32(ctx->r8, -0X52C4);
    // 0x800C167C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C1680: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C1684: blez        $a1, L_800C1730
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C1688: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_800C1730;
    }
    // 0x800C1688: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C168C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C1690: addiu       $t1, $t1, -0x52D0
    ctx->r9 = ADD32(ctx->r9, -0X52D0);
    // 0x800C1694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1698: addiu       $t2, $t2, -0x52CC
    ctx->r10 = ADD32(ctx->r10, -0X52CC);
L_800C169C:
    // 0x800C169C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800C16A0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800C16A4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C16A8: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C16AC: addu        $a2, $t6, $v0
    ctx->r6 = ADD32(ctx->r14, ctx->r2);
    // 0x800C16B0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C16B4: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C16B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C16BC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C16C0: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x800C16C4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800C16C8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800C16CC: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C16D0: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C16D4: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    // 0x800C16D8: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C16DC: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800C16E0: nop

    // 0x800C16E4: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800C16E8: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x800C16EC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800C16F0: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800C16F4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C16F8: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800C16FC: addu        $a2, $t5, $v0
    ctx->r6 = ADD32(ctx->r13, ctx->r2);
    // 0x800C1700: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800C1704: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800C1708: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C170C: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800C1710: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
    // 0x800C1714: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C1718: nop

    // 0x800C171C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C1720: bne         $at, $zero, L_800C169C
    if (ctx->r1 != 0) {
        // 0x800C1724: nop
    
            goto L_800C169C;
    }
    // 0x800C1724: nop

    // 0x800C1728: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x800C172C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C1730:
    // 0x800C1730: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C1734: subu        $t8, $v0, $a0
    ctx->r24 = SUB32(ctx->r2, ctx->r4);
    // 0x800C1738: addiu       $t1, $t1, -0x52D0
    ctx->r9 = ADD32(ctx->r9, -0X52D0);
    // 0x800C173C: b           L_800C17D8
    // 0x800C1740: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_800C17D8;
    // 0x800C1740: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_800C1744:
    // 0x800C1744: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C1748: addiu       $t0, $t0, -0x52C4
    ctx->r8 = ADD32(ctx->r8, -0X52C4);
    // 0x800C174C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C1750: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C1754: blez        $a1, L_800C17CC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C1758: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_800C17CC;
    }
    // 0x800C1758: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C175C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C1760: addiu       $a0, $a0, -0x52C8
    ctx->r4 = ADD32(ctx->r4, -0X52C8);
    // 0x800C1764: addiu       $t1, $t1, -0x52D0
    ctx->r9 = ADD32(ctx->r9, -0X52D0);
    // 0x800C1768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C176C:
    // 0x800C176C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800C1770: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800C1774: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1778: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800C177C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1780: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x800C1784: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C1788: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800C178C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1790: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800C1794: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C1798: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x800C179C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800C17A0: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800C17A4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C17A8: lwc1        $f16, 0x8($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800C17AC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C17B0: swc1        $f16, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f16.u32l;
    // 0x800C17B4: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C17B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C17BC: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C17C0: bne         $at, $zero, L_800C176C
    if (ctx->r1 != 0) {
        // 0x800C17C4: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800C176C;
    }
    // 0x800C17C4: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C17C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C17CC:
    // 0x800C17CC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C17D0: addiu       $t1, $t1, -0x52D0
    ctx->r9 = ADD32(ctx->r9, -0X52D0);
    // 0x800C17D4: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
L_800C17D8:
    // 0x800C17D8: blez        $a1, L_800C18FC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C17DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C18FC;
    }
    // 0x800C17DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C17E0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C17E4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C17E8: addiu       $a1, $a1, 0x3750
    ctx->r5 = ADD32(ctx->r5, 0X3750);
    // 0x800C17EC: addiu       $a2, $a2, 0x3760
    ctx->r6 = ADD32(ctx->r6, 0X3760);
    // 0x800C17F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800C17F4:
    // 0x800C17F4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C17F8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800C17FC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800C1800: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1804: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1808: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C180C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C1810: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C1814: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C1818: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C181C: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x800C1820: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C1824: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C1828: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800C182C: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800C1830: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800C1834: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x800C1838: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800C183C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800C1840: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1844: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1848: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C184C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C1850: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C1854: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800C1858: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x800C185C: addu        $t8, $a1, $t3
    ctx->r24 = ADD32(ctx->r5, ctx->r11);
    // 0x800C1860: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800C1864: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800C1868: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800C186C: addu        $t4, $t9, $a0
    ctx->r12 = ADD32(ctx->r25, ctx->r4);
    // 0x800C1870: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800C1874: sh          $t6, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r14;
    // 0x800C1878: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800C187C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800C1880: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C1884: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1888: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800C188C: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800C1890: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C1894: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800C1898: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C189C: addu        $t4, $a1, $t6
    ctx->r12 = ADD32(ctx->r5, ctx->r14);
    // 0x800C18A0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C18A4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800C18A8: addu        $t7, $t5, $a0
    ctx->r15 = ADD32(ctx->r13, ctx->r4);
    // 0x800C18AC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800C18B0: sb          $t8, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r24;
    // 0x800C18B4: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800C18B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C18BC: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800C18C0: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800C18C4: bne         $at, $zero, L_800C17F4
    if (ctx->r1 != 0) {
        // 0x800C18C8: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800C17F4;
    }
    // 0x800C18C8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C18CC: jr          $ra
    // 0x800C18D0: nop

    return;
    // 0x800C18D0: nop

L_800C18D4:
    // 0x800C18D4: addiu       $v1, $v1, 0x3744
    ctx->r3 = ADD32(ctx->r3, 0X3744);
    // 0x800C18D8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800C18DC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800C18E0: beq         $v0, $at, L_800C18FC
    if (ctx->r2 == ctx->r1) {
        // 0x800C18E4: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800C18FC;
    }
    // 0x800C18E4: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C18E8: beq         $at, $zero, L_800C18F8
    if (ctx->r1 == 0) {
        // 0x800C18EC: subu        $t9, $v0, $a0
        ctx->r25 = SUB32(ctx->r2, ctx->r4);
            goto L_800C18F8;
    }
    // 0x800C18EC: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x800C18F0: jr          $ra
    // 0x800C18F4: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x800C18F4: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
L_800C18F8:
    // 0x800C18F8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_800C18FC:
    // 0x800C18FC: jr          $ra
    // 0x800C1900: nop

    return;
    // 0x800C1900: nop

;}
RECOMP_FUNC void transition_render_barndoor_hor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C190C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C1910: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C1914: jal         0x8007B820
    // 0x800C1918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C1918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C191C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C1920: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C1924: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1928: addiu       $t8, $t8, 0x3BD8
    ctx->r24 = ADD32(ctx->r24, 0X3BD8);
    // 0x800C192C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C1930: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C1934: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C1938: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C193C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C1940: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1944: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C1948: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C194C: addiu       $a3, $a3, 0x3760
    ctx->r7 = ADD32(ctx->r7, 0X3760);
    // 0x800C1950: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C1954: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800C1958: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C195C: addiu       $t1, $t1, 0x3750
    ctx->r9 = ADD32(ctx->r9, 0X3750);
    // 0x800C1960: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C1964: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C1968: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C196C: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800C1970: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x800C1974: andi        $t7, $t6, 0x6
    ctx->r15 = ctx->r14 & 0X6;
    // 0x800C1978: ori         $t8, $t7, 0x58
    ctx->r24 = ctx->r15 | 0X58;
    // 0x800C197C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800C1980: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800C1984: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800C1988: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800C198C: ori         $t4, $t3, 0xE0
    ctx->r12 = ctx->r11 | 0XE0;
    // 0x800C1990: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C1994: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800C1998: lui         $t3, 0x570
    ctx->r11 = S32(0X570 << 16);
    // 0x800C199C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C19A0: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800C19A4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C19A8: ori         $t3, $t3, 0x80
    ctx->r11 = ctx->r11 | 0X80;
    // 0x800C19AC: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800C19B0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C19B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C19B8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C19BC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800C19C0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800C19C4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C19C8: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800C19CC: nop

    // 0x800C19D0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C19D4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C19D8: lw          $t6, 0x3758($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3758);
    // 0x800C19DC: nop

    // 0x800C19E0: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800C19E4: jal         0x8007B820
    // 0x800C19E8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C19E8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_1:
    // 0x800C19EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C19F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C19F4: jr          $ra
    // 0x800C19F8: nop

    return;
    // 0x800C19F8: nop

;}
RECOMP_FUNC void transition_render_barndoor_vert(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C19FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1A04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C1A08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C1A0C: jal         0x8007B820
    // 0x800C1A10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C1A10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C1A14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C1A18: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C1A1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1A20: addiu       $t8, $t8, 0x3BD8
    ctx->r24 = ADD32(ctx->r24, 0X3BD8);
    // 0x800C1A24: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C1A28: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C1A2C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C1A30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C1A34: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C1A38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1A3C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C1A40: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C1A44: addiu       $a3, $a3, 0x3760
    ctx->r7 = ADD32(ctx->r7, 0X3760);
    // 0x800C1A48: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C1A4C: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800C1A50: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C1A54: addiu       $t1, $t1, 0x3750
    ctx->r9 = ADD32(ctx->r9, 0X3750);
    // 0x800C1A58: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C1A5C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C1A60: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C1A64: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800C1A68: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x800C1A6C: andi        $t7, $t6, 0x6
    ctx->r15 = ctx->r14 & 0X6;
    // 0x800C1A70: ori         $t8, $t7, 0x58
    ctx->r24 = ctx->r15 | 0X58;
    // 0x800C1A74: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800C1A78: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800C1A7C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800C1A80: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800C1A84: ori         $t4, $t3, 0xE0
    ctx->r12 = ctx->r11 | 0XE0;
    // 0x800C1A88: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C1A8C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800C1A90: lui         $t3, 0x570
    ctx->r11 = S32(0X570 << 16);
    // 0x800C1A94: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C1A98: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800C1A9C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C1AA0: ori         $t3, $t3, 0x80
    ctx->r11 = ctx->r11 | 0X80;
    // 0x800C1AA4: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800C1AA8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C1AAC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1AB0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C1AB4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800C1AB8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800C1ABC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C1AC0: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800C1AC4: nop

    // 0x800C1AC8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C1ACC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C1AD0: lw          $t6, 0x3758($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3758);
    // 0x800C1AD4: nop

    // 0x800C1AD8: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800C1ADC: jal         0x8007B820
    // 0x800C1AE0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C1AE0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_1:
    // 0x800C1AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1AEC: jr          $ra
    // 0x800C1AF0: nop

    return;
    // 0x800C1AF0: nop

;}
RECOMP_FUNC void transition_init_circle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1AF4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C1AF8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C1AFC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C1B00: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x800C1B04: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800C1B08: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800C1B0C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800C1B10: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800C1B14: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800C1B18: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800C1B1C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C1B20: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C1B24: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C1B28: jal         0x80070EDC
    // 0x800C1B2C: addiu       $a0, $zero, 0xDA0
    ctx->r4 = ADD32(0, 0XDA0);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C1B2C: addiu       $a0, $zero, 0xDA0
    ctx->r4 = ADD32(0, 0XDA0);
    after_0:
    // 0x800C1B30: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C1B34: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C1B38: addiu       $t7, $v0, 0x2D0
    ctx->r15 = ADD32(ctx->r2, 0X2D0);
    // 0x800C1B3C: addiu       $a1, $a1, 0x3758
    ctx->r5 = ADD32(ctx->r5, 0X3758);
    // 0x800C1B40: addiu       $a0, $a0, 0x3750
    ctx->r4 = ADD32(ctx->r4, 0X3750);
    // 0x800C1B44: addiu       $t9, $t7, 0x2D0
    ctx->r25 = ADD32(ctx->r15, 0X2D0);
    // 0x800C1B48: addiu       $t5, $t9, 0x400
    ctx->r13 = ADD32(ctx->r25, 0X400);
    // 0x800C1B4C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C1B50: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800C1B54: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800C1B58: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x800C1B5C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C1B60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C1B64: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C1B68: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C1B6C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C1B70: addiu       $a2, $a2, -0x530A
    ctx->r6 = ADD32(ctx->r6, -0X530A);
    // 0x800C1B74: addiu       $t2, $t2, 0x3758
    ctx->r10 = ADD32(ctx->r10, 0X3758);
    // 0x800C1B78: addiu       $v1, $v1, 0x3750
    ctx->r3 = ADD32(ctx->r3, 0X3750);
    // 0x800C1B7C: addiu       $a0, $a0, -0x530C
    ctx->r4 = ADD32(ctx->r4, -0X530C);
    // 0x800C1B80: addiu       $a1, $a1, -0x530B
    ctx->r5 = ADD32(ctx->r5, -0X530B);
    // 0x800C1B84: addiu       $t1, $zero, 0x2D0
    ctx->r9 = ADD32(0, 0X2D0);
    // 0x800C1B88: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800C1B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C1B90:
    // 0x800C1B90: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1B94: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1B98: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1B9C: sb          $t6, 0x6($t8)
    MEM_B(0X6, ctx->r24) = ctx->r14;
    // 0x800C1BA0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BA4: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800C1BA8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1BAC: sb          $t9, 0x7($t5)
    MEM_B(0X7, ctx->r13) = ctx->r25;
    // 0x800C1BB0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BB4: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1BB8: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1BBC: sb          $t7, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r15;
    // 0x800C1BC0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BC4: nop

    // 0x800C1BC8: addu        $t9, $t4, $v0
    ctx->r25 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1BCC: sb          $t0, 0x9($t9)
    MEM_B(0X9, ctx->r25) = ctx->r8;
    // 0x800C1BD0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BD4: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1BD8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1BDC: sb          $t5, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r13;
    // 0x800C1BE0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BE4: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800C1BE8: addu        $t9, $t4, $v0
    ctx->r25 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1BEC: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x800C1BF0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BF4: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1BF8: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800C1BFC: sb          $t6, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r14;
    // 0x800C1C00: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C04: nop

    // 0x800C1C08: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C0C: sb          $t0, 0x13($t8)
    MEM_B(0X13, ctx->r24) = ctx->r8;
    // 0x800C1C10: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C14: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1C18: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C1C1C: sb          $t9, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r25;
    // 0x800C1C20: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C24: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x800C1C28: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C2C: sb          $t7, 0x1B($t8)
    MEM_B(0X1B, ctx->r24) = ctx->r15;
    // 0x800C1C30: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C34: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1C38: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1C3C: sb          $t5, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r13;
    // 0x800C1C40: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C44: nop

    // 0x800C1C48: addu        $t7, $t4, $v0
    ctx->r15 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C4C: sb          $t0, 0x1D($t7)
    MEM_B(0X1D, ctx->r15) = ctx->r8;
    // 0x800C1C50: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C54: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1C58: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1C5C: sb          $t8, 0x24($t5)
    MEM_B(0X24, ctx->r13) = ctx->r24;
    // 0x800C1C60: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C64: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800C1C68: addu        $t7, $t4, $v0
    ctx->r15 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C6C: sb          $t6, 0x25($t7)
    MEM_B(0X25, ctx->r15) = ctx->r14;
    // 0x800C1C70: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C74: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1C78: addu        $t5, $t8, $v0
    ctx->r13 = ADD32(ctx->r24, ctx->r2);
    // 0x800C1C7C: sb          $t9, 0x26($t5)
    MEM_B(0X26, ctx->r13) = ctx->r25;
    // 0x800C1C80: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C84: nop

    // 0x800C1C88: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C8C: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800C1C90: bne         $v0, $t1, L_800C1B90
    if (ctx->r2 != ctx->r9) {
        // 0x800C1C94: sb          $t0, 0x27($t6)
        MEM_B(0X27, ctx->r14) = ctx->r8;
            goto L_800C1B90;
    }
    // 0x800C1C94: sb          $t0, 0x27($t6)
    MEM_B(0X27, ctx->r14) = ctx->r8;
    // 0x800C1C98: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C1C9C: sltu        $at, $v1, $t2
    ctx->r1 = ctx->r3 < ctx->r10 ? 1 : 0;
    // 0x800C1CA0: bne         $at, $zero, L_800C1B90
    if (ctx->r1 != 0) {
        // 0x800C1CA4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C1B90;
    }
    // 0x800C1CA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1CA8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C1CAC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C1CB0: addiu       $t2, $t2, 0x3758
    ctx->r10 = ADD32(ctx->r10, 0X3758);
    // 0x800C1CB4: addiu       $v1, $v1, 0x3750
    ctx->r3 = ADD32(ctx->r3, 0X3750);
    // 0x800C1CB8: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x800C1CBC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_800C1CC0:
    // 0x800C1CC0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1CC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C1CC8: sb          $zero, 0xC7($t7)
    MEM_B(0XC7, ctx->r15) = 0;
    // 0x800C1CCC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C1CD0: nop

    // 0x800C1CD4: sb          $zero, 0x22F($t8)
    MEM_B(0X22F, ctx->r24) = 0;
L_800C1CD8:
    // 0x800C1CD8: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x800C1CDC: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C1CE0: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C1CE4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C1CE8: addiu       $t8, $a3, 0x2
    ctx->r24 = ADD32(ctx->r7, 0X2);
    // 0x800C1CEC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1CF0: mflo        $v0
    ctx->r2 = lo;
    // 0x800C1CF4: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x800C1CF8: sb          $zero, 0xC7($t4)
    MEM_B(0XC7, ctx->r12) = 0;
    // 0x800C1CFC: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C1D00: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C1D04: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D08: addiu       $t8, $a3, 0x3
    ctx->r24 = ADD32(ctx->r7, 0X3);
    // 0x800C1D0C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1D10: sb          $zero, 0x22F($t7)
    MEM_B(0X22F, ctx->r15) = 0;
    // 0x800C1D14: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D18: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800C1D1C: mflo        $a0
    ctx->r4 = lo;
    // 0x800C1D20: addu        $t4, $t5, $a0
    ctx->r12 = ADD32(ctx->r13, ctx->r4);
    // 0x800C1D24: sb          $zero, 0xC7($t4)
    MEM_B(0XC7, ctx->r12) = 0;
    // 0x800C1D28: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C1D2C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D30: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C1D34: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800C1D38: sb          $zero, 0x22F($t7)
    MEM_B(0X22F, ctx->r15) = 0;
    // 0x800C1D3C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D40: mflo        $a1
    ctx->r5 = lo;
    // 0x800C1D44: addu        $t4, $t5, $a1
    ctx->r12 = ADD32(ctx->r13, ctx->r5);
    // 0x800C1D48: sb          $zero, 0xC7($t4)
    MEM_B(0XC7, ctx->r12) = 0;
    // 0x800C1D4C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C1D50: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D54: nop

    // 0x800C1D58: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C1D5C: sb          $zero, 0x22F($t7)
    MEM_B(0X22F, ctx->r15) = 0;
    // 0x800C1D60: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D64: mflo        $a2
    ctx->r6 = lo;
    // 0x800C1D68: addu        $t4, $t5, $a2
    ctx->r12 = ADD32(ctx->r13, ctx->r6);
    // 0x800C1D6C: sb          $zero, 0xC7($t4)
    MEM_B(0XC7, ctx->r12) = 0;
    // 0x800C1D70: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D74: nop

    // 0x800C1D78: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800C1D7C: bne         $a3, $t1, L_800C1CD8
    if (ctx->r7 != ctx->r9) {
        // 0x800C1D80: sb          $zero, 0x22F($t7)
        MEM_B(0X22F, ctx->r15) = 0;
            goto L_800C1CD8;
    }
    // 0x800C1D80: sb          $zero, 0x22F($t7)
    MEM_B(0X22F, ctx->r15) = 0;
    // 0x800C1D84: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C1D88: sltu        $at, $v1, $t2
    ctx->r1 = ctx->r3 < ctx->r10 ? 1 : 0;
    // 0x800C1D8C: bne         $at, $zero, L_800C1CC0
    if (ctx->r1 != 0) {
        // 0x800C1D90: nop
    
            goto L_800C1CC0;
    }
    // 0x800C1D90: nop

    // 0x800C1D94: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800C1D98: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800C1D9C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800C1DA0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800C1DA4: addiu       $s2, $s2, 0x3758
    ctx->r18 = ADD32(ctx->r18, 0X3758);
    // 0x800C1DA8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C1DAC: addiu       $s0, $zero, -0x10
    ctx->r16 = ADD32(0, -0X10);
L_800C1DB0:
    // 0x800C1DB0: sll         $s3, $s5, 16
    ctx->r19 = S32(ctx->r21 << 16);
    // 0x800C1DB4: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800C1DB8: sll         $a0, $t8, 16
    ctx->r4 = S32(ctx->r24 << 16);
    // 0x800C1DBC: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C1DC0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800C1DC4: jal         0x80070A04
    // 0x800C1DC8: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x800C1DC8: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    after_1:
    // 0x800C1DCC: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800C1DD0: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x800C1DD4: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C1DD8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800C1DDC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800C1DE0: nop

    // 0x800C1DE4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800C1DE8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1DEC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C1DF0: nop

    // 0x800C1DF4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800C1DF8: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x800C1DFC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800C1E00: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x800C1E04: jal         0x80070A38
    // 0x800C1E08: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_2;
    // 0x800C1E08: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
    after_2:
    // 0x800C1E0C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C1E10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C1E14: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x800C1E18: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C1E1C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800C1E20: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1E24: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C1E28: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C1E2C: addiu       $v0, $v0, 0x3750
    ctx->r2 = ADD32(ctx->r2, 0X3750);
    // 0x800C1E30: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800C1E34: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1E38: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C1E3C: sll         $v1, $t8, 1
    ctx->r3 = S32(ctx->r24 << 1);
    // 0x800C1E40: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C1E44: negu        $a1, $s1
    ctx->r5 = SUB32(0, ctx->r17);
    // 0x800C1E48: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x800C1E4C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C1E50: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800C1E54: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
L_800C1E58:
    // 0x800C1E58: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C1E5C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C1E60: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800C1E64: sh          $s1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r17;
    // 0x800C1E68: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E6C: nop

    // 0x800C1E70: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1E74: sh          $a0, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r4;
    // 0x800C1E78: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E7C: nop

    // 0x800C1E80: addu        $t4, $t5, $v1
    ctx->r12 = ADD32(ctx->r13, ctx->r3);
    // 0x800C1E84: sh          $s0, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r16;
    // 0x800C1E88: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E8C: nop

    // 0x800C1E90: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800C1E94: sh          $s0, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r16;
    // 0x800C1E98: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E9C: nop

    // 0x800C1EA0: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1EA4: sh          $s0, 0xB8($t9)
    MEM_H(0XB8, ctx->r25) = ctx->r16;
    // 0x800C1EA8: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800C1EAC: nop

    // 0x800C1EB0: addu        $t4, $t5, $v1
    ctx->r12 = ADD32(ctx->r13, ctx->r3);
    // 0x800C1EB4: sh          $s0, 0xC2($t4)
    MEM_H(0XC2, ctx->r12) = ctx->r16;
    // 0x800C1EB8: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800C1EBC: nop

    // 0x800C1EC0: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800C1EC4: sh          $a1, 0x168($t7)
    MEM_H(0X168, ctx->r15) = ctx->r5;
    // 0x800C1EC8: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x800C1ECC: nop

    // 0x800C1ED0: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1ED4: sh          $a0, 0x16A($t9)
    MEM_H(0X16A, ctx->r25) = ctx->r4;
    // 0x800C1ED8: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800C1EDC: nop

    // 0x800C1EE0: addu        $t4, $t5, $v1
    ctx->r12 = ADD32(ctx->r13, ctx->r3);
    // 0x800C1EE4: sh          $s0, 0x16C($t4)
    MEM_H(0X16C, ctx->r12) = ctx->r16;
    // 0x800C1EE8: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800C1EEC: nop

    // 0x800C1EF0: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800C1EF4: sh          $s0, 0x176($t7)
    MEM_H(0X176, ctx->r15) = ctx->r16;
    // 0x800C1EF8: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x800C1EFC: nop

    // 0x800C1F00: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1F04: sh          $s0, 0x220($t9)
    MEM_H(0X220, ctx->r25) = ctx->r16;
    // 0x800C1F08: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800C1F0C: nop

    // 0x800C1F10: addu        $t4, $t5, $v1
    ctx->r12 = ADD32(ctx->r13, ctx->r3);
    // 0x800C1F14: bne         $v0, $s2, L_800C1E58
    if (ctx->r2 != ctx->r18) {
        // 0x800C1F18: sh          $s0, 0x22A($t4)
        MEM_H(0X22A, ctx->r12) = ctx->r16;
            goto L_800C1E58;
    }
    // 0x800C1F18: sh          $s0, 0x22A($t4)
    MEM_H(0X22A, ctx->r12) = ctx->r16;
    // 0x800C1F1C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C1F20: slti        $at, $s4, 0x9
    ctx->r1 = SIGNED(ctx->r20) < 0X9 ? 1 : 0;
    // 0x800C1F24: bne         $at, $zero, L_800C1DB0
    if (ctx->r1 != 0) {
        // 0x800C1F28: addiu       $s5, $s5, 0x1000
        ctx->r21 = ADD32(ctx->r21, 0X1000);
            goto L_800C1DB0;
    }
    // 0x800C1F28: addiu       $s5, $s5, 0x1000
    ctx->r21 = ADD32(ctx->r21, 0X1000);
    // 0x800C1F2C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800C1F30: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C1F34: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800C1F38: addiu       $v1, $v1, 0x3758
    ctx->r3 = ADD32(ctx->r3, 0X3758);
    // 0x800C1F3C: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x800C1F40: beq         $t8, $zero, L_800C1FB8
    if (ctx->r24 == 0) {
        // 0x800C1F44: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_800C1FB8;
    }
    // 0x800C1F44: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C1F48: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C1F4C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C1F50: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C1F54: lhu         $t9, 0x3740($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X3740);
    // 0x800C1F58: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C1F5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1F60: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800C1F64: swc1        $f2, -0x52E8($at)
    MEM_W(-0X52E8, ctx->r1) = ctx->f2.u32l;
    // 0x800C1F68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1F6C: swc1        $f2, -0x52E4($at)
    MEM_W(-0X52E4, ctx->r1) = ctx->f2.u32l;
    // 0x800C1F70: bgez        $t9, L_800C1F88
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800C1F74: cvt.s.w     $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800C1F88;
    }
    // 0x800C1F74: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C1F78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C1F7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C1F80: nop

    // 0x800C1F84: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_800C1F88:
    // 0x800C1F88: nop

    // 0x800C1F8C: div.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800C1F90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1F94: div.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800C1F98: swc1        $f6, -0x52E0($at)
    MEM_W(-0X52E0, ctx->r1) = ctx->f6.u32l;
    // 0x800C1F9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1FA0: swc1        $f8, -0x52DC($at)
    MEM_W(-0X52DC, ctx->r1) = ctx->f8.u32l;
    // 0x800C1FA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1FA8: swc1        $f20, -0x52D8($at)
    MEM_W(-0X52D8, ctx->r1) = ctx->f20.u32l;
    // 0x800C1FAC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1FB0: b           L_800C202C
    // 0x800C1FB4: swc1        $f12, -0x52D4($at)
    MEM_W(-0X52D4, ctx->r1) = ctx->f12.u32l;
        goto L_800C202C;
    // 0x800C1FB4: swc1        $f12, -0x52D4($at)
    MEM_W(-0X52D4, ctx->r1) = ctx->f12.u32l;
L_800C1FB8:
    // 0x800C1FB8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C1FBC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C1FC0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C1FC4: lhu         $t5, 0x3740($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X3740);
    // 0x800C1FC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1FCC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800C1FD0: swc1        $f20, -0x52E8($at)
    MEM_W(-0X52E8, ctx->r1) = ctx->f20.u32l;
    // 0x800C1FD4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C1FD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1FDC: swc1        $f12, -0x52E4($at)
    MEM_W(-0X52E4, ctx->r1) = ctx->f12.u32l;
    // 0x800C1FE0: bgez        $t5, L_800C1FF8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800C1FE4: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800C1FF8;
    }
    // 0x800C1FE4: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C1FE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C1FEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C1FF0: nop

    // 0x800C1FF4: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
L_800C1FF8:
    // 0x800C1FF8: neg.s       $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = -ctx->f20.fl;
    // 0x800C1FFC: nop

    // 0x800C2000: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800C2004: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x800C2008: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C200C: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C2010: swc1        $f4, -0x52E0($at)
    MEM_W(-0X52E0, ctx->r1) = ctx->f4.u32l;
    // 0x800C2014: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2018: swc1        $f8, -0x52DC($at)
    MEM_W(-0X52DC, ctx->r1) = ctx->f8.u32l;
    // 0x800C201C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2020: swc1        $f2, -0x52D8($at)
    MEM_W(-0X52D8, ctx->r1) = ctx->f2.u32l;
    // 0x800C2024: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2028: swc1        $f2, -0x52D4($at)
    MEM_W(-0X52D4, ctx->r1) = ctx->f2.u32l;
L_800C202C:
    // 0x800C202C: addiu       $a2, $a2, 0x3760
    ctx->r6 = ADD32(ctx->r6, 0X3760);
    // 0x800C2030: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x800C2034: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800C2038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C203C:
    // 0x800C203C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C2040: nop

    // 0x800C2044: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C2048: sb          $a0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r4;
    // 0x800C204C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C2050: nop

    // 0x800C2054: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2058: sh          $zero, 0x4($t8)
    MEM_H(0X4, ctx->r24) = 0;
    // 0x800C205C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C2060: nop

    // 0x800C2064: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C2068: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x800C206C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C2070: nop

    // 0x800C2074: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C2078: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x800C207C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C2080: nop

    // 0x800C2084: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2088: sh          $zero, 0xA($t8)
    MEM_H(0XA, ctx->r24) = 0;
    // 0x800C208C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C2090: nop

    // 0x800C2094: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C2098: sh          $zero, 0xC($t5)
    MEM_H(0XC, ctx->r13) = 0;
    // 0x800C209C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C20A0: nop

    // 0x800C20A4: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C20A8: sh          $zero, 0xE($t6)
    MEM_H(0XE, ctx->r14) = 0;
    // 0x800C20AC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C20B0: nop

    // 0x800C20B4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C20B8: sb          $a0, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r4;
    // 0x800C20BC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C20C0: nop

    // 0x800C20C4: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C20C8: sh          $zero, 0x14($t5)
    MEM_H(0X14, ctx->r13) = 0;
    // 0x800C20CC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C20D0: nop

    // 0x800C20D4: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C20D8: sh          $zero, 0x16($t6)
    MEM_H(0X16, ctx->r14) = 0;
    // 0x800C20DC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C20E0: nop

    // 0x800C20E4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C20E8: sh          $zero, 0x18($t8)
    MEM_H(0X18, ctx->r24) = 0;
    // 0x800C20EC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C20F0: nop

    // 0x800C20F4: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C20F8: sh          $zero, 0x1A($t5)
    MEM_H(0X1A, ctx->r13) = 0;
    // 0x800C20FC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C2100: nop

    // 0x800C2104: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C2108: sh          $zero, 0x1C($t6)
    MEM_H(0X1C, ctx->r14) = 0;
    // 0x800C210C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C2110: nop

    // 0x800C2114: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2118: sh          $zero, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = 0;
    // 0x800C211C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C2120: nop

    // 0x800C2124: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C2128: sb          $a0, 0x20($t5)
    MEM_B(0X20, ctx->r13) = ctx->r4;
    // 0x800C212C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C2130: nop

    // 0x800C2134: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C2138: sh          $zero, 0x24($t6)
    MEM_H(0X24, ctx->r14) = 0;
    // 0x800C213C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C2140: nop

    // 0x800C2144: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2148: sh          $zero, 0x26($t8)
    MEM_H(0X26, ctx->r24) = 0;
    // 0x800C214C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C2150: nop

    // 0x800C2154: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C2158: sh          $zero, 0x28($t5)
    MEM_H(0X28, ctx->r13) = 0;
    // 0x800C215C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C2160: nop

    // 0x800C2164: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C2168: sh          $zero, 0x2A($t6)
    MEM_H(0X2A, ctx->r14) = 0;
    // 0x800C216C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C2170: nop

    // 0x800C2174: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2178: sh          $zero, 0x2C($t8)
    MEM_H(0X2C, ctx->r24) = 0;
    // 0x800C217C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C2180: nop

    // 0x800C2184: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C2188: sh          $zero, 0x2E($t5)
    MEM_H(0X2E, ctx->r13) = 0;
    // 0x800C218C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C2190: nop

    // 0x800C2194: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C2198: sb          $a0, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r4;
    // 0x800C219C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C21A0: nop

    // 0x800C21A4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C21A8: sh          $zero, 0x34($t8)
    MEM_H(0X34, ctx->r24) = 0;
    // 0x800C21AC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C21B0: nop

    // 0x800C21B4: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C21B8: sh          $zero, 0x36($t5)
    MEM_H(0X36, ctx->r13) = 0;
    // 0x800C21BC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C21C0: nop

    // 0x800C21C4: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C21C8: sh          $zero, 0x38($t6)
    MEM_H(0X38, ctx->r14) = 0;
    // 0x800C21CC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C21D0: nop

    // 0x800C21D4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C21D8: sh          $zero, 0x3A($t8)
    MEM_H(0X3A, ctx->r24) = 0;
    // 0x800C21DC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C21E0: nop

    // 0x800C21E4: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C21E8: sh          $zero, 0x3C($t5)
    MEM_H(0X3C, ctx->r13) = 0;
    // 0x800C21EC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C21F0: nop

    // 0x800C21F4: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C21F8: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800C21FC: bne         $v0, $a1, L_800C203C
    if (ctx->r2 != ctx->r5) {
        // 0x800C2200: sh          $zero, 0x3E($t6)
        MEM_H(0X3E, ctx->r14) = 0;
            goto L_800C203C;
    }
    // 0x800C2200: sh          $zero, 0x3E($t6)
    MEM_H(0X3E, ctx->r14) = 0;
    // 0x800C2204: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C2208: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x800C220C: bne         $at, $zero, L_800C203C
    if (ctx->r1 != 0) {
        // 0x800C2210: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C203C;
    }
    // 0x800C2210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C2214: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C2218: addiu       $t2, $t2, 0x3760
    ctx->r10 = ADD32(ctx->r10, 0X3760);
    // 0x800C221C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C2220: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800C2224: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
L_800C2228:
    // 0x800C2228: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C222C: addiu       $v0, $v0, 0x3758
    ctx->r2 = ADD32(ctx->r2, 0X3758);
    // 0x800C2230: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800C2234: addiu       $a2, $a0, 0x1
    ctx->r6 = ADD32(ctx->r4, 0X1);
    // 0x800C2238: addiu       $a1, $a0, 0x3
    ctx->r5 = ADD32(ctx->r4, 0X3);
    // 0x800C223C: addiu       $t0, $a0, 0x2
    ctx->r8 = ADD32(ctx->r4, 0X2);
L_800C2240:
    // 0x800C2240: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800C2244: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C2248: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C224C: sb          $a0, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r4;
    // 0x800C2250: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C2254: nop

    // 0x800C2258: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C225C: sb          $a2, 0x2($t5)
    MEM_B(0X2, ctx->r13) = ctx->r6;
    // 0x800C2260: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C2264: nop

    // 0x800C2268: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C226C: sb          $a1, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r5;
    // 0x800C2270: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C2274: nop

    // 0x800C2278: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C227C: sb          $a0, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r4;
    // 0x800C2280: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C2284: nop

    // 0x800C2288: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C228C: sb          $a1, 0x12($t5)
    MEM_B(0X12, ctx->r13) = ctx->r5;
    // 0x800C2290: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C2294: nop

    // 0x800C2298: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C229C: sb          $t0, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r8;
    // 0x800C22A0: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C22A4: nop

    // 0x800C22A8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C22AC: sb          $a0, 0x101($t8)
    MEM_B(0X101, ctx->r24) = ctx->r4;
    // 0x800C22B0: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C22B4: nop

    // 0x800C22B8: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C22BC: sb          $a2, 0x102($t5)
    MEM_B(0X102, ctx->r13) = ctx->r6;
    // 0x800C22C0: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C22C4: nop

    // 0x800C22C8: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C22CC: sb          $a1, 0x103($t6)
    MEM_B(0X103, ctx->r14) = ctx->r5;
    // 0x800C22D0: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C22D4: nop

    // 0x800C22D8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C22DC: sb          $a0, 0x111($t8)
    MEM_B(0X111, ctx->r24) = ctx->r4;
    // 0x800C22E0: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C22E4: nop

    // 0x800C22E8: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C22EC: sb          $a1, 0x112($t5)
    MEM_B(0X112, ctx->r13) = ctx->r5;
    // 0x800C22F0: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C22F4: nop

    // 0x800C22F8: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C22FC: sb          $t0, 0x113($t6)
    MEM_B(0X113, ctx->r14) = ctx->r8;
    // 0x800C2300: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C2304: nop

    // 0x800C2308: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C230C: sb          $a0, 0x201($t8)
    MEM_B(0X201, ctx->r24) = ctx->r4;
    // 0x800C2310: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C2314: nop

    // 0x800C2318: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C231C: sb          $a2, 0x202($t5)
    MEM_B(0X202, ctx->r13) = ctx->r6;
    // 0x800C2320: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C2324: nop

    // 0x800C2328: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C232C: sb          $a1, 0x203($t6)
    MEM_B(0X203, ctx->r14) = ctx->r5;
    // 0x800C2330: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C2334: nop

    // 0x800C2338: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C233C: sb          $a0, 0x211($t8)
    MEM_B(0X211, ctx->r24) = ctx->r4;
    // 0x800C2340: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C2344: nop

    // 0x800C2348: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C234C: sb          $a1, 0x212($t5)
    MEM_B(0X212, ctx->r13) = ctx->r5;
    // 0x800C2350: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C2354: nop

    // 0x800C2358: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C235C: sb          $t0, 0x213($t6)
    MEM_B(0X213, ctx->r14) = ctx->r8;
    // 0x800C2360: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C2364: nop

    // 0x800C2368: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C236C: sb          $a0, 0x301($t8)
    MEM_B(0X301, ctx->r24) = ctx->r4;
    // 0x800C2370: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C2374: nop

    // 0x800C2378: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C237C: sb          $a2, 0x302($t5)
    MEM_B(0X302, ctx->r13) = ctx->r6;
    // 0x800C2380: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C2384: nop

    // 0x800C2388: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C238C: sb          $a1, 0x303($t6)
    MEM_B(0X303, ctx->r14) = ctx->r5;
    // 0x800C2390: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C2394: nop

    // 0x800C2398: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C239C: sb          $a0, 0x311($t8)
    MEM_B(0X311, ctx->r24) = ctx->r4;
    // 0x800C23A0: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C23A4: nop

    // 0x800C23A8: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C23AC: sb          $a1, 0x312($t5)
    MEM_B(0X312, ctx->r13) = ctx->r5;
    // 0x800C23B0: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C23B4: nop

    // 0x800C23B8: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C23BC: bne         $v0, $t2, L_800C2240
    if (ctx->r2 != ctx->r10) {
        // 0x800C23C0: sb          $t0, 0x313($t6)
        MEM_B(0X313, ctx->r14) = ctx->r8;
            goto L_800C2240;
    }
    // 0x800C23C0: sb          $t0, 0x313($t6)
    MEM_B(0X313, ctx->r14) = ctx->r8;
    // 0x800C23C4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C23C8: bne         $s4, $t3, L_800C2228
    if (ctx->r20 != ctx->r11) {
        // 0x800C23CC: sll         $a0, $s4, 1
        ctx->r4 = S32(ctx->r20 << 1);
            goto L_800C2228;
    }
    // 0x800C23CC: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
    // 0x800C23D0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C23D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C23D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C23DC: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C23E0: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C23E4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800C23E8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800C23EC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800C23F0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800C23F4: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800C23F8: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800C23FC: sw          $t7, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = ctx->r15;
    // 0x800C2400: jr          $ra
    // 0x800C2404: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C2404: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void transition_update_circle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2408: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C240C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C2410: addiu       $v1, $v1, 0x3740
    ctx->r3 = ADD32(ctx->r3, 0X3740);
    // 0x800C2414: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800C2418: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800C241C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800C2420: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800C2424: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800C2428: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800C242C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800C2430: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800C2434: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800C2438: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800C243C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800C2440: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800C2444: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800C2448: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800C244C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C2450: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800C2454: blez        $v0, L_800C2728
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C2458: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C2728;
    }
    // 0x800C2458: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C245C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C2460: beq         $at, $zero, L_800C24B4
    if (ctx->r1 == 0) {
        // 0x800C2464: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800C24B4;
    }
    // 0x800C2464: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C2468: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C246C: lwc1        $f8, -0x52E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X52E0);
    // 0x800C2470: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800C2474: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C2478: addiu       $s7, $s7, -0x52E8
    ctx->r23 = ADD32(ctx->r23, -0X52E8);
    // 0x800C247C: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800C2480: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2484: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C2488: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800C248C: swc1        $f16, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f16.u32l;
    // 0x800C2490: lwc1        $f4, -0x52DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X52DC);
    // 0x800C2494: addiu       $fp, $fp, -0x52E4
    ctx->r30 = ADD32(ctx->r30, -0X52E4);
    // 0x800C2498: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C249C: lwc1        $f18, 0x0($fp)
    ctx->f18.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800C24A0: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800C24A4: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800C24A8: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800C24AC: b           L_800C24E0
    // 0x800C24B0: swc1        $f6, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f6.u32l;
        goto L_800C24E0;
    // 0x800C24B0: swc1        $f6, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f6.u32l;
L_800C24B4:
    // 0x800C24B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C24B8: lwc1        $f10, -0x52D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X52D8);
    // 0x800C24BC: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800C24C0: addiu       $s7, $s7, -0x52E8
    ctx->r23 = ADD32(ctx->r23, -0X52E8);
    // 0x800C24C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C24C8: swc1        $f10, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f10.u32l;
    // 0x800C24CC: lwc1        $f16, -0x52D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X52D4);
    // 0x800C24D0: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800C24D4: addiu       $fp, $fp, -0x52E4
    ctx->r30 = ADD32(ctx->r30, -0X52E4);
    // 0x800C24D8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800C24DC: swc1        $f16, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f16.u32l;
L_800C24E0:
    // 0x800C24E0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C24E4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800C24E8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800C24EC: lwc1        $f22, -0x6754($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X6754);
    // 0x800C24F0: addiu       $s0, $s0, 0x3750
    ctx->r16 = ADD32(ctx->r16, 0X3750);
    // 0x800C24F4: addiu       $s1, $s1, 0x3760
    ctx->r17 = ADD32(ctx->r17, 0X3760);
    // 0x800C24F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C24FC: addiu       $s6, $zero, 0x9
    ctx->r22 = ADD32(0, 0X9);
    // 0x800C2500: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
L_800C2504:
    // 0x800C2504: sll         $s4, $s3, 16
    ctx->r20 = S32(ctx->r19 << 16);
    // 0x800C2508: sra         $t7, $s4, 16
    ctx->r15 = S32(SIGNED(ctx->r20) >> 16);
    // 0x800C250C: sll         $a0, $t7, 16
    ctx->r4 = S32(ctx->r15 << 16);
    // 0x800C2510: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C2514: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800C2518: jal         0x80070A04
    // 0x800C251C: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800C251C: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    after_0:
    // 0x800C2520: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800C2524: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x800C2528: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C252C: mul.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C2530: jal         0x80070A38
    // 0x800C2534: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800C2534: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x800C2538: lwc1        $f18, 0x0($fp)
    ctx->f18.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800C253C: sll         $t0, $s2, 1
    ctx->r8 = S32(ctx->r18 << 1);
    // 0x800C2540: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800C2544: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800C2548: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C254C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C2550: mul.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800C2554: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x800C2558: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C255C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C2560: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800C2564: addiu       $s3, $s3, 0x1000
    ctx->r19 = ADD32(ctx->r19, 0X1000);
    // 0x800C2568: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800C256C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C2570: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C2574: nop

    // 0x800C2578: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800C257C: mflo        $v0
    ctx->r2 = lo;
    // 0x800C2580: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800C2584: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800C2588: mul.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800C258C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C2590: sh          $a0, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r4;
    // 0x800C2594: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800C2598: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C259C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C25A0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800C25A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C25A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C25AC: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x800C25B0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C25B4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800C25B8: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800C25BC: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800C25C0: sh          $v1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r3;
    // 0x800C25C4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800C25C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C25CC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C25D0: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800C25D4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C25D8: negu        $a3, $a0
    ctx->r7 = SUB32(0, ctx->r4);
    // 0x800C25DC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C25E0: sh          $a3, 0x172($t8)
    MEM_H(0X172, ctx->r24) = ctx->r7;
    // 0x800C25E4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C25E8: nop

    // 0x800C25EC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C25F0: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800C25F4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C25F8: nop

    // 0x800C25FC: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C2600: sh          $v1, 0x174($t3)
    MEM_H(0X174, ctx->r11) = ctx->r3;
    // 0x800C2604: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800C2608: nop

    // 0x800C260C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C2610: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800C2614: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C2618: nop

    // 0x800C261C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2620: sh          $a0, 0xB4($t8)
    MEM_H(0XB4, ctx->r24) = ctx->r4;
    // 0x800C2624: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C2628: nop

    // 0x800C262C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C2630: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800C2634: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C2638: nop

    // 0x800C263C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C2640: sh          $v1, 0xB6($t3)
    MEM_H(0XB6, ctx->r11) = ctx->r3;
    // 0x800C2644: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800C2648: nop

    // 0x800C264C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C2650: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800C2654: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C2658: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800C265C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2660: sh          $a3, 0x21C($t8)
    MEM_H(0X21C, ctx->r24) = ctx->r7;
    // 0x800C2664: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C2668: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800C266C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C2670: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800C2674: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C2678: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C267C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C2680: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C2684: sh          $v1, 0x21E($t3)
    MEM_H(0X21E, ctx->r11) = ctx->r3;
    // 0x800C2688: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800C268C: cvt.w.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = CVT_W_S(ctx->f20.fl);
    // 0x800C2690: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C2694: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800C2698: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800C269C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C26A0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800C26A4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800C26A8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C26AC: sh          $a1, 0xBE($t9)
    MEM_H(0XBE, ctx->r25) = ctx->r5;
    // 0x800C26B0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800C26B4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800C26B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C26BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C26C0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800C26C4: cvt.w.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800C26C8: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800C26CC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800C26D0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800C26D4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C26D8: sh          $a2, 0xC0($t5)
    MEM_H(0XC0, ctx->r13) = ctx->r6;
    // 0x800C26DC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C26E0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800C26E4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C26E8: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800C26EC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C26F0: negu        $t8, $a1
    ctx->r24 = SUB32(0, ctx->r5);
    // 0x800C26F4: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C26F8: sh          $t8, 0x226($t3)
    MEM_H(0X226, ctx->r11) = ctx->r24;
    // 0x800C26FC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800C2700: nop

    // 0x800C2704: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C2708: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800C270C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C2710: nop

    // 0x800C2714: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2718: bne         $s2, $s6, L_800C2504
    if (ctx->r18 != ctx->r22) {
        // 0x800C271C: sh          $a2, 0x228($t9)
        MEM_H(0X228, ctx->r25) = ctx->r6;
            goto L_800C2504;
    }
    // 0x800C271C: sh          $a2, 0x228($t9)
    MEM_H(0X228, ctx->r25) = ctx->r6;
    // 0x800C2720: b           L_800C2758
    // 0x800C2724: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_800C2758;
    // 0x800C2724: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_800C2728:
    // 0x800C2728: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C272C: addiu       $v1, $v1, 0x3744
    ctx->r3 = ADD32(ctx->r3, 0X3744);
    // 0x800C2730: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800C2734: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800C2738: beq         $v0, $at, L_800C2754
    if (ctx->r2 == ctx->r1) {
        // 0x800C273C: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800C2754;
    }
    // 0x800C273C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C2740: beq         $at, $zero, L_800C2750
    if (ctx->r1 == 0) {
        // 0x800C2744: subu        $t0, $v0, $a0
        ctx->r8 = SUB32(ctx->r2, ctx->r4);
            goto L_800C2750;
    }
    // 0x800C2744: subu        $t0, $v0, $a0
    ctx->r8 = SUB32(ctx->r2, ctx->r4);
    // 0x800C2748: b           L_800C2754
    // 0x800C274C: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
        goto L_800C2754;
    // 0x800C274C: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
L_800C2750:
    // 0x800C2750: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_800C2754:
    // 0x800C2754: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_800C2758:
    // 0x800C2758: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C275C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C2760: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C2764: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C2768: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800C276C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2770: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800C2774: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800C2778: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800C277C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800C2780: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800C2784: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800C2788: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800C278C: jr          $ra
    // 0x800C2790: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C2790: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void transition_render_circle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C279C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C27A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C27A4: jal         0x8007B820
    // 0x800C27A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C27A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C27AC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C27B0: lw          $v1, 0x3760($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3760);
    // 0x800C27B4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C27B8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C27BC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800C27C0: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x800C27C4: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C27C8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800C27CC: lw          $a3, 0x3750($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3750);
    // 0x800C27D0: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x800C27D4: lw          $t0, 0x3758($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3758);
    // 0x800C27D8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C27DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C27E0: addiu       $t9, $t9, 0x3BD8
    ctx->r25 = ADD32(ctx->r25, 0X3BD8);
    // 0x800C27E4: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800C27E8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800C27EC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800C27F0: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800C27F4: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800C27F8: andi        $t3, $a0, 0x6
    ctx->r11 = ctx->r4 & 0X6;
    // 0x800C27FC: ori         $t4, $t3, 0x88
    ctx->r12 = ctx->r11 | 0X88;
    // 0x800C2800: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C2804: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800C2808: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x800C280C: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C2810: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C2814: addiu       $a3, $a3, 0xB4
    ctx->r7 = ADD32(ctx->r7, 0XB4);
    // 0x800C2818: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800C281C: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800C2820: andi        $t3, $a0, 0x6
    ctx->r11 = ctx->r4 & 0X6;
    // 0x800C2824: ori         $t8, $t7, 0x14C
    ctx->r24 = ctx->r15 | 0X14C;
    // 0x800C2828: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
    // 0x800C282C: ori         $t4, $t3, 0x88
    ctx->r12 = ctx->r11 | 0X88;
    // 0x800C2830: lui         $t2, 0x5F0
    ctx->r10 = S32(0X5F0 << 16);
    // 0x800C2834: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C2838: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x800C283C: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C2840: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x800C2844: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C2848: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800C284C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800C2850: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x800C2854: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x800C2858: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800C285C: addiu       $a3, $a3, 0xB4
    ctx->r7 = ADD32(ctx->r7, 0XB4);
    // 0x800C2860: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800C2864: ori         $t8, $t7, 0x14C
    ctx->r24 = ctx->r15 | 0X14C;
    // 0x800C2868: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800C286C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800C2870: andi        $t3, $a0, 0x6
    ctx->r11 = ctx->r4 & 0X6;
    // 0x800C2874: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x800C2878: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x800C287C: ori         $t4, $t3, 0x88
    ctx->r12 = ctx->r11 | 0X88;
    // 0x800C2880: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C2884: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800C2888: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800C288C: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x800C2890: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C2894: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C2898: addiu       $a3, $a3, 0xB4
    ctx->r7 = ADD32(ctx->r7, 0XB4);
    // 0x800C289C: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800C28A0: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800C28A4: ori         $t8, $t7, 0x14C
    ctx->r24 = ctx->r15 | 0X14C;
    // 0x800C28A8: andi        $t3, $a0, 0x6
    ctx->r11 = ctx->r4 & 0X6;
    // 0x800C28AC: ori         $t4, $t3, 0x88
    ctx->r12 = ctx->r11 | 0X88;
    // 0x800C28B0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C28B4: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x800C28B8: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x800C28BC: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x800C28C0: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C28C4: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C28C8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C28CC: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800C28D0: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800C28D4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800C28D8: ori         $t8, $t7, 0x14C
    ctx->r24 = ctx->r15 | 0X14C;
    // 0x800C28DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C28E0: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C28E4: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
    // 0x800C28E8: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x800C28EC: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x800C28F0: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800C28F4: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800C28F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C28FC: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x800C2900: jal         0x8007B820
    // 0x800C2904: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C2904: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    after_1:
    // 0x800C2908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C290C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2910: jr          $ra
    // 0x800C2914: nop

    return;
    // 0x800C2914: nop

;}
RECOMP_FUNC void transition_render_waves(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2918: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C291C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C2920: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C2924: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C2928: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C292C: jal         0x8007B820
    // 0x800C2930: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C2930: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C2934: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C2938: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800C293C: lw          $v1, 0x3760($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3760);
    // 0x800C2940: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x800C2944: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800C2948: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C294C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C2950: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x800C2954: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C2958: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C295C: lw          $a2, 0x3750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3750);
    // 0x800C2960: lw          $a3, 0x3758($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3758);
    // 0x800C2964: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C2968: addiu       $t9, $t9, 0x3BD8
    ctx->r25 = ADD32(ctx->r25, 0X3BD8);
    // 0x800C296C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800C2970: lui         $s0, 0x5D0
    ctx->r16 = S32(0X5D0 << 16);
    // 0x800C2974: lui         $t5, 0x5B0
    ctx->r13 = S32(0X5B0 << 16);
    // 0x800C2978: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800C297C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800C2980: ori         $t5, $t5, 0xC0
    ctx->r13 = ctx->r13 | 0XC0;
    // 0x800C2984: ori         $s0, $s0, 0xE0
    ctx->r16 = ctx->r16 | 0XE0;
    // 0x800C2988: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800C298C: addiu       $ra, $zero, 0x6
    ctx->r31 = ADD32(0, 0X6);
    // 0x800C2990: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800C2994: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C2998: lui         $t2, 0x400
    ctx->r10 = S32(0X400 << 16);
    // 0x800C299C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800C29A0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800C29A4:
    // 0x800C29A4: beq         $t0, $t3, L_800C29B4
    if (ctx->r8 == ctx->r11) {
        // 0x800C29A8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C29B4;
    }
    // 0x800C29A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C29AC: bne         $t0, $t4, L_800C29FC
    if (ctx->r8 != ctx->r12) {
        // 0x800C29B0: addu        $a0, $a2, $t1
        ctx->r4 = ADD32(ctx->r6, ctx->r9);
            goto L_800C29FC;
    }
    // 0x800C29B0: addu        $a0, $a2, $t1
    ctx->r4 = ADD32(ctx->r6, ctx->r9);
L_800C29B4:
    // 0x800C29B4: addu        $a0, $a2, $t1
    ctx->r4 = ADD32(ctx->r6, ctx->r9);
    // 0x800C29B8: andi        $t6, $a0, 0x6
    ctx->r14 = ctx->r4 & 0X6;
    // 0x800C29BC: ori         $t7, $t6, 0x68
    ctx->r15 = ctx->r14 | 0X68;
    // 0x800C29C0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800C29C4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C29C8: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x800C29CC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800C29D0: ori         $t7, $t6, 0x104
    ctx->r15 = ctx->r14 | 0X104;
    // 0x800C29D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C29D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C29DC: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C29E0: addu        $t8, $a3, $t1
    ctx->r24 = ADD32(ctx->r7, ctx->r9);
    // 0x800C29E4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800C29E8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800C29EC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800C29F0: addiu       $a2, $a2, 0x8C
    ctx->r6 = ADD32(ctx->r6, 0X8C);
    // 0x800C29F4: b           L_800C2A40
    // 0x800C29F8: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
        goto L_800C2A40;
    // 0x800C29F8: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
L_800C29FC:
    // 0x800C29FC: andi        $t9, $a0, 0x6
    ctx->r25 = ctx->r4 & 0X6;
    // 0x800C2A00: ori         $t6, $t9, 0x78
    ctx->r14 = ctx->r25 | 0X78;
    // 0x800C2A04: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800C2A08: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800C2A0C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C2A10: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800C2A14: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x800C2A18: ori         $t6, $t9, 0x128
    ctx->r14 = ctx->r25 | 0X128;
    // 0x800C2A1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C2A20: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C2A24: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C2A28: addu        $t7, $a3, $t1
    ctx->r15 = ADD32(ctx->r7, ctx->r9);
    // 0x800C2A2C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800C2A30: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x800C2A34: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800C2A38: addiu       $a2, $a2, 0xA0
    ctx->r6 = ADD32(ctx->r6, 0XA0);
    // 0x800C2A3C: addiu       $a3, $a3, 0xE0
    ctx->r7 = ADD32(ctx->r7, 0XE0);
L_800C2A40:
    // 0x800C2A40: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C2A44: bne         $t0, $ra, L_800C29A4
    if (ctx->r8 != ctx->r31) {
        // 0x800C2A48: nop
    
            goto L_800C29A4;
    }
    // 0x800C2A48: nop

    // 0x800C2A4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C2A50: jal         0x8007B820
    // 0x800C2A54: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C2A54: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    after_1:
    // 0x800C2A58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2A5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C2A60: jr          $ra
    // 0x800C2A64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C2A64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void transition_render_barndoor_diag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2A6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2A70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C2A74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C2A78: jal         0x8007B820
    // 0x800C2A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C2A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C2A80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C2A84: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C2A88: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2A8C: addiu       $t8, $t8, 0x3BD8
    ctx->r24 = ADD32(ctx->r24, 0X3BD8);
    // 0x800C2A90: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C2A94: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C2A98: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C2A9C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C2AA0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C2AA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2AA8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C2AAC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C2AB0: addiu       $a3, $a3, 0x3760
    ctx->r7 = ADD32(ctx->r7, 0X3760);
    // 0x800C2AB4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C2AB8: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800C2ABC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C2AC0: addiu       $t1, $t1, 0x3750
    ctx->r9 = ADD32(ctx->r9, 0X3750);
    // 0x800C2AC4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C2AC8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C2ACC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C2AD0: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800C2AD4: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x800C2AD8: andi        $t7, $t6, 0x6
    ctx->r15 = ctx->r14 & 0X6;
    // 0x800C2ADC: ori         $t8, $t7, 0x48
    ctx->r24 = ctx->r15 | 0X48;
    // 0x800C2AE0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800C2AE4: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800C2AE8: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800C2AEC: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800C2AF0: ori         $t4, $t3, 0xBC
    ctx->r12 = ctx->r11 | 0XBC;
    // 0x800C2AF4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C2AF8: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800C2AFC: lui         $t3, 0x550
    ctx->r11 = S32(0X550 << 16);
    // 0x800C2B00: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C2B04: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800C2B08: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C2B0C: ori         $t3, $t3, 0x60
    ctx->r11 = ctx->r11 | 0X60;
    // 0x800C2B10: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800C2B14: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C2B18: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2B1C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C2B20: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800C2B24: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800C2B28: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C2B2C: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800C2B30: nop

    // 0x800C2B34: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C2B38: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C2B3C: lw          $t6, 0x3758($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3758);
    // 0x800C2B40: nop

    // 0x800C2B44: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800C2B48: jal         0x8007B820
    // 0x800C2B4C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C2B4C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_1:
    // 0x800C2B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2B54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2B58: jr          $ra
    // 0x800C2B5C: nop

    return;
    // 0x800C2B5C: nop

;}
RECOMP_FUNC void transition_init_blank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2B60: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C2B64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C2B68: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C2B6C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C2B70: addiu       $a1, $a1, -0x5300
    ctx->r5 = ADD32(ctx->r5, -0X5300);
    // 0x800C2B74: addiu       $v1, $v1, -0x5308
    ctx->r3 = ADD32(ctx->r3, -0X5308);
    // 0x800C2B78: addiu       $a0, $a0, -0x5304
    ctx->r4 = ADD32(ctx->r4, -0X5304);
    // 0x800C2B7C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C2B80: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800C2B84: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800C2B88: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800C2B8C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C2B90: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800C2B94: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C2B98: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C2B9C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x800C2BA0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800C2BA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2BA8: sb          $t2, -0x5309($at)
    MEM_B(-0X5309, ctx->r1) = ctx->r10;
    // 0x800C2BAC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C2BB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C2BB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2BB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C2BBC: swc1        $f4, -0x52F0($at)
    MEM_W(-0X52F0, ctx->r1) = ctx->f4.u32l;
    // 0x800C2BC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2BC4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C2BC8: lbu         $t3, -0x530C($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X530C);
    // 0x800C2BCC: swc1        $f6, -0x52EC($at)
    MEM_W(-0X52EC, ctx->r1) = ctx->f6.u32l;
    // 0x800C2BD0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C2BD4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C2BD8: lhu         $v0, 0x3740($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3740);
    // 0x800C2BDC: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800C2BE0: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800C2BE4: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800C2BE8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C2BEC: bne         $v0, $zero, L_800C2BF8
    if (ctx->r2 != 0) {
        // 0x800C2BF0: nop
    
            goto L_800C2BF8;
    }
    // 0x800C2BF0: nop

    // 0x800C2BF4: break       7
    do_break(2148281332);
L_800C2BF8:
    // 0x800C2BF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C2BFC: bne         $v0, $at, L_800C2C10
    if (ctx->r2 != ctx->r1) {
        // 0x800C2C00: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C2C10;
    }
    // 0x800C2C00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C2C04: bne         $t6, $at, L_800C2C10
    if (ctx->r14 != ctx->r1) {
        // 0x800C2C08: nop
    
            goto L_800C2C10;
    }
    // 0x800C2C08: nop

    // 0x800C2C0C: break       6
    do_break(2148281356);
L_800C2C10:
    // 0x800C2C10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2C14: lbu         $t8, -0x530B($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X530B);
    // 0x800C2C18: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C2C1C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C2C20: lbu         $t3, -0x530A($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X530A);
    // 0x800C2C24: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C2C28: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800C2C2C: mflo        $t7
    ctx->r15 = lo;
    // 0x800C2C30: sw          $t7, -0x52FC($at)
    MEM_W(-0X52FC, ctx->r1) = ctx->r15;
    // 0x800C2C34: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800C2C38: nop

    // 0x800C2C3C: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800C2C40: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x800C2C44: bne         $v0, $zero, L_800C2C50
    if (ctx->r2 != 0) {
        // 0x800C2C48: nop
    
            goto L_800C2C50;
    }
    // 0x800C2C48: nop

    // 0x800C2C4C: break       7
    do_break(2148281420);
L_800C2C50:
    // 0x800C2C50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C2C54: bne         $v0, $at, L_800C2C68
    if (ctx->r2 != ctx->r1) {
        // 0x800C2C58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C2C68;
    }
    // 0x800C2C58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C2C5C: bne         $t1, $at, L_800C2C68
    if (ctx->r9 != ctx->r1) {
        // 0x800C2C60: nop
    
            goto L_800C2C68;
    }
    // 0x800C2C60: nop

    // 0x800C2C64: break       6
    do_break(2148281444);
L_800C2C68:
    // 0x800C2C68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2C6C: mflo        $t2
    ctx->r10 = lo;
    // 0x800C2C70: sw          $t2, -0x52F8($at)
    MEM_W(-0X52F8, ctx->r1) = ctx->r10;
    // 0x800C2C74: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800C2C78: nop

    // 0x800C2C7C: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800C2C80: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800C2C84: bne         $v0, $zero, L_800C2C90
    if (ctx->r2 != 0) {
        // 0x800C2C88: nop
    
            goto L_800C2C90;
    }
    // 0x800C2C88: nop

    // 0x800C2C8C: break       7
    do_break(2148281484);
L_800C2C90:
    // 0x800C2C90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C2C94: bne         $v0, $at, L_800C2CA8
    if (ctx->r2 != ctx->r1) {
        // 0x800C2C98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C2CA8;
    }
    // 0x800C2C98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C2C9C: bne         $t6, $at, L_800C2CA8
    if (ctx->r14 != ctx->r1) {
        // 0x800C2CA0: nop
    
            goto L_800C2CA8;
    }
    // 0x800C2CA0: nop

    // 0x800C2CA4: break       6
    do_break(2148281508);
L_800C2CA8:
    // 0x800C2CA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2CAC: mflo        $t7
    ctx->r15 = lo;
    // 0x800C2CB0: sw          $t7, -0x52F4($at)
    MEM_W(-0X52F4, ctx->r1) = ctx->r15;
    // 0x800C2CB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2CB8: jr          $ra
    // 0x800C2CBC: sw          $t8, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = ctx->r24;
    return;
    // 0x800C2CBC: sw          $t8, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void transition_update_blank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2CC0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C2CC4: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x800C2CC8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800C2CCC: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800C2CD0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C2CD4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800C2CD8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800C2CDC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800C2CE0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C2CE4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C2CE8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C2CEC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C2CF0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C2CF4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C2CF8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C2CFC: addiu       $a1, $a1, 0x3740
    ctx->r5 = ADD32(ctx->r5, 0X3740);
    // 0x800C2D00: addiu       $a2, $a2, -0x5308
    ctx->r6 = ADD32(ctx->r6, -0X5308);
    // 0x800C2D04: addiu       $a3, $a3, -0x52FC
    ctx->r7 = ADD32(ctx->r7, -0X52FC);
    // 0x800C2D08: addiu       $t0, $t0, -0x5304
    ctx->r8 = ADD32(ctx->r8, -0X5304);
    // 0x800C2D0C: addiu       $t1, $t1, -0x52F8
    ctx->r9 = ADD32(ctx->r9, -0X52F8);
    // 0x800C2D10: addiu       $t2, $t2, -0x5300
    ctx->r10 = ADD32(ctx->r10, -0X5300);
    // 0x800C2D14: addiu       $t3, $t3, -0x52F4
    ctx->r11 = ADD32(ctx->r11, -0X52F4);
    // 0x800C2D18: addiu       $t4, $t4, -0x530C
    ctx->r12 = ADD32(ctx->r12, -0X530C);
    // 0x800C2D1C: addiu       $t5, $t5, -0x530B
    ctx->r13 = ADD32(ctx->r13, -0X530B);
    // 0x800C2D20: addiu       $s2, $s2, 0x3744
    ctx->r18 = ADD32(ctx->r18, 0X3744);
    // 0x800C2D24: addiu       $s0, $s0, -0x530A
    ctx->r16 = ADD32(ctx->r16, -0X530A);
    // 0x800C2D28: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x800C2D2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C2D30:
    // 0x800C2D30: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800C2D34: nop

    // 0x800C2D38: blez        $v1, L_800C2DCC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C2D3C: nop
    
            goto L_800C2DCC;
    }
    // 0x800C2D3C: nop

    // 0x800C2D40: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800C2D44: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C2D48: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C2D4C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800C2D50: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C2D54: mflo        $t8
    ctx->r24 = lo;
    // 0x800C2D58: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800C2D5C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800C2D60: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800C2D64: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C2D68: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800C2D6C: mflo        $t8
    ctx->r24 = lo;
    // 0x800C2D70: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C2D74: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800C2D78: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C2D7C: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C2D80: mflo        $t8
    ctx->r24 = lo;
    // 0x800C2D84: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800C2D88: bne         $at, $zero, L_800C2DC0
    if (ctx->r1 != 0) {
        // 0x800C2D8C: sw          $t9, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r25;
            goto L_800C2DC0;
    }
    // 0x800C2D8C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800C2D90: lbu         $t7, 0x0($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X0);
    // 0x800C2D94: lbu         $t8, 0x0($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X0);
    // 0x800C2D98: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800C2D9C: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x800C2DA0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800C2DA4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C2DA8: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800C2DAC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C2DB0: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800C2DB4: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800C2DB8: b           L_800C2DEC
    // 0x800C2DBC: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
        goto L_800C2DEC;
    // 0x800C2DBC: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_800C2DC0:
    // 0x800C2DC0: subu        $t8, $v1, $a0
    ctx->r24 = SUB32(ctx->r3, ctx->r4);
    // 0x800C2DC4: b           L_800C2DEC
    // 0x800C2DC8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
        goto L_800C2DEC;
    // 0x800C2DC8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
L_800C2DCC:
    // 0x800C2DCC: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x800C2DD0: nop

    // 0x800C2DD4: beq         $s1, $v1, L_800C2DEC
    if (ctx->r17 == ctx->r3) {
        // 0x800C2DD8: subu        $t9, $v1, $a0
        ctx->r25 = SUB32(ctx->r3, ctx->r4);
            goto L_800C2DEC;
    }
    // 0x800C2DD8: subu        $t9, $v1, $a0
    ctx->r25 = SUB32(ctx->r3, ctx->r4);
    // 0x800C2DDC: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800C2DE0: bgtz        $t7, L_800C2DEC
    if (SIGNED(ctx->r15) > 0) {
        // 0x800C2DE4: sh          $t9, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r25;
            goto L_800C2DEC;
    }
    // 0x800C2DE4: sh          $t9, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r25;
    // 0x800C2DE8: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
L_800C2DEC:
    // 0x800C2DEC: beq         $v0, $zero, L_800C2D30
    if (ctx->r2 == 0) {
        // 0x800C2DF0: nop
    
            goto L_800C2D30;
    }
    // 0x800C2DF0: nop

    // 0x800C2DF4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800C2DF8: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x800C2DFC: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x800C2E00: jr          $ra
    // 0x800C2E04: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C2E04: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void transition_render_blank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2E08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2E10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C2E14: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C2E18: jal         0x8007A970
    // 0x800C2E1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800C2E1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C2E20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C2E24: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C2E28: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C2E2C: addiu       $t8, $t8, 0x3768
    ctx->r24 = ADD32(ctx->r24, 0X3768);
    // 0x800C2E30: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C2E34: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C2E38: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C2E3C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C2E40: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C2E44: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C2E48: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800C2E4C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C2E50: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C2E54: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C2E58: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800C2E5C: lw          $t2, -0x5308($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5308);
    // 0x800C2E60: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C2E64: sra         $t4, $t2, 16
    ctx->r12 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800C2E68: lw          $t6, -0x5304($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5304);
    // 0x800C2E6C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C2E70: lw          $t2, -0x5300($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5300);
    // 0x800C2E74: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C2E78: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800C2E7C: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x800C2E80: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800C2E84: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800C2E88: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C2E8C: or          $t1, $t5, $t9
    ctx->r9 = ctx->r13 | ctx->r25;
    // 0x800C2E90: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x800C2E94: or          $t7, $t1, $t6
    ctx->r15 = ctx->r9 | ctx->r14;
    // 0x800C2E98: ori         $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 | 0XFF;
    // 0x800C2E9C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C2EA0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C2EA4: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800C2EA8: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800C2EAC: lui         $t2, 0xFFFD
    ctx->r10 = S32(0XFFFD << 16);
    // 0x800C2EB0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800C2EB4: ori         $t2, $t2, 0xF6FB
    ctx->r10 = ctx->r10 | 0XF6FB;
    // 0x800C2EB8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800C2EBC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C2EC0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800C2EC4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C2EC8: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C2ECC: andi        $t1, $v0, 0x3FF
    ctx->r9 = ctx->r2 & 0X3FF;
    // 0x800C2ED0: sll         $t6, $t1, 14
    ctx->r14 = S32(ctx->r9 << 14);
    // 0x800C2ED4: andi        $t9, $t5, 0x3FF
    ctx->r25 = ctx->r13 & 0X3FF;
    // 0x800C2ED8: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800C2EDC: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800C2EE0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800C2EE4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800C2EE8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800C2EEC: or          $t3, $t7, $t2
    ctx->r11 = ctx->r15 | ctx->r10;
    // 0x800C2EF0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800C2EF4: jal         0x8007B820
    // 0x800C2EF8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C2EF8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    after_1:
    // 0x800C2EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2F00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2F04: jr          $ra
    // 0x800C2F08: nop

    return;
    // 0x800C2F08: nop

    // 0x800C2F0C: nop

;}
RECOMP_FUNC void init_dialogue_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2F18: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800C2F1C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C2F20: jal         0x80070EDC
    // 0x800C2F24: addiu       $a0, $zero, 0x780
    ctx->r4 = ADD32(0, 0X780);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C2F24: addiu       $a0, $zero, 0x780
    ctx->r4 = ADD32(0, 0X780);
    after_0:
    // 0x800C2F28: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C2F2C: addiu       $v1, $v1, -0x5278
    ctx->r3 = ADD32(ctx->r3, -0X5278);
    // 0x800C2F30: addiu       $t7, $v0, 0x3C0
    ctx->r15 = ADD32(ctx->r2, 0X3C0);
    // 0x800C2F34: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800C2F38: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800C2F3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F40: sw          $zero, -0x526C($at)
    MEM_W(-0X526C, ctx->r1) = 0;
    // 0x800C2F44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F48: sh          $zero, -0x528A($at)
    MEM_H(-0X528A, ctx->r1) = 0;
    // 0x800C2F4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F50: sh          $zero, -0x5298($at)
    MEM_H(-0X5298, ctx->r1) = 0;
    // 0x800C2F54: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x800C2F58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F5C: sh          $a0, -0x5296($at)
    MEM_H(-0X5296, ctx->r1) = ctx->r4;
    // 0x800C2F60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F64: sh          $zero, -0x5286($at)
    MEM_H(-0X5286, ctx->r1) = 0;
    // 0x800C2F68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F6C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800C2F70: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x800C2F74: sh          $a0, -0x5292($at)
    MEM_H(-0X5292, ctx->r1) = ctx->r4;
    // 0x800C2F78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F7C: addiu       $t8, $zero, 0x120
    ctx->r24 = ADD32(0, 0X120);
    // 0x800C2F80: bne         $t9, $zero, L_800C2FA4
    if (ctx->r25 != 0) {
        // 0x800C2F84: sh          $t8, -0x528E($at)
        MEM_H(-0X528E, ctx->r1) = ctx->r24;
            goto L_800C2FA4;
    }
    // 0x800C2F84: sh          $t8, -0x528E($at)
    MEM_H(-0X528E, ctx->r1) = ctx->r24;
    // 0x800C2F88: addiu       $t0, $zero, 0xE0
    ctx->r8 = ADD32(0, 0XE0);
    // 0x800C2F8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F90: sh          $t0, -0x5290($at)
    MEM_H(-0X5290, ctx->r1) = ctx->r8;
    // 0x800C2F94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F98: addiu       $t1, $zero, 0xF8
    ctx->r9 = ADD32(0, 0XF8);
    // 0x800C2F9C: b           L_800C2FBC
    // 0x800C2FA0: sh          $t1, -0x528C($at)
    MEM_H(-0X528C, ctx->r1) = ctx->r9;
        goto L_800C2FBC;
    // 0x800C2FA0: sh          $t1, -0x528C($at)
    MEM_H(-0X528C, ctx->r1) = ctx->r9;
L_800C2FA4:
    // 0x800C2FA4: addiu       $t2, $zero, 0xCA
    ctx->r10 = ADD32(0, 0XCA);
    // 0x800C2FA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2FAC: sh          $t2, -0x5290($at)
    MEM_H(-0X5290, ctx->r1) = ctx->r10;
    // 0x800C2FB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2FB4: addiu       $t3, $zero, 0xDE
    ctx->r11 = ADD32(0, 0XDE);
    // 0x800C2FB8: sh          $t3, -0x528C($at)
    MEM_H(-0X528C, ctx->r1) = ctx->r11;
L_800C2FBC:
    // 0x800C2FBC: jal         0x800C5C30
    // 0x800C2FC0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_1;
    // 0x800C2FC0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x800C2FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2FCC: jr          $ra
    // 0x800C2FD0: nop

    return;
    // 0x800C2FD0: nop

;}
RECOMP_FUNC void free_message_box(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2FD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2FD8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C2FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2FE0: lw          $a0, -0x5278($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5278);
    // 0x800C2FE4: jal         0x80071380
    // 0x800C2FE8: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800C2FE8: nop

    after_0:
    // 0x800C2FEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2FF0: sh          $zero, -0x528A($at)
    MEM_H(-0X528A, ctx->r1) = 0;
    // 0x800C2FF4: jal         0x800C5B80
    // 0x800C2FF8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_close(rdram, ctx);
        goto after_1;
    // 0x800C2FF8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x800C2FFC: jal         0x800C59F4
    // 0x800C3000: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_2;
    // 0x800C3000: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_2:
    // 0x800C3004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3008: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C300C: jr          $ra
    // 0x800C3010: nop

    return;
    // 0x800C3010: nop

;}
RECOMP_FUNC void set_subtitles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3014: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C3018: jr          $ra
    // 0x800C301C: sw          $a0, 0x3C10($at)
    MEM_W(0X3C10, ctx->r1) = ctx->r4;
    return;
    // 0x800C301C: sw          $a0, 0x3C10($at)
    MEM_W(0X3C10, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void render_subtitles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3020: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C3024: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C3028: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C302C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C3030: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C3034: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C3038: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C303C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C3040: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C3044: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C3048: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C304C: jal         0x800C59F4
    // 0x800C3050: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_0;
    // 0x800C3050: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x800C3054: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C3058: lh          $t6, -0x5288($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X5288);
    // 0x800C305C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C3060: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800C3064: bne         $at, $zero, L_800C3084
    if (ctx->r1 != 0) {
        // 0x800C3068: addiu       $s1, $s1, -0x528C
        ctx->r17 = ADD32(ctx->r17, -0X528C);
            goto L_800C3084;
    }
    // 0x800C3068: addiu       $s1, $s1, -0x528C
    ctx->r17 = ADD32(ctx->r17, -0X528C);
    // 0x800C306C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3070: addiu       $s0, $s0, -0x5290
    ctx->r16 = ADD32(ctx->r16, -0X5290);
    // 0x800C3074: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800C3078: nop

    // 0x800C307C: addiu       $t8, $t7, -0xE
    ctx->r24 = ADD32(ctx->r15, -0XE);
    // 0x800C3080: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800C3084:
    // 0x800C3084: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3088: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800C308C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800C3090: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x800C3094: addiu       $s7, $s7, -0x528E
    ctx->r23 = ADD32(ctx->r23, -0X528E);
    // 0x800C3098: addiu       $s6, $s6, -0x5292
    ctx->r22 = ADD32(ctx->r22, -0X5292);
    // 0x800C309C: addiu       $s0, $s0, -0x5290
    ctx->r16 = ADD32(ctx->r16, -0X5290);
    // 0x800C30A0: lh          $a2, 0x0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X0);
    // 0x800C30A4: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    // 0x800C30A8: lh          $a3, 0x0($s7)
    ctx->r7 = MEM_H(ctx->r23, 0X0);
    // 0x800C30AC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C30B0: jal         0x800C543C
    // 0x800C30B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x800C30B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x800C30B8: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800C30BC: addiu       $s5, $s5, -0x5298
    ctx->r21 = ADD32(ctx->r21, -0X5298);
    // 0x800C30C0: lh          $t0, 0x0($s5)
    ctx->r8 = MEM_H(ctx->r21, 0X0);
    // 0x800C30C4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C30C8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800C30CC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C30D0: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C30D4: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x800C30D8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800C30DC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800C30E0: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x800C30E4: jal         0x800C551C
    // 0x800C30E8: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_2;
    // 0x800C30E8: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_2:
    // 0x800C30EC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C30F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C30F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C30F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C30FC: jal         0x800C55B0
    // 0x800C3100: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_3;
    // 0x800C3100: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x800C3104: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C3108: lh          $v0, -0x5288($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5288);
    // 0x800C310C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x800C3110: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    // 0x800C3114: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800C3118: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x800C311C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800C3120: subu        $t4, $t3, $v1
    ctx->r12 = SUB32(ctx->r11, ctx->r3);
    // 0x800C3124: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800C3128: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800C312C: subu        $s3, $t6, $t7
    ctx->r19 = SUB32(ctx->r14, ctx->r15);
    // 0x800C3130: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800C3134: sra         $t8, $s3, 1
    ctx->r24 = S32(SIGNED(ctx->r19) >> 1);
    // 0x800C3138: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800C313C: bne         $at, $zero, L_800C314C
    if (ctx->r1 != 0) {
        // 0x800C3140: or          $s3, $t8, $zero
        ctx->r19 = ctx->r24 | 0;
            goto L_800C314C;
    }
    // 0x800C3140: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x800C3144: addiu       $t9, $v1, 0xE
    ctx->r25 = ADD32(ctx->r3, 0XE);
    // 0x800C3148: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
L_800C314C:
    // 0x800C314C: blez        $v0, L_800C328C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C3150: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800C328C;
    }
    // 0x800C3150: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C3154: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C3158: addiu       $s2, $s2, -0x5280
    ctx->r18 = ADD32(ctx->r18, -0X5280);
    // 0x800C315C: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
L_800C3160:
    // 0x800C3160: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x800C3164: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C3168: lbu         $a1, 0x5($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X5);
    // 0x800C316C: jal         0x800C54DC
    // 0x800C3170: nop

    set_dialogue_font(rdram, ctx);
        goto after_4;
    // 0x800C3170: nop

    after_4:
    // 0x800C3174: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800C3178: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C317C: lbu         $s0, 0x6($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X6);
    // 0x800C3180: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800C3184: bne         $s0, $fp, L_800C31A8
    if (ctx->r16 != ctx->r30) {
        // 0x800C3188: nop
    
            goto L_800C31A8;
    }
    // 0x800C3188: nop

    // 0x800C318C: lh          $t1, 0x0($s7)
    ctx->r9 = MEM_H(ctx->r23, 0X0);
    // 0x800C3190: lh          $t2, 0x0($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X0);
    // 0x800C3194: nop

    // 0x800C3198: subu        $s1, $t1, $t2
    ctx->r17 = SUB32(ctx->r9, ctx->r10);
    // 0x800C319C: sra         $t3, $s1, 1
    ctx->r11 = S32(SIGNED(ctx->r17) >> 1);
    // 0x800C31A0: b           L_800C31C8
    // 0x800C31A4: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
        goto L_800C31C8;
    // 0x800C31A4: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
L_800C31A8:
    // 0x800C31A8: bne         $s0, $at, L_800C31C8
    if (ctx->r16 != ctx->r1) {
        // 0x800C31AC: addiu       $s1, $zero, 0x8
        ctx->r17 = ADD32(0, 0X8);
            goto L_800C31C8;
    }
    // 0x800C31AC: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x800C31B0: lh          $t4, 0x0($s7)
    ctx->r12 = MEM_H(ctx->r23, 0X0);
    // 0x800C31B4: lh          $t5, 0x0($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X0);
    // 0x800C31B8: nop

    // 0x800C31BC: subu        $s1, $t4, $t5
    ctx->r17 = SUB32(ctx->r12, ctx->r13);
    // 0x800C31C0: b           L_800C31C8
    // 0x800C31C4: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
        goto L_800C31C8;
    // 0x800C31C4: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
L_800C31C8:
    // 0x800C31C8: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x800C31CC: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    // 0x800C31D0: lbu         $a3, 0x3($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X3);
    // 0x800C31D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C31D8: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800C31DC: lh          $t8, 0x0($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X0);
    // 0x800C31E0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C31E4: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C31E8: mflo        $t9
    ctx->r25 = lo;
    // 0x800C31EC: sra         $t0, $t9, 8
    ctx->r8 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800C31F0: jal         0x800C5560
    // 0x800C31F4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    set_current_text_colour(rdram, ctx);
        goto after_5;
    // 0x800C31F4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_5:
    // 0x800C31F8: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800C31FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C3200: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800C3204: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C3208: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C320C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800C3210: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C3214: jal         0x800C56C8
    // 0x800C3218: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    render_dialogue_text(rdram, ctx);
        goto after_6;
    // 0x800C3218: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_6:
    // 0x800C321C: lh          $t3, 0x0($s5)
    ctx->r11 = MEM_H(ctx->r21, 0X0);
    // 0x800C3220: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800C3224: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x800C3228: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800C322C: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800C3230: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800C3234: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800C3238: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C323C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C3240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C3244: jal         0x800C5560
    // 0x800C3248: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_text_colour(rdram, ctx);
        goto after_7;
    // 0x800C3248: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x800C324C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800C3250: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C3254: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C3258: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C325C: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x800C3260: addiu       $a2, $s3, 0x1
    ctx->r6 = ADD32(ctx->r19, 0X1);
    // 0x800C3264: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C3268: jal         0x800C56C8
    // 0x800C326C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    render_dialogue_text(rdram, ctx);
        goto after_8;
    // 0x800C326C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_8:
    // 0x800C3270: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C3274: lh          $t7, -0x5288($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X5288);
    // 0x800C3278: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C327C: slt         $at, $s4, $t7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C3280: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C3284: bne         $at, $zero, L_800C3160
    if (ctx->r1 != 0) {
        // 0x800C3288: addiu       $s3, $s3, 0xE
        ctx->r19 = ADD32(ctx->r19, 0XE);
            goto L_800C3160;
    }
    // 0x800C3288: addiu       $s3, $s3, 0xE
    ctx->r19 = ADD32(ctx->r19, 0XE);
L_800C328C:
    // 0x800C328C: jal         0x800C5B54
    // 0x800C3290: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    open_dialogue_box(rdram, ctx);
        goto after_9;
    // 0x800C3290: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
    // 0x800C3294: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C3298: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C329C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C32A0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C32A4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C32A8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C32AC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C32B0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C32B4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C32B8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C32BC: jr          $ra
    // 0x800C32C0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C32C0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void find_next_subtitle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C32C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C32C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C32CC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C32D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C32D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C32D8: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C32DC: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800C32E0: addiu       $s1, $s1, -0x5270
    ctx->r17 = ADD32(ctx->r17, -0X5270);
    // 0x800C32E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C32E8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C32EC: addiu       $s4, $s4, -0x5294
    ctx->r20 = ADD32(ctx->r20, -0X5294);
    // 0x800C32F0: addiu       $s3, $s3, -0x5288
    ctx->r19 = ADD32(ctx->r19, -0X5288);
    // 0x800C32F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C32F8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800C32FC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800C3300: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C3304: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C3308: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C330C: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
    // 0x800C3310: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x800C3314: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3318: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C331C: beq         $v0, $zero, L_800C3430
    if (ctx->r2 == 0) {
        // 0x800C3320: addiu       $fp, $zero, 0xA
        ctx->r30 = ADD32(0, 0XA);
            goto L_800C3430;
    }
    // 0x800C3320: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x800C3324: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800C3328: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800C332C: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    // 0x800C3330: addiu       $s5, $s5, -0x5286
    ctx->r21 = ADD32(ctx->r21, -0X5286);
    // 0x800C3334: addiu       $s6, $s6, -0x5280
    ctx->r22 = ADD32(ctx->r22, -0X5280);
    // 0x800C3338: addiu       $s7, $zero, 0x6
    ctx->r23 = ADD32(0, 0X6);
    // 0x800C333C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
L_800C3340:
    // 0x800C3340: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800C3344: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x800C3348: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
    // 0x800C334C: sw          $s0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r16;
    // 0x800C3350: lbu         $t9, 0x7($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7);
    // 0x800C3354: nop

    // 0x800C3358: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C335C: mflo        $a0
    ctx->r4 = lo;
    // 0x800C3360: jal         0x8000C8B4
    // 0x800C3364: nop

    normalise_time(rdram, ctx);
        goto after_0;
    // 0x800C3364: nop

    after_0:
    // 0x800C3368: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800C336C: sh          $v0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r2;
    // 0x800C3370: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800C3374: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x800C3378: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C337C: nop

    // 0x800C3380: andi        $t2, $v1, 0x80
    ctx->r10 = ctx->r3 & 0X80;
L_800C3384:
    // 0x800C3384: beq         $t2, $zero, L_800C3398
    if (ctx->r10 == 0) {
        // 0x800C3388: addiu       $t4, $s0, 0x1
        ctx->r12 = ADD32(ctx->r16, 0X1);
            goto L_800C3398;
    }
    // 0x800C3388: addiu       $t4, $s0, 0x1
    ctx->r12 = ADD32(ctx->r16, 0X1);
    // 0x800C338C: addiu       $t3, $s0, 0x2
    ctx->r11 = ADD32(ctx->r16, 0X2);
    // 0x800C3390: b           L_800C339C
    // 0x800C3394: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
        goto L_800C339C;
    // 0x800C3394: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
L_800C3398:
    // 0x800C3398: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
L_800C339C:
    // 0x800C339C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C33A0: nop

    // 0x800C33A4: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C33A8: nop

    // 0x800C33AC: bne         $v1, $zero, L_800C3384
    if (ctx->r3 != 0) {
        // 0x800C33B0: andi        $t2, $v1, 0x80
        ctx->r10 = ctx->r3 & 0X80;
            goto L_800C3384;
    }
    // 0x800C33B0: andi        $t2, $v1, 0x80
    ctx->r10 = ctx->r3 & 0X80;
    // 0x800C33B4: lh          $t5, 0x0($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X0);
    // 0x800C33B8: addiu       $t7, $s0, 0x1
    ctx->r15 = ADD32(ctx->r16, 0X1);
    // 0x800C33BC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800C33C0: sh          $t6, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r14;
    // 0x800C33C4: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    // 0x800C33C8: nop

    // 0x800C33CC: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x800C33D0: bne         $at, $zero, L_800C33DC
    if (ctx->r1 != 0) {
        // 0x800C33D4: nop
    
            goto L_800C33DC;
    }
    // 0x800C33D4: nop

    // 0x800C33D8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800C33DC:
    // 0x800C33DC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C33E0: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800C33E4: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800C33E8: bne         $fp, $v0, L_800C3404
    if (ctx->r30 != ctx->r2) {
        // 0x800C33EC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C3404;
    }
    // 0x800C33EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C33F0: addiu       $s0, $t7, 0x1
    ctx->r16 = ADD32(ctx->r15, 0X1);
    // 0x800C33F4: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x800C33F8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C33FC: b           L_800C3420
    // 0x800C3400: nop

        goto L_800C3420;
    // 0x800C3400: nop

L_800C3404:
    // 0x800C3404: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800C3408: bne         $v1, $at, L_800C3420
    if (ctx->r3 != ctx->r1) {
        // 0x800C340C: addiu       $t9, $s0, 0x1
        ctx->r25 = ADD32(ctx->r16, 0X1);
            goto L_800C3420;
    }
    // 0x800C340C: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
    // 0x800C3410: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C3414: lbu         $v0, 0x0($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X0);
    // 0x800C3418: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800C341C: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_800C3420:
    // 0x800C3420: beq         $v0, $zero, L_800C3430
    if (ctx->r2 == 0) {
        // 0x800C3424: nop
    
            goto L_800C3430;
    }
    // 0x800C3424: nop

    // 0x800C3428: beq         $s2, $zero, L_800C3340
    if (ctx->r18 == 0) {
        // 0x800C342C: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_800C3340;
    }
    // 0x800C342C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
L_800C3430:
    // 0x800C3430: lh          $t0, 0x0($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X0);
    // 0x800C3434: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C3438: blez        $t0, L_800C3444
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800C343C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800C3444;
    }
    // 0x800C343C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3440: sh          $t1, -0x528A($at)
    MEM_H(-0X528A, ctx->r1) = ctx->r9;
L_800C3444:
    // 0x800C3444: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C3448: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C344C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3450: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C3454: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C3458: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C345C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C3460: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C3464: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800C3468: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800C346C: jr          $ra
    // 0x800C3470: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C3470: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void process_subtitles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3474: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C3478: lw          $t6, 0x3C10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3C10);
    // 0x800C347C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3484: bne         $t6, $zero, L_800C3498
    if (ctx->r14 != 0) {
        // 0x800C3488: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800C3498;
    }
    // 0x800C3488: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800C348C: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C3490: addiu       $a3, $a3, -0x528A
    ctx->r7 = ADD32(ctx->r7, -0X528A);
    // 0x800C3494: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
L_800C3498:
    // 0x800C3498: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C349C: addiu       $a3, $a3, -0x528A
    ctx->r7 = ADD32(ctx->r7, -0X528A);
    // 0x800C34A0: lh          $a0, 0x0($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X0);
    // 0x800C34A4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C34A8: beq         $a0, $zero, L_800C3580
    if (ctx->r4 == 0) {
        // 0x800C34AC: addiu       $a2, $a2, -0x5294
        ctx->r6 = ADD32(ctx->r6, -0X5294);
            goto L_800C3580;
    }
    // 0x800C34AC: addiu       $a2, $a2, -0x5294
    ctx->r6 = ADD32(ctx->r6, -0X5294);
    // 0x800C34B0: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x800C34B4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C34B8: bgtz        $v1, L_800C351C
    if (SIGNED(ctx->r3) > 0) {
        // 0x800C34BC: subu        $t7, $v1, $a1
        ctx->r15 = SUB32(ctx->r3, ctx->r5);
            goto L_800C351C;
    }
    // 0x800C34BC: subu        $t7, $v1, $a1
    ctx->r15 = SUB32(ctx->r3, ctx->r5);
    // 0x800C34C0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C34C4: lh          $t8, -0x5296($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X5296);
    // 0x800C34C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C34CC: multu       $a1, $t8
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C34D0: addiu       $v0, $v0, -0x5298
    ctx->r2 = ADD32(ctx->r2, -0X5298);
    // 0x800C34D4: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800C34D8: mflo        $t9
    ctx->r25 = lo;
    // 0x800C34DC: subu        $t0, $t7, $t9
    ctx->r8 = SUB32(ctx->r15, ctx->r25);
    // 0x800C34E0: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x800C34E4: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800C34E8: nop

    // 0x800C34EC: bgez        $t1, L_800C3580
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800C34F0: nop
    
            goto L_800C3580;
    }
    // 0x800C34F0: nop

    // 0x800C34F4: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800C34F8: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x800C34FC: jal         0x800C5B80
    // 0x800C3500: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_close(rdram, ctx);
        goto after_0;
    // 0x800C3500: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x800C3504: jal         0x800C59F4
    // 0x800C3508: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_1;
    // 0x800C3508: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x800C350C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3510: lh          $a0, -0x528A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X528A);
    // 0x800C3514: b           L_800C3580
    // 0x800C3518: nop

        goto L_800C3580;
    // 0x800C3518: nop

L_800C351C:
    // 0x800C351C: lh          $t3, -0x5296($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X5296);
    // 0x800C3520: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C3524: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C3528: addiu       $v0, $v0, -0x5298
    ctx->r2 = ADD32(ctx->r2, -0X5298);
    // 0x800C352C: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800C3530: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x800C3534: mflo        $t4
    ctx->r12 = lo;
    // 0x800C3538: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800C353C: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x800C3540: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800C3544: nop

    // 0x800C3548: slti        $at, $t6, 0x101
    ctx->r1 = SIGNED(ctx->r14) < 0X101 ? 1 : 0;
    // 0x800C354C: bne         $at, $zero, L_800C3558
    if (ctx->r1 != 0) {
        // 0x800C3550: nop
    
            goto L_800C3558;
    }
    // 0x800C3550: nop

    // 0x800C3554: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
L_800C3558:
    // 0x800C3558: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x800C355C: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800C3560: nop

    // 0x800C3564: bgtz        $t9, L_800C3580
    if (SIGNED(ctx->r25) > 0) {
        // 0x800C3568: nop
    
            goto L_800C3580;
    }
    // 0x800C3568: nop

    // 0x800C356C: jal         0x800C32C4
    // 0x800C3570: nop

    find_next_subtitle(rdram, ctx);
        goto after_2;
    // 0x800C3570: nop

    after_2:
    // 0x800C3574: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3578: lh          $a0, -0x528A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X528A);
    // 0x800C357C: nop

L_800C3580:
    // 0x800C3580: beq         $a0, $zero, L_800C3594
    if (ctx->r4 == 0) {
        // 0x800C3584: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C3594;
    }
    // 0x800C3584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3588: jal         0x800C3020
    // 0x800C358C: nop

    render_subtitles(rdram, ctx);
        goto after_3;
    // 0x800C358C: nop

    after_3:
    // 0x800C3590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C3594:
    // 0x800C3594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3598: jr          $ra
    // 0x800C359C: nop

    return;
    // 0x800C359C: nop

;}
RECOMP_FUNC void load_game_text_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C35A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C35A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C35A8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800C35AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C35B0: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800C35B4: sh          $t6, -0x52B4($at)
    MEM_H(-0X52B4, ctx->r1) = ctx->r14;
    // 0x800C35B8: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C35BC: jal         0x80070EDC
    // 0x800C35C0: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C35C0: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    after_0:
    // 0x800C35C4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C35C8: addiu       $v1, $v1, -0x52A8
    ctx->r3 = ADD32(ctx->r3, -0X52A8);
    // 0x800C35CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C35D0: addiu       $t8, $v0, 0x80
    ctx->r24 = ADD32(ctx->r2, 0X80);
    // 0x800C35D4: addiu       $a0, $a0, -0x52C0
    ctx->r4 = ADD32(ctx->r4, -0X52C0);
    // 0x800C35D8: addiu       $t0, $t8, 0x3C0
    ctx->r8 = ADD32(ctx->r24, 0X3C0);
    // 0x800C35DC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C35E0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C35E4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800C35E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C35EC: jal         0x800C2F10
    // 0x800C35F0: sw          $zero, -0x529C($at)
    MEM_W(-0X529C, ctx->r1) = 0;
    init_dialogue_text(rdram, ctx);
        goto after_1;
    // 0x800C35F0: sw          $zero, -0x529C($at)
    MEM_W(-0X529C, ctx->r1) = 0;
    after_1:
    // 0x800C35F4: jal         0x800772DC
    // 0x800C35F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    asset_table_size(rdram, ctx);
        goto after_2;
    // 0x800C35F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x800C35FC: sra         $t1, $v0, 2
    ctx->r9 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800C3600: addiu       $t2, $t1, -0x2
    ctx->r10 = ADD32(ctx->r9, -0X2);
    // 0x800C3604: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C360C: sh          $t2, -0x52B0($at)
    MEM_H(-0X52B0, ctx->r1) = ctx->r10;
    // 0x800C3610: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C3614: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C3618: sb          $t3, 0x3C00($at)
    MEM_B(0X3C00, ctx->r1) = ctx->r11;
    // 0x800C361C: jr          $ra
    // 0x800C3620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C3620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
