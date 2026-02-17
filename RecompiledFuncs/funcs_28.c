#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void set_next_taj_challenge_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D874: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D878: jr          $ra
    // 0x8009D87C: sb          $a0, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = ctx->r4;
    return;
    // 0x8009D87C: sb          $a0, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void set_menu_id_if_option_equal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D880: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D884: addiu       $v0, $v0, 0x6A82
    ctx->r2 = ADD32(ctx->r2, 0X6A82);
    // 0x8009D888: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D88C: nop

    // 0x8009D890: bne         $a0, $t6, L_8009D89C
    if (ctx->r4 != ctx->r14) {
        // 0x8009D894: nop
    
            goto L_8009D89C;
    }
    // 0x8009D894: nop

    // 0x8009D898: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
L_8009D89C:
    // 0x8009D89C: jr          $ra
    // 0x8009D8A0: nop

    return;
    // 0x8009D8A0: nop

;}
RECOMP_FUNC void taj_menu_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D8A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009D8A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D8AC: jal         0x8006ECD0
    // 0x8009D8B0: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009D8B0: nop

    after_0:
    // 0x8009D8B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009D8B8: lb          $v1, -0x5A4($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X5A4);
    // 0x8009D8BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009D8C0: beq         $v1, $zero, L_8009D8E0
    if (ctx->r3 == 0) {
        // 0x8009D8C4: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8009D8E0;
    }
    // 0x8009D8C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D8C8: addiu       $v0, $v0, 0x6A82
    ctx->r2 = ADD32(ctx->r2, 0X6A82);
    // 0x8009D8CC: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D8D0: negu        $t7, $v1
    ctx->r15 = SUB32(0, ctx->r3);
    // 0x8009D8D4: bne         $t6, $zero, L_8009D8E0
    if (ctx->r14 != 0) {
        // 0x8009D8D8: nop
    
            goto L_8009D8E0;
    }
    // 0x8009D8D8: nop

    // 0x8009D8DC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_8009D8E0:
    // 0x8009D8E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D8E4: addiu       $v0, $v0, 0x6A82
    ctx->r2 = ADD32(ctx->r2, 0X6A82);
    // 0x8009D8E8: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x8009D8EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009D8F0: bne         $a1, $zero, L_8009D904
    if (ctx->r5 != 0) {
        // 0x8009D8F4: nop
    
            goto L_8009D904;
    }
    // 0x8009D8F4: nop

    // 0x8009D8F8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8009D8FC: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x8009D900: nop

L_8009D904:
    // 0x8009D904: blez        $a1, L_8009D938
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8009D908: slti        $at, $a1, 0x4
        ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
            goto L_8009D938;
    }
    // 0x8009D908: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8009D90C: beq         $at, $zero, L_8009D938
    if (ctx->r1 == 0) {
        // 0x8009D910: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009D938;
    }
    // 0x8009D910: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D914: addiu       $t9, $zero, 0x7C
    ctx->r25 = ADD32(0, 0X7C);
    // 0x8009D918: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009D91C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009D920: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009D924: jal         0x800C543C
    // 0x8009D928: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x8009D928: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_1:
    // 0x8009D92C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D930: jal         0x800C54DC
    // 0x8009D934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_2;
    // 0x8009D934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8009D938:
    // 0x8009D938: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8009D93C: jal         0x8006A794
    // 0x8009D940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_3;
    // 0x8009D940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8009D944: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D948: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D94C: lb          $a1, 0x6A82($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6A82);
    // 0x8009D950: sb          $zero, 0x6AA4($at)
    MEM_B(0X6AA4, ctx->r1) = 0;
    // 0x8009D954: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009D958: beq         $a1, $at, L_8009D988
    if (ctx->r5 == ctx->r1) {
        // 0x8009D95C: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_8009D988;
    }
    // 0x8009D95C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8009D960: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009D964: beq         $a1, $at, L_8009DA30
    if (ctx->r5 == ctx->r1) {
        // 0x8009D968: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009DA30;
    }
    // 0x8009D968: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D96C: addiu       $at, $zero, 0x62
    ctx->r1 = ADD32(0, 0X62);
    // 0x8009D970: beq         $a1, $at, L_8009D988
    if (ctx->r5 == ctx->r1) {
        // 0x8009D974: addiu       $at, $zero, 0x63
        ctx->r1 = ADD32(0, 0X63);
            goto L_8009D988;
    }
    // 0x8009D974: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8009D978: beq         $a1, $at, L_8009DA30
    if (ctx->r5 == ctx->r1) {
        // 0x8009D97C: nop
    
            goto L_8009DA30;
    }
    // 0x8009D97C: nop

    // 0x8009D980: b           L_8009DB38
    // 0x8009D984: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
        goto L_8009DB38;
    // 0x8009D984: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
L_8009D988:
    // 0x8009D988: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009D98C: lw          $t0, -0x5E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E0);
    // 0x8009D990: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009D994: lw          $a3, 0xA0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XA0);
    // 0x8009D998: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009D99C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009D9A0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009D9A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D9A8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009D9AC: jal         0x800C56C8
    // 0x8009D9B0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_4;
    // 0x8009D9B0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_4:
    // 0x8009D9B4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009D9B8: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009D9BC: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8009D9C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D9C4: sb          $t3, 0x6AAE($at)
    MEM_B(0X6AAE, ctx->r1) = ctx->r11;
    // 0x8009D9C8: lw          $a0, 0xA4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XA4);
    // 0x8009D9CC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D9D0: jal         0x8009D6FC
    // 0x8009D9D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_5;
    // 0x8009D9D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8009D9D8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009D9DC: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009D9E0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D9E4: lw          $a0, 0xA8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XA8);
    // 0x8009D9E8: jal         0x8009D6FC
    // 0x8009D9EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_6;
    // 0x8009D9EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8009D9F0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009D9F4: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x8009D9F8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D9FC: lw          $a0, 0xAC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XAC);
    // 0x8009DA00: jal         0x8009D6FC
    // 0x8009DA04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_option(rdram, ctx);
        goto after_7;
    // 0x8009DA04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_7:
    // 0x8009DA08: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009DA0C: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x8009DA10: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DA14: lw          $a0, 0xB0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XB0);
    // 0x8009DA18: jal         0x8009D6FC
    // 0x8009DA1C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    render_dialogue_option(rdram, ctx);
        goto after_8;
    // 0x8009DA1C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x8009DA20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009DA24: lb          $a1, 0x6A82($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6A82);
    // 0x8009DA28: b           L_8009DB38
    // 0x8009DA2C: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
        goto L_8009DB38;
    // 0x8009DA2C: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
L_8009DA30:
    // 0x8009DA30: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009DA34: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x8009DA38: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009DA3C: lw          $a3, 0xB4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XB4);
    // 0x8009DA40: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8009DA44: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8009DA48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009DA4C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009DA50: jal         0x800C56C8
    // 0x8009DA54: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_9;
    // 0x8009DA54: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_9:
    // 0x8009DA58: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8009DA5C: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8009DA60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DA64: sb          $t1, 0x6AAE($at)
    MEM_B(0X6AAE, ctx->r1) = ctx->r9;
    // 0x8009DA68: lhu         $v1, 0x14($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X14);
    // 0x8009DA6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DA70: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    // 0x8009DA74: beq         $t3, $zero, L_8009DAA8
    if (ctx->r11 == 0) {
        // 0x8009DA78: andi        $t4, $v1, 0x8
        ctx->r12 = ctx->r3 & 0X8;
            goto L_8009DAA8;
    }
    // 0x8009DA78: andi        $t4, $v1, 0x8
    ctx->r12 = ctx->r3 & 0X8;
    // 0x8009DA7C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009DA80: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009DA84: sb          $t4, -0x594($at)
    MEM_B(-0X594, ctx->r1) = ctx->r12;
    // 0x8009DA88: lw          $a0, 0xB8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XB8);
    // 0x8009DA8C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DA90: jal         0x8009D6FC
    // 0x8009DA94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_10;
    // 0x8009DA94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8009DA98: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8009DA9C: nop

    // 0x8009DAA0: lhu         $v1, 0x14($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X14);
    // 0x8009DAA4: nop

L_8009DAA8:
    // 0x8009DAA8: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x8009DAAC: beq         $t7, $zero, L_8009DAE4
    if (ctx->r15 == 0) {
        // 0x8009DAB0: andi        $t8, $v1, 0x10
        ctx->r24 = ctx->r3 & 0X10;
            goto L_8009DAE4;
    }
    // 0x8009DAB0: andi        $t8, $v1, 0x10
    ctx->r24 = ctx->r3 & 0X10;
    // 0x8009DAB4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009DAB8: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x8009DABC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DAC0: sb          $t8, -0x594($at)
    MEM_B(-0X594, ctx->r1) = ctx->r24;
    // 0x8009DAC4: lw          $a0, 0xBC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XBC);
    // 0x8009DAC8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DACC: jal         0x8009D6FC
    // 0x8009DAD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_11;
    // 0x8009DAD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x8009DAD4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8009DAD8: nop

    // 0x8009DADC: lhu         $v1, 0x14($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X14);
    // 0x8009DAE0: nop

L_8009DAE4:
    // 0x8009DAE4: andi        $t1, $v1, 0x4
    ctx->r9 = ctx->r3 & 0X4;
    // 0x8009DAE8: beq         $t1, $zero, L_8009DB10
    if (ctx->r9 == 0) {
        // 0x8009DAEC: andi        $t2, $v1, 0x20
        ctx->r10 = ctx->r3 & 0X20;
            goto L_8009DB10;
    }
    // 0x8009DAEC: andi        $t2, $v1, 0x20
    ctx->r10 = ctx->r3 & 0X20;
    // 0x8009DAF0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009DAF4: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x8009DAF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DAFC: sb          $t2, -0x594($at)
    MEM_B(-0X594, ctx->r1) = ctx->r10;
    // 0x8009DB00: lw          $a0, 0xC0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC0);
    // 0x8009DB04: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DB08: jal         0x8009D6FC
    // 0x8009DB0C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_option(rdram, ctx);
        goto after_12;
    // 0x8009DB0C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_12:
L_8009DB10:
    // 0x8009DB10: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009DB14: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009DB18: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DB1C: lw          $a0, 0xB0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XB0);
    // 0x8009DB20: jal         0x8009D6FC
    // 0x8009DB24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    render_dialogue_option(rdram, ctx);
        goto after_13;
    // 0x8009DB24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_13:
    // 0x8009DB28: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009DB2C: lb          $a1, 0x6A82($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6A82);
    // 0x8009DB30: nop

    // 0x8009DB34: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
L_8009DB38:
    // 0x8009DB38: sltiu       $at, $t5, 0x10
    ctx->r1 = ctx->r13 < 0X10 ? 1 : 0;
    // 0x8009DB3C: beq         $at, $zero, L_8009DF28
    if (ctx->r1 == 0) {
        // 0x8009DB40: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8009DF28;
    }
    // 0x8009DB40: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8009DB44: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009DB48: addu        $at, $at, $t5
    gpr jr_addend_8009DB54 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8009DB4C: lw          $t5, -0x74D0($at)
    ctx->r13 = ADD32(ctx->r1, -0X74D0);
    // 0x8009DB50: nop

    // 0x8009DB54: jr          $t5
    // 0x8009DB58: nop

    switch (jr_addend_8009DB54 >> 2) {
        case 0: goto L_8009DE88; break;
        case 1: goto L_8009DE88; break;
        case 2: goto L_8009DE88; break;
        case 3: goto L_8009DE60; break;
        case 4: goto L_8009DE34; break;
        case 5: goto L_8009DE18; break;
        case 6: goto L_8009DE18; break;
        case 7: goto L_8009DE18; break;
        case 8: goto L_8009DB5C; break;
        case 9: goto L_8009DB7C; break;
        case 10: goto L_8009DCE4; break;
        case 11: goto L_8009DD84; break;
        case 12: goto L_8009DEAC; break;
        case 13: goto L_8009DEDC; break;
        case 14: goto L_8009DEF4; break;
        case 15: goto L_8009DEF4; break;
        default: switch_error(__func__, 0x8009DB54, 0x800E8B30);
    }
    // 0x8009DB58: nop

L_8009DB5C:
    // 0x8009DB5C: jal         0x800C3744
    // 0x8009DB60: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    set_current_text(rdram, ctx);
        goto after_14;
    // 0x8009DB60: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_14:
    // 0x8009DB64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009DB68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DB6C: sb          $v0, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r2;
    // 0x8009DB70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DB74: b           L_8009DF28
    // 0x8009DB78: sb          $v0, -0x5A8($at)
    MEM_B(-0X5A8, ctx->r1) = ctx->r2;
        goto L_8009DF28;
    // 0x8009DB78: sb          $v0, -0x5A8($at)
    MEM_B(-0X5A8, ctx->r1) = ctx->r2;
L_8009DB7C:
    // 0x8009DB7C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009DB80: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x8009DB84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DB88: sb          $zero, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = 0;
    // 0x8009DB8C: lw          $a3, 0x2F8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X2F8);
    // 0x8009DB90: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009DB94: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8009DB98: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009DB9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009DBA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DBA4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009DBA8: jal         0x800C56C8
    // 0x8009DBAC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_15;
    // 0x8009DBAC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_15:
    // 0x8009DBB0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009DBB4: lw          $t0, -0x5E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E0);
    // 0x8009DBB8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8009DBBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DBC0: sb          $t9, 0x6AAE($at)
    MEM_B(0X6AAE, ctx->r1) = ctx->r25;
    // 0x8009DBC4: lw          $a0, 0x94($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X94);
    // 0x8009DBC8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DBCC: jal         0x8009D6FC
    // 0x8009DBD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_16;
    // 0x8009DBD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x8009DBD4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8009DBD8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009DBDC: lhu         $t2, 0x14($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X14);
    // 0x8009DBE0: nop

    // 0x8009DBE4: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x8009DBE8: beq         $t3, $zero, L_8009DC04
    if (ctx->r11 == 0) {
        // 0x8009DBEC: nop
    
            goto L_8009DC04;
    }
    // 0x8009DBEC: nop

    // 0x8009DBF0: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009DBF4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DBF8: lw          $a0, 0x9C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X9C);
    // 0x8009DBFC: jal         0x8009D6FC
    // 0x8009DC00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_17;
    // 0x8009DC00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
L_8009DC04:
    // 0x8009DC04: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009DC08: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009DC0C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DC10: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    // 0x8009DC14: jal         0x8009D6FC
    // 0x8009DC18: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_option(rdram, ctx);
        goto after_18;
    // 0x8009DC18: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_18:
    // 0x8009DC1C: jal         0x8009D7B0
    // 0x8009DC20: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_19;
    // 0x8009DC20: nop

    after_19:
    // 0x8009DC24: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009DC28: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8009DC2C: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8009DC30: beq         $t7, $zero, L_8009DC54
    if (ctx->r15 == 0) {
        // 0x8009DC34: andi        $t0, $t9, 0x8000
        ctx->r8 = ctx->r25 & 0X8000;
            goto L_8009DC54;
    }
    // 0x8009DC34: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x8009DC38: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009DC3C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8009DC40: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009DC44: jal         0x80001D04
    // 0x8009DC48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_20;
    // 0x8009DC48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x8009DC4C: b           L_8009DF2C
    // 0x8009DC50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DC50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DC54:
    // 0x8009DC54: beq         $t0, $zero, L_8009DF28
    if (ctx->r8 == 0) {
        // 0x8009DC58: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009DF28;
    }
    // 0x8009DC58: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009DC5C: jal         0x80001D04
    // 0x8009DC60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_21;
    // 0x8009DC60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x8009DC64: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009DC68: lb          $v1, 0x6AB6($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6AB6);
    // 0x8009DC6C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8009DC70: beq         $v1, $zero, L_8009DCC4
    if (ctx->r3 == 0) {
        // 0x8009DC74: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8009DCC4;
    }
    // 0x8009DC74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DC78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009DC7C: beq         $v1, $at, L_8009DC98
    if (ctx->r3 == ctx->r1) {
        // 0x8009DC80: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_8009DC98;
    }
    // 0x8009DC80: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8009DC84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009DC88: beq         $v1, $at, L_8009DCBC
    if (ctx->r3 == ctx->r1) {
        // 0x8009DC8C: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8009DCBC;
    }
    // 0x8009DC8C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8009DC90: b           L_8009DF2C
    // 0x8009DC94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DC94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DC98:
    // 0x8009DC98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DC9C: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
    // 0x8009DCA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DCA4: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
    // 0x8009DCA8: addiu       $a0, $zero, 0x239
    ctx->r4 = ADD32(0, 0X239);
    // 0x8009DCAC: jal         0x8003AC7C
    // 0x8009DCB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_22;
    // 0x8009DCB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x8009DCB4: b           L_8009DF2C
    // 0x8009DCB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DCB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DCBC:
    // 0x8009DCBC: b           L_8009DF28
    // 0x8009DCC0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
        goto L_8009DF28;
    // 0x8009DCC0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_8009DCC4:
    // 0x8009DCC4: sb          $t3, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r11;
    // 0x8009DCC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DCCC: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
    // 0x8009DCD0: addiu       $a0, $zero, 0x234
    ctx->r4 = ADD32(0, 0X234);
    // 0x8009DCD4: jal         0x8003AC7C
    // 0x8009DCD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_23;
    // 0x8009DCD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x8009DCDC: b           L_8009DF2C
    // 0x8009DCE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DCE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DCE4:
    // 0x8009DCE4: jal         0x8009D7B0
    // 0x8009DCE8: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_24;
    // 0x8009DCE8: nop

    after_24:
    // 0x8009DCEC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8009DCF0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8009DCF4: andi        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 & 0X4000;
    // 0x8009DCF8: beq         $t5, $zero, L_8009DD30
    if (ctx->r13 == 0) {
        // 0x8009DCFC: andi        $t8, $t7, 0x8000
        ctx->r24 = ctx->r15 & 0X8000;
            goto L_8009DD30;
    }
    // 0x8009DCFC: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8009DD00: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009DD04: jal         0x80001D04
    // 0x8009DD08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_25;
    // 0x8009DD08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x8009DD0C: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    // 0x8009DD10: jal         0x8003AC7C
    // 0x8009DD14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_26;
    // 0x8009DD14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x8009DD18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009DD1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DD20: sb          $t6, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r14;
    // 0x8009DD24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DD28: b           L_8009DF28
    // 0x8009DD2C: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
        goto L_8009DF28;
    // 0x8009DD2C: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
L_8009DD30:
    // 0x8009DD30: beq         $t8, $zero, L_8009DF28
    if (ctx->r24 == 0) {
        // 0x8009DD34: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8009DF28;
    }
    // 0x8009DD34: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009DD38: lb          $v0, 0x6AB6($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AB6);
    // 0x8009DD3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009DD40: beq         $v0, $at, L_8009DD60
    if (ctx->r2 == ctx->r1) {
        // 0x8009DD44: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8009DD60;
    }
    // 0x8009DD44: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009DD48: ori         $t9, $v0, 0x80
    ctx->r25 = ctx->r2 | 0X80;
    // 0x8009DD4C: addiu       $t0, $zero, 0x62
    ctx->r8 = ADD32(0, 0X62);
    // 0x8009DD50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DD54: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8009DD58: b           L_8009DF28
    // 0x8009DD5C: sb          $t0, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r8;
        goto L_8009DF28;
    // 0x8009DD5C: sb          $t0, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r8;
L_8009DD60:
    // 0x8009DD60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DD64: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
    // 0x8009DD68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DD6C: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
    // 0x8009DD70: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    // 0x8009DD74: jal         0x8003AC7C
    // 0x8009DD78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_27;
    // 0x8009DD78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x8009DD7C: b           L_8009DF2C
    // 0x8009DD80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DD80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DD84:
    // 0x8009DD84: jal         0x8009D7B0
    // 0x8009DD88: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_28;
    // 0x8009DD88: nop

    after_28:
    // 0x8009DD8C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8009DD90: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009DD94: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8009DD98: bne         $t2, $zero, L_8009DDB8
    if (ctx->r10 != 0) {
        // 0x8009DD9C: andi        $v0, $v1, 0x8000
        ctx->r2 = ctx->r3 & 0X8000;
            goto L_8009DDB8;
    }
    // 0x8009DD9C: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x8009DDA0: beq         $v0, $zero, L_8009DDE8
    if (ctx->r2 == 0) {
        // 0x8009DDA4: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8009DDE8;
    }
    // 0x8009DDA4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009DDA8: lb          $t3, 0x6AB6($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X6AB6);
    // 0x8009DDAC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009DDB0: bne         $t3, $at, L_8009DDE8
    if (ctx->r11 != ctx->r1) {
        // 0x8009DDB4: nop
    
            goto L_8009DDE8;
    }
    // 0x8009DDB4: nop

L_8009DDB8:
    // 0x8009DDB8: jal         0x80001D04
    // 0x8009DDBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_29;
    // 0x8009DDBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x8009DDC0: addiu       $a0, $zero, 0x23A
    ctx->r4 = ADD32(0, 0X23A);
    // 0x8009DDC4: jal         0x8003AC7C
    // 0x8009DDC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_30;
    // 0x8009DDC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x8009DDCC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009DDD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DDD4: sb          $t4, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r12;
    // 0x8009DDD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DDDC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8009DDE0: b           L_8009DF28
    // 0x8009DDE4: sb          $t5, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = ctx->r13;
        goto L_8009DF28;
    // 0x8009DDE4: sb          $t5, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = ctx->r13;
L_8009DDE8:
    // 0x8009DDE8: beq         $v0, $zero, L_8009DF28
    if (ctx->r2 == 0) {
        // 0x8009DDEC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8009DF28;
    }
    // 0x8009DDEC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009DDF0: lb          $t6, 0x6AB6($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X6AB6);
    // 0x8009DDF4: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009DDF8: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x8009DDFC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8009DE00: jal         0x80001D04
    // 0x8009DE04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_31;
    // 0x8009DE04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x8009DE08: addiu       $t8, $zero, 0x63
    ctx->r24 = ADD32(0, 0X63);
    // 0x8009DE0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE10: b           L_8009DF28
    // 0x8009DE14: sb          $t8, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r24;
        goto L_8009DF28;
    // 0x8009DE14: sb          $t8, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r24;
L_8009DE18:
    // 0x8009DE18: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8009DE1C: jal         0x800C3744
    // 0x8009DE20: subu        $a0, $t9, $a1
    ctx->r4 = SUB32(ctx->r25, ctx->r5);
    set_current_text(rdram, ctx);
        goto after_32;
    // 0x8009DE20: subu        $a0, $t9, $a1
    ctx->r4 = SUB32(ctx->r25, ctx->r5);
    after_32:
    // 0x8009DE24: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8009DE28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE2C: b           L_8009DF28
    // 0x8009DE30: sb          $t0, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r8;
        goto L_8009DF28;
    // 0x8009DE30: sb          $t0, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r8;
L_8009DE34:
    // 0x8009DE34: jal         0x800C3744
    // 0x8009DE38: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    set_current_text(rdram, ctx);
        goto after_33;
    // 0x8009DE38: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_33:
    // 0x8009DE3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DE40: sb          $zero, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = 0;
    // 0x8009DE44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009DE4C: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
    // 0x8009DE50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE54: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8009DE58: b           L_8009DF28
    // 0x8009DE5C: sb          $t2, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = ctx->r10;
        goto L_8009DF28;
    // 0x8009DE5C: sb          $t2, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = ctx->r10;
L_8009DE60:
    // 0x8009DE60: jal         0x800C3744
    // 0x8009DE64: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    set_current_text(rdram, ctx);
        goto after_34;
    // 0x8009DE64: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_34:
    // 0x8009DE68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DE6C: sb          $zero, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = 0;
    // 0x8009DE70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE74: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x8009DE78: sb          $t3, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r11;
    // 0x8009DE7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE80: b           L_8009DF28
    // 0x8009DE84: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
        goto L_8009DF28;
    // 0x8009DE84: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
L_8009DE88:
    // 0x8009DE88: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8009DE8C: jal         0x800C3744
    // 0x8009DE90: subu        $a0, $t4, $a1
    ctx->r4 = SUB32(ctx->r12, ctx->r5);
    set_current_text(rdram, ctx);
        goto after_35;
    // 0x8009DE90: subu        $a0, $t4, $a1
    ctx->r4 = SUB32(ctx->r12, ctx->r5);
    after_35:
    // 0x8009DE94: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8009DE98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE9C: sb          $t5, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r13;
    // 0x8009DEA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DEA4: b           L_8009DF28
    // 0x8009DEA8: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
        goto L_8009DF28;
    // 0x8009DEA8: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
L_8009DEAC:
    // 0x8009DEAC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009DEB0: lb          $t6, -0x5A4($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X5A4);
    // 0x8009DEB4: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8009DEB8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8009DEBC: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x8009DEC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DEC4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8009DEC8: sb          $t9, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r25;
    // 0x8009DECC: jal         0x800C5B80
    // 0x8009DED0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    dialogue_close(rdram, ctx);
        goto after_36;
    // 0x8009DED0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_36:
    // 0x8009DED4: b           L_8009DF2C
    // 0x8009DED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DEDC:
    // 0x8009DEDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DEE0: sb          $zero, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = 0;
    // 0x8009DEE4: jal         0x800C5B80
    // 0x8009DEE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    dialogue_close(rdram, ctx);
        goto after_37;
    // 0x8009DEE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_37:
    // 0x8009DEEC: b           L_8009DF2C
    // 0x8009DEF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DF2C;
    // 0x8009DEF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DEF4:
    // 0x8009DEF4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8009DEF8: bne         $a1, $at, L_8009DF04
    if (ctx->r5 != ctx->r1) {
        // 0x8009DEFC: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8009DF04;
    }
    // 0x8009DEFC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8009DF00: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8009DF04:
    // 0x8009DF04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DF08: sb          $zero, -0x5A0($at)
    MEM_B(-0X5A0, ctx->r1) = 0;
    // 0x8009DF0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DF10: jal         0x800C5B80
    // 0x8009DF14: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    dialogue_close(rdram, ctx);
        goto after_38;
    // 0x8009DF14: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_38:
    // 0x8009DF18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DF1C: sb          $zero, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = 0;
    // 0x8009DF20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DF24: sb          $zero, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = 0;
L_8009DF28:
    // 0x8009DF28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DF2C:
    // 0x8009DF2C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8009DF30: jr          $ra
    // 0x8009DF34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8009DF34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void dialogue_race_defeat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DF38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009DF3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DF40: addiu       $t6, $zero, 0x87
    ctx->r14 = ADD32(0, 0X87);
    // 0x8009DF44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009DF48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DF4C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009DF50: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009DF54: jal         0x800C543C
    // 0x8009DF58: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_0;
    // 0x8009DF58: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_0:
    // 0x8009DF5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DF60: jal         0x800C54DC
    // 0x8009DF64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_1;
    // 0x8009DF64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8009DF68: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8009DF6C: jal         0x8006A794
    // 0x8009DF70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x8009DF70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8009DF74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DF78: sb          $zero, 0x6AA4($at)
    MEM_B(0X6AA4, ctx->r1) = 0;
    // 0x8009DF7C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009DF80: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x8009DF84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DF88: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009DF8C: sb          $zero, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = 0;
    // 0x8009DF90: lw          $a3, 0xC4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XC4);
    // 0x8009DF94: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009DF98: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8009DF9C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009DFA0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009DFA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DFA8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009DFAC: jal         0x800C56C8
    // 0x8009DFB0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_3;
    // 0x8009DFB0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_3:
    // 0x8009DFB4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009DFB8: lw          $t0, -0x5E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E0);
    // 0x8009DFBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009DFC0: lw          $a3, 0xC8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC8);
    // 0x8009DFC4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009DFC8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009DFCC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009DFD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DFD4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009DFD8: jal         0x800C56C8
    // 0x8009DFDC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    render_dialogue_text(rdram, ctx);
        goto after_4;
    // 0x8009DFDC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_4:
    // 0x8009DFE0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009DFE4: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009DFE8: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x8009DFEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DFF0: sb          $t3, 0x6AAE($at)
    MEM_B(0X6AAE, ctx->r1) = ctx->r11;
    // 0x8009DFF4: lw          $a0, 0x5C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X5C);
    // 0x8009DFF8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DFFC: jal         0x8009D6FC
    // 0x8009E000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_5;
    // 0x8009E000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8009E004: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009E008: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009E00C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009E010: lw          $a0, 0xCC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XCC);
    // 0x8009E014: jal         0x8009D6FC
    // 0x8009E018: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_6;
    // 0x8009E018: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8009E01C: jal         0x8009D7B0
    // 0x8009E020: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_7;
    // 0x8009E020: nop

    after_7:
    // 0x8009E024: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8009E028: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009E02C: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8009E030: beq         $t7, $zero, L_8009E074
    if (ctx->r15 == 0) {
        // 0x8009E034: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009E074;
    }
    // 0x8009E034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E038: jal         0x80001D04
    // 0x8009E03C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8009E03C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8009E040: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009E044: lb          $v0, 0x6AB6($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AB6);
    // 0x8009E048: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009E04C: beq         $v0, $zero, L_8009E064
    if (ctx->r2 == 0) {
        // 0x8009E050: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8009E064;
    }
    // 0x8009E050: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009E054: beq         $v0, $at, L_8009E06C
    if (ctx->r2 == ctx->r1) {
        // 0x8009E058: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8009E06C;
    }
    // 0x8009E058: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8009E05C: b           L_8009E074
    // 0x8009E060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009E074;
    // 0x8009E060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009E064:
    // 0x8009E064: b           L_8009E070
    // 0x8009E068: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_8009E070;
    // 0x8009E068: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8009E06C:
    // 0x8009E06C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_8009E070:
    // 0x8009E070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009E074:
    // 0x8009E074: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8009E078: jr          $ra
    // 0x8009E07C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009E07C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void tt_menu_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E080: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009E084: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009E088: jal         0x8006ECD0
    // 0x8009E08C: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009E08C: nop

    after_0:
    // 0x8009E090: jal         0x8009F1C4
    // 0x8009E094: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    is_in_two_player_adventure(rdram, ctx);
        goto after_1;
    // 0x8009E094: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_1:
    // 0x8009E098: beq         $v0, $zero, L_8009E0B8
    if (ctx->r2 == 0) {
        // 0x8009E09C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009E0B8;
    }
    // 0x8009E09C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E0A0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8009E0A4: nop

    // 0x8009E0A8: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8009E0AC: nop

    // 0x8009E0B0: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8009E0B4: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
L_8009E0B8:
    // 0x8009E0B8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8009E0BC: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8009E0C0: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8009E0C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E0C8: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8009E0CC: bne         $t9, $zero, L_8009E0D8
    if (ctx->r25 != 0) {
        // 0x8009E0D0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009E0D8;
    }
    // 0x8009E0D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E0D4: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
L_8009E0D8:
    // 0x8009E0D8: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E0DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009E0E0: beq         $v1, $at, L_8009E12C
    if (ctx->r3 == ctx->r1) {
        // 0x8009E0E4: addiu       $a1, $zero, 0x18
        ctx->r5 = ADD32(0, 0X18);
            goto L_8009E12C;
    }
    // 0x8009E0E4: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009E0E8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009E0EC: beq         $v1, $at, L_8009E12C
    if (ctx->r3 == ctx->r1) {
        // 0x8009E0F0: addiu       $t2, $zero, 0x78
        ctx->r10 = ADD32(0, 0X78);
            goto L_8009E12C;
    }
    // 0x8009E0F0: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x8009E0F4: jal         0x8001B7B4
    // 0x8009E0F8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    has_ghost_to_save(rdram, ctx);
        goto after_2;
    // 0x8009E0F8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_2:
    // 0x8009E0FC: beq         $v0, $zero, L_8009E10C
    if (ctx->r2 == 0) {
        // 0x8009E100: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009E10C;
    }
    // 0x8009E100: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E104: addiu       $t3, $zero, 0x88
    ctx->r11 = ADD32(0, 0X88);
    // 0x8009E108: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_8009E10C:
    // 0x8009E10C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8009E110: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009E114: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009E118: addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    // 0x8009E11C: jal         0x800C543C
    // 0x8009E120: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_3;
    // 0x8009E120: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x8009E124: b           L_8009E144
    // 0x8009E128: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8009E144;
    // 0x8009E128: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8009E12C:
    // 0x8009E12C: addiu       $t5, $zero, 0xDC
    ctx->r13 = ADD32(0, 0XDC);
    // 0x8009E130: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8009E134: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009E138: jal         0x800C543C
    // 0x8009E13C: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_4;
    // 0x8009E13C: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_4:
    // 0x8009E140: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8009E144:
    // 0x8009E144: jal         0x800C54DC
    // 0x8009E148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_5;
    // 0x8009E148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8009E14C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8009E150: jal         0x8006A794
    // 0x8009E154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_6;
    // 0x8009E154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8009E158: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E15C: sb          $zero, 0x6AA4($at)
    MEM_B(0X6AA4, ctx->r1) = 0;
    // 0x8009E160: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009E164: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E168: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8009E16C: addiu       $t0, $t0, 0x6A82
    ctx->r8 = ADD32(ctx->r8, 0X6A82);
    // 0x8009E170: sb          $t6, 0x6AAE($at)
    MEM_B(0X6AAE, ctx->r1) = ctx->r14;
    // 0x8009E174: lb          $v1, 0x0($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X0);
    // 0x8009E178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009E17C: sltiu       $at, $v1, 0xB
    ctx->r1 = ctx->r3 < 0XB ? 1 : 0;
    // 0x8009E180: beq         $at, $zero, L_8009E8C0
    if (ctx->r1 == 0) {
        // 0x8009E184: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_8009E8C0;
    }
    // 0x8009E184: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8009E188: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8009E18C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009E190: addu        $at, $at, $t7
    gpr jr_addend_8009E19C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8009E194: lw          $t7, -0x7490($at)
    ctx->r15 = ADD32(ctx->r1, -0X7490);
    // 0x8009E198: nop

    // 0x8009E19C: jr          $t7
    // 0x8009E1A0: nop

    switch (jr_addend_8009E19C >> 2) {
        case 0: goto L_8009E1A4; break;
        case 1: goto L_8009E434; break;
        case 2: goto L_8009E8C0; break;
        case 3: goto L_8009E8C0; break;
        case 4: goto L_8009E4F4; break;
        case 5: goto L_8009E530; break;
        case 6: goto L_8009E5DC; break;
        case 7: goto L_8009E6D8; break;
        case 8: goto L_8009E780; break;
        case 9: goto L_8009E8C0; break;
        case 10: goto L_8009E1A4; break;
        default: switch_error(__func__, 0x8009E19C, 0x800E8B70);
    }
    // 0x8009E1A0: nop

L_8009E1A4:
    // 0x8009E1A4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009E1A8: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x8009E1AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009E1B0: lw          $a3, 0x2F4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X2F4);
    // 0x8009E1B4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8009E1B8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8009E1BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009E1C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E1C4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E1C8: jal         0x800C56C8
    // 0x8009E1CC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_7;
    // 0x8009E1CC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_7:
    // 0x8009E1D0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009E1D4: lw          $t2, -0x5E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E0);
    // 0x8009E1D8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009E1DC: lw          $a0, 0x11C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X11C);
    // 0x8009E1E0: jal         0x8009D6FC
    // 0x8009E1E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    render_dialogue_option(rdram, ctx);
        goto after_8;
    // 0x8009E1E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x8009E1E8: jal         0x8009F1C4
    // 0x8009E1EC: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_9;
    // 0x8009E1EC: nop

    after_9:
    // 0x8009E1F0: bne         $v0, $zero, L_8009E260
    if (ctx->r2 != 0) {
        // 0x8009E1F4: nop
    
            goto L_8009E260;
    }
    // 0x8009E1F4: nop

    // 0x8009E1F8: jal         0x8000E4C8
    // 0x8009E1FC: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_10;
    // 0x8009E1FC: nop

    after_10:
    // 0x8009E200: beq         $v0, $zero, L_8009E228
    if (ctx->r2 == 0) {
        // 0x8009E204: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8009E228;
    }
    // 0x8009E204: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009E208: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009E20C: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x8009E210: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009E214: lw          $a0, 0x104($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X104);
    // 0x8009E218: jal         0x8009D6FC
    // 0x8009E21C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_11;
    // 0x8009E21C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8009E220: b           L_8009E23C
    // 0x8009E224: nop

        goto L_8009E23C;
    // 0x8009E224: nop

L_8009E228:
    // 0x8009E228: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009E22C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009E230: lw          $a0, 0x108($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X108);
    // 0x8009E234: jal         0x8009D6FC
    // 0x8009E238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_12;
    // 0x8009E238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
L_8009E23C:
    // 0x8009E23C: jal         0x8001B7B4
    // 0x8009E240: nop

    has_ghost_to_save(rdram, ctx);
        goto after_13;
    // 0x8009E240: nop

    after_13:
    // 0x8009E244: beq         $v0, $zero, L_8009E260
    if (ctx->r2 == 0) {
        // 0x8009E248: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8009E260;
    }
    // 0x8009E248: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009E24C: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009E250: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009E254: lw          $a0, 0x6C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X6C);
    // 0x8009E258: jal         0x8009D6FC
    // 0x8009E25C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_14;
    // 0x8009E25C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
L_8009E260:
    // 0x8009E260: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009E264: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x8009E268: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009E26C: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x8009E270: jal         0x8009D6FC
    // 0x8009E274: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_option(rdram, ctx);
        goto after_15;
    // 0x8009E274: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_15:
    // 0x8009E278: jal         0x8009D7B0
    // 0x8009E27C: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_16;
    // 0x8009E27C: nop

    after_16:
    // 0x8009E280: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009E284: lb          $t7, 0x6AB6($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6AB6);
    // 0x8009E288: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009E28C: bne         $t7, $zero, L_8009E2FC
    if (ctx->r15 != 0) {
        // 0x8009E290: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_8009E2FC;
    }
    // 0x8009E290: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8009E294: lb          $v0, 0x69FC($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X69FC);
    // 0x8009E298: nop

    // 0x8009E29C: blez        $v0, L_8009E2CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009E2A0: nop
    
            goto L_8009E2CC;
    }
    // 0x8009E2A0: nop

    // 0x8009E2A4: jal         0x8000E4C8
    // 0x8009E2A8: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_17;
    // 0x8009E2A8: nop

    after_17:
    // 0x8009E2AC: bne         $v0, $zero, L_8009E2BC
    if (ctx->r2 != 0) {
        // 0x8009E2B0: addiu       $a0, $zero, 0x231
        ctx->r4 = ADD32(0, 0X231);
            goto L_8009E2BC;
    }
    // 0x8009E2B0: addiu       $a0, $zero, 0x231
    ctx->r4 = ADD32(0, 0X231);
    // 0x8009E2B4: jal         0x80036C0C
    // 0x8009E2B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_18;
    // 0x8009E2B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
L_8009E2BC:
    // 0x8009E2BC: jal         0x8000E4BC
    // 0x8009E2C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_time_trial_enabled(rdram, ctx);
        goto after_19;
    // 0x8009E2C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x8009E2C4: b           L_8009E2FC
    // 0x8009E2C8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
        goto L_8009E2FC;
    // 0x8009E2C8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8009E2CC:
    // 0x8009E2CC: bgez        $v0, L_8009E2FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009E2D0: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_8009E2FC;
    }
    // 0x8009E2D0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8009E2D4: jal         0x8000E4C8
    // 0x8009E2D8: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_20;
    // 0x8009E2D8: nop

    after_20:
    // 0x8009E2DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009E2E0: bne         $v0, $at, L_8009E2F0
    if (ctx->r2 != ctx->r1) {
        // 0x8009E2E4: addiu       $a0, $zero, 0x230
        ctx->r4 = ADD32(0, 0X230);
            goto L_8009E2F0;
    }
    // 0x8009E2E4: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    // 0x8009E2E8: jal         0x80036C0C
    // 0x8009E2EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_21;
    // 0x8009E2EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
L_8009E2F0:
    // 0x8009E2F0: jal         0x8000E4BC
    // 0x8009E2F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_time_trial_enabled(rdram, ctx);
        goto after_22;
    // 0x8009E2F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x8009E2F8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8009E2FC:
    // 0x8009E2FC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8009E300: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8009E304: beq         $t9, $zero, L_8009E3D0
    if (ctx->r25 == 0) {
        // 0x8009E308: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8009E3D0;
    }
    // 0x8009E308: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009E30C: lb          $t1, 0x6A82($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X6A82);
    // 0x8009E310: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8009E314: beq         $t1, $at, L_8009E3D0
    if (ctx->r9 == ctx->r1) {
        // 0x8009E318: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009E3D0;
    }
    // 0x8009E318: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E31C: lb          $v1, 0x6AB6($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6AB6);
    // 0x8009E320: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009E324: beq         $v1, $at, L_8009E340
    if (ctx->r3 == ctx->r1) {
        // 0x8009E328: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009E340;
    }
    // 0x8009E328: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009E32C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009E330: beq         $v1, $at, L_8009E378
    if (ctx->r3 == ctx->r1) {
        // 0x8009E334: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009E378;
    }
    // 0x8009E334: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009E338: b           L_8009E3C8
    // 0x8009E33C: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
        goto L_8009E3C8;
    // 0x8009E33C: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
L_8009E340:
    // 0x8009E340: jal         0x80001D04
    // 0x8009E344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_23;
    // 0x8009E344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x8009E348: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009E34C: addiu       $a0, $a0, 0x6938
    ctx->r4 = ADD32(ctx->r4, 0X6938);
    // 0x8009E350: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8009E354: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E358: sw          $zero, 0x6940($at)
    MEM_W(0X6940, ctx->r1) = 0;
    // 0x8009E35C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E360: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E364: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8009E368: lb          $v1, 0x6AB6($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6AB6);
    // 0x8009E36C: b           L_8009E3C4
    // 0x8009E370: sb          $t2, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r10;
        goto L_8009E3C4;
    // 0x8009E370: sb          $t2, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r10;
    // 0x8009E374: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
L_8009E378:
    // 0x8009E378: jal         0x80001D04
    // 0x8009E37C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_24;
    // 0x8009E37C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x8009E380: addiu       $a0, $zero, 0x22E
    ctx->r4 = ADD32(0, 0X22E);
    // 0x8009E384: jal         0x80036C0C
    // 0x8009E388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_25;
    // 0x8009E388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x8009E38C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009E390: jal         0x8009CBB8
    // 0x8009E394: addiu       $a0, $a0, 0x23AC
    ctx->r4 = ADD32(ctx->r4, 0X23AC);
    menu_assetgroup_load(rdram, ctx);
        goto after_26;
    // 0x8009E394: addiu       $a0, $a0, 0x23AC
    ctx->r4 = ADD32(ctx->r4, 0X23AC);
    after_26:
    // 0x8009E398: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009E39C: jal         0x8009CDE8
    // 0x8009E3A0: addiu       $a0, $a0, 0x23C0
    ctx->r4 = ADD32(ctx->r4, 0X23C0);
    menu_imagegroup_load(rdram, ctx);
        goto after_27;
    // 0x8009E3A0: addiu       $a0, $a0, 0x23C0
    ctx->r4 = ADD32(ctx->r4, 0X23C0);
    after_27:
    // 0x8009E3A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8009E3A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009E3AC: sb          $t3, 0x23A8($at)
    MEM_B(0X23A8, ctx->r1) = ctx->r11;
    // 0x8009E3B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E3B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E3B8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8009E3BC: lb          $v1, 0x6AB6($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6AB6);
    // 0x8009E3C0: sb          $t4, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r12;
L_8009E3C4:
    // 0x8009E3C4: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
L_8009E3C8:
    // 0x8009E3C8: b           L_8009E3EC
    // 0x8009E3CC: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
        goto L_8009E3EC;
    // 0x8009E3CC: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_8009E3D0:
    // 0x8009E3D0: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8009E3D4: beq         $t7, $zero, L_8009E3EC
    if (ctx->r15 == 0) {
        // 0x8009E3D8: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8009E3EC;
    }
    // 0x8009E3D8: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009E3DC: jal         0x80001D04
    // 0x8009E3E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_28;
    // 0x8009E3E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
    // 0x8009E3E4: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009E3E8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_8009E3EC:
    // 0x8009E3EC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E3F0: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E3F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009E3F8: bne         $v1, $at, L_8009E404
    if (ctx->r3 != ctx->r1) {
        // 0x8009E3FC: addiu       $t1, $zero, 0xA
        ctx->r9 = ADD32(0, 0XA);
            goto L_8009E404;
    }
    // 0x8009E3FC: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8009E400: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8009E404:
    // 0x8009E404: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8009E408: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009E40C: bne         $t9, $at, L_8009E420
    if (ctx->r25 != ctx->r1) {
        // 0x8009E410: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8009E420;
    }
    // 0x8009E410: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8009E414: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E418: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
    // 0x8009E41C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_8009E420:
    // 0x8009E420: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8009E424: bne         $v1, $at, L_8009E8C4
    if (ctx->r3 != ctx->r1) {
        // 0x8009E428: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8009E8C4;
    }
    // 0x8009E428: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009E42C: b           L_8009E8C0
    // 0x8009E430: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_8009E8C0;
    // 0x8009E430: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_8009E434:
    // 0x8009E434: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009E438: lw          $a0, 0x6948($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6948);
    // 0x8009E43C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009E440: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8009E444: addiu       $t6, $zero, 0x3A
    ctx->r14 = ADD32(0, 0X3A);
    // 0x8009E448: beq         $a1, $zero, L_8009E460
    if (ctx->r5 == 0) {
        // 0x8009E44C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8009E460;
    }
    // 0x8009E44C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8009E450:
    // 0x8009E450: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x8009E454: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009E458: bne         $t3, $zero, L_8009E450
    if (ctx->r11 != 0) {
        // 0x8009E45C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8009E450;
    }
    // 0x8009E45C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8009E460:
    // 0x8009E460: blez        $v1, L_8009E4D0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009E464: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8009E4D0;
    }
    // 0x8009E464: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8009E468: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8009E46C: beq         $a1, $zero, L_8009E4D0
    if (ctx->r5 == 0) {
        // 0x8009E470: subu        $a2, $t6, $t5
        ctx->r6 = SUB32(ctx->r14, ctx->r13);
            goto L_8009E4D0;
    }
    // 0x8009E470: subu        $a2, $t6, $t5
    ctx->r6 = SUB32(ctx->r14, ctx->r13);
    // 0x8009E474: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8009E478: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009E47C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_8009E480:
    // 0x8009E480: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8009E484: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009E488: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009E48C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E490: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E494: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8009E498: jal         0x800C56C8
    // 0x8009E49C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    render_dialogue_text(rdram, ctx);
        goto after_29;
    // 0x8009E49C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_29:
    // 0x8009E4A0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8009E4A4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009E4A8: lw          $t9, 0x6948($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6948);
    // 0x8009E4AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009E4B0: addu        $t1, $t9, $v1
    ctx->r9 = ADD32(ctx->r25, ctx->r3);
    // 0x8009E4B4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8009E4B8: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x8009E4BC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8009E4C0: bne         $a3, $zero, L_8009E480
    if (ctx->r7 != 0) {
        // 0x8009E4C4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8009E480;
    }
    // 0x8009E4C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009E4C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009E4CC: addiu       $t0, $t0, 0x6A82
    ctx->r8 = ADD32(ctx->r8, 0X6A82);
L_8009E4D0:
    // 0x8009E4D0: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8009E4D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E4D8: andi        $t3, $t2, 0xC000
    ctx->r11 = ctx->r10 & 0XC000;
    // 0x8009E4DC: beq         $t3, $zero, L_8009E4E8
    if (ctx->r11 == 0) {
        // 0x8009E4E0: nop
    
            goto L_8009E4E8;
    }
    // 0x8009E4E0: nop

    // 0x8009E4E4: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_8009E4E8:
    // 0x8009E4E8: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E4EC: b           L_8009E8C4
    // 0x8009E4F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E8C4;
    // 0x8009E4F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E4F4:
    // 0x8009E4F4: andi        $t4, $a0, 0xC000
    ctx->r12 = ctx->r4 & 0XC000;
    // 0x8009E4F8: beq         $t4, $zero, L_8009E8C0
    if (ctx->r12 == 0) {
        // 0x8009E4FC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8009E8C0;
    }
    // 0x8009E4FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009E500: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8009E504: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009E508: sb          $zero, 0x23A8($at)
    MEM_B(0X23A8, ctx->r1) = 0;
    // 0x8009E50C: jal         0x8009C9EC
    // 0x8009E510: addiu       $a0, $a0, 0x23AC
    ctx->r4 = ADD32(ctx->r4, 0X23AC);
    menu_assetgroup_free(rdram, ctx);
        goto after_30;
    // 0x8009E510: addiu       $a0, $a0, 0x23AC
    ctx->r4 = ADD32(ctx->r4, 0X23AC);
    after_30:
    // 0x8009E514: addiu       $a0, $zero, 0x22F
    ctx->r4 = ADD32(0, 0X22F);
    // 0x8009E518: jal         0x80036C0C
    // 0x8009E51C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_31;
    // 0x8009E51C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x8009E520: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E524: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E528: b           L_8009E8C4
    // 0x8009E52C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E8C4;
    // 0x8009E52C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E530:
    // 0x8009E530: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009E534: lw          $v0, -0x5E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E0);
    // 0x8009E538: addiu       $v1, $zero, 0xD0
    ctx->r3 = ADD32(0, 0XD0);
    // 0x8009E53C: lw          $t6, 0xD0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD0);
    // 0x8009E540: nop

    // 0x8009E544: beq         $t6, $zero, L_8009E5AC
    if (ctx->r14 == 0) {
        // 0x8009E548: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_8009E5AC;
    }
    // 0x8009E548: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8009E54C: lw          $a3, 0xD0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XD0);
    // 0x8009E550: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8009E554: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8009E558:
    // 0x8009E558: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8009E55C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009E560: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8009E564: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E568: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E56C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8009E570: jal         0x800C56C8
    // 0x8009E574: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    render_dialogue_text(rdram, ctx);
        goto after_32;
    // 0x8009E574: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_32:
    // 0x8009E578: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8009E57C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009E580: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x8009E584: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009E588: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009E58C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8009E590: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8009E594: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8009E598: bne         $a3, $zero, L_8009E558
    if (ctx->r7 != 0) {
        // 0x8009E59C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8009E558;
    }
    // 0x8009E59C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009E5A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009E5A4: addiu       $t0, $t0, 0x6A82
    ctx->r8 = ADD32(ctx->r8, 0X6A82);
    // 0x8009E5A8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
L_8009E5AC:
    // 0x8009E5AC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8009E5B0: andi        $t2, $t1, 0xC000
    ctx->r10 = ctx->r9 & 0XC000;
    // 0x8009E5B4: beq         $t2, $zero, L_8009E5D0
    if (ctx->r10 == 0) {
        // 0x8009E5B8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009E5D0;
    }
    // 0x8009E5B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E5BC: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8009E5C0: nop

    // 0x8009E5C4: ori         $t6, $t4, 0x2
    ctx->r14 = ctx->r12 | 0X2;
    // 0x8009E5C8: sw          $t6, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r14;
    // 0x8009E5CC: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_8009E5D0:
    // 0x8009E5D0: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E5D4: b           L_8009E8C4
    // 0x8009E5D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E8C4;
    // 0x8009E5D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E5DC:
    // 0x8009E5DC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009E5E0: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009E5E4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009E5E8: lw          $a3, 0x27C($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X27C);
    // 0x8009E5EC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8009E5F0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009E5F4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009E5F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E5FC: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E600: jal         0x800C56C8
    // 0x8009E604: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    render_dialogue_text(rdram, ctx);
        goto after_33;
    // 0x8009E604: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_33:
    // 0x8009E608: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009E60C: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x8009E610: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009E614: lw          $a3, 0x280($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X280);
    // 0x8009E618: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009E61C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009E620: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009E624: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E628: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E62C: jal         0x800C56C8
    // 0x8009E630: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    render_dialogue_text(rdram, ctx);
        goto after_34;
    // 0x8009E630: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_34:
    // 0x8009E634: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009E638: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009E63C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009E640: lw          $a3, 0x284($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X284);
    // 0x8009E644: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8009E648: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8009E64C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009E650: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E654: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E658: jal         0x800C56C8
    // 0x8009E65C: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    render_dialogue_text(rdram, ctx);
        goto after_35;
    // 0x8009E65C: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    after_35:
    // 0x8009E660: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8009E664: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009E668: andi        $t7, $t5, 0x9000
    ctx->r15 = ctx->r13 & 0X9000;
    // 0x8009E66C: beq         $t7, $zero, L_8009E6A8
    if (ctx->r15 == 0) {
        // 0x8009E670: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_8009E6A8;
    }
    // 0x8009E670: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8009E674: jal         0x80001D04
    // 0x8009E678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_36;
    // 0x8009E678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_36:
    // 0x8009E67C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009E680: addiu       $a0, $a0, 0x6938
    ctx->r4 = ADD32(ctx->r4, 0X6938);
    // 0x8009E684: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8009E688: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8009E68C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E690: sw          $t8, 0x6940($at)
    MEM_W(0X6940, ctx->r1) = ctx->r24;
    // 0x8009E694: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E698: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8009E69C: b           L_8009E6C8
    // 0x8009E6A0: sb          $t9, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r25;
        goto L_8009E6C8;
    // 0x8009E6A0: sb          $t9, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r25;
    // 0x8009E6A4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
L_8009E6A8:
    // 0x8009E6A8: nop

    // 0x8009E6AC: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x8009E6B0: beq         $t2, $zero, L_8009E6C8
    if (ctx->r10 == 0) {
        // 0x8009E6B4: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8009E6C8;
    }
    // 0x8009E6B4: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009E6B8: jal         0x80001D04
    // 0x8009E6BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_37;
    // 0x8009E6BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_37:
    // 0x8009E6C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E6C4: sb          $zero, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = 0;
L_8009E6C8:
    // 0x8009E6C8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E6CC: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E6D0: b           L_8009E8C4
    // 0x8009E6D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E8C4;
    // 0x8009E6D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E6D8:
    // 0x8009E6D8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009E6DC: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009E6E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009E6E4: lw          $a3, 0x288($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X288);
    // 0x8009E6E8: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8009E6EC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8009E6F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009E6F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E6F8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E6FC: jal         0x800C56C8
    // 0x8009E700: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    render_dialogue_text(rdram, ctx);
        goto after_38;
    // 0x8009E700: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_38:
    // 0x8009E704: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009E708: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009E70C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009E710: lw          $a3, 0x2E8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X2E8);
    // 0x8009E714: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8009E718: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009E71C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009E720: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E724: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E728: jal         0x800C56C8
    // 0x8009E72C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    render_dialogue_text(rdram, ctx);
        goto after_39;
    // 0x8009E72C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_39:
    // 0x8009E730: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009E734: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x8009E738: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009E73C: lw          $a3, 0x2EC($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X2EC);
    // 0x8009E740: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009E744: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009E748: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009E74C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E750: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E754: jal         0x800C56C8
    // 0x8009E758: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    render_dialogue_text(rdram, ctx);
        goto after_40;
    // 0x8009E758: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    after_40:
    // 0x8009E75C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8009E760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E764: andi        $t6, $t4, 0xD000
    ctx->r14 = ctx->r12 & 0XD000;
    // 0x8009E768: beq         $t6, $zero, L_8009E774
    if (ctx->r14 == 0) {
        // 0x8009E76C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009E774;
    }
    // 0x8009E76C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E770: sb          $zero, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = 0;
L_8009E774:
    // 0x8009E774: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E778: b           L_8009E8C4
    // 0x8009E77C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E8C4;
    // 0x8009E77C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E780:
    // 0x8009E780: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009E784: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x8009E788: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009E78C: lw          $a3, 0x1F0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X1F0);
    // 0x8009E790: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8009E794: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009E798: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8009E79C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E7A0: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E7A4: jal         0x800C56C8
    // 0x8009E7A8: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    render_dialogue_text(rdram, ctx);
        goto after_41;
    // 0x8009E7A8: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_41:
    // 0x8009E7AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009E7B0: addiu       $a0, $a0, 0x6938
    ctx->r4 = ADD32(ctx->r4, 0X6938);
    // 0x8009E7B4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8009E7B8: nop

    // 0x8009E7BC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8009E7C0: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x8009E7C4: bne         $at, $zero, L_8009E8B4
    if (ctx->r1 != 0) {
        // 0x8009E7C8: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_8009E8B4;
    }
    // 0x8009E7C8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009E7CC: jal         0x8001B76C
    // 0x8009E7D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_save_player_ghost(rdram, ctx);
        goto after_42;
    // 0x8009E7D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_42:
    // 0x8009E7D4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8009E7D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009E7DC: bne         $v1, $at, L_8009E7F4
    if (ctx->r3 != ctx->r1) {
        // 0x8009E7E0: sltiu       $at, $v1, 0xA
        ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
            goto L_8009E7F4;
    }
    // 0x8009E7E0: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
    // 0x8009E7E4: jal         0x8001B76C
    // 0x8009E7E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_save_player_ghost(rdram, ctx);
        goto after_43;
    // 0x8009E7E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_43:
    // 0x8009E7EC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8009E7F0: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
L_8009E7F4:
    // 0x8009E7F4: beq         $at, $zero, L_8009E898
    if (ctx->r1 == 0) {
        // 0x8009E7F8: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_8009E898;
    }
    // 0x8009E7F8: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8009E7FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009E800: addu        $at, $at, $t2
    gpr jr_addend_8009E80C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8009E804: lw          $t2, -0x7464($at)
    ctx->r10 = ADD32(ctx->r1, -0X7464);
    // 0x8009E808: nop

    // 0x8009E80C: jr          $t2
    // 0x8009E810: nop

    switch (jr_addend_8009E80C >> 2) {
        case 0: goto L_8009E814; break;
        case 1: goto L_8009E838; break;
        case 2: goto L_8009E898; break;
        case 3: goto L_8009E898; break;
        case 4: goto L_8009E858; break;
        case 5: goto L_8009E898; break;
        case 6: goto L_8009E858; break;
        case 7: goto L_8009E828; break;
        case 8: goto L_8009E898; break;
        case 9: goto L_8009E878; break;
        default: switch_error(__func__, 0x8009E80C, 0x800E8B9C);
    }
    // 0x8009E810: nop

L_8009E814:
    // 0x8009E814: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009E818: lw          $t4, 0x6940($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6940);
    // 0x8009E81C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E820: b           L_8009E8B4
    // 0x8009E824: sb          $t4, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r12;
        goto L_8009E8B4;
    // 0x8009E824: sb          $t4, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r12;
L_8009E828:
    // 0x8009E828: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8009E82C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E830: b           L_8009E8B4
    // 0x8009E834: sb          $t6, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r14;
        goto L_8009E8B4;
    // 0x8009E834: sb          $t6, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r14;
L_8009E838:
    // 0x8009E838: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009E83C: addiu       $t3, $t3, 0xF58
    ctx->r11 = ADD32(ctx->r11, 0XF58);
    // 0x8009E840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E844: sw          $t3, 0x6948($at)
    MEM_W(0X6948, ctx->r1) = ctx->r11;
    // 0x8009E848: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E84C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009E850: b           L_8009E8B4
    // 0x8009E854: sb          $t5, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r13;
        goto L_8009E8B4;
    // 0x8009E854: sb          $t5, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r13;
L_8009E858:
    // 0x8009E858: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009E85C: addiu       $t7, $t7, 0xF44
    ctx->r15 = ADD32(ctx->r15, 0XF44);
    // 0x8009E860: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E864: sw          $t7, 0x6948($at)
    MEM_W(0X6948, ctx->r1) = ctx->r15;
    // 0x8009E868: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E86C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009E870: b           L_8009E8B4
    // 0x8009E874: sb          $t8, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r24;
        goto L_8009E8B4;
    // 0x8009E874: sb          $t8, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r24;
L_8009E878:
    // 0x8009E878: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009E87C: addiu       $t9, $t9, 0xF6C
    ctx->r25 = ADD32(ctx->r25, 0XF6C);
    // 0x8009E880: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E884: sw          $t9, 0x6948($at)
    MEM_W(0X6948, ctx->r1) = ctx->r25;
    // 0x8009E888: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E88C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009E890: b           L_8009E8B4
    // 0x8009E894: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
        goto L_8009E8B4;
    // 0x8009E894: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
L_8009E898:
    // 0x8009E898: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009E89C: addiu       $t2, $t2, 0xF30
    ctx->r10 = ADD32(ctx->r10, 0XF30);
    // 0x8009E8A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E8A4: sw          $t2, 0x6948($at)
    MEM_W(0X6948, ctx->r1) = ctx->r10;
    // 0x8009E8A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E8AC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009E8B0: sb          $t4, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r12;
L_8009E8B4:
    // 0x8009E8B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E8B8: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E8BC: nop

L_8009E8C0:
    // 0x8009E8C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E8C4:
    // 0x8009E8C4: beq         $v1, $at, L_8009E8DC
    if (ctx->r3 == ctx->r1) {
        // 0x8009E8C8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009E8DC;
    }
    // 0x8009E8C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E8CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009E8D0: beq         $v1, $at, L_8009E8DC
    if (ctx->r3 == ctx->r1) {
        // 0x8009E8D4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8009E8DC;
    }
    // 0x8009E8D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009E8D8: bne         $v1, $at, L_8009E904
    if (ctx->r3 != ctx->r1) {
        // 0x8009E8DC: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_8009E904;
    }
L_8009E8DC:
    // 0x8009E8DC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009E8E0: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x8009E8E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8009E8E8: lw          $a3, 0x100($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X100);
    // 0x8009E8EC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8009E8F0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8009E8F4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009E8F8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E8FC: jal         0x800C56C8
    // 0x8009E900: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_44;
    // 0x8009E900: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_44:
L_8009E904:
    // 0x8009E904: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E908: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8009E90C: jr          $ra
    // 0x8009E910: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8009E910: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void dialogue_tt_gamestatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E914: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8009E918: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009E91C: addiu       $v1, $v1, 0x23A8
    ctx->r3 = ADD32(ctx->r3, 0X23A8);
    // 0x8009E920: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009E924: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8009E928: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8009E92C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8009E930: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8009E934: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8009E938: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8009E93C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8009E940: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8009E944: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8009E948: bne         $s4, $v0, L_8009E95C
    if (ctx->r20 != ctx->r2) {
        // 0x8009E94C: swc1        $f20, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
            goto L_8009E95C;
    }
    // 0x8009E94C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8009E950: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8009E954: b           L_8009ED00
    // 0x8009E958: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
        goto L_8009ED00;
    // 0x8009E958: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_8009E95C:
    // 0x8009E95C: jal         0x8006ECD0
    // 0x8009E960: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009E960: nop

    after_0:
    // 0x8009E964: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8009E968: jal         0x80068748
    // 0x8009E96C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x8009E96C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x8009E970: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8009E974: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8009E978: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8009E97C: bne         $t7, $zero, L_8009E98C
    if (ctx->r15 != 0) {
        // 0x8009E980: lui         $s2, 0x800E
        ctx->r18 = S32(0X800E << 16);
            goto L_8009E98C;
    }
    // 0x8009E980: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8009E984: b           L_8009E990
    // 0x8009E988: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
        goto L_8009E990;
    // 0x8009E988: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
L_8009E98C:
    // 0x8009E98C: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
L_8009E990:
    // 0x8009E990: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8009E994: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x8009E998: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8009E99C: beq         $t0, $zero, L_8009E9A8
    if (ctx->r8 == 0) {
        // 0x8009E9A0: addiu       $s2, $s2, -0x324
        ctx->r18 = ADD32(ctx->r18, -0X324);
            goto L_8009E9A8;
    }
    // 0x8009E9A0: addiu       $s2, $s2, -0x324
    ctx->r18 = ADD32(ctx->r18, -0X324);
    // 0x8009E9A4: addiu       $s3, $zero, 0x9
    ctx->r19 = ADD32(0, 0X9);
L_8009E9A8:
    // 0x8009E9A8: addiu       $t1, $zero, -0x4A
    ctx->r9 = ADD32(0, -0X4A);
    // 0x8009E9AC: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8009E9B0: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009E9B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009E9B8: sll         $v0, $s3, 5
    ctx->r2 = S32(ctx->r19 << 5);
    // 0x8009E9BC: addiu       $t4, $zero, 0x41
    ctx->r12 = ADD32(0, 0X41);
    // 0x8009E9C0: subu        $t5, $t4, $s5
    ctx->r13 = SUB32(ctx->r12, ctx->r21);
    // 0x8009E9C4: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8009E9C8: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8009E9CC: swc1        $f6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f6.u32l;
    // 0x8009E9D0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8009E9D4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009E9D8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8009E9DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8009E9E0: jal         0x8009CFA4
    // 0x8009E9E4: swc1        $f10, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_2;
    // 0x8009E9E4: swc1        $f10, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f10.u32l;
    after_2:
    // 0x8009E9E8: jal         0x8007C36C
    // 0x8009E9EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_3;
    // 0x8009E9EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8009E9F0: addiu       $t8, $zero, -0x1D
    ctx->r24 = ADD32(0, -0X1D);
    // 0x8009E9F4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8009E9F8: addiu       $t0, $zero, 0x62
    ctx->r8 = ADD32(0, 0X62);
    // 0x8009E9FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009EA00: subu        $t1, $t0, $s5
    ctx->r9 = SUB32(ctx->r8, ctx->r21);
    // 0x8009EA04: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8009EA08: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8009EA0C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8009EA10: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009EA14: swc1        $f18, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f18.u32l;
    // 0x8009EA18: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009EA1C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8009EA20: swc1        $f20, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f20.u32l;
    // 0x8009EA24: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8009EA28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009EA2C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8009EA30: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x8009EA34: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009EA38: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x8009EA3C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8009EA40: nop

    // 0x8009EA44: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8009EA48: nop

    // 0x8009EA4C: lh          $a1, 0x0($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X0);
    // 0x8009EA50: nop

    // 0x8009EA54: div         $zero, $a1, $s0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r16)));
    // 0x8009EA58: bne         $s0, $zero, L_8009EA64
    if (ctx->r16 != 0) {
        // 0x8009EA5C: nop
    
            goto L_8009EA64;
    }
    // 0x8009EA5C: nop

    // 0x8009EA60: break       7
    do_break(2148133472);
L_8009EA64:
    // 0x8009EA64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009EA68: bne         $s0, $at, L_8009EA7C
    if (ctx->r16 != ctx->r1) {
        // 0x8009EA6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009EA7C;
    }
    // 0x8009EA6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009EA70: bne         $a1, $at, L_8009EA7C
    if (ctx->r5 != ctx->r1) {
        // 0x8009EA74: nop
    
            goto L_8009EA7C;
    }
    // 0x8009EA74: nop

    // 0x8009EA78: break       6
    do_break(2148133496);
L_8009EA7C:
    // 0x8009EA7C: mflo        $v0
    ctx->r2 = lo;
    // 0x8009EA80: beq         $v0, $zero, L_8009EACC
    if (ctx->r2 == 0) {
        // 0x8009EA84: nop
    
            goto L_8009EACC;
    }
    // 0x8009EA84: nop

    // 0x8009EA88: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8009EA8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009EA90: jal         0x8009CFA4
    // 0x8009EA94: sh          $v0, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r2;
    menu_element_render(rdram, ctx);
        goto after_4;
    // 0x8009EA94: sh          $v0, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r2;
    after_4:
    // 0x8009EA98: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8009EA9C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8009EAA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009EAA4: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8009EAA8: nop

    // 0x8009EAAC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8009EAB0: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
    // 0x8009EAB4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8009EAB8: nop

    // 0x8009EABC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8009EAC0: nop

    // 0x8009EAC4: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x8009EAC8: nop

L_8009EACC:
    // 0x8009EACC: div         $zero, $a1, $s0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r16)));
    // 0x8009EAD0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8009EAD4: bne         $s0, $zero, L_8009EAE0
    if (ctx->r16 != 0) {
        // 0x8009EAD8: nop
    
            goto L_8009EAE0;
    }
    // 0x8009EAD8: nop

    // 0x8009EADC: break       7
    do_break(2148133596);
L_8009EAE0:
    // 0x8009EAE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009EAE4: bne         $s0, $at, L_8009EAF8
    if (ctx->r16 != ctx->r1) {
        // 0x8009EAE8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009EAF8;
    }
    // 0x8009EAE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009EAEC: bne         $a1, $at, L_8009EAF8
    if (ctx->r5 != ctx->r1) {
        // 0x8009EAF0: nop
    
            goto L_8009EAF8;
    }
    // 0x8009EAF0: nop

    // 0x8009EAF4: break       6
    do_break(2148133620);
L_8009EAF8:
    // 0x8009EAF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009EAFC: mfhi        $t8
    ctx->r24 = hi;
    // 0x8009EB00: sh          $t8, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r24;
    // 0x8009EB04: jal         0x8009CFA4
    // 0x8009EB08: nop

    menu_element_render(rdram, ctx);
        goto after_5;
    // 0x8009EB08: nop

    after_5:
    // 0x8009EB0C: addiu       $t0, $zero, -0x31
    ctx->r8 = ADD32(0, -0X31);
    // 0x8009EB10: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8009EB14: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB18: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009EB1C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8009EB20: swc1        $f8, 0x14C($t1)
    MEM_W(0X14C, ctx->r9) = ctx->f8.u32l;
    // 0x8009EB24: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB28: jal         0x8009CFA4
    // 0x8009EB2C: swc1        $f20, 0x150($t2)
    MEM_W(0X150, ctx->r10) = ctx->f20.u32l;
    menu_element_render(rdram, ctx);
        goto after_6;
    // 0x8009EB2C: swc1        $f20, 0x150($t2)
    MEM_W(0X150, ctx->r10) = ctx->f20.u32l;
    after_6:
    // 0x8009EB30: jal         0x8007C36C
    // 0x8009EB34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    sprite_opaque(rdram, ctx);
        goto after_7;
    // 0x8009EB34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_7:
    // 0x8009EB38: addiu       $t3, $zero, -0x59
    ctx->r11 = ADD32(0, -0X59);
    // 0x8009EB3C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8009EB40: addiu       $s5, $s5, 0x32
    ctx->r21 = ADD32(ctx->r21, 0X32);
    // 0x8009EB44: addiu       $t5, $zero, 0x5F
    ctx->r13 = ADD32(0, 0X5F);
    // 0x8009EB48: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009EB4C: subu        $t6, $t5, $s5
    ctx->r14 = SUB32(ctx->r13, ctx->r21);
    // 0x8009EB50: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB54: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8009EB58: swc1        $f16, 0x1EC($t4)
    MEM_W(0X1EC, ctx->r12) = ctx->f16.u32l;
    // 0x8009EB5C: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009EB60: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB64: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8009EB68: swc1        $f20, 0x1F0($t7)
    MEM_W(0X1F0, ctx->r15) = ctx->f20.u32l;
    // 0x8009EB6C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8009EB70: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB74: lbu         $t9, 0x17($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X17);
    // 0x8009EB78: jal         0x8009CFA4
    // 0x8009EB7C: sh          $t9, 0x1F8($t0)
    MEM_H(0X1F8, ctx->r8) = ctx->r25;
    menu_element_render(rdram, ctx);
        goto after_8;
    // 0x8009EB7C: sh          $t9, 0x1F8($t0)
    MEM_H(0X1F8, ctx->r8) = ctx->r25;
    after_8:
    // 0x8009EB80: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009EB84: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB88: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8009EB8C: swc1        $f4, 0x20C($t1)
    MEM_W(0X20C, ctx->r9) = ctx->f4.u32l;
    // 0x8009EB90: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009EB94: nop

    // 0x8009EB98: swc1        $f20, 0x210($t2)
    MEM_W(0X210, ctx->r10) = ctx->f20.u32l;
    // 0x8009EB9C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8009EBA0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8009EBA4: lbu         $t4, 0x16($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X16);
    // 0x8009EBA8: jal         0x8009CFA4
    // 0x8009EBAC: sh          $t4, 0x218($t5)
    MEM_H(0X218, ctx->r13) = ctx->r12;
    menu_element_render(rdram, ctx);
        goto after_9;
    // 0x8009EBAC: sh          $t4, 0x218($t5)
    MEM_H(0X218, ctx->r13) = ctx->r12;
    after_9:
    // 0x8009EBB0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8009EBB4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8009EBB8: lhu         $v1, 0xE($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0XE);
    // 0x8009EBBC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009EBC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8009EBC4:
    // 0x8009EBC4: and         $t7, $v1, $v0
    ctx->r15 = ctx->r3 & ctx->r2;
    // 0x8009EBC8: bne         $v0, $t7, L_8009EBD4
    if (ctx->r2 != ctx->r15) {
        // 0x8009EBCC: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8009EBD4;
    }
    // 0x8009EBCC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8009EBD0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8009EBD4:
    // 0x8009EBD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009EBD8: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8009EBDC: bne         $at, $zero, L_8009EBC4
    if (ctx->r1 != 0) {
        // 0x8009EBE0: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8009EBC4;
    }
    // 0x8009EBE0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8009EBE4: addiu       $s5, $s5, 0x32
    ctx->r21 = ADD32(ctx->r21, 0X32);
    // 0x8009EBE8: addiu       $t9, $zero, 0x5F
    ctx->r25 = ADD32(0, 0X5F);
    // 0x8009EBEC: subu        $t0, $t9, $s5
    ctx->r8 = SUB32(ctx->r25, ctx->r21);
    // 0x8009EBF0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8009EBF4: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
    // 0x8009EBF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009EBFC: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
L_8009EC00:
    // 0x8009EC00: addiu       $t1, $s1, -0x7C
    ctx->r9 = ADD32(ctx->r17, -0X7C);
    // 0x8009EC04: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8009EC08: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009EC0C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009EC10: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8009EC14: swc1        $f10, 0x1AC($t2)
    MEM_W(0X1AC, ctx->r10) = ctx->f10.u32l;
    // 0x8009EC18: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8009EC1C: beq         $at, $zero, L_8009EC30
    if (ctx->r1 == 0) {
        // 0x8009EC20: swc1        $f20, 0x1B0($t3)
        MEM_W(0X1B0, ctx->r11) = ctx->f20.u32l;
            goto L_8009EC30;
    }
    // 0x8009EC20: swc1        $f20, 0x1B0($t3)
    MEM_W(0X1B0, ctx->r11) = ctx->f20.u32l;
    // 0x8009EC24: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8009EC28: b           L_8009EC3C
    // 0x8009EC2C: sh          $s4, 0x1B8($t4)
    MEM_H(0X1B8, ctx->r12) = ctx->r20;
        goto L_8009EC3C;
    // 0x8009EC2C: sh          $s4, 0x1B8($t4)
    MEM_H(0X1B8, ctx->r12) = ctx->r20;
L_8009EC30:
    // 0x8009EC30: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8009EC34: nop

    // 0x8009EC38: sh          $zero, 0x1B8($t5)
    MEM_H(0X1B8, ctx->r13) = 0;
L_8009EC3C:
    // 0x8009EC3C: jal         0x8009CFA4
    // 0x8009EC40: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    menu_element_render(rdram, ctx);
        goto after_10;
    // 0x8009EC40: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_10:
    // 0x8009EC44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009EC48: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009EC4C: bne         $at, $zero, L_8009EC00
    if (ctx->r1 != 0) {
        // 0x8009EC50: addiu       $s1, $s1, 0x1E
        ctx->r17 = ADD32(ctx->r17, 0X1E);
            goto L_8009EC00;
    }
    // 0x8009EC50: addiu       $s1, $s1, 0x1E
    ctx->r17 = ADD32(ctx->r17, 0X1E);
    // 0x8009EC54: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8009EC58: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009EC5C: lhu         $v1, 0x8($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X8);
    // 0x8009EC60: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8009EC64: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8009EC68:
    // 0x8009EC68: and         $t7, $v1, $v0
    ctx->r15 = ctx->r3 & ctx->r2;
    // 0x8009EC6C: bne         $v0, $t7, L_8009EC78
    if (ctx->r2 != ctx->r15) {
        // 0x8009EC70: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_8009EC78;
    }
    // 0x8009EC70: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8009EC74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8009EC78:
    // 0x8009EC78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009EC7C: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8009EC80: bne         $at, $zero, L_8009EC68
    if (ctx->r1 != 0) {
        // 0x8009EC84: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8009EC68;
    }
    // 0x8009EC84: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8009EC88: addiu       $s5, $s5, 0x2D
    ctx->r21 = ADD32(ctx->r21, 0X2D);
    // 0x8009EC8C: addiu       $t9, $zero, 0x5F
    ctx->r25 = ADD32(0, 0X5F);
    // 0x8009EC90: subu        $t0, $t9, $s5
    ctx->r8 = SUB32(ctx->r25, ctx->r21);
    // 0x8009EC94: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8009EC98: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
    // 0x8009EC9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009ECA0: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
L_8009ECA4:
    // 0x8009ECA4: addiu       $t1, $s1, -0x7C
    ctx->r9 = ADD32(ctx->r17, -0X7C);
    // 0x8009ECA8: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8009ECAC: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009ECB0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009ECB4: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8009ECB8: swc1        $f4, 0x1CC($t2)
    MEM_W(0X1CC, ctx->r10) = ctx->f4.u32l;
    // 0x8009ECBC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8009ECC0: beq         $at, $zero, L_8009ECD4
    if (ctx->r1 == 0) {
        // 0x8009ECC4: swc1        $f20, 0x1D0($t3)
        MEM_W(0X1D0, ctx->r11) = ctx->f20.u32l;
            goto L_8009ECD4;
    }
    // 0x8009ECC4: swc1        $f20, 0x1D0($t3)
    MEM_W(0X1D0, ctx->r11) = ctx->f20.u32l;
    // 0x8009ECC8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8009ECCC: b           L_8009ECE0
    // 0x8009ECD0: sh          $s4, 0x1D8($t4)
    MEM_H(0X1D8, ctx->r12) = ctx->r20;
        goto L_8009ECE0;
    // 0x8009ECD0: sh          $s4, 0x1D8($t4)
    MEM_H(0X1D8, ctx->r12) = ctx->r20;
L_8009ECD4:
    // 0x8009ECD4: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8009ECD8: nop

    // 0x8009ECDC: sh          $zero, 0x1D8($t5)
    MEM_H(0X1D8, ctx->r13) = 0;
L_8009ECE0:
    // 0x8009ECE0: jal         0x8009CFA4
    // 0x8009ECE4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    menu_element_render(rdram, ctx);
        goto after_11;
    // 0x8009ECE4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_11:
    // 0x8009ECE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009ECEC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009ECF0: bne         $s0, $at, L_8009ECA4
    if (ctx->r16 != ctx->r1) {
        // 0x8009ECF4: addiu       $s1, $s1, 0x1E
        ctx->r17 = ADD32(ctx->r17, 0X1E);
            goto L_8009ECA4;
    }
    // 0x8009ECF4: addiu       $s1, $s1, 0x1E
    ctx->r17 = ADD32(ctx->r17, 0X1E);
    // 0x8009ECF8: jal         0x80068748
    // 0x8009ECFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_12;
    // 0x8009ECFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
L_8009ED00:
    // 0x8009ED00: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8009ED04: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8009ED08: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8009ED0C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8009ED10: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8009ED14: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8009ED18: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8009ED1C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8009ED20: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8009ED24: jr          $ra
    // 0x8009ED28: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8009ED28: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void trophy_race_cabinet_menu_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ED2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009ED30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009ED34: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x8009ED38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009ED3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009ED40: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009ED44: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009ED48: jal         0x800C543C
    // 0x8009ED4C: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_0;
    // 0x8009ED4C: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_0:
    // 0x8009ED50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009ED54: jal         0x800C54DC
    // 0x8009ED58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_1;
    // 0x8009ED58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8009ED5C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8009ED60: jal         0x8006A794
    // 0x8009ED64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x8009ED64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8009ED68: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009ED6C: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x8009ED70: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009ED74: lw          $a3, 0x118($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X118);
    // 0x8009ED78: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009ED7C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8009ED80: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009ED84: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009ED88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009ED8C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009ED90: jal         0x800C56C8
    // 0x8009ED94: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_3;
    // 0x8009ED94: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_3:
    // 0x8009ED98: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009ED9C: lb          $v1, 0x6A04($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A04);
    // 0x8009EDA0: nop

    // 0x8009EDA4: bgez        $v1, L_8009EDC8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009EDA8: nop
    
            goto L_8009EDC8;
    }
    // 0x8009EDA8: nop

    // 0x8009EDAC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EDB0: addiu       $v1, $v1, 0x6A78
    ctx->r3 = ADD32(ctx->r3, 0X6A78);
    // 0x8009EDB4: lb          $t0, 0x0($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X0);
    // 0x8009EDB8: nop

    // 0x8009EDBC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8009EDC0: b           L_8009EDE4
    // 0x8009EDC4: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
        goto L_8009EDE4;
    // 0x8009EDC4: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
L_8009EDC8:
    // 0x8009EDC8: blez        $v1, L_8009EDE4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009EDCC: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009EDE4;
    }
    // 0x8009EDCC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EDD0: addiu       $v1, $v1, 0x6A78
    ctx->r3 = ADD32(ctx->r3, 0X6A78);
    // 0x8009EDD4: lb          $t2, 0x0($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X0);
    // 0x8009EDD8: nop

    // 0x8009EDDC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8009EDE0: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
L_8009EDE4:
    // 0x8009EDE4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EDE8: addiu       $v1, $v1, 0x6A78
    ctx->r3 = ADD32(ctx->r3, 0X6A78);
    // 0x8009EDEC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009EDF0: nop

    // 0x8009EDF4: bgez        $v0, L_8009EE0C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009EDF8: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8009EE0C;
    }
    // 0x8009EDF8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8009EDFC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8009EE00: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009EE04: nop

    // 0x8009EE08: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_8009EE0C:
    // 0x8009EE0C: bne         $at, $zero, L_8009EE20
    if (ctx->r1 != 0) {
        // 0x8009EE10: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8009EE20;
    }
    // 0x8009EE10: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009EE14: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x8009EE18: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009EE1C: nop

L_8009EE20:
    // 0x8009EE20: jal         0x8009D65C
    // 0x8009EE24: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
    set_option_text_colour(rdram, ctx);
        goto after_4;
    // 0x8009EE24: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
    after_4:
    // 0x8009EE28: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009EE2C: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009EE30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009EE34: lw          $a3, 0x2D0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X2D0);
    // 0x8009EE38: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8009EE3C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009EE40: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009EE44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009EE48: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009EE4C: jal         0x800C56C8
    // 0x8009EE50: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    render_dialogue_text(rdram, ctx);
        goto after_5;
    // 0x8009EE50: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_5:
    // 0x8009EE54: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EE58: addiu       $v1, $v1, 0x6A78
    ctx->r3 = ADD32(ctx->r3, 0X6A78);
    // 0x8009EE5C: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8009EE60: nop

    // 0x8009EE64: xori        $t8, $a0, 0x1
    ctx->r24 = ctx->r4 ^ 0X1;
    // 0x8009EE68: jal         0x8009D65C
    // 0x8009EE6C: sltiu       $a0, $t8, 0x1
    ctx->r4 = ctx->r24 < 0X1 ? 1 : 0;
    set_option_text_colour(rdram, ctx);
        goto after_6;
    // 0x8009EE6C: sltiu       $a0, $t8, 0x1
    ctx->r4 = ctx->r24 < 0X1 ? 1 : 0;
    after_6:
    // 0x8009EE70: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009EE74: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x8009EE78: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009EE7C: lw          $a3, 0xCC($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XCC);
    // 0x8009EE80: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8009EE84: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8009EE88: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8009EE8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009EE90: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009EE94: jal         0x800C56C8
    // 0x8009EE98: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    render_dialogue_text(rdram, ctx);
        goto after_7;
    // 0x8009EE98: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_7:
    // 0x8009EE9C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8009EEA0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EEA4: andi        $t2, $a1, 0x8000
    ctx->r10 = ctx->r5 & 0X8000;
    // 0x8009EEA8: beq         $t2, $zero, L_8009EEC0
    if (ctx->r10 == 0) {
        // 0x8009EEAC: addiu       $v1, $v1, 0x6A78
        ctx->r3 = ADD32(ctx->r3, 0X6A78);
            goto L_8009EEC0;
    }
    // 0x8009EEAC: addiu       $v1, $v1, 0x6A78
    ctx->r3 = ADD32(ctx->r3, 0X6A78);
    // 0x8009EEB0: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8009EEB4: nop

    // 0x8009EEB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8009EEBC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
L_8009EEC0:
    // 0x8009EEC0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8009EEC4: andi        $t3, $a1, 0x4000
    ctx->r11 = ctx->r5 & 0X4000;
    // 0x8009EEC8: beq         $t3, $zero, L_8009EED8
    if (ctx->r11 == 0) {
        // 0x8009EECC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009EED8;
    }
    // 0x8009EECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009EED0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8009EED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009EED8:
    // 0x8009EED8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009EEDC: jr          $ra
    // 0x8009EEE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8009EEE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void dialogue_open_stub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EEE4: jr          $ra
    // 0x8009EEE8: nop

    return;
    // 0x8009EEE8: nop

;}
RECOMP_FUNC void dialogue_close_stub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EEEC: jr          $ra
    // 0x8009EEF0: nop

    return;
    // 0x8009EEF0: nop

;}
RECOMP_FUNC void dialogue_ortho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EEF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EEF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009EEFC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8009EF00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009EF04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EF08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009EF0C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8009EF10: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8009EF14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009EF18: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8009EF1C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009EF20: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8009EF24: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009EF28: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009EF2C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8009EF30: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8009EF34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF38: jal         0x8006816C
    // 0x8009EF3C: sw          $t1, 0x694C($at)
    MEM_W(0X694C, ctx->r1) = ctx->r9;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x8009EF3C: sw          $t1, 0x694C($at)
    MEM_W(0X694C, ctx->r1) = ctx->r9;
    after_0:
    // 0x8009EF40: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009EF44: lb          $t2, 0x23A8($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X23A8);
    // 0x8009EF48: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009EF4C: beq         $t2, $zero, L_8009EF6C
    if (ctx->r10 == 0) {
        // 0x8009EF50: nop
    
            goto L_8009EF6C;
    }
    // 0x8009EF50: nop

    // 0x8009EF54: lb          $t3, 0x6A82($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X6A82);
    // 0x8009EF58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009EF5C: bne         $t3, $at, L_8009EF6C
    if (ctx->r11 != ctx->r1) {
        // 0x8009EF60: nop
    
            goto L_8009EF6C;
    }
    // 0x8009EF60: nop

    // 0x8009EF64: jal         0x8009E914
    // 0x8009EF68: nop

    dialogue_tt_gamestatus(rdram, ctx);
        goto after_1;
    // 0x8009EF68: nop

    after_1:
L_8009EF6C:
    // 0x8009EF6C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009EF70: lw          $t4, 0x693C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X693C);
    // 0x8009EF74: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8009EF78: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009EF7C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8009EF80: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8009EF84: lw          $t6, 0x6944($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6944);
    // 0x8009EF88: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009EF8C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009EF90: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8009EF94: lw          $t8, 0x694C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X694C);
    // 0x8009EF98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009EF9C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8009EFA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EFA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009EFA8: jr          $ra
    // 0x8009EFAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8009EFAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void get_eeprom_settings_pointer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EFB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EFB4: jr          $ra
    // 0x8009EFB8: addiu       $v0, $v0, 0x69E8
    ctx->r2 = ADD32(ctx->r2, 0X69E8);
    return;
    // 0x8009EFB8: addiu       $v0, $v0, 0x69E8
    ctx->r2 = ADD32(ctx->r2, 0X69E8);
;}
RECOMP_FUNC void set_eeprom_settings_value(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EFBC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EFC0: addiu       $v0, $v0, 0x69E8
    ctx->r2 = ADD32(ctx->r2, 0X69E8);
    // 0x8009EFC4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8009EFC8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8009EFCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EFD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EFD4: or          $t0, $t6, $a0
    ctx->r8 = ctx->r14 | ctx->r4;
    // 0x8009EFD8: or          $t1, $t7, $a1
    ctx->r9 = ctx->r15 | ctx->r5;
    // 0x8009EFDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009EFE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009EFE4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8009EFE8: jal         0x8006EF20
    // 0x8009EFEC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    mark_write_eeprom_settings(rdram, ctx);
        goto after_0;
    // 0x8009EFEC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    after_0:
    // 0x8009EFF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EFF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009EFF8: jr          $ra
    // 0x8009EFFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009EFFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void unset_eeprom_settings_value(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F000: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009F004: addiu       $v0, $v0, 0x69E8
    ctx->r2 = ADD32(ctx->r2, 0X69E8);
    // 0x8009F008: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8009F00C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8009F010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009F014: nor         $t0, $a0, $zero
    ctx->r8 = ~(ctx->r4 | 0);
    // 0x8009F018: nor         $t1, $a1, $zero
    ctx->r9 = ~(ctx->r5 | 0);
    // 0x8009F01C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F020: and         $t2, $t6, $t0
    ctx->r10 = ctx->r14 & ctx->r8;
    // 0x8009F024: and         $t3, $t7, $t1
    ctx->r11 = ctx->r15 & ctx->r9;
    // 0x8009F028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009F02C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009F030: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8009F034: jal         0x8006EF20
    // 0x8009F038: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    mark_write_eeprom_settings(rdram, ctx);
        goto after_0;
    // 0x8009F038: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_0:
    // 0x8009F03C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009F044: jr          $ra
    // 0x8009F048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009F048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void get_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F04C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009F050: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F054: lw          $v1, 0x69EC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X69EC);
    // 0x8009F058: lw          $v0, 0x69E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X69E8);
    // 0x8009F05C: jr          $ra
    // 0x8009F060: nop

    return;
    // 0x8009F060: nop

;}
RECOMP_FUNC void get_language(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F064: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009F068: lw          $t7, 0x69EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69EC);
    // 0x8009F06C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8009F070: andi        $t9, $t7, 0xC
    ctx->r25 = ctx->r15 & 0XC;
    // 0x8009F074: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009F078: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8009F07C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x8009F080: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8009F084: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009F088: beq         $t9, $at, L_8009F0B8
    if (ctx->r25 == ctx->r1) {
        // 0x8009F08C: nop
    
            goto L_8009F0B8;
    }
    // 0x8009F08C: nop

    // 0x8009F090: bne         $t8, $zero, L_8009F0A0
    if (ctx->r24 != 0) {
        // 0x8009F094: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8009F0A0;
    }
    // 0x8009F094: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8009F098: beq         $t9, $at, L_8009F0C0
    if (ctx->r25 == ctx->r1) {
        // 0x8009F09C: nop
    
            goto L_8009F0C0;
    }
    // 0x8009F09C: nop

L_8009F0A0:
    // 0x8009F0A0: bne         $t8, $zero, L_8009F0CC
    if (ctx->r24 != 0) {
        // 0x8009F0A4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8009F0CC;
    }
    // 0x8009F0A4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8009F0A8: beq         $t9, $at, L_8009F0C8
    if (ctx->r25 == ctx->r1) {
        // 0x8009F0AC: nop
    
            goto L_8009F0C8;
    }
    // 0x8009F0AC: nop

    // 0x8009F0B0: b           L_8009F0D0
    // 0x8009F0B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8009F0D0;
    // 0x8009F0B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009F0B8:
    // 0x8009F0B8: b           L_8009F0CC
    // 0x8009F0BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8009F0CC;
    // 0x8009F0BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8009F0C0:
    // 0x8009F0C0: b           L_8009F0CC
    // 0x8009F0C4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8009F0CC;
    // 0x8009F0C4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8009F0C8:
    // 0x8009F0C8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8009F0CC:
    // 0x8009F0CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009F0D0:
    // 0x8009F0D0: jr          $ra
    // 0x8009F0D4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8009F0D4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void set_language(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F0D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009F0DC: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8009F0E0: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8009F0E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009F0E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F0EC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8009F0F0: beq         $a0, $at, L_8009F118
    if (ctx->r4 == ctx->r1) {
        // 0x8009F0F4: sw          $t6, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r14;
            goto L_8009F118;
    }
    // 0x8009F0F4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8009F0F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009F0FC: beq         $a0, $at, L_8009F12C
    if (ctx->r4 == ctx->r1) {
        // 0x8009F100: addiu       $t0, $zero, 0x0
        ctx->r8 = ADD32(0, 0X0);
            goto L_8009F12C;
    }
    // 0x8009F100: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8009F104: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009F108: beq         $a0, $at, L_8009F13C
    if (ctx->r4 == ctx->r1) {
        // 0x8009F10C: addiu       $t2, $zero, 0x0
        ctx->r10 = ADD32(0, 0X0);
            goto L_8009F13C;
    }
    // 0x8009F10C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8009F110: b           L_8009F148
    // 0x8009F114: nop

        goto L_8009F148;
    // 0x8009F114: nop

L_8009F118:
    // 0x8009F118: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8009F11C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8009F120: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8009F124: b           L_8009F148
    // 0x8009F128: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_8009F148;
    // 0x8009F128: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_8009F12C:
    // 0x8009F12C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8009F130: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8009F134: b           L_8009F148
    // 0x8009F138: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
        goto L_8009F148;
    // 0x8009F138: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_8009F13C:
    // 0x8009F13C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8009F140: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8009F144: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_8009F148:
    // 0x8009F148: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009F14C: addiu       $v0, $v0, 0x69E8
    ctx->r2 = ADD32(ctx->r2, 0X69E8);
    // 0x8009F150: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8009F154: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009F158: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8009F15C: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8009F160: addiu       $at, $zero, -0xD
    ctx->r1 = ADD32(0, -0XD);
    // 0x8009F164: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8009F168: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8009F16C: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8009F170: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009F174: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009F178: or          $t2, $t6, $t0
    ctx->r10 = ctx->r14 | ctx->r8;
    // 0x8009F17C: or          $t3, $t7, $t1
    ctx->r11 = ctx->r15 | ctx->r9;
    // 0x8009F180: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8009F184: jal         0x8007FD50
    // 0x8009F188: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    load_menu_text(rdram, ctx);
        goto after_0;
    // 0x8009F188: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_0:
    // 0x8009F18C: jal         0x8006EF20
    // 0x8009F190: nop

    mark_write_eeprom_settings(rdram, ctx);
        goto after_1;
    // 0x8009F190: nop

    after_1:
    // 0x8009F194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F198: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009F19C: jr          $ra
    // 0x8009F1A0: nop

    return;
    // 0x8009F1A0: nop

;}
RECOMP_FUNC void is_adventure_two_unlocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F1A4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009F1A8: lw          $t7, 0x69EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69EC);
    // 0x8009F1AC: jr          $ra
    // 0x8009F1B0: andi        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 & 0X1;
    return;
    // 0x8009F1B0: andi        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 & 0X1;
;}
RECOMP_FUNC void is_in_adventure_two(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F1B4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009F1B8: lw          $v0, -0x5EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5EC);
    // 0x8009F1BC: jr          $ra
    // 0x8009F1C0: nop

    return;
    // 0x8009F1C0: nop

;}
RECOMP_FUNC void is_in_two_player_adventure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F1C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009F1C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F1CC: jal         0x8009C814
    // 0x8009F1D0: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8009F1D0: nop

    after_0:
    // 0x8009F1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F1D8: beq         $v0, $zero, L_8009F1E8
    if (ctx->r2 == 0) {
        // 0x8009F1DC: nop
    
            goto L_8009F1E8;
    }
    // 0x8009F1DC: nop

    // 0x8009F1E0: b           L_8009F1F4
    // 0x8009F1E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009F1F4;
    // 0x8009F1E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009F1E8:
    // 0x8009F1E8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009F1EC: lw          $v0, -0x5C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C0);
    // 0x8009F1F0: nop

L_8009F1F4:
    // 0x8009F1F4: jr          $ra
    // 0x8009F1F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8009F1F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void is_tt_unlocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F1FC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009F200: lw          $v0, 0x318($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X318);
    // 0x8009F204: nop

    // 0x8009F208: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8009F20C: jr          $ra
    // 0x8009F210: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8009F210: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void is_drumstick_unlocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F214: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009F218: lw          $v0, 0x318($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X318);
    // 0x8009F21C: nop

    // 0x8009F220: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8009F224: jr          $ra
    // 0x8009F228: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8009F228: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8009F22C: nop

;}
RECOMP_FUNC void hud_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F230: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009F234: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009F238: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009F23C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009F240: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009F244: jal         0x80066450
    // 0x8009F248: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8009F248: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009F24C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F250: addiu       $v1, $v1, 0x72CC
    ctx->r3 = ADD32(ctx->r3, 0X72CC);
    // 0x8009F254: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8009F258: jal         0x8006676C
    // 0x8009F25C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    cam_set_layout(rdram, ctx);
        goto after_1;
    // 0x8009F25C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8009F260: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F264: jal         0x8006ECD0
    // 0x8009F268: sb          $v0, 0x72F7($at)
    MEM_B(0X72F7, ctx->r1) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_2;
    // 0x8009F268: sb          $v0, 0x72F7($at)
    MEM_B(0X72F7, ctx->r1) = ctx->r2;
    after_2:
    // 0x8009F26C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F270: jal         0x8000E1DC
    // 0x8009F274: sw          $v0, 0x7744($at)
    MEM_W(0X7744, ctx->r1) = ctx->r2;
    check_if_silver_coin_race(rdram, ctx);
        goto after_3;
    // 0x8009F274: sw          $v0, 0x7744($at)
    MEM_W(0X7744, ctx->r1) = ctx->r2;
    after_3:
    // 0x8009F278: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F27C: sb          $v0, 0x7748($at)
    MEM_B(0X7748, ctx->r1) = ctx->r2;
    // 0x8009F280: jal         0x80076EE4
    // 0x8009F284: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x8009F284: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_4:
    // 0x8009F288: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009F28C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8009F290: addiu       $s1, $s1, 0x72B0
    ctx->r17 = ADD32(ctx->r17, 0X72B0);
    // 0x8009F294: addiu       $a2, $a2, 0x72B8
    ctx->r6 = ADD32(ctx->r6, 0X72B8);
    // 0x8009F298: sll         $t6, $zero, 1
    ctx->r14 = S32(0 << 1);
    // 0x8009F29C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8009F2A0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8009F2A4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8009F2A8: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8009F2AC: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009F2B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009F2B4: beq         $s2, $t8, L_8009F2DC
    if (ctx->r18 == ctx->r24) {
        // 0x8009F2B8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8009F2DC;
    }
    // 0x8009F2B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009F2BC: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
L_8009F2C0:
    // 0x8009F2C0: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8009F2C4: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8009F2C8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8009F2CC: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8009F2D0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8009F2D4: bne         $s2, $t2, L_8009F2C0
    if (ctx->r18 != ctx->r10) {
        // 0x8009F2D8: addiu       $t9, $s0, 0x1
        ctx->r25 = ADD32(ctx->r16, 0X1);
            goto L_8009F2C0;
    }
    // 0x8009F2D8: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
L_8009F2DC:
    // 0x8009F2DC: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x8009F2E0: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x8009F2E4: jal         0x80070EDC
    // 0x8009F2E8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8009F2E8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_5:
    // 0x8009F2EC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009F2F0: addiu       $a2, $a2, 0x72B8
    ctx->r6 = ADD32(ctx->r6, 0X72B8);
    // 0x8009F2F4: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x8009F2F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009F2FC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009F300: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8009F304: addiu       $a3, $a3, 0x72B4
    ctx->r7 = ADD32(ctx->r7, 0X72B4);
    // 0x8009F308: addiu       $a0, $a0, 0x7298
    ctx->r4 = ADD32(ctx->r4, 0X7298);
    // 0x8009F30C: addu        $t5, $t3, $v0
    ctx->r13 = ADD32(ctx->r11, ctx->r2);
    // 0x8009F310: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8009F314: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8009F318: blez        $s0, L_8009F358
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8009F31C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8009F358;
    }
    // 0x8009F31C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009F320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009F324:
    // 0x8009F324: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8009F328: nop

    // 0x8009F32C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8009F330: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8009F334: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8009F338: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009F33C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8009F340: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8009F344: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8009F348: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8009F34C: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8009F350: bne         $at, $zero, L_8009F324
    if (ctx->r1 != 0) {
        // 0x8009F354: nop
    
            goto L_8009F324;
    }
    // 0x8009F354: nop

L_8009F358:
    // 0x8009F358: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8009F35C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009F360: lh          $a0, 0x2($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X2);
    // 0x8009F364: nop

    // 0x8009F368: andi        $t2, $a0, 0x3FFF
    ctx->r10 = ctx->r4 & 0X3FFF;
    // 0x8009F36C: jal         0x8007C57C
    // 0x8009F370: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_6;
    // 0x8009F370: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_6:
    // 0x8009F374: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009F378: addiu       $a3, $a3, 0x72B4
    ctx->r7 = ADD32(ctx->r7, 0X72B4);
    // 0x8009F37C: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x8009F380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009F384: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x8009F388: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009F38C: nop

    // 0x8009F390: lh          $a0, 0x2E($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X2E);
    // 0x8009F394: nop

    // 0x8009F398: andi        $t5, $a0, 0x3FFF
    ctx->r13 = ctx->r4 & 0X3FFF;
    // 0x8009F39C: jal         0x8007C57C
    // 0x8009F3A0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_7;
    // 0x8009F3A0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_7:
    // 0x8009F3A4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009F3A8: addiu       $a3, $a3, 0x72B4
    ctx->r7 = ADD32(ctx->r7, 0X72B4);
    // 0x8009F3AC: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8009F3B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009F3B4: sw          $v0, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->r2;
    // 0x8009F3B8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009F3BC: nop

    // 0x8009F3C0: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    // 0x8009F3C4: nop

    // 0x8009F3C8: andi        $t8, $a0, 0x3FFF
    ctx->r24 = ctx->r4 & 0X3FFF;
    // 0x8009F3CC: jal         0x8007C57C
    // 0x8009F3D0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_8;
    // 0x8009F3D0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_8:
    // 0x8009F3D4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009F3D8: addiu       $a3, $a3, 0x72B4
    ctx->r7 = ADD32(ctx->r7, 0X72B4);
    // 0x8009F3DC: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8009F3E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009F3E4: sw          $v0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r2;
    // 0x8009F3E8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8009F3EC: nop

    // 0x8009F3F0: lh          $a0, 0x22($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X22);
    // 0x8009F3F4: nop

    // 0x8009F3F8: andi        $t1, $a0, 0x3FFF
    ctx->r9 = ctx->r4 & 0X3FFF;
    // 0x8009F3FC: jal         0x8007C57C
    // 0x8009F400: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_9;
    // 0x8009F400: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_9:
    // 0x8009F404: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009F408: addiu       $a3, $a3, 0x72B4
    ctx->r7 = ADD32(ctx->r7, 0X72B4);
    // 0x8009F40C: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8009F410: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F414: sw          $v0, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->r2;
    // 0x8009F418: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x8009F41C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009F420: beq         $v1, $at, L_8009F430
    if (ctx->r3 == ctx->r1) {
        // 0x8009F424: ori         $a1, $zero, 0xFFFF
        ctx->r5 = 0 | 0XFFFF;
            goto L_8009F430;
    }
    // 0x8009F424: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8009F428: b           L_8009F434
    // 0x8009F42C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8009F434;
    // 0x8009F42C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009F430:
    // 0x8009F430: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8009F434:
    // 0x8009F434: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x8009F438: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8009F43C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8009F440: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8009F444: jal         0x80070EDC
    // 0x8009F448: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    mempool_alloc_safe(rdram, ctx);
        goto after_10;
    // 0x8009F448: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    after_10:
    // 0x8009F44C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F450: addiu       $v1, $v1, 0x72A0
    ctx->r3 = ADD32(ctx->r3, 0X72A0);
    // 0x8009F454: addiu       $t4, $v0, 0x760
    ctx->r12 = ADD32(ctx->r2, 0X760);
    // 0x8009F458: addiu       $t6, $t4, 0x760
    ctx->r14 = ADD32(ctx->r12, 0X760);
    // 0x8009F45C: addiu       $t8, $t6, 0x760
    ctx->r24 = ADD32(ctx->r14, 0X760);
    // 0x8009F460: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8009F464: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8009F468: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x8009F46C: jal         0x8009F574
    // 0x8009F470: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    hud_init_element(rdram, ctx);
        goto after_11;
    // 0x8009F470: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    after_11:
    // 0x8009F474: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F478: sb          $zero, 0x7324($at)
    MEM_B(0X7324, ctx->r1) = 0;
    // 0x8009F47C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F480: sw          $zero, 0x732C($at)
    MEM_W(0X732C, ctx->r1) = 0;
    // 0x8009F484: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F488: sh          $zero, 0x7308($at)
    MEM_H(0X7308, ctx->r1) = 0;
    // 0x8009F48C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8009F490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F494: sb          $v0, 0x7326($at)
    MEM_B(0X7326, ctx->r1) = ctx->r2;
    // 0x8009F498: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F49C: sb          $zero, 0x7325($at)
    MEM_B(0X7325, ctx->r1) = 0;
    // 0x8009F4A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4A4: sb          $v0, 0x7327($at)
    MEM_B(0X7327, ctx->r1) = ctx->r2;
    // 0x8009F4A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009F4B0: sb          $t9, 0x7329($at)
    MEM_B(0X7329, ctx->r1) = ctx->r25;
    // 0x8009F4B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009F4BC: sb          $t0, 0x7328($at)
    MEM_B(0X7328, ctx->r1) = ctx->r8;
    // 0x8009F4C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4C4: sb          $zero, 0x7330($at)
    MEM_B(0X7330, ctx->r1) = 0;
    // 0x8009F4C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4CC: sh          $zero, 0x733C($at)
    MEM_H(0X733C, ctx->r1) = 0;
    // 0x8009F4D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4D4: sw          $zero, 0x7334($at)
    MEM_W(0X7334, ctx->r1) = 0;
    // 0x8009F4D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4DC: sw          $zero, 0x72FC($at)
    MEM_W(0X72FC, ctx->r1) = 0;
    // 0x8009F4E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4E4: sw          $zero, 0x7304($at)
    MEM_W(0X7304, ctx->r1) = 0;
    // 0x8009F4E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F4EC: sb          $zero, 0x7293($at)
    MEM_B(0X7293, ctx->r1) = 0;
    // 0x8009F4F0: jal         0x8001E2D0
    // 0x8009F4F4: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    get_misc_asset(rdram, ctx);
        goto after_12;
    // 0x8009F4F4: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_12:
    // 0x8009F4F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F4FC: addiu       $v1, $v1, 0x7754
    ctx->r3 = ADD32(ctx->r3, 0X7754);
    // 0x8009F500: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8009F504: jal         0x8007F638
    // 0x8009F508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8007F1E8(rdram, ctx);
        goto after_13;
    // 0x8009F508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x8009F50C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009F510: jal         0x80004A60
    // 0x8009F514: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_14;
    // 0x8009F514: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_14:
    // 0x8009F518: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8009F51C: jal         0x80004A60
    // 0x8009F520: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_15;
    // 0x8009F520: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_15:
    // 0x8009F524: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009F528: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009F52C: addiu       $s1, $s1, 0x2D10
    ctx->r17 = ADD32(ctx->r17, 0X2D10);
    // 0x8009F530: addiu       $s0, $s0, 0x2CF0
    ctx->r16 = ADD32(ctx->r16, 0X2CF0);
L_8009F534:
    // 0x8009F534: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8009F538: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x8009F53C: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x8009F540: beq         $a0, $zero, L_8009F550
    if (ctx->r4 == 0) {
        // 0x8009F544: sb          $s2, 0xC($s0)
        MEM_B(0XC, ctx->r16) = ctx->r18;
            goto L_8009F550;
    }
    // 0x8009F544: sb          $s2, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r18;
    // 0x8009F548: jal         0x8000488C
    // 0x8009F54C: nop

    sndp_stop(rdram, ctx);
        goto after_16;
    // 0x8009F54C: nop

    after_16:
L_8009F550:
    // 0x8009F550: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8009F554: bne         $s0, $s1, L_8009F534
    if (ctx->r16 != ctx->r17) {
        // 0x8009F558: nop
    
            goto L_8009F534;
    }
    // 0x8009F558: nop

    // 0x8009F55C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009F560: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009F564: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009F568: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009F56C: jr          $ra
    // 0x8009F570: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009F570: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void hud_init_element(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F574: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8009F578: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8009F57C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8009F580: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8009F584: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8009F588: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8009F58C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8009F590: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8009F594: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8009F598: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8009F59C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8009F5A0: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8009F5A4: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8009F5A8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8009F5AC: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8009F5B0: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8009F5B4: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8009F5B8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8009F5BC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8009F5C0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8009F5C4: jal         0x8006BFD8
    // 0x8009F5C8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    level_type(rdram, ctx);
        goto after_0;
    // 0x8009F5C8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8009F5CC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009F5D0: beq         $t4, $v0, L_8009F5E4
    if (ctx->r12 == ctx->r2) {
        // 0x8009F5D4: lui         $s0, 0x8000
        ctx->r16 = S32(0X8000 << 16);
            goto L_8009F5E4;
    }
    // 0x8009F5D4: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8009F5D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009F5DC: bne         $v0, $at, L_8009F5FC
    if (ctx->r2 != ctx->r1) {
        // 0x8009F5E0: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8009F5FC;
    }
    // 0x8009F5E0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
L_8009F5E4:
    // 0x8009F5E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F5E8: sw          $zero, 0x72E4($at)
    MEM_W(0X72E4, ctx->r1) = 0;
    // 0x8009F5EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F5F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009F5F4: b           L_8009F64C
    // 0x8009F5F8: sb          $t6, 0x72F4($at)
    MEM_B(0X72F4, ctx->r1) = ctx->r14;
        goto L_8009F64C;
    // 0x8009F5F8: sb          $t6, 0x72F4($at)
    MEM_B(0X72F4, ctx->r1) = ctx->r14;
L_8009F5FC:
    // 0x8009F5FC: lw          $t7, 0x72CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72CC);
    // 0x8009F600: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x8009F604: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8009F608: beq         $at, $zero, L_8009F62C
    if (ctx->r1 == 0) {
        // 0x8009F60C: addiu       $t9, $zero, 0xC8
        ctx->r25 = ADD32(0, 0XC8);
            goto L_8009F62C;
    }
    // 0x8009F60C: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x8009F610: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F614: sw          $t8, 0x72E4($at)
    MEM_W(0X72E4, ctx->r1) = ctx->r24;
    // 0x8009F618: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8009F61C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009F620: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F624: b           L_8009F644
    // 0x8009F628: swc1        $f4, 0x72F0($at)
    MEM_W(0X72F0, ctx->r1) = ctx->f4.u32l;
        goto L_8009F644;
    // 0x8009F628: swc1        $f4, 0x72F0($at)
    MEM_W(0X72F0, ctx->r1) = ctx->f4.u32l;
L_8009F62C:
    // 0x8009F62C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F630: sw          $t9, 0x72E4($at)
    MEM_W(0X72E4, ctx->r1) = ctx->r25;
    // 0x8009F634: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8009F638: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009F63C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F640: swc1        $f6, 0x72F0($at)
    MEM_W(0X72F0, ctx->r1) = ctx->f6.u32l;
L_8009F644:
    // 0x8009F644: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F648: sb          $zero, 0x72F4($at)
    MEM_B(0X72F4, ctx->r1) = 0;
L_8009F64C:
    // 0x8009F64C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F650: sh          $zero, 0x72EC($at)
    MEM_H(0X72EC, ctx->r1) = 0;
    // 0x8009F654: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F658: sb          $zero, 0x7294($at)
    MEM_B(0X7294, ctx->r1) = 0;
    // 0x8009F65C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F660: sb          $zero, 0x72F6($at)
    MEM_B(0X72F6, ctx->r1) = 0;
    // 0x8009F664: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F668: sb          $zero, 0x72F8($at)
    MEM_B(0X72F8, ctx->r1) = 0;
    // 0x8009F66C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F670: sb          $zero, 0x72F5($at)
    MEM_B(0X72F5, ctx->r1) = 0;
    // 0x8009F674: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F678: addiu       $s0, $s0, 0x300
    ctx->r16 = ADD32(ctx->r16, 0X300);
    // 0x8009F67C: sb          $zero, 0x7290($at)
    MEM_B(0X7290, ctx->r1) = 0;
    // 0x8009F680: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8009F684: addiu       $t9, $zero, -0x64
    ctx->r25 = ADD32(0, -0X64);
    // 0x8009F688: bne         $t6, $zero, L_8009F6A0
    if (ctx->r14 != 0) {
        // 0x8009F68C: addiu       $a0, $zero, 0x78
        ctx->r4 = ADD32(0, 0X78);
            goto L_8009F6A0;
    }
    // 0x8009F68C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x8009F690: addiu       $t7, $zero, 0x3D
    ctx->r15 = ADD32(0, 0X3D);
    // 0x8009F694: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F698: b           L_8009F6AC
    // 0x8009F69C: sb          $t7, 0x774B($at)
    MEM_B(0X774B, ctx->r1) = ctx->r15;
        goto L_8009F6AC;
    // 0x8009F69C: sb          $t7, 0x774B($at)
    MEM_B(0X774B, ctx->r1) = ctx->r15;
L_8009F6A0:
    // 0x8009F6A0: addiu       $t8, $zero, 0x33
    ctx->r24 = ADD32(0, 0X33);
    // 0x8009F6A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6A8: sb          $t8, 0x774B($at)
    MEM_B(0X774B, ctx->r1) = ctx->r24;
L_8009F6AC:
    // 0x8009F6AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6B0: sb          $zero, 0x7291($at)
    MEM_B(0X7291, ctx->r1) = 0;
    // 0x8009F6B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6B8: sb          $zero, 0x7292($at)
    MEM_B(0X7292, ctx->r1) = 0;
    // 0x8009F6BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6C0: sb          $zero, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = 0;
    // 0x8009F6C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6C8: sb          $zero, 0x7749($at)
    MEM_B(0X7749, ctx->r1) = 0;
    // 0x8009F6CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6D0: sw          $t9, 0x730C($at)
    MEM_W(0X730C, ctx->r1) = ctx->r25;
    // 0x8009F6D4: jal         0x8006FB8C
    // 0x8009F6D8: addiu       $a1, $zero, 0x168
    ctx->r5 = ADD32(0, 0X168);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x8009F6D8: addiu       $a1, $zero, 0x168
    ctx->r5 = ADD32(0, 0X168);
    after_1:
    // 0x8009F6DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6E0: jal         0x8000E158
    // 0x8009F6E4: sw          $v0, 0x7310($at)
    MEM_W(0X7310, ctx->r1) = ctx->r2;
    is_race_started_by_player_two(rdram, ctx);
        goto after_2;
    // 0x8009F6E4: sw          $v0, 0x7310($at)
    MEM_W(0X7310, ctx->r1) = ctx->r2;
    after_2:
    // 0x8009F6E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6EC: sb          $v0, 0x774A($at)
    MEM_B(0X774A, ctx->r1) = ctx->r2;
    // 0x8009F6F0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8009F6F4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F6F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009F6FC: addiu       $a0, $a0, 0x7750
    ctx->r4 = ADD32(ctx->r4, 0X7750);
    // 0x8009F700: addiu       $v1, $v1, 0x774C
    ctx->r3 = ADD32(ctx->r3, 0X774C);
    // 0x8009F704: addiu       $t6, $zero, 0x37
    ctx->r14 = ADD32(0, 0X37);
    // 0x8009F708: addiu       $t7, $zero, 0xB3
    ctx->r15 = ADD32(0, 0XB3);
    // 0x8009F70C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009F710: bne         $t8, $zero, L_8009F72C
    if (ctx->r24 != 0) {
        // 0x8009F714: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8009F72C;
    }
    // 0x8009F714: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009F718: addiu       $t6, $t7, 0x1E
    ctx->r14 = ADD32(ctx->r15, 0X1E);
    // 0x8009F71C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8009F720: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009F724: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x8009F728: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8009F72C:
    // 0x8009F72C: jal         0x8001B674
    // 0x8009F730: nop

    timetrial_ghost_staff(rdram, ctx);
        goto after_3;
    // 0x8009F730: nop

    after_3:
    // 0x8009F734: bne         $v0, $zero, L_8009F748
    if (ctx->r2 != 0) {
        // 0x8009F738: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8009F748;
    }
    // 0x8009F738: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009F73C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F740: b           L_8009F754
    // 0x8009F744: sb          $zero, 0x7331($at)
    MEM_B(0X7331, ctx->r1) = 0;
        goto L_8009F754;
    // 0x8009F744: sb          $zero, 0x7331($at)
    MEM_B(0X7331, ctx->r1) = 0;
L_8009F748:
    // 0x8009F748: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009F74C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F750: sb          $t9, 0x7331($at)
    MEM_B(0X7331, ctx->r1) = ctx->r25;
L_8009F754:
    // 0x8009F754: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009F758: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x8009F75C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009F760: beq         $v0, $at, L_8009F770
    if (ctx->r2 == ctx->r1) {
        // 0x8009F764: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_8009F770;
    }
    // 0x8009F764: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8009F768: b           L_8009F774
    // 0x8009F76C: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
        goto L_8009F774;
    // 0x8009F76C: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
L_8009F770:
    // 0x8009F770: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
L_8009F774:
    // 0x8009F774: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8009F778: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009F77C: blez        $t7, L_800A04E4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8009F780: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800A04E4;
    }
    // 0x8009F780: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009F784: lui         $at, 0xC268
    ctx->r1 = S32(0XC268 << 16);
    // 0x8009F788: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8009F78C: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x8009F790: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8009F794: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x8009F798: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8009F79C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009F7A0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8009F7A4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8009F7A8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8009F7AC: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x8009F7B0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8009F7B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009F7B8: addiu       $t8, $t8, 0x72A0
    ctx->r24 = ADD32(ctx->r24, 0X72A0);
    // 0x8009F7BC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009F7C0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009F7C4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009F7C8: lwc1        $f15, -0x73D8($at)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r1, -0X73D8);
    // 0x8009F7CC: lwc1        $f14, -0x73D4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8009F7D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009F7D4: addiu       $a1, $a1, 0x729C
    ctx->r5 = ADD32(ctx->r5, 0X729C);
    // 0x8009F7D8: addiu       $t1, $t1, 0x72B0
    ctx->r9 = ADD32(ctx->r9, 0X72B0);
    // 0x8009F7DC: addiu       $s0, $s0, 0x2B44
    ctx->r16 = ADD32(ctx->r16, 0X2B44);
    // 0x8009F7E0: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x8009F7E4: addiu       $fp, $zero, 0x36
    ctx->r30 = ADD32(0, 0X36);
    // 0x8009F7E8: addiu       $s7, $zero, 0x1C
    ctx->r23 = ADD32(0, 0X1C);
    // 0x8009F7EC: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x8009F7F0: addiu       $s5, $zero, 0xB
    ctx->r21 = ADD32(0, 0XB);
    // 0x8009F7F4: addiu       $s4, $zero, 0xF
    ctx->r20 = ADD32(0, 0XF);
    // 0x8009F7F8: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8009F7FC: addiu       $s2, $zero, 0x760
    ctx->r18 = ADD32(0, 0X760);
    // 0x8009F800: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x8009F804: addiu       $ra, $zero, 0x12
    ctx->r31 = ADD32(0, 0X12);
    // 0x8009F808: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8009F80C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8009F810: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8009F814: ori         $t0, $zero, 0xC000
    ctx->r8 = 0 | 0XC000;
L_8009F818:
    // 0x8009F818: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8009F81C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009F820: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8009F824: addiu       $v0, $v0, 0x23E4
    ctx->r2 = ADD32(ctx->r2, 0X23E4);
    // 0x8009F828: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009F82C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_8009F830:
    // 0x8009F830: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F834: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009F838: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8009F83C: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x8009F840: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F844: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009F848: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8009F84C: swc1        $f10, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f10.u32l;
    // 0x8009F850: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F854: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009F858: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8009F85C: swc1        $f4, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f4.u32l;
    // 0x8009F860: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F864: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009F868: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8009F86C: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x8009F870: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F874: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8009F878: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F87C: sh          $t7, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r15;
    // 0x8009F880: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F884: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8009F888: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F88C: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    // 0x8009F890: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F894: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8009F898: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F89C: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x8009F8A0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8A4: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8009F8A8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F8AC: sh          $t7, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r15;
    // 0x8009F8B0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8B4: lh          $t6, 0x18($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X18);
    // 0x8009F8B8: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F8BC: sh          $t6, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r14;
    // 0x8009F8C0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8C4: lb          $t9, 0x1A($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1A);
    // 0x8009F8C8: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F8CC: sb          $t9, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r25;
    // 0x8009F8D0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8D4: lb          $t7, 0x1B($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1B);
    // 0x8009F8D8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F8DC: sb          $t7, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = ctx->r15;
    // 0x8009F8E0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8E4: lb          $t6, 0x1C($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C);
    // 0x8009F8E8: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F8EC: sb          $t6, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = ctx->r14;
    // 0x8009F8F0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8F4: lb          $t9, 0x1D($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1D);
    // 0x8009F8F8: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8009F8FC: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F900: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8009F904: bne         $v0, $s0, L_8009F830
    if (ctx->r2 != ctx->r16) {
        // 0x8009F908: sb          $t9, 0x1D($t6)
        MEM_B(0X1D, ctx->r14) = ctx->r25;
            goto L_8009F830;
    }
    // 0x8009F908: sb          $t9, 0x1D($t6)
    MEM_B(0X1D, ctx->r14) = ctx->r25;
    // 0x8009F90C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F910: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8009F914: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F918: sb          $t7, 0x5DC($t8)
    MEM_B(0X5DC, ctx->r24) = ctx->r15;
    // 0x8009F91C: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x8009F920: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8009F924: bne         $t4, $v1, L_8009FB38
    if (ctx->r12 != ctx->r3) {
        // 0x8009F928: nop
    
            goto L_8009FB38;
    }
    // 0x8009F928: nop

    // 0x8009F92C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009F930: addiu       $v0, $v1, 0x2B44
    ctx->r2 = ADD32(ctx->r3, 0X2B44);
    // 0x8009F934: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8009F938: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009F93C: beq         $t2, $t9, L_8009FA3C
    if (ctx->r10 == ctx->r25) {
        // 0x8009F940: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_8009FA3C;
    }
    // 0x8009F940: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009F944: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009F948: addiu       $t6, $t6, 0x2B44
    ctx->r14 = ADD32(ctx->r14, 0X2B44);
    // 0x8009F94C: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    // 0x8009F950: nop

L_8009F954:
    // 0x8009F954: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8009F958: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F95C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8009F960: sll         $t9, $a0, 5
    ctx->r25 = S32(ctx->r4 << 5);
    // 0x8009F964: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009F968: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8009F96C: swc1        $f10, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f10.u32l;
    // 0x8009F970: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8009F974: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F978: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8009F97C: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8009F980: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    // 0x8009F984: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8009F988: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8009F98C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8009F990: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x8009F994: nop

    // 0x8009F998: andi        $t6, $t8, 0xC000
    ctx->r14 = ctx->r24 & 0XC000;
    // 0x8009F99C: bne         $t0, $t6, L_8009F9E8
    if (ctx->r8 != ctx->r14) {
        // 0x8009F9A0: nop
    
            goto L_8009F9E8;
    }
    // 0x8009F9A0: nop

    // 0x8009F9A4: bne         $a3, $zero, L_8009F9C8
    if (ctx->r7 != 0) {
        // 0x8009F9A8: nop
    
            goto L_8009F9C8;
    }
    // 0x8009F9A8: nop

    // 0x8009F9AC: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8009F9B0: nop

    // 0x8009F9B4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8009F9B8: nop

    // 0x8009F9BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009F9C0: b           L_8009FA2C
    // 0x8009F9C4: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
        goto L_8009FA2C;
    // 0x8009F9C4: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
L_8009F9C8:
    // 0x8009F9C8: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x8009F9CC: nop

    // 0x8009F9D0: addiu       $t8, $t9, 0x6C
    ctx->r24 = ADD32(ctx->r25, 0X6C);
    // 0x8009F9D4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8009F9D8: nop

    // 0x8009F9DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009F9E0: b           L_8009FA2C
    // 0x8009F9E4: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
        goto L_8009FA2C;
    // 0x8009F9E4: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
L_8009F9E8:
    // 0x8009F9E8: bne         $a3, $zero, L_8009FA10
    if (ctx->r7 != 0) {
        // 0x8009F9EC: nop
    
            goto L_8009FA10;
    }
    // 0x8009F9EC: nop

    // 0x8009F9F0: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8009F9F4: nop

    // 0x8009F9F8: addiu       $t7, $t6, 0x3C
    ctx->r15 = ADD32(ctx->r14, 0X3C);
    // 0x8009F9FC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8009FA00: nop

    // 0x8009FA04: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009FA08: b           L_8009FA2C
    // 0x8009FA0C: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
        goto L_8009FA2C;
    // 0x8009FA0C: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
L_8009FA10:
    // 0x8009FA10: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x8009FA14: nop

    // 0x8009FA18: addiu       $t8, $t9, -0x30
    ctx->r24 = ADD32(ctx->r25, -0X30);
    // 0x8009FA1C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8009FA20: nop

    // 0x8009FA24: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009FA28: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
L_8009FA2C:
    // 0x8009FA2C: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x8009FA30: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8009FA34: bne         $t2, $a0, L_8009F954
    if (ctx->r10 != ctx->r4) {
        // 0x8009FA38: nop
    
            goto L_8009F954;
    }
    // 0x8009FA38: nop

L_8009FA3C:
    // 0x8009FA3C: lwc1        $f4, -0x73C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X73C8);
    // 0x8009FA40: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA44: lui         $at, 0x4377
    ctx->r1 = S32(0X4377 << 16);
    // 0x8009FA48: swc1        $f4, 0x64C($t6)
    MEM_W(0X64C, ctx->r14) = ctx->f4.u32l;
    // 0x8009FA4C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009FA54: swc1        $f0, 0x650($t7)
    MEM_W(0X650, ctx->r15) = ctx->f0.u32l;
    // 0x8009FA58: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA5C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8009FA60: swc1        $f6, 0x40C($t9)
    MEM_W(0X40C, ctx->r25) = ctx->f6.u32l;
    // 0x8009FA64: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009FA6C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009FA70: swc1        $f8, 0x410($t8)
    MEM_W(0X410, ctx->r24) = ctx->f8.u32l;
    // 0x8009FA74: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA78: lwc1        $f10, -0x73C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73C4);
    // 0x8009FA7C: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x8009FA80: swc1        $f10, 0x66C($t6)
    MEM_W(0X66C, ctx->r14) = ctx->f10.u32l;
    // 0x8009FA84: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009FA8C: lui         $at, 0x42CE
    ctx->r1 = S32(0X42CE << 16);
    // 0x8009FA90: swc1        $f4, 0x670($t7)
    MEM_W(0X670, ctx->r15) = ctx->f4.u32l;
    // 0x8009FA94: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009FA9C: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x8009FAA0: swc1        $f6, 0x68C($t9)
    MEM_W(0X68C, ctx->r25) = ctx->f6.u32l;
    // 0x8009FAA4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009FAAC: lui         $at, 0x4384
    ctx->r1 = S32(0X4384 << 16);
    // 0x8009FAB0: swc1        $f8, 0x690($t8)
    MEM_W(0X690, ctx->r24) = ctx->f8.u32l;
    // 0x8009FAB4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009FABC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8009FAC0: swc1        $f10, 0x6AC($t6)
    MEM_W(0X6AC, ctx->r14) = ctx->f10.u32l;
    // 0x8009FAC4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009FACC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009FAD0: swc1        $f4, 0x6B0($t7)
    MEM_W(0X6B0, ctx->r15) = ctx->f4.u32l;
    // 0x8009FAD4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAD8: lwc1        $f6, -0x73C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73C0);
    // 0x8009FADC: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x8009FAE0: swc1        $f6, 0x6CC($t9)
    MEM_W(0X6CC, ctx->r25) = ctx->f6.u32l;
    // 0x8009FAE4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009FAEC: lui         $at, 0x4389
    ctx->r1 = S32(0X4389 << 16);
    // 0x8009FAF0: swc1        $f8, 0x6D0($t8)
    MEM_W(0X6D0, ctx->r24) = ctx->f8.u32l;
    // 0x8009FAF4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009FAFC: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x8009FB00: swc1        $f10, 0x6EC($t6)
    MEM_W(0X6EC, ctx->r14) = ctx->f10.u32l;
    // 0x8009FB04: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009FB0C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009FB10: swc1        $f4, 0x6F0($t7)
    MEM_W(0X6F0, ctx->r15) = ctx->f4.u32l;
    // 0x8009FB14: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB18: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009FB1C: swc1        $f0, 0x650($t9)
    MEM_W(0X650, ctx->r25) = ctx->f0.u32l;
    // 0x8009FB20: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB24: nop

    // 0x8009FB28: sb          $t8, 0x5DC($t6)
    MEM_B(0X5DC, ctx->r14) = ctx->r24;
    // 0x8009FB2C: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x8009FB30: b           L_8009FCFC
    // 0x8009FB34: nop

        goto L_8009FCFC;
    // 0x8009FB34: nop

L_8009FB38:
    // 0x8009FB38: beq         $t3, $v1, L_8009FB44
    if (ctx->r11 == ctx->r3) {
        // 0x8009FB3C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8009FB44;
    }
    // 0x8009FB3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009FB40: bne         $v1, $at, L_8009FCFC
    if (ctx->r3 != ctx->r1) {
        // 0x8009FB44: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8009FCFC;
    }
L_8009FB44:
    // 0x8009FB44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009FB48: addiu       $v0, $a0, 0x2C04
    ctx->r2 = ADD32(ctx->r4, 0X2C04);
    // 0x8009FB4C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8009FB50: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009FB54: beq         $t2, $t7, L_8009FCFC
    if (ctx->r10 == ctx->r15) {
        // 0x8009FB58: addiu       $t9, $t9, 0x2C04
        ctx->r25 = ADD32(ctx->r25, 0X2C04);
            goto L_8009FCFC;
    }
    // 0x8009FB58: addiu       $t9, $t9, 0x2C04
    ctx->r25 = ADD32(ctx->r25, 0X2C04);
    // 0x8009FB5C: lh          $v1, 0x0($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X0);
    // 0x8009FB60: nop

L_8009FB64:
    // 0x8009FB64: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB68: sll         $t6, $v1, 5
    ctx->r14 = S32(ctx->r3 << 5);
    // 0x8009FB6C: addu        $a0, $t8, $t6
    ctx->r4 = ADD32(ctx->r24, ctx->r14);
    // 0x8009FB70: lh          $t9, 0x6($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X6);
    // 0x8009FB74: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8009FB78: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x8009FB7C: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8009FB80: lh          $t9, 0x0($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X0);
    // 0x8009FB84: nop

    // 0x8009FB88: andi        $t7, $t9, 0xC000
    ctx->r15 = ctx->r25 & 0XC000;
    // 0x8009FB8C: bne         $t0, $t7, L_8009FC38
    if (ctx->r8 != ctx->r15) {
        // 0x8009FB90: nop
    
            goto L_8009FC38;
    }
    // 0x8009FB90: nop

    // 0x8009FB94: beq         $a3, $zero, L_8009FBA4
    if (ctx->r7 == 0) {
        // 0x8009FB98: nop
    
            goto L_8009FBA4;
    }
    // 0x8009FB98: nop

    // 0x8009FB9C: bne         $a3, $t3, L_8009FBC0
    if (ctx->r7 != ctx->r11) {
        // 0x8009FBA0: nop
    
            goto L_8009FBC0;
    }
    // 0x8009FBA0: nop

L_8009FBA4:
    // 0x8009FBA4: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8009FBA8: nop

    // 0x8009FBAC: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8009FBB0: nop

    // 0x8009FBB4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009FBB8: b           L_8009FBDC
    // 0x8009FBBC: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
        goto L_8009FBDC;
    // 0x8009FBBC: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
L_8009FBC0:
    // 0x8009FBC0: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x8009FBC4: nop

    // 0x8009FBC8: addiu       $t9, $t6, 0xA0
    ctx->r25 = ADD32(ctx->r14, 0XA0);
    // 0x8009FBCC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8009FBD0: nop

    // 0x8009FBD4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009FBD8: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
L_8009FBDC:
    // 0x8009FBDC: beq         $a3, $zero, L_8009FBEC
    if (ctx->r7 == 0) {
        // 0x8009FBE0: nop
    
            goto L_8009FBEC;
    }
    // 0x8009FBE0: nop

    // 0x8009FBE4: bne         $a3, $t4, L_8009FC10
    if (ctx->r7 != ctx->r12) {
        // 0x8009FBE8: nop
    
            goto L_8009FC10;
    }
    // 0x8009FBE8: nop

L_8009FBEC:
    // 0x8009FBEC: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8009FBF0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8009FBF4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8009FBF8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FBFC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009FC00: sll         $t9, $t6, 5
    ctx->r25 = S32(ctx->r14 << 5);
    // 0x8009FC04: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x8009FC08: b           L_8009FCE0
    // 0x8009FC0C: swc1        $f8, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f8.u32l;
        goto L_8009FCE0;
    // 0x8009FC0C: swc1        $f8, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f8.u32l;
L_8009FC10:
    // 0x8009FC10: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8009FC14: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8009FC18: addiu       $t8, $t6, 0x6C
    ctx->r24 = ADD32(ctx->r14, 0X6C);
    // 0x8009FC1C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8009FC20: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FC24: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009FC28: sll         $t6, $t7, 5
    ctx->r14 = S32(ctx->r15 << 5);
    // 0x8009FC2C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8009FC30: b           L_8009FCE0
    // 0x8009FC34: swc1        $f4, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f4.u32l;
        goto L_8009FCE0;
    // 0x8009FC34: swc1        $f4, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f4.u32l;
L_8009FC38:
    // 0x8009FC38: beq         $a3, $zero, L_8009FC48
    if (ctx->r7 == 0) {
        // 0x8009FC3C: nop
    
            goto L_8009FC48;
    }
    // 0x8009FC3C: nop

    // 0x8009FC40: bne         $a3, $t3, L_8009FC68
    if (ctx->r7 != ctx->r11) {
        // 0x8009FC44: nop
    
            goto L_8009FC68;
    }
    // 0x8009FC44: nop

L_8009FC48:
    // 0x8009FC48: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8009FC4C: nop

    // 0x8009FC50: addiu       $t9, $t7, -0x50
    ctx->r25 = ADD32(ctx->r15, -0X50);
    // 0x8009FC54: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8009FC58: nop

    // 0x8009FC5C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009FC60: b           L_8009FC84
    // 0x8009FC64: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
        goto L_8009FC84;
    // 0x8009FC64: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
L_8009FC68:
    // 0x8009FC68: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x8009FC6C: nop

    // 0x8009FC70: addiu       $t8, $t6, 0x50
    ctx->r24 = ADD32(ctx->r14, 0X50);
    // 0x8009FC74: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8009FC78: nop

    // 0x8009FC7C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009FC80: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
L_8009FC84:
    // 0x8009FC84: beq         $a3, $zero, L_8009FC94
    if (ctx->r7 == 0) {
        // 0x8009FC88: nop
    
            goto L_8009FC94;
    }
    // 0x8009FC88: nop

    // 0x8009FC8C: bne         $a3, $t4, L_8009FCBC
    if (ctx->r7 != ctx->r12) {
        // 0x8009FC90: nop
    
            goto L_8009FCBC;
    }
    // 0x8009FC90: nop

L_8009FC94:
    // 0x8009FC94: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8009FC98: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8009FC9C: addiu       $t9, $t7, 0x3C
    ctx->r25 = ADD32(ctx->r15, 0X3C);
    // 0x8009FCA0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8009FCA4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FCA8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009FCAC: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x8009FCB0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8009FCB4: b           L_8009FCE0
    // 0x8009FCB8: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
        goto L_8009FCE0;
    // 0x8009FCB8: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
L_8009FCBC:
    // 0x8009FCBC: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8009FCC0: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8009FCC4: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x8009FCC8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8009FCCC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FCD0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009FCD4: sll         $t8, $t9, 5
    ctx->r24 = S32(ctx->r25 << 5);
    // 0x8009FCD8: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8009FCDC: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
L_8009FCE0:
    // 0x8009FCE0: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x8009FCE4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8009FCE8: bne         $t2, $v1, L_8009FB64
    if (ctx->r10 != ctx->r3) {
        // 0x8009FCEC: nop
    
            goto L_8009FB64;
    }
    // 0x8009FCEC: nop

    // 0x8009FCF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009FCF4: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x8009FCF8: nop

L_8009FCFC:
    // 0x8009FCFC: beq         $v1, $zero, L_8009FE18
    if (ctx->r3 == 0) {
        // 0x8009FD00: nop
    
            goto L_8009FE18;
    }
    // 0x8009FD00: nop

    // 0x8009FD04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8009FD08:
    // 0x8009FD08: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FD0C: nop

    // 0x8009FD10: addu        $a0, $t9, $v1
    ctx->r4 = ADD32(ctx->r25, ctx->r3);
    // 0x8009FD14: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x8009FD18: nop

    // 0x8009FD1C: bne         $t5, $v0, L_8009FD2C
    if (ctx->r13 != ctx->r2) {
        // 0x8009FD20: nop
    
            goto L_8009FD2C;
    }
    // 0x8009FD20: nop

    // 0x8009FD24: b           L_8009FE00
    // 0x8009FD28: sh          $s1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r17;
        goto L_8009FE00;
    // 0x8009FD28: sh          $s1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r17;
L_8009FD2C:
    // 0x8009FD2C: bne         $s3, $v0, L_8009FD3C
    if (ctx->r19 != ctx->r2) {
        // 0x8009FD30: nop
    
            goto L_8009FD3C;
    }
    // 0x8009FD30: nop

    // 0x8009FD34: b           L_8009FE00
    // 0x8009FD38: sh          $s4, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r20;
        goto L_8009FE00;
    // 0x8009FD38: sh          $s4, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r20;
L_8009FD3C:
    // 0x8009FD3C: bne         $s5, $v0, L_8009FD4C
    if (ctx->r21 != ctx->r2) {
        // 0x8009FD40: nop
    
            goto L_8009FD4C;
    }
    // 0x8009FD40: nop

    // 0x8009FD44: b           L_8009FE00
    // 0x8009FD48: sh          $s6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r22;
        goto L_8009FE00;
    // 0x8009FD48: sh          $s6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r22;
L_8009FD4C:
    // 0x8009FD4C: bne         $ra, $v0, L_8009FD5C
    if (ctx->r31 != ctx->r2) {
        // 0x8009FD50: nop
    
            goto L_8009FD5C;
    }
    // 0x8009FD50: nop

    // 0x8009FD54: b           L_8009FE00
    // 0x8009FD58: sh          $s7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r23;
        goto L_8009FE00;
    // 0x8009FD58: sh          $s7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r23;
L_8009FD5C:
    // 0x8009FD5C: bne         $fp, $v0, L_8009FD80
    if (ctx->r30 != ctx->r2) {
        // 0x8009FD60: nop
    
            goto L_8009FD80;
    }
    // 0x8009FD60: nop

    // 0x8009FD64: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8009FD68: nop

    // 0x8009FD6C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8009FD70: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x8009FD74: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8009FD78: b           L_8009FE00
    // 0x8009FD7C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
        goto L_8009FE00;
    // 0x8009FD7C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
L_8009FD80:
    // 0x8009FD80: beq         $v1, $zero, L_8009FE00
    if (ctx->r3 == 0) {
        // 0x8009FD84: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_8009FE00;
    }
    // 0x8009FD84: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8009FD88: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FD8C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8009FE00;
    }
    // 0x8009FD8C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8009FD90: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FD94: addiu       $at, $zero, 0x4A0
        ctx->r1 = ADD32(0, 0X4A0);
            goto L_8009FE00;
    }
    // 0x8009FD94: addiu       $at, $zero, 0x4A0
    ctx->r1 = ADD32(0, 0X4A0);
    // 0x8009FD98: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FD9C: addiu       $at, $zero, 0x5E0
        ctx->r1 = ADD32(0, 0X5E0);
            goto L_8009FE00;
    }
    // 0x8009FD9C: addiu       $at, $zero, 0x5E0
    ctx->r1 = ADD32(0, 0X5E0);
    // 0x8009FDA0: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FDA4: addiu       $at, $zero, 0x600
        ctx->r1 = ADD32(0, 0X600);
            goto L_8009FE00;
    }
    // 0x8009FDA4: addiu       $at, $zero, 0x600
    ctx->r1 = ADD32(0, 0X600);
    // 0x8009FDA8: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FDAC: addiu       $at, $zero, 0x60
        ctx->r1 = ADD32(0, 0X60);
            goto L_8009FE00;
    }
    // 0x8009FDAC: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x8009FDB0: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FDB4: addiu       $at, $zero, 0x640
        ctx->r1 = ADD32(0, 0X640);
            goto L_8009FE00;
    }
    // 0x8009FDB4: addiu       $at, $zero, 0x640
    ctx->r1 = ADD32(0, 0X640);
    // 0x8009FDB8: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FDBC: addiu       $at, $zero, 0x660
        ctx->r1 = ADD32(0, 0X660);
            goto L_8009FE00;
    }
    // 0x8009FDBC: addiu       $at, $zero, 0x660
    ctx->r1 = ADD32(0, 0X660);
    // 0x8009FDC0: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FDC4: slti        $at, $v1, 0x680
        ctx->r1 = SIGNED(ctx->r3) < 0X680 ? 1 : 0;
            goto L_8009FE00;
    }
    // 0x8009FDC4: slti        $at, $v1, 0x680
    ctx->r1 = SIGNED(ctx->r3) < 0X680 ? 1 : 0;
    // 0x8009FDC8: bne         $at, $zero, L_8009FDE8
    if (ctx->r1 != 0) {
        // 0x8009FDCC: slti        $at, $v1, 0x700
        ctx->r1 = SIGNED(ctx->r3) < 0X700 ? 1 : 0;
            goto L_8009FDE8;
    }
    // 0x8009FDCC: slti        $at, $v1, 0x700
    ctx->r1 = SIGNED(ctx->r3) < 0X700 ? 1 : 0;
    // 0x8009FDD0: beq         $at, $zero, L_8009FDE8
    if (ctx->r1 == 0) {
        // 0x8009FDD4: addiu       $at, $zero, 0x380
        ctx->r1 = ADD32(0, 0X380);
            goto L_8009FDE8;
    }
    // 0x8009FDD4: addiu       $at, $zero, 0x380
    ctx->r1 = ADD32(0, 0X380);
    // 0x8009FDD8: beq         $v1, $at, L_8009FDE8
    if (ctx->r3 == ctx->r1) {
        // 0x8009FDDC: addiu       $at, $zero, 0x120
        ctx->r1 = ADD32(0, 0X120);
            goto L_8009FDE8;
    }
    // 0x8009FDDC: addiu       $at, $zero, 0x120
    ctx->r1 = ADD32(0, 0X120);
    // 0x8009FDE0: bne         $v1, $at, L_8009FE00
    if (ctx->r3 != ctx->r1) {
        // 0x8009FDE4: nop
    
            goto L_8009FE00;
    }
    // 0x8009FDE4: nop

L_8009FDE8:
    // 0x8009FDE8: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8009FDEC: nop

    // 0x8009FDF0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8009FDF4: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8009FDF8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8009FDFC: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
L_8009FE00:
    // 0x8009FE00: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8009FE04: bne         $v1, $s2, L_8009FD08
    if (ctx->r3 != ctx->r18) {
        // 0x8009FE08: nop
    
            goto L_8009FD08;
    }
    // 0x8009FE08: nop

    // 0x8009FE0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009FE10: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x8009FE14: nop

L_8009FE18:
    // 0x8009FE18: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE1C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8009FE20: bne         $at, $zero, L_8009FEE0
    if (ctx->r1 != 0) {
        // 0x8009FE24: nop
    
            goto L_8009FEE0;
    }
    // 0x8009FE24: nop

    // 0x8009FE28: swc1        $f22, 0x3C8($a0)
    MEM_W(0X3C8, ctx->r4) = ctx->f22.u32l;
    // 0x8009FE2C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE30: nop

    // 0x8009FE34: swc1        $f22, 0x3E8($t7)
    MEM_W(0X3E8, ctx->r15) = ctx->f22.u32l;
    // 0x8009FE38: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE3C: nop

    // 0x8009FE40: swc1        $f22, 0x3A8($t8)
    MEM_W(0X3A8, ctx->r24) = ctx->f22.u32l;
    // 0x8009FE44: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE48: nop

    // 0x8009FE4C: swc1        $f22, 0x188($t6)
    MEM_W(0X188, ctx->r14) = ctx->f22.u32l;
    // 0x8009FE50: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE54: nop

    // 0x8009FE58: swc1        $f22, 0x1A8($t9)
    MEM_W(0X1A8, ctx->r25) = ctx->f22.u32l;
    // 0x8009FE5C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE60: addiu       $t9, $zero, 0x26
    ctx->r25 = ADD32(0, 0X26);
    // 0x8009FE64: swc1        $f22, 0x468($t7)
    MEM_W(0X468, ctx->r15) = ctx->f22.u32l;
    // 0x8009FE68: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE6C: nop

    // 0x8009FE70: swc1        $f22, 0x488($t8)
    MEM_W(0X488, ctx->r24) = ctx->f22.u32l;
    // 0x8009FE74: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE78: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x8009FE7C: swc1        $f22, 0x1C8($t6)
    MEM_W(0X1C8, ctx->r14) = ctx->f22.u32l;
    // 0x8009FE80: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE84: nop

    // 0x8009FE88: sh          $t9, 0x3C6($t7)
    MEM_H(0X3C6, ctx->r15) = ctx->r25;
    // 0x8009FE8C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE90: addiu       $t9, $zero, 0x29
    ctx->r25 = ADD32(0, 0X29);
    // 0x8009FE94: sh          $t8, 0x3E6($t6)
    MEM_H(0X3E6, ctx->r14) = ctx->r24;
    // 0x8009FE98: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE9C: addiu       $t8, $zero, 0x25
    ctx->r24 = ADD32(0, 0X25);
    // 0x8009FEA0: sh          $t9, 0x3A6($t7)
    MEM_H(0X3A6, ctx->r15) = ctx->r25;
    // 0x8009FEA4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FEA8: addiu       $t9, $zero, 0x27
    ctx->r25 = ADD32(0, 0X27);
    // 0x8009FEAC: sh          $t8, 0x186($t6)
    MEM_H(0X186, ctx->r14) = ctx->r24;
    // 0x8009FEB0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FEB4: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x8009FEB8: sh          $t9, 0x1A6($t7)
    MEM_H(0X1A6, ctx->r15) = ctx->r25;
    // 0x8009FEBC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FEC0: addiu       $t9, $zero, 0x2C
    ctx->r25 = ADD32(0, 0X2C);
    // 0x8009FEC4: sh          $t8, 0x466($t6)
    MEM_H(0X466, ctx->r14) = ctx->r24;
    // 0x8009FEC8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FECC: addiu       $t8, $zero, 0x2A
    ctx->r24 = ADD32(0, 0X2A);
    // 0x8009FED0: sh          $t9, 0x486($t7)
    MEM_H(0X486, ctx->r15) = ctx->r25;
    // 0x8009FED4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FED8: b           L_8009FEF0
    // 0x8009FEDC: sh          $t8, 0x1C6($t6)
    MEM_H(0X1C6, ctx->r14) = ctx->r24;
        goto L_8009FEF0;
    // 0x8009FEDC: sh          $t8, 0x1C6($t6)
    MEM_H(0X1C6, ctx->r14) = ctx->r24;
L_8009FEE0:
    // 0x8009FEE0: sb          $t4, 0x5D($a0)
    MEM_B(0X5D, ctx->r4) = ctx->r12;
    // 0x8009FEE4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FEE8: nop

    // 0x8009FEEC: sb          $t4, 0x37D($t9)
    MEM_B(0X37D, ctx->r25) = ctx->r12;
L_8009FEF0:
    // 0x8009FEF0: jal         0x8000E4D8
    // 0x8009FEF4: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    is_in_time_trial(rdram, ctx);
        goto after_4;
    // 0x8009FEF4: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    after_4:
    // 0x8009FEF8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009FEFC: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x8009FF00: beq         $v0, $zero, L_800A0010
    if (ctx->r2 == 0) {
        // 0x8009FF04: addiu       $a1, $a1, 0x729C
        ctx->r5 = ADD32(ctx->r5, 0X729C);
            goto L_800A0010;
    }
    // 0x8009FF04: addiu       $a1, $a1, 0x729C
    ctx->r5 = ADD32(ctx->r5, 0X729C);
    // 0x8009FF08: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF0C: nop

    // 0x8009FF10: lwc1        $f6, 0xEC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8009FF14: nop

    // 0x8009FF18: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8009FF1C: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    // 0x8009FF20: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF24: nop

    // 0x8009FF28: lwc1        $f10, 0x10C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x8009FF2C: nop

    // 0x8009FF30: add.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8009FF34: swc1        $f4, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FF38: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF3C: nop

    // 0x8009FF40: lwc1        $f6, 0x12C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x8009FF44: nop

    // 0x8009FF48: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8009FF4C: swc1        $f8, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FF50: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF54: nop

    // 0x8009FF58: lwc1        $f10, 0x38C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38C);
    // 0x8009FF5C: nop

    // 0x8009FF60: add.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8009FF64: swc1        $f4, 0x38C($a0)
    MEM_W(0X38C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FF68: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF6C: nop

    // 0x8009FF70: lwc1        $f6, 0x36C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X36C);
    // 0x8009FF74: nop

    // 0x8009FF78: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8009FF7C: swc1        $f8, 0x36C($a0)
    MEM_W(0X36C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FF80: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF84: nop

    // 0x8009FF88: lwc1        $f10, 0x24C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24C);
    // 0x8009FF8C: nop

    // 0x8009FF90: add.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8009FF94: swc1        $f4, 0x24C($a0)
    MEM_W(0X24C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FF98: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF9C: nop

    // 0x8009FFA0: lwc1        $f6, 0x8C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8009FFA4: nop

    // 0x8009FFA8: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8009FFAC: swc1        $f8, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FFB0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FFB4: nop

    // 0x8009FFB8: lwc1        $f10, 0xAC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x8009FFBC: nop

    // 0x8009FFC0: add.s       $f4, $f10, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8009FFC4: swc1        $f4, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f4.u32l;
    // 0x8009FFC8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FFCC: nop

    // 0x8009FFD0: lwc1        $f6, 0xCC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x8009FFD4: nop

    // 0x8009FFD8: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8009FFDC: swc1        $f8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f8.u32l;
    // 0x8009FFE0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FFE4: nop

    // 0x8009FFE8: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8009FFEC: nop

    // 0x8009FFF0: add.s       $f4, $f10, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8009FFF4: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FFF8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FFFC: nop

    // 0x800A0000: lwc1        $f6, 0x20C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20C);
    // 0x800A0004: nop

    // 0x800A0008: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x800A000C: swc1        $f8, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->f8.u32l;
L_800A0010:
    // 0x800A0010: jal         0x8006BFD8
    // 0x800A0014: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    level_type(rdram, ctx);
        goto after_5;
    // 0x800A0014: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    after_5:
    // 0x800A0018: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A001C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A0020: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A0024: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A0028: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x800A002C: addiu       $a1, $a1, 0x729C
    ctx->r5 = ADD32(ctx->r5, 0X729C);
    // 0x800A0030: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800A0034: beq         $v0, $at, L_800A0050
    if (ctx->r2 == ctx->r1) {
        // 0x800A0038: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800A0050;
    }
    // 0x800A0038: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A003C: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A0040: beq         $v0, $at, L_800A015C
    if (ctx->r2 == ctx->r1) {
        // 0x800A0044: lui         $t7, 0x8000
        ctx->r15 = S32(0X8000 << 16);
            goto L_800A015C;
    }
    // 0x800A0044: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800A0048: b           L_800A0260
    // 0x800A004C: nop

        goto L_800A0260;
    // 0x800A004C: nop

L_800A0050:
    // 0x800A0050: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0054: nop

    // 0x800A0058: lwc1        $f10, 0xEC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x800A005C: nop

    // 0x800A0060: add.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x800A0064: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x800A0068: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A006C: nop

    // 0x800A0070: lwc1        $f6, 0x10C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x800A0074: nop

    // 0x800A0078: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x800A007C: swc1        $f8, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f8.u32l;
    // 0x800A0080: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0084: nop

    // 0x800A0088: lwc1        $f10, 0x12C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x800A008C: nop

    // 0x800A0090: add.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x800A0094: swc1        $f4, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f4.u32l;
    // 0x800A0098: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A009C: nop

    // 0x800A00A0: lwc1        $f6, 0x38C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X38C);
    // 0x800A00A4: nop

    // 0x800A00A8: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x800A00AC: swc1        $f8, 0x38C($a0)
    MEM_W(0X38C, ctx->r4) = ctx->f8.u32l;
    // 0x800A00B0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A00B4: nop

    // 0x800A00B8: lwc1        $f10, 0x36C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X36C);
    // 0x800A00BC: nop

    // 0x800A00C0: add.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x800A00C4: swc1        $f4, 0x36C($a0)
    MEM_W(0X36C, ctx->r4) = ctx->f4.u32l;
    // 0x800A00C8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A00CC: nop

    // 0x800A00D0: lwc1        $f6, 0x24C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24C);
    // 0x800A00D4: nop

    // 0x800A00D8: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x800A00DC: swc1        $f8, 0x24C($a0)
    MEM_W(0X24C, ctx->r4) = ctx->f8.u32l;
    // 0x800A00E0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A00E4: nop

    // 0x800A00E8: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800A00EC: nop

    // 0x800A00F0: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x800A00F4: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x800A00F8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A00FC: nop

    // 0x800A0100: lwc1        $f6, 0x8C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x800A0104: nop

    // 0x800A0108: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x800A010C: swc1        $f8, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f8.u32l;
    // 0x800A0110: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0114: nop

    // 0x800A0118: lwc1        $f10, 0xAC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x800A011C: nop

    // 0x800A0120: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x800A0124: swc1        $f4, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f4.u32l;
    // 0x800A0128: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A012C: nop

    // 0x800A0130: lwc1        $f6, 0xCC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x800A0134: nop

    // 0x800A0138: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x800A013C: swc1        $f8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f8.u32l;
    // 0x800A0140: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0144: nop

    // 0x800A0148: lwc1        $f10, 0x20C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20C);
    // 0x800A014C: nop

    // 0x800A0150: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x800A0154: b           L_800A0260
    // 0x800A0158: swc1        $f4, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->f4.u32l;
        goto L_800A0260;
    // 0x800A0158: swc1        $f4, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->f4.u32l;
L_800A015C:
    // 0x800A015C: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800A0160: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0164: bne         $t7, $zero, L_800A0184
    if (ctx->r15 != 0) {
        // 0x800A0168: nop
    
            goto L_800A0184;
    }
    // 0x800A0168: nop

    // 0x800A016C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0170: nop

    // 0x800A0174: lwc1        $f6, 0x410($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X410);
    // 0x800A0178: nop

    // 0x800A017C: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800A0180: swc1        $f8, 0x410($a0)
    MEM_W(0X410, ctx->r4) = ctx->f8.u32l;
L_800A0184:
    // 0x800A0184: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A0188: nop

    // 0x800A018C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800A0190: bne         $at, $zero, L_800A01B8
    if (ctx->r1 != 0) {
        // 0x800A0194: nop
    
            goto L_800A01B8;
    }
    // 0x800A0194: nop

    // 0x800A0198: beq         $a3, $zero, L_800A01A8
    if (ctx->r7 == 0) {
        // 0x800A019C: nop
    
            goto L_800A01A8;
    }
    // 0x800A019C: nop

    // 0x800A01A0: bne         $a3, $t3, L_800A01B0
    if (ctx->r7 != ctx->r11) {
        // 0x800A01A4: nop
    
            goto L_800A01B0;
    }
    // 0x800A01A4: nop

L_800A01A8:
    // 0x800A01A8: b           L_800A01CC
    // 0x800A01AC: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
        goto L_800A01CC;
    // 0x800A01AC: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_800A01B0:
    // 0x800A01B0: b           L_800A01CC
    // 0x800A01B4: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
        goto L_800A01CC;
    // 0x800A01B4: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
L_800A01B8:
    // 0x800A01B8: bne         $t4, $v0, L_800A01CC
    if (ctx->r12 != ctx->r2) {
        // 0x800A01BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A01CC;
    }
    // 0x800A01BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A01C0: b           L_800A01CC
    // 0x800A01C4: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
        goto L_800A01CC;
    // 0x800A01C4: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
    // 0x800A01C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A01CC:
    // 0x800A01CC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800A01D0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A01D4: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A01D8: lwc1        $f4, 0x36C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X36C);
    // 0x800A01DC: nop

    // 0x800A01E0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A01E4: swc1        $f6, 0x36C($a0)
    MEM_W(0X36C, ctx->r4) = ctx->f6.u32l;
    // 0x800A01E8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A01EC: nop

    // 0x800A01F0: lwc1        $f8, 0xEC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x800A01F4: nop

    // 0x800A01F8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A01FC: swc1        $f10, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f10.u32l;
    // 0x800A0200: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0204: nop

    // 0x800A0208: lwc1        $f4, 0x10C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x800A020C: nop

    // 0x800A0210: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A0214: swc1        $f6, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f6.u32l;
    // 0x800A0218: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A021C: nop

    // 0x800A0220: lwc1        $f8, 0x12C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x800A0224: nop

    // 0x800A0228: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A022C: swc1        $f10, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f10.u32l;
    // 0x800A0230: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0234: nop

    // 0x800A0238: lwc1        $f4, 0x38C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38C);
    // 0x800A023C: nop

    // 0x800A0240: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A0244: swc1        $f6, 0x38C($a0)
    MEM_W(0X38C, ctx->r4) = ctx->f6.u32l;
    // 0x800A0248: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A024C: nop

    // 0x800A0250: lwc1        $f8, 0x24C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24C);
    // 0x800A0254: nop

    // 0x800A0258: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A025C: swc1        $f10, 0x24C($a0)
    MEM_W(0X24C, ctx->r4) = ctx->f10.u32l;
L_800A0260:
    // 0x800A0260: jal         0x80023450
    // 0x800A0264: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    is_taj_challenge(rdram, ctx);
        goto after_6;
    // 0x800A0264: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    after_6:
    // 0x800A0268: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A026C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A0270: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A0274: lwc1        $f13, -0x7398($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, -0X7398);
    // 0x800A0278: lwc1        $f12, -0x7394($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7394);
    // 0x800A027C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A0280: lwc1        $f15, -0x7390($at)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r1, -0X7390);
    // 0x800A0284: lwc1        $f14, -0x738C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X738C);
    // 0x800A0288: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x800A028C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A0290: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A0294: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A0298: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A029C: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x800A02A0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A02A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A02A8: addiu       $t1, $t1, 0x72B0
    ctx->r9 = ADD32(ctx->r9, 0X72B0);
    // 0x800A02AC: addiu       $a1, $a1, 0x729C
    ctx->r5 = ADD32(ctx->r5, 0X729C);
    // 0x800A02B0: ori         $t0, $zero, 0xC000
    ctx->r8 = 0 | 0XC000;
    // 0x800A02B4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800A02B8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800A02BC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A02C0: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x800A02C4: beq         $v0, $zero, L_800A0344
    if (ctx->r2 == 0) {
        // 0x800A02C8: addiu       $ra, $zero, 0x12
        ctx->r31 = ADD32(0, 0X12);
            goto L_800A0344;
    }
    // 0x800A02C8: addiu       $ra, $zero, 0x12
    ctx->r31 = ADD32(0, 0X12);
    // 0x800A02CC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A02D0: nop

    // 0x800A02D4: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800A02D8: nop

    // 0x800A02DC: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800A02E0: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x800A02E4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A02E8: nop

    // 0x800A02EC: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x800A02F0: nop

    // 0x800A02F4: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A02F8: swc1        $f10, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f10.u32l;
    // 0x800A02FC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0300: nop

    // 0x800A0304: lwc1        $f4, 0xAC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x800A0308: nop

    // 0x800A030C: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800A0310: swc1        $f6, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f6.u32l;
    // 0x800A0314: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0318: nop

    // 0x800A031C: lwc1        $f8, 0xCC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x800A0320: nop

    // 0x800A0324: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A0328: swc1        $f10, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f10.u32l;
    // 0x800A032C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0330: nop

    // 0x800A0334: lwc1        $f4, 0x20C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20C);
    // 0x800A0338: nop

    // 0x800A033C: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800A0340: swc1        $f6, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->f6.u32l;
L_800A0344:
    // 0x800A0344: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800A0348: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800A034C: nop

    // 0x800A0350: bne         $t8, $zero, L_800A04A0
    if (ctx->r24 != 0) {
        // 0x800A0354: nop
    
            goto L_800A04A0;
    }
    // 0x800A0354: nop

    // 0x800A0358: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A035C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A0360: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
L_800A0364:
    // 0x800A0364: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800A0368: nop

    // 0x800A036C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800A0370: mul.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x800A0374: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800A0378: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x800A037C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A0380: nop

    // 0x800A0384: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x800A0388: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800A038C: nop

    // 0x800A0390: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800A0394: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x800A0398: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A039C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800A03A0: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800A03A4: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x800A03A8: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800A03AC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800A03B0: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800A03B4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800A03B8: slti        $at, $v1, 0x760
    ctx->r1 = SIGNED(ctx->r3) < 0X760 ? 1 : 0;
    // 0x800A03BC: andi        $t9, $t7, 0xC000
    ctx->r25 = ctx->r15 & 0XC000;
    // 0x800A03C0: bne         $t0, $t9, L_800A03E0
    if (ctx->r8 != ctx->r25) {
        // 0x800A03C4: nop
    
            goto L_800A03E0;
    }
    // 0x800A03C4: nop

    // 0x800A03C8: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800A03CC: nop

    // 0x800A03D0: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A03D4: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x800A03D8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A03DC: nop

L_800A03E0:
    // 0x800A03E0: bne         $at, $zero, L_800A0364
    if (ctx->r1 != 0) {
        // 0x800A03E4: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800A0364;
    }
    // 0x800A03E4: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800A03E8: addiu       $v0, $a0, 0x4E0
    ctx->r2 = ADD32(ctx->r4, 0X4E0);
    // 0x800A03EC: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800A03F0: addiu       $a2, $zero, 0x2A
    ctx->r6 = ADD32(0, 0X2A);
    // 0x800A03F4: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A03F8: sll         $v1, $a2, 5
    ctx->r3 = S32(ctx->r6 << 5);
    // 0x800A03FC: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x800A0400: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A0404: nop

    // 0x800A0408: lwc1        $f4, 0x510($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X510);
    // 0x800A040C: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, 0X4E0);
    // 0x800A0410: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A0414: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x800A0418: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A041C: nop

    // 0x800A0420: lwc1        $f8, 0x530($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X530);
    // 0x800A0424: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, 0X4E0);
    // 0x800A0428: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A042C: swc1        $f10, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f10.u32l;
    // 0x800A0430: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800A0434: nop

    // 0x800A0438: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x800A043C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800A0440: nop

    // 0x800A0444: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A0448: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x800A044C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A0450: nop

    // 0x800A0454: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x800A0458: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800A045C: nop

    // 0x800A0460: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A0464: swc1        $f10, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f10.u32l;
    // 0x800A0468: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A046C: nop

    // 0x800A0470: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x800A0474: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x800A0478: nop

    // 0x800A047C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A0480: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
    // 0x800A0484: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A0488: nop

    // 0x800A048C: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x800A0490: lwc1        $f8, 0x70($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X70);
    // 0x800A0494: nop

    // 0x800A0498: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A049C: swc1        $f10, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f10.u32l;
L_800A04A0:
    // 0x800A04A0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800A04A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800A04A8: swc1        $f22, 0x268($t8)
    MEM_W(0X268, ctx->r24) = ctx->f22.u32l;
    // 0x800A04AC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A04B0: nop

    // 0x800A04B4: sh          $ra, 0x286($t6)
    MEM_H(0X286, ctx->r14) = ctx->r31;
    // 0x800A04B8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A04BC: nop

    // 0x800A04C0: sh          $t5, 0x2A6($t7)
    MEM_H(0X2A6, ctx->r15) = ctx->r13;
    // 0x800A04C4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A04C8: nop

    // 0x800A04CC: sh          $t5, 0x2C6($t9)
    MEM_H(0X2C6, ctx->r25) = ctx->r13;
    // 0x800A04D0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800A04D4: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x800A04D8: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800A04DC: bne         $a3, $t7, L_8009F818
    if (ctx->r7 != ctx->r15) {
        // 0x800A04E0: sw          $t6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r14;
            goto L_8009F818;
    }
    // 0x800A04E0: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_800A04E4:
    // 0x800A04E4: jal         0x8006BFD8
    // 0x800A04E8: nop

    level_type(rdram, ctx);
        goto after_7;
    // 0x800A04E8: nop

    after_7:
    // 0x800A04EC: andi        $t9, $v0, 0x40
    ctx->r25 = ctx->r2 & 0X40;
    // 0x800A04F0: beq         $t9, $zero, L_800A0514
    if (ctx->r25 == 0) {
        // 0x800A04F4: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800A0514;
    }
    // 0x800A04F4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A04F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A04FC: addiu       $v0, $v0, 0x2D24
    ctx->r2 = ADD32(ctx->r2, 0X2D24);
    // 0x800A0500: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x800A0504: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A0508: sb          $t8, 0x2D28($at)
    MEM_B(0X2D28, ctx->r1) = ctx->r24;
    // 0x800A050C: b           L_800A0524
    // 0x800A0510: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
        goto L_800A0524;
    // 0x800A0510: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
L_800A0514:
    // 0x800A0514: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A0518: lb          $t6, 0x2D28($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X2D28);
    // 0x800A051C: addiu       $v0, $v0, 0x2D24
    ctx->r2 = ADD32(ctx->r2, 0X2D24);
    // 0x800A0520: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
L_800A0524:
    // 0x800A0524: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800A0528: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A052C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A0530: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800A0534: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A0538: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800A053C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A0540: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800A0544: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A0548: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800A054C: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A0550: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800A0554: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800A0558: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800A055C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800A0560: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800A0564: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800A0568: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800A056C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800A0570: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800A0574: jr          $ra
    // 0x800A0578: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800A0578: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void hud_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A057C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A0580: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0584: lw          $v0, 0x72B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72B8);
    // 0x800A0588: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A058C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A0590: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A0594: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A0598: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A059C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A05A0: blez        $v0, L_800A066C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A05A4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800A066C;
    }
    // 0x800A05A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A05A8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A05AC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A05B0: addiu       $s2, $s2, 0x72B4
    ctx->r18 = ADD32(ctx->r18, 0X72B4);
    // 0x800A05B4: addiu       $s4, $s4, 0x72B0
    ctx->r20 = ADD32(ctx->r20, 0X72B0);
    // 0x800A05B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A05BC: ori         $s3, $zero, 0xC000
    ctx->r19 = 0 | 0XC000;
L_800A05C0:
    // 0x800A05C0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800A05C4: nop

    // 0x800A05C8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800A05CC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800A05D0: nop

    // 0x800A05D4: beq         $a0, $zero, L_800A065C
    if (ctx->r4 == 0) {
        // 0x800A05D8: nop
    
            goto L_800A065C;
    }
    // 0x800A05D8: nop

    // 0x800A05DC: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800A05E0: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x800A05E4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800A05E8: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x800A05EC: nop

    // 0x800A05F0: andi        $t1, $v0, 0xC000
    ctx->r9 = ctx->r2 & 0XC000;
    // 0x800A05F4: bne         $s3, $t1, L_800A060C
    if (ctx->r19 != ctx->r9) {
        // 0x800A05F8: andi        $t2, $v0, 0x8000
        ctx->r10 = ctx->r2 & 0X8000;
            goto L_800A060C;
    }
    // 0x800A05F8: andi        $t2, $v0, 0x8000
    ctx->r10 = ctx->r2 & 0X8000;
    // 0x800A05FC: jal         0x8007B70C
    // 0x800A0600: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x800A0600: nop

    after_0:
    // 0x800A0604: b           L_800A0648
    // 0x800A0608: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
        goto L_800A0648;
    // 0x800A0608: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_800A060C:
    // 0x800A060C: beq         $t2, $zero, L_800A0624
    if (ctx->r10 == 0) {
        // 0x800A0610: andi        $t3, $v0, 0x4000
        ctx->r11 = ctx->r2 & 0X4000;
            goto L_800A0624;
    }
    // 0x800A0610: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x800A0614: jal         0x8007D100
    // 0x800A0618: nop

    sprite_free(rdram, ctx);
        goto after_1;
    // 0x800A0618: nop

    after_1:
    // 0x800A061C: b           L_800A0648
    // 0x800A0620: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
        goto L_800A0648;
    // 0x800A0620: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_800A0624:
    // 0x800A0624: beq         $t3, $zero, L_800A063C
    if (ctx->r11 == 0) {
        // 0x800A0628: nop
    
            goto L_800A063C;
    }
    // 0x800A0628: nop

    // 0x800A062C: jal         0x8000FFB8
    // 0x800A0630: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x800A0630: nop

    after_2:
    // 0x800A0634: b           L_800A0648
    // 0x800A0638: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
        goto L_800A0648;
    // 0x800A0638: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_800A063C:
    // 0x800A063C: jal         0x80060180
    // 0x800A0640: nop

    free_3d_model(rdram, ctx);
        goto after_3;
    // 0x800A0640: nop

    after_3:
    // 0x800A0644: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_800A0648:
    // 0x800A0648: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A064C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x800A0650: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800A0654: lw          $v0, 0x72B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72B8);
    // 0x800A0658: nop

L_800A065C:
    // 0x800A065C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A0660: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800A0664: bne         $at, $zero, L_800A05C0
    if (ctx->r1 != 0) {
        // 0x800A0668: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800A05C0;
    }
    // 0x800A0668: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800A066C:
    // 0x800A066C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0670: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A0674: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A0678: lw          $a0, 0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72A0);
    // 0x800A067C: addiu       $s4, $s4, 0x72B0
    ctx->r20 = ADD32(ctx->r20, 0X72B0);
    // 0x800A0680: jal         0x80071380
    // 0x800A0684: addiu       $s2, $s2, 0x72B4
    ctx->r18 = ADD32(ctx->r18, 0X72B4);
    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800A0684: addiu       $s2, $s2, 0x72B4
    ctx->r18 = ADD32(ctx->r18, 0X72B4);
    after_4:
    // 0x800A0688: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800A068C: jal         0x80071380
    // 0x800A0690: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800A0690: nop

    after_5:
    // 0x800A0694: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0698: sw          $zero, 0x72B8($at)
    MEM_W(0X72B8, ctx->r1) = 0;
    // 0x800A069C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800A06A0: jal         0x80071380
    // 0x800A06A4: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800A06A4: nop

    after_6:
    // 0x800A06A8: jal         0x8001004C
    // 0x800A06AC: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_7;
    // 0x800A06AC: nop

    after_7:
    // 0x800A06B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A06B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A06B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A06BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A06C0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A06C4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A06C8: jr          $ra
    // 0x800A06CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A06CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void race_starting(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A06D0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A06D4: lbu         $v0, 0x72F4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F4);
    // 0x800A06D8: jr          $ra
    // 0x800A06DC: nop

    return;
    // 0x800A06DC: nop

;}
RECOMP_FUNC void hud_render_player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A06E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A06E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A06E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A06EC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800A06F0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800A06F4: jal         0x80066460
    // 0x800A06F8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    get_current_viewport(rdram, ctx);
        goto after_0;
    // 0x800A06F8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A06FC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A0700: lbu         $t6, 0x774A($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X774A);
    // 0x800A0704: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0708: beq         $t6, $zero, L_800A0728
    if (ctx->r14 == 0) {
        // 0x800A070C: sw          $v0, 0x72C8($at)
        MEM_W(0X72C8, ctx->r1) = ctx->r2;
            goto L_800A0728;
    }
    // 0x800A070C: sw          $v0, 0x72C8($at)
    MEM_W(0X72C8, ctx->r1) = ctx->r2;
    // 0x800A0710: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A0714: lw          $t7, 0x72C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72C8);
    // 0x800A0718: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A071C: jal         0x8001BB4C
    // 0x800A0720: subu        $a0, $t8, $t7
    ctx->r4 = SUB32(ctx->r24, ctx->r15);
    get_racer_object_by_port(rdram, ctx);
        goto after_1;
    // 0x800A0720: subu        $a0, $t8, $t7
    ctx->r4 = SUB32(ctx->r24, ctx->r15);
    after_1:
    // 0x800A0724: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_800A0728:
    // 0x800A0728: jal         0x8006BFF0
    // 0x800A072C: nop

    level_header(rdram, ctx);
        goto after_2;
    // 0x800A072C: nop

    after_2:
    // 0x800A0730: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0734: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0738: bne         $t9, $zero, L_800A0760
    if (ctx->r25 != 0) {
        // 0x800A073C: sw          $v0, 0x7320($at)
        MEM_W(0X7320, ctx->r1) = ctx->r2;
            goto L_800A0760;
    }
    // 0x800A073C: sw          $v0, 0x7320($at)
    MEM_W(0X7320, ctx->r1) = ctx->r2;
    // 0x800A0740: jal         0x8001E474
    // 0x800A0744: nop

    cutscene_id(rdram, ctx);
        goto after_3;
    // 0x800A0744: nop

    after_3:
    // 0x800A0748: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A074C: bne         $v0, $at, L_800A0764
    if (ctx->r2 != ctx->r1) {
        // 0x800A0750: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_800A0764;
    }
    // 0x800A0750: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0754: jal         0x8001BB4C
    // 0x800A0758: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object_by_port(rdram, ctx);
        goto after_4;
    // 0x800A0758: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800A075C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_800A0760:
    // 0x800A0760: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_800A0764:
    // 0x800A0764: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A0768: beq         $t0, $zero, L_800A10A8
    if (ctx->r8 == 0) {
        // 0x800A076C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A10A8;
    }
    // 0x800A076C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A0770: lw          $t1, 0x7320($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7320);
    // 0x800A0774: nop

    // 0x800A0778: lbu         $t2, 0xBC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XBC);
    // 0x800A077C: nop

    // 0x800A0780: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800A0784: bne         $t3, $zero, L_800A10A8
    if (ctx->r11 != 0) {
        // 0x800A0788: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A10A8;
    }
    // 0x800A0788: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A078C: jal         0x8006DC4C
    // 0x800A0790: nop

    get_game_mode(rdram, ctx);
        goto after_5;
    // 0x800A0790: nop

    after_5:
    // 0x800A0794: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800A0798: beq         $v0, $v1, L_800A10A4
    if (ctx->r2 == ctx->r3) {
        // 0x800A079C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800A10A4;
    }
    // 0x800A079C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A07A0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A07A4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800A07A8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800A07AC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800A07B0: sw          $t5, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = ctx->r13;
    // 0x800A07B4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800A07B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A07BC: sw          $t8, 0x72C0($at)
    MEM_W(0X72C0, ctx->r1) = ctx->r24;
    // 0x800A07C0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800A07C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A07C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A07CC: lb          $t0, 0x7291($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7291);
    // 0x800A07D0: sw          $t9, 0x72C4($at)
    MEM_W(0X72C4, ctx->r1) = ctx->r25;
    // 0x800A07D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A07D8: beq         $t0, $zero, L_800A081C
    if (ctx->r8 == 0) {
        // 0x800A07DC: sw          $zero, 0x7740($at)
        MEM_W(0X7740, ctx->r1) = 0;
            goto L_800A081C;
    }
    // 0x800A07DC: sw          $zero, 0x7740($at)
    MEM_W(0X7740, ctx->r1) = 0;
    // 0x800A07E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A07E4: addiu       $a2, $a2, 0x7290
    ctx->r6 = ADD32(ctx->r6, 0X7290);
    // 0x800A07E8: lb          $t1, 0x0($a2)
    ctx->r9 = MEM_B(ctx->r6, 0X0);
    // 0x800A07EC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800A07F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A07F4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800A07F8: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x800A07FC: lb          $t4, 0x0($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X0);
    // 0x800A0800: lbu         $v0, 0x774B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X774B);
    // 0x800A0804: nop

    // 0x800A0808: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800A080C: beq         $at, $zero, L_800A084C
    if (ctx->r1 == 0) {
        // 0x800A0810: nop
    
            goto L_800A084C;
    }
    // 0x800A0810: nop

    // 0x800A0814: b           L_800A084C
    // 0x800A0818: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
        goto L_800A084C;
    // 0x800A0818: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_800A081C:
    // 0x800A081C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A0820: addiu       $a2, $a2, 0x7290
    ctx->r6 = ADD32(ctx->r6, 0X7290);
    // 0x800A0824: lb          $t5, 0x0($a2)
    ctx->r13 = MEM_B(ctx->r6, 0X0);
    // 0x800A0828: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800A082C: nop

    // 0x800A0830: subu        $t8, $t5, $t6
    ctx->r24 = SUB32(ctx->r13, ctx->r14);
    // 0x800A0834: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x800A0838: lb          $t7, 0x0($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X0);
    // 0x800A083C: nop

    // 0x800A0840: bgez        $t7, L_800A084C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800A0844: nop
    
            goto L_800A084C;
    }
    // 0x800A0844: nop

    // 0x800A0848: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
L_800A084C:
    // 0x800A084C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A0850: lb          $t9, 0x7292($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7292);
    // 0x800A0854: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0858: bne         $t9, $zero, L_800A10A4
    if (ctx->r25 != 0) {
        // 0x800A085C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800A10A4;
    }
    // 0x800A085C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A0860: lbu         $t1, 0x774A($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X774A);
    // 0x800A0864: lw          $v0, 0x64($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X64);
    // 0x800A0868: beq         $t1, $zero, L_800A0884
    if (ctx->r9 == 0) {
        // 0x800A086C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800A0884;
    }
    // 0x800A086C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A0870: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800A0874: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0878: subu        $t3, $v1, $t2
    ctx->r11 = SUB32(ctx->r3, ctx->r10);
    // 0x800A087C: b           L_800A0890
    // 0x800A0880: sw          $t3, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r11;
        goto L_800A0890;
    // 0x800A0880: sw          $t3, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r11;
L_800A0884:
    // 0x800A0884: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x800A0888: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A088C: sw          $t4, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r12;
L_800A0890:
    // 0x800A0890: lw          $t5, 0x72C8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72C8);
    // 0x800A0894: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A0898: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800A089C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800A08A0: lw          $t8, 0x72A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72A0);
    // 0x800A08A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A08A8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800A08AC: jal         0x8001E474
    // 0x800A08B0: sw          $t8, 0x729C($at)
    MEM_W(0X729C, ctx->r1) = ctx->r24;
    cutscene_id(rdram, ctx);
        goto after_6;
    // 0x800A08B0: sw          $t8, 0x729C($at)
    MEM_W(0X729C, ctx->r1) = ctx->r24;
    after_6:
    // 0x800A08B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A08B8: beq         $v0, $at, L_800A0AE8
    if (ctx->r2 == ctx->r1) {
        // 0x800A08BC: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800A0AE8;
    }
    // 0x800A08BC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A08C0: lw          $t7, 0x72CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72CC);
    // 0x800A08C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A08C8: bne         $t7, $zero, L_800A0988
    if (ctx->r15 != 0) {
        // 0x800A08CC: nop
    
            goto L_800A0988;
    }
    // 0x800A08CC: nop

    // 0x800A08D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A08D4: lw          $a0, 0x72D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72D0);
    // 0x800A08D8: jal         0x8006A794
    // 0x800A08DC: nop

    input_pressed(rdram, ctx);
        goto after_7;
    // 0x800A08DC: nop

    after_7:
    // 0x800A08E0: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x800A08E4: beq         $t9, $zero, L_800A0A4C
    if (ctx->r25 == 0) {
        // 0x800A08E8: nop
    
            goto L_800A0A4C;
    }
    // 0x800A08E8: nop

    // 0x800A08EC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800A08F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A08F4: lb          $t1, 0x1D8($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X1D8);
    // 0x800A08F8: nop

    // 0x800A08FC: bne         $t1, $zero, L_800A0A4C
    if (ctx->r9 != 0) {
        // 0x800A0900: nop
    
            goto L_800A0A4C;
    }
    // 0x800A0900: nop

    // 0x800A0904: lw          $t2, 0x7320($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7320);
    // 0x800A0908: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A090C: lb          $v0, 0x4C($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X4C);
    // 0x800A0910: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A0914: beq         $v0, $zero, L_800A0924
    if (ctx->r2 == 0) {
        // 0x800A0918: nop
    
            goto L_800A0924;
    }
    // 0x800A0918: nop

    // 0x800A091C: bne         $v0, $at, L_800A0A4C
    if (ctx->r2 != ctx->r1) {
        // 0x800A0920: nop
    
            goto L_800A0A4C;
    }
    // 0x800A0920: nop

L_800A0924:
    // 0x800A0924: lbu         $t3, 0x72F4($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X72F4);
    // 0x800A0928: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A092C: beq         $t3, $zero, L_800A0A4C
    if (ctx->r11 == 0) {
        // 0x800A0930: addiu       $v0, $v0, 0x2D10
        ctx->r2 = ADD32(ctx->r2, 0X2D10);
            goto L_800A0A4C;
    }
    // 0x800A0930: addiu       $v0, $v0, 0x2D10
    ctx->r2 = ADD32(ctx->r2, 0X2D10);
    // 0x800A0934: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x800A0938: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800A093C: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x800A0940: andi        $a0, $t6, 0xFF
    ctx->r4 = ctx->r14 & 0XFF;
    // 0x800A0944: addiu       $a0, $a0, 0x14F
    ctx->r4 = ADD32(ctx->r4, 0X14F);
    // 0x800A0948: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x800A094C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800A0950: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800A0954: jal         0x80001D04
    // 0x800A0958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800A0958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800A095C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A0960: addiu       $v0, $v0, 0x2D10
    ctx->r2 = ADD32(ctx->r2, 0X2D10);
    // 0x800A0964: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800A0968: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x800A096C: beq         $t7, $zero, L_800A0980
    if (ctx->r15 == 0) {
        // 0x800A0970: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800A0980;
    }
    // 0x800A0970: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A0974: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A0978: b           L_800A0A4C
    // 0x800A097C: sb          $t9, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = ctx->r25;
        goto L_800A0A4C;
    // 0x800A097C: sb          $t9, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = ctx->r25;
L_800A0980:
    // 0x800A0980: b           L_800A0A4C
    // 0x800A0984: sb          $zero, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = 0;
        goto L_800A0A4C;
    // 0x800A0984: sb          $zero, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = 0;
L_800A0988:
    // 0x800A0988: lw          $a0, 0x72D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72D0);
    // 0x800A098C: jal         0x8006A794
    // 0x800A0990: nop

    input_pressed(rdram, ctx);
        goto after_9;
    // 0x800A0990: nop

    after_9:
    // 0x800A0994: andi        $t0, $v0, 0x4
    ctx->r8 = ctx->r2 & 0X4;
    // 0x800A0998: beq         $t0, $zero, L_800A0A4C
    if (ctx->r8 == 0) {
        // 0x800A099C: nop
    
            goto L_800A0A4C;
    }
    // 0x800A099C: nop

    // 0x800A09A0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800A09A4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A09A8: lb          $t2, 0x1D8($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A09AC: nop

    // 0x800A09B0: bne         $t2, $zero, L_800A0A4C
    if (ctx->r10 != 0) {
        // 0x800A09B4: nop
    
            goto L_800A0A4C;
    }
    // 0x800A09B4: nop

    // 0x800A09B8: lw          $t3, 0x7320($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7320);
    // 0x800A09BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A09C0: lb          $t5, 0x4C($t3)
    ctx->r13 = MEM_B(ctx->r11, 0X4C);
    // 0x800A09C4: nop

    // 0x800A09C8: andi        $t4, $t5, 0x40
    ctx->r12 = ctx->r13 & 0X40;
    // 0x800A09CC: bne         $t4, $zero, L_800A0A4C
    if (ctx->r12 != 0) {
        // 0x800A09D0: nop
    
            goto L_800A0A4C;
    }
    // 0x800A09D0: nop

    // 0x800A09D4: lbu         $t6, 0x72F4($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X72F4);
    // 0x800A09D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A09DC: beq         $t6, $zero, L_800A0A4C
    if (ctx->r14 == 0) {
        // 0x800A09E0: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800A0A4C;
    }
    // 0x800A09E0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A09E4: lw          $t8, 0x72CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72CC);
    // 0x800A09E8: lh          $t0, 0x0($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X0);
    // 0x800A09EC: addiu       $t9, $t9, 0x2D14
    ctx->r25 = ADD32(ctx->r25, 0X2D14);
    // 0x800A09F0: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800A09F4: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800A09F8: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x800A09FC: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800A0A00: nop

    // 0x800A0A04: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800A0A08: beq         $at, $zero, L_800A0A18
    if (ctx->r1 == 0) {
        // 0x800A0A0C: addiu       $t2, $a0, 0x1
        ctx->r10 = ADD32(ctx->r4, 0X1);
            goto L_800A0A18;
    }
    // 0x800A0A0C: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x800A0A10: b           L_800A0A1C
    // 0x800A0A14: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
        goto L_800A0A1C;
    // 0x800A0A14: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
L_800A0A18:
    // 0x800A0A18: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_800A0A1C:
    // 0x800A0A1C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A0A20: addiu       $t7, $zero, 0x150
    ctx->r15 = ADD32(0, 0X150);
    // 0x800A0A24: lh          $t5, 0x0($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X0);
    // 0x800A0A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A0A2C: addu        $t4, $v1, $t5
    ctx->r12 = ADD32(ctx->r3, ctx->r13);
    // 0x800A0A30: lbu         $t6, 0x0($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X0);
    // 0x800A0A34: nop

    // 0x800A0A38: sltiu       $t8, $t6, 0x1
    ctx->r24 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800A0A3C: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    // 0x800A0A40: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x800A0A44: jal         0x80001D04
    // 0x800A0A48: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800A0A48: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_10:
L_800A0A4C:
    // 0x800A0A4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0A50: lw          $a0, 0x72D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72D0);
    // 0x800A0A54: jal         0x8006A794
    // 0x800A0A58: nop

    input_pressed(rdram, ctx);
        goto after_11;
    // 0x800A0A58: nop

    after_11:
    // 0x800A0A5C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A0A60: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800A0A64: beq         $t1, $zero, L_800A0AE8
    if (ctx->r9 == 0) {
        // 0x800A0A68: addiu       $a2, $a2, 0x7290
        ctx->r6 = ADD32(ctx->r6, 0X7290);
            goto L_800A0AE8;
    }
    // 0x800A0A68: addiu       $a2, $a2, 0x7290
    ctx->r6 = ADD32(ctx->r6, 0X7290);
    // 0x800A0A6C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800A0A70: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A0A74: lb          $t2, 0x1D8($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X1D8);
    // 0x800A0A78: nop

    // 0x800A0A7C: bne         $t2, $zero, L_800A0AE8
    if (ctx->r10 != 0) {
        // 0x800A0A80: nop
    
            goto L_800A0AE8;
    }
    // 0x800A0A80: nop

    // 0x800A0A84: lbu         $t3, 0x72F4($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X72F4);
    // 0x800A0A88: nop

    // 0x800A0A8C: beq         $t3, $zero, L_800A0AE8
    if (ctx->r11 == 0) {
        // 0x800A0A90: nop
    
            goto L_800A0AE8;
    }
    // 0x800A0A90: nop

    // 0x800A0A94: lb          $t5, 0x0($a2)
    ctx->r13 = MEM_B(ctx->r6, 0X0);
    // 0x800A0A98: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A0A9C: bne         $t5, $zero, L_800A0AE8
    if (ctx->r13 != 0) {
        // 0x800A0AA0: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800A0AE8;
    }
    // 0x800A0AA0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A0AA4: lw          $t4, 0x72CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72CC);
    // 0x800A0AA8: addiu       $t6, $t6, 0x2D24
    ctx->r14 = ADD32(ctx->r14, 0X2D24);
    // 0x800A0AAC: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x800A0AB0: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x800A0AB4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A0AB8: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x800A0ABC: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800A0AC0: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x800A0AC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A0AC8: bne         $t1, $zero, L_800A0AE0
    if (ctx->r9 != 0) {
        // 0x800A0ACC: addiu       $a0, $zero, 0x5E
        ctx->r4 = ADD32(0, 0X5E);
            goto L_800A0AE0;
    }
    // 0x800A0ACC: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    // 0x800A0AD0: jal         0x80001D04
    // 0x800A0AD4: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    sound_play(rdram, ctx);
        goto after_12;
    // 0x800A0AD4: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_12:
    // 0x800A0AD8: b           L_800A0AE8
    // 0x800A0ADC: nop

        goto L_800A0AE8;
    // 0x800A0ADC: nop

L_800A0AE0:
    // 0x800A0AE0: jal         0x80001D04
    // 0x800A0AE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x800A0AE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_800A0AE8:
    // 0x800A0AE8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A0AEC: lb          $t0, 0x7294($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7294);
    // 0x800A0AF0: nop

    // 0x800A0AF4: bne         $t0, $zero, L_800A0B88
    if (ctx->r8 != 0) {
        // 0x800A0AF8: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800A0B88;
    }
    // 0x800A0AF8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A0AFC: lw          $t2, 0x7320($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7320);
    // 0x800A0B00: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x800A0B04: lb          $v0, 0x4C($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X4C);
    // 0x800A0B08: nop

    // 0x800A0B0C: andi        $t3, $v0, 0x40
    ctx->r11 = ctx->r2 & 0X40;
    // 0x800A0B10: bne         $t3, $zero, L_800A0B2C
    if (ctx->r11 != 0) {
        // 0x800A0B14: nop
    
            goto L_800A0B2C;
    }
    // 0x800A0B14: nop

    // 0x800A0B18: beq         $v0, $zero, L_800A0B2C
    if (ctx->r2 == 0) {
        // 0x800A0B1C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A0B2C;
    }
    // 0x800A0B1C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A0B20: beq         $v0, $at, L_800A0B2C
    if (ctx->r2 == ctx->r1) {
        // 0x800A0B24: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800A0B2C;
    }
    // 0x800A0B24: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A0B28: bne         $v0, $at, L_800A0B60
    if (ctx->r2 != ctx->r1) {
        // 0x800A0B2C: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800A0B60;
    }
L_800A0B2C:
    // 0x800A0B2C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A0B30: addiu       $v0, $v0, 0x2CF0
    ctx->r2 = ADD32(ctx->r2, 0X2CF0);
    // 0x800A0B34: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x800A0B38: jal         0x80001844
    // 0x800A0B3C: sb          $v1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r3;
    music_stop(rdram, ctx);
        goto after_14;
    // 0x800A0B3C: sb          $v1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r3;
    after_14:
    // 0x800A0B40: jal         0x800012E8
    // 0x800A0B44: nop

    music_channel_reset_all(rdram, ctx);
        goto after_15;
    // 0x800A0B44: nop

    after_15:
    // 0x800A0B48: jal         0x80000B34
    // 0x800A0B4C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    music_play(rdram, ctx);
        goto after_16;
    // 0x800A0B4C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_16:
    // 0x800A0B50: jal         0x8000318C
    // 0x800A0B54: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_17;
    // 0x800A0B54: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_17:
    // 0x800A0B58: b           L_800A0B70
    // 0x800A0B5C: nop

        goto L_800A0B70;
    // 0x800A0B5C: nop

L_800A0B60:
    // 0x800A0B60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A0B64: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A0B68: jal         0x8006BF50
    // 0x800A0B6C: nop

    level_music_start(rdram, ctx);
        goto after_18;
    // 0x800A0B6C: nop

    after_18:
L_800A0B70:
    // 0x800A0B70: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0B74: addiu       $v0, $v0, 0x7294
    ctx->r2 = ADD32(ctx->r2, 0X7294);
    // 0x800A0B78: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x800A0B7C: nop

    // 0x800A0B80: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800A0B84: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
L_800A0B88:
    // 0x800A0B88: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0B8C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A0B90: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A0B94: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800A0B98: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A0B9C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A0BA0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A0BA4: jal         0x8007852C
    // 0x800A0BA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    rsp_init(rdram, ctx);
        goto after_19;
    // 0x800A0BA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_19:
    // 0x800A0BAC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0BB0: jal         0x800784A4
    // 0x800A0BB4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    rdp_init(rdram, ctx);
        goto after_20;
    // 0x800A0BB4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_20:
    // 0x800A0BB8: jal         0x8007B278
    // 0x800A0BBC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    tex_enable_modes(rdram, ctx);
        goto after_21;
    // 0x800A0BBC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_21:
    // 0x800A0BC0: jal         0x8007B25C
    // 0x800A0BC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    tex_disable_modes(rdram, ctx);
        goto after_22;
    // 0x800A0BC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_22:
    // 0x800A0BC8: jal         0x8007C36C
    // 0x800A0BCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_23;
    // 0x800A0BCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x800A0BD0: jal         0x80066750
    // 0x800A0BD4: nop

    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_24;
    // 0x800A0BD4: nop

    after_24:
    // 0x800A0BD8: bne         $v0, $zero, L_800A0D74
    if (ctx->r2 != 0) {
        // 0x800A0BDC: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800A0D74;
    }
    // 0x800A0BDC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A0BE0: lbu         $t7, 0x72F4($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X72F4);
    // 0x800A0BE4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A0BE8: bne         $t7, $zero, L_800A0D74
    if (ctx->r15 != 0) {
        // 0x800A0BEC: nop
    
            goto L_800A0D74;
    }
    // 0x800A0BEC: nop

    // 0x800A0BF0: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x800A0BF4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A0BF8: bne         $t1, $zero, L_800A0D74
    if (ctx->r9 != 0) {
        // 0x800A0BFC: nop
    
            goto L_800A0D74;
    }
    // 0x800A0BFC: nop

    // 0x800A0C00: lbu         $t0, 0x72F5($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X72F5);
    // 0x800A0C04: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0C08: beq         $t0, $zero, L_800A0CF0
    if (ctx->r8 == 0) {
        // 0x800A0C0C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800A0CF0;
    }
    // 0x800A0C0C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A0C10: addiu       $v0, $v0, 0x72EC
    ctx->r2 = ADD32(ctx->r2, 0X72EC);
    // 0x800A0C14: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x800A0C18: jal         0x80070A04
    // 0x800A0C1C: nop

    sins_f(rdram, ctx);
        goto after_25;
    // 0x800A0C1C: nop

    after_25:
    // 0x800A0C20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0C24: addiu       $a0, $a0, 0x72F0
    ctx->r4 = ADD32(ctx->r4, 0X72F0);
    // 0x800A0C28: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A0C2C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800A0C30: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A0C34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A0C38: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0C3C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800A0C40: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A0C44: addiu       $v0, $v0, 0x72EC
    ctx->r2 = ADD32(ctx->r2, 0X72EC);
    // 0x800A0C48: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x800A0C4C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A0C50: nop

    // 0x800A0C54: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A0C58: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A0C5C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A0C60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0C64: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A0C68: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800A0C6C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A0C70: sw          $t3, 0x72E8($at)
    MEM_W(0X72E8, ctx->r1) = ctx->r11;
    // 0x800A0C74: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x800A0C78: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800A0C7C: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x800A0C80: andi        $v1, $t8, 0xFFFF
    ctx->r3 = ctx->r24 & 0XFFFF;
    // 0x800A0C84: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800A0C88: bne         $at, $zero, L_800A0D74
    if (ctx->r1 != 0) {
        // 0x800A0C8C: sh          $t8, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r24;
            goto L_800A0D74;
    }
    // 0x800A0C8C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800A0C90: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800A0C94: addu        $t7, $v1, $at
    ctx->r15 = ADD32(ctx->r3, ctx->r1);
    // 0x800A0C98: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A0C9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A0CA0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800A0CA4: div.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800A0CA8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A0CAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A0CB0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A0CB4: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800A0CB8: addiu       $v1, $v1, 0x72E4
    ctx->r3 = ADD32(ctx->r3, 0X72E4);
    // 0x800A0CBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0CC0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A0CC4: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800A0CC8: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A0CCC: nop

    // 0x800A0CD0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A0CD4: c.le.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d <= ctx->f4.d;
    // 0x800A0CD8: nop

    // 0x800A0CDC: bc1f        L_800A0D74
    if (!c1cs) {
        // 0x800A0CE0: nop
    
            goto L_800A0D74;
    }
    // 0x800A0CE0: nop

    // 0x800A0CE4: sb          $t9, 0x72F4($at)
    MEM_B(0X72F4, ctx->r1) = ctx->r25;
    // 0x800A0CE8: b           L_800A0D74
    // 0x800A0CEC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800A0D74;
    // 0x800A0CEC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800A0CF0:
    // 0x800A0CF0: lb          $t1, 0x7294($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X7294);
    // 0x800A0CF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0CF8: bne         $t1, $at, L_800A0D1C
    if (ctx->r9 != ctx->r1) {
        // 0x800A0CFC: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800A0D1C;
    }
    // 0x800A0CFC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A0D00: jal         0x80001D04
    // 0x800A0D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_26;
    // 0x800A0D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x800A0D08: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A0D0C: lb          $t0, 0x7294($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7294);
    // 0x800A0D10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0D14: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800A0D18: sb          $t2, 0x7294($at)
    MEM_B(0X7294, ctx->r1) = ctx->r10;
L_800A0D1C:
    // 0x800A0D1C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800A0D20: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A0D24: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800A0D28: addiu       $v1, $v1, 0x72E4
    ctx->r3 = ADD32(ctx->r3, 0X72E4);
    // 0x800A0D2C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800A0D30: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800A0D34: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A0D38: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800A0D3C: subu        $v0, $t3, $t5
    ctx->r2 = SUB32(ctx->r11, ctx->r13);
    // 0x800A0D40: bgez        $v0, L_800A0D50
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A0D44: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800A0D50;
    }
    // 0x800A0D44: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800A0D48: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800A0D4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A0D50:
    // 0x800A0D50: bne         $v0, $zero, L_800A0D74
    if (ctx->r2 != 0) {
        // 0x800A0D54: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800A0D74;
    }
    // 0x800A0D54: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A0D58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0D5C: sb          $t8, 0x72F5($at)
    MEM_B(0X72F5, ctx->r1) = ctx->r24;
    // 0x800A0D60: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x800A0D64: jal         0x80001D04
    // 0x800A0D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_27;
    // 0x800A0D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x800A0D6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0D70: sw          $zero, 0x72E8($at)
    MEM_W(0X72E8, ctx->r1) = 0;
L_800A0D74:
    // 0x800A0D74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A0D78: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
    // 0x800A0D7C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A0D80: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800A0D84: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A0D88: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800A0D8C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800A0D90: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800A0D94: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A0D98: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0D9C: jal         0x800A7FBC
    // 0x800A0DA0: nop

    hud_magnet_reticle(rdram, ctx);
        goto after_28;
    // 0x800A0DA0: nop

    after_28:
    // 0x800A0DA4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0DA8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A0DAC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A0DB0: jal         0x8006816C
    // 0x800A0DB4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    mtx_ortho(rdram, ctx);
        goto after_29;
    // 0x800A0DB4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_29:
    // 0x800A0DB8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0DBC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A0DC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A0DC4: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x800A0DC8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800A0DCC: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800A0DD0: addiu       $t4, $zero, -0x100
    ctx->r12 = ADD32(0, -0X100);
    // 0x800A0DD4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A0DD8: jal         0x8001139C
    // 0x800A0DDC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    get_race_countdown(rdram, ctx);
        goto after_30;
    // 0x800A0DDC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_30:
    // 0x800A0DE0: sra         $a0, $v0, 1
    ctx->r4 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800A0DE4: jal         0x8000E4D8
    // 0x800A0DE8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    is_in_time_trial(rdram, ctx);
        goto after_31;
    // 0x800A0DE8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_31:
    // 0x800A0DEC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0DF0: beq         $v0, $zero, L_800A0E10
    if (ctx->r2 == 0) {
        // 0x800A0DF4: nop
    
            goto L_800A0E10;
    }
    // 0x800A0DF4: nop

    // 0x800A0DF8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0DFC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0E00: jal         0x800A2CBC
    // 0x800A0E04: nop

    hud_main_time_trial(rdram, ctx);
        goto after_32;
    // 0x800A0E04: nop

    after_32:
    // 0x800A0E08: b           L_800A0F48
    // 0x800A0E0C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0E0C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0E10:
    // 0x800A0E10: jal         0x8001E474
    // 0x800A0E14: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    cutscene_id(rdram, ctx);
        goto after_33;
    // 0x800A0E14: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_33:
    // 0x800A0E18: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0E1C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A0E20: bne         $v0, $at, L_800A0E4C
    if (ctx->r2 != ctx->r1) {
        // 0x800A0E24: nop
    
            goto L_800A0E4C;
    }
    // 0x800A0E24: nop

    // 0x800A0E28: jal         0x80068748
    // 0x800A0E2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_34;
    // 0x800A0E2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_34:
    // 0x800A0E30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0E34: jal         0x800A76E8
    // 0x800A0E38: nop

    hud_balloons(rdram, ctx);
        goto after_35;
    // 0x800A0E38: nop

    after_35:
    // 0x800A0E3C: jal         0x80068748
    // 0x800A0E40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_36;
    // 0x800A0E40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_36:
    // 0x800A0E44: b           L_800A0F48
    // 0x800A0E48: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0E48: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0E4C:
    // 0x800A0E4C: jal         0x8006BFD8
    // 0x800A0E50: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    level_type(rdram, ctx);
        goto after_37;
    // 0x800A0E50: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_37:
    // 0x800A0E54: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0E58: beq         $v0, $zero, L_800A0E90
    if (ctx->r2 == 0) {
        // 0x800A0E5C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A0E90;
    }
    // 0x800A0E5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A0E60: beq         $v0, $at, L_800A0E90
    if (ctx->r2 == ctx->r1) {
        // 0x800A0E64: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800A0E90;
    }
    // 0x800A0E64: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A0E68: beq         $v0, $at, L_800A0ED4
    if (ctx->r2 == ctx->r1) {
        // 0x800A0E6C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800A0ED4;
    }
    // 0x800A0E6C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A0E70: beq         $v0, $at, L_800A0F04
    if (ctx->r2 == ctx->r1) {
        // 0x800A0E74: addiu       $at, $zero, 0x41
        ctx->r1 = ADD32(0, 0X41);
            goto L_800A0F04;
    }
    // 0x800A0E74: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A0E78: beq         $v0, $at, L_800A0EEC
    if (ctx->r2 == ctx->r1) {
        // 0x800A0E7C: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_800A0EEC;
    }
    // 0x800A0E7C: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800A0E80: beq         $v0, $at, L_800A0F20
    if (ctx->r2 == ctx->r1) {
        // 0x800A0E84: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_800A0F20;
    }
    // 0x800A0E84: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0E88: b           L_800A0F38
    // 0x800A0E8C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
        goto L_800A0F38;
    // 0x800A0E8C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_800A0E90:
    // 0x800A0E90: jal         0x80023450
    // 0x800A0E94: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    is_taj_challenge(rdram, ctx);
        goto after_38;
    // 0x800A0E94: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_38:
    // 0x800A0E98: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0E9C: beq         $v0, $zero, L_800A0EC0
    if (ctx->r2 == 0) {
        // 0x800A0EA0: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_800A0EC0;
    }
    // 0x800A0EA0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0EA4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0EA8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0EAC: jal         0x800A2B7C
    // 0x800A0EB0: nop

    hud_main_taj(rdram, ctx);
        goto after_39;
    // 0x800A0EB0: nop

    after_39:
    // 0x800A0EB4: b           L_800A0F48
    // 0x800A0EB8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0EB8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A0EBC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
L_800A0EC0:
    // 0x800A0EC0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0EC4: jal         0x800A1300
    // 0x800A0EC8: nop

    hud_main_race(rdram, ctx);
        goto after_40;
    // 0x800A0EC8: nop

    after_40:
    // 0x800A0ECC: b           L_800A0F48
    // 0x800A0ED0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0ED0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0ED4:
    // 0x800A0ED4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0ED8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0EDC: jal         0x800A2ACC
    // 0x800A0EE0: nop

    hud_main_boss(rdram, ctx);
        goto after_41;
    // 0x800A0EE0: nop

    after_41:
    // 0x800A0EE4: b           L_800A0F48
    // 0x800A0EE8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0EE8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0EEC:
    // 0x800A0EEC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0EF0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0EF4: jal         0x800A1788
    // 0x800A0EF8: nop

    hud_main_treasure(rdram, ctx);
        goto after_42;
    // 0x800A0EF8: nop

    after_42:
    // 0x800A0EFC: b           L_800A0F48
    // 0x800A0F00: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0F00: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0F04:
    // 0x800A0F04: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0F08: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0F0C: jal         0x800A2144
    // 0x800A0F10: nop

    hud_main_battle(rdram, ctx);
        goto after_43;
    // 0x800A0F10: nop

    after_43:
    // 0x800A0F14: b           L_800A0F48
    // 0x800A0F18: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0F18: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A0F1C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
L_800A0F20:
    // 0x800A0F20: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0F24: jal         0x800A1968
    // 0x800A0F28: nop

    hud_main_eggs(rdram, ctx);
        goto after_44;
    // 0x800A0F28: nop

    after_44:
    // 0x800A0F2C: b           L_800A0F48
    // 0x800A0F30: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0F30: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A0F34: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_800A0F38:
    // 0x800A0F38: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A0F3C: jal         0x800A2C08
    // 0x800A0F40: nop

    hud_main_hub(rdram, ctx);
        goto after_45;
    // 0x800A0F40: nop

    after_45:
    // 0x800A0F44: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0F48:
    // 0x800A0F48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0F4C: lb          $t5, 0x1D8($t3)
    ctx->r13 = MEM_B(ctx->r11, 0X1D8);
    // 0x800A0F50: nop

    // 0x800A0F54: bne         $t5, $at, L_800A1008
    if (ctx->r13 != ctx->r1) {
        // 0x800A0F58: nop
    
            goto L_800A1008;
    }
    // 0x800A0F58: nop

    // 0x800A0F5C: jal         0x80068748
    // 0x800A0F60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_46;
    // 0x800A0F60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_46:
    // 0x800A0F64: jal         0x8000E4D8
    // 0x800A0F68: nop

    is_in_time_trial(rdram, ctx);
        goto after_47;
    // 0x800A0F68: nop

    after_47:
    // 0x800A0F6C: beq         $v0, $zero, L_800A0F8C
    if (ctx->r2 == 0) {
        // 0x800A0F70: nop
    
            goto L_800A0F8C;
    }
    // 0x800A0F70: nop

    // 0x800A0F74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0F78: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A0F7C: jal         0x800A738C
    // 0x800A0F80: nop

    hud_time_trial_finish(rdram, ctx);
        goto after_48;
    // 0x800A0F80: nop

    after_48:
    // 0x800A0F84: b           L_800A1000
    // 0x800A0F88: nop

        goto L_800A1000;
    // 0x800A0F88: nop

L_800A0F8C:
    // 0x800A0F8C: jal         0x80066450
    // 0x800A0F90: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_49;
    // 0x800A0F90: nop

    after_49:
    // 0x800A0F94: bne         $v0, $zero, L_800A0FF4
    if (ctx->r2 != 0) {
        // 0x800A0F98: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0FF4;
    }
    // 0x800A0F98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0F9C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800A0FA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0FA4: lh          $t8, 0x1AC($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X1AC);
    // 0x800A0FA8: nop

    // 0x800A0FAC: bne         $t8, $at, L_800A0FF4
    if (ctx->r24 != ctx->r1) {
        // 0x800A0FB0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0FF4;
    }
    // 0x800A0FB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0FB4: jal         0x8009F1C4
    // 0x800A0FB8: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_50;
    // 0x800A0FB8: nop

    after_50:
    // 0x800A0FBC: beq         $v0, $zero, L_800A0FDC
    if (ctx->r2 == 0) {
        // 0x800A0FC0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0FDC;
    }
    // 0x800A0FC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0FC4: jal         0x8006BFD8
    // 0x800A0FC8: nop

    level_type(rdram, ctx);
        goto after_51;
    // 0x800A0FC8: nop

    after_51:
    // 0x800A0FCC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A0FD0: bne         $v0, $at, L_800A0FF4
    if (ctx->r2 != ctx->r1) {
        // 0x800A0FD4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0FF4;
    }
    // 0x800A0FD4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0FD8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_800A0FDC:
    // 0x800A0FDC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A0FE0: jal         0x800A4EC4
    // 0x800A0FE4: nop

    hud_race_finish_1player(rdram, ctx);
        goto after_52;
    // 0x800A0FE4: nop

    after_52:
    // 0x800A0FE8: b           L_800A1000
    // 0x800A0FEC: nop

        goto L_800A1000;
    // 0x800A0FEC: nop

    // 0x800A0FF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_800A0FF4:
    // 0x800A0FF4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A0FF8: jal         0x800A679C
    // 0x800A0FFC: nop

    hud_race_finish_multiplayer(rdram, ctx);
        goto after_53;
    // 0x800A0FFC: nop

    after_53:
L_800A1000:
    // 0x800A1000: jal         0x80068748
    // 0x800A1004: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_54;
    // 0x800A1004: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_54:
L_800A1008:
    // 0x800A1008: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A100C: sb          $zero, 0x7291($at)
    MEM_B(0X7291, ctx->r1) = 0;
    // 0x800A1010: jal         0x8007C36C
    // 0x800A1014: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_55;
    // 0x800A1014: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_55:
    // 0x800A1018: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A101C: lw          $v0, 0x7740($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7740);
    // 0x800A1020: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A1024: beq         $v0, $zero, L_800A106C
    if (ctx->r2 == 0) {
        // 0x800A1028: addiu       $a1, $a1, 0x7340
        ctx->r5 = ADD32(ctx->r5, 0X7340);
            goto L_800A106C;
    }
    // 0x800A1028: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x800A102C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800A1030: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x800A1034: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800A1038: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A103C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A1040: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A1044: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A1048: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A104C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800A1050: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800A1054: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800A1058: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800A105C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A1060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A1064: jal         0x80078F08
    // 0x800A1068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    texrect_draw(rdram, ctx);
        goto after_56;
    // 0x800A1068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_56:
L_800A106C:
    // 0x800A106C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A1070: lw          $t3, 0x72BC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72BC);
    // 0x800A1074: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800A1078: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A107C: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x800A1080: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800A1084: lw          $t6, 0x72C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72C0);
    // 0x800A1088: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A108C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800A1090: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800A1094: lw          $t7, 0x72C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72C4);
    // 0x800A1098: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800A109C: jal         0x8007B278
    // 0x800A10A0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    tex_enable_modes(rdram, ctx);
        goto after_57;
    // 0x800A10A0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    after_57:
L_800A10A4:
    // 0x800A10A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A10A8:
    // 0x800A10A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A10AC: jr          $ra
    // 0x800A10B0: nop

    return;
    // 0x800A10B0: nop

;}
RECOMP_FUNC void hud_audio_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A10B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A10B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A10BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A10C0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800A10C4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800A10C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A10CC: addiu       $s1, $s1, 0x2D10
    ctx->r17 = ADD32(ctx->r17, 0X2D10);
    // 0x800A10D0: addiu       $s0, $s0, 0x2CF0
    ctx->r16 = ADD32(ctx->r16, 0X2CF0);
L_800A10D4:
    // 0x800A10D4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800A10D8: nop

    // 0x800A10DC: beq         $a0, $zero, L_800A10F4
    if (ctx->r4 == 0) {
        // 0x800A10E0: nop
    
            goto L_800A10F4;
    }
    // 0x800A10E0: nop

    // 0x800A10E4: jal         0x8000488C
    // 0x800A10E8: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x800A10E8: nop

    after_0:
    // 0x800A10EC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800A10F0: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
L_800A10F4:
    // 0x800A10F4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800A10F8: bne         $s0, $s1, L_800A10D4
    if (ctx->r16 != ctx->r17) {
        // 0x800A10FC: nop
    
            goto L_800A10D4;
    }
    // 0x800A10FC: nop

    // 0x800A1100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A1104: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A1108: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A110C: jr          $ra
    // 0x800A1110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A1110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void hud_audio_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1114: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A1118: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A111C: addiu       $v1, $v1, 0x7334
    ctx->r3 = ADD32(ctx->r3, 0X7334);
    // 0x800A1120: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A1124: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A1128: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800A112C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A1130: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A1134: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A1138: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A113C: blez        $v0, L_800A1174
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A1140: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800A1174;
    }
    // 0x800A1140: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A1144: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800A1148: bgtz        $t6, L_800A1174
    if (SIGNED(ctx->r14) > 0) {
        // 0x800A114C: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_800A1174;
    }
    // 0x800A114C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800A1150: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A1154: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A1158: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800A115C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800A1160: bne         $t8, $zero, L_800A1174
    if (ctx->r24 != 0) {
        // 0x800A1164: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A1174;
    }
    // 0x800A1164: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A1168: lhu         $a0, 0x733C($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X733C);
    // 0x800A116C: jal         0x80001D04
    // 0x800A1170: nop

    sound_play(rdram, ctx);
        goto after_0;
    // 0x800A1170: nop

    after_0:
L_800A1174:
    // 0x800A1174: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800A1178: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800A117C: addiu       $s3, $s3, 0x2D10
    ctx->r19 = ADD32(ctx->r19, 0X2D10);
    // 0x800A1180: addiu       $s0, $s0, 0x2CF0
    ctx->r16 = ADD32(ctx->r16, 0X2CF0);
    // 0x800A1184: addiu       $s4, $zero, 0x7F
    ctx->r20 = ADD32(0, 0X7F);
    // 0x800A1188: addiu       $s2, $zero, 0x7F
    ctx->r18 = ADD32(0, 0X7F);
L_800A118C:
    // 0x800A118C: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800A1190: nop

    // 0x800A1194: beq         $a2, $zero, L_800A1248
    if (ctx->r6 == 0) {
        // 0x800A1198: nop
    
            goto L_800A1248;
    }
    // 0x800A1198: nop

    // 0x800A119C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800A11A0: nop

    // 0x800A11A4: bne         $a1, $zero, L_800A11C4
    if (ctx->r5 != 0) {
        // 0x800A11A8: nop
    
            goto L_800A11C4;
    }
    // 0x800A11A8: nop

    // 0x800A11AC: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800A11B0: jal         0x80001D04
    // 0x800A11B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    sound_play(rdram, ctx);
        goto after_1;
    // 0x800A11B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x800A11B8: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800A11BC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800A11C0: nop

L_800A11C4:
    // 0x800A11C4: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800A11C8: jal         0x80001FB8
    // 0x800A11CC: nop

    sound_volume_set_relative(rdram, ctx);
        goto after_2;
    // 0x800A11CC: nop

    after_2:
    // 0x800A11D0: lb          $a0, 0x3($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X3);
    // 0x800A11D4: nop

    // 0x800A11D8: blez        $a0, L_800A1210
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800A11DC: nop
    
            goto L_800A1210;
    }
    // 0x800A11DC: nop

    // 0x800A11E0: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A11E4: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x800A11E8: mflo        $v0
    ctx->r2 = lo;
    // 0x800A11EC: subu        $t9, $s2, $v0
    ctx->r25 = SUB32(ctx->r18, ctx->r2);
    // 0x800A11F0: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A11F4: bne         $at, $zero, L_800A1204
    if (ctx->r1 != 0) {
        // 0x800A11F8: addu        $t0, $v1, $v0
        ctx->r8 = ADD32(ctx->r3, ctx->r2);
            goto L_800A1204;
    }
    // 0x800A11F8: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x800A11FC: b           L_800A1264
    // 0x800A1200: sb          $t0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r8;
        goto L_800A1264;
    // 0x800A1200: sb          $t0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r8;
L_800A1204:
    // 0x800A1204: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800A1208: b           L_800A1264
    // 0x800A120C: sb          $s4, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r20;
        goto L_800A1264;
    // 0x800A120C: sb          $s4, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r20;
L_800A1210:
    // 0x800A1210: bgez        $a0, L_800A1264
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800A1214: nop
    
            goto L_800A1264;
    }
    // 0x800A1214: nop

    // 0x800A1218: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A121C: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x800A1220: mflo        $v0
    ctx->r2 = lo;
    // 0x800A1224: negu        $t1, $v0
    ctx->r9 = SUB32(0, ctx->r2);
    // 0x800A1228: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A122C: beq         $at, $zero, L_800A123C
    if (ctx->r1 == 0) {
        // 0x800A1230: addu        $t2, $v1, $v0
        ctx->r10 = ADD32(ctx->r3, ctx->r2);
            goto L_800A123C;
    }
    // 0x800A1230: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
    // 0x800A1234: b           L_800A1264
    // 0x800A1238: sb          $t2, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r10;
        goto L_800A1264;
    // 0x800A1238: sb          $t2, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r10;
L_800A123C:
    // 0x800A123C: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800A1240: b           L_800A1264
    // 0x800A1244: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
        goto L_800A1264;
    // 0x800A1244: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
L_800A1248:
    // 0x800A1248: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800A124C: nop

    // 0x800A1250: beq         $a1, $zero, L_800A1264
    if (ctx->r5 == 0) {
        // 0x800A1254: nop
    
            goto L_800A1264;
    }
    // 0x800A1254: nop

    // 0x800A1258: jal         0x8000488C
    // 0x800A125C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    sndp_stop(rdram, ctx);
        goto after_3;
    // 0x800A125C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x800A1260: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_800A1264:
    // 0x800A1264: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800A1268: bne         $s0, $s3, L_800A118C
    if (ctx->r16 != ctx->r19) {
        // 0x800A126C: nop
    
            goto L_800A118C;
    }
    // 0x800A126C: nop

    // 0x800A1270: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1274: addiu       $v1, $v1, 0x7330
    ctx->r3 = ADD32(ctx->r3, 0X7330);
    // 0x800A1278: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x800A127C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800A1280: beq         $t3, $zero, L_800A12E4
    if (ctx->r11 == 0) {
        // 0x800A1284: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800A12E4;
    }
    // 0x800A1284: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A1288: lbu         $t4, 0x2CF2($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X2CF2);
    // 0x800A128C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A1290: bne         $t4, $zero, L_800A12E4
    if (ctx->r12 != 0) {
        // 0x800A1294: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800A12E4;
    }
    // 0x800A1294: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A1298: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800A129C: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A12A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A12A4: bne         $v0, $at, L_800A12C0
    if (ctx->r2 != ctx->r1) {
        // 0x800A12A8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A12C0;
    }
    // 0x800A12A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A12AC: jal         0x8000318C
    // 0x800A12B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_4;
    // 0x800A12B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_4:
    // 0x800A12B4: b           L_800A12E4
    // 0x800A12B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800A12E4;
    // 0x800A12B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A12BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800A12C0:
    // 0x800A12C0: bne         $v0, $at, L_800A12D8
    if (ctx->r2 != ctx->r1) {
        // 0x800A12C4: nop
    
            goto L_800A12D8;
    }
    // 0x800A12C4: nop

    // 0x800A12C8: jal         0x8000318C
    // 0x800A12CC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_5;
    // 0x800A12CC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_5:
    // 0x800A12D0: b           L_800A12E4
    // 0x800A12D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800A12E4;
    // 0x800A12D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800A12D8:
    // 0x800A12D8: jal         0x8000318C
    // 0x800A12DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_6;
    // 0x800A12DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_6:
    // 0x800A12E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800A12E4:
    // 0x800A12E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A12E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A12EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A12F0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A12F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A12F8: jr          $ra
    // 0x800A12FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A12FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void hud_main_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1300: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A1304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A1308: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A130C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A1310: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A1314: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A1318: lw          $s1, 0x64($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X64);
    // 0x800A131C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800A1320: jal         0x80068748
    // 0x800A1324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A1324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A1328: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A132C: jal         0x800A13F4
    // 0x800A1330: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_course_arrows(rdram, ctx);
        goto after_1;
    // 0x800A1330: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800A1334: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A1338: jal         0x800A5FAC
    // 0x800A133C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_wrong_way(rdram, ctx);
        goto after_2;
    // 0x800A133C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800A1340: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A1344: jal         0x800A422C
    // 0x800A1348: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_start(rdram, ctx);
        goto after_3;
    // 0x800A1348: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800A134C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A1350: lw          $t7, 0x7320($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7320);
    // 0x800A1354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A1358: lb          $t8, 0x4C($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X4C);
    // 0x800A135C: nop

    // 0x800A1360: bne         $t8, $zero, L_800A1370
    if (ctx->r24 != 0) {
        // 0x800A1364: nop
    
            goto L_800A1370;
    }
    // 0x800A1364: nop

    // 0x800A1368: jal         0x800A5498
    // 0x800A136C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_lap_count(rdram, ctx);
        goto after_4;
    // 0x800A136C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
L_800A1370:
    // 0x800A1370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A1374: jal         0x800A469C
    // 0x800A1378: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_bananas(rdram, ctx);
        goto after_5;
    // 0x800A1378: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800A137C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A1380: jal         0x800A80C4
    // 0x800A1384: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_time(rdram, ctx);
        goto after_6;
    // 0x800A1384: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800A1388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A138C: jal         0x800A518C
    // 0x800A1390: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_position(rdram, ctx);
        goto after_7;
    // 0x800A1390: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800A1394: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A1398: jal         0x800A3DCC
    // 0x800A139C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_speedometre(rdram, ctx);
        goto after_8;
    // 0x800A139C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800A13A0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A13A4: lbu         $t9, 0x7748($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7748);
    // 0x800A13A8: nop

    // 0x800A13AC: beq         $t9, $zero, L_800A13D0
    if (ctx->r25 == 0) {
        // 0x800A13B0: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_800A13D0;
    }
    // 0x800A13B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A13B4: lb          $t0, 0x1D8($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X1D8);
    // 0x800A13B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A13BC: bne         $t0, $zero, L_800A13CC
    if (ctx->r8 != 0) {
        // 0x800A13C0: nop
    
            goto L_800A13CC;
    }
    // 0x800A13C0: nop

    // 0x800A13C4: jal         0x800A4CE8
    // 0x800A13C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_silver_coins(rdram, ctx);
        goto after_9;
    // 0x800A13C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
L_800A13CC:
    // 0x800A13CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_800A13D0:
    // 0x800A13D0: jal         0x800A7A7C
    // 0x800A13D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_weapon(rdram, ctx);
        goto after_10;
    // 0x800A13D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x800A13D8: jal         0x80068748
    // 0x800A13DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_11;
    // 0x800A13DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x800A13E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A13E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A13E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A13EC: jr          $ra
    // 0x800A13F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A13F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void hud_course_arrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A13F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A13F8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A13FC: lbu         $t6, 0x2D10($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2D10);
    // 0x800A1400: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A1404: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A1408: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A140C: beq         $t6, $zero, L_800A1778
    if (ctx->r14 == 0) {
        // 0x800A1410: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800A1778;
    }
    // 0x800A1410: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A1414: lb          $v0, 0x1F9($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1F9);
    // 0x800A1418: nop

    // 0x800A141C: blez        $v0, L_800A1634
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A1420: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800A1634;
    }
    // 0x800A1420: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800A1424: lbu         $v1, 0x1F8($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1F8);
    // 0x800A1428: subu        $t9, $v0, $a1
    ctx->r25 = SUB32(ctx->r2, ctx->r5);
    // 0x800A142C: beq         $v1, $zero, L_800A161C
    if (ctx->r3 == 0) {
        // 0x800A1430: sb          $t9, 0x1F9($a0)
        MEM_B(0X1F9, ctx->r4) = ctx->r25;
            goto L_800A161C;
    }
    // 0x800A1430: sb          $t9, 0x1F9($a0)
    MEM_B(0X1F9, ctx->r4) = ctx->r25;
    // 0x800A1434: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A1438: lw          $s0, 0x729C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X729C);
    // 0x800A143C: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x800A1440: sltiu       $at, $t1, 0x8
    ctx->r1 = ctx->r9 < 0X8 ? 1 : 0;
    // 0x800A1444: beq         $at, $zero, L_800A14FC
    if (ctx->r1 == 0) {
        // 0x800A1448: addiu       $s0, $s0, 0x420
        ctx->r16 = ADD32(ctx->r16, 0X420);
            goto L_800A14FC;
    }
    // 0x800A1448: addiu       $s0, $s0, 0x420
    ctx->r16 = ADD32(ctx->r16, 0X420);
    // 0x800A144C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800A1450: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A1454: addu        $at, $at, $t1
    gpr jr_addend_800A1460 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800A1458: lw          $t1, -0x7388($at)
    ctx->r9 = ADD32(ctx->r1, -0X7388);
    // 0x800A145C: nop

    // 0x800A1460: jr          $t1
    // 0x800A1464: nop

    switch (jr_addend_800A1460 >> 2) {
        case 0: goto L_800A1468; break;
        case 1: goto L_800A1478; break;
        case 2: goto L_800A1488; break;
        case 3: goto L_800A1498; break;
        case 4: goto L_800A14AC; break;
        case 5: goto L_800A14C0; break;
        case 6: goto L_800A14D4; break;
        case 7: goto L_800A14EC; break;
        default: switch_error(__func__, 0x800A1460, 0x800E8C78);
    }
    // 0x800A1464: nop

L_800A1468:
    // 0x800A1468: addiu       $t2, $zero, 0x21
    ctx->r10 = ADD32(0, 0X21);
    // 0x800A146C: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x800A1470: b           L_800A1508
    // 0x800A1474: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_800A1508;
    // 0x800A1474: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A1478:
    // 0x800A1478: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800A147C: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
    // 0x800A1480: b           L_800A1508
    // 0x800A1484: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_800A1508;
    // 0x800A1484: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A1488:
    // 0x800A1488: addiu       $t4, $zero, 0x1F
    ctx->r12 = ADD32(0, 0X1F);
    // 0x800A148C: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x800A1490: b           L_800A1508
    // 0x800A1494: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_800A1508;
    // 0x800A1494: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A1498:
    // 0x800A1498: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800A149C: addiu       $t5, $zero, 0x21
    ctx->r13 = ADD32(0, 0X21);
    // 0x800A14A0: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    // 0x800A14A4: b           L_800A1508
    // 0x800A14A8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_800A1508;
    // 0x800A14A8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800A14AC:
    // 0x800A14AC: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800A14B0: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800A14B4: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
    // 0x800A14B8: b           L_800A1508
    // 0x800A14BC: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_800A1508;
    // 0x800A14BC: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800A14C0:
    // 0x800A14C0: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800A14C4: addiu       $t8, $zero, 0x1F
    ctx->r24 = ADD32(0, 0X1F);
    // 0x800A14C8: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
    // 0x800A14CC: b           L_800A1508
    // 0x800A14D0: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_800A1508;
    // 0x800A14D0: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800A14D4:
    // 0x800A14D4: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800A14D8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x800A14DC: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x800A14E0: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x800A14E4: b           L_800A1508
    // 0x800A14E8: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
        goto L_800A1508;
    // 0x800A14E8: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
L_800A14EC:
    // 0x800A14EC: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x800A14F0: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x800A14F4: b           L_800A1508
    // 0x800A14F8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_800A1508;
    // 0x800A14F8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A14FC:
    // 0x800A14FC: addiu       $t1, $zero, 0x1D
    ctx->r9 = ADD32(0, 0X1D);
    // 0x800A1500: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
    // 0x800A1504: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A1508:
    // 0x800A1508: jal         0x8009C850
    // 0x800A150C: nop

    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x800A150C: nop

    after_0:
    // 0x800A1510: andi        $t2, $v0, 0x4
    ctx->r10 = ctx->r2 & 0X4;
    // 0x800A1514: beq         $t2, $zero, L_800A1548
    if (ctx->r10 == 0) {
        // 0x800A1518: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800A1548;
    }
    // 0x800A1518: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A151C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A1520: nop

    // 0x800A1524: lbu         $t3, 0x1F8($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X1F8);
    // 0x800A1528: nop

    // 0x800A152C: slti        $at, $t3, 0x1E
    ctx->r1 = SIGNED(ctx->r11) < 0X1E ? 1 : 0;
    // 0x800A1530: beq         $at, $zero, L_800A1548
    if (ctx->r1 == 0) {
        // 0x800A1534: nop
    
            goto L_800A1548;
    }
    // 0x800A1534: nop

    // 0x800A1538: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x800A153C: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x800A1540: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x800A1544: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
L_800A1548:
    // 0x800A1548: lw          $t8, 0x72CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72CC);
    // 0x800A154C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A1550: bne         $t8, $zero, L_800A161C
    if (ctx->r24 != 0) {
        // 0x800A1554: nop
    
            goto L_800A161C;
    }
    // 0x800A1554: nop

    // 0x800A1558: lb          $t9, 0x1D8($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1D8);
    // 0x800A155C: nop

    // 0x800A1560: bne         $t9, $zero, L_800A161C
    if (ctx->r25 != 0) {
        // 0x800A1564: nop
    
            goto L_800A161C;
    }
    // 0x800A1564: nop

    // 0x800A1568: lbu         $t7, 0x1F8($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X1F8);
    // 0x800A156C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800A1570: beq         $t7, $zero, L_800A161C
    if (ctx->r15 == 0) {
        // 0x800A1574: nop
    
            goto L_800A161C;
    }
    // 0x800A1574: nop

    // 0x800A1578: lbu         $t1, 0x2D38($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2D38);
    // 0x800A157C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A1580: bne         $t1, $zero, L_800A161C
    if (ctx->r9 != 0) {
        // 0x800A1584: addiu       $a0, $a0, 0x72BC
        ctx->r4 = ADD32(ctx->r4, 0X72BC);
            goto L_800A161C;
    }
    // 0x800A1584: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A1588: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A158C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A1590: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800A1594: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800A1598: addiu       $t5, $zero, -0x60
    ctx->r13 = ADD32(0, -0X60);
    // 0x800A159C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A15A0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A15A4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A15A8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A15AC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800A15B0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800A15B4: jal         0x800AAB5C
    // 0x800A15B8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A15B8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    after_1:
    // 0x800A15BC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A15C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A15C4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A15C8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A15CC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A15D0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800A15D4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A15D8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A15DC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A15E0: jal         0x800AAB5C
    // 0x800A15E4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A15E4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x800A15E8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A15EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A15F0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800A15F4: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
    // 0x800A15F8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x800A15FC: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800A1600: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A1604: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A1608: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800A160C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800A1610: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800A1614: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800A1618: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800A161C:
    // 0x800A161C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A1620: lbu         $v0, 0x2D38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2D38);
    // 0x800A1624: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A1628: b           L_800A1648
    // 0x800A162C: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
        goto L_800A1648;
    // 0x800A162C: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
    // 0x800A1630: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
L_800A1634:
    // 0x800A1634: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A1638: sb          $zero, 0x1F9($t9)
    MEM_B(0X1F9, ctx->r25) = 0;
    // 0x800A163C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A1640: lbu         $v0, 0x2D38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2D38);
    // 0x800A1644: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
L_800A1648:
    // 0x800A1648: beq         $v0, $zero, L_800A1778
    if (ctx->r2 == 0) {
        // 0x800A164C: andi        $t7, $v0, 0x20
        ctx->r15 = ctx->r2 & 0X20;
            goto L_800A1778;
    }
    // 0x800A164C: andi        $t7, $v0, 0x20
    ctx->r15 = ctx->r2 & 0X20;
    // 0x800A1650: beq         $t7, $zero, L_800A1750
    if (ctx->r15 == 0) {
        // 0x800A1654: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A1750;
    }
    // 0x800A1654: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A1658: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A165C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800A1660: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800A1664: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x800A1668: addiu       $t3, $zero, -0x60
    ctx->r11 = ADD32(0, -0X60);
    // 0x800A166C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A1670: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800A1674: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800A1678: lw          $s0, 0x729C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X729C);
    // 0x800A167C: addiu       $t5, $zero, 0x1D
    ctx->r13 = ADD32(0, 0X1D);
    // 0x800A1680: addiu       $s0, $s0, 0x420
    ctx->r16 = ADD32(ctx->r16, 0X420);
    // 0x800A1684: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x800A1688: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800A168C: jal         0x8009C850
    // 0x800A1690: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    get_filtered_cheats(rdram, ctx);
        goto after_3;
    // 0x800A1690: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    after_3:
    // 0x800A1694: andi        $t4, $v0, 0x4
    ctx->r12 = ctx->r2 & 0X4;
    // 0x800A1698: beq         $t4, $zero, L_800A16CC
    if (ctx->r12 == 0) {
        // 0x800A169C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A16CC;
    }
    // 0x800A169C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A16A0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A16A4: nop

    // 0x800A16A8: lbu         $t8, 0x1F8($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1F8);
    // 0x800A16AC: nop

    // 0x800A16B0: slti        $at, $t8, 0x1E
    ctx->r1 = SIGNED(ctx->r24) < 0X1E ? 1 : 0;
    // 0x800A16B4: beq         $at, $zero, L_800A16CC
    if (ctx->r1 == 0) {
        // 0x800A16B8: nop
    
            goto L_800A16CC;
    }
    // 0x800A16B8: nop

    // 0x800A16BC: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x800A16C0: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x800A16C4: subu        $t1, $t7, $t9
    ctx->r9 = SUB32(ctx->r15, ctx->r25);
    // 0x800A16C8: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
L_800A16CC:
    // 0x800A16CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A16D0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A16D4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A16D8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A16DC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A16E0: jal         0x800AAB5C
    // 0x800A16E4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A16E4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x800A16E8: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A16EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A16F0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A16F4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A16F8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800A16FC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x800A1700: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A1704: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A1708: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A170C: jal         0x800AAB5C
    // 0x800A1710: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A1710: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_5:
    // 0x800A1714: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A1718: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A171C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A1720: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800A1724: lw          $v0, 0x72BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72BC);
    // 0x800A1728: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A172C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800A1730: sw          $t2, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = ctx->r10;
    // 0x800A1734: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A1738: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A173C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1740: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800A1744: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800A1748: lbu         $a0, 0x2D38($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2D38);
    // 0x800A174C: nop

L_800A1750:
    // 0x800A1750: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800A1754: nop

    // 0x800A1758: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A175C: beq         $at, $zero, L_800A1770
    if (ctx->r1 == 0) {
        // 0x800A1760: subu        $t6, $a0, $t4
        ctx->r14 = SUB32(ctx->r4, ctx->r12);
            goto L_800A1770;
    }
    // 0x800A1760: subu        $t6, $a0, $t4
    ctx->r14 = SUB32(ctx->r4, ctx->r12);
    // 0x800A1764: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A1768: b           L_800A1778
    // 0x800A176C: sb          $t6, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = ctx->r14;
        goto L_800A1778;
    // 0x800A176C: sb          $t6, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = ctx->r14;
L_800A1770:
    // 0x800A1770: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A1774: sb          $zero, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = 0;
L_800A1778:
    // 0x800A1778: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A177C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A1780: jr          $ra
    // 0x800A1784: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A1784: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void hud_main_treasure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1788: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800A178C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A1790: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800A1794: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800A1798: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800A179C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800A17A0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A17A4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800A17A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800A17AC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800A17B0: lw          $a3, 0x64($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X64);
    // 0x800A17B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A17B8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800A17BC: jal         0x8001BAA8
    // 0x800A17C0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800A17C0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A17C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800A17C8: jal         0x80068748
    // 0x800A17CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800A17CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800A17D0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800A17D4: jal         0x800A422C
    // 0x800A17D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    hud_race_start(rdram, ctx);
        goto after_2;
    // 0x800A17D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A17DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A17E0: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A17E4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800A17E8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800A17EC: beq         $v0, $s3, L_800A180C
    if (ctx->r2 == ctx->r19) {
        // 0x800A17F0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A180C;
    }
    // 0x800A17F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A17F4: beq         $v0, $at, L_800A18FC
    if (ctx->r2 == ctx->r1) {
        // 0x800A17F8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A18FC;
    }
    // 0x800A17F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A17FC: beq         $v0, $at, L_800A18FC
    if (ctx->r2 == ctx->r1) {
        // 0x800A1800: nop
    
            goto L_800A18FC;
    }
    // 0x800A1800: nop

    // 0x800A1804: b           L_800A1908
    // 0x800A1808: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
        goto L_800A1908;
    // 0x800A1808: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
L_800A180C:
    // 0x800A180C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1810: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A1814: blez        $t7, L_800A18BC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A1818: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800A18BC;
    }
    // 0x800A1818: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800A181C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800A1820: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A1824: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A1828: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
L_800A182C:
    // 0x800A182C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A1830: nop

    // 0x800A1834: lw          $a0, 0x64($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X64);
    // 0x800A1838: jal         0x800A4B38
    // 0x800A183C: nop

    hud_treasure(rdram, ctx);
        goto after_3;
    // 0x800A183C: nop

    after_3:
    // 0x800A1840: bne         $s1, $s3, L_800A1878
    if (ctx->r17 != ctx->r19) {
        // 0x800A1844: nop
    
            goto L_800A1878;
    }
    // 0x800A1844: nop

    // 0x800A1848: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A184C: nop

    // 0x800A1850: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1854: nop

    // 0x800A1858: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800A185C: swc1        $f6, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f6.u32l;
    // 0x800A1860: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A1864: nop

    // 0x800A1868: lwc1        $f8, 0x40C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A186C: nop

    // 0x800A1870: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A1874: swc1        $f10, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f10.u32l;
L_800A1878:
    // 0x800A1878: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A187C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A1880: lwc1        $f16, 0x64C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1884: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A1888: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x800A188C: swc1        $f18, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f18.u32l;
    // 0x800A1890: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A1894: nop

    // 0x800A1898: lwc1        $f4, 0x40C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A189C: nop

    // 0x800A18A0: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800A18A4: swc1        $f6, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f6.u32l;
    // 0x800A18A8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800A18AC: nop

    // 0x800A18B0: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A18B4: bne         $at, $zero, L_800A182C
    if (ctx->r1 != 0) {
        // 0x800A18B8: nop
    
            goto L_800A182C;
    }
    // 0x800A18B8: nop

L_800A18BC:
    // 0x800A18BC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A18C0: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A18C4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A18C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A18CC: lwc1        $f0, -0x7368($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7368);
    // 0x800A18D0: lwc1        $f8, 0x64C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A18D4: nop

    // 0x800A18D8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A18DC: swc1        $f10, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f10.u32l;
    // 0x800A18E0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A18E4: nop

    // 0x800A18E8: lwc1        $f16, 0x40C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A18EC: nop

    // 0x800A18F0: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800A18F4: b           L_800A1904
    // 0x800A18F8: swc1        $f18, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f18.u32l;
        goto L_800A1904;
    // 0x800A18F8: swc1        $f18, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f18.u32l;
L_800A18FC:
    // 0x800A18FC: jal         0x800A4B38
    // 0x800A1900: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_treasure(rdram, ctx);
        goto after_4;
    // 0x800A1900: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
L_800A1904:
    // 0x800A1904: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
L_800A1908:
    // 0x800A1908: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A190C: lw          $a3, 0x64($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X64);
    // 0x800A1910: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A1914: jal         0x8007B820
    // 0x800A1918: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x800A1918: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_5:
    // 0x800A191C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800A1920: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800A1924: jal         0x800A469C
    // 0x800A1928: nop

    hud_bananas(rdram, ctx);
        goto after_6;
    // 0x800A1928: nop

    after_6:
    // 0x800A192C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800A1930: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800A1934: jal         0x800A7A7C
    // 0x800A1938: nop

    hud_weapon(rdram, ctx);
        goto after_7;
    // 0x800A1938: nop

    after_7:
    // 0x800A193C: jal         0x80068748
    // 0x800A1940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_8;
    // 0x800A1940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800A1944: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A1948: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800A194C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A1950: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800A1954: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800A1958: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800A195C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800A1960: jr          $ra
    // 0x800A1964: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800A1964: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void hud_main_eggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A196C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1970: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A1974: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A1978: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A197C: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x800A1980: nop

    // 0x800A1984: lb          $t7, 0x1D8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1D8);
    // 0x800A1988: nop

    // 0x800A198C: bne         $t7, $zero, L_800A1A24
    if (ctx->r15 != 0) {
        // 0x800A1990: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A1A24;
    }
    // 0x800A1990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A1994: jal         0x80068748
    // 0x800A1998: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A1998: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A199C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A19A0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A19A4: jal         0x800A422C
    // 0x800A19A8: nop

    hud_race_start(rdram, ctx);
        goto after_1;
    // 0x800A19A8: nop

    after_1:
    // 0x800A19AC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A19B0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A19B4: jal         0x800A7A7C
    // 0x800A19B8: nop

    hud_weapon(rdram, ctx);
        goto after_2;
    // 0x800A19B8: nop

    after_2:
    // 0x800A19BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A19C0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A19C4: lw          $v1, 0x729C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X729C);
    // 0x800A19C8: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x800A19CC: lb          $a0, 0x67A($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X67A);
    // 0x800A19D0: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800A19D4: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x800A19D8: slt         $at, $t9, $a0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A19DC: bne         $at, $zero, L_800A19F0
    if (ctx->r1 != 0) {
        // 0x800A19E0: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800A19F0;
    }
    // 0x800A19E0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A19E4: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
    // 0x800A19E8: b           L_800A19FC
    // 0x800A19EC: sb          $t0, 0x67A($v1)
    MEM_B(0X67A, ctx->r3) = ctx->r8;
        goto L_800A19FC;
    // 0x800A19EC: sb          $t0, 0x67A($v1)
    MEM_B(0X67A, ctx->r3) = ctx->r8;
L_800A19F0:
    // 0x800A19F0: addu        $t1, $a0, $v0
    ctx->r9 = ADD32(ctx->r4, ctx->r2);
    // 0x800A19F4: addiu       $t2, $t1, -0xFF
    ctx->r10 = ADD32(ctx->r9, -0XFF);
    // 0x800A19F8: sb          $t2, 0x67A($v1)
    MEM_B(0X67A, ctx->r3) = ctx->r10;
L_800A19FC:
    // 0x800A19FC: lbu         $t3, 0x72F7($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X72F7);
    // 0x800A1A00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A1A04: beq         $t3, $at, L_800A1A18
    if (ctx->r11 == ctx->r1) {
        // 0x800A1A08: nop
    
            goto L_800A1A18;
    }
    // 0x800A1A08: nop

    // 0x800A1A0C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A1A10: jal         0x800A1A30
    // 0x800A1A14: nop

    hud_draw_eggs(rdram, ctx);
        goto after_3;
    // 0x800A1A14: nop

    after_3:
L_800A1A18:
    // 0x800A1A18: jal         0x80068748
    // 0x800A1A1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_4;
    // 0x800A1A1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800A1A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1A24:
    // 0x800A1A24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A1A28: jr          $ra
    // 0x800A1A2C: nop

    return;
    // 0x800A1A2C: nop

;}
RECOMP_FUNC void hud_draw_eggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1A30: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A1A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1A38: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800A1A3C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800A1A40: jal         0x8001BAA8
    // 0x800A1A44: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800A1A44: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x800A1A48: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A1A4C: lbu         $t6, 0x72F7($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X72F7);
    // 0x800A1A50: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800A1A54: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800A1A58: bne         $t4, $t6, L_800A1BCC
    if (ctx->r12 != ctx->r14) {
        // 0x800A1A5C: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800A1BCC;
    }
    // 0x800A1A5C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800A1A60: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A1A64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A1A68: blez        $t7, L_800A1BC4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A1A6C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800A1BC4;
    }
    // 0x800A1A6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A1A70: andi        $v1, $t7, 0x3
    ctx->r3 = ctx->r15 & 0X3;
    // 0x800A1A74: beq         $v1, $zero, L_800A1AD4
    if (ctx->r3 == 0) {
        // 0x800A1A78: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_800A1AD4;
    }
    // 0x800A1A78: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800A1A7C: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x800A1A80: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    // 0x800A1A84: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A1A88:
    // 0x800A1A88: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A1A8C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800A1A90: lw          $v1, 0x64($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X64);
    // 0x800A1A94: nop

    // 0x800A1A98: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A1A9C: nop

    // 0x800A1AA0: beq         $t0, $t5, L_800A1ABC
    if (ctx->r8 == ctx->r13) {
        // 0x800A1AA4: nop
    
            goto L_800A1ABC;
    }
    // 0x800A1AA4: nop

    // 0x800A1AA8: lb          $t6, 0x1D8($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1D8);
    // 0x800A1AAC: nop

    // 0x800A1AB0: beq         $t6, $zero, L_800A1ABC
    if (ctx->r14 == 0) {
        // 0x800A1AB4: nop
    
            goto L_800A1ABC;
    }
    // 0x800A1AB4: nop

    // 0x800A1AB8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A1ABC:
    // 0x800A1ABC: bne         $t1, $a3, L_800A1A88
    if (ctx->r9 != ctx->r7) {
        // 0x800A1AC0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800A1A88;
    }
    // 0x800A1AC0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800A1AC4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A1AC8: nop

    // 0x800A1ACC: beq         $a3, $t7, L_800A1BC4
    if (ctx->r7 == ctx->r15) {
        // 0x800A1AD0: nop
    
            goto L_800A1BC4;
    }
    // 0x800A1AD0: nop

L_800A1AD4:
    // 0x800A1AD4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800A1AD8: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x800A1ADC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A1AE0: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800A1AE4: addu        $a1, $v0, $t5
    ctx->r5 = ADD32(ctx->r2, ctx->r13);
    // 0x800A1AE8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A1AEC:
    // 0x800A1AEC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A1AF0: nop

    // 0x800A1AF4: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x800A1AF8: nop

    // 0x800A1AFC: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800A1B00: nop

    // 0x800A1B04: beq         $t0, $t7, L_800A1B20
    if (ctx->r8 == ctx->r15) {
        // 0x800A1B08: nop
    
            goto L_800A1B20;
    }
    // 0x800A1B08: nop

    // 0x800A1B0C: lb          $t8, 0x1D8($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X1D8);
    // 0x800A1B10: nop

    // 0x800A1B14: beq         $t8, $zero, L_800A1B20
    if (ctx->r24 == 0) {
        // 0x800A1B18: nop
    
            goto L_800A1B20;
    }
    // 0x800A1B18: nop

    // 0x800A1B1C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A1B20:
    // 0x800A1B20: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800A1B24: nop

    // 0x800A1B28: lw          $a0, 0x64($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X64);
    // 0x800A1B2C: nop

    // 0x800A1B30: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x800A1B34: nop

    // 0x800A1B38: beq         $t0, $t5, L_800A1B54
    if (ctx->r8 == ctx->r13) {
        // 0x800A1B3C: nop
    
            goto L_800A1B54;
    }
    // 0x800A1B3C: nop

    // 0x800A1B40: lb          $t6, 0x1D8($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A1B44: nop

    // 0x800A1B48: beq         $t6, $zero, L_800A1B54
    if (ctx->r14 == 0) {
        // 0x800A1B4C: nop
    
            goto L_800A1B54;
    }
    // 0x800A1B4C: nop

    // 0x800A1B50: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A1B54:
    // 0x800A1B54: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800A1B58: nop

    // 0x800A1B5C: lw          $a0, 0x64($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X64);
    // 0x800A1B60: nop

    // 0x800A1B64: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x800A1B68: nop

    // 0x800A1B6C: beq         $t0, $t8, L_800A1B88
    if (ctx->r8 == ctx->r24) {
        // 0x800A1B70: nop
    
            goto L_800A1B88;
    }
    // 0x800A1B70: nop

    // 0x800A1B74: lb          $t9, 0x1D8($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A1B78: nop

    // 0x800A1B7C: beq         $t9, $zero, L_800A1B88
    if (ctx->r25 == 0) {
        // 0x800A1B80: nop
    
            goto L_800A1B88;
    }
    // 0x800A1B80: nop

    // 0x800A1B84: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A1B88:
    // 0x800A1B88: lw          $t5, 0xC($a1)
    ctx->r13 = MEM_W(ctx->r5, 0XC);
    // 0x800A1B8C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800A1B90: lw          $a0, 0x64($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X64);
    // 0x800A1B94: nop

    // 0x800A1B98: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800A1B9C: nop

    // 0x800A1BA0: beq         $t0, $t6, L_800A1BBC
    if (ctx->r8 == ctx->r14) {
        // 0x800A1BA4: nop
    
            goto L_800A1BBC;
    }
    // 0x800A1BA4: nop

    // 0x800A1BA8: lb          $t7, 0x1D8($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A1BAC: nop

    // 0x800A1BB0: beq         $t7, $zero, L_800A1BBC
    if (ctx->r15 == 0) {
        // 0x800A1BB4: nop
    
            goto L_800A1BBC;
    }
    // 0x800A1BB4: nop

    // 0x800A1BB8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A1BBC:
    // 0x800A1BBC: bne         $a1, $t1, L_800A1AEC
    if (ctx->r5 != ctx->r9) {
        // 0x800A1BC0: nop
    
            goto L_800A1AEC;
    }
    // 0x800A1BC0: nop

L_800A1BC4:
    // 0x800A1BC4: beq         $a2, $t4, L_800A1ED8
    if (ctx->r6 == ctx->r12) {
        // 0x800A1BC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A1ED8;
    }
    // 0x800A1BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1BCC:
    // 0x800A1BCC: beq         $t3, $zero, L_800A1BE0
    if (ctx->r11 == 0) {
        // 0x800A1BD0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A1BE0;
    }
    // 0x800A1BD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A1BD4: lw          $t1, 0x64($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X64);
    // 0x800A1BD8: b           L_800A1BF4
    // 0x800A1BDC: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
        goto L_800A1BF4;
    // 0x800A1BDC: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
L_800A1BE0:
    // 0x800A1BE0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800A1BE4: nop

    // 0x800A1BE8: lw          $t1, 0x64($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X64);
    // 0x800A1BEC: nop

    // 0x800A1BF0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
L_800A1BF4:
    // 0x800A1BF4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A1BF8: bne         $t9, $at, L_800A1ED4
    if (ctx->r25 != ctx->r1) {
        // 0x800A1BFC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800A1ED4;
    }
    // 0x800A1BFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A1C00: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800A1C04: jal         0x80068748
    // 0x800A1C08: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800A1C08: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    after_1:
    // 0x800A1C0C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A1C10: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A1C14: addiu       $a2, $a2, 0x729C
    ctx->r6 = ADD32(ctx->r6, 0X729C);
    // 0x800A1C18: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1C1C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A1C20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1C24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1C28: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1C2C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800A1C30: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1C34: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800A1C38: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A1C3C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800A1C40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A1C44: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A1C48: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800A1C4C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A1C50: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1C54: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1C58: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A1C5C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800A1C60: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A1C64: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A1C68: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A1C6C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800A1C70: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A1C74: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x800A1C78: lwc1        $f18, 0x66C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A1C7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1C80: sub.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x800A1C84: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A1C88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1C8C: nop

    // 0x800A1C90: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1C94: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A1C98: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800A1C9C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A1CA0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800A1CA4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800A1CA8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800A1CAC: lwc1        $f16, 0x670($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A1CB0: nop

    // 0x800A1CB4: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800A1CB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A1CBC: nop

    // 0x800A1CC0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A1CC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1CC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1CCC: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800A1CD0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A1CD4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A1CD8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A1CDC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800A1CE0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A1CE4: lwc1        $f1, -0x7360($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7360);
    // 0x800A1CE8: lwc1        $f0, -0x735C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X735C);
    // 0x800A1CEC: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800A1CF0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
L_800A1CF4:
    // 0x800A1CF4: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A1CF8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1CFC: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A1D00: lw          $v0, 0x64($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X64);
    // 0x800A1D04: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A1D08: bne         $at, $zero, L_800A1D24
    if (ctx->r1 != 0) {
        // 0x800A1D0C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A1D24;
    }
    // 0x800A1D0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A1D10: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800A1D14: lh          $t8, 0x0($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X0);
    // 0x800A1D18: nop

    // 0x800A1D1C: bne         $t7, $t8, L_800A1D7C
    if (ctx->r15 != ctx->r24) {
        // 0x800A1D20: addiu       $t9, $zero, -0x2
        ctx->r25 = ADD32(0, -0X2);
            goto L_800A1D7C;
    }
    // 0x800A1D20: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
L_800A1D24:
    // 0x800A1D24: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800A1D28: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800A1D2C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A1D30: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800A1D34: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800A1D38: jal         0x800A1EE4
    // 0x800A1D3C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    hud_eggs_portrait(rdram, ctx);
        goto after_2;
    // 0x800A1D3C: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x800A1D40: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A1D44: lwc1        $f1, -0x7358($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7358);
    // 0x800A1D48: lwc1        $f0, -0x7354($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7354);
    // 0x800A1D4C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800A1D50: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1D54: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A1D58: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A1D5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A1D60: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A1D64: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800A1D68: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800A1D6C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A1D70: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A1D74: addiu       $a2, $a2, 0x729C
    ctx->r6 = ADD32(ctx->r6, 0X729C);
    // 0x800A1D78: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
L_800A1D7C:
    // 0x800A1D7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A1D80: sw          $t9, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r25;
    // 0x800A1D84: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1D88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A1D8C: bne         $v1, $at, L_800A1DB8
    if (ctx->r3 != ctx->r1) {
        // 0x800A1D90: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800A1DB8;
    }
    // 0x800A1D90: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800A1D94: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
    // 0x800A1D98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A1D9C: lwc1        $f8, 0x64C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1DA0: nop

    // 0x800A1DA4: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800A1DA8: swc1        $f10, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f10.u32l;
    // 0x800A1DAC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1DB0: b           L_800A1E60
    // 0x800A1DB4: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
        goto L_800A1E60;
    // 0x800A1DB4: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
L_800A1DB8:
    // 0x800A1DB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A1DBC: bne         $v1, $at, L_800A1E5C
    if (ctx->r3 != ctx->r1) {
        // 0x800A1DC0: lui         $t6, 0x8000
        ctx->r14 = S32(0X8000 << 16);
            goto L_800A1E5C;
    }
    // 0x800A1DC0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A1DC4: swc1        $f14, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f14.u32l;
    // 0x800A1DC8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A1DCC: nop

    // 0x800A1DD0: bne         $t6, $zero, L_800A1E24
    if (ctx->r14 != 0) {
        // 0x800A1DD4: nop
    
            goto L_800A1E24;
    }
    // 0x800A1DD4: nop

    // 0x800A1DD8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1DDC: nop

    // 0x800A1DE0: lwc1        $f18, 0x650($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A1DE4: nop

    // 0x800A1DE8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800A1DEC: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x800A1DF0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800A1DF4: swc1        $f8, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f8.u32l;
    // 0x800A1DF8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1DFC: nop

    // 0x800A1E00: lwc1        $f16, 0x670($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A1E04: nop

    // 0x800A1E08: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800A1E0C: add.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f10.d + ctx->f0.d;
    // 0x800A1E10: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800A1E14: swc1        $f4, 0x670($v0)
    MEM_W(0X670, ctx->r2) = ctx->f4.u32l;
    // 0x800A1E18: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1E1C: b           L_800A1E60
    // 0x800A1E20: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
        goto L_800A1E60;
    // 0x800A1E20: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
L_800A1E24:
    // 0x800A1E24: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1E28: nop

    // 0x800A1E2C: lwc1        $f6, 0x650($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A1E30: nop

    // 0x800A1E34: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800A1E38: swc1        $f8, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f8.u32l;
    // 0x800A1E3C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1E40: nop

    // 0x800A1E44: lwc1        $f16, 0x670($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A1E48: nop

    // 0x800A1E4C: add.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A1E50: swc1        $f10, 0x670($v0)
    MEM_W(0X670, ctx->r2) = ctx->f10.u32l;
    // 0x800A1E54: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1E58: nop

L_800A1E5C:
    // 0x800A1E5C: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
L_800A1E60:
    // 0x800A1E60: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800A1E64: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x800A1E68: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800A1E6C: bne         $a3, $at, L_800A1CF4
    if (ctx->r7 != ctx->r1) {
        // 0x800A1E70: swc1        $f4, 0x66C($v0)
        MEM_W(0X66C, ctx->r2) = ctx->f4.u32l;
            goto L_800A1CF4;
    }
    // 0x800A1E70: swc1        $f4, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f4.u32l;
    // 0x800A1E74: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800A1E78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A1E7C: swc1        $f14, 0x64C($t5)
    MEM_W(0X64C, ctx->r13) = ctx->f14.u32l;
    // 0x800A1E80: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800A1E84: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A1E88: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800A1E8C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A1E90: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800A1E94: nop

    // 0x800A1E98: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A1E9C: swc1        $f8, 0x66C($t6)
    MEM_W(0X66C, ctx->r14) = ctx->f8.u32l;
    // 0x800A1EA0: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800A1EA4: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A1EA8: nop

    // 0x800A1EAC: swc1        $f16, 0x650($t5)
    MEM_W(0X650, ctx->r13) = ctx->f16.u32l;
    // 0x800A1EB0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800A1EB4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1EB8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800A1EBC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A1EC0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800A1EC4: nop

    // 0x800A1EC8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A1ECC: jal         0x80068748
    // 0x800A1ED0: swc1        $f18, 0x670($t6)
    MEM_W(0X670, ctx->r14) = ctx->f18.u32l;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_3;
    // 0x800A1ED0: swc1        $f18, 0x670($t6)
    MEM_W(0X670, ctx->r14) = ctx->f18.u32l;
    after_3:
L_800A1ED4:
    // 0x800A1ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1ED8:
    // 0x800A1ED8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800A1EDC: jr          $ra
    // 0x800A1EE0: nop

    return;
    // 0x800A1EE0: nop

;}
RECOMP_FUNC void hud_eggs_portrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1EE4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A1EE8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A1EEC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A1EF0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A1EF4: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A1EF8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A1EFC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A1F00: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A1F04: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800A1F08: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800A1F0C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800A1F10: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800A1F14: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A1F18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A1F1C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A1F20: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A1F24: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800A1F28: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1F2C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1F30: lwc1        $f4, 0x66C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A1F34: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1F38: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1F3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A1F40: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A1F44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A1F48: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x800A1F4C: lb          $t8, 0x3($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X3);
    // 0x800A1F50: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A1F54: addiu       $t9, $t8, 0x38
    ctx->r25 = ADD32(ctx->r24, 0X38);
    // 0x800A1F58: sh          $t9, 0x646($v0)
    MEM_H(0X646, ctx->r2) = ctx->r25;
    // 0x800A1F5C: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A1F60: sb          $t0, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = ctx->r8;
    // 0x800A1F64: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A1F68: bne         $at, $zero, L_800A1F8C
    if (ctx->r1 != 0) {
        // 0x800A1F6C: or          $s3, $a0, $zero
        ctx->r19 = ctx->r4 | 0;
            goto L_800A1F8C;
    }
    // 0x800A1F6C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800A1F70: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800A1F74: bne         $s1, $v1, L_800A1FB4
    if (ctx->r17 != ctx->r3) {
        // 0x800A1F78: nop
    
            goto L_800A1FB4;
    }
    // 0x800A1F78: nop

    // 0x800A1F7C: lh          $t1, 0x0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X0);
    // 0x800A1F80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A1F84: bne         $t1, $at, L_800A1FB4
    if (ctx->r9 != ctx->r1) {
        // 0x800A1F88: nop
    
            goto L_800A1FB4;
    }
    // 0x800A1F88: nop

L_800A1F8C:
    // 0x800A1F8C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A1F90: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A1F94: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800A1F98: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800A1F9C: addiu       $a2, $s6, 0x72C4
    ctx->r6 = ADD32(ctx->r22, 0X72C4);
    // 0x800A1FA0: addiu       $a1, $s5, 0x72C0
    ctx->r5 = ADD32(ctx->r21, 0X72C0);
    // 0x800A1FA4: addiu       $a0, $s4, 0x72BC
    ctx->r4 = ADD32(ctx->r20, 0X72BC);
    // 0x800A1FA8: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800A1FAC: jal         0x800AAB5C
    // 0x800A1FB0: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A1FB0: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    after_0:
L_800A1FB4:
    // 0x800A1FB4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A1FB8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A1FBC: lb          $v0, 0x67A($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X67A);
    // 0x800A1FC0: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800A1FC4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800A1FC8: addiu       $s6, $s6, 0x72C4
    ctx->r22 = ADD32(ctx->r22, 0X72C4);
    // 0x800A1FCC: addiu       $s5, $s5, 0x72C0
    ctx->r21 = ADD32(ctx->r21, 0X72C0);
    // 0x800A1FD0: bgez        $v0, L_800A1FE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A1FD4: addiu       $s4, $s4, 0x72BC
        ctx->r20 = ADD32(ctx->r20, 0X72BC);
            goto L_800A1FE8;
    }
    // 0x800A1FD4: addiu       $s4, $s4, 0x72BC
    ctx->r20 = ADD32(ctx->r20, 0X72BC);
    // 0x800A1FD8: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x800A1FDC: addiu       $t4, $t3, 0x100
    ctx->r12 = ADD32(ctx->r11, 0X100);
    // 0x800A1FE0: b           L_800A1FF8
    // 0x800A1FE4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_800A1FF8;
    // 0x800A1FE4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_800A1FE8:
    // 0x800A1FE8: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x800A1FEC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A1FF0: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x800A1FF4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800A1FF8:
    // 0x800A1FF8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800A1FFC: addiu       $t9, $zero, 0xFE
    ctx->r25 = ADD32(0, 0XFE);
    // 0x800A2000: slti        $at, $t8, 0xFF
    ctx->r1 = SIGNED(ctx->r24) < 0XFF ? 1 : 0;
    // 0x800A2004: bne         $at, $zero, L_800A2010
    if (ctx->r1 != 0) {
        // 0x800A2008: nop
    
            goto L_800A2010;
    }
    // 0x800A2008: nop

    // 0x800A200C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_800A2010:
    // 0x800A2010: lb          $t0, 0x193($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X193);
    // 0x800A2014: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A2018: blez        $t0, L_800A2074
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800A201C: lui         $at, 0x4140
        ctx->r1 = S32(0X4140 << 16);
            goto L_800A2074;
    }
    // 0x800A201C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800A2020: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A2024: nop

L_800A2028:
    // 0x800A2028: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A202C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A2030: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800A2034: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800A2038: jal         0x800AAB5C
    // 0x800A203C: addiu       $a3, $a3, 0x660
    ctx->r7 = ADD32(ctx->r7, 0X660);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A203C: addiu       $a3, $a3, 0x660
    ctx->r7 = ADD32(ctx->r7, 0X660);
    after_1:
    // 0x800A2040: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A2044: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A2048: lwc1        $f8, 0x66C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A204C: nop

    // 0x800A2050: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A2054: swc1        $f10, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f10.u32l;
    // 0x800A2058: lb          $t1, 0x193($s3)
    ctx->r9 = MEM_B(ctx->r19, 0X193);
    // 0x800A205C: nop

    // 0x800A2060: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A2064: beq         $at, $zero, L_800A2078
    if (ctx->r1 == 0) {
        // 0x800A2068: lui         $at, 0x4140
        ctx->r1 = S32(0X4140 << 16);
            goto L_800A2078;
    }
    // 0x800A2068: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800A206C: bne         $s0, $s1, L_800A2028
    if (ctx->r16 != ctx->r17) {
        // 0x800A2070: nop
    
            goto L_800A2028;
    }
    // 0x800A2070: nop

L_800A2074:
    // 0x800A2074: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
L_800A2078:
    // 0x800A2078: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800A207C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A2080: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800A2084: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800A2088: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A208C: sw          $t3, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r11;
    // 0x800A2090: lb          $t4, 0x1CF($s3)
    ctx->r12 = MEM_B(ctx->r19, 0X1CF);
    // 0x800A2094: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800A2098: blez        $t4, L_800A20F8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A209C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800A20F8;
    }
    // 0x800A209C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A20A0: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800A20A4: beq         $at, $zero, L_800A20FC
    if (ctx->r1 == 0) {
        // 0x800A20A8: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_800A20FC;
    }
    // 0x800A20A8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_800A20AC:
    // 0x800A20AC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A20B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A20B4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800A20B8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800A20BC: jal         0x800AAB5C
    // 0x800A20C0: addiu       $a3, $a3, 0x660
    ctx->r7 = ADD32(ctx->r7, 0X660);
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A20C0: addiu       $a3, $a3, 0x660
    ctx->r7 = ADD32(ctx->r7, 0X660);
    after_2:
    // 0x800A20C4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A20C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A20CC: lwc1        $f16, 0x66C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A20D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A20D4: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x800A20D8: swc1        $f18, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f18.u32l;
    // 0x800A20DC: lb          $t6, 0x1CF($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X1CF);
    // 0x800A20E0: nop

    // 0x800A20E4: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800A20E8: beq         $at, $zero, L_800A20F8
    if (ctx->r1 == 0) {
        // 0x800A20EC: slti        $at, $s1, 0x3
        ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
            goto L_800A20F8;
    }
    // 0x800A20EC: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800A20F0: bne         $at, $zero, L_800A20AC
    if (ctx->r1 != 0) {
        // 0x800A20F4: nop
    
            goto L_800A20AC;
    }
    // 0x800A20F4: nop

L_800A20F8:
    // 0x800A20F8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_800A20FC:
    // 0x800A20FC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800A2100: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800A2104: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2108: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A210C: swc1        $f6, 0x66C($t7)
    MEM_W(0X66C, ctx->r15) = ctx->f6.u32l;
    // 0x800A2110: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A2114: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800A2118: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800A211C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800A2120: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800A2124: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A2128: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A212C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A2130: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A2134: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A2138: sb          $zero, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = 0;
    // 0x800A213C: jr          $ra
    // 0x800A2140: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800A2140: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void hud_main_battle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2144: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A2148: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A214C: lbu         $t7, 0x72F7($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X72F7);
    // 0x800A2150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2154: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800A2158: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800A215C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800A2160: lw          $a3, 0x64($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X64);
    // 0x800A2164: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A2168: bne         $t7, $at, L_800A2180
    if (ctx->r15 != ctx->r1) {
        // 0x800A216C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A2180;
    }
    // 0x800A216C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A2170: lb          $t8, 0x1D8($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1D8);
    // 0x800A2174: nop

    // 0x800A2178: bne         $t8, $zero, L_800A237C
    if (ctx->r24 != 0) {
        // 0x800A217C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A237C;
    }
    // 0x800A217C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2180:
    // 0x800A2180: jal         0x80068748
    // 0x800A2184: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A2184: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A2188: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A218C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800A2190: jal         0x800A422C
    // 0x800A2194: nop

    hud_race_start(rdram, ctx);
        goto after_1;
    // 0x800A2194: nop

    after_1:
    // 0x800A2198: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800A219C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800A21A0: jal         0x800A7A7C
    // 0x800A21A4: nop

    hud_weapon(rdram, ctx);
        goto after_2;
    // 0x800A21A4: nop

    after_2:
    // 0x800A21A8: jal         0x8001BAA8
    // 0x800A21AC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    get_racer_objects(rdram, ctx);
        goto after_3;
    // 0x800A21AC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x800A21B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A21B4: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A21B8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800A21BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A21C0: beq         $v1, $at, L_800A21D8
    if (ctx->r3 == ctx->r1) {
        // 0x800A21C4: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_800A21D8;
    }
    // 0x800A21C4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800A21C8: beq         $v1, $t2, L_800A21F4
    if (ctx->r3 == ctx->r10) {
        // 0x800A21CC: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_800A21F4;
    }
    // 0x800A21CC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800A21D0: b           L_800A2368
    // 0x800A21D4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_800A2368;
    // 0x800A21D4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800A21D8:
    // 0x800A21D8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800A21DC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800A21E0: jal         0x800A2388
    // 0x800A21E4: nop

    hud_battle_portraits(rdram, ctx);
        goto after_4;
    // 0x800A21E4: nop

    after_4:
    // 0x800A21E8: b           L_800A2370
    // 0x800A21EC: nop

        goto L_800A2370;
    // 0x800A21EC: nop

    // 0x800A21F0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_800A21F4:
    // 0x800A21F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A21F8: blez        $t9, L_800A2354
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800A21FC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800A2354;
    }
    // 0x800A21FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A2200: andi        $v1, $t9, 0x3
    ctx->r3 = ctx->r25 & 0X3;
    // 0x800A2204: beq         $v1, $zero, L_800A2264
    if (ctx->r3 == 0) {
        // 0x800A2208: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_800A2264;
    }
    // 0x800A2208: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800A220C: sll         $t3, $zero, 2
    ctx->r11 = S32(0 << 2);
    // 0x800A2210: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x800A2214: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A2218:
    // 0x800A2218: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800A221C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800A2220: lw          $v1, 0x64($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X64);
    // 0x800A2224: nop

    // 0x800A2228: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A222C: nop

    // 0x800A2230: beq         $t0, $t5, L_800A224C
    if (ctx->r8 == ctx->r13) {
        // 0x800A2234: nop
    
            goto L_800A224C;
    }
    // 0x800A2234: nop

    // 0x800A2238: lb          $t6, 0x1D8($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1D8);
    // 0x800A223C: nop

    // 0x800A2240: beq         $t6, $zero, L_800A224C
    if (ctx->r14 == 0) {
        // 0x800A2244: nop
    
            goto L_800A224C;
    }
    // 0x800A2244: nop

    // 0x800A2248: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A224C:
    // 0x800A224C: bne         $t1, $a2, L_800A2218
    if (ctx->r9 != ctx->r6) {
        // 0x800A2250: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A2218;
    }
    // 0x800A2250: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A2254: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800A2258: nop

    // 0x800A225C: beq         $a2, $t7, L_800A2354
    if (ctx->r6 == ctx->r15) {
        // 0x800A2260: nop
    
            goto L_800A2354;
    }
    // 0x800A2260: nop

L_800A2264:
    // 0x800A2264: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800A2268: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800A226C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A2270: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800A2274: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x800A2278: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A227C:
    // 0x800A227C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800A2280: nop

    // 0x800A2284: lw          $v1, 0x64($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X64);
    // 0x800A2288: nop

    // 0x800A228C: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A2290: nop

    // 0x800A2294: beq         $t0, $t5, L_800A22B0
    if (ctx->r8 == ctx->r13) {
        // 0x800A2298: nop
    
            goto L_800A22B0;
    }
    // 0x800A2298: nop

    // 0x800A229C: lb          $t6, 0x1D8($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1D8);
    // 0x800A22A0: nop

    // 0x800A22A4: beq         $t6, $zero, L_800A22B0
    if (ctx->r14 == 0) {
        // 0x800A22A8: nop
    
            goto L_800A22B0;
    }
    // 0x800A22A8: nop

    // 0x800A22AC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A22B0:
    // 0x800A22B0: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800A22B4: nop

    // 0x800A22B8: lw          $a3, 0x64($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X64);
    // 0x800A22BC: nop

    // 0x800A22C0: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800A22C4: nop

    // 0x800A22C8: beq         $t0, $t8, L_800A22E4
    if (ctx->r8 == ctx->r24) {
        // 0x800A22CC: nop
    
            goto L_800A22E4;
    }
    // 0x800A22CC: nop

    // 0x800A22D0: lb          $t9, 0x1D8($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1D8);
    // 0x800A22D4: nop

    // 0x800A22D8: beq         $t9, $zero, L_800A22E4
    if (ctx->r25 == 0) {
        // 0x800A22DC: nop
    
            goto L_800A22E4;
    }
    // 0x800A22DC: nop

    // 0x800A22E0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A22E4:
    // 0x800A22E4: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x800A22E8: nop

    // 0x800A22EC: lw          $a3, 0x64($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X64);
    // 0x800A22F0: nop

    // 0x800A22F4: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x800A22F8: nop

    // 0x800A22FC: beq         $t0, $t4, L_800A2318
    if (ctx->r8 == ctx->r12) {
        // 0x800A2300: nop
    
            goto L_800A2318;
    }
    // 0x800A2300: nop

    // 0x800A2304: lb          $t5, 0x1D8($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X1D8);
    // 0x800A2308: nop

    // 0x800A230C: beq         $t5, $zero, L_800A2318
    if (ctx->r13 == 0) {
        // 0x800A2310: nop
    
            goto L_800A2318;
    }
    // 0x800A2310: nop

    // 0x800A2314: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A2318:
    // 0x800A2318: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800A231C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A2320: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x800A2324: nop

    // 0x800A2328: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800A232C: nop

    // 0x800A2330: beq         $t0, $t7, L_800A234C
    if (ctx->r8 == ctx->r15) {
        // 0x800A2334: nop
    
            goto L_800A234C;
    }
    // 0x800A2334: nop

    // 0x800A2338: lb          $t8, 0x1D8($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1D8);
    // 0x800A233C: nop

    // 0x800A2340: beq         $t8, $zero, L_800A234C
    if (ctx->r24 == 0) {
        // 0x800A2344: nop
    
            goto L_800A234C;
    }
    // 0x800A2344: nop

    // 0x800A2348: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A234C:
    // 0x800A234C: bne         $a0, $t1, L_800A227C
    if (ctx->r4 != ctx->r9) {
        // 0x800A2350: nop
    
            goto L_800A227C;
    }
    // 0x800A2350: nop

L_800A2354:
    // 0x800A2354: bne         $a1, $t2, L_800A2370
    if (ctx->r5 != ctx->r10) {
        // 0x800A2358: nop
    
            goto L_800A2370;
    }
    // 0x800A2358: nop

    // 0x800A235C: b           L_800A237C
    // 0x800A2360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A237C;
    // 0x800A2360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A2364: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800A2368:
    // 0x800A2368: jal         0x800A469C
    // 0x800A236C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_bananas(rdram, ctx);
        goto after_5;
    // 0x800A236C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
L_800A2370:
    // 0x800A2370: jal         0x80068748
    // 0x800A2374: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_6;
    // 0x800A2374: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800A2378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A237C:
    // 0x800A237C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800A2380: jr          $ra
    // 0x800A2384: nop

    return;
    // 0x800A2384: nop

;}
RECOMP_FUNC void hud_battle_portraits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2388: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800A238C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A2390: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A2394: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800A2398: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800A239C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800A23A0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800A23A4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800A23A8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800A23AC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800A23B0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A23B4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A23B8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A23BC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A23C0: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800A23C4: jal         0x8001BAA8
    // 0x800A23C8: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800A23C8: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_0:
    // 0x800A23CC: beq         $s0, $zero, L_800A23E0
    if (ctx->r16 == 0) {
        // 0x800A23D0: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800A23E0;
    }
    // 0x800A23D0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800A23D4: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x800A23D8: b           L_800A23F4
    // 0x800A23DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800A23F4;
    // 0x800A23DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800A23E0:
    // 0x800A23E0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800A23E4: nop

    // 0x800A23E8: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x800A23EC: nop

    // 0x800A23F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800A23F4:
    // 0x800A23F4: jal         0x80068748
    // 0x800A23F8: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800A23F8: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    after_1:
    // 0x800A23FC: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800A2400: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x800A2404: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A2408: bne         $t7, $at, L_800A27F4
    if (ctx->r15 != ctx->r1) {
        // 0x800A240C: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800A27F4;
    }
    // 0x800A240C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A2410: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A2414: addiu       $s0, $s0, 0x729C
    ctx->r16 = ADD32(ctx->r16, 0X729C);
    // 0x800A2418: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A241C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A2420: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2424: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2428: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A242C: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A2430: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A2434: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800A2438: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A243C: mfc1        $s4, $f6
    ctx->r20 = (int32_t)ctx->f6.u32l;
    // 0x800A2440: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800A2444: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A2448: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A244C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A2450: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2454: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2458: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A245C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A2460: lwc1        $f21, -0x7350($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X7350);
    // 0x800A2464: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A2468: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800A246C: lwc1        $f20, -0x734C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X734C);
    // 0x800A2470: addiu       $s5, $s5, 0x72F7
    ctx->r21 = ADD32(ctx->r21, 0X72F7);
    // 0x800A2474: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800A2478: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x800A247C: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
    // 0x800A2480: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800A2484: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
L_800A2488:
    // 0x800A2488: mtc1        $s4, $f16
    ctx->f16.u32l = ctx->r20;
    // 0x800A248C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2490: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A2494: lwc1        $f12, 0x64C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A2498: addu        $t3, $s1, $t0
    ctx->r11 = ADD32(ctx->r17, ctx->r8);
    // 0x800A249C: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x800A24A0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800A24A4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A24A8: lwc1        $f16, 0x650($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A24AC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A24B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A24B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A24B8: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800A24BC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A24C0: lw          $a0, 0x64($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X64);
    // 0x800A24C4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A24C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A24CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A24D0: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800A24D4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800A24D8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A24DC: nop

    // 0x800A24E0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A24E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A24E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A24EC: nop

    // 0x800A24F0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A24F4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A24F8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800A24FC: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A2500: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x800A2504: add.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800A2508: swc1        $f8, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f8.u32l;
    // 0x800A250C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2510: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A2514: lwc1        $f16, 0x650($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A2518: nop

    // 0x800A251C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A2520: swc1        $f18, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f18.u32l;
    // 0x800A2524: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2528: nop

    // 0x800A252C: lwc1        $f4, 0x68C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X68C);
    // 0x800A2530: nop

    // 0x800A2534: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A2538: swc1        $f6, 0x68C($v0)
    MEM_W(0X68C, ctx->r2) = ctx->f6.u32l;
    // 0x800A253C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2540: nop

    // 0x800A2544: lwc1        $f8, 0x690($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X690);
    // 0x800A2548: nop

    // 0x800A254C: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800A2550: swc1        $f10, 0x690($v0)
    MEM_W(0X690, ctx->r2) = ctx->f10.u32l;
    // 0x800A2554: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2558: nop

    // 0x800A255C: lwc1        $f16, 0x6AC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6AC);
    // 0x800A2560: nop

    // 0x800A2564: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A2568: swc1        $f18, 0x6AC($v0)
    MEM_W(0X6AC, ctx->r2) = ctx->f18.u32l;
    // 0x800A256C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2570: nop

    // 0x800A2574: lwc1        $f4, 0x6B0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6B0);
    // 0x800A2578: nop

    // 0x800A257C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A2580: swc1        $f6, 0x6B0($v0)
    MEM_W(0X6B0, ctx->r2) = ctx->f6.u32l;
    // 0x800A2584: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2588: nop

    // 0x800A258C: lwc1        $f8, 0x6CC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x800A2590: nop

    // 0x800A2594: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A2598: swc1        $f10, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f10.u32l;
    // 0x800A259C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A25A0: nop

    // 0x800A25A4: lwc1        $f16, 0x6D0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6D0);
    // 0x800A25A8: nop

    // 0x800A25AC: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A25B0: swc1        $f18, 0x6D0($v0)
    MEM_W(0X6D0, ctx->r2) = ctx->f18.u32l;
    // 0x800A25B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A25B8: nop

    // 0x800A25BC: lwc1        $f4, 0x6EC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6EC);
    // 0x800A25C0: nop

    // 0x800A25C4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A25C8: swc1        $f6, 0x6EC($v0)
    MEM_W(0X6EC, ctx->r2) = ctx->f6.u32l;
    // 0x800A25CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A25D0: nop

    // 0x800A25D4: lwc1        $f8, 0x6F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6F0);
    // 0x800A25D8: nop

    // 0x800A25DC: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A25E0: swc1        $f10, 0x6F0($v0)
    MEM_W(0X6F0, ctx->r2) = ctx->f10.u32l;
    // 0x800A25E4: lbu         $v1, 0x0($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X0);
    // 0x800A25E8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800A25EC: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A25F0: bne         $at, $zero, L_800A260C
    if (ctx->r1 != 0) {
        // 0x800A25F4: nop
    
            goto L_800A260C;
    }
    // 0x800A25F4: nop

    // 0x800A25F8: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x800A25FC: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x800A2600: nop

    // 0x800A2604: bne         $t5, $t6, L_800A2628
    if (ctx->r13 != ctx->r14) {
        // 0x800A2608: nop
    
            goto L_800A2628;
    }
    // 0x800A2608: nop

L_800A260C:
    // 0x800A260C: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x800A2610: jal         0x800A2834
    // 0x800A2614: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    hud_lives_render(rdram, ctx);
        goto after_2;
    // 0x800A2614: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800A2618: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x800A261C: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800A2620: lbu         $v1, 0x0($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X0);
    // 0x800A2624: nop

L_800A2628:
    // 0x800A2628: bne         $s6, $v1, L_800A2638
    if (ctx->r22 != ctx->r3) {
        // 0x800A262C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800A2638;
    }
    // 0x800A262C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800A2630: b           L_800A2690
    // 0x800A2634: addiu       $s4, $s4, 0x44
    ctx->r20 = ADD32(ctx->r20, 0X44);
        goto L_800A2690;
    // 0x800A2634: addiu       $s4, $s4, 0x44
    ctx->r20 = ADD32(ctx->r20, 0X44);
L_800A2638:
    // 0x800A2638: bne         $fp, $v1, L_800A2690
    if (ctx->r30 != ctx->r3) {
        // 0x800A263C: lui         $t7, 0x8000
        ctx->r15 = S32(0X8000 << 16);
            goto L_800A2690;
    }
    // 0x800A263C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800A2640: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800A2644: nop

    // 0x800A2648: bne         $t7, $zero, L_800A268C
    if (ctx->r15 != 0) {
        // 0x800A264C: nop
    
            goto L_800A268C;
    }
    // 0x800A264C: nop

    // 0x800A2650: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x800A2654: nop

    // 0x800A2658: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800A265C: add.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = ctx->f18.d + ctx->f20.d;
    // 0x800A2660: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A2664: nop

    // 0x800A2668: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A266C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2670: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2674: nop

    // 0x800A2678: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800A267C: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x800A2680: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A2684: b           L_800A2690
    // 0x800A2688: nop

        goto L_800A2690;
    // 0x800A2688: nop

L_800A268C:
    // 0x800A268C: addiu       $s1, $s1, 0x37
    ctx->r17 = ADD32(ctx->r17, 0X37);
L_800A2690:
    // 0x800A2690: bne         $s2, $s7, L_800A2488
    if (ctx->r18 != ctx->r23) {
        // 0x800A2694: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_800A2488;
    }
    // 0x800A2694: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800A2698: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800A269C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A26A0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800A26A4: lwc1        $f12, 0x64C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A26A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A26AC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A26B0: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A26B4: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A26B8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A26BC: nop

    // 0x800A26C0: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A26C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A26C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A26CC: nop

    // 0x800A26D0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A26D4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A26D8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800A26DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A26E0: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800A26E4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A26E8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A26EC: nop

    // 0x800A26F0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A26F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A26F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A26FC: nop

    // 0x800A2700: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A2704: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A2708: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800A270C: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A2710: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800A2714: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800A2718: swc1        $f4, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f4.u32l;
    // 0x800A271C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2720: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A2724: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A2728: nop

    // 0x800A272C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A2730: swc1        $f10, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f10.u32l;
    // 0x800A2734: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2738: nop

    // 0x800A273C: lwc1        $f16, 0x68C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X68C);
    // 0x800A2740: nop

    // 0x800A2744: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A2748: swc1        $f18, 0x68C($v0)
    MEM_W(0X68C, ctx->r2) = ctx->f18.u32l;
    // 0x800A274C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2750: nop

    // 0x800A2754: lwc1        $f4, 0x690($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X690);
    // 0x800A2758: nop

    // 0x800A275C: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A2760: swc1        $f6, 0x690($v0)
    MEM_W(0X690, ctx->r2) = ctx->f6.u32l;
    // 0x800A2764: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2768: nop

    // 0x800A276C: lwc1        $f8, 0x6AC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6AC);
    // 0x800A2770: nop

    // 0x800A2774: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A2778: swc1        $f10, 0x6AC($v0)
    MEM_W(0X6AC, ctx->r2) = ctx->f10.u32l;
    // 0x800A277C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2780: nop

    // 0x800A2784: lwc1        $f16, 0x6B0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6B0);
    // 0x800A2788: nop

    // 0x800A278C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A2790: swc1        $f18, 0x6B0($v0)
    MEM_W(0X6B0, ctx->r2) = ctx->f18.u32l;
    // 0x800A2794: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2798: nop

    // 0x800A279C: lwc1        $f4, 0x6CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x800A27A0: nop

    // 0x800A27A4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A27A8: swc1        $f6, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f6.u32l;
    // 0x800A27AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A27B0: nop

    // 0x800A27B4: lwc1        $f8, 0x6D0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6D0);
    // 0x800A27B8: nop

    // 0x800A27BC: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A27C0: swc1        $f10, 0x6D0($v0)
    MEM_W(0X6D0, ctx->r2) = ctx->f10.u32l;
    // 0x800A27C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A27C8: nop

    // 0x800A27CC: lwc1        $f16, 0x6EC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6EC);
    // 0x800A27D0: nop

    // 0x800A27D4: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A27D8: swc1        $f18, 0x6EC($v0)
    MEM_W(0X6EC, ctx->r2) = ctx->f18.u32l;
    // 0x800A27DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A27E0: nop

    // 0x800A27E4: lwc1        $f4, 0x6F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6F0);
    // 0x800A27E8: nop

    // 0x800A27EC: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A27F0: swc1        $f6, 0x6F0($v0)
    MEM_W(0X6F0, ctx->r2) = ctx->f6.u32l;
L_800A27F4:
    // 0x800A27F4: jal         0x80068748
    // 0x800A27F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_3;
    // 0x800A27F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800A27FC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800A2800: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A2804: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A2808: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A280C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A2810: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A2814: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800A2818: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800A281C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800A2820: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800A2824: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800A2828: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800A282C: jr          $ra
    // 0x800A2830: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800A2830: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void hud_lives_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2834: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2838: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A283C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A2840: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2844: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A2848: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A284C: lb          $t7, 0x3($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3);
    // 0x800A2850: addiu       $s0, $s0, 0x729C
    ctx->r16 = ADD32(ctx->r16, 0X729C);
    // 0x800A2854: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A2858: addiu       $t8, $t7, 0x38
    ctx->r24 = ADD32(ctx->r15, 0X38);
    // 0x800A285C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A2860: sh          $t8, 0x646($t9)
    MEM_H(0X646, ctx->r25) = ctx->r24;
    // 0x800A2864: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A2868: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800A286C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A2870: bne         $at, $zero, L_800A2898
    if (ctx->r1 != 0) {
        // 0x800A2874: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A2898;
    }
    // 0x800A2874: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A2878: bne         $v1, $at, L_800A28EC
    if (ctx->r3 != ctx->r1) {
        // 0x800A287C: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_800A28EC;
    }
    // 0x800A287C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800A2880: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A2884: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A2888: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800A288C: nop

    // 0x800A2890: bne         $t1, $at, L_800A28EC
    if (ctx->r9 != ctx->r1) {
        // 0x800A2894: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_800A28EC;
    }
    // 0x800A2894: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_800A2898:
    // 0x800A2898: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800A289C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A28A0: sb          $t2, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = ctx->r10;
    // 0x800A28A4: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A28A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A28AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A28B0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A28B4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A28B8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A28BC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A28C0: jal         0x800AAB5C
    // 0x800A28C4: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A28C4: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    after_0:
    // 0x800A28C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A28CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A28D0: sb          $zero, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = 0;
    // 0x800A28D4: jal         0x800784A4
    // 0x800A28D8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    rdp_init(rdram, ctx);
        goto after_1;
    // 0x800A28D8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_1:
    // 0x800A28DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A28E0: jal         0x8007B820
    // 0x800A28E4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    rendermode_reset(rdram, ctx);
        goto after_2;
    // 0x800A28E4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_2:
    // 0x800A28E8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_800A28EC:
    // 0x800A28EC: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800A28F0: lb          $v0, 0x185($t3)
    ctx->r2 = MEM_B(ctx->r11, 0X185);
    // 0x800A28F4: nop

    // 0x800A28F8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800A28FC: beq         $at, $zero, L_800A2940
    if (ctx->r1 == 0) {
        // 0x800A2900: nop
    
            goto L_800A2940;
    }
    // 0x800A2900: nop

    // 0x800A2904: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A2908: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A290C: sh          $v0, 0x6D8($t4)
    MEM_H(0X6D8, ctx->r12) = ctx->r2;
    // 0x800A2910: lbu         $t5, 0x72F7($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X72F7);
    // 0x800A2914: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A2918: bne         $t5, $at, L_800A29D8
    if (ctx->r13 != ctx->r1) {
        // 0x800A291C: nop
    
            goto L_800A29D8;
    }
    // 0x800A291C: nop

    // 0x800A2920: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2924: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800A2928: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A292C: lwc1        $f4, 0x6CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x800A2930: nop

    // 0x800A2934: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A2938: b           L_800A29D8
    // 0x800A293C: swc1        $f8, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f8.u32l;
        goto L_800A29D8;
    // 0x800A293C: swc1        $f8, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f8.u32l;
L_800A2940:
    // 0x800A2940: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800A2944: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A2948: bne         $v1, $zero, L_800A2954
    if (ctx->r3 != 0) {
        // 0x800A294C: nop
    
            goto L_800A2954;
    }
    // 0x800A294C: nop

    // 0x800A2950: break       7
    do_break(2148149584);
L_800A2954:
    // 0x800A2954: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A2958: bne         $v1, $at, L_800A296C
    if (ctx->r3 != ctx->r1) {
        // 0x800A295C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A296C;
    }
    // 0x800A295C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A2960: bne         $v0, $at, L_800A296C
    if (ctx->r2 != ctx->r1) {
        // 0x800A2964: nop
    
            goto L_800A296C;
    }
    // 0x800A2964: nop

    // 0x800A2968: break       6
    do_break(2148149608);
L_800A296C:
    // 0x800A296C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2970: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2974: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2978: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A297C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A2980: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A2984: mflo        $t6
    ctx->r14 = lo;
    // 0x800A2988: sh          $t6, 0x6D8($t7)
    MEM_H(0X6D8, ctx->r15) = ctx->r14;
    // 0x800A298C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A2990: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800A2994: lb          $t9, 0x185($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X185);
    // 0x800A2998: nop

    // 0x800A299C: div         $zero, $t9, $v1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r3)));
    // 0x800A29A0: bne         $v1, $zero, L_800A29AC
    if (ctx->r3 != 0) {
        // 0x800A29A4: nop
    
            goto L_800A29AC;
    }
    // 0x800A29A4: nop

    // 0x800A29A8: break       7
    do_break(2148149672);
L_800A29AC:
    // 0x800A29AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A29B0: bne         $v1, $at, L_800A29C4
    if (ctx->r3 != ctx->r1) {
        // 0x800A29B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A29C4;
    }
    // 0x800A29B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A29B8: bne         $t9, $at, L_800A29C4
    if (ctx->r25 != ctx->r1) {
        // 0x800A29BC: nop
    
            goto L_800A29C4;
    }
    // 0x800A29BC: nop

    // 0x800A29C0: break       6
    do_break(2148149696);
L_800A29C4:
    // 0x800A29C4: mfhi        $t0
    ctx->r8 = hi;
    // 0x800A29C8: sh          $t0, 0x6F8($t1)
    MEM_H(0X6F8, ctx->r9) = ctx->r8;
    // 0x800A29CC: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A29D0: jal         0x800AAB5C
    // 0x800A29D4: addiu       $a3, $a3, 0x6E0
    ctx->r7 = ADD32(ctx->r7, 0X6E0);
    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A29D4: addiu       $a3, $a3, 0x6E0
    ctx->r7 = ADD32(ctx->r7, 0X6E0);
    after_3:
L_800A29D8:
    // 0x800A29D8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A29DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A29E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A29E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A29E8: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A29EC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A29F0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A29F4: jal         0x800AAB5C
    // 0x800A29F8: addiu       $a3, $a3, 0x6C0
    ctx->r7 = ADD32(ctx->r7, 0X6C0);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A29F8: addiu       $a3, $a3, 0x6C0
    ctx->r7 = ADD32(ctx->r7, 0X6C0);
    after_4:
    // 0x800A29FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A2A00: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A2A04: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800A2A08: bne         $a0, $v1, L_800A2A50
    if (ctx->r4 != ctx->r3) {
        // 0x800A2A0C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A2A50;
    }
    // 0x800A2A0C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2A10: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800A2A14: nop

    // 0x800A2A18: lb          $t3, 0x185($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X185);
    // 0x800A2A1C: nop

    // 0x800A2A20: slti        $at, $t3, 0xA
    ctx->r1 = SIGNED(ctx->r11) < 0XA ? 1 : 0;
    // 0x800A2A24: beq         $at, $zero, L_800A2A50
    if (ctx->r1 == 0) {
        // 0x800A2A28: nop
    
            goto L_800A2A50;
    }
    // 0x800A2A28: nop

    // 0x800A2A2C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2A30: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800A2A34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A2A38: lwc1        $f10, 0x6CC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x800A2A3C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A2A40: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800A2A44: swc1        $f18, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f18.u32l;
    // 0x800A2A48: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A2A4C: nop

L_800A2A50:
    // 0x800A2A50: beq         $a0, $v1, L_800A2ABC
    if (ctx->r4 == ctx->r3) {
        // 0x800A2A54: addiu       $a1, $a1, 0x72C0
        ctx->r5 = ADD32(ctx->r5, 0X72C0);
            goto L_800A2ABC;
    }
    // 0x800A2A54: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A2A58: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A2A5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2A60: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2A64: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A2A68: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A2A6C: jal         0x800AAB5C
    // 0x800A2A70: addiu       $a3, $a3, 0x6A0
    ctx->r7 = ADD32(ctx->r7, 0X6A0);
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A2A70: addiu       $a3, $a3, 0x6A0
    ctx->r7 = ADD32(ctx->r7, 0X6A0);
    after_5:
    // 0x800A2A74: jal         0x8007C36C
    // 0x800A2A78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_6;
    // 0x800A2A78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A2A7C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A2A80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2A84: sb          $t4, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = ctx->r12;
    // 0x800A2A88: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A2A8C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2A90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2A94: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2A98: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A2A9C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A2AA0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A2AA4: jal         0x800AAB5C
    // 0x800A2AA8: addiu       $a3, $a3, 0x680
    ctx->r7 = ADD32(ctx->r7, 0X680);
    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A2AA8: addiu       $a3, $a3, 0x680
    ctx->r7 = ADD32(ctx->r7, 0X680);
    after_7:
    // 0x800A2AAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2AB0: sb          $zero, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = 0;
    // 0x800A2AB4: jal         0x8007C36C
    // 0x800A2AB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_8;
    // 0x800A2AB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
L_800A2ABC:
    // 0x800A2ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2AC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A2AC4: jr          $ra
    // 0x800A2AC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A2AC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void hud_main_boss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2ACC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2AD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2AD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A2AD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A2ADC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A2AE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A2AE4: lw          $s1, 0x64($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X64);
    // 0x800A2AE8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800A2AEC: jal         0x80068748
    // 0x800A2AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A2AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A2AF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A2AF8: jal         0x800A5FAC
    // 0x800A2AFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_wrong_way(rdram, ctx);
        goto after_1;
    // 0x800A2AFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800A2B00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A2B04: jal         0x800A422C
    // 0x800A2B08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_start(rdram, ctx);
        goto after_2;
    // 0x800A2B08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800A2B0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A2B10: jal         0x800A80C4
    // 0x800A2B14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_time(rdram, ctx);
        goto after_3;
    // 0x800A2B14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800A2B18: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A2B1C: jal         0x800A7A7C
    // 0x800A2B20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_weapon(rdram, ctx);
        goto after_4;
    // 0x800A2B20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800A2B24: jal         0x8006BFF0
    // 0x800A2B28: nop

    level_header(rdram, ctx);
        goto after_5;
    // 0x800A2B28: nop

    after_5:
    // 0x800A2B2C: lb          $t7, 0x4B($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X4B);
    // 0x800A2B30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A2B34: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800A2B38: bne         $at, $zero, L_800A2B48
    if (ctx->r1 != 0) {
        // 0x800A2B3C: nop
    
            goto L_800A2B48;
    }
    // 0x800A2B3C: nop

    // 0x800A2B40: jal         0x800A5498
    // 0x800A2B44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_lap_count(rdram, ctx);
        goto after_6;
    // 0x800A2B44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
L_800A2B48:
    // 0x800A2B48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A2B4C: jal         0x800A3DCC
    // 0x800A2B50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_speedometre(rdram, ctx);
        goto after_7;
    // 0x800A2B50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800A2B54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A2B58: jal         0x800A518C
    // 0x800A2B5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_position(rdram, ctx);
        goto after_8;
    // 0x800A2B5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800A2B60: jal         0x80068748
    // 0x800A2B64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_9;
    // 0x800A2B64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x800A2B68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2B6C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A2B70: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A2B74: jr          $ra
    // 0x800A2B78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A2B78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void hud_main_taj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2B7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2B80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2B84: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A2B88: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A2B8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A2B90: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A2B94: lw          $s0, 0x64($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X64);
    // 0x800A2B98: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800A2B9C: jal         0x80068748
    // 0x800A2BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A2BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A2BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2BA8: jal         0x800A5FAC
    // 0x800A2BAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_wrong_way(rdram, ctx);
        goto after_1;
    // 0x800A2BAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800A2BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2BB4: jal         0x800A5498
    // 0x800A2BB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_lap_count(rdram, ctx);
        goto after_2;
    // 0x800A2BB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800A2BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2BC0: jal         0x800A518C
    // 0x800A2BC4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_race_position(rdram, ctx);
        goto after_3;
    // 0x800A2BC4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800A2BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2BCC: jal         0x800A80C4
    // 0x800A2BD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_race_time(rdram, ctx);
        goto after_4;
    // 0x800A2BD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800A2BD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A2BD8: jal         0x800A422C
    // 0x800A2BDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_race_start(rdram, ctx);
        goto after_5;
    // 0x800A2BDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800A2BE0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A2BE4: jal         0x800A3DCC
    // 0x800A2BE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_speedometre(rdram, ctx);
        goto after_6;
    // 0x800A2BE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800A2BEC: jal         0x80068748
    // 0x800A2BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_7;
    // 0x800A2BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A2BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2BF8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A2BFC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A2C00: jr          $ra
    // 0x800A2C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A2C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void hud_main_hub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2C08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2C10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A2C14: jal         0x80066450
    // 0x800A2C18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800A2C18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A2C1C: bne         $v0, $zero, L_800A2CB0
    if (ctx->r2 != 0) {
        // 0x800A2C20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A2CB0;
    }
    // 0x800A2C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A2C24: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A2C28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A2C2C: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x800A2C30: jal         0x80068748
    // 0x800A2C34: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800A2C34: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_1:
    // 0x800A2C38: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2C3C: jal         0x800A76E8
    // 0x800A2C40: nop

    hud_balloons(rdram, ctx);
        goto after_2;
    // 0x800A2C40: nop

    after_2:
    // 0x800A2C44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A2C48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A2C4C: jal         0x800A3DCC
    // 0x800A2C50: nop

    hud_speedometre(rdram, ctx);
        goto after_3;
    // 0x800A2C50: nop

    after_3:
    // 0x800A2C54: jal         0x8009F1C4
    // 0x800A2C58: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_4;
    // 0x800A2C58: nop

    after_4:
    // 0x800A2C5C: beq         $v0, $zero, L_800A2CA4
    if (ctx->r2 == 0) {
        // 0x800A2C60: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_800A2CA4;
    }
    // 0x800A2C60: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A2C64: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A2C68: nop

    // 0x800A2C6C: addiu       $a3, $a3, 0x720
    ctx->r7 = ADD32(ctx->r7, 0X720);
    // 0x800A2C70: jal         0x8006ECD0
    // 0x800A2C74: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    get_settings(rdram, ctx);
        goto after_5;
    // 0x800A2C74: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_5:
    // 0x800A2C78: lb          $t8, 0x71($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X71);
    // 0x800A2C7C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800A2C80: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2C84: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2C88: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2C8C: addiu       $t9, $t8, 0x38
    ctx->r25 = ADD32(ctx->r24, 0X38);
    // 0x800A2C90: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A2C94: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A2C98: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A2C9C: jal         0x800AAB5C
    // 0x800A2CA0: sh          $t9, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r25;
    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A2CA0: sh          $t9, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r25;
    after_6:
L_800A2CA4:
    // 0x800A2CA4: jal         0x80068748
    // 0x800A2CA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_7;
    // 0x800A2CA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A2CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2CB0:
    // 0x800A2CB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A2CB4: jr          $ra
    // 0x800A2CB8: nop

    return;
    // 0x800A2CB8: nop

;}
RECOMP_FUNC void hud_main_time_trial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2CBC: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800A2CC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A2CC4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A2CC8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A2CCC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A2CD0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A2CD4: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x800A2CD8: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x800A2CDC: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x800A2CE0: lw          $t7, 0x64($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X64);
    // 0x800A2CE4: addiu       $s0, $s0, 0x72B4
    ctx->r16 = ADD32(ctx->r16, 0X72B4);
    // 0x800A2CE8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A2CEC: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x800A2CF0: lw          $t8, 0x50($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X50);
    // 0x800A2CF4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800A2CF8: bne         $t8, $zero, L_800A2D74
    if (ctx->r24 != 0) {
        // 0x800A2CFC: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A2D74;
    }
    // 0x800A2CFC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A2D00: lw          $t9, 0x72B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72B0);
    // 0x800A2D04: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800A2D08: lh          $t3, 0x28($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X28);
    // 0x800A2D0C: sb          $t4, 0x91($sp)
    MEM_B(0X91, ctx->r29) = ctx->r12;
    // 0x800A2D10: sh          $zero, 0x92($sp)
    MEM_H(0X92, ctx->r29) = 0;
    // 0x800A2D14: sh          $zero, 0x94($sp)
    MEM_H(0X94, ctx->r29) = 0;
    // 0x800A2D18: sh          $zero, 0x96($sp)
    MEM_H(0X96, ctx->r29) = 0;
    // 0x800A2D1C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A2D20: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x800A2D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A2D28: jal         0x8000EA54
    // 0x800A2D2C: sb          $t3, 0x90($sp)
    MEM_B(0X90, ctx->r29) = ctx->r11;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x800A2D2C: sb          $t3, 0x90($sp)
    MEM_B(0X90, ctx->r29) = ctx->r11;
    after_0:
    // 0x800A2D30: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A2D34: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2D38: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A2D3C: addiu       $s1, $s1, 0x729C
    ctx->r17 = ADD32(ctx->r17, 0X729C);
    // 0x800A2D40: sw          $v0, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r2;
    // 0x800A2D44: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800A2D48: addiu       $t6, $zero, -0x8000
    ctx->r14 = ADD32(0, -0X8000);
    // 0x800A2D4C: sh          $t6, 0x340($t7)
    MEM_H(0X340, ctx->r15) = ctx->r14;
    // 0x800A2D50: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A2D54: nop

    // 0x800A2D58: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    // 0x800A2D5C: nop

    // 0x800A2D60: beq         $a0, $zero, L_800A2D74
    if (ctx->r4 == 0) {
        // 0x800A2D64: nop
    
            goto L_800A2D74;
    }
    // 0x800A2D64: nop

    // 0x800A2D68: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x800A2D6C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A2D70: nop

L_800A2D74:
    // 0x800A2D74: lw          $t8, 0x88($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X88);
    // 0x800A2D78: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A2D7C: bne         $t8, $zero, L_800A2DD8
    if (ctx->r24 != 0) {
        // 0x800A2D80: addiu       $s1, $s1, 0x729C
        ctx->r17 = ADD32(ctx->r17, 0X729C);
            goto L_800A2DD8;
    }
    // 0x800A2D80: addiu       $s1, $s1, 0x729C
    ctx->r17 = ADD32(ctx->r17, 0X729C);
    // 0x800A2D84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A2D88: lw          $t9, 0x72B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72B0);
    // 0x800A2D8C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800A2D90: lh          $t3, 0x44($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X44);
    // 0x800A2D94: sb          $t4, 0x89($sp)
    MEM_B(0X89, ctx->r29) = ctx->r12;
    // 0x800A2D98: sh          $zero, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = 0;
    // 0x800A2D9C: sh          $zero, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = 0;
    // 0x800A2DA0: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x800A2DA4: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A2DA8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800A2DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A2DB0: jal         0x8000EA54
    // 0x800A2DB4: sb          $t3, 0x88($sp)
    MEM_B(0X88, ctx->r29) = ctx->r11;
    spawn_object(rdram, ctx);
        goto after_1;
    // 0x800A2DB4: sb          $t3, 0x88($sp)
    MEM_B(0X88, ctx->r29) = ctx->r11;
    after_1:
    // 0x800A2DB8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A2DBC: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2DC0: sw          $v0, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->r2;
    // 0x800A2DC4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800A2DC8: addiu       $t6, $zero, -0x8000
    ctx->r14 = ADD32(0, -0X8000);
    // 0x800A2DCC: sh          $t6, 0x440($t7)
    MEM_H(0X440, ctx->r15) = ctx->r14;
    // 0x800A2DD0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A2DD4: nop

L_800A2DD8:
    // 0x800A2DD8: lw          $s0, 0x50($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X50);
    // 0x800A2DDC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A2DE0: beq         $s0, $zero, L_800A3BFC
    if (ctx->r16 == 0) {
        // 0x800A2DE4: addiu       $s2, $s2, 0x7327
        ctx->r18 = ADD32(ctx->r18, 0X7327);
            goto L_800A3BFC;
    }
    // 0x800A2DE4: addiu       $s2, $s2, 0x7327
    ctx->r18 = ADD32(ctx->r18, 0X7327);
    // 0x800A2DE8: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2DEC: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x800A2DF0: sb          $t8, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r24;
    // 0x800A2DF4: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x800A2DF8: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800A2DFC: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x800A2E00: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800A2E04: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800A2E08: sh          $t3, 0x52($t5)
    MEM_H(0X52, ctx->r13) = ctx->r11;
    // 0x800A2E0C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2E10: nop

    // 0x800A2E14: beq         $v0, $at, L_800A30A8
    if (ctx->r2 == ctx->r1) {
        // 0x800A2E18: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A30A8;
    }
    // 0x800A2E18: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A2E1C: bne         $v0, $at, L_800A2E54
    if (ctx->r2 != ctx->r1) {
        // 0x800A2E20: nop
    
            goto L_800A2E54;
    }
    // 0x800A2E20: nop

    // 0x800A2E24: jal         0x8001139C
    // 0x800A2E28: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    get_race_countdown(rdram, ctx);
        goto after_2;
    // 0x800A2E28: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_2:
    // 0x800A2E2C: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2E30: bne         $v0, $zero, L_800A2E4C
    if (ctx->r2 != 0) {
        // 0x800A2E34: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_800A2E4C;
    }
    // 0x800A2E34: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800A2E38: jal         0x800015C8
    // 0x800A2E3C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    music_is_playing(rdram, ctx);
        goto after_3;
    // 0x800A2E3C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_3:
    // 0x800A2E40: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2E44: bne         $v0, $zero, L_800A2E54
    if (ctx->r2 != 0) {
        // 0x800A2E48: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_800A2E54;
    }
    // 0x800A2E48: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
L_800A2E4C:
    // 0x800A2E4C: b           L_800A3094
    // 0x800A2E50: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
        goto L_800A3094;
    // 0x800A2E50: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
L_800A2E54:
    // 0x800A2E54: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2E58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A2E5C: bne         $t7, $at, L_800A2F68
    if (ctx->r15 != ctx->r1) {
        // 0x800A2E60: nop
    
            goto L_800A2F68;
    }
    // 0x800A2E60: nop

    // 0x800A2E64: jal         0x800015F8
    // 0x800A2E68: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    music_animation_fraction(rdram, ctx);
        goto after_4;
    // 0x800A2E68: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_4:
    // 0x800A2E6C: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A2E70: lbu         $t4, 0x0($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2E74: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800A2E78: sll         $t3, $t4, 3
    ctx->r11 = S32(ctx->r12 << 3);
    // 0x800A2E7C: lw          $t2, 0x44($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X44);
    // 0x800A2E80: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800A2E84: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x800A2E88: lw          $v0, 0x4($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X4);
    // 0x800A2E8C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A2E90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A2E94: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x800A2E98: c.eq.d      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.d == ctx->f12.d;
    // 0x800A2E9C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800A2EA0: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2EA4: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800A2EA8: bc1f        L_800A2EB8
    if (!c1cs) {
        // 0x800A2EAC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800A2EB8;
    }
    // 0x800A2EAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800A2EB0: b           L_800A3094
    // 0x800A2EB4: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
        goto L_800A3094;
    // 0x800A2EB4: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
L_800A2EB8:
    // 0x800A2EB8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A2EBC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800A2EC0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A2EC4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A2EC8: c.lt.d      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.d < ctx->f12.d;
    // 0x800A2ECC: nop

    // 0x800A2ED0: bc1f        L_800A2F28
    if (!c1cs) {
        // 0x800A2ED4: nop
    
            goto L_800A2F28;
    }
    // 0x800A2ED4: nop

    // 0x800A2ED8: sub.d       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f12.d - ctx->f18.d;
    // 0x800A2EDC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800A2EE0: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x800A2EE4: cvt.d.s     $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.d = CVT_D_S(ctx->f14.fl);
    // 0x800A2EE8: add.d       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f2.d + ctx->f2.d;
    // 0x800A2EEC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A2EF0: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x800A2EF4: mul.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800A2EF8: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800A2EFC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A2F00: nop

    // 0x800A2F04: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A2F08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2F0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2F10: nop

    // 0x800A2F14: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A2F18: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800A2F1C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A2F20: b           L_800A3094
    // 0x800A2F24: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
        goto L_800A3094;
    // 0x800A2F24: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
L_800A2F28:
    // 0x800A2F28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A2F2C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A2F30: mul.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800A2F34: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A2F38: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800A2F3C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A2F40: nop

    // 0x800A2F44: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A2F48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2F4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2F50: nop

    // 0x800A2F54: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A2F58: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A2F5C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A2F60: b           L_800A3094
    // 0x800A2F64: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
        goto L_800A3094;
    // 0x800A2F64: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
L_800A2F68:
    // 0x800A2F68: jal         0x8006ECE0
    // 0x800A2F6C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    is_game_paused(rdram, ctx);
        goto after_5;
    // 0x800A2F6C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_5:
    // 0x800A2F70: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2F74: bne         $v0, $zero, L_800A3094
    if (ctx->r2 != 0) {
        // 0x800A2F78: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A3094;
    }
    // 0x800A2F78: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2F7C: addiu       $a1, $a1, 0x7329
    ctx->r5 = ADD32(ctx->r5, 0X7329);
    // 0x800A2F80: lb          $v0, 0x0($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X0);
    // 0x800A2F84: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x800A2F88: bgez        $v0, L_800A2FD4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A2F8C: nop
    
            goto L_800A2FD4;
    }
    // 0x800A2F8C: nop

    // 0x800A2F90: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x800A2F94: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    // 0x800A2F98: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A2F9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A2FA0: mflo        $v1
    ctx->r3 = lo;
    // 0x800A2FA4: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x800A2FA8: slt         $at, $t3, $a0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A2FAC: beq         $at, $zero, L_800A2FBC
    if (ctx->r1 == 0) {
        // 0x800A2FB0: addu        $t5, $a0, $v1
        ctx->r13 = ADD32(ctx->r4, ctx->r3);
            goto L_800A2FBC;
    }
    // 0x800A2FB0: addu        $t5, $a0, $v1
    ctx->r13 = ADD32(ctx->r4, ctx->r3);
    // 0x800A2FB4: b           L_800A3094
    // 0x800A2FB8: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
        goto L_800A3094;
    // 0x800A2FB8: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
L_800A2FBC:
    // 0x800A2FBC: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
    // 0x800A2FC0: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x800A2FC4: nop

    // 0x800A2FC8: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800A2FCC: b           L_800A3094
    // 0x800A2FD0: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
        goto L_800A3094;
    // 0x800A2FD0: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
L_800A2FD4:
    // 0x800A2FD4: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A2FD8: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x800A2FDC: mflo        $t2
    ctx->r10 = lo;
    // 0x800A2FE0: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800A2FE4: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
    // 0x800A2FE8: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x800A2FEC: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2FF0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800A2FF4: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x800A2FF8: lw          $t7, 0x44($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X44);
    // 0x800A2FFC: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x800A3000: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x800A3004: lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X4);
    // 0x800A3008: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A300C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800A3010: sll         $t2, $v1, 4
    ctx->r10 = S32(ctx->r3 << 4);
    // 0x800A3014: slt         $at, $t3, $t2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A3018: bne         $at, $zero, L_800A3098
    if (ctx->r1 != 0) {
        // 0x800A301C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3098;
    }
    // 0x800A301C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3020: lbu         $t5, 0x7328($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7328);
    // 0x800A3024: nop

    // 0x800A3028: beq         $t5, $zero, L_800A3048
    if (ctx->r13 == 0) {
        // 0x800A302C: nop
    
            goto L_800A3048;
    }
    // 0x800A302C: nop

    // 0x800A3030: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x800A3034: addiu       $t7, $t2, -0x1
    ctx->r15 = ADD32(ctx->r10, -0X1);
    // 0x800A3038: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x800A303C: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x800A3040: b           L_800A3094
    // 0x800A3044: sh          $t7, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r15;
        goto L_800A3094;
    // 0x800A3044: sh          $t7, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r15;
L_800A3048:
    // 0x800A3048: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800A304C: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3050: nop

    // 0x800A3054: lbu         $t9, 0x1FC($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X1FC);
    // 0x800A3058: nop

    // 0x800A305C: bne         $t9, $zero, L_800A3098
    if (ctx->r25 != 0) {
        // 0x800A3060: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3098;
    }
    // 0x800A3060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3064: lb          $t2, 0x1D8($t4)
    ctx->r10 = MEM_B(ctx->r12, 0X1D8);
    // 0x800A3068: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A306C: bne         $t2, $zero, L_800A3094
    if (ctx->r10 != 0) {
        // 0x800A3070: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A3094;
    }
    // 0x800A3070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A3074: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A3078: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A307C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800A3080: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800A3084: jal         0x800A3C14
    // 0x800A3088: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    hud_stopwatch_face(rdram, ctx);
        goto after_6;
    // 0x800A3088: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_6:
    // 0x800A308C: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A3090: nop

L_800A3094:
    // 0x800A3094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A3098:
    // 0x800A3098: jal         0x80061F70
    // 0x800A309C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    obj_animate(rdram, ctx);
        goto after_7;
    // 0x800A309C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_7:
    // 0x800A30A0: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A30A4: nop

L_800A30A8:
    // 0x800A30A8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A30AC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A30B0: addiu       $s2, $s2, 0x72BC
    ctx->r18 = ADD32(ctx->r18, 0X72BC);
    // 0x800A30B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A30B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A30BC: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A30C0: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A30C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A30C8: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A30CC: jal         0x800AAB5C
    // 0x800A30D0: addiu       $a3, $a3, 0x340
    ctx->r7 = ADD32(ctx->r7, 0X340);
    hud_element_render(rdram, ctx);
        goto after_8;
    // 0x800A30D0: addiu       $a3, $a3, 0x340
    ctx->r7 = ADD32(ctx->r7, 0X340);
    after_8:
    // 0x800A30D4: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x800A30D8: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A30DC: lb          $v1, 0x193($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X193);
    // 0x800A30E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A30E4: bltz        $v1, L_800A3118
    if (SIGNED(ctx->r3) < 0) {
        // 0x800A30E8: lui         $t8, 0x8000
        ctx->r24 = S32(0X8000 << 16);
            goto L_800A3118;
    }
    // 0x800A30E8: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800A30EC: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800A30F0: addu        $s0, $a1, $t5
    ctx->r16 = ADD32(ctx->r5, ctx->r13);
    // 0x800A30F4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800A30F8:
    // 0x800A30F8: lw          $t6, 0x128($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X128);
    // 0x800A30FC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800A3100: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800A3104: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A3108: bne         $at, $zero, L_800A3118
    if (ctx->r1 != 0) {
        // 0x800A310C: addu        $t1, $t1, $t6
        ctx->r9 = ADD32(ctx->r9, ctx->r14);
            goto L_800A3118;
    }
    // 0x800A310C: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x800A3110: bne         $t0, $v0, L_800A30F8
    if (ctx->r8 != ctx->r2) {
        // 0x800A3114: nop
    
            goto L_800A30F8;
    }
    // 0x800A3114: nop

L_800A3118:
    // 0x800A3118: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800A311C: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    // 0x800A3120: bne         $t8, $zero, L_800A316C
    if (ctx->r24 != 0) {
        // 0x800A3124: nop
    
            goto L_800A316C;
    }
    // 0x800A3124: nop

    // 0x800A3128: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800A312C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A3130: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A3134: lwc1        $f11, -0x7348($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X7348);
    // 0x800A3138: lwc1        $f10, -0x7344($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7344);
    // 0x800A313C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A3140: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800A3144: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A3148: nop

    // 0x800A314C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A3150: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A3154: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A3158: nop

    // 0x800A315C: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800A3160: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A3164: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800A3168: nop

L_800A316C:
    // 0x800A316C: jal         0x8000C8B4
    // 0x800A3170: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    normalise_time(rdram, ctx);
        goto after_9;
    // 0x800A3170: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_9:
    // 0x800A3174: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A3178: nop

    // 0x800A317C: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A3180: beq         $at, $zero, L_800A3198
    if (ctx->r1 == 0) {
        // 0x800A3184: addiu       $s0, $zero, 0x444
        ctx->r16 = ADD32(0, 0X444);
            goto L_800A3198;
    }
    // 0x800A3184: addiu       $s0, $zero, 0x444
    ctx->r16 = ADD32(0, 0X444);
    // 0x800A3188: jal         0x8000C8B4
    // 0x800A318C: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    normalise_time(rdram, ctx);
        goto after_10;
    // 0x800A318C: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    after_10:
    // 0x800A3190: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800A3194: addiu       $s0, $zero, 0x444
    ctx->r16 = ADD32(0, 0X444);
L_800A3198:
    // 0x800A3198: multu       $t1, $s0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A319C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800A31A0: mflo        $t9
    ctx->r25 = lo;
    // 0x800A31A4: addiu       $t4, $t9, 0x7FF8
    ctx->r12 = ADD32(ctx->r25, 0X7FF8);
    // 0x800A31A8: sh          $t4, 0x444($t2)
    MEM_H(0X444, ctx->r10) = ctx->r12;
    // 0x800A31AC: jal         0x8000E0B0
    // 0x800A31B0: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    get_contpak_error(rdram, ctx);
        goto after_11;
    // 0x800A31B0: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_11:
    // 0x800A31B4: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A31B8: bgtz        $v0, L_800A31F0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800A31BC: addiu       $v1, $zero, 0x3C
        ctx->r3 = ADD32(0, 0X3C);
            goto L_800A31F0;
    }
    // 0x800A31BC: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x800A31C0: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A31C4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A31C8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A31CC: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A31D0: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A31D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A31D8: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A31DC: jal         0x800AAB5C
    // 0x800A31E0: addiu       $a3, $a3, 0x440
    ctx->r7 = ADD32(ctx->r7, 0X440);
    hud_element_render(rdram, ctx);
        goto after_12;
    // 0x800A31E0: addiu       $a3, $a3, 0x440
    ctx->r7 = ADD32(ctx->r7, 0X440);
    after_12:
    // 0x800A31E4: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A31E8: nop

    // 0x800A31EC: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_800A31F0:
    // 0x800A31F0: div         $zero, $t1, $v1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r3)));
    // 0x800A31F4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800A31F8: bne         $v1, $zero, L_800A3204
    if (ctx->r3 != 0) {
        // 0x800A31FC: nop
    
            goto L_800A3204;
    }
    // 0x800A31FC: nop

    // 0x800A3200: break       7
    do_break(2148151808);
L_800A3204:
    // 0x800A3204: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A3208: bne         $v1, $at, L_800A321C
    if (ctx->r3 != ctx->r1) {
        // 0x800A320C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A321C;
    }
    // 0x800A320C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A3210: bne         $t1, $at, L_800A321C
    if (ctx->r9 != ctx->r1) {
        // 0x800A3214: nop
    
            goto L_800A321C;
    }
    // 0x800A3214: nop

    // 0x800A3218: break       6
    do_break(2148151832);
L_800A321C:
    // 0x800A321C: mflo        $t3
    ctx->r11 = lo;
    // 0x800A3220: addiu       $t5, $t3, 0x1E
    ctx->r13 = ADD32(ctx->r11, 0X1E);
    // 0x800A3224: nop

    // 0x800A3228: div         $zero, $t5, $v1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r3)));
    // 0x800A322C: bne         $v1, $zero, L_800A3238
    if (ctx->r3 != 0) {
        // 0x800A3230: nop
    
            goto L_800A3238;
    }
    // 0x800A3230: nop

    // 0x800A3234: break       7
    do_break(2148151860);
L_800A3238:
    // 0x800A3238: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A323C: bne         $v1, $at, L_800A3250
    if (ctx->r3 != ctx->r1) {
        // 0x800A3240: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A3250;
    }
    // 0x800A3240: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A3244: bne         $t5, $at, L_800A3250
    if (ctx->r13 != ctx->r1) {
        // 0x800A3248: nop
    
            goto L_800A3250;
    }
    // 0x800A3248: nop

    // 0x800A324C: break       6
    do_break(2148151884);
L_800A3250:
    // 0x800A3250: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800A3254: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A3258: mfhi        $t1
    ctx->r9 = hi;
    // 0x800A325C: nop

    // 0x800A3260: nop

    // 0x800A3264: multu       $t1, $s0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A3268: mflo        $t6
    ctx->r14 = lo;
    // 0x800A326C: sh          $t6, 0x444($t8)
    MEM_H(0X444, ctx->r24) = ctx->r14;
    // 0x800A3270: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A3274: nop

    // 0x800A3278: lwc1        $f8, 0x350($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X350);
    // 0x800A327C: nop

    // 0x800A3280: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A3284: jal         0x8000E0B0
    // 0x800A3288: swc1        $f4, 0x450($v0)
    MEM_W(0X450, ctx->r2) = ctx->f4.u32l;
    get_contpak_error(rdram, ctx);
        goto after_13;
    // 0x800A3288: swc1        $f4, 0x450($v0)
    MEM_W(0X450, ctx->r2) = ctx->f4.u32l;
    after_13:
    // 0x800A328C: bgtz        $v0, L_800A32B8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800A3290: lw          $t7, 0x98($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X98);
            goto L_800A32B8;
    }
    // 0x800A3290: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x800A3294: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A3298: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A329C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A32A0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A32A4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A32A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A32AC: jal         0x800AAB5C
    // 0x800A32B0: addiu       $a3, $a3, 0x440
    ctx->r7 = ADD32(ctx->r7, 0X440);
    hud_element_render(rdram, ctx);
        goto after_14;
    // 0x800A32B0: addiu       $a3, $a3, 0x440
    ctx->r7 = ADD32(ctx->r7, 0X440);
    after_14:
    // 0x800A32B4: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
L_800A32B8:
    // 0x800A32B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A32BC: jal         0x80068748
    // 0x800A32C0: sb          $zero, 0x20($t7)
    MEM_B(0X20, ctx->r15) = 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_15;
    // 0x800A32C0: sb          $zero, 0x20($t7)
    MEM_B(0X20, ctx->r15) = 0;
    after_15:
    // 0x800A32C4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A32C8: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A32CC: jal         0x800A13F4
    // 0x800A32D0: nop

    hud_course_arrows(rdram, ctx);
        goto after_16;
    // 0x800A32D0: nop

    after_16:
    // 0x800A32D4: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800A32D8: nop

    // 0x800A32DC: lb          $t9, 0x1D8($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A32E0: nop

    // 0x800A32E4: bne         $t9, $zero, L_800A3618
    if (ctx->r25 != 0) {
        // 0x800A32E8: nop
    
            goto L_800A3618;
    }
    // 0x800A32E8: nop

    // 0x800A32EC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A32F0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800A32F4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A32F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A32FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A3300: lwc1        $f6, 0x2F0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X2F0);
    // 0x800A3304: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A3308: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A330C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A3310: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800A3314: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A3318: sw          $t3, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r11;
    // 0x800A331C: lb          $t5, 0x194($t1)
    ctx->r13 = MEM_B(ctx->r9, 0X194);
    // 0x800A3320: nop

    // 0x800A3324: blez        $t5, L_800A34C4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A3328: sll         $t5, $t0, 2
        ctx->r13 = S32(ctx->r8 << 2);
            goto L_800A34C4;
    }
    // 0x800A3328: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800A332C: lw          $t6, 0x7320($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7320);
    // 0x800A3330: sll         $v0, $zero, 2
    ctx->r2 = S32(0 << 2);
    // 0x800A3334: lb          $t8, 0x4B($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X4B);
    // 0x800A3338: addu        $s0, $t1, $v0
    ctx->r16 = ADD32(ctx->r9, ctx->r2);
    // 0x800A333C: blez        $t8, L_800A34C0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800A3340: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800A34C0;
    }
    // 0x800A3340: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800A3344: addiu       $t7, $t7, 0x2D2C
    ctx->r15 = ADD32(ctx->r15, 0X2D2C);
    // 0x800A3348: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x800A334C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_800A3350:
    // 0x800A3350: lw          $a0, 0x128($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X128);
    // 0x800A3354: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x800A3358: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800A335C: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x800A3360: jal         0x800597E0
    // 0x800A3364: addiu       $a3, $sp, 0xAC
    ctx->r7 = ADD32(ctx->r29, 0XAC);
    get_timestamp_from_frames(rdram, ctx);
        goto after_17;
    // 0x800A3364: addiu       $a3, $sp, 0xAC
    ctx->r7 = ADD32(ctx->r29, 0XAC);
    after_17:
    // 0x800A3368: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800A336C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A3370: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x800A3374: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A3378: sw          $t2, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r10;
    // 0x800A337C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800A3380: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A3384: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A3388: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A338C: lwc1        $f10, 0x2EC($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X2EC);
    // 0x800A3390: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800A3394: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A3398: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    // 0x800A339C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800A33A0: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x800A33A4: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    // 0x800A33A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A33AC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A33B0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800A33B4: jal         0x800A8518
    // 0x800A33B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    hud_timer_render(rdram, ctx);
        goto after_18;
    // 0x800A33B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_18:
    // 0x800A33BC: addiu       $t7, $zero, -0x2
    ctx->r15 = ADD32(0, -0X2);
    // 0x800A33C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A33C4: sw          $t7, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r15;
    // 0x800A33C8: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x800A33CC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800A33D0: addiu       $t4, $t9, 0xC
    ctx->r12 = ADD32(ctx->r25, 0XC);
    // 0x800A33D4: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800A33D8: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x800A33DC: sw          $t4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r12;
    // 0x800A33E0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800A33E4: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A33E8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A33EC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800A33F0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800A33F4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800A33F8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800A33FC: sh          $t1, 0x338($t6)
    MEM_H(0X338, ctx->r14) = ctx->r9;
    // 0x800A3400: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A3404: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3408: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A340C: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A3410: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A3414: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x800A3418: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A341C: jal         0x800AAB5C
    // 0x800A3420: addiu       $a3, $a3, 0x320
    ctx->r7 = ADD32(ctx->r7, 0X320);
    hud_element_render(rdram, ctx);
        goto after_19;
    // 0x800A3420: addiu       $a3, $a3, 0x320
    ctx->r7 = ADD32(ctx->r7, 0X320);
    after_19:
    // 0x800A3424: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A3428: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A342C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3430: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A3434: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A3438: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A343C: jal         0x800AAB5C
    // 0x800A3440: addiu       $a3, $a3, 0x300
    ctx->r7 = ADD32(ctx->r7, 0X300);
    hud_element_render(rdram, ctx);
        goto after_20;
    // 0x800A3440: addiu       $a3, $a3, 0x300
    ctx->r7 = ADD32(ctx->r7, 0X300);
    after_20:
    // 0x800A3444: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A3448: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800A344C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A3450: lwc1        $f6, 0x330($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X330);
    // 0x800A3454: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A3458: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A345C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A3460: swc1        $f8, 0x330($v0)
    MEM_W(0X330, ctx->r2) = ctx->f8.u32l;
    // 0x800A3464: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A3468: nop

    // 0x800A346C: lwc1        $f10, 0x310($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X310);
    // 0x800A3470: nop

    // 0x800A3474: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A3478: swc1        $f4, 0x310($v0)
    MEM_W(0X310, ctx->r2) = ctx->f4.u32l;
    // 0x800A347C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800A3480: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3484: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x800A3488: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x800A348C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800A3490: lb          $t4, 0x194($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X194);
    // 0x800A3494: nop

    // 0x800A3498: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800A349C: beq         $at, $zero, L_800A34C4
    if (ctx->r1 == 0) {
        // 0x800A34A0: sll         $t5, $t0, 2
        ctx->r13 = S32(ctx->r8 << 2);
            goto L_800A34C4;
    }
    // 0x800A34A0: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800A34A4: lw          $t2, 0x7320($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7320);
    // 0x800A34A8: nop

    // 0x800A34AC: lb          $t3, 0x4B($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X4B);
    // 0x800A34B0: nop

    // 0x800A34B4: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800A34B8: bne         $at, $zero, L_800A3350
    if (ctx->r1 != 0) {
        // 0x800A34BC: nop
    
            goto L_800A3350;
    }
    // 0x800A34BC: nop

L_800A34C0:
    // 0x800A34C0: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
L_800A34C4:
    // 0x800A34C4: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800A34C8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A34CC: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800A34D0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A34D4: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A34D8: lwc1        $f8, 0x330($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X330);
    // 0x800A34DC: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800A34E0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A34E4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A34E8: swc1        $f10, 0x330($v0)
    MEM_W(0X330, ctx->r2) = ctx->f10.u32l;
    // 0x800A34EC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A34F0: addiu       $s0, $s0, 0x730C
    ctx->r16 = ADD32(ctx->r16, 0X730C);
    // 0x800A34F4: lwc1        $f4, 0x310($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X310);
    // 0x800A34F8: nop

    // 0x800A34FC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A3500: swc1        $f6, 0x310($v0)
    MEM_W(0X310, ctx->r2) = ctx->f6.u32l;
    // 0x800A3504: lbu         $t6, 0x1EF($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X1EF);
    // 0x800A3508: nop

    // 0x800A350C: andi        $t8, $t6, 0x4
    ctx->r24 = ctx->r14 & 0X4;
    // 0x800A3510: beq         $t8, $zero, L_800A3554
    if (ctx->r24 == 0) {
        // 0x800A3514: nop
    
            goto L_800A3554;
    }
    // 0x800A3514: nop

    // 0x800A3518: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A351C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800A3520: bgtz        $t7, L_800A3554
    if (SIGNED(ctx->r15) > 0) {
        // 0x800A3524: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_800A3554;
    }
    // 0x800A3524: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A3528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A352C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800A3530: jal         0x800A3C14
    // 0x800A3534: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    hud_stopwatch_face(rdram, ctx);
        goto after_21;
    // 0x800A3534: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_21:
    // 0x800A3538: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800A353C: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x800A3540: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800A3544: lbu         $t2, 0x1EF($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1EF);
    // 0x800A3548: nop

    // 0x800A354C: andi        $t3, $t2, 0xFFFB
    ctx->r11 = ctx->r10 & 0XFFFB;
    // 0x800A3550: sb          $t3, 0x1EF($t1)
    MEM_B(0X1EF, ctx->r9) = ctx->r11;
L_800A3554:
    // 0x800A3554: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A3558: addiu       $s0, $s0, 0x730C
    ctx->r16 = ADD32(ctx->r16, 0X730C);
    // 0x800A355C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A3560: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3564: blez        $v0, L_800A3580
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A3568: subu        $t6, $v0, $t5
        ctx->r14 = SUB32(ctx->r2, ctx->r13);
            goto L_800A3580;
    }
    // 0x800A3568: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x800A356C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800A3570: bgez        $t6, L_800A3580
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800A3574: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800A3580;
    }
    // 0x800A3574: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800A3578: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800A357C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A3580:
    // 0x800A3580: bne         $v0, $zero, L_800A3618
    if (ctx->r2 != 0) {
        // 0x800A3584: nop
    
            goto L_800A3618;
    }
    // 0x800A3584: nop

    // 0x800A3588: lb          $t8, 0x1D8($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A358C: addiu       $t7, $zero, -0x64
    ctx->r15 = ADD32(0, -0X64);
    // 0x800A3590: bne         $t8, $zero, L_800A3618
    if (ctx->r24 != 0) {
        // 0x800A3594: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A3618;
    }
    // 0x800A3594: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A3598: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800A359C: lw          $t9, 0x7300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7300);
    // 0x800A35A0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A35A4: bne         $t9, $zero, L_800A3618
    if (ctx->r25 != 0) {
        // 0x800A35A8: addiu       $s0, $s0, 0x7324
        ctx->r16 = ADD32(ctx->r16, 0X7324);
            goto L_800A3618;
    }
    // 0x800A35A8: addiu       $s0, $s0, 0x7324
    ctx->r16 = ADD32(ctx->r16, 0X7324);
    // 0x800A35AC: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x800A35B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A35B4: jal         0x8006FB8C
    // 0x800A35B8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    rand_range(rdram, ctx);
        goto after_22;
    // 0x800A35B8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_22:
    // 0x800A35BC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A35C0: addiu       $s1, $s1, 0x7308
    ctx->r17 = ADD32(ctx->r17, 0X7308);
    // 0x800A35C4: lhu         $t2, 0x0($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X0);
    // 0x800A35C8: addiu       $v1, $v0, 0x14B
    ctx->r3 = ADD32(ctx->r2, 0X14B);
    // 0x800A35CC: andi        $t3, $v1, 0xFFFF
    ctx->r11 = ctx->r3 & 0XFFFF;
    // 0x800A35D0: bne         $t2, $t3, L_800A35FC
    if (ctx->r10 != ctx->r11) {
        // 0x800A35D4: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_800A35FC;
    }
    // 0x800A35D4: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_800A35D8:
    // 0x800A35D8: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x800A35DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A35E0: jal         0x8006FB8C
    // 0x800A35E4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    rand_range(rdram, ctx);
        goto after_23;
    // 0x800A35E4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_23:
    // 0x800A35E8: lhu         $t4, 0x0($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X0);
    // 0x800A35EC: addiu       $v1, $v0, 0x14B
    ctx->r3 = ADD32(ctx->r2, 0X14B);
    // 0x800A35F0: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x800A35F4: beq         $t4, $t5, L_800A35D8
    if (ctx->r12 == ctx->r13) {
        // 0x800A35F8: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_800A35D8;
    }
    // 0x800A35F8: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_800A35FC:
    // 0x800A35FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3600: sh          $a0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r4;
    // 0x800A3604: jal         0x80001D04
    // 0x800A3608: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_24;
    // 0x800A3608: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_24:
    // 0x800A360C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A3610: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3614: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
L_800A3618:
    // 0x800A3618: lb          $v1, 0x193($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X193);
    // 0x800A361C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A3620: blez        $v1, L_800A3728
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A3624: addiu       $s1, $s1, 0x7308
        ctx->r17 = ADD32(ctx->r17, 0X7308);
            goto L_800A3728;
    }
    // 0x800A3624: addiu       $s1, $s1, 0x7308
    ctx->r17 = ADD32(ctx->r17, 0X7308);
    // 0x800A3628: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A362C: lw          $t8, 0x7320($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7320);
    // 0x800A3630: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800A3634: lb          $t7, 0x4B($t8)
    ctx->r15 = MEM_B(ctx->r24, 0X4B);
    // 0x800A3638: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x800A363C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800A3640: beq         $at, $zero, L_800A3728
    if (ctx->r1 == 0) {
        // 0x800A3644: nop
    
            goto L_800A3728;
    }
    // 0x800A3644: nop

    // 0x800A3648: lw          $t3, 0x128($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X128);
    // 0x800A364C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A3650: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x800A3654: beq         $at, $zero, L_800A3728
    if (ctx->r1 == 0) {
        // 0x800A3658: nop
    
            goto L_800A3728;
    }
    // 0x800A3658: nop

    // 0x800A365C: lw          $t4, 0x7300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7300);
    // 0x800A3660: nop

    // 0x800A3664: bne         $t4, $zero, L_800A3728
    if (ctx->r12 != 0) {
        // 0x800A3668: nop
    
            goto L_800A3728;
    }
    // 0x800A3668: nop

    // 0x800A366C: lb          $t5, 0x1D6($t1)
    ctx->r13 = MEM_B(ctx->r9, 0X1D6);
    // 0x800A3670: nop

    // 0x800A3674: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x800A3678: beq         $at, $zero, L_800A3728
    if (ctx->r1 == 0) {
        // 0x800A367C: nop
    
            goto L_800A3728;
    }
    // 0x800A367C: nop

    // 0x800A3680: jal         0x8006ECD0
    // 0x800A3684: nop

    get_settings(rdram, ctx);
        goto after_25;
    // 0x800A3684: nop

    after_25:
    // 0x800A3688: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A368C: addiu       $s0, $s0, 0x7744
    ctx->r16 = ADD32(ctx->r16, 0X7744);
    // 0x800A3690: jal         0x8006BFC8
    // 0x800A3694: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    level_id(rdram, ctx);
        goto after_26;
    // 0x800A3694: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    after_26:
    // 0x800A3698: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x800A369C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A36A0: lb          $v1, 0x193($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X193);
    // 0x800A36A4: lb          $t2, 0x1D6($t6)
    ctx->r10 = MEM_B(ctx->r14, 0X1D6);
    // 0x800A36A8: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800A36AC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A36B0: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800A36B4: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800A36B8: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x800A36BC: lw          $a0, 0x124($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X124);
    // 0x800A36C0: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800A36C4: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800A36C8: lhu         $t2, 0x0($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X0);
    // 0x800A36CC: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x800A36D0: slt         $at, $a0, $t2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A36D4: beq         $at, $zero, L_800A3728
    if (ctx->r1 == 0) {
        // 0x800A36D8: nop
    
            goto L_800A3728;
    }
    // 0x800A36D8: nop

    // 0x800A36DC: blez        $a1, L_800A3714
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800A36E0: or          $t1, $a0, $zero
        ctx->r9 = ctx->r4 | 0;
            goto L_800A3714;
    }
    // 0x800A36E0: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800A36E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A36E8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800A36EC: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
L_800A36F0:
    // 0x800A36F0: lw          $t9, 0x128($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X128);
    // 0x800A36F4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A36F8: slt         $at, $t1, $t9
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A36FC: bne         $at, $zero, L_800A370C
    if (ctx->r1 != 0) {
        // 0x800A3700: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800A370C;
    }
    // 0x800A3700: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A3704: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800A3708: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800A370C:
    // 0x800A370C: bne         $at, $zero, L_800A36F0
    if (ctx->r1 != 0) {
        // 0x800A3710: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A36F0;
    }
    // 0x800A3710: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800A3714:
    // 0x800A3714: beq         $t1, $zero, L_800A3728
    if (ctx->r9 == 0) {
        // 0x800A3718: addiu       $a0, $zero, 0x144
        ctx->r4 = ADD32(0, 0X144);
            goto L_800A3728;
    }
    // 0x800A3718: addiu       $a0, $zero, 0x144
    ctx->r4 = ADD32(0, 0X144);
    // 0x800A371C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3720: jal         0x80001D04
    // 0x800A3724: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_27;
    // 0x800A3724: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_27:
L_800A3728:
    // 0x800A3728: jal         0x8001B2BC
    // 0x800A372C: nop

    timetrial_valid_player_ghost(rdram, ctx);
        goto after_28;
    // 0x800A372C: nop

    after_28:
    // 0x800A3730: beq         $v0, $zero, L_800A3870
    if (ctx->r2 == 0) {
        // 0x800A3734: lw          $t2, 0xA0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XA0);
            goto L_800A3870;
    }
    // 0x800A3734: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3738: jal         0x8001B314
    // 0x800A373C: nop

    timetrial_player_ghost(rdram, ctx);
        goto after_29;
    // 0x800A373C: nop

    after_29:
    // 0x800A3740: beq         $v0, $zero, L_800A386C
    if (ctx->r2 == 0) {
        // 0x800A3744: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800A386C;
    }
    // 0x800A3744: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A3748: jal         0x8001139C
    // 0x800A374C: nop

    get_race_countdown(rdram, ctx);
        goto after_30;
    // 0x800A374C: nop

    after_30:
    // 0x800A3750: bne         $v0, $zero, L_800A3870
    if (ctx->r2 != 0) {
        // 0x800A3754: lw          $t2, 0xA0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XA0);
            goto L_800A3870;
    }
    // 0x800A3754: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3758: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x800A375C: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A3760: lb          $t4, 0x1D8($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X1D8);
    // 0x800A3764: nop

    // 0x800A3768: bne         $t4, $zero, L_800A3870
    if (ctx->r12 != 0) {
        // 0x800A376C: lw          $t2, 0xA0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XA0);
            goto L_800A3870;
    }
    // 0x800A376C: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3770: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A3774: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800A3778: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800A377C: lwc1        $f6, 0x10($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800A3780: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A3784: lwc1        $f10, 0x14($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X14);
    // 0x800A3788: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A378C: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800A3790: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800A3794: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A3798: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800A379C: nop

    // 0x800A37A0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800A37A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A37A8: jal         0x800CA030
    // 0x800A37AC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_31;
    // 0x800A37AC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_31:
    // 0x800A37B0: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x800A37B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A37B8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A37BC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800A37C0: nop

    // 0x800A37C4: bc1f        L_800A3848
    if (!c1cs) {
        // 0x800A37C8: nop
    
            goto L_800A3848;
    }
    // 0x800A37C8: nop

    // 0x800A37CC: lw          $t8, 0x7300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7300);
    // 0x800A37D0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A37D4: bne         $t8, $zero, L_800A3848
    if (ctx->r24 != 0) {
        // 0x800A37D8: addiu       $s0, $s0, 0x7310
        ctx->r16 = ADD32(ctx->r16, 0X7310);
            goto L_800A3848;
    }
    // 0x800A37D8: addiu       $s0, $s0, 0x7310
    ctx->r16 = ADD32(ctx->r16, 0X7310);
    // 0x800A37DC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A37E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A37E4: bne         $t7, $zero, L_800A3848
    if (ctx->r15 != 0) {
        // 0x800A37E8: nop
    
            goto L_800A3848;
    }
    // 0x800A37E8: nop

    // 0x800A37EC: jal         0x8006FB8C
    // 0x800A37F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    rand_range(rdram, ctx);
        goto after_32;
    // 0x800A37F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_32:
    // 0x800A37F4: lhu         $t2, 0x0($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X0);
    // 0x800A37F8: addiu       $v1, $v0, 0x147
    ctx->r3 = ADD32(ctx->r2, 0X147);
    // 0x800A37FC: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800A3800: bne         $t2, $t6, L_800A3828
    if (ctx->r10 != ctx->r14) {
        // 0x800A3804: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_800A3828;
    }
    // 0x800A3804: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_800A3808:
    // 0x800A3808: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A380C: jal         0x8006FB8C
    // 0x800A3810: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    rand_range(rdram, ctx);
        goto after_33;
    // 0x800A3810: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_33:
    // 0x800A3814: lhu         $t9, 0x0($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X0);
    // 0x800A3818: addiu       $v1, $v0, 0x147
    ctx->r3 = ADD32(ctx->r2, 0X147);
    // 0x800A381C: andi        $t3, $v1, 0xFFFF
    ctx->r11 = ctx->r3 & 0XFFFF;
    // 0x800A3820: beq         $t9, $t3, L_800A3808
    if (ctx->r25 == ctx->r11) {
        // 0x800A3824: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_800A3808;
    }
    // 0x800A3824: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_800A3828:
    // 0x800A3828: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A382C: sh          $a0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r4;
    // 0x800A3830: jal         0x80001D04
    // 0x800A3834: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_34;
    // 0x800A3834: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_34:
    // 0x800A3838: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x800A383C: jal         0x8006FB8C
    // 0x800A3840: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    rand_range(rdram, ctx);
        goto after_35;
    // 0x800A3840: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    after_35:
    // 0x800A3844: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800A3848:
    // 0x800A3848: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A384C: addiu       $s0, $s0, 0x7310
    ctx->r16 = ADD32(ctx->r16, 0X7310);
    // 0x800A3850: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A3854: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3858: nop

    // 0x800A385C: subu        $t8, $t4, $t5
    ctx->r24 = SUB32(ctx->r12, ctx->r13);
    // 0x800A3860: bgez        $t8, L_800A386C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A3864: sw          $t8, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r24;
            goto L_800A386C;
    }
    // 0x800A3864: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800A3868: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800A386C:
    // 0x800A386C: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
L_800A3870:
    // 0x800A3870: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3874: lb          $v1, 0x193($t2)
    ctx->r3 = MEM_B(ctx->r10, 0X193);
    // 0x800A3878: nop

    // 0x800A387C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800A3880: addu        $t9, $t2, $t6
    ctx->r25 = ADD32(ctx->r10, ctx->r14);
    // 0x800A3884: lw          $t3, 0x128($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X128);
    // 0x800A3888: nop

    // 0x800A388C: slti        $at, $t3, 0x1E
    ctx->r1 = SIGNED(ctx->r11) < 0X1E ? 1 : 0;
    // 0x800A3890: beq         $at, $zero, L_800A38BC
    if (ctx->r1 == 0) {
        // 0x800A3894: nop
    
            goto L_800A38BC;
    }
    // 0x800A3894: nop

    // 0x800A3898: beq         $v1, $zero, L_800A38BC
    if (ctx->r3 == 0) {
        // 0x800A389C: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_800A38BC;
    }
    // 0x800A389C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800A38A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A38A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A38A8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800A38AC: jal         0x800A3C14
    // 0x800A38B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    hud_stopwatch_face(rdram, ctx);
        goto after_36;
    // 0x800A38B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_36:
    // 0x800A38B4: b           L_800A3910
    // 0x800A38B8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
        goto L_800A3910;
    // 0x800A38B8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
L_800A38BC:
    // 0x800A38BC: lb          $t5, 0x1D3($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X1D3);
    // 0x800A38C0: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x800A38C4: blez        $t5, L_800A38E8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A38C8: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_800A38E8;
    }
    // 0x800A38C8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800A38CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A38D0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800A38D4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800A38D8: jal         0x800A3C14
    // 0x800A38DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    hud_stopwatch_face(rdram, ctx);
        goto after_37;
    // 0x800A38DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_37:
    // 0x800A38E0: b           L_800A3910
    // 0x800A38E4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
        goto L_800A3910;
    // 0x800A38E4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
L_800A38E8:
    // 0x800A38E8: lbu         $t7, 0x1FC($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X1FC);
    // 0x800A38EC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800A38F0: slti        $at, $t7, 0x79
    ctx->r1 = SIGNED(ctx->r15) < 0X79 ? 1 : 0;
    // 0x800A38F4: bne         $at, $zero, L_800A390C
    if (ctx->r1 != 0) {
        // 0x800A38F8: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_800A390C;
    }
    // 0x800A38F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A38FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A3900: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800A3904: jal         0x800A3C14
    // 0x800A3908: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    hud_stopwatch_face(rdram, ctx);
        goto after_38;
    // 0x800A3908: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_38:
L_800A390C:
    // 0x800A390C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
L_800A3910:
    // 0x800A3910: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3914: jal         0x800A5498
    // 0x800A3918: nop

    hud_lap_count(rdram, ctx);
        goto after_39;
    // 0x800A3918: nop

    after_39:
    // 0x800A391C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3920: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3924: jal         0x800A80C4
    // 0x800A3928: nop

    hud_race_time(rdram, ctx);
        goto after_40;
    // 0x800A3928: nop

    after_40:
    // 0x800A392C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3930: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3934: jal         0x800A469C
    // 0x800A3938: nop

    hud_bananas(rdram, ctx);
        goto after_41;
    // 0x800A3938: nop

    after_41:
    // 0x800A393C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3940: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3944: jal         0x800A5FAC
    // 0x800A3948: nop

    hud_wrong_way(rdram, ctx);
        goto after_42;
    // 0x800A3948: nop

    after_42:
    // 0x800A394C: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800A3950: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3954: jal         0x800A422C
    // 0x800A3958: nop

    hud_race_start(rdram, ctx);
        goto after_43;
    // 0x800A3958: nop

    after_43:
    // 0x800A395C: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    // 0x800A3960: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3964: jal         0x800A3DCC
    // 0x800A3968: nop

    hud_speedometre(rdram, ctx);
        goto after_44;
    // 0x800A3968: nop

    after_44:
    // 0x800A396C: jal         0x8000E0B0
    // 0x800A3970: nop

    get_contpak_error(rdram, ctx);
        goto after_45;
    // 0x800A3970: nop

    after_45:
    // 0x800A3974: blez        $v0, L_800A3BF4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A3978: nop
    
            goto L_800A3BF4;
    }
    // 0x800A3978: nop

    // 0x800A397C: jal         0x8000E0B0
    // 0x800A3980: nop

    get_contpak_error(rdram, ctx);
        goto after_46;
    // 0x800A3980: nop

    after_46:
    // 0x800A3984: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A3988: beq         $v0, $at, L_800A39B4
    if (ctx->r2 == ctx->r1) {
        // 0x800A398C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A39B4;
    }
    // 0x800A398C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A3990: beq         $v0, $at, L_800A39DC
    if (ctx->r2 == ctx->r1) {
        // 0x800A3994: lui         $t3, 0x800F
        ctx->r11 = S32(0X800F << 16);
            goto L_800A39DC;
    }
    // 0x800A3994: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800A3998: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A399C: beq         $v0, $at, L_800A3A00
    if (ctx->r2 == ctx->r1) {
        // 0x800A39A0: lui         $t8, 0x800F
        ctx->r24 = S32(0X800F << 16);
            goto L_800A3A00;
    }
    // 0x800A39A0: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800A39A4: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800A39A8: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x800A39AC: b           L_800A3A20
    // 0x800A39B0: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
        goto L_800A3A20;
    // 0x800A39B0: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_800A39B4:
    // 0x800A39B4: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800A39B8: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800A39BC: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800A39C0: addiu       $t2, $t2, -0x7430
    ctx->r10 = ADD32(ctx->r10, -0X7430);
    // 0x800A39C4: addiu       $t6, $t6, -0x7428
    ctx->r14 = ADD32(ctx->r14, -0X7428);
    // 0x800A39C8: addiu       $t9, $t9, -0x7420
    ctx->r25 = ADD32(ctx->r25, -0X7420);
    // 0x800A39CC: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800A39D0: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x800A39D4: b           L_800A3A20
    // 0x800A39D8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
        goto L_800A3A20;
    // 0x800A39D8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_800A39DC:
    // 0x800A39DC: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800A39E0: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800A39E4: addiu       $t3, $t3, -0x7418
    ctx->r11 = ADD32(ctx->r11, -0X7418);
    // 0x800A39E8: addiu       $t4, $t4, -0x740C
    ctx->r12 = ADD32(ctx->r12, -0X740C);
    // 0x800A39EC: addiu       $t5, $t5, -0x7408
    ctx->r13 = ADD32(ctx->r13, -0X7408);
    // 0x800A39F0: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x800A39F4: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x800A39F8: b           L_800A3A20
    // 0x800A39FC: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
        goto L_800A3A20;
    // 0x800A39FC: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
L_800A3A00:
    // 0x800A3A00: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800A3A04: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800A3A08: addiu       $t8, $t8, -0x7400
    ctx->r24 = ADD32(ctx->r24, -0X7400);
    // 0x800A3A0C: addiu       $t7, $t7, -0x73F4
    ctx->r15 = ADD32(ctx->r15, -0X73F4);
    // 0x800A3A10: addiu       $t2, $t2, -0x73F0
    ctx->r10 = ADD32(ctx->r10, -0X73F0);
    // 0x800A3A14: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800A3A18: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x800A3A1C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
L_800A3A20:
    // 0x800A3A20: jal         0x800C46C4
    // 0x800A3A24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_kerning(rdram, ctx);
        goto after_47;
    // 0x800A3A24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_47:
    // 0x800A3A28: jal         0x800C484C
    // 0x800A3A2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_48;
    // 0x800A3A2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_48:
    // 0x800A3A30: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A3A34: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A3A38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A3A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A3A40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A3A44: jal         0x800C48E4
    // 0x800A3A48: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_49;
    // 0x800A3A48: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_49:
    // 0x800A3A4C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A3A50: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A3A54: addiu       $s1, $s1, 0x72E4
    ctx->r17 = ADD32(ctx->r17, 0X72E4);
    // 0x800A3A58: addiu       $s0, $s0, 0x774C
    ctx->r16 = ADD32(ctx->r16, 0X774C);
    // 0x800A3A5C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A3A60: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800A3A64: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3A68: lw          $t5, 0x72E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72E8);
    // 0x800A3A6C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3A70: lw          $a2, 0x7750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7750);
    // 0x800A3A74: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800A3A78: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x800A3A7C: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800A3A80: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800A3A84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A3A88: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A3A8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3A90: jal         0x800C49A0
    // 0x800A3A94: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    draw_text(rdram, ctx);
        goto after_50;
    // 0x800A3A94: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_50:
    // 0x800A3A98: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A3A9C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800A3AA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A3AA4: lw          $t9, 0x72E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72E8);
    // 0x800A3AA8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3AAC: lw          $a2, 0x7750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7750);
    // 0x800A3AB0: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x800A3AB4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800A3AB8: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x800A3ABC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    // 0x800A3AC0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A3AC4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A3AC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3ACC: jal         0x800C49A0
    // 0x800A3AD0: addiu       $a2, $a2, 0xF
    ctx->r6 = ADD32(ctx->r6, 0XF);
    draw_text(rdram, ctx);
        goto after_51;
    // 0x800A3AD0: addiu       $a2, $a2, 0xF
    ctx->r6 = ADD32(ctx->r6, 0XF);
    after_51:
    // 0x800A3AD4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A3AD8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800A3ADC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A3AE0: lw          $t7, 0x72E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72E8);
    // 0x800A3AE4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3AE8: lw          $a2, 0x7750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7750);
    // 0x800A3AEC: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x800A3AF0: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800A3AF4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800A3AF8: addu        $a1, $t8, $t7
    ctx->r5 = ADD32(ctx->r24, ctx->r15);
    // 0x800A3AFC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A3B00: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A3B04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3B08: jal         0x800C49A0
    // 0x800A3B0C: addiu       $a2, $a2, 0x1D
    ctx->r6 = ADD32(ctx->r6, 0X1D);
    draw_text(rdram, ctx);
        goto after_52;
    // 0x800A3B0C: addiu       $a2, $a2, 0x1D
    ctx->r6 = ADD32(ctx->r6, 0X1D);
    after_52:
    // 0x800A3B10: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A3B14: lw          $v0, 0x7754($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7754);
    // 0x800A3B18: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800A3B1C: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x800A3B20: lbu         $a0, 0x10($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X10);
    // 0x800A3B24: lbu         $a1, 0x11($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X11);
    // 0x800A3B28: lbu         $a2, 0x12($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X12);
    // 0x800A3B2C: jal         0x800C48E4
    // 0x800A3B30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    set_text_colour(rdram, ctx);
        goto after_53;
    // 0x800A3B30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_53:
    // 0x800A3B34: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A3B38: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800A3B3C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3B40: lw          $t5, 0x72E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72E8);
    // 0x800A3B44: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3B48: lw          $a2, 0x7750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7750);
    // 0x800A3B4C: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x800A3B50: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800A3B54: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800A3B58: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A3B5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3B60: jal         0x800C49A0
    // 0x800A3B64: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    draw_text(rdram, ctx);
        goto after_54;
    // 0x800A3B64: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_54:
    // 0x800A3B68: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A3B6C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800A3B70: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A3B74: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3B78: lw          $a2, 0x7750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7750);
    // 0x800A3B7C: lw          $t9, 0x72E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72E8);
    // 0x800A3B80: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800A3B84: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x800A3B88: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x800A3B8C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A3B90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3B94: addiu       $a2, $a2, 0xE
    ctx->r6 = ADD32(ctx->r6, 0XE);
    // 0x800A3B98: jal         0x800C49A0
    // 0x800A3B9C: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    draw_text(rdram, ctx);
        goto after_55;
    // 0x800A3B9C: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    after_55:
    // 0x800A3BA0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A3BA4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800A3BA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A3BAC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3BB0: lw          $a2, 0x7750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7750);
    // 0x800A3BB4: lw          $t7, 0x72E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72E8);
    // 0x800A3BB8: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800A3BBC: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800A3BC0: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x800A3BC4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A3BC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3BCC: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    // 0x800A3BD0: jal         0x800C49A0
    // 0x800A3BD4: addu        $a1, $t8, $t7
    ctx->r5 = ADD32(ctx->r24, ctx->r15);
    draw_text(rdram, ctx);
        goto after_56;
    // 0x800A3BD4: addu        $a1, $t8, $t7
    ctx->r5 = ADD32(ctx->r24, ctx->r15);
    after_56:
    // 0x800A3BD8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3BDC: lw          $a0, 0x7754($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7754);
    // 0x800A3BE0: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3BE4: jal         0x8007F69C
    // 0x800A3BE8: nop

    update_colour_cycle(rdram, ctx);
        goto after_57;
    // 0x800A3BE8: nop

    after_57:
    // 0x800A3BEC: jal         0x800C46C4
    // 0x800A3BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_kerning(rdram, ctx);
        goto after_58;
    // 0x800A3BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_58:
L_800A3BF4:
    // 0x800A3BF4: jal         0x80068748
    // 0x800A3BF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_59;
    // 0x800A3BF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_59:
L_800A3BFC:
    // 0x800A3BFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3C00: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A3C04: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A3C08: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A3C0C: jr          $ra
    // 0x800A3C10: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800A3C10: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void hud_stopwatch_face(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3C14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A3C18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A3C1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A3C20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A3C24: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x800A3C28: andi        $s1, $a1, 0xFF
    ctx->r17 = ctx->r5 & 0XFF;
    // 0x800A3C2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A3C30: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A3C34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800A3C38: jal         0x8000E4D8
    // 0x800A3C3C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    is_in_time_trial(rdram, ctx);
        goto after_0;
    // 0x800A3C3C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A3C40: beq         $v0, $zero, L_800A3DA4
    if (ctx->r2 == 0) {
        // 0x800A3C44: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800A3DA4;
    }
    // 0x800A3C44: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A3C48: lw          $t6, 0x72B4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72B4);
    // 0x800A3C4C: nop

    // 0x800A3C50: lw          $v0, 0x50($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X50);
    // 0x800A3C54: nop

    // 0x800A3C58: beq         $v0, $zero, L_800A3DA8
    if (ctx->r2 == 0) {
        // 0x800A3C5C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A3DA8;
    }
    // 0x800A3C5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A3C60: lw          $t7, 0x68($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X68);
    // 0x800A3C64: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x800A3C68: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800A3C6C: addiu       $ra, $ra, 0x7325
    ctx->r31 = ADD32(ctx->r31, 0X7325);
    // 0x800A3C70: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A3C74: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A3C78: lh          $a3, 0x28($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X28);
    // 0x800A3C7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A3C80: blez        $a3, L_800A3D68
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800A3C84: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800A3D68;
    }
    // 0x800A3C84: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3C88: lui         $t4, 0xFF7E
    ctx->r12 = S32(0XFF7E << 16);
    // 0x800A3C8C: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x800A3C90: addiu       $t5, $t5, 0x7326
    ctx->r13 = ADD32(ctx->r13, 0X7326);
    // 0x800A3C94: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A3C98: lui         $t2, 0x81
    ctx->r10 = S32(0X81 << 16);
    // 0x800A3C9C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_800A3CA0:
    // 0x800A3CA0: lw          $t8, 0x38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X38);
    // 0x800A3CA4: lbu         $t9, 0x0($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X0);
    // 0x800A3CA8: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x800A3CAC: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x800A3CB0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800A3CB4: bne         $t9, $a2, L_800A3D38
    if (ctx->r25 != ctx->r6) {
        // 0x800A3CB8: nop
    
            goto L_800A3D38;
    }
    // 0x800A3CB8: nop

    // 0x800A3CBC: bne         $t1, $s0, L_800A3CF4
    if (ctx->r9 != ctx->r16) {
        // 0x800A3CC0: sb          $s0, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r16;
            goto L_800A3CF4;
    }
    // 0x800A3CC0: sb          $s0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r16;
    // 0x800A3CC4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A3CC8: nop

    // 0x800A3CCC: lw          $t7, 0x38($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X38);
    // 0x800A3CD0: nop

    // 0x800A3CD4: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x800A3CD8: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800A3CDC: nop

    // 0x800A3CE0: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x800A3CE4: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x800A3CE8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A3CEC: b           L_800A3D24
    // 0x800A3CF0: sh          $t3, 0x50($t6)
    MEM_H(0X50, ctx->r14) = ctx->r11;
        goto L_800A3D24;
    // 0x800A3CF0: sh          $t3, 0x50($t6)
    MEM_H(0X50, ctx->r14) = ctx->r11;
L_800A3CF4:
    // 0x800A3CF4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A3CF8: nop

    // 0x800A3CFC: lw          $t8, 0x38($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X38);
    // 0x800A3D00: nop

    // 0x800A3D04: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x800A3D08: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x800A3D0C: nop

    // 0x800A3D10: and         $t6, $t9, $t4
    ctx->r14 = ctx->r25 & ctx->r12;
    // 0x800A3D14: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x800A3D18: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A3D1C: nop

    // 0x800A3D20: sh          $zero, 0x50($t7)
    MEM_H(0X50, ctx->r15) = 0;
L_800A3D24:
    // 0x800A3D24: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A3D28: nop

    // 0x800A3D2C: lh          $a3, 0x28($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X28);
    // 0x800A3D30: b           L_800A3D60
    // 0x800A3D34: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
        goto L_800A3D60;
    // 0x800A3D34: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
L_800A3D38:
    // 0x800A3D38: lbu         $t8, 0x0($ra)
    ctx->r24 = MEM_BU(ctx->r31, 0X0);
    // 0x800A3D3C: nop

    // 0x800A3D40: bne         $t8, $a2, L_800A3D60
    if (ctx->r24 != ctx->r6) {
        // 0x800A3D44: slt         $at, $t0, $a3
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800A3D60;
    }
    // 0x800A3D44: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800A3D48: sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
    // 0x800A3D4C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A3D50: nop

    // 0x800A3D54: lh          $a3, 0x28($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X28);
    // 0x800A3D58: nop

    // 0x800A3D5C: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
L_800A3D60:
    // 0x800A3D60: bne         $at, $zero, L_800A3CA0
    if (ctx->r1 != 0) {
        // 0x800A3D64: addiu       $a0, $a0, 0xC
        ctx->r4 = ADD32(ctx->r4, 0XC);
            goto L_800A3CA0;
    }
    // 0x800A3D64: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
L_800A3D68:
    // 0x800A3D68: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3D6C: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x800A3D70: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x800A3D74: addiu       $ra, $ra, 0x7325
    ctx->r31 = ADD32(ctx->r31, 0X7325);
    // 0x800A3D78: addiu       $t5, $t5, 0x7326
    ctx->r13 = ADD32(ctx->r13, 0X7326);
    // 0x800A3D7C: sb          $s0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r16;
    // 0x800A3D80: sb          $s1, 0x0($ra)
    MEM_B(0X0, ctx->r31) = ctx->r17;
    // 0x800A3D84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A3D88: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x800A3D8C: sb          $t9, 0x7327($at)
    MEM_B(0X7327, ctx->r1) = ctx->r25;
    // 0x800A3D90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A3D94: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x800A3D98: sb          $t6, 0x7329($at)
    MEM_B(0X7329, ctx->r1) = ctx->r14;
    // 0x800A3D9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A3DA0: sb          $t7, 0x7328($at)
    MEM_B(0X7328, ctx->r1) = ctx->r15;
L_800A3DA4:
    // 0x800A3DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A3DA8:
    // 0x800A3DA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A3DAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A3DB0: jr          $ra
    // 0x800A3DB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A3DB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void hud_speedometre_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3DB8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A3DBC: lw          $t7, 0x729C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X729C);
    // 0x800A3DC0: addiu       $t6, $zero, 0x6490
    ctx->r14 = ADD32(0, 0X6490);
    // 0x800A3DC4: jr          $ra
    // 0x800A3DC8: sh          $t6, 0x4C4($t7)
    MEM_H(0X4C4, ctx->r15) = ctx->r14;
    return;
    // 0x800A3DC8: sh          $t6, 0x4C4($t7)
    MEM_H(0X4C4, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void hud_speedometre(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3DCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A3DD0: lbu         $t6, 0x72F7($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X72F7);
    // 0x800A3DD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A3DD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A3DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3DE0: bne         $t6, $at, L_800A421C
    if (ctx->r14 != ctx->r1) {
        // 0x800A3DE4: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_800A421C;
    }
    // 0x800A3DE4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800A3DE8: jal         0x80066750
    // 0x800A3DEC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_0;
    // 0x800A3DEC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A3DF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A3DF4: bne         $v0, $zero, L_800A4220
    if (ctx->r2 != 0) {
        // 0x800A3DF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A4220;
    }
    // 0x800A3DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3DFC: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800A3E00: nop

    // 0x800A3E04: lb          $t7, 0x1D8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1D8);
    // 0x800A3E08: nop

    // 0x800A3E0C: bne         $t7, $zero, L_800A4220
    if (ctx->r15 != 0) {
        // 0x800A3E10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A4220;
    }
    // 0x800A3E10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3E14: lb          $t8, 0x1D6($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1D6);
    // 0x800A3E18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A3E1C: bne         $t8, $at, L_800A3E5C
    if (ctx->r24 != ctx->r1) {
        // 0x800A3E20: nop
    
            goto L_800A3E5C;
    }
    // 0x800A3E20: nop

    // 0x800A3E24: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800A3E28: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800A3E2C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800A3E30: lwc1        $f14, 0x24($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800A3E34: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800A3E38: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800A3E3C: nop

    // 0x800A3E40: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800A3E44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A3E48: jal         0x800CA030
    // 0x800A3E4C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A3E4C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x800A3E50: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800A3E54: b           L_800A3E80
    // 0x800A3E58: nop

        goto L_800A3E80;
    // 0x800A3E58: nop

L_800A3E5C:
    // 0x800A3E5C: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800A3E60: lwc1        $f14, 0x24($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800A3E64: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800A3E68: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800A3E6C: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800A3E70: jal         0x800CA030
    // 0x800A3E74: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800A3E74: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_2:
    // 0x800A3E78: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800A3E7C: nop

L_800A3E80:
    // 0x800A3E80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A3E84: lwc1        $f4, 0x2DB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2DB8);
    // 0x800A3E88: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800A3E8C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800A3E90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A3E94: bc1f        L_800A3EA0
    if (!c1cs) {
        // 0x800A3E98: nop
    
            goto L_800A3EA0;
    }
    // 0x800A3E98: nop

    // 0x800A3E9C: swc1        $f0, 0x2DB8($at)
    MEM_W(0X2DB8, ctx->r1) = ctx->f0.u32l;
L_800A3EA0:
    // 0x800A3EA0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A3EA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A3EA8: lb          $t9, 0x1E6($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1E6);
    // 0x800A3EAC: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A3EB0: beq         $t9, $zero, L_800A3EC4
    if (ctx->r25 == 0) {
        // 0x800A3EB4: lui         $at, 0x40E0
        ctx->r1 = S32(0X40E0 << 16);
            goto L_800A3EC4;
    }
    // 0x800A3EB4: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x800A3EB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A3EBC: nop

    // 0x800A3EC0: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
L_800A3EC4:
    // 0x800A3EC4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A3EC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A3ECC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A3ED0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800A3ED4: nop

    // 0x800A3ED8: bc1f        L_800A3EE4
    if (!c1cs) {
        // 0x800A3EDC: nop
    
            goto L_800A3EE4;
    }
    // 0x800A3EDC: nop

    // 0x800A3EE0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800A3EE4:
    // 0x800A3EE4: lwc1        $f10, 0x2C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800A3EE8: nop

    // 0x800A3EEC: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x800A3EF0: nop

    // 0x800A3EF4: bc1f        L_800A3F00
    if (!c1cs) {
        // 0x800A3EF8: nop
    
            goto L_800A3F00;
    }
    // 0x800A3EF8: nop

    // 0x800A3EFC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800A3F00:
    // 0x800A3F00: lwc1        $f12, -0x7340($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7340);
    // 0x800A3F04: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800A3F08: sub.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800A3F0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A3F10: nop

    // 0x800A3F14: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800A3F18: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800A3F1C: nop

    // 0x800A3F20: bc1f        L_800A3F2C
    if (!c1cs) {
        // 0x800A3F24: nop
    
            goto L_800A3F2C;
    }
    // 0x800A3F24: nop

    // 0x800A3F28: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800A3F2C:
    // 0x800A3F2C: jal         0x8006ECE0
    // 0x800A3F30: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    is_game_paused(rdram, ctx);
        goto after_3;
    // 0x800A3F30: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x800A3F34: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A3F38: bne         $v0, $zero, L_800A3FF4
    if (ctx->r2 != 0) {
        // 0x800A3F3C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800A3FF4;
    }
    // 0x800A3F3C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3F40: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A3F44: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A3F48: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800A3F4C: lh          $t0, 0x4C4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4C4);
    // 0x800A3F50: nop

    // 0x800A3F54: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800A3F58: nop

    // 0x800A3F5C: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A3F60: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800A3F64: nop

    // 0x800A3F68: bc1f        L_800A3FB4
    if (!c1cs) {
        // 0x800A3F6C: nop
    
            goto L_800A3FB4;
    }
    // 0x800A3F6C: nop

    // 0x800A3F70: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A3F74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A3F78: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800A3F7C: nop

    // 0x800A3F80: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A3F84: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800A3F88: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A3F8C: nop

    // 0x800A3F90: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A3F94: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A3F98: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A3F9C: nop

    // 0x800A3FA0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A3FA4: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x800A3FA8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A3FAC: b           L_800A3FF4
    // 0x800A3FB0: sh          $t2, 0x4C4($v0)
    MEM_H(0X4C4, ctx->r2) = ctx->r10;
        goto L_800A3FF4;
    // 0x800A3FB0: sh          $t2, 0x4C4($v0)
    MEM_H(0X4C4, ctx->r2) = ctx->r10;
L_800A3FB4:
    // 0x800A3FB4: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800A3FB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A3FBC: nop

    // 0x800A3FC0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A3FC4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800A3FC8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A3FCC: nop

    // 0x800A3FD0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A3FD4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A3FD8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A3FDC: nop

    // 0x800A3FE0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A3FE4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A3FE8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A3FEC: sh          $t4, 0x4C4($v0)
    MEM_H(0X4C4, ctx->r2) = ctx->r12;
    // 0x800A3FF0: nop

L_800A3FF4:
    // 0x800A3FF4: lw          $t5, 0x72CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72CC);
    // 0x800A3FF8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A3FFC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800A4000: lb          $t6, 0x2D24($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X2D24);
    // 0x800A4004: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A4008: bne         $t6, $zero, L_800A421C
    if (ctx->r14 != 0) {
        // 0x800A400C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A421C;
    }
    // 0x800A400C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4010: lb          $t7, 0x7293($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7293);
    // 0x800A4014: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4018: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800A401C: beq         $t8, $zero, L_800A409C
    if (ctx->r24 == 0) {
        // 0x800A4020: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A409C;
    }
    // 0x800A4020: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4024: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A4028: lb          $t9, 0x7290($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7290);
    // 0x800A402C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A4030: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800A4034: lbu         $t0, 0x774B($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X774B);
    // 0x800A4038: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A403C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A4040: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A4044: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800A4048: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800A404C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A4050: bgez        $t0, L_800A4064
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800A4054: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800A4064;
    }
    // 0x800A4054: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A4058: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A405C: nop

    // 0x800A4060: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800A4064:
    // 0x800A4064: nop

    // 0x800A4068: div.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800A406C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800A4070: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A4074: nop

    // 0x800A4078: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A407C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A4080: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A4084: nop

    // 0x800A4088: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A408C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800A4090: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A4094: b           L_800A40A4
    // 0x800A4098: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
        goto L_800A40A4;
    // 0x800A4098: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_800A409C:
    // 0x800A409C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A40A0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
L_800A40A4:
    // 0x800A40A4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A40A8: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A40AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A40B0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A40B4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A40B8: jal         0x800AAB5C
    // 0x800A40BC: addiu       $a3, $a3, 0x5A0
    ctx->r7 = ADD32(ctx->r7, 0X5A0);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A40BC: addiu       $a3, $a3, 0x5A0
    ctx->r7 = ADD32(ctx->r7, 0X5A0);
    after_4:
    // 0x800A40C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A40C4: jal         0x8007B820
    // 0x800A40C8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x800A40C8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_5:
    // 0x800A40CC: jal         0x8007C36C
    // 0x800A40D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_6;
    // 0x800A40D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A40D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A40D8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A40DC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A40E0: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A40E4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800A40E8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800A40EC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800A40F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800A40F4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800A40F8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800A40FC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800A4100: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A4104: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800A4108: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A410C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4110: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4114: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4118: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A411C: jal         0x800AAB5C
    // 0x800A4120: addiu       $a3, $a3, 0x4C0
    ctx->r7 = ADD32(ctx->r7, 0X4C0);
    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A4120: addiu       $a3, $a3, 0x4C0
    ctx->r7 = ADD32(ctx->r7, 0X4C0);
    after_7:
    // 0x800A4124: jal         0x8007C36C
    // 0x800A4128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_8;
    // 0x800A4128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800A412C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A4130: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A4134: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4138: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A413C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4140: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4144: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4148: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A414C: jal         0x800AAB5C
    // 0x800A4150: addiu       $a3, $a3, 0x4E0
    ctx->r7 = ADD32(ctx->r7, 0X4E0);
    hud_element_render(rdram, ctx);
        goto after_9;
    // 0x800A4150: addiu       $a3, $a3, 0x4E0
    ctx->r7 = ADD32(ctx->r7, 0X4E0);
    after_9:
    // 0x800A4154: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A4158: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A415C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4160: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4164: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4168: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A416C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4170: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4174: jal         0x800AAB5C
    // 0x800A4178: addiu       $a3, $a3, 0x500
    ctx->r7 = ADD32(ctx->r7, 0X500);
    hud_element_render(rdram, ctx);
        goto after_10;
    // 0x800A4178: addiu       $a3, $a3, 0x500
    ctx->r7 = ADD32(ctx->r7, 0X500);
    after_10:
    // 0x800A417C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A4180: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A4184: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4188: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A418C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4190: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4194: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4198: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A419C: jal         0x800AAB5C
    // 0x800A41A0: addiu       $a3, $a3, 0x520
    ctx->r7 = ADD32(ctx->r7, 0X520);
    hud_element_render(rdram, ctx);
        goto after_11;
    // 0x800A41A0: addiu       $a3, $a3, 0x520
    ctx->r7 = ADD32(ctx->r7, 0X520);
    after_11:
    // 0x800A41A4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A41A8: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A41AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A41B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A41B4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A41B8: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A41BC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A41C0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A41C4: jal         0x800AAB5C
    // 0x800A41C8: addiu       $a3, $a3, 0x540
    ctx->r7 = ADD32(ctx->r7, 0X540);
    hud_element_render(rdram, ctx);
        goto after_12;
    // 0x800A41C8: addiu       $a3, $a3, 0x540
    ctx->r7 = ADD32(ctx->r7, 0X540);
    after_12:
    // 0x800A41CC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A41D0: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A41D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A41D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A41DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A41E0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A41E4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A41E8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A41EC: jal         0x800AAB5C
    // 0x800A41F0: addiu       $a3, $a3, 0x560
    ctx->r7 = ADD32(ctx->r7, 0X560);
    hud_element_render(rdram, ctx);
        goto after_13;
    // 0x800A41F0: addiu       $a3, $a3, 0x560
    ctx->r7 = ADD32(ctx->r7, 0X560);
    after_13:
    // 0x800A41F4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A41F8: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A41FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4200: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4204: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4208: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A420C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4210: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4214: jal         0x800AAB5C
    // 0x800A4218: addiu       $a3, $a3, 0x580
    ctx->r7 = ADD32(ctx->r7, 0X580);
    hud_element_render(rdram, ctx);
        goto after_14;
    // 0x800A4218: addiu       $a3, $a3, 0x580
    ctx->r7 = ADD32(ctx->r7, 0X580);
    after_14:
L_800A421C:
    // 0x800A421C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A4220:
    // 0x800A4220: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A4224: jr          $ra
    // 0x800A4228: nop

    return;
    // 0x800A4228: nop

;}
RECOMP_FUNC void hud_race_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A422C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800A4230: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A4234: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800A4238: jal         0x8006ECE0
    // 0x800A423C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    is_game_paused(rdram, ctx);
        goto after_0;
    // 0x800A423C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A4240: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800A4244: bne         $v0, $zero, L_800A468C
    if (ctx->r2 != 0) {
        // 0x800A4248: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800A468C;
    }
    // 0x800A4248: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A424C: bne         $t1, $zero, L_800A4270
    if (ctx->r9 != 0) {
        // 0x800A4250: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800A4270;
    }
    // 0x800A4250: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A4254: addiu       $v1, $v1, 0x2CF0
    ctx->r3 = ADD32(ctx->r3, 0X2CF0);
    // 0x800A4258: lb          $t6, 0xC($v1)
    ctx->r14 = MEM_B(ctx->r3, 0XC);
    // 0x800A425C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800A4260: bne         $v0, $t6, L_800A4270
    if (ctx->r2 != ctx->r14) {
        // 0x800A4264: nop
    
            goto L_800A4270;
    }
    // 0x800A4264: nop

    // 0x800A4268: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x800A426C: sb          $v0, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r2;
L_800A4270:
    // 0x800A4270: lw          $t7, 0x72CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72CC);
    // 0x800A4274: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A4278: bne         $t7, $at, L_800A4290
    if (ctx->r15 != ctx->r1) {
        // 0x800A427C: nop
    
            goto L_800A4290;
    }
    // 0x800A427C: nop

    // 0x800A4280: jal         0x8007C36C
    // 0x800A4284: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_1;
    // 0x800A4284: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800A4288: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800A428C: nop

L_800A4290:
    // 0x800A4290: blez        $t1, L_800A44A0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800A4294: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800A44A0;
    }
    // 0x800A4294: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A4298: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A429C: lbu         $t8, 0x72F4($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X72F4);
    // 0x800A42A0: sll         $t3, $t1, 8
    ctx->r11 = S32(ctx->r9 << 8);
    // 0x800A42A4: beq         $t8, $zero, L_800A4364
    if (ctx->r24 == 0) {
        // 0x800A42A8: subu        $t3, $t3, $t1
        ctx->r11 = SUB32(ctx->r11, ctx->r9);
            goto L_800A4364;
    }
    // 0x800A42A8: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800A42AC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800A42B0: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x800A42B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A42B8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A42BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A42C0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800A42C4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A42C8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800A42CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A42D0: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800A42D4: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A42D8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800A42DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A42E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A42E4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A42E8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A42EC: mflo        $t4
    ctx->r12 = lo;
    // 0x800A42F0: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800A42F4: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800A42F8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A42FC: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A4300: jal         0x800AAB5C
    // 0x800A4304: addiu       $a3, $a3, 0x1A0
    ctx->r7 = ADD32(ctx->r7, 0X1A0);
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A4304: addiu       $a3, $a3, 0x1A0
    ctx->r7 = ADD32(ctx->r7, 0X1A0);
    after_2:
    // 0x800A4308: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A430C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4310: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A4314: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800A4318: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A431C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A4320: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800A4324: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A4328: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A432C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A4330: lb          $t2, 0x7294($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X7294);
    // 0x800A4334: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A4338: bne         $t2, $at, L_800A4364
    if (ctx->r10 != ctx->r1) {
        // 0x800A433C: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_800A4364;
    }
    // 0x800A433C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800A4340: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4344: jal         0x80001D04
    // 0x800A4348: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A4348: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_3:
    // 0x800A434C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A4350: addiu       $v0, $v0, 0x7294
    ctx->r2 = ADD32(ctx->r2, 0X7294);
    // 0x800A4354: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x800A4358: nop

    // 0x800A435C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800A4360: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
L_800A4364:
    // 0x800A4364: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A4368: lw          $t5, 0x72FC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72FC);
    // 0x800A436C: nop

    // 0x800A4370: bne         $t5, $zero, L_800A4684
    if (ctx->r13 != 0) {
        // 0x800A4374: nop
    
            goto L_800A4684;
    }
    // 0x800A4374: nop

    // 0x800A4378: jal         0x8002359C
    // 0x800A437C: nop

    func_80023568(rdram, ctx);
        goto after_4;
    // 0x800A437C: nop

    after_4:
    // 0x800A4380: bne         $v0, $zero, L_800A4684
    if (ctx->r2 != 0) {
        // 0x800A4384: nop
    
            goto L_800A4684;
    }
    // 0x800A4384: nop

    // 0x800A4388: jal         0x8001BAA8
    // 0x800A438C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    get_racer_objects(rdram, ctx);
        goto after_5;
    // 0x800A438C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x800A4390: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800A4394: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800A4398: jal         0x8006FB8C
    // 0x800A439C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_6;
    // 0x800A439C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A43A0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800A43A4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800A43A8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A43AC: lw          $t0, -0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, -0X4);
    // 0x800A43B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A43B4: lw          $v1, 0x64($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X64);
    // 0x800A43B8: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x800A43BC: lb          $t9, 0x1D6($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X1D6);
    // 0x800A43C0: nop

    // 0x800A43C4: bne         $t9, $zero, L_800A4684
    if (ctx->r25 != 0) {
        // 0x800A43C8: nop
    
            goto L_800A4684;
    }
    // 0x800A43C8: nop

    // 0x800A43CC: jal         0x8006FB8C
    // 0x800A43D0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800A43D0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_7:
    // 0x800A43D4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A43D8: slti        $at, $v0, 0x60
    ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
    // 0x800A43DC: bne         $at, $zero, L_800A4684
    if (ctx->r1 != 0) {
        // 0x800A43E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800A4684;
    }
    // 0x800A43E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A43E4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800A43E8: jal         0x8006FB8C
    // 0x800A43EC: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    rand_range(rdram, ctx);
        goto after_8;
    // 0x800A43EC: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_8:
    // 0x800A43F0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A43F4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A43F8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800A43FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A4400: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A4404: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x800A4408: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800A440C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A4410: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A4414: lui         $at, 0x3FF4
    ctx->r1 = S32(0X3FF4 << 16);
    // 0x800A4418: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A441C: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x800A4420: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A4424: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A4428: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800A442C: sub.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d - ctx->f18.d;
    // 0x800A4430: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800A4434: jal         0x8006FB8C
    // 0x800A4438: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    rand_range(rdram, ctx);
        goto after_9;
    // 0x800A4438: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x800A443C: sll         $t3, $v0, 6
    ctx->r11 = S32(ctx->r2 << 6);
    // 0x800A4440: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x800A4444: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800A4448: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x800A444C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A4450: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A4454: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A4458: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A445C: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x800A4460: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    // 0x800A4464: lw          $a3, 0x14($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X14);
    // 0x800A4468: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A446C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A4470: addiu       $t6, $t6, 0x72FC
    ctx->r14 = ADD32(ctx->r14, 0X72FC);
    // 0x800A4474: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800A4478: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A447C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800A4480: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800A4484: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x800A4488: mflo        $t4
    ctx->r12 = lo;
    // 0x800A448C: addiu       $t5, $t4, 0x18
    ctx->r13 = ADD32(ctx->r12, 0X18);
    // 0x800A4490: jal         0x800095E8
    // 0x800A4494: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    audspat_play_sound_direct(rdram, ctx);
        goto after_10;
    // 0x800A4494: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_10:
    // 0x800A4498: b           L_800A4684
    // 0x800A449C: nop

        goto L_800A4684;
    // 0x800A449C: nop

L_800A44A0:
    // 0x800A44A0: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A44A4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A44A8: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A44AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A44B0: lwc1        $f6, 0x18C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X18C);
    // 0x800A44B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A44B8: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800A44BC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A44C0: bc1f        L_800A4684
    if (!c1cs) {
        // 0x800A44C4: lui         $t9, 0xFA00
        ctx->r25 = S32(0XFA00 << 16);
            goto L_800A4684;
    }
    // 0x800A44C4: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800A44C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A44CC: addiu       $t2, $zero, -0x60
    ctx->r10 = ADD32(0, -0X60);
    // 0x800A44D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800A44D4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800A44D8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800A44DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A44E0: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A44E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A44E8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A44EC: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A44F0: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A44F4: jal         0x800AAB5C
    // 0x800A44F8: addiu       $a3, $a3, 0x180
    ctx->r7 = ADD32(ctx->r7, 0X180);
    hud_element_render(rdram, ctx);
        goto after_11;
    // 0x800A44F8: addiu       $a3, $a3, 0x180
    ctx->r7 = ADD32(ctx->r7, 0X180);
    after_11:
    // 0x800A44FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4500: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4504: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A4508: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800A450C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800A4510: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800A4514: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A4518: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A451C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A4520: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800A4524: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800A4528: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A452C: addiu       $a3, $a3, 0x72C8
    ctx->r7 = ADD32(ctx->r7, 0X72C8);
    // 0x800A4530: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800A4534: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A4538: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800A453C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800A4540: lb          $t8, 0x19A($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X19A);
    // 0x800A4544: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A4548: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x800A454C: sb          $t2, 0x19A($a1)
    MEM_B(0X19A, ctx->r5) = ctx->r10;
    // 0x800A4550: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800A4554: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x800A4558: nop

    // 0x800A455C: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x800A4560: lb          $t5, 0x19A($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X19A);
    // 0x800A4564: nop

    // 0x800A4568: slti        $at, $t5, 0x3C
    ctx->r1 = SIGNED(ctx->r13) < 0X3C ? 1 : 0;
    // 0x800A456C: bne         $at, $zero, L_800A4604
    if (ctx->r1 != 0) {
        // 0x800A4570: nop
    
            goto L_800A4604;
    }
    // 0x800A4570: nop

    // 0x800A4574: lb          $t6, 0x7294($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7294);
    // 0x800A4578: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A457C: bne         $t6, $at, L_800A45E8
    if (ctx->r14 != ctx->r1) {
        // 0x800A4580: lw          $t9, 0x5C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X5C);
            goto L_800A45E8;
    }
    // 0x800A4580: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800A4584: jal         0x80066450
    // 0x800A4588: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_12;
    // 0x800A4588: nop

    after_12:
    // 0x800A458C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800A4590: bne         $at, $zero, L_800A45AC
    if (ctx->r1 != 0) {
        // 0x800A4594: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800A45AC;
    }
    // 0x800A4594: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A4598: jal         0x80000B34
    // 0x800A459C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    music_play(rdram, ctx);
        goto after_13;
    // 0x800A459C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x800A45A0: b           L_800A45BC
    // 0x800A45A4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
        goto L_800A45BC;
    // 0x800A45A4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A45A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800A45AC:
    // 0x800A45AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A45B0: jal         0x8006BF50
    // 0x800A45B4: nop

    level_music_start(rdram, ctx);
        goto after_14;
    // 0x800A45B4: nop

    after_14:
    // 0x800A45B8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
L_800A45BC:
    // 0x800A45BC: jal         0x80001D04
    // 0x800A45C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x800A45C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800A45C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A45C8: addiu       $v0, $v0, 0x7294
    ctx->r2 = ADD32(ctx->r2, 0X7294);
    // 0x800A45CC: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x800A45D0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A45D4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800A45D8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800A45DC: lw          $a2, 0x729C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X729C);
    // 0x800A45E0: nop

    // 0x800A45E4: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
L_800A45E8:
    // 0x800A45E8: lwc1        $f8, 0x18C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18C);
    // 0x800A45EC: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x800A45F0: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800A45F4: nop

    // 0x800A45F8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A45FC: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800A4600: swc1        $f4, 0x18C($a2)
    MEM_W(0X18C, ctx->r6) = ctx->f4.u32l;
L_800A4604:
    // 0x800A4604: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A4608: lb          $t3, 0x7294($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X7294);
    // 0x800A460C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A4610: bne         $t3, $at, L_800A4684
    if (ctx->r11 != ctx->r1) {
        // 0x800A4614: addiu       $a0, $zero, 0x19
        ctx->r4 = ADD32(0, 0X19);
            goto L_800A4684;
    }
    // 0x800A4614: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x800A4618: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A461C: jal         0x80001D04
    // 0x800A4620: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_16;
    // 0x800A4620: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_16:
    // 0x800A4624: jal         0x8001B674
    // 0x800A4628: nop

    timetrial_ghost_staff(rdram, ctx);
        goto after_17;
    // 0x800A4628: nop

    after_17:
    // 0x800A462C: beq         $v0, $zero, L_800A4664
    if (ctx->r2 == 0) {
        // 0x800A4630: nop
    
            goto L_800A4664;
    }
    // 0x800A4630: nop

    // 0x800A4634: jal         0x8001B684
    // 0x800A4638: nop

    timetrial_staff_unbeaten(rdram, ctx);
        goto after_18;
    // 0x800A4638: nop

    after_18:
    // 0x800A463C: bne         $v0, $zero, L_800A4664
    if (ctx->r2 != 0) {
        // 0x800A4640: addiu       $a0, $zero, 0x24B
        ctx->r4 = ADD32(0, 0X24B);
            goto L_800A4664;
    }
    // 0x800A4640: addiu       $a0, $zero, 0x24B
    ctx->r4 = ADD32(0, 0X24B);
    // 0x800A4644: lui         $a1, 0x3FD9
    ctx->r5 = S32(0X3FD9 << 16);
    // 0x800A4648: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800A464C: jal         0x800A79E0
    // 0x800A4650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    hud_sound_play_delayed(rdram, ctx);
        goto after_19;
    // 0x800A4650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x800A4654: lui         $a1, 0x3FD9
    ctx->r5 = S32(0X3FD9 << 16);
    // 0x800A4658: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800A465C: jal         0x800C36B0
    // 0x800A4660: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    set_delayed_text(rdram, ctx);
        goto after_20;
    // 0x800A4660: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    after_20:
L_800A4664:
    // 0x800A4664: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A4668: lb          $t5, 0x7294($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X7294);
    // 0x800A466C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A4670: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A4674: sb          $t4, 0x7330($at)
    MEM_B(0X7330, ctx->r1) = ctx->r12;
    // 0x800A4678: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A467C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800A4680: sb          $t6, 0x7294($at)
    MEM_B(0X7294, ctx->r1) = ctx->r14;
L_800A4684:
    // 0x800A4684: jal         0x8007C36C
    // 0x800A4688: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_21;
    // 0x800A4688: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
L_800A468C:
    // 0x800A468C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A4690: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800A4694: jr          $ra
    // 0x800A4698: nop

    return;
    // 0x800A4698: nop

;}
RECOMP_FUNC void hud_bananas(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A469C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A46A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A46A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A46A8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800A46AC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800A46B0: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800A46B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A46B8: beq         $v0, $at, L_800A4768
    if (ctx->r2 == ctx->r1) {
        // 0x800A46BC: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800A4768;
    }
    // 0x800A46BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A46C0: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x800A46C4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A46C8: blez        $v1, L_800A4708
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A46CC: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800A4708;
    }
    // 0x800A46CC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800A46D0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800A46D4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A46D8: lbu         $t9, 0x2D14($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X2D14);
    // 0x800A46DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A46E0: beq         $t9, $at, L_800A4708
    if (ctx->r25 == ctx->r1) {
        // 0x800A46E4: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800A4708;
    }
    // 0x800A46E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A46E8: lw          $t2, 0x7320($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7320);
    // 0x800A46EC: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A46F0: lb          $v0, 0x4C($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X4C);
    // 0x800A46F4: nop

    // 0x800A46F8: beq         $v0, $at, L_800A4708
    if (ctx->r2 == ctx->r1) {
        // 0x800A46FC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800A4708;
    }
    // 0x800A46FC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A4700: bne         $v0, $at, L_800A4B2C
    if (ctx->r2 != ctx->r1) {
        // 0x800A4704: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4B2C;
    }
    // 0x800A4704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4708:
    // 0x800A4708: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800A470C: nop

    // 0x800A4710: lb          $t4, 0x1D8($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X1D8);
    // 0x800A4714: nop

    // 0x800A4718: bne         $t4, $zero, L_800A4B2C
    if (ctx->r12 != 0) {
        // 0x800A471C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4B2C;
    }
    // 0x800A471C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A4720: blez        $v1, L_800A4768
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A4724: nop
    
            goto L_800A4768;
    }
    // 0x800A4724: nop

    // 0x800A4728: lb          $v0, 0x193($t3)
    ctx->r2 = MEM_B(ctx->r11, 0X193);
    // 0x800A472C: nop

    // 0x800A4730: blez        $v0, L_800A4768
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A4734: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_800A4768;
    }
    // 0x800A4734: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800A4738: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800A473C: lw          $t7, 0x128($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X128);
    // 0x800A4740: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A4744: slti        $at, $t7, 0xB4
    ctx->r1 = SIGNED(ctx->r15) < 0XB4 ? 1 : 0;
    // 0x800A4748: beq         $at, $zero, L_800A4768
    if (ctx->r1 == 0) {
        // 0x800A474C: nop
    
            goto L_800A4768;
    }
    // 0x800A474C: nop

    // 0x800A4750: lw          $t8, 0x7320($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7320);
    // 0x800A4754: nop

    // 0x800A4758: lb          $t9, 0x4C($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X4C);
    // 0x800A475C: nop

    // 0x800A4760: andi        $t2, $t9, 0x40
    ctx->r10 = ctx->r25 & 0X40;
    // 0x800A4764: beq         $t2, $zero, L_800A4B28
    if (ctx->r10 == 0) {
        // 0x800A4768: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800A4B28;
    }
L_800A4768:
    // 0x800A4768: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A476C: addiu       $s0, $s0, 0x729C
    ctx->r16 = ADD32(ctx->r16, 0X729C);
    // 0x800A4770: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A4774: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4778: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A477C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4780: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4784: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4788: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A478C: jal         0x800AAB5C
    // 0x800A4790: addiu       $a3, $a3, 0x240
    ctx->r7 = ADD32(ctx->r7, 0X240);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A4790: addiu       $a3, $a3, 0x240
    ctx->r7 = ADD32(ctx->r7, 0X240);
    after_0:
    // 0x800A4794: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A4798: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A479C: lb          $a0, 0x185($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X185);
    // 0x800A47A0: nop

    // 0x800A47A4: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x800A47A8: lb          $a1, 0xFA($v0)
    ctx->r5 = MEM_B(ctx->r2, 0XFA);
    // 0x800A47AC: lbu         $v1, 0xF9($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XF9);
    // 0x800A47B0: bne         $a1, $zero, L_800A47DC
    if (ctx->r5 != 0) {
        // 0x800A47B4: nop
    
            goto L_800A47DC;
    }
    // 0x800A47B4: nop

    // 0x800A47B8: lb          $t4, 0xFB($v0)
    ctx->r12 = MEM_B(ctx->r2, 0XFB);
    // 0x800A47BC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800A47C0: beq         $a0, $t4, L_800A47DC
    if (ctx->r4 == ctx->r12) {
        // 0x800A47C4: nop
    
            goto L_800A47DC;
    }
    // 0x800A47C4: nop

    // 0x800A47C8: sb          $t3, 0xFA($v0)
    MEM_B(0XFA, ctx->r2) = ctx->r11;
    // 0x800A47CC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800A47D0: lb          $t5, 0x185($a2)
    ctx->r13 = MEM_B(ctx->r6, 0X185);
    // 0x800A47D4: b           L_800A4868
    // 0x800A47D8: sb          $t5, 0xFB($t6)
    MEM_B(0XFB, ctx->r14) = ctx->r13;
        goto L_800A4868;
    // 0x800A47D8: sb          $t5, 0xFB($t6)
    MEM_B(0XFB, ctx->r14) = ctx->r13;
L_800A47DC:
    // 0x800A47DC: beq         $a1, $zero, L_800A4868
    if (ctx->r5 == 0) {
        // 0x800A47E0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800A4868;
    }
    // 0x800A47E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A47E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A47E8: nop

    // 0x800A47EC: swc1        $f4, 0x388($v0)
    MEM_W(0X388, ctx->r2) = ctx->f4.u32l;
    // 0x800A47F0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A47F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A47F8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A47FC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A4800: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A4804: lh          $t2, 0xF8($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XF8);
    // 0x800A4808: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800A480C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800A4810: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x800A4814: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x800A4818: slt         $at, $t9, $t4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800A481C: beq         $at, $zero, L_800A4868
    if (ctx->r1 == 0) {
        // 0x800A4820: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800A4868;
    }
    // 0x800A4820: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800A4824: lb          $t3, 0xFA($v0)
    ctx->r11 = MEM_B(ctx->r2, 0XFA);
    // 0x800A4828: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A482C: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x800A4830: sb          $t5, 0xFA($v0)
    MEM_B(0XFA, ctx->r2) = ctx->r13;
    // 0x800A4834: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A4838: nop

    // 0x800A483C: lb          $t6, 0xFA($v0)
    ctx->r14 = MEM_B(ctx->r2, 0XFA);
    // 0x800A4840: nop

    // 0x800A4844: bne         $t6, $zero, L_800A4868
    if (ctx->r14 != 0) {
        // 0x800A4848: nop
    
            goto L_800A4868;
    }
    // 0x800A4848: nop

    // 0x800A484C: sb          $a0, 0x39B($v0)
    MEM_B(0X39B, ctx->r2) = ctx->r4;
    // 0x800A4850: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A4854: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800A4858: sb          $t7, 0x39A($t8)
    MEM_B(0X39A, ctx->r24) = ctx->r15;
    // 0x800A485C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A4860: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A4864: sh          $a0, 0x398($t9)
    MEM_H(0X398, ctx->r25) = ctx->r4;
L_800A4868:
    // 0x800A4868: bne         $v1, $zero, L_800A498C
    if (ctx->r3 != 0) {
        // 0x800A486C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800A498C;
    }
    // 0x800A486C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A4870: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A4874: jal         0x8007C36C
    // 0x800A4878: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    sprite_opaque(rdram, ctx);
        goto after_1;
    // 0x800A4878: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x800A487C: jal         0x800662D8
    // 0x800A4880: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_2;
    // 0x800A4880: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800A4884: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A4888: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A488C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4890: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4894: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4898: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A489C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A48A0: jal         0x800AAB5C
    // 0x800A48A4: addiu       $a3, $a3, 0x360
    ctx->r7 = ADD32(ctx->r7, 0X360);
    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A48A4: addiu       $a3, $a3, 0x360
    ctx->r7 = ADD32(ctx->r7, 0X360);
    after_3:
    // 0x800A48A8: jal         0x800662D8
    // 0x800A48AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_4;
    // 0x800A48AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800A48B0: jal         0x8007C36C
    // 0x800A48B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_5;
    // 0x800A48B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x800A48B8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800A48BC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A48C0: nop

    // 0x800A48C4: sh          $t2, 0xF8($t4)
    MEM_H(0XF8, ctx->r12) = ctx->r10;
    // 0x800A48C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A48CC: nop

    // 0x800A48D0: lb          $t3, 0x39B($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X39B);
    // 0x800A48D4: nop

    // 0x800A48D8: beq         $t3, $zero, L_800A4A10
    if (ctx->r11 == 0) {
        // 0x800A48DC: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_800A4A10;
    }
    // 0x800A48DC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800A48E0: lb          $t5, 0x39A($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X39A);
    // 0x800A48E4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800A48E8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800A48EC: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x800A48F0: sb          $t7, 0x39A($v0)
    MEM_B(0X39A, ctx->r2) = ctx->r15;
    // 0x800A48F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A48F8: nop

    // 0x800A48FC: lb          $t8, 0x39A($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X39A);
    // 0x800A4900: nop

    // 0x800A4904: bgez        $t8, L_800A494C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A4908: nop
    
            goto L_800A494C;
    }
    // 0x800A4908: nop

    // 0x800A490C: sb          $a0, 0x39A($v0)
    MEM_B(0X39A, ctx->r2) = ctx->r4;
    // 0x800A4910: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A4914: nop

    // 0x800A4918: lh          $v1, 0x398($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X398);
    // 0x800A491C: nop

    // 0x800A4920: bne         $a0, $v1, L_800A4948
    if (ctx->r4 != ctx->r3) {
        // 0x800A4924: addiu       $t4, $v1, 0x1
        ctx->r12 = ADD32(ctx->r3, 0X1);
            goto L_800A4948;
    }
    // 0x800A4924: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x800A4928: sh          $zero, 0x398($v0)
    MEM_H(0X398, ctx->r2) = 0;
    // 0x800A492C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A4930: nop

    // 0x800A4934: lb          $t9, 0x39B($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X39B);
    // 0x800A4938: nop

    // 0x800A493C: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x800A4940: b           L_800A494C
    // 0x800A4944: sb          $t2, 0x39B($v0)
    MEM_B(0X39B, ctx->r2) = ctx->r10;
        goto L_800A494C;
    // 0x800A4944: sb          $t2, 0x39B($v0)
    MEM_B(0X39B, ctx->r2) = ctx->r10;
L_800A4948:
    // 0x800A4948: sh          $t4, 0x398($v0)
    MEM_H(0X398, ctx->r2) = ctx->r12;
L_800A494C:
    // 0x800A494C: jal         0x800662D8
    // 0x800A4950: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_6;
    // 0x800A4950: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A4954: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A4958: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A495C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4960: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4964: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4968: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A496C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4970: jal         0x800AAB5C
    // 0x800A4974: addiu       $a3, $a3, 0x380
    ctx->r7 = ADD32(ctx->r7, 0X380);
    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A4974: addiu       $a3, $a3, 0x380
    ctx->r7 = ADD32(ctx->r7, 0X380);
    after_7:
    // 0x800A4978: jal         0x800662D8
    // 0x800A497C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_8;
    // 0x800A497C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800A4980: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A4984: b           L_800A4A10
    // 0x800A4988: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
        goto L_800A4A10;
    // 0x800A4988: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_800A498C:
    // 0x800A498C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A4990: addiu       $t3, $v0, 0x80
    ctx->r11 = ADD32(ctx->r2, 0X80);
    // 0x800A4994: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A4998: jal         0x80068748
    // 0x800A499C: sh          $t3, 0xF8($t5)
    MEM_H(0XF8, ctx->r13) = ctx->r11;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_9;
    // 0x800A499C: sh          $t3, 0xF8($t5)
    MEM_H(0XF8, ctx->r13) = ctx->r11;
    after_9:
    // 0x800A49A0: jal         0x8007C36C
    // 0x800A49A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_10;
    // 0x800A49A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x800A49A8: jal         0x800662D8
    // 0x800A49AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_11;
    // 0x800A49AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x800A49B0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A49B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A49B8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A49BC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A49C0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A49C4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A49C8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A49CC: jal         0x800AAB5C
    // 0x800A49D0: addiu       $a3, $a3, 0xE0
    ctx->r7 = ADD32(ctx->r7, 0XE0);
    hud_element_render(rdram, ctx);
        goto after_12;
    // 0x800A49D0: addiu       $a3, $a3, 0xE0
    ctx->r7 = ADD32(ctx->r7, 0XE0);
    after_12:
    // 0x800A49D4: jal         0x8007C36C
    // 0x800A49D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_13;
    // 0x800A49D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x800A49DC: jal         0x800662D8
    // 0x800A49E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_14;
    // 0x800A49E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x800A49E4: jal         0x80068748
    // 0x800A49E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_15;
    // 0x800A49E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x800A49EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A49F0: nop

    // 0x800A49F4: lh          $t6, 0xF8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XF8);
    // 0x800A49F8: nop

    // 0x800A49FC: addiu       $t7, $t6, -0x80
    ctx->r15 = ADD32(ctx->r14, -0X80);
    // 0x800A4A00: sh          $t7, 0xF8($v0)
    MEM_H(0XF8, ctx->r2) = ctx->r15;
    // 0x800A4A04: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A4A08: nop

    // 0x800A4A0C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_800A4A10:
    // 0x800A4A10: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x800A4A14: div         $zero, $t1, $t0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r8)));
    // 0x800A4A18: bne         $t0, $zero, L_800A4A24
    if (ctx->r8 != 0) {
        // 0x800A4A1C: nop
    
            goto L_800A4A24;
    }
    // 0x800A4A1C: nop

    // 0x800A4A20: break       7
    do_break(2148157984);
L_800A4A24:
    // 0x800A4A24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4A28: bne         $t0, $at, L_800A4A3C
    if (ctx->r8 != ctx->r1) {
        // 0x800A4A2C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A4A3C;
    }
    // 0x800A4A2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A4A30: bne         $t1, $at, L_800A4A3C
    if (ctx->r9 != ctx->r1) {
        // 0x800A4A34: nop
    
            goto L_800A4A3C;
    }
    // 0x800A4A34: nop

    // 0x800A4A38: break       6
    do_break(2148158008);
L_800A4A3C:
    // 0x800A4A3C: mflo        $v1
    ctx->r3 = lo;
    // 0x800A4A40: beq         $v1, $zero, L_800A4AAC
    if (ctx->r3 == 0) {
        // 0x800A4A44: nop
    
            goto L_800A4AAC;
    }
    // 0x800A4A44: nop

    // 0x800A4A48: div         $zero, $t1, $t0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r8)));
    // 0x800A4A4C: sh          $v1, 0x118($v0)
    MEM_H(0X118, ctx->r2) = ctx->r3;
    // 0x800A4A50: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A4A54: bne         $t0, $zero, L_800A4A60
    if (ctx->r8 != 0) {
        // 0x800A4A58: nop
    
            goto L_800A4A60;
    }
    // 0x800A4A58: nop

    // 0x800A4A5C: break       7
    do_break(2148158044);
L_800A4A60:
    // 0x800A4A60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4A64: bne         $t0, $at, L_800A4A78
    if (ctx->r8 != ctx->r1) {
        // 0x800A4A68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A4A78;
    }
    // 0x800A4A68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A4A6C: bne         $t1, $at, L_800A4A78
    if (ctx->r9 != ctx->r1) {
        // 0x800A4A70: nop
    
            goto L_800A4A78;
    }
    // 0x800A4A70: nop

    // 0x800A4A74: break       6
    do_break(2148158068);
L_800A4A78:
    // 0x800A4A78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4A7C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4A80: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4A84: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4A88: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4A8C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4A90: mfhi        $t8
    ctx->r24 = hi;
    // 0x800A4A94: sh          $t8, 0x138($t9)
    MEM_H(0X138, ctx->r25) = ctx->r24;
    // 0x800A4A98: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A4A9C: jal         0x800AAB5C
    // 0x800A4AA0: addiu       $a3, $a3, 0x120
    ctx->r7 = ADD32(ctx->r7, 0X120);
    hud_element_render(rdram, ctx);
        goto after_16;
    // 0x800A4AA0: addiu       $a3, $a3, 0x120
    ctx->r7 = ADD32(ctx->r7, 0X120);
    after_16:
    // 0x800A4AA4: b           L_800A4AE4
    // 0x800A4AA8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
        goto L_800A4AE4;
    // 0x800A4AA8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_800A4AAC:
    // 0x800A4AAC: div         $zero, $t1, $t0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r8)));
    // 0x800A4AB0: bne         $t0, $zero, L_800A4ABC
    if (ctx->r8 != 0) {
        // 0x800A4AB4: nop
    
            goto L_800A4ABC;
    }
    // 0x800A4AB4: nop

    // 0x800A4AB8: break       7
    do_break(2148158136);
L_800A4ABC:
    // 0x800A4ABC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4AC0: bne         $t0, $at, L_800A4AD4
    if (ctx->r8 != ctx->r1) {
        // 0x800A4AC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A4AD4;
    }
    // 0x800A4AC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A4AC8: bne         $t1, $at, L_800A4AD4
    if (ctx->r9 != ctx->r1) {
        // 0x800A4ACC: nop
    
            goto L_800A4AD4;
    }
    // 0x800A4ACC: nop

    // 0x800A4AD0: break       6
    do_break(2148158160);
L_800A4AD4:
    // 0x800A4AD4: mfhi        $t2
    ctx->r10 = hi;
    // 0x800A4AD8: sh          $t2, 0x118($v0)
    MEM_H(0X118, ctx->r2) = ctx->r10;
    // 0x800A4ADC: nop

    // 0x800A4AE0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_800A4AE4:
    // 0x800A4AE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4AE8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4AEC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4AF0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4AF4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4AF8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4AFC: jal         0x800AAB5C
    // 0x800A4B00: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
    hud_element_render(rdram, ctx);
        goto after_17;
    // 0x800A4B00: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
    after_17:
    // 0x800A4B04: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A4B08: lw          $v1, 0x72BC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72BC);
    // 0x800A4B0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A4B10: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800A4B14: sw          $t4, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = ctx->r12;
    // 0x800A4B18: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A4B1C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A4B20: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800A4B24: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_800A4B28:
    // 0x800A4B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4B2C:
    // 0x800A4B2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4B30: jr          $ra
    // 0x800A4B34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800A4B34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void hud_treasure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4B38: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A4B3C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800A4B40: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A4B44: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x800A4B48: addiu       $s7, $s7, 0x729C
    ctx->r23 = ADD32(ctx->r23, 0X729C);
    // 0x800A4B4C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A4B50: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800A4B54: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A4B58: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800A4B5C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800A4B60: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800A4B64: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800A4B68: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800A4B6C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800A4B70: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A4B74: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A4B78: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A4B7C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A4B80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A4B84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A4B88: lwc1        $f4, 0x410($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X410);
    // 0x800A4B8C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A4B90: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A4B94: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A4B98: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A4B9C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A4BA0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800A4BA4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800A4BA8: bne         $at, $zero, L_800A4BCC
    if (ctx->r1 != 0) {
        // 0x800A4BAC: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_800A4BCC;
    }
    // 0x800A4BAC: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800A4BB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A4BB4: bne         $v0, $at, L_800A4C14
    if (ctx->r2 != ctx->r1) {
        // 0x800A4BB8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_800A4C14;
    }
    // 0x800A4BB8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800A4BBC: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x800A4BC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4BC4: bne         $t8, $at, L_800A4C14
    if (ctx->r24 != ctx->r1) {
        // 0x800A4BC8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_800A4C14;
    }
    // 0x800A4BC8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_800A4BCC:
    // 0x800A4BCC: lb          $t9, 0x3($s6)
    ctx->r25 = MEM_B(ctx->r22, 0X3);
    // 0x800A4BD0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A4BD4: addiu       $t0, $t9, 0x38
    ctx->r8 = ADD32(ctx->r25, 0X38);
    // 0x800A4BD8: sh          $t0, 0x646($s1)
    MEM_H(0X646, ctx->r17) = ctx->r8;
    // 0x800A4BDC: lw          $a3, 0x0($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X0);
    // 0x800A4BE0: addiu       $s2, $s2, 0x7295
    ctx->r18 = ADD32(ctx->r18, 0X7295);
    // 0x800A4BE4: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800A4BE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4BEC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4BF0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4BF4: sb          $fp, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r30;
    // 0x800A4BF8: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4BFC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4C00: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4C04: jal         0x800AAB5C
    // 0x800A4C08: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A4C08: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    after_0:
    // 0x800A4C0C: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800A4C10: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_800A4C14:
    // 0x800A4C14: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A4C18: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800A4C1C: lui         $s3, 0x8080
    ctx->r19 = S32(0X8080 << 16);
    // 0x800A4C20: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A4C24: addiu       $s2, $s2, 0x7295
    ctx->r18 = ADD32(ctx->r18, 0X7295);
    // 0x800A4C28: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800A4C2C: ori         $s3, $s3, 0x8080
    ctx->r19 = ctx->r19 | 0X8080;
    // 0x800A4C30: addiu       $s5, $s5, 0x2DB4
    ctx->r21 = ADD32(ctx->r21, 0X2DB4);
    // 0x800A4C34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A4C38: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_800A4C3C:
    // 0x800A4C3C: lb          $t1, 0x193($s6)
    ctx->r9 = MEM_B(ctx->r22, 0X193);
    // 0x800A4C40: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800A4C44: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A4C48: bne         $at, $zero, L_800A4C54
    if (ctx->r1 != 0) {
        // 0x800A4C4C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A4C54;
    }
    // 0x800A4C4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4C50: sw          $s3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r19;
L_800A4C54:
    // 0x800A4C54: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4C58: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4C5C: sb          $fp, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r30;
    // 0x800A4C60: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4C64: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4C68: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4C6C: jal         0x800AAB5C
    // 0x800A4C70: addiu       $a3, $s1, 0x400
    ctx->r7 = ADD32(ctx->r17, 0X400);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A4C70: addiu       $a3, $s1, 0x400
    ctx->r7 = ADD32(ctx->r17, 0X400);
    after_1:
    // 0x800A4C74: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800A4C78: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800A4C7C: lwc1        $f8, 0x410($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X410);
    // 0x800A4C80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A4C84: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800A4C88: bne         $s0, $s4, L_800A4C3C
    if (ctx->r16 != ctx->r20) {
        // 0x800A4C8C: swc1        $f10, 0x410($s1)
        MEM_W(0X410, ctx->r17) = ctx->f10.u32l;
            goto L_800A4C3C;
    }
    // 0x800A4C8C: swc1        $f10, 0x410($s1)
    MEM_W(0X410, ctx->r17) = ctx->f10.u32l;
    // 0x800A4C90: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800A4C94: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x800A4C98: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800A4C9C: addiu       $t4, $zero, -0x2
    ctx->r12 = ADD32(0, -0X2);
    // 0x800A4CA0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A4CA4: swc1        $f18, 0x410($t3)
    MEM_W(0X410, ctx->r11) = ctx->f18.u32l;
    // 0x800A4CA8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800A4CAC: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x800A4CB0: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800A4CB4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A4CB8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800A4CBC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800A4CC0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4CC4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800A4CC8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800A4CCC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4CD0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A4CD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A4CD8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A4CDC: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A4CE0: jr          $ra
    // 0x800A4CE4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800A4CE4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void hud_silver_coins(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4CE8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800A4CEC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800A4CF0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A4CF4: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x800A4CF8: addiu       $fp, $fp, 0x729C
    ctx->r30 = ADD32(ctx->r30, 0X729C);
    // 0x800A4CFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A4D00: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A4D04: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A4D08: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A4D0C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800A4D10: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800A4D14: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800A4D18: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A4D1C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A4D20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A4D24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4D28: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800A4D2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A4D30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A4D34: lwc1        $f4, 0x5D0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X5D0);
    // 0x800A4D38: lui         $s2, 0x8080
    ctx->r18 = S32(0X8080 << 16);
    // 0x800A4D3C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A4D40: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800A4D44: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A4D48: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A4D4C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A4D50: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A4D54: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A4D58: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800A4D5C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800A4D60: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A4D64: swc1        $f10, 0x5D0($s1)
    MEM_W(0X5D0, ctx->r17) = ctx->f10.u32l;
    // 0x800A4D68: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800A4D6C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A4D70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A4D74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A4D78: lwc1        $f16, 0x5D0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X5D0);
    // 0x800A4D7C: addiu       $s5, $s5, 0x72C4
    ctx->r21 = ADD32(ctx->r21, 0X72C4);
    // 0x800A4D80: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A4D84: addiu       $s4, $s4, 0x72C0
    ctx->r20 = ADD32(ctx->r20, 0X72C0);
    // 0x800A4D88: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800A4D8C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A4D90: addiu       $s3, $s3, 0x72BC
    ctx->r19 = ADD32(ctx->r19, 0X72BC);
    // 0x800A4D94: ori         $s2, $s2, 0x8080
    ctx->r18 = ctx->r18 | 0X8080;
    // 0x800A4D98: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A4D9C: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    // 0x800A4DA0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
L_800A4DA4:
    // 0x800A4DA4: lb          $t1, 0x202($s6)
    ctx->r9 = MEM_B(ctx->r22, 0X202);
    // 0x800A4DA8: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A4DAC: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A4DB0: bne         $at, $zero, L_800A4DC0
    if (ctx->r1 != 0) {
        // 0x800A4DB4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800A4DC0;
    }
    // 0x800A4DB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800A4DB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4DBC: sw          $s2, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r18;
L_800A4DC0:
    // 0x800A4DC0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800A4DC4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800A4DC8: jal         0x800AAB5C
    // 0x800A4DCC: addiu       $a3, $s1, 0x5C0
    ctx->r7 = ADD32(ctx->r17, 0X5C0);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A4DCC: addiu       $a3, $s1, 0x5C0
    ctx->r7 = ADD32(ctx->r17, 0X5C0);
    after_0:
    // 0x800A4DD0: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A4DD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A4DD8: lb          $t2, 0x5DC($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X5DC);
    // 0x800A4DDC: lwc1        $f4, 0x5D0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X5D0);
    // 0x800A4DE0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800A4DE4: nop

    // 0x800A4DE8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A4DEC: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800A4DF0: bne         $s0, $s7, L_800A4DA4
    if (ctx->r16 != ctx->r23) {
        // 0x800A4DF4: swc1        $f10, 0x5D0($s1)
        MEM_W(0X5D0, ctx->r17) = ctx->f10.u32l;
            goto L_800A4DA4;
    }
    // 0x800A4DF4: swc1        $f10, 0x5D0($s1)
    MEM_W(0X5D0, ctx->r17) = ctx->f10.u32l;
    // 0x800A4DF8: lb          $t3, 0x202($s6)
    ctx->r11 = MEM_B(ctx->r22, 0X202);
    // 0x800A4DFC: nop

    // 0x800A4E00: bne         $s7, $t3, L_800A4E78
    if (ctx->r23 != ctx->r11) {
        // 0x800A4E04: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_800A4E78;
    }
    // 0x800A4E04: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A4E08: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A4E0C: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A4E10: lb          $v0, 0x5DB($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X5DB);
    // 0x800A4E14: nop

    // 0x800A4E18: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x800A4E1C: beq         $at, $zero, L_800A4E30
    if (ctx->r1 == 0) {
        // 0x800A4E20: addu        $t5, $v0, $t4
        ctx->r13 = ADD32(ctx->r2, ctx->r12);
            goto L_800A4E30;
    }
    // 0x800A4E20: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800A4E24: sb          $t5, 0x5DB($s1)
    MEM_B(0X5DB, ctx->r17) = ctx->r13;
    // 0x800A4E28: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A4E2C: nop

L_800A4E30:
    // 0x800A4E30: lb          $t6, 0x5DA($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X5DA);
    // 0x800A4E34: nop

    // 0x800A4E38: bne         $t6, $zero, L_800A4E78
    if (ctx->r14 != 0) {
        // 0x800A4E3C: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_800A4E78;
    }
    // 0x800A4E3C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A4E40: lb          $t7, 0x5DB($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X5DB);
    // 0x800A4E44: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4E48: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x800A4E4C: bne         $at, $zero, L_800A4E74
    if (ctx->r1 != 0) {
        // 0x800A4E50: addiu       $a1, $a1, 0x7300
        ctx->r5 = ADD32(ctx->r5, 0X7300);
            goto L_800A4E74;
    }
    // 0x800A4E50: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A4E54: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A4E58: sb          $t8, 0x5DA($s1)
    MEM_B(0X5DA, ctx->r17) = ctx->r24;
    // 0x800A4E5C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A4E60: nop

    // 0x800A4E64: bne         $t9, $zero, L_800A4E78
    if (ctx->r25 != 0) {
        // 0x800A4E68: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_800A4E78;
    }
    // 0x800A4E68: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A4E6C: jal         0x80001D04
    // 0x800A4E70: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    sound_play(rdram, ctx);
        goto after_1;
    // 0x800A4E70: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    after_1:
L_800A4E74:
    // 0x800A4E74: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
L_800A4E78:
    // 0x800A4E78: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x800A4E7C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800A4E80: addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
    // 0x800A4E84: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A4E88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4E8C: swc1        $f18, 0x5D0($t1)
    MEM_W(0X5D0, ctx->r9) = ctx->f18.u32l;
    // 0x800A4E90: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4E94: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800A4E98: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800A4E9C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800A4EA0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4EA4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A4EA8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A4EAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A4EB0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A4EB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4EB8: sw          $t2, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r10;
    // 0x800A4EBC: jr          $ra
    // 0x800A4EC0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800A4EC0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void hud_race_finish_1player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4EC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A4EC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A4ECC: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A4ED0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A4ED4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4ED8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A4EDC: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
    // 0x800A4EE0: addiu       $a3, $v0, 0x700
    ctx->r7 = ADD32(ctx->r2, 0X700);
    // 0x800A4EE4: lb          $v1, 0x1A($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1A);
    // 0x800A4EE8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800A4EEC: beq         $v1, $zero, L_800A4F1C
    if (ctx->r3 == 0) {
        // 0x800A4EF0: addiu       $s0, $v0, 0x740
        ctx->r16 = ADD32(ctx->r2, 0X740);
            goto L_800A4F1C;
    }
    // 0x800A4EF0: addiu       $s0, $v0, 0x740
    ctx->r16 = ADD32(ctx->r2, 0X740);
    // 0x800A4EF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A4EF8: beq         $v1, $at, L_800A4F78
    if (ctx->r3 == ctx->r1) {
        // 0x800A4EFC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800A4F78;
    }
    // 0x800A4EFC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A4F00: beq         $v1, $v0, L_800A5080
    if (ctx->r3 == ctx->r2) {
        // 0x800A4F04: sll         $t3, $a1, 2
        ctx->r11 = S32(ctx->r5 << 2);
            goto L_800A5080;
    }
    // 0x800A4F04: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x800A4F08: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800A4F0C: beq         $v1, $v0, L_800A50E0
    if (ctx->r3 == ctx->r2) {
        // 0x800A4F10: nop
    
            goto L_800A50E0;
    }
    // 0x800A4F10: nop

    // 0x800A4F14: b           L_800A50E8
    // 0x800A4F18: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
        goto L_800A50E8;
    // 0x800A4F18: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
L_800A4F1C:
    // 0x800A4F1C: jal         0x80000BE0
    // 0x800A4F20: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    music_voicelimit_set(rdram, ctx);
        goto after_0;
    // 0x800A4F20: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A4F24: jal         0x80000B34
    // 0x800A4F28: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    music_play(rdram, ctx);
        goto after_1;
    // 0x800A4F28: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_1:
    // 0x800A4F2C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A4F30: jal         0x80001D04
    // 0x800A4F34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800A4F34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800A4F38: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4F3C: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A4F40: jal         0x80001D04
    // 0x800A4F44: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A4F44: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    after_3:
    // 0x800A4F48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A4F4C: addiu       $v0, $v0, 0x2CF0
    ctx->r2 = ADD32(ctx->r2, 0X2CF0);
    // 0x800A4F50: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800A4F54: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x800A4F58: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // 0x800A4F5C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800A4F60: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800A4F64: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4F68: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A4F6C: sb          $t8, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r24;
    // 0x800A4F70: b           L_800A50E4
    // 0x800A4F74: sb          $t9, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r25;
        goto L_800A50E4;
    // 0x800A4F74: sb          $t9, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r25;
L_800A4F78:
    // 0x800A4F78: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x800A4F7C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x800A4F80: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800A4F84: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x800A4F88: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A4F8C: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A4F90: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A4F94: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    // 0x800A4F98: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A4F9C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A4FA0: swc1        $f8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f8.u32l;
    // 0x800A4FA4: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A4FA8: nop

    // 0x800A4FAC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800A4FB0: nop

    // 0x800A4FB4: bc1f        L_800A4FC0
    if (!c1cs) {
        // 0x800A4FB8: nop
    
            goto L_800A4FC0;
    }
    // 0x800A4FB8: nop

    // 0x800A4FBC: swc1        $f2, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f2.u32l;
L_800A4FC0:
    // 0x800A4FC0: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A4FC4: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x800A4FC8: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800A4FCC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A4FD0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x800A4FD4: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A4FD8: nop

    // 0x800A4FDC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800A4FE0: nop

    // 0x800A4FE4: bc1f        L_800A4FF8
    if (!c1cs) {
        // 0x800A4FE8: nop
    
            goto L_800A4FF8;
    }
    // 0x800A4FE8: nop

    // 0x800A4FEC: swc1        $f12, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f12.u32l;
    // 0x800A4FF0: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A4FF4: nop

L_800A4FF8:
    // 0x800A4FF8: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x800A4FFC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800A5000: bc1f        L_800A50E4
    if (!c1cs) {
        // 0x800A5004: sb          $t1, 0x27($sp)
        MEM_B(0X27, ctx->r29) = ctx->r9;
            goto L_800A50E4;
    }
    // 0x800A5004: sb          $t1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r9;
    // 0x800A5008: lb          $t2, 0x1B($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X1B);
    // 0x800A500C: addiu       $t5, $zero, -0x78
    ctx->r13 = ADD32(0, -0X78);
    // 0x800A5010: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x800A5014: sb          $t3, 0x1B($a3)
    MEM_B(0X1B, ctx->r7) = ctx->r11;
    // 0x800A5018: lb          $t4, 0x1B($a3)
    ctx->r12 = MEM_B(ctx->r7, 0X1B);
    // 0x800A501C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5020: slti        $at, $t4, 0x78
    ctx->r1 = SIGNED(ctx->r12) < 0X78 ? 1 : 0;
    // 0x800A5024: bne         $at, $zero, L_800A503C
    if (ctx->r1 != 0) {
        // 0x800A5028: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800A503C;
    }
    // 0x800A5028: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A502C: lb          $t6, 0x1C($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X1C);
    // 0x800A5030: sb          $t5, 0x1B($a3)
    MEM_B(0X1B, ctx->r7) = ctx->r13;
    // 0x800A5034: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A5038: sb          $t7, 0x1C($a3)
    MEM_B(0X1C, ctx->r7) = ctx->r15;
L_800A503C:
    // 0x800A503C: lb          $t8, 0x1C($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1C);
    // 0x800A5040: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A5044: bne         $v0, $t8, L_800A50E8
    if (ctx->r2 != ctx->r24) {
        // 0x800A5048: lb          $t5, 0x27($sp)
        ctx->r13 = MEM_B(ctx->r29, 0X27);
            goto L_800A50E8;
    }
    // 0x800A5048: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
    // 0x800A504C: sb          $v0, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r2;
    // 0x800A5050: jal         0x80001D04
    // 0x800A5054: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x800A5054: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_4:
    // 0x800A5058: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800A505C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A5060: addiu       $v0, $v0, 0x2CF0
    ctx->r2 = ADD32(ctx->r2, 0X2CF0);
    // 0x800A5064: lb          $t1, 0xC($v0)
    ctx->r9 = MEM_B(ctx->r2, 0XC);
    // 0x800A5068: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800A506C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A5070: bne         $t0, $t1, L_800A50E4
    if (ctx->r8 != ctx->r9) {
        // 0x800A5074: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_800A50E4;
    }
    // 0x800A5074: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800A5078: b           L_800A50E4
    // 0x800A507C: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
        goto L_800A50E4;
    // 0x800A507C: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
L_800A5080:
    // 0x800A5080: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x800A5084: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A5088: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x800A508C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800A5090: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A5094: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5098: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A509C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800A50A0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A50A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A50A8: swc1        $f8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f8.u32l;
    // 0x800A50AC: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A50B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800A50B4: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A50B8: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800A50BC: sb          $t4, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r12;
    // 0x800A50C0: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A50C4: nop

    // 0x800A50C8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800A50CC: nop

    // 0x800A50D0: bc1f        L_800A50E8
    if (!c1cs) {
        // 0x800A50D4: lb          $t5, 0x27($sp)
        ctx->r13 = MEM_B(ctx->r29, 0X27);
            goto L_800A50E8;
    }
    // 0x800A50D4: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
    // 0x800A50D8: b           L_800A50E4
    // 0x800A50DC: sb          $v0, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r2;
        goto L_800A50E4;
    // 0x800A50DC: sb          $v0, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r2;
L_800A50E0:
    // 0x800A50E0: sb          $v0, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r2;
L_800A50E4:
    // 0x800A50E4: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
L_800A50E8:
    // 0x800A50E8: nop

    // 0x800A50EC: beq         $t5, $zero, L_800A516C
    if (ctx->r13 == 0) {
        // 0x800A50F0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A516C;
    }
    // 0x800A50F0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A50F4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A50F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A50FC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800A5100: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800A5104: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A5108: addiu       $t8, $zero, -0x2E
    ctx->r24 = ADD32(0, -0X2E);
    // 0x800A510C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5110: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5114: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5118: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A511C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800A5120: jal         0x800AAB5C
    // 0x800A5124: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A5124: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    after_5:
    // 0x800A5128: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A512C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5130: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5134: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5138: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A513C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5140: jal         0x800AAB5C
    // 0x800A5144: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A5144: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x800A5148: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A514C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5150: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A5154: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x800A5158: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800A515C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800A5160: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800A5164: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800A5168: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800A516C:
    // 0x800A516C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A5174: jr          $ra
    // 0x800A5178: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A5178: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800A4C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A517C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800A5180: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800A5184: jr          $ra
    // 0x800A5188: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800A5188: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
