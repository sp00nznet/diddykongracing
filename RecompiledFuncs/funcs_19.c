#include "recomp.h"
#include "funcs.h"
#include <stdio.h>

RECOMP_FUNC void default_alloc_displaylist_heap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F21C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8006F220: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006F224: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8006F228: lw          $t5, -0x26C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X26C4);
    // 0x8006F22C: lw          $t9, -0x26D4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26D4);
    // 0x8006F230: lw          $t7, -0x26A4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26A4);
    // 0x8006F234: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8006F238: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F23C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006F240: lw          $t2, -0x26B4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X26B4);
    // 0x8006F244: sw          $t6, 0x3A8C($at)
    MEM_W(0X3A8C, ctx->r1) = ctx->r14;
    // 0x8006F248: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006F24C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8006F250: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8006F254: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8006F258: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8006F25C: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x8006F260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006F264: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8006F268: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8006F26C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F270: addu        $a0, $t4, $t6
    ctx->r4 = ADD32(ctx->r12, ctx->r14);
    // 0x8006F274: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8006F278: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006F27C: jal         0x80070EDC
    // 0x8006F280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8006F280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006F284: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006F288: addiu       $v1, $v1, 0x1770
    ctx->r3 = ADD32(ctx->r3, 0X1770);
    // 0x8006F28C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8006F290: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8006F294: lw          $t7, -0x26D4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26D4);
    // 0x8006F298: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006F29C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8006F2A0: lw          $t2, -0x26B4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X26B4);
    // 0x8006F2A4: lw          $t5, -0x26C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X26C4);
    // 0x8006F2A8: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8006F2AC: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8006F2B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F2B4: sw          $t0, 0x1780($at)
    MEM_W(0X1780, ctx->r1) = ctx->r8;
    // 0x8006F2B8: sll         $t1, $t2, 6
    ctx->r9 = S32(ctx->r10 << 6);
    // 0x8006F2BC: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8006F2C0: addu        $t3, $t1, $t0
    ctx->r11 = ADD32(ctx->r9, ctx->r8);
    // 0x8006F2C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F2C8: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006F2CC: sw          $t3, 0x1790($at)
    MEM_W(0X1790, ctx->r1) = ctx->r11;
    // 0x8006F2D0: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8006F2D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006F2D8: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x8006F2DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F2E0: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006F2E4: sw          $t6, 0x17A0($at)
    MEM_W(0X17A0, ctx->r1) = ctx->r14;
    // 0x8006F2E8: jal         0x80070EDC
    // 0x8006F2EC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8006F2EC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_1:
    // 0x8006F2F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F2F4: lw          $a0, -0x26D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26D4);
    // 0x8006F2F8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006F2FC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8006F300: lw          $a2, -0x26C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X26C4);
    // 0x8006F304: lw          $a1, -0x26B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X26B4);
    // 0x8006F308: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006F30C: addiu       $v1, $v1, 0x1770
    ctx->r3 = ADD32(ctx->r3, 0X1770);
    // 0x8006F310: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8006F314: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8006F318: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8006F31C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F320: sw          $t8, 0x1784($at)
    MEM_W(0X1784, ctx->r1) = ctx->r24;
    // 0x8006F324: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8006F328: sll         $t2, $a1, 6
    ctx->r10 = S32(ctx->r5 << 6);
    // 0x8006F32C: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x8006F330: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F334: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8006F338: sw          $t1, 0x1794($at)
    MEM_W(0X1794, ctx->r1) = ctx->r9;
    // 0x8006F33C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8006F340: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x8006F344: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F348: sw          $t5, 0x17A4($at)
    MEM_W(0X17A4, ctx->r1) = ctx->r13;
    // 0x8006F34C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F350: sw          $a0, 0x3AA8($at)
    MEM_W(0X3AA8, ctx->r1) = ctx->r4;
    // 0x8006F354: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F358: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8006F35C: lw          $t4, -0x26A4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X26A4);
    // 0x8006F360: sw          $a1, 0x3AAC($at)
    MEM_W(0X3AAC, ctx->r1) = ctx->r5;
    // 0x8006F364: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F36C: sw          $t4, 0x3AB0($at)
    MEM_W(0X3AB0, ctx->r1) = ctx->r12;
    // 0x8006F370: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F374: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006F378: jr          $ra
    // 0x8006F37C: sw          $a2, 0x3AB4($at)
    MEM_W(0X3AB4, ctx->r1) = ctx->r6;
    return;
    // 0x8006F37C: sw          $a2, 0x3AB4($at)
    MEM_W(0X3AB4, ctx->r1) = ctx->r6;
;}
RECOMP_FUNC void level_transition_begin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F380: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F384: addiu       $v0, $v0, -0x26FC
    ctx->r2 = ADD32(ctx->r2, -0X26FC);
    // 0x8006F388: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8006F38C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F394: bne         $t6, $zero, L_8006F43C
    if (ctx->r14 != 0) {
        // 0x8006F398: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8006F43C;
    }
    // 0x8006F398: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006F39C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8006F3A0: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8006F3A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F3A8: sb          $zero, 0x3AA4($at)
    MEM_B(0X3AA4, ctx->r1) = 0;
    // 0x8006F3AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F3B0: sb          $zero, 0x3AA6($at)
    MEM_B(0X3AA6, ctx->r1) = 0;
    // 0x8006F3B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006F3B8: bne         $a0, $at, L_8006F3D8
    if (ctx->r4 != ctx->r1) {
        // 0x8006F3BC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006F3D8;
    }
    // 0x8006F3BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F3C0: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    // 0x8006F3C4: jal         0x800C06F8
    // 0x8006F3C8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F3C8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006F3CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F3D0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006F3D4: addiu       $v0, $v0, -0x26FC
    ctx->r2 = ADD32(ctx->r2, -0X26FC);
L_8006F3D8:
    // 0x8006F3D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006F3DC: bne         $a1, $at, L_8006F404
    if (ctx->r5 != ctx->r1) {
        // 0x8006F3E0: addiu       $t8, $zero, 0x11A
        ctx->r24 = ADD32(0, 0X11A);
            goto L_8006F404;
    }
    // 0x8006F3E0: addiu       $t8, $zero, 0x11A
    ctx->r24 = ADD32(0, 0X11A);
    // 0x8006F3E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F3E8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8006F3EC: addiu       $a0, $a0, -0x266C
    ctx->r4 = ADD32(ctx->r4, -0X266C);
    // 0x8006F3F0: jal         0x800C06F8
    // 0x8006F3F4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8006F3F4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8006F3F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F3FC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006F400: addiu       $v0, $v0, -0x26FC
    ctx->r2 = ADD32(ctx->r2, -0X26FC);
L_8006F404:
    // 0x8006F404: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006F408: bne         $a1, $at, L_8006F430
    if (ctx->r5 != ctx->r1) {
        // 0x8006F40C: addiu       $t9, $zero, 0x168
        ctx->r25 = ADD32(0, 0X168);
            goto L_8006F430;
    }
    // 0x8006F40C: addiu       $t9, $zero, 0x168
    ctx->r25 = ADD32(0, 0X168);
    // 0x8006F410: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F414: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8006F418: addiu       $a0, $a0, -0x266C
    ctx->r4 = ADD32(ctx->r4, -0X266C);
    // 0x8006F41C: jal         0x800C06F8
    // 0x8006F420: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8006F420: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x8006F424: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F428: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006F42C: addiu       $v0, $v0, -0x26FC
    ctx->r2 = ADD32(ctx->r2, -0X26FC);
L_8006F430:
    // 0x8006F430: bne         $a1, $zero, L_8006F43C
    if (ctx->r5 != 0) {
        // 0x8006F434: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8006F43C;
    }
    // 0x8006F434: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8006F438: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
L_8006F43C:
    // 0x8006F43C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F444: jr          $ra
    // 0x8006F448: nop

    return;
    // 0x8006F448: nop

;}
RECOMP_FUNC void func_8006F20C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F44C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F450: lh          $t6, -0x26FC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X26FC);
    // 0x8006F454: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F458: bne         $t6, $zero, L_8006F484
    if (ctx->r14 != 0) {
        // 0x8006F45C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006F484;
    }
    // 0x8006F45C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F460: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F464: jal         0x800C06F8
    // 0x8006F468: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F468: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    after_0:
    // 0x8006F46C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8006F470: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F474: sh          $t7, -0x26FC($at)
    MEM_H(-0X26FC, ctx->r1) = ctx->r15;
    // 0x8006F478: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F47C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006F480: sb          $t8, 0x3AA4($at)
    MEM_B(0X3AA4, ctx->r1) = ctx->r24;
L_8006F484:
    // 0x8006F484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F488: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F48C: jr          $ra
    // 0x8006F490: nop

    return;
    // 0x8006F490: nop

;}
RECOMP_FUNC void begin_trophy_race_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F494: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F498: lh          $t6, -0x26FC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X26FC);
    // 0x8006F49C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F4A0: bne         $t6, $zero, L_8006F4CC
    if (ctx->r14 != 0) {
        // 0x8006F4A4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006F4CC;
    }
    // 0x8006F4A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F4A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F4AC: jal         0x800C06F8
    // 0x8006F4B0: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F4B0: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    after_0:
    // 0x8006F4B4: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8006F4B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F4BC: sh          $t7, -0x26FC($at)
    MEM_H(-0X26FC, ctx->r1) = ctx->r15;
    // 0x8006F4C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F4C4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8006F4C8: sb          $t8, 0x3AA4($at)
    MEM_B(0X3AA4, ctx->r1) = ctx->r24;
L_8006F4CC:
    // 0x8006F4CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F4D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F4D4: jr          $ra
    // 0x8006F4D8: nop

    return;
    // 0x8006F4D8: nop

;}
RECOMP_FUNC void begin_lighthouse_rocket_cutscene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F4DC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F4E0: lh          $t6, -0x26FC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X26FC);
    // 0x8006F4E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F4E8: bne         $t6, $zero, L_8006F568
    if (ctx->r14 != 0) {
        // 0x8006F4EC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006F568;
    }
    // 0x8006F4EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F4F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006F4F4: lw          $v0, 0x3A90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A90);
    // 0x8006F4F8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006F4FC: lhu         $t7, 0xE($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XE);
    // 0x8006F500: nop

    // 0x8006F504: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8006F508: bne         $t8, $at, L_8006F56C
    if (ctx->r24 != ctx->r1) {
        // 0x8006F50C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006F56C;
    }
    // 0x8006F50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F510: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8006F514: nop

    // 0x8006F518: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x8006F51C: bne         $t9, $zero, L_8006F56C
    if (ctx->r25 != 0) {
        // 0x8006F520: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006F56C;
    }
    // 0x8006F520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F524: lhu         $t0, 0xC($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XC);
    // 0x8006F528: ori         $t2, $v1, 0x1
    ctx->r10 = ctx->r3 | 0X1;
    // 0x8006F52C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8006F530: beq         $t1, $zero, L_8006F568
    if (ctx->r9 == 0) {
        // 0x8006F534: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006F568;
    }
    // 0x8006F534: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F538: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8006F53C: jal         0x800C06F8
    // 0x8006F540: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F540: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    after_0:
    // 0x8006F544: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x8006F548: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F54C: sh          $t3, -0x26FC($at)
    MEM_H(-0X26FC, ctx->r1) = ctx->r11;
    // 0x8006F550: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F554: addiu       $t4, $zero, 0x2D
    ctx->r12 = ADD32(0, 0X2D);
    // 0x8006F558: sb          $t4, 0x3AA5($at)
    MEM_B(0X3AA5, ctx->r1) = ctx->r12;
    // 0x8006F55C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F560: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8006F564: sb          $t5, 0x3AA4($at)
    MEM_B(0X3AA4, ctx->r1) = ctx->r13;
L_8006F568:
    // 0x8006F568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006F56C:
    // 0x8006F56C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F570: jr          $ra
    // 0x8006F574: nop

    return;
    // 0x8006F574: nop

;}
RECOMP_FUNC void begin_level_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F578: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F57C: lh          $t6, -0x26FC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X26FC);
    // 0x8006F580: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F584: bne         $t6, $zero, L_8006F5B8
    if (ctx->r14 != 0) {
        // 0x8006F588: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006F5B8;
    }
    // 0x8006F588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F58C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F590: sb          $a0, 0x3AA5($at)
    MEM_B(0X3AA5, ctx->r1) = ctx->r4;
    // 0x8006F594: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F598: jal         0x800C06F8
    // 0x8006F59C: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F59C: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    after_0:
    // 0x8006F5A0: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8006F5A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F5A8: sh          $t7, -0x26FC($at)
    MEM_H(-0X26FC, ctx->r1) = ctx->r15;
    // 0x8006F5AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F5B0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8006F5B4: sb          $t8, 0x3AA4($at)
    MEM_B(0X3AA4, ctx->r1) = ctx->r24;
L_8006F5B8:
    // 0x8006F5B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F5BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F5C0: jr          $ra
    // 0x8006F5C4: nop

    return;
    // 0x8006F5C4: nop

;}
RECOMP_FUNC void set_pause_lockout_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F5C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F5CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006F5D0: jr          $ra
    // 0x8006F5D4: sb          $a0, -0x26F8($at)
    MEM_B(-0X26F8, ctx->r1) = ctx->r4;
    return;
    // 0x8006F5D4: sb          $a0, -0x26F8($at)
    MEM_B(-0X26F8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void swap_lead_player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F5D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F5DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F5E0: jal         0x8006A74C
    // 0x8006F5E4: nop

    input_swap_id(rdram, ctx);
        goto after_0;
    // 0x8006F5E4: nop

    after_0:
    // 0x8006F5E8: jal         0x8000E194
    // 0x8006F5EC: nop

    toggle_lead_player_index(rdram, ctx);
        goto after_1;
    // 0x8006F5EC: nop

    after_1:
    // 0x8006F5F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006F5F4: lw          $v0, 0x3A90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A90);
    // 0x8006F5F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006F5FC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8006F600: addiu       $v1, $v0, 0x54
    ctx->r3 = ADD32(ctx->r2, 0X54);
    // 0x8006F604: addiu       $a0, $v0, 0x6C
    ctx->r4 = ADD32(ctx->r2, 0X6C);
L_8006F608:
    // 0x8006F608: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8006F60C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8006F610: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8006F614: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8006F618: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8006F61C: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8006F620: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x8006F624: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006F628: sb          $t7, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r15;
    // 0x8006F62C: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8006F630: lbu         $v0, -0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X2);
    // 0x8006F634: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x8006F638: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8006F63C: sb          $t8, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r24;
    // 0x8006F640: sb          $v0, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r2;
    // 0x8006F644: lbu         $v0, -0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X1);
    // 0x8006F648: lbu         $t9, -0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0X1);
    // 0x8006F64C: nop

    // 0x8006F650: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
    // 0x8006F654: bne         $a1, $a2, L_8006F608
    if (ctx->r5 != ctx->r6) {
        // 0x8006F658: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_8006F608;
    }
    // 0x8006F658: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
    // 0x8006F65C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F664: jr          $ra
    // 0x8006F668: nop

    return;
    // 0x8006F668: nop

;}
RECOMP_FUNC void set_frame_blackout_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F66C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8006F670: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F674: jr          $ra
    // 0x8006F678: sb          $t6, -0x26A0($at)
    MEM_B(-0X26A0, ctx->r1) = ctx->r14;
    return;
    // 0x8006F678: sb          $t6, -0x26A0($at)
    MEM_B(-0X26A0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void mode_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F67C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F680: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006F684: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006F688: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006F68C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006F690: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006F694: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006F698: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_8006F69C:
    // 0x8006F69C: jal         0x8006A768
    // 0x8006F6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_held(rdram, ctx);
        goto after_0;
    // 0x8006F6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006F6A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006F6A8: bne         $s0, $s2, L_8006F69C
    if (ctx->r16 != ctx->r18) {
        // 0x8006F6AC: or          $s1, $s1, $v0
        ctx->r17 = ctx->r17 | ctx->r2;
            goto L_8006F69C;
    }
    // 0x8006F6AC: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
    // 0x8006F6B0: andi        $t6, $s1, 0x1000
    ctx->r14 = ctx->r17 & 0X1000;
    // 0x8006F6B4: beq         $t6, $zero, L_8006F6C8
    if (ctx->r14 == 0) {
        // 0x8006F6B8: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8006F6C8;
    }
    // 0x8006F6B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006F6BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006F6C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F6C4: sw          $t7, 0x314($at)
    MEM_W(0X314, ctx->r1) = ctx->r15;
L_8006F6C8:
    // 0x8006F6C8: addiu       $v0, $v0, 0x3AA0
    ctx->r2 = ADD32(ctx->r2, 0X3AA0);
    // 0x8006F6CC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8006F6D0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x8006F6D4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8006F6D8: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x8006F6DC: bne         $at, $zero, L_8006F6F0
    if (ctx->r1 != 0) {
        // 0x8006F6E0: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_8006F6F0;
    }
    // 0x8006F6E0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006F6E4: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    // 0x8006F6E8: jal         0x8006DC68
    // 0x8006F6EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    load_menu_with_level_background(rdram, ctx);
        goto after_1;
    // 0x8006F6EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
L_8006F6F0:
    // 0x8006F6F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006F6F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006F6F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F6FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006F700: jr          $ra
    // 0x8006F704: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006F704: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void is_controller_missing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F708: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F70C: lw          $t6, -0x270C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X270C);
    // 0x8006F710: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006F714: bne         $t6, $at, L_8006F724
    if (ctx->r14 != ctx->r1) {
        // 0x8006F718: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006F724;
    }
    // 0x8006F718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006F71C: jr          $ra
    // 0x8006F720: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8006F720: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006F724:
    // 0x8006F724: jr          $ra
    // 0x8006F728: nop

    return;
    // 0x8006F728: nop

;}
RECOMP_FUNC void drm_validate_imem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F72C: lui         $t6, 0xA400
    ctx->r14 = S32(0XA400 << 16);
    // 0x8006F730: lw          $t7, 0x1000($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1000);
    // 0x8006F734: addiu       $at, $zero, 0x17D7
    ctx->r1 = ADD32(0, 0X17D7);
    // 0x8006F738: beq         $t7, $at, L_8006F748
    if (ctx->r15 == ctx->r1) {
        // 0x8006F73C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006F748;
    }
    // 0x8006F73C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F740: jr          $ra
    // 0x8006F744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006F744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006F748:
    // 0x8006F748: jr          $ra
    // 0x8006F74C: nop

    return;
    // 0x8006F74C: nop

;}
RECOMP_FUNC void interrupts_disable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F750: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006F754: lb          $t0, -0x2660($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2660);
    // 0x8006F758: beq         $t0, $zero, L_8006F774
    if (ctx->r8 == 0) {
        // 0x8006F75C: mfc0        $t0, Status
        ctx->r8 = cop0_status_read(ctx);
            goto L_8006F774;
    }
    // 0x8006F75C: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x8006F760: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8006F764: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8006F768: mtc0        $t1, Status
    cop0_status_write(ctx, ctx->r9);    // 0x8006F76C: andi        $v0, $t0, 0x1
    ctx->r2 = ctx->r8 & 0X1;
    // 0x8006F770: nop

L_8006F774:
    // 0x8006F774: jr          $ra
    // 0x8006F778: nop

    return;
    // 0x8006F778: nop

;}
RECOMP_FUNC void interrupts_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F77C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006F780: lb          $t0, -0x2660($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2660);
    // 0x8006F784: beq         $t0, $zero, L_8006F79C
    if (ctx->r8 == 0) {
        // 0x8006F788: mfc0        $t0, Status
        ctx->r8 = cop0_status_read(ctx);
            goto L_8006F79C;
    }
    // 0x8006F788: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x8006F78C: or          $t0, $t0, $a0
    ctx->r8 = ctx->r8 | ctx->r4;
    // 0x8006F790: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x8006F794: nop

    // 0x8006F798: nop

L_8006F79C:
    // 0x8006F79C: jr          $ra
    // 0x8006F7A0: nop

    return;
    // 0x8006F7A0: nop

;}
RECOMP_FUNC void set_gIntDisFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F7A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F7A8: jr          $ra
    // 0x8006F7AC: sb          $a0, -0x2660($at)
    MEM_B(-0X2660, ctx->r1) = ctx->r4;
    return;
    // 0x8006F7AC: sb          $a0, -0x2660($at)
    MEM_B(-0X2660, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void get_gIntDisFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F7B0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F7B4: jr          $ra
    // 0x8006F7B8: lbu         $v0, -0x2660($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2660);
    return;
    // 0x8006F7B8: lbu         $v0, -0x2660($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2660);
;}
RECOMP_FUNC void mtx_to_mtxs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F7BC: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
    // 0x8006F7C0: lui         $t7, 0xFFFF
    ctx->r15 = S32(0XFFFF << 16);
L_8006F7C4:
    // 0x8006F7C4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8006F7C8: lw          $t2, 0x20($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X20);
    // 0x8006F7CC: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8006F7D0: lw          $t4, 0x24($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X24);
    // 0x8006F7D4: sh          $t1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r9;
    // 0x8006F7D8: sh          $t2, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r10;
    // 0x8006F7DC: sh          $t3, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r11;
    // 0x8006F7E0: sh          $t4, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r12;
    // 0x8006F7E4: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x8006F7E8: srl         $t2, $t2, 16
    ctx->r10 = S32(U32(ctx->r10) >> 16);
    // 0x8006F7EC: srl         $t3, $t3, 16
    ctx->r11 = S32(U32(ctx->r11) >> 16);
    // 0x8006F7F0: srl         $t4, $t4, 16
    ctx->r12 = S32(U32(ctx->r12) >> 16);
    // 0x8006F7F4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8006F7F8: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x8006F7FC: sh          $t2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r10;
    // 0x8006F800: sh          $t3, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r11;
    // 0x8006F804: sh          $t4, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r12;
    // 0x8006F808: addi        $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8006F80C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006F810: bnel        $t0, $zero, L_8006F7C4
    if (ctx->r8 != 0) {
        // 0x8006F814: nop
    
            goto L_8006F7C4;
    }
    goto skip_0;
    // 0x8006F814: nop

    skip_0:
    // 0x8006F818: jr          $ra
    // 0x8006F81C: nop

    return;
    // 0x8006F81C: nop

;}
RECOMP_FUNC void mtxf_to_mtxs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F820: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8006F824: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8006F828: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
L_8006F82C:
    // 0x8006F82C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F830: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F834: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F838: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F83C: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006F840: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8006F844: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F848: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006F84C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8006F850: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8006F854: nop

    // 0x8006F858: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8006F85C: trunc.w.s   $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8006F860: trunc.w.s   $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006F864: swc1        $f4, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->f4.u32l;
    // 0x8006F868: trunc.w.s   $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8006F86C: swc1        $f6, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f6.u32l;
    // 0x8006F870: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8006F874: swc1        $f8, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->f8.u32l;
    // 0x8006F878: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8006F87C: bnel        $t0, $zero, L_8006F82C
    if (ctx->r8 != 0) {
        // 0x8006F880: nop
    
            goto L_8006F82C;
    }
    goto skip_0;
    // 0x8006F880: nop

    skip_0:
    // 0x8006F884: jr          $ra
    // 0x8006F888: nop

    return;
    // 0x8006F888: nop

;}
RECOMP_FUNC void mtxf_transform_point(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F88C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8006F890: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F894: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8006F898: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006F89C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F8A0: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x8006F8A4: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8006F8A8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006F8AC: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8006F8B0: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8006F8B4: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8006F8B8: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8006F8BC: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8006F8C0: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8006F8C4: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8006F8C8: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F8CC: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8006F8D0: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x8006F8D4: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8006F8D8: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8006F8DC: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8006F8E0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8006F8E4: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8006F8E8: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8006F8EC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006F8F0: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8006F8F4: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x8006F8F8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F8FC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8006F900: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006F904: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F908: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8006F90C: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006F910: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8006F914: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8006F918: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8006F91C: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8006F920: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006F924: jr          $ra
    // 0x8006F928: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    return;
    // 0x8006F928: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
;}
RECOMP_FUNC void mtxf_transform_dir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F92C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8006F930: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F934: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8006F938: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006F93C: mul.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8006F940: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8006F944: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8006F948: mul.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F94C: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8006F950: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006F954: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F958: mul.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8006F95C: add.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F960: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8006F964: lwc1        $f14, 0x24($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8006F968: mul.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F96C: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x8006F970: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006F974: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8006F978: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F97C: add.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F980: mul.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8006F984: lwc1        $f12, 0x18($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8006F988: lwc1        $f14, 0x28($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8006F98C: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x8006F990: mul.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F994: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8006F998: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006F99C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F9A0: jr          $ra
    // 0x8006F9A4: swc1        $f14, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f14.u32l;
    return;
    // 0x8006F9A4: swc1        $f14, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f14.u32l;
;}
RECOMP_FUNC void mtxf_mul(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F9A8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006F9AC: sdc1        $f2, 0x0($sp)
    CHECK_FR(ctx, 2);
    SD(ctx->f2.u64, 0X0, ctx->r29);
    // 0x8006F9B0: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
L_8006F9B4:
    // 0x8006F9B4: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F9B8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8006F9BC: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F9C0: lwc1        $f12, 0x10($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8006F9C4: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006F9C8: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F9CC: lwc1        $f14, 0x20($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8006F9D0: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F9D4: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006F9D8: lwc1        $f16, 0x30($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8006F9DC: mul.s       $f14, $f6, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006F9E0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8006F9E4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8006F9E8: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006F9EC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006F9F0: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F9F4: lwc1        $f12, 0x14($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8006F9F8: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006F9FC: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8006FA00: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006FA04: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8006FA08: lwc1        $f14, 0x24($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8006FA0C: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006FA10: lwc1        $f16, 0x34($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8006FA14: swc1        $f18, -0x10($a2)
    MEM_W(-0X10, ctx->r6) = ctx->f18.u32l;
    // 0x8006FA18: mul.s       $f14, $f6, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006FA1C: nop

    // 0x8006FA20: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006FA24: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006FA28: lwc1        $f12, 0x18($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8006FA2C: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006FA30: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8006FA34: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006FA38: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8006FA3C: lwc1        $f14, 0x28($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8006FA40: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006FA44: lwc1        $f16, 0x38($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8006FA48: swc1        $f18, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->f18.u32l;
    // 0x8006FA4C: mul.s       $f14, $f6, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006FA50: nop

    // 0x8006FA54: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006FA58: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006FA5C: lwc1        $f12, 0x1C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8006FA60: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006FA64: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8006FA68: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006FA6C: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8006FA70: lwc1        $f14, 0x2C($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8006FA74: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006FA78: lwc1        $f16, 0x3C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x8006FA7C: swc1        $f18, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->f18.u32l;
    // 0x8006FA80: mul.s       $f14, $f6, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006FA84: nop

    // 0x8006FA88: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006FA8C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006FA90: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006FA94: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8006FA98: swc1        $f18, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f18.u32l;
    // 0x8006FA9C: bnel        $t0, $zero, L_8006F9B4
    if (ctx->r8 != 0) {
        // 0x8006FAA0: nop
    
            goto L_8006F9B4;
    }
    goto skip_0;
    // 0x8006FAA0: nop

    skip_0:
    // 0x8006FAA4: ldc1        $f2, 0x0($sp)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r29, 0X0);
    // 0x8006FAA8: jr          $ra
    // 0x8006FAAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006FAAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void mtxf_to_mtx(uint8_t* rdram, recomp_context* ctx) {
    // mtxf_to_mtx diagnostic removed (confirmed working)
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FAB0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8006FAB4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8006FAB8: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
L_8006FABC:
    // 0x8006FABC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006FAC0: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006FAC4: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006FAC8: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006FACC: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006FAD0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8006FAD4: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006FAD8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006FADC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006FAE0: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8006FAE4: nop

    // 0x8006FAE8: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8006FAEC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8006FAF0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8006FAF4: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8006FAF8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8006FAFC: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8006FB00: sh          $t1, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r9;
    // 0x8006FB04: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8006FB08: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8006FB0C: sh          $t2, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r10;
    // 0x8006FB10: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x8006FB14: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8006FB18: sh          $t3, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r11;
    // 0x8006FB1C: srl         $t2, $t2, 16
    ctx->r10 = S32(U32(ctx->r10) >> 16);
    // 0x8006FB20: sh          $t4, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r12;
    // 0x8006FB24: srl         $t3, $t3, 16
    ctx->r11 = S32(U32(ctx->r11) >> 16);
    // 0x8006FB28: srl         $t4, $t4, 16
    ctx->r12 = S32(U32(ctx->r12) >> 16);
    // 0x8006FB2C: sh          $t1, -0x8($a1)
    MEM_H(-0X8, ctx->r5) = ctx->r9;
    // 0x8006FB30: sh          $t2, -0x6($a1)
    MEM_H(-0X6, ctx->r5) = ctx->r10;
    // 0x8006FB34: sh          $t3, -0x4($a1)
    MEM_H(-0X4, ctx->r5) = ctx->r11;
    // 0x8006FB38: sh          $t4, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r12;
    // 0x8006FB3C: bnel        $t0, $zero, L_8006FABC
    if (ctx->r8 != 0) {
        // 0x8006FB40: nop
    
            goto L_8006FABC;
    }
    goto skip_0;
    // 0x8006FB40: nop

    skip_0:
    // mtxf_to_mtx output diagnostic removed (confirmed working)
    // 0x8006FB44: jr          $ra
    // 0x8006FB48: nop

    return;
    // 0x8006FB48: nop

;}
RECOMP_FUNC void set_rng_seed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006FB50: jr          $ra
    // 0x8006FB54: sw          $a0, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = ctx->r4;
    return;
    // 0x8006FB54: sw          $a0, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void save_rng_seed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB58: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006FB5C: lw          $a0, -0x265C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X265C);
    // 0x8006FB60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006FB64: jr          $ra
    // 0x8006FB68: sw          $a0, -0x2658($at)
    MEM_W(-0X2658, ctx->r1) = ctx->r4;
    return;
    // 0x8006FB68: sw          $a0, -0x2658($at)
    MEM_W(-0X2658, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void load_rng_seed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB6C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006FB70: lw          $a0, -0x2658($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2658);
    // 0x8006FB74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006FB78: jr          $ra
    // 0x8006FB7C: sw          $a0, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = ctx->r4;
    return;
    // 0x8006FB7C: sw          $a0, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void get_rng_seed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB80: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006FB84: jr          $ra
    // 0x8006FB88: lw          $v0, -0x265C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X265C);
    return;
    // 0x8006FB88: lw          $v0, -0x265C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X265C);
;}
RECOMP_FUNC void rand_range(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB8C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006FB90: lw          $t0, -0x265C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X265C);
    // 0x8006FB94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006FB98: sub         $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    // 0x8006FB9C: dsll32      $t1, $t0, 31
    ctx->r9 = ctx->r8 << (31 + 32);
    // 0x8006FBA0: dsll        $t2, $t0, 31
    ctx->r10 = ctx->r8 << 31;
    // 0x8006FBA4: dsrl        $t1, $t1, 31
    ctx->r9 = ctx->r9 >> 31;
    // 0x8006FBA8: dsrl32      $t2, $t2, 0
    ctx->r10 = ctx->r10 >> (0 + 32);
    // 0x8006FBAC: dsll32      $t3, $t0, 12
    ctx->r11 = ctx->r8 << (12 + 32);
    // 0x8006FBB0: or          $t1, $t1, $t2
    ctx->r9 = ctx->r9 | ctx->r10;
    // 0x8006FBB4: dsrl32      $t3, $t3, 0
    ctx->r11 = ctx->r11 >> (0 + 32);
    // 0x8006FBB8: xor         $t1, $t1, $t3
    ctx->r9 = ctx->r9 ^ ctx->r11;
    // 0x8006FBBC: dsrl        $t3, $t1, 20
    ctx->r11 = ctx->r9 >> 20;
    // 0x8006FBC0: andi        $t3, $t3, 0xFFF
    ctx->r11 = ctx->r11 & 0XFFF;
    // 0x8006FBC4: xor         $t0, $t3, $t1
    ctx->r8 = ctx->r11 ^ ctx->r9;
    // 0x8006FBC8: sw          $t0, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = ctx->r8;
    // 0x8006FBCC: addi        $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006FBD0: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8006FBD4: divu        $zero, $t0, $a1
    lo = S32(U32(ctx->r8) / U32(ctx->r5)); hi = S32(U32(ctx->r8) % U32(ctx->r5));
    // 0x8006FBD8: mflo        $t0
    ctx->r8 = lo;
    // 0x8006FBDC: mfhi        $v0
    ctx->r2 = hi;
    // 0x8006FBE0: add         $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006FBE4: bne         $a1, $zero, L_8006FBF0
    if (ctx->r5 != 0) {
        // 0x8006FBE8: nop
    
            goto L_8006FBF0;
    }
    // 0x8006FBE8: nop

    // 0x8006FBEC: break       7
    do_break(2147941356);
L_8006FBF0:
    // 0x8006FBF0: jr          $ra
    // 0x8006FBF4: nop

    return;
    // 0x8006FBF4: nop

;}
RECOMP_FUNC void vec3s_reflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FBF8: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x8006FBFC: lh          $t3, 0x0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X0);
    // 0x8006FC00: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x8006FC04: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8006FC08: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC0C: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x8006FC10: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x8006FC14: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FC18: nop

    // 0x8006FC1C: nop

    // 0x8006FC20: mult        $t1, $t4
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC24: mflo        $t7
    ctx->r15 = lo;
    // 0x8006FC28: add         $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8006FC2C: nop

    // 0x8006FC30: mult        $t2, $t5
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC34: mflo        $t8
    ctx->r24 = lo;
    // 0x8006FC38: add         $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8006FC3C: sra         $t6, $t6, 12
    ctx->r14 = S32(SIGNED(ctx->r14) >> 12);
    // 0x8006FC40: mult        $t6, $t3
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC44: mflo        $t3
    ctx->r11 = lo;
    // 0x8006FC48: sra         $t3, $t3, 13
    ctx->r11 = S32(SIGNED(ctx->r11) >> 13);
    // 0x8006FC4C: sub         $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x8006FC50: mult        $t6, $t4
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC54: sh          $t3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r11;
    // 0x8006FC58: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FC5C: sra         $t4, $t4, 13
    ctx->r12 = S32(SIGNED(ctx->r12) >> 13);
    // 0x8006FC60: sub         $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8006FC64: mult        $t6, $t5
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC68: sh          $t4, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r12;
    // 0x8006FC6C: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FC70: sra         $t5, $t5, 13
    ctx->r13 = S32(SIGNED(ctx->r13) >> 13);
    // 0x8006FC74: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x8006FC78: jr          $ra
    // 0x8006FC7C: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
    return;
    // 0x8006FC7C: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void mtx_to_mtxs_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FC80: ori         $t2, $zero, 0x10
    ctx->r10 = 0 | 0X10;
    // 0x8006FC84: xor         $t3, $t3, $t3
    ctx->r11 = ctx->r11 ^ ctx->r11;
L_8006FC88:
    // 0x8006FC88: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x8006FC8C: lhu         $t1, 0x20($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X20);
    // 0x8006FC90: addi        $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006FC94: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8006FC98: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x8006FC9C: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8006FCA0: addi        $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8006FCA4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8006FCA8: bnel        $t3, $t2, L_8006FC88
    if (ctx->r11 != ctx->r10) {
        // 0x8006FCAC: nop
    
            goto L_8006FC88;
    }
    goto skip_0;
    // 0x8006FCAC: nop

    skip_0:
    // 0x8006FCB0: jr          $ra
    // 0x8006FCB4: nop

    return;
    // 0x8006FCB4: nop

;}
RECOMP_FUNC void mtxs_transform_point(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FCB8: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x8006FCBC: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8006FCC0: lh          $t1, 0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X2);
    // 0x8006FCC4: lh          $t2, 0x4($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X4);
    // 0x8006FCC8: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FCCC: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    // 0x8006FCD0: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FCD4: nop

    // 0x8006FCD8: nop

    // 0x8006FCDC: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FCE0: lw          $t3, 0x20($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X20);
    // 0x8006FCE4: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FCE8: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FCEC: nop

    // 0x8006FCF0: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FCF4: lw          $t3, 0x30($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X30);
    // 0x8006FCF8: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FCFC: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FD00: add         $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006FD04: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FD08: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x8006FD0C: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8006FD10: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FD14: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8006FD18: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FD1C: nop

    // 0x8006FD20: nop

    // 0x8006FD24: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FD28: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x8006FD2C: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FD30: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FD34: nop

    // 0x8006FD38: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FD3C: lw          $t3, 0x34($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X34);
    // 0x8006FD40: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FD44: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FD48: add         $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006FD4C: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FD50: sh          $t4, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r12;
    // 0x8006FD54: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x8006FD58: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FD5C: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x8006FD60: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FD64: nop

    // 0x8006FD68: nop

    // 0x8006FD6C: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FD70: lw          $t3, 0x28($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X28);
    // 0x8006FD74: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FD78: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FD7C: nop

    // 0x8006FD80: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FD84: lw          $t3, 0x38($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X38);
    // 0x8006FD88: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FD8C: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FD90: add         $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006FD94: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FD98: jr          $ra
    // 0x8006FD9C: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
    return;
    // 0x8006FD9C: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
;}
RECOMP_FUNC void mtxs_transform_dir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FDA0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8006FDA4: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x8006FDA8: lh          $t1, 0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X2);
    // 0x8006FDAC: lh          $t2, 0x4($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X4);
    // 0x8006FDB0: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FDB4: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    // 0x8006FDB8: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FDBC: nop

    // 0x8006FDC0: nop

    // 0x8006FDC4: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FDC8: lw          $t3, 0x20($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X20);
    // 0x8006FDCC: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FDD0: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FDD4: nop

    // 0x8006FDD8: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FDDC: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8006FDE0: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FDE4: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FDE8: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FDEC: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FDF0: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x8006FDF4: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8006FDF8: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FDFC: nop

    // 0x8006FE00: nop

    // 0x8006FE04: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FE08: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x8006FE0C: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FE10: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FE14: nop

    // 0x8006FE18: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FE1C: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x8006FE20: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FE24: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FE28: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FE2C: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FE30: sh          $t4, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r12;
    // 0x8006FE34: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x8006FE38: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FE3C: nop

    // 0x8006FE40: nop

    // 0x8006FE44: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FE48: lw          $t3, 0x28($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X28);
    // 0x8006FE4C: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FE50: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FE54: nop

    // 0x8006FE58: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FE5C: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FE60: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FE64: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FE68: jr          $ra
    // 0x8006FE6C: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
    return;
    // 0x8006FE6C: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
;}
RECOMP_FUNC void mtxf_from_transform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FE70: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006FE74: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x8006FE78: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x8006FE7C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006FE80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006FE84: jal         0x80070A70
    // 0x8006FE88: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    sins_s16(rdram, ctx);
        goto after_0;
    // 0x8006FE88: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_0:
    // 0x8006FE8C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006FE90: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8006FE94: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006FE98: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8006FE9C: jal         0x80070A6C
    // 0x8006FEA0: nop

    coss_s16(rdram, ctx);
        goto after_1;
    // 0x8006FEA0: nop

    after_1:
    // 0x8006FEA4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8006FEA8: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x8006FEAC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8006FEB0: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8006FEB4: jal         0x80070A70
    // 0x8006FEB8: nop

    sins_s16(rdram, ctx);
        goto after_2;
    // 0x8006FEB8: nop

    after_2:
    // 0x8006FEBC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8006FEC0: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x8006FEC4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006FEC8: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8006FECC: jal         0x80070A6C
    // 0x8006FED0: nop

    coss_s16(rdram, ctx);
        goto after_3;
    // 0x8006FED0: nop

    after_3:
    // 0x8006FED4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8006FED8: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x8006FEDC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006FEE0: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8006FEE4: jal         0x80070A70
    // 0x8006FEE8: nop

    sins_s16(rdram, ctx);
        goto after_4;
    // 0x8006FEE8: nop

    after_4:
    // 0x8006FEEC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8006FEF0: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x8006FEF4: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006FEF8: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8006FEFC: jal         0x80070A6C
    // 0x8006FF00: nop

    coss_s16(rdram, ctx);
        goto after_5;
    // 0x8006FF00: nop

    after_5:
    // 0x8006FF04: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8006FF08: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x8006FF0C: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x8006FF10: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006FF14: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x8006FF18: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x8006FF1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006FF20: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8006FF24: nop

    // 0x8006FF28: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8006FF2C: nop

    // 0x8006FF30: mul.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8006FF34: nop

    // 0x8006FF38: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8006FF3C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006FF40: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006FF44: nop

    // 0x8006FF48: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FF4C: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x8006FF50: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8006FF54: nop

    // 0x8006FF58: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FF5C: swc1        $f16, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8006FF60: mul.s       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8006FF64: nop

    // 0x8006FF68: mul.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8006FF6C: nop

    // 0x8006FF70: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8006FF74: sub.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8006FF78: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006FF7C: nop

    // 0x8006FF80: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FF84: swc1        $f16, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f16.u32l;
    // 0x8006FF88: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8006FF8C: nop

    // 0x8006FF90: mul.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8006FF94: nop

    // 0x8006FF98: mul.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8006FF9C: sub.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8006FFA0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006FFA4: nop

    // 0x8006FFA8: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FFAC: swc1        $f16, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f16.u32l;
    // 0x8006FFB0: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8006FFB4: nop

    // 0x8006FFB8: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FFBC: swc1        $f16, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f16.u32l;
    // 0x8006FFC0: mul.s       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8006FFC4: nop

    // 0x8006FFC8: mul.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8006FFCC: nop

    // 0x8006FFD0: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8006FFD4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006FFD8: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006FFDC: nop

    // 0x8006FFE0: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FFE4: swc1        $f16, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f16.u32l;
    // 0x8006FFE8: mul.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8006FFEC: nop

    // 0x8006FFF0: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FFF4: swc1        $f16, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f16.u32l;
    // 0x8006FFF8: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8006FFFC: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x80070000: swc1        $f16, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f16.u32l;
    // 0x80070004: mul.s       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80070008: nop

    // 0x8007000C: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80070010: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80070014: swc1        $f16, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f16.u32l;
    // 0x80070018: lw          $t0, 0xC($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XC);
    // 0x8007001C: sw          $t0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r8;
    // 0x80070020: lw          $t0, 0x10($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X10);
    // 0x80070024: sw          $t0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r8;
    // 0x80070028: lw          $t0, 0x14($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X14);
    // 0x8007002C: swc1        $f18, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f18.u32l;
    // 0x80070030: sw          $t0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r8;
    // 0x80070034: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070038: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8007003C: jr          $ra
    // 0x80070040: nop

    return;
    // 0x80070040: nop

;}
RECOMP_FUNC void mtxf_scale_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070044: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x80070048: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8007004C: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80070050: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80070054: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80070058: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8007005C: swc1        $f16, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f16.u32l;
    // 0x80070060: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80070064: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80070068: jr          $ra
    // 0x8007006C: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x8007006C: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void mtxf_translate_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070070: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x80070074: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80070078: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8007007C: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80070080: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80070084: lwc1        $f2, 0x30($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80070088: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8007008C: mul.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80070090: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80070094: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80070098: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007009C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800700A0: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x800700A4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800700A8: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x800700AC: jr          $ra
    // 0x800700B0: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800700B0: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void mtxf_from_inverse_transform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800700B4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800700B8: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x800700BC: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x800700C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800700C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800700C8: jal         0x80070A70
    // 0x800700CC: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    sins_s16(rdram, ctx);
        goto after_0;
    // 0x800700CC: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_0:
    // 0x800700D0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800700D4: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x800700D8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800700DC: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800700E0: jal         0x80070A6C
    // 0x800700E4: nop

    coss_s16(rdram, ctx);
        goto after_1;
    // 0x800700E4: nop

    after_1:
    // 0x800700E8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800700EC: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x800700F0: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800700F4: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800700F8: jal         0x80070A70
    // 0x800700FC: nop

    sins_s16(rdram, ctx);
        goto after_2;
    // 0x800700FC: nop

    after_2:
    // 0x80070100: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80070104: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x80070108: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007010C: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80070110: jal         0x80070A6C
    // 0x80070114: nop

    coss_s16(rdram, ctx);
        goto after_3;
    // 0x80070114: nop

    after_3:
    // 0x80070118: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8007011C: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80070120: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80070124: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80070128: jal         0x80070A70
    // 0x8007012C: nop

    sins_s16(rdram, ctx);
        goto after_4;
    // 0x8007012C: nop

    after_4:
    // 0x80070130: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80070134: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80070138: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007013C: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80070140: jal         0x80070A6C
    // 0x80070144: nop

    coss_s16(rdram, ctx);
        goto after_5;
    // 0x80070144: nop

    after_5:
    // 0x80070148: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8007014C: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x80070150: swc1        $f4, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f4.u32l;
    // 0x80070154: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80070158: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x8007015C: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x80070160: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80070164: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80070168: nop

    // 0x8007016C: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80070170: nop

    // 0x80070174: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80070178: nop

    // 0x8007017C: mul.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80070180: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80070184: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x80070188: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8007018C: nop

    // 0x80070190: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80070194: nop

    // 0x80070198: mul.s       $f18, $f2, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8007019C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800701A0: swc1        $f16, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f16.u32l;
    // 0x800701A4: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800701A8: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x800701AC: swc1        $f16, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f16.u32l;
    // 0x800701B0: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800701B4: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x800701B8: swc1        $f16, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f16.u32l;
    // 0x800701BC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800701C0: swc1        $f16, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f16.u32l;
    // 0x800701C4: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800701C8: nop

    // 0x800701CC: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800701D0: nop

    // 0x800701D4: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800701D8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800701DC: swc1        $f16, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f16.u32l;
    // 0x800701E0: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800701E4: nop

    // 0x800701E8: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800701EC: nop

    // 0x800701F0: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800701F4: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800701F8: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800701FC: swc1        $f16, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f16.u32l;
    // 0x80070200: mul.s       $f16, $f2, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80070204: swc1        $f16, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f16.u32l;
    // 0x80070208: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8007020C: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80070210: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80070214: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80070218: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8007021C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80070220: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070224: lwc1        $f18, 0x20($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80070228: mul.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007022C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070230: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80070234: swc1        $f16, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f16.u32l;
    // 0x80070238: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8007023C: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80070240: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80070244: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070248: lwc1        $f18, 0x24($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X24);
    // 0x8007024C: mul.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80070250: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070254: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80070258: swc1        $f16, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f16.u32l;
    // 0x8007025C: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80070260: lwc1        $f16, 0x18($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X18);
    // 0x80070264: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80070268: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8007026C: lwc1        $f18, 0x28($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X28);
    // 0x80070270: mul.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80070274: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070278: swc1        $f16, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f16.u32l;
    // 0x8007027C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80070280: nop

    // 0x80070284: swc1        $f16, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f16.u32l;
    // 0x80070288: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x8007028C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070290: jr          $ra
    // 0x80070294: nop

    return;
    // 0x80070294: nop

;}
RECOMP_FUNC void func_80070058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070298: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007029C: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x800702A0: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x800702A4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800702A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800702AC: jal         0x80070A70
    // 0x800702B0: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    sins_s16(rdram, ctx);
        goto after_0;
    // 0x800702B0: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_0:
    // 0x800702B4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800702B8: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x800702BC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800702C0: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800702C4: jal         0x80070A6C
    // 0x800702C8: nop

    coss_s16(rdram, ctx);
        goto after_1;
    // 0x800702C8: nop

    after_1:
    // 0x800702CC: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800702D0: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x800702D4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800702D8: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800702DC: jal         0x80070A70
    // 0x800702E0: nop

    sins_s16(rdram, ctx);
        goto after_2;
    // 0x800702E0: nop

    after_2:
    // 0x800702E4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800702E8: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x800702EC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800702F0: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800702F4: jal         0x80070A6C
    // 0x800702F8: nop

    coss_s16(rdram, ctx);
        goto after_3;
    // 0x800702F8: nop

    after_3:
    // 0x800702FC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80070300: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80070304: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80070308: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8007030C: jal         0x80070A70
    // 0x80070310: nop

    sins_s16(rdram, ctx);
        goto after_4;
    // 0x80070310: nop

    after_4:
    // 0x80070314: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80070318: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x8007031C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80070320: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80070324: jal         0x80070A6C
    // 0x80070328: nop

    coss_s16(rdram, ctx);
        goto after_5;
    // 0x80070328: nop

    after_5:
    // 0x8007032C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80070330: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80070334: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x80070338: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007033C: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x80070340: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x80070344: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80070348: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007034C: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80070350: swc1        $f18, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f18.u32l;
    // 0x80070354: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070358: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8007035C: mul.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80070360: nop

    // 0x80070364: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80070368: jr          $ra
    // 0x8007036C: nop

    return;
    // 0x8007036C: nop

;}
RECOMP_FUNC void mtxf_billboard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070370: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070374: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x80070378: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x8007037C: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070380: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80070384: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80070388: jal         0x80070A70
    // 0x8007038C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    sins_s16(rdram, ctx);
        goto after_0;
    // 0x8007038C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80070390: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80070394: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80070398: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007039C: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800703A0: jal         0x80070A6C
    // 0x800703A4: nop

    coss_s16(rdram, ctx);
        goto after_1;
    // 0x800703A4: nop

    after_1:
    // 0x800703A8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800703AC: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800703B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800703B4: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800703B8: swc1        $f16, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f16.u32l;
    // 0x800703BC: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
    // 0x800703C0: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x800703C4: sw          $zero, 0x18($a3)
    MEM_W(0X18, ctx->r7) = 0;
    // 0x800703C8: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x800703CC: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800703D0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800703D4: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800703D8: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    // 0x800703DC: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x800703E0: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x800703E4: sw          $zero, 0x34($a3)
    MEM_W(0X34, ctx->r7) = 0;
    // 0x800703E8: mul.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800703EC: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x800703F0: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800703F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800703F8: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x800703FC: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80070400: swc1        $f16, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f16.u32l;
    // 0x80070404: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x80070408: neg.s       $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = -ctx->f8.fl;
    // 0x8007040C: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
    // 0x80070410: swc1        $f10, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f10.u32l;
    // 0x80070414: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070418: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8007041C: jr          $ra
    // 0x80070420: nop

    return;
    // 0x80070420: nop

;}
RECOMP_FUNC void vec3s_rotate_rpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070424: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070428: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x8007042C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80070430: lh          $t3, 0x0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X0);
    // 0x80070434: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x80070438: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x8007043C: jal         0x80070A70
    // 0x80070440: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    sins_s16(rdram, ctx);
        goto after_0;
    // 0x80070440: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_0:
    // 0x80070444: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x80070448: jal         0x80070A6C
    // 0x8007044C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    coss_s16(rdram, ctx);
        goto after_1;
    // 0x8007044C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_1:
    // 0x80070450: mult        $t3, $t6
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070454: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x80070458: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x8007045C: mflo        $t0
    ctx->r8 = lo;
    // 0x80070460: nop

    // 0x80070464: nop

    // 0x80070468: mult        $t4, $t6
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007046C: mflo        $t1
    ctx->r9 = lo;
    // 0x80070470: nop

    // 0x80070474: nop

    // 0x80070478: mult        $t3, $t7
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007047C: mflo        $t3
    ctx->r11 = lo;
    // 0x80070480: sub         $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x80070484: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80070488: mult        $t4, $t7
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007048C: mflo        $t4
    ctx->r12 = lo;
    // 0x80070490: add         $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x80070494: jal         0x80070A70
    // 0x80070498: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    sins_s16(rdram, ctx);
        goto after_2;
    // 0x80070498: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    after_2:
    // 0x8007049C: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x800704A0: jal         0x80070A6C
    // 0x800704A4: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    coss_s16(rdram, ctx);
        goto after_3;
    // 0x800704A4: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    after_3:
    // 0x800704A8: mult        $t4, $t6
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800704AC: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x800704B0: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    // 0x800704B4: mflo        $t0
    ctx->r8 = lo;
    // 0x800704B8: nop

    // 0x800704BC: nop

    // 0x800704C0: mult        $t5, $t6
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800704C4: mflo        $t1
    ctx->r9 = lo;
    // 0x800704C8: nop

    // 0x800704CC: nop

    // 0x800704D0: mult        $t4, $t7
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800704D4: mflo        $t4
    ctx->r12 = lo;
    // 0x800704D8: sub         $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x800704DC: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800704E0: mult        $t5, $t7
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800704E4: mflo        $t5
    ctx->r13 = lo;
    // 0x800704E8: add         $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x800704EC: jal         0x80070A70
    // 0x800704F0: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    sins_s16(rdram, ctx);
        goto after_4;
    // 0x800704F0: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    after_4:
    // 0x800704F4: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x800704F8: jal         0x80070A6C
    // 0x800704FC: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    coss_s16(rdram, ctx);
        goto after_5;
    // 0x800704FC: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    after_5:
    // 0x80070500: mult        $t3, $t6
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070504: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x80070508: sh          $t4, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r12;
    // 0x8007050C: mflo        $t0
    ctx->r8 = lo;
    // 0x80070510: nop

    // 0x80070514: nop

    // 0x80070518: mult        $t5, $t6
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007051C: mflo        $t1
    ctx->r9 = lo;
    // 0x80070520: nop

    // 0x80070524: nop

    // 0x80070528: mult        $t3, $t7
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007052C: mflo        $t3
    ctx->r11 = lo;
    // 0x80070530: add         $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80070534: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80070538: mult        $t5, $t7
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007053C: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x80070540: mflo        $t5
    ctx->r13 = lo;
    // 0x80070544: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x80070548: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8007054C: sh          $t5, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r13;
    // 0x80070550: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070554: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070558: jr          $ra
    // 0x8007055C: nop

    return;
    // 0x8007055C: nop

;}
RECOMP_FUNC void vec3f_rotate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070560: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070564: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070568: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007056C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80070570: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80070574: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80070578: jal         0x80070A04
    // 0x8007057C: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x8007057C: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    after_0:
    // 0x80070580: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070584: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    // 0x80070588: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007058C: jal         0x80070A38
    // 0x80070590: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x80070590: nop

    after_1:
    // 0x80070594: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070598: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x8007059C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800705A0: sub.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800705A4: jal         0x80070A04
    // 0x800705A8: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x800705A8: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    after_2:
    // 0x800705AC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800705B0: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x800705B4: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800705B8: jal         0x80070A38
    // 0x800705BC: nop

    coss_f(rdram, ctx);
        goto after_3;
    // 0x800705BC: nop

    after_3:
    // 0x800705C0: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800705C4: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x800705C8: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800705CC: sub.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x800705D0: jal         0x80070A04
    // 0x800705D4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    sins_f(rdram, ctx);
        goto after_4;
    // 0x800705D4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    after_4:
    // 0x800705D8: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800705DC: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x800705E0: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800705E4: jal         0x80070A38
    // 0x800705E8: nop

    coss_f(rdram, ctx);
        goto after_5;
    // 0x800705E8: nop

    after_5:
    // 0x800705EC: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800705F0: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800705F4: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800705F8: add.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800705FC: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80070600: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80070604: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x80070608: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x8007060C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070610: jr          $ra
    // 0x80070614: nop

    return;
    // 0x80070614: nop

;}
RECOMP_FUNC void vec3f_rotate_ypr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070618: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007061C: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070620: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80070624: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80070628: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8007062C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80070630: jal         0x80070A04
    // 0x80070634: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x80070634: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_0:
    // 0x80070638: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8007063C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x80070640: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070644: jal         0x80070A38
    // 0x80070648: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x80070648: nop

    after_1:
    // 0x8007064C: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070650: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x80070654: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070658: add.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8007065C: jal         0x80070A04
    // 0x80070660: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80070660: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    after_2:
    // 0x80070664: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80070668: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x8007066C: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070670: jal         0x80070A38
    // 0x80070674: nop

    coss_f(rdram, ctx);
        goto after_3;
    // 0x80070674: nop

    after_3:
    // 0x80070678: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007067C: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    // 0x80070680: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070684: sub.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80070688: jal         0x80070A04
    // 0x8007068C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    sins_f(rdram, ctx);
        goto after_4;
    // 0x8007068C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    after_4:
    // 0x80070690: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070694: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    // 0x80070698: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007069C: jal         0x80070A38
    // 0x800706A0: nop

    coss_f(rdram, ctx);
        goto after_5;
    // 0x800706A0: nop

    after_5:
    // 0x800706A4: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800706A8: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x800706AC: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800706B0: sub.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800706B4: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800706B8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800706BC: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800706C0: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x800706C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800706C8: jr          $ra
    // 0x800706CC: nop

    return;
    // 0x800706CC: nop

;}
RECOMP_FUNC void vec3f_rotate_py(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800706D0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800706D4: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x800706D8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800706DC: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800706E0: jal         0x80070A04
    // 0x800706E4: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800706E4: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    after_0:
    // 0x800706E8: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800706EC: jal         0x80070A38
    // 0x800706F0: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800706F0: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    after_1:
    // 0x800706F4: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800706F8: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
    // 0x800706FC: jal         0x80070A04
    // 0x80070700: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80070700: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_2:
    // 0x80070704: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070708: jal         0x80070A38
    // 0x8007070C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    coss_f(rdram, ctx);
        goto after_3;
    // 0x8007070C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_3:
    // 0x80070710: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070714: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80070718: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x8007071C: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x80070720: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070724: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070728: jr          $ra
    // 0x8007072C: nop

    return;
    // 0x8007072C: nop

;}
RECOMP_FUNC void tri2d_xz_contains_point(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070730: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80070734: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x80070738: lh          $t1, 0x4($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X4);
    // 0x8007073C: lh          $t3, 0x4($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4);
    // 0x80070740: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80070744: lh          $t5, 0x4($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X4);
    // 0x80070748: sub         $t6, $a0, $t0
    ctx->r14 = SUB32(ctx->r4, ctx->r8);
    // 0x8007074C: sub         $t7, $t3, $t1
    ctx->r15 = SUB32(ctx->r11, ctx->r9);
    // 0x80070750: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070754: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x80070758: sub         $t9, $a1, $t1
    ctx->r25 = SUB32(ctx->r5, ctx->r9);
    // 0x8007075C: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    // 0x80070760: sub         $t8, $t2, $t0
    ctx->r24 = SUB32(ctx->r10, ctx->r8);
    // 0x80070764: ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // 0x80070768: mflo        $t6
    ctx->r14 = lo;
    // 0x8007076C: mflo        $t6
    ctx->r14 = lo;
    // 0x80070770: nop

    // 0x80070774: nop

    // 0x80070778: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007077C: mflo        $t7
    ctx->r15 = lo;
    // 0x80070780: mflo        $t8
    ctx->r24 = lo;
    // 0x80070784: sub         $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80070788: bgezl       $t6, L_80070798
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8007078C: sub         $t6, $a0, $t2
        ctx->r14 = SUB32(ctx->r4, ctx->r10);
            goto L_80070798;
    }
    goto skip_0;
    // 0x8007078C: sub         $t6, $a0, $t2
    ctx->r14 = SUB32(ctx->r4, ctx->r10);
    skip_0:
    // 0x80070790: xor         $a3, $a3, $a3
    ctx->r7 = ctx->r7 ^ ctx->r7;
    // 0x80070794: sub         $t6, $a0, $t2
    ctx->r14 = SUB32(ctx->r4, ctx->r10);
L_80070798:
    // 0x80070798: sub         $t7, $t5, $t3
    ctx->r15 = SUB32(ctx->r13, ctx->r11);
    // 0x8007079C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800707A0: sub         $t8, $t4, $t2
    ctx->r24 = SUB32(ctx->r12, ctx->r10);
    // 0x800707A4: sub         $t9, $a1, $t3
    ctx->r25 = SUB32(ctx->r5, ctx->r11);
    // 0x800707A8: ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // 0x800707AC: mflo        $t6
    ctx->r14 = lo;
    // 0x800707B0: mflo        $t6
    ctx->r14 = lo;
    // 0x800707B4: nop

    // 0x800707B8: nop

    // 0x800707BC: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800707C0: mflo        $t7
    ctx->r15 = lo;
    // 0x800707C4: mflo        $t8
    ctx->r24 = lo;
    // 0x800707C8: sub         $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x800707CC: bgez        $t6, L_800707D8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800707D0: nop
    
            goto L_800707D8;
    }
    // 0x800707D0: nop

    // 0x800707D4: xor         $a2, $a2, $a2
    ctx->r6 = ctx->r6 ^ ctx->r6;
L_800707D8:
    // 0x800707D8: bne         $a3, $a2, L_80070830
    if (ctx->r7 != ctx->r6) {
        // 0x800707DC: nop
    
            goto L_80070830;
    }
    // 0x800707DC: nop

    // 0x800707E0: sub         $t6, $a0, $t4
    ctx->r14 = SUB32(ctx->r4, ctx->r12);
    // 0x800707E4: sub         $t7, $t1, $t5
    ctx->r15 = SUB32(ctx->r9, ctx->r13);
    // 0x800707E8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800707EC: sub         $t8, $t0, $t4
    ctx->r24 = SUB32(ctx->r8, ctx->r12);
    // 0x800707F0: sub         $t9, $a1, $t5
    ctx->r25 = SUB32(ctx->r5, ctx->r13);
    // 0x800707F4: ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // 0x800707F8: mflo        $t6
    ctx->r14 = lo;
    // 0x800707FC: mflo        $t6
    ctx->r14 = lo;
    // 0x80070800: nop

    // 0x80070804: nop

    // 0x80070808: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007080C: mflo        $t7
    ctx->r15 = lo;
    // 0x80070810: mflo        $t8
    ctx->r24 = lo;
    // 0x80070814: sub         $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80070818: bgez        $t6, L_80070824
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8007081C: nop
    
            goto L_80070824;
    }
    // 0x8007081C: nop

    // 0x80070820: xor         $a1, $a1, $a1
    ctx->r5 = ctx->r5 ^ ctx->r5;
L_80070824:
    // 0x80070824: bne         $a1, $a2, L_80070830
    if (ctx->r5 != ctx->r6) {
        // 0x80070828: nop
    
            goto L_80070830;
    }
    // 0x80070828: nop

    // 0x8007082C: ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80070830:
    // 0x80070830: jr          $ra
    // 0x80070834: nop

    return;
    // 0x80070834: nop

;}
RECOMP_FUNC void mtxf_from_translation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070838: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8007083C: addiu       $t1, $t0, 0x40
    ctx->r9 = ADD32(ctx->r8, 0X40);
L_80070840:
    // 0x80070840: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80070844: bne         $t1, $t0, L_80070840
    if (ctx->r9 != ctx->r8) {
        // 0x80070848: sw          $zero, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = 0;
            goto L_80070840;
    }
    // 0x80070848: sw          $zero, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = 0;
    // 0x8007084C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80070850: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80070854: nop

    // 0x80070858: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x8007085C: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80070860: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x80070864: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x80070868: sw          $a1, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r5;
    // 0x8007086C: sw          $a2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r6;
    // 0x80070870: jr          $ra
    // 0x80070874: sw          $a3, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r7;
    return;
    // 0x80070874: sw          $a3, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void mtxf_from_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070878: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8007087C: addiu       $t1, $t0, 0x40
    ctx->r9 = ADD32(ctx->r8, 0X40);
L_80070880:
    // 0x80070880: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80070884: bne         $t1, $t0, L_80070880
    if (ctx->r9 != ctx->r8) {
        // 0x80070888: sw          $zero, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = 0;
            goto L_80070880;
    }
    // 0x80070888: sw          $zero, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = 0;
    // 0x8007088C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80070890: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80070894: nop

    // 0x80070898: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x8007089C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800708A0: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    // 0x800708A4: jr          $ra
    // 0x800708A8: sw          $a3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r7;
    return;
    // 0x800708A8: sw          $a3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void atan2s(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800708AC: or          $t0, $a0, $a1
    ctx->r8 = ctx->r4 | ctx->r5;
    // 0x800708B0: bne         $zero, $t0, L_800708C0
    if (0 != ctx->r8) {
        // 0x800708B4: nop
    
            goto L_800708C0;
    }
    // 0x800708B4: nop

    // 0x800708B8: jr          $ra
    // 0x800708BC: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x800708BC: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_800708C0:
    // 0x800708C0: bltz        $a0, L_800708D8
    if (SIGNED(ctx->r4) < 0) {
        // 0x800708C4: nop
    
            goto L_800708D8;
    }
    // 0x800708C4: nop

    // 0x800708C8: bltzl       $a1, L_800708F8
    if (SIGNED(ctx->r5) < 0) {
        // 0x800708CC: negu        $a1, $a1
        ctx->r5 = SUB32(0, ctx->r5);
            goto L_800708F8;
    }
    goto skip_0;
    // 0x800708CC: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    skip_0:
    // 0x800708D0: j           L_80070908
    // 0x800708D4: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
        goto L_80070908;
    // 0x800708D4: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_800708D8:
    // 0x800708D8: bltz        $a1, L_800708E8
    if (SIGNED(ctx->r5) < 0) {
        // 0x800708DC: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_800708E8;
    }
    // 0x800708DC: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800708E0: j           L_800708FC
    // 0x800708E4: ori         $v0, $zero, 0xC000
    ctx->r2 = 0 | 0XC000;
        goto L_800708FC;
    // 0x800708E4: ori         $v0, $zero, 0xC000
    ctx->r2 = 0 | 0XC000;
L_800708E8:
    // 0x800708E8: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800708EC: j           L_80070908
    // 0x800708F0: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
        goto L_80070908;
    // 0x800708F0: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x800708F4: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_800708F8:
    // 0x800708F8: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
L_800708FC:
    // 0x800708FC: xor         $a0, $a0, $a1
    ctx->r4 = ctx->r4 ^ ctx->r5;
    // 0x80070900: xor         $a1, $a0, $a1
    ctx->r5 = ctx->r4 ^ ctx->r5;
    // 0x80070904: xor         $a0, $a0, $a1
    ctx->r4 = ctx->r4 ^ ctx->r5;
L_80070908:
    // 0x80070908: subu        $t0, $a0, $a1
    ctx->r8 = SUB32(ctx->r4, ctx->r5);
    // 0x8007090C: bltzl       $t0, L_80070958
    if (SIGNED(ctx->r8) < 0) {
        // 0x80070910: dsll        $t0, $a0, 11
        ctx->r8 = ctx->r4 << 11;
            goto L_80070958;
    }
    goto skip_1;
    // 0x80070910: dsll        $t0, $a0, 11
    ctx->r8 = ctx->r4 << 11;
    skip_1:
    // 0x80070914: dsll        $t0, $a1, 11
    ctx->r8 = ctx->r5 << 11;
    // 0x80070918: ddivu       $zero, $t0, $a0
    DDIVU(U64(ctx->r8), U64(ctx->r4), &lo, &hi);
    // 0x8007091C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80070920: addiu       $t1, $t1, -0x1E52
    ctx->r9 = ADD32(ctx->r9, -0X1E52);
    // 0x80070924: addiu       $v0, $v0, 0x4000
    ctx->r2 = ADD32(ctx->r2, 0X4000);
    // 0x80070928: bne         $a0, $zero, L_80070934
    if (ctx->r4 != 0) {
        // 0x8007092C: nop
    
            goto L_80070934;
    }
    // 0x8007092C: nop

    // 0x80070930: break       7
    do_break(2147944752);
L_80070934:
    // 0x80070934: mflo        $t0
    ctx->r8 = lo;
    // 0x80070938: mflo        $t0
    ctx->r8 = lo;
    // 0x8007093C: andi        $t0, $t0, 0xFFE
    ctx->r8 = ctx->r8 & 0XFFE;
    // 0x80070940: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80070944: lh          $t0, 0x0($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X0);
    // 0x80070948: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x8007094C: jr          $ra
    // 0x80070950: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x80070950: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80070954: dsll        $t0, $a0, 11
    ctx->r8 = ctx->r4 << 11;
L_80070958:
    // 0x80070958: ddivu       $zero, $t0, $a1
    DDIVU(U64(ctx->r8), U64(ctx->r5), &lo, &hi);
    // 0x8007095C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80070960: addiu       $t1, $t1, -0x1E52
    ctx->r9 = ADD32(ctx->r9, -0X1E52);
    // 0x80070964: bne         $a1, $zero, L_80070970
    if (ctx->r5 != 0) {
        // 0x80070968: nop
    
            goto L_80070970;
    }
    // 0x80070968: nop

    // 0x8007096C: break       7
    do_break(2147944812);
L_80070970:
    // 0x80070970: mflo        $t0
    ctx->r8 = lo;
    // 0x80070974: mflo        $t0
    ctx->r8 = lo;
    // 0x80070978: andi        $t0, $t0, 0xFFE
    ctx->r8 = ctx->r8 & 0XFFE;
    // 0x8007097C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80070980: lh          $t0, 0x0($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X0);
    // 0x80070984: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80070988: jr          $ra
    // 0x8007098C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x8007098C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
;}
RECOMP_FUNC void arctan2_f(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_800708AC:
    // 0x80070990: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80070994: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80070998: nop

    // 0x8007099C: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800709A0: nop

    // 0x800709A4: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800709A8: cvt.w.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = CVT_W_S(ctx->f12.fl);
    // 0x800709AC: cvt.w.s     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = CVT_W_S(ctx->f14.fl);
    // 0x800709B0: mfc1        $a0, $f12
    ctx->r4 = (int32_t)ctx->f12.u32l;
    // 0x800709B4: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800709B8: j           L_800708AC
    // 0x800709BC: nop

    atan2s(rdram, ctx);
    return;
    // 0x800709BC: nop

;}
RECOMP_FUNC void fix32_sqrt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800709C0: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x800709C4: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800709C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800709CC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800709D0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800709D4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800709D8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800709DC: cvt.w.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800709E0: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x800709E4: jr          $ra
    // 0x800709E8: nop

    return;
    // 0x800709E8: nop

;}
RECOMP_FUNC void bad_int_sqrt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800709EC: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x800709F0: nop

    // 0x800709F4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800709F8: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x800709FC: jr          $ra
    // 0x80070A00: nop

    return;
    // 0x80070A00: nop

;}
RECOMP_FUNC void sins_f(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A04: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070A08: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070A0C: jal         0x80070A70
    // 0x80070A10: nop

    sins_s16(rdram, ctx);
        goto after_0;
    // 0x80070A10: nop

    after_0:
    // 0x80070A14: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070A18: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x80070A1C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80070A20: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070A24: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070A28: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070A2C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80070A30: jr          $ra
    // 0x80070A34: nop

    return;
    // 0x80070A34: nop

;}
RECOMP_FUNC void coss_f(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A38: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070A3C: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070A40: jal         0x80070A6C
    // 0x80070A44: nop

    coss_s16(rdram, ctx);
        goto after_0;
    // 0x80070A44: nop

    after_0:
    // 0x80070A48: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070A4C: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x80070A50: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80070A54: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070A58: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070A5C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070A60: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80070A64: jr          $ra
    // 0x80070A68: nop

    return;
    // 0x80070A68: nop

;}
