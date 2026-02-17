#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void debug_render_checkpoints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BB9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001BBA0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8001BBA4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001BBA8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8001BBAC: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8001BBB0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001BBB4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001BBB8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001BBBC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8001BBC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001BBC4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8001BBC8: jal         0x8007B918
    // 0x8001BBCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x8001BBCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8001BBD0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8001BBD4: addiu       $s4, $s4, -0x4BB0
    ctx->r20 = ADD32(ctx->r20, -0X4BB0);
    // 0x8001BBD8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8001BBDC: nop

    // 0x8001BBE0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8001BBE4: bne         $at, $zero, L_8001BC58
    if (ctx->r1 != 0) {
        // 0x8001BBE8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001BC58;
    }
    // 0x8001BBE8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001BBEC: blez        $v0, L_8001BC24
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001BBF0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001BC24;
    }
    // 0x8001BBF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001BBF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001BBF8:
    // 0x8001BBF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001BBFC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8001BC00: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8001BC04: jal         0x8001BC74
    // 0x8001BC08: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    debug_render_checkpoint_node(rdram, ctx);
        goto after_1;
    // 0x8001BC08: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_1:
    // 0x8001BC0C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8001BC10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001BC14: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BC18: bne         $at, $zero, L_8001BBF8
    if (ctx->r1 != 0) {
        // 0x8001BC1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001BBF8;
    }
    // 0x8001BC1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001BC20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001BC24:
    // 0x8001BC24: blez        $v0, L_8001BC54
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001BC28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001BC54;
    }
    // 0x8001BC28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001BC2C:
    // 0x8001BC2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001BC30: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8001BC34: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8001BC38: jal         0x8001BC74
    // 0x8001BC3C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    debug_render_checkpoint_node(rdram, ctx);
        goto after_2;
    // 0x8001BC3C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_2:
    // 0x8001BC40: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8001BC44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001BC48: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001BC4C: bne         $at, $zero, L_8001BC2C
    if (ctx->r1 != 0) {
        // 0x8001BC50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001BC2C;
    }
    // 0x8001BC50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001BC54:
    // 0x8001BC54: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001BC58:
    // 0x8001BC58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001BC5C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001BC60: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8001BC64: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8001BC68: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8001BC6C: jr          $ra
    // 0x8001BC70: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001BC70: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void debug_render_checkpoint_node(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC74: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001BC78: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001BC7C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001BC80: jr          $ra
    // 0x8001BC84: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x8001BC84: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void spectate_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC88: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001BC8C: addiu       $a3, $a3, -0x4BA0
    ctx->r7 = ADD32(ctx->r7, -0X4BA0);
    // 0x8001BC90: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8001BC94: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001BC98: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x8001BC9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BCA0: blez        $v1, L_8001BD3C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001BCA4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001BD3C;
    }
    // 0x8001BCA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001BCA8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001BCAC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8001BCB0: addiu       $t0, $t0, -0x4C28
    ctx->r8 = ADD32(ctx->r8, -0X4C28);
    // 0x8001BCB4: addiu       $t2, $t2, -0x4BA4
    ctx->r10 = ADD32(ctx->r10, -0X4BA4);
    // 0x8001BCB8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
L_8001BCBC:
    // 0x8001BCBC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8001BCC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001BCC4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8001BCC8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8001BCCC: nop

    // 0x8001BCD0: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x8001BCD4: nop

    // 0x8001BCD8: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8001BCDC: bne         $t9, $zero, L_8001BD34
    if (ctx->r25 != 0) {
        // 0x8001BCE0: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001BD34;
    }
    // 0x8001BCE0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001BCE4: lh          $t3, 0x48($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X48);
    // 0x8001BCE8: nop

    // 0x8001BCEC: bne         $t1, $t3, L_8001BD34
    if (ctx->r9 != ctx->r11) {
        // 0x8001BCF0: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001BD34;
    }
    // 0x8001BCF0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001BCF4: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8001BCF8: nop

    // 0x8001BCFC: slti        $at, $a2, 0x14
    ctx->r1 = SIGNED(ctx->r6) < 0X14 ? 1 : 0;
    // 0x8001BD00: beq         $at, $zero, L_8001BD34
    if (ctx->r1 == 0) {
        // 0x8001BD04: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001BD34;
    }
    // 0x8001BD04: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001BD08: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8001BD0C: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x8001BD10: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8001BD14: sw          $a0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r4;
    // 0x8001BD18: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8001BD1C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001BD20: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001BD24: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8001BD28: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x8001BD2C: nop

    // 0x8001BD30: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001BD34:
    // 0x8001BD34: bne         $at, $zero, L_8001BCBC
    if (ctx->r1 != 0) {
        // 0x8001BD38: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001BCBC;
    }
    // 0x8001BD38: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001BD3C:
    // 0x8001BD3C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001BD40: lw          $a2, -0x4BA0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4BA0);
    // 0x8001BD44: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001BD48: addiu       $t2, $t2, -0x4BA4
    ctx->r10 = ADD32(ctx->r10, -0X4BA4);
    // 0x8001BD4C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001BD50: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001BD54:
    // 0x8001BD54: blez        $a2, L_8001BDB8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001BD58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001BDB8;
    }
    // 0x8001BD58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BD5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001BD60:
    // 0x8001BD60: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8001BD64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001BD68: addu        $a3, $t9, $a1
    ctx->r7 = ADD32(ctx->r25, ctx->r5);
    // 0x8001BD6C: lw          $t0, 0x4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4);
    // 0x8001BD70: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8001BD74: lw          $t3, 0x78($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X78);
    // 0x8001BD78: lw          $t4, 0x78($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X78);
    // 0x8001BD7C: nop

    // 0x8001BD80: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001BD84: beq         $at, $zero, L_8001BDB0
    if (ctx->r1 == 0) {
        // 0x8001BD88: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001BDB0;
    }
    // 0x8001BD88: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001BD8C: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x8001BD90: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8001BD94: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001BD98: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x8001BD9C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8001BDA0: lw          $a2, -0x4BA0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4BA0);
    // 0x8001BDA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001BDA8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001BDAC: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
L_8001BDB0:
    // 0x8001BDB0: bne         $at, $zero, L_8001BD60
    if (ctx->r1 != 0) {
        // 0x8001BDB4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001BD60;
    }
    // 0x8001BDB4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001BDB8:
    // 0x8001BDB8: beq         $v1, $zero, L_8001BD54
    if (ctx->r3 == 0) {
        // 0x8001BDBC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8001BD54;
    }
    // 0x8001BDBC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001BDC0: jr          $ra
    // 0x8001BDC4: nop

    return;
    // 0x8001BDC4: nop

;}
RECOMP_FUNC void spectate_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BDC8: bltz        $a0, L_8001BDE4
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001BDCC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001BDE4;
    }
    // 0x8001BDCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001BDD0: lw          $t6, -0x4BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BA0);
    // 0x8001BDD4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001BDD8: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001BDDC: bne         $at, $zero, L_8001BDEC
    if (ctx->r1 != 0) {
        // 0x8001BDE0: nop
    
            goto L_8001BDEC;
    }
    // 0x8001BDE0: nop

L_8001BDE4:
    // 0x8001BDE4: jr          $ra
    // 0x8001BDE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BDE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BDEC:
    // 0x8001BDEC: lw          $t7, -0x4BA4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4BA4);
    // 0x8001BDF0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8001BDF4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001BDF8: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8001BDFC: nop

    // 0x8001BE00: jr          $ra
    // 0x8001BE04: nop

    return;
    // 0x8001BE04: nop

;}
RECOMP_FUNC void spectate_nearest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BE08: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BE0C: lw          $v0, -0x4BA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BA0);
    // 0x8001BE10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001BE14: bne         $v0, $zero, L_8001BE24
    if (ctx->r2 != 0) {
        // 0x8001BE18: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8001BE24;
    }
    // 0x8001BE18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001BE1C: b           L_8001BF4C
    // 0x8001BE20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001BF4C;
    // 0x8001BE20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BE24:
    // 0x8001BE24: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8001BE28: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001BE2C: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8001BE30: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BE34: bne         $at, $zero, L_8001BE40
    if (ctx->r1 != 0) {
        // 0x8001BE38: addiu       $a2, $a0, -0x1
        ctx->r6 = ADD32(ctx->r4, -0X1);
            goto L_8001BE40;
    }
    // 0x8001BE38: addiu       $a2, $a0, -0x1
    ctx->r6 = ADD32(ctx->r4, -0X1);
    // 0x8001BE3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001BE40:
    // 0x8001BE40: bgez        $a2, L_8001BE4C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8001BE44: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8001BE4C;
    }
    // 0x8001BE44: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001BE48: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
L_8001BE4C:
    // 0x8001BE4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BE50: lw          $v0, -0x4BA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BA4);
    // 0x8001BE54: lwc1        $f2, 0xC($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8001BE58: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8001BE5C: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x8001BE60: lwc1        $f14, 0x10($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8001BE64: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8001BE68: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8001BE6C: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8001BE70: lwc1        $f18, 0x14($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8001BE74: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001BE78: sub.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8001BE7C: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8001BE80: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8001BE84: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001BE88: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8001BE8C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8001BE90: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8001BE94: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001BE98: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001BE9C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8001BEA0: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8001BEA4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001BEA8: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x8001BEAC: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x8001BEB0: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8001BEB4: lwc1        $f6, 0x10($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8001BEB8: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8001BEBC: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8001BEC0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001BEC4: sub.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8001BEC8: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001BECC: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8001BED0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001BED4: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001BED8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001BEDC: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x8001BEE0: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8001BEE4: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8001BEE8: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8001BEEC: lwc1        $f4, 0x10($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X10);
    // 0x8001BEF0: lwc1        $f8, 0x14($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X14);
    // 0x8001BEF4: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8001BEF8: bc1f        L_8001BF10
    if (!c1cs) {
        // 0x8001BEFC: sub.s       $f16, $f8, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
            goto L_8001BF10;
    }
    // 0x8001BEFC: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8001BF00: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8001BF04: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8001BF08: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x8001BF0C: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
L_8001BF10:
    // 0x8001BF10: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001BF14: nop

    // 0x8001BF18: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001BF1C: nop

    // 0x8001BF20: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001BF24: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001BF28: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8001BF2C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001BF30: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8001BF34: nop

    // 0x8001BF38: bc1f        L_8001BF48
    if (!c1cs) {
        // 0x8001BF3C: nop
    
            goto L_8001BF48;
    }
    // 0x8001BF3C: nop

    // 0x8001BF40: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x8001BF44: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
L_8001BF48:
    // 0x8001BF48: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8001BF4C:
    // 0x8001BF4C: jr          $ra
    // 0x8001BF50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001BF50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ainode_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BF54: addiu       $sp, $sp, -0x190
    ctx->r29 = ADD32(ctx->r29, -0X190);
    // 0x8001BF58: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BF5C: addiu       $v0, $v0, -0x4B70
    ctx->r2 = ADD32(ctx->r2, -0X4B70);
    // 0x8001BF60: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001BF64: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001BF68: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001BF6C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001BF70: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001BF74: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001BF78: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001BF7C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001BF80: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001BF84: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001BF88: beq         $t6, $zero, L_8001C41C
    if (ctx->r14 == 0) {
        // 0x8001BF8C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8001C41C;
    }
    // 0x8001BF8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001BF90: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001BF94: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8001BF98: addiu       $t2, $t2, -0x4B7C
    ctx->r10 = ADD32(ctx->r10, -0X4B7C);
    // 0x8001BF9C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_8001BFA0:
    // 0x8001BFA0: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8001BFA4: nop

    // 0x8001BFA8: addu        $t8, $t7, $fp
    ctx->r24 = ADD32(ctx->r15, ctx->r30);
    // 0x8001BFAC: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x8001BFB0: slti        $at, $fp, 0x200
    ctx->r1 = SIGNED(ctx->r30) < 0X200 ? 1 : 0;
    // 0x8001BFB4: bne         $at, $zero, L_8001BFA0
    if (ctx->r1 != 0) {
        // 0x8001BFB8: sw          $zero, 0x0($t8)
        MEM_W(0X0, ctx->r24) = 0;
            goto L_8001BFA0;
    }
    // 0x8001BFB8: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8001BFBC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001BFC0: lw          $a0, -0x4C24($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C24);
    // 0x8001BFC4: sh          $zero, 0x186($sp)
    MEM_H(0X186, ctx->r29) = 0;
    // 0x8001BFC8: blez        $a0, L_8001C080
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001BFCC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001C080;
    }
    // 0x8001BFCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001BFD0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001BFD4: addiu       $a1, $a1, -0x4C28
    ctx->r5 = ADD32(ctx->r5, -0X4C28);
    // 0x8001BFD8: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8001BFDC: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x8001BFE0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_8001BFE4:
    // 0x8001BFE4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8001BFE8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001BFEC: addu        $t3, $t9, $fp
    ctx->r11 = ADD32(ctx->r25, ctx->r30);
    // 0x8001BFF0: lw          $s3, 0x0($t3)
    ctx->r19 = MEM_W(ctx->r11, 0X0);
    // 0x8001BFF4: nop

    // 0x8001BFF8: lh          $t4, 0x6($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X6);
    // 0x8001BFFC: nop

    // 0x8001C000: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8001C004: bne         $t5, $zero, L_8001C078
    if (ctx->r13 != 0) {
        // 0x8001C008: slt         $at, $a3, $a0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8001C078;
    }
    // 0x8001C008: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001C00C: lh          $t6, 0x48($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X48);
    // 0x8001C010: nop

    // 0x8001C014: bne         $a2, $t6, L_8001C078
    if (ctx->r6 != ctx->r14) {
        // 0x8001C018: slt         $at, $a3, $a0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8001C078;
    }
    // 0x8001C018: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001C01C: lw          $v0, 0x3C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X3C);
    // 0x8001C020: nop

    // 0x8001C024: lbu         $v1, 0x9($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X9);
    // 0x8001C028: nop

    // 0x8001C02C: andi        $t7, $v1, 0x80
    ctx->r15 = ctx->r3 & 0X80;
    // 0x8001C030: bne         $t7, $zero, L_8001C074
    if (ctx->r15 != 0) {
        // 0x8001C034: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_8001C074;
    }
    // 0x8001C034: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8001C038: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8001C03C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001C040: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8001C044: sw          $s3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r19;
    // 0x8001C048: lh          $t5, 0x186($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X186);
    // 0x8001C04C: lbu         $t4, 0x9($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X9);
    // 0x8001C050: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x8001C054: sb          $t4, 0xE4($t6)
    MEM_B(0XE4, ctx->r14) = ctx->r12;
    // 0x8001C058: lb          $t7, 0xE($v0)
    ctx->r15 = MEM_B(ctx->r2, 0XE);
    // 0x8001C05C: addu        $t9, $s7, $t5
    ctx->r25 = ADD32(ctx->r23, ctx->r13);
    // 0x8001C060: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x8001C064: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8001C068: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x8001C06C: lw          $a0, -0x4C24($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C24);
    // 0x8001C070: sh          $t3, 0x186($sp)
    MEM_H(0X186, ctx->r29) = ctx->r11;
L_8001C074:
    // 0x8001C074: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
L_8001C078:
    // 0x8001C078: bne         $at, $zero, L_8001BFE4
    if (ctx->r1 != 0) {
        // 0x8001C07C: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_8001BFE4;
    }
    // 0x8001C07C: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
L_8001C080:
    // 0x8001C080: lh          $t4, 0x186($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X186);
    // 0x8001C084: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x8001C088: beq         $t4, $zero, L_8001C41C
    if (ctx->r12 == 0) {
        // 0x8001C08C: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_8001C41C;
    }
    // 0x8001C08C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8001C090: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8001C094: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
L_8001C098:
    // 0x8001C098: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8001C09C: nop

    // 0x8001C0A0: addu        $t7, $t6, $fp
    ctx->r15 = ADD32(ctx->r14, ctx->r30);
    // 0x8001C0A4: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x8001C0A8: nop

    // 0x8001C0AC: beq         $s3, $zero, L_8001C174
    if (ctx->r19 == 0) {
        // 0x8001C0B0: nop
    
            goto L_8001C174;
    }
    // 0x8001C0B0: nop

    // 0x8001C0B4: lw          $s4, 0x64($s3)
    ctx->r20 = MEM_W(ctx->r19, 0X64);
    // 0x8001C0B8: lw          $s0, 0x3C($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X3C);
    // 0x8001C0BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001C0C0:
    // 0x8001C0C0: lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA);
    // 0x8001C0C4: nop

    // 0x8001C0C8: andi        $t8, $v1, 0x80
    ctx->r24 = ctx->r3 & 0X80;
    // 0x8001C0CC: bne         $t8, $zero, L_8001C168
    if (ctx->r24 != 0) {
        // 0x8001C0D0: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_8001C168;
    }
    // 0x8001C0D0: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8001C0D4: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8001C0D8: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8001C0DC: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x8001C0E0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8001C0E4: addu        $t6, $s4, $t4
    ctx->r14 = ADD32(ctx->r20, ctx->r12);
    // 0x8001C0E8: bne         $v0, $zero, L_8001C0F8
    if (ctx->r2 != 0) {
        // 0x8001C0EC: sw          $v0, 0x0($t6)
        MEM_W(0X0, ctx->r14) = ctx->r2;
            goto L_8001C0F8;
    }
    // 0x8001C0EC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8001C0F0: b           L_8001C168
    // 0x8001C0F4: sb          $s5, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r21;
        goto L_8001C168;
    // 0x8001C0F4: sb          $s5, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r21;
L_8001C0F8:
    // 0x8001C0F8: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8001C0FC: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001C100: lwc1        $f8, 0x10($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001C104: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001C108: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C10C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001C110: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001C114: lwc1        $f16, 0x14($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001C118: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C11C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001C120: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8001C124: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x8001C128: addu        $s2, $s4, $t7
    ctx->r18 = ADD32(ctx->r20, ctx->r15);
    // 0x8001C12C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001C130: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001C134: jal         0x800CA030
    // 0x8001C138: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C138: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8001C13C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001C140: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001C144: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001C148: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001C14C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001C150: addiu       $t2, $t2, -0x4B7C
    ctx->r10 = ADD32(ctx->r10, -0X4B7C);
    // 0x8001C154: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8001C158: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8001C15C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001C160: sh          $t9, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r25;
    // 0x8001C164: nop

L_8001C168:
    // 0x8001C168: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001C16C: bne         $s1, $s6, L_8001C0C0
    if (ctx->r17 != ctx->r22) {
        // 0x8001C170: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001C0C0;
    }
    // 0x8001C170: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001C174:
    // 0x8001C174: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x8001C178: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x8001C17C: bne         $fp, $at, L_8001C098
    if (ctx->r30 != ctx->r1) {
        // 0x8001C180: nop
    
            goto L_8001C098;
    }
    // 0x8001C180: nop

    // 0x8001C184: lh          $t1, 0x186($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X186);
    // 0x8001C188: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001C18C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
L_8001C190:
    // 0x8001C190: blez        $t1, L_8001C2E0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001C194: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8001C2E0;
    }
    // 0x8001C194: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8001C198: lh          $v0, 0x186($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X186);
    // 0x8001C19C: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8001C1A0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001C1A4: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8001C1A8: beq         $t5, $zero, L_8001C210
    if (ctx->r13 == 0) {
        // 0x8001C1AC: addiu       $t7, $sp, 0xE4
        ctx->r15 = ADD32(ctx->r29, 0XE4);
            goto L_8001C210;
    }
    // 0x8001C1AC: addiu       $t7, $sp, 0xE4
    ctx->r15 = ADD32(ctx->r29, 0XE4);
    // 0x8001C1B0: lb          $t3, 0xE5($sp)
    ctx->r11 = MEM_B(ctx->r29, 0XE5);
    // 0x8001C1B4: lb          $t8, 0xE4($sp)
    ctx->r24 = MEM_B(ctx->r29, 0XE4);
    // 0x8001C1B8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001C1BC: addu        $t6, $t0, $t4
    ctx->r14 = ADD32(ctx->r8, ctx->r12);
    // 0x8001C1C0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001C1C4: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
    // 0x8001C1C8: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8001C1CC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001C1D0: lwc1        $f2, 0x10($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8001C1D4: lwc1        $f0, 0x10($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8001C1D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001C1DC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001C1E0: nop

    // 0x8001C1E4: bc1f        L_8001C208
    if (!c1cs) {
        // 0x8001C1E8: nop
    
            goto L_8001C208;
    }
    // 0x8001C1E8: nop

    // 0x8001C1EC: lb          $v0, 0x64($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X64);
    // 0x8001C1F0: lb          $t6, 0x65($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X65);
    // 0x8001C1F4: sb          $t3, 0xE4($sp)
    MEM_B(0XE4, ctx->r29) = ctx->r11;
    // 0x8001C1F8: sb          $t8, 0xE5($sp)
    MEM_B(0XE5, ctx->r29) = ctx->r24;
    // 0x8001C1FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C200: sb          $v0, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r2;
    // 0x8001C204: sb          $t6, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r14;
L_8001C208:
    // 0x8001C208: beq         $a3, $t1, L_8001C2DC
    if (ctx->r7 == ctx->r9) {
        // 0x8001C20C: addiu       $t7, $sp, 0xE4
        ctx->r15 = ADD32(ctx->r29, 0XE4);
            goto L_8001C2DC;
    }
    // 0x8001C20C: addiu       $t7, $sp, 0xE4
    ctx->r15 = ADD32(ctx->r29, 0XE4);
L_8001C210:
    // 0x8001C210: addu        $a0, $a3, $t7
    ctx->r4 = ADD32(ctx->r7, ctx->r15);
L_8001C214:
    // 0x8001C214: lb          $a1, 0x1($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X1);
    // 0x8001C218: lb          $a2, 0x0($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X0);
    // 0x8001C21C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8001C220: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8001C224: addu        $t3, $t0, $t8
    ctx->r11 = ADD32(ctx->r8, ctx->r24);
    // 0x8001C228: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
    // 0x8001C22C: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8001C230: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8001C234: lwc1        $f0, 0x10($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8001C238: lwc1        $f18, 0x10($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8001C23C: addu        $v1, $s7, $a3
    ctx->r3 = ADD32(ctx->r23, ctx->r7);
    // 0x8001C240: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8001C244: nop

    // 0x8001C248: bc1f        L_8001C284
    if (!c1cs) {
        // 0x8001C24C: nop
    
            goto L_8001C284;
    }
    // 0x8001C24C: nop

    // 0x8001C250: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x8001C254: sb          $a2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r6;
    // 0x8001C258: lb          $a1, 0x1($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X1);
    // 0x8001C25C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8001C260: lb          $t9, 0x1($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X1);
    // 0x8001C264: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x8001C268: addu        $t4, $t0, $t5
    ctx->r12 = ADD32(ctx->r8, ctx->r13);
    // 0x8001C26C: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8001C270: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x8001C274: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8001C278: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C27C: lwc1        $f0, 0x10($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8001C280: nop

L_8001C284:
    // 0x8001C284: lb          $a2, 0x2($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X2);
    // 0x8001C288: addu        $v1, $s7, $a3
    ctx->r3 = ADD32(ctx->r23, ctx->r7);
    // 0x8001C28C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x8001C290: addu        $t6, $t0, $t3
    ctx->r14 = ADD32(ctx->r8, ctx->r11);
    // 0x8001C294: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001C298: nop

    // 0x8001C29C: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8001C2A0: nop

    // 0x8001C2A4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8001C2A8: nop

    // 0x8001C2AC: bc1f        L_8001C2D0
    if (!c1cs) {
        // 0x8001C2B0: nop
    
            goto L_8001C2D0;
    }
    // 0x8001C2B0: nop

    // 0x8001C2B4: lb          $v0, 0x1($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1);
    // 0x8001C2B8: lb          $t5, 0x2($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X2);
    // 0x8001C2BC: sb          $a2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r6;
    // 0x8001C2C0: sb          $a1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r5;
    // 0x8001C2C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C2C8: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x8001C2CC: sb          $t5, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r13;
L_8001C2D0:
    // 0x8001C2D0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8001C2D4: bne         $a3, $t1, L_8001C214
    if (ctx->r7 != ctx->r9) {
        // 0x8001C2D8: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_8001C214;
    }
    // 0x8001C2D8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_8001C2DC:
    // 0x8001C2DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8001C2E0:
    // 0x8001C2E0: beq         $s1, $zero, L_8001C190
    if (ctx->r17 == 0) {
        // 0x8001C2E4: nop
    
            goto L_8001C190;
    }
    // 0x8001C2E4: nop

    // 0x8001C2E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C2EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001C2F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001C2F4: lwc1        $f0, 0x5BC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5BC8);
    // 0x8001C2F8: addiu       $v1, $v1, -0x4B54
    ctx->r3 = ADD32(ctx->r3, -0X4B54);
    // 0x8001C2FC: addiu       $v0, $v0, -0x4B68
    ctx->r2 = ADD32(ctx->r2, -0X4B68);
L_8001C300:
    // 0x8001C300: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001C304: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8001C308: bne         $at, $zero, L_8001C300
    if (ctx->r1 != 0) {
        // 0x8001C30C: swc1        $f0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
            goto L_8001C300;
    }
    // 0x8001C30C: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8001C310: lb          $v0, 0x64($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X64);
    // 0x8001C314: blez        $t1, L_8001C3F8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001C318: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001C3F8;
    }
    // 0x8001C318: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001C31C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8001C320: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001C324: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8001C328: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001C32C: addiu       $a2, $a2, -0x4B68
    ctx->r6 = ADD32(ctx->r6, -0X4B68);
    // 0x8001C330: addiu       $t4, $sp, 0x64
    ctx->r12 = ADD32(ctx->r29, 0X64);
L_8001C334:
    // 0x8001C334: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001C338: beq         $at, $zero, L_8001C378
    if (ctx->r1 == 0) {
        // 0x8001C33C: addu        $v1, $a3, $t4
        ctx->r3 = ADD32(ctx->r7, ctx->r12);
            goto L_8001C378;
    }
    // 0x8001C33C: addu        $v1, $a3, $t4
    ctx->r3 = ADD32(ctx->r7, ctx->r12);
    // 0x8001C340: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x8001C344: nop

    // 0x8001C348: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001C34C: bne         $at, $zero, L_8001C378
    if (ctx->r1 != 0) {
        // 0x8001C350: nop
    
            goto L_8001C378;
    }
    // 0x8001C350: nop

L_8001C354:
    // 0x8001C354: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001C358: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001C35C: beq         $at, $zero, L_8001C378
    if (ctx->r1 == 0) {
        // 0x8001C360: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001C378;
    }
    // 0x8001C360: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001C364: lb          $t3, 0x0($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X0);
    // 0x8001C368: nop

    // 0x8001C36C: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001C370: beq         $at, $zero, L_8001C354
    if (ctx->r1 == 0) {
        // 0x8001C374: nop
    
            goto L_8001C354;
    }
    // 0x8001C374: nop

L_8001C378:
    // 0x8001C378: lb          $a1, 0x0($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X0);
    // 0x8001C37C: addiu       $t7, $sp, 0xE4
    ctx->r15 = ADD32(ctx->r29, 0XE4);
    // 0x8001C380: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001C384: beq         $at, $zero, L_8001C3E4
    if (ctx->r1 == 0) {
        // 0x8001C388: addu        $a0, $a3, $t7
        ctx->r4 = ADD32(ctx->r7, ctx->r15);
            goto L_8001C3E4;
    }
    // 0x8001C388: addu        $a0, $a3, $t7
    ctx->r4 = ADD32(ctx->r7, ctx->r15);
    // 0x8001C38C: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x8001C390: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8001C394: lb          $t9, -0x1($a0)
    ctx->r25 = MEM_B(ctx->r4, -0X1);
    // 0x8001C398: lb          $t3, 0x0($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X0);
    // 0x8001C39C: sra         $t6, $v0, 24
    ctx->r14 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8001C3A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8001C3A4: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8001C3A8: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8001C3AC: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8001C3B0: addu        $t4, $t0, $t5
    ctx->r12 = ADD32(ctx->r8, ctx->r13);
    // 0x8001C3B4: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8001C3B8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001C3BC: lwc1        $f6, 0x10($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8001C3C0: lwc1        $f8, 0x10($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8001C3C4: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8001C3C8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001C3CC: addu        $t4, $a2, $t5
    ctx->r12 = ADD32(ctx->r6, ctx->r13);
    // 0x8001C3D0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8001C3D4: mul.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x8001C3D8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8001C3DC: b           L_8001C3EC
    // 0x8001C3E0: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
        goto L_8001C3EC;
    // 0x8001C3E0: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
L_8001C3E4:
    // 0x8001C3E4: lh          $a3, 0x186($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X186);
    // 0x8001C3E8: nop

L_8001C3EC:
    // 0x8001C3EC: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001C3F0: bne         $at, $zero, L_8001C334
    if (ctx->r1 != 0) {
        // 0x8001C3F4: addiu       $t4, $sp, 0x64
        ctx->r12 = ADD32(ctx->r29, 0X64);
            goto L_8001C334;
    }
    // 0x8001C3F4: addiu       $t4, $sp, 0x64
    ctx->r12 = ADD32(ctx->r29, 0X64);
L_8001C3F8:
    // 0x8001C3F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C3FC: lwc1        $f6, 0x5BCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5BCC);
    // 0x8001C400: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001C404: addiu       $a2, $a2, -0x4B68
    ctx->r6 = ADD32(ctx->r6, -0X4B68);
    // 0x8001C408: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8001C40C: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001C410: nop

    // 0x8001C414: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001C418: swc1        $f10, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f10.u32l;
L_8001C41C:
    // 0x8001C41C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001C420: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C424: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C428: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001C42C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001C430: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001C434: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C438: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001C43C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001C440: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001C444: jr          $ra
    // 0x8001C448: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
    return;
    // 0x8001C448: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
;}
RECOMP_FUNC void obj_elevation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C44C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C450: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001C454: lwc1        $f2, 0x5BD0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5BD0);
    // 0x8001C458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001C45C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001C460: addiu       $a0, $a0, -0x4B68
    ctx->r4 = ADD32(ctx->r4, -0X4B68);
    // 0x8001C464: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_8001C468:
    // 0x8001C468: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8001C46C: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8001C470: nop

    // 0x8001C474: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8001C478: nop

    // 0x8001C47C: bc1t        L_8001C4A0
    if (c1cs) {
        // 0x8001C480: nop
    
            goto L_8001C4A0;
    }
    // 0x8001C480: nop

    // 0x8001C484: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8001C488: nop

    // 0x8001C48C: bc1f        L_8001C4A0
    if (!c1cs) {
        // 0x8001C490: nop
    
            goto L_8001C4A0;
    }
    // 0x8001C490: nop

    // 0x8001C494: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8001C498: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001C49C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8001C4A0:
    // 0x8001C4A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001C4A4: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8001C4A8: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001C4AC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8001C4B0: bne         $at, $zero, L_8001C468
    if (ctx->r1 != 0) {
        // 0x8001C4B4: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8001C468;
    }
    // 0x8001C4B4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001C4B8: jr          $ra
    // 0x8001C4BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001C4BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ainode_register(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C4C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001C4C4: lw          $a1, -0x4B7C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4B7C);
    // 0x8001C4C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001C4CC: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_8001C4D0:
    // 0x8001C4D0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8001C4D4: nop

    // 0x8001C4D8: bne         $t6, $zero, L_8001C4EC
    if (ctx->r14 != 0) {
        // 0x8001C4DC: nop
    
            goto L_8001C4EC;
    }
    // 0x8001C4DC: nop

    // 0x8001C4E0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8001C4E4: jr          $ra
    // 0x8001C4E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001C4E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001C4EC:
    // 0x8001C4EC: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8001C4F0: nop

    // 0x8001C4F4: bne         $t7, $zero, L_8001C508
    if (ctx->r15 != 0) {
        // 0x8001C4F8: nop
    
            goto L_8001C508;
    }
    // 0x8001C4F8: nop

    // 0x8001C4FC: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x8001C500: jr          $ra
    // 0x8001C504: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x8001C504: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8001C508:
    // 0x8001C508: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8001C50C: nop

    // 0x8001C510: bne         $t8, $zero, L_8001C524
    if (ctx->r24 != 0) {
        // 0x8001C514: nop
    
            goto L_8001C524;
    }
    // 0x8001C514: nop

    // 0x8001C518: sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
    // 0x8001C51C: jr          $ra
    // 0x8001C520: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x8001C520: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
L_8001C524:
    // 0x8001C524: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x8001C528: nop

    // 0x8001C52C: bne         $t9, $zero, L_8001C540
    if (ctx->r25 != 0) {
        // 0x8001C530: nop
    
            goto L_8001C540;
    }
    // 0x8001C530: nop

    // 0x8001C534: sw          $a0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r4;
    // 0x8001C538: jr          $ra
    // 0x8001C53C: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x8001C53C: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
L_8001C540:
    // 0x8001C540: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001C544: bne         $v1, $v0, L_8001C4D0
    if (ctx->r3 != ctx->r2) {
        // 0x8001C548: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_8001C4D0;
    }
    // 0x8001C548: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8001C54C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8001C550: jr          $ra
    // 0x8001C554: nop

    return;
    // 0x8001C554: nop

;}
RECOMP_FUNC void ainode_find_nearest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C558: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8001C55C: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8001C560: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8001C564: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8001C568: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8001C56C: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8001C570: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8001C574: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8001C578: mov.s       $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    ctx->f22.fl = ctx->f14.fl;
    // 0x8001C57C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x8001C580: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8001C584: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8001C588: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8001C58C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8001C590: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8001C594: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8001C598: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8001C59C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8001C5A0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8001C5A4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001C5A8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8001C5AC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001C5B0: beq         $a3, $zero, L_8001C5C4
    if (ctx->r7 == 0) {
        // 0x8001C5B4: swc1        $f20, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
            goto L_8001C5C4;
    }
    // 0x8001C5B4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8001C5B8: jal         0x8001C44C
    // 0x8001C5BC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    obj_elevation(rdram, ctx);
        goto after_0;
    // 0x8001C5BC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_0:
    // 0x8001C5C0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
L_8001C5C4:
    // 0x8001C5C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C5C8: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8001C5CC: lw          $fp, 0x64($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X64);
    // 0x8001C5D0: lwc1        $f20, 0x5BD4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5BD4);
    // 0x8001C5D4: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8001C5D8: addiu       $s3, $s3, -0x4B7C
    ctx->r19 = ADD32(ctx->r19, -0X4B7C);
    // 0x8001C5DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001C5E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C5E4: addiu       $s6, $zero, 0x80
    ctx->r22 = ADD32(0, 0X80);
    // 0x8001C5E8: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x8001C5EC: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_8001C5F0:
    // 0x8001C5F0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8001C5F4: nop

    // 0x8001C5F8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8001C5FC: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8001C600: nop

    // 0x8001C604: beq         $v0, $zero, L_8001C698
    if (ctx->r2 == 0) {
        // 0x8001C608: nop
    
            goto L_8001C698;
    }
    // 0x8001C608: nop

    // 0x8001C60C: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x8001C610: beq         $s2, $zero, L_8001C62C
    if (ctx->r18 == 0) {
        // 0x8001C614: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8001C62C;
    }
    // 0x8001C614: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001C618: lb          $t8, 0xE($v1)
    ctx->r24 = MEM_B(ctx->r3, 0XE);
    // 0x8001C61C: nop

    // 0x8001C620: beq         $fp, $t8, L_8001C62C
    if (ctx->r30 == ctx->r24) {
        // 0x8001C624: nop
    
            goto L_8001C62C;
    }
    // 0x8001C624: nop

    // 0x8001C628: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001C62C:
    // 0x8001C62C: bne         $s2, $s4, L_8001C648
    if (ctx->r18 != ctx->r20) {
        // 0x8001C630: nop
    
            goto L_8001C648;
    }
    // 0x8001C630: nop

    // 0x8001C634: lbu         $t9, 0x8($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X8);
    // 0x8001C638: nop

    // 0x8001C63C: beq         $s5, $t9, L_8001C648
    if (ctx->r21 == ctx->r25) {
        // 0x8001C640: nop
    
            goto L_8001C648;
    }
    // 0x8001C640: nop

    // 0x8001C644: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001C648:
    // 0x8001C648: beq         $a0, $zero, L_8001C698
    if (ctx->r4 == 0) {
        // 0x8001C64C: nop
    
            goto L_8001C698;
    }
    // 0x8001C64C: nop

    // 0x8001C650: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001C654: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C658: sub.s       $f0, $f4, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x8001C65C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C660: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001C664: sub.s       $f2, $f6, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x8001C668: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001C66C: sub.s       $f14, $f8, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x8001C670: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001C674: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8001C678: jal         0x800CA030
    // 0x8001C67C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001C67C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_1:
    // 0x8001C680: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8001C684: nop

    // 0x8001C688: bc1f        L_8001C698
    if (!c1cs) {
        // 0x8001C68C: nop
    
            goto L_8001C698;
    }
    // 0x8001C68C: nop

    // 0x8001C690: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8001C694: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
L_8001C698:
    // 0x8001C698: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001C69C: bne         $s0, $s6, L_8001C5F0
    if (ctx->r16 != ctx->r22) {
        // 0x8001C6A0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8001C5F0;
    }
    // 0x8001C6A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8001C6A4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8001C6A8: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x8001C6AC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8001C6B0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8001C6B4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001C6B8: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8001C6BC: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001C6C0: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8001C6C4: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001C6C8: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8001C6CC: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001C6D0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8001C6D4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8001C6D8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8001C6DC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8001C6E0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8001C6E4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8001C6E8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8001C6EC: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8001C6F0: jr          $ra
    // 0x8001C6F4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8001C6F4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8001C6C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C6F8: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8001C6FC: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8001C700: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8001C704: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8001C708: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8001C70C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8001C710: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x8001C714: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8001C718: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8001C71C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8001C720: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8001C724: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8001C728: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x8001C72C: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8001C730: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x8001C734: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8001C738: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x8001C73C: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8001C740: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x8001C744: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8001C748: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8001C74C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001C750: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8001C754: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x8001C758: sw          $a2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r6;
    // 0x8001C75C: bne         $t6, $zero, L_8001C784
    if (ctx->r14 != 0) {
        // 0x8001C760: sw          $a3, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = ctx->r7;
            goto L_8001C784;
    }
    // 0x8001C760: sw          $a3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r7;
    // 0x8001C764: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C768: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001C76C: lwc1        $f9, 0x5BD8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5BD8);
    // 0x8001C770: lwc1        $f8, 0x5BDC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5BDC);
    // 0x8001C774: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001C778: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8001C77C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8001C780: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
L_8001C784:
    // 0x8001C784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001C788: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001C78C: addiu       $s5, $sp, 0xAC
    ctx->r21 = ADD32(ctx->r29, 0XAC);
    // 0x8001C790: addiu       $s4, $sp, 0xC0
    ctx->r20 = ADD32(ctx->r29, 0XC0);
    // 0x8001C794: addiu       $s3, $sp, 0xD4
    ctx->r19 = ADD32(ctx->r29, 0XD4);
    // 0x8001C798: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x8001C79C: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
L_8001C7A0:
    // 0x8001C7A0: lbu         $a0, 0xC($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XC);
    // 0x8001C7A4: nop

    // 0x8001C7A8: bne         $s0, $a0, L_8001C7BC
    if (ctx->r16 != ctx->r4) {
        // 0x8001C7AC: nop
    
            goto L_8001C7BC;
    }
    // 0x8001C7AC: nop

    // 0x8001C7B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001C7B4: b           L_8001CC2C
    // 0x8001C7B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8001CC2C;
    // 0x8001C7B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8001C7BC:
    // 0x8001C7BC: sw          $a1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r5;
    // 0x8001C7C0: jal         0x8001D248
    // 0x8001C7C4: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    ainode_get(rdram, ctx);
        goto after_0;
    // 0x8001C7C4: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001C7C8: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x8001C7CC: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8001C7D0: bne         $v0, $zero, L_8001C7E4
    if (ctx->r2 != 0) {
        // 0x8001C7D4: sll         $v1, $a1, 2
        ctx->r3 = S32(ctx->r5 << 2);
            goto L_8001C7E4;
    }
    // 0x8001C7D4: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8001C7D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001C7DC: b           L_8001CC2C
    // 0x8001C7E0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8001CC2C;
    // 0x8001C7E0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8001C7E4:
    // 0x8001C7E4: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001C7E8: addu        $t7, $s3, $v1
    ctx->r15 = ADD32(ctx->r19, ctx->r3);
    // 0x8001C7EC: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x8001C7F0: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C7F4: addu        $t8, $s4, $v1
    ctx->r24 = ADD32(ctx->r20, ctx->r3);
    // 0x8001C7F8: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x8001C7FC: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C800: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001C804: addu        $t9, $s5, $v1
    ctx->r25 = ADD32(ctx->r21, ctx->r3);
    // 0x8001C808: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001C80C: bne         $a1, $s1, L_8001C7A0
    if (ctx->r5 != ctx->r17) {
        // 0x8001C810: swc1        $f6, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
            goto L_8001C7A0;
    }
    // 0x8001C810: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x8001C814: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x8001C818: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001C81C: jal         0x80022574
    // 0x8001C820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_1;
    // 0x8001C820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8001C824: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x8001C828: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x8001C82C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001C830: jal         0x80022574
    // 0x8001C834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_2;
    // 0x8001C834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8001C838: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x8001C83C: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x8001C840: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001C844: jal         0x80022574
    // 0x8001C848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_3;
    // 0x8001C848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8001C84C: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x8001C850: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8001C854: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001C858: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x8001C85C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8001C860: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C864: bc1f        L_8001C878
    if (!c1cs) {
        // 0x8001C868: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8001C878;
    }
    // 0x8001C868: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C86C: lwc1        $f16, 0x5BE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5BE0);
    // 0x8001C870: nop

    // 0x8001C874: swc1        $f16, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f16.u32l;
L_8001C878:
    // 0x8001C878: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001C87C: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x8001C880: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001C884:
    // 0x8001C884: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8001C888: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001C88C: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8001C890: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8001C894: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001C898: add.s       $f20, $f8, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001C89C: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x8001C8A0: c.le.d      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.d <= ctx->f0.d;
    // 0x8001C8A4: nop

    // 0x8001C8A8: bc1f        L_8001C8BC
    if (!c1cs) {
        // 0x8001C8AC: nop
    
            goto L_8001C8BC;
    }
    // 0x8001C8AC: nop

    // 0x8001C8B0: sub.d       $f10, $f0, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f28.d); 
    ctx->f10.d = ctx->f0.d - ctx->f28.d;
    // 0x8001C8B4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8001C8B8: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
L_8001C8BC:
    // 0x8001C8BC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001C8C0: jal         0x80022574
    // 0x8001C8C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_4;
    // 0x8001C8C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8001C8C8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001C8CC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8001C8D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001C8D4: jal         0x80022574
    // 0x8001C8D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_5;
    // 0x8001C8D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x8001C8DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001C8E0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8001C8E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001C8E8: jal         0x80022574
    // 0x8001C8EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_6;
    // 0x8001C8EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8001C8F0: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001C8F4: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001C8F8: sub.s       $f24, $f24, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f30.fl;
    // 0x8001C8FC: sub.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f16.fl;
    // 0x8001C900: bne         $s0, $zero, L_8001C95C
    if (ctx->r16 != 0) {
        // 0x8001C904: sub.s       $f26, $f0, $f18
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f0.fl - ctx->f18.fl;
            goto L_8001C95C;
    }
    // 0x8001C904: sub.s       $f26, $f0, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8001C908: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001C90C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C910: mul.s       $f8, $f24, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8001C914: nop

    // 0x8001C918: mul.s       $f10, $f26, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8001C91C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001C920: jal         0x800CA030
    // 0x8001C924: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8001C924: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_7:
    // 0x8001C928: lwc1        $f16, 0xF0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001C92C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001C930: div.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8001C934: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8001C938: c.eq.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl == ctx->f2.fl;
    // 0x8001C93C: nop

    // 0x8001C940: bc1t        L_8001C95C
    if (c1cs) {
        // 0x8001C944: nop
    
            goto L_8001C95C;
    }
    // 0x8001C944: nop

    // 0x8001C948: div.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001C94C: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8001C950: nop

    // 0x8001C954: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001C958: swc1        $f10, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f10.u32l;
L_8001C95C:
    // 0x8001C95C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001C960: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001C964: bne         $s0, $at, L_8001C884
    if (ctx->r16 != ctx->r1) {
        // 0x8001C968: nop
    
            goto L_8001C884;
    }
    // 0x8001C968: nop

    // 0x8001C96C: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
    // 0x8001C970: swc1        $f20, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f20.u32l;
    // 0x8001C974: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001C978: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001C97C: add.s       $f18, $f22, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x8001C980: add.s       $f30, $f24, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f30.fl = ctx->f24.fl + ctx->f30.fl;
    // 0x8001C984: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x8001C988: add.s       $f4, $f26, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f26.fl + ctx->f8.fl;
    // 0x8001C98C: swc1        $f30, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f30.u32l;
    // 0x8001C990: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x8001C994: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001C998: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001C99C: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C9A0: sub.s       $f22, $f6, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8001C9A4: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001C9A8: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001C9AC: sub.s       $f24, $f30, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x8001C9B0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C9B4: swc1        $f22, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f22.u32l;
    // 0x8001C9B8: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8001C9BC: sub.s       $f26, $f18, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8001C9C0: swc1        $f26, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f26.u32l;
    // 0x8001C9C4: mul.s       $f16, $f26, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8001C9C8: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001C9CC: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
    // 0x8001C9D0: jal         0x800CA030
    // 0x8001C9D4: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8001C9D4: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_8:
    // 0x8001C9D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001C9DC: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001C9E0: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x8001C9E4: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8001C9E8: bc1t        L_8001CA20
    if (c1cs) {
        // 0x8001C9EC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8001CA20;
    }
    // 0x8001C9EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C9F0: lwc1        $f9, 0x5BE8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5BE8);
    // 0x8001C9F4: lwc1        $f8, 0x5BEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5BEC);
    // 0x8001C9F8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8001C9FC: nop

    // 0x8001CA00: div.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x8001CA04: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8001CA08: mul.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8001CA0C: nop

    // 0x8001CA10: mul.s       $f24, $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8001CA14: nop

    // 0x8001CA18: mul.s       $f26, $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x8001CA1C: nop

L_8001CA20:
    // 0x8001CA20: mul.s       $f18, $f30, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x8001CA24: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001CA28: nop

    // 0x8001CA2C: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8001CA30: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001CA34: jal         0x800CA030
    // 0x8001CA38: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x8001CA38: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_9:
    // 0x8001CA3C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8001CA40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001CA44: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8001CA48: div.s       $f20, $f0, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8001CA4C: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8001CA50: nop

    // 0x8001CA54: bc1f        L_8001CA60
    if (!c1cs) {
        // 0x8001CA58: nop
    
            goto L_8001CA60;
    }
    // 0x8001CA58: nop

    // 0x8001CA5C: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
L_8001CA60:
    // 0x8001CA60: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8001CA64: c.le.d      $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f28.d <= ctx->f18.d;
    // 0x8001CA68: nop

    // 0x8001CA6C: bc1f        L_8001CB60
    if (!c1cs) {
        // 0x8001CA70: lw          $t3, 0xEC($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XEC);
            goto L_8001CB60;
    }
    // 0x8001CA70: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CA74: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8001CA78: jal         0x80070990
    // 0x8001CA7C: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    arctan2_f(rdram, ctx);
        goto after_10;
    // 0x8001CA7C: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_10:
    // 0x8001CA80: lw          $t0, 0xEC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CA84: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8001CA88: lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X0);
    // 0x8001CA8C: ori         $s4, $zero, 0x8001
    ctx->r20 = 0 | 0X8001;
    // 0x8001CA90: andi        $t1, $v1, 0xFFFF
    ctx->r9 = ctx->r3 & 0XFFFF;
    // 0x8001CA94: subu        $s0, $v0, $t1
    ctx->r16 = SUB32(ctx->r2, ctx->r9);
    // 0x8001CA98: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x8001CA9C: slt         $at, $s0, $s4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8001CAA0: bne         $at, $zero, L_8001CAB0
    if (ctx->r1 != 0) {
        // 0x8001CAA4: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8001CAB0;
    }
    // 0x8001CAA4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8001CAA8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8001CAAC: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
L_8001CAB0:
    // 0x8001CAB0: slti        $at, $s0, -0x8000
    ctx->r1 = SIGNED(ctx->r16) < -0X8000 ? 1 : 0;
    // 0x8001CAB4: beq         $at, $zero, L_8001CAC0
    if (ctx->r1 == 0) {
        // 0x8001CAB8: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8001CAC0;
    }
    // 0x8001CAB8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001CABC: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
L_8001CAC0:
    // 0x8001CAC0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8001CAC4: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001CAC8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8001CACC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001CAD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001CAD4: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CAD8: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001CADC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001CAE0: mfc1        $s3, $f8
    ctx->r19 = (int32_t)ctx->f8.u32l;
    // 0x8001CAE4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8001CAE8: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001CAEC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8001CAF0: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x8001CAF4: mflo        $t3
    ctx->r11 = lo;
    // 0x8001CAF8: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8001CAFC: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8001CB00: jal         0x80070990
    // 0x8001CB04: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    arctan2_f(rdram, ctx);
        goto after_11;
    // 0x8001CB04: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    after_11:
    // 0x8001CB08: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CB0C: nop

    // 0x8001CB10: lh          $v1, 0x2($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X2);
    // 0x8001CB14: nop

    // 0x8001CB18: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x8001CB1C: subu        $s0, $v0, $t8
    ctx->r16 = SUB32(ctx->r2, ctx->r24);
    // 0x8001CB20: slt         $at, $s0, $s4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8001CB24: bne         $at, $zero, L_8001CB34
    if (ctx->r1 != 0) {
        // 0x8001CB28: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8001CB34;
    }
    // 0x8001CB28: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8001CB2C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8001CB30: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
L_8001CB34:
    // 0x8001CB34: slti        $at, $s0, -0x8000
    ctx->r1 = SIGNED(ctx->r16) < -0X8000 ? 1 : 0;
    // 0x8001CB38: beq         $at, $zero, L_8001CB44
    if (ctx->r1 == 0) {
        // 0x8001CB3C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8001CB44;
    }
    // 0x8001CB3C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001CB40: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
L_8001CB44:
    // 0x8001CB44: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001CB48: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CB4C: mflo        $t9
    ctx->r25 = lo;
    // 0x8001CB50: sra         $t0, $t9, 4
    ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8001CB54: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8001CB58: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x8001CB5C: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
L_8001CB60:
    // 0x8001CB60: ori         $s0, $zero, 0x8000
    ctx->r16 = 0 | 0X8000;
    // 0x8001CB64: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8001CB68: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x8001CB6C: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    // 0x8001CB70: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8001CB74: jal         0x80070A04
    // 0x8001CB78: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_12;
    // 0x8001CB78: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_12:
    // 0x8001CB7C: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CB80: mul.s       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001CB84: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8001CB88: nop

    // 0x8001CB8C: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    // 0x8001CB90: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8001CB94: jal         0x80070A38
    // 0x8001CB98: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    coss_f(rdram, ctx);
        goto after_13;
    // 0x8001CB98: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_13:
    // 0x8001CB9C: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001CBA0: lw          $a0, 0xEC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CBA4: mul.s       $f10, $f22, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x8001CBA8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8001CBAC: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001CBB0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8001CBB4: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8001CBB8: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8001CBBC: jal         0x80011570
    // 0x8001CBC0: nop

    move_object(rdram, ctx);
        goto after_14;
    // 0x8001CBC0: nop

    after_14:
    // 0x8001CBC4: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001CBC8: lw          $t1, 0xEC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CBCC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001CBD0: swc1        $f4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f4.u32l;
    // 0x8001CBD4: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001CBD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001CBDC: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x8001CBE0: nop

    // 0x8001CBE4: mul.s       $f20, $f10, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001CBE8: beq         $s1, $zero, L_8001CC24
    if (ctx->r17 == 0) {
        // 0x8001CBEC: nop
    
            goto L_8001CC24;
    }
    // 0x8001CBEC: nop

    // 0x8001CBF0: lbu         $t2, 0xD($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0XD);
    // 0x8001CBF4: lbu         $t3, 0xE($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0XE);
    // 0x8001CBF8: lbu         $t4, 0xF($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XF);
    // 0x8001CBFC: lbu         $t5, 0x10($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X10);
    // 0x8001CC00: sb          $t2, 0xC($s2)
    MEM_B(0XC, ctx->r18) = ctx->r10;
    // 0x8001CC04: sb          $t3, 0xD($s2)
    MEM_B(0XD, ctx->r18) = ctx->r11;
    // 0x8001CC08: sb          $t4, 0xE($s2)
    MEM_B(0XE, ctx->r18) = ctx->r12;
    // 0x8001CC0C: sb          $t5, 0xF($s2)
    MEM_B(0XF, ctx->r18) = ctx->r13;
    // 0x8001CC10: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x8001CC14: andi        $a1, $t4, 0xFF
    ctx->r5 = ctx->r12 & 0XFF;
    // 0x8001CC18: jal         0x8001CC7C
    // 0x8001CC1C: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    ainode_find_next(rdram, ctx);
        goto after_15;
    // 0x8001CC1C: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    after_15:
    // 0x8001CC20: sb          $v0, 0x10($s2)
    MEM_B(0X10, ctx->r18) = ctx->r2;
L_8001CC24:
    // 0x8001CC24: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x8001CC28: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8001CC2C:
    // 0x8001CC2C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001CC30: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001CC34: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8001CC38: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001CC3C: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8001CC40: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001CC44: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8001CC48: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001CC4C: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8001CC50: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001CC54: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8001CC58: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001CC5C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8001CC60: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8001CC64: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8001CC68: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8001CC6C: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8001CC70: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x8001CC74: jr          $ra
    // 0x8001CC78: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8001CC78: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void ainode_find_next(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CC7C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8001CC80: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8001CC84: slti        $at, $a0, -0x1
    ctx->r1 = SIGNED(ctx->r4) < -0X1 ? 1 : 0;
    // 0x8001CC88: bne         $at, $zero, L_8001CC9C
    if (ctx->r1 != 0) {
        // 0x8001CC8C: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_8001CC9C;
    }
    // 0x8001CC8C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001CC90: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x8001CC94: bne         $at, $zero, L_8001CCA4
    if (ctx->r1 != 0) {
        // 0x8001CC98: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001CCA4;
    }
    // 0x8001CC98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
L_8001CC9C:
    // 0x8001CC9C: b           L_8001CD50
    // 0x8001CCA0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8001CD50;
    // 0x8001CCA0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8001CCA4:
    // 0x8001CCA4: lw          $t6, -0x4B7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B7C);
    // 0x8001CCA8: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001CCAC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001CCB0: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001CCB4: andi        $t9, $a2, 0x3
    ctx->r25 = ctx->r6 & 0X3;
    // 0x8001CCB8: bne         $v0, $zero, L_8001CCC8
    if (ctx->r2 != 0) {
        // 0x8001CCBC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001CCC8;
    }
    // 0x8001CCBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001CCC0: b           L_8001CD50
    // 0x8001CCC4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8001CD50;
    // 0x8001CCC4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8001CCC8:
    // 0x8001CCC8: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x8001CCCC: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x8001CCD0: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8001CCD4: lb          $a3, 0x18($t0)
    ctx->r7 = MEM_B(ctx->r8, 0X18);
    // 0x8001CCD8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8001CCDC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001CCE0: andi        $t2, $a3, 0x3
    ctx->r10 = ctx->r7 & 0X3;
    // 0x8001CCE4: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8001CCE8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8001CCEC:
    // 0x8001CCEC: addu        $t3, $v1, $a3
    ctx->r11 = ADD32(ctx->r3, ctx->r7);
    // 0x8001CCF0: lbu         $v0, 0xA($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0XA);
    // 0x8001CCF4: nop

    // 0x8001CCF8: beq         $a0, $v0, L_8001CD14
    if (ctx->r4 == ctx->r2) {
        // 0x8001CCFC: nop
    
            goto L_8001CD14;
    }
    // 0x8001CCFC: nop

    // 0x8001CD00: beq         $s0, $v0, L_8001CD18
    if (ctx->r16 == ctx->r2) {
        // 0x8001CD04: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001CD18;
    }
    // 0x8001CD04: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001CD08: sb          $a3, 0x18($t0)
    MEM_B(0X18, ctx->r8) = ctx->r7;
    // 0x8001CD0C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8001CD10: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8001CD14:
    // 0x8001CD14: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001CD18:
    // 0x8001CD18: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001CD1C: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8001CD20: andi        $t4, $a3, 0x3
    ctx->r12 = ctx->r7 & 0X3;
    // 0x8001CD24: bne         $at, $zero, L_8001CCEC
    if (ctx->r1 != 0) {
        // 0x8001CD28: or          $a3, $t4, $zero
        ctx->r7 = ctx->r12 | 0;
            goto L_8001CCEC;
    }
    // 0x8001CD28: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x8001CD2C: bne         $a1, $zero, L_8001CD3C
    if (ctx->r5 != 0) {
        // 0x8001CD30: nop
    
            goto L_8001CD3C;
    }
    // 0x8001CD30: nop

    // 0x8001CD34: b           L_8001CD50
    // 0x8001CD38: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8001CD50;
    // 0x8001CD38: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8001CD3C:
    // 0x8001CD3C: lb          $t5, 0x18($t0)
    ctx->r13 = MEM_B(ctx->r8, 0X18);
    // 0x8001CD40: nop

    // 0x8001CD44: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8001CD48: lbu         $v0, 0xA($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA);
    // 0x8001CD4C: nop

L_8001CD50:
    // 0x8001CD50: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8001CD54: jr          $ra
    // 0x8001CD58: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8001CD58: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8001CD28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD5C: addiu       $sp, $sp, -0x378
    ctx->r29 = ADD32(ctx->r29, -0X378);
    // 0x8001CD60: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8001CD64: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8001CD68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001CD6C: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8001CD70: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8001CD74: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8001CD78: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8001CD7C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8001CD80: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8001CD84: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8001CD88: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8001CD8C: sw          $a0, 0x378($sp)
    MEM_W(0X378, ctx->r29) = ctx->r4;
    // 0x8001CD90: sw          $a2, 0x380($sp)
    MEM_W(0X380, ctx->r29) = ctx->r6;
    // 0x8001CD94: sw          $a3, 0x384($sp)
    MEM_W(0X384, ctx->r29) = ctx->r7;
    // 0x8001CD98: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001CD9C: addiu       $t2, $sp, 0x154
    ctx->r10 = ADD32(ctx->r29, 0X154);
L_8001CDA0:
    // 0x8001CDA0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8001CDA4: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001CDA8: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x8001CDAC: sra         $t5, $t8, 16
    ctx->r13 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001CDB0: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001CDB4: slti        $at, $t5, 0x80
    ctx->r1 = SIGNED(ctx->r13) < 0X80 ? 1 : 0;
    // 0x8001CDB8: bne         $at, $zero, L_8001CDA0
    if (ctx->r1 != 0) {
        // 0x8001CDBC: sw          $zero, 0x0($t7)
        MEM_W(0X0, ctx->r15) = 0;
            goto L_8001CDA0;
    }
    // 0x8001CDBC: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8001CDC0: lw          $t6, 0x378($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X378);
    // 0x8001CDC4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001CDC8: lw          $v1, -0x4B7C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B7C);
    // 0x8001CDCC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001CDD0: addu        $a0, $v1, $t7
    ctx->r4 = ADD32(ctx->r3, ctx->r15);
    // 0x8001CDD4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001CDD8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001CDDC: lw          $s4, 0x64($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X64);
    // 0x8001CDE0: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x8001CDE4: lw          $fp, 0x370($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X370);
    // 0x8001CDE8: lh          $a2, 0x36C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X36C);
    // 0x8001CDEC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8001CDF0: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x8001CDF4: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8001CDF8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001CDFC: sb          $t8, 0x363($sp)
    MEM_B(0X363, ctx->r29) = ctx->r24;
    // 0x8001CE00: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8001CE04: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x8001CE08: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8001CE0C: addiu       $t3, $sp, 0x54
    ctx->r11 = ADD32(ctx->r29, 0X54);
    // 0x8001CE10: addiu       $t0, $sp, 0xD4
    ctx->r8 = ADD32(ctx->r29, 0XD4);
    // 0x8001CE14: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x8001CE18: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
L_8001CE1C:
    // 0x8001CE1C: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
L_8001CE20:
    // 0x8001CE20: addu        $t6, $s4, $t9
    ctx->r14 = ADD32(ctx->r20, ctx->r25);
    // 0x8001CE24: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001CE28: lw          $t8, 0x378($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X378);
    // 0x8001CE2C: beq         $t7, $zero, L_8001D058
    if (ctx->r15 == 0) {
        // 0x8001CE30: addu        $s0, $s1, $t5
        ctx->r16 = ADD32(ctx->r17, ctx->r13);
            goto L_8001D058;
    }
    // 0x8001CE30: addu        $s0, $s1, $t5
    ctx->r16 = ADD32(ctx->r17, ctx->r13);
    // 0x8001CE34: lbu         $v1, 0x9($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X9);
    // 0x8001CE38: lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA);
    // 0x8001CE3C: bne         $t8, $v1, L_8001CE54
    if (ctx->r24 != ctx->r3) {
        // 0x8001CE40: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8001CE54;
    }
    // 0x8001CE40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001CE44: lw          $t9, 0x380($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X380);
    // 0x8001CE48: nop

    // 0x8001CE4C: beq         $v0, $t9, L_8001CE6C
    if (ctx->r2 == ctx->r25) {
        // 0x8001CE50: nop
    
            goto L_8001CE6C;
    }
    // 0x8001CE50: nop

L_8001CE54:
    // 0x8001CE54: lw          $t6, 0x380($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X380);
    // 0x8001CE58: lw          $t7, 0x378($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X378);
    // 0x8001CE5C: bne         $t6, $v1, L_8001CE84
    if (ctx->r14 != ctx->r3) {
        // 0x8001CE60: nop
    
            goto L_8001CE84;
    }
    // 0x8001CE60: nop

    // 0x8001CE64: bne         $v0, $t7, L_8001CE84
    if (ctx->r2 != ctx->r15) {
        // 0x8001CE68: nop
    
            goto L_8001CE84;
    }
    // 0x8001CE68: nop

L_8001CE6C:
    // 0x8001CE6C: beq         $s5, $zero, L_8001CE78
    if (ctx->r21 == 0) {
        // 0x8001CE70: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001CE78;
    }
    // 0x8001CE70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001CE74: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8001CE78:
    // 0x8001CE78: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001CE7C: sll         $t8, $s5, 24
    ctx->r24 = S32(ctx->r21 << 24);
    // 0x8001CE80: sra         $s5, $t8, 24
    ctx->r21 = S32(SIGNED(ctx->r24) >> 24);
L_8001CE84:
    // 0x8001CE84: beq         $a3, $zero, L_8001CF10
    if (ctx->r7 == 0) {
        // 0x8001CE88: addiu       $a0, $t1, -0x1
        ctx->r4 = ADD32(ctx->r9, -0X1);
            goto L_8001CF10;
    }
    // 0x8001CE88: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
    // 0x8001CE8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001CE90: blez        $t1, L_8001CED4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001CE94: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001CED4;
    }
    // 0x8001CE94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001CE98: lb          $t6, 0xD4($sp)
    ctx->r14 = MEM_B(ctx->r29, 0XD4);
    // 0x8001CE9C: nop

    // 0x8001CEA0: beq         $v0, $t6, L_8001CED8
    if (ctx->r2 == ctx->r14) {
        // 0x8001CEA4: sll         $t7, $t5, 1
        ctx->r15 = S32(ctx->r13 << 1);
            goto L_8001CED8;
    }
    // 0x8001CEA4: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
L_8001CEA8:
    // 0x8001CEA8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001CEAC: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8001CEB0: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001CEB4: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001CEB8: beq         $at, $zero, L_8001CED4
    if (ctx->r1 == 0) {
        // 0x8001CEBC: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8001CED4;
    }
    // 0x8001CEBC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8001CEC0: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8001CEC4: lb          $t6, 0x0($t9)
    ctx->r14 = MEM_B(ctx->r25, 0X0);
    // 0x8001CEC8: nop

    // 0x8001CECC: bne         $v0, $t6, L_8001CEA8
    if (ctx->r2 != ctx->r14) {
        // 0x8001CED0: nop
    
            goto L_8001CEA8;
    }
    // 0x8001CED0: nop

L_8001CED4:
    // 0x8001CED4: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
L_8001CED8:
    // 0x8001CED8: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x8001CEDC: lh          $t9, 0x10($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X10);
    // 0x8001CEE0: bne         $a2, $t1, L_8001CEF0
    if (ctx->r6 != ctx->r9) {
        // 0x8001CEE4: addu        $fp, $t9, $ra
        ctx->r30 = ADD32(ctx->r25, ctx->r31);
            goto L_8001CEF0;
    }
    // 0x8001CEE4: addu        $fp, $t9, $ra
    ctx->r30 = ADD32(ctx->r25, ctx->r31);
    // 0x8001CEE8: b           L_8001CF10
    // 0x8001CEEC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_8001CF10;
    // 0x8001CEEC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8001CEF0:
    // 0x8001CEF0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001CEF4: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001CEF8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001CEFC: nop

    // 0x8001CF00: slt         $at, $fp, $t8
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001CF04: beq         $at, $zero, L_8001CF10
    if (ctx->r1 == 0) {
        // 0x8001CF08: nop
    
            goto L_8001CF10;
    }
    // 0x8001CF08: nop

    // 0x8001CF0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8001CF10:
    // 0x8001CF10: beq         $a3, $zero, L_8001D058
    if (ctx->r7 == 0) {
        // 0x8001CF14: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_8001D058;
    }
    // 0x8001CF14: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8001CF18: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001CF1C: beq         $at, $zero, L_8001CF50
    if (ctx->r1 == 0) {
        // 0x8001CF20: addu        $t4, $t2, $t9
        ctx->r12 = ADD32(ctx->r10, ctx->r25);
            goto L_8001CF50;
    }
    // 0x8001CF20: addu        $t4, $t2, $t9
    ctx->r12 = ADD32(ctx->r10, ctx->r25);
L_8001CF24:
    // 0x8001CF24: addu        $v0, $t0, $a2
    ctx->r2 = ADD32(ctx->r8, ctx->r6);
    // 0x8001CF28: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
    // 0x8001CF2C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001CF30: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8001CF34: lb          $t6, 0x1($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1);
    // 0x8001CF38: lb          $t7, 0x1($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1);
    // 0x8001CF3C: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001CF40: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001CF44: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8001CF48: bne         $at, $zero, L_8001CF24
    if (ctx->r1 != 0) {
        // 0x8001CF4C: sb          $t7, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r15;
            goto L_8001CF24;
    }
    // 0x8001CF4C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_8001CF50:
    // 0x8001CF50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001CF54: bne         $a3, $at, L_8001CF6C
    if (ctx->r7 != ctx->r1) {
        // 0x8001CF58: nop
    
            goto L_8001CF6C;
    }
    // 0x8001CF58: nop

    // 0x8001CF5C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001CF60: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x8001CF64: sra         $t1, $t6, 16
    ctx->r9 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001CF68: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
L_8001CF6C:
    // 0x8001CF6C: sw          $fp, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r30;
    // 0x8001CF70: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8001CF74: lb          $t6, 0x363($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X363);
    // 0x8001CF78: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x8001CF7C: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001CF80: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001CF84: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8001CF88: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8001CF8C: addu        $a1, $t3, $t9
    ctx->r5 = ADD32(ctx->r11, ctx->r25);
    // 0x8001CF90: beq         $t6, $zero, L_8001CFA4
    if (ctx->r14 == 0) {
        // 0x8001CF94: addu        $v1, $t0, $t9
        ctx->r3 = ADD32(ctx->r8, ctx->r25);
            goto L_8001CFA4;
    }
    // 0x8001CF94: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x8001CF98: lbu         $t7, 0xA($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XA);
    // 0x8001CF9C: b           L_8001CFA8
    // 0x8001CFA0: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
        goto L_8001CFA8;
    // 0x8001CFA0: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
L_8001CFA4:
    // 0x8001CFA4: sb          $s3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r19;
L_8001CFA8:
    // 0x8001CFA8: lbu         $t8, 0xA($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XA);
    // 0x8001CFAC: blez        $v0, L_8001D058
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001CFB0: sb          $t8, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r24;
            goto L_8001D058;
    }
    // 0x8001CFB0: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x8001CFB4: lb          $t9, -0x1($v1)
    ctx->r25 = MEM_B(ctx->r3, -0X1);
    // 0x8001CFB8: addu        $v0, $t0, $a2
    ctx->r2 = ADD32(ctx->r8, ctx->r6);
    // 0x8001CFBC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001CFC0: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x8001CFC4: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001CFC8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001CFCC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001CFD0: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001CFD4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001CFD8: nop

    // 0x8001CFDC: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001CFE0: beq         $at, $zero, L_8001D058
    if (ctx->r1 == 0) {
        // 0x8001CFE4: nop
    
            goto L_8001D058;
    }
    // 0x8001CFE4: nop

    // 0x8001CFE8: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8001CFEC: lb          $a1, -0x1($v0)
    ctx->r5 = MEM_B(ctx->r2, -0X1);
    // 0x8001CFF0: nop

    // 0x8001CFF4: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
L_8001CFF8:
    // 0x8001CFF8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001CFFC: lb          $a3, 0x0($v1)
    ctx->r7 = MEM_B(ctx->r3, 0X0);
    // 0x8001D000: lb          $t6, -0x1($v1)
    ctx->r14 = MEM_B(ctx->r3, -0X1);
    // 0x8001D004: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8001D008: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001D00C: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x8001D010: sb          $a0, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r4;
    // 0x8001D014: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8001D018: sb          $a3, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r7;
    // 0x8001D01C: blez        $t9, L_8001D058
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001D020: sb          $t6, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r14;
            goto L_8001D058;
    }
    // 0x8001D020: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8001D024: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x8001D028: lb          $a1, -0x1($v0)
    ctx->r5 = MEM_B(ctx->r2, -0X1);
    // 0x8001D02C: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8001D030: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8001D034: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001D038: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8001D03C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001D040: addu        $t6, $t2, $t9
    ctx->r14 = ADD32(ctx->r10, ctx->r25);
    // 0x8001D044: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001D048: nop

    // 0x8001D04C: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001D050: bne         $at, $zero, L_8001CFF8
    if (ctx->r1 != 0) {
        // 0x8001D054: addu        $v1, $t3, $a2
        ctx->r3 = ADD32(ctx->r11, ctx->r6);
            goto L_8001CFF8;
    }
    // 0x8001D054: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
L_8001D058:
    // 0x8001D058: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001D05C: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8001D060: sra         $t5, $t9, 16
    ctx->r13 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001D064: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8001D068: bne         $at, $zero, L_8001CE20
    if (ctx->r1 != 0) {
        // 0x8001D06C: sll         $t9, $t5, 2
        ctx->r25 = S32(ctx->r13 << 2);
            goto L_8001CE20;
    }
    // 0x8001D06C: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8001D070: blez        $t1, L_8001D11C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001D074: nop
    
            goto L_8001D11C;
    }
    // 0x8001D074: nop

    // 0x8001D078: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8001D07C: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x8001D080: sra         $t1, $t8, 16
    ctx->r9 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001D084: addu        $t9, $t0, $t1
    ctx->r25 = ADD32(ctx->r8, ctx->r9);
    // 0x8001D088: lb          $v1, 0x0($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X0);
    // 0x8001D08C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8001D090: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8001D094: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x8001D098: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8001D09C: addu        $t9, $t3, $t1
    ctx->r25 = ADD32(ctx->r11, ctx->r9);
    // 0x8001D0A0: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x8001D0A4: lb          $s3, 0x0($t9)
    ctx->r19 = MEM_B(ctx->r25, 0X0);
    // 0x8001D0A8: lbu         $t6, 0x9($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X9);
    // 0x8001D0AC: andi        $t9, $s6, 0x100
    ctx->r25 = ctx->r22 & 0X100;
    // 0x8001D0B0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8001D0B4: addu        $t7, $t2, $t8
    ctx->r15 = ADD32(ctx->r10, ctx->r24);
    // 0x8001D0B8: lw          $ra, 0x0($t7)
    ctx->r31 = MEM_W(ctx->r15, 0X0);
    // 0x8001D0BC: lw          $s4, 0x64($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X64);
    // 0x8001D0C0: beq         $t9, $zero, L_8001D0E4
    if (ctx->r25 == 0) {
        // 0x8001D0C4: sb          $zero, 0x363($sp)
        MEM_B(0X363, ctx->r29) = 0;
            goto L_8001D0E4;
    }
    // 0x8001D0C4: sb          $zero, 0x363($sp)
    MEM_B(0X363, ctx->r29) = 0;
    // 0x8001D0C8: andi        $t6, $s6, 0x7F
    ctx->r14 = ctx->r22 & 0X7F;
    // 0x8001D0CC: bne         $t6, $v1, L_8001D100
    if (ctx->r14 != ctx->r3) {
        // 0x8001D0D0: nop
    
            goto L_8001D100;
    }
    // 0x8001D0D0: nop

    // 0x8001D0D4: sll         $s2, $s3, 16
    ctx->r18 = S32(ctx->r19 << 16);
    // 0x8001D0D8: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001D0DC: b           L_8001D100
    // 0x8001D0E0: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
        goto L_8001D100;
    // 0x8001D0E0: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_8001D0E4:
    // 0x8001D0E4: lbu         $t7, 0x8($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X8);
    // 0x8001D0E8: nop

    // 0x8001D0EC: bne         $s6, $t7, L_8001D100
    if (ctx->r22 != ctx->r15) {
        // 0x8001D0F0: nop
    
            goto L_8001D100;
    }
    // 0x8001D0F0: nop

    // 0x8001D0F4: sll         $s2, $s3, 16
    ctx->r18 = S32(ctx->r19 << 16);
    // 0x8001D0F8: sra         $t9, $s2, 16
    ctx->r25 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001D0FC: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_8001D100:
    // 0x8001D100: bne         $t1, $zero, L_8001D11C
    if (ctx->r9 != 0) {
        // 0x8001D104: nop
    
            goto L_8001D11C;
    }
    // 0x8001D104: nop

    // 0x8001D108: bne         $s2, $s7, L_8001D11C
    if (ctx->r18 != ctx->r23) {
        // 0x8001D10C: nop
    
            goto L_8001D11C;
    }
    // 0x8001D10C: nop

    // 0x8001D110: sll         $s2, $s3, 16
    ctx->r18 = S32(ctx->r19 << 16);
    // 0x8001D114: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001D118: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
L_8001D11C:
    // 0x8001D11C: bne         $s2, $s7, L_8001D134
    if (ctx->r18 != ctx->r23) {
        // 0x8001D120: nop
    
            goto L_8001D134;
    }
    // 0x8001D120: nop

    // 0x8001D124: bgtz        $t1, L_8001CE1C
    if (SIGNED(ctx->r9) > 0) {
        // 0x8001D128: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_8001CE1C;
    }
    // 0x8001D128: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001D12C: sw          $fp, 0x370($sp)
    MEM_W(0X370, ctx->r29) = ctx->r30;
    // 0x8001D130: sh          $a2, 0x36C($sp)
    MEM_H(0X36C, ctx->r29) = ctx->r6;
L_8001D134:
    // 0x8001D134: beq         $s2, $s7, L_8001D1B0
    if (ctx->r18 == ctx->r23) {
        // 0x8001D138: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001D1B0;
    }
    // 0x8001D138: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D13C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8001D140: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001D144: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001D148: nop

    // 0x8001D14C: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x8001D150: lw          $s4, 0x64($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X64);
    // 0x8001D154: lbu         $t7, 0xA($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XA);
    // 0x8001D158: nop

    // 0x8001D15C: beq         $s2, $t7, L_8001D194
    if (ctx->r18 == ctx->r15) {
        // 0x8001D160: slti        $at, $t5, 0x4
        ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
            goto L_8001D194;
    }
    // 0x8001D160: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
L_8001D164:
    // 0x8001D164: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001D168: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8001D16C: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001D170: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x8001D174: beq         $at, $zero, L_8001D190
    if (ctx->r1 == 0) {
        // 0x8001D178: or          $t5, $t6, $zero
        ctx->r13 = ctx->r14 | 0;
            goto L_8001D190;
    }
    // 0x8001D178: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x8001D17C: addu        $t8, $s1, $t6
    ctx->r24 = ADD32(ctx->r17, ctx->r14);
    // 0x8001D180: lbu         $t7, 0xA($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XA);
    // 0x8001D184: nop

    // 0x8001D188: bne         $s2, $t7, L_8001D164
    if (ctx->r18 != ctx->r15) {
        // 0x8001D18C: nop
    
            goto L_8001D164;
    }
    // 0x8001D18C: nop

L_8001D190:
    // 0x8001D190: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
L_8001D194:
    // 0x8001D194: beq         $at, $zero, L_8001D1B0
    if (ctx->r1 == 0) {
        // 0x8001D198: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001D1B0;
    }
    // 0x8001D198: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D19C: lw          $t9, 0x384($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X384);
    // 0x8001D1A0: nop

    // 0x8001D1A4: addu        $t6, $s4, $t9
    ctx->r14 = ADD32(ctx->r20, ctx->r25);
    // 0x8001D1A8: sb          $t5, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r13;
    // 0x8001D1AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8001D1B0:
    // 0x8001D1B0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8001D1B4: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8001D1B8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8001D1BC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8001D1C0: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8001D1C4: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8001D1C8: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D1CC: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8001D1D0: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8001D1D4: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8001D1D8: jr          $ra
    // 0x8001D1DC: addiu       $sp, $sp, 0x378
    ctx->r29 = ADD32(ctx->r29, 0X378);
    return;
    // 0x8001D1DC: addiu       $sp, $sp, 0x378
    ctx->r29 = ADD32(ctx->r29, 0X378);
;}
RECOMP_FUNC void ainode_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D1E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001D1E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001D1E8: jr          $ra
    // 0x8001D1EC: sw          $t6, -0x4B70($at)
    MEM_W(-0X4B70, ctx->r1) = ctx->r14;
    return;
    // 0x8001D1EC: sw          $t6, -0x4B70($at)
    MEM_W(-0X4B70, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void ainode_tail_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D1F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001D1F4: addiu       $v1, $v1, -0x4B78
    ctx->r3 = ADD32(ctx->r3, -0X4B78);
    // 0x8001D1F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001D1FC: nop

    // 0x8001D200: beq         $a0, $v0, L_8001D210
    if (ctx->r4 == ctx->r2) {
        // 0x8001D204: nop
    
            goto L_8001D210;
    }
    // 0x8001D204: nop

    // 0x8001D208: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8001D20C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8001D210:
    // 0x8001D210: jr          $ra
    // 0x8001D214: nop

    return;
    // 0x8001D214: nop

;}
RECOMP_FUNC void ainode_tail(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D218: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001D21C: addiu       $v1, $v1, -0x4B78
    ctx->r3 = ADD32(ctx->r3, -0X4B78);
    // 0x8001D220: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8001D224: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001D228: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001D22C: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x8001D230: lw          $t7, -0x4B7C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4B7C);
    // 0x8001D234: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001D238: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8001D23C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8001D240: jr          $ra
    // 0x8001D244: nop

    return;
    // 0x8001D244: nop

;}
RECOMP_FUNC void ainode_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D248: bltz        $a0, L_8001D270
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001D24C: slti        $at, $a0, 0x80
        ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
            goto L_8001D270;
    }
    // 0x8001D24C: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x8001D250: beq         $at, $zero, L_8001D270
    if (ctx->r1 == 0) {
        // 0x8001D254: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001D270;
    }
    // 0x8001D254: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001D258: lw          $t6, -0x4B7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B7C);
    // 0x8001D25C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001D260: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001D264: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001D268: jr          $ra
    // 0x8001D26C: nop

    return;
    // 0x8001D26C: nop

L_8001D270:
    // 0x8001D270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001D274: jr          $ra
    // 0x8001D278: nop

    return;
    // 0x8001D278: nop

;}
RECOMP_FUNC void func_8001D248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D27C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001D280: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001D284: jr          $ra
    // 0x8001D288: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x8001D288: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void set_world_shading(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D28C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D290: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001D294: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001D298: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x8001D29C: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x8001D2A0: lh          $a3, 0x2A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2A);
    // 0x8001D2A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D2A8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001D2AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001D2B0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001D2B4: addiu       $a0, $a0, -0x4B50
    ctx->r4 = ADD32(ctx->r4, -0X4B50);
    // 0x8001D2B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001D2BC: jal         0x8001D4E8
    // 0x8001D2C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    set_shading_properties(rdram, ctx);
        goto after_0;
    // 0x8001D2C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8001D2C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D2C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D2CC: jr          $ra
    // 0x8001D2D0: nop

    return;
    // 0x8001D2D0: nop

;}
RECOMP_FUNC void add_shading_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D2D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D2D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D2DC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001D2E0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001D2E4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001D2E8: lw          $s0, 0x54($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X54);
    // 0x8001D2EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D2F0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D2F4: beq         $s0, $zero, L_8001D4D4
    if (ctx->r16 == 0) {
        // 0x8001D2F8: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_8001D4D4;
    }
    // 0x8001D2F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001D2FC: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8001D300: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001D304: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8001D308: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D30C: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x8001D310: lw          $s0, 0x54($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X54);
    // 0x8001D314: nop

    // 0x8001D318: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8001D31C: nop

    // 0x8001D320: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001D324: nop

    // 0x8001D328: bc1f        L_8001D340
    if (!c1cs) {
        // 0x8001D32C: nop
    
            goto L_8001D340;
    }
    // 0x8001D32C: nop

    // 0x8001D330: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x8001D334: lw          $s0, 0x54($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X54);
    // 0x8001D338: b           L_8001D368
    // 0x8001D33C: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
        goto L_8001D368;
    // 0x8001D33C: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
L_8001D340:
    // 0x8001D340: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001D344: nop

    // 0x8001D348: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8001D34C: nop

    // 0x8001D350: bc1f        L_8001D364
    if (!c1cs) {
        // 0x8001D354: nop
    
            goto L_8001D364;
    }
    // 0x8001D354: nop

    // 0x8001D358: swc1        $f12, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f12.u32l;
    // 0x8001D35C: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D360: nop

L_8001D364:
    // 0x8001D364: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
L_8001D368:
    // 0x8001D368: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001D36C: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8001D370: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001D374: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x8001D378: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D37C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001D380: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8001D384: nop

    // 0x8001D388: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001D38C: nop

    // 0x8001D390: bc1f        L_8001D3AC
    if (!c1cs) {
        // 0x8001D394: nop
    
            goto L_8001D3AC;
    }
    // 0x8001D394: nop

    // 0x8001D398: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8001D39C: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D3A0: nop

    // 0x8001D3A4: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8001D3A8: nop

L_8001D3AC:
    // 0x8001D3AC: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x8001D3B0: nop

    // 0x8001D3B4: bc1f        L_8001D3D8
    if (!c1cs) {
        // 0x8001D3B8: nop
    
            goto L_8001D3D8;
    }
    // 0x8001D3B8: nop

    // 0x8001D3BC: lwc1        $f18, 0x5BF0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5BF0);
    // 0x8001D3C0: nop

    // 0x8001D3C4: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x8001D3C8: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D3CC: nop

    // 0x8001D3D0: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8001D3D4: nop

L_8001D3D8:
    // 0x8001D3D8: lh          $t0, 0x24($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X24);
    // 0x8001D3DC: lh          $t1, 0x3A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3A);
    // 0x8001D3E0: lh          $t6, 0x22($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X22);
    // 0x8001D3E4: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x8001D3E8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001D3EC: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x8001D3F0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8001D3F4: lh          $t3, 0x26($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X26);
    // 0x8001D3F8: lh          $t4, 0x3E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3E);
    // 0x8001D3FC: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x8001D400: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x8001D404: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001D408: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8001D40C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8001D410: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001D414: jal         0x8001D4E8
    // 0x8001D418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_shading_properties(rdram, ctx);
        goto after_0;
    // 0x8001D418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8001D41C: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x8001D420: nop

    // 0x8001D424: lbu         $t6, 0x3D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3D);
    // 0x8001D428: nop

    // 0x8001D42C: beq         $t6, $zero, L_8001D4D8
    if (ctx->r14 == 0) {
        // 0x8001D430: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001D4D8;
    }
    // 0x8001D430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D434: lbu         $t7, 0x3A($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3A);
    // 0x8001D438: lw          $t8, 0x54($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X54);
    // 0x8001D43C: nop

    // 0x8001D440: sb          $t7, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r15;
    // 0x8001D444: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x8001D448: lw          $t1, 0x54($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X54);
    // 0x8001D44C: lbu         $t0, 0x3B($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X3B);
    // 0x8001D450: nop

    // 0x8001D454: sb          $t0, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r8;
    // 0x8001D458: lw          $t2, 0x40($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X40);
    // 0x8001D45C: lw          $t4, 0x54($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X54);
    // 0x8001D460: lbu         $t3, 0x3C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3C);
    // 0x8001D464: nop

    // 0x8001D468: sb          $t3, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r11;
    // 0x8001D46C: lw          $t5, 0x40($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X40);
    // 0x8001D470: lw          $t7, 0x54($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X54);
    // 0x8001D474: lbu         $t6, 0x3D($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X3D);
    // 0x8001D478: nop

    // 0x8001D47C: sb          $t6, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r14;
    // 0x8001D480: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D484: nop

    // 0x8001D488: lh          $t8, 0x1C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1C);
    // 0x8001D48C: nop

    // 0x8001D490: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8001D494: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8001D498: sh          $t0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r8;
    // 0x8001D49C: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D4A0: nop

    // 0x8001D4A4: lh          $t1, 0x1E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1E);
    // 0x8001D4A8: nop

    // 0x8001D4AC: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8001D4B0: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8001D4B4: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    // 0x8001D4B8: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D4BC: nop

    // 0x8001D4C0: lh          $t4, 0x20($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X20);
    // 0x8001D4C4: nop

    // 0x8001D4C8: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8001D4CC: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x8001D4D0: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
L_8001D4D4:
    // 0x8001D4D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001D4D8:
    // 0x8001D4D8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D4DC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001D4E0: jr          $ra
    // 0x8001D4E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001D4E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void set_shading_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D4E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001D4EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D4F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001D4F4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8001D4F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D4FC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D500: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D504: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D508: sh          $a3, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r7;
    // 0x8001D50C: swc1        $f12, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f12.u32l;
    // 0x8001D510: swc1        $f14, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f14.u32l;
    // 0x8001D514: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8001D518: lh          $t8, 0x42($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X42);
    // 0x8001D51C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001D520: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x8001D524: lh          $t9, 0x46($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X46);
    // 0x8001D528: lui         $at, 0xC680
    ctx->r1 = S32(0XC680 << 16);
    // 0x8001D52C: sh          $t9, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r25;
    // 0x8001D530: lh          $t0, 0x46($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X46);
    // 0x8001D534: lh          $t1, 0x42($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X42);
    // 0x8001D538: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D53C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001D540: sh          $a3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r7;
    // 0x8001D544: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001D548: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001D54C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8001D550: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8001D554: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8001D558: sh          $t0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r8;
    // 0x8001D55C: sh          $t1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r9;
    // 0x8001D560: jal         0x80070560
    // 0x8001D564: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x8001D564: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8001D568: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001D56C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001D570: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001D574: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8001D578: nop

    // 0x8001D57C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8001D580: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D584: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D588: nop

    // 0x8001D58C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001D590: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8001D594: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8001D598: sh          $t3, 0x1C($a2)
    MEM_H(0X1C, ctx->r6) = ctx->r11;
    // 0x8001D59C: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001D5A0: nop

    // 0x8001D5A4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8001D5A8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8001D5AC: nop

    // 0x8001D5B0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8001D5B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D5B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D5BC: nop

    // 0x8001D5C0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001D5C4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8001D5C8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8001D5CC: sh          $t5, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r13;
    // 0x8001D5D0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001D5D4: sb          $zero, 0x18($a2)
    MEM_B(0X18, ctx->r6) = 0;
    // 0x8001D5D8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001D5DC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001D5E0: sb          $zero, 0x19($a2)
    MEM_B(0X19, ctx->r6) = 0;
    // 0x8001D5E4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001D5E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D5EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D5F0: sb          $zero, 0x1A($a2)
    MEM_B(0X1A, ctx->r6) = 0;
    // 0x8001D5F4: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001D5F8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8001D5FC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001D600: sh          $t7, 0x20($a2)
    MEM_H(0X20, ctx->r6) = ctx->r15;
    // 0x8001D604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D608: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001D60C: jr          $ra
    // 0x8001D610: nop

    return;
    // 0x8001D610: nop

;}
RECOMP_FUNC void update_envmap_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D614: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001D618: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D61C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8001D620: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8001D624: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001D628: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001D62C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8001D630: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D634: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001D638: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001D63C: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8001D640: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8001D644: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8001D648: jal         0x800CA030
    // 0x8001D64C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001D64C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8001D650: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001D654: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001D658: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x8001D65C: lui         $at, 0xC600
    ctx->r1 = S32(0XC600 << 16);
    // 0x8001D660: bc1t        L_8001D68C
    if (c1cs) {
        // 0x8001D664: nop
    
            goto L_8001D68C;
    }
    // 0x8001D664: nop

    // 0x8001D668: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001D66C: nop

    // 0x8001D670: div.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001D674: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8001D678: nop

    // 0x8001D67C: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8001D680: nop

    // 0x8001D684: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8001D688: nop

L_8001D68C:
    // 0x8001D68C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001D690: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001D694: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001D698: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D69C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D6A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D6A4: cvt.w.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = CVT_W_S(ctx->f20.fl);
    // 0x8001D6A8: addiu       $v0, $v0, -0x4A98
    ctx->r2 = ADD32(ctx->r2, -0X4A98);
    // 0x8001D6AC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001D6B0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8001D6B4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001D6B8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001D6BC: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001D6C0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001D6C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D6C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D6CC: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8001D6D0: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x8001D6D4: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8001D6D8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001D6DC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8001D6E0: nop

    // 0x8001D6E4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8001D6E8: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x8001D6EC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8001D6F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D6F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D6F8: nop

    // 0x8001D6FC: cvt.w.s     $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    ctx->f8.u32l = CVT_W_S(ctx->f22.fl);
    // 0x8001D700: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001D704: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8001D708: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8001D70C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D710: jr          $ra
    // 0x8001D714: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
    return;
    // 0x8001D714: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void obj_shade_fancy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D718: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001D71C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D720: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001D724: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001D728: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8001D72C: lh          $t0, 0x28($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X28);
    // 0x8001D730: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8001D734: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001D738: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001D73C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001D740: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8001D744: blez        $t0, L_8001D7A8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001D748: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001D7A8;
    }
    // 0x8001D748: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001D74C: lw          $a2, 0x38($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X38);
    // 0x8001D750: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8001D754: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_8001D758:
    // 0x8001D758: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001D75C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001D760: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x8001D764: sra         $v1, $t2, 16
    ctx->r3 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8001D768: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001D76C: mflo        $t6
    ctx->r14 = lo;
    // 0x8001D770: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x8001D774: lbu         $t7, 0x6($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X6);
    // 0x8001D778: nop

    // 0x8001D77C: beq         $a0, $t7, L_8001D788
    if (ctx->r4 == ctx->r15) {
        // 0x8001D780: nop
    
            goto L_8001D788;
    }
    // 0x8001D780: nop

    // 0x8001D784: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8001D788:
    // 0x8001D788: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8001D78C: nop

    // 0x8001D790: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8001D794: beq         $t9, $zero, L_8001D7A0
    if (ctx->r25 == 0) {
        // 0x8001D798: nop
    
            goto L_8001D7A0;
    }
    // 0x8001D798: nop

    // 0x8001D79C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_8001D7A0:
    // 0x8001D7A0: bne         $at, $zero, L_8001D758
    if (ctx->r1 != 0) {
        // 0x8001D7A4: nop
    
            goto L_8001D758;
    }
    // 0x8001D7A4: nop

L_8001D7A8:
    // 0x8001D7A8: beq         $a3, $zero, L_8001D810
    if (ctx->r7 == 0) {
        // 0x8001D7AC: nop
    
            goto L_8001D810;
    }
    // 0x8001D7AC: nop

    // 0x8001D7B0: lw          $t4, 0x40($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X40);
    // 0x8001D7B4: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    // 0x8001D7B8: lbu         $t5, 0x71($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X71);
    // 0x8001D7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D7C0: beq         $t5, $zero, L_8001D7FC
    if (ctx->r13 == 0) {
        // 0x8001D7C4: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8001D7FC;
    }
    // 0x8001D7C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001D7C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D7CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D7D0: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    // 0x8001D7D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D7D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001D7DC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001D7E0: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x8001D7E4: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    // 0x8001D7E8: jal         0x8001D840
    // 0x8001D7EC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    calc_dynamic_lighting_for_object_1(rdram, ctx);
        goto after_0;
    // 0x8001D7EC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001D7F0: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x8001D7F4: b           L_8001D810
    // 0x8001D7F8: nop

        goto L_8001D810;
    // 0x8001D7F8: nop

L_8001D7FC:
    // 0x8001D7FC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8001D800: jal         0x80024784
    // 0x8001D804: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    calc_dynamic_lighting_for_object_2(rdram, ctx);
        goto after_1;
    // 0x8001D804: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    after_1:
    // 0x8001D808: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x8001D80C: nop

L_8001D810:
    // 0x8001D810: beq         $t1, $zero, L_8001D830
    if (ctx->r9 == 0) {
        // 0x8001D814: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001D830;
    }
    // 0x8001D814: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D818: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x8001D81C: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x8001D820: lh          $a3, 0x0($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X0);
    // 0x8001D824: jal         0x8001DD88
    // 0x8001D828: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    calc_env_mapping_for_object(rdram, ctx);
        goto after_2;
    // 0x8001D828: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8001D82C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001D830:
    // 0x8001D830: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D834: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001D838: jr          $ra
    // 0x8001D83C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001D83C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void calc_dynamic_lighting_for_object_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D840: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8001D844: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001D848: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001D84C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001D850: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001D854: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001D858: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001D85C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001D860: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001D864: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001D868: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001D86C: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8001D870: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x8001D874: lw          $v0, 0x54($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X54);
    // 0x8001D878: sll         $s2, $a2, 16
    ctx->r18 = S32(ctx->r6 << 16);
    // 0x8001D87C: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001D880: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x8001D884: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001D888: beq         $v0, $zero, L_8001DD58
    if (ctx->r2 == 0) {
        // 0x8001D88C: or          $s7, $a1, $zero
        ctx->r23 = ctx->r5 | 0;
            goto L_8001DD58;
    }
    // 0x8001D88C: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8001D890: lw          $t7, 0x40($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X40);
    // 0x8001D894: lw          $fp, 0x44($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X44);
    // 0x8001D898: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x8001D89C: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x8001D8A0: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x8001D8A4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001D8A8: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8001D8AC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001D8B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001D8B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001D8B8: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8001D8BC: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x8001D8C0: nop

    // 0x8001D8C4: lh          $t8, 0xA($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XA);
    // 0x8001D8C8: nop

    // 0x8001D8CC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001D8D0: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8001D8D4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8001D8D8: nop

    // 0x8001D8DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001D8E0: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8001D8E4: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x8001D8E8: nop

    // 0x8001D8EC: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x8001D8F0: nop

    // 0x8001D8F4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001D8F8: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8001D8FC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8001D900: nop

    // 0x8001D904: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001D908: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x8001D90C: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x8001D910: nop

    // 0x8001D914: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8001D918: sh          $t8, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r24;
    // 0x8001D91C: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8001D920: nop

    // 0x8001D924: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8001D928: sh          $t6, 0x96($sp)
    MEM_H(0X96, ctx->r29) = ctx->r14;
    // 0x8001D92C: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x8001D930: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x8001D934: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8001D938: sh          $t8, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r24;
    // 0x8001D93C: jal         0x80070618
    // 0x8001D940: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    vec3f_rotate_ypr(rdram, ctx);
        goto after_0;
    // 0x8001D940: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    after_0:
    // 0x8001D944: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x8001D948: lh          $t1, 0x9E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9E);
    // 0x8001D94C: lbu         $t6, 0x3D($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X3D);
    // 0x8001D950: nop

    // 0x8001D954: beq         $t6, $zero, L_8001D984
    if (ctx->r14 == 0) {
        // 0x8001D958: nop
    
            goto L_8001D984;
    }
    // 0x8001D958: nop

    // 0x8001D95C: beq         $s2, $zero, L_8001D984
    if (ctx->r18 == 0) {
        // 0x8001D960: nop
    
            goto L_8001D984;
    }
    // 0x8001D960: nop

    // 0x8001D964: jal         0x80069FE4
    // 0x8001D968: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    get_projection_matrix_f32(rdram, ctx);
        goto after_1;
    // 0x8001D968: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    after_1:
    // 0x8001D96C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001D970: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001D974: jal         0x8006F92C
    // 0x8001D978: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_2;
    // 0x8001D978: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x8001D97C: lh          $t1, 0x9E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9E);
    // 0x8001D980: nop

L_8001D984:
    // 0x8001D984: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001D988: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001D98C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001D990: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8001D994: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001D998: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8001D99C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D9A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D9A4: lw          $v0, 0x54($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X54);
    // 0x8001D9A8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001D9AC: lh          $t6, 0x1C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1C);
    // 0x8001D9B0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8001D9B4: mfc1        $s3, $f8
    ctx->r19 = (int32_t)ctx->f8.u32l;
    // 0x8001D9B8: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8001D9BC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001D9C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D9C4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001D9C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D9CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D9D0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8001D9D4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8001D9D8: lbu         $s6, 0x7($v0)
    ctx->r22 = MEM_BU(ctx->r2, 0X7);
    // 0x8001D9DC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001D9E0: mfc1        $s4, $f18
    ctx->r20 = (int32_t)ctx->f18.u32l;
    // 0x8001D9E4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001D9E8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001D9EC: nop

    // 0x8001D9F0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001D9F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D9F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D9FC: nop

    // 0x8001DA00: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001DA04: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001DA08: mfc1        $s5, $f8
    ctx->r21 = (int32_t)ctx->f8.u32l;
    // 0x8001DA0C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001DA10: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x8001DA14: lw          $t8, 0x54($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X54);
    // 0x8001DA18: nop

    // 0x8001DA1C: lh          $t9, 0x1E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X1E);
    // 0x8001DA20: nop

    // 0x8001DA24: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001DA28: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8001DA2C: nop

    // 0x8001DA30: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DA34: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8001DA38: lw          $t7, 0x54($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X54);
    // 0x8001DA3C: nop

    // 0x8001DA40: lh          $t8, 0x20($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X20);
    // 0x8001DA44: nop

    // 0x8001DA48: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001DA4C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8001DA50: nop

    // 0x8001DA54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001DA58: beq         $s2, $zero, L_8001DA80
    if (ctx->r18 == 0) {
        // 0x8001DA5C: swc1        $f8, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
            goto L_8001DA80;
    }
    // 0x8001DA5C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x8001DA60: jal         0x80069FE4
    // 0x8001DA64: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    get_projection_matrix_f32(rdram, ctx);
        goto after_3;
    // 0x8001DA64: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    after_3:
    // 0x8001DA68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001DA6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001DA70: jal         0x8006F92C
    // 0x8001DA74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_4;
    // 0x8001DA74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x8001DA78: lh          $t1, 0x9E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9E);
    // 0x8001DA7C: nop

L_8001DA80:
    // 0x8001DA80: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8001DA84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001DA88: jal         0x80070618
    // 0x8001DA8C: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    vec3f_rotate_ypr(rdram, ctx);
        goto after_5;
    // 0x8001DA8C: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    after_5:
    // 0x8001DA90: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001DA94: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001DA98: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001DA9C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001DAA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DAA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DAA8: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001DAAC: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001DAB0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001DAB4: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001DAB8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001DABC: lw          $v0, 0x54($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X54);
    // 0x8001DAC0: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x8001DAC4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8001DAC8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001DACC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8001DAD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DAD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DAD8: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8001DADC: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8001DAE0: lwc1        $f2, 0xB0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8001DAE4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8001DAE8: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8001DAEC: lh          $t1, 0x9E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9E);
    // 0x8001DAF0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001DAF4: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8001DAF8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001DAFC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DB00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DB04: nop

    // 0x8001DB08: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001DB0C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001DB10: mfc1        $ra, $f8
    ctx->r31 = (int32_t)ctx->f8.u32l;
    // 0x8001DB14: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001DB18: lwc1        $f8, 0x2C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8001DB1C: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x8001DB20: lh          $v1, 0x28($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X28);
    // 0x8001DB24: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8001DB28: nop

    // 0x8001DB2C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8001DB30: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001DB34: nop

    // 0x8001DB38: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001DB3C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DB40: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DB44: nop

    // 0x8001DB48: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001DB4C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001DB50: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8001DB54: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001DB58: nop

    // 0x8001DB5C: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001DB60: nop

    // 0x8001DB64: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8001DB68: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001DB6C: nop

    // 0x8001DB70: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001DB74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DB78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DB7C: nop

    // 0x8001DB80: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8001DB84: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x8001DB88: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001DB8C: blez        $v1, L_8001DD58
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001DB90: nop
    
            goto L_8001DD58;
    }
    // 0x8001DB90: nop

    // 0x8001DB94: lw          $a2, 0x38($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X38);
    // 0x8001DB98: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_8001DB9C:
    // 0x8001DB9C: lh          $t3, 0x9A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X9A);
    // 0x8001DBA0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8001DBA4: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8001DBA8: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8001DBAC: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8001DBB0: addu        $v0, $a2, $t3
    ctx->r2 = ADD32(ctx->r6, ctx->r11);
    // 0x8001DBB4: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x8001DBB8: nop

    // 0x8001DBBC: beq         $t8, $at, L_8001DD0C
    if (ctx->r24 == ctx->r1) {
        // 0x8001DBC0: nop
    
            goto L_8001DD0C;
    }
    // 0x8001DBC0: nop

    // 0x8001DBC4: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x8001DBC8: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x8001DBCC: nop

    // 0x8001DBD0: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001DBD4: beq         $at, $zero, L_8001DD3C
    if (ctx->r1 == 0) {
        // 0x8001DBD8: lh          $v0, 0x9A($sp)
        ctx->r2 = MEM_H(ctx->r29, 0X9A);
            goto L_8001DD3C;
    }
    // 0x8001DBD8: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
L_8001DBDC:
    // 0x8001DBDC: multu       $t1, $s1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DBE0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8001DBE4: mflo        $t7
    ctx->r15 = lo;
    // 0x8001DBE8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8001DBEC: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    // 0x8001DBF0: lh          $a3, 0x0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X0);
    // 0x8001DBF4: multu       $a2, $s5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DBF8: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x8001DBFC: mflo        $t8
    ctx->r24 = lo;
    // 0x8001DC00: nop

    // 0x8001DC04: nop

    // 0x8001DC08: multu       $a3, $s3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC0C: mflo        $t9
    ctx->r25 = lo;
    // 0x8001DC10: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8001DC14: nop

    // 0x8001DC18: multu       $t0, $s4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC1C: mflo        $t7
    ctx->r15 = lo;
    // 0x8001DC20: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8001DC24: sra         $t8, $a0, 13
    ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
    // 0x8001DC28: blez        $t8, L_8001DC50
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001DC2C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001DC50;
    }
    // 0x8001DC2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001DC30: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC34: mflo        $a0
    ctx->r4 = lo;
    // 0x8001DC38: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001DC3C: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x8001DC40: bne         $at, $zero, L_8001DC50
    if (ctx->r1 != 0) {
        // 0x8001DC44: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_8001DC50;
    }
    // 0x8001DC44: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8001DC48: b           L_8001DC50
    // 0x8001DC4C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
        goto L_8001DC50;
    // 0x8001DC4C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8001DC50:
    // 0x8001DC50: multu       $a2, $ra
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC54: mflo        $t6
    ctx->r14 = lo;
    // 0x8001DC58: nop

    // 0x8001DC5C: nop

    // 0x8001DC60: multu       $a3, $t4
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC64: mflo        $t7
    ctx->r15 = lo;
    // 0x8001DC68: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001DC6C: nop

    // 0x8001DC70: multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC74: mflo        $t9
    ctx->r25 = lo;
    // 0x8001DC78: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8001DC7C: sra         $t6, $v1, 13
    ctx->r14 = S32(SIGNED(ctx->r3) >> 13);
    // 0x8001DC80: blez        $t6, L_8001DCAC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001DC84: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_8001DCAC;
    }
    // 0x8001DC84: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x8001DC88: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC8C: mflo        $v1
    ctx->r3 = lo;
    // 0x8001DC90: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001DC94: addu        $v1, $t7, $t2
    ctx->r3 = ADD32(ctx->r15, ctx->r10);
    // 0x8001DC98: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8001DC9C: bne         $at, $zero, L_8001DCAC
    if (ctx->r1 != 0) {
        // 0x8001DCA0: nop
    
            goto L_8001DCAC;
    }
    // 0x8001DCA0: nop

    // 0x8001DCA4: b           L_8001DCAC
    // 0x8001DCA8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_8001DCAC;
    // 0x8001DCA8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_8001DCAC:
    // 0x8001DCAC: multu       $a1, $s2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DCB0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001DCB4: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8001DCB8: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001DCBC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001DCC0: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8001DCC4: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001DCC8: mflo        $t8
    ctx->r24 = lo;
    // 0x8001DCCC: addu        $v0, $fp, $t8
    ctx->r2 = ADD32(ctx->r30, ctx->r24);
    // 0x8001DCD0: sb          $a0, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r4;
    // 0x8001DCD4: sb          $a0, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r4;
    // 0x8001DCD8: sb          $a0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r4;
    // 0x8001DCDC: sb          $v1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r3;
    // 0x8001DCE0: lw          $a2, 0x38($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X38);
    // 0x8001DCE4: nop

    // 0x8001DCE8: addu        $t9, $a2, $t3
    ctx->r25 = ADD32(ctx->r6, ctx->r11);
    // 0x8001DCEC: lh          $t6, 0xE($t9)
    ctx->r14 = MEM_H(ctx->r25, 0XE);
    // 0x8001DCF0: nop

    // 0x8001DCF4: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001DCF8: bne         $at, $zero, L_8001DBDC
    if (ctx->r1 != 0) {
        // 0x8001DCFC: nop
    
            goto L_8001DBDC;
    }
    // 0x8001DCFC: nop

    // 0x8001DD00: lh          $v1, 0x28($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X28);
    // 0x8001DD04: b           L_8001DD3C
    // 0x8001DD08: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
        goto L_8001DD3C;
    // 0x8001DD08: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
L_8001DD0C:
    // 0x8001DD0C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8001DD10: nop

    // 0x8001DD14: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8001DD18: beq         $t8, $zero, L_8001DD38
    if (ctx->r24 == 0) {
        // 0x8001DD1C: nop
    
            goto L_8001DD38;
    }
    // 0x8001DD1C: nop

    // 0x8001DD20: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x8001DD24: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8001DD28: addu        $t6, $t1, $t9
    ctx->r14 = ADD32(ctx->r9, ctx->r25);
    // 0x8001DD2C: subu        $t1, $t6, $t7
    ctx->r9 = SUB32(ctx->r14, ctx->r15);
    // 0x8001DD30: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x8001DD34: sra         $t1, $t8, 16
    ctx->r9 = S32(SIGNED(ctx->r24) >> 16);
L_8001DD38:
    // 0x8001DD38: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
L_8001DD3C:
    // 0x8001DD3C: nop

    // 0x8001DD40: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001DD44: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8001DD48: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001DD4C: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001DD50: bne         $at, $zero, L_8001DB9C
    if (ctx->r1 != 0) {
        // 0x8001DD54: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_8001DB9C;
    }
    // 0x8001DD54: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
L_8001DD58:
    // 0x8001DD58: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001DD5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DD60: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DD64: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001DD68: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001DD6C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001DD70: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DD74: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001DD78: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001DD7C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001DD80: jr          $ra
    // 0x8001DD84: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8001DD84: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void calc_env_mapping_for_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DD88: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x8001DD8C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001DD90: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001DD94: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001DD98: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001DD9C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001DDA0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001DDA4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001DDA8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001DDAC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001DDB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DDB4: sw          $a1, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r5;
    // 0x8001DDB8: sw          $a2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r6;
    // 0x8001DDBC: sw          $a3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r7;
    // 0x8001DDC0: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x8001DDC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001DDC8: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x8001DDCC: lw          $t2, 0x40($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X40);
    // 0x8001DDD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001DDD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001DDD8: addiu       $s1, $sp, 0x98
    ctx->r17 = ADD32(ctx->r29, 0X98);
    // 0x8001DDDC: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8001DDE0: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8001DDE4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001DDE8: sh          $t6, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r14;
    // 0x8001DDEC: sh          $a2, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r6;
    // 0x8001DDF0: sh          $a3, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r7;
    // 0x8001DDF4: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x8001DDF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DDFC: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x8001DE00: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x8001DE04: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8001DE08: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    // 0x8001DE0C: jal         0x8006FE70
    // 0x8001DE10: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x8001DE10: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001DE14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DE18: jal         0x8006F820
    // 0x8001DE1C: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    mtxf_to_mtxs(rdram, ctx);
        goto after_1;
    // 0x8001DE1C: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    after_1:
    // 0x8001DE20: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x8001DE24: lh          $v0, 0x28($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X28);
    // 0x8001DE28: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8001DE2C: blez        $v0, L_8001E140
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001DE30: addiu       $s3, $s3, -0x4B18
        ctx->r19 = ADD32(ctx->r19, -0X4B18);
            goto L_8001E140;
    }
    // 0x8001DE30: addiu       $s3, $s3, -0x4B18
    ctx->r19 = ADD32(ctx->r19, -0X4B18);
    // 0x8001DE34: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001DE38: lw          $a2, 0x38($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X38);
    // 0x8001DE3C: addiu       $s1, $s1, -0x4A98
    ctx->r17 = ADD32(ctx->r17, -0X4A98);
L_8001DE40:
    // 0x8001DE40: lh          $s7, 0x62($sp)
    ctx->r23 = MEM_H(ctx->r29, 0X62);
    // 0x8001DE44: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8001DE48: sll         $t3, $s7, 2
    ctx->r11 = S32(ctx->r23 << 2);
    // 0x8001DE4C: subu        $t3, $t3, $s7
    ctx->r11 = SUB32(ctx->r11, ctx->r23);
    // 0x8001DE50: sll         $s7, $t3, 2
    ctx->r23 = S32(ctx->r11 << 2);
    // 0x8001DE54: addu        $a1, $a2, $s7
    ctx->r5 = ADD32(ctx->r6, ctx->r23);
    // 0x8001DE58: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x8001DE5C: nop

    // 0x8001DE60: andi        $t4, $v1, 0x8000
    ctx->r12 = ctx->r3 & 0X8000;
    // 0x8001DE64: beq         $t4, $zero, L_8001E0F4
    if (ctx->r12 == 0) {
        // 0x8001DE68: and         $t5, $v1, $at
        ctx->r13 = ctx->r3 & ctx->r1;
            goto L_8001E0F4;
    }
    // 0x8001DE68: and         $t5, $v1, $at
    ctx->r13 = ctx->r3 & ctx->r1;
    // 0x8001DE6C: ori         $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 | 0X8000;
    // 0x8001DE70: xori        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 ^ 0X8000;
    // 0x8001DE74: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x8001DE78: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x8001DE7C: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8001DE80: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8001DE84: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8001DE88: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8001DE8C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8001DE90: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8001DE94: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001DE98: beq         $v0, $a3, L_8001DEEC
    if (ctx->r2 == ctx->r7) {
        // 0x8001DE9C: addiu       $t9, $zero, 0x6
        ctx->r25 = ADD32(0, 0X6);
            goto L_8001DEEC;
    }
    // 0x8001DE9C: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8001DEA0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001DEA4: beq         $v0, $at, L_8001DEDC
    if (ctx->r2 == ctx->r1) {
        // 0x8001DEA8: addiu       $t6, $zero, 0x5
        ctx->r14 = ADD32(0, 0X5);
            goto L_8001DEDC;
    }
    // 0x8001DEA8: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8001DEAC: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001DEB0: beq         $v0, $at, L_8001DECC
    if (ctx->r2 == ctx->r1) {
        // 0x8001DEB4: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8001DECC;
    }
    // 0x8001DEB4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8001DEB8: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8001DEBC: addiu       $t3, $zero, 0x1FF
    ctx->r11 = ADD32(0, 0X1FF);
    // 0x8001DEC0: sh          $t3, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r11;
    // 0x8001DEC4: b           L_8001DEF8
    // 0x8001DEC8: sh          $t2, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r10;
        goto L_8001DEF8;
    // 0x8001DEC8: sh          $t2, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r10;
L_8001DECC:
    // 0x8001DECC: addiu       $t5, $zero, 0xFFF
    ctx->r13 = ADD32(0, 0XFFF);
    // 0x8001DED0: sh          $t5, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r13;
    // 0x8001DED4: b           L_8001DEF8
    // 0x8001DED8: sh          $t4, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r12;
        goto L_8001DEF8;
    // 0x8001DED8: sh          $t4, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r12;
L_8001DEDC:
    // 0x8001DEDC: addiu       $t7, $zero, 0x7FF
    ctx->r15 = ADD32(0, 0X7FF);
    // 0x8001DEE0: sh          $t7, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r15;
    // 0x8001DEE4: b           L_8001DEF8
    // 0x8001DEE8: sh          $t6, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r14;
        goto L_8001DEF8;
    // 0x8001DEE8: sh          $t6, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r14;
L_8001DEEC:
    // 0x8001DEEC: addiu       $t8, $zero, 0x3FF
    ctx->r24 = ADD32(0, 0X3FF);
    // 0x8001DEF0: sh          $t8, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r24;
    // 0x8001DEF4: sh          $t9, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r25;
L_8001DEF8:
    // 0x8001DEF8: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8001DEFC: addiu       $s5, $zero, 0x6
    ctx->r21 = ADD32(0, 0X6);
    // 0x8001DF00: beq         $v0, $a3, L_8001DF3C
    if (ctx->r2 == ctx->r7) {
        // 0x8001DF04: addiu       $s6, $zero, 0x3FF
        ctx->r22 = ADD32(0, 0X3FF);
            goto L_8001DF3C;
    }
    // 0x8001DF04: addiu       $s6, $zero, 0x3FF
    ctx->r22 = ADD32(0, 0X3FF);
    // 0x8001DF08: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001DF0C: beq         $v0, $at, L_8001DF34
    if (ctx->r2 == ctx->r1) {
        // 0x8001DF10: addiu       $s5, $zero, 0x5
        ctx->r21 = ADD32(0, 0X5);
            goto L_8001DF34;
    }
    // 0x8001DF10: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x8001DF14: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001DF18: beq         $v0, $at, L_8001DF2C
    if (ctx->r2 == ctx->r1) {
        // 0x8001DF1C: addiu       $s5, $zero, 0x4
        ctx->r21 = ADD32(0, 0X4);
            goto L_8001DF2C;
    }
    // 0x8001DF1C: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x8001DF20: addiu       $s5, $zero, 0x7
    ctx->r21 = ADD32(0, 0X7);
    // 0x8001DF24: b           L_8001DF3C
    // 0x8001DF28: addiu       $s6, $zero, 0x1FF
    ctx->r22 = ADD32(0, 0X1FF);
        goto L_8001DF3C;
    // 0x8001DF28: addiu       $s6, $zero, 0x1FF
    ctx->r22 = ADD32(0, 0X1FF);
L_8001DF2C:
    // 0x8001DF2C: b           L_8001DF3C
    // 0x8001DF30: addiu       $s6, $zero, 0xFFF
    ctx->r22 = ADD32(0, 0XFFF);
        goto L_8001DF3C;
    // 0x8001DF30: addiu       $s6, $zero, 0xFFF
    ctx->r22 = ADD32(0, 0XFFF);
L_8001DF34:
    // 0x8001DF34: b           L_8001DF3C
    // 0x8001DF38: addiu       $s6, $zero, 0x7FF
    ctx->r22 = ADD32(0, 0X7FF);
        goto L_8001DF3C;
    // 0x8001DF38: addiu       $s6, $zero, 0x7FF
    ctx->r22 = ADD32(0, 0X7FF);
L_8001DF3C:
    // 0x8001DF3C: lh          $s0, 0x2($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X2);
    // 0x8001DF40: lh          $t0, 0xE($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XE);
    // 0x8001DF44: nop

    // 0x8001DF48: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001DF4C: beq         $at, $zero, L_8001E050
    if (ctx->r1 == 0) {
        // 0x8001DF50: sll         $t2, $s4, 2
        ctx->r10 = S32(ctx->r20 << 2);
            goto L_8001E050;
    }
L_8001DF50:
    // 0x8001DF50: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x8001DF54: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8001DF58: subu        $t2, $t2, $s4
    ctx->r10 = SUB32(ctx->r10, ctx->r20);
    // 0x8001DF5C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8001DF60: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8001DF64: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x8001DF68: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001DF6C: sh          $t3, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r11;
    // 0x8001DF70: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x8001DF74: sll         $t6, $s4, 16
    ctx->r14 = S32(ctx->r20 << 16);
    // 0x8001DF78: sh          $t4, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r12;
    // 0x8001DF7C: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x8001DF80: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001DF84: sra         $s4, $t6, 16
    ctx->r20 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001DF88: addiu       $a1, $a1, -0x4A92
    ctx->r5 = ADD32(ctx->r5, -0X4A92);
    // 0x8001DF8C: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x8001DF90: jal         0x8006FDA0
    // 0x8001DF94: sh          $t5, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r13;
    mtxs_transform_dir(rdram, ctx);
        goto after_2;
    // 0x8001DF94: sh          $t5, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r13;
    after_2:
    // 0x8001DF98: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8001DF9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DFA0: bne         $t9, $zero, L_8001DFB0
    if (ctx->r25 != 0) {
        // 0x8001DFA4: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8001DFB0;
    }
    // 0x8001DFA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001DFA8: jal         0x8006FBF8
    // 0x8001DFAC: addiu       $a1, $a1, -0x4A92
    ctx->r5 = ADD32(ctx->r5, -0X4A92);
    vec3s_reflect(rdram, ctx);
        goto after_3;
    // 0x8001DFAC: addiu       $a1, $a1, -0x4A92
    ctx->r5 = ADD32(ctx->r5, -0X4A92);
    after_3:
L_8001DFB0:
    // 0x8001DFB0: lh          $v0, 0x6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X6);
    // 0x8001DFB4: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x8001DFB8: blez        $v0, L_8001DFCC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001DFBC: ori         $a3, $zero, 0x8000
        ctx->r7 = 0 | 0X8000;
            goto L_8001DFCC;
    }
    // 0x8001DFBC: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // 0x8001DFC0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001DFC4: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8001DFC8: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
L_8001DFCC:
    // 0x8001DFCC: blez        $v1, L_8001DFE0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001DFD0: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_8001DFE0;
    }
    // 0x8001DFD0: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8001DFD4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8001DFD8: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x8001DFDC: sra         $v1, $t1, 16
    ctx->r3 = S32(SIGNED(ctx->r9) >> 16);
L_8001DFE0:
    // 0x8001DFE0: addu        $v0, $t3, $a3
    ctx->r2 = ADD32(ctx->r11, ctx->r7);
    // 0x8001DFE4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8001DFE8: lh          $t0, 0x6A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X6A);
    // 0x8001DFEC: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8001DFF0: addu        $v1, $t6, $a3
    ctx->r3 = ADD32(ctx->r14, ctx->r7);
    // 0x8001DFF4: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8001DFF8: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8001DFFC: lh          $t2, 0x68($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X68);
    // 0x8001E000: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001E004: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x8001E008: srav        $t1, $t5, $t0
    ctx->r9 = S32(SIGNED(ctx->r13) >> (ctx->r8 & 31));
    // 0x8001E00C: addu        $a0, $s3, $t8
    ctx->r4 = ADD32(ctx->r19, ctx->r24);
    // 0x8001E010: srav        $t4, $t9, $s5
    ctx->r12 = S32(SIGNED(ctx->r25) >> (ctx->r21 & 31));
    // 0x8001E014: and         $t5, $t4, $s6
    ctx->r13 = ctx->r12 & ctx->r22;
    // 0x8001E018: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8001E01C: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x8001E020: sh          $t5, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r13;
    // 0x8001E024: lw          $a2, 0x38($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X38);
    // 0x8001E028: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E02C: addu        $a1, $a2, $s7
    ctx->r5 = ADD32(ctx->r6, ctx->r23);
    // 0x8001E030: lh          $t0, 0xE($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XE);
    // 0x8001E034: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x8001E038: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001E03C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001E040: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x8001E044: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001E048: bne         $at, $zero, L_8001DF50
    if (ctx->r1 != 0) {
        // 0x8001E04C: sra         $s2, $t9, 16
        ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
            goto L_8001DF50;
    }
    // 0x8001E04C: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
L_8001E050:
    // 0x8001E050: lh          $s0, 0x4($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X4);
    // 0x8001E054: lh          $t1, 0x10($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X10);
    // 0x8001E058: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x8001E05C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001E060: beq         $at, $zero, L_8001E0E8
    if (ctx->r1 == 0) {
        // 0x8001E064: sll         $t2, $s0, 4
        ctx->r10 = S32(ctx->r16 << 4);
            goto L_8001E0E8;
    }
    // 0x8001E064: sll         $t2, $s0, 4
    ctx->r10 = S32(ctx->r16 << 4);
L_8001E068:
    // 0x8001E068: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x8001E06C: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x8001E070: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x8001E074: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001E078: addu        $v1, $s3, $t4
    ctx->r3 = ADD32(ctx->r19, ctx->r12);
    // 0x8001E07C: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x8001E080: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8001E084: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x8001E088: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x8001E08C: addu        $a0, $s3, $t9
    ctx->r4 = ADD32(ctx->r19, ctx->r25);
    // 0x8001E090: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x8001E094: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x8001E098: lbu         $t1, 0x3($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X3);
    // 0x8001E09C: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
    // 0x8001E0A0: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x8001E0A4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001E0A8: addu        $a1, $s3, $t2
    ctx->r5 = ADD32(ctx->r19, ctx->r10);
    // 0x8001E0AC: sh          $t0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r8;
    // 0x8001E0B0: lh          $t3, 0x0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X0);
    // 0x8001E0B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E0B8: sh          $t3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r11;
    // 0x8001E0BC: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8001E0C0: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x8001E0C4: sh          $t4, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r12;
    // 0x8001E0C8: lw          $a2, 0x38($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X38);
    // 0x8001E0CC: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8001E0D0: addu        $t7, $a2, $s7
    ctx->r15 = ADD32(ctx->r6, ctx->r23);
    // 0x8001E0D4: lh          $t9, 0x10($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X10);
    // 0x8001E0D8: nop

    // 0x8001E0DC: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001E0E0: bne         $at, $zero, L_8001E068
    if (ctx->r1 != 0) {
        // 0x8001E0E4: sll         $t2, $s0, 4
        ctx->r10 = S32(ctx->r16 << 4);
            goto L_8001E068;
    }
    // 0x8001E0E4: sll         $t2, $s0, 4
    ctx->r10 = S32(ctx->r16 << 4);
L_8001E0E8:
    // 0x8001E0E8: lh          $v0, 0x28($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X28);
    // 0x8001E0EC: b           L_8001E124
    // 0x8001E0F0: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
        goto L_8001E124;
    // 0x8001E0F0: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
L_8001E0F4:
    // 0x8001E0F4: lbu         $t8, 0x6($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X6);
    // 0x8001E0F8: nop

    // 0x8001E0FC: slti        $at, $t8, 0xFF
    ctx->r1 = SIGNED(ctx->r24) < 0XFF ? 1 : 0;
    // 0x8001E100: beq         $at, $zero, L_8001E124
    if (ctx->r1 == 0) {
        // 0x8001E104: lh          $t5, 0x62($sp)
        ctx->r13 = MEM_H(ctx->r29, 0X62);
            goto L_8001E124;
    }
    // 0x8001E104: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
    // 0x8001E108: lh          $t0, 0xE($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XE);
    // 0x8001E10C: lh          $t2, 0x2($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X2);
    // 0x8001E110: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x8001E114: subu        $s4, $t1, $t2
    ctx->r20 = SUB32(ctx->r9, ctx->r10);
    // 0x8001E118: sll         $t3, $s4, 16
    ctx->r11 = S32(ctx->r20 << 16);
    // 0x8001E11C: sra         $s4, $t3, 16
    ctx->r20 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8001E120: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
L_8001E124:
    // 0x8001E124: nop

    // 0x8001E128: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001E12C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8001E130: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001E134: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001E138: bne         $at, $zero, L_8001DE40
    if (ctx->r1 != 0) {
        // 0x8001E13C: sh          $t6, 0x62($sp)
        MEM_H(0X62, ctx->r29) = ctx->r14;
            goto L_8001DE40;
    }
    // 0x8001E13C: sh          $t6, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r14;
L_8001E140:
    // 0x8001E140: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001E144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E148: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E14C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001E150: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001E154: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001E158: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E15C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001E160: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001E164: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001E168: jr          $ra
    // 0x8001E16C: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x8001E16C: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void set_racer_position_and_angle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E170: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001E174: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001E178: addiu       $t3, $t3, -0x4C24
    ctx->r11 = ADD32(ctx->r11, -0X4C24);
    // 0x8001E17C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8001E180: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8001E184: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x8001E188: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8001E18C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8001E190: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8001E194: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8001E198: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x8001E19C: blez        $v1, L_8001E2C0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E1A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001E2C0;
    }
    // 0x8001E1A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E1A4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001E1A8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001E1AC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8001E1B0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001E1B4: addiu       $t4, $t4, -0x4C28
    ctx->r12 = ADD32(ctx->r12, -0X4C28);
    // 0x8001E1B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8001E1BC:
    // 0x8001E1BC: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8001E1C0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001E1C4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001E1C8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8001E1CC: nop

    // 0x8001E1D0: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8001E1D4: nop

    // 0x8001E1D8: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8001E1DC: bne         $t7, $zero, L_8001E2B0
    if (ctx->r15 != 0) {
        // 0x8001E1E0: nop
    
            goto L_8001E2B0;
    }
    // 0x8001E1E0: nop

    // 0x8001E1E4: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
    // 0x8001E1E8: nop

    // 0x8001E1EC: bne         $t5, $t8, L_8001E2B0
    if (ctx->r13 != ctx->r24) {
        // 0x8001E1F0: nop
    
            goto L_8001E2B0;
    }
    // 0x8001E1F0: nop

    // 0x8001E1F4: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8001E1F8: nop

    // 0x8001E1FC: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x8001E200: nop

    // 0x8001E204: bne         $s0, $t9, L_8001E2B4
    if (ctx->r16 != ctx->r25) {
        // 0x8001E208: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001E2B4;
    }
    // 0x8001E208: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E20C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001E210: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001E214: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001E218: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001E21C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001E220: nop

    // 0x8001E224: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001E228: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001E22C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8001E230: nop

    // 0x8001E234: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001E238: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
    // 0x8001E23C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001E240: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001E244: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001E248: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001E24C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001E250: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001E254: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001E258: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8001E25C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001E260: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x8001E264: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001E268: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001E26C: nop

    // 0x8001E270: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8001E274: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8001E278: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001E27C: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x8001E280: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x8001E284: nop

    // 0x8001E288: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x8001E28C: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8001E290: nop

    // 0x8001E294: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x8001E298: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8001E29C: nop

    // 0x8001E2A0: sh          $t6, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r14;
    // 0x8001E2A4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8001E2A8: nop

    // 0x8001E2AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001E2B0:
    // 0x8001E2B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001E2B4:
    // 0x8001E2B4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E2B8: bne         $at, $zero, L_8001E1BC
    if (ctx->r1 != 0) {
        // 0x8001E2BC: nop
    
            goto L_8001E1BC;
    }
    // 0x8001E2BC: nop

L_8001E2C0:
    // 0x8001E2C0: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8001E2C4: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8001E2C8: jr          $ra
    // 0x8001E2CC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8001E2CC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void get_misc_asset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E2D0: bltz        $a0, L_8001E2EC
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001E2D4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001E2EC;
    }
    // 0x8001E2D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001E2D8: lw          $t6, -0x4CE0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CE0);
    // 0x8001E2DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001E2E0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001E2E4: bne         $at, $zero, L_8001E2FC
    if (ctx->r1 != 0) {
        // 0x8001E2E8: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8001E2FC;
    }
    // 0x8001E2E8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
L_8001E2EC:
    // 0x8001E2EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E2F0: lw          $v0, -0x4D14($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D14);
    // 0x8001E2F4: jr          $ra
    // 0x8001E2F8: nop

    return;
    // 0x8001E2F8: nop

L_8001E2FC:
    // 0x8001E2FC: lw          $t7, -0x4D10($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4D10);
    // 0x8001E300: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001E304: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001E308: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8001E30C: lw          $t2, -0x4D14($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4D14);
    // 0x8001E310: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8001E314: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8001E318: jr          $ra
    // 0x8001E31C: nop

    return;
    // 0x8001E31C: nop

;}
RECOMP_FUNC void is_bridge_raised(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E320: bltz        $a0, L_8001E36C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001E324: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_8001E36C;
    }
    // 0x8001E324: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8001E328: beq         $at, $zero, L_8001E36C
    if (ctx->r1 == 0) {
        // 0x8001E32C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001E36C;
    }
    // 0x8001E32C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001E330: lw          $t6, -0x4CB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CB4);
    // 0x8001E334: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001E338: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x8001E33C: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x8001E340: nop

    // 0x8001E344: blez        $v1, L_8001E364
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E348: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8001E364;
    }
    // 0x8001E348: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8001E34C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8001E350: lw          $t8, -0x4CB4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4CB4);
    // 0x8001E354: nop

    // 0x8001E358: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8001E35C: lb          $v1, 0x0($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X0);
    // 0x8001E360: nop

L_8001E364:
    // 0x8001E364: jr          $ra
    // 0x8001E368: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001E368: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001E36C:
    // 0x8001E36C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E370: jr          $ra
    // 0x8001E374: nop

    return;
    // 0x8001E374: nop

;}
RECOMP_FUNC void start_bridge_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E378: bltz        $a0, L_8001E398
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001E37C: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_8001E398;
    }
    // 0x8001E37C: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8001E380: beq         $at, $zero, L_8001E398
    if (ctx->r1 == 0) {
        // 0x8001E384: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8001E398;
    }
    // 0x8001E384: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001E388: lw          $t7, -0x4CB4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CB4);
    // 0x8001E38C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8001E390: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8001E394: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
L_8001E398:
    // 0x8001E398: jr          $ra
    // 0x8001E39C: nop

    return;
    // 0x8001E39C: nop

;}
RECOMP_FUNC void obj_bridge_pos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E3A0: lui         $at, 0xC6FA
    ctx->r1 = S32(0XC6FA << 16);
    // 0x8001E3A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001E3A8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8001E3AC: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8001E3B0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8001E3B4: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8001E3B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E3BC: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x8001E3C0: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x8001E3C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001E3C8: blez        $v1, L_8001E468
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E3CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001E468;
    }
    // 0x8001E3CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E3D0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001E3D4: addiu       $t1, $t1, -0x4C28
    ctx->r9 = ADD32(ctx->r9, -0X4C28);
    // 0x8001E3D8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001E3DC: addiu       $t2, $zero, 0x27
    ctx->r10 = ADD32(0, 0X27);
L_8001E3E0:
    // 0x8001E3E0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001E3E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E3E8: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8001E3EC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8001E3F0: nop

    // 0x8001E3F4: beq         $a0, $zero, L_8001E460
    if (ctx->r4 == 0) {
        // 0x8001E3F8: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E460;
    }
    // 0x8001E3F8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E3FC: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x8001E400: nop

    // 0x8001E404: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8001E408: bne         $t9, $zero, L_8001E460
    if (ctx->r25 != 0) {
        // 0x8001E40C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E460;
    }
    // 0x8001E40C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E410: lh          $t3, 0x48($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X48);
    // 0x8001E414: nop

    // 0x8001E418: bne         $t2, $t3, L_8001E460
    if (ctx->r10 != ctx->r11) {
        // 0x8001E41C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E460;
    }
    // 0x8001E41C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E420: lw          $t4, 0x78($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X78);
    // 0x8001E424: nop

    // 0x8001E428: bne         $s0, $t4, L_8001E460
    if (ctx->r16 != ctx->r12) {
        // 0x8001E42C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E460;
    }
    // 0x8001E42C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E430: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001E434: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E438: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8001E43C: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001E440: nop

    // 0x8001E444: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8001E448: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001E44C: nop

    // 0x8001E450: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x8001E454: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x8001E458: nop

    // 0x8001E45C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E460:
    // 0x8001E460: bne         $at, $zero, L_8001E3E0
    if (ctx->r1 != 0) {
        // 0x8001E464: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8001E3E0;
    }
    // 0x8001E464: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8001E468:
    // 0x8001E468: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8001E46C: jr          $ra
    // 0x8001E470: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8001E470: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void cutscene_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E474: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E478: lh          $v0, -0x4C06($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4C06);
    // 0x8001E47C: jr          $ra
    // 0x8001E480: nop

    return;
    // 0x8001E480: nop

;}
RECOMP_FUNC void cutscene_id_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E484: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E488: jr          $ra
    // 0x8001E48C: sh          $a0, -0x4C06($at)
    MEM_H(-0X4C06, ctx->r1) = ctx->r4;
    return;
    // 0x8001E48C: sh          $a0, -0x4C06($at)
    MEM_H(-0X4C06, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8001E45C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E490: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E494: addiu       $v0, $v0, -0x4C06
    ctx->r2 = ADD32(ctx->r2, -0X4C06);
    // 0x8001E498: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8001E49C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E4A0: beq         $a0, $t6, L_8001E4D8
    if (ctx->r4 == ctx->r14) {
        // 0x8001E4A4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8001E4D8;
    }
    // 0x8001E4A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E4A8: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x8001E4AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E4B0: sw          $zero, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = 0;
    // 0x8001E4B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E4B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001E4BC: jal         0x8006DC4C
    // 0x8001E4C0: sb          $t7, -0x4C02($at)
    MEM_B(-0X4C02, ctx->r1) = ctx->r15;
    get_game_mode(rdram, ctx);
        goto after_0;
    // 0x8001E4C0: sb          $t7, -0x4C02($at)
    MEM_B(-0X4C02, ctx->r1) = ctx->r15;
    after_0:
    // 0x8001E4C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E4C8: bne         $v0, $at, L_8001E4DC
    if (ctx->r2 != ctx->r1) {
        // 0x8001E4CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E4DC;
    }
    // 0x8001E4CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E4D0: jal         0x8006F66C
    // 0x8001E4D4: nop

    set_frame_blackout_timer(rdram, ctx);
        goto after_1;
    // 0x8001E4D4: nop

    after_1:
L_8001E4D8:
    // 0x8001E4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E4DC:
    // 0x8001E4DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E4E0: jr          $ra
    // 0x8001E4E4: nop

    return;
    // 0x8001E4E4: nop

;}
RECOMP_FUNC void get_object_list_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E4E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E4EC: lw          $v0, -0x4C20($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C20);
    // 0x8001E4F0: jr          $ra
    // 0x8001E4F4: nop

    return;
    // 0x8001E4F4: nop

;}
RECOMP_FUNC void func_8001E4C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E4F8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8001E4FC: addiu       $t0, $t0, -0x4C24
    ctx->r8 = ADD32(ctx->r8, -0X4C24);
    // 0x8001E500: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001E504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E508: blez        $v1, L_8001E558
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E50C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001E558;
    }
    // 0x8001E50C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001E510: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001E514: addiu       $t1, $t1, -0x4C28
    ctx->r9 = ADD32(ctx->r9, -0X4C28);
    // 0x8001E518: addiu       $a2, $zero, -0x2001
    ctx->r6 = ADD32(0, -0X2001);
L_8001E51C:
    // 0x8001E51C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001E520: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E524: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8001E528: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x8001E52C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001E530: lh          $t8, 0x6($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X6);
    // 0x8001E534: nop

    // 0x8001E538: and         $t9, $t8, $a2
    ctx->r25 = ctx->r24 & ctx->r6;
    // 0x8001E53C: sh          $t9, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r25;
    // 0x8001E540: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001E544: nop

    // 0x8001E548: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E54C: bne         $at, $zero, L_8001E51C
    if (ctx->r1 != 0) {
        // 0x8001E550: nop
    
            goto L_8001E51C;
    }
    // 0x8001E550: nop

    // 0x8001E554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001E558:
    // 0x8001E558: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001E55C: blez        $v1, L_8001E610
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E560: addiu       $t1, $t1, -0x4C28
        ctx->r9 = ADD32(ctx->r9, -0X4C28);
            goto L_8001E610;
    }
    // 0x8001E560: addiu       $t1, $t1, -0x4C28
    ctx->r9 = ADD32(ctx->r9, -0X4C28);
    // 0x8001E564: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001E568: addiu       $t3, $t3, -0x4C06
    ctx->r11 = ADD32(ctx->r11, -0X4C06);
    // 0x8001E56C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001E570: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8001E574: addiu       $t2, $zero, 0x31
    ctx->r10 = ADD32(0, 0X31);
L_8001E578:
    // 0x8001E578: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8001E57C: nop

    // 0x8001E580: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x8001E584: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8001E588: nop

    // 0x8001E58C: beq         $a1, $zero, L_8001E5F8
    if (ctx->r5 == 0) {
        // 0x8001E590: nop
    
            goto L_8001E5F8;
    }
    // 0x8001E590: nop

    // 0x8001E594: lh          $v1, 0x6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X6);
    // 0x8001E598: nop

    // 0x8001E59C: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x8001E5A0: bne         $t7, $zero, L_8001E5F8
    if (ctx->r15 != 0) {
        // 0x8001E5A4: nop
    
            goto L_8001E5F8;
    }
    // 0x8001E5A4: nop

    // 0x8001E5A8: lh          $t8, 0x48($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X48);
    // 0x8001E5AC: nop

    // 0x8001E5B0: bne         $t2, $t8, L_8001E5F8
    if (ctx->r10 != ctx->r24) {
        // 0x8001E5B4: nop
    
            goto L_8001E5F8;
    }
    // 0x8001E5B4: nop

    // 0x8001E5B8: lw          $a2, 0x3C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X3C);
    // 0x8001E5BC: lh          $t9, 0x0($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X0);
    // 0x8001E5C0: lb          $a3, 0x21($a2)
    ctx->r7 = MEM_B(ctx->r6, 0X21);
    // 0x8001E5C4: nop

    // 0x8001E5C8: beq         $t9, $a3, L_8001E5F8
    if (ctx->r25 == ctx->r7) {
        // 0x8001E5CC: nop
    
            goto L_8001E5F8;
    }
    // 0x8001E5CC: nop

    // 0x8001E5D0: beq         $t4, $a3, L_8001E5F8
    if (ctx->r12 == ctx->r7) {
        // 0x8001E5D4: nop
    
            goto L_8001E5F8;
    }
    // 0x8001E5D4: nop

    // 0x8001E5D8: lw          $a2, 0x64($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X64);
    // 0x8001E5DC: ori         $t5, $v1, 0x2000
    ctx->r13 = ctx->r3 | 0X2000;
    // 0x8001E5E0: beq         $a2, $zero, L_8001E5F8
    if (ctx->r6 == 0) {
        // 0x8001E5E4: sh          $t5, 0x6($a1)
        MEM_H(0X6, ctx->r5) = ctx->r13;
            goto L_8001E5F8;
    }
    // 0x8001E5E4: sh          $t5, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r13;
    // 0x8001E5E8: lh          $t6, 0x6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X6);
    // 0x8001E5EC: nop

    // 0x8001E5F0: ori         $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 | 0X2000;
    // 0x8001E5F4: sh          $t7, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r15;
L_8001E5F8:
    // 0x8001E5F8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001E5FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E600: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E604: bne         $at, $zero, L_8001E578
    if (ctx->r1 != 0) {
        // 0x8001E608: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8001E578;
    }
    // 0x8001E608: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001E60C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001E610:
    // 0x8001E610: addiu       $a2, $v1, -0x1
    ctx->r6 = ADD32(ctx->r3, -0X1);
    // 0x8001E614: bltz        $a2, L_8001E70C
    if (SIGNED(ctx->r6) < 0) {
        // 0x8001E618: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_8001E70C;
    }
    // 0x8001E618: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8001E61C: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
L_8001E620:
    // 0x8001E620: bne         $at, $zero, L_8001E674
    if (ctx->r1 != 0) {
        // 0x8001E624: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001E674;
    }
    // 0x8001E624: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001E628: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001E62C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8001E630: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
L_8001E634:
    // 0x8001E634: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8001E638: nop

    // 0x8001E63C: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8001E640: nop

    // 0x8001E644: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x8001E648: beq         $t7, $zero, L_8001E65C
    if (ctx->r15 == 0) {
        // 0x8001E64C: nop
    
            goto L_8001E65C;
    }
    // 0x8001E64C: nop

    // 0x8001E650: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E654: b           L_8001E660
    // 0x8001E658: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_8001E660;
    // 0x8001E658: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8001E65C:
    // 0x8001E65C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8001E660:
    // 0x8001E660: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001E664: bne         $at, $zero, L_8001E674
    if (ctx->r1 != 0) {
        // 0x8001E668: nop
    
            goto L_8001E674;
    }
    // 0x8001E668: nop

    // 0x8001E66C: beq         $v1, $zero, L_8001E634
    if (ctx->r3 == 0) {
        // 0x8001E670: nop
    
            goto L_8001E634;
    }
    // 0x8001E670: nop

L_8001E674:
    // 0x8001E674: bltz        $a2, L_8001E6C4
    if (SIGNED(ctx->r6) < 0) {
        // 0x8001E678: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001E6C4;
    }
    // 0x8001E678: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001E67C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001E680: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8001E684: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
L_8001E688:
    // 0x8001E688: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8001E68C: nop

    // 0x8001E690: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8001E694: nop

    // 0x8001E698: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x8001E69C: beq         $t7, $zero, L_8001E6AC
    if (ctx->r15 == 0) {
        // 0x8001E6A0: nop
    
            goto L_8001E6AC;
    }
    // 0x8001E6A0: nop

    // 0x8001E6A4: b           L_8001E6B4
    // 0x8001E6A8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_8001E6B4;
    // 0x8001E6A8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8001E6AC:
    // 0x8001E6AC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001E6B0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
L_8001E6B4:
    // 0x8001E6B4: bltz        $a2, L_8001E6C8
    if (SIGNED(ctx->r6) < 0) {
        // 0x8001E6B8: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001E6C8;
    }
    // 0x8001E6B8: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001E6BC: beq         $v1, $zero, L_8001E688
    if (ctx->r3 == 0) {
        // 0x8001E6C0: nop
    
            goto L_8001E688;
    }
    // 0x8001E6C0: nop

L_8001E6C4:
    // 0x8001E6C4: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
L_8001E6C8:
    // 0x8001E6C8: beq         $at, $zero, L_8001E700
    if (ctx->r1 == 0) {
        // 0x8001E6CC: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8001E700;
    }
    // 0x8001E6CC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001E6D0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8001E6D4: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8001E6D8: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x8001E6DC: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8001E6E0: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
    // 0x8001E6E4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8001E6E8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8001E6EC: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001E6F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E6F4: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8001E6F8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001E6FC: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
L_8001E700:
    // 0x8001E700: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001E704: beq         $at, $zero, L_8001E620
    if (ctx->r1 == 0) {
        // 0x8001E708: slt         $at, $a3, $v0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001E620;
    }
    // 0x8001E708: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
L_8001E70C:
    // 0x8001E70C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E710: sw          $v0, -0x4C20($at)
    MEM_W(-0X4C20, ctx->r1) = ctx->r2;
    // 0x8001E714: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E718: jr          $ra
    // 0x8001E71C: sh          $zero, -0x4C04($at)
    MEM_H(-0X4C04, ctx->r1) = 0;
    return;
    // 0x8001E71C: sh          $zero, -0x4C04($at)
    MEM_H(-0X4C04, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8001E6EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E720: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001E724: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8001E728: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E72C: lb          $v1, -0x4C80($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X4C80);
    // 0x8001E730: sll         $s0, $a0, 24
    ctx->r16 = S32(ctx->r4 << 24);
    // 0x8001E734: sra         $t6, $s0, 24
    ctx->r14 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8001E738: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8001E73C: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x8001E740: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x8001E744: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x8001E748: blez        $v1, L_8001E8B4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E74C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001E8B4;
    }
    // 0x8001E74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E750: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001E754: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8001E758: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001E75C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001E760: addiu       $t4, $t4, -0x4C06
    ctx->r12 = ADD32(ctx->r12, -0X4C06);
    // 0x8001E764: addiu       $s1, $s1, -0x4C08
    ctx->r17 = ADD32(ctx->r17, -0X4C08);
    // 0x8001E768: addiu       $s2, $s2, -0x4C0C
    ctx->r18 = ADD32(ctx->r18, -0X4C0C);
    // 0x8001E76C: addiu       $a1, $a1, -0x4CA8
    ctx->r5 = ADD32(ctx->r5, -0X4CA8);
    // 0x8001E770: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
L_8001E774:
    // 0x8001E774: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8001E778: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x8001E77C: lw          $a2, 0x3C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X3C);
    // 0x8001E780: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x8001E784: lb          $t0, 0x9($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X9);
    // 0x8001E788: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E78C: beq         $t7, $t0, L_8001E79C
    if (ctx->r15 == ctx->r8) {
        // 0x8001E790: nop
    
            goto L_8001E79C;
    }
    // 0x8001E790: nop

    // 0x8001E794: bne         $t5, $t0, L_8001E8AC
    if (ctx->r13 != ctx->r8) {
        // 0x8001E798: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E8AC;
    }
    // 0x8001E798: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E79C:
    // 0x8001E79C: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x8001E7A0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001E7A4: blez        $t1, L_8001E7F8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001E7A8: nop
    
            goto L_8001E7F8;
    }
    // 0x8001E7A8: nop

    // 0x8001E7AC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8001E7B0: lb          $t2, 0x8($a2)
    ctx->r10 = MEM_B(ctx->r6, 0X8);
    // 0x8001E7B4: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8001E7B8: nop

    // 0x8001E7BC: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x8001E7C0: nop

    // 0x8001E7C4: beq         $t2, $t9, L_8001E7F8
    if (ctx->r10 == ctx->r25) {
        // 0x8001E7C8: nop
    
            goto L_8001E7F8;
    }
    // 0x8001E7C8: nop

L_8001E7CC:
    // 0x8001E7CC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001E7D0: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001E7D4: beq         $at, $zero, L_8001E7F8
    if (ctx->r1 == 0) {
        // 0x8001E7D8: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_8001E7F8;
    }
    // 0x8001E7D8: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8001E7DC: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8001E7E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001E7E4: nop

    // 0x8001E7E8: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x8001E7EC: nop

    // 0x8001E7F0: bne         $t2, $t9, L_8001E7CC
    if (ctx->r10 != ctx->r25) {
        // 0x8001E7F4: nop
    
            goto L_8001E7CC;
    }
    // 0x8001E7F4: nop

L_8001E7F8:
    // 0x8001E7F8: beq         $t0, $t1, L_8001E898
    if (ctx->r8 == ctx->r9) {
        // 0x8001E7FC: nop
    
            goto L_8001E898;
    }
    // 0x8001E7FC: nop

    // 0x8001E800: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001E804: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8001E808: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001E80C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001E810: nop

    // 0x8001E814: lw          $a2, 0x64($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X64);
    // 0x8001E818: nop

    // 0x8001E81C: beq         $a2, $zero, L_8001E898
    if (ctx->r6 == 0) {
        // 0x8001E820: nop
    
            goto L_8001E898;
    }
    // 0x8001E820: nop

    // 0x8001E824: lw          $t6, 0x5C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X5C);
    // 0x8001E828: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001E82C: beq         $t6, $zero, L_8001E83C
    if (ctx->r14 == 0) {
        // 0x8001E830: nop
    
            goto L_8001E83C;
    }
    // 0x8001E830: nop

    // 0x8001E834: b           L_8001E83C
    // 0x8001E838: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_8001E83C;
    // 0x8001E838: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8001E83C:
    // 0x8001E83C: beq         $s0, $t0, L_8001E8AC
    if (ctx->r16 == ctx->r8) {
        // 0x8001E840: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E8AC;
    }
    // 0x8001E840: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E844: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8001E848: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E84C: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x8001E850: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8001E854: nop

    // 0x8001E858: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
    // 0x8001E85C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8001E860: sw          $a2, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r6;
    // 0x8001E864: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x8001E868: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001E86C: nop

    // 0x8001E870: swc1        $f10, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f10.u32l;
    // 0x8001E874: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001E878: nop

    // 0x8001E87C: swc1        $f16, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f16.u32l;
    // 0x8001E880: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001E884: nop

    // 0x8001E888: swc1        $f18, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f18.u32l;
    // 0x8001E88C: lb          $v1, -0x4C80($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X4C80);
    // 0x8001E890: b           L_8001E8AC
    // 0x8001E894: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_8001E8AC;
    // 0x8001E894: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E898:
    // 0x8001E898: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x8001E89C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E8A0: lb          $v1, -0x4C80($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X4C80);
    // 0x8001E8A4: nop

    // 0x8001E8A8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E8AC:
    // 0x8001E8AC: bne         $at, $zero, L_8001E774
    if (ctx->r1 != 0) {
        // 0x8001E8B0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001E774;
    }
    // 0x8001E8B0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001E8B4:
    // 0x8001E8B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E8B8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8001E8BC: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x8001E8C0: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x8001E8C4: sb          $zero, -0x4C7F($at)
    MEM_B(-0X4C7F, ctx->r1) = 0;
    // 0x8001E8C8: jr          $ra
    // 0x8001E8CC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8001E8CC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8001E89C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E8D0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E8D4: addiu       $v0, $v0, -0x4C7F
    ctx->r2 = ADD32(ctx->r2, -0X4C7F);
    // 0x8001E8D8: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8001E8DC: nop

    // 0x8001E8E0: beq         $t6, $zero, L_8001E8F0
    if (ctx->r14 == 0) {
        // 0x8001E8E4: nop
    
            goto L_8001E8F0;
    }
    // 0x8001E8E4: nop

    // 0x8001E8E8: jr          $ra
    // 0x8001E8EC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    return;
    // 0x8001E8EC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8001E8F0:
    // 0x8001E8F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E8F4: lb          $v1, -0x4C80($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X4C80);
    // 0x8001E8F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E8FC: blez        $v1, L_8001E968
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E900: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8001E968;
    }
    // 0x8001E900: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001E904: addiu       $a1, $a1, -0x4CA8
    ctx->r5 = ADD32(ctx->r5, -0X4CA8);
L_8001E908:
    // 0x8001E908: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8001E90C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E910: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x8001E914: nop

    // 0x8001E918: lw          $a3, 0xC($a2)
    ctx->r7 = MEM_W(ctx->r6, 0XC);
    // 0x8001E91C: nop

    // 0x8001E920: beq         $a3, $zero, L_8001E960
    if (ctx->r7 == 0) {
        // 0x8001E924: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E960;
    }
    // 0x8001E924: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E928: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001E92C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E930: swc1        $f4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f4.u32l;
    // 0x8001E934: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x8001E938: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001E93C: nop

    // 0x8001E940: swc1        $f6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f6.u32l;
    // 0x8001E944: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x8001E948: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8001E94C: nop

    // 0x8001E950: swc1        $f8, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f8.u32l;
    // 0x8001E954: lb          $v1, -0x4C80($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X4C80);
    // 0x8001E958: nop

    // 0x8001E95C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E960:
    // 0x8001E960: bne         $at, $zero, L_8001E908
    if (ctx->r1 != 0) {
        // 0x8001E964: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001E908;
    }
    // 0x8001E964: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001E968:
    // 0x8001E968: jr          $ra
    // 0x8001E96C: nop

    return;
    // 0x8001E96C: nop

;}
RECOMP_FUNC void func_8001E93C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E970: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001E974: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001E978: lb          $t6, -0x4C02($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X4C02);
    // 0x8001E97C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001E980: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001E984: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001E988: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001E98C: beq         $t6, $zero, L_8001EA1C
    if (ctx->r14 == 0) {
        // 0x8001E990: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8001EA1C;
    }
    // 0x8001E990: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001E994: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001E998: lh          $a0, -0x4C08($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4C08);
    // 0x8001E99C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001E9A0: blez        $a0, L_8001EA1C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001E9A4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8001EA1C;
    }
    // 0x8001E9A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001E9A8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001E9AC: addiu       $t5, $t5, -0x4C0C
    ctx->r13 = ADD32(ctx->r13, -0X4C0C);
    // 0x8001E9B0: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
L_8001E9B4:
    // 0x8001E9B4: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001E9B8: nop

    // 0x8001E9BC: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8001E9C0: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001E9C4: nop

    // 0x8001E9C8: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8001E9CC: lw          $t0, 0x3C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X3C);
    // 0x8001E9D0: beq         $v1, $zero, L_8001EA0C
    if (ctx->r3 == 0) {
        // 0x8001E9D4: nop
    
            goto L_8001EA0C;
    }
    // 0x8001E9D4: nop

    // 0x8001E9D8: lb          $t9, 0x21($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X21);
    // 0x8001E9DC: nop

    // 0x8001E9E0: beq         $s0, $t9, L_8001EA0C
    if (ctx->r16 == ctx->r25) {
        // 0x8001E9E4: nop
    
            goto L_8001EA0C;
    }
    // 0x8001E9E4: nop

    // 0x8001E9E8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001E9EC: jal         0x8000FFB8
    // 0x8001E9F0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    free_object(rdram, ctx);
        goto after_0;
    // 0x8001E9F0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8001E9F4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8001E9F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001E9FC: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x8001EA00: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001EA04: lh          $a0, -0x4C08($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4C08);
    // 0x8001EA08: addiu       $t5, $t5, -0x4C0C
    ctx->r13 = ADD32(ctx->r13, -0X4C0C);
L_8001EA0C:
    // 0x8001EA0C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001EA10: slt         $at, $s3, $a0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001EA14: bne         $at, $zero, L_8001E9B4
    if (ctx->r1 != 0) {
        // 0x8001EA18: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8001E9B4;
    }
    // 0x8001EA18: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8001EA1C:
    // 0x8001EA1C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001EA20: addiu       $v0, $v0, -0x4D42
    ctx->r2 = ADD32(ctx->r2, -0X4D42);
    // 0x8001EA24: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8001EA28: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
    // 0x8001EA2C: slti        $at, $t6, 0x15
    ctx->r1 = SIGNED(ctx->r14) < 0X15 ? 1 : 0;
    // 0x8001EA30: bne         $at, $zero, L_8001EA3C
    if (ctx->r1 != 0) {
        // 0x8001EA34: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001EA3C;
    }
    // 0x8001EA34: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001EA38: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8001EA3C:
    // 0x8001EA3C: jal         0x8001E4F8
    // 0x8001EA40: nop

    func_8001E4C4(rdram, ctx);
        goto after_1;
    // 0x8001EA40: nop

    after_1:
    // 0x8001EA44: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001EA48: lw          $a2, -0x4C24($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C24);
    // 0x8001EA4C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001EA50: blez        $a2, L_8001EAE0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001EA54: addiu       $t5, $t5, -0x4C0C
        ctx->r13 = ADD32(ctx->r13, -0X4C0C);
            goto L_8001EAE0;
    }
    // 0x8001EA54: addiu       $t5, $t5, -0x4C0C
    ctx->r13 = ADD32(ctx->r13, -0X4C0C);
    // 0x8001EA58: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001EA5C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001EA60: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001EA64: lw          $a1, -0x4C28($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4C28);
    // 0x8001EA68: addiu       $t1, $t1, -0x4C06
    ctx->r9 = ADD32(ctx->r9, -0X4C06);
    // 0x8001EA6C: addiu       $t3, $t3, -0x4CA8
    ctx->r11 = ADD32(ctx->r11, -0X4CA8);
    // 0x8001EA70: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8001EA74: sll         $a3, $a2, 2
    ctx->r7 = S32(ctx->r6 << 2);
    // 0x8001EA78: addiu       $t0, $zero, 0x53
    ctx->r8 = ADD32(0, 0X53);
L_8001EA7C:
    // 0x8001EA7C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8001EA80: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001EA84: beq         $v0, $zero, L_8001EAD8
    if (ctx->r2 == 0) {
        // 0x8001EA88: slt         $at, $t2, $a3
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8001EAD8;
    }
    // 0x8001EA88: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001EA8C: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8001EA90: nop

    // 0x8001EA94: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8001EA98: bne         $t8, $zero, L_8001EAD8
    if (ctx->r24 != 0) {
        // 0x8001EA9C: nop
    
            goto L_8001EAD8;
    }
    // 0x8001EA9C: nop

    // 0x8001EAA0: lh          $t9, 0x48($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X48);
    // 0x8001EAA4: nop

    // 0x8001EAA8: bne         $t0, $t9, L_8001EAD8
    if (ctx->r8 != ctx->r25) {
        // 0x8001EAAC: nop
    
            goto L_8001EAD8;
    }
    // 0x8001EAAC: nop

    // 0x8001EAB0: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x8001EAB4: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x8001EAB8: lb          $a0, 0x9($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X9);
    // 0x8001EABC: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x8001EAC0: beq         $t6, $a0, L_8001EAD0
    if (ctx->r14 == ctx->r4) {
        // 0x8001EAC4: addu        $t8, $t3, $t7
        ctx->r24 = ADD32(ctx->r11, ctx->r15);
            goto L_8001EAD0;
    }
    // 0x8001EAC4: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x8001EAC8: bne         $s0, $a0, L_8001EAD8
    if (ctx->r16 != ctx->r4) {
        // 0x8001EACC: nop
    
            goto L_8001EAD8;
    }
    // 0x8001EACC: nop

L_8001EAD0:
    // 0x8001EAD0: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8001EAD4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8001EAD8:
    // 0x8001EAD8: bne         $at, $zero, L_8001EA7C
    if (ctx->r1 != 0) {
        // 0x8001EADC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001EA7C;
    }
    // 0x8001EADC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001EAE0:
    // 0x8001EAE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EAE4: sb          $s3, -0x4C80($at)
    MEM_B(-0X4C80, ctx->r1) = ctx->r19;
    // 0x8001EAE8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8001EAEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EAF0: sb          $s2, -0x4C7F($at)
    MEM_B(-0X4C7F, ctx->r1) = ctx->r18;
    // 0x8001EAF4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001EAF8: lw          $t4, -0x4C20($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4C20);
    // 0x8001EAFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EB00: sh          $zero, -0x4C08($at)
    MEM_H(-0X4C08, ctx->r1) = 0;
    // 0x8001EB04: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001EB08: beq         $at, $zero, L_8001EB84
    if (ctx->r1 == 0) {
        // 0x8001EB0C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001EB84;
    }
    // 0x8001EB0C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001EB10: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001EB14: addiu       $v1, $v1, -0x4C28
    ctx->r3 = ADD32(ctx->r3, -0X4C28);
    // 0x8001EB18: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8001EB1C: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
L_8001EB20:
    // 0x8001EB20: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8001EB24: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8001EB28: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8001EB2C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8001EB30: nop

    // 0x8001EB34: beq         $v0, $zero, L_8001EB7C
    if (ctx->r2 == 0) {
        // 0x8001EB38: slt         $at, $t4, $a2
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001EB7C;
    }
    // 0x8001EB38: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001EB3C: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8001EB40: nop

    // 0x8001EB44: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8001EB48: bne         $t8, $zero, L_8001EB7C
    if (ctx->r24 != 0) {
        // 0x8001EB4C: slt         $at, $t4, $a2
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001EB7C;
    }
    // 0x8001EB4C: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001EB50: lh          $t9, 0x48($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X48);
    // 0x8001EB54: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x8001EB58: bne         $a0, $t9, L_8001EB7C
    if (ctx->r4 != ctx->r25) {
        // 0x8001EB5C: slt         $at, $t4, $a2
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001EB7C;
    }
    // 0x8001EB5C: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001EB60: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001EB64: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001EB68: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001EB6C: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8001EB70: lw          $a2, -0x4C24($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C24);
    // 0x8001EB74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001EB78: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
L_8001EB7C:
    // 0x8001EB7C: bne         $at, $zero, L_8001EB20
    if (ctx->r1 != 0) {
        // 0x8001EB80: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8001EB20;
    }
    // 0x8001EB80: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
L_8001EB84:
    // 0x8001EB84: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8001EB88: addiu       $ra, $s3, -0x1
    ctx->r31 = ADD32(ctx->r19, -0X1);
    // 0x8001EB8C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8001EB90:
    // 0x8001EB90: blez        $ra, L_8001EC98
    if (SIGNED(ctx->r31) <= 0) {
        // 0x8001EB94: or          $t3, $s2, $zero
        ctx->r11 = ctx->r18 | 0;
            goto L_8001EC98;
    }
    // 0x8001EB94: or          $t3, $s2, $zero
    ctx->r11 = ctx->r18 | 0;
    // 0x8001EB98: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001EB9C:
    // 0x8001EB9C: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8001EBA0: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8001EBA4: addu        $a1, $t9, $t2
    ctx->r5 = ADD32(ctx->r25, ctx->r10);
    // 0x8001EBA8: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x8001EBAC: lw          $a3, 0x4($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X4);
    // 0x8001EBB0: lw          $t1, 0x3C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X3C);
    // 0x8001EBB4: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    // 0x8001EBB8: lb          $t6, 0x21($t1)
    ctx->r14 = MEM_B(ctx->r9, 0X21);
    // 0x8001EBBC: lb          $v0, 0x10($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X10);
    // 0x8001EBC0: lb          $v1, 0x10($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X10);
    // 0x8001EBC4: bne         $s0, $t6, L_8001EBD8
    if (ctx->r16 != ctx->r14) {
        // 0x8001EBC8: nop
    
            goto L_8001EBD8;
    }
    // 0x8001EBC8: nop

    // 0x8001EBCC: addiu       $v0, $v0, -0x190
    ctx->r2 = ADD32(ctx->r2, -0X190);
    // 0x8001EBD0: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8001EBD4: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
L_8001EBD8:
    // 0x8001EBD8: lb          $t9, 0x21($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X21);
    // 0x8001EBDC: nop

    // 0x8001EBE0: bne         $s0, $t9, L_8001EBF8
    if (ctx->r16 != ctx->r25) {
        // 0x8001EBE4: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001EBF8;
    }
    // 0x8001EBE4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001EBE8: addiu       $v1, $v1, -0x190
    ctx->r3 = ADD32(ctx->r3, -0X190);
    // 0x8001EBEC: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8001EBF0: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001EBF4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8001EBF8:
    // 0x8001EBF8: beq         $at, $zero, L_8001EC18
    if (ctx->r1 == 0) {
        // 0x8001EBFC: nop
    
            goto L_8001EC18;
    }
    // 0x8001EBFC: nop

    // 0x8001EC00: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8001EC04: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001EC08: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001EC0C: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001EC10: b           L_8001EC8C
    // 0x8001EC14: sw          $a2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r6;
        goto L_8001EC8C;
    // 0x8001EC14: sw          $a2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r6;
L_8001EC18:
    // 0x8001EC18: bne         $v0, $v1, L_8001EC8C
    if (ctx->r2 != ctx->r3) {
        // 0x8001EC1C: nop
    
            goto L_8001EC8C;
    }
    // 0x8001EC1C: nop

    // 0x8001EC20: lb          $v0, 0x11($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X11);
    // 0x8001EC24: lb          $v1, 0x11($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X11);
    // 0x8001EC28: nop

    // 0x8001EC2C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001EC30: beq         $at, $zero, L_8001EC50
    if (ctx->r1 == 0) {
        // 0x8001EC34: nop
    
            goto L_8001EC50;
    }
    // 0x8001EC34: nop

    // 0x8001EC38: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8001EC3C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001EC40: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001EC44: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8001EC48: b           L_8001EC8C
    // 0x8001EC4C: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
        goto L_8001EC8C;
    // 0x8001EC4C: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
L_8001EC50:
    // 0x8001EC50: bne         $v0, $v1, L_8001EC8C
    if (ctx->r2 != ctx->r3) {
        // 0x8001EC54: nop
    
            goto L_8001EC8C;
    }
    // 0x8001EC54: nop

    // 0x8001EC58: lw          $t8, 0x78($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X78);
    // 0x8001EC5C: nop

    // 0x8001EC60: beq         $s2, $t8, L_8001EC78
    if (ctx->r18 == ctx->r24) {
        // 0x8001EC64: nop
    
            goto L_8001EC78;
    }
    // 0x8001EC64: nop

    // 0x8001EC68: lw          $t9, 0x78($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X78);
    // 0x8001EC6C: nop

    // 0x8001EC70: bne         $s1, $t9, L_8001EC8C
    if (ctx->r17 != ctx->r25) {
        // 0x8001EC74: nop
    
            goto L_8001EC8C;
    }
    // 0x8001EC74: nop

L_8001EC78:
    // 0x8001EC78: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8001EC7C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001EC80: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001EC84: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8001EC88: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
L_8001EC8C:
    // 0x8001EC8C: bne         $t4, $ra, L_8001EB9C
    if (ctx->r12 != ctx->r31) {
        // 0x8001EC90: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8001EB9C;
    }
    // 0x8001EC90: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001EC94: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8001EC98:
    // 0x8001EC98: beq         $t3, $zero, L_8001EB90
    if (ctx->r11 == 0) {
        // 0x8001EC9C: nop
    
            goto L_8001EB90;
    }
    // 0x8001EC9C: nop

    // 0x8001ECA0: blez        $s3, L_8001EE68
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8001ECA4: addiu       $a0, $zero, -0x65
        ctx->r4 = ADD32(0, -0X65);
            goto L_8001EE68;
    }
    // 0x8001ECA4: addiu       $a0, $zero, -0x65
    ctx->r4 = ADD32(0, -0X65);
    // 0x8001ECA8: andi        $v0, $s3, 0x3
    ctx->r2 = ctx->r19 & 0X3;
    // 0x8001ECAC: beq         $v0, $zero, L_8001ED18
    if (ctx->r2 == 0) {
        // 0x8001ECB0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001ED18;
    }
    // 0x8001ECB0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001ECB4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8001ECB8: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
L_8001ECBC:
    // 0x8001ECBC: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001ECC0: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8001ECC4: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001ECC8: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8001ECCC: nop

    // 0x8001ECD0: lw          $t1, 0x3C($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X3C);
    // 0x8001ECD4: nop

    // 0x8001ECD8: lb          $t7, 0x10($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X10);
    // 0x8001ECDC: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8001ECE0: beq         $a0, $t7, L_8001ECF0
    if (ctx->r4 == ctx->r15) {
        // 0x8001ECE4: nop
    
            goto L_8001ECF0;
    }
    // 0x8001ECE4: nop

    // 0x8001ECE8: lb          $a0, 0x10($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X10);
    // 0x8001ECEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001ECF0:
    // 0x8001ECF0: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001ECF4: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001ECF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001ECFC: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001ED00: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8001ED04: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001ED08: bne         $v1, $t4, L_8001ECBC
    if (ctx->r3 != ctx->r12) {
        // 0x8001ED0C: sw          $zero, 0x78($t6)
        MEM_W(0X78, ctx->r14) = 0;
            goto L_8001ECBC;
    }
    // 0x8001ED0C: sw          $zero, 0x78($t6)
    MEM_W(0X78, ctx->r14) = 0;
    // 0x8001ED10: beq         $t4, $s3, L_8001EE68
    if (ctx->r12 == ctx->r19) {
        // 0x8001ED14: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_8001EE68;
    }
    // 0x8001ED14: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_8001ED18:
    // 0x8001ED18: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8001ED1C: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8001ED20: sll         $a1, $s3, 2
    ctx->r5 = S32(ctx->r19 << 2);
L_8001ED24:
    // 0x8001ED24: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001ED28: nop

    // 0x8001ED2C: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8001ED30: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001ED34: nop

    // 0x8001ED38: lw          $t1, 0x3C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X3C);
    // 0x8001ED3C: nop

    // 0x8001ED40: lb          $t6, 0x10($t1)
    ctx->r14 = MEM_B(ctx->r9, 0X10);
    // 0x8001ED44: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8001ED48: beq         $a0, $t6, L_8001ED58
    if (ctx->r4 == ctx->r14) {
        // 0x8001ED4C: nop
    
            goto L_8001ED58;
    }
    // 0x8001ED4C: nop

    // 0x8001ED50: lb          $a0, 0x10($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X10);
    // 0x8001ED54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001ED58:
    // 0x8001ED58: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001ED5C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001ED60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001ED64: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8001ED68: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001ED6C: nop

    // 0x8001ED70: sw          $zero, 0x78($t9)
    MEM_W(0X78, ctx->r25) = 0;
    // 0x8001ED74: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001ED78: nop

    // 0x8001ED7C: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8001ED80: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8001ED84: nop

    // 0x8001ED88: lw          $t0, 0x3C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X3C);
    // 0x8001ED8C: nop

    // 0x8001ED90: lb          $v1, 0x10($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X10);
    // 0x8001ED94: nop

    // 0x8001ED98: beq         $a0, $v1, L_8001EDA8
    if (ctx->r4 == ctx->r3) {
        // 0x8001ED9C: nop
    
            goto L_8001EDA8;
    }
    // 0x8001ED9C: nop

    // 0x8001EDA0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001EDA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001EDA8:
    // 0x8001EDA8: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001EDAC: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8001EDB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001EDB4: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8001EDB8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001EDBC: nop

    // 0x8001EDC0: sw          $zero, 0x78($t7)
    MEM_W(0X78, ctx->r15) = 0;
    // 0x8001EDC4: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001EDC8: nop

    // 0x8001EDCC: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001EDD0: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x8001EDD4: nop

    // 0x8001EDD8: lw          $t0, 0x3C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X3C);
    // 0x8001EDDC: nop

    // 0x8001EDE0: lb          $v1, 0x10($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X10);
    // 0x8001EDE4: nop

    // 0x8001EDE8: beq         $a0, $v1, L_8001EDF8
    if (ctx->r4 == ctx->r3) {
        // 0x8001EDEC: nop
    
            goto L_8001EDF8;
    }
    // 0x8001EDEC: nop

    // 0x8001EDF0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001EDF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001EDF8:
    // 0x8001EDF8: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001EDFC: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001EE00: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001EE04: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8001EE08: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8001EE0C: nop

    // 0x8001EE10: sw          $zero, 0x78($t9)
    MEM_W(0X78, ctx->r25) = 0;
    // 0x8001EE14: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001EE18: nop

    // 0x8001EE1C: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8001EE20: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8001EE24: nop

    // 0x8001EE28: lw          $t0, 0x3C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X3C);
    // 0x8001EE2C: nop

    // 0x8001EE30: lb          $v1, 0x10($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X10);
    // 0x8001EE34: nop

    // 0x8001EE38: beq         $a0, $v1, L_8001EE48
    if (ctx->r4 == ctx->r3) {
        // 0x8001EE3C: nop
    
            goto L_8001EE48;
    }
    // 0x8001EE3C: nop

    // 0x8001EE40: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001EE44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001EE48:
    // 0x8001EE48: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001EE4C: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8001EE50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001EE54: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8001EE58: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8001EE5C: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x8001EE60: bne         $t2, $a1, L_8001ED24
    if (ctx->r10 != ctx->r5) {
        // 0x8001EE64: sw          $zero, 0x78($t7)
        MEM_W(0X78, ctx->r15) = 0;
            goto L_8001ED24;
    }
    // 0x8001EE64: sw          $zero, 0x78($t7)
    MEM_W(0X78, ctx->r15) = 0;
L_8001EE68:
    // 0x8001EE68: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001EE6C: lb          $t8, -0x4C02($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X4C02);
    // 0x8001EE70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EE74: beq         $t8, $zero, L_8001EE84
    if (ctx->r24 == 0) {
        // 0x8001EE78: sh          $s3, -0x4C08($at)
        MEM_H(-0X4C08, ctx->r1) = ctx->r19;
            goto L_8001EE84;
    }
    // 0x8001EE78: sh          $s3, -0x4C08($at)
    MEM_H(-0X4C08, ctx->r1) = ctx->r19;
    // 0x8001EE7C: jal         0x8001EEA8
    // 0x8001EE80: nop

    func_8001EE74(rdram, ctx);
        goto after_2;
    // 0x8001EE80: nop

    after_2:
L_8001EE84:
    // 0x8001EE84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001EE88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EE8C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001EE90: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001EE94: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EE98: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001EE9C: sb          $zero, -0x4C02($at)
    MEM_B(-0X4C02, ctx->r1) = 0;
    // 0x8001EEA0: jr          $ra
    // 0x8001EEA4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8001EEA4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8001EE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EEA8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001EEAC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001EEB0: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8001EEB4: addiu       $s7, $s7, -0x4C08
    ctx->r23 = ADD32(ctx->r23, -0X4C08);
    // 0x8001EEB8: lh          $t6, 0x0($s7)
    ctx->r14 = MEM_H(ctx->r23, 0X0);
    // 0x8001EEBC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001EEC0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001EEC4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001EEC8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001EECC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001EED0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001EED4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001EED8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001EEDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001EEE0: blez        $t6, L_8001EF9C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001EEE4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001EF9C;
    }
    // 0x8001EEE4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001EEE8: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8001EEEC: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8001EEF0: addiu       $s4, $s4, -0x4C0C
    ctx->r20 = ADD32(ctx->r20, -0X4C0C);
    // 0x8001EEF4: addiu       $fp, $fp, -0x4D5A
    ctx->r30 = ADD32(ctx->r30, -0X4D5A);
    // 0x8001EEF8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001EEFC: addiu       $s6, $zero, 0x14
    ctx->r22 = ADD32(0, 0X14);
    // 0x8001EF00: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
L_8001EF04:
    // 0x8001EF04: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8001EF08: nop

    // 0x8001EF0C: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8001EF10: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x8001EF14: nop

    // 0x8001EF18: lw          $t9, 0x64($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X64);
    // 0x8001EF1C: lw          $s0, 0x3C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X3C);
    // 0x8001EF20: bne         $t9, $zero, L_8001EF50
    if (ctx->r25 != 0) {
        // 0x8001EF24: nop
    
            goto L_8001EF50;
    }
    // 0x8001EF24: nop

    // 0x8001EF28: lb          $t0, 0x11($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X11);
    // 0x8001EF2C: nop

    // 0x8001EF30: bne         $t0, $zero, L_8001EF50
    if (ctx->r8 != 0) {
        // 0x8001EF34: nop
    
            goto L_8001EF50;
    }
    // 0x8001EF34: nop

    // 0x8001EF38: lh          $t1, 0xC($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XC);
    // 0x8001EF3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001EF40: beq         $s5, $t1, L_8001EF50
    if (ctx->r21 == ctx->r9) {
        // 0x8001EF44: nop
    
            goto L_8001EF50;
    }
    // 0x8001EF44: nop

    // 0x8001EF48: jal         0x8001F270
    // 0x8001EF4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001F23C(rdram, ctx);
        goto after_0;
    // 0x8001EF4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
L_8001EF50:
    // 0x8001EF50: lb          $t2, 0x0($fp)
    ctx->r10 = MEM_B(ctx->r30, 0X0);
    // 0x8001EF54: nop

    // 0x8001EF58: bne         $t2, $zero, L_8001EF70
    if (ctx->r10 != 0) {
        // 0x8001EF5C: nop
    
            goto L_8001EF70;
    }
    // 0x8001EF5C: nop

    // 0x8001EF60: lb          $t3, 0x21($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X21);
    // 0x8001EF64: nop

    // 0x8001EF68: beq         $s6, $t3, L_8001EF88
    if (ctx->r22 == ctx->r11) {
        // 0x8001EF6C: nop
    
            goto L_8001EF88;
    }
    // 0x8001EF6C: nop

L_8001EF70:
    // 0x8001EF70: lw          $a1, 0x64($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X64);
    // 0x8001EF74: nop

    // 0x8001EF78: beq         $a1, $zero, L_8001EF88
    if (ctx->r5 == 0) {
        // 0x8001EF7C: nop
    
            goto L_8001EF88;
    }
    // 0x8001EF7C: nop

    // 0x8001EF80: jal         0x8001EFD8
    // 0x8001EF84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_init_animobject(rdram, ctx);
        goto after_1;
    // 0x8001EF84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
L_8001EF88:
    // 0x8001EF88: lh          $t4, 0x0($s7)
    ctx->r12 = MEM_H(ctx->r23, 0X0);
    // 0x8001EF8C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001EF90: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001EF94: bne         $at, $zero, L_8001EF04
    if (ctx->r1 != 0) {
        // 0x8001EF98: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8001EF04;
    }
    // 0x8001EF98: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8001EF9C:
    // 0x8001EF9C: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8001EFA0: addiu       $fp, $fp, -0x4D5A
    ctx->r30 = ADD32(ctx->r30, -0X4D5A);
    // 0x8001EFA4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001EFA8: sb          $zero, 0x0($fp)
    MEM_B(0X0, ctx->r30) = 0;
    // 0x8001EFAC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001EFB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001EFB4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EFB8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001EFBC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001EFC0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001EFC4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EFC8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001EFCC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001EFD0: jr          $ra
    // 0x8001EFD4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001EFD4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_init_animobject(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EFD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001EFDC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001EFE0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001EFE4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001EFE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001EFEC: lw          $s1, 0x3C($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X3C);
    // 0x8001EFF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001EFF4: lbu         $t7, 0xB($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XB);
    // 0x8001EFF8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001EFFC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8001F000: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8001F004: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F008: lw          $s0, 0x64($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X64);
    // 0x8001F00C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001F010: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001F014: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8001F018: bc1f        L_8001F028
    if (!c1cs) {
        // 0x8001F01C: nop
    
            goto L_8001F028;
    }
    // 0x8001F01C: nop

    // 0x8001F020: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001F024: nop

L_8001F028:
    // 0x8001F028: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001F02C: lw          $t8, 0x40($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X40);
    // 0x8001F030: nop

    // 0x8001F034: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8001F038: sw          $zero, 0x78($a1)
    MEM_W(0X78, ctx->r5) = 0;
    // 0x8001F03C: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
    // 0x8001F040: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001F044: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    // 0x8001F048: lb          $v0, 0x22($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X22);
    // 0x8001F04C: nop

    // 0x8001F050: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8001F054: bne         $at, $zero, L_8001F070
    if (ctx->r1 != 0) {
        // 0x8001F058: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8001F070;
    }
    // 0x8001F058: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001F05C: beq         $at, $zero, L_8001F070
    if (ctx->r1 == 0) {
        // 0x8001F060: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8001F070;
    }
    // 0x8001F060: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8001F064: sw          $t9, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r25;
    // 0x8001F068: lb          $v0, 0x22($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X22);
    // 0x8001F06C: nop

L_8001F070:
    // 0x8001F070: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001F074: bne         $at, $zero, L_8001F088
    if (ctx->r1 != 0) {
        // 0x8001F078: slti        $at, $v0, 0x12
        ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
            goto L_8001F088;
    }
    // 0x8001F078: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x8001F07C: beq         $at, $zero, L_8001F088
    if (ctx->r1 == 0) {
        // 0x8001F080: addiu       $t0, $v0, -0x9
        ctx->r8 = ADD32(ctx->r2, -0X9);
            goto L_8001F088;
    }
    // 0x8001F080: addiu       $t0, $v0, -0x9
    ctx->r8 = ADD32(ctx->r2, -0X9);
    // 0x8001F084: sw          $t0, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r8;
L_8001F088:
    // 0x8001F088: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8001F08C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001F090: swc1        $f16, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f16.u32l;
    // 0x8001F094: lwc1        $f18, 0x10($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8001F098: nop

    // 0x8001F09C: swc1        $f18, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f18.u32l;
    // 0x8001F0A0: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8001F0A4: nop

    // 0x8001F0A8: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
    // 0x8001F0AC: lh          $t1, 0x0($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X0);
    // 0x8001F0B0: nop

    // 0x8001F0B4: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x8001F0B8: lh          $t2, 0x4($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X4);
    // 0x8001F0BC: nop

    // 0x8001F0C0: sh          $t2, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r10;
    // 0x8001F0C4: lh          $t3, 0x2($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X2);
    // 0x8001F0C8: nop

    // 0x8001F0CC: sh          $t3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r11;
    // 0x8001F0D0: sh          $zero, 0x26($s0)
    MEM_H(0X26, ctx->r16) = 0;
    // 0x8001F0D4: lb          $t4, 0x21($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X21);
    // 0x8001F0D8: nop

    // 0x8001F0DC: sb          $t4, 0x3D($s0)
    MEM_B(0X3D, ctx->r16) = ctx->r12;
    // 0x8001F0E0: lb          $t5, 0x10($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X10);
    // 0x8001F0E4: nop

    // 0x8001F0E8: sh          $t5, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r13;
    // 0x8001F0EC: lb          $t6, 0x14($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X14);
    // 0x8001F0F0: lwc1        $f16, 0x5BFC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5BFC);
    // 0x8001F0F4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8001F0F8: lwc1        $f17, 0x5BF8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X5BF8);
    // 0x8001F0FC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F100: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8001F104: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8001F108: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8001F10C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8001F110: lh          $a0, 0xE($s1)
    ctx->r4 = MEM_H(ctx->r17, 0XE);
    // 0x8001F114: jal         0x8000C8B4
    // 0x8001F118: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    normalise_time(rdram, ctx);
        goto after_0;
    // 0x8001F118: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001F11C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F120: sh          $v0, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r2;
    // 0x8001F124: lb          $t7, 0x12($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X12);
    // 0x8001F128: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001F12C: sb          $t7, 0x3B($a1)
    MEM_B(0X3B, ctx->r5) = ctx->r15;
    // 0x8001F130: lbu         $t8, 0x16($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X16);
    // 0x8001F134: nop

    // 0x8001F138: sh          $t8, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r24;
    // 0x8001F13C: lb          $t9, 0x17($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X17);
    // 0x8001F140: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8001F144: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8001F148: nop

    // 0x8001F14C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F150: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8001F154: lbu         $t0, 0x18($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X18);
    // 0x8001F158: nop

    // 0x8001F15C: sb          $t0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r8;
    // 0x8001F160: lbu         $t1, 0x19($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X19);
    // 0x8001F164: nop

    // 0x8001F168: sb          $t1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r9;
    // 0x8001F16C: lb          $t2, 0x2C($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X2C);
    // 0x8001F170: nop

    // 0x8001F174: sb          $t2, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r10;
    // 0x8001F178: lb          $t3, 0x2D($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X2D);
    // 0x8001F17C: nop

    // 0x8001F180: sb          $t3, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = ctx->r11;
    // 0x8001F184: lb          $t4, 0x1A($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X1A);
    // 0x8001F188: nop

    // 0x8001F18C: sb          $t4, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r12;
    // 0x8001F190: lb          $t5, 0x1B($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X1B);
    // 0x8001F194: nop

    // 0x8001F198: sb          $t5, 0x32($s0)
    MEM_B(0X32, ctx->r16) = ctx->r13;
    // 0x8001F19C: lb          $t6, 0x1C($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1C);
    // 0x8001F1A0: nop

    // 0x8001F1A4: sb          $t6, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r14;
    // 0x8001F1A8: lb          $t7, 0x20($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X20);
    // 0x8001F1AC: sb          $zero, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = 0;
    // 0x8001F1B0: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8001F1B4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8001F1B8: sb          $t7, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r15;
    // 0x8001F1BC: sw          $zero, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = 0;
    // 0x8001F1C0: lh          $a0, 0x24($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X24);
    // 0x8001F1C4: jal         0x8000C8B4
    // 0x8001F1C8: nop

    normalise_time(rdram, ctx);
        goto after_1;
    // 0x8001F1C8: nop

    after_1:
    // 0x8001F1CC: sh          $v0, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r2;
    // 0x8001F1D0: lb          $t8, 0x26($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X26);
    // 0x8001F1D4: nop

    // 0x8001F1D8: sb          $t8, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r24;
    // 0x8001F1DC: lb          $v1, 0x13($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X13);
    // 0x8001F1E0: nop

    // 0x8001F1E4: bltz        $v1, L_8001F1F0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8001F1E8: nop
    
            goto L_8001F1F0;
    }
    // 0x8001F1E8: nop

    // 0x8001F1EC: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
L_8001F1F0:
    // 0x8001F1F0: lb          $t9, 0x1F($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1F);
    // 0x8001F1F4: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x8001F1F8: sb          $t9, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r25;
    // 0x8001F1FC: lbu         $t0, 0x1E($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1E);
    // 0x8001F200: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8001F204: sb          $t0, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r8;
    // 0x8001F208: lb          $t1, 0x29($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X29);
    // 0x8001F20C: nop

    // 0x8001F210: sb          $t1, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r9;
    // 0x8001F214: lb          $t2, 0x2E($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X2E);
    // 0x8001F218: nop

    // 0x8001F21C: sb          $t2, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r10;
    // 0x8001F220: lb          $t3, 0x2F($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X2F);
    // 0x8001F224: nop

    // 0x8001F228: sb          $t3, 0x41($s0)
    MEM_B(0X41, ctx->r16) = ctx->r11;
    // 0x8001F22C: lb          $t4, 0x2B($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X2B);
    // 0x8001F230: sb          $t5, 0x42($s0)
    MEM_B(0X42, ctx->r16) = ctx->r13;
    // 0x8001F234: beq         $a0, $zero, L_8001F244
    if (ctx->r4 == 0) {
        // 0x8001F238: sb          $t4, 0x3C($s0)
        MEM_B(0X3C, ctx->r16) = ctx->r12;
            goto L_8001F244;
    }
    // 0x8001F238: sb          $t4, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r12;
    // 0x8001F23C: jal         0x8000488C
    // 0x8001F240: nop

    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x8001F240: nop

    after_2:
L_8001F244:
    // 0x8001F244: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8001F248: lb          $t6, 0x30($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X30);
    // 0x8001F24C: sw          $s2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r18;
    // 0x8001F250: sb          $zero, 0x45($s0)
    MEM_B(0X45, ctx->r16) = 0;
    // 0x8001F254: sb          $t6, 0x43($s0)
    MEM_B(0X43, ctx->r16) = ctx->r14;
    // 0x8001F258: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001F25C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001F260: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001F268: jr          $ra
    // 0x8001F26C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001F26C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001F23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F270: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001F274: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001F278: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001F27C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001F280: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001F284: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001F288: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001F28C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001F290: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x8001F294: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8001F298: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x8001F29C: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x8001F2A0: addiu       $s5, $sp, 0x3C
    ctx->r21 = ADD32(ctx->r29, 0X3C);
    // 0x8001F2A4: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x8001F2A8: lh          $t8, 0x6($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X6);
    // 0x8001F2AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001F2B0: sh          $t8, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r24;
    // 0x8001F2B4: lh          $t9, 0xC($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XC);
    // 0x8001F2B8: nop

    // 0x8001F2BC: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8001F2C0: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x8001F2C4: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x8001F2C8: sb          $t2, 0x3D($sp)
    MEM_B(0X3D, ctx->r29) = ctx->r10;
    // 0x8001F2CC: lh          $t3, 0xC($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XC);
    // 0x8001F2D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001F2D4: jal         0x8000EA54
    // 0x8001F2D8: sb          $t3, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r11;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x8001F2D8: sb          $t3, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r11;
    after_0:
    // 0x8001F2DC: sw          $v0, 0x64($s4)
    MEM_W(0X64, ctx->r20) = ctx->r2;
    // 0x8001F2E0: beq         $v0, $zero, L_8001F318
    if (ctx->r2 == 0) {
        // 0x8001F2E4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8001F318;
    }
    // 0x8001F2E4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8001F2E8: lh          $t4, 0x48($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X48);
    // 0x8001F2EC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8001F2F0: bne         $t4, $at, L_8001F318
    if (ctx->r12 != ctx->r1) {
        // 0x8001F2F4: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8001F318;
    }
    // 0x8001F2F4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001F2F8: lbu         $t5, -0x4B8C($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4B8C);
    // 0x8001F2FC: nop

    // 0x8001F300: beq         $t5, $zero, L_8001F318
    if (ctx->r13 == 0) {
        // 0x8001F304: nop
    
            goto L_8001F318;
    }
    // 0x8001F304: nop

    // 0x8001F308: jal         0x8000FFB8
    // 0x8001F30C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_object(rdram, ctx);
        goto after_1;
    // 0x8001F30C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8001F310: sw          $zero, 0x64($s4)
    MEM_W(0X64, ctx->r20) = 0;
    // 0x8001F314: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001F318:
    // 0x8001F318: beq         $s1, $zero, L_8001F3C8
    if (ctx->r17 == 0) {
        // 0x8001F31C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8001F3C8;
    }
    // 0x8001F31C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F320: sw          $zero, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = 0;
    // 0x8001F324: jal         0x8001EFD8
    // 0x8001F328: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    obj_init_animobject(rdram, ctx);
        goto after_2;
    // 0x8001F328: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8001F32C: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8001F330: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x8001F334: lb          $t7, 0x54($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X54);
    // 0x8001F338: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8001F33C: bne         $t7, $at, L_8001F3C8
    if (ctx->r15 != ctx->r1) {
        // 0x8001F340: addiu       $s3, $s3, -0x4D42
        ctx->r19 = ADD32(ctx->r19, -0X4D42);
            goto L_8001F3C8;
    }
    // 0x8001F340: addiu       $s3, $s3, -0x4D42
    ctx->r19 = ADD32(ctx->r19, -0X4D42);
    // 0x8001F344: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x8001F348: lb          $t8, 0x0($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X0);
    // 0x8001F34C: jal         0x80066450
    // 0x8001F350: sb          $t8, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r24;
    cam_get_viewport_layout(rdram, ctx);
        goto after_3;
    // 0x8001F350: sb          $t8, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r24;
    after_3:
    // 0x8001F354: jal         0x8006C3DC
    // 0x8001F358: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    race_is_adventure_2P(rdram, ctx);
        goto after_4;
    // 0x8001F358: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_4:
    // 0x8001F35C: beq         $v0, $zero, L_8001F368
    if (ctx->r2 == 0) {
        // 0x8001F360: nop
    
            goto L_8001F368;
    }
    // 0x8001F360: nop

    // 0x8001F364: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8001F368:
    // 0x8001F368: blez        $s2, L_8001F3B8
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8001F36C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001F3B8;
    }
    // 0x8001F36C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001F370: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8001F374:
    // 0x8001F374: jal         0x8000EA54
    // 0x8001F378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_5;
    // 0x8001F378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8001F37C: beq         $v0, $zero, L_8001F3AC
    if (ctx->r2 == 0) {
        // 0x8001F380: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8001F3AC;
    }
    // 0x8001F380: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8001F384: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8001F388: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F38C: jal         0x8001EFD8
    // 0x8001F390: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    obj_init_animobject(rdram, ctx);
        goto after_6;
    // 0x8001F390: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8001F394: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x8001F398: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001F39C: sb          $s0, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r16;
    // 0x8001F3A0: lb          $t9, 0x0($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X0);
    // 0x8001F3A4: nop

    // 0x8001F3A8: sb          $t9, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r25;
L_8001F3AC:
    // 0x8001F3AC: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8001F3B0: bne         $at, $zero, L_8001F374
    if (ctx->r1 != 0) {
        // 0x8001F3B4: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8001F374;
    }
    // 0x8001F3B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8001F3B8:
    // 0x8001F3B8: lb          $t0, 0x0($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X0);
    // 0x8001F3BC: nop

    // 0x8001F3C0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8001F3C4: sb          $t1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r9;
L_8001F3C8:
    // 0x8001F3C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F3CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001F3D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001F3D4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F3D8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001F3DC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001F3E0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8001F3E4: jr          $ra
    // 0x8001F3E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8001F3E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8001F3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F3EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001F3F0: lb          $v0, -0x4CAC($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4CAC);
    // 0x8001F3F4: jr          $ra
    // 0x8001F3F8: nop

    return;
    // 0x8001F3F8: nop

;}
RECOMP_FUNC void func_8001F3C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F3FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001F400: addiu       $v0, $v0, -0x4CAC
    ctx->r2 = ADD32(ctx->r2, -0X4CAC);
    // 0x8001F404: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8001F408: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001F40C: beq         $a0, $t6, L_8001F418
    if (ctx->r4 == ctx->r14) {
        // 0x8001F410: nop
    
            goto L_8001F418;
    }
    // 0x8001F410: nop

    // 0x8001F414: sh          $zero, -0x4C08($at)
    MEM_H(-0X4C08, ctx->r1) = 0;
L_8001F418:
    // 0x8001F418: jr          $ra
    // 0x8001F41C: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x8001F41C: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_8001F3EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F420: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001F424: lh          $v0, -0x4C08($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4C08);
    // 0x8001F428: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001F42C: bne         $v0, $zero, L_8001F43C
    if (ctx->r2 != 0) {
        // 0x8001F430: nop
    
            goto L_8001F43C;
    }
    // 0x8001F430: nop

    // 0x8001F434: jr          $ra
    // 0x8001F438: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8001F438: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001F43C:
    // 0x8001F43C: blez        $v0, L_8001F478
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F440: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001F478;
    }
    // 0x8001F440: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001F444: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001F448: lw          $a2, -0x4C0C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C0C);
    // 0x8001F44C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F450: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
L_8001F454:
    // 0x8001F454: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8001F458: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001F45C: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x8001F460: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001F464: bne         $a1, $t7, L_8001F470
    if (ctx->r5 != ctx->r15) {
        // 0x8001F468: nop
    
            goto L_8001F470;
    }
    // 0x8001F468: nop

    // 0x8001F46C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001F470:
    // 0x8001F470: bne         $at, $zero, L_8001F454
    if (ctx->r1 != 0) {
        // 0x8001F474: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8001F454;
    }
    // 0x8001F474: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8001F478:
    // 0x8001F478: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001F47C: jr          $ra
    // 0x8001F480: nop

    return;
    // 0x8001F480: nop

;}
RECOMP_FUNC void func_8001F450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F484: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001F488: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001F48C: jr          $ra
    // 0x8001F490: sb          $t6, -0x4D2D($at)
    MEM_B(-0X4D2D, ctx->r1) = ctx->r14;
    return;
    // 0x8001F490: sb          $t6, -0x4D2D($at)
    MEM_B(-0X4D2D, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8001F460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F494: addiu       $sp, $sp, -0x198
    ctx->r29 = ADD32(ctx->r29, -0X198);
    // 0x8001F498: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001F49C: lh          $t6, -0x4C06($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4C06);
    // 0x8001F4A0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8001F4A4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8001F4A8: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8001F4AC: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8001F4B0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8001F4B4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8001F4B8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8001F4BC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8001F4C0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8001F4C4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001F4C8: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8001F4CC: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x8001F4D0: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001F4D4: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8001F4D8: bgez        $t6, L_8001F4E8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001F4DC: sw          $a1, 0x19C($sp)
        MEM_W(0X19C, ctx->r29) = ctx->r5;
            goto L_8001F4E8;
    }
    // 0x8001F4DC: sw          $a1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r5;
    // 0x8001F4E0: b           L_800210C8
    // 0x8001F4E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800210C8;
    // 0x8001F4E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001F4E8:
    // 0x8001F4E8: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F4EC: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8001F4F0: slti        $at, $t7, 0x9
    ctx->r1 = SIGNED(ctx->r15) < 0X9 ? 1 : 0;
    // 0x8001F4F4: bne         $at, $zero, L_8001F500
    if (ctx->r1 != 0) {
        // 0x8001F4F8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8001F500;
    }
    // 0x8001F4F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001F4FC: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
L_8001F500:
    // 0x8001F500: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F504: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8001F508: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8001F50C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8001F510: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F514: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001F518: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001F51C: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    // 0x8001F520: lw          $s3, 0x64($s6)
    ctx->r19 = MEM_W(ctx->r22, 0X64);
    // 0x8001F524: bne         $t6, $zero, L_8001F544
    if (ctx->r14 != 0) {
        // 0x8001F528: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_8001F544;
    }
    // 0x8001F528: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8001F52C: lwc1        $f9, 0x5C00($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5C00);
    // 0x8001F530: lwc1        $f8, 0x5C04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5C04);
    // 0x8001F534: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8001F538: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8001F53C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8001F540: swc1        $f4, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f4.u32l;
L_8001F544:
    // 0x8001F544: lh          $t7, 0x2A($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X2A);
    // 0x8001F548: nop

    // 0x8001F54C: bgez        $t7, L_8001F5B4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8001F550: nop
    
            goto L_8001F5B4;
    }
    // 0x8001F550: nop

    // 0x8001F554: lbu         $v0, 0x34($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X34);
    // 0x8001F558: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001F55C: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x8001F560: beq         $t8, $zero, L_8001F56C
    if (ctx->r24 == 0) {
        // 0x8001F564: andi        $t9, $v0, 0x2
        ctx->r25 = ctx->r2 & 0X2;
            goto L_8001F56C;
    }
    // 0x8001F564: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x8001F568: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
L_8001F56C:
    // 0x8001F56C: beq         $t9, $zero, L_8001F57C
    if (ctx->r25 == 0) {
        // 0x8001F570: andi        $t7, $v0, 0x4
        ctx->r15 = ctx->r2 & 0X4;
            goto L_8001F57C;
    }
    // 0x8001F570: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x8001F574: ori         $t6, $t0, 0x4000
    ctx->r14 = ctx->r8 | 0X4000;
    // 0x8001F578: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
L_8001F57C:
    // 0x8001F57C: beq         $t7, $zero, L_8001F588
    if (ctx->r15 == 0) {
        // 0x8001F580: ori         $t8, $t0, 0x1000
        ctx->r24 = ctx->r8 | 0X1000;
            goto L_8001F588;
    }
    // 0x8001F580: ori         $t8, $t0, 0x1000
    ctx->r24 = ctx->r8 | 0X1000;
    // 0x8001F584: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_8001F588:
    // 0x8001F588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001F58C: jal         0x8006A794
    // 0x8001F590: sw          $t0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8001F590: sw          $t0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r8;
    after_0:
    // 0x8001F594: lw          $t0, 0x174($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X174);
    // 0x8001F598: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001F59C: bne         $s0, $s1, L_8001F588
    if (ctx->r16 != ctx->r17) {
        // 0x8001F5A0: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_8001F588;
    }
    // 0x8001F5A0: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x8001F5A4: and         $t9, $s2, $t0
    ctx->r25 = ctx->r18 & ctx->r8;
    // 0x8001F5A8: beq         $t9, $zero, L_8001F5B4
    if (ctx->r25 == 0) {
        // 0x8001F5AC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8001F5B4;
    }
    // 0x8001F5AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001F5B0: sh          $t6, 0x2A($s3)
    MEM_H(0X2A, ctx->r19) = ctx->r14;
L_8001F5B4:
    // 0x8001F5B4: lh          $v0, 0x2A($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2A);
    // 0x8001F5B8: nop

    // 0x8001F5BC: bltz        $v0, L_8001F620
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001F5C0: nop
    
            goto L_8001F620;
    }
    // 0x8001F5C0: nop

    // 0x8001F5C4: lb          $t7, 0x45($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X45);
    // 0x8001F5C8: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F5CC: bne         $t7, $zero, L_8001F620
    if (ctx->r15 != 0) {
        // 0x8001F5D0: subu        $t9, $v0, $t8
        ctx->r25 = SUB32(ctx->r2, ctx->r24);
            goto L_8001F620;
    }
    // 0x8001F5D0: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x8001F5D4: sh          $t9, 0x2A($s3)
    MEM_H(0X2A, ctx->r19) = ctx->r25;
    // 0x8001F5D8: lh          $v0, 0x2A($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2A);
    // 0x8001F5DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001F5E0: bgtz        $v0, L_8001F620
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001F5E4: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_8001F620;
    }
    // 0x8001F5E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001F5E8: lw          $t7, 0x1C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X1C);
    // 0x8001F5EC: sb          $t6, 0x45($s3)
    MEM_B(0X45, ctx->r19) = ctx->r14;
    // 0x8001F5F0: lw          $s1, 0x3C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X3C);
    // 0x8001F5F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8001F5F8: jal         0x80021138
    // 0x8001F5FC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80021104(rdram, ctx);
        goto after_1;
    // 0x8001F5FC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x8001F600: sh          $zero, 0x2A($s3)
    MEM_H(0X2A, ctx->r19) = 0;
    // 0x8001F604: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001F608: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001F60C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8001F610: jal         0x80021290
    // 0x8001F614: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    func_8002125C(rdram, ctx);
        goto after_2;
    // 0x8001F614: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_2:
    // 0x8001F618: lh          $v0, 0x2A($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2A);
    // 0x8001F61C: nop

L_8001F620:
    // 0x8001F620: beq         $v0, $zero, L_8001F658
    if (ctx->r2 == 0) {
        // 0x8001F624: nop
    
            goto L_8001F658;
    }
    // 0x8001F624: nop

    // 0x8001F628: lb          $t8, 0x3A($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X3A);
    // 0x8001F62C: nop

    // 0x8001F630: beq         $t8, $zero, L_8001F650
    if (ctx->r24 == 0) {
        // 0x8001F634: nop
    
            goto L_8001F650;
    }
    // 0x8001F634: nop

    // 0x8001F638: lh          $t9, 0x6($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X6);
    // 0x8001F63C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001F640: ori         $t6, $t9, 0x4000
    ctx->r14 = ctx->r25 | 0X4000;
    // 0x8001F644: sh          $t6, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r14;
    // 0x8001F648: b           L_800210C8
    // 0x8001F64C: sb          $zero, 0x42($s3)
    MEM_B(0X42, ctx->r19) = 0;
        goto L_800210C8;
    // 0x8001F64C: sb          $zero, 0x42($s3)
    MEM_B(0X42, ctx->r19) = 0;
L_8001F650:
    // 0x8001F650: b           L_800210C8
    // 0x8001F654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800210C8;
    // 0x8001F654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001F658:
    // 0x8001F658: lh          $t7, 0x6($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X6);
    // 0x8001F65C: addiu       $s0, $zero, -0x4001
    ctx->r16 = ADD32(0, -0X4001);
    // 0x8001F660: andi        $t8, $t7, 0xBFFF
    ctx->r24 = ctx->r15 & 0XBFFF;
    // 0x8001F664: sh          $t8, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r24;
    // 0x8001F668: lb          $v1, 0x39($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X39);
    // 0x8001F66C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8001F670: blez        $v1, L_8001F6B4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001F674: nop
    
            goto L_8001F6B4;
    }
    // 0x8001F674: nop

    // 0x8001F678: jal         0x80001918
    // 0x8001F67C: nop

    music_current_sequence(rdram, ctx);
        goto after_3;
    // 0x8001F67C: nop

    after_3:
    // 0x8001F680: lb          $v1, 0x39($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X39);
    // 0x8001F684: nop

    // 0x8001F688: beq         $v1, $v0, L_8001F6A4
    if (ctx->r3 == ctx->r2) {
        // 0x8001F68C: addiu       $t9, $zero, -0x2
        ctx->r25 = ADD32(0, -0X2);
            goto L_8001F6A4;
    }
    // 0x8001F68C: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
    // 0x8001F690: jal         0x80000B34
    // 0x8001F694: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    music_play(rdram, ctx);
        goto after_4;
    // 0x8001F694: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    after_4:
    // 0x8001F698: jal         0x80000B18
    // 0x8001F69C: nop

    music_change_off(rdram, ctx);
        goto after_5;
    // 0x8001F69C: nop

    after_5:
    // 0x8001F6A0: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
L_8001F6A4:
    // 0x8001F6A4: jal         0x80000CBC
    // 0x8001F6A8: sb          $t9, 0x39($s3)
    MEM_B(0X39, ctx->r19) = ctx->r25;
    music_volume_reset(rdram, ctx);
        goto after_6;
    // 0x8001F6A8: sb          $t9, 0x39($s3)
    MEM_B(0X39, ctx->r19) = ctx->r25;
    after_6:
    // 0x8001F6AC: b           L_8001F6D0
    // 0x8001F6B0: lb          $v1, 0x38($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X38);
        goto L_8001F6D0;
    // 0x8001F6B0: lb          $v1, 0x38($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X38);
L_8001F6B4:
    // 0x8001F6B4: bne         $v1, $at, L_8001F6CC
    if (ctx->r3 != ctx->r1) {
        // 0x8001F6B8: nop
    
            goto L_8001F6CC;
    }
    // 0x8001F6B8: nop

    // 0x8001F6BC: jal         0x80000B28
    // 0x8001F6C0: nop

    music_change_on(rdram, ctx);
        goto after_7;
    // 0x8001F6C0: nop

    after_7:
    // 0x8001F6C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8001F6C8: sb          $t6, 0x39($s3)
    MEM_B(0X39, ctx->r19) = ctx->r14;
L_8001F6CC:
    // 0x8001F6CC: lb          $v1, 0x38($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X38);
L_8001F6D0:
    // 0x8001F6D0: nop

    // 0x8001F6D4: beq         $v1, $zero, L_8001F74C
    if (ctx->r3 == 0) {
        // 0x8001F6D8: nop
    
            goto L_8001F74C;
    }
    // 0x8001F6D8: nop

    // 0x8001F6DC: lh          $t7, 0x24($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X24);
    // 0x8001F6E0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8001F6E4: bne         $t7, $zero, L_8001F74C
    if (ctx->r15 != 0) {
        // 0x8001F6E8: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8001F74C;
    }
    // 0x8001F6E8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8001F6EC: bne         $v0, $at, L_8001F714
    if (ctx->r2 != ctx->r1) {
        // 0x8001F6F0: nop
    
            goto L_8001F714;
    }
    // 0x8001F6F0: nop

    // 0x8001F6F4: lw          $a0, 0x18($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X18);
    // 0x8001F6F8: nop

    // 0x8001F6FC: beq         $a0, $zero, L_8001F748
    if (ctx->r4 == 0) {
        // 0x8001F700: nop
    
            goto L_8001F748;
    }
    // 0x8001F700: nop

    // 0x8001F704: jal         0x8000488C
    // 0x8001F708: nop

    sndp_stop(rdram, ctx);
        goto after_8;
    // 0x8001F708: nop

    after_8:
    // 0x8001F70C: b           L_8001F74C
    // 0x8001F710: sb          $zero, 0x38($s3)
    MEM_B(0X38, ctx->r19) = 0;
        goto L_8001F74C;
    // 0x8001F710: sb          $zero, 0x38($s3)
    MEM_B(0X38, ctx->r19) = 0;
L_8001F714:
    // 0x8001F714: lw          $a0, 0x18($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X18);
    // 0x8001F718: nop

    // 0x8001F71C: beq         $a0, $zero, L_8001F73C
    if (ctx->r4 == 0) {
        // 0x8001F720: nop
    
            goto L_8001F73C;
    }
    // 0x8001F720: nop

    // 0x8001F724: jal         0x8000488C
    // 0x8001F728: nop

    sndp_stop(rdram, ctx);
        goto after_9;
    // 0x8001F728: nop

    after_9:
    // 0x8001F72C: lb          $v0, 0x38($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X38);
    // 0x8001F730: nop

    // 0x8001F734: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8001F738: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8001F73C:
    // 0x8001F73C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8001F740: jal         0x80001D04
    // 0x8001F744: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8001F744: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    after_10:
L_8001F748:
    // 0x8001F748: sb          $zero, 0x38($s3)
    MEM_B(0X38, ctx->r19) = 0;
L_8001F74C:
    // 0x8001F74C: lb          $v0, 0x43($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X43);
    // 0x8001F750: nop

    // 0x8001F754: beq         $v0, $zero, L_8001F768
    if (ctx->r2 == 0) {
        // 0x8001F758: nop
    
            goto L_8001F768;
    }
    // 0x8001F758: nop

    // 0x8001F75C: jal         0x80000C98
    // 0x8001F760: sll         $a0, $v0, 8
    ctx->r4 = S32(ctx->r2 << 8);
    music_fade(rdram, ctx);
        goto after_11;
    // 0x8001F760: sll         $a0, $v0, 8
    ctx->r4 = S32(ctx->r2 << 8);
    after_11:
    // 0x8001F764: sb          $zero, 0x43($s3)
    MEM_B(0X43, ctx->r19) = 0;
L_8001F768:
    // 0x8001F768: lb          $v0, 0x41($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X41);
    // 0x8001F76C: lbu         $t0, 0x42($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X42);
    // 0x8001F770: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8001F774: beq         $t9, $zero, L_8001F7B8
    if (ctx->r25 == 0) {
        // 0x8001F778: andi        $t6, $v0, 0x2
        ctx->r14 = ctx->r2 & 0X2;
            goto L_8001F7B8;
    }
    // 0x8001F778: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8001F77C: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8001F780: lw          $v0, 0x19C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F784: beq         $t6, $zero, L_8001F790
    if (ctx->r14 == 0) {
        // 0x8001F788: sll         $t7, $v0, 3
        ctx->r15 = S32(ctx->r2 << 3);
            goto L_8001F790;
    }
    // 0x8001F788: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x8001F78C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8001F790:
    // 0x8001F790: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001F794: beq         $at, $zero, L_8001F7A4
    if (ctx->r1 == 0) {
        // 0x8001F798: nop
    
            goto L_8001F7A4;
    }
    // 0x8001F798: nop

    // 0x8001F79C: b           L_8001F7EC
    // 0x8001F7A0: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
        goto L_8001F7EC;
    // 0x8001F7A0: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
L_8001F7A4:
    // 0x8001F7A4: lh          $t8, 0x6($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X6);
    // 0x8001F7A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001F7AC: ori         $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 | 0X4000;
    // 0x8001F7B0: b           L_8001F7EC
    // 0x8001F7B4: sh          $t9, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r25;
        goto L_8001F7EC;
    // 0x8001F7B4: sh          $t9, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r25;
L_8001F7B8:
    // 0x8001F7B8: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F7BC: beq         $t6, $zero, L_8001F7C8
    if (ctx->r14 == 0) {
        // 0x8001F7C0: sll         $t8, $t7, 3
        ctx->r24 = S32(ctx->r15 << 3);
            goto L_8001F7C8;
    }
    // 0x8001F7C0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8001F7C4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_8001F7C8:
    // 0x8001F7C8: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8001F7CC: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x8001F7D0: bne         $at, $zero, L_8001F7DC
    if (ctx->r1 != 0) {
        // 0x8001F7D4: nop
    
            goto L_8001F7DC;
    }
    // 0x8001F7D4: nop

    // 0x8001F7D8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_8001F7DC:
    // 0x8001F7DC: lh          $t9, 0x6($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X6);
    // 0x8001F7E0: nop

    // 0x8001F7E4: and         $t6, $t9, $s0
    ctx->r14 = ctx->r25 & ctx->r16;
    // 0x8001F7E8: sh          $t6, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r14;
L_8001F7EC:
    // 0x8001F7EC: lbu         $v0, 0x3B($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X3B);
    // 0x8001F7F0: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x8001F7F4: andi        $s2, $v0, 0x7F
    ctx->r18 = ctx->r2 & 0X7F;
    // 0x8001F7F8: beq         $s2, $at, L_8001F9BC
    if (ctx->r18 == ctx->r1) {
        // 0x8001F7FC: sb          $t0, 0x42($s3)
        MEM_B(0X42, ctx->r19) = ctx->r8;
            goto L_8001F9BC;
    }
    // 0x8001F7FC: sb          $t0, 0x42($s3)
    MEM_B(0X42, ctx->r19) = ctx->r8;
    // 0x8001F800: slti        $at, $s2, 0x8
    ctx->r1 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // 0x8001F804: bne         $at, $zero, L_8001F8A0
    if (ctx->r1 != 0) {
        // 0x8001F808: slti        $at, $s2, 0x6
        ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
            goto L_8001F8A0;
    }
    // 0x8001F808: slti        $at, $s2, 0x6
    ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
    // 0x8001F80C: jal         0x8001E2D0
    // 0x8001F810: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    get_misc_asset(rdram, ctx);
        goto after_12;
    // 0x8001F810: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_12:
    // 0x8001F814: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8001F818: addu        $t7, $t7, $s2
    ctx->r15 = ADD32(ctx->r15, ctx->r18);
    // 0x8001F81C: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x8001F820: addiu       $s1, $v1, -0x28
    ctx->r17 = ADD32(ctx->r3, -0X28);
    // 0x8001F824: lb          $t0, 0x0($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X0);
    // 0x8001F828: lb          $s0, 0x1($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X1);
    // 0x8001F82C: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x8001F830: addiu       $t0, $t8, 0x384
    ctx->r8 = ADD32(ctx->r24, 0X384);
    // 0x8001F834: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x8001F838: addiu       $s0, $t9, 0x384
    ctx->r16 = ADD32(ctx->r25, 0X384);
    // 0x8001F83C: sw          $t0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r8;
    // 0x8001F840: jal         0x8000C8B4
    // 0x8001F844: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    normalise_time(rdram, ctx);
        goto after_13;
    // 0x8001F844: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_13:
    // 0x8001F848: lw          $t0, 0x174($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X174);
    // 0x8001F84C: lb          $a1, 0x2($s1)
    ctx->r5 = MEM_B(ctx->r17, 0X2);
    // 0x8001F850: lb          $a2, 0x3($s1)
    ctx->r6 = MEM_B(ctx->r17, 0X3);
    // 0x8001F854: lb          $a3, 0x4($s1)
    ctx->r7 = MEM_B(ctx->r17, 0X4);
    // 0x8001F858: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001F85C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8001F860: lbu         $t9, 0x3C($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X3C);
    // 0x8001F864: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8001F868: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F86C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8001F870: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8001F874: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x8001F878: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8001F87C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8001F880: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F884: mflo        $t6
    ctx->r14 = lo;
    // 0x8001F888: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8001F88C: jal         0x80030E20
    // 0x8001F890: nop

    slowly_change_fog(rdram, ctx);
        goto after_14;
    // 0x8001F890: nop

    after_14:
    // 0x8001F894: b           L_8001F9B8
    // 0x8001F898: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
        goto L_8001F9B8;
    // 0x8001F898: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8001F89C: slti        $at, $s2, 0x6
    ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
L_8001F8A0:
    // 0x8001F8A0: bne         $at, $zero, L_8001F90C
    if (ctx->r1 != 0) {
        // 0x8001F8A4: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8001F90C;
    }
    // 0x8001F8A4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8001F8A8: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x8001F8AC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8001F8B0: bne         $s2, $at, L_8001F8D4
    if (ctx->r18 != ctx->r1) {
        // 0x8001F8B4: sb          $t7, 0xA4($sp)
        MEM_B(0XA4, ctx->r29) = ctx->r15;
            goto L_8001F8D4;
    }
    // 0x8001F8B4: sb          $t7, 0xA4($sp)
    MEM_B(0XA4, ctx->r29) = ctx->r15;
    // 0x8001F8B8: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x8001F8BC: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x8001F8C0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8001F8C4: sb          $t6, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r14;
    // 0x8001F8C8: sb          $t9, 0xA6($sp)
    MEM_B(0XA6, ctx->r29) = ctx->r25;
    // 0x8001F8CC: b           L_8001F8EC
    // 0x8001F8D0: sb          $t8, 0xA5($sp)
    MEM_B(0XA5, ctx->r29) = ctx->r24;
        goto L_8001F8EC;
    // 0x8001F8D0: sb          $t8, 0xA5($sp)
    MEM_B(0XA5, ctx->r29) = ctx->r24;
L_8001F8D4:
    // 0x8001F8D4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8001F8D8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8001F8DC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8001F8E0: sb          $t9, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r25;
    // 0x8001F8E4: sb          $t8, 0xA6($sp)
    MEM_B(0XA6, ctx->r29) = ctx->r24;
    // 0x8001F8E8: sb          $t7, 0xA5($sp)
    MEM_B(0XA5, ctx->r29) = ctx->r15;
L_8001F8EC:
    // 0x8001F8EC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8001F8F0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8001F8F4: sh          $t6, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r14;
    // 0x8001F8F8: sh          $t7, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = ctx->r15;
    // 0x8001F8FC: jal         0x800C06F8
    // 0x8001F900: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    transition_begin(rdram, ctx);
        goto after_15;
    // 0x8001F900: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    after_15:
    // 0x8001F904: b           L_8001F9B8
    // 0x8001F908: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
        goto L_8001F9B8;
    // 0x8001F908: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
L_8001F90C:
    // 0x8001F90C: jal         0x8001E2D0
    // 0x8001F910: sb          $v0, 0xA4($sp)
    MEM_B(0XA4, ctx->r29) = ctx->r2;
    get_misc_asset(rdram, ctx);
        goto after_16;
    // 0x8001F910: sb          $v0, 0xA4($sp)
    MEM_B(0XA4, ctx->r29) = ctx->r2;
    after_16:
    // 0x8001F914: lb          $t8, 0x40($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X40);
    // 0x8001F918: nop

    // 0x8001F91C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001F920: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001F924: addu        $s1, $v0, $t9
    ctx->r17 = ADD32(ctx->r2, ctx->r25);
    // 0x8001F928: lb          $t6, 0x0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X0);
    // 0x8001F92C: nop

    // 0x8001F930: sb          $t6, 0xA5($sp)
    MEM_B(0XA5, ctx->r29) = ctx->r14;
    // 0x8001F934: lb          $t7, 0x1($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1);
    // 0x8001F938: nop

    // 0x8001F93C: sb          $t7, 0xA6($sp)
    MEM_B(0XA6, ctx->r29) = ctx->r15;
    // 0x8001F940: lb          $t8, 0x2($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X2);
    // 0x8001F944: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x8001F948: sb          $t8, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r24;
    // 0x8001F94C: lbu         $t9, 0x3B($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X3B);
    // 0x8001F950: nop

    // 0x8001F954: andi        $t6, $t9, 0x80
    ctx->r14 = ctx->r25 & 0X80;
    // 0x8001F958: beq         $t6, $zero, L_8001F968
    if (ctx->r14 == 0) {
        // 0x8001F95C: nop
    
            goto L_8001F968;
    }
    // 0x8001F95C: nop

    // 0x8001F960: b           L_8001F96C
    // 0x8001F964: sh          $zero, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = 0;
        goto L_8001F96C;
    // 0x8001F964: sh          $zero, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = 0;
L_8001F968:
    // 0x8001F968: sh          $t7, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = ctx->r15;
L_8001F96C:
    // 0x8001F96C: jal         0x8000C8B4
    // 0x8001F970: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    normalise_time(rdram, ctx);
        goto after_17;
    // 0x8001F970: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_17:
    // 0x8001F974: lbu         $t8, 0x3C($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3C);
    // 0x8001F978: nop

    // 0x8001F97C: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F980: mflo        $t9
    ctx->r25 = lo;
    // 0x8001F984: sh          $t9, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r25;
    // 0x8001F988: jal         0x800C06AC
    // 0x8001F98C: nop

    check_fadeout_transition(rdram, ctx);
        goto after_18;
    // 0x8001F98C: nop

    after_18:
    // 0x8001F990: beq         $v0, $zero, L_8001F9AC
    if (ctx->r2 == 0) {
        // 0x8001F994: nop
    
            goto L_8001F9AC;
    }
    // 0x8001F994: nop

    // 0x8001F998: lbu         $t6, 0xA4($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XA4);
    // 0x8001F99C: nop

    // 0x8001F9A0: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x8001F9A4: beq         $t7, $zero, L_8001F9B8
    if (ctx->r15 == 0) {
        // 0x8001F9A8: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_8001F9B8;
    }
    // 0x8001F9A8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
L_8001F9AC:
    // 0x8001F9AC: jal         0x800C06F8
    // 0x8001F9B0: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    transition_begin(rdram, ctx);
        goto after_19;
    // 0x8001F9B0: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    after_19:
    // 0x8001F9B4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
L_8001F9B8:
    // 0x8001F9B8: sb          $t8, 0x3B($s3)
    MEM_B(0X3B, ctx->r19) = ctx->r24;
L_8001F9BC:
    // 0x8001F9BC: lbu         $t9, 0x2E($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X2E);
    // 0x8001F9C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001F9C4: bne         $t9, $at, L_8001FAC0
    if (ctx->r25 != ctx->r1) {
        // 0x8001F9C8: nop
    
            goto L_8001FAC0;
    }
    // 0x8001F9C8: nop

    // 0x8001F9CC: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001F9D0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001F9D4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001F9D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001F9DC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001F9E0: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8001F9E4: lb          $t7, 0x31($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X31);
    // 0x8001F9E8: lh          $t6, 0x0($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X0);
    // 0x8001F9EC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8001F9F0: lh          $t7, 0x2($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X2);
    // 0x8001F9F4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F9F8: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8001F9FC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001FA00: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001FA04: nop

    // 0x8001FA08: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001FA0C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FA10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FA14: nop

    // 0x8001FA18: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001FA1C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001FA20: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8001FA24: nop

    // 0x8001FA28: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001FA2C: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    // 0x8001FA30: lb          $t6, 0x32($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X32);
    // 0x8001FA34: nop

    // 0x8001FA38: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8001FA3C: lh          $t6, 0x4($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X4);
    // 0x8001FA40: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001FA44: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001FA48: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001FA4C: nop

    // 0x8001FA50: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001FA54: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FA58: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FA5C: nop

    // 0x8001FA60: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001FA64: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001FA68: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8001FA6C: nop

    // 0x8001FA70: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001FA74: sh          $t9, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r25;
    // 0x8001FA78: lb          $t7, 0x33($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X33);
    // 0x8001FA7C: nop

    // 0x8001FA80: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8001FA84: nop

    // 0x8001FA88: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001FA8C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001FA90: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001FA94: nop

    // 0x8001FA98: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001FA9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FAA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FAA4: nop

    // 0x8001FAA8: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001FAAC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001FAB0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8001FAB4: nop

    // 0x8001FAB8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001FABC: sh          $t9, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r25;
L_8001FAC0:
    // 0x8001FAC0: beq         $s4, $zero, L_8001FDD8
    if (ctx->r20 == 0) {
        // 0x8001FAC4: nop
    
            goto L_8001FDD8;
    }
    // 0x8001FAC4: nop

    // 0x8001FAC8: lw          $t7, 0x40($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X40);
    // 0x8001FACC: nop

    // 0x8001FAD0: lb          $t6, 0x53($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X53);
    // 0x8001FAD4: nop

    // 0x8001FAD8: bne         $t6, $zero, L_8001FDD8
    if (ctx->r14 != 0) {
        // 0x8001FADC: nop
    
            goto L_8001FDD8;
    }
    // 0x8001FADC: nop

    // 0x8001FAE0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001FAE4: lb          $t8, 0x3B($s6)
    ctx->r24 = MEM_B(ctx->r22, 0X3B);
    // 0x8001FAE8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001FAEC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FAF0: sb          $t8, 0x3B($s4)
    MEM_B(0X3B, ctx->r20) = ctx->r24;
    // 0x8001FAF4: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FAF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FAFC: lh          $v0, 0x18($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X18);
    // 0x8001FB00: cvt.w.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = CVT_W_S(ctx->f2.fl);
    // 0x8001FB04: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8001FB08: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001FB0C: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8001FB10: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001FB14: beq         $v0, $t8, L_8001FB34
    if (ctx->r2 == ctx->r24) {
        // 0x8001FB18: nop
    
            goto L_8001FB34;
    }
    // 0x8001FB18: nop

    // 0x8001FB1C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8001FB20: nop

    // 0x8001FB24: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001FB28: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FB2C: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FB30: nop

L_8001FB34:
    // 0x8001FB34: lb          $t7, 0x3A($s4)
    ctx->r15 = MEM_B(ctx->r20, 0X3A);
    // 0x8001FB38: lw          $t9, 0x68($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X68);
    // 0x8001FB3C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8001FB40: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8001FB44: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x8001FB48: nop

    // 0x8001FB4C: beq         $v1, $zero, L_8001FDAC
    if (ctx->r3 == 0) {
        // 0x8001FB50: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FB50: nop

    // 0x8001FB54: lb          $v0, 0x3B($s4)
    ctx->r2 = MEM_B(ctx->r20, 0X3B);
    // 0x8001FB58: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8001FB5C: bltz        $v0, L_8001FDAC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FB60: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FB60: nop

    // 0x8001FB64: lh          $t7, 0x48($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X48);
    // 0x8001FB68: nop

    // 0x8001FB6C: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001FB70: beq         $at, $zero, L_8001FDAC
    if (ctx->r1 == 0) {
        // 0x8001FB74: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FB74: nop

    // 0x8001FB78: lw          $t9, 0x44($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X44);
    // 0x8001FB7C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8001FB80: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8001FB84: lw          $s5, 0x4($t8)
    ctx->r21 = MEM_W(ctx->r24, 0X4);
    // 0x8001FB88: lbu         $v1, 0x2C($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X2C);
    // 0x8001FB8C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x8001FB90: sll         $t7, $s5, 4
    ctx->r15 = S32(ctx->r21 << 4);
    // 0x8001FB94: beq         $v1, $zero, L_8001FBC0
    if (ctx->r3 == 0) {
        // 0x8001FB98: or          $s5, $t7, $zero
        ctx->r21 = ctx->r15 | 0;
            goto L_8001FBC0;
    }
    // 0x8001FB98: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
    // 0x8001FB9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FBA0: beq         $v1, $at, L_8001FC60
    if (ctx->r3 == ctx->r1) {
        // 0x8001FBA4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001FC60;
    }
    // 0x8001FBA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001FBA8: beq         $v1, $at, L_8001FC0C
    if (ctx->r3 == ctx->r1) {
        // 0x8001FBAC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8001FC0C;
    }
    // 0x8001FBAC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001FBB0: beq         $v1, $at, L_8001FD08
    if (ctx->r3 == ctx->r1) {
        // 0x8001FBB4: nop
    
            goto L_8001FD08;
    }
    // 0x8001FBB4: nop

    // 0x8001FBB8: b           L_8001FDB0
    // 0x8001FBBC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FDB0;
    // 0x8001FBBC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FBC0:
    // 0x8001FBC0: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FBC4: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FBC8: nop

    // 0x8001FBCC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001FBD0: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x8001FBD4: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8001FBD8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001FBDC: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FBE0: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FBE4: nop

    // 0x8001FBE8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001FBEC: nop

    // 0x8001FBF0: bc1f        L_8001FDAC
    if (!c1cs) {
        // 0x8001FBF4: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FBF4: nop

    // 0x8001FBF8: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8001FBFC: swc1        $f6, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f6.u32l;
    // 0x8001FC00: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FC04: b           L_8001FDB0
    // 0x8001FC08: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FDB0;
    // 0x8001FC08: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FC0C:
    // 0x8001FC0C: lwc1        $f8, 0x14($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FC10: lwc1        $f10, 0x114($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FC14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FC18: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001FC1C: mtc1        $s5, $f8
    ctx->f8.u32l = ctx->r21;
    // 0x8001FC20: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8001FC24: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001FC28: swc1        $f6, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f6.u32l;
    // 0x8001FC2C: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FC30: nop

    // 0x8001FC34: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001FC38: nop

    // 0x8001FC3C: bc1f        L_8001FDAC
    if (!c1cs) {
        // 0x8001FC40: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FC40: nop

    // 0x8001FC44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001FC48: nop

    // 0x8001FC4C: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8001FC50: swc1        $f4, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f4.u32l;
    // 0x8001FC54: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FC58: b           L_8001FDB0
    // 0x8001FC5C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FDB0;
    // 0x8001FC5C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FC60:
    // 0x8001FC60: lbu         $t9, 0x2D($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X2D);
    // 0x8001FC64: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FC68: bne         $t9, $zero, L_8001FCCC
    if (ctx->r25 != 0) {
        // 0x8001FC6C: nop
    
            goto L_8001FCCC;
    }
    // 0x8001FC6C: nop

    // 0x8001FC70: lwc1        $f6, 0x14($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FC74: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FC78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FC7C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001FC80: mtc1        $s5, $f6
    ctx->f6.u32l = ctx->r21;
    // 0x8001FC84: add.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8001FC88: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001FC8C: swc1        $f4, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f4.u32l;
    // 0x8001FC90: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FC94: nop

    // 0x8001FC98: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001FC9C: nop

    // 0x8001FCA0: bc1f        L_8001FCC4
    if (!c1cs) {
        // 0x8001FCA4: nop
    
            goto L_8001FCC4;
    }
    // 0x8001FCA4: nop

    // 0x8001FCA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001FCAC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001FCB0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8001FCB4: sb          $t6, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = ctx->r14;
    // 0x8001FCB8: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FCBC: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FCC0: nop

L_8001FCC4:
    // 0x8001FCC4: b           L_8001FDB0
    // 0x8001FCC8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FDB0;
    // 0x8001FCC8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FCCC:
    // 0x8001FCCC: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FCD0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001FCD4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001FCD8: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x8001FCDC: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FCE0: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FCE4: nop

    // 0x8001FCE8: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x8001FCEC: nop

    // 0x8001FCF0: bc1f        L_8001FDAC
    if (!c1cs) {
        // 0x8001FCF4: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FCF4: nop

    // 0x8001FCF8: swc1        $f22, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f22.u32l;
    // 0x8001FCFC: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FD00: b           L_8001FDAC
    // 0x8001FD04: sb          $zero, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = 0;
        goto L_8001FDAC;
    // 0x8001FD04: sb          $zero, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = 0;
L_8001FD08:
    // 0x8001FD08: lbu         $t8, 0x2D($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X2D);
    // 0x8001FD0C: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FD10: bne         $t8, $zero, L_8001FD74
    if (ctx->r24 != 0) {
        // 0x8001FD14: nop
    
            goto L_8001FD74;
    }
    // 0x8001FD14: nop

    // 0x8001FD18: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FD1C: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FD20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FD24: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001FD28: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x8001FD2C: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8001FD30: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001FD34: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FD38: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FD3C: nop

    // 0x8001FD40: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001FD44: nop

    // 0x8001FD48: bc1f        L_8001FD6C
    if (!c1cs) {
        // 0x8001FD4C: nop
    
            goto L_8001FD6C;
    }
    // 0x8001FD4C: nop

    // 0x8001FD50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001FD54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001FD58: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8001FD5C: sb          $t7, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = ctx->r15;
    // 0x8001FD60: swc1        $f8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f8.u32l;
    // 0x8001FD64: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FD68: nop

L_8001FD6C:
    // 0x8001FD6C: b           L_8001FDB0
    // 0x8001FD70: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FDB0;
    // 0x8001FD70: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FD74:
    // 0x8001FD74: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FD78: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001FD7C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001FD80: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8001FD84: swc1        $f8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f8.u32l;
    // 0x8001FD88: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FD8C: nop

    // 0x8001FD90: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x8001FD94: nop

    // 0x8001FD98: bc1f        L_8001FDAC
    if (!c1cs) {
        // 0x8001FD9C: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FD9C: nop

    // 0x8001FDA0: swc1        $f22, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f22.u32l;
    // 0x8001FDA4: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FDA8: nop

L_8001FDAC:
    // 0x8001FDAC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FDB0:
    // 0x8001FDB0: nop

    // 0x8001FDB4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001FDB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FDBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FDC0: nop

    // 0x8001FDC4: cvt.w.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = CVT_W_S(ctx->f2.fl);
    // 0x8001FDC8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8001FDCC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001FDD0: sh          $t6, 0x18($s4)
    MEM_H(0X18, ctx->r20) = ctx->r14;
    // 0x8001FDD4: nop

L_8001FDD8:
    // 0x8001FDD8: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8001FDDC: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8001FDE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001FDE4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001FDE8: c.le.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d <= ctx->f4.d;
    // 0x8001FDEC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001FDF0: bc1f        L_8001FE0C
    if (!c1cs) {
        // 0x8001FDF4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8001FE0C;
    }
    // 0x8001FDF4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001FDF8: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FDFC: jal         0x80021518
    // 0x8001FE00: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800214E4(rdram, ctx);
        goto after_20;
    // 0x8001FE00: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_20:
    // 0x8001FE04: b           L_800210CC
    // 0x8001FE08: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_800210CC;
    // 0x8001FE08: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001FE0C:
    // 0x8001FE0C: lh          $v1, -0x4C08($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4C08);
    // 0x8001FE10: lh          $a1, 0x28($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X28);
    // 0x8001FE14: blez        $v1, L_8001FE70
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001FE18: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8001FE70;
    }
    // 0x8001FE18: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001FE1C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001FE20: addiu       $a3, $a3, -0x4C0C
    ctx->r7 = ADD32(ctx->r7, -0X4C0C);
    // 0x8001FE24: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8001FE28: nop

    // 0x8001FE2C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8001FE30: nop

    // 0x8001FE34: lw          $t7, 0x7C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X7C);
    // 0x8001FE38: nop

    // 0x8001FE3C: beq         $a1, $t7, L_8001FE70
    if (ctx->r5 == ctx->r15) {
        // 0x8001FE40: nop
    
            goto L_8001FE70;
    }
    // 0x8001FE40: nop

L_8001FE44:
    // 0x8001FE44: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001FE48: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FE4C: beq         $at, $zero, L_8001FE70
    if (ctx->r1 == 0) {
        // 0x8001FE50: sll         $t9, $s4, 2
        ctx->r25 = S32(ctx->r20 << 2);
            goto L_8001FE70;
    }
    // 0x8001FE50: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x8001FE54: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x8001FE58: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001FE5C: nop

    // 0x8001FE60: lw          $t7, 0x7C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X7C);
    // 0x8001FE64: nop

    // 0x8001FE68: bne         $a1, $t7, L_8001FE44
    if (ctx->r5 != ctx->r15) {
        // 0x8001FE6C: nop
    
            goto L_8001FE44;
    }
    // 0x8001FE6C: nop

L_8001FE70:
    // 0x8001FE70: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001FE74: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FE78: bne         $at, $zero, L_8001FE94
    if (ctx->r1 != 0) {
        // 0x8001FE7C: addiu       $a3, $a3, -0x4C0C
        ctx->r7 = ADD32(ctx->r7, -0X4C0C);
            goto L_8001FE94;
    }
    // 0x8001FE7C: addiu       $a3, $a3, -0x4C0C
    ctx->r7 = ADD32(ctx->r7, -0X4C0C);
    // 0x8001FE80: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FE84: jal         0x80021518
    // 0x8001FE88: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800214E4(rdram, ctx);
        goto after_21;
    // 0x8001FE88: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_21:
    // 0x8001FE8C: b           L_800210CC
    // 0x8001FE90: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_800210CC;
    // 0x8001FE90: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001FE94:
    // 0x8001FE94: addiu       $t9, $s4, 0x1
    ctx->r25 = ADD32(ctx->r20, 0X1);
    // 0x8001FE98: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FE9C: beq         $at, $zero, L_8001FEF4
    if (ctx->r1 == 0) {
        // 0x8001FEA0: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_8001FEF4;
    }
    // 0x8001FEA0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8001FEA4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8001FEA8: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x8001FEAC: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x8001FEB0: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8001FEB4: addu        $v0, $s4, $s5
    ctx->r2 = ADD32(ctx->r20, ctx->r21);
    // 0x8001FEB8: lw          $t9, 0x7C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X7C);
    // 0x8001FEBC: nop

    // 0x8001FEC0: bne         $a1, $t9, L_8001FEF4
    if (ctx->r5 != ctx->r25) {
        // 0x8001FEC4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001FEF4;
    }
    // 0x8001FEC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001FEC8:
    // 0x8001FEC8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FECC: beq         $at, $zero, L_8001FEF4
    if (ctx->r1 == 0) {
        // 0x8001FED0: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8001FEF4;
    }
    // 0x8001FED0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001FED4: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x8001FED8: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x8001FEDC: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8001FEE0: nop

    // 0x8001FEE4: lw          $t9, 0x7C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X7C);
    // 0x8001FEE8: nop

    // 0x8001FEEC: beq         $a1, $t9, L_8001FEC8
    if (ctx->r5 == ctx->r25) {
        // 0x8001FEF0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001FEC8;
    }
    // 0x8001FEF0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001FEF4:
    // 0x8001FEF4: slti        $at, $s5, 0x2
    ctx->r1 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
    // 0x8001FEF8: beq         $at, $zero, L_8001FF14
    if (ctx->r1 == 0) {
        // 0x8001FEFC: nop
    
            goto L_8001FF14;
    }
    // 0x8001FEFC: nop

    // 0x8001FF00: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FF04: jal         0x80021518
    // 0x8001FF08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800214E4(rdram, ctx);
        goto after_22;
    // 0x8001FF08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_22:
    // 0x8001FF0C: b           L_800210CC
    // 0x8001FF10: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_800210CC;
    // 0x8001FF10: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001FF14:
    // 0x8001FF14: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8001FF18: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001FF1C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8001FF20: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001FF24: lw          $t8, 0x40($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X40);
    // 0x8001FF28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001FF2C: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8001FF30: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x8001FF34: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8001FF38: nop

    // 0x8001FF3C: div.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x8001FF40: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x8001FF44: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x8001FF48: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8001FF4C: slti        $at, $s5, 0x3
    ctx->r1 = SIGNED(ctx->r21) < 0X3 ? 1 : 0;
    // 0x8001FF50: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8001FF54: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8001FF58: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x8001FF5C: lw          $t7, -0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, -0X4);
    // 0x8001FF60: nop

    // 0x8001FF64: lw          $s1, 0x3C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X3C);
    // 0x8001FF68: bne         $at, $zero, L_8001FF90
    if (ctx->r1 != 0) {
        // 0x8001FF6C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8001FF90;
    }
    // 0x8001FF6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001FF70: lb          $v0, 0x1D($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X1D);
    // 0x8001FF74: addiu       $t9, $s5, -0x1
    ctx->r25 = ADD32(ctx->r21, -0X1);
    // 0x8001FF78: bltz        $v0, L_8001FF8C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FF7C: slt         $at, $v0, $t9
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_8001FF8C;
    }
    // 0x8001FF7C: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001FF80: beq         $at, $zero, L_8001FF90
    if (ctx->r1 == 0) {
        // 0x8001FF84: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8001FF90;
    }
    // 0x8001FF84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001FF88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001FF8C:
    // 0x8001FF8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8001FF90:
    // 0x8001FF90: bne         $v1, $at, L_8001FFC0
    if (ctx->r3 != ctx->r1) {
        // 0x8001FF94: nop
    
            goto L_8001FFC0;
    }
    // 0x8001FF94: nop

    // 0x8001FF98: lh          $t6, 0x26($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X26);
    // 0x8001FF9C: addiu       $t8, $s5, -0x1
    ctx->r24 = ADD32(ctx->r21, -0X1);
    // 0x8001FFA0: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001FFA4: bne         $at, $zero, L_8001FFC0
    if (ctx->r1 != 0) {
        // 0x8001FFA8: nop
    
            goto L_8001FFC0;
    }
    // 0x8001FFA8: nop

    // 0x8001FFAC: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FFB0: jal         0x80021518
    // 0x8001FFB4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800214E4(rdram, ctx);
        goto after_23;
    // 0x8001FFB4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_23:
    // 0x8001FFB8: b           L_800210CC
    // 0x8001FFBC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_800210CC;
    // 0x8001FFBC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001FFC0:
    // 0x8001FFC0: lh          $v0, 0x36($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X36);
    // 0x8001FFC4: sw          $v1, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r3;
    // 0x8001FFC8: bltz        $v0, L_8001FFF0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FFCC: addiu       $t1, $sp, 0x154
        ctx->r9 = ADD32(ctx->r29, 0X154);
            goto L_8001FFF0;
    }
    // 0x8001FFCC: addiu       $t1, $sp, 0x154
    ctx->r9 = ADD32(ctx->r29, 0X154);
    // 0x8001FFD0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001FFD4: lb          $t7, -0x4D2D($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X4D2D);
    // 0x8001FFD8: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FFDC: bne         $t7, $zero, L_8001FFE8
    if (ctx->r15 != 0) {
        // 0x8001FFE0: subu        $t6, $v0, $t9
        ctx->r14 = SUB32(ctx->r2, ctx->r25);
            goto L_8001FFE8;
    }
    // 0x8001FFE0: subu        $t6, $v0, $t9
    ctx->r14 = SUB32(ctx->r2, ctx->r25);
    // 0x8001FFE4: sh          $t6, 0x36($s3)
    MEM_H(0X36, ctx->r19) = ctx->r14;
L_8001FFE8:
    // 0x8001FFE8: b           L_800210C8
    // 0x8001FFEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800210C8;
    // 0x8001FFEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001FFF0:
    // 0x8001FFF0: lh          $s0, 0x26($s3)
    ctx->r16 = MEM_H(ctx->r19, 0X26);
    // 0x8001FFF4: addiu       $t2, $sp, 0x140
    ctx->r10 = ADD32(ctx->r29, 0X140);
    // 0x8001FFF8: addiu       $t3, $sp, 0x12C
    ctx->r11 = ADD32(ctx->r29, 0X12C);
    // 0x8001FFFC: addiu       $t5, $sp, 0xE0
    ctx->r13 = ADD32(ctx->r29, 0XE0);
    // 0x80020000: addiu       $t4, $sp, 0xCC
    ctx->r12 = ADD32(ctx->r29, 0XCC);
    // 0x80020004: addiu       $ra, $sp, 0xB8
    ctx->r31 = ADD32(ctx->r29, 0XB8);
    // 0x80020008: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    // 0x8002000C: addiu       $s2, $sp, 0x108
    ctx->r18 = ADD32(ctx->r29, 0X108);
    // 0x80020010: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80020014:
    // 0x80020014: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020018: bne         $s0, $at, L_800201C4
    if (ctx->r16 != ctx->r1) {
        // 0x8002001C: slt         $at, $s0, $s5
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_800201C4;
    }
    // 0x8002001C: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020020: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x80020024: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80020028: beq         $t8, $zero, L_80020108
    if (ctx->r24 == 0) {
        // 0x8002002C: addu        $t6, $s4, $s5
        ctx->r14 = ADD32(ctx->r20, ctx->r21);
            goto L_80020108;
    }
    // 0x8002002C: addu        $t6, $s4, $s5
    ctx->r14 = ADD32(ctx->r20, ctx->r21);
    // 0x80020030: addu        $v0, $a2, $t7
    ctx->r2 = ADD32(ctx->r6, ctx->r15);
    // 0x80020034: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80020038: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8002003C: lwc1        $f0, 0xC($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80020040: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80020044: nop

    // 0x80020048: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8002004C: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020050: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x80020054: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80020058: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8002005C: lwc1        $f2, 0x10($t8)
    ctx->f2.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80020060: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80020064: nop

    // 0x80020068: sub.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8002006C: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80020070: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x80020074: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80020078: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8002007C: lwc1        $f12, 0x14($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80020080: lwc1        $f8, 0x14($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80020084: nop

    // 0x80020088: sub.s       $f6, $f12, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8002008C: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80020090: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x80020094: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80020098: nop

    // 0x8002009C: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x800200A0: nop

    // 0x800200A4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800200A8: nop

    // 0x800200AC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800200B0: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x800200B4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800200B8: nop

    // 0x800200BC: lh          $t6, 0x2($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X2);
    // 0x800200C0: nop

    // 0x800200C4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800200C8: nop

    // 0x800200CC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800200D0: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800200D4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800200D8: nop

    // 0x800200DC: lh          $t7, 0x4($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X4);
    // 0x800200E0: nop

    // 0x800200E4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800200E8: nop

    // 0x800200EC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800200F0: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x800200F4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800200F8: nop

    // 0x800200FC: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80020100: b           L_8002052C
    // 0x80020104: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
        goto L_8002052C;
    // 0x80020104: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
L_80020108:
    // 0x80020108: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8002010C: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x80020110: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x80020114: nop

    // 0x80020118: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8002011C: nop

    // 0x80020120: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80020124: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x80020128: nop

    // 0x8002012C: lwc1        $f4, 0x10($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80020130: nop

    // 0x80020134: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x80020138: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x8002013C: nop

    // 0x80020140: lwc1        $f8, 0x14($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80020144: nop

    // 0x80020148: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x8002014C: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x80020150: nop

    // 0x80020154: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x80020158: nop

    // 0x8002015C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80020160: nop

    // 0x80020164: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80020168: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x8002016C: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x80020170: nop

    // 0x80020174: lh          $t6, 0x2($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X2);
    // 0x80020178: nop

    // 0x8002017C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80020180: nop

    // 0x80020184: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80020188: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x8002018C: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x80020190: nop

    // 0x80020194: lh          $t7, 0x4($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X4);
    // 0x80020198: nop

    // 0x8002019C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800201A0: nop

    // 0x800201A4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800201A8: swc1        $f10, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f10.u32l;
    // 0x800201AC: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800201B0: nop

    // 0x800201B4: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800201B8: b           L_8002052C
    // 0x800201BC: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
        goto L_8002052C;
    // 0x800201BC: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x800201C0: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
L_800201C4:
    // 0x800201C4: bne         $at, $zero, L_800203F8
    if (ctx->r1 != 0) {
        // 0x800201C8: addu        $a1, $s0, $s4
        ctx->r5 = ADD32(ctx->r16, ctx->r20);
            goto L_800203F8;
    }
    // 0x800201C8: addu        $a1, $s0, $s4
    ctx->r5 = ADD32(ctx->r16, ctx->r20);
    // 0x800201CC: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x800201D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800201D4: bne         $t6, $at, L_8002032C
    if (ctx->r14 != ctx->r1) {
        // 0x800201D8: addu        $v0, $s5, $s4
        ctx->r2 = ADD32(ctx->r21, ctx->r20);
            goto L_8002032C;
    }
    // 0x800201D8: addu        $v0, $s5, $s4
    ctx->r2 = ADD32(ctx->r21, ctx->r20);
    // 0x800201DC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800201E0: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800201E4: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800201E8: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800201EC: lw          $s1, 0x3C($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X3C);
    // 0x800201F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800201F4: lb          $t6, 0x22($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X22);
    // 0x800201F8: addiu       $s0, $s5, -0x1
    ctx->r16 = ADD32(ctx->r21, -0X1);
    // 0x800201FC: bne         $t6, $at, L_80020268
    if (ctx->r14 != ctx->r1) {
        // 0x80020200: addiu       $a1, $a1, -0x4
        ctx->r5 = ADD32(ctx->r5, -0X4);
            goto L_80020268;
    }
    // 0x80020200: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80020204: lb          $a0, 0x30($s3)
    ctx->r4 = MEM_B(ctx->r19, 0X30);
    // 0x80020208: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8002020C: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x80020210: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x80020214: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x80020218: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x8002021C: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x80020220: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80020224: jal         0x80066828
    // 0x80020228: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    set_active_camera(rdram, ctx);
        goto after_24;
    // 0x80020228: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_24:
    // 0x8002022C: jal         0x80069F3C
    // 0x80020230: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_25;
    // 0x80020230: nop

    after_25:
    // 0x80020234: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80020238: lw          $a2, -0x4C0C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C0C);
    // 0x8002023C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80020240: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80020244: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80020248: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8002024C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80020250: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80020254: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80020258: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8002025C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80020260: b           L_80020274
    // 0x80020264: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
        goto L_80020274;
    // 0x80020264: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
L_80020268:
    // 0x80020268: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
    // 0x8002026C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80020270: nop

L_80020274:
    // 0x80020274: lw          $t8, -0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, -0X4);
    // 0x80020278: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002027C: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80020280: nop

    // 0x80020284: sub.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80020288: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8002028C: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80020290: lw          $t7, -0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, -0X4);
    // 0x80020294: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80020298: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8002029C: nop

    // 0x800202A0: sub.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800202A4: add.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800202A8: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x800202AC: lw          $t9, -0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, -0X4);
    // 0x800202B0: lwc1        $f12, 0x14($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800202B4: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x800202B8: nop

    // 0x800202BC: sub.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x800202C0: add.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800202C4: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x800202C8: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800202CC: nop

    // 0x800202D0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800202D4: nop

    // 0x800202D8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800202DC: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800202E0: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x800202E4: nop

    // 0x800202E8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800202EC: nop

    // 0x800202F0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800202F4: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x800202F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800202FC: nop

    // 0x80020300: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80020304: nop

    // 0x80020308: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8002030C: nop

    // 0x80020310: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80020314: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x80020318: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8002031C: nop

    // 0x80020320: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80020324: b           L_8002052C
    // 0x80020328: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
        goto L_8002052C;
    // 0x80020328: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
L_8002032C:
    // 0x8002032C: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x80020330: nop

    // 0x80020334: addu        $t8, $s4, $t6
    ctx->r24 = ADD32(ctx->r20, ctx->r14);
    // 0x80020338: addu        $t7, $t8, $s0
    ctx->r15 = ADD32(ctx->r24, ctx->r16);
    // 0x8002033C: subu        $t9, $t7, $s5
    ctx->r25 = SUB32(ctx->r15, ctx->r21);
    // 0x80020340: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80020344: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x80020348: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002034C: nop

    // 0x80020350: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80020354: nop

    // 0x80020358: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x8002035C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80020360: nop

    // 0x80020364: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80020368: nop

    // 0x8002036C: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x80020370: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80020374: nop

    // 0x80020378: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8002037C: nop

    // 0x80020380: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x80020384: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80020388: nop

    // 0x8002038C: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x80020390: nop

    // 0x80020394: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80020398: nop

    // 0x8002039C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800203A0: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x800203A4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800203A8: nop

    // 0x800203AC: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x800203B0: nop

    // 0x800203B4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800203B8: nop

    // 0x800203BC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800203C0: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800203C4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800203C8: nop

    // 0x800203CC: lh          $t8, 0x4($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X4);
    // 0x800203D0: nop

    // 0x800203D4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800203D8: nop

    // 0x800203DC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800203E0: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x800203E4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800203E8: nop

    // 0x800203EC: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800203F0: b           L_8002052C
    // 0x800203F4: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
        goto L_8002052C;
    // 0x800203F4: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
L_800203F8:
    // 0x800203F8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800203FC: addu        $a0, $a2, $t9
    ctx->r4 = ADD32(ctx->r6, ctx->r25);
    // 0x80020400: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80020404: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80020408: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x8002040C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80020410: lb          $t6, 0x22($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X22);
    // 0x80020414: nop

    // 0x80020418: bne         $t6, $at, L_80020484
    if (ctx->r14 != ctx->r1) {
        // 0x8002041C: nop
    
            goto L_80020484;
    }
    // 0x8002041C: nop

    // 0x80020420: lb          $a0, 0x30($s3)
    ctx->r4 = MEM_B(ctx->r19, 0X30);
    // 0x80020424: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80020428: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x8002042C: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x80020430: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x80020434: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x80020438: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x8002043C: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80020440: jal         0x80066828
    // 0x80020444: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    set_active_camera(rdram, ctx);
        goto after_26;
    // 0x80020444: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    after_26:
    // 0x80020448: jal         0x80069F3C
    // 0x8002044C: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_27;
    // 0x8002044C: nop

    after_27:
    // 0x80020450: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80020454: lw          $a2, -0x4C0C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C0C);
    // 0x80020458: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x8002045C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80020460: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80020464: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80020468: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8002046C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80020470: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80020474: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80020478: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8002047C: b           L_80020484
    // 0x80020480: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
        goto L_80020484;
    // 0x80020480: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
L_80020484:
    // 0x80020484: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80020488: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002048C: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80020490: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80020494: nop

    // 0x80020498: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x8002049C: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800204A0: nop

    // 0x800204A4: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x800204A8: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x800204AC: nop

    // 0x800204B0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800204B4: nop

    // 0x800204B8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800204BC: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800204C0: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x800204C4: nop

    // 0x800204C8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800204CC: nop

    // 0x800204D0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800204D4: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x800204D8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800204DC: nop

    // 0x800204E0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800204E4: nop

    // 0x800204E8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800204EC: nop

    // 0x800204F0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800204F4: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x800204F8: lb          $t6, 0x22($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X22);
    // 0x800204FC: nop

    // 0x80020500: bne         $t6, $at, L_80020518
    if (ctx->r14 != ctx->r1) {
        // 0x80020504: nop
    
            goto L_80020518;
    }
    // 0x80020504: nop

    // 0x80020508: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8002050C: nop

    // 0x80020510: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x80020514: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
L_80020518:
    // 0x80020518: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8002051C: nop

    // 0x80020520: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80020524: nop

    // 0x80020528: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
L_8002052C:
    // 0x8002052C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80020530: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80020534: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80020538: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x8002053C: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80020540: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80020544: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x80020548: bne         $a3, $s2, L_80020014
    if (ctx->r7 != ctx->r18) {
        // 0x8002054C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80020014;
    }
    // 0x8002054C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020550: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80020554: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80020558: c.eq.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl == ctx->f10.fl;
    // 0x8002055C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80020560: bc1f        L_80020578
    if (!c1cs) {
        // 0x80020564: addiu       $s1, $sp, 0x154
        ctx->r17 = ADD32(ctx->r29, 0X154);
            goto L_80020578;
    }
    // 0x80020564: addiu       $s1, $sp, 0x154
    ctx->r17 = ADD32(ctx->r29, 0X154);
    // 0x80020568: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002056C: lwc1        $f4, 0x5C08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5C08);
    // 0x80020570: nop

    // 0x80020574: swc1        $f4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f4.u32l;
L_80020578:
    // 0x80020578: lwc1        $f8, 0x4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8002057C: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80020580: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80020584: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80020588: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002058C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80020590: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80020594: add.s       $f20, $f4, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80020598: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002059C: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x800205A0: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x800205A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800205A8: bc1f        L_800205C4
    if (!c1cs) {
        // 0x800205AC: nop
    
            goto L_800205C4;
    }
    // 0x800205AC: nop

    // 0x800205B0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800205B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800205B8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800205BC: sub.d       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f0.d - ctx->f6.d;
    // 0x800205C0: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
L_800205C4:
    // 0x800205C4: lb          $t7, 0x3F($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X3F);
    // 0x800205C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800205CC: bne         $t7, $zero, L_80020610
    if (ctx->r15 != 0) {
        // 0x800205D0: nop
    
            goto L_80020610;
    }
    // 0x800205D0: nop

    // 0x800205D4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800205D8: jal         0x80022574
    // 0x800205DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_28;
    // 0x800205DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_28:
    // 0x800205E0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800205E4: swc1        $f0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f0.u32l;
    // 0x800205E8: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x800205EC: jal         0x80022574
    // 0x800205F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_29;
    // 0x800205F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_29:
    // 0x800205F4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800205F8: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x800205FC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020600: jal         0x80022574
    // 0x80020604: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_30;
    // 0x80020604: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    after_30:
    // 0x80020608: b           L_80020648
    // 0x8002060C: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
        goto L_80020648;
    // 0x8002060C: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
L_80020610:
    // 0x80020610: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020614: jal         0x800228BC
    // 0x80020618: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lerp(rdram, ctx);
        goto after_31;
    // 0x80020618: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_31:
    // 0x8002061C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020620: swc1        $f0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f0.u32l;
    // 0x80020624: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x80020628: jal         0x800228BC
    // 0x8002062C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lerp(rdram, ctx);
        goto after_32;
    // 0x8002062C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_32:
    // 0x80020630: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020634: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x80020638: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002063C: jal         0x800228BC
    // 0x80020640: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    lerp(rdram, ctx);
        goto after_33;
    // 0x80020640: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    after_33:
    // 0x80020644: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
L_80020648:
    // 0x80020648: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8002064C: lwc1        $f8, 0xC($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80020650: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80020654: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80020658: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002065C: swc1        $f6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f6.u32l;
    // 0x80020660: lwc1        $f10, 0x10($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80020664: nop

    // 0x80020668: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8002066C: swc1        $f8, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f8.u32l;
    // 0x80020670: lwc1        $f4, 0x14($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80020674: nop

    // 0x80020678: sub.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8002067C: beq         $s0, $at, L_800206D8
    if (ctx->r16 == ctx->r1) {
        // 0x80020680: swc1        $f10, 0x11C($sp)
        MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
            goto L_800206D8;
    }
    // 0x80020680: swc1        $f10, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
    // 0x80020684: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80020688: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8002068C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80020690: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80020694: nop

    // 0x80020698: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8002069C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800206A0: jal         0x800CA030
    // 0x800206A4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_34;
    // 0x800206A4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_34:
    // 0x800206A8: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800206AC: nop

    // 0x800206B0: div.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800206B4: c.eq.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl == ctx->f2.fl;
    // 0x800206B8: nop

    // 0x800206BC: bc1t        L_800206D8
    if (c1cs) {
        // 0x800206C0: nop
    
            goto L_800206D8;
    }
    // 0x800206C0: nop

    // 0x800206C4: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800206C8: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800206CC: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800206D0: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800206D4: swc1        $f4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f4.u32l;
L_800206D8:
    // 0x800206D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800206DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800206E0: bne         $s0, $at, L_80020578
    if (ctx->r16 != ctx->r1) {
        // 0x800206E4: nop
    
            goto L_80020578;
    }
    // 0x800206E4: nop

    // 0x800206E8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800206EC: addiu       $a0, $sp, 0xF4
    ctx->r4 = ADD32(ctx->r29, 0XF4);
    // 0x800206F0: jal         0x80022574
    // 0x800206F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_35;
    // 0x800206F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_35:
    // 0x800206F8: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800206FC: lw          $t9, 0x40($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X40);
    // 0x80020700: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80020704: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80020708: nop

    // 0x8002070C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80020710: beq         $s2, $zero, L_800207A4
    if (ctx->r18 == 0) {
        // 0x80020714: swc1        $f4, 0x8($s6)
        MEM_W(0X8, ctx->r22) = ctx->f4.u32l;
            goto L_800207A4;
    }
    // 0x80020714: swc1        $f4, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f4.u32l;
    // 0x80020718: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x8002071C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020720: bne         $t6, $at, L_800207A4
    if (ctx->r14 != ctx->r1) {
        // 0x80020724: nop
    
            goto L_800207A4;
    }
    // 0x80020724: nop

    // 0x80020728: lh          $t8, 0x26($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X26);
    // 0x8002072C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80020730: addiu       $t7, $t8, 0x2
    ctx->r15 = ADD32(ctx->r24, 0X2);
    // 0x80020734: bne         $s5, $t7, L_800207A4
    if (ctx->r21 != ctx->r15) {
        // 0x80020738: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800207A4;
    }
    // 0x80020738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002073C: jal         0x80022574
    // 0x80020740: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    catmull_rom_interpolation(rdram, ctx);
        goto after_36;
    // 0x80020740: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_36:
    // 0x80020744: swc1        $f0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f0.u32l;
    // 0x80020748: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x8002074C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020750: jal         0x80022574
    // 0x80020754: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    catmull_rom_interpolation(rdram, ctx);
        goto after_37;
    // 0x80020754: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_37:
    // 0x80020758: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x8002075C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020760: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80020764: jal         0x80022574
    // 0x80020768: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_38;
    // 0x80020768: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    after_38:
    // 0x8002076C: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
    // 0x80020770: lwc1        $f10, 0xC($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80020774: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020778: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8002077C: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80020780: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
    // 0x80020784: lwc1        $f6, 0x10($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80020788: nop

    // 0x8002078C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80020790: swc1        $f10, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f10.u32l;
    // 0x80020794: lwc1        $f8, 0x14($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80020798: nop

    // 0x8002079C: sub.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800207A0: swc1        $f4, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f4.u32l;
L_800207A4:
    // 0x800207A4: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800207A8: lwc1        $f10, 0x114($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800207AC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800207B0: div.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800207B4: swc1        $f8, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->f8.u32l;
    // 0x800207B8: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800207BC: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800207C0: nop

    // 0x800207C4: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800207C8: swc1        $f10, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->f10.u32l;
    // 0x800207CC: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800207D0: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800207D4: nop

    // 0x800207D8: div.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800207DC: swc1        $f6, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->f6.u32l;
    // 0x800207E0: lw          $a3, 0x11C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X11C);
    // 0x800207E4: lw          $a2, 0x120($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X120);
    // 0x800207E8: lw          $a1, 0x124($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X124);
    // 0x800207EC: jal         0x80011570
    // 0x800207F0: nop

    move_object(rdram, ctx);
        goto after_39;
    // 0x800207F0: nop

    after_39:
    // 0x800207F4: lbu         $v1, 0x2E($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X2E);
    // 0x800207F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800207FC: beq         $v1, $at, L_80020D6C
    if (ctx->r3 == ctx->r1) {
        // 0x80020800: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80020D6C;
    }
    // 0x80020800: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80020804: beq         $v1, $at, L_8002081C
    if (ctx->r3 == ctx->r1) {
        // 0x80020808: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8002081C;
    }
    // 0x80020808: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002080C: beq         $v1, $at, L_80020D6C
    if (ctx->r3 == ctx->r1) {
        // 0x80020810: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80020D6C;
    }
    // 0x80020810: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80020814: b           L_80020954
    // 0x80020818: addiu       $t5, $sp, 0xE4
    ctx->r13 = ADD32(ctx->r29, 0XE4);
        goto L_80020954;
    // 0x80020818: addiu       $t5, $sp, 0xE4
    ctx->r13 = ADD32(ctx->r29, 0XE4);
L_8002081C:
    // 0x8002081C: lb          $t9, 0x3F($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X3F);
    // 0x80020820: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80020824: bne         $t9, $zero, L_80020870
    if (ctx->r25 != 0) {
        // 0x80020828: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80020870;
    }
    // 0x80020828: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002082C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020830: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80020834: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020838: jal         0x80022670
    // 0x8002083C: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    cubic_spline_interpolation(rdram, ctx);
        goto after_40;
    // 0x8002083C: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    after_40:
    // 0x80020840: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020844: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x80020848: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002084C: jal         0x80022670
    // 0x80020850: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    cubic_spline_interpolation(rdram, ctx);
        goto after_41;
    // 0x80020850: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    after_41:
    // 0x80020854: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020858: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x8002085C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020860: jal         0x80022670
    // 0x80020864: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_42;
    // 0x80020864: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    after_42:
    // 0x80020868: b           L_800208A8
    // 0x8002086C: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
        goto L_800208A8;
    // 0x8002086C: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
L_80020870:
    // 0x80020870: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020874: jal         0x800228E4
    // 0x80020878: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    lerp_and_get_derivative(rdram, ctx);
        goto after_43;
    // 0x80020878: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    after_43:
    // 0x8002087C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020880: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x80020884: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020888: jal         0x800228E4
    // 0x8002088C: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    lerp_and_get_derivative(rdram, ctx);
        goto after_44;
    // 0x8002088C: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    after_44:
    // 0x80020890: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020894: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x80020898: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002089C: jal         0x800228E4
    // 0x800208A0: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    lerp_and_get_derivative(rdram, ctx);
        goto after_45;
    // 0x800208A0: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    after_45:
    // 0x800208A4: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
L_800208A8:
    // 0x800208A8: lwc1        $f2, 0x120($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800208AC: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800208B0: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800208B4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800208B8: nop

    // 0x800208BC: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800208C0: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800208C4: jal         0x800CA030
    // 0x800208C8: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_46;
    // 0x800208C8: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_46:
    // 0x800208CC: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x800208D0: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x800208D4: bc1t        L_8002091C
    if (c1cs) {
        // 0x800208D8: nop
    
            goto L_8002091C;
    }
    // 0x800208D8: nop

    // 0x800208DC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800208E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800208E4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800208E8: nop

    // 0x800208EC: div.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x800208F0: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800208F4: lwc1        $f2, 0x120($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800208F8: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800208FC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80020900: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80020904: nop

    // 0x80020908: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8002090C: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
    // 0x80020910: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80020914: swc1        $f2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f2.u32l;
    // 0x80020918: swc1        $f14, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f14.u32l;
L_8002091C:
    // 0x8002091C: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80020920: lwc1        $f12, 0x124($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020924: jal         0x80070990
    // 0x80020928: nop

    arctan2_f(rdram, ctx);
        goto after_47;
    // 0x80020928: nop

    after_47:
    // 0x8002092C: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80020930: addu        $t6, $v0, $at
    ctx->r14 = ADD32(ctx->r2, ctx->r1);
    // 0x80020934: sh          $t6, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r14;
    // 0x80020938: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8002093C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80020940: lwc1        $f12, 0x120($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80020944: jal         0x80070990
    // 0x80020948: nop

    arctan2_f(rdram, ctx);
        goto after_48;
    // 0x80020948: nop

    after_48:
    // 0x8002094C: b           L_80020D6C
    // 0x80020950: sh          $v0, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r2;
        goto L_80020D6C;
    // 0x80020950: sh          $v0, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r2;
L_80020954:
    // 0x80020954: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x80020958: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002095C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80020960: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80020964: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80020968: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8002096C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80020970: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80020974: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80020978: addiu       $t4, $sp, 0xD0
    ctx->r12 = ADD32(ctx->r29, 0XD0);
    // 0x8002097C: addiu       $ra, $sp, 0xBC
    ctx->r31 = ADD32(ctx->r29, 0XBC);
    // 0x80020980: addiu       $a3, $sp, 0xCC
    ctx->r7 = ADD32(ctx->r29, 0XCC);
    // 0x80020984: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // 0x80020988: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
L_8002098C:
    // 0x8002098C: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80020990: lwc1        $f6, -0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, -0X4);
    // 0x80020994: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80020998: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002099C: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x800209A0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800209A4: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x800209A8: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x800209AC: bc1f        L_800209C4
    if (!c1cs) {
        // 0x800209B0: addiu       $t8, $zero, 0x5
        ctx->r24 = ADD32(0, 0X5);
            goto L_800209C4;
    }
    // 0x800209B0: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800209B4: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x800209B8: sub.d       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f10.d - ctx->f14.d;
    // 0x800209BC: b           L_800209E0
    // 0x800209C0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_800209E0;
    // 0x800209C0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_800209C4:
    // 0x800209C4: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x800209C8: nop

    // 0x800209CC: bc1f        L_800209E0
    if (!c1cs) {
        // 0x800209D0: nop
    
            goto L_800209E0;
    }
    // 0x800209D0: nop

    // 0x800209D4: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x800209D8: add.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f4.d + ctx->f14.d;
    // 0x800209DC: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_800209E0:
    // 0x800209E0: beq         $at, $zero, L_80020A6C
    if (ctx->r1 == 0) {
        // 0x800209E4: or          $s0, $t0, $zero
        ctx->r16 = ctx->r8 | 0;
            goto L_80020A6C;
    }
    // 0x800209E4: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x800209E8: subu        $a0, $t8, $t0
    ctx->r4 = SUB32(ctx->r24, ctx->r8);
    // 0x800209EC: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x800209F0: beq         $t7, $zero, L_80020A24
    if (ctx->r15 == 0) {
        // 0x800209F4: addu        $v1, $t7, $t0
        ctx->r3 = ADD32(ctx->r15, ctx->r8);
            goto L_80020A24;
    }
    // 0x800209F4: addu        $v1, $t7, $t0
    ctx->r3 = ADD32(ctx->r15, ctx->r8);
    // 0x800209F8: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x800209FC: addiu       $t6, $sp, 0xE0
    ctx->r14 = ADD32(ctx->r29, 0XE0);
    // 0x80020A00: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
L_80020A04:
    // 0x80020A04: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020A08: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020A0C: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020A10: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020A14: bne         $v1, $s0, L_80020A04
    if (ctx->r3 != ctx->r16) {
        // 0x80020A18: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020A04;
    }
    // 0x80020A18: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020A1C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80020A20: beq         $s0, $at, L_80020A68
    if (ctx->r16 == ctx->r1) {
        // 0x80020A24: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_80020A68;
    }
L_80020A24:
    // 0x80020A24: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80020A28: addiu       $t7, $sp, 0xE0
    ctx->r15 = ADD32(ctx->r29, 0XE0);
    // 0x80020A2C: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
L_80020A30:
    // 0x80020A30: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020A34: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80020A38: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020A3C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80020A40: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020A44: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80020A48: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020A4C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80020A50: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020A54: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80020A58: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020A5C: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80020A60: bne         $v0, $a1, L_80020A30
    if (ctx->r2 != ctx->r5) {
        // 0x80020A64: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020A30;
    }
    // 0x80020A64: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
L_80020A68:
    // 0x80020A68: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_80020A6C:
    // 0x80020A6C: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80020A70: lwc1        $f6, -0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, -0X4);
    // 0x80020A74: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80020A78: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80020A7C: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x80020A80: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80020A84: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x80020A88: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x80020A8C: bc1f        L_80020AA4
    if (!c1cs) {
        // 0x80020A90: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_80020AA4;
    }
    // 0x80020A90: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80020A94: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x80020A98: sub.d       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f10.d - ctx->f14.d;
    // 0x80020A9C: b           L_80020AC0
    // 0x80020AA0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_80020AC0;
    // 0x80020AA0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80020AA4:
    // 0x80020AA4: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x80020AA8: nop

    // 0x80020AAC: bc1f        L_80020AC0
    if (!c1cs) {
        // 0x80020AB0: nop
    
            goto L_80020AC0;
    }
    // 0x80020AB0: nop

    // 0x80020AB4: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x80020AB8: add.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f4.d + ctx->f14.d;
    // 0x80020ABC: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80020AC0:
    // 0x80020AC0: beq         $at, $zero, L_80020B48
    if (ctx->r1 == 0) {
        // 0x80020AC4: subu        $a0, $t9, $t0
        ctx->r4 = SUB32(ctx->r25, ctx->r8);
            goto L_80020B48;
    }
    // 0x80020AC4: subu        $a0, $t9, $t0
    ctx->r4 = SUB32(ctx->r25, ctx->r8);
    // 0x80020AC8: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x80020ACC: beq         $t6, $zero, L_80020B00
    if (ctx->r14 == 0) {
        // 0x80020AD0: addu        $v1, $t6, $t0
        ctx->r3 = ADD32(ctx->r14, ctx->r8);
            goto L_80020B00;
    }
    // 0x80020AD0: addu        $v1, $t6, $t0
    ctx->r3 = ADD32(ctx->r14, ctx->r8);
    // 0x80020AD4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80020AD8: addiu       $t7, $sp, 0xCC
    ctx->r15 = ADD32(ctx->r29, 0XCC);
    // 0x80020ADC: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
L_80020AE0:
    // 0x80020AE0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020AE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020AE8: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020AEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020AF0: bne         $v1, $s0, L_80020AE0
    if (ctx->r3 != ctx->r16) {
        // 0x80020AF4: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020AE0;
    }
    // 0x80020AF4: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020AF8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80020AFC: beq         $s0, $at, L_80020B44
    if (ctx->r16 == ctx->r1) {
        // 0x80020B00: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_80020B44;
    }
L_80020B00:
    // 0x80020B00: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80020B04: addiu       $t6, $sp, 0xCC
    ctx->r14 = ADD32(ctx->r29, 0XCC);
    // 0x80020B08: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
L_80020B0C:
    // 0x80020B0C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020B10: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80020B14: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020B18: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80020B1C: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020B20: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80020B24: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020B28: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80020B2C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020B30: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80020B34: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020B38: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80020B3C: bne         $v0, $a2, L_80020B0C
    if (ctx->r2 != ctx->r6) {
        // 0x80020B40: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020B0C;
    }
    // 0x80020B40: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
L_80020B44:
    // 0x80020B44: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_80020B48:
    // 0x80020B48: lwc1        $f4, 0x0($ra)
    ctx->f4.u32l = MEM_W(ctx->r31, 0X0);
    // 0x80020B4C: lwc1        $f6, -0x4($ra)
    ctx->f6.u32l = MEM_W(ctx->r31, -0X4);
    // 0x80020B50: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80020B54: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80020B58: subu        $a0, $t8, $t0
    ctx->r4 = SUB32(ctx->r24, ctx->r8);
    // 0x80020B5C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80020B60: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x80020B64: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x80020B68: bc1f        L_80020B80
    if (!c1cs) {
        // 0x80020B6C: slti        $at, $t0, 0x5
        ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
            goto L_80020B80;
    }
    // 0x80020B6C: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x80020B70: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x80020B74: sub.d       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f10.d - ctx->f14.d;
    // 0x80020B78: b           L_80020B9C
    // 0x80020B7C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_80020B9C;
    // 0x80020B7C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80020B80:
    // 0x80020B80: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x80020B84: nop

    // 0x80020B88: bc1f        L_80020B9C
    if (!c1cs) {
        // 0x80020B8C: nop
    
            goto L_80020B9C;
    }
    // 0x80020B8C: nop

    // 0x80020B90: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x80020B94: add.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f4.d + ctx->f14.d;
    // 0x80020B98: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80020B9C:
    // 0x80020B9C: beq         $at, $zero, L_80020C1C
    if (ctx->r1 == 0) {
        // 0x80020BA0: andi        $t7, $a0, 0x3
        ctx->r15 = ctx->r4 & 0X3;
            goto L_80020C1C;
    }
    // 0x80020BA0: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x80020BA4: beq         $t7, $zero, L_80020BD8
    if (ctx->r15 == 0) {
        // 0x80020BA8: addu        $v1, $t7, $t0
        ctx->r3 = ADD32(ctx->r15, ctx->r8);
            goto L_80020BD8;
    }
    // 0x80020BA8: addu        $v1, $t7, $t0
    ctx->r3 = ADD32(ctx->r15, ctx->r8);
    // 0x80020BAC: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80020BB0: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
    // 0x80020BB4: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
L_80020BB8:
    // 0x80020BB8: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020BBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020BC0: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020BC4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020BC8: bne         $v1, $s0, L_80020BB8
    if (ctx->r3 != ctx->r16) {
        // 0x80020BCC: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020BB8;
    }
    // 0x80020BCC: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020BD0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80020BD4: beq         $s0, $at, L_80020C1C
    if (ctx->r16 == ctx->r1) {
        // 0x80020BD8: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_80020C1C;
    }
L_80020BD8:
    // 0x80020BD8: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80020BDC: addiu       $t7, $sp, 0xB8
    ctx->r15 = ADD32(ctx->r29, 0XB8);
    // 0x80020BE0: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
L_80020BE4:
    // 0x80020BE4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020BE8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80020BEC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020BF0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80020BF4: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020BF8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80020BFC: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020C00: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80020C04: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020C08: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80020C0C: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020C10: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80020C14: bne         $v0, $a3, L_80020BE4
    if (ctx->r2 != ctx->r7) {
        // 0x80020C18: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020BE4;
    }
    // 0x80020C18: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
L_80020C1C:
    // 0x80020C1C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80020C20: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80020C24: bne         $t0, $at, L_8002098C
    if (ctx->r8 != ctx->r1) {
        // 0x80020C28: addiu       $ra, $ra, 0x4
        ctx->r31 = ADD32(ctx->r31, 0X4);
            goto L_8002098C;
    }
    // 0x80020C28: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x80020C2C: lb          $t9, 0x3F($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X3F);
    // 0x80020C30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020C34: bne         $t9, $zero, L_80020CD4
    if (ctx->r25 != 0) {
        // 0x80020C38: addiu       $a0, $sp, 0xE0
        ctx->r4 = ADD32(ctx->r29, 0XE0);
            goto L_80020CD4;
    }
    // 0x80020C38: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x80020C3C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020C40: jal         0x80022574
    // 0x80020C44: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    catmull_rom_interpolation(rdram, ctx);
        goto after_49;
    // 0x80020C44: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    after_49:
    // 0x80020C48: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80020C4C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020C50: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80020C54: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020C58: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020C5C: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80020C60: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020C64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020C68: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80020C6C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80020C70: jal         0x80022574
    // 0x80020C74: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
    catmull_rom_interpolation(rdram, ctx);
        goto after_50;
    // 0x80020C74: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
    after_50:
    // 0x80020C78: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80020C7C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020C80: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80020C84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020C88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020C8C: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80020C90: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020C94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020C98: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80020C9C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80020CA0: jal         0x80022574
    // 0x80020CA4: sh          $t9, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r25;
    catmull_rom_interpolation(rdram, ctx);
        goto after_51;
    // 0x80020CA4: sh          $t9, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r25;
    after_51:
    // 0x80020CA8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80020CAC: nop

    // 0x80020CB0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80020CB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020CB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020CBC: nop

    // 0x80020CC0: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020CC4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80020CC8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80020CCC: b           L_80020D6C
    // 0x80020CD0: sh          $t8, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r24;
        goto L_80020D6C;
    // 0x80020CD0: sh          $t8, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r24;
L_80020CD4:
    // 0x80020CD4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020CD8: jal         0x800228BC
    // 0x80020CDC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lerp(rdram, ctx);
        goto after_52;
    // 0x80020CDC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_52:
    // 0x80020CE0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80020CE4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020CE8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80020CEC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020CF0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020CF4: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80020CF8: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020CFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020D00: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80020D04: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80020D08: jal         0x800228BC
    // 0x80020D0C: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    lerp(rdram, ctx);
        goto after_53;
    // 0x80020D0C: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    after_53:
    // 0x80020D10: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80020D14: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020D18: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80020D1C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020D20: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020D24: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80020D28: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020D2C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020D30: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80020D34: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80020D38: jal         0x800228BC
    // 0x80020D3C: sh          $t8, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r24;
    lerp(rdram, ctx);
        goto after_54;
    // 0x80020D3C: sh          $t8, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r24;
    after_54:
    // 0x80020D40: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80020D44: nop

    // 0x80020D48: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80020D4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020D50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020D54: nop

    // 0x80020D58: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020D5C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80020D60: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80020D64: sh          $t9, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r25;
    // 0x80020D68: nop

L_80020D6C:
    // 0x80020D6C: lw          $v1, 0x168($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X168);
    // 0x80020D70: lh          $t0, 0x26($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X26);
    // 0x80020D74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020D78: beq         $v1, $at, L_80020D90
    if (ctx->r3 == ctx->r1) {
        // 0x80020D7C: swc1        $f20, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
            goto L_80020D90;
    }
    // 0x80020D7C: swc1        $f20, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
    // 0x80020D80: slt         $at, $t0, $s5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020D84: bne         $at, $zero, L_80020D90
    if (ctx->r1 != 0) {
        // 0x80020D88: subu        $t6, $t0, $s5
        ctx->r14 = SUB32(ctx->r8, ctx->r21);
            goto L_80020D90;
    }
    // 0x80020D88: subu        $t6, $t0, $s5
    ctx->r14 = SUB32(ctx->r8, ctx->r21);
    // 0x80020D8C: addu        $t0, $t6, $v1
    ctx->r8 = ADD32(ctx->r14, ctx->r3);
L_80020D90:
    // 0x80020D90: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80020D94: addiu       $t1, $t1, -0x4C0C
    ctx->r9 = ADD32(ctx->r9, -0X4C0C);
    // 0x80020D98: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80020D9C: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80020DA0: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80020DA4: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80020DA8: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80020DAC: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80020DB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80020DB4: lw          $s1, 0x3C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X3C);
    // 0x80020DB8: lwc1        $f1, 0x5C10($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X5C10);
    // 0x80020DBC: lb          $t9, 0x14($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X14);
    // 0x80020DC0: lwc1        $f0, 0x5C14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5C14);
    // 0x80020DC4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80020DC8: nop

    // 0x80020DCC: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80020DD0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80020DD4: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80020DD8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80020DDC: c.lt.s      $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f10.fl < ctx->f22.fl;
    // 0x80020DE0: swc1        $f10, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f10.u32l;
    // 0x80020DE4: bc1f        L_80020DF8
    if (!c1cs) {
        // 0x80020DE8: nop
    
            goto L_80020DF8;
    }
    // 0x80020DE8: nop

    // 0x80020DEC: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80020DF0: b           L_80020E04
    // 0x80020DF4: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
        goto L_80020E04;
    // 0x80020DF4: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
L_80020DF8:
    // 0x80020DF8: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020DFC: nop

    // 0x80020E00: swc1        $f4, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f4.u32l;
L_80020E04:
    // 0x80020E04: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020E08: nop

    // 0x80020E0C: c.le.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl <= ctx->f6.fl;
    // 0x80020E10: nop

    // 0x80020E14: bc1f        L_80020EBC
    if (!c1cs) {
        // 0x80020E18: nop
    
            goto L_80020EBC;
    }
    // 0x80020E18: nop

    // 0x80020E1C: bne         $s2, $zero, L_80020EBC
    if (ctx->r18 != 0) {
        // 0x80020E20: addiu       $v0, $t0, 0x1
        ctx->r2 = ADD32(ctx->r8, 0X1);
            goto L_80020EBC;
    }
    // 0x80020E20: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x80020E24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020E28: beq         $v1, $at, L_80020E40
    if (ctx->r3 == ctx->r1) {
        // 0x80020E2C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80020E40;
    }
    // 0x80020E2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80020E30: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020E34: bne         $at, $zero, L_80020E40
    if (ctx->r1 != 0) {
        // 0x80020E38: subu        $t6, $v0, $s5
        ctx->r14 = SUB32(ctx->r2, ctx->r21);
            goto L_80020E40;
    }
    // 0x80020E38: subu        $t6, $v0, $s5
    ctx->r14 = SUB32(ctx->r2, ctx->r21);
    // 0x80020E3C: addu        $s0, $t6, $v1
    ctx->r16 = ADD32(ctx->r14, ctx->r3);
L_80020E40:
    // 0x80020E40: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020E44: beq         $at, $zero, L_80020EA0
    if (ctx->r1 == 0) {
        // 0x80020E48: sll         $t7, $s4, 2
        ctx->r15 = S32(ctx->r20 << 2);
            goto L_80020EA0;
    }
    // 0x80020E48: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80020E4C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80020E50: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80020E54: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80020E58: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80020E5C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80020E60: lwc1        $f14, 0x124($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020E64: lw          $s1, 0x3C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X3C);
    // 0x80020E68: nop

    // 0x80020E6C: lb          $v0, 0x14($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X14);
    // 0x80020E70: nop

    // 0x80020E74: bltz        $v0, L_80020E9C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80020E78: nop
    
            goto L_80020E9C;
    }
    // 0x80020E78: nop

    // 0x80020E7C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80020E80: nop

    // 0x80020E84: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80020E88: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80020E8C: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80020E90: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80020E94: b           L_80020EA0
    // 0x80020E98: swc1        $f10, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
        goto L_80020EA0;
    // 0x80020E98: swc1        $f10, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
L_80020E9C:
    // 0x80020E9C: swc1        $f14, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f14.u32l;
L_80020EA0:
    // 0x80020EA0: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80020EA4: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020EA8: nop

    // 0x80020EAC: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80020EB0: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80020EB4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80020EB8: swc1        $f8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f8.u32l;
L_80020EBC:
    // 0x80020EBC: beq         $s2, $zero, L_80020F7C
    if (ctx->r18 == 0) {
        // 0x80020EC0: nop
    
            goto L_80020F7C;
    }
    // 0x80020EC0: nop

    // 0x80020EC4: lh          $t9, 0x26($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X26);
    // 0x80020EC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020ECC: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80020ED0: bne         $v1, $at, L_80020F24
    if (ctx->r3 != ctx->r1) {
        // 0x80020ED4: sh          $t6, 0x26($s3)
        MEM_H(0X26, ctx->r19) = ctx->r14;
            goto L_80020F24;
    }
    // 0x80020ED4: sh          $t6, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r14;
    // 0x80020ED8: lh          $v0, 0x26($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X26);
    // 0x80020EDC: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x80020EE0: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020EE4: bne         $at, $zero, L_80020EF8
    if (ctx->r1 != 0) {
        // 0x80020EE8: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80020EF8;
    }
    // 0x80020EE8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80020EEC: addiu       $t8, $s5, -0x1
    ctx->r24 = ADD32(ctx->r21, -0X1);
    // 0x80020EF0: b           L_80020F7C
    // 0x80020EF4: sh          $t8, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r24;
        goto L_80020F7C;
    // 0x80020EF4: sh          $t8, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r24;
L_80020EF8:
    // 0x80020EF8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80020EFC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80020F00: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80020F04: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80020F08: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80020F0C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80020F10: lw          $a1, 0x3C($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X3C);
    // 0x80020F14: jal         0x80021290
    // 0x80020F18: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8002125C(rdram, ctx);
        goto after_55;
    // 0x80020F18: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_55:
    // 0x80020F1C: b           L_80020F80
    // 0x80020F20: lbu         $t7, 0x2E($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X2E);
        goto L_80020F80;
    // 0x80020F20: lbu         $t7, 0x2E($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X2E);
L_80020F24:
    // 0x80020F24: lh          $v0, 0x26($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X26);
    // 0x80020F28: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80020F2C: slt         $at, $s5, $v0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80020F30: beq         $at, $zero, L_80020F44
    if (ctx->r1 == 0) {
        // 0x80020F34: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80020F44;
    }
    // 0x80020F34: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80020F38: sh          $t6, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r14;
    // 0x80020F3C: lh          $v0, 0x26($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X26);
    // 0x80020F40: nop

L_80020F44:
    // 0x80020F44: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020F48: bne         $at, $zero, L_80020F58
    if (ctx->r1 != 0) {
        // 0x80020F4C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80020F58;
    }
    // 0x80020F4C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80020F50: subu        $t8, $v0, $s5
    ctx->r24 = SUB32(ctx->r2, ctx->r21);
    // 0x80020F54: addu        $s2, $t8, $v1
    ctx->r18 = ADD32(ctx->r24, ctx->r3);
L_80020F58:
    // 0x80020F58: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80020F5C: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
    // 0x80020F60: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80020F64: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80020F68: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80020F6C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80020F70: lw          $a1, 0x3C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X3C);
    // 0x80020F74: jal         0x80021290
    // 0x80020F78: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8002125C(rdram, ctx);
        goto after_56;
    // 0x80020F78: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_56:
L_80020F7C:
    // 0x80020F7C: lbu         $t7, 0x2E($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X2E);
L_80020F80:
    // 0x80020F80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80020F84: bne         $t7, $at, L_800210AC
    if (ctx->r15 != ctx->r1) {
        // 0x80020F88: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800210AC;
    }
    // 0x80020F88: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80020F8C: lh          $v1, -0x4C08($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4C08);
    // 0x80020F90: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80020F94: blez        $v1, L_80020FEC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80020F98: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80020FEC;
    }
    // 0x80020F98: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80020F9C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80020FA0: lw          $a2, -0x4C0C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C0C);
    // 0x80020FA4: lb          $v0, 0x3E($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X3E);
    // 0x80020FA8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80020FAC: nop

    // 0x80020FB0: lw          $t6, 0x7C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X7C);
    // 0x80020FB4: nop

    // 0x80020FB8: beq         $v0, $t6, L_80020FEC
    if (ctx->r2 == ctx->r14) {
        // 0x80020FBC: nop
    
            goto L_80020FEC;
    }
    // 0x80020FBC: nop

L_80020FC0:
    // 0x80020FC0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80020FC4: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80020FC8: beq         $at, $zero, L_80020FEC
    if (ctx->r1 == 0) {
        // 0x80020FCC: sll         $t8, $t0, 2
        ctx->r24 = S32(ctx->r8 << 2);
            goto L_80020FEC;
    }
    // 0x80020FCC: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80020FD0: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x80020FD4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80020FD8: nop

    // 0x80020FDC: lw          $t6, 0x7C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X7C);
    // 0x80020FE0: nop

    // 0x80020FE4: bne         $v0, $t6, L_80020FC0
    if (ctx->r2 != ctx->r14) {
        // 0x80020FE8: nop
    
            goto L_80020FC0;
    }
    // 0x80020FE8: nop

L_80020FEC:
    // 0x80020FEC: beq         $t0, $v1, L_800210AC
    if (ctx->r8 == ctx->r3) {
        // 0x80020FF0: addiu       $t1, $t1, -0x4C0C
        ctx->r9 = ADD32(ctx->r9, -0X4C0C);
            goto L_800210AC;
    }
    // 0x80020FF0: addiu       $t1, $t1, -0x4C0C
    ctx->r9 = ADD32(ctx->r9, -0X4C0C);
    // 0x80020FF4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80020FF8: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80020FFC: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80021000: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80021004: nop

    // 0x80021008: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x8002100C: nop

    // 0x80021010: beq         $v1, $zero, L_800210AC
    if (ctx->r3 == 0) {
        // 0x80021014: nop
    
            goto L_800210AC;
    }
    // 0x80021014: nop

    // 0x80021018: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002101C: lwc1        $f10, 0xC($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80021020: nop

    // 0x80021024: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80021028: swc1        $f4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f4.u32l;
    // 0x8002102C: lwc1        $f6, 0x10($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80021030: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80021034: nop

    // 0x80021038: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8002103C: swc1        $f10, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f10.u32l;
    // 0x80021040: lwc1        $f8, 0x14($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80021044: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80021048: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8002104C: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80021050: lwc1        $f8, 0x120($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80021054: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80021058: swc1        $f6, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f6.u32l;
    // 0x8002105C: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80021060: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80021064: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80021068: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8002106C: jal         0x800CA030
    // 0x80021070: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_57;
    // 0x80021070: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_57:
    // 0x80021074: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80021078: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8002107C: bc1f        L_800210AC
    if (!c1cs) {
        // 0x80021080: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800210AC;
    }
    // 0x80021080: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80021084: lwc1        $f12, 0x124($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80021088: jal         0x80070990
    // 0x8002108C: nop

    arctan2_f(rdram, ctx);
        goto after_58;
    // 0x8002108C: nop

    after_58:
    // 0x80021090: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80021094: addu        $t8, $v0, $at
    ctx->r24 = ADD32(ctx->r2, ctx->r1);
    // 0x80021098: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
    // 0x8002109C: lwc1        $f12, 0x120($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800210A0: jal         0x80070990
    // 0x800210A4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_59;
    // 0x800210A4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_59:
    // 0x800210A8: sh          $v0, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r2;
L_800210AC:
    // 0x800210AC: lb          $t7, 0x2F($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X2F);
    // 0x800210B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800210B4: sw          $t7, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->r15;
    // 0x800210B8: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x800210BC: jal         0x800B019C
    // 0x800210C0: nop

    obj_spawn_particle(rdram, ctx);
        goto after_60;
    // 0x800210C0: nop

    after_60:
    // 0x800210C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800210C8:
    // 0x800210C8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800210CC:
    // 0x800210CC: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800210D0: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800210D4: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800210D8: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800210DC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800210E0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800210E4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800210E8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800210EC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800210F0: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800210F4: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800210F8: jr          $ra
    // 0x800210FC: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
    return;
    // 0x800210FC: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
;}
RECOMP_FUNC void func_800210CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021100: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021104: addiu       $v1, $v1, -0x4D43
    ctx->r3 = ADD32(ctx->r3, -0X4D43);
    // 0x80021108: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x8002110C: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x80021110: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x80021114: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80021118: bne         $at, $zero, L_8002112C
    if (ctx->r1 != 0) {
        // 0x8002111C: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_8002112C;
    }
    // 0x8002111C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80021120: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80021124: jr          $ra
    // 0x80021128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80021128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002112C:
    // 0x8002112C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021130: jr          $ra
    // 0x80021134: nop

    return;
    // 0x80021134: nop

;}
RECOMP_FUNC void func_80021104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021138: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002113C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021140: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80021144: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x80021148: lw          $v1, 0x1C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C);
    // 0x8002114C: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80021150: bne         $t6, $at, L_80021178
    if (ctx->r14 != ctx->r1) {
        // 0x80021154: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80021178;
    }
    // 0x80021154: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80021158: addiu       $v0, $v0, -0x4D42
    ctx->r2 = ADD32(ctx->r2, -0X4D42);
    // 0x8002115C: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x80021160: nop

    // 0x80021164: sb          $t7, 0x44($a1)
    MEM_B(0X44, ctx->r5) = ctx->r15;
    // 0x80021168: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x8002116C: nop

    // 0x80021170: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80021174: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_80021178:
    // 0x80021178: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002117C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80021180: lb          $a0, 0x22($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X22);
    // 0x80021184: nop

    // 0x80021188: bne         $a0, $at, L_8002120C
    if (ctx->r4 != ctx->r1) {
        // 0x8002118C: slti        $at, $a0, 0xA
        ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
            goto L_8002120C;
    }
    // 0x8002118C: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x80021190: lb          $a0, 0x30($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X30);
    // 0x80021194: jal         0x80066828
    // 0x80021198: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    set_active_camera(rdram, ctx);
        goto after_0;
    // 0x80021198: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002119C: jal         0x80069F3C
    // 0x800211A0: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_1;
    // 0x800211A0: nop

    after_1:
    // 0x800211A4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800211A8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800211AC: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x800211B0: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
    // 0x800211B4: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800211B8: nop

    // 0x800211BC: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
    // 0x800211C0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800211C4: nop

    // 0x800211C8: swc1        $f8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f8.u32l;
    // 0x800211CC: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800211D0: nop

    // 0x800211D4: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x800211D8: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x800211DC: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x800211E0: nop

    // 0x800211E4: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800211E8: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
    // 0x800211EC: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800211F0: nop

    // 0x800211F4: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x800211F8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800211FC: nop

    // 0x80021200: lb          $a0, 0x22($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X22);
    // 0x80021204: nop

    // 0x80021208: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
L_8002120C:
    // 0x8002120C: bne         $at, $zero, L_80021280
    if (ctx->r1 != 0) {
        // 0x80021210: slti        $at, $a0, 0x12
        ctx->r1 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
            goto L_80021280;
    }
    // 0x80021210: slti        $at, $a0, 0x12
    ctx->r1 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
    // 0x80021214: beq         $at, $zero, L_80021280
    if (ctx->r1 == 0) {
        // 0x80021218: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80021280;
    }
    // 0x80021218: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002121C: lw          $t8, -0x4B9C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4B9C);
    // 0x80021220: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80021224: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80021228: lw          $v0, -0x28($t0)
    ctx->r2 = MEM_W(ctx->r8, -0X28);
    // 0x8002122C: nop

    // 0x80021230: beq         $v0, $zero, L_80021284
    if (ctx->r2 == 0) {
        // 0x80021234: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80021284;
    }
    // 0x80021234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021238: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002123C: nop

    // 0x80021240: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x80021244: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80021248: nop

    // 0x8002124C: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x80021250: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80021254: nop

    // 0x80021258: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x8002125C: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x80021260: nop

    // 0x80021264: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x80021268: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x8002126C: nop

    // 0x80021270: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x80021274: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x80021278: nop

    // 0x8002127C: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
L_80021280:
    // 0x80021280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021284:
    // 0x80021284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80021288: jr          $ra
    // 0x8002128C: nop

    return;
    // 0x8002128C: nop

;}
RECOMP_FUNC void func_8002125C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021298: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8002129C: lb          $v0, 0x12($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X12);
    // 0x800212A0: nop

    // 0x800212A4: bltz        $v0, L_800212F8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800212A8: nop
    
            goto L_800212F8;
    }
    // 0x800212A8: nop

    // 0x800212AC: lb          $t6, 0x3B($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3B);
    // 0x800212B0: nop

    // 0x800212B4: beq         $v0, $t6, L_800212D0
    if (ctx->r2 == ctx->r14) {
        // 0x800212B8: nop
    
            goto L_800212D0;
    }
    // 0x800212B8: nop

    // 0x800212BC: lbu         $t7, 0x16($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X16);
    // 0x800212C0: nop

    // 0x800212C4: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x800212C8: lb          $v0, 0x12($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X12);
    // 0x800212CC: nop

L_800212D0:
    // 0x800212D0: sb          $v0, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r2;
    // 0x800212D4: lb          $t8, 0x17($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X17);
    // 0x800212D8: nop

    // 0x800212DC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800212E0: nop

    // 0x800212E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800212E8: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x800212EC: lbu         $t9, 0x18($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X18);
    // 0x800212F0: nop

    // 0x800212F4: sb          $t9, 0x2C($a2)
    MEM_B(0X2C, ctx->r6) = ctx->r25;
L_800212F8:
    // 0x800212F8: lb          $v0, 0x13($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X13);
    // 0x800212FC: nop

    // 0x80021300: bltz        $v0, L_8002130C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80021304: nop
    
            goto L_8002130C;
    }
    // 0x80021304: nop

    // 0x80021308: sb          $v0, 0x2F($a2)
    MEM_B(0X2F, ctx->r6) = ctx->r2;
L_8002130C:
    // 0x8002130C: lh          $a0, 0x24($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X24);
    // 0x80021310: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80021314: jal         0x8000C8B4
    // 0x80021318: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    normalise_time(rdram, ctx);
        goto after_0;
    // 0x80021318: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002131C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80021320: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80021324: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80021328: sh          $v0, 0x36($a2)
    MEM_H(0X36, ctx->r6) = ctx->r2;
    // 0x8002132C: lb          $t0, 0x2D($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X2D);
    // 0x80021330: nop

    // 0x80021334: sb          $t0, 0x3F($a2)
    MEM_B(0X3F, ctx->r6) = ctx->r8;
    // 0x80021338: lb          $t1, 0x26($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X26);
    // 0x8002133C: nop

    // 0x80021340: sb          $t1, 0x3A($a2)
    MEM_B(0X3A, ctx->r6) = ctx->r9;
    // 0x80021344: lb          $t2, 0x1F($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1F);
    // 0x80021348: nop

    // 0x8002134C: sb          $t2, 0x39($a2)
    MEM_B(0X39, ctx->r6) = ctx->r10;
    // 0x80021350: lb          $t3, 0x30($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X30);
    // 0x80021354: nop

    // 0x80021358: sb          $t3, 0x43($a2)
    MEM_B(0X43, ctx->r6) = ctx->r11;
    // 0x8002135C: lbu         $t4, 0x1E($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1E);
    // 0x80021360: nop

    // 0x80021364: sb          $t4, 0x38($a2)
    MEM_B(0X38, ctx->r6) = ctx->r12;
    // 0x80021368: lb          $t5, 0x29($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X29);
    // 0x8002136C: nop

    // 0x80021370: sb          $t5, 0x3B($a2)
    MEM_B(0X3B, ctx->r6) = ctx->r13;
    // 0x80021374: lb          $t6, 0x2E($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X2E);
    // 0x80021378: nop

    // 0x8002137C: sb          $t6, 0x40($a2)
    MEM_B(0X40, ctx->r6) = ctx->r14;
    // 0x80021380: lb          $t7, 0x2F($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X2F);
    // 0x80021384: nop

    // 0x80021388: sb          $t7, 0x41($a2)
    MEM_B(0X41, ctx->r6) = ctx->r15;
    // 0x8002138C: lb          $t8, 0x2B($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X2B);
    // 0x80021390: nop

    // 0x80021394: sb          $t8, 0x3C($a2)
    MEM_B(0X3C, ctx->r6) = ctx->r24;
    // 0x80021398: lbu         $a0, 0x27($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X27);
    // 0x8002139C: nop

    // 0x800213A0: beq         $a0, $at, L_800213B8
    if (ctx->r4 == ctx->r1) {
        // 0x800213A4: nop
    
            goto L_800213B8;
    }
    // 0x800213A4: nop

    // 0x800213A8: jal         0x800C3744
    // 0x800213AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    set_current_text(rdram, ctx);
        goto after_1;
    // 0x800213AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800213B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800213B4: nop

L_800213B8:
    // 0x800213B8: lb          $a0, 0x2A($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X2A);
    // 0x800213BC: nop

    // 0x800213C0: bltz        $a0, L_800213D8
    if (SIGNED(ctx->r4) < 0) {
        // 0x800213C4: nop
    
            goto L_800213D8;
    }
    // 0x800213C4: nop

    // 0x800213C8: jal         0x8001E490
    // 0x800213CC: nop

    func_8001E45C(rdram, ctx);
        goto after_2;
    // 0x800213CC: nop

    after_2:
    // 0x800213D0: b           L_80021428
    // 0x800213D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80021428;
    // 0x800213D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800213D8:
    // 0x800213D8: lb          $a0, 0x15($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X15);
    // 0x800213DC: nop

    // 0x800213E0: bltz        $a0, L_800213F8
    if (SIGNED(ctx->r4) < 0) {
        // 0x800213E4: nop
    
            goto L_800213F8;
    }
    // 0x800213E4: nop

    // 0x800213E8: jal         0x80021434
    // 0x800213EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80021400(rdram, ctx);
        goto after_3;
    // 0x800213EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x800213F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800213F4: nop

L_800213F8:
    // 0x800213F8: lb          $t9, 0x28($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X28);
    // 0x800213FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80021400: bltz        $t9, L_80021424
    if (SIGNED(ctx->r25) < 0) {
        // 0x80021404: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80021424;
    }
    // 0x80021404: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80021408: lb          $t0, -0x4D5F($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X4D5F);
    // 0x8002140C: addiu       $t1, $t1, -0x4D5E
    ctx->r9 = ADD32(ctx->r9, -0X4D5E);
    // 0x80021410: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80021414: lb          $t2, 0x0($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X0);
    // 0x80021418: nop

    // 0x8002141C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80021420: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_80021424:
    // 0x80021424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021428:
    // 0x80021428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002142C: jr          $ra
    // 0x80021430: nop

    return;
    // 0x80021430: nop

;}
RECOMP_FUNC void func_80021400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021434: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021438: lh          $v1, -0x4C08($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4C08);
    // 0x8002143C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80021440: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80021444: blez        $v1, L_800214A4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80021448: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800214A4;
    }
    // 0x80021448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002144C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80021450: lw          $a1, -0x4C0C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4C0C);
    // 0x80021454: nop

    // 0x80021458: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8002145C: nop

    // 0x80021460: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x80021464: nop

    // 0x80021468: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8002146C: beq         $t6, $t9, L_800214A8
    if (ctx->r14 == ctx->r25) {
        // 0x80021470: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800214A8;
    }
    // 0x80021470: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_80021474:
    // 0x80021474: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80021478: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002147C: beq         $at, $zero, L_800214A4
    if (ctx->r1 == 0) {
        // 0x80021480: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_800214A4;
    }
    // 0x80021480: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80021484: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x80021488: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8002148C: nop

    // 0x80021490: lw          $t3, 0x7C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X7C);
    // 0x80021494: nop

    // 0x80021498: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8002149C: bne         $a0, $t4, L_80021474
    if (ctx->r4 != ctx->r12) {
        // 0x800214A0: nop
    
            goto L_80021474;
    }
    // 0x800214A0: nop

L_800214A4:
    // 0x800214A4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800214A8:
    // 0x800214A8: beq         $at, $zero, L_800214F0
    if (ctx->r1 == 0) {
        // 0x800214AC: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800214F0;
    }
    // 0x800214AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800214B0: lw          $t5, -0x4C0C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4C0C);
    // 0x800214B4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800214B8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800214BC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800214C0: nop

    // 0x800214C4: lw          $v1, 0x64($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X64);
    // 0x800214C8: nop

    // 0x800214CC: beq         $v1, $zero, L_800214F0
    if (ctx->r3 == 0) {
        // 0x800214D0: nop
    
            goto L_800214F0;
    }
    // 0x800214D0: nop

    // 0x800214D4: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x800214D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800214DC: lh          $t9, 0x2A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2A);
    // 0x800214E0: nop

    // 0x800214E4: bgez        $t9, L_800214F0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800214E8: nop
    
            goto L_800214F0;
    }
    // 0x800214E8: nop

    // 0x800214EC: sh          $t0, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r8;
L_800214F0:
    // 0x800214F0: jr          $ra
    // 0x800214F4: nop

    return;
    // 0x800214F4: nop

;}
RECOMP_FUNC void func_800214C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800214F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800214FC: lb          $t6, -0x4D5F($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X4D5F);
    // 0x80021500: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80021504: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80021508: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8002150C: lb          $v0, -0x4D5D($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D5D);
    // 0x80021510: jr          $ra
    // 0x80021514: nop

    return;
    // 0x80021514: nop

;}
