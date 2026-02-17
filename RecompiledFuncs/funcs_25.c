#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void menu_boot_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A84: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80088A88: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80088A8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80088A90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80088A94: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80088A98: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80088A9C: bne         $t6, $zero, L_80088AA8
    if (ctx->r14 != 0) {
        // 0x80088AA0: addiu       $v1, $zero, 0x78
        ctx->r3 = ADD32(0, 0X78);
            goto L_80088AA8;
    }
    // 0x80088AA0: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // 0x80088AA4: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_80088AA8:
    // 0x80088AA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088AAC: lw          $v0, 0x71E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X71E0);
    // 0x80088AB0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80088AB4: beq         $v0, $zero, L_80088ADC
    if (ctx->r2 == 0) {
        // 0x80088AB8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80088ADC;
    }
    // 0x80088AB8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80088ABC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088AC0: beq         $v0, $at, L_80088B28
    if (ctx->r2 == ctx->r1) {
        // 0x80088AC4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80088B28;
    }
    // 0x80088AC4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80088AC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80088ACC: beq         $v0, $at, L_80088B90
    if (ctx->r2 == ctx->r1) {
        // 0x80088AD0: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_80088B90;
    }
    // 0x80088AD0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80088AD4: b           L_80088BE4
    // 0x80088AD8: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
        goto L_80088BE4;
    // 0x80088AD8: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
L_80088ADC:
    // 0x80088ADC: addiu       $v1, $v1, 0x71D8
    ctx->r3 = ADD32(ctx->r3, 0X71D8);
    // 0x80088AE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80088AE4: nop

    // 0x80088AE8: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80088AEC: beq         $at, $zero, L_80088B0C
    if (ctx->r1 == 0) {
        // 0x80088AF0: addu        $t7, $v0, $a1
        ctx->r15 = ADD32(ctx->r2, ctx->r5);
            goto L_80088B0C;
    }
    // 0x80088AF0: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x80088AF4: slti        $at, $t7, 0x21
    ctx->r1 = SIGNED(ctx->r15) < 0X21 ? 1 : 0;
    // 0x80088AF8: bne         $at, $zero, L_80088BE0
    if (ctx->r1 != 0) {
        // 0x80088AFC: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80088BE0;
    }
    // 0x80088AFC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80088B00: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80088B04: b           L_80088BE0
    // 0x80088B08: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_80088BE0;
    // 0x80088B08: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80088B0C:
    // 0x80088B0C: jal         0x80088C60
    // 0x80088B10: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    bootscreen_init_cpak(rdram, ctx);
        goto after_0;
    // 0x80088B10: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80088B14: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80088B18: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80088B1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088B20: b           L_80088BE0
    // 0x80088B24: sw          $t0, 0x71E0($at)
    MEM_W(0X71E0, ctx->r1) = ctx->r8;
        goto L_80088BE0;
    // 0x80088B24: sw          $t0, 0x71E0($at)
    MEM_W(0X71E0, ctx->r1) = ctx->r8;
L_80088B28:
    // 0x80088B28: addiu       $v1, $v1, 0x71D8
    ctx->r3 = ADD32(ctx->r3, 0X71D8);
    // 0x80088B2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80088B30: nop

    // 0x80088B34: slti        $at, $v0, 0x8C
    ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
    // 0x80088B38: beq         $at, $zero, L_80088B5C
    if (ctx->r1 == 0) {
        // 0x80088B3C: addu        $t1, $v0, $a1
        ctx->r9 = ADD32(ctx->r2, ctx->r5);
            goto L_80088B5C;
    }
    // 0x80088B3C: addu        $t1, $v0, $a1
    ctx->r9 = ADD32(ctx->r2, ctx->r5);
    // 0x80088B40: slti        $at, $t1, 0x8D
    ctx->r1 = SIGNED(ctx->r9) < 0X8D ? 1 : 0;
    // 0x80088B44: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80088B48: bne         $at, $zero, L_80088B7C
    if (ctx->r1 != 0) {
        // 0x80088B4C: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80088B7C;
    }
    // 0x80088B4C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80088B50: addiu       $v0, $zero, 0x8C
    ctx->r2 = ADD32(0, 0X8C);
    // 0x80088B54: b           L_80088B7C
    // 0x80088B58: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80088B7C;
    // 0x80088B58: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80088B5C:
    // 0x80088B5C: jal         0x80088C3C
    // 0x80088B60: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    bootscreen_free(rdram, ctx);
        goto after_1;
    // 0x80088B60: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x80088B64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088B68: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80088B6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088B70: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80088B74: lw          $v0, 0x71D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X71D8);
    // 0x80088B78: sw          $t3, 0x71E0($at)
    MEM_W(0X71E0, ctx->r1) = ctx->r11;
L_80088B7C:
    // 0x80088B7C: slti        $at, $v0, 0x81
    ctx->r1 = SIGNED(ctx->r2) < 0X81 ? 1 : 0;
    // 0x80088B80: bne         $at, $zero, L_80088BE4
    if (ctx->r1 != 0) {
        // 0x80088B84: slti        $at, $a3, 0x12C
        ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
            goto L_80088BE4;
    }
    // 0x80088B84: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
    // 0x80088B88: b           L_80088BE0
    // 0x80088B8C: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
        goto L_80088BE0;
    // 0x80088B8C: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
L_80088B90:
    // 0x80088B90: lw          $t4, -0x604($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X604);
    // 0x80088B94: nop

    // 0x80088B98: beq         $t4, $zero, L_80088BCC
    if (ctx->r12 == 0) {
        // 0x80088B9C: addiu       $a3, $zero, 0x12C
        ctx->r7 = ADD32(0, 0X12C);
            goto L_80088BCC;
    }
    // 0x80088B9C: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    // 0x80088BA0: jal         0x800C06AC
    // 0x80088BA4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    check_fadeout_transition(rdram, ctx);
        goto after_2;
    // 0x80088BA4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_2:
    // 0x80088BA8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80088BAC: bne         $v0, $zero, L_80088BC8
    if (ctx->r2 != 0) {
        // 0x80088BB0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80088BC8;
    }
    // 0x80088BB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088BB4: addiu       $a0, $a0, -0x314
    ctx->r4 = ADD32(ctx->r4, -0X314);
    // 0x80088BB8: jal         0x800C06F8
    // 0x80088BBC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x80088BBC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_3:
    // 0x80088BC0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80088BC4: nop

L_80088BC8:
    // 0x80088BC8: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
L_80088BCC:
    // 0x80088BCC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80088BD0: jal         0x80089540
    // 0x80088BD4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    menu_controller_pak_loop(rdram, ctx);
        goto after_4;
    // 0x80088BD4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80088BD8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80088BDC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80088BE0:
    // 0x80088BE0: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
L_80088BE4:
    // 0x80088BE4: beq         $at, $zero, L_80088C2C
    if (ctx->r1 == 0) {
        // 0x80088BE8: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80088C2C;
    }
    // 0x80088BE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088BEC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80088BF0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80088BF4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80088BF8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80088BFC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80088C00: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80088C04: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80088C08: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80088C0C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80088C10: addiu       $a1, $a1, -0x2A4
    ctx->r5 = ADD32(ctx->r5, -0X2A4);
    // 0x80088C14: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80088C18: jal         0x80078F08
    // 0x80088C1C: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    texrect_draw(rdram, ctx);
        goto after_5;
    // 0x80088C1C: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    after_5:
    // 0x80088C20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088C24: jal         0x8007B820
    // 0x80088C28: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    rendermode_reset(rdram, ctx);
        goto after_6;
    // 0x80088C28: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_6:
L_80088C2C:
    // 0x80088C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80088C30: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80088C34: jr          $ra
    // 0x80088C38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80088C38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bootscreen_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088C44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088C48: jal         0x8009C9EC
    // 0x80088C4C: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x80088C4C: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    after_0:
    // 0x80088C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088C54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80088C58: jr          $ra
    // 0x80088C5C: nop

    return;
    // 0x80088C5C: nop

;}
RECOMP_FUNC void bootscreen_init_cpak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088C68: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x80088C6C: jal         0x80070EDC
    // 0x80088C70: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80088C70: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80088C74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80088C78: addiu       $a1, $a1, 0x7060
    ctx->r5 = ADD32(ctx->r5, 0X7060);
    // 0x80088C7C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088C80: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80088C84: addiu       $a0, $a0, 0x7064
    ctx->r4 = ADD32(ctx->r4, 0X7064);
    // 0x80088C88: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_80088C8C:
    // 0x80088C8C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80088C90: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80088C94: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80088C98: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80088C9C: slti        $at, $v1, 0x200
    ctx->r1 = SIGNED(ctx->r3) < 0X200 ? 1 : 0;
    // 0x80088CA0: bne         $at, $zero, L_80088C8C
    if (ctx->r1 != 0) {
        // 0x80088CA4: sw          $t7, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->r15;
            goto L_80088C8C;
    }
    // 0x80088CA4: sw          $t7, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r15;
    // 0x80088CA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088CAC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80088CB0: addiu       $v1, $v1, 0x7021
    ctx->r3 = ADD32(ctx->r3, 0X7021);
    // 0x80088CB4: addiu       $v0, $v0, 0x7020
    ctx->r2 = ADD32(ctx->r2, 0X7020);
L_80088CB8:
    // 0x80088CB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80088CBC: bne         $v0, $v1, L_80088CB8
    if (ctx->r2 != ctx->r3) {
        // 0x80088CC0: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_80088CB8;
    }
    // 0x80088CC0: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x80088CC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088CC8: sw          $zero, 0x71D0($at)
    MEM_W(0X71D0, ctx->r1) = 0;
    // 0x80088CCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088CD0: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x80088CD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088CD8: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80088CDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088CE0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80088CE4: jal         0x8009F064
    // 0x80088CE8: sw          $t8, 0x7028($at)
    MEM_W(0X7028, ctx->r1) = ctx->r24;
    get_language(rdram, ctx);
        goto after_1;
    // 0x80088CE8: sw          $t8, 0x7028($at)
    MEM_W(0X7028, ctx->r1) = ctx->r24;
    after_1:
    // 0x80088CEC: jal         0x8007FD50
    // 0x80088CF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    load_menu_text(rdram, ctx);
        goto after_2;
    // 0x80088CF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80088CF4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088CF8: addiu       $a0, $a0, 0x7028
    ctx->r4 = ADD32(ctx->r4, 0X7028);
    // 0x80088CFC: jal         0x8008838C
    // 0x80088D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80087F14(rdram, ctx);
        goto after_3;
    // 0x80088D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80088D04: bne         $v0, $zero, L_80088D14
    if (ctx->r2 != 0) {
        // 0x80088D08: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80088D14;
    }
    // 0x80088D08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088D0C: b           L_80088D2C
    // 0x80088D10: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
        goto L_80088D2C;
    // 0x80088D10: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
L_80088D14:
    // 0x80088D14: jal         0x800887A4
    // 0x80088D18: nop

    check_for_controller_pak_errors(rdram, ctx);
        goto after_4;
    // 0x80088D18: nop

    after_4:
    // 0x80088D1C: bne         $v0, $zero, L_80088D2C
    if (ctx->r2 != 0) {
        // 0x80088D20: addiu       $t9, $zero, 0x14
        ctx->r25 = ADD32(0, 0X14);
            goto L_80088D2C;
    }
    // 0x80088D20: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80088D24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088D28: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
L_80088D2C:
    // 0x80088D2C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80088D30: lw          $t0, 0x7188($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7188);
    // 0x80088D34: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80088D38: bne         $t0, $zero, L_80088D54
    if (ctx->r8 != 0) {
        // 0x80088D3C: addiu       $a0, $zero, 0x3F
        ctx->r4 = ADD32(0, 0X3F);
            goto L_80088D54;
    }
    // 0x80088D3C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x80088D40: lw          $t1, 0x314($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X314);
    // 0x80088D44: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x80088D48: bne         $t1, $zero, L_80088D54
    if (ctx->r9 != 0) {
        // 0x80088D4C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80088D54;
    }
    // 0x80088D4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088D50: sw          $t2, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r10;
L_80088D54:
    // 0x80088D54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088D58: sw          $zero, -0x620($at)
    MEM_W(-0X620, ctx->r1) = 0;
    // 0x80088D5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088D60: jal         0x8009CC18
    // 0x80088D64: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    menu_asset_load(rdram, ctx);
        goto after_5;
    // 0x80088D64: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    after_5:
    // 0x80088D68: jal         0x8008E968
    // 0x80088D6C: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_6;
    // 0x80088D6C: nop

    after_6:
    // 0x80088D70: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80088D74: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x80088D78: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80088D7C: bne         $t3, $zero, L_80088D94
    if (ctx->r11 != 0) {
        // 0x80088D80: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80088D94;
    }
    // 0x80088D80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088D84: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80088D88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088D8C: b           L_80088D98
    // 0x80088D90: sw          $t4, 0x7174($at)
    MEM_W(0X7174, ctx->r1) = ctx->r12;
        goto L_80088D98;
    // 0x80088D90: sw          $t4, 0x7174($at)
    MEM_W(0X7174, ctx->r1) = ctx->r12;
L_80088D94:
    // 0x80088D94: sw          $t5, 0x7174($at)
    MEM_W(0X7174, ctx->r1) = ctx->r13;
L_80088D98:
    // 0x80088D98: jal         0x800C46D0
    // 0x80088D9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_7;
    // 0x80088D9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x80088DA0: jal         0x800724D8
    // 0x80088DA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rumble_enable(rdram, ctx);
        goto after_8;
    // 0x80088DA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x80088DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80088DB0: jr          $ra
    // 0x80088DB4: nop

    return;
    // 0x80088DB4: nop

;}
RECOMP_FUNC void pakmenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DB8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80088DBC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80088DC0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80088DC4: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80088DC8: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80088DCC: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80088DD0: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80088DD4: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80088DD8: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80088DDC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80088DE0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80088DE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80088DE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088DEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088DF0: jal         0x800C492C
    // 0x80088DF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_0;
    // 0x80088DF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80088DF8: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80088DFC: lw          $s6, 0x695C($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X695C);
    // 0x80088E00: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80088E04: sll         $t6, $s6, 3
    ctx->r14 = S32(ctx->r22 << 3);
    // 0x80088E08: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80088E0C: bne         $at, $zero, L_80088E1C
    if (ctx->r1 != 0) {
        // 0x80088E10: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_80088E1C;
    }
    // 0x80088E10: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x80088E14: addiu       $t7, $zero, 0x1FF
    ctx->r15 = ADD32(0, 0X1FF);
    // 0x80088E18: subu        $s6, $t7, $t6
    ctx->r22 = SUB32(ctx->r15, ctx->r14);
L_80088E1C:
    // 0x80088E1C: lw          $t8, 0x7188($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7188);
    // 0x80088E20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80088E24: beq         $t8, $zero, L_80088E44
    if (ctx->r24 == 0) {
        // 0x80088E28: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_80088E44;
    }
    // 0x80088E28: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80088E2C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80088E30: addiu       $a1, $a1, 0x234
    ctx->r5 = ADD32(ctx->r5, 0X234);
    // 0x80088E34: jal         0x8008263C
    // 0x80088E38: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_1;
    // 0x80088E38: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80088E3C: b           L_80089518
    // 0x80088E40: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80089518;
    // 0x80088E40: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80088E44:
    // 0x80088E44: lw          $t9, 0x314($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X314);
    // 0x80088E48: nop

    // 0x80088E4C: beq         $t9, $zero, L_80089518
    if (ctx->r25 == 0) {
        // 0x80088E50: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80089518;
    }
    // 0x80088E50: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80088E54: jal         0x800C484C
    // 0x80088E58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x80088E58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80088E5C: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x80088E60: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80088E64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80088E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088E6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088E70: jal         0x800C48E4
    // 0x80088E74: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_3;
    // 0x80088E74: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x80088E78: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80088E7C: addiu       $s7, $s7, -0x5E0
    ctx->r23 = ADD32(ctx->r23, -0X5E0);
    // 0x80088E80: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x80088E84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088E88: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80088E8C: lw          $a3, 0x8C($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8C);
    // 0x80088E90: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80088E94: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80088E98: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80088E9C: jal         0x800C49A0
    // 0x80088EA0: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    draw_text(rdram, ctx);
        goto after_4;
    // 0x80088EA0: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    after_4:
    // 0x80088EA4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80088EA8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80088EAC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80088EB0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088EB4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088EB8: jal         0x800C48E4
    // 0x80088EBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_5;
    // 0x80088EBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80088EC0: lw          $t4, 0x0($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X0);
    // 0x80088EC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088EC8: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80088ECC: lw          $a3, 0x8C($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8C);
    // 0x80088ED0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80088ED4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80088ED8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80088EDC: jal         0x800C49A0
    // 0x80088EE0: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    draw_text(rdram, ctx);
        goto after_6;
    // 0x80088EE0: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_6:
    // 0x80088EE4: addiu       $s5, $zero, 0x30
    ctx->r21 = ADD32(0, 0X30);
    // 0x80088EE8: jal         0x800C59F4
    // 0x80088EEC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_7;
    // 0x80088EEC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_7:
    // 0x80088EF0: addiu       $t6, $s5, 0x1E
    ctx->r14 = ADD32(ctx->r21, 0X1E);
    // 0x80088EF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80088EF8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088EFC: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80088F00: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80088F04: jal         0x800C543C
    // 0x80088F08: addiu       $a3, $zero, 0x106
    ctx->r7 = ADD32(0, 0X106);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_8;
    // 0x80088F08: addiu       $a3, $zero, 0x106
    ctx->r7 = ADD32(0, 0X106);
    after_8:
    // 0x80088F0C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80088F10: lw          $t7, -0x620($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X620);
    // 0x80088F14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80088F18: bne         $t7, $at, L_80088F44
    if (ctx->r15 != ctx->r1) {
        // 0x80088F1C: sra         $t8, $s6, 1
        ctx->r24 = S32(SIGNED(ctx->r22) >> 1);
            goto L_80088F44;
    }
    // 0x80088F1C: sra         $t8, $s6, 1
    ctx->r24 = S32(SIGNED(ctx->r22) >> 1);
    // 0x80088F20: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x80088F24: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80088F28: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F2C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088F30: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088F34: jal         0x800C551C
    // 0x80088F38: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_9;
    // 0x80088F38: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_9:
    // 0x80088F3C: b           L_80088F64
    // 0x80088F40: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
        goto L_80088F64;
    // 0x80088F40: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_80088F44:
    // 0x80088F44: addiu       $t0, $zero, 0xE0
    ctx->r8 = ADD32(0, 0XE0);
    // 0x80088F48: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80088F4C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F50: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x80088F54: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80088F58: jal         0x800C551C
    // 0x80088F5C: addiu       $a3, $zero, 0x5C
    ctx->r7 = ADD32(0, 0X5C);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_10;
    // 0x80088F5C: addiu       $a3, $zero, 0x5C
    ctx->r7 = ADD32(0, 0X5C);
    after_10:
    // 0x80088F60: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_80088F64:
    // 0x80088F64: jal         0x800C54DC
    // 0x80088F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_11;
    // 0x80088F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80088F6C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80088F70: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80088F74: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F78: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088F7C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088F80: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80088F84: jal         0x800C5560
    // 0x80088F88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_12;
    // 0x80088F88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_12:
    // 0x80088F8C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088F94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088F98: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80088F9C: jal         0x800C55B0
    // 0x80088FA0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_13;
    // 0x80088FA0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x80088FA4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80088FA8: lw          $t3, 0x7028($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7028);
    // 0x80088FAC: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x80088FB0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80088FB4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80088FB8: lw          $a3, 0x158($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X158);
    // 0x80088FBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80088FC0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80088FC4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80088FC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80088FCC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088FD0: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80088FD4: jal         0x800C56C8
    // 0x80088FD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_text(rdram, ctx);
        goto after_14;
    // 0x80088FD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_14:
    // 0x80088FDC: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80088FE0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80088FE4: lw          $t9, 0x7170($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7170);
    // 0x80088FE8: lw          $a3, 0x1C8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X1C8);
    // 0x80088FEC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80088FF0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80088FF4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088FF8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80088FFC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80089000: jal         0x800C56C8
    // 0x80089004: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    render_dialogue_text(rdram, ctx);
        goto after_15;
    // 0x80089004: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_15:
    // 0x80089008: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008900C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089018: jal         0x800C60B8
    // 0x8008901C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    render_dialogue_box(rdram, ctx);
        goto after_16;
    // 0x8008901C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_16:
    // 0x80089020: addiu       $s5, $s5, 0x22
    ctx->r21 = ADD32(ctx->r21, 0X22);
    // 0x80089024: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089028: jal         0x800C54DC
    // 0x8008902C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    set_dialogue_font(rdram, ctx);
        goto after_17;
    // 0x8008902C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80089030: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089038: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008903C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80089040: jal         0x800C55B0
    // 0x80089044: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_18;
    // 0x80089044: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_18:
    // 0x80089048: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008904C: lw          $v0, 0x7174($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7174);
    // 0x80089050: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80089054: bltz        $v0, L_80089248
    if (SIGNED(ctx->r2) < 0) {
        // 0x80089058: nop
    
            goto L_80089248;
    }
    // 0x80089058: nop

L_8008905C:
    // 0x8008905C: jal         0x800C59F4
    // 0x80089060: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_19;
    // 0x80089060: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_19:
    // 0x80089064: addiu       $t1, $s5, 0xE
    ctx->r9 = ADD32(ctx->r21, 0XE);
    // 0x80089068: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008906C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089070: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80089074: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80089078: jal         0x800C543C
    // 0x8008907C: addiu       $a3, $zero, 0x124
    ctx->r7 = ADD32(0, 0X124);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_20;
    // 0x8008907C: addiu       $a3, $zero, 0x124
    ctx->r7 = ADD32(0, 0X124);
    after_20:
    // 0x80089080: bgez        $s1, L_800890EC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80089084: lui         $t6, 0x800F
        ctx->r14 = S32(0X800F << 16);
            goto L_800890EC;
    }
    // 0x80089084: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80089088: addiu       $t3, $zero, 0xE0
    ctx->r11 = ADD32(0, 0XE0);
    // 0x8008908C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089090: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089094: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80089098: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x8008909C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x800890A0: jal         0x800C551C
    // 0x800890A4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_21;
    // 0x800890A4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    after_21:
    // 0x800890A8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800890AC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800890B0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800890B4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800890B8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800890BC: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x800890C0: addiu       $a2, $zero, 0xE0
    ctx->r6 = ADD32(0, 0XE0);
    // 0x800890C4: jal         0x800C5560
    // 0x800890C8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    set_current_text_colour(rdram, ctx);
        goto after_22;
    // 0x800890C8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_22:
    // 0x800890CC: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x800890D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800890D4: lw          $t5, 0x6978($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6978);
    // 0x800890D8: lw          $s2, 0x1CC($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X1CC);
    // 0x800890DC: lw          $s0, 0x1D0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X1D0);
    // 0x800890E0: lw          $s4, 0x1D4($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X1D4);
    // 0x800890E4: b           L_800891A0
    // 0x800890E8: addu        $v1, $s1, $t5
    ctx->r3 = ADD32(ctx->r17, ctx->r13);
        goto L_800891A0;
    // 0x800890E8: addu        $v1, $s1, $t5
    ctx->r3 = ADD32(ctx->r17, ctx->r13);
L_800890EC:
    // 0x800890EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800890F0: lw          $t8, 0x6978($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6978);
    // 0x800890F4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800890F8: lw          $t7, -0x620($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X620);
    // 0x800890FC: addiu       $s4, $t6, -0x7864
    ctx->r20 = ADD32(ctx->r14, -0X7864);
    // 0x80089100: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x80089104: bne         $t7, $t9, L_80089134
    if (ctx->r15 != ctx->r25) {
        // 0x80089108: or          $s2, $s4, $zero
        ctx->r18 = ctx->r20 | 0;
            goto L_80089134;
    }
    // 0x80089108: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x8008910C: sra         $t0, $s6, 1
    ctx->r8 = S32(SIGNED(ctx->r22) >> 1);
    // 0x80089110: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x80089114: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089118: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008911C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089120: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089124: jal         0x800C551C
    // 0x80089128: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_23;
    // 0x80089128: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_23:
    // 0x8008912C: b           L_80089154
    // 0x80089130: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
        goto L_80089154;
    // 0x80089130: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
L_80089134:
    // 0x80089134: addiu       $t3, $zero, 0xE0
    ctx->r11 = ADD32(0, 0XE0);
    // 0x80089138: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8008913C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089140: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80089144: addiu       $a2, $zero, 0xE0
    ctx->r6 = ADD32(0, 0XE0);
    // 0x80089148: jal         0x800C551C
    // 0x8008914C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_24;
    // 0x8008914C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_24:
    // 0x80089150: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
L_80089154:
    // 0x80089154: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80089158: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8008915C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80089160: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089164: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80089168: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8008916C: jal         0x800C5560
    // 0x80089170: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    set_current_text_colour(rdram, ctx);
        goto after_25;
    // 0x80089170: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    after_25:
    // 0x80089174: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80089178: lw          $t5, 0x6978($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6978);
    // 0x8008917C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80089180: addu        $v1, $t5, $s1
    ctx->r3 = ADD32(ctx->r13, ctx->r17);
    // 0x80089184: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80089188: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8008918C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80089190: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x80089194: lw          $s0, 0x7060($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7060);
    // 0x80089198: lw          $s3, 0x7130($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X7130);
    // 0x8008919C: nop

L_800891A0:
    // 0x800891A0: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800891A4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800891A8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800891AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800891B0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800891B4: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x800891B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800891BC: jal         0x800C56C8
    // 0x800891C0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_26;
    // 0x800891C0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_26:
    // 0x800891C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800891C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800891CC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800891D0: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x800891D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800891D8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800891DC: jal         0x800C56C8
    // 0x800891E0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    render_dialogue_text(rdram, ctx);
        goto after_27;
    // 0x800891E0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_27:
    // 0x800891E4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800891E8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800891EC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800891F0: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x800891F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800891F8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800891FC: jal         0x800C56C8
    // 0x80089200: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    render_dialogue_text(rdram, ctx);
        goto after_28;
    // 0x80089200: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_28:
    // 0x80089204: jal         0x800C46C4
    // 0x80089208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_kerning(rdram, ctx);
        goto after_29;
    // 0x80089208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_29:
    // 0x8008920C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089210: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089218: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008921C: jal         0x800C60B8
    // 0x80089220: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    render_dialogue_box(rdram, ctx);
        goto after_30;
    // 0x80089220: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_30:
    // 0x80089224: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x80089228: jal         0x800C46C4
    // 0x8008922C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_kerning(rdram, ctx);
        goto after_31;
    // 0x8008922C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x80089230: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80089234: lw          $v0, 0x7174($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7174);
    // 0x80089238: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008923C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80089240: bne         $at, $zero, L_8008905C
    if (ctx->r1 != 0) {
        // 0x80089244: nop
    
            goto L_8008905C;
    }
    // 0x80089244: nop

L_80089248:
    // 0x80089248: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008924C: lw          $t0, 0x6978($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6978);
    // 0x80089250: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    // 0x80089254: subu        $t1, $s0, $v0
    ctx->r9 = SUB32(ctx->r16, ctx->r2);
    // 0x80089258: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8008925C: beq         $at, $zero, L_800892C0
    if (ctx->r1 == 0) {
        // 0x80089260: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800892C0;
    }
    // 0x80089260: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80089264: lw          $t3, 0x695C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X695C);
    // 0x80089268: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008926C: andi        $t2, $t3, 0x8
    ctx->r10 = ctx->r11 & 0X8;
    // 0x80089270: beq         $t2, $zero, L_80089338
    if (ctx->r10 == 0) {
        // 0x80089274: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_80089338;
    }
    // 0x80089274: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089278: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008927C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80089280: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80089284: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80089288: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008928C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80089290: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80089294: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80089298: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008929C: addiu       $a1, $a1, 0x9BC
    ctx->r5 = ADD32(ctx->r5, 0X9BC);
    // 0x800892A0: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x800892A4: jal         0x80078F08
    // 0x800892A8: addiu       $a3, $s5, 0x8
    ctx->r7 = ADD32(ctx->r21, 0X8);
    texrect_draw(rdram, ctx);
        goto after_32;
    // 0x800892A8: addiu       $a3, $s5, 0x8
    ctx->r7 = ADD32(ctx->r21, 0X8);
    after_32:
    // 0x800892AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800892B0: jal         0x8007B820
    // 0x800892B4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    rendermode_reset(rdram, ctx);
        goto after_33;
    // 0x800892B4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_33:
    // 0x800892B8: b           L_80089338
    // 0x800892BC: nop

        goto L_80089338;
    // 0x800892BC: nop

L_800892C0:
    // 0x800892C0: jal         0x800C484C
    // 0x800892C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_34;
    // 0x800892C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_34:
    // 0x800892C8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800892CC: lw          $t7, -0x620($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X620);
    // 0x800892D0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800892D4: bne         $s0, $t7, L_80089300
    if (ctx->r16 != ctx->r15) {
        // 0x800892D8: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80089300;
    }
    // 0x800892D8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800892DC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800892E0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800892E4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800892E8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800892EC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800892F0: jal         0x800C48E4
    // 0x800892F4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    set_text_colour(rdram, ctx);
        goto after_35;
    // 0x800892F4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_35:
    // 0x800892F8: b           L_80089318
    // 0x800892FC: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
        goto L_80089318;
    // 0x800892FC: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
L_80089300:
    // 0x80089300: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80089304: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80089308: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008930C: jal         0x800C48E4
    // 0x80089310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_36;
    // 0x80089310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_36:
    // 0x80089314: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
L_80089318:
    // 0x80089318: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008931C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80089320: lw          $a3, 0xCC($t1)
    ctx->r7 = MEM_W(ctx->r9, 0XCC);
    // 0x80089324: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089328: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008932C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089330: jal         0x800C49A0
    // 0x80089334: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    draw_text(rdram, ctx);
        goto after_37;
    // 0x80089334: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_37:
L_80089338:
    // 0x80089338: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8008933C: addiu       $s3, $s3, 0x6980
    ctx->r19 = ADD32(ctx->r19, 0X6980);
    // 0x80089340: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80089344: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80089348: beq         $t2, $zero, L_800894C0
    if (ctx->r10 == 0) {
        // 0x8008934C: nop
    
            goto L_800894C0;
    }
    // 0x8008934C: nop

    // 0x80089350: lw          $t4, 0x71D0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X71D0);
    // 0x80089354: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80089358: bne         $t4, $zero, L_800894C0
    if (ctx->r12 != 0) {
        // 0x8008935C: nop
    
            goto L_800894C0;
    }
    // 0x8008935C: nop

    // 0x80089360: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x80089364: addiu       $s5, $zero, 0x78
    ctx->r21 = ADD32(0, 0X78);
    // 0x80089368: bne         $t5, $zero, L_80089378
    if (ctx->r13 != 0) {
        // 0x8008936C: nop
    
            goto L_80089378;
    }
    // 0x8008936C: nop

    // 0x80089370: b           L_80089378
    // 0x80089374: addiu       $s5, $zero, 0x86
    ctx->r21 = ADD32(0, 0X86);
        goto L_80089378;
    // 0x80089374: addiu       $s5, $zero, 0x86
    ctx->r21 = ADD32(0, 0X86);
L_80089378:
    // 0x80089378: jal         0x800C59F4
    // 0x8008937C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_38;
    // 0x8008937C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_38:
    // 0x80089380: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089384: jal         0x800C54DC
    // 0x80089388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_39;
    // 0x80089388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_39:
    // 0x8008938C: addiu       $t6, $s5, 0x1C
    ctx->r14 = ADD32(ctx->r21, 0X1C);
    // 0x80089390: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80089394: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089398: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x8008939C: addiu       $a2, $s5, -0x1C
    ctx->r6 = ADD32(ctx->r21, -0X1C);
    // 0x800893A0: jal         0x800C543C
    // 0x800893A4: addiu       $a3, $zero, 0xF4
    ctx->r7 = ADD32(0, 0XF4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_40;
    // 0x800893A4: addiu       $a3, $zero, 0xF4
    ctx->r7 = ADD32(0, 0XF4);
    after_40:
    // 0x800893A8: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x800893AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800893B0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800893B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800893B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800893BC: jal         0x800C551C
    // 0x800893C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_41;
    // 0x800893C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_41:
    // 0x800893C4: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x800893C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800893CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800893D0: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_800893D4:
    // 0x800893D4: bne         $s1, $zero, L_80089404
    if (ctx->r17 != 0) {
        // 0x800893D8: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_80089404;
    }
    // 0x800893D8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800893DC: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x800893E0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800893E4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800893E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800893EC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800893F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800893F4: jal         0x800C5560
    // 0x800893F8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_text_colour(rdram, ctx);
        goto after_42;
    // 0x800893F8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_42:
    // 0x800893FC: b           L_80089458
    // 0x80089400: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
        goto L_80089458;
    // 0x80089400: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
L_80089404:
    // 0x80089404: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80089408: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008940C: bne         $s1, $t0, L_8008943C
    if (ctx->r17 != ctx->r8) {
        // 0x80089410: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008943C;
    }
    // 0x80089410: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089414: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80089418: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8008941C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089420: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089424: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089428: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8008942C: jal         0x800C5560
    // 0x80089430: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    set_current_text_colour(rdram, ctx);
        goto after_43;
    // 0x80089430: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_43:
    // 0x80089434: b           L_80089458
    // 0x80089438: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
        goto L_80089458;
    // 0x80089438: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
L_8008943C:
    // 0x8008943C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80089440: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80089444: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089448: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8008944C: jal         0x800C5560
    // 0x80089450: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_44;
    // 0x80089450: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_44:
    // 0x80089454: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
L_80089458:
    // 0x80089458: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008945C: lw          $t5, -0x620($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X620);
    // 0x80089460: addu        $t4, $t2, $s0
    ctx->r12 = ADD32(ctx->r10, ctx->r16);
    // 0x80089464: lw          $a3, 0x1BC($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X1BC);
    // 0x80089468: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8008946C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80089470: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80089474: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80089478: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008947C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089480: jal         0x800C56C8
    // 0x80089484: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_45;
    // 0x80089484: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_45:
    // 0x80089488: beq         $s1, $zero, L_80089498
    if (ctx->r17 == 0) {
        // 0x8008948C: nop
    
            goto L_80089498;
    }
    // 0x8008948C: nop

    // 0x80089490: b           L_8008949C
    // 0x80089494: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
        goto L_8008949C;
    // 0x80089494: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
L_80089498:
    // 0x80089498: addiu       $s5, $s5, 0x14
    ctx->r21 = ADD32(ctx->r21, 0X14);
L_8008949C:
    // 0x8008949C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800894A0: bne         $s1, $s2, L_800893D4
    if (ctx->r17 != ctx->r18) {
        // 0x800894A4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800893D4;
    }
    // 0x800894A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800894A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800894AC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800894B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800894B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800894B8: jal         0x800C60B8
    // 0x800894BC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    render_dialogue_box(rdram, ctx);
        goto after_46;
    // 0x800894BC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_46:
L_800894C0:
    // 0x800894C0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800894C4: lw          $t7, 0x71D0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X71D0);
    // 0x800894C8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800894CC: beq         $t7, $zero, L_80089514
    if (ctx->r15 == 0) {
        // 0x800894D0: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80089514;
    }
    // 0x800894D0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800894D4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800894D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800894DC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800894E0: jal         0x800C48E4
    // 0x800894E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_47;
    // 0x800894E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_47:
    // 0x800894E8: jal         0x800C484C
    // 0x800894EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_48;
    // 0x800894EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_48:
    // 0x800894F0: lw          $t0, 0x0($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X0);
    // 0x800894F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800894F8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800894FC: lw          $a3, 0x1F0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X1F0);
    // 0x80089500: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089504: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089508: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008950C: jal         0x800C49A0
    // 0x80089510: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    draw_text(rdram, ctx);
        goto after_49;
    // 0x80089510: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_49:
L_80089514:
    // 0x80089514: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80089518:
    // 0x80089518: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8008951C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80089520: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80089524: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80089528: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8008952C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80089530: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80089534: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80089538: jr          $ra
    // 0x8008953C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8008953C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void menu_controller_pak_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089540: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80089544: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x80089548: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008954C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80089550: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x80089554: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80089558: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008955C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80089560: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x80089564: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80089568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008956C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80089570: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80089574: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80089578: beq         $at, $zero, L_8008959C
    if (ctx->r1 == 0) {
        // 0x8008957C: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008959C;
    }
    // 0x8008957C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80089580: jal         0x80088DB8
    // 0x80089584: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    pakmenu_render(rdram, ctx);
        goto after_0;
    // 0x80089584: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80089588: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008958C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80089590: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80089594: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80089598: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_8008959C:
    // 0x8008959C: bne         $v0, $zero, L_800899FC
    if (ctx->r2 != 0) {
        // 0x800895A0: addu        $t4, $v0, $a0
        ctx->r12 = ADD32(ctx->r2, ctx->r4);
            goto L_800899FC;
    }
    // 0x800895A0: addu        $t4, $v0, $a0
    ctx->r12 = ADD32(ctx->r2, ctx->r4);
    // 0x800895A4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800895A8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800895AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800895B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800895B4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800895B8: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x800895BC: addiu       $v1, $v1, 0x69FC
    ctx->r3 = ADD32(ctx->r3, 0X69FC);
    // 0x800895C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800895C4:
    // 0x800895C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800895C8: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    // 0x800895CC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x800895D0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800895D4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800895D8: jal         0x8006A794
    // 0x800895DC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x800895DC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x800895E0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800895E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800895E8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800895EC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800895F0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800895F4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800895F8: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x800895FC: lb          $t4, 0x0($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X0);
    // 0x80089600: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80089604: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80089608: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008960C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80089610: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x80089614: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x80089618: bne         $a0, $at, L_800895C4
    if (ctx->r4 != ctx->r1) {
        // 0x8008961C: addu        $t0, $t0, $t4
        ctx->r8 = ADD32(ctx->r8, ctx->r12);
            goto L_800895C4;
    }
    // 0x8008961C: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80089620: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80089624: lw          $v0, 0x7188($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7188);
    // 0x80089628: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008962C: beq         $v0, $zero, L_800896C8
    if (ctx->r2 == 0) {
        // 0x80089630: addiu       $t2, $t2, 0x6980
        ctx->r10 = ADD32(ctx->r10, 0X6980);
            goto L_800896C8;
    }
    // 0x80089630: addiu       $t2, $t2, 0x6980
    ctx->r10 = ADD32(ctx->r10, 0X6980);
    // 0x80089634: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089638: beq         $v0, $at, L_800899A4
    if (ctx->r2 == ctx->r1) {
        // 0x8008963C: andi        $t5, $a2, 0x9000
        ctx->r13 = ctx->r6 & 0X9000;
            goto L_800899A4;
    }
    // 0x8008963C: andi        $t5, $a2, 0x9000
    ctx->r13 = ctx->r6 & 0X9000;
    // 0x80089640: beq         $t5, $zero, L_800899A4
    if (ctx->r13 == 0) {
        // 0x80089644: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_800899A4;
    }
    // 0x80089644: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80089648: jal         0x80001D04
    // 0x8008964C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008964C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80089650: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089654: addiu       $a0, $a0, 0x7028
    ctx->r4 = ADD32(ctx->r4, 0X7028);
    // 0x80089658: jal         0x8008838C
    // 0x8008965C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80087F14(rdram, ctx);
        goto after_3;
    // 0x8008965C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80089660: bne         $v0, $zero, L_80089670
    if (ctx->r2 != 0) {
        // 0x80089664: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80089670;
    }
    // 0x80089664: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089668: b           L_80089684
    // 0x8008966C: sw          $zero, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = 0;
        goto L_80089684;
    // 0x8008966C: sw          $zero, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = 0;
L_80089670:
    // 0x80089670: jal         0x800887A4
    // 0x80089674: nop

    check_for_controller_pak_errors(rdram, ctx);
        goto after_4;
    // 0x80089674: nop

    after_4:
    // 0x80089678: bne         $v0, $zero, L_80089684
    if (ctx->r2 != 0) {
        // 0x8008967C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80089684;
    }
    // 0x8008967C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089680: sw          $zero, 0x314($at)
    MEM_W(0X314, ctx->r1) = 0;
L_80089684:
    // 0x80089684: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80089688: lw          $t6, 0x7188($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7188);
    // 0x8008968C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80089690: bne         $t6, $zero, L_800899A4
    if (ctx->r14 != 0) {
        // 0x80089694: nop
    
            goto L_800899A4;
    }
    // 0x80089694: nop

    // 0x80089698: lw          $t7, 0x314($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X314);
    // 0x8008969C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800896A0: bne         $t7, $zero, L_800899A4
    if (ctx->r15 != 0) {
        // 0x800896A4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800899A4;
    }
    // 0x800896A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800896A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800896AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800896B0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800896B4: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
    // 0x800896B8: jal         0x800C06F8
    // 0x800896BC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_5;
    // 0x800896BC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_5:
    // 0x800896C0: b           L_800899A8
    // 0x800896C4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
        goto L_800899A8;
    // 0x800896C4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_800896C8:
    // 0x800896C8: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800896CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800896D0: beq         $v0, $zero, L_80089818
    if (ctx->r2 == 0) {
        // 0x800896D4: andi        $t8, $a2, 0x4000
        ctx->r24 = ctx->r6 & 0X4000;
            goto L_80089818;
    }
    // 0x800896D4: andi        $t8, $a2, 0x4000
    ctx->r24 = ctx->r6 & 0X4000;
    // 0x800896D8: addiu       $a0, $a0, 0x71D0
    ctx->r4 = ADD32(ctx->r4, 0X71D0);
    // 0x800896DC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800896E0: andi        $t5, $a2, 0x4000
    ctx->r13 = ctx->r6 & 0X4000;
    // 0x800896E4: beq         $v1, $zero, L_80089798
    if (ctx->r3 == 0) {
        // 0x800896E8: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_80089798;
    }
    // 0x800896E8: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x800896EC: bne         $t4, $zero, L_800899A4
    if (ctx->r12 != 0) {
        // 0x800896F0: sw          $t4, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r12;
            goto L_800899A4;
    }
    // 0x800896F0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800896F4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800896F8: addiu       $t1, $t1, -0x620
    ctx->r9 = ADD32(ctx->r9, -0X620);
    // 0x800896FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089700: lw          $a0, 0x7028($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7028);
    // 0x80089704: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80089708: jal         0x80076520
    // 0x8008970C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    delete_file(rdram, ctx);
        goto after_6;
    // 0x8008970C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80089710: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80089714: beq         $v0, $zero, L_80089748
    if (ctx->r2 == 0) {
        // 0x80089718: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80089748;
    }
    // 0x80089718: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008971C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80089720: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80089724: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089728: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008972C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80089730: sw          $t7, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r15;
    // 0x80089734: jal         0x800C06F8
    // 0x80089738: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_7;
    // 0x80089738: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_7:
    // 0x8008973C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80089740: b           L_80089790
    // 0x80089744: addiu       $t2, $t2, 0x6980
    ctx->r10 = ADD32(ctx->r10, 0X6980);
        goto L_80089790;
    // 0x80089744: addiu       $t2, $t2, 0x6980
    ctx->r10 = ADD32(ctx->r10, 0X6980);
L_80089748:
    // 0x80089748: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008974C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80089750: addiu       $a0, $a0, 0x7028
    ctx->r4 = ADD32(ctx->r4, 0X7028);
    // 0x80089754: jal         0x8008838C
    // 0x80089758: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80087F14(rdram, ctx);
        goto after_8;
    // 0x80089758: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_8:
    // 0x8008975C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80089760: beq         $v0, $zero, L_80089790
    if (ctx->r2 == 0) {
        // 0x80089764: addiu       $t2, $t2, 0x6980
        ctx->r10 = ADD32(ctx->r10, 0X6980);
            goto L_80089790;
    }
    // 0x80089764: addiu       $t2, $t2, 0x6980
    ctx->r10 = ADD32(ctx->r10, 0X6980);
    // 0x80089768: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008976C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80089770: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089774: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80089778: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8008977C: sw          $t4, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r12;
    // 0x80089780: jal         0x800C06F8
    // 0x80089784: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_9;
    // 0x80089784: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_9:
    // 0x80089788: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008978C: addiu       $t2, $t2, 0x6980
    ctx->r10 = ADD32(ctx->r10, 0X6980);
L_80089790:
    // 0x80089790: b           L_800899A4
    // 0x80089794: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
        goto L_800899A4;
    // 0x80089794: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80089798:
    // 0x80089798: beq         $t5, $zero, L_800897B0
    if (ctx->r13 == 0) {
        // 0x8008979C: andi        $t7, $a2, 0x9000
        ctx->r15 = ctx->r6 & 0X9000;
            goto L_800897B0;
    }
    // 0x8008979C: andi        $t7, $a2, 0x9000
    ctx->r15 = ctx->r6 & 0X9000;
    // 0x800897A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800897A4: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800897A8: b           L_800899A4
    // 0x800897AC: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
        goto L_800899A4;
    // 0x800897AC: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_800897B0:
    // 0x800897B0: beq         $t7, $zero, L_800897D8
    if (ctx->r15 == 0) {
        // 0x800897B4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800897D8;
    }
    // 0x800897B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800897B8: bne         $v0, $at, L_800897C8
    if (ctx->r2 != ctx->r1) {
        // 0x800897BC: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_800897C8;
    }
    // 0x800897BC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800897C0: b           L_800899A4
    // 0x800897C4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
        goto L_800899A4;
    // 0x800897C4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_800897C8:
    // 0x800897C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800897CC: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800897D0: b           L_800899A4
    // 0x800897D4: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
        goto L_800899A4;
    // 0x800897D4: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_800897D8:
    // 0x800897D8: blez        $t0, L_800897F8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800897DC: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800897F8;
    }
    // 0x800897DC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800897E0: bne         $at, $zero, L_800897F8
    if (ctx->r1 != 0) {
        // 0x800897E4: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800897F8;
    }
    // 0x800897E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800897E8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800897EC: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x800897F0: b           L_800899A4
    // 0x800897F4: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
        goto L_800899A4;
    // 0x800897F4: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_800897F8:
    // 0x800897F8: bgez        $t0, L_800899A4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800897FC: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800899A4;
    }
    // 0x800897FC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80089800: beq         $at, $zero, L_800899A4
    if (ctx->r1 == 0) {
        // 0x80089804: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_800899A4;
    }
    // 0x80089804: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80089808: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008980C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80089810: b           L_800899A4
    // 0x80089814: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_800899A4;
    // 0x80089814: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80089818:
    // 0x80089818: bne         $t8, $zero, L_80089838
    if (ctx->r24 != 0) {
        // 0x8008981C: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_80089838;
    }
    // 0x8008981C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80089820: addiu       $t1, $t1, -0x620
    ctx->r9 = ADD32(ctx->r9, -0X620);
    // 0x80089824: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80089828: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8008982C: bne         $t3, $v1, L_80089860
    if (ctx->r11 != ctx->r3) {
        // 0x80089830: andi        $t9, $a2, 0x9000
        ctx->r25 = ctx->r6 & 0X9000;
            goto L_80089860;
    }
    // 0x80089830: andi        $t9, $a2, 0x9000
    ctx->r25 = ctx->r6 & 0X9000;
    // 0x80089834: beq         $t9, $zero, L_80089860
    if (ctx->r25 == 0) {
        // 0x80089838: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80089860;
    }
L_80089838:
    // 0x80089838: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008983C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80089840: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089844: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80089848: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8008984C: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
    // 0x80089850: jal         0x800C06F8
    // 0x80089854: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_10;
    // 0x80089854: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_10:
    // 0x80089858: b           L_800899A8
    // 0x8008985C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
        goto L_800899A8;
    // 0x8008985C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_80089860:
    // 0x80089860: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80089864: beq         $v1, $at, L_8008987C
    if (ctx->r3 == ctx->r1) {
        // 0x80089868: nop
    
            goto L_8008987C;
    }
    // 0x80089868: nop

    // 0x8008986C: beq         $v1, $t3, L_80089890
    if (ctx->r3 == ctx->r11) {
        // 0x80089870: nop
    
            goto L_80089890;
    }
    // 0x80089870: nop

    // 0x80089874: b           L_800898A8
    // 0x80089878: andi        $v0, $a2, 0x9000
    ctx->r2 = ctx->r6 & 0X9000;
        goto L_800898A8;
    // 0x80089878: andi        $v0, $a2, 0x9000
    ctx->r2 = ctx->r6 & 0X9000;
L_8008987C:
    // 0x8008987C: bgez        $t0, L_800899A4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80089880: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800899A4;
    }
    // 0x80089880: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80089884: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80089888: b           L_800899A4
    // 0x8008988C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
        goto L_800899A4;
    // 0x8008988C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80089890:
    // 0x80089890: blez        $t0, L_800899A4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80089894: addiu       $t7, $zero, 0xF
        ctx->r15 = ADD32(0, 0XF);
            goto L_800899A4;
    }
    // 0x80089894: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80089898: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008989C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800898A0: b           L_800899A4
    // 0x800898A4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_800899A4;
    // 0x800898A4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_800898A8:
    // 0x800898A8: beq         $v0, $zero, L_800898F8
    if (ctx->r2 == 0) {
        // 0x800898AC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800898F8;
    }
    // 0x800898AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800898B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800898B4: lbu         $v0, 0x7120($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7120);
    // 0x800898B8: nop

    // 0x800898BC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800898C0: bne         $at, $zero, L_800898EC
    if (ctx->r1 != 0) {
        // 0x800898C4: slti        $at, $v0, 0x7
        ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
            goto L_800898EC;
    }
    // 0x800898C4: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x800898C8: beq         $at, $zero, L_800898EC
    if (ctx->r1 == 0) {
        // 0x800898CC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800898EC;
    }
    // 0x800898CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800898D0: addiu       $a0, $a0, 0x71D0
    ctx->r4 = ADD32(ctx->r4, 0X71D0);
    // 0x800898D4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800898D8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800898DC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800898E0: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800898E4: b           L_8008993C
    // 0x800898E8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
        goto L_8008993C;
    // 0x800898E8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_800898EC:
    // 0x800898EC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800898F0: b           L_8008993C
    // 0x800898F4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
        goto L_8008993C;
    // 0x800898F4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
L_800898F8:
    // 0x800898F8: blez        $t0, L_80089924
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800898FC: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80089924;
    }
    // 0x800898FC: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80089900: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80089904: bgez        $t6, L_80089918
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80089908: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80089918;
    }
    // 0x80089908: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8008990C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80089910: b           L_8008993C
    // 0x80089914: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8008993C;
    // 0x80089914: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80089918:
    // 0x80089918: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008991C: b           L_8008993C
    // 0x80089920: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_8008993C;
    // 0x80089920: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80089924:
    // 0x80089924: bgez        $t0, L_8008993C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80089928: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8008993C;
    }
    // 0x80089928: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8008992C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80089930: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80089934: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80089938: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8008993C:
    // 0x8008993C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80089940: addiu       $a1, $a1, 0x6978
    ctx->r5 = ADD32(ctx->r5, 0X6978);
    // 0x80089944: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089948: lw          $a0, 0x7174($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7174);
    // 0x8008994C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80089950: subu        $t5, $v1, $a0
    ctx->r13 = SUB32(ctx->r3, ctx->r4);
    // 0x80089954: addu        $t4, $v0, $a0
    ctx->r12 = ADD32(ctx->r2, ctx->r4);
    // 0x80089958: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8008995C: bne         $at, $zero, L_80089970
    if (ctx->r1 != 0) {
        // 0x80089960: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80089970;
    }
    // 0x80089960: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80089964: addiu       $v0, $t5, 0x1
    ctx->r2 = ADD32(ctx->r13, 0X1);
    // 0x80089968: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8008996C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_80089970:
    // 0x80089970: beq         $at, $zero, L_80089980
    if (ctx->r1 == 0) {
        // 0x80089974: nop
    
            goto L_80089980;
    }
    // 0x80089974: nop

    // 0x80089978: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8008997C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80089980:
    // 0x80089980: subu        $v1, $t3, $a0
    ctx->r3 = SUB32(ctx->r11, ctx->r4);
    // 0x80089984: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80089988: beq         $at, $zero, L_80089998
    if (ctx->r1 == 0) {
        // 0x8008998C: nop
    
            goto L_80089998;
    }
    // 0x8008998C: nop

    // 0x80089990: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80089994: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80089998:
    // 0x80089998: bgez        $v0, L_800899A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008999C: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_800899A8;
    }
    // 0x8008999C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800899A0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800899A4:
    // 0x800899A4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_800899A8:
    // 0x800899A8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800899AC: beq         $t7, $zero, L_800899C4
    if (ctx->r15 == 0) {
        // 0x800899B0: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_800899C4;
    }
    // 0x800899B0: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800899B4: jal         0x80001D04
    // 0x800899B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_11;
    // 0x800899B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x800899BC: b           L_80089A2C
    // 0x800899C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80089A2C;
    // 0x800899C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800899C4:
    // 0x800899C4: beq         $t8, $zero, L_800899DC
    if (ctx->r24 == 0) {
        // 0x800899C8: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_800899DC;
    }
    // 0x800899C8: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800899CC: jal         0x80001D04
    // 0x800899D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_12;
    // 0x800899D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x800899D4: b           L_80089A2C
    // 0x800899D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80089A2C;
    // 0x800899D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800899DC:
    // 0x800899DC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800899E0: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800899E4: beq         $t9, $zero, L_80089A2C
    if (ctx->r25 == 0) {
        // 0x800899E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80089A2C;
    }
    // 0x800899E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800899EC: jal         0x80001D04
    // 0x800899F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x800899F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x800899F4: b           L_80089A2C
    // 0x800899F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80089A2C;
    // 0x800899F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800899FC:
    // 0x800899FC: slti        $at, $t4, 0x24
    ctx->r1 = SIGNED(ctx->r12) < 0X24 ? 1 : 0;
    // 0x80089A00: bne         $at, $zero, L_80089A28
    if (ctx->r1 != 0) {
        // 0x80089A04: sw          $t4, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r12;
            goto L_80089A28;
    }
    // 0x80089A04: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80089A08: jal         0x80089A38
    // 0x80089A0C: nop

    pakmenu_free(rdram, ctx);
        goto after_14;
    // 0x80089A0C: nop

    after_14:
    // 0x80089A10: jal         0x80081820
    // 0x80089A14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    menu_init(rdram, ctx);
        goto after_15;
    // 0x80089A14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x80089A18: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80089A1C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80089A20: jal         0x8006E528
    // 0x80089A24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_16;
    // 0x80089A24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
L_80089A28:
    // 0x80089A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80089A2C:
    // 0x80089A2C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80089A30: jr          $ra
    // 0x80089A34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80089A34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void pakmenu_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80089A3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80089A40: jal         0x8009CA4C
    // 0x80089A44: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    menu_asset_free(rdram, ctx);
        goto after_0;
    // 0x80089A44: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_0:
    // 0x80089A48: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089A4C: lw          $a0, 0x7060($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7060);
    // 0x80089A50: jal         0x80071380
    // 0x80089A54: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x80089A54: nop

    after_1:
    // 0x80089A58: jal         0x800C478C
    // 0x80089A5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_2;
    // 0x80089A5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80089A60: jal         0x800724D8
    // 0x80089A64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rumble_enable(rdram, ctx);
        goto after_3;
    // 0x80089A64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80089A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80089A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80089A70: jr          $ra
    // 0x80089A74: nop

    return;
    // 0x80089A74: nop

;}
RECOMP_FUNC void menu_magic_codes_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089A7C: sh          $zero, 0x7200($at)
    MEM_H(0X7200, ctx->r1) = 0;
    // 0x80089A80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089A84: sh          $zero, 0x7202($at)
    MEM_H(0X7202, ctx->r1) = 0;
    // 0x80089A88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089A8C: sh          $zero, 0x7206($at)
    MEM_H(0X7206, ctx->r1) = 0;
    // 0x80089A90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089A94: sh          $zero, 0x7204($at)
    MEM_H(0X7204, ctx->r1) = 0;
    // 0x80089A98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089A9C: sw          $zero, 0x6A10($at)
    MEM_W(0X6A10, ctx->r1) = 0;
    // 0x80089AA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089AA4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80089AA8: sh          $t6, 0x720C($at)
    MEM_H(0X720C, ctx->r1) = ctx->r14;
    // 0x80089AAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089AB0: sb          $zero, 0x7218($at)
    MEM_B(0X7218, ctx->r1) = 0;
    // 0x80089AB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089AB8: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80089ABC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089AC0: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x80089AC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089AC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80089ACC: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x80089AD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80089AD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089AD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80089ADC: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x80089AE0: jal         0x800C06F8
    // 0x80089AE4: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x80089AE4: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_0:
    // 0x80089AE8: addiu       $t7, $zero, 0x84
    ctx->r15 = ADD32(0, 0X84);
    // 0x80089AEC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80089AF0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80089AF4: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x80089AF8: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80089AFC: jal         0x800C543C
    // 0x80089B00: addiu       $a3, $zero, 0x10E
    ctx->r7 = ADD32(0, 0X10E);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x80089B00: addiu       $a3, $zero, 0x10E
    ctx->r7 = ADD32(0, 0X10E);
    after_1:
    // 0x80089B04: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80089B08: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80089B0C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80089B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089B14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089B18: jal         0x800C551C
    // 0x80089B1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_2;
    // 0x80089B1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80089B20: jal         0x800C59F4
    // 0x80089B24: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_3;
    // 0x80089B24: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x80089B28: jal         0x800C46D0
    // 0x80089B2C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_4;
    // 0x80089B2C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80089B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80089B34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80089B38: jr          $ra
    // 0x80089B3C: nop

    return;
    // 0x80089B3C: nop

;}
RECOMP_FUNC void cheatmenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B40: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80089B44: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80089B48: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80089B4C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80089B50: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80089B54: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80089B58: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80089B5C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80089B60: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80089B64: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80089B68: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80089B6C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80089B70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80089B74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089B78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089B7C: jal         0x800C492C
    // 0x80089B80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_0;
    // 0x80089B80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80089B84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089B88: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089B8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089B90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089B94: jal         0x800C60B8
    // 0x80089B98: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_1;
    // 0x80089B98: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_1:
    // 0x80089B9C: jal         0x800C484C
    // 0x80089BA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x80089BA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80089BA4: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80089BA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80089BAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80089BB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089BB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089BB8: jal         0x800C48E4
    // 0x80089BBC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_3;
    // 0x80089BBC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x80089BC0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80089BC4: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x80089BC8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089BCC: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80089BD0: lw          $a3, 0x44($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X44);
    // 0x80089BD4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80089BD8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089BDC: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80089BE0: jal         0x800C49A0
    // 0x80089BE4: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_4;
    // 0x80089BE4: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_4:
    // 0x80089BE8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80089BEC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089BF0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089BF4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089BF8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089BFC: jal         0x800C48E4
    // 0x80089C00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_5;
    // 0x80089C00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80089C04: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80089C08: lw          $t1, -0x5E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E0);
    // 0x80089C0C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089C10: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80089C14: lw          $a3, 0x44($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X44);
    // 0x80089C18: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80089C1C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089C20: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80089C24: jal         0x800C49A0
    // 0x80089C28: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_6;
    // 0x80089C28: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_6:
    // 0x80089C2C: addiu       $s3, $zero, 0x41
    ctx->r19 = ADD32(0, 0X41);
    // 0x80089C30: jal         0x800C484C
    // 0x80089C34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x80089C34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80089C38: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80089C3C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089C40: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089C44: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089C48: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089C4C: jal         0x800C48E4
    // 0x80089C50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x80089C50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80089C54: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80089C58: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80089C5C: addiu       $s5, $s5, 0x7202
    ctx->r21 = ADD32(ctx->r21, 0X7202);
    // 0x80089C60: addiu       $s6, $s6, 0x7200
    ctx->r22 = ADD32(ctx->r22, 0X7200);
    // 0x80089C64: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80089C68: addiu       $s4, $zero, 0x3C
    ctx->r20 = ADD32(0, 0X3C);
    // 0x80089C6C: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
L_80089C70:
    // 0x80089C70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80089C74: addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
L_80089C78:
    // 0x80089C78: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80089C7C: lh          $t4, 0x7206($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7206);
    // 0x80089C80: nop

    // 0x80089C84: bne         $s7, $t4, L_80089CE8
    if (ctx->r23 != ctx->r12) {
        // 0x80089C88: slti        $at, $s3, 0x5B
        ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
            goto L_80089CE8;
    }
    // 0x80089C88: slti        $at, $s3, 0x5B
    ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
    // 0x80089C8C: lh          $t5, 0x0($s5)
    ctx->r13 = MEM_H(ctx->r21, 0X0);
    // 0x80089C90: nop

    // 0x80089C94: bne         $s0, $t5, L_80089CE8
    if (ctx->r16 != ctx->r13) {
        // 0x80089C98: slti        $at, $s3, 0x5B
        ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
            goto L_80089CE8;
    }
    // 0x80089C98: slti        $at, $s3, 0x5B
    ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
    // 0x80089C9C: lh          $t6, 0x0($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X0);
    // 0x80089CA0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80089CA4: bne         $fp, $t6, L_80089CE4
    if (ctx->r30 != ctx->r14) {
        // 0x80089CA8: addiu       $a0, $zero, 0x80
        ctx->r4 = ADD32(0, 0X80);
            goto L_80089CE4;
    }
    // 0x80089CA8: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80089CAC: lw          $s2, 0x695C($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X695C);
    // 0x80089CB0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089CB4: sll         $t7, $s2, 3
    ctx->r15 = S32(ctx->r18 << 3);
    // 0x80089CB8: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80089CBC: bne         $at, $zero, L_80089CCC
    if (ctx->r1 != 0) {
        // 0x80089CC0: or          $s2, $t7, $zero
        ctx->r18 = ctx->r15 | 0;
            goto L_80089CCC;
    }
    // 0x80089CC0: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80089CC4: addiu       $t8, $zero, 0x1FF
    ctx->r24 = ADD32(0, 0X1FF);
    // 0x80089CC8: subu        $s2, $t8, $t7
    ctx->r18 = SUB32(ctx->r24, ctx->r15);
L_80089CCC:
    // 0x80089CCC: sra         $t9, $s2, 1
    ctx->r25 = S32(SIGNED(ctx->r18) >> 1);
    // 0x80089CD0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80089CD4: addiu       $a3, $t9, 0x80
    ctx->r7 = ADD32(ctx->r25, 0X80);
    // 0x80089CD8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089CDC: jal         0x800C48E4
    // 0x80089CE0: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    set_text_colour(rdram, ctx);
        goto after_9;
    // 0x80089CE0: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    after_9:
L_80089CE4:
    // 0x80089CE4: slti        $at, $s3, 0x5B
    ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
L_80089CE8:
    // 0x80089CE8: beq         $at, $zero, L_80089D1C
    if (ctx->r1 == 0) {
        // 0x80089CEC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80089D1C;
    }
    // 0x80089CEC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089CF0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80089CF4: sb          $s3, 0x5C($sp)
    MEM_B(0X5C, ctx->r29) = ctx->r19;
    // 0x80089CF8: sb          $zero, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = 0;
    // 0x80089CFC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80089D00: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089D04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80089D08: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80089D0C: jal         0x800C49A0
    // 0x80089D10: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    draw_text(rdram, ctx);
        goto after_10;
    // 0x80089D10: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_10:
    // 0x80089D14: b           L_80089D70
    // 0x80089D18: nop

        goto L_80089D70;
    // 0x80089D18: nop

L_80089D1C:
    // 0x80089D1C: bne         $s0, $s7, L_80089D50
    if (ctx->r16 != ctx->r23) {
        // 0x80089D20: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80089D50;
    }
    // 0x80089D20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089D24: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089D28: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80089D2C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80089D30: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089D34: addiu       $a3, $a3, -0x7860
    ctx->r7 = ADD32(ctx->r7, -0X7860);
    // 0x80089D38: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089D3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80089D40: jal         0x800C49A0
    // 0x80089D44: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    draw_text(rdram, ctx);
        goto after_11;
    // 0x80089D44: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_11:
    // 0x80089D48: b           L_80089D70
    // 0x80089D4C: nop

        goto L_80089D70;
    // 0x80089D4C: nop

L_80089D50:
    // 0x80089D50: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80089D54: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80089D58: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80089D5C: addiu       $a3, $a3, -0x785C
    ctx->r7 = ADD32(ctx->r7, -0X785C);
    // 0x80089D60: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089D64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80089D68: jal         0x800C49A0
    // 0x80089D6C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    draw_text(rdram, ctx);
        goto after_12;
    // 0x80089D6C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_12:
L_80089D70:
    // 0x80089D70: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80089D74: lh          $t5, 0x7206($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7206);
    // 0x80089D78: nop

    // 0x80089D7C: bne         $s7, $t5, L_80089DB8
    if (ctx->r23 != ctx->r13) {
        // 0x80089D80: nop
    
            goto L_80089DB8;
    }
    // 0x80089D80: nop

    // 0x80089D84: lh          $t6, 0x0($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X0);
    // 0x80089D88: nop

    // 0x80089D8C: bne         $s0, $t6, L_80089DB8
    if (ctx->r16 != ctx->r14) {
        // 0x80089D90: nop
    
            goto L_80089DB8;
    }
    // 0x80089D90: nop

    // 0x80089D94: lh          $t7, 0x0($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X0);
    // 0x80089D98: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089D9C: bne         $fp, $t7, L_80089DB8
    if (ctx->r30 != ctx->r15) {
        // 0x80089DA0: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80089DB8;
    }
    // 0x80089DA0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089DA4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80089DA8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80089DAC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089DB0: jal         0x800C48E4
    // 0x80089DB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_13;
    // 0x80089DB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
L_80089DB8:
    // 0x80089DB8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80089DBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80089DC0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80089DC4: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x80089DC8: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x80089DCC: bne         $s0, $at, L_80089C78
    if (ctx->r16 != ctx->r1) {
        // 0x80089DD0: or          $s3, $t9, $zero
        ctx->r19 = ctx->r25 | 0;
            goto L_80089C78;
    }
    // 0x80089DD0: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x80089DD4: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80089DD8: slti        $at, $fp, 0x4
    ctx->r1 = SIGNED(ctx->r30) < 0X4 ? 1 : 0;
    // 0x80089DDC: bne         $at, $zero, L_80089C70
    if (ctx->r1 != 0) {
        // 0x80089DE0: addiu       $s4, $s4, 0x16
        ctx->r20 = ADD32(ctx->r20, 0X16);
            goto L_80089C70;
    }
    // 0x80089DE0: addiu       $s4, $s4, 0x16
    ctx->r20 = ADD32(ctx->r20, 0X16);
    // 0x80089DE4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80089DE8: lw          $s2, 0x695C($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X695C);
    // 0x80089DEC: nop

    // 0x80089DF0: sll         $t1, $s2, 3
    ctx->r9 = S32(ctx->r18 << 3);
    // 0x80089DF4: slti        $at, $t1, 0x100
    ctx->r1 = SIGNED(ctx->r9) < 0X100 ? 1 : 0;
    // 0x80089DF8: bne         $at, $zero, L_80089E08
    if (ctx->r1 != 0) {
        // 0x80089DFC: or          $s2, $t1, $zero
        ctx->r18 = ctx->r9 | 0;
            goto L_80089E08;
    }
    // 0x80089DFC: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x80089E00: addiu       $t2, $zero, 0x1FF
    ctx->r10 = ADD32(0, 0X1FF);
    // 0x80089E04: subu        $s2, $t2, $t1
    ctx->r18 = SUB32(ctx->r10, ctx->r9);
L_80089E08:
    // 0x80089E08: jal         0x800C484C
    // 0x80089E0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_14;
    // 0x80089E0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x80089E10: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
    // 0x80089E14: addiu       $s6, $s6, 0x300
    ctx->r22 = ADD32(ctx->r22, 0X300);
    // 0x80089E18: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80089E1C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80089E20: addiu       $s3, $zero, 0xA4
    ctx->r19 = ADD32(0, 0XA4);
    // 0x80089E24: bne         $t3, $zero, L_80089E30
    if (ctx->r11 != 0) {
        // 0x80089E28: addiu       $s4, $zero, 0x10
        ctx->r20 = ADD32(0, 0X10);
            goto L_80089E30;
    }
    // 0x80089E28: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    // 0x80089E2C: addiu       $s4, $zero, 0x18
    ctx->r20 = ADD32(0, 0X18);
L_80089E30:
    // 0x80089E30: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80089E34: lw          $t4, 0x320($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X320);
    // 0x80089E38: sll         $t5, $fp, 2
    ctx->r13 = S32(ctx->r30 << 2);
    // 0x80089E3C: beq         $t4, $zero, L_80089EC8
    if (ctx->r12 == 0) {
        // 0x80089E40: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_80089EC8;
    }
    // 0x80089E40: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80089E44: addiu       $t6, $t6, 0x320
    ctx->r14 = ADD32(ctx->r14, 0X320);
    // 0x80089E48: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80089E4C: addiu       $s5, $s5, 0x6980
    ctx->r21 = ADD32(ctx->r21, 0X6980);
    // 0x80089E50: addu        $s1, $t5, $t6
    ctx->r17 = ADD32(ctx->r13, ctx->r14);
L_80089E54:
    // 0x80089E54: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80089E58: lh          $t7, 0x7206($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7206);
    // 0x80089E5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80089E60: bne         $fp, $t7, L_80089E7C
    if (ctx->r30 != ctx->r15) {
        // 0x80089E64: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80089E7C;
    }
    // 0x80089E64: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089E68: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x80089E6C: nop

    // 0x80089E70: bne         $t8, $zero, L_80089E80
    if (ctx->r24 != 0) {
        // 0x80089E74: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_80089E80;
    }
    // 0x80089E74: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80089E78: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80089E7C:
    // 0x80089E7C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
L_80089E80:
    // 0x80089E80: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089E84: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089E88: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089E8C: jal         0x800C48E4
    // 0x80089E90: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    set_text_colour(rdram, ctx);
        goto after_15;
    // 0x80089E90: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_15:
    // 0x80089E94: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089E98: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80089E9C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80089EA0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089EA4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089EA8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089EAC: jal         0x800C49A0
    // 0x80089EB0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    draw_text(rdram, ctx);
        goto after_16;
    // 0x80089EB0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_16:
    // 0x80089EB4: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80089EB8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80089EBC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80089EC0: bne         $t2, $zero, L_80089E54
    if (ctx->r10 != 0) {
        // 0x80089EC4: addu        $s3, $s3, $s4
        ctx->r19 = ADD32(ctx->r19, ctx->r20);
            goto L_80089E54;
    }
    // 0x80089EC4: addu        $s3, $s3, $s4
    ctx->r19 = ADD32(ctx->r19, ctx->r20);
L_80089EC8:
    // 0x80089EC8: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80089ECC: addiu       $s5, $s5, 0x6980
    ctx->r21 = ADD32(ctx->r21, 0X6980);
    // 0x80089ED0: jal         0x800C484C
    // 0x80089ED4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_17;
    // 0x80089ED4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x80089ED8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80089EDC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089EE0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089EE4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089EE8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80089EEC: jal         0x800C48E4
    // 0x80089EF0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x80089EF0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_18:
    // 0x80089EF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80089EF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089EFC: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80089F00: jal         0x800C492C
    // 0x80089F04: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_text_background_colour(rdram, ctx);
        goto after_19;
    // 0x80089F04: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_19:
    // 0x80089F08: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80089F0C: lh          $v0, 0x7206($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7206);
    // 0x80089F10: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80089F14: bne         $v0, $at, L_80089F98
    if (ctx->r2 != ctx->r1) {
        // 0x80089F18: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80089F98;
    }
    // 0x80089F18: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80089F1C: lh          $t0, 0x720C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X720C);
    // 0x80089F20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80089F24: bne         $t0, $at, L_80089F5C
    if (ctx->r8 != ctx->r1) {
        // 0x80089F28: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80089F5C;
    }
    // 0x80089F28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80089F2C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80089F30: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x80089F34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089F38: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80089F3C: lw          $a3, 0x48($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X48);
    // 0x80089F40: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80089F44: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089F48: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089F4C: jal         0x800C49A0
    // 0x80089F50: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    draw_text(rdram, ctx);
        goto after_20;
    // 0x80089F50: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    after_20:
    // 0x80089F54: b           L_80089FFC
    // 0x80089F58: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
        goto L_80089FFC;
    // 0x80089F58: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80089F5C:
    // 0x80089F5C: lw          $v0, 0x71F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X71F0);
    // 0x80089F60: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x80089F64: addiu       $v1, $v0, 0x2
    ctx->r3 = ADD32(ctx->r2, 0X2);
    // 0x80089F68: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80089F6C: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x80089F70: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089F74: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80089F78: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089F7C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089F80: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089F84: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80089F88: jal         0x800C49A0
    // 0x80089F8C: addu        $a3, $t8, $v0
    ctx->r7 = ADD32(ctx->r24, ctx->r2);
    draw_text(rdram, ctx);
        goto after_21;
    // 0x80089F8C: addu        $a3, $t8, $v0
    ctx->r7 = ADD32(ctx->r24, ctx->r2);
    after_21:
    // 0x80089F90: b           L_80089FFC
    // 0x80089F94: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
        goto L_80089FFC;
    // 0x80089F94: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80089F98:
    // 0x80089F98: bne         $s7, $v0, L_80089FCC
    if (ctx->r23 != ctx->r2) {
        // 0x80089F9C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80089FCC;
    }
    // 0x80089F9C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80089FA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089FA4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80089FA8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80089FAC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089FB0: addiu       $a3, $a3, 0x7218
    ctx->r7 = ADD32(ctx->r7, 0X7218);
    // 0x80089FB4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089FB8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089FBC: jal         0x800C49A0
    // 0x80089FC0: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    draw_text(rdram, ctx);
        goto after_22;
    // 0x80089FC0: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    after_22:
    // 0x80089FC4: b           L_80089FFC
    // 0x80089FC8: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
        goto L_80089FFC;
    // 0x80089FC8: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80089FCC:
    // 0x80089FCC: bne         $v0, $at, L_80089FF8
    if (ctx->r2 != ctx->r1) {
        // 0x80089FD0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80089FF8;
    }
    // 0x80089FD0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089FD4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80089FD8: lw          $t2, -0x5E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E0);
    // 0x80089FDC: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80089FE0: lw          $a3, 0x4C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4C);
    // 0x80089FE4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089FE8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089FEC: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089FF0: jal         0x800C49A0
    // 0x80089FF4: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    draw_text(rdram, ctx);
        goto after_23;
    // 0x80089FF4: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    after_23:
L_80089FF8:
    // 0x80089FF8: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80089FFC:
    // 0x80089FFC: nop

    // 0x8008A000: beq         $t4, $zero, L_8008A128
    if (ctx->r12 == 0) {
        // 0x8008A004: nop
    
            goto L_8008A128;
    }
    // 0x8008A004: nop

    // 0x8008A008: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8008A00C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8008A010: bne         $t5, $zero, L_8008A020
    if (ctx->r13 != 0) {
        // 0x8008A014: addiu       $s3, $zero, 0x78
        ctx->r19 = ADD32(0, 0X78);
            goto L_8008A020;
    }
    // 0x8008A014: addiu       $s3, $zero, 0x78
    ctx->r19 = ADD32(0, 0X78);
    // 0x8008A018: b           L_8008A020
    // 0x8008A01C: addiu       $s3, $zero, 0x86
    ctx->r19 = ADD32(0, 0X86);
        goto L_8008A020;
    // 0x8008A01C: addiu       $s3, $zero, 0x86
    ctx->r19 = ADD32(0, 0X86);
L_8008A020:
    // 0x8008A020: jal         0x800C59F4
    // 0x8008A024: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_24;
    // 0x8008A024: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_24:
    // 0x8008A028: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008A02C: jal         0x800C54DC
    // 0x8008A030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_25;
    // 0x8008A030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x8008A034: addiu       $t6, $s3, 0x1C
    ctx->r14 = ADD32(ctx->r19, 0X1C);
    // 0x8008A038: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008A03C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008A040: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x8008A044: addiu       $a2, $s3, -0x1C
    ctx->r6 = ADD32(ctx->r19, -0X1C);
    // 0x8008A048: jal         0x800C543C
    // 0x8008A04C: addiu       $a3, $zero, 0xF4
    ctx->r7 = ADD32(0, 0XF4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_26;
    // 0x8008A04C: addiu       $a3, $zero, 0xF4
    ctx->r7 = ADD32(0, 0XF4);
    after_26:
    // 0x8008A050: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8008A054: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008A058: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008A05C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008A060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A064: jal         0x800C551C
    // 0x8008A068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_27;
    // 0x8008A068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_27:
    // 0x8008A06C: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8008A070: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008A074: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_8008A078:
    // 0x8008A078: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008A07C: bne         $fp, $zero, L_8008A090
    if (ctx->r30 != 0) {
        // 0x8008A080: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8008A090;
    }
    // 0x8008A080: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008A084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A088: b           L_8008A0A4
    // 0x8008A08C: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
        goto L_8008A0A4;
    // 0x8008A08C: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
L_8008A090:
    // 0x8008A090: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x8008A094: nop

    // 0x8008A098: bne         $fp, $t8, L_8008A0A8
    if (ctx->r30 != ctx->r24) {
        // 0x8008A09C: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_8008A0A8;
    }
    // 0x8008A09C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008A0A0: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_8008A0A4:
    // 0x8008A0A4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
L_8008A0A8:
    // 0x8008A0A8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8008A0AC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008A0B0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008A0B4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8008A0B8: jal         0x800C5560
    // 0x8008A0BC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    set_current_text_colour(rdram, ctx);
        goto after_28;
    // 0x8008A0BC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_28:
    // 0x8008A0C0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008A0C4: lw          $t1, -0x5E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E0);
    // 0x8008A0C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8008A0CC: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8008A0D0: lw          $a3, 0x250($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X250);
    // 0x8008A0D4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8008A0D8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8008A0DC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8008A0E0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008A0E4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8008A0E8: jal         0x800C56C8
    // 0x8008A0EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_29;
    // 0x8008A0EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_29:
    // 0x8008A0F0: beq         $fp, $zero, L_8008A100
    if (ctx->r30 == 0) {
        // 0x8008A0F4: nop
    
            goto L_8008A100;
    }
    // 0x8008A0F4: nop

    // 0x8008A0F8: b           L_8008A104
    // 0x8008A0FC: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
        goto L_8008A104;
    // 0x8008A0FC: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
L_8008A100:
    // 0x8008A100: addiu       $s3, $s3, 0x14
    ctx->r19 = ADD32(ctx->r19, 0X14);
L_8008A104:
    // 0x8008A104: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8008A108: bne         $fp, $s4, L_8008A078
    if (ctx->r30 != ctx->r20) {
        // 0x8008A10C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8008A078;
    }
    // 0x8008A10C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8008A110: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008A114: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008A118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008A11C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A120: jal         0x800C60B8
    // 0x8008A124: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    render_dialogue_box(rdram, ctx);
        goto after_30;
    // 0x8008A124: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_30:
L_8008A128:
    // 0x8008A128: jal         0x8009C850
    // 0x8008A12C: nop

    get_filtered_cheats(rdram, ctx);
        goto after_31;
    // 0x8008A12C: nop

    after_31:
    // 0x8008A130: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x8008A134: bgez        $t5, L_8008A148
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8008A138: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8008A148;
    }
    // 0x8008A138: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8008A13C: jal         0x8008B1FC
    // 0x8008A140: nop

    cheatmenu_checksum(rdram, ctx);
        goto after_32;
    // 0x8008A140: nop

    after_32:
    // 0x8008A144: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8008A148:
    // 0x8008A148: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008A14C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8008A150: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008A154: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8008A158: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008A15C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8008A160: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008A164: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A168: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8008A16C: jr          $ra
    // 0x8008A170: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8008A170: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void menu_magic_codes_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A174: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008A178: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008A17C: addiu       $t3, $t3, 0x6978
    ctx->r11 = ADD32(ctx->r11, 0X6978);
    // 0x8008A180: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8008A184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A188: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8008A18C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8008A190: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8008A194: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008A198: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8008A19C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8008A1A0: beq         $v0, $zero, L_8008A1B8
    if (ctx->r2 == 0) {
        // 0x8008A1A4: sw          $zero, 0x34($sp)
        MEM_W(0X34, ctx->r29) = 0;
            goto L_8008A1B8;
    }
    // 0x8008A1A4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8008A1A8: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x8008A1AC: bgez        $t6, L_8008A1B8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008A1B0: sw          $t6, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r14;
            goto L_8008A1B8;
    }
    // 0x8008A1B0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8008A1B4: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_8008A1B8:
    // 0x8008A1B8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008A1BC: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008A1C0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008A1C4: beq         $v0, $zero, L_8008A204
    if (ctx->r2 == 0) {
        // 0x8008A1C8: addiu       $v1, $v1, 0x695C
        ctx->r3 = ADD32(ctx->r3, 0X695C);
            goto L_8008A204;
    }
    // 0x8008A1C8: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8008A1CC: blez        $v0, L_8008A1F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008A1D0: subu        $t9, $v0, $a0
        ctx->r25 = SUB32(ctx->r2, ctx->r4);
            goto L_8008A1F0;
    }
    // 0x8008A1D0: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x8008A1D4: addu        $t8, $v0, $a0
    ctx->r24 = ADD32(ctx->r2, ctx->r4);
    // 0x8008A1D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A1DC: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
    // 0x8008A1E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008A1E4: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008A1E8: b           L_8008A208
    // 0x8008A1EC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
        goto L_8008A208;
    // 0x8008A1EC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8008A1F0:
    // 0x8008A1F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A1F4: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
    // 0x8008A1F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008A1FC: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008A200: nop

L_8008A204:
    // 0x8008A204: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8008A208:
    // 0x8008A208: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x8008A20C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8008A210: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8008A214: bne         $at, $zero, L_8008A23C
    if (ctx->r1 != 0) {
        // 0x8008A218: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008A23C;
    }
    // 0x8008A218: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008A21C: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8008A220: beq         $at, $zero, L_8008A23C
    if (ctx->r1 == 0) {
        // 0x8008A224: nop
    
            goto L_8008A23C;
    }
    // 0x8008A224: nop

    // 0x8008A228: jal         0x80089B40
    // 0x8008A22C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    cheatmenu_render(rdram, ctx);
        goto after_0;
    // 0x8008A22C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008A230: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008A234: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8008A238: addiu       $t3, $t3, 0x6978
    ctx->r11 = ADD32(ctx->r11, 0X6978);
L_8008A23C:
    // 0x8008A23C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008A240: lw          $t9, 0x6964($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6964);
    // 0x8008A244: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8008A248: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8008A24C: bne         $t9, $zero, L_8008A2E4
    if (ctx->r25 != 0) {
        // 0x8008A250: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8008A2E4;
    }
    // 0x8008A250: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8008A254: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008A258: lw          $t6, -0x604($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X604);
    // 0x8008A25C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A260: bne         $t6, $zero, L_8008A2E4
    if (ctx->r14 != 0) {
        // 0x8008A264: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8008A2E4;
    }
    // 0x8008A264: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008A268: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008A26C: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x8008A270: addiu       $v1, $v1, 0x69FC
    ctx->r3 = ADD32(ctx->r3, 0X69FC);
L_8008A274:
    // 0x8008A274: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8008A278: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8008A27C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008A280: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    // 0x8008A284: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8008A288: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x8008A28C: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x8008A290: jal         0x8006A794
    // 0x8008A294: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008A294: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    after_1:
    // 0x8008A298: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8008A29C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8008A2A0: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8008A2A4: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8008A2A8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8008A2AC: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8008A2B0: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x8008A2B4: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x8008A2B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008A2BC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8008A2C0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008A2C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008A2C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008A2CC: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x8008A2D0: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8008A2D4: bne         $a2, $at, L_8008A274
    if (ctx->r6 != ctx->r1) {
        // 0x8008A2D8: addu        $t1, $t1, $t8
        ctx->r9 = ADD32(ctx->r9, ctx->r24);
            goto L_8008A274;
    }
    // 0x8008A2D8: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8008A2DC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008A2E0: addiu       $t3, $t3, 0x6978
    ctx->r11 = ADD32(ctx->r11, 0X6978);
L_8008A2E4:
    // 0x8008A2E4: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8008A2E8: addiu       $ra, $ra, 0x7206
    ctx->r31 = ADD32(ctx->r31, 0X7206);
    // 0x8008A2EC: lh          $v0, 0x0($ra)
    ctx->r2 = MEM_H(ctx->r31, 0X0);
    // 0x8008A2F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008A2F4: bne         $v0, $at, L_8008A31C
    if (ctx->r2 != ctx->r1) {
        // 0x8008A2F8: addiu       $t4, $zero, 0x5
        ctx->r12 = ADD32(0, 0X5);
            goto L_8008A31C;
    }
    // 0x8008A2F8: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8008A2FC: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x8008A300: andi        $t6, $t2, 0x9000
    ctx->r14 = ctx->r10 & 0X9000;
    // 0x8008A304: beq         $t9, $zero, L_8008A314
    if (ctx->r25 == 0) {
        // 0x8008A308: nop
    
            goto L_8008A314;
    }
    // 0x8008A308: nop

    // 0x8008A30C: beq         $t6, $zero, L_8008A878
    if (ctx->r14 == 0) {
        // 0x8008A310: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8008A878;
    }
    // 0x8008A310: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_8008A314:
    // 0x8008A314: b           L_8008A874
    // 0x8008A318: sh          $zero, 0x0($ra)
    MEM_H(0X0, ctx->r31) = 0;
        goto L_8008A874;
    // 0x8008A318: sh          $zero, 0x0($ra)
    MEM_H(0X0, ctx->r31) = 0;
L_8008A31C:
    // 0x8008A31C: bne         $t4, $v0, L_8008A668
    if (ctx->r12 != ctx->r2) {
        // 0x8008A320: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_8008A668;
    }
    // 0x8008A320: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8008A324: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008A328: addiu       $v0, $v0, 0x7202
    ctx->r2 = ADD32(ctx->r2, 0X7202);
    // 0x8008A32C: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8008A330: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008A334: addiu       $a1, $a1, 0x7200
    ctx->r5 = ADD32(ctx->r5, 0X7200);
    // 0x8008A338: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8008A33C: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8008A340: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8008A344: bgez        $t0, L_8008A370
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8008A348: or          $a2, $t8, $a0
        ctx->r6 = ctx->r24 | ctx->r4;
            goto L_8008A370;
    }
    // 0x8008A348: or          $a2, $t8, $a0
    ctx->r6 = ctx->r24 | ctx->r4;
    // 0x8008A34C: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x8008A350: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8008A354: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8008A358: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8008A35C: bgez        $v1, L_8008A370
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008A360: nop
    
            goto L_8008A370;
    }
    // 0x8008A360: nop

    // 0x8008A364: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x8008A368: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8008A36C: nop

L_8008A370:
    // 0x8008A370: blez        $t0, L_8008A39C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8008A374: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_8008A39C;
    }
    // 0x8008A374: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8008A378: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8008A37C: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8008A380: nop

    // 0x8008A384: slti        $at, $v1, 0x7
    ctx->r1 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x8008A388: bne         $at, $zero, L_8008A39C
    if (ctx->r1 != 0) {
        // 0x8008A38C: nop
    
            goto L_8008A39C;
    }
    // 0x8008A38C: nop

    // 0x8008A390: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8008A394: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8008A398: nop

L_8008A39C:
    // 0x8008A39C: andi        $v0, $v1, 0xF
    ctx->r2 = ctx->r3 & 0XF;
    // 0x8008A3A0: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8008A3A4: bgez        $t1, L_8008A3D4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8008A3A8: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8008A3D4;
    }
    // 0x8008A3A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8008A3AC: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x8008A3B0: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x8008A3B4: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8008A3B8: nop

    // 0x8008A3BC: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8008A3C0: bne         $at, $zero, L_8008A3D4
    if (ctx->r1 != 0) {
        // 0x8008A3C4: nop
    
            goto L_8008A3D4;
    }
    // 0x8008A3C4: nop

    // 0x8008A3C8: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8008A3CC: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8008A3D0: nop

L_8008A3D4:
    // 0x8008A3D4: blez        $t1, L_8008A400
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8008A3D8: andi        $t9, $t2, 0x8000
        ctx->r25 = ctx->r10 & 0X8000;
            goto L_8008A400;
    }
    // 0x8008A3D8: andi        $t9, $t2, 0x8000
    ctx->r25 = ctx->r10 & 0X8000;
    // 0x8008A3DC: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x8008A3E0: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x8008A3E4: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8008A3E8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8008A3EC: bgez        $a0, L_8008A404
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8008A3F0: or          $t7, $v0, $a0
        ctx->r15 = ctx->r2 | ctx->r4;
            goto L_8008A404;
    }
    // 0x8008A3F0: or          $t7, $v0, $a0
    ctx->r15 = ctx->r2 | ctx->r4;
    // 0x8008A3F4: sh          $t5, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r13;
    // 0x8008A3F8: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8008A3FC: nop

L_8008A400:
    // 0x8008A400: or          $t7, $v0, $a0
    ctx->r15 = ctx->r2 | ctx->r4;
L_8008A404:
    // 0x8008A404: beq         $a2, $t7, L_8008A414
    if (ctx->r6 == ctx->r15) {
        // 0x8008A408: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_8008A414;
    }
    // 0x8008A408: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8008A40C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A410: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_8008A414:
    // 0x8008A414: beq         $t9, $zero, L_8008A49C
    if (ctx->r25 == 0) {
        // 0x8008A418: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008A49C;
    }
    // 0x8008A418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008A41C: bne         $t5, $a0, L_8008A434
    if (ctx->r13 != ctx->r4) {
        // 0x8008A420: nop
    
            goto L_8008A434;
    }
    // 0x8008A420: nop

    // 0x8008A424: bne         $t4, $v1, L_8008A434
    if (ctx->r12 != ctx->r3) {
        // 0x8008A428: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8008A434;
    }
    // 0x8008A428: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008A42C: b           L_8008A49C
    // 0x8008A430: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
        goto L_8008A49C;
    // 0x8008A430: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_8008A434:
    // 0x8008A434: bne         $t5, $a0, L_8008A44C
    if (ctx->r13 != ctx->r4) {
        // 0x8008A438: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8008A44C;
    }
    // 0x8008A438: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8008A43C: bne         $v1, $at, L_8008A44C
    if (ctx->r3 != ctx->r1) {
        // 0x8008A440: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8008A44C;
    }
    // 0x8008A440: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A444: b           L_8008A49C
    // 0x8008A448: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
        goto L_8008A49C;
    // 0x8008A448: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
L_8008A44C:
    // 0x8008A44C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008A450: addiu       $a2, $a2, 0x7204
    ctx->r6 = ADD32(ctx->r6, 0X7204);
    // 0x8008A454: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x8008A458: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A45C: slti        $at, $v0, 0x13
    ctx->r1 = SIGNED(ctx->r2) < 0X13 ? 1 : 0;
    // 0x8008A460: beq         $at, $zero, L_8008A49C
    if (ctx->r1 == 0) {
        // 0x8008A464: sll         $t9, $a0, 3
        ctx->r25 = S32(ctx->r4 << 3);
            goto L_8008A49C;
    }
    // 0x8008A464: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8008A468: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8008A46C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8008A470: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A474: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8008A478: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008A47C: addiu       $t7, $t6, 0x41
    ctx->r15 = ADD32(ctx->r14, 0X41);
    // 0x8008A480: sb          $t7, 0x7218($at)
    MEM_B(0X7218, ctx->r1) = ctx->r15;
    // 0x8008A484: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8008A488: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x8008A48C: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x8008A490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A494: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8008A498: sb          $zero, 0x7218($at)
    MEM_B(0X7218, ctx->r1) = 0;
L_8008A49C:
    // 0x8008A49C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008A4A0: andi        $t6, $t2, 0x4000
    ctx->r14 = ctx->r10 & 0X4000;
    // 0x8008A4A4: beq         $t6, $zero, L_8008A4C8
    if (ctx->r14 == 0) {
        // 0x8008A4A8: addiu       $a2, $a2, 0x7204
        ctx->r6 = ADD32(ctx->r6, 0X7204);
            goto L_8008A4C8;
    }
    // 0x8008A4A8: addiu       $a2, $a2, 0x7204
    ctx->r6 = ADD32(ctx->r6, 0X7204);
    // 0x8008A4AC: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x8008A4B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A4B4: blez        $t7, L_8008A4C4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8008A4B8: nop
    
            goto L_8008A4C4;
    }
    // 0x8008A4B8: nop

    // 0x8008A4BC: b           L_8008A4C8
    // 0x8008A4C0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
        goto L_8008A4C8;
    // 0x8008A4C0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
L_8008A4C4:
    // 0x8008A4C4: sh          $zero, 0x0($ra)
    MEM_H(0X0, ctx->r31) = 0;
L_8008A4C8:
    // 0x8008A4C8: andi        $t9, $t2, 0x1000
    ctx->r25 = ctx->r10 & 0X1000;
    // 0x8008A4CC: beq         $t9, $zero, L_8008A4D8
    if (ctx->r25 == 0) {
        // 0x8008A4D0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8008A4D8;
    }
    // 0x8008A4D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008A4D4: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
L_8008A4D8:
    // 0x8008A4D8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8008A4DC: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
    // 0x8008A4E0: beq         $t7, $zero, L_8008A52C
    if (ctx->r15 == 0) {
        // 0x8008A4E4: lw          $t6, 0x48($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X48);
            goto L_8008A52C;
    }
    // 0x8008A4E4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008A4E8: jal         0x80001D04
    // 0x8008A4EC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008A4EC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_2:
    // 0x8008A4F0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008A4F4: addiu       $a2, $a2, 0x7204
    ctx->r6 = ADD32(ctx->r6, 0X7204);
    // 0x8008A4F8: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x8008A4FC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8008A500: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8008A504: addiu       $ra, $ra, 0x7206
    ctx->r31 = ADD32(ctx->r31, 0X7206);
    // 0x8008A508: blez        $v0, L_8008A528
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008A50C: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_8008A528;
    }
    // 0x8008A50C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8008A510: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8008A514: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x8008A518: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x8008A51C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A520: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8008A524: sb          $zero, 0x7218($at)
    MEM_B(0X7218, ctx->r1) = 0;
L_8008A528:
    // 0x8008A528: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
L_8008A52C:
    // 0x8008A52C: nop

    // 0x8008A530: beq         $t6, $zero, L_8008A878
    if (ctx->r14 == 0) {
        // 0x8008A534: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8008A878;
    }
    // 0x8008A534: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A538: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x8008A53C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A540: bne         $t8, $zero, L_8008A550
    if (ctx->r24 != 0) {
        // 0x8008A544: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_8008A550;
    }
    // 0x8008A544: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8008A548: b           L_8008A874
    // 0x8008A54C: sh          $zero, 0x0($ra)
    MEM_H(0X0, ctx->r31) = 0;
        goto L_8008A874;
    // 0x8008A54C: sh          $zero, 0x0($ra)
    MEM_H(0X0, ctx->r31) = 0;
L_8008A550:
    // 0x8008A550: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008A554: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008A558: lw          $t1, 0x71F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X71F0);
    // 0x8008A55C: addiu       $t4, $t4, 0x720C
    ctx->r12 = ADD32(ctx->r12, 0X720C);
    // 0x8008A560: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
    // 0x8008A564: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008A568: lw          $t2, 0x71F8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71F8);
    // 0x8008A56C: lh          $t0, 0x0($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X0);
    // 0x8008A570: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x8008A574: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008A578: beq         $at, $zero, L_8008A604
    if (ctx->r1 == 0) {
        // 0x8008A57C: nop
    
            goto L_8008A604;
    }
    // 0x8008A57C: nop

L_8008A580:
    // 0x8008A580: multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A584: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008A588: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8008A58C: addiu       $a1, $a1, 0x7217
    ctx->r5 = ADD32(ctx->r5, 0X7217);
    // 0x8008A590: mflo        $t9
    ctx->r25 = lo;
    // 0x8008A594: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8008A598: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8008A59C: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8008A5A0: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x8008A5A4: addu        $v0, $t8, $t1
    ctx->r2 = ADD32(ctx->r24, ctx->r9);
    // 0x8008A5A8: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
L_8008A5AC:
    // 0x8008A5AC: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8008A5B0: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x8008A5B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008A5B8: beq         $v0, $v1, L_8008A5C4
    if (ctx->r2 == ctx->r3) {
        // 0x8008A5BC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8008A5C4;
    }
    // 0x8008A5BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008A5C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8008A5C4:
    // 0x8008A5C4: beq         $a3, $zero, L_8008A5DC
    if (ctx->r7 == 0) {
        // 0x8008A5C8: nop
    
            goto L_8008A5DC;
    }
    // 0x8008A5C8: nop

    // 0x8008A5CC: beq         $v0, $zero, L_8008A5DC
    if (ctx->r2 == 0) {
        // 0x8008A5D0: nop
    
            goto L_8008A5DC;
    }
    // 0x8008A5D0: nop

    // 0x8008A5D4: bne         $v1, $zero, L_8008A5AC
    if (ctx->r3 != 0) {
        // 0x8008A5D8: nop
    
            goto L_8008A5AC;
    }
    // 0x8008A5D8: nop

L_8008A5DC:
    // 0x8008A5DC: bne         $a3, $zero, L_8008A5F4
    if (ctx->r7 != 0) {
        // 0x8008A5E0: slt         $at, $t0, $t2
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8008A5F4;
    }
    // 0x8008A5E0: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008A5E4: sh          $t9, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r25;
    // 0x8008A5E8: lh          $t0, 0x0($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X0);
    // 0x8008A5EC: nop

    // 0x8008A5F0: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
L_8008A5F4:
    // 0x8008A5F4: beq         $at, $zero, L_8008A604
    if (ctx->r1 == 0) {
        // 0x8008A5F8: nop
    
            goto L_8008A604;
    }
    // 0x8008A5F8: nop

    // 0x8008A5FC: beq         $a3, $zero, L_8008A580
    if (ctx->r7 == 0) {
        // 0x8008A600: nop
    
            goto L_8008A580;
    }
    // 0x8008A600: nop

L_8008A604:
    // 0x8008A604: bne         $a3, $zero, L_8008A614
    if (ctx->r7 != 0) {
        // 0x8008A608: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_8008A614;
    }
    // 0x8008A608: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8008A60C: b           L_8008A650
    // 0x8008A610: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
        goto L_8008A650;
    // 0x8008A610: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
L_8008A614:
    // 0x8008A614: multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A618: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008A61C: addiu       $v1, $v1, 0x31C
    ctx->r3 = ADD32(ctx->r3, 0X31C);
    // 0x8008A620: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008A624: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A628: sllv        $v0, $t7, $t0
    ctx->r2 = S32(ctx->r15 << (ctx->r8 & 31));
    // 0x8008A62C: or          $t9, $t8, $v0
    ctx->r25 = ctx->r24 | ctx->r2;
    // 0x8008A630: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008A634: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008A638: lw          $t6, 0x318($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X318);
    // 0x8008A63C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A640: or          $t7, $t6, $v0
    ctx->r15 = ctx->r14 | ctx->r2;
    // 0x8008A644: mflo        $t8
    ctx->r24 = lo;
    // 0x8008A648: sw          $t7, 0x318($at)
    MEM_W(0X318, ctx->r1) = ctx->r15;
    // 0x8008A64C: sh          $t8, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r24;
L_8008A650:
    // 0x8008A650: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8008A654: sh          $t9, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r25;
    // 0x8008A658: addiu       $t6, $zero, 0xF0
    ctx->r14 = ADD32(0, 0XF0);
    // 0x8008A65C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A660: b           L_8008A874
    // 0x8008A664: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
        goto L_8008A874;
    // 0x8008A664: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
L_8008A668:
    // 0x8008A668: bne         $a1, $v0, L_8008A690
    if (ctx->r5 != ctx->r2) {
        // 0x8008A66C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8008A690;
    }
    // 0x8008A66C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008A670: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8008A674: andi        $t8, $t2, 0x9000
    ctx->r24 = ctx->r10 & 0X9000;
    // 0x8008A678: beq         $t7, $zero, L_8008A688
    if (ctx->r15 == 0) {
        // 0x8008A67C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008A688;
    }
    // 0x8008A67C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A680: beq         $t8, $zero, L_8008A878
    if (ctx->r24 == 0) {
        // 0x8008A684: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8008A878;
    }
    // 0x8008A684: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_8008A688:
    // 0x8008A688: b           L_8008A874
    // 0x8008A68C: sh          $t9, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r25;
        goto L_8008A874;
    // 0x8008A68C: sh          $t9, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r25;
L_8008A690:
    // 0x8008A690: addiu       $a0, $a0, 0x6980
    ctx->r4 = ADD32(ctx->r4, 0X6980);
    // 0x8008A694: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8008A698: andi        $t6, $t2, 0x9000
    ctx->r14 = ctx->r10 & 0X9000;
    // 0x8008A69C: beq         $v1, $zero, L_8008A750
    if (ctx->r3 == 0) {
        // 0x8008A6A0: andi        $t9, $t2, 0x9000
        ctx->r25 = ctx->r10 & 0X9000;
            goto L_8008A750;
    }
    // 0x8008A6A0: andi        $t9, $t2, 0x9000
    ctx->r25 = ctx->r10 & 0X9000;
    // 0x8008A6A4: beq         $t6, $zero, L_8008A6FC
    if (ctx->r14 == 0) {
        // 0x8008A6A8: andi        $t8, $t2, 0x4000
        ctx->r24 = ctx->r10 & 0X4000;
            goto L_8008A6FC;
    }
    // 0x8008A6A8: andi        $t8, $t2, 0x4000
    ctx->r24 = ctx->r10 & 0X4000;
    // 0x8008A6AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A6B0: bne         $v1, $at, L_8008A6EC
    if (ctx->r3 != ctx->r1) {
        // 0x8008A6B4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8008A6EC;
    }
    // 0x8008A6B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A6B8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008A6BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A6C0: addiu       $v1, $v1, 0x31C
    ctx->r3 = ADD32(ctx->r3, 0X31C);
    // 0x8008A6C4: sw          $zero, 0x318($at)
    MEM_W(0X318, ctx->r1) = 0;
    // 0x8008A6C8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008A6CC: sh          $a1, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r5;
    // 0x8008A6D0: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x8008A6D4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008A6D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A6DC: addiu       $t6, $zero, 0xF0
    ctx->r14 = ADD32(0, 0XF0);
    // 0x8008A6E0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8008A6E4: b           L_8008A6F4
    // 0x8008A6E8: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
        goto L_8008A6F4;
    // 0x8008A6E8: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
L_8008A6EC:
    // 0x8008A6EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A6F0: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
L_8008A6F4:
    // 0x8008A6F4: b           L_8008A874
    // 0x8008A6F8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_8008A874;
    // 0x8008A6F8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8008A6FC:
    // 0x8008A6FC: beq         $t8, $zero, L_8008A710
    if (ctx->r24 == 0) {
        // 0x8008A700: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008A710;
    }
    // 0x8008A700: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A704: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8008A708: b           L_8008A874
    // 0x8008A70C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_8008A874;
    // 0x8008A70C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8008A710:
    // 0x8008A710: bgez        $t1, L_8008A730
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8008A714: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008A730;
    }
    // 0x8008A714: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A718: bne         $v1, $at, L_8008A730
    if (ctx->r3 != ctx->r1) {
        // 0x8008A71C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8008A730;
    }
    // 0x8008A71C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008A720: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8008A724: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8008A728: b           L_8008A874
    // 0x8008A72C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_8008A874;
    // 0x8008A72C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8008A730:
    // 0x8008A730: blez        $t1, L_8008A874
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8008A734: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008A874;
    }
    // 0x8008A734: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008A738: bne         $v1, $at, L_8008A874
    if (ctx->r3 != ctx->r1) {
        // 0x8008A73C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008A874;
    }
    // 0x8008A73C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A740: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A744: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8008A748: b           L_8008A874
    // 0x8008A74C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
        goto L_8008A874;
    // 0x8008A74C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_8008A750:
    // 0x8008A750: bgez        $t1, L_8008A780
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8008A754: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8008A780;
    }
    // 0x8008A754: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8008A758: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8008A75C: sh          $t6, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r14;
    // 0x8008A760: lh          $v0, 0x0($ra)
    ctx->r2 = MEM_H(ctx->r31, 0X0);
    // 0x8008A764: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8008A768: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8008A76C: bne         $at, $zero, L_8008A780
    if (ctx->r1 != 0) {
        // 0x8008A770: nop
    
            goto L_8008A780;
    }
    // 0x8008A770: nop

    // 0x8008A774: sh          $t5, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r13;
    // 0x8008A778: lh          $v0, 0x0($ra)
    ctx->r2 = MEM_H(ctx->r31, 0X0);
    // 0x8008A77C: nop

L_8008A780:
    // 0x8008A780: blez        $t1, L_8008A7AC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8008A784: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_8008A7AC;
    }
    // 0x8008A784: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8008A788: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8008A78C: sh          $t7, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r15;
    // 0x8008A790: lh          $v0, 0x0($ra)
    ctx->r2 = MEM_H(ctx->r31, 0X0);
    // 0x8008A794: nop

    // 0x8008A798: bgez        $v0, L_8008A7AC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008A79C: nop
    
            goto L_8008A7AC;
    }
    // 0x8008A79C: nop

    // 0x8008A7A0: sh          $zero, 0x0($ra)
    MEM_H(0X0, ctx->r31) = 0;
    // 0x8008A7A4: lh          $v0, 0x0($ra)
    ctx->r2 = MEM_H(ctx->r31, 0X0);
    // 0x8008A7A8: nop

L_8008A7AC:
    // 0x8008A7AC: beq         $a2, $v0, L_8008A7B8
    if (ctx->r6 == ctx->r2) {
        // 0x8008A7B0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008A7B8;
    }
    // 0x8008A7B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A7B4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_8008A7B8:
    // 0x8008A7B8: beq         $t9, $zero, L_8008A830
    if (ctx->r25 == 0) {
        // 0x8008A7BC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8008A830;
    }
    // 0x8008A7BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008A7C0: bne         $t5, $v0, L_8008A7D4
    if (ctx->r13 != ctx->r2) {
        // 0x8008A7C4: sw          $t6, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r14;
            goto L_8008A7D4;
    }
    // 0x8008A7C4: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8008A7C8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008A7CC: b           L_8008A830
    // 0x8008A7D0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
        goto L_8008A830;
    // 0x8008A7D0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
L_8008A7D4:
    // 0x8008A7D4: bne         $v0, $zero, L_8008A80C
    if (ctx->r2 != 0) {
        // 0x8008A7D8: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8008A80C;
    }
    // 0x8008A7D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008A7DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008A7E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008A7E4: addiu       $a2, $a2, 0x7204
    ctx->r6 = ADD32(ctx->r6, 0X7204);
    // 0x8008A7E8: addiu       $v0, $v0, 0x7202
    ctx->r2 = ADD32(ctx->r2, 0X7202);
    // 0x8008A7EC: addiu       $a1, $a1, 0x7200
    ctx->r5 = ADD32(ctx->r5, 0X7200);
    // 0x8008A7F0: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8008A7F4: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8008A7F8: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x8008A7FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A800: sb          $zero, 0x7218($at)
    MEM_B(0X7218, ctx->r1) = 0;
    // 0x8008A804: b           L_8008A830
    // 0x8008A808: sh          $t4, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r12;
        goto L_8008A830;
    // 0x8008A808: sh          $t4, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r12;
L_8008A80C:
    // 0x8008A80C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A810: bne         $v0, $at, L_8008A820
    if (ctx->r2 != ctx->r1) {
        // 0x8008A814: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8008A820;
    }
    // 0x8008A814: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8008A818: b           L_8008A830
    // 0x8008A81C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
        goto L_8008A830;
    // 0x8008A81C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_8008A820:
    // 0x8008A820: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008A824: bne         $v0, $at, L_8008A830
    if (ctx->r2 != ctx->r1) {
        // 0x8008A828: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008A830;
    }
    // 0x8008A828: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A82C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_8008A830:
    // 0x8008A830: andi        $t6, $t2, 0x4000
    ctx->r14 = ctx->r10 & 0X4000;
    // 0x8008A834: beq         $t6, $zero, L_8008A840
    if (ctx->r14 == 0) {
        // 0x8008A838: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_8008A840;
    }
    // 0x8008A838: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008A83C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
L_8008A840:
    // 0x8008A840: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008A844: nop

    // 0x8008A848: beq         $t8, $zero, L_8008A878
    if (ctx->r24 == 0) {
        // 0x8008A84C: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8008A878;
    }
    // 0x8008A84C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A850: bgez        $t8, L_8008A860
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008A854: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8008A860;
    }
    // 0x8008A854: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A858: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A85C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_8008A860:
    // 0x8008A860: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8008A864: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008A868: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    // 0x8008A86C: jal         0x800C06F8
    // 0x8008A870: sw          $t6, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r14;
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8008A870: sw          $t6, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r14;
    after_3:
L_8008A874:
    // 0x8008A874: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_8008A878:
    // 0x8008A878: nop

    // 0x8008A87C: beq         $t7, $zero, L_8008A894
    if (ctx->r15 == 0) {
        // 0x8008A880: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008A894;
    }
    // 0x8008A880: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008A884: jal         0x80001D04
    // 0x8008A888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008A888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8008A88C: b           L_8008A8C4
    // 0x8008A890: nop

        goto L_8008A8C4;
    // 0x8008A890: nop

L_8008A894:
    // 0x8008A894: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8008A898: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8008A89C: beq         $t8, $zero, L_8008A8B4
    if (ctx->r24 == 0) {
        // 0x8008A8A0: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008A8B4;
    }
    // 0x8008A8A0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008A8A4: jal         0x80001D04
    // 0x8008A8A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8008A8A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8008A8AC: b           L_8008A8C4
    // 0x8008A8B0: nop

        goto L_8008A8C4;
    // 0x8008A8B0: nop

L_8008A8B4:
    // 0x8008A8B4: beq         $t9, $zero, L_8008A8C4
    if (ctx->r25 == 0) {
        // 0x8008A8B8: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008A8C4;
    }
    // 0x8008A8B8: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008A8BC: jal         0x80001D04
    // 0x8008A8C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008A8C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_8008A8C4:
    // 0x8008A8C4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008A8C8: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008A8CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A8D0: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x8008A8D4: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x8008A8D8: bne         $at, $zero, L_8008A8E8
    if (ctx->r1 != 0) {
        // 0x8008A8DC: slti        $at, $v0, 0x1F
        ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
            goto L_8008A8E8;
    }
    // 0x8008A8DC: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8008A8E0: bne         $at, $zero, L_8008A96C
    if (ctx->r1 != 0) {
        // 0x8008A8E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008A96C;
    }
    // 0x8008A8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A8E8:
    // 0x8008A8E8: jal         0x8008A978
    // 0x8008A8EC: nop

    cheatmenu_free(rdram, ctx);
        goto after_7;
    // 0x8008A8EC: nop

    after_7:
    // 0x8008A8F0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008A8F4: lw          $t6, -0x604($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X604);
    // 0x8008A8F8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008A8FC: bgez        $t6, L_8008A960
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008A900: nop
    
            goto L_8008A960;
    }
    // 0x8008A900: nop

    // 0x8008A904: lw          $t7, 0x318($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X318);
    // 0x8008A908: nop

    // 0x8008A90C: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x8008A910: beq         $t8, $zero, L_8008A950
    if (ctx->r24 == 0) {
        // 0x8008A914: nop
    
            goto L_8008A950;
    }
    // 0x8008A914: nop

    // 0x8008A918: jal         0x80000B28
    // 0x8008A91C: nop

    music_change_on(rdram, ctx);
        goto after_8;
    // 0x8008A91C: nop

    after_8:
    // 0x8008A920: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A924: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A928: sw          $t9, 0x20CC($at)
    MEM_W(0X20CC, ctx->r1) = ctx->r25;
    // 0x8008A92C: jal         0x80081820
    // 0x8008A930: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    menu_init(rdram, ctx);
        goto after_9;
    // 0x8008A930: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_9:
    // 0x8008A934: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008A938: lw          $t6, 0x318($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X318);
    // 0x8008A93C: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x8008A940: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8008A944: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A948: b           L_8008A968
    // 0x8008A94C: sw          $t7, 0x318($at)
    MEM_W(0X318, ctx->r1) = ctx->r15;
        goto L_8008A968;
    // 0x8008A94C: sw          $t7, 0x318($at)
    MEM_W(0X318, ctx->r1) = ctx->r15;
L_8008A950:
    // 0x8008A950: jal         0x80081820
    // 0x8008A954: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    menu_init(rdram, ctx);
        goto after_10;
    // 0x8008A954: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_10:
    // 0x8008A958: b           L_8008A96C
    // 0x8008A95C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A96C;
    // 0x8008A95C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A960:
    // 0x8008A960: jal         0x80081820
    // 0x8008A964: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    menu_init(rdram, ctx);
        goto after_11;
    // 0x8008A964: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_11:
L_8008A968:
    // 0x8008A968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A96C:
    // 0x8008A96C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8008A970: jr          $ra
    // 0x8008A974: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8008A974: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void cheatmenu_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A97C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A980: jal         0x800C478C
    // 0x8008A984: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x8008A984: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008A988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A98C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A990: jr          $ra
    // 0x8008A994: nop

    return;
    // 0x8008A994: nop

;}
RECOMP_FUNC void menu_magic_codes_list_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A998: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A99C: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8008A9A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A9A4: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8008A9A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A9AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A9B0: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8008A9B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A9B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A9BC: sh          $zero, 0x7206($at)
    MEM_H(0X7206, ctx->r1) = 0;
    // 0x8008A9C0: jal         0x800C46D0
    // 0x8008A9C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_0;
    // 0x8008A9C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008A9C8: jal         0x8009CC18
    // 0x8008A9CC: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    menu_asset_load(rdram, ctx);
        goto after_1;
    // 0x8008A9CC: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_1:
    // 0x8008A9D0: jal         0x8008E968
    // 0x8008A9D4: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_2;
    // 0x8008A9D4: nop

    after_2:
    // 0x8008A9D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008A9DC: jal         0x800C06F8
    // 0x8008A9E0: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8008A9E0: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_3:
    // 0x8008A9E4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8008A9E8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8008A9EC: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8008A9F0: bne         $t6, $zero, L_8008AA08
    if (ctx->r14 != 0) {
        // 0x8008A9F4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008AA08;
    }
    // 0x8008A9F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A9F8: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8008A9FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AA00: b           L_8008AA0C
    // 0x8008AA04: sw          $t7, 0x7234($at)
    MEM_W(0X7234, ctx->r1) = ctx->r15;
        goto L_8008AA0C;
    // 0x8008AA04: sw          $t7, 0x7234($at)
    MEM_W(0X7234, ctx->r1) = ctx->r15;
L_8008AA08:
    // 0x8008AA08: sw          $t8, 0x7234($at)
    MEM_W(0X7234, ctx->r1) = ctx->r24;
L_8008AA0C:
    // 0x8008AA0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008AA10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008AA14: jr          $ra
    // 0x8008AA18: nop

    return;
    // 0x8008AA18: nop

;}
RECOMP_FUNC void cheatlist_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AA1C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8008AA20: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8008AA24: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8008AA28: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8008AA2C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8008AA30: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8008AA34: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8008AA38: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8008AA3C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8008AA40: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8008AA44: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8008AA48: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8008AA4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008AA50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008AA54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008AA58: jal         0x800C492C
    // 0x8008AA5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_0;
    // 0x8008AA5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8008AA60: jal         0x800C484C
    // 0x8008AA64: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_1;
    // 0x8008AA64: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8008AA68: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8008AA6C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008AA70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008AA74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008AA78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008AA7C: jal         0x800C48E4
    // 0x8008AA80: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x8008AA80: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x8008AA84: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x8008AA88: addiu       $s7, $s7, -0x5E0
    ctx->r23 = ADD32(ctx->r23, -0X5E0);
    // 0x8008AA8C: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8008AA90: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008AA94: addiu       $s5, $s5, 0x693C
    ctx->r21 = ADD32(ctx->r21, 0X693C);
    // 0x8008AA98: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8008AA9C: lw          $a3, 0x50($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X50);
    // 0x8008AAA0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008AAA4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AAA8: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8008AAAC: jal         0x800C49A0
    // 0x8008AAB0: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_3;
    // 0x8008AAB0: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_3:
    // 0x8008AAB4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008AAB8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008AABC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008AAC0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008AAC4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008AAC8: jal         0x800C48E4
    // 0x8008AACC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x8008AACC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8008AAD0: lw          $t0, 0x0($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X0);
    // 0x8008AAD4: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008AAD8: lw          $a3, 0x50($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X50);
    // 0x8008AADC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008AAE0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AAE4: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008AAE8: jal         0x800C49A0
    // 0x8008AAEC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x8008AAEC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x8008AAF0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008AAF4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008AAF8: lw          $v1, 0x31C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C);
    // 0x8008AAFC: addiu       $a0, $a0, 0x7240
    ctx->r4 = ADD32(ctx->r4, 0X7240);
    // 0x8008AB00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008AB04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008AB08: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8008AB0C:
    // 0x8008AB0C: and         $t2, $v0, $v1
    ctx->r10 = ctx->r2 & ctx->r3;
    // 0x8008AB10: beq         $t2, $zero, L_8008AB28
    if (ctx->r10 == 0) {
        // 0x8008AB14: sll         $t5, $v0, 1
        ctx->r13 = S32(ctx->r2 << 1);
            goto L_8008AB28;
    }
    // 0x8008AB14: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x8008AB18: sll         $t3, $s3, 1
    ctx->r11 = S32(ctx->r19 << 1);
    // 0x8008AB1C: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8008AB20: sh          $s0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r16;
    // 0x8008AB24: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8008AB28:
    // 0x8008AB28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008AB2C: slti        $at, $s0, 0x20
    ctx->r1 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x8008AB30: bne         $at, $zero, L_8008AB0C
    if (ctx->r1 != 0) {
        // 0x8008AB34: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8008AB0C;
    }
    // 0x8008AB34: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8008AB38: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008AB3C: lw          $fp, 0x695C($fp)
    ctx->r30 = MEM_W(ctx->r30, 0X695C);
    // 0x8008AB40: addiu       $s2, $zero, 0x36
    ctx->r18 = ADD32(0, 0X36);
    // 0x8008AB44: sll         $t6, $fp, 3
    ctx->r14 = S32(ctx->r30 << 3);
    // 0x8008AB48: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8008AB4C: bne         $at, $zero, L_8008AB5C
    if (ctx->r1 != 0) {
        // 0x8008AB50: or          $fp, $t6, $zero
        ctx->r30 = ctx->r14 | 0;
            goto L_8008AB5C;
    }
    // 0x8008AB50: or          $fp, $t6, $zero
    ctx->r30 = ctx->r14 | 0;
    // 0x8008AB54: addiu       $t7, $zero, 0x1FF
    ctx->r15 = ADD32(0, 0X1FF);
    // 0x8008AB58: subu        $fp, $t7, $t6
    ctx->r30 = SUB32(ctx->r15, ctx->r14);
L_8008AB5C:
    // 0x8008AB5C: jal         0x800C484C
    // 0x8008AB60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_6;
    // 0x8008AB60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8008AB64: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008AB68: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008AB6C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008AB70: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008AB74: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008AB78: jal         0x800C48E4
    // 0x8008AB7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x8008AB7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8008AB80: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008AB84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008AB88: lw          $t9, 0x7234($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7234);
    // 0x8008AB8C: lw          $v1, 0x6980($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6980);
    // 0x8008AB90: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008AB94: lw          $s6, 0x71F0($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X71F0);
    // 0x8008AB98: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x8008AB9C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008ABA0: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8008ABA4: beq         $at, $zero, L_8008ACDC
    if (ctx->r1 == 0) {
        // 0x8008ABA8: addiu       $s6, $s6, 0x2
        ctx->r22 = ADD32(ctx->r22, 0X2);
            goto L_8008ACDC;
    }
    // 0x8008ABA8: addiu       $s6, $s6, 0x2
    ctx->r22 = ADD32(ctx->r22, 0X2);
    // 0x8008ABAC: slt         $at, $v1, $s3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8008ABB0: beq         $at, $zero, L_8008ACDC
    if (ctx->r1 == 0) {
        // 0x8008ABB4: sll         $t0, $v1, 1
        ctx->r8 = S32(ctx->r3 << 1);
            goto L_8008ACDC;
    }
    // 0x8008ABB4: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x8008ABB8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008ABBC: addiu       $t1, $t1, 0x7240
    ctx->r9 = ADD32(ctx->r9, 0X7240);
    // 0x8008ABC0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008ABC4: addiu       $s4, $s4, 0x7206
    ctx->r20 = ADD32(ctx->r20, 0X7206);
    // 0x8008ABC8: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
L_8008ABCC:
    // 0x8008ABCC: lh          $t2, 0x0($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X0);
    // 0x8008ABD0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008ABD4: bne         $s0, $t2, L_8008ABF0
    if (ctx->r16 != ctx->r10) {
        // 0x8008ABD8: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008ABF0;
    }
    // 0x8008ABD8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008ABDC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8008ABE0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8008ABE4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008ABE8: jal         0x800C48E4
    // 0x8008ABEC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x8008ABEC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_8:
L_8008ABF0:
    // 0x8008ABF0: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x8008ABF4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008ABF8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008ABFC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008AC00: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8008AC04: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x8008AC08: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x8008AC0C: lw          $t9, 0x71F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X71F0);
    // 0x8008AC10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008AC14: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AC18: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8008AC1C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008AC20: jal         0x800C49A0
    // 0x8008AC24: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    draw_text(rdram, ctx);
        goto after_9;
    // 0x8008AC24: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    after_9:
    // 0x8008AC28: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x8008AC2C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008AC30: lw          $t3, 0x318($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X318);
    // 0x8008AC34: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8008AC38: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x8008AC3C: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8008AC40: beq         $t4, $zero, L_8008AC6C
    if (ctx->r12 == 0) {
        // 0x8008AC44: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8008AC6C;
    }
    // 0x8008AC44: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AC48: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x8008AC4C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AC50: lw          $a3, 0x54($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X54);
    // 0x8008AC54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008AC58: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8008AC5C: jal         0x800C49A0
    // 0x8008AC60: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_10;
    // 0x8008AC60: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_10:
    // 0x8008AC64: b           L_8008AC88
    // 0x8008AC68: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
        goto L_8008AC88;
    // 0x8008AC68: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
L_8008AC6C:
    // 0x8008AC6C: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8008AC70: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8008AC74: lw          $a3, 0x58($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X58);
    // 0x8008AC78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008AC7C: jal         0x800C49A0
    // 0x8008AC80: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_11;
    // 0x8008AC80: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_11:
    // 0x8008AC84: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
L_8008AC88:
    // 0x8008AC88: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008AC8C: bne         $s0, $t7, L_8008ACA8
    if (ctx->r16 != ctx->r15) {
        // 0x8008AC90: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008ACA8;
    }
    // 0x8008AC90: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008AC94: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008AC98: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008AC9C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008ACA0: jal         0x800C48E4
    // 0x8008ACA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_12;
    // 0x8008ACA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
L_8008ACA8:
    // 0x8008ACA8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008ACAC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008ACB0: lw          $t1, 0x7234($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7234);
    // 0x8008ACB4: lw          $t9, 0x6980($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6980);
    // 0x8008ACB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008ACBC: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x8008ACC0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008ACC4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8008ACC8: beq         $at, $zero, L_8008ACDC
    if (ctx->r1 == 0) {
        // 0x8008ACCC: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_8008ACDC;
    }
    // 0x8008ACCC: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x8008ACD0: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8008ACD4: bne         $at, $zero, L_8008ABCC
    if (ctx->r1 != 0) {
        // 0x8008ACD8: nop
    
            goto L_8008ABCC;
    }
    // 0x8008ACD8: nop

L_8008ACDC:
    // 0x8008ACDC: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008ACE0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008ACE4: beq         $at, $zero, L_8008AD38
    if (ctx->r1 == 0) {
        // 0x8008ACE8: addiu       $s4, $s4, 0x7206
        ctx->r20 = ADD32(ctx->r20, 0X7206);
            goto L_8008AD38;
    }
    // 0x8008ACE8: addiu       $s4, $s4, 0x7206
    ctx->r20 = ADD32(ctx->r20, 0X7206);
    // 0x8008ACEC: lh          $t0, 0x0($s4)
    ctx->r8 = MEM_H(ctx->r20, 0X0);
    // 0x8008ACF0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008ACF4: bne         $s3, $t0, L_8008AD10
    if (ctx->r19 != ctx->r8) {
        // 0x8008ACF8: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008AD10;
    }
    // 0x8008ACF8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008ACFC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008AD00: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008AD04: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008AD08: jal         0x800C48E4
    // 0x8008AD0C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    set_text_colour(rdram, ctx);
        goto after_13;
    // 0x8008AD0C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_13:
L_8008AD10:
    // 0x8008AD10: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x8008AD14: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8008AD18: lw          $a3, 0x14($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X14);
    // 0x8008AD1C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008AD20: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AD24: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8008AD28: jal         0x800C49A0
    // 0x8008AD2C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_14;
    // 0x8008AD2C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_14:
    // 0x8008AD30: b           L_8008AD84
    // 0x8008AD34: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_8008AD84;
    // 0x8008AD34: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8008AD38:
    // 0x8008AD38: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008AD3C: lw          $t5, 0x695C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X695C);
    // 0x8008AD40: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AD44: andi        $t6, $t5, 0x8
    ctx->r14 = ctx->r13 & 0X8;
    // 0x8008AD48: beq         $t6, $zero, L_8008AD80
    if (ctx->r14 == 0) {
        // 0x8008AD4C: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8008AD80;
    }
    // 0x8008AD4C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008AD50: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8008AD54: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008AD58: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008AD5C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8008AD60: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8008AD64: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8008AD68: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8008AD6C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008AD70: addiu       $a1, $a1, 0x9BC
    ctx->r5 = ADD32(ctx->r5, 0X9BC);
    // 0x8008AD74: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x8008AD78: jal         0x80078F08
    // 0x8008AD7C: addiu       $a3, $s2, 0x8
    ctx->r7 = ADD32(ctx->r18, 0X8);
    texrect_draw(rdram, ctx);
        goto after_15;
    // 0x8008AD7C: addiu       $a3, $s2, 0x8
    ctx->r7 = ADD32(ctx->r18, 0X8);
    after_15:
L_8008AD80:
    // 0x8008AD80: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8008AD84:
    // 0x8008AD84: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8008AD88: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AD8C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8008AD90: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8008AD94: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8008AD98: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AD9C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8008ADA0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8008ADA4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8008ADA8: jr          $ra
    // 0x8008ADAC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8008ADAC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void cheatlist_exclusive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ADB0: and         $t6, $a0, $a1
    ctx->r14 = ctx->r4 & ctx->r5;
    // 0x8008ADB4: beq         $t6, $zero, L_8008ADD8
    if (ctx->r14 == 0) {
        // 0x8008ADB8: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8008ADD8;
    }
    // 0x8008ADB8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008ADBC: addiu       $v1, $v1, 0x318
    ctx->r3 = ADD32(ctx->r3, 0X318);
    // 0x8008ADC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008ADC4: nor         $t8, $a2, $zero
    ctx->r24 = ~(ctx->r6 | 0);
    // 0x8008ADC8: and         $t7, $a0, $v0
    ctx->r15 = ctx->r4 & ctx->r2;
    // 0x8008ADCC: beq         $t7, $zero, L_8008ADD8
    if (ctx->r15 == 0) {
        // 0x8008ADD0: and         $t9, $v0, $t8
        ctx->r25 = ctx->r2 & ctx->r24;
            goto L_8008ADD8;
    }
    // 0x8008ADD0: and         $t9, $v0, $t8
    ctx->r25 = ctx->r2 & ctx->r24;
    // 0x8008ADD4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8008ADD8:
    // 0x8008ADD8: jr          $ra
    // 0x8008ADDC: nop

    return;
    // 0x8008ADDC: nop

;}
RECOMP_FUNC void menu_magic_codes_list_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ADE0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8008ADE4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008ADE8: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008ADEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008ADF0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8008ADF4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8008ADF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008ADFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008AE00: beq         $v0, $zero, L_8008AE40
    if (ctx->r2 == 0) {
        // 0x8008AE04: sw          $zero, 0x48($sp)
        MEM_W(0X48, ctx->r29) = 0;
            goto L_8008AE40;
    }
    // 0x8008AE04: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8008AE08: blez        $v0, L_8008AE2C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008AE0C: subu        $t7, $v0, $a0
        ctx->r15 = SUB32(ctx->r2, ctx->r4);
            goto L_8008AE2C;
    }
    // 0x8008AE0C: subu        $t7, $v0, $a0
    ctx->r15 = SUB32(ctx->r2, ctx->r4);
    // 0x8008AE10: addu        $t6, $v0, $a0
    ctx->r14 = ADD32(ctx->r2, ctx->r4);
    // 0x8008AE14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008AE18: sw          $t6, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r14;
    // 0x8008AE1C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008AE20: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008AE24: b           L_8008AE40
    // 0x8008AE28: nop

        goto L_8008AE40;
    // 0x8008AE28: nop

L_8008AE2C:
    // 0x8008AE2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008AE30: sw          $t7, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r15;
    // 0x8008AE34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008AE38: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008AE3C: nop

L_8008AE40:
    // 0x8008AE40: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008AE44: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8008AE48: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008AE4C: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x8008AE50: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8008AE54: andi        $t1, $t9, 0x3F
    ctx->r9 = ctx->r25 & 0X3F;
    // 0x8008AE58: bne         $at, $zero, L_8008AE74
    if (ctx->r1 != 0) {
        // 0x8008AE5C: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8008AE74;
    }
    // 0x8008AE5C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8008AE60: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8008AE64: beq         $at, $zero, L_8008AE74
    if (ctx->r1 == 0) {
        // 0x8008AE68: nop
    
            goto L_8008AE74;
    }
    // 0x8008AE68: nop

    // 0x8008AE6C: jal         0x8008AA1C
    // 0x8008AE70: nop

    cheatlist_render(rdram, ctx);
        goto after_0;
    // 0x8008AE70: nop

    after_0:
L_8008AE74:
    // 0x8008AE74: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008AE78: lw          $t2, 0x6964($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6964);
    // 0x8008AE7C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008AE80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008AE84: bne         $t2, $zero, L_8008AEF4
    if (ctx->r10 != 0) {
        // 0x8008AE88: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8008AEF4;
    }
    // 0x8008AE88: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8008AE8C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008AE90: lw          $t3, -0x604($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X604);
    // 0x8008AE94: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008AE98: bne         $t3, $zero, L_8008AEF4
    if (ctx->r11 != 0) {
        // 0x8008AE9C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8008AEF4;
    }
    // 0x8008AE9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008AEA0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008AEA4: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x8008AEA8: addiu       $v1, $v1, 0x69FC
    ctx->r3 = ADD32(ctx->r3, 0X69FC);
    // 0x8008AEAC: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_8008AEB0:
    // 0x8008AEB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008AEB4: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8008AEB8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008AEBC: jal         0x8006A794
    // 0x8008AEC0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008AEC0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_1:
    // 0x8008AEC4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8008AEC8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AECC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008AED0: lb          $t4, 0x0($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X0);
    // 0x8008AED4: lb          $t5, 0x0($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X0);
    // 0x8008AED8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008AEDC: or          $s3, $s3, $v0
    ctx->r19 = ctx->r19 | ctx->r2;
    // 0x8008AEE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008AEE4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008AEE8: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8008AEEC: bne         $s0, $s1, L_8008AEB0
    if (ctx->r16 != ctx->r17) {
        // 0x8008AEF0: addu        $s2, $s2, $t5
        ctx->r18 = ADD32(ctx->r18, ctx->r13);
            goto L_8008AEB0;
    }
    // 0x8008AEF0: addu        $s2, $s2, $t5
    ctx->r18 = ADD32(ctx->r18, ctx->r13);
L_8008AEF4:
    // 0x8008AEF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008AEF8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008AEFC: lw          $v0, 0x31C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C);
    // 0x8008AF00: addiu       $t0, $t0, 0x7240
    ctx->r8 = ADD32(ctx->r8, 0X7240);
    // 0x8008AF04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008AF08: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8008AF0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008AF10: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_8008AF14:
    // 0x8008AF14: and         $t6, $s1, $v0
    ctx->r14 = ctx->r17 & ctx->r2;
    // 0x8008AF18: beq         $t6, $zero, L_8008AF30
    if (ctx->r14 == 0) {
        // 0x8008AF1C: sll         $t9, $s1, 1
        ctx->r25 = S32(ctx->r17 << 1);
            goto L_8008AF30;
    }
    // 0x8008AF1C: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x8008AF20: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x8008AF24: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8008AF28: sh          $s0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r16;
    // 0x8008AF2C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8008AF30:
    // 0x8008AF30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008AF34: bne         $s0, $v1, L_8008AF14
    if (ctx->r16 != ctx->r3) {
        // 0x8008AF38: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8008AF14;
    }
    // 0x8008AF38: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8008AF3C: bltz        $a2, L_8008AF48
    if (SIGNED(ctx->r6) < 0) {
        // 0x8008AF40: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8008AF48;
    }
    // 0x8008AF40: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008AF44: blez        $a2, L_8008B068
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008AF48: addiu       $s0, $s0, 0x7206
        ctx->r16 = ADD32(ctx->r16, 0X7206);
            goto L_8008B068;
    }
L_8008AF48:
    // 0x8008AF48: addiu       $s0, $s0, 0x7206
    ctx->r16 = ADD32(ctx->r16, 0X7206);
    // 0x8008AF4C: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8008AF50: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008AF54: beq         $a3, $t1, L_8008B068
    if (ctx->r7 == ctx->r9) {
        // 0x8008AF58: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008B068;
    }
    // 0x8008AF58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008AF5C: jal         0x80001D04
    // 0x8008AF60: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008AF60: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8008AF64: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x8008AF68: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008AF6C: addiu       $t0, $t0, 0x7240
    ctx->r8 = ADD32(ctx->r8, 0X7240);
    // 0x8008AF70: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8008AF74: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008AF78: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8008AF7C: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8008AF80: addiu       $v0, $v0, 0x318
    ctx->r2 = ADD32(ctx->r2, 0X318);
    // 0x8008AF84: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8008AF88: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008AF8C: sllv        $s1, $t6, $t5
    ctx->r17 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x8008AF90: xor         $t8, $t7, $s1
    ctx->r24 = ctx->r15 ^ ctx->r17;
    // 0x8008AF94: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8008AF98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AF9C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8008AFA0: jal         0x8008ADB0
    // 0x8008AFA4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    cheatlist_exclusive(rdram, ctx);
        goto after_3;
    // 0x8008AFA4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_3:
    // 0x8008AFA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AFAC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8008AFB0: jal         0x8008ADB0
    // 0x8008AFB4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    cheatlist_exclusive(rdram, ctx);
        goto after_4;
    // 0x8008AFB4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_4:
    // 0x8008AFB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AFBC: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x8008AFC0: jal         0x8008ADB0
    // 0x8008AFC4: addiu       $a2, $zero, 0x6080
    ctx->r6 = ADD32(0, 0X6080);
    cheatlist_exclusive(rdram, ctx);
        goto after_5;
    // 0x8008AFC4: addiu       $a2, $zero, 0x6080
    ctx->r6 = ADD32(0, 0X6080);
    after_5:
    // 0x8008AFC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AFCC: addiu       $a1, $zero, 0x6080
    ctx->r5 = ADD32(0, 0X6080);
    // 0x8008AFD0: jal         0x8008ADB0
    // 0x8008AFD4: addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    cheatlist_exclusive(rdram, ctx);
        goto after_6;
    // 0x8008AFD4: addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    after_6:
    // 0x8008AFD8: lui         $a2, 0x1F
    ctx->r6 = S32(0X1F << 16);
    // 0x8008AFDC: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008AFE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AFE4: jal         0x8008ADB0
    // 0x8008AFE8: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    cheatlist_exclusive(rdram, ctx);
        goto after_7;
    // 0x8008AFE8: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_7:
    // 0x8008AFEC: lui         $a1, 0x1F
    ctx->r5 = S32(0X1F << 16);
    // 0x8008AFF0: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8008AFF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AFF8: jal         0x8008ADB0
    // 0x8008AFFC: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    cheatlist_exclusive(rdram, ctx);
        goto after_8;
    // 0x8008AFFC: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    after_8:
    // 0x8008B000: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B004: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8008B008: jal         0x8008ADB0
    // 0x8008B00C: lui         $a2, 0xF
    ctx->r6 = S32(0XF << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_9;
    // 0x8008B00C: lui         $a2, 0xF
    ctx->r6 = S32(0XF << 16);
    after_9:
    // 0x8008B010: lui         $a2, 0xE
    ctx->r6 = S32(0XE << 16);
    // 0x8008B014: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008B018: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B01C: jal         0x8008ADB0
    // 0x8008B020: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_10;
    // 0x8008B020: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_10:
    // 0x8008B024: lui         $a2, 0xD
    ctx->r6 = S32(0XD << 16);
    // 0x8008B028: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008B02C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B030: jal         0x8008ADB0
    // 0x8008B034: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_11;
    // 0x8008B034: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    after_11:
    // 0x8008B038: lui         $a2, 0xB
    ctx->r6 = S32(0XB << 16);
    // 0x8008B03C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008B040: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B044: jal         0x8008ADB0
    // 0x8008B048: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_12;
    // 0x8008B048: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    after_12:
    // 0x8008B04C: lui         $a2, 0x7
    ctx->r6 = S32(0X7 << 16);
    // 0x8008B050: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008B054: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008B058: jal         0x8008ADB0
    // 0x8008B05C: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_13;
    // 0x8008B05C: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    after_13:
    // 0x8008B060: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8008B064: nop

L_8008B068:
    // 0x8008B068: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008B06C: addiu       $s0, $s0, 0x7206
    ctx->r16 = ADD32(ctx->r16, 0X7206);
    // 0x8008B070: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008B074: bgez        $s2, L_8008B0A4
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8008B078: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8008B0A4;
    }
    // 0x8008B078: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8008B07C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8008B080: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x8008B084: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008B088: nop

    // 0x8008B08C: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008B090: beq         $at, $zero, L_8008B0A4
    if (ctx->r1 == 0) {
        // 0x8008B094: nop
    
            goto L_8008B0A4;
    }
    // 0x8008B094: nop

    // 0x8008B098: sh          $a3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r7;
    // 0x8008B09C: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008B0A0: nop

L_8008B0A4:
    // 0x8008B0A4: blez        $s2, L_8008B0D0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8008B0A8: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8008B0D0;
    }
    // 0x8008B0A8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008B0AC: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8008B0B0: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x8008B0B4: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008B0B8: nop

    // 0x8008B0BC: bgez        $v0, L_8008B0D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008B0C0: nop
    
            goto L_8008B0D0;
    }
    // 0x8008B0C0: nop

    // 0x8008B0C4: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8008B0C8: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008B0CC: nop

L_8008B0D0:
    // 0x8008B0D0: addiu       $a1, $a1, 0x6980
    ctx->r5 = ADD32(ctx->r5, 0X6980);
    // 0x8008B0D4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008B0D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B0DC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008B0E0: beq         $at, $zero, L_8008B0F0
    if (ctx->r1 == 0) {
        // 0x8008B0E4: nop
    
            goto L_8008B0F0;
    }
    // 0x8008B0E4: nop

    // 0x8008B0E8: b           L_8008B110
    // 0x8008B0EC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_8008B110;
    // 0x8008B0EC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8008B0F0:
    // 0x8008B0F0: lw          $a0, 0x7234($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7234);
    // 0x8008B0F4: nop

    // 0x8008B0F8: addu        $t2, $v1, $a0
    ctx->r10 = ADD32(ctx->r3, ctx->r4);
    // 0x8008B0FC: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008B100: bne         $at, $zero, L_8008B110
    if (ctx->r1 != 0) {
        // 0x8008B104: subu        $t3, $v0, $a0
        ctx->r11 = SUB32(ctx->r2, ctx->r4);
            goto L_8008B110;
    }
    // 0x8008B104: subu        $t3, $v0, $a0
    ctx->r11 = SUB32(ctx->r2, ctx->r4);
    // 0x8008B108: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008B10C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
L_8008B110:
    // 0x8008B110: beq         $a2, $v0, L_8008B12C
    if (ctx->r6 == ctx->r2) {
        // 0x8008B114: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008B12C;
    }
    // 0x8008B114: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008B118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B11C: jal         0x80001D04
    // 0x8008B120: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_14;
    // 0x8008B120: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_14:
    // 0x8008B124: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8008B128: nop

L_8008B12C:
    // 0x8008B12C: andi        $t6, $s3, 0x9000
    ctx->r14 = ctx->r19 & 0X9000;
    // 0x8008B130: beq         $t6, $zero, L_8008B14C
    if (ctx->r14 == 0) {
        // 0x8008B134: andi        $t8, $s3, 0x4000
        ctx->r24 = ctx->r19 & 0X4000;
            goto L_8008B14C;
    }
    // 0x8008B134: andi        $t8, $s3, 0x4000
    ctx->r24 = ctx->r19 & 0X4000;
    // 0x8008B138: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x8008B13C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008B140: bne         $a3, $t5, L_8008B14C
    if (ctx->r7 != ctx->r13) {
        // 0x8008B144: nop
    
            goto L_8008B14C;
    }
    // 0x8008B144: nop

    // 0x8008B148: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
L_8008B14C:
    // 0x8008B14C: beq         $t8, $zero, L_8008B158
    if (ctx->r24 == 0) {
        // 0x8008B150: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_8008B158;
    }
    // 0x8008B150: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8008B154: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
L_8008B158:
    // 0x8008B158: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8008B15C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B160: beq         $t1, $zero, L_8008B180
    if (ctx->r9 == 0) {
        // 0x8008B164: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008B180;
    }
    // 0x8008B164: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B168: sw          $t1, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r9;
    // 0x8008B16C: jal         0x800C06F8
    // 0x8008B170: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_15;
    // 0x8008B170: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_15:
    // 0x8008B174: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008B178: jal         0x80001D04
    // 0x8008B17C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_16;
    // 0x8008B17C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
L_8008B180:
    // 0x8008B180: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008B184: lw          $t2, -0x604($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X604);
    // 0x8008B188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B18C: slti        $at, $t2, -0x1E
    ctx->r1 = SIGNED(ctx->r10) < -0X1E ? 1 : 0;
    // 0x8008B190: beq         $at, $zero, L_8008B1B0
    if (ctx->r1 == 0) {
        // 0x8008B194: nop
    
            goto L_8008B1B0;
    }
    // 0x8008B194: nop

    // 0x8008B198: jal         0x8008B1D4
    // 0x8008B19C: nop

    cheatlist_free(rdram, ctx);
        goto after_17;
    // 0x8008B19C: nop

    after_17:
    // 0x8008B1A0: jal         0x80081820
    // 0x8008B1A4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    menu_init(rdram, ctx);
        goto after_18;
    // 0x8008B1A4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_18:
    // 0x8008B1A8: b           L_8008B1B8
    // 0x8008B1AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008B1B8;
    // 0x8008B1AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008B1B0:
    // 0x8008B1B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B1B4: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_8008B1B8:
    // 0x8008B1B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008B1BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008B1C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008B1C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B1C8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8008B1CC: jr          $ra
    // 0x8008B1D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8008B1D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void cheatlist_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B1D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B1D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B1DC: jal         0x8009CA4C
    // 0x8008B1E0: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    menu_asset_free(rdram, ctx);
        goto after_0;
    // 0x8008B1E0: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_0:
    // 0x8008B1E4: jal         0x800C478C
    // 0x8008B1E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_1;
    // 0x8008B1E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8008B1EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B1F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B1F4: jr          $ra
    // 0x8008B1F8: nop

    return;
    // 0x8008B1F8: nop

;}
RECOMP_FUNC void cheatmenu_checksum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B1FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008B200: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008B204: lw          $t6, 0x2398($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2398);
    // 0x8008B208: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008B20C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008B210: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008B214: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008B218: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008B21C: bne         $t6, $zero, L_8008B30C
    if (ctx->r14 != 0) {
        // 0x8008B220: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8008B30C;
    }
    // 0x8008B220: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B224: lui         $s0, 0xB9
    ctx->r16 = S32(0XB9 << 16);
    // 0x8008B228: addiu       $s0, $s0, -0x3030
    ctx->r16 = ADD32(ctx->r16, -0X3030);
    // 0x8008B22C: addiu       $s0, $s0, -0x1000
    ctx->r16 = ADD32(ctx->r16, -0X1000);
    // 0x8008B230: addiu       $s3, $zero, 0x1000
    ctx->r19 = ADD32(0, 0X1000);
    // 0x8008B234: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x8008B238: addiu       $a0, $zero, 0x5000
    ctx->r4 = ADD32(0, 0X5000);
    // 0x8008B23C: jal         0x80070EDC
    // 0x8008B240: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8008B240: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_0:
    // 0x8008B244: beq         $s0, $zero, L_8008B2F8
    if (ctx->r16 == 0) {
        // 0x8008B248: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_8008B2F8;
    }
    // 0x8008B248: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_8008B24C:
    // 0x8008B24C: slti        $at, $s2, 0x5001
    ctx->r1 = SIGNED(ctx->r18) < 0X5001 ? 1 : 0;
    // 0x8008B250: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x8008B254: bne         $at, $zero, L_8008B260
    if (ctx->r1 != 0) {
        // 0x8008B258: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8008B260;
    }
    // 0x8008B258: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008B25C: addiu       $s1, $zero, 0x5000
    ctx->r17 = ADD32(0, 0X5000);
L_8008B260:
    // 0x8008B260: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008B264: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8008B268: jal         0x80077370
    // 0x8008B26C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    dmacopy(rdram, ctx);
        goto after_1;
    // 0x8008B26C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x8008B270: blez        $s1, L_8008B2F0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8008B274: subu        $s2, $s2, $s1
        ctx->r18 = SUB32(ctx->r18, ctx->r17);
            goto L_8008B2F0;
    }
    // 0x8008B274: subu        $s2, $s2, $s1
    ctx->r18 = SUB32(ctx->r18, ctx->r17);
    // 0x8008B278: andi        $a0, $s1, 0x3
    ctx->r4 = ctx->r17 & 0X3;
    // 0x8008B27C: beq         $a0, $zero, L_8008B2B0
    if (ctx->r4 == 0) {
        // 0x8008B280: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8008B2B0;
    }
    // 0x8008B280: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8008B284: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008B288: lw          $a1, 0x2394($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2394);
    // 0x8008B28C: addu        $v0, $s4, $s0
    ctx->r2 = ADD32(ctx->r20, ctx->r16);
L_8008B290:
    // 0x8008B290: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8008B294: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B298: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B29C: bne         $v1, $s0, L_8008B290
    if (ctx->r3 != ctx->r16) {
        // 0x8008B2A0: addu        $a1, $a1, $t7
        ctx->r5 = ADD32(ctx->r5, ctx->r15);
            goto L_8008B290;
    }
    // 0x8008B2A0: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8008B2A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B2A8: beq         $s0, $s1, L_8008B2F0
    if (ctx->r16 == ctx->r17) {
        // 0x8008B2AC: sw          $a1, 0x2394($at)
        MEM_W(0X2394, ctx->r1) = ctx->r5;
            goto L_8008B2F0;
    }
    // 0x8008B2AC: sw          $a1, 0x2394($at)
    MEM_W(0X2394, ctx->r1) = ctx->r5;
L_8008B2B0:
    // 0x8008B2B0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008B2B4: lw          $a1, 0x2394($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2394);
    // 0x8008B2B8: addu        $v0, $s4, $s0
    ctx->r2 = ADD32(ctx->r20, ctx->r16);
L_8008B2BC:
    // 0x8008B2BC: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8008B2C0: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8008B2C4: lbu         $t0, 0x2($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2);
    // 0x8008B2C8: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8008B2CC: lbu         $t1, 0x3($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X3);
    // 0x8008B2D0: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8008B2D4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008B2D8: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x8008B2DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008B2E0: bne         $s0, $s1, L_8008B2BC
    if (ctx->r16 != ctx->r17) {
        // 0x8008B2E4: addu        $a1, $a1, $t1
        ctx->r5 = ADD32(ctx->r5, ctx->r9);
            goto L_8008B2BC;
    }
    // 0x8008B2E4: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x8008B2E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B2EC: sw          $a1, 0x2394($at)
    MEM_W(0X2394, ctx->r1) = ctx->r5;
L_8008B2F0:
    // 0x8008B2F0: bne         $s2, $zero, L_8008B24C
    if (ctx->r18 != 0) {
        // 0x8008B2F4: addu        $s3, $s3, $s1
        ctx->r19 = ADD32(ctx->r19, ctx->r17);
            goto L_8008B24C;
    }
    // 0x8008B2F4: addu        $s3, $s3, $s1
    ctx->r19 = ADD32(ctx->r19, ctx->r17);
L_8008B2F8:
    // 0x8008B2F8: jal         0x80071380
    // 0x8008B2FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mempool_free(rdram, ctx);
        goto after_2;
    // 0x8008B2FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x8008B300: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008B304: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B308: sw          $t2, 0x2398($at)
    MEM_W(0X2398, ctx->r1) = ctx->r10;
L_8008B30C:
    // 0x8008B30C: lui         $s0, 0xB9
    ctx->r16 = S32(0XB9 << 16);
    // 0x8008B310: addiu       $s0, $s0, -0x3030
    ctx->r16 = ADD32(ctx->r16, -0X3030);
    // 0x8008B314: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008B318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B31C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008B320: jal         0x800B6814
    // 0x8008B324: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_render_printf_background_colour(rdram, ctx);
        goto after_3;
    // 0x8008B324: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_3:
    // 0x8008B328: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8008B32C: jal         0x800B68BC
    // 0x8008B330: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    set_render_printf_position(rdram, ctx);
        goto after_4;
    // 0x8008B330: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    after_4:
    // 0x8008B334: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008B338: lw          $a1, 0x2394($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2394);
    // 0x8008B33C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B340: addiu       $a0, $a0, -0x7858
    ctx->r4 = ADD32(ctx->r4, -0X7858);
    // 0x8008B344: jal         0x800B643C
    // 0x8008B348: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    render_printf(rdram, ctx);
        goto after_5;
    // 0x8008B348: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x8008B34C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B350: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B354: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B358: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008B35C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008B360: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008B364: jr          $ra
    // 0x8008B368: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008B368: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void charselect_prev(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B36C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008B370: beq         $a0, $v0, L_8008B394
    if (ctx->r4 == ctx->r2) {
        // 0x8008B374: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8008B394;
    }
    // 0x8008B374: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8008B378: beq         $a0, $v1, L_8008B3A0
    if (ctx->r4 == ctx->r3) {
        // 0x8008B37C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8008B3A0;
    }
    // 0x8008B37C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B380: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008B384: beq         $a0, $at, L_8008B394
    if (ctx->r4 == ctx->r1) {
        // 0x8008B388: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8008B394;
    }
    // 0x8008B388: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B38C: jr          $ra
    // 0x8008B390: sw          $zero, 0x550($at)
    MEM_W(0X550, ctx->r1) = 0;
    return;
    // 0x8008B390: sw          $zero, 0x550($at)
    MEM_W(0X550, ctx->r1) = 0;
L_8008B394:
    // 0x8008B394: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B398: jr          $ra
    // 0x8008B39C: sw          $v0, 0x550($at)
    MEM_W(0X550, ctx->r1) = ctx->r2;
    return;
    // 0x8008B39C: sw          $v0, 0x550($at)
    MEM_W(0X550, ctx->r1) = ctx->r2;
L_8008B3A0:
    // 0x8008B3A0: sw          $v1, 0x550($at)
    MEM_W(0X550, ctx->r1) = ctx->r3;
    // 0x8008B3A4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8008B3A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B3AC: sw          $t6, 0x554($at)
    MEM_W(0X554, ctx->r1) = ctx->r14;
    // 0x8008B3B0: jr          $ra
    // 0x8008B3B4: nop

    return;
    // 0x8008B3B4: nop

;}
RECOMP_FUNC void titlescreen_controller_assign(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B3B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008B3BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008B3C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B3C4: addiu       $a1, $t6, 0x6988
    ctx->r5 = ADD32(ctx->r14, 0X6988);
    // 0x8008B3C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B3CC: sw          $a2, -0x5C4($at)
    MEM_W(-0X5C4, ctx->r1) = ctx->r6;
    // 0x8008B3D0: addiu       $v0, $v0, 0x6990
    ctx->r2 = ADD32(ctx->r2, 0X6990);
    // 0x8008B3D4: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x8008B3D8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8008B3DC:
    // 0x8008B3DC: bne         $a1, $v1, L_8008B3EC
    if (ctx->r5 != ctx->r3) {
        // 0x8008B3E0: nop
    
            goto L_8008B3EC;
    }
    // 0x8008B3E0: nop

    // 0x8008B3E4: b           L_8008B3F0
    // 0x8008B3E8: sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
        goto L_8008B3F0;
    // 0x8008B3E8: sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
L_8008B3EC:
    // 0x8008B3EC: sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
L_8008B3F0:
    // 0x8008B3F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008B3F4: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8008B3F8: bne         $at, $zero, L_8008B3DC
    if (ctx->r1 != 0) {
        // 0x8008B3FC: nop
    
            goto L_8008B3DC;
    }
    // 0x8008B3FC: nop

    // 0x8008B400: bne         $a0, $zero, L_8008B418
    if (ctx->r4 != 0) {
        // 0x8008B404: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008B418;
    }
    // 0x8008B404: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B408: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008B40C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B410: b           L_8008B41C
    // 0x8008B414: sb          $t7, 0x6974($at)
    MEM_B(0X6974, ctx->r1) = ctx->r15;
        goto L_8008B41C;
    // 0x8008B414: sb          $t7, 0x6974($at)
    MEM_B(0X6974, ctx->r1) = ctx->r15;
L_8008B418:
    // 0x8008B418: sb          $zero, 0x6974($at)
    MEM_B(0X6974, ctx->r1) = 0;
L_8008B41C:
    // 0x8008B41C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008B420: bne         $a0, $at, L_8008B434
    if (ctx->r4 != ctx->r1) {
        // 0x8008B424: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008B434;
    }
    // 0x8008B424: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008B428: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B42C: b           L_8008B43C
    // 0x8008B430: sb          $t8, 0x6975($at)
    MEM_B(0X6975, ctx->r1) = ctx->r24;
        goto L_8008B43C;
    // 0x8008B430: sb          $t8, 0x6975($at)
    MEM_B(0X6975, ctx->r1) = ctx->r24;
L_8008B434:
    // 0x8008B434: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B438: sb          $zero, 0x6975($at)
    MEM_B(0X6975, ctx->r1) = 0;
L_8008B43C:
    // 0x8008B43C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008B440: bne         $a0, $at, L_8008B454
    if (ctx->r4 != ctx->r1) {
        // 0x8008B444: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008B454;
    }
    // 0x8008B444: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008B448: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B44C: b           L_8008B45C
    // 0x8008B450: sb          $t9, 0x6976($at)
    MEM_B(0X6976, ctx->r1) = ctx->r25;
        goto L_8008B45C;
    // 0x8008B450: sb          $t9, 0x6976($at)
    MEM_B(0X6976, ctx->r1) = ctx->r25;
L_8008B454:
    // 0x8008B454: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B458: sb          $zero, 0x6976($at)
    MEM_B(0X6976, ctx->r1) = 0;
L_8008B45C:
    // 0x8008B45C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008B460: bne         $a0, $at, L_8008B474
    if (ctx->r4 != ctx->r1) {
        // 0x8008B464: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8008B474;
    }
    // 0x8008B464: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008B468: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B46C: jr          $ra
    // 0x8008B470: sb          $t0, 0x6977($at)
    MEM_B(0X6977, ctx->r1) = ctx->r8;
    return;
    // 0x8008B470: sb          $t0, 0x6977($at)
    MEM_B(0X6977, ctx->r1) = ctx->r8;
L_8008B474:
    // 0x8008B474: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B478: sb          $zero, 0x6977($at)
    MEM_B(0X6977, ctx->r1) = 0;
    // 0x8008B47C: jr          $ra
    // 0x8008B480: nop

    return;
    // 0x8008B480: nop

;}
RECOMP_FUNC void menu_character_select_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B484: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008B488: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008B48C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008B490: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008B494: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008B498: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008B49C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B4A0: jal         0x8006A674
    // 0x8008B4A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    input_assign_players(rdram, ctx);
        goto after_0;
    // 0x8008B4A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x8008B4A8: jal         0x8009F214
    // 0x8008B4AC: nop

    is_drumstick_unlocked(rdram, ctx);
        goto after_1;
    // 0x8008B4AC: nop

    after_1:
    // 0x8008B4B0: beq         $v0, $zero, L_8008B4F4
    if (ctx->r2 == 0) {
        // 0x8008B4B4: nop
    
            goto L_8008B4F4;
    }
    // 0x8008B4B4: nop

    // 0x8008B4B8: jal         0x8009F1FC
    // 0x8008B4BC: nop

    is_tt_unlocked(rdram, ctx);
        goto after_2;
    // 0x8008B4BC: nop

    after_2:
    // 0x8008B4C0: beq         $v0, $zero, L_8008B4E0
    if (ctx->r2 == 0) {
        // 0x8008B4C4: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8008B4E0;
    }
    // 0x8008B4C4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008B4C8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008B4CC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008B4D0: addiu       $a3, $a3, 0x696C
    ctx->r7 = ADD32(ctx->r7, 0X696C);
    // 0x8008B4D4: addiu       $t6, $t6, 0x4C0
    ctx->r14 = ADD32(ctx->r14, 0X4C0);
    // 0x8008B4D8: b           L_8008B52C
    // 0x8008B4DC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
        goto L_8008B52C;
    // 0x8008B4DC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
L_8008B4E0:
    // 0x8008B4E0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008B4E4: addiu       $a3, $a3, 0x696C
    ctx->r7 = ADD32(ctx->r7, 0X696C);
    // 0x8008B4E8: addiu       $t7, $t7, 0x3C0
    ctx->r15 = ADD32(ctx->r15, 0X3C0);
    // 0x8008B4EC: b           L_8008B52C
    // 0x8008B4F0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
        goto L_8008B52C;
    // 0x8008B4F0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
L_8008B4F4:
    // 0x8008B4F4: jal         0x8009F1FC
    // 0x8008B4F8: nop

    is_tt_unlocked(rdram, ctx);
        goto after_3;
    // 0x8008B4F8: nop

    after_3:
    // 0x8008B4FC: beq         $v0, $zero, L_8008B518
    if (ctx->r2 == 0) {
        // 0x8008B500: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8008B518;
    }
    // 0x8008B500: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008B504: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008B508: addiu       $a3, $a3, 0x696C
    ctx->r7 = ADD32(ctx->r7, 0X696C);
    // 0x8008B50C: addiu       $t8, $t8, 0x440
    ctx->r24 = ADD32(ctx->r24, 0X440);
    // 0x8008B510: b           L_8008B52C
    // 0x8008B514: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
        goto L_8008B52C;
    // 0x8008B514: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_8008B518:
    // 0x8008B518: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008B51C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008B520: addiu       $a3, $a3, 0x696C
    ctx->r7 = ADD32(ctx->r7, 0X696C);
    // 0x8008B524: addiu       $t9, $t9, 0x350
    ctx->r25 = ADD32(ctx->r25, 0X350);
    // 0x8008B528: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
L_8008B52C:
    // 0x8008B52C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B530: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008B534: addiu       $v1, $v1, 0x6980
    ctx->r3 = ADD32(ctx->r3, 0X6980);
    // 0x8008B538: addiu       $v0, $v0, 0x697C
    ctx->r2 = ADD32(ctx->r2, 0X697C);
L_8008B53C:
    // 0x8008B53C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B540: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008B544: bne         $at, $zero, L_8008B53C
    if (ctx->r1 != 0) {
        // 0x8008B548: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_8008B53C;
    }
    // 0x8008B548: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x8008B54C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B550: sw          $zero, -0x600($at)
    MEM_W(-0X600, ctx->r1) = 0;
    // 0x8008B554: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B558: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8008B55C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B560: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8008B564: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008B568: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B56C: addiu       $t0, $t0, 0x6974
    ctx->r8 = ADD32(ctx->r8, 0X6974);
    // 0x8008B570: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008B574: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008B578: sw          $zero, -0x5FC($at)
    MEM_W(-0X5FC, ctx->r1) = 0;
    // 0x8008B57C: addiu       $v1, $v1, 0x6988
    ctx->r3 = ADD32(ctx->r3, 0X6988);
    // 0x8008B580: addiu       $s2, $s2, 0x6960
    ctx->r18 = ADD32(ctx->r18, 0X6960);
    // 0x8008B584: addu        $v0, $zero, $t0
    ctx->r2 = ADD32(0, ctx->r8);
    // 0x8008B588: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008B58C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008B590: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x8008B594: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
L_8008B598:
    // 0x8008B598: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x8008B59C: addu        $t3, $v1, $s0
    ctx->r11 = ADD32(ctx->r3, ctx->r16);
    // 0x8008B5A0: beq         $t1, $zero, L_8008B5D0
    if (ctx->r9 == 0) {
        // 0x8008B5A4: nop
    
            goto L_8008B5D0;
    }
    // 0x8008B5A4: nop

    // 0x8008B5A8: lb          $t4, 0x0($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X0);
    // 0x8008B5AC: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8008B5B0: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B5B4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8008B5B8: mflo        $t5
    ctx->r13 = lo;
    // 0x8008B5BC: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x8008B5C0: lh          $t7, 0xC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XC);
    // 0x8008B5C4: sh          $a1, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r5;
    // 0x8008B5C8: sb          $a2, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r6;
    // 0x8008B5CC: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
L_8008B5D0:
    // 0x8008B5D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B5D4: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8008B5D8: beq         $at, $zero, L_8008B5E8
    if (ctx->r1 == 0) {
        // 0x8008B5DC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008B5E8;
    }
    // 0x8008B5DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B5E0: beq         $s1, $zero, L_8008B598
    if (ctx->r17 == 0) {
        // 0x8008B5E4: nop
    
            goto L_8008B598;
    }
    // 0x8008B5E4: nop

L_8008B5E8:
    // 0x8008B5E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B5EC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008B5F0: addiu       $v1, $v1, 0x6958
    ctx->r3 = ADD32(ctx->r3, 0X6958);
    // 0x8008B5F4: addiu       $v0, $v0, 0x6954
    ctx->r2 = ADD32(ctx->r2, 0X6954);
    // 0x8008B5F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008B5FC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008B600: addiu       $s2, $s2, 0x6960
    ctx->r18 = ADD32(ctx->r18, 0X6960);
    // 0x8008B604: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x8008B608: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008B60C: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8008B610: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
    // 0x8008B614: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x8008B618: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x8008B61C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x8008B620: jal         0x80000B34
    // 0x8008B624: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    music_play(rdram, ctx);
        goto after_4;
    // 0x8008B624: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_4:
    // 0x8008B628: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008B62C: addiu       $s3, $s3, 0x334
    ctx->r19 = ADD32(ctx->r19, 0X334);
    // 0x8008B630: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_8008B634:
    // 0x8008B634: lb          $t8, 0x0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X0);
    // 0x8008B638: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x8008B63C: beq         $s0, $t8, L_8008B65C
    if (ctx->r16 == ctx->r24) {
        // 0x8008B640: addu        $s1, $s3, $t9
        ctx->r17 = ADD32(ctx->r19, ctx->r25);
            goto L_8008B65C;
    }
    // 0x8008B640: addu        $s1, $s3, $t9
    ctx->r17 = ADD32(ctx->r19, ctx->r25);
    // 0x8008B644: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8008B648: jal         0x80001114
    // 0x8008B64C: nop

    music_channel_off(rdram, ctx);
        goto after_5;
    // 0x8008B64C: nop

    after_5:
    // 0x8008B650: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x8008B654: jal         0x80001114
    // 0x8008B658: nop

    music_channel_off(rdram, ctx);
        goto after_6;
    // 0x8008B658: nop

    after_6:
L_8008B65C:
    // 0x8008B65C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B660: bne         $s0, $s4, L_8008B634
    if (ctx->r16 != ctx->r20) {
        // 0x8008B664: nop
    
            goto L_8008B634;
    }
    // 0x8008B664: nop

    // 0x8008B668: jal         0x80001114
    // 0x8008B66C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_channel_off(rdram, ctx);
        goto after_7;
    // 0x8008B66C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_7:
    // 0x8008B670: jal         0x80000B18
    // 0x8008B674: nop

    music_change_off(rdram, ctx);
        goto after_8;
    // 0x8008B674: nop

    after_8:
    // 0x8008B678: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B67C: jal         0x8009CBB8
    // 0x8008B680: addiu       $a0, $a0, 0x348
    ctx->r4 = ADD32(ctx->r4, 0X348);
    menu_assetgroup_load(rdram, ctx);
        goto after_9;
    // 0x8008B680: addiu       $a0, $a0, 0x348
    ctx->r4 = ADD32(ctx->r4, 0X348);
    after_9:
    // 0x8008B684: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B688: jal         0x8009CDE8
    // 0x8008B68C: addiu       $a0, $a0, 0x34C
    ctx->r4 = ADD32(ctx->r4, 0X34C);
    menu_imagegroup_load(rdram, ctx);
        goto after_10;
    // 0x8008B68C: addiu       $a0, $a0, 0x34C
    ctx->r4 = ADD32(ctx->r4, 0X34C);
    after_10:
    // 0x8008B690: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B694: jal         0x800C06F8
    // 0x8008B698: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_11;
    // 0x8008B698: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_11:
    // 0x8008B69C: jal         0x800C46D0
    // 0x8008B6A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_12;
    // 0x8008B6A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x8008B6A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B6A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B6AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B6B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008B6B4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008B6B8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008B6BC: jr          $ra
    // 0x8008B6C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008B6C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void charselect_render_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B6C4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008B6C8: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008B6CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B6D0: slti        $at, $v0, -0x16
    ctx->r1 = SIGNED(ctx->r2) < -0X16 ? 1 : 0;
    // 0x8008B6D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008B6D8: bne         $at, $zero, L_8008B800
    if (ctx->r1 != 0) {
        // 0x8008B6DC: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8008B800;
    }
    // 0x8008B6DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008B6E0: slti        $at, $v0, 0x17
    ctx->r1 = SIGNED(ctx->r2) < 0X17 ? 1 : 0;
    // 0x8008B6E4: beq         $at, $zero, L_8008B804
    if (ctx->r1 == 0) {
        // 0x8008B6E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008B804;
    }
    // 0x8008B6E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B6EC: jal         0x800C484C
    // 0x8008B6F0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_0;
    // 0x8008B6F0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008B6F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008B6F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B6FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008B700: jal         0x800C492C
    // 0x8008B704: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x8008B704: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8008B708: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8008B70C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008B710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008B714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B718: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008B71C: jal         0x800C48E4
    // 0x8008B720: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x8008B720: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x8008B724: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008B728: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x8008B72C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B730: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8008B734: lw          $a3, 0x21C($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X21C);
    // 0x8008B738: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008B73C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008B740: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8008B744: jal         0x800C49A0
    // 0x8008B748: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_3;
    // 0x8008B748: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_3:
    // 0x8008B74C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008B750: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008B754: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008B758: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008B75C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008B760: jal         0x800C48E4
    // 0x8008B764: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x8008B764: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8008B768: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008B76C: lw          $t0, -0x5E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E0);
    // 0x8008B770: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B774: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008B778: lw          $a3, 0x21C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X21C);
    // 0x8008B77C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008B780: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008B784: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008B788: jal         0x800C49A0
    // 0x8008B78C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x8008B78C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x8008B790: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008B794: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008B798: lw          $t2, -0x600($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X600);
    // 0x8008B79C: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8008B7A0: nop

    // 0x8008B7A4: bne         $v0, $t2, L_8008B7E4
    if (ctx->r2 != ctx->r10) {
        // 0x8008B7A8: nop
    
            goto L_8008B7E4;
    }
    // 0x8008B7A8: nop

    // 0x8008B7AC: blez        $v0, L_8008B7E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008B7B0: lui         $t3, 0x8000
        ctx->r11 = S32(0X8000 << 16);
            goto L_8008B7E4;
    }
    // 0x8008B7B0: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8008B7B4: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x8008B7B8: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // 0x8008B7BC: bne         $t3, $zero, L_8008B7C8
    if (ctx->r11 != 0) {
        // 0x8008B7C0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8008B7C8;
    }
    // 0x8008B7C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B7C4: addiu       $a2, $zero, 0xEA
    ctx->r6 = ADD32(0, 0XEA);
L_8008B7C8:
    // 0x8008B7C8: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8008B7CC: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8008B7D0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008B7D4: addiu       $a3, $a3, -0x7840
    ctx->r7 = ADD32(ctx->r7, -0X7840);
    // 0x8008B7D8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008B7DC: jal         0x800C49A0
    // 0x8008B7E0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    draw_text(rdram, ctx);
        goto after_6;
    // 0x8008B7E0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_6:
L_8008B7E4:
    // 0x8008B7E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B7E8: jal         0x8007B820
    // 0x8008B7EC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    rendermode_reset(rdram, ctx);
        goto after_7;
    // 0x8008B7EC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_7:
    // 0x8008B7F0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8008B7F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008B7F8: jal         0x8006632C
    // 0x8008B7FC: nop

    cam_set_fov(rdram, ctx);
        goto after_8;
    // 0x8008B7FC: nop

    after_8:
L_8008B800:
    // 0x8008B800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008B804:
    // 0x8008B804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B808: jr          $ra
    // 0x8008B80C: nop

    return;
    // 0x8008B80C: nop

;}
RECOMP_FUNC void charselect_new_player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B810: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008B814: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008B818: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008B81C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008B820: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008B824: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008B828: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B82C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8008B830: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008B834: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008B838: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008B83C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008B840: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8008B844: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8008B848: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008B84C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008B850: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008B854: addiu       $s7, $s7, 0x696C
    ctx->r23 = ADD32(ctx->r23, 0X696C);
    // 0x8008B858: addiu       $s5, $s5, 0x6D78
    ctx->r21 = ADD32(ctx->r21, 0X6D78);
    // 0x8008B85C: addiu       $s4, $s4, -0x5C4
    ctx->r20 = ADD32(ctx->r20, -0X5C4);
    // 0x8008B860: addiu       $s3, $s3, 0x6960
    ctx->r19 = ADD32(ctx->r19, 0X6960);
    // 0x8008B864: addiu       $s2, $s2, 0x6974
    ctx->r18 = ADD32(ctx->r18, 0X6974);
    // 0x8008B868: addiu       $s0, $s0, 0x6988
    ctx->r16 = ADD32(ctx->r16, 0X6988);
    // 0x8008B86C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008B870: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8008B874: addiu       $fp, $zero, 0xE
    ctx->r30 = ADD32(0, 0XE);
L_8008B878:
    // 0x8008B878: lb          $t6, 0x0($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X0);
    // 0x8008B87C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8008B880: bne         $t6, $zero, L_8008B940
    if (ctx->r14 != 0) {
        // 0x8008B884: addu        $t8, $s5, $t7
        ctx->r24 = ADD32(ctx->r21, ctx->r15);
            goto L_8008B940;
    }
    // 0x8008B884: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8008B888: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8008B88C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8008B890: andi        $t0, $t9, 0x9000
    ctx->r8 = ctx->r25 & 0X9000;
    // 0x8008B894: beq         $t0, $zero, L_8008B940
    if (ctx->r8 == 0) {
        // 0x8008B898: addu        $a3, $s0, $s1
        ctx->r7 = ADD32(ctx->r16, ctx->r17);
            goto L_8008B940;
    }
    // 0x8008B898: addu        $a3, $s0, $s1
    ctx->r7 = ADD32(ctx->r16, ctx->r17);
L_8008B89C:
    // 0x8008B89C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008B8A0: addiu       $t1, $t1, 0x6974
    ctx->r9 = ADD32(ctx->r9, 0X6974);
    // 0x8008B8A4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008B8A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008B8AC: addu        $v1, $zero, $t1
    ctx->r3 = ADD32(0, ctx->r9);
    // 0x8008B8B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008B8B4:
    // 0x8008B8B4: lb          $t2, 0x0($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X0);
    // 0x8008B8B8: addu        $t3, $s0, $v0
    ctx->r11 = ADD32(ctx->r16, ctx->r2);
    // 0x8008B8BC: beq         $t2, $zero, L_8008B8D8
    if (ctx->r10 == 0) {
        // 0x8008B8C0: nop
    
            goto L_8008B8D8;
    }
    // 0x8008B8C0: nop

    // 0x8008B8C4: lb          $t4, 0x0($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X0);
    // 0x8008B8C8: nop

    // 0x8008B8CC: bne         $a2, $t4, L_8008B8D8
    if (ctx->r6 != ctx->r12) {
        // 0x8008B8D0: nop
    
            goto L_8008B8D8;
    }
    // 0x8008B8D0: nop

    // 0x8008B8D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8008B8D8:
    // 0x8008B8D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B8DC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8008B8E0: beq         $at, $zero, L_8008B8F0
    if (ctx->r1 == 0) {
        // 0x8008B8E4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8008B8F0;
    }
    // 0x8008B8E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008B8E8: bne         $a0, $zero, L_8008B8B4
    if (ctx->r4 != 0) {
        // 0x8008B8EC: nop
    
            goto L_8008B8B4;
    }
    // 0x8008B8EC: nop

L_8008B8F0:
    // 0x8008B8F0: beq         $a0, $zero, L_8008B89C
    if (ctx->r4 == 0) {
        // 0x8008B8F4: nop
    
            goto L_8008B89C;
    }
    // 0x8008B8F4: nop

    // 0x8008B8F8: sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // 0x8008B8FC: lb          $t8, 0x0($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X0);
    // 0x8008B900: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x8008B904: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B908: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8008B90C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8008B910: sb          $s6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r22;
    // 0x8008B914: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8008B918: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8008B91C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008B920: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B924: mflo        $t9
    ctx->r25 = lo;
    // 0x8008B928: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8008B92C: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x8008B930: sh          $zero, 0x2($s3)
    MEM_H(0X2, ctx->r19) = 0;
    // 0x8008B934: sb          $t2, 0x1($s3)
    MEM_B(0X1, ctx->r19) = ctx->r10;
    // 0x8008B938: jal         0x80001D04
    // 0x8008B93C: sb          $t1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r9;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x8008B93C: sb          $t1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r9;
    after_0:
L_8008B940:
    // 0x8008B940: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008B944: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008B948: bne         $s1, $at, L_8008B878
    if (ctx->r17 != ctx->r1) {
        // 0x8008B94C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8008B878;
    }
    // 0x8008B94C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008B950: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008B954: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B958: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B95C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008B960: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008B964: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008B968: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B96C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008B970: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008B974: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8008B978: jr          $ra
    // 0x8008B97C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8008B97C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void charselect_pick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B980: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008B984: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008B988: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008B98C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B990: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008B994: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008B998: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008B99C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8008B9A0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008B9A4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008B9A8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008B9AC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008B9B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008B9B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B9B8: addiu       $s4, $s4, 0x6D78
    ctx->r20 = ADD32(ctx->r20, 0X6D78);
    // 0x8008B9BC: addiu       $s1, $s1, 0x6974
    ctx->r17 = ADD32(ctx->r17, 0X6974);
    // 0x8008B9C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8008B9C4:
    // 0x8008B9C4: lb          $t6, 0x0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X0);
    // 0x8008B9C8: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8008B9CC: beq         $t6, $zero, L_8008B9E0
    if (ctx->r14 == 0) {
        // 0x8008B9D0: addu        $t8, $s4, $t7
        ctx->r24 = ADD32(ctx->r20, ctx->r15);
            goto L_8008B9E0;
    }
    // 0x8008B9D0: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x8008B9D4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8008B9D8: nop

    // 0x8008B9DC: or          $v0, $v0, $t9
    ctx->r2 = ctx->r2 | ctx->r25;
L_8008B9E0:
    // 0x8008B9E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B9E4: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8008B9E8: bne         $at, $zero, L_8008B9C4
    if (ctx->r1 != 0) {
        // 0x8008B9EC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8008B9C4;
    }
    // 0x8008B9EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008B9F0: andi        $t0, $v0, 0x9000
    ctx->r8 = ctx->r2 & 0X9000;
    // 0x8008B9F4: beq         $t0, $zero, L_8008BB14
    if (ctx->r8 == 0) {
        // 0x8008B9F8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8008BB14;
    }
    // 0x8008B9F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008B9FC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8008BA00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BA04: jal         0x8006EDE8
    // 0x8008BA08: sw          $s2, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r18;
    mark_read_all_save_files(rdram, ctx);
        goto after_0;
    // 0x8008BA08: sw          $s2, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r18;
    after_0:
    // 0x8008BA0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008BA10: jal         0x800C06F8
    // 0x8008BA14: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8008BA14: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_1:
    // 0x8008BA18: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008BA1C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x8008BA20: addiu       $v0, $v0, 0x6D78
    ctx->r2 = ADD32(ctx->r2, 0X6D78);
    // 0x8008BA24: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8008BA28:
    // 0x8008BA28: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8008BA2C: nop

    // 0x8008BA30: andi        $t2, $t1, 0x9000
    ctx->r10 = ctx->r9 & 0X9000;
    // 0x8008BA34: beq         $t2, $zero, L_8008BA40
    if (ctx->r10 == 0) {
        // 0x8008BA38: nop
    
            goto L_8008BA40;
    }
    // 0x8008BA38: nop

    // 0x8008BA3C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_8008BA40:
    // 0x8008BA40: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008BA44: slti        $t3, $s0, 0x4
    ctx->r11 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8008BA48: slti        $t4, $s1, 0x0
    ctx->r12 = SIGNED(ctx->r17) < 0X0 ? 1 : 0;
    // 0x8008BA4C: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x8008BA50: bne         $t5, $zero, L_8008BA28
    if (ctx->r13 != 0) {
        // 0x8008BA54: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8008BA28;
    }
    // 0x8008BA54: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008BA58: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008BA5C: addiu       $s7, $s7, 0x6DA8
    ctx->r23 = ADD32(ctx->r23, 0X6DA8);
    // 0x8008BA60: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8008BA64: addu        $s0, $s7, $t6
    ctx->r16 = ADD32(ctx->r23, ctx->r14);
    // 0x8008BA68: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008BA6C: nop

    // 0x8008BA70: beq         $a0, $zero, L_8008BA80
    if (ctx->r4 == 0) {
        // 0x8008BA74: nop
    
            goto L_8008BA80;
    }
    // 0x8008BA74: nop

    // 0x8008BA78: jal         0x8000488C
    // 0x8008BA7C: nop

    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x8008BA7C: nop

    after_2:
L_8008BA80:
    // 0x8008BA80: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008BA84: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x8008BA88: lb          $t8, 0x6988($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X6988);
    // 0x8008BA8C: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008BA90: addiu       $fp, $fp, 0x696C
    ctx->r30 = ADD32(ctx->r30, 0X696C);
    // 0x8008BA94: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8008BA98: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x8008BA9C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8008BAA0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8008BAA4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8008BAA8: lh          $a0, 0xC($t0)
    ctx->r4 = MEM_H(ctx->r8, 0XC);
    // 0x8008BAAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8008BAB0: addiu       $a0, $a0, 0x19E
    ctx->r4 = ADD32(ctx->r4, 0X19E);
    // 0x8008BAB4: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x8008BAB8: jal         0x80001D04
    // 0x8008BABC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008BABC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
    // 0x8008BAC0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008BAC4: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8008BAC8: nop

    // 0x8008BACC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8008BAD0: beq         $at, $zero, L_8008BB04
    if (ctx->r1 == 0) {
        // 0x8008BAD4: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8008BB04;
    }
    // 0x8008BAD4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8008BAD8: bne         $at, $zero, L_8008BAF0
    if (ctx->r1 != 0) {
        // 0x8008BADC: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_8008BAF0;
    }
    // 0x8008BADC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008BAE0: lw          $t2, 0x318($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X318);
    // 0x8008BAE4: nop

    // 0x8008BAE8: sll         $t3, $t2, 7
    ctx->r11 = S32(ctx->r10 << 7);
    // 0x8008BAEC: bgez        $t3, L_8008BB04
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8008BAF0: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8008BB04;
    }
L_8008BAF0:
    // 0x8008BAF0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008BAF4: lw          $t4, 0x550($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X550);
    // 0x8008BAF8: nop

    // 0x8008BAFC: bne         $s2, $t4, L_8008BBE4
    if (ctx->r18 != ctx->r12) {
        // 0x8008BB00: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8008BBE4;
    }
    // 0x8008BB00: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8008BB04:
    // 0x8008BB04: jal         0x80000C98
    // 0x8008BB08: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_4;
    // 0x8008BB08: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_4:
    // 0x8008BB0C: b           L_8008BBE4
    // 0x8008BB10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8008BBE4;
    // 0x8008BB10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8008BB14:
    // 0x8008BB14: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008BB18: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008BB1C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008BB20: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008BB24: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008BB28: addiu       $s3, $s3, -0x600
    ctx->r19 = ADD32(ctx->r19, -0X600);
    // 0x8008BB2C: addiu       $s5, $s5, 0x697C
    ctx->r21 = ADD32(ctx->r21, 0X697C);
    // 0x8008BB30: addiu       $s7, $s7, 0x6DA8
    ctx->r23 = ADD32(ctx->r23, 0X6DA8);
    // 0x8008BB34: addiu       $fp, $fp, 0x696C
    ctx->r30 = ADD32(ctx->r30, 0X696C);
    // 0x8008BB38: addiu       $s1, $s1, 0x6974
    ctx->r17 = ADD32(ctx->r17, 0X6974);
    // 0x8008BB3C: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_8008BB40:
    // 0x8008BB40: lb          $t5, 0x0($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X0);
    // 0x8008BB44: addu        $v1, $s5, $s0
    ctx->r3 = ADD32(ctx->r21, ctx->r16);
    // 0x8008BB48: beq         $t5, $zero, L_8008BBD4
    if (ctx->r13 == 0) {
        // 0x8008BB4C: nop
    
            goto L_8008BBD4;
    }
    // 0x8008BB4C: nop

    // 0x8008BB50: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x8008BB54: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8008BB58: beq         $t6, $zero, L_8008BBD4
    if (ctx->r14 == 0) {
        // 0x8008BB5C: addu        $t8, $s4, $v0
        ctx->r24 = ADD32(ctx->r20, ctx->r2);
            goto L_8008BBD4;
    }
    // 0x8008BB5C: addu        $t8, $s4, $v0
    ctx->r24 = ADD32(ctx->r20, ctx->r2);
    // 0x8008BB60: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8008BB64: addu        $a1, $s7, $v0
    ctx->r5 = ADD32(ctx->r23, ctx->r2);
    // 0x8008BB68: andi        $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 & 0X4000;
    // 0x8008BB6C: beq         $t9, $zero, L_8008BBD4
    if (ctx->r25 == 0) {
        // 0x8008BB70: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8008BBD4;
    }
    // 0x8008BB70: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008BB74: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8008BB78: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8008BB7C: addiu       $t2, $t2, 0x6988
    ctx->r10 = ADD32(ctx->r10, 0X6988);
    // 0x8008BB80: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8008BB84: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8008BB88: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x8008BB8C: beq         $a0, $zero, L_8008BBA4
    if (ctx->r4 == 0) {
        // 0x8008BB90: addu        $s2, $s0, $t2
        ctx->r18 = ADD32(ctx->r16, ctx->r10);
            goto L_8008BBA4;
    }
    // 0x8008BB90: addu        $s2, $s0, $t2
    ctx->r18 = ADD32(ctx->r16, ctx->r10);
    // 0x8008BB94: jal         0x8000488C
    // 0x8008BB98: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_5;
    // 0x8008BB98: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_5:
    // 0x8008BB9C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8008BBA0: nop

L_8008BBA4:
    // 0x8008BBA4: lb          $t4, 0x0($s2)
    ctx->r12 = MEM_B(ctx->r18, 0X0);
    // 0x8008BBA8: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x8008BBAC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8008BBB0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008BBB4: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8008BBB8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8008BBBC: lh          $a0, 0xC($t6)
    ctx->r4 = MEM_H(ctx->r14, 0XC);
    // 0x8008BBC0: nop

    // 0x8008BBC4: addiu       $a0, $a0, 0x93
    ctx->r4 = ADD32(ctx->r4, 0X93);
    // 0x8008BBC8: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x8008BBCC: jal         0x80001D04
    // 0x8008BBD0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008BBD0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_6:
L_8008BBD4:
    // 0x8008BBD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008BBD8: bne         $s0, $s6, L_8008BB40
    if (ctx->r16 != ctx->r22) {
        // 0x8008BBDC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8008BB40;
    }
    // 0x8008BBDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008BBE0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8008BBE4:
    // 0x8008BBE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008BBE8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BBEC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008BBF0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008BBF4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008BBF8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008BBFC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008BC00: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008BC04: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8008BC08: jr          $ra
    // 0x8008BC0C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8008BC0C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void charselect_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BC10: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008BC14: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8008BC18: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8008BC1C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8008BC20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008BC24: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8008BC28: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8008BC2C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008BC30: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008BC34: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008BC38: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x8008BC3C: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008BC40: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8008BC44: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8008BC48: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8008BC4C: addiu       $fp, $fp, 0x696C
    ctx->r30 = ADD32(ctx->r30, 0X696C);
    // 0x8008BC50: addiu       $s7, $s7, -0x600
    ctx->r23 = ADD32(ctx->r23, -0X600);
    // 0x8008BC54: addiu       $s6, $s6, 0x6988
    ctx->r22 = ADD32(ctx->r22, 0X6988);
    // 0x8008BC58: addiu       $s0, $s0, 0x6960
    ctx->r16 = ADD32(ctx->r16, 0X6960);
    // 0x8008BC5C: addiu       $s3, $zero, 0xE
    ctx->r19 = ADD32(0, 0XE);
    // 0x8008BC60: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8008BC64: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
    // 0x8008BC68: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8008BC6C:
    // 0x8008BC6C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8008BC70: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8008BC74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008BC78: beq         $t6, $zero, L_8008BFB0
    if (ctx->r14 == 0) {
        // 0x8008BC7C: addiu       $t7, $t7, 0x697C
        ctx->r15 = ADD32(ctx->r15, 0X697C);
            goto L_8008BFB0;
    }
    // 0x8008BC7C: addiu       $t7, $t7, 0x697C
    ctx->r15 = ADD32(ctx->r15, 0X697C);
    // 0x8008BC80: addu        $a1, $s4, $t7
    ctx->r5 = ADD32(ctx->r20, ctx->r15);
    // 0x8008BC84: lb          $t9, 0x0($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X0);
    // 0x8008BC88: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008BC8C: addiu       $t8, $t8, 0x6D78
    ctx->r24 = ADD32(ctx->r24, 0X6D78);
    // 0x8008BC90: sll         $a2, $s4, 2
    ctx->r6 = S32(ctx->r20 << 2);
    // 0x8008BC94: beq         $t9, $zero, L_8008BD10
    if (ctx->r25 == 0) {
        // 0x8008BC98: addu        $v0, $a2, $t8
        ctx->r2 = ADD32(ctx->r6, ctx->r24);
            goto L_8008BD10;
    }
    // 0x8008BC98: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x8008BC9C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8008BCA0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008BCA4: andi        $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 & 0X4000;
    // 0x8008BCA8: beq         $t1, $zero, L_8008BFB0
    if (ctx->r9 == 0) {
        // 0x8008BCAC: addiu       $t4, $t4, 0x6DA8
        ctx->r12 = ADD32(ctx->r12, 0X6DA8);
            goto L_8008BFB0;
    }
    // 0x8008BCAC: addiu       $t4, $t4, 0x6DA8
    ctx->r12 = ADD32(ctx->r12, 0X6DA8);
    // 0x8008BCB0: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x8008BCB4: addu        $s1, $a2, $t4
    ctx->r17 = ADD32(ctx->r6, ctx->r12);
    // 0x8008BCB8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008BCBC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8008BCC0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8008BCC4: sw          $t3, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r11;
    // 0x8008BCC8: beq         $a0, $zero, L_8008BCD8
    if (ctx->r4 == 0) {
        // 0x8008BCCC: addu        $s2, $s6, $s4
        ctx->r18 = ADD32(ctx->r22, ctx->r20);
            goto L_8008BCD8;
    }
    // 0x8008BCCC: addu        $s2, $s6, $s4
    ctx->r18 = ADD32(ctx->r22, ctx->r20);
    // 0x8008BCD0: jal         0x8000488C
    // 0x8008BCD4: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x8008BCD4: nop

    after_0:
L_8008BCD8:
    // 0x8008BCD8: lb          $t6, 0x0($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X0);
    // 0x8008BCDC: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x8008BCE0: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BCE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008BCE8: mflo        $t7
    ctx->r15 = lo;
    // 0x8008BCEC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8008BCF0: lh          $a0, 0xC($t8)
    ctx->r4 = MEM_H(ctx->r24, 0XC);
    // 0x8008BCF4: nop

    // 0x8008BCF8: addiu       $a0, $a0, 0x93
    ctx->r4 = ADD32(ctx->r4, 0X93);
    // 0x8008BCFC: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x8008BD00: jal         0x80001D04
    // 0x8008BD04: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8008BD04: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x8008BD08: b           L_8008BFB4
    // 0x8008BD0C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
        goto L_8008BFB4;
    // 0x8008BD0C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8008BD10:
    // 0x8008BD10: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8008BD14: addu        $s2, $s6, $s4
    ctx->r18 = ADD32(ctx->r22, ctx->r20);
    // 0x8008BD18: andi        $t0, $v1, 0x4000
    ctx->r8 = ctx->r3 & 0X4000;
    // 0x8008BD1C: beq         $t0, $zero, L_8008BE10
    if (ctx->r8 == 0) {
        // 0x8008BD20: andi        $t8, $v1, 0x9000
        ctx->r24 = ctx->r3 & 0X9000;
            goto L_8008BE10;
    }
    // 0x8008BD20: andi        $t8, $v1, 0x9000
    ctx->r24 = ctx->r3 & 0X9000;
    // 0x8008BD24: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008BD28: lw          $t1, -0x5C4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5C4);
    // 0x8008BD2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BD30: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8008BD34: sw          $t2, -0x5C4($at)
    MEM_W(-0X5C4, ctx->r1) = ctx->r10;
    // 0x8008BD38: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008BD3C: lw          $a2, -0x5C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5C4);
    // 0x8008BD40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008BD44: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x8008BD48: blez        $a2, L_8008BDE4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008BD4C: sb          $zero, 0x6974($at)
        MEM_B(0X6974, ctx->r1) = 0;
            goto L_8008BDE4;
    }
    // 0x8008BD4C: sb          $zero, 0x6974($at)
    MEM_B(0X6974, ctx->r1) = 0;
    // 0x8008BD50: lb          $t4, 0x0($s2)
    ctx->r12 = MEM_B(ctx->r18, 0X0);
    // 0x8008BD54: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BD58: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BD5C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008BD60: lb          $t3, 0x6954($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X6954);
    // 0x8008BD64: mflo        $t6
    ctx->r14 = lo;
    // 0x8008BD68: addu        $t5, $a1, $t6
    ctx->r13 = ADD32(ctx->r5, ctx->r14);
    // 0x8008BD6C: lh          $t7, 0xC($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XC);
    // 0x8008BD70: nop

    // 0x8008BD74: bne         $t3, $t7, L_8008BDE8
    if (ctx->r11 != ctx->r15) {
        // 0x8008BD78: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_8008BDE8;
    }
    // 0x8008BD78: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8008BD7C: lb          $t8, 0x1($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1);
    // 0x8008BD80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008BD84: bgtz        $t8, L_8008BDE4
    if (SIGNED(ctx->r24) > 0) {
        // 0x8008BD88: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8008BDE4;
    }
    // 0x8008BD88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008BD8C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008BD90: addiu       $t9, $t9, 0x6974
    ctx->r25 = ADD32(ctx->r25, 0X6974);
    // 0x8008BD94: addu        $v0, $zero, $t9
    ctx->r2 = ADD32(0, ctx->r25);
L_8008BD98:
    // 0x8008BD98: lb          $t0, 0x0($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X0);
    // 0x8008BD9C: addu        $t1, $s6, $v1
    ctx->r9 = ADD32(ctx->r22, ctx->r3);
    // 0x8008BDA0: beq         $t0, $zero, L_8008BDCC
    if (ctx->r8 == 0) {
        // 0x8008BDA4: nop
    
            goto L_8008BDCC;
    }
    // 0x8008BDA4: nop

    // 0x8008BDA8: lb          $t2, 0x0($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X0);
    // 0x8008BDAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008BDB0: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BDB4: mflo        $t4
    ctx->r12 = lo;
    // 0x8008BDB8: addu        $t6, $a1, $t4
    ctx->r14 = ADD32(ctx->r5, ctx->r12);
    // 0x8008BDBC: lh          $t5, 0xC($t6)
    ctx->r13 = MEM_H(ctx->r14, 0XC);
    // 0x8008BDC0: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8008BDC4: sb          $s5, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r21;
    // 0x8008BDC8: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
L_8008BDCC:
    // 0x8008BDCC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008BDD0: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8008BDD4: beq         $at, $zero, L_8008BDE4
    if (ctx->r1 == 0) {
        // 0x8008BDD8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008BDE4;
    }
    // 0x8008BDD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008BDDC: beq         $a0, $zero, L_8008BD98
    if (ctx->r4 == 0) {
        // 0x8008BDE0: nop
    
            goto L_8008BD98;
    }
    // 0x8008BDE0: nop

L_8008BDE4:
    // 0x8008BDE4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_8008BDE8:
    // 0x8008BDE8: bgtz        $a2, L_8008BFB0
    if (SIGNED(ctx->r6) > 0) {
        // 0x8008BDEC: sb          $t3, 0x0($s2)
        MEM_B(0X0, ctx->r18) = ctx->r11;
            goto L_8008BFB0;
    }
    // 0x8008BDEC: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
    // 0x8008BDF0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008BDF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BDF8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008BDFC: sw          $t7, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r15;
    // 0x8008BE00: jal         0x800C06F8
    // 0x8008BE04: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8008BE04: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_2:
    // 0x8008BE08: b           L_8008BFB4
    // 0x8008BE0C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
        goto L_8008BFB4;
    // 0x8008BE0C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8008BE10:
    // 0x8008BE10: beq         $t8, $zero, L_8008BE7C
    if (ctx->r24 == 0) {
        // 0x8008BE14: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008BE7C;
    }
    // 0x8008BE14: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008BE18: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008BE1C: addiu       $t2, $t2, 0x6DA8
    ctx->r10 = ADD32(ctx->r10, 0X6DA8);
    // 0x8008BE20: lw          $t0, 0x0($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X0);
    // 0x8008BE24: addu        $s1, $a2, $t2
    ctx->r17 = ADD32(ctx->r6, ctx->r10);
    // 0x8008BE28: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008BE2C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008BE30: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
    // 0x8008BE34: beq         $a0, $zero, L_8008BE44
    if (ctx->r4 == 0) {
        // 0x8008BE38: sw          $t1, 0x0($s7)
        MEM_W(0X0, ctx->r23) = ctx->r9;
            goto L_8008BE44;
    }
    // 0x8008BE38: sw          $t1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r9;
    // 0x8008BE3C: jal         0x8000488C
    // 0x8008BE40: nop

    sndp_stop(rdram, ctx);
        goto after_3;
    // 0x8008BE40: nop

    after_3:
L_8008BE44:
    // 0x8008BE44: lb          $t6, 0x0($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X0);
    // 0x8008BE48: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x8008BE4C: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BE50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008BE54: mflo        $t5
    ctx->r13 = lo;
    // 0x8008BE58: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x8008BE5C: lh          $a0, 0xC($t3)
    ctx->r4 = MEM_H(ctx->r11, 0XC);
    // 0x8008BE60: nop

    // 0x8008BE64: addiu       $a0, $a0, 0x87
    ctx->r4 = ADD32(ctx->r4, 0X87);
    // 0x8008BE68: andi        $t7, $a0, 0xFFFF
    ctx->r15 = ctx->r4 & 0XFFFF;
    // 0x8008BE6C: jal         0x80001D04
    // 0x8008BE70: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008BE70: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x8008BE74: b           L_8008BFB4
    // 0x8008BE78: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
        goto L_8008BFB4;
    // 0x8008BE78: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8008BE7C:
    // 0x8008BE7C: lb          $t8, 0x0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X0);
    // 0x8008BE80: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x8008BE84: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BE88: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008BE8C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8008BE90: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BE94: lh          $a0, 0x6DD0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6DD0);
    // 0x8008BE98: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8008BE9C: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    // 0x8008BEA0: addiu       $t9, $zero, 0x15C
    ctx->r25 = ADD32(0, 0X15C);
    // 0x8008BEA4: mflo        $v0
    ctx->r2 = lo;
    // 0x8008BEA8: addu        $s1, $v0, $a1
    ctx->r17 = ADD32(ctx->r2, ctx->r5);
    // 0x8008BEAC: blez        $a0, L_8008BEDC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8008BEB0: nop
    
            goto L_8008BEDC;
    }
    // 0x8008BEB0: nop

    // 0x8008BEB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008BEB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008BEBC: jal         0x8008C4A0
    // 0x8008BEC0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    charselect_move(rdram, ctx);
        goto after_5;
    // 0x8008BEC0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_5:
    // 0x8008BEC4: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8008BEC8: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BECC: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x8008BED0: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x8008BED4: b           L_8008BF8C
    // 0x8008BED8: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
        goto L_8008BF8C;
    // 0x8008BED8: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
L_8008BEDC:
    // 0x8008BEDC: bgez        $a0, L_8008BF14
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8008BEE0: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_8008BF14;
    }
    // 0x8008BEE0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8008BEE4: addiu       $t1, $zero, 0x15C
    ctx->r9 = ADD32(0, 0X15C);
    // 0x8008BEE8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008BEEC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008BEF0: addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    // 0x8008BEF4: jal         0x8008C4A0
    // 0x8008BEF8: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    charselect_move(rdram, ctx);
        goto after_6;
    // 0x8008BEF8: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    after_6:
    // 0x8008BEFC: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8008BF00: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BF04: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x8008BF08: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x8008BF0C: b           L_8008BF8C
    // 0x8008BF10: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
        goto L_8008BF8C;
    // 0x8008BF10: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
L_8008BF14:
    // 0x8008BF14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008BF18: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8008BF1C: lh          $a0, 0x6DB8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6DB8);
    // 0x8008BF20: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8008BF24: bgez        $a0, L_8008BF58
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8008BF28: addiu       $a3, $zero, 0xEC
        ctx->r7 = ADD32(0, 0XEC);
            goto L_8008BF58;
    }
    // 0x8008BF28: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    // 0x8008BF2C: addiu       $t6, $zero, 0x15C
    ctx->r14 = ADD32(0, 0X15C);
    // 0x8008BF30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008BF34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008BF38: jal         0x8008C4A0
    // 0x8008BF3C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    charselect_move(rdram, ctx);
        goto after_7;
    // 0x8008BF3C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_7:
    // 0x8008BF40: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8008BF44: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BF48: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x8008BF4C: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8008BF50: b           L_8008BF8C
    // 0x8008BF54: sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12 << 1);
        goto L_8008BF8C;
    // 0x8008BF54: sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12 << 1);
L_8008BF58:
    // 0x8008BF58: blez        $a0, L_8008BF8C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8008BF5C: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_8008BF8C;
    }
    // 0x8008BF5C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8008BF60: addiu       $t5, $zero, 0x15C
    ctx->r13 = ADD32(0, 0X15C);
    // 0x8008BF64: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008BF68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008BF6C: addiu       $a1, $s1, 0x8
    ctx->r5 = ADD32(ctx->r17, 0X8);
    // 0x8008BF70: jal         0x8008C4A0
    // 0x8008BF74: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    charselect_move(rdram, ctx);
        goto after_8;
    // 0x8008BF74: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    after_8:
    // 0x8008BF78: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8008BF7C: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BF80: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x8008BF84: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x8008BF88: sll         $v0, $t3, 1
    ctx->r2 = S32(ctx->r11 << 1);
L_8008BF8C:
    // 0x8008BF8C: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x8008BF90: lh          $v1, 0xC($t7)
    ctx->r3 = MEM_H(ctx->r15, 0XC);
    // 0x8008BF94: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
    // 0x8008BF98: nop

    // 0x8008BF9C: beq         $t8, $v1, L_8008BFB4
    if (ctx->r24 == ctx->r3) {
        // 0x8008BFA0: lw          $v0, 0x4C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X4C);
            goto L_8008BFB4;
    }
    // 0x8008BFA0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8008BFA4: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x8008BFA8: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8008BFAC: sb          $s5, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r21;
L_8008BFB0:
    // 0x8008BFB0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8008BFB4:
    // 0x8008BFB4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8008BFB8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008BFBC: bne         $s4, $at, L_8008BC6C
    if (ctx->r20 != ctx->r1) {
        // 0x8008BFC0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008BC6C;
    }
    // 0x8008BFC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008BFC4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8008BFC8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008BFCC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8008BFD0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008BFD4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8008BFD8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008BFDC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8008BFE0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008BFE4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8008BFE8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8008BFEC: jr          $ra
    // 0x8008BFF0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8008BFF0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void charselect_assign_ai(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BFF4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008BFF8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008BFFC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008C000: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008C004: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008C008: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008C00C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008C010: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008C014: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008C018: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008C01C: jal         0x8009F214
    // 0x8008C020: addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    is_drumstick_unlocked(rdram, ctx);
        goto after_0;
    // 0x8008C020: addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    after_0:
    // 0x8008C024: beq         $v0, $zero, L_8008C030
    if (ctx->r2 == 0) {
        // 0x8008C028: nop
    
            goto L_8008C030;
    }
    // 0x8008C028: nop

    // 0x8008C02C: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
L_8008C030:
    // 0x8008C030: jal         0x8009F1FC
    // 0x8008C034: nop

    is_tt_unlocked(rdram, ctx);
        goto after_1;
    // 0x8008C034: nop

    after_1:
    // 0x8008C038: beq         $v0, $zero, L_8008C044
    if (ctx->r2 == 0) {
        // 0x8008C03C: slti        $at, $s0, 0x8
        ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
            goto L_8008C044;
    }
    // 0x8008C03C: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8008C040: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_8008C044:
    // 0x8008C044: beq         $at, $zero, L_8008C0A4
    if (ctx->r1 == 0) {
        // 0x8008C048: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8008C0A4;
    }
    // 0x8008C048: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008C04C: blez        $s0, L_8008C08C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008C050: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8008C08C;
    }
    // 0x8008C050: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008C054: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008C058: addiu       $t6, $t6, 0x6990
    ctx->r14 = ADD32(ctx->r14, 0X6990);
    // 0x8008C05C: addu        $s3, $zero, $t6
    ctx->r19 = ADD32(0, ctx->r14);
    // 0x8008C060: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x8008C064: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_8008C068:
    // 0x8008C068: lb          $t7, 0x0($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X0);
    // 0x8008C06C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8008C070: bne         $v1, $t7, L_8008C07C
    if (ctx->r3 != ctx->r15) {
        // 0x8008C074: sltu        $at, $s3, $v0
        ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
            goto L_8008C07C;
    }
    // 0x8008C074: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x8008C078: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008C07C:
    // 0x8008C07C: beq         $at, $zero, L_8008C08C
    if (ctx->r1 == 0) {
        // 0x8008C080: nop
    
            goto L_8008C08C;
    }
    // 0x8008C080: nop

    // 0x8008C084: beq         $s1, $zero, L_8008C068
    if (ctx->r17 == 0) {
        // 0x8008C088: nop
    
            goto L_8008C068;
    }
    // 0x8008C088: nop

L_8008C08C:
    // 0x8008C08C: bne         $s1, $zero, L_8008C0A4
    if (ctx->r17 != 0) {
        // 0x8008C090: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_8008C0A4;
    }
    // 0x8008C090: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x8008C094: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C098: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008C09C: sb          $v1, 0x6990($at)
    MEM_B(0X6990, ctx->r1) = ctx->r3;
    // 0x8008C0A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8008C0A4:
    // 0x8008C0A4: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8008C0A8: beq         $at, $zero, L_8008C1B4
    if (ctx->r1 == 0) {
        // 0x8008C0AC: or          $s2, $s0, $zero
        ctx->r18 = ctx->r16 | 0;
            goto L_8008C1B4;
    }
    // 0x8008C0AC: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x8008C0B0: addiu       $t8, $t8, 0x6990
    ctx->r24 = ADD32(ctx->r24, 0X6990);
    // 0x8008C0B4: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008C0B8: addiu       $s4, $s4, 0x696C
    ctx->r20 = ADD32(ctx->r20, 0X696C);
    // 0x8008C0BC: addu        $s3, $s0, $t8
    ctx->r19 = ADD32(ctx->r16, ctx->r24);
    // 0x8008C0C0: addiu       $s5, $zero, 0xE
    ctx->r21 = ADD32(0, 0XE);
L_8008C0C4:
    // 0x8008C0C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8008C0C8:
    // 0x8008C0C8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8008C0CC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008C0D0: jal         0x8006FB8C
    // 0x8008C0D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    rand_range(rdram, ctx);
        goto after_2;
    // 0x8008C0D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_2:
    // 0x8008C0D8: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008C0DC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8008C0E0: andi        $a1, $s2, 0x3
    ctx->r5 = ctx->r18 & 0X3;
    // 0x8008C0E4: mflo        $t0
    ctx->r8 = lo;
    // 0x8008C0E8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8008C0EC: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x8008C0F0: blez        $s2, L_8008C19C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8008C0F4: sb          $t2, 0x0($s3)
        MEM_B(0X0, ctx->r19) = ctx->r10;
            goto L_8008C19C;
    }
    // 0x8008C0F4: sb          $t2, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r10;
    // 0x8008C0F8: beq         $a1, $zero, L_8008C130
    if (ctx->r5 == 0) {
        // 0x8008C0FC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8008C130;
    }
    // 0x8008C0FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8008C100: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008C104: addiu       $t3, $t3, 0x6990
    ctx->r11 = ADD32(ctx->r11, 0X6990);
    // 0x8008C108: lb          $v1, 0x0($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X0);
    // 0x8008C10C: addu        $v0, $s0, $t3
    ctx->r2 = ADD32(ctx->r16, ctx->r11);
L_8008C110:
    // 0x8008C110: lb          $t4, 0x0($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X0);
    // 0x8008C114: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008C118: bne         $t4, $v1, L_8008C124
    if (ctx->r12 != ctx->r3) {
        // 0x8008C11C: nop
    
            goto L_8008C124;
    }
    // 0x8008C11C: nop

    // 0x8008C120: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008C124:
    // 0x8008C124: bne         $a0, $s0, L_8008C110
    if (ctx->r4 != ctx->r16) {
        // 0x8008C128: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008C110;
    }
    // 0x8008C128: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008C12C: beq         $s0, $s2, L_8008C19C
    if (ctx->r16 == ctx->r18) {
        // 0x8008C130: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8008C19C;
    }
L_8008C130:
    // 0x8008C130: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008C134: addiu       $t5, $t5, 0x6990
    ctx->r13 = ADD32(ctx->r13, 0X6990);
    // 0x8008C138: lb          $v1, 0x0($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X0);
    // 0x8008C13C: addu        $v0, $s0, $t5
    ctx->r2 = ADD32(ctx->r16, ctx->r13);
    // 0x8008C140: addu        $a0, $s2, $t5
    ctx->r4 = ADD32(ctx->r18, ctx->r13);
L_8008C144:
    // 0x8008C144: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8008C148: nop

    // 0x8008C14C: bne         $t6, $v1, L_8008C158
    if (ctx->r14 != ctx->r3) {
        // 0x8008C150: nop
    
            goto L_8008C158;
    }
    // 0x8008C150: nop

    // 0x8008C154: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008C158:
    // 0x8008C158: lb          $t7, 0x1($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1);
    // 0x8008C15C: nop

    // 0x8008C160: bne         $t7, $v1, L_8008C16C
    if (ctx->r15 != ctx->r3) {
        // 0x8008C164: nop
    
            goto L_8008C16C;
    }
    // 0x8008C164: nop

    // 0x8008C168: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008C16C:
    // 0x8008C16C: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
    // 0x8008C170: nop

    // 0x8008C174: bne         $t8, $v1, L_8008C180
    if (ctx->r24 != ctx->r3) {
        // 0x8008C178: nop
    
            goto L_8008C180;
    }
    // 0x8008C178: nop

    // 0x8008C17C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008C180:
    // 0x8008C180: lb          $t9, 0x3($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3);
    // 0x8008C184: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008C188: bne         $t9, $v1, L_8008C194
    if (ctx->r25 != ctx->r3) {
        // 0x8008C18C: nop
    
            goto L_8008C194;
    }
    // 0x8008C18C: nop

    // 0x8008C190: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008C194:
    // 0x8008C194: bne         $v0, $a0, L_8008C144
    if (ctx->r2 != ctx->r4) {
        // 0x8008C198: nop
    
            goto L_8008C144;
    }
    // 0x8008C198: nop

L_8008C19C:
    // 0x8008C19C: bne         $s1, $zero, L_8008C0C8
    if (ctx->r17 != 0) {
        // 0x8008C1A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008C0C8;
    }
    // 0x8008C1A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008C1A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008C1A8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8008C1AC: bne         $s2, $at, L_8008C0C4
    if (ctx->r18 != ctx->r1) {
        // 0x8008C1B0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8008C0C4;
    }
    // 0x8008C1B0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8008C1B4:
    // 0x8008C1B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8008C1B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008C1BC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C1C0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008C1C4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008C1C8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008C1CC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008C1D0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008C1D4: jr          $ra
    // 0x8008C1D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8008C1D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void menu_character_select_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C1DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008C1E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C1E4: jal         0x8008B6C4
    // 0x8008C1E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    charselect_render_text(rdram, ctx);
        goto after_0;
    // 0x8008C1E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008C1EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008C1F0: jal         0x8008C620
    // 0x8008C1F4: nop

    charselect_music_channels(rdram, ctx);
        goto after_1;
    // 0x8008C1F4: nop

    after_1:
    // 0x8008C1F8: jal         0x8008E9A4
    // 0x8008C1FC: nop

    menu_input(rdram, ctx);
        goto after_2;
    // 0x8008C1FC: nop

    after_2:
    // 0x8008C200: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008C204: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008C208: addiu       $a0, $a0, 0x6980
    ctx->r4 = ADD32(ctx->r4, 0X6980);
    // 0x8008C20C: addiu       $v0, $v0, 0x697C
    ctx->r2 = ADD32(ctx->r2, 0X697C);
    // 0x8008C210: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008C214: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8008C218:
    // 0x8008C218: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8008C21C: nop

    // 0x8008C220: bne         $t2, $t6, L_8008C22C
    if (ctx->r10 != ctx->r14) {
        // 0x8008C224: nop
    
            goto L_8008C22C;
    }
    // 0x8008C224: nop

    // 0x8008C228: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8008C22C:
    // 0x8008C22C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008C230: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8008C234: bne         $at, $zero, L_8008C218
    if (ctx->r1 != 0) {
        // 0x8008C238: nop
    
            goto L_8008C218;
    }
    // 0x8008C238: nop

    // 0x8008C23C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008C240: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C244: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
    // 0x8008C248: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x8008C24C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008C250: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008C254: bne         $v0, $zero, L_8008C2C4
    if (ctx->r2 != 0) {
        // 0x8008C258: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8008C2C4;
    }
    // 0x8008C258: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008C25C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008C260: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008C264: lb          $t4, 0x6977($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X6977);
    // 0x8008C268: lb          $t9, 0x6976($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X6976);
    // 0x8008C26C: lb          $t7, 0x6974($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6974);
    // 0x8008C270: lb          $t8, 0x6975($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X6975);
    // 0x8008C274: sb          $t4, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r12;
    // 0x8008C278: sb          $t9, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r25;
    // 0x8008C27C: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x8008C280: jal         0x8008B810
    // 0x8008C284: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    charselect_new_player(rdram, ctx);
        goto after_3;
    // 0x8008C284: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    after_3:
    // 0x8008C288: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008C28C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008C290: lw          $t6, -0x600($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X600);
    // 0x8008C294: lw          $t5, -0x5C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5C4);
    // 0x8008C298: nop

    // 0x8008C29C: bne         $t5, $t6, L_8008C2B4
    if (ctx->r13 != ctx->r14) {
        // 0x8008C2A0: nop
    
            goto L_8008C2B4;
    }
    // 0x8008C2A0: nop

    // 0x8008C2A4: jal         0x8008B980
    // 0x8008C2A8: nop

    charselect_pick(rdram, ctx);
        goto after_4;
    // 0x8008C2A8: nop

    after_4:
    // 0x8008C2AC: b           L_8008C490
    // 0x8008C2B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C490;
    // 0x8008C2B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C2B4:
    // 0x8008C2B4: jal         0x8008BC10
    // 0x8008C2B8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    charselect_input(rdram, ctx);
        goto after_5;
    // 0x8008C2B8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x8008C2BC: b           L_8008C490
    // 0x8008C2C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C490;
    // 0x8008C2C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C2C4:
    // 0x8008C2C4: blez        $v0, L_8008C448
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008C2C8: nop
    
            goto L_8008C448;
    }
    // 0x8008C2C8: nop

    // 0x8008C2CC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8008C2D0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008C2D4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8008C2D8: slti        $at, $t8, 0x1F
    ctx->r1 = SIGNED(ctx->r24) < 0X1F ? 1 : 0;
    // 0x8008C2DC: bne         $at, $zero, L_8008C48C
    if (ctx->r1 != 0) {
        // 0x8008C2E0: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008C48C;
    }
    // 0x8008C2E0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008C2E4: lw          $t4, 0x550($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X550);
    // 0x8008C2E8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8008C2EC: bne         $t4, $zero, L_8008C30C
    if (ctx->r12 != 0) {
        // 0x8008C2F0: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8008C30C;
    }
    // 0x8008C2F0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008C2F4: lw          $t5, 0x318($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X318);
    // 0x8008C2F8: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
    // 0x8008C2FC: sll         $t6, $t5, 7
    ctx->r14 = S32(ctx->r13 << 7);
    // 0x8008C300: bgez        $t6, L_8008C30C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008C304: nop
    
            goto L_8008C30C;
    }
    // 0x8008C304: nop

    // 0x8008C308: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
L_8008C30C:
    // 0x8008C30C: jal         0x8008C5E0
    // 0x8008C310: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    charselect_free(rdram, ctx);
        goto after_6;
    // 0x8008C310: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_6:
    // 0x8008C314: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C318: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008C31C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008C320: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008C324: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008C328: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008C32C: addiu       $a1, $a1, 0x6990
    ctx->r5 = ADD32(ctx->r5, 0X6990);
    // 0x8008C330: addiu       $a2, $a2, 0x696C
    ctx->r6 = ADD32(ctx->r6, 0X696C);
    // 0x8008C334: addiu       $a3, $a3, 0x6988
    ctx->r7 = ADD32(ctx->r7, 0X6988);
    // 0x8008C338: addiu       $v1, $v1, 0x6974
    ctx->r3 = ADD32(ctx->r3, 0X6974);
    // 0x8008C33C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008C340: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8008C344: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
L_8008C348:
    // 0x8008C348: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x8008C34C: addu        $t9, $a3, $v0
    ctx->r25 = ADD32(ctx->r7, ctx->r2);
    // 0x8008C350: beq         $t7, $zero, L_8008C380
    if (ctx->r15 == 0) {
        // 0x8008C354: nop
    
            goto L_8008C380;
    }
    // 0x8008C354: nop

    // 0x8008C358: lb          $t4, 0x0($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X0);
    // 0x8008C35C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008C360: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008C364: addu        $t9, $a1, $a0
    ctx->r25 = ADD32(ctx->r5, ctx->r4);
    // 0x8008C368: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008C36C: mflo        $t5
    ctx->r13 = lo;
    // 0x8008C370: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x8008C374: lh          $t7, 0xC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XC);
    // 0x8008C378: nop

    // 0x8008C37C: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
L_8008C380:
    // 0x8008C380: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008C384: bne         $v0, $t1, L_8008C348
    if (ctx->r2 != ctx->r9) {
        // 0x8008C388: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8008C348;
    }
    // 0x8008C388: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008C38C: jal         0x8008BFF4
    // 0x8008C390: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    charselect_assign_ai(rdram, ctx);
        goto after_7;
    // 0x8008C390: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_7:
    // 0x8008C394: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008C398: jal         0x8006A698
    // 0x8008C39C: addiu       $a0, $a0, 0x6974
    ctx->r4 = ADD32(ctx->r4, 0X6974);
    charselect_assign_players(rdram, ctx);
        goto after_8;
    // 0x8008C39C: addiu       $a0, $a0, 0x6974
    ctx->r4 = ADD32(ctx->r4, 0X6974);
    after_8:
    // 0x8008C3A0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008C3A4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008C3A8: lw          $t4, -0x5C4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5C4);
    // 0x8008C3AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008C3B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C3B4: sw          $t2, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = ctx->r10;
    // 0x8008C3B8: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8008C3BC: bne         $at, $zero, L_8008C420
    if (ctx->r1 != 0) {
        // 0x8008C3C0: nop
    
            goto L_8008C420;
    }
    // 0x8008C3C0: nop

    // 0x8008C3C4: jal         0x80000B18
    // 0x8008C3C8: nop

    music_change_off(rdram, ctx);
        goto after_9;
    // 0x8008C3C8: nop

    after_9:
    // 0x8008C3CC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8008C3D0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008C3D4: jal         0x8006E528
    // 0x8008C3D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_10;
    // 0x8008C3D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8008C3DC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008C3E0: lw          $t8, -0x5C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5C4);
    // 0x8008C3E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008C3E8: bne         $t2, $t8, L_8008C410
    if (ctx->r10 != ctx->r24) {
        // 0x8008C3EC: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8008C410;
    }
    // 0x8008C3EC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008C3F0: lw          $t5, -0x5E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E8);
    // 0x8008C3F4: nop

    // 0x8008C3F8: bne         $t5, $zero, L_8008C410
    if (ctx->r13 != 0) {
        // 0x8008C3FC: nop
    
            goto L_8008C410;
    }
    // 0x8008C3FC: nop

    // 0x8008C400: jal         0x80081820
    // 0x8008C404: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    menu_init(rdram, ctx);
        goto after_11;
    // 0x8008C404: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_11:
    // 0x8008C408: b           L_8008C490
    // 0x8008C40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C490;
    // 0x8008C40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C410:
    // 0x8008C410: jal         0x80081820
    // 0x8008C414: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    menu_init(rdram, ctx);
        goto after_12;
    // 0x8008C414: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_12:
    // 0x8008C418: b           L_8008C490
    // 0x8008C41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C490;
    // 0x8008C41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C420:
    // 0x8008C420: jal         0x80000B28
    // 0x8008C424: nop

    music_change_on(rdram, ctx);
        goto after_13;
    // 0x8008C424: nop

    after_13:
    // 0x8008C428: jal         0x80082D08
    // 0x8008C42C: nop

    trackmenu_set_records(rdram, ctx);
        goto after_14;
    // 0x8008C42C: nop

    after_14:
    // 0x8008C430: jal         0x8006E7FC
    // 0x8008C434: nop

    init_racer_headers(rdram, ctx);
        goto after_15;
    // 0x8008C434: nop

    after_15:
    // 0x8008C438: jal         0x80081820
    // 0x8008C43C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    menu_init(rdram, ctx);
        goto after_16;
    // 0x8008C43C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_16:
    // 0x8008C440: b           L_8008C490
    // 0x8008C444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008C490;
    // 0x8008C444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C448:
    // 0x8008C448: bgez        $v0, L_8008C48C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008C44C: nop
    
            goto L_8008C48C;
    }
    // 0x8008C44C: nop

    // 0x8008C450: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8008C454: nop

    // 0x8008C458: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8008C45C: slti        $at, $t7, -0x1E
    ctx->r1 = SIGNED(ctx->r15) < -0X1E ? 1 : 0;
    // 0x8008C460: beq         $at, $zero, L_8008C48C
    if (ctx->r1 == 0) {
        // 0x8008C464: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_8008C48C;
    }
    // 0x8008C464: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008C468: jal         0x80000B28
    // 0x8008C46C: nop

    music_change_on(rdram, ctx);
        goto after_17;
    // 0x8008C46C: nop

    after_17:
    // 0x8008C470: jal         0x8008C5E0
    // 0x8008C474: nop

    charselect_free(rdram, ctx);
        goto after_18;
    // 0x8008C474: nop

    after_18:
    // 0x8008C478: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008C47C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C480: sw          $t2, -0x5C4($at)
    MEM_W(-0X5C4, ctx->r1) = ctx->r10;
    // 0x8008C484: jal         0x80081820
    // 0x8008C488: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    menu_init(rdram, ctx);
        goto after_19;
    // 0x8008C488: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
L_8008C48C:
    // 0x8008C48C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C490:
    // 0x8008C490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C494: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008C498: jr          $ra
    // 0x8008C49C: nop

    return;
    // 0x8008C49C: nop

;}
RECOMP_FUNC void charselect_move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C4A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008C4A4: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8008C4A8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8008C4AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8008C4B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008C4B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008C4B8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8008C4BC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8008C4C0: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8008C4C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008C4C8: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8008C4CC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8008C4D0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8008C4D4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8008C4D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008C4DC: blez        $a2, L_8008C578
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008C4E0: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8008C578;
    }
    // 0x8008C4E0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8008C4E4: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8008C4E8: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x8008C4EC: beq         $s7, $t6, L_8008C578
    if (ctx->r23 == ctx->r14) {
        // 0x8008C4F0: lui         $s5, 0x40
        ctx->r21 = S32(0X40 << 16);
            goto L_8008C578;
    }
    // 0x8008C4F0: lui         $s5, 0x40
    ctx->r21 = S32(0X40 << 16);
    // 0x8008C4F4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008C4F8: addiu       $s2, $s2, 0x6988
    ctx->r18 = ADD32(ctx->r18, 0X6988);
L_8008C4FC:
    // 0x8008C4FC: jal         0x8009C850
    // 0x8008C500: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x8008C500: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x8008C504: and         $t7, $v0, $s5
    ctx->r15 = ctx->r2 & ctx->r21;
    // 0x8008C508: bne         $t7, $zero, L_8008C558
    if (ctx->r15 != 0) {
        // 0x8008C50C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008C558;
    }
    // 0x8008C50C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C510:
    // 0x8008C510: beq         $v0, $s4, L_8008C534
    if (ctx->r2 == ctx->r20) {
        // 0x8008C514: addu        $t8, $s2, $v0
        ctx->r24 = ADD32(ctx->r18, ctx->r2);
            goto L_8008C534;
    }
    // 0x8008C514: addu        $t8, $s2, $v0
    ctx->r24 = ADD32(ctx->r18, ctx->r2);
    // 0x8008C518: addu        $t0, $s3, $s1
    ctx->r8 = ADD32(ctx->r19, ctx->r17);
    // 0x8008C51C: lb          $t1, 0x0($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X0);
    // 0x8008C520: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x8008C524: nop

    // 0x8008C528: bne         $t9, $t1, L_8008C534
    if (ctx->r25 != ctx->r9) {
        // 0x8008C52C: nop
    
            goto L_8008C534;
    }
    // 0x8008C52C: nop

    // 0x8008C530: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8008C534:
    // 0x8008C534: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008C538: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8008C53C: beq         $at, $zero, L_8008C54C
    if (ctx->r1 == 0) {
        // 0x8008C540: nop
    
            goto L_8008C54C;
    }
    // 0x8008C540: nop

    // 0x8008C544: beq         $s0, $zero, L_8008C510
    if (ctx->r16 == 0) {
        // 0x8008C548: nop
    
            goto L_8008C510;
    }
    // 0x8008C548: nop

L_8008C54C:
    // 0x8008C54C: beq         $s0, $zero, L_8008C558
    if (ctx->r16 == 0) {
        // 0x8008C550: nop
    
            goto L_8008C558;
    }
    // 0x8008C550: nop

    // 0x8008C554: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8008C558:
    // 0x8008C558: beq         $s0, $zero, L_8008C578
    if (ctx->r16 == 0) {
        // 0x8008C55C: slt         $at, $s1, $s6
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_8008C578;
    }
    // 0x8008C55C: slt         $at, $s1, $s6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8008C560: beq         $at, $zero, L_8008C578
    if (ctx->r1 == 0) {
        // 0x8008C564: addu        $t2, $s3, $s1
        ctx->r10 = ADD32(ctx->r19, ctx->r17);
            goto L_8008C578;
    }
    // 0x8008C564: addu        $t2, $s3, $s1
    ctx->r10 = ADD32(ctx->r19, ctx->r17);
    // 0x8008C568: lb          $t3, 0x0($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X0);
    // 0x8008C56C: nop

    // 0x8008C570: bne         $s7, $t3, L_8008C4FC
    if (ctx->r23 != ctx->r11) {
        // 0x8008C574: nop
    
            goto L_8008C4FC;
    }
    // 0x8008C574: nop

L_8008C578:
    // 0x8008C578: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008C57C: bne         $s0, $zero, L_8008C5A8
    if (ctx->r16 != 0) {
        // 0x8008C580: addiu       $s2, $s2, 0x6988
        ctx->r18 = ADD32(ctx->r18, 0X6988);
            goto L_8008C5A8;
    }
    // 0x8008C580: addiu       $s2, $s2, 0x6988
    ctx->r18 = ADD32(ctx->r18, 0X6988);
    // 0x8008C584: addu        $t4, $s3, $s1
    ctx->r12 = ADD32(ctx->r19, ctx->r17);
    // 0x8008C588: lb          $t5, 0x0($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X0);
    // 0x8008C58C: addu        $t6, $s2, $s4
    ctx->r14 = ADD32(ctx->r18, ctx->r20);
    // 0x8008C590: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x8008C594: lhu         $a0, 0x46($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X46);
    // 0x8008C598: jal         0x80001D04
    // 0x8008C59C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8008C59C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8008C5A0: b           L_8008C5B8
    // 0x8008C5A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8008C5B8;
    // 0x8008C5A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8008C5A8:
    // 0x8008C5A8: lhu         $a0, 0x4A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4A);
    // 0x8008C5AC: jal         0x80001D04
    // 0x8008C5B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008C5B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8008C5B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8008C5B8:
    // 0x8008C5B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008C5BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008C5C0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C5C4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8008C5C8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8008C5CC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8008C5D0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8008C5D4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8008C5D8: jr          $ra
    // 0x8008C5DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8008C5DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void charselect_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C5E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C5E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C5E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C5EC: jal         0x8009C9EC
    // 0x8008C5F0: addiu       $a0, $a0, 0x348
    ctx->r4 = ADD32(ctx->r4, 0X348);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8008C5F0: addiu       $a0, $a0, 0x348
    ctx->r4 = ADD32(ctx->r4, 0X348);
    after_0:
    // 0x8008C5F4: jal         0x800712F0
    // 0x8008C5F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_1;
    // 0x8008C5F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8008C5FC: jal         0x800C478C
    // 0x8008C600: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_2;
    // 0x8008C600: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8008C604: jal         0x800712F0
    // 0x8008C608: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_3;
    // 0x8008C608: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x8008C60C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C610: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C614: sw          $zero, 0x550($at)
    MEM_W(0X550, ctx->r1) = 0;
    // 0x8008C618: jr          $ra
    // 0x8008C61C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008C61C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void charselect_music_channels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C620: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008C624: addiu       $a1, $a1, 0x6960
    ctx->r5 = ADD32(ctx->r5, 0X6960);
    // 0x8008C628: lb          $v0, 0x1($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1);
    // 0x8008C62C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008C630: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008C634: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008C638: blez        $v0, L_8008C718
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008C63C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8008C718;
    }
    // 0x8008C63C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008C640: subu        $t7, $v0, $a0
    ctx->r15 = SUB32(ctx->r2, ctx->r4);
    // 0x8008C644: sb          $t7, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r15;
    // 0x8008C648: lb          $t8, 0x1($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X1);
    // 0x8008C64C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008C650: bgtz        $t8, L_8008C718
    if (SIGNED(ctx->r24) > 0) {
        // 0x8008C654: addiu       $s0, $s0, 0x6958
        ctx->r16 = ADD32(ctx->r16, 0X6958);
            goto L_8008C718;
    }
    // 0x8008C654: addiu       $s0, $s0, 0x6958
    ctx->r16 = ADD32(ctx->r16, 0X6958);
    // 0x8008C658: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8008C65C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C660: bltz        $v0, L_8008C69C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C664: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_8008C69C;
    }
    // 0x8008C664: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8008C668: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8008C66C: lbu         $a0, 0x334($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X334);
    // 0x8008C670: jal         0x80001114
    // 0x8008C674: nop

    music_channel_off(rdram, ctx);
        goto after_0;
    // 0x8008C674: nop

    after_0:
    // 0x8008C678: lb          $t0, 0x0($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X0);
    // 0x8008C67C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C680: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8008C684: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8008C688: lbu         $a0, 0x335($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X335);
    // 0x8008C68C: jal         0x80001114
    // 0x8008C690: nop

    music_channel_off(rdram, ctx);
        goto after_1;
    // 0x8008C690: nop

    after_1:
    // 0x8008C694: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008C698: addiu       $a1, $a1, 0x6960
    ctx->r5 = ADD32(ctx->r5, 0X6960);
L_8008C69C:
    // 0x8008C69C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C6A0: addiu       $v1, $v1, 0x6954
    ctx->r3 = ADD32(ctx->r3, 0X6954);
    // 0x8008C6A4: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8008C6A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C6AC: bltz        $v0, L_8008C6C0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C6B0: sb          $v0, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r2;
            goto L_8008C6C0;
    }
    // 0x8008C6B0: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8008C6B4: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
    // 0x8008C6B8: nop

    // 0x8008C6BC: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
L_8008C6C0:
    // 0x8008C6C0: lb          $t3, 0x0($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X0);
    // 0x8008C6C4: nop

    // 0x8008C6C8: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x8008C6CC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8008C6D0: nop

    // 0x8008C6D4: bltz        $v0, L_8008C718
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C6D8: sll         $t5, $v0, 1
        ctx->r13 = S32(ctx->r2 << 1);
            goto L_8008C718;
    }
    // 0x8008C6D8: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x8008C6DC: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8008C6E0: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8008C6E4: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
    // 0x8008C6E8: lbu         $a0, 0x334($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X334);
    // 0x8008C6EC: jal         0x80001170
    // 0x8008C6F0: nop

    music_channel_on(rdram, ctx);
        goto after_2;
    // 0x8008C6F0: nop

    after_2:
    // 0x8008C6F4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C6F8: addiu       $v1, $v1, 0x6954
    ctx->r3 = ADD32(ctx->r3, 0X6954);
    // 0x8008C6FC: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x8008C700: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C704: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8008C708: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8008C70C: lbu         $a0, 0x335($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X335);
    // 0x8008C710: jal         0x80001170
    // 0x8008C714: nop

    music_channel_on(rdram, ctx);
        goto after_3;
    // 0x8008C714: nop

    after_3:
L_8008C718:
    // 0x8008C718: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C71C: addiu       $v1, $v1, 0x6954
    ctx->r3 = ADD32(ctx->r3, 0X6954);
    // 0x8008C720: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8008C724: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008C728: bltz        $v0, L_8008C7A8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C72C: addiu       $s0, $s0, 0x6958
        ctx->r16 = ADD32(ctx->r16, 0X6958);
            goto L_8008C7A8;
    }
    // 0x8008C72C: addiu       $s0, $s0, 0x6958
    ctx->r16 = ADD32(ctx->r16, 0X6958);
    // 0x8008C730: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8008C734: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x8008C738: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008C73C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8008C740: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x8008C744: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    // 0x8008C748: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x8008C74C: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x8008C750: bne         $at, $zero, L_8008C768
    if (ctx->r1 != 0) {
        // 0x8008C754: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008C768;
    }
    // 0x8008C754: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C758: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x8008C75C: sh          $t2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r10;
    // 0x8008C760: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    // 0x8008C764: nop

L_8008C768:
    // 0x8008C768: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8008C76C: lbu         $a0, 0x334($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X334);
    // 0x8008C770: jal         0x80001268
    // 0x8008C774: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_4;
    // 0x8008C774: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    after_4:
    // 0x8008C778: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C77C: addiu       $v1, $v1, 0x6954
    ctx->r3 = ADD32(ctx->r3, 0X6954);
    // 0x8008C780: lb          $t4, 0x0($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X0);
    // 0x8008C784: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C788: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8008C78C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8008C790: lbu         $a0, 0x335($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X335);
    // 0x8008C794: lbu         $a1, 0x3($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X3);
    // 0x8008C798: jal         0x80001268
    // 0x8008C79C: nop

    music_channel_fade_set(rdram, ctx);
        goto after_5;
    // 0x8008C79C: nop

    after_5:
    // 0x8008C7A0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C7A4: addiu       $v1, $v1, 0x6954
    ctx->r3 = ADD32(ctx->r3, 0X6954);
L_8008C7A8:
    // 0x8008C7A8: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8008C7AC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008C7B0: bltz        $v0, L_8008C85C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C7B4: sll         $t9, $t7, 2
        ctx->r25 = S32(ctx->r15 << 2);
            goto L_8008C85C;
    }
    // 0x8008C7B4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8008C7B8: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x8008C7BC: lb          $t0, 0x0($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X0);
    // 0x8008C7C0: subu        $t8, $t6, $t9
    ctx->r24 = SUB32(ctx->r14, ctx->r25);
    // 0x8008C7C4: beq         $t0, $v0, L_8008C848
    if (ctx->r8 == ctx->r2) {
        // 0x8008C7C8: sh          $t8, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r24;
            goto L_8008C848;
    }
    // 0x8008C7C8: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8008C7CC: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x8008C7D0: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8008C7D4: bgez        $v1, L_8008C818
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008C7D8: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008C818;
    }
    // 0x8008C7D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C7DC: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x8008C7E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C7E4: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8008C7E8: lbu         $a0, 0x334($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X334);
    // 0x8008C7EC: jal         0x80001114
    // 0x8008C7F0: nop

    music_channel_off(rdram, ctx);
        goto after_6;
    // 0x8008C7F0: nop

    after_6:
    // 0x8008C7F4: lb          $t2, 0x0($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X0);
    // 0x8008C7F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C7FC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8008C800: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8008C804: lbu         $a0, 0x335($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X335);
    // 0x8008C808: jal         0x80001114
    // 0x8008C80C: nop

    music_channel_off(rdram, ctx);
        goto after_7;
    // 0x8008C80C: nop

    after_7:
    // 0x8008C810: b           L_8008C84C
    // 0x8008C814: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
        goto L_8008C84C;
    // 0x8008C814: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
L_8008C818:
    // 0x8008C818: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x8008C81C: lbu         $a0, 0x334($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X334);
    // 0x8008C820: jal         0x80001268
    // 0x8008C824: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_8;
    // 0x8008C824: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    after_8:
    // 0x8008C828: lb          $t5, 0x0($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X0);
    // 0x8008C82C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C830: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x8008C834: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8008C838: lbu         $a0, 0x335($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X335);
    // 0x8008C83C: lbu         $a1, 0x3($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X3);
    // 0x8008C840: jal         0x80001268
    // 0x8008C844: nop

    music_channel_fade_set(rdram, ctx);
        goto after_9;
    // 0x8008C844: nop

    after_9:
L_8008C848:
    // 0x8008C848: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
L_8008C84C:
    // 0x8008C84C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8008C850: bgez        $t6, L_8008C860
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008C854: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008C860;
    }
    // 0x8008C854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C858: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_8008C85C:
    // 0x8008C85C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008C860:
    // 0x8008C860: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008C864: jr          $ra
    // 0x8008C868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8008C868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void menu_caution_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C86C: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8008C870: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C878: sw          $t6, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = ctx->r14;
    // 0x8008C87C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C880: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C884: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8008C888: jal         0x800C46D0
    // 0x8008C88C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_0;
    // 0x8008C88C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008C890: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C894: jal         0x800C06F8
    // 0x8008C898: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8008C898: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_1:
    // 0x8008C89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C8A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008C8A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C8A8: sw          $t7, -0x5E8($at)
    MEM_W(-0X5E8, ctx->r1) = ctx->r15;
    // 0x8008C8AC: jr          $ra
    // 0x8008C8B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008C8B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void menu_caution_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C8B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008C8B8: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
    // 0x8008C8BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008C8C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C8C8: beq         $v0, $zero, L_8008C8DC
    if (ctx->r2 == 0) {
        // 0x8008C8CC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8008C8DC;
    }
    // 0x8008C8CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008C8D0: addu        $t7, $v0, $a0
    ctx->r15 = ADD32(ctx->r2, ctx->r4);
    // 0x8008C8D4: b           L_8008C924
    // 0x8008C8D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_8008C924;
    // 0x8008C8D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8008C8DC:
    // 0x8008C8DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008C8E0: lw          $t8, 0x6964($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6964);
    // 0x8008C8E4: nop

    // 0x8008C8E8: bgtz        $t8, L_8008C924
    if (SIGNED(ctx->r24) > 0) {
        // 0x8008C8EC: nop
    
            goto L_8008C924;
    }
    // 0x8008C8EC: nop

    // 0x8008C8F0: jal         0x8006A794
    // 0x8008C8F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8008C8F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8008C8F8: andi        $t9, $v0, 0xD000
    ctx->r25 = ctx->r2 & 0XD000;
    // 0x8008C8FC: beq         $t9, $zero, L_8008C924
    if (ctx->r25 == 0) {
        // 0x8008C900: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008C924;
    }
    // 0x8008C900: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008C904: jal         0x80001D04
    // 0x8008C908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8008C908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8008C90C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008C910: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C914: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C918: sw          $t0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r8;
    // 0x8008C91C: jal         0x800C06F8
    // 0x8008C920: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8008C920: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_2:
L_8008C924:
    // 0x8008C924: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008C928: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
    // 0x8008C92C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008C930: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008C934: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8008C938: beq         $at, $zero, L_8008C958
    if (ctx->r1 == 0) {
        // 0x8008C93C: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8008C958;
    }
    // 0x8008C93C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008C940: addiu       $a1, $a1, 0x558
    ctx->r5 = ADD32(ctx->r5, 0X558);
    // 0x8008C944: jal         0x8008263C
    // 0x8008C948: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_3;
    // 0x8008C948: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x8008C94C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008C950: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008C954: nop

L_8008C958:
    // 0x8008C958: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8008C95C: bne         $at, $zero, L_8008C974
    if (ctx->r1 != 0) {
        // 0x8008C960: nop
    
            goto L_8008C974;
    }
    // 0x8008C960: nop

    // 0x8008C964: jal         0x8008C9A0
    // 0x8008C968: nop

    caution_free(rdram, ctx);
        goto after_4;
    // 0x8008C968: nop

    after_4:
    // 0x8008C96C: jal         0x80081820
    // 0x8008C970: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    menu_init(rdram, ctx);
        goto after_5;
    // 0x8008C970: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_5:
L_8008C974:
    // 0x8008C974: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C978: addiu       $v1, $v1, 0x6964
    ctx->r3 = ADD32(ctx->r3, 0X6964);
    // 0x8008C97C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008C980: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8008C984: blez        $v0, L_8008C990
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008C988: subu        $t2, $v0, $t1
        ctx->r10 = SUB32(ctx->r2, ctx->r9);
            goto L_8008C990;
    }
    // 0x8008C988: subu        $t2, $v0, $t1
    ctx->r10 = SUB32(ctx->r2, ctx->r9);
    // 0x8008C98C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_8008C990:
    // 0x8008C990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C998: jr          $ra
    // 0x8008C99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8008C99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void caution_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C9A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C9A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C9A8: jal         0x800C478C
    // 0x8008C9AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x8008C9AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008C9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C9B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C9B8: jr          $ra
    // 0x8008C9BC: nop

    return;
    // 0x8008C9BC: nop

;}
RECOMP_FUNC void menu_game_select_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C9C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C9C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008C9C8: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8008C9CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C9D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008C9D4: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8008C9D8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008C9DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C9E0: addiu       $s4, $s4, 0x6980
    ctx->r20 = ADD32(ctx->r20, 0X6980);
    // 0x8008C9E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008C9E8: sw          $zero, -0x620($at)
    MEM_W(-0X620, ctx->r1) = 0;
    // 0x8008C9EC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8008C9F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C9F4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008C9F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008C9FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008CA00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CA04: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8008CA08: jal         0x800C06F8
    // 0x8008CA0C: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8008CA0C: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_0:
    // 0x8008CA10: jal         0x8006EDE8
    // 0x8008CA14: nop

    mark_read_all_save_files(rdram, ctx);
        goto after_1;
    // 0x8008CA14: nop

    after_1:
    // 0x8008CA18: jal         0x8001B7C4
    // 0x8008CA1C: nop

    set_ghost_none(rdram, ctx);
        goto after_2;
    // 0x8008CA1C: nop

    after_2:
    // 0x8008CA20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008CA24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CA28: sw          $t7, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r15;
    // 0x8008CA2C: jal         0x8009CC18
    // 0x8008CA30: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    menu_asset_load(rdram, ctx);
        goto after_3;
    // 0x8008CA30: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_3:
    // 0x8008CA34: jal         0x8008043C
    // 0x8008CA38: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8007FFEC(rdram, ctx);
        goto after_4;
    // 0x8008CA38: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x8008CA3C: jal         0x800C46D0
    // 0x8008CA40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_5;
    // 0x8008CA40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x8008CA44: jal         0x80000B34
    // 0x8008CA48: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    music_play(rdram, ctx);
        goto after_6;
    // 0x8008CA48: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_6:
    // 0x8008CA4C: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008CA50: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008CA54: addiu       $s2, $s2, 0x6954
    ctx->r18 = ADD32(ctx->r18, 0X6954);
    // 0x8008CA58: addiu       $s3, $s3, 0x334
    ctx->r19 = ADD32(ctx->r19, 0X334);
    // 0x8008CA5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8008CA60:
    // 0x8008CA60: lb          $t8, 0x0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X0);
    // 0x8008CA64: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x8008CA68: beq         $s0, $t8, L_8008CA88
    if (ctx->r16 == ctx->r24) {
        // 0x8008CA6C: addu        $s1, $s3, $t9
        ctx->r17 = ADD32(ctx->r19, ctx->r25);
            goto L_8008CA88;
    }
    // 0x8008CA6C: addu        $s1, $s3, $t9
    ctx->r17 = ADD32(ctx->r19, ctx->r25);
    // 0x8008CA70: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8008CA74: jal         0x80001114
    // 0x8008CA78: nop

    music_channel_off(rdram, ctx);
        goto after_7;
    // 0x8008CA78: nop

    after_7:
    // 0x8008CA7C: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x8008CA80: jal         0x80001114
    // 0x8008CA84: nop

    music_channel_off(rdram, ctx);
        goto after_8;
    // 0x8008CA84: nop

    after_8:
L_8008CA88:
    // 0x8008CA88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008CA8C: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8008CA90: bne         $at, $zero, L_8008CA60
    if (ctx->r1 != 0) {
        // 0x8008CA94: nop
    
            goto L_8008CA60;
    }
    // 0x8008CA94: nop

    // 0x8008CA98: jal         0x80001114
    // 0x8008CA9C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_channel_off(rdram, ctx);
        goto after_9;
    // 0x8008CA9C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
    // 0x8008CAA0: jal         0x80000B18
    // 0x8008CAA4: nop

    music_change_off(rdram, ctx);
        goto after_10;
    // 0x8008CAA4: nop

    after_10:
    // 0x8008CAA8: jal         0x8009F1A4
    // 0x8008CAAC: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_11;
    // 0x8008CAAC: nop

    after_11:
    // 0x8008CAB0: beq         $v0, $zero, L_8008CAD8
    if (ctx->r2 == 0) {
        // 0x8008CAB4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8008CAD8;
    }
    // 0x8008CAB4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008CAB8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008CABC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008CAC0: addiu       $v1, $v1, 0x6A00
    ctx->r3 = ADD32(ctx->r3, 0X6A00);
    // 0x8008CAC4: addiu       $t0, $t0, 0x7F8
    ctx->r8 = ADD32(ctx->r8, 0X7F8);
    // 0x8008CAC8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8008CACC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8008CAD0: b           L_8008CAF0
    // 0x8008CAD4: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
        goto L_8008CAF0;
    // 0x8008CAD4: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
L_8008CAD8:
    // 0x8008CAD8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008CADC: addiu       $v1, $v1, 0x6A00
    ctx->r3 = ADD32(ctx->r3, 0X6A00);
    // 0x8008CAE0: addiu       $t2, $t2, 0x718
    ctx->r10 = ADD32(ctx->r10, 0X718);
    // 0x8008CAE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8008CAE8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8008CAEC: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
L_8008CAF0:
    // 0x8008CAF0: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8008CAF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008CAF8: bltz        $t4, L_8008CB30
    if (SIGNED(ctx->r12) < 0) {
        // 0x8008CAFC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8008CB30;
    }
    // 0x8008CAFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008CB00: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
L_8008CB04:
    // 0x8008CB04: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008CB08: or          $t7, $s0, $zero
    ctx->r15 = ctx->r16 | 0;
    // 0x8008CB0C: lw          $t5, 0x10C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10C);
    // 0x8008CB10: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x8008CB14: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8008CB18: sw          $t5, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->r13;
    // 0x8008CB1C: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x8008CB20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008CB24: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8008CB28: beq         $at, $zero, L_8008CB04
    if (ctx->r1 == 0) {
        // 0x8008CB2C: nop
    
            goto L_8008CB04;
    }
    // 0x8008CB2C: nop

L_8008CB30:
    // 0x8008CB30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008CB34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008CB38: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CB3C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008CB40: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008CB44: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008CB48: jr          $ra
    // 0x8008CB4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008CB4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gameselect_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CB50: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008CB54: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008CB58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008CB5C: slti        $at, $v0, -0x15
    ctx->r1 = SIGNED(ctx->r2) < -0X15 ? 1 : 0;
    // 0x8008CB60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CB64: bne         $at, $zero, L_8008CC64
    if (ctx->r1 != 0) {
        // 0x8008CB68: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8008CC64;
    }
    // 0x8008CB68: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008CB6C: slti        $at, $v0, 0x16
    ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
    // 0x8008CB70: beq         $at, $zero, L_8008CC64
    if (ctx->r1 == 0) {
        // 0x8008CB74: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8008CC64;
    }
    // 0x8008CB74: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008CB78: lw          $a2, 0x695C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X695C);
    // 0x8008CB7C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008CB80: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x8008CB84: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8008CB88: bne         $at, $zero, L_8008CB98
    if (ctx->r1 != 0) {
        // 0x8008CB8C: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_8008CB98;
    }
    // 0x8008CB8C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8008CB90: addiu       $t7, $zero, 0x1FF
    ctx->r15 = ADD32(0, 0X1FF);
    // 0x8008CB94: subu        $a2, $t7, $t6
    ctx->r6 = SUB32(ctx->r15, ctx->r14);
L_8008CB98:
    // 0x8008CB98: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008CB9C: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8008CBA0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008CBA4: jal         0x8006816C
    // 0x8008CBA8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x8008CBA8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8008CBAC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008CBB0: addiu       $a0, $a0, 0x6980
    ctx->r4 = ADD32(ctx->r4, 0X6980);
    // 0x8008CBB4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8008CBB8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CBBC: bltz        $t8, L_8008CC0C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8008CBC0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008CC0C;
    }
    // 0x8008CBC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008CBC4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008CBC8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008CBCC: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    // 0x8008CBD0: addiu       $a3, $a3, 0x6A00
    ctx->r7 = ADD32(ctx->r7, 0X6A00);
L_8008CBD4:
    // 0x8008CBD4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8008CBD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008CBDC: bne         $v0, $t9, L_8008CBE8
    if (ctx->r2 != ctx->r25) {
        // 0x8008CBE0: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8008CBE8;
    }
    // 0x8008CBE0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8008CBE4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8008CBE8:
    // 0x8008CBE8: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8008CBEC: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x8008CBF0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8008CBF4: sb          $v1, 0x6F($t3)
    MEM_B(0X6F, ctx->r11) = ctx->r3;
    // 0x8008CBF8: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8008CBFC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008CC00: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008CC04: beq         $at, $zero, L_8008CBD4
    if (ctx->r1 == 0) {
        // 0x8008CC08: nop
    
            goto L_8008CBD4;
    }
    // 0x8008CC08: nop

L_8008CC0C:
    // 0x8008CC0C: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x8008CC10: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x8008CC14: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008CC18: bne         $t5, $zero, L_8008CC38
    if (ctx->r13 != 0) {
        // 0x8008CC1C: addiu       $a3, $a3, 0x6A00
        ctx->r7 = ADD32(ctx->r7, 0X6A00);
            goto L_8008CC38;
    }
    // 0x8008CC1C: addiu       $a3, $a3, 0x6A00
    ctx->r7 = ADD32(ctx->r7, 0X6A00);
    // 0x8008CC20: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8008CC24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CC28: sw          $t6, -0x2E4($at)
    MEM_W(-0X2E4, ctx->r1) = ctx->r14;
    // 0x8008CC2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CC30: b           L_8008CC48
    // 0x8008CC34: sw          $zero, -0x2E0($at)
    MEM_W(-0X2E0, ctx->r1) = 0;
        goto L_8008CC48;
    // 0x8008CC34: sw          $zero, -0x2E0($at)
    MEM_W(-0X2E0, ctx->r1) = 0;
L_8008CC38:
    // 0x8008CC38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CC3C: sw          $zero, -0x2E4($at)
    MEM_W(-0X2E4, ctx->r1) = 0;
    // 0x8008CC40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CC44: sw          $zero, -0x2E0($at)
    MEM_W(-0X2E0, ctx->r1) = 0;
L_8008CC48:
    // 0x8008CC48: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x8008CC4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008CC50: jal         0x8008263C
    // 0x8008CC54: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_1;
    // 0x8008CC54: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x8008CC58: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008CC5C: jal         0x80081018
    // 0x8008CC60: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    func_80080BC8(rdram, ctx);
        goto after_2;
    // 0x8008CC60: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_2:
L_8008CC64:
    // 0x8008CC64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CC68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008CC6C: jr          $ra
    // 0x8008CC70: nop

    return;
    // 0x8008CC70: nop

;}
RECOMP_FUNC void menu_game_select_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CC74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008CC78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CC7C: jal         0x8008C620
    // 0x8008CC80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    charselect_music_channels(rdram, ctx);
        goto after_0;
    // 0x8008CC80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008CC84: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008CC88: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8008CC8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008CC90: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008CC94: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008CC98: addiu       $a1, $a1, 0x6978
    ctx->r5 = ADD32(ctx->r5, 0X6978);
    // 0x8008CC9C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008CCA0: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8008CCA4: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8008CCA8: beq         $v0, $zero, L_8008CCD8
    if (ctx->r2 == 0) {
        // 0x8008CCAC: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008CCD8;
    }
    // 0x8008CCAC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008CCB0: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8008CCB4: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8008CCB8: bne         $at, $zero, L_8008CCD8
    if (ctx->r1 != 0) {
        // 0x8008CCBC: sw          $t9, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r25;
            goto L_8008CCD8;
    }
    // 0x8008CCBC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8008CCC0: jal         0x80082D08
    // 0x8008CCC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    trackmenu_set_records(rdram, ctx);
        goto after_1;
    // 0x8008CCC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x8008CCC8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008CCCC: addiu       $a1, $a1, 0x6978
    ctx->r5 = ADD32(ctx->r5, 0X6978);
    // 0x8008CCD0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008CCD4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8008CCD8:
    // 0x8008CCD8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008CCDC: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
    // 0x8008CCE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008CCE4: nop

    // 0x8008CCE8: beq         $v0, $zero, L_8008CD14
    if (ctx->r2 == 0) {
        // 0x8008CCEC: slti        $at, $v0, 0x1F
        ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
            goto L_8008CD14;
    }
    // 0x8008CCEC: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8008CCF0: bgez        $v0, L_8008CD08
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008CCF4: addu        $t2, $v0, $a0
        ctx->r10 = ADD32(ctx->r2, ctx->r4);
            goto L_8008CD08;
    }
    // 0x8008CCF4: addu        $t2, $v0, $a0
    ctx->r10 = ADD32(ctx->r2, ctx->r4);
    // 0x8008CCF8: subu        $t1, $v0, $a0
    ctx->r9 = SUB32(ctx->r2, ctx->r4);
    // 0x8008CCFC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8008CD00: b           L_8008CD10
    // 0x8008CD04: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8008CD10;
    // 0x8008CD04: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8008CD08:
    // 0x8008CD08: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8008CD0C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8008CD10:
    // 0x8008CD10: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
L_8008CD14:
    // 0x8008CD14: bne         $at, $zero, L_8008CDA4
    if (ctx->r1 != 0) {
        // 0x8008CD18: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_8008CDA4;
    }
    // 0x8008CD18: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x8008CD1C: jal         0x8008CF84
    // 0x8008CD20: nop

    gameselect_free(rdram, ctx);
        goto after_2;
    // 0x8008CD20: nop

    after_2:
    // 0x8008CD24: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008CD28: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008CD2C: lw          $t3, 0x6980($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6980);
    // 0x8008CD30: lw          $v0, -0x620($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X620);
    // 0x8008CD34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CD38: bne         $t3, $v0, L_8008CD78
    if (ctx->r11 != ctx->r2) {
        // 0x8008CD3C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008CD78;
    }
    // 0x8008CD3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008CD40: jal         0x80000B28
    // 0x8008CD44: nop

    music_change_on(rdram, ctx);
        goto after_3;
    // 0x8008CD44: nop

    after_3:
    // 0x8008CD48: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008CD4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CD50: jal         0x8006E7FC
    // 0x8008CD54: sw          $t4, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = ctx->r12;
    init_racer_headers(rdram, ctx);
        goto after_4;
    // 0x8008CD54: sw          $t4, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = ctx->r12;
    after_4:
    // 0x8008CD58: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8008CD5C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008CD60: jal         0x8006E528
    // 0x8008CD64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_5;
    // 0x8008CD64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8008CD68: jal         0x80081820
    // 0x8008CD6C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    menu_init(rdram, ctx);
        goto after_6;
    // 0x8008CD6C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_6:
    // 0x8008CD70: b           L_8008CF74
    // 0x8008CD74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008CF74;
    // 0x8008CD74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008CD78:
    // 0x8008CD78: sw          $v0, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r2;
    // 0x8008CD7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CD80: sw          $zero, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = 0;
    // 0x8008CD84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CD88: jal         0x8006DD54
    // 0x8008CD8C: sb          $zero, 0x6F80($at)
    MEM_B(0X6F80, ctx->r1) = 0;
    set_level_default_vehicle(rdram, ctx);
        goto after_7;
    // 0x8008CD8C: sb          $zero, 0x6F80($at)
    MEM_B(0X6F80, ctx->r1) = 0;
    after_7:
    // 0x8008CD90: jal         0x80081820
    // 0x8008CD94: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    menu_init(rdram, ctx);
        goto after_8;
    // 0x8008CD94: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_8:
    // 0x8008CD98: b           L_8008CF74
    // 0x8008CD9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008CF74;
    // 0x8008CD9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008CDA0: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
L_8008CDA4:
    // 0x8008CDA4: beq         $at, $zero, L_8008CE0C
    if (ctx->r1 == 0) {
        // 0x8008CDA8: nop
    
            goto L_8008CE0C;
    }
    // 0x8008CDA8: nop

    // 0x8008CDAC: jal         0x8008CF84
    // 0x8008CDB0: nop

    gameselect_free(rdram, ctx);
        goto after_9;
    // 0x8008CDB0: nop

    after_9:
    // 0x8008CDB4: jal         0x8009F214
    // 0x8008CDB8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    is_drumstick_unlocked(rdram, ctx);
        goto after_10;
    // 0x8008CDB8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_10:
    // 0x8008CDBC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CDC0: beq         $v0, $zero, L_8008CDCC
    if (ctx->r2 == 0) {
        // 0x8008CDC4: nop
    
            goto L_8008CDCC;
    }
    // 0x8008CDC4: nop

    // 0x8008CDC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8008CDCC:
    // 0x8008CDCC: jal         0x8009F1FC
    // 0x8008CDD0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    is_tt_unlocked(rdram, ctx);
        goto after_11;
    // 0x8008CDD0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_11:
    // 0x8008CDD4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CDD8: beq         $v0, $zero, L_8008CDE8
    if (ctx->r2 == 0) {
        // 0x8008CDDC: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_8008CDE8;
    }
    // 0x8008CDDC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008CDE0: xori        $t5, $a2, 0x3
    ctx->r13 = ctx->r6 ^ 0X3;
    // 0x8008CDE4: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
L_8008CDE8:
    // 0x8008CDE8: jal         0x8006E528
    // 0x8008CDEC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_level_for_menu(rdram, ctx);
        goto after_12;
    // 0x8008CDEC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_12:
    // 0x8008CDF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008CDF4: jal         0x8008B36C
    // 0x8008CDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    charselect_prev(rdram, ctx);
        goto after_13;
    // 0x8008CDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x8008CDFC: jal         0x80081820
    // 0x8008CE00: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    menu_init(rdram, ctx);
        goto after_14;
    // 0x8008CE00: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_14:
    // 0x8008CE04: b           L_8008CF74
    // 0x8008CE08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008CF74;
    // 0x8008CE08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008CE0C:
    // 0x8008CE0C: jal         0x8008CB50
    // 0x8008CE10: nop

    gameselect_render(rdram, ctx);
        goto after_15;
    // 0x8008CE10: nop

    after_15:
    // 0x8008CE14: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008CE18: lw          $t6, -0x604($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X604);
    // 0x8008CE1C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008CE20: bne         $t6, $zero, L_8008CF68
    if (ctx->r14 != 0) {
        // 0x8008CE24: addiu       $a1, $a1, 0x6978
        ctx->r5 = ADD32(ctx->r5, 0X6978);
            goto L_8008CF68;
    }
    // 0x8008CE24: addiu       $a1, $a1, 0x6978
    ctx->r5 = ADD32(ctx->r5, 0X6978);
    // 0x8008CE28: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8008CE2C: nop

    // 0x8008CE30: bne         $t7, $zero, L_8008CF68
    if (ctx->r15 != 0) {
        // 0x8008CE34: nop
    
            goto L_8008CF68;
    }
    // 0x8008CE34: nop

    // 0x8008CE38: jal         0x8006A794
    // 0x8008CE3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_16;
    // 0x8008CE3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x8008CE40: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008CE44: lw          $t8, -0x5C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5C4);
    // 0x8008CE48: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008CE4C: lb          $a2, 0x6A04($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X6A04);
    // 0x8008CE50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008CE54: bne         $t8, $at, L_8008CE84
    if (ctx->r24 != ctx->r1) {
        // 0x8008CE58: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008CE84;
    }
    // 0x8008CE58: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008CE5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008CE60: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8008CE64: jal         0x8006A794
    // 0x8008CE68: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    input_pressed(rdram, ctx);
        goto after_17;
    // 0x8008CE68: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_17:
    // 0x8008CE6C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008CE70: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8008CE74: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008CE78: lb          $t9, 0x6A05($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X6A05);
    // 0x8008CE7C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008CE80: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_8008CE84:
    // 0x8008CE84: andi        $t0, $v1, 0x9000
    ctx->r8 = ctx->r3 & 0X9000;
    // 0x8008CE88: beq         $t0, $zero, L_8008CEE0
    if (ctx->r8 == 0) {
        // 0x8008CE8C: andi        $t4, $v1, 0x4000
        ctx->r12 = ctx->r3 & 0X4000;
            goto L_8008CEE0;
    }
    // 0x8008CE8C: andi        $t4, $v1, 0x4000
    ctx->r12 = ctx->r3 & 0X4000;
    // 0x8008CE90: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008CE94: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008CE98: lw          $t2, -0x620($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X620);
    // 0x8008CE9C: lw          $t1, 0x6980($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6980);
    // 0x8008CEA0: nop

    // 0x8008CEA4: bne         $t1, $t2, L_8008CEB4
    if (ctx->r9 != ctx->r10) {
        // 0x8008CEA8: nop
    
            goto L_8008CEB4;
    }
    // 0x8008CEA8: nop

    // 0x8008CEAC: jal         0x80000C98
    // 0x8008CEB0: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_18;
    // 0x8008CEB0: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_18:
L_8008CEB4:
    // 0x8008CEB4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CEB8: jal         0x800C06F8
    // 0x8008CEBC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_19;
    // 0x8008CEBC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_19:
    // 0x8008CEC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8008CEC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CEC8: sw          $t3, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r11;
    // 0x8008CECC: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008CED0: jal         0x80001D04
    // 0x8008CED4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_20;
    // 0x8008CED4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x8008CED8: b           L_8008CF68
    // 0x8008CEDC: nop

        goto L_8008CF68;
    // 0x8008CEDC: nop

L_8008CEE0:
    // 0x8008CEE0: beq         $t4, $zero, L_8008CF00
    if (ctx->r12 == 0) {
        // 0x8008CEE4: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008CF00;
    }
    // 0x8008CEE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CEE8: jal         0x800C06F8
    // 0x8008CEEC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_21;
    // 0x8008CEEC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_21:
    // 0x8008CEF0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8008CEF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CEF8: b           L_8008CF68
    // 0x8008CEFC: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
        goto L_8008CF68;
    // 0x8008CEFC: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
L_8008CF00:
    // 0x8008CF00: bgez        $a2, L_8008CF40
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008CF04: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8008CF40;
    }
    // 0x8008CF04: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008CF08: addiu       $v1, $v1, -0x620
    ctx->r3 = ADD32(ctx->r3, -0X620);
    // 0x8008CF0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008CF10: lw          $t6, 0x6980($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6980);
    // 0x8008CF14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008CF18: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008CF1C: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8008CF20: beq         $at, $zero, L_8008CF40
    if (ctx->r1 == 0) {
        // 0x8008CF24: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_8008CF40;
    }
    // 0x8008CF24: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8008CF28: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008CF2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008CF30: jal         0x80001D04
    // 0x8008CF34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    sound_play(rdram, ctx);
        goto after_22;
    // 0x8008CF34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_22:
    // 0x8008CF38: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008CF3C: nop

L_8008CF40:
    // 0x8008CF40: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008CF44: blez        $a2, L_8008CF68
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008CF48: addiu       $v1, $v1, -0x620
        ctx->r3 = ADD32(ctx->r3, -0X620);
            goto L_8008CF68;
    }
    // 0x8008CF48: addiu       $v1, $v1, -0x620
    ctx->r3 = ADD32(ctx->r3, -0X620);
    // 0x8008CF4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008CF50: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008CF54: blez        $v0, L_8008CF68
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008CF58: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8008CF68;
    }
    // 0x8008CF58: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8008CF5C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008CF60: jal         0x80001D04
    // 0x8008CF64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_23;
    // 0x8008CF64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
L_8008CF68:
    // 0x8008CF68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CF6C: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x8008CF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008CF74:
    // 0x8008CF74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CF78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008CF7C: jr          $ra
    // 0x8008CF80: nop

    return;
    // 0x8008CF80: nop

;}
RECOMP_FUNC void gameselect_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CF84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CF88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CF8C: jal         0x800C478C
    // 0x8008CF90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x8008CF90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008CF94: jal         0x800803D8
    // 0x8008CF98: nop

    menu_button_free(rdram, ctx);
        goto after_1;
    // 0x8008CF98: nop

    after_1:
    // 0x8008CF9C: jal         0x8009CA4C
    // 0x8008CFA0: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    menu_asset_free(rdram, ctx);
        goto after_2;
    // 0x8008CFA0: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_2:
    // 0x8008CFA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CFA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CFAC: jr          $ra
    // 0x8008CFB0: nop

    return;
    // 0x8008CFB0: nop

;}
RECOMP_FUNC void menu_file_select_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CFB4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008CFB8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008CFBC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008CFC0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008CFC4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008CFC8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008CFCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CFD0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8008CFD4: jal         0x8006B464
    // 0x8008CFD8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    level_count(rdram, ctx);
        goto after_0;
    // 0x8008CFD8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8008CFDC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CFE0: jal         0x8009CBB8
    // 0x8008CFE4: addiu       $a0, $a0, 0x918
    ctx->r4 = ADD32(ctx->r4, 0X918);
    menu_assetgroup_load(rdram, ctx);
        goto after_1;
    // 0x8008CFE4: addiu       $a0, $a0, 0x918
    ctx->r4 = ADD32(ctx->r4, 0X918);
    after_1:
    // 0x8008CFE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CFEC: jal         0x8009CDE8
    // 0x8008CFF0: addiu       $a0, $a0, 0x924
    ctx->r4 = ADD32(ctx->r4, 0X924);
    menu_imagegroup_load(rdram, ctx);
        goto after_2;
    // 0x8008CFF0: addiu       $a0, $a0, 0x924
    ctx->r4 = ADD32(ctx->r4, 0X924);
    after_2:
    // 0x8008CFF4: jal         0x8008043C
    // 0x8008CFF8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8007FFEC(rdram, ctx);
        goto after_3;
    // 0x8008CFF8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_3:
    // 0x8008CFFC: jal         0x8006EDE8
    // 0x8008D000: nop

    mark_read_all_save_files(rdram, ctx);
        goto after_4;
    // 0x8008D000: nop

    after_4:
    // 0x8008D004: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008D008: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D00C: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
    // 0x8008D010: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D014: sw          $zero, -0x5B4($at)
    MEM_W(-0X5B4, ctx->r1) = 0;
    // 0x8008D018: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D01C: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8008D020: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D024: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8008D028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D02C: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8008D030: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D034: sw          $zero, 0x6A24($at)
    MEM_W(0X6A24, ctx->r1) = 0;
    // 0x8008D038: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D03C: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
    // 0x8008D040: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D044: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008D048: sw          $zero, 0x7280($at)
    MEM_W(0X7280, ctx->r1) = 0;
    // 0x8008D04C: jal         0x800C06F8
    // 0x8008D050: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_5;
    // 0x8008D050: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_5:
    // 0x8008D054: jal         0x800C46D0
    // 0x8008D058: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_6;
    // 0x8008D058: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x8008D05C: jal         0x80000B34
    // 0x8008D060: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    music_play(rdram, ctx);
        goto after_7;
    // 0x8008D060: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_7:
    // 0x8008D064: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008D068: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008D06C: addiu       $s2, $s2, 0x6954
    ctx->r18 = ADD32(ctx->r18, 0X6954);
    // 0x8008D070: addiu       $s3, $s3, 0x334
    ctx->r19 = ADD32(ctx->r19, 0X334);
    // 0x8008D074: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008D078: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_8008D07C:
    // 0x8008D07C: lb          $t7, 0x0($s2)
    ctx->r15 = MEM_B(ctx->r18, 0X0);
    // 0x8008D080: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x8008D084: beq         $s0, $t7, L_8008D0A4
    if (ctx->r16 == ctx->r15) {
        // 0x8008D088: addu        $s1, $s3, $t8
        ctx->r17 = ADD32(ctx->r19, ctx->r24);
            goto L_8008D0A4;
    }
    // 0x8008D088: addu        $s1, $s3, $t8
    ctx->r17 = ADD32(ctx->r19, ctx->r24);
    // 0x8008D08C: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8008D090: jal         0x80001114
    // 0x8008D094: nop

    music_channel_off(rdram, ctx);
        goto after_8;
    // 0x8008D094: nop

    after_8:
    // 0x8008D098: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x8008D09C: jal         0x80001114
    // 0x8008D0A0: nop

    music_channel_off(rdram, ctx);
        goto after_9;
    // 0x8008D0A0: nop

    after_9:
L_8008D0A4:
    // 0x8008D0A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008D0A8: bne         $s0, $s4, L_8008D07C
    if (ctx->r16 != ctx->r20) {
        // 0x8008D0AC: nop
    
            goto L_8008D07C;
    }
    // 0x8008D0AC: nop

    // 0x8008D0B0: jal         0x80001114
    // 0x8008D0B4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_channel_off(rdram, ctx);
        goto after_10;
    // 0x8008D0B4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_10:
    // 0x8008D0B8: jal         0x80000B18
    // 0x8008D0BC: nop

    music_change_off(rdram, ctx);
        goto after_11;
    // 0x8008D0BC: nop

    after_11:
    // 0x8008D0C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008D0C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008D0C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D0CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008D0D0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008D0D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008D0D8: jr          $ra
    // 0x8008D0DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8008D0DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void fileselect_render_element(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D0E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008D0E4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008D0E8: addiu       $t2, $t2, -0x5D4
    ctx->r10 = ADD32(ctx->r10, -0X5D4);
    // 0x8008D0EC: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x8008D0F0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008D0F4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D0F8: addiu       $t3, $t3, -0x31C
    ctx->r11 = ADD32(ctx->r11, -0X31C);
    // 0x8008D0FC: addiu       $t0, $t0, -0x5DC
    ctx->r8 = ADD32(ctx->r8, -0X5DC);
    // 0x8008D100: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8008D104: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x8008D108: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x8008D10C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008D110: addiu       $t8, $a1, -0x9F
    ctx->r24 = ADD32(ctx->r5, -0X9F);
    // 0x8008D114: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8008D118: addiu       $t1, $t1, -0x5D8
    ctx->r9 = ADD32(ctx->r9, -0X5D8);
    // 0x8008D11C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008D120: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x8008D124: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008D128: addiu       $v1, $v1, -0x324
    ctx->r3 = ADD32(ctx->r3, -0X324);
    // 0x8008D12C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8008D130: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8008D134: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008D138: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8008D13C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008D140: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008D144: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x8008D148: sb          $t4, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r12;
    // 0x8008D14C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D150: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8008D154: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8008D158: sb          $a3, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r7;
    // 0x8008D15C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8008D160: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x8008D164: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8008D168: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x8008D16C: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
    // 0x8008D170: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008D174: addiu       $t6, $zero, 0x77
    ctx->r14 = ADD32(0, 0X77);
    // 0x8008D178: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x8008D17C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8008D180: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008D184: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008D188: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008D18C: swc1        $f10, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f10.u32l;
    // 0x8008D190: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8008D194: jal         0x8009CFA4
    // 0x8008D198: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    menu_element_render(rdram, ctx);
        goto after_0;
    // 0x8008D198: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8008D19C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8008D1A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D1A4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008D1A8: sb          $t4, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r12;
    // 0x8008D1AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D1B0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8008D1B4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8008D1B8: sb          $t6, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r14;
    // 0x8008D1BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D1C0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008D1C4: sb          $t5, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r13;
    // 0x8008D1C8: addiu       $t9, $t8, -0xA1
    ctx->r25 = ADD32(ctx->r24, -0XA1);
    // 0x8008D1CC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8008D1D0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008D1D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D1D8: addiu       $v1, $v1, -0x324
    ctx->r3 = ADD32(ctx->r3, -0X324);
    // 0x8008D1DC: sw          $t7, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r15;
    // 0x8008D1E0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008D1E4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D1E8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008D1EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008D1F0: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x8008D1F4: swc1        $f18, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f18.u32l;
    // 0x8008D1F8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008D1FC: addiu       $t7, $zero, 0x79
    ctx->r15 = ADD32(0, 0X79);
    // 0x8008D200: subu        $t8, $t7, $t5
    ctx->r24 = SUB32(ctx->r15, ctx->r13);
    // 0x8008D204: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8008D208: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008D20C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008D210: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x8008D214: jal         0x8009CFA4
    // 0x8008D218: swc1        $f6, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f6.u32l;
    menu_element_render(rdram, ctx);
        goto after_1;
    // 0x8008D218: swc1        $f6, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f6.u32l;
    after_1:
    // 0x8008D21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D220: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008D224: jr          $ra
    // 0x8008D228: nop

    return;
    // 0x8008D228: nop

;}
RECOMP_FUNC void fileselect_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D22C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8008D230: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8008D234: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8008D238: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8008D23C: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x8008D240: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x8008D244: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x8008D248: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8008D24C: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8008D250: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8008D254: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8008D258: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8008D25C: bne         $t6, $zero, L_8008D26C
    if (ctx->r14 != 0) {
        // 0x8008D260: sw          $a0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r4;
            goto L_8008D26C;
    }
    // 0x8008D260: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8008D264: b           L_8008D270
    // 0x8008D268: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
        goto L_8008D270;
    // 0x8008D268: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
L_8008D26C:
    // 0x8008D26C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_8008D270:
    // 0x8008D270: jal         0x8009C2A0
    // 0x8008D274: nop

    menu_camera_centre(rdram, ctx);
        goto after_0;
    // 0x8008D274: nop

    after_0:
    // 0x8008D278: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008D27C: addiu       $s7, $s7, 0x693C
    ctx->r23 = ADD32(ctx->r23, 0X693C);
    // 0x8008D280: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008D284: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8008D288: jal         0x8006816C
    // 0x8008D28C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    mtx_ortho(rdram, ctx);
        goto after_1;
    // 0x8008D28C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x8008D290: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008D294: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008D298: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008D29C: lui         $s3, 0xB0E0
    ctx->r19 = S32(0XB0E0 << 16);
    // 0x8008D2A0: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8008D2A4: addiu       $s2, $s2, -0x5EC
    ctx->r18 = ADD32(ctx->r18, -0X5EC);
    // 0x8008D2A8: ori         $s3, $s3, 0xC0FF
    ctx->r19 = ctx->r19 | 0XC0FF;
    // 0x8008D2AC: addiu       $s5, $s5, 0x6AF0
    ctx->r21 = ADD32(ctx->r21, 0X6AF0);
    // 0x8008D2B0: addiu       $s0, $s0, 0x94C
    ctx->r16 = ADD32(ctx->r16, 0X94C);
    // 0x8008D2B4: addiu       $s1, $s1, 0x6A40
    ctx->r17 = ADD32(ctx->r17, 0X6A40);
    // 0x8008D2B8: addiu       $s4, $zero, 0x78
    ctx->r20 = ADD32(0, 0X78);
L_8008D2BC:
    // 0x8008D2BC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8008D2C0: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x8008D2C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D2C8: beq         $t7, $t8, L_8008D2E0
    if (ctx->r15 == ctx->r24) {
        // 0x8008D2CC: nop
    
            goto L_8008D2E0;
    }
    // 0x8008D2CC: nop

    // 0x8008D2D0: lbu         $t9, 0x1($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X1);
    // 0x8008D2D4: lui         $v0, 0x6A90
    ctx->r2 = S32(0X6A90 << 16);
    // 0x8008D2D8: bne         $t9, $zero, L_8008D2E8
    if (ctx->r25 != 0) {
        // 0x8008D2DC: ori         $v0, $v0, 0x73FF
        ctx->r2 = ctx->r2 | 0X73FF;
            goto L_8008D2E8;
    }
    // 0x8008D2DC: ori         $v0, $v0, 0x73FF
    ctx->r2 = ctx->r2 | 0X73FF;
L_8008D2E0:
    // 0x8008D2E0: b           L_8008D2E8
    // 0x8008D2E4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_8008D2E8;
    // 0x8008D2E4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_8008D2E8:
    // 0x8008D2E8: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8008D2EC: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x8008D2F0: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x8008D2F4: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    // 0x8008D2F8: lh          $t3, 0xA($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA);
    // 0x8008D2FC: lw          $t4, 0x10C($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X10C);
    // 0x8008D300: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x8008D304: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008D308: addiu       $a1, $a1, -0xA0
    ctx->r5 = ADD32(ctx->r5, -0XA0);
    // 0x8008D30C: subu        $a2, $s4, $t0
    ctx->r6 = SUB32(ctx->r20, ctx->r8);
    // 0x8008D310: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008D314: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8008D318: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8008D31C: jal         0x800809D0
    // 0x8008D320: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    func_80080580(rdram, ctx);
        goto after_2;
    // 0x8008D320: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_2:
    // 0x8008D324: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008D328: addiu       $t5, $t5, 0x97C
    ctx->r13 = ADD32(ctx->r13, 0X97C);
    // 0x8008D32C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8008D330: sltu        $at, $s0, $t5
    ctx->r1 = ctx->r16 < ctx->r13 ? 1 : 0;
    // 0x8008D334: bne         $at, $zero, L_8008D2BC
    if (ctx->r1 != 0) {
        // 0x8008D338: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8008D2BC;
    }
    // 0x8008D338: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x8008D33C: jal         0x80081018
    // 0x8008D340: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80080BC8(rdram, ctx);
        goto after_3;
    // 0x8008D340: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_3:
    // 0x8008D344: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008D348: lw          $t6, 0x6978($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6978);
    // 0x8008D34C: nop

    // 0x8008D350: bne         $t6, $zero, L_8008D5B0
    if (ctx->r14 != 0) {
        // 0x8008D354: nop
    
            goto L_8008D5B0;
    }
    // 0x8008D354: nop

    // 0x8008D358: jal         0x800C484C
    // 0x8008D35C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_4;
    // 0x8008D35C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x8008D360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D364: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008D368: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008D36C: jal         0x800C492C
    // 0x8008D370: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_5;
    // 0x8008D370: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8008D374: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008D378: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008D37C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8008D380: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008D384: addiu       $s3, $s3, -0x324
    ctx->r19 = ADD32(ctx->r19, -0X324);
    // 0x8008D388: addiu       $s4, $s4, 0x97C
    ctx->r20 = ADD32(ctx->r20, 0X97C);
    // 0x8008D38C: addiu       $s0, $s0, 0x94C
    ctx->r16 = ADD32(ctx->r16, 0X94C);
    // 0x8008D390: addiu       $s1, $s1, 0x6A40
    ctx->r17 = ADD32(ctx->r17, 0X6A40);
    // 0x8008D394: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
L_8008D398:
    // 0x8008D398: lbu         $t7, 0x1($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1);
    // 0x8008D39C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D3A0: beq         $t7, $zero, L_8008D550
    if (ctx->r15 == 0) {
        // 0x8008D3A4: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008D550;
    }
    // 0x8008D3A4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D3A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D3AC: jal         0x8007C36C
    // 0x8008D3B0: addiu       $s2, $zero, 0xB
    ctx->r18 = ADD32(0, 0XB);
    sprite_opaque(rdram, ctx);
        goto after_6;
    // 0x8008D3B0: addiu       $s2, $zero, 0xB
    ctx->r18 = ADD32(0, 0XB);
    after_6:
    // 0x8008D3B4: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x8008D3B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008D3BC: beq         $t8, $zero, L_8008D3C8
    if (ctx->r24 == 0) {
        // 0x8008D3C0: addiu       $t3, $zero, 0x80
        ctx->r11 = ADD32(0, 0X80);
            goto L_8008D3C8;
    }
    // 0x8008D3C0: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8008D3C4: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_8008D3C8:
    // 0x8008D3C8: lh          $t9, 0x4($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X4);
    // 0x8008D3CC: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x8008D3D0: lh          $t1, 0x6($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X6);
    // 0x8008D3D4: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x8008D3D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8008D3DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008D3E0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008D3E4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8008D3E8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x8008D3EC: jal         0x8008D0E0
    // 0x8008D3F0: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    fileselect_render_element(rdram, ctx);
        goto after_7;
    // 0x8008D3F0: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_7:
    // 0x8008D3F4: jal         0x80068748
    // 0x8008D3F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_8;
    // 0x8008D3F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x8008D3FC: lhu         $t4, 0x2($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X2);
    // 0x8008D400: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8008D404: div         $zero, $t4, $s5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r21)));
    // 0x8008D408: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8008D40C: bne         $s5, $zero, L_8008D418
    if (ctx->r21 != 0) {
        // 0x8008D410: nop
    
            goto L_8008D418;
    }
    // 0x8008D410: nop

    // 0x8008D414: break       7
    do_break(2148062228);
L_8008D418:
    // 0x8008D418: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008D41C: bne         $s5, $at, L_8008D430
    if (ctx->r21 != ctx->r1) {
        // 0x8008D420: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008D430;
    }
    // 0x8008D420: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008D424: bne         $t4, $at, L_8008D430
    if (ctx->r12 != ctx->r1) {
        // 0x8008D428: nop
    
            goto L_8008D430;
    }
    // 0x8008D428: nop

    // 0x8008D42C: break       6
    do_break(2148062252);
L_8008D430:
    // 0x8008D430: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D434: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008D438: mflo        $t5
    ctx->r13 = lo;
    // 0x8008D43C: sh          $t5, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r13;
    // 0x8008D440: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8008D444: lh          $t7, 0xC($s4)
    ctx->r15 = MEM_H(ctx->r20, 0XC);
    // 0x8008D448: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x8008D44C: lh          $t9, 0xE($s4)
    ctx->r25 = MEM_H(ctx->r20, 0XE);
    // 0x8008D450: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8008D454: addiu       $a1, $a1, -0x6
    ctx->r5 = ADD32(ctx->r5, -0X6);
    // 0x8008D458: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8008D45C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008D460: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008D464: jal         0x8008D0E0
    // 0x8008D468: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    fileselect_render_element(rdram, ctx);
        goto after_9;
    // 0x8008D468: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    after_9:
    // 0x8008D46C: lhu         $t2, 0x2($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X2);
    // 0x8008D470: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8008D474: div         $zero, $t2, $s5
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r21)));
    // 0x8008D478: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8008D47C: bne         $s5, $zero, L_8008D488
    if (ctx->r21 != 0) {
        // 0x8008D480: nop
    
            goto L_8008D488;
    }
    // 0x8008D480: nop

    // 0x8008D484: break       7
    do_break(2148062340);
L_8008D488:
    // 0x8008D488: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008D48C: bne         $s5, $at, L_8008D4A0
    if (ctx->r21 != ctx->r1) {
        // 0x8008D490: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008D4A0;
    }
    // 0x8008D490: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008D494: bne         $t2, $at, L_8008D4A0
    if (ctx->r10 != ctx->r1) {
        // 0x8008D498: nop
    
            goto L_8008D4A0;
    }
    // 0x8008D498: nop

    // 0x8008D49C: break       6
    do_break(2148062364);
L_8008D4A0:
    // 0x8008D4A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D4A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008D4A8: mfhi        $t3
    ctx->r11 = hi;
    // 0x8008D4AC: sh          $t3, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r11;
    // 0x8008D4B0: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8008D4B4: lh          $t5, 0xC($s4)
    ctx->r13 = MEM_H(ctx->r20, 0XC);
    // 0x8008D4B8: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x8008D4BC: lh          $t7, 0xE($s4)
    ctx->r15 = MEM_H(ctx->r20, 0XE);
    // 0x8008D4C0: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8008D4C4: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x8008D4C8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8008D4CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008D4D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008D4D4: jal         0x8008D0E0
    // 0x8008D4D8: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    fileselect_render_element(rdram, ctx);
        goto after_10;
    // 0x8008D4D8: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    after_10:
    // 0x8008D4DC: jal         0x80068748
    // 0x8008D4E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_11;
    // 0x8008D4E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x8008D4E4: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x8008D4E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D4EC: sb          $v0, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r2;
    // 0x8008D4F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D4F4: sb          $v0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r2;
    // 0x8008D4F8: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    // 0x8008D4FC: lh          $t2, 0x12($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X12);
    // 0x8008D500: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8008D504: lh          $t0, 0x10($s4)
    ctx->r8 = MEM_H(ctx->r20, 0X10);
    // 0x8008D508: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x8008D50C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8008D510: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008D514: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008D518: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008D51C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008D520: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x8008D524: jal         0x8008D0E0
    // 0x8008D528: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    fileselect_render_element(rdram, ctx);
        goto after_12;
    // 0x8008D528: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_12:
    // 0x8008D52C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008D530: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D534: sb          $v0, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r2;
    // 0x8008D538: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D53C: sb          $v0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r2;
    // 0x8008D540: jal         0x8007C36C
    // 0x8008D544: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_13;
    // 0x8008D544: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x8008D548: b           L_8008D59C
    // 0x8008D54C: nop

        goto L_8008D59C;
    // 0x8008D54C: nop

L_8008D550:
    // 0x8008D550: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8008D554: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008D558: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D55C: jal         0x800C48E4
    // 0x8008D560: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    set_text_colour(rdram, ctx);
        goto after_14;
    // 0x8008D560: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_14:
    // 0x8008D564: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008D568: lw          $t1, -0x5E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E0);
    // 0x8008D56C: lh          $t8, 0xA($s4)
    ctx->r24 = MEM_H(ctx->r20, 0XA);
    // 0x8008D570: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x8008D574: lh          $t6, 0x8($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X8);
    // 0x8008D578: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8008D57C: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8008D580: lw          $a3, 0x12C($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X12C);
    // 0x8008D584: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8008D588: addu        $a2, $t0, $s6
    ctx->r6 = ADD32(ctx->r8, ctx->r22);
    // 0x8008D58C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008D590: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D594: jal         0x800C49A0
    // 0x8008D598: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    draw_text(rdram, ctx);
        goto after_15;
    // 0x8008D598: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_15:
L_8008D59C:
    // 0x8008D59C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D5A0: addiu       $t3, $t3, 0x97C
    ctx->r11 = ADD32(ctx->r11, 0X97C);
    // 0x8008D5A4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8008D5A8: bne         $s0, $t3, L_8008D398
    if (ctx->r16 != ctx->r11) {
        // 0x8008D5AC: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8008D398;
    }
    // 0x8008D5AC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8008D5B0:
    // 0x8008D5B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D5B4: lw          $v0, 0x695C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X695C);
    // 0x8008D5B8: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8008D5BC: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x8008D5C0: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x8008D5C4: addiu       $s4, $s4, 0x97C
    ctx->r20 = ADD32(ctx->r20, 0X97C);
    // 0x8008D5C8: bne         $at, $zero, L_8008D5D8
    if (ctx->r1 != 0) {
        // 0x8008D5CC: or          $v0, $t4, $zero
        ctx->r2 = ctx->r12 | 0;
            goto L_8008D5D8;
    }
    // 0x8008D5CC: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8008D5D0: addiu       $t5, $zero, 0x1FF
    ctx->r13 = ADD32(0, 0X1FF);
    // 0x8008D5D4: subu        $v0, $t5, $t4
    ctx->r2 = SUB32(ctx->r13, ctx->r12);
L_8008D5D8:
    // 0x8008D5D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D5DC: jal         0x800C484C
    // 0x8008D5E0: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    set_text_font(rdram, ctx);
        goto after_16;
    // 0x8008D5E0: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_16:
    // 0x8008D5E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D5E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008D5EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008D5F0: jal         0x800C492C
    // 0x8008D5F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_17;
    // 0x8008D5F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_17:
    // 0x8008D5F8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8008D5FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008D600: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D604: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D608: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D60C: jal         0x800C48E4
    // 0x8008D610: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x8008D610: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x8008D614: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008D618: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
L_8008D61C:
    // 0x8008D61C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008D620: lw          $t7, 0x6A24($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A24);
    // 0x8008D624: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8008D628: beq         $t7, $zero, L_8008D67C
    if (ctx->r15 == 0) {
        // 0x8008D62C: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8008D67C;
    }
    // 0x8008D62C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008D630: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D634: lw          $v0, 0x6A34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A34);
    // 0x8008D638: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008D63C: bne         $v0, $zero, L_8008D65C
    if (ctx->r2 != 0) {
        // 0x8008D640: nop
    
            goto L_8008D65C;
    }
    // 0x8008D640: nop

    // 0x8008D644: lw          $t8, 0x6A2C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A2C);
    // 0x8008D648: nop

    // 0x8008D64C: bne         $s3, $t8, L_8008D65C
    if (ctx->r19 != ctx->r24) {
        // 0x8008D650: nop
    
            goto L_8008D65C;
    }
    // 0x8008D650: nop

    // 0x8008D654: b           L_8008D6C8
    // 0x8008D658: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8008D6C8;
    // 0x8008D658: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8008D65C:
    // 0x8008D65C: blez        $v0, L_8008D6C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008D660: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8008D6C8;
    }
    // 0x8008D660: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008D664: lw          $t9, 0x6A30($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A30);
    // 0x8008D668: nop

    // 0x8008D66C: bne         $s3, $t9, L_8008D6C8
    if (ctx->r19 != ctx->r25) {
        // 0x8008D670: nop
    
            goto L_8008D6C8;
    }
    // 0x8008D670: nop

    // 0x8008D674: b           L_8008D6C8
    // 0x8008D678: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8008D6C8;
    // 0x8008D678: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8008D67C:
    // 0x8008D67C: lw          $t0, 0x6A28($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6A28);
    // 0x8008D680: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008D684: beq         $t0, $zero, L_8008D6A4
    if (ctx->r8 == 0) {
        // 0x8008D688: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8008D6A4;
    }
    // 0x8008D688: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008D68C: lw          $t1, 0x6A2C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6A2C);
    // 0x8008D690: nop

    // 0x8008D694: bne         $s3, $t1, L_8008D6C8
    if (ctx->r19 != ctx->r9) {
        // 0x8008D698: nop
    
            goto L_8008D6C8;
    }
    // 0x8008D698: nop

    // 0x8008D69C: b           L_8008D6C8
    // 0x8008D6A0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8008D6C8;
    // 0x8008D6A0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8008D6A4:
    // 0x8008D6A4: lw          $t2, 0x6980($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6980);
    // 0x8008D6A8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D6AC: bne         $t2, $zero, L_8008D6C8
    if (ctx->r10 != 0) {
        // 0x8008D6B0: nop
    
            goto L_8008D6C8;
    }
    // 0x8008D6B0: nop

    // 0x8008D6B4: lw          $t3, -0x5B4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5B4);
    // 0x8008D6B8: nop

    // 0x8008D6BC: bne         $s3, $t3, L_8008D6C8
    if (ctx->r19 != ctx->r11) {
        // 0x8008D6C0: nop
    
            goto L_8008D6C8;
    }
    // 0x8008D6C0: nop

    // 0x8008D6C4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8008D6C8:
    // 0x8008D6C8: beq         $s2, $zero, L_8008D72C
    if (ctx->r18 == 0) {
        // 0x8008D6CC: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8008D72C;
    }
    // 0x8008D6CC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D6D0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008D6D4: addiu       $t5, $t5, 0x94C
    ctx->r13 = ADD32(ctx->r13, 0X94C);
    // 0x8008D6D8: sll         $t4, $s3, 4
    ctx->r12 = S32(ctx->r19 << 4);
    // 0x8008D6DC: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x8008D6E0: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x8008D6E4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8008D6E8: or          $t0, $v0, $at
    ctx->r8 = ctx->r2 | ctx->r1;
    // 0x8008D6EC: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x8008D6F0: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x8008D6F4: lh          $t8, 0x8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8);
    // 0x8008D6F8: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x8008D6FC: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8008D700: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x8008D704: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8008D708: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8008D70C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8008D710: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8008D714: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8008D718: addu        $a2, $t6, $s6
    ctx->r6 = ADD32(ctx->r14, ctx->r22);
    // 0x8008D71C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008D720: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8008D724: jal         0x800812E0
    // 0x8008D728: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_80080E90(rdram, ctx);
        goto after_19;
    // 0x8008D728: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_19:
L_8008D72C:
    // 0x8008D72C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008D730: lw          $t1, 0x7280($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7280);
    // 0x8008D734: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008D738: beq         $t1, $zero, L_8008D74C
    if (ctx->r9 == 0) {
        // 0x8008D73C: sll         $t3, $s3, 2
        ctx->r11 = S32(ctx->r19 << 2);
            goto L_8008D74C;
    }
    // 0x8008D73C: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x8008D740: lw          $t2, -0x5B4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5B4);
    // 0x8008D744: nop

    // 0x8008D748: beq         $s3, $t2, L_8008D7D0
    if (ctx->r19 == ctx->r10) {
        // 0x8008D74C: subu        $t3, $t3, $s3
        ctx->r11 = SUB32(ctx->r11, ctx->r19);
            goto L_8008D7D0;
    }
L_8008D74C:
    // 0x8008D74C: subu        $t3, $t3, $s3
    ctx->r11 = SUB32(ctx->r11, ctx->r19);
    // 0x8008D750: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008D754: addiu       $t4, $t4, 0x6A40
    ctx->r12 = ADD32(ctx->r12, 0X6A40);
    // 0x8008D758: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008D75C: addu        $s1, $t3, $t4
    ctx->r17 = ADD32(ctx->r11, ctx->r12);
    // 0x8008D760: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x8008D764: jal         0x80097D0C
    // 0x8008D768: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    filename_trim(rdram, ctx);
        goto after_20;
    // 0x8008D768: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_20:
    // 0x8008D76C: lbu         $t5, 0x1($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X1);
    // 0x8008D770: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x8008D774: bne         $t5, $zero, L_8008D78C
    if (ctx->r13 != 0) {
        // 0x8008D778: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008D78C;
    }
    // 0x8008D778: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008D77C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8008D780: lw          $a0, 0x930($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X930);
    // 0x8008D784: jal         0x80097D0C
    // 0x8008D788: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    filename_trim(rdram, ctx);
        goto after_21;
    // 0x8008D788: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_21:
L_8008D78C:
    // 0x8008D78C: beq         $s5, $zero, L_8008D7D0
    if (ctx->r21 == 0) {
        // 0x8008D790: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8008D7D0;
    }
    // 0x8008D790: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D794: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008D798: addiu       $t8, $t8, 0x94C
    ctx->r24 = ADD32(ctx->r24, 0X94C);
    // 0x8008D79C: sll         $t7, $s3, 4
    ctx->r15 = S32(ctx->r19 << 4);
    // 0x8008D7A0: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x8008D7A4: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x8008D7A8: lh          $t1, 0x2($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X2);
    // 0x8008D7AC: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x8008D7B0: lh          $t9, 0x0($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X0);
    // 0x8008D7B4: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8008D7B8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8008D7BC: addu        $a2, $t3, $s6
    ctx->r6 = ADD32(ctx->r11, ctx->r22);
    // 0x8008D7C0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008D7C4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x8008D7C8: jal         0x800C49A0
    // 0x8008D7CC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    draw_text(rdram, ctx);
        goto after_22;
    // 0x8008D7CC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_22:
L_8008D7D0:
    // 0x8008D7D0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8008D7D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008D7D8: bne         $s3, $at, L_8008D61C
    if (ctx->r19 != ctx->r1) {
        // 0x8008D7DC: nop
    
            goto L_8008D61C;
    }
    // 0x8008D7DC: nop

    // 0x8008D7E0: jal         0x800C484C
    // 0x8008D7E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_23;
    // 0x8008D7E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_23:
    // 0x8008D7E8: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x8008D7EC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008D7F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D7F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008D7F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008D7FC: jal         0x800C48E4
    // 0x8008D800: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_24;
    // 0x8008D800: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_24:
    // 0x8008D804: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008D808: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x8008D80C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8008D810: lw          $a3, 0x2F0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X2F0);
    // 0x8008D814: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008D818: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D81C: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8008D820: jal         0x800C49A0
    // 0x8008D824: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    draw_text(rdram, ctx);
        goto after_25;
    // 0x8008D824: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    after_25:
    // 0x8008D828: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008D82C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008D830: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D834: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D838: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D83C: jal         0x800C48E4
    // 0x8008D840: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_26;
    // 0x8008D840: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_26:
    // 0x8008D844: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008D848: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x8008D84C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8008D850: lw          $a3, 0x2F0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X2F0);
    // 0x8008D854: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8008D858: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D85C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D860: jal         0x800C49A0
    // 0x8008D864: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    draw_text(rdram, ctx);
        goto after_27;
    // 0x8008D864: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_27:
    // 0x8008D868: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8008D86C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008D870: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D874: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D878: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D87C: jal         0x800C48E4
    // 0x8008D880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_28;
    // 0x8008D880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_28:
    // 0x8008D884: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008D888: lw          $t2, 0x6A24($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6A24);
    // 0x8008D88C: addiu       $s6, $s6, 0xBB
    ctx->r22 = ADD32(ctx->r22, 0XBB);
    // 0x8008D890: beq         $t2, $zero, L_8008D940
    if (ctx->r10 == 0) {
        // 0x8008D894: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8008D940;
    }
    // 0x8008D894: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008D898: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D89C: lw          $v0, 0x6A34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A34);
    // 0x8008D8A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D8A4: bne         $v0, $zero, L_8008D8E0
    if (ctx->r2 != 0) {
        // 0x8008D8A8: nop
    
            goto L_8008D8E0;
    }
    // 0x8008D8A8: nop

    // 0x8008D8AC: jal         0x800C484C
    // 0x8008D8B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_29;
    // 0x8008D8B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_29:
    // 0x8008D8B4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D8B8: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x8008D8BC: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8008D8C0: lw          $a3, 0x134($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X134);
    // 0x8008D8C4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008D8C8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D8CC: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D8D0: jal         0x800C49A0
    // 0x8008D8D4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_30;
    // 0x8008D8D4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_30:
    // 0x8008D8D8: b           L_8008DA88
    // 0x8008D8DC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008DA88;
    // 0x8008D8DC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D8E0:
    // 0x8008D8E0: bne         $v0, $at, L_8008D91C
    if (ctx->r2 != ctx->r1) {
        // 0x8008D8E4: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8008D91C;
    }
    // 0x8008D8E4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D8E8: jal         0x800C484C
    // 0x8008D8EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_31;
    // 0x8008D8EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x8008D8F0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008D8F4: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8008D8F8: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8008D8FC: lw          $a3, 0x138($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X138);
    // 0x8008D900: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008D904: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D908: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D90C: jal         0x800C49A0
    // 0x8008D910: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_32;
    // 0x8008D910: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_32:
    // 0x8008D914: b           L_8008DA88
    // 0x8008D918: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008DA88;
    // 0x8008D918: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D91C:
    // 0x8008D91C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8008D920: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8008D924: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008D928: addiu       $a3, $a3, -0x783C
    ctx->r7 = ADD32(ctx->r7, -0X783C);
    // 0x8008D92C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D930: jal         0x800C49A0
    // 0x8008D934: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_33;
    // 0x8008D934: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_33:
    // 0x8008D938: b           L_8008DA88
    // 0x8008D93C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008DA88;
    // 0x8008D93C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D940:
    // 0x8008D940: lw          $t8, 0x6A28($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A28);
    // 0x8008D944: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008D948: beq         $t8, $zero, L_8008D9B4
    if (ctx->r24 == 0) {
        // 0x8008D94C: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8008D9B4;
    }
    // 0x8008D94C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008D950: lw          $t9, 0x6A34($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A34);
    // 0x8008D954: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D958: bne         $t9, $zero, L_8008D994
    if (ctx->r25 != 0) {
        // 0x8008D95C: addiu       $a1, $zero, 0xA0
        ctx->r5 = ADD32(0, 0XA0);
            goto L_8008D994;
    }
    // 0x8008D95C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D960: jal         0x800C484C
    // 0x8008D964: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_34;
    // 0x8008D964: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_34:
    // 0x8008D968: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008D96C: lw          $t0, -0x5E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E0);
    // 0x8008D970: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008D974: lw          $a3, 0x13C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X13C);
    // 0x8008D978: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008D97C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D980: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D984: jal         0x800C49A0
    // 0x8008D988: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_35;
    // 0x8008D988: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_35:
    // 0x8008D98C: b           L_8008DA88
    // 0x8008D990: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008DA88;
    // 0x8008D990: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D994:
    // 0x8008D994: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8008D998: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8008D99C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008D9A0: addiu       $a3, $a3, -0x7838
    ctx->r7 = ADD32(ctx->r7, -0X7838);
    // 0x8008D9A4: jal         0x800C49A0
    // 0x8008D9A8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_36;
    // 0x8008D9A8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_36:
    // 0x8008D9AC: b           L_8008DA88
    // 0x8008D9B0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008DA88;
    // 0x8008D9B0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D9B4:
    // 0x8008D9B4: lw          $t3, 0x7280($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7280);
    // 0x8008D9B8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008D9BC: bne         $t3, $zero, L_8008DA88
    if (ctx->r11 != 0) {
        // 0x8008D9C0: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8008DA88;
    }
    // 0x8008D9C0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8008D9C4: lw          $t4, 0x6980($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6980);
    // 0x8008D9C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D9CC: bne         $t4, $at, L_8008D9EC
    if (ctx->r12 != ctx->r1) {
        // 0x8008D9D0: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8008D9EC;
    }
    // 0x8008D9D0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D9D4: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8008D9D8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8008D9DC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008D9E0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D9E4: jal         0x800C48E4
    // 0x8008D9E8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_37;
    // 0x8008D9E8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_37:
L_8008D9EC:
    // 0x8008D9EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008D9F0: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x8008D9F4: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8008D9F8: lw          $a3, 0x140($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X140);
    // 0x8008D9FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008DA00: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008DA04: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8008DA08: jal         0x800C49A0
    // 0x8008DA0C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_38;
    // 0x8008DA0C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_38:
    // 0x8008DA10: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008DA14: lw          $t8, 0x6980($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6980);
    // 0x8008DA18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008DA1C: bne         $t8, $at, L_8008DA48
    if (ctx->r24 != ctx->r1) {
        // 0x8008DA20: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8008DA48;
    }
    // 0x8008DA20: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008DA24: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8008DA28: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008DA2C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008DA30: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008DA34: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008DA38: jal         0x800C48E4
    // 0x8008DA3C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_39;
    // 0x8008DA3C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_39:
    // 0x8008DA40: b           L_8008DA60
    // 0x8008DA44: nop

        goto L_8008DA60;
    // 0x8008DA44: nop

L_8008DA48:
    // 0x8008DA48: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8008DA4C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8008DA50: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008DA54: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008DA58: jal         0x800C48E4
    // 0x8008DA5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_40;
    // 0x8008DA5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_40:
L_8008DA60:
    // 0x8008DA60: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008DA64: lw          $t1, -0x5E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E0);
    // 0x8008DA68: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8008DA6C: lw          $a3, 0x144($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X144);
    // 0x8008DA70: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008DA74: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008DA78: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8008DA7C: jal         0x800C49A0
    // 0x8008DA80: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_41;
    // 0x8008DA80: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_41:
    // 0x8008DA84: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008DA88:
    // 0x8008DA88: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8008DA8C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8008DA90: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8008DA94: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8008DA98: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8008DA9C: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8008DAA0: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x8008DAA4: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8008DAA8: jr          $ra
    // 0x8008DAAC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8008DAAC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void fileselect_input_root(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DAB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008DAB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DAB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008DABC: jal         0x8006A794
    // 0x8008DAC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8008DAC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8008DAC4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008DAC8: lw          $t6, -0x5C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C4);
    // 0x8008DACC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DAD0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008DAD4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8008DAD8: lb          $a2, 0x69FC($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X69FC);
    // 0x8008DADC: lb          $a3, 0x6A04($a3)
    ctx->r7 = MEM_B(ctx->r7, 0X6A04);
    // 0x8008DAE0: bne         $t0, $t6, L_8008DB28
    if (ctx->r8 != ctx->r14) {
        // 0x8008DAE4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008DB28;
    }
    // 0x8008DAE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008DAE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008DAEC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8008DAF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008DAF4: jal         0x8006A794
    // 0x8008DAF8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008DAF8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8008DAFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008DB00: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008DB04: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8008DB08: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008DB0C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DB10: lb          $t7, 0x69FD($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X69FD);
    // 0x8008DB14: lb          $t8, 0x6A05($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X6A05);
    // 0x8008DB18: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8008DB1C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008DB20: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8008DB24: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
L_8008DB28:
    // 0x8008DB28: andi        $t9, $v1, 0x9000
    ctx->r25 = ctx->r3 & 0X9000;
    // 0x8008DB2C: beq         $t9, $zero, L_8008DC48
    if (ctx->r25 == 0) {
        // 0x8008DB30: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8008DC48;
    }
    // 0x8008DB30: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008DB34: addiu       $t1, $t1, 0x6980
    ctx->r9 = ADD32(ctx->r9, 0X6980);
    // 0x8008DB38: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8008DB3C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008DB40: beq         $v0, $zero, L_8008DB64
    if (ctx->r2 == 0) {
        // 0x8008DB44: addiu       $t3, $t3, -0x5B4
        ctx->r11 = ADD32(ctx->r11, -0X5B4);
            goto L_8008DB64;
    }
    // 0x8008DB44: addiu       $t3, $t3, -0x5B4
    ctx->r11 = ADD32(ctx->r11, -0X5B4);
    // 0x8008DB48: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008DB4C: beq         $v0, $t2, L_8008DBD4
    if (ctx->r2 == ctx->r10) {
        // 0x8008DB50: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008DBD4;
    }
    // 0x8008DB50: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008DB54: beq         $v0, $t0, L_8008DC10
    if (ctx->r2 == ctx->r8) {
        // 0x8008DB58: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008DC10;
    }
    // 0x8008DB58: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008DB5C: b           L_8008DC5C
    // 0x8008DB60: nop

        goto L_8008DC5C;
    // 0x8008DB60: nop

L_8008DB64:
    // 0x8008DB64: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8008DB68: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008DB6C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008DB70: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008DB74: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008DB78: addiu       $t6, $t6, 0x6A40
    ctx->r14 = ADD32(ctx->r14, 0X6A40);
    // 0x8008DB7C: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8008DB80: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x8008DB84: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008DB88: beq         $t7, $zero, L_8008DBC4
    if (ctx->r15 == 0) {
        // 0x8008DB8C: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008DBC4;
    }
    // 0x8008DB8C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008DB90: lw          $t8, -0x5EC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5EC);
    // 0x8008DB94: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8008DB98: addiu       $a0, $zero, 0x15C
    ctx->r4 = ADD32(0, 0X15C);
    // 0x8008DB9C: beq         $t8, $t9, L_8008DBC0
    if (ctx->r24 == ctx->r25) {
        // 0x8008DBA0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008DBC0;
    }
    // 0x8008DBA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008DBA4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008DBA8: jal         0x80001D04
    // 0x8008DBAC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008DBAC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8008DBB0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008DBB4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DBB8: b           L_8008DC5C
    // 0x8008DBBC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
        goto L_8008DC5C;
    // 0x8008DBBC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_8008DBC0:
    // 0x8008DBC0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
L_8008DBC4:
    // 0x8008DBC4: jal         0x80001D04
    // 0x8008DBC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008DBC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8008DBCC: b           L_8008DD64
    // 0x8008DBD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008DD64;
    // 0x8008DBD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DBD4:
    // 0x8008DBD4: jal         0x80001D04
    // 0x8008DBD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008DBD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8008DBDC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008DBE0: addiu       $t3, $t3, -0x5B4
    ctx->r11 = ADD32(ctx->r11, -0X5B4);
    // 0x8008DBE4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8008DBE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DBEC: sw          $t4, 0x6A2C($at)
    MEM_W(0X6A2C, ctx->r1) = ctx->r12;
    // 0x8008DBF0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008DBF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DBF8: sw          $t2, 0x6A24($at)
    MEM_W(0X6A24, ctx->r1) = ctx->r10;
    // 0x8008DBFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DC00: sw          $zero, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = 0;
    // 0x8008DC04: b           L_8008DD64
    // 0x8008DC08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008DD64;
    // 0x8008DC08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008DC0C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
L_8008DC10:
    // 0x8008DC10: jal         0x80001D04
    // 0x8008DC14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8008DC14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8008DC18: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008DC1C: addiu       $t3, $t3, -0x5B4
    ctx->r11 = ADD32(ctx->r11, -0X5B4);
    // 0x8008DC20: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8008DC24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DC28: sw          $t5, 0x6A2C($at)
    MEM_W(0X6A2C, ctx->r1) = ctx->r13;
    // 0x8008DC2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008DC30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DC34: sw          $t2, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r10;
    // 0x8008DC38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DC3C: sw          $zero, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = 0;
    // 0x8008DC40: b           L_8008DD64
    // 0x8008DC44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008DD64;
    // 0x8008DC44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008DC48:
    // 0x8008DC48: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x8008DC4C: beq         $t6, $zero, L_8008DC5C
    if (ctx->r14 == 0) {
        // 0x8008DC50: nop
    
            goto L_8008DC5C;
    }
    // 0x8008DC50: nop

    // 0x8008DC54: b           L_8008DD64
    // 0x8008DC58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8008DD64;
    // 0x8008DC58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8008DC5C:
    // 0x8008DC5C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008DC60: addiu       $t1, $t1, 0x6980
    ctx->r9 = ADD32(ctx->r9, 0X6980);
    // 0x8008DC64: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008DC68: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8008DC6C: addiu       $t3, $t3, -0x5B4
    ctx->r11 = ADD32(ctx->r11, -0X5B4);
    // 0x8008DC70: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8008DC74: sll         $t7, $v0, 8
    ctx->r15 = S32(ctx->r2 << 8);
    // 0x8008DC78: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008DC7C: bne         $v0, $zero, L_8008DCD8
    if (ctx->r2 != 0) {
        // 0x8008DC80: or          $a0, $t7, $v1
        ctx->r4 = ctx->r15 | ctx->r3;
            goto L_8008DCD8;
    }
    // 0x8008DC80: or          $a0, $t7, $v1
    ctx->r4 = ctx->r15 | ctx->r3;
    // 0x8008DC84: bgez        $a2, L_8008DC9C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008DC88: nop
    
            goto L_8008DC9C;
    }
    // 0x8008DC88: nop

    // 0x8008DC8C: blez        $v1, L_8008DC9C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8008DC90: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_8008DC9C;
    }
    // 0x8008DC90: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x8008DC94: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8008DC98: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8008DC9C:
    // 0x8008DC9C: blez        $a2, L_8008DCB4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008DCA0: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008DCB4;
    }
    // 0x8008DCA0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008DCA4: beq         $at, $zero, L_8008DCB4
    if (ctx->r1 == 0) {
        // 0x8008DCA8: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_8008DCB4;
    }
    // 0x8008DCA8: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8008DCAC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8008DCB0: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_8008DCB4:
    // 0x8008DCB4: bgez        $a3, L_8008DD48
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8008DCB8: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008DD48;
    }
    // 0x8008DCB8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008DCBC: bne         $at, $zero, L_8008DCD0
    if (ctx->r1 != 0) {
        // 0x8008DCC0: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8008DCD0;
    }
    // 0x8008DCC0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8008DCC4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8008DCC8: b           L_8008DD48
    // 0x8008DCCC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8008DD48;
    // 0x8008DCCC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8008DCD0:
    // 0x8008DCD0: b           L_8008DD48
    // 0x8008DCD4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
        goto L_8008DD48;
    // 0x8008DCD4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
L_8008DCD8:
    // 0x8008DCD8: bgez        $a2, L_8008DCF0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008DCDC: nop
    
            goto L_8008DCF0;
    }
    // 0x8008DCDC: nop

    // 0x8008DCE0: bne         $t0, $v0, L_8008DCF0
    if (ctx->r8 != ctx->r2) {
        // 0x8008DCE4: nop
    
            goto L_8008DCF0;
    }
    // 0x8008DCE4: nop

    // 0x8008DCE8: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x8008DCEC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8008DCF0:
    // 0x8008DCF0: blez        $a2, L_8008DD08
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008DCF4: nop
    
            goto L_8008DD08;
    }
    // 0x8008DCF4: nop

    // 0x8008DCF8: bne         $t2, $v0, L_8008DD08
    if (ctx->r10 != ctx->r2) {
        // 0x8008DCFC: nop
    
            goto L_8008DD08;
    }
    // 0x8008DCFC: nop

    // 0x8008DD00: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8008DD04: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8008DD08:
    // 0x8008DD08: blez        $a3, L_8008DD4C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8008DD0C: sll         $t4, $v0, 8
        ctx->r12 = S32(ctx->r2 << 8);
            goto L_8008DD4C;
    }
    // 0x8008DD0C: sll         $t4, $v0, 8
    ctx->r12 = S32(ctx->r2 << 8);
    // 0x8008DD10: bne         $t2, $v0, L_8008DD28
    if (ctx->r10 != ctx->r2) {
        // 0x8008DD14: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008DD28;
    }
    // 0x8008DD14: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008DD18: bne         $at, $zero, L_8008DD28
    if (ctx->r1 != 0) {
        // 0x8008DD1C: nop
    
            goto L_8008DD28;
    }
    // 0x8008DD1C: nop

    // 0x8008DD20: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8008DD24: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8008DD28:
    // 0x8008DD28: bne         $t0, $v0, L_8008DD40
    if (ctx->r8 != ctx->r2) {
        // 0x8008DD2C: nop
    
            goto L_8008DD40;
    }
    // 0x8008DD2C: nop

    // 0x8008DD30: bgtz        $v1, L_8008DD40
    if (SIGNED(ctx->r3) > 0) {
        // 0x8008DD34: nop
    
            goto L_8008DD40;
    }
    // 0x8008DD34: nop

    // 0x8008DD38: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x8008DD3C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_8008DD40:
    // 0x8008DD40: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8008DD44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008DD48:
    // 0x8008DD48: sll         $t4, $v0, 8
    ctx->r12 = S32(ctx->r2 << 8);
L_8008DD4C:
    // 0x8008DD4C: or          $t5, $t4, $v1
    ctx->r13 = ctx->r12 | ctx->r3;
    // 0x8008DD50: beq         $a0, $t5, L_8008DD60
    if (ctx->r4 == ctx->r13) {
        // 0x8008DD54: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008DD60;
    }
    // 0x8008DD54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008DD58: jal         0x80001D04
    // 0x8008DD5C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008DD5C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    after_6:
L_8008DD60:
    // 0x8008DD60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008DD64:
    // 0x8008DD64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DD68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008DD6C: jr          $ra
    // 0x8008DD70: nop

    return;
    // 0x8008DD70: nop

;}
RECOMP_FUNC void fileselect_input_copy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DD74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008DD78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DD7C: jal         0x8006ECD0
    // 0x8008DD80: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8008DD80: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008DD84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008DD88: jal         0x8006A794
    // 0x8008DD8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008DD8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8008DD90: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008DD94: lw          $t6, -0x5C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C4);
    // 0x8008DD98: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008DD9C: lb          $a1, 0x69FC($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X69FC);
    // 0x8008DDA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008DDA4: bne         $t6, $at, L_8008DDD4
    if (ctx->r14 != ctx->r1) {
        // 0x8008DDA8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008DDD4;
    }
    // 0x8008DDA8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008DDAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008DDB0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8008DDB4: jal         0x8006A794
    // 0x8008DDB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x8008DDB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x8008DDBC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008DDC0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8008DDC4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008DDC8: lb          $t7, 0x69FD($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X69FD);
    // 0x8008DDCC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008DDD0: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_8008DDD4:
    // 0x8008DDD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DDD8: lw          $v0, 0x6A34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A34);
    // 0x8008DDDC: andi        $t8, $v1, 0x4000
    ctx->r24 = ctx->r3 & 0X4000;
    // 0x8008DDE0: bne         $v0, $zero, L_8008DEF0
    if (ctx->r2 != 0) {
        // 0x8008DDE4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008DEF0;
    }
    // 0x8008DDE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008DDE8: beq         $t8, $zero, L_8008DE08
    if (ctx->r24 == 0) {
        // 0x8008DDEC: andi        $t9, $v1, 0x9000
        ctx->r25 = ctx->r3 & 0X9000;
            goto L_8008DE08;
    }
    // 0x8008DDEC: andi        $t9, $v1, 0x9000
    ctx->r25 = ctx->r3 & 0X9000;
    // 0x8008DDF0: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DDF4: jal         0x80001D04
    // 0x8008DDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008DDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8008DDFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DE00: b           L_8008E124
    // 0x8008DE04: sw          $zero, 0x6A24($at)
    MEM_W(0X6A24, ctx->r1) = 0;
        goto L_8008E124;
    // 0x8008DE04: sw          $zero, 0x6A24($at)
    MEM_W(0X6A24, ctx->r1) = 0;
L_8008DE08:
    // 0x8008DE08: beq         $t9, $zero, L_8008DEA0
    if (ctx->r25 == 0) {
        // 0x8008DE0C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8008DEA0;
    }
    // 0x8008DE0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DE10: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DE14: addiu       $v0, $v0, 0x6A2C
    ctx->r2 = ADD32(ctx->r2, 0X6A2C);
    // 0x8008DE18: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8008DE1C: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8008DE20: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008DE24: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008DE28: addiu       $t0, $t0, 0x6A40
    ctx->r8 = ADD32(ctx->r8, 0X6A40);
    // 0x8008DE2C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008DE30: mflo        $t2
    ctx->r10 = lo;
    // 0x8008DE34: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8008DE38: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x8008DE3C: nop

    // 0x8008DE40: beq         $t4, $zero, L_8008DE8C
    if (ctx->r12 == 0) {
        // 0x8008DE44: nop
    
            goto L_8008DE8C;
    }
    // 0x8008DE44: nop

    // 0x8008DE48: jal         0x80001D04
    // 0x8008DE4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008DE4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8008DE50: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DE54: addiu       $v0, $v0, 0x6A2C
    ctx->r2 = ADD32(ctx->r2, 0X6A2C);
    // 0x8008DE58: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8008DE5C: jal         0x8006EDB8
    // 0x8008DE60: nop

    mark_read_save_file(rdram, ctx);
        goto after_5;
    // 0x8008DE60: nop

    after_5:
    // 0x8008DE64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DE68: addiu       $v0, $v0, 0x6A2C
    ctx->r2 = ADD32(ctx->r2, 0X6A2C);
    // 0x8008DE6C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8008DE70: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DE74: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x8008DE78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008DE7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DE80: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8008DE84: b           L_8008E124
    // 0x8008DE88: sw          $t6, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r14;
        goto L_8008E124;
    // 0x8008DE88: sw          $t6, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r14;
L_8008DE8C:
    // 0x8008DE8C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DE90: jal         0x80001D04
    // 0x8008DE94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008DE94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8008DE98: b           L_8008E128
    // 0x8008DE9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008E128;
    // 0x8008DE9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DEA0:
    // 0x8008DEA0: addiu       $v0, $v0, 0x6A2C
    ctx->r2 = ADD32(ctx->r2, 0X6A2C);
    // 0x8008DEA4: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8008DEA8: bgez        $a1, L_8008DEC0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008DEAC: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_8008DEC0;
    }
    // 0x8008DEAC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8008DEB0: blez        $a2, L_8008DEC0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008DEB4: addiu       $t7, $a2, -0x1
        ctx->r15 = ADD32(ctx->r6, -0X1);
            goto L_8008DEC0;
    }
    // 0x8008DEB4: addiu       $t7, $a2, -0x1
    ctx->r15 = ADD32(ctx->r6, -0X1);
    // 0x8008DEB8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8008DEBC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_8008DEC0:
    // 0x8008DEC0: blez        $a1, L_8008DED8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8008DEC4: slti        $at, $a2, 0x2
        ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
            goto L_8008DED8;
    }
    // 0x8008DEC4: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8008DEC8: beq         $at, $zero, L_8008DED8
    if (ctx->r1 == 0) {
        // 0x8008DECC: addiu       $t8, $a2, 0x1
        ctx->r24 = ADD32(ctx->r6, 0X1);
            goto L_8008DED8;
    }
    // 0x8008DECC: addiu       $t8, $a2, 0x1
    ctx->r24 = ADD32(ctx->r6, 0X1);
    // 0x8008DED0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8008DED4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
L_8008DED8:
    // 0x8008DED8: beq         $v1, $a2, L_8008E124
    if (ctx->r3 == ctx->r6) {
        // 0x8008DEDC: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008E124;
    }
    // 0x8008DEDC: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008DEE0: jal         0x80001D04
    // 0x8008DEE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x8008DEE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8008DEE8: b           L_8008E128
    // 0x8008DEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008E128;
    // 0x8008DEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DEF0:
    // 0x8008DEF0: bne         $v0, $at, L_8008DFF0
    if (ctx->r2 != ctx->r1) {
        // 0x8008DEF4: andi        $t1, $v1, 0x9000
        ctx->r9 = ctx->r3 & 0X9000;
            goto L_8008DFF0;
    }
    // 0x8008DEF4: andi        $t1, $v1, 0x9000
    ctx->r9 = ctx->r3 & 0X9000;
    // 0x8008DEF8: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x8008DEFC: beq         $t9, $zero, L_8008DF30
    if (ctx->r25 == 0) {
        // 0x8008DF00: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008DF30;
    }
    // 0x8008DF00: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DF04: jal         0x80001D04
    // 0x8008DF08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8008DF08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8008DF0C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DF10: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x8008DF14: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8008DF18: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DF1C: addiu       $v0, $v0, 0x6A2C
    ctx->r2 = ADD32(ctx->r2, 0X6A2C);
    // 0x8008DF20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DF24: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8008DF28: b           L_8008E124
    // 0x8008DF2C: sw          $zero, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = 0;
        goto L_8008E124;
    // 0x8008DF2C: sw          $zero, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = 0;
L_8008DF30:
    // 0x8008DF30: andi        $t2, $v1, 0x9000
    ctx->r10 = ctx->r3 & 0X9000;
    // 0x8008DF34: beq         $t2, $zero, L_8008DF9C
    if (ctx->r10 == 0) {
        // 0x8008DF38: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8008DF9C;
    }
    // 0x8008DF38: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DF3C: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x8008DF40: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8008DF44: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8008DF48: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008DF4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008DF50: addiu       $t0, $t0, 0x6A40
    ctx->r8 = ADD32(ctx->r8, 0X6A40);
    // 0x8008DF54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008DF58: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DF5C: mflo        $t4
    ctx->r12 = lo;
    // 0x8008DF60: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8008DF64: lbu         $t6, 0x1($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X1);
    // 0x8008DF68: nop

    // 0x8008DF6C: bne         $t6, $zero, L_8008DF8C
    if (ctx->r14 != 0) {
        // 0x8008DF70: nop
    
            goto L_8008DF8C;
    }
    // 0x8008DF70: nop

    // 0x8008DF74: jal         0x80001D04
    // 0x8008DF78: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    sound_play(rdram, ctx);
        goto after_9;
    // 0x8008DF78: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    after_9:
    // 0x8008DF7C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8008DF80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DF84: b           L_8008E124
    // 0x8008DF88: sw          $t7, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r15;
        goto L_8008E124;
    // 0x8008DF88: sw          $t7, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r15;
L_8008DF8C:
    // 0x8008DF8C: jal         0x80001D04
    // 0x8008DF90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8008DF90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8008DF94: b           L_8008E128
    // 0x8008DF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008E128;
    // 0x8008DF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DF9C:
    // 0x8008DF9C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DFA0: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x8008DFA4: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8008DFA8: bgez        $a1, L_8008DFC0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008DFAC: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8008DFC0;
    }
    // 0x8008DFAC: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8008DFB0: blez        $a3, L_8008DFC0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8008DFB4: addiu       $t8, $a3, -0x1
        ctx->r24 = ADD32(ctx->r7, -0X1);
            goto L_8008DFC0;
    }
    // 0x8008DFB4: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x8008DFB8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8008DFBC: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_8008DFC0:
    // 0x8008DFC0: blez        $a1, L_8008DFD8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8008DFC4: slti        $at, $a3, 0x2
        ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
            goto L_8008DFD8;
    }
    // 0x8008DFC4: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x8008DFC8: beq         $at, $zero, L_8008DFD8
    if (ctx->r1 == 0) {
        // 0x8008DFCC: addiu       $t9, $a3, 0x1
        ctx->r25 = ADD32(ctx->r7, 0X1);
            goto L_8008DFD8;
    }
    // 0x8008DFCC: addiu       $t9, $a3, 0x1
    ctx->r25 = ADD32(ctx->r7, 0X1);
    // 0x8008DFD0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8008DFD4: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
L_8008DFD8:
    // 0x8008DFD8: beq         $v1, $a3, L_8008E124
    if (ctx->r3 == ctx->r7) {
        // 0x8008DFDC: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008E124;
    }
    // 0x8008DFDC: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008DFE0: jal         0x80001D04
    // 0x8008DFE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_11;
    // 0x8008DFE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x8008DFE8: b           L_8008E128
    // 0x8008DFEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008E128;
    // 0x8008DFEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DFF0:
    // 0x8008DFF0: beq         $t1, $zero, L_8008E104
    if (ctx->r9 == 0) {
        // 0x8008DFF4: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008E104;
    }
    // 0x8008DFF4: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008DFF8: jal         0x80001D04
    // 0x8008DFFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_12;
    // 0x8008DFFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8008E000: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E004: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x8008E008: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8008E00C: jal         0x8006EE58
    // 0x8008E010: nop

    force_mark_write_save_file(rdram, ctx);
        goto after_13;
    // 0x8008E010: nop

    after_13:
    // 0x8008E014: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E018: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x8008E01C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8008E020: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8008E024: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008E028: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008E02C: addiu       $t0, $t0, 0x6A40
    ctx->r8 = ADD32(ctx->r8, 0X6A40);
    // 0x8008E030: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E034: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008E038: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x8008E03C: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x8008E040: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008E044: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E048: mflo        $t2
    ctx->r10 = lo;
    // 0x8008E04C: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x8008E050: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008E054: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x8008E058: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8008E05C: nop

    // 0x8008E060: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8008E064: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x8008E068: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x8008E06C: lw          $t5, 0x10($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X10);
    // 0x8008E070: subu        $t3, $t3, $a3
    ctx->r11 = SUB32(ctx->r11, ctx->r7);
    // 0x8008E074: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x8008E078: beq         $t6, $zero, L_8008E084
    if (ctx->r14 == 0) {
        // 0x8008E07C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_8008E084;
    }
    // 0x8008E07C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008E080: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
L_8008E084:
    // 0x8008E084: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008E088: addiu       $v0, $v0, 0x6A2C
    ctx->r2 = ADD32(ctx->r2, 0X6A2C);
    // 0x8008E08C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8008E090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008E094: multu       $a2, $v1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008E098: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8008E09C: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x8008E0A0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008E0A4: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x8008E0A8: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8008E0AC: mflo        $t7
    ctx->r15 = lo;
    // 0x8008E0B0: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8008E0B4: lbu         $t9, 0x4($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4);
    // 0x8008E0B8: nop

    // 0x8008E0BC: beq         $t9, $zero, L_8008E0E8
    if (ctx->r25 == 0) {
        // 0x8008E0C0: addu        $t5, $t4, $a1
        ctx->r13 = ADD32(ctx->r12, ctx->r5);
            goto L_8008E0E8;
    }
    // 0x8008E0C0: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x8008E0C4: lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4);
    // 0x8008E0C8: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
L_8008E0CC:
    // 0x8008E0CC: sb          $a0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r4;
    // 0x8008E0D0: lbu         $a0, 0x5($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X5);
    // 0x8008E0D4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008E0D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008E0DC: bne         $a0, $zero, L_8008E0CC
    if (ctx->r4 != 0) {
        // 0x8008E0E0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008E0CC;
    }
    // 0x8008E0E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008E0E4: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
L_8008E0E8:
    // 0x8008E0E8: sb          $zero, 0x4($t5)
    MEM_B(0X4, ctx->r13) = 0;
    // 0x8008E0EC: sw          $a3, -0x5B4($at)
    MEM_W(-0X5B4, ctx->r1) = ctx->r7;
    // 0x8008E0F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E0F4: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8008E0F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E0FC: b           L_8008E124
    // 0x8008E100: sw          $zero, 0x6A24($at)
    MEM_W(0X6A24, ctx->r1) = 0;
        goto L_8008E124;
    // 0x8008E100: sw          $zero, 0x6A24($at)
    MEM_W(0X6A24, ctx->r1) = 0;
L_8008E104:
    // 0x8008E104: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x8008E108: beq         $t6, $zero, L_8008E124
    if (ctx->r14 == 0) {
        // 0x8008E10C: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008E124;
    }
    // 0x8008E10C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008E110: jal         0x80001D04
    // 0x8008E114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_14;
    // 0x8008E114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x8008E118: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008E11C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E120: sw          $t7, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r15;
L_8008E124:
    // 0x8008E124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008E128:
    // 0x8008E128: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008E12C: jr          $ra
    // 0x8008E130: nop

    return;
    // 0x8008E130: nop

;}
RECOMP_FUNC void fileselect_input_erase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E134: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008E138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E13C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008E140: jal         0x8006A794
    // 0x8008E144: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8008E144: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8008E148: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008E14C: lw          $t6, -0x5C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C4);
    // 0x8008E150: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008E154: lb          $a1, 0x69FC($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X69FC);
    // 0x8008E158: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008E15C: bne         $t6, $at, L_8008E18C
    if (ctx->r14 != ctx->r1) {
        // 0x8008E160: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008E18C;
    }
    // 0x8008E160: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008E164: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008E168: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008E16C: jal         0x8006A794
    // 0x8008E170: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008E170: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8008E174: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008E178: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E17C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008E180: lb          $t7, 0x69FD($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X69FD);
    // 0x8008E184: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008E188: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_8008E18C:
    // 0x8008E18C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008E190: lw          $t8, 0x6A34($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A34);
    // 0x8008E194: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x8008E198: bne         $t8, $zero, L_8008E270
    if (ctx->r24 != 0) {
        // 0x8008E19C: andi        $t7, $v1, 0x9000
        ctx->r15 = ctx->r3 & 0X9000;
            goto L_8008E270;
    }
    // 0x8008E19C: andi        $t7, $v1, 0x9000
    ctx->r15 = ctx->r3 & 0X9000;
    // 0x8008E1A0: beq         $t9, $zero, L_8008E1C0
    if (ctx->r25 == 0) {
        // 0x8008E1A4: andi        $t0, $v1, 0x9000
        ctx->r8 = ctx->r3 & 0X9000;
            goto L_8008E1C0;
    }
    // 0x8008E1A4: andi        $t0, $v1, 0x9000
    ctx->r8 = ctx->r3 & 0X9000;
    // 0x8008E1A8: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008E1AC: jal         0x80001D04
    // 0x8008E1B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008E1B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8008E1B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E1B8: b           L_8008E318
    // 0x8008E1BC: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
        goto L_8008E318;
    // 0x8008E1BC: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
L_8008E1C0:
    // 0x8008E1C0: beq         $t0, $zero, L_8008E220
    if (ctx->r8 == 0) {
        // 0x8008E1C4: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8008E220;
    }
    // 0x8008E1C4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E1C8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E1CC: addiu       $a2, $a2, 0x6A2C
    ctx->r6 = ADD32(ctx->r6, 0X6A2C);
    // 0x8008E1D0: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8008E1D4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008E1D8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8008E1DC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8008E1E0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008E1E4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8008E1E8: lbu         $t3, 0x6A41($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X6A41);
    // 0x8008E1EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008E1F0: beq         $t3, $zero, L_8008E210
    if (ctx->r11 == 0) {
        // 0x8008E1F4: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008E210;
    }
    // 0x8008E1F4: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008E1F8: jal         0x80001D04
    // 0x8008E1FC: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008E1FC: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    after_3:
    // 0x8008E200: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008E204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E208: b           L_8008E318
    // 0x8008E20C: sw          $t4, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r12;
        goto L_8008E318;
    // 0x8008E20C: sw          $t4, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = ctx->r12;
L_8008E210:
    // 0x8008E210: jal         0x80001D04
    // 0x8008E214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008E214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8008E218: b           L_8008E31C
    // 0x8008E21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008E31C;
    // 0x8008E21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008E220:
    // 0x8008E220: addiu       $a2, $a2, 0x6A2C
    ctx->r6 = ADD32(ctx->r6, 0X6A2C);
    // 0x8008E224: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8008E228: bgez        $a1, L_8008E240
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008E22C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8008E240;
    }
    // 0x8008E22C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008E230: blez        $v1, L_8008E240
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8008E234: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_8008E240;
    }
    // 0x8008E234: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x8008E238: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8008E23C: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_8008E240:
    // 0x8008E240: blez        $a1, L_8008E258
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8008E244: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008E258;
    }
    // 0x8008E244: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008E248: beq         $at, $zero, L_8008E258
    if (ctx->r1 == 0) {
        // 0x8008E24C: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8008E258;
    }
    // 0x8008E24C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8008E250: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8008E254: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8008E258:
    // 0x8008E258: beq         $v0, $v1, L_8008E318
    if (ctx->r2 == ctx->r3) {
        // 0x8008E25C: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008E318;
    }
    // 0x8008E25C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008E260: jal         0x80001D04
    // 0x8008E264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8008E264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8008E268: b           L_8008E31C
    // 0x8008E26C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008E31C;
    // 0x8008E26C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008E270:
    // 0x8008E270: beq         $t7, $zero, L_8008E2FC
    if (ctx->r15 == 0) {
        // 0x8008E274: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008E2FC;
    }
    // 0x8008E274: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008E278: jal         0x80001D04
    // 0x8008E27C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008E27C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8008E280: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E284: addiu       $a2, $a2, 0x6A2C
    ctx->r6 = ADD32(ctx->r6, 0X6A2C);
    // 0x8008E288: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8008E28C: jal         0x8006EEEC
    // 0x8008E290: nop

    mark_save_file_to_erase(rdram, ctx);
        goto after_7;
    // 0x8008E290: nop

    after_7:
    // 0x8008E294: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E298: addiu       $a2, $a2, 0x6A2C
    ctx->r6 = ADD32(ctx->r6, 0X6A2C);
    // 0x8008E29C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8008E2A0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008E2A4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8008E2A8: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8008E2AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008E2B0: addiu       $t9, $t9, 0x6A40
    ctx->r25 = ADD32(ctx->r25, 0X6A40);
    // 0x8008E2B4: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8008E2B8: addiu       $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
    // 0x8008E2BC: addiu       $t1, $zero, 0x4B
    ctx->r9 = ADD32(0, 0X4B);
    // 0x8008E2C0: addiu       $t2, $zero, 0x52
    ctx->r10 = ADD32(0, 0X52);
    // 0x8008E2C4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008E2C8: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8008E2CC: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008E2D0: sb          $t0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r8;
    // 0x8008E2D4: sb          $t1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r9;
    // 0x8008E2D8: sb          $t2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r10;
    // 0x8008E2DC: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // 0x8008E2E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E2E4: sw          $v1, -0x5B4($at)
    MEM_W(-0X5B4, ctx->r1) = ctx->r3;
    // 0x8008E2E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E2EC: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8008E2F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E2F4: b           L_8008E318
    // 0x8008E2F8: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
        goto L_8008E318;
    // 0x8008E2F8: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
L_8008E2FC:
    // 0x8008E2FC: andi        $t3, $v1, 0x4000
    ctx->r11 = ctx->r3 & 0X4000;
    // 0x8008E300: beq         $t3, $zero, L_8008E318
    if (ctx->r11 == 0) {
        // 0x8008E304: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008E318;
    }
    // 0x8008E304: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008E308: jal         0x80001D04
    // 0x8008E30C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8008E30C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8008E310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E314: sw          $zero, 0x6A34($at)
    MEM_W(0X6A34, ctx->r1) = 0;
L_8008E318:
    // 0x8008E318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008E31C:
    // 0x8008E31C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008E320: jr          $ra
    // 0x8008E324: nop

    return;
    // 0x8008E324: nop

;}
RECOMP_FUNC void menu_file_select_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E328: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008E32C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008E330: jal         0x8006ECD0
    // 0x8008E334: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8008E334: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008E338: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8008E33C: jal         0x8008C620
    // 0x8008E340: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    charselect_music_channels(rdram, ctx);
        goto after_1;
    // 0x8008E340: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x8008E344: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008E348: lw          $v0, 0x6978($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6978);
    // 0x8008E34C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E350: beq         $v0, $zero, L_8008E430
    if (ctx->r2 == 0) {
        // 0x8008E354: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8008E430;
    }
    // 0x8008E354: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8008E358: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
    // 0x8008E35C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008E360: lw          $t7, 0x6978($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6978);
    // 0x8008E364: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8008E368: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8008E36C: bne         $at, $zero, L_8008E430
    if (ctx->r1 != 0) {
        // 0x8008E370: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8008E430;
    }
    // 0x8008E370: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008E374: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008E378: addiu       $a3, $a3, 0x6AD0
    ctx->r7 = ADD32(ctx->r7, 0X6AD0);
    // 0x8008E37C: addiu       $v0, $v0, 0x6A40
    ctx->r2 = ADD32(ctx->r2, 0X6A40);
L_8008E380:
    // 0x8008E380: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8008E384: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008E388: lbu         $t8, 0x4B($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4B);
    // 0x8008E38C: addiu       $t4, $zero, 0x4B
    ctx->r12 = ADD32(0, 0X4B);
    // 0x8008E390: beq         $t8, $zero, L_8008E3BC
    if (ctx->r24 == 0) {
        // 0x8008E394: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008E3BC;
    }
    // 0x8008E394: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E398: addiu       $t9, $zero, 0x44
    ctx->r25 = ADD32(0, 0X44);
    // 0x8008E39C: addiu       $t5, $zero, 0x52
    ctx->r13 = ADD32(0, 0X52);
    // 0x8008E3A0: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8008E3A4: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008E3A8: sb          $t9, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r25;
    // 0x8008E3AC: sb          $t4, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r12;
    // 0x8008E3B0: sb          $t5, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r13;
    // 0x8008E3B4: b           L_8008E410
    // 0x8008E3B8: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
        goto L_8008E410;
    // 0x8008E3B8: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
L_8008E3BC:
    // 0x8008E3BC: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x8008E3C0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8008E3C4: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8008E3C8: beq         $t7, $zero, L_8008E3D4
    if (ctx->r15 == 0) {
        // 0x8008E3CC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008E3D4;
    }
    // 0x8008E3CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008E3D0: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
L_8008E3D4:
    // 0x8008E3D4: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8008E3D8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008E3DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8008E3E0: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8008E3E4: nop

    // 0x8008E3E8: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x8008E3EC: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    // 0x8008E3F0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8008E3F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8008E3F8: jal         0x80097C34
    // 0x8008E3FC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    filename_decompress(rdram, ctx);
        goto after_2;
    // 0x8008E3FC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x8008E400: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8008E404: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8008E408: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8008E40C: nop

L_8008E410:
    // 0x8008E410: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8008E414: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008E418: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8008E41C: bne         $t0, $at, L_8008E380
    if (ctx->r8 != ctx->r1) {
        // 0x8008E420: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8008E380;
    }
    // 0x8008E420: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8008E424: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E428: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x8008E42C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_8008E430:
    // 0x8008E430: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008E434: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8008E438: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8008E43C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008E440: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008E444: addiu       $a2, $a2, -0x604
    ctx->r6 = ADD32(ctx->r6, -0X604);
    // 0x8008E448: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008E44C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8008E450: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8008E454: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8008E458: beq         $v0, $zero, L_8008E480
    if (ctx->r2 == 0) {
        // 0x8008E45C: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008E480;
    }
    // 0x8008E45C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008E460: blez        $v0, L_8008E478
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008E464: subu        $t4, $v0, $a1
        ctx->r12 = SUB32(ctx->r2, ctx->r5);
            goto L_8008E478;
    }
    // 0x8008E464: subu        $t4, $v0, $a1
    ctx->r12 = SUB32(ctx->r2, ctx->r5);
    // 0x8008E468: addu        $t9, $v0, $a1
    ctx->r25 = ADD32(ctx->r2, ctx->r5);
    // 0x8008E46C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8008E470: b           L_8008E480
    // 0x8008E474: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8008E480;
    // 0x8008E474: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8008E478:
    // 0x8008E478: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8008E47C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_8008E480:
    // 0x8008E480: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x8008E484: bne         $at, $zero, L_8008E4B0
    if (ctx->r1 != 0) {
        // 0x8008E488: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_8008E4B0;
    }
    // 0x8008E488: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8008E48C: beq         $at, $zero, L_8008E4B0
    if (ctx->r1 == 0) {
        // 0x8008E490: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8008E4B0;
    }
    // 0x8008E490: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8008E494: jal         0x8008D22C
    // 0x8008E498: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    fileselect_render(rdram, ctx);
        goto after_3;
    // 0x8008E498: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_3:
    // 0x8008E49C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008E4A0: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008E4A4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8008E4A8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8008E4AC: nop

L_8008E4B0:
    // 0x8008E4B0: bne         $v0, $zero, L_8008E744
    if (ctx->r2 != 0) {
        // 0x8008E4B4: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8008E744;
    }
    // 0x8008E4B4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008E4B8: lw          $t5, 0x6978($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6978);
    // 0x8008E4BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E4C0: bne         $t5, $zero, L_8008E744
    if (ctx->r13 != 0) {
        // 0x8008E4C4: nop
    
            goto L_8008E744;
    }
    // 0x8008E4C4: nop

    // 0x8008E4C8: lw          $t6, 0x6A24($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A24);
    // 0x8008E4CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008E4D0: beq         $t6, $zero, L_8008E4E8
    if (ctx->r14 == 0) {
        // 0x8008E4D4: nop
    
            goto L_8008E4E8;
    }
    // 0x8008E4D4: nop

    // 0x8008E4D8: jal         0x8008DD74
    // 0x8008E4DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    fileselect_input_copy(rdram, ctx);
        goto after_4;
    // 0x8008E4DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x8008E4E0: b           L_8008E744
    // 0x8008E4E4: nop

        goto L_8008E744;
    // 0x8008E4E4: nop

L_8008E4E8:
    // 0x8008E4E8: lw          $t7, 0x6A28($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A28);
    // 0x8008E4EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008E4F0: beq         $t7, $zero, L_8008E508
    if (ctx->r15 == 0) {
        // 0x8008E4F4: nop
    
            goto L_8008E508;
    }
    // 0x8008E4F4: nop

    // 0x8008E4F8: jal         0x8008E134
    // 0x8008E4FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    fileselect_input_erase(rdram, ctx);
        goto after_5;
    // 0x8008E4FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
    // 0x8008E500: b           L_8008E744
    // 0x8008E504: nop

        goto L_8008E744;
    // 0x8008E504: nop

L_8008E508:
    // 0x8008E508: lw          $t8, 0x7280($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7280);
    // 0x8008E50C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008E510: beq         $t8, $zero, L_8008E634
    if (ctx->r24 == 0) {
        // 0x8008E514: nop
    
            goto L_8008E634;
    }
    // 0x8008E514: nop

    // 0x8008E518: jal         0x8006A794
    // 0x8008E51C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_6;
    // 0x8008E51C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_6:
    // 0x8008E520: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8008E524: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x8008E528: beq         $t9, $zero, L_8008E584
    if (ctx->r25 == 0) {
        // 0x8008E52C: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8008E584;
    }
    // 0x8008E52C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008E530: lw          $t4, 0x1520($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1520);
    // 0x8008E534: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8008E538: bne         $t4, $zero, L_8008E584
    if (ctx->r12 != 0) {
        // 0x8008E53C: subu        $t5, $t5, $t0
        ctx->r13 = SUB32(ctx->r13, ctx->r8);
            goto L_8008E584;
    }
    // 0x8008E53C: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x8008E540: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E544: addiu       $t6, $t6, 0x6A40
    ctx->r14 = ADD32(ctx->r14, 0X6A40);
    // 0x8008E548: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008E54C: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8008E550: jal         0x80098724
    // 0x8008E554: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    menu_unload_bigfont(rdram, ctx);
        goto after_7;
    // 0x8008E554: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_7:
    // 0x8008E558: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8008E55C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E560: sw          $zero, 0x7280($at)
    MEM_W(0X7280, ctx->r1) = 0;
    // 0x8008E564: addiu       $t7, $zero, 0x44
    ctx->r15 = ADD32(0, 0X44);
    // 0x8008E568: addiu       $t8, $zero, 0x4B
    ctx->r24 = ADD32(0, 0X4B);
    // 0x8008E56C: addiu       $t9, $zero, 0x52
    ctx->r25 = ADD32(0, 0X52);
    // 0x8008E570: sb          $t7, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r15;
    // 0x8008E574: sb          $t8, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r24;
    // 0x8008E578: sb          $t9, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r25;
    // 0x8008E57C: b           L_8008E744
    // 0x8008E580: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
        goto L_8008E744;
    // 0x8008E580: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
L_8008E584:
    // 0x8008E584: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8008E588: jal         0x8009824C
    // 0x8008E58C: nop

    filename_enter(rdram, ctx);
        goto after_8;
    // 0x8008E58C: nop

    after_8:
    // 0x8008E590: beq         $v0, $zero, L_8008E744
    if (ctx->r2 == 0) {
        // 0x8008E594: nop
    
            goto L_8008E744;
    }
    // 0x8008E594: nop

    // 0x8008E598: jal         0x80098724
    // 0x8008E59C: nop

    menu_unload_bigfont(rdram, ctx);
        goto after_9;
    // 0x8008E59C: nop

    after_9:
    // 0x8008E5A0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008E5A4: lw          $t4, -0x5B4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5B4);
    // 0x8008E5A8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E5AC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008E5B0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008E5B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E5B8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008E5BC: addiu       $t6, $t6, 0x6A40
    ctx->r14 = ADD32(ctx->r14, 0X6A40);
    // 0x8008E5C0: sw          $zero, 0x7280($at)
    MEM_W(0X7280, ctx->r1) = 0;
    // 0x8008E5C4: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8008E5C8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008E5CC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008E5D0: lw          $t7, -0x5EC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5EC);
    // 0x8008E5D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E5D8: beq         $t7, $zero, L_8008E5E8
    if (ctx->r15 == 0) {
        // 0x8008E5DC: addiu       $a0, $v0, 0x4
        ctx->r4 = ADD32(ctx->r2, 0X4);
            goto L_8008E5E8;
    }
    // 0x8008E5DC: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8008E5E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008E5E4: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
L_8008E5E8:
    // 0x8008E5E8: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8008E5EC: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008E5F0: jal         0x80097C80
    // 0x8008E5F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    filename_compress(rdram, ctx);
        goto after_10;
    // 0x8008E5F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x8008E5F8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8008E5FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E600: sw          $v0, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->r2;
    // 0x8008E604: lw          $a0, -0x5B4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B4);
    // 0x8008E608: jal         0x8006EDB8
    // 0x8008E60C: nop

    mark_read_save_file(rdram, ctx);
        goto after_11;
    // 0x8008E60C: nop

    after_11:
    // 0x8008E610: jal         0x80000C98
    // 0x8008E614: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_12;
    // 0x8008E614: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_12:
    // 0x8008E618: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E61C: jal         0x800C06F8
    // 0x8008E620: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_13;
    // 0x8008E620: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_13:
    // 0x8008E624: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8008E628: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E62C: b           L_8008E744
    // 0x8008E630: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
        goto L_8008E744;
    // 0x8008E630: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
L_8008E634:
    // 0x8008E634: jal         0x8008DAB0
    // 0x8008E638: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    fileselect_input_root(rdram, ctx);
        goto after_14;
    // 0x8008E638: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_14:
    // 0x8008E63C: beq         $v0, $zero, L_8008E744
    if (ctx->r2 == 0) {
        // 0x8008E640: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_8008E744;
    }
    // 0x8008E640: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008E644: blez        $v0, L_8008E720
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008E648: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8008E720;
    }
    // 0x8008E648: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008E64C: lw          $t1, -0x5B4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5B4);
    // 0x8008E650: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008E654: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8008E658: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x8008E65C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008E660: addiu       $t7, $t7, 0x6A40
    ctx->r15 = ADD32(ctx->r15, 0X6A40);
    // 0x8008E664: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8008E668: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8008E66C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008E670: beq         $t8, $zero, L_8008E6A4
    if (ctx->r24 == 0) {
        // 0x8008E674: addiu       $t3, $t3, 0x1530
        ctx->r11 = ADD32(ctx->r11, 0X1530);
            goto L_8008E6A4;
    }
    // 0x8008E674: addiu       $t3, $t3, 0x1530
    ctx->r11 = ADD32(ctx->r11, 0X1530);
    // 0x8008E678: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008E67C: jal         0x80001D04
    // 0x8008E680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x8008E680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x8008E684: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E688: lw          $a0, -0x5B4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B4);
    // 0x8008E68C: jal         0x8006EDB8
    // 0x8008E690: nop

    mark_read_save_file(rdram, ctx);
        goto after_16;
    // 0x8008E690: nop

    after_16:
    // 0x8008E694: jal         0x80000C98
    // 0x8008E698: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_17;
    // 0x8008E698: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_17:
    // 0x8008E69C: b           L_8008E724
    // 0x8008E6A0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
        goto L_8008E724;
    // 0x8008E6A0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8008E6A4:
    // 0x8008E6A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E6A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E6AC: sw          $t9, 0x7280($at)
    MEM_W(0X7280, ctx->r1) = ctx->r25;
    // 0x8008E6B0: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8008E6B4: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8008E6B8: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x8008E6BC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8008E6C0: bne         $t4, $zero, L_8008E6CC
    if (ctx->r12 != 0) {
        // 0x8008E6C4: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_8008E6CC;
    }
    // 0x8008E6C4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008E6C8: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
L_8008E6CC:
    // 0x8008E6CC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008E6D0: addiu       $t6, $t6, 0x94C
    ctx->r14 = ADD32(ctx->r14, 0X94C);
    // 0x8008E6D4: sll         $t5, $t1, 4
    ctx->r13 = S32(ctx->r9 << 4);
    // 0x8008E6D8: addiu       $t2, $t2, 0x97C
    ctx->r10 = ADD32(ctx->r10, 0X97C);
    // 0x8008E6DC: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x8008E6E0: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x8008E6E4: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x8008E6E8: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x8008E6EC: lh          $t9, 0x2($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X2);
    // 0x8008E6F0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8008E6F4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8008E6F8: addiu       $t6, $v0, 0x4
    ctx->r14 = ADD32(ctx->r2, 0X4);
    // 0x8008E6FC: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8008E700: addu        $a2, $t5, $t0
    ctx->r6 = ADD32(ctx->r13, ctx->r8);
    // 0x8008E704: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8008E708: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8008E70C: addiu       $a0, $t0, 0xBB
    ctx->r4 = ADD32(ctx->r8, 0XBB);
    // 0x8008E710: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008E714: jal         0x80097DB0
    // 0x8008E718: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    filename_init(rdram, ctx);
        goto after_18;
    // 0x8008E718: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_18:
    // 0x8008E71C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008E720:
    // 0x8008E720: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8008E724:
    // 0x8008E724: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E728: beq         $t8, $zero, L_8008E744
    if (ctx->r24 == 0) {
        // 0x8008E72C: nop
    
            goto L_8008E744;
    }
    // 0x8008E72C: nop

    // 0x8008E730: jal         0x800C06F8
    // 0x8008E734: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_19;
    // 0x8008E734: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_19:
    // 0x8008E738: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008E73C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E740: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
L_8008E744:
    // 0x8008E744: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008E748: addiu       $a2, $a2, -0x604
    ctx->r6 = ADD32(ctx->r6, -0X604);
    // 0x8008E74C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008E750: nop

    // 0x8008E754: slti        $at, $v0, 0x24
    ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
    // 0x8008E758: bne         $at, $zero, L_8008E8AC
    if (ctx->r1 != 0) {
        // 0x8008E75C: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_8008E8AC;
    }
    // 0x8008E75C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008E760: addiu       $a2, $a2, 0x318
    ctx->r6 = ADD32(ctx->r6, 0X318);
    // 0x8008E764: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8008E768: lui         $a0, 0xFBFF
    ctx->r4 = S32(0XFBFF << 16);
    // 0x8008E76C: sll         $t4, $v1, 5
    ctx->r12 = S32(ctx->r3 << 5);
    // 0x8008E770: bgez        $t4, L_8008E7B0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8008E774: ori         $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 | 0XFFFF;
            goto L_8008E7B0;
    }
    // 0x8008E774: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x8008E778: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008E77C: addiu       $a1, $a1, 0x31C
    ctx->r5 = ADD32(ctx->r5, 0X31C);
    // 0x8008E780: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8008E784: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8008E788: and         $t5, $v1, $a0
    ctx->r13 = ctx->r3 & ctx->r4;
    // 0x8008E78C: and         $t7, $t6, $a0
    ctx->r15 = ctx->r14 & ctx->r4;
    // 0x8008E790: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8008E794: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8008E798: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8008E79C: nop

    // 0x8008E7A0: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8008E7A4: nop

    // 0x8008E7A8: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x8008E7AC: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
L_8008E7B0:
    // 0x8008E7B0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008E7B4: lw          $t5, -0x5C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5C4);
    // 0x8008E7B8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008E7BC: xori        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 ^ 0X2;
    // 0x8008E7C0: addiu       $v0, $v0, -0x5C0
    ctx->r2 = ADD32(ctx->r2, -0X5C0);
    // 0x8008E7C4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8008E7C8: beq         $t6, $zero, L_8008E7D8
    if (ctx->r14 == 0) {
        // 0x8008E7CC: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_8008E7D8;
    }
    // 0x8008E7CC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008E7D0: jal         0x8000E1B8
    // 0x8008E7D4: nop

    reset_lead_player_index(rdram, ctx);
        goto after_20;
    // 0x8008E7D4: nop

    after_20:
L_8008E7D8:
    // 0x8008E7D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008E7DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E7E0: sw          $t8, -0x5C4($at)
    MEM_W(-0X5C4, ctx->r1) = ctx->r24;
    // 0x8008E7E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E7E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E7EC: jal         0x8008E8E0
    // 0x8008E7F0: sw          $t9, 0x152C($at)
    MEM_W(0X152C, ctx->r1) = ctx->r25;
    fileselect_free(rdram, ctx);
        goto after_21;
    // 0x8008E7F0: sw          $t9, 0x152C($at)
    MEM_W(0X152C, ctx->r1) = ctx->r25;
    after_21:
    // 0x8008E7F4: jal         0x80000B28
    // 0x8008E7F8: nop

    music_change_on(rdram, ctx);
        goto after_22;
    // 0x8008E7F8: nop

    after_22:
    // 0x8008E7FC: jal         0x8006E7FC
    // 0x8008E800: nop

    init_racer_headers(rdram, ctx);
        goto after_23;
    // 0x8008E800: nop

    after_23:
    // 0x8008E804: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8008E808: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E80C: sw          $zero, 0x1568($at)
    MEM_W(0X1568, ctx->r1) = 0;
    // 0x8008E810: lbu         $t4, 0x4B($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4B);
    // 0x8008E814: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008E818: beq         $t4, $zero, L_8008E878
    if (ctx->r12 == 0) {
        // 0x8008E81C: nop
    
            goto L_8008E878;
    }
    // 0x8008E81C: nop

    // 0x8008E820: lw          $t5, -0x5EC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5EC);
    // 0x8008E824: nop

    // 0x8008E828: beq         $t5, $zero, L_8008E840
    if (ctx->r13 == 0) {
        // 0x8008E82C: nop
    
            goto L_8008E840;
    }
    // 0x8008E82C: nop

    // 0x8008E830: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8008E834: nop

    // 0x8008E838: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x8008E83C: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
L_8008E840:
    // 0x8008E840: jal         0x8001E2D0
    // 0x8008E844: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    get_misc_asset(rdram, ctx);
        goto after_24;
    // 0x8008E844: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_24:
    // 0x8008E848: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008E84C: lw          $a2, -0x5C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5C4);
    // 0x8008E850: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008E854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008E858: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008E85C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008E860: jal         0x8009B114
    // 0x8008E864: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    cinematic_start(rdram, ctx);
        goto after_25;
    // 0x8008E864: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_25:
    // 0x8008E868: jal         0x80081820
    // 0x8008E86C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    menu_init(rdram, ctx);
        goto after_26;
    // 0x8008E86C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_26:
    // 0x8008E870: b           L_8008E8D0
    // 0x8008E874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008E8D0;
    // 0x8008E874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008E878:
    // 0x8008E878: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8008E87C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E880: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x8008E884: beq         $t9, $zero, L_8008E89C
    if (ctx->r25 == 0) {
        // 0x8008E888: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8008E89C;
    }
    // 0x8008E888: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008E88C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008E890: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E894: b           L_8008E8A0
    // 0x8008E898: sw          $t4, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r12;
        goto L_8008E8A0;
    // 0x8008E898: sw          $t4, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r12;
L_8008E89C:
    // 0x8008E89C: sw          $zero, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = 0;
L_8008E8A0:
    // 0x8008E8A0: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8008E8A4: b           L_8008E8D4
    // 0x8008E8A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8008E8D4;
    // 0x8008E8A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8008E8AC:
    // 0x8008E8AC: slti        $at, $v0, -0x23
    ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
    // 0x8008E8B0: beq         $at, $zero, L_8008E8D0
    if (ctx->r1 == 0) {
        // 0x8008E8B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008E8D0;
    }
    // 0x8008E8B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008E8B8: jal         0x8008E8E0
    // 0x8008E8BC: nop

    fileselect_free(rdram, ctx);
        goto after_27;
    // 0x8008E8BC: nop

    after_27:
    // 0x8008E8C0: jal         0x80081820
    // 0x8008E8C4: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    menu_init(rdram, ctx);
        goto after_28;
    // 0x8008E8C4: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_28:
    // 0x8008E8C8: b           L_8008E8D0
    // 0x8008E8CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008E8D0;
    // 0x8008E8CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008E8D0:
    // 0x8008E8D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8008E8D4:
    // 0x8008E8D4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8008E8D8: jr          $ra
    // 0x8008E8DC: nop

    return;
    // 0x8008E8DC: nop

;}
RECOMP_FUNC void fileselect_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E8E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E8E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E8E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E8EC: jal         0x8009C9EC
    // 0x8008E8F0: addiu       $a0, $a0, 0x918
    ctx->r4 = ADD32(ctx->r4, 0X918);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8008E8F0: addiu       $a0, $a0, 0x918
    ctx->r4 = ADD32(ctx->r4, 0X918);
    after_0:
    // 0x8008E8F4: jal         0x800803D8
    // 0x8008E8F8: nop

    menu_button_free(rdram, ctx);
        goto after_1;
    // 0x8008E8F8: nop

    after_1:
    // 0x8008E8FC: jal         0x800C478C
    // 0x8008E900: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_2;
    // 0x8008E900: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8008E904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E90C: jr          $ra
    // 0x8008E910: nop

    return;
    // 0x8008E910: nop

;}
RECOMP_FUNC void menu_init_vehicle_textures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E914: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008E918: addiu       $v1, $v1, 0x6AF0
    ctx->r3 = ADD32(ctx->r3, 0X6AF0);
    // 0x8008E91C: lw          $t6, 0x60($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X60);
    // 0x8008E920: lw          $t7, 0x64($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X64);
    // 0x8008E924: lw          $t8, 0x68($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X68);
    // 0x8008E928: lw          $t9, 0x6C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6C);
    // 0x8008E92C: lw          $t0, 0x70($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X70);
    // 0x8008E930: lw          $t1, 0x74($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X74);
    // 0x8008E934: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008E938: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E93C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008E940: addiu       $a1, $a1, 0xA0C
    ctx->r5 = ADD32(ctx->r5, 0XA0C);
    // 0x8008E944: addiu       $a0, $a0, 0x9F4
    ctx->r4 = ADD32(ctx->r4, 0X9F4);
    // 0x8008E948: addiu       $v0, $v0, 0x9DC
    ctx->r2 = ADD32(ctx->r2, 0X9DC);
    // 0x8008E94C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008E950: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8008E954: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8008E958: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8008E95C: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8008E960: jr          $ra
    // 0x8008E964: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    return;
    // 0x8008E964: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void menu_init_arrow_textures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E968: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008E96C: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
    // 0x8008E970: lw          $t6, 0xF4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF4);
    // 0x8008E974: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E978: sw          $t6, 0x99C($at)
    MEM_W(0X99C, ctx->r1) = ctx->r14;
    // 0x8008E97C: lw          $t7, 0xF0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XF0);
    // 0x8008E980: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E984: sw          $t7, 0x9AC($at)
    MEM_W(0X9AC, ctx->r1) = ctx->r15;
    // 0x8008E988: lw          $t8, 0xFC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XFC);
    // 0x8008E98C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E990: sw          $t8, 0x9BC($at)
    MEM_W(0X9BC, ctx->r1) = ctx->r24;
    // 0x8008E994: lw          $t9, 0xF8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XF8);
    // 0x8008E998: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E99C: jr          $ra
    // 0x8008E9A0: sw          $t9, 0x9CC($at)
    MEM_W(0X9CC, ctx->r1) = ctx->r25;
    return;
    // 0x8008E9A0: sw          $t9, 0x9CC($at)
    MEM_W(0X9CC, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void menu_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E9A4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8008E9A8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E9AC: lw          $t6, 0x6964($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6964);
    // 0x8008E9B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008E9B4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8008E9B8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008E9BC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008E9C0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008E9C4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008E9C8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008E9CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008E9D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008E9D4: bne         $t6, $zero, L_8008EB74
    if (ctx->r14 != 0) {
        // 0x8008E9D8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8008EB74;
    }
    // 0x8008E9D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008E9DC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008E9E0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008E9E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008E9E8: addiu       $v0, $v0, 0x6DDA
    ctx->r2 = ADD32(ctx->r2, 0X6DDA);
    // 0x8008E9EC: addiu       $s1, $s1, 0x6DD0
    ctx->r17 = ADD32(ctx->r17, 0X6DD0);
    // 0x8008E9F0: addiu       $s2, $s2, 0x6DB8
    ctx->r18 = ADD32(ctx->r18, 0X6DB8);
    // 0x8008E9F4: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
L_8008E9F8:
    // 0x8008E9F8: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8008E9FC: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x8008EA00: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008EA04: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8008EA08: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x8008EA0C: sh          $zero, -0x2($s2)
    MEM_H(-0X2, ctx->r18) = 0;
    // 0x8008EA10: bne         $at, $zero, L_8008E9F8
    if (ctx->r1 != 0) {
        // 0x8008EA14: sh          $zero, -0x2($s1)
        MEM_H(-0X2, ctx->r17) = 0;
            goto L_8008E9F8;
    }
    // 0x8008EA14: sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    // 0x8008EA18: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008EA1C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008EA20: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008EA24: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008EA28: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8008EA2C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008EA30: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008EA34: addiu       $s6, $s6, 0x6DB8
    ctx->r22 = ADD32(ctx->r22, 0X6DB8);
    // 0x8008EA38: addiu       $s7, $s7, 0x6DD0
    ctx->r23 = ADD32(ctx->r23, 0X6DD0);
    // 0x8008EA3C: addiu       $fp, $fp, -0x5C4
    ctx->r30 = ADD32(ctx->r30, -0X5C4);
    // 0x8008EA40: addiu       $s5, $s5, 0x6A04
    ctx->r21 = ADD32(ctx->r21, 0X6A04);
    // 0x8008EA44: addiu       $s4, $s4, 0x69FC
    ctx->r20 = ADD32(ctx->r20, 0X69FC);
    // 0x8008EA48: addiu       $s1, $s1, 0x6DD0
    ctx->r17 = ADD32(ctx->r17, 0X6DD0);
    // 0x8008EA4C: addiu       $s2, $s2, 0x6DB8
    ctx->r18 = ADD32(ctx->r18, 0X6DB8);
    // 0x8008EA50: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008EA54: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
L_8008EA58:
    // 0x8008EA58: jal         0x8006A768
    // 0x8008EA5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    input_held(rdram, ctx);
        goto after_0;
    // 0x8008EA5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x8008EA60: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x8008EA64: lb          $v1, 0x0($s4)
    ctx->r3 = MEM_B(ctx->r20, 0X0);
    // 0x8008EA68: lb          $a0, 0x0($s5)
    ctx->r4 = MEM_B(ctx->r21, 0X0);
    // 0x8008EA6C: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008EA70: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8008EA74: sh          $v1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r3;
    // 0x8008EA78: beq         $at, $zero, L_8008EAA4
    if (ctx->r1 == 0) {
        // 0x8008EA7C: sh          $a0, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r4;
            goto L_8008EAA4;
    }
    // 0x8008EA7C: sh          $a0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r4;
    // 0x8008EA80: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8008EA84: lh          $t2, 0x8($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X8);
    // 0x8008EA88: lh          $t4, 0x8($s7)
    ctx->r12 = MEM_H(ctx->r23, 0X8);
    // 0x8008EA8C: or          $t1, $t8, $v0
    ctx->r9 = ctx->r24 | ctx->r2;
    // 0x8008EA90: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8008EA94: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x8008EA98: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x8008EA9C: sh          $t3, 0x8($s6)
    MEM_H(0X8, ctx->r22) = ctx->r11;
    // 0x8008EAA0: sh          $t5, 0x8($s7)
    MEM_H(0X8, ctx->r23) = ctx->r13;
L_8008EAA4:
    // 0x8008EAA4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8008EAA8: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8008EAAC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008EAB0: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8008EAB4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8008EAB8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8008EABC: bne         $at, $zero, L_8008EA58
    if (ctx->r1 != 0) {
        // 0x8008EAC0: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8008EA58;
    }
    // 0x8008EAC0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8008EAC4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008EAC8: lw          $t6, 0x6D90($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D90);
    // 0x8008EACC: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x8008EAD0: nor         $t7, $t6, $zero
    ctx->r15 = ~(ctx->r14 | 0);
    // 0x8008EAD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EAD8: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x8008EADC: sw          $t8, 0x6D78($at)
    MEM_W(0X6D78, ctx->r1) = ctx->r24;
    // 0x8008EAE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EAE4: sw          $v0, 0x6D90($at)
    MEM_W(0X6D90, ctx->r1) = ctx->r2;
    // 0x8008EAE8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008EAEC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008EAF0: addiu       $t1, $t1, 0x6D90
    ctx->r9 = ADD32(ctx->r9, 0X6D90);
    // 0x8008EAF4: sll         $a0, $s3, 2
    ctx->r4 = S32(ctx->r19 << 2);
    // 0x8008EAF8: addu        $v0, $a0, $t1
    ctx->r2 = ADD32(ctx->r4, ctx->r9);
    // 0x8008EAFC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8008EB00: addiu       $t2, $sp, 0x60
    ctx->r10 = ADD32(ctx->r29, 0X60);
    // 0x8008EB04: addu        $s0, $a0, $t2
    ctx->r16 = ADD32(ctx->r4, ctx->r10);
    // 0x8008EB08: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008EB0C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8008EB10: addiu       $t9, $t9, 0x6D78
    ctx->r25 = ADD32(ctx->r25, 0X6D78);
    // 0x8008EB14: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x8008EB18: addu        $v1, $a0, $t9
    ctx->r3 = ADD32(ctx->r4, ctx->r25);
    // 0x8008EB1C: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8008EB20: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8008EB24: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8008EB28: and         $t5, $t4, $a1
    ctx->r13 = ctx->r12 & ctx->r5;
    // 0x8008EB2C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8008EB30: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8008EB34: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x8008EB38: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8008EB3C: nor         $t1, $t9, $zero
    ctx->r9 = ~(ctx->r25 | 0);
    // 0x8008EB40: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x8008EB44: nor         $t7, $t6, $zero
    ctx->r15 = ~(ctx->r14 | 0);
    // 0x8008EB48: and         $t8, $t7, $a2
    ctx->r24 = ctx->r15 & ctx->r6;
    // 0x8008EB4C: and         $t2, $t1, $a3
    ctx->r10 = ctx->r9 & ctx->r7;
    // 0x8008EB50: and         $t5, $t4, $t0
    ctx->r13 = ctx->r12 & ctx->r8;
    // 0x8008EB54: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x8008EB58: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8008EB5C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8008EB60: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8008EB64: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8008EB68: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x8008EB6C: b           L_8008EC18
    // 0x8008EB70: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
        goto L_8008EC18;
    // 0x8008EB70: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
L_8008EB74:
    // 0x8008EB74: ori         $t6, $zero, 0xD000
    ctx->r14 = 0 | 0XD000;
    // 0x8008EB78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EB7C: sw          $t6, 0x6D90($at)
    MEM_W(0X6D90, ctx->r1) = ctx->r14;
    // 0x8008EB80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EB84: sw          $zero, 0x6D78($at)
    MEM_W(0X6D78, ctx->r1) = 0;
    // 0x8008EB88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EB8C: sh          $zero, 0x6DB8($at)
    MEM_H(0X6DB8, ctx->r1) = 0;
    // 0x8008EB90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EB94: sh          $zero, 0x6DD0($at)
    MEM_H(0X6DD0, ctx->r1) = 0;
    // 0x8008EB98: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008EB9C: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008EBA0: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008EBA4: sll         $a0, $s3, 2
    ctx->r4 = S32(ctx->r19 << 2);
    // 0x8008EBA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008EBAC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008EBB0: sll         $a1, $s3, 1
    ctx->r5 = S32(ctx->r19 << 1);
    // 0x8008EBB4: addiu       $s7, $s7, 0x6DD0
    ctx->r23 = ADD32(ctx->r23, 0X6DD0);
    // 0x8008EBB8: addiu       $s6, $s6, 0x6DB8
    ctx->r22 = ADD32(ctx->r22, 0X6DB8);
    // 0x8008EBBC: addiu       $t7, $t7, 0x6D90
    ctx->r15 = ADD32(ctx->r15, 0X6D90);
    // 0x8008EBC0: addiu       $t8, $t8, 0x6D78
    ctx->r24 = ADD32(ctx->r24, 0X6D78);
    // 0x8008EBC4: ori         $a2, $zero, 0xD000
    ctx->r6 = 0 | 0XD000;
    // 0x8008EBC8: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x8008EBCC: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x8008EBD0: addu        $s2, $s6, $a1
    ctx->r18 = ADD32(ctx->r22, ctx->r5);
    // 0x8008EBD4: addu        $s1, $s7, $a1
    ctx->r17 = ADD32(ctx->r23, ctx->r5);
    // 0x8008EBD8: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x8008EBDC: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // 0x8008EBE0: sh          $zero, 0x6($s1)
    MEM_H(0X6, ctx->r17) = 0;
    // 0x8008EBE4: sh          $zero, 0x2($s2)
    MEM_H(0X2, ctx->r18) = 0;
    // 0x8008EBE8: sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // 0x8008EBEC: sh          $zero, 0x6($s2)
    MEM_H(0X6, ctx->r18) = 0;
    // 0x8008EBF0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8008EBF4: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8008EBF8: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8008EBFC: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8008EC00: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    // 0x8008EC04: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // 0x8008EC08: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8008EC0C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8008EC10: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x8008EC14: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_8008EC18:
    // 0x8008EC18: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008EC1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008EC20: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008EC24: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008EC28: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008EC2C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008EC30: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EC34: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008EC38: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008EC3C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8008EC40: jr          $ra
    // 0x8008EC44: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8008EC44: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void trackmenu_active(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EC48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008EC4C: lw          $v0, 0xEFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XEFC);
    // 0x8008EC50: jr          $ra
    // 0x8008EC54: nop

    return;
    // 0x8008EC54: nop

;}
RECOMP_FUNC void menu_track_select_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EC58: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8008EC5C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8008EC60: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8008EC64: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8008EC68: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8008EC6C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8008EC70: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8008EC74: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008EC78: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8008EC7C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8008EC80: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008EC84: jal         0x800C46D0
    // 0x8008EC88: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_0;
    // 0x8008EC88: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008EC8C: jal         0x8006ECD0
    // 0x8008EC90: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x8008EC90: nop

    after_1:
    // 0x8008EC94: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8008EC98: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8008EC9C: jal         0x8006B464
    // 0x8008ECA0: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    level_count(rdram, ctx);
        goto after_2;
    // 0x8008ECA0: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_2:
    // 0x8008ECA4: jal         0x8001E2D0
    // 0x8008ECA8: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x8008ECA8: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_3:
    // 0x8008ECAC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008ECB0: addiu       $v1, $v1, -0x5F8
    ctx->r3 = ADD32(ctx->r3, -0X5F8);
    // 0x8008ECB4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008ECB8: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x8008ECBC: beq         $t6, $zero, L_8008ECE4
    if (ctx->r14 == 0) {
        // 0x8008ECC0: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008ECE4;
    }
    // 0x8008ECC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ECC4: sw          $zero, 0x6F88($at)
    MEM_W(0X6F88, ctx->r1) = 0;
    // 0x8008ECC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ECCC: sw          $zero, 0x6F8C($at)
    MEM_W(0X6F8C, ctx->r1) = 0;
    // 0x8008ECD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008ECD4: sw          $zero, 0x994($at)
    MEM_W(0X994, ctx->r1) = 0;
    // 0x8008ECD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008ECDC: sw          $zero, 0x998($at)
    MEM_W(0X998, ctx->r1) = 0;
    // 0x8008ECE0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8008ECE4:
    // 0x8008ECE4: jal         0x8007A970
    // 0x8008ECE8: nop

    fb_size(rdram, ctx);
        goto after_4;
    // 0x8008ECE8: nop

    after_4:
    // 0x8008ECEC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008ECF0: addiu       $a2, $a2, 0x6A1C
    ctx->r6 = ADD32(ctx->r6, 0X6A1C);
    // 0x8008ECF4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008ECF8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8008ECFC: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x8008ED00: addiu       $a3, $a3, 0x6A20
    ctx->r7 = ADD32(ctx->r7, 0X6A20);
    // 0x8008ED04: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8008ED08: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8008ED0C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8008ED10: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8008ED14: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8008ED18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ED1C: sw          $t2, 0x6A14($at)
    MEM_W(0X6A14, ctx->r1) = ctx->r10;
    // 0x8008ED20: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x8008ED24: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008ED28: addiu       $fp, $fp, 0x6A18
    ctx->r30 = ADD32(ctx->r30, 0X6A18);
    // 0x8008ED2C: sra         $t3, $a1, 1
    ctx->r11 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8008ED30: sw          $t3, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r11;
    // 0x8008ED34: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008ED38: lw          $t4, 0x6F88($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6F88);
    // 0x8008ED3C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008ED40: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8008ED44: lw          $t5, 0x6F8C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6F8C);
    // 0x8008ED48: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008ED4C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8008ED50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008ED54: negu        $t6, $a1
    ctx->r14 = SUB32(0, ctx->r5);
    // 0x8008ED58: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8008ED5C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8008ED60: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8008ED64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ED68: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x8008ED6C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8008ED70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008ED74: swc1        $f10, 0x6F9C($at)
    MEM_W(0X6F9C, ctx->r1) = ctx->f10.u32l;
    // 0x8008ED78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ED7C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008ED80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008ED84: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8008ED88: swc1        $f8, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f8.u32l;
    // 0x8008ED8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ED90: sw          $s5, 0x6FB4($at)
    MEM_W(0X6FB4, ctx->r1) = ctx->r21;
    // 0x8008ED94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ED98: sw          $s5, 0x6FB8($at)
    MEM_W(0X6FB8, ctx->r1) = ctx->r21;
    // 0x8008ED9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EDA0: sw          $s5, 0x6970($at)
    MEM_W(0X6970, ctx->r1) = ctx->r21;
    // 0x8008EDA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EDA8: sw          $t7, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r15;
    // 0x8008EDAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EDB0: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8008EDB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EDB8: jal         0x8008F4C4
    // 0x8008EDBC: sw          $s5, 0x6D70($at)
    MEM_W(0X6D70, ctx->r1) = ctx->r21;
    trackmenu_assets(rdram, ctx);
        goto after_5;
    // 0x8008EDBC: sw          $s5, 0x6D70($at)
    MEM_W(0X6D70, ctx->r1) = ctx->r21;
    after_5:
    // 0x8008EDC0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008EDC4: jal         0x800C06F8
    // 0x8008EDC8: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_6;
    // 0x8008EDC8: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_6:
    // 0x8008EDCC: jal         0x800C0690
    // 0x8008EDD0: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_7;
    // 0x8008EDD0: nop

    after_7:
    // 0x8008EDD4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8008EDD8: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x8008EDDC: jal         0x80077FAC
    // 0x8008EDE0: addiu       $a2, $zero, 0xDF
    ctx->r6 = ADD32(0, 0XDF);
    bgdraw_fillcolour(rdram, ctx);
        goto after_8;
    // 0x8008EDE0: addiu       $a2, $zero, 0xDF
    ctx->r6 = ADD32(0, 0XDF);
    after_8:
    // 0x8008EDE4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8008EDE8: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008EDEC: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8008EDF0: addiu       $s2, $s2, 0xCB0
    ctx->r18 = ADD32(ctx->r18, 0XCB0);
    // 0x8008EDF4: addiu       $s6, $s6, 0x6AF0
    ctx->r22 = ADD32(ctx->r22, 0X6AF0);
    // 0x8008EDF8: addiu       $s1, $s1, 0xC90
    ctx->r17 = ADD32(ctx->r17, 0XC90);
    // 0x8008EDFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008EE00:
    // 0x8008EE00: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x8008EE04: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8008EE08: beq         $s5, $a0, L_8008EE3C
    if (ctx->r21 == ctx->r4) {
        // 0x8008EE0C: addu        $s0, $s2, $t6
        ctx->r16 = ADD32(ctx->r18, ctx->r14);
            goto L_8008EE3C;
    }
    // 0x8008EE0C: addu        $s0, $s2, $t6
    ctx->r16 = ADD32(ctx->r18, ctx->r14);
    // 0x8008EE10: jal         0x8009CC18
    // 0x8008EE14: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    menu_asset_load(rdram, ctx);
        goto after_9;
    // 0x8008EE14: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    after_9:
    // 0x8008EE18: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x8008EE1C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8008EE20: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8008EE24: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x8008EE28: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8008EE2C: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x8008EE30: addu        $s0, $s2, $t9
    ctx->r16 = ADD32(ctx->r18, ctx->r25);
    // 0x8008EE34: b           L_8008EE40
    // 0x8008EE38: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
        goto L_8008EE40;
    // 0x8008EE38: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_8008EE3C:
    // 0x8008EE3C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8008EE40:
    // 0x8008EE40: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x8008EE44: nop

    // 0x8008EE48: beq         $s5, $a0, L_8008EE74
    if (ctx->r21 == ctx->r4) {
        // 0x8008EE4C: nop
    
            goto L_8008EE74;
    }
    // 0x8008EE4C: nop

    // 0x8008EE50: jal         0x8009CC18
    // 0x8008EE54: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    menu_asset_load(rdram, ctx);
        goto after_10;
    // 0x8008EE54: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    after_10:
    // 0x8008EE58: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x8008EE5C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8008EE60: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008EE64: addu        $t9, $s6, $t8
    ctx->r25 = ADD32(ctx->r22, ctx->r24);
    // 0x8008EE68: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8008EE6C: b           L_8008EE78
    // 0x8008EE70: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
        goto L_8008EE78;
    // 0x8008EE70: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
L_8008EE74:
    // 0x8008EE74: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8008EE78:
    // 0x8008EE78: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008EE7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008EE80: bne         $a1, $at, L_8008EE00
    if (ctx->r5 != ctx->r1) {
        // 0x8008EE84: addiu       $s1, $s1, 0x6
        ctx->r17 = ADD32(ctx->r17, 0X6);
            goto L_8008EE00;
    }
    // 0x8008EE84: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x8008EE88: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8008EE8C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8008EE90: jal         0x80070EDC
    // 0x8008EE94: addiu       $a0, $zero, 0xB40
    ctx->r4 = ADD32(0, 0XB40);
    mempool_alloc_safe(rdram, ctx);
        goto after_11;
    // 0x8008EE94: addiu       $a0, $zero, 0xB40
    ctx->r4 = ADD32(0, 0XB40);
    after_11:
    // 0x8008EE98: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008EE9C: addiu       $a1, $a1, 0xEF0
    ctx->r5 = ADD32(ctx->r5, 0XEF0);
    // 0x8008EEA0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8008EEA4: addiu       $t3, $v0, 0x280
    ctx->r11 = ADD32(ctx->r2, 0X280);
    // 0x8008EEA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008EEAC: sw          $t3, 0xEF4($at)
    MEM_W(0XEF4, ctx->r1) = ctx->r11;
    // 0x8008EEB0: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    // 0x8008EEB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008EEB8: addiu       $t5, $t4, 0x280
    ctx->r13 = ADD32(ctx->r12, 0X280);
    // 0x8008EEBC: sw          $t5, 0xEE8($at)
    MEM_W(0XEE8, ctx->r1) = ctx->r13;
    // 0x8008EEC0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008EEC4: lw          $t6, 0xEE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XEE8);
    // 0x8008EEC8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008EECC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008EED0: addiu       $t7, $t6, 0x320
    ctx->r15 = ADD32(ctx->r14, 0X320);
    // 0x8008EED4: sw          $t7, 0xEEC($at)
    MEM_W(0XEEC, ctx->r1) = ctx->r15;
    // 0x8008EED8: addiu       $a0, $zero, -0xA0
    ctx->r4 = ADD32(0, -0XA0);
    // 0x8008EEDC: addiu       $t0, $t0, 0xEF0
    ctx->r8 = ADD32(ctx->r8, 0XEF0);
    // 0x8008EEE0: addiu       $v1, $v1, 0xEE8
    ctx->r3 = ADD32(ctx->r3, 0XEE8);
    // 0x8008EEE4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008EEE8: addiu       $a3, $zero, 0x320
    ctx->r7 = ADD32(0, 0X320);
    // 0x8008EEEC: addiu       $a2, $zero, -0x400
    ctx->r6 = ADD32(0, -0X400);
    // 0x8008EEF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008EEF4:
    // 0x8008EEF4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008EEF8: nop

    // 0x8008EEFC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008EF00: sh          $a0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r4;
    // 0x8008EF04: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF08: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8008EF0C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8008EF10: sh          $a2, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r6;
    // 0x8008EF14: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF18: nop

    // 0x8008EF1C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8008EF20: sb          $a1, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r5;
    // 0x8008EF24: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF28: nop

    // 0x8008EF2C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8008EF30: sb          $a1, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r5;
    // 0x8008EF34: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF38: nop

    // 0x8008EF3C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8008EF40: sb          $a1, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r5;
    // 0x8008EF44: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF48: nop

    // 0x8008EF4C: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8008EF50: sh          $a0, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r4;
    // 0x8008EF54: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF58: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8008EF5C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8008EF60: sh          $a2, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r6;
    // 0x8008EF64: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF68: nop

    // 0x8008EF6C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8008EF70: sb          $a1, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r5;
    // 0x8008EF74: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF78: nop

    // 0x8008EF7C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8008EF80: sb          $a1, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r5;
    // 0x8008EF84: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF88: nop

    // 0x8008EF8C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008EF90: sb          $a1, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r5;
    // 0x8008EF94: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8008EF98: nop

    // 0x8008EF9C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8008EFA0: sh          $a0, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r4;
    // 0x8008EFA4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8008EFA8: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8008EFAC: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8008EFB0: sh          $a2, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r6;
    // 0x8008EFB4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8008EFB8: nop

    // 0x8008EFBC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8008EFC0: sb          $a1, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r5;
    // 0x8008EFC4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8008EFC8: nop

    // 0x8008EFCC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8008EFD0: sb          $a1, 0x1B($t8)
    MEM_B(0X1B, ctx->r24) = ctx->r5;
    // 0x8008EFD4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008EFD8: nop

    // 0x8008EFDC: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8008EFE0: sb          $a1, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = ctx->r5;
    // 0x8008EFE4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8008EFE8: nop

    // 0x8008EFEC: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8008EFF0: sh          $a0, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r4;
    // 0x8008EFF4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008EFF8: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8008EFFC: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8008F000: sh          $a2, 0x22($t5)
    MEM_H(0X22, ctx->r13) = ctx->r6;
    // 0x8008F004: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008F008: nop

    // 0x8008F00C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8008F010: sb          $a1, 0x24($t7)
    MEM_B(0X24, ctx->r15) = ctx->r5;
    // 0x8008F014: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008F018: nop

    // 0x8008F01C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008F020: sb          $a1, 0x25($t9)
    MEM_B(0X25, ctx->r25) = ctx->r5;
    // 0x8008F024: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8008F028: nop

    // 0x8008F02C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8008F030: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x8008F034: bne         $v0, $a3, L_8008EEF4
    if (ctx->r2 != ctx->r7) {
        // 0x8008F038: sb          $a1, 0x26($t2)
        MEM_B(0X26, ctx->r10) = ctx->r5;
            goto L_8008EEF4;
    }
    // 0x8008F038: sb          $a1, 0x26($t2)
    MEM_B(0X26, ctx->r10) = ctx->r5;
    // 0x8008F03C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008F040: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8008F044: bne         $at, $zero, L_8008EEF4
    if (ctx->r1 != 0) {
        // 0x8008F048: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008EEF4;
    }
    // 0x8008F048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008F04C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F050: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008F054: addiu       $t0, $t0, 0xEF8
    ctx->r8 = ADD32(ctx->r8, 0XEF8);
    // 0x8008F058: addiu       $v1, $v1, 0xEF0
    ctx->r3 = ADD32(ctx->r3, 0XEF0);
    // 0x8008F05C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8008F060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008F064: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8008F068: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8008F06C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F070:
    // 0x8008F070: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8008F074: nop

    // 0x8008F078: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8008F07C: sb          $a0, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r4;
    // 0x8008F080: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8008F084: nop

    // 0x8008F088: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8008F08C: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x8008F090: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8008F094: nop

    // 0x8008F098: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8008F09C: sb          $a1, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r5;
    // 0x8008F0A0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008F0A4: nop

    // 0x8008F0A8: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8008F0AC: sb          $a2, 0x3($t1)
    MEM_B(0X3, ctx->r9) = ctx->r6;
    // 0x8008F0B0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8008F0B4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8008F0B8: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8008F0BC: sb          $a0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r4;
    // 0x8008F0C0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008F0C4: nop

    // 0x8008F0C8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8008F0CC: sb          $a2, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r6;
    // 0x8008F0D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008F0D4: nop

    // 0x8008F0D8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8008F0DC: sb          $a1, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r5;
    // 0x8008F0E0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008F0E4: nop

    // 0x8008F0E8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008F0EC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8008F0F0: slti        $at, $v0, 0x280
    ctx->r1 = SIGNED(ctx->r2) < 0X280 ? 1 : 0;
    // 0x8008F0F4: bne         $at, $zero, L_8008F070
    if (ctx->r1 != 0) {
        // 0x8008F0F8: sb          $a3, 0x3($t9)
        MEM_B(0X3, ctx->r25) = ctx->r7;
            goto L_8008F070;
    }
    // 0x8008F0F8: sb          $a3, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r7;
    // 0x8008F0FC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008F100: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8008F104: bne         $at, $zero, L_8008F070
    if (ctx->r1 != 0) {
        // 0x8008F108: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008F070;
    }
    // 0x8008F108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008F10C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F110: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8008F114: sw          $zero, 0x6EE4($at)
    MEM_W(0X6EE4, ctx->r1) = 0;
    // 0x8008F118: jal         0x80078EFC
    // 0x8008F11C: addiu       $a0, $a0, -0x530
    ctx->r4 = ADD32(ctx->r4, -0X530);
    bgdraw_set_func(rdram, ctx);
        goto after_12;
    // 0x8008F11C: addiu       $a0, $a0, -0x530
    ctx->r4 = ADD32(ctx->r4, -0X530);
    after_12:
    // 0x8008F120: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8008F124: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F128: sra         $v1, $v0, 1
    ctx->r3 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008F12C: addu        $t1, $v1, $v0
    ctx->r9 = ADD32(ctx->r3, ctx->r2);
    // 0x8008F130: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008F134: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x8008F138: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x8008F13C: jal         0x80066B80
    // 0x8008F140: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    viewport_menu_set(rdram, ctx);
        goto after_13;
    // 0x8008F140: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    after_13:
    // 0x8008F144: jal         0x80066850
    // 0x8008F148: nop

    copy_viewports_to_stack(rdram, ctx);
        goto after_14;
    // 0x8008F148: nop

    after_14:
    // 0x8008F14C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F150: jal         0x80066A58
    // 0x8008F154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camEnableUserView(rdram, ctx);
        goto after_15;
    // 0x8008F154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x8008F158: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008F15C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F160: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F164: sw          $t2, 0xEFC($at)
    MEM_W(0XEFC, ctx->r1) = ctx->r10;
    // 0x8008F168: jal         0x8009CBB8
    // 0x8008F16C: addiu       $a0, $a0, 0xD44
    ctx->r4 = ADD32(ctx->r4, 0XD44);
    menu_assetgroup_load(rdram, ctx);
        goto after_16;
    // 0x8008F16C: addiu       $a0, $a0, 0xD44
    ctx->r4 = ADD32(ctx->r4, 0XD44);
    after_16:
    // 0x8008F170: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F174: jal         0x8009CDE8
    // 0x8008F178: addiu       $a0, $a0, 0xD60
    ctx->r4 = ADD32(ctx->r4, 0XD60);
    menu_imagegroup_load(rdram, ctx);
        goto after_17;
    // 0x8008F178: addiu       $a0, $a0, 0xD60
    ctx->r4 = ADD32(ctx->r4, 0XD60);
    after_17:
    // 0x8008F17C: jal         0x8008E968
    // 0x8008F180: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_18;
    // 0x8008F180: nop

    after_18:
    // 0x8008F184: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008F188: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F18C: addiu       $v1, $v1, 0xB74
    ctx->r3 = ADD32(ctx->r3, 0XB74);
    // 0x8008F190: addiu       $v0, $v0, 0xB54
    ctx->r2 = ADD32(ctx->r2, 0XB54);
    // 0x8008F194: lw          $t3, 0x20($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X20);
    // 0x8008F198: lw          $t4, 0x24($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X24);
    // 0x8008F19C: lw          $t5, 0x28($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X28);
    // 0x8008F1A0: lw          $t6, 0x2C($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X2C);
    // 0x8008F1A4: lw          $t7, 0x30($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X30);
    // 0x8008F1A8: lw          $t8, 0x34($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X34);
    // 0x8008F1AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008F1B0: addiu       $t9, $t9, 0x6EA8
    ctx->r25 = ADD32(ctx->r25, 0X6EA8);
    // 0x8008F1B4: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8008F1B8: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8008F1BC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008F1C0: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x8008F1C4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8008F1C8: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
    // 0x8008F1CC: sw          $t5, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r13;
    // 0x8008F1D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8008F1D4: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x8008F1D8: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
L_8008F1DC:
    // 0x8008F1DC: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8008F1E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008F1E4: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
L_8008F1E8:
    // 0x8008F1E8: bne         $s1, $zero, L_8008F218
    if (ctx->r17 != 0) {
        // 0x8008F1EC: sh          $s5, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r21;
            goto L_8008F218;
    }
    // 0x8008F1EC: sh          $s5, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r21;
    // 0x8008F1F0: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8008F1F4: beq         $at, $zero, L_8008F21C
    if (ctx->r1 == 0) {
        // 0x8008F1F8: slti        $at, $s1, 0x4
        ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
            goto L_8008F21C;
    }
    // 0x8008F1F8: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8008F1FC: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F200: mflo        $t1
    ctx->r9 = lo;
    // 0x8008F204: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8008F208: addu        $t3, $t2, $s7
    ctx->r11 = ADD32(ctx->r10, ctx->r23);
    // 0x8008F20C: lb          $t4, 0x0($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X0);
    // 0x8008F210: b           L_8008F33C
    // 0x8008F214: sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
        goto L_8008F33C;
    // 0x8008F214: sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
L_8008F218:
    // 0x8008F218: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
L_8008F21C:
    // 0x8008F21C: beq         $at, $zero, L_8008F26C
    if (ctx->r1 == 0) {
        // 0x8008F220: nop
    
            goto L_8008F26C;
    }
    // 0x8008F220: nop

    // 0x8008F224: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F228: mflo        $t5
    ctx->r13 = lo;
    // 0x8008F22C: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x8008F230: addu        $t7, $t6, $s7
    ctx->r15 = ADD32(ctx->r14, ctx->r23);
    // 0x8008F234: lb          $v0, 0x0($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X0);
    // 0x8008F238: nop

    // 0x8008F23C: beq         $s5, $v0, L_8008F33C
    if (ctx->r21 == ctx->r2) {
        // 0x8008F240: nop
    
            goto L_8008F33C;
    }
    // 0x8008F240: nop

    // 0x8008F244: lw          $t8, 0x4($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X4);
    // 0x8008F248: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8008F24C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8008F250: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8008F254: nop

    // 0x8008F258: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8008F25C: beq         $t3, $zero, L_8008F33C
    if (ctx->r11 == 0) {
        // 0x8008F260: nop
    
            goto L_8008F33C;
    }
    // 0x8008F260: nop

    // 0x8008F264: b           L_8008F33C
    // 0x8008F268: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
        goto L_8008F33C;
    // 0x8008F268: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_8008F26C:
    // 0x8008F26C: bne         $s1, $s6, L_8008F304
    if (ctx->r17 != ctx->r22) {
        // 0x8008F270: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8008F304;
    }
    // 0x8008F270: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008F274: sll         $a2, $s3, 2
    ctx->r6 = S32(ctx->r19 << 2);
    // 0x8008F278: subu        $a2, $a2, $s3
    ctx->r6 = SUB32(ctx->r6, ctx->r19);
    // 0x8008F27C: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8008F280: addu        $v0, $a2, $s7
    ctx->r2 = ADD32(ctx->r6, ctx->r23);
    // 0x8008F284: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008F28C:
    // 0x8008F28C: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x8008F290: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008F294: beq         $s5, $v1, L_8008F2C0
    if (ctx->r21 == ctx->r3) {
        // 0x8008F298: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_8008F2C0;
    }
    // 0x8008F298: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8008F29C: lw          $t4, 0x4($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X4);
    // 0x8008F2A0: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8008F2A4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8008F2A8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8008F2AC: nop

    // 0x8008F2B0: andi        $t8, $t7, 0x6
    ctx->r24 = ctx->r15 & 0X6;
    // 0x8008F2B4: bne         $s0, $t8, L_8008F2C0
    if (ctx->r16 != ctx->r24) {
        // 0x8008F2B8: nop
    
            goto L_8008F2C0;
    }
    // 0x8008F2B8: nop

    // 0x8008F2BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8008F2C0:
    // 0x8008F2C0: bne         $at, $zero, L_8008F28C
    if (ctx->r1 != 0) {
        // 0x8008F2C4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008F28C;
    }
    // 0x8008F2C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008F2C8: bne         $a1, $s6, L_8008F2F0
    if (ctx->r5 != ctx->r22) {
        // 0x8008F2CC: addu        $t3, $a2, $s1
        ctx->r11 = ADD32(ctx->r6, ctx->r17);
            goto L_8008F2F0;
    }
    // 0x8008F2CC: addu        $t3, $a2, $s1
    ctx->r11 = ADD32(ctx->r6, ctx->r17);
    // 0x8008F2D0: beq         $s3, $s6, L_8008F2F0
    if (ctx->r19 == ctx->r22) {
        // 0x8008F2D4: addiu       $t9, $zero, 0x82
        ctx->r25 = ADD32(0, 0X82);
            goto L_8008F2F0;
    }
    // 0x8008F2D4: addiu       $t9, $zero, 0x82
    ctx->r25 = ADD32(0, 0X82);
    // 0x8008F2D8: lhu         $t1, 0xC($s4)
    ctx->r9 = MEM_HU(ctx->r20, 0XC);
    // 0x8008F2DC: sllv        $v0, $t9, $s3
    ctx->r2 = S32(ctx->r25 << (ctx->r19 & 31));
    // 0x8008F2E0: and         $t2, $t1, $v0
    ctx->r10 = ctx->r9 & ctx->r2;
    // 0x8008F2E4: beq         $v0, $t2, L_8008F2F0
    if (ctx->r2 == ctx->r10) {
        // 0x8008F2E8: nop
    
            goto L_8008F2F0;
    }
    // 0x8008F2E8: nop

    // 0x8008F2EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008F2F0:
    // 0x8008F2F0: bne         $a1, $s6, L_8008F33C
    if (ctx->r5 != ctx->r22) {
        // 0x8008F2F4: addu        $t4, $t3, $s7
        ctx->r12 = ADD32(ctx->r11, ctx->r23);
            goto L_8008F33C;
    }
    // 0x8008F2F4: addu        $t4, $t3, $s7
    ctx->r12 = ADD32(ctx->r11, ctx->r23);
    // 0x8008F2F8: lb          $t5, 0x0($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X0);
    // 0x8008F2FC: b           L_8008F33C
    // 0x8008F300: sh          $t5, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r13;
        goto L_8008F33C;
    // 0x8008F300: sh          $t5, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r13;
L_8008F304:
    // 0x8008F304: bne         $s1, $at, L_8008F33C
    if (ctx->r17 != ctx->r1) {
        // 0x8008F308: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8008F33C;
    }
    // 0x8008F308: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008F30C: lhu         $t6, 0x8($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X8);
    // 0x8008F310: sllv        $t8, $t7, $fp
    ctx->r24 = S32(ctx->r15 << (ctx->r30 & 31));
    // 0x8008F314: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x8008F318: beq         $t9, $zero, L_8008F33C
    if (ctx->r25 == 0) {
        // 0x8008F31C: nop
    
            goto L_8008F33C;
    }
    // 0x8008F31C: nop

    // 0x8008F320: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F324: mflo        $t1
    ctx->r9 = lo;
    // 0x8008F328: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8008F32C: addu        $t3, $t2, $s7
    ctx->r11 = ADD32(ctx->r10, ctx->r23);
    // 0x8008F330: lb          $t4, 0x0($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X0);
    // 0x8008F334: nop

    // 0x8008F338: sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
L_8008F33C:
    // 0x8008F33C: jal         0x8009F1A4
    // 0x8008F340: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_19;
    // 0x8008F340: nop

    after_19:
    // 0x8008F344: beq         $v0, $zero, L_8008F368
    if (ctx->r2 == 0) {
        // 0x8008F348: nop
    
            goto L_8008F368;
    }
    // 0x8008F348: nop

    // 0x8008F34C: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F350: mflo        $t5
    ctx->r13 = lo;
    // 0x8008F354: addu        $t7, $t5, $s1
    ctx->r15 = ADD32(ctx->r13, ctx->r17);
    // 0x8008F358: addu        $t6, $t7, $s7
    ctx->r14 = ADD32(ctx->r15, ctx->r23);
    // 0x8008F35C: lb          $t8, 0x0($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X0);
    // 0x8008F360: nop

    // 0x8008F364: sh          $t8, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r24;
L_8008F368:
    // 0x8008F368: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008F36C: bne         $s1, $s0, L_8008F1E8
    if (ctx->r17 != ctx->r16) {
        // 0x8008F370: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_8008F1E8;
    }
    // 0x8008F370: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8008F374: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8008F378: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008F37C: addiu       $t1, $t9, 0xC
    ctx->r9 = ADD32(ctx->r25, 0XC);
    // 0x8008F380: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x8008F384: bne         $fp, $at, L_8008F1DC
    if (ctx->r30 != ctx->r1) {
        // 0x8008F388: or          $s3, $fp, $zero
        ctx->r19 = ctx->r30 | 0;
            goto L_8008F1DC;
    }
    // 0x8008F388: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x8008F38C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008F390: lw          $v0, 0x6F8C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F8C);
    // 0x8008F394: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008F398: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8008F39C: lw          $t4, 0x6F88($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6F88);
    // 0x8008F3A0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008F3A4: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x8008F3A8: addiu       $a3, $a3, 0x6EA8
    ctx->r7 = ADD32(ctx->r7, 0X6EA8);
    // 0x8008F3AC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008F3B0: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x8008F3B4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8008F3B8: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8008F3BC: lh          $t6, 0x0($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X0);
    // 0x8008F3C0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F3C4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008F3C8: addiu       $s0, $s0, -0x5B8
    ctx->r16 = ADD32(ctx->r16, -0X5B8);
    // 0x8008F3CC: addiu       $v1, $v1, -0x5BC
    ctx->r3 = ADD32(ctx->r3, -0X5BC);
    // 0x8008F3D0: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8008F3D4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8008F3D8: bne         $s5, $t6, L_8008F414
    if (ctx->r21 != ctx->r14) {
        // 0x8008F3DC: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8008F414;
    }
    // 0x8008F3DC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8008F3E0: lh          $a0, 0x0($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X0);
    // 0x8008F3E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008F3E8: addiu       $v0, $v0, 0x6970
    ctx->r2 = ADD32(ctx->r2, 0X6970);
    // 0x8008F3EC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008F3F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008F3F4: jal         0x8006E528
    // 0x8008F3F8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    load_level_for_menu(rdram, ctx);
        goto after_20;
    // 0x8008F3F8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_20:
    // 0x8008F3FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008F400: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8008F404: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F408: sw          $zero, 0x6FB4($at)
    MEM_W(0X6FB4, ctx->r1) = 0;
    // 0x8008F40C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F410: sw          $zero, 0x6FB8($at)
    MEM_W(0X6FB8, ctx->r1) = 0;
L_8008F414:
    // 0x8008F414: jal         0x800C59F4
    // 0x8008F418: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_21;
    // 0x8008F418: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_21:
    // 0x8008F41C: jal         0x8008043C
    // 0x8008F420: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8007FFEC(rdram, ctx);
        goto after_22;
    // 0x8008F420: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_22:
    // 0x8008F424: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F428: sw          $zero, 0x6DE0($at)
    MEM_W(0X6DE0, ctx->r1) = 0;
    // 0x8008F42C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008F430: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F434: addiu       $s0, $s0, -0x320
    ctx->r16 = ADD32(ctx->r16, -0X320);
    // 0x8008F438: sw          $zero, 0x6DE8($at)
    MEM_W(0X6DE8, ctx->r1) = 0;
    // 0x8008F43C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8008F440: jal         0x80000BE0
    // 0x8008F444: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_23;
    // 0x8008F444: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_23:
    // 0x8008F448: jal         0x80000C1C
    // 0x8008F44C: nop

    music_voicelimit_change_off(rdram, ctx);
        goto after_24;
    // 0x8008F44C: nop

    after_24:
    // 0x8008F450: jal         0x80000B34
    // 0x8008F454: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_25;
    // 0x8008F454: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_25:
    // 0x8008F458: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    // 0x8008F45C: jal         0x80001990
    // 0x8008F460: nop

    music_volume_set(rdram, ctx);
        goto after_26;
    // 0x8008F460: nop

    after_26:
    // 0x8008F464: jal         0x80000B18
    // 0x8008F468: nop

    music_change_off(rdram, ctx);
        goto after_27;
    // 0x8008F468: nop

    after_27:
    // 0x8008F46C: jal         0x8006F7A4
    // 0x8008F470: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_gIntDisFlag(rdram, ctx);
        goto after_28;
    // 0x8008F470: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_28:
    // 0x8008F474: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008F478: lw          $t4, 0x998($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X998);
    // 0x8008F47C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F480: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008F484: lw          $t3, 0x990($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X990);
    // 0x8008F488: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8008F48C: sw          $t4, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r12;
    // 0x8008F490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F494: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008F498: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8008F49C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008F4A0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8008F4A4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008F4A8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8008F4AC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008F4B0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8008F4B4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8008F4B8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8008F4BC: jr          $ra
    // 0x8008F4C0: sw          $t3, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = ctx->r11;
    return;
    // 0x8008F4C0: sw          $t3, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void trackmenu_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F4C4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008F4C8: addiu       $a1, $a1, 0x6D70
    ctx->r5 = ADD32(ctx->r5, 0X6D70);
    // 0x8008F4CC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008F4D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F4D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008F4D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F4DC: beq         $v0, $at, L_8008F504
    if (ctx->r2 == ctx->r1) {
        // 0x8008F4E0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8008F504;
    }
    // 0x8008F4E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008F4E4: beq         $v0, $zero, L_8008F504
    if (ctx->r2 == 0) {
        // 0x8008F4E8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008F504;
    }
    // 0x8008F4E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008F4EC: bne         $v0, $at, L_8008F504
    if (ctx->r2 != ctx->r1) {
        // 0x8008F4F0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008F504;
    }
    // 0x8008F4F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F4F4: jal         0x8009C9EC
    // 0x8008F4F8: addiu       $a0, $a0, 0xD68
    ctx->r4 = ADD32(ctx->r4, 0XD68);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8008F4F8: addiu       $a0, $a0, 0xD68
    ctx->r4 = ADD32(ctx->r4, 0XD68);
    after_0:
    // 0x8008F4FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008F500: addiu       $a1, $a1, 0x6D70
    ctx->r5 = ADD32(ctx->r5, 0X6D70);
L_8008F504:
    // 0x8008F504: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008F508: nop

    // 0x8008F50C: bltz        $t6, L_8008F6D8
    if (SIGNED(ctx->r14) < 0) {
        // 0x8008F510: sw          $t6, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r14;
            goto L_8008F6D8;
    }
    // 0x8008F510: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8008F514: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8008F518: beq         $at, $zero, L_8008F6DC
    if (ctx->r1 == 0) {
        // 0x8008F51C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008F6DC;
    }
    // 0x8008F51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F520: beq         $t6, $zero, L_8008F53C
    if (ctx->r14 == 0) {
        // 0x8008F524: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008F53C;
    }
    // 0x8008F524: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F528: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008F52C: beq         $t6, $at, L_8008F55C
    if (ctx->r14 == ctx->r1) {
        // 0x8008F530: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008F55C;
    }
    // 0x8008F530: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F534: b           L_8008F6DC
    // 0x8008F538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F6DC;
    // 0x8008F538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F53C:
    // 0x8008F53C: lwc1        $f4, 0x6F9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F9C);
    // 0x8008F540: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F544: swc1        $f4, 0x6FA8($at)
    MEM_W(0X6FA8, ctx->r1) = ctx->f4.u32l;
    // 0x8008F548: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F54C: lwc1        $f6, 0x6FA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x8008F550: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F554: b           L_8008F6D8
    // 0x8008F558: swc1        $f6, 0x6FAC($at)
    MEM_W(0X6FAC, ctx->r1) = ctx->f6.u32l;
        goto L_8008F6D8;
    // 0x8008F558: swc1        $f6, 0x6FAC($at)
    MEM_W(0X6FAC, ctx->r1) = ctx->f6.u32l;
L_8008F55C:
    // 0x8008F55C: lw          $a0, -0x5BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5BC);
    // 0x8008F560: jal         0x8006B2EC
    // 0x8008F564: nop

    leveltable_vehicle_default(rdram, ctx);
        goto after_1;
    // 0x8008F564: nop

    after_1:
    // 0x8008F568: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008F56C: lw          $a2, -0x5C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5C4);
    // 0x8008F570: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008F574: blez        $a2, L_8008F5A4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008F578: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008F5A4;
    }
    // 0x8008F578: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008F57C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008F580: addiu       $v1, $t7, 0x6F80
    ctx->r3 = ADD32(ctx->r15, 0X6F80);
    // 0x8008F584: addu        $a1, $a2, $v1
    ctx->r5 = ADD32(ctx->r6, ctx->r3);
    // 0x8008F588: addiu       $a0, $a0, 0x6F84
    ctx->r4 = ADD32(ctx->r4, 0X6F84);
L_8008F58C:
    // 0x8008F58C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008F590: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8008F594: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008F598: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
    // 0x8008F59C: bne         $at, $zero, L_8008F58C
    if (ctx->r1 != 0) {
        // 0x8008F5A0: sb          $v0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r2;
            goto L_8008F58C;
    }
    // 0x8008F5A0: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
L_8008F5A4:
    // 0x8008F5A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F5A8: sw          $zero, -0x600($at)
    MEM_W(-0X600, ctx->r1) = 0;
    // 0x8008F5AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F5B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F5B4: sw          $t8, 0xF00($at)
    MEM_W(0XF00, ctx->r1) = ctx->r24;
    // 0x8008F5B8: jal         0x8009CBB8
    // 0x8008F5BC: addiu       $a0, $a0, 0xD68
    ctx->r4 = ADD32(ctx->r4, 0XD68);
    menu_assetgroup_load(rdram, ctx);
        goto after_2;
    // 0x8008F5BC: addiu       $a0, $a0, 0xD68
    ctx->r4 = ADD32(ctx->r4, 0XD68);
    after_2:
    // 0x8008F5C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F5C4: jal         0x8009CDE8
    // 0x8008F5C8: addiu       $a0, $a0, 0xDB0
    ctx->r4 = ADD32(ctx->r4, 0XDB0);
    menu_imagegroup_load(rdram, ctx);
        goto after_3;
    // 0x8008F5C8: addiu       $a0, $a0, 0xDB0
    ctx->r4 = ADD32(ctx->r4, 0XDB0);
    after_3:
    // 0x8008F5CC: jal         0x8008E914
    // 0x8008F5D0: nop

    menu_init_vehicle_textures(rdram, ctx);
        goto after_4;
    // 0x8008F5D0: nop

    after_4:
    // 0x8008F5D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008F5D8: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
    // 0x8008F5DC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F5E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F5E4: lw          $t9, 0x90($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X90);
    // 0x8008F5E8: lw          $t0, 0x94($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X94);
    // 0x8008F5EC: lw          $t1, 0x98($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X98);
    // 0x8008F5F0: lw          $t2, 0x9C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X9C);
    // 0x8008F5F4: addiu       $a0, $a0, 0xA3C
    ctx->r4 = ADD32(ctx->r4, 0XA3C);
    // 0x8008F5F8: addiu       $v1, $v1, 0xA24
    ctx->r3 = ADD32(ctx->r3, 0XA24);
    // 0x8008F5FC: lw          $t3, 0x7C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X7C);
    // 0x8008F600: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F604: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008F608: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x8008F60C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8008F610: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x8008F614: sw          $t3, 0xA54($at)
    MEM_W(0XA54, ctx->r1) = ctx->r11;
    // 0x8008F618: lw          $t4, 0x78($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X78);
    // 0x8008F61C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F620: sw          $t4, 0xA64($at)
    MEM_W(0XA64, ctx->r1) = ctx->r12;
    // 0x8008F624: lw          $t5, 0x84($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X84);
    // 0x8008F628: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F62C: sw          $t5, 0xA74($at)
    MEM_W(0XA74, ctx->r1) = ctx->r13;
    // 0x8008F630: lw          $t6, 0x80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X80);
    // 0x8008F634: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F638: sw          $t6, 0xA84($at)
    MEM_W(0XA84, ctx->r1) = ctx->r14;
    // 0x8008F63C: lw          $t7, 0x8C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8C);
    // 0x8008F640: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F644: sw          $t7, 0xA94($at)
    MEM_W(0XA94, ctx->r1) = ctx->r15;
    // 0x8008F648: lw          $t8, 0x88($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X88);
    // 0x8008F64C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F650: sw          $t8, 0xAA4($at)
    MEM_W(0XAA4, ctx->r1) = ctx->r24;
    // 0x8008F654: lw          $t9, 0xA0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA0);
    // 0x8008F658: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F65C: sw          $t9, 0xAB4($at)
    MEM_W(0XAB4, ctx->r1) = ctx->r25;
    // 0x8008F660: lw          $t0, 0xA8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XA8);
    // 0x8008F664: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F668: sw          $t0, 0xAC4($at)
    MEM_W(0XAC4, ctx->r1) = ctx->r8;
    // 0x8008F66C: lw          $t1, 0xA4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XA4);
    // 0x8008F670: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F674: sw          $t1, 0xAD4($at)
    MEM_W(0XAD4, ctx->r1) = ctx->r9;
    // 0x8008F678: lw          $t2, 0xAC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XAC);
    // 0x8008F67C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F680: sw          $t2, 0xAE4($at)
    MEM_W(0XAE4, ctx->r1) = ctx->r10;
    // 0x8008F684: lw          $t3, 0xB0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XB0);
    // 0x8008F688: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F68C: sw          $t3, 0xAF4($at)
    MEM_W(0XAF4, ctx->r1) = ctx->r11;
    // 0x8008F690: lw          $t4, 0xB4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XB4);
    // 0x8008F694: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F698: sw          $t4, 0xB04($at)
    MEM_W(0XB04, ctx->r1) = ctx->r12;
    // 0x8008F69C: lw          $t5, 0xB8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XB8);
    // 0x8008F6A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F6A4: sw          $t5, 0xB14($at)
    MEM_W(0XB14, ctx->r1) = ctx->r13;
    // 0x8008F6A8: lw          $t6, 0xBC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XBC);
    // 0x8008F6AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F6B0: sw          $t6, 0xB24($at)
    MEM_W(0XB24, ctx->r1) = ctx->r14;
    // 0x8008F6B4: lw          $t7, 0xC0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC0);
    // 0x8008F6B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F6BC: sw          $t7, 0xB34($at)
    MEM_W(0XB34, ctx->r1) = ctx->r15;
    // 0x8008F6C0: lw          $t8, 0xC4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC4);
    // 0x8008F6C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F6C8: sw          $t8, 0xB44($at)
    MEM_W(0XB44, ctx->r1) = ctx->r24;
    // 0x8008F6CC: lw          $t9, 0x1A4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1A4);
    // 0x8008F6D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F6D4: sw          $t9, 0xB94($at)
    MEM_W(0XB94, ctx->r1) = ctx->r25;
L_8008F6D8:
    // 0x8008F6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F6DC:
    // 0x8008F6DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F6E0: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8008F6E4: jr          $ra
    // 0x8008F6E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008F6E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void menu_track_select_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F6EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008F6F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F6F4: jal         0x8006ECD0
    // 0x8008F6F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8008F6F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008F6FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008F700: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8008F704: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008F708: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008F70C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8008F710: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8008F714: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x8008F718: jal         0x800C7940
    // 0x8008F71C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    bgload_active(rdram, ctx);
        goto after_1;
    // 0x8008F71C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    after_1:
    // 0x8008F720: bne         $v0, $zero, L_8008F768
    if (ctx->r2 != 0) {
        // 0x8008F724: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8008F768;
    }
    // 0x8008F724: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F728: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
    // 0x8008F72C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008F730: nop

    // 0x8008F734: beq         $v0, $zero, L_8008F768
    if (ctx->r2 == 0) {
        // 0x8008F738: nop
    
            goto L_8008F768;
    }
    // 0x8008F738: nop

    // 0x8008F73C: bgez        $v0, L_8008F75C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008F740: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_8008F75C;
    }
    // 0x8008F740: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008F744: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008F748: nop

    // 0x8008F74C: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x8008F750: b           L_8008F768
    // 0x8008F754: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_8008F768;
    // 0x8008F754: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8008F758: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_8008F75C:
    // 0x8008F75C: nop

    // 0x8008F760: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8008F764: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_8008F768:
    // 0x8008F768: jal         0x8008E9A4
    // 0x8008F76C: nop

    menu_input(rdram, ctx);
        goto after_2;
    // 0x8008F76C: nop

    after_2:
    // 0x8008F770: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008F774: addiu       $a1, $a1, 0x693C
    ctx->r5 = ADD32(ctx->r5, 0X693C);
    // 0x8008F778: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008F77C: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x8008F780: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8008F784: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8008F788: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x8008F78C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008F790: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8008F794: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8008F798: lw          $a0, 0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6D70);
    // 0x8008F79C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008F7A0: beq         $a0, $zero, L_8008F7B8
    if (ctx->r4 == 0) {
        // 0x8008F7A4: nop
    
            goto L_8008F7B8;
    }
    // 0x8008F7A4: nop

    // 0x8008F7A8: beq         $a0, $at, L_8008F7E8
    if (ctx->r4 == ctx->r1) {
        // 0x8008F7AC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8008F7E8;
    }
    // 0x8008F7AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F7B0: b           L_8008F808
    // 0x8008F7B4: nop

        goto L_8008F808;
    // 0x8008F7B4: nop

L_8008F7B8:
    // 0x8008F7B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F7BC: jal         0x800903D4
    // 0x8008F7C0: nop

    func_8008FF1C(rdram, ctx);
        goto after_3;
    // 0x8008F7C0: nop

    after_3:
    // 0x8008F7C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F7C8: jal         0x800909A0
    // 0x8008F7CC: nop

    trackmenu_track_view(rdram, ctx);
        goto after_4;
    // 0x8008F7CC: nop

    after_4:
    // 0x8008F7D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F7D4: jal         0x80090DD0
    // 0x8008F7D8: nop

    trackmenu_input(rdram, ctx);
        goto after_5;
    // 0x8008F7D8: nop

    after_5:
    // 0x8008F7DC: b           L_8008F808
    // 0x8008F7E0: nop

        goto L_8008F808;
    // 0x8008F7E0: nop

    // 0x8008F7E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8008F7E8:
    // 0x8008F7E8: jal         0x80091390
    // 0x8008F7EC: nop

    trackmenu_timetrial_sound(rdram, ctx);
        goto after_6;
    // 0x8008F7EC: nop

    after_6:
    // 0x8008F7F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F7F4: jal         0x800913E8
    // 0x8008F7F8: nop

    trackmenu_setup_render(rdram, ctx);
        goto after_7;
    // 0x8008F7F8: nop

    after_7:
    // 0x8008F7FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F800: jal         0x800926A4
    // 0x8008F804: nop

    func_80092188(rdram, ctx);
        goto after_8;
    // 0x8008F804: nop

    after_8:
L_8008F808:
    // 0x8008F808: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F80C: addiu       $v1, $v1, -0x320
    ctx->r3 = ADD32(ctx->r3, -0X320);
    // 0x8008F810: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008F814: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008F818: bgez        $v0, L_8008F830
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008F81C: sll         $t8, $t7, 1
        ctx->r24 = S32(ctx->r15 << 1);
            goto L_8008F830;
    }
    // 0x8008F81C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8008F820: jal         0x80001990
    // 0x8008F824: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    music_volume_set(rdram, ctx);
        goto after_9;
    // 0x8008F824: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8008F828: b           L_8008F854
    // 0x8008F82C: nop

        goto L_8008F854;
    // 0x8008F82C: nop

L_8008F830:
    // 0x8008F830: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8008F834: slti        $at, $t9, 0x51
    ctx->r1 = SIGNED(ctx->r25) < 0X51 ? 1 : 0;
    // 0x8008F838: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008F83C: bne         $at, $zero, L_8008F84C
    if (ctx->r1 != 0) {
        // 0x8008F840: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8008F84C;
    }
    // 0x8008F840: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8008F844: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8008F848: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8008F84C:
    // 0x8008F84C: jal         0x80001990
    // 0x8008F850: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    music_volume_set(rdram, ctx);
        goto after_10;
    // 0x8008F850: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_10:
L_8008F854:
    // 0x8008F854: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008F858: lw          $v0, 0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D70);
    // 0x8008F85C: nop

    // 0x8008F860: bgez        $v0, L_8008F920
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008F864: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8008F920;
    }
    // 0x8008F864: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8008F868: jal         0x8008F9EC
    // 0x8008F86C: nop

    menu_track_select_unload(rdram, ctx);
        goto after_11;
    // 0x8008F86C: nop

    after_11:
    // 0x8008F870: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008F874: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8008F878: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F87C: sw          $zero, -0x608($at)
    MEM_W(-0X608, ctx->r1) = 0;
    // 0x8008F880: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8008F884: beq         $at, $zero, L_8008F8A8
    if (ctx->r1 == 0) {
        // 0x8008F888: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008F8A8;
    }
    // 0x8008F888: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008F88C: bne         $v0, $at, L_8008F900
    if (ctx->r2 != ctx->r1) {
        // 0x8008F890: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8008F900;
    }
    // 0x8008F890: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008F894: lw          $t1, 0x318($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X318);
    // 0x8008F898: nop

    // 0x8008F89C: sll         $t2, $t1, 7
    ctx->r10 = S32(ctx->r9 << 7);
    // 0x8008F8A0: bltz        $t2, L_8008F904
    if (SIGNED(ctx->r10) < 0) {
        // 0x8008F8A4: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_8008F904;
    }
    // 0x8008F8A4: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
L_8008F8A8:
    // 0x8008F8A8: jal         0x8009F214
    // 0x8008F8AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    is_drumstick_unlocked(rdram, ctx);
        goto after_12;
    // 0x8008F8AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_12:
    // 0x8008F8B0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F8B4: beq         $v0, $zero, L_8008F8C0
    if (ctx->r2 == 0) {
        // 0x8008F8B8: nop
    
            goto L_8008F8C0;
    }
    // 0x8008F8B8: nop

    // 0x8008F8BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8008F8C0:
    // 0x8008F8C0: jal         0x8009F1FC
    // 0x8008F8C4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    is_tt_unlocked(rdram, ctx);
        goto after_13;
    // 0x8008F8C4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_13:
    // 0x8008F8C8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F8CC: beq         $v0, $zero, L_8008F8DC
    if (ctx->r2 == 0) {
        // 0x8008F8D0: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_8008F8DC;
    }
    // 0x8008F8D0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008F8D4: xori        $t3, $a2, 0x3
    ctx->r11 = ctx->r6 ^ 0X3;
    // 0x8008F8D8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
L_8008F8DC:
    // 0x8008F8DC: jal         0x8006E528
    // 0x8008F8E0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_level_for_menu(rdram, ctx);
        goto after_14;
    // 0x8008F8E0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_14:
    // 0x8008F8E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F8E8: jal         0x8008B36C
    // 0x8008F8EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    charselect_prev(rdram, ctx);
        goto after_15;
    // 0x8008F8EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x8008F8F0: jal         0x80081820
    // 0x8008F8F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    menu_init(rdram, ctx);
        goto after_16;
    // 0x8008F8F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x8008F8F8: b           L_8008F9DC
    // 0x8008F8FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F9DC;
    // 0x8008F8FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F900:
    // 0x8008F900: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
L_8008F904:
    // 0x8008F904: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008F908: jal         0x8006E528
    // 0x8008F90C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_17;
    // 0x8008F90C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x8008F910: jal         0x80081820
    // 0x8008F914: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    menu_init(rdram, ctx);
        goto after_18;
    // 0x8008F914: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_18:
    // 0x8008F918: b           L_8008F9DC
    // 0x8008F91C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F9DC;
    // 0x8008F91C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F920:
    // 0x8008F920: bne         $at, $zero, L_8008F9D4
    if (ctx->r1 != 0) {
        // 0x8008F924: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008F9D4;
    }
    // 0x8008F924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008F928: jal         0x8008F9EC
    // 0x8008F92C: nop

    menu_track_select_unload(rdram, ctx);
        goto after_19;
    // 0x8008F92C: nop

    after_19:
    // 0x8008F930: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008F934: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008F938: lw          $t5, 0x6AE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6AE8);
    // 0x8008F93C: lw          $t4, 0x990($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X990);
    // 0x8008F940: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008F944: beq         $t4, $t5, L_8008F97C
    if (ctx->r12 == ctx->r13) {
        // 0x8008F948: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8008F97C;
    }
    // 0x8008F948: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008F94C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8008F950: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_8008F954:
    // 0x8008F954: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x8008F958: addiu       $t7, $a2, 0x2
    ctx->r15 = ADD32(ctx->r6, 0X2);
    // 0x8008F95C: addiu       $t8, $a2, 0x3
    ctx->r24 = ADD32(ctx->r6, 0X3);
    // 0x8008F960: sb          $a2, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r6;
    // 0x8008F964: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8008F968: sb          $t8, 0xA2($v0)
    MEM_B(0XA2, ctx->r2) = ctx->r24;
    // 0x8008F96C: sb          $t7, 0x8A($v0)
    MEM_B(0X8A, ctx->r2) = ctx->r15;
    // 0x8008F970: sb          $t6, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r14;
    // 0x8008F974: bne         $a2, $v1, L_8008F954
    if (ctx->r6 != ctx->r3) {
        // 0x8008F978: addiu       $v0, $v0, 0x60
        ctx->r2 = ADD32(ctx->r2, 0X60);
            goto L_8008F954;
    }
    // 0x8008F978: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
L_8008F97C:
    // 0x8008F97C: lw          $t9, 0x6F88($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6F88);
    // 0x8008F980: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008F984: beq         $t9, $at, L_8008F9A4
    if (ctx->r25 == ctx->r1) {
        // 0x8008F988: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8008F9A4;
    }
    // 0x8008F988: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008F98C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008F990: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008F994: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F998: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8008F99C: b           L_8008F9DC
    // 0x8008F9A0: sw          $t0, -0x608($at)
    MEM_W(-0X608, ctx->r1) = ctx->r8;
        goto L_8008F9DC;
    // 0x8008F9A0: sw          $t0, -0x608($at)
    MEM_W(-0X608, ctx->r1) = ctx->r8;
L_8008F9A4:
    // 0x8008F9A4: lw          $t1, 0x6F8C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6F8C);
    // 0x8008F9A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F9AC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008F9B0: sw          $t2, 0x1568($at)
    MEM_W(0X1568, ctx->r1) = ctx->r10;
    // 0x8008F9B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F9B8: sb          $zero, -0x630($at)
    MEM_B(-0X630, ctx->r1) = 0;
    // 0x8008F9BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F9C0: sw          $zero, 0x156C($at)
    MEM_W(0X156C, ctx->r1) = 0;
    // 0x8008F9C4: jal         0x80081820
    // 0x8008F9C8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    menu_init(rdram, ctx);
        goto after_20;
    // 0x8008F9C8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_20:
    // 0x8008F9CC: b           L_8008F9DC
    // 0x8008F9D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F9DC;
    // 0x8008F9D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F9D4:
    // 0x8008F9D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F9D8: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_8008F9DC:
    // 0x8008F9DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F9E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008F9E4: jr          $ra
    // 0x8008F9E8: nop

    return;
    // 0x8008F9E8: nop

;}
